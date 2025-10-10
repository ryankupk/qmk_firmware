// SOFLE RGB
// compile command: qmk compile -kb sofle/rev1 -km ryankupk -e CONVERT_TO=promicro_rp2040 -j 4
// flash command: qmk flash -kb sofle/rev1 -km ryankupk -e CONVERT_TO=rp2040_ce -j 4
// generate autocorrect: qmk generate-autocorrect-data ryankupk/autocorrect_dictionary.txt -kb sofle -km ryankupk; from directory: qmk_firmware/keyboards/sofle/keymaps

#include QMK_KEYBOARD_H
#include "common.h"

#ifdef OLED_ENABLE
    #include "oled.c"
#endif

#ifdef ENCODER_MAP_ENABLE
    #include "encoder.c"
#endif

#ifdef RGBLIGHT_ENABLE
    #include "rgb.c"
#endif

#ifdef CAPS_WORD_ENABLE
    #include "caps_word.c"
#endif

#define SHARED_LAYER LAYOUT( \
  KC_GRV,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_DEL,  KC_BSPC, \
  _______, KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     _______, _______,  KC_8,    KC_9,    KC_0,   _______, \
  _______, KC_NO,  KC_NO,   KC_NO,  KC_NO,   KC_NO,                     KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, KC_NO,   KC_GRV , \
  _______, KC_NO,  KC_NO,   KC_NO,  KC_NO,   KC_NO,_______,     _______,_______, _______, KC_NO,   KC_NO,   KC_NO,   _______, \
              _______, KC_RAISE, _______, _______, _______,    S(KC_ENT), _______, _______,  KC_HOME, KC_END \
)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_BSLS,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOTE,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_ENT,   MS_BTN1,KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_EQUAL,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
         KC_LALT, KC_LGUI, KC_RAISE, KC_RSFT, KC_BSPC,                      KC_ENT, KC_SPC , KC_LOWER, KC_LBRC, KC_RBRC
  //    \--------+--------+--------+---------+-------|                   |--------+---------+--------+---------+-------/
),
[_GAMING] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,   KC_F23,    KC_F24, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 KC_TRNS, KC_RAISE, KC_SPC, KC_LGUI,   KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

[_LOWER] = SHARED_LAYER,
[_RAISE] = SHARED_LAYER,

[_ADJUST] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX,LALT(KC_F4),XXXXXXX,                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  XXXXXXX, KC_QWERTY,AC_ON, XXXXXXX,XXXXXXX,  XXXXXXX,                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  UG_TOGG, UG_HUEU,UG_SATU, UG_VALU,  XXXXXXX,KC_GAMING,                  XXXXXXX ,XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  UG_NEXT, UG_HUED,UG_SATD,UG_VALD,   XXXXXXX,XXXXXXX,KC_F23,     KC_F24, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                tap_code16(AC_ON);
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_GAMING:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAMING);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
    }
    return true;
}
