#include "keymap_common.h"

// TODO
// ctrl-space to send space
// media keys
// shift-esc to send ~

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: plain */
    KEYMAP(   // LAYER 0: Default
      FN10,1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS, EQL, BSLS, GRV,\
      TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC, RBRC, BSPC,    \
      LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT, ENT,           \
      LSFT,     Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,      UP,       \
      NLCK,LALT,LGUI,FN0, SPC,         FN1,                        LEFT,DOWN,RGHT
    ),
    KEYMAP(   // LAYER 1: Function
      NO,  F1  ,F2  ,F3  ,F4  ,F5  ,F6  ,F7  ,F8  ,F9  ,F10 ,F11 ,F12 ,NO,  NO,    \
      NO,  NO,  NO,  END ,NO,  NO,  NO,  PGUP,NO,  NO,  NO,  NO,  NO,  DELETE,     \
      NO,  HOME,NO,  PGDN,NO,  NO,  LEFT,DOWN,UP  ,RGHT,NO,  NO,  NO,              \
      CAPS,NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,                   \
      NO,  NO,  NO,  FN0, NO,  NO,  NO,  NO,  NO                                   \
    ),
    KEYMAP(   // LAYER 2: Shift
      GRV ,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,       \
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,            \
      LSFT,TRNS,TRNS,TRNS,TRNS,TRNS,PGDN,TRNS,TRNS,TRNS,TRNS,TRNS,                 \
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS                                 \
    ),
    KEYMAP(   // LAYER 3: Mouse
      NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,   \
      NO,  NO,  NO,  NO,  NO,  NO,  NO,  BTN1,BTN3,BTN2,NO,  NO,  NO,  NO,         \
      NO,  NO,  NO,  NO,  NO,  NO,  MS_L,MS_D,MS_U,MS_R,NO,  NO,  NO,              \
      NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,                   \
      NO,  NO,  NO,  FN0, NO,  FN1, NO,  NO,  NO                                   \
    ),
};

/* id for user defined functions */
enum macro_id {
    LSHIFT_ESC,
};

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),          // FN0 switch to layer 1
    [1] = ACTION_LAYER_MOMENTARY(3),          // FN1 switch to layer 3
//  [2] = ACTION_LAYER_MOMENTARY(2),          // FN2 switch to layer 2
    [10] = ACTION_MACRO_TAP(LSHIFT_ESC),   // Function: RShift with tap ')'
};

/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    keyevent_t event = record->event;
    tap_t tap = record->tap;

    switch (id) {
      case SHIFT_ESC:
        if (tap.count > 0 && !tap.interrupted) {
          if keyboard_report->mods == MOD_BIT(KC_LSHIFT) {
            return (
              // if LSHIFT is pressed then send a ~
              event.pressed ? MACRO( D(LSHIFT), D(GRV), U(GRV), U(LSHIFT), END ) : MACRO_NONE
            );
          else
            return (
              // if LSHIFT is not pressed then send an ESC
              event.pressed ? MACRO( D(ESC), U(ESC), END ) : MACRO_NONE
            );
          }

        } else {
          return (event.pressed ?
              MACRO( D(LSHIFT), END ) : MACRO( U(LSHIFT), END ) );
        }
    }
    return MACRO_NONE;
}
