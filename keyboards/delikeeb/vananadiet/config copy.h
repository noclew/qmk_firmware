// Copyright 2023 noclew (@noclew)
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

/* key matrix size */
#define MATRIX_ROWS 7
#define MATRIX_COLS 7
/* Rows */
#define MATRIX_ROW_PINS { GP28, GP27, GP26, GP1, GP9, GP29, GP8 }
// #define MATRIX_ROW_PINS { F5, F6, F7, D2, B5, F4, B4 }

/* Cols */

#define PIN_USED_74HC595 7

#define SHR_LATCH GP0
#define SHR_CLOCK GP6
#define SHR_DATA  GP7


// #define SHR_LATCH D3
// #define SHR_CLOCK D7
// #define SHR_DATA  E6
#define SHR_COLS { 0x000001, 0x000002, 0x000004, 0x000008, 0x000010, 0x000020, 0x000040,  0x000080}




