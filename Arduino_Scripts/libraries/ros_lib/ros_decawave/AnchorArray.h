#ifndef _ROS_ros_decawave_AnchorArray_h
#define _ROS_ros_decawave_AnchorArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ros_decawave/Anchor.h"

namespace ros_decawave
{

  class AnchorArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t anchors_length;
      typedef ros_decawave::Anchor _anchors_type;
      _anchors_type st_anchors;
      _anchors_type * anchors;

    AnchorArray():
      header(),
      anchors_length(0), st_anchors(), anchors(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->anchors_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->anchors_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->anchors_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->anchors_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->anchors_length);
      for( uint32_t i = 0; i < anchors_length; i++){
      offset += this->anchors[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t anchors_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      anchors_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      anchors_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      anchors_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->anchors_length);
      if(anchors_lengthT > anchors_length)
        this->anchors = (ros_decawave::Anchor*)realloc(this->anchors, anchors_lengthT * sizeof(ros_decawave::Anchor));
      anchors_length = anchors_lengthT;
      for( uint32_t i = 0; i < anchors_length; i++){
      offset += this->st_anchors.deserialize(inbuffer + offset);
        memcpy( &(this->anchors[i]), &(this->st_anchors), sizeof(ros_decawave::Anchor));
      }
     return offset;
    }

    virtual const char * getType() override { return "ros_decawave/AnchorArray"; };
    virtual const char * getMD5() override { return "57f47863c037d488af1159bddb78915c"; };

  };

}
#endif
