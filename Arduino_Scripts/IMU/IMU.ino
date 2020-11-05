#include <ros.h>
#include <ros/time.h>
#include <amr/grove_10dof.h>

#include "MPU9250.h"

// SDA - D20 - White
// SCL - D21 - Yellow

// ROS node
ros::NodeHandle IMU_node ;
amr::grove_10dof IMU_msg ;

ros::Publisher IMU_AM_pub("/IMU", &IMU_msg) ;

// IMU
MPU9250 IMU(Wire, 0x68) ;
int IMU_status ;

void setup() 
{
  IMU_node.initNode() ;
  IMU_node.advertise(IMU_AM_pub);
  Serial.begin(500000) ;

  IMU_status = IMU.begin() ;
  if (IMU_status > 0)
  {
    // setting the accelerometer full scale range to +/-16G
    IMU.setAccelRange(MPU9250::ACCEL_RANGE_16G);
    // setting the gyroscope full scale range to +/-2000 deg/s
    IMU.setGyroRange(MPU9250::GYRO_RANGE_2000DPS);
    // setting DLPF bandwidth to 41 Hz
    IMU.setDlpfBandwidth(MPU9250::DLPF_BANDWIDTH_41HZ);
    //  update rate = 1000/(1+SRD) => 100Hz
    IMU.setSrd(9);

    IMU_msg.state_connect = true ;
    IMU_msg.header.seq = 0 ;
  }
  else
  {
    IMU_msg.state_connect = false ;
  }
}

void loop() {
  if (IMU_msg.state_connect)
  {
    IMU.readSensor() ;
    IMU_msg.header.seq++ ;

    IMU_msg.header.stamp = IMU_node.now() ;
    IMU_msg.header.frame_id = "IMU_10DOF" ;

    IMU_msg.accel_val[0] = IMU.getAccelX_mss() ;
    IMU_msg.accel_val[1] = IMU.getAccelY_mss() ;
    IMU_msg.accel_val[2] = IMU.getAccelZ_mss() ;

    IMU_msg.gyro_val[0] = IMU.getGyroX_rads() ;
    IMU_msg.gyro_val[1] = IMU.getGyroY_rads() ;
    IMU_msg.gyro_val[2] = IMU.getGyroZ_rads() ;

    IMU_msg.mag_val[0] = IMU.getMagX_uT() ;
    IMU_msg.mag_val[1] = IMU.getMagY_uT() ;
    IMU_msg.mag_val[2] = IMU.getMagZ_uT() ;

    IMU_msg.temp = IMU.getTemperature_C();

    IMU_AM_pub.publish(&IMU_msg) ;
    IMU_node.spinOnce();
  }
}
