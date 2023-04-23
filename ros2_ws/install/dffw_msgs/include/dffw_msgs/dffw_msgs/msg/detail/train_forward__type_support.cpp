// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from dffw_msgs:msg/TrainForward.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "dffw_msgs/msg/detail/train_forward__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace dffw_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void TrainForward_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) dffw_msgs::msg::TrainForward(_init);
}

void TrainForward_fini_function(void * message_memory)
{
  auto typed_message = static_cast<dffw_msgs::msg::TrainForward *>(message_memory);
  typed_message->~TrainForward();
}

size_t size_function__TrainForward__h_pos_shape(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__TrainForward__h_pos_shape(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void * get_function__TrainForward__h_pos_shape(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__TrainForward__h_pos_shape(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int32_t *>(
    get_const_function__TrainForward__h_pos_shape(untyped_member, index));
  auto & value = *reinterpret_cast<int32_t *>(untyped_value);
  value = item;
}

void assign_function__TrainForward__h_pos_shape(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int32_t *>(
    get_function__TrainForward__h_pos_shape(untyped_member, index));
  const auto & value = *reinterpret_cast<const int32_t *>(untyped_value);
  item = value;
}

void resize_function__TrainForward__h_pos_shape(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  member->resize(size);
}

size_t size_function__TrainForward__h_pos_data(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__TrainForward__h_pos_data(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__TrainForward__h_pos_data(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__TrainForward__h_pos_data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__TrainForward__h_pos_data(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__TrainForward__h_pos_data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__TrainForward__h_pos_data(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__TrainForward__h_pos_data(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__TrainForward__h_neg_shape(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__TrainForward__h_neg_shape(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void * get_function__TrainForward__h_neg_shape(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__TrainForward__h_neg_shape(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int32_t *>(
    get_const_function__TrainForward__h_neg_shape(untyped_member, index));
  auto & value = *reinterpret_cast<int32_t *>(untyped_value);
  value = item;
}

void assign_function__TrainForward__h_neg_shape(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int32_t *>(
    get_function__TrainForward__h_neg_shape(untyped_member, index));
  const auto & value = *reinterpret_cast<const int32_t *>(untyped_value);
  item = value;
}

void resize_function__TrainForward__h_neg_shape(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  member->resize(size);
}

size_t size_function__TrainForward__h_neg_data(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__TrainForward__h_neg_data(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__TrainForward__h_neg_data(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__TrainForward__h_neg_data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__TrainForward__h_neg_data(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__TrainForward__h_neg_data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__TrainForward__h_neg_data(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__TrainForward__h_neg_data(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TrainForward_message_member_array[4] = {
  {
    "h_pos_shape",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dffw_msgs::msg::TrainForward, h_pos_shape),  // bytes offset in struct
    nullptr,  // default value
    size_function__TrainForward__h_pos_shape,  // size() function pointer
    get_const_function__TrainForward__h_pos_shape,  // get_const(index) function pointer
    get_function__TrainForward__h_pos_shape,  // get(index) function pointer
    fetch_function__TrainForward__h_pos_shape,  // fetch(index, &value) function pointer
    assign_function__TrainForward__h_pos_shape,  // assign(index, value) function pointer
    resize_function__TrainForward__h_pos_shape  // resize(index) function pointer
  },
  {
    "h_pos_data",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dffw_msgs::msg::TrainForward, h_pos_data),  // bytes offset in struct
    nullptr,  // default value
    size_function__TrainForward__h_pos_data,  // size() function pointer
    get_const_function__TrainForward__h_pos_data,  // get_const(index) function pointer
    get_function__TrainForward__h_pos_data,  // get(index) function pointer
    fetch_function__TrainForward__h_pos_data,  // fetch(index, &value) function pointer
    assign_function__TrainForward__h_pos_data,  // assign(index, value) function pointer
    resize_function__TrainForward__h_pos_data  // resize(index) function pointer
  },
  {
    "h_neg_shape",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dffw_msgs::msg::TrainForward, h_neg_shape),  // bytes offset in struct
    nullptr,  // default value
    size_function__TrainForward__h_neg_shape,  // size() function pointer
    get_const_function__TrainForward__h_neg_shape,  // get_const(index) function pointer
    get_function__TrainForward__h_neg_shape,  // get(index) function pointer
    fetch_function__TrainForward__h_neg_shape,  // fetch(index, &value) function pointer
    assign_function__TrainForward__h_neg_shape,  // assign(index, value) function pointer
    resize_function__TrainForward__h_neg_shape  // resize(index) function pointer
  },
  {
    "h_neg_data",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dffw_msgs::msg::TrainForward, h_neg_data),  // bytes offset in struct
    nullptr,  // default value
    size_function__TrainForward__h_neg_data,  // size() function pointer
    get_const_function__TrainForward__h_neg_data,  // get_const(index) function pointer
    get_function__TrainForward__h_neg_data,  // get(index) function pointer
    fetch_function__TrainForward__h_neg_data,  // fetch(index, &value) function pointer
    assign_function__TrainForward__h_neg_data,  // assign(index, value) function pointer
    resize_function__TrainForward__h_neg_data  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TrainForward_message_members = {
  "dffw_msgs::msg",  // message namespace
  "TrainForward",  // message name
  4,  // number of fields
  sizeof(dffw_msgs::msg::TrainForward),
  TrainForward_message_member_array,  // message members
  TrainForward_init_function,  // function to initialize message memory (memory has to be allocated)
  TrainForward_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TrainForward_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TrainForward_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace dffw_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<dffw_msgs::msg::TrainForward>()
{
  return &::dffw_msgs::msg::rosidl_typesupport_introspection_cpp::TrainForward_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, dffw_msgs, msg, TrainForward)() {
  return &::dffw_msgs::msg::rosidl_typesupport_introspection_cpp::TrainForward_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
