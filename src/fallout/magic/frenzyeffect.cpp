// src/fallout/magic/frenzyeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/frenzyeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/Actor.h"
#include "../../../include/FrenzyEffect.h"
#include "../../../include/MagicTarget.h"
#include "../../../include/TESSaveLoadGame.h"

// These base serialization entry points are absent from the approved shared header.
struct ValueModifierEffectSerialization
{
    unsigned short FUN_00802d90(Actor* apActor);
    void FUN_00802db0(Actor* apActor);
    void FUN_00802dd0(Actor* apActor);
};

// @fnv 0x0080df90
// src: XBOX_PDB 0x0080df90
unsigned short FrenzyEffect::GetSaveSize_0080df90(Actor* apActor)
{
    unsigned short isize = 0;
    isize += reinterpret_cast<ValueModifierEffectSerialization*>(this)->FUN_00802d90(apActor);
    isize += 1;
    return isize;
}

extern "C" float __cdecl BSMAX_00404010(float, float);
extern float DAT_011dc778;

// Subtracts FUN_00404010(0.0f, value) from DAT_011dc778 and stores the result back into DAT_011dc778.
// @fnv 0x0080fc90
// src: COMMUNITY 0x0080fc90
void _11DC778_Subtract(float value)
{
    DAT_011dc778 = DAT_011dc778 - BSMAX_00404010(0.0f, value);
}

extern int DAT_0107a16c;
struct ValueModifierEffectCtor
{
    void __thiscall FUN_0080dbb0_ctor(void* a, void* b, void* c);
};
// Runs the ValueModifierEffect constructor, installs the vtable pointer at DAT_0107a16c, clears the byte at offset 0x4c, and returns this.
// @fnv 0x0080dbb0
void* FrenzyEffect::ConstructFrenzyEffect(void* apArg1, void* apArg2, void* apArg3)
{
    ((ValueModifierEffectCtor*)this)->FUN_0080dbb0_ctor(apArg1, apArg2, apArg3);
    *reinterpret_cast<void**>(this) = &DAT_0107a16c;
    exhausted = 0;
    return this;
}

extern TESSaveLoadGame* g_TESSaveLoadGame;
// Calls FUN_00802db0 on the actor, then passes this+0x4c and 1 to TESSaveLoadGame::FUN_008579b0.
// @fnv 0x0080dfd0
// src: XBOX_PDB 0x0080dfd0
void __thiscall FrenzyEffect::SaveGame_0080dfd0(Actor* actor)
{
    reinterpret_cast<ValueModifierEffectSerialization*>(this)->FUN_00802db0(actor);
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&exhausted, 1);
}


// @fnv 0x0080e000
// src: XBOX_PDB 0x0080e000
void FrenzyEffect::LoadGame_0080e000(Actor* apActor)
{
    reinterpret_cast<ValueModifierEffectSerialization*>(this)->FUN_00802dd0(apActor);
    g_TESSaveLoadGame->ReadTypedData(&exhausted, 1);
}

struct Proc_S
{
    void* GetNext();
};
// Calls FUN_0082c000, resolves target and caster, and sets byte at offset 0x4c to 1 when both exist and the target check passes.
// @fnv 0x0080dd30
// src: XBOX_PDB 0x0080dd30
void FrenzyEffect::Start_0080dd30()
{
    ValueModifierEffect::Start();
    Actor* target = ActiveEffect::FUN_0059bb30() ? ActiveEffect::FUN_0059bb30()->GetOwnerActor() : 0;
    Actor* caster = ((Proc_S*)this)->GetNext() ? ((MagicCaster*)((Proc_S*)this)->GetNext())->GetCasterActor() : 0;
    if (target && caster && target->HasCombatState())
        exhausted = 1;
}

// Allocates a FrenzyEffect, copies exhausted, calls CopyData and returns the copy.
// @fnv 0x0080dbf0
// src: XBOX_PDB 0x0080dbf0
FrenzyEffect* FrenzyEffect::Copy_0080dbf0()
{
    FrenzyEffect* copy = new FrenzyEffect(m_pEffectInstance, pSpell, pEffect);
    copy->exhausted = exhausted;
    CopyData(copy);
    return copy;
}

// Allocates and constructs a FrenzyEffect from three pointers and returns it.
// @fnv 0x0080df10
void* __cdecl CreateFrenzyEffectObject(void* apFirst, void* apSecond, void* apThird)
{
    return new FrenzyEffect(apFirst, apSecond, apThird);
}

struct Population
{
    unsigned int ProcessArray_GetProcessLevelTail(unsigned int unused);
    Actor* ProcessArray_GetItem(unsigned int index);
};

struct World
{
    Population* FUN_00717e50();
};

extern "C" World DAT_011e0e80;

// @fnv 0x0080ddd0
// src: XBOX_PDB 0x0080ddd0
void FrenzyEffect::Finish_0080ddd0()
{
    ApplyEffect();
    if (exhausted)
        return;
    {
        Actor* actor = ActiveEffect::FUN_0059bb30() ? ActiveEffect::FUN_0059bb30()->FUN_00822b40() : 0;
        if (actor != 0 && actor->Actor_IsInCombat())
        {
            actor->Unk_10D(0);
            Population* pPopulation = DAT_011e0e80.FUN_00717e50();
            for (unsigned int uiIndex = 0; uiIndex < pPopulation->ProcessArray_GetProcessLevelTail(0); uiIndex++)
            {
                Actor* element = pPopulation->ProcessArray_GetItem(uiIndex);
                if (element != actor)
                {
                    Actor* pOtherActor = element != 0 && element->IsActor() ? element : 0;
                    if (pOtherActor)
                    {
                        pOtherActor->Actor_RemoveFleeTarget(actor);
                        if (pOtherActor->Actor_IsInCombat())
                            pOtherActor->Unk_10D(actor);
                    }
                }
            }
        }
    }
}

extern char DAT_011a0ef8;
extern char DAT_011a0f14;
extern "C" void* __cdecl FUN_00ec43fb(void*, long, void*, void*, int);

struct FrenzyCheckCharacter
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
    virtual bool IsDead(bool abStrict);
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
    virtual bool IsImmune();
    unsigned short GetLevel_0087f9f0();
};

bool MagicFormulas_CheckTargetLevelMagnitude(int aiLevel, float afMagnitude);

// Checks whether apTarget is a valid, non-dead, non-immune character that passes the level and magnitude check for the Frenzy effect.
// @fnv 0x0080dca0
// src: XBOX_PDB 0x0080dca0
bool FrenzyEffect::CheckTarget_0080dca0(MagicTarget* apTarget)
{
    FrenzyCheckCharacter* pChar =
        static_cast<FrenzyCheckCharacter*>(FUN_00ec43fb(apTarget, 0, &DAT_011a0ef8, &DAT_011a0f14, 0));
    if (pChar && !pChar->IsDead(false) && !pChar->IsImmune() && MagicFormulas_CheckTargetLevelMagnitude(pChar->GetLevel_0087f9f0(), GetFloatAtOffset1C()))
        return true;
    return false;
}
