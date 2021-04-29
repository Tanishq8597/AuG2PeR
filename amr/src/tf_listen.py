#! /usr/bin/env python3

import rospy
from geometry_msgs.msg import PointStamped
import tf

rospy.init_node("Tf_listen")
rate = rospy.Rate(100)
# rospy.spin()

def transformPoint(tf_listener):
    laser_point = PointStamped()
    laser_point.header.frame_id = "Lidar"
    laser_point.header.stamp = rospy.get_rostime()

    laser_point.point.x = 1.2
    laser_point.point.y = 3
    laser_point.point.z = 0

    tf_listener.waitForTransform("Lidar","Body",rospy.Time.now(), rospy.Duration(1.0))
    # (T,R) = tf_listener.lookupTransform('Body','Lidar',rospy.Time(0))
    base_point = tf_listener.transformPoint("Body",laser_point)
    print(base_point)
    # try:
    #     # print("In listener")
        
    #     # base_point = tf_listener.transformPoint("Body",laser_point)

    #     # rospy.loginfo("base_laser: (%.2f, %.2f. %.2f) -----> base_link: (%.2f, %.2f, %.2f) at time %.2f"%(
    #     # laser_point.point.x, laser_point.point.y, laser_point.point.z,
    #     # base_point.point.x, base_point.point.y, base_point.point.z, base_point.header.stamp.toSec()));
    # except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
    #     pass

if __name__ == "__main__":
    try:
        print("In main")
        while not rospy.is_shutdown():
            tf_listener = tf.TransformListener()
            transformPoint(tf_listener)
            rate.sleep()
    except rospy.ROSInterruptException:
        pass
            
            
    

