#include "vesc_uart.h"

#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>

static int g_fd = -1;

/* ---------- CONFIGURABLE CONSTANTS ---------- */

/* Default UART device for the VESC on Jetson */
#define VESC_UART_DEVICE   "/dev/ttyACM0"

/* UART baud rate */
#define VESC_UART_BAUD     115200

/* CAN IDs of slave VESCs that should mirror the duty command */
static const uint8_t VESC_CAN_SLAVES[] = {
    10,   /* add more IDs here if you chain more slaves */
};

/* VESC command IDs (from VESC firmware) */
#define COMM_SET_DUTY      5
#define COMM_FORWARD_CAN   34

/* ---------- INTERNAL HELPERS ---------- */

static uint16_t crc16(const uint8_t *data, int len) {
    /* Standard CRC16 implementation used by VESC UART protocol */
    uint16_t crc = 0;
    for (int i = 0; i < len; i++) {
        crc ^= (uint16_t)data[i] << 8;
        for (int j = 0; j < 8; j++) {
            if (crc & 0x8000) {
                crc = (crc << 1) ^ 0x1021;
            } else {
                crc = (crc << 1);
            }
        }
    }
    return crc;
}

static int open_config_port(const char *dev, int baud) {
    int fd = open(dev, O_RDWR | O_NOCTTY);
    if (fd < 0) {
        return -1;
    }

    struct termios tio;
    memset(&tio, 0, sizeof(tio));

    cfmakeraw(&tio);

    speed_t spd = B115200;
    switch (baud) {
        case 9600:   spd = B9600;   break;
        case 19200:  spd = B19200;  break;
        case 38400:  spd = B38400;  break;
        case 57600:  spd = B57600;  break;
        case 115200: spd = B115200; break;
        default:     spd = B115200; break;
    }

    cfsetispeed(&tio, spd);
    cfsetospeed(&tio, spd);

    tio.c_cflag |= (CLOCAL | CREAD);
    tio.c_cflag &= ~(PARENB | CSTOPB | CSIZE);
    tio.c_cflag |= CS8;

    tio.c_cc[VTIME] = 1; /* 0.1s read timeout */
    tio.c_cc[VMIN]  = 0;

    if (tcsetattr(fd, TCSANOW, &tio) != 0) {
        close(fd);
        return -1;
    }

    tcflush(fd, TCIOFLUSH);
    usleep(100000); /* Let things settle a bit */

    return fd;
}

/* Build and send a raw VESC UART frame with given payload */
static int vesc_send_payload(const uint8_t *payload, uint8_t len) {
    if (g_fd < 0) {
        return -1;
    }

    /* frame: [start][len][payload...][crc_hi][crc_lo][stop] */
    uint8_t frame[3 + 256 + 2 + 1]; /* more than enough for small payloads */
    if (len > 256) {
        return -2;
    }

    frame[0] = 2;      /* short frame start byte */
    frame[1] = len;

    memcpy(&frame[2], payload, len);

    uint16_t c = crc16(payload, len);
    frame[2 + len] = (uint8_t)(c >> 8);
    frame[3 + len] = (uint8_t)(c & 0xFF);
    frame[4 + len] = 3;  /* stop byte */

    ssize_t total_len = 2 + len + 2 + 1;
    ssize_t n = write(g_fd, frame, total_len);

    return (n == total_len) ? 0 : -3;
}

/* Send duty to the local VESC (no CAN) */
static int vesc_send_duty_local(double duty) {
    if (g_fd < 0) {
        return -1;
    }

    if (duty > 0.95)  duty = 0.95;
    if (duty < -0.95) duty = -0.95;

    int32_t val = (int32_t)(duty * 100000.0);

    uint8_t payload[1 + 4];
    payload[0] = COMM_SET_DUTY;
    payload[1] = (uint8_t)((val >> 24) & 0xFF);
    payload[2] = (uint8_t)((val >> 16) & 0xFF);
    payload[3] = (uint8_t)((val >> 8)  & 0xFF);
    payload[4] = (uint8_t)(val & 0xFF);

    return vesc_send_payload(payload, sizeof(payload));
}

/* Send duty to a VESC on CAN bus through COMM_FORWARD_CAN */
static int vesc_send_duty_can(double duty, uint8_t can_id) {
    if (g_fd < 0) {
        return -1;
    }

    if (duty > 0.95)  duty = 0.95;
    if (duty < -0.95) duty = -0.95;

    int32_t val = (int32_t)(duty * 100000.0);

    /* inner command: SET_DUTY */
    uint8_t inner[1 + 4];
    inner[0] = COMM_SET_DUTY;
    inner[1] = (uint8_t)((val >> 24) & 0xFF);
    inner[2] = (uint8_t)((val >> 16) & 0xFF);
    inner[3] = (uint8_t)((val >> 8)  & 0xFF);
    inner[4] = (uint8_t)(val & 0xFF);

    /* outer payload: FORWARD_CAN, CAN_ID, inner... */
    uint8_t payload[1 + 1 + sizeof(inner)];
    payload[0] = COMM_FORWARD_CAN;
    payload[1] = can_id;
    memcpy(&payload[2], inner, sizeof(inner));

    return vesc_send_payload(payload, sizeof(payload));
}

/* ---------- PUBLIC API ---------- */

int vesc_open_noargs(void) {
    g_fd = open_config_port(VESC_UART_DEVICE, VESC_UART_BAUD);
    return (g_fd < 0) ? -1 : 0;
}

void vesc_close(void) {
    if (g_fd >= 0) {
        close(g_fd);
        g_fd = -1;
    }
}

int vesc_send_duty(double duty) {
    int status = 0;

    /* 1) Send to master / local VESC */
    int s_local = vesc_send_duty_local(duty);
    if (s_local < 0) {
        status = s_local;
    }

    /* 2) Forward same duty to all configured CAN slaves */
    for (size_t i = 0; i < (sizeof(VESC_CAN_SLAVES) / sizeof(VESC_CAN_SLAVES[0])); i++) {
        int s_can = vesc_send_duty_can(duty, VESC_CAN_SLAVES[i]);
        if (s_can < 0) {
            status = s_can;
        }
    }

    return status;
}

int vesc_poll(float* v_in, float* t_mos, float* t_motor) {
    /* Stub for now. You can later implement COMM_GET_VALUES here. */
    (void)v_in;
    (void)t_mos;
    (void)t_motor;
    return -1;
}