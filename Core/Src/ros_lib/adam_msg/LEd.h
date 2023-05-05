#ifndef _ROS_adam_msg_LEd_h
#define _ROS_adam_msg_LEd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace adam_msg
{

  class LEd : public ros::Msg
  {
    public:
      typedef int8_t _led_type;
      _led_type led;
      typedef int8_t _status_type;
      _status_type status;

    LEd():
      led(0),
      status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_led;
      u_led.real = this->led;
      *(outbuffer + offset + 0) = (u_led.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->led);
      union {
        int8_t real;
        uint8_t base;
      } u_status;
      u_status.real = this->status;
      *(outbuffer + offset + 0) = (u_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_led;
      u_led.base = 0;
      u_led.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->led = u_led.real;
      offset += sizeof(this->led);
      union {
        int8_t real;
        uint8_t base;
      } u_status;
      u_status.base = 0;
      u_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->status = u_status.real;
      offset += sizeof(this->status);
     return offset;
    }

    virtual const char * getType() override { return "adam_msg/LEd"; };
    virtual const char * getMD5() override { return "8b281732d2f9c2f4f5b2bf6fd0b6cab2"; };

  };

}
#endif
