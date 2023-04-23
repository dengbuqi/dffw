// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dffw_msgs:msg/PytorchTensorFloat32.idl
// generated code does not contain a copyright notice

#ifndef DFFW_MSGS__MSG__DETAIL__PYTORCH_TENSOR_FLOAT32__BUILDER_HPP_
#define DFFW_MSGS__MSG__DETAIL__PYTORCH_TENSOR_FLOAT32__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dffw_msgs/msg/detail/pytorch_tensor_float32__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dffw_msgs
{

namespace msg
{

namespace builder
{

class Init_PytorchTensorFloat32_data
{
public:
  explicit Init_PytorchTensorFloat32_data(::dffw_msgs::msg::PytorchTensorFloat32 & msg)
  : msg_(msg)
  {}
  ::dffw_msgs::msg::PytorchTensorFloat32 data(::dffw_msgs::msg::PytorchTensorFloat32::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dffw_msgs::msg::PytorchTensorFloat32 msg_;
};

class Init_PytorchTensorFloat32_shape
{
public:
  Init_PytorchTensorFloat32_shape()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PytorchTensorFloat32_data shape(::dffw_msgs::msg::PytorchTensorFloat32::_shape_type arg)
  {
    msg_.shape = std::move(arg);
    return Init_PytorchTensorFloat32_data(msg_);
  }

private:
  ::dffw_msgs::msg::PytorchTensorFloat32 msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dffw_msgs::msg::PytorchTensorFloat32>()
{
  return dffw_msgs::msg::builder::Init_PytorchTensorFloat32_shape();
}

}  // namespace dffw_msgs

#endif  // DFFW_MSGS__MSG__DETAIL__PYTORCH_TENSOR_FLOAT32__BUILDER_HPP_
