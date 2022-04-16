// Copyright 2022 Alex Olshansky (@clbn)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define USE_SERIAL
#define EE_HANDS
#define KINETIC_SPEED

// Home row mods
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD

// RGB underglow (underlight)
#define RGB_DI_PIN D1
#define RGBLED_NUM 24
#define RGBLED_SPLIT { 12, 12 }
#define RGBLIGHT_SLEEP              // Switch off lighting when the host goes to sleep
#define RGBLIGHT_LIMIT_VAL 150      // Maximum brightness level (0-255)

// Only enable select animation modes to decrease firmware size
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT
