/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"
#include "definitions.h"


enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _SYM,
  _NUMB,
  _NAV,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  BACKLIT,
};

#define LOWER   MO(_SYM)
#define RAISE   MO(_NUMB)
#define NAV     MO(_NAV)

// Left-hand home row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define SFT_D LSFT_T(KC_D)
#define CTL_F LCTL_T(KC_F)

// Right-hand home row mods
#define CTL_J RCTL_T(KC_J)
#define SFT_K RSFT_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUISCLN RGUI_T(KC_SCLN)

#define SYM_SPC LT(_SYM, KC_SPC)
#define NUMB_BS LT(_NUMB, KC_BSPC)
#define NAV_ESC LT(_NAV, KC_ESC)
#define SYM_ENT LT(_SYM, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |Esc  |  Bksp |  Y  |   U  |   I  |   O  |   P   |
 * |------+------+------+------+------+-----+-------+-----+------+------+------+-------|
 * |   A  |   S  |   D  |   F  |   G  |  "  |   '   |  H  |   J  |   K  |   L  | ; [Ö] |
 * |------+------+------+------+------+-----+-------+-----+------+------+------+-------|
 * |   Z  |   X  |   C  |   V  |   B  |Shift| Shift |  N  |   M  |   ,  |   .  |   /   |
 * |------+------+------+------+------+-----+-----+--------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | SPC  |  Nav |     TAB     |Raise | Numb | Numb |Brite | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_ESC,  KC_BSPC, KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,
    GUI_A,   ALT_S,   SFT_D,   CTL_F,   KC_G,    KC_DQT,  KC_QUOT, KC_H,    CTL_J,   SFT_K,   ALT_L,    KC_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LSFT, KC_RSFT, KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,
    KC_LCTL, KC_LGUI, KC_LALT, NAV_ESC, SYM_SPC, KC_TAB,  KC_TAB,  SYM_ENT, NUMB_BS, _______, BACKLIT,  KC_RCTL
),

/* Colemak-dh
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  | ; [ö]| Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | Nav  |Lower |    Space    |Raise | Numb | Numb |Brite | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT ,
    KC_LCTL, KC_LGUI, KC_LALT, NAV,     LOWER,   KC_SPC,  KC_SPC,  RAISE,   _______, _______, BACKLIT,  KC_RCTL
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |       |       | ^  |   &  |   *  |   |  |  DEL |
 * |------+------+------+------+------+-------+-------+----+------+------+------+------|
 * |   \  |   )  |   =  |   (  |      |       |       |    |   -  |   {  |   +  |  }   |
 * |------+------+------+------+------+-------+-------+----+------+------+------+------|
 * |      |      |      |   `  |      |       |       |    |   _  |[ [å] |   ~  |  ]   |
 * |------+------+------+------+------+-------+-------+----+------+------+------+------|
 * |      |      |      |      |              |       |    |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYM] = LAYOUT_planck_grid(
     KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR,  KC_PIPE, KC_DEL,
     KC_BSLS, KC_RPRN, KC_EQL,  KC_LPRN, _______, _______, _______, _______, KC_MINS, KC_LCBR,  KC_PLUS, KC_RCBR,
     _______, _______, _______, KC_GRV,  _______, _______, _______, _______, KC_UNDS, KC_LBRC,  KC_TILD, KC_RBRC,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ,  |   7  |   8  |  9   |      |      |      |      |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   0  |   4  |   5  |  6   |      |      |      |      |  F4  |  F5  |  F6  |  F11 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   .  |   1  |   2  |  3   |      |      |      |      |  F1  |  F2  |  F3  |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMB] = LAYOUT_planck_grid(
    KC_COMM, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______, KC_F7,   KC_F8,    KC_F9,   KC_F10,
    KC_0,    KC_4,    KC_5,    KC_6,    _______, _______, _______, _______, KC_F4,   KC_F5,    KC_F6,   KC_F11,
    KC_DOT,  KC_1,    KC_2,    KC_3,    _______, _______, _______, _______, KC_F1,   KC_F2,    KC_F3,   KC_F12,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,
),

/* Navigation
* ,-----------------------------------------------------------------------------------.
* |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |      | Left | DOWN |  UP  |RIGHT | ' [ä]|      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |      |  "   |      |      |      |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |             |      |      |      |      |      |
* `-----------------------------------------------------------------------------------'
*/
[_NAV] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_DEL,
    _______, _______, _______, _______, _______, _______, _______,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  KC_QUOT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NAV, _SYM, _ADJUST);
}

/**
 * process_record_user is called by QMK during key processing before
 * the actual key event is handled.
 *
 * More info: https://beta.docs.qmk.fm/using-qmk/guides/custom_quantum_functions
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return RECORD_KEYPRESS_HANDLED;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return RECORD_KEYPRESS_HANDLED;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return RECORD_KEYPRESS_HANDLED;
      break;
  }
  return RECORD_KEYPRESS_PASSTHROUGH;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_SYM)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
            if (active) {
                layer_off(_ADJUST);
            }
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
