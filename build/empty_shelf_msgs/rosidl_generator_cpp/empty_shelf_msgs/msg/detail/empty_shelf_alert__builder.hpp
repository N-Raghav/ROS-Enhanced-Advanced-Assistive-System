// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from empty_shelf_msgs:msg/EmptyShelfAlert.idl
// generated code does not contain a copyright notice

#ifndef EMPTY_SHELF_MSGS__MSG__DETAIL__EMPTY_SHELF_ALERT__BUILDER_HPP_
#define EMPTY_SHELF_MSGS__MSG__DETAIL__EMPTY_SHELF_ALERT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "empty_shelf_msgs/msg/detail/empty_shelf_alert__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace empty_shelf_msgs
{

namespace msg
{

namespace builder
{

class Init_EmptyShelfAlert_status
{
public:
  explicit Init_EmptyShelfAlert_status(::empty_shelf_msgs::msg::EmptyShelfAlert & msg)
  : msg_(msg)
  {}
  ::empty_shelf_msgs::msg::EmptyShelfAlert status(::empty_shelf_msgs::msg::EmptyShelfAlert::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::empty_shelf_msgs::msg::EmptyShelfAlert msg_;
};

class Init_EmptyShelfAlert_confidence
{
public:
  explicit Init_EmptyShelfAlert_confidence(::empty_shelf_msgs::msg::EmptyShelfAlert & msg)
  : msg_(msg)
  {}
  Init_EmptyShelfAlert_status confidence(::empty_shelf_msgs::msg::EmptyShelfAlert::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_EmptyShelfAlert_status(msg_);
  }

private:
  ::empty_shelf_msgs::msg::EmptyShelfAlert msg_;
};

class Init_EmptyShelfAlert_depth
{
public:
  explicit Init_EmptyShelfAlert_depth(::empty_shelf_msgs::msg::EmptyShelfAlert & msg)
  : msg_(msg)
  {}
  Init_EmptyShelfAlert_confidence depth(::empty_shelf_msgs::msg::EmptyShelfAlert::_depth_type arg)
  {
    msg_.depth = std::move(arg);
    return Init_EmptyShelfAlert_confidence(msg_);
  }

private:
  ::empty_shelf_msgs::msg::EmptyShelfAlert msg_;
};

class Init_EmptyShelfAlert_y
{
public:
  explicit Init_EmptyShelfAlert_y(::empty_shelf_msgs::msg::EmptyShelfAlert & msg)
  : msg_(msg)
  {}
  Init_EmptyShelfAlert_depth y(::empty_shelf_msgs::msg::EmptyShelfAlert::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_EmptyShelfAlert_depth(msg_);
  }

private:
  ::empty_shelf_msgs::msg::EmptyShelfAlert msg_;
};

class Init_EmptyShelfAlert_x
{
public:
  explicit Init_EmptyShelfAlert_x(::empty_shelf_msgs::msg::EmptyShelfAlert & msg)
  : msg_(msg)
  {}
  Init_EmptyShelfAlert_y x(::empty_shelf_msgs::msg::EmptyShelfAlert::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_EmptyShelfAlert_y(msg_);
  }

private:
  ::empty_shelf_msgs::msg::EmptyShelfAlert msg_;
};

class Init_EmptyShelfAlert_shelf_level
{
public:
  explicit Init_EmptyShelfAlert_shelf_level(::empty_shelf_msgs::msg::EmptyShelfAlert & msg)
  : msg_(msg)
  {}
  Init_EmptyShelfAlert_x shelf_level(::empty_shelf_msgs::msg::EmptyShelfAlert::_shelf_level_type arg)
  {
    msg_.shelf_level = std::move(arg);
    return Init_EmptyShelfAlert_x(msg_);
  }

private:
  ::empty_shelf_msgs::msg::EmptyShelfAlert msg_;
};

class Init_EmptyShelfAlert_timestamp
{
public:
  Init_EmptyShelfAlert_timestamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EmptyShelfAlert_shelf_level timestamp(::empty_shelf_msgs::msg::EmptyShelfAlert::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_EmptyShelfAlert_shelf_level(msg_);
  }

private:
  ::empty_shelf_msgs::msg::EmptyShelfAlert msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::empty_shelf_msgs::msg::EmptyShelfAlert>()
{
  return empty_shelf_msgs::msg::builder::Init_EmptyShelfAlert_timestamp();
}

}  // namespace empty_shelf_msgs

#endif  // EMPTY_SHELF_MSGS__MSG__DETAIL__EMPTY_SHELF_ALERT__BUILDER_HPP_
