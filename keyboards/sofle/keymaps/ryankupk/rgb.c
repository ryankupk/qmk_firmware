#pragma once

// Define colors for each layer (HSV values)
#define HSV_QWERTY          169, 255, 160 // BLUE
#define HSV_GAMING          106, 255, 160 // SPRING GREEN
#define HSV_GAMING_WASD     222, 255, 160 // ROSE
#define HSV_LOWER           222, 255, 160 // ROSE
#define HSV_RAISE           222, 255, 160 // ROSE
#define HSV_ADJUST          127, 255, 160 // CYAN

// Directly set all LEDs to a specific color
void set_layer_color(uint8_t h, uint8_t s, uint8_t v) {
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT); // Set to static mode
    rgblight_sethsv_noeeprom(h, s, v);                  // Set all LEDs to this color
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Get the highest active layer
    uint8_t highest_layer = get_highest_layer(state);
    
    // Check default layer state for persistent layers
    uint8_t default_layer = get_highest_layer(default_layer_state);
    
    // Handle all layers by directly setting colors
    if (highest_layer == _ADJUST) {
        set_layer_color(HSV_ADJUST);
    } else if (highest_layer == _LOWER) {
        set_layer_color(HSV_LOWER);
    } else if (highest_layer == _RAISE) {
        set_layer_color(HSV_RAISE);
    } else if (default_layer == _GAMING) {
        set_layer_color(HSV_GAMING);
    } else {
        // Default to QWERTY
        set_layer_color(HSV_QWERTY);
    }
    
    return state;
}

void keyboard_post_init_user(void) {
    // Disable all animations and set to initial color
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv(HSV_QWERTY);  // Set initial color to QWERTY blue
    
    // This is important - disable any layer indicators to prevent conflicts
    rgblight_layers = NULL;
}