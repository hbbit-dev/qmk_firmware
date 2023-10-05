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

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    CTRL,  // light control keys
};

enum {
    TD_ESC = 0, //bactaholic - ESC + Tilde
    TD_TAB, //bactaholic - TAB + CAPS
    TD_SIGN, //bactaholic - KC_SIGN
    TD_PIPE, //bactaholic - add pipe, mostly for grep lol
    TD_QUIT, //bactaholic - double tap to alt+f4
    };

enum custom_keycodes {
    EXAMPLE = SAFE_RANGE, //bactaholic - example custom keycode
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        TD(TD_ESC),  KC_1   ,  KC_2  ,  KC_3   , KC_4   ,    KC_5   ,    KC_VOLU    ,         KC_PGUP ,   KC_6   ,  KC_7   ,  KC_8   ,  KC_9   ,  KC_0   ,  KC_BSPC    ,
        TD(TD_TAB),  KC_Q   ,  KC_W  ,  KC_E   , KC_R   ,    KC_T   ,    TG(SYMB)   ,         TG(CTRL),   KC_Y   ,  KC_U   ,  KC_I   ,  KC_O   ,  KC_P   ,  TD(TD_PIPE),
        KC_LSFT   ,  KC_A   ,  KC_S  ,  KC_D   , KC_F   ,    KC_G   ,    TD(TD_SIGN),         KC_PGDN ,   KC_H   ,  KC_J   ,  KC_K   ,  KC_L   ,  KC_SCLN,  KC_QUOT    ,
        KC_HOME   ,  KC_Z   ,  KC_X  ,  KC_C   , KC_V   ,    KC_B   ,                                     KC_N   ,  KC_M   ,  KC_COMM,  KC_DOT ,  KC_SLSH,  KC_DEL     ,
        KC_LCTL   ,  KC_LALT,  KC_INS,  KC_LBRC, KC_RBRC,    TD(TD_QUIT),                                 KC_MPLY,  KC_UP  ,  KC_DOWN,  KC_LEFT,  KC_RGHT,  KC_RCTL    ,
                                         KC_SPC , KC_BSPC,    KC_LGUI,                                     KC_EQL  ,  KC_MINS,  KC_ENT
    ),

    [SYMB] = LAYOUT_moonlander(
        TD_ESC    ,  KC_F1  ,  KC_F2  ,  KC_F3  ,  KC_F4  ,  KC_F5  ,    KC_VOLU    ,         KC_PGUP,   KC_F6  ,  KC_F7  ,  KC_F8  ,  KC_F9  ,  KC_F10 ,  KC_F11 ,
        TD_TAB    ,  KC_Q   ,  KC_W   ,  KC_E   ,  KC_R   ,  KC_T   ,    TG(SYMB)   ,         TG(CTRL),  KC_Y   ,  KC_U   ,  KC_I   ,  KC_O   ,  KC_P   ,  TD_PIPE,
        KC_LSFT   ,  KC_A   ,  KC_S   ,  KC_D   ,  KC_F   ,  KC_G   ,    TD(TD_SIGN),         KC_PGDN,   KC_H   ,  KC_J   ,  KC_K   ,  KC_L   ,  KC_SCLN,  KC_QUOT,
        KC_HOME   ,  KC_Z   ,  KC_X   ,  KC_C   ,  KC_V   ,  KC_B   ,                                    KC_N   ,  KC_M   ,  KC_COMM,  KC_DOT ,  KC_SLSH,  KC_DEL ,
        KC_LCTL   ,  KC_LALT,  KC_INS ,  KC_LBRC,  KC_RBRC,  TD(TD_QUIT),                                KC_MPLY,  KC_UP  ,  KC_DOWN,  KC_LEFT,  KC_RGHT,  KC_RCTL,
                                          KC_SPC ,  KC_BSPC,  KC_LGUI,           KC_EQL ,  KC_MINS, KC_ENT
    ),

    [CTRL] = LAYOUT_moonlander(
        TD_ESC    ,  KC_F1  ,  KC_F2  ,  KC_F3  ,  KC_F4  ,  KC_F5  ,  KC_VOLU    ,         KC_PGUP ,  KC_F6  ,  KC_F7  ,  KC_F8  ,  KC_F9  ,  KC_F10 ,  KC_F11 ,
        _______   ,  RGB_MOD,  _______,  _______,  _______,  AC_TOGG,  TG(SYMB)   ,         TG(CTRL),  _______,  KC_UP  ,  _______,  _______,  _______,  _______,
        _______   ,  RGB_HUI,  RGB_SAI,  RGB_VAI,  RGB_SPI,  _______,  TD(TD_SIGN),         KC_PGDN ,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  _______,  _______,
        _______   ,  RGB_HUD,  RGB_SAD,  RGB_VAD,  RGB_SPD,  _______,                                  _______,  _______,  _______,  _______,  _______,  _______,
        _______   ,  _______,  _______,  _______,  _______,  _______,                                  _______,  _______,  _______,  _______,  _______,  _______,
                                         _______,  _______,  _______,                                  _______, _______, _______
    ),
};

void send_signature(tap_dance_state_t *state, void *user_data)
{
    if(state->count == 1) {
        SEND_STRING(SS_TAP(X_VOLD));
    } else {
        SEND_STRING("bactaholic - ");
    }
}

void send_quit(tap_dance_state_t *state, void *user_data)
{
    if(state->count == 1) {
        SEND_STRING(SS_TAP(X_HOME)SS_DOWN(X_LSFT)SS_TAP(X_END)SS_UP(X_LSFT));
    }
    if(state->count == 2) {
        SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_F4)SS_UP(X_LALT));
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_GRV),
    [TD_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_CAPS),
    [TD_SIGN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, send_signature, NULL),
    [TD_PIPE] = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, KC_PIPE),
    [TD_QUIT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, send_quit, NULL),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case EXAMPLE:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_F4));
                return false;
            }
            break;
    }
    return true;
}