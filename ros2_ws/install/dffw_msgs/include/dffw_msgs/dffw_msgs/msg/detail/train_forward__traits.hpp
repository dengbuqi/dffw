// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dffw_msgs:msg/TrainForward.idl
// generated code does not contain a copyright notice

#ifndef DFFW_MSGS__MSG__DETAIL__TRAIN_FORWARD__TRAITS_HPP_
#define DFFW_MSGS__MSG__DETAIL__TRAIN_FORWARD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dffw_msgs/msg/detail/train_forward__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace dffw_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const TrainForward & msg,
  std::ostream & out)
{
  out << "{";
  // member: h_pos_shape
  {
    if (msg.h_pos_shape.size() == 0) {
      out << "h_pos_shape: []";
    } else {
      out << "h_pos_shape: [";
      size_t pending_items = msg.h_pos_shape.size();
      for (auto item : msg.h_pos_shape) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: h_pos_data
  {
    if (msg.h_pos_data.size() == 0) {
      out << "h_pos_data: []";
    } else {
      out << "h_pos_data: [";
      size_t pending_items = msg.h_pos_data.size();
      for (auto item : msg.h_pos_data) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: h_neg_shape
  {
    if (msg.h_neg_shape.size() == 0) {
      out << "h_neg_shape: []";
    } else {
      out << "h_neg_shape: [";
      size_t pending_items = msg.h_neg_shape.size();
      for (auto item : msg.h_neg_shape) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: h_neg_data
  {
    if (msg.h_neg_data.size() == 0) {
      out << "h_neg_data: []";
    } else {
      out << "h_neg_data: [";
      size_t pending_items = msg.h_neg_data.size();
      for (auto item : msg.h_neg_data) {
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
  const TrainForward & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: h_pos_shape
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.h_pos_shape.size() == 0) {
      out << "h_pos_shape: []\n";
    } else {
      out << "h_pos_shape:\n";
      for (auto item : msg.h_pos_shape) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: h_pos_data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.h_pos_data.size() == 0) {
      out << "h_pos_data: []\n";
    } else {
      out << "h_pos_data:\n";
      for (auto item : msg.h_pos_data) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: h_neg_shape
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.h_neg_shape.size() == 0) {
      out << "h_neg_shape: []\n";
    } else {
      out << "h_neg_shape:\n";
      for (auto item : msg.h_neg_shape) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: h_neg_data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.h_neg_data.size() == 0) {
      out << "h_neg_data: []\n";
    } else {
      out << "h_neg_data:\n";
      for (auto item : msg.h_neg_data) {
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

inline std::string to_yaml(const TrainForward & msg, bool use_flow_style = false)
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
  const dffw_msgs::msg::TrainForward & msg,
  std::ostream & out, size_t indentation = 0)
{
  dffw_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dffw_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const dffw_msgs::msg::TrainForward & msg)
{
  return dffw_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<dffw_msgs::msg::TrainForward>()
{
  return "dffw_msgs::msg::TrainForward";
}

template<>
inline const char * name<dffw_msgs::msg::TrainForward>()
{
  return "dffw_msgs/msg/TrainForward";
}

template<>
struct has_fixed_size<dffw_msgs::msg::TrainForward>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<dffw_msgs::msg::TrainForward>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<dffw_msgs::msg::TrainForward>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DFFW_MSGS__MSG__DETAIL__TRAIN_FORWARD__TRAITS_HPP_
