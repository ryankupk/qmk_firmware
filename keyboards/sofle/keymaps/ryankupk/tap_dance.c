#pragma once

#include "quantum.h"

enum {
    TD_QUOTE_BACKTICK,
    TD_HOME,
    TD_END,
    TD_ESC,
};

void td_quote_backtick_finished(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap_code16(KC_QUOTE);
            break;
        case 2:
            tap_code16(KC_GRAVE);
            break;
        case 3:
            tap_code16(KC_GRAVE);
            tap_code16(KC_GRAVE);
            tap_code16(KC_GRAVE);
            break;
    }
}

void td_quote_backtick_reset(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_QUOTE_BACKTICK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_quote_backtick_finished, td_quote_backtick_reset),
    [TD_HOME] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT, KC_HOME),
    [TD_END] = ACTION_TAP_DANCE_DOUBLE(KC_RIGHT, KC_END),
    [TD_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_GRV),
};
