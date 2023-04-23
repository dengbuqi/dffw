// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dffw_msgs:msg/InferanceForward.idl
// generated code does not contain a copyright notice

#ifndef DFFW_MSGS__MSG__DETAIL__INFERANCE_FORWARD__STRUCT_H_
#define DFFW_MSGS__MSG__DETAIL__INFERANCE_FORWARD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'h_shape'
// Member 'h_data'
// Member 'goodness_shape'
// Member 'goodness_data'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/InferanceForward in the package dffw_msgs.
typedef struct dffw_msgs__msg__InferanceForward
{
  rosidl_runtime_c__int32__Sequence h_shape;
  rosidl_runtime_c__float__Sequence h_data;
  rosidl_runtime_c__int32__Sequence goodness_shape;
  rosidl_runtime_c__float__Sequence goodness_data;
} dffw_msgs__msg__InferanceForward;

// Struct for a sequence of dffw_msgs__msg__InferanceForward.
typedef struct dffw_msgs__msg__InferanceForward__Sequence
{
  dffw_msgs__msg__InferanceForward * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dffw_msgs__msg__InferanceForward__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DFFW_MSGS__MSG__DETAIL__INFERANCE_FORWARD__STRUCT_H_
