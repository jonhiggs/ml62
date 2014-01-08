#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: plain */
    KEYMAP(ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS, EQL, BSLS, GRV,\
           TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC, RBRC, BSPC,    \
           LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT, ENT,           \
           LSFT,     Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,      UP,       \
           FN1,LALT,LGUI,FN0, SPC,                                     LEFT,DOWN,RGHT)
};
const uint16_t PROGMEM fn_actions[] = {};
