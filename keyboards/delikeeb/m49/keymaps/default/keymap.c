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

#include QMK_KEYBOARD_H
#include "print.h"
#include "wait.h"


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // [_QW] = LAYOUT_7x7(
  //      KC_2    , KC_4    ,
  //     TT(_LWR),  TT(_RSE)),

  // [_LWR] = LAYOUT_7x7(
  //      RGB_TOG , KC_3,
  //      _______,  _______ ),

  // [_RSE] = LAYOUT_7x7(
  //     KC_5 , KC_6  ,
  //     _______, _______),

  // [_ADJ] = LAYOUT_7x7(
  //     RGB_TOG, QK_BOOT  ,
  //      _______ , _______),


  /* BASE
    * -------------------------------------------                               -------------------------------------------
    * |   `  |   1  |   2  |   3  |   4  |   5  |                               |   6  |   7  |   8  |   9  |   0  | Bksp |
    * -------------------------------------------                               -------------------------------------------
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |                               |   Y  |   U  |   I  |   O  |   P  |   \  |
    * ---------------------------------------------------               ---------------------------------------------------
    * | Esc  |   A  |   S  |   D  |   F  |   G  | Bksp  |               | Bksp  |   H  |   J  |   K  |   L  |   ;  |Enter |
    * ---------------------------------------------------    -------    ---------------------------------------------------
    * | Shift|   Z  |   X  |   C  |   V  |   B  | Del   |    | Del |    | Del   |   N  |   M  |   ,  |   .  |   /  |Sft(')|
    * ---------------------------------------------------------------------------------------------------------------------
    *            | Ctrl |  Win  |  Alt  | Lower | Space | LSpc  |  RSpc | Space | Raise |  Alt  |  Left  | Right |
    *            -------------------------------------------------------------------------------------------------
    */

  [_BASE] = LAYOUT(
  KC_GRV,     KC_1   ,    KC_2   ,    KC_3   ,    KC_4   ,    KC_5  ,                                     KC_6   ,    KC_7   ,    KC_8   ,    KC_9   ,    KC_0   ,    KC_BSPC,
  KC_TAB,     KC_Q   ,    KC_W   ,    KC_E   ,    KC_R   ,    KC_T  ,                                     KC_Y   ,    KC_U   ,    KC_I   ,    KC_O   ,    KC_P   ,    KC_BSLS,
  KC_ESC,     KC_A   ,    KC_S   ,    KC_D   ,    KC_F   ,    KC_G  ,     KC_BTN1,            KC_BTN2,    KC_H   ,    KC_J   ,    KC_K   ,    KC_L   ,    KC_SCLN,    KC_ENT ,
  KC_LSFT,    KC_Z   ,    KC_X   ,    KC_C   ,    KC_V   ,    KC_B  ,     KC_BTN2,   KC_DEL,  KC_DEL ,    KC_N   ,    KC_M   ,    KC_COMM,    KC_DOT ,    KC_SLSH,    RSFT_T(KC_QUOT),
              KC_LCTL,    KC_LGUI,    KC_LALT,    KC_V   ,    KC_SPC,     KC_SPC,             KC_SPC,     KC_SPC ,    KC_M   ,    KC_RALT,    KC_LEFT,    KC_RGHT
  )
};
// clang-format on



#ifdef CONSOLE_ENABLE
bool process_record_user(uint16_t keycode, keyrecord_t* record) {

  // If console is enabled, it will print the matrix position and status of each key pressed
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    return true;
}
#endif

// layer_state_t layer_state_set_user(layer_state_t state) {

//     return update_tri_layer_state(state, _LWR, _RSE, _ADJ);
// }


void keyboard_post_init_user(void) {

#ifdef CONSOLE_ENABLE
  debug_enable = true;
  debug_matrix = true;
  debug_keyboard = true;
#endif

}
