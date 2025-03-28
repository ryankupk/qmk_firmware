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

/* ws2812 RGB LED */
#define WS2812_DI_PIN D3

#ifdef RGBLIGHT_ENABLE
	#define RGBLIGHT_LAYERS
	#define RGBLIGHT_MAX_LAYERS 1
	#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
    #define RGBLIGHT_SLEEP

    #define RGBLIGHT_SPLIT
    #define RGBLIGHT_LED_COUNT 72
    #define RGBLED_SPLIT { 36, 36 }

    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17

#endif

#undef RGB_MATRIX_ENABLE