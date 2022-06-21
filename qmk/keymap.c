// Copyright 2022 Alex Olshansky (@clbn)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Layers
#define L_ENGRAM 0
#define L_QWERTY 1
#define L_MEDIA 2
#define L_NAV 3
#define L_FUN 4
#define L_NUM 5
#define L_SYM 6

// Top thumb rows: layer switching (turn on `layer` when held, `kc` when tapped)
#define LT_MED  LT(L_MEDIA, KC_ESC)
#define LT_NAV  LT(L_NAV,   KC_SPACE)
#define LT_FUN  LT(L_FUN,   KC_ENTER)
#define LT_NUM  LT(L_NUM,   KC_BACKSPACE)
#define LT_SYM  LT(L_SYM,   KC_DEL)

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
#define U_TAB_L SCMD(KC_LBRC)
#define U_TAB_R SCMD(KC_RBRC)

enum custom_keycodes {
  U_QUEX = SAFE_RANGE, // Custom key for ? and !
  U_ARNG, // Macro for Å
  U_ADIA, // Macro for Ä
  U_ODIA  // Macro for Ö
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [L_ENGRAM] = LAYOUT_5x6_5(
    /*
     *  ┌───────╥───────╥───────╥───────╥───────╥───────┐                              ┌───────╥───────╥───────╥───────╥───────╥───────┐
     *  │       ║       ║       ║ Engram║       ║       │                              │       ║       ║Qwerty ║       ║       ║       │
     *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
     *  │   Å   ║   B   ║   Y   ║   O   ║   U   ║  ' (  │                              │  " )  ║   L   ║   D   ║   W   ║   V   ║   Z   │
     *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
     *  │  ` ~  ║ C ctl ║ I opt ║ E cmd ║ A sft ║  , ;  │                              │  . :  ║ H sft ║ T cmd ║ S opt ║ N ctl ║   Q   │
     *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
     *  │   Ä   ║   G   ║   X   ║   J   ║   K   ║  - _  │                              │  ? !  ║   R   ║   M   ║   F   ║   P   ║   Ö   │
     *  └───────╨───────╬═══════╬═══════╬───────╨───────┘                              └───────╨───────╬═══════╬═══════╬───────╨───────┘
     *                  │       ║       │    ┌───────╥───────╥───────┐    ┌───────╥───────╥───────┐    │       ║       │
     *                  └───────╨───────┘    │Esc Med║Spc Nav║  Tab  │    │Ent Fun║Bsp Num║Del Sym│    └───────╨───────┘
     *                                       └───────╬═══════╬═══════╡    ╞═══════╬═══════╬───────┘
     *                                               │       ║       │    │       ║       │
     *                                               └───────╨───────┘    └───────╨───────┘
     */
    XXXXXXX, XXXXXXX, XXXXXXX, TO_ENGR, XXXXXXX, XXXXXXX,                               XXXXXXX, XXXXXXX, TO_QWER, XXXXXXX, XXXXXXX, XXXXXXX,
    U_ARNG,  KC_B,    KC_Y,    KC_O,    KC_U,    KC_9,                                  KC_0,    KC_L,    KC_D,    KC_W,    KC_V,    KC_Z,
    KC_GRV,  E_HRM_C, E_HRM_I, E_HRM_E, E_HRM_A, KC_COMM,                               KC_DOT,  E_HRM_H, E_HRM_T, E_HRM_S, E_HRM_N, KC_Q,
    U_ADIA,  KC_G,    KC_X,    KC_J,    KC_K,    KC_MINS,                               U_QUEX,  KC_R,    KC_M,    KC_F,    KC_P,    U_ODIA,
                      XXXXXXX, XXXXXXX,     LT_MED,  LT_NAV,  KC_TAB,      LT_FUN,  LT_NUM,  LT_SYM,      XXXXXXX, XXXXXXX,
                                                     XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX
  ),

  [L_QWERTY] = LAYOUT_5x6_5(
    /*
     *  ┌───────╥───────╥───────╥───────╥───────╥───────┐                              ┌───────╥───────╥───────╥───────╥───────╥───────┐
     *  │       ║       ║       ║ Engram║       ║       │                              │       ║       ║Qwerty ║       ║       ║       │
     *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
     *  │       ║   Q   ║   W   ║   E   ║   R   ║   T   │                              │   Y   ║   U   ║   I   ║   O   ║   P   ║  [ {  │
     *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
     *  │  ` ~  ║ A ctl ║ S opt ║ D cmd ║ F sft ║   G   │                              │   H   ║ J sft ║ K cmd ║ L opt ║ ;: ctl║  ' "  │
     *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
     *  │       ║   Z   ║   X   ║   C   ║   V   ║   B   │                              │   N   ║   M   ║  , <  ║  . >  ║  / ?  ║  } ]  │
     *  └───────╨───────╬═══════╬═══════╬───────╨───────┘                              └───────╨───────╬═══════╬═══════╬───────╨───────┘
     *                  │       ║       │    ┌───────╥───────╥───────┐    ┌───────╥───────╥───────┐    │       ║       │
     *                  └───────╨───────┘    │Esc Med║Spc Nav║  Tab  │    │Ent Fun║Bsp Num║Del Sym│    └───────╨───────┘
     *                                       └───────╬═══════╬═══════╡    ╞═══════╬═══════╬───────┘
     *                                               │       ║       │    │       ║       │
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
     *                  │       ║       │    ┌───────╥┬┬┬┬┬┬┬╥───────┐    ┌───────╥───────╥───────┐    │ ← tab ║ tab → │
     *                  └───────╨───────┘    │       ║│┃┃┃┃┃│║       │    │ Enter ║ Bksp  ║  Del  │    └───────╨───────┘
     *                                       └───────╬╧╧╧╧╧╧╧╬═══════╡    ╞═══════╬═══════╬───────┘
     *                                               │       ║       │    │       ║       │
     *                                               └───────╨───────┘    └───────╨───────┘
     */
    RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               U_REDO,  U_PASTE, U_COPY,  U_CUT,   U_UNDO,  XXXXXXX,
    XXXXXXX, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, XXXXXXX,                               KC_PGUP, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               KC_PGDN, U_HOME,  U_WRD_L, U_WRD_R, U_END,   XXXXXXX,
                      XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,     KC_ENT,  KC_BSPC, KC_DEL,      U_TAB_L, U_TAB_R,
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
     *                  │       ║       │    ┌───────╥───────╥───────┐    ┌┬┬┬┬┬┬┬╥───────╥───────┐    │       ║       │
     *                  └───────╨───────┘    │  Esc  ║ Space ║  Tab  │    ││┃┃┃┃┃│║       ║       │    └───────╨───────┘
     *                                       └───────╬═══════╬═══════╡    ╞╧╧╧╧╧╧╧╬═══════╬───────┘
     *                                               │       ║       │    │       ║       │
     *                                               └───────╨───────┘    └───────╨───────┘
     */
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_F12,  KC_F7,   KC_F8,   KC_F9,   XXXXXXX,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_F11,  KC_F4,   KC_F5,   KC_F6,   XXXXXXX,                               XXXXXXX, KC_RSFT, KC_RCMD, KC_ROPT, KC_RCTL, XXXXXXX,
    XXXXXXX, KC_F10,  KC_F1,   KC_F2,   KC_F3,   XXXXXXX,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      XXXXXXX, XXXXXXX,     KC_ESC,  KC_SPC,  KC_TAB,      XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX,
                                                     XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX
  ),

  [L_NUM] = LAYOUT_5x6_5(
    /*
     *  ┌───────╥───────╥───────╥───────╥───────╥───────┐                              ┌───────╥───────╥───────╥───────╥───────╥───────┐
     *  │       ║       ║       ║       ║       ║       │                              │       ║       ║       ║       ║       ║       │
     *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
     *  │       ║   (   ║   7   ║   8   ║   9   ║   )   │                              │       ║       ║       ║       ║       ║       │
     *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
     *  │   `   ║   -   ║   4   ║   5   ║   6   ║   +   │                              │       ║ Shift ║  Cmd  ║  Opt  ║ Ctrl  ║       │
     *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
     *  │       ║   /   ║   1   ║   2   ║   3   ║   *   │                              │       ║       ║       ║       ║       ║       │
     *  └───────╨───────╬═══════╬═══════╬───────╨───────┘                              └───────╨───────╬═══════╬═══════╬───────╨───────┘
     *                  │   <   ║   >   │    ┌───────╥───────╥───────┐    ┌───────╥┬┬┬┬┬┬┬╥───────┐    │       ║       │
     *                  └───────╨───────┘    │   .   ║   0   ║   =   │    │       ║│┃┃┃┃┃│║       │    └───────╨───────┘
     *                                       └───────╬═══════╬═══════╡    ╞═══════╬╧╧╧╧╧╧╧╬───────┘
     *                                               │       ║       │    │       ║       │
     *                                               └───────╨───────┘    └───────╨───────┘
     */
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_LPRN, KC_7,    KC_8,    KC_9,    KC_RPRN,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_GRV,  KC_MINS, KC_4,    KC_5,    KC_6,    KC_PLUS,                               XXXXXXX, KC_RSFT, KC_RCMD, KC_ROPT, KC_RCTL, XXXXXXX,
    XXXXXXX, KC_SLSH, KC_1,    KC_2,    KC_3,    KC_ASTR,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      KC_LT,   KC_GT,       KC_PDOT, KC_0,    KC_EQL,      XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX,
                                                     XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX
  ),

  [L_SYM] = LAYOUT_5x6_5(
    /*
     *  ┌───────╥───────╥───────╥───────╥───────╥───────┐                              ┌───────╥───────╥───────╥───────╥───────╥───────┐
     *  │       ║       ║       ║       ║       ║       │                              │       ║       ║       ║       ║       ║       │
     *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
     *  │       ║   {   ║   &   ║   *   ║   ?   ║   }   │                              │       ║       ║       ║       ║       ║       │
     *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
     *  │   ~   ║   [   ║   $   ║   %   ║   ^   ║   ]   │                              │       ║ Shift ║  Cmd  ║  Opt  ║ Ctrl  ║       │
     *  ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡                              ╞═══════╬═══════╬═══════╬═══════╬═══════╬═══════╡
     *  │       ║   \   ║   !   ║   @   ║   #   ║   |   │                              │       ║       ║       ║       ║       ║       │
     *  └───────╨───────╬═══════╬═══════╬───────╨───────┘                              └───────╨───────╬═══════╬═══════╬───────╨───────┘
     *                  │   <   ║   >   │    ┌───────╥───────╥───────┐    ┌───────╥───────╥┬┬┬┬┬┬┬┐    │       ║       │
     *                  └───────╨───────┘    │   (   ║   )   ║   _   │    │       ║       ║│┃┃┃┃┃││    └───────╨───────┘
     *                                       └───────╬═══════╬═══════╡    ╞═══════╬═══════╬┴┴┴┴┴┴┴┘
     *                                               │       ║       │    │       ║       │
     *                                               └───────╨───────┘    └───────╨───────┘
     */
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_LCBR, KC_AMPR, KC_ASTR, KC_QUES, KC_RCBR,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_TILD, KC_LBRC, KC_DLR,  KC_PERC, KC_CIRC, KC_RBRC,                               XXXXXXX, KC_RSFT, KC_RCMD, KC_ROPT, KC_RCTL, XXXXXXX,
    XXXXXXX, KC_BSLS, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      KC_LT,   KC_GT,       KC_LPRN, KC_RPRN, KC_UNDS,     XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX,
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

/*
 * Temporarily turn off Qwerty layer (fall back to Engram) while Cmd/Opt/Ctrl are pressed
 *
 * This enables the use of common Latin-letter shortcuts (Cmd+T, Ctrl+C etc.)
 * when typing in Cyrillic+Qwerty, without manually switching layouts.
 *
 * To achieve this, we:
 *   1. Catch Cmd/Opt/Ctrl press in Qwerty layer and turn it off
 *      (so the base Engram layer becomes active). This step happens in
 *      process_record_user().
 *   2. Catch Cmd/Opt/Ctrl release in Engram layer (since that one is
 *      active after step 1), and if all of those mods are released,
 *      reactivate Qwerty layer. This step happens in post_process_record_user(),
 *      so we can check if the mods were released.
 */

uint8_t mod_state;
bool REACTIVATE_QWERTY = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  mod_state = get_mods();
  switch (keycode) {

    // Temporarily turn off Qwerty, step 1:

    case Q_HRM_A: // Left Ctrl
    case Q_HRM_S: // Left Opt
    case Q_HRM_D: // Left Cmd
    case Q_HRM_K: // Right Cmd
    case Q_HRM_L: // Right Opt
    case Q_HRM_C: // Right Ctrl
      // If it's hold (not tap) and keydown (not keyup)
      if (!record->tap.count && record->event.pressed) {
        REACTIVATE_QWERTY = true;
        layer_off(L_QWERTY);
      }
      return true;

    // Disable Cmd+H (T→H rollover accidents)

    case E_HRM_H:
      // If it's tap (not hold) and Right Cmd is pressed (but other mods are not)
      if (record->tap.count && (mod_state == MOD_BIT(KC_RGUI))) {
        return false;
      }
      return true;

    // Macros for Å, Ä, Ö

    case U_ARNG:
      if (record->event.pressed) {
        SEND_STRING(SS_RALT("a")); // Alt+A produces "å" in US ANSI on macOS (a.k.a. ABC)
        return false;
      }
      return true;

    case U_ADIA:
    case U_ODIA:
      if (record->event.pressed) {
        clear_mods(); // Deactivate possibly pressed shift(s), otherwise Alt+U won't produce the dead key we need
        SEND_STRING(SS_RALT("u")); // Send the dead key with Alt+U
        set_mods(mod_state); // Restore modifier state
        send_string(keycode == U_ADIA ? "a" : "o"); // Finally, send "A" or "O"
        return false;
      }
      return true;
  }
  return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    // Temporarily turn off Qwerty, step 2:

    case E_HRM_C: // Left Ctrl
    case E_HRM_I: // Left Opt
    case E_HRM_E: // Left Cmd
    case E_HRM_T: // Right Cmd
    case E_HRM_S: // Right Opt
    case E_HRM_N: // Right Ctrl
      // If it's hold (not tap) and keyup (not keydown)
      if (!record->tap.count && !record->event.pressed) {
        // If Qwerty layer was ON before and all C/A/G (Ctrl/Opt/Cmd) mods are released
        if (REACTIVATE_QWERTY && !(get_mods() & MOD_MASK_CAG)) {
          REACTIVATE_QWERTY = false;
          layer_on(L_QWERTY);
        }
      }
      break;

    // Combine Engram/Qwerty layout change with host lang change:

    case TO_ENGR:
      // After switching to Engram layout, also switch to Latin input source
      if (record->event.pressed) {
        tap_code16(HO_LNG1);
      }
      break;
    case TO_QWER:
      // After switching to Qwerty layout, also switch to Cyrillic input source
      if (record->event.pressed) {
        tap_code16(HO_LNG2);
      }
      break;
  }
}
