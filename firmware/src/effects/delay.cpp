#include "effects/delay.h"
#include "audio/audio_graph.h"
#include "audio/mixer.h"
#include "dsp/parameters.h"

DelayEffect::DelayEffect() : enabled(false) {}

void DelayEffect::setEnabled(bool state) {
    enabled = state;
    updateParameters();
}

bool DelayEffect::isEnabled() const {
    return enabled;
}

void DelayEffect::updateParameters() {
    AudioGraph::delay1.delay(0, currentDelayParams.time_ms);
    Mixer::updateDelayInput(enabled, currentDelayParams.feedback);
}

void DelayEffect::updateModulation(float mod_ms) {
    if (enabled) {
        int dynamicDelay = (int)(currentDelayParams.time_ms + mod_ms);
        if (dynamicDelay < 1) dynamicDelay = 1;
        AudioGraph::delay1.delay(0, dynamicDelay);
    }
}