#ifndef ROS_DECAWAVE__VISIBILITY_CONTROL_H_
#define ROS_DECAWAVE__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROS_DECAWAVE_EXPORT __attribute__ ((dllexport))
    #define ROS_DECAWAVE_IMPORT __attribute__ ((dllimport))
  #else
    #define ROS_DECAWAVE_EXPORT __declspec(dllexport)
    #define ROS_DECAWAVE_IMPORT __declspec(dllimport)
  #endif
  #ifdef ROS_DECAWAVE_BUILDING_LIBRARY
    #define ROS_DECAWAVE_PUBLIC ROS_DECAWAVE_EXPORT
  #else
    #define ROS_DECAWAVE_PUBLIC ROS_DECAWAVE_IMPORT
  #endif
  #define ROS_DECAWAVE_PUBLIC_TYPE ROS_DECAWAVE_PUBLIC
  #define ROS_DECAWAVE_LOCAL
#else
  #define ROS_DECAWAVE_EXPORT __attribute__ ((visibility("default")))
  #define ROS_DECAWAVE_IMPORT
  #if __GNUC__ >= 4
    #define ROS_DECAWAVE_PUBLIC __attribute__ ((visibility("default")))
    #define ROS_DECAWAVE_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define ROS_DECAWAVE_PUBLIC
    #define ROS_DECAWAVE_LOCAL
  #endif
  #define ROS_DECAWAVE_PUBLIC_TYPE
#endif
#endif  // ROS_DECAWAVE__VISIBILITY_CONTROL_H_
// Generated 10-Nov-2020 22:10:35
// Copyright 2019-2020 The MathWorks, Inc.
