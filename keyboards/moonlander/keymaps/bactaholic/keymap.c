/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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


//the following hackjob is @bactaholic's fault


#include QMK_KEYBOARD_H
#include "version.h"
#include "features/autocorrection.h"

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    CTRL,  // media keys
};

enum tap_dance_keys {
    TD_ESC = 0, //bh - ESC + Tilde
    TD_TAB = 0, //bh - TAB + CAPS
    TD_SIGN = 0, //bh - KC_SIGN
    TD_PIPE = 0, //bh - add pipe, mostly for grep lol
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
    KC_SIGN, //bh - Create custom keycode
    KC_QUIT,
    SELWORD,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        TD_ESC ,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_VOLU,           KC_PGUP,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        TD_TAB ,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    TG(SYMB),         TG(CTRL),  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    TD_PIPE,
        KC_LSFT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    TD_SIGN,           KC_PGDN,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_HOME,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                 KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_DEL,
        KC_LCTL,  KC_LALT, KC_INS,  KC_LBRC, KC_RBRC,         KC_QUIT,           KC_MPLY,   KC_UP,   KC_DOWN, KC_LEFT, KC_RGHT, KC_RCTL,
                                            KC_SPC,  KC_BSPC, KC_LGUI,           KC_EQL ,   KC_MINS,  KC_ENT
    ),

    [SYMB] = LAYOUT_moonlander(
        TD_ESC ,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_VOLU,           KC_PGUP, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        TD_TAB ,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    TG(BASE),         TG(CTRL),  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    TD_PIPE,
        KC_LSFT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_SIGN,           KC_PGDN,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_HOME,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                 KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_DEL,
        KC_LCTL,  KC_LALT, KC_INS,  KC_LBRC, KC_RBRC,         KC_QUIT,           KC_MPLY,  KC_UP, KC_DOWN, KC_LEFT, KC_RGHT, KC_RCTL,
                                            KC_SPC,  KC_BSPC, KC_LGUI,           KC_EQL ,  KC_MINS, KC_ENT
    ),

    [CTRL] = LAYOUT_moonlander(
        TD_ESC ,   KC_F1, KC_F2,   KC_F3  , KC_F4,   KC_F5,    KC_VOLU,           KC_PGUP, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, RGB_MOD, _______, _______, _______, _______,  TG(SYMB),         TG(BASE), _______, _______,  _______,  _______,  _______, _______,
        _______, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______,  KC_SIGN,           KC_PGDN, _______, _______,  _______,  _______,  _______, _______,
        _______, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______,                              _______, _______,  _______,  _______,  _______, _______,
        _______,  _______, _______, _______, _______,          _______,           _______,          _______,  _______,  _______,  _______,  _______,
                                            _______, _______, _______,            _______, _______, _______
    ),
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_TILD),
    [TD_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_SIGN),
    [TD_SIGN] = ACTION_TAP_DANCE_DOUBLE(KC_KB_VOLUME_DOWN, KC_SIGN),
    [TD_PIPE] = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, KC_PIPE),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case KC_SIGN:
                SEND_STRING("bactaholic - ");
                return false;
                break;
            case KC_QUIT:
                SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_F4));
                return false;
                break;
        }
    }
    return true;
}
