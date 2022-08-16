#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_korean.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_lithuanian_azerty.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"
#include "keymap_belgian.h"
#include "keymap_us_international.h"
#include "keymap_croatian.h"
#include "keymap_turkish_q.h"
#include "keymap_slovak.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)
#define TIMEOUT 10

enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_MACRO_8,
  ST_MACRO_9,
  ST_MACRO_10,
  ST_MACRO_11,
  ST_MACRO_12,
  ST_MACRO_13,
  ST_MACRO_14,
  ST_MACRO_15,
  ST_MACRO_16,
};


enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _LAYER4,
  _LAYER5,
  _LAYER6,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
    KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_DELETE,      KC_BSPACE,      KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           
    KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_QUOTE,       KC_ENTER,       KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      
    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_ESCAPE,      KC_TAB,         KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       
    KC_LCTRL,       KC_LALT,        MO(5),          KC_LSHIFT,      LOWER,          KC_SPACE,       KC_NO,          RAISE,          MO(4),          TG(6),          KC_LGUI,        KC_RALT
  ),

  [_LOWER] = LAYOUT_planck_grid(
    ST_MACRO_0,     ST_MACRO_1,     ST_MACRO_2,     ST_MACRO_3,     ST_MACRO_4,     KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_EXLM,        KC_LCBR,        KC_RCBR,        KC_AT,          
    ST_MACRO_5,     ST_MACRO_6,     ST_MACRO_7,     ST_MACRO_8,     ST_MACRO_9,     KC_GRAVE,       KC_TRANSPARENT, KC_NO,          KC_HASH,        KC_LPRN,        KC_RPRN,        KC_DLR,         
    ST_MACRO_10,    ST_MACRO_11,    ST_MACRO_12,    ST_MACRO_13,    ST_MACRO_14,    LALT(LCTL(KC_T)),KC_TRANSPARENT, KC_NO,          KC_PIPE,        KC_LBRACKET,    KC_RBRACKET,    KC_AMPR,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_RAISE] = LAYOUT_planck_grid(
    KC_0,           KC_1,           KC_2,           KC_3,           KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_PERC,        KC_NO,          
    KC_DOT,         KC_4,           KC_5,           KC_6,           KC_NO,          KC_GRAVE,       KC_TRANSPARENT, KC_NO,          KC_MINUS,       KC_PLUS,        KC_SLASH,       KC_ASTR,        
    KC_EQUAL,       KC_7,           KC_8,           KC_9,           KC_NO,          KC_CALCULATOR,  KC_TRANSPARENT, KC_NO,          KC_BSLASH,      KC_LABK,        KC_RABK,        KC_CIRC,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_ADJUST] = LAYOUT_planck_grid(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    LCTL(LSFT(KC_DELETE)),KC_TAB,         LCTL(KC_DELETE),KC_DELETE,      KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,          KC_BSPACE,      LCTL(KC_BSPACE),KC_ENTER,       LCTL(LSFT(KC_BSPACE)),
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_LAYER4] = LAYOUT_planck_grid(
    KC_NO,          KC_MS_BTN2,     KC_MS_UP,       KC_MS_BTN1,     KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_ENTER,       KC_UP,          KC_NO,          KC_NO,          
    KC_NO,          KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_NO,          KC_NO,          KC_TRANSPARENT, ST_MACRO_15,    KC_LEFT,        KC_DOWN,        KC_RIGHT,       ST_MACRO_16,    
    KC_MS_WH_LEFT,  KC_MS_WH_UP,    KC_MS_BTN3,     KC_MS_WH_DOWN,  KC_MS_WH_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          MT(MOD_LALT, KC_HOME),KC_NO,          KC_END,         KC_NO,          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_LAYER5] = LAYOUT_planck_grid(
    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_NO,          KC_AUDIO_MUTE,  
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_MEDIA_REWIND,KC_MEDIA_FAST_FORWARD,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_STOP,  
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_LAYER6] = LAYOUT_planck_grid(
    KC_3,           KC_2,           KC_W,           KC_1,           KC_ESCAPE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_A,           KC_S,           KC_D,           KC_8,           KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_7,           KC_6,           KC_5,           KC_4,           KC_9,           KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_SPACE,       KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,255,255}, {0,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {214,224,185}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {214,224,185}, {214,224,185}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {41,255,255}, {41,255,255}, {23,251,254}, {41,255,255}, {23,251,254}, {0,0,255}, {23,251,254}, {23,251,254}, {23,251,254}, {41,255,255}, {41,255,255} },

    [1] = { {139,155,185}, {139,155,185}, {139,155,185}, {139,155,185}, {139,155,185}, {0,255,255}, {0,255,255}, {0,0,0}, {0,157,255}, {0,0,255}, {0,0,255}, {162,255,255}, {139,155,185}, {139,155,185}, {139,155,185}, {139,155,185}, {139,155,185}, {0,0,255}, {214,224,185}, {0,0,0}, {162,255,255}, {0,0,255}, {0,0,255}, {70,211,255}, {139,155,185}, {139,155,185}, {139,155,185}, {139,155,185}, {139,155,185}, {85,255,255}, {214,224,185}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {41,255,255}, {41,255,255}, {23,251,254}, {41,255,255}, {23,251,254}, {0,0,255}, {23,251,254}, {23,251,254}, {23,251,254}, {41,255,255}, {41,255,255} },

    [2] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,255}, {214,224,185}, {0,0,0}, {0,179,255}, {81,211,255}, {0,179,255}, {81,211,255}, {142,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {142,255,255}, {214,224,185}, {0,0,0}, {162,255,255}, {0,0,255}, {0,0,255}, {81,211,255}, {41,255,255}, {41,255,255}, {23,251,254}, {41,255,255}, {23,251,254}, {0,0,255}, {23,251,254}, {23,251,254}, {23,251,254}, {41,255,255}, {41,255,255} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {214,224,185}, {0,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {214,224,185}, {0,0,0}, {0,255,255}, {0,255,255}, {214,224,185}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {214,224,185}, {214,224,185}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {23,251,254}, {41,255,255}, {23,251,254}, {0,0,0}, {23,251,254}, {23,251,254}, {23,251,254}, {41,255,255}, {41,255,255} },

    [4] = { {0,0,0}, {0,0,255}, {0,153,255}, {32,255,255}, {0,0,0}, {0,255,255}, {0,255,255}, {0,0,0}, {32,255,255}, {0,153,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,153,255}, {0,153,255}, {0,153,255}, {0,0,0}, {0,0,0}, {214,224,185}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {32,157,255}, {32,157,255}, {32,157,255}, {32,157,255}, {32,157,255}, {214,224,185}, {214,224,185}, {0,0,0}, {0,153,255}, {0,0,0}, {0,153,255}, {0,0,0}, {41,255,255}, {41,255,255}, {23,251,254}, {41,255,255}, {23,251,254}, {0,0,255}, {23,251,254}, {23,251,254}, {23,251,254}, {41,255,255}, {41,255,255} },

    [5] = { {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {36,226,249}, {36,226,249}, {86,255,255}, {86,255,255}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {172,255,255}, {172,255,255}, {86,255,255}, {0,255,255}, {41,255,255}, {41,255,255}, {23,251,254}, {41,255,255}, {23,251,254}, {0,0,0}, {23,251,254}, {23,251,254}, {23,251,254}, {41,255,255}, {41,255,255} },

    [6] = { {0,0,255}, {0,0,255}, {0,153,255}, {0,0,255}, {214,224,185}, {0,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,153,255}, {0,153,255}, {0,153,255}, {0,0,255}, {0,0,0}, {214,224,185}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {214,224,185}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {23,251,254}, {41,255,255}, {0,0,255}, {0,0,255}, {23,251,254}, {23,251,254}, {23,251,254}, {41,255,255}, {41,255,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_F) SS_DELAY(TIMEOUT) SS_TAP(X_O) SS_DELAY(TIMEOUT) SS_TAP(X_R));

    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_E)) SS_DELAY(TIMEOUT) SS_TAP(X_A) SS_DELAY(TIMEOUT) SS_TAP(X_C) SS_DELAY(TIMEOUT) SS_TAP(X_H));

    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_M) SS_DELAY(TIMEOUT) SS_TAP(X_A) SS_DELAY(TIMEOUT) SS_TAP(X_P));

    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_F) SS_DELAY(TIMEOUT) SS_TAP(X_I) SS_DELAY(TIMEOUT) SS_TAP(X_L) SS_DELAY(TIMEOUT) SS_TAP(X_T) SS_DELAY(TIMEOUT) SS_TAP(X_E));

    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_S) SS_DELAY(TIMEOUT) SS_TAP(X_T) SS_DELAY(TIMEOUT) SS_TAP(X_R) SS_DELAY(TIMEOUT) SS_TAP(X_U) SS_DELAY(TIMEOUT) SS_TAP(X_C));

    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_W) SS_DELAY(TIMEOUT) SS_TAP(X_H) SS_DELAY(TIMEOUT) SS_TAP(X_I) SS_DELAY(TIMEOUT) SS_TAP(X_L) SS_DELAY(TIMEOUT) SS_TAP(X_E));

    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_E) SS_DELAY(TIMEOUT) SS_TAP(X_L) SS_DELAY(TIMEOUT) SS_TAP(X_S) SS_DELAY(TIMEOUT) SS_TAP(X_E) SS_DELAY(TIMEOUT) SS_TAP(X_SPACE));

    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_I) SS_DELAY(TIMEOUT) SS_TAP(X_F));

    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_T) SS_DELAY(TIMEOUT) SS_TAP(X_R) SS_DELAY(TIMEOUT) SS_TAP(X_Y));

    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_C) SS_DELAY(TIMEOUT) SS_TAP(X_A) SS_DELAY(TIMEOUT) SS_TAP(X_T) SS_DELAY(TIMEOUT) SS_TAP(X_C) SS_DELAY(TIMEOUT) SS_TAP(X_H));

    }
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_G) SS_DELAY(TIMEOUT) SS_TAP(X_E) SS_DELAY(TIMEOUT) SS_TAP(X_T));

    }
    break;
    case ST_MACRO_11:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_C) SS_DELAY(TIMEOUT) SS_TAP(X_L) SS_DELAY(TIMEOUT) SS_TAP(X_A) SS_DELAY(TIMEOUT) SS_TAP(X_S) SS_DELAY(TIMEOUT) SS_TAP(X_S));

    }
    break;
    case ST_MACRO_12:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_T) SS_DELAY(TIMEOUT) SS_TAP(X_H) SS_DELAY(TIMEOUT) SS_TAP(X_I) SS_DELAY(TIMEOUT) SS_TAP(X_S) SS_DELAY(TIMEOUT) SS_TAP(X_DOT));

    }
    break;
    case ST_MACRO_13:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_F) SS_DELAY(TIMEOUT) SS_TAP(X_U) SS_DELAY(TIMEOUT) SS_TAP(X_N) SS_DELAY(TIMEOUT) SS_TAP(X_C));

    }
    break;
    case ST_MACRO_14:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_T) SS_DELAY(TIMEOUT) SS_TAP(X_I) SS_DELAY(TIMEOUT) SS_TAP(X_O) SS_DELAY(TIMEOUT) SS_TAP(X_N));

    }
    break;
    case ST_MACRO_15:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)));

    }
    break;
    case ST_MACRO_16:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_RIGHT)));

    }
    break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


