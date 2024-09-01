// ===================================================================================
// Macro Functions which associate Actions with Events (Customize your MacroPad here!)
// ===================================================================================
/*
// The list of available USB HID functions can be found in src/usb_composite.h
// The keys are enumerated the following way:
// +---+---+---+    -----
// | 3 | 2 | 1 |  /       \
// +---+---+---+  |encoder|
// | 4 | 5 | 6 |  \       /
// +---+---+---+    -----
*/

// Key 1 example -> mouse wheel up (scroll page)
// ---------------------------------------------

// Define action(s) if key1 was pressed
static inline void KEY1_PRESSED() {
                                                      // nothing to do
}

// Define action(s) if key1 was released
static inline void KEY1_RELEASED() {
                                                      // nothing to do
}

// Define action(s) when key1 is held
static inline void KEY1_HOLD() {
  MOUSE_wheel_up();                                   // turn mouse wheel up
  DLY_ms(10);                                         // delay
}

// Key 2 example -> ALT + TAB (switch application)
// -----------------------------------------------

// Define action(s) if key2 was pressed
static inline void KEY2_PRESSED() {
  KBD_press(KBD_KEY_LEFT_ALT);                        // press left ALT key
}

// Define action(s) if key2 was released
static inline void KEY2_RELEASED() {
  KBD_release(KBD_KEY_LEFT_ALT);                      // release left ALT key
}

// Define action(s) when key2 is held
static inline void KEY2_HOLD() {
  KBD_type(KBD_KEY_TAB);                              // press and release TAB key
  DLY_ms(500);                                        // delay
}

// Key 3 example -> WIN + DOWN ARROW (show apps)
// ---------------------------------------------

// Define action(s) if key3 was pressed
static inline void KEY3_PRESSED() {
  KBD_press(KBD_KEY_LEFT_GUI);                        // press left WIN key
  KBD_press(KBD_KEY_DOWN_ARROW);                      // press DOWN ARROW key
}

// Define action(s) if key3 was released
static inline void KEY3_RELEASED() {
  KBD_release(KBD_KEY_DOWN_ARROW);                    // release DOWN ARROW key
  KBD_release(KBD_KEY_LEFT_GUI);                      // release left WIN key
}

// Define action(s) when key3 is held
static inline void KEY3_HOLD() {
                                                      // nothing to do
}

// Key 4 example -> CTRL + ALT + DEL (shutdown)
// --------------------------------------------

// Define action(s) if key4 was pressed
static inline void KEY4_PRESSED() {
  KBD_press(KBD_KEY_LEFT_CTRL);                       // press left CTRL key
  KBD_press(KBD_KEY_LEFT_ALT);                        // press left ALT key
  KBD_press(KBD_KEY_DELETE);                          // press DEL key
}

// Define action(s) if key4 was released
static inline void KEY4_RELEASED() {
  KBD_release(KBD_KEY_DELETE);                        // release DEL key
  KBD_release(KBD_KEY_LEFT_ALT);                      // release left ALT key
  KBD_release(KBD_KEY_LEFT_CTRL);                     // release left CTRL key
}

// Define action(s) when key4 is held
static inline void KEY4_HOLD() {
                                                      // nothing to do
}

// Key 5 example -> Linux open terminal and run shutdown command
// -------------------------------------------------------------

// Define action(s) if key5 was pressed
static inline void KEY5_PRESSED() {
  KBD_press(KBD_KEY_LEFT_GUI);                        // press left WIN key
  KBD_type('t');                                      // press and release 'T' key
  DLY_ms(500);                                        // wait for terminal to open
  KBD_release(KBD_KEY_LEFT_GUI);                      // release left WIN key
  KBD_print("sudo shutdown -h now");                  // type shutdown command
  KBD_type(KBD_KEY_RETURN);                           // press and release RETURN key
}

// Define action(s) if key5 was released
static inline void KEY5_RELEASED() {
                                                      // nothing to do
}

// Define action(s) when key5 is held
static inline void KEY5_HOLD() {
                                                      // nothing to do
}

// Key 6 example -> mouse wheel down (scroll page)
// -----------------------------------------------

// Define action(s) if key6 was pressed
static inline void KEY6_PRESSED() {
                                                      // nothing to do
}

// Define action(s) if key6 was released
static inline void KEY6_RELEASED() {
                                                      // nothing to do
}

// Define action(s) when key6 is held
static inline void KEY6_HOLD() {
  MOUSE_wheel_down();                                 // turn mouse wheel down
  DLY_ms(10);                                         // delay
}

// Rotary encoder example -> volume control knob
// ---------------------------------------------

// Define action(s) if encoder was rotated clockwise
static inline void ENC_CW_ACTION() {
  CON_press(CON_VOL_UP);                              // press VOLUME UP key
}

// Define action(s) after encoder was rotated clockwise
static inline void ENC_CW_RELEASED() {
  CON_release();                                      // release VOLUME UP KEY
}

// Define action(s) if encoder was rotated counter-clockwise
static inline void ENC_CCW_ACTION() {
  CON_press(CON_VOL_DOWN);                            // press VOLUME DOWN key
}

// Define action(s) after encoder was rotated counter-clockwise
static inline void ENC_CCW_RELEASED() {
  CON_release();                                      // release VOLUME DOWN KEY
}

// Define action(s) if encoder switch was pressed
static inline void ENC_SW_PRESSED() {
  CON_press(CON_VOL_MUTE);                            // press VOLUME MUTE key
}

// Define action(s) if encoder switch was released
static inline void ENC_SW_RELEASED() {
  CON_release();                                      // release VOLUME MUTE key
}

// ===================================================================================
// NeoPixel Configuration
// ===================================================================================

// Global NeoPixel brightness
#define NEO_BRIGHT_KEYS   2         // NeoPixel brightness for keys (0..2)
#define NEO_BRIGHT_ENC    0         // NeoPixel brightness for encoder ring (0..2)

// Key colors (hue value: 0..191)
#define NEO_KEY1          0         // red
#define NEO_KEY2          32        // yellow
#define NEO_KEY3          64        // green
#define NEO_KEY4          96        // cyan
#define NEO_KEY5          128       // blue
#define NEO_KEY6          160       // magenta
