#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_std_msgs_Float32 and std_msgs::msg::Float32

void convertFromBus(std_msgs::msg::Float32& msgPtr, SL_Bus_std_msgs_Float32 const* busPtr)
{
  const std::string rosMessageType("std_msgs/Float32");

  msgPtr.data =  busPtr->data;
}

void convertToBus(SL_Bus_std_msgs_Float32* busPtr, const std_msgs::msg::Float32& msgPtr)
{
  const std::string rosMessageType("std_msgs/Float32");

  busPtr->data =  msgPtr.data;
}


// Conversions between SL_Bus_std_msgs_Int32 and std_msgs::msg::Int32

void convertFromBus(std_msgs::msg::Int32& msgPtr, SL_Bus_std_msgs_Int32 const* busPtr)
{
  const std::string rosMessageType("std_msgs/Int32");

  msgPtr.data =  busPtr->data;
}

void convertToBus(SL_Bus_std_msgs_Int32* busPtr, const std_msgs::msg::Int32& msgPtr)
{
  const std::string rosMessageType("std_msgs/Int32");

  busPtr->data =  msgPtr.data;
}

