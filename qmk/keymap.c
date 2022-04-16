// Copyright 2022 Alex Olshansky (@clbn)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Layers
#define L_ENGRAM 0
#define L_QWERTY 1
#define L_MEDIA 2
#define L_NAV 3
#define L_SYM 5
#define L_NUM 6
#define L_FUN 7

// Top thumb rows: layer switching (turn on `layer` when held, `kc` when tapped)
#define LT_MED  LT(L_MEDIA, KC_ESC)
#define LT_NAV  LT(L_NAV,   KC_SPACE)
#define LT_SYM  LT(L_SYM,   KC_ENTER)
#define LT_NUM  LT(L_NUM,   KC_BACKSPACE)
#define LT_FUN  LT(L_FUN,   KC_DEL)

// Bottom thumb rows: layer switching (turn on `layer` and turn off other layers)
#define TO_ENGR TO(L_ENGRAM)
#define TO_QWER TO(L_QWERTY)

// Bottom thumb rows: host lang switching (sends shortcut for switching input source)
#define HO_LNG1 LCMD(LSFT(KC_1))
#define HO_LNG2 LCMD(LSFT(KC_2))

// Engram home row mods (a.k.a. mod tap keys: `mod` when held, `kc` when tapped)
#define E_HRM_C LCTL_T(KC_C)
#define E_HRM_I LOPT_T(KC_I)
#define E_HRM_E LCMD_T(KC_E)
#define E_HRM_A LSFT_T(KC_A)
#define E_HRM_H RSFT_T(KC_H)
#define E_HRM_T RCMD_T(KC_T)
#define E_HRM_S ROPT_T(KC_S)
#define E_HRM_N RCTL_T(KC_N)

// Qwerty home row mods (a.k.a. mod tap keys: `mod` when held, `kc` when tapped)
#define Q_HRM_A LCTL_T(KC_A)
#define Q_HRM_S LOPT_T(KC_S)
#define Q_HRM_D LCMD_T(KC_D)
#define Q_HRM_F LSFT_T(KC_F)
#define Q_HRM_J RSFT_T(KC_J)
#define Q_HRM_K RCMD_T(KC_K)
#define Q_HRM_L ROPT_T(KC_L)
#define Q_HRM_C RCTL_T(KC_SEMICOLON)

// Mac shortcuts
#define U_REDO  SCMD(KC_Z)
#define U_PASTE LCMD(KC_V)
#define U_COPY  LCMD(KC_C)
#define U_CUT   LCMD(KC_X)
#define U_UNDO  LCMD(KC_Z)
#define U_HOME  LCMD(KC_LEFT)
#define U_WRD_L LOPT(KC_LEFT)
#define U_WRD_R LOPT(KC_RIGHT)
#define U_END   LCMD(KC_RIGHT)

enum custom_keycodes {
  U_QUEX = SAFE_RANGE // The custom key for ? and !
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [L_ENGRAM] = LAYOUT_5x6_5(
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
     *                  └───────╨───────┘    │Esc Med║Spc Nav║  Tab  │    │Ent Sym║Bsp Num║Del Fun│    └───────╨───────┘
     *                                       └───────╬═══════╬═══════╡    ╞═══════╬═══════╬───────┘
     *                                               │Engram ║ Latin │    │  Cyr  ║ Qwerty│
     *                                               └───────╨───────┘    └───────╨───────┘
     */
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_B,    KC_Y,    KC_O,    KC_U,    KC_9,                                  KC_0,    KC_L,    KC_D,    KC_W,    KC_V,    KC_Z,
    KC_GRV,  E_HRM_C, E_HRM_I, E_HRM_E, E_HRM_A, KC_COMM,                               KC_DOT,  E_HRM_H, E_HRM_T, E_HRM_S, E_HRM_N, KC_Q,
    XXXXXXX, KC_G,    KC_X,    KC_J,    KC_K,    KC_MINS,                               U_QUEX,  KC_R,    KC_M,    KC_F,    KC_P,    KC_SLASH,
                      XXXXXXX, XXXXXXX,     LT_MED,  LT_NAV,  KC_TAB,      LT_SYM,  LT_NUM,  LT_FUN,      XXXXXXX, XXXXXXX,
                                                     TO_ENGR, HO_LNG1,     HO_LNG2, TO_QWER
  ),

  [L_QWERTY] = LAYOUT_5x6_5(
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
    _______, _______, _______, _______, _______, _______,                               _______, _______, _______, _______, _______, _______,
    _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    _______, Q_HRM_A, Q_HRM_S, Q_HRM_D, Q_HRM_F, KC_G,                                  KC_H,    Q_HRM_J, Q_HRM_K, Q_HRM_L, Q_HRM_C, KC_QUOT,
    _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC,
                      XXXXXXX, XXXXXXX,     _______, _______, _______,     _______, _______, _______,     XXXXXXX, XXXXXXX,
                                                     _______, _______,     _______, _______
  ),

  [L_MEDIA] = LAYOUT_5x6_5(
    /*
     *  ┌───────╥───────╥───────╥───────╥───────╥───────┐                              ┌───────╥───────╥───────╥───────╥───────╥───────┐
     *  │ Reset ║       ║       ║       ║       ║       │                              │       ║       ║       ║       ║       ║       │
     *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
     *  │       ║       ║       ║       ║       ║       │                              │RGB Tog║RGB Mod║RGB Hue║RGB Sat║RGB Val║       │
     *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
     *  │       ║  Ctrl ║  Opt  ║  Cmd  ║ Shift ║       │                              │       ║ Prev  ║ Vol ↓ ║ Vol ↑ ║ Next  ║       │
     *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
     *  │       ║       ║       ║       ║       ║       │                              │       ║       ║ Bri ↓ ║ Bri ↑ ║       ║       │
     *  └───────╨───────╬═══════╬═══════╬───────╨───────┘                              └───────╨───────╬═══════╬═══════╬───────╨───────┘
     *                  │       ║       │    ┌┬┬┬┬┬┬┬╥───────╥───────┐    ┌───────╥───────╥───────┐    │       ║       │
     *                  └───────╨───────┘    ││┃┃┃┃┃│║       ║       │    │       ║ Play  ║ Mute  │    └───────╨───────┘
     *                                       └┴┴┴┴┴┴┴╬═══════╬═══════╡    ╞═══════╬═══════╬───────┘
     *                                               │       ║       │    │       ║       │
     *                                               └───────╨───────┘    └───────╨───────┘
     */
    RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,
    XXXXXXX, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, XXXXXXX,                               XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX,
                      XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_MPLY, KC_MUTE,     XXXXXXX, XXXXXXX,
                                                     XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX
  ),

  [L_NAV] = LAYOUT_5x6_5(
    /*
     *  ┌───────╥───────╥───────╥───────╥───────╥───────┐                              ┌───────╥───────╥───────╥───────╥───────╥───────┐
     *  │ Reset ║       ║       ║       ║       ║       │                              │       ║       ║       ║       ║       ║       │
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
    RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               U_REDO,  U_PASTE, U_COPY,  U_CUT,   U_UNDO,  XXXXXXX,
    XXXXXXX, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, XXXXXXX,                               KC_PGUP, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               KC_PGDN, U_HOME,  U_WRD_L, U_WRD_R, U_END,   XXXXXXX,
                      XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,     KC_ENT,  KC_BSPC, KC_DEL,      XXXXXXX, XXXXXXX,
                                                     XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX
  ),

  [L_SYM] = LAYOUT_5x6_5(
    /*
     *  ┌───────╥───────╥───────╥───────╥───────╥───────┐                              ┌───────╥───────╥───────╥───────╥───────╥───────┐
     *  │       ║       ║       ║       ║       ║       │                              │       ║       ║       ║       ║       ║       │
     *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
     *  │       ║   {   ║   &   ║   *   ║   (   ║   }   │                              │       ║       ║       ║       ║       ║       │
     *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
     *  │       ║   :   ║   $   ║   %   ║   ^   ║   +   │                              │       ║ Shift ║  Cmd  ║  Opt  ║ Ctrl  ║       │
     *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
     *  │       ║   ~   ║   !   ║   @   ║   #   ║   |   │                              │       ║       ║       ║       ║       ║       │
     *  └───────╨───────╬═══════╬═══════╬───────╨───────┘                              └───────╨───────╬═══════╬═══════╬───────╨───────┘
     *                  │   <   ║   >   │    ┌───────╥───────╥───────┐    ┌┬┬┬┬┬┬┬╥───────╥───────┐    │       ║       │
     *                  └───────╨───────┘    │   (   ║   )   ║   _   │    ││┃┃┃┃┃│║       ║       │    └───────╨───────┘
     *                                       └───────╬═══════╬═══════╡    ╞╧╧╧╧╧╧╧╬═══════╬───────┘
     *                                               │       ║       │    │       ║       │
     *                                               └───────╨───────┘    └───────╨───────┘
     */
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                               XXXXXXX, KC_RSFT, KC_RCMD, KC_ROPT, KC_RCTL, XXXXXXX,
    XXXXXXX, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      KC_LT,   KC_GT,       KC_LPRN, KC_RPRN, KC_UNDS,     XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX,
                                                     XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX
  ),

  [L_NUM] = LAYOUT_5x6_5(
    /*
     *  ┌───────╥───────╥───────╥───────╥───────╥───────┐                              ┌───────╥───────╥───────╥───────╥───────╥───────┐
     *  │       ║       ║       ║       ║       ║       │                              │       ║       ║       ║       ║       ║       │
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
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,                                XXXXXXX, KC_RSFT, KC_RCMD, KC_ROPT, KC_RCTL, XXXXXXX,
    XXXXXXX, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      KC_LT,   KC_GT,       KC_PDOT, KC_0,    KC_MINS,     XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX,
                                                     XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX
  ),

  [L_FUN] = LAYOUT_5x6_5(
    /*
     *  ┌───────╥───────╥───────╥───────╥───────╥───────┐                              ┌───────╥───────╥───────╥───────╥───────╥───────┐
     *  │       ║       ║       ║       ║       ║       │                              │       ║       ║       ║       ║       ║       │
     *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
     *  │       ║  F12  ║  F7   ║  F8   ║  F9   ║       │                              │       ║       ║       ║       ║       ║       │
     *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
     *  │       ║  F11  ║  F4   ║  F5   ║  F6   ║       │                              │       ║ Shift ║  Cmd  ║  Opt  ║ Ctrl  ║       │
     *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
     *  │       ║  F10  ║  F1   ║  F2   ║  F3   ║       │                              │       ║       ║       ║       ║       ║       │
     *  └───────╨───────╬═══════╬═══════╬───────╨───────┘                              └───────╨───────╬═══════╬═══════╬───────╨───────┘
     *                  │       ║       │    ┌───────╥───────╥───────┐    ┌───────╥───────╥┬┬┬┬┬┬┬┐    │       ║       │
     *                  └───────╨───────┘    │  Esc  ║ Space ║  Tab  │    │       ║       ║│┃┃┃┃┃││    └───────╨───────┘
     *                                       └───────╬═══════╬═══════╡    ╞═══════╬═══════╬┴┴┴┴┴┴┴┘
     *                                               │       ║       │    │       ║       │
     *                                               └───────╨───────┘    └───────╨───────┘
     */
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_F12,  KC_F7,   KC_F8,   KC_F9,   XXXXXXX,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_F11,  KC_F4,   KC_F5,   KC_F6,   XXXXXXX,                               XXXXXXX, KC_RSFT, KC_RCMD, KC_ROPT, KC_RCTL, XXXXXXX,
    XXXXXXX, KC_F10,  KC_F1,   KC_F2,   KC_F3,   XXXXXXX,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      XXXXXXX, XXXXXXX,     KC_ESC,  KC_SPC,  KC_TAB,      XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX,
                                                     XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX
  )
};

/*
 * Key overrides for implementing Engram punctuation on US ANSI keys
 */

// 9( → '(
const key_override_t nine_single_quote_override = ko_make_with_layers_and_negmods(0, KC_9, KC_QUOT, 1 << L_ENGRAM, MOD_MASK_SHIFT);

// 0) → ")
const key_override_t zero_double_quote_override = ko_make_with_layers_and_negmods(0, KC_0, S(KC_QUOT), 1 << L_ENGRAM, MOD_MASK_SHIFT);

// ,< → ,;
const key_override_t lt_semicolon_override = ko_make_with_layers(MOD_BIT(KC_RIGHT_SHIFT), KC_COMMA, KC_SEMICOLON, 1 << L_ENGRAM);

// .> → .:
const key_override_t gt_colon_override = ko_make_with_layers(MOD_BIT(KC_LEFT_SHIFT), KC_DOT, KC_COLON, 1 << L_ENGRAM);

// U_QUEX → ?!
const key_override_t quex_question_override = ko_make_with_layers_and_negmods(0, U_QUEX, KC_QUESTION, 1 << L_ENGRAM, MOD_MASK_SHIFT);
const key_override_t quex_exclaim_override = ko_make_with_layers(MOD_BIT(KC_LEFT_SHIFT), U_QUEX, KC_EXCLAIM, 1 << L_ENGRAM);

const key_override_t **key_overrides = (const key_override_t *[]){
    &nine_single_quote_override,
    &zero_double_quote_override,
    &lt_semicolon_override,
    &gt_colon_override,
    &quex_question_override,
    &quex_exclaim_override,
    NULL
};
