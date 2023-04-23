// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dffw_msgs:msg/InferanceForward.idl
// generated code does not contain a copyright notice

#ifndef DFFW_MSGS__MSG__DETAIL__INFERANCE_FORWARD__TRAITS_HPP_
#define DFFW_MSGS__MSG__DETAIL__INFERANCE_FORWARD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dffw_msgs/msg/detail/inferance_forward__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace dffw_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const InferanceForward & msg,
  std::ostream & out)
{
  out << "{";
  // member: h_shape
  {
    if (msg.h_shape.size() == 0) {
      out << "h_shape: []";
    } else {
      out << "h_shape: [";
      size_t pending_items = msg.h_shape.size();
      for (auto item : msg.h_shape) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: h_data
  {
    if (msg.h_data.size() == 0) {
      out << "h_data: []";
    } else {
      out << "h_data: [";
      size_t pending_items = msg.h_data.size();
      for (auto item : msg.h_data) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: goodness_shape
  {
    if (msg.goodness_shape.size() == 0) {
      out << "goodness_shape: []";
    } else {
      out << "goodness_shape: [";
      size_t pending_items = msg.goodness_shape.size();
      for (auto item : msg.goodness_shape) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: goodness_data
  {
    if (msg.goodness_data.size() == 0) {
      out << "goodness_data: []";
    } else {
      out << "goodness_data: [";
      size_t pending_items = msg.goodness_data.size();
      for (auto item : msg.goodness_data) {
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
  const InferanceForward & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: h_shape
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.h_shape.size() == 0) {
      out << "h_shape: []\n";
    } else {
      out << "h_shape:\n";
      for (auto item : msg.h_shape) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: h_data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.h_data.size() == 0) {
      out << "h_data: []\n";
    } else {
      out << "h_data:\n";
      for (auto item : msg.h_data) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: goodness_shape
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.goodness_shape.size() == 0) {
      out << "goodness_shape: []\n";
    } else {
      out << "goodness_shape:\n";
      for (auto item : msg.goodness_shape) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: goodness_data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.goodness_data.size() == 0) {
      out << "goodness_data: []\n";
    } else {
      out << "goodness_data:\n";
      for (auto item : msg.goodness_data) {
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

inline std::string to_yaml(const InferanceForward & msg, bool use_flow_style = false)
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
  const dffw_msgs::msg::InferanceForward & msg,
  std::ostream & out, size_t indentation = 0)
{
  dffw_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dffw_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const dffw_msgs::msg::InferanceForward & msg)
{
  return dffw_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<dffw_msgs::msg::InferanceForward>()
{
  return "dffw_msgs::msg::InferanceForward";
}

template<>
inline const char * name<dffw_msgs::msg::InferanceForward>()
{
  return "dffw_msgs/msg/InferanceForward";
}

template<>
struct has_fixed_size<dffw_msgs::msg::InferanceForward>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<dffw_msgs::msg::InferanceForward>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<dffw_msgs::msg::InferanceForward>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DFFW_MSGS__MSG__DETAIL__INFERANCE_FORWARD__TRAITS_HPP_
