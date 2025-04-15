// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from empty_shelf_msgs:msg/EmptyShelfAlert.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "empty_shelf_msgs/msg/detail/empty_shelf_alert__rosidl_typesupport_introspection_c.h"
#include "empty_shelf_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "empty_shelf_msgs/msg/detail/empty_shelf_alert__functions.h"
#include "empty_shelf_msgs/msg/detail/empty_shelf_alert__struct.h"


// Include directives for member types
// Member `timestamp`
#include "builtin_interfaces/msg/time.h"
// Member `timestamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"
// Member `status`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void empty_shelf_msgs__msg__EmptyShelfAlert__rosidl_typesupport_introspection_c__EmptyShelfAlert_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  empty_shelf_msgs__msg__EmptyShelfAlert__init(message_memory);
}

void empty_shelf_msgs__msg__EmptyShelfAlert__rosidl_typesupport_introspection_c__EmptyShelfAlert_fini_function(void * message_memory)
{
  empty_shelf_msgs__msg__EmptyShelfAlert__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember empty_shelf_msgs__msg__EmptyShelfAlert__rosidl_typesupport_introspection_c__EmptyShelfAlert_message_member_array[7] = {
  {
    "timestamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(empty_shelf_msgs__msg__EmptyShelfAlert, timestamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "shelf_level",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(empty_shelf_msgs__msg__EmptyShelfAlert, shelf_level),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(empty_shelf_msgs__msg__EmptyShelfAlert, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(empty_shelf_msgs__msg__EmptyShelfAlert, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "depth",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(empty_shelf_msgs__msg__EmptyShelfAlert, depth),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "confidence",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(empty_shelf_msgs__msg__EmptyShelfAlert, confidence),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(empty_shelf_msgs__msg__EmptyShelfAlert, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers empty_shelf_msgs__msg__EmptyShelfAlert__rosidl_typesupport_introspection_c__EmptyShelfAlert_message_members = {
  "empty_shelf_msgs__msg",  // message namespace
  "EmptyShelfAlert",  // message name
  7,  // number of fields
  sizeof(empty_shelf_msgs__msg__EmptyShelfAlert),
  empty_shelf_msgs__msg__EmptyShelfAlert__rosidl_typesupport_introspection_c__EmptyShelfAlert_message_member_array,  // message members
  empty_shelf_msgs__msg__EmptyShelfAlert__rosidl_typesupport_introspection_c__EmptyShelfAlert_init_function,  // function to initialize message memory (memory has to be allocated)
  empty_shelf_msgs__msg__EmptyShelfAlert__rosidl_typesupport_introspection_c__EmptyShelfAlert_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t empty_shelf_msgs__msg__EmptyShelfAlert__rosidl_typesupport_introspection_c__EmptyShelfAlert_message_type_support_handle = {
  0,
  &empty_shelf_msgs__msg__EmptyShelfAlert__rosidl_typesupport_introspection_c__EmptyShelfAlert_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_empty_shelf_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, empty_shelf_msgs, msg, EmptyShelfAlert)() {
  empty_shelf_msgs__msg__EmptyShelfAlert__rosidl_typesupport_introspection_c__EmptyShelfAlert_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!empty_shelf_msgs__msg__EmptyShelfAlert__rosidl_typesupport_introspection_c__EmptyShelfAlert_message_type_support_handle.typesupport_identifier) {
    empty_shelf_msgs__msg__EmptyShelfAlert__rosidl_typesupport_introspection_c__EmptyShelfAlert_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &empty_shelf_msgs__msg__EmptyShelfAlert__rosidl_typesupport_introspection_c__EmptyShelfAlert_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
