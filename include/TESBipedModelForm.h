#pragma once

#include "BaseFormComponent.h"
#include "TESModelTextureSwap.h"
#include "TESIcon.h"
#include "BGSMessageIcon.h"
#include "TESModelRDT.h"

class BGSBipedModelList;
class BipedAnim;
class BSFaceGenModel;
class TESBoundObject;
class TESForm;
enum BIPED_OBJECT;
enum SEX;

class TESBipedModelForm : public BaseFormComponent
{
public:
    unsigned long partMask;
    unsigned char bipedFlags;
    unsigned char fil009[3];
    TESModelTextureSwap bipedModel[2];
    TESModelTextureSwap groundModel[2];
    TESIcon icon[2];
    BGSMessageIcon messageIcon[2];
    TESModelRDT modelRDT;

    TESBipedModelForm();
    ~TESBipedModelForm();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);

    void InitializeComponent();
    void InitItem(TESForm* form);
    bool IsPowerArmor();
    bool IsPlayable();
    bool FUN_0047c850();
    bool TESBipedModelForm_HasBackpack();
    bool FUN_00480af0(int slot, bool hair, bool modelList);
    bool TESBipedModelForm_GetPlayable();
    void TESBipedModelForm_SetAddOnModel(bool value);
    BSFaceGenModel* GetBipedConstraint();
    bool GetIsHeavyArmor() const;
    bool GetIsMediumArmor() const;
    bool HasBipedModel(BIPED_OBJECT slot, bool hair, BGSBipedModelList* modelList);
    bool HasBipedModel(int slot, bool hair, void* modelList);
    void SetBipedModel(BipedAnim* anim, SEX sex, BIPED_OBJECT slot);
    void SetBipedModel(BipedAnim* anim, SEX sex, int slot);
    TESModelTextureSwap* GetWorldModel(int sex);
    TESModelTextureSwap* GetBipedModel(SEX sex);
    const char* GetBipedModel(int sex);
    TESModel* GetWeaponModel(SEX sex);

    static TESBipedModelForm* GetFormAsBipedModel(TESForm* form);
    static TESBipedModelForm* GetFormAsBipedModel(const TESForm* form);
    static TESBipedModelForm* GetFormAsBipedModel(TESBoundObject* form);
};
