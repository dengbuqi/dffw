// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dffw_msgs:msg/PytorchTensorFloat32.idl
// generated code does not contain a copyright notice

#ifndef DFFW_MSGS__MSG__DETAIL__PYTORCH_TENSOR_FLOAT32__TRAITS_HPP_
#define DFFW_MSGS__MSG__DETAIL__PYTORCH_TENSOR_FLOAT32__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dffw_msgs/msg/detail/pytorch_tensor_float32__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace dffw_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const PytorchTensorFloat32 & msg,
  std::ostream & out)
{
  out << "{";
  // member: shape
  {
    if (msg.shape.size() == 0) {
      out << "shape: []";
    } else {
      out << "shape: [";
      size_t pending_items = msg.shape.size();
      for (auto item : msg.shape) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: data
  {
    if (msg.data.size() == 0) {
      out << "data: []";
    } else {
      out << "data: [";
      size_t pending_items = msg.data.size();
      for (auto item : msg.data) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PytorchTensorFloat32 & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: shape
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.shape.size() == 0) {
      out << "shape: []\n";
    } else {
      out << "shape:\n";
      for (auto item : msg.shape) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.data.size() == 0) {
      out << "data: []\n";
    } else {
      out << "data:\n";
      for (auto item : msg.data) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PytorchTensorFloat32 & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace dffw_msgs

namespace rosidl_generator_traits
{

[[deprecated("use dffw_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const dffw_msgs::msg::PytorchTensorFloat32 & msg,
  std::ostream & out, size_t indentation = 0)
{
  dffw_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dffw_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const dffw_msgs::msg::PytorchTensorFloat32 & msg)
{
  return dffw_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<dffw_msgs::msg::PytorchTensorFloat32>()
{
  return "dffw_msgs::msg::PytorchTensorFloat32";
}

template<>
inline const char * name<dffw_msgs::msg::PytorchTensorFloat32>()
{
  return "dffw_msgs/msg/PytorchTensorFloat32";
}

template<>
struct has_fixed_size<dffw_msgs::msg::PytorchTensorFloat32>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<dffw_msgs::msg::PytorchTensorFloat32>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<dffw_msgs::msg::PytorchTensorFloat32>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DFFW_MSGS__MSG__DETAIL__PYTORCH_TENSOR_FLOAT32__TRAITS_HPP_
