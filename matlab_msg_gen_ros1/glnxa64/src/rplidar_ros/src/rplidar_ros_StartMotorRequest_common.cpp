// Copyright 2019-2020 The MathWorks, Inc.
// Common copy functions for rplidar_ros/StartMotorRequest
#include "boost/date_time.hpp"
#include "boost/shared_array.hpp"
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4244)
#pragma warning(disable : 4265)
#pragma warning(disable : 4458)
#pragma warning(disable : 4100)
#pragma warning(disable : 4127)
#pragma warning(disable : 4267)
#else
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wredundant-decls"
#pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wshadow"
#endif //_MSC_VER
#include "ros/ros.h"
#include "rplidar_ros/StartMotorRequest.h"
#include "visibility_control.h"
#ifndef FOUNDATION_MATLABDATA_API
#include "MDArray.hpp"
#include "StructArray.hpp"
#include "TypedArrayRef.hpp"
#include "Struct.hpp"
#include "ArrayFactory.hpp"
#include "StructRef.hpp"
#include "Reference.hpp"
#endif
#ifndef FOUNDATION_MATLABDATA_API
typedef matlab::data::Array MDArray_T;
typedef matlab::data::ArrayFactory MDFactory_T;
#else
typedef foundation::matlabdata::Array MDArray_T;
typedef foundation::matlabdata::standalone::ClientArrayFactory MDFactory_T;
#endif
namespace rplidar_ros {
namespace matlabhelper {
namespace StartMotorRequest {
  void copy_from_arr_std_msgs_UInt16(std_msgs::UInt16& val, const matlab::data::StructArray& arr);
  MDArray_T get_arr_std_msgs_UInt16(MDFactory_T& factory, const rplidar_ros::StartMotorRequest::_pwm_type& val);
  //----------------------------------------------------------------------------
  void copy_from_arr_std_msgs_UInt16(std_msgs::UInt16& val, const matlab::data::StructArray& arr) {
    // _std_msgs_UInt16.data
    try {
        const matlab::data::TypedArray<uint16_t> _pwmdata_arr = arr[0]["data"];
        val.data = _pwmdata_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'data' is missing.");
    } catch (matlab::data::TypeMismatchException&) {
        throw std::invalid_argument("Field 'data' is wrong type; expected a uint16.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T get_arr_std_msgs_UInt16(MDFactory_T& factory, const rplidar_ros::StartMotorRequest::_pwm_type& val) {
    auto _pwmoutArray = factory.createStructArray({1,1},{"data"});
    // _std_msgs_UInt16.data
    _pwmoutArray[0]["data"] = factory.createScalar(val.data);
    return std::move(_pwmoutArray);
  }
  //----------------------------------------------------------------------------
  RPLIDAR_ROS_EXPORT void copy_from_arr(boost::shared_ptr<rplidar_ros::StartMotorRequest>& msg, const matlab::data::StructArray arr) {
    try {
        //pwm
        const matlab::data::StructArray pwm_arr = arr[0]["pwm"];
        copy_from_arr_std_msgs_UInt16(msg->pwm,pwm_arr);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'pwm' is missing.");
    } catch (matlab::data::TypeMismatchException&) {
        throw std::invalid_argument("Field 'pwm' is wrong type; expected a struct.");
    }
  }
  //----------------------------------------------------------------------------
  RPLIDAR_ROS_EXPORT MDArray_T get_arr(MDFactory_T& factory, const boost::shared_ptr<const rplidar_ros::StartMotorRequest>& msg) {
    auto outArray = factory.createStructArray({1,1},{"pwm"});
    // pwm
    outArray[0]["pwm"] = get_arr_std_msgs_UInt16(factory, msg->pwm);
    return std::move(outArray);
  }
} //namespace StartMotorRequest
} //namespace matlabhelper
} //namespace rplidar_ros
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1