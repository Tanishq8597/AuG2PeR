#ifndef _ROS_amr_wheel_h
#define _ROS_amr_wheel_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace amr
{

  class wheel : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _setpoint_speed_type;
      _setpoint_speed_type setpoint_speed;
      typedef float _encoder_speed_type;
      _encoder_speed_type encoder_speed;
      typedef float _PID_speed_type;
      _PID_speed_type PID_speed;
      typedef float _dt_type;
      _dt_type dt;

    wheel():
      header(),
      setpoint_speed(0),
      encoder_speed(0),
      PID_speed(0),
      dt(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->setpoint_speed);
      offset += serializeAvrFloat64(outbuffer + offset, this->encoder_speed);
      offset += serializeAvrFloat64(outbuffer + offset, this->PID_speed);
      offset += serializeAvrFloat64(outbuffer + offset, this->dt);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->setpoint_speed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->encoder_speed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->PID_speed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->dt));
     return offset;
    }

    virtual const char * getType() override { return "amr/wheel"; };
    virtual const char * getMD5() override { return "7c16d9d03816d0fd55bb4097f7cbdbc9"; };

  };

}
#endif
