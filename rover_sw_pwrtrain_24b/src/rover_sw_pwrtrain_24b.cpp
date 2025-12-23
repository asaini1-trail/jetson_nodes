/*
 * rover_sw_pwrtrain_24b.cpp
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

#include "rover_sw_pwrtrain_24b.h"
#include "rtwtypes.h"
#include "rover_sw_pwrtrain_24b_types.h"
#include <string.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include <math.h>
#include "rover_sw_pwrtrain_24b_private.h"
#include "rmw/qos_profiles.h"
#include <stddef.h>
#include "rt_defines.h"

/* user code (top of source file) */
int vesc_open_noargs(void);
void vesc_close(void);
int vesc_send_duty(double duty);
int vesc_poll(float* v_in, float* t_mos, float* t_motor);

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
void rover_sw_pwrtrain_24b::rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  rover_sw_pwrtrain_24b_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  this->step();
  rover_sw_pwrtrain_24b_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  this->step();
  rover_sw_pwrtrain_24b_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * System initialize for enable system:
 *    '<S35>/Enabled Subsystem'
 *    '<S36>/Enabled Subsystem'
 *    '<S37>/Enabled Subsystem'
 *    '<S38>/Enabled Subsystem'
 */
void rover_sw_pwrtrain_24b::rover_sw__EnabledSubsystem_Init
  (B_EnabledSubsystem_rover_sw_p_T *localB)
{
  /* SystemInitialize for SignalConversion generated from: '<S41>/In1' */
  memset(&localB->In1, 0, sizeof(SL_Bus_std_msgs_Float32));
}

/*
 * Output and update for enable system:
 *    '<S35>/Enabled Subsystem'
 *    '<S36>/Enabled Subsystem'
 *    '<S37>/Enabled Subsystem'
 *    '<S38>/Enabled Subsystem'
 */
void rover_sw_pwrtrain_24b::rover_sw_pwrtr_EnabledSubsystem(boolean_T rtu_Enable,
  const SL_Bus_std_msgs_Float32 *rtu_In1, B_EnabledSubsystem_rover_sw_p_T
  *localB)
{
  /* Outputs for Enabled SubSystem: '<S35>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S41>/Enable'
   */
  if (rtu_Enable) {
    /* SignalConversion generated from: '<S41>/In1' */
    localB->In1 = *rtu_In1;
  }

  /* End of Outputs for SubSystem: '<S35>/Enabled Subsystem' */
}

/*
 * System initialize for enable system:
 *    '<S39>/Enabled Subsystem'
 *    '<S40>/Enabled Subsystem'
 */
void rover_sw_pwrtrain_24b::rover_s_EnabledSubsystem_p_Init
  (B_EnabledSubsystem_rover_sw_e_T *localB)
{
  /* SystemInitialize for SignalConversion generated from: '<S45>/In1' */
  memset(&localB->In1, 0, sizeof(SL_Bus_std_msgs_Bool));
}

/*
 * Output and update for enable system:
 *    '<S39>/Enabled Subsystem'
 *    '<S40>/Enabled Subsystem'
 */
void rover_sw_pwrtrain_24b::rover_sw_pwr_EnabledSubsystem_g(boolean_T rtu_Enable,
  const SL_Bus_std_msgs_Bool *rtu_In1, B_EnabledSubsystem_rover_sw_e_T *localB)
{
  /* Outputs for Enabled SubSystem: '<S39>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S45>/Enable'
   */
  if (rtu_Enable) {
    /* SignalConversion generated from: '<S45>/In1' */
    localB->In1 = *rtu_In1;
  }

  /* End of Outputs for SubSystem: '<S39>/Enabled Subsystem' */
}

void rover_sw_pwrtrain_24b::rov_Publisher_setupImpl_mygou5b(const
  ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  sJ4ih70VmKcvCeguWN0mNVF deadline;
  sJ4ih70VmKcvCeguWN0mNVF lifespan;
  sJ4ih70VmKcvCeguWN0mNVF liveliness_lease_duration;
  static const char_T b_zeroDelimTopic[16] = "/auto_mode_stat";
  qos_profile = rmw_qos_profile_default;

  /* Start for MATLABSystem: '<S34>/SinkBlock' */
  deadline.sec = 0.0;
  deadline.nsec = 0.0;
  lifespan.sec = 0.0;
  lifespan.nsec = 0.0;
  liveliness_lease_duration.sec = 0.0;
  liveliness_lease_duration.nsec = 0.0;
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE, deadline, lifespan,
                 RMW_QOS_POLICY_LIVELINESS_AUTOMATIC, liveliness_lease_duration,
                 (bool)obj->QOSAvoidROSNamespaceConventions);
  for (int32_T i = 0; i < 16; i++) {
    /* Start for MATLABSystem: '<S34>/SinkBlock' */
    rover_sw_pwrtrain_24b_B.b_zeroDelimTopic_n[i] = b_zeroDelimTopic[i];
  }

  Pub_rover_sw_pwrtrain_24b_599.createPublisher
    (&rover_sw_pwrtrain_24b_B.b_zeroDelimTopic_n[0], qos_profile);
}

void rover_sw_pwrtrain_24b::rover__Publisher_setupImpl_mygo(const
  ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  sJ4ih70VmKcvCeguWN0mNVF deadline;
  sJ4ih70VmKcvCeguWN0mNVF lifespan;
  sJ4ih70VmKcvCeguWN0mNVF liveliness_lease_duration;
  static const char_T b_zeroDelimTopic[27] = "/vesc/last_cmd_status_left";
  qos_profile = rmw_qos_profile_default;

  /* Start for MATLABSystem: '<S31>/SinkBlock' */
  deadline.sec = 0.0;
  deadline.nsec = 0.0;
  lifespan.sec = 0.0;
  lifespan.nsec = 0.0;
  liveliness_lease_duration.sec = 0.0;
  liveliness_lease_duration.nsec = 0.0;
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE, deadline, lifespan,
                 RMW_QOS_POLICY_LIVELINESS_AUTOMATIC, liveliness_lease_duration,
                 (bool)obj->QOSAvoidROSNamespaceConventions);
  for (int32_T i = 0; i < 27; i++) {
    /* Start for MATLABSystem: '<S31>/SinkBlock' */
    rover_sw_pwrtrain_24b_B.b_zeroDelimTopic_p[i] = b_zeroDelimTopic[i];
  }

  Pub_rover_sw_pwrtrain_24b_388.createPublisher
    (&rover_sw_pwrtrain_24b_B.b_zeroDelimTopic_p[0], qos_profile);
}

void rover_sw_pwrtrain_24b::rover_Publisher_setupImpl_mygou(const
  ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  sJ4ih70VmKcvCeguWN0mNVF deadline;
  sJ4ih70VmKcvCeguWN0mNVF lifespan;
  sJ4ih70VmKcvCeguWN0mNVF liveliness_lease_duration;
  static const char_T b_zeroDelimTopic[28] = "/vesc/last_cmd_status_right";
  qos_profile = rmw_qos_profile_default;

  /* Start for MATLABSystem: '<S32>/SinkBlock' */
  deadline.sec = 0.0;
  deadline.nsec = 0.0;
  lifespan.sec = 0.0;
  lifespan.nsec = 0.0;
  liveliness_lease_duration.sec = 0.0;
  liveliness_lease_duration.nsec = 0.0;
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE, deadline, lifespan,
                 RMW_QOS_POLICY_LIVELINESS_AUTOMATIC, liveliness_lease_duration,
                 (bool)obj->QOSAvoidROSNamespaceConventions);
  for (int32_T i = 0; i < 28; i++) {
    /* Start for MATLABSystem: '<S32>/SinkBlock' */
    rover_sw_pwrtrain_24b_B.b_zeroDelimTopic_k[i] = b_zeroDelimTopic[i];
  }

  Pub_rover_sw_pwrtrain_24b_389.createPublisher
    (&rover_sw_pwrtrain_24b_B.b_zeroDelimTopic_k[0], qos_profile);
}

void rover_sw_pwrtrain_24b::rover_Subscriber_setupImpl_mygo(const
  ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  sJ4ih70VmKcvCeguWN0mNVF deadline;
  sJ4ih70VmKcvCeguWN0mNVF lifespan;
  sJ4ih70VmKcvCeguWN0mNVF liveliness_lease_duration;
  static const char_T b_zeroDelimTopic[18] = "/auto_mode_enable";
  qos_profile = rmw_qos_profile_default;

  /* Start for MATLABSystem: '<S39>/SourceBlock' */
  deadline.sec = 0.0;
  deadline.nsec = 0.0;
  lifespan.sec = 0.0;
  lifespan.nsec = 0.0;
  liveliness_lease_duration.sec = 0.0;
  liveliness_lease_duration.nsec = 0.0;
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE, deadline, lifespan,
                 RMW_QOS_POLICY_LIVELINESS_AUTOMATIC, liveliness_lease_duration,
                 (bool)obj->QOSAvoidROSNamespaceConventions);
  for (int32_T i = 0; i < 18; i++) {
    /* Start for MATLABSystem: '<S39>/SourceBlock' */
    rover_sw_pwrtrain_24b_B.b_zeroDelimTopic_g[i] = b_zeroDelimTopic[i];
  }

  Sub_rover_sw_pwrtrain_24b_521.createSubscriber
    (&rover_sw_pwrtrain_24b_B.b_zeroDelimTopic_g[0], qos_profile);
}

void rover_sw_pwrtrain_24b::rover_sw_p_Subscriber_setupImpl(const
  ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  sJ4ih70VmKcvCeguWN0mNVF deadline;
  sJ4ih70VmKcvCeguWN0mNVF lifespan;
  sJ4ih70VmKcvCeguWN0mNVF liveliness_lease_duration;
  static const char_T b_zeroDelimTopic[19] = "/vesc/cmd_throttle";
  qos_profile = rmw_qos_profile_default;

  /* Start for MATLABSystem: '<S35>/SourceBlock' */
  deadline.sec = 0.0;
  deadline.nsec = 0.0;
  lifespan.sec = 0.0;
  lifespan.nsec = 0.0;
  liveliness_lease_duration.sec = 0.0;
  liveliness_lease_duration.nsec = 0.0;
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE, deadline, lifespan,
                 RMW_QOS_POLICY_LIVELINESS_AUTOMATIC, liveliness_lease_duration,
                 (bool)obj->QOSAvoidROSNamespaceConventions);
  for (int32_T i = 0; i < 19; i++) {
    /* Start for MATLABSystem: '<S35>/SourceBlock' */
    rover_sw_pwrtrain_24b_B.b_zeroDelimTopic_f[i] = b_zeroDelimTopic[i];
  }

  Sub_rover_sw_pwrtrain_24b_390.createSubscriber
    (&rover_sw_pwrtrain_24b_B.b_zeroDelimTopic_f[0], qos_profile);
}

void rover_sw_pwrtrain_24b::rover_sw_Subscriber_setupImpl_m(const
  ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  sJ4ih70VmKcvCeguWN0mNVF deadline;
  sJ4ih70VmKcvCeguWN0mNVF lifespan;
  sJ4ih70VmKcvCeguWN0mNVF liveliness_lease_duration;
  static const char_T b_zeroDelimTopic[19] = "/vesc/cmd_steering";
  qos_profile = rmw_qos_profile_default;

  /* Start for MATLABSystem: '<S36>/SourceBlock' */
  deadline.sec = 0.0;
  deadline.nsec = 0.0;
  lifespan.sec = 0.0;
  lifespan.nsec = 0.0;
  liveliness_lease_duration.sec = 0.0;
  liveliness_lease_duration.nsec = 0.0;
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE, deadline, lifespan,
                 RMW_QOS_POLICY_LIVELINESS_AUTOMATIC, liveliness_lease_duration,
                 (bool)obj->QOSAvoidROSNamespaceConventions);
  for (int32_T i = 0; i < 19; i++) {
    /* Start for MATLABSystem: '<S36>/SourceBlock' */
    rover_sw_pwrtrain_24b_B.b_zeroDelimTopic_cv[i] = b_zeroDelimTopic[i];
  }

  Sub_rover_sw_pwrtrain_24b_391.createSubscriber
    (&rover_sw_pwrtrain_24b_B.b_zeroDelimTopic_cv[0], qos_profile);
}

void rover_sw_pwrtrain_24b::rover_sw_pw_Publisher_setupImpl(const
  ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  sJ4ih70VmKcvCeguWN0mNVF deadline;
  sJ4ih70VmKcvCeguWN0mNVF lifespan;
  sJ4ih70VmKcvCeguWN0mNVF liveliness_lease_duration;
  static const char_T b_zeroDelimTopic[27] = "/vesc/last_cmd_status_left";
  qos_profile = rmw_qos_profile_default;

  /* Start for MATLABSystem: '<S21>/SinkBlock' */
  deadline.sec = 0.0;
  deadline.nsec = 0.0;
  lifespan.sec = 0.0;
  lifespan.nsec = 0.0;
  liveliness_lease_duration.sec = 0.0;
  liveliness_lease_duration.nsec = 0.0;
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE, deadline, lifespan,
                 RMW_QOS_POLICY_LIVELINESS_AUTOMATIC, liveliness_lease_duration,
                 (bool)obj->QOSAvoidROSNamespaceConventions);
  for (int32_T i = 0; i < 27; i++) {
    /* Start for MATLABSystem: '<S21>/SinkBlock' */
    rover_sw_pwrtrain_24b_B.b_zeroDelimTopic_b[i] = b_zeroDelimTopic[i];
  }

  Pub_rover_sw_pwrtrain_24b_138.createPublisher
    (&rover_sw_pwrtrain_24b_B.b_zeroDelimTopic_b[0], qos_profile);
}

void rover_sw_pwrtrain_24b::rover_sw__Publisher_setupImpl_m(const
  ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  sJ4ih70VmKcvCeguWN0mNVF deadline;
  sJ4ih70VmKcvCeguWN0mNVF lifespan;
  sJ4ih70VmKcvCeguWN0mNVF liveliness_lease_duration;
  static const char_T b_zeroDelimTopic[28] = "/vesc/last_cmd_status_right";
  qos_profile = rmw_qos_profile_default;

  /* Start for MATLABSystem: '<S22>/SinkBlock' */
  deadline.sec = 0.0;
  deadline.nsec = 0.0;
  lifespan.sec = 0.0;
  lifespan.nsec = 0.0;
  liveliness_lease_duration.sec = 0.0;
  liveliness_lease_duration.nsec = 0.0;
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE, deadline, lifespan,
                 RMW_QOS_POLICY_LIVELINESS_AUTOMATIC, liveliness_lease_duration,
                 (bool)obj->QOSAvoidROSNamespaceConventions);
  for (int32_T i = 0; i < 28; i++) {
    /* Start for MATLABSystem: '<S22>/SinkBlock' */
    rover_sw_pwrtrain_24b_B.b_zeroDelimTopic_c[i] = b_zeroDelimTopic[i];
  }

  Pub_rover_sw_pwrtrain_24b_139.createPublisher
    (&rover_sw_pwrtrain_24b_B.b_zeroDelimTopic_c[0], qos_profile);
}

void rover_sw_pwrtrain_24b::rover_sw_Publisher_setupImpl_my(const
  ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  sJ4ih70VmKcvCeguWN0mNVF deadline;
  sJ4ih70VmKcvCeguWN0mNVF lifespan;
  sJ4ih70VmKcvCeguWN0mNVF liveliness_lease_duration;
  static const char_T b_zeroDelimTopic[27] = "/vesc/last_cmd_status_left";
  qos_profile = rmw_qos_profile_default;

  /* Start for MATLABSystem: '<S17>/SinkBlock' */
  deadline.sec = 0.0;
  deadline.nsec = 0.0;
  lifespan.sec = 0.0;
  lifespan.nsec = 0.0;
  liveliness_lease_duration.sec = 0.0;
  liveliness_lease_duration.nsec = 0.0;
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE, deadline, lifespan,
                 RMW_QOS_POLICY_LIVELINESS_AUTOMATIC, liveliness_lease_duration,
                 (bool)obj->QOSAvoidROSNamespaceConventions);
  for (int32_T i = 0; i < 27; i++) {
    /* Start for MATLABSystem: '<S17>/SinkBlock' */
    rover_sw_pwrtrain_24b_B.b_zeroDelimTopic_cx[i] = b_zeroDelimTopic[i];
  }

  Pub_rover_sw_pwrtrain_24b_542.createPublisher
    (&rover_sw_pwrtrain_24b_B.b_zeroDelimTopic_cx[0], qos_profile);
}

void rover_sw_pwrtrain_24b::rover_s_Publisher_setupImpl_myg(const
  ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  sJ4ih70VmKcvCeguWN0mNVF deadline;
  sJ4ih70VmKcvCeguWN0mNVF lifespan;
  sJ4ih70VmKcvCeguWN0mNVF liveliness_lease_duration;
  static const char_T b_zeroDelimTopic[28] = "/vesc/last_cmd_status_right";
  qos_profile = rmw_qos_profile_default;

  /* Start for MATLABSystem: '<S18>/SinkBlock' */
  deadline.sec = 0.0;
  deadline.nsec = 0.0;
  lifespan.sec = 0.0;
  lifespan.nsec = 0.0;
  liveliness_lease_duration.sec = 0.0;
  liveliness_lease_duration.nsec = 0.0;
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE, deadline, lifespan,
                 RMW_QOS_POLICY_LIVELINESS_AUTOMATIC, liveliness_lease_duration,
                 (bool)obj->QOSAvoidROSNamespaceConventions);
  for (int32_T i = 0; i < 28; i++) {
    /* Start for MATLABSystem: '<S18>/SinkBlock' */
    rover_sw_pwrtrain_24b_B.b_zeroDelimTopic[i] = b_zeroDelimTopic[i];
  }

  Pub_rover_sw_pwrtrain_24b_543.createPublisher
    (&rover_sw_pwrtrain_24b_B.b_zeroDelimTopic[0], qos_profile);
}

void rover_sw_pwrtrain_24b::rove_Publisher_setupImpl_mygou5(const
  ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  sJ4ih70VmKcvCeguWN0mNVF lifespan;
  sJ4ih70VmKcvCeguWN0mNVF liveliness_lease_duration;
  char_T b_zeroDelimTopic[11];
  static const char_T b_zeroDelimTopic_0[11] = "/led_state";
  qos_profile = rmw_qos_profile_default;

  /* Start for MATLABSystem: '<S33>/SinkBlock' */
  rover_sw_pwrtrain_24b_B.deadline_p.sec = 0.0;
  rover_sw_pwrtrain_24b_B.deadline_p.nsec = 0.0;
  lifespan.sec = 0.0;
  lifespan.nsec = 0.0;
  liveliness_lease_duration.sec = 0.0;
  liveliness_lease_duration.nsec = 0.0;
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE,
                 rover_sw_pwrtrain_24b_B.deadline_p, lifespan,
                 RMW_QOS_POLICY_LIVELINESS_AUTOMATIC, liveliness_lease_duration,
                 (bool)obj->QOSAvoidROSNamespaceConventions);
  for (int32_T i = 0; i < 11; i++) {
    /* Start for MATLABSystem: '<S33>/SinkBlock' */
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Pub_rover_sw_pwrtrain_24b_246.createPublisher(&b_zeroDelimTopic[0],
    qos_profile);
}

void rover_sw_pwrtrain_24b::DifferentialDriveKinematics_set
  (robotics_slmobile_internal_bl_T *obj)
{
  static const char_T b[23] = { 'V', 'e', 'h', 'i', 'c', 'l', 'e', 'S', 'p', 'e',
    'e', 'd', 'H', 'e', 'a', 'd', 'i', 'n', 'g', 'R', 'a', 't', 'e' };

  for (int32_T i = 0; i < 23; i++) {
    /* Start for MATLABSystem: '<S24>/MATLAB System' */
    obj->KinModel.VehicleInputsInternal[i] = b[i];
  }

  /* Start for MATLABSystem: '<S24>/MATLAB System' */
  obj->KinModel.TrackWidth = obj->TrackWidth;
  obj->KinModel.WheelRadius = obj->WheelRadius;
  obj->KinModel.WheelSpeedRange[0] = obj->WheelSpeedRange[0];
  obj->KinModel.WheelSpeedRange[1] = obj->WheelSpeedRange[1];
}

void rover_sw_pwrtrain_24b::rover_s_Subscriber_setupImpl_my(const
  ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  sJ4ih70VmKcvCeguWN0mNVF deadline;
  sJ4ih70VmKcvCeguWN0mNVF lifespan;
  sJ4ih70VmKcvCeguWN0mNVF liveliness_lease_duration;
  static const char_T b_zeroDelimTopic[16] = "/front_distance";
  qos_profile = rmw_qos_profile_default;

  /* Start for MATLABSystem: '<S37>/SourceBlock' */
  deadline.sec = 0.0;
  deadline.nsec = 0.0;
  lifespan.sec = 0.0;
  lifespan.nsec = 0.0;
  liveliness_lease_duration.sec = 0.0;
  liveliness_lease_duration.nsec = 0.0;
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE, deadline, lifespan,
                 RMW_QOS_POLICY_LIVELINESS_AUTOMATIC, liveliness_lease_duration,
                 (bool)obj->QOSAvoidROSNamespaceConventions);
  for (int32_T i = 0; i < 16; i++) {
    /* Start for MATLABSystem: '<S37>/SourceBlock' */
    rover_sw_pwrtrain_24b_B.b_zeroDelimTopic_m[i] = b_zeroDelimTopic[i];
  }

  Sub_rover_sw_pwrtrain_24b_392.createSubscriber
    (&rover_sw_pwrtrain_24b_B.b_zeroDelimTopic_m[0], qos_profile);
}

void rover_sw_pwrtrain_24b::rover__Subscriber_setupImpl_myg(const
  ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  sJ4ih70VmKcvCeguWN0mNVF deadline;
  sJ4ih70VmKcvCeguWN0mNVF lifespan;
  sJ4ih70VmKcvCeguWN0mNVF liveliness_lease_duration;
  static const char_T b_zeroDelimTopic[16] = "/vesc/cmd_speed";
  qos_profile = rmw_qos_profile_default;

  /* Start for MATLABSystem: '<S38>/SourceBlock' */
  deadline.sec = 0.0;
  deadline.nsec = 0.0;
  lifespan.sec = 0.0;
  lifespan.nsec = 0.0;
  liveliness_lease_duration.sec = 0.0;
  liveliness_lease_duration.nsec = 0.0;
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE, deadline, lifespan,
                 RMW_QOS_POLICY_LIVELINESS_AUTOMATIC, liveliness_lease_duration,
                 (bool)obj->QOSAvoidROSNamespaceConventions);
  for (int32_T i = 0; i < 16; i++) {
    /* Start for MATLABSystem: '<S38>/SourceBlock' */
    rover_sw_pwrtrain_24b_B.b_zeroDelimTopic_g1[i] = b_zeroDelimTopic[i];
  }

  Sub_rover_sw_pwrtrain_24b_466.createSubscriber
    (&rover_sw_pwrtrain_24b_B.b_zeroDelimTopic_g1[0], qos_profile);
}

void rover_sw_pwrtrain_24b::rove_Subscriber_setupImpl_mygou(const
  ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  sJ4ih70VmKcvCeguWN0mNVF lifespan;
  sJ4ih70VmKcvCeguWN0mNVF liveliness_lease_duration;
  char_T b_zeroDelimTopic[15];
  static const char_T b_zeroDelimTopic_0[15] = "/inhibit_start";
  qos_profile = rmw_qos_profile_default;

  /* Start for MATLABSystem: '<S40>/SourceBlock' */
  rover_sw_pwrtrain_24b_B.deadline.sec = 0.0;
  rover_sw_pwrtrain_24b_B.deadline.nsec = 0.0;
  lifespan.sec = 0.0;
  lifespan.nsec = 0.0;
  liveliness_lease_duration.sec = 0.0;
  liveliness_lease_duration.nsec = 0.0;
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE,
                 rover_sw_pwrtrain_24b_B.deadline, lifespan,
                 RMW_QOS_POLICY_LIVELINESS_AUTOMATIC, liveliness_lease_duration,
                 (bool)obj->QOSAvoidROSNamespaceConventions);
  for (int32_T i = 0; i < 15; i++) {
    /* Start for MATLABSystem: '<S40>/SourceBlock' */
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_rover_sw_pwrtrain_24b_601.createSubscriber(&b_zeroDelimTopic[0],
    qos_profile);
}

real_T rover_sw_pwrtrain_24b::rover_sw_pwrtrain_24b_norm(const real_T x[2])
{
  real_T y;
  rover_sw_pwrtrain_24b_B.scale = 3.3121686421112381E-170;

  /* Start for MATLABSystem: '<S6>/Pure Pursuit' */
  rover_sw_pwrtrain_24b_B.absxk = fabs(x[0]);
  if (rover_sw_pwrtrain_24b_B.absxk > 3.3121686421112381E-170) {
    y = 1.0;
    rover_sw_pwrtrain_24b_B.scale = rover_sw_pwrtrain_24b_B.absxk;
  } else {
    rover_sw_pwrtrain_24b_B.t = rover_sw_pwrtrain_24b_B.absxk /
      3.3121686421112381E-170;
    y = rover_sw_pwrtrain_24b_B.t * rover_sw_pwrtrain_24b_B.t;
  }

  /* Start for MATLABSystem: '<S6>/Pure Pursuit' */
  rover_sw_pwrtrain_24b_B.absxk = fabs(x[1]);
  if (rover_sw_pwrtrain_24b_B.absxk > rover_sw_pwrtrain_24b_B.scale) {
    rover_sw_pwrtrain_24b_B.t = rover_sw_pwrtrain_24b_B.scale /
      rover_sw_pwrtrain_24b_B.absxk;
    y = y * rover_sw_pwrtrain_24b_B.t * rover_sw_pwrtrain_24b_B.t + 1.0;
    rover_sw_pwrtrain_24b_B.scale = rover_sw_pwrtrain_24b_B.absxk;
  } else {
    rover_sw_pwrtrain_24b_B.t = rover_sw_pwrtrain_24b_B.absxk /
      rover_sw_pwrtrain_24b_B.scale;
    y += rover_sw_pwrtrain_24b_B.t * rover_sw_pwrtrain_24b_B.t;
  }

  return rover_sw_pwrtrain_24b_B.scale * sqrt(y);
}

real_T rover_sw_pwrtrain_24b::rover_sw_pwr_closestPointOnLine(const real_T pt1[2],
  real_T pt2[2], const real_T refPt[2])
{
  real_T distance;
  int32_T b_k;
  boolean_T exitg1;
  boolean_T p;
  boolean_T p_0;

  /* Start for MATLABSystem: '<S6>/Pure Pursuit' */
  p = false;
  p_0 = true;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 2)) {
    if (!(pt1[b_k] == pt2[b_k])) {
      p_0 = false;
      exitg1 = true;
    } else {
      b_k++;
    }
  }

  if (p_0) {
    p = true;
  }

  if (p) {
    pt2[0] = pt1[0];
    rover_sw_pwrtrain_24b_B.refPt[0] = refPt[0] - pt1[0];
    pt2[1] = pt1[1];
    rover_sw_pwrtrain_24b_B.refPt[1] = refPt[1] - pt1[1];
    distance = rover_sw_pwrtrain_24b_norm(rover_sw_pwrtrain_24b_B.refPt);
  } else {
    rover_sw_pwrtrain_24b_B.alpha = pt2[0] - pt1[0];
    rover_sw_pwrtrain_24b_B.v12 = (pt2[0] - refPt[0]) *
      rover_sw_pwrtrain_24b_B.alpha;
    rover_sw_pwrtrain_24b_B.v12_g = rover_sw_pwrtrain_24b_B.alpha *
      rover_sw_pwrtrain_24b_B.alpha;
    rover_sw_pwrtrain_24b_B.alpha = pt2[1] - pt1[1];
    rover_sw_pwrtrain_24b_B.alpha = ((pt2[1] - refPt[1]) *
      rover_sw_pwrtrain_24b_B.alpha + rover_sw_pwrtrain_24b_B.v12) /
      (rover_sw_pwrtrain_24b_B.alpha * rover_sw_pwrtrain_24b_B.alpha +
       rover_sw_pwrtrain_24b_B.v12_g);
    if (rover_sw_pwrtrain_24b_B.alpha > 1.0) {
      pt2[0] = pt1[0];
      pt2[1] = pt1[1];
    } else if (!(rover_sw_pwrtrain_24b_B.alpha < 0.0)) {
      pt2[0] = (1.0 - rover_sw_pwrtrain_24b_B.alpha) * pt2[0] +
        rover_sw_pwrtrain_24b_B.alpha * pt1[0];
      pt2[1] = (1.0 - rover_sw_pwrtrain_24b_B.alpha) * pt2[1] +
        rover_sw_pwrtrain_24b_B.alpha * pt1[1];
    }

    rover_sw_pwrtrain_24b_B.refPt[0] = refPt[0] - pt2[0];
    rover_sw_pwrtrain_24b_B.refPt[1] = refPt[1] - pt2[1];
    distance = rover_sw_pwrtrain_24b_norm(rover_sw_pwrtrain_24b_B.refPt);
  }

  /* End of Start for MATLABSystem: '<S6>/Pure Pursuit' */
  return distance;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(static_cast<real_T>(tmp), static_cast<real_T>(tmp_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model step function */
void rover_sw_pwrtrain_24b::step()
{
  /* local block i/o variables */
  SL_Bus_std_msgs_Float32 rtb_SourceBlock_o2;
  SL_Bus_std_msgs_Float32 rtb_SourceBlock_o2_l;
  SL_Bus_std_msgs_Float32 rtb_SourceBlock_o2_p;
  SL_Bus_std_msgs_Float32 rtb_SourceBlock_o2_m;
  SL_Bus_std_msgs_Bool rtb_SourceBlock_o2_p4;
  SL_Bus_std_msgs_Bool rtb_SourceBlock_o2_ln;
  int32_T i;
  int32_T ret;
  real32_T rateLimiterRate;
  boolean_T forwardUp;
  boolean_T p;
  static const char_T a[23] = { 'W', 'h', 'e', 'e', 'l', 'S', 'p', 'e', 'e', 'd',
    's', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' };

  static const char_T a_0[23] = { 'V', 'e', 'h', 'i', 'c', 'l', 'e', 'S', 'p',
    'e', 'e', 'd', 'H', 'e', 'a', 'd', 'i', 'n', 'g', 'R', 'a', 't', 'e' };

  SL_Bus_std_msgs_Int32 rtb_BusAssignment1;
  SL_Bus_std_msgs_Int32 rtb_BusAssignment2;
  SL_Bus_std_msgs_Int32 rtb_BusAssignment3;
  int32_T tmp_0;
  real32_T rtb_RateLimiter1;
  int8_T rtAction;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T tmp;
  if (rtmIsMajorTimeStep((&rover_sw_pwrtrain_24b_M))) {
    /* set solver stop time */
    if (!((&rover_sw_pwrtrain_24b_M)->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&(&rover_sw_pwrtrain_24b_M)->solverInfo,
                            (((&rover_sw_pwrtrain_24b_M)->Timing.clockTickH0 + 1)
        * (&rover_sw_pwrtrain_24b_M)->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&(&rover_sw_pwrtrain_24b_M)->solverInfo,
                            (((&rover_sw_pwrtrain_24b_M)->Timing.clockTick0 + 1)
        * (&rover_sw_pwrtrain_24b_M)->Timing.stepSize0 +
        (&rover_sw_pwrtrain_24b_M)->Timing.clockTickH0 *
        (&rover_sw_pwrtrain_24b_M)->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep((&rover_sw_pwrtrain_24b_M))) {
    (&rover_sw_pwrtrain_24b_M)->Timing.t[0] = rtsiGetT
      (&(&rover_sw_pwrtrain_24b_M)->solverInfo);
  }

  tmp = rtmIsMajorTimeStep((&rover_sw_pwrtrain_24b_M));
  if (tmp) {
    /* MATLABSystem: '<S39>/SourceBlock' */
    rover_sw_pwrtrain_24b_B.SourceBlock_o1_n =
      Sub_rover_sw_pwrtrain_24b_521.getLatestMessage(&rtb_SourceBlock_o2_ln);

    /* Outputs for Enabled SubSystem: '<S39>/Enabled Subsystem' */
    rover_sw_pwr_EnabledSubsystem_g(rover_sw_pwrtrain_24b_B.SourceBlock_o1_n,
      &rtb_SourceBlock_o2_ln, &rover_sw_pwrtrain_24b_B.EnabledSubsystem_g);

    /* End of Outputs for SubSystem: '<S39>/Enabled Subsystem' */

    /* MATLABSystem: '<S35>/SourceBlock' */
    rover_sw_pwrtrain_24b_B.SourceBlock_o1_mk =
      Sub_rover_sw_pwrtrain_24b_390.getLatestMessage(&rtb_SourceBlock_o2_m);

    /* Outputs for Enabled SubSystem: '<S35>/Enabled Subsystem' */
    rover_sw_pwrtr_EnabledSubsystem(rover_sw_pwrtrain_24b_B.SourceBlock_o1_mk,
      &rtb_SourceBlock_o2_m, &rover_sw_pwrtrain_24b_B.EnabledSubsystem);

    /* End of Outputs for SubSystem: '<S35>/Enabled Subsystem' */

    /* MATLABSystem: '<S36>/SourceBlock' */
    rover_sw_pwrtrain_24b_B.SourceBlock_o1_nc =
      Sub_rover_sw_pwrtrain_24b_391.getLatestMessage(&rtb_SourceBlock_o2_p);

    /* Outputs for Enabled SubSystem: '<S36>/Enabled Subsystem' */
    rover_sw_pwrtr_EnabledSubsystem(rover_sw_pwrtrain_24b_B.SourceBlock_o1_nc,
      &rtb_SourceBlock_o2_p, &rover_sw_pwrtrain_24b_B.EnabledSubsystem_o);

    /* End of Outputs for SubSystem: '<S36>/Enabled Subsystem' */

    /* MATLAB Function: '<S7>/MATLAB Function1' incorporates:
     *  Constant: '<S7>/Constant1'
     */
    rover_sw_pwrtrain_24b_DW.SFunction_DIMS2[0] = 10000;
    rover_sw_pwrtrain_24b_DW.SFunction_DIMS2[1] = 2;
    memset(&rover_sw_pwrtrain_24b_B.waypoints_m[0], 0, 20000U * sizeof(real_T));
    ret = 1;
    rover_sw_pwrtrain_24b_B.x = 0.0;
    rover_sw_pwrtrain_24b_B.y = 0.0;
    rover_sw_pwrtrain_24b_B.waypoints_m[0] = 0.0;
    rover_sw_pwrtrain_24b_B.waypoints_m[rover_sw_pwrtrain_24b_DW.SFunction_DIMS2[
      0]] = 0.0;
    rover_sw_pwrtrain_24b_B.laneX.set_size(1, 16);
    for (i = 0; i < 16; i++) {
      rover_sw_pwrtrain_24b_B.targetX = i * 100;
      if (rover_sw_pwrtrain_24b_B.targetX <= 1400) {
        rover_sw_pwrtrain_24b_B.laneX[i] = static_cast<int16_T>
          (rover_sw_pwrtrain_24b_B.targetX);
      } else {
        rover_sw_pwrtrain_24b_B.laneX[i] = 1400;
      }
    }

    forwardUp = true;
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i <= 15)) {
      rover_sw_pwrtrain_24b_B.targetX = rover_sw_pwrtrain_24b_B.laneX[i];
      exitg2 = false;
      while ((!exitg2) && (rover_sw_pwrtrain_24b_B.x !=
                           rover_sw_pwrtrain_24b_B.targetX)) {
        if (rover_sw_pwrtrain_24b_B.targetX > rover_sw_pwrtrain_24b_B.x) {
          rover_sw_pwrtrain_24b_B.x += 100.0;
          if (rover_sw_pwrtrain_24b_B.x > rover_sw_pwrtrain_24b_B.targetX) {
            rover_sw_pwrtrain_24b_B.x = rover_sw_pwrtrain_24b_B.targetX;
          }
        } else {
          rover_sw_pwrtrain_24b_B.x -= 100.0;
          if (rover_sw_pwrtrain_24b_B.x < rover_sw_pwrtrain_24b_B.targetX) {
            rover_sw_pwrtrain_24b_B.x = rover_sw_pwrtrain_24b_B.targetX;
          }
        }

        ret++;
        if (ret > 10000) {
          exitg2 = true;
        } else {
          rover_sw_pwrtrain_24b_B.waypoints_m[ret - 1] =
            rover_sw_pwrtrain_24b_B.x;
          rover_sw_pwrtrain_24b_B.waypoints_m[(ret +
            rover_sw_pwrtrain_24b_DW.SFunction_DIMS2[0]) - 1] =
            rover_sw_pwrtrain_24b_B.y;
        }
      }

      if (ret > 10000) {
        exitg1 = true;
      } else {
        if (forwardUp) {
          rover_sw_pwrtrain_24b_B.targetX = 5700;
        } else {
          rover_sw_pwrtrain_24b_B.targetX = 0;
        }

        exitg2 = false;
        while ((!exitg2) && (rover_sw_pwrtrain_24b_B.y !=
                             rover_sw_pwrtrain_24b_B.targetX)) {
          if (rover_sw_pwrtrain_24b_B.targetX > rover_sw_pwrtrain_24b_B.y) {
            rover_sw_pwrtrain_24b_B.y += 200.0;
            if (rover_sw_pwrtrain_24b_B.y > rover_sw_pwrtrain_24b_B.targetX) {
              rover_sw_pwrtrain_24b_B.y = rover_sw_pwrtrain_24b_B.targetX;
            }
          } else {
            rover_sw_pwrtrain_24b_B.y -= 200.0;
            if (rover_sw_pwrtrain_24b_B.y < rover_sw_pwrtrain_24b_B.targetX) {
              rover_sw_pwrtrain_24b_B.y = rover_sw_pwrtrain_24b_B.targetX;
            }
          }

          ret++;
          if (ret > 10000) {
            exitg2 = true;
          } else {
            rover_sw_pwrtrain_24b_B.waypoints_m[ret - 1] =
              rover_sw_pwrtrain_24b_B.x;
            rover_sw_pwrtrain_24b_B.waypoints_m[(ret +
              rover_sw_pwrtrain_24b_DW.SFunction_DIMS2[0]) - 1] =
              rover_sw_pwrtrain_24b_B.y;
          }
        }

        forwardUp = !forwardUp;
        if (ret > 10000) {
          exitg1 = true;
        } else {
          i++;
        }
      }
    }

    while ((rover_sw_pwrtrain_24b_B.y > 0.0) && (ret < 10000)) {
      rover_sw_pwrtrain_24b_B.y -= 200.0;
      if (rover_sw_pwrtrain_24b_B.y < 0.0) {
        rover_sw_pwrtrain_24b_B.y = 0.0;
      }

      ret++;
      rover_sw_pwrtrain_24b_B.waypoints_m[ret - 1] = rover_sw_pwrtrain_24b_B.x;
      rover_sw_pwrtrain_24b_B.waypoints_m[(ret +
        rover_sw_pwrtrain_24b_DW.SFunction_DIMS2[0]) - 1] =
        rover_sw_pwrtrain_24b_B.y;
    }

    while ((rover_sw_pwrtrain_24b_B.x != 0.0) && (ret < 10000)) {
      if (rover_sw_pwrtrain_24b_B.x > 0.0) {
        rover_sw_pwrtrain_24b_B.x -= 100.0;
        if (rover_sw_pwrtrain_24b_B.x < 0.0) {
          rover_sw_pwrtrain_24b_B.x = 0.0;
        }
      } else {
        rover_sw_pwrtrain_24b_B.x += 100.0;
        if (rover_sw_pwrtrain_24b_B.x > 0.0) {
          rover_sw_pwrtrain_24b_B.x = 0.0;
        }
      }

      ret++;
      rover_sw_pwrtrain_24b_B.waypoints_m[ret - 1] = rover_sw_pwrtrain_24b_B.x;
      rover_sw_pwrtrain_24b_B.waypoints_m[(ret +
        rover_sw_pwrtrain_24b_DW.SFunction_DIMS2[0]) - 1] =
        rover_sw_pwrtrain_24b_B.y;
    }

    /* End of MATLAB Function: '<S7>/MATLAB Function1' */
  }

  /* Integrator: '<S24>/Integrator' */
  rover_sw_pwrtrain_24b_B.Integrator[0] =
    rover_sw_pwrtrain_24b_X.Integrator_CSTATE[0];
  rover_sw_pwrtrain_24b_B.Integrator[1] =
    rover_sw_pwrtrain_24b_X.Integrator_CSTATE[1];
  rover_sw_pwrtrain_24b_B.Integrator[2] =
    rover_sw_pwrtrain_24b_X.Integrator_CSTATE[2];
  if (tmp) {
    /* MATLABSystem: '<S6>/Pure Pursuit' */
    if (rover_sw_pwrtrain_24b_DW.obj.DesiredLinearVelocity != 0.5) {
      rover_sw_pwrtrain_24b_DW.obj.DesiredLinearVelocity = 0.5;
    }

    if (rover_sw_pwrtrain_24b_DW.obj.MaxAngularVelocity != 1.0) {
      rover_sw_pwrtrain_24b_DW.obj.MaxAngularVelocity = 1.0;
    }

    if (rover_sw_pwrtrain_24b_DW.obj.LookaheadDistance != 0.1) {
      rover_sw_pwrtrain_24b_DW.obj.LookaheadDistance = 0.1;
    }

    if (!rover_sw_pwrtrain_24b_DW.obj.CacheInputSizes) {
      rover_sw_pwrtrain_24b_DW.obj.CacheInputSizes = true;
      for (i = 0; i < 8; i++) {
        rover_sw_pwrtrain_24b_DW.obj.inputVarSize[0].f1[i] = 1U;
      }

      i = rover_sw_pwrtrain_24b_DW.SFunction_DIMS2[0];
      if (rover_sw_pwrtrain_24b_DW.SFunction_DIMS2[0] < 0) {
        i = 0;
      }

      rover_sw_pwrtrain_24b_DW.obj.inputVarSize[1].f1[0] = static_cast<uint32_T>
        (i);
      i = rover_sw_pwrtrain_24b_DW.SFunction_DIMS2[1];
      if (rover_sw_pwrtrain_24b_DW.SFunction_DIMS2[1] < 0) {
        i = 0;
      }

      rover_sw_pwrtrain_24b_DW.obj.inputVarSize[1].f1[1] = static_cast<uint32_T>
        (i);
      for (i = 0; i < 6; i++) {
        rover_sw_pwrtrain_24b_DW.obj.inputVarSize[1].f1[i + 2] = 1U;
      }
    }

    /* Start for MATLABSystem: '<S6>/Pure Pursuit' */
    i = rover_sw_pwrtrain_24b_DW.SFunction_DIMS2[0];
    if (rover_sw_pwrtrain_24b_DW.SFunction_DIMS2[0] < 0) {
      i = 0;
    }

    /* MATLABSystem: '<S6>/Pure Pursuit' */
    rover_sw_pwrtrain_24b_B.inSize[0] = static_cast<uint32_T>(i);

    /* Start for MATLABSystem: '<S6>/Pure Pursuit' */
    i = rover_sw_pwrtrain_24b_DW.SFunction_DIMS2[1];
    if (rover_sw_pwrtrain_24b_DW.SFunction_DIMS2[1] < 0) {
      i = 0;
    }

    /* MATLABSystem: '<S6>/Pure Pursuit' */
    rover_sw_pwrtrain_24b_B.inSize[1] = static_cast<uint32_T>(i);
    for (i = 0; i < 6; i++) {
      rover_sw_pwrtrain_24b_B.inSize[i + 2] = 1U;
    }

    ret = 0;
    exitg1 = false;
    while ((!exitg1) && (ret < 8)) {
      if (rover_sw_pwrtrain_24b_DW.obj.inputVarSize[1].f1[ret] !=
          rover_sw_pwrtrain_24b_B.inSize[ret]) {
        for (i = 0; i < 8; i++) {
          rover_sw_pwrtrain_24b_DW.obj.inputVarSize[1].f1[i] =
            rover_sw_pwrtrain_24b_B.inSize[i];
        }

        exitg1 = true;
      } else {
        ret++;
      }
    }

    for (i = 0; i < 20000; i++) {
      rover_sw_pwrtrain_24b_B.paddedWaypts[i] = (rtNaN);
    }

    tmp_0 = rover_sw_pwrtrain_24b_DW.SFunction_DIMS2[0];
    ret = rover_sw_pwrtrain_24b_DW.SFunction_DIMS2[0];
    for (i = 0; i < 2; i++) {
      for (rover_sw_pwrtrain_24b_B.targetX = 0; rover_sw_pwrtrain_24b_B.targetX <
           ret; rover_sw_pwrtrain_24b_B.targetX++) {
        rover_sw_pwrtrain_24b_B.paddedWaypts[rover_sw_pwrtrain_24b_B.targetX +
          10000 * i] = rover_sw_pwrtrain_24b_B.waypoints_m[tmp_0 * i +
          rover_sw_pwrtrain_24b_B.targetX];
      }
    }

    forwardUp = false;
    p = true;
    ret = 0;
    exitg1 = false;
    while ((!exitg1) && (ret < 20000)) {
      if ((rover_sw_pwrtrain_24b_DW.obj.WaypointsInternal[ret] ==
           rover_sw_pwrtrain_24b_B.paddedWaypts[ret]) || (rtIsNaN
           (rover_sw_pwrtrain_24b_DW.obj.WaypointsInternal[ret]) && rtIsNaN
           (rover_sw_pwrtrain_24b_B.paddedWaypts[ret]))) {
        ret++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (p) {
      forwardUp = true;
    }

    if (!forwardUp) {
      memcpy(&rover_sw_pwrtrain_24b_DW.obj.WaypointsInternal[0],
             &rover_sw_pwrtrain_24b_B.paddedWaypts[0], 20000U * sizeof(real_T));
      rover_sw_pwrtrain_24b_DW.obj.ProjectionLineIndex = 0.0;
    }

    ret = rover_sw_pwrtrain_24b_DW.SFunction_DIMS2[0];
    rover_sw_pwrtrain_24b_B.targetX = 0;
    for (i = 0; i < ret; i++) {
      rover_sw_pwrtrain_24b_B.targetX++;
    }

    tmp_0 = rover_sw_pwrtrain_24b_B.targetX;
    rover_sw_pwrtrain_24b_B.targetX = 0;
    for (i = 0; i < ret; i++) {
      /* MATLABSystem: '<S6>/Pure Pursuit' */
      rover_sw_pwrtrain_24b_B.tmp_data[rover_sw_pwrtrain_24b_B.targetX] =
        static_cast<int16_T>(i);
      rover_sw_pwrtrain_24b_B.targetX++;
    }

    /* MATLABSystem: '<S6>/Pure Pursuit' incorporates:
     *  ZeroOrderHold: '<S6>/Zero-Order Hold2'
     */
    ret = rover_sw_pwrtrain_24b_DW.SFunction_DIMS2[1];
    rover_sw_pwrtrain_24b_B.waypoints.set_size(tmp_0,
      rover_sw_pwrtrain_24b_DW.SFunction_DIMS2[1]);
    for (i = 0; i < ret; i++) {
      for (rover_sw_pwrtrain_24b_B.targetX = 0; rover_sw_pwrtrain_24b_B.targetX <
           tmp_0; rover_sw_pwrtrain_24b_B.targetX++) {
        rover_sw_pwrtrain_24b_B.waypoints[rover_sw_pwrtrain_24b_B.targetX +
          rover_sw_pwrtrain_24b_B.waypoints.size(0) * i] =
          rover_sw_pwrtrain_24b_B.waypoints_m[rover_sw_pwrtrain_24b_DW.SFunction_DIMS2
          [0] * i +
          rover_sw_pwrtrain_24b_B.tmp_data[rover_sw_pwrtrain_24b_B.targetX]];
      }
    }

    if ((tmp_0 == 0) || (rover_sw_pwrtrain_24b_DW.SFunction_DIMS2[1] == 0)) {
      /* Product: '<S25>/Product' */
      rover_sw_pwrtrain_24b_B.Product = 0.0;
      rover_sw_pwrtrain_24b_B.Product1 = 0.0;
    } else {
      forwardUp = false;
      if (rover_sw_pwrtrain_24b_DW.obj.ProjectionLineIndex == 0.0) {
        forwardUp = true;
        rover_sw_pwrtrain_24b_DW.obj.ProjectionPoint[0] =
          rover_sw_pwrtrain_24b_B.waypoints_m[rover_sw_pwrtrain_24b_B.tmp_data[0]];
        rover_sw_pwrtrain_24b_DW.obj.ProjectionPoint[1] =
          rover_sw_pwrtrain_24b_B.waypoints_m[rover_sw_pwrtrain_24b_B.tmp_data[0]
          + rover_sw_pwrtrain_24b_DW.SFunction_DIMS2[0]];
        rover_sw_pwrtrain_24b_DW.obj.ProjectionLineIndex = 1.0;
      }

      if (tmp_0 == 1) {
        rover_sw_pwrtrain_24b_B.x =
          rover_sw_pwrtrain_24b_B.waypoints_m[rover_sw_pwrtrain_24b_B.tmp_data[0]];
        rover_sw_pwrtrain_24b_DW.obj.ProjectionPoint[0] =
          rover_sw_pwrtrain_24b_B.x;
        rover_sw_pwrtrain_24b_B.y =
          rover_sw_pwrtrain_24b_B.waypoints_m[rover_sw_pwrtrain_24b_B.tmp_data[0]
          + rover_sw_pwrtrain_24b_DW.SFunction_DIMS2[0]];
        rover_sw_pwrtrain_24b_DW.obj.ProjectionPoint[1] =
          rover_sw_pwrtrain_24b_B.y;
        rover_sw_pwrtrain_24b_DW.obj.LookaheadPoint[0] =
          rover_sw_pwrtrain_24b_B.x;
        rover_sw_pwrtrain_24b_DW.obj.LookaheadPoint[1] =
          rover_sw_pwrtrain_24b_B.y;
      } else {
        rover_sw_pwrtrain_24b_B.lookaheadStartPt[0] =
          rover_sw_pwrtrain_24b_B.waypoints_m[rover_sw_pwrtrain_24b_B.tmp_data[
          static_cast<int32_T>(rover_sw_pwrtrain_24b_DW.obj.ProjectionLineIndex
          + 1.0) - 1]];
        rover_sw_pwrtrain_24b_B.lookaheadStartPt[1] =
          rover_sw_pwrtrain_24b_B.waypoints_m[rover_sw_pwrtrain_24b_B.tmp_data[
          static_cast<int32_T>(rover_sw_pwrtrain_24b_DW.obj.ProjectionLineIndex
          + 1.0) - 1] + rover_sw_pwrtrain_24b_DW.SFunction_DIMS2[0]];
        rover_sw_pwrtrain_24b_B.y = rover_sw_pwr_closestPointOnLine
          (rover_sw_pwrtrain_24b_DW.obj.ProjectionPoint,
           rover_sw_pwrtrain_24b_B.lookaheadStartPt,
           &rover_sw_pwrtrain_24b_B.Integrator[0]);
        rover_sw_pwrtrain_24b_DW.obj.ProjectionPoint[0] =
          rover_sw_pwrtrain_24b_B.lookaheadStartPt[0];
        rover_sw_pwrtrain_24b_B.waypoints_l[0] =
          rover_sw_pwrtrain_24b_B.lookaheadStartPt[0] -
          rover_sw_pwrtrain_24b_B.waypoints_m[rover_sw_pwrtrain_24b_B.tmp_data[
          static_cast<int32_T>(rover_sw_pwrtrain_24b_DW.obj.ProjectionLineIndex
          + 1.0) - 1]];
        rover_sw_pwrtrain_24b_DW.obj.ProjectionPoint[1] =
          rover_sw_pwrtrain_24b_B.lookaheadStartPt[1];
        rover_sw_pwrtrain_24b_B.waypoints_l[1] =
          rover_sw_pwrtrain_24b_B.lookaheadStartPt[1] -
          rover_sw_pwrtrain_24b_B.waypoints_m[rover_sw_pwrtrain_24b_B.tmp_data[
          static_cast<int32_T>(rover_sw_pwrtrain_24b_DW.obj.ProjectionLineIndex
          + 1.0) - 1] + rover_sw_pwrtrain_24b_DW.SFunction_DIMS2[0]];
        rover_sw_pwrtrain_24b_B.x = rover_sw_pwrtrain_24b_norm
          (rover_sw_pwrtrain_24b_B.waypoints_l);
        rover_sw_pwrtrain_24b_B.overshootDist =
          rover_sw_pwrtrain_24b_DW.obj.ProjectionLineIndex + 1.0;
        ret = static_cast<int32_T>((1.0 -
          (rover_sw_pwrtrain_24b_DW.obj.ProjectionLineIndex + 1.0)) + (
          static_cast<real_T>(tmp_0) - 1.0)) - 1;
        i = 0;
        exitg1 = false;
        while ((!exitg1) && (i <= ret)) {
          rover_sw_pwrtrain_24b_B.i = rover_sw_pwrtrain_24b_B.overshootDist +
            static_cast<real_T>(i);
          if ((!forwardUp) && (rover_sw_pwrtrain_24b_B.x >
                               rover_sw_pwrtrain_24b_DW.obj.LookaheadDistance))
          {
            exitg1 = true;
          } else {
            rover_sw_pwrtrain_24b_B.waypoints_tmp =
              rover_sw_pwrtrain_24b_B.waypoints[static_cast<int32_T>
              (rover_sw_pwrtrain_24b_B.i + 1.0) - 1];
            rover_sw_pwrtrain_24b_B.waypoints_tmp_d =
              rover_sw_pwrtrain_24b_B.waypoints[static_cast<int32_T>
              (rover_sw_pwrtrain_24b_B.i) - 1];
            rover_sw_pwrtrain_24b_B.waypoints_l[0] =
              rover_sw_pwrtrain_24b_B.waypoints_tmp_d -
              rover_sw_pwrtrain_24b_B.waypoints_tmp;
            rover_sw_pwrtrain_24b_B.lookaheadStartPt[0] =
              rover_sw_pwrtrain_24b_B.waypoints_tmp;
            rover_sw_pwrtrain_24b_B.waypoints_j[0] =
              rover_sw_pwrtrain_24b_B.waypoints_tmp_d;
            rover_sw_pwrtrain_24b_B.waypoints_tmp =
              rover_sw_pwrtrain_24b_B.waypoints[(static_cast<int32_T>
              (rover_sw_pwrtrain_24b_B.i + 1.0) +
              rover_sw_pwrtrain_24b_B.waypoints.size(0)) - 1];
            rover_sw_pwrtrain_24b_B.waypoints_tmp_d =
              rover_sw_pwrtrain_24b_B.waypoints[(static_cast<int32_T>
              (rover_sw_pwrtrain_24b_B.i) +
              rover_sw_pwrtrain_24b_B.waypoints.size(0)) - 1];
            rover_sw_pwrtrain_24b_B.waypoints_l[1] =
              rover_sw_pwrtrain_24b_B.waypoints_tmp_d -
              rover_sw_pwrtrain_24b_B.waypoints_tmp;
            rover_sw_pwrtrain_24b_B.lookaheadStartPt[1] =
              rover_sw_pwrtrain_24b_B.waypoints_tmp;
            rover_sw_pwrtrain_24b_B.waypoints_j[1] =
              rover_sw_pwrtrain_24b_B.waypoints_tmp_d;
            rover_sw_pwrtrain_24b_B.x += rover_sw_pwrtrain_24b_norm
              (rover_sw_pwrtrain_24b_B.waypoints_l);
            rover_sw_pwrtrain_24b_B.waypoints_tmp =
              rover_sw_pwr_closestPointOnLine
              (rover_sw_pwrtrain_24b_B.waypoints_j,
               rover_sw_pwrtrain_24b_B.lookaheadStartPt,
               &rover_sw_pwrtrain_24b_B.Integrator[0]);
            if (rover_sw_pwrtrain_24b_B.waypoints_tmp <
                rover_sw_pwrtrain_24b_B.y) {
              rover_sw_pwrtrain_24b_B.y = rover_sw_pwrtrain_24b_B.waypoints_tmp;
              rover_sw_pwrtrain_24b_DW.obj.ProjectionPoint[0] =
                rover_sw_pwrtrain_24b_B.lookaheadStartPt[0];
              rover_sw_pwrtrain_24b_DW.obj.ProjectionPoint[1] =
                rover_sw_pwrtrain_24b_B.lookaheadStartPt[1];
              rover_sw_pwrtrain_24b_DW.obj.ProjectionLineIndex =
                rover_sw_pwrtrain_24b_B.i;
            }

            i++;
          }
        }

        rover_sw_pwrtrain_24b_B.waypoints_l[0] =
          rover_sw_pwrtrain_24b_DW.obj.ProjectionPoint[0] -
          rover_sw_pwrtrain_24b_B.waypoints_m[rover_sw_pwrtrain_24b_B.tmp_data[
          static_cast<int32_T>(rover_sw_pwrtrain_24b_DW.obj.ProjectionLineIndex
          + 1.0) - 1]];
        rover_sw_pwrtrain_24b_B.waypoints_l[1] =
          rover_sw_pwrtrain_24b_DW.obj.ProjectionPoint[1] -
          rover_sw_pwrtrain_24b_B.waypoints_m[rover_sw_pwrtrain_24b_B.tmp_data[
          static_cast<int32_T>(rover_sw_pwrtrain_24b_DW.obj.ProjectionLineIndex
          + 1.0) - 1] + rover_sw_pwrtrain_24b_DW.SFunction_DIMS2[0]];
        rover_sw_pwrtrain_24b_B.x = rover_sw_pwrtrain_24b_norm
          (rover_sw_pwrtrain_24b_B.waypoints_l);
        rover_sw_pwrtrain_24b_B.lookaheadStartPt[0] =
          rover_sw_pwrtrain_24b_DW.obj.ProjectionPoint[0];
        rover_sw_pwrtrain_24b_DW.obj.LookaheadPoint[0] =
          rover_sw_pwrtrain_24b_B.waypoints_m[rover_sw_pwrtrain_24b_B.tmp_data[
          static_cast<int32_T>(rover_sw_pwrtrain_24b_DW.obj.ProjectionLineIndex
          + 1.0) - 1]];
        rover_sw_pwrtrain_24b_B.lookaheadStartPt[1] =
          rover_sw_pwrtrain_24b_DW.obj.ProjectionPoint[1];
        rover_sw_pwrtrain_24b_DW.obj.LookaheadPoint[1] =
          rover_sw_pwrtrain_24b_B.waypoints_m[rover_sw_pwrtrain_24b_B.tmp_data[
          static_cast<int32_T>(rover_sw_pwrtrain_24b_DW.obj.ProjectionLineIndex
          + 1.0) - 1] + rover_sw_pwrtrain_24b_DW.SFunction_DIMS2[0]];
        rover_sw_pwrtrain_24b_B.overshootDist = rover_sw_pwrtrain_24b_B.x -
          rover_sw_pwrtrain_24b_DW.obj.LookaheadDistance;
        rover_sw_pwrtrain_24b_B.y =
          rover_sw_pwrtrain_24b_DW.obj.ProjectionLineIndex;
        while ((rover_sw_pwrtrain_24b_B.overshootDist < 0.0) &&
               (rover_sw_pwrtrain_24b_B.y < static_cast<real_T>(tmp_0) - 1.0)) {
          rover_sw_pwrtrain_24b_B.y++;
          rover_sw_pwrtrain_24b_B.overshootDist =
            rover_sw_pwrtrain_24b_B.waypoints[static_cast<int32_T>
            (rover_sw_pwrtrain_24b_B.y) - 1];
          rover_sw_pwrtrain_24b_B.lookaheadStartPt[0] =
            rover_sw_pwrtrain_24b_B.overshootDist;
          rover_sw_pwrtrain_24b_B.i = rover_sw_pwrtrain_24b_B.waypoints[
            static_cast<int32_T>(rover_sw_pwrtrain_24b_B.y + 1.0) - 1];
          rover_sw_pwrtrain_24b_DW.obj.LookaheadPoint[0] =
            rover_sw_pwrtrain_24b_B.i;
          rover_sw_pwrtrain_24b_B.waypoints_l[0] =
            rover_sw_pwrtrain_24b_B.overshootDist - rover_sw_pwrtrain_24b_B.i;
          rover_sw_pwrtrain_24b_B.overshootDist =
            rover_sw_pwrtrain_24b_B.waypoints[(static_cast<int32_T>
            (rover_sw_pwrtrain_24b_B.y) + rover_sw_pwrtrain_24b_B.waypoints.size
            (0)) - 1];
          rover_sw_pwrtrain_24b_B.lookaheadStartPt[1] =
            rover_sw_pwrtrain_24b_B.overshootDist;
          rover_sw_pwrtrain_24b_B.i = rover_sw_pwrtrain_24b_B.waypoints[(
            static_cast<int32_T>(rover_sw_pwrtrain_24b_B.y + 1.0) +
            rover_sw_pwrtrain_24b_B.waypoints.size(0)) - 1];
          rover_sw_pwrtrain_24b_DW.obj.LookaheadPoint[1] =
            rover_sw_pwrtrain_24b_B.i;
          rover_sw_pwrtrain_24b_B.waypoints_l[1] =
            rover_sw_pwrtrain_24b_B.overshootDist - rover_sw_pwrtrain_24b_B.i;
          rover_sw_pwrtrain_24b_B.x += rover_sw_pwrtrain_24b_norm
            (rover_sw_pwrtrain_24b_B.waypoints_l);
          rover_sw_pwrtrain_24b_B.overshootDist = rover_sw_pwrtrain_24b_B.x -
            rover_sw_pwrtrain_24b_DW.obj.LookaheadDistance;
        }

        rover_sw_pwrtrain_24b_B.waypoints_l[0] =
          rover_sw_pwrtrain_24b_B.lookaheadStartPt[0] -
          rover_sw_pwrtrain_24b_DW.obj.LookaheadPoint[0];
        rover_sw_pwrtrain_24b_B.waypoints_l[1] =
          rover_sw_pwrtrain_24b_B.lookaheadStartPt[1] -
          rover_sw_pwrtrain_24b_DW.obj.LookaheadPoint[1];
        rover_sw_pwrtrain_24b_B.x = rover_sw_pwrtrain_24b_B.overshootDist /
          rover_sw_pwrtrain_24b_norm(rover_sw_pwrtrain_24b_B.waypoints_l);
        if (rover_sw_pwrtrain_24b_B.x > 0.0) {
          rover_sw_pwrtrain_24b_DW.obj.LookaheadPoint[0] = (1.0 -
            rover_sw_pwrtrain_24b_B.x) *
            rover_sw_pwrtrain_24b_DW.obj.LookaheadPoint[0] +
            rover_sw_pwrtrain_24b_B.x *
            rover_sw_pwrtrain_24b_B.lookaheadStartPt[0];
          rover_sw_pwrtrain_24b_DW.obj.LookaheadPoint[1] = (1.0 -
            rover_sw_pwrtrain_24b_B.x) *
            rover_sw_pwrtrain_24b_DW.obj.LookaheadPoint[1] +
            rover_sw_pwrtrain_24b_B.x *
            rover_sw_pwrtrain_24b_B.lookaheadStartPt[1];
        }
      }

      rover_sw_pwrtrain_24b_B.x = rt_atan2d_snf
        (rover_sw_pwrtrain_24b_DW.obj.LookaheadPoint[1] -
         rover_sw_pwrtrain_24b_B.Integrator[1],
         rover_sw_pwrtrain_24b_DW.obj.LookaheadPoint[0] -
         rover_sw_pwrtrain_24b_B.Integrator[0]) -
        rover_sw_pwrtrain_24b_B.Integrator[2];
      if (fabs(rover_sw_pwrtrain_24b_B.x) > 3.1415926535897931) {
        if (rtIsNaN(rover_sw_pwrtrain_24b_B.x + 3.1415926535897931) || rtIsInf
            (rover_sw_pwrtrain_24b_B.x + 3.1415926535897931)) {
          rover_sw_pwrtrain_24b_B.y = (rtNaN);
        } else if (rover_sw_pwrtrain_24b_B.x + 3.1415926535897931 == 0.0) {
          rover_sw_pwrtrain_24b_B.y = 0.0;
        } else {
          rover_sw_pwrtrain_24b_B.y = fmod(rover_sw_pwrtrain_24b_B.x +
            3.1415926535897931, 6.2831853071795862);
          forwardUp = (rover_sw_pwrtrain_24b_B.y == 0.0);
          if (!forwardUp) {
            rover_sw_pwrtrain_24b_B.overshootDist = fabs
              ((rover_sw_pwrtrain_24b_B.x + 3.1415926535897931) /
               6.2831853071795862);
            forwardUp = !(fabs(rover_sw_pwrtrain_24b_B.overshootDist - floor
                               (rover_sw_pwrtrain_24b_B.overshootDist + 0.5)) >
                          2.2204460492503131E-16 *
                          rover_sw_pwrtrain_24b_B.overshootDist);
          }

          if (forwardUp) {
            rover_sw_pwrtrain_24b_B.y = 0.0;
          } else if (rover_sw_pwrtrain_24b_B.y < 0.0) {
            rover_sw_pwrtrain_24b_B.y += 6.2831853071795862;
          }
        }

        if ((rover_sw_pwrtrain_24b_B.y == 0.0) && (rover_sw_pwrtrain_24b_B.x +
             3.1415926535897931 > 0.0)) {
          rover_sw_pwrtrain_24b_B.y = 6.2831853071795862;
        }

        rover_sw_pwrtrain_24b_B.x = rover_sw_pwrtrain_24b_B.y -
          3.1415926535897931;
      }

      rover_sw_pwrtrain_24b_B.Product1 = 2.0 * sin(rover_sw_pwrtrain_24b_B.x) /
        rover_sw_pwrtrain_24b_DW.obj.LookaheadDistance;
      if (rtIsNaN(rover_sw_pwrtrain_24b_B.Product1)) {
        rover_sw_pwrtrain_24b_B.Product1 = 0.0;
      }

      if (fabs(fabs(rover_sw_pwrtrain_24b_B.x) - 3.1415926535897931) <
          1.4901161193847656E-8) {
        if (rtIsNaN(rover_sw_pwrtrain_24b_B.Product1)) {
          rover_sw_pwrtrain_24b_B.Product1 = (rtNaN);
        } else if (rover_sw_pwrtrain_24b_B.Product1 < 0.0) {
          rover_sw_pwrtrain_24b_B.Product1 = -1.0;
        } else {
          rover_sw_pwrtrain_24b_B.Product1 = (rover_sw_pwrtrain_24b_B.Product1 >
            0.0);
        }
      }

      if (fabs(rover_sw_pwrtrain_24b_B.Product1) >
          rover_sw_pwrtrain_24b_DW.obj.MaxAngularVelocity) {
        if (rtIsNaN(rover_sw_pwrtrain_24b_B.Product1)) {
          rover_sw_pwrtrain_24b_B.x = (rtNaN);
        } else if (rover_sw_pwrtrain_24b_B.Product1 < 0.0) {
          rover_sw_pwrtrain_24b_B.x = -1.0;
        } else {
          rover_sw_pwrtrain_24b_B.x = (rover_sw_pwrtrain_24b_B.Product1 > 0.0);
        }

        rover_sw_pwrtrain_24b_B.Product1 = rover_sw_pwrtrain_24b_B.x *
          rover_sw_pwrtrain_24b_DW.obj.MaxAngularVelocity;
      }

      /* Product: '<S25>/Product' incorporates:
       *  ZeroOrderHold: '<S6>/Zero-Order Hold2'
       */
      rover_sw_pwrtrain_24b_B.Product =
        rover_sw_pwrtrain_24b_DW.obj.DesiredLinearVelocity;
      rover_sw_pwrtrain_24b_DW.obj.LastPose[0] =
        rover_sw_pwrtrain_24b_B.Integrator[0];
      rover_sw_pwrtrain_24b_DW.obj.LastPose[1] =
        rover_sw_pwrtrain_24b_B.Integrator[1];
      rover_sw_pwrtrain_24b_DW.obj.LastPose[2] =
        rover_sw_pwrtrain_24b_B.Integrator[2];
    }

    /* If: '<S5>/If' incorporates:
     *  Logic: '<S14>/OR'
     */
    if (rtsiIsModeUpdateTimeStep(&(&rover_sw_pwrtrain_24b_M)->solverInfo)) {
      rtAction = static_cast<int8_T>
        (rover_sw_pwrtrain_24b_B.EnabledSubsystem_g.In1.data);
      rover_sw_pwrtrain_24b_DW.If_ActiveSubsystem = static_cast<int8_T>
        (rover_sw_pwrtrain_24b_B.EnabledSubsystem_g.In1.data);
    } else {
      rtAction = rover_sw_pwrtrain_24b_DW.If_ActiveSubsystem;
    }

    if (rtAction == 0) {
      /* Outputs for IfAction SubSystem: '<S5>/Subsystem1' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */
      /* Outputs for Enabled SubSystem: '<S14>/vesc_comm' incorporates:
       *  EnablePort: '<S23>/Enable'
       */
      if (rover_sw_pwrtrain_24b_B.SourceBlock_o1_mk ||
          rover_sw_pwrtrain_24b_B.SourceBlock_o1_nc) {
        /* Sum: '<S23>/Plus' incorporates:
         *  Product: '<S23>/Product'
         */
        rtb_RateLimiter1 = rover_sw_pwrtrain_24b_B.EnabledSubsystem.In1.data *
          rover_sw_pwrtrain_24b_B.EnabledSubsystem_o.In1.data +
          rover_sw_pwrtrain_24b_B.EnabledSubsystem.In1.data;

        /* RateLimiter: '<S23>/Rate Limiter' */
        rateLimiterRate = rtb_RateLimiter1 - rover_sw_pwrtrain_24b_DW.PrevY;
        if (rateLimiterRate > 0.002F) {
          rtb_RateLimiter1 = rover_sw_pwrtrain_24b_DW.PrevY + 0.002F;
        } else if (rateLimiterRate < -0.012F) {
          rtb_RateLimiter1 = rover_sw_pwrtrain_24b_DW.PrevY - 0.012F;
        }

        rover_sw_pwrtrain_24b_DW.PrevY = rtb_RateLimiter1;

        /* End of RateLimiter: '<S23>/Rate Limiter' */

        /* CCaller: '<S23>/vesc_send_duty_left' incorporates:
         *  DataTypeConversion: '<S23>/Data Type Conversion'
         */
        rover_sw_pwrtrain_24b_B.vesc_send_duty_left = vesc_send_duty_left(
          static_cast<real_T>(rtb_RateLimiter1));

        /* Sum: '<S23>/Plus2' incorporates:
         *  Product: '<S23>/Product1'
         */
        rtb_RateLimiter1 = rover_sw_pwrtrain_24b_B.EnabledSubsystem.In1.data -
          rover_sw_pwrtrain_24b_B.EnabledSubsystem.In1.data *
          rover_sw_pwrtrain_24b_B.EnabledSubsystem_o.In1.data;

        /* RateLimiter: '<S23>/Rate Limiter1' */
        rateLimiterRate = rtb_RateLimiter1 - rover_sw_pwrtrain_24b_DW.PrevY_l;
        if (rateLimiterRate > 0.002F) {
          rtb_RateLimiter1 = rover_sw_pwrtrain_24b_DW.PrevY_l + 0.002F;
        } else if (rateLimiterRate < -0.012F) {
          rtb_RateLimiter1 = rover_sw_pwrtrain_24b_DW.PrevY_l - 0.012F;
        }

        rover_sw_pwrtrain_24b_DW.PrevY_l = rtb_RateLimiter1;

        /* End of RateLimiter: '<S23>/Rate Limiter1' */

        /* CCaller: '<S23>/vesc_send_duty_right' incorporates:
         *  DataTypeConversion: '<S23>/Data Type Conversion2'
         */
        rover_sw_pwrtrain_24b_B.vesc_send_duty_right = vesc_send_duty_right(
          static_cast<real_T>(rtb_RateLimiter1));
      }

      /* End of Outputs for SubSystem: '<S14>/vesc_comm' */

      /* BusAssignment: '<S14>/Bus Assignment1' incorporates:
       *  Logic: '<S14>/OR'
       */
      rtb_BusAssignment1.data = rover_sw_pwrtrain_24b_B.vesc_send_duty_left;

      /* MATLABSystem: '<S21>/SinkBlock' */
      Pub_rover_sw_pwrtrain_24b_138.publish(&rtb_BusAssignment1);

      /* BusAssignment: '<S14>/Bus Assignment2' */
      rtb_BusAssignment2.data = rover_sw_pwrtrain_24b_B.vesc_send_duty_right;

      /* MATLABSystem: '<S22>/SinkBlock' */
      Pub_rover_sw_pwrtrain_24b_139.publish(&rtb_BusAssignment2);

      /* End of Outputs for SubSystem: '<S5>/Subsystem1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S5>/Subsystem' incorporates:
       *  ActionPort: '<S13>/Action Port'
       */
      /* BusAssignment: '<S13>/Bus Assignment1' incorporates:
       *  CCaller: '<S13>/vesc_send_duty_left'
       *  Constant: '<S13>/Constant'
       *  Constant: '<S13>/Constant2'
       *  Constant: '<S13>/Constant4'
       *  Constant: '<S5>/half_trackwidth'
       *  Gain: '<S13>/Gain'
       *  Product: '<S13>/Divide'
       *  Product: '<S13>/Divide2'
       *  Product: '<S13>/Divide4'
       *  Product: '<S13>/Product'
       *  Sum: '<S13>/Subtract'
       */
      rtb_BusAssignment1.data = vesc_send_duty_left
        ((rover_sw_pwrtrain_24b_B.Product - rover_sw_pwrtrain_24b_B.Product1 *
          0.25) / 0.096 * 60.0 / 6.28 / 350.0);

      /* MATLABSystem: '<S17>/SinkBlock' */
      Pub_rover_sw_pwrtrain_24b_542.publish(&rtb_BusAssignment1);

      /* BusAssignment: '<S13>/Bus Assignment2' incorporates:
       *  CCaller: '<S13>/vesc_send_duty_right'
       *  Constant: '<S13>/Constant1'
       *  Constant: '<S13>/Constant3'
       *  Constant: '<S13>/Constant5'
       *  Constant: '<S5>/half_trackwidth'
       *  Gain: '<S13>/Gain1'
       *  Product: '<S13>/Divide1'
       *  Product: '<S13>/Divide3'
       *  Product: '<S13>/Divide5'
       *  Product: '<S13>/Product1'
       *  Sum: '<S13>/Subtract1'
       */
      rtb_BusAssignment2.data = vesc_send_duty_right
        ((rover_sw_pwrtrain_24b_B.Product1 * 0.25 +
          rover_sw_pwrtrain_24b_B.Product) / 0.096 * 60.0 / 6.28 / 350.0);

      /* MATLABSystem: '<S18>/SinkBlock' */
      Pub_rover_sw_pwrtrain_24b_543.publish(&rtb_BusAssignment2);

      /* End of Outputs for SubSystem: '<S5>/Subsystem' */
    }

    /* End of If: '<S5>/If' */

    /* Outputs for Atomic SubSystem: '<S4>/status_indicator_lamp' */
    /* Switch: '<S12>/Switch' incorporates:
     *  Logic: '<S12>/OR'
     */
    if ((rover_sw_pwrtrain_24b_B.EnabledSubsystem.In1.data != 0.0F) ||
        (rover_sw_pwrtrain_24b_B.EnabledSubsystem_o.In1.data != 0.0F)) {
      /* BusAssignment: '<S8>/Bus Assignment3' incorporates:
       *  Constant: '<S12>/Constant'
       *  DataTypeConversion: '<S12>/Data Type Conversion1'
       */
      rtb_BusAssignment3.data = 1300;
    } else {
      /* BusAssignment: '<S8>/Bus Assignment3' incorporates:
       *  Constant: '<S12>/Constant1'
       *  DataTypeConversion: '<S12>/Data Type Conversion1'
       */
      rtb_BusAssignment3.data = 1500;
    }

    /* End of Switch: '<S12>/Switch' */
    /* End of Outputs for SubSystem: '<S4>/status_indicator_lamp' */

    /* MATLABSystem: '<S33>/SinkBlock' */
    Pub_rover_sw_pwrtrain_24b_246.publish(&rtb_BusAssignment3);
  }

  /* MATLABSystem: '<S24>/MATLAB System' */
  if (rover_sw_pwrtrain_24b_DW.obj_j.TrackWidth != 0.5) {
    if (rover_sw_pwrtrain_24b_DW.obj_j.isInitialized == 1) {
      rover_sw_pwrtrain_24b_DW.obj_j.TunablePropsChanged = true;
      rover_sw_pwrtrain_24b_DW.obj_j.tunablePropertyChanged[0] = true;
    }

    rover_sw_pwrtrain_24b_DW.obj_j.TrackWidth = 0.5;
  }

  if (rover_sw_pwrtrain_24b_DW.obj_j.WheelRadius != 0.095) {
    if (rover_sw_pwrtrain_24b_DW.obj_j.isInitialized == 1) {
      rover_sw_pwrtrain_24b_DW.obj_j.TunablePropsChanged = true;
      rover_sw_pwrtrain_24b_DW.obj_j.tunablePropertyChanged[1] = true;
    }

    rover_sw_pwrtrain_24b_DW.obj_j.WheelRadius = 0.095;
  }

  forwardUp = false;
  p = true;
  ret = 0;
  exitg1 = false;
  while ((!exitg1) && (ret < 2)) {
    if (!(rover_sw_pwrtrain_24b_DW.obj_j.WheelSpeedRange[ret] ==
          rover_sw_pwrtrain_24_ConstInitP.MATLABSystem_WheelSpeedRange[ret])) {
      p = false;
      exitg1 = true;
    } else {
      ret++;
    }
  }

  if (p) {
    forwardUp = true;
  }

  if (!forwardUp) {
    if (rover_sw_pwrtrain_24b_DW.obj_j.isInitialized == 1) {
      rover_sw_pwrtrain_24b_DW.obj_j.TunablePropsChanged = true;
      rover_sw_pwrtrain_24b_DW.obj_j.tunablePropertyChanged[2] = true;
    }

    rover_sw_pwrtrain_24b_DW.obj_j.WheelSpeedRange[0] = (rtMinusInf);
    rover_sw_pwrtrain_24b_DW.obj_j.WheelSpeedRange[1] = (rtInf);
  }

  if (rover_sw_pwrtrain_24b_DW.obj_j.TunablePropsChanged) {
    rover_sw_pwrtrain_24b_DW.obj_j.TunablePropsChanged = false;
    if (rover_sw_pwrtrain_24b_DW.obj_j.tunablePropertyChanged[1]) {
      rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelRadius =
        rover_sw_pwrtrain_24b_DW.obj_j.WheelRadius;
    }

    if (rover_sw_pwrtrain_24b_DW.obj_j.tunablePropertyChanged[0]) {
      rover_sw_pwrtrain_24b_DW.obj_j.KinModel.TrackWidth =
        rover_sw_pwrtrain_24b_DW.obj_j.TrackWidth;
    }

    if (rover_sw_pwrtrain_24b_DW.obj_j.tunablePropertyChanged[2]) {
      rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelSpeedRange[0] =
        rover_sw_pwrtrain_24b_DW.obj_j.WheelSpeedRange[0];
      rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelSpeedRange[1] =
        rover_sw_pwrtrain_24b_DW.obj_j.WheelSpeedRange[1];
    }

    rover_sw_pwrtrain_24b_DW.obj_j.tunablePropertyChanged[0] = false;
    rover_sw_pwrtrain_24b_DW.obj_j.tunablePropertyChanged[1] = false;
    rover_sw_pwrtrain_24b_DW.obj_j.tunablePropertyChanged[2] = false;
  }

  rover_sw_pwrtrain_24b_B.x = 0.0;

  /* MATLABSystem: '<S24>/MATLAB System' */
  rover_sw_pwrtrain_24b_B.MATLABSystem[2] = 0.0;

  /* MATLABSystem: '<S24>/MATLAB System' */
  ret = std::memcmp(&a[0],
                    &rover_sw_pwrtrain_24b_DW.obj_j.KinModel.VehicleInputsInternal
                    [0], 23);
  if (ret == 0) {
    ret = 0;
  } else {
    ret = std::memcmp(&a_0[0],
                      &rover_sw_pwrtrain_24b_DW.obj_j.KinModel.VehicleInputsInternal
                      [0], 23);
    if (ret == 0) {
      ret = 1;
    } else {
      ret = -1;
    }
  }

  switch (ret) {
   case 0:
    if ((rover_sw_pwrtrain_24b_B.Product >=
         rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelSpeedRange[0]) || rtIsNaN
        (rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelSpeedRange[0])) {
      rover_sw_pwrtrain_24b_B.y = rover_sw_pwrtrain_24b_B.Product;
    } else {
      rover_sw_pwrtrain_24b_B.y =
        rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelSpeedRange[0];
    }

    forwardUp = !rtIsNaN
      (rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelSpeedRange[1]);
    if ((!(rover_sw_pwrtrain_24b_B.y <=
           rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelSpeedRange[1])) &&
        forwardUp) {
      rover_sw_pwrtrain_24b_B.y =
        rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelSpeedRange[1];
    }

    if ((rover_sw_pwrtrain_24b_B.Product1 >=
         rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelSpeedRange[0]) || rtIsNaN
        (rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelSpeedRange[0])) {
      rover_sw_pwrtrain_24b_B.overshootDist = rover_sw_pwrtrain_24b_B.Product1;
    } else {
      rover_sw_pwrtrain_24b_B.overshootDist =
        rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelSpeedRange[0];
    }

    if ((!(rover_sw_pwrtrain_24b_B.overshootDist <=
           rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelSpeedRange[1])) &&
        forwardUp) {
      rover_sw_pwrtrain_24b_B.overshootDist =
        rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelSpeedRange[1];
    }

    rover_sw_pwrtrain_24b_B.x = (rover_sw_pwrtrain_24b_B.overshootDist +
      rover_sw_pwrtrain_24b_B.y) *
      rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelRadius / 2.0;

    /* MATLABSystem: '<S24>/MATLAB System' */
    rover_sw_pwrtrain_24b_B.MATLABSystem[2] =
      (rover_sw_pwrtrain_24b_B.overshootDist - rover_sw_pwrtrain_24b_B.y) *
      rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelRadius /
      (rover_sw_pwrtrain_24b_DW.obj_j.KinModel.TrackWidth / 2.0 * 2.0);
    break;

   case 1:
    rover_sw_pwrtrain_24b_B.x =
      rover_sw_pwrtrain_24b_DW.obj_j.KinModel.TrackWidth / 2.0 *
      rover_sw_pwrtrain_24b_B.Product1;
    rover_sw_pwrtrain_24b_B.lookaheadStartPt[0] =
      (rover_sw_pwrtrain_24b_B.Product - rover_sw_pwrtrain_24b_B.x) /
      rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelRadius;
    rover_sw_pwrtrain_24b_B.lookaheadStartPt[1] = (rover_sw_pwrtrain_24b_B.x +
      rover_sw_pwrtrain_24b_B.Product) /
      rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelRadius;
    forwardUp = rtIsNaN(rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelSpeedRange
                        [0]);
    if ((rover_sw_pwrtrain_24b_B.lookaheadStartPt[0] >=
         rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelSpeedRange[0]) ||
        forwardUp) {
      rover_sw_pwrtrain_24b_B.y = rover_sw_pwrtrain_24b_B.lookaheadStartPt[0];
    } else {
      rover_sw_pwrtrain_24b_B.y =
        rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelSpeedRange[0];
    }

    p = !rtIsNaN(rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelSpeedRange[1]);
    if ((!(rover_sw_pwrtrain_24b_B.y <=
           rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelSpeedRange[1])) && p) {
      rover_sw_pwrtrain_24b_B.y =
        rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelSpeedRange[1];
    }

    if ((rover_sw_pwrtrain_24b_B.lookaheadStartPt[1] >=
         rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelSpeedRange[0]) ||
        forwardUp) {
      rover_sw_pwrtrain_24b_B.overshootDist =
        rover_sw_pwrtrain_24b_B.lookaheadStartPt[1];
    } else {
      rover_sw_pwrtrain_24b_B.overshootDist =
        rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelSpeedRange[0];
    }

    if ((!(rover_sw_pwrtrain_24b_B.overshootDist <=
           rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelSpeedRange[1])) && p) {
      rover_sw_pwrtrain_24b_B.overshootDist =
        rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelSpeedRange[1];
    }

    rover_sw_pwrtrain_24b_B.x = (rover_sw_pwrtrain_24b_B.overshootDist +
      rover_sw_pwrtrain_24b_B.y) *
      rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelRadius / 2.0;

    /* MATLABSystem: '<S24>/MATLAB System' */
    rover_sw_pwrtrain_24b_B.MATLABSystem[2] =
      (rover_sw_pwrtrain_24b_B.overshootDist - rover_sw_pwrtrain_24b_B.y) *
      rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelRadius /
      (rover_sw_pwrtrain_24b_DW.obj_j.KinModel.TrackWidth / 2.0 * 2.0);
    break;
  }

  /* MATLABSystem: '<S24>/MATLAB System' */
  rover_sw_pwrtrain_24b_B.MATLABSystem[0] = cos
    (rover_sw_pwrtrain_24b_B.Integrator[2]) * rover_sw_pwrtrain_24b_B.x;
  rover_sw_pwrtrain_24b_B.MATLABSystem[1] = sin
    (rover_sw_pwrtrain_24b_B.Integrator[2]) * rover_sw_pwrtrain_24b_B.x;
  if (tmp) {
    /* MATLABSystem: '<S37>/SourceBlock' */
    rover_sw_pwrtrain_24b_B.SourceBlock_o1_m =
      Sub_rover_sw_pwrtrain_24b_392.getLatestMessage(&rtb_SourceBlock_o2_l);

    /* Outputs for Enabled SubSystem: '<S37>/Enabled Subsystem' */
    rover_sw_pwrtr_EnabledSubsystem(rover_sw_pwrtrain_24b_B.SourceBlock_o1_m,
      &rtb_SourceBlock_o2_l, &rover_sw_pwrtrain_24b_B.EnabledSubsystem_p);

    /* End of Outputs for SubSystem: '<S37>/Enabled Subsystem' */

    /* MATLABSystem: '<S38>/SourceBlock' */
    rover_sw_pwrtrain_24b_B.SourceBlock_o1_l =
      Sub_rover_sw_pwrtrain_24b_466.getLatestMessage(&rtb_SourceBlock_o2);

    /* Outputs for Enabled SubSystem: '<S38>/Enabled Subsystem' */
    rover_sw_pwrtr_EnabledSubsystem(rover_sw_pwrtrain_24b_B.SourceBlock_o1_l,
      &rtb_SourceBlock_o2, &rover_sw_pwrtrain_24b_B.EnabledSubsystem_p4);

    /* End of Outputs for SubSystem: '<S38>/Enabled Subsystem' */

    /* MATLABSystem: '<S40>/SourceBlock' */
    rover_sw_pwrtrain_24b_B.SourceBlock_o1 =
      Sub_rover_sw_pwrtrain_24b_601.getLatestMessage(&rtb_SourceBlock_o2_p4);

    /* Outputs for Enabled SubSystem: '<S40>/Enabled Subsystem' */
    rover_sw_pwr_EnabledSubsystem_g(rover_sw_pwrtrain_24b_B.SourceBlock_o1,
      &rtb_SourceBlock_o2_p4, &rover_sw_pwrtrain_24b_B.EnabledSubsystem_b);

    /* End of Outputs for SubSystem: '<S40>/Enabled Subsystem' */
  }

  if (rtmIsMajorTimeStep((&rover_sw_pwrtrain_24b_M))) {
    rt_ertODEUpdateContinuousStates(&(&rover_sw_pwrtrain_24b_M)->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++(&rover_sw_pwrtrain_24b_M)->Timing.clockTick0)) {
      ++(&rover_sw_pwrtrain_24b_M)->Timing.clockTickH0;
    }

    (&rover_sw_pwrtrain_24b_M)->Timing.t[0] = rtsiGetSolverStopTime
      (&(&rover_sw_pwrtrain_24b_M)->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      (&rover_sw_pwrtrain_24b_M)->Timing.clockTick1++;
      if (!(&rover_sw_pwrtrain_24b_M)->Timing.clockTick1) {
        (&rover_sw_pwrtrain_24b_M)->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void rover_sw_pwrtrain_24b::rover_sw_pwrtrain_24b_derivatives()
{
  XDot_rover_sw_pwrtrain_24b_T *_rtXdot;
  _rtXdot = ((XDot_rover_sw_pwrtrain_24b_T *) (&rover_sw_pwrtrain_24b_M)->derivs);

  /* Derivatives for Integrator: '<S24>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = rover_sw_pwrtrain_24b_B.MATLABSystem[0];
  _rtXdot->Integrator_CSTATE[1] = rover_sw_pwrtrain_24b_B.MATLABSystem[1];
  _rtXdot->Integrator_CSTATE[2] = rover_sw_pwrtrain_24b_B.MATLABSystem[2];
}

/* Model initialize function */
void rover_sw_pwrtrain_24b::initialize()
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  rover_sw_pwrtrain_24_ConstInitP.MATLABSystem_WheelSpeedRange[0] = rtMinusInf;
  rover_sw_pwrtrain_24_ConstInitP.MATLABSystem_WheelSpeedRange[1] = rtInf;

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&(&rover_sw_pwrtrain_24b_M)->solverInfo,
                          &(&rover_sw_pwrtrain_24b_M)->Timing.simTimeStep);
    rtsiSetTPtr(&(&rover_sw_pwrtrain_24b_M)->solverInfo, &rtmGetTPtr
                ((&rover_sw_pwrtrain_24b_M)));
    rtsiSetStepSizePtr(&(&rover_sw_pwrtrain_24b_M)->solverInfo,
                       &(&rover_sw_pwrtrain_24b_M)->Timing.stepSize0);
    rtsiSetdXPtr(&(&rover_sw_pwrtrain_24b_M)->solverInfo,
                 &(&rover_sw_pwrtrain_24b_M)->derivs);
    rtsiSetContStatesPtr(&(&rover_sw_pwrtrain_24b_M)->solverInfo, (real_T **) &(
      &rover_sw_pwrtrain_24b_M)->contStates);
    rtsiSetNumContStatesPtr(&(&rover_sw_pwrtrain_24b_M)->solverInfo,
      &(&rover_sw_pwrtrain_24b_M)->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&(&rover_sw_pwrtrain_24b_M)->solverInfo,
      &(&rover_sw_pwrtrain_24b_M)->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&(&rover_sw_pwrtrain_24b_M)->solverInfo,
      &(&rover_sw_pwrtrain_24b_M)->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&(&rover_sw_pwrtrain_24b_M)->solverInfo,
      &(&rover_sw_pwrtrain_24b_M)->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&(&rover_sw_pwrtrain_24b_M)->solverInfo,
      (boolean_T**) &(&rover_sw_pwrtrain_24b_M)->contStateDisabled);
    rtsiSetErrorStatusPtr(&(&rover_sw_pwrtrain_24b_M)->solverInfo,
                          (&rtmGetErrorStatus((&rover_sw_pwrtrain_24b_M))));
    rtsiSetRTModelPtr(&(&rover_sw_pwrtrain_24b_M)->solverInfo,
                      (&rover_sw_pwrtrain_24b_M));
  }

  rtsiSetSimTimeStep(&(&rover_sw_pwrtrain_24b_M)->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&(&rover_sw_pwrtrain_24b_M)->solverInfo,
    false);
  rtsiSetIsContModeFrozen(&(&rover_sw_pwrtrain_24b_M)->solverInfo, false);
  (&rover_sw_pwrtrain_24b_M)->intgData.y = (&rover_sw_pwrtrain_24b_M)->odeY;
  (&rover_sw_pwrtrain_24b_M)->intgData.f[0] = (&rover_sw_pwrtrain_24b_M)->odeF[0];
  (&rover_sw_pwrtrain_24b_M)->intgData.f[1] = (&rover_sw_pwrtrain_24b_M)->odeF[1];
  (&rover_sw_pwrtrain_24b_M)->intgData.f[2] = (&rover_sw_pwrtrain_24b_M)->odeF[2];
  (&rover_sw_pwrtrain_24b_M)->contStates = ((X_rover_sw_pwrtrain_24b_T *)
    &rover_sw_pwrtrain_24b_X);
  (&rover_sw_pwrtrain_24b_M)->contStateDisabled = ((XDis_rover_sw_pwrtrain_24b_T
    *) &rover_sw_pwrtrain_24b_XDis);
  (&rover_sw_pwrtrain_24b_M)->Timing.tStart = (0.0);
  rtsiSetSolverData(&(&rover_sw_pwrtrain_24b_M)->solverInfo, static_cast<void *>
                    (&(&rover_sw_pwrtrain_24b_M)->intgData));
  rtsiSetSolverName(&(&rover_sw_pwrtrain_24b_M)->solverInfo,"ode3");
  rtmSetTPtr((&rover_sw_pwrtrain_24b_M), &(&rover_sw_pwrtrain_24b_M)
             ->Timing.tArray[0]);
  (&rover_sw_pwrtrain_24b_M)->Timing.stepSize0 = 0.01;

  {
    int32_T i;
    static const int16_T tmp[8] = { 10000, 2, 1, 1, 1, 1, 1, 1 };

    /* Start for MATLABSystem: '<S34>/SinkBlock' */
    rover_sw_pwrtrain_24b_DW.obj_m.QOSAvoidROSNamespaceConventions = false;
    rover_sw_pwrtrain_24b_DW.obj_m.matlabCodegenIsDeleted = false;
    rover_sw_pwrtrain_24b_DW.objisempty_n = true;
    rover_sw_pwrtrain_24b_DW.obj_m.isSetupComplete = false;
    rover_sw_pwrtrain_24b_DW.obj_m.isInitialized = 1;
    rov_Publisher_setupImpl_mygou5b(&rover_sw_pwrtrain_24b_DW.obj_m);
    rover_sw_pwrtrain_24b_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S31>/SinkBlock' */
    rover_sw_pwrtrain_24b_DW.obj_g4.QOSAvoidROSNamespaceConventions = false;
    rover_sw_pwrtrain_24b_DW.obj_g4.matlabCodegenIsDeleted = false;
    rover_sw_pwrtrain_24b_DW.objisempty_k1 = true;
    rover_sw_pwrtrain_24b_DW.obj_g4.isSetupComplete = false;
    rover_sw_pwrtrain_24b_DW.obj_g4.isInitialized = 1;
    rover__Publisher_setupImpl_mygo(&rover_sw_pwrtrain_24b_DW.obj_g4);
    rover_sw_pwrtrain_24b_DW.obj_g4.isSetupComplete = true;

    /* Start for MATLABSystem: '<S32>/SinkBlock' */
    rover_sw_pwrtrain_24b_DW.obj_f.QOSAvoidROSNamespaceConventions = false;
    rover_sw_pwrtrain_24b_DW.obj_f.matlabCodegenIsDeleted = false;
    rover_sw_pwrtrain_24b_DW.objisempty_ks = true;
    rover_sw_pwrtrain_24b_DW.obj_f.isSetupComplete = false;
    rover_sw_pwrtrain_24b_DW.obj_f.isInitialized = 1;
    rover_Publisher_setupImpl_mygou(&rover_sw_pwrtrain_24b_DW.obj_f);
    rover_sw_pwrtrain_24b_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S39>/SourceBlock' */
    rover_sw_pwrtrain_24b_DW.obj_mg.QOSAvoidROSNamespaceConventions = false;
    rover_sw_pwrtrain_24b_DW.obj_mg.matlabCodegenIsDeleted = false;
    rover_sw_pwrtrain_24b_DW.objisempty_l = true;
    rover_sw_pwrtrain_24b_DW.obj_mg.isSetupComplete = false;
    rover_sw_pwrtrain_24b_DW.obj_mg.isInitialized = 1;
    rover_Subscriber_setupImpl_mygo(&rover_sw_pwrtrain_24b_DW.obj_mg);
    rover_sw_pwrtrain_24b_DW.obj_mg.isSetupComplete = true;

    /* Start for MATLABSystem: '<S35>/SourceBlock' */
    rover_sw_pwrtrain_24b_DW.obj_i.QOSAvoidROSNamespaceConventions = false;
    rover_sw_pwrtrain_24b_DW.obj_i.matlabCodegenIsDeleted = false;
    rover_sw_pwrtrain_24b_DW.objisempty_c = true;
    rover_sw_pwrtrain_24b_DW.obj_i.isSetupComplete = false;
    rover_sw_pwrtrain_24b_DW.obj_i.isInitialized = 1;
    rover_sw_p_Subscriber_setupImpl(&rover_sw_pwrtrain_24b_DW.obj_i);
    rover_sw_pwrtrain_24b_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S36>/SourceBlock' */
    rover_sw_pwrtrain_24b_DW.obj_ng.QOSAvoidROSNamespaceConventions = false;
    rover_sw_pwrtrain_24b_DW.obj_ng.matlabCodegenIsDeleted = false;
    rover_sw_pwrtrain_24b_DW.objisempty_ea = true;
    rover_sw_pwrtrain_24b_DW.obj_ng.isSetupComplete = false;
    rover_sw_pwrtrain_24b_DW.obj_ng.isInitialized = 1;
    rover_sw_Subscriber_setupImpl_m(&rover_sw_pwrtrain_24b_DW.obj_ng);
    rover_sw_pwrtrain_24b_DW.obj_ng.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Pure Pursuit' */
    rover_sw_pwrtrain_24b_DW.obj.CacheInputSizes = false;
    rover_sw_pwrtrain_24b_DW.objisempty_ek = true;
    rover_sw_pwrtrain_24b_DW.obj.DesiredLinearVelocity = 0.5;
    rover_sw_pwrtrain_24b_DW.obj.MaxAngularVelocity = 1.0;
    rover_sw_pwrtrain_24b_DW.obj.LookaheadDistance = 0.1;
    rover_sw_pwrtrain_24b_DW.obj.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      rover_sw_pwrtrain_24b_DW.obj.inputVarSize[0].f1[i] = 1U;
      rover_sw_pwrtrain_24b_DW.obj.inputVarSize[1].f1[i] = static_cast<uint32_T>
        (tmp[i]);
    }

    for (i = 0; i < 20000; i++) {
      rover_sw_pwrtrain_24b_DW.obj.WaypointsInternal[i] = (rtNaN);
    }

    rover_sw_pwrtrain_24b_DW.obj.LookaheadPoint[0] = 0.0;
    rover_sw_pwrtrain_24b_DW.obj.LookaheadPoint[1] = 0.0;
    rover_sw_pwrtrain_24b_DW.obj.LastPose[0] = 0.0;
    rover_sw_pwrtrain_24b_DW.obj.LastPose[1] = 0.0;
    rover_sw_pwrtrain_24b_DW.obj.LastPose[2] = 0.0;
    rover_sw_pwrtrain_24b_DW.obj.ProjectionPoint[0] = (rtNaN);
    rover_sw_pwrtrain_24b_DW.obj.ProjectionPoint[1] = (rtNaN);
    rover_sw_pwrtrain_24b_DW.obj.ProjectionLineIndex = 0.0;

    /* End of Start for MATLABSystem: '<S6>/Pure Pursuit' */

    /* Start for If: '<S5>/If' */
    rover_sw_pwrtrain_24b_DW.If_ActiveSubsystem = -1;

    /* Start for IfAction SubSystem: '<S5>/Subsystem1' */
    /* Start for MATLABSystem: '<S21>/SinkBlock' */
    rover_sw_pwrtrain_24b_DW.obj_a.QOSAvoidROSNamespaceConventions = false;
    rover_sw_pwrtrain_24b_DW.obj_a.matlabCodegenIsDeleted = false;
    rover_sw_pwrtrain_24b_DW.objisempty_nh = true;
    rover_sw_pwrtrain_24b_DW.obj_a.isSetupComplete = false;
    rover_sw_pwrtrain_24b_DW.obj_a.isInitialized = 1;
    rover_sw_pw_Publisher_setupImpl(&rover_sw_pwrtrain_24b_DW.obj_a);
    rover_sw_pwrtrain_24b_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S22>/SinkBlock' */
    rover_sw_pwrtrain_24b_DW.obj_p.QOSAvoidROSNamespaceConventions = false;
    rover_sw_pwrtrain_24b_DW.obj_p.matlabCodegenIsDeleted = false;
    rover_sw_pwrtrain_24b_DW.objisempty_d = true;
    rover_sw_pwrtrain_24b_DW.obj_p.isSetupComplete = false;
    rover_sw_pwrtrain_24b_DW.obj_p.isInitialized = 1;
    rover_sw__Publisher_setupImpl_m(&rover_sw_pwrtrain_24b_DW.obj_p);
    rover_sw_pwrtrain_24b_DW.obj_p.isSetupComplete = true;

    /* End of Start for SubSystem: '<S5>/Subsystem1' */

    /* Start for IfAction SubSystem: '<S5>/Subsystem' */
    /* Start for MATLABSystem: '<S17>/SinkBlock' */
    rover_sw_pwrtrain_24b_DW.obj_c.QOSAvoidROSNamespaceConventions = false;
    rover_sw_pwrtrain_24b_DW.obj_c.matlabCodegenIsDeleted = false;
    rover_sw_pwrtrain_24b_DW.objisempty_jb = true;
    rover_sw_pwrtrain_24b_DW.obj_c.isSetupComplete = false;
    rover_sw_pwrtrain_24b_DW.obj_c.isInitialized = 1;
    rover_sw_Publisher_setupImpl_my(&rover_sw_pwrtrain_24b_DW.obj_c);
    rover_sw_pwrtrain_24b_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<S18>/SinkBlock' */
    rover_sw_pwrtrain_24b_DW.obj_n.QOSAvoidROSNamespaceConventions = false;
    rover_sw_pwrtrain_24b_DW.obj_n.matlabCodegenIsDeleted = false;
    rover_sw_pwrtrain_24b_DW.objisempty_j = true;
    rover_sw_pwrtrain_24b_DW.obj_n.isSetupComplete = false;
    rover_sw_pwrtrain_24b_DW.obj_n.isInitialized = 1;
    rover_s_Publisher_setupImpl_myg(&rover_sw_pwrtrain_24b_DW.obj_n);
    rover_sw_pwrtrain_24b_DW.obj_n.isSetupComplete = true;

    /* End of Start for SubSystem: '<S5>/Subsystem' */

    /* Start for MATLABSystem: '<S33>/SinkBlock' */
    rover_sw_pwrtrain_24b_DW.obj_g.QOSAvoidROSNamespaceConventions = false;
    rover_sw_pwrtrain_24b_DW.obj_g.matlabCodegenIsDeleted = false;
    rover_sw_pwrtrain_24b_DW.objisempty_k = true;
    rover_sw_pwrtrain_24b_DW.obj_g.isSetupComplete = false;
    rover_sw_pwrtrain_24b_DW.obj_g.isInitialized = 1;
    rove_Publisher_setupImpl_mygou5(&rover_sw_pwrtrain_24b_DW.obj_g);
    rover_sw_pwrtrain_24b_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S24>/MATLAB System' */
    rover_sw_pwrtrain_24b_DW.obj_j.tunablePropertyChanged[0] = false;
    rover_sw_pwrtrain_24b_DW.obj_j.tunablePropertyChanged[1] = false;
    rover_sw_pwrtrain_24b_DW.obj_j.tunablePropertyChanged[2] = false;
    rover_sw_pwrtrain_24b_DW.objisempty_o = true;
    rover_sw_pwrtrain_24b_DW.obj_j.TrackWidth = 0.5;
    rover_sw_pwrtrain_24b_DW.obj_j.WheelRadius = 0.095;
    rover_sw_pwrtrain_24b_DW.obj_j.WheelSpeedRange[0] = (rtMinusInf);
    rover_sw_pwrtrain_24b_DW.obj_j.WheelSpeedRange[1] = (rtInf);
    rover_sw_pwrtrain_24b_DW.obj_j.isInitialized = 1;
    DifferentialDriveKinematics_set(&rover_sw_pwrtrain_24b_DW.obj_j);
    rover_sw_pwrtrain_24b_DW.obj_j.TunablePropsChanged = false;

    /* Start for MATLABSystem: '<S37>/SourceBlock' */
    rover_sw_pwrtrain_24b_DW.obj_h.QOSAvoidROSNamespaceConventions = false;
    rover_sw_pwrtrain_24b_DW.obj_h.matlabCodegenIsDeleted = false;
    rover_sw_pwrtrain_24b_DW.objisempty_e = true;
    rover_sw_pwrtrain_24b_DW.obj_h.isSetupComplete = false;
    rover_sw_pwrtrain_24b_DW.obj_h.isInitialized = 1;
    rover_s_Subscriber_setupImpl_my(&rover_sw_pwrtrain_24b_DW.obj_h);
    rover_sw_pwrtrain_24b_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S38>/SourceBlock' */
    rover_sw_pwrtrain_24b_DW.obj_fl.QOSAvoidROSNamespaceConventions = false;
    rover_sw_pwrtrain_24b_DW.obj_fl.matlabCodegenIsDeleted = false;
    rover_sw_pwrtrain_24b_DW.objisempty_f = true;
    rover_sw_pwrtrain_24b_DW.obj_fl.isSetupComplete = false;
    rover_sw_pwrtrain_24b_DW.obj_fl.isInitialized = 1;
    rover__Subscriber_setupImpl_myg(&rover_sw_pwrtrain_24b_DW.obj_fl);
    rover_sw_pwrtrain_24b_DW.obj_fl.isSetupComplete = true;

    /* Start for MATLABSystem: '<S40>/SourceBlock' */
    rover_sw_pwrtrain_24b_DW.obj_cy.QOSAvoidROSNamespaceConventions = false;
    rover_sw_pwrtrain_24b_DW.obj_cy.matlabCodegenIsDeleted = false;
    rover_sw_pwrtrain_24b_DW.objisempty = true;
    rover_sw_pwrtrain_24b_DW.obj_cy.isSetupComplete = false;
    rover_sw_pwrtrain_24b_DW.obj_cy.isInitialized = 1;
    rove_Subscriber_setupImpl_mygou(&rover_sw_pwrtrain_24b_DW.obj_cy);
    rover_sw_pwrtrain_24b_DW.obj_cy.isSetupComplete = true;

    /* ConstCode for MATLABSystem: '<S34>/SinkBlock' */
    Pub_rover_sw_pwrtrain_24b_599.publish
      (&rover_sw_pwrtrain_24b_ConstB.BusAssignment4);

    /* ConstCode for MATLABSystem: '<S31>/SinkBlock' */
    Pub_rover_sw_pwrtrain_24b_388.publish
      (&rover_sw_pwrtrain_24b_ConstB.BusAssignment1);

    /* ConstCode for MATLABSystem: '<S32>/SinkBlock' */
    Pub_rover_sw_pwrtrain_24b_389.publish
      (&rover_sw_pwrtrain_24b_ConstB.BusAssignment2);
  }

  {
    int32_T i;
    static const char_T tmp[23] = { 'V', 'e', 'h', 'i', 'c', 'l', 'e', 'S', 'p',
      'e', 'e', 'd', 'H', 'e', 'a', 'd', 'i', 'n', 'g', 'R', 'a', 't', 'e' };

    /* InitializeConditions for Integrator: '<S24>/Integrator' */
    rover_sw_pwrtrain_24b_X.Integrator_CSTATE[0] = 0.0;
    rover_sw_pwrtrain_24b_X.Integrator_CSTATE[1] = 0.0;
    rover_sw_pwrtrain_24b_X.Integrator_CSTATE[2] = 0.0;

    /* SystemInitialize for Enabled SubSystem: '<S39>/Enabled Subsystem' */
    rover_s_EnabledSubsystem_p_Init(&rover_sw_pwrtrain_24b_B.EnabledSubsystem_g);

    /* End of SystemInitialize for SubSystem: '<S39>/Enabled Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S35>/Enabled Subsystem' */
    rover_sw__EnabledSubsystem_Init(&rover_sw_pwrtrain_24b_B.EnabledSubsystem);

    /* End of SystemInitialize for SubSystem: '<S35>/Enabled Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S36>/Enabled Subsystem' */
    rover_sw__EnabledSubsystem_Init(&rover_sw_pwrtrain_24b_B.EnabledSubsystem_o);

    /* End of SystemInitialize for SubSystem: '<S36>/Enabled Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S37>/Enabled Subsystem' */
    rover_sw__EnabledSubsystem_Init(&rover_sw_pwrtrain_24b_B.EnabledSubsystem_p);

    /* End of SystemInitialize for SubSystem: '<S37>/Enabled Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S38>/Enabled Subsystem' */
    rover_sw__EnabledSubsystem_Init(&rover_sw_pwrtrain_24b_B.EnabledSubsystem_p4);

    /* End of SystemInitialize for SubSystem: '<S38>/Enabled Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S40>/Enabled Subsystem' */
    rover_s_EnabledSubsystem_p_Init(&rover_sw_pwrtrain_24b_B.EnabledSubsystem_b);

    /* End of SystemInitialize for SubSystem: '<S40>/Enabled Subsystem' */

    /* InitializeConditions for MATLABSystem: '<S6>/Pure Pursuit' */
    rover_sw_pwrtrain_24b_DW.obj.LookaheadPoint[0] *= 0.0;
    rover_sw_pwrtrain_24b_DW.obj.LookaheadPoint[1] *= 0.0;
    rover_sw_pwrtrain_24b_DW.obj.LastPose[0] *= 0.0;
    rover_sw_pwrtrain_24b_DW.obj.LastPose[1] *= 0.0;
    rover_sw_pwrtrain_24b_DW.obj.LastPose[2] *= 0.0;
    rover_sw_pwrtrain_24b_DW.obj.ProjectionPoint[0] = (rtNaN);
    rover_sw_pwrtrain_24b_DW.obj.ProjectionPoint[1] = (rtNaN);
    rover_sw_pwrtrain_24b_DW.obj.ProjectionLineIndex *= 0.0;

    /* InitializeConditions for MATLABSystem: '<S24>/MATLAB System' */
    for (i = 0; i < 23; i++) {
      rover_sw_pwrtrain_24b_DW.obj_j.KinModel.VehicleInputsInternal[i] = tmp[i];
    }

    rover_sw_pwrtrain_24b_DW.obj_j.KinModel.TrackWidth =
      rover_sw_pwrtrain_24b_DW.obj_j.TrackWidth;
    rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelRadius =
      rover_sw_pwrtrain_24b_DW.obj_j.WheelRadius;
    rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelSpeedRange[0] =
      rover_sw_pwrtrain_24b_DW.obj_j.WheelSpeedRange[0];
    rover_sw_pwrtrain_24b_DW.obj_j.KinModel.WheelSpeedRange[1] =
      rover_sw_pwrtrain_24b_DW.obj_j.WheelSpeedRange[1];

    /* End of InitializeConditions for MATLABSystem: '<S24>/MATLAB System' */

    /* Outputs for Atomic SubSystem: '<Root>/Initialize Function' */
    /* CCaller: '<S1>/C Caller' */
    vesc_open_noargs();

    /* End of Outputs for SubSystem: '<Root>/Initialize Function' */
  }
}

/* Model terminate function */
void rover_sw_pwrtrain_24b::terminate()
{
  /* Outputs for Atomic SubSystem: '<Root>/Terminate Function' */
  /* CCaller: '<S2>/C Caller1' */
  vesc_close();

  /* End of Outputs for SubSystem: '<Root>/Terminate Function' */

  /* Terminate for MATLABSystem: '<S34>/SinkBlock' */
  if (!rover_sw_pwrtrain_24b_DW.obj_m.matlabCodegenIsDeleted) {
    rover_sw_pwrtrain_24b_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((rover_sw_pwrtrain_24b_DW.obj_m.isInitialized == 1) &&
        rover_sw_pwrtrain_24b_DW.obj_m.isSetupComplete) {
      Pub_rover_sw_pwrtrain_24b_599.resetPublisherPtr();//();
    }
  }

  /* End of Terminate for MATLABSystem: '<S34>/SinkBlock' */

  /* Terminate for MATLABSystem: '<S31>/SinkBlock' */
  if (!rover_sw_pwrtrain_24b_DW.obj_g4.matlabCodegenIsDeleted) {
    rover_sw_pwrtrain_24b_DW.obj_g4.matlabCodegenIsDeleted = true;
    if ((rover_sw_pwrtrain_24b_DW.obj_g4.isInitialized == 1) &&
        rover_sw_pwrtrain_24b_DW.obj_g4.isSetupComplete) {
      Pub_rover_sw_pwrtrain_24b_388.resetPublisherPtr();//();
    }
  }

  /* End of Terminate for MATLABSystem: '<S31>/SinkBlock' */

  /* Terminate for MATLABSystem: '<S32>/SinkBlock' */
  if (!rover_sw_pwrtrain_24b_DW.obj_f.matlabCodegenIsDeleted) {
    rover_sw_pwrtrain_24b_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((rover_sw_pwrtrain_24b_DW.obj_f.isInitialized == 1) &&
        rover_sw_pwrtrain_24b_DW.obj_f.isSetupComplete) {
      Pub_rover_sw_pwrtrain_24b_389.resetPublisherPtr();//();
    }
  }

  /* End of Terminate for MATLABSystem: '<S32>/SinkBlock' */

  /* Terminate for MATLABSystem: '<S39>/SourceBlock' */
  if (!rover_sw_pwrtrain_24b_DW.obj_mg.matlabCodegenIsDeleted) {
    rover_sw_pwrtrain_24b_DW.obj_mg.matlabCodegenIsDeleted = true;
    if ((rover_sw_pwrtrain_24b_DW.obj_mg.isInitialized == 1) &&
        rover_sw_pwrtrain_24b_DW.obj_mg.isSetupComplete) {
      Sub_rover_sw_pwrtrain_24b_521.resetSubscriberPtr();//();
    }
  }

  /* End of Terminate for MATLABSystem: '<S39>/SourceBlock' */

  /* Terminate for MATLABSystem: '<S35>/SourceBlock' */
  if (!rover_sw_pwrtrain_24b_DW.obj_i.matlabCodegenIsDeleted) {
    rover_sw_pwrtrain_24b_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((rover_sw_pwrtrain_24b_DW.obj_i.isInitialized == 1) &&
        rover_sw_pwrtrain_24b_DW.obj_i.isSetupComplete) {
      Sub_rover_sw_pwrtrain_24b_390.resetSubscriberPtr();//();
    }
  }

  /* End of Terminate for MATLABSystem: '<S35>/SourceBlock' */

  /* Terminate for MATLABSystem: '<S36>/SourceBlock' */
  if (!rover_sw_pwrtrain_24b_DW.obj_ng.matlabCodegenIsDeleted) {
    rover_sw_pwrtrain_24b_DW.obj_ng.matlabCodegenIsDeleted = true;
    if ((rover_sw_pwrtrain_24b_DW.obj_ng.isInitialized == 1) &&
        rover_sw_pwrtrain_24b_DW.obj_ng.isSetupComplete) {
      Sub_rover_sw_pwrtrain_24b_391.resetSubscriberPtr();//();
    }
  }

  /* End of Terminate for MATLABSystem: '<S36>/SourceBlock' */

  /* Terminate for IfAction SubSystem: '<S5>/Subsystem1' */
  /* Terminate for MATLABSystem: '<S21>/SinkBlock' */
  if (!rover_sw_pwrtrain_24b_DW.obj_a.matlabCodegenIsDeleted) {
    rover_sw_pwrtrain_24b_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((rover_sw_pwrtrain_24b_DW.obj_a.isInitialized == 1) &&
        rover_sw_pwrtrain_24b_DW.obj_a.isSetupComplete) {
      Pub_rover_sw_pwrtrain_24b_138.resetPublisherPtr();//();
    }
  }

  /* End of Terminate for MATLABSystem: '<S21>/SinkBlock' */

  /* Terminate for MATLABSystem: '<S22>/SinkBlock' */
  if (!rover_sw_pwrtrain_24b_DW.obj_p.matlabCodegenIsDeleted) {
    rover_sw_pwrtrain_24b_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((rover_sw_pwrtrain_24b_DW.obj_p.isInitialized == 1) &&
        rover_sw_pwrtrain_24b_DW.obj_p.isSetupComplete) {
      Pub_rover_sw_pwrtrain_24b_139.resetPublisherPtr();//();
    }
  }

  /* End of Terminate for MATLABSystem: '<S22>/SinkBlock' */
  /* End of Terminate for SubSystem: '<S5>/Subsystem1' */

  /* Terminate for IfAction SubSystem: '<S5>/Subsystem' */
  /* Terminate for MATLABSystem: '<S17>/SinkBlock' */
  if (!rover_sw_pwrtrain_24b_DW.obj_c.matlabCodegenIsDeleted) {
    rover_sw_pwrtrain_24b_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((rover_sw_pwrtrain_24b_DW.obj_c.isInitialized == 1) &&
        rover_sw_pwrtrain_24b_DW.obj_c.isSetupComplete) {
      Pub_rover_sw_pwrtrain_24b_542.resetPublisherPtr();//();
    }
  }

  /* End of Terminate for MATLABSystem: '<S17>/SinkBlock' */

  /* Terminate for MATLABSystem: '<S18>/SinkBlock' */
  if (!rover_sw_pwrtrain_24b_DW.obj_n.matlabCodegenIsDeleted) {
    rover_sw_pwrtrain_24b_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((rover_sw_pwrtrain_24b_DW.obj_n.isInitialized == 1) &&
        rover_sw_pwrtrain_24b_DW.obj_n.isSetupComplete) {
      Pub_rover_sw_pwrtrain_24b_543.resetPublisherPtr();//();
    }
  }

  /* End of Terminate for MATLABSystem: '<S18>/SinkBlock' */
  /* End of Terminate for SubSystem: '<S5>/Subsystem' */

  /* Terminate for MATLABSystem: '<S33>/SinkBlock' */
  if (!rover_sw_pwrtrain_24b_DW.obj_g.matlabCodegenIsDeleted) {
    rover_sw_pwrtrain_24b_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((rover_sw_pwrtrain_24b_DW.obj_g.isInitialized == 1) &&
        rover_sw_pwrtrain_24b_DW.obj_g.isSetupComplete) {
      Pub_rover_sw_pwrtrain_24b_246.resetPublisherPtr();//();
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/SinkBlock' */

  /* Terminate for MATLABSystem: '<S37>/SourceBlock' */
  if (!rover_sw_pwrtrain_24b_DW.obj_h.matlabCodegenIsDeleted) {
    rover_sw_pwrtrain_24b_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((rover_sw_pwrtrain_24b_DW.obj_h.isInitialized == 1) &&
        rover_sw_pwrtrain_24b_DW.obj_h.isSetupComplete) {
      Sub_rover_sw_pwrtrain_24b_392.resetSubscriberPtr();//();
    }
  }

  /* End of Terminate for MATLABSystem: '<S37>/SourceBlock' */

  /* Terminate for MATLABSystem: '<S38>/SourceBlock' */
  if (!rover_sw_pwrtrain_24b_DW.obj_fl.matlabCodegenIsDeleted) {
    rover_sw_pwrtrain_24b_DW.obj_fl.matlabCodegenIsDeleted = true;
    if ((rover_sw_pwrtrain_24b_DW.obj_fl.isInitialized == 1) &&
        rover_sw_pwrtrain_24b_DW.obj_fl.isSetupComplete) {
      Sub_rover_sw_pwrtrain_24b_466.resetSubscriberPtr();//();
    }
  }

  /* End of Terminate for MATLABSystem: '<S38>/SourceBlock' */

  /* Terminate for MATLABSystem: '<S40>/SourceBlock' */
  if (!rover_sw_pwrtrain_24b_DW.obj_cy.matlabCodegenIsDeleted) {
    rover_sw_pwrtrain_24b_DW.obj_cy.matlabCodegenIsDeleted = true;
    if ((rover_sw_pwrtrain_24b_DW.obj_cy.isInitialized == 1) &&
        rover_sw_pwrtrain_24b_DW.obj_cy.isSetupComplete) {
      Sub_rover_sw_pwrtrain_24b_601.resetSubscriberPtr();//();
    }
  }

  /* End of Terminate for MATLABSystem: '<S40>/SourceBlock' */
}

/* Constructor */
rover_sw_pwrtrain_24b::rover_sw_pwrtrain_24b() :
  rover_sw_pwrtrain_24b_B(),
  rover_sw_pwrtrain_24b_DW(),
  rover_sw_pwrtrain_24b_X(),
  rover_sw_pwrtrain_24b_XDis(),
  rover_sw_pwrtrain_24b_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
rover_sw_pwrtrain_24b::~rover_sw_pwrtrain_24b()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_rover_sw_pwrtrain_24_T * rover_sw_pwrtrain_24b::getRTM()
{
  return (&rover_sw_pwrtrain_24b_M);
}
