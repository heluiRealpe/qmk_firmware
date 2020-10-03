#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "eeconfig.h"

#include "raw_hid.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _CHILDPROOF 5
#define _NUMPAD 6
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  NUMPAD,
  CHILDPROOF,
  ADJUST,
};

#define GUIBSPC GUI_T(KC_BSPC)
#define RSFTENT RSFT_T(KC_ENT)
#define LSFTENT LSFT_T(KC_ENT)
#define LCTLESC LCTL_T(KC_ESC)
#define RCTLESC RCTL_T(KC_ESC)
#define RCTLENT RCTL_T(KC_ENT)

/* Home Row Mods, Dvorak, LH */
#define LGUIT_A LGUI_T(KC_A)
#define LALTT_O LALT_T(KC_O)
#define LCTLT_E LCTL_T(KC_E)
#define LSFTT_U LSFT_T(KC_U)

/* Home Row Mods, QWERTY, LH */
#define LSFTT_F LSFT_T(KC_F)

/* Lower Row Mods, Dvorak, LH */
#define LGUIT_Q LGUI_T(KC_Q)
#define LALTT_J LALT_T(KC_J)
#define LCTLT_K LCTL_T(KC_K)

/* Lower Row Mods, QWERTY, LH */
#define LGUIT_X LGUI_T(KC_X)
#define LALTT_C LALT_T(KC_C)
#define LCTLT_V LCTL_T(KC_V)

/* Home Row Mods, Dvorak, RH */
#define RSFTT_H RSFT_T(KC_H)
#define RCTLT_T RCTL_T(KC_T)
#define RALTT_N RALT_T(KC_N)
#define RGUIT_S RGUI_T(KC_S)

/* Home Row Mods, QWERTY, RH */
#define RSFTT_J RSFT_T(KC_J)

/* Lower Row Mods, Dvorak, RH */
#define RCTLT_M RCTL_T(KC_M)
#define RALTT_W RALT_T(KC_W)
#define RGUIT_V RGUI_T(KC_V)

/* Lower Row Mods, QWERTY, RH */
#define RA_COMM RALT_T(KC_COMM)
#define RG_DOT  RGUI_T(KC_DOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_mit( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  LCTLESC, KC_A,    KC_S,    KC_D,    LSFTT_F, KC_G,    KC_H,    RSFTT_J, KC_K,    KC_L,    KC_SCLN, RCTLENT, \
  KC_LSFT, KC_Z,    LGUIT_X, LALTT_C, LCTLT_V, KC_B,    KC_N,    RCTLT_M, RA_COMM, RG_DOT,  KC_QUOT, KC_RSFT, \
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,      KC_SPC,        RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

[_COLEMAK] = LAYOUT_planck_mit( \
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,      KC_SPC,        RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

[_DVORAK] = LAYOUT_planck_mit( \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  LCTLESC, LGUIT_A, LALTT_O, LCTLT_E, LSFTT_U, KC_I,    KC_D,    RSFTT_H, RCTLT_T, RALTT_N, RGUIT_S, RCTLENT, \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT, \
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,      KC_SPC,        RAISE,   KC_RGUI, KC_RALT, KC_RCTL, NUMPAD \
),

[_LOWER] = LAYOUT_planck_mit( \
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
  KC_INS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_QUES, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______,     _______,      _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

[_RAISE] = LAYOUT_planck_mit( \
  KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, \
  KC_DEL,  _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_SLSH, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______,    _______,       _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

[_CHILDPROOF] = LAYOUT_planck_mit( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  ADJUST,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
),

[_NUMPAD] = LAYOUT_planck_mit( \
  _______, _______, _______, KC_UP,   _______, KC_INS,  KC_HOME, KC_PGUP, KC_7,    KC_8,    KC_9,    _______, \
  _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  KC_END,  KC_PGDN, KC_4,    KC_5,    KC_6,    _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    _______, \
  _______, _______, _______, _______, _______,     _______,      _______, KC_0,    KC_0,    KC_DOT,  _______  \
),

[_ADJUST] =  LAYOUT_planck_mit( \
  RESET,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_SPI, RGB_SPD, _______,
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  CHILDPROOF, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, KC_WH_D, KC_WH_U, \
  _______, _______, _______, _______, _______,     _______,      _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R \
)


};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// layer_state_t layer_state_set_user(layer_state_t state) {
//   // switch (state) {
//   // case _QWERTY:
//   //   rgb_matrix_sethsv_noeeprom(HSV_RED);
//   //   break;
//   // case _DVORAK:
//   //   rgb_matrix_sethsv_noeeprom(HSV_PURPLE);
//   //   break;
//   // case _LOWER:
//   //   rgb_matrix_sethsv_noeeprom(HSV_GREEN);
//   //   break;
//   // case _RAISE:
//   //   rgb_matrix_sethsv_noeeprom(HSV_ORANGE);
//   //   break;
//   // case _ADJUST:
//   //   rgb_matrix_sethsv_noeeprom(HSV_BLUE);
//   //   break;
//   // }
//   return state;
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case CHILDPROOF:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_CHILDPROOF);
      }
      return false;
      break;
    case NUMPAD:
      if (record->event.pressed) {
        layer_on(_NUMPAD);
      } else {
        layer_off(_NUMPAD);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

// RAW_EPSIZE is 32
void raw_hid_receive(uint8_t *data, uint8_t length) {
    raw_hid_send(data, length);
}
