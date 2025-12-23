#ifndef ROVER_SW_PWRTRAIN__VISIBILITY_CONTROL_H_
#define ROVER_SW_PWRTRAIN__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROVER_SW_PWRTRAIN_EXPORT __attribute__ ((dllexport))
    #define ROVER_SW_PWRTRAIN_IMPORT __attribute__ ((dllimport))
  #else
    #define ROVER_SW_PWRTRAIN_EXPORT __declspec(dllexport)
    #define ROVER_SW_PWRTRAIN_IMPORT __declspec(dllimport)
  #endif
  #ifdef ROVER_SW_PWRTRAIN_BUILDING_LIBRARY
    #define ROVER_SW_PWRTRAIN_PUBLIC ROVER_SW_PWRTRAIN_EXPORT
  #else
    #define ROVER_SW_PWRTRAIN_PUBLIC ROVER_SW_PWRTRAIN_IMPORT
  #endif
  #define ROVER_SW_PWRTRAIN_PUBLIC_TYPE ROVER_SW_PWRTRAIN_PUBLIC
  #define ROVER_SW_PWRTRAIN_LOCAL
#else
  #define ROVER_SW_PWRTRAIN_EXPORT __attribute__ ((visibility("default")))
  #define ROVER_SW_PWRTRAIN_IMPORT
  #if __GNUC__ >= 4
    #define ROVER_SW_PWRTRAIN_PUBLIC __attribute__ ((visibility("default")))
    #define ROVER_SW_PWRTRAIN_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define ROVER_SW_PWRTRAIN_PUBLIC
    #define ROVER_SW_PWRTRAIN_LOCAL
  #endif
  #define ROVER_SW_PWRTRAIN_PUBLIC_TYPE
#endif
#endif  // ROVER_SW_PWRTRAIN__VISIBILITY_CONTROL_H_
// Generated 30-Nov-2025 12:04:21
 