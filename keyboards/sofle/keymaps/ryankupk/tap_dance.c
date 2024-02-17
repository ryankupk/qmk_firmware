#pragma once

enum {
    TD_QUOTE_BACKTICK,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_QUOTE_BACKTICK] = ACTION_TAP_DANCE_DOUBLE(KC_QUOTE, KC_GRV),
};

