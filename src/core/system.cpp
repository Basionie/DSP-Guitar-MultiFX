#include "core/system.h"
#include "core/hardware.h"
#include "config/pins.h"
#include "config/constants.h"
#include "audio/audio_manager.h"
#include "effects/effect_manager.h"
#include "ui/ui.h"


unsigned long lastInterruptTime = 0;

void initSystem() {
    attachInterrupt(digitalPinToInterrupt(PIN_FS_REVERB), isrToggleReverb, FALLING); 
    attachInterrupt(digitalPinToInterrupt(PIN_FS_DELAY), isrToggleDelay, FALLING);   
    attachInterrupt(digitalPinToInterrupt(PIN_FS_CHORUS), isrToggleChorus, FALLING); 
}

void isrToggleReverb() { 
    if (millis() - lastInterruptTime > DEBOUNCE_DELAY_MS) { 
        EffectManager::toggleReverb();
        lastInterruptTime = millis(); 
    } 
}
void isrToggleDelay() { 
    if (millis() - lastInterruptTime > DEBOUNCE_DELAY_MS) { 
        EffectManager::toggleDelay();
        lastInterruptTime = millis(); 
    } 
}
void isrToggleChorus() { 
    if (millis() - lastInterruptTime > DEBOUNCE_DELAY_MS) { 
        EffectManager::toggleChorus();
        lastInterruptTime = millis(); 
    } 
}

void cb_SystemCheck() {
    static bool last_system_state = true;
    bool current_system_state = (digitalRead(PIN_SYS_BTN) == LOW); 

    if (current_system_state != last_system_state) {
        last_system_state = current_system_state;
        if (current_system_state) {
            system_is_on = true;
            digitalWrite(PIN_SYS_LED, HIGH);
            AudioManager::setSystemVolume(OUTPUT_VOLUME); 
            ui_needs_update = true;            
        } else {
            system_is_on = false;
            digitalWrite(PIN_SYS_LED, LOW);
            AudioManager::setSystemVolume(0);             
            u8g2.clearBuffer();
            u8g2.setFont(u8g2_font_7x14_tr);
            u8g2.drawStr(20, 38, "SYSTEM STANDBY");
            u8g2.sendBuffer();
        }
    }
}