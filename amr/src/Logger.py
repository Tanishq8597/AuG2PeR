#! /usr/bin/env python3

import rospy
from amr.msg import grove_10dof
from std_msgs.msg import Header

rospy.init_node("IMU_Logger")
log_time = Header()
time_pub = rospy.Publisher("Propogation_Time",Header,queue_size=2)

def IMU_CB(data):
    current_time = rospy.get_rostime() 
    log_time.stamp.secs = current_time.secs
    log_time.stamp.nsecs= current_time.nsecs 
    # rospy.loginfo("%i sec %i nsec",log_time.stamp.secs-data.header.stamp.secs,log_time.stamp.nsecs-data.header.stamp.nsecs)
    time_pub.publish(log_time)

rospy.Subscriber("/IMU",grove_10dof,IMU_CB)
rospy.spin()

if __name__ == '__main__':
    try:
        while not rospy.is_shutdown():
            rate.sleep()
    except rospy.ROSInterruptException:
        pass