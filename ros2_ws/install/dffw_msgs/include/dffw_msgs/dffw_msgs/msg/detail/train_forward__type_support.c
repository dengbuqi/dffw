// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from dffw_msgs:msg/TrainForward.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "dffw_msgs/msg/detail/train_forward__rosidl_typesupport_introspection_c.h"
#include "dffw_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "dffw_msgs/msg/detail/train_forward__functions.h"
#include "dffw_msgs/msg/detail/train_forward__struct.h"


// Include directives for member types
// Member `h_pos_shape`
// Member `h_pos_data`
// Member `h_neg_shape`
// Member `h_neg_data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__TrainForward_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  dffw_msgs__msg__TrainForward__init(message_memory);
}

void dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__TrainForward_fini_function(void * message_memory)
{
  dffw_msgs__msg__TrainForward__fini(message_memory);
}

size_t dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__size_function__TrainForward__h_pos_shape(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__get_const_function__TrainForward__h_pos_shape(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__get_function__TrainForward__h_pos_shape(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__fetch_function__TrainForward__h_pos_shape(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__get_const_function__TrainForward__h_pos_shape(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__assign_function__TrainForward__h_pos_shape(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__get_function__TrainForward__h_pos_shape(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__resize_function__TrainForward__h_pos_shape(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

size_t dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__size_function__TrainForward__h_pos_data(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__get_const_function__TrainForward__h_pos_data(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__get_function__TrainForward__h_pos_data(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__fetch_function__TrainForward__h_pos_data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__get_const_function__TrainForward__h_pos_data(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__assign_function__TrainForward__h_pos_data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__get_function__TrainForward__h_pos_data(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__resize_function__TrainForward__h_pos_data(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__size_function__TrainForward__h_neg_shape(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__get_const_function__TrainForward__h_neg_shape(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__get_function__TrainForward__h_neg_shape(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__fetch_function__TrainForward__h_neg_shape(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__get_const_function__TrainForward__h_neg_shape(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__assign_function__TrainForward__h_neg_shape(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__get_function__TrainForward__h_neg_shape(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__resize_function__TrainForward__h_neg_shape(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

size_t dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__size_function__TrainForward__h_neg_data(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__get_const_function__TrainForward__h_neg_data(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__get_function__TrainForward__h_neg_data(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__fetch_function__TrainForward__h_neg_data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__get_const_function__TrainForward__h_neg_data(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__assign_function__TrainForward__h_neg_data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__get_function__TrainForward__h_neg_data(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__resize_function__TrainForward__h_neg_data(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__TrainForward_message_member_array[4] = {
  {
    "h_pos_shape",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dffw_msgs__msg__TrainForward, h_pos_shape),  // bytes offset in struct
    NULL,  // default value
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__size_function__TrainForward__h_pos_shape,  // size() function pointer
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__get_const_function__TrainForward__h_pos_shape,  // get_const(index) function pointer
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__get_function__TrainForward__h_pos_shape,  // get(index) function pointer
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__fetch_function__TrainForward__h_pos_shape,  // fetch(index, &value) function pointer
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__assign_function__TrainForward__h_pos_shape,  // assign(index, value) function pointer
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__resize_function__TrainForward__h_pos_shape  // resize(index) function pointer
  },
  {
    "h_pos_data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dffw_msgs__msg__TrainForward, h_pos_data),  // bytes offset in struct
    NULL,  // default value
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__size_function__TrainForward__h_pos_data,  // size() function pointer
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__get_const_function__TrainForward__h_pos_data,  // get_const(index) function pointer
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__get_function__TrainForward__h_pos_data,  // get(index) function pointer
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__fetch_function__TrainForward__h_pos_data,  // fetch(index, &value) function pointer
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__assign_function__TrainForward__h_pos_data,  // assign(index, value) function pointer
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__resize_function__TrainForward__h_pos_data  // resize(index) function pointer
  },
  {
    "h_neg_shape",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dffw_msgs__msg__TrainForward, h_neg_shape),  // bytes offset in struct
    NULL,  // default value
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__size_function__TrainForward__h_neg_shape,  // size() function pointer
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__get_const_function__TrainForward__h_neg_shape,  // get_const(index) function pointer
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__get_function__TrainForward__h_neg_shape,  // get(index) function pointer
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__fetch_function__TrainForward__h_neg_shape,  // fetch(index, &value) function pointer
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__assign_function__TrainForward__h_neg_shape,  // assign(index, value) function pointer
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__resize_function__TrainForward__h_neg_shape  // resize(index) function pointer
  },
  {
    "h_neg_data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dffw_msgs__msg__TrainForward, h_neg_data),  // bytes offset in struct
    NULL,  // default value
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__size_function__TrainForward__h_neg_data,  // size() function pointer
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__get_const_function__TrainForward__h_neg_data,  // get_const(index) function pointer
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__get_function__TrainForward__h_neg_data,  // get(index) function pointer
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__fetch_function__TrainForward__h_neg_data,  // fetch(index, &value) function pointer
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__assign_function__TrainForward__h_neg_data,  // assign(index, value) function pointer
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__resize_function__TrainForward__h_neg_data  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__TrainForward_message_members = {
  "dffw_msgs__msg",  // message namespace
  "TrainForward",  // message name
  4,  // number of fields
  sizeof(dffw_msgs__msg__TrainForward),
  dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__TrainForward_message_member_array,  // message members
  dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__TrainForward_init_function,  // function to initialize message memory (memory has to be allocated)
  dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__TrainForward_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__TrainForward_message_type_support_handle = {
  0,
  &dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__TrainForward_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_dffw_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dffw_msgs, msg, TrainForward)() {
  if (!dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__TrainForward_message_type_support_handle.typesupport_identifier) {
    dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__TrainForward_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &dffw_msgs__msg__TrainForward__rosidl_typesupport_introspection_c__TrainForward_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
