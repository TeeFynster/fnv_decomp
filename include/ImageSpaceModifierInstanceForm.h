#pragma once

#include "ImageSpaceModifierInstance.h"
#include "NiAVObject.h"

class TESImageSpaceModifier;

class ImageSpaceModifierInstanceForm : public ImageSpaceModifierInstance
{
  public:
    ImageSpaceModifierInstanceForm();
    virtual ~ImageSpaceModifierInstanceForm();
    ImageSpaceModifierInstanceForm(TESImageSpaceModifier*, float, float, NiAVObject*);
    void* Destroy(unsigned int);

    static void __cdecl Stop(TESImageSpaceModifier*);
    static ImageSpaceModifierInstanceForm* __cdecl Trigger(TESImageSpaceModifier*, float, NiAVObject*);
    static ImageSpaceModifierInstanceForm* ApplyImageSpaceModifier(TESImageSpaceModifier*, float, NiAVObject*);

    TESImageSpaceModifier* GetImageSpaceMod();
    bool IsExpired();
    void Apply();
    void FormatDebugString(char*);
    bool Blend(TESImageSpaceModifier*, float, float, NiAVObject*);
    void SetPad5(float);

    TESImageSpaceModifier* m_pPreviousImageSpaceModifier;
    TESImageSpaceModifier* m_pImageSpaceModifier;
    float m_fBlendWeight;
    NiPointer<NiAVObject> m_pTargetNode;
    float m_fElapsedTime;
};
