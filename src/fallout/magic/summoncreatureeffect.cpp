#include "../../../include/SummonCreatureEffect.h"
#include "../../../include/Actor.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/ActiveEffect.h"
#include "../../../include/AssociatedItemEffect.h"
#include "../../../include/EffectSetting.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESBoundObject.h"
#include "../../../include/TESSaveLoadGame.h"

// src/fallout/magic/summoncreatureeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/summoncreatureeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void __cdecl _Deallocate(void*);

// Calls FUN_00828590, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x00828560
void* SummonCreatureEffect::FUN_00828560(unsigned int flags)
{
    FUN_00828590();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// Returns 0; the local variables are initialized to 0 and never used.
// @fnv 0x00828da0
int __thiscall SummonCreatureEffect::GetZero(int a, int b, int c)
{
    int v1 = 0;
    int v2 = 0;
    return v1;
}

// @fnv 0x00829720
// src: XBOX_PDB 0x00829720
unsigned short __thiscall SummonCreatureEffect::GetSaveSize_00829720(Actor* actor)
{
    unsigned short isize = 0;
    isize += AssociatedItemEffect::GetSaveSize(actor);
    isize += 4;
    isize += 1;
    if (!unk4C)
    {
        isize += 4;
        isize += 0xc;
        isize += 0xc;
    }
    return isize;
}

extern TESSaveLoadGame* g_TESSaveLoadGame;
// Calls the base loader, reads a 4-byte id and a byte from the save stream, stores them, and reads further fields when the id is zero and not forced.
// @fnv 0x00829850
void SummonCreatureEffect::LoadAssociatedItemEffect(Actor* actor)
{
    unsigned int id;
    unsigned char bforcedToZero;
    FUN_00806e30(actor);
    // This call consumes the forced-to-zero flag returned in AL by the numeric-ID loader.
    typedef void (__thiscall TESSaveLoadGame::*LoadNumericID)(unsigned int*, int);
    typedef unsigned char (__thiscall TESSaveLoadGame::*LoadNumericIDWithFlag)(unsigned int*, int);
    bforcedToZero = (g_TESSaveLoadGame->*reinterpret_cast<LoadNumericIDWithFlag>(
        static_cast<LoadNumericID>(&TESSaveLoadGame::FUN_00857aa0)))(&id, 4);
    unk4C = (Actor*)id;
    g_TESSaveLoadGame->ReadTypedData(&unk50, 1);
    if (!id && !bforcedToZero)
    {
        g_TESSaveLoadGame->ReadTypedData(&unk54, 4);
        g_TESSaveLoadGame->ReadTypedData(&unk58, 0xc);
        g_TESSaveLoadGame->ReadTypedData(&unk64, 0xc);
        unk70 = 0;
    }
    else
    {
        unk70 = 1;
    }
}

struct FUN_0040b800_shell
{
    void FUN_0040b800(bool);
};
// Destructor: if unk71 is set and FUN_0044ddc0() returns non-null, calls FUN_0040b800(true) on the returned shell object.
// @fnv 0x00828590
SummonCreatureEffect::~SummonCreatureEffect()
{
    if (unk71 && FUN_0044ddc0())
        ((FUN_0040b800_shell*)FUN_0044ddc0())->FUN_0040b800(true);
}

struct SelectedRecord
{
    int x;
    int y;
    int z;
};
extern void* selectionContext;
int __cdecl SummonPosSort(const void*, const void*);
void __cdecl FUN_00ec6f20(int, int, int, int);
// Collects records via GetZero, sorts them with FUN_00ec6f20, finds the first matching FUN_00828f00, copies it to output and frees the array.
// @fnv 0x00828cb0
bool SummonCreatureEffect::SelectRecord(void* context, int flags, SelectedRecord* output)
{
    SelectedRecord* entries = 0;
    int count = GetZero((int)&entries, (int)context, flags);
    if (count <= 0 || entries == 0)
        return false;
    int index = 0;
    selectionContext = context;
    FUN_00ec6f20((int)entries, count, sizeof(SelectedRecord), (int)&SummonPosSort);
    index = 0;
    while (index < count && !SummonCreatureEffect_CheckSummonLocation(flags, &entries[index]))
    {
        ++index;
    }
    if (index < count)
    {
        *output = entries[index];
        SelectedRecord* selected = entries;
        _Deallocate(selected);
        return true;
    }
    else
    {
        SelectedRecord* discarded = entries;
        _Deallocate(discarded);
        return false;
    }
}

// Exe 0x00829970: unit-local ListNode view; declarations and layout are preserved.
struct SummoncreatureeffectListNodeView
{
    void* value;
    SummoncreatureeffectListNodeView* _ref_00726070();
    bool _ref_008256d0() const;
    struct ActiveEffect** _ref_006815c0();
};
extern Actor* g_thePlayer;
struct GlobalObject2_0040c150
{
    int* Setting_Int();
};
extern GlobalObject2_0040c150 g_011d171c;
extern float DAT_01015f5c;

// @fnv 0x00829970
void SummonCreatureEffect::DispelOldestQualifyingEffect()
{
    SummoncreatureeffectListNodeView* node = (SummoncreatureeffectListNodeView*)g_thePlayer->GetActiveEffectList();
    int bestAge;
    ActiveEffect* bestEffect;
    float validCount;
    bestEffect = 0;
    validCount = DAT_01015f5c;
    bestAge = 0;
    while (node && !node->_ref_008256d0())
    {
        ActiveEffect* effect = *node->_ref_006815c0();
        EffectSetting* setting = effect->GetEffectSetting();
        if (setting->IsAssociatedFormUsed() && setting->IsFlagSet(0x40000))
        {
            ++bestAge;
            if (effect->GetAge() > validCount)
            {
                bestEffect = effect;
                validCount = effect->GetAge();
            }
        }
        node = node->_ref_00726070();
    }
    if (bestEffect && bestAge > *g_011d171c.Setting_Int())
        bestEffect->Dispel(false);
}

float NiCos(float f);
float NiSin_005c53d0(float f);
void* BSTempEffectParticle_Spawn(void* pCell, float fScale, const char* m_kModelObjectsItem, NiPoint3 point, NiPoint3 vel, float fScale2,
                   int iFlags, int iUnk);
float GetAnimValueByPrefix(void* pA, const char* m_pIdleForm, const char* pEvent);

struct S_008287e0_Model
{
    virtual void vfn00();
    virtual void vfn01();
    virtual void vfn02();
    virtual void vfn03();
    virtual void vfn04();
    virtual const char* vfn05();
};

struct S_008287e0_Base
{
    virtual void vfn00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct S_008287e0_Setting : S_008287e0_Base, S_008287e0_Model
{
};

struct S_008287e0_Item
{
    S_008287e0_Setting* FUN_00825c00();
};

struct S_008287e0_Temp
{
    void PlaySequence(const char* m_pIdleForm);
    void* FUN_00490e40();
};

struct S_008287e0_Magic
{
    void FUN_0040a420(bool b);
};

// @fnv 0x008287e0
// src: XBOX_PDB 0x008287e0
void SummonCreatureEffect::Start_008287e0()
{
    Actor* ref = FUN_0059bb30() ? FUN_0059bb30()->FUN_00822b40() : 0;
    if (!ref)
        return;

    unk64 = *ref->FUN_00430830();
    unk58 = *static_cast<const Actor*>(ref)->GetPos();
    NiPoint3 point;
    if (SelectRecord(ref, (int)unk4C, &point))
        unk58 = point;

    const char* m_pIdleForm = "SpecialIdle_SummonEffect";
    NiPoint3 vel = 64.0f * NiPoint3(-NiSin_005c53d0(-unk64.z), NiCos(-unk64.z), 0.0f);
    void* m_kModelObjectsItem =
        BSTempEffectParticle_Spawn(ref->FUN_008d6f30(), 1.0f, ((S_008287e0_Item*)GetHavokWorldObjectCountInSceneGraph_0084e3a0())->FUN_00825c00()->vfn05(), vel, unk58, 1.0f, 7, 0);
    ((S_008287e0_Temp*)m_kModelObjectsItem)->PlaySequence(m_pIdleForm);
    void* pAVObject = ((S_008287e0_Temp*)m_kModelObjectsItem)->FUN_00490e40();
    unk54 = GetAnimValueByPrefix(pAVObject, m_pIdleForm, "Hit");

    if (!unk71 && FUN_0044ddc0())
    {
        ((S_008287e0_Magic*)FUN_0044ddc0())->FUN_0040a420(false);
        unk71 = true;
    }
}

extern unsigned int DAT_011f426c;

// Constructor: sets the vtable, initialises the two sub-objects, and zeroes unk4C, unk50, unk54, unk70 and unk71.
// @fnv 0x00828470
SummonCreatureEffect::SummonCreatureEffect(MagicCaster* a1, MagicItem* a2, EffectItem* a3) : AssociatedItemEffect(a1, a2, a3)
{
    unk4C = 0;
    unk50 = 0;
    unk54 = 0.0f;
    unk58 = *(NiPoint3*)&DAT_011f426c;
    unk64 = *(NiPoint3*)&DAT_011f426c;
    unk70 = 0;
    unk71 = 0;
}

struct FUN_0044ddc0_ret
{
    void FUN_0040a420(int a1);
};

// @fnv 0x00828610
SummonCreatureEffect* SummonCreatureEffect::CloneObject()
{
    SummonCreatureEffect* obj = new SummonCreatureEffect(m_pEffectInstance, pSpell, pEffect);
    AssociatedItemEffect::CopyData(obj);
    obj->unk4C = unk4C;
    obj->unk50 = unk50;
    obj->unk54 = unk54;
    obj->unk58 = unk58;
    obj->unk64 = unk64;
    obj->unk70 = unk70;
    if (unk71 != 0 && obj->unk71 == 0 && FUN_0044ddc0())
    {
        ((FUN_0044ddc0_ret*)FUN_0044ddc0())->FUN_0040a420(0);
    }
    obj->unk71 = unk71;
    return obj;
}

// Allocates and constructs a summon effect from its caster, spell and effect item.
// @fnv 0x00828760
// src: XBOX_PDB 0x00828760
SummonCreatureEffect* __cdecl SummonCreatureEffect_Instantiate(MagicCaster* caster, MagicItem* spell, EffectItem* effect)
{
    return new SummonCreatureEffect(caster, spell, effect);
}

struct FxnNode
{
    Actor* FUN_00822b40();
    int FUN_0045cd60();
    void HighProcess_FadeAndDelete(Actor* obj);
    void FUN_0040b800(int a);
};

void __cdecl CommandEffect_CleanupCommandedActor(Actor* obj, Actor* node, int flag);

// @fnv 0x008289e0
void SummonCreatureEffect::CleanupSummonedCreature()
{
    Actor* a = (this->FUN_0059bb30() != 0) ? this->FUN_0059bb30()->FUN_00822b40() : 0;
    if (this->unk4C != 0 && a != 0)
    {
        if (this->unk4C->FUN_008d8520() != 0 && ((FxnNode*)this->unk4C->FUN_008d8520())->FUN_0045cd60() == 0)
        {
            if (!this->unk4C->HasHealth(false))
            {
                this->unk4C->Actor_Kill(0, 0.0f);
            }
            ((FxnNode*)this->unk4C->FUN_008d8520())->HighProcess_FadeAndDelete(this->unk4C);
            CommandEffect_CleanupCommandedActor(this->unk4C, a, 1);
        }
        else
        {
            CommandEffect_CleanupCommandedActor(this->unk4C, a, 1);
            this->unk4C->MarkForDeletion(true);
        }
        this->unk4C = 0;
    }
    if (this->unk71 != 0 && this->FUN_0044ddc0() != 0)
    {
        ((FxnNode*)this->FUN_0044ddc0())->FUN_0040b800(0);
        this->unk71 = 0;
    }
}

extern int g_011dcc58;
float __cdecl ComputeDirectionalFalloff(int owner, int key);

// Looks up two float values by id from g_011dcc58 and returns 0 if equal, 1 if the first is smaller, -1 otherwise.
// @fnv 0x00828b20
// src: XBOX_PDB 0x00828b20
int __cdecl SummonPosSort(int aiIdA, int aiIdB)
{
    int idA = aiIdA;
    int idB = aiIdB;
    float valueA = ComputeDirectionalFalloff(g_011dcc58, idA);
    float valueB = ComputeDirectionalFalloff(g_011dcc58, idB);
    if (valueA == valueB)
    {
        return 0;
    }
    else if (valueA < valueB)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void __cdecl CommandEffect_UpdateCommandedActor(Actor* t, Actor* actor);
extern Actor* DAT_011dea3c;

// @fnv 0x00828ba0
// src: XBOX_PDB 0x00828ba0
void SummonCreatureEffect::Update_00828ba0(int unused)
{
    Actor* actor = FUN_0059bb30() ? FUN_0059bb30()->FUN_00822b40() : 0;
    if (!actor || (unk70 && (!unk4C || unk4C->HasHealth(false))))
    {
        Dispel(false);
        return;
    }
    if (m_fEffectMagnitude >= unk54 && !unk70)
    {
        SpawnSummonedActor(actor);
        if (actor == DAT_011dea3c)
            DispelOldestQualifyingEffect();
        unk70 = 1;
    }
    if (unk4C && !unk4C->HasHealth(false))
        CommandEffect_UpdateCommandedActor(unk4C, actor);
}

extern float DAT_0101b2d0;
extern float DAT_01013d84;
extern double DAT_01011588;

struct S_00828dc0_Mat;
struct S_00828dc0_Mat
{
    float m0, m1, m2, m3, m4, m5, m6, m7, m8;
    void FUN_004a0c90(float z);
    void FUN_004b45b0(S_00828dc0_Mat* out);
};

extern S_00828dc0_Mat DAT_011a9448;

struct S_00828dc0_Obj
{
    void SubtractIntoVector(NiPoint3* out, int x);
};

void NiPoint3_TransformByMatrix3(NiPoint3* out, const NiPoint3* v, const S_00828dc0_Mat* m);
float NiAbs_00408820(float f);

// @fnv 0x00828dc0
float ComputeDirectionalFalloff(Actor* actor, S_00828dc0_Obj* obj)
{
    float low = DAT_0101b2d0;
    float high = DAT_01013d84;
    float delta[sizeof(NiPoint3) / sizeof(float)];
    obj->SubtractIntoVector(reinterpret_cast<NiPoint3*>(delta), (int)static_cast<const Actor*>(actor)->GetPos());
    float dist = reinterpret_cast<NiPoint3*>(delta)->FUN_00457990();
    float scale = 1.0f;
    if (dist < low)
        scale = dist / low;
    else if (dist < high)
        scale = (high - dist) / (high - low);
    else
        scale = 0.0f;
    NiPoint3 rot = *actor->FUN_00430830();
    S_00828dc0_Mat matrix = DAT_011a9448;
    matrix.FUN_004a0c90(rot.z);
    S_00828dc0_Mat mInv;
    matrix.FUN_004b45b0(&mInv);
    float localDir[sizeof(NiPoint3) / sizeof(float)];
    NiPoint3_TransformByMatrix3(reinterpret_cast<NiPoint3*>(localDir), reinterpret_cast<NiPoint3*>(delta), &matrix);
    reinterpret_cast<NiPoint3*>(localDir)->Unitize_004a0c10();
    float x = 1.0f - NiAbs_00408820(reinterpret_cast<NiPoint3*>(localDir)->x);
    x = x * x;
    float fy = (1.0f + reinterpret_cast<NiPoint3*>(localDir)->y) * DAT_01011588;
    return scale * x * fy;
}

extern TESSaveLoadGame* g_registrationManager;

// @fnv 0x008297a0
// src: XBOX_PDB 0x008297a0
void SummonCreatureEffect::SaveGame_008297a0(int value)
{
    FUN_00806de0((Actor*)value);
    int id = 0;
    if (unk4C != 0)
        id = unk4C->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    g_registrationManager->TESSaveLoadGame_SaveNumericID(&id, 4);
    g_registrationManager->TESSaveLoadGame_SaveGameDataOLD(&unk50, 1);
    if (unk4C == 0)
    {
        g_registrationManager->TESSaveLoadGame_SaveGameDataOLD(&unk54, 4);
        g_registrationManager->TESSaveLoadGame_SaveGameDataOLD(&unk58, 12);
        g_registrationManager->TESSaveLoadGame_SaveGameDataOLD(&unk64, 12);
    }
}

struct S_008294e0_Str
{
    char* m_data;
    unsigned short m_len;
    unsigned short m_kMaximumCorner;
    ~S_008294e0_Str();
    const char* Modelloader_GetReferencedThis();
};

struct S_008294e0_Named
{
    S_008294e0_Str AssignFromSub();
};

struct S_008294e0_Proc
{
    virtual void vp_000();
    virtual void vp_004();
    virtual void vp_008();
    virtual void vp_00C();
    virtual void vp_010();
    virtual void vp_014();
    virtual void vp_018();
    virtual void vp_01C();
    virtual void vp_020();
    virtual void vp_024();
    virtual void vp_028();
    virtual void vp_02C();
    virtual void vp_030();
    virtual void vp_034();
    virtual void vp_038();
    virtual void vp_03C();
    virtual void vp_040();
    virtual void vp_044();
    virtual void vp_048();
    virtual void vp_04C();
    virtual void vp_050();
    virtual void vp_054();
    virtual void vp_058();
    virtual void vp_05C();
    virtual void vp_060();
    virtual void vp_064();
    virtual void vp_068();
    virtual void vp_06C();
    virtual void vp_070();
    virtual void vp_074();
    virtual void vp_078();
    virtual void vp_07C();
    virtual void vp_080();
    virtual void vp_084();
    virtual void vp_088();
    virtual void vp_08C();
    virtual void vp_090();
    virtual void vp_094();
    virtual void vp_098();
    virtual void vp_09C();
    virtual void vp_0A0();
    virtual void vp_0A4();
    virtual void vp_0A8();
    virtual void vp_0AC();
    virtual void vp_0B0();
    virtual void vp_0B4();
    virtual void vp_0B8();
    virtual void vp_0BC();
    virtual void vp_0C0();
    virtual void vp_0C4();
    virtual void vp_0C8();
    virtual void vp_0CC();
    virtual void vp_0D0();
    virtual void vp_0D4();
    virtual void vp_0D8();
    virtual void vp_0DC();
    virtual void vp_0E0();
    virtual void vp_0E4();
    virtual void vp_0E8();
    virtual void vp_0EC();
    virtual void vp_0F0();
    virtual void vp_0F4();
    virtual void vp_0F8();
    virtual void vp_0FC();
    virtual void vp_100();
    virtual void vp_104();
    virtual void vp_108();
    virtual void vp_10C();
    virtual void vp_110();
    virtual void vp_114();
    virtual void vp_118();
    virtual void vp_11C();
    virtual void vp_120();
    virtual void vp_124();
    virtual void vp_128();
    virtual void vp_12C();
    virtual void vp_130();
    virtual void vp_134();
    virtual void vp_138();
    virtual void vp_13C();
    virtual void vp_140();
    virtual void vp_144();
    virtual void vp_148();
    virtual void vp_14C();
    virtual void vp_150();
    virtual void vp_154();
    virtual void vp_158();
    virtual void vp_15C();
    virtual void vp_160();
    virtual void vp_164();
    virtual void vp_168();
    virtual void vp_16C();
    virtual void vp_170();
    virtual void vp_174();
    virtual void vp_178();
    virtual void vp_17C();
    virtual void vp_180();
    virtual void vp_184();
    virtual void vp_188();
    virtual void vp_18C();
    virtual void vp_190();
    virtual void vp_194();
    virtual void vp_198();
    virtual void vp_19C();
    virtual void vp_1A0();
    virtual void vp_1A4();
    virtual void vp_1A8();
    virtual void vp_1AC();
    virtual void vp_1B0();
    virtual void vp_1B4();
    virtual void vp_1B8();
    virtual void vp_1BC();
    virtual void vp_1C0();
    virtual void vp_1C4();
    virtual void vp_1C8();
    virtual void vp_1CC();
    virtual void vp_1D0();
    virtual void vp_1D4();
    virtual void vp_1D8();
    virtual void vp_1DC();
    virtual void vp_1E0();
    virtual void vp_1E4();
    virtual void vp_1E8();
    virtual void vp_1EC();
    virtual void vp_1F0();
    virtual void vp_1F4();
    virtual void vp_1F8();
    virtual void vp_1FC();
    virtual void vp_200();
    virtual void vp_204();
    virtual void vp_208();
    virtual void vp_20C();
    virtual void vp_210();
    virtual void vp_214();
    virtual void vp_218();
    virtual void vp_21C();
    virtual void vp_220();
    virtual void vp_224();
    virtual void vp_228();
    virtual void vp_22C();
    virtual void vp_230();
    virtual void vp_234();
    virtual void vp_238();
    virtual void vp_23C();
    virtual void vp_240();
    virtual void vp_244();
    virtual void vp_248();
    virtual void vp_24C();
    virtual void vp_250();
    virtual void vp_254();
    virtual void vp_258();
    virtual void vp_25C();
    virtual void vp_260();
    virtual void vp_264();
    virtual void vp_268();
    virtual void vp_26C();
    virtual void vp_270();
    virtual void vp_274();
    virtual void vp_278();
    virtual void vp_27C();
    virtual void vp_280();
    virtual void vp_284();
    virtual void vp_288();
    virtual void vp_28C();
    virtual void vp_290();
    virtual void vp_294();
    virtual void vp_298();
    virtual void vp_29C();
    virtual void vp_2A0();
    virtual void vp_2A4();
    virtual void vp_2A8();
    virtual void vp_2AC();
    virtual void vp_2B0();
    virtual void vp_2B4();
    virtual void vp_2B8();
    virtual void vp_2BC();
    virtual void vp_2C0();
    virtual void vp_2C4();
    virtual void vp_2C8();
    virtual void vp_2CC();
    virtual void vp_2D0();
    virtual void vp_2D4();
    virtual void vp_2D8();
    virtual void vp_2DC();
    virtual void vp_2E0();
    virtual void vp_2E4();
    virtual void vp_2E8();
    virtual void vp_2EC();
    virtual void vp_2F0();
    virtual void vp_2F4();
    virtual void vp_2F8();
    virtual void vp_2FC();
    virtual void vp_300();
    virtual void vp_304();
    virtual void vp_308();
    virtual void vp_30C();
    virtual void vp_310();
    virtual void vp_314();
    virtual void vp_318();
    virtual void vp_31C();
    virtual void vp_320();
    virtual void vp_324();
    virtual void vp_328();
    virtual void vp_32C();
    virtual void vp_330();
    virtual void vp_334();
    virtual void vp_338();
    virtual void vp_33C();
    virtual void vp_340();
    virtual void vp_344();
    virtual void vp_348();
    virtual void vp_34C();
    virtual void vp_350();
    virtual void vp_354();
    virtual void vp_358();
    virtual void vp_35C();
    virtual void vp_360();
    virtual void vp_364();
    virtual void vp_368();
    virtual void vp_36C();
    virtual void vp_370();
    virtual void vp_374();
    virtual void vp_378();
    virtual void vp_37C();
    virtual void vp_380();
    virtual void vp_384();
    virtual void vp_388();
    virtual void vp_38C();
    virtual void vp_390();
    virtual void vp_394();
    virtual void vp_398();
    virtual void vp_39C();
    virtual void vp_3A0();
    virtual void vp_3A4();
    virtual void vp_3A8();
    virtual void vp_3AC();
    virtual void vp_3B0();
    virtual void vp_3B4();
    virtual void vp_3B8();
    virtual void vp_3BC();
    virtual void vp_3C0();
    virtual void vp_3C4();
    virtual void vp_3C8();
    virtual void vp_3CC();
    virtual void vp_3D0();
    virtual void vp_3D4();
    virtual void vp_3D8();
    virtual void vp_3DC();
    virtual void vp_3E0();
    virtual void vp_3E4();
    virtual void vp_3E8();
    virtual void vp_3EC();
    virtual void vp_3F0();
    virtual void vp_3F4();
    virtual void vp_3F8();
    virtual void vp_3FC();
    virtual void vp_400();
    virtual void vp_404();
    virtual void vp_408();
    virtual void vp_40C();
    virtual void vp_410();
    virtual void vp_414();
    virtual void vp_418();
    virtual void vp_41C();
    virtual void vp_420();
    virtual void vp_424();
    virtual void vp_428();
    virtual void vp_42C();
    virtual void vp_430();
    virtual void vp_434();
    virtual void vp_438();
    virtual void vp_43C();
    virtual void vp_440();
    virtual void vp_444();
    virtual void vp_448();
    virtual void vp_44C();
    virtual void vp_450();
    virtual void vp_454();
    virtual void vp_458();
    virtual void vp_45C();
    virtual void vp_460();
    virtual void vp_464();
    virtual void vp_468();
    virtual void vp_46C();
    virtual void vp_470();
    virtual void vp_474();
    virtual void vp_478();
    virtual void vp_47C();
    virtual void vp_480();
    virtual void vp_484();
    virtual void vp_488();
    virtual void vp_48C();
    virtual void vp_490();
    virtual void vp_494();
    virtual void vp_498();
    virtual void vp_49C();
    virtual void vp_4A0();
    virtual void vp_4A4();
    virtual void vp_4A8();
    virtual void vp_4AC();
    virtual void vp_4B0();
    virtual void vp_4B4();
    virtual void vp_4B8();
    virtual void vp_4BC();
    virtual void vp_4C0();
    virtual void vp_4C4();
    virtual void vp_4C8();
    virtual void vp_4CC();
    virtual void vp_4D0();
    virtual void vp_4D4();
    virtual void vp_4D8();
    virtual void vp_4DC();
    virtual void vp_4E0();
    virtual void vp_4E4();
    virtual void vp_4E8();
    virtual void vp_4EC();
    virtual void vp_4F0();
    virtual void vp_4F4();
    virtual void vp_4F8();
    virtual void vp_4FC();
    virtual void vp_500();
    virtual void vp_504();
    virtual void vp_508();
    virtual void vp_50C();
    virtual void vp_510();
    virtual void vp_514();
    virtual void vp_518();
    virtual void vp_51C();
    virtual void vp_520();
    virtual void vp_524();
    virtual void vp_528();
    virtual void vp_52C();
    virtual void vp_530();
    virtual void vp_534();
    virtual void vp_538();
    virtual void vp_53C();
    virtual void vp_540();
    virtual void vp_544();
    virtual void vp_548();
    virtual void vp_54C();
    virtual void vp_550();
    virtual void vp_554();
    virtual void vp_558();
    virtual void vp_55C();
    virtual void vp_560();
    virtual void vp_564();
    virtual void vp_568();
    virtual void vp_56C();
    virtual void vp_570();
    virtual void vp_574();
    virtual void vp_578();
    virtual void vp_57C();
    virtual void vp_580();
    virtual void vp_584();
    virtual void vp_588();
    virtual void vp_58C();
    virtual void vp_590();
    virtual void vp_594();
    virtual void vp_598();
    virtual void vp_59C();
    virtual void vp_5A0();
    virtual void vp_5A4();
    virtual void vp_5A8();
    virtual void vp_5AC();
    virtual void vp_5B0();
    virtual void vp_5B4();
    virtual void vp_5B8();
    virtual void vp_5BC();
    virtual void vp_5C0();
    virtual void vp_5C4();
    virtual void vp_5C8();
    virtual void vp_5CC();
    virtual void vp_5D0();
    virtual void vp_5D4();
    virtual void vp_5D8();
    virtual void vp_5DC();
    virtual void vp_5E0();
    virtual void vp_5E4();
    virtual void vp_5E8();
    virtual void vp_5EC();
    virtual void vp_5F0();
    virtual void vp_5F4();
    virtual void vp_5F8();
    virtual void vp_5FC();
    virtual void vp_600();
    virtual void vp_604();
    virtual void vp_608();
    virtual void vp_60C();
    virtual void vp_610();
    virtual void vp_614();
    virtual void vp_618();
    virtual void vp_61C();
    virtual void vp_620();
    virtual void vp_624();
    virtual void vp_628();
    virtual void vp_62C();
    virtual void vp_630();
    virtual void vp_634();
    virtual void vp_638();
    virtual void vp_63C();
    virtual void vp_640();
    virtual void vp_644();
    virtual void vp_648();
    virtual void vp_64C();
    virtual void vp_650();
    virtual void vp_654();
    virtual void vp_658();
    virtual void vp_65C();
    virtual void vp_660();
    virtual void vp_664();
    virtual void vp_668();
    virtual void vp_66C();
    virtual void vp_670();
    virtual void vp_674();
    virtual void vp_678();
    virtual void vp_67C();
    virtual void vp_680();
    virtual void vp_684();
    virtual void vp_688();
    virtual void vp_68C();
    virtual void vp_690();
    virtual void SetSomething(int a);
};

struct S_008294e0_Handler
{
    Actor* PlaceObjectReference(TESBoundObject* obj, NiPoint3* pos, NiPoint3* rot, int cell,
                                         int a, int b, int c);
};
extern S_008294e0_Handler* DAT_011c3f2c;

void __cdecl Warning_005b5e40(const char* fmt, ...);
void __cdecl StartHostilityAndCombat(Actor* ref, Actor* actor);

// @fnv 0x008294e0
void SummonCreatureEffect::SpawnSummonedActor(int unused)
{
    // This call passes a context argument to the shared cell lookup entry point.
    typedef LookTarget* (__thiscall TESForm::*CellLookup)();
    typedef int (__thiscall TESForm::*CellLookupWithContext)(int);
    Actor* actor = FUN_0059bb30() ? FUN_0059bb30()->FUN_00822b40() : 0;
    if (!actor)
        return;
    Actor* ref;
    TESBoundObject* pCreatureForm = dynamic_cast<TESBoundObject*>((TESForm*)FUN_006733e0());
    if (!pCreatureForm)
    {
        Warning_005b5e40("GAME EFFECTS: %s effect has no associated creature.",
                     ((S_008294e0_Named*)FUN_007df1d0())->AssignFromSub().Modelloader_GetReferencedThis());
    }
    else
    {
        ref = DAT_011c3f2c->PlaceObjectReference(pCreatureForm, &unk58, &unk64,
                                                 (actor->*reinterpret_cast<CellLookupWithContext>(static_cast<CellLookup>(&Actor::FUN_008d6f30)))(actor->TESObjectREFR_GetWorldSpace()), 0, 0, 0);
        if (ref)
        {
            if (ref->IsActor())
            {
                unk4C = ref;
                unk4C->TESObjectREFR_SetLocationOnReference(&unk58);
                unk4C->vfn_01fc(false);
                unk4C->Unk_98();
                StartHostilityAndCombat(unk4C, actor);
                ((S_008294e0_Proc*)unk4C->FUN_008d8520())->SetSomething(1);
            }
            else
            {
                Warning_005b5e40("GAME EFFECTS: %s summoned a non-actor.", actor->TESObjectREFR_GetFullName());
                ref->SetDeleted(true);
            }
        }
        else if (!pCreatureForm)
        {
            Warning_005b5e40("DEFAULT: %s effect unable to create reference.",
                         ((S_008294e0_Named*)FUN_007df1d0())->AssignFromSub().Modelloader_GetReferencedThis());
        }
    }
}

TESForm* __cdecl TESForm_GetFormByNumericID(unsigned int);
// Calls the base handler, resolves unk4C to an Actor via FUN_004839c0, and dispels the effect if the lookup fails.
// @fnv 0x00829900
// src: XBOX_PDB 0x00829900
void SummonCreatureEffect::InitLoadGame_00829900(void* arg)
{
    AssociatedItemEffect::FUN_00806e70((Actor*)arg);
    int iFormId = (int)unk4C;
    if (iFormId)
    {
        unk4C = dynamic_cast<Actor*>(TESForm_GetFormByNumericID((unsigned int)iFormId));
        if (!unk4C)
            ((ActiveEffect*)this)->Dispel(true);
    }
}
