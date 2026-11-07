// fallout_shared/tescreature.cpp: creature records and actor components (55 functions)

#include "../../include/TESCreature.h"
#include "../../include/CreatureSounds.h"
#include "../../include/TESModelList.h"
#include "../../include/TESNPC.h"
#include "../../include/BGSBodyPartData.h"
#include "../../include/TESSpellList.h"
#include "../../include/BGSDestructibleObjectForm.h"
#include "../../include/CombatProcedure.h"
#include "../../include/TESAIForm.h"
#include "../../include/TESActorBaseData.h"
#include "../../include/TESAnimation.h"
#include "../../include/TESAttackDamageForm.h"
#include "../../include/TESAttributes.h"
#include "../../include/TESBoundAnimObject.h"
#include "../../include/TESContainer.h"
#include "../../include/TESDataHandler.h"
#include "../../include/TESHealthForm.h"
#include "../../include/TESModel.h"
#include "../../include/TESScriptableForm.h"
#include "../../include/Actor.h"
#include "../../include/BGSSaveFormBuffer.h"
#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/BGSSaveLoadGame.h"
#include "../../include/BaseProcess.h"
#include "../../include/MiddleHighProcess.h"
#include "../../include/MobileObject.h"
#include "../../include/TESFullName.h"
#include "../../include/BGSPreloadable.h"
#include "../../include/BaseFormComponent.h"
#include "../../include/InventoryChanges.h"

class TESCombatStyle;
class BGSImpactDataSet;
class BGSListForm;

extern "C" const float gCreatureFootWeight;
extern "C" char gVtable_TESCreature;
extern "C" char gVtable_30;
extern "C" char gVtable_64;
extern "C" char gVtable_70;
extern "C" char gVtable_7c;
extern "C" char gVtable_90;
extern "C" char gVtable_b0;
extern "C" char gVtable_b8;
extern "C" char gVtable_c4;
extern "C" char gVtable_d0;
extern "C" char gVtable_dc;
extern "C" char gVtable_f4;
extern "C" char gVtable_100;
extern "C" char gVtable_104;
extern "C" char gVtable_10c;
extern "C" char gVtable_114;
extern "C" char gDestructorEhHandler;
extern "C" void FnvActorBaseCtorAlias();
extern "C" void FnvAttackCtorAlias();
extern "C" void FnvClearDataAlias();
extern "C" void FnvModelListDtorAlias();
extern "C" void FnvAttackDtorAlias();
extern "C" void FnvActorBaseDtorAlias();
extern "C" unsigned int __security_cookie;

#include "../../include/ENUM_FORM_ID.h"
extern TESDataHandlerTypes::TESFaction* DAT_011cb550;

extern TESDataHandler* g_dataHandler;



// @fnv 0x005F7900
TESCreature::~TESCreature()
{
    ClearData();
}

// @fnv 0x005F7B80
void TESCreature::ClearData()
{
    if (((TESActorBaseData*)((char*)this + 0x30))->GetFlag(0x100))
    {
        delete m_pCreatureSounds;
        m_pCreatureSounds = 0;
    }
    m_cCreatureDataFlag = 0xff;
}

// @fnv 0x005F7A40
void TESCreature::ResetFormData()
{
    dataPadding = 0;
    m_ucField00 = 50;
    m_ucField01 = 50;
    m_ucField02 = 50;
    m_ucCreatureType = 32;
    m_pImpactDataSet = 0;
    m_pCreatureListForm = 0;
    m_fFirstCreatureStat = 0.0f;
    m_fSecondCreatureStat = gCreatureFootWeight;
    m_fThirdCreatureStatCur = 1.0f;
    m_pCreatureSounds = 0;
    m_pCombatStyle = 0;
    m_pBodyPartDataCur = 0;
    m_bHasImpactDataSet = false;
    m_eSoundLevel = (SOUND_LEVEL)1;
    m_eImpactMaterial = (BGSImpactDataSet__IMPACT_MATERIAL_TYPE)6;
    m_cCreatureDataFlag = 0xff;
    ((TESActorBaseData*)((char*)this + 0x30))->UpdateFlagBit(0x40, true, false);
    ((TESActorBaseData*)((char*)this + 0x30))->UpdateFlagBit(false, false);
    ((CombatProcedure*)((char*)this + 0xb0))->Initialize((CombatController*)0x32);
}

// @fnv 0x005F9210
CreatureSounds* TESCreature::GetMutableCreatureSounds()
{
    if (!((TESActorBaseData*)((char*)this + 0x30))->GetFlag(0x100) || !m_pCreatureSounds)
    {
        ((TESActorBaseData*)((char*)this + 0x30))->UpdateFlagBit(0x100, true, true);
        m_pCreatureSounds = new CreatureSounds;
    }
    return m_pCreatureSounds;
}

// @fnv 0x005FB3B0
void TESCreature::LoadGame(BGSLoadFormBuffer* buffer)
{
    ((TESActorBase*)this)->TESActorBase::LoadGame(buffer);
    if (buffer->GetChangeFlags(0x200u).operator bool())
    {
        buffer->ReadTypedData(&m_ucField00, 1u);
        buffer->ReadTypedData(&m_ucField01, 1u);
        buffer->ReadTypedData(&m_ucField02, 1u);
    }
}

// @fnv 0x005F9140
void TESCreature::SetCreatureSoundsFrom(TESCreature* soundCreature)
{
    if (((TESActorBaseData*)((char*)this + 0x30))->GetFlag(0x100))
    {
        if (soundCreature)
        {
            delete m_pCreatureSounds;
            ((TESActorBaseData*)((char*)this + 0x30))->UpdateFlagBit(0x100, false, true);
            m_pCreature = soundCreature;
        }
    }
    else
    {
        m_pCreature = soundCreature;
    }
}

// @fnv 0x005FA2E0
BGSBodyPartData* TESCreature::GetBodyPartData() const
{
    if (m_pBodyPartDataCur)
        return m_pBodyPartDataCur;
    return BGSBodyPartData::ms_pBodyPartData;
}

// @fnv 0x005FA310
void TESCreature::SetBodyPartData(BGSBodyPartData* bodyPartData)
{
    m_pBodyPartDataCur = bodyPartData;
}

// @fnv 0x005FB430
void TESCreature::Revert(BGSLoadFormBuffer* buffer)
{
    ((TESNPC*)this)->TESNPC::Revert(buffer);
}

// @fnv 0x005F7230
TESCreature::TESCreature()
{
    ((TESForm*)this)->SetFormType(ENUM_FORM_ID_CREA_ID);
    ResetFormData();
    ((TESAIForm*)((char*)this + 0x90))->SetResponsibility(50, false);
    ((TESAIForm*)((char*)this + 0x90))->SetAggression(1, false);
    ((TESAIForm*)((char*)this + 0x90))->SetConfidence(2, false);
    ((TESAIForm*)((char*)this + 0x90))->SetEnergy(2, false);
    if (!g_dataHandler->FUN_004516b0())
        ((TESActorBaseData*)((char*)this + 0x30))->SetFactionRank(DAT_011cb550, 0);
}

struct BGSImpactDataSet;
struct QueuedFile;
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
typedef char _sizecheck_BGSPreloadable[sizeof(BGSPreloadable) == 4 ? 1 : -1];

// @fnv 0x005f8bb0
void TESCreature::SetImpactDataSet(BGSImpactDataSet* apSet)
{
    m_pImpactDataSet = apSet;
}

// Returns the TESCreature at offset 0x128 unless the actor base data has flag 0x100 set, in which case it returns 0.
// @fnv 0x005f9100
TESCreature* TESCreature::GetSoundCreature()
{
    if (((TESActorBaseData*)((char*)this + 0x30))->GetFlag(0x100))
    {
        return 0;
    }
    else
    {
        return *(TESCreature**)((char*)this + 0x128);
    }
}

// @fnv 0x005f91d0
CreatureSounds* TESCreature::GetCreatureSounds()
{
    if (((TESActorBaseData*)((char*)this + 0x30))->GetFlag(0x100))
        return *(CreatureSounds**)((char*)this + 0x128);
    else
        return 0;
}

// @fnv 0x005f9ad0
// src: COMMUNITY 0x005f9ad0
unsigned char TESCreature::ShadowSceneNode_GetDisableLightUpdate()
{
    return m_ucCreatureType;
}

// @fnv 0x005f9af0
void TESCreature::SetCreatureType(unsigned char acVal)
{
    m_ucCreatureType = acVal;
}

struct BGSImpactDataSet;

// @fnv 0x005f9b30
BGSImpactDataSet* TESCreature::GetImpactDataSet()
{
    return m_pImpactDataSet;
}

// @fnv 0x005fa2c0
void TESCreature::SetByteAt12D(unsigned char aiVal)
{
    *((unsigned char*)this + 0x12d) = aiVal;
}

// @fnv 0x005fbdb0
// src: GUESS 0x005fbdb0 (confidence: medium)
void TESCreature::SetTypeAtOffset12C(unsigned char aeType)
{
    *((char*)this + 0x12c) = aeType;
}

// @fnv 0x00821660
// src: COMMUNITY 0x00821660
float TESCreature::GetFootWeight()
{
    return m_fSecondCreatureStat;
}

struct NiFormArray;
struct TESIdleForm;
struct TESObject;
struct TESObjectREFR;
struct IdleAnimationManager
{
    void RemoveIdleForm(TESIdleForm*);
    void InitializeIdleAnimations();
    void ResetIdleAnimations();
    void LoadIdleAnimations();
    NiFormArray* AddRootIdleArray(TESForm*);
    NiFormArray* AddRootIdleArray(char*, void*, bool);
    NiFormArray* GetRootIdleArray(TESForm*);
    NiFormArray* GetRootIdleArray(char*);
    NiFormArray* GetIdleArray(TESForm*);
    NiFormArray* GetIdleArray(char*);
    static void BuildIdlePath(char*, char*);
    void* FindIdleArrayEntry(char*, int);
    void ClearIdleData();
    static TESObject* GetCurrentUsedItem();
    static void SetUsedItem(TESObject*);
    static void SetUsedItemLevel(int);
    static int GetUsedItemLevel();
    static void SetUsedItemActivate(bool);
    static bool GetUsedItemActivate();
    bool GetInitialized();
    TESIdleForm* FindIdleFormForObject(TESObjectREFR*, TESObjectREFR*);
    void* __vecDelDtor(unsigned int);
    char m_acIdlePath[20];
    bool bInitialized;
    char _pad_15[3];
    char m_acIdleName[16];
};
typedef char _sizecheck_TESIdleManager[sizeof(IdleAnimationManager) == 40 ? 1 : -1];
struct FUN_00843150_shell : public IdleAnimationManager
{
    bool InterfaceManager_GetMagicPageNumber();
};

// @fnv 0x00843150
// src: COMMUNITY 0x00843150
bool FUN_00843150_shell::InterfaceManager_GetMagicPageNumber()
{
    return bInitialized;
}

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_005f75b0(unsigned int flags);
};
// Runs the destructor on this object, then frees it with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x005f75b0
void* DelStandIn::FUN_005f75b0(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

struct FUN_0050f760_shell
{
    int TESBoundObject_ReplaceModel_0050f600(int);
    int TESBoundAnimObject_ReplaceModel(int);
};
// @fnv 0x0050f760
// src: XBOX_PDB 0x0050f760
int FUN_0050f760_shell::TESBoundAnimObject_ReplaceModel(int a)
{
    return TESBoundObject_ReplaceModel_0050f600(a);
}

struct FUN_0051f4b0_shell
{
    void TESCreature_SetMaterialType(int value);
};

// @fnv 0x0051f4b0
// src: COMMUNITY 0x0051f4b0
void FUN_0051f4b0_shell::TESCreature_SetMaterialType(int value)
{
    *(int*)((char*)this + 0x118) = value;
}

struct FUN_005f7460_shell
{
    void TESActorBase_GetLevel();
};

// @fnv 0x005f7460
// src: COMMUNITY 0x005f7460
void FUN_005f7460_shell::TESActorBase_GetLevel()
{
    ((TESActorBaseData*)((char*)this - 0xd0))->TESActorBaseData_GetLevel();
}

struct FUN_005f7570_shell
{
    void* TESActorBase_GetActor();
};
// @fnv 0x005f7570
// src: COMMUNITY 0x005f7570
void* FUN_005f7570_shell::TESActorBase_GetActor()
{
    return (char*)this - 0x100;
}

struct FUN_005f9040_shell : public TESActorBaseData
{
    bool TESCreature_GetNoLeftArm();
};
// @fnv 0x005f9040
// src: COMMUNITY 0x005f9040
bool FUN_005f9040_shell::TESCreature_GetNoLeftArm()
{
    return GetFlag(0x20000);
}

struct FUN_005f9060_shell : public TESActorBaseData
{
    bool TESCreature_GetNoRightArn();
};
// @fnv 0x005f9060
// src: COMMUNITY 0x005f9060
bool FUN_005f9060_shell::TESCreature_GetNoRightArn()
{
    return GetFlag(0x10000);
}

struct FUN_005f9080_shell : public TESActorBaseData
{
    bool TESNPC_GetNoHead();
};
// @fnv 0x005f9080
// src: COMMUNITY 0x005f9080
bool FUN_005f9080_shell::TESNPC_GetNoHead()
{
    return GetFlag(0x8000);
}

struct FUN_005f90a0_shell : public TESActorBaseData
{
    bool TESCreature_GetNoShadow();
};
// @fnv 0x005f90a0
// src: COMMUNITY 0x005f90a0
bool FUN_005f90a0_shell::TESCreature_GetNoShadow()
{
    return GetFlag(0x80000);
}

extern int DAT_01000000;

struct CreatureFlagQueries
{
    bool HasFlag01000000();
    bool HasFlag02000000();
};

// @fnv 0x005f90c0
bool CreatureFlagQueries::HasFlag01000000()
{
    return ((TESActorBaseData*)((char*)this + 0x30))->GetFlag((unsigned int)&DAT_01000000);
}

// @fnv 0x005f90e0
bool CreatureFlagQueries::HasFlag02000000()
{
    return ((TESActorBaseData*)((char*)this + 0x30))->GetFlag(0x2000000);
}

// @fnv 0x005f9b10
void TESCreature::SetBoltSmallWidth(float afBoltSmallWidth)
{
    *(float*)((char*)this + 0x138) = afBoltSmallWidth;
}

// @fnv 0x005f9b70
const void* TESCreature::GetOffset12C()
{
    return (char*)this + 0x12c;
}

namespace ActorValue
{
    bool IsSkill(Index);
    unsigned char ToArrayIndex(int, Index);
};
struct FUN_006078e0_s
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void SetFlags(int);
    void ApplyCommand(ActorValue::Index, int);
    void TESNPC_SetActorValueI(ActorValue::Index aiWhich, int aiValue);
};
// Stores a skill actor value as a byte at offset 0x114 and sets flag 0x200, otherwise forwards to ApplyCommand.
// @fnv 0x006078e0
// src: COMMUNITY 0x006078e0
void FUN_006078e0_s::TESNPC_SetActorValueI(ActorValue::Index aiWhich, int aiValue)
{
    if (ActorValue::IsSkill(aiWhich))
    {
        reinterpret_cast<unsigned char*>(this)[0x114 + (char)ActorValue::ToArrayIndex(2, aiWhich)] =
            (unsigned char)aiValue;
        SetFlags(0x200);
    }
    else
    {
        ApplyCommand(aiWhich, aiValue);
    }
}

struct FUN_008126e0_shell
{
    void SetWhich(int aiWhich);
};

// @fnv 0x008126e0
void FUN_008126e0_shell::SetWhich(int aiWhich)
{
    *(int*)((char*)this + 0x140) = aiWhich;
}

struct FUN_005f8f10_shell : TESActorBaseData
{
    unsigned short GetFatigue();
    bool GetMatchesPCLevel();
    unsigned short TESActorBaseData_GetLevel();
    unsigned short GetScaledFatigue();
};

// Returns fatigue, multiplied by FUN_0047ded0 (clamped to at least 1) when GetMatchesPCLevel is true.
// @fnv 0x005f8f10
unsigned short FUN_005f8f10_shell::GetScaledFatigue()
{
    unsigned short fatigue = GetFatigue();
    if (GetMatchesPCLevel())
    {
        short value = TESActorBaseData_GetLevel();
        if (value < 1)
            value = 1;
        fatigue = (unsigned short)(value * (unsigned short)fatigue);
    }
    return fatigue;
}

struct FUN_005f7420_shell
{
    virtual void _v0();
    virtual double _v1(int);
    virtual void _v2();
    virtual void _v3();
    virtual void _v4();
    virtual void _v5();
    virtual double _v6(int);
    float GetSumOfVirtualValues(int);
};
// Returns the sum of the two virtual calls _v1 and _v6 for the given index, cast to float.
// @fnv 0x005f7420
float FUN_005f7420_shell::GetSumOfVirtualValues(int aiWhich)
{
    return (float)(_v1(aiWhich) + _v6(aiWhich));
}

struct FUN_005f78b0_shell
{
    void* DestroyActorBase(unsigned int);
};
// Destructs the TESActorBase and, if flags has bit 0 set, frees the object with operator delete; returns this.
// @fnv 0x005f78b0
void* FUN_005f78b0_shell::DestroyActorBase(unsigned int flags)
{
    ((TESActorBase*)this)->TESActorBase::~TESActorBase();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_005f8e90_shell : public TESActorBaseData
{
    int TESCreature_TESHealthForm_getNext_get004();
    int _ref_00726070();
    bool GetMatchesPCLevel();
    short TESActorBaseData_GetLevel();
};

// @fnv 0x005f8e90
// src: COMMUNITY 0x005f8e90
int FUN_005f8e90_shell::TESCreature_TESHealthForm_getNext_get004()
{
    unsigned short result = 0;
    if (reinterpret_cast<FUN_005f8e90_shell*>(reinterpret_cast<char*>(this) - 0x80)->GetMatchesPCLevel())
    {
        short factor = reinterpret_cast<FUN_005f8e90_shell*>(reinterpret_cast<char*>(this) - 0x80)->TESActorBaseData_GetLevel();
        if (factor < 1)
            factor = 1;
        result = factor * _ref_00726070();
    }
    else
    {
        result = _ref_00726070();
    }
    return result;
}

struct FUN_005f16f0_shell
{
    unsigned short GetSaveSize_005f16f0(unsigned int);
};
struct CreatureSaveSize : FUN_005f16f0_shell
{
    unsigned short GetSaveSize(unsigned int);
};
// @fnv 0x005fb180
unsigned short CreatureSaveSize::GetSaveSize(unsigned int aiFlags)
{
    unsigned short isize = 0;
    isize += GetSaveSize_005f16f0(aiFlags);
    if (aiFlags & 0x200)
        isize += 3;
    if (aiFlags & 0)
        isize += 4;
    return isize;
}

struct FUN_005f1f30_shell
{
    void __thiscall SaveGame_005f1f30(BGSSaveFormBuffer*);
};
// Calls FUN_005f1f30, then if change flag 0x200 is set saves three bytes at offsets 0x12d, 0x12e and 0x12f into the buffer.
// @fnv 0x005fb330
void TESCreature::SaveGame(BGSSaveFormBuffer* buffer)
{
    ((FUN_005f1f30_shell*)this)->SaveGame_005f1f30(buffer);
    if (buffer->GetChangeFlags(0x200u).operator bool())
    {
        buffer->SaveData((char*)this + 0x12d, 1, 0);
        buffer->SaveData((char*)this + 0x12e, 1, 0);
        buffer->SaveData((char*)this + 0x12f, 1, 0);
    }
}

float __cdecl floorf(float);
struct FUN_005f73f0_Holder
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual float v8(int);
    int ConvertVirtualResultToInt(int);
};
// Calls the virtual v8 with a and converts the returned float to int via FUN_00406ce0.
// @fnv 0x005f73f0
int FUN_005f73f0_Holder::ConvertVirtualResultToInt(int a)
{
    return (int)floorf(v8(a));
}

struct FakeAVOwner
{
    virtual void b0() = 0;
    virtual void b1() = 0;
    virtual void b2() = 0;
    virtual float GetAV(int) = 0;
};
struct FakePrimary
{
    virtual void a0() = 0;
    virtual void a1() = 0;
    virtual void a2() = 0;
    virtual void a3() = 0;
    virtual void a4() = 0;
    virtual void a5() = 0;
    virtual void a6() = 0;
    virtual void a7() = 0;
    virtual void a8() = 0;
    virtual void a9() = 0;
    virtual void a10() = 0;
    virtual void a11() = 0;
    virtual void a12() = 0;
    virtual void a13() = 0;
    virtual void a14() = 0;
    virtual void a15() = 0;
    virtual void a16() = 0;
    virtual void a17() = 0;
    virtual void a18() = 0;
    virtual void a19() = 0;
    virtual void a20() = 0;
    virtual void a21() = 0;
    virtual void a22() = 0;
    virtual void a23() = 0;
    virtual void a24() = 0;
    virtual void a25() = 0;
    virtual void a26() = 0;
    virtual void a27() = 0;
    virtual void a28() = 0;
    virtual void a29() = 0;
    virtual void a30() = 0;
    virtual void a31() = 0;
    virtual void a32() = 0;
    virtual void a33() = 0;
    virtual void a34() = 0;
    virtual void a35() = 0;
    virtual void a36() = 0;
    virtual void a37() = 0;
    virtual void a38() = 0;
    virtual void a39() = 0;
    virtual void a40() = 0;
    virtual void a41() = 0;
    virtual void a42() = 0;
    virtual void a43() = 0;
    virtual void a44() = 0;
    virtual void a45() = 0;
    virtual void a46() = 0;
    virtual void a47() = 0;
    virtual void a48() = 0;
    virtual void a49() = 0;
    virtual void a50() = 0;
    virtual void a51() = 0;
    virtual void a52() = 0;
    virtual void a53() = 0;
    virtual void a54() = 0;
    virtual void a55() = 0;
    virtual void a56() = 0;
    virtual void a57() = 0;
    virtual void a58() = 0;
    virtual void a59() = 0;
    virtual void a60() = 0;
    virtual void a61() = 0;
    virtual void a62() = 0;
    virtual void a63() = 0;
    virtual void a64() = 0;
    virtual void a65() = 0;
    virtual void a66() = 0;
    virtual void a67() = 0;
    virtual void a68() = 0;
    virtual void a69() = 0;
    virtual void a70() = 0;
    virtual void a71() = 0;
    virtual void a72() = 0;
    virtual void a73() = 0;
    virtual void a74() = 0;
    virtual void a75() = 0;
    virtual void a76() = 0;
    virtual void a77() = 0;
    virtual void a78() = 0;
    virtual void a79() = 0;
    virtual void a80() = 0;
    virtual void a81() = 0;
    virtual void a82() = 0;
    virtual void a83() = 0;
    virtual void a84() = 0;
    virtual void a85() = 0;
    virtual void a86() = 0;
    virtual void a87() = 0;
    virtual void a88() = 0;
    virtual void a89() = 0;
    virtual void a90() = 0;
    virtual void a91() = 0;
    virtual void a92() = 0;
    virtual void a93() = 0;
    virtual void a94() = 0;
    virtual void a95() = 0;
    virtual void a96() = 0;
    virtual void a97() = 0;
    virtual void a98() = 0;
    virtual void a99() = 0;
    virtual void SetAV(int, float) = 0;
    char _pad[252];
};
struct StandIn : FakePrimary, FakeAVOwner
{
    void TESActorBase_ModActorValue(int, float);
};
// Adds aiValue to the actor value aiWhich by reading GetAV and writing the sum back with SetAV.
// @fnv 0x005f7520
// src: COMMUNITY 0x005f7520
void StandIn::TESActorBase_ModActorValue(int aiWhich, float aiValue)
{
    SetAV(aiWhich, GetAV(aiWhich) + aiValue);
}


// The approved touch-spell destructor adds EH cleanup to this actor-base constructor.
class ActorBaseTouchSpellComponent
{
public:
    ActorBaseTouchSpellComponent();
    virtual void vfn_00() = 0;
    unsigned char componentLayout[8];
};

struct FUN_005f75e0 : public TESBoundAnimObject,
                      public TESActorBaseData,
                      public TESContainer,
                      public ActorBaseTouchSpellComponent,
                      public TESSpellList,
                      public TESAIForm,
                      public TESHealthForm,
                      public TESAttributes,
                      public TESAnimation,
                      public TESFullName,
                      public TESModel,
                      public TESScriptableForm,
                      public ActorValueOwner,
                      public BGSDestructibleObjectForm
{
    FUN_005f75e0();
};

// Empty constructor that initializes the object's base subobjects.
// @fnv 0x005f75e0
FUN_005f75e0::FUN_005f75e0()
{}

struct FUN_005f0b30_shell
{
    void SetHealth_005f0b30(int);
};

struct FUN_005f12d0_shell : public FUN_005f0b30_shell
{
    void ApplyCommand(int, int);
};

// Dispatches a command code to the matching setter on the AI form, mood form, actor base or base shell, passing value as the argument.
// @fnv 0x005f12d0
void FUN_005f12d0_shell::ApplyCommand(int command, int value)
{
    switch (command)
    {
    case 5:
        ((TESAttributes*)((char*)this + 0xb8))->SetStrength((unsigned char)value);
        break;
    case 6:
        ((TESAttributes*)((char*)this + 0xb8))->SetPerception((unsigned char)value);
        break;
    case 7:
        ((TESAttributes*)((char*)this + 0xb8))->SetEndurance((unsigned char)value);
        break;
    case 8:
        ((TESAttributes*)((char*)this + 0xb8))->SetCharisma((unsigned char)value);
        break;
    case 9:
        ((TESAttributes*)((char*)this + 0xb8))->SetIntelligence((unsigned char)value);
        break;
    case 10:
        ((TESAttributes*)((char*)this + 0xb8))->SetAgility((unsigned char)value);
        break;
    case 11:
        ((TESAttributes*)((char*)this + 0xb8))->SetLuck((unsigned char)value);
        break;
    case 16:
        this->SetHealth_005f0b30(value);
        break;
    case 0:
        ((TESAIForm*)((char*)this + 0x90))->SetAggression((unsigned char)value, true);
        break;
    case 1:
        ((TESAIForm*)((char*)this + 0x90))->SetConfidence((unsigned char)value, true);
        break;
    case 2:
        ((TESAIForm*)((char*)this + 0x90))->SetEnergy((unsigned char)value, true);
        break;
    case 3:
        ((TESAIForm*)((char*)this + 0x90))->SetResponsibility((unsigned char)value, true);
        break;
    case 4:
        ((TESAIForm*)((char*)this + 0x90))->SetAIMood((unsigned char)value);
        break;
    case 21:
        ((TESActorBaseData*)((char*)this + 0x30))->SetSpeedMult((unsigned short)value);
        break;
    case 23:
        ((TESActorBaseData*)((char*)this + 0x30))->SetKarmaValue((float)value);
        break;
    default:
        break;
    }
}

namespace fnv_005fa200 {

struct P09AV
{
    static bool __cdecl GetFlag(int flag, unsigned int value);
};

struct FUN_006078e0_s
{
    void ApplyCommand(ActorValue::Index index, int value);
};

// @fnv 0x005fa200
}  // namespace fnv_005fa200

void TESCreature::SetActorValueI(ActorValue::Index index, int value)
{
    if (fnv_005fa200::P09AV::GetFlag(index, 0x400))
    {
        SetByteAt12D(static_cast<unsigned char>(value));
        MarkAsModified(0x200);
    }
    else
    {
        switch (index)
        {
        case static_cast<ActorValue::Index>(0x38):
            if (value < 0)
            {
                reinterpret_cast<TESAttackDamageForm*>(reinterpret_cast<char*>(this) + 0x10c)->SetAttackDamage(0);
            }
            else if (value > 0xffff)
            {
                reinterpret_cast<TESAttackDamageForm*>(reinterpret_cast<char*>(this) + 0x10c)->SetAttackDamage(0xffff);
            }
            else
            {
                reinterpret_cast<TESAttackDamageForm*>(reinterpret_cast<char*>(this) + 0x10c)
                    ->SetAttackDamage(static_cast<unsigned short>(value));
            }
            break;

        default:
            reinterpret_cast<fnv_005fa200::FUN_006078e0_s*>(this)->ApplyCommand((ActorValue::Index)index, value);
            break;
        }
    }
}

struct FUN_00608e00_shell
{
    void SaveGame_005f18c0(unsigned int);
};

struct PC7d
{
    void TESForm_SaveGameDataOLD(unsigned int, int);
};

struct FUN_00484d20_Class
{
    void ForwardToSaveLoadGame(int, int);
};

unsigned int __fastcall _ref_0084e3a0(unsigned int);

// @fnv 0x005fb1e0
void TESCreature::SaveGameLegacy(unsigned int flags)
{
    reinterpret_cast<FUN_00608e00_shell*>(this)->SaveGame_005f18c0(flags);

    if (flags & 0x200)
    {
        reinterpret_cast<PC7d*>(this)->TESForm_SaveGameDataOLD(
            reinterpret_cast<unsigned int>(reinterpret_cast<unsigned char*>(this) + 0x12d), 1);
        reinterpret_cast<PC7d*>(this)->TESForm_SaveGameDataOLD(
            reinterpret_cast<unsigned int>(reinterpret_cast<unsigned char*>(this) + 0x12e), 1);
        reinterpret_cast<PC7d*>(this)->TESForm_SaveGameDataOLD(
            reinterpret_cast<unsigned int>(reinterpret_cast<unsigned char*>(this) + 0x12f), 1);
    }

    if (flags & 0)
    {
        unsigned int result =
            _ref_0084e3a0(*reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0x140));
        reinterpret_cast<FUN_00484d20_Class*>(this)->ForwardToSaveLoadGame(reinterpret_cast<int>(&result), 4);
    }
}


class FUN_005f77b0
{
  public:
    TESBoundAnimObject m_0;
    TESActorBaseData m_30;
    TESContainer m_64;
    unsigned char touchSpellLayout[12];
    TESSpellList m_7c;
    TESAIForm m_90;
    TESHealthForm m_b0;
    TESAttributes m_b8;
    TESAnimation m_c4;
    TESFullName m_d0;
    TESModel m_dc;
    unsigned char scriptableAndActorValueLayout[16];
    BGSDestructibleObjectForm m_104;
    ~FUN_005f77b0();
};

// @fnv 0x005f77b0
FUN_005f77b0::~FUN_005f77b0()
{}

struct FormObj_5f7c20
{
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};

// Save is not yet declared by the shared CreatureSounds header.
extern "C" void SaveCreatureSounds();



struct Sub70_5f7c20
{
    int u00, u04, u08;
    void FUN_0047bd70();
};

struct Subd0_5f7c20
{
    int u00, u04, u08;
    void Save_00487010();
};

struct Sub12c_5f7c20
{
    int u00;
    void FUN_00483710();
};

bool __cdecl TESForm_QEndianSwapOnSave();
void __cdecl TESForm_AddChunk_3(unsigned int, unsigned char);
void __cdecl TESForm_AddChunk_00485910(unsigned int, unsigned int);
void __cdecl TESForm_AddChunk_00485910(unsigned int, float);
void __cdecl TESForm_AddChunk_00485910(unsigned int, int);

// @fnv 0x005f7c20
void TESCreature::SaveForm()
{
    BeginFormRecord();
    TESFullName::Save_00487010();
    TESModel::WriteToBuffer(0x4c444f4d, 0x54444f4d);
    TESSpellList::TESSpellList_SaveSubRecord();
    ((Sub70_5f7c20*)((char*)this + 0x70))->FUN_0047bd70();
    TESModelList::CopyModelListToBuffer(0x5a46494e, 0x5446494e);
    TESActorBaseData::Save();
    BGSDestructibleObjectForm::Save();
    if (TESForm_QEndianSwapOnSave())
    {
        ((Sub12c_5f7c20*)&Data)->FUN_00483710();
    }
    TESForm___SaveData(&Data, 4);
    if (TESForm_QEndianSwapOnSave())
    {
        ((Sub12c_5f7c20*)&Data)->FUN_00483710();
    }
    TESForm_AddChunk_3(0x4d414e52, m_ucCreatureType);
    if (((const TESActorBase*)this)->GetCombatStyle())
    {
        TESForm_AddChunk_00485910(0x4d414e5a, ((TESForm*)((const TESActorBase*)this)->GetCombatStyle())->GetHavokWorldObjectCountInSceneGraph_0084e3a0());
    }
    if (((const TESActorBase*)this)->GetBodyPartData())
    {
        TESForm_AddChunk_00485910(0x4d414e50, ((const TESActorBase*)this)->GetBodyPartData()->GetHavokWorldObjectCountInSceneGraph_0084e3a0());
    }
    TESForm_AddChunk_00485910(0x4d414e54, m_fFirstCreatureStat);
    TESForm_AddChunk_00485910(0x4d414e42, m_fThirdCreatureStatCur);
    TESForm_AddChunk_00485910(0x4d414e57, m_fSecondCreatureStat);
    TESForm_AddChunk_00485910(0x344d414e, (int)m_eImpactMaterial);
    TESForm_AddChunk_00485910(0x354d414e, (int)m_eSoundLevel);
    if (TESActorBaseData::GetFlag(0x100))
    {
        CreatureSounds* sounds = GetCreatureSounds();
        if (sounds)
        {
            __asm
            {
                mov ecx, sounds
                call SaveCreatureSounds
            }
        }
    }
    else
    {
        TESCreature* soundCreature = GetSoundCreature();
        if (soundCreature)
        {
            unsigned int soundId = soundCreature->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            TESForm_AddChunk_00485910(0x52435343, soundId);
        }
    }
    if (m_pImpactDataSet)
    {
        unsigned int impactId = ((TESForm*)m_pImpactDataSet)->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
        TESForm_AddChunk_00485910(0x4d414e43, impactId);
    }
    if (m_pCreatureListForm)
    {
        unsigned int weaponId = ((TESForm*)m_pCreatureListForm)->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
        TESForm_AddChunk_00485910(0x4d414e4c, weaponId);
    }
    FinishFormRecord();
}

extern "C" void* _alloca(unsigned int);
void* operator new(unsigned int);
void operator delete(void*);
void* ourMemset(void*, int, unsigned int);
struct CreatureRecordFile
{
    unsigned char FUN_00472660();
    int TESFile_GetTESChunk();
    bool FUN_004726f0();
    unsigned int GetField25C();
    bool FUN_00401680();
    unsigned short FUN_00403570();
    void FUN_00472890(void*, unsigned int);
    void ReadChunkInt(void*);
    void ReadChunkData(void*);
};
struct CreatureContainerEntry
{
    unsigned int form;
    int count;
    void TwoValues_Endian();
};
struct CreatureFactionEntry
{
    unsigned int faction;
    unsigned char rank;
    unsigned char unk05;
    unsigned short unk06;
    void QuestPerkEntryData_Endian();
};
struct CreatureAIData
{
    unsigned char aggression, confidence, energy, responsibility;
    unsigned int services;
    unsigned char trainingSkill, trainingLevel;
    unsigned short unk0A;
    unsigned char unk0C, unk0D, mood, unk0F;
    unsigned int unk10;
    void SwapEndianFields();
};
struct FUN_0040e690
{
    unsigned int owner, global, condition;
    FUN_0040e690();
    void FUN_0040e780(CreatureRecordFile*);
};
struct LastContainerItem
{
    unsigned int object;
    unsigned int count;
    FUN_0040e690* extra;
};
extern LastContainerItem* DAT_011cb5f8;
struct CreatureTypedDataReader
{
    void Read(TESFile*, void*, unsigned int);
};
extern const char DAT_0104947c[];
void Warning_005b5e40(const char*, ...);
// Reads a creature record from the file, dispatching each chunk to the matching component loader, and returns true when the record type is 43.
// @fnv 0x005f7ec0
bool TESCreature::LoadForm(TESFile* file)
{
    unsigned char formType = ((CreatureRecordFile*)file)->FUN_00472660();
    if (formType != 43)
        return false;
    TESForm::FUN_00485110(file);
    SetInitializationState(false);
    int soundType = -1;
    int chunk;
    bool consumed5;
    bool valid4;
    while ((chunk = ((CreatureRecordFile*)file)->TESFile_GetTESChunk()) != 0)
    {
        consumed5 = false;
        valid4 = true;
        switch (chunk)
        {
        case 0x44494445: {  // EDID
            char* editorID = (char*)_alloca(((CreatureRecordFile*)file)->GetField25C());
            ((CreatureRecordFile*)file)->FUN_00472890(editorID, 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:
            TESFullName::LoadFullNameChunk(this, file);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
            TESModel::LoadModelData(this, (TESFile*)file);
            break;
        case 0x49524353: {
            unsigned int scriptID = 0;
            ((CreatureRecordFile*)file)->ReadChunkInt(&scriptID);
            TESScriptableForm::Initialize(scriptID);
            TESScriptableForm::InitItem((TESForm*)this);
            break;
        }
        case 0x4f544e43:
        case 0x44454f43:
            switch (((CreatureRecordFile*)file)->TESFile_GetTESChunk())
            {
            case 0x4f544e43: {
                CreatureContainerEntry item;
                ourMemset(&item, 0, 8);
                ((CreatureRecordFile*)file)->FUN_00472890(&item, 8);
                if (((CreatureRecordFile*)file)->FUN_00401680())
                    item.TwoValues_Endian();
                DAT_011cb5f8 = (LastContainerItem*)TESContainer::AddContainerObject((void*)&item);
                break;
            }
            case 0x44454f43:
                if (DAT_011cb5f8)
                {
                    DAT_011cb5f8->extra = new FUN_0040e690;
                    DAT_011cb5f8->extra->FUN_0040e780((CreatureRecordFile*)file);
                    DAT_011cb5f8 = 0;
                }
                break;
            }
            break;
        case 0x4f4c5053: {
            unsigned int spellID = 0;
            ((CreatureRecordFile*)file)->ReadChunkInt(&spellID);
            TESSpellList::TESSpellList_AddSpell_0048d290(spellID);
            break;
        }
        case 0x4d544945: {
            unsigned int touchID = 0;
            ((CreatureRecordFile*)file)->ReadChunkInt(&touchID);
            BGSTouchSpellForm::Initialize(touchID);
            break;
        }
        case 0x544d4145: {
            unsigned short touchAmount = 0;
            ((CreatureRecordFile*)file)->ReadChunkData(&touchAmount);
            BGSTouchSpellForm::FUN_00483170(touchAmount);
            break;
        }
        case 0x54444941: {
            CreatureAIData ai;
            ourMemset(&ai, 0, 20);
            ((CreatureRecordFile*)file)->FUN_00472890(&ai, 20);
            if (((CreatureRecordFile*)file)->FUN_00401680())
                ai.SwapEndianFields();
            if (((CreatureRecordFile*)file)->FUN_00403570() < 4 && ai.aggression > 1)
                ++ai.aggression;
            if (((CreatureRecordFile*)file)->FUN_00403570() < 6)
            {
                switch (ai.aggression)
                {
                case 0:
                    ai.mood = 0;
                    break;
                case 1:
                    ai.aggression = 0;
                    ai.mood = 1;
                    break;
                case 2:
                    ai.aggression = 1;
                    ai.mood = 1;
                    break;
                case 3:
                    ai.aggression = 1;
                    ai.mood = 2;
                    break;
                case 4:
                    ai.aggression = 2;
                    ai.mood = 2;
                    break;
                case 5:
                    ai.aggression = 3;
                    ai.mood = 0;
                    break;
                }
            }
            if (((CreatureRecordFile*)file)->FUN_00403570() < 7)
                ai.confidence = 4 - ai.confidence;
            TESAIForm::SetAIData((PackedRecordData*)&ai);
            break;
        }
        case 0x44494b50: {
            unsigned int packageID = 0;
            ((CreatureRecordFile*)file)->ReadChunkInt(&packageID);
            TESAIForm::AddPackage((TESPackage*)packageID);
            break;
        }
        case 0x4d414e53: {
            CreatureFactionEntry faction;
            ourMemset(&faction, 0, 8);
            ((CreatureRecordFile*)file)->FUN_00472890(&faction, 8);
            if (((CreatureRecordFile*)file)->FUN_00401680())
                faction.QuestPerkEntryData_Endian();
            TESActorBaseData::SetFactionRank((TESFaction*)faction.faction, (char)faction.rank);
            break;
        }
        case 0x4d414e49: {
            unsigned int deathID = 0;
            ((CreatureRecordFile*)file)->ReadChunkInt(&deathID);
            m_pBaseTemplateForm = (TESLevItem*)deathID;
            break;
        }
        case 0x4b435456: {
            unsigned int voiceID;
            ((CreatureRecordFile*)file)->ReadChunkInt(&voiceID);
            m_kFactionList = (BGSVoiceType*)voiceID;
            break;
        }
        case 0x544c5054: {
            unsigned int templateID;
            ((CreatureRecordFile*)file)->ReadChunkInt(&templateID);
            m_ppTemplateForms = (TESForm*)templateID;
            break;
        }
        case 0x53424341:
            ((CreatureRecordFile*)file)->FUN_00472890(&actorData, 24);
            if (((CreatureRecordFile*)file)->FUN_00401680())
                actorData.SwapEndianness();
            if (((CreatureRecordFile*)file)->FUN_00403570() < 8)
                actorData.m_usField16 = 0;
            actorData.m_usField06 = 0;
            break;
        case 0x5a46464b:
            TESAnimation::LoadAnimationChunk(this, (TESFile*)file);
            break;
        case 0x5a46494e:
        case 0x5446494e:
            TESModelList::LoadStringChunk(this, file);
            break;
        case 0x54534544:
        case 0x44545344:
            BGSDestructibleObjectForm::LoadDestructibleData(this, (TESFile*)file);
            break;
        case 0x41544144:
            ((CreatureTypedDataReader*)this)->Read(file, &Data, 4);
            break;
        case 0x304d414e: {
            if (((CreatureRecordFile*)file)->GetField25C())
            {
                char* model = (char*)_alloca(((CreatureRecordFile*)file)->GetField25C());
                ((CreatureRecordFile*)file)->FUN_00472890(model, 0);
            }
            break;
        }
        case 0x314d414e: {
            if (((CreatureRecordFile*)file)->GetField25C())
            {
                char* model2 = (char*)_alloca(((CreatureRecordFile*)file)->GetField25C());
                ((CreatureRecordFile*)file)->FUN_00472890(model2, 0);
            }
            break;
        }
        case 0x4d414e42:
            ((CreatureRecordFile*)file)->ReadChunkInt(&m_fThirdCreatureStatCur);
            break;
        case 0x4d414e57:
            ((CreatureRecordFile*)file)->ReadChunkInt(&m_fSecondCreatureStat);
            break;
        case 0x4d414e54:
            ((CreatureRecordFile*)file)->ReadChunkInt(&m_fFirstCreatureStat);
            break;
        case 0x344d414e: {
            unsigned int material;
            ((CreatureRecordFile*)file)->ReadChunkInt(&material);
            m_eImpactMaterial = (BGSImpactDataSet__IMPACT_MATERIAL_TYPE)material;
            break;
        }
        case 0x354d414e: {
            unsigned int level;
            ((CreatureRecordFile*)file)->ReadChunkInt(&level);
            if (level > 3)
                m_eSoundLevel = (SOUND_LEVEL)1;
            else
                m_eSoundLevel = (SOUND_LEVEL)level;
            break;
        }
        case 0x4d414e52: {
            if (((CreatureRecordFile*)file)->GetField25C() == 4)
            {
                unsigned int oldReach = 0;
                ((CreatureRecordFile*)file)->ReadChunkInt(&oldReach);
                m_ucCreatureType = (unsigned char)oldReach;
            }
            else
                ((CreatureRecordFile*)file)->FUN_00472890(&m_ucCreatureType, 1);
            break;
        }
        case 0x52435343: {
            unsigned int soundCreature = 0;
            ((CreatureRecordFile*)file)->ReadChunkInt(&soundCreature);
            SetCreatureSoundsFrom((TESCreature*)soundCreature);
            break;
        }
        case 0x54445343: {
            int newSoundType;
            ((CreatureRecordFile*)file)->ReadChunkInt(&newSoundType);
            soundType = newSoundType;
            break;
        }
        case 0x49445343:
        case 0x46445343: {
            CreatureSounds* loadedSounds = GetMutableCreatureSounds();
            if (!loadedSounds->LoadSoundsFromFile(file, (CREATURE_SOUND_TYPE)soundType, this))
                consumed5 = true;
            break;
        }
        case 0x4d414e5a: {
            unsigned int combat;
            ((CreatureRecordFile*)file)->ReadChunkInt(&combat);
            SetCombatStyle((TESCombatStyle*)combat);
            break;
        }
        case 0x4d414e50: {
            unsigned int parts;
            ((CreatureRecordFile*)file)->ReadChunkInt(&parts);
            m_pBodyPartDataCur = (BGSBodyPartData*)parts;
            break;
        }
        case 0x4d414e43: {
            unsigned int impact = 0;
            ((CreatureRecordFile*)file)->ReadChunkInt(&impact);
            SetImpactDataSet((BGSImpactDataSet*)impact);
            break;
        }
        case 0x4d414e4c: {
            unsigned int weapons = 0;
            ((CreatureRecordFile*)file)->ReadChunkInt(&weapons);
            FUN_005f8bd0((BGSListForm*)weapons);
            break;
        }
        }
        if (!valid4)
            break;
        if (!consumed5 && !((CreatureRecordFile*)file)->FUN_004726f0())
            break;
    }
    if (!TESActorBaseData::GetShortAtOffset12())
        Warning_005b5e40(DAT_0104947c, GetName(), GetHavokWorldObjectCountInSceneGraph_0084e3a0());
    return true;
}

struct FUN_005f8d70_runtime : FUN_00843150_shell
{
    void* FUN_00600700(void*);
};
extern FUN_005f8d70_runtime* DAT_011cb6a0;
struct FUN_005f8d70_virtual
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* v5(unsigned int);
};
struct FUN_005f8d70_record
{
    int* FUN_006815c0();
};
struct FUN_005f8d70_actor : TESActorBaseData
{
    bool FUN_00461560();
};
struct FUN_005f8d70_settings
{
    float* Setting_Float_00403e20();
};
extern FUN_005f8d70_settings DAT_011cb58c;
struct FUN_005f8d70_shell
{
    unsigned short FUN_0047ff30();
    unsigned short TESCreature_GetAttackDamage();
};
// @fnv 0x005f8d70
// src: COMMUNITY 0x005f8d70
unsigned short FUN_005f8d70_shell::TESCreature_GetAttackDamage()
{
    unsigned short result = 0;
    if (DAT_011cb6a0->InterfaceManager_GetMagicPageNumber() && !g_dataHandler->FUN_004516b0() &&
        reinterpret_cast<signed char*>(this)[0x50] == -1)
    {
        FUN_005f8d70_record* record = static_cast<FUN_005f8d70_record*>(DAT_011cb6a0->FUN_00600700(
            reinterpret_cast<FUN_005f8d70_virtual*>(reinterpret_cast<char*>(this) - 0x30)->v5(1)));
        if (record == 0 || *record->FUN_006815c0() == 0)
            reinterpret_cast<signed char*>(this)[0x50] = 0;
        else
            reinterpret_cast<signed char*>(this)[0x50] = 1;
    }
    if (reinterpret_cast<signed char*>(this)[0x50] == 0)
        return 0;
    if (reinterpret_cast<FUN_005f8d70_actor*>(reinterpret_cast<char*>(this) - 0xdc)->FUN_00461560())
    {
        short level = reinterpret_cast<FUN_005f8d70_actor*>(reinterpret_cast<char*>(this) - 0xdc)->TESActorBaseData_GetLevel();
        if (level < 1)
            level = 1;
        result = FUN_0047ff30();
        result += static_cast<int>(static_cast<double>(level) * *DAT_011cb58c.Setting_Float_00403e20());
    }
    else
    {
        result = FUN_0047ff30();
    }
    return result;
}

class TESBoundObject;
struct ExtraDataList;
struct ExtraDataNode
{
    ExtraDataList*& FUN_006815c0();
};
struct InventoryEntryData
{
    TESBoundObject* FUN_0044ddc0();
    ExtraDataNode* Modelloader_GetReferencedThis();
    int FUN_00726070();
    ~InventoryEntryData();
};
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
// TESCreature does not yet declare this weapon-eligibility helper.
struct CreatureWeaponEligibility
{
    bool CanEquipWeapon(TESBoundObject*);
};

// @fnv 0x005f9e00
void TESCreature::UpdateModel3D(TESObjectREFR* reference, bool unused, bool equip, bool allowChanges)
{
    bool savedVal = true;
    if (!allowChanges)
        savedVal = g_BGSSaveLoadGame->SetThreadAllowChanges(false);
    if (reference->IsActor())
        reference->FUN_00571b50();
    InventoryChanges* entry = InventoryChanges::GetOrAddInventoryChanges(reference);
    entry->RemoveWornItems(true, reference);
    Actor* actor = dynamic_cast<Actor*>(reference);
    if (actor && actor->GetCurrentAIProcess())
    {
        actor->GetCurrentAIProcess()->SetCurrentAmmunition(0);
        actor->GetCurrentAIProcess()->SetCurrentShield(0);
        actor->GetCurrentAIProcess()->SetCurrentTorch(0);
        actor->GetCurrentAIProcess()->SetCurrentArmor(0, 0, false);
    }
    InventoryEntryData* weapon = 0;
    InventoryEntryData* aWeapon = 0;
    float value = 0.0f;
    if (equip && entry)
        weapon = entry->SelectBestWeapon(this, &value, 6, true);
    if (weapon && ((CreatureWeaponEligibility*)this)->CanEquipWeapon(weapon->FUN_0044ddc0()) && !reference->TESObjectREFR_WearingObject(weapon->FUN_0044ddc0()))
    {
        reference->EquipItem(weapon->FUN_0044ddc0(), 1, 0, false);
        if (aWeapon && !reference->TESObjectREFR_WearingObject(aWeapon->FUN_0044ddc0()))
        {
            ExtraDataList* extra = 0;
            if (aWeapon->Modelloader_GetReferencedThis())
                extra = aWeapon->Modelloader_GetReferencedThis()->FUN_006815c0();
            reference->EquipItem(aWeapon->FUN_0044ddc0(), aWeapon->FUN_00726070(), extra, false);
        }
    }
    delete weapon;
    delete aWeapon;
    if (!allowChanges)
        g_BGSSaveLoadGame->SetThreadAllowChanges(savedVal);
    if (actor && actor->GetCurrentAIProcess())
        actor->UpdateSpells(true);
}

struct Effect
{
    int unk00;
    int unk04;
    int unk08;
    int type;
    int part;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    void* weapon;
    bool EffectSetting_IsFlagSetAny(unsigned int);
};

namespace fnv_008b4d10 {
struct Part
{
    bool IsFlag40Set();
    bool BGSBodyPart_IsExplodablePart();
    unsigned char GetByte65();
    signed char GetByte63();
    bool BGSBodyPart_IsSeverablePart();
};
struct BaseView
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual BGSBodyPartData* GetBody();
};
struct Node
{
    bool GetAppCulled_00456610();
};
struct Weapon
{
    unsigned int FUN_00401170();
};
extern Weapon* DAT_011ca278;
struct GlobalObject_0045cf30
{
    bool* Bool();
};
extern GlobalObject_0045cf30 g_011df7f8, g_011df858;
struct Queue
{
    void TaskQueueInterface_QueueDismemberLimb(void*, int, int, bool, bool);
};
Queue* FUN_004537b0();
bool AILinearTaskThreadManager_ShouldQueue3DTask();
void RollChanceOutcome(ActorValueOwner*, Weapon*, int, int, int, bool, bool*, bool*);
}  // namespace fnv_008b4d10

// Checks the actor's creature/special state, then applies the effect to matching body parts, calling FUN_00572fc0 and FUN_008b52a0 or queueing via FUN_0087b440.
// @fnv 0x008b4d10
void Actor::ApplyEffectToBodyParts(Effect* effect, int type, int part, void* source, void* target, int intA, int intB,
                                   bool flag)
{
    using namespace fnv_008b4d10;
    TESCreature* eb = dynamic_cast<TESCreature*>(GetActorBase());
    if (((eb && eb->IsHumanoidCreature()) || IsCharacter()) && *g_011df7f8.Bool())
        return;
    switch (type)
    {
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
        break;
    default:
        TESObjectREFR_SetDismembered(-1, source, target, effect ? effect->part : part, false);
        return;
    }
    if (FUN_00573090(part))
        return;
    if (GetEssential() || GetIsChildSize(false))
        return;
    Part* q;
    fnv_008b4d10::Weapon* b;
    int ba;
    Node* k;
    BGSBodyPartData* l;
    Part* c;
    int h = 0;
    bool f = false;
    bool cf = false;
    BGSBodyPartData* i = reinterpret_cast<BaseView*>(GetActorBase())->GetBody();
    if (i)
    {
        q = reinterpret_cast<Part*>(i->GetValueByIndex(part));
        if (q)
        {
            cf = q->IsFlag40Set();
            if (q->BGSBodyPart_IsExplodablePart())
                h = q->GetByte65();
            if (q && cf && h >= 100)
                f = true;
        }
    }
    bool s = (effect && effect->part != part) ? true : false;
    bool p = false;
    bool a = f;
    if (effect)
    {
        if (effect->EffectSetting_IsFlagSetAny(64))
            a = true;
        else if (effect->EffectSetting_IsFlagSetAny(32))
            p = true;
    }
    if (!p && !a)
    {
        b = s ? 0
              : (source && reinterpret_cast<fnv_008b4d10::Weapon*>(source)->FUN_00401170() == 40
                     ? reinterpret_cast<fnv_008b4d10::Weapon*>(source)
                     : (effect && effect->weapon ? reinterpret_cast<fnv_008b4d10::Weapon*>(effect->weapon)
                                                 : (effect && effect->type == 45 ? DAT_011ca278 : 0)));
        RollChanceOutcome(this, b, h, intA, intB, cf, &p, &a);
    }
    if (!p && !a)
        return;
    for (ba = 0; ba < 15; ba++)
    {
        if (*g_011df858.Bool() && ba != -1)
            ba = part;
        l = reinterpret_cast<BaseView*>(GetActorBase())->GetBody();
        c = l ? reinterpret_cast<Part*>(l->GetValueByIndex(ba)) : 0;
        if (!c || c->GetByte63() != type)
            continue;
        k = reinterpret_cast<Node*>(m_pBaseProcess->GetNodeByType(static_cast<LIMB_TYPE>(ba)));
        if (!k || k->GetAppCulled_00456610())
            continue;
        if (a && !c->BGSBodyPart_IsExplodablePart())
            a = false;
        if (!c->BGSBodyPart_IsSeverablePart() && !c->BGSBodyPart_IsExplodablePart())
            continue;
        TESObjectREFR_SetDismembered(ba, source, target, ba, a);
        if (!AILinearTaskThreadManager_ShouldQueue3DTask())
            Actor_DismemberLimb(type, ba, a, !flag, true, false);
        else
            FUN_004537b0()->TaskQueueInterface_QueueDismemberLimb(this, type, ba, a, !flag);
        if (*g_011df858.Bool() && ba != -1)
            break;
    }
}

extern "C" char DAT_01183a00;
extern "C" char DAT_01183028;
extern "C" void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
struct S47bdd0
{
    void FUN_0047bdd0(void*);
};

struct S4870f0
{
    void CopyFullNameFrom(void*);
};
struct Spells
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual int v22();
    virtual void v23(int);
    int* FUN_00717e50();
};
// @fnv 0x005f9820
void TESCreature::CopyFrom(const TESForm* apSource)
{
    CreatureSounds* ptr;
    TESCreature* src2 = (TESCreature*)FUN_00ec43fb((void*)apSource, 0, &DAT_01183028, &DAT_01183a00, 0);
    if (!src2)
        return;
    if (GetCreatureSounds())
    {
        CreatureSounds* snd = m_pCreatureSounds;
        CreatureSounds* del2 = snd;
        del2 ? del2->DeleteThis(1) : 0;
    }
    m_pCreatureSounds = 0;
    ((TESAIForm*)((char*)this + 0x90))->BaseFormRecord((BaseFormComponent*)apSource);
    ((TESSpellList*)((char*)this + 0x7c))->BaseFormRecord((BaseFormComponent*)apSource);
    ((S47bdd0*)((char*)this + 0x70))->FUN_0047bdd0((void*)apSource);
    ((TESActorBaseData*)((char*)this + 0x30))->BaseFormRecord((BaseFormComponent*)apSource);
    ((TESHealthForm*)((char*)this + 0xb0))->BaseFormRecord((BaseFormComponent*)apSource);
    ((TESAttributes*)((char*)this + 0xb8))->BaseFormRecord((BaseFormComponent*)apSource);
    ((S4870f0*)((char*)this + 0xd0))->CopyFullNameFrom((void*)apSource);
    ((TESModel*)((char*)this + 0xdc))->BaseFormRecord((BaseFormComponent*)apSource);
    TESModelList::BaseFormRecord((BaseFormComponent*)apSource);
    ((TESScriptableForm*)((char*)this + 0xf4))->BaseFormRecord((BaseFormComponent*)apSource);
    ((TESContainer*)((char*)this + 0x64))->BaseFormRecord((BaseFormComponent*)apSource);
    ((TESAnimation*)((char*)this + 0xc4))->BaseFormRecord((BaseFormComponent*)apSource);
    ((BGSDestructibleObjectForm*)((char*)this + 0x104))->FUN_004786e0((BaseFormComponent*)apSource);
    memcpy((char*)this + 0x12c, src2->GetOffset12C(), 4);
    *(int*)((char*)this + 0x34) = *((Spells*)((char*)src2 + 0x30))->FUN_00717e50();
    SetCreatureType(src2->ShadowSceneNode_GetDisableLightUpdate());
    FUN_00507780(src2->TESObjectWEAP_GetShotsPerSecond());
    SetBoltGrowWidth(src2->TESEffectShader_GetAddOnScaleStart());
    SetBoltSmallWidth(src2->GetFootWeight());
    ((Spells*)((char*)this + 0x30))->v23(((Spells*)((char*)src2 + 0x30))->v22());
    if (src2->GetCreatureSounds())
    {
        ptr = GetMutableCreatureSounds();
        ptr->Copy(src2->GetCreatureSounds());
    }
    else
    {
        SetCreatureSoundsFrom(src2->GetSoundCreature());
    }
    *(unsigned int*)((char*)this + 0x154) = src2->FUN_009c0070();
    SetImpactDataSet(src2->GetImpactDataSet());
    FUN_005f8bd0(src2->GetField158());
    SetCombatStyle(((const TESCreature*)src2)->GetCombatStyle());
    SetBodyPartData(((const TESCreature*)src2)->GetBodyPartData());
}

struct CreatureProcessUpdater
{
    void UpdateProcess(TESObjectREFR* ref);
};
// Casts ref to MobileObject, gets its BaseProcess, casts to MiddleHighProcess, and calls Apply on it.
// @fnv 0x005fa0a0
void CreatureProcessUpdater::UpdateProcess(TESObjectREFR* ref)
{
    MobileObject* mobile = dynamic_cast<MobileObject*>(ref);
    if (mobile && mobile->FUN_008d8520())
    {
        MiddleHighProcess* process = dynamic_cast<MiddleHighProcess*>(mobile->FUN_008d8520());
        if (process)
        {
            process->ApplyProcessLevelChange(mobile);
        }
    }
}
