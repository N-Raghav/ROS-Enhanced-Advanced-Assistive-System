// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from empty_shelf_msgs:msg/EmptyShelfAlert.idl
// generated code does not contain a copyright notice

#ifndef EMPTY_SHELF_MSGS__MSG__DETAIL__EMPTY_SHELF_ALERT__STRUCT_H_
#define EMPTY_SHELF_MSGS__MSG__DETAIL__EMPTY_SHELF_ALERT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__struct.h"
// Member 'status'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/EmptyShelfAlert in the package empty_shelf_msgs.
typedef struct empty_shelf_msgs__msg__EmptyShelfAlert
{
  builtin_interfaces__msg__Time timestamp;
  int32_t shelf_level;
  float x;
  float y;
  float depth;
  float confidence;
  rosidl_runtime_c__String status;
} empty_shelf_msgs__msg__EmptyShelfAlert;

// Struct for a sequence of empty_shelf_msgs__msg__EmptyShelfAlert.
typedef struct empty_shelf_msgs__msg__EmptyShelfAlert__Sequence
{
  empty_shelf_msgs__msg__EmptyShelfAlert * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} empty_shelf_msgs__msg__EmptyShelfAlert__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // EMPTY_SHELF_MSGS__MSG__DETAIL__EMPTY_SHELF_ALERT__STRUCT_H_
