/* Ported from the ZMK config (zmk-config-corne).
 * Wired QMK build for the splitkb Aurora Corne on Adafruit KB2040 controllers.
 *
 * Layout is a positional 1:1 port of the ZMK keymap. Things that did not
 * carry over from ZMK:
 *   - studio_unlock : ZMK Studio only, no QMK equivalent -> KC_NO
 *   - all BLE/split-sync tuning from the .conf : irrelevant once wired
 */

#include QMK_KEYBOARD_H

// Matches the ZMK layer indices: LA_DEF=0, LA_NUM=1, LA_SYM=2, LA_NA1=3, LA_FUN=4
enum layers {
    _DEF,
    _NUM,
    _SYM,
    _NA1,
    _FUN,
};

// ZMK macros: m_ptr "->", m_dptr "=>"
enum custom_keycodes {
    M_PTR = SAFE_RANGE,  // ->
    M_DPTR,              // =>
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // base (LA_DEF)
    [_DEF] = LAYOUT_split_3x6_3(
        KC_LCTL, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LCTL,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LALT,
                               KC_LSFT, MO(_NUM), MO(_NA1),   MO(_SYM), KC_SPC,  KC_LSFT
    ),

    // num (LA_NUM)
    [_NUM] = LAYOUT_split_3x6_3(
        _______, KC_EXLM, KC_AT,   KC_HASH,      KC_DLR,       KC_PERC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,
        _______, KC_LCTL, KC_LGUI, KC_LALT,      KC_LSFT,      KC_RALT,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, KC_ENT,  KC_ASTR, LCTL(KC_INS), LSFT(KC_INS), KC_SPC,     KC_CIRC, KC_AMPR, KC_COMM, KC_DOT,  KC_SLSH, _______,
                                   _______, _______, _______,    MO(_FUN), _______, _______
    ),

    // sym (LA_SYM)
    [_SYM] = LAYOUT_split_3x6_3(
        _______, LCTL(LSFT(KC_ESC)), KC_PLUS, KC_LCBR, KC_RCBR, LSFT(KC_F10),   LCTL(LSFT(KC_F)), KC_VOLU, KC_VOLD, XXXXXXX, KC_UP,   _______,
        _______, KC_LT,              KC_UNDS, KC_LPRN, KC_RPRN, KC_GRV,         KC_RALT,          KC_LSFT, KC_LALT, KC_LGUI, KC_LCTL, _______,
        _______, KC_GT,              KC_PAUS, KC_LBRC, KC_RBRC, KC_DQUO,        KC_LEFT,          KC_RGHT, KC_ENT,  M_DPTR,  KC_DOWN, _______,
                                         _______, MO(_FUN), XXXXXXX,    _______, _______, _______
    ),

    // na1 (LA_NA1)
    [_NA1] = LAYOUT_split_3x6_3(
        _______, KC_ESC,     XXXXXXX,    KC_DEL,     KC_BSPC,    CW_TOGG,            KC_PGUP, KC_HOME,    KC_UP,   KC_END,  KC_EQL,  _______,
        _______, KC_LCTL,    KC_LGUI,    KC_LALT,    KC_LSFT,    LGUI(KC_SPC),       KC_PGDN, KC_LEFT,    KC_DOWN, KC_RGHT, KC_MINS, _______,
        _______, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(LSFT(KC_S)),   KC_QUOT, S(KC_NUBS), KC_TILD, M_PTR,   KC_BSLS, _______,
                                         _______, _______, _______,    XXXXXXX, _______, _______
    ),

    // func (LA_FUN)
    [_FUN] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, QK_BOOT,    KC_F1,  KC_F2,  KC_F3,   KC_F4,   KC_F5,   _______,
        _______, KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, XXXXXXX,    KC_F6,  KC_F7,  KC_F8,   KC_F9,   KC_F10,  _______,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,     KC_F11, KC_F12, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                               _______, _______, _______,    _______, _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M_PTR:
            if (record->event.pressed) SEND_STRING("->");
            return false;
        case M_DPTR:
            if (record->event.pressed) SEND_STRING("=>");
            return false;
    }
    return true;
}
