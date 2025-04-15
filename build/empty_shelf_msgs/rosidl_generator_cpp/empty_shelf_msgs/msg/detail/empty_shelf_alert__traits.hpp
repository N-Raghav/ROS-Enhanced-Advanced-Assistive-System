// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from empty_shelf_msgs:msg/EmptyShelfAlert.idl
// generated code does not contain a copyright notice

#ifndef EMPTY_SHELF_MSGS__MSG__DETAIL__EMPTY_SHELF_ALERT__TRAITS_HPP_
#define EMPTY_SHELF_MSGS__MSG__DETAIL__EMPTY_SHELF_ALERT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "empty_shelf_msgs/msg/detail/empty_shelf_alert__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace empty_shelf_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const EmptyShelfAlert & msg,
  std::ostream & out)
{
  out << "{";
  // member: timestamp
  {
    out << "timestamp: ";
    to_flow_style_yaml(msg.timestamp, out);
    out << ", ";
  }

  // member: shelf_level
  {
    out << "shelf_level: ";
    rosidl_generator_traits::value_to_yaml(msg.shelf_level, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: depth
  {
    out << "depth: ";
    rosidl_generator_traits::value_to_yaml(msg.depth, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << ", ";
  }

  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EmptyShelfAlert & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: timestamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timestamp:\n";
    to_block_style_yaml(msg.timestamp, out, indentation + 2);
  }

  // member: shelf_level
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "shelf_level: ";
    rosidl_generator_traits::value_to_yaml(msg.shelf_level, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: depth
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "depth: ";
    rosidl_generator_traits::value_to_yaml(msg.depth, out);
    out << "\n";
  }

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }

  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EmptyShelfAlert & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace empty_shelf_msgs

namespace rosidl_generator_traits
{

[[deprecated("use empty_shelf_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const empty_shelf_msgs::msg::EmptyShelfAlert & msg,
  std::ostream & out, size_t indentation = 0)
{
  empty_shelf_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use empty_shelf_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const empty_shelf_msgs::msg::EmptyShelfAlert & msg)
{
  return empty_shelf_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<empty_shelf_msgs::msg::EmptyShelfAlert>()
{
  return "empty_shelf_msgs::msg::EmptyShelfAlert";
}

template<>
inline const char * name<empty_shelf_msgs::msg::EmptyShelfAlert>()
{
  return "empty_shelf_msgs/msg/EmptyShelfAlert";
}

template<>
struct has_fixed_size<empty_shelf_msgs::msg::EmptyShelfAlert>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<empty_shelf_msgs::msg::EmptyShelfAlert>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<empty_shelf_msgs::msg::EmptyShelfAlert>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // EMPTY_SHELF_MSGS__MSG__DETAIL__EMPTY_SHELF_ALERT__TRAITS_HPP_
