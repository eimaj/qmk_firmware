/* Copyright 2015-2017 Jack Humbert
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

#include "contra.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers
{
  _QWERTY,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _FUNCTION
};

enum planck_keycodes
{
  QWERTY = SAFE_RANGE,
  COLEMAK,
  LOWER,
  RAISE,
  FUNCTION
};

enum
{
  KC_GTHAN,
  KC_LTHAN,
  KC_ROCKET,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Qwerty
   * ,-----------------------------------------------------------------------------------.
   * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |Hyp(Tb)|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Sft(Ent)|
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | FUNC | Tab  | Alt  | GUI  |Lower | Sft(Space)  |Raise | Left | Down |  Up  |Right |
   * `-----------------------------------------------------------------------------------'
   */
    [_QWERTY] = {
        {KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC},
        {ALL_T(KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT},
        {KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, SFT_T(KC_ENT)},
        {FUNCTION, KC_LCTL, KC_LALT, KC_LGUI, LOWER, SFT_T(KC_SPC), SFT_T(KC_SPC), RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT}},

    /* Lower
   * ,-----------------------------------------------------------------------------------.
   * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   _  |   +  |   {  |   }  |  `   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |  =>  |   |  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |     Play    |      | Home | PgDn | PgUp | End  |
   * `-----------------------------------------------------------------------------------'
   */
    [_LOWER] = {{KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL}, {_______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_GRV}, {_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_ROCKET, KC_BSLS, SFT_T(KC_ENT)}, {_______, _______, _______, _______, _______, KC_MPLY, KC_MPLY, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END}},

    /* Raise
   * ,-----------------------------------------------------------------------------------.
   * |   ~  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   -  |   =  |   [  |   ]  |  `   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |   <  |   >  |   \  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |     Play    |      | Prev | Vol- | Vol+ | Next |
   * `-----------------------------------------------------------------------------------'
   */
    [_RAISE] = {{KC_TILD, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC}, {_______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_GRV}, {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PIPE, SFT_T(KC_ENT)}, {_______, _______, _______, _______, _______, KC_MPLY, KC_MPLY, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT}},

    /* Function
   * ,-----------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |      |  7   |  8   |  9   |      |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |  4   |  5   |  6   |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |  1   |  2   |  3   |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |  0   |  .   |      |      |
   * `-----------------------------------------------------------------------------------'
   */
    [_FUNCTION] = {{_______, _______, _______, _______, _______, _______, _______, _______, KC_7, KC_8, KC_9, KC_BSPC}, {KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, _______, _______, KC_4, KC_5, KC_6, _______}, {KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, _______, KC_1, KC_2, KC_3, _______}, {_______, _______, _______, _______, _______, _______, _______, _______, KC_0, KC_DOT, _______, _______}}};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
  case LOWER:
    if (record->event.pressed)
    {
      layer_on(_LOWER);
      update_tri_layer(_LOWER, _RAISE, _FUNCTION);
    }
    else
    {
      layer_off(_LOWER);
      update_tri_layer(_LOWER, _RAISE, _FUNCTION);
    }
    return false;
    break;

  case RAISE:
    if (record->event.pressed)
    {
      layer_on(_RAISE);
      update_tri_layer(_LOWER, _RAISE, _FUNCTION);
    }
    else
    {
      layer_off(_RAISE);
      update_tri_layer(_LOWER, _RAISE, _FUNCTION);
    }
    return false;
    break;

  case FUNCTION:
    if (record->event.pressed)
    {
      layer_on(_FUNCTION);
    }
    else
    {
      layer_off(_FUNCTION);
    }
    return false;
    break;

  // MACROS
  case KC_ROCKET:
    if (record->event.pressed)
    {
      SEND_STRING("=>"); // this is our macro!
      return false;
    }
    return false;
    break;
  }
  return true;
}
