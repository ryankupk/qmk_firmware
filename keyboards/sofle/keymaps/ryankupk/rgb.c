#pragma once

// Define colors for each layer (HSV values)
#define HSV_QWERTY          169, 255, 160 // BLUE
#define HSV_GAMING          106, 255, 160 // SPRING GREEN
#define HSV_GAMING_WASD     222, 255, 160 // ROSE 
#define HSV_LOWER           222, 255, 160 // ROSE
#define HSV_RAISE           222, 255, 160 // ROSE
#define HSV_ADJUST          127, 255, 160 // CYAN

// Define LED indices for Sofle keyboard
// W, A, S, D, Raise, 1, 2, 3, and the Lower key on the right half
#define LED_W       8
#define LED_A       15
#define LED_S       16
#define LED_D       17
#define LED_RAISE   28
#define LED_1       7 
#define LED_2       6
#define LED_3       5
#define LED_LOWER_RIGHT 33

// Define lighting layer for gaming mode
const rgblight_segment_t PROGMEM gaming_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    // Left half base color
    {0, 30, HSV_GAMING},    // Set all LEDs to gaming color first
    
    // WASD and other specific keys to different color
    {LED_W, 1, HSV_GAMING_WASD},
    {LED_A, 1, HSV_GAMING_WASD},
    {LED_S, 1, HSV_GAMING_WASD},
    {LED_D, 1, HSV_GAMING_WASD},
    {LED_RAISE, 1, HSV_GAMING_WASD},
    {LED_1, 1, HSV_GAMING_WASD},
    {LED_2, 1, HSV_GAMING_WASD},
    {LED_3, 1, HSV_GAMING_WASD},
    {LED_LOWER_RIGHT, 1, HSV_GAMING_WASD}
);

// Combine all lighting layers into an array
const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    gaming_layer
);

// Directly set all LEDs to a specific color (for non-gaming layers)
void set_layer_color(uint8_t h, uint8_t s, uint8_t v) {
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT); // Set to static mode
    rgblight_sethsv_noeeprom(h, s, v);                  // Set all LEDs to this color
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Get the highest active layer
    uint8_t highest_layer = get_highest_layer(state);
    
    // Check default layer state for persistent layers
    uint8_t default_layer = get_highest_layer(default_layer_state);
    
    if (default_layer == _GAMING) {
        // Using lighting layers for Gaming mode
        rgblight_set_layer_state(0, true); // Enable gaming lighting layer
    } else {
        // Disable gaming lighting layer
        rgblight_set_layer_state(0, false);
        
        // Handle all other layers by directly setting colors
        if (highest_layer == _ADJUST) {
            set_layer_color(HSV_ADJUST);
        } else if (highest_layer == _LOWER) {
            set_layer_color(HSV_LOWER);
        } else if (highest_layer == _RAISE) {
            set_layer_color(HSV_RAISE);
        } else {
            // Default to QWERTY
            set_layer_color(HSV_QWERTY);
        }
    }
    
    return state;
}

void keyboard_post_init_user(void) {
    // Initialize the RGB layers
    rgblight_layers = rgb_layers;
    
    // Disable all animations and set to initial color
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv(HSV_QWERTY);  // Set initial color to QWERTY blue
}