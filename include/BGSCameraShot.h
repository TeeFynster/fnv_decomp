#pragma once

#include "TESForm.h"
#include "TESModel.h"
#include "TESImageSpaceModifiableForm.h"
#include "BGSCameraShot__CAMERA_SHOT_DATA.h"
#include "NiAVObject.h"
#include "NiPoint3.h"

class TESObjectREFR;
class NiNode;

class BGSCameraShot : public TESForm, public TESModel, public TESImageSpaceModifiableForm
{
public:
    BGSCameraShot();
    virtual ~BGSCameraShot();
    virtual void ClearData();
    virtual bool LoadForm2(TESFile* file);
    virtual void InitItem();
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);

    bool Load(TESFile* file);
    void ResetCameraShot();
    void ResetFormData();
    void SetupCamera(void* reference, int mode);
    void UpdateCamera(float time);
    NiPoint3 GetCameraPosition();
    bool IsNotFlag4Set();
    bool IsInitialized();
    float TESCombatStyle_GetTargetingFOV();

    BGSCameraShot__CAMERA_SHOT_DATA Data;
    NiPointer<NiAVObject> m_pLocationNode;
    NiPointer<NiAVObject> m_pTargetNode;
    TESObjectREFR* m_pReference;
    NiPointer<NiNode> m_spPositionNode;
    NiPointer<NiAVObject> m_pSceneObject;
    char m_bUpdateNodePosition;
    bool m_bFlag74;
    bool m_bFlag75;
    unsigned char layoutPadding77[1];
};
