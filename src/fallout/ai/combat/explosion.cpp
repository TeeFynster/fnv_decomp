#include "../../../../include/NiColorA.h"
#include "../../../../include/ProcessLists.h"
#include "../../../../include/Actor.h"
#include "../../../../include/Setting.h"
#include "../../../../include/NiPointer.h"
#include "../../../../include/Explosion.h"
// MSVC generates this reserved closure name itself; the header's explicit
// helper declaration must use a nonreserved identifier in this translation unit.
#define __local_vftable_ctor_closure BoundObjectVtableClosure
#include "../../../../include/BGSExplosion.h"
#undef __local_vftable_ctor_closure
#include "../../../../include/BSAudio.h"
#include "../../../../include/BSOcclusionPlane.h"
#include "../../../../include/GameTimerRecord.h"
#include "../../../../include/HighProcess.h"
#include "../../../../include/MobileObject.h"
#include "../../../../include/NavMeshPtr.h"
#include "../../../../include/TESDataHandler.h"
#include "../../../../include/TESObjectREFR.h"
#include "../../../../include/bhkLiquidAction.h"
#include "../../../../include/AutoMemContext.h"
#include "../../../../include/BGSLoadGameBuffer.h"
#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/TESForm.h"
#include "../../../../include/BGSSaveFormBuffer.h"
#include "../../../../include/TESObjectWEAP.h"
#include "../../../../include/ActorCause.h"

// src/fallout/ai/combat/explosion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/explosion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x009ac170
// src: COMMUNITY 0x009ac170
void __thiscall Explosion::SetActorCause_009ac170(ActorCause* apActorCause)
{
    m_pActorCause = apActorCause;
}

void __cdecl _Deallocate(void*);

// Runs the Explosion destructor and, when flags has bit 0 set, deallocates this; returns this.
// @fnv 0x009ac1d0
void* Explosion::Destroy(unsigned int flags)
{
    Explosion::~Explosion();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern NiRTTI g_01268420;

// @fnv 0x009ae240
const NiRTTI* __thiscall bhkLiquidAction::GetRTTI() const
{
    return &g_01268420;
}

// src: XBOX_PDB 0x00458b50
NavMesh* NavMeshPtr::AnimatingText_GetFullText()
{
    return 0;
}

struct FUN_009afc30_shell
{
    NavMeshPtr m_navMeshPtr;
    NavMesh* hkpFixedBufferCdPointCollector_getHits();
};

// @fnv 0x009afc30
// src: XBOX_PDB 0x009afc30
NavMesh* FUN_009afc30_shell::hkpFixedBufferCdPointCollector_getHits()
{
    return ((NavMeshPtr*)((char*)this + 8))->AnimatingText_GetFullText();
}

// This is the distinct 0x00932d60 load step; shared MobileObject only
// declares the 0x00932a00 ApplyLoadBuffer step.
struct MobileObjectLoadStep
{
    void ApplyLoadBuffer(BGSLoadFormBuffer* apLoadGameBuffer);
};

// @fnv 0x009b2770
// src: XBOX_PDB 0x009b2770
void Explosion::FinishLoadGame_009b2770(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<MobileObjectLoadStep*>(this)->ApplyLoadBuffer(apLoadGameBuffer);
}

// @fnv 0x009ad5f0
int BSOcclusionPlane::IsNotCulled()
{
    return !GetCullResult();
}

struct FUN_009afbb0_shell
{
    virtual ~FUN_009afbb0_shell();
    void* FUN_009afbb0(unsigned int flags);
    void ForwardCall_009afc10();
};

extern "C" void __cdecl Object_UpdateFields_009afbe0(void*);

// Calls FUN_009afc10, then if bit 0 of flags is set calls FUN_009afbe0 on this, and returns this.
// @fnv 0x009afbb0
void* FUN_009afbb0_shell::FUN_009afbb0(unsigned int flags)
{
    ForwardCall_009afc10();
    if (flags & 1)
        Object_UpdateFields_009afbe0(this);
    return this;
}

struct FUN_00621100_shell
{
    void __thiscall SetVtable(void);
};

struct FUN_009afc10_shell
{
    void __thiscall ForwardCall_009afc10();
};

// @fnv 0x009afc10
// src: GUESS 0x009afc10 (confidence: low)
void __thiscall FUN_009afc10_shell::ForwardCall_009afc10()
{
    ((FUN_00621100_shell*)this)->SetVtable();
}

struct FUN_009afc50_shell
{
    char m_auiShapeKeys[0x14];
    NavMeshPtr m_navMeshPtr;
    NavMesh* hkpFixedBufferCdPointCollector_getHits();
};

// @fnv 0x009afc50
// src: XBOX_PDB 0x009afc30
NavMesh* FUN_009afc50_shell::hkpFixedBufferCdPointCollector_getHits()
{
    return m_navMeshPtr.AnimatingText_GetFullText();
}

void __cdecl FUN_009ac940(void*);
struct FUN_009ac910_shell
{
    void __thiscall FUN_009ac940();
    void* __thiscall FUN_009ac910(unsigned int flags);
};
// Calls FUN_009ac940, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x009ac910
void* __thiscall FUN_009ac910_shell::FUN_009ac910(unsigned int flags)
{
    FUN_009ac940();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl _delete(void*, unsigned int);
struct FUN_00cbc920_shell
{
    void __thiscall FUN_00cbc920();
};
struct StandIn
{
    void* __thiscall FUN_009ae250(unsigned int);
};
// Calls FUN_00cbc920 on this, then frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x009ae250
void* StandIn::FUN_009ae250(unsigned int flags)
{
    ((FUN_00cbc920_shell*)this)->FUN_00cbc920();
    if (flags & 1)
        _delete(this, 0x40);
    return this;
}

// The shared timer lacks the 0x0084d030 accessor used here.
struct GameTimerAccessorBridge
{
    float GetStoredFloatValue();
};
extern GameTimerRecord g_timeGlobal;

// @fnv 0x009ae580
// src: XBOX_PDB 0x009ae580
void Explosion::ProcessMovement(float afDelta)
{
    float fdelta = reinterpret_cast<GameTimerAccessorBridge*>(&g_timeGlobal)->GetStoredFloatValue();
    Update(fdelta);
    m_fFirstFloatValue += fdelta;
}

BSAudio* __cdecl _FUN_00c85750();
struct UnkObj
{
    virtual void f0();
    virtual void f1();
    virtual void f2(void*, int);
};
// @fnv 0x009afbe0
// src: GUESS 0x009afbe0 (confidence: low)
void __cdecl Object_UpdateFields_009afbe0(void* a1)
{
    if (a1 != 0)
    {
        UnkObj* v = (UnkObj*)_FUN_00c85750()->GetAudioBackendData();
        v->f2(a1, 0x18);
    }
}

struct H00622570
{
    void __thiscall UpdateState_00622570(bool);
};
struct S009afc70
{
    char m_auiShapeKeys[0x14];
    NavMeshPtr m_navMeshPtr;
    void* __thiscall hkpFixedBufferCdPointCollector_hasHit(void*);
};
// Calls FUN_00622570 on a1 with true when m_navMeshPtr.FUN_00458b50() returns a value greater than 0, then returns a1.
// @fnv 0x009afc70
// src: COMMUNITY 0x009afc70
void* __thiscall S009afc70::hkpFixedBufferCdPointCollector_hasHit(void* apTarget)
{
    ((H00622570*)apTarget)->UpdateState_00622570((int)m_navMeshPtr.AnimatingText_GetFullText() > 0);
    return apTarget;
}

class BGSRagdoll;
struct RagdollCallView
{
  public:
    virtual void F00()
    {}
    virtual void F01()
    {}
    virtual void F02()
    {}
    virtual void F03()
    {}
    virtual void F04()
    {}
    virtual void F05()
    {}
    virtual void F06()
    {}
    virtual void F07()
    {}
    virtual void F08()
    {}
    virtual void F09()
    {}
    virtual void F10()
    {}
    virtual void F11()
    {}
    virtual void F12()
    {}
    virtual void F13()
    {}
    virtual void F14()
    {}
    virtual void F15()
    {}
    virtual void F16()
    {}
    virtual void F17()
    {}
    virtual void F18()
    {}
    virtual void F19()
    {}
    virtual void F20()
    {}
    virtual void F21(int)
    {}
};
struct FUN_009b0d30_shell
{
    void __thiscall activate_00c9c1d0();
    void __thiscall hkpRigidBody_applyAngularImpulse(int);
};
// @fnv 0x009b0d30
// src: COMMUNITY 0x009b0d30
void __thiscall FUN_009b0d30_shell::hkpRigidBody_applyAngularImpulse(int a1)
{
    this->activate_00c9c1d0();
    reinterpret_cast<RagdollCallView*>(reinterpret_cast<TESDataHandler*>(this)->GetBGSRagdollList())->F21(a1);
}

struct RetObj
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual bool vf37();
};
// Returns true if _FNV_GetObjectReference() is non-null and its vf37() call returns true, otherwise false.
// @fnv 0x00565690
// src: COMMUNITY 0x00565690
bool Actor::TESObjectREFR_BaseIsQuestItem()
{
    return _FNV_GetObjectReference() ? _FNV_GetObjectReference()->vf37() : false;
}

// Only the flag accessor is missing from the shared explosion declarations.
struct ExplosionFlagAccessor
{
    bool __thiscall HasAnyFlags(int);
};
extern Setting originalRuntimeFloatSetting818;
// @fnv 0x009ad5a0
float __thiscall BGSExplosion::GetScaledValue()
{
    return (float)(reinterpret_cast<ExplosionFlagAccessor*>(this)->HasAnyFlags(1) ? (double)Data.m_fImpactThirdValue
                                  : (double)(Data.m_fImpactThirdValue * *originalRuntimeFloatSetting818.Float()));
}

extern const float runtimeFloatSettingDefault247;
struct FUN_009ae0f0
{
    char _pad[8];
    float m8;
    float mC;
    float m10;
    float m14;
    void __thiscall hkUnaryActionCinfo_hkUnaryActionCinfo();
    FUN_009ae0f0();
};
// Calls FUN_00537bb0, then sets m8 to runtimeFloatSettingDefault247 and mC, m10, m14 to 15.0f, 64.0f, 15.0f.
// @fnv 0x009ae0f0
FUN_009ae0f0::FUN_009ae0f0()
{
    hkUnaryActionCinfo_hkUnaryActionCinfo();
    m8 = runtimeFloatSettingDefault247;
    mC = 15.0f;
    m10 = 64.0f;
    m14 = 15.0f;
}

void* __cdecl operator new(unsigned int);
// TESObjectWEAP.h forward-declares enum SOUND_LEVEL, which conflicts with
// the SOUND_LEVEL typedef imported by BaseProcess.h.
TESForm* GetFormByID(unsigned int);
ActorCause* FindStateByValue(int);
struct FUN_00825ad0
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int uiFormID18;
    unsigned int uiFormID1C;
    unsigned int uiFormID20;
    FUN_00825ad0(void* apOwner);
};

// @fnv 0x009b22c0
// src: XBOX_PDB 0x009b22c0
void Explosion::LoadGame_009b22c0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    MobileObject::ApplyLoadBuffer(apLoadGameBuffer);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&m_fFirstFloatValue), 4u);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&f3DLifetime), 4u);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&fOuterRadius), 4u);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&ExplosionRuntimeData), 4u);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&ReferenceCauseInfo), 1u);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&m_iValueE4), 4u);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&fInnerRadius), 4u);
    if (apLoadGameBuffer->GetVersion() >= 0xe)
    {
        apLoadGameBuffer->ReadTypedData(static_cast<void*>(&m_fFourthRecordValue), 4u);
        apLoadGameBuffer->ReadTypedData(static_cast<void*>(&MagicWeaponState), 1u);
        apLoadGameBuffer->ReadTypedData(static_cast<void*>(&bUnderwater), 1u);
        apLoadGameBuffer->ReadTypedData(static_cast<void*>(&kClosestPoint), 0xcu);
        apLoadGameBuffer->ReadTypedData(static_cast<void*>(&kClosestPointNormal), 0xcu);
    }
    if (apLoadGameBuffer->GetVersion() >= 0x14)
        apLoadGameBuffer->ReadTypedData(static_cast<void*>(&m_fClosestPointScalar), 4u);
    apLoadGameBuffer->ReadFormIdentifier(static_cast<void*>(&pOwnerRef));
    apLoadGameBuffer->ReadFormIdentifier(static_cast<void*>(&ReferenceSoundCauseData));
    m_pFiringWeapon =
        dynamic_cast<TESObjectWEAP*>(GetFormByID(((BGSLoadGameBuffer*)apLoadGameBuffer)->ReadFormIdentifier()));
    int iactorCauseID = -1;
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&iactorCauseID), 4u);
    m_pActorCause = FindStateByValue(iactorCauseID);
    bool bhasCaster = true;
    if (apLoadGameBuffer->GetVersion() >= 7)
        apLoadGameBuffer->ReadTypedData(static_cast<void*>(&bhasCaster), 1u);
    if (bhasCaster)
    {
        if (!m_pEffectInstance)
            m_pEffectInstance = reinterpret_cast<NonActorMagicCaster*>(new FUN_00825ad0(this));
        apLoadGameBuffer->ReadFormIdentifier(static_cast<void*>(&reinterpret_cast<FUN_00825ad0*>(m_pEffectInstance)->uiFormID18));
        apLoadGameBuffer->ReadFormIdentifier(static_cast<void*>(&reinterpret_cast<FUN_00825ad0*>(m_pEffectInstance)->uiFormID1C));
        apLoadGameBuffer->ReadFormIdentifier(static_cast<void*>(&reinterpret_cast<FUN_00825ad0*>(m_pEffectInstance)->uiFormID20));
    }
    if (m_iValueE4 > 0)
    {
        m_bFlagD5 = true;
        m_bFlagD6 = true;
        m_bFlagD7 = true;
    }
}

struct Vec3f
{
    float x;
    float y;
    float z;
};
extern const float g_fConst010162c0;
void* __fastcall Callee00439e90(void* p);
void* __fastcall Callee0053d280(void* p);
// TESObjectREFR.h lacks this helper and the corresponding virtual signatures.
struct FUN_005762b0_cls
{
    virtual void vf0()
    {}
    virtual void vf1()
    {}
    virtual void vf2()
    {}
    virtual void vf3()
    {}
    virtual void vf4()
    {}
    virtual void vf5()
    {}
    virtual void vf6()
    {}
    virtual void vf7()
    {}
    virtual void vf8()
    {}
    virtual void vf9()
    {}
    virtual void vf10()
    {}
    virtual void vf11()
    {}
    virtual void vf12()
    {}
    virtual void vf13()
    {}
    virtual void vf14()
    {}
    virtual void vf15()
    {}
    virtual void vf16()
    {}
    virtual void vf17()
    {}
    virtual void vf18()
    {}
    virtual void vf19()
    {}
    virtual void vf20()
    {}
    virtual void vf21()
    {}
    virtual void vf22()
    {}
    virtual void vf23()
    {}
    virtual void vf24()
    {}
    virtual void vf25()
    {}
    virtual void vf26()
    {}
    virtual void vf27()
    {}
    virtual void vf28()
    {}
    virtual void vf29()
    {}
    virtual void vf30()
    {}
    virtual void vf31()
    {}
    virtual void vf32()
    {}
    virtual void vf33()
    {}
    virtual void vf34()
    {}
    virtual void vf35()
    {}
    virtual void vf36()
    {}
    virtual void vf37()
    {}
    virtual void vf38()
    {}
    virtual void vf39()
    {}
    virtual void vf40()
    {}
    virtual void vf41()
    {}
    virtual void vf42()
    {}
    virtual void vf43()
    {}
    virtual void vf44()
    {}
    virtual void vf45()
    {}
    virtual void vf46()
    {}
    virtual void vf47()
    {}
    virtual void vf48()
    {}
    virtual void vf49()
    {}
    virtual void vf50()
    {}
    virtual void vf51()
    {}
    virtual void vf52()
    {}
    virtual void vf53()
    {}
    virtual void vf54()
    {}
    virtual void vf55()
    {}
    virtual void vf56()
    {}
    virtual void vf57()
    {}
    virtual void vf58()
    {}
    virtual void vf59()
    {}
    virtual void vf60()
    {}
    virtual void vf61()
    {}
    virtual void vf62()
    {}
    virtual void vf63()
    {}
    virtual void vf64()
    {}
    virtual void vf65()
    {}
    virtual void vf66()
    {}
    virtual void vf67()
    {}
    virtual void vf68()
    {}
    virtual void vf69()
    {}
    virtual void vf70()
    {}
    virtual void vf71()
    {}
    virtual void vf72()
    {}
    virtual void vf73()
    {}
    virtual void vf74()
    {}
    virtual void vf75()
    {}
    virtual void vf76()
    {}
    virtual void vf77()
    {}
    virtual void vf78()
    {}
    virtual void vf79()
    {}
    virtual void vf80()
    {}
    virtual void vf81()
    {}
    virtual void vf82()
    {}
    virtual void vf83()
    {}
    virtual void vf84()
    {}
    virtual void vf85()
    {}
    virtual void vf86()
    {}
    virtual void vf87()
    {}
    virtual void vf88()
    {}
    virtual void vf89()
    {}
    virtual void vf90()
    {}
    virtual void vf91()
    {}
    virtual void vf92()
    {}
    virtual void vf93()
    {}
    virtual void vf94()
    {}
    virtual void vf95()
    {}
    virtual void vf96()
    {}
    virtual void vf97()
    {}
    virtual void vf98()
    {}
    virtual void vf99()
    {}
    virtual void vf100()
    {}
    virtual void vf101()
    {}
    virtual void vf102()
    {}
    virtual void vf103()
    {}
    virtual void vf104()
    {}
    virtual void vf105()
    {}
    virtual void vf106()
    {}
    virtual void vf107()
    {}
    virtual void vf108()
    {}
    virtual void vf109()
    {}
    virtual void vf110()
    {}
    virtual void vf111()
    {}
    virtual void vf112()
    {}
    virtual void vf113()
    {}
    virtual void vf114()
    {}
    virtual void vf115()
    {}
    virtual void vf116()
    {}
    virtual void vf117()
    {}
    virtual void* vf118(unsigned int* p, Vec3f* q, void* r)
    {
        return 0;
    }
    virtual void* vf119(Vec3f* p, Vec3f* q, float f)
    {
        return 0;
    }
    virtual void vf120()
    {}
    virtual void vf121()
    {}
    virtual void vf122()
    {}
    virtual void vf123()
    {}
    virtual void vf124()
    {}
    virtual void* vf125(int a, void* p)
    {
        return 0;
    }
    int TESObjectREFR_GetLookingAtLocation(int a1);
};
// Calls vf125 with a1 and the result of a chain of vf118/vf119 calls on local Vec3f values, then passes that to Callee00439e90, and returns a1.
// @fnv 0x005762b0
// src: COMMUNITY 0x005762b0
int FUN_005762b0_cls::TESObjectREFR_GetLookingAtLocation(int a1)
{
    Vec3f a2;
    Vec3f bTmp;
    Vec3f c;
    Vec3f d;
    Callee00439e90(
        vf125(a1, Callee0053d280(Callee00439e90(vf118((unsigned int*)&d, &bTmp, vf119(&c, &a2, g_fConst010162c0))))));
    return a1;
}

extern Setting originalRuntimeFloatSetting818;

// Retained: Explosion.h does not declare GetEffectiveValue (0x009ac550).
struct FUN_009ac550_cls : ExplosionFlagAccessor
{
    char _pad[0x8b];
    float m_8C;
    float GetEffectiveValue();
};

// Returns m_8C, or m_8C multiplied by the float setting when HasAnyFlags(1) is zero.
// @fnv 0x009ac550
float FUN_009ac550_cls::GetEffectiveValue()
{
    return (float)((HasAnyFlags(1) != 0) ? (double)m_8C : (double)(m_8C * *originalRuntimeFloatSetting818.Float()));
}

extern int g_ae140Count;

struct Ae140Vec
{
    int unk00;
    int unk04;
    int unk08;
    Ae140Vec();
};

extern Ae140Vec g_ae140Default;

struct Ae140Base
{
    virtual ~Ae140Base();
    int unk04;
    int unk08;
    int unk0c;
    Ae140Base();
};

struct FUN_009ae140_cls : Ae140Base
{
    virtual ~FUN_009ae140_cls();
    int m_10;
    float m_14;
    float m_18;
    float m_1c;
    float m_20;
    Ae140Vec m_24;
    Ae140Vec m_30;
    unsigned char m_3c;

    void Setup(unsigned int aArg);
    FUN_009ae140_cls(unsigned int aArg);
};

// Initialises the object's fields to defaults, calls Setup with aArg, and increments g_ae140Count.
// @fnv 0x009ae140
FUN_009ae140_cls::FUN_009ae140_cls(unsigned int aArg)
{
    m_10 = 0;
    m_14 = 0.0f;
    m_18 = 0.0f;
    m_1c = 0.0f;
    m_20 = 0.0f;
    m_24 = g_ae140Default;
    m_30 = g_ae140Default;
    m_3c = 1;
    Setup(aArg);
    ++g_ae140Count;
}

struct VectorHolder
{
    unsigned int handle;
    void __thiscall FUN_006815c0();
    void __thiscall FUN_00537e90(unsigned int);
    VectorHolder()
    {
        FUN_006815c0();
    }
};
struct BaseObject
{
    virtual ~BaseObject();
    unsigned int unk04;
    void __thiscall hkpCdPointCollector_hkpCdPointCollector();
    BaseObject()
    {
        hkpCdPointCollector_hkpCdPointCollector();
    }
};
struct FUN_009afaf0 : BaseObject
{
    VectorHolder first;
    VectorHolder second;
    VectorHolder third;
    VectorHolder fourth;
    FUN_009afaf0(unsigned int firstValue, unsigned int secondValue);
    virtual ~FUN_009afaf0();
};
// Constructs the object and initialises its four VectorHolder members with firstValue, firstValue, secondValue and 0.
// @fnv 0x009afaf0
FUN_009afaf0::FUN_009afaf0(unsigned int firstValue, unsigned int secondValue)
{
    first.FUN_00537e90(firstValue);
    second.FUN_00537e90(firstValue);
    third.FUN_00537e90(secondValue);
    fourth.FUN_00537e90(0);
}

struct FUN_009afca0_holder
{
    void __thiscall InvokeCallback(void* param);
};

extern void(__cdecl* g_01268430)(void* param, void* thisptr);

// @fnv 0x009afca0
void __thiscall FUN_009afca0_holder::InvokeCallback(void* param)
{
    g_01268430(param, this);
}

struct EntryRecord
{
    int category;
    int unk04;
    int result;
};
struct SearchNode
{
    EntryRecord** FUN_006815c0();
    SearchNode* FUN_00726070();
    bool FUN_008256d0();
};
// Retained: Explosion.h does not declare FindEntryResultByCategory (0x009b1720).
struct SearchOwner : MobileObject
{
    unsigned int unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0;
    SearchNode entries;
    int* FindEntryResultByCategory(int category);
};
// Walks the entries node chain until a matching category is found, returning a pointer to that entry's result or null.
// @fnv 0x009b1720
int* SearchOwner::FindEntryResultByCategory(int category)
{
    int* pResult = 0;
    SearchNode* node = &entries;
    while (pResult == 0 && node != 0 && !node->FUN_008256d0())
    {
        EntryRecord* entry = *node->FUN_006815c0();
        if (entry != 0 && entry->category == category)
            pResult = &entry->result;
        node = node->FUN_00726070();
    }
    return pResult;
}

class TESForm;
TESForm* GetFormByID(unsigned int);
void* LookupThing18(void*);
void* LookupThing1C(void*);
struct CasterData
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    void* pUnk18;
    void* pUnk1C;
    TESObjectREFR* pRef20;
};

// The shared base has no declaration for the 0x00932b70 finish-load step.
struct MobileObjectFinishLoadStep
{
    void BaseFinishLoad(void* apBuffer);
};

// @fnv 0x009b25b0
// src: COMMUNITY 0x009b25b0
void Explosion::InitLoadGame_009b25b0(void* apBuffer)
{
    reinterpret_cast<MobileObjectFinishLoadStep*>(this)->BaseFinishLoad(apBuffer);
    pOwnerRef = pOwnerRef ? dynamic_cast<TESObjectREFR*>(GetFormByID((unsigned int)pOwnerRef)) : 0;
    ReferenceSoundCauseData = ReferenceSoundCauseData ? dynamic_cast<TESObjectREFR*>(GetFormByID((unsigned int)ReferenceSoundCauseData)) : 0;
    if (m_pEffectInstance)
    {
        reinterpret_cast<CasterData*>(m_pEffectInstance)->pUnk18 = reinterpret_cast<CasterData*>(m_pEffectInstance)->pUnk18 ? LookupThing18(reinterpret_cast<CasterData*>(m_pEffectInstance)->pUnk18) : 0;
        reinterpret_cast<CasterData*>(m_pEffectInstance)->pUnk1C = reinterpret_cast<CasterData*>(m_pEffectInstance)->pUnk1C ? LookupThing1C(reinterpret_cast<CasterData*>(m_pEffectInstance)->pUnk1C) : 0;
        reinterpret_cast<CasterData*>(m_pEffectInstance)->pRef20 =
            reinterpret_cast<CasterData*>(m_pEffectInstance)->pRef20 ? dynamic_cast<TESObjectREFR*>(GetFormByID((unsigned int)reinterpret_cast<CasterData*>(m_pEffectInstance)->pRef20)) : 0;
    }
    if (IsNotCulled())
        Initialize();
}

struct GlobalObject_00633c90
{
    GlobalObject_00633c90(int v);
    ~GlobalObject_00633c90();
    int m_ptr;
    GlobalObject_00633c90& operator=(void* p);
};
struct GlobalObject_0096a2d0
{
    GlobalObject_0096a2d0();
    ~GlobalObject_0096a2d0();
    int m_item;
    int m_next;
};
struct GlobalObject_0041a250
{
    GlobalObject_0041a250();
    ~GlobalObject_0041a250();
    int m_00;
    int m_04;
    int m_08;
};
struct GlobalObject_0042f730
{
    GlobalObject_0042f730(void* p);
    ~GlobalObject_0042f730();
    int m_ptr;
    void AssignRetainedObject(void* p);
};
struct GlobalObject_006815c0
{
    GlobalObject_006815c0();
    float x;
    float y;
    float z;
};
extern "C" Vec3f NiPoint3_ZERO;

struct Base1_9abf30
{
    virtual ~Base1_9abf30();
    virtual void bvtbl00();
    int bf04;
    int bf08;
    int bf0c;
    int bf10;
    int bf14;
};
struct Base2_9abf30
{
    virtual void wvtbl00();
};

struct FUN_0092eb50 : Base1_9abf30, Base2_9abf30
{
    FUN_0092eb50();
    virtual ~FUN_0092eb50();
};

// Retained: Explosion.h does not declare the default constructor (0x009abf30).
struct FUN_009abf30 : FUN_0092eb50
{
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    float m_88;
    float m_8c;
    float m_90;
    float m_94;
    float m_98;
    float m_9c;
    GlobalObject_00633c90 m_a0;
    GlobalObject_0096a2d0 m_a4;
    GlobalObject_0041a250 m_ac;
    GlobalObject_0041a250 m_b8;
    GlobalObject_00633c90 m_c4;
    int m_c8;
    int m_cc;
    GlobalObject_0042f730 m_d0;
    unsigned char m_d4;
    unsigned char m_d5;
    unsigned char m_d6;
    unsigned char m_d7;
    unsigned char m_d8;
    unsigned char m_d9;
    unsigned char m_da;
    unsigned char m_db;
    int m_dc;
    int m_e0;
    int m_e4;
    GlobalObject_006815c0 m_e8;
    GlobalObject_006815c0 m_f4;
    float m_100;
    FUN_009abf30();
    virtual ~FUN_009abf30();
};

// @fnv 0x009abf30
FUN_009abf30::FUN_009abf30() : m_a0(0), m_c4(0), m_d0(0)
{
    m_68 = 0;
    m_e4 = 0;
    m_88 = 0.0f;
    m_8c = 0.0f;
    m_90 = 0.0f;
    m_94 = 0.0f;
    m_98 = 0.0f;
    m_9c = 1.0f;
    m_a0 = 0;
    m_c4 = 0;
    m_d0.AssignRetainedObject(0);
    m_c8 = 0;
    m_cc = 0;
    m_e0 = 0;
    m_d4 = 0;
    m_d5 = 0;
    m_d6 = 0;
    m_d7 = 0;
    m_d8 = 0;
    m_d9 = 0;
    m_dc = 0;
    m_e8 = *(GlobalObject_006815c0*)&NiPoint3_ZERO;
    m_f4 = *(GlobalObject_006815c0*)&NiPoint3_ZERO;
    m_100 = -1.0f;
}

namespace fnv_009ac200 {
struct PrimaryC
{
    virtual ~PrimaryC();
    int u04, u08, u0c, u10, u14;
};
struct SecondaryC
{
    virtual ~SecondaryC();
    int u1c;
    int u20;
    int u24;
    int u28;
    int u2c;
    int u30;
    int u34;
    int u38;
    int u3c;
    int u40;
    int u44;
    int u48;
    int u4c;
    int u50;
    int u54;
    int u58;
    int u5c;
    int u60;
    int u64;
    int u68;
    int u6c;
    int u70;
    int u74;
    int u78;
    int u7c;
    int u80;
    int u84;
};
struct MobileC : PrimaryC, SecondaryC
{
    MobileC();
    virtual ~MobileC();
    void SetParent(void*);
    void SetLocation(const Vec3f&);
    void SetRotation(struct MatrixC);
    void SetForm(void*);
    struct ExplosionFormC* GetActorBase();
};
struct MatrixC
{
    float a, b, c, d, e, f, g, h, i;
};
struct ExplosionFormC
{
    float Radius();
    float Force();
    bool HasFlag(int);
};
struct SmartC
{
    void* ptr;
    SmartC(void*);
    ~SmartC();
    SmartC& operator=(void*);
};
struct ListC
{
    void* head;
    void* next;
    ListC();
    ~ListC();
};
struct TripleC
{
    int a, b, c;
    TripleC();
    ~TripleC();
};
struct CauseC
{
    void* ptr;
    CauseC(void*);
    ~CauseC();
    CauseC& operator=(void*);
};
struct PointC
{
    float x, y, z;
    PointC();
};
struct OwnerC
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual bool IsSpecial();
};
extern MatrixC DAT_011a9448;
extern PointC NiPoint3_ZERO;
extern const float DAT_01017718;
extern const float DAT_01012054;
// Retained: Explosion.h does not declare this constructor overload (0x009ac200).
struct FUN_009ac200 : MobileC
{
    float age, lifetime, timer, radius, force, scale;
    SmartC object;
    ListC list;
    TripleC first, second;
    SmartC another;
    OwnerC* owner;
    int unkCC;
    CauseC cause;
    bool flagD4, flagD5, flagD6, flagD7, flagD8, flagD9;
    short unkDA;
    FUN_00825ad0* caster;
    void* weapon;
    int frames;
    PointC position, velocity;
    float finalValue;
    virtual ~FUN_009ac200();
    FUN_009ac200(void*, OwnerC*, void*, Vec3f, MatrixC);
};
// @fnv 0x009ac200
FUN_009ac200::FUN_009ac200(void* form, OwnerC* source, void* parent, Vec3f location, MatrixC rotation)
    : object(0), another(0), cause(0)
{
    u68 = 0;
    owner = source;
    SetParent(parent);
    SetLocation(location);
    SetRotation(rotation);
    flagD8 = false;
    if (form)
    {
        SetForm(form);
        radius = GetActorBase()->Radius();
        force = GetActorBase()->Force();
        flagD8 = GetActorBase()->HasFlag(64);
        if (GetActorBase()->HasFlag(2))
            SetRotation(DAT_011a9448);
    }
    frames = 0;
    lifetime = DAT_01017718;
    timer = 0.0f;
    age = 0.0f;
    scale = 1.0f;
    object = 0;
    another = 0;
    cause = 0;
    weapon = 0;
    flagD4 = false;
    flagD5 = false;
    flagD6 = false;
    flagD7 = false;
    flagD9 = false;
    caster = source && source->IsSpecial() ? 0 : new FUN_00825ad0(this);
    position = NiPoint3_ZERO;
    velocity = NiPoint3_ZERO;
    finalValue = DAT_01012054;
}
}  // namespace fnv_009ac200

// When the reference's 3D is loaded, run a world update on its root node with the current time.

extern float g_fB17A0CurrentTime;

class B17A0UpdateData
{
  public:
    B17A0UpdateData(float fTime, bool m_bUpdateEnabled, bool bIsMultiThreaded);

    float m_fTime;
    bool m_bUpdate;
    bool m_bIsMultiThreaded;
    unsigned char unk06;
    unsigned char unk07;
    int unk08;
};

class B17A0Node
{
  public:
    void Update(const B17A0UpdateData& kData);
};

// If the 3D is loaded and present, builds update data from the current time and updates the 3D node.
// @fnv 0x009b17a0
void Explosion::Update3D(int iUnused)
{
    if (IsNotCulled() && GetNiNode())
    {
        B17A0UpdateData kData(g_fB17A0CurrentTime, true, false);
        reinterpret_cast<B17A0Node*>(GetNiNode())->Update(kData);
    }
}

// FUN_009b2790 v01 - worker7 data round

struct AC_0042f730;
struct Holder0042f780
{
    int m_00;
    Holder0042f780* AssignRetainedObject(AC_0042f730* p);
};

struct HeadW7
{
    void* FUN_009ac910(unsigned int flags);
};

struct ListW7
{
    int m_00;
    bool _ref_008256d0();
    HeadW7** _ref_006815c0();
    void _ref_0063f7b0();
};

struct Vec3W7
{
    float x;
    float y;
    float z;
};
extern Vec3W7 __NiPoint3_ZERO;

// @fnv 0x009b2790
// src: COMMUNITY 0x009b2790
void Explosion::RevertBGS_009b2790(BGSLoadFormBuffer* apBuffer)
{
    MobileObject::Revert(apBuffer);
    ReferenceCauseInfo = 0;
    m_bFlagD5 = 0;
    m_bFlagD6 = 0;
    m_bFlagD7 = 0;
    reinterpret_cast<Holder0042f780&>(m_pActorCause).AssignRetainedObject(0);
    m_fFourthRecordValue = 1.0f;
    MagicWeaponState = 0;
    bUnderwater = 0;
    reinterpret_cast<Vec3W7&>(kClosestPoint) = __NiPoint3_ZERO;
    reinterpret_cast<Vec3W7&>(kClosestPointNormal) = __NiPoint3_ZERO;
    while (!reinterpret_cast<ListW7&>(kTargets)._ref_008256d0())
    {
        HeadW7* head = *reinterpret_cast<ListW7&>(kTargets)._ref_006815c0();
        HeadW7* toFree = head;
        toFree ? toFree->FUN_009ac910(1) : 0;
        reinterpret_cast<ListW7&>(kTargets)._ref_0063f7b0();
    }
}

// The update helpers pass this position by value as a POD.
struct ExplosionPosition
{
    float x, y, z;
    ExplosionPosition operator-(const ExplosionPosition&) const;
    float Length() const;
};
struct MatrixWater
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    MatrixWater();
    void FUN_004a0c90(float);
};
struct SaveX
{
    bool BGSSaveLoadGame_GetSaveGameLoading();
};
extern SaveX* g_BGSSaveLoadGame;
struct SceneX
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual SceneX* AsNode();
    virtual SceneX* AsFade();
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
    virtual void Attach(SceneX*, bool);
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    void FUN_00450f90(bool);
    void BSFadeNode_TurnFadeNodeOn();
    void NiAVObject_SetTranslate(const ExplosionPosition&);
    void UpdateProperties();
};
struct IdFlagState
{
    int id, flags, state;
    IdFlagState();
    ~IdFlagState();
    void operator=(const IdFlagState&);
    bool FUN_00ad8ce0();
    bool FUN_00ad8b60(float, float, float);
    bool FUN_00ad8830(bool);
};
struct AudioX
{
    IdFlagState BSAudio_GetSoundHandleByEditorName(const char*, unsigned);
};
AudioX* BSAudio_QInstance();
extern Setting DAT_011d0520, DAT_011d0280, DAT_011d0da4, DAT_011d0ce4, DAT_011d0a78, DAT_011c7ae8;
struct RefX;
struct BaseX
{
    void* EffectSetting_GetLight();
    float GetScaledValue();
    float NiAVObject_GetWorldScale();
    int* BGSExplosion_GetSoundLevelValue();
};
struct CellX
{
    void RemoveReference(RefX*);
    void AddReference(RefX*, bool);
    SceneX* FUN_005497a0();
    float TESObjectCELL_GetWaterHeight();
};
struct ActorProcX
{
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p20();
    virtual void p21();
    virtual void p22();
    virtual void p23();
    virtual void p24();
    virtual void p25();
    virtual void p26();
    virtual void p27();
    virtual void p28();
    virtual void p29();
    virtual void p30();
    virtual void p31();
    virtual void p32();
    virtual void p33();
    virtual void p34();
    virtual void p35();
    virtual void p36();
    virtual void p37();
    virtual void p38();
    virtual void p39();
    virtual void p40();
    virtual void p41();
    virtual void p42();
    virtual void p43();
    virtual void p44();
    virtual void p45();
    virtual void p46();
    virtual void p47();
    virtual void p48();
    virtual void p49();
    virtual void p50();
    virtual void p51();
    virtual void p52();
    virtual void p53();
    virtual void p54();
    virtual void p55();
    virtual void p56();
    virtual void p57();
    virtual void p58();
    virtual void p59();
    virtual void p60();
    virtual void p61();
    virtual void p62();
    virtual void React(RefX*, ExplosionPosition, int*, int, unsigned);
};
// Retained: the shared base has vfn_168(int) at slot 0x168, while this
// update needs a parameterless, pointer-returning GetActor call there.
struct RefX
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
    virtual void SetFlags(unsigned);
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
    virtual NiPointer<Actor>* GetActor();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void Initialize();
    virtual void v114();
    virtual void v115();
    virtual SceneX* GetScene();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const ExplosionPosition& GetPosition();
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    HighProcess* process;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    float animationTime;
    float radius;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    IdFlagState soundAC;
    IdFlagState soundB8;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    bool disabled;

    BaseX* FUN_004181e0();
    float Explosion_GetRadius();
    void Explosion_TestExplosionUnderWater();
    void Init3D();
    bool IsNotCulled();
    void Explosion_AttachDistant();
    void* TESObjectREFR_GetWorldSpace();
    CellX* FUN_008d6f30();
    const ExplosionPosition& FUN_00430830();
    void Explosion_UpdateRadiation();
    struct ExtraX* BSFile_GetDevice();
    void UpdateCastSound();
    unsigned QUserData();
    void StartSounds();
    unsigned char GetByteAtOffsetD9();
    void UpdateExplosion();
};
extern RefX* DAT_011dea3c;
struct ExtraX
{
    void ExtraDataList_SetRadius(float);
};
struct HandlerX
{
    void PlaceObjectReference(void*, const ExplosionPosition&, const ExplosionPosition&, CellX*, void*, int, int, int);
};
extern HandlerX* DAT_011c3f2c;
extern ProcessLists DAT_011e0e80;
struct ListX
{
    void NiTPointerListBase_NiTPointerAllocator_unsigned_int_unsigned_int_AddHead(RefX* const&);
};
extern ListX DAT_011c7b8c;
struct TesX
{
    void FUN_00458e20(SceneX*, float);
};
extern TesX* DAT_011dea10;
SceneX* CreateOctahedron(float, const NiColorA*, int);
void* TESImageSpaceModifier_GetExplosionInFace();
void FUN_005299a0(void*, float, SceneX*);
float ComputeSquaredRatioComplement(float, float);
float GetAnimValueByPrefix(SceneX*, const char*, const char*);
void UpdateDistanceFade(float, const ExplosionPosition&);
float RandomFloatTwoPi();
void BSTempEffectParticle_Spawn_00689210(CellX*, float, const char*, MatrixWater, ExplosionPosition, float, int, int);
// Updates an explosion reference: scales by distance, spawns effects, updates cell membership, reacts actors, plays splash sounds and applies image-space effects.
// @fnv 0x009acd60
void RefX::UpdateExplosion()
{
    AutoMemContext memory3(49, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\AI\\Combat\\Explosion.cpp", 376);
    bool loading4 = g_BGSSaveLoadGame->BGSSaveLoadGame_GetSaveGameLoading();
    bool newProcess2 = (bool)(unsigned char)(process == 0);
    if (newProcess2)
        process = new HighProcess;
    float distance = (DAT_011dea3c->GetPosition() - GetPosition()).Length();
    float scaled = ComputeSquaredRatioComplement(Explosion_GetRadius(), distance);
    if (scaled > *DAT_011d0520.Setting_Float_00403e20() && !disabled)
        FUN_005299a0(TESImageSpaceModifier_GetExplosionInFace(), 1.0f, 0);
    Explosion_TestExplosionUnderWater();
    Init3D();
    if (IsNotCulled())
        Explosion_AttachDistant();
    else
    {
        if (!loading4 && FUN_004181e0()->EffectSetting_GetLight())
            DAT_011c3f2c->PlaceObjectReference(FUN_004181e0()->EffectSetting_GetLight(), GetPosition(), FUN_00430830(),
                                               FUN_008d6f30(), TESObjectREFR_GetWorldSpace(), 0, 0, 0);
        if (!loading4 && FUN_004181e0()->GetScaledValue() > 0.0 && FUN_004181e0()->NiAVObject_GetWorldScale() > 0.0)
        {
            Explosion_UpdateRadiation();
            BSFile_GetDevice()->ExtraDataList_SetRadius(FUN_004181e0()->GetScaledValue());
            SetFlags(0x40000000);
        }
        UpdateCastSound();
        Initialize();
        CellX* cell = FUN_008d6f30();
        if (cell)
        {
            if (!loading4)
                cell->RemoveReference(this);
            cell->AddReference(this, false);
        }
        SceneX* sceneB = GetScene();
        if (sceneB)
            sceneB->FUN_00450f90(scaled > *DAT_011d0520.Setting_Float_00403e20() && !disabled);
        if (sceneB && cell->FUN_005497a0())
            cell->FUN_005497a0()->Attach(sceneB, true);
        SceneX* node7 = sceneB ? sceneB->AsNode() : 0;
        SceneX* fade9 = node7 ? node7->AsFade() : 0;
        if (fade9)
            fade9->BSFadeNode_TurnFadeNodeOn();
        animationTime = GetAnimValueByPrefix(sceneB, "SpecialIdle_AreaEffect", "Hit");
    }
    if (!loading4)
    {
        NiPointer<Actor>* actorPointer = GetActor();
        if (actorPointer && static_cast<Actor*>(*actorPointer) && static_cast<Actor*>(*actorPointer)->FUN_008d8520())
        {
            Actor* actor = static_cast<Actor*>(*actorPointer);
            reinterpret_cast<ActorProcX*>(actor->FUN_008d8520())->React((RefX*)actor, GetPosition(), FUN_004181e0()->BGSExplosion_GetSoundLevelValue(), 2,
                                         QUserData());
        }
        StartSounds();
        if (soundAC.FUN_00ad8ce0() || soundB8.FUN_00ad8ce0())
            UpdateDistanceFade(radius * *DAT_011d0280.Setting_Float_00403e20(), GetPosition());
        if (FUN_008d6f30() && GetByteAtOffsetD9())
        {
            ExplosionPosition position8 = GetPosition();
            position8.z = FUN_008d6f30()->TESObjectCELL_GetWaterHeight();
            float size_2 = Explosion_GetRadius() / *DAT_011d0da4.Setting_Float_00403e20();
            MatrixWater rotationA;
            rotationA.FUN_004a0c90(RandomFloatTwoPi());
            BSTempEffectParticle_Spawn_00689210(DAT_011dea3c->FUN_008d6f30(), 1.0f, DAT_011d0ce4.FUN_00403df0(), rotationA, position8, size_2,
                         7, 0);
            IdFlagState sound;
            sound = BSAudio_QInstance()->BSAudio_GetSoundHandleByEditorName("CWaterExplosionSplash", 0x102);
            if (sound.FUN_00ad8ce0())
            {
                sound.FUN_00ad8b60(position8.x, position8.y, position8.z);
                sound.FUN_00ad8830(false);
            }
        }
    }
    if (*DAT_011d0a78.Setting_Int() > 0)
    {
        NiColorA params(1.0f, 1.0f, 1.0f, 0.65f);
        SceneX* effect2 = CreateOctahedron(2.5f, &params, 1);
        effect2->UpdateProperties();
        effect2->NiAVObject_SetTranslate(GetPosition());
        DAT_011dea10->FUN_00458e20(effect2, 10.0f);
    }
    if (newProcess2)
        DAT_011e0e80.ProcessLists_AddReference(this, 0, false, 0, false);
    if (*DAT_011c7ae8.FUN_00408d60())
    {
        DAT_011c7b8c.NiTPointerListBase_NiTPointerAllocator_unsigned_int_unsigned_int_AddHead(this);
    }
}

struct DRNode;

struct DRObject3D
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual DRNode* GetAsNode();
};

struct DRController
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void Stop();
};

template <class T> struct DRPointer
{
    T* m_pObject;

    ~DRPointer();
    operator T*() const;
    T* operator->() const;
    DRPointer& operator=(T* apObject);
};

struct DRItem
{
    ~DRItem();
};

struct DRItemList
{
    DRItem* pItem;
    DRItemList* pNext2;

    ~DRItemList();
    bool IsEmpty();
    DRItem** GetItem();
    void RemoveHead();
};

struct DRSoundHandle
{
    int unk00;
    int unk04;
    int unk08;

    ~DRSoundHandle();
};

struct DRCause;

struct DRCauseHolder
{
    DRCause* pCause;

    ~DRCauseHolder();
    DRCauseHolder& operator=(DRCause* apCause);
};

struct DRDeletable
{
    virtual ~DRDeletable();
};

struct DRPortalGraph
{
    void RemoveObject(DRObject3D* apObject);
};

struct DRWorld
{
    static void __cdecl RemoveObject(DRObject3D* apObject, bool abRecurse, bool abUnk);
};

struct DRCell
{
    DRWorld* GetOwningWorld();
    DRPortalGraph* GetPortalGraph();
};

struct DRDataHandler
{
    bool IsShuttingDown();
};

struct DRSetting
{
    unsigned char* Bool();
};

struct DRRefList
{
    void* GetHeadPos();
    void* GetNextPos(void* apPos);
    struct DRRef*& GetAt(void* apPos);
    struct DRRef* RemovePos(void*& arpPos);
};

void __cdecl DRDetachNode(DRNode* apNode);
bool __cdecl DRIsAttached(DRNode* apNode);

extern DRDataHandler* g_pDRDataHandler;
extern DRSetting g_kDRSetting;
extern DRRefList g_kDRRefList;

struct DRRefPrimary
{
    virtual ~DRRefPrimary();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct DRRefSecondary
{
    virtual void v00();
};

struct DRRef : DRRefPrimary, DRRefSecondary
{
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    ~DRRef();
    DRObject3D* Get3DSimple();
    DRCell* GetParentCell();
    void Explosion_FreeLight();
    void MobileObject_CleanUpOtherMobileObjects(bool abFlag);
    void Explosion_StopSounds();
};

// Retained: defining the destructor with the shared member types changes
// the original machine code at 0x009ac5a0.
struct FUN_009ac5a0 : DRRef
{
    DRPointer<DRController> spController;
    DRItemList kItems;
    DRSoundHandle kSound1;
    DRSoundHandle kSound2;
    DRPointer<DRController> m_pController;
    int unkC8;
    int unkCC;
    DRCauseHolder kCause;
    int unkD4;
    int unkD8;
    DRDeletable* pOwned;

    virtual ~FUN_009ac5a0();
};

// @fnv 0x009ac5a0
FUN_009ac5a0::~FUN_009ac5a0()
{
    if (Get3DSimple() && Get3DSimple()->GetAsNode() && DRIsAttached(Get3DSimple()->GetAsNode()))
        DRDetachNode(Get3DSimple()->GetAsNode());
    if (GetParentCell() && GetParentCell()->GetOwningWorld() && GetParentCell())
        GetParentCell()->GetOwningWorld()->RemoveObject(Get3DSimple(), true, false);
    if (0)
    {
    }
    Explosion_FreeLight();
    if (spController)
        spController->Stop();
    spController = 0;
    while (!kItems.IsEmpty())
    {
        delete *kItems.GetItem();
        kItems.RemoveHead();
    }
    if (!g_pDRDataHandler->IsShuttingDown())
        MobileObject_CleanUpOtherMobileObjects(false);
    Explosion_StopSounds();
    kCause = 0;
    if (pOwned)
        delete pOwned;
    if (*g_kDRSetting.Bool())
    {
        void* pPos7 = g_kDRRefList.GetHeadPos();
        void* pNext2 = 0;
        void* pFound = 0;
        bool bFound = false;
        while (pPos7 && !bFound)
        {
            pNext2 = g_kDRRefList.GetNextPos(pPos7);
            if (pPos7)
            {
                DRRef* pRef = g_kDRRefList.GetAt(pPos7);
                if (pRef == this)
                {
                    bFound = true;
                    pFound = pPos7;
                }
                pPos7 = pNext2;
            }
        }
        g_kDRRefList.RemovePos(pFound);
    }
    DRObject3D* p3D = Get3DSimple();
    DRCell* pCell4 = GetParentCell();
    if (pCell4)
    {
        DRPortalGraph* pGraph = pCell4->GetPortalGraph();
        if (pGraph)
            pGraph->RemoveObject(p3D);
    }
}

class SavedActorCause
{
  public:
    unsigned int FUN_00825c00();
};
class SavedActorCausePointer
{
  public:
    SavedActorCause* object;
    SavedActorCause* Modelloader_GetReferencedThis();
};
class CasterReference
{
  public:
    unsigned int FUN_0040a1e0();
};
class CasterSource
{
  public:
    unsigned int RefreshItem();
};
class ExplosionCasterData
{
  public:
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14;
    CasterReference* reference;
    CasterSource* source;
    void* weapon;
};

// The shared base has no declaration for the 0x00932880 save step.
struct MobileObjectSaveStep
{
    void MobileObject_SaveGame(BGSSaveFormBuffer*);
};

// Writes explosion save fields, actor cause ID, and optional caster data to the save buffer.
// @fnv 0x009b2040
void Explosion::WriteToSaveBuffer(BGSSaveFormBuffer* buffer)
{
    reinterpret_cast<MobileObjectSaveStep*>(this)->MobileObject_SaveGame(buffer);
    buffer->FUN_00865e50(&m_fFirstFloatValue, 4, 0);
    buffer->FUN_00865e50(&f3DLifetime, 4, 0);
    buffer->FUN_00865e50(&fOuterRadius, 4, 0);
    buffer->FUN_00865e50(&ExplosionRuntimeData, 4, 0);
    buffer->FUN_00865e50(&ReferenceCauseInfo, 1, 0);
    buffer->FUN_00865e50(&m_iValueE4, 4, 0);
    buffer->FUN_00865e50(&fInnerRadius, 4, 0);
    buffer->FUN_00865e50(&m_fFourthRecordValue, 4, 0);
    buffer->FUN_00865e50(&MagicWeaponState, 1, 0);
    buffer->FUN_00865e50(&bUnderwater, 1, 0);
    buffer->FUN_00865e50(&kClosestPoint, 12, 0);
    buffer->FUN_00865e50(&kClosestPointNormal, 12, 0);
    buffer->FUN_00865e50(&m_fClosestPointScalar, 4, 0);
    buffer->FUN_00865df0(pOwnerRef, 0);
    buffer->FUN_00865df0(ReferenceSoundCauseData, 0);
    buffer->FUN_00865df0(m_pFiringWeapon, 0);
    unsigned int causeID = reinterpret_cast<SavedActorCausePointer&>(m_pActorCause).Modelloader_GetReferencedThis() ? reinterpret_cast<SavedActorCausePointer&>(m_pActorCause).Modelloader_GetReferencedThis()->FUN_00825c00() : -1;
    buffer->FUN_00865e50(&causeID, 4, 0);
    bool casterPresent = reinterpret_cast<ExplosionCasterData*>(m_pEffectInstance);
    buffer->FUN_00865e50(&casterPresent, 1, 0);
    if (casterPresent)
    {
        buffer->FUN_00865db0(reinterpret_cast<ExplosionCasterData*>(m_pEffectInstance)->reference ? reinterpret_cast<ExplosionCasterData*>(m_pEffectInstance)->reference->FUN_0040a1e0() : 0, 0);
        buffer->FUN_00865db0(reinterpret_cast<ExplosionCasterData*>(m_pEffectInstance)->source ? reinterpret_cast<ExplosionCasterData*>(m_pEffectInstance)->source->RefreshItem() : 0, 0);
        buffer->FUN_00865df0(reinterpret_cast<ExplosionCasterData*>(m_pEffectInstance)->weapon, 0);
    }
}

struct Base1
{
    int unk00;
};
struct Base2
{
    int unk04;
};
struct FUN_0057c400_shell
{
    Base2* bhkTTNode_TESObjectREFR_GetEntry(int a);
};
// TESObjectREFR.h does not declare this adjusted-result helper.
struct FUN_00576870_cls
{
    int unk00;
    FUN_0057c400_shell m_sub;
    Base1* ZoneEntry_GetZoneEntry_0(int a);
};
struct Derived : Base1, Base2
{
};

// Calls m_sub.FUN_0057c400(a) and returns the result cast to Derived*.
// @fnv 0x00576870
// src: COMMUNITY 0x00576870
Base1* FUN_00576870_cls::ZoneEntry_GetZoneEntry_0(int a)
{
    return static_cast<Derived*>(m_sub.bhkTTNode_TESObjectREFR_GetEntry(a));
}
