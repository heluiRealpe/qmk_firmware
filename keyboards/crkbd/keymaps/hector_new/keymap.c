#include QMK_KEYBOARD_H

#include "features/achordion.h"
#include "quantum.h"

enum Layers{
    L_QWERTY, L_LOWER, L_RAISE, L_MOV, L_NUM, L_ADJUST
};

enum custom_keycodes {
//  SELWORD,
  SELLINE = SAFE_RANGE,
  SRCHSEL,
  QWERTY,
  LOWER,
  RAISE,
  MOV,
  NUM,
  UNDO,
  CUT,
  COPY,
  PASTE,
  REDO,
  ADJUST,
  MACRO1,
  MACRO2,
  MACRO3,
  MACRO4,
  MACRO5,
  MACRO6,
  MACRO7,
  MACRO8,
  MACRO9,
  MACRO10,
  MACRO11,
  MACRO12,
  MACRO13,
  MACRO14,
  TD_Q_TAB = 0,
  TD_A_ESC,
  TD_ONEGR,
  TD_EXTIL,
  TD_SCLQT,
  TD_WHOME,
  TD_EEND,
  TD_ENE,
  NO_SLEEP  //custom macro key.  turns on screensaver mode
};

#define KC_CAD LALT(LCTL(KC_DEL))
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
#define UNDO LCTL(KC_Z)
#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define REDO LCTL(KC_Y)
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
#define LALT_COM LALT_T(KC_COMM)
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
 *
  [_TPL] = LAYOUT_wrapper(
  //,-----------------------------------------------------.      ,----------------------------------------------------.
    |        |   Q    |   W    |   E    |   R    |   T    |      |    Y   |   U    |   I    |   O    |   P    |       |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    |        |   A    |   S    |   D    |   F    |   G    |      |    H   |   J    |   K    |   L    |   ;:   |       |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    |        |   Z    |   X    |   C    |   V    |   B    |      |    N   |   M    |   ,<   |   .>   |   /?   |       |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
                                    ,-----------------------,  ,-----------------------.
                                    | LGUI  | Lower*|AltSpac|  | Space | Raise*|RAltCi |
                                   /|-------+-------+-------'  +-------+-------+-------|\
  ),
*/
 [L_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_QTAB,KC_WHOME, KC_EEND,   KC_R ,  KC_T  ,                       KC_Y  ,   KC_U ,  KC_I  ,  KC_O  ,  KC_P  , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_AESC,  KC_S  ,  KC_D  ,   KC_F ,  KC_G  ,                       KC_H  ,  KC_J  ,  KC_K  ,  KC_L  ,KC_SCLQT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,LSHIFT_Z, LCTRL_X, LALT_C , LGUI_V ,  KC_B  ,                      KC_ENE , RGUIL_M,RALT_COM,RCTR_DOT,RSHIFT_H, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,  LOWER , SPCNUM ,    KC_SPC , RAISE  , XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

/*
 * LOWER LAYER
  [_TPL] = LAYOUT_wrapper(
  //,-----------------------------------------------------.      ,----------------------------------------------------.
    |   `    |   1    |   2    |   3    |   4    |   5    |      |     6  |   7    |   8    |   9    |   0    |       |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    |        |        |        |        |        |        |      |    \   |   -    |   =    |   [    |   ]    |       |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    |        |        |        |        |        |        |      |        |        |        |        |        |       |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
                                    ,-----------------------,  ,-----------------------.
                                    |       | ******|       |  |       |       |CapLock|
                                   /|-------+-------+-------'  +-------+-------+-------|\
  ),
*/
  [L_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,KC_ONEGR,  KC_2  , KC_3   , KC_4   , KC_5   ,                      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_ESC , LALTTAB, RCTRTAB, QK_REP , KC_TAB ,                      KC_BSLS, KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, UNDO   , CUT    , COPY   , PASTE  , REDO   ,                      KC_CAPS, CW_TOGG,LALT_COM, KC_DOT ,KC_SLASH, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, KC_ENT ,    AJSTLAY, MOVLAY , _______
                                      //`--------------------------'  `--------------------------'
  ),

/*
 * RAISE LAYER
  [_TPL] = LAYOUT_wrapper(
  //,-----------------------------------------------------.      ,----------------------------------------------------.
    |   ~    |   !    |   @    |   #    |   $    |   %    |      |    ^   |    &   |   *    |   (    |   )    |       |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    |        |        | Screen | WnShoo |        |        |      |    |   |   _    |   +    |   {    |   }    |       |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    |        |  PLY2  |  REC2  |  PLY1  |  REC1  |  RSTP  |      | Left   | Down   |  Up    | Right  |PgDown  |       |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
                                    ,-----------------------,  ,-----------------------.
                                    |       |       |       |  |       | ******|       |
                                   /|-------+-------+-------'  +-------+-------+-------|\
  ),
*/
  [L_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,KC_EXTIL,  KC_AT , KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_PSCR, WINSHOT, KC_PGUP, KC_PGDN, KC_CAD ,                      KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, DM_PLY2, DM_REC2, DM_PLY1, DM_REC1, DM_RSTP,                      KC_LEFT, KC_DOWN, KC_UP  ,KC_RIGHT, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, MOVLAY , _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

/*
 * L_ADJUST LAYER
  [_TPL] = LAYOUT_wrapper(
  //,-----------------------------------------------------.      ,----------------------------------------------------.
    |        |        |        |  End   |        |        |      |        | Bri+   |   Bri- |        |        |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    |        | Home   |        | KC_BRID| KC_BRIU|        |      |        | RGB+   |   RGB- |        |        |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    |Static  |BLtogg  |BLstep  |        |        |        |      |        | SAT+   |   SAT- |        | QK_BOOT|
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
                                    ,-----------------------,  ,-----------------------.
                                    |       | ******|       |  | ******|       |       |
                                   /|-------+-------+-------'  +-------+-------+-------|\
  ),
*/
  [L_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, KC_END , _______, _______,                      MACRO1 , MACRO3 , MACRO4 , MACRO13,NO_SLEEP, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_HOME, _______, KC_BRIU, KC_BRID, _______,                      MACRO2 , MACRO8 , MACRO14, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, AC_TOGG, _______, _______, QK_BOOT, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,   _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

/*
 * NUM LAYER
  [_TPL] = LAYOUT_wrapper(
  //,-----------------------------------------------------.      ,----------------------------------------------------.
    |        |  F1    |  F2    |  F3    |  F4    |  F5    |        MACRO1 | MACRO1 | MACRO1 | Delete |BackSpac|       |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    |        |  F6    |  F7    |  F8    |  F9    |  F10   |      | MACRO1 | MACRO1 | MACRO1 | MACRO1 |   '"   |       |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
                                    ,-----------------------,  ,-----------------------.
                                    |       |       | ******|  |       |       |       |
                                   /|-------+-------+-------'  +-------+-------+-------|\
  ),
*/
  [L_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                      MACRO12, MACRO9 , MACRO10, KC_DEL , KC_BSPC, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,                      MACRO11, MACRO5 , MACRO6 , MACRO7 , KC_QUOT, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_F11 , KC_F12 , _______, _______, _______,                      SRCHSEL, _______, SELLINE, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

/*
 * L_MOV LAYER
  [_TPL] = LAYOUT_wrapper(
  //,-----------------------------------------------------.      ,----------------------------------------------------.
    |        |        |        |        |        |        |         PlaSto|  Vol-  |  Vol+  |  Mute  |        |       |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    |        |        |        |        | MOUS1  | MOUS2  |         MOUSL | MOUSD  | MOUSU  | MOUSR  |        |SySleep|
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    |        |        | ACC0   | ACC1   | ACC2   |        |        WheelL | WheelD | WheelU | WheelR |        |       |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
                                    ,-----------------------,  ,-----------------------.
                                    |       | ******|       |  |       | ******|       |
                                   /|-------+-------+-------'  +-------+-------+-------|\
  ),
*/
  [L_MOV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, QWERTY , KC_ACL0, KC_ACL1, KC_ACL2, QWERTY ,                      KC_MPLY, KC_VOLD, KC_VOLU, KC_MUTE, QWERTY , _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, QWERTY , QWERTY , KC_BTN2, KC_BTN1, QWERTY ,                      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, QWERTY , _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, QWERTY ,                      KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, QWERTY , _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

combo_t key_combos[] = {};
uint16_t COMBO_LEN = 0;

bool stop_screensaver = false;     //screensaver mode status
uint32_t last_activity_timer = 0;

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    // Increase the tapping term a little for slower ring and pinky fingers.
   // LEFT HAND
    case KC_QTAB:
    case KC_AESC:
    case LSHIFT_Z:
    case KC_WHOME:
    case LCTRL_X:
    // RIGHT HAND
    case KC_SCLQT:
    case RSHIFT_H:
    case RCTR_DOT:
      return TAPPING_TERM + 15;

    default:
      return TAPPING_TERM;
  }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    // Repeating is useful for Vim navigation keys.
    case KC_H:
    case KC_J:
    case KC_K:
    case KC_L:
      return QUICK_TAP_TERM;  // Enable key repeating.
    default:
      return 0;  // Otherwise, force hold and disable key repeating.
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if (!process_achordion(keycode, record)) { return false; }

  if (record->event.pressed) { stop_screensaver = false; }   //turn off screensaver mode on any keypress

  switch (keycode) {
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
    case MACRO13:
        if (record->event.pressed) {
            SEND_STRING("B3l$nRv1zF3rn$nd3z");
        }
        return false;
    case MACRO14:
        if (record->event.pressed) {
            SEND_STRING("Sonconato1");
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
    case NO_SLEEP:
        if (record->event.pressed) {               //if NO_SLEEP is pressed
            SEND_STRING("stop_screensaver");
            stop_screensaver = !stop_screensaver;  //turn on screensaver mode
            last_activity_timer = timer_read32();  //reset timer
        }
        return false;
        break;
  }
  return true;
}

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
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, uint16_t other_keycode, keyrecord_t* other_record) {
  if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 4) {
    return true;
  }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
    case LOWER:
    case RAISE:
    case SPCNUM:
    case MOVLAY:
    case AJSTLAY:
    case UNDO:
    case CUT:
    case COPY:
    case PASTE:
    case REDO:
      return 0;  // Bypass Achordion for these keys.
  }

  return 800;  // Otherwise use a timeout of 800 ms.
}

char sentence_case_press_user(uint16_t keycode, keyrecord_t* record,
                              uint8_t mods) {
  if ((mods & ~(MOD_MASK_SHIFT | MOD_BIT(KC_RALT))) == 0) {
    const bool shifted = mods & MOD_MASK_SHIFT;
    switch (keycode) {
      case KC_LCTL ... KC_RGUI:  // Mod keys.
        return '\0';  // These keys are ignored.

      case KC_A ... KC_Z:
        return 'a';  // Letter key.

      case KC_DOT:  // Both . and Shift . (?) punctuate sentence endings.
        return '.';
      case KC_COMM:  // Shift , (!) is a sentence ending.
        return shifted ? '.' : '#';

      case KC_1 ... KC_0:  // 1 2 3 4 5 6 7 8 9 0
      case KC_MINS ... KC_SCLN:  // - = [ ] ; ` backslash
      case KC_GRV:
      case KC_SLSH:
        return '#';  // Symbol key.

      case KC_SPC:
        return ' ';  // Space key.

      case KC_QUOT:
        return '\'';  // Quote key.
    }
  }

  return '\0';
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

void matrix_scan_user(void) {
  achordion_task();

  if (stop_screensaver) {                                             //if screensaver mode is active
      if (timer_elapsed32(last_activity_timer) > SCREENSAVE_DELAY) {  //and no key has been pressed in more than SCREENSAVE_DELAY ms
          tap_code16(KC_UP);
          last_activity_timer = timer_read32();                       //  reset last_activity_timer
      }
  }
}

bool process_autocorrect_user(uint16_t *keycode, keyrecord_t *record, uint8_t *typo_buffer_size, uint8_t *mods) {
    // See quantum_keycodes.h for reference on these matched ranges.
    switch (*keycode) {
        // Exclude these keycodes from processing.
        case KC_LSFT:
        case KC_RSFT:
        case KC_CAPS:
        case QK_TO ... QK_ONE_SHOT_LAYER_MAX:
//        case QK_LAYER_TAP_TOGGLE ... QK_LAYER_MOD_MAX:
        case QK_ONE_SHOT_MOD ... QK_ONE_SHOT_MOD_MAX:
            return false;

        // Mask for base keycode from shifted keys.
        case QK_LSFT ... QK_LSFT + 255:
        case QK_RSFT ... QK_RSFT + 255:
            if (*keycode >= QK_LSFT && *keycode <= (QK_LSFT + 255)) {
                *mods |= MOD_LSFT;
            } else {
                *mods |= MOD_RSFT;
            }
            *keycode &= 0xFF; // Get the basic keycode.
            return true;
        // Handle custom keycodes
        case L_LOWER:
        case L_RAISE:
        case L_MOV:
        case L_NUM:
        case L_ADJUST:
            *typo_buffer_size = 0;
            return false;

        case KC_QTAB:
            *keycode = KC_Q;
            return true;
        case KC_WHOME:
            *keycode = KC_W;
            return true;
        case KC_EEND:
            *keycode = KC_E;
            return true;
        case KC_AESC:
            *keycode = KC_A;
            return true;
        case LSHIFT_Z:
            *keycode = KC_Z;
            return true;
        case LCTRL_X:
            *keycode = KC_X;
            return true;
        case LALT_C:
            *keycode = KC_C;
            return true;
        case LGUI_V:
            *keycode = KC_V;
            return true;
        case KC_ENE:
            *keycode = KC_N;
            return true;
        case RGUIL_M:
            *keycode = KC_M;
            return true;
    }

    // Disable autocorrect while a mod other than shift is active.
    if ((*mods & ~MOD_MASK_SHIFT) != 0) {
        *typo_buffer_size = 0;
        return false;
    }

    return true;
}
#ifdef OLED_ENABLE
//enum Layers{
//    L_QWERTY, L_LOWER, L_RAISE, L_MOV, L_NUM, L_ADJUST
//};

//oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
//  if (!is_keyboard_master()) {
//    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
//  }
//  return rotation;
//}

void oled_render_layer_state_r2g(void) {

    oled_write_ln_P(PSTR("    "), false);
    oled_write_P(PSTR("Layer: "), false);
    uint8_t layer = get_highest_layer(layer_state);
    switch (layer) {
        case L_QWERTY:
            oled_write_ln_P(PSTR("Q W E R T Y"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("L O W E R"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("R A I S E"), false); break;
        case L_MOV:
            oled_write_ln_P(PSTR("M O U S E"), false);
            break;
        case L_NUM:
            oled_write_ln_P(PSTR("FrOw & MaCrOs"), false);
            break;
        case L_ADJUST:
            oled_write_ln_P(PSTR("A D J U S T"), false);
            break;
        default:
            break;
    }

    if(autocorrect_is_enabled()){
        oled_write_ln_P(PSTR("autocorrect-mode"), false);
    } else {
        oled_write_ln_P(PSTR("    "), false);
    }

    // Host Keyboard LED Status
    // mods
    led_t led_state = host_keyboard_led_state();
    if(led_state.caps_lock){
        oled_write_ln_P(PSTR("CAPS LOCK"), false);
    } else if(get_mods() & MOD_MASK_SHIFT) {
        oled_write_ln_P(PSTR("SHIFT"), false);
    } else if(get_mods() & MOD_MASK_CTRL){
        oled_write_ln_P(PSTR("CTRL"), false);
    } else if(get_mods() & MOD_MASK_ALT){
        oled_write_ln_P(PSTR("ALT"), false);
    } else if(get_mods() & MOD_MASK_GUI){
        oled_write_ln_P(PSTR("GUI"), false);
    } else if(is_caps_word_on()){
        oled_write_ln_P(PSTR("CAPS WORD"), false);
    } else {
        oled_write_ln_P(PSTR("    "), false);
    }
}

//char keylog_str_r2g[24] = {};

const char code_to_name_r2g[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

char key_name_r2g = ' ';
uint16_t last_keycode_r2g;
uint8_t last_row_r2g;
uint8_t last_col_r2g;

void set_keylog_r2g(uint16_t keycode, keyrecord_t *record) {
    key_name_r2g = ' ';
    last_keycode_r2g = keycode;
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { last_keycode_r2g = keycode & 0xFF; }
    if (keycode < 60) {
      key_name_r2g = code_to_name_r2g[keycode];
    }
    last_row_r2g = record->event.key.row;
    last_col_r2g = record->event.key.col;
}

const char *depad_str(const char *depad_str, char depad_char) {
    while (*depad_str == depad_char) ++depad_str;
    return depad_str;
}

void oled_render_keylog_r2g(void) {
    // oled_write(keylog_str_r2g, false);
    const char *last_row_r2g_str = get_u8_str(last_row_r2g, ' ');
    oled_write(depad_str(last_row_r2g_str, ' '), false);
    oled_write_P(PSTR("x"), false);
    const char *last_col_r2g_str = get_u8_str(last_col_r2g, ' ');
    oled_write(depad_str(last_col_r2g_str, ' '), false);
    oled_write_P(PSTR(", k"), false);
    const char *last_keycode_r2g_str = get_u16_str(last_keycode_r2g, ' ');
    oled_write(depad_str(last_keycode_r2g_str, ' '), false);
    oled_write_P(PSTR(":"), false);
    oled_write_char(key_name_r2g, false);
    oled_write_ln_P(PSTR(" "), false);
}

void render_bootmagic_status_r2g(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo_r2g(void) {
    static const char PROGMEM mb_logo[] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f,
0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x83, 0x83, 0x83, 0x83, 0x83, 0xff, 0xff,
0x83, 0x83, 0x83, 0x83, 0xff, 0xff, 0x83, 0x83, 0x83, 0x83, 0x83, 0xff, 0xff, 0x83, 0x83, 0x83,
0x83, 0xff, 0xff, 0x83, 0x83, 0x83, 0x83, 0x83, 0xff, 0xff, 0xff, 0xff, 0x82, 0x82, 0x82, 0x82,
0x82, 0xff, 0xff, 0x83, 0x83, 0x83, 0x83, 0xff, 0xff, 0x83, 0x83, 0x83, 0x83, 0x83, 0xff, 0xff,
0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xfc, 0xfc, 0xfc,
0x9c, 0x9c, 0xfc, 0xfc, 0xf8, 0xf8, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x78, 0x7c, 0x3c,
0x9c, 0xfc, 0xfc, 0xf8, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xf8, 0x3c, 0x3c,
0x9c, 0xbc, 0xfc, 0xb8, 0xb8, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x41, 0x41, 0x41, 0x41, 0x41, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x41, 0x41, 0x41, 0x41, 0x41, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0x41, 0x41, 0x41, 0x41, 0x41, 0xff, 0xff, 0xff, 0xff, 0x41, 0x41, 0x41, 0x41,
0x41, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0x41, 0x41, 0x41, 0x41, 0x41, 0xff, 0xff,
0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f,
0x03, 0x07, 0x0f, 0x3f, 0x3f, 0x3e, 0x38, 0x20, 0x00, 0x00, 0x00, 0x00, 0x38, 0x3c, 0x3e, 0x3f,
0x3f, 0x3f, 0x3b, 0x39, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0f, 0x1f, 0x3f, 0x3c, 0x38,
0x3b, 0x3b, 0x3f, 0x1f, 0x1f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0,
0xf0, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff,
0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
    oled_write_raw_P(mb_logo, sizeof(mb_logo));
    //oled_set_cursor(oled_max_chars()/2,oled_max_lines()/2);
    //oled_write_P(PSTR("R2G"), false);
}

bool oled_task_kb(void) {
    if (!oled_task_user()) { return false; }
    if (is_keyboard_master()) {
        oled_render_layer_state_r2g();
        // oled_render_keylog_r2g();
    } else {
        oled_render_logo_r2g();
    }
    return false;
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog_r2g(keycode, record);
  }
  return process_record_user(keycode, record);
}

#endif // OLED_ENABLE
