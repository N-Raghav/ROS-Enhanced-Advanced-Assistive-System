// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from empty_shelf_msgs:msg/EmptyShelfAlert.idl
// generated code does not contain a copyright notice
#include "empty_shelf_msgs/msg/detail/empty_shelf_alert__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `timestamp`
#include "builtin_interfaces/msg/detail/time__functions.h"
// Member `status`
#include "rosidl_runtime_c/string_functions.h"

bool
empty_shelf_msgs__msg__EmptyShelfAlert__init(empty_shelf_msgs__msg__EmptyShelfAlert * msg)
{
  if (!msg) {
    return false;
  }
  // timestamp
  if (!builtin_interfaces__msg__Time__init(&msg->timestamp)) {
    empty_shelf_msgs__msg__EmptyShelfAlert__fini(msg);
    return false;
  }
  // shelf_level
  // x
  // y
  // depth
  // confidence
  // status
  if (!rosidl_runtime_c__String__init(&msg->status)) {
    empty_shelf_msgs__msg__EmptyShelfAlert__fini(msg);
    return false;
  }
  return true;
}

void
empty_shelf_msgs__msg__EmptyShelfAlert__fini(empty_shelf_msgs__msg__EmptyShelfAlert * msg)
{
  if (!msg) {
    return;
  }
  // timestamp
  builtin_interfaces__msg__Time__fini(&msg->timestamp);
  // shelf_level
  // x
  // y
  // depth
  // confidence
  // status
  rosidl_runtime_c__String__fini(&msg->status);
}

bool
empty_shelf_msgs__msg__EmptyShelfAlert__are_equal(const empty_shelf_msgs__msg__EmptyShelfAlert * lhs, const empty_shelf_msgs__msg__EmptyShelfAlert * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // timestamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->timestamp), &(rhs->timestamp)))
  {
    return false;
  }
  // shelf_level
  if (lhs->shelf_level != rhs->shelf_level) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // depth
  if (lhs->depth != rhs->depth) {
    return false;
  }
  // confidence
  if (lhs->confidence != rhs->confidence) {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->status), &(rhs->status)))
  {
    return false;
  }
  return true;
}

bool
empty_shelf_msgs__msg__EmptyShelfAlert__copy(
  const empty_shelf_msgs__msg__EmptyShelfAlert * input,
  empty_shelf_msgs__msg__EmptyShelfAlert * output)
{
  if (!input || !output) {
    return false;
  }
  // timestamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->timestamp), &(output->timestamp)))
  {
    return false;
  }
  // shelf_level
  output->shelf_level = input->shelf_level;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // depth
  output->depth = input->depth;
  // confidence
  output->confidence = input->confidence;
  // status
  if (!rosidl_runtime_c__String__copy(
      &(input->status), &(output->status)))
  {
    return false;
  }
  return true;
}

empty_shelf_msgs__msg__EmptyShelfAlert *
empty_shelf_msgs__msg__EmptyShelfAlert__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  empty_shelf_msgs__msg__EmptyShelfAlert * msg = (empty_shelf_msgs__msg__EmptyShelfAlert *)allocator.allocate(sizeof(empty_shelf_msgs__msg__EmptyShelfAlert), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(empty_shelf_msgs__msg__EmptyShelfAlert));
  bool success = empty_shelf_msgs__msg__EmptyShelfAlert__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
empty_shelf_msgs__msg__EmptyShelfAlert__destroy(empty_shelf_msgs__msg__EmptyShelfAlert * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    empty_shelf_msgs__msg__EmptyShelfAlert__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
empty_shelf_msgs__msg__EmptyShelfAlert__Sequence__init(empty_shelf_msgs__msg__EmptyShelfAlert__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  empty_shelf_msgs__msg__EmptyShelfAlert * data = NULL;

  if (size) {
    data = (empty_shelf_msgs__msg__EmptyShelfAlert *)allocator.zero_allocate(size, sizeof(empty_shelf_msgs__msg__EmptyShelfAlert), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = empty_shelf_msgs__msg__EmptyShelfAlert__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        empty_shelf_msgs__msg__EmptyShelfAlert__fini(&data[i - 1]);
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
empty_shelf_msgs__msg__EmptyShelfAlert__Sequence__fini(empty_shelf_msgs__msg__EmptyShelfAlert__Sequence * array)
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
      empty_shelf_msgs__msg__EmptyShelfAlert__fini(&array->data[i]);
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

empty_shelf_msgs__msg__EmptyShelfAlert__Sequence *
empty_shelf_msgs__msg__EmptyShelfAlert__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  empty_shelf_msgs__msg__EmptyShelfAlert__Sequence * array = (empty_shelf_msgs__msg__EmptyShelfAlert__Sequence *)allocator.allocate(sizeof(empty_shelf_msgs__msg__EmptyShelfAlert__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = empty_shelf_msgs__msg__EmptyShelfAlert__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
empty_shelf_msgs__msg__EmptyShelfAlert__Sequence__destroy(empty_shelf_msgs__msg__EmptyShelfAlert__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    empty_shelf_msgs__msg__EmptyShelfAlert__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
empty_shelf_msgs__msg__EmptyShelfAlert__Sequence__are_equal(const empty_shelf_msgs__msg__EmptyShelfAlert__Sequence * lhs, const empty_shelf_msgs__msg__EmptyShelfAlert__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!empty_shelf_msgs__msg__EmptyShelfAlert__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
empty_shelf_msgs__msg__EmptyShelfAlert__Sequence__copy(
  const empty_shelf_msgs__msg__EmptyShelfAlert__Sequence * input,
  empty_shelf_msgs__msg__EmptyShelfAlert__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(empty_shelf_msgs__msg__EmptyShelfAlert);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    empty_shelf_msgs__msg__EmptyShelfAlert * data =
      (empty_shelf_msgs__msg__EmptyShelfAlert *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!empty_shelf_msgs__msg__EmptyShelfAlert__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          empty_shelf_msgs__msg__EmptyShelfAlert__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!empty_shelf_msgs__msg__EmptyShelfAlert__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
