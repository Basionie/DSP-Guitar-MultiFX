#ifndef EFFECTS_IEFFECT_H
#define EFFECTS_IEFFECT_H

class IEffect {
public:
    virtual ~IEffect() = default;
    virtual void setEnabled(bool state) = 0;
    virtual bool isEnabled() const = 0;
    virtual void updateParameters() = 0;
};

#endif // EFFECTS_IEFFECT_H