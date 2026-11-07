
// src/fallout/ai/lipsyncbackgroundmanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/lipsyncbackgroundmanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/AutoMemContext.h"
#include "../../../include/IOManager.h"
#include "../../../include/LipTask.h"

struct FUN_00c3d0e0_stub
{
    bool __thiscall QueuedFileEntry_GetDescription(char* apDescription, unsigned int aiBufferSize, const char* apTag);
};


// @fnv 0x00905e00
// src: XBOX_PDB 0x00905e00
bool LipTask::GetDescription_00905e00(char* apDescription, unsigned int aiBufferSize)
{
    return reinterpret_cast<FUN_00c3d0e0_stub*>(this)->QueuedFileEntry_GetDescription(apDescription, aiBufferSize, "liptask");
}

struct FUN_009060f0_shell
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int arg);
    void CallVirtual5(int arg);
};

// @fnv 0x009060f0
void FUN_009060f0_shell::CallVirtual5(int arg)
{
    this->v5(arg);
}

struct FUN_00906160_shell
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int arg);
    void __thiscall FUN_00906160(int a, int b, int c);
};
struct FUN_00905e30_shell : FUN_00906160_shell
{
    void* __thiscall EvaluateValue_00905e30();
};
// @fnv 0x00905e30
// src: GUESS 0x00905e30 (confidence: low)
void* __thiscall FUN_00905e30_shell::EvaluateValue_00905e30()
{
    FUN_00906160(10, 37, 12);
    return this;
}

struct FUN_00905dc0_shell
{
    char _pad0[0x30];
    int _m30;
    char _pad1[4];
    FUN_009060f0_shell* _m38;
    void QueuedFile_Cancel(int, void*);
    void HandleStateChange(int, void*);
};
// Calls FUN_00c3cb70 with the previous state and task owner, then, unless the previous state is 5, calls CallVirtual5 on _m38 with _m30.
// @fnv 0x00905dc0
void FUN_00905dc0_shell::HandleStateChange(int aePreviousState, void* apTaskOwner)
{
    QueuedFile_Cancel(aePreviousState, apTaskOwner);
    if (aePreviousState != 5)
    {
        _m38->CallVirtual5(_m30);
    }
}

struct UnkObj
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
    virtual void v220(int arg);
    virtual void v221(int arg);
    virtual void v222();
    virtual void v223();
    virtual void v224(int arg);
};
struct UnkHolder
{
    UnkObj* FUN_008d8520();
};
struct FUN_00905d20_cls
{
    int unk00;
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
    UnkHolder* m_30;
    int m_34;
    FUN_009060f0_shell* m_38;
    void LipTask_Finish();
};

// If the holder's object exists, calls v224 with m_34, v220 with 0, and v221 with 1 when m_34 is 0, then calls m_38 with m_30.
// @fnv 0x00905d20
// src: XBOX_PDB 0x00905d20
void FUN_00905d20_cls::LipTask_Finish()
{
    if (m_30->FUN_008d8520() != 0)
    {
        m_30->FUN_008d8520()->v224(m_34);
        m_30->FUN_008d8520()->v220(0);
        if (m_34 == 0)
        {
            m_30->FUN_008d8520()->v221(1);
        }
    }
    m_38->CallVirtual5(reinterpret_cast<int>(m_30));
}

// LockFreeMapIterator<NiPointer<LipTask> > - a 13 byte polymorphic iterator
struct It
{
    void* unk00;
    int unk04;
    int unk08;
    unsigned char unk0c;
    It();
    ~It();
    bool LockFreeMap_char_const_Model_LockFreeMapIterator_GetFinished();
};

// GlobalObject_00528cb0 - a 4 byte smart pointer holder
struct G
{
    int unk00;
    G(int a);
    ~G();
    int Modelloader_GetReferencedThis(int a);
};

extern IOManager* DAT_01202d98;

// LockFreeMap<MobileObject*, NiPointer<LipTask> > - the base of the class below
struct BaseMap
{
    BaseMap();
    ~BaseMap();
    int unk00;
};

struct FUN_00905e50_Class : public BaseMap
{
    FUN_00905e50_Class();
    ~FUN_00905e50_Class();
    bool AdvanceRequest(It* a, int* b, G* c, int d);
    void CallVirtual5(int a);
};

// Destructor iterates an It until done, and for each successful AdvanceRequest call invokes CallVirtual5 and FUN_0044ac40 on the result of FUN_00559450.
// @fnv 0x00905e50
FUN_00905e50_Class::~FUN_00905e50_Class()
{
    {
        It iter;
        while (!iter.LockFreeMap_char_const_Model_LockFreeMapIterator_GetFinished())
        {
            int n = 0;
            G g2(0);
            if (AdvanceRequest(&iter, &n, &g2, 1))
            {
                CallVirtual5(n);
                DAT_01202d98->BSTaskManager_CancelTask(g2.Modelloader_GetReferencedThis(0));
            }
        }
    }
}

namespace fnv_00905f30 {
struct FUN_00905ba0
{
    FUN_00905ba0(int owner, int actor, const char* tag);
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
};
struct S_00905f30_Ref
{
    S_00905f30_Ref(FUN_00905ba0* p);
    ~S_00905f30_Ref();
    FUN_00905ba0* p;
};
struct S_00905f30_Proc
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
    virtual void SetTarget(int a);
};
struct S_00905f30_Actor
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
    S_00905f30_Proc* GetProc();
};
struct S_00905f30_Owner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool Enqueue(S_00905f30_Actor* a, const S_00905f30_Ref& r, int f);
    void LipSyncBackgroundManager_CancelLipFile(S_00905f30_Actor* a);
    void StartLipSyncTask(S_00905f30_Actor* actor, const char* tag);
};

// Creates a task for the actor and tag, enqueues it, clears the actor's proc target and adds the task to the manager.
// @fnv 0x00905f30
void S_00905f30_Owner::StartLipSyncTask(S_00905f30_Actor* actor, const char* tag)
{
    AutoMemContext ctx(0x35, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Ai\\LipSyncBackgroundManager.cpp",
                       0x61);
    LipSyncBackgroundManager_CancelLipFile(actor);
    FUN_00905ba0* task = new FUN_00905ba0((int)this, (int)actor, tag);
    bool ok = Enqueue(actor, task, 0);
    actor->GetProc()->SetTarget(0);
    DAT_01202d98->AddTask(reinterpret_cast<QIOTask*>(task));
}
}  // namespace fnv_00905f30

extern unsigned int DAT_011c16bc;
extern char str_010885e8[];

struct BGSTerrainManager;

struct FUN_00905c50_Class
{
    int unk00;
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
    UnkHolder* unk30;
    BGSTerrainManager* unk34;

    int FUN_00c3cff0(int a1, int a2);
    void InitTerrainManager();
};

BGSTerrainManager* __cdecl ReadAnimationFromStream(void* apFile);

// @fnv 0x00905c50
void FUN_00905c50_Class::InitTerrainManager()
{
    void* file;
    AutoMemContext memoryContext7(0x35, true, str_010885e8, 0x15);

    file = (void*)FUN_00c3cff0(4, 0x10);
    if (file == 0)
    {
        unk30->FUN_008d8520()->v220(0);
        unk30->FUN_008d8520()->v221(1);
    }

    unk34 = ReadAnimationFromStream(file);
}
