#ifndef AMR__VISIBILITY_CONTROL_H_
#define AMR__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define AMR_EXPORT __attribute__ ((dllexport))
    #define AMR_IMPORT __attribute__ ((dllimport))
  #else
    #define AMR_EXPORT __declspec(dllexport)
    #define AMR_IMPORT __declspec(dllimport)
  #endif
  #ifdef AMR_BUILDING_LIBRARY
    #define AMR_PUBLIC AMR_EXPORT
  #else
    #define AMR_PUBLIC AMR_IMPORT
  #endif
  #define AMR_PUBLIC_TYPE AMR_PUBLIC
  #define AMR_LOCAL
#else
  #define AMR_EXPORT __attribute__ ((visibility("default")))
  #define AMR_IMPORT
  #if __GNUC__ >= 4
    #define AMR_PUBLIC __attribute__ ((visibility("default")))
    #define AMR_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define AMR_PUBLIC
    #define AMR_LOCAL
  #endif
  #define AMR_PUBLIC_TYPE
#endif
#endif  // AMR__VISIBILITY_CONTROL_H_
// Generated 10-Nov-2020 22:10:33
// Copyright 2019-2020 The MathWorks, Inc.
