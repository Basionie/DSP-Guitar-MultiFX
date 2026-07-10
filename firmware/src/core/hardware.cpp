#include "core/hardware.h"
#include "config/pins.h"

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ PIN_I2C_SCL, /* data=*/ PIN_I2C_SDA, /* reset=*/ U8X8_PIN_NONE);
Encoder myEnc(PIN_ENC_A, PIN_ENC_B);

void initHardware() {
    pinMode(PIN_SYS_BTN, INPUT_PULLUP);
    pinMode(PIN_SYS_LED, OUTPUT);
    pinMode(PIN_BTN_ENC, INPUT_PULLUP);
    pinMode(PIN_FS_DELAY, INPUT_PULLUP);
    pinMode(PIN_FS_REVERB, INPUT_PULLUP);
    pinMode(PIN_FS_CHORUS, INPUT_PULLUP);

    u8g2.begin();
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_7x14_tr);
    u8g2.drawStr(15, 38, "DSP CONTROLLER"); 
    u8g2.sendBuffer();
    delay(1500); 
}