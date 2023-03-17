#include QMK_KEYBOARD_H

// Uses "Example 6: Using tap dance for momentary-layer-switch and layer-toggle keys" on QMK wiki
// Define a type for as many tap dance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP
} qk_td_state_t;

typedef struct {
    bool is_press_action;
    qk_td_state_t state;
} qk_td_tap_t;


// Tap dance declarations
enum {
    EQL_LAYR, // Our custom tap dance key; add any other tap dance keys to this enum 
};

// Declare the functions to be used with your tap dance key(s)

// Function associated with all tap dances
// qk_td_state_t cur_dance(qk_tap_dance_state_t *state);

// Functions associated with individual tap dances
// void ql_finished(qk_tap_dance_state_t *state, void *user_data);
// void ql_reset(qk_tap_dance_state_t *state, void *user_data);






const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Numbers/Base */
    KC_1, XXXXXXX, KC_UP, XXXXXXX,
    KC_1, KC_LEFT, KC_DOWN, KC_RIGHT,
    KC_1, KC_1, KC_1, KC_X,
    KC_CIRC,    KC_LPRN,    KC_RPRN,          KC_SLASH,
    KC_7,       KC_8,       KC_9,             KC_ASTR,
    KC_4,       KC_5,       KC_6,             KC_MINS,
    KC_1,       KC_2,       KC_3,             KC_PLUS,
    KC_0,       KC_DOT,     LSFT(KC_BSPC),    LT(1, KC_ENT) //will need = sign too for google docs etc - make double tap enter and single =
  ),
  [1] = LAYOUT( /* 2nd */
    KC_TRNS, XXXXXXX, KC_TRNS, XXXXXXX,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    _______, _______, _______, _______,
    _______, KC_LBRC, KC_RBRC, QK_BOOT,
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______
  ),
  [2] = LAYOUT( /* alpha */
    _______, XXXXXXX, _______, XXXXXXX,
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______
  ),
};





// Determine the current tap dance state
qk_td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) return TD_DOUBLE_TAP;
    else return TD_UNKNOWN;
}

// Initialize tap structure associated with example tap dance key
static qk_td_tap_t ql_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Functions that control what our tap dance key does
void ql_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_EQL);
            break;
        case TD_SINGLE_HOLD:
            layer_on(1);
            break;
        case TD_DOUBLE_TAP:
            tap_code(KC_ENT);
            break;
        default:
            break;
    }
}

void ql_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (ql_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(1);
    }
    ql_tap_state.state = TD_NONE;
}

// Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
    [EQL_LAYR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset)
};

// Set a long-ish tapping term for tap-dance keys
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return 275;
        default:
            return TAPPING_TERM;
    }
}