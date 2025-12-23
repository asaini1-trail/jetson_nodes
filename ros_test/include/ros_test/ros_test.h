/*
 * ros_test.h
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

#ifndef ros_test_h_
#define ros_test_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros2_initialize.h"
#include "ros_test_types.h"
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

/* Block signals (default storage) */
struct B_ros_test_T {
  char_T b_zeroDelimTopic[22];
  sJ4ih70VmKcvCeguWN0mNVF deadline;
  int32_T CCaller2;                    /* '<S2>/C Caller2' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_ros_test_T {
  ros_slros2_internal_block_Pub_T obj; /* '<S4>/SinkBlock' */
  ros_slros2_internal_block_Sub_T obj_c;/* '<S5>/SourceBlock' */
  boolean_T objisempty;                /* '<S5>/SourceBlock' */
  boolean_T objisempty_d;              /* '<S4>/SinkBlock' */
};

/* Real-time Model Data Structure */
struct tag_RTM_ros_test_T {
  const char_T *errorStatus;
};

/* Class declaration for model ros_test */
class ros_test
{
  /* public data and function members */
 public:
  /* Real-Time Model get method */
  RT_MODEL_ros_test_T * getRTM();

  /* model start function */
  void start();

  /* Initial conditions function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  ros_test();

  /* Destructor */
  ~ros_test();

  /* private data and function members */
 private:
  /* Block signals */
  B_ros_test_T ros_test_B;

  /* Block states */
  DW_ros_test_T ros_test_DW;

  /* private member function(s) for subsystem '<Root>'*/
  void ros_test_Subscriber_setupImpl(const ros_slros2_internal_block_Sub_T *obj);
  void ros_test_Publisher_setupImpl(const ros_slros2_internal_block_Pub_T *obj);

  /* Real-Time Model */
  RT_MODEL_ros_test_T ros_test_M;
};

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Data Type Conversion1' : Eliminate redundant data type conversion
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
 * '<Root>' : 'ros_test'
 * '<S1>'   : 'ros_test/Blank Message1'
 * '<S2>'   : 'ros_test/Enabled Subsystem'
 * '<S3>'   : 'ros_test/Initialize Function'
 * '<S4>'   : 'ros_test/Publish1'
 * '<S5>'   : 'ros_test/Subscribe'
 * '<S6>'   : 'ros_test/Terminate Function'
 * '<S7>'   : 'ros_test/Subscribe/Enabled Subsystem'
 */
#endif                                 /* ros_test_h_ */
