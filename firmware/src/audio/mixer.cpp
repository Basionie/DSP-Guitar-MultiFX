#include "audio/mixer.h"
#include "audio/audio_graph.h"
#include "config/constants.h"

namespace Mixer {
    void init() {
        AudioGraph::finalMixerL.gain(0, FINAL_DRY_GAIN);
        AudioGraph::finalMixerR.gain(0, FINAL_DRY_GAIN);
        AudioGraph::finalMixerL.gain(1, FINAL_WET_GAIN);
        AudioGraph::finalMixerR.gain(1, FINAL_WET_GAIN);
    }

    void updateDelayInput(bool delayOn, float feedback) {
        AudioGraph::delayInputMixer.gain(0, delayOn ? 1.0f : 0.0f);                 
        AudioGraph::delayInputMixer.gain(1, delayOn ? feedback : 0.0f); 
    }

    void updateReverbInput(bool delayOn, bool reverbOn) {
        AudioGraph::reverbInputMixer.gain(0, (delayOn && reverbOn) ? REVERB_FROM_DELAY_GAIN : 0.0f);
        AudioGraph::reverbInputMixer.gain(1, reverbOn ? REVERB_FROM_CHORUS_GAIN : 0.0f);
    }

    void updateWetMix(bool delayOn, float delayWet, bool reverbOn, float reverbWet) {
        AudioGraph::wetMixer.gain(0, delayOn ? delayWet : 0.0f);   
        AudioGraph::wetMixer.gain(1, reverbOn ? reverbWet : 0.0f);
    }
    
    void updateFinalOutput() { } // Handled dynamically in future updates if needed
}