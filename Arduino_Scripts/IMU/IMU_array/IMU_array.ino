#include <ros.h>
#include <ros/time.h>
#include <std_msgs/Float64MultiArray.h>
#include <std_msgs/MultiArrayDimension.h>
#include <std_msgs/Header.h>
//#include <sensor_msgs/Imu.h>
//#include <sensor_msgs/MagneticField.h>

#include "MPU9250.h"

// SDA - D20 - White
// SCL - D21 - Yellow

// ROS node
ros::NodeHandle IMU_node ;
//sensor_msgs::Imu imu_msg ;
//sensor_msgs::MagneticField mag_msg;
std_msgs::Float64MultiArray imu;
std_msgs::Float64MultiArray imu_cov;
std_msgs::Header imu_header ;

std_msgs::MultiArrayDimension a;

//ros::Publisher IMU_ag_pub("/imu/data_raw", &imu_msg) ;
//ros::Publisher IMU_mag_pub("/imu/mag", &mag_msg) ;
ros::Publisher IMU_pub("/imu/data", &imu) ;
ros::Publisher IMU_cov_pub("/imu/cov", &imu_cov) ;
ros::Publisher IMU_time_pub("/imu/head", &imu_header) ;

// IMU
MPU9250 IMU(Wire, 0x68);
int stat, accel, gyro , mag;

void setup()
{
  IMU_node.initNode();
  Serial.begin(500000) ;
  IMU_node.advertise(IMU_pub);
  IMU_node.advertise(IMU_cov_pub);
  IMU_node.advertise(IMU_time_pub);
  set_IMU();

  imu.layout.dim[0].size = 9;
  imu.layout.dim[0].stride=1;

  imu_cov.layout.dim[0].size = 9;
  imu_cov.layout.dim[0].stride=1;
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
    imu_header.seq = 0 ;

    //    gyro = IMU.calibrateGyro();
    //    accel= IMU.calibrateAccel();
    //    mag = IMU.calibrateMag() ;
    gyro = 1 ;
    accel = 1;
    mag = 1 ;
  }
  //  else
  //  {
  //    imu_msg.header.frame_id = "Disconnected" ;
  //    IMU_ag_pub.publish(&imu_msg) ;
  //    IMU_node.spinOnce();
  //  }
}

void loop()
{
  if (stat > 0)
  {
    IMU.readSensor() ;
    //
    //    imu_msg.header.seq++ ;
    //    mag_msg.header.seq = imu_msg.header.seq ;
    //
    //    imu_msg.header.stamp = IMU_node.now() ;
    //    mag_msg.header.stamp = IMU_node.now() ;

    imu_header.stamp     = IMU_node.now() ;
    imu_header.frame_id  = 'IMU' ;
    imu_header.seq++ ;

    //    imu_msg.header.frame_id = "Accel" ;
    //    mag_msg.header.frame_id = "Mag" ;
    //
    //    imu_msg.linear_acceleration.x = IMU.getAccelX_mss() ;
    //    imu_msg.linear_acceleration.y = IMU.getAccelY_mss() ;
    //    imu_msg.linear_acceleration.z = IMU.getAccelZ_mss() ;

    imu.data[0] =IMU.getAccelX_mss() ;
    imu.data[1] =IMU.getAccelY_mss() ;
    imu.data[2] =IMU.getAccelZ_mss() ;

    if (accel > 0)
    {
      //      imu_msg.linear_acceleration_covariance[0] = IMU.getAccelBiasX_mss() ;
      //      imu_msg.linear_acceleration_covariance[4] = IMU.getAccelBiasY_mss() ;
      //      imu_msg.linear_acceleration_covariance[8] = IMU.getAccelBiasZ_mss() ;

      imu_cov.data[0] =IMU.getAccelBiasX_mss() ;
      imu_cov.data[1] =IMU.getAccelBiasY_mss() ;
      imu_cov.data[2] =IMU.getAccelBiasZ_mss() ;
    }

    //    imu_msg.angular_velocity.x = IMU.getGyroX_rads() ;
    //    imu_msg.angular_velocity.y = IMU.getGyroY_rads() ;
    //    imu_msg.angular_velocity.z = IMU.getGyroZ_rads() ;

//    imu.data[3] = IMU.getGyroX_rads() ;
//    imu.data[4] = IMU.getGyroY_rads() ;
//    imu.data[5] = IMU.getGyroZ_rads() ;
//
//    if (gyro > 0)
//    {
//      //      imu_msg.angular_velocity_covariance[0] = -0.003671223996207118 ;
//      //      imu_msg.angular_velocity_covariance[4] = -0.03246975317597389 ;
//      //      imu_msg.angular_velocity_covariance[8] = -0.015176254324615002 ;
//
//      imu_cov.data[3] = -0.003671223996207118 ;
//      imu_cov.data[4] = -0.03246975317597389 ;
//      imu_cov.data[5] = -0.015176254324615002 ;
//    }
//
//    //    mag_msg.magnetic_field.x = IMU.getMagX_uT();
//    //    mag_msg.magnetic_field.y = IMU.getMagY_uT();
//    //    mag_msg.magnetic_field.z = IMU.getMagZ_uT();
//
//    imu.data[6] = IMU.getMagX_uT();
//    imu.data[7] = IMU.getMagY_uT();
//    imu.data[8] = IMU.getMagZ_uT();
//
//
//    if (mag > 0)
//    {
//      //      mag_msg.magnetic_field_covariance[0] = IMU.getMagBiasX_uT();
//      //      mag_msg.magnetic_field_covariance[4] = IMU.getMagBiasY_uT() ;
//      //      mag_msg.magnetic_field_covariance[8] = IMU.getMagBiasZ_uT() ;
//
//      imu_cov.data[6] = IMU.getMagBiasX_uT();
//      imu_cov.data[7] = IMU.getMagBiasY_uT() ;
//      imu_cov.data[8] = IMU.getMagBiasZ_uT() ;
//    }

    //    IMU_ag_pub.publish(&imu_msg) ;
    //    IMU_mag_pub.publish(&mag_msg) ;
    IMU_pub.publish(&imu) ;
    IMU_cov_pub.publish(&imu_cov) ;
    IMU_time_pub.publish(&imu_header);
    IMU_node.spinOnce();
    delay(1) ;
  }
}
