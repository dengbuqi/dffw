// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dffw_msgs:msg/InferanceForward.idl
// generated code does not contain a copyright notice
#include "dffw_msgs/msg/detail/inferance_forward__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `h_shape`
// Member `h_data`
// Member `goodness_shape`
// Member `goodness_data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
dffw_msgs__msg__InferanceForward__init(dffw_msgs__msg__InferanceForward * msg)
{
  if (!msg) {
    return false;
  }
  // h_shape
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->h_shape, 0)) {
    dffw_msgs__msg__InferanceForward__fini(msg);
    return false;
  }
  // h_data
  if (!rosidl_runtime_c__float__Sequence__init(&msg->h_data, 0)) {
    dffw_msgs__msg__InferanceForward__fini(msg);
    return false;
  }
  // goodness_shape
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->goodness_shape, 0)) {
    dffw_msgs__msg__InferanceForward__fini(msg);
    return false;
  }
  // goodness_data
  if (!rosidl_runtime_c__float__Sequence__init(&msg->goodness_data, 0)) {
    dffw_msgs__msg__InferanceForward__fini(msg);
    return false;
  }
  return true;
}

void
dffw_msgs__msg__InferanceForward__fini(dffw_msgs__msg__InferanceForward * msg)
{
  if (!msg) {
    return;
  }
  // h_shape
  rosidl_runtime_c__int32__Sequence__fini(&msg->h_shape);
  // h_data
  rosidl_runtime_c__float__Sequence__fini(&msg->h_data);
  // goodness_shape
  rosidl_runtime_c__int32__Sequence__fini(&msg->goodness_shape);
  // goodness_data
  rosidl_runtime_c__float__Sequence__fini(&msg->goodness_data);
}

bool
dffw_msgs__msg__InferanceForward__are_equal(const dffw_msgs__msg__InferanceForward * lhs, const dffw_msgs__msg__InferanceForward * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // h_shape
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->h_shape), &(rhs->h_shape)))
  {
    return false;
  }
  // h_data
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->h_data), &(rhs->h_data)))
  {
    return false;
  }
  // goodness_shape
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->goodness_shape), &(rhs->goodness_shape)))
  {
    return false;
  }
  // goodness_data
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->goodness_data), &(rhs->goodness_data)))
  {
    return false;
  }
  return true;
}

bool
dffw_msgs__msg__InferanceForward__copy(
  const dffw_msgs__msg__InferanceForward * input,
  dffw_msgs__msg__InferanceForward * output)
{
  if (!input || !output) {
    return false;
  }
  // h_shape
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->h_shape), &(output->h_shape)))
  {
    return false;
  }
  // h_data
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->h_data), &(output->h_data)))
  {
    return false;
  }
  // goodness_shape
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->goodness_shape), &(output->goodness_shape)))
  {
    return false;
  }
  // goodness_data
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->goodness_data), &(output->goodness_data)))
  {
    return false;
  }
  return true;
}

dffw_msgs__msg__InferanceForward *
dffw_msgs__msg__InferanceForward__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dffw_msgs__msg__InferanceForward * msg = (dffw_msgs__msg__InferanceForward *)allocator.allocate(sizeof(dffw_msgs__msg__InferanceForward), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dffw_msgs__msg__InferanceForward));
  bool success = dffw_msgs__msg__InferanceForward__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dffw_msgs__msg__InferanceForward__destroy(dffw_msgs__msg__InferanceForward * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dffw_msgs__msg__InferanceForward__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dffw_msgs__msg__InferanceForward__Sequence__init(dffw_msgs__msg__InferanceForward__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dffw_msgs__msg__InferanceForward * data = NULL;

  if (size) {
    data = (dffw_msgs__msg__InferanceForward *)allocator.zero_allocate(size, sizeof(dffw_msgs__msg__InferanceForward), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dffw_msgs__msg__InferanceForward__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dffw_msgs__msg__InferanceForward__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
dffw_msgs__msg__InferanceForward__Sequence__fini(dffw_msgs__msg__InferanceForward__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      dffw_msgs__msg__InferanceForward__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

dffw_msgs__msg__InferanceForward__Sequence *
dffw_msgs__msg__InferanceForward__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dffw_msgs__msg__InferanceForward__Sequence * array = (dffw_msgs__msg__InferanceForward__Sequence *)allocator.allocate(sizeof(dffw_msgs__msg__InferanceForward__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dffw_msgs__msg__InferanceForward__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dffw_msgs__msg__InferanceForward__Sequence__destroy(dffw_msgs__msg__InferanceForward__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dffw_msgs__msg__InferanceForward__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dffw_msgs__msg__InferanceForward__Sequence__are_equal(const dffw_msgs__msg__InferanceForward__Sequence * lhs, const dffw_msgs__msg__InferanceForward__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dffw_msgs__msg__InferanceForward__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dffw_msgs__msg__InferanceForward__Sequence__copy(
  const dffw_msgs__msg__InferanceForward__Sequence * input,
  dffw_msgs__msg__InferanceForward__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dffw_msgs__msg__InferanceForward);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dffw_msgs__msg__InferanceForward * data =
      (dffw_msgs__msg__InferanceForward *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dffw_msgs__msg__InferanceForward__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dffw_msgs__msg__InferanceForward__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dffw_msgs__msg__InferanceForward__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
