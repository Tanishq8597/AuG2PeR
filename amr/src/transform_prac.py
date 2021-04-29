#! /usr/bin/env python3

import rospy
from tf import TransformBroadcaster
import tf

rospy.init_node("Transform_prac")
# rospy.spin()
rate = rospy.Rate(100)

import rospy
from std_msgs.msg import String

pub = rospy.Publisher('topic_name', String, queue_size=10)
   

if __name__ == "__main__":
    try:
        
        while not rospy.is_shutdown():
        #     prac_broadcaster = TransformBroadcaster()
        #     # Lidar -> Body
        #     prac_broadcaster.sendTransform((-0.00676668663066682,7.9575573954549E-05,-0.00738187226715975),
        #             tf.transformations.quaternion_from_euler(0,0,0),
        #             rospy.get_rostime(),"Body","Lidar")
        #     # Body -> W
        #     prac_broadcaster.sendTransform((0,0,0),
        #             tf.transformations.quaternion_from_euler(0,0,0),
        #             rospy.get_rostime(),"W","Body")
            pub.publish("hello world")
            rate.sleep()
            # rospy.spin()
    except rospy.ROSInterruptException:
        pass

