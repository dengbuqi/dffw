// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dffw_msgs:msg/PytorchTensorFloat32.idl
// generated code does not contain a copyright notice

#ifndef DFFW_MSGS__MSG__DETAIL__PYTORCH_TENSOR_FLOAT32__STRUCT_HPP_
#define DFFW_MSGS__MSG__DETAIL__PYTORCH_TENSOR_FLOAT32__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__dffw_msgs__msg__PytorchTensorFloat32 __attribute__((deprecated))
#else
# define DEPRECATED__dffw_msgs__msg__PytorchTensorFloat32 __declspec(deprecated)
#endif

namespace dffw_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PytorchTensorFloat32_
{
  using Type = PytorchTensorFloat32_<ContainerAllocator>;

  explicit PytorchTensorFloat32_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit PytorchTensorFloat32_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _shape_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _shape_type shape;
  using _data_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__shape(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->shape = _arg;
    return *this;
  }
  Type & set__data(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dffw_msgs::msg::PytorchTensorFloat32_<ContainerAllocator> *;
  using ConstRawPtr =
    const dffw_msgs::msg::PytorchTensorFloat32_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dffw_msgs::msg::PytorchTensorFloat32_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dffw_msgs::msg::PytorchTensorFloat32_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dffw_msgs::msg::PytorchTensorFloat32_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dffw_msgs::msg::PytorchTensorFloat32_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dffw_msgs::msg::PytorchTensorFloat32_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dffw_msgs::msg::PytorchTensorFloat32_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dffw_msgs::msg::PytorchTensorFloat32_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dffw_msgs::msg::PytorchTensorFloat32_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dffw_msgs__msg__PytorchTensorFloat32
    std::shared_ptr<dffw_msgs::msg::PytorchTensorFloat32_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dffw_msgs__msg__PytorchTensorFloat32
    std::shared_ptr<dffw_msgs::msg::PytorchTensorFloat32_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PytorchTensorFloat32_ & other) const
  {
    if (this->shape != other.shape) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const PytorchTensorFloat32_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PytorchTensorFloat32_

// alias to use template instance with default allocator
using PytorchTensorFloat32 =
  dffw_msgs::msg::PytorchTensorFloat32_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace dffw_msgs

#endif  // DFFW_MSGS__MSG__DETAIL__PYTORCH_TENSOR_FLOAT32__STRUCT_HPP_
