// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dffw_msgs:msg/PytorchTensorFloat32.idl
// generated code does not contain a copyright notice

#ifndef DFFW_MSGS__MSG__DETAIL__PYTORCH_TENSOR_FLOAT32__STRUCT_H_
#define DFFW_MSGS__MSG__DETAIL__PYTORCH_TENSOR_FLOAT32__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'shape'
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/PytorchTensorFloat32 in the package dffw_msgs.
/**
  * PyTorch Tensor message
 */
typedef struct dffw_msgs__msg__PytorchTensorFloat32
{
  rosidl_runtime_c__int32__Sequence shape;
  rosidl_runtime_c__float__Sequence data;
} dffw_msgs__msg__PytorchTensorFloat32;

// Struct for a sequence of dffw_msgs__msg__PytorchTensorFloat32.
typedef struct dffw_msgs__msg__PytorchTensorFloat32__Sequence
{
  dffw_msgs__msg__PytorchTensorFloat32 * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dffw_msgs__msg__PytorchTensorFloat32__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DFFW_MSGS__MSG__DETAIL__PYTORCH_TENSOR_FLOAT32__STRUCT_H_
