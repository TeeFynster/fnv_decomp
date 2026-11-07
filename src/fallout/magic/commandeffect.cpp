
// src/fallout/magic/commandeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/commandeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/ActiveEffect.h"
#include "../../../include/ActorValueInfo.h"
#include "../../../include/BSThread.h"
#include "../../../include/MagicTarget.h"
#include "../../../include/MagicCaster.h"


class CommandEffect : public ActiveEffect
{
public:
    CommandEffect(MagicCaster*, MagicItem*, EffectItem*);
    virtual CommandEffect* Copy();
    void CheckTarget_0080b640(const char*);
    void Start_0080b660();
    void Update_0080b6f0(int);
    void Finish_0080b7c0();

    MagicCaster* FUN_0045cd60();
    void FUN_00804210(int);
};

class CommandCreatureEffect : public CommandEffect
{
public:
    CommandCreatureEffect(MagicCaster*, MagicItem*, EffectItem*);
};

// @fnv 0x0080b370
CommandCreatureEffect::CommandCreatureEffect(MagicCaster* caster, MagicItem* item, EffectItem* effect)
    : CommandEffect(caster, item, effect)
{}

// @fnv 0x0080b560
CommandEffect::CommandEffect(MagicCaster* caster, MagicItem* item, EffectItem* effect)
    : ActiveEffect(caster, item, effect)
{}

// @fnv 0x0080b590
CommandEffect* CommandEffect::Copy()
{
    CommandEffect* effect = new CommandEffect(m_pEffectInstance, pSpell, pEffect);
    CopyData(effect);
    return effect;
}

// @fnv 0x0080b640
// src: XBOX_PDB 0x0080b640
void CommandEffect::CheckTarget_0080b640(const char* apName)
{
    reinterpret_cast<const ActorValueInfo*>(this)->SetScriptName(apName);
}

void __cdecl StartHostilityAndCombat(Actor*, Actor*);

// @fnv 0x0080b660
// src: XBOX_PDB 0x0080b660
void CommandEffect::Start_0080b660()
{
    Actor* pSourceActor = FUN_0059bb30() ? FUN_0059bb30()->FUN_00822b40() : (Actor*)0;
    Actor* pCasterActor = FUN_0045cd60() ? FUN_0045cd60()->FUN_00815410() : (Actor*)0;
    if (pSourceActor && pCasterActor)
        StartHostilityAndCombat(pSourceActor, pCasterActor);
}

void CommandEffect_CleanupCommandedActor(Actor*, Actor*, int);

// @fnv 0x0080b7c0
// src: XBOX_PDB 0x0080b7c0
void CommandEffect::Finish_0080b7c0()
{
    Actor* ptarget =
        ((BSThread*)this)->GetThreadID() ? ((MagicTarget*)((BSThread*)this)->GetThreadID())->GetOwnerActor() : 0;
    Actor* pcaster = FUN_0045cd60() ? FUN_0045cd60()->GetCasterActor() : 0;
    if (ptarget && pcaster)
        CommandEffect_CleanupCommandedActor(ptarget, pcaster, 1);
}

class EffectHost
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual bool v22c(int);
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual bool v2e8();
};
void __cdecl CommandEffect_UpdateCommandedActor(void*, void*);
// @fnv 0x0080b6f0
// src: XBOX_PDB 0x0080b6f0
void CommandEffect::Update_0080b6f0(int)
{
    EffectHost* a;
    void* b;
    a = FUN_0059bb30() != 0 ? reinterpret_cast<EffectHost*>(FUN_0059bb30()->FUN_00822b40())
                                                         : 0;
    b = FUN_0045cd60() != 0 ? FUN_0045cd60()->FUN_00815410()
                                                         : 0;
    if (a != 0 && b != 0)
    {
        if (a->v22c(0) || a->v2e8())
            FUN_00804210(0);
        else
            CommandEffect_UpdateCommandedActor(a, b);
    }
}

struct B850Actor;

struct B850Package
{
    int get();
};

struct B850Process
{
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual void vfunc08C();
    virtual void vfunc090();
    virtual void vfunc094();
    virtual void vfunc098();
    virtual void vfunc09C();
    virtual void vfunc0A0();
    virtual void vfunc0A4();
    virtual void vfunc0A8();
    virtual void vfunc0AC();
    virtual void vfunc0B0();
    virtual void vfunc0B4();
    virtual void vfunc0B8();
    virtual void vfunc0BC();
    virtual void vfunc0C0();
    virtual void vfunc0C4();
    virtual void vfunc0C8();
    virtual void vfunc0CC();
    virtual void vfunc0D0();
    virtual void vfunc0D4();
    virtual void vfunc0D8();
    virtual void vfunc0DC();
    virtual void vfunc0E0();
    virtual void vfunc0E4();
    virtual void vfunc0E8();
    virtual void vfunc0EC();
    virtual void vfunc0F0();
    virtual void vfunc0F4();
    virtual void vfunc0F8();
    virtual void vfunc0FC();
    virtual void vfunc100();
    virtual void vfunc104();
    virtual void vfunc108();
    virtual void vfunc10C();
    virtual void vfunc110();
    virtual void vfunc114();
    virtual void vfunc118();
    virtual void vfunc11C();
    virtual void vfunc120();
    virtual void vfunc124();
    virtual void vfunc128();
    virtual void vfunc12C();
    virtual void vfunc130();
    virtual void vfunc134();
    virtual void vfunc138();
    virtual void vfunc13C();
    virtual void vfunc140();
    virtual void vfunc144();
    virtual void vfunc148();
    virtual void vfunc14C();
    virtual void vfunc150();
    virtual void vfunc154();
    virtual void vfunc158();
    virtual void vfunc15C();
    virtual void vfunc160();
    virtual void vfunc164();
    virtual void vfunc168();
    virtual void vfunc16C();
    virtual void vfunc170();
    virtual void vfunc174();
    virtual void vfunc178();
    virtual void vfunc17C();
    virtual void vfunc180();
    virtual void vfunc184();
    virtual void vfunc188();
    virtual void vfunc18C();
    virtual void vfunc190();
    virtual void vfunc194();
    virtual void vfunc198();
    virtual void vfunc19C();
    virtual void vfunc1A0();
    virtual void vfunc1A4();
    virtual void vfunc1A8();
    virtual void vfunc1AC();
    virtual void vfunc1B0();
    virtual void vfunc1B4();
    virtual void vfunc1B8();
    virtual void vfunc1BC();
    virtual void vfunc1C0();
    virtual void vfunc1C4();
    virtual void vfunc1C8();
    virtual void vfunc1CC();
    virtual void vfunc1D0();
    virtual void vfunc1D4();
    virtual void vfunc1D8();
    virtual void vfunc1DC();
    virtual void vfunc1E0();
    virtual void vfunc1E4();
    virtual void vfunc1E8();
    virtual void vfunc1EC();
    virtual void vfunc1F0();
    virtual void vfunc1F4();
    virtual void vfunc1F8();
    virtual void vfunc1FC();
    virtual void vfunc200();
    virtual void vfunc204();
    virtual void vfunc208();
    virtual void vfunc20C();
    virtual void vfunc210();
    virtual void vfunc214();
    virtual void vfunc218();
    virtual void vfunc21C();
    virtual void vfunc220();
    virtual void vfunc224();
    virtual void vfunc228();
    virtual void vfunc22C();
    virtual void vfunc230();
    virtual void vfunc234();
    virtual void vfunc238();
    virtual void vfunc23C();
    virtual void vfunc240();
    virtual void vfunc244();
    virtual void vfunc248();
    virtual void vfunc24C();
    virtual void vfunc250();
    virtual void vfunc254();
    virtual void vfunc258();
    virtual void vfunc25C();
    virtual void vfunc260();
    virtual void vfunc264();
    virtual void vfunc268();
    virtual void vfunc26C();
    virtual void vfunc270();
    virtual void vfunc274();
    virtual void vfunc278();
    virtual B850Package* GetCurrentPackage();
    virtual void vfunc280();
    virtual void vfunc284();
    virtual void vfunc288();
    virtual void vfunc28C();
    virtual void vfunc290();
    virtual void vfunc294();
    virtual void vfunc298();
    virtual void vfunc29C();
    virtual void vfunc2A0();
    virtual void vfunc2A4();
    virtual void vfunc2A8();
    virtual void vfunc2AC();
    virtual void vfunc2B0();
    virtual void vfunc2B4();
    virtual void vfunc2B8();
    virtual void vfunc2BC();
    virtual void vfunc2C0();
    virtual void vfunc2C4();
    virtual void vfunc2C8();
    virtual void vfunc2CC();
    virtual void vfunc2D0();
    virtual void vfunc2D4();
    virtual void vfunc2D8();
    virtual void vfunc2DC();
    virtual void vfunc2E0();
    virtual void vfunc2E4();
    virtual void vfunc2E8();
    virtual void vfunc2EC();
    virtual void vfunc2F0();
    virtual void vfunc2F4();
    virtual void vfunc2F8();
    virtual void vfunc2FC();
    virtual void vfunc300();
    virtual void vfunc304();
    virtual void vfunc308();
    virtual void vfunc30C();
    virtual void vfunc310();
    virtual void vfunc314();
    virtual void vfunc318();
    virtual void vfunc31C();
    virtual void vfunc320();
    virtual void vfunc324();
    virtual void vfunc328();
    virtual void vfunc32C();
    virtual void vfunc330();
    virtual void vfunc334();
    virtual void vfunc338();
    virtual void vfunc33C();
    virtual void vfunc340();
    virtual void vfunc344();
    virtual void vfunc348();
    virtual void vfunc34C();
    virtual void vfunc350();
    virtual void vfunc354();
    virtual void vfunc358();
    virtual void vfunc35C();
    virtual void vfunc360();
    virtual void vfunc364();
    virtual void vfunc368();
    virtual void vfunc36C();
    virtual void vfunc370();
    virtual void vfunc374();
    virtual void vfunc378();
    virtual void vfunc37C();
    virtual void vfunc380();
    virtual void vfunc384();
    virtual void vfunc388();
    virtual void vfunc38C();
    virtual void vfunc390();
    virtual void vfunc394();
    virtual void vfunc398();
    virtual void vfunc39C();
    virtual void vfunc3A0();
    virtual void vfunc3A4();
    virtual void vfunc3A8();
    virtual void vfunc3AC();
    virtual void vfunc3B0();
    virtual void vfunc3B4();
    virtual void vfunc3B8();
    virtual void vfunc3BC();
    virtual void vfunc3C0();
    virtual void vfunc3C4();
    virtual void vfunc3C8();
    virtual void vfunc3CC();
    virtual void vfunc3D0();
    virtual void vfunc3D4();
    virtual void vfunc3D8();
    virtual void vfunc3DC();
    virtual void vfunc3E0();
    virtual void vfunc3E4();
    virtual void vfunc3E8();
    virtual void vfunc3EC();
    virtual void vfunc3F0();
    virtual void vfunc3F4();
    virtual void vfunc3F8();
    virtual void vfunc3FC();
    virtual void vfunc400();
    virtual void vfunc404();
    virtual void vfunc408();
    virtual void vfunc40C();
    virtual void vfunc410();
    virtual void vfunc414();
    virtual void vfunc418();
    virtual void vfunc41C();
    virtual void vfunc420();
    virtual void vfunc424();
    virtual void vfunc428();
    virtual void vfunc42C();
    virtual void vfunc430();
    virtual void vfunc434();
    virtual void vfunc438();
    virtual void vfunc43C();
    virtual void vfunc440();
    virtual void vfunc444();
    virtual void vfunc448();
    virtual void vfunc44C();
    virtual void vfunc450();
    virtual void vfunc454();
    virtual void vfunc458();
    virtual void vfunc45C();
    virtual void vfunc460();
    virtual void vfunc464();
    virtual void vfunc468();
    virtual void vfunc46C();
    virtual void vfunc470();
    virtual void vfunc474();
    virtual void vfunc478();
    virtual void vfunc47C();
    virtual void vfunc480();
    virtual void vfunc484();
    virtual void vfunc488();
    virtual void vfunc48C();
    virtual void vfunc490();
    virtual void vfunc494();
    virtual void vfunc498();
    virtual void vfunc49C();
    virtual void vfunc4A0();
    virtual void vfunc4A4();
    virtual void vfunc4A8();
    virtual void vfunc4AC();
    virtual void vfunc4B0();
    virtual void vfunc4B4();
    virtual void vfunc4B8();
    virtual void vfunc4BC();
    virtual void vfunc4C0();
    virtual void vfunc4C4();
    virtual void vfunc4C8();
    virtual void vfunc4CC();
    virtual void vfunc4D0();
    virtual void vfunc4D4();
    virtual void vfunc4D8();
    virtual void vfunc4DC();
    virtual void vfunc4E0();
    virtual void vfunc4E4();
    virtual void vfunc4E8();
    virtual void vfunc4EC();
    virtual void vfunc4F0();
    virtual void vfunc4F4();
    virtual void vfunc4F8();
    virtual void vfunc4FC();
    virtual void vfunc500();
    virtual void vfunc504();
    virtual void vfunc508();
    virtual void vfunc50C();
    virtual void vfunc510();
    virtual void vfunc514();
    virtual void vfunc518();
    virtual void vfunc51C();
    virtual void vfunc520();
    virtual void vfunc524();
    virtual void SetCombatTarget(B850Actor* pkTarget);
};

struct B850Actor
{
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual void vfunc08C();
    virtual void vfunc090();
    virtual void vfunc094();
    virtual void vfunc098();
    virtual void vfunc09C();
    virtual void vfunc0A0();
    virtual void vfunc0A4();
    virtual void vfunc0A8();
    virtual void vfunc0AC();
    virtual void vfunc0B0();
    virtual void vfunc0B4();
    virtual void vfunc0B8();
    virtual void vfunc0BC();
    virtual void vfunc0C0();
    virtual void vfunc0C4();
    virtual void vfunc0C8();
    virtual void vfunc0CC();
    virtual void vfunc0D0();
    virtual void vfunc0D4();
    virtual void vfunc0D8();
    virtual void vfunc0DC();
    virtual void vfunc0E0();
    virtual void vfunc0E4();
    virtual void vfunc0E8();
    virtual void vfunc0EC();
    virtual void vfunc0F0();
    virtual void vfunc0F4();
    virtual void vfunc0F8();
    virtual void vfunc0FC();
    virtual void vfunc100();
    virtual void vfunc104();
    virtual void vfunc108();
    virtual void vfunc10C();
    virtual void vfunc110();
    virtual void vfunc114();
    virtual void vfunc118();
    virtual void vfunc11C();
    virtual void vfunc120();
    virtual void vfunc124();
    virtual void vfunc128();
    virtual void vfunc12C();
    virtual void vfunc130();
    virtual void vfunc134();
    virtual void vfunc138();
    virtual void vfunc13C();
    virtual void vfunc140();
    virtual void vfunc144();
    virtual void vfunc148();
    virtual void vfunc14C();
    virtual void vfunc150();
    virtual void vfunc154();
    virtual void vfunc158();
    virtual void vfunc15C();
    virtual void vfunc160();
    virtual void vfunc164();
    virtual void vfunc168();
    virtual void vfunc16C();
    virtual void vfunc170();
    virtual void vfunc174();
    virtual void vfunc178();
    virtual void vfunc17C();
    virtual void vfunc180();
    virtual void vfunc184();
    virtual void vfunc188();
    virtual void vfunc18C();
    virtual void vfunc190();
    virtual void vfunc194();
    virtual void vfunc198();
    virtual void vfunc19C();
    virtual void vfunc1A0();
    virtual void vfunc1A4();
    virtual void vfunc1A8();
    virtual void vfunc1AC();
    virtual void vfunc1B0();
    virtual void vfunc1B4();
    virtual void vfunc1B8();
    virtual void vfunc1BC();
    virtual void vfunc1C0();
    virtual void vfunc1C4();
    virtual void vfunc1C8();
    virtual void vfunc1CC();
    virtual void vfunc1D0();
    virtual void vfunc1D4();
    virtual void vfunc1D8();
    virtual void vfunc1DC();
    virtual void vfunc1E0();
    virtual void vfunc1E4();
    virtual void vfunc1E8();
    virtual void vfunc1EC();
    virtual void vfunc1F0();
    virtual void vfunc1F4();
    virtual void vfunc1F8();
    virtual void vfunc1FC();
    virtual void vfunc200();
    virtual void vfunc204();
    virtual void vfunc208();
    virtual void vfunc20C();
    virtual void vfunc210();
    virtual void vfunc214();
    virtual void vfunc218();
    virtual void vfunc21C();
    virtual void vfunc220();
    virtual void vfunc224();
    virtual void vfunc228();
    virtual void vfunc22C();
    virtual void vfunc230();
    virtual void vfunc234();
    virtual void vfunc238();
    virtual void vfunc23C();
    virtual void vfunc240();
    virtual void vfunc244();
    virtual void vfunc248();
    virtual void vfunc24C();
    virtual void vfunc250();
    virtual void vfunc254();
    virtual void vfunc258();
    virtual void vfunc25C();
    virtual void vfunc260();
    virtual void vfunc264();
    virtual void vfunc268();
    virtual void vfunc26C();
    virtual void vfunc270();
    virtual void vfunc274();
    virtual void vfunc278();
    virtual void vfunc27C();
    virtual void vfunc280();
    virtual void vfunc284();
    virtual void vfunc288();
    virtual void vfunc28C();
    virtual void vfunc290();
    virtual void vfunc294();
    virtual void vfunc298();
    virtual void vfunc29C();
    virtual void vfunc2A0();
    virtual void vfunc2A4();
    virtual void vfunc2A8();
    virtual void vfunc2AC();
    virtual void vfunc2B0();
    virtual void vfunc2B4();
    virtual void vfunc2B8();
    virtual void vfunc2BC();
    virtual void vfunc2C0();
    virtual void vfunc2C4();
    virtual void vfunc2C8();
    virtual void vfunc2CC();
    virtual void vfunc2D0();
    virtual void vfunc2D4();
    virtual void vfunc2D8();
    virtual void vfunc2DC();
    virtual void vfunc2E0();
    virtual void vfunc2E4();
    virtual void vfunc2E8();
    virtual void vfunc2EC();
    virtual void vfunc2F0();
    virtual void vfunc2F4();
    virtual void vfunc2F8();
    virtual void vfunc2FC();
    virtual void vfunc300();
    virtual void vfunc304();
    virtual void vfunc308();
    virtual void vfunc30C();
    virtual void vfunc310();
    virtual void vfunc314();
    virtual void vfunc318();
    virtual void vfunc31C();
    virtual void vfunc320();
    virtual void vfunc324();
    virtual void vfunc328();
    virtual void vfunc32C();
    virtual void vfunc330();
    virtual void vfunc334();
    virtual void vfunc338();
    virtual void vfunc33C();
    virtual void vfunc340();
    virtual void vfunc344();
    virtual void vfunc348();
    virtual void vfunc34C();
    virtual void vfunc350();
    virtual void vfunc354();
    virtual void vfunc358();
    virtual void vfunc35C();
    virtual void vfunc360();
    virtual void vfunc364();
    virtual void vfunc368();
    virtual void vfunc36C();
    virtual void vfunc370();
    virtual void vfunc374();
    virtual void vfunc378();
    virtual void vfunc37C();
    virtual void vfunc380();
    virtual void vfunc384();
    virtual void vfunc388();
    virtual void vfunc38C();
    virtual void vfunc390();
    virtual void vfunc394();
    virtual void vfunc398();
    virtual void vfunc39C();
    virtual void ModifyDisposition(int iA, int iB, int iC);
    virtual void vfunc3A4();
    virtual void vfunc3A8();
    virtual void vfunc3AC();
    virtual void vfunc3B0();
    virtual void vfunc3B4();
    virtual void vfunc3B8();
    virtual void vfunc3BC();
    virtual void vfunc3C0();
    virtual void vfunc3C4();
    virtual void vfunc3C8();
    virtual void vfunc3CC();
    virtual void vfunc3D0();
    virtual void vfunc3D4();
    virtual void vfunc3D8();
    virtual void vfunc3DC();
    virtual void vfunc3E0();
    virtual void vfunc3E4();
    virtual void vfunc3E8();
    virtual void vfunc3EC();
    virtual void vfunc3F0();
    virtual void vfunc3F4();
    virtual void vfunc3F8();
    virtual void vfunc3FC();
    virtual void vfunc400();
    virtual void vfunc404();
    virtual void vfunc408();
    virtual void vfunc40C();
    virtual void vfunc410();
    virtual void vfunc414();
    virtual void vfunc418();
    virtual void vfunc41C();
    virtual void vfunc420();
    virtual void vfunc424();
    virtual void vfunc428();
    virtual void vfunc42C();
    virtual void vfunc430();
    virtual void vfunc434();
    virtual void vfunc438();
    virtual void vfunc43C();
    virtual void vfunc440();
    virtual void vfunc444();
    virtual void vfunc448();
    virtual void vfunc44C();
    virtual void vfunc450();
    virtual void vfunc454();
    virtual void vfunc458();
    virtual void vfunc45C();
    virtual void AddHostility(B850Actor* pkTarget, float fAmount);

    B850Process* GetProcess();
};

extern "C" B850Actor* g_thePlayer;

// Adds 100 hostility toward pkTarget, sets it as combat target, raises disposition, and calls get() on the target's current package if not the player.
// @fnv 0x0080b850
void __cdecl StartHostilityAndCombat(B850Actor* pkActor, B850Actor* pkTarget)
{
    pkActor->AddHostility(pkTarget, 100.0f);
    B850Process* pkProcess = pkActor->GetProcess();
    pkProcess->SetCombatTarget(pkTarget);
    pkActor->ModifyDisposition(1, 100, 0);
    B850Package* pkPackage3 = 0;
    if (pkTarget != g_thePlayer)
        pkPackage3 = pkTarget->GetProcess()->GetCurrentPackage();
    if (pkPackage3)
        pkPackage3->get();
}

struct VirtOwner
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void* v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
    virtual void v4d8();
    virtual void v4dc();
    virtual void v4e0();
    virtual void v4e4();
    virtual void v4e8();
    virtual void v4ec();
    virtual void v4f0();
    virtual void v4f4();
    virtual void v4f8();
    virtual void v4fc();
    virtual void v500();
    virtual void v504();
    virtual void v508();
    virtual void v50c();
    virtual void v510();
    virtual void v514();
    virtual void v518();
    virtual void v51c();
    virtual void v520();
    virtual void v524();
    virtual void v528(void* other);
    virtual void* v52c();
};

struct ActorRef
{
    VirtOwner* FUN_008d8520();
    unsigned char Actor_IsInCombat();
    unsigned char Actor_IsRunningRunOnce();
    void FUN_004534f0(void* other);
};

struct ResultRef
{
    int FUN_0041ca90();
};

extern int DAT_011dea3c;

// @fnv 0x0080b8f0
// src: XBOX_PDB 0x0080b8f0
void CommandEffect_UpdateCommandedActor(void* pActor, void* pOther)
{
    void* w3;
    void* w1;
    VirtOwner* w4;
    VirtOwner* w0;
    VirtOwner* w5;
    VirtOwner* w2;
    if (reinterpret_cast<ActorRef*>(pActor)->FUN_008d8520() == 0)
        return;
    {
        w4 = reinterpret_cast<ActorRef*>(pActor)->FUN_008d8520();
        if (w4->v52c() != pOther)
        {
            w0 = reinterpret_cast<ActorRef*>(pActor)->FUN_008d8520();
            w0->v528(pOther);
        }
    }
    if (reinterpret_cast<ActorRef*>(pActor)->Actor_IsInCombat() == 0)
    {
        w3 = 0;
        if ((int)pOther != DAT_011dea3c)
        {
            w5 = reinterpret_cast<ActorRef*>(pOther)->FUN_008d8520();
            w3 = w5->v27c();
        }
        w2 = reinterpret_cast<ActorRef*>(pActor)->FUN_008d8520();
        w1 = w2->v27c();
        if (w3 == 0 || reinterpret_cast<ResultRef*>(w3)->FUN_0041ca90() == 0x12)
        {
            if (w1 == 0 || reinterpret_cast<ActorRef*>(pActor)->Actor_IsRunningRunOnce() == 0)
                reinterpret_cast<ActorRef*>(pActor)->FUN_004534f0(pOther);
        }
    }
}

struct FUN_008d8520_class
{
    void* FUN_008d8520();
};

typedef void(__thiscall* SlotNoFloat)(void* self, int aArg);
typedef void(__thiscall* SlotWithFloat)(void* self, int aArg, float aValue);
typedef void(__thiscall* SlotThreeInts)(void* self, int aA, int aB, int aC);

extern float DAT_01024100;

// If the owner's FUN_008d8520 result is non-null and abFlag is set, calls slot 330 on it with 0, then calls slots 280 and 232 on apOwner.
// @fnv 0x0080b9e0
// src: XBOX_PDB 0x0080b9e0
void CommandEffect_CleanupCommandedActor(void* apOwner, int aValue, bool abFlag)
{
    if (((FUN_008d8520_class*)apOwner)->FUN_008d8520() != 0 && abFlag)
    {
        void* pTarget = ((FUN_008d8520_class*)apOwner)->FUN_008d8520();
        ((SlotNoFloat)(*(void***)pTarget)[330])(pTarget, 0);
    }
    ((SlotWithFloat)(*(void***)apOwner)[280])(apOwner, aValue, DAT_01024100);
    ((SlotThreeInts)(*(void***)apOwner)[232])(apOwner, 1, -100, 0);
}
