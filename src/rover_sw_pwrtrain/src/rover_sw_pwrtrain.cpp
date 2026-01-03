/*
 * rover_sw_pwrtrain.cpp
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

#include "rover_sw_pwrtrain.h"
#include "rtwtypes.h"
#include "rover_sw_pwrtrain_types.h"
#include <string.h>
#include "rmw/qos_profiles.h"
#include <stddef.h>

/* user code (top of source file) */
int vesc_open_noargs(void);
void vesc_close(void);
int vesc_send_duty(double duty);
int vesc_poll(float* v_in, float* t_mos, float* t_motor);

/*
 * System initialize for enable system:
 *    '<S22>/Enabled Subsystem'
 *    '<S23>/Enabled Subsystem'
 *    '<S24>/Enabled Subsystem'
 */
void rover_sw_pwrtrain::rover_sw__EnabledSubsystem_Init
  (B_EnabledSubsystem_rover_sw_p_T *localB)
{
  /* SystemInitialize for SignalConversion generated from: '<S26>/In1' */
  memset(&localB->In1, 0, sizeof(SL_Bus_std_msgs_Float32));
}

/*
 * Output and update for enable system:
 *    '<S22>/Enabled Subsystem'
 *    '<S23>/Enabled Subsystem'
 *    '<S24>/Enabled Subsystem'
 */
void rover_sw_pwrtrain::rover_sw_pwrtr_EnabledSubsystem(boolean_T rtu_Enable,
  const SL_Bus_std_msgs_Float32 *rtu_In1, B_EnabledSubsystem_rover_sw_p_T
  *localB)
{
  /* Outputs for Enabled SubSystem: '<S22>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S26>/Enable'
   */
  if (rtu_Enable) {
    /* SignalConversion generated from: '<S26>/In1' */
    localB->In1 = *rtu_In1;
  }

  /* End of Outputs for SubSystem: '<S22>/Enabled Subsystem' */
}

void rover_sw_pwrtrain::rover_sw_p_Subscriber_setupImpl(const
  ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  sJ4ih70VmKcvCeguWN0mNVF deadline;
  sJ4ih70VmKcvCeguWN0mNVF lifespan;
  sJ4ih70VmKcvCeguWN0mNVF liveliness_lease_duration;
  static const char_T b_zeroDelimTopic[19] = "/vesc/cmd_throttle";
  qos_profile = rmw_qos_profile_default;

  /* Start for MATLABSystem: '<S22>/SourceBlock' */
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
    /* Start for MATLABSystem: '<S22>/SourceBlock' */
    rover_sw_pwrtrain_B.b_zeroDelimTopic_b[i] = b_zeroDelimTopic[i];
  }

  Sub_rover_sw_pwrtrain_140.createSubscriber
    (&rover_sw_pwrtrain_B.b_zeroDelimTopic_b[0], qos_profile);
}

void rover_sw_pwrtrain::rover_s_Subscriber_setupImpl_py(const
  ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  sJ4ih70VmKcvCeguWN0mNVF deadline;
  sJ4ih70VmKcvCeguWN0mNVF lifespan;
  sJ4ih70VmKcvCeguWN0mNVF liveliness_lease_duration;
  static const char_T b_zeroDelimTopic[16] = "/front_distance";
  qos_profile = rmw_qos_profile_default;

  /* Start for MATLABSystem: '<S24>/SourceBlock' */
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
    /* Start for MATLABSystem: '<S24>/SourceBlock' */
    rover_sw_pwrtrain_B.b_zeroDelimTopic_cv[i] = b_zeroDelimTopic[i];
  }

  Sub_rover_sw_pwrtrain_173.createSubscriber
    (&rover_sw_pwrtrain_B.b_zeroDelimTopic_cv[0], qos_profile);
}

void rover_sw_pwrtrain::rover_sw_Subscriber_setupImpl_p(const
  ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  sJ4ih70VmKcvCeguWN0mNVF deadline;
  sJ4ih70VmKcvCeguWN0mNVF lifespan;
  sJ4ih70VmKcvCeguWN0mNVF liveliness_lease_duration;
  static const char_T b_zeroDelimTopic[19] = "/vesc/cmd_steering";
  qos_profile = rmw_qos_profile_default;

  /* Start for MATLABSystem: '<S23>/SourceBlock' */
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
    /* Start for MATLABSystem: '<S23>/SourceBlock' */
    rover_sw_pwrtrain_B.b_zeroDelimTopic_cx[i] = b_zeroDelimTopic[i];
  }

  Sub_rover_sw_pwrtrain_141.createSubscriber
    (&rover_sw_pwrtrain_B.b_zeroDelimTopic_cx[0], qos_profile);
}

void rover_sw_pwrtrain::rover_s_Publisher_setupImpl_pyc(const
  ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  sJ4ih70VmKcvCeguWN0mNVF deadline;
  sJ4ih70VmKcvCeguWN0mNVF lifespan;
  sJ4ih70VmKcvCeguWN0mNVF liveliness_lease_duration;
  static const char_T b_zeroDelimTopic[27] = "/vesc/last_cmd_status_left";
  qos_profile = rmw_qos_profile_default;

  /* Start for MATLABSystem: '<S20>/SinkBlock' */
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
    /* Start for MATLABSystem: '<S20>/SinkBlock' */
    rover_sw_pwrtrain_B.b_zeroDelimTopic_k[i] = b_zeroDelimTopic[i];
  }

  Pub_rover_sw_pwrtrain_138.createPublisher
    (&rover_sw_pwrtrain_B.b_zeroDelimTopic_k[0], qos_profile);
}

void rover_sw_pwrtrain::rover__Publisher_setupImpl_pycx(const
  ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  sJ4ih70VmKcvCeguWN0mNVF deadline;
  sJ4ih70VmKcvCeguWN0mNVF lifespan;
  sJ4ih70VmKcvCeguWN0mNVF liveliness_lease_duration;
  static const char_T b_zeroDelimTopic[28] = "/vesc/last_cmd_status_right";
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
  for (int32_T i = 0; i < 28; i++) {
    /* Start for MATLABSystem: '<S21>/SinkBlock' */
    rover_sw_pwrtrain_B.b_zeroDelimTopic_m[i] = b_zeroDelimTopic[i];
  }

  Pub_rover_sw_pwrtrain_139.createPublisher
    (&rover_sw_pwrtrain_B.b_zeroDelimTopic_m[0], qos_profile);
}

void rover_sw_pwrtrain::rover_sw_pw_Publisher_setupImpl(const
  ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  sJ4ih70VmKcvCeguWN0mNVF lifespan;
  sJ4ih70VmKcvCeguWN0mNVF liveliness_lease_duration;
  char_T b_zeroDelimTopic[11];
  static const char_T b_zeroDelimTopic_0[11] = "/led_state";
  qos_profile = rmw_qos_profile_default;

  /* Start for MATLABSystem: '<S7>/SinkBlock' */
  rover_sw_pwrtrain_B.deadline.sec = 0.0;
  rover_sw_pwrtrain_B.deadline.nsec = 0.0;
  lifespan.sec = 0.0;
  lifespan.nsec = 0.0;
  liveliness_lease_duration.sec = 0.0;
  liveliness_lease_duration.nsec = 0.0;
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE,
                 rover_sw_pwrtrain_B.deadline, lifespan,
                 RMW_QOS_POLICY_LIVELINESS_AUTOMATIC, liveliness_lease_duration,
                 (bool)obj->QOSAvoidROSNamespaceConventions);
  for (int32_T i = 0; i < 11; i++) {
    /* Start for MATLABSystem: '<S7>/SinkBlock' */
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Pub_rover_sw_pwrtrain_246.createPublisher(&b_zeroDelimTopic[0], qos_profile);
}

void rover_sw_pwrtrain::rover__Subscriber_setupImpl_pyc(const
  ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  sJ4ih70VmKcvCeguWN0mNVF deadline;
  sJ4ih70VmKcvCeguWN0mNVF lifespan;
  sJ4ih70VmKcvCeguWN0mNVF liveliness_lease_duration;
  static const char_T b_zeroDelimTopic[17] = "/autonomous_mode";
  qos_profile = rmw_qos_profile_default;

  /* Start for MATLABSystem: '<S10>/SourceBlock' */
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
  for (int32_T i = 0; i < 17; i++) {
    /* Start for MATLABSystem: '<S10>/SourceBlock' */
    rover_sw_pwrtrain_B.b_zeroDelimTopic_p[i] = b_zeroDelimTopic[i];
  }

  Sub_rover_sw_pwrtrain_78.createSubscriber
    (&rover_sw_pwrtrain_B.b_zeroDelimTopic_p[0], qos_profile);
}

void rover_sw_pwrtrain::rover_sw__Publisher_setupImpl_p(const
  ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  sJ4ih70VmKcvCeguWN0mNVF deadline;
  sJ4ih70VmKcvCeguWN0mNVF lifespan;
  sJ4ih70VmKcvCeguWN0mNVF liveliness_lease_duration;
  static const char_T b_zeroDelimTopic[27] = "/vesc/last_cmd_status_left";
  qos_profile = rmw_qos_profile_default;

  /* Start for MATLABSystem: '<S13>/SinkBlock' */
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
    /* Start for MATLABSystem: '<S13>/SinkBlock' */
    rover_sw_pwrtrain_B.b_zeroDelimTopic_c[i] = b_zeroDelimTopic[i];
  }

  Pub_rover_sw_pwrtrain_99.createPublisher
    (&rover_sw_pwrtrain_B.b_zeroDelimTopic_c[0], qos_profile);
}

void rover_sw_pwrtrain::rover_sw_Publisher_setupImpl_py(const
  ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  sJ4ih70VmKcvCeguWN0mNVF deadline;
  sJ4ih70VmKcvCeguWN0mNVF lifespan;
  sJ4ih70VmKcvCeguWN0mNVF liveliness_lease_duration;
  static const char_T b_zeroDelimTopic[28] = "/vesc/last_cmd_status_right";
  qos_profile = rmw_qos_profile_default;

  /* Start for MATLABSystem: '<S14>/SinkBlock' */
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
    /* Start for MATLABSystem: '<S14>/SinkBlock' */
    rover_sw_pwrtrain_B.b_zeroDelimTopic[i] = b_zeroDelimTopic[i];
  }

  Pub_rover_sw_pwrtrain_100.createPublisher
    (&rover_sw_pwrtrain_B.b_zeroDelimTopic[0], qos_profile);
}

/* Model step function */
void rover_sw_pwrtrain::step()
{
  SL_Bus_std_msgs_Bool rtb_SourceBlock_o2_e_0;
  SL_Bus_std_msgs_Float32 tmp;
  SL_Bus_std_msgs_Int32 rtb_BusAssignment1;
  SL_Bus_std_msgs_Int32 rtb_BusAssignment1_k;
  SL_Bus_std_msgs_Int32 rtb_BusAssignment1_m;
  SL_Bus_std_msgs_Int32 rtb_BusAssignment2;
  SL_Bus_std_msgs_Int32 rtb_BusAssignment2_c;
  real_T rtb_BusAssignment1_a_tmp;
  real_T rtb_Plus2;
  real32_T rtb_Switch;
  real32_T rtb_Switch1;
  boolean_T b_varargout_1;
  boolean_T b_varargout_1_0;
  boolean_T b_varargout_1_1;

  /* Outputs for Atomic SubSystem: '<S4>/If Action Subsystem1' */
  /* MATLABSystem: '<S22>/SourceBlock' */
  b_varargout_1 = Sub_rover_sw_pwrtrain_140.getLatestMessage(&tmp);

  /* Outputs for Enabled SubSystem: '<S22>/Enabled Subsystem' */
  /* Start for MATLABSystem: '<S22>/SourceBlock' */
  rover_sw_pwrtr_EnabledSubsystem(b_varargout_1, &tmp,
    &rover_sw_pwrtrain_B.EnabledSubsystem_d);

  /* End of Outputs for SubSystem: '<S22>/Enabled Subsystem' */

  /* MATLABSystem: '<S24>/SourceBlock' */
  b_varargout_1_0 = Sub_rover_sw_pwrtrain_173.getLatestMessage(&tmp);

  /* Outputs for Enabled SubSystem: '<S24>/Enabled Subsystem' */
  /* Start for MATLABSystem: '<S24>/SourceBlock' */
  rover_sw_pwrtr_EnabledSubsystem(b_varargout_1_0, &tmp,
    &rover_sw_pwrtrain_B.EnabledSubsystem_g);

  /* End of Outputs for SubSystem: '<S24>/Enabled Subsystem' */

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S18>/Constant'
   *  Gain: '<S9>/Gain1'
   *  RelationalOperator: '<S18>/Compare'
   */
  if (rover_sw_pwrtrain_B.EnabledSubsystem_g.In1.data >= 20.0F) {
    rtb_Switch = rover_sw_pwrtrain_B.EnabledSubsystem_d.In1.data;
  } else {
    rtb_Switch = 0.1F * rover_sw_pwrtrain_B.EnabledSubsystem_d.In1.data;
  }

  /* End of Switch: '<S9>/Switch' */

  /* MATLABSystem: '<S23>/SourceBlock' */
  b_varargout_1_1 = Sub_rover_sw_pwrtrain_141.getLatestMessage(&tmp);

  /* Outputs for Enabled SubSystem: '<S23>/Enabled Subsystem' */
  /* Start for MATLABSystem: '<S23>/SourceBlock' */
  rover_sw_pwrtr_EnabledSubsystem(b_varargout_1_1, &tmp,
    &rover_sw_pwrtrain_B.EnabledSubsystem_k);

  /* End of Outputs for SubSystem: '<S23>/Enabled Subsystem' */

  /* Switch: '<S9>/Switch1' incorporates:
   *  Constant: '<S19>/Constant'
   *  Gain: '<S9>/Gain'
   *  RelationalOperator: '<S19>/Compare'
   */
  if (rover_sw_pwrtrain_B.EnabledSubsystem_g.In1.data >= 20.0F) {
    rtb_Switch1 = rover_sw_pwrtrain_B.EnabledSubsystem_k.In1.data;
  } else {
    rtb_Switch1 = 0.1F * rover_sw_pwrtrain_B.EnabledSubsystem_k.In1.data;
  }

  /* End of Switch: '<S9>/Switch1' */

  /* Outputs for Enabled SubSystem: '<S9>/Subsystem' incorporates:
   *  EnablePort: '<S25>/Enable'
   */
  /* Logic: '<S9>/OR' incorporates:
   *  MATLABSystem: '<S22>/SourceBlock'
   *  MATLABSystem: '<S23>/SourceBlock'
   *  MATLABSystem: '<S24>/SourceBlock'
   * */
  if (b_varargout_1_0 || b_varargout_1 || b_varargout_1_1) {
    /* Product: '<S25>/Product' incorporates:
     *  Product: '<S25>/Product1'
     */
    rtb_Switch1 *= rtb_Switch;

    /* CCaller: '<S25>/vesc_send_duty_left' incorporates:
     *  DataTypeConversion: '<S25>/Data Type Conversion'
     *  Product: '<S25>/Product'
     *  Sum: '<S25>/Plus'
     */
    rover_sw_pwrtrain_B.vesc_send_duty_left = vesc_send_duty_left
      (static_cast<real_T>(rtb_Switch1 + rtb_Switch));

    /* CCaller: '<S25>/vesc_send_duty_right' incorporates:
     *  DataTypeConversion: '<S25>/Data Type Conversion2'
     *  Sum: '<S25>/Plus2'
     */
    rover_sw_pwrtrain_B.vesc_send_duty_right = vesc_send_duty_right
      (static_cast<real_T>(rtb_Switch - rtb_Switch1));
  }

  /* End of Logic: '<S9>/OR' */
  /* End of Outputs for SubSystem: '<S9>/Subsystem' */

  /* BusAssignment: '<S9>/Bus Assignment1' */
  rtb_BusAssignment1.data = rover_sw_pwrtrain_B.vesc_send_duty_left;

  /* MATLABSystem: '<S20>/SinkBlock' */
  Pub_rover_sw_pwrtrain_138.publish(&rtb_BusAssignment1);

  /* BusAssignment: '<S9>/Bus Assignment2' */
  rtb_BusAssignment2.data = rover_sw_pwrtrain_B.vesc_send_duty_right;

  /* MATLABSystem: '<S21>/SinkBlock' */
  Pub_rover_sw_pwrtrain_139.publish(&rtb_BusAssignment2);

  /* End of Outputs for SubSystem: '<S4>/If Action Subsystem1' */

  /* Outputs for Atomic SubSystem: '<S3>/lamp_contrl' */
  /* Switch: '<S5>/Switch' incorporates:
   *  Logic: '<S5>/OR'
   */
  if ((rover_sw_pwrtrain_B.EnabledSubsystem_d.In1.data != 0.0F) ||
      (rover_sw_pwrtrain_B.EnabledSubsystem_k.In1.data != 0.0F)) {
    /* BusAssignment: '<S5>/Bus Assignment1' incorporates:
     *  Constant: '<S5>/Constant'
     *  DataTypeConversion: '<S5>/Data Type Conversion1'
     */
    rtb_BusAssignment1_m.data = 1300;
  } else {
    /* BusAssignment: '<S5>/Bus Assignment1' incorporates:
     *  Constant: '<S5>/Constant1'
     *  DataTypeConversion: '<S5>/Data Type Conversion1'
     */
    rtb_BusAssignment1_m.data = 1500;
  }

  /* End of Switch: '<S5>/Switch' */

  /* MATLABSystem: '<S7>/SinkBlock' */
  Pub_rover_sw_pwrtrain_246.publish(&rtb_BusAssignment1_m);

  /* End of Outputs for SubSystem: '<S3>/lamp_contrl' */

  /* MATLABSystem: '<S10>/SourceBlock' */
  b_varargout_1 = Sub_rover_sw_pwrtrain_78.getLatestMessage
    (&rtb_SourceBlock_o2_e_0);

  /* Outputs for Enabled SubSystem: '<S10>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S29>/Enable'
   */
  /* Start for MATLABSystem: '<S10>/SourceBlock' */
  if (b_varargout_1) {
    /* SignalConversion generated from: '<S29>/In1' */
    rover_sw_pwrtrain_B.In1 = rtb_SourceBlock_o2_e_0;
  }

  /* End of Outputs for SubSystem: '<S10>/Enabled Subsystem' */

  /* Outputs for Enabled SubSystem: '<S4>/If Action Subsystem' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  /* Logic: '<S4>/AND' incorporates:
   *  MATLABSystem: '<S10>/SourceBlock'
   * */
  if (b_varargout_1 && rover_sw_pwrtrain_B.In1.data) {
    /* Gain: '<S15>/Gain' incorporates:
     *  Inport: '<Root>/throttle'
     */
    rtb_Plus2 = 0.1 * rover_sw_pwrtrain_U.throttle;

    /* Product: '<S15>/Product' incorporates:
     *  Gain: '<S15>/Gain1'
     *  Inport: '<Root>/steering'
     *  Product: '<S15>/Product1'
     */
    rtb_BusAssignment1_a_tmp = 0.1 * rover_sw_pwrtrain_U.steering * rtb_Plus2;

    /* BusAssignment: '<S8>/Bus Assignment1' incorporates:
     *  CCaller: '<S15>/vesc_send_duty_left'
     *  Product: '<S15>/Product'
     *  Sum: '<S15>/Plus'
     */
    rtb_BusAssignment1_k.data = vesc_send_duty_left(rtb_BusAssignment1_a_tmp +
      rtb_Plus2);

    /* MATLABSystem: '<S13>/SinkBlock' */
    Pub_rover_sw_pwrtrain_99.publish(&rtb_BusAssignment1_k);

    /* BusAssignment: '<S8>/Bus Assignment2' incorporates:
     *  CCaller: '<S15>/vesc_send_duty_right'
     *  Sum: '<S15>/Plus2'
     */
    rtb_BusAssignment2_c.data = vesc_send_duty_right(rtb_Plus2 -
      rtb_BusAssignment1_a_tmp);

    /* MATLABSystem: '<S14>/SinkBlock' */
    Pub_rover_sw_pwrtrain_100.publish(&rtb_BusAssignment2_c);
  }

  /* End of Logic: '<S4>/AND' */
  /* End of Outputs for SubSystem: '<S4>/If Action Subsystem' */
}

/* Model initialize function */
void rover_sw_pwrtrain::initialize()
{
  /* Start for Atomic SubSystem: '<S4>/If Action Subsystem1' */
  /* Start for MATLABSystem: '<S22>/SourceBlock' */
  rover_sw_pwrtrain_DW.obj_b.QOSAvoidROSNamespaceConventions = false;
  rover_sw_pwrtrain_DW.obj_b.matlabCodegenIsDeleted = false;
  rover_sw_pwrtrain_DW.objisempty_c = true;
  rover_sw_pwrtrain_DW.obj_b.isSetupComplete = false;
  rover_sw_pwrtrain_DW.obj_b.isInitialized = 1;
  rover_sw_p_Subscriber_setupImpl(&rover_sw_pwrtrain_DW.obj_b);
  rover_sw_pwrtrain_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S24>/SourceBlock' */
  rover_sw_pwrtrain_DW.obj_ll.QOSAvoidROSNamespaceConventions = false;
  rover_sw_pwrtrain_DW.obj_ll.matlabCodegenIsDeleted = false;
  rover_sw_pwrtrain_DW.objisempty_f = true;
  rover_sw_pwrtrain_DW.obj_ll.isSetupComplete = false;
  rover_sw_pwrtrain_DW.obj_ll.isInitialized = 1;
  rover_s_Subscriber_setupImpl_py(&rover_sw_pwrtrain_DW.obj_ll);
  rover_sw_pwrtrain_DW.obj_ll.isSetupComplete = true;

  /* Start for MATLABSystem: '<S23>/SourceBlock' */
  rover_sw_pwrtrain_DW.obj_h.QOSAvoidROSNamespaceConventions = false;
  rover_sw_pwrtrain_DW.obj_h.matlabCodegenIsDeleted = false;
  rover_sw_pwrtrain_DW.objisempty_j = true;
  rover_sw_pwrtrain_DW.obj_h.isSetupComplete = false;
  rover_sw_pwrtrain_DW.obj_h.isInitialized = 1;
  rover_sw_Subscriber_setupImpl_p(&rover_sw_pwrtrain_DW.obj_h);
  rover_sw_pwrtrain_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<S20>/SinkBlock' */
  rover_sw_pwrtrain_DW.obj_a.QOSAvoidROSNamespaceConventions = false;
  rover_sw_pwrtrain_DW.obj_a.matlabCodegenIsDeleted = false;
  rover_sw_pwrtrain_DW.objisempty_n = true;
  rover_sw_pwrtrain_DW.obj_a.isSetupComplete = false;
  rover_sw_pwrtrain_DW.obj_a.isInitialized = 1;
  rover_s_Publisher_setupImpl_pyc(&rover_sw_pwrtrain_DW.obj_a);
  rover_sw_pwrtrain_DW.obj_a.isSetupComplete = true;

  /* Start for MATLABSystem: '<S21>/SinkBlock' */
  rover_sw_pwrtrain_DW.obj.QOSAvoidROSNamespaceConventions = false;
  rover_sw_pwrtrain_DW.obj.matlabCodegenIsDeleted = false;
  rover_sw_pwrtrain_DW.objisempty_d = true;
  rover_sw_pwrtrain_DW.obj.isSetupComplete = false;
  rover_sw_pwrtrain_DW.obj.isInitialized = 1;
  rover__Publisher_setupImpl_pycx(&rover_sw_pwrtrain_DW.obj);
  rover_sw_pwrtrain_DW.obj.isSetupComplete = true;

  /* End of Start for SubSystem: '<S4>/If Action Subsystem1' */

  /* Start for Atomic SubSystem: '<S3>/lamp_contrl' */
  /* Start for MATLABSystem: '<S7>/SinkBlock' */
  rover_sw_pwrtrain_DW.obj_g.QOSAvoidROSNamespaceConventions = false;
  rover_sw_pwrtrain_DW.obj_g.matlabCodegenIsDeleted = false;
  rover_sw_pwrtrain_DW.objisempty_kn = true;
  rover_sw_pwrtrain_DW.obj_g.isSetupComplete = false;
  rover_sw_pwrtrain_DW.obj_g.isInitialized = 1;
  rover_sw_pw_Publisher_setupImpl(&rover_sw_pwrtrain_DW.obj_g);
  rover_sw_pwrtrain_DW.obj_g.isSetupComplete = true;

  /* End of Start for SubSystem: '<S3>/lamp_contrl' */

  /* Start for MATLABSystem: '<S10>/SourceBlock' */
  rover_sw_pwrtrain_DW.obj_c.QOSAvoidROSNamespaceConventions = false;
  rover_sw_pwrtrain_DW.obj_c.matlabCodegenIsDeleted = false;
  rover_sw_pwrtrain_DW.objisempty = true;
  rover_sw_pwrtrain_DW.obj_c.isSetupComplete = false;
  rover_sw_pwrtrain_DW.obj_c.isInitialized = 1;
  rover__Subscriber_setupImpl_pyc(&rover_sw_pwrtrain_DW.obj_c);
  rover_sw_pwrtrain_DW.obj_c.isSetupComplete = true;

  /* Start for Enabled SubSystem: '<S4>/If Action Subsystem' */
  /* Start for MATLABSystem: '<S13>/SinkBlock' */
  rover_sw_pwrtrain_DW.obj_l.QOSAvoidROSNamespaceConventions = false;
  rover_sw_pwrtrain_DW.obj_l.matlabCodegenIsDeleted = false;
  rover_sw_pwrtrain_DW.objisempty_i = true;
  rover_sw_pwrtrain_DW.obj_l.isSetupComplete = false;
  rover_sw_pwrtrain_DW.obj_l.isInitialized = 1;
  rover_sw__Publisher_setupImpl_p(&rover_sw_pwrtrain_DW.obj_l);
  rover_sw_pwrtrain_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S14>/SinkBlock' */
  rover_sw_pwrtrain_DW.obj_o.QOSAvoidROSNamespaceConventions = false;
  rover_sw_pwrtrain_DW.obj_o.matlabCodegenIsDeleted = false;
  rover_sw_pwrtrain_DW.objisempty_k = true;
  rover_sw_pwrtrain_DW.obj_o.isSetupComplete = false;
  rover_sw_pwrtrain_DW.obj_o.isInitialized = 1;
  rover_sw_Publisher_setupImpl_py(&rover_sw_pwrtrain_DW.obj_o);
  rover_sw_pwrtrain_DW.obj_o.isSetupComplete = true;

  /* End of Start for SubSystem: '<S4>/If Action Subsystem' */

  /* SystemInitialize for Atomic SubSystem: '<S4>/If Action Subsystem1' */
  /* SystemInitialize for Enabled SubSystem: '<S22>/Enabled Subsystem' */
  rover_sw__EnabledSubsystem_Init(&rover_sw_pwrtrain_B.EnabledSubsystem_d);

  /* End of SystemInitialize for SubSystem: '<S22>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S24>/Enabled Subsystem' */
  rover_sw__EnabledSubsystem_Init(&rover_sw_pwrtrain_B.EnabledSubsystem_g);

  /* End of SystemInitialize for SubSystem: '<S24>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S23>/Enabled Subsystem' */
  rover_sw__EnabledSubsystem_Init(&rover_sw_pwrtrain_B.EnabledSubsystem_k);

  /* End of SystemInitialize for SubSystem: '<S23>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<S4>/If Action Subsystem1' */

  /* SystemInitialize for SignalConversion generated from: '<S29>/In1' */
  memset(&rover_sw_pwrtrain_B.In1, 0, sizeof(SL_Bus_std_msgs_Bool));

  /* Outputs for Atomic SubSystem: '<Root>/Initialize Function' */
  /* CCaller: '<S1>/C Caller' */
  vesc_open_noargs();

  /* End of Outputs for SubSystem: '<Root>/Initialize Function' */
}

/* Model terminate function */
void rover_sw_pwrtrain::terminate()
{
  /* Outputs for Atomic SubSystem: '<Root>/Terminate Function' */
  /* CCaller: '<S2>/C Caller1' */
  vesc_close();

  /* End of Outputs for SubSystem: '<Root>/Terminate Function' */

  /* Terminate for Atomic SubSystem: '<S4>/If Action Subsystem1' */
  /* Terminate for MATLABSystem: '<S22>/SourceBlock' */
  if (!rover_sw_pwrtrain_DW.obj_b.matlabCodegenIsDeleted) {
    rover_sw_pwrtrain_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((rover_sw_pwrtrain_DW.obj_b.isInitialized == 1) &&
        rover_sw_pwrtrain_DW.obj_b.isSetupComplete) {
      Sub_rover_sw_pwrtrain_140.resetSubscriberPtr();//();
    }
  }

  /* End of Terminate for MATLABSystem: '<S22>/SourceBlock' */

  /* Terminate for MATLABSystem: '<S24>/SourceBlock' */
  if (!rover_sw_pwrtrain_DW.obj_ll.matlabCodegenIsDeleted) {
    rover_sw_pwrtrain_DW.obj_ll.matlabCodegenIsDeleted = true;
    if ((rover_sw_pwrtrain_DW.obj_ll.isInitialized == 1) &&
        rover_sw_pwrtrain_DW.obj_ll.isSetupComplete) {
      Sub_rover_sw_pwrtrain_173.resetSubscriberPtr();//();
    }
  }

  /* End of Terminate for MATLABSystem: '<S24>/SourceBlock' */

  /* Terminate for MATLABSystem: '<S23>/SourceBlock' */
  if (!rover_sw_pwrtrain_DW.obj_h.matlabCodegenIsDeleted) {
    rover_sw_pwrtrain_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((rover_sw_pwrtrain_DW.obj_h.isInitialized == 1) &&
        rover_sw_pwrtrain_DW.obj_h.isSetupComplete) {
      Sub_rover_sw_pwrtrain_141.resetSubscriberPtr();//();
    }
  }

  /* End of Terminate for MATLABSystem: '<S23>/SourceBlock' */

  /* Terminate for MATLABSystem: '<S20>/SinkBlock' */
  if (!rover_sw_pwrtrain_DW.obj_a.matlabCodegenIsDeleted) {
    rover_sw_pwrtrain_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((rover_sw_pwrtrain_DW.obj_a.isInitialized == 1) &&
        rover_sw_pwrtrain_DW.obj_a.isSetupComplete) {
      Pub_rover_sw_pwrtrain_138.resetPublisherPtr();//();
    }
  }

  /* End of Terminate for MATLABSystem: '<S20>/SinkBlock' */

  /* Terminate for MATLABSystem: '<S21>/SinkBlock' */
  if (!rover_sw_pwrtrain_DW.obj.matlabCodegenIsDeleted) {
    rover_sw_pwrtrain_DW.obj.matlabCodegenIsDeleted = true;
    if ((rover_sw_pwrtrain_DW.obj.isInitialized == 1) &&
        rover_sw_pwrtrain_DW.obj.isSetupComplete) {
      Pub_rover_sw_pwrtrain_139.resetPublisherPtr();//();
    }
  }

  /* End of Terminate for MATLABSystem: '<S21>/SinkBlock' */
  /* End of Terminate for SubSystem: '<S4>/If Action Subsystem1' */

  /* Terminate for Atomic SubSystem: '<S3>/lamp_contrl' */
  /* Terminate for MATLABSystem: '<S7>/SinkBlock' */
  if (!rover_sw_pwrtrain_DW.obj_g.matlabCodegenIsDeleted) {
    rover_sw_pwrtrain_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((rover_sw_pwrtrain_DW.obj_g.isInitialized == 1) &&
        rover_sw_pwrtrain_DW.obj_g.isSetupComplete) {
      Pub_rover_sw_pwrtrain_246.resetPublisherPtr();//();
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/SinkBlock' */
  /* End of Terminate for SubSystem: '<S3>/lamp_contrl' */

  /* Terminate for MATLABSystem: '<S10>/SourceBlock' */
  if (!rover_sw_pwrtrain_DW.obj_c.matlabCodegenIsDeleted) {
    rover_sw_pwrtrain_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((rover_sw_pwrtrain_DW.obj_c.isInitialized == 1) &&
        rover_sw_pwrtrain_DW.obj_c.isSetupComplete) {
      Sub_rover_sw_pwrtrain_78.resetSubscriberPtr();//();
    }
  }

  /* End of Terminate for MATLABSystem: '<S10>/SourceBlock' */

  /* Terminate for Enabled SubSystem: '<S4>/If Action Subsystem' */
  /* Terminate for MATLABSystem: '<S13>/SinkBlock' */
  if (!rover_sw_pwrtrain_DW.obj_l.matlabCodegenIsDeleted) {
    rover_sw_pwrtrain_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((rover_sw_pwrtrain_DW.obj_l.isInitialized == 1) &&
        rover_sw_pwrtrain_DW.obj_l.isSetupComplete) {
      Pub_rover_sw_pwrtrain_99.resetPublisherPtr();//();
    }
  }

  /* End of Terminate for MATLABSystem: '<S13>/SinkBlock' */

  /* Terminate for MATLABSystem: '<S14>/SinkBlock' */
  if (!rover_sw_pwrtrain_DW.obj_o.matlabCodegenIsDeleted) {
    rover_sw_pwrtrain_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((rover_sw_pwrtrain_DW.obj_o.isInitialized == 1) &&
        rover_sw_pwrtrain_DW.obj_o.isSetupComplete) {
      Pub_rover_sw_pwrtrain_100.resetPublisherPtr();//();
    }
  }

  /* End of Terminate for MATLABSystem: '<S14>/SinkBlock' */
  /* End of Terminate for SubSystem: '<S4>/If Action Subsystem' */
}

/* Constructor */
rover_sw_pwrtrain::rover_sw_pwrtrain() :
  rover_sw_pwrtrain_U(),
  rover_sw_pwrtrain_B(),
  rover_sw_pwrtrain_DW(),
  rover_sw_pwrtrain_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
rover_sw_pwrtrain::~rover_sw_pwrtrain()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_rover_sw_pwrtrain_T * rover_sw_pwrtrain::getRTM()
{
  return (&rover_sw_pwrtrain_M);
}
