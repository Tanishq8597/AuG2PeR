#! /usr/bin/env python3
import rospy
import tf
import math
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import PointStamped
import matplotlib.pyplot as plt
plt.style.use('seaborn-whitegrid')


def laser_CB(msg):
    angle = 0

    for dist in msg.ranges:
        point_Lidar = PointStamped()
        point_body  = PointStamped()

        point_Lidar.header.frame_id = 'Lidar'
        point_Lidar.header.stamp = rospy.Time.now()
        angle += msg.angle_increment
        if dist == math.inf: continue
        if angle > math.pi/4 and angle < 7*math.pi/4 :
            continue
        
        point_Lidar.point.x = -dist*math.cos(angle)
        point_Lidar.point.y = -dist*math.sin(angle)
        point_Lidar.point.z = 0
        point_body = pLidar_Body.transformPoint('Body',point_Lidar)

        pLidar_Body_pub.sendTransform((point_body.point.x,point_body.point.y,point_body.point.z),\
            tf.transformations.quaternion_from_euler(0,0,angle),\
                rospy.Time.now(),\
                    'L_Obs',\
                        'Body')
    

if __name__ == "__main__":
    rospy.init_node("Laser_CB")
    sub = rospy.Subscriber('/scan',LaserScan,laser_CB)

    pLidar_Body_pub = tf.TransformBroadcaster()
    pLidar_Body     = tf.TransformListener()
    rospy.spin()