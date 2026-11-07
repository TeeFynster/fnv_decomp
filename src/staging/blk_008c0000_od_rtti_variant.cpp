#include "../../include/ProcessLists.h"

// src/staging/blk_008c0000_od_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESObjectREFR). The skeleton of src/staging/blk_008c0000_od.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

// src/staging/blk_008c0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/Actor.h"
#include "../../include/BSSimpleArray.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiPoint3.h"
#include "../../include/BGSSaveFormBuffer.h"
#include "../../include/BSMultiBoundNode.h"
#include "../../include/ArrowProjectile.h"
#include "../../include/BSMultiBound.h"
#include "../../include/CountingSemaphore.h"
#include "../../include/MagicCaster.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiCamera.h"
#include "../../include/NiTimeController.h"
#include "../../include/TES.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESTopicInfo.h"
#include "../../include/ActorPackageContext.h"
#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/BSFaceGenMorphData.h"
#include "../../include/BSMultiBoundShape.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiUpdateData.h"
#include "../../include/NiMatrix3.h"
#include "../../include/BGSAcousticSpace.h"
#include "../../include/GO.h"
#include "../../include/HighProcess.h"
#include "../../include/PathingRequest.h"
struct FUN_008c1be0_Class
{
    unsigned int __thiscall bhkTTNode_TESObjectREFR_GetFlags(unsigned int mask);
};
struct BooleanFloatQuery
{
    void DecRefCount();
};
struct S_008c1c60
{
    void __thiscall ReleaseReferencedObject_008c1c60();
};
struct FlaggedData
{
    int ContainsAnyFlag(unsigned int);
    int ContainsAnyFlag_Thunk();
};
int FlaggedData::ContainsAnyFlag(unsigned int)
{
    return 0;
}
struct FUN_008c5000_shell
{
    int Actor_GetCastPowerItem(int);
    int IsNonZero(int arg);
};
void ActorPackageContext::Clear()
{}
struct FUN_008c6c80_Class
{
    void __thiscall FUN_008c6c80(int a);
};
extern int DAT_01085864;
struct FUN_008ca740_class
{
    void __thiscall InitializeVtbl();
    FUN_008ca740_class* __thiscall InitializeFields_008ca740();
};
extern int DAT_01085884;
struct FUN_008ca7a0_cls
{
    void* vtbl;
    void* __thiscall InitializeVtbl();
};
struct GlobalObject_0044fae0
{
    void* Object_InitializeCriticalSection_Thunk();
};
struct FUN_008caab0 : GlobalObject_0044fae0
{
    int m_40;
    int m_44;
    void* Init();
};
struct FUN_008cc6d0_class
{
    void EffectSetting_SetAreaSound(int value);
};
struct T_
{
    void SetValue(void*);
};
struct FUN_008cd6a0_Class
{
    void hkRotation_set(void*);
    void hkTransform_set(void* a, void* b);
};
extern int DAT_011dfc9c;
unsigned int __cdecl bhkCollisionFilter_GetNewSystemGroup();
unsigned int __cdecl GetCachedValue();
struct FUN_008ce370_cls
{
    unsigned char GetByteAtOffsetC1();
};
struct CalleeObj
{
    void UpdateState_00622570(bool);
};
struct FUN_008cfff0_Class
{
    int m_iWordAt00;
    int m_cByteAtOffset1;
    int m_cByteAtOffset2;
    CalleeObj* hkpWorldObject_isAddedToWorld(CalleeObj* arg);
};
struct FUN_008d01e0_Class
{
    float NiAVObject_GetWorldScale() const;
};
struct FUN_008d0200_Class
{
    char GetByteAtOffsetC3();
};
struct FUN_008d0220_class
{
    void SetByteAtOffsetC3(char arg);
};
struct FUN_008d0240_Class
{
    void ArrowProjectile_ClearAttachedRef();
};
struct FUN_008d1160_Class
{
    void __thiscall ForwardCall_008d1160();
    void __thiscall FUN_00c705c0();
};
struct GlobalObject2_0096a2d0
{
    void __thiscall _ref_00905330(const void**);
};
extern GlobalObject2_0096a2d0 g_011dfe14;
void __cdecl BSDoorHavokController_ReleaseDoor(const void* p);
extern float DAT_011dfed4;
extern float DAT_011dfed8;
void __cdecl SetCameraShakeData(float a, float b);
struct FUN_008d5020_class
{
    void __thiscall CharacterProgression_AllocateData();
};
// src: COMMUNITY 0x008d5020
void __thiscall FUN_008d5020_class::CharacterProgression_AllocateData()
{}
struct FUN_008d4360_class
{
    FUN_008d4360_class* __thiscall CharacterProgression_CharacterProgression();
};
extern "C" void __cdecl FreeAndClear();
struct FUN_008d4380_class
{
    void __thiscall FreeAndClear();
    void __thiscall FreeAndClear_Thunk();
};
struct FUN_008d5590_shell
{
    void CharacterProgressionData_InitializeData();
};
struct FUN_008d50e0_shell
{
    FUN_008d5590_shell* m_p;
    void CharacterProgression_InitializeData();
};
struct FUN_008d5660_class
{
    void __thiscall SaveToBuffer(int a);
    void __thiscall ForwardToInner(int a);
};
struct FUN_008d5720
{
    char bFlag;
    int nValue;
    void __thiscall Init(int);
};
struct TaskQueueInterface
{
    void SetTaskFlagDWord(bool enabled, unsigned int flag);
    void SetTaskFlag(bool enabled);
};
struct FUN_008da180_Class
{
    float GetField2B4();
};
struct FUN_006d2c00_shell
{
    void FUN_006d2c00();
};
extern int DAT_0108583c;
struct FUN_008ca800_Class
{
    int a;
    int b;
    int c;
    FUN_008ca800_Class* __thiscall BSTFreeList_MobileObjectMessage_BSTFreeList_MobileObjectMessage();
};
extern "C" void __cdecl _Deallocate(void*);
struct FUN_008c4f90_Class
{
    void __thiscall Actor_RemoveCastPower(int arg);
};
void __cdecl _Deallocate(void*);
// Sibling blk_008c0000_od binds this accessor to 0x004ae750 (nullable GetReferenceFlags), not ScriptLocals::GetLocalData at 0x00541c80.
struct NullableReferenceFlagsAccessor
{
    void* GetLocalData();
};
struct FUN_008c5df0_Class
{
    void bhkMouseSpringAction_SetMousePosition_hk(void* arg);
};
struct FUN_008c5e20_Class
{
    int a;
    int b;
    int c;
    int d;
    float e;
    int f;
    void* __thiscall InitializeFields_008c5e20();
};
struct FUN_008c7790_Class
{
    void __thiscall FUN_008c77c0();
    void* __thiscall DestroyIfFlagged(unsigned int flags);
};
struct GlobalObject_0078d3b0
{
    ~GlobalObject_0078d3b0();
};
struct FUN_00aa63c0_base
{
    ~FUN_00aa63c0_base();
};
struct FUN_008c77c0_Class : FUN_00aa63c0_base
{
    ~FUN_008c77c0_Class();
    unsigned char m_00[0x30];
    GlobalObject_0078d3b0 m_008c77f0;
    unsigned char m_18[0x0b];
    GlobalObject_0078d3b0 m_008c77e4;
};
extern unsigned char DAT_011dfa19;
void __fastcall AITaskThread_WaitForCompletion(void*);
struct FUN_008c7990_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void __fastcall AILinearTaskThreadManager_WaitForThreads();
};
struct FUN_008ca7c0_shell
{
    bool __thiscall PopNode(int a);
    void __thiscall Reinitialize(int b);
    bool __thiscall BSTFreeList_Allocate(int a, int b);
};
struct FUN_008_Struct
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* __thiscall InitializeFields_008caa70(FUN_008_Struct* source);
};
struct BMobile_S
{
    BMobile_S();
    ~BMobile_S();
    char pad[0xd0];
};
struct B006815c0
{
    B006815c0();
};
extern int DAT_01085948;
extern int DAT_01085954;
extern int DAT_011dfc98;
struct FUN_008cab20 : BMobile_S
{
    FUN_008cab20();
};
extern int DAT_01085e2c;
void __cdecl InitializeFields_008c5e20();
struct FUN_008d0270_Class
{
    void* vtbl;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    FUN_008d0270_Class* __thiscall BaseProcess_BaseProcess();
};
void __cdecl CallWithParam(int);
struct FUN_008d1130_Class : FUN_008d1160_Class
{
    FUN_008d1130_Class* __thiscall FUN_008d1130(unsigned int flags);
};
extern "C" void __fastcall FUN_00a6d220(void*);
extern int DAT_010867fc;
struct FUN_008d15d0_Class
{
    void* __thiscall BSPlayerDistanceCheckController_BSPlayerDistanceCheckController();
};
struct FUN_0087d4a0
{
    FUN_0087d4a0(bool ab);
    ~FUN_0087d4a0();
    void FUN_008d4e80();
};
struct SFTX
{
    void SetFormType(int);
};
extern int DAT_0108695c;
extern int DAT_010869a4;
extern int DAT_010869d4;
extern int DAT_01086a0c;
extern int DAT_01086a60;
extern int DAT_01086a6c;
struct FUN_008d1d30 : FUN_0087d4a0
{
    FUN_008d1d30();
};
struct FUN_008d56c0_class
{
    void __thiscall SaveToBuffer(int a);
};
struct FUN_008d56f0_Class
{
    void __thiscall CharacterProgressionData_LoadGameBGS(BGSLoadFormBuffer* buffer);
};
unsigned int __cdecl gm_GetTickCount();
unsigned int __cdecl FollowerBarks_GetBarkNoRepeatDuration(unsigned int a);
struct FUN_008d6000_Class
{
    unsigned int m_iWordAt00;
    unsigned int m_iWordAt04;
    unsigned int m_8;
    unsigned int m_iThirdValue;
    void __thiscall InitTiming(unsigned int a, unsigned int b);
};
struct S694a0
{
    void NiCullingProcess_SetFrustum(void*);
};
struct FUN_008d6bb0_shell
{
    void CreateMultiBoundNode(int);
};

extern ProcessLists DAT_011e0e80;
struct FUN_008d6f50_Class
{
    void HighActorCuller_Run(int arg);
};
extern "C" void __cdecl _delete(void* p, unsigned int size);
struct FUN_008df980_Class
{
    void __thiscall FUN_008df9b0();
    void* __thiscall FUN_008df980(unsigned int flags);
};
struct NiFixedStr
{
    operator const char*();
};
struct SeqObj
{
    NiFixedStr& GetName();
};
struct ModelLoader
{
    void ModelLoader_ReleaseFile(const char* name);
};
struct Loader_S
{
    ModelLoader* m_p;
};
extern Loader_S g_modelLoader;
extern int DAT_011e00e0[12];
extern int DAT_011e0110[12];
void __cdecl FreeWobbleAnimations();
struct Model
{
    NiTimeController* GetObject3D();
};
struct GlobalObject_00a7b610
{
    bool __cdecl NiObject_IsExactKindOf(NiTimeController*);
};
extern GlobalObject_00a7b610 g_012031b8;
int __cdecl get_g_bip01();
struct FUN_008da1a0_Class
{
    void HighProcess_InitBoneLOD(Actor* actor);
};
struct FUN_0052d240_obj
{
    ~FUN_0052d240_obj();
};
struct FUN_008c7860_Class : FUN_008c77c0_Class
{
    unsigned char m_00[0x13];
    FUN_0052d240_obj m_008c78b0;
    ~FUN_008c7860_Class();
};
struct Call741e0
{
    void FUN_00c741e0(int);
};
extern int DAT_01086658;
extern int DAT_01086674;
extern int DAT_01086684;
struct FUN_008d10e0_Class : Call741e0
{
    void* bhkCharacterListenerArrow_bhkCharacterListenerArrow(int a, int b);
};
struct FUN_00929240_Class
{
    void MagicShaderHitEffect_SetLifeTime(float);
};
struct CloneableObj
{
    void FUN_00a6cfe0(CloneableObj*, void*);
};
struct FUN_008d17d0_Class
{
    void BSPlayerDistanceCheckController_CopyMembers(BGSAcousticSpace* dst, void* arg);
};
struct FUN_0087adf0_shell
{
    int InitScriptRunLockForSelf();
};
struct FUN_008c1c30_Class
{
    FUN_0087adf0_shell* m_iWordAt00;
    FUN_008c1c30_Class* UpdateState_008c1c30(FUN_0087adf0_shell* a);
};
struct FUN_008c45a0_Result
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
    virtual void Actor_SetShouldCheckMagicNode(unsigned char arg);
};
struct FUN_008c7250_Class
{
    FUN_008c7250_Class* __thiscall FUN_008c7250();
};
struct FUN_008c7270 : GlobalObject_0078d3b0
{
    ~FUN_008c7270();
};
struct FUN_008c7270_Class
{
    void FUN_008c7270();
};
struct FUN_008c8110_Class
{
    void __thiscall ForwardCall_008c8110();
    unsigned char m_00[0x18];
    FUN_008c7270_Class m_18;
};
void __stdcall FUN_0065ee50_Helper(void* p, unsigned int size, int count, void(__cdecl* cb)(void));
void __cdecl FUN_008c7270_Cb(void);
struct Date
{
    ~Date();
};
struct FUN_008ca770_Class
{
    void ProcessEntries_008ca8d0(Date**);
    void ProcessState_008ca770(Date**);
};
int __cdecl BSAtomicCompareExchange(long volatile*, long, long);
// Exe 0x008d12e0: unit-local Interface view; declarations and layout are preserved.
struct BlkInterfaceView
{
    static void __cdecl PrintDebugMessage();
};
struct FUN_008ca8d0_Class
{
    int m_iWordAt00;
    long volatile m_iWordAt04;
    int m_8;
    void __thiscall ProcessEntries_008ca8d0(int* arg);
};
struct FUN_008caae0_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    void* __thiscall BSTFreeListElem_MobileObjectMessage_BSTFreeListElem_MobileObjectMessage();
};
struct FUN_008cc6f0_Class
{
    void* EvaluateValue_008cc6f0();
};
struct FUN_008d3f40_Class
{
    void __thiscall GetEntryAt(int arg);
};
struct FUN_008d3f10_Class
{
    unsigned char pad[0x38];
    GO m_38;

    void __thiscall NiGeomMorpherController_GetTarget(int arg);
};
struct FUN_008d50a0_Class
{
    void* m_p;
    void __thiscall FreeAndClear();
};
struct FUN_008d5680_Class
{
    FUN_008d56f0_Class* m_p;
    void CharacterProgression_LoadGameBGS(BGSLoadFormBuffer* arg);
};
struct FUN_008d56a0_Class
{
    void __thiscall ProcessAndTransformResult_008d56a0(int value);
};
extern int DAT_011c3580;
int __cdecl MagicSystem_GetAbsorbShaderEffect();
struct S_8c4f10_Item
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
    virtual void v14(int a);
};
struct S_8c4f10_Node
{
    S_8c4f10_Item** FUN_006815c0();
    S_8c4f10_Node* FUN_00726070();
    int FUN_005ae380();
};
struct S_8c4f10_List
{
    virtual void v00();
    virtual void v01();
    virtual S_8c4f10_Node* v02();
};
struct S_8c4f10_Cls
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
    S_8c4f10_List list;
    void Actor_CheckDeletedCaster(int a);
};
struct SpawnedElemB
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
};
extern "C" void __stdcall SpawnedArrayCtor(void* pBase, unsigned int elemSize, unsigned int count, void (*ctor)(void*),
                                           void (*dtor)(void*));
void SpawnedElemB_Ctor(void* p)
{}
void SpawnedElemB_Dtor(void* p)
{}
struct FUN_008c71d0_cls
{
    unsigned int m_00[3];
    unsigned int m_0c[3];
    SpawnedElemB m_18[3];
    unsigned int m_3c[12];
    unsigned int m_6c[8];
    unsigned int* m_8c;
    unsigned int* m_90;
    FUN_008c71d0_cls* AILinearTaskThreadManager_AILinearTaskThreadManager();
};
// Stand-in for the game's class (the pack's own unit file does not declare it):
//   +0x00  two element pointers          +0x0c  two ints
//   +0x3c  twelve ints                   +0x6c  eight ints
struct FNV_008c9fb0_Element
{
    void SignalAtOffset30();
};
struct FUN_008c78c0_Class
{
    FNV_008c9fb0_Element* unk00[2];
    int unk08;
    int unk0c[2];
    int unk14[10];
    int unk3c[12];
    int unk6c[8];
    void AILinearTaskThreadManager_StartThreads();
};
// Callback slot in the game's global handler table: one int argument, and the
// callee pops it (stdcall), so the call site has no stack cleanup.
extern void(__stdcall* g_FNV_008c78c0_hook)(int);
void __cdecl ProgramFlow();
int __cdecl BSAtomicCompareExchange(long volatile*, long, long);
struct FreeNode16
{
    int unk00;
    int unk04;
    int unk08;
    FreeNode16* next;
};
struct FUN_008ca830_cls
{
    int unk00;
    long unk04;
    FreeNode16* m_08;
    FreeNode16* m_0c;
    void InitFreeList(unsigned int count, FreeNode16* base);
};
struct FUN_008ca940_node
{
    int m_00;
    int m_04;
    int m_08;
    FUN_008ca940_node* m_0c;
};
void __cdecl ProgramFlow();
class FUN_008ca940_cls
{
  public:
    int m_00;
    long m_04;
    FUN_008ca940_node* m_08;

    bool PopNode(FUN_008ca940_node** out);
};
class FUN_008cab00_cls
{
  public:
    void DeleteCriticalSection_Thunk();
    void ForwardCall_008cab00();
};
extern int DAT_01085c90;
struct Renderer
{
    void NiAVObject_SetTranslate(void*);
    void SetRotate_0043fa80(void*);
    double GetFloatAt64();
    void NiAVObject_SetScale(float);
};
void __cdecl bhkWorld_RemoveObjects(Renderer*, int, int);
void __cdecl TESHavokUtilities_RemoveHavokFromSceneGraph(Renderer*);
void __cdecl Warning_005b5e40(const void*);
struct GameContext
{
    void RemoveObject_00b5b1c0(Renderer*);
    void FUN_00b5eeb0(Renderer*);
};
GameContext* __cdecl FUN_00450b80(int);
struct Player;
struct Callback
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void v55() = 0;
    virtual void v56() = 0;
    virtual void v57() = 0;
    virtual void v58() = 0;
    virtual void v59() = 0;
    virtual void v60() = 0;
    virtual void v61() = 0;
    virtual void v62() = 0;
    virtual void v63() = 0;
    virtual void v64() = 0;
    virtual void v65() = 0;
    virtual void v66() = 0;
    virtual void v67() = 0;
    virtual void v68() = 0;
    virtual void v69() = 0;
    virtual void v70() = 0;
    virtual void v71() = 0;
    virtual void v72() = 0;
    virtual void v73() = 0;
    virtual void v74() = 0;
    virtual void v75() = 0;
    virtual void v76() = 0;
    virtual void v77() = 0;
    virtual void v78() = 0;
    virtual void v79() = 0;
    virtual void v80() = 0;
    virtual void v81() = 0;
    virtual void v82() = 0;
    virtual void v83() = 0;
    virtual void v84() = 0;
    virtual void v85() = 0;
    virtual void v86() = 0;
    virtual void v87() = 0;
    virtual void v88() = 0;
    virtual void v89() = 0;
    virtual void v90() = 0;
    virtual void v91() = 0;
    virtual void v92() = 0;
    virtual void v93() = 0;
    virtual void v94() = 0;
    virtual void v95() = 0;
    virtual void v96() = 0;
    virtual void v97() = 0;
    virtual void v98() = 0;
    virtual void v99() = 0;
    virtual void v100() = 0;
    virtual void v101() = 0;
    virtual void v102() = 0;
    virtual void v103() = 0;
    virtual void v104() = 0;
    virtual void v105() = 0;
    virtual void v106() = 0;
    virtual void v107() = 0;
    virtual void v108() = 0;
    virtual void v109() = 0;
    virtual void v110() = 0;
    virtual void v111() = 0;
    virtual void v112() = 0;
    virtual void v113() = 0;
    virtual void v114() = 0;
    virtual void v115() = 0;
    virtual void v116() = 0;
    virtual void v117() = 0;
    virtual void v118() = 0;
    virtual void v119() = 0;
    virtual void v120() = 0;
    virtual void v121() = 0;
    virtual void v122() = 0;
    virtual void v123() = 0;
    virtual void v124() = 0;
    virtual void v125() = 0;
    virtual void v126() = 0;
    virtual void v127() = 0;
    virtual void v128() = 0;
    virtual void v129() = 0;
    virtual void v130() = 0;
    virtual void v131() = 0;
    virtual void v132() = 0;
    virtual void v133() = 0;
    virtual void v134() = 0;
    virtual void v135() = 0;
    virtual void v136() = 0;
    virtual void v137() = 0;
    virtual void v138() = 0;
    virtual void v139() = 0;
    virtual void v140() = 0;
    virtual void v141() = 0;
    virtual void v142() = 0;
    virtual void v143() = 0;
    virtual void v144() = 0;
    virtual void v145() = 0;
    virtual void v146() = 0;
    virtual void v147() = 0;
    virtual void v148() = 0;
    virtual void v149() = 0;
    virtual void v150() = 0;
    virtual void v151() = 0;
    virtual void v152() = 0;
    virtual void v153() = 0;
    virtual void v154() = 0;
    virtual void v155() = 0;
    virtual void v156() = 0;
    virtual void v157() = 0;
    virtual void v158() = 0;
    virtual void v159() = 0;
    virtual void v160() = 0;
    virtual void v161() = 0;
    virtual void v162() = 0;
    virtual void v163() = 0;
    virtual void v164() = 0;
    virtual void v165() = 0;
    virtual void v166() = 0;
    virtual void v167() = 0;
    virtual void v168() = 0;
    virtual void v169() = 0;
    virtual void v170() = 0;
    virtual void v171() = 0;
    virtual void v172() = 0;
    virtual void v173() = 0;
    virtual void v174() = 0;
    virtual void v175() = 0;
    virtual void v176() = 0;
    virtual void v177() = 0;
    virtual void v178() = 0;
    virtual void v179() = 0;
    virtual void v180() = 0;
    virtual void v181() = 0;
    virtual void v182() = 0;
    virtual void v183() = 0;
    virtual void v184() = 0;
    virtual void v185() = 0;
    virtual void v186() = 0;
    virtual void v187() = 0;
    virtual void v188() = 0;
    virtual void v189() = 0;
    virtual void v190() = 0;
    virtual void v191() = 0;
    virtual void v192() = 0;
    virtual void v193() = 0;
    virtual void v194() = 0;
    virtual void v195() = 0;
    virtual void v196() = 0;
    virtual void v197() = 0;
    virtual void v198() = 0;
    virtual void v199() = 0;
    virtual void v200() = 0;
    virtual void v201() = 0;
    virtual void v202() = 0;
    virtual void v203() = 0;
    virtual void v204() = 0;
    virtual void v205() = 0;
    virtual void v206() = 0;
    virtual void v207() = 0;
    virtual void v208() = 0;
    virtual void v209() = 0;
    virtual void v210() = 0;
    virtual void v211() = 0;
    virtual void v212() = 0;
    virtual void v213() = 0;
    virtual void v214() = 0;
    virtual void v215() = 0;
    virtual void v216() = 0;
    virtual void v217() = 0;
    virtual void v218() = 0;
    virtual void v219() = 0;
    virtual void v220() = 0;
    virtual void v221() = 0;
    virtual void v222() = 0;
    virtual void v223() = 0;
    virtual void v224() = 0;
    virtual void v225() = 0;
    virtual void v226() = 0;
    virtual void v227() = 0;
    virtual void v228() = 0;
    virtual void v229() = 0;
    virtual void v230() = 0;
    virtual void v231() = 0;
    virtual void v232() = 0;
    virtual void v233() = 0;
    virtual void v234() = 0;
    virtual void v235() = 0;
    virtual void v236() = 0;
    virtual void v237() = 0;
    virtual void v238() = 0;
    virtual void v239() = 0;
    virtual void v240() = 0;
    virtual void v241() = 0;
    virtual void v242() = 0;
    virtual void v243() = 0;
    virtual void v244() = 0;
    virtual void v245() = 0;
    virtual void v246() = 0;
    virtual void v247() = 0;
    virtual void v248() = 0;
    virtual void v249() = 0;
    virtual void v250() = 0;
    virtual void v251() = 0;
    virtual void v252() = 0;
    virtual void v253() = 0;
    virtual void v254() = 0;
    virtual void v255() = 0;
    virtual void v256() = 0;
    virtual void v257() = 0;
    virtual void v258() = 0;
    virtual void v259() = 0;
    virtual void v260() = 0;
    virtual void v261() = 0;
    virtual void v262() = 0;
    virtual void v263() = 0;
    virtual void v264() = 0;
    virtual void v265() = 0;
    virtual void v266() = 0;
    virtual void v267() = 0;
    virtual void v268() = 0;
    virtual void v269() = 0;
    virtual void v270() = 0;
    virtual void v271() = 0;
    virtual void v272() = 0;
    virtual void v273() = 0;
    virtual void v274() = 0;
    virtual void v275() = 0;
    virtual void v276() = 0;
    virtual void v277() = 0;
    virtual void v278() = 0;
    virtual void v279() = 0;
    virtual void v280() = 0;
    virtual void v281() = 0;
    virtual void v282() = 0;
    virtual void v283() = 0;
    virtual void v284() = 0;
    virtual void v285() = 0;
    virtual void v286() = 0;
    virtual void v287() = 0;
    virtual void v288() = 0;
    virtual void v289() = 0;
    virtual void v290() = 0;
    virtual void v291() = 0;
    virtual void v292() = 0;
    virtual void v293() = 0;
    virtual void v294() = 0;
    virtual void v295() = 0;
    virtual void v296() = 0;
    virtual void v297() = 0;
    virtual void v298() = 0;
    virtual void v299() = 0;
    virtual void v300() = 0;
    virtual void v301() = 0;
    virtual void v302() = 0;
    virtual void v303() = 0;
    virtual void v304() = 0;
    virtual void v305() = 0;
    virtual void v306() = 0;
    virtual void v307() = 0;
    virtual void v308() = 0;
    virtual void v309() = 0;
    virtual void v310() = 0;
    virtual void v311() = 0;
    virtual void v312() = 0;
    virtual void v313() = 0;
    virtual void v314() = 0;
    virtual void v315() = 0;
    virtual void v316() = 0;
    virtual void v317() = 0;
    virtual void v318() = 0;
    virtual void v319() = 0;
    virtual void v320() = 0;
    virtual void v321() = 0;
    virtual void v322() = 0;
    virtual void v323() = 0;
    virtual void v324() = 0;
    virtual void v325() = 0;
    virtual void v326() = 0;
    virtual void v327() = 0;
    virtual void v328() = 0;
    virtual void v329() = 0;
    virtual void v330() = 0;
    virtual void v331() = 0;
    virtual void v332() = 0;
    virtual void v333() = 0;
    virtual void v334() = 0;
    virtual void v335() = 0;
    virtual void v336() = 0;
    virtual void v337() = 0;
    virtual void v338() = 0;
    virtual void v339() = 0;
    virtual void v340() = 0;
    virtual void v341() = 0;
    virtual void v342() = 0;
    virtual void v343() = 0;
    virtual void v344() = 0;
    virtual void v345() = 0;
    virtual void v346() = 0;
    virtual void v347() = 0;
    virtual void v348() = 0;
    virtual void v349() = 0;
    virtual void v350() = 0;
    virtual void v351() = 0;
    virtual void v352() = 0;
    virtual void v353() = 0;
    virtual void v354() = 0;
    virtual void v355() = 0;
    virtual void v356() = 0;
    virtual void v357() = 0;
    virtual void v358() = 0;
    virtual void v359() = 0;
    virtual void v360() = 0;
    virtual void v361() = 0;
    virtual void v362() = 0;
    virtual void v363() = 0;
    virtual void v364() = 0;
    virtual void v365() = 0;
    virtual void v366() = 0;
    virtual void v367() = 0;
    virtual void v368() = 0;
    virtual void v369() = 0;
    virtual void v370() = 0;
    virtual void v371() = 0;
    virtual void v372() = 0;
    virtual void v373() = 0;
    virtual void v374() = 0;
    virtual void v375() = 0;
    virtual void v376() = 0;
    virtual void v377() = 0;
    virtual void v378() = 0;
    virtual void v379() = 0;
    virtual void v380() = 0;
    virtual void v381() = 0;
    virtual void v382() = 0;
    virtual void v383() = 0;
    virtual void v384() = 0;
    virtual void v385() = 0;
    virtual void v386() = 0;
    virtual void v387() = 0;
    virtual void v388() = 0;
    virtual void v389() = 0;
    virtual void v390() = 0;
    virtual void v391() = 0;
    virtual void v392() = 0;
    virtual void v393() = 0;
    virtual void v394() = 0;
    virtual void v395() = 0;
    virtual void v396() = 0;
    virtual void v397() = 0;
    virtual void v398() = 0;
    virtual void v399() = 0;
    virtual void v400() = 0;
    virtual void v401() = 0;
    virtual void v402() = 0;
    virtual void v403() = 0;
    virtual void v404() = 0;
    virtual void v405() = 0;
    virtual void v406() = 0;
    virtual void v407() = 0;
    virtual void v408() = 0;
    virtual void v409() = 0;
    virtual void v410() = 0;
    virtual void v411() = 0;
    virtual void v412() = 0;
    virtual void v413() = 0;
    virtual void v414() = 0;
    virtual void v415() = 0;
    virtual void v416() = 0;
    virtual void v417() = 0;
    virtual void v418() = 0;
    virtual void v419() = 0;
    virtual void v420() = 0;
    virtual void v421() = 0;
    virtual void v422() = 0;
    virtual void v423() = 0;
    virtual void v424() = 0;
    virtual void execute(Player*) = 0;
};
struct ActiveItem
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void v55() = 0;
    virtual void v56() = 0;
    virtual void v57() = 0;
    virtual void v58() = 0;
    virtual void v59() = 0;
    virtual void v60() = 0;
    virtual void v61() = 0;
    virtual void v62() = 0;
    virtual void v63() = 0;
    virtual unsigned char isReady() = 0;
    Callback* FUN_008d8520();
};
struct Action
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void apply(Renderer*, int) = 0;
    float NiAVObject_GetWorldScale() const;
};
struct State
{
    unsigned int unknown00;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int unknown0c;
    unsigned int unknown10;
    unsigned int unknown14;
    unsigned int unknown18;
    unsigned int unknown1c;
    unsigned int unknown20;
    unsigned int unknown24;
    ActiveItem* active;
    Action* action;
    unsigned int configuration30;
};
struct Player
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void v55() = 0;
    virtual void v56() = 0;
    virtual void v57() = 0;
    virtual void v58() = 0;
    virtual void v59() = 0;
    virtual void v60() = 0;
    virtual void v61() = 0;
    virtual void v62() = 0;
    virtual void v63() = 0;
    virtual void v64() = 0;
    virtual void v65() = 0;
    virtual void v66() = 0;
    virtual void v67() = 0;
    virtual void v68() = 0;
    virtual void v69() = 0;
    virtual void v70() = 0;
    virtual void v71() = 0;
    virtual void v72() = 0;
    virtual void v73() = 0;
    virtual void v74() = 0;
    virtual void v75() = 0;
    virtual void v76() = 0;
    virtual void v77() = 0;
    virtual void v78() = 0;
    virtual void v79() = 0;
    virtual void v80() = 0;
    virtual void v81() = 0;
    virtual void v82() = 0;
    virtual void v83() = 0;
    virtual void v84() = 0;
    virtual void v85() = 0;
    virtual void v86() = 0;
    virtual void v87() = 0;
    virtual void v88() = 0;
    virtual void v89() = 0;
    virtual void v90() = 0;
    virtual void v91() = 0;
    virtual void v92() = 0;
    virtual void v93() = 0;
    virtual void v94() = 0;
    virtual void v95() = 0;
    virtual void v96() = 0;
    virtual void v97() = 0;
    virtual void v98() = 0;
    virtual void v99() = 0;
    virtual void v100() = 0;
    virtual void v101() = 0;
    virtual void v102() = 0;
    virtual void v103() = 0;
    virtual void v104() = 0;
    virtual void v105() = 0;
    virtual void v106() = 0;
    virtual void v107() = 0;
    virtual void v108() = 0;
    virtual void v109() = 0;
    virtual void v110() = 0;
    virtual void v111() = 0;
    virtual void v112() = 0;
    virtual void v113() = 0;
    virtual void v114() = 0;
    virtual void v115() = 0;
    virtual Renderer* currentRenderer() = 0;
    virtual void v117() = 0;
    virtual void v118() = 0;
    virtual void v119() = 0;
    virtual void v120() = 0;
    virtual void v121() = 0;
    virtual void v122() = 0;
    virtual void v123() = 0;
    virtual void v124() = 0;
    virtual void v125() = 0;
    virtual void v126() = 0;
    virtual void v127() = 0;
    virtual void v128() = 0;
    virtual void v129() = 0;
    virtual void v130() = 0;
    virtual void v131() = 0;
    virtual void v132() = 0;
    virtual void v133() = 0;
    virtual void v134() = 0;
    virtual void v135() = 0;
    virtual void v136() = 0;
    virtual void v137() = 0;
    virtual void v138() = 0;
    virtual void v139() = 0;
    virtual void v140() = 0;
    virtual void v141() = 0;
    virtual void v142() = 0;
    virtual void v143() = 0;
    virtual void v144() = 0;
    virtual void v145() = 0;
    virtual void v146() = 0;
    virtual void v147() = 0;
    virtual void v148() = 0;
    virtual void v149() = 0;
    virtual void v150() = 0;
    virtual void v151() = 0;
    virtual void v152() = 0;
    virtual void v153() = 0;
    virtual void v154() = 0;
    virtual void v155() = 0;
    virtual void v156() = 0;
    virtual void v157() = 0;
    virtual void v158() = 0;
    virtual void v159() = 0;
    virtual void v160() = 0;
    virtual void v161() = 0;
    virtual void v162() = 0;
    virtual void v163() = 0;
    virtual void v164() = 0;
    virtual void v165() = 0;
    virtual void v166() = 0;
    virtual void v167() = 0;
    virtual void resetRenderer() = 0;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int unknown0c;
    unsigned int unknown10;
    unsigned int unknown14;
    unsigned int unknown18;
    unsigned int unknown1c;
    unsigned int unknown20;
    unsigned int unknown24;
    unsigned int unknown28;
    unsigned int unknown2c;
    unsigned int unknown30;
    unsigned int unknown34;
    unsigned int unknown38;
    unsigned int unknown3c;
    unsigned int unknown40;
    unsigned int unknown44;
    unsigned int unknown48;
    unsigned int unknown4c;
    unsigned int unknown50;
    unsigned int unknown54;
    unsigned int unknown58;
    unsigned int unknown5c;
    unsigned int unknown60;
    unsigned int unknown64;
    unsigned int unknown68;
    unsigned int unknown6c;
    unsigned int unknown70;
    unsigned int unknown74;
    unsigned int unknown78;
    unsigned int unknown7c;
    unsigned int unknown80;
    unsigned int unknown84;
    State* state;
    unsigned char RenderActiveAction(int unused);
};
struct EventTarget;
struct ResourceInfo
{
    EventTarget* bhkNiCollisionObject_GetWorldObject();
};
struct EventProperty
{
    unsigned char bhkShape_QMaterial();
};
struct EventTarget
{
    EventProperty* bhkWorldObject_GetShape();
};
ResourceInfo* __cdecl FindFirstCollisionObject(int source);
extern float DAT_01016248;
struct EventRecord
{
    int param1;
    int param2;
    int param3;
    float weight;
    float defaultWeight;
    unsigned char resourceType;
    unsigned char enabled;
    unsigned short attributes;
    void* eventPointer;
    EventTarget* target;
    int cursorOffset;
    void BGSPrimitive_EvaluateValue_006240d0();
};
void __cdecl ImpactMixer_PlayCollisionSound(EventRecord*);
struct Object
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
    virtual int GetSource();
    void ArrowProjectile_PlayArrowCollisionSound(float weight, int a, int b, int c, int offset, unsigned char enabled);
};
struct FUN_00620b80_shell
{
    unsigned int GetReferenceFlags();
};
struct FUN_005609f0_shell
{
    bool FUN_005609f0();
};
struct FUN_00a29680_Obj
{
    void Object_DoNothing();
};
struct Holder_cffa0
{
    bool bhkWorldObject_IsAddedToWorld();
};
struct Target_cls
{
    int FUN_008ce390();
    unsigned char FUN_00440d80();
};
struct Arg_cls
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int TESDataHandler_GetWorldSpaceList();
    int FUN_006815c0();
};
void bhkCharacterListenerArrow_ProcessCollision(Target_cls* p, int a, int b, int c);
struct FUN_008d14e0_cls
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004C;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005C;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006C;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007C;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008C;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009C;
    int unk00A0;
    int unk00A4;
    int unk00A8;
    int unk00AC;
    int unk00B0;
    int unk00B4;
    int unk00B8;
    int unk00BC;
    int unk00C0;
    int unk00C4;
    int unk00C8;
    int unk00CC;
    int unk00D0;
    int unk00D4;
    int unk00D8;
    int unk00DC;
    int unk00E0;
    int unk00E4;
    int unk00E8;
    int unk00EC;
    int unk00F0;
    int unk00F4;
    int unk00F8;
    int unk00FC;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010C;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011C;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012C;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013C;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014C;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015C;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016C;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017C;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018C;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019C;
    int unk01A0;
    int unk01A4;
    int unk01A8;
    int unk01AC;
    int unk01B0;
    int unk01B4;
    int unk01B8;
    int unk01BC;
    int unk01C0;
    int unk01C4;
    int unk01C8;
    int unk01CC;
    int unk01D0;
    int unk01D4;
    int unk01D8;
    int unk01DC;
    int unk01E0;
    int unk01E4;
    int unk01E8;
    int unk01EC;
    int unk01F0;
    int unk01F4;
    int unk01F8;
    int unk01FC;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020C;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021C;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022C;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023C;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024C;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025C;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026C;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027C;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028C;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029C;
    int unk02A0;
    int unk02A4;
    int unk02A8;
    int unk02AC;
    int unk02B0;
    int unk02B4;
    int unk02B8;
    int unk02BC;
    int unk02C0;
    int unk02C4;
    int unk02C8;
    int unk02CC;
    int unk02D0;
    int unk02D4;
    int unk02D8;
    int unk02DC;
    int unk02E0;
    int unk02E4;
    int unk02E8;
    int unk02EC;
    int unk02F0;
    int unk02F4;
    int unk02F8;
    int unk02FC;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030C;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031C;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032C;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033C;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034C;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035C;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036C;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037C;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038C;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039C;
    int unk03A0;
    int unk03A4;
    int unk03A8;
    int unk03AC;
    int unk03B0;
    int unk03B4;
    int unk03B8;
    int unk03BC;
    int unk03C0;
    int unk03C4;
    int unk03C8;
    int unk03CC;
    int unk03D0;
    int unk03D4;
    int unk03D8;
    int unk03DC;
    int unk03E0;
    int unk03E4;
    int unk03E8;
    int unk03EC;
    int unk03F0;
    int unk03F4;
    int unk03F8;
    int unk03FC;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040C;
    int unk0410;
    int unk0414;
    int unk0418;
    int unk041C;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042C;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043C;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044C;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045C;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046C;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047C;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048C;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049C;
    int unk04A0;
    int unk04A4;
    int unk04A8;
    int unk04AC;
    int unk04B0;
    int unk04B4;
    int unk04B8;
    int unk04BC;
    int unk04C0;
    int unk04C4;
    int unk04C8;
    int unk04CC;
    int unk04D0;
    int unk04D4;
    int unk04D8;
    int unk04DC;
    int unk04E0;
    int unk04E4;
    int unk04E8;
    int unk04EC;
    int unk04F0;
    int unk04F4;
    int unk04F8;
    int unk04FC;
    int unk0500;
    int unk0504;
    int unk0508;
    int unk050C;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051C;
    int unk0520;
    int unk0524;
    int unk0528;
    int unk052C;
    int unk0530;
    int unk0534;
    int unk0538;
    int unk053C;
    int unk0540;
    int unk0544;
    int unk0548;
    int unk054C;
    int unk0550;
    int unk0554;
    int unk0558;
    int unk055C;
    int unk0560;
    int unk0564;
    int unk0568;
    int unk056C;
    int unk0570;
    int unk0574;
    int unk0578;
    int unk057C;
    int unk0580;
    int unk0584;
    int unk0588;
    int unk058C;
    int unk0590;
    int unk0594;
    int unk0598;
    int unk059C;
    int unk05A0;
    int unk05A4;
    int unk05A8;
    int unk05AC;
    int unk05B0;
    int unk05B4;
    int unk05B8;
    int unk05BC;
    int unk05C0;
    int unk05C4;
    int unk05C8;
    int unk05CC;
    int unk05D0;
    int unk05D4;
    int unk05D8;
    int unk05DC;
    int unk05E0;
    int unk05E4;
    int unk05E8;
    int unk05EC;
    int unk05F0;
    int unk05F4;
    int unk05F8;
    int unk05FC;
    int unk0600;
    int unk0604;
    int unk0608;
    int unk060C;
    int unk0610;
    int unk0614;
    int unk0618;
    int unk061C;
    int unk0620;
    int unk0624;
    int unk0628;
    int unk062C;
    int unk0630;
    int unk0634;
    int unk0638;
    int unk063C;
    int unk0640;
    int unk0644;
    int unk0648;
    int unk064C;
    Target_cls* m_650;
    void bhkCharacterListenerArrow_contactPointAddedCallback(Arg_cls* a1);
};
extern float DAT_011dfed4;
float __cdecl GetCameraShakeMult();
extern float DAT_011dfed8;
float __cdecl GetCameraShakeCurrentTime();
struct AnimTimeSource
{
    float GetSourceTimeStub();
};
extern NiMatrix3 DAT_011a9448;
int ComputeRelativeRotation(int index, float time, NiMatrix3* out);
struct Small_b7397
{
    int unk00;
    void Reset(int v);
    ~Small_b7397();
};
struct Sub08_b7397
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    ~Sub08_b7397();
};
class FUN_008d6af0_cls
{
  public:
    int unk04;
    Sub08_b7397 m_08;
    Small_b7397 m_98;
    Small_b7397 m_9c;
    Small_b7397 m_a0;
    virtual ~FUN_008d6af0_cls();
};
extern const float DAT_010181e8;
struct B8DF9B0Queue
{
    void* m_pHead;

    ~B8DF9B0Queue();
};
class B8DF9B0Base
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;

    ~B8DF9B0Base();
};
class FUN_008df9b0 : public B8DF9B0Base
{
  public:
    B8DF9B0Queue m_kQueue;

    ~FUN_008df9b0();
};
// Forward a reference's base form and its owner value (if it has extra data) to this handler.
class C1CD0Owner
{
  public:
    int* GetValuePtr();
};
class C1CD0Ref
{
  public:
    C1CD0Owner* GetOwner();
    void* GetBaseForm();
};
class C1CD0Handler
{
  public:
    void Handle(void* pvBaseForm, int iValue);
    void HandleRef(C1CD0Ref* pkRef);
};
// Secondary-interface override: return the current process's value, or null when the actor has no process.
void FNV_Warning(const char* fmt, ...);
struct ArrowCollision
{
    ArrowWorldObj* bhkNiCollisionObject_GetWorldObject();
};
ArrowCollision* __cdecl FindFirstCollisionObject(ArrowRenderer* source);
struct ArrowImpact
{
    int type;
};
struct RotationMatrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    void FUN_006815c0();
    void FUN_004b46a0(RotationMatrix&);
    NiPoint3 FUN_004b4500(const NiPoint3&);
};
struct SceneNode
{
    void NiAVObject_SetTranslate(const NiPoint3&);
    void NiAVObject_Update(NiUpdateData&);
    RotationMatrix& NiAVObject_GetWorldRotate();
};
struct LoadingState
{
    bool FUN_0047c850();
};
extern LoadingState* DAT_011de45c;
struct FloatSetting
{
    float* Float();
};
extern FloatSetting DAT_011ce1dc, DAT_011cedac;
struct AnimationOutput
{
    void bhkWorldObject_SetCollisionFilter(unsigned int);
    void bhkRigidBody_SetLinearVelocity(const NiPoint3&);
    void bhkRigidBody_SetAngularVelocity(const NiPoint3&);
};
struct UpdateToken
{
    unsigned int value;
    UpdateToken(int, unsigned int, int);
};
struct ResourceUpdate
{
    void bhkNiCollisionObject_SetNotify(bool);
};
ResourceUpdate* FindFirstCollisionObject(SceneNode*);
void bhkWorld_SetMotion(SceneNode*, int, bool, bool, bool);
NiPoint3 FUN_004a3760(float, const NiPoint3&);
void NiPoint3_UnitizeVector(NiPoint3&);
double NiAbs_00408820(float);
float SignOfFloat(float);
struct MovementState
{
    unsigned int unknown00;
    NiPoint3 position;
    NiPoint3 direction;
};
struct MovementController
{
    virtual void virtual0() = 0;
    virtual void virtual1() = 0;
    virtual void virtual2() = 0;
    virtual void virtual3() = 0;
    virtual void virtual4() = 0;
    virtual void virtual5() = 0;
    virtual void virtual6() = 0;
    virtual void virtual7() = 0;
    virtual void virtual8() = 0;
    virtual void virtual9() = 0;
    virtual void virtual10() = 0;
    virtual void virtual11() = 0;
    virtual void virtual12() = 0;
    virtual void virtual13() = 0;
    virtual void virtual14() = 0;
    virtual void virtual15() = 0;
    virtual void virtual16() = 0;
    virtual void virtual17() = 0;
    virtual void virtual18() = 0;
    virtual void virtual19() = 0;
    virtual void virtual20() = 0;
    virtual void virtual21() = 0;
    virtual void virtual22() = 0;
    virtual void virtual23() = 0;
    virtual void virtual24() = 0;
    virtual void virtual25() = 0;
    virtual void virtual26() = 0;
    virtual void virtual27() = 0;
    virtual void virtual28() = 0;
    virtual void virtual29() = 0;
    virtual void virtual30() = 0;
    virtual void virtual31() = 0;
    virtual void virtual32() = 0;
    virtual void virtual33() = 0;
    virtual void virtual34() = 0;
    virtual void virtual35() = 0;
    virtual void virtual36() = 0;
    virtual void virtual37() = 0;
    virtual void virtual38() = 0;
    virtual void virtual39() = 0;
    virtual void virtual40() = 0;
    virtual void virtual41() = 0;
    virtual void virtual42() = 0;
    virtual void virtual43() = 0;
    virtual void virtual44() = 0;
    virtual void virtual45() = 0;
    virtual void virtual46() = 0;
    virtual void virtual47() = 0;
    virtual void virtual48() = 0;
    virtual void virtual49() = 0;
    virtual void virtual50() = 0;
    virtual void virtual51() = 0;
    virtual void virtual52() = 0;
    virtual void virtual53() = 0;
    virtual void virtual54() = 0;
    virtual void virtual55() = 0;
    virtual void virtual56() = 0;
    virtual void virtual57() = 0;
    virtual void virtual58() = 0;
    virtual void virtual59() = 0;
    virtual void virtual60() = 0;
    virtual void virtual61() = 0;
    virtual void virtual62() = 0;
    virtual void virtual63() = 0;
    virtual void virtual64() = 0;
    virtual void virtual65() = 0;
    virtual void virtual66() = 0;
    virtual void virtual67() = 0;
    virtual void virtual68() = 0;
    virtual void virtual69() = 0;
    virtual void virtual70() = 0;
    virtual void virtual71() = 0;
    virtual void virtual72() = 0;
    virtual void virtual73() = 0;
    virtual void virtual74() = 0;
    virtual void virtual75() = 0;
    virtual void virtual76() = 0;
    virtual void virtual77() = 0;
    virtual void virtual78() = 0;
    virtual void virtual79() = 0;
    virtual void virtual80() = 0;
    virtual void virtual81() = 0;
    virtual void virtual82() = 0;
    virtual void virtual83() = 0;
    virtual void virtual84() = 0;
    virtual void virtual85() = 0;
    virtual void virtual86() = 0;
    virtual void virtual87() = 0;
    virtual void virtual88() = 0;
    virtual void virtual89() = 0;
    virtual void virtual90() = 0;
    virtual void virtual91() = 0;
    virtual void virtual92() = 0;
    virtual void virtual93() = 0;
    virtual void virtual94() = 0;
    virtual void virtual95() = 0;
    virtual void virtual96() = 0;
    virtual void virtual97() = 0;
    virtual void virtual98() = 0;
    virtual void virtual99() = 0;
    virtual void virtual100() = 0;
    virtual void virtual101() = 0;
    virtual void virtual102() = 0;
    virtual void virtual103() = 0;
    virtual void virtual104() = 0;
    virtual void virtual105() = 0;
    virtual void virtual106() = 0;
    virtual void virtual107() = 0;
    virtual void virtual108() = 0;
    virtual void virtual109() = 0;
    virtual void virtual110() = 0;
    virtual void virtual111() = 0;
    virtual void virtual112() = 0;
    virtual void virtual113() = 0;
    virtual void virtual114() = 0;
    virtual void virtual115() = 0;
    virtual SceneNode* getNode() = 0;
    virtual void virtual117() = 0;
    virtual void virtual118() = 0;
    virtual void virtual119() = 0;
    virtual void virtual120() = 0;
    virtual void virtual121() = 0;
    virtual void virtual122() = 0;
    virtual void virtual123() = 0;
    virtual void virtual124() = 0;
    virtual void virtual125() = 0;
    virtual void virtual126() = 0;
    virtual void virtual127() = 0;
    virtual void virtual128() = 0;
    virtual void virtual129() = 0;
    virtual void virtual130() = 0;
    virtual void virtual131() = 0;
    virtual void virtual132() = 0;
    virtual void virtual133() = 0;
    virtual void virtual134() = 0;
    virtual void virtual135() = 0;
    virtual void virtual136() = 0;
    virtual void virtual137() = 0;
    virtual void virtual138() = 0;
    virtual void virtual139() = 0;
    virtual void virtual140() = 0;
    virtual void virtual141() = 0;
    virtual void virtual142() = 0;
    virtual void virtual143() = 0;
    virtual void virtual144() = 0;
    virtual void virtual145() = 0;
    virtual void virtual146() = 0;
    virtual void virtual147() = 0;
    virtual void virtual148() = 0;
    virtual void virtual149() = 0;
    virtual void virtual150() = 0;
    virtual void virtual151() = 0;
    virtual void virtual152() = 0;
    virtual void virtual153() = 0;
    virtual void virtual154() = 0;
    virtual void virtual155() = 0;
    virtual void virtual156() = 0;
    virtual void virtual157() = 0;
    virtual void virtual158() = 0;
    virtual void virtual159() = 0;
    virtual void virtual160() = 0;
    virtual void virtual161() = 0;
    virtual void virtual162() = 0;
    virtual void virtual163() = 0;
    virtual void virtual164() = 0;
    virtual void virtual165() = 0;
    virtual void virtual166() = 0;
    virtual void virtual167() = 0;
    virtual void resetNode() = 0;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int unknown0c;
    unsigned int unknown10;
    unsigned int unknown14;
    unsigned int unknown18;
    unsigned int unknown1c;
    unsigned int unknown20;
    unsigned int unknown24;
    unsigned int unknown28;
    unsigned int unknown2c;
    unsigned int unknown30;
    unsigned int unknown34;
    unsigned int unknown38;
    unsigned int unknown3c;
    unsigned int unknown40;
    unsigned int unknown44;
    unsigned int unknown48;
    unsigned int unknown4c;
    unsigned int unknown50;
    unsigned int unknown54;
    unsigned int unknown58;
    unsigned int unknown5c;
    unsigned int unknown60;
    unsigned int unknown64;
    unsigned int unknown68;
    unsigned int unknown6c;
    unsigned int unknown70;
    unsigned int unknown74;
    unsigned int unknown78;
    unsigned int unknown7c;
    unsigned int unknown80;
    unsigned int unknown84;
    MovementState* state;
    unsigned int unknown8c;
    unsigned int unknown90;
    unsigned int unknown94;
    float speed;
    unsigned int unknown9c;
    unsigned int unknowna0;
    unsigned int unknowna4;
    unsigned int unknowna8;
    unsigned int unknownac;
    unsigned int unknownb0;
    NiPoint3 velocity;
    bool UpdateAnimation(AnimationOutput* output);
};
struct SceneArg
{
    void* GetData();
};
struct SceneHolder
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    void SetArg(SceneArg* arg);
    void SetData(void* data);
};
struct FUN_008d6bb0_owner
{
    int unk00;
    int unk04;
    SceneHolder holder;
    NiPointer<BSMultiBoundNode> m_pController;
    NiPointer<BSMultiBound> pMultiBound;
    NiPointer<BSMultiBoundShape> pShape;
    void CreateMultiBoundNode(SceneArg* arg);
};

struct LiveCallback
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void v55() = 0;
    virtual void v56() = 0;
    virtual void v57() = 0;
    virtual void v58() = 0;
    virtual void v59() = 0;
    virtual void v60() = 0;
    virtual void v61() = 0;
    virtual void v62() = 0;
    virtual void v63() = 0;
    virtual void v64() = 0;
    virtual void v65() = 0;
    virtual void v66() = 0;
    virtual void v67() = 0;
    virtual void v68() = 0;
    virtual void v69() = 0;
    virtual void v70() = 0;
    virtual void v71() = 0;
    virtual void v72() = 0;
    virtual void v73() = 0;
    virtual void v74() = 0;
    virtual void v75() = 0;
    virtual void v76() = 0;
    virtual void v77() = 0;
    virtual void v78() = 0;
    virtual void v79() = 0;
    virtual void v80() = 0;
    virtual void v81() = 0;
    virtual void v82() = 0;
    virtual void v83() = 0;
    virtual void v84() = 0;
    virtual void v85() = 0;
    virtual void v86() = 0;
    virtual void v87() = 0;
    virtual void v88() = 0;
    virtual void v89() = 0;
    virtual void v90() = 0;
    virtual void v91() = 0;
    virtual void v92() = 0;
    virtual void v93() = 0;
    virtual void v94() = 0;
    virtual void v95() = 0;
    virtual void v96() = 0;
    virtual void v97() = 0;
    virtual void v98() = 0;
    virtual void v99() = 0;
    virtual void v100() = 0;
    virtual void v101() = 0;
    virtual void v102() = 0;
    virtual void v103() = 0;
    virtual void v104() = 0;
    virtual void v105() = 0;
    virtual void v106() = 0;
    virtual void v107() = 0;
    virtual void v108() = 0;
    virtual void v109() = 0;
    virtual void v110() = 0;
    virtual void v111() = 0;
    virtual void v112() = 0;
    virtual void v113() = 0;
    virtual void v114() = 0;
    virtual void v115() = 0;
    virtual void v116() = 0;
    virtual void v117() = 0;
    virtual void v118() = 0;
    virtual void v119() = 0;
    virtual void v120() = 0;
    virtual void v121() = 0;
    virtual void v122() = 0;
    virtual void v123() = 0;
    virtual void v124() = 0;
    virtual void v125() = 0;
    virtual void v126() = 0;
    virtual void v127() = 0;
    virtual void v128() = 0;
    virtual void v129() = 0;
    virtual void v130() = 0;
    virtual void v131() = 0;
    virtual void v132() = 0;
    virtual int v133() = 0;
    virtual void v134() = 0;
    virtual void v135() = 0;
    virtual void v136() = 0;
    virtual void v137() = 0;
    virtual void v138() = 0;
    virtual unsigned char v139(int flag) = 0;
    virtual void v140() = 0;
    virtual void v141() = 0;
    virtual void v142() = 0;
    virtual void v143() = 0;
    virtual void v144() = 0;
    virtual void v145() = 0;
    virtual void v146() = 0;
    virtual void v147() = 0;
    virtual void v148() = 0;
    virtual void v149() = 0;
    virtual void v150() = 0;
    virtual void v151() = 0;
    virtual void v152() = 0;
    virtual void v153() = 0;
    virtual void v154() = 0;
    virtual void v155() = 0;
    virtual void v156() = 0;
    virtual void v157() = 0;
    virtual void v158() = 0;
    virtual void v159() = 0;
    virtual void v160() = 0;
    virtual void v161() = 0;
    virtual void v162() = 0;
    virtual void v163() = 0;
    virtual void v164() = 0;
    virtual void v165() = 0;
    virtual void v166() = 0;
    virtual void v167() = 0;
    virtual void v168() = 0;
    virtual void v169() = 0;
    virtual void v170() = 0;
    virtual void v171() = 0;
    virtual void v172() = 0;
    virtual void v173() = 0;
    virtual void v174() = 0;
    virtual void v175() = 0;
    virtual void v176() = 0;
    virtual void v177() = 0;
    virtual void v178() = 0;
    virtual void v179() = 0;
    virtual void v180() = 0;
    virtual void v181() = 0;
    virtual void v182() = 0;
    virtual void v183() = 0;
    virtual void v184() = 0;
    virtual void v185() = 0;
    virtual void v186() = 0;
    virtual void v187() = 0;
    virtual void v188() = 0;
    virtual void v189() = 0;
    virtual void v190() = 0;
    virtual void v191() = 0;
    virtual void v192() = 0;
    virtual void v193() = 0;
    virtual void v194() = 0;
    virtual void v195() = 0;
    virtual void v196() = 0;
    virtual void v197() = 0;
    virtual void v198() = 0;
    virtual void v199() = 0;
    virtual void v200() = 0;
    virtual void v201() = 0;
    virtual void v202() = 0;
    virtual void v203() = 0;
    virtual void v204() = 0;
    virtual void v205() = 0;
    virtual void v206() = 0;
    virtual void v207() = 0;
    virtual void v208() = 0;
    virtual void v209() = 0;
    virtual void v210() = 0;
    virtual void v211() = 0;
    virtual void v212() = 0;
    virtual void v213() = 0;
    virtual void v214() = 0;
    virtual void v215() = 0;
    virtual void v216() = 0;
    virtual void v217() = 0;
    virtual void v218() = 0;
    virtual void v219() = 0;
    virtual void v220() = 0;
    virtual void v221() = 0;
    virtual void v222() = 0;
    virtual void v223() = 0;
    virtual void v224() = 0;
    virtual void v225() = 0;
    virtual void v226() = 0;
    virtual void v227() = 0;
    virtual void v228() = 0;
    virtual void v229() = 0;
    virtual void v230() = 0;
    virtual void v231() = 0;
    virtual void v232() = 0;
    virtual void v233() = 0;
    virtual void v234() = 0;
    virtual void v235() = 0;
    virtual void v236() = 0;
    virtual void v237() = 0;
    virtual void v238() = 0;
    virtual void v239() = 0;
    virtual void v240() = 0;
    virtual void v241() = 0;
    virtual void v242() = 0;
    virtual void v243() = 0;
    virtual void v244() = 0;
    virtual void v245() = 0;
    virtual void v246() = 0;
    virtual void v247() = 0;
    virtual void v248() = 0;
    virtual void v249() = 0;
    virtual void v250() = 0;
    virtual void v251() = 0;
    virtual void v252() = 0;
    virtual void v253() = 0;
    virtual void v254() = 0;
    virtual void v255() = 0;
    virtual void v256() = 0;
    virtual void v257() = 0;
    virtual void v258() = 0;
    virtual int v259() = 0;
    LiveCallback* __thiscall FUN_008d8520();
    unsigned char __thiscall GetGhost_008ace90();
};
struct SourceData
{
    int __thiscall hkpCollidable_getCollisionFilterInfo();
};
struct StateHandle
{
    int value;
    void __thiscall FUN_008c71b0(int);
    int __thiscall CFilter_GetGroup();
};
struct ArgumentData
{
    int unk00;
    int unk04;
    int unk08;
    void __thiscall FUN_006815c0();
};
struct TargetOwner
{
    void __thiscall ArrowProjectile_CollideTerrain(ArgumentData*, ArgumentData*);
    void __thiscall ArrowProjectile_CollideActor(ArgumentData*, ArgumentData*, LiveCallback*);
    void __thiscall FUN_008cc730(ArgumentData*, ArgumentData*, void*, int);
};
struct CurrentState
{
    void* __thiscall PlayerCharacter_GetGrabObject();
};
extern CurrentState* DAT_011dea3c;
extern int DAT_011841cc;
extern int DAT_011846d4;
extern LiveCallback* __fastcall FUN_008d8520(LiveCallback*);
extern void* __cdecl GetReferenceFromObject(SourceData*);
extern LiveCallback* __cdecl FUN_00ec43fb(void*, int, const void*, const void*, int);
extern int __cdecl hkpGetPhantom(SourceData*);
extern int __cdecl hkpGetRigidBody(SourceData*);
extern int __cdecl bhkEntity_Getbhk(int);
extern unsigned int __cdecl GetCachedValue();
extern void __cdecl FUN_00458620(ArgumentData*, int);
extern void __cdecl HK2NINS(ArgumentData*, int);

// @fnv 0x008d12e0
// src: COMMUNITY 0x008d12e0
void __cdecl bhkCharacterListenerArrow_ProcessCollision(TargetOwner* target, SourceData* source, int arg0, int arg1)
{
    void* owner = GetReferenceFromObject(source);
    LiveCallback* active = FUN_00ec43fb(owner, 0, &DAT_011841cc, &DAT_011846d4, 0);
    int action = hkpGetPhantom(source);
    if (action)
    {
        if (!active)
        {
            return;
        }
        else
        {
            if (active->v139(0))
            {
                return;
            }
            else
            {
                if (FUN_008d8520(active) && FUN_008d8520(active)->v259() && FUN_008d8520(active)->v259() != 6)
                {
                    return;
                }
                else
                {
                    if (active->v133() == 4 || active->v133() == 9)
                        return;
                }
            }
        }
    }
    StateHandle state;
    state.FUN_008c71b0(source->hkpCollidable_getCollisionFilterInfo());
    if (state.CFilter_GetGroup() == GetCachedValue())
        return;
    if (owner && owner == DAT_011dea3c->PlayerCharacter_GetGrabObject())
        return;
    ArgumentData first;
    first.FUN_006815c0();
    FUN_00458620(&first, arg0);
    ArgumentData argumentBundle;
    argumentBundle.FUN_006815c0();
    HK2NINS(&argumentBundle, arg1);
    if (state.CFilter_GetGroup() == 1)
    {
        target->ArrowProjectile_CollideTerrain(&first, &argumentBundle);
        return;
    }
    if (owner)
    {
        if (active && !active->GetGhost_008ace90())
        {
            target->ArrowProjectile_CollideActor(&first, &argumentBundle, active);
            return;
        }
        if (!active)
        {
            int identifier = bhkEntity_Getbhk(hkpGetRigidBody(source));
            target->FUN_008cc730(&first, &argumentBundle, owner, identifier);
        }
    }
}

struct Obj
{
    unsigned int bhkCharacterController_GetCollisionGroup();
};
struct ActorImpact
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    NiPoint3 position;
    TESObjectREFR* object;
};
struct SceneOutput : AnimationOutput
{
    SceneNode* GetReferenceFlags();
};
ResourceUpdate* __cdecl FUN_004b5a20(SceneNode* node);
struct SceneProjectile
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
    virtual SceneNode* v1d0();
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
    ActorImpact* unk88;

    bool ArrowProjectile_ProcessSimulate(SceneOutput* owner);
};

// @fnv 0x008cdaf0
// src: XBOX_PDB 0x008cdaf0
bool SceneProjectile::ArrowProjectile_ProcessSimulate(SceneOutput* owner)
{
    v2a0();
    bhkWorld_SetMotion(v1d0(), 1, true, false, true);
    Actor* actor = dynamic_cast<Actor*>(unk88->object);
    if (actor && actor->FUN_009306d0())
    {
        owner->bhkWorldObject_SetCollisionFilter(UpdateToken(4, actor->FUN_009306d0()->bhkCharacterController_GetCollisionGroup(), 0).value);
    }
    else
    {
        owner->bhkWorldObject_SetCollisionFilter(UpdateToken(4, GetCachedValue(), 0).value);
    }
    owner->bhkRigidBody_SetLinearVelocity(unk88->position);
    ResourceUpdate* resource = FUN_004b5a20(owner->GetReferenceFlags());
    if (resource)
        resource->bhkNiCollisionObject_SetNotify(true);
    return true;
}
