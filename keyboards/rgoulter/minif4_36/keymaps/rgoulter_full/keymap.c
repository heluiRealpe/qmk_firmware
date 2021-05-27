/* Copyright 2021 Richard Goulter
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

#include "print.h"

// Defines names for use in layer keycodes and the keymap
enum layers {
  _DVORAK,
  _QWERTY,
  _CHILDPROOF,
  _NAVR,
  _MOUR,
  _MEDR,
  _NSL,
  _NSSL,
  _FUNL,
};

#define DVORAK     DF(_DVORAK)
#define QWERTY     DF(_QWERTY)
#define CHILDPROOF     DF(_CHILDPROOF)
#define SPC_NAVR  LT(_NAVR, KC_SPC)
#define TAB_MOUR  LT(_MOUR, KC_TAB)
#define ESC_MEDR  LT(_MEDR, KC_ESC)
#define BKSP_NSL   LT(_NSL, KC_BSPC)
#define ENT_NSSL  LT(_NSSL, KC_ENT)
#define DEL_FUNL  LT(_FUNL, KC_DEL)

/* Home Row, outer column */
#define LCTLESC LCTL_T(KC_ESC)
#define RCTLENT RCTL_T(KC_ENT)

/* Home Row Mods, Dvorak, LH */
#define LALTT_A LALT_T(KC_A)
#define LGUIT_O LGUI_T(KC_O)
#define LCTLT_E LCTL_T(KC_E)
#define LSFTT_U LSFT_T(KC_U)

/* Home Row Mods, QWERTY, LH */
// #define LALTT_A LALT_T(KC_A)
#define LGUIT_S LGUI_T(KC_S)
#define LCTLT_D LCTL_T(KC_D)
#define LSFTT_F LSFT_T(KC_F)

/* Home Row Mods, Dvorak, RH */
#define RSFTT_H RSFT_T(KC_H)
#define RCTLT_T RCTL_T(KC_T)
#define RGUIT_N RGUI_T(KC_N)
#define RALTT_S RALT_T(KC_S)

/* Home Row Mods, QWERTY, RH */
#define RSFTT_J RSFT_T(KC_J)
#define RCTLT_K RCTL_T(KC_K)
#define RGUIT_L RGUI_T(KC_L)
#define RALTTSC RALT_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DVORAK] = LAYOUT(
  KC_QUOT, KC_COMM, KC_DOT,   KC_P,     KC_Y,        KC_F,     KC_G,     KC_C,    KC_R,    KC_L,
  LALTT_A, LGUIT_O, LCTLT_E,  LSFTT_U,  KC_I,        KC_D,     RSFTT_H,  RCTLT_T, RGUIT_N, RALTT_S,
  KC_SCLN, KC_Q,    KC_J,     KC_K,     KC_X,        KC_B,     KC_M,     KC_W,    KC_V,    KC_Z,
                    TAB_MOUR, ESC_MEDR, SPC_NAVR,    BKSP_NSL, ENT_NSSL, DEL_FUNL
),

[_QWERTY] = LAYOUT(
  KC_Q,    KC_W,     KC_E,     KC_R,     KC_T,        KC_Y,     KC_U,     KC_I,     KC_O,    KC_P,
  LALTT_A, LGUIT_S,  LCTLT_D,  LSFTT_F,  KC_G,        KC_H,     RSFTT_J,  RCTLT_K,  RGUIT_L, RALTTSC,
  KC_Z,    KC_X,     KC_C,     KC_V,     KC_B,        KC_N,     KC_M,     KC_COMM,  KC_DOT,  KC_QUOT,
                     TAB_MOUR, ESC_MEDR, SPC_NAVR,    BKSP_NSL, ENT_NSSL, DEL_FUNL
),

[_NAVR] = LAYOUT( \
  _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,    KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______,
  _______, _______, _______, _______, _______,    KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_INS,
                    _______, _______, _______,    _______, _______, _______
),

[_MOUR] = LAYOUT( \
  _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
  _______, _______, _______, _______, _______,    KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,
                    _______, _______, _______,    KC_BTN1, KC_BTN2, KC_BTN3
),

[_MEDR] = LAYOUT( \
  _______, _______, _______, _______, _______,    RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,
  _______, _______, _______, _______, _______,    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
  _______, _______, _______, _______, _______,    QWERTY,  DVORAK,  _______, _______, _______,
                    _______, _______, _______,    KC_MPLY, KC_MSTP, KC_MUTE
),

[_NSL] = LAYOUT( \
  KC_LBRC, KC_7, KC_8,   KC_9, KC_RBRC,    _______, _______, _______, _______, _______,
  KC_GRV,  KC_4, KC_5,   KC_6, KC_EQL,     _______, _______, _______, _______, _______,
  KC_SLSH, KC_1, KC_2,   KC_3, KC_BSLS,    _______, _______, _______, _______, _______,
                 KC_DOT, KC_0, KC_MINS,    _______, _______, _______
),

[_NSSL] = LAYOUT( \
  KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,    _______, _______, _______, _______, _______,
  KC_TILD, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,     _______, _______, _______, _______, _______,
  KC_QUES, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,      _______, _______, _______, _______, _______,
                    KC_LPRN, KC_RPRN, KC_UNDS,    _______, _______, _______
),

[_FUNL] = LAYOUT( \
  KC_F12, KC_F7, KC_F8,    KC_F9,   _______,    _______, _______, _______, _______, _______,
  KC_F11, KC_F4, KC_F5,    KC_F6,   _______,    _______, _______, _______, _______, _______,
  KC_F10, KC_F1, KC_F2,    KC_F3,   _______,    _______, _______, _______, _______, _______,
                  _______, _______, _______,    _______, _______, _______
),

};

#ifdef COMBO_ENABLE
enum combo_events {
  DESKTOP_GO_LEFT,
  DESKTOP_GO_RIGHT,
  LEAD,
};

// can't be keys which have tap-hold
const uint16_t PROGMEM dsk_lower_left_combo[] = {KC_J, KC_K, COMBO_END};
// const uint16_t PROGMEM dsk_lower_left_combo[] = {LCTLT_E, LSFTT_U, COMBO_END};
const uint16_t PROGMEM dsk_lower_right_combo[] = {KC_M, KC_W, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [DESKTOP_GO_LEFT] = COMBO_ACTION(dsk_lower_left_combo),
  [DESKTOP_GO_RIGHT] = COMBO_ACTION(dsk_lower_right_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case DESKTOP_GO_LEFT:
      if (pressed) {
        // macOS
        tap_code16(LCTL(KC_LEFT));
      }
      break;
    case DESKTOP_GO_RIGHT:
      if (pressed) {
        // macOS
        tap_code16(LCTL(KC_RIGHT));
      }
      break;
  }
}
#endif

void keyboard_post_init_user(void) {
#ifdef RGB_MATRIX_ENABLE
  // rgb_matrix_mode_noeeprom(RGB_MATRIX_MULTISPLASH);
  rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_PINWHEEL);
#endif
}

void encoder_update_user(uint8_t index, bool clockwise) {
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    oled_scroll_set_area(0, 0);
    oled_scroll_set_speed(0);

    // For simplicity,
    // this only allows the left-hand board to be master.
    // If the right-hand board is used as master,
    // the OLEDs are rendered "upside down".
    if (is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }

    return rotation;
}

// Use all 94 visible ASCII characters for testing.
static void test_logo(void) {
    uint8_t lines = oled_max_lines();
    if (lines > 3) {
        lines = 3;
    }
    uint8_t chars = oled_max_chars();
    if (chars > 21) {
        chars = 21;
    }
    for (uint8_t row = 0; row < lines; ++row) {
        oled_set_cursor(0, row);
        for (uint8_t col = 0; col < chars; ++col) {
            oled_write_char(0x80 + 0x20 * row + col, false);
        }
    }
}

/*
#define TEST_CHAR_COUNT ('~' - '!' + 1)

static char get_test_char(uint8_t char_index) { return char_index + '!'; }

// Fill the whole screen with distinct characters (if the display is large enough to show more than 94 characters
// at once, the sequence is repeated the second time with inverted characters).
static void test_characters(void) {
    uint8_t cols       = oled_max_chars();
    uint8_t rows       = oled_max_lines();
    bool    invert     = false;
    uint8_t char_index = 0;
    for (uint8_t row = 0; row < rows; ++row) {
        for (uint8_t col = 0; col < cols; ++col) {
            oled_write_char(get_test_char(char_index), invert);
            if (++char_index >= TEST_CHAR_COUNT) {
                char_index = 0;
                invert     = !invert;
            }
        }
    }
}

// */
void oled_task_user(void) {
    // Host Keyboard Layer Status
  test_logo();
  // test_characters();
  /*
    oled_clear();
    oled_write(("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
    case _DVORAK:
            oled_write_ln(("Dvorak"), false);
            break;
    case _QWERTY:
            oled_write_ln(("QWERTY"), false);
            break;
    case _CHILDPROOF:
            oled_write_ln(("CHILDPROOF"), false);
            break;
    case _NAVR:
            oled_write_ln(("NAVR"), false);
            break;
    case _MOUR:
            oled_write_ln(("MOUR"), false);
            break;
    case _MEDR:
            oled_write_ln(("MEDR"), false);
            break;
    case _NSL:
            oled_write_ln(("NSL"), false);
            break;
    case _NSSL:
            oled_write_ln(("NSSL"), false);
            break;
    case _FUNL:
            oled_write_ln(("FUNL"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln(("Undefined"), false);
    }

  */
}
#endif
