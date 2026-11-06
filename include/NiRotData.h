#pragma once

#include "NiObject.h"
#include "NiPosData.h"

class TimedRotationKey;

class NiRotData : public NiObject
{
  public:
    void SetKeys(TimedRotationKey* pkKeys, unsigned int uiNumKeys, NiAnimationKey::KeyType eType);
    void GuaranteeKeysAtStartAndEnd(float fStartTime, float fEndTime);
    TimedRotationKey* ComputePositionAtTime(unsigned int& uiNumKeys, int& eType, unsigned char& ucSize) const;

    unsigned int m_uiNumKeys;
    TimedRotationKey* m_pKeyArray;
    NiAnimationKey::KeyType m_eRequestType;
    unsigned char m_ucKeyDataSize;
};
