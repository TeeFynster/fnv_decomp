#include "../../../include/ActorValue.h"
#include "../../../include/NiColorA.h"
#include "../../../include/Setting.h"

#include "../../../include/AbsorbEffect.h"
#include "../../../include/MagicCaster.h"
#include "../../../include/MagicTarget.h"
#include "../../../include/EffectItem.h"
#include "../../../include/EffectSetting.h"
#include "../../../include/NiAVObject.h"
#include "../../../include/NiNode.h"

// src/fallout/magic/absorbeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/absorbeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// These serialization overrides are not declared by the approved ValueModifierEffect header.
struct EffectSerialization : ActiveEffect
{
    unsigned short GetSaveSize(Actor* apActor);
    void SaveGame(Actor* apActor);
    void LoadGame(Actor* apActor);
};

// The shared ActiveEffect interface does not expose its caster getter.
struct EffectCasterAccess
{
    MagicCaster* GetCaster();
};

// @fnv 0x00802db0
void EffectSerialization::SaveGame(Actor* apActor)
{
    ActiveEffect::SaveGame(apActor);
}

struct FUN_00803a50_shell
{
    unsigned char bFlag;  // +0x177
    void BoltShaderProperty_SetStartFromPoint(unsigned char flag);
};

// @fnv 0x00803a50
// src: COMMUNITY 0x00803a50
void FUN_00803a50_shell::BoltShaderProperty_SetStartFromPoint(unsigned char flag)
{
    ((unsigned char*)this)[0x177] = flag;
}

struct FUN_00803a90_shell
{
    void SetBoltGrowWidth(float afBoltGrowWidth);
};

// @fnv 0x00803a90
void FUN_00803a90_shell::SetBoltGrowWidth(float afBoltGrowWidth)
{
    *(float*)((char*)this + 0x13c) = afBoltGrowWidth;
}

struct FUN_00803b10_shell
{
    void SetByteAtOffset175(unsigned char value);
};

// @fnv 0x00803b10
void FUN_00803b10_shell::SetByteAtOffset175(unsigned char value)
{
    reinterpret_cast<unsigned char*>(this)[0x175] = value;
}

struct FUN_00803b50_shell
{
    void BoltShaderProperty_SetSubSegmentVariance(float value);
};
// @fnv 0x00803b50
// src: XBOX_PDB 0x00803b50
void FUN_00803b50_shell::BoltShaderProperty_SetSubSegmentVariance(float value)
{
    *(float*)((char*)this + 0x150) = value;
}

// @fnv 0x00803d00
// src: XBOX_PDB 0x00803d00
void __thiscall AbsorbEffect::FinishInitLoadGame(Actor* apActor)
{
    ValueModifierEffect::FinishLoadGameTES(apActor);
    InitBoltEffect();
}

// @fnv 0x0082a650
// src: XBOX_PDB 0x0082a650
void AbsorbEffect::CopyData_0082a650(ActiveEffect* apDestination)
{
    ValueModifierEffect::CopyData(apDestination);
}

// @fnv 0x00802dd0
void EffectSerialization::LoadGame(Actor* apActor)
{
    ActiveEffect::LoadGame(apActor);
}

void __cdecl _Deallocate(void* p);

// Calls FUN_00802e20 on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x00802df0
void* __thiscall AbsorbEffect::Destroy(unsigned int flags)
{
    this->FUN_00802e20();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00803a70_shell
{
    void BoltShaderProperty_SetNumBolts(unsigned int value);
};

// @fnv 0x00803a70
// src: XBOX_PDB 0x00803a70
void FUN_00803a70_shell::BoltShaderProperty_SetNumBolts(unsigned int value)
{
    *(unsigned int*)((char*)this + 0x128) = value;
}

struct FUN_00803b30_shell
{
    void BoltShaderProperty_SetSegmentLength(float value);
};

// @fnv 0x00803b30
// src: XBOX_PDB 0x00803b30
void FUN_00803b30_shell::BoltShaderProperty_SetSegmentLength(float value)
{
    *(float*)((char*)this + 0x144) = value;
}

// @fnv 0x00802d90
unsigned short __thiscall EffectSerialization::GetSaveSize(Actor* apActor)
{
    return ActiveEffect::GetSaveSize(apActor);
}

struct FUN_00803ab0_shell
{
    void SetArg(NiColorA p);
};
// Copies the bolt colour into the object at offset 0x154.
// @fnv 0x00803ab0
void FUN_00803ab0_shell::SetArg(NiColorA aArg)
{
    *(NiColorA*)((char*)this + 0x154) = aArg;
}

struct FUN_00803ae0_shell
{
    void SetData(NiColorA aVal);
};
// Stores the bolt colour at offset 0x164.
// @fnv 0x00803ae0
void FUN_00803ae0_shell::SetData(NiColorA aVal)
{
    *reinterpret_cast<NiColorA*>((char*)this + 0x164) = aVal;
}

void __cdecl BoltShader_Stop(NiAVObject* apSource, NiAVObject* apTarget);
// @fnv 0x00802e20
AbsorbEffect::~AbsorbEffect()
{
    BoltShader_Stop(spBolt, m_spTargetObject);
    m_spTargetObject = 0;
    if (spBolt)
    {
        NiNode* pParent = ((const NiAVObject*)(NiAVObject*)spBolt)->GetParent();
        if (pParent)
            pParent->RemoveObject(spBolt);
        spBolt = 0;
    }
}

// @fnv 0x00802cb0
AbsorbEffect::AbsorbEffect(MagicCaster* apCaster, MagicItem* apItem, EffectItem* apEffect)
    : ValueModifierEffect(apCaster, apItem, apEffect), spBolt(0), spNode50(0), spNode54(0), m_spTargetObject(0)
{
    m_spTargetObject = 0;
    spBolt = 0;
    spNode54 = 0;
    spNode50 = 0;
}

void* __cdecl operator new(unsigned int size);

// @fnv 0x00802f40
ActiveEffect* AbsorbEffect::Copy()
{
    ActiveEffect* pkClone = new AbsorbEffect(m_pEffectInstance, pSpell, pEffect);
    CopyData(pkClone);
    return pkClone;
}

// @fnv 0x00802ff0
AbsorbEffect* __cdecl CreateAbsorbRecord(MagicCaster* apCaster, MagicItem* apItem, EffectItem* apEffect)
{
    return new AbsorbEffect(apCaster, apItem, apEffect);
}

extern double DAT_01012060;

// @fnv 0x00803070
void AbsorbEffect::Start()
{
    ValueModifierEffect::Start();
    if (pEffect->GetEffectSetting()->IsFlagSet(2) != 0 || (double)fDuration == DAT_01012060)
    {
        Actor* result = ((EffectCasterAccess*)this)->GetCaster() != 0
                           ? ((EffectCasterAccess*)this)->GetCaster()->GetCasterActor()
                           : 0;
        ApplyActorValueModifier(result, -GetFloatAtOffset1C(), ActorValue::ActorValue__Index_VALUE_NONE);
    }
    RefreshPlayerActorValue();
    InitBoltEffect();
}

struct BoltAVOwner
{
    virtual void v00();
    virtual void v01();
    virtual int GetActorValueInt(int iAV);
};

struct BoltProcessStandIn;
struct BoltLOSData
{
    char pad00[0x1e];
    unsigned char bHasLOS;
};

struct BoltActorStandIn
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
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
    virtual void v113();
    virtual void v114();
    virtual void v115();

    virtual void* Get3D();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual bool IsDead(bool bNotEssential);

    char pad04[0xa4 - 4];
    BoltAVOwner kAVOwner;

    float TESObjectREFR_GetDistanceFromReference(BoltActorStandIn* pkOther, bool b1, bool b2);
    BoltProcessStandIn* FUN_008d8520();
};

struct BoltProcessStandIn
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
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
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual void v291();
    virtual void v292();
    virtual void v293();
    virtual void v294();
    virtual void v295();
    virtual void v296();
    virtual void v297();
    virtual void v298();
    virtual void v299();
    virtual void v300();
    virtual void v301();
    virtual void v302();
    virtual void v303();
    virtual void v304();
    virtual void v305();
    virtual void v306();
    virtual void v307();
    virtual void v308();
    virtual void v309();
    virtual void v310();
    virtual void v311();
    virtual void v312();
    virtual void v313();
    virtual void v314();
    virtual void v315();
    virtual void v316();
    virtual void v317();
    virtual void v318();
    virtual void v319();
    virtual void v320();
    virtual BoltLOSData* GetLOS(BoltActorStandIn* pkTarget, int iUnk);
};

extern Setting g_s_011d1aa8;
float __cdecl CombatFormulas_CalcWeaponReach(float f);

// @fnv 0x00803120
void AbsorbEffect::Update(float fTimeOffset)
{
    ValueModifierEffect::Update(fTimeOffset);
    BoltActorStandIn* pkCaster = ((EffectCasterAccess*)this)->GetCaster()
                                   ? (BoltActorStandIn*)((EffectCasterAccess*)this)->GetCaster()->GetCasterActor()
                                   : 0;
    BoltActorStandIn* pkTarget = ActiveEffect::FUN_0059bb30()
                                   ? (BoltActorStandIn*)ActiveEffect::FUN_0059bb30()->FUN_00822b40()
                                   : 0;
    if (!pEffect->GetEffectSetting()->IsFlagSet(2) && fDuration > 0.0)
    {
        int iAV = GetActorValue();
        if (pkTarget && pkTarget->kAVOwner.GetActorValueInt(GetActorValue()) <= 0.0)
            Dispel(false);
        if (!FUN_00705cf0())
            ApplyActorValueModifier((Actor*)pkCaster, -GetFloatAtOffset1C() * fTimeOffset, ActorValue::ActorValue__Index_VALUE_NONE);
    }
    if (!FUN_00705cf0() && pkTarget && pkTarget->Get3D() && !pkTarget->IsDead(false) && pkCaster && pkCaster->Get3D() &&
        !pkCaster->IsDead(false))
    {
        float fDist = pkCaster->TESObjectREFR_GetDistanceFromReference(pkTarget, false, false);
        if (fDist > CombatFormulas_CalcWeaponReach(*g_s_011d1aa8.Setting_Float_00403e20()))
            Dispel(false);
        else if (pkCaster->FUN_008d8520())
        {
            BoltLOSData* pkLOS = pkCaster->FUN_008d8520()->GetLOS(pkTarget, 0);
            if (pkLOS && !pkLOS->bHasLOS)
                Dispel(false);
        }
    }
    else
    {
        Dispel(false);
    }
    if (!FUN_00705cf0())
        Update3D_00803b70(fTimeOffset);
}

// @fnv 0x008033b0
void AbsorbEffect::Finish()
{
    ApplyEffect();
    if (pEffect->GetEffectSetting()->IsFlagSet(2))
    {
        Actor* t = ((EffectCasterAccess*)this)->GetCaster() ? ((EffectCasterAccess*)this)->GetCaster()->GetCasterActor() : 0;
        float f = GetModifiedMagnitude(GetFloatAtOffset1C());
        ApplyActorValueModifier(t, f, ActorValue::ActorValue__Index_VALUE_NONE);
    }
    BoltShader_Stop(spBolt, m_spTargetObject);
    if (spBolt)
    {
        NiNode* n = ((const NiAVObject*)(NiAVObject*)spBolt)->GetParent();
        if (n)
            n->RemoveObject(spBolt);
        spBolt = 0;
    }
}

namespace fnv_008034c0 {
void* __cdecl Object_DispatchCommandFour(unsigned int uiSize);
void __cdecl BoltFree(void* pvMem);


struct BoltExtraData
{
    int unk00, unk04, unk08, unk0c;
    BoltExtraData();
    static void* operator new(unsigned int uiSize)
    {
        return Object_DispatchCommandFour(uiSize);
    }
    static void operator delete(void* pvMem)
    {
        BoltFree(pvMem);
    }
    void BSXFlags_SetFlags(int a1, int a2);
};

struct BoltGeometry
{
    void BoltShaderProperty_SetBoltsRadius(float f);
    void FUN_00507780(float f);
    void BoltShaderProperty_SetSegmentLength(float f);
    void BoltShaderProperty_SetSegmentVariance(float f);
    void BoltShaderProperty_SetSubSegmentVariance(float f);
    void SetBoltSmallWidth(float f);
    void SetBoltGrowWidth(float f);
    void BoltShaderProperty_SetNumBolts(unsigned int ui);
    void SetArg(NiColorA kColor);
    void SetData(NiColorA kColor);
    void SetByteAtOffset175(unsigned char uc);
    void BoltShaderProperty_SetStartFromPoint(unsigned char uc);
    void BoltShaderProperty_InitSegmentData();
};

// The shared NiPointer interface does not declare this comparison helper.
template <class T> struct BoltPtr
{
    bool FUN_00822510(T* pObject) const;
};

const char* __cdecl BSXFlags_Tag();
BoltGeometry* __cdecl BoltShader_Start(NiNode* pkNode, int iFlag);

extern Setting g_s_011d1710;
extern Setting g_s_011d1c88;
extern Setting g_s_011d1af0;
extern Setting g_s_011d1d3c;
extern Setting g_s_011d1ac0;
extern Setting g_s_011d1ab4;
extern Setting g_s_011d1680;
extern Setting g_s_011d1c64;
extern Setting g_s_011d18b4;
extern Setting g_s_011d1570;
extern Setting g_s_011d1c94;
extern Setting g_s_011d1818;
extern Setting g_s_011d1830;
extern Setting g_s_011d16a4;

// The shared lookup virtual occupies 0x9c; this call site requires 0x8c.
struct BoltNodeLookup
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
    virtual NiAVObject* GetObjectByName(const NiFixedString& kName);
};

struct BoltModelInfo
{
    BoltNodeLookup* GetStringAtOffset();
};
struct BoltRoot
{
    BoltModelInfo* GetControllerManager_00496940();
};

struct BoltAttachSource
{
    NiNode* FUN_005497a0();
};

struct BoltActor
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
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
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual NiAVObject* Get3D();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual BoltRoot* GetRoot();

    BoltAttachSource* FUN_008d6f30();
};

static const char s_szSpine1[] = "Bip01 Spine1";
extern const char g_szBoltEnd[] = "";

}  // namespace fnv_008034c0

using namespace fnv_008034c0;

// Creates the effect's node, attaches it to the caster, builds the bolt geometry and sets its parameters from the global settings.
// @fnv 0x008034c0
void AbsorbEffect::InitBoltEffect()
{
    spBolt = new NiNode(0);
    BoltExtraData* pkDataZ = reinterpret_cast<BoltExtraData*>(((NiAVObject*)spBolt)->FUN_00a5bdd0(*reinterpret_cast<const NiFixedString*>(BSXFlags_Tag())));
    if (!pkDataZ)
    {
        pkDataZ = new BoltExtraData;
        ((NiAVObject*)spBolt)->AddExtraData(*reinterpret_cast<const NiFixedString*>(BSXFlags_Tag()), reinterpret_cast<NiExtraData*>(pkDataZ));
    }
    pkDataZ->BSXFlags_SetFlags(1, 1);

    BoltActor* pkAY = ActiveEffect::FUN_0059bb30()
                          ? (BoltActor*)ActiveEffect::FUN_0059bb30()->GetMagicTargetReference()
                          : 0;
    BoltActor* pkBOut = ((EffectCasterAccess*)this)->GetCaster()
                            ? (BoltActor*)((EffectCasterAccess*)this)->GetCaster()->GetCasterReference()
                            : 0;
    NiNode* pkAttachTmp;
    BoltRoot* pkRootRes;
    if (pkAY && pkBOut)
    {
        pkAttachTmp = pkAY->FUN_008d6f30()->FUN_005497a0();
        pkAttachTmp->AttachChildInAvailableSlot(static_cast<NiAVObject*>(spBolt), true);
        m_spTargetObject = 0;
        m_spTargetObject = (NiAVObject*)BoltShader_Start((NiNode*)(NiAVObject*)spBolt, 1);

        pkRootRes = pkBOut->GetRoot();
        if (pkRootRes)
        {
            spNode50 =
                pkRootRes->GetControllerManager_00496940()->GetStringAtOffset()->GetObjectByName(NiFixedString(s_szSpine1));
            if (reinterpret_cast<const BoltPtr<NiAVObject>&>(spNode50).FUN_00822510(0))
                spNode50 = pkAY->Get3D();
        }
        pkRootRes = pkAY->GetRoot();
        if (pkRootRes)
        {
            spNode54 =
                pkRootRes->GetControllerManager_00496940()->GetStringAtOffset()->GetObjectByName(NiFixedString(s_szSpine1));
            if (reinterpret_cast<const BoltPtr<NiAVObject>&>(spNode54).FUN_00822510(0))
                spNode54 = pkBOut->Get3D();
        }

        if ((BoltGeometry*)(NiAVObject*)m_spTargetObject)
        {
            ((BoltGeometry*)(NiAVObject*)m_spTargetObject)->BoltShaderProperty_SetBoltsRadius(*g_s_011d1710.Setting_Float_00403e20());
            ((BoltGeometry*)(NiAVObject*)m_spTargetObject)->FUN_00507780(*g_s_011d1c88.Setting_Float_00403e20());
            ((BoltGeometry*)(NiAVObject*)m_spTargetObject)->BoltShaderProperty_SetSegmentLength(*g_s_011d1af0.Setting_Float_00403e20());
            ((BoltGeometry*)(NiAVObject*)m_spTargetObject)->BoltShaderProperty_SetSegmentVariance(*g_s_011d1d3c.Setting_Float_00403e20());
            ((BoltGeometry*)(NiAVObject*)m_spTargetObject)->BoltShaderProperty_SetSubSegmentVariance(*g_s_011d1ac0.Setting_Float_00403e20());
            ((BoltGeometry*)(NiAVObject*)m_spTargetObject)->SetBoltSmallWidth(*g_s_011d1ab4.Setting_Float_00403e20());
            ((BoltGeometry*)(NiAVObject*)m_spTargetObject)->SetBoltGrowWidth(*g_s_011d1680.Setting_Float_00403e20());
            ((BoltGeometry*)(NiAVObject*)m_spTargetObject)->BoltShaderProperty_SetNumBolts(*g_s_011d1c64.Setting_Int());
            ((BoltGeometry*)(NiAVObject*)m_spTargetObject)->SetArg(NiColorA(*g_s_011d1c94.Setting_Float_00403e20(), *g_s_011d1570.Setting_Float_00403e20(),
                                                            *g_s_011d18b4.Setting_Float_00403e20(), 1.0f));
            ((BoltGeometry*)(NiAVObject*)m_spTargetObject)->SetData(NiColorA(*g_s_011d16a4.Setting_Float_00403e20(), *g_s_011d1830.Setting_Float_00403e20(),
                                                             *g_s_011d1818.Setting_Float_00403e20(), 1.0f));
            ((BoltGeometry*)(NiAVObject*)m_spTargetObject)->SetByteAtOffset175(0);
            ((BoltGeometry*)(NiAVObject*)m_spTargetObject)->BoltShaderProperty_SetStartFromPoint(1);
            ((BoltGeometry*)(NiAVObject*)m_spTargetObject)->BoltShaderProperty_InitSegmentData();
        }
    }
}

struct FUN_006815c0
{
    float m0;
    float m1;
    float m2;
    float m3;
    float m4;
    float m5;
    float m6;
    float m7;
    float m8;
    FUN_006815c0();
    void FUN_00a59780(float a, float b, float c);
};

struct S_00803b70_O58
{
    void AddValue(float a, float b, float c);
};

extern Setting DAT_011d1c10;
extern NiPoint3 DAT_011f426c;
extern unsigned char DAT_011db9f4;
float __cdecl NiATan2(float a, float b);

// @fnv 0x00803b70
// src: XBOX_PDB 0x00803b70
void AbsorbEffect::Update3D_00803b70(float value)
{
    if (((NiAVObject*)spNode50) && ((NiAVObject*)spNode54) && ((NiAVObject*)spBolt) && ((NiAVObject*)m_spTargetObject) && !DAT_011db9f4)
    {
        NiPoint3 v7 = DAT_011f426c;
        v7 = ((NiAVObject*)spNode50)->NiAVObject_GetWorldTranslate();
        ((NiAVObject*)spBolt)->NiAVObject_SetTranslate(&v7);
        NiPoint3 r = ((NiAVObject*)spNode54)->NiAVObject_GetWorldTranslate().SubtractIntoVector(v7);
        FUN_006815c0 mat;
        float t = r.z;
        r.z = 0.0f;
        float fPlanarLen = r.FUN_00457990();
        mat.FUN_00a59780(NiATan2(r.x, r.y), 0.0f, -NiATan2(t, fPlanarLen));
        ((NiAVObject*)spBolt)->SetRotate_0043fa80(reinterpret_cast<const void*>(&mat));
        // The original call to Setting's 0x00403e20 accessor passes an unused zero argument.
        ((S_00803b70_O58*)(NiAVObject*)m_spTargetObject)->AddValue(value, r.FUN_00457990(), *(DAT_011d1c10.*reinterpret_cast<float* (Setting::*)(int)>(&Setting::Setting_Float_00403e20))(0));
    }
}
