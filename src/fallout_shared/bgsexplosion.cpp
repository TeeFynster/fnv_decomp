// fallout_shared/bgsexplosion.cpp: BGSExplosion, EffectSetting, ScalarHelper, BGSExplosionCompare and more (22 functions)

#include "../../include/BGSExplosion.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESModel.h"
#include "bgsexplosion_types_BGSExplosion.h"
#include "bgsexplosion_decls.h"

// Clears the explosion's field to 0 and calls InitExplosionData on the object returned by FUN_004fadc0.
// @fnv 0x004fade0
void BGSExplosion::ResetFormData()
{
    m_pExplosionBoundObject = 0;
    GetData_004fadc0()->InitExplosionData();
}

// @fnv 0x004fabf0
BGSExplosion::BGSExplosion()
    : TESBoundObject(), TESFullName(), TESModel(), TESEnchantableForm(), BGSPreloadable(), TESImageSpaceModifiableForm()
{
    Data.Object_ProcessAndReturnValue_004faa00();
    SetFormType((ENUM_FORM_ID)0x51);
    ResetFormData();
    TESEnchantableForm::SetCastingType((MagicSystem__CastingType)2);
}
// @fnv 0x004fae10
void BGSExplosion::InitItem()
{
    if (static_cast<TESFormInitFlag*>(static_cast<TESForm*>(this))->IsFormInitialized())
        return;

    unsigned int formID = reinterpret_cast<unsigned int>(reinterpret_cast<EffectSetting*>(this)->GetCastSound());
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        reinterpret_cast<EffectSetting*>(this)->SetCastSound(
            reinterpret_cast<TESSound*>(dynamic_cast<TESObjectLIGH*>(TESFormInitFlag::GetFormByID(formID))));
    }

    formID = reinterpret_cast<unsigned int>(reinterpret_cast<EffectSetting*>(this)->GetBoltSound());
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        reinterpret_cast<EffectSetting*>(this)->SetBoltSound(
            dynamic_cast<TESSound*>(TESFormInitFlag::GetFormByID(formID)));
    }

    formID = reinterpret_cast<PlayerMover*>(this)->GetActorStateFlags();
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        FUN_004febf0(dynamic_cast<TESSound*>(TESFormInitFlag::GetFormByID(formID)));
    }

    formID = reinterpret_cast<unsigned int>(BGSExplosion_GetImpactDataSet());
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        SetImpactDataSet_004fb0b0(dynamic_cast<BGSImpactDataSet*>(TESFormInitFlag::GetFormByID(formID)));
        if (!BGSExplosion_GetImpactDataSet())
            Warning("MASTERFILE: Could not find impact data set (%08X) for explosion '%s' (%08X).", formID, GetName(),
                    static_cast<TESForm*>(this)->GetHavokWorldObjectCountInSceneGraph_0084e3a0());
    }

    formID = reinterpret_cast<unsigned int>(m_pExplosionBoundObject);
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        m_pExplosionBoundObject = dynamic_cast<TESBoundObject*>(TESFormInitFlag::GetFormByID(formID));
        if (!m_pExplosionBoundObject)
            Warning("MASTERFILE: Could not find impact placed object (%08X) for explosion '%s' (%08X).", formID,
                    GetName(),
                    static_cast<TESForm*>(this)->GetHavokWorldObjectCountInSceneGraph_0084e3a0());
    }

    TESImageSpaceModifiableForm::InitItem(this);
    TESEnchantableForm::InitItem(this);
    SetInitializationState(true);
}

// @fnv 0x004fb0d0
bool BGSExplosion::LoadForm(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    if (formType != 0x51)
        return false;

    ClearData();
    LoadRecordHeader(file);
    SetInitializationState(false);

    int chunkID;
    while ((chunkID = file->GetChunkID()) != 0)
    {
        switch (chunkID)
        {
        case 0x44494445: {
            char* editorID = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(editorID, 0x200);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:
            TESFullNameLoader::LoadFullNameChunk(this, file);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x4d414e45:
        case 0x4d544945: {
            unsigned int value = 0;
            file->GetChunkData(&value);
            reinterpret_cast<CombatProcedure*>(reinterpret_cast<char*>(this) + 0x54)
                ->Initialize(reinterpret_cast<CombatController*>(value));
            break;
        }
        case 0x4d414e41:
        case 0x544d4145: {
            unsigned short amount = 0;
            reinterpret_cast<TESFileChunkData16*>(file)->GetChunkData(&amount);
            TESEnchantableForm::FUN_00483170(amount);
            break;
        }
        case 0x41544144:
            reinterpret_cast<BGSImpactData*>(this)->ReadTypedData(file, &Data, 0x34);
            break;
        case 0x4d414e4d: {
            unsigned int value = 0;
            file->GetChunkData(&value);
            reinterpret_cast<CombatProcedure*>(reinterpret_cast<char*>(this) + 0x68)
                ->Initialize(reinterpret_cast<CombatController*>(value));
            break;
        }
        case 0x4d414e49: {
            unsigned int value = 0;
            file->GetChunkData(&value);
            m_pExplosionBoundObject = reinterpret_cast<TESBoundObject*>(value);
            break;
        }
        }

        if (chunkID == 0x41544144 && file->IsEndianConversionRequired())
            reinterpret_cast<EndianConvertibleData*>(&Data)->Endian();

        if (!file->NextChunk())
            break;
    }

    return true;
}

// @fnv 0x004fb090
void EffectSetting::SetBoltSound(TESSound* sound)
{
    data.m_pBoltSound = sound;
}

// @fnv 0x004fb0b0
// src: XBOX_PDB 0x004fb0b0
void BGSExplosion::SetImpactDataSet_004fb0b0(BGSImpactDataSet* apImpactDataSet)
{
    Data.m_pImpactDataSet = apImpactDataSet;
}

// @fnv 0x004fb070
TESSound* EffectSetting::GetCastSound()
{
    return data.m_pCastSound;
}

// @fnv 0x004fadc0
// src: XBOX_PDB 0x004fadc0
ExplosionEffectSettings* BGSExplosion::GetData_004fadc0()
{
    return &Data;
}

// @fnv 0x004faa00
// src: GUESS 0x004faa00 (confidence: low)
ExplosionEffectSettings* __fastcall Object_ProcessAndReturnValue_004faa00(ExplosionEffectSettings* pThis)
{
    pThis->InitExplosionData();
    return pThis;
}

struct BGSExplosionData_init
{
    float f0;   // 0x00
    float f1;   // 0x04
    float f2;   // 0x08
    int i3;     // 0x0c
    int i4;     // 0x10
    int i5;     // 0x14
    float f6;   // 0x18
    int i7;     // 0x1c
    int i8;     // 0x20
    float f9;   // 0x24
    float f10;  // 0x28
    float f11;  // 0x2c
    int i12;    // 0x30
};

// Zeroes the float and int fields of the explosion data and sets i12 to 1.
// @fnv 0x004faa20
void __fastcall InitExplosionData(BGSExplosionData_init* pThis)
{
    pThis->f0 = 0.0f;
    pThis->f1 = 0.0f;
    pThis->f2 = 0.0f;
    pThis->f9 = 0.0f;
    pThis->f10 = 0.0f;
    pThis->f11 = 0.0f;
    pThis->i3 = 0;
    pThis->i4 = 0;
    pThis->i5 = 0;
    pThis->f6 = 0.0f;
    pThis->i7 = 0;
    pThis->i8 = 0;
    pThis->i12 = 1;
}

void _Deallocate(void*);
struct ScalarHelper
{
    void FUN_004fad20();
    void* FUN_004facf0(unsigned int);
};
// Calls FUN_004fad20, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x004facf0
void* ScalarHelper::FUN_004facf0(unsigned int flags)
{
    FUN_004fad20();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

int __cdecl BGSImpactDataSet_GetImpactMaterialType(int);
struct Proxy804
{
    BGSImpactData* GetImpactDataForMaterial(int);
    BGSImpactData* BGSImpactDataSet_GetImpactData(int);
};
// @fnv 0x004fb7a0
// src: XBOX_PDB 0x004fb7a0
BGSImpactData* Proxy804::BGSImpactDataSet_GetImpactData(int a)
{
    return GetImpactDataForMaterial(BGSImpactDataSet_GetImpactMaterialType(a));
}

struct FUN_004fb7a0_obj
{
    int BGSImpactDataSet_GetImpactData(int);
};
struct FUN_004fb7d0_shell
{
    int BGSExplosion_GetImpactData(int);
};
// If the explosion object returned by FUN_00516bf0 exists, forwards a to its FUN_004fb7a0 and returns the result; otherwise returns 0.
// @fnv 0x004fb7d0
// src: XBOX_PDB 0x004fb7d0
int FUN_004fb7d0_shell::BGSExplosion_GetImpactData(int a)
{
    int result = 0;
    if (((BGSExplosion*)this)->BGSExplosion_GetImpactDataSet())
        result = ((FUN_004fb7a0_obj*)((BGSExplosion*)this)->BGSExplosion_GetImpactDataSet())->BGSImpactDataSet_GetImpactData(a);
    return result;
}

struct FUN_00477950_shell : public BGSExplosion
{
    bool HasAnyFlags(unsigned int mask);
};

// @fnv 0x00477950
bool FUN_00477950_shell::HasAnyFlags(unsigned int mask)
{
    return (GetData_004fadc0()->iFlags & mask) ? true : false;
}

struct FUN_005e79a0_t
{
    bool TESForm_CompareAllComponents(TESForm* form);
};

extern "C" int memcmp(const void*, const void*, unsigned int);

struct EffectSettingShell : EffectSetting
{
    TESObjectLIGH* GetLight();
};

struct BGSExplosionCompare : BGSExplosion
{
    bool CompareTo(TESForm* form);
};

// @fnv 0x004fb610
bool BGSExplosionCompare::CompareTo(TESForm* form)
{
    BGSExplosion* pOther = dynamic_cast<BGSExplosion*>(form);
    if (!pOther)
        return true;
    if (((FUN_005e79a0_t*)this)->TESForm_CompareAllComponents(pOther))
        return true;
    if (memcmp((char*)this + 0x74, pOther->GetData_004fadc0(), 0x34))
        return true;
    if (reinterpret_cast<EffectSettingShell*>(this)->GetLight() !=
        reinterpret_cast<EffectSettingShell*>(pOther)->GetLight())
        return true;
    return false;
}

struct GlobalObject_0045cfe0
{
    int* Int();
};
struct GlobalObject2_0040c150
{
    int* Int();
};
GlobalObject2_0040c150 g_011cd3b4;
GlobalObject2_0040c150 g_011cd538;
GlobalObject2_0040c150 g_011cdde0;
struct FUN_004fb810_shell
{
    int m_00a4;
    int* BGSExplosion_GetSoundLevelValue();
};
// @fnv 0x004fb810
// src: XBOX_PDB 0x004fb810
int* FUN_004fb810_shell::BGSExplosion_GetSoundLevelValue()
{
    int result = 0;
    switch (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xa4))
    {
    case 2:
        result = ((GlobalObject_0045cfe0*)&g_011cd3b4)->Int()[0];
        break;
    case 1:
        result = ((GlobalObject_0045cfe0*)&g_011cd538)->Int()[0];
        break;
    case 0:
        result = ((GlobalObject_0045cfe0*)&g_011cdde0)->Int()[0];
        break;
    }
    return (int*)result;
}

struct FUN_004855a0
{
    void M();
};

struct DoorPart30
{
    void Save_00487010();
};

struct FUN_004891d0_obj
{
    void WriteToBuffer(unsigned int, unsigned int);
};

struct FUN_0047bd70_shell
{
    void FUN_0047bd70();
};

struct FUN_00487450_shell
{
    void FUN_00487450();
};

struct FUN_00485680
{
    void M();
};

struct FUN_00485e00_shell
{
    void TESForm___SaveData(EndianConvertibleData*, int);
};

struct FUN_004fd380_shell
{
    TESObjectLIGH* EffectSetting_GetLight();
};

bool _FUN_00401500();
void _FUN_00485910(unsigned int, unsigned int);

struct FUN_004fb3b0_shell
{
    void BGSExplosion_SaveAlt();
};

// @fnv 0x004fb3b0
// src: COMMUNITY 0x004fb3b0
void FUN_004fb3b0_shell::BGSExplosion_SaveAlt()
{
    TESSound* psaveLight;
    TESSound* psaveSound2;
    unsigned int itempint;
    BGSImpactDataSet* psaveImpact;
    unsigned int psaveSound1;

    reinterpret_cast<FUN_004855a0*>(this)->M();
    reinterpret_cast<DoorPart30*>(reinterpret_cast<unsigned char*>(this) + 0x30)->Save_00487010();
    reinterpret_cast<FUN_004891d0_obj*>(reinterpret_cast<unsigned char*>(this) + 0x3C)
        ->WriteToBuffer(0x4C444F4D, 0x54444F4D);
    reinterpret_cast<FUN_0047bd70_shell*>(reinterpret_cast<unsigned char*>(this) + 0x54)->FUN_0047bd70();
    reinterpret_cast<FUN_00487450_shell*>(reinterpret_cast<unsigned char*>(this) + 0x68)->FUN_00487450();

    psaveLight = reinterpret_cast<EffectSetting*>(this)->GetCastSound();
    reinterpret_cast<EffectSetting*>(this)->SetCastSound(
        reinterpret_cast<TESSound*>(reinterpret_cast<EffectSetting*>(this)->GetCastSound()
                                        ? reinterpret_cast<EffectSetting*>(this)->GetCastSound()->GetFormID()
                                        : 0));

    psaveSound2 = reinterpret_cast<EffectSetting*>(this)->GetBoltSound();
    reinterpret_cast<EffectSetting*>(this)->SetBoltSound(
        reinterpret_cast<TESSound*>(reinterpret_cast<EffectSetting*>(this)->GetBoltSound()
                                        ? reinterpret_cast<EffectSetting*>(this)->GetBoltSound()->GetFormID()
                                        : 0));

    itempint = reinterpret_cast<PlayerMover*>(this)->GetActorStateFlags();
    reinterpret_cast<BGSExplosion*>(this)->FUN_004febf0(reinterpret_cast<TESSound*>(
        reinterpret_cast<PlayerMover*>(this)->GetActorStateFlags()
            ? reinterpret_cast<TESForm*>(reinterpret_cast<PlayerMover*>(this)->GetActorStateFlags())->GetFormID()
            : 0));

    psaveImpact = reinterpret_cast<BGSExplosion*>(this)->BGSExplosion_GetImpactDataSet();
    reinterpret_cast<BGSExplosion*>(this)->SetImpactDataSet_004fb0b0(
        reinterpret_cast<BGSImpactDataSet*>(reinterpret_cast<BGSExplosion*>(this)->BGSExplosion_GetImpactDataSet()
                                                ? reinterpret_cast<BGSExplosion*>(this)->BGSExplosion_GetImpactDataSet()->GetFormID()
                                                : 0));

    if (_FUN_00401500())
        reinterpret_cast<EndianConvertibleData*>(reinterpret_cast<unsigned char*>(this) + 0x74)->Endian();

    reinterpret_cast<FUN_00485e00_shell*>(this)->TESForm___SaveData(
        reinterpret_cast<EndianConvertibleData*>(reinterpret_cast<unsigned char*>(this) + 0x74), 0x34);

    if (_FUN_00401500())
        reinterpret_cast<EndianConvertibleData*>(reinterpret_cast<unsigned char*>(this) + 0x74)->Endian();

    reinterpret_cast<EffectSetting*>(this)->SetCastSound(psaveLight);
    reinterpret_cast<EffectSetting*>(this)->SetBoltSound(psaveSound2);
    reinterpret_cast<BGSExplosion*>(this)->FUN_004febf0(reinterpret_cast<TESSound*>(itempint));
    reinterpret_cast<BGSExplosion*>(this)->SetImpactDataSet_004fb0b0(psaveImpact);

    if (reinterpret_cast<FUN_004fd380_shell*>(this)->EffectSetting_GetLight())
    {
        psaveSound1 = reinterpret_cast<FUN_004fd380_shell*>(this)->EffectSetting_GetLight()->GetFormID();
        _FUN_00485910(0x4D414E49, psaveSound1);
    }

    reinterpret_cast<FUN_00485680*>(this)->M();
}

class FUN_004fad20_cls : public TESBoundObject,
                         public TESFullName,
                         public TESModel,
                         public TESEnchantableForm,
                         public BGSPreloadable,
                         public TESImageSpaceModifiableForm
{
  public:
    virtual ~FUN_004fad20_cls();
};

// Empty destructor for a class deriving from TESBoundObject, TESFullName, TESModel, TESEnchantableForm, BGSPreloadable and TESImageSpaceModifiableForm.
// @fnv 0x004fad20
FUN_004fad20_cls::~FUN_004fad20_cls()
{}

// 0x00443d30 is ModelLoader::ProcessModelRequest in bgsdestructibleobjectform.cpp;
// ModelLoader has no shared header yet.
class ModelLoader
{
  public:
    void ProcessModelRequest(TESModel* model, IO_TASK_PRIORITY priority, QueuedFile* file, int resourceType,
                             bool flag, int unused, int unused2);
};

extern ModelLoader* g_modelLoader;
extern BGSExplosion* g_defaultExplosion;

int __cdecl TES_GetLODMult(TESBoundObject* object);

// 0x004fb6a0 uses TESModel at 0x3c and the impact dataset at 0x90, identifying BGSExplosion.
// Its QueueResourceLoad override is not yet declared by the shared BGSExplosion header.
class ExplosionResourceQueue : public BGSExplosion
{
  public:
    virtual void QueueResourceLoad(IO_TASK_PRIORITY priority, QueuedFile* file);
};

// The original dispatches through the inherited preloadable slot at +0x18.
struct PreloadableFormView : TESForm, BGSPreloadable
{
};

// Queues the explosion model, impact dataset, and default explosion model.
// @fnv 0x004fb6a0
void ExplosionResourceQueue::QueueResourceLoad(IO_TASK_PRIORITY priority, QueuedFile* file)
{
    if (TESModel::GetModelLength())
        g_modelLoader->ProcessModelRequest(this, priority, file, TES_GetLODMult(this), true, 0, 0);

    if (Data.m_pImpactDataSet)
        reinterpret_cast<PreloadableFormView*>(Data.m_pImpactDataSet)->QueueResourceLoad(priority, file);

    if (g_defaultExplosion && g_defaultExplosion->TESModel::GetModelLength())
        g_modelLoader->ProcessModelRequest(g_defaultExplosion, priority, file, TES_GetLODMult(this), true, 0, 0);
}

class FNVArg
{
  public:
    bool IsFlagged();
};

class FNVSub
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* v5();
};

struct FNVGlobal
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    FNVSub m_3c;
};

class FNVFactory
{
  public:
    void* Create(void* a, int b, int c, int d, int e, int f);
};

class FNVRes
{
  public:
    int Apply(void* guard);
};

class FNVGuard
{
  public:
    FNVGuard(float f);
    ~FNVGuard();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
};

extern FNVGlobal* g_pGlobal;
extern FNVFactory* g_pFactory;

struct FUN_004fb880_cls
{
    int Helper(FNVArg* a1, unsigned char a2);
    int ApplyOrCreateResult(FNVArg* a1, unsigned char a2);
};

// If the argument is not flagged, delegates to Helper; otherwise creates a result via g_pFactory and applies it with a guard, returning the result.
// @fnv 0x004fb880
int FUN_004fb880_cls::ApplyOrCreateResult(FNVArg* a1, unsigned char a2)
{
    int iResult = 0;
    unsigned char flagTmp = 0;
    {
        FNVArg* arg = a1;
        if (!arg->IsFlagged())
        {
            iResult = Helper(a1, a2);
        }
        else
        {
            void* obj = g_pGlobal->m_3c.v5();
            FNVRes* pRes = (FNVRes*)g_pFactory->Create(obj, 0, 1, 0, 0, 0);
            FNVGuard guard3(1.0f);
            if (pRes != 0)
            {
                iResult = pRes->Apply(&guard3);
            }
        }
        return iResult;
    }
}

struct BaseDtor_b4673
{
    virtual void unk00();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    ~BaseDtor_b4673();
};

struct MemberDtor_b4673
{
    virtual void unk00();
    int m_04;
    ~MemberDtor_b4673();
};

struct FUN_004fc270 : BaseDtor_b4673, MemberDtor_b4673
{
    virtual void unk30();
    ~FUN_004fc270();
};

// Destructor of FUN_004fc270; the body is empty and the base and member destructors run implicitly.
// @fnv 0x004fc270
FUN_004fc270::~FUN_004fc270()
{}

#include <string.h>
struct FUN_005e78f0_t
{
    void TESForm_CopyAllComponents(TESForm*);
};
struct EffectSetting_shell : EffectSetting
{
    TESObjectLIGH* GetLight();
    void SetLight(TESObjectLIGH*);
};
struct BGSExplosion_shell : BGSExplosion
{
    void __thiscall BGSExplosion_Copy(TESForm* apCopy);
};
// Copies explosion data from apCopy into this, including base fields, a 0x34-byte block, and the associated light.
// @fnv 0x004fb5a0
// src: XBOX_PDB 0x004fb5a0
void __thiscall BGSExplosion_shell::BGSExplosion_Copy(TESForm* apCopy)
{
    BGSExplosion* pcopy = dynamic_cast<BGSExplosion*>(apCopy);
    if (!pcopy)
        return;
    ((FUN_005e78f0_t*)this)->TESForm_CopyAllComponents(pcopy);
    memcpy(GetData_004fadc0(), pcopy->GetData_004fadc0(), 0x34);
    ((EffectSetting_shell*)this)->SetLight(((EffectSetting_shell*)pcopy)->GetLight());
}
