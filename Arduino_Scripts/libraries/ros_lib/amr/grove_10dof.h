#ifndef _ROS_amr_grove_10dof_h
#define _ROS_amr_grove_10dof_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace amr
{

  class grove_10dof : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _state_connect_type;
      _state_connect_type state_connect;
      float gyro_val[3];
      float accel_val[3];
      float mag_val[3];
      typedef float _temp_type;
      _temp_type temp;

    grove_10dof():
      header(),
      state_connect(0),
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
      union {
        bool real;
        uint8_t base;
      } u_state_connect;
      u_state_connect.real = this->state_connect;
      *(outbuffer + offset + 0) = (u_state_connect.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->state_connect);
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
      union {
        bool real;
        uint8_t base;
      } u_state_connect;
      u_state_connect.base = 0;
      u_state_connect.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->state_connect = u_state_connect.real;
      offset += sizeof(this->state_connect);
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

    virtual const char * getType() override { return "amr/grove_10dof"; };
    virtual const char * getMD5() override { return "7cd7611c13f25aa6605cfb4b00507029"; };

  };

}
#endif
