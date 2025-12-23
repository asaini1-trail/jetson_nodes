/*
 * rover_sw_pwrtrain_24b.h
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

#ifndef rover_sw_pwrtrain_24b_h_
#define rover_sw_pwrtrain_24b_h_
#include <cstring>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros2_initialize.h"
#include "rover_sw_pwrtrain_24b_types.h"
#include "coder_array.h"

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetInf.h"

}

extern "C"
{

#include "rtGetNaN.h"

}

#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

/* user code (top of header file) */
#include "vesc_uart.h"

/* Block signals for system '<S35>/Enabled Subsystem' */
struct B_EnabledSubsystem_rover_sw_p_T {
  SL_Bus_std_msgs_Float32 In1;         /* '<S41>/In1' */
};

/* Block signals for system '<S39>/Enabled Subsystem' */
struct B_EnabledSubsystem_rover_sw_e_T {
  SL_Bus_std_msgs_Bool In1;            /* '<S45>/In1' */
};

/* Block signals (default storage) */
struct B_rover_sw_pwrtrain_24b_T {
  coder::array<int16_T,2> laneX;
  coder::array<real_T,2> waypoints;
  real_T paddedWaypts[20000];
  real_T waypoints_m[20000];           /* '<S7>/MATLAB Function1' */
  int16_T tmp_data[10000];
  uint32_T inSize[8];
  char_T b_zeroDelimTopic[28];
  char_T b_zeroDelimTopic_c[28];
  char_T b_zeroDelimTopic_k[28];
  char_T b_zeroDelimTopic_cx[27];
  char_T b_zeroDelimTopic_b[27];
  char_T b_zeroDelimTopic_p[27];
  real_T Integrator[3];                /* '<S24>/Integrator' */
  real_T MATLABSystem[3];              /* '<S24>/MATLAB System' */
  char_T b_zeroDelimTopic_cv[19];
  char_T b_zeroDelimTopic_f[19];
  char_T b_zeroDelimTopic_g[18];
  char_T b_zeroDelimTopic_g1[16];
  char_T b_zeroDelimTopic_m[16];
  char_T b_zeroDelimTopic_n[16];
  sJ4ih70VmKcvCeguWN0mNVF deadline;
  sJ4ih70VmKcvCeguWN0mNVF deadline_p;
  real_T lookaheadStartPt[2];
  real_T waypoints_l[2];
  real_T waypoints_j[2];
  real_T refPt[2];
  real_T Product;                      /* '<S25>/Product' */
  real_T Product1;                     /* '<S25>/Product1' */
  real_T x;
  real_T y;
  real_T i;
  real_T overshootDist;
  real_T waypoints_tmp;
  real_T waypoints_tmp_d;
  real_T alpha;
  real_T v12;
  real_T v12_g;
  real_T scale;
  real_T absxk;
  real_T t;
  int32_T vesc_send_duty_left;         /* '<S23>/vesc_send_duty_left' */
  int32_T vesc_send_duty_right;        /* '<S23>/vesc_send_duty_right' */
  int32_T targetX;
  boolean_T SourceBlock_o1;            /* '<S40>/SourceBlock' */
  boolean_T SourceBlock_o1_n;          /* '<S39>/SourceBlock' */
  boolean_T SourceBlock_o1_l;          /* '<S38>/SourceBlock' */
  boolean_T SourceBlock_o1_m;          /* '<S37>/SourceBlock' */
  boolean_T SourceBlock_o1_nc;         /* '<S36>/SourceBlock' */
  boolean_T SourceBlock_o1_mk;         /* '<S35>/SourceBlock' */
  B_EnabledSubsystem_rover_sw_e_T EnabledSubsystem_b;/* '<S40>/Enabled Subsystem' */
  B_EnabledSubsystem_rover_sw_e_T EnabledSubsystem_g;/* '<S39>/Enabled Subsystem' */
  B_EnabledSubsystem_rover_sw_p_T EnabledSubsystem_p4;/* '<S38>/Enabled Subsystem' */
  B_EnabledSubsystem_rover_sw_p_T EnabledSubsystem_p;/* '<S37>/Enabled Subsystem' */
  B_EnabledSubsystem_rover_sw_p_T EnabledSubsystem_o;/* '<S36>/Enabled Subsystem' */
  B_EnabledSubsystem_rover_sw_p_T EnabledSubsystem;/* '<S35>/Enabled Subsystem' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_rover_sw_pwrtrain_24b_T {
  nav_slalgs_internal_PurePursu_T obj; /* '<S6>/Pure Pursuit' */
  robotics_slmobile_internal_bl_T obj_j;/* '<S24>/MATLAB System' */
  ros_slros2_internal_block_Pub_T obj_m;/* '<S34>/SinkBlock' */
  ros_slros2_internal_block_Pub_T obj_g;/* '<S33>/SinkBlock' */
  ros_slros2_internal_block_Pub_T obj_f;/* '<S32>/SinkBlock' */
  ros_slros2_internal_block_Pub_T obj_g4;/* '<S31>/SinkBlock' */
  ros_slros2_internal_block_Pub_T obj_n;/* '<S18>/SinkBlock' */
  ros_slros2_internal_block_Pub_T obj_c;/* '<S17>/SinkBlock' */
  ros_slros2_internal_block_Pub_T obj_p;/* '<S22>/SinkBlock' */
  ros_slros2_internal_block_Pub_T obj_a;/* '<S21>/SinkBlock' */
  ros_slros2_internal_block_Sub_T obj_cy;/* '<S40>/SourceBlock' */
  ros_slros2_internal_block_Sub_T obj_mg;/* '<S39>/SourceBlock' */
  ros_slros2_internal_block_Sub_T obj_fl;/* '<S38>/SourceBlock' */
  ros_slros2_internal_block_Sub_T obj_h;/* '<S37>/SourceBlock' */
  ros_slros2_internal_block_Sub_T obj_ng;/* '<S36>/SourceBlock' */
  ros_slros2_internal_block_Sub_T obj_i;/* '<S35>/SourceBlock' */
  real32_T PrevY;                      /* '<S23>/Rate Limiter' */
  real32_T PrevY_l;                    /* '<S23>/Rate Limiter1' */
  int32_T SFunction_DIMS2[2];          /* '<S7>/MATLAB Function1' */
  int8_T If_ActiveSubsystem;           /* '<S5>/If' */
  boolean_T objisempty;                /* '<S40>/SourceBlock' */
  boolean_T objisempty_l;              /* '<S39>/SourceBlock' */
  boolean_T objisempty_f;              /* '<S38>/SourceBlock' */
  boolean_T objisempty_e;              /* '<S37>/SourceBlock' */
  boolean_T objisempty_ea;             /* '<S36>/SourceBlock' */
  boolean_T objisempty_c;              /* '<S35>/SourceBlock' */
  boolean_T objisempty_n;              /* '<S34>/SinkBlock' */
  boolean_T objisempty_k;              /* '<S33>/SinkBlock' */
  boolean_T objisempty_ks;             /* '<S32>/SinkBlock' */
  boolean_T objisempty_k1;             /* '<S31>/SinkBlock' */
  boolean_T objisempty_ek;             /* '<S6>/Pure Pursuit' */
  boolean_T objisempty_o;              /* '<S24>/MATLAB System' */
  boolean_T objisempty_j;              /* '<S18>/SinkBlock' */
  boolean_T objisempty_jb;             /* '<S17>/SinkBlock' */
  boolean_T objisempty_d;              /* '<S22>/SinkBlock' */
  boolean_T objisempty_nh;             /* '<S21>/SinkBlock' */
};

/* Continuous states (default storage) */
struct X_rover_sw_pwrtrain_24b_T {
  real_T Integrator_CSTATE[3];         /* '<S24>/Integrator' */
};

/* State derivatives (default storage) */
struct XDot_rover_sw_pwrtrain_24b_T {
  real_T Integrator_CSTATE[3];         /* '<S24>/Integrator' */
};

/* State disabled  */
struct XDis_rover_sw_pwrtrain_24b_T {
  boolean_T Integrator_CSTATE[3];      /* '<S24>/Integrator' */
};

/* Invariant block signals (default storage) */
struct ConstB_rover_sw_pwrtrain_24b_T {
  SL_Bus_std_msgs_Int32 BusAssignment4;/* '<S8>/Bus Assignment4' */
  SL_Bus_std_msgs_Int32 BusAssignment1;/* '<S8>/Bus Assignment1' */
  SL_Bus_std_msgs_Int32 BusAssignment2;/* '<S8>/Bus Assignment2' */
};

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
struct ODE3_IntgData {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
};

#endif

/* Constant parameters with dynamic initialization (default storage) */
struct ConstInitP_rover_sw_pwrtrain__T {
  /* Expression: WheelSpeedRange
   * Referenced by: '<S24>/MATLAB System'
   */
  real_T MATLABSystem_WheelSpeedRange[2];
};

/* Real-time Model Data Structure */
struct tag_RTM_rover_sw_pwrtrain_24b_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_rover_sw_pwrtrain_24b_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_rover_sw_pwrtrain_24b_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[3];
  real_T odeF[3][3];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tStart;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[4];
  } Timing;
};

extern const ConstB_rover_sw_pwrtrain_24b_T rover_sw_pwrtrain_24b_ConstB;/* constant block i/o */

/* Constant parameters with dynamic initialization (default storage) */
extern ConstInitP_rover_sw_pwrtrain__T rover_sw_pwrtrain_24_ConstInitP;/* constant parameters */

/* Class declaration for model rover_sw_pwrtrain_24b */
class rover_sw_pwrtrain_24b
{
  /* public data and function members */
 public:
  /* Real-Time Model get method */
  RT_MODEL_rover_sw_pwrtrain_24_T * getRTM();

  /* model start function */
  void start();

  /* Initial conditions function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  rover_sw_pwrtrain_24b();

  /* Destructor */
  ~rover_sw_pwrtrain_24b();

  /* private data and function members */
 private:
  /* Block signals */
  B_rover_sw_pwrtrain_24b_T rover_sw_pwrtrain_24b_B;

  /* Block states */
  DW_rover_sw_pwrtrain_24b_T rover_sw_pwrtrain_24b_DW;

  /* Block continuous states */
  X_rover_sw_pwrtrain_24b_T rover_sw_pwrtrain_24b_X;

  /* Block Continuous state disabled vector */
  XDis_rover_sw_pwrtrain_24b_T rover_sw_pwrtrain_24b_XDis;

  /* private member function(s) for subsystem '<S35>/Enabled Subsystem'*/
  static void rover_sw__EnabledSubsystem_Init(B_EnabledSubsystem_rover_sw_p_T
    *localB);
  static void rover_sw_pwrtr_EnabledSubsystem(boolean_T rtu_Enable, const
    SL_Bus_std_msgs_Float32 *rtu_In1, B_EnabledSubsystem_rover_sw_p_T *localB);

  /* private member function(s) for subsystem '<S39>/Enabled Subsystem'*/
  static void rover_s_EnabledSubsystem_p_Init(B_EnabledSubsystem_rover_sw_e_T
    *localB);
  static void rover_sw_pwr_EnabledSubsystem_g(boolean_T rtu_Enable, const
    SL_Bus_std_msgs_Bool *rtu_In1, B_EnabledSubsystem_rover_sw_e_T *localB);

  /* private member function(s) for subsystem '<Root>'*/
  void rov_Publisher_setupImpl_mygou5b(const ros_slros2_internal_block_Pub_T
    *obj);
  void rover__Publisher_setupImpl_mygo(const ros_slros2_internal_block_Pub_T
    *obj);
  void rover_Publisher_setupImpl_mygou(const ros_slros2_internal_block_Pub_T
    *obj);
  void rover_Subscriber_setupImpl_mygo(const ros_slros2_internal_block_Sub_T
    *obj);
  void rover_sw_p_Subscriber_setupImpl(const ros_slros2_internal_block_Sub_T
    *obj);
  void rover_sw_Subscriber_setupImpl_m(const ros_slros2_internal_block_Sub_T
    *obj);
  void rover_sw_pw_Publisher_setupImpl(const ros_slros2_internal_block_Pub_T
    *obj);
  void rover_sw__Publisher_setupImpl_m(const ros_slros2_internal_block_Pub_T
    *obj);
  void rover_sw_Publisher_setupImpl_my(const ros_slros2_internal_block_Pub_T
    *obj);
  void rover_s_Publisher_setupImpl_myg(const ros_slros2_internal_block_Pub_T
    *obj);
  void rove_Publisher_setupImpl_mygou5(const ros_slros2_internal_block_Pub_T
    *obj);
  void DifferentialDriveKinematics_set(robotics_slmobile_internal_bl_T *obj);
  void rover_s_Subscriber_setupImpl_my(const ros_slros2_internal_block_Sub_T
    *obj);
  void rover__Subscriber_setupImpl_myg(const ros_slros2_internal_block_Sub_T
    *obj);
  void rove_Subscriber_setupImpl_mygou(const ros_slros2_internal_block_Sub_T
    *obj);
  real_T rover_sw_pwrtrain_24b_norm(const real_T x[2]);
  real_T rover_sw_pwr_closestPointOnLine(const real_T pt1[2], real_T pt2[2],
    const real_T refPt[2]);

  /* Global mass matrix */

  /* Continuous states update member function*/
  void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si );

  /* Derivatives member function */
  void rover_sw_pwrtrain_24b_derivatives();

  /* Real-Time Model */
  RT_MODEL_rover_sw_pwrtrain_24_T rover_sw_pwrtrain_24b_M;
};

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S10>/Compare' : Unused code path elimination
 * Block '<S10>/Constant' : Unused code path elimination
 * Block '<S3>/Constant' : Unused code path elimination
 * Block '<S3>/Constant1' : Unused code path elimination
 * Block '<S3>/Switch' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate' : Unused code path elimination
 * Block '<S6>/Display' : Unused code path elimination
 * Block '<S6>/Display1' : Unused code path elimination
 * Block '<S6>/Display2' : Unused code path elimination
 * Block '<S25>/Display' : Unused code path elimination
 * Block '<S13>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S13>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S13>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S13>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S14>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S14>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S24>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S24>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S24>/Reshape' : Reshape block reduction
 * Block '<S6>/Zero-Order Hold' : Eliminated since input and output rates are identical
 * Block '<S6>/Zero-Order Hold1' : Eliminated since input and output rates are identical
 * Block '<S8>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S8>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S8>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S8>/Data Type Conversion4' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'rover_sw_pwrtrain_24b'
 * '<S1>'   : 'rover_sw_pwrtrain_24b/Initialize Function'
 * '<S2>'   : 'rover_sw_pwrtrain_24b/Terminate Function'
 * '<S3>'   : 'rover_sw_pwrtrain_24b/forward_collision_check'
 * '<S4>'   : 'rover_sw_pwrtrain_24b/lamp_controls'
 * '<S5>'   : 'rover_sw_pwrtrain_24b/motor_controls'
 * '<S6>'   : 'rover_sw_pwrtrain_24b/path_following'
 * '<S7>'   : 'rover_sw_pwrtrain_24b/path_generation'
 * '<S8>'   : 'rover_sw_pwrtrain_24b/ros_publish'
 * '<S9>'   : 'rover_sw_pwrtrain_24b/ros_subscribe'
 * '<S10>'  : 'rover_sw_pwrtrain_24b/forward_collision_check/Compare To Constant'
 * '<S11>'  : 'rover_sw_pwrtrain_24b/lamp_controls/headlamps_controls'
 * '<S12>'  : 'rover_sw_pwrtrain_24b/lamp_controls/status_indicator_lamp'
 * '<S13>'  : 'rover_sw_pwrtrain_24b/motor_controls/Subsystem'
 * '<S14>'  : 'rover_sw_pwrtrain_24b/motor_controls/Subsystem1'
 * '<S15>'  : 'rover_sw_pwrtrain_24b/motor_controls/Subsystem/Blank Message1'
 * '<S16>'  : 'rover_sw_pwrtrain_24b/motor_controls/Subsystem/Blank Message2'
 * '<S17>'  : 'rover_sw_pwrtrain_24b/motor_controls/Subsystem/Publish1'
 * '<S18>'  : 'rover_sw_pwrtrain_24b/motor_controls/Subsystem/Publish2'
 * '<S19>'  : 'rover_sw_pwrtrain_24b/motor_controls/Subsystem1/Blank Message1'
 * '<S20>'  : 'rover_sw_pwrtrain_24b/motor_controls/Subsystem1/Blank Message2'
 * '<S21>'  : 'rover_sw_pwrtrain_24b/motor_controls/Subsystem1/Publish1'
 * '<S22>'  : 'rover_sw_pwrtrain_24b/motor_controls/Subsystem1/Publish2'
 * '<S23>'  : 'rover_sw_pwrtrain_24b/motor_controls/Subsystem1/vesc_comm'
 * '<S24>'  : 'rover_sw_pwrtrain_24b/path_following/Differential Drive Kinematic Model'
 * '<S25>'  : 'rover_sw_pwrtrain_24b/path_following/Zero-Velocity At Goal'
 * '<S26>'  : 'rover_sw_pwrtrain_24b/path_generation/MATLAB Function1'
 * '<S27>'  : 'rover_sw_pwrtrain_24b/ros_publish/Blank Message1'
 * '<S28>'  : 'rover_sw_pwrtrain_24b/ros_publish/Blank Message2'
 * '<S29>'  : 'rover_sw_pwrtrain_24b/ros_publish/Blank Message3'
 * '<S30>'  : 'rover_sw_pwrtrain_24b/ros_publish/Blank Message4'
 * '<S31>'  : 'rover_sw_pwrtrain_24b/ros_publish/Publish1'
 * '<S32>'  : 'rover_sw_pwrtrain_24b/ros_publish/Publish2'
 * '<S33>'  : 'rover_sw_pwrtrain_24b/ros_publish/Publish3'
 * '<S34>'  : 'rover_sw_pwrtrain_24b/ros_publish/Publish4'
 * '<S35>'  : 'rover_sw_pwrtrain_24b/ros_subscribe/Subscribe'
 * '<S36>'  : 'rover_sw_pwrtrain_24b/ros_subscribe/Subscribe1'
 * '<S37>'  : 'rover_sw_pwrtrain_24b/ros_subscribe/Subscribe2'
 * '<S38>'  : 'rover_sw_pwrtrain_24b/ros_subscribe/Subscribe3'
 * '<S39>'  : 'rover_sw_pwrtrain_24b/ros_subscribe/Subscribe4'
 * '<S40>'  : 'rover_sw_pwrtrain_24b/ros_subscribe/Subscribe5'
 * '<S41>'  : 'rover_sw_pwrtrain_24b/ros_subscribe/Subscribe/Enabled Subsystem'
 * '<S42>'  : 'rover_sw_pwrtrain_24b/ros_subscribe/Subscribe1/Enabled Subsystem'
 * '<S43>'  : 'rover_sw_pwrtrain_24b/ros_subscribe/Subscribe2/Enabled Subsystem'
 * '<S44>'  : 'rover_sw_pwrtrain_24b/ros_subscribe/Subscribe3/Enabled Subsystem'
 * '<S45>'  : 'rover_sw_pwrtrain_24b/ros_subscribe/Subscribe4/Enabled Subsystem'
 * '<S46>'  : 'rover_sw_pwrtrain_24b/ros_subscribe/Subscribe5/Enabled Subsystem'
 */
#endif                                 /* rover_sw_pwrtrain_24b_h_ */
