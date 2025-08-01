 /* Copyright 2021 Dane Evans
  *
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
  // SOFLE RGB
#include <stdio.h>

#include QMK_KEYBOARD_H
#include "keymap_finnish.h"

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

enum sofle_layers {
    _BASE = 0,
    // _CLMK,
    _SYM,
    _NAV,
    _FUN
};

#define MO_SYM  MO(_SYM)
#define MO_NAV  MO(_NAV)
// #define TG_CLMK TG(_CLMK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     // TODO a d ghost tap

// _QWERTY from default
[_BASE] = LAYOUT(
  KC_MINS, KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_EQL,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BACKSLASH,
  MT(MOD_LGUI, KC_ESC) , KC_A, KC_S,  KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_LSFT, KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,   KC_MUTE,     LCTL(KC_0), KC_B,  KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  KC_LCTL, KC_LALT, MO_SYM,MT(MOD_LALT, KC_BSPC) , KC_LCTL,      KC_ENT, KC_SPC, MO_NAV, KC_LSFT, KC_RCTL
),

// XXXXXXX is disable key, _______ is keep base key
/*[_SYM] = LAYOUT(*/
/*  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,*/
/*  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12,*/
/*  _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,*/
/*  _______,  KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,*/
/*                       _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______*/
/*),*/
// _LOWER from default
[_SYM] = LAYOUT(
  KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  _______,  KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR,                       KC_CIRC, KC_AMPR, KC_SCLN, KC_MINS,   KC_PLUS, KC_F12,
  _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                       KC_ASTR, KC_LBRC, KC_RBRC, KC_LPRN,   KC_RPRN, KC_PIPE,
  _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  _______,     _______, KC_6,    KC_7,    KC_8,    KC_COLN,   KC_BSLS,   KC_F12,
                   _______, _______, _______, KC_BSPC, _______,       _______, _______, _______, _______, _______
),

// _RAISE from default
[_NAV] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______,                       _______,  _______  , _______,  _______ ,  _______ ,_______,
  _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX,                          KC_PGUP, C(KC_LEFT),   KC_UP, C(KC_RGHT), C(KC_BSPC), KC_BSPC,
  _______, KC_LALT,  KC_MPRV,  KC_MPLY, KC_MNXT, KC_INS,                        KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, KC_BSPC,
  _______, _______,  KC_PSCR,   KC_APP,  XXXXXXX, XXXXXXX, _______,       _______,  XXXXXXX, KC_HOME, XXXXXXX, KC_END,   XXXXXXX, _______,
                         _______, _______, _______, KC_DEL,_______ ,       _______, _______, _______, KC_X, _______
),

// _ADJUST from default
[_FUN] = LAYOUT(
  KC_LALT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_O,                   KC_B, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,
  XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KX_CAON,XXXXXXX, KX_CAOF, XXXXXXX,XXXXXXX,             C(G(KC_LEFT)),KC_NO,KC_NO,C(G(KC_RGHT)),XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,XXXXXXX,     RGB_TOG, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
)

// [_BASE] = LAYOUT(
//   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX,
//   XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,    FI_ODIA, XXXXXXX,
//   XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,       KC_MPLY, KC_N,    KC_M,    FI_COMM, FI_DOT,  FI_ADIA, XXXXXXX,
//                     XXXXXXX, XXXXXXX, KC_LCTL, MO_SYM,  KC_SPC,        KC_LSFT, MO_NAV,  KC_RCTL, XXXXXXX, XXXXXXX
// ),

// [_CLMK] = LAYOUT(
//   _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
//   _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                            KC_J,    KC_L,    KC_U,    KC_Y,    FI_ODIA, _______,
//   _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                            KC_M,    KC_N,    KC_E,    KC_I,    FI_O,    _______,
//   _______, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______,       _______, KC_K,    KC_H,    FI_COMM, FI_DOT,  FI_ADIA, _______,
//                     _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
// ),

// [_SYM] = LAYOUT(
//   _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
//   _______, KC_ESC,  FI_PERC, FI_DLR,  FI_EURO, XXXXXXX,                         FI_CIRC, FI_TILD, FI_QUOT, FI_DQUO, FI_GRV,  _______,
//   _______, FI_LABK, FI_LCBR, FI_LBRC, FI_LPRN, FI_BSLS,                         FI_SLSH, FI_RPRN, FI_RBRC, FI_RCBR, FI_RABK, _______,
//   _______, FI_EXLM, FI_AT,   FI_HASH, FI_AMPR, FI_PIPE, _______,       _______, FI_ASTR, FI_MINS, FI_EQL,  FI_PLUS, FI_QUES, _______,
//                     _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
// ),

// [_NAV] = LAYOUT(
//   _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
//   _______, KC_ESC,  FI_7,    FI_8,    FI_9,    OSM(MOD_LGUI),                   OSM(MOD_LGUI), KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______,
//   _______, KC_TAB,  FI_4,    FI_5,    FI_6,    OSM(MOD_LALT),                   OSM(MOD_LALT), KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
//   _______, FI_0,    FI_1,    FI_2,    FI_3,    OSM(MOD_LCTL), _______, _______, OSM(MOD_LCTL), KC_BSPC, KC_ENT,  KC_DEL,  OSM(MOD_RGUI), _______,
//                     _______, _______, _______, _______, KC_LSFT,       _______, _______, _______, _______, _______
// ),

// [_FUN] = LAYOUT(
//   _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
//   _______, KC_F10,  KC_F7,   KC_F8,   KC_F9,   OSM(MOD_LGUI),                   OSM(MOD_LGUI), KC_INS,  KC_PSCR, XXXXXXX, XXXXXXX, _______,
//   _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   OSM(MOD_LALT),                   OSM(MOD_LALT), KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, _______,
//   _______, KC_F12,  KC_F1,   KC_F2,   KC_F3,   OSM(MOD_LCTL), TG_CLMK, RGB_TOG, OSM(MOD_LCTL), KC_VOLD, KC_MUTE, KC_VOLU, OSM(MOD_RGUI), _______,
//                     _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
// )
};

layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _SYM, _NAV, _FUN);
}


#ifdef KEY_CANCELLATION_ENABLE
const key_cancellation_t PROGMEM key_cancellation_list[] = {
    // on key down
    //       |    key to be released
    //       |     |
    [0] = {KC_D, KC_A},
    [1] = {KC_A, KC_D}
};
#endif

#ifdef OLED_ENABLE

// Custom logo based on the PCB gecko
static const char PROGMEM sofle_logo[] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,240,  8,  6,  2,  1,  0,  0,  0,  0,  0,  0,128,  0,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,224,248, 28,  6,  2,  3,  1,  1,  1,225,255, 62,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,224,120, 28,206,103, 59, 15,  0,  0,192,240,120, 28,207,127, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7, 63,120,240,192,128,128,  0, 64, 96,112,248,255,222,207, 78, 10,  0,  0,  0,128,192,192, 96,124,112,120, 32,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,129,  7, 15, 28, 60, 56,112,112,224,193,131,  1,  0,  0,  0,  0,128,128,  0,224,240, 16, 24,240, 96,  0,  0,128,224,248,191, 15, 13,  6,  3,  1,  0,128,224,252,223,103, 49, 12,  7,  1,192,224,112, 48, 24,152,248,112,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0, 80,112,112,240,120,252, 12, 28, 56,113,227,119,127, 62, 30, 31, 63, 63, 61,124,124,124,124,124,252,253,255,127,124,124,124,124,124, 56, 56, 16,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 62,255,255,193,128,  0,  0,  0,  0,  0,128,128,193,127, 63,  0,  0, 56,254,255,193, 64, 99, 55, 28, 30, 19, 16,232,252,127,  7,  3,255,  6, 12, 12,  4,  4,  4,127,255,193,192, 64, 32, 16,126,255,199,132,134,130,195, 65, 32, 48,  8,  4,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 64, 63,255, 57,112, 16,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  3,  3,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,126,255,207, 96, 56, 15,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
};

static const char PROGMEM qmk_logo[] = { 128,128,128,128,192,224,240,255,255,240,240,255,255,240,240,255,255,240,240,255,255,240,240,255,255,240,224,192,128,128,128,128,153,153,153,153,255,255,255,255,255,  1,  1,255,255,255,255,  1,  1,255,255,255,255,  1,  1,255,255,255,255,255,153,153,153,153,153,153,153,153,255,255,255,255,255,252,240,243,227,231,231,  0,  0,231,231,227,243,240,252,255,255,255,255,255,153,153,153,153,  1,  1,  1,  1,  3,  7, 15,255,255, 15, 15,255,255, 15, 15,255,255, 15, 15,255,255, 15, 15,255,255, 15,  7,  3,  1,  1,  1,  1,
};

static const char PROGMEM g_layer_qwrt[] = {
    0,248,  4,  2,  2,226, 18, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 18,226,  2,  2,  4,248,  0,  0,255,  0,  0,  0,255,  0,  0,  0,  0,  0,  0,252,254,  7,  3,  3,  7,254,252,  0,  0,  0,  0,  0,  0,255,  0,  0,  0,255,  0,  0,255,  0,  0,  0,127,128,  0,  0,  0,  0,  0,  3,  7, 14, 12, 12, 30, 63, 19,  0,  0,  0,  0,  0,128,127,  0,  0,  0,255,  0,  0, 31, 32, 64, 64, 64, 64, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 64, 64, 64, 64, 32, 31,  0,
};

static const char PROGMEM g_layer_clmk[] = {
    0,248,  4,  2,  2,226, 18, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 18,226,  2,  2,  4,248,  0,  0,255,  0,  0,  0,255,  0,  0,  0,  0,  0,  0,252,254,  7,  3,  3,  7, 14, 12,  0,  0,  0,  0,  0,  0,255,  0,  0,  0,255,  0,  0,255,  0,  0,  0,127,128,  0,  0,  0,  0,  0,  3,  7, 14, 12, 12, 14,  7,  3,  0,  0,  0,  0,  0,128,127,  0,  0,  0,255,  0,  0, 31, 32, 64, 64, 64, 64, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 64, 64, 64, 64, 32, 31,  0,
};

static const char PROGMEM g_layer_sym[] = {
    0,248,  4,  2,  2,226, 18, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 18,226,  2,  2,  4,248,  0,  0,255,  0,  0,  0,255,  0,  0,  0,  0,  0,  0,  0, 14, 14,195,227,126, 62,  0,  0,  0,  0,  0,  0,  0,255,  0,  0,  0,255,  0,  0,255,  0,  0,  0,127,128,  0,  0,  0,  0,  0,  0,  0,  0, 13, 13,  0,  0,  0,  0,  0,  0,  0,  0,128,127,  0,  0,  0,255,  0,  0, 31, 32, 64, 64, 64, 64, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 64, 64, 64, 64, 32, 31,  0,
};

static const char PROGMEM g_layer_nav[] = {
    0,248,  4,  2,  2,226, 18, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 18,226,  2,  2,  4,248,  0,  0,255,  0,  0,  0,255,  0,  0,  0,  0, 64,224,240,248,252,224,224,224,224,224,224,224,  0,  0,  0,  0,255,  0,  0,  0,255,  0,  0,255,  0,  0,  0,127,128,  0,  0,  0,  0,  0,  1,  3,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,127,  0,  0,  0,255,  0,  0, 31, 32, 64, 64, 64, 64, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 64, 64, 64, 64, 32, 31,  0,
};

static const char PROGMEM g_layer_fun[] = {
    0,248,  4,  2,  2,226, 18, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 18,226,  2,  2,  4,248,  0,  0,255,  0,  0,  0,255,  0,  0,  0,  0,  0,254,254, 38, 38, 38,  0,  0, 12,254,254,  0,  0,  0,  0,  0,255,  0,  0,  0,255,  0,  0,255,  0,  0,  0,127,128,  0,  0,  0,  0,  3,  3,  0,  0,  0,  0,  0,  0,  3,  3,  0,  0,  0,  0,128,127,  0,  0,  0,255,  0,  0, 31, 32, 64, 64, 64, 64, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 64, 64, 64, 64, 32, 31,  0,
};

static void render_sofle_logo(void) {
    oled_write_raw_P(sofle_logo, sizeof(sofle_logo));
}

static void render_qmk_logo(void) {
    oled_write_raw_P(qmk_logo, sizeof(qmk_logo));
}

static void render_status(void) {
    oled_write_ln_P(PSTR("\r"), false);
    render_qmk_logo();
    oled_write_ln_P(PSTR("\r\r\r\r\r\r\r"), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_raw_P(g_layer_qwrt, sizeof(g_layer_qwrt));
            break;
        // case _CLMK:
        //     oled_write_raw_P(g_layer_clmk, sizeof(g_layer_clmk));
        //     break;
        case _NAV:
            oled_write_raw_P(g_layer_nav, sizeof(g_layer_nav));
            break;
        case _SYM:
            oled_write_raw_P(g_layer_sym, sizeof(g_layer_sym));
            break;
        case _FUN:
            oled_write_raw_P(g_layer_fun, sizeof(g_layer_fun));
            break;
        default:
            oled_write_ln_P(PSTR("???\n"), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();
    } else {
        render_sofle_logo();
    }
    return false;
}

#endif

#ifdef ENCODER_ENABLE

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD,  KC_VOLU),       ENCODER_CCW_CW(LCTL(S(KC_MINS)),  LCTL(S(KC_PLUS))) },
    // [_CLMK] = { ENCODER_CCW_CW(_______,  _______),       ENCODER_CCW_CW(_______,  _______) },
    [_NAV]  = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),       ENCODER_CCW_CW(RGB_SPD,  RGB_SPI) },
    [_SYM]  = { ENCODER_CCW_CW(KC_U, LCTL(KC_R)),        ENCODER_CCW_CW(LCTL(S(KC_DOWN)),LCTL(S(KC_UP))) },
    [_FUN]  = { ENCODER_CCW_CW(RGB_HUD,  RGB_HUI),       ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
};
#endif

#endif
