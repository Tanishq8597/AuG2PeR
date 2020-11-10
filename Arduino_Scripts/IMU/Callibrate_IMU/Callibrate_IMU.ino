#include "MPU9250.h"

MPU9250 IMU(Wire, 0x68) ;
int Gyro_status ;
int Accel_status;
int Mag_status  ;

float ax, ay, az ;
float ax_s, ay_s, az_s ;
float gx, gy, gz ;
float gx_s, gy_s, gz_s ;
float mx, my, mz ;
float mx_s, my_s, mz_s ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(500000) ;
  //  IMU.begin() ;
  //
  //  Serial.println("Now calibrating Accelerometer") ;
  //  Accel_status = IMU.calibrateAccel() ;
  //  Serial.println(Accel_status) ;

  //  if (Accel_status == 1)
  //  {
  //    ax = IMU.getAccelBiasX_mss();
  //    ay = IMU.getAccelBiasY_mss();
  //    az = IMU.getAccelBiasZ_mss();
  //
  //    ax_s = IMU.getAccelScaleFactorX();
  //    ay_s = IMU.getAccelScaleFactorY();
  //    az_s = IMU.getAccelScaleFactorZ();
  //
  //    Serial.println("Accelerometer biases are :") ;
  //    Serial.print(ax) ;
  //    Serial.print("\t") ;
  //    Serial.print(ay) ;
  //    Serial.print("\t") ;
  //    Serial.print(az) ;
  //    Serial.print("\n") ;
  //
  //    Serial.println("Accelerometer scales are :") ;
  //    Serial.print(ax_s) ;
  //    Serial.print("\t") ;
  //    Serial.print(ay_s) ;
  //    Serial.print("\t") ;
  //    Serial.print(az_s) ;
  //    Serial.print("\n\n") ;
  //  }

  Serial.println("Now calibrating Gyroscope") ;
  Gyro_status = IMU.calibrateGyro()  ;
  Serial.println(Gyro_status) ;

  if (Gyro_status == 1)
  {
    gx = IMU.getGyroBiasX_rads() ;
    gy = IMU.getGyroBiasY_rads() ;
    gz = IMU.getGyroBiasZ_rads() ;

    Serial.println("Gyroscope biases are :") ;
    Serial.print(gx) ;
    Serial.print("\t") ;
    Serial.print(gy) ;
    Serial.print("\t") ;
    Serial.print(gz) ;
    Serial.print("\n") ;
  }

  //  Mag_status  = IMU.calibrateMag()   ;
  //  Serial.println("Now calibrating Magnetometer") ;
  //  Serial.println(Mag_status) ;
  //
  //  if (Mag_status == 1)
  //  {
  //    mx = IMU.getMagBiasX_uT();
  //    my = IMU.getMagBiasY_uT();
  //    mz = IMU.getMagBiasZ_uT();
  //
  //    mx_s = IMU.getMagScaleFactorX();
  //    my_s = IMU.getMagScaleFactorY();
  //    mz_s = IMU.getMagScaleFactorZ();
  //
  //    Serial.println("Magnetometer biases are :") ;
  //    Serial.print(mx) ;
  //    Serial.print("\t") ;
  //    Serial.print(my) ;
  //    Serial.print("\t") ;
  //    Serial.print(mz) ;
  //    Serial.print("\n") ;
  //
  //    Serial.println("Magnetometer scales are :") ;
  //    Serial.print(mx_s) ;
  //    Serial.print("\t") ;
  //    Serial.print(my_s) ;
  //    Serial.print("\t") ;
  //    Serial.print(mz_s) ;
  //    Serial.println("\n\n") ;
  //  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
