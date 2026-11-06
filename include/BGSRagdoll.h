#pragma once

#include "TESForm.h"
#include "TESModel.h"
#include "SaveMetadata.h"
#include "RagdollAnimationData.h"
#include "FootIK_DATA.h"
#include "LookIK_DATA.h"
#include "GrabIK_DATA.h"
#include "RagdollFeedbackProfile.h"
#include "BGSBodyPartData.h"

class TESActorBase;

class BGSRagdoll : public TESForm, public TESModel
{
public:
    SaveMetadata ActorAnimationData;
    unsigned char layoutPadding3E[2];
    RagdollAnimationData m_kRagdollAnimationData;
    FootIK_DATA m_kFootIKData;
    LookIK_DATA m_kLookIKData;
    GrabIK_DATA m_kGrabIKData;
    RagdollFeedbackProfile m_kRagdollFeedbackProfile;
    int m_iRagdollType;
    BGSBodyPartData* m_pBodyPartDataCur;
    TESActorBase* m_pActorBase;

    BGSRagdoll();
    virtual ~BGSRagdoll();
    virtual bool LoadForm(TESFile* file);
    virtual void InitItem(void);

    void ResetFormData();
    bool Load(TESFile* file);
};
