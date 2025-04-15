import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/raghav/turtlebot4_ws/src/install/empty_shelf_detector'
