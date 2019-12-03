#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// No layers:
[0] = LAYOUT_ortho_3x10(
	KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,
	KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,     KC_L,    KC_RSFT,
	KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,  KC_BSPC,  KC_SPC,    KC_ENT
),

// Layers:
// [0] = LAYOUT_ortho_3x10(
// 	KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,
// 	KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,
// 	LT(3, KC_Z),    KC_X,    KC_C,    KC_V,    LT(1, KC_B),    LT(2, KC_N),    KC_M,  KC_BSPC,  KC_SPC,  LSFT_T(KC_ENT)
// ),

[1] = LAYOUT_ortho_3x10(
	KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
	KC_TAB,  _______, _______, _______, KC_DQT,  KC_QUOT, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,
	KC_LSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX, KC_HYPR, KC_QUOT, KC_COMM,  KC_DOT, KC_SLSH
),

[2] = LAYOUT_ortho_3x10(
	KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
	_______, _______, _______, _______, KC_LT, KC_GT, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,
	_______, _______, _______, _______, KC_HYPR, XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_RSFT
),

[3] = LAYOUT_ortho_3x10(
	KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, RESET,
	KC_LSFT, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,  KC_GRV,
	_______, KC_RCTL, KC_RALT, KC_RGUI, _______, _______, KC_TILD, KC_PIPE, _______, KC_BSLS
)
};
