/* Copyright 2022 hector
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

#include "features/select_word.h"

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _MOV,
  _NUM,
  _ADJUST
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
  UNDO,
  COPY,
  CUT,
  PASTE,
  REDO
};

#define SPCMOV LT(_MOV, KC_SPC)
#define TABNUM LT(_NUM, KC_TAB)
#define RAISE LT(_RAISE, KC_ENT)
#define LOWER LT(_LOWER, KC_BSPC)
#define UNDO LCTL(KC_Z)
#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define REDO LCTL(KC_Y)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
* ,-----------------------------------------------------------------------------------.
* | Tab* |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* | Esc* |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ;:  |  '"  |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |  ,<  |  .>  |  /?  | Shift|
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | LCtrl| GUI  | Shift| Alt* |Lower*|  SpaceBar   |Raise*| RAlt*|CapsWo| HYPR | RCtrl|
* `-----------------------------------------------------------------------------------'
*
* - Tap dance MOV/Space
* - Tap dance Raise/Enter
* - Tap dance Lower/Backspace
* - Tap dance Tab/Num
* - Tap dance Left Alt when held, ( when tapped
* - Tap dance Right Alt when held, ) when tapped
*/
[_QWERTY] = LAYOUT_ortho_4x12_1x2uC(
    TABNUM , KC_Q    , KC_W    , KC_E    , KC_R  , KC_T   , KC_Y   , KC_U  , KC_I    , KC_O    , KC_P    , KC_BSPC,
    KC_ESC , KC_A    , KC_S    , KC_D    , KC_F  , KC_G   , KC_H   , KC_J  , KC_K    , KC_L    , KC_SCLN , KC_QUOT,
    KC_LSFT, KC_Z    , KC_X    , KC_C    , KC_V  , KC_B   , KC_N   , KC_M  , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT,
    KC_LCTL, KC_LGUI , KC_LSFT , KC_LAPO , LOWER ,   KC_SPACE      , RAISE , KC_RAPC , CAPSWRD , KC_HYPR , KC_RCTL
    ), 

/* Lower
* ,-----------------------------------------------------------------------------------.
* |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |      |SrchSe|WnShoo|Screen|ShWord|SeLine|   \  |   -  |   =  |   [  |   ]  |      |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |      |LiUndo|LiCut |LiCopy|LPaste|LiRedo|ASRepo|ASDown|AShfUp|ASTogg|      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      | **** |   Space*    |      |      |CapsLk|      |      |
* `-----------------------------------------------------------------------------------'
*/
[_LOWER] = LAYOUT_ortho_4x12_1x2uC(
    KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSPC ,
    _______ , SRCHSEL ,LSG(KC_S), KC_PSCR , SELWORD , SELLINE , KC_BSLS , KC_MINS , KC_EQL  , KC_LBRC , KC_RBRC , _______ ,
    _______ , KC_UNDO , KC_CUT  , KC_COPY , KC_PASTE, KC_AGAIN, KC_ASRP , KC_ASDN , KC_ASUP , KC_ASTG , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ ,     SPCMOV      , _______ , _______ , KC_CAPS , _______ , _______
    ),

/* Raise
* ,-----------------------------------------------------------------------------------.
* |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |      | PLY2 | REC2 | PLY1 | REC1 | RSTP |   |  |   _  |   +  |   {  |   }  |      |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |      |MACRO4|MACRO3|MACRO2|MACRO1|MACRO5|      |      |      |      |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |  SpaceBar   | **** |      |      |      |      |
* `-----------------------------------------------------------------------------------'
*/
[_RAISE] = LAYOUT_ortho_4x12_1x2uC(
    KC_TILD , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC , KC_AMPR   , KC_ASTR    , KC_LPRN , KC_RPRN , KC_BSPC ,
    _______ , DM_PLY2 , DM_REC2 , DM_PLY1 , DM_REC1 , DM_RSTP , KC_PIPE , KC_UNDS   , KC_PLUS    , KC_LCBR , KC_RCBR , _______ ,
    _______ , MACRO4  , MACRO3  , MACRO2  , MACRO1  , MACRO5  , _______ , _______   , _______    , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ ,      KC_SPACE     , _______   , _______    , _______ , _______ , _______
    ),
    
/* MOV
* ,-----------------------------------------------------------------------------------.
* |      |      |      |  End |      |      |      |PgDown| PgUp |      |Insert|      |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |      | Home |      |      |      |      | Left | Down |  Up  | Right| Del  |      |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |      | Undo | Cut  | Copy | Paste| Redo |      |      |      |      |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      | *********** | Enter|      |      |      |      |
* `-----------------------------------------------------------------------------------'
*
*/
[_MOV] = LAYOUT_ortho_4x12_1x2uC(
    _______ , _______ , _______ , KC_END  , _______ , _______ , _______ , KC_PGDN , KC_PGUP , _______  , KC_INS , _______,
    _______ , KC_HOME , _______ , _______ , _______ , _______ , KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , KC_DEL  , _______,
    _______ ,  UNDO   ,  CUT    ,  COPY   ,  PASTE  ,  REDO   , _______ , _______ , _______ , _______  , _______ , _______,
    _______ , _______ , _______ , _______ , _______ ,       _______     , KC_ENT  , _______ , _______  , _______ , _______
    ),

/* NUM
* ,-----------------------------------------------------------------------------------.
* | **** |  F1  |  F2  |  F3  |  F4  |  F5  |      |   7  |   8  |   9  |   *  | Del  |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |      |  F6  |  F7  |  F8  |  F9  |  F10 | Bksp |   4  |   5  |   6  |   +  |      |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |      |  F11 |  F12 |      |      |      | Enter|   1  |   2  |   3  |   -  |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |  SpaceBar   |   0  |   ,  |   .  |      |      |
* `-----------------------------------------------------------------------------------'
*/
[_NUM] = LAYOUT_ortho_4x12_1x2uC(
    _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , _______ , KC_P7, KC_P8  , KC_P9 , KC_PAST , KC_DEL  ,
    _______ , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_BSPC , KC_P4, KC_P5  , KC_P6 , KC_PPLS , _______ ,
    _______ , KC_F11  , KC_F12  , _______ , _______ , _______ , KC_ENT  , KC_P1, KC_P2  , KC_P3 , KC_PMNS , _______ ,
    _______ , _______ , _______ , _______ , _______ ,      KC_SPACE     , KC_0 , KC_COMM, KC_PDOT, _______ , _______
    ), 

/* Adjust (Lower + Raise)
* ,----------------------------------------------------------------------------------------.
* |      | SAT+ | RGB+ | Bri+ |      |      |PlaSto| Vol- | Vol+ | Mute |      |           |
* |------+------+------+------+------+-------------+------+------+------+------+-----------|
* |      | SAT- | RGB- | Bri- | MOUS1| MOUS2| MOUSL| MOUSD| MOUSU| MOUSR|      |SystemSleep|
* |------+------+------+------+------+------|------+------+------+------+------+-----------|
* |Static|BLtogg|BLstep| ACC0 | ACC1 | ACC2 |WheelL|WheelD|WheelU|WheelR|      |           |
* |------+------+------+------+------+------+------+------+------+------+------+-----------|
* |      | Reset| Debug|      | **** |             | **** |      |      |      |           |
* `----------------------------------------------------------------------------------------'
*/
[_ADJUST] = LAYOUT_ortho_4x12_1x2uC(
    _______ , RGB_SAI, RGB_HUI , RGB_VAI , _______ , _______ , KC_MPLY , KC_VOLD, KC_VOLU, KC_MUTE, _______, _______,
    _______ , RGB_SAD, RGB_HUD , RGB_VAD , KC_BTN1 , KC_BTN2 , KC_MS_L , KC_MS_D, KC_MS_U, KC_MS_R, _______, KC_SLEP,
    RGB_M_P , RGB_TOG, RGB_MOD , KC_ACL0 , KC_ACL1 , KC_ACL2 , KC_WH_L , KC_WH_D, KC_WH_U, KC_WH_R, _______, _______,
    _______ , RESET  , DEBUG   , _______ , _______ ,     _______      , _______, _______, _______, _______, _______
    )

};

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
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
}

int RGB_current_mode;

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
}

bool isRecording = false;
bool isRecordingLedOn = false;
static uint16_t recording_timer;

void rgb_matrix_indicators_user(void) {
  #ifdef RGB_MATRIX_ENABLE
  switch (biton32(layer_state)) {
    case _LOWER:
      for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
         rgb_matrix_set_color(i, 245, 200, 66);
      }
      break;

    case _RAISE:
      for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
          rgb_matrix_set_color(i, 173, 47, 93);
      }
      break;

    case _MOV:
      for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
         rgb_matrix_set_color(i, 0, 255, 255);
      }
      break;

    case _NUM:
      for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
         rgb_matrix_set_color(i, 255, 0, 255);
      }
      break;

    case _ADJUST:
      for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
         rgb_matrix_set_color(i, 66, 200, 245);
      }
      break;

    default:
        if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
          for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
          rgb_matrix_set_color(0, 255, 0, 0);
          rgb_matrix_set_color(1, 0, 255, 0);
          rgb_matrix_set_color(2, 0, 0, 255);
          rgb_matrix_set_color(3, 0, 255, 0);
          rgb_matrix_set_color(4, 255, 0, 0);
          rgb_matrix_set_color(5, 0, 255, 0);
          rgb_matrix_set_color(6, 0, 0, 255);
          rgb_matrix_set_color(7, 0, 255, 0);
          rgb_matrix_set_color(8, 255, 0, 0);
          rgb_matrix_set_color(9, 0, 255, 0);
          rgb_matrix_set_color(10, 0, 0, 255);
          rgb_matrix_set_color(11, 0, 255, 0);
	    	  rgb_matrix_set_color(12, 255, 0, 0);
          rgb_matrix_set_color(13, 0, 255, 0);
          rgb_matrix_set_color(14, 0, 0, 255);
          rgb_matrix_set_color(15, 0, 255, 0);
          rgb_matrix_set_color(16, 255, 0, 0);
          rgb_matrix_set_color(17, 0, 255, 0);
          rgb_matrix_set_color(18, 0, 0, 255);
          rgb_matrix_set_color(19, 0, 255, 0);
          rgb_matrix_set_color(20, 255, 0, 0);
          rgb_matrix_set_color(21, 0, 255, 0);
          rgb_matrix_set_color(22, 0, 0, 255);
          rgb_matrix_set_color(23, 0, 255, 0);
		  rgb_matrix_set_color(24, 255, 0, 0);
          rgb_matrix_set_color(25, 0, 255, 0);
          rgb_matrix_set_color(26, 0, 0, 255);
          rgb_matrix_set_color(27, 0, 255, 0);
          rgb_matrix_set_color(28, 255, 0, 0);
          rgb_matrix_set_color(29, 0, 255, 0);
          rgb_matrix_set_color(30, 0, 0, 255);
          rgb_matrix_set_color(31, 0, 255, 0);
          rgb_matrix_set_color(32, 255, 0, 0);
          rgb_matrix_set_color(33, 0, 255, 0);
          rgb_matrix_set_color(34, 0, 0, 255);
          rgb_matrix_set_color(35, 0, 255, 0);
		  rgb_matrix_set_color(36, 255, 0, 0);
          rgb_matrix_set_color(37, 0, 255, 0);
          rgb_matrix_set_color(38, 0, 0, 255);
          rgb_matrix_set_color(39, 0, 255, 0);
          rgb_matrix_set_color(40, 255, 0, 0);
          rgb_matrix_set_color(41, 0, 255, 0);
          rgb_matrix_set_color(42, 0, 0, 255);
          rgb_matrix_set_color(43, 0, 255, 0);
          rgb_matrix_set_color(44, 255, 0, 0);
          rgb_matrix_set_color(45, 0, 255, 0);
          rgb_matrix_set_color(46, 0, 0, 255);
          rgb_matrix_set_color(47, 0, 255, 0);
          }
       }
      break;
  }
    if (isRecording)
    {
        // timer_elapsed() is a built-in function in qmk => it calculates in ms the time elapsed with timer_read()
        if (timer_elapsed(recording_timer) > 500) 
        {
            isRecordingLedOn = !isRecordingLedOn;
            recording_timer = timer_read();
        }
        if (isRecordingLedOn)
        {
          rgb_matrix_set_color(0, 255, 0, 0);
          rgb_matrix_set_color(1, 0, 255, 0);
          rgb_matrix_set_color(2, 0, 0, 255);
          rgb_matrix_set_color(3, 0, 255, 0);
          rgb_matrix_set_color(4, 255, 0, 0);
          rgb_matrix_set_color(5, 0, 255, 0);
          rgb_matrix_set_color(6, 0, 0, 255);
          rgb_matrix_set_color(7, 0, 255, 0);
          rgb_matrix_set_color(8, 255, 0, 0);
          rgb_matrix_set_color(9, 0, 255, 0);
          rgb_matrix_set_color(10, 0, 0, 255);
          rgb_matrix_set_color(11, 0, 255, 0);
        }
    }
	
    if (get_autoshift_state())
    {
          rgb_matrix_set_color(12, 255, 0, 0);
          rgb_matrix_set_color(13, 0, 255, 0);
          rgb_matrix_set_color(14, 0, 0, 255);
          rgb_matrix_set_color(15, 0, 255, 0);
          rgb_matrix_set_color(16, 255, 0, 0);
          rgb_matrix_set_color(17, 0, 255, 0);
          rgb_matrix_set_color(18, 0, 0, 255);
          rgb_matrix_set_color(19, 0, 255, 0);
          rgb_matrix_set_color(20, 255, 0, 0);
          rgb_matrix_set_color(21, 0, 255, 0);
          rgb_matrix_set_color(22, 0, 0, 255);
          rgb_matrix_set_color(23, 0, 255, 0);
    }
    if (is_caps_word_on())
    {
          rgb_matrix_set_color(24, 255, 0, 0);
          rgb_matrix_set_color(25, 0, 255, 0);
          rgb_matrix_set_color(26, 0, 0, 255);
          rgb_matrix_set_color(27, 0, 255, 0);
          rgb_matrix_set_color(28, 255, 0, 0);
          rgb_matrix_set_color(29, 0, 255, 0);
          rgb_matrix_set_color(30, 0, 0, 255);
          rgb_matrix_set_color(31, 0, 255, 0);
          rgb_matrix_set_color(32, 255, 0, 0);
          rgb_matrix_set_color(33, 0, 255, 0);
          rgb_matrix_set_color(34, 0, 0, 255);
          rgb_matrix_set_color(35, 0, 255, 0);
    }
  #endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_select_word(keycode, record, SELWORD)) { return false; }
  switch (keycode) {
    case MACRO1:
        if (record->event.pressed) {
            SEND_STRING("B1tl0ck3r");
        }
        return false;
    case MACRO2:
        if (record->event.pressed) {
            SEND_STRING("H3ct0rLv1s");
        }
        return false;
    case MACRO3:
        if (record->event.pressed) {
            SEND_STRING("R34lp3C4str1ll0");
        }
        return false;
    case MACRO4:
        if (record->event.pressed) {
            SEND_STRING("2417906");
        }
        return false;
    case MACRO5:
        if (record->event.pressed) {
            SEND_STRING("qpls2g7xlj3nbh7bsodssoiwzj5iejxsxbowqysmp7upqzewif2a");
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
    #ifdef RGB_MATRIX_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgb_matrix_default();
          rgb_matrix_enable();
        }
      #endif
      break;
  }
  return true;
}

// Listener function => Triggered when you start recording a macro.
void dynamic_macro_record_start_user(void) 
{
    isRecording = true;
    isRecordingLedOn = true;
    // timer_read() is a built-in function in qmk. => It read the current time
    recording_timer = timer_read();
}

// Listener function => Triggered when the macro recording is stopped.
void dynamic_macro_record_end_user(int8_t direction) 
{
    isRecording = false;
    isRecordingLedOn = false;
}

uint16_t get_autoshift_timeout(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case AUTO_SHIFT_NUMERIC:
            return 2 * get_generic_autoshift_timeout();
        case AUTO_SHIFT_SPECIAL:
            return get_generic_autoshift_timeout() + 50;
        case AUTO_SHIFT_ALPHA:
        default:
            return get_generic_autoshift_timeout();
    }
}

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_DOT:
            return true;
        case KC_COMM:
            return true;
        case KC_SLSH:
            return true;
        case KC_SCLN:
            return true;
        case KC_QUOT:
            return true;
        default:
            return false;
    }
}
