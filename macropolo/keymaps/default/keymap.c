/* Copyright 2019 mythosmann
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

#define _PICK 0
#define _PREM 1
#define _PS 2
#define _KICAD 3
#define _NONE 4



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*.-----------.-----------.-----------.-----------.
  |           |           |/         \|/ Layer   \|
  |           |           |\         /|\ Select  /|
  |-----------+-----------+-----------+-----------|
  |           |           |           |           |
  |           |           |           |           |
  |-----------+-----------+-----------+-----------|
  | Premiere  | Photoshop | KiCad     | None      |
  |           |           |           |           |
  `-----------'-----------'-----------'-----------'*/
  [_PICK] = LAYOUT( /* Layer Select */
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
    DF(_PREM), DF(_PS), DF(_KICAD), DF(_NONE) \
  ),
/*.-----------.-----------.-----------.-----------.
  | Timeline  | Timeline  |/ Save    \|/ Layer   \|
  | Select    | Cut       |\ Ctrl+S  /|\ Select  /|
  |-----------+-----------+-----------+-----------|
  | Insert    | Overwrite | Delete    | Enter     |
  |           |           |           |           |
  |-----------+-----------+-----------+-----------|
  | Shift     | Control   | Alt       | Space      |
  |           |           |           |           |
  `-----------'-----------'-----------'-----------'*/
  [_PREM] = LAYOUT( /* Premiere */
    KC_V,  KC_C,  LCTL(KC_S), DF(_PICK), \
    KC_COMMA,  KC_DOT,  KC_DELETE, KC_ENTER, \
    KC_LSFT,  KC_LCTL,  KC_LALT, KC_SPACE \
  ),
/*.-----------.-----------.-----------.-----------.
  | Selection | Wire      |/         \|/ Layer   \|
  | Tool      | Tool      |\         /|\ Select  /|
  |-----------+-----------+-----------+-----------|
  | Shift     | New       | Move      | Delete    |
  |           | Track     |           |           |
  |-----------+-----------+-----------+-----------|
  | Control   |           |           |           |
  |           |           |           |           |
  `-----------'-----------'-----------'-----------'*/
  [_KICAD] = LAYOUT( /* KiCad */
    KC_ESC,  KC_W,  KC_C, DF(_PICK), \
    KC_LSFT,  KC_X,  KC_M, KC_DEL, \
    KC_LCTL,  KC_I,  KC_J, KC_K \
  ),
/*.-----------.-----------.-----------.-----------.
  | S         | R         |/ C       \|/ Layer   \|
  |           |           |\         /|\ Select  /|
  |-----------+-----------+-----------+-----------|
  | Shift     | E         | F         | G         |
  |           |           |           |           |
  |-----------+-----------+-----------+-----------|
  | Control   | Alt       | Space     | K         |
  |           |           |           |           |
  `-----------'-----------'-----------'-----------'*/
  [_PS] = LAYOUT( /* Photoshop */
    KC_S,  KC_R,  KC_C, DF(_PICK), \
    KC_RSFT,  KC_E,  KC_F, KC_G, \
    KC_RCTL,  KC_LALT,  KC_SPC, KC_K \
  ),
/*.-----------.-----------.-----------.-----------.
  | A         | B         |/ C       \|/ Layer   \|
  |           |           |\         /|\ Select  /|
  |-----------+-----------+-----------+-----------|
  | D         | E         | F         | G         |
  |           |           |           |           |
  |-----------+-----------+-----------+-----------|
  | H         | I         | J         | K         |
  |           |           |           |           |
  `-----------'-----------'-----------'-----------'*/
  [_NONE] = LAYOUT( /* Useless */
    KC_A,  KC_B,  KC_C, DF(_PICK), \
    KC_D,  KC_E,  KC_F, KC_G, \
    KC_H,  KC_I,  KC_J, KC_K \
  ),
};

// void encoder_update_user(uint8_t index, bool clockwise) {
//   if (index == 0) { /* First encoder */
//     if (clockwise) {
//       tap_code(KC_UP);
//     } else {
//       tap_code(KC_DOWN);
//     }
//   } else if (index == 1) {
//     if (clockwise) {
//       tap_code(KC_RIGHT);
//     } else {
//       tap_code(KC_LEFT);
//     }
//   }
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
      switch(biton32(layer_state)) {
      case _NONE:
        if (clockwise) {
          tap_code(KC_MS_U);
        } else {
          tap_code(KC_MS_D);
        }
        break;
      default:
        if (clockwise) {
          tap_code(KC_UP);
        } else {
          tap_code(KC_DOWN);
        }
        break;
      }
  } else if (index == 1) {
      switch(biton32(layer_state)) {
      case _NONE:
        if (clockwise) {
          tap_code(KC_MS_R);
        } else {
          tap_code(KC_MS_L);
        }
        break;
      default:
        if (clockwise) {
          tap_code(KC_RGHT);
        } else {
          tap_code(KC_LEFT);
        }
        break;
      }
    }
  }
