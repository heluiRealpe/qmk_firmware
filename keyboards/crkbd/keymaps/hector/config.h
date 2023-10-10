#pragma once

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define DYNAMIC_KEYMAP_LAYER_COUNT 6

// Tap-hold configuration for home row mods.
#define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define SENTENCE_CASE_BUFFER_SIZE 10

#define QUICK_TAP_TERM_PER_KEY
#define QUICK_TAP_TERM 120

// Improved mouse key defaults
// Delay between pressing a key and cursor movement
#define MOUSEKEY_DELAY 16
// Time between cursor movements in milliseconds
#define MOUSEKEY_INTERVAL 16
// Step size for acceleration
#define MOUSEKEY_MOVE_DELTA 9
#define MOUSEKEY_MAX_SPEED 12
#define MOUSEKEY_TIME_TO_MAX 70
#define MOUSEKEY_WHEEL_DELAY 16
#define MOUSEKEY_WHEEL_INTERVAL 30
#define MOUSEKEY_WHEEL_MAX_SPEED 10
#define MOUSEKEY_WHEEL_TIME_TO_MAX 9

//configure how long to wait after last activity. 120000ms = 2 mins
#define SCREENSAVE_DELAY 120000

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

#define NO_ALT_REPEAT_KEY

#define CAPS_WORD_INVERT_ON_SHIFT
#define CAPS_WORD_IDLE_TIMEOUT 3000  // 3 seconds.
