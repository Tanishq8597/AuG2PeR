// Generated by gencpp from file ros_decawave/Acc.msg
// DO NOT EDIT!


#ifndef ROS_DECAWAVE_MESSAGE_ACC_H
#define ROS_DECAWAVE_MESSAGE_ACC_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace ros_decawave
{
template <class ContainerAllocator>
struct Acc_
{
  typedef Acc_<ContainerAllocator> Type;

  Acc_()
    : header()
    , x(0.0)
    , y(0.0)
    , z(0.0)  {
    }
  Acc_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , x(0.0)
    , y(0.0)
    , z(0.0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef double _x_type;
  _x_type x;

   typedef double _y_type;
  _y_type y;

   typedef double _z_type;
  _z_type z;





  typedef boost::shared_ptr< ::ros_decawave::Acc_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_decawave::Acc_<ContainerAllocator> const> ConstPtr;

}; // struct Acc_

typedef ::ros_decawave::Acc_<std::allocator<void> > Acc;

typedef boost::shared_ptr< ::ros_decawave::Acc > AccPtr;
typedef boost::shared_ptr< ::ros_decawave::Acc const> AccConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_decawave::Acc_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_decawave::Acc_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace ros_decawave

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'ros_decawave': ['/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/ros_decawave/msg'], 'std_msgs': ['/usr/local/MATLAB/R2020b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg', '/usr/local/MATLAB/R2020b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::ros_decawave::Acc_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_decawave::Acc_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_decawave::Acc_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_decawave::Acc_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_decawave::Acc_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_decawave::Acc_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_decawave::Acc_<ContainerAllocator> >
{
  static const char* value()
  {
    return "5defbd163657b4f6f639ba6d5676cc01";
  }

  static const char* value(const ::ros_decawave::Acc_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x5defbd163657b4f6ULL;
  static const uint64_t static_value2 = 0xf639ba6d5676cc01ULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_decawave::Acc_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_decawave/Acc";
  }

  static const char* value(const ::ros_decawave::Acc_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_decawave::Acc_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Anchor message structure. qf is the quality of this measurement and dist_qf the quality of the estimated distance.\n"
"\n"
"Header header\n"
"\n"
"float64 x ## in m/s2\n"
"float64 y ## in m/s2\n"
"float64 z ## in m/s2\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
;
  }

  static const char* value(const ::ros_decawave::Acc_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_decawave::Acc_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.z);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Acc_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_decawave::Acc_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_decawave::Acc_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "x: ";
    Printer<double>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<double>::stream(s, indent + "  ", v.y);
    s << indent << "z: ";
    Printer<double>::stream(s, indent + "  ", v.z);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_DECAWAVE_MESSAGE_ACC_H
