// effectsetting.cpp: EffectSetting and effect data helpers (41 functions)

#include <stddef.h>
#include "../include/BSStringT.h"
#define FNV_JOIN2(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN2(a, b)
#define FNV_STATIC_ASSERT(e) typedef char FNV_JOIN(fnv_check_, __LINE__)[(e) ? 1 : -1]
#include "../include/BSSimpleList.h"
#include "../include/LowProcess.h"
#include "../include/MiddleHighProcess.h"
#include "../include/TESChallenge.h"
#include "../include/TESGrass.h"
#include "../include/TESEffectShader.h"
#include "../include/TESSound.h"
#include "../include/TESObjectLIGH.h"

#include "../include/EffectSetting.h"
#include "../include/TES.h"
#include "../include/TESFile.h"

FNV_STATIC_ASSERT(sizeof(EffectSetting__EffectSettingData) == 72);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, iFlags) == 0);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_fBaseCost) == 4);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_pAssociatedForm) == 8);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_iAssociatedSkill) == 12);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_iResistanceActorValue) == 16);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_sCounterEffectCount) == 20);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, apTargetLight) == 24);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, fSpeed) == 28);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_pEffectShader) == 32);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_pEnchantEffectShader) == 36);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_pCastSound) == 40);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_pBoltSound) == 44);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_pContactSound) == 48);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_pAreaEffectSound) == 52);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_fEnchantmentFactor) == 56);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_fBarterFactor) == 60);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_eEffectTypeItem) == 64);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_iAssociatedActorValue) == 68);
FNV_STATIC_ASSERT(sizeof(EffectSetting) == 176);
FNV_STATIC_ASSERT(offsetof(EffectSetting, m_pEffectSettingCallback) == 80);
FNV_STATIC_ASSERT(offsetof(EffectSetting, m_pPredicateData) == 84);
FNV_STATIC_ASSERT(offsetof(EffectSetting, data) == 88);
FNV_STATIC_ASSERT(offsetof(EffectSetting, counterEffects) == 160);
FNV_STATIC_ASSERT(offsetof(EffectSetting, m_iActorValue) == 168);
FNV_STATIC_ASSERT(offsetof(EffectSetting, m_iEffectID) == 172);

class TESFullNameLoader
{
  public:
    static void LoadFullNameChunk(TESFullName*, TESFile*);
};
template <int n> struct EndianSizeTag
{
};
void BSEndian(unsigned int*, EndianSizeTag<4>);
extern "C" void* __cdecl _alloca(unsigned int);
extern "C" void* __cdecl memset(void*, int, unsigned int);
int __cdecl Warning(const char*, ...);

// This entry point returns a full register value in the original Load call.
int __fastcall ReadEffectFormType(TESFile* file);

double NiAbs_00408820(float value);

#include "../include/PathingRequest.h"
#include "../include/TESDataHandler.h"

// Compares the effect name with name case-insensitively and, if they differ, sets the full name to name.
// @fnv 0x00408570
void EffectSetting::UpdateEffectName(const char* name)
{
    int comparison = GetEffectName().StrCmp(name, true);
    if (comparison)
        SetFullName(name);
}

// @fnv 0x00408880
bool EffectSetting::HasEffectID()
{
    return m_iEffectID > 0;
}

// @fnv 0x004088a0
bool EffectSetting::UsesAssociatedActorValue()
{
    return m_iEffectID < 0;
}

// @fnv 0x00408a20
bool EffectSetting::HasNoAssociatedActorValue()
{
    return m_iActorValue < 0;
}

// Loads an EffectSetting record from a TESFile, dispatching on chunk IDs to read editor ID, name, description, texture, model, data and counter effects.
// @fnv 0x00407ac0
bool EffectSetting::Load(TESFile* file)
{
    if (ReadEffectFormType(file) != 16)
        return false;
    LoadRecordHeader(file);
    int chunk;
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch (chunk)
        {
        case 0x44494445:  // EDID
        {
            char* editorID = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
        }
        break;
        case 0x444e424f:  // OBND
            readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:  // FULL
            TESFullNameLoader::LoadFullNameChunk(this, file);
            break;
        case 0x43534544:  // DESC
            TESDescription::ReadDescriptionFromFile(this, file);
            break;
        case 0x4e4f4349:  // ICON
            TESTexture::ReadTextureData(this, file);
            break;
        case 0x4c444f4d:  // MODL
        case 0x54444f4d:  // MODT
            TESModel::LoadModelData(this, file);
            break;
        case 0x41544144:  // DATA
            memset(&data, 0, sizeof(data));
            data.fSpeed = 1.0f;
            file->GetChunkData(&data, sizeof(data));
            if (file->IsEndianConversionRequired())
                data.Endian();
            SetFlag(PLAYER_KNOWS, false);
            break;
        case 0x45435345:  // ESCE
        {
            struct CounterEffectReference
            {
                unsigned int formID;
                EffectSetting* effect;
            } counterRef;
            file->GetChunkData(&counterRef.formID);
            if (file->IsEndianConversionRequired())
                BSEndian(&counterRef.formID, EndianSizeTag<4>());
            TESForm::RemapFormIDForFile(counterRef.formID, file);
            counterRef.effect = dynamic_cast<EffectSetting*>(TESForm::GetFormByID(counterRef.formID));
            if (counterRef.effect)
            {
                counterEffects.AddHead(counterRef.effect);
                data.m_sCounterEffectCount = counterEffects.ItemsInList();
            }
            else
                Warning("FORMS: Invalid form ID (%d) for effect setting found while loading counter effects for %s.",
                        counterRef.formID, GetName());
        }
        break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// Resolves the effect's associated item, light, sounds and shaders by form ID, warns on missing forms, and marks the item initialized.
// @fnv 0x00407e50
void EffectSetting::InitItem()
{
    unsigned int formID;
    if (GetInitialized())
        return;
    if (IsAssociatedFormUsed() && !GetFlag(0x180000))
    {
        unsigned int associatedID = reinterpret_cast<unsigned int>(data.m_pAssociatedForm);
        if (associatedID)
        {
            TESForm::RemapFormIDForFile(associatedID, GetFile(-1));
            data.m_pAssociatedForm = TESForm::GetFormByID(associatedID);
            if (!data.m_pAssociatedForm)
                Warning("MASTERFILE: Could not find associated item (%08X) for Effect '%s' (%08X).", associatedID,
                        GetName(), GetFormID());
        }
    }
    else
        data.m_pAssociatedForm = 0;
    formID = reinterpret_cast<unsigned int>(GetLight());
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        SetLight(dynamic_cast<TESObjectLIGH*>(TESForm::GetFormByID(formID)));
        if (!GetLight())
            Warning("MASTERFILE: Could not find light (%08X) for Effect '%s' (%08X).", formID, GetName(), GetFormID());
    }
    formID = reinterpret_cast<unsigned int>(GetCastSound());
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        SetCastSound(dynamic_cast<TESSound*>(TESForm::GetFormByID(formID)));
        if (!GetCastSound())
            Warning("MASTERFILE: Could not find cast sound (%08X) for Effect '%s' (%08X).", formID, GetName(),
                    GetFormID());
    }
    formID = reinterpret_cast<unsigned int>(GetBoltSound());
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        SetBoltSound(dynamic_cast<TESSound*>(TESForm::GetFormByID(formID)));
        if (!GetBoltSound())
            Warning("MASTERFILE: Could not find bolt sound (%08X) for Effect '%s' (%08X).", formID, GetName(),
                    GetFormID());
    }
    formID = reinterpret_cast<unsigned int>(GetHitSound());
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        SetHitSound(dynamic_cast<TESSound*>(TESForm::GetFormByID(formID)));
        if (!GetHitSound())
            Warning("MASTERFILE: Could not find hit sound (%08X) for Effect '%s' (%08X).", formID, GetName(),
                    GetFormID());
    }
    formID = reinterpret_cast<unsigned int>(GetAreaSound());
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        SetAreaSound(dynamic_cast<TESSound*>(TESForm::GetFormByID(formID)));
        if (!GetAreaSound())
            Warning("MASTERFILE: Could not find area sound (%08X) for Effect '%s' (%08X).", formID, GetName(),
                    GetFormID());
    }
    formID = reinterpret_cast<unsigned int>(GetEffectShader());
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        SetEffectShader(dynamic_cast<TESEffectShader*>(TESForm::GetFormByID(formID)));
        if (!GetEffectShader())
            Warning("MASTERFILE: Could not find effect shader (%08X) for Effect '%s' (%08X).", formID, GetName(),
                    GetFormID());
    }
    formID = reinterpret_cast<unsigned int>(GetEnchantEffectShader());
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        SetEnchantEffectShader(dynamic_cast<TESEffectShader*>(TESForm::GetFormByID(formID)));
        if (!GetEnchantEffectShader())
            Warning("MASTERFILE: Could not find enchant effect shader (%08X) for Effect '%s' (%08X).", formID,
                    GetName(), GetFormID());
    }
    SetInitializationState(true);
}

// @fnv 0x004088c0
// src: COMMUNITY 0x004088c0
int EffectSetting::IncEffectLoadedCount()
{
    if (m_iActorValue < 0)
        --m_iActorValue;
    else
        ++m_iActorValue;
    return m_iActorValue;
}
// Sets or clears the given EffectFlag bit in data.iFlags according to value.
// @fnv 0x00407e00
void EffectSetting::SetFlag(EffectFlag flag, bool value)
{
    value ? data.iFlags |= flag : data.iFlags &= ~flag;
}
// @fnv 0x00408970
int EffectSetting::QueueAssociatedItem()
{
    if (m_iActorValue > 0)
        Warning("GAME EFFECTS: Trying to Queue up an Effect Associated Item which is already loaded");
    else
        --m_iActorValue;
    return m_iActorValue;
}
// @fnv 0x004089c0
int EffectSetting::NormalizeEffectLoadedCount()
{
    m_iActorValue = (int)NiAbs_00408820((float)m_iActorValue);
    return m_iActorValue;
}

struct FUN_004077c0_shell : public TESForm
{
    bool TESForm_GetTemporary();
};

// @fnv 0x004077c0
// src: XBOX_PDB 0x004077c0
bool FUN_004077c0_shell::TESForm_GetTemporary()
{
    return (*(unsigned int*)((char*)this + 8) & 0x4000) ? true : false;
}

// @fnv 0x004077e0
// src: COMMUNITY 0x004077e0
void* EffectSetting::TESDataHandler_GetRecipes()
{
    return &counterEffects;
}

// @fnv 0x00407820
// src: XBOX_PDB 0x00407820
TESEffectShader* EffectSetting::GetEffectShader_00407820()
{
    return data.m_pEffectShader;
}

// @fnv 0x004078a0
void EffectSetting::SetEffectID(int aeID)
{
    data.m_eEffectTypeItem = static_cast<EffectArchetypes__ArchetypeID>(aeID);
}

// @fnv 0x00408680
bool EffectSetting::HasAllFlags(unsigned int aiFlags)
{
    return (data.iFlags & aiFlags) == aiFlags;
}

// Increments or decrements the counter at offset 0xac depending on its sign, then returns the new value.
// @fnv 0x004086e0
int EffectSetting::UpdateCounter()
{
    if (m_iEffectID < 0)
    {
        m_iEffectID -= 1;
    }
    else
    {
        m_iEffectID += 1;
    }
    return m_iEffectID;
}

// If the associated-item count at offset 0xac is positive, logs a warning; otherwise decrements it, and returns the count.
// @fnv 0x00408790
int __fastcall QueueEffectCounter(EffectSetting* self)
{
    if (self->m_iEffectID > 0)
    {
        Warning("GAME EFFECTS: Trying to Queue up an Effect Associated Item which is already loaded");
    }
    else
    {
        self->m_iEffectID = self->m_iEffectID - 1;
    }
    return self->m_iEffectID;
}

namespace std {
float __cdecl abs(float);
}

// @fnv 0x00408820
// src: XBOX_PDB 0x00408820
double NiAbs_00408820(float fValue)
{
    return std::abs(fValue);
}

double __cdecl _fabs(double);

// @fnv 0x00408860
// src: XBOX_PDB 0x00408860
float fabsf_00408860(float afValue)
{
    return (float)_fabs((double)afValue);
}

int __cdecl FUN_00ec6da0(const char*, const char*);

// @fnv 0x00408b20
// src: XBOX_PDB 0x00408b20
int __cdecl BSstrcmp(const char* apString1, const char* apString2)
{
    return FUN_00ec6da0(apString1, apString2);
}

// @fnv 0x004ee4b0
// src: XBOX_PDB 0x004ee4b0
void EffectSetting::BSShaderProperty_SetDepthBias(float afBaseCost)
{
    data.m_fBaseCost = afBaseCost;
}

struct FUN_00591300_shell : public TESFullName
{
    void BSStringT_Thunk();
};

// @fnv 0x00591300
// src: GUESS 0x00591300 (confidence: medium)
void FUN_00591300_shell::BSStringT_Thunk()
{
    ((BSStringT<char>*)((char*)this + 4))->BSStringT<char>::~BSStringT<char>();
}

// @fnv 0x00810570
void EffectSetting::SetAssociatedActorValue(int aeAssociatedActorValue)
{
    data.m_iAssociatedActorValue = aeAssociatedActorValue;
}

// @fnv 0x00857230
void EffectSetting::SetHitSound(TESSound* apValue)
{
    data.m_pContactSound = apValue;
}

// @fnv 0x008ce390
TESSound* EffectSetting::GetAreaSound()
{
    return data.m_pAreaEffectSound;
}

void __cdecl operator delete(void*);
// A word-sized aggregate keeps this legacy stack argument beside ECX's object.
struct EffectDestroyFlags
{
    unsigned int value;
};

// @fnv 0x00407200
void* __fastcall DestroyEffectSettingIfFlagged(EffectSetting* self, EffectDestroyFlags flags)
{
    self->EffectSetting::~EffectSetting();
    if (flags.value & 1)
        operator delete(self);
    return self;
}

extern "C" short __cdecl FUN_00ec3bda(short);

// Replaces the short value pointed to by p with the result of FUN_00ec3bda applied to it.
// @fnv 0x00407a90
// src: XBOX_PDB 0x00407a90
void __cdecl BSEndian_00407a90(short* psValue)
{
    short* tmp = psValue;
    *tmp = FUN_00ec3bda(*tmp);
}

// @fnv 0x00408550
int __fastcall GetEffectCounterCount(EffectSetting* self)
{
    return self->data.m_sCounterEffectCount;
}

// @fnv 0x004086a0
int __fastcall GetEffectFlagMode(EffectSetting* self)
{
    return (self->IsFlagSet_00403e60(0x2000000) ? 2 : 0) + (self->IsFlagSet_00403e60(0x4000000) ? 1 : 0);
}

// Steps the int at offset 0xAC one unit toward zero and returns the resulting value.
// @fnv 0x00408730
int __fastcall ClampEffectCounterTowardZero(EffectSetting* self)
{
    if (self->m_iEffectID < 0)
        self->m_iEffectID = self->m_iEffectID + 1;
    else if (self->m_iEffectID > 0)
        self->m_iEffectID = self->m_iEffectID - 1;
    return self->m_iEffectID;
}

// Converts the int at offset 0xac to float, passes it to FUN_00408820, stores the result back at 0xac and returns it.
// @fnv 0x004087e0
int __fastcall NormalizeEffectCounter(EffectSetting* self)
{
    self->m_iEffectID = (int)NiAbs_00408820((float)self->m_iEffectID);
    return self->m_iEffectID;
}

// Moves the loaded count one step toward zero and returns it.
// @fnv 0x00408910
int __fastcall StepEffectLoadedCountTowardZero(EffectSetting* self)
{
    if (self->m_iActorValue < 0)
        self->m_iActorValue++;
    else if (self->m_iActorValue > 0)
        self->m_iActorValue--;
    return self->m_iActorValue;
}

// @fnv 0x00408a00
bool __fastcall IsEffectLoadedCountPositive(EffectSetting* self)
{
    return self->m_iActorValue > 0;
}

// These comparison entry points are absent from BSStringT.h. Aggregates keep
// their legacy stack arguments alongside the string object in ECX.
struct BSStringArgument
{
    const BSStringT<char>* value;
};
struct BSStringCompareArguments
{
    const BSStringT<char>* value;
    bool ignoreCase;
};
bool __fastcall BSStringsEqual(BSStringT<char>* self, BSStringArgument string);
int __fastcall CompareBSStrings(BSStringT<char>* self, BSStringCompareArguments args);

// @fnv 0x00501c30
bool __fastcall BSStringsNotEqual(BSStringT<char>* self, BSStringArgument string)
{
    return !reinterpret_cast<bool (__thiscall*)(BSStringT<char>*, const BSStringT<char>*)>(BSStringsEqual)(
        self, string.value);
}

// @fnv 0x00501c60
bool __fastcall BSStringsEqual(BSStringT<char>* self, BSStringArgument string)
{
    return !reinterpret_cast<int (__thiscall*)(BSStringT<char>*, const BSStringT<char>*, bool)>(CompareBSStrings)(
        self, string.value, true);
}

// @fnv 0x00501c90
int __fastcall CompareBSStrings(BSStringT<char>* self, BSStringCompareArguments args)
{
    return self->StrCmp(static_cast<const char*>(*args.value), args.ignoreCase);
}

struct IMH
{
    int CombatController_GetCombatState();
};

struct TargetDoorController
{
};

struct Date
{
};

struct PlayerQuestData
{
    void SetLogDate(Date* value);
};

// Operations absent from EffectSetting.h remain free entry points. Aggregates
// keep legacy stack arguments alongside the object pointer in ECX.
void __fastcall SetEffectField90(EffectSetting* setting, float value);

void __fastcall SetEffectField94(EffectSetting* setting, float value);

struct EffectModeValue
{
    unsigned int value;
};
void __fastcall SetEffectMode(EffectSetting* setting, EffectModeValue value);

struct DH : public TESDataHandler
{
};

extern DH* g_dataHandler;

struct TESEffectShaderAux
{
    float Explosion_GetRadius();
};

float __fastcall GetField90Float(char* value);
struct EffectCounterSource
{
    void* list;
};
void __fastcall CopyEffectCounterValues(EffectSetting* self, EffectCounterSource source);

// Copies fields from an EffectSetting into this object, assigning a new ref ID when this form is non-temporary and has no form ID.
// @fnv 0x00407600
void EffectSetting::CopyFromBase(BaseFormComponent* component)
{
    EffectSetting* psetting = dynamic_cast<EffectSetting*>(reinterpret_cast<TESForm*>(component));
    if (!psetting)
        return;

    TESForm::CopyFrom(reinterpret_cast<TESForm*>(component));
    reinterpret_cast<LowProcess*>(this)->LowProcess::SetPackageObjectType(
        reinterpret_cast<TESChallenge*>(psetting)->GetThreshold());
    this->BSShaderProperty_SetDepthBias(reinterpret_cast<TESGrass*>(psetting)->TESGrass::GetLowestAllowedSlope());
    this->SetAssociatedActorValue(
        reinterpret_cast<IMH*>(psetting)->CombatController_GetCombatState());
    reinterpret_cast<MiddleHighProcess*>(this)->MiddleHighProcess::AddDeferredHideLimb(
        reinterpret_cast<ObjectToAcquire*>(psetting->GetEffectID()));
    reinterpret_cast<PlayerQuestData*>(this)->SetLogDate(
        reinterpret_cast<Date*>(reinterpret_cast<TES*>(psetting)->GetLogDate()));
    SetEffectField90(this, GetField90Float(reinterpret_cast<char*>(psetting)));
    SetEffectField94(this, reinterpret_cast<TESEffectShaderAux*>(psetting)->Explosion_GetRadius());
    reinterpret_cast<PathingRequest*>(this)->SetCenterRadius(
        reinterpret_cast<PathingRequest*>(psetting)->GetCenterRadius());
    this->SetEffectID(psetting->GetArchetype());
    reinterpret_cast<void (__thiscall*)(EffectSetting*, unsigned int)>(SetEffectMode)(
        this, reinterpret_cast<TESChallenge*>(psetting)->GetInterval());
    this->SetLight(psetting->GetLight());
    this->SetEffectShader(psetting->GetEffectShader());
    this->SetEnchantEffectShader(psetting->GetEnchantEffectShader());
    this->SetCastSound(psetting->GetCastSound());
    this->SetBoltSound(psetting->GetBoltSound());
    this->SetHitSound(psetting->GetHitSound());
    this->SetAreaSound(psetting->GetAreaSound());
    reinterpret_cast<void (__thiscall*)(EffectSetting*, void*)>(CopyEffectCounterValues)(
        this, psetting->TESDataHandler_GetRecipes());

    if (!this->IsTemporary() && this->GetFormID() == 0)
        this->SetRefID(g_dataHandler->GetNextID(), true);
}

void BSEndian(unsigned int*, EndianSizeTag<2>);

// Byte-swaps the 4-byte fields at offsets 0x00-0x40 and the 2-byte field at 0x14 of this object via BSEndian.
// @fnv 0x004078c0
void EffectSetting__EffectSettingData::Endian()
{
    BSEndian((unsigned int*)((unsigned char*)this + 0x00), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x04), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x44), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x08), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x0C), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x10), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x14), EndianSizeTag<2>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x18), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x1C), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x20), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x24), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x28), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x2C), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x30), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x34), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x38), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x3C), EndianSizeTag<4>());
    BSEndian((unsigned int*)((unsigned char*)this + 0x40), EndianSizeTag<4>());
}

// @fnv 0x00407230
EffectSetting::~EffectSetting()
{
    ClearData();
}

// Rebuilds the counter-effect list and updates the record's count.
// @fnv 0x00408600
void __fastcall CopyEffectCounterValues(EffectSetting* self, EffectCounterSource source)
{
    EffectSetting* val;
    self->counterEffects.RemoveAll();
    self->data.m_sCounterEffectCount = 0;
    for (BSSimpleList<EffectSetting*>* cur = (BSSimpleList<EffectSetting*>*)source.list;
         cur != 0 && (val = cur->GetItem()) != 0; cur = cur->GetNext())
    {
        self->counterEffects.AddHead(val);
        self->data.m_sCounterEffectCount++;
    }
}

// These legacy getters return double to preserve the original comparison's
// floating-point temporaries. The shared class has no equivalent declarations.
double __fastcall GetEffectBaseCostForComparison(EffectSetting* setting);
double __fastcall GetEffectCenterRadiusForComparison(EffectSetting* setting);

extern int DAT_01183028;
extern int DAT_011837c4;
void* __cdecl FUN_00ec43fb(void* a1, int a2, int* a3, int* a4, int a5);

// @fnv 0x004082f0
bool EffectSetting::CompareWithBase(BaseFormComponent* component)
{
    EffectSetting* other = (EffectSetting*)FUN_00ec43fb(component, 0, &DAT_01183028, &DAT_011837c4, 0);
    if (other == 0)
        return 1;
    if (TESForm::Compare(reinterpret_cast<TESForm*>(component)))
        return 1;
    if (reinterpret_cast<TESChallenge*>(this)->GetThreshold() != reinterpret_cast<TESChallenge*>(other)->GetThreshold() ||
        !(GetEffectBaseCostForComparison(this) == GetEffectBaseCostForComparison(other)) ||
        reinterpret_cast<IMH*>(this)->CombatController_GetCombatState() != reinterpret_cast<IMH*>(other)->CombatController_GetCombatState() ||
        reinterpret_cast<TESChallenge*>(this)->GetInterval() != reinterpret_cast<TESChallenge*>(other)->GetInterval() ||
        GetEffectID() != other->GetEffectID() ||
        reinterpret_cast<TES*>(this)->GetLogDate() != reinterpret_cast<TES*>(other)->GetLogDate() ||
        GetLight() != other->GetLight() || GetEffectShader() != other->GetEffectShader() ||
        GetEnchantEffectShader() != other->GetEnchantEffectShader() ||
        !(GetEffectCenterRadiusForComparison(this) == GetEffectCenterRadiusForComparison(other)) ||
        GetCastSound() != other->GetCastSound() || GetBoltSound() != other->GetBoltSound() ||
        GetHitSound() != other->GetHitSound() || GetAreaSound() != other->GetAreaSound() ||
        GetEffectCounterCount(this) != GetEffectCounterCount(other) || GetArchetype() != other->GetArchetype())
        return 1;
    BSSimpleList<EffectSetting*>* pa4 = &counterEffects;
    BSSimpleList<EffectSetting*>* pbX = &other->counterEffects;
    while (pa4 && pbX)
    {
        EffectSetting* av = pa4->GetItem();
        EffectSetting* bv5 = pbX->GetItem();
        if (av != bv5)
            return 1;
        pa4 = pa4->GetNext();
        pbX = pbX->GetNext();
    }
    return 0;
}
