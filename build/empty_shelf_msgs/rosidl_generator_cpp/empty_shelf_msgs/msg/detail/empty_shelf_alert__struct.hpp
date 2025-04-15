// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from empty_shelf_msgs:msg/EmptyShelfAlert.idl
// generated code does not contain a copyright notice

#ifndef EMPTY_SHELF_MSGS__MSG__DETAIL__EMPTY_SHELF_ALERT__STRUCT_HPP_
#define EMPTY_SHELF_MSGS__MSG__DETAIL__EMPTY_SHELF_ALERT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__empty_shelf_msgs__msg__EmptyShelfAlert __attribute__((deprecated))
#else
# define DEPRECATED__empty_shelf_msgs__msg__EmptyShelfAlert __declspec(deprecated)
#endif

namespace empty_shelf_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EmptyShelfAlert_
{
  using Type = EmptyShelfAlert_<ContainerAllocator>;

  explicit EmptyShelfAlert_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->shelf_level = 0l;
      this->x = 0.0f;
      this->y = 0.0f;
      this->depth = 0.0f;
      this->confidence = 0.0f;
      this->status = "";
    }
  }

  explicit EmptyShelfAlert_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_alloc, _init),
    status(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->shelf_level = 0l;
      this->x = 0.0f;
      this->y = 0.0f;
      this->depth = 0.0f;
      this->confidence = 0.0f;
      this->status = "";
    }
  }

  // field types and members
  using _timestamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _timestamp_type timestamp;
  using _shelf_level_type =
    int32_t;
  _shelf_level_type shelf_level;
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;
  using _depth_type =
    float;
  _depth_type depth;
  using _confidence_type =
    float;
  _confidence_type confidence;
  using _status_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _status_type status;

  // setters for named parameter idiom
  Type & set__timestamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }
  Type & set__shelf_level(
    const int32_t & _arg)
  {
    this->shelf_level = _arg;
    return *this;
  }
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__depth(
    const float & _arg)
  {
    this->depth = _arg;
    return *this;
  }
  Type & set__confidence(
    const float & _arg)
  {
    this->confidence = _arg;
    return *this;
  }
  Type & set__status(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    empty_shelf_msgs::msg::EmptyShelfAlert_<ContainerAllocator> *;
  using ConstRawPtr =
    const empty_shelf_msgs::msg::EmptyShelfAlert_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<empty_shelf_msgs::msg::EmptyShelfAlert_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<empty_shelf_msgs::msg::EmptyShelfAlert_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      empty_shelf_msgs::msg::EmptyShelfAlert_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<empty_shelf_msgs::msg::EmptyShelfAlert_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      empty_shelf_msgs::msg::EmptyShelfAlert_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<empty_shelf_msgs::msg::EmptyShelfAlert_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<empty_shelf_msgs::msg::EmptyShelfAlert_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<empty_shelf_msgs::msg::EmptyShelfAlert_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__empty_shelf_msgs__msg__EmptyShelfAlert
    std::shared_ptr<empty_shelf_msgs::msg::EmptyShelfAlert_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__empty_shelf_msgs__msg__EmptyShelfAlert
    std::shared_ptr<empty_shelf_msgs::msg::EmptyShelfAlert_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EmptyShelfAlert_ & other) const
  {
    if (this->timestamp != other.timestamp) {
      return false;
    }
    if (this->shelf_level != other.shelf_level) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->depth != other.depth) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const EmptyShelfAlert_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EmptyShelfAlert_

// alias to use template instance with default allocator
using EmptyShelfAlert =
  empty_shelf_msgs::msg::EmptyShelfAlert_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace empty_shelf_msgs

#endif  // EMPTY_SHELF_MSGS__MSG__DETAIL__EMPTY_SHELF_ALERT__STRUCT_HPP_
