#ifndef EFFECTS_DELAY_H
#define EFFECTS_DELAY_H

#include "effects/ieffect.h"

class DelayEffect : public IEffect {
public:
    DelayEffect();
    void setEnabled(bool state) override;
    bool isEnabled() const override;
    void updateParameters() override;
    void updateModulation(float mod_ms); // Special method for LFO updates
private:
    bool enabled;
};

#endif // EFFECTS_DELAY_H