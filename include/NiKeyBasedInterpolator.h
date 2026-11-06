#pragma once

#include "NiInterpolator.h"

class NiAnimationKey;

class NiKeyBasedInterpolator : public NiInterpolator
{
  public:
    NiKeyBasedInterpolator() throw();
    virtual ~NiKeyBasedInterpolator();
    NiKeyBasedInterpolator& operator=(const NiKeyBasedInterpolator&);

    virtual void LoadBinary(NiStream& kStream);
    virtual void GetInterpolatorTimeRange(float& arBeginKeyTime, float& arEndKeyTime) const;

    virtual unsigned short GetKeyChannelCount() const = 0;
    virtual unsigned int GetColorKeyCount(unsigned short usChannel) const = 0;
    virtual void vf57() = 0;
    virtual void vf58() = 0;
    virtual NiAnimationKey* GetChannelKeys(unsigned short usChannel) const = 0;
    virtual unsigned char GetColorKeySize(unsigned short usChannel) const = 0;
    virtual void vf61(unsigned short usChannel) = 0;
};
