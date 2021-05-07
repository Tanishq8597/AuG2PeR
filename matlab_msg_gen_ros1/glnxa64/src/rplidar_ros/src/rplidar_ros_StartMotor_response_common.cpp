// Copyright 2020 The MathWorks, Inc.
// Common copy functions of server for rplidar_ros/StartMotorResponse
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
#include "rplidar_ros/StartMotor.h"
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
namespace StartMotor_Response {
  //----------------------------------------------------------------------------
  RPLIDAR_ROS_EXPORT void copy_from_arr(rplidar_ros::StartMotor::Response& msg, const matlab::data::StructArray arr) {
  }
  //----------------------------------------------------------------------------
  RPLIDAR_ROS_EXPORT MDArray_T get_arr(MDFactory_T& factory, const rplidar_ros::StartMotor::Response& msg) {
    auto outArray = factory.createStructArray({1,1},{});
    return std::move(outArray);
  }
} //namespace StartMotor_Response
} //namespace matlabhelper
} //namespace rplidar_ros
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1