/* Copyright 2018 Carlos Filoteo
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
#ifdef LED_ENABLE
#include "protocol/serial.h"
#endif

#define _______ KC_TRNS
#define LT3_TAB LT(3, KC_TAB)
#define MT_RSFT_ENT MT(MOD_RSFT, KC_ENT)

enum custom_keycodes
{
  LED_TOG = SAFE_RANGE,
  LED_CHG
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base Layer
   * ,-------------------------------------------------------------------------.
   * | Esc |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |Bspace |
   * |-------------------------------------------------------------------------+
   * |Tab/Hyper |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |   '  |
   * |-------------------------------------------------------------------------+
   * | Shift |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |Sh/En|
   * |-------------------------------------------------------------------------+
   * | | Ctrl | Alt | Gui |  L2  |   Space   |  L1  | Left| Down|  Up |Right|
   * `-------------------------------------------------------------------------'
   */

    LAYOUT(
        KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        ALL_T(KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, SFT_T(KC_ENT),
        KC_LCTL, LT3_TAB, KC_LALT, KC_LGUI, MO(1), KC_SPC, MO(2), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),

    /* FN Layer 1
   * ,-------------------------------------------------------------------------.
   * | ` ~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  | Bksp  |
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     |  -  |  =  |  [  |  ]  |  \   |
   * |-------------------------------------------------------------------------+
   * |       | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 |     |

   * |-------------------------------------------------------------------------+
   * |     |     |     |Capsl|      |          |       | Home| PgDn| PgUp| End |
   * `-------------------------------------------------------------------------'
   */

    LAYOUT(/* Right */
           KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
           _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_GRV,
           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PIPE, SFT_T(KC_ENT),
           _______, _______, _______, _______, _______, KC_MPLY, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END),

    /* FN Layer 2
   * ,-------------------------------------------------------------------------.
   * | FN6 | FN7 | FN8 | FN9 | FN9 | FN10| FN11| FN12| FN13| FN14| FN15| Delete|
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     | FN17| FN18| FN19| FN20|  FN21|
   * |-------------------------------------------------------------------------+
   * |       | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |Capsl|      |          |       | Home| PgDn| PgUp| End |
   * `-------------------------------------------------------------------------'
   */

    LAYOUT(/* Left */
           KC_TILD, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
           _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_GRV,
           _______, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, _______, _______, KC_BSLS, SFT_T(KC_ENT),
           _______, _______, _______, _______, _______, KC_MPLY, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT),

    /* FN Layer 2
   * ,-------------------------------------------------------------------------.
   * | Esc | Calc|Webhm| Mail| Comp|     |     |     |     |     |PrtSc|       |
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     |     |     |     |     |      |
   * |-------------------------------------------------------------------------+
   * |       |LEDtg|LEDch|     |     |     |     |     |     |     |     |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |     |      |          |       |MousL|MousD|MousU|MousR|
   * `-------------------------------------------------------------------------'
   */

    LAYOUT(/* Tab */
           KC_ESC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R),
};

//LED keymap functions
#ifdef LED_ENABLE
void led_chmode(void)
{
  serial_send(101);
}

void led_toggle(void)
{
  serial_send(100);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  if (record->event.pressed)
  {
    switch (keycode)
    {
    case LED_TOG:
#ifdef LED_ENABLE
      led_toggle();
#endif
      return false;
    case LED_CHG:
#ifdef LED_ENABLE
      led_chmode();
#endif
      return false;
    }
  }
  return true;
};
#endif
