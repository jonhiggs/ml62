#include "keymap_common.h"

// TODO
// ctrl-space to send space
// media keys
// shift-esc to send ~

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
      NO,  F1  ,F2  ,F3  ,F4  ,F5  ,F6  ,F7  ,F8  ,F9  ,F10 ,F11 ,F12 ,NO,  NO,    \
      NO,  NO,  NO,  END ,NO,  NO,  NO,  PGUP,NO,  NO,  NO,  NO,  NO,  DELETE,     \
      NO,  HOME,NO,  PGDN,NO,  NO,  LEFT,DOWN,UP  ,RGHT,NO,  NO,  NO,              \
      CAPS,NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,                   \
      NO,  NO,  NO,  FN0, NO,  NO,  NO,  NO,  NO                                   \
    ),
    KEYMAP(   // LAYER 2: Shift # DISABLED
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

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),          // FN0 switch to layer 1
    [1] = ACTION_LAYER_MOMENTARY(3),          // FN1 switch to layer 3
//  [2] = ACTION_LAYER_MOMENTARY(2),          // FN2 switch to layer 2

};

/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  keyevent_t event = record->event;
  tap_t tap = record->tap;

  switch (id) {
    case LSHIFT_ESC:
      if (tap.count > 0 && !tap.interrupted) {
        return (event.pressed ?
          MACRO( D(LSHIFT), D(9), U(9) U(LSHIFT), END ) : MACRO_NONE);
      } else {
        return (event.pressed ?
          MACRO( D(LSHIFT), END ) : MACRO( U(LSHIFT), END ) );
      }
  }
  return MACRO_NONE;
}

/*
 * user defined action function
 */
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  keyevent_t event = record->event;
  tap_t tap = record->tap;

  switch (id) {
    case LSHIFT_ESC:
      // LShft + tap '('
      // NOTE: cant use register_code to avoid conflicting with magic key bind
      if (event.pressed) {
        if (tap.count == 0 || tap.interrupted) {
          //add_mods(MOD_BIT(KC_LSHIFT));
          layer_on(1);
        } else {
          add_mods(MOD_BIT(KC_LSHIFT));
          add_key(KC_GRV);
          send_keyboard_report();
          del_mods(MOD_BIT(KC_LSHIFT));
          del_key(KC_GRV);
          send_keyboard_report();
        }
      } else {
        if (tap.count == 0 || tap.interrupted) {
          //del_mods(MOD_BIT(KC_LSHIFT));
          layer_off(1);
        }
      }
      break;
  }
}
