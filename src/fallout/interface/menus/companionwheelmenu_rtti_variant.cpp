
// src/fallout/interface/menus/companionwheelmenu_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (Tile). The skeleton of src/fallout/interface/menus/companionwheelmenu.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "companionwheelmenu_decls.h"
#include "../../../../include/Menu.h"
#include "../../../../include/CompanionWheelMenu.h"
#include "../../../../include/Actor.h"
#include "../../../../include/AlchemyItem.h"
#include "../../../../include/DialoguePackage.h"
#include "../../../../include/RadialTile.h"
#include "../../../../include/TESForm.h"
#include "../../../../include/TESPackage.h"
#include "../../../../include/TESTopic.h"
#include "../../../../include/Tile.h"
#include "../../../../include/DialogueItem.h"
#include "../../../../include/MagicCaster.h"
#include "../../../../include/Setting.h"
#include "../../../../include/BSSoundHandle.h"
extern Actor* g_thePlayer;
bool CompanionWheelMenu_GetShouldCompanionWheelOpen(Actor* a);
int __cdecl return_1075();
extern "C" float __cdecl LogFloat(float);
float NiATan(float value);
extern "C" void __cdecl CloseMenuAndRefresh(int);
void __fastcall CompanionWheelMenu_Do_Talk(int thisPtr);
extern bool __cdecl _FUN_004b71d0();
struct FUN_00755680_shell
{
    bool __thiscall InterfaceManager_GetMouseVisible();
};
void __cdecl _Deallocate(void*);
struct FUN_008a7760_holder
{
    void __thiscall OpenDialogMenu();
};
MagicCaster* __cdecl _FUN_004b7210();
extern int DAT_011d92b8;
void __cdecl InterfaceManager_PlayMenuSound(int);
unsigned int __cdecl gm_GetTickCount(void);
float __cdecl NiATan(float value);
int __cdecl _FUN_00ec7d40(int value);
extern char $SG3295[];
extern double _DAT_01012060;
extern double DAT_01071e20;
extern float DAT_01071e28;
extern float DAT_01071e2c;
extern double _DAT_0104eea0;
extern short DAT_011d8a5c;
extern short DAT_011d8a5e;
extern short DAT_011d8a74;
struct MenuFactory
{
    Menu* Tile_GetMenu();
};
MenuFactory* __cdecl Tile_GetMenuByClass(int id);
int __cdecl OpenCompanionMenu(int value);
bool __cdecl DestroyCompanionWheelMenu(int value);
extern "C" bool __cdecl Interface_IsTopMenuID(int);
bool __cdecl Interface_IsTopMenuID(int);
struct PackageNode
{
    PackageNode* FUN_00726070();
};
struct ActorLevelInfo
{
    unsigned int unk00, unk04, unk08;
    unsigned short unk0c;
    unsigned char level;
};
struct DialoguePolicy
{
    bool TESTopic_IsRemappedRumors();
};
struct DialogueManager
{
    DialogueItem* TESTopic_CreateDialogueItem(Actor*, Actor*, int, int, int);
};
DialogueManager* GetTopicSubTypeName(int, int);
struct ActorPosition
{
    float x, y, z;
};
struct ActorExtraData
{
    void FUN_00815b00();
};
struct ActorLock
{
    bool FUN_0047c850();
};
extern Actor* interactionPlayer;
struct DialogueDisplay
{
    void QuitVATSPlayback(int, int);
};
extern DialogueDisplay dialogueDisplay;
void Interface_QueueMenuCreate(int, Actor*, unsigned int, int, int, int);
struct InputState
{
    void FUN_00ad8780();
};
InputState* __stdcall BSAudio_QInstance(int);
int Interface_GetMenuModeType();
struct MessageSetting
{
    const char* FUN_00403df0();
};
extern MessageSetting lockedMessage;
int sprintf(char*, const char*, ...);
extern float messageDuration;
void DispatchMessageToSink(const char*, int, int, int, float, int);
struct SoundFile
{
    unsigned int GetSoundID();
};
struct SoundPath
{
    const char* CStr();
};
struct DialogueResponse
{
    SoundFile* GetSoundByEditorID();
    unsigned int GetSoundID();
    BSStringT<char>& GetText();
    int GetEmotionValue();
    int GetEmotionType();
    unsigned int GetFlags();
    SoundPath* GetVoicePath(BSSoundHandle* snd);
};
struct TopicInfoStandin
{
    TESTopicInfo* GetTopicInfo(Actor* speaker, Actor* target);
};
struct TopicInfoQ
{
    TESQuest* GetQuest();
};
struct CStringArg_757690
{
    unsigned data;
    unsigned length;
    ~CStringArg_757690();
    unsigned __thiscall BSStringT_char_Length();
    int __thiscall Modelloader_GetReferencedThis();
    int __thiscall Modelloader_GetReferencedThis(int);
};
struct CValueArg_757690
{
    unsigned value;
    unsigned kind;
    unsigned other;
    ~CValueArg_757690();
    int __thiscall FUN_00ad8b30();
};
struct CInterface_757690
{
    unsigned char* __thiscall FUN_00408d60();
};
struct CRandom_757690
{
    float* __thiscall Setting_Float_00403e20();
};
extern CInterface_757690 DAT_011d8928;
extern CRandom_757690 DAT_011d2178;
extern double DAT_01012060;
extern double DAT_01017b70;
unsigned __cdecl FUN_00ec6130(int);
unsigned __cdecl Cmd_GetSessionTime_Execute();
namespace ScriptAnimation {
struct Reference;
struct Idle;
struct Process;
struct Sequence;
struct ResultList
{
    int head, tail, count;
    ~ResultList();
    void FUN_00ad8e60(void (*)(unsigned int), unsigned int);
};
void TESObjectREFR_SayToCallBack(unsigned int);
struct Sequence
{
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    void FUN_0083c7b0();
    int FUN_0083c820();
    void FUN_0083c850(int);
    ~Sequence();
};
struct Idle
{
    Sequence* TESTopic_CreateDialogueItem(Reference*, int, int, int, int);
};
struct Reference
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ~Reference();
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
    virtual bool IsSpecial();
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
    virtual ResultList Play(Idle*, Reference*, bool, bool, int, int, bool);
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
    virtual void* GetNode();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void* GetParent();
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
    virtual bool IsDead(int);
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
    virtual ResultList PlayActor(Idle*, Actor*, bool, bool, int, int);
    void TESObjectREFR_SetSayToTopic(Idle*);
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    void TESObjectREFR_SetSayToTopicInfo(unsigned int);
    Reference* FUN_005e3fa0();
    void FUN_00484490();
    void TESObjectREFR_SetObjectReference(void*);
    void TESObjectREFR_SetLocationOnReference(void*);
};
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
    virtual void Clear(int);
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void Reset();
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
    virtual void Update();
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
    virtual void Play(Actor*, Idle*, bool, int, int, int);
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
    virtual void SetAlert(int);
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
    virtual void v321();
    virtual void v322();
    virtual void v323();
    virtual void v324();
    virtual void v325();
    virtual void v326();
    virtual void v327();
    virtual void v328();
    virtual void v329();
    virtual void v330();
    virtual void v331();
    virtual void v332();
    virtual void v333();
    virtual void v334();
    virtual void v335();
    virtual void v336();
    virtual void v337();
    virtual void v338();
    virtual void v339();
    virtual void v340();
    virtual void v341();
    virtual void v342();
    virtual void v343();
    virtual void v344();
    virtual void v345();
    virtual void v346();
    virtual void v347();
    virtual void v348();
    virtual void v349();
    virtual void v350();
    virtual void v351();
    virtual void v352();
    virtual void v353();
    virtual void v354();
    virtual void v355();
    virtual void v356();
    virtual void v357();
    virtual void v358();
    virtual void v359();
    virtual void v360();
    virtual void v361();
    virtual void v362();
    virtual void v363();
    virtual void v364();
    virtual void v365();
    virtual void v366();
    virtual void v367();
    virtual void v368();
    virtual void v369();
    virtual void v370();
    virtual void v371();
    virtual void v372();
    virtual void v373();
    virtual void v374();
    virtual void v375();
    virtual void v376();
    virtual void v377();
    virtual void v378();
    virtual void v379();
    virtual void v380();
    virtual void v381();
    virtual void v382();
    virtual void v383();
    virtual void v384();
    virtual void v385();
    virtual void v386();
    virtual void v387();
    virtual void v388();
    virtual void v389();
    virtual void v390();
    virtual void v391();
    virtual void v392();
    virtual void v393();
    virtual void RestoreState(int);
    virtual void v395();
    virtual void v396();
    virtual void v397();
    virtual void v398();
    virtual void v399();
    virtual void v400();
    virtual void v401();
    virtual void SetState(int);
    virtual void v403();
    virtual void v404();
    virtual void v405();
    virtual void v406();
    virtual void v407();
    virtual void v408();
    virtual void v409();
    virtual void v410();
    virtual void v411();
    virtual void v412();
    virtual int GetState(int);
    int FUN_0045cd60();
};
extern Actor* DAT_011dea3c;
extern Setting DAT_011cd378;
extern const float DAT_01012054;
extern const char DAT_011846d4, DAT_011841cc;
Actor* FUN_00ec43fb(Reference*, int, const void*, const void*, int);
// 0x004f8960: no arguments on the stack; ECX carries the Actor.
int __fastcall GetActorAnimationAction(Actor*);
void Script_SetActionFlag(Idle*, void*, int);
Reference* TESObjectREFR_CreateReference(int, int);
bool Script_ParseParameters(void*, void*, void*, Reference*, void*, void*, void*, Idle**, int*, void**, int*, int*);
// @fnv 0x005c8a50
// src: EXE 0x005c8a50
bool Cmd_Say_Execute(void* paramInfo, void* scriptData, Reference* source, void* containing, void* script, void* locals,
                  double* result, void* offset)
{
    *result = 0.0;
    Idle* idleVal = 0;
    int force = 0;
    void* object4 = 0;
    int immediateA = 0;
    int _usePriority = 0;
    if (!Script_ParseParameters(paramInfo, scriptData, offset, source, containing, script, locals, &idleVal, &force, &object4,
                      &immediateA, &_usePriority))
        return false;
    bool forceFlag4 = false;
    bool immediateFlag4 = false;
    bool priorityFlag = false;
    if (immediateA)
        immediateFlag4 = true;
    if (force > 0)
        forceFlag4 = true;
    if (_usePriority > 0)
        priorityFlag = true;
    Actor* actor = FUN_00ec43fb(source, 0, &DAT_011841cc, &DAT_011846d4, 0);
    int previous = *DAT_011cd378.Setting_Int();
    DAT_011cd378.ProcessAndReturnValue_0045ce80(0x7fffffff);
    if (idleVal)
    {
        if (actor)
        {
            if (reinterpret_cast<Process*>(actor->FUN_008d8520()) && !reinterpret_cast<Reference*>(actor)->IsDead(1))
            {
                actor->ReferenceMobileState = DAT_01012054;
                reinterpret_cast<Process*>(actor->FUN_008d8520())->SetAlert(0);
                reinterpret_cast<Process*>(actor->FUN_008d8520())->Reset();
                if (!actor->FUN_00931850())
                {
                    int state = reinterpret_cast<Process*>(actor->FUN_008d8520())->GetState(2);
                    reinterpret_cast<Process*>(actor->FUN_008d8520())->SetState(0);
                    reinterpret_cast<Process*>(actor->FUN_008d8520())->RestoreState(state);
                    reinterpret_cast<Process*>(actor->FUN_008d8520())->Update();
                }
                else if (immediateA)
                {
                    reinterpret_cast<Reference*>(actor)->TESObjectREFR_SetSayToTopic(idleVal);
                    Sequence* chosen = idleVal->TESTopic_CreateDialogueItem(reinterpret_cast<Reference*>(actor), 0, 0, 0, 0);
                    if (chosen)
                        source->TESObjectREFR_SetSayToTopicInfo(chosen->GetHavokWorldObjectCountInSceneGraph_0084e3a0());
                    ResultList events = reinterpret_cast<Reference*>(actor)->PlayActor(idleVal, actor, immediateFlag4, priorityFlag, 0, 0);
                    events.FUN_00ad8e60(TESObjectREFR_SayToCallBack, source->GetHavokWorldObjectCountInSceneGraph_0084e3a0());
                    return true;
                }
                if (DAT_011dea3c->FUN_0094df60() || reinterpret_cast<Process*>(actor->FUN_008d8520())->FUN_0045cd60() != 0 ||
                    (actor->GetEssential() && GetActorAnimationAction(actor) == 6))
                {
                    Sequence* selected = idleVal->TESTopic_CreateDialogueItem(reinterpret_cast<Reference*>(actor), 0, 0, 0, 1);
                    if (selected)
                    {
                        selected->FUN_0083c7b0();
                        int unused = selected->FUN_0083c820();
                        selected->FUN_0083c850(0);
                        selected->FUN_0083c850(1);
                        Script_SetActionFlag(idleVal, actor->BSFile_GetDevice(), 0x40000);
                        delete selected;
                    }
                }
                else
                    reinterpret_cast<Process*>(actor->FUN_008d8520())->Play(actor, idleVal, forceFlag4, 0, 1, 1);
            }
            else if (reinterpret_cast<Process*>(actor->FUN_008d8520()))
            {
                Script_SetActionFlag(idleVal, actor->BSFile_GetDevice(), 0x40000);
                reinterpret_cast<Process*>(actor->FUN_008d8520())->Clear(0);
            }
        }
        else if (source && object4)
        {
            Reference* created = TESObjectREFR_CreateReference(59, 0);
            created->FUN_00484490();
            created->TESObjectREFR_SetObjectReference(object4);
            created->TESObjectREFR_SetLocationOnReference(source->GetParent());
            source->TESObjectREFR_SetSayToTopic(idleVal);
            Sequence* chosen2 = idleVal->TESTopic_CreateDialogueItem(created, 0, 0, 0, 0);
            if (chosen2)
                source->TESObjectREFR_SetSayToTopicInfo(chosen2->GetHavokWorldObjectCountInSceneGraph_0084e3a0());
            ResultList events7 = created->Play(idleVal, created, immediateFlag4, priorityFlag, 0, 0, forceFlag4);
            events7.FUN_00ad8e60(TESObjectREFR_SayToCallBack, source->GetHavokWorldObjectCountInSceneGraph_0084e3a0());
            delete created;
        }
        else if (source->GetNode() || (source->IsSpecial() && source->FUN_005e3fa0()->GetNode()))
        {
            source->TESObjectREFR_SetSayToTopic(idleVal);
            Sequence* chosen3 = idleVal->TESTopic_CreateDialogueItem(source, 0, 0, 0, 0);
            if (chosen3)
                source->TESObjectREFR_SetSayToTopicInfo(chosen3->GetHavokWorldObjectCountInSceneGraph_0084e3a0());
            ResultList events3 = source->Play(idleVal, 0, immediateFlag4, priorityFlag, 0, 0, forceFlag4);
            events3.FUN_00ad8e60(TESObjectREFR_SayToCallBack, source->GetHavokWorldObjectCountInSceneGraph_0084e3a0());
        }
    }
    DAT_011cd378.ProcessAndReturnValue_0045ce80(previous);
    return true;
}
}

class SaveLoad755
{
  public:
    bool IsLoading();
};
class Manager755
{
  public:
    void Refresh();
};
extern CompanionWheelMenu* g_pkMenu755;
extern SaveLoad755* g_pkSaveLoad755;
extern Manager755 g_kManager755;
void __cdecl CloseMenuAndRefresh(bool bFade);
struct ScriptTile256
{
    void Set(const char*, double);
};
struct MenuGlobal256
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    ScriptTile256* script;
};
struct HealingExtra
{
    int unk00;
};
struct HealingExtraList
{
    HealingExtra*& FUN_006815c0();
};
struct HealingInventoryEntry
{
    HealingExtraList* Modelloader_GetReferencedThis();
    TESBoundObject* FUN_0044ddc0();
    void* FUN_004459e0(unsigned int);
};
extern Actor* DAT_011dea3c;
extern char DAT_01183108, DAT_01183028, DAT_011830cc;
extern double DAT_01012060, DAT_01012070;
extern float DAT_01013974;
TESForm* FUN_0058db10(int);
void* FUN_00ec43fb(void*, int, void*, void*, int);
float FUN_00646800(ActorValueOwner*, int, int);
void* FollowerBarks_GetBarkTopicByType(int);


// @fnv 0x00755c50
// src: XBOX_PDB 0x00755c50
void CompanionWheelMenu::SetButtonAsHighlighted(float angle)
{
    if (angle >= 0.0 && angle < 0.5235980153083801)
        angle = 0.55f;
    else if (angle >= 2.617990016937256 && angle < 3.141590118408203)
        angle = 2.6f;
    else if (angle >= 3.14159 && angle < 3.665186)
        angle = 3.7f;
    else if (angle >= 5.759578)
        angle = 5.7f;

    int k;
    RadialTile* radialTile;
    float a;
    float high;
    for (k = 0; k < 16; k++)
    {
        radialTile = dynamic_cast<RadialTile*>(tiles[k]);
        if (radialTile)
        {
            a = radialTile->GetValueFloat(0x1006);
            high = radialTile->GetValueFloat(0x1007);
            if (angle >= a && angle < high)
            {
                SelectTile(k, false);
                break;
            }
        }
    }
}
