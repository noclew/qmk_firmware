// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "print.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /* BASE
     * -------------------------------------------                     -------------------------------------------
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |                     |   Y  |   U  |   I  |   O  |   P  |   \  |
     * -------------------------------------------                     -------------------------------------------
     * | Esc  |   A  |   S  |   D  |   F  |   G  |                     |   H  |   J  |   K  |   L  |   ;  |Enter |
     * --------------------------------------------------       --------------------------------------------------
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   B  |       |   B  |   N  |   M  |   ,  |   .  |   /  |Sft(')|
     * ------------------------------------------------------------------------------------------------------------
     *        | GUI  |  Alt | Ctrl |Lower |Space |      | ROT  |       |Space |Raise |Alt   | Left | Right|
     *        ------------------------------------      --------       ------------------------------------
     */
    [0] = LAYOUT_ortho_4x4(
        KC_TAB,     KC_Q   ,    KC_W   ,    KC_E   ,    KC_R   ,    KC_T  ,                                          KC_Y   ,    KC_U   ,    KC_I   ,    KC_O   ,    KC_P   ,    KC_BSLS,
        KC_ESC,     KC_A   ,    KC_S   ,    KC_D   ,    KC_F   ,    KC_G  ,                                          KC_H   ,    KC_J   ,    KC_K   ,    KC_L   ,    KC_SCLN,    KC_ENT ,
        KC_LSFT,    KC_Z   ,    KC_X   ,    KC_C   ,    KC_V   ,    KC_B  ,     KC_DEL ,                KC_BSPC,     KC_N   ,    KC_M   ,    KC_COMM,    KC_DOT ,    KC_SLSH,    RSFT_T(KC_QUOT),
                    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_GRV ,    KC_SPC,                 KC_BSPC,                 KC_SPC ,    KC_GRV ,    KC_RALT,    KC_LEFT,    KC_RGHT
        )
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif 
  return true;
}