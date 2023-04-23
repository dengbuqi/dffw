// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dffw_msgs:msg/TrainForward.idl
// generated code does not contain a copyright notice

#ifndef DFFW_MSGS__MSG__DETAIL__TRAIN_FORWARD__STRUCT_HPP_
#define DFFW_MSGS__MSG__DETAIL__TRAIN_FORWARD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__dffw_msgs__msg__TrainForward __attribute__((deprecated))
#else
# define DEPRECATED__dffw_msgs__msg__TrainForward __declspec(deprecated)
#endif

namespace dffw_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TrainForward_
{
  using Type = TrainForward_<ContainerAllocator>;

  explicit TrainForward_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit TrainForward_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _h_pos_shape_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _h_pos_shape_type h_pos_shape;
  using _h_pos_data_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _h_pos_data_type h_pos_data;
  using _h_neg_shape_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _h_neg_shape_type h_neg_shape;
  using _h_neg_data_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _h_neg_data_type h_neg_data;

  // setters for named parameter idiom
  Type & set__h_pos_shape(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->h_pos_shape = _arg;
    return *this;
  }
  Type & set__h_pos_data(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->h_pos_data = _arg;
    return *this;
  }
  Type & set__h_neg_shape(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->h_neg_shape = _arg;
    return *this;
  }
  Type & set__h_neg_data(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->h_neg_data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dffw_msgs::msg::TrainForward_<ContainerAllocator> *;
  using ConstRawPtr =
    const dffw_msgs::msg::TrainForward_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dffw_msgs::msg::TrainForward_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dffw_msgs::msg::TrainForward_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dffw_msgs::msg::TrainForward_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dffw_msgs::msg::TrainForward_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dffw_msgs::msg::TrainForward_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dffw_msgs::msg::TrainForward_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dffw_msgs::msg::TrainForward_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dffw_msgs::msg::TrainForward_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dffw_msgs__msg__TrainForward
    std::shared_ptr<dffw_msgs::msg::TrainForward_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dffw_msgs__msg__TrainForward
    std::shared_ptr<dffw_msgs::msg::TrainForward_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrainForward_ & other) const
  {
    if (this->h_pos_shape != other.h_pos_shape) {
      return false;
    }
    if (this->h_pos_data != other.h_pos_data) {
      return false;
    }
    if (this->h_neg_shape != other.h_neg_shape) {
      return false;
    }
    if (this->h_neg_data != other.h_neg_data) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrainForward_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrainForward_

// alias to use template instance with default allocator
using TrainForward =
  dffw_msgs::msg::TrainForward_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace dffw_msgs

#endif  // DFFW_MSGS__MSG__DETAIL__TRAIN_FORWARD__STRUCT_HPP_
