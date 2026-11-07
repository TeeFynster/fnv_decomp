#pragma once

#include "TESBoundAnimObject.h"
#include "TESFullName.h"
#include "TESModelTextureSwap.h"
#include "TESIcon.h"
#include "BGSMessageIcon.h"
#include "TESScriptableForm.h"
#include "TESWeightForm.h"
#include "TESValueForm.h"
#include "BGSDestructibleObjectForm.h"
#include "LightSourceData.h"
#include "NiColor.h"

class NiAVObject;
class NiLight;
class NiNode;
class TESObjectREFR;
class TESSound;

class TESObjectLIGH : public TESBoundAnimObject,
                      public TESFullName,
                      public TESModelTextureSwap,
                      public TESIcon,
                      public BGSMessageIcon,
                      public TESScriptableForm,
                      public TESWeightForm,
                      public TESValueForm,
                      public BGSDestructibleObjectForm
{
public:
    TESObjectLIGH();
    virtual ~TESObjectLIGH();

    virtual void InitItem();
    NiAVObject* Get3DObject(TESObjectREFR* reference);

    void ResetFormData();
    void FUN_0050c9e0(int);
    void SetSound(TESSound* sound);
    bool GetCanCarry();
    bool InvokeAction(unsigned int, unsigned int, bool, unsigned int, unsigned int);
    bool Activate_0050e4b0(unsigned int, unsigned int, bool, unsigned int, unsigned int);
    NiNode* Create3DModel(TESObjectREFR* reference);
    NiLight* CreateLight(TESObjectREFR* reference, NiAVObject* object, bool flag);
    void* CreateLight(void* reference, void* object, bool flag);
    unsigned int GetColor();
    NiColor* GetLightColor();
    bool GetDynamic();
    float GetRadius();
    int FUN_0087eaa0();

    LightSourceData data;
    float fFadeAmount;
    TESSound* m_pGameSound;
    NiColor m_kDiffuseColor;
};
