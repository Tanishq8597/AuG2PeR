#include <ros.h>
#include <ros/time.h>
#include <sensor_msgs/Imu.h>
#include <sensor_msgs/MagneticField.h>

#include "MPU9250.h"

// SDA - D20 - White
// SCL - D21 - Yellow

// ROS node
ros::NodeHandle IMU_node ;
sensor_msgs::Imu imu_msg ;
sensor_msgs::MagneticField mag_msg;

ros::Publisher IMU_ag_pub("/imu/data_raw", &imu_msg) ;
ros::Publisher IMU_mag_pub("/imu/mag", &mag_msg) ;

// IMU
MPU9250 IMU(Wire, 0x68);
int stat, accel, gyro , mag;

void setup()
{
  IMU_node.initNode();
  Serial.begin(500000) ;
  IMU_node.advertise(IMU_ag_pub);
  IMU_node.advertise(IMU_mag_pub);
  set_IMU();
}

void set_IMU()
{
  stat = IMU.begin() ;

  if (stat > 0 )
  {
    //    IMU_node.loginfo("IMU.begin success");
    // setting the accelerometer full scale range to +/-16G
    IMU.setAccelRange(MPU9250::ACCEL_RANGE_16G);
    // setting the gyroscope full scale range to +/-2000 deg/s
    IMU.setGyroRange(MPU9250::GYRO_RANGE_2000DPS);
    // setting DLPF bandwidth to 41 Hz
    IMU.setDlpfBandwidth(MPU9250::DLPF_BANDWIDTH_41HZ);
    //  update rate = 1000/(1+SRD) => 250Hz
    IMU.setSrd(0);
    //    IMU_node.loginfo("IMU connected");
    imu_msg.header.seq = 0 ;

    //    gyro = IMU.calibrateGyro();
    //    accel= IMU.calibrateAccel();
    //    mag = IMU.calibrateMag() ;
    gyro = 1 ;
    accel = 1;
    mag = 1 ;
  }
  else
  {
    imu_msg.header.frame_id = "Disconnected" ;
    IMU_ag_pub.publish(&imu_msg) ;
    IMU_node.spinOnce();
  }
}

void loop()
{
  if (stat > 0)
  {
    IMU.readSensor() ;

    imu_msg.header.seq++ ;
    mag_msg.header.seq = imu_msg.header.seq ;

    imu_msg.header.stamp = IMU_node.now() ;
    mag_msg.header.stamp = IMU_node.now() ;
    imu_msg.header.frame_id = "Accel" ;
    mag_msg.header.frame_id = "Mag" ;

    imu_msg.linear_acceleration.x = IMU.getAccelX_mss() ;
    imu_msg.linear_acceleration.y = IMU.getAccelY_mss() ;
    imu_msg.linear_acceleration.z = IMU.getAccelZ_mss() ;

    if (accel > 0)
    {
      imu_msg.linear_acceleration_covariance[0] = IMU.getAccelBiasX_mss() ;
      imu_msg.linear_acceleration_covariance[4] = IMU.getAccelBiasY_mss() ;
      imu_msg.linear_acceleration_covariance[8] = IMU.getAccelBiasZ_mss() ;
    }

    imu_msg.angular_velocity.x = IMU.getGyroX_rads() ;
    imu_msg.angular_velocity.y = IMU.getGyroY_rads() ;
    imu_msg.angular_velocity.z = IMU.getGyroZ_rads() ;

    if (gyro > 0)
    {
      imu_msg.angular_velocity_covariance[0] = -0.003671223996207118 ;
      imu_msg.angular_velocity_covariance[4] = -0.03246975317597389 ;
      imu_msg.angular_velocity_covariance[8] = -0.015176254324615002 ;
    }

    mag_msg.magnetic_field.x = IMU.getMagX_uT();
    mag_msg.magnetic_field.y = IMU.getMagY_uT();
    mag_msg.magnetic_field.z = IMU.getMagZ_uT();

    if (mag > 0)
    {
      mag_msg.magnetic_field_covariance[0] = IMU.getMagBiasX_uT();
      mag_msg.magnetic_field_covariance[4] = IMU.getMagBiasY_uT() ;
      mag_msg.magnetic_field_covariance[8] = IMU.getMagBiasZ_uT() ;
    }

    IMU_ag_pub.publish(&imu_msg) ;
    IMU_mag_pub.publish(&mag_msg) ;
    IMU_node.spinOnce();
    delay(1) ;
  }
}
