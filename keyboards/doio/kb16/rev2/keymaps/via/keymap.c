/* Copyright 2022 DOIO
 * Copyright 2022 HorrorTroll <https://github.com/HorrorTroll>
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

// OLED animation
#include "lib/layer_status/layer_status.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layer_names {
    _BASE,
    _FN
};

// enum layer_keycodes { };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
       ┌───┬───┬───┬───┐   ┌───┐ ┌───┐
       │J0 │J1 │J2 │J3 │   │J0 │ │J1 │
       ├───┼───┼───┼───┤   └───┘ └───┘
       │J4 │J5 │J6 │J7 │
       ├───┼───┼───┼───┤
       │J8 │J9 │J10│J11│      ┌───┐
       ├───┼───┼───┼───┤      │J3 │
       │J12│J13│J14│J15│      └───┘
       └───┴───┴───┴───┘
*/
    /*  Row:    0         1        2        3         4      */
    [_BASE] = LAYOUT(
                JS_0,     JS_1,    JS_2,    JS_3,     JS_0,
                JS_4,     JS_5,    JS_6,    JS_7,     JS_1,
                JS_8,     JS_9,    JS_10,   JS_11,    JS_3,
                JS_12,    JS_13,   JS_14,   JS_15
            ),

/*
       ┌───┬───┬───┬───┐   ┌───┐ ┌───┐
       │Spi│Spd│   │   │   │   │ │TO0│
       ├───┼───┼───┼───┤   └───┘ └───┘
       │Sai│Sad│   │   │
       ├───┼───┼───┼───┤
       │Tog│Mod│Hui│   │      ┌───┐
       ├───┼───┼───┼───┤      │   │
       │   │Vai│Hud│Vad│      └───┘
       └───┴───┴───┴───┘
*/
    /*  Row:    0        1        2        3        4        */
    [FN2] = LAYOUT(
                RGB_SPI, RGB_SPD, _______, QK_BOOT, _______,
                RGB_SAI, RGB_SAD, _______, _______, TO(_BASE),
                RGB_TOG, RGB_MOD, RGB_HUI, _______, _______,
                _______, RGB_VAI, RGB_HUD, RGB_VAD
            ),
};

#ifdef OLED_ENABLE
    bool oled_task_user(void) {
        render_layer_status();

        return true;
    }
#endif

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
[_BASE] = { ENCODER_CCW_CW(JS_7, JS_11), ENCODER_CCW_CW(JS_7, JS_11), ENCODER_CCW_CW(JS_7, JS_11) },
[_FN]   = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};
#endif
