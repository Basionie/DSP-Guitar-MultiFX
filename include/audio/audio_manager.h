#ifndef AUDIO_MANAGER_H
#define AUDIO_MANAGER_H

namespace AudioManager {
    void init();
    void setSystemVolume(float volume);
    void setupStaticRouting(); // Handles pre-filters and final output mixing
}

#endif // AUDIO_MANAGER_H