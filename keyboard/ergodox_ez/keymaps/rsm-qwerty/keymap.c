#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define L1 1 // symbols/F-keys/media
#define L2 2 // Layer 2
#define L3 3 // Layer 3
#define L4 4 // Layer 4
#define L5 5 // Layer 5
#define L6 6 // Layer 6
#define L7 7 // Layer 7
#define L8 8 // Layer 8
#define L9 9 // Layer 9

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   Grv  |   1  |   2  |   3  |   4  |   5  | INS  |           |   =  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Caps   |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L3  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|  L2  |           |  L4  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  Esc | LAlt | LGui | LCtl |  Del |                                       | RCtl | RGui | RAlt |   [  |   ]  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Home |  End |       | Right|  Left  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | PgUp |       |  Up  |        |      |
 *                                 | Space|Backsp|------|       |------|  Enter |Space |
 *                                 |      |ace   | PgDn |       | Down |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,         KC_1,         KC_2,       KC_3,     KC_4,     KC_5,       KC_INS,
        KC_CAPS,        KC_Q,         KC_W,       KC_E,     KC_R,     KC_T,       KC_FN1,
        KC_TAB,         KC_A,         KC_S,       KC_D,     KC_F,     KC_G,
        KC_LSFT,        KC_Z,         KC_X,       KC_C,     KC_V,     KC_B,       TG(L2),
        KC_ESC,         KC_LALT,      KC_LGUI,    KC_LCTL,  KC_DEL,
                                                                      KC_HOME,    KC_END,
                                                                                  KC_PGUP,
                                                            KC_SPC,   KC_BSPC,    KC_PGDN,
        // right hand
        KC_EQL,         KC_6,         KC_7,       KC_8,     KC_9,     KC_0,       KC_MINS,
        TG(L3),         KC_Y,         KC_U,       KC_I,     KC_O,     KC_P,       KC_BSLS,
                        KC_H,         KC_J,       KC_K,     KC_L,     KC_SCLN,    KC_QUOT,
        TG(L4),         KC_N,         KC_M,       KC_COMM,  KC_DOT,   KC_SLSH,    KC_RSFT,
                                      KC_RCTL,    KC_RGUI,  KC_RALT,  KC_LBRC,    KC_RBRC,
        KC_LEFT,        KC_RGHT,
        KC_UP,
        KC_DOWN,        KC_ENT,       KC_SPC
    ),
/* Keymap 1: L1ol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// L1 = F-KEYS & NUM PAD
[L1] = KEYMAP(
       // left hand
       KC_NO  ,KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
       KC_NO  ,KC_F1  ,KC_F2,  KC_F3  ,KC_F4  ,KC_SLCK,KC_TRNS,
       KC_NO  ,KC_F5  ,KC_F6,  KC_F7  ,KC_F8  ,KC_PSCR,
       KC_NO  ,KC_F9  ,KC_F10, KC_F11 ,KC_F12 ,KC_BRK ,TG(L5),
       KC_TRNS,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,
                                       KC_NO  ,KC_VOLU,
                                               KC_MUTE,
                               KC_NO  ,KC_NO  ,KC_VOLD,
       // right hand
       KC_NO  , KC_NO  , KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_BRK ,
       TG(L6) , KC_NO  , KC_P7  , KC_P8  , KC_P9  , KC_PLUS, KC_SLCK,
                KC_NO  , KC_P4  , KC_P5  , KC_P6  , KC_PLUS, KC_PSCR,
       TG(L7) , KC_NO  , KC_P1  , KC_P2  , KC_P3  , KC_PENT, KC_NO  ,
                         KC_P0  , KC_P0  , KC_PDOT, KC_PENT, KC_NO  ,
       KC_MRWD, KC_MFFD,
       KC_MPRV,
       KC_MNXT, KC_MSTP, KC_MPLY
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Layer 2
[L2] = KEYMAP(
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_TRNS,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                                           KC_NO  , KC_NO  ,
                                                    KC_NO  ,
                                  KC_NO  , KC_NO  , KC_NO  ,
    // right hand
       KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                 KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                          KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  ,
       KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  
),


// Layer 3
[L3] = KEYMAP(
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                                           KC_NO  , KC_NO  ,
                                                    KC_NO  ,
                                  KC_NO  , KC_NO  , KC_NO  ,
    // right hand
       KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_TRNS,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                 KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                          KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  ,
       KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  
),


// Layer 4
[L4] = KEYMAP(
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                                           KC_NO  , KC_NO  ,
                                                    KC_NO  ,
                                  KC_NO  , KC_NO  , KC_NO  ,
    // right hand
       KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                 KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_TRNS,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                          KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  ,
       KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  
),


// Layer 5
[L5] = KEYMAP(
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_TRNS  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                                           KC_NO  , KC_NO  ,
                                                    KC_NO  ,
                                  KC_NO  , KC_NO  , KC_NO  ,
    // right hand
       KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       TG(L8) ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                 KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                          KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  ,
       KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  
),


// Layer 6
[L6] = KEYMAP(
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                                           KC_NO  , KC_NO  ,
                                                    KC_NO  ,
                                  KC_NO  , KC_NO  , KC_NO  ,
    // right hand
       KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_TRNS,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                 KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                          KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  ,
       KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  
),


// Layer 7
[L7] = KEYMAP(
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                                           KC_NO  , KC_NO  ,
                                                    KC_NO  ,
                                  KC_NO  , KC_NO  , KC_NO  ,
    // right hand
       KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                 KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_TRNS,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                          KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  ,
       KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  
),


// Layer 8
[L8] = KEYMAP(
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                                           KC_NO  , KC_NO  ,
                                                    KC_NO  ,
                                  KC_NO  , KC_NO  , KC_NO  ,
    // right hand
       KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_TRNS,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                 KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       TG(L9) ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                          KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  ,
       KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  
),


// Layer 9
[L9] = KEYMAP(
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                                           KC_NO  , KC_NO  ,
                                                    KC_NO  ,
                                  KC_NO  , KC_NO  , KC_NO  ,
    // right hand
       KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                 KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_TRNS,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                          KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  ,
       KC_NO  ,
       KC_NO  , KC_NO  , RESET  
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(L1),                // FN1 - Momentary Layer 1
    [2] = ACTION_LAYER_TAP_TOGGLE(L2),                // FN1 - Momentary Layer 2
    [3] = ACTION_LAYER_TAP_TOGGLE(L3),                // FN1 - Momentary Layer 3
    [4] = ACTION_LAYER_TAP_TOGGLE(L4),                // FN1 - Momentary Layer 4
    [5] = ACTION_LAYER_TAP_TOGGLE(L5),                // FN1 - Momentary Layer 5
    [6] = ACTION_LAYER_TAP_TOGGLE(L6),                // FN1 - Momentary Layer 6
    [7] = ACTION_LAYER_TAP_TOGGLE(L7),                // FN1 - Momentary Layer 7
    [8] = ACTION_LAYER_TAP_TOGGLE(L8),                // FN1 - Momentary Layer 8
    [9] = ACTION_LAYER_TAP_TOGGLE(L9),                // FN1 - Momentary Layer 9
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    ergodox_led_all_set(LED_BRIGHTNESS_LO);
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 4:
            ergodox_right_led_3_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 8:
            //ergodox_blink_all_leds();
            ergodox_led_all_set(LED_BRIGHTNESS_HI);
            ergodox_right_led_1_on();
            break;
        case 9:    
            ergodox_led_all_set(LED_BRIGHTNESS_HI);
            ergodox_led_all_on();
            break;
        default:
            // none
            break;
    }

};

