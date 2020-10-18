#include<ros.h>
#include <ros/time.h>
#include<amr/grove_10dof.h>

// Grove libraries
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU9250.h"
#include "BMP280.h"

// SDA - D20
// SCL - D21

// ROS node handle
ros::NodeHandle IMU_n ;

// Publisher for custom message
amr::grove_10dof IMU_msg ;
ros::Publisher IMU_pub("IMU", &IMU_msg) ;

// GROVE 10 DOF example code

// class default I2C address is 0x68
// specific I2C addresses may be passed as a parameter here
// AD0 low = 0x68 (default for InvenSense evaluation board)
// AD0 high = 0x69
MPU9250 accelgyro;
I2Cdev   I2C_M;
BMP280 bmp280;

//#define sample_num_mdate  5000

int16_t ax, ay, az;
int16_t gx, gy, gz;
int16_t mx, my, mz;

float Axyz[3];
float Gxyz[3];
float temperature;

void setup() {
  // ROS setup
  IMU_n.initNode();
  IMU_n.advertise(IMU_pub) ;

  Serial.begin(115200) ;

  // GROVE 10 DOF example code
  // join I2C bus (I2Cdev library doesn't do this automatically)
  Wire.begin();
  //Wire.setClock(400000);

  accelgyro.initialize();
  bmp280.init();

  // wait to ensure connection
//  while (~(accelgyro.testConnection()))
//  {
//    IMU_msg.state_connect = false ;
//    IMU_pub.publish(&IMU_msg) ;
//  }
  IMU_msg.state_connect = true ;
  IMU_msg.header.seq = 1 ;
}

void loop() {
  // GROVE 10 DOF example code
  getAccel_Data();
  getGyro_Data();
  temperature = bmp280.getTemperature();

  // Fill in IMU_msg
  IMU_msg.header.stamp=IMU_n.now() ;
  IMU_msg.header.frame_id="IMU + temp" ;

  IMU_msg.gyro_val[0] = Gxyz[0] ;
  IMU_msg.gyro_val[1] = Gxyz[1] ;
  IMU_msg.gyro_val[2] = Gxyz[2] ;
  
  IMU_msg.accel_val[0]= Axyz[0] ;
  IMU_msg.accel_val[0]= Axyz[0] ;
  IMU_msg.accel_val[0]= Axyz[0] ;
  
  IMU_msg.temp = temperature;

  IMU_pub.publish(&IMU_msg) ;
  IMU_n.spinOnce();
//  delay(5) ;

  IMU_msg.header.seq++ ;
}

// Function Declarations
float getAccel_Data(void) {
  accelgyro.getMotion9(&ax, &ay, &az, &gx, &gy, &gz, &mx, &my, &mz);
  Axyz[0] = (double) ax / 16384;
  Axyz[1] = (double) ay / 16384;
  Axyz[2] = (double) az / 16384;
}

float getGyro_Data(void) {
  accelgyro.getMotion9(&ax, &ay, &az, &gx, &gy, &gz, &mx, &my, &mz);
  Gxyz[0] = (double) gx * 250 / 32768;
  Gxyz[1] = (double) gy * 250 / 32768;
  Gxyz[2] = (double) gz * 250 / 32768;
}
