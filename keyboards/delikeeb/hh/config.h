// Copyright 2022 noclew (@noclew)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT


#pragma once

#define MASTER_RIGHT

#define SERIAL_DEBUG

#define POINTING_DEVICE_CS_PIN GP6 // or #define CIRQUE_PINNACLE_SPI_CS_PIN GP5
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP2
#define SPI_MOSI_PIN GP3
#define SPI_MISO_PIN GP4
#define POINTING_DEVICE_INVERT_X 
#define POINTING_DEVICE_INVERT_Y
#define POINTING_DEVICE_MOTION_PIN GP9
#define POINTING_DEVICE_TASK_THROTTLE_MS 1

// #define ENCODERS_PAD_A { }
// #define ENCODERS_PAD_B { }
// #define ENCODER_RESOLUTIONS { }
// #define ENCODERS_PAD_A_RIGHT { GP1 }
// #define ENCODERS_PAD_B_RIGHT { GP0 } 
// #define ENCODER_RESOLUTIONS_RIGHT { 4 }

