import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from geometry_msgs.msg import Point
from cv_bridge import CvBridge
import cv2
import numpy as np
import os

class EmptyShelfDetector(Node):
    def __init__(self):
        super().__init__('empty_shelf_detector')
        
        # ROS2 Subscriber to camera feed
        self.subscription = self.create_subscription(
            Image,
            '/camera/image_raw',  # Change if different topic
            self.image_callback,
            10
        )
        self.subscription  # Prevent unused variable warning
        
        # ROS2 Publisher for coordinates
        self.publisher = self.create_publisher(Point, '/empty_shelf_coordinates', 10)
        
        self.bridge = CvBridge()
        self.image_count = 0
        self.image_save_path = '/home/user/turtlebot_images/'  # Update path as needed
        os.makedirs(self.image_save_path, exist_ok=True)

    def image_callback(self, msg):
        # Convert ROS2 Image to OpenCV format
        cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        
        # Convert to grayscale and apply edge detection
        gray = cv2.cvtColor(cv_image, cv2.COLOR_BGR2GRAY)
        edges = cv2.Canny(gray, 50, 150)
        
        # Find contours (potential empty shelves)
        contours, _ = cv2.findContours(edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        empty_shelf_coords = []
        
        for contour in contours:
            x, y, w, h = cv2.boundingRect(contour)
            if w > 50 and h > 50:  # Filter based on size (tune as needed)
                empty_shelf_coords.append((x + w // 2, y + h // 2))  # Store center coordinates
                cv2.rectangle(cv_image, (x, y), (x + w, y + h), (0, 255, 0), 2)
        
        # Publish coordinates
        for coord in empty_shelf_coords:
            point_msg = Point()
            point_msg.x, point_msg.y, point_msg.z = float(coord[0]), float(coord[1]), 0.0
            self.publisher.publish(point_msg)
        
        # Save image
        image_filename = os.path.join(self.image_save_path, f'image_{self.image_count}.jpg')
        cv2.imwrite(image_filename, cv_image)
        self.image_count += 1
        
        # Display image
        cv2.imshow('Empty Shelf Detection', cv_image)
        cv2.waitKey(1)


def main(args=None):
    rclpy.init(args=args)
    node = EmptyShelfDetector()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()
