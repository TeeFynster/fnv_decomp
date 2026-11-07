
// src/fallout/magic/sundamageeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/sundamageeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/SunDamageEffect.h"
#include "../../../include/TESSaveLoadGame.h"
extern TESSaveLoadGame* g_TESSaveLoadGame;
// @fnv 0x0082a390
unsigned short SunDamageEffect::GetSaveSize(Actor* apActor)
{
    unsigned short usSize = 0;
    usSize += ActiveEffect::GetSaveSize(apActor);
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x71)
        usSize += 4;
    return usSize;
}

// @fnv 0x0082a420
void SunDamageEffect::LoadGame(Actor* apActor)
{
    ActiveEffect::LoadGame(apActor);
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x71)
        g_TESSaveLoadGame->ReadTypedData(&fValue, 4);
}

struct PC7d
{
    char _pad[148];
};
extern PC7d* g_thePlayer;
// @fnv 0x0082a150
// src: XBOX_PDB 0x0082a150
bool SunDamageEffect::IsCausingDamage()
{
    if ((unsigned int)FUN_0059bb30() ==
        (g_thePlayer ? (unsigned int)(reinterpret_cast<char*>(g_thePlayer) + 0x94) : 0))
    {
        if (this->GetDamageAmount() > (double)0.01f)
            return true;
    }
    return false;
}

// @fnv 0x0082a3e0
void SunDamageEffect::SaveGame(Actor* apActor)
{
    ActiveEffect::SaveGame(apActor);
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x71)
        g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&fValue, 4);
}

// @fnv 0x00829a70
SunDamageEffect::SunDamageEffect(MagicCaster* a, MagicItem* pItem, EffectItem* pEffect) : ActiveEffect(a, pItem, pEffect)
{
    fValue = 0.0f;
    bFlag4D = 0;
    bFlag4C = 0;
}

// @fnv 0x00829ac0
ActiveEffect* SunDamageEffect::Copy()
{
    SunDamageEffect* pkClone = new SunDamageEffect(m_pEffectInstance, pSpell, pEffect);
    CopyData(pkClone);
    pkClone->fValue = fValue;
    pkClone->bFlag4C = bFlag4C;
    pkClone->bFlag4D = bFlag4D;
    return pkClone;
}

struct S_00829bb0_Cell
{
    bool FUN_00454b10();
};

struct S_00829bb0_Val
{
    float TESWeather_GetWeatherData(int a, float b, float c);
};

struct S_00829bb0_Proc
{
    S_00829bb0_Val* TESMain_GetThread();
    S_00829bb0_Val* FUN_00825c00();
    float Sky_GetCurrentWeatherPct();
};

struct S_00829bb0_Actor
{
    virtual ~S_00829bb0_Actor();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual void v1A0();
    virtual void v1A4();
    virtual void v1A8();
    virtual void v1AC();
    virtual void v1B0();
    virtual void v1B4();
    virtual void v1B8();
    virtual void v1BC();
    virtual void v1C0();
    virtual void v1C4();
    virtual void v1C8();
    virtual void v1CC();
    virtual void v1D0();
    virtual void v1D4();
    virtual void v1D8();
    virtual void v1DC();
    virtual void v1E0();
    virtual void v1E4();
    virtual void v1E8();
    virtual void v1EC();
    virtual void v1F0();
    virtual void v1F4();
    virtual void v1F8();
    virtual void v1FC();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20C();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21C();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22C();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23C();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24C();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25C();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26C();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27C();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28C();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29C();
    virtual void v2A0();
    virtual void v2A4();
    virtual void v2A8();
    virtual void v2AC();
    virtual void v2B0();
    virtual void v2B4();
    virtual void v2B8();
    virtual void v2BC();
    virtual void v2C0();
    virtual void v2C4();
    virtual void v2C8();
    virtual void v2CC();
    virtual void v2D0();
    virtual void v2D4();
    virtual void v2D8();
    virtual void v2DC();
    virtual void v2E0();
    virtual void v2E4();
    virtual void v2E8();
    virtual void v2EC();
    virtual void v2F0();
    virtual void v2F4();
    virtual void v2F8();
    virtual void v2FC();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30C();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31C();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32C();
    virtual void v330();
    virtual void v334();
    virtual void v338(float a, float b, int c);
    S_00829bb0_Cell* FUN_008d6f30();
    bool TESObjectREFR_GetInterior();
    S_00829bb0_Proc* FUN_008d8520();
    void Actor_TriggerPain(int a, int b);
};

struct S_00829bb0_Caster
{
    virtual void v00();
    virtual S_00829bb0_Actor* GetActor();
};

struct S_00829bb0_Setting
{
    float* Setting_Float_00403e20();
};

extern S_00829bb0_Actor* DAT_011dea3c;
extern S_00829bb0_Actor* DAT_011dea10;
extern S_00829bb0_Setting DAT_011d1944;
extern S_00829bb0_Setting DAT_011d18d8;
extern float DAT_011a14f8;

// Toggles the effect based on the caster's actor and cell, and when the actor is DAT_011dea3c updates DAT_011a14f8 and blends proc values.
// @fnv 0x00829bb0
void SunDamageEffect::UpdateEffect(float arg)
{
    if (bFlag4D)
    {
        bFlag4D = 0;
    }
    else if (FUN_0059bb30() && reinterpret_cast<S_00829bb0_Caster*>(FUN_0059bb30())->GetActor())
    {
        S_00829bb0_Actor* actor = reinterpret_cast<S_00829bb0_Caster*>(FUN_0059bb30())->GetActor();
        S_00829bb0_Cell* cell = actor->FUN_008d6f30();
        if (actor->TESObjectREFR_GetInterior() && (!cell || !cell->FUN_00454b10()))
        {
            UpdateHitEffect(false);
            if (actor == DAT_011dea3c)
                DAT_011a14f8 = *DAT_011d1944.Setting_Float_00403e20();
        }
        else
        {
            S_00829bb0_Proc* proc;
            float f = GetDamageAmount();
            UpdateHitEffect(f > 0.01f);
            if (actor == DAT_011dea3c)
            {
                if (f > 0.01f)
                {
                    DAT_011dea3c->v338(f * arg, 0.0f, 0);
                    if (DAT_011a14f8 < 0.0)
                    {
                        DAT_011dea3c->Actor_TriggerPain(1, 1);
                        DAT_011a14f8 = *DAT_011d18d8.Setting_Float_00403e20();
                    }
                    else if (DAT_011a14f8 == 3.4028234663852886e+38)
                    {
                        DAT_011a14f8 = *DAT_011d1944.Setting_Float_00403e20();
                    }
                    DAT_011a14f8 = DAT_011a14f8 - arg;
                }
                proc = DAT_011dea10->FUN_008d8520();
                float fValue = proc->TESMain_GetThread() ? proc->TESMain_GetThread()->TESWeather_GetWeatherData(5, 1.0f, 0.0f) : 0.0f;
                if (proc->FUN_00825c00())
                {
                    float w = proc->Sky_GetCurrentWeatherPct();
                    fValue = fValue * w;
                    fValue += (1.0 - w) * proc->FUN_00825c00()->TESWeather_GetWeatherData(5, 1.0f, 0.0f);
                }
            }
        }
    }
}

struct S_00829e00_Target;

struct S_00829e00_Caster
{
    virtual void v00();
    virtual S_00829e00_Target* GetTarget();
};

struct S_00829e00_Setting
{
    void* GetEffectShader_00407820();
};

// Hit effect applied to the target (0x6c bytes).
struct S_00829e00_HitEffect
{
    virtual ~S_00829e00_HitEffect();
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
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual bool vC4();
    int unk04;
    int unk08;
    int unk0C;
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
    int unk68;
    void SetByteAt24(int a);
    void FUN_00984f60(void* owner);
};

struct S_00829e00_Effect : S_00829e00_HitEffect
{
    static void* operator new(unsigned int size);
    S_00829e00_Effect(S_00829e00_Target* target, void* form, float duration);
};

struct S_00829e00_List
{
    S_00829e00_HitEffect* m_item;
    S_00829e00_List* m_next;
    S_00829e00_List(S_00829e00_HitEffect* const& item);
    ~S_00829e00_List();
    bool FUN_008256d0();
    void FUN_00470470();
    S_00829e00_HitEffect** FUN_006815c0();
    S_00829e00_List* FUN_00726070();
};

struct S_00829e00_Manager
{
    void ProcessLists_AddTempEffect(S_00829e00_HitEffect* effect);
    void ProcessLists_FinishMagicShaderHitEffect(S_00829e00_Target* target, void* form);
};
extern S_00829e00_Manager DAT_011e0e80;

// @fnv 0x00829e00
// src: XBOX_PDB 0x00829e00
void SunDamageEffect::UpdateHitEffect(bool abApply)
{
    void* form = reinterpret_cast<S_00829e00_Setting*>(FUN_007df1d0())->GetEffectShader_00407820();
    if (!form || !FUN_0059bb30() || FUN_0055b980() != 4)
        return;
    if (abApply)
    {
        if (!reinterpret_cast<S_00829e00_List*&>(pHitEffectList) || reinterpret_cast<S_00829e00_List*&>(pHitEffectList)->FUN_008256d0())
        {
            if (reinterpret_cast<S_00829e00_List*&>(pHitEffectList))
            {
                reinterpret_cast<S_00829e00_List*&>(pHitEffectList)->FUN_00470470();
                delete reinterpret_cast<S_00829e00_List*&>(pHitEffectList);
                reinterpret_cast<S_00829e00_List*&>(pHitEffectList) = 0;
            }
            S_00829e00_Effect* effect = new S_00829e00_Effect(reinterpret_cast<S_00829e00_Caster*>(FUN_0059bb30())->GetTarget(), form, -1.0f);
            if (effect->vC4())
            {
                DAT_011e0e80.ProcessLists_AddTempEffect(effect);
                reinterpret_cast<S_00829e00_List*&>(pHitEffectList) = new S_00829e00_List(effect);
                effect->FUN_00984f60(this);
            }
            else
            {
                delete effect;
                effect = 0;
            }
        }
    }
    else if (reinterpret_cast<S_00829e00_List*&>(pHitEffectList))
    {
        S_00829e00_List* node = reinterpret_cast<S_00829e00_List*&>(pHitEffectList);
        while (node && !node->FUN_008256d0())
        {
            S_00829e00_HitEffect* item = *node->FUN_006815c0();
            item->SetByteAt24(1);
            item->FUN_00984f60(0);
            node = node->FUN_00726070();
        }
        reinterpret_cast<S_00829e00_List*&>(pHitEffectList)->FUN_00470470();
        delete reinterpret_cast<S_00829e00_List*&>(pHitEffectList);
        reinterpret_cast<S_00829e00_List*&>(pHitEffectList) = 0;
        DAT_011e0e80.ProcessLists_FinishMagicShaderHitEffect(reinterpret_cast<S_00829e00_Caster*>(FUN_0059bb30())->GetTarget(), form);
    }
}

// Allocates and constructs a SunDamageEffect from the given caster, item and effect item.
// @fnv 0x0082a0d0
// src: COMMUNITY 0x0082a0d0
SunDamageEffect* SunDamageEffect_Create(MagicCaster* apCaster, MagicItem* apItem, EffectItem* apEffect)
{
    return new SunDamageEffect(apCaster, apItem, apEffect);
}

struct H_Fld
{
    char _pad0[8];
    float f8;
};
struct H_Calls;
struct H_Calls
{
    virtual H_Calls* v0() = 0;
    virtual H_Calls* v1() = 0;
    virtual H_Calls* v2() = 0;
    virtual H_Calls* v3() = 0;
    virtual H_Calls* v4() = 0;
    virtual H_Calls* v5() = 0;
    virtual H_Calls* v6() = 0;
    virtual H_Calls* v7() = 0;
    virtual H_Calls* v8() = 0;
    virtual H_Calls* v9() = 0;
    virtual H_Calls* v10() = 0;
    virtual H_Calls* v11() = 0;
    virtual H_Calls* v12() = 0;
    virtual H_Calls* v13() = 0;
    virtual H_Calls* v14() = 0;
    virtual H_Calls* v15() = 0;
    virtual H_Calls* v16() = 0;
    virtual H_Calls* v17() = 0;
    virtual H_Calls* v18() = 0;
    virtual H_Calls* v19() = 0;
    virtual H_Calls* v20() = 0;
    virtual H_Calls* v21() = 0;
    virtual H_Calls* v22() = 0;
    virtual H_Calls* v23() = 0;
    virtual H_Calls* v24() = 0;
    virtual H_Calls* v25() = 0;
    virtual H_Calls* v26() = 0;
    virtual H_Calls* v27() = 0;
    virtual H_Calls* v28() = 0;
    virtual H_Calls* v29() = 0;
    virtual H_Calls* v30() = 0;
    virtual H_Calls* v31() = 0;
    virtual H_Calls* v32() = 0;
    virtual H_Calls* v33() = 0;
    virtual H_Calls* v34() = 0;
    virtual H_Calls* v35() = 0;
    virtual H_Calls* v36() = 0;
    virtual H_Calls* v37() = 0;
    virtual H_Calls* v38() = 0;
    virtual H_Calls* v39() = 0;
    virtual H_Calls* v40() = 0;
    virtual H_Calls* v41() = 0;
    virtual H_Calls* v42() = 0;
    virtual H_Calls* v43() = 0;
    virtual H_Calls* v44() = 0;
    virtual H_Calls* v45() = 0;
    virtual H_Calls* v46() = 0;
    virtual H_Calls* v47() = 0;
    virtual H_Calls* v48() = 0;
    virtual H_Calls* v49() = 0;
    virtual H_Calls* v50() = 0;
    virtual H_Calls* v51() = 0;
    virtual H_Calls* v52() = 0;
    virtual H_Calls* v53() = 0;
    virtual H_Calls* v54() = 0;
    virtual H_Calls* v55() = 0;
    virtual H_Calls* v56() = 0;
    virtual H_Calls* v57() = 0;
    virtual H_Calls* v58() = 0;
    virtual H_Calls* v59() = 0;
    virtual H_Calls* v60() = 0;
    virtual H_Calls* v61() = 0;
    virtual H_Calls* v62() = 0;
    virtual H_Calls* v63() = 0;
    virtual H_Calls* v64() = 0;
    virtual H_Calls* v65() = 0;
    virtual H_Calls* v66() = 0;
    virtual H_Calls* v67() = 0;
    virtual H_Calls* v68() = 0;
    virtual H_Calls* v69() = 0;
    virtual H_Calls* v70() = 0;
    virtual H_Calls* v71() = 0;
    virtual H_Calls* v72() = 0;
    virtual H_Calls* v73() = 0;
    virtual H_Calls* v74() = 0;
    virtual H_Calls* v75() = 0;
    virtual H_Calls* v76() = 0;
    virtual H_Calls* v77() = 0;
    virtual H_Calls* v78() = 0;
    virtual H_Calls* v79() = 0;
    virtual H_Calls* v80() = 0;
    virtual H_Calls* v81() = 0;
    virtual H_Calls* v82() = 0;
    virtual H_Calls* v83() = 0;
    virtual H_Calls* v84() = 0;
    virtual H_Calls* v85() = 0;
    virtual H_Calls* v86() = 0;
    virtual H_Calls* v87() = 0;
    virtual H_Calls* v88() = 0;
    virtual H_Calls* v89() = 0;
    virtual H_Calls* v90() = 0;
    virtual H_Calls* v91() = 0;
    virtual H_Calls* v92() = 0;
    virtual H_Calls* v93() = 0;
    virtual H_Calls* v94() = 0;
    virtual H_Calls* v95() = 0;
    virtual H_Calls* v96() = 0;
    virtual H_Calls* v97() = 0;
    virtual H_Calls* v98() = 0;
    virtual H_Calls* v99() = 0;
    virtual H_Calls* v100() = 0;
    virtual H_Calls* v101() = 0;
    virtual H_Calls* v102() = 0;
    virtual H_Calls* v103() = 0;
    virtual H_Calls* v104() = 0;
    virtual H_Calls* v105() = 0;
    virtual H_Calls* v106() = 0;
    virtual H_Calls* v107() = 0;
    virtual H_Calls* v108() = 0;
    virtual H_Calls* v109() = 0;
    virtual H_Calls* v110() = 0;
    virtual H_Calls* v111() = 0;
    virtual H_Calls* v112() = 0;
    virtual H_Calls* v113() = 0;
    virtual H_Calls* v114() = 0;
    virtual H_Calls* v115() = 0;
    virtual H_Calls* v116() = 0;
    virtual H_Calls* v117() = 0;
    virtual H_Calls* v118() = 0;
    virtual H_Calls* v119() = 0;
    virtual H_Calls* v120() = 0;
    virtual H_Calls* v121() = 0;
    virtual H_Calls* v122() = 0;
    virtual H_Calls* v123() = 0;
    virtual H_Calls* v124() = 0;
    virtual H_Fld* v125() = 0;
    H_Calls* FUN_0059bb30();
    H_Calls* FUN_008d6f30();
    bool TESObjectREFR_GetInterior();
    bool FUN_00454b10();
    H_Calls* FUN_008d8520();
    float GetFieldEC();
    float Sky_GetSunriseBegin();
    float Sky_GetSunsetEnd();
    H_Calls* TESMain_GetThread();
    float TESWeather_GetWeatherData(int, float, float);
    H_Calls* FUN_00825c00();
    float Sky_GetCurrentWeatherPct();
    bool FUN_004518e0();
    double TESObjectREFR_GetRelevantWaterHeight();
    float GetFloatAtOffset1C();
};
float MagicFormulas_CalcSunDamage(float, float, float, float, bool, float, bool);

// Calls FUN_00649390 with values read from this, DAT_011dea10, and p; returns 0.0 when the guard fails.
// @fnv 0x0082a1b0
// src: XBOX_PDB 0x0082a1b0
double SunDamageEffect::GetDamageAmount()
{
    H_Calls* p;
    H_Calls* aQ;
    p = ((H_Calls*)FUN_0059bb30()) ? ((H_Calls*)FUN_0059bb30())->v1() : 0;
    aQ = p ? p->FUN_008d6f30() : 0;
    if (p && (!p->TESObjectREFR_GetInterior() || (aQ && aQ->FUN_00454b10())))
    {
        bool b9;
        float f4;
        bool b11;
        float f18;
        float aF1c;
        H_Calls* obj;
        float vTmp;
        float v_;
        obj = ((H_Calls*)DAT_011dea10)->FUN_008d8520();
        aF1c = obj->GetFieldEC();
        f4 = obj->Sky_GetSunriseBegin();
        f18 = obj->Sky_GetSunsetEnd();
        b9 = true;
        vTmp = obj->TESMain_GetThread() ? obj->TESMain_GetThread()->TESWeather_GetWeatherData(5, 1.0f, 0.0f) : 0.0f;
        if (obj->FUN_00825c00())
        {
            v_ = obj->Sky_GetCurrentWeatherPct();
            vTmp = vTmp * v_;
            vTmp = (1.0 - v_) * obj->FUN_00825c00()->TESWeather_GetWeatherData(5, 1.0f, 0.0f) + vTmp;
        }
        b11 = false;
        if (p->FUN_008d6f30()->FUN_004518e0())
        {
            if (p->TESObjectREFR_GetRelevantWaterHeight() >= p->v125()->f8)
                b11 = true;
        }
        return MagicFormulas_CalcSunDamage(GetFloatAtOffset1C(), aF1c, f4, f18, b9, vTmp, b11);
    }
    return 0.0;
}
