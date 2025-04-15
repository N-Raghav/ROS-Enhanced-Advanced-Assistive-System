#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from empty_shelf_msgs.msg import EmptyShelfAlert
import os
import time
import signal


class EmptyShelfAlertListener(Node):
    def __init__(self):
        super().__init__('empty_shelf_alert_listener')
        self.subscriber = self.create_subscription(
            EmptyShelfAlert,
            '/empty_shelf_alert',
            self.listener_callback,
            10
        )
        self.last_alert_time = 0

    def listener_callback(self, msg):
        depth_meters = f"{msg.z:.2f}" if msg.z > 0 else "unknown"
        log_msg = (
            f"⚠️ Empty shelf detected at "
            f"x={msg.x:.2f}, y={msg.y:.2f}, depth={depth_meters}m, label='{msg.label}'"
        )
        self.get_logger().info(log_msg)

        # Throttle speech alerts to once every 5 seconds
        current_time = time.time()
        if current_time - self.last_alert_time > 5:
            os.system(f"espeak 'Empty shelf detected at {depth_meters} meters'")
            self.last_alert_time = current_time


def main(args=None):
    rclpy.init(args=args)
    node = EmptyShelfAlertListener()

    def shutdown_handler(signum, frame):
        node.get_logger().info('Shutting down EmptyShelfAlertListener...')
        node.destroy_node()
        rclpy.shutdown()

    signal.signal(signal.SIGINT, shutdown_handler)

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        if rclpy.ok():
            node.destroy_node()
            rclpy.shutdown()


if __name__ == '__main__':
    main()
