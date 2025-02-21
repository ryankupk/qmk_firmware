#pragma once

// Separate brightness for left and right indicators
#define LEFT_INDICATOR_BRIGHTNESS 15
#define RIGHT_INDICATOR_BRIGHTNESS 15

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

// Light combinations
#define SET_INDICATORS(hsv) \
    {0, 1, HSV_OVERRIDE_HELP(hsv, LEFT_INDICATOR_BRIGHTNESS)}, \
    {35+0, 1, HSV_OVERRIDE_HELP(hsv, RIGHT_INDICATOR_BRIGHTNESS)}
#define SET_UNDERGLOW(hsv) \
    {1, 6, hsv}, \
    {35+1, 6, hsv}
#define SET_NUMROW(hsv) \
    {10, 2, hsv}, \
    {20, 2, hsv}, \
    {30, 2, hsv}, \
    {35+10, 2, hsv}, \
    {35+20, 2, hsv}, \
    {35+30, 2, hsv}
#define SET_INNER_COL(hsv) \
    {33, 4, hsv}, \
    {35+33, 4, hsv}
#define SET_OUTER_COL(hsv) \
    {7, 4, hsv}, \
    {35+7, 4, hsv}
#define SET_THUMB_CLUSTER(hsv) \
    {25, 2, hsv}, \
    {35+25, 2, hsv}

// QWERTY layer uses cool colors
#define HSV_QWERTY_BASE     170, 255, 255    // Blue base
#define HSV_QWERTY_ACCENT   190, 255, 255    // Cyan accent

// Gaming layer uses warm colors
#define HSV_GAMING_BASE     0, 255, 255      // Red base
#define HSV_GAMING_ACCENT   28, 255, 255     // Orange-red accent

// Utility layers use purple theme
#define HSV_UTILITY_BASE    213, 255, 255    // Purple base
#define HSV_UTILITY_RAISE   223, 255, 255    // Light purple for Raise
#define HSV_UTILITY_LOWER   203, 255, 255    // Dark purple for Lower
#define HSV_UTILITY_ADJUST  193, 255, 255    // Magenta-purple for Adjust

// QWERTY layer with animation-friendly configuration
const rgblight_segment_t PROGMEM layer_qwerty_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_INDICATORS(HSV_QWERTY_BASE),
    SET_UNDERGLOW(HSV_QWERTY_ACCENT),
    SET_NUMROW(HSV_QWERTY_ACCENT),
    SET_INNER_COL(HSV_QWERTY_ACCENT),
    SET_OUTER_COL(HSV_QWERTY_ACCENT),
    SET_THUMB_CLUSTER(HSV_QWERTY_ACCENT)
);

// Gaming layer with distinct warm colors
const rgblight_segment_t PROGMEM layer_gaming_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_INDICATORS(HSV_GAMING_BASE),
    SET_UNDERGLOW(HSV_GAMING_ACCENT),
    SET_NUMROW(HSV_GAMING_BASE),
    SET_INNER_COL(HSV_GAMING_BASE),
    SET_OUTER_COL(HSV_GAMING_BASE),
    SET_THUMB_CLUSTER(HSV_GAMING_ACCENT)
);

// Lower layer - darker purple
const rgblight_segment_t PROGMEM layer_lower_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_INDICATORS(HSV_UTILITY_BASE),
    SET_UNDERGLOW(HSV_UTILITY_LOWER),
    SET_NUMROW(HSV_UTILITY_LOWER),
    SET_INNER_COL(HSV_UTILITY_LOWER),
    SET_OUTER_COL(HSV_UTILITY_LOWER),
    SET_THUMB_CLUSTER(HSV_UTILITY_LOWER)
);

// Raise layer - lighter purple
const rgblight_segment_t PROGMEM layer_raise_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_INDICATORS(HSV_UTILITY_BASE),
    SET_UNDERGLOW(HSV_UTILITY_RAISE),
    SET_NUMROW(HSV_UTILITY_RAISE),
    SET_INNER_COL(HSV_UTILITY_RAISE),
    SET_OUTER_COL(HSV_UTILITY_RAISE),
    SET_THUMB_CLUSTER(HSV_UTILITY_RAISE)
);

// Adjust layer - magenta-purple
const rgblight_segment_t PROGMEM layer_adjust_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_INDICATORS(HSV_UTILITY_BASE),
    SET_UNDERGLOW(HSV_UTILITY_ADJUST),
    SET_NUMROW(HSV_UTILITY_ADJUST),
    SET_INNER_COL(HSV_UTILITY_ADJUST),
    SET_OUTER_COL(HSV_UTILITY_ADJUST),
    SET_THUMB_CLUSTER(HSV_UTILITY_ADJUST)
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_qwerty_lights,
    layer_gaming_lights,
    layer_lower_lights,
    layer_raise_lights,
    layer_adjust_lights
);

layer_state_t layer_state_set_user(layer_state_t state) {
    // Clear all layers first
    rgblight_set_layer_state(0, false);
    rgblight_set_layer_state(1, false);
    rgblight_set_layer_state(2, false);
    rgblight_set_layer_state(3, false);
    rgblight_set_layer_state(4, false);

    // Then set the active layer
    if (layer_state_cmp(state, _GAMING)) {
        rgblight_set_layer_state(1, true);
    } else if (layer_state_cmp(state, _LOWER)) {
        rgblight_set_layer_state(2, true);
    } else if (layer_state_cmp(state, _RAISE)) {
        rgblight_set_layer_state(3, true);
    } else if (layer_state_cmp(state, _ADJUST)) {
        rgblight_set_layer_state(4, true);
    } else {
        rgblight_set_layer_state(0, true); // Default to QWERTY
    }
    
    return state;
}

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
    
    // Set default RGB mode to breathing effect for QWERTY layer
    rgblight_mode(RGBLIGHT_MODE_BREATHING + 2); // +2 gives a medium breathing speed
}