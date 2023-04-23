// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from dffw_msgs:msg/PytorchTensorFloat32.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "dffw_msgs/msg/detail/pytorch_tensor_float32__struct.hpp"
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

void PytorchTensorFloat32_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) dffw_msgs::msg::PytorchTensorFloat32(_init);
}

void PytorchTensorFloat32_fini_function(void * message_memory)
{
  auto typed_message = static_cast<dffw_msgs::msg::PytorchTensorFloat32 *>(message_memory);
  typed_message->~PytorchTensorFloat32();
}

size_t size_function__PytorchTensorFloat32__shape(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__PytorchTensorFloat32__shape(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void * get_function__PytorchTensorFloat32__shape(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__PytorchTensorFloat32__shape(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int32_t *>(
    get_const_function__PytorchTensorFloat32__shape(untyped_member, index));
  auto & value = *reinterpret_cast<int32_t *>(untyped_value);
  value = item;
}

void assign_function__PytorchTensorFloat32__shape(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int32_t *>(
    get_function__PytorchTensorFloat32__shape(untyped_member, index));
  const auto & value = *reinterpret_cast<const int32_t *>(untyped_value);
  item = value;
}

void resize_function__PytorchTensorFloat32__shape(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  member->resize(size);
}

size_t size_function__PytorchTensorFloat32__data(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__PytorchTensorFloat32__data(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__PytorchTensorFloat32__data(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__PytorchTensorFloat32__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__PytorchTensorFloat32__data(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__PytorchTensorFloat32__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__PytorchTensorFloat32__data(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__PytorchTensorFloat32__data(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember PytorchTensorFloat32_message_member_array[2] = {
  {
    "shape",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dffw_msgs::msg::PytorchTensorFloat32, shape),  // bytes offset in struct
    nullptr,  // default value
    size_function__PytorchTensorFloat32__shape,  // size() function pointer
    get_const_function__PytorchTensorFloat32__shape,  // get_const(index) function pointer
    get_function__PytorchTensorFloat32__shape,  // get(index) function pointer
    fetch_function__PytorchTensorFloat32__shape,  // fetch(index, &value) function pointer
    assign_function__PytorchTensorFloat32__shape,  // assign(index, value) function pointer
    resize_function__PytorchTensorFloat32__shape  // resize(index) function pointer
  },
  {
    "data",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dffw_msgs::msg::PytorchTensorFloat32, data),  // bytes offset in struct
    nullptr,  // default value
    size_function__PytorchTensorFloat32__data,  // size() function pointer
    get_const_function__PytorchTensorFloat32__data,  // get_const(index) function pointer
    get_function__PytorchTensorFloat32__data,  // get(index) function pointer
    fetch_function__PytorchTensorFloat32__data,  // fetch(index, &value) function pointer
    assign_function__PytorchTensorFloat32__data,  // assign(index, value) function pointer
    resize_function__PytorchTensorFloat32__data  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers PytorchTensorFloat32_message_members = {
  "dffw_msgs::msg",  // message namespace
  "PytorchTensorFloat32",  // message name
  2,  // number of fields
  sizeof(dffw_msgs::msg::PytorchTensorFloat32),
  PytorchTensorFloat32_message_member_array,  // message members
  PytorchTensorFloat32_init_function,  // function to initialize message memory (memory has to be allocated)
  PytorchTensorFloat32_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t PytorchTensorFloat32_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PytorchTensorFloat32_message_members,
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
get_message_type_support_handle<dffw_msgs::msg::PytorchTensorFloat32>()
{
  return &::dffw_msgs::msg::rosidl_typesupport_introspection_cpp::PytorchTensorFloat32_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, dffw_msgs, msg, PytorchTensorFloat32)() {
  return &::dffw_msgs::msg::rosidl_typesupport_introspection_cpp::PytorchTensorFloat32_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
