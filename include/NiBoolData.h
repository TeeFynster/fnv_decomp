#pragma once

#include "NiObject.h"
#include "NiColorInterpolator.h"

class BooleanKey;

class NiBoolData : public NiObject
{
  public:
    virtual void LoadBinary(NiStream& stream);

    void SetColorKeys(BooleanKey*, unsigned int, NiAnimationKey::KeyType);
    void DecrementRefCount();
    void* Destroy(unsigned int);

    unsigned int m_uiNumKeys;
    BooleanKey* m_pKeyArray;
    NiAnimationKey::KeyType m_eRequestType;
    unsigned char m_ucKeyDataSize;
    unsigned char unk15[3];
};
