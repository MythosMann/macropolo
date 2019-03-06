<<<<<<< HEAD
/* Copyright 2019 REPLACE_WITH_YOUR_NAME
=======
/* Copyright 2019 mythosmann
>>>>>>> low_profile
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
<<<<<<< HEAD

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Base */
    KC_A,  KC_1,  KC_H, \
      KC_TAB,  KC_SPC   \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
=======
//layer defs
#define _PICK 0
#define _PREM 1
#define _PS 2
#define _KICAD 3
#define _CODE 4
#define _MED 5
#define _MINE 6
#define _OSU 7
#define _MU 8
//keycode defs


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*                          .-------.   .-------.
  .-----------.-----------./>NO      \./>NO      \.
  |           |           ||<NO      |||<NO      ||
  |           |           |\         /|\ Select  /|
  |-----------+-----------+-----------+-----------|
  | Media     | Minecraft | Osu!      | Music     |
  |           |           |           |           |
  |-----------+-----------+-----------+-----------|
  | Premiere  | Photoshop | KiCad     | None      |
  |           |           |           |           |
  `-----------'-----------'-----------'-----------'*/
  [_PICK] = LAYOUT( /* Layer Select */
    KC_NO, KC_NO, KC_NO, KC_TRNS, \
    TO(_MED), TO(_MINE), TO(_OSU), TO(_MU), \
    TO(_PREM), TO(_PS), TO(_KICAD), TO(_CODE) \
  ),
/*                          .-------.   .-------.
  .-----------.-----------./>Right   \./>Up      \.
  | Timeline  | Timeline  ||<Left    |||<Down    ||
  | Select    | Cut       |\ Ctrl+S  /|\ Select  /|
  |-----------+-----------+-----------+-----------|
  | Insert    | Overwrite | Delete    | Enter     |
  |           |           |           |           |
  |-----------+-----------+-----------+-----------|
  | Shift     | Control   | Alt       | Space      |
  |           |           |           |           |
  `-----------'-----------'-----------'-----------'*/
  [_PREM] = LAYOUT( /* Premiere */
    KC_V, KC_C, LCTL(KC_S), TG(_PREM),  \
    KC_COMMA,  KC_DOT,  KC_DELETE, KC_ENTER, \
    KC_LSFT,  KC_LCTL,  KC_LALT, KC_SPACE \
  ),
/*                          .-------.   .-------.
  .-----------.-----------./>Right   \./>Up      \.
  | Selection | Wire      ||<Left    |||<Down    ||
  | Tool      | Tool      |\         /|\ Layers  /|
  |-----------+-----------+-----------+-----------|
  | Shift     | New       | Move      | Delete    |
  |           | Track     |           |           |
  |-----------+-----------+-----------+-----------|
  | Control   |           |           |           |
  |           |           |           |           |
  `-----------'-----------'-----------'-----------'*/
  [_KICAD] = LAYOUT( /* KiCad */
    KC_ESC, KC_W,  KC_C,  TG(_KICAD), \
    KC_LSFT,  KC_X,  KC_M, KC_DEL, \
    KC_LCTL,  KC_I,  KC_J, KC_ENT \
  ),
/*                          .-------.   .-------.
  .-----------.-----------./>Right   \./>Wh Up   \.
  | S         | R         ||<Left    |||<Wh Down ||
  |           |           |\         /|\ Layers  /|
  |-----------+-----------+-----------+-----------|
  | Shift     | E         | F         | G         |
  |           |           |           |           |
  |-----------+-----------+-----------+-----------|
  | Control   | Alt       | Space     | K         |
  |           |           |           |           |
  `-----------'-----------'-----------'-----------'*/
  [_PS] = LAYOUT( /* Photoshop */
    KC_S, KC_R,  KC_C, TG(_PS), \
    KC_RSFT,  KC_E,  KC_F, KC_G, \
    KC_RCTL,  KC_LALT,  KC_SPC, KC_K \
  ),
/*                          .-------.   .-------.
  .-----------.-----------./>PageUp  \./>Up      \.
  | Escape    | Tab       ||<PageDown||/<Down    ||
  |           |           |\ Save    /|\ Layers  /|
  |-----------+-----------+-'-------'-+-----------|
  | RGB       | E         | F         | G         |
  | Hue+      |           |           |           |
  |-----------+-----------+-----------+-----------|
  | RGB       | I         | J         | K         |
  | Hue-      |           |           |           |
  `-----------'-----------'-----------'-----------'*/
  [_CODE] = LAYOUT( /* Coding hotkeys */
    KC_ESC, KC_TAB, LCTL(KC_S), TG(_CODE),  \
    KC_LSFT, KC_LALT, KC_ASTERISK, KC_SLSH, \
    KC_LCTL, KC_LBRACKET, KC_RBRACKET, KC_ENT \
  ),
  /*                          .-------.   .-------.
    .-----------.-----------./>VolUp   \./>MNXT    \.
    | Play      | Stop      ||<VolDown |||<MPRV    ||
    | Pause     |           |\ Player  /|\ Layers  /|
    |-----------+-----------+-----------+-----------|
    | Mute      |           | RGB       | RGB Value |
    |           |           | Toggle    | Increase  |
    |-----------+-----------+-----------+-----------|
    | RGB       |           |           | RGB Value |
    | Hue-      |           |           | Decrease  |
    `-----------'-----------'-----------'-----------'*/
    [_MED] = LAYOUT( /* Media Control */
      KC_MPLY, KC_MSTP,  KC_MEDIA_SELECT, TG(_MED),  \
      KC_AUDIO_MUTE,  KC_NO, RGB_TOG, RGB_VAI, \
      KC_NO, KC_NO, KC_NO, RGB_VAD \
    ),
  /*                          .-------.   .-------.
    .-----------.-----------./>PageUp  \./>Wh Up   \.
    | E         | Tab       ||<PageDown|||<Wh Down ||
    |           |           |\ F3      /|\         /|
    |-----------+-----------+-----------+-----------|
    |           |           |           |           |
    |           |           |           |           |
    |-----------+-----------+-----------+-----------|
    |           |           |           |           |
    |           |           |           |           |
    `-----------'-----------'-----------'-----------'*/
    [_MINE] = LAYOUT( /* Minecraft */
      KC_E, KC_TAB,  KC_F3, TG(_MINE),  \
      KC_NO, KC_NO, KC_NO, KC_NO, \
      KC_NO, KC_NO, KC_NO, KC_NO \
    ),
/*                          .-------.   .-------.
  .-----------.-----------./>PageUp  \./>Wh Up   \.
  | Esc       |           ||<PageDown|||<Wh Down ||
  |           |           |\ F3      /|\         /|
  |-----------+-----------+-----------+-----------|
  |           |           |           |           |
  |           |           |           |           |
  |-----------+-----------+-----------+-----------|
  | G         | H         | J         | K         |
  |           |           |           |           |
  `-----------'-----------'-----------'-----------'*/
  [_OSU] = LAYOUT( /* Osu! */
    KC_ESC, KC_MSTP,  KC_F3, TG(_OSU),  \
    KC_NO, KC_NO, KC_NO, KC_NO, \
    KC_G, KC_H, KC_J, KC_K \
  ),
/*                          .-------.   .-------.
  .-----------.-----------./>PageUp  \./>Wh Up   \.
  | Clicky    | Music     ||<PageDown|||<Wh Down ||
  | Toggle    | On        |\ AU_TOG  /|\         /|
  |-----------+-----------+-----------+-----------|
  | Clicky    | Music     | Audio     |           |
  | Up        | Off       | On        |           |
  |-----------+-----------+-----------+-----------|
  | Clicky    | Clicky    | Audio     |           |
  | Down      | Reset     | Off       |           |
  `-----------'-----------'-----------'-----------'*/
    [_MU] = LAYOUT( /* Audio */
    CK_TOGG, MU_ON, AU_TOG, TG(_MU),  \
    CK_UP, MU_OFF, AU_ON, KC_NO, \
    CK_DOWN, CK_RST, AU_OFF, KC_NO \
  ),
};

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
if (index == 0) {
    switch(biton32(layer_state)) {
      case _PICK:
        clockwise ? tap_code(KC_NO) : tap_code(KC_NO);
        break;
      case _CODE:
        clockwise ? tap_code(KC_PGUP) : tap_code(KC_PGDN);
        break;
      case _MED:
        clockwise ? tap_code(KC_AUDIO_VOL_UP) : tap_code(KC_AUDIO_VOL_DOWN);
        break;
      case _MU:
        clockwise ? tap_code(KC_NO) : tap_code(KC_NO);
        break;
      default:
        clockwise ? tap_code(KC_UP) : tap_code(KC_DOWN);
        break;
      }
  }
else if (index == 1) {
    switch(biton32(layer_state)) {
      case _PICK:
        clockwise ? tap_code(KC_NO) : tap_code(KC_NO);
        break;
      case _CODE:
        clockwise ? tap_code(KC_UP) : tap_code(KC_DOWN);
        break;
      case _MED:
        clockwise ? tap_code(KC_MEDIA_NEXT_TRACK) : tap_code(KC_MEDIA_PREV_TRACK);
        break;
      case _PS:
        clockwise ? tap_code(KC_MS_WH_UP) : tap_code(KC_MS_WH_DOWN);
        break;
      case _MU:
        clockwise ? tap_code(KC_NO) : tap_code(KC_NO);
        break;
      default:
        clockwise ? tap_code(KC_RIGHT) : tap_code(KC_LEFT);
        break;
      }
    }
}
#endif // ENCODER_ENABLE

#ifdef RGBLIGHT_ENABLE
uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case _PICK:
        rgblight_sethsv_range (0,30,70,0,7);
        break;
    case _PREM:
        rgblight_sethsv_at (50,255,255,0);
        break;
    case _PS:
        rgblight_sethsv_at (100,180,255,1);
        break;
    case _KICAD:
        rgblight_sethsv_at (150,180,255,2);
        break;
    case _CODE:
        rgblight_sethsv_at (200,255,255,3);
        break;
    case _MED:
        rgblight_sethsv_at (250,255,255,4);
        break;
    case _MINE:
        rgblight_sethsv_at (120,255,150,5);
        break;
    case _OSU:
        rgblight_sethsv_at (300,255,255,6);
        break;
    case _MU:
        rgblight_sethsv_range (270,230,255,0,2);
        break;
    default: //  for any other layers, or the default layer
        rgblight_sethsv (0,0,100);
        break;
    }
  return state;
}
#endif //RGBLIGHT_ENABLE
>>>>>>> low_profile
