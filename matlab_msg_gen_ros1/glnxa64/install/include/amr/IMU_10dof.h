// Generated by gencpp from file amr/IMU_10dof.msg
// DO NOT EDIT!


#ifndef AMR_MESSAGE_IMU_10DOF_H
#define AMR_MESSAGE_IMU_10DOF_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace amr
{
template <class ContainerAllocator>
struct IMU_10dof_
{
  typedef IMU_10dof_<ContainerAllocator> Type;

  IMU_10dof_()
    : header()
    , gyro_val()
    , accel_val()
    , mag_val()
    , temp(0.0)  {
      gyro_val.assign(0.0);

      accel_val.assign(0.0);

      mag_val.assign(0.0);
  }
  IMU_10dof_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , gyro_val()
    , accel_val()
    , mag_val()
    , temp(0.0)  {
  (void)_alloc;
      gyro_val.assign(0.0);

      accel_val.assign(0.0);

      mag_val.assign(0.0);
  }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef boost::array<double, 3>  _gyro_val_type;
  _gyro_val_type gyro_val;

   typedef boost::array<double, 3>  _accel_val_type;
  _accel_val_type accel_val;

   typedef boost::array<double, 3>  _mag_val_type;
  _mag_val_type mag_val;

   typedef double _temp_type;
  _temp_type temp;





  typedef boost::shared_ptr< ::amr::IMU_10dof_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::amr::IMU_10dof_<ContainerAllocator> const> ConstPtr;

}; // struct IMU_10dof_

typedef ::amr::IMU_10dof_<std::allocator<void> > IMU_10dof;

typedef boost::shared_ptr< ::amr::IMU_10dof > IMU_10dofPtr;
typedef boost::shared_ptr< ::amr::IMU_10dof const> IMU_10dofConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::amr::IMU_10dof_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::amr::IMU_10dof_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace amr

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'amr': ['/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/amr/msg'], 'std_msgs': ['/usr/local/MATLAB/R2020b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg', '/usr/local/MATLAB/R2020b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::amr::IMU_10dof_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::amr::IMU_10dof_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::amr::IMU_10dof_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::amr::IMU_10dof_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::amr::IMU_10dof_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::amr::IMU_10dof_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::amr::IMU_10dof_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9b8d7eca084f26c332bc26f08693149d";
  }

  static const char* value(const ::amr::IMU_10dof_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9b8d7eca084f26c3ULL;
  static const uint64_t static_value2 = 0x32bc26f08693149dULL;
};

template<class ContainerAllocator>
struct DataType< ::amr::IMU_10dof_<ContainerAllocator> >
{
  static const char* value()
  {
    return "amr/IMU_10dof";
  }

  static const char* value(const ::amr::IMU_10dof_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::amr::IMU_10dof_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n"
"\n"
"float64[3] gyro_val\n"
"\n"
"float64[3] accel_val\n"
"\n"
"float64[3] mag_val\n"
"\n"
"float64 temp\n"
"\n"
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

  static const char* value(const ::amr::IMU_10dof_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::amr::IMU_10dof_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.gyro_val);
      stream.next(m.accel_val);
      stream.next(m.mag_val);
      stream.next(m.temp);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct IMU_10dof_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::amr::IMU_10dof_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::amr::IMU_10dof_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "gyro_val[]" << std::endl;
    for (size_t i = 0; i < v.gyro_val.size(); ++i)
    {
      s << indent << "  gyro_val[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.gyro_val[i]);
    }
    s << indent << "accel_val[]" << std::endl;
    for (size_t i = 0; i < v.accel_val.size(); ++i)
    {
      s << indent << "  accel_val[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.accel_val[i]);
    }
    s << indent << "mag_val[]" << std::endl;
    for (size_t i = 0; i < v.mag_val.size(); ++i)
    {
      s << indent << "  mag_val[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.mag_val[i]);
    }
    s << indent << "temp: ";
    Printer<double>::stream(s, indent + "  ", v.temp);
  }
};

} // namespace message_operations
} // namespace ros

#endif // AMR_MESSAGE_IMU_10DOF_H
