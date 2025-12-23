/*
 * ros_test_types.h
 *
 * Home License - for personal use only.  Not for government, academic,
 * research, commercial, or other organizational use.
 *
 * Code generation for model "ros_test".
 *
 * Model version              : 1.23
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C++ source code generated on : Thu Nov 13 22:59:59 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Apple->ARM64
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef ros_test_types_h_
#define ros_test_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_std_msgs_Int32_
#define DEFINED_TYPEDEF_FOR_SL_Bus_std_msgs_Int32_

struct SL_Bus_std_msgs_Int32
{
  int32_T data;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_std_msgs_Float32_
#define DEFINED_TYPEDEF_FOR_SL_Bus_std_msgs_Float32_

struct SL_Bus_std_msgs_Float32
{
  real32_T data;
};

#endif

/* Custom Type definition for MATLABSystem: '<S5>/SourceBlock' */
#include "rmw/qos_profiles.h"
#ifndef struct_sJ4ih70VmKcvCeguWN0mNVF
#define struct_sJ4ih70VmKcvCeguWN0mNVF

struct sJ4ih70VmKcvCeguWN0mNVF
{
  real_T sec;
  real_T nsec;
};

#endif                                 /* struct_sJ4ih70VmKcvCeguWN0mNVF */

#ifndef struct_ros_slros2_internal_block_Pub_T
#define struct_ros_slros2_internal_block_Pub_T

struct ros_slros2_internal_block_Pub_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T QOSAvoidROSNamespaceConventions;
};

#endif                              /* struct_ros_slros2_internal_block_Pub_T */

#ifndef struct_ros_slros2_internal_block_Sub_T
#define struct_ros_slros2_internal_block_Sub_T

struct ros_slros2_internal_block_Sub_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T QOSAvoidROSNamespaceConventions;
};

#endif                              /* struct_ros_slros2_internal_block_Sub_T */

/* Forward declaration for rtModel */
typedef struct tag_RTM_ros_test_T RT_MODEL_ros_test_T;

#endif                                 /* ros_test_types_h_ */
