/* Copyright
 *   2021 solartempest
 *   2021 QMK
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


#include "encoder.c"



//#include "oled.c" //Stock OLED code
//Note that the keyboard animations below take a large amount of space!
//#include "bongocat.c" //OLED code for Bongocat, original code by foureight84.
//#include "luna.c" //OLED code for Luna, original code by Hellsingcoder and adapted by Jackasaur.
#include "snakey.c" //OLED code for Snakey, customized from Luna. If not used, do not use OLED_LOGO in config.h.
//#include "snakey_minimal.c" //OLED code for Snakey, without WPM/related animations to save space. If not used, do not use OLED_LOGO in config.h.



extern rgblight_config_t rgblight_config; // To pull layer status for RGBLIGHT

enum custom_keycodes {
    SV_NMLK
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {  //Can skip these hard-coded layouts to save space when using only VIA (+700).
/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | ] }  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LCTR |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |  ; : | ' "  |
 * |------+------+------+------+------+------|  Enc  |    |  Enc  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |  ,<  |  . > |   /? |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |  \|  |  End | HOME | LGUI | /Enter  /       \Space \  | LAY1 | LAY2 | RAlt |  INS |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
*/
[0] = LAYOUT(
  KC_ESC,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,						  KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	 KC_BSPC,
  KC_TAB,	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,	  					  KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	 KC_LBRC,
  KC_LCTL,	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,					 	  KC_H,	KC_J,	KC_K,	KC_L,	KC_SCLN, KC_QUOT,
  KC_LSFT,	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,	KC_MUTE,	 KC_MPLY, KC_N,	KC_M,	KC_COMM,KC_DOT,	KC_SLSH, KC_RSFT,
					KC_BSLS,KC_END,KC_HOME,KC_LGUI,	KC_ENT,		 KC_SPC,	 MO(1),	MO(2),  KC_RALT,KC_INS
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | `~   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 | DEL  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | F11  |  F12 |      |      |      |                    |   Y  |      |  UP  |  -_  |  =+  |  ]}  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPS |   A  |   S  |      |   F  |      |-------.    ,-------|      | LEFT | DOWN | RIGHT|      |      |
 * |------+------+------+------+------+------|  Enc  |    |  Enc  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |      |      |-------|    |-------|      |      |      |      |      |  `~  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | PGDN | PGUP | LCtrl| /Enter  /       \Space \  | XXXX | LAY3 | RAlt |RCtrl |
 *            |      |      |      |      |/       /         \      \ | XXXX |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
*/
[1] = LAYOUT(
  KC_ESC,	KC_F1,	KC_F2,	 KC_F3,	  KC_F4,   KC_F5,						 KC_F6,	  KC_F7,   KC_F8,	KC_F9,	 KC_F10,   KC_DEL,
  KC_TAB,	KC_F11,	KC_F12,	 KC_TRNS, KC_TRNS, KC_TRNS,						 KC_Y,	  KC_TRNS, KC_UP,	KC_MINS, KC_EQL,   KC_RBRC,
  KC_CAPS,	KC_A,	KC_S,	 KC_TRNS, KC_F,	   KC_TRNS,				 		 KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_SCLN,  KC_TRNS,
  KC_LSFT,	KC_Z,	KC_X,	 KC_C,	  KC_TRNS, KC_TRNS, 			KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_GRV,
					KC_LGUI, KC_END, KC_HOME, KC_LCTL, KC_ENT, KC_MUTE,		 KC_SPC,	 KC_TRNS, MO(3),   KC_RALT, KC_RCTL
),
/* RAISE/NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | F13  | F14  | F15  | F16  | F17  | F18  |                    | F19  | F20  | F21  | F22  | F23  | F24  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |      |      |      |      |      |                    |      |   7  |  8   |  9   |      |  ]}  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |   4  |  5   |  6   |   +  |      |
 * |------+------+------+------+------+------|  Enc  |    |  Enc  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   0  |   1  |  2   |  3   |   =  |  `~  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | NMLK |      |      | Space| /Enter  /       \Space \  |      | XXXX | RAlt |RCtrl |
 *            |      |      |      |      |/       /         \      \ |      | XXXX |      |      |
 *            `----------------------------------'           '------''---------------------------'
*/
[2] = LAYOUT(
  KC_F13,	KC_F14,	 KC_F15,  KC_F16,  KC_F17,	KC_F18,						 		 KC_F19,  KC_F20, KC_F21,  KC_F22, KC_F23,	KC_F24,
  KC_TAB,	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,	KC_TRNS,							 KC_TRNS, KC_P7,  KC_P8,   KC_P9,  KC_TRNS,	KC_TRNS,
  KC_TRNS,	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,	KC_TRNS,	 						 KC_TRNS, KC_P4,  KC_P5,   KC_P6,  KC_PLUS,  KC_TRNS,
  KC_TRNS,	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,	KC_TRNS, 					KC_MPLY, KC_P0,	  KC_P1,  KC_P2,   KC_P3,  KC_EQL,	KC_TRNS,
					 SV_NMLK, KC_TRNS, KC_TRNS, KC_SPC,  KC_PENT, KC_MUTE,	KC_SPC,	 KC_TRNS, MO(3),  KC_RALT, KC_RCTL
),
/* RGB
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGBM+ |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGBM- |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|  Enc  |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | NMLK |      |      |      | /RGB_TOG/       \      \  | XXXX | XXXX |      |      |
 *            |      |      |      |      |/       /         \      \ | XXXX | XXXX |      |      |
 *            `----------------------------------'           '------''---------------------------'
*/
[3] = LAYOUT(
  KC_TRNS,	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,	KC_TRNS,						 	 	 KC_TRNS, KC_TRNS, KC_TRNS,	KC_TRNS, KC_TRNS, KC_TRNS,
  RGB_MOD,	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,	KC_TRNS,						 	 	 KC_TRNS, KC_TRNS, KC_TRNS,	KC_TRNS, KC_TRNS, KC_TRNS,
  RGB_RMOD,	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,	KC_TRNS,						 	 	 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,	KC_TRNS, 						KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
					 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG, KC_MUTE,		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)
};

void matrix_scan_user(void) {
	encoder_action_unregister();
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	#if defined(KEYBOARD_PET) || defined(OLED_LOGO)
		if (record->event.pressed) { //OLED timeout code
			oled_timer = timer_read32();
		}
	#endif
	uint8_t layernumby = 2;
	switch (keycode) { //For keycode overrides
		case SV_NMLK:
			
            if (record->event.pressed) {
                register_code(KC_NUM);  // press the numlock key
                register_code(TG(layernumby));          // toggle to layer 3
            } else {
                unregister_code(KC_NUM);  // release the num lock key
				unregister_code(TG(layernumby));
            }
            break;
		#ifdef KEYBOARD_PET // KEYBOARD PET STATUS
			case KC_LCTL:
			case KC_RCTL:
				#ifndef SNEAK_DISABLE
				if (record->event.pressed) { //Pet sneaks when control held.
					isSneaking = true;
				} else {
					isSneaking = false;
				}
				#endif
				return true;
			case KC_SPC:
				if (record->event.pressed) { //Pet jumps when enter is pressed.
					isJumping = true;
					showedJump = false;
				} else {
					isJumping = false;
				}
				return true;
		#endif
		}
	return true;
}


	layer_state_t layer_state_set_user(layer_state_t state)	//Use for layer lighting. This method uses less space than RGBLIGHT_LAYER_SEGMENTS.
	{
		switch (get_highest_layer(state)) { // Change all other LEDs based on layer state as well
			case 0:
				//rgblight_sethsv_noeeprom(50,255,80);	//green-blue gradient
				rgblight_sethsv_noeeprom(115,170,80);	//pale blue gradient
				break;
			case 1:
				rgblight_sethsv_noeeprom(160,255,80);	//blue-magenta gradient
				break;
			case 2:
				rgblight_sethsv_noeeprom(80,255,80);
				break;
			case 3:
				//rgblight_sethsv_noeeprom(118,255,80);	//blue-purple gradient
				rgblight_sethsv_noeeprom(252,255,80);
				break;
		  }
		return state;
	}
	
	bool led_update_user(led_t led_state)	//Lock key status indicators
	{
		if(led_state.caps_lock){
			rgblight_sethsv_range(43,100,170, 28,31); //White-left caps lock indication
		}
		 if(led_state.num_lock){
		 	rgblight_sethsv_range(43,100,170, 4,7); //White-right num lock indication. Since this indicator is inverted, it must be on the master side of the keyboard to shut off properly when the computer is sleeping.
		 }
		// if(led_state.scroll_lock){
		// 	rgblight_sethsv_range(43,100,170, 16,19); //White-middle scroll lock indication
		// }
		return true;
	}


void keyboard_post_init_user(void)
{
	rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT+8); //Set to static gradient 9
	
	layer_move(0); 						//Start on layer0 by default to set LED colours. Can remove to save a very small amount of space.
}