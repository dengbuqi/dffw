// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from dffw_msgs:msg/PytorchTensorFloat32.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "dffw_msgs/msg/detail/pytorch_tensor_float32__rosidl_typesupport_introspection_c.h"
#include "dffw_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "dffw_msgs/msg/detail/pytorch_tensor_float32__functions.h"
#include "dffw_msgs/msg/detail/pytorch_tensor_float32__struct.h"


// Include directives for member types
// Member `shape`
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__PytorchTensorFloat32_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  dffw_msgs__msg__PytorchTensorFloat32__init(message_memory);
}

void dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__PytorchTensorFloat32_fini_function(void * message_memory)
{
  dffw_msgs__msg__PytorchTensorFloat32__fini(message_memory);
}

size_t dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__size_function__PytorchTensorFloat32__shape(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__get_const_function__PytorchTensorFloat32__shape(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__get_function__PytorchTensorFloat32__shape(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__fetch_function__PytorchTensorFloat32__shape(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__get_const_function__PytorchTensorFloat32__shape(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__assign_function__PytorchTensorFloat32__shape(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__get_function__PytorchTensorFloat32__shape(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__resize_function__PytorchTensorFloat32__shape(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

size_t dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__size_function__PytorchTensorFloat32__data(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__get_const_function__PytorchTensorFloat32__data(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__get_function__PytorchTensorFloat32__data(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__fetch_function__PytorchTensorFloat32__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__get_const_function__PytorchTensorFloat32__data(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__assign_function__PytorchTensorFloat32__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__get_function__PytorchTensorFloat32__data(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__resize_function__PytorchTensorFloat32__data(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__PytorchTensorFloat32_message_member_array[2] = {
  {
    "shape",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dffw_msgs__msg__PytorchTensorFloat32, shape),  // bytes offset in struct
    NULL,  // default value
    dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__size_function__PytorchTensorFloat32__shape,  // size() function pointer
    dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__get_const_function__PytorchTensorFloat32__shape,  // get_const(index) function pointer
    dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__get_function__PytorchTensorFloat32__shape,  // get(index) function pointer
    dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__fetch_function__PytorchTensorFloat32__shape,  // fetch(index, &value) function pointer
    dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__assign_function__PytorchTensorFloat32__shape,  // assign(index, value) function pointer
    dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__resize_function__PytorchTensorFloat32__shape  // resize(index) function pointer
  },
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dffw_msgs__msg__PytorchTensorFloat32, data),  // bytes offset in struct
    NULL,  // default value
    dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__size_function__PytorchTensorFloat32__data,  // size() function pointer
    dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__get_const_function__PytorchTensorFloat32__data,  // get_const(index) function pointer
    dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__get_function__PytorchTensorFloat32__data,  // get(index) function pointer
    dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__fetch_function__PytorchTensorFloat32__data,  // fetch(index, &value) function pointer
    dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__assign_function__PytorchTensorFloat32__data,  // assign(index, value) function pointer
    dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__resize_function__PytorchTensorFloat32__data  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__PytorchTensorFloat32_message_members = {
  "dffw_msgs__msg",  // message namespace
  "PytorchTensorFloat32",  // message name
  2,  // number of fields
  sizeof(dffw_msgs__msg__PytorchTensorFloat32),
  dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__PytorchTensorFloat32_message_member_array,  // message members
  dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__PytorchTensorFloat32_init_function,  // function to initialize message memory (memory has to be allocated)
  dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__PytorchTensorFloat32_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__PytorchTensorFloat32_message_type_support_handle = {
  0,
  &dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__PytorchTensorFloat32_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_dffw_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dffw_msgs, msg, PytorchTensorFloat32)() {
  if (!dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__PytorchTensorFloat32_message_type_support_handle.typesupport_identifier) {
    dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__PytorchTensorFloat32_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &dffw_msgs__msg__PytorchTensorFloat32__rosidl_typesupport_introspection_c__PytorchTensorFloat32_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
