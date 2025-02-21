#pragma once

//#define USE_MATRIX_I2C

///https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/

#define MASTER_RIGHT

#define CUSTOM_FONT

#define CUSTOM_LAYER_READ //if you remove this it causes issues - needs better guarding

#define SPLIT_WPM_ENABLE
#define SPLIT_OLED_ENABLE

#define DEBOUNCE 3

#define ENCODER_RESOLUTIONS { 4 }
#define ENCODER_RESOLUTIONS_RIGHT { 3 }

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// #define QUICK_TAP_TERM 0

#ifdef TAPPING_TERM // ms cooldown for tapdance
    #undef TAPPING_TERM
    #define TAPPING_TERM 280
    #define TAPPING_TERM_PER_KEY
#endif

/* ws2812 RGB LED */
#define WS2812_DI_PIN D3

#ifdef RGBLIGHT_ENABLE
	// #define RGBLED_NUM 72
    #define RGBLIGHT_LED_COUNT 72
    #define RGBLED_SPLIT { 36, 36 }
    #define RGBLIGHT_SPLIT
    #define RGBLIGHT_LAYERS
    #define RGBLIGHT_SLEEP

    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17

    // Enable only the effects to use
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    //#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    //#define RGBLIGHT_EFFECT_SNAKE
    //#define RGBLIGHT_EFFECT_KNIGHT
    //#define RGBLIGHT_EFFECT_CHRISTMAS
    //#define RGBLIGHT_EFFECT_STATIC_GRADIENT
    //#define RGBLIGHT_EFFECT_RGB_TEST
    //#define RGBLIGHT_EFFECT_ALTERNATING
    //#define RGBLIGHT_EFFECT_TWINKLE
#endif

#undef RGB_MATRIX_ENABLE