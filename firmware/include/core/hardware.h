#ifndef CORE_HARDWARE_H
#define CORE_HARDWARE_H

#include <Arduino.h>
#include <U8g2lib.h>
#include <Encoder.h>

extern U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2;
extern Encoder myEnc;

extern const int BTN_ENC;
extern const int FS_DELAY;
extern const int FS_REVERB;
extern const int FS_CHORUS;
extern const int buttonPin;
extern const int ledPin;

void initHardware();

#endif // CORE_HARDWARE_H