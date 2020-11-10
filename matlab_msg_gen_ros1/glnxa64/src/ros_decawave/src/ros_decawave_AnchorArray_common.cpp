// Copyright 2019-2020 The MathWorks, Inc.
// Common copy functions for ros_decawave/AnchorArray
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
#include "ros_decawave/AnchorArray.h"
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
namespace ros_decawave {
namespace matlabhelper {
namespace AnchorArray {
  void copy_from_arr_std_msgs_Header(std_msgs::Header& val, const matlab::data::StructArray& arr);
  MDArray_T get_arr_std_msgs_Header(MDFactory_T& factory, const ros_decawave::AnchorArray::_header_type& val);
  void copy_from_arr_ros_Time(ros::Time& val, const matlab::data::StructArray& arr);
  MDArray_T get_arr_ros_Time(MDFactory_T& factory, const std_msgs::Header::_stamp_type& val);
  void copy_from_arr_ros_decawave_Anchor_var_arr(ros_decawave::Anchor& val, const matlab::data::Struct& arr);
  MDArray_T get_arr_ros_decawave_Anchor_var_arr(MDFactory_T& factory, const ros_decawave::AnchorArray::_anchors_type& val);
  //----------------------------------------------------------------------------
  void copy_from_arr_std_msgs_Header(std_msgs::Header& val, const matlab::data::StructArray& arr) {
    // _std_msgs_Header.seq
    try {
        const matlab::data::TypedArray<uint32_t> _headerseq_arr = arr[0]["seq"];
        val.seq = _headerseq_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'seq' is missing.");
    } catch (matlab::data::TypeMismatchException&) {
        throw std::invalid_argument("Field 'seq' is wrong type; expected a uint32.");
    }
    // _std_msgs_Header.stamp
    try {
        const matlab::data::StructArray _headerstamp_arr = arr[0]["stamp"];
        copy_from_arr_ros_Time(val.stamp,_headerstamp_arr);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'stamp' is missing.");
    } catch (matlab::data::TypeMismatchException&) {
        throw std::invalid_argument("Field 'stamp' is wrong type; expected a struct.");
    }
    // _std_msgs_Header.frame_id
    try {
        const matlab::data::CharArray _headerframe_id_arr = arr[0]["frame_id"];
        val.frame_id = _headerframe_id_arr.toAscii();
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'frame_id' is missing.");
    } catch (matlab::data::TypeMismatchException&) {
        throw std::invalid_argument("Field 'frame_id' is wrong type; expected a string.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T get_arr_std_msgs_Header(MDFactory_T& factory, const ros_decawave::AnchorArray::_header_type& val) {
    auto _headeroutArray = factory.createStructArray({1,1},{"seq","stamp","frame_id"});
    // _std_msgs_Header.seq
    _headeroutArray[0]["seq"] = factory.createScalar(val.seq);
    // _std_msgs_Header.stamp
    _headeroutArray[0]["stamp"] = get_arr_ros_Time(factory, val.stamp);
    // _std_msgs_Header.frame_id
    _headeroutArray[0]["frame_id"] = factory.createCharArray(val.frame_id);
    return std::move(_headeroutArray);
  }
  //----------------------------------------------------------------------------
  void copy_from_arr_ros_Time(ros::Time& val, const matlab::data::StructArray& arr) {
    // _ros_Time.sec
    try {
        const matlab::data::TypedArray<uint32_t> _header_stampsec_arr = arr[0]["sec"];
        val.sec = _header_stampsec_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'sec' is missing.");
    } catch (matlab::data::TypeMismatchException&) {
        throw std::invalid_argument("Field 'sec' is wrong type; expected a uint32.");
    }
    // _ros_Time.nsec
    try {
        const matlab::data::TypedArray<uint32_t> _header_stampnsec_arr = arr[0]["nsec"];
        val.nsec = _header_stampnsec_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'nsec' is missing.");
    } catch (matlab::data::TypeMismatchException&) {
        throw std::invalid_argument("Field 'nsec' is wrong type; expected a uint32.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T get_arr_ros_Time(MDFactory_T& factory, const std_msgs::Header::_stamp_type& val) {
    auto _header_stampoutArray = factory.createStructArray({1,1},{"sec","nsec"});
    // _ros_Time.sec
    _header_stampoutArray[0]["sec"] = factory.createScalar(val.sec);
    // _ros_Time.nsec
    _header_stampoutArray[0]["nsec"] = factory.createScalar(val.nsec);
    return std::move(_header_stampoutArray);
  }
  //----------------------------------------------------------------------------
  void copy_from_arr_ros_decawave_Anchor_var_arr(ros_decawave::Anchor& val, const matlab::data::Struct& arr) {
    // _ros_decawave_Anchor_var_arr.header
    try {
        const matlab::data::StructArray _anchorsheader_arr = arr["header"];
        copy_from_arr_std_msgs_Header(val.header,_anchorsheader_arr);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'header' is missing.");
    } catch (matlab::data::TypeMismatchException&) {
        throw std::invalid_argument("Field 'header' is wrong type; expected a struct.");
    }
    // _ros_decawave_Anchor_var_arr.x
    try {
        const matlab::data::TypedArray<double> _anchorsx_arr = arr["x"];
        val.x = _anchorsx_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'x' is missing.");
    } catch (matlab::data::TypeMismatchException&) {
        throw std::invalid_argument("Field 'x' is wrong type; expected a double.");
    }
    // _ros_decawave_Anchor_var_arr.y
    try {
        const matlab::data::TypedArray<double> _anchorsy_arr = arr["y"];
        val.y = _anchorsy_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'y' is missing.");
    } catch (matlab::data::TypeMismatchException&) {
        throw std::invalid_argument("Field 'y' is wrong type; expected a double.");
    }
    // _ros_decawave_Anchor_var_arr.z
    try {
        const matlab::data::TypedArray<double> _anchorsz_arr = arr["z"];
        val.z = _anchorsz_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'z' is missing.");
    } catch (matlab::data::TypeMismatchException&) {
        throw std::invalid_argument("Field 'z' is wrong type; expected a double.");
    }
    // _ros_decawave_Anchor_var_arr.qf
    try {
        const matlab::data::TypedArray<double> _anchorsqf_arr = arr["qf"];
        val.qf = _anchorsqf_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'qf' is missing.");
    } catch (matlab::data::TypeMismatchException&) {
        throw std::invalid_argument("Field 'qf' is wrong type; expected a double.");
    }
    // _ros_decawave_Anchor_var_arr.distance
    try {
        const matlab::data::TypedArray<double> _anchorsdistance_arr = arr["distance"];
        val.distance = _anchorsdistance_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'distance' is missing.");
    } catch (matlab::data::TypeMismatchException&) {
        throw std::invalid_argument("Field 'distance' is wrong type; expected a double.");
    }
    // _ros_decawave_Anchor_var_arr.dist_qf
    try {
        const matlab::data::TypedArray<double> _anchorsdist_qf_arr = arr["dist_qf"];
        val.dist_qf = _anchorsdist_qf_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'dist_qf' is missing.");
    } catch (matlab::data::TypeMismatchException&) {
        throw std::invalid_argument("Field 'dist_qf' is wrong type; expected a double.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T get_arr_ros_decawave_Anchor_var_arr(MDFactory_T& factory, const ros_decawave::AnchorArray::_anchors_type& val) {
    auto _anchorsoutArray = factory.createStructArray({1,val.size()},{"header","x","y","z","qf","distance","dist_qf"});
    for (size_t idx = 0; idx < val.size(); ++idx){
    // _ros_decawave_Anchor_var_arr.header
    _anchorsoutArray[idx]["header"] = get_arr_std_msgs_Header(factory, val[idx].header);
    // _ros_decawave_Anchor_var_arr.x
    	_anchorsoutArray[idx]["x"] = factory.createScalar(val[idx].x);
    // _ros_decawave_Anchor_var_arr.y
    	_anchorsoutArray[idx]["y"] = factory.createScalar(val[idx].y);
    // _ros_decawave_Anchor_var_arr.z
    	_anchorsoutArray[idx]["z"] = factory.createScalar(val[idx].z);
    // _ros_decawave_Anchor_var_arr.qf
    	_anchorsoutArray[idx]["qf"] = factory.createScalar(val[idx].qf);
    // _ros_decawave_Anchor_var_arr.distance
    	_anchorsoutArray[idx]["distance"] = factory.createScalar(val[idx].distance);
    // _ros_decawave_Anchor_var_arr.dist_qf
    	_anchorsoutArray[idx]["dist_qf"] = factory.createScalar(val[idx].dist_qf);
    }
    return std::move(_anchorsoutArray);
  }
  //----------------------------------------------------------------------------
  ROS_DECAWAVE_EXPORT void copy_from_arr(boost::shared_ptr<ros_decawave::AnchorArray>& msg, const matlab::data::StructArray arr) {
    try {
        //header
        const matlab::data::StructArray header_arr = arr[0]["header"];
        copy_from_arr_std_msgs_Header(msg->header,header_arr);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'header' is missing.");
    } catch (matlab::data::TypeMismatchException&) {
        throw std::invalid_argument("Field 'header' is wrong type; expected a struct.");
    }
    try {
        //anchors
        const matlab::data::StructArray anchors_arr = arr[0]["anchors"];
        for (auto _anchorsarr : anchors_arr) {
        	ros_decawave::Anchor _val;
        	copy_from_arr_ros_decawave_Anchor_var_arr(_val,_anchorsarr);
        	msg->anchors.push_back(_val);
        }
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'anchors' is missing.");
    } catch (matlab::data::TypeMismatchException&) {
        throw std::invalid_argument("Field 'anchors' is wrong type; expected a struct.");
    }
  }
  //----------------------------------------------------------------------------
  ROS_DECAWAVE_EXPORT MDArray_T get_arr(MDFactory_T& factory, const boost::shared_ptr<const ros_decawave::AnchorArray>& msg) {
    auto outArray = factory.createStructArray({1,1},{"header","anchors"});
    // header
    outArray[0]["header"] = get_arr_std_msgs_Header(factory, msg->header);
    // anchors
    outArray[0]["anchors"] = get_arr_ros_decawave_Anchor_var_arr(factory, msg->anchors);
    return std::move(outArray);
  }
} //namespace AnchorArray
} //namespace matlabhelper
} //namespace ros_decawave
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1