#pragma once

#include "NiObject.h"
#include "NiAVObject.h"

class ImageSpaceModifierInstanceForm;

class ImageSpaceModifierInstance : public NiObject
{
  public:
    ImageSpaceModifierInstance(float, float, NiAVObject*);
    virtual ~ImageSpaceModifierInstance();

    // Slots 0 through 34 are inherited from NiObject.
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual ImageSpaceModifierInstanceForm* GetInstanceForm();
    virtual void vf38(char* apBuffer);

    static float GetTime();
    bool IsFlagSet();
    void __thiscall PlayerCharacter_StopVatsImageSpace();

    bool m_bHasBeenApplied;
    unsigned char layoutPadding9[3];
    float fWaterLevelItem;
    NiPointer<NiAVObject> m_spTargetObject;
    float m_fStartTime;
    unsigned int iFlags;
};
