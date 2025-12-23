/*
 * rover_sw_pwrtrain_24b_types.h
 *
 * Home License - for personal use only.  Not for government, academic,
 * research, commercial, or other organizational use.
 *
 * Code generation for model "rover_sw_pwrtrain_24b".
 *
 * Model version              : 1.39
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C++ source code generated on : Mon Dec 22 21:21:49 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Apple->ARM64
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef rover_sw_pwrtrain_24b_types_h_
#define rover_sw_pwrtrain_24b_types_h_
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

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_std_msgs_Bool_
#define DEFINED_TYPEDEF_FOR_SL_Bus_std_msgs_Bool_

struct SL_Bus_std_msgs_Bool
{
  boolean_T data;
};

#endif

/* Custom Type definition for MATLABSystem: '<S40>/SourceBlock' */
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

#ifndef struct_c_differentialDriveKinematics_T
#define struct_c_differentialDriveKinematics_T

struct c_differentialDriveKinematics_T
{
  real_T TrackWidth;
  real_T WheelRadius;
  real_T WheelSpeedRange[2];
  char_T VehicleInputsInternal[23];
};

#endif                              /* struct_c_differentialDriveKinematics_T */

#ifndef struct_robotics_slmobile_internal_bl_T
#define struct_robotics_slmobile_internal_bl_T

struct robotics_slmobile_internal_bl_T
{
  boolean_T tunablePropertyChanged[3];
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  c_differentialDriveKinematics_T KinModel;
  real_T TrackWidth;
  real_T WheelRadius;
  real_T WheelSpeedRange[2];
};

#endif                              /* struct_robotics_slmobile_internal_bl_T */

#ifndef struct_cell_wrap_rover_sw_pwrtrain_2_T
#define struct_cell_wrap_rover_sw_pwrtrain_2_T

struct cell_wrap_rover_sw_pwrtrain_2_T
{
  uint32_T f1[8];
};

#endif                              /* struct_cell_wrap_rover_sw_pwrtrain_2_T */

#ifndef struct_nav_slalgs_internal_PurePursu_T
#define struct_nav_slalgs_internal_PurePursu_T

struct nav_slalgs_internal_PurePursu_T
{
  int32_T isInitialized;
  cell_wrap_rover_sw_pwrtrain_2_T inputVarSize[2];
  boolean_T CacheInputSizes;
  real_T MaxAngularVelocity;
  real_T LookaheadDistance;
  real_T DesiredLinearVelocity;
  real_T ProjectionPoint[2];
  real_T ProjectionLineIndex;
  real_T LookaheadPoint[2];
  real_T LastPose[3];
  real_T WaypointsInternal[20000];
};

#endif                              /* struct_nav_slalgs_internal_PurePursu_T */

/* Forward declaration for rtModel */
typedef struct tag_RTM_rover_sw_pwrtrain_24b_T RT_MODEL_rover_sw_pwrtrain_24_T;

#endif                                 /* rover_sw_pwrtrain_24b_types_h_ */
