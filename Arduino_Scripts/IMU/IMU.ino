#include <ros.h>
#include <ros/time.h>
#include <sensor_msgs/Imu.h>

#include "MPU9250.h"

// SDA - D20 - White
// SCL - D21 - Yellow

// ROS node
ros::NodeHandle IMU_node ;
sensor_msgs::Imu imu_msg ;

ros::Publisher IMU_AM_pub("/IMU", &imu_msg) ;

// IMU
MPU9250 IMU(Wire, 0x68) ;
int IMU_status ;
int16_t mx,my.mz


void setup()
{
  IMU_node.initNode() ;
  IMU_node.advertise(IMU_AM_pub);
  Serial.begin(500000) ;
  set_IMU();
}

void set_IMU()
{
  IMU_status = IMU.begin() ;
  if (IMU_status > 0)
  {
    // setting the accelerometer full scale range to +/-16G
    IMU.setAccelRange(MPU9250::ACCEL_RANGE_16G);
    // setting the gyroscope full scale range to +/-2000 deg/s
    IMU.setGyroRange(MPU9250::GYRO_RANGE_2000DPS);
    // setting DLPF bandwidth to 41 Hz
    IMU.setDlpfBandwidth(MPU9250::DLPF_BANDWIDTH_41HZ);
    //  update rate = 1000/(1+SRD) => 250Hz
    IMU.setSrd(3);

    imu_msg.header.seq = 0 ;
  }
  else
  {
    imu_msg.header.frame_id = "Disconnected" ;
    IMU_AM_pub.publish(&imu_msg) ;
    IMU_node.spinOnce();
  }
}

void loop()
{
  if (IMU_status > 0)
  {
//    IMU.readSensor() ;
    imu_msg.header.seq++ ;

    imu_msg.header.stamp = IMU_node.now() ;
    imu_msg.header.frame_id = "IMU" ;

    IMU.getmotion9(
      imu_msg.linear_acceleration.x,imu_msg.linear_acceleration.y,imu_msg.linear_acceleration.z,
      imu_msg.angular_acceleration.x,imu_msg.angular_acceleration.y,imu_msg.angular_acceleration.z,
      mx,my,mz)

//    IMU_msg.accel_val[0] = IMU.getAccelerationX() ;
//    IMU_msg.accel_val[1] = IMU.getAccelerationY() ;
//    IMU_msg.accel_val[2] = IMU.getAccelerationZ() ;
//
//    IMU_msg.gyro_val[0] = IMU.getGyroX_rads() ;
//    IMU_msg.gyro_val[1] = IMU.getGyroY_rads() ;
//    IMU_msg.gyro_val[2] = IMU.getGyroZ_rads() ;
//
//    IMU_msg.mag_val[0] = IMU.getMagX_uT() ;
//    IMU_msg.mag_val[1] = IMU.getMagY_uT() ;
//    IMU_msg.mag_val[2] = IMU.getMagZ_uT() ;

    IMU_msg.temp = IMU.getTemperature_C();

    IMU_AM_pub.publish(&imu_msg) ;
    IMU_node.spinOnce();
    delay(1) ;
  }
}
