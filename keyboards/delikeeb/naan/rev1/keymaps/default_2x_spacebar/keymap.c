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
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _MAC,
    _ADJUST
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    LOWER = SAFE_RANGE,
    RAISE,
    ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT_2x_spacebar(
        KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINUS,   KC_BSPC,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSLS,
        KC_ESC,     KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_ENT,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    RSFT_T(KC_QUOT),    KC_DEL,
        KC_LCTL,    KC_LGUI,    KC_LALT,    LOWER,      KC_SPC,     KC_SPC,     RAISE,      KC_RALT,    KC_DOWN,    KC_LEFT,    KC_RGHT
    ),

    [_LOWER] = LAYOUT_2x_spacebar(
        KC_DEL ,    KC_F1  ,    KC_F2  ,    KC_F3  ,    KC_F4  ,    KC_F5  ,    KC_F6  ,    KC_F7  ,    KC_F8  ,    KC_F9  ,    KC_F10 ,    KC_F11 ,    KC_F12 ,
        _______,    KC_SLSH,    KC_7   ,    KC_8   ,    KC_9   ,    KC_PPLS,    KC_CIRC,    KC_LBRC,    KC_RBRC,    KC_AT  ,    KC_EXLM,    KC_DLR,
        KC_EQL ,    KC_0   ,    KC_4   ,    KC_5   ,    KC_6   ,    KC_MINS,    KC_PIPE,    KC_LPRN,    KC_RPRN,    KC_HASH,    KC_DQUO,    _______,
        KC_ENT ,    KC_PAST,    KC_1   ,    KC_2   ,    KC_3   ,    KC_UNDS,    KC_DLR ,    KC_LCBR,    KC_RCBR,    KC_AMPR,    KC_PERC,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),

    [_RAISE] = LAYOUT_2x_spacebar(
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_HOME,    KC_BSPC,    KC_DEL ,    KC_END ,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    KC_QUOT,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_PGUP,    _______,    _______,    KC_PGDN,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),

    [_MAC] = LAYOUT_2x_spacebar(
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        KC_LCTL,    _______,    KC_LALT,    KC_LGUI,    _______,    _______,    _______,    _______,    _______,    _______,    _______

    ),

    [_ADJUST] = LAYOUT_2x_spacebar(
        RESET  ,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    DEBUG  ,    _______,
        _______,    RGB_TOG,    RGB_RMOD,   RGB_MOD,    RGB_VAD,    RGB_VAI,    _______,    _______,    _______,    _______,    _______,    _______,
        KC_CAPS,    _______,    RGB_HUD,    RGB_HUI,    RGB_SAD,    RGB_SAI,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    )
};

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
        return false;

        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
        return false;

        case RESET:
            if (record->event.pressed) {
                #ifdef AUDIO_ENABLE
                    stop_all_notes();
                    PLAY_SONG(song_coin);
                #endif
            }
        return false;
    }
    return true;
}


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

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    //render_logo();
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("_BASE\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("_LOWER\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("_RAISE\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}

#endif
