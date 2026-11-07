
// src/fallout_shared/tesscriptfunctions_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (-). The skeleton of src/fallout_shared/tesscriptfunctions.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "../../include/BGSListForm.h"
#include "../../include/Script.h"
#include "../../include/TESActorBase.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESFaction.h"
#include "../../include/TESForm.h"
#include "../../include/TESNPC.h"
#include "../../include/TESQuest.h"
#include "../../include/TESObjectREFR.h"
class ScriptParameter;
#include "../../include/OBJECT_ACTION.h"
class BGSMusicType;
class FalloutAudioMedia
{
  public:
    static void PlayMedia(BGSMusicType*);
    static void EndMediaUpdate();
    static void Update();
};
class ScriptLocals;
extern bool ExtractArgs(const ScriptParameter*, const char*, unsigned int*, TESObjectREFR*, TESObjectREFR*, Script*,
                        ScriptLocals*, ...);

// @fnv 0x005c6c80
// src: EXE 0x005c6c80
bool __cdecl Cmd_DuplicateNPCStats_Execute(const ScriptParameter* paramInfo, const char* scriptData, TESObjectREFR* thisObj,
                          TESObjectREFR* containingObj, Script* scriptObj, ScriptLocals* locals, double& result,
                          unsigned int& opcodeOffsetPtr)
{
    TESObjectREFR* targetRef7 = 0;
    if (!ExtractArgs(paramInfo, scriptData, &opcodeOffsetPtr, thisObj, containingObj, scriptObj, locals, &targetRef7))
        return false;

    if (thisObj != 0 && thisObj->IsActor() && targetRef7 != 0)
    {
        TESObjectREFR* actor = thisObj;
        TESNPC* npc1 = dynamic_cast<TESNPC*>(actor->GetObjectReference());
        TESNPC* npc4 = dynamic_cast<TESNPC*>(targetRef7->GetObjectReference());

        if (npc1 != 0 && npc4 != 0)
        {
            npc1->SetClass(npc4->TESActorBase::GetClass());
            npc1->SetLevel(npc4->TESActorBaseData_GetLevel());
            npc1->AutoCalcStats(false);
        }
    }

    return true;
}

class FNVActorContext
{
  public:
    void ExtraDataList_SetHeadTrackTargetExtra(TESObjectREFR*);
};
struct FNVWipController_SV
{
    virtual void vf_000();
    virtual void vf_004();
    virtual void vf_008();
    virtual void vf_00c();
    virtual void vf_010();
    virtual void vf_014();
    virtual void vf_018();
    virtual void vf_01c();
    virtual void vf_020();
    virtual void vf_024();
    virtual void vf_028();
    virtual void vf_02c();
    virtual void vf_030();
    virtual void vf_034();
    virtual void vf_038();
    virtual void vf_03c();
    virtual void vf_040();
    virtual void vf_044();
    virtual void vf_048();
    virtual void vf_04c();
    virtual void vf_050();
    virtual void vf_054();
    virtual void vf_058();
    virtual void vf_05c();
    virtual void vf_060();
    virtual void vf_064();
    virtual void vf_068();
    virtual void vf_06c();
    virtual void vf_070();
    virtual void vf_074();
    virtual void vf_078();
    virtual void vf_07c();
    virtual void vf_080();
    virtual void vf_084();
    virtual void vf_088();
    virtual void vf_08c();
    virtual void vf_090();
    virtual void vf_094();
    virtual void vf_098();
    virtual void vf_09c();
    virtual void vf_0a0();
    virtual void vf_0a4();
    virtual void vf_0a8();
    virtual void vf_0ac();
    virtual void vf_0b0();
    virtual void vf_0b4();
    virtual void vf_0b8();
    virtual void vf_0bc();
    virtual void vf_0c0();
    virtual void vf_0c4();
    virtual void vf_0c8();
    virtual void vf_0cc();
    virtual void vf_0d0();
    virtual void vf_0d4();
    virtual void vf_0d8();
    virtual void vf_0dc();
    virtual void vf_0e0();
    virtual void vf_0e4();
    virtual void vf_0e8();
    virtual void vf_0ec();
    virtual void vf_0f0();
    virtual void vf_0f4();
    virtual void vf_0f8();
    virtual void vf_0fc();
    virtual void vf_100();
    virtual void vf_104();
    virtual void vf_108();
    virtual void vf_10c();
    virtual void vf_110();
    virtual void vf_114();
    virtual void vf_118();
    virtual void vf_11c();
    virtual void vf_120();
    virtual void vf_124();
    virtual void vf_128();
    virtual void vf_12c();
    virtual void vf_130();
    virtual void vf_134();
    virtual void vf_138();
    virtual void vf_13c();
    virtual void vf_140();
    virtual void vf_144();
    virtual void vf_148();
    virtual void vf_14c();
    virtual void vf_150();
    virtual void vf_154();
    virtual void vf_158();
    virtual void vf_15c();
    virtual void vf_160();
    virtual void vf_164();
    virtual void vf_168();
    virtual void vf_16c();
    virtual void vf_170();
    virtual void vf_174();
    virtual void vf_178();
    virtual void vf_17c();
    virtual void vf_180();
    virtual void vf_184();
    virtual void vf_188();
    virtual void vf_18c();
    virtual void vf_190();
    virtual void vf_194();
    virtual void vf_198();
    virtual void vf_19c();
    virtual void vf_1a0();
    virtual void vf_1a4();
    virtual void vf_1a8();
    virtual void vf_1ac();
    virtual void vf_1b0();
    virtual void vf_1b4();
    virtual void vf_1b8();
    virtual void vf_1bc();
    virtual void vf_1c0();
    virtual void vf_1c4();
    virtual void vf_1c8();
    virtual void vf_1cc();
    virtual void vf_1d0();
    virtual void vf_1d4();
    virtual void vf_1d8();
    virtual void vf_1dc();
    virtual void vf_1e0();
    virtual void vf_1e4();
    virtual void vf_1e8();
    virtual void vf_1ec();
    virtual void vf_1f0();
    virtual void vf_1f4();
    virtual void vf_1f8();
    virtual void vf_1fc();
    virtual void vf_200();
    virtual void vf_204();
    virtual void vf_208();
    virtual void vf_20c();
    virtual void vf_210();
    virtual void vf_214();
    virtual void vf_218();
    virtual void vf_21c();
    virtual void vf_220();
    virtual void vf_224();
    virtual void vf_228();
    virtual void vf_22c();
    virtual void vf_230();
    virtual void vf_234();
    virtual void vf_238();
    virtual void vf_23c();
    virtual void vf_240();
    virtual void vf_244();
    virtual void vf_248();
    virtual void vf_24c();
    virtual void vf_250();
    virtual void vf_254();
    virtual void vf_258();
    virtual void vf_25c();
    virtual void vf_260();
    virtual void vf_264();
    virtual void vf_268();
    virtual void vf_26c();
    virtual void vf_270();
    virtual void vf_274();
    virtual void vf_278();
    virtual void vf_27c();
    virtual void vf_280();
    virtual void vf_284();
    virtual void vf_288();
    virtual void vf_28c();
    virtual void vf_290();
    virtual void vf_294();
    virtual void vf_298();
    virtual void vf_29c();
    virtual void vf_2a0();
    virtual void vf_2a4();
    virtual void vf_2a8();
    virtual void vf_2ac();
    virtual void vf_2b0();
    virtual void vf_2b4();
    virtual void vf_2b8();
    virtual void vf_2bc();
    virtual void vf_2c0();
    virtual void vf_2c4();
    virtual void vf_2c8();
    virtual void vf_2cc();
    virtual void vf_2d0();
    virtual void vf_2d4();
    virtual void vf_2d8();
    virtual void vf_2dc();
    virtual void vf_2e0();
    virtual void vf_2e4();
    virtual void vf_2e8();
    virtual void vf_2ec();
    virtual void vf_2f0();
    virtual void vf_2f4();
    virtual void vf_2f8();
    virtual void vf_2fc();
    virtual void vf_300();
    virtual void vf_304();
    virtual void vf_308();
    virtual void vf_30c();
    virtual void vf_310();
    virtual void vf_314();
    virtual void vf_318();
    virtual void vf_31c();
    virtual void vf_320();
    virtual void vf_324();
    virtual void vf_328();
    virtual void vf_32c();
    virtual void vf_330();
    virtual void vf_334();
    virtual void vf_338();
    virtual void vf_33c();
    virtual void vf_340();
    virtual void vf_344();
    virtual void vf_348();
    virtual void vf_34c();
    virtual void vf_350();
    virtual void vf_354();
    virtual void vf_358();
    virtual void vf_35c();
    virtual void vf_360();
    virtual void vf_364();
    virtual void vf_368();
    virtual void vf_36c();
    virtual void vf_370();
    virtual void vf_374();
    virtual void vf_378();
    virtual void vf_37c();
    virtual void vf_380();
    virtual void vf_384();
    virtual void vf_388();
    virtual void vf_38c();
    virtual void vf_390();
    virtual void vf_394();
    virtual void vf_398();
    virtual void vf_39c();
    virtual void vf_3a0();
    virtual void vf_3a4();
    virtual void vf_3a8();
    virtual void vf_3ac();
    virtual void vf_3b0();
    virtual void vf_3b4();
    virtual void vf_3b8();
    virtual void vf_3bc();
    virtual void vf_3c0();
    virtual void vf_3c4();
    virtual void vf_3c8();
    virtual void vf_3cc();
    virtual void vf_3d0();
    virtual void vf_3d4();
    virtual void vf_3d8();
    virtual void vf_3dc();
    virtual void vf_3e0();
    virtual void vf_3e4();
    virtual void vf_3e8();
    virtual void vf_3ec();
    virtual void vf_3f0();
    virtual void vf_3f4();
    virtual void vf_3f8();
    virtual void vf_3fc();
    virtual void vf_400();
    virtual void vf_404();
    virtual void vf_408();
    virtual void vf_40c();
    virtual void vf_410();
    virtual void vf_414();
    virtual void vf_418();
    virtual void vf_41c();
    virtual void vf_420();
    virtual void vf_424();
    virtual void vf_428();
    virtual void vf_42c();
    virtual void vf_430();
    virtual void vf_434();
    virtual void vf_438();
    virtual void vf_43c();
    virtual void vf_440();
    virtual void vf_444();
    virtual void vf_448();
    virtual void vf_44c();
    virtual void vf_450();
    virtual void vf_454();
    virtual void vf_458();
    virtual void vf_45c();
    virtual void vf_460();
    virtual void vf_464();
    virtual void vf_468();
    virtual void vf_46c();
    virtual void vf_470();
    virtual void vf_474();
    virtual void vf_478();
    virtual void vf_47c();
    virtual void vf_480();
    virtual void vf_484();
    virtual void vf_488();
    virtual void vf_48c();
    virtual void vf_490();
    virtual void vf_494();
    virtual void vf_498();
    virtual void vf_49c();
    virtual void vf_4a0();
    virtual void vf_4a4();
    virtual void vf_4a8();
    virtual void vf_4ac();
    virtual void vf_4b0();
    virtual void vf_4b4();
    virtual void vf_4b8();
    virtual void vf_4bc();
    virtual void vf_4c0();
    virtual void vf_4c4();
    virtual void vf_4c8();
    virtual void vf_4cc();
    virtual void vf_4d0();
    virtual void vf_4d4();
    virtual void vf_4d8();
    virtual void vf_4dc();
    virtual void vf_4e0();
    virtual void vf_4e4();
    virtual void vf_4e8();
    virtual void vf_4ec();
    virtual void vf_4f0();
    virtual void vf_4f4();
    virtual void vf_4f8();
    virtual void vf_4fc();
    virtual void vf_500();
    virtual void vf_504();
    virtual void vf_508();
    virtual void vf_50c();
    virtual void vf_510();
    virtual void vf_514();
    virtual void vf_518();
    virtual void vf_51c();
    virtual void vf_520();
    virtual void vf_524();
    virtual void vf_528();
    virtual void vf_52c();
    virtual void vf_530();
    virtual void vf_534();
    virtual void vf_538();
    virtual void vf_53c();
    virtual void vf_540();
    virtual void vf_544();
    virtual void vf_548();
    virtual void vf_54c();
    virtual void vf_550();
    virtual void vf_554();
    virtual void vf_558();
    virtual void vf_55c();
    virtual void vf_560();
    virtual void vf_564();
    virtual void vf_568();
    virtual void vf_56c();
    virtual void vf_570();
    virtual void vf_574();
    virtual void vf_578();
    virtual void vf_57c();
    virtual void vf_580();
    virtual void vf_584();
    virtual void vf_588();
    virtual void vf_58c();
    virtual void vf_590();
    virtual void vf_594();
    virtual void vf_598();
    virtual void vf_59c();
    virtual void vf_5a0();
    virtual void vf_5a4();
    virtual void vf_5a8();
    virtual void vf_5ac();
    virtual void vf_5b0();
    virtual void vf_5b4();
    virtual void vf_5b8();
    virtual void vf_5bc();
    virtual void vf_5c0();
    virtual void vf_5c4();
    virtual void vf_5c8();
    virtual void vf_5cc();
    virtual void vf_5d0();
    virtual void vf_5d4();
    virtual void vf_5d8();
    virtual void vf_5dc();
    virtual void vf_5e0();
    virtual void vf_5e4();
    virtual void vf_5e8();
    virtual void vf_5ec();
    virtual void vf_5f0();
    virtual void vf_5f4();
    virtual void vf_5f8();
    virtual void vf_5fc();
    virtual void vf_600();
    virtual void vf_604();
    virtual void vf_608();
    virtual void vf_60c();
    virtual void vf_610();
    virtual void vf_614();
    virtual void vf_618();
    virtual void vf_61c();
    virtual void vf_620();
    virtual void vf_624();
    virtual void vf_628();
    virtual void vf_62c();
    virtual void vf_630();
    virtual void vf_634();
    virtual void vf_638();
    virtual void vf_63c();
    virtual void vf_640();
    virtual void vf_644();
    virtual void v648(int);
    virtual void vf_64c();
    virtual void vf_650();
    virtual void vf_654();
    virtual void vf_658();
    virtual void vf_65c();
    virtual void vf_660();
    virtual void vf_664();
    virtual void vf_668();
    virtual void vf_66c();
    virtual void vf_670();
    virtual void vf_674();
    virtual void vf_678();
    virtual void vf_67c();
    virtual void vf_680();
    virtual void vf_684();
    virtual void vf_688();
    virtual void vf_68c();
    virtual void vf_690();
    virtual void vf_694();
    virtual void vf_698();
    virtual void vf_69c();
    virtual void vf_6a0();
    virtual void vf_6a4();
    virtual void vf_6a8();
    virtual void vf_6ac();
    virtual void vf_6b0();
    virtual void vf_6b4();
    virtual void vf_6b8();
    virtual void vf_6bc();
    virtual void vf_6c0();
    virtual void vf_6c4();
    virtual void vf_6c8();
    virtual void vf_6cc();
    virtual void vf_6d0();
    virtual void vf_6d4();
    virtual void vf_6d8();
    virtual void vf_6dc();
    virtual void vf_6e0();
    virtual void vf_6e4();
    virtual void vf_6e8();
    virtual void vf_6ec();
    virtual void vf_6f0();
    virtual void vf_6f4();
    virtual void vf_6f8();
    virtual void vf_6fc();
    virtual void vf_700();
    virtual void vf_704();
    virtual void vf_708();
    virtual void vf_70c();
    virtual void vf_710();
    virtual void vf_714();
    virtual void vf_718();
    virtual void vf_71c();
    virtual void vf_720();
    virtual void vf_724();
    virtual void vf_728();
    virtual void vf_72c();
    virtual void vf_730();
    virtual void vf_734();
    virtual void vf_738();
    virtual void vf_73c();
    virtual void vf_740();
    virtual void vf_744();
    virtual void vf_748();
    virtual void vf_74c();
    virtual void vf_750();
    virtual void vf_754();
    virtual void vf_758();
    virtual void vf_75c();
    virtual void vf_760();
    virtual void vf_764();
    virtual void vf_768();
    virtual void vf_76c();
    virtual void vf_770();
    virtual void vf_774();
    virtual void vf_778();
    virtual void vf_77c();
    virtual void vf_780();
    virtual void vf_784();
    virtual void vf_788();
    virtual void vf_78c();
    virtual void vf_790();
    virtual void vf_794();
    virtual void vf_798();
    virtual void vf_79c();
    virtual void vf_7a0();
    virtual void vf_7a4();
    virtual void vf_7a8();
    virtual void v7ac(int);
};
struct Actor_5c98e0_Shell
{
    FNVActorContext* BSFile_GetDevice();
    FNVWipController_SV* FUN_008d8520();
    void ClearLookAtTarget();
};

extern "C" void* __cdecl FNV_DynamicCast(void*, long, const void*, const void*, int);
extern char DAT_011841cc;
extern char DAT_011846d4;

// @fnv 0x005c98e0
// src: EXE 0x005c98e0
bool __cdecl Cmd_StopLook_Execute(const ScriptParameter* apParameters, const char* apCompiledParams,
                          TESObjectREFR* apRefObject, TESObjectREFR* apContainer, Script* apScript,
                          ScriptLocals* apScriptLocals, double& afReturnValue, unsigned int& auiOffset)
{
    if (apRefObject)
    {
        Actor_5c98e0_Shell* actor =
            static_cast<Actor_5c98e0_Shell*>(FNV_DynamicCast(apRefObject, 0, &DAT_011841cc, &DAT_011846d4, 0));
        if (actor)
        {
            actor->BSFile_GetDevice()->ExtraDataList_SetHeadTrackTargetExtra(0);
            if (actor->FUN_008d8520())
            {
                actor->FUN_008d8520()->v648(1);
                actor->ClearLookAtTarget();
                actor->FUN_008d8520()->v7ac(0);
            }
        }
    }
    return true;
}
