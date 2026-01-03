// Copyright 2022-2024 The MathWorks, Inc.
// Generated 30-Nov-2025 12:04:20
#ifndef _SLROS2_INITIALIZE_H_
#define _SLROS2_INITIALIZE_H_
#include "rover_sw_pwrtrain_types.h"
// Generic pub-sub header
#include "slros2_generic_pubsub.h"
#ifndef SET_QOS_VALUES
#define SET_QOS_VALUES(qosStruct, _history, _depth, _durability, _reliability, _deadline \
, _lifespan, _liveliness, _lease_duration, _avoid_ros_namespace_conventions)             \
    {                                                                                    \
        qosStruct.history = _history;                                                    \
        qosStruct.depth = _depth;                                                        \
        qosStruct.durability = _durability;                                              \
        qosStruct.reliability = _reliability;                                            \
        qosStruct.deadline.sec = _deadline.sec;                                          \
        qosStruct.deadline.nsec = _deadline.nsec;                                        \
        qosStruct.lifespan.sec = _lifespan.sec;                                          \
        qosStruct.lifespan.nsec = _lifespan.nsec;                                        \
        qosStruct.liveliness = _liveliness;                                              \
        qosStruct.liveliness_lease_duration.sec = _lease_duration.sec;                   \
        qosStruct.liveliness_lease_duration.nsec = _lease_duration.nsec;                 \
        qosStruct.avoid_ros_namespace_conventions = _avoid_ros_namespace_conventions;    \
    }
#endif
inline rclcpp::QoS getQOSSettingsFromRMW(const rmw_qos_profile_t& qosProfile) {
    rclcpp::QoS qos(rclcpp::QoSInitialization::from_rmw(qosProfile));
    if (RMW_QOS_POLICY_DURABILITY_TRANSIENT_LOCAL == qosProfile.durability) {
        qos.transient_local();
    } else {
        qos.durability_volatile();
    }
    if (RMW_QOS_POLICY_RELIABILITY_RELIABLE == qosProfile.reliability) {
        qos.reliable();
    } else {
        qos.best_effort();
    }
    return qos;
}
// rover_sw_pwrtrain/led_controls/lamp_contrl/Publish1
extern SimulinkPublisher<std_msgs::msg::Int32,SL_Bus_std_msgs_Int32> Pub_rover_sw_pwrtrain_246;
// rover_sw_pwrtrain/motor_controls/If Action Subsystem/Publish1
extern SimulinkPublisher<std_msgs::msg::Int32,SL_Bus_std_msgs_Int32> Pub_rover_sw_pwrtrain_99;
// rover_sw_pwrtrain/motor_controls/If Action Subsystem/Publish2
extern SimulinkPublisher<std_msgs::msg::Int32,SL_Bus_std_msgs_Int32> Pub_rover_sw_pwrtrain_100;
// rover_sw_pwrtrain/motor_controls/If Action Subsystem1/Publish1
extern SimulinkPublisher<std_msgs::msg::Int32,SL_Bus_std_msgs_Int32> Pub_rover_sw_pwrtrain_138;
// rover_sw_pwrtrain/motor_controls/If Action Subsystem1/Publish2
extern SimulinkPublisher<std_msgs::msg::Int32,SL_Bus_std_msgs_Int32> Pub_rover_sw_pwrtrain_139;
// rover_sw_pwrtrain/motor_controls/If Action Subsystem1/Subscribe
extern SimulinkSubscriber<std_msgs::msg::Float32,SL_Bus_std_msgs_Float32> Sub_rover_sw_pwrtrain_140;
// rover_sw_pwrtrain/motor_controls/If Action Subsystem1/Subscribe1
extern SimulinkSubscriber<std_msgs::msg::Float32,SL_Bus_std_msgs_Float32> Sub_rover_sw_pwrtrain_141;
// rover_sw_pwrtrain/motor_controls/If Action Subsystem1/Subscribe2
extern SimulinkSubscriber<std_msgs::msg::Float32,SL_Bus_std_msgs_Float32> Sub_rover_sw_pwrtrain_173;
// rover_sw_pwrtrain/motor_controls/Subscribe2
extern SimulinkSubscriber<std_msgs::msg::Bool,SL_Bus_std_msgs_Bool> Sub_rover_sw_pwrtrain_78;
#endif
