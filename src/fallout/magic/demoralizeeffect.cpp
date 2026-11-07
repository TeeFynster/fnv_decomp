// src/fallout/magic/demoralizeeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/demoralizeeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/DemoralizeEffect.h"
#include "../../../include/Actor.h"
#include "../../../include/MagicTarget.h"
#include "../../../include/CombatController.h"
#include "../../../include/TESSaveLoadGame.h"

// Returns the save size of the effect: the base ActiveEffect save size plus one byte.
// @fnv 0x0080ccf0
unsigned short DemoralizeEffect::GetSaveSize(Actor* apActor)
{
    unsigned short isize = 0;
    isize += ActiveEffect::GetSaveSize(apActor);
    isize += 1;
    return isize;
}

// @fnv 0x0080c890
DemoralizeEffect::DemoralizeEffect(MagicCaster* a, MagicItem* pItem, EffectItem* pEffectItem)
    : ActiveEffect(a, pItem, pEffectItem)
{
    m_bDemoralized = 0;
}

extern TESSaveLoadGame* g_TESSaveLoadGame;

// @fnv 0x0082b750
void DemoralizeEffect::SaveGame(Actor* apActor)
{
    ActiveEffect::SaveGame(apActor);
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&m_bDemoralized, 1);
}

struct PackageNodeHandler
{
    virtual void method000();
    virtual void method001();
    virtual void method002();
    virtual void method003();
    virtual void method004();
    virtual void method005();
    virtual void method006();
    virtual void method007();
    virtual void method008();
    virtual void method009();
    virtual void method010();
    virtual void method011();
    virtual void method012();
    virtual void method013();
    virtual void method014();
    virtual void method015();
    virtual void method016();
    virtual void method017();
    virtual void method018();
    virtual void method019();
    virtual void method020();
    virtual void method021();
    virtual void method022();
    virtual void method023();
    virtual void method024();
    virtual void method025();
    virtual void method026();
    virtual void method027();
    virtual void method028();
    virtual void method029();
    virtual void method030();
    virtual void method031();
    virtual void method032();
    virtual void method033();
    virtual void method034();
    virtual void method035();
    virtual void method036();
    virtual void method037();
    virtual void method038();
    virtual void method039();
    virtual void method040();
    virtual void method041();
    virtual void method042();
    virtual void method043();
    virtual void method044();
    virtual void method045();
    virtual void method046();
    virtual void method047();
    virtual void method048();
    virtual void method049();
    virtual void method050();
    virtual void method051();
    virtual void method052();
    virtual void method053();
    virtual void method054();
    virtual void method055();
    virtual void method056();
    virtual void method057();
    virtual void method058();
    virtual void method059();
    virtual void method060();
    virtual void method061();
    virtual void method062();
    virtual void method063();
    virtual void method064();
    virtual void method065();
    virtual void method066();
    virtual void method067();
    virtual void method068();
    virtual void method069();
    virtual void method070();
    virtual void method071();
    virtual void method072();
    virtual void method073();
    virtual void method074();
    virtual void method075();
    virtual void method076();
    virtual void method077();
    virtual void method078();
    virtual void method079();
    virtual void method080();
    virtual void method081();
    virtual void method082();
    virtual void method083();
    virtual void method084();
    virtual void method085();
    virtual void method086();
    virtual void method087();
    virtual void method088();
    virtual void method089();
    virtual void method090();
    virtual void method091();
    virtual void method092();
    virtual void method093();
    virtual void method094();
    virtual void method095();
    virtual void method096();
    virtual void method097();
    virtual void method098();
    virtual void method099();
    virtual void method100();
    virtual void method101();
    virtual void method102();
    virtual void method103();
    virtual void method104();
    virtual void method105();
    virtual void method106();
    virtual void method107();
    virtual void method108();
    virtual void method109();
    virtual void method110();
    virtual void method111();
    virtual void method112();
    virtual void method113();
    virtual void method114();
    virtual void method115();
    virtual void method116();
    virtual void method117();
    virtual void method118();
    virtual void method119();
    virtual void method120();
    virtual void method121();
    virtual void method122();
    virtual void method123();
    virtual void method124();
    virtual void method125();
    virtual void method126();
    virtual void method127();
    virtual void method128();
    virtual void method129();
    virtual void method130();
    virtual void method131();
    virtual void method132();
    virtual void method133();
    virtual void method134();
    virtual void method135();
    virtual void method136();
    virtual void method137();
    virtual void method138();
    virtual void method139();
    virtual void method140();
    virtual void method141();
    virtual void method142();
    virtual void method143();
    virtual void method144();
    virtual void method145();
    virtual void method146();
    virtual void method147();
    virtual void method148();
    virtual void method149();
    virtual void method150();
    virtual void method151();
    virtual void method152();
    virtual void method153();
    virtual void method154();
    virtual void method155();
    virtual void method156();
    virtual void method157();
    virtual void method158();
    virtual void method159();
    virtual void method160();
    virtual void method161();
    virtual void method162();
    virtual void method163();
    virtual void method164();
    virtual void method165();
    virtual void method166();
    virtual void method167();
    virtual void method168();
    virtual void method169();
    virtual void method170();
    virtual void method171();
    virtual void method172();
    virtual void method173();
    virtual void method174();
    virtual void method175();
    virtual void method176();
    virtual void method177();
    virtual void method178();
    virtual void method179();
    virtual void method180();
    virtual void method181();
    virtual void method182();
    virtual void method183();
    virtual void method184();
    virtual void method185();
    virtual void method186();
    virtual void method187();
    virtual void method188();
    virtual void method189();
    virtual void method190();
    virtual void method191();
    virtual void method192();
    virtual void method193();
    virtual void method194();
    virtual void method195();
    virtual void method196();
    virtual void method197();
    virtual void method198();
    virtual void method199();
    virtual void method200();
    virtual void method201();
    virtual void method202();
    virtual void method203();
    virtual void method204();
    virtual void method205();
    virtual void method206();
    virtual void Restore(Actor*, Actor*, int, int, int, int, int, int, int, int, int, int, int);
};

// @fnv 0x0080cb60
void DemoralizeEffect::Finish()
{
    if (!m_bDemoralized)
        return;
    Actor* target = FUN_0059bb30() ? FUN_0059bb30()->FUN_00822b40() : 0;
    Actor* caster = FUN_0045cd60() ? FUN_0045cd60()->GetCasterActor() : 0;
    if (target)
    {
        if (target->Actor_IsInCombat())
        {
            target->Unk_10D(caster);
            if (caster && target->FUN_008d8520())
            {
                reinterpret_cast<PackageNodeHandler*>(target->FUN_008d8520())->Restore(target, caster, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
            }
        }
        else if (target->Actor_IsFleeing(0))
            target->Actor_RemoveFleeTarget(caster);
    }
}

// @fnv 0x0080cc70
ActiveEffect* __cdecl CreateDemoralizeEffect(MagicCaster* caster, MagicItem* item, EffectItem* effect)
{
    return new DemoralizeEffect(caster, item, effect);
}

// @fnv 0x0080c8d0
ActiveEffect* DemoralizeEffect::Copy()
{
    DemoralizeEffect* obj = ::new DemoralizeEffect(m_pEffectInstance, pSpell, pEffect);
    obj->m_bDemoralized = m_bDemoralized;
    CopyData(obj);
    return obj;
}

extern float DAT_01012054;

// @fnv 0x0080ca50
void DemoralizeEffect::Start()
{
    Actor* caster = FUN_0059bb30() ? FUN_0059bb30()->FUN_00822b40() : 0;
    Actor* target2 = FUN_0045cd60() ? FUN_0045cd60()->GetCasterActor() : 0;
    if (caster && target2)
    {
        if (caster->GetCombatController())
        {
            // This call uses arguments absent from the shared slot 0x428 declaration.
            reinterpret_cast<CombatController* (__thiscall*)(Actor*, Actor*, int)>(
                (*reinterpret_cast<void***>(caster))[0x428 / 4])(caster, target2, 0)->FUN_008d0600();
            m_bDemoralized = 1;
        }
        else if (!caster->Actor_IsFleeing(0))
        {
            caster->Actor_EndInterruptPackage(0);
            // The shared slot 0x410 currently has no arguments; retain this call's ABI.
            reinterpret_cast<void (__thiscall*)(Actor*, Actor*, bool, bool, bool, int, int, float, float)>(
                (*reinterpret_cast<void***>(caster))[0x410 / 4])(
                    caster, target2, 1, 1, 1, 0, 0, DAT_01012054, DAT_01012054);
            m_bDemoralized = 1;
        }
    }
}

extern int DAT_011a0ef8;
extern int DAT_011a106c;

bool MagicFormulas_CheckTargetLevelMagnitude(unsigned short, float);
int FUN_00ec43fb(MagicTarget*, int, int*, int*, int);

// @fnv 0x0080c980
bool DemoralizeEffect::IsEffectValid(MagicTarget* apTarget)
{
    Actor* actor = apTarget ? apTarget->FUN_00822b40() : 0;
    if (actor != 0 && !actor->HasHealth(false) && !actor->GetIsDying() &&
        MagicFormulas_CheckTargetLevelMagnitude(actor->GetLevel_0087f9f0(), this->GetFloatAtOffset1C()))
    {
        int result = FUN_00ec43fb(apTarget, 0, &DAT_011a0ef8, &DAT_011a106c, 0);
        if (result != 0)
        {
        }
        else
        {
            if (actor->Actor_IsReanimated())
                return false;
        }
        return true;
    }
    return false;
}
