#include "../../../../include/BSSimpleArray.h"
// src/fallout/ai/combat/hitdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/hitdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/Actor.h"
#include "../../../../include/BGSBodyPart.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/Setting.h"

struct FUN_009b7040_shell
{
    float GetField168();
};

// @fnv 0x009b7040
float FUN_009b7040_shell::GetField168()
{
    return *(float*)((char*)this + 0x168);
}

struct FUN_009b73b0_shell
{
    char GetByteAtOffset() const;
};

// @fnv 0x009b73b0
char FUN_009b73b0_shell::GetByteAtOffset() const
{
    return *(char*)((char*)this + 0x1c8);
}

struct FUN_009b7840_shell
{
    void RaiseMaxValue(float a);
};

// If a exceeds the float at offset 0x5c, stores a there, keeping the larger of the two.
// @fnv 0x009b7840
void FUN_009b7840_shell::RaiseMaxValue(float afValue)
{
    if (afValue > *((float*)((char*)this + 0x5c)))
    {
        *((float*)((char*)this + 0x5c)) = afValue;
    }
}

// Returns true for the index values 0, 1, 2, 16, 17, 20 and 21, and false for any other value.
// @fnv 0x0066de30
// src: XBOX_PDB 0x0066de30
bool ActionPoints_IsMeleeAttackAction(int a)
{
    switch (a)
    {
    case 0:
    case 1:
    case 2:
    case 16:
    case 17:
    case 20:
    case 21:
        return true;
    default:
        return false;
    }
}

extern float DAT_011f4270;
extern float DAT_011f4274;

extern NiPoint3 _NiPoint3_ZERO;

// HitData is 0x64 bytes; keep its local definition until include/HitData.h is available.
class HitData
{
  public:
    void* m_pAggressor;
    void* pTarget;
    void* m_pSourceReference;
    unsigned int m_uiHitLocation;
    unsigned int m_uiHitFlags;
    float m_fDamage;
    float m_fArmorDamage;
    float m_fHealthDamage;
    float m_fLimbDamage;
    float m_fFatigueDamage;
    float m_fSneakAttackMultiplier;
    float m_fCriticalHitMultiplier;
    void* pWeapon;
    float m_fWeaponDamage;
    NiPoint3 vOffset1;
    NiPoint3 vOffset2;
    void* m_pHitDataObjectAtOffset50;
    void* m_pHitDataObjectAtOffset54;
    unsigned int uiFlags;
    float m_fHitValueAtOffset5C;
    int BackgroundTask;
    void ClearData_009b4dc0();
    void Copy_009b4ec0(const HitData& src);
};

// @fnv 0x009b4dc0
// src: XBOX_PDB 0x009b4dc0
void HitData::ClearData_009b4dc0()
{
    m_pAggressor = 0;
    pTarget = 0;
    m_pSourceReference = 0;
    m_uiHitLocation = 0x4d;
    m_uiHitFlags = 0xffffffff;
    m_fDamage = 0.0f;
    m_fArmorDamage = 0.0f;
    m_fHealthDamage = 0.0f;
    m_fLimbDamage = 0.0f;
    m_fFatigueDamage = 0.0f;
    m_fSneakAttackMultiplier = 0.0f;
    m_fCriticalHitMultiplier = 0.0f;
    vOffset1 = _NiPoint3_ZERO;
    vOffset2 = _NiPoint3_ZERO;
    pWeapon = 0;
    m_fWeaponDamage = 0.0f;
    m_pHitDataObjectAtOffset50 = 0;
    m_pHitDataObjectAtOffset54 = 0;
    uiFlags = 0;
    BackgroundTask = 0;
    m_fHitValueAtOffset5C = 0.0f;
}

struct GlobalObject_00869f00
{
    void Clear(bool a);
};

extern int DAT_0108f9e8;

struct FUN_009b7970_shell
{
    void InitializeAndClear();
};

// @fnv 0x009b7970
void FUN_009b7970_shell::InitializeAndClear()
{
    *reinterpret_cast<int*>(this) = (int)&DAT_0108f9e8;
    reinterpret_cast<GlobalObject_00869f00*>(this)->Clear(true);
}

struct FUN_009b7010_shell
{
    NiPoint3& Projectile_GetMovementDirection(NiPoint3& akDest);
};
// Copies the NiPoint3 stored at offset 0x104 of this object into akDest and returns it.
// @fnv 0x009b7010
// src: COMMUNITY 0x009b7010
NiPoint3& FUN_009b7010_shell::Projectile_GetMovementDirection(NiPoint3& akDest)
{
    akDest = *reinterpret_cast<const NiPoint3*>(reinterpret_cast<const char*>(this) + 0x104);
    return akDest;
}

struct AX
{
    void BSSimpleArray_float_1024_InitialSetup(unsigned int a, unsigned int b);
};
struct FUN_009b7940_shell
{
    int* vtable;
    void BSSimpleArray_float_1024_InitialSetup(unsigned int a, unsigned int b);
    FUN_009b7940_shell* Initialize();
};
// Sets the vtable to DAT_0108f9e8, calls FUN_006b3eb0 with 0, 0, and returns this.
// @fnv 0x009b7940
FUN_009b7940_shell* FUN_009b7940_shell::Initialize()
{
    vtable = &DAT_0108f9e8;
    BSSimpleArray_float_1024_InitialSetup(0, 0);
    return this;
}


struct WeightedResultList
{
    BSSimpleArray<void*, 1024> kResults;
    BSSimpleArray<void*, 1024> kWeights;
    int m_iTotalWeight;
    void BSWeightedRandom_BGSBodyPart_AddWeightedResult(BGSBodyPart* aResult, unsigned int aiWeight);
};
// @fnv 0x009b7990
// src: XBOX_PDB 0x009b7990
void WeightedResultList::BSWeightedRandom_BGSBodyPart_AddWeightedResult(BGSBodyPart* aResult, unsigned int aiWeight)
{
    m_iTotalWeight += aiWeight;
    kWeights.Add((void*&)aiWeight);
    kResults.Add((void*&)aResult);
}

extern "C" void __cdecl Deallocate(void*);
struct FUN_009ca4c0_shell
{
    void FreeStoredPointer();
};
// If the pointer at offset 0x14 is set, deallocates it and clears that field.
// @fnv 0x009ca4c0
void FUN_009ca4c0_shell::FreeStoredPointer()
{
    if (*(void**)((char*)this + 0x14))
    {
        void* p = *(void**)((char*)this + 0x14);
        Deallocate(p);
        *(void**)((char*)this + 0x14) = 0;
    }
}

struct BaseS
{
    char data[12];
    BaseS();
};
struct FUN_009b4d90
{
    char _pad[56];
    BaseS m1;
    BaseS m2;
    FUN_009b4d90();
};
// Constructs the object by calling FUN_009b4dc0 on this.
// @fnv 0x009b4d90
FUN_009b4d90::FUN_009b4d90()
{
    ((HitData*)this)->ClearData_009b4dc0();
}

// @fnv 0x009b4ec0
// src: XBOX_PDB 0x009b4ec0
void HitData::Copy_009b4ec0(const HitData& src)
{
    m_pAggressor = src.m_pAggressor;
    pTarget = src.pTarget;
    m_pSourceReference = src.m_pSourceReference;
    m_uiHitLocation = src.m_uiHitLocation;
    m_uiHitFlags = src.m_uiHitFlags;
    m_fDamage = src.m_fDamage;
    m_fArmorDamage = src.m_fArmorDamage;
    m_fHealthDamage = src.m_fHealthDamage;
    m_fLimbDamage = src.m_fLimbDamage;
    m_fFatigueDamage = src.m_fFatigueDamage;
    m_fSneakAttackMultiplier = src.m_fSneakAttackMultiplier;
    m_fCriticalHitMultiplier = src.m_fCriticalHitMultiplier;
    vOffset1 = src.vOffset1;
    vOffset2 = src.vOffset2;
    pWeapon = src.pWeapon;
    m_fWeaponDamage = src.m_fWeaponDamage;
    m_pHitDataObjectAtOffset50 = src.m_pHitDataObjectAtOffset50;
    m_pHitDataObjectAtOffset54 = src.m_pHitDataObjectAtOffset54;
    uiFlags = src.uiFlags;
    m_fHitValueAtOffset5C = src.m_fHitValueAtOffset5C;
}

struct SpawnObj
{
    unsigned int unk00;
    unsigned char flag4;
};

struct SpawnLocal
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    float unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    SpawnLocal();
    void FUN_00407e00(unsigned int a, bool b);
};

void __cdecl SetContextInfo(SpawnLocal* ctx, SpawnObj* p);

// @fnv 0x009b4fe0
// src: COMMUNITY 0x009b4fe0
float __cdecl HitData_PredictVATSCommandHealthDamage(SpawnObj* pSpawnObj)
{
    if (pSpawnObj == 0)
    {
        return 0.0f;
    }
    SpawnLocal L;
    L.FUN_00407e00(0x800, true);
    L.FUN_00407e00(0x1000, true);
    unsigned char saved = pSpawnObj->flag4;
    pSpawnObj->flag4 = 1;
    SetContextInfo(&L, pSpawnObj);
    pSpawnObj->flag4 = saved;
    return L.unk14;
}

struct SpawnedSub
{
    unsigned int unk00[4];
    SpawnedSub();
};

struct SpawnedBase
{
    SpawnedBase();
    ~SpawnedBase()
    {}
};

struct FUN_009b7870 : SpawnedBase
{
    unsigned int unk00[4];
    SpawnedSub m10;
    unsigned int m20;
    FUN_009b7870();
};

// Initializes the object by setting m20 to 0.
// @fnv 0x009b7870
FUN_009b7870::FUN_009b7870()
{
    m20 = 0;
}

void __cdecl ApplyPerkModifiers(int aeEntry, Actor* apActor, ...);
float __cdecl GetWeaponDPS(void* apOwner, void* apWeapon);
float& __fastcall Setting_Float_00403e20(float* apSetting);
unsigned int __cdecl FUN_00487f50();
extern unsigned int DAT_011ca278;
extern int DAT_011ce46c;
extern int DAT_011ce858;
extern int DAT_011ce57c;
extern const double DAT_01012060;

struct FUN_009b7060_weapon
{
    unsigned short GetShortAtOffset1C0();
    bool GetByteAtOffset();
    unsigned int GetField1CC();
};

// Actor.h does not yet declare the detection query at 0x0088b880.
// Keep only that external method declaration here until it is shared.
struct ActorDetectionQuery
{
    bool Actor_LineOfSight(int, Actor*, int, int, int);
};

struct FUN_009b7060_shell
{
    Actor* pSource;
    Actor* pTarget;
    char pad[0x14 - 0x08];
    float afDamageAmount;
    char padCur[0x30 - 0x18];
    FUN_009b7060_weapon* pWeapon;
    char kad[0x50 - 0x34];
    unsigned int uiValue;
    int iValue;
    bool EffectSetting_IsFlagSetAny(int aeFlag);
    void FUN_00407e00(int aeFlag, bool abSet);
    void ApplyCriticalHit();
};

// @fnv 0x009b7060
void FUN_009b7060_shell::ApplyCriticalHit()
{
    if (pTarget && reinterpret_cast<MagicTarget*>((char*)pTarget + 0x94)->CanReceiveMagicEffects())
        return;
    if (EffectSetting_IsFlagSetAny(0x800))
        return;

    float fLimbDamage4 = 0.0f;
    float fCritChance =
        GetWeaponDPS(pSource ? (char*)pSource + 0xa4 : 0, pWeapon ? pWeapon : (FUN_009b7060_weapon*)DAT_011ca278);
    ApplyPerkModifiers(1, pSource, pWeapon ? pWeapon : (FUN_009b7060_weapon*)DAT_011ca278, pTarget, &fCritChance);
    ApplyPerkModifiers(0x24, pTarget, pWeapon ? pWeapon : (FUN_009b7060_weapon*)DAT_011ca278, pSource, &fCritChance);
    if (iValue)
        fCritChance += Setting_Float_00403e20((float*)&DAT_011ce46c);
    fCritChance *= 10.0;

    if (pSource && pSource->IsPlayerRef() && pTarget && pTarget->IsActor() &&
        !pTarget->HasHealth(false) && pSource->FUN_004997b0() &&
        !pTarget->IsCombatTargetHostile(pSource))
    {
        bool cDetected = reinterpret_cast<ActorDetectionQuery*>(pTarget)->Actor_LineOfSight(0, pSource, 1, 0, 0);
        int iDetection = pTarget->CalculateDetectionLevel(0, pSource, &cDetected, false, 0, false, 0);
        if (iDetection <= 0)
        {
            fCritChance *= Setting_Float_00403e20((float*)&DAT_011ce858);
            FUN_00407e00(0x400, true);
        }
    }

    int iNewRoll = FUN_00487f50() % 1000;
    if (iNewRoll < (int)fCritChance)
    {
        FUN_00407e00(4, true);
        FUN_009b7060_weapon* pCritWeapon = pWeapon ? pWeapon : (FUN_009b7060_weapon*)DAT_011ca278;
        if (pCritWeapon)
        {
            fLimbDamage4 =
                pWeapon ? (double)pWeapon->GetShortAtOffset1C0() : afDamageAmount * Setting_Float_00403e20((float*)&DAT_011ce57c);
            ApplyPerkModifiers(2, pSource, pCritWeapon, pTarget, &fLimbDamage4);
            if (fLimbDamage4 > DAT_01012060)
                afDamageAmount += fLimbDamage4;
            FUN_00407e00(8, pCritWeapon->GetByteAtOffset());
            uiValue = pCritWeapon->GetField1CC();
        }
    }
}

namespace fnv_009b73d0 {
struct Item;
struct Process;
struct ActorBase;
struct Parts;
struct Part;
struct Process
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
    virtual Item* GetItem();
};
struct ActorBase
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
    virtual Parts* GetParts();
};
struct Item
{
    Parts* Flags();
    float Health(int);
};
struct Parts
{
    bool Special();
    Part* Find(int);
};
struct Part
{
    bool Valid();
    unsigned char Chance();
    bool Critical();
    signed char ValueIndex();
};
// Record behind the hit data's +0x54 pointer (VATS queued action); ApplyDamageEffects (0x009b73d0) reads only the
// shot count byte at +0x08. Not the console-command Command.
struct VATSQueuedAction
{
    int unk00;
    int unk04;
    unsigned char count;
};
struct Weapon
{
    bool Check();
};
extern Setting originalRuntimeFloatSetting748;
extern Setting g_011cf794;
extern Weapon* DAT_011ca278;
void Compute(ActorValueOwner*, Weapon*, int, int, int, bool, bool*, bool*);
struct Hit
{
    Actor* source;
    Actor* target;
    void* ref;
    int skill;
    int limb;
    float health;
    float total;
    float fatigue;
    float limbDamage;
    float blocked;
    float armor;
    float weaponDamage;
    Weapon* weapon;
    float weaponHealth;
    NiPoint3 offset1;
    NiPoint3 offset2;
    void* critical;
    VATSQueuedAction* command;
    unsigned flags;
    float bonus;
    int refs;
    bool GetFlag(unsigned);
    void SetFlag(unsigned, bool);
    void ApplyDamageEffects();
};
// @fnv 0x009b73d0
void Hit::ApplyDamageEffects()
{
    if (!target || !target->IsActor())
        return;
    if (reinterpret_cast<MagicTarget*>((char*)target + 0x94)->CanReceiveMagicEffects())
        return;
    if (bonus > 0.0)
    {
        if (bonus >= 1.0 && GetFlag(0x400))
        {
            if (!weapon || weapon->Check())
                bonus *= *originalRuntimeFloatSetting748.Float();
            else
                bonus *= *g_011cf794.Float();
        }
        health *= bonus;
        if (source && !source->IsCreature() && skill == 45)
            fatigue *= bonus;
        total *= bonus;
    }
    float count = 1.0f;
    if (command && command->count > 1)
        count = command->count;
    int current = 0;
    bool guaranteed = false;
    bool criticalFlagX = false;
    if (limb == 14)
    {
        Item* item_ = reinterpret_cast<Process*>(target->FUN_008d8520())->GetItem();
        Parts* flags_ = item_ ? item_->Flags() : 0;
        if (flags_)
        {
            float itemHealth4 = item_->Health(0);
            if (itemHealth4 - limbDamage <= 0.0)
            {
                if (target->IsCreature() || flags_->Special())
                    SetFlag(0x200, true);
                else
                    SetFlag(0x100, true);
            }
        }
    }
    else if (limb != -1)
    {
        Parts* partsX = reinterpret_cast<ActorBase*>(target->Base())->GetParts();
        if (partsX)
        {
            Part* part = partsX->Find(limb);
            if (part && part->Valid())
            {
                current = part->Chance();
                criticalFlagX = part->Critical();
                guaranteed = criticalFlagX && current >= 100;
                int index7 = part->ValueIndex();
                float valueVal = target->GetCurrentActorValue(static_cast<ActorValue::Index>(index7));
                if (valueVal > 0.0 && valueVal - limbDamage <= 0.0)
                    SetFlag(0x80, true);
            }
        }
    }
    float chance9 = target->GetCurrentActorValue(static_cast<ActorValue::Index>(16));
    if (chance9 - health * count <= 0.0)
    {
        SetFlag(0x10, true);
        if (limb != -1)
        {
            bool explodeTmp = false;
            bool dismember8 = guaranteed;
            if (!dismember8)
                Compute(static_cast<ActorValueOwner*>(target), weapon ? weapon : (skill == 45 ? DAT_011ca278 : 0),
                        current, 0, 0, criticalFlagX, &explodeTmp, &dismember8);
            if (explodeTmp)
                SetFlag(0x20, true);
            if (dismember8)
                SetFlag(0x40, true);
        }
    }
}
}  // namespace fnv_009b73d0

struct FUN_00438690
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ~FUN_00438690();
};

struct Base_009b78e0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ~Base_009b78e0();
};

struct FUN_009b78e0 : Base_009b78e0
{
    FUN_00438690 m10;
    int m20;
    ~FUN_009b78e0();
};

// @fnv 0x009b78e0
FUN_009b78e0::~FUN_009b78e0()
{}

namespace n9b {
struct Tgt
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual bool v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
    virtual void v50();
    virtual void v51();
    virtual int v52();
};
struct Mgr
{
    Tgt* FUN_008d8520();
};
struct Info
{
    int m_iWordAt00;
    unsigned char m_iWordAt04;
    char pad[7];
    Tgt* m_iThirdValue;
};
struct Ctx
{
    char pad[0x54];
    Info* m_54;
};
}
extern n9b::Mgr* DAT_011dea3c;
bool __cdecl ActionPoints_IsMeleeAttackAction(int v);
void __cdecl InitHitData(n9b::Ctx* ctx, n9b::Mgr* mgr, n9b::Tgt* t, int v, bool flag);
// @fnv 0x009b5050
void __cdecl SetContextInfo(n9b::Ctx* ctx, n9b::Info* info)
{
    if (!ctx || !info || !info->m_iThirdValue)
        return;
    ctx->m_54 = info;
    bool flag = ActionPoints_IsMeleeAttackAction(info->m_iWordAt00) && info->m_iWordAt04;
    InitHitData(ctx, DAT_011dea3c, info->m_iThirdValue->v40() ? info->m_iThirdValue : 0, DAT_011dea3c->FUN_008d8520()->v52(), flag);
}
