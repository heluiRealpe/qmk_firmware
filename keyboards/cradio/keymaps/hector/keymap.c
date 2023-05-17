/* Copyright 2018-2021
 * ENDO Katsuhiro <ka2hiro@curlybracket.co.jp>
 * David Philip Barr <@davidphilipbarr>
 * Pierre Chevalier <pierrechevalier83@gmail.com>
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

/* Base layer 0 layout uses home row mods. See the following guide for details:
 * https://precondition.github.io/home-row-mods
 */

#include "keymap_us_international.h"
#include "sendstring_us_international.h"
#include "features/select_word.h"

enum Layers{
    L_QWERTY, L_LOWER, L_RAISE, L_MOV, L_NUM, L_ADJUST
};

enum custom_keycodes {
  SELWORD = SAFE_RANGE,
  SELLINE,
  SRCHSEL,
  QWERTY,
  LOWER,
  RAISE,
  MOV,
  NUM,
  ADJUST,
  MACRO1,
  MACRO2,
  MACRO3,
  MACRO4,
  MACRO5,
  MACRO6,
  MACRO7,
  MACRO8,
  TD_Q_TAB = 0,
  TD_A_ESC,
  TD_ONEGR,
  TD_EXTIL,
  TD_SCLQT,
  TD_WHOME,
  TD_EEND,
  TD_ENE
};

// LAYER SWITCHING
#define LOWER LT(L_LOWER, KC_BSPC)
#define RAISE LT(L_RAISE, KC_ENT)
#define SPCNUM LT(L_NUM, KC_SPC)
#define MOVLAY TG(L_MOV)
#define QWERTY TG(L_MOV)
#define AJSTLAY MO(L_ADJUST)
// MODIFIER KEYS
#define LALTTAB LALT(KC_TAB)
#define RCTRTAB RCTL(KC_TAB)
#define WINSHOT LSG(KC_S)
// MOD-TAP KEYS
// LEFT HAND
#define LSHIFT_Z SFT_T(KC_Z)
#define LCTRL_X CTL_T(KC_X)
#define LALT_C LALT_T(KC_C)
#define LGUI_V LGUI_T(KC_V)
// RIGHT HAND
#define RSHIFT_H RSFT_T(KC_SLSH)
#define RCTR_DOT RCTL_T(KC_DOT)
#define RGUIL_M RGUI_T(KC_M)
#define RALT_COM RALT_T(KC_COMM)
// TAP-DANCE KEYS
// LEFT HAND
#define KC_QTAB TD(TD_Q_TAB)
#define KC_AESC TD(TD_A_ESC)
#define KC_WHOME TD(TD_WHOME)
#define KC_EEND TD(TD_EEND)
#define KC_ONEGR TD(TD_ONEGR)
#define KC_EXTIL TD(TD_EXTIL)
// RIGHT HAND
#define KC_SCLQT TD(TD_SCLQT)
#define KC_ENE TD(TD_ENE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
  [_TPL] = LAYOUT_wrapper(
  //---------------------------------------------.      ,--------------------------------------------.
    |   Q    |   W    |   E    |   R    |   T    |      |    Y   |   U    |   I    |   O    |   P    |
  //+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------|
    |   A    |   S    |   D    |   F    |   G    |      |    H   |   J    |   K    |   L    |   ;:   |
  //+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------|
    |   Z    |   X    |   C    |   V    |   B    |      |    N   |   M    |   ,<   |   .>   |   /?   |
  //+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------|
                                    ---------------,  ,---------------.
                                   | Lower*|AltSpac|  | Space | Raise*|
                                  /|-------+-------'  +-------+-------|\
  ),
*/
  [L_QWERTY] = LAYOUT_split_3x5_2(
  //--------------------------------------------.                    ,--------------------------------------------.
     KC_QTAB,KC_WHOME, KC_EEND,   KC_R ,  KC_T  ,                       KC_Y  ,   KC_U ,  KC_I  ,  KC_O  ,  KC_P  ,
  //--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     KC_AESC,  KC_S  ,  KC_D  ,   KC_F ,  KC_G  ,                       KC_H  ,  KC_J  ,  KC_K  ,  KC_L  ,KC_SCLQT,
  //--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    LSHIFT_Z, LCTRL_X, LALT_C , LGUI_V ,  KC_B  ,                      KC_ENE , RGUIL_M,RALT_COM,RCTR_DOT,RSHIFT_H,
  //--------+--------+--------+--------|--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          LOWER , SPCNUM ,    KC_SPC , RAISE
                                      //`----------------'  `----------------'
  ),

/*
 * LOWER LAYER
  [_TPL] = LAYOUT_wrapper(
  //---------------------------------------------.      ,--------------------------------------------.
    |   1    |   2    |   3    |   4    |   5    |      |     6  |   7    |   8    |   9    |   0    |
  //+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------|
    |        |        |        |        |        |      |    \   |   -    |   =    |   [    |   ]    |
  //+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------|
    |BrowHome|BrowBack|BroReloa|BroSearc|BoForwar|      | Insert |        |        |        |        |
  //+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------|
                                   ----------------,  ,-----------------------.
                                   | ******|       |  |       |       |CapLock|
                                  /+-------+-------'  +-------+-------+-------|\
  ),
*/
  [L_LOWER] = LAYOUT_split_3x5_2(
  //---------------------------------------------.                    ,--------------------------------------------.
     KC_ONEGR,  KC_2  , KC_3   , KC_4   , KC_5   ,                      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   ,
  //+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_ESC , WINSHOT, LALTTAB, RCTRTAB, KC_TAB ,                      KC_BSLS, KC_MINS, KC_EQL , KC_LBRC, KC_RBRC,
  //+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_WHOM, KC_WBAK, KC_WREF, KC_WSCH, KC_WFWD,                       CW_TOGG, KC_APP, _______, _______, _______,
  //+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          _______, _______,    AJSTLAY, MOVLAY
                                      //`-----------------'  `-----------------'
  ),

/*
 * RAISE LAYER
  [_TPL] = LAYOUT_wrapper(
  //,--------------------------------------------.      ,--------------------------------------------.
    |   !    |   @    |   #    |   $    |   %    |      |    ^   |    &   |   *    |   (    |   )    |
  //|--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------|
    |        | Screen | WnShoo |        |        |      |    |   |   _    |   +    |   {    |   }    |
  //|--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------|
    |  PLY2  |  REC2  |  PLY1  |  REC1  |  RSTP  |      | Left   | Down   |  Up    | Right  |        |
  //|--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------|
                                    ,---------------,  ,---------------.
                                    |       |       |  |       | ******|
                                   /|-------+-------'  +-------+-------|\
  ),
*/
  [L_RAISE] = LAYOUT_split_3x5_2(
  //,--------------------------------------------.                    ,--------------------------------------------.
     KC_EXTIL,  KC_AT , KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  //+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_PSCR, WINSHOT, KC_PGUP, KC_PGDN, SELWORD,                      KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      DM_PLY2, DM_REC2, DM_PLY1, DM_REC1, DM_RSTP,                      KC_LEFT, KC_DOWN, KC_UP  ,KC_RIGHT, _______,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          MOVLAY , _______,    _______, _______
                                      //`-----------------'  `-----------------'
  ),

/*
 * L_ADJUST LAYER
  [_TPL] = LAYOUT_wrapper(
  //,--------------------------------------------.      ,--------------------------------------------.
    |        |        |  End   |        |        |      |        | Bri-   | Bri+   |        |        |
  //|--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------|
    | Home   |        |        |        |        |      |        | RGB-   | RGB+   |        |        |
  //|--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------|
    |Static  |BLtogg  |BLstep  |        |        |      |        | SAT-   | SAT+   |        | QK_BOOT|
  //|--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------|
                                   ,---------------,  ,---------------.
                                   | ******|       |  | ******|       |
                                  /|-------+-------'  +-------+-------|\
  ),
*/
  [L_ADJUST] = LAYOUT_split_3x5_2(
  //,-------------------------------------------.                    ,--------------------------------------------.
     _______, _______, KC_END , _______, _______,                      _______, RGB_VAD, RGB_VAI, _______, _______,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     KC_HOME, _______, KC_BRIU, KC_BRID, _______,                      _______, RGB_HUD, RGB_HUI, KC_SLEP, _______,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     RGB_TOG, RGB_MOD, RGB_M_P, _______, _______,                      _______, RGB_SAD, RGB_SAI, _______, QK_BOOT,
  //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                         _______, _______,    _______, _______
                                      //`----------------'  `-----------------'
  ),

/*
 * NUM LAYER
  [_TPL] = LAYOUT_wrapper(
  //,--------------------------------------------.      ,--------------------------------------------.
       F1    |  F2    |  F3    |  F4    |  F5    |      | MACRO1 | MACRO1 | MACRO1 | Delete |BackSpac|
  //|--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------|
       F6    |  F7    |  F8    |  F9    |  F10   |      | MACRO1 | MACRO1 | MACRO1 | MACRO1 |   '"   |
  //|--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------|
       F11   |  F12   |        |        |        |      |        |        |        |        |        |
  //|--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------|
                                   ,---------------,  ,---------------.
                                   |       | ******|  |       |       |
                                 //|-------+-------'  +-------+-------|\
  ),
*/
  [L_NUM] = LAYOUT_split_3x5_2(
  //,--------------------------------------------.                    ,--------------------------------------------.
      KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                      MACRO1 , MACRO3 , MACRO4 , KC_DEL , KC_BSPC,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,                      MACRO2 , MACRO5 , MACRO6 , MACRO7 , KC_QUOT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_F11 , KC_F12 , _______, _______, _______,                      KC_CAPS, SELLINE, SRCHSEL, _______, _______,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          _______, _______,    _______, _______
                                       //-----------------------------+--------|
  ),

/*
 * L_MOV LAYER
  [_TPL] = LAYOUT_wrapper(
  //,--------------------------------------------.      ,--------------------------------------------.
    |        |        |        |        |        |         PlaSto|  Vol-  |  Vol+  |  Mute  |        |
  //|--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------|
    |        |        |        | MOUS1  | MOUS2  |         MOUSL | MOUSD  | MOUSU  | MOUSR  | SySleep|
  //|--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------|
    |        | ACC0   | ACC1   | ACC2   |        |        WheelL | WheelD | WheelU | WheelR |        |
  //|--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------|
                                    ,---------------,  ,---------------.
                                    | ******|       |  |       | ******|
                                  //|-------+-------'  +-------+-------|\
  ),
*/
  [L_MOV] = LAYOUT_split_3x5_2(
  //,--------------------------------------------.                    ,--------------------------------------------.
      QWERTY , KC_ACL0, KC_ACL1, KC_ACL2, QWERTY ,                      KC_MPLY, KC_VOLD, KC_VOLU, KC_MUTE, QWERTY ,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_ESC , QWERTY , KC_BTN2, KC_BTN1, QWERTY ,                      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_SLEP,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, QWERTY ,                      KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, QWERTY ,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          _______, _______,    _______, _______
                                      //`-----------------'  `-----------------'
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if (!process_select_word(keycode, record, SELWORD)) {return false;}
  switch (keycode) {
    case MACRO1:
        if (record->event.pressed) {
            SEND_STRING("B1tl0ck3r");
        }
        return false;
    case MACRO2:
        if (record->event.pressed) {
            SEND_STRING("y0457595rH3ct0rR34lp3C4str1ll0");
        }
        return false;
    case MACRO3:
        if (record->event.pressed) {
            SEND_STRING("Z9T4jh4Zqh$BfpI");
        }
        return false;
    case MACRO4:
        if (record->event.pressed) {
            SEND_STRING("2417906");
        }
        return false;
    case MACRO5:
        if (record->event.pressed) {
            SEND_STRING("git add .");
        }
        return false;
    case MACRO6:
        if (record->event.pressed) {
            SEND_STRING("git commit -m ''");
        }
        return false;
    case MACRO7:
        if (record->event.pressed) {
            SEND_STRING("git ");
        }
        return false;
    case SELLINE:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)));
        }
        return false;
    case SRCHSEL:
        if (record->event.pressed) {
          SEND_STRING(SS_LCTL("ct") SS_DELAY(100) SS_LCTL("v") SS_TAP(X_ENTER));
        }
        return false;
      break;
  }
  return true;
}

// Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    [TD_Q_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_TAB),
    [TD_A_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_ESC),
    [TD_ONEGR] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_GRV),
    [TD_EXTIL] = ACTION_TAP_DANCE_DOUBLE(KC_EXLM, KC_TILD),
    [TD_SCLQT] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT),
    [TD_WHOME] = ACTION_TAP_DANCE_DOUBLE(KC_W, KC_HOME),
    [TD_EEND] = ACTION_TAP_DANCE_DOUBLE(KC_E, KC_END),
    [TD_ENE] = ACTION_TAP_DANCE_DOUBLE(KC_N, RALT(KC_N)),
};

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_AESC:
        case KC_QTAB:
        case KC_WHOME:
        case KC_EEND:
        case KC_MINS:
        case KC_ENE:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_0 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
};
