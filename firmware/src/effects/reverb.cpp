#include "effects/reverb.h"
#include "audio/audio_graph.h"
#include "dsp/parameters.h"

ReverbEffect::ReverbEffect() : enabled(false) {}

void ReverbEffect::setEnabled(bool state) {
    enabled = state;
    updateParameters();
}

bool ReverbEffect::isEnabled() const {
    return enabled;
}

void ReverbEffect::updateParameters() {
    AudioGraph::reverb1.roomsize(currentReverbParams.room_size);
    AudioGraph::reverb1.damping(currentReverbParams.damping);
}