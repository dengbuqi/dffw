// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dffw_msgs:msg/InferanceForward.idl
// generated code does not contain a copyright notice

#ifndef DFFW_MSGS__MSG__DETAIL__INFERANCE_FORWARD__STRUCT_HPP_
#define DFFW_MSGS__MSG__DETAIL__INFERANCE_FORWARD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__dffw_msgs__msg__InferanceForward __attribute__((deprecated))
#else
# define DEPRECATED__dffw_msgs__msg__InferanceForward __declspec(deprecated)
#endif

namespace dffw_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct InferanceForward_
{
  using Type = InferanceForward_<ContainerAllocator>;

  explicit InferanceForward_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit InferanceForward_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _h_shape_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _h_shape_type h_shape;
  using _h_data_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _h_data_type h_data;
  using _goodness_shape_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _goodness_shape_type goodness_shape;
  using _goodness_data_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _goodness_data_type goodness_data;

  // setters for named parameter idiom
  Type & set__h_shape(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->h_shape = _arg;
    return *this;
  }
  Type & set__h_data(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->h_data = _arg;
    return *this;
  }
  Type & set__goodness_shape(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->goodness_shape = _arg;
    return *this;
  }
  Type & set__goodness_data(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->goodness_data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dffw_msgs::msg::InferanceForward_<ContainerAllocator> *;
  using ConstRawPtr =
    const dffw_msgs::msg::InferanceForward_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dffw_msgs::msg::InferanceForward_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dffw_msgs::msg::InferanceForward_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dffw_msgs::msg::InferanceForward_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dffw_msgs::msg::InferanceForward_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dffw_msgs::msg::InferanceForward_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dffw_msgs::msg::InferanceForward_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dffw_msgs::msg::InferanceForward_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dffw_msgs::msg::InferanceForward_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dffw_msgs__msg__InferanceForward
    std::shared_ptr<dffw_msgs::msg::InferanceForward_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dffw_msgs__msg__InferanceForward
    std::shared_ptr<dffw_msgs::msg::InferanceForward_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const InferanceForward_ & other) const
  {
    if (this->h_shape != other.h_shape) {
      return false;
    }
    if (this->h_data != other.h_data) {
      return false;
    }
    if (this->goodness_shape != other.goodness_shape) {
      return false;
    }
    if (this->goodness_data != other.goodness_data) {
      return false;
    }
    return true;
  }
  bool operator!=(const InferanceForward_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct InferanceForward_

// alias to use template instance with default allocator
using InferanceForward =
  dffw_msgs::msg::InferanceForward_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace dffw_msgs

#endif  // DFFW_MSGS__MSG__DETAIL__INFERANCE_FORWARD__STRUCT_HPP_
