#ifndef EFFECTS_EFFECT_MANAGER_H
#define EFFECTS_EFFECT_MANAGER_H

#include "effects/delay.h"
#include "effects/reverb.h"
#include "effects/chorus.h"

class EffectManager {
public:
    static DelayEffect delay;
    static ReverbEffect reverb;
    static ChorusEffect chorus;

    static void init();
    static void applySettings();
    static void resetToDefaults();
    
    // Footswitch Toggles
    static void toggleDelay();
    static void toggleReverb();
    static void toggleChorus();
};

#endif // EFFECTS_EFFECT_MANAGER_H