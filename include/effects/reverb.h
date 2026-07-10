#ifndef EFFECTS_REVERB_H
#define EFFECTS_REVERB_H

#include "effects/ieffect.h"

class ReverbEffect : public IEffect {
public:
    ReverbEffect();
    void setEnabled(bool state) override;
    bool isEnabled() const override;
    void updateParameters() override;
private:
    bool enabled;
    const float REVERB_FROM_DELAY_GAIN = 0.6f;
    const float REVERB_FROM_CHORUS_GAIN = 0.5f;
};

#endif // EFFECTS_REVERB_H