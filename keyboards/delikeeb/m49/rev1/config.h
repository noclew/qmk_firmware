/*
Copyright 2021-2022 Alin M Elena <alinm.elena@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
#pragma once

///////////////////////////////////////////////////// SPI Setting ///////////////////////////////////////////////////// 
#define SPI_DRIVER SPID0

// “SPI divisor” sets how fast the SPI clock runs by dividing down the microcontroller’s main clock. 
// If MCU runs at 16 MHz and your SPI divisor is set to 8, then your SPI clock will run at 2 MHz (16 MHz / 8).
// it was 32.
#define SPI_DIVISOR 4

/* Shift Register Clock/Latch configuration (MCU to ShiftRegister.RCLK - 12) */
#define SPI_LATCH_PIN GP0

/* Shift Register SPI Serial Clock configuration (MCU to ShiftRegister.SRCLK - 11) */
#define SPI_SCK_PIN GP6

/* Shift Register SPI Data Out configuration (MCU to ShiftRegister.SER - 14) */
#define SPI_MISO_PIN GP4

#define SPI_MOSI_PIN GP7



///////////////////////////////////////////////////// Matrix Setting ///////////////////////////////////////////////////// 
// Define Row Pins
#define MATRIX_ROWS 9
#define MATRIX_COLS 8

// Define Row Pins
#define ROWS  {GP10, GP1, GP26, GP27, GP8, GP28, GP29, GP9, GP18}



//0x0001, 0x0002, 0x0004, 0x0008, 0x0010, 0x0020, 0x0040, 0x0080, 0x0100, 0x0200, 0x0400, 0x0800, 0x1000, 0x2000, 0x4000, 0x8000
// 1QA     1QB     1QC     1QD     1QE     1QF     1QG     1QH     2QA     2QB     2QC     2QD     2QE     2QF     2QG     2QH

//              C0      C1       C2    C3      C4      C5      C6
//              1QH     1QF     1QG    1QE    1QD      1QC    1QB
//#define COLS { 0x0080, 0x0020, 0x0040, 0x0010, 0x0008, 0x0004, 0x0002}

#define COLS { 0x0010, 0x0080, 0x0040, 0x0020, 0x0002, 0x0004, 0x0008, 0x0001}

///////////////////////////////////////////////////// 2040 Setting ///////////////////////////////////////////////////// 

/* Double tap reset button to enter bootloader */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17



///////////////////////////////////////////////////// 2040 Setting ///////////////////////////////////////////////////// 
#define POINTING_DEVICE_DEBUG
#define PMW33XX_CS_PIN GP5 // or #define CIRQUE_PINNACLE_SPI_CS_PIN GP5
// #define POINTING_DEVICE_MOTION_PIN GP19