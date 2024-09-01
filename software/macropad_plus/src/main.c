// ===================================================================================
// Project:   MacroPad Plus for CH32V003
// Version:   v1.0
// Year:      2024
// Author:    Stefan Wagner
// Github:    https://github.com/wagiminator
// EasyEDA:   https://easyeda.com/wagiminator
// License:   http://creativecommons.org/licenses/by-sa/3.0/
// ===================================================================================
//
// Description:
// ------------
// Firmware example implementation for the MacroPad Plus.
//
// References:
// -----------
// - CNLohr ch32v003fun: https://github.com/cnlohr/ch32v003fun
// - WCH Nanjing Qinheng Microelectronics: http://wch.cn
//
// Compilation Instructions:
// -------------------------
// - Make sure GCC toolchain (gcc-riscv64-unknown-elf, newlib) and Python3 with
//   rvprog (via pip) are installed. In addition, Linux requires access rights to
//   WCH-LinkE programmer.
// - Connect the WCH-LinkE programmer to the MCU board.
// - Run 'make flash'.
//
// Operating Instructions:
// -----------------------
// - Connect the board via USB to your PC. It should be detected as a HID device with
//   keyboard and mouse interface.
// - Press a macro key or turn the knob and see what happens.


// ===================================================================================
// Libraries, Definitions and Macros
// ===================================================================================
#include <config.h>                               // user configurations
#include <system.h>                               // system functions
#include <gpio.h>                                 // GPIO functions
#include <neo_spi.h>                              // NeoPixel fuctions
#include <encoder_tim.h>                          // rotary encoder functions
#include <usb_composite.h>                        // USB HID composite functions
#include <macros.h>                               // user defined macros

// ===================================================================================
// NeoPixel Functions
// ===================================================================================

uint8_t neoencoder = 0;                           // state of NeoPixel ring rotation

// Update NeoPixel ring colors
void NEO_encoder_update(void) {
  uint8_t i, j;
  j = neoencoder;
  for(i=6; i<18; i++) {
    NEO_writeHue(i, j, NEO_BRIGHT_ENC);
    j += 16;
    if(j >= 192) j -= 192;
  }
  NEO_update();
}

// Rotate NeoPixel ring clockwise
void NEO_encoder_cw(void) {
  neoencoder += 8;
  if(neoencoder >= 192) neoencoder -= 192;
  NEO_encoder_update();
}

// Rotate NeoPixel ring counter-clockwise
void NEO_encoder_ccw(void) {
  neoencoder -= 8;
  if(neoencoder >= 192) neoencoder -= 64;
  NEO_encoder_update();
}

// ===================================================================================
// Main Function
// ===================================================================================
int main(void) {
  // Variables
  uint8_t key1last = 0;                           // last state of key 1
  uint8_t key2last = 0;                           // last state of key 2
  uint8_t key3last = 0;                           // last state of key 3
  uint8_t key4last = 0;                           // last state of key 4
  uint8_t key5last = 0;                           // last state of key 5
  uint8_t key6last = 0;                           // last state of key 6
  uint8_t isSwitchPressed = 0;                    // state of rotary encoder switch

  // Setup pins for keys and encoder
  PIN_input_PU(PIN_KEY1);
  PIN_input_PU(PIN_KEY2);
  PIN_input_PU(PIN_KEY3);
  PIN_input_PU(PIN_KEY4);
  PIN_input_PU(PIN_KEY5);
  PIN_input_PU(PIN_KEY6);
  PIN_input_PU(PIN_ENC_SW);
  PIN_input_PU(PIN_ENC_A);
  PIN_input_PU(PIN_ENC_B);

  // Setup NeoPixels
  NEO_init();                                     // init NeoPixels
  NEO_clearAll();                                 // clear NeoPixels

  // Init USB HID device
  HID_init();                                     // init USB HID device
  NEO_encoder_update();                           // set NeoPixel ring for encoder

  // Loop
  while(1) {

    // Handle key 1
    // ------------
    if((!PIN_read(PIN_KEY1)) != key1last) {       // key state changed?
      key1last = !key1last;                       // update last state flag
      if(key1last) {                              // key was pressed?
        NEO_writeHue(0, NEO_KEY1, NEO_BRIGHT_KEYS);    // light up corresponding NeoPixel
        NEO_update();                             // update pixels
        KEY1_PRESSED();                           // take proper action
      }
      else {                                      // key was released?
        NEO_clearPixel(0);                        // light up corresponding NeoPixel
        NEO_update();                             // update pixels
        KEY1_RELEASED();                          // take proper action
      }
    }
    else if(key1last) {                           // key still being pressed?
      KEY1_HOLD();                                // take proper action
    }

    // Handle key 2
    // ------------
    if((!PIN_read(PIN_KEY2)) != key2last) {       // key state changed?
      key2last = !key2last;                       // update last state flag
      if(key2last) {                              // key was pressed?
        NEO_writeHue(1, NEO_KEY2, NEO_BRIGHT_KEYS);    // light up corresponding NeoPixel
        NEO_update();                             // update pixels
        KEY2_PRESSED();                           // take proper action
      }
      else {                                      // key was released?
        NEO_clearPixel(1);                        // light up corresponding NeoPixel
        NEO_update();                             // update pixels
        KEY2_RELEASED();                          // take proper action
      }
    }
    else if(key2last) {                           // key still being pressed?
      KEY2_HOLD();                                // take proper action
    }

    // Handle key 3
    // ------------
    if((!PIN_read(PIN_KEY3)) != key3last) {       // key state changed?
      key3last = !key3last;                       // update last state flag
      if(key3last) {                              // key was pressed?
        NEO_writeHue(2, NEO_KEY3, NEO_BRIGHT_KEYS);    // light up corresponding NeoPixel
        NEO_update();                             // update pixels
        KEY3_PRESSED();                           // take proper action
      }
      else {                                      // key was released?
        NEO_clearPixel(2);                        // light up corresponding NeoPixel
        NEO_update();                             // update pixels
        KEY3_RELEASED();                          // take proper action
      }
    }
    else if(key3last) {                           // key still being pressed?
      KEY3_HOLD();                                // take proper action
    }

    // Handle key 4
    // ------------
    if((!PIN_read(PIN_KEY4)) != key4last) {       // key state changed?
      key4last = !key4last;                       // update last state flag
      if(key4last) {                              // key was pressed?
        NEO_writeHue(3, NEO_KEY4, NEO_BRIGHT_KEYS);    // light up corresponding NeoPixel
        NEO_update();                             // update pixels
        KEY4_PRESSED();                           // take proper action
      }
      else {                                      // key was released?
        NEO_clearPixel(3);                        // light up corresponding NeoPixel
        NEO_update();                             // update pixels
        KEY4_RELEASED();                          // take proper action
      }
    }
    else if(key4last) {                           // key still being pressed?
      KEY4_HOLD();                                // take proper action
    }

    // Handle key 5
    // ------------
    if((!PIN_read(PIN_KEY5)) != key5last) {       // key state changed?
      key5last = !key5last;                       // update last state flag
      if(key5last) {                              // key was pressed?
        NEO_writeHue(4, NEO_KEY5, NEO_BRIGHT_KEYS);    // light up corresponding NeoPixel
        NEO_update();                             // update pixels
        KEY5_PRESSED();                           // take proper action
      }
      else {                                      // key was released?
        NEO_clearPixel(4);                        // light up corresponding NeoPixel
        NEO_update();                             // update pixels
        KEY5_RELEASED();                          // take proper action
      }
    }
    else if(key5last) {                           // key still being pressed?
      KEY5_HOLD();                                // take proper action
    }

    // Handle key 6
    // ------------
    if((!PIN_read(PIN_KEY6)) != key6last) {       // key state changed?
      key6last = !key6last;                       // update last state flag
      if(key6last) {                              // key was pressed?
        NEO_writeHue(5, NEO_KEY6, NEO_BRIGHT_KEYS);    // light up corresponding NeoPixel
        NEO_update();                             // update pixels
        KEY6_PRESSED();                           // take proper action
      }
      else {                                      // key was released?
        NEO_clearPixel(5);                        // light up corresponding NeoPixel
        NEO_update();                             // update pixels
        KEY6_RELEASED();                          // take proper action
      }
    }
    else if(key6last) {                           // key still being pressed?
      KEY6_HOLD();                                // take proper action
    }

    // Handle rotary encoder
    // ---------------------
    if(!PIN_read(PIN_ENC_A)) {                    // encoder turned ?
      if(PIN_read(PIN_ENC_B)) {                   // clockwise ?
        ENC_CW_ACTION();                          // take proper action
        NEO_encoder_cw();                         // rotate NeoPixels
        DLY_ms(5);                                // debounce
        ENC_CW_RELEASED();                        // take proper action
      }
      else {                                      // counter-clockwise ?
        ENC_CCW_ACTION();                         // take proper action
        NEO_encoder_ccw();                        // rotate NeoPixels
        DLY_ms(5);                                // debounce
        ENC_CCW_RELEASED();                       // take proper action
      }
      while(!PIN_read(PIN_ENC_A));                // wait until next detent
    } 
    else {
      if(!isSwitchPressed && !PIN_read(PIN_ENC_SW)) {     // switch previously pressed?
        ENC_SW_PRESSED();                         // take proper action
        isSwitchPressed = 1;
      }
      else if(isSwitchPressed && PIN_read(PIN_ENC_SW)) {  // switch previously released?
        ENC_SW_RELEASED();                        // take proper action
        isSwitchPressed = 0;                      // update switch state
      }
    }

    DLY_ms(1);                                    // debounce
  }
}
