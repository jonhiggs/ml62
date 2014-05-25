#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: plain */
    KEYMAP(   // LAYER 0: Default
      FN10,1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS, EQL, BSLS, GRV,\
      TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC, RBRC, BSPC,    \
      LCTL,FN14,S,   D,   F,   G,FN13,   J,   K,   L,   SCLN,QUOT, ENT,           \
      LSFT,     Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,      UP,       \
      FN15,LGUI,FN1,LALT, FN11,       FN2,                        LEFT,DOWN,RGHT
    ),
    KEYMAP(   // LAYER 1: Function1
      TRNS,F1  ,F2  ,F3  ,F4  ,F5  ,F6  ,F7  ,F8  ,F9  ,F10 ,F11 ,F12 ,NO,  NO, \
      TRNS,NO,  NO,  END ,NO,  NO,  NO,  PGUP,NO,  NO,  NO,  NO,  NO,  DELETE,  \
      TRNS,NO,  NO,  PGDN,NO,  NO,  LEFT,DOWN,UP  ,RGHT,NO,  NO,  NO,           \
      TRNS,NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,                \
      TRNS,TRNS,TRNS,TRNS,FN12,NO,  NO,  NO,  NO                                \
    ),
    KEYMAP(   // LAYER 2: Function2
      NO  ,F14,F15,NO, NO,NO, NO,  MPRV,MPLY,MNXT,MUTE,VOLD,VOLU,NO,NO, \
      NO  ,NO,NO,NO, NO,NO, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,    \
      TRNS,A, NO,NO, NO,NO, H,   NO,  NO,  NO,  NO,  NO,  NO,       \
      CAPS,NO,NO,NO, NO,NO, NO,  NO,  NO,  NO,  NO,  NO,          \
      TRNS,TRNS,FN1,TRNS,TRNS,FN2,NO,  NO,  NO                        \
    ),
};

/* id for user defined functions */
enum function_id {
    BACKSPACE,
    ESC,
    HOME,
    SPACE,
    SPOTLIGHT,
    TMUX,
};

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_MOMENTARY(1),          // FN1 switch to layer 1
    [2] = ACTION_LAYER_MOMENTARY(2),          // FN2 switch to layer 2
    [10] = ACTION_FUNCTION(ESC),              // Special ESC key.
    [11] = ACTION_FUNCTION(SPACE),            // Special Space Key.
    [12] = ACTION_FUNCTION(SPOTLIGHT),        // Special Spotlight Key.
    [13] = ACTION_FUNCTION(BACKSPACE),        // Ctrl-H sends backspace.
    [14] = ACTION_FUNCTION(HOME),             // Ctrl-A sends home.
    [15] = ACTION_FUNCTION(TMUX),             // tmux bind prefix
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  keyevent_t event = record->event;
  tap_t tap = record->tap;

  switch (id) {
    case BACKSPACE:
      if (event.pressed) {
        // press the keys
        if (get_mods() & MOD_LCTL) {
          del_mods(MOD_BIT(KC_LCTRL));
          add_key(KC_BSPC);
          send_keyboard_report();
          add_mods(MOD_BIT(KC_LCTRL));
        } else {
          add_key(KC_H);
          send_keyboard_report();
        }
      } else {
        // release the keys.
        del_key(KC_BSPC);
        del_key(KC_H);
        send_keyboard_report();
      }
      break;

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

    case HOME:
      if (event.pressed) {
        // press the keys
        if (get_mods() & MOD_LCTL) {
          del_mods(MOD_BIT(KC_LCTRL));
          add_key(KC_HOME);
          send_keyboard_report();
          add_mods(MOD_BIT(KC_LCTRL));
        } else {
          add_key(KC_A);
          send_keyboard_report();
        }
      } else {
        // release the keys.
        del_key(KC_HOME);
        del_key(KC_A);
        send_keyboard_report();
      }
      break;

    case SPACE:
      if (event.pressed) {
        // press the keys
        if (get_mods() & MOD_LCTL) {
          del_mods(MOD_BIT(KC_LCTRL));
          add_key(KC_SPC);
          send_keyboard_report();
          add_mods(MOD_BIT(KC_LCTRL));
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

    case SPOTLIGHT:
      if (event.pressed) {
        add_mods(MOD_BIT(KC_LGUI));
        add_key(KC_SPC);
        send_keyboard_report();
        del_mods(MOD_BIT(KC_LGUI));
        del_key(KC_SPC);
        send_keyboard_report();
      }
      break;

    case TMUX:
      if (event.pressed) {
        add_mods(MOD_BIT(KC_LALT));
        add_key(KC_P);
        send_keyboard_report();
        del_key(KC_P);
        send_keyboard_report();
      } else {
        del_mods(MOD_BIT(KC_LALT));
        send_keyboard_report();
      }
      break;
  }

}
