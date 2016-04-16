#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "keymap_extras/keymap_bepo.h"

#define BASE 0 // default layer
#define QWER 1 // qwerty compat layer
#define SQWER 2 // shifted qwerty compat layer
#define AQWER 3 // alted qwerty compat layer
#define FNX 4 // function keys
#define NUM 5 // numeric keypad keys
#define NAV 6 // navigation keys
#define MSE 7 // mouse keys

#define KP_00 0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Base layer
 *
 * ,--------------------------------------------------.                                  ,--------------------------------------------------.
 * |   $    |   "  |   <  |   >  |   (  |   )  |  Esc |                                  |ScroLo|   @  |   +  |   -  |   /  |   *  |   =    |
 * |--------+------+------+------+------+-------------|                                  |------+------+------+------+------+------+--------|
 * |   %    |   B  |E_ACUT|   P  |   O  |E_GRAV|Backsp|                                  |CapsLo|   ^  |   V  |   D  |   L  |   J  |   Z    |
 * |--------+------+------+------+------+------|  ace |                                  |      |------+------+------+------+------+--------|
 * |   W    |   A  |   U  |   I  |   E  |   ,  |------|                                  |------|   C  |   T  |   S  |   R  |   N  |   M    |
 * |--------+------+------+------+------+------|Delete|                                  | NumLo|------+------+------+------+------+--------|
 * | E_CIRC |A_GRAV|   Y  |   X  |   .  |   K  |      |                                  |      |   '  |   Q  |   G  |   H  |   F  | C_CEDIL|
 * `--------+------+------+------+------+-------------,-------------.      ,-------------`-------------+------+------+------+------+--------'
 *   |QWERTY|      |LSuper| LCtrl|  LAlt|             |      | L_Mse|      |      |Insert|             | AltGr| RCtrl|RSuper|PrntSc| Pause|
 *   `----------------------------------'      ,------|------|------|      |------+------+------.      `----------------------------------'
 *                                             |      |      | L_Num|      |      |      |      |
 *                                             | Space|  Tab |------|      |------|RShift|Enter |
 *                                             |      |      | L_Nav|      | L_Fx |      |      |
 *                                             `--------------------'      `--------------------'
 */
[BASE] = KEYMAP(
// Left hand
BP_DOLLAR,	BP_DQOT,	BP_LGIL,	BP_RGIL,	BP_LPRN,	BP_RPRN,	KC_ESC,
BP_PERCENT,	BP_B,		BP_E_ACUTE,	BP_P,		BP_O,		BP_E_GRAVE,	KC_BSPC,
BP_W,		BP_A,		BP_U,		BP_I,		BP_E,		BP_COMMA,
BP_ECRC,	BP_A_GRAVE,	BP_Y,		BP_X,		BP_DOT,		BP_K,		KC_DEL,
TG(QWER),	KC_NO,		KC_LGUI,	KC_LCTL,	KC_LALT,
														KC_NO,		MO(MSE),
																MO(NUM),
												KC_SPC,		KC_TAB,		MO(NAV),
// Right hand
				KC_SLCK,	BP_AT,		BP_PLUS,	BP_MINUS,	BP_SLASH,	BP_ASTR,	BP_EQUAL,
				KC_CAPSLOCK,	BP_DCRC,	BP_V,		BP_D,		BP_L,		BP_J,		BP_Z,
						BP_C,		BP_T,		BP_S,		BP_R,		BP_N,		BP_M,
				KC_NUMLOCK,	BP_APOS,	BP_Q,		BP_G,		BP_H,		BP_F,		BP_CCED,
								BP_ALGR,	KC_RCTL,	KC_RGUI,	KC_PSCREEN,	KC_PAUSE,
KC_NO,		KC_INS,
KC_NO,
MO(FNX),	KC_RSHIFT,	KC_ENTER),
/* Keymap 1: QWERTY system compatibility layer
 *
 * ,--------------------------------------------------.                                  ,--------------------------------------------------.
 * |   $    |   "  |   <  |   >  |   (  |   )  |  Esc |                                  |ScroLo|   @  |   +  |   -  |   /  |   *  |   =    |
 * |--------+------+------+------+------+-------------|                                  |------+------+------+------+------+------+--------|
 * |   %    |   b  |   e  |   p  |   o  |   e  |Backsp|                                  |CapsLo|   ^  |   v  |   d  |   l  |   j  |   z    |
 * |--------+------+------+------+------+------|  ace |                                  |      |------+------+------+------+------+--------|
 * |   w    |   a  |   u  |   i  |   e  |   ,  |------|                                  |------|   c  |   t  |   s  |   r  |   n  |   m    |
 * |--------+------+------+------+------+------|Delete|                                  | NumLo|------+------+------+------+------+--------|
 * |   e    |   a  |   y  |   x  |   .  |   k  |      |                                  |      |   '  |   q  |   g  |   h  |   f  |   c    |
 * `--------+------+------+------+------+-------------,-------------.      ,-------------`-------------+------+------+------+------+--------'
 *   | BEPO |      |LSuper| LCtrl|  LAlt|             |      | L_Mse|      |      |Insert|             | AltGr| RCtrl|RSuper|PrntSc| Pause|
 *   `----------------------------------'      ,------|------|------|      |------+------+------.      `----------------------------------'
 *                                             |      |      | L_Num|      |      |      |      |
 *                                             | Space|  Tab |------|      |------|RShift|Enter |
 *                                             |      |      | L_Nav|      | L_Fx |      |      |
 *                                             `--------------------'      `--------------------'
 */
[QWER] = KEYMAP(
// Left hand
KC_DOLLAR,	S(KC_QUOT),	S(KC_COMM),	S(KC_DOT),	KC_LPRN,	KC_RPRN,	KC_ESC,
KC_PERCENT,	KC_B,		KC_E,		KC_P,		KC_O,		KC_E,		KC_BSPC,
KC_W,		KC_A,		KC_U,		KC_I,		KC_E,		KC_COMMA,
KC_E,		KC_A,		KC_Y,		KC_X,		KC_DOT,		KC_K,		KC_DEL,
KC_TRNS,	KC_NO,		KC_LGUI,	KC_LCTL,	KC_LALT,
														KC_NO,		MO(MSE),
																MO(NUM),
												KC_SPC,		KC_TAB,		MO(NAV),
// Right hand
				KC_SLCK,	KC_AT,		KC_PLUS,	KC_MINUS,	KC_SLASH,	KC_ASTR,	KC_EQUAL,
				KC_CAPSLOCK,	KC_CIRC,	KC_V,		KC_D,		KC_L,		KC_J,		KC_Z,
						KC_C,		KC_T,		KC_S,		KC_R,		KC_N,		KC_M,
				KC_NUMLOCK,	KC_QUOT,	KC_Q,		KC_G,		KC_H,		KC_F,		KC_C,
								MO(AQWER),	KC_RCTL,	KC_RGUI,	KC_PSCREEN,	KC_PAUSE,
KC_NO,		KC_INS,
KC_NO,
MO(FNX),	MO(SQWER),	KC_ENTER),
/* Keymap 2: QWERTY shifted system compatibility layer
 *
 * ,--------------------------------------------------.                                  ,--------------------------------------------------.
 * |   #    |   1  |   2  |   3  |   4  |   5  |  Esc |                                  |ScroLo|   6  |   7  |   8  |   9  |   0  |   =    |
 * |--------+------+------+------+------+-------------|                                  |------+------+------+------+------+------+--------|
 * |   `    |   B  |   E  |   P  |   O  |   E  |Backsp|                                  |CapsLo|   !  |   V  |   D  |   L  |   J  |   Z    |
 * |--------+------+------+------+------+------|  ace |                                  |      |------+------+------+------+------+--------|
 * |   W    |   A  |   U  |   I  |   E  |   ;  |------|                                  |------|   C  |   T  |   S  |   R  |   N  |   M    |
 * |--------+------+------+------+------+------|Delete|                                  | NumLo|------+------+------+------+------+--------|
 * |   E    |   A  |   Y  |   X  |   :  |   K  |      |                                  |      |   ?  |   Q  |   G  |   H  |   F  |   C    |
 * `--------+------+------+------+------+-------------,-------------.      ,-------------`-------------+------+------+------+------+--------'
 *   | BEPO |      |LSuper| LCtrl|  LAlt|             |      | L_Mse|      |      |Insert|             | AltGr| RCtrl|RSuper|PrntSc| Pause|
 *   `----------------------------------'      ,------|------|------|      |------+------+------.      `----------------------------------'
 *                                             |      |      | L_Num|      |      |      |      |
 *                                             | Space|  Tab |------|      |------|RShift|Enter |
 *                                             |      |      | L_Nav|      | L_Fx |      |      |
 *                                             `--------------------'      `--------------------'
 */
[SQWER] = KEYMAP(
// Left hand
S(KC_3),	KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		KC_TRNS,
KC_GRV,		S(KC_B),	S(KC_E),	S(KC_P),	S(KC_O),	S(KC_E),	KC_TRNS,
S(KC_W),	S(KC_A),	S(KC_U),	S(KC_I),	S(KC_E),	KC_SCOLON,
S(KC_E),	S(KC_A),	S(KC_Y),	S(KC_X),	S(KC_SCOLON),	S(KC_K),	KC_TRNS,
KC_TRNS,	KC_TRNS,	S(KC_LGUI),	S(KC_LCTL),	S(KC_LALT),
														KC_TRNS,	KC_TRNS,
																KC_TRNS,
												KC_TRNS,	S(KC_TAB),	KC_TRNS,
// Right hand
				KC_TRNS,	KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		KC_TRNS,
				KC_TRNS,	S(KC_1),	S(KC_V),	S(KC_D),	S(KC_L),	S(KC_J),	S(KC_Z),
						S(KC_C),	S(KC_T),	S(KC_S),	S(KC_R),	S(KC_N),	S(KC_M),
				KC_TRNS,	S(KC_SLASH),	S(KC_Q),	S(KC_G),	S(KC_H),	S(KC_F),	S(KC_C),
								S(KC_RALT),	S(KC_RCTL),	S(KC_RGUI),	KC_TRNS,	KC_TRNS,
KC_TRNS,	KC_TRNS,
KC_TRNS,
KC_TRNS,	KC_TRNS,	KC_TRNS),
/* Keymap 3: QWERTY alted system compatibility layer
 *
 * ,--------------------------------------------------.                                  ,--------------------------------------------------.
 * |   $    |   "  |   <  |   >  |   [  |   ]  |  Esc |                                  |ScroLo|   @  |   +  |   -  |   /  |   *  |   =    |
 * |--------+------+------+------+------+-------------|                                  |------+------+------+------+------+------+--------|
 * |   %    |   |  |   e  |   &  |   o  |   e  |Backsp|                                  |CapsLo|   ^  |   v  |   d  |   l  |   j  |   z    |
 * |--------+------+------+------+------+------|  ace |                                  |      |------+------+------+------+------+--------|
 * |   w    |   a  |   u  |   i  |   €  |   ,  |------|                                  |------|   c  |   t  |   s  |   r  |   n  |   m    |
 * |--------+------+------+------+------+------|Delete|                                  | NumLo|------+------+------+------+------+--------|
 * |   e    |   \  |   {  |   }  |   .  |   ~  |      |                                  |      |   '  |   q  |   g  |   h  |   f  |   c    |
 * `--------+------+------+------+------+-------------,-------------.      ,-------------`-------------+------+------+------+------+--------'
 *   | BEPO |      |LSuper| LCtrl|  LAlt|             |      | L_Mse|      |      |Insert|             | AltGr| RCtrl|RSuper|PrntSc| Pause|
 *   `----------------------------------'      ,------|------|------|      |------+------+------.      `----------------------------------'
 *                                             |      |      | L_Num|      |      |      |      |
 *                                             | Space|  Tab |------|      |------|RShift|Enter |
 *                                             |      |      | L_Nav|      | L_Fx |      |      |
 *                                             `--------------------'      `--------------------'
 */
[AQWER] = KEYMAP(
// Left hand
KC_DOLLAR,	S(KC_QUOT),	S(KC_COMM),	S(KC_DOT),	KC_LBRC,	KC_RBRC,	KC_ESC,
KC_PERCENT,	S(KC_BSLASH),	KC_E,		S(KC_7),	KC_O,		KC_E,		KC_BSPC,
KC_W,		KC_A,		KC_U,		KC_I,		RALT(KC_5),	KC_COMMA,
KC_E,		KC_BSLASH,	S(KC_LBRC),	S(KC_RBRC),	KC_DOT,		S(KC_GRV),	KC_DEL,
KC_TRNS,	KC_NO,		KC_LGUI,	KC_LCTL,	KC_LALT,
														KC_NO,		MO(MSE),
																MO(NUM),
												KC_SPC,		KC_TAB,		MO(NAV),
// Right hand
				KC_SLCK,	KC_AT,		KC_PLUS,	KC_MINUS,	KC_SLASH,	KC_ASTR,	KC_EQUAL,
				KC_CAPSLOCK,	KC_CIRC,	KC_V,		KC_D,		KC_L,		KC_J,		KC_Z,
						KC_C,		KC_T,		KC_S,		KC_R,		KC_N,		KC_M,
				KC_NUMLOCK,	KC_QUOT,	KC_Q,		KC_G,		KC_H,		KC_F,		KC_C,
								KC_TRNS,	KC_RCTL,	KC_RGUI,	KC_PSCREEN,	KC_PAUSE,
KC_NO,		KC_INS,
KC_NO,
MO(FNX),	MO(SQWER),	KC_ENTER),
/* Keymap 4: function layer
 *
 * ,--------------------------------------------------.                                  ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |                                  |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|                                  |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |                                  |      |      |      |      |      |      |   F12  |
 * |--------+------+------+------+------+------|      |                                  |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|                                  |------|      |      |      |      |      |   F13  |
 * |--------+------+------+------+------+------|      |                                  |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |                                  |      |      |      |      |      |      |   F14  |
 * `--------+------+------+------+------+-------------,-------------.      ,-------------`-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |             |      |      |      |      |      |             |      |      |      |      |      |
 *   `----------------------------------'      ,------|------|------|      |------+------+------.      `----------------------------------'
 *                                             |      |      |      |      |      |      |      |
 *                                             |      |      |------|      |------|      |      |
 *                                             |      |      |      |      |      |      |      |
 *                                             `--------------------'      `--------------------'
 */
[FNX] = KEYMAP(
// Left hand
KC_NO,		KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		KC_NO,
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_TRNS,	KC_TRNS,	KC_TRNS,
														KC_NO,		KC_NO,
																KC_NO,
												KC_NO,		KC_NO,		KC_NO,
// Right hand
				KC_NO,		KC_F6,		KC_F7,		KC_F8,		KC_F9,		KC_F10,		KC_F11,
				KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_F12,
						KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_F13,
				KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_F14,
								KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_NO,		KC_NO,
KC_NO,		KC_NO,
KC_NO,
KC_TRNS,	KC_TRNS,	KC_NO),
/* Keymap 5: numeric layer, sends keypad codes
 *
 * ,--------------------------------------------------.                                  ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |                                  |      |      |   +  |   -  |   /  |   *  |        |
 * |--------+------+------+------+------+-------------|                                  |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |                                  |      |      |   7  |   8  |   9  |      |        |
 * |--------+------+------+------+------+------|      |                                  |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|                                  |------|      |   4  |   5  |   6  |      |        |
 * |--------+------+------+------+------+------|      |                                  |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |                                  |      |      |   1  |   2  |   3  |      |        |
 * `--------+------+------+------+------+-------------,-------------.      ,-------------`-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |             |      |      |      |      |      |             |   0  |  00  |   .  |      |      |
 *   `----------------------------------'      ,------|------|------|      |------+------+------.      `----------------------------------'
 *                                             |      |      |      |      |      |      |      |
 *                                             |      |      |------|      |------|      | Enter|
 *                                             |      |      |      |      |      |      |      |
 *                                             `--------------------'      `--------------------'
 */
[NUM] = KEYMAP(
// Left hand
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_TRNS,	KC_TRNS,	KC_TRNS,
														KC_NO,		KC_NO,
																KC_TRNS,
												KC_NO,		KC_NO,		KC_NO,
// Right hand
				KC_NO,		KC_NO,		KC_KP_PLUS,	KC_KP_MINUS,	KC_KP_SLASH,	KC_KP_ASTERISK,	KC_NO,
				KC_NO,		KC_NO,		KC_KP_7,	KC_KP_8,	KC_KP_9,	KC_NO,		KC_NO,
						KC_NO,		KC_KP_4,	KC_KP_5,	KC_KP_6,	KC_NO,		KC_NO,
				KC_NO,		KC_NO,		KC_KP_1,	KC_KP_2,	KC_KP_3,	KC_NO,		KC_NO,
								KC_KP_0,	M(KP_00),	KC_KP_COMMA,	KC_NO,		KC_NO,
KC_NO,		KC_NO,
KC_NO,
KC_NO,		KC_TRNS,	KC_KP_ENTER),
/* Keymap 6: navigation layer
 *
 * ,--------------------------------------------------.                                  ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |                                  |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|                                  |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |                                  |      |      | Home |  Up  |  End | PgUp |        |
 * |--------+------+------+------+------+------|      |                                  |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|                                  |------|      | Left | Down | Right| PgDn |        |
 * |--------+------+------+------+------+------|      |                                  |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |                                  |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------,-------------.      ,-------------`-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |             |      |      |      |      |      |             |      |      |      |      |      |
 *   `----------------------------------'      ,------|------|------|      |------+------+------.      `----------------------------------'
 *                                             |      |      |      |      |      |      |      |
 *                                             |      |      |------|      |------|      |      |
 *                                             |      |      |      |      |      |      |      |
 *                                             `--------------------'      `--------------------'
 */
[NAV] = KEYMAP(
// Left hand
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_TRNS,	KC_TRNS,	KC_TRNS,
														KC_NO,		KC_NO,
																KC_NO,
												KC_NO,		KC_NO,		KC_TRNS,
// Right hand
				KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
				KC_NO,		KC_NO,		KC_HOME,	KC_UP,		KC_END,		KC_PGUP,	KC_NO,
						KC_NO,		KC_LEFT,	KC_DOWN,	KC_RIGHT,	KC_PGDOWN,	KC_NO,
				KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
								KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_NO,		KC_NO,
KC_NO,		KC_NO,
KC_NO,
KC_NO,		KC_TRNS,	KC_NO),
/* Keymap 7: mouse layer
 *
 * ,--------------------------------------------------.                                  ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |                                  |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|                                  |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |                                  |      |      |LClick|  Up  |RClick| WhUp |        |
 * |--------+------+------+------+------+------|      |                                  |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|                                  |------|      | Left | Down | Right|WhDown|        |
 * |--------+------+------+------+------+------|      |                                  |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |                                  |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------,-------------.      ,-------------`-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |             |      |      |      |      |      |             |      |      |      |      |      |
 *   `----------------------------------'      ,------|------|------|      |------+------+------.      `----------------------------------'
 *                                             |      |      |      |      |      |      |      |
 *                                             |      |      |------|      |------|      |      |
 *                                             |      |      |      |      |      |      |      |
 *                                             `--------------------'      `--------------------'
 */
[MSE] = KEYMAP(
// Left hand
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_TRNS,	KC_TRNS,	KC_TRNS,
														KC_NO,		KC_TRNS,
																KC_NO,
												KC_NO,		KC_NO,		KC_NO,
// Right hand
				KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
				KC_NO,		KC_NO,		KC_MS_BTN1,	KC_MS_UP,	KC_MS_BTN2,	KC_MS_WH_UP,	KC_NO,
						KC_NO,		KC_MS_LEFT,	KC_MS_DOWN,	KC_MS_RIGHT,	KC_MS_WH_DOWN,	KC_NO,
				KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
								KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_NO,		KC_NO,
KC_NO,		KC_NO,
KC_NO,
KC_NO,		KC_TRNS,	KC_NO)
};

const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case KP_00:
      if (record->event.pressed) {
        return MACRO( T(KP_0), D(KP_0), END );
      } else {
        return MACRO( U(KP_0), END );
      }
      break;
  }
  return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};
