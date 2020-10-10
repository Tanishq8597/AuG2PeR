#! /usr/bin/env python3

import rospy

from std_msgs.msg import String

R2A_pub = rospy.Publisher('ROS2ArduinoSub',String,queue_size=10)
rospy.init_node('Ground_Station',anonymous=False)
rate = rospy.Rate(100)

if __name__ == '__main__':
    try:
        while not rospy.is_shutdown():
            R2A_pub.publish("Ground Station here")
            rate.sleep()
    except rospy.ROSInterruptException:
        pass


