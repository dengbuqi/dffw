// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dffw_msgs:msg/TrainForward.idl
// generated code does not contain a copyright notice

#ifndef DFFW_MSGS__MSG__DETAIL__TRAIN_FORWARD__BUILDER_HPP_
#define DFFW_MSGS__MSG__DETAIL__TRAIN_FORWARD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dffw_msgs/msg/detail/train_forward__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dffw_msgs
{

namespace msg
{

namespace builder
{

class Init_TrainForward_h_neg_data
{
public:
  explicit Init_TrainForward_h_neg_data(::dffw_msgs::msg::TrainForward & msg)
  : msg_(msg)
  {}
  ::dffw_msgs::msg::TrainForward h_neg_data(::dffw_msgs::msg::TrainForward::_h_neg_data_type arg)
  {
    msg_.h_neg_data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dffw_msgs::msg::TrainForward msg_;
};

class Init_TrainForward_h_neg_shape
{
public:
  explicit Init_TrainForward_h_neg_shape(::dffw_msgs::msg::TrainForward & msg)
  : msg_(msg)
  {}
  Init_TrainForward_h_neg_data h_neg_shape(::dffw_msgs::msg::TrainForward::_h_neg_shape_type arg)
  {
    msg_.h_neg_shape = std::move(arg);
    return Init_TrainForward_h_neg_data(msg_);
  }

private:
  ::dffw_msgs::msg::TrainForward msg_;
};

class Init_TrainForward_h_pos_data
{
public:
  explicit Init_TrainForward_h_pos_data(::dffw_msgs::msg::TrainForward & msg)
  : msg_(msg)
  {}
  Init_TrainForward_h_neg_shape h_pos_data(::dffw_msgs::msg::TrainForward::_h_pos_data_type arg)
  {
    msg_.h_pos_data = std::move(arg);
    return Init_TrainForward_h_neg_shape(msg_);
  }

private:
  ::dffw_msgs::msg::TrainForward msg_;
};

class Init_TrainForward_h_pos_shape
{
public:
  Init_TrainForward_h_pos_shape()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrainForward_h_pos_data h_pos_shape(::dffw_msgs::msg::TrainForward::_h_pos_shape_type arg)
  {
    msg_.h_pos_shape = std::move(arg);
    return Init_TrainForward_h_pos_data(msg_);
  }

private:
  ::dffw_msgs::msg::TrainForward msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dffw_msgs::msg::TrainForward>()
{
  return dffw_msgs::msg::builder::Init_TrainForward_h_pos_shape();
}

}  // namespace dffw_msgs

#endif  // DFFW_MSGS__MSG__DETAIL__TRAIN_FORWARD__BUILDER_HPP_
