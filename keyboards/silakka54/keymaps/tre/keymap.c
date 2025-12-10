// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

#include "sm_td.h"


enum {
    QWERTY = 0,
    GALLIUM = 1,
    SYM = 2,
    NUM_NAV = 3,
    APP_WIN = 4,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────┬───┬───┬──────┬──────┬─────┐   ┌─────┬──────┬──────┬───┬───┬──────┐
//    │  `   │ 1 │ 2 │  3   │  4   │  5  │   │  6  │  7   │  8   │ 9 │ 0 │  -   │
//    ├──────┼───┼───┼──────┼──────┼─────┤   ├─────┼──────┼──────┼───┼───┼──────┤
//    │ tab  │ q │ w │  e   │  r   │  t  │   │  y  │  u   │  i   │ o │ p │ bspc │
//    ├──────┼───┼───┼──────┼──────┼─────┤   ├─────┼──────┼──────┼───┼───┼──────┤
//    │ esc  │ a │ s │  d   │  f   │  g  │   │  h  │  j   │  k   │ l │ ; │  '   │
//    ├──────┼───┼───┼──────┼──────┼─────┤   ├─────┼──────┼──────┼───┼───┼──────┤
//    │ lsft │ z │ x │  c   │  v   │  b  │   │  n  │  m   │  ,   │ . │ / │ rsft │
//    └──────┴───┴───┼──────┼──────┼─────┤   ├─────┼──────┼──────┼───┴───┴──────┘
//                   │ lctl │ lalt │ spc │   │ ent │ ralt │ rctl │
//                   └──────┴──────┴─────┘   └─────┴──────┴──────┘
[QWERTY] = LAYOUT(
  KC_GRV  , KC_1 , KC_2 , KC_3    , KC_4    , KC_5   ,     KC_6   , KC_7    , KC_8    , KC_9   , KC_0    , KC_MINUS,
  KC_TAB  , KC_Q , KC_W , KC_E    , KC_R    , KC_T   ,     KC_Y   , KC_U    , KC_I    , KC_O   , KC_P    , KC_BSPC ,
  KC_ESC  , KC_A , KC_S , KC_D    , KC_F    , KC_G   ,     KC_H   , KC_J    , KC_K    , KC_L   , KC_SCLN , KC_QUOT ,
  KC_LSFT , KC_Z , KC_X , KC_C    , KC_V    , KC_B   ,     KC_N   , KC_M    , KC_COMM , KC_DOT , KC_SLSH , KC_RSFT ,
                          KC_LCTL , KC_LALT , KC_SPC ,     KC_ENT , KC_RALT , KC_RCTL
),

//    ┌──────┬───┬───┬──────┬──────┬─────┐   ┌─────┬──────┬──────┬───┬───┬──────┐
//    │  `   │ 1 │ 2 │  3   │  4   │  5  │   │  6  │  7   │  8   │ 9 │ 0 │  -   │
//    ├──────┼───┼───┼──────┼──────┼─────┤   ├─────┼──────┼──────┼───┼───┼──────┤
//    │ tab  │ b │ l │  d   │  c   │  v  │   │  j  │  y   │  o   │ u │ , │ bspc │
//    ├──────┼───┼───┼──────┼──────┼─────┤   ├─────┼──────┼──────┼───┼───┼──────┤
//    │ esc  │ n │ r │  t   │  s   │  g  │   │  p  │  h   │  a   │ e │ i │  /   │
//    ├──────┼───┼───┼──────┼──────┼─────┤   ├─────┼──────┼──────┼───┼───┼──────┤
//    │ lsft │ x │ q │  m   │  w   │  z  │   │  k  │  f   │  '   │ ; │ . │ rsft │
//    └──────┴───┴───┼──────┼──────┼─────┤   ├─────┼──────┼──────┼───┴───┴──────┘
//                   │ lctl │ lalt │ spc │   │ ent │ ralt │ rctl │
//                   └──────┴──────┴─────┘   └─────┴──────┴──────┘
[GALLIUM] = LAYOUT(
  KC_GRV  , KC_1 , KC_2 , KC_3    , KC_4    , KC_5   ,     KC_6   , KC_7    , KC_8    , KC_9    , KC_0    , KC_MINUS,
  KC_TAB  , KC_B , KC_L , KC_D    , KC_C    , KC_V   ,     KC_J   , KC_Y    , KC_O    , KC_U    , KC_COMM , KC_BSPC ,
  KC_ESC  , KC_N , KC_R , KC_T    , KC_S    , KC_G   ,     KC_P   , KC_H    , KC_A    , KC_E    , KC_I    , KC_SLSH ,
  KC_LSFT , KC_X , KC_Q , KC_M    , KC_W    , KC_Z   ,     KC_K   , KC_F    , KC_QUOT , KC_SCLN , KC_DOT  , KC_RSFT ,
                          KC_LCTL , KC_LALT , KC_SPC ,     KC_ENT , KC_RALT , KC_RCTL
),

//    ┌─────────┬─────┬─────┬─────┬──────┬─────┐   ┌─────┬──────┬─────┬─────┬─────┬─────────┐
//    │         │     │     │     │      │     │   │     │      │     │     │     │         │
//    ├─────────┼─────┼─────┼─────┼──────┼─────┤   ├─────┼──────┼─────┼─────┼─────┼─────────┤
//    │         │  !  │  @  │  #  │  $   │     │   │     │  %   │  ^  │  &  │  *  │         │
//    ├─────────┼─────┼─────┼─────┼──────┼─────┤   ├─────┼──────┼─────┼─────┼─────┼─────────┤
//    │         │  (  │  <  │  [  │  {   │     │   │     │  }   │  ]  │  >  │  )  │         │
//    ├─────────┼─────┼─────┼─────┼──────┼─────┤   ├─────┼──────┼─────┼─────┼─────┼─────────┤
//    │ CW_TOGG │     │  \  │  -  │  =   │     │   │     │  +   │  _  │  |  │     │ CW_TOGG │
//    └─────────┴─────┴─────┼─────┼──────┼─────┤   ├─────┼──────┼─────┼─────┴─────┴─────────┘
//                          │     │ lgui │     │   │     │ rgui │     │
//                          └─────┴──────┴─────┘   └─────┴──────┴─────┘
[SYM] = LAYOUT(
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS  , KC_TRNS  , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_EXLM , KC_AT   , KC_HASH  , KC_DLR   , KC_TRNS ,     KC_TRNS , KC_PERC , KC_CIRC , KC_AMPR , KC_ASTR , KC_TRNS,
  KC_TRNS , KC_LPRN , KC_LT   , KC_LBRC  , KC_LCBR  , KC_TRNS ,     KC_TRNS , KC_RCBR , KC_RBRC , KC_GT   , KC_RPRN , KC_TRNS,
  CW_TOGG , KC_TRNS , KC_BSLS , KC_MINUS , KC_EQUAL , KC_TRNS ,     KC_TRNS , KC_PLUS , KC_UNDS , KC_PIPE , KC_TRNS , CW_TOGG,
                                KC_TRNS  , KC_LGUI  , KC_TRNS ,     KC_TRNS , KC_RGUI , KC_TRNS
),

//    ┌──────┬──────┬──────┬──────┬──────┬──────┐   ┌──────┬──────┬──────┬──────┬──────┬──────┐
//    │  f1  │  f2  │  f3  │  f4  │  f5  │  f6  │   │  f7  │  f8  │  f9  │ f10  │ f11  │ f12  │
//    ├──────┼──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼──────┼──────┤
//    │      │ home │      │  up  │      │ pgup │   │ kp_* │ kp_7 │ kp_8 │ kp_9 │ kp_/ │ bspc │
//    ├──────┼──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼──────┼──────┤
//    │      │ end  │ left │ down │ rght │ pgdn │   │ kp_+ │ kp_4 │ kp_5 │ kp_6 │ kp_- │ kp_, │
//    ├──────┼──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼──────┼──────┤
//    │ pscr │ ins  │      │      │ app  │ del  │   │ kp_0 │ kp_1 │ kp_2 │ kp_3 │ kp_= │ kp_. │
//    └──────┴──────┴──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┴──────┴──────┘
//                         │      │      │      │   │      │      │      │
//                         └──────┴──────┴──────┘   └──────┴──────┴──────┘
[NUM_NAV] = LAYOUT(
  KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5    , KC_F6   ,     KC_F7   , KC_F8   , KC_F9   , KC_F10 , KC_F11  , KC_F12 ,
  KC_TRNS , KC_HOME , KC_TRNS , KC_UP   , KC_TRNS  , KC_PGUP ,     KC_PAST , KC_P7   , KC_P8   , KC_P9  , KC_PSLS , KC_BSPC,
  KC_TRNS , KC_END  , KC_LEFT , KC_DOWN , KC_RIGHT , KC_PGDN ,     KC_PPLS , KC_P4   , KC_P5   , KC_P6  , KC_PMNS , KC_PCMM,
  KC_PSCR , KC_INS  , KC_TRNS , KC_TRNS , KC_APP   , KC_DEL  ,     KC_P0   , KC_P1   , KC_P2   , KC_P3  , KC_PEQL , KC_PDOT,
                                KC_TRNS , KC_TRNS  , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS
),

//    ┌─────┬─────┬───────────┬───────────┬───────────┬───────────┐   ┌─────┬─────────┬─────────┬─────┬─────┬───────┐
//    │     │     │ LCG(left) │ LSG(left) │ LSG(rght) │ LCG(rght) │   │     │         │         │     │     │       │
//    ├─────┼─────┼───────────┼───────────┼───────────┼───────────┤   ├─────┼─────────┼─────────┼─────┼─────┼───────┤
//    │     │     │           │   vold    │   volu    │           │   │     │ LSA(f1) │ LSA(f2) │     │     │       │
//    ├─────┼─────┼───────────┼───────────┼───────────┼───────────┤   ├─────┼─────────┼─────────┼─────┼─────┼───────┤
//    │     │     │   mstp    │   mprv    │   mnxt    │   mply    │   │     │         │         │     │     │       │
//    ├─────┼─────┼───────────┼───────────┼───────────┼───────────┤   ├─────┼─────────┼─────────┼─────┼─────┼───────┤
//    │     │     │           │           │           │           │   │     │         │         │     │     │ TG(1) │
//    └─────┴─────┴───────────┼───────────┼───────────┼───────────┤   ├─────┼─────────┼─────────┼─────┴─────┴───────┘
//                            │           │           │  QK_LLCK  │   │     │         │         │
//                            └───────────┴───────────┴───────────┘   └─────┴─────────┴─────────┘
[APP_WIN] = LAYOUT(
  KC_TRNS , KC_TRNS , LCG(KC_LEFT) , LSG(KC_LEFT) , LSG(KC_RIGHT) , LCG(KC_RIGHT) ,     KC_TRNS , KC_TRNS    , KC_TRNS    , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS      , KC_VOLD      , KC_VOLU       , KC_TRNS       ,     KC_TRNS , LSA(KC_F1) , LSA(KC_F2) , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_MSTP      , KC_MPRV      , KC_MNXT       , KC_MPLY       ,     KC_TRNS , KC_TRNS    , KC_TRNS    , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS      , KC_TRNS      , KC_TRNS       , KC_TRNS       ,     KC_TRNS , KC_TRNS    , KC_TRNS    , KC_TRNS , KC_TRNS , TG(1)  ,
                                     KC_TRNS      , KC_TRNS       , QK_LLCK       ,     KC_TRNS , KC_TRNS    , KC_TRNS
)
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
                       'L', 'L', 'L',  'R', 'R', 'R'
);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_smtd(keycode, record)) {
    return false;
  }
  // TODO
  return true;
}

smtd_resolution on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
  switch(keycode) {
    // QWERTY
    SMTD_LT(KC_A, SYM)
    SMTD_MT(KC_S, KC_LCTL)
    SMTD_MT(KC_D, KC_LALT)
    SMTD_MT(KC_F, KC_LSFT)

    SMTD_MT(KC_J, KC_LSFT)
    SMTD_MT(KC_K, KC_LALT)
    SMTD_MT(KC_L, KC_LCTL)
    SMTD_LT(KC_SCLN, SYM)

    // GALLIUM
    //SMTD_LT(KC_N, SYM)
    //SMTD_MT(KC_R, KC_LCTL)
    //SMTD_MT(KC_T, KC_LALT)
    //SMTD_MT(KC_S, KC_LSFT)

    //SMTD_MT(KC_H, KC_LSFT)
    //SMTD_MT(KC_A, KC_LALT)
    //SMTD_MT(KC_E, KC_LCTL)
    //SMTD_LT(KC_I, SYM)

    // Layers
    SMTD_LT(KC_LALT, NUM_NAV)
    SMTD_LT(KC_RALT, NUM_NAV)
    SMTD_LT(KC_RCTL, APP_WIN)
  }
  return SMTD_RESOLUTION_UNHANDLED;
}

/*
[5] = LAYOUT(
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
                                KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS
),
[6] = LAYOUT(
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
                                KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS
),
[7] = LAYOUT(
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
                                KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS
)
*/
