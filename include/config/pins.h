#ifndef CORE_PINS_H
#define CORE_PINS_H

// Display Pins (I2C)
constexpr int PIN_I2C_SDA = 25;
constexpr int PIN_I2C_SCL = 24;

// Rotary Encoder Pins
constexpr int PIN_ENC_A   = 31;
constexpr int PIN_ENC_B   = 32;
constexpr int PIN_BTN_ENC = 30;

// Footswitch Pins
constexpr int PIN_FS_DELAY  = 34;
constexpr int PIN_FS_REVERB = 33;
constexpr int PIN_FS_CHORUS = 35;

// System Master Pins
constexpr int PIN_SYS_BTN = 36;
constexpr int PIN_SYS_LED = 37;

#endif // CORE_PINS_H