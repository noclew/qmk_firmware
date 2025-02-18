// Copyright 2025 noclew (@noclew)
// 595 codes were borrowed from awesome Alin M Elena <alinm.elena@gmail.com>, DR.Faustroll
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

////////////////////////////////////// General Setting ////////////////////////////////////// 

/* Double tap reset button to enter bootloader */
// Ferefence https://docs.qmk.fm/platformdev_rp2040#double-tap
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U // Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17 // Specify a optional status led by GPIO number which blinks when entering the bootloader

////////////////////////////////////// SPI Setting ////////////////////////////////////// 

#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP6
#define SPI_MOSI_PIN GP7
#define SPI_MISO_PIN GP4   

////////////////////////////////////// Matrix Setting ////////////////////////////////////// 

#define MATRIX_ROWS 9
#define MATRIX_COLS 8

// Define Row Pins
#define ROWS  {GP10, GP1, GP26, GP27, GP8, GP28, GP29, GP9, GP18}


////////////////////////////////////// Shifter Setting ////////////////////////////////////// 
/*
ShiftRegister SN74HC595N

1
QB |1    16| VCC
QC |2    15| QA
QD |3    14| SER data
QE |4    13| OE
QF |5    12| RCLK latch
QG |6    11| SRCLK clock
QH |7    10| SRCLR
 G |8    9 | QH*

SRCLR - 10 to VCC
OE - G
It uses four pins from the MCU to provide 16 output pins */

#define SPI_DIVISOR 4
#define SPI_LATCH_PIN GP0 
//0x0001, 0x0002, 0x0004, 0x0008, 0x0010, 0x0020, 0x0040, 0x0080, 0x0100, 0x0200, 0x0400, 0x0800, 0x1000, 0x2000, 0x4000, 0x8000
// 1QA     1QB     1QC     1QD     1QE     1QF     1QG     1QH     2QA     2QB     2QC     2QD     2QE     2QF     2QG     2QH

//              C0      C1       C2    C3      C4      C5      C6
//              1QH     1QF     1QG    1QE    1QD      1QC    1QB
//#define COLS { 0x0080, 0x0020, 0x0040, 0x0010, 0x0008, 0x0004, 0x0002}

#define COLS { 0x0010, 0x0080, 0x0040, 0x0020, 0x0002, 0x0004, 0x0008, 0x0001}

////////////////////////////////////// OLED 1306 ////////////////////////////////////// 
#ifdef OLED_ENABLE
#    define OLED_DISPLAY_128X64
#define I2C1_SCL_PIN        GP3
#define I2C1_SDA_PIN        GP2
#define I2C_DRIVER I2CD1
#define OLED_BRIGHTNESS 128
#define OLED_FONT_H "keyboards/delikeeb/trackball2/lib/glcdfont.c"
#endif