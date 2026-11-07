#include "../../../include/ActiveEffect.h"
#include "../../../include/Actor.h"
#include "../../../include/BSThread.h"
#include "../../../include/Character.h"
#include "../../../include/MagicCaster.h"
#include "../../../include/MagicTarget.h"
#include "../../../include/ReanimateEffect.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESSaveLoadGame.h"

// src/fallout/magic/reanimateeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/reanimateeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x00827440
// src: XBOX_PDB 0x00827440
unsigned short __thiscall ReanimateEffect::GetSaveSize_00827440(Actor* apActor)
{
    unsigned short isize = 0;
    isize += FUN_00804f80(apActor);
    isize += 4;
    isize += 4;
    isize += 0xc;
    isize += 0x10;
    return isize;
}

extern TESSaveLoadGame* g_TESSaveLoadGame;


// Loads the base ActiveEffect state, then reads four blocks (4, 4, 12 and 16 bytes) into this object at offsets 0x4c, 0x50, 0x54 and 0x60 via g_TESSaveLoadGame.
// @fnv 0x00827510
void ReanimateEffect::LoadGame(Actor* apActor)
{
    ActiveEffect::LoadGame(apActor);
    g_TESSaveLoadGame->ReadTypedData((void*)((char*)this + 0x4c), 4);
    g_TESSaveLoadGame->ReadTypedData((void*)((char*)this + 0x50), 4);
    g_TESSaveLoadGame->ReadTypedData((void*)((char*)this + 0x54), 12);
    g_TESSaveLoadGame->ReadTypedData((void*)((char*)this + 0x60), 16);
}

struct BodyVirt
{
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual void b10();
    virtual void b11();
    virtual void b12();
    virtual void b13();
    virtual void b14();
    virtual void b15();
    virtual void b16();
    virtual void b17();
    virtual void b18();
    virtual void b19();
    virtual void b20();
    virtual void b21();
    virtual void b22();
    virtual void b23();
    virtual void b24();
    virtual void b25();
    virtual void b26();
    virtual void b27();
    virtual void b28();
    virtual void b29();
    virtual void b30();
    virtual void b31();
    virtual void b32();
    virtual void b33();
    virtual void b34();
    virtual void b35();
    virtual void b36();
    virtual void b37();
    virtual void b38();
    virtual void b39();
    virtual void b40();
    virtual void b41();
    virtual void b42();
    virtual void b43();
    virtual void b44();
    virtual void b45();
    virtual void b46();
    virtual void b47();
    virtual void b48();
    virtual void b49();
    virtual void b50();
    virtual void b51();
    virtual void b52();
    virtual void b53();
    virtual void b54();
    virtual void b55();
    virtual void b56();
    virtual void __thiscall b57(int);
};
// Reverts this form, then restores body motion if the actor has 3D and iState is below 0x32.
// @fnv 0x008276e0
// src: XBOX_PDB 0x008276e0
void __thiscall ReanimateEffect::Revert_008276e0(Actor* apActor)
{
    ((TESForm*)this)->TESForm::Revert((unsigned int)apActor);
    if (iState < 0x32 && apActor && apActor->GetNiNode() && pBody)
    {
        pBody->b57(1);
    }
}

// Allocates and constructs a reanimation effect from the three arguments, returning the new object.
// @fnv 0x008273c0
// src: GUESS 0x008273c0 (confidence: medium)
ReanimateEffect* Object_ConstructObject(MagicCaster* apCaster, MagicItem* apSpell, EffectItem* apEffect)
{
    return new ReanimateEffect(apCaster, apSpell, apEffect);
}

// @fnv 0x008274a0
// src: XBOX_PDB 0x008274a0
void ReanimateEffect::SaveGame_008274a0(Actor* apActor)
{
    ActiveEffect::SaveGame(apActor);
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&m_4c, 4);
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&m_50, 4);
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(m_54, 12);
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(m_60, 16);
}

void* __cdecl operator new(unsigned int);
extern int _data_011c16bc;

struct FUN_008266a0_copy54
{
    unsigned char data[12];
};

struct FUN_008266a0_copy60
{
    unsigned char data[16];
};


// Allocates a new effect from three fields of this, passes it to a17, copies fields at 0x48-0x6f into it and returns it.
// @fnv 0x008266a0
// src: XBOX_PDB 0x008266a0
ActiveEffect* ReanimateEffect::Copy_008266a0()
{
    ActiveEffect* presult = reinterpret_cast<ActiveEffect*>(
        new ReanimateEffect(m_pEffectInstance, pSpell, pEffect));

    reinterpret_cast<ActiveEffect*>(this)->CopyData(presult);

    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(presult) + 0x48) =
        *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x48);
    *reinterpret_cast<int*>(reinterpret_cast<char*>(presult) + 0x4c) =
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x4c);
    *reinterpret_cast<float*>(reinterpret_cast<char*>(presult) + 0x50) =
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x50);

    *reinterpret_cast<FUN_008266a0_copy54*>(reinterpret_cast<char*>(presult) + 0x54) =
        *reinterpret_cast<FUN_008266a0_copy54*>(reinterpret_cast<char*>(this) + 0x54);

    *reinterpret_cast<FUN_008266a0_copy60*>(reinterpret_cast<char*>(presult) + 0x60) =
        *reinterpret_cast<FUN_008266a0_copy60*>(reinterpret_cast<char*>(this) + 0x60);

    return presult;
}

struct DH
{
    bool __thiscall TESDataHandler_GetClearingData();
};

extern DH* g_dataHandler;


struct Proc_S
{
    void* __thiscall GetNext();
};


struct EffectVirt
{
    virtual void a0()
    {}
    virtual void a1()
    {}
    virtual void a2()
    {}
    virtual void a3()
    {}
    virtual void a4()
    {}
    virtual void a5()
    {}
    virtual void a6()
    {}
    virtual void a7()
    {}
    virtual void a8()
    {}
    virtual void a9()
    {}
    virtual void a10()
    {}
    virtual void a11()
    {}
    virtual void a12()
    {}
    virtual void a13()
    {}
    virtual void a14()
    {}
    virtual void a15()
    {}
    virtual void a16()
    {}
    virtual void a17()
    {}
    virtual void a18()
    {}
    virtual void a19()
    {}
    virtual void a20()
    {}
    virtual void a21()
    {}
    virtual void a22()
    {}
    virtual void a23()
    {}
    virtual void a24()
    {}
    virtual void a25()
    {}
    virtual void a26()
    {}
    virtual void a27()
    {}
    virtual void a28()
    {}
    virtual void a29()
    {}
    virtual void a30()
    {}
    virtual void a31()
    {}
    virtual void a32()
    {}
    virtual void a33()
    {}
    virtual void a34()
    {}
    virtual void a35()
    {}
    virtual void a36()
    {}
    virtual void a37()
    {}
    virtual void a38()
    {}
    virtual void a39()
    {}
    virtual void a40()
    {}
    virtual void a41()
    {}
    virtual void a42()
    {}
    virtual void a43()
    {}
    virtual void a44()
    {}
    virtual void a45()
    {}
    virtual void a46()
    {}
    virtual void a47()
    {}
    virtual void a48()
    {}
    virtual void a49()
    {}
    virtual void a50()
    {}
    virtual void a51()
    {}
    virtual void a52()
    {}
    virtual void a53()
    {}
    virtual void a54()
    {}
    virtual void a55()
    {}
    virtual void a56()
    {}
    virtual void a57(int)
    {}
    virtual void a58()
    {}
    virtual void a59()
    {}
    virtual void a60()
    {}
    virtual void a61()
    {}
    virtual void a62()
    {}
    virtual void a63()
    {}
    virtual void a64()
    {}
    virtual void a65()
    {}
    virtual void a66()
    {}
    virtual void a67()
    {}
    virtual void a68()
    {}
    virtual void a69()
    {}
    virtual void a70()
    {}
    virtual void a71()
    {}
    virtual void a72()
    {}
    virtual void a73()
    {}
    virtual void a74()
    {}
    virtual void a75()
    {}
    virtual void a76()
    {}
    virtual void a77()
    {}
    virtual void a78()
    {}
    virtual void a79()
    {}
    virtual void a80()
    {}
    virtual void a81()
    {}
    virtual void a82()
    {}
    virtual void a83()
    {}
    virtual void a84()
    {}
    virtual void a85()
    {}
    virtual void a86()
    {}
    virtual void a87()
    {}
    virtual void a88()
    {}
    virtual void a89()
    {}
};

void __cdecl CommandEffect_CleanupCommandedActor(Actor*, Actor*, int);


// @fnv 0x00827230
// src: XBOX_PDB 0x00827230
void __thiscall ReanimateEffect::Finish_00827230()
{
    if (g_dataHandler->TESDataHandler_GetClearingData())
        return;

    Actor* pTarget = reinterpret_cast<ActiveEffect*>(this)->GetTarget()
                         ? reinterpret_cast<ActiveEffect*>(this)->GetTarget()->GetOwnerActor()
                         : 0;

    if (pTarget != 0)
    {
        if (m_4c < 0x32)
        {
            pTarget->Actor_SetGhost(false);
            if (m_48 != 0)
                m_48->a57(1);
            pTarget->Kill(0, 0.0f);
        }
        else
        {
            if (!pTarget->HasHealth(false))
                pTarget->Kill(0, 0.0f);
        }

        Actor* pCasterActor =
            reinterpret_cast<Proc_S*>(this)->GetNext()
                ? reinterpret_cast<MagicCaster*>(reinterpret_cast<Proc_S*>(this)->GetNext())->GetCasterActor()
                : 0;

        if (pCasterActor != 0)
            CommandEffect_CleanupCommandedActor(pTarget, pCasterActor, 0);
    }
}

struct BoneName
{
    const char* text;
    BoneName(const char*);
    ~BoneName();
};
struct ReanimateNode
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual ReanimateNode* GetObject(const BoneName&);
};
struct ReanimateBody
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void SetActive(bool, bool);
};
struct ActorBodyAccess : Actor
{
    ReanimateBody* Actor_GetFaceAnimationData();
};
struct BoneCollision
{
    BodyVirt* bhkNiCollisionObject_GetWorldObject();
};
BoneCollision* FUN_0043b610(ReanimateNode*);
void bhkWorld_SetMotion(ReanimateNode*, bool, bool, bool, bool);
void Warning_005b5e40(const char*);
// @fnv 0x00827580
void ReanimateEffect::UpdateReanimation(Actor* actor)
{
    FUN_00805760(actor);
    ReanimateNode* root = reinterpret_cast<ReanimateNode*>(actor->GetNiNode());
    if (root)
    {
        ReanimateBody* controller2 = static_cast<ActorBodyAccess*>(actor)->Actor_GetFaceAnimationData();
        if (controller2)
        {
            if (state < 40)
                controller2->SetActive(true, true);
            else
                controller2->SetActive(false, false);
        }
        if (state < 30)
            bhkWorld_SetMotion(root, true, true, false, true);
        ReanimateNode* spine = root->GetObject(BoneName("Bip01 Spine2"));
        if (spine)
        {
            BoneCollision* collision8 = FUN_0043b610(spine);
            if (collision8)
            {
                pBody = collision8->bhkNiCollisionObject_GetWorldObject();
                pBody->b57(4);
            }
        }
        else
        {
            Warning_005b5e40("SAVELOAD: No Bip01 Spine2 bone for reanimation. Need a backup bone!");
        }
    }
}

struct RActor;
struct RNode;
struct RProcess;
struct RPackage;
struct RVector
{
    float x, y, z;
};
struct RSource
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
    virtual int GetType();
};
struct RValues
{
    virtual int GetBase(int, int);
    virtual void v1();
    virtual void v2();
    virtual float GetCurrent(int);
};
struct BoneKey
{
    const char* text;
    BoneKey(const char*);
    ~BoneKey();
};
struct RNode
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
    virtual RNode* GetObject(const BoneKey&);
};
struct RProcess
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
    virtual void Reset(int);
    virtual void v395();
    virtual void v396();
    virtual void v397();
    virtual void v398();
    virtual void v399();
    virtual void v400();
    virtual void v401();
    virtual void v402();
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
    virtual void v413();
    virtual void v414();
    virtual void v415();
    virtual void v416();
    virtual void v417();
    virtual void v418();
    virtual void v419();
    virtual void v420();
    virtual void v421();
    virtual void v422();
    virtual void v423();
    virtual void v424();
    virtual void v425();
    virtual void v426();
    virtual void v427();
    virtual void v428();
    virtual void v429();
    virtual void v430();
    virtual void v431();
    virtual void v432();
    virtual void v433();
    virtual void v434();
    virtual void v435();
    virtual void v436();
    virtual void v437();
    virtual void v438();
    virtual void v439();
    virtual void v440();
    virtual void v441();
    virtual void v442();
    virtual void v443();
    virtual void v444();
    virtual void v445();
    virtual void Enable(int);
};
struct RProcessAccess : RProcess
{
    void* GetSource();
};
struct RBody
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
    virtual void SetMotion(int);
};
struct RBodyAccess : RBody
{
    void GetPosition(RVector&);
    void GetRotation(RVector&);
};
struct RCollision
{
    RBodyAccess* GetBody();
};
RCollision* FindCollision(RNode*);
struct RPackage
{
    void SetType(int);
    void SetReach(bool);
    void SetComplete(bool);
    void SetProcedure(int);
    void SetEnabled(bool);
};
RPackage* MakePackage(int);
struct RActor
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
    virtual void SetStateFlags(int);
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
    virtual void Refresh();
    virtual void v114();
    virtual void v115();
    virtual RNode* GetNode();
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
    virtual void SetType(int);
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
    virtual void SetPackage(RPackage*, bool, bool);
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
    virtual void ModValue(int, float);
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
    virtual void Clear(int);
};
struct RActorAccess : RActor
{
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
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    RValues values;
    void SetState(int);
    bool CheckFlag();
    RProcessAccess* GetProcess();
    void SetFlag(bool);
    void SetLocation(RVector*);
    void SetZero(int);
    void Prepare();
    void UpdateNode(RNode*);
};
struct RNodeAccess : RNode
{
    RVector* GetPosition();
};
struct RTarget
{
    RActorAccess* AsActor();
};
void UpdatePhysics(RNode*, int, bool, bool, bool);
void Warn(const char*);
RSource* __fastcall GetReanimationSource(ReanimateEffect* apEffect);

// If the target actor is dead, resets and reconfigures it, assigns a package, and stores the spine bone's body position and rotation; otherwise dispels.
// @fnv 0x008267b0
void ReanimateEffect::StartReanimation()
{
    if (!GetReanimationSource(this))
    {
        Dispel(true);
        return;
    }
    RActorAccess* actor = GetTarget() ? reinterpret_cast<RTarget*>(GetTarget())->AsActor() : 0;
    if (actor && actor->IsDead(0))
    {
        actor->SetStateFlags(0);
        actor->SetState(4);
        if (actor->CheckFlag())
            actor->Clear(0);
        RProcessAccess* process = actor->GetProcess();
        if (!process->GetSource())
            process->Enable(1);
        actor->SetFlag(true);
        actor->SetType(GetReanimationSource(this)->GetType());
        if (actor->GetNode())
            actor->SetLocation(((RNodeAccess*)actor->GetNode())->GetPosition());
        actor->Refresh();
        actor->GetProcess()->Reset(0);
        actor->SetZero(0);
        actor->ModValue(16, actor->values.GetBase(16, 0) - actor->values.GetCurrent(16));
        if (actor->GetNode())
        {
            actor->Prepare();
            actor->UpdateNode(actor->GetNode());
        }
        RPackage* package = MakePackage(27);
        package->SetType(27);
        package->SetReach(true);
        package->SetComplete(true);
        package->SetProcedure(25);
        package->SetEnabled(true);
        actor->SetPackage(package, true, true);
        RNode* node = actor->GetNode();
        if (node)
        {
            UpdatePhysics(node, 1, true, false, true);
            RNode* bone = node->GetObject(BoneKey("Bip01 Spine2"));
            if (bone)
            {
                RCollision* collision = FindCollision(bone);
                if (collision)
                {
                    body = collision->GetBody();
                    body->SetMotion(4);
                    body->GetPosition(*reinterpret_cast<RVector*>(m_54));
                    body->GetRotation(*reinterpret_cast<RVector*>(m_60));
                }
            }
            else
                Warn("ANIMATION: No Bip01 Spine2 bone for reanimation. Need a backup bone!");
        }
    }
    else
        Dispel(false);
}

// The shared Character has no declaration for 0x004f8960. Its no-argument
// thiscall accessor uses ECX, as does this one-argument fastcall declaration.
int __fastcall GetReanimationCharacterState(Character* apCharacter);

typedef TESObjectREFR* (__thiscall* ReanimationReferenceResolver)(TESObjectREFR*);


// The reference resolver at virtual slot 1 returns the candidate Character.
// That return signature is not exposed by the shared TESObjectREFR declaration.
// @fnv 0x00827340
// src: XBOX_PDB 0x00827340
bool ReanimateEffect::CheckTarget_00827340(TESObjectREFR* apRef)
{
    Character* pChar = dynamic_cast<Character*>((*reinterpret_cast<ReanimationReferenceResolver**>(apRef))[1](apRef));
    if (pChar != 0 && pChar->HasHealth(false) && !pChar->Actor_IsReanimated() && GetReanimationCharacterState(pChar) != 6)
    {
        return true;
    }
    return false;
}

struct V12b
{
    unsigned int d[3];
};
struct V16b
{
    unsigned int d[4];
};
struct V12t
{
    unsigned int d[3];
    V12t& Make(float, float, float);
};
struct V16p
{
    unsigned int d[4];
};
extern V16p g_v;
// The shared effect stores its vectors as byte arrays. Their initialization
// routine takes the vector address in ECX.
void __fastcall InitializeReanimationVector(void* apVector);

// Initializes m_48, m_4c, and m_50 to zero, assigns m_54 from Make(0, 0, 0), and copies g_v to m_60.
// @fnv 0x008265b0
ReanimateEffect::ReanimateEffect(MagicCaster* a, MagicItem* b, EffectItem* c) : ActiveEffect(a, b, c)
{
    InitializeReanimationVector(m_54);
    InitializeReanimationVector(m_60);
    m_48 = 0;
    m_50 = 0.0f;
    m_4c = 0;
    V12t t;
    *reinterpret_cast<V12b*>(m_54) = *(V12b*)&t.Make(0.0f, 0.0f, 0.0f);
    *reinterpret_cast<V16b*>(m_60) = *(V16b*)&g_v;
}
