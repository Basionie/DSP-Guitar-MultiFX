#include <Arduino.h>
#include "core/hardware.h"
#include "core/system.h"
#include "core/scheduler.h"
#include "audio/audio_manager.h"
#include "effects/effect_manager.h"
#include "ui/display.h"
#include "config/constants.h"

void setup() {
    // 1. Start Serial for debugging
    Serial.begin(115200);

    // 2. Initialize low-level hardware (Pins, Encoder, Display)
    initHardware();
    
    // 3. Initialize system interrupts (Footswitches)
    initSystem();

    // 4. Initialize Audio Graph (Memory, I2S, Static Patch Cords)
    AudioManager::init();

    // 5. Initialize Effect wrappers and set default states
    EffectManager::init();

    // 6. Set initial volume and draw the UI
    AudioManager::setSystemVolume(OUTPUT_VOLUME); 
    drawUI(); 

    // 7. Register and enable background tasks
    initScheduler();
}

void loop() {
    // The CriticalTaskScheduler handles all execution.
    // Periodic tasks (Poll, Modulation, UI) run in the background.
    sched.execute(); 
}