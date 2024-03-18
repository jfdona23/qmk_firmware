#include QMK_KEYBOARD_H

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 * 
 * Macros documentation: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_macros.md
 * 
 * SS_TAP() presses and releases a key.
 * SS_DOWN() presses (but does not release) a key.
 * SS_UP() releases a key.
 * SS_DELAY(msecs)
 * 
 * SS_LCTL(string)
 * SS_LSFT(string)
 * SS_LALT(string) or SS_LOPT(string)
 * SS_LGUI(string), SS_LCMD(string) or SS_LWIN(string)
 * SS_RCTL(string)
 * SS_RSFT(string)
 * SS_RALT(string), SS_ROPT(string) or SS_ALGR(string)
 * SS_RGUI(string), SS_RCMD(string) or SS_RWIN(string)
 * 
 */

enum custom_keycodes {
	UPDTHOST = SAFE_RANGE,
	MAC_COPY,
	MAC_PASTE,
	MAC_CUT,
	MAC_LCK,
	MAC_SCRN_CP,
	VSCODE
};

#define ______ KC_TRNS

#define MAC_CMD SS_LGUI(SS_TAP(X_SPC)) \
				SS_DELAY(100) \
				"Terminal" \
				SS_DELAY(100) \
				SS_TAP(X_ENT) \
				SS_DELAY(50) 

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
	switch (keycode) {
		case UPDTHOST:
			if (record->event.pressed) {
				SEND_STRING(
					MAC_CMD
					"sudo curl https://someonewhocares.org/hosts/hosts -o /etc/hosts"
					SS_TAP(X_ENT)
				);
			}
			break;
		case MAC_COPY:
			if (record->event.pressed) {
				SEND_STRING(SS_LGUI(SS_TAP(X_C)));
			}
			break;
		case MAC_PASTE:
			if (record->event.pressed) {
				SEND_STRING(SS_LGUI(SS_TAP(X_V)));
			}
			break;
		case MAC_CUT:
			if (record->event.pressed) {
				SEND_STRING(SS_LGUI(SS_TAP(X_X)));
			}
			break;
		case MAC_LCK:
			if (record->event.pressed) {
				SEND_STRING(SS_LCTL(SS_LGUI("q")));
			}
			break;
		case MAC_SCRN_CP:
			if (record->event.pressed) {
				SEND_STRING(SS_LCTL(SS_LSFT(SS_LGUI("4"))));
			}
			break;
		case VSCODE:
			if (record->event.pressed) {
				SEND_STRING(MAC_CMD "code" SS_TAP(X_ENT));
			}
			break;
		return false;
	}
	return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
		MAC_COPY,		MAC_PASTE,	MAC_CUT,
		KC_VOLD,		KC_MUTE,	KC_VOLU,
		MAC_SCRN_CP,	MAC_LCK,	LT(1,KC_NO)
		),
	[1] = LAYOUT(
		UPDTHOST,	VSCODE,		______,
		______,		______,		______,
		______,		______,		KC_TRNS
		)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
