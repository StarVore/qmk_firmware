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



static uint8_t  encoder_state[2] = {0};
static keypos_t encoder_ccw[2] = {{6, 3}, {6, 8}}; //Use these keymap positions to specify the encoder functions on rotate.
static keypos_t encoder_cw[2] = {{6, 1}, {6, 6}};

void encoder_action_unregister(void) {
	for (int index = 0; index < 2; ++index) {
		if (encoder_state[index]) {
			keyevent_t encoder_event = (keyevent_t){.key = encoder_state[index] >> 1 ? encoder_cw[index] : encoder_ccw[index], .pressed = false, .time = (timer_read() | 1)};
			encoder_state[index] = 0;
			action_exec(encoder_event);
		}
	}
}

void encoder_action_register(uint8_t index, bool clockwise) {
	keyevent_t encoder_event = (keyevent_t){.key = clockwise ? encoder_cw[index] : encoder_ccw[index], .pressed = true, .time = (timer_read() | 1)};
	encoder_state[index] = (clockwise ^ 1) | (clockwise << 1);
	action_exec(encoder_event);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
	encoder_action_register(index, clockwise);
	return false;
};


// bool encoder_update_user(uint8_t index, bool clockwise) {
//     if (index == 0) {
//         switch (get_highest_layer(layer_state)) {
//             case 0:
//                 if (clockwise) {
// 					tap_code(KC_UP);
//                     break;
// 				} else {
// 					tap_code(KC_DOWN);
//                     break;
// 				}
// 				break;
//             case 1:
//                 if (clockwise) {
//                     tap_code(KC_VOLU);
//                     break;
//                 } else {
//                     tap_code(KC_VOLD);
//                     break;
//                 }
//                 break;
//             case 2:
//                 if (clockwise) {
// 					tap_code(KC_WH_D);
//                     break;
// 				} else {
// 					tap_code(KC_WH_U);
//                     break;
// 				}
// 				break;
//         }

// 	} else if (index == 1) {
// 	    switch (get_highest_layer(layer_state)) {
// 			case 0:
// 				if (clockwise) {
// 					tap_code(KC_LEFT);
//                     break;
// 				} else {
// 					tap_code(KC_RGHT);
//                     break;
// 				}
// 				break;
// 		}
//     }
//     return true;
// }

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
     [0] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),          ENCODER_CCW_CW(KC_UP, KC_DOWN) },
     [1] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD),           ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
	 [2] = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D),           ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
	 [3] = { ENCODER_CCW_CW(RGB_VAI, RGB_VAD),           ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
};
#endif