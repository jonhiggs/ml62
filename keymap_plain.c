#include "keymap_common.h"

// TODO
// media keys

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: plain */
    KEYMAP(   // LAYER 0: Default
      FN10,1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS, EQL, BSLS, GRV,\
      TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC, RBRC, BSPC,    \
      LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT, ENT,           \
      LSFT,     Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,      UP,       \
      NLCK,LALT,LGUI,FN0, FN11,       FN1,                        LEFT,DOWN,RGHT
    ),
    KEYMAP(   // LAYER 1: Function
      NO,  F1  ,F2  ,F3  ,F4  ,F5  ,F6  ,F7  ,F8  ,F9  ,F10 ,F11 ,F12 ,NO,  NO, \
      NO,  NO,  NO,  END ,NO,  NO,  NO,  PGUP,NO,  NO,  NO,  NO,  NO,  DELETE,  \
      NO,  HOME,NO,  PGDN,NO,  NO,  LEFT,DOWN,UP  ,RGHT,NO,  NO,  NO,           \
      CAPS,NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,                \
      NO,  NO,  NO,  FN0, NO,  NO,  NO,  NO,  NO                                \
    ),
    KEYMAP(   // LAYER 2: Mouse
      NO,F14,F15,NO, NO,NO, NO,  MPRV,MPLY,MNXT,MUTE,VOLD,VOLU,NO,NO, \
      NO,NO,NO,NO, NO,NO, NO,  BTN1,BTN3,BTN2,NO,  NO,  NO,  NO,    \
      NO,NO,NO,NO, NO,NO, MS_L,MS_D,MS_U,MS_R,NO,  NO,  NO,       \
      NO,NO,NO,NO, NO,NO, NO,  NO,  NO,  NO,  NO,  NO,          \
      NO,NO,NO,FN0,NO,FN1,NO,  NO,  NO                        \
    ),
};

/* id for user defined functions */
enum function_id {
    ESC,
    SPACE,
};

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),          // FN0 switch to layer 1
    [1] = ACTION_LAYER_MOMENTARY(2),          // FN1 switch to layer 2
    [10] = ACTION_FUNCTION(ESC),              // Special ESC key.
    [11] = ACTION_FUNCTION(SPACE),            // Special Space Key.
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  keyevent_t event = record->event;
  tap_t tap = record->tap;

  switch (id) {
    case ESC:
      if (event.pressed) {
        // press the keys
        if (get_mods(MOD_BIT(KC_LSHIFT))) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        // release the keys.
        del_key(KC_GRV);
        del_key(KC_ESC);
        send_keyboard_report();
      }
      break;

    case SPACE:
      if (event.pressed) {
        // press the keys

        // if control is pressed, release it before sending a space.
        if (get_mods(MOD_BIT(KC_LCTRL))) {
          del_mods(MOD_BIT(KC_LCTRL));
          add_key(KC_SPC);
          send_keyboard_report();
          add_mods(MOD_BIT(KC_LCTRL));
          send_keyboard_report();
        } else {
          add_key(KC_SPC);
          send_keyboard_report();
        }
      } else {
        // release the keys.
        del_key(KC_SPC);
        send_keyboard_report();
      }
      break;
  }
}
