#pragma once

#define LWR_TAB LT(_LOWER, KC_TAB)
#define LW2_ESC LT(_LOWER2, KC_ESC)

#define RS2_BSP LT(_RAISE2, KC_BSPC)
#define RSE_ENT LT(_RAISE, KC_ENT)

/* Home Row, outer column */
#define LCTLESC LCTL_T(KC_ESC)
#define RCTLENT RCTL_T(KC_ENT)

/* Home Row Mods, Dvorak, LH */
#define LALTT_A LALT_T(KC_A)
#define LGUIT_O LGUI_T(KC_O)
#define LCTLT_E LCTL_T(KC_E)
#define LSFTT_U LSFT_T(KC_U)

/* Home Row Mods, QWERTY, LH */
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

#define ___BASE_BOTTOM_ROW___ \
  _______, _______, _______, LWR_TAB, LW2_ESC,    KC_SPC,      RS2_BSP,    RSE_ENT, _______, _______, _______


// macOS
#define CODE16_MACOS_DESKTOP_LEFT  LCTL(KC_LEFT)
#define CODE16_MACOS_DESKTOP_RIGHT LCTL(KC_RIGHT)

// Linux, Gnome shell
#define CODE16_LINUX_DESKTOP_LEFT  LCTL(LALT(KC_LEFT))
#define CODE16_LINUX_DESKTOP_RIGHT LCTL(LALT(KC_RIGHT))

// Windows 10
#define CODE16_WIN_DESKTOP_LEFT  LCTL(LGUI(KC_LEFT))
#define CODE16_WIN_DESKTOP_RIGHT LCTL(LGUI(KC_RIGHT))
