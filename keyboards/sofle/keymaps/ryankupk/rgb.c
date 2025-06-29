#pragma once

#define HSV_QWERTY          169, 255, 80 // BLUE
#define HSV_GAMING          0,   255, 80 // RED
#define HSV_GAMING_WASD     106, 255, 80 // SPRING GREEN
#define HSV_LOWER           222, 255, 80 // ROSE
#define HSV_RAISE           222, 255, 80 // ROSE
#define HSV_ADJUST          127, 255, 80 // CYAN

#define LED_W       20
#define LED_A       14
#define LED_S       19
#define LED_D       24
#define LED_1       22
#define LED_2       21
#define LED_3       12
#define LED_RAISE   17

#define LED_LOWER_RIGHT 53

// QWERTY layer lighting - excludes LEDs 0 and 36
const rgblight_segment_t PROGMEM qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, HSV_OFF},        // Turn off all LEDs first
    {1, 35, HSV_QWERTY},                     // Left half (skip LED 0)
    {37, 35, HSV_QWERTY}                     // Right half (skip LED 36)
);

// LOWER layer lighting - excludes LEDs 0 and 36  
const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, HSV_OFF},        // Turn off all LEDs first
    {1, 35, HSV_LOWER},                      // Left half (skip LED 0)
    {37, 35, HSV_LOWER}                      // Right half (skip LED 36)
);

// RAISE layer lighting - excludes LEDs 0 and 36
const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, HSV_OFF},        // Turn off all LEDs first
    {1, 35, HSV_RAISE},                      // Left half (skip LED 0)
    {37, 35, HSV_RAISE}                      // Right half (skip LED 36)
);

// ADJUST layer lighting - excludes LEDs 0 and 36
const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, HSV_OFF},        // Turn off all LEDs first
    {1, 35, HSV_ADJUST},                     // Left half (skip LED 0)
    {37, 35, HSV_ADJUST}                     // Right half (skip LED 36)
);

// GAMING layer lighting - excludes LEDs 0 and 36
const rgblight_segment_t PROGMEM gaming_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, HSV_OFF},        // Turn off all LEDs first
    {1, 35, HSV_GAMING},                     // Left half base color (skip LED 0)
    
    // WASD and other highlighted keys
    {LED_W,     1, HSV_GAMING_WASD},
    {LED_A,     1, HSV_GAMING_WASD},
    {LED_S,     1, HSV_GAMING_WASD},
    {LED_D,     1, HSV_GAMING_WASD},
    {LED_RAISE, 1, HSV_GAMING_WASD},
    {LED_1,     1, HSV_GAMING_WASD},
    {LED_2,     1, HSV_GAMING_WASD},
    {LED_3,     1, HSV_GAMING_WASD},
    
    // Right half - only specific LEDs, skip LED 36
    {LED_LOWER_RIGHT, 1, HSV_GAMING_WASD}
);

// Array of all lighting layers
const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    qwerty_layer,   // Layer 0
    lower_layer,    // Layer 1  
    raise_layer,    // Layer 2
    adjust_layer,   // Layer 3
    gaming_layer    // Layer 4
);

layer_state_t layer_state_set_user(layer_state_t state) {
    // Turn off all lighting layers first
    for (int i = 0; i < 5; i++) {
        rgblight_set_layer_state(i, false);
    }
    
    // Get the highest active layer
    uint8_t highest_layer = get_highest_layer(state);
    
    // Check default layer state for persistent layers
    uint8_t default_layer = get_highest_layer(default_layer_state);
    
    if (default_layer == _GAMING) {
        rgblight_set_layer_state(4, true); // Enable gaming lighting layer
    } else {
        // Handle all other layers using lighting layers
        if (highest_layer == _ADJUST) {
            rgblight_set_layer_state(3, true); // Enable adjust lighting layer
        } else if (highest_layer == _LOWER) {
            rgblight_set_layer_state(1, true); // Enable lower lighting layer
        } else if (highest_layer == _RAISE) {
            rgblight_set_layer_state(2, true); // Enable raise lighting layer
        } else {
            rgblight_set_layer_state(0, true); // Enable QWERTY lighting layer
        }
    }
    
    return state;
}

void keyboard_post_init_user(void) {
    // Initialize the RGB layers
    rgblight_layers = rgb_layers;
    
    // Set initial state
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_set_layer_state(0, true); // Start with QWERTY layer
}