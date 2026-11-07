// fallout_shared/tesbipedmodelform.cpp: TESBipedModelForm, TESModelRDT, BipedComparison, BipedModelCopy (20 functions)

#include "tesbipedmodelform_decls.h"
#include "layout_support.h"
#include "../../include/TESForm.h"
#include "tesbipedmodelform_types_TESBipedModelForm.h"
#include "tesbipedmodelform_types_BIPED_OBJECT.h"
#include "tesbipedmodelform_types_SEX.h"
#include "tesbipedmodelform_types_BGSBipedModelList.h"

// @fnv 0x004802f0
TESBipedModelForm::TESBipedModelForm()
{
    InitializeComponent();
}

// @fnv 0x00480d10
bool TESBipedModelForm::IsPowerArmor()
{
    if (bipedFlags & 0x20)
        return true;
    else
        return false;
}

// Initializes both biped and world model slots (indices 0 and 1) of the form.
// @fnv 0x00480750
void TESBipedModelForm::InitItem(TESForm* form)
{
    bipedModel[0].InitItem(form);
    groundModel[0].InitItem(form);
    bipedModel[1].InitItem(form);
    groundModel[1].InitItem(form);
}

// Checks whether this form or a form in modelList fills the given biped slot, recursing into biped model forms found in the list.
// @fnv 0x00480af0
bool TESBipedModelForm::HasBipedModel(BIPED_OBJECT slot, bool hair, BGSBipedModelList* modelList)
{
    if (hair && slot == BIPED_OBJECT_BO_HAIR && (partMask & 1))
        return false;

    bool fillsSlot = partMask & (1 << slot);
    if (!fillsSlot && modelList)
    {
        BGSListForm* listForm = modelList->GetList();
        if (listForm)
        {
            BSSimpleList<TESForm*>* itemList = listForm->GetList();
            while (!fillsSlot && itemList && !itemList->IsEmpty())
            {
                struct
                {
                    TESBipedModelForm* bipedForm;
                    TESForm* form;
                } locals;
                locals.form = itemList->GetItem();
                locals.bipedForm = TESBipedModelForm::GetFormAsBipedModel(locals.form);
                if (locals.bipedForm)
                    fillsSlot = locals.bipedForm->HasBipedModel(slot, hair, 0);
                itemList = itemList->GetNext();
            }
        }
    }
    return fillsSlot;
}

// Falls back to the male model when the female model is empty, applies the model to the biped anim, and loads face gen extra data if present.
// @fnv 0x00480bd0
void TESBipedModelForm::SetBipedModel(BipedAnim* anim, SEX sex, BIPED_OBJECT slot)
{
    if (sex == SEX_SEX_FEMALE && !bipedModel[sex].GetModelLength())
        sex = SEX_SEX_MALE;

    anim->SetBipedObject(dynamic_cast<TESForm*>(this), &bipedModel[sex], slot);

    if (modelRDT.GetModelLength())
    {
        BSFaceGenModel* model = GetBipedConstraint();
        NiPointer<BSFaceGenModelExtraData> extra(0);
        g_modelLoader->ModelLoader_FindModel(model, &extra);
        if (extra.operator->())
            anim->FUN_0043f010(extra.operator->()->GetModelFilePath())->ApplyRDTNodeScales();
    }
}

// Returns the face gen model obtained through the member TESModelRDT's vtable slot 5.
// @fnv 0x00480ce0
// src: XBOX_PDB 0x00480ce0
BSFaceGenModel* TESBipedModelForm::GetBipedConstraint()
{
    return (BSFaceGenModel*)modelRDT.GetModelFilePath();
}

// @fnv 0x004803e0
TESModelRDT::TESModelRDT()
{}

struct FUN_00480d30_shell : public TESBipedModelForm
{
    bool TESBipedModelForm_HasBackpack();
};

// @fnv 0x00480d30
// src: COMMUNITY 0x00480d30
bool FUN_00480d30_shell::TESBipedModelForm_HasBackpack()
{
    if (*((unsigned char*)this + 8) & 4)
        return true;
    else
        return false;
}

struct FUN_00480d50_shell : public TESBipedModelForm
{
    void TESBipedModelForm_SetAddOnModel(bool);
};

// Sets or clears bit 0x10 in the byte at offset 8 of this TESBipedModelForm according to abVal.
// @fnv 0x00480d50
// src: XBOX_PDB 0x00480d50
void FUN_00480d50_shell::TESBipedModelForm_SetAddOnModel(bool abVal)
{
    if (abVal)
        *((unsigned char*)this + 8) |= 0x10;
    else
        *((unsigned char*)this + 8) &= ~0x10;
}

struct FUN_00480d90_shell : public TESBipedModelForm
{
    bool TESBipedModelForm_GetPlayable();
};

// @fnv 0x00480d90
// src: XBOX_PDB 0x00480d90
bool FUN_00480d90_shell::TESBipedModelForm_GetPlayable()
{
    if (*((unsigned char*)this + 8) & 0x40)
        return false;
    else
        return true;
}

struct FUN_00481110_shell : public TESBipedModelForm
{
    TESModelTextureSwap* GetWorldModel(int);
};

// @fnv 0x00481110
TESModelTextureSwap* FUN_00481110_shell::GetWorldModel(int aeSex)
{
    if (groundModel[aeSex].GetModelLength() == 0 && aeSex == 1)
    {
        aeSex = 0;
    }
    return &groundModel[aeSex];
}

struct FUN_00480ad0_shell
{
    unsigned int m_00;
    unsigned int m_04;
    bool HasFlag(unsigned int arg);
};

// @fnv 0x00480ad0
bool FUN_00480ad0_shell::HasFlag(unsigned int arg)
{
    return (m_04 & ((unsigned int*)((char*)arg + 4))[0]) ? true : false;
}

struct FUN_00481150_shell
{
    unsigned char layoutPadding0c[0xc];
    TESModelTextureSwap bipedModel[2];
    TESModelTextureSwap* GetBipedModel(SEX aeSex);
};

// Returns the biped model for the given sex, falling back to the first model when the requested one is empty and the sex is 1.
// @fnv 0x00481150
TESModelTextureSwap* FUN_00481150_shell::GetBipedModel(SEX aeSex)
{
    if (bipedModel[aeSex].GetModelLength() == 0 && aeSex == 1)
    {
        aeSex = (SEX)0;
    }
    return &bipedModel[aeSex];
}

struct FUN_00481190_standin
{
    unsigned char _pad[0x4C];
    TESModelTextureSwap models[2];
    BSFaceGenModel* _TESBipedModelForm_GetWorldModel(int idx);
};
// Returns the model from models[idx], falling back to index 0 when index 1 has no model length.
// @fnv 0x00481190
// src: COMMUNITY 0x00481190
BSFaceGenModel* FUN_00481190_standin::_TESBipedModelForm_GetWorldModel(int aiIndex)
{
    if (!models[aiIndex].GetModelLength() && aiIndex == 1)
        aiIndex = 0;
    return (BSFaceGenModel*)models[aiIndex].GetModelFilePath();
}

struct FUN_004811e0_shell
{
    char _pad[12];
    TESModelTextureSwap bipedModel[2];
    const char* TESBipedModelForm_GetBipedModel(int aeSex);
};
// @fnv 0x004811e0
// src: XBOX_PDB 0x004811e0
const char* FUN_004811e0_shell::TESBipedModelForm_GetBipedModel(int aeSex)
{
    if (bipedModel[aeSex].GetModelLength() == 0 && aeSex == 1)
        aeSex = 0;
    return bipedModel[aeSex].GetModelFilePath();
}

struct DoorPart3c
{
    void ProcessAndFreeData(unsigned int, unsigned int, unsigned int);
};

struct FUN_0047a240_shell
{
    void FUN_0047a240(unsigned int);
};

struct FUN_004891d0_obj
{
    void WriteToBuffer(unsigned int, unsigned int);
};

struct FUN_00489240_Class
{
    void TESModel_SaveFlags(unsigned int);
};

struct FUN_0048e370_obj
{
    void TESTexture_Save(unsigned int);
};

struct BIPED_MODEL_ENDIAN : BipedModelForm
{
    void Endian()
    {
        unsigned int value = m_uiBipedModelFlags;
        m_uiBipedModelFlags = ((value & 0x000000ffU) << 24) | ((value & 0x0000ff00U) << 8) |
                              ((value & 0x00ff0000U) >> 8) | ((value & 0xff000000U) >> 24);
    }
};

bool _FUN_00401500();
void _FUN_00485990(int, void*, int);

struct FUN_00480610_shell
{
    void InitBipedModel();
};

// @fnv 0x00480610
void FUN_00480610_shell::InitBipedModel()
{
    if (_FUN_00401500())
    {
        reinterpret_cast<BIPED_MODEL_ENDIAN*>(reinterpret_cast<char*>(this) + 4)->Endian();
    }

    _FUN_00485990(0x54444d42, reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 4), 8);

    if (_FUN_00401500())
    {
        reinterpret_cast<BIPED_MODEL_ENDIAN*>(reinterpret_cast<char*>(this) + 4)->Endian();
    }

    reinterpret_cast<DoorPart3c*>(reinterpret_cast<char*>(this) + 0x0c)
        ->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    reinterpret_cast<FUN_00489240_Class*>(reinterpret_cast<char*>(this) + 0x0c)->TESModel_SaveFlags(0x44444f4d);

    reinterpret_cast<DoorPart3c*>(reinterpret_cast<char*>(this) + 0x4c)
        ->ProcessAndFreeData(0x32444f4d, 0x54324f4d, 0x53324f4d);

    reinterpret_cast<FUN_0048e370_obj*>(reinterpret_cast<char*>(this) + 0x8c)->TESTexture_Save(0x4e4f4349);
    reinterpret_cast<FUN_0047a240_shell*>(reinterpret_cast<char*>(this) + 0xa4)->FUN_0047a240(0x4f43494d);

    reinterpret_cast<DoorPart3c*>(reinterpret_cast<char*>(this) + 0x2c)
        ->ProcessAndFreeData(0x33444f4d, 0x54334f4d, 0x53334f4d);
    reinterpret_cast<FUN_00489240_Class*>(reinterpret_cast<char*>(this) + 0x2c)->TESModel_SaveFlags(0x44534f4d);

    reinterpret_cast<DoorPart3c*>(reinterpret_cast<char*>(this) + 0x6c)
        ->ProcessAndFreeData(0x34444f4d, 0x54344f4d, 0x53344f4d);

    reinterpret_cast<FUN_0048e370_obj*>(reinterpret_cast<char*>(this) + 0x98)->TESTexture_Save(0x324f4349);
    reinterpret_cast<FUN_0047a240_shell*>(reinterpret_cast<char*>(this) + 0xb4)->FUN_0047a240(0x3243494d);

    reinterpret_cast<FUN_004891d0_obj*>(reinterpret_cast<char*>(this) + 0xc4)->WriteToBuffer(0x54434d42, 0);
}

struct FUN_00480570_cls : public TESBipedModelForm
{
    void FreeModels();
};

// @fnv 0x00480570
void FUN_00480570_cls::FreeModels()
{
    bipedModel[0].Free();
    groundModel[0].Free();
    icon[0].Free();
    bipedModel[1].Free();
    groundModel[1].Free();
    icon[1].Free();
    modelRDT.Free();
}

struct FUN_004804d0_shell;

struct FUN_004804d0_standin
{
    virtual void Call();
};

struct FUN_004804d0_shell
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned char unk08;

    FUN_004804d0_standin unk0c;

    unsigned char unk10;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    unsigned char unk14;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    unsigned char unk18;
    unsigned char unk19;
    unsigned char unk1a;
    unsigned char unk1b;
    unsigned char unk1c;
    unsigned char unk1d;
    unsigned char unk1e;
    unsigned char unk1f;
    unsigned char unk20;
    unsigned char unk21;
    unsigned char unk22;
    unsigned char unk23;
    unsigned char unk24;
    unsigned char unk25;
    unsigned char unk26;
    unsigned char unk27;
    unsigned char unk28;
    unsigned char unk29;
    unsigned char unk2a;
    unsigned char unk2b;

    FUN_004804d0_standin unk2c;

    unsigned char unk30;
    unsigned char unk31;
    unsigned char unk32;
    unsigned char unk33;
    unsigned char unk34;
    unsigned char unk35;
    unsigned char unk36;
    unsigned char unk37;
    unsigned char unk38;
    unsigned char unk39;
    unsigned char unk3a;
    unsigned char unk3b;
    unsigned char unk3c;
    unsigned char unk3d;
    unsigned char unk3e;
    unsigned char unk3f;
    unsigned char unk40;
    unsigned char unk41;
    unsigned char unk42;
    unsigned char unk43;
    unsigned char unk44;
    unsigned char unk45;
    unsigned char unk46;
    unsigned char unk47;
    unsigned char unk48;
    unsigned char unk49;
    unsigned char unk4a;
    unsigned char unk4b;

    FUN_004804d0_standin unk4c;

    unsigned char unk50;
    unsigned char unk51;
    unsigned char unk52;
    unsigned char unk53;
    unsigned char unk54;
    unsigned char unk55;
    unsigned char unk56;
    unsigned char unk57;
    unsigned char unk58;
    unsigned char unk59;
    unsigned char unk5a;
    unsigned char unk5b;
    unsigned char unk5c;
    unsigned char unk5d;
    unsigned char unk5e;
    unsigned char unk5f;
    unsigned char unk60;
    unsigned char unk61;
    unsigned char unk62;
    unsigned char unk63;
    unsigned char unk64;
    unsigned char unk65;
    unsigned char unk66;
    unsigned char unk67;
    unsigned char unk68;
    unsigned char unk69;
    unsigned char unk6a;
    unsigned char unk6b;

    FUN_004804d0_standin unk6c;

    unsigned char unk70;
    unsigned char unk71;
    unsigned char unk72;
    unsigned char unk73;
    unsigned char unk74;
    unsigned char unk75;
    unsigned char unk76;
    unsigned char unk77;
    unsigned char unk78;
    unsigned char unk79;
    unsigned char unk7a;
    unsigned char unk7b;
    unsigned char unk7c;
    unsigned char unk7d;
    unsigned char unk7e;
    unsigned char unk7f;
    unsigned char unk80;
    unsigned char unk81;
    unsigned char unk82;
    unsigned char unk83;
    unsigned char unk84;
    unsigned char unk85;
    unsigned char unk86;
    unsigned char unk87;
    unsigned char unk88;
    unsigned char unk89;
    unsigned char unk8a;
    unsigned char unk8b;

    FUN_004804d0_standin unk8c;

    unsigned char unk90;
    unsigned char unk91;
    unsigned char unk92;
    unsigned char unk93;
    unsigned char unk94;
    unsigned char unk95;
    unsigned char unk96;
    unsigned char unk97;

    FUN_004804d0_standin unk98;

    unsigned char unk9c;
    unsigned char unk9d;
    unsigned char unk9e;
    unsigned char unk9f;
    unsigned char unkA0;
    unsigned char unkA1;
    unsigned char unkA2;
    unsigned char unkA3;
    unsigned char unkA4;
    unsigned char unkA5;
    unsigned char unkA6;
    unsigned char unkA7;
    unsigned char unkA8;
    unsigned char unkA9;
    unsigned char unkAa;
    unsigned char unkAb;
    unsigned char unkAc;
    unsigned char unkAd;
    unsigned char unkAe;
    unsigned char unkAf;
    unsigned char unkB0;
    unsigned char unkB1;
    unsigned char unkB2;
    unsigned char unkB3;
    unsigned char unkB4;
    unsigned char unkB5;
    unsigned char unkB6;
    unsigned char unkB7;
    unsigned char unkB8;
    unsigned char unkB9;
    unsigned char unkBa;
    unsigned char unkBb;
    unsigned char unkBc;
    unsigned char unkBd;
    unsigned char unkBe;
    unsigned char unkBf;
    unsigned char unkC0;
    unsigned char unkC1;
    unsigned char unkC2;
    unsigned char unkC3;

    FUN_004804d0_standin unkC4;

    void TESBipedModelForm_InitializeDataComponent();
};

// Clears unk04 and unk08, then calls Call on the seven embedded objects at unk0c, unk4c, unk8c, unk2c, unk6c, unk98 and unkC4.
// @fnv 0x004804d0
// src: XBOX_PDB 0x004804d0
void FUN_004804d0_shell::TESBipedModelForm_InitializeDataComponent()
{
    unk04 = 0;
    unk08 = 0;

    unk0c.Call();
    unk4c.Call();
    unk8c.Call();
    unk2c.Call();
    unk6c.Call();
    unk98.Call();
    unkC4.Call();
}

#include <string.h>
class BipedComparison : public TESBipedModelForm
{
  public:
    bool TESBipedModelForm_CompareComponent(BaseFormComponent* other);
};

// Compares this BipedComparison against another BaseFormComponent, returning true if the cast fails or any biped model, icon, or facegen field differs.
// @fnv 0x004808f0
// src: XBOX_PDB 0x004808f0
bool BipedComparison::TESBipedModelForm_CompareComponent(BaseFormComponent* other)
{
    TESBipedModelForm* compared = dynamic_cast<TESBipedModelForm*>(other);
    if (!compared)
        return true;
    if (memcmp(&partMask, &compared->partMask, sizeof(BipedModelForm)))
        return true;
    if (bipedModel[0].CompareWithBase(static_cast<BaseFormComponent*>(&compared->bipedModel[0])))
        return true;
    if (groundModel[0].CompareWithBase(static_cast<BaseFormComponent*>(&compared->groundModel[0])))
        return true;
    if (icon[0].CompareWithBase(static_cast<BaseFormComponent*>(&compared->icon[0])))
        return true;
    if (messageIcon[0].CompareWithBase(static_cast<BaseFormComponent*>(&compared->messageIcon[0])))
        return true;
    if (bipedModel[1].CompareWithBase(static_cast<BaseFormComponent*>(&compared->bipedModel[1])))
        return true;
    if (groundModel[1].CompareWithBase(static_cast<BaseFormComponent*>(&compared->groundModel[1])))
        return true;
    if (icon[1].CompareWithBase(static_cast<BaseFormComponent*>(&compared->icon[1])))
        return true;
    if (messageIcon[1].CompareWithBase(static_cast<BaseFormComponent*>(&compared->messageIcon[1])))
        return true;
    if (modelRDT.CompareWithBase(static_cast<BaseFormComponent*>(&compared->modelRDT)))
        return true;
    return false;
}

class BipedModelCopy : public TESBipedModelForm
{
  public:
    void TESBipedModelForm_CopyComponent(BaseFormComponent* component);
};

// Copies all biped model fields from a source TESBipedModelForm into this BipedModelCopy after casting the component.
// @fnv 0x004807a0
// src: XBOX_PDB 0x004807a0
void BipedModelCopy::TESBipedModelForm_CopyComponent(BaseFormComponent* component)
{
    TESBipedModelForm* source;
    source = dynamic_cast<TESBipedModelForm*>(component);
    if (source == 0)
    {
    }
    else
    {
        memcpy(&partMask, &source->partMask, sizeof(BipedModelForm));
        bipedModel[0].CopyFromBase(static_cast<BaseFormComponent*>(&source->bipedModel[0]));
        groundModel[0].CopyFromBase(static_cast<BaseFormComponent*>(&source->groundModel[0]));
        icon[0].CopyFromBase(static_cast<BaseFormComponent*>(&source->icon[0]));
        messageIcon[0].CopyFromBase(static_cast<BaseFormComponent*>(&source->messageIcon[0]));
        bipedModel[1].CopyFromBase(static_cast<BaseFormComponent*>(&source->bipedModel[1]));
        groundModel[1].CopyFromBase(static_cast<BaseFormComponent*>(&source->groundModel[1]));
        icon[1].CopyFromBase(static_cast<BaseFormComponent*>(&source->icon[1]));
        messageIcon[1].CopyFromBase(static_cast<BaseFormComponent*>(&source->messageIcon[1]));
        modelRDT.CopyFromBase(static_cast<BaseFormComponent*>(&source->modelRDT));
    }
}
