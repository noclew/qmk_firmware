/* Copyright 2021 noclew
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
    L01, L02, L03, L04, L05, L06,               R06, R05, R04, R03, R02, R01,  \
    L07, L08, L09, L10, L11, L12,               R12, R11, R10, R09, R08, R07,  \
    L13, L14, L15, L16, L17, L18,               R18, R17, R16, R15, R14, R13,  \
    L19, L20, L21, L22, L23, L24, L30,     R30, R24, R23, R22, R21, R20, R19,  \
         L25, L26, L27, L28, L29,               R29, R28, R27, R26, R25       \
) { \
    { L01, L02, L03, L04, L05, L06 },\
    { L07, L08, L09, L10, L11, L12 },\
    { L13, L14, L15, L16, L17, L18 },\
    { L19, L20, L21, L22, L23, L24 },\
    { L25, L26, L27, L28, L29, L30 },\
    { R01, R02, R03, R04, R05, R06 },\
    { R07, R08, R09, R10, R11, R12 },\
    { R13, R14, R15, R16, R17, R18 },\
    { R19, R20, R21, R22, R23, R24 },\
    { R25, R26, R27, R28, R29, R30 } \
}
