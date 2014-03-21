#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: plain */
    KEYMAP(   // LAYER 0: Default
      ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS, EQL, BSLS, GRV,\
      TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC, RBRC, BSPC,    \
      LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT, ENT,           \
      LSFT,     Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,      UP,       \
      NLCK,LALT,LGUI,FN0, SPC,         FN1,                        LEFT,DOWN,RGHT
    ),
    KEYMAP(   // LAYER 1: Function
      TRNS,F1  ,F2  ,F3  ,F4  ,F5  ,F6  ,F7  ,F8  ,F9  ,F10 ,F11 ,F12 ,TRNS,TRNS,  \
      TRNS,TRNS,TRNS,END ,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PGUP,TRNS,TRNS,DELETE,     \
      TRNS,HOME,TRNS,TRNS,TRNS,TRNS,LEFT,DOWN,UP  ,RGHT,TRNS,TRNS,TRNS,            \
      CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,PGDN,TRNS,TRNS,TRNS,TRNS,TRNS,                 \
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS                                 \
    ),
    KEYMAP(   // LAYER 2: Shift # DISABLED
      GRV ,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,       \
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,            \
      LSFT,TRNS,TRNS,TRNS,TRNS,TRNS,PGDN,TRNS,TRNS,TRNS,TRNS,TRNS,                 \
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS                                 \
    ),
    KEYMAP(   // LAYER 3: Mouse
      NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE, \
      NONE,NONE,NONE,NONE,NONE,NONE,NONE,BTN1,BTN3,BTN2,NONE,NONE,NONE,NONE,       \
      NONE,NONE,NONE,NONE,NONE,NONE,MS_L,MS_D,MS_U,MS_R,NONE,NONE,NONE,            \
      NONE,NONE,NONE,NONE,NONE,NONE,PGDN,NONE,NONE,NONE,NONE,NONE,                 \
      NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE                                 \
    ),
};

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),          // FN0 switch to layer 1
    [1] = ACTION_LAYER_MOMENTARY(3),          // FN1 switch to layer 3
//  [2] = ACTION_LAYER_MOMENTARY(2),          // FN2 switch to layer 2

};


//const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    /* 0: Default layer
//     * ,-----------------------------------------------------------.
//     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|
//     * |-----------------------------------------------------------|
//     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Bspc |
//     * |-----------------------------------------------------------|
//     * |Ctrl  |  A|  S|  D|  F|  G|  H|  J|  K|  L|Fn3|  '|Return  |
//     * |-----------------------------------------------------------|
//     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Fn |
//     * |-----------------------------------------------------------|
//     * |    |Gui |Alt |      Space             |    |Alt |Gui |    |
//     * `-----------------------------------------------------------'
//     */
//    KEYMAP_HHKB(
//        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS, GRV, \
//        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSPC,      \
//        LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,       \
//        LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     RSFT,FN0,       \
//        NO,  LGUI,LALT,          SPC,                     NO,  RALT,RGUI,NO),
//    /* 1: HHKB Fn layer
//     * ,-----------------------------------------------------------.
//     * |Pwr| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Del|
//     * |-----------------------------------------------------------|
//     * |Caps |   |   |   |   |   |   |   |Psc|Slk|Pus|Up |   |     |
//     * |-----------------------------------------------------------|
//     * |      |VoD|VoU|Mut|Ejc|   |  *|  /|Hom|PgU|Lef|Rig|Enter   |
//     * |-----------------------------------------------------------|
//     * |        |   |   |   |   |   |  +|  -|End|PgD|Dow|      |   |
//     * |-----------------------------------------------------------|
//     * |    |    |    |                        |    |    |    |    |
//     * `-----------------------------------------------------------'
//     */
//    KEYMAP_HHKB(
//        PWR, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS, DEL,  \
//        CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PSCR,SLCK,PAUS,UP,  TRNS,TRNS,      \
//        TRNS,VOLD,VOLU,MUTE,EJCT,TRNS,PAST,PSLS,HOME,PGUP,LEFT,RGHT,     PENT,      \
//        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PPLS,PMNS,END, PGDN,DOWN,     TRNS,TRNS,      \
//        TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,TRNS),
//};
//
///*
// * Fn action definition
// */
//const uint16_t PROGMEM fn_actions[] = {
//    [0] = ACTION_LAYER_MOMENTARY(1),
//};
