// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dffw_msgs:msg/TrainForward.idl
// generated code does not contain a copyright notice
#include "dffw_msgs/msg/detail/train_forward__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `h_pos_shape`
// Member `h_pos_data`
// Member `h_neg_shape`
// Member `h_neg_data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
dffw_msgs__msg__TrainForward__init(dffw_msgs__msg__TrainForward * msg)
{
  if (!msg) {
    return false;
  }
  // h_pos_shape
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->h_pos_shape, 0)) {
    dffw_msgs__msg__TrainForward__fini(msg);
    return false;
  }
  // h_pos_data
  if (!rosidl_runtime_c__float__Sequence__init(&msg->h_pos_data, 0)) {
    dffw_msgs__msg__TrainForward__fini(msg);
    return false;
  }
  // h_neg_shape
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->h_neg_shape, 0)) {
    dffw_msgs__msg__TrainForward__fini(msg);
    return false;
  }
  // h_neg_data
  if (!rosidl_runtime_c__float__Sequence__init(&msg->h_neg_data, 0)) {
    dffw_msgs__msg__TrainForward__fini(msg);
    return false;
  }
  return true;
}

void
dffw_msgs__msg__TrainForward__fini(dffw_msgs__msg__TrainForward * msg)
{
  if (!msg) {
    return;
  }
  // h_pos_shape
  rosidl_runtime_c__int32__Sequence__fini(&msg->h_pos_shape);
  // h_pos_data
  rosidl_runtime_c__float__Sequence__fini(&msg->h_pos_data);
  // h_neg_shape
  rosidl_runtime_c__int32__Sequence__fini(&msg->h_neg_shape);
  // h_neg_data
  rosidl_runtime_c__float__Sequence__fini(&msg->h_neg_data);
}

bool
dffw_msgs__msg__TrainForward__are_equal(const dffw_msgs__msg__TrainForward * lhs, const dffw_msgs__msg__TrainForward * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // h_pos_shape
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->h_pos_shape), &(rhs->h_pos_shape)))
  {
    return false;
  }
  // h_pos_data
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->h_pos_data), &(rhs->h_pos_data)))
  {
    return false;
  }
  // h_neg_shape
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->h_neg_shape), &(rhs->h_neg_shape)))
  {
    return false;
  }
  // h_neg_data
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->h_neg_data), &(rhs->h_neg_data)))
  {
    return false;
  }
  return true;
}

bool
dffw_msgs__msg__TrainForward__copy(
  const dffw_msgs__msg__TrainForward * input,
  dffw_msgs__msg__TrainForward * output)
{
  if (!input || !output) {
    return false;
  }
  // h_pos_shape
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->h_pos_shape), &(output->h_pos_shape)))
  {
    return false;
  }
  // h_pos_data
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->h_pos_data), &(output->h_pos_data)))
  {
    return false;
  }
  // h_neg_shape
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->h_neg_shape), &(output->h_neg_shape)))
  {
    return false;
  }
  // h_neg_data
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->h_neg_data), &(output->h_neg_data)))
  {
    return false;
  }
  return true;
}

dffw_msgs__msg__TrainForward *
dffw_msgs__msg__TrainForward__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dffw_msgs__msg__TrainForward * msg = (dffw_msgs__msg__TrainForward *)allocator.allocate(sizeof(dffw_msgs__msg__TrainForward), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dffw_msgs__msg__TrainForward));
  bool success = dffw_msgs__msg__TrainForward__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dffw_msgs__msg__TrainForward__destroy(dffw_msgs__msg__TrainForward * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dffw_msgs__msg__TrainForward__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dffw_msgs__msg__TrainForward__Sequence__init(dffw_msgs__msg__TrainForward__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dffw_msgs__msg__TrainForward * data = NULL;

  if (size) {
    data = (dffw_msgs__msg__TrainForward *)allocator.zero_allocate(size, sizeof(dffw_msgs__msg__TrainForward), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dffw_msgs__msg__TrainForward__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dffw_msgs__msg__TrainForward__fini(&data[i - 1]);
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
dffw_msgs__msg__TrainForward__Sequence__fini(dffw_msgs__msg__TrainForward__Sequence * array)
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
      dffw_msgs__msg__TrainForward__fini(&array->data[i]);
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

dffw_msgs__msg__TrainForward__Sequence *
dffw_msgs__msg__TrainForward__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dffw_msgs__msg__TrainForward__Sequence * array = (dffw_msgs__msg__TrainForward__Sequence *)allocator.allocate(sizeof(dffw_msgs__msg__TrainForward__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dffw_msgs__msg__TrainForward__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dffw_msgs__msg__TrainForward__Sequence__destroy(dffw_msgs__msg__TrainForward__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dffw_msgs__msg__TrainForward__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dffw_msgs__msg__TrainForward__Sequence__are_equal(const dffw_msgs__msg__TrainForward__Sequence * lhs, const dffw_msgs__msg__TrainForward__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dffw_msgs__msg__TrainForward__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dffw_msgs__msg__TrainForward__Sequence__copy(
  const dffw_msgs__msg__TrainForward__Sequence * input,
  dffw_msgs__msg__TrainForward__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dffw_msgs__msg__TrainForward);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dffw_msgs__msg__TrainForward * data =
      (dffw_msgs__msg__TrainForward *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dffw_msgs__msg__TrainForward__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dffw_msgs__msg__TrainForward__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dffw_msgs__msg__TrainForward__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
