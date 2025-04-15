#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np
import os
import csv
from datetime import datetime
import time
from empty_shelf_msgs.msg import EmptyShelfAlert
import signal


class EmptyShelfDetector(Node):
    def __init__(self):
        super().__init__('empty_shelf_detector')

        self.bridge = CvBridge()
        self.image_count = 0
        self.empty_crop_count = 0
        self.depth_frame = None
        self.last_speech_time = time.time()

        # Declare and retrieve parameters
        self.declare_parameter("image_save_path", "/home/raghav/turtlebot4_ws/images")
        self.image_save_path = self.get_parameter("image_save_path").get_parameter_value().string_value
        self.cropped_save_path = os.path.join(self.image_save_path, "empty_crops")
        os.makedirs(self.image_save_path, exist_ok=True)
        os.makedirs(self.cropped_save_path, exist_ok=True)

        self.csv_file_path = os.path.join(self.image_save_path, "empty_shelf_data.csv")
        if not os.path.exists(self.csv_file_path):
            with open(self.csv_file_path, mode='w', newline='') as file:
                writer = csv.writer(file)
                writer.writerow(["Timestamp", "Shelf_Level", "X", "Y", "Depth", "Confidence", "Status"])

        # Subscriptions and Publishers
        self.image_sub = self.create_subscription(Image, '/oakd/rgb/preview/image_raw', self.image_callback, 10)
        self.depth_sub = self.create_subscription(Image, '/oakd/depth/image_raw', self.depth_callback, 10)
        self.publisher = self.create_publisher(EmptyShelfAlert, '/empty_shelf_alert', 10)

    def speak(self, text):
        if time.time() - self.last_speech_time > 5:
            os.system(f"espeak '{text}'")
            self.last_speech_time = time.time()

    def depth_callback(self, msg):
        try:
            self.depth_frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')
        except Exception as e:
            self.get_logger().error(f"Depth conversion error: {e}")

    def calculate_edge_density(self, region):
        gray = cv2.cvtColor(region, cv2.COLOR_BGR2GRAY)
        edges = cv2.Canny(gray, 50, 150)
        return np.sum(edges > 0) / edges.size

    def is_low_color_histogram(self, region):
        hsv = cv2.cvtColor(region, cv2.COLOR_BGR2HSV)
        saturation = hsv[:, :, 1]
        return np.mean(saturation) < 60

    def get_depth_at(self, x, y):
        if self.depth_frame is None:
            return None
        h, w = self.depth_frame.shape
        x = min(max(x, 0), w - 1)
        y = min(max(y, 0), h - 1)
        return self.depth_frame[y, x] / 1000.0  # Convert mm to meters

    def image_callback(self, msg):
        try:
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        except Exception as e:
            self.get_logger().error(f"Image conversion error: {e}")
            return

        height, width, _ = cv_image.shape
        top, bottom = int(0.2 * height), int(0.8 * height)
        roi = cv_image[top:bottom, :]

        gray = cv2.cvtColor(roi, cv2.COLOR_BGR2GRAY)
        edges = cv2.Canny(gray, 50, 150)
        contours, _ = cv2.findContours(edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

        for contour in contours:
            x, y, w, h = cv2.boundingRect(contour)
            if w > 50 and h > 50:
                x1, y1 = x, y + top
                x2, y2 = x + w, y + h + top
                region = cv_image[y1:y2, x1:x2]

                edge_density = self.calculate_edge_density(region)
                low_texture = edge_density < 0.02
                low_color = self.is_low_color_histogram(region)

                cx, cy = x + w // 2, y + h // 2 + top
                depth = self.get_depth_at(cx, cy)
                valid_depth = depth is not None and depth > 0.5

                # Confidence can be improved
                confidence = max(0.0, (1.0 - edge_density * 10) * (1.0 if low_color else 0.5))

                if low_texture and low_color and valid_depth:
                    cv2.rectangle(cv_image, (x1, y1), (x2, y2), (0, 255, 0), 2)
                    label = f"E:{edge_density:.2f} D:{depth:.2f}"
                    cv2.putText(cv_image, label, (x1, y1 - 5), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 1)

                    # Save cropped region
                    crop_filename = os.path.join(self.cropped_save_path, f"empty_{self.empty_crop_count}.jpg")
                    cv2.imwrite(crop_filename, region)
                    self.empty_crop_count += 1

                    # Publish alert
                    alert_msg = EmptyShelfAlert()
                    alert_msg.timestamp = self.get_clock().now().to_msg()
                    alert_msg.shelf_level = int((cy / height) * 5)
                    alert_msg.x = float(cx)
                    alert_msg.y = float(cy)
                    alert_msg.depth = float(depth)
                    alert_msg.confidence = float(confidence)
                    alert_msg.status = "EMPTY"
                    self.publisher.publish(alert_msg)

                    self.speak("Empty shelf detected")

                    # Log to CSV
                    with open(self.csv_file_path, mode='a', newline='') as file:
                        writer = csv.writer(file)
                        timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
                        writer.writerow([timestamp, alert_msg.shelf_level, alert_msg.x,
                                         alert_msg.y, alert_msg.depth, alert_msg.confidence, alert_msg.status])
                else:
                    cv2.rectangle(cv_image, (x1, y1), (x2, y2), (0, 0, 255), 1)
                    label = f"E:{edge_density:.2f}"
                    cv2.putText(cv_image, label, (x1, y1 - 5), cv2.FONT_HERSHEY_SIMPLEX, 0.4, (0, 0, 255), 1)

        # Save full frame
        image_filename = os.path.join(self.image_save_path, f'image_{self.image_count}.jpg')
        cv2.imwrite(image_filename, cv_image)
        self.image_count += 1

        # Display for debugging
        cv2.imshow('Detected Empty Shelves', cv_image)
        cv2.waitKey(1)


def main(args=None):
    def shutdown(signal_num, frame):
        cv2.destroyAllWindows()
        rclpy.shutdown()

    signal.signal(signal.SIGINT, shutdown)

    rclpy.init(args=args)
    node = EmptyShelfDetector()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        cv2.destroyAllWindows()


if __name__ == '__main__':
    main()
