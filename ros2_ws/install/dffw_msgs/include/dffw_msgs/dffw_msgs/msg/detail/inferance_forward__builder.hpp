// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dffw_msgs:msg/InferanceForward.idl
// generated code does not contain a copyright notice

#ifndef DFFW_MSGS__MSG__DETAIL__INFERANCE_FORWARD__BUILDER_HPP_
#define DFFW_MSGS__MSG__DETAIL__INFERANCE_FORWARD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dffw_msgs/msg/detail/inferance_forward__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dffw_msgs
{

namespace msg
{

namespace builder
{

class Init_InferanceForward_goodness_data
{
public:
  explicit Init_InferanceForward_goodness_data(::dffw_msgs::msg::InferanceForward & msg)
  : msg_(msg)
  {}
  ::dffw_msgs::msg::InferanceForward goodness_data(::dffw_msgs::msg::InferanceForward::_goodness_data_type arg)
  {
    msg_.goodness_data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dffw_msgs::msg::InferanceForward msg_;
};

class Init_InferanceForward_goodness_shape
{
public:
  explicit Init_InferanceForward_goodness_shape(::dffw_msgs::msg::InferanceForward & msg)
  : msg_(msg)
  {}
  Init_InferanceForward_goodness_data goodness_shape(::dffw_msgs::msg::InferanceForward::_goodness_shape_type arg)
  {
    msg_.goodness_shape = std::move(arg);
    return Init_InferanceForward_goodness_data(msg_);
  }

private:
  ::dffw_msgs::msg::InferanceForward msg_;
};

class Init_InferanceForward_h_data
{
public:
  explicit Init_InferanceForward_h_data(::dffw_msgs::msg::InferanceForward & msg)
  : msg_(msg)
  {}
  Init_InferanceForward_goodness_shape h_data(::dffw_msgs::msg::InferanceForward::_h_data_type arg)
  {
    msg_.h_data = std::move(arg);
    return Init_InferanceForward_goodness_shape(msg_);
  }

private:
  ::dffw_msgs::msg::InferanceForward msg_;
};

class Init_InferanceForward_h_shape
{
public:
  Init_InferanceForward_h_shape()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_InferanceForward_h_data h_shape(::dffw_msgs::msg::InferanceForward::_h_shape_type arg)
  {
    msg_.h_shape = std::move(arg);
    return Init_InferanceForward_h_data(msg_);
  }

private:
  ::dffw_msgs::msg::InferanceForward msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dffw_msgs::msg::InferanceForward>()
{
  return dffw_msgs::msg::builder::Init_InferanceForward_h_shape();
}

}  // namespace dffw_msgs

#endif  // DFFW_MSGS__MSG__DETAIL__INFERANCE_FORWARD__BUILDER_HPP_
