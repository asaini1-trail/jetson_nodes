/*
 * rover_sw_pwrtrain.h
 *
 * Home License - for personal use only.  Not for government, academic,
 * research, commercial, or other organizational use.
 *
 * Code generation for model "rover_sw_pwrtrain".
 *
 * Model version              : 1.37
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C++ source code generated on : Sun Nov 30 12:04:17 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Apple->ARM64
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef rover_sw_pwrtrain_h_
#define rover_sw_pwrtrain_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros2_initialize.h"
#include "rover_sw_pwrtrain_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* user code (top of header file) */
#include "vesc_uart.h"

/* Block signals for system '<S22>/Enabled Subsystem' */
struct B_EnabledSubsystem_rover_sw_p_T {
  SL_Bus_std_msgs_Float32 In1;         /* '<S26>/In1' */
};

/* Block signals (default storage) */
struct B_rover_sw_pwrtrain_T {
  char_T b_zeroDelimTopic[28];
  char_T b_zeroDelimTopic_m[28];
  char_T b_zeroDelimTopic_c[27];
  char_T b_zeroDelimTopic_k[27];
  char_T b_zeroDelimTopic_cx[19];
  char_T b_zeroDelimTopic_b[19];
  char_T b_zeroDelimTopic_p[17];
  char_T b_zeroDelimTopic_cv[16];
  sJ4ih70VmKcvCeguWN0mNVF deadline;
  SL_Bus_std_msgs_Bool In1;            /* '<S29>/In1' */
  int32_T vesc_send_duty_left;         /* '<S25>/vesc_send_duty_left' */
  int32_T vesc_send_duty_right;        /* '<S25>/vesc_send_duty_right' */
  B_EnabledSubsystem_rover_sw_p_T EnabledSubsystem_g;/* '<S24>/Enabled Subsystem' */
  B_EnabledSubsystem_rover_sw_p_T EnabledSubsystem_k;/* '<S23>/Enabled Subsystem' */
  B_EnabledSubsystem_rover_sw_p_T EnabledSubsystem_d;/* '<S22>/Enabled Subsystem' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_rover_sw_pwrtrain_T {
  ros_slros2_internal_block_Pub_T obj; /* '<S21>/SinkBlock' */
  ros_slros2_internal_block_Pub_T obj_a;/* '<S20>/SinkBlock' */
  ros_slros2_internal_block_Pub_T obj_o;/* '<S14>/SinkBlock' */
  ros_slros2_internal_block_Pub_T obj_l;/* '<S13>/SinkBlock' */
  ros_slros2_internal_block_Pub_T obj_g;/* '<S7>/SinkBlock' */
  ros_slros2_internal_block_Sub_T obj_c;/* '<S10>/SourceBlock' */
  ros_slros2_internal_block_Sub_T obj_ll;/* '<S24>/SourceBlock' */
  ros_slros2_internal_block_Sub_T obj_h;/* '<S23>/SourceBlock' */
  ros_slros2_internal_block_Sub_T obj_b;/* '<S22>/SourceBlock' */
  boolean_T objisempty;                /* '<S10>/SourceBlock' */
  boolean_T objisempty_f;              /* '<S24>/SourceBlock' */
  boolean_T objisempty_j;              /* '<S23>/SourceBlock' */
  boolean_T objisempty_c;              /* '<S22>/SourceBlock' */
  boolean_T objisempty_d;              /* '<S21>/SinkBlock' */
  boolean_T objisempty_n;              /* '<S20>/SinkBlock' */
  boolean_T objisempty_k;              /* '<S14>/SinkBlock' */
  boolean_T objisempty_i;              /* '<S13>/SinkBlock' */
  boolean_T objisempty_kn;             /* '<S7>/SinkBlock' */
};

/* External inputs (root inport signals with default storage) */
struct ExtU_rover_sw_pwrtrain_T {
  real_T throttle;                     /* '<Root>/throttle' */
  real_T steering;                     /* '<Root>/steering' */
};

/* Real-time Model Data Structure */
struct tag_RTM_rover_sw_pwrtrain_T {
  const char_T *errorStatus;
};

/* Class declaration for model rover_sw_pwrtrain */
class rover_sw_pwrtrain
{
  /* public data and function members */
 public:
  /* Real-Time Model get method */
  RT_MODEL_rover_sw_pwrtrain_T * getRTM();

  /* Root inports set method */
  void setExternalInputs(const ExtU_rover_sw_pwrtrain_T
    *pExtU_rover_sw_pwrtrain_T)
  {
    rover_sw_pwrtrain_U = *pExtU_rover_sw_pwrtrain_T;
  }

  /* model start function */
  void start();

  /* Initial conditions function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  rover_sw_pwrtrain();

  /* Destructor */
  ~rover_sw_pwrtrain();

  /* private data and function members */
 private:
  /* External inputs */
  ExtU_rover_sw_pwrtrain_T rover_sw_pwrtrain_U;

  /* Block signals */
  B_rover_sw_pwrtrain_T rover_sw_pwrtrain_B;

  /* Block states */
  DW_rover_sw_pwrtrain_T rover_sw_pwrtrain_DW;

  /* private member function(s) for subsystem '<S22>/Enabled Subsystem'*/
  static void rover_sw__EnabledSubsystem_Init(B_EnabledSubsystem_rover_sw_p_T
    *localB);
  static void rover_sw_pwrtr_EnabledSubsystem(boolean_T rtu_Enable, const
    SL_Bus_std_msgs_Float32 *rtu_In1, B_EnabledSubsystem_rover_sw_p_T *localB);

  /* private member function(s) for subsystem '<Root>'*/
  void rover_sw_p_Subscriber_setupImpl(const ros_slros2_internal_block_Sub_T
    *obj);
  void rover_s_Subscriber_setupImpl_py(const ros_slros2_internal_block_Sub_T
    *obj);
  void rover_sw_Subscriber_setupImpl_p(const ros_slros2_internal_block_Sub_T
    *obj);
  void rover_s_Publisher_setupImpl_pyc(const ros_slros2_internal_block_Pub_T
    *obj);
  void rover__Publisher_setupImpl_pycx(const ros_slros2_internal_block_Pub_T
    *obj);
  void rover_sw_pw_Publisher_setupImpl(const ros_slros2_internal_block_Pub_T
    *obj);
  void rover__Subscriber_setupImpl_pyc(const ros_slros2_internal_block_Sub_T
    *obj);
  void rover_sw__Publisher_setupImpl_p(const ros_slros2_internal_block_Pub_T
    *obj);
  void rover_sw_Publisher_setupImpl_py(const ros_slros2_internal_block_Pub_T
    *obj);

  /* Real-Time Model */
  RT_MODEL_rover_sw_pwrtrain_T rover_sw_pwrtrain_M;
};

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S8>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S8>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S15>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S15>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion3' : Eliminate redundant data type conversion
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
 * '<Root>' : 'rover_sw_pwrtrain'
 * '<S1>'   : 'rover_sw_pwrtrain/Initialize Function'
 * '<S2>'   : 'rover_sw_pwrtrain/Terminate Function'
 * '<S3>'   : 'rover_sw_pwrtrain/led_controls'
 * '<S4>'   : 'rover_sw_pwrtrain/motor_controls'
 * '<S5>'   : 'rover_sw_pwrtrain/led_controls/lamp_contrl'
 * '<S6>'   : 'rover_sw_pwrtrain/led_controls/lamp_contrl/Blank Message1'
 * '<S7>'   : 'rover_sw_pwrtrain/led_controls/lamp_contrl/Publish1'
 * '<S8>'   : 'rover_sw_pwrtrain/motor_controls/If Action Subsystem'
 * '<S9>'   : 'rover_sw_pwrtrain/motor_controls/If Action Subsystem1'
 * '<S10>'  : 'rover_sw_pwrtrain/motor_controls/Subscribe2'
 * '<S11>'  : 'rover_sw_pwrtrain/motor_controls/If Action Subsystem/Blank Message1'
 * '<S12>'  : 'rover_sw_pwrtrain/motor_controls/If Action Subsystem/Blank Message2'
 * '<S13>'  : 'rover_sw_pwrtrain/motor_controls/If Action Subsystem/Publish1'
 * '<S14>'  : 'rover_sw_pwrtrain/motor_controls/If Action Subsystem/Publish2'
 * '<S15>'  : 'rover_sw_pwrtrain/motor_controls/If Action Subsystem/Subsystem'
 * '<S16>'  : 'rover_sw_pwrtrain/motor_controls/If Action Subsystem1/Blank Message1'
 * '<S17>'  : 'rover_sw_pwrtrain/motor_controls/If Action Subsystem1/Blank Message2'
 * '<S18>'  : 'rover_sw_pwrtrain/motor_controls/If Action Subsystem1/Compare To Constant'
 * '<S19>'  : 'rover_sw_pwrtrain/motor_controls/If Action Subsystem1/Compare To Constant1'
 * '<S20>'  : 'rover_sw_pwrtrain/motor_controls/If Action Subsystem1/Publish1'
 * '<S21>'  : 'rover_sw_pwrtrain/motor_controls/If Action Subsystem1/Publish2'
 * '<S22>'  : 'rover_sw_pwrtrain/motor_controls/If Action Subsystem1/Subscribe'
 * '<S23>'  : 'rover_sw_pwrtrain/motor_controls/If Action Subsystem1/Subscribe1'
 * '<S24>'  : 'rover_sw_pwrtrain/motor_controls/If Action Subsystem1/Subscribe2'
 * '<S25>'  : 'rover_sw_pwrtrain/motor_controls/If Action Subsystem1/Subsystem'
 * '<S26>'  : 'rover_sw_pwrtrain/motor_controls/If Action Subsystem1/Subscribe/Enabled Subsystem'
 * '<S27>'  : 'rover_sw_pwrtrain/motor_controls/If Action Subsystem1/Subscribe1/Enabled Subsystem'
 * '<S28>'  : 'rover_sw_pwrtrain/motor_controls/If Action Subsystem1/Subscribe2/Enabled Subsystem'
 * '<S29>'  : 'rover_sw_pwrtrain/motor_controls/Subscribe2/Enabled Subsystem'
 */
#endif                                 /* rover_sw_pwrtrain_h_ */
