#pragma once

#include "NiObject.h"
#include "NiPosData.h"
#include "NiRTTI.h"

class ColorAnimationKey;

class NiColorData : public NiObject
{
  public:
    NiColorData();
    virtual ~NiColorData();
    virtual const NiRTTI* GetRTTI() const;

    void SetColorKeys(ColorAnimationKey*, unsigned int, NiAnimationKey::KeyType);

    unsigned int m_uiNumKeys;
    ColorAnimationKey* m_pKeyArray;
    NiAnimationKey::KeyType m_eRequestType;
    unsigned char m_ucKeyDataSize;
    unsigned char m_aucPad[3];
};
