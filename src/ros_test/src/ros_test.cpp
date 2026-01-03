/*
 * ros_test.cpp
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

#include "ros_test.h"
#include "ros_test_types.h"
#include "rtwtypes.h"
#include "rmw/qos_profiles.h"
#include <stddef.h>

/* user code (top of source file) */
int vesc_open_noargs(void);
void vesc_close(void);
int vesc_send_duty(double duty);
int vesc_poll(float* v_in, float* t_mos, float* t_motor);
void ros_test::ros_test_Subscriber_setupImpl(const
  ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  sJ4ih70VmKcvCeguWN0mNVF lifespan;
  sJ4ih70VmKcvCeguWN0mNVF liveliness_lease_duration;
  char_T b_zeroDelimTopic[15];
  static const char_T b_zeroDelimTopic_0[15] = "/vesc/cmd_duty";
  qos_profile = rmw_qos_profile_default;

  /* Start for MATLABSystem: '<S5>/SourceBlock' */
  ros_test_B.deadline.sec = 0.0;
  ros_test_B.deadline.nsec = 0.0;
  lifespan.sec = 0.0;
  lifespan.nsec = 0.0;
  liveliness_lease_duration.sec = 0.0;
  liveliness_lease_duration.nsec = 0.0;
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE, ros_test_B.deadline,
                 lifespan, RMW_QOS_POLICY_LIVELINESS_AUTOMATIC,
                 liveliness_lease_duration, (bool)
                 obj->QOSAvoidROSNamespaceConventions);
  for (int32_T i = 0; i < 15; i++) {
    /* Start for MATLABSystem: '<S5>/SourceBlock' */
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_ros_test_15.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
}

void ros_test::ros_test_Publisher_setupImpl(const
  ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  sJ4ih70VmKcvCeguWN0mNVF deadline;
  sJ4ih70VmKcvCeguWN0mNVF lifespan;
  sJ4ih70VmKcvCeguWN0mNVF liveliness_lease_duration;
  static const char_T b_zeroDelimTopic[22] = "/vesc/last_cmd_status";
  qos_profile = rmw_qos_profile_default;

  /* Start for MATLABSystem: '<S4>/SinkBlock' */
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
  for (int32_T i = 0; i < 22; i++) {
    /* Start for MATLABSystem: '<S4>/SinkBlock' */
    ros_test_B.b_zeroDelimTopic[i] = b_zeroDelimTopic[i];
  }

  Pub_ros_test_31.createPublisher(&ros_test_B.b_zeroDelimTopic[0], qos_profile);
}

/* Model step function */
void ros_test::step()
{
  SL_Bus_std_msgs_Float32 rtb_SourceBlock_o2_0;
  SL_Bus_std_msgs_Int32 rtb_BusAssignment1;
  boolean_T b_varargout_1;

  /* MATLABSystem: '<S5>/SourceBlock' */
  b_varargout_1 = Sub_ros_test_15.getLatestMessage(&rtb_SourceBlock_o2_0);

  /* Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  /* Start for MATLABSystem: '<S5>/SourceBlock' */
  if (b_varargout_1) {
    /* CCaller: '<S2>/C Caller2' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion'
     */
    ros_test_B.CCaller2 = vesc_send_duty(static_cast<real_T>
      (rtb_SourceBlock_o2_0.data));
  }

  /* End of Start for MATLABSystem: '<S5>/SourceBlock' */
  /* End of Outputs for SubSystem: '<S5>/Enabled Subsystem' */
  /* End of Outputs for SubSystem: '<Root>/Enabled Subsystem' */

  /* BusAssignment: '<Root>/Bus Assignment1' */
  rtb_BusAssignment1.data = ros_test_B.CCaller2;

  /* MATLABSystem: '<S4>/SinkBlock' */
  Pub_ros_test_31.publish(&rtb_BusAssignment1);
}

/* Model initialize function */
void ros_test::initialize()
{
  /* Start for MATLABSystem: '<S5>/SourceBlock' */
  ros_test_DW.obj_c.QOSAvoidROSNamespaceConventions = false;
  ros_test_DW.obj_c.matlabCodegenIsDeleted = false;
  ros_test_DW.objisempty = true;
  ros_test_DW.obj_c.isSetupComplete = false;
  ros_test_DW.obj_c.isInitialized = 1;
  ros_test_Subscriber_setupImpl(&ros_test_DW.obj_c);
  ros_test_DW.obj_c.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/SinkBlock' */
  ros_test_DW.obj.QOSAvoidROSNamespaceConventions = false;
  ros_test_DW.obj.matlabCodegenIsDeleted = false;
  ros_test_DW.objisempty_d = true;
  ros_test_DW.obj.isSetupComplete = false;
  ros_test_DW.obj.isInitialized = 1;
  ros_test_Publisher_setupImpl(&ros_test_DW.obj);
  ros_test_DW.obj.isSetupComplete = true;

  /* Outputs for Atomic SubSystem: '<Root>/Initialize Function' */
  /* CCaller: '<S3>/C Caller' */
  vesc_open_noargs();

  /* End of Outputs for SubSystem: '<Root>/Initialize Function' */
}

/* Model terminate function */
void ros_test::terminate()
{
  /* Outputs for Atomic SubSystem: '<Root>/Terminate Function' */
  /* CCaller: '<S6>/C Caller1' */
  vesc_close();

  /* End of Outputs for SubSystem: '<Root>/Terminate Function' */

  /* Terminate for MATLABSystem: '<S5>/SourceBlock' */
  if (!ros_test_DW.obj_c.matlabCodegenIsDeleted) {
    ros_test_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((ros_test_DW.obj_c.isInitialized == 1) &&
        ros_test_DW.obj_c.isSetupComplete) {
      Sub_ros_test_15.resetSubscriberPtr();//();
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/SourceBlock' */

  /* Terminate for MATLABSystem: '<S4>/SinkBlock' */
  if (!ros_test_DW.obj.matlabCodegenIsDeleted) {
    ros_test_DW.obj.matlabCodegenIsDeleted = true;
    if ((ros_test_DW.obj.isInitialized == 1) && ros_test_DW.obj.isSetupComplete)
    {
      Pub_ros_test_31.resetPublisherPtr();//();
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/SinkBlock' */
}

/* Constructor */
ros_test::ros_test() :
  ros_test_B(),
  ros_test_DW(),
  ros_test_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
ros_test::~ros_test()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_ros_test_T * ros_test::getRTM()
{
  return (&ros_test_M);
}
