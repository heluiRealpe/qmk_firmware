#include QMK_KEYBOARD_H

#include "features/achordion.h"
#include "features/repeat_key.h"
#include "features/select_word.h"
#include "features/sentence_case.h"

enum Layers{
    L_QWERTY, L_LOWER, L_RAISE, L_MOV, L_NUM, L_ADJUST
};

enum custom_keycodes {
  REPEAT = SAFE_RANGE,
  SELWORD,
  SELLINE,
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
    |        |BrowHome|BrowBack|BroReloa|BroSearc|BoForwar|      | Insert |        |        |        |        |       |
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
      _______, KC_ESC , LALTTAB, RCTRTAB, REPEAT , KC_TAB ,                      KC_BSLS, KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, _______,
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
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, QK_BOOT, _______,
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
      _______, KC_F11 , KC_F12 , _______, _______, _______,                      SRCHSEL, SELWORD, SELLINE, _______, _______, _______,
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
  // If you quickly hold a tap-hold key after tapping it, the tap action is
  // repeated. Key repeating is useful e.g. for Vim navigation keys, but can
  // lead to missed triggers in fast typing. Here, returning 0 means we
  // instead want to "force hold" and disable key repeating.
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
  if (!process_repeat_key(keycode, record, REPEAT)) { return false; }
  if (!process_select_word(keycode, record, SELWORD)) {return false;}
  if (!process_sentence_case(keycode, record)) { return false; }

  if (record->event.pressed) { stop_screensaver = false; }   //turn off screensaver mode on any keypress

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
            SEND_STRING("pacman -Syu");
        }
        return false;
    case MACRO8:
        if (record->event.pressed) {
            SEND_STRING("lepanto");
        }
        return false;
    case MACRO9:
        if (record->event.pressed) {
            SEND_STRING("git pull"); }
        return false;
    case MACRO10:
        if (record->event.pressed) {
            SEND_STRING("git push");
        }
        return false;
    case MACRO11:
        if (record->event.pressed) {
            SEND_STRING("sudo apt update");
        }
        return false;
    case MACRO12:
        if (record->event.pressed) {
            SEND_STRING("sudo apt upgrade");
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
  // Also allow same-hand holds when the other key is in the rows below the
  // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
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

  // Otherwise clear Sentence Case to initial state.
  sentence_case_clear();
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
  select_word_task();
  sentence_case_task();

  if (stop_screensaver) {                                             //if screensaver mode is active
      if (timer_elapsed32(last_activity_timer) > SCREENSAVE_DELAY) {  //and no key has been pressed in more than SCREENSAVE_DELAY ms
          tap_code16(KC_MS_D);
          tap_code16(KC_UP);
          last_activity_timer = timer_read32();                       //  reset last_activity_timer
      }
  }
}
