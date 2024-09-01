// ===================================================================================
// CH32V003 MacroPad Plus User Configurations
// ===================================================================================

#pragma once

// Pin defines
#define PIN_KEY1            PD0       // connected to key 1 (active low)
#define PIN_KEY2            PD6       // connected to key 2 (active low)
#define PIN_KEY3            PD5       // connected to key 3 (active low)
#define PIN_KEY4            PD4       // connected to key 4 (active low)
#define PIN_KEY5            PD2       // connected to key 5 (active low)
#define PIN_KEY6            PD3       // connected to key 6 (active low)
#define PIN_ENC_A           PC4       // connected to rotary encoder A (do not change!)
#define PIN_ENC_B           PC7       // connected to rotary encoder B (do not change!)
#define PIN_ENC_SW          PC3       // connected to rotary encoder switch
#define PIN_NEO             PC6       // connected to NeoPixels (do not change!)

// USB pin definitions
#define USB_PORT            A         // [A,C,D] GPIO Port to use with D+, D- and DPU
#define USB_PIN_DP          1         // [0-4] GPIO Number for USB D+ Pin
#define USB_PIN_DM          2         // [0-4] GPIO Number for USB D- Pin

// USB configuration descriptor
#define USB_MAX_POWER_mA    50        // max power in mA 

// USB device descriptor
#define USB_VENDOR_ID       0x1209    // VID
#define USB_PRODUCT_ID      0xc003    // PID
#define USB_DEVICE_VERSION  0x0100    // v1.0 (BCD-format)
#define USB_LANGUAGE        0x0409    // US English

// USB string descriptors
#define MANUF_STR           "wagiminator"
#define PROD_STR            "MacroPad Plus"
#define SERIAL_STR          "CH32V003HID"
