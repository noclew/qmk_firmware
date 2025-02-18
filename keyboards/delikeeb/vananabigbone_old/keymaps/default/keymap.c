/* Copyright 2020 noclew
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
#include QMK_KEYBOARD_H


// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
};

// Defines the keycodes used by our macros in process_record_user
enum vananaBB_keycodes {
    BASE = SAFE_RANGE,
    LOWER,
    RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* BASE
     * -------------------------------------------                                   -------------------------------------------
     * |   `  |   1  |   2  |   3  |   4  |   5  |                                   |   6  |   7  |   8  |   9  |   0  | Bksp |
     * -------------------------------------------                                   -------------------------------------------
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |                                   |   Y  |   U  |   I  |   O  |   P  |   \  |
     * -------------------------------------------   ---------            ---------  --------------------------------------------
     * | Esc  |   A  |   S  |   D  |   F  |   G  |   | Bksp  |           | Bksp  |   |   H  |   J  |   K  |   L  |   ;  |Enter |
     * -------------------------------------------   --------- --------- ---------   -------------------------------------------
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   | Del   | | Del   | | Del   |   |   N  |   M  |   ,  |   .  |   /  |Sft(')|
     * -------------------------------------------   --------- --------- ---------   -------------------------------------------
     *             | GUI  |  Alt | Ctrl |Lower |Space |                          |Space |Raise |Alt   | Left | Right|
     *             ------------------------------------                          ------------------------------------
     */

    [_BASE] = LAYOUT(
    KC_GRV,     KC_1   ,    KC_2   ,    KC_3   ,    KC_4   ,    KC_5  ,                                   KC_6   ,    KC_7   ,    KC_8   ,    KC_9   ,    KC_0   ,    KC_BSPC,
    KC_TAB,     KC_Q   ,    KC_W   ,    KC_E   ,    KC_R   ,    KC_T  ,                                   KC_Y   ,    KC_U   ,    KC_I   ,    KC_O   ,    KC_P   ,    KC_BSLS,
    KC_ESC,     KC_A   ,    KC_S   ,    KC_D   ,    KC_F   ,    KC_G  ,     KC_BTN1,          KC_BTN2,    KC_H   ,    KC_J   ,    KC_K   ,    KC_L   ,    KC_SCLN,    KC_ENT ,
    KC_LSFT,    KC_Z   ,    KC_X   ,    KC_C   ,    KC_V   ,    KC_B  ,     KC_BTN2, KC_DEL , KC_DEL ,    KC_N   ,    KC_M   ,    KC_COMM,    KC_DOT ,    KC_SLSH,    RSFT_T(KC_QUOT),
                KC_LCTL,    KC_LGUI,    KC_LALT,    LOWER  ,    KC_SPC,                                   KC_SPC ,    RAISE  ,    KC_RALT,    KC_LEFT,    KC_RGHT
    ),

    [_LOWER] = LAYOUT(
    KC_F1  ,    KC_F2  ,    KC_F3  ,    KC_F4  ,    KC_F5  ,    KC_F6  ,                                  KC_F7  ,    KC_F8  ,    KC_F9  ,    KC_F10 ,    KC_F11 ,    KC_F12 ,
    KC_BSPC,    KC_SLSH,    KC_7   ,    KC_8   ,    KC_9   ,    KC_PPLS,                                  KC_CIRC,    KC_LBRC,    KC_RBRC,    KC_AT  ,    KC_EXLM,    _______,
    KC_EQL ,    KC_0   ,    KC_4   ,    KC_5   ,    KC_6   ,    KC_MINS,    KC_LEFT,          KC_LEFT,    KC_PIPE,    KC_LPRN,    KC_RPRN,    KC_HASH,    KC_DQUO,    _______,
    KC_ENT ,    KC_PAST,    KC_1   ,    KC_2   ,    KC_3   ,    KC_UNDS,    KC_RGHT, KC_RGHT, KC_RGHT,    KC_DLR ,    KC_LCBR,    KC_RCBR,    KC_AMPR,    KC_PERC,    _______,
                _______,    _______,    _______,    _______,    _______,                                  _______,    _______,    _______,    _______,    _______
    ),

    [_RAISE] = LAYOUT(
    _______,    _______,    _______,    _______,    _______,    _______,                                  _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,                                  _______,    KC_HOME,    KC_UP  ,    KC_DEL ,    KC_END ,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,    KC_UP  ,          KC_UP  ,    KC_BSPC,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_QUOT,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,    KC_DOWN, KC_DOWN, KC_DOWN,    _______,    KC_PGUP,    _______,    KC_PGDN,    _______,    _______,
                _______,    _______,    _______,    _______,    _______,                                  _______,    _______,    _______,    _______,    _______
    ),

    [_ADJUST] = LAYOUT(
    QK_BOOT,    KC_Z,       _______,    _______,    _______,    _______,                                  _______,    _______,    _______,    _______,    _______,    DEBUG  ,
    _______,    RGB_TOG,    RGB_RMOD,   RGB_MOD,    RGB_VAD,    RGB_VAI,                                  _______,    _______,    _______,    _______,    _______,    _______,
    KC_CAPS,    _______,    RGB_HUD,    RGB_HUI,    RGB_SAD,    RGB_SAI,    KC_VOLU,          KC_VOLU,    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,    KC_VOLD, KC_VOLD, KC_VOLD,    _______,    _______,    _______,    _______,    _______,    _______,
                _______,    _______,    _______,    _______,    _______,                                  _______,    _______,    _______,    _______,    _______
    )
};


bool set_scrolling = false;


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
        return true;

        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
        return true;

        case QK_BOOT:
            if (record->event.pressed) {
                #ifdef AUDIO_ENABLE
                    stop_all_notes();
                    PLAY_SONG(song_coin);
                #endif
            }
        return true;
    }
    return true;
}



// report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
//     if (set_scrolling) {
//         mouse_report.h = mouse_report.x;
//         mouse_report.v = mouse_report.y;
//         mouse_report.x = 0;
//         mouse_report.y = 0;
//     }
//     return mouse_report;
// }

bool encoder_update_user(uint8_t index, bool clockwise) {
    /* With an if statement we can check which encoder was turned. */
    if (index == 0) { /* First encoder */
        /* And with another if statement we can check the direction. */
        if (clockwise) {
            if (IS_LAYER_ON(_LOWER)){
                tap_code(KC_RIGHT);
            } else if (IS_LAYER_ON(_RAISE)){
                tap_code(KC_DOWN);
            } else {
                tap_code(KC_VOLU);
            }
        } else {
            if (IS_LAYER_ON(_LOWER)){
                tap_code(KC_LEFT);
            } else if (IS_LAYER_ON(_RAISE)){
                tap_code(KC_UP);
            } else {
                tap_code(KC_VOLD);
            }
        }

    } else if (index == 1) { /* Second encoder. Only supported by Elite-C */
        if (clockwise) {
            if (IS_LAYER_ON(_LOWER)){
                tap_code(KC_RIGHT);
            } else if (IS_LAYER_ON(_RAISE)){
                tap_code(KC_DOWN);
            } else {
                tap_code(KC_VOLU);
            }
        } else {
            if (IS_LAYER_ON(_LOWER)){
                tap_code(KC_LEFT);
            } else if (IS_LAYER_ON(_RAISE)){
                tap_code(KC_UP);
            } else {
                tap_code(KC_VOLD);
            }
        }
    }
    return true;
}

// disable wheel


// OLED task calls
// #ifdef OLED_ENABLE
// bool oled_task_user(void) {
//     // Host Keyboard Layer Status
//     oled_write_P(PSTR("Layer: "), false);

//     switch (get_highest_layer(layer_state)) {
//         case _BASE:
//             oled_write_P(PSTR("Default\n"), false);
//             break;
//         case _LOWER:
//             oled_write_P(PSTR("FN\n"), false);
//             break;
//         case _RAISE:
//             oled_write_P(PSTR("ADJ\n"), false);
//             break;
//         default:
//             // Or use the write_ln shortcut over adding '\n' to the end of your string
//             oled_write_ln_P(PSTR("Undefined"), false);
//     }

//     // Host Keyboard LED Status
//     led_t led_state = host_keyboard_led_state();
//     oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
//     oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
//     oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    
//     return false;
// }


// static void render_logo(void) {
//     static const char PROGMEM qmk_logo[] = {
//         0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
//         0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
//         0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
//     };

//     oled_write_P(qmk_logo, false);
// }
// #endif

#include <stdio.h>

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   if (record->event.pressed) {
//     set_keylog(keycode, record);
//   }
//   return true;
// }
#endif // OLED_ENABLE