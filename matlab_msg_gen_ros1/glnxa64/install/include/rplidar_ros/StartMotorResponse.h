// Generated by gencpp from file rplidar_ros/StartMotorResponse.msg
// DO NOT EDIT!


#ifndef RPLIDAR_ROS_MESSAGE_STARTMOTORRESPONSE_H
#define RPLIDAR_ROS_MESSAGE_STARTMOTORRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace rplidar_ros
{
template <class ContainerAllocator>
struct StartMotorResponse_
{
  typedef StartMotorResponse_<ContainerAllocator> Type;

  StartMotorResponse_()
    {
    }
  StartMotorResponse_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }







  typedef boost::shared_ptr< ::rplidar_ros::StartMotorResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rplidar_ros::StartMotorResponse_<ContainerAllocator> const> ConstPtr;

}; // struct StartMotorResponse_

typedef ::rplidar_ros::StartMotorResponse_<std::allocator<void> > StartMotorResponse;

typedef boost::shared_ptr< ::rplidar_ros::StartMotorResponse > StartMotorResponsePtr;
typedef boost::shared_ptr< ::rplidar_ros::StartMotorResponse const> StartMotorResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rplidar_ros::StartMotorResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rplidar_ros::StartMotorResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace rplidar_ros

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/usr/local/MATLAB/R2020b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg', '/usr/local/MATLAB/R2020b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::rplidar_ros::StartMotorResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rplidar_ros::StartMotorResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rplidar_ros::StartMotorResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rplidar_ros::StartMotorResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rplidar_ros::StartMotorResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rplidar_ros::StartMotorResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rplidar_ros::StartMotorResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::rplidar_ros::StartMotorResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::rplidar_ros::StartMotorResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rplidar_ros/StartMotorResponse";
  }

  static const char* value(const ::rplidar_ros::StartMotorResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rplidar_ros::StartMotorResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n"
;
  }

  static const char* value(const ::rplidar_ros::StartMotorResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rplidar_ros::StartMotorResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct StartMotorResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rplidar_ros::StartMotorResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::rplidar_ros::StartMotorResponse_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // RPLIDAR_ROS_MESSAGE_STARTMOTORRESPONSE_H