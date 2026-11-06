#pragma once

#include "BSTempEffect.h"
#include "NiAVObject.h"

class BSTempEffectDebris : public BSTempEffect
{
  public:
    BSTempEffectDebris();
    virtual ~BSTempEffectDebris();

    virtual bool ShouldDelete();
    void SetIsForegroundEffect(bool foregroundElement);
    bool IsNew();

    NiPointer<NiAVObject> m_pSceneObject;
    const char* pFilename;
    bool m_bForegroundEffect;
    bool bForceDelete;
    bool m_bShouldDelete;
    unsigned char pad23;
};
