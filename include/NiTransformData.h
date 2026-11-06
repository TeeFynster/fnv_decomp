#pragma once

#include "NiObject.h"
#include "NiPosData.h"

class TimedRotationKey;
class PositionKeyInterpolator;
class TimedAnimationKey;

class NiTransformData : public NiObject
{
  public:
    unsigned short m_usNumRotKeys;
    unsigned short m_usNumPosKeys;
    unsigned short m_usNumScaleKeys;
    unsigned char layoutPaddingE[2];
    NiAnimationKey::KeyType m_eRotationKeyType;
    NiAnimationKey::KeyType m_ePositionKeyType;
    NiAnimationKey::KeyType m_eScaleKeyType;
    unsigned char m_ucRotationKeySize;
    unsigned char m_ucPositionKeySize;
    unsigned char m_ucScaleKeySize;
    unsigned char layoutPadding1F[1];
    TimedRotationKey* m_pkRotationKeys;
    PositionKeyInterpolator* m_pkPositionKeys;
    TimedAnimationKey* m_pkScaleKeyArray;

    void SetRotationKeys(TimedRotationKey*, unsigned int, NiAnimationKey::KeyType);
    void SetPositionKeys(PositionKeyInterpolator*, unsigned int, NiAnimationKey::KeyType);
    void SetScaleKeys(TimedAnimationKey*, unsigned int, NiAnimationKey::KeyType);
};
