#pragma once

#include "NiObject.h"
#include "NiColorInterpolator.h"
#include "NiPoint3.h"

class PositionKeyInterpolator;

class NiPosData : public NiObject
{
  public:
    virtual void LoadBinary(NiStream&);

    void SetColorKeys(PositionKeyInterpolator*, unsigned int, NiAnimationKey::KeyType);
    static NiPoint3* ComputePositionAtTime(NiPoint3*, float, const NiPoint3*);
    static NiPoint3 ComputePositionAtTime(float, const NiPoint3&);

    unsigned int m_uiNumKeys;
    PositionKeyInterpolator* m_pKeyArray;
    NiAnimationKey::KeyType m_eRequestType;
    unsigned char m_ucKeyDataSize;
    unsigned char m_padding15[3];
};
