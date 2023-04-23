// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dffw_msgs:msg/TrainForward.idl
// generated code does not contain a copyright notice

#ifndef DFFW_MSGS__MSG__DETAIL__TRAIN_FORWARD__STRUCT_H_
#define DFFW_MSGS__MSG__DETAIL__TRAIN_FORWARD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'h_pos_shape'
// Member 'h_pos_data'
// Member 'h_neg_shape'
// Member 'h_neg_data'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/TrainForward in the package dffw_msgs.
typedef struct dffw_msgs__msg__TrainForward
{
  rosidl_runtime_c__int32__Sequence h_pos_shape;
  rosidl_runtime_c__float__Sequence h_pos_data;
  rosidl_runtime_c__int32__Sequence h_neg_shape;
  rosidl_runtime_c__float__Sequence h_neg_data;
} dffw_msgs__msg__TrainForward;

// Struct for a sequence of dffw_msgs__msg__TrainForward.
typedef struct dffw_msgs__msg__TrainForward__Sequence
{
  dffw_msgs__msg__TrainForward * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dffw_msgs__msg__TrainForward__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DFFW_MSGS__MSG__DETAIL__TRAIN_FORWARD__STRUCT_H_
