// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from empty_shelf_msgs:msg/EmptyShelfAlert.idl
// generated code does not contain a copyright notice

#ifndef EMPTY_SHELF_MSGS__MSG__DETAIL__EMPTY_SHELF_ALERT__FUNCTIONS_H_
#define EMPTY_SHELF_MSGS__MSG__DETAIL__EMPTY_SHELF_ALERT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "empty_shelf_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "empty_shelf_msgs/msg/detail/empty_shelf_alert__struct.h"

/// Initialize msg/EmptyShelfAlert message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * empty_shelf_msgs__msg__EmptyShelfAlert
 * )) before or use
 * empty_shelf_msgs__msg__EmptyShelfAlert__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_empty_shelf_msgs
bool
empty_shelf_msgs__msg__EmptyShelfAlert__init(empty_shelf_msgs__msg__EmptyShelfAlert * msg);

/// Finalize msg/EmptyShelfAlert message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_empty_shelf_msgs
void
empty_shelf_msgs__msg__EmptyShelfAlert__fini(empty_shelf_msgs__msg__EmptyShelfAlert * msg);

/// Create msg/EmptyShelfAlert message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * empty_shelf_msgs__msg__EmptyShelfAlert__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_empty_shelf_msgs
empty_shelf_msgs__msg__EmptyShelfAlert *
empty_shelf_msgs__msg__EmptyShelfAlert__create();

/// Destroy msg/EmptyShelfAlert message.
/**
 * It calls
 * empty_shelf_msgs__msg__EmptyShelfAlert__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_empty_shelf_msgs
void
empty_shelf_msgs__msg__EmptyShelfAlert__destroy(empty_shelf_msgs__msg__EmptyShelfAlert * msg);

/// Check for msg/EmptyShelfAlert message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_empty_shelf_msgs
bool
empty_shelf_msgs__msg__EmptyShelfAlert__are_equal(const empty_shelf_msgs__msg__EmptyShelfAlert * lhs, const empty_shelf_msgs__msg__EmptyShelfAlert * rhs);

/// Copy a msg/EmptyShelfAlert message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_empty_shelf_msgs
bool
empty_shelf_msgs__msg__EmptyShelfAlert__copy(
  const empty_shelf_msgs__msg__EmptyShelfAlert * input,
  empty_shelf_msgs__msg__EmptyShelfAlert * output);

/// Initialize array of msg/EmptyShelfAlert messages.
/**
 * It allocates the memory for the number of elements and calls
 * empty_shelf_msgs__msg__EmptyShelfAlert__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_empty_shelf_msgs
bool
empty_shelf_msgs__msg__EmptyShelfAlert__Sequence__init(empty_shelf_msgs__msg__EmptyShelfAlert__Sequence * array, size_t size);

/// Finalize array of msg/EmptyShelfAlert messages.
/**
 * It calls
 * empty_shelf_msgs__msg__EmptyShelfAlert__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_empty_shelf_msgs
void
empty_shelf_msgs__msg__EmptyShelfAlert__Sequence__fini(empty_shelf_msgs__msg__EmptyShelfAlert__Sequence * array);

/// Create array of msg/EmptyShelfAlert messages.
/**
 * It allocates the memory for the array and calls
 * empty_shelf_msgs__msg__EmptyShelfAlert__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_empty_shelf_msgs
empty_shelf_msgs__msg__EmptyShelfAlert__Sequence *
empty_shelf_msgs__msg__EmptyShelfAlert__Sequence__create(size_t size);

/// Destroy array of msg/EmptyShelfAlert messages.
/**
 * It calls
 * empty_shelf_msgs__msg__EmptyShelfAlert__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_empty_shelf_msgs
void
empty_shelf_msgs__msg__EmptyShelfAlert__Sequence__destroy(empty_shelf_msgs__msg__EmptyShelfAlert__Sequence * array);

/// Check for msg/EmptyShelfAlert message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_empty_shelf_msgs
bool
empty_shelf_msgs__msg__EmptyShelfAlert__Sequence__are_equal(const empty_shelf_msgs__msg__EmptyShelfAlert__Sequence * lhs, const empty_shelf_msgs__msg__EmptyShelfAlert__Sequence * rhs);

/// Copy an array of msg/EmptyShelfAlert messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_empty_shelf_msgs
bool
empty_shelf_msgs__msg__EmptyShelfAlert__Sequence__copy(
  const empty_shelf_msgs__msg__EmptyShelfAlert__Sequence * input,
  empty_shelf_msgs__msg__EmptyShelfAlert__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // EMPTY_SHELF_MSGS__MSG__DETAIL__EMPTY_SHELF_ALERT__FUNCTIONS_H_
