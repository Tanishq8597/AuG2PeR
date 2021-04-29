#ifndef _ROS_ros_decawave_Tag_h
#define _ROS_ros_decawave_Tag_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace ros_decawave
{

  class Tag : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _x_type;
      _x_type x;
      typedef float _y_type;
      _y_type y;
      typedef float _z_type;
      _z_type z;
      typedef float _qf_type;
      _qf_type qf;
      typedef int16_t _n_anchors_type;
      _n_anchors_type n_anchors;

    Tag():
      header(),
      x(0),
      y(0),
      z(0),
      qf(0),
      n_anchors(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->x);
      offset += serializeAvrFloat64(outbuffer + offset, this->y);
      offset += serializeAvrFloat64(outbuffer + offset, this->z);
      offset += serializeAvrFloat64(outbuffer + offset, this->qf);
      union {
        int16_t real;
        uint16_t base;
      } u_n_anchors;
      u_n_anchors.real = this->n_anchors;
      *(outbuffer + offset + 0) = (u_n_anchors.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_n_anchors.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->n_anchors);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->z));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->qf));
      union {
        int16_t real;
        uint16_t base;
      } u_n_anchors;
      u_n_anchors.base = 0;
      u_n_anchors.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_n_anchors.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->n_anchors = u_n_anchors.real;
      offset += sizeof(this->n_anchors);
     return offset;
    }

    virtual const char * getType() override { return "ros_decawave/Tag"; };
    virtual const char * getMD5() override { return "2c5d53ffcbf3427d3ef936e7e3b87a10"; };

  };

}
#endif
