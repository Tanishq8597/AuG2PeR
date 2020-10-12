#ifndef _ROS_handpose_HandPose_h
#define _ROS_handpose_HandPose_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace handpose
{

  class HandPose : public ros::Msg
  {
    public:
      typedef const char* _currentGesture_type;
      _currentGesture_type currentGesture;
      typedef const char* _handedness_type;
      _handedness_type handedness;
      typedef float _velocity_x_type;
      _velocity_x_type velocity_x;
      typedef float _velocity_y_type;
      _velocity_y_type velocity_y;
      typedef float _position_x_type;
      _position_x_type position_x;
      typedef float _position_y_type;
      _position_y_type position_y;

    HandPose():
      currentGesture(""),
      handedness(""),
      velocity_x(0),
      velocity_y(0),
      position_x(0),
      position_y(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_currentGesture = strlen(this->currentGesture);
      varToArr(outbuffer + offset, length_currentGesture);
      offset += 4;
      memcpy(outbuffer + offset, this->currentGesture, length_currentGesture);
      offset += length_currentGesture;
      uint32_t length_handedness = strlen(this->handedness);
      varToArr(outbuffer + offset, length_handedness);
      offset += 4;
      memcpy(outbuffer + offset, this->handedness, length_handedness);
      offset += length_handedness;
      union {
        float real;
        uint32_t base;
      } u_velocity_x;
      u_velocity_x.real = this->velocity_x;
      *(outbuffer + offset + 0) = (u_velocity_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity_x);
      union {
        float real;
        uint32_t base;
      } u_velocity_y;
      u_velocity_y.real = this->velocity_y;
      *(outbuffer + offset + 0) = (u_velocity_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity_y);
      union {
        float real;
        uint32_t base;
      } u_position_x;
      u_position_x.real = this->position_x;
      *(outbuffer + offset + 0) = (u_position_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_position_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_position_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_position_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->position_x);
      union {
        float real;
        uint32_t base;
      } u_position_y;
      u_position_y.real = this->position_y;
      *(outbuffer + offset + 0) = (u_position_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_position_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_position_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_position_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->position_y);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_currentGesture;
      arrToVar(length_currentGesture, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_currentGesture; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_currentGesture-1]=0;
      this->currentGesture = (char *)(inbuffer + offset-1);
      offset += length_currentGesture;
      uint32_t length_handedness;
      arrToVar(length_handedness, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_handedness; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_handedness-1]=0;
      this->handedness = (char *)(inbuffer + offset-1);
      offset += length_handedness;
      union {
        float real;
        uint32_t base;
      } u_velocity_x;
      u_velocity_x.base = 0;
      u_velocity_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocity_x = u_velocity_x.real;
      offset += sizeof(this->velocity_x);
      union {
        float real;
        uint32_t base;
      } u_velocity_y;
      u_velocity_y.base = 0;
      u_velocity_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocity_y = u_velocity_y.real;
      offset += sizeof(this->velocity_y);
      union {
        float real;
        uint32_t base;
      } u_position_x;
      u_position_x.base = 0;
      u_position_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_position_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_position_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_position_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->position_x = u_position_x.real;
      offset += sizeof(this->position_x);
      union {
        float real;
        uint32_t base;
      } u_position_y;
      u_position_y.base = 0;
      u_position_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_position_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_position_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_position_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->position_y = u_position_y.real;
      offset += sizeof(this->position_y);
     return offset;
    }

    virtual const char * getType() override { return "handpose/HandPose"; };
    virtual const char * getMD5() override { return "730f3d7ab6bc3e8ebdcb2a6c24280807"; };

  };

}
#endif
