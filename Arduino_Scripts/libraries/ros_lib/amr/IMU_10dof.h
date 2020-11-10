#ifndef _ROS_amr_IMU_10dof_h
#define _ROS_amr_IMU_10dof_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace amr
{

  class IMU_10dof : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      float gyro_val[3];
      float accel_val[3];
      float mag_val[3];
      typedef float _temp_type;
      _temp_type temp;

    IMU_10dof():
      header(),
      gyro_val(),
      accel_val(),
      mag_val(),
      temp(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->gyro_val[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->accel_val[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->mag_val[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->temp);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gyro_val[i]));
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->accel_val[i]));
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->mag_val[i]));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->temp));
     return offset;
    }

    virtual const char * getType() override { return "amr/IMU_10dof"; };
    virtual const char * getMD5() override { return "9b8d7eca084f26c332bc26f08693149d"; };

  };

}
#endif
