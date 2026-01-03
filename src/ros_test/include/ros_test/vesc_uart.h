#ifndef VESC_UART_H
#define VESC_UART_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Open the default VESC UART port.
 * Currently hardcoded to /dev/ttyACM0 at 115200 baud.
 * Returns 0 on success, <0 on error.
 */
int  vesc_open_noargs(void);

/**
 * Close the UART port if open.
 */
void vesc_close(void);

/**
 * Send a duty-cycle command.
 *
 * - duty in range [-1.0, 1.0], internally clamped to [-0.95, 0.95]
 * - Sends to local VESC over UART
 * - Also forwards the same duty to one or more CAN slaves
 *
 * Returns 0 on success, <0 if write fails or port not open.
 */
int  vesc_send_duty(double duty);

/**
 * Placeholder for future telemetry reading.
 * Currently just a stub returning -1.
 */
int  vesc_poll(float* v_in, float* t_mos, float* t_motor);

#ifdef __cplusplus
}
#endif

#endif /* VESC_UART_H */