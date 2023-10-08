#include QMK_KEYBOARD_H
#include "version.h"

#define KC_UNDO LCTL(KC_Z)
#define KC_CUT  LCTL(KC_X)
#define KC_COPY LCTL(KC_C)
#define KC_PSTE LCTL(KC_V)

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  EXAMPLE,
};

enum tap_dance_codes {
  QUIT,
  BKTK,
  CAPS,
  SIGN,
  PIPE,
  HYPH,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [MSTR] = LAYOUT_voyager(
    TD(BKTK), KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,        KC_6   ,TD(SIGN), KC_8   , KC_9   , KC_0   , KC_BSPC ,       
    TD(CAPS), KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , TD(PIPE),      
    KC_LSFT , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,        KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, TD(HYPH),
    KC_LCTL , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,        KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RCTRL,       
                                        TD(QUIT), KC_SPC ,        KC_ENT , LT(CTRL,KC_EQL)
  ),
  [CTRL] = LAYOUT_voyager(
    _______ , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,           KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11 ,
    _______ , RGB_MOD  , _______  , _______  , _______  , KC_VOLU  ,           _______  , _______  , _______  , _______  , _______  , KC_F12 ,      
    _______ , RGB_HUI  , RGB_SAI  , RGB_VAI  , RGB_SPI  , KC_VOLD  ,           _______  , _______  , _______  , _______  , KC_UP    , _______,
    _______ , RGB_HUD  , RGB_SAD  , RGB_VAD  , RGB_SPD  , _______  ,           _______  , _______  , _______  , KC_LEFT  , KC_DOWN  , KC_RGHT,       
                                               _______  , _______  ,   LT(LGHT,KC_ENT)  , _______
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case EXAMPLE:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
  }
  return true;
}


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[1];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void td_alt_f4(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 1) {
      case SINGLE_TAP: register_code16(KC_LGUI); break;
    }
    if(state->count == 2) {
        case SINGLE_HOLD: register_code16(KC_LALT); break;
        case SINGLE_TAP: register_code16(KC_F4); break;
    }
}

void td_backtick(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 1) {
      case SINGLE_TAP: register_code16(KC_ESC); break;
    }
    if(state->count == 2) {
        case SINGLE_TAP: register_code16(KC_GRV); break;
    }
}

void td_caps(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 1) {
    case SINGLE_TAP: register_code16(KC_TAB); break;
  } 
  if(state->count == 2) {
    case SINGLE_TAP: register_code16(KC_CAPS); break;
  }
}

void td_sign_code(qk_tap_dance_state_t *state, void *user_data){
  if(state->count == 1){
    case SINGLE_TAP: register_code16(KC_7); break;
  }
  if(state->count == 2){
    SEND_STRING(" bactaholic - ")
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [QUIT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_alt_f4, NULL),
        [BKTK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_backtick, NULL),
        [CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_caps, NULL),
        [SIGN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_sign_code, NULL),
        [PIPE] = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, KC_PIPE),
        [HYPH] = ACTION_TAP_DANCE_DOUBLE(KC_QUOTE, KC_MINS),
};
