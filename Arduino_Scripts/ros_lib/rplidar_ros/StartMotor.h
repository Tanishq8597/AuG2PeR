#ifndef _ROS_SERVICE_StartMotor_h
#define _ROS_SERVICE_StartMotor_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/UInt16.h"

namespace rplidar_ros
{

static const char STARTMOTOR[] = "rplidar_ros/StartMotor";

  class StartMotorRequest : public ros::Msg
  {
    public:
      typedef std_msgs::UInt16 _pwm_type;
      _pwm_type pwm;

    StartMotorRequest():
      pwm()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->pwm.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->pwm.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return STARTMOTOR; };
    virtual const char * getMD5() override { return "bd160db0cb9e838a10809e84d876d07a"; };

  };

  class StartMotorResponse : public ros::Msg
  {
    public:

    StartMotorResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return STARTMOTOR; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class StartMotor {
    public:
    typedef StartMotorRequest Request;
    typedef StartMotorResponse Response;
  };

}
#endif
