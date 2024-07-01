#ifndef _ROS_dgz_msgs_ListFloat64_h
#define _ROS_dgz_msgs_ListFloat64_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dgz_msgs
{

  class ListFloat64 : public ros::Msg
  {
    public:
      uint32_t data_length;
      typedef double _data_type;
      _data_type st_data;
      _data_type * data;

    ListFloat64():
      data_length(0), st_data(), data(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->data_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data_length);
      for( uint32_t i = 0; i < data_length; i++){
      union {
        double real;
        uint64_t base;
      } u_datai;
      u_datai.real = this->data[i];
      *(outbuffer + offset + 0) = (u_datai.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_datai.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_datai.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_datai.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_datai.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_datai.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_datai.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_datai.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->data_length);
      if(data_lengthT > data_length)
        this->data = (double*)realloc(this->data, data_lengthT * sizeof(double));
      data_length = data_lengthT;
      for( uint32_t i = 0; i < data_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_data;
      u_st_data.base = 0;
      u_st_data.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_data.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_data.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_data.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_data.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_data.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_data.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_data.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_data = u_st_data.real;
      offset += sizeof(this->st_data);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(double));
      }
     return offset;
    }

    virtual const char * getType() override { return "dgz_msgs/ListFloat64"; };
    virtual const char * getMD5() override { return "788898178a3da2c3718461eecda8f714"; };

  };

}
#endif
