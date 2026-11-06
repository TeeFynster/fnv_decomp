#pragma once

#include "NiObject.h"
#include "NiPosData.h"

class TimedAnimationKey;

class NiFloatData : public NiObject
{
  public:
    NiFloatData();
    virtual void LoadBinary(NiStream&);

    void SetColorKeys(TimedAnimationKey*, unsigned int, NiAnimationKey::KeyType);

    unsigned int m_uiNumKeys;
    TimedAnimationKey* m_pKeyArray;
    NiAnimationKey::KeyType m_eRequestType;
    unsigned char m_ucKeyDataSize;
    unsigned char m_auPadKeySize[3];
};
