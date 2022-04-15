// Copyright 2022 Alex Olshansky (@clbn)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define _ENGRAM 0
#define _QWERTY 1
#define _NAVIGATION 2
#define _NUMBERS 3

#define _LCTL_C LCTL_T(KC_C)
#define _LOPT_I LOPT_T(KC_I)
#define _LCMD_E LCMD_T(KC_E)
#define _LSFT_A LSFT_T(KC_A)
#define _RSFT_H RSFT_T(KC_H)
#define _RCMD_T RCMD_T(KC_T)
#define _ROPT_S ROPT_T(KC_S)
#define _RCTL_N RCTL_T(KC_N)

#define _LCTL_A LCTL_T(KC_A)
#define _LOPT_S LOPT_T(KC_S)
#define _LCMD_D LCMD_T(KC_D)
#define _LSFT_F LSFT_T(KC_F)
#define _RSFT_J RSFT_T(KC_J)
#define _RCMD_K RCMD_T(KC_K)
#define _ROPT_L ROPT_T(KC_L)
#define _RCTL_C RCTL_T(KC_SEMICOLON)

#define _L_ENGR TO(_ENGRAM)
#define _L_QWER TO(_QWERTY)
#define _NAV_SP LT(_NAVIGATION, KC_SPACE)
#define _NUM_BS LT(_NUMBERS, KC_BACKSPACE)

#define _REDO   SCMD(KC_Z)
#define _PASTE  LCMD(KC_V)
#define _COPY   LCMD(KC_C)
#define _CUT    LCMD(KC_X)
#define _UNDO   LCMD(KC_Z)

#define _HOME   LCMD(KC_LEFT)
#define _W_LEFT LOPT(KC_LEFT)
#define _W_RGHT LOPT(KC_RIGHT)
#define _END    LCMD(KC_RIGHT)

enum custom_keycodes {
  U_QUEX = SAFE_RANGE // The custom key for ? and !
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_ENGRAM] = LAYOUT_5x6_5(
  /*
   *  ┌───────╥───────╥───────╥───────╥───────╥───────┐                              ┌───────╥───────╥───────╥───────╥───────╥───────┐
   *  │       ║       ║       ║       ║       ║       │                              │       ║       ║       ║       ║       ║       │
   *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
   *  │       ║   B   ║   Y   ║   O   ║   U   ║  ' (  │                              │  " )  ║   L   ║   D   ║   W   ║   V   ║   Z   │
   *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
   *  │  ` ~  ║ C ctl ║ I opt ║ E cmd ║ A sft ║  , ;  │                              │  . :  ║ H sft ║ T cmd ║ S opt ║ N ctl ║   Q   │
   *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
   *  │       ║   G   ║   X   ║   J   ║   K   ║  - _  │                              │  ? !  ║   R   ║   M   ║   F   ║   P   ║  / ?  │
   *  └───────╨───────╬═══════╬═══════╬───────╨───────┘                              └───────╨───────╬═══════╬═══════╬───────╨───────┘
   *                  │       ║       │    ┌───────╥───────╥───────┐    ┌───────╥───────╥───────┐    │       ║       │
   *                  └───────╨───────┘    │  Esc  ║Spce L2║  Tab  │    │ Enter ║Bksp L3║  Del  │    └───────╨───────┘
   *                                       └───────╬═══════╬═══════╡    ╞═══════╬═══════╬───────┘
   *                                               │Engram ║ Latin │    │  Cyr  ║ Qwerty│
   *                                               └───────╨───────┘    └───────╨───────┘
   */
       XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                               XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
       XXXXXXX,KC_B,   KC_Y,   KC_O,   KC_U,   KC_9,                                  KC_0,   KC_L,   KC_D,   KC_W,   KC_V,   KC_Z,
       KC_GRV, _LCTL_C,_LOPT_I,_LCMD_E,_LSFT_A,KC_COMM,                               KC_DOT, _RSFT_H,_RCMD_T,_LOPT_S,_RCTL_N,KC_Q,
       XXXXXXX,KC_G,   KC_X,   KC_J,   KC_K,   KC_MINS,                               U_QUEX, KC_R,   KC_M,   KC_F,   KC_P,   KC_SLASH,
                       XXXXXXX,XXXXXXX,     KC_ESC, _NAV_SP,KC_TAB,      KC_ENT, _NUM_BS,KC_DEL,      XXXXXXX,XXXXXXX,
                                                    _L_ENGR,XXXXXXX,     XXXXXXX,_L_QWER
  ),

  [_QWERTY] = LAYOUT_5x6_5(
  /*
   *  ┌───────╥───────╥───────╥───────╥───────╥───────┐                              ┌───────╥───────╥───────╥───────╥───────╥───────┐
   *  │       ║       ║       ║       ║       ║       │                              │       ║       ║       ║       ║       ║       │
   *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
   *  │       ║   Q   ║   W   ║   E   ║   R   ║   T   │                              │   Y   ║   U   ║   I   ║   O   ║   P   ║  [ {  │
   *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
   *  │  ` ~  ║ A ctl ║ S opt ║ D cmd ║ F sft ║   G   │                              │   H   ║ J sft ║ K cmd ║ L opt ║ ;: ctl║  ' "  │
   *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
   *  │       ║   Z   ║   X   ║   C   ║   V   ║   B   │                              │   N   ║   M   ║  , <  ║  . >  ║  / ?  ║  } ]  │
   *  └───────╨───────╬═══════╬═══════╬───────╨───────┘                              └───────╨───────╬═══════╬═══════╬───────╨───────┘
   *                  │       ║       │    ┌───────╥───────╥───────┐    ┌───────╥───────╥───────┐    │       ║       │
   *                  └───────╨───────┘    │  Esc  ║Spce L2║  Tab  │    │ Enter ║Bksp L3║  Del  │    └───────╨───────┘
   *                                       └───────╬═══════╬═══════╡    ╞═══════╬═══════╬───────┘
   *                                               │Engram ║ Latin │    │  Cyr  ║ Qwerty│
   *                                               └───────╨───────┘    └───────╨───────┘
   */
       _______,_______,_______,_______,_______,_______,                               _______,_______,_______,_______,_______,_______,
       _______,KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                  KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,
       _______,_LCTL_A,_LOPT_S,_LCMD_D,_LSFT_F,KC_G,                                  KC_H,   _RSFT_J,_RCMD_K,_ROPT_L,_RCTL_C,KC_QUOT,
       _______,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                                  KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RBRC,
                       XXXXXXX,XXXXXXX,     _______,_______,_______,     _______,_______,_______,     XXXXXXX,XXXXXXX,
                                                    _______,_______,     _______,_______
  ),

  [_NAVIGATION] = LAYOUT_5x6_5(
  /*
   *  ┌───────╥───────╥───────╥───────╥───────╥───────┐                              ┌───────╥───────╥───────╥───────╥───────╥───────┐
   *  │ Reset ║       ║       ║       ║       ║       │                              │  F7   ║  F8   ║  F9   ║  F10  ║  F11  ║  F12  │
   *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
   *  │       ║       ║       ║       ║       ║       │                              │ Redo  ║ Paste ║ Copy  ║  Cut  ║ Undo  ║       │
   *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
   *  │       ║  Ctrl ║  Opt  ║  Cmd  ║ Shift ║       │                              │ PgUp  ║   ←   ║   ↓   ║   ↑   ║   →   ║       │
   *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
   *  │       ║       ║       ║       ║       ║       │                              │ PgDn  ║  ← ⌘  ║  ← ⌥  ║  ⌥ →  ║  ⌘ →  ║       │
   *  └───────╨───────╬═══════╬═══════╬───────╨───────┘                              └───────╨───────╬═══════╬═══════╬───────╨───────┘
   *                  │       ║       │    ┌───────╥┬┬┬┬┬┬┬╥───────┐    ┌───────╥───────╥───────┐    │       ║       │
   *                  └───────╨───────┘    │       ║│┃┃┃┃┃│║       │    │ Enter ║ Bksp  ║  Del  │    └───────╨───────┘
   *                                       └───────╬╧╧╧╧╧╧╧╬═══════╡    ╞═══════╬═══════╬───────┘
   *                                               │       ║       │    │       ║       │
   *                                               └───────╨───────┘    └───────╨───────┘
   */
       RESET,  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                               KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,
       XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                               _REDO,  _PASTE, _COPY,  _CUT,   _UNDO,  XXXXXXX,
       XXXXXXX,KC_LCTL,KC_LOPT,KC_LCMD,KC_LSFT,XXXXXXX,                               KC_PGUP,KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,XXXXXXX,
       XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                               KC_PGDN,_HOME,  _W_LEFT,_W_RGHT,_END,   XXXXXXX,
                       XXXXXXX,XXXXXXX,     XXXXXXX,XXXXXXX,XXXXXXX,     KC_ENT, KC_BSPC,KC_DEL,      XXXXXXX, XXXXXXX,
                                                    XXXXXXX,XXXXXXX,     XXXXXXX,XXXXXXX
  ),

  [_NUMBERS] = LAYOUT_5x6_5(
  /*
   *  ┌───────╥───────╥───────╥───────╥───────╥───────┐                              ┌───────╥───────╥───────╥───────╥───────╥───────┐
   *  │  F1   ║  F2   ║  F3   ║  F4   ║  F5   ║  F6   │                              │       ║       ║       ║       ║       ║       │
   *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
   *  │       ║  [ {  ║  7 &  ║  8 *  ║  9 (  ║  ] }  │                              │       ║       ║       ║       ║       ║       │
   *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
   *  │       ║  ; :  ║  4 $  ║  5 %  ║  6 ^  ║  = +  │                              │       ║ Shift ║  Cmd  ║  Opt  ║ Ctrl  ║       │
   *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
   *  │       ║  ` ~  ║  1 !  ║  2 @  ║  3 #  ║  \ |  │                              │       ║       ║       ║       ║       ║       │
   *  └───────╨───────╬═══════╬═══════╬───────╨───────┘                              └───────╨───────╬═══════╬═══════╬───────╨───────┘
   *                  │   <   ║   >   │    ┌───────╥───────╥───────┐    ┌───────╥┬┬┬┬┬┬┬╥───────┐    │       ║       │
   *                  └───────╨───────┘    │   .   ║  0 )  ║  - _  │    │       ║│┃┃┃┃┃│║       │    └───────╨───────┘
   *                                       └───────╬═══════╬═══════╡    ╞═══════╬╧╧╧╧╧╧╧╬───────┘
   *                                               │       ║       │    │       ║       │
   *                                               └───────╨───────┘    └───────╨───────┘
   */
       KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,                                 XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
       XXXXXXX,KC_LBRC,KC_7,   KC_8,   KC_9,   KC_RBRC,                               XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
       XXXXXXX,KC_SCLN,KC_4,   KC_5,   KC_6,   KC_EQL,                                XXXXXXX,KC_RSFT,KC_RCMD,KC_ROPT,KC_RCTL,XXXXXXX,
       XXXXXXX,KC_GRV, KC_1,   KC_2,   KC_3,   KC_BSLS,                               XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                       KC_LT,  KC_GT,       KC_PDOT,KC_0,   KC_MINS,     XXXXXXX,XXXXXXX,XXXXXXX,     XXXXXXX,XXXXXXX,
                                                    XXXXXXX,XXXXXXX,     XXXXXXX,XXXXXXX
  )
};

/*
 * Key overrides for implementing Engram punctuation on US ANSI keys
 */

// 9( → '(
const key_override_t nine_single_quote_override = ko_make_with_layers_and_negmods(0, KC_9, KC_QUOT, 1 << _ENGRAM, MOD_MASK_SHIFT);

// 0) → ")
const key_override_t zero_double_quote_override = ko_make_with_layers_and_negmods(0, KC_0, S(KC_QUOT), 1 << _ENGRAM, MOD_MASK_SHIFT);

// ,< → ,;
const key_override_t lt_semicolon_override = ko_make_with_layers(MOD_BIT(KC_RIGHT_SHIFT), KC_COMMA, KC_SEMICOLON, 1 << _ENGRAM);

// .> → .:
const key_override_t gt_colon_override = ko_make_with_layers(MOD_BIT(KC_LEFT_SHIFT), KC_DOT, KC_COLON, 1 << _ENGRAM);

// U_QUEX → ?!
const key_override_t quex_question_override = ko_make_with_layers_and_negmods(0, U_QUEX, KC_QUESTION, 1 << _ENGRAM, MOD_MASK_SHIFT);
const key_override_t quex_exclaim_override = ko_make_with_layers(MOD_BIT(KC_LEFT_SHIFT), U_QUEX, KC_EXCLAIM, 1 << _ENGRAM);

const key_override_t **key_overrides = (const key_override_t *[]){
    &nine_single_quote_override,
    &zero_double_quote_override,
    &lt_semicolon_override,
    &gt_colon_override,
    &quex_question_override,
    &quex_exclaim_override,
    NULL
};
