#include "../../../../../include/BSThreadCriticalSectionPC.h"
#include "../../../../../include/hkArray.h"
// src/havok/physics/dynamics/world/hkpworld_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/dynamics/world/hkpworld.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/dynamics/world/hkpworld.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/hkpworld.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// VC9 recognizes this intrinsic type and the declarations below directly.
// Retain the unit's SIMD representation when shared headers request xmmintrin.h.
#define _INCLUDED_MM2
// Exe 0x00c95a80 FUN_00c95a80: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) { float m128_f32[4]; } __m128, LocalM128;
extern "C" {
extern LocalM128 _mm_add_ps(LocalM128 _A, LocalM128 _B);
extern LocalM128 _mm_add_ss(LocalM128 _A, LocalM128 _B);
extern LocalM128 _mm_and_ps(LocalM128 _A, LocalM128 _B);
extern LocalM128 _mm_andnot_ps(LocalM128 _A, LocalM128 _B);
extern LocalM128 _mm_cmpeq_ss(LocalM128 _A, LocalM128 _B);
extern LocalM128 _mm_load_ps(float const*_A);
extern LocalM128 _mm_load_ss(float const*_A);
extern LocalM128 _mm_max_ps(LocalM128 _A, LocalM128 _B);
extern LocalM128 _mm_min_ps(LocalM128 _A, LocalM128 _B);
extern LocalM128 _mm_mul_ps(LocalM128 _A, LocalM128 _B);
extern LocalM128 _mm_mul_ss(LocalM128 _A, LocalM128 _B);
extern LocalM128 _mm_rsqrt_ss(LocalM128 _A);
extern LocalM128 _mm_set_ps1(float _A);
extern LocalM128 _mm_set_ss(float _A);
extern LocalM128 _mm_setr_ps(float _A, float _B, float _C, float _D);
extern LocalM128 _mm_setzero_ps(void);
extern LocalM128 _mm_shuffle_ps(LocalM128 _A, LocalM128 _B, int _Imm8);
extern LocalM128 _mm_sqrt_ss(LocalM128 _A);
extern void _mm_store_ps(float *_V, LocalM128 _A);
extern void _mm_store_ss(float *_V, LocalM128 _A);
extern LocalM128 _mm_sub_ps(LocalM128 _A, LocalM128 _B);
extern LocalM128 _mm_sub_ss(LocalM128 _A, LocalM128 _B);
extern LocalM128 _mm_unpackhi_ps(LocalM128 _A, LocalM128 _B);
extern LocalM128 _mm_xor_ps(LocalM128 _A, LocalM128 _B);
}
#include "../../../../../include/AutoMemContext.h"
#include "../../../../../include/hkBaseObject.h"
#include "../../../../../include/hkBool.h"
#include "../../../../../include/hkMultiThreadCheck.h"
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkQuaternion.h"
#include "../../../../../include/hkQsTransform.h"

#include "../../../../../include/hkMonitorStream.h"
// hkpWorld_MemUsageOut_hkpworld_rtm_variant: local type (was include/hkpWorld_MemUsageOut.h, which had no evidence of one real class); no method of it is bound to a named game function
class hkpWorld_MemUsageOut_hkpworld_rtm_variant {
public:
    int m_maxSize;
    int m_totalSize;
    void* m_maxObject;
};
#include "../../../../../include/FinishingFlag.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkMonitorStream.h"
#include "../../../../../include/NiBinaryStream.h"
#include "../../../../../include/NiObject.h"
#include "../../../../../include/NiStream.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkStackMemory.h"
#include "../../../../../include/bhkWorld.h"
#include "../../../../../include/hkDebugDisplay.h"
#include "../../../../../include/hkDebugDisplayHandler.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkSingleton.h"
#include "../../../../../include/hkThreadMemory.h"
#include "../../../../../include/hkpBroadPhaseHandle.h"
#include "../../../../../include/hkpCdBody.h"
#include "../../../../../include/hkpCollidableCollidableFilter.h"
#include "../../../../../include/hkpCollisionFilter.h"
#include "../../../../../include/hkpSimulationIsland.h"
#include "../../../../../include/hkpWorld.h"
#include "../../../../../include/hkRotation.h"
#include "../../../../../include/hkSimdReal.h"
#include "../../../../../include/Pair.h"
#include "../../../../../include/NiPoint3.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkAabb.h"
#include "../../../../../include/hkVector4_S.h"
#include "../../../../../include/hkpAction.h"
#include "../../../../../include/hkpEntity.h"
#include "../../../../../include/hkpPhysicsSystem.h"
#include "../../../../../include/hkpPhantom.h"
#include "../../../../../include/hkpSimulation.h"
#include "../../../../../include/hkpMotion.h"
#include "../../../../../include/hkpBroadPhase.h"
#include "../../../../../include/hkSmallArray.h"

typedef short hkInt16;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
inline hkMultiThreadCheck::hkMultiThreadCheck() {}
struct FUN_00cf7c10 {
    void __thiscall PerformThisObjectOperation();
};
struct FUN_00c91120 {
    void __thiscall ExecutePendingOperations();
};
struct FUN_00c91180_Class {
    void EnterTlsGuard();
    void IncrementCounter();
};
struct FUN_00c91250_Class {
    void* m_p;
    void hkpWorld_markTreeDirty();
};
struct FUN_00cf6d20_Class {
    void __thiscall hkMultiThreadCheck_disableChecks();
};
struct FUN_00cf6d30_Class {
    void __thiscall ResetThreadCheck();
};
struct FUN_00c91280_Class {
    void __thiscall hkpWorld_setMultithreadedAccessChecking(int);
};
struct Ctx_00caa840 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    NiBinaryStream* m_pBackingStream;
};
struct Blk40 { float f[16]; };
template <class T> inline unsigned int WriteBinaryArray(NiBinaryStream& binstream, const T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    return binstream.BinaryWrite(pValue, uiNumEls * sizeof(T), &uiSize, uiNumEls);
}
template <class T> inline void SerializeValue(Ctx_00caa840& kStream, const T& tValue)
{
    WriteBinaryArray(*kStream.m_pBackingStream, &tValue, 1);
}
// Shape serialization view: two 64-byte blocks at 0x20/0x60 and state through 0xc8; include/Data.h is a 16-byte actor-value record.
struct SerializedShapeState {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    Blk40 m_20;
    Blk40 m_60;
    unsigned char unkA0;
    unsigned char unkA1;
    char m_a2;
    unsigned char unkA3;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    int m_b0;
    unsigned int unkB4;
    unsigned int unkB8;
    int m_bc;
    unsigned int unkC0;
    int m_c4;
    int m_c8;
};
struct FUN_00caa840_shell {
    void* m_iWordAt00;
    SerializedShapeState* m_data;
    void hkConstraintCinfo_SaveBinary(Ctx_00caa840* ctx);
    void SaveShape(int n, Ctx_00caa840* ctx);
    void WriteToStream(Ctx_00caa840* ctx);
};
void __stdcall hkpContactMgrFactory_calcContentStatistics(void* self, int arg);
struct FUN_00cf86e0_class {
    void hkpSimulation_setFrameTimeMarker(float);
};
void __fastcall hkpWorld_setFrameTimeMarker(void* p, int edx, float afValue);
struct RefObj { void FUN_00c90510(); };
struct DDCC60World { void removeReference(); };
struct FUN_00c910d0_Class {
    void* m_iWordAt00; void* m_iWordAt04; void* m_8; void* m_iThirdValue; void* m_10; void* m_14; void* m_18;
    void* m_1c; void* m_20; void* m_24; void* m_28; void* m_2c; void* m_30; void* m_34;
    void* m_38; void* m_3c; void* m_40; void* m_44; void* m_48; void* m_4c; void* m_50;
    void* m_54; void* m_58; void* m_5c; void* m_60; void* m_64; void* m_68; void* m_6c;
    void* m_70; void* m_74; void* m_78; void* m_7c; void* m_80; void* m_84; void* m_88;
    void* m_8c; void* m_90; void* m_94; void* m_98; void* m_9c; void* m_a0; void* m_a4;
    void* m_a8; void* m_ac; void* m_b0; void* m_b4; void* m_b8; void* m_bc; void* m_c0;
    void* m_c4; void* m_c8; void* m_cc; void* m_d0; void* m_d4; void* m_d8; void* m_dc;
    void* m_e0; void* m_e4; void* m_e8; void* m_ec; void* m_f0; void* m_f4; void* m_f8;
    void* m_fc; void* m_100; void* m_104; void* m_108; void* m_10c; void* m_110; void* m_114;
    void* m_118; void* m_11c; void* m_120; void* m_124; void* m_128; void* m_12c; void* m_130;
    void* m_134; void* m_138; void* m_13c; void* m_140; void* m_144; void* m_148; void* m_14c;
    void* m_150; void* m_154; void* m_158; void* m_15c; void* m_160; void* m_164; void* m_168;
    void* m_16c; void* m_170; void* m_174; void* m_178; void* m_17c; void* m_180; void* m_184;
    void* m_188; void* m_18c; void* m_190; void* m_194; void* m_198; void* m_19c; void* m_1a0;
    void* m_1a4; void* m_1a8; void* m_1ac; void* m_1b0; void* m_1b4; void* m_1b8;
    void* m_1bc;
    void SetRefObject(void*);
};
struct FUN_00cf7ae0_Class {
    void hkpWorldOperationQueue_executeAllPendingBodyOperations();
};
struct FUN_00c91140_Class {
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0C;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1C;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2C;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
    unsigned int m_3C;
    unsigned int m_40;
    unsigned int m_44;
    unsigned int m_48;
    unsigned int m_4C;
    unsigned int m_50;
    unsigned int m_54;
    unsigned int m_58;
    unsigned int m_5C;
    unsigned int m_60;
    unsigned int m_64;
    unsigned int m_68;
    unsigned int m_6C;
    unsigned int m_70;
    unsigned int m_74;
    unsigned int m_78;
    unsigned int m_7C;
    unsigned int m_80;
    unsigned int m_84;
    unsigned int m_88;
    unsigned int m_8C;
    int m_90;
    void UpdateFields_00c91140();
};
struct S_00cf7540_Ref {
    void* m_p;
};
struct S_00cf7540 {
    void __thiscall AddEntry(S_00cf7540_Ref*, S_00cf7540_Ref*, int, int);
};
struct FUN_00c91170_Class {
    void hkpWorld_addBodyOperation(S_00cf7540_Ref*, S_00cf7540_Ref*, int, int);
};
void __cdecl hkReferencedObject_unlockAll();
struct FUN_00c91190_Class {
    void __thiscall hkpWorld_unlock();
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
struct FUN_00c911d0_Class {
    void __thiscall EnterLock(void*);
};
extern void (__stdcall *DAT_00fdf05c)(void*);
struct FUN_00c911f0_Class {
    void UpdateState_00c911f0(void*);
};
struct FUN_00c928c0_ActionList
{
    hkpAction** m_ppActions;
    int m_uiItemCount;
};
struct FUN_00c928c0_ActionOwner
{
    unsigned char m_auiShapeKeys[0x38];
    FUN_00c928c0_ActionList m_actionList;
};
struct FUN_00c928c0_Context
{
    unsigned char m_pad00[0x28];
    FUN_00c928c0_ActionOwner** m_owners1;
    unsigned int m_ownerCount1;
    unsigned char m_pad30[0x04];
    FUN_00c928c0_ActionOwner** m_owners2;
    unsigned int m_ownerCount2;
};
void enumerateAllActionsInWorld( FUN_00c928c0_Context* context, hkpPhysicsSystem* physicsSystem);
struct FUN_00c92b50_Class {
    char pad[0x28];
    void* m_data;   // +0x28
    int m_iElementCount;     // +0x2c
    void __thiscall ComputeMemoryUsage(hkpWorld_MemUsageOut_hkpworld_rtm_variant* out);
};
struct CA8B80Command {
    unsigned char m_bType;
    void* m_p;
};
struct CA8B80Queue {
    void __thiscall Push(CA8B80Command*);
};
struct FUN_00c97510 {
    void __thiscall ProcessPointer(void*);
};
struct FUN_00c97f50_Class {
    void DispatchOrQueue(void* p);
};
extern int DAT_010c3bb8;
void __cdecl _Deallocate(void*);
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* lpCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* lpCriticalSection);
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall FUN_00fdf05c(void*);
extern "C" __declspec(dllimport) void __stdcall FUN_00fdf100(void*);
struct FUN_00c90f30_Class {
    int unk00;
    void* __thiscall SetUnk00();
};
struct CpuScalar {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    float value;
};
struct CpuObject {
    unsigned int unk00;
    unsigned int unk04;
    CpuScalar* value;
    float hkpWorld_getCurrentTime();
};
struct FUN_00cf86f0_Class {
    void __thiscall IsFieldEqual();
};
struct FUN_00c91060_Class {
    void* m_iWordAt00;
    void* m_iWordAt04;
    FUN_00cf86f0_Class* m_8;
    void __thiscall hkpWorld_isSimulationAtMarker();
};
struct Inner
{
    void Tail();
};
struct FUN_00c91070_cls
{
    int unk00;
    int unk04;
    Inner* m_08;
    void ForwardCall_00c91070();
};
struct FnvCpu_FUN_00c91090_CpuInterface {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void Invoke(int arg0);
};
struct FnvCpu_FUN_00c91090_CpuOwner {
    unsigned int unk00;
    unsigned int unk04;
    FnvCpu_FUN_00c91090_CpuInterface* target;
    void ForwardCall_00c91090(int arg0);
};
struct PendingOperations {
    void __thiscall FUN_00cf7690();
};
struct WorldWithPending : hkpWorld {
    void __thiscall hkpWorld_queueOperation();
};
struct Target
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void Forward(int a);
};
struct FUN_00c91270_cls
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
    Target* m_5C;
    void ahkpWorld_updateKdTree(int a);
};
struct FUN_00c98250_Class {
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* __thiscall hkpNullContactMgrFactory_createContactMgr(int, int, int);
};
void __stdcall Object_UpdateFields_00c982a0(char* pFlag, int a2, int a3, int a4, int a5, int a6);
void __stdcall hkpWorld_SetOutputFlag(unsigned char* flag, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
extern __declspec(thread) int g_tlsMemContext;
extern unsigned int DAT_011afe7c;
struct ScopedMemContext {
    int m_saved;
    ScopedMemContext(int ctx) { m_saved = g_tlsMemContext; g_tlsMemContext = ctx; }
    ~ScopedMemContext() { g_tlsMemContext = m_saved; }
};
struct C67Owner {
    int unk00;
    int unk04;
    int unk08;
    struct C67Flags* unk0C;
};
struct C67Flags {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int unk10;
    void clearFlag20() { unk10 &= ~0x20; }
};
struct C67Collidable {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    signed char m_iOwnerOffset;
    char unk11;
    char unk12;
    char unk13;
    int unk14;
    char m_type;
    C67Owner* getOwner() { return (C67Owner*)((char*)this + m_iOwnerOffset); }
};
struct C67Entry {
    void removeReference();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C67Collidable m_kCollidable;
};
inline C67Owner* getEntityOwner(C67Collidable* coll)
{
    if (coll->m_type == 1)
        return coll->getOwner();
    return 0;
}
struct C67Sink {
    void RemoveEntities(C67Entry** entries, unsigned int count);
};
class FUN_00c67aa0_Class {
public:
    virtual void vf00(); virtual void vf01(); virtual void vf02(); virtual void vf03();
    virtual void vf04(); virtual void vf05(); virtual void vf06(); virtual void vf07();
    virtual void vf08(); virtual void vf09(); virtual void vf10(); virtual void vf11();
    virtual void vf12(); virtual void vf13(); virtual void vf14(); virtual void vf15();
    virtual void vf16(); virtual void vf17(); virtual void vf18(); virtual void vf19();
    virtual void vf20(); virtual void vf21(); virtual void vf22(); virtual void vf23();
    virtual void vf24(); virtual void vf25(); virtual void vf26(); virtual void vf27();
    virtual void vf28(); virtual void vf29(); virtual void vf30(); virtual void vf31();
    virtual void vf32(); virtual void vf33(); virtual void vf34(); virtual void vf35();
    virtual void vf36();
    virtual C67Sink* getSink();
    int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48;
    C67Entry** m_entries;
    unsigned int m_iNumberOfEntries;
    void FlushEntries();
};
struct WorldExt : public hkpWorld {
    float hkpWorld_getCurrentTime() throw();
    void hkpWorld_setFrameTimeMarker(float f) throw();
    void hkpWorld_advanceTime() throw();
    bool hkpWorld_isSimulationAtMarker() throw();
    float hkpWorld_getCurrentPsiTime() throw();
    void hkpWorld_stepDeltaTime(float f) throw();
    void hkpWorld_stepMultithreaded(int a, int b, float f) throw();
    void FUN_00c91120() throw();
    void UpdateFields_00c91140() throw();
};
struct Class_012677d0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    void EnsureObjectsCreated(unsigned char val) throw();
};
extern float DAT_012677c4;
extern char DAT_012677a0;
extern int DAT_012677c8;
extern unsigned char DAT_012677a2;
extern unsigned int DAT_011afe80;
extern float DAT_011afe68;
extern unsigned char DAT_01267b2c;
extern Class_012677d0* DAT_012677d0;
extern float DAT_01267b38;
extern float DAT_011ac3a0;
extern float DAT_012677ac;
extern float DAT_011afe64;
extern char DAT_012677cd;
void __stdcall nullsub_5(int);
void Object_DoNothing_00c911a0();
extern void (__stdcall *DAT_00fdf100)(void*);
struct FUN_00c91230_World : hkpWorld {
    void __thiscall ProcessState_00c91230(void* param);
};
struct FUN_00c912c0_Class : hkpWorld {
    unsigned int hkpWorld_getMultithreadedAccessChecking();
};
struct Comparator {
    virtual void unused_00();
    virtual void unused_01();
    virtual void unused_02();
    virtual void unused_03();
    virtual void unused_04();
    virtual void unused_05();
    virtual void unused_06();
    virtual void unused_07();
    virtual void unused_08();
    virtual void unused_09();
    virtual void unused_0a();
    virtual void unused_0b();
    virtual void unused_0c();
    virtual void unused_0d();
    virtual void unused_0e();
    virtual void unused_0f();
    virtual void unused_10();
    virtual void unused_11();
    virtual void unused_12();
    virtual bool accepts(const void* left, const void* right);
};
struct FilterCore {
    virtual void reserved();
    virtual unsigned char* evaluate(unsigned char* answer, const void* left, const void* right);
};
struct FilterOwner {
    void* unknown_00;
    void* unknown_04;
    FilterCore core;
};
struct OpPacket {
    unsigned char opcode;
    const void* left;
    const void* right;
};
struct EventSink {
    void hkpTypedBroadPhaseDispatcher_addPairs(const Pair* p, int action, FilterCore* core);
};
int __cdecl FindEntryValue(const void*, const void*);
struct FUN_00c913b0_Class {
    void* unknown_00;
    void* unknown_04;
    void* unknown_08;
    void* unknown_0c;
    void* unknown_10;
    void* unknown_14;
    void* unknown_18;
    void* unknown_1c;
    void* unknown_20;
    void* unknown_24;
    void* unknown_28;
    void* unknown_2c;
    void* unknown_30;
    void* unknown_34;
    void* unknown_38;
    void* unknown_3c;
    void* unknown_40;
    void* unknown_44;
    void* unknown_48;
    void* unknown_4c;
    void* unknown_50;
    void* unknown_54;
    Comparator* m_comparator;
    void* unknown_5c;
    void* unknown_60;
    EventSink* m_callback;
    void* unknown_68;
    void* unknown_6c;
    void* unknown_70;
    void* unknown_74;
    void* unknown_78;
    FilterOwner* m_iFilter;
    void* unknown_80;
    void* unknown_84;
    void* unknown_88;
    void* unknown_8c;
    void* unknown_90;
    void* m_pDataAtOffset94;
    void hkpWorld_queueOperation(const OpPacket* packet);
    void ProcessPair(const void* left, const void* right);
};
struct Sh00c91160 { void hkpWorld_queueOperation(void* rec); };
struct SimVtbl
{
    void* slot[12];
    void (__thiscall* invoke)(void*, int, int, void*, int);   // +0x30
};
struct Sim
{
    SimVtbl* m_vtbl;
};
struct WorldQ
{
    char pad0[8];
    Sim* m_pSimulation;                              // +0x08
    char pad_c[0x94 - 0xc];
    int m_iCriticalOperationsLockCount;               // +0x94

    void __thiscall DispatchOp(int a0, int a1, int a2);
};
class hkpMotionC914;
void __cdecl hkSweptTransformUtil_setTimeInformation(float fA, float fB, int* piOut) throw();
struct hkpCollidableQualityC914 {
    void SetFlagBits(unsigned char ucA, unsigned char ucB, unsigned char ucC) throw();
};

struct hkWorldOperationBaseC914 {
    unsigned char m_type;
};
struct hkWorldOperationAddEntityC914 : public hkWorldOperationBaseC914 {
    hkpEntity* m_pEntity;
    int m_iActivationState;

    hkWorldOperationAddEntityC914() { m_type = 1; }
};

void __cdecl hkpWorldOperationUtil_addEntitySI(hkpWorld* pkWorld, hkpEntity* pkEntity, int iInitialActivationState) throw();
void __cdecl hkpWorldOperationUtil_addEntityBP(hkpWorld* pkWorld, hkpEntity* pkEntity) throw();
void __cdecl NotifyEntityAdded(hkpWorld* pkWorld, hkpEntity* pkEntity) throw();
void __cdecl hkpEntityCallbackUtil_fireEntityAdded(hkpEntity* pkEntity) throw();
struct PointerArray {
    void** elements;
    int size;
    __forceinline int Find(void* target) const {
        for(int index=0;index<size;++index) {
            if(elements[index]==target) return index;
        }
        return -1;
    }
};
struct ObjectTable {
    unsigned int unk000;
unsigned int unk004;
unsigned int unk008;
unsigned int unk00c;
unsigned int unk010;
unsigned int unk014;
unsigned int unk018;
unsigned int unk01c;
unsigned int unk020;
unsigned int unk024;
unsigned int unk028;
unsigned int unk02c;
unsigned int unk030;
unsigned int unk034;
unsigned int unk038;
unsigned int unk03c;
unsigned int unk040;
unsigned int unk044;
unsigned int unk048;
unsigned int unk04c;
unsigned int unk050;
unsigned int unk054;
unsigned int unk058;
unsigned int unk05c;
unsigned int unk060;
unsigned int unk064;
unsigned int unk068;
unsigned int unk06c;
unsigned int unk070;
unsigned int unk074;
unsigned int unk078;
unsigned int unk07c;
unsigned int unk080;
unsigned int unk084;
unsigned int unk088;
unsigned int unk08c;
unsigned int unk090;
unsigned int unk094;
unsigned int unk098;
unsigned int unk09c;
unsigned int unk0a0;
unsigned int unk0a4;
unsigned int unk0a8;
unsigned int unk0ac;
unsigned int unk0b0;
unsigned int unk0b4;
unsigned int unk0b8;
unsigned int unk0bc;
unsigned int unk0c0;
unsigned int unk0c4;
unsigned int unk0c8;
unsigned int unk0cc;
unsigned int unk0d0;
unsigned int unk0d4;
unsigned int unk0d8;
unsigned int unk0dc;
unsigned int unk0e0;
unsigned int unk0e4;
unsigned int unk0e8;
unsigned int unk0ec;
unsigned int unk0f0;
unsigned int unk0f4;
unsigned int unk0f8;
unsigned int unk0fc;
unsigned int unk100;
unsigned int unk104;
unsigned int unk108;
unsigned int unk10c;
unsigned int unk110;
unsigned int unk114;
unsigned int unk118;
unsigned int unk11c;
unsigned int unk120;
unsigned int unk124;
unsigned int unk128;
unsigned int unk12c;
unsigned int unk130;
unsigned int unk134;
unsigned int unk138;
unsigned int unk13c;
unsigned int unk140;
unsigned int unk144;
unsigned int unk148;
unsigned int unk14c;
unsigned int unk150;
unsigned int unk154;
    PointerArray pointers;
    void RemovePointer(void* value);
};
struct SearchArray {
unsigned int unk000;
unsigned int unk004;
unsigned int unk008;
unsigned int unk00c;
unsigned int unk010;
unsigned int unk014;
unsigned int unk018;
unsigned int unk01c;
unsigned int unk020;
unsigned int unk024;
unsigned int unk028;
unsigned int unk02c;
unsigned int unk030;
unsigned int unk034;
unsigned int unk038;
unsigned int unk03c;
unsigned int unk040;
unsigned int unk044;
unsigned int unk048;
unsigned int unk04c;
unsigned int unk050;
unsigned int unk054;
unsigned int unk058;
unsigned int unk05c;
unsigned int unk060;
unsigned int unk064;
unsigned int unk068;
unsigned int unk06c;
unsigned int unk070;
unsigned int unk074;
unsigned int unk078;
unsigned int unk07c;
unsigned int unk080;
unsigned int unk084;
unsigned int unk088;
unsigned int unk08c;
unsigned int unk090;
unsigned int unk094;
unsigned int unk098;
unsigned int unk09c;
unsigned int unk0a0;
unsigned int unk0a4;
unsigned int unk0a8;
unsigned int unk0ac;
unsigned int unk0b0;
unsigned int unk0b4;
unsigned int unk0b8;
unsigned int unk0bc;
unsigned int unk0c0;
unsigned int unk0c4;
unsigned int unk0c8;
unsigned int unk0cc;
unsigned int unk0d0;
unsigned int unk0d4;
unsigned int unk0d8;
unsigned int unk0dc;
unsigned int unk0e0;
unsigned int unk0e4;
unsigned int unk0e8;
unsigned int unk0ec;
unsigned int unk0f0;
unsigned int unk0f4;
unsigned int unk0f8;
unsigned int unk0fc;
unsigned int unk100;
unsigned int unk104;
unsigned int unk108;
unsigned int unk10c;
unsigned int unk110;
unsigned int unk114;
unsigned int unk118;
unsigned int unk11c;
unsigned int unk120;
unsigned int unk124;
unsigned int unk128;
unsigned int unk12c;
unsigned int unk130;
unsigned int unk134;
unsigned int unk138;
unsigned int unk13c;
unsigned int unk140;
unsigned int unk144;
unsigned int unk148;
unsigned int unk14c;
unsigned int unk150;
unsigned int unk154;
unsigned int unk158;
unsigned int unk15c;
unsigned int unk160;
int* items;
int count;
void ClearValue(int value);
int find(int value) const { for(int i=0;i<count;++i){if(items[i]==value)return i;}return -1;}
};
struct EntryListNode {
    int* volatile entries;
    int count;
    int findIndex(int value) const {
        int total = count;
        int index = 0;
        if (total > 0) {
            int* cursor = entries;
            do {
                if (*cursor == value)
                    return index;
                ++index;
                ++cursor;
            } while (index < total);
        }
        return -1;
    }
};
struct FUN_00c919d0_Class {
    void hkpWorld_removeIslandPostIntegrateListener(int value);
};
struct CD22Registry {
    void __thiscall IncrementCounter();
    void __thiscall hkpWorld_unlock();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5();
    int hkpWorld_collide();
};
struct hkShapeC927 {
    unsigned short m_type;
    unsigned short unk02;
    int unk04[4];
    hkShapeC927* m_pChildAtom;
};
struct hkRecordC927 {
    void* m_object;
    int unk04[2];
    hkShapeC927* m_pCollisionShape;
    int unk10[8];
};
struct hkRecordListC927 {
    hkRecordC927* m_data;
    unsigned short m_iElementCount;
};
struct hkEntityC927 {
    char unk00[0xac];
    hkRecordListC927 m_records;
};
struct hkWorldC927 {
    int unk00[0x12];
    hkEntityC927** m_kActorEntries;
    int m_iActorEntryCount;
};
class hkSetC927 {
public:
    void hkpPhysicsSystem_addConstraint(void* object);
};
void __cdecl enumerateAllConstraintsInIsland(hkWorldC927* world, hkSetC927* set);
// the pointer arrays below are hkArray<void*> (include/hkArray.h)
struct PendingOps { 
    void* m_vtbl; void* m_04; void* m_08; void* m_0c; 
    hkArray<void*> m_10; hkArray<void*> m_1c;
};
struct HandlerRegistration { void* data; void* other; HandlerRegistration* next; };
struct WorldSave {
    void* m_vtbl; unsigned short m_usMemSizeAndFlags; short m_sReferenceCount;
    void* m_pSimulation; unsigned int m_unknown0c;
    hkVector4 m_kGravity;
    void* m_pFixedIsland; void* m_pFixedRigidBody;
    hkArray<void*> m_kActiveSimulationIslands;
    hkArray<void*> m_kInactiveSimulationIslands;
    hkArray<void*> m_kDirtySimulationIslands;
    void* m_pMaintenanceManager; void* m_pMemoryWatchDog;
    unsigned char m_bAssertOnRunningOutOfSolverMemory;
    void* m_pJobSemaphore; void* m_pKdTreeManager;
    unsigned char m_bUseKdTree;
    void* m_pBroadPhaseDispatcher; void* m_pPhantomBroadPhaseListener;
    void* m_pEntityEntityBroadPhaseListener; void* m_pBroadPhaseBorderListener;
    void* m_pMultithreadedSimulationJobData;
    void* m_pCollisionInput; void* m_pCollisionFilter; void* m_pDispatcher;
    void* m_pConvexListCollisionFilter; PendingOps* m_pPendingOperations;
    int m_iPendingOperationCount; int m_iQueuedOperationCount;
    int m_iCriticalOperationsLockCount; int m_iCriticalOperationsLockCountForPhantoms;
    unsigned char m_bBlockExecutingPendingOperations; unsigned char m_bBlockExecutingPendingOperationQueues;
    HandlerRegistration* m_pPendingOperationQueues; int m_iPendingOperationQueueCount;
    hkMultiThreadCheck m_kMultiThreadCheck;
    unsigned char m_bProcessActionsInSingleThread;
    unsigned char m_bAllowUnconstrainedIslandJob;
    unsigned int m_uiMinDesiredIslandSize;
    void* m_pModifyConstraintCriticalSection; int m_iIsLocked;
    void* m_pIslandDirtyListCriticalSection; void* m_pPropertyMasterLock;
    unsigned char m_bWantSimulationIslands;
    float m_fSnapCollisionToConvexEdgeThreshold; float m_fSnapCollisionToConcaveEdgeThreshold;
    unsigned char m_bEnableToiWeldRejection; unsigned char m_bWantDeactivation;
    unsigned char m_bActivateOnBodyTransformChange;
    float m_fDeactivationReferenceDistance; float m_fToiCollisionResponseRotateNormal;
    int m_iMaxSectorsPerMidphaseTask; unsigned char m_bProcessToisMultithreaded;
    int m_iMaxSectorsPerNarrowphaseTask; int m_iMaxEntriesPerMidphaseToiTask;
    int m_iMaxEntriesPerNarrowphaseToiTask;
    float m_fSimplifiedToiPenetrationThreshold; float m_fToiPenetrationThreshold;
    float m_fHigherToiPenetrationThreshold; float m_fForcedToiPenetrationThreshold;
    unsigned int m_uiLastEntityUid; unsigned int m_uiLastIslandUid; unsigned int m_uiLastConstraintUid;
    hkArray<void*> m_kPhantoms; hkArray<void*> m_kActionListeners; hkArray<void*> m_kEntityListenerArray;
    hkArray<void*> m_kPhantomListeners; hkArray<void*> m_kConstraintListeners; hkArray<void*> m_kWorldDeletionListeners;
    hkArray<void*> m_kIslandActivationListeners; hkArray<void*> m_kWorldPostSimulationListeners;
    hkArray<void*> m_kWorldPostIntegrateListeners; hkArray<void*> m_kWorldPostCollideListeners;
    hkArray<void*> m_kIslandPostIntegrateListeners; hkArray<void*> m_kIslandPostCollideListeners;
    hkArray<void*> m_kContactListeners; hkArray<void*> m_kContactImpulseLimitBreachedListeners;
    void* m_pViolatedConstraintArray; void* m_pBroadPhaseBorder;
    void hkpWorld_calcContentStatistics(struct ObjectWriter* writer, void* unused);
};
struct ObjectWriter {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void WriteValue(char* name, void* value, int flags);
    virtual void slot10();
    virtual void WriteArray(int kind, char* name, void* array, int length, void* bounded);
    virtual void OpenBlock(char* name);
    virtual void CloseBlock();
    int m_unknown04;
    void* m_reference08;
    int m_unknown0c;
    unsigned char m_writeAll10;
    void DispatchWithMode(char* name, void* value, unsigned int length, int flags);
};
void* __cdecl hkStatisticsCollector_getAllocatedSize(void* array, unsigned int bytes);
extern char str_010c6700;
extern char str_0109c938;
extern char str_010c66f0;
extern char str_010c66e4;
extern char str_010c6084;
extern char str_010c66d8;
extern char str_010c41a4;
extern char str_010c66b8;
extern char str_010c6698;
extern char str_010c6684;
extern char str_010c6664;
extern char str_010c664c;
extern char str_010c6630;
extern char str_010c6624;
extern char str_010c6618;
extern char str_010c660c;
extern char str_010c6600;
extern char str_010c65f8;
extern char str_010c65e8;
extern char str_010c65d8;
extern char str_010c65c4;
extern char str_010c65bc;
extern char str_010c65b0;
extern char str_010c65a4;
extern char str_010c6598;
extern char str_010c6580;
extern char str_010c6578;
extern char str_010c6564;
extern char str_010c6558;
extern char str_010c654c;
extern char str_010c6540;
extern char str_010c6534;
extern char str_010c6524;
extern char str_010c6514;
extern char str_010c6504;
extern char str_010c64f4;
extern char str_010c64e4;
extern char str_010c64d4;
extern char str_010c64c8;
static __forceinline void SaveArray(ObjectWriter* writer,hkArray<void*>& array,char* name,unsigned int stride) {
    if ((array.m_iCapacityState & 0x80000000u) == 0 || writer->m_writeAll10) {
        void* ptr = array.m_data;
         unsigned int capacity = (array.m_iCapacityState & 0x3fffffff);
         void* bounded = hkStatisticsCollector_getAllocatedSize(ptr, capacity * stride);
        writer->WriteArray(3, name, array.m_data, array.m_iElementCount * stride, bounded);
    }
}
static __forceinline void SaveBlob(ObjectWriter* writer,char* name,void* address,unsigned int length) {
    writer->DispatchWithMode(name,address,length,0);
}
struct WorldWatchDogHolder : hkpWorld {
    void* __thiscall hkpWorld_getMemoryWatchDog();
};
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
inline void __cdecl operator delete(void*, void*) { }
struct ThreadMemHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_alloc;
};
void* hkMemoryRouter_getInstance();
void ResizeAudioStream(void* alloc, void* array, int elemSize);
void QueryEntityIntoBuffer(hkpWorld* world, hkpPhantom* phantom);
void NotifyPhantomAdded(hkpWorld* world, hkpPhantom* phantom);
struct PendingOperation {
    unsigned char m_type;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    hkpPhantom* m_pPhantom;
};
struct FUN_00c936a0_World : hkpWorld {
    void hkpWorld_queueOperation(PendingOperation* op);
    void FUN_00c91120();
    void UpdateFields_00c91140();

    hkpPhantom* hkpWorld_addPhantom(hkpPhantom* phantom);
};
struct FUN_00c93ae0_Vt {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c(void* p, int n);
    virtual void slot10();
};
struct FUN_00c93ae0_Dtm {
    void hkJobQueue_processAllJobs();
};
struct FUN_00c93ae0_Cb {
    int hkpWorld_initMtStep(void* p, float f);
};
struct FUN_00c93ae0_Pair {
    void hkpWorld_finishMtStep(void* a, void* b);
};
struct FUN_00c93ae0_class {
    void hkpWorld_stepMultithreaded(void* p1, void* p2, float f);
};


class FUN_00c93d10 : public hkReferencedObject {
public:
    void* m_pSimulation;
    char m_padC[0x4];
    hkVector4 m_kGravity;
    void* m_pFixedIsland;
    void* m_pFixedRigidBody;
    hkArray<void*> m_kActiveSimulationIslands;
    hkArray<void*> m_kInactiveSimulationIslands;
    hkArray<void*> m_kDirtySimulationIslands;
    void* m_pMaintenanceManager;
    void* m_pMemoryWatchDog;
    char m_pad54[0x54];
    hkMultiThreadCheck m_kMultiThreadCheck;
    char m_padB0[0x6c];
    hkArray<void*> m_kPhantoms;
    hkArray<void*> m_kActionListeners;
    hkArray<void*> m_kEntityListenerArray;
    hkArray<void*> m_kPhantomListeners;
    hkArray<void*> m_kConstraintListeners;
    hkArray<void*> m_kWorldDeletionListeners;
    hkArray<void*> m_kIslandActivationListeners;
    hkArray<void*> m_kWorldPostSimulationListeners;
    hkArray<void*> m_kWorldPostIntegrateListeners;
    hkArray<void*> m_kWorldPostCollideListeners;
    hkArray<void*> m_kIslandPostIntegrateListeners;
    hkArray<void*> m_kIslandPostCollideListeners;
    hkArray<void*> m_kContactListeners;

    FUN_00c93d10(int iUnused) throw();
    virtual void calcContentStatistics() throw();
};
struct SystemObject {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    void* owner;
    void* attachment;
};
struct ActiveFlag {
    char value;
    operator bool() const { return value != 0; }
};
struct PhysicsSystem {
    unsigned int unk00;
    unsigned int unk04;
    hkArray<void*> entities;
    hkArray<SystemObject*> constraints;
    hkArray<void*> actions;
    hkArray<void*> phantoms;
    unsigned int unk38;
    unsigned int unk3c;
    ActiveFlag active;
    ActiveFlag isActive() const { return active; }
};
inline int findNull(const hkArray<void*>& values) {
    for (int i = 0; i < values.m_iElementCount; ++i) {
        if (values.m_data[i] == 0)
            return i;
    }
    return -1;
}
struct SystemWorld : hkpWorld {
    void hkpWorld_addEntityBatch(void**, int, int);
    void hkpWorld_addEntity(void*, int);
    void hkpWorld_addPhantomBatch(void**, int);
    void hkpWorld_addPhantom(void*);
    void hkpWorld_addAction(void*);
    void hkpWorld_addConstraint(SystemObject*);
    void hkpWorld_addPhysicsSystem(PhysicsSystem* system);
};
class hkpConstraintInstanceC980;
class hkpActionC980;
class hkpRigidBodyC980;
class hkpEntityC980;

struct hkBoolRetC980 {
    char m_cBooleanValue;
    hkBoolRetC980() throw() {}
};


extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
class hkListenerC984 {
public:
    virtual void v00();
    virtual void v04();
    virtual void onEvent(int a, int b, int c, int d, int e);
};
class hkDispatcherC984 {
public:
    int unk00;
    int unk04;
    hkListenerC984** m_kListeners;
    int m_numListeners;
    int unk10;
    void* m_kCriticalSection;

    void DispatchEvent(int a, int b, int c, int d, int e);
};
extern void(__stdcall* DAT_00fdf05c)(void* pvSection);
extern void(__stdcall* DAT_00fdf100)(void* pvSection);

struct hkVector3C985 {
    float x;
    float y;
    float z;
};
class hkListenerC985 {
public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void notify(void* a, void* b, void* c, float x, float y, float z, void* d);
};
class hkpListenerC986 {
public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual void V5() throw();
    virtual void V6() throw();
    virtual void V7() throw();
    virtual void notify(int a, int b, int c, int d) throw();
};
class hkpListenerC98B {
public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual void V5() throw();
    virtual void V6() throw();
    virtual void V7() throw();
    virtual void V8() throw();
    virtual void notify(int a, int b, int c, int d, int e) throw();
};
// 0x00c98720  unit_74447a602ec8.cpp  /MT /O2 /GS /EHsc /Gy
// thiscall, 6 stack args (ret 0x18): lock pointer at this+0x14, walk the array at
// this+8 for this->count0c elements, call vtable slot 0x28 with the six args, unlock.
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
struct Listener00c98720 {
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void s0c();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1c();
    virtual void s20();
    virtual void s24();
    virtual void s28(int, int, int, int, int, int);
};


struct IListener {
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c(void* a1, void* a2, void* a3, void* a4, void* a5);
};
extern "C" __declspec(dllimport) void __stdcall FUN_00fdf05c(void*);
extern "C" __declspec(dllimport) void __stdcall FUN_00fdf100(void*);
struct FUN_00c99160_Dispatch {
    virtual void fn00();
    virtual void fn04();
    virtual void fn08();
    virtual void fn0c();
    virtual void fn10();
    virtual void fn14();
    virtual void fn18();
    virtual void fn1c();
    virtual void fn20();
    virtual void fn24();
    virtual void fn28();
    virtual void fn2c();
    virtual void fn30();
    virtual void fn34();
    virtual void fn38();
    virtual void fn3c(int a, int b, int c, int d, int e);
};
struct FUN_00c991c0_Interface {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void __thiscall slot38(int, int, int, int);
};
extern void (__stdcall *DAT_00fdf05c)(void*);
extern void (__stdcall *DAT_00fdf100)(void*);
struct __declspec(align(16)) AlignedRotation : hkRotation {
    void SetFromInput_Thunk(const hkQuaternion& a1);
};
struct FUN_00ca8420_Local {
    unsigned char unk00;
    unsigned int unk04;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
};
struct FUN_00ca8420_Target {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8C;
    int unk90;
    int unk94;

    void __thiscall hkpWorld_queueOperation(FUN_00ca8420_Local* local);
};
struct FUN_00ca8420_Class {
    void* unk00;
    void* unk04;
    FUN_00ca8420_Target* unk08;

    void __thiscall hkpRigidBody_setMotionType(int param2, int param3, int param4);
};
void __cdecl hkpWorldOperationUtil_setRigidBodyMotionType(void* param1, int param2, int param3, int param4);
void __cdecl NotifyEntitySetMotionType(void* param1, void* param2);
void __cdecl InvokeMotionTypeCallbacks(void* param1);
struct hkVector3CA8A {
    float x;
    float y;
    float z;
};
struct hkWorldOperationBaseCA8A {
    unsigned char m_type;
};
struct hkSetVelocityOpCA8A : public hkWorldOperationBaseCA8A {
    hkpEntity* m_pEntity;
    float m_fVelocity[3];

    hkSetVelocityOpCA8A() { m_type = 0x1b; }
};

struct UnkCall {
    void activate_00c9c1d0();
};


struct FUN_00ca94c0_Ctx {
    void* self;
    unsigned int arg;
    unsigned int result;
};
struct FUN_00ca94c0_Elem {
    virtual void Visit(FUN_00ca94c0_Ctx* ctx);
};
struct FUN_00ca94c0_Class {
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
    FUN_00ca94c0_Elem** m_pElements;
    int m_uiItemCount;
    int hkpPhantom_fireCollidableAdded(unsigned int arg);
};
struct Allocator9 { void* __thiscall Game_DoHeapAlloc(unsigned int size); };
extern Allocator9 DAT_011f6238;
extern "C" int DAT_010c5dc0;
extern __declspec(thread) unsigned char threadContext9;
struct Guard9 {
    int previous;
    Guard9() {
        int* flag = (int*)((char*)&threadContext9 + 0x2b4);
        previous = *flag;
        *flag = 16;
    }
    ~Guard9() {
        int* flag = (int*)((char*)&threadContext9 + 0x2b4);
        *flag = previous;
    }
};
struct Node9 { void* vtable; int value; int references; int previous; int next; };
struct Class9 {
    void* unk00; void* unk04; int callbackFlag; int* data;
    void __thiscall CopyFromSource(Node9* node);
    int* __thiscall GetOrCreateData(unsigned char* wasEmpty);
};
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
typedef unsigned int (__cdecl* ReadFn)(NiBinaryStream* pThis, void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents);
inline unsigned int BinaryRead(NiBinaryStream* stream, void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes = 0, unsigned int uiNumComponents = 0)
{
    unsigned int uiBytes = stream->BinaryRead(pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    return uiBytes;
}
template <class T>
inline unsigned int NiBinaryStreamLoad(NiBinaryStream* binstream, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    return BinaryRead(binstream, pValue, uiNumEls * sizeof(T), &uiSize, uiNumEls);
}
template <class T>
inline void ReadBinaryValue(NiStream& stream, T& value)
{
    NiBinaryStreamLoad(stream.GetBinaryStream(), &value, 1);
}
extern "C" void __cdecl SwapEndianBlocks(void* p);
inline void SwapDword(unsigned long& val) {
    val = _byteswap_ulong(val);
}
inline void ByteSwapBlk(Blk40& blk)
{
    unsigned long* u = (unsigned long*)&blk;
    SwapDword(u[12]);
    SwapDword(u[13]);
    SwapDword(u[14]);
    SwapDword(u[15]);
    SwapEndianBlocks(&blk);
}
struct FUN_00d1df70 {
    void removeReference();
};
// Shape serialization view with SetReferencedObject; inherits the 0xcc-byte state, unlike the 16-byte include/Data.h record.
struct ReferencedShapeState : SerializedShapeState {
    void SetReferencedObject(hkReferencedObject* obj);
};
struct FUN_00d53200_class {
    void* m_unk00;
    ReferencedShapeState* m_data;

    void hkConstraintCinfo_LoadBinary(NiStream& stream);
    hkReferencedObject* hkConstraintCinfo_LoadMotor(NiStream& stream);

    void ReadFromStream(NiStream& stream);
};
struct AudioTlsState {
 int unk000;
 int unk004;
 int unk008;
 int unk00C;
 int unk010;
 int unk014;
 int unk018;
 int unk01C;
 int unk020;
 int unk024;
 int unk028;
 int unk02C;
 int unk030;
 int unk034;
 int unk038;
 int unk03C;
 int unk040;
 int unk044;
 int unk048;
 int unk04C;
 int unk050;
 int unk054;
 int unk058;
 int unk05C;
 int unk060;
 int unk064;
 int unk068;
 int unk06C;
 int unk070;
 int unk074;
 int unk078;
 int unk07C;
 int unk080;
 int unk084;
 int unk088;
 int unk08C;
 int unk090;
 int unk094;
 int unk098;
 int unk09C;
 int unk0A0;
 int unk0A4;
 int unk0A8;
 int unk0AC;
 int unk0B0;
 int unk0B4;
 int unk0B8;
 int unk0BC;
 int unk0C0;
 int unk0C4;
 int unk0C8;
 int unk0CC;
 int unk0D0;
 int unk0D4;
 int unk0D8;
 int unk0DC;
 int unk0E0;
 int unk0E4;
 int unk0E8;
 int unk0EC;
 int unk0F0;
 int unk0F4;
 int unk0F8;
 int unk0FC;
 int unk100;
 int unk104;
 int unk108;
 int unk10C;
 int unk110;
 int unk114;
 int unk118;
 int unk11C;
 int unk120;
 int unk124;
 int unk128;
 int unk12C;
 int unk130;
 int unk134;
 int unk138;
 int unk13C;
 int unk140;
 int unk144;
 int unk148;
 int unk14C;
 int unk150;
 int unk154;
 int unk158;
 int unk15C;
 int unk160;
 int unk164;
 int unk168;
 int unk16C;
 int unk170;
 int unk174;
 int unk178;
 int unk17C;
 int unk180;
 int unk184;
 int unk188;
 int unk18C;
 int unk190;
 int unk194;
 int unk198;
 int unk19C;
 int unk1A0;
 int unk1A4;
 int unk1A8;
 int unk1AC;
 int unk1B0;
 int unk1B4;
 int unk1B8;
 int unk1BC;
 int unk1C0;
 int unk1C4;
 int unk1C8;
 int unk1CC;
 int unk1D0;
 int unk1D4;
 int unk1D8;
 int unk1DC;
 int unk1E0;
 int unk1E4;
 int unk1E8;
 int unk1EC;
 int unk1F0;
 int unk1F4;
 int unk1F8;
 int unk1FC;
 int unk200;
 int unk204;
 int unk208;
 int unk20C;
 int unk210;
 int unk214;
 int unk218;
 int unk21C;
 int unk220;
 int unk224;
 int unk228;
 int unk22C;
 int unk230;
 int unk234;
 int unk238;
 int unk23C;
 int unk240;
 int unk244;
 int unk248;
 int unk24C;
 int unk250;
 int unk254;
 int unk258;
 int unk25C;
 int unk260;
 int unk264;
 int unk268;
 int unk26C;
 int unk270;
 int unk274;
 int unk278;
 int unk27C;
 int unk280;
 int unk284;
 int unk288;
 int unk28C;
 int unk290;
 int unk294;
 int unk298;
 int unk29C;
 int unk2A0;
 int unk2A4;
 int unk2A8;
 int unk2AC;
 int unk2B0;
 int unk2B4;
};
__declspec(thread) AudioTlsState threadData;
struct MemoryScope {
 int previous;
 MemoryScope() {previous=threadData.unk2B4;threadData.unk2B4=16;}
 ~MemoryScope() {threadData.unk2B4=previous;}
};
NiPoint3& HK2NINS(NiPoint3&,const hkVector4&);
char* NiGetViewerString_00a7d550(const char*,float);
char* NiGetViewerString_00a7d5e0(const char*,const char*);
struct Strings {
 void* unk00; char** unk04;
 unsigned short unk08,unk0A,unk0C,unk0E;
 void FUN_0096ad30(unsigned);
 void FUN_0096ae90(unsigned,char*&);
 void Append(char* text) {
  unsigned n=unk0A;
  if(n>=unk08) FUN_0096ad30(n+unk0E);
  FUN_0096ae90(n,text);
 }
};
struct Constraint {
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
 hkVector4 unk30;
 hkVector4 unk40;
 hkVector4 unk50;
 hkVector4 unk60;
 int unk70;
 int unk74;
 int unk78;
 int unk7C;
 int unk80;
 int unk84;
 int unk88;
 int unk8C;
 hkVector4 unk90;
 unsigned short unkA0; unsigned char unkA2,unkA3;
 int unkA4;
 int unkA8;
 float unkAC;
 int unkB0;
 int unkB4;
 int unkB8;
 float unkBC;
 int unkC0;
 float unkC4;
 float unkC8;
};
struct Owner {
 int unk00; Constraint* unk04;
 void hkConstraintCinfo_GetViewerStrings(Strings*);
 void AppendConstraintToStrings(Strings*);
};
class hkRefObjCBFB {
public:
    virtual ~hkRefObjCBFB() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkRefObjCBFB() { m_sReferenceCount = 1; }
};
class hkListenerACBFB {
public:
    virtual void a0() = 0;
};
class hkListenerBCBFB {
public:
    virtual void b0() = 0;
};
class hkListenerCCBFB {
public:
    virtual void c0() = 0;
};
class hkListenerDCBFB {
public:
    virtual void d0() = 0;
};

// Reconstructed ClearIndexedValues (FNV 1.4.0.525, /MT /O2 /GS /EHsc /Gy).
// Stand-in declarations; unknown fields are named by their byte offset.
// External callees keep the pack's FUN_ names and bind through relocations.
struct Tls676 { char m_pad0000[0x2b4]; int m_2b4; };
__declspec(thread) Tls676 g_tls676;
struct Elem676;
struct Sub676 { char m_pad0000[0x14]; unsigned char m_14; };
struct Elem676 { char m_pad0000[0xc]; Sub676* m_iThirdValue; void removeReference(); };
struct Q676 {
    void hkpWorld_addPhantomBatch(Elem676** arr, int count);
    void hkpWorld_removePhantom(Elem676* e);
};
struct GC676 { void* m_p; int m_unused; };
struct Tmp676 { float m_f; unsigned char b0, b1, b2, b3, b4; };
struct GCObj676 {
    virtual void *g00(void*);
    virtual void *g01(void*);
    virtual void *g02(void*);
    virtual void *g03(void*);
    virtual void *g04(void*);
    virtual void *g05(void*);
    virtual void *g06(void*);
    virtual void *g07(void*);
    virtual void *g08(void*);
    virtual void *g09(void*);
    virtual void *g10(void*);
    virtual void *g11(void*);
    virtual void *g12(void*);
    virtual void *g13(void*);
    virtual void *g14(void*);
    virtual void *g15(void*);
    virtual void *g16(void*);
    virtual void *g17(void*);
    virtual void *g18(void*);
    virtual void *g19(void*);
    virtual void *g20(void*);
    virtual void *g21(void*);
    virtual void *g22(void*);
    virtual void *g23(void*);
    virtual void *g24(void*);
    virtual void *g25(void*);
    virtual void *g26(void*);
    virtual void *g27(void*);
    virtual void *g28(void*);
    virtual void *g29(void*);
    virtual void *g30(void*);
    virtual void *g31(void*);
    virtual void *g32(void*);
    virtual void *g33(void*);
    virtual void *g34(void*);
    virtual void *g35(void*);
    virtual void g36(void*);
};
struct This676 {
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
    virtual void v35();
    virtual void v36();
    virtual void* v37();
    char m_pad0004[0x30];
    Elem676** m_aiIndexedValues;              // +0x34
    unsigned int m_uiItemCount;         // +0x38
    void ClearIndexedValues();
};
// Scoped override of the thread-local context field (0x10 during the operation).
struct Guard676 {
    int m_saved;
    Guard676() { m_saved = g_tls676.m_2b4; g_tls676.m_2b4 = 0x10; }
    ~Guard676() { g_tls676.m_2b4 = m_saved; }
};
extern GC676* bhkWorldObject_GetProperty(GC676* out, Elem676* obj, void* rtti);
extern void* FUN_00ec61c0(void* dst, int value, unsigned int size);
extern unsigned char DAT_01267b70;
struct BoolC68BF0 {
    char m_cBooleanValue;
};
struct HkEntityC68BF0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int m_uiValue1;
};
struct EntityC68BF0;
struct HkWorldC68BF0 {
    BoolC68BF0 ProcessTarget(EntityC68BF0* pkEntity);
};
struct EntityC68BF0 {
    void FUN_00c90510();
    int unk00;
    int unk04;
    int unk08;
    HkEntityC68BF0* m_pkHkEntity;
};
struct WorldC68BF0 {
    virtual void v00();
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
    virtual HkWorldC68BF0* GetHavokWorld();
    void ProcessPendingItems();
    void ReleaseBodies();
    void ClearReferences();
    void FlushEntries();
    bool bhkWorld_Remove(EntityC68BF0* pkEntity);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned int m_uiBatchDepth;
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
    EntityC68BF0** m_ppkPendingAdds;
    unsigned int m_uiNumPendingAdds;
};
struct FUN_00c91000_Class
{
    LocalM128 m_iWordAt00;
    LocalM128 m_10;

    void __thiscall UpdateFields_00c91000(const LocalM128* value);
};
struct FUN_00c91620_Target;
struct FUN_00c91620_Args {
    unsigned char type;
    FUN_00c91620_Target* target;
};
struct FUN_00c91620_Aux {
    void* m_00; void* m_04; void* m_08; void* m_0c;
    void* m_10; void* m_14; void* m_18; void* m_1c; void* m_20;
    void FreeStorage();
};
struct FUN_00c91620_Target {
    virtual void vf00(); virtual void vf04(); virtual void vf08();
    virtual void vf0c(); virtual void vf10(); virtual void vf14();

    unsigned short m_04;
    void* m_08; void* m_0c; void* m_10; void* m_14;
    void* m_18; void* m_1c; void* m_20; void* m_24;
    void* m_28; void* m_2c;
    FUN_00c91620_Aux m_30;
    int m_54;

    void FUN_00c905b0();
};
struct FUN_00c91620_Class {
    void* m_00; void* m_04; void* m_08; void* m_0c;
    void* m_10; void* m_14; void* m_18; void* m_1c;
    void* m_20; void* m_24; void* m_28; void* m_2c;
    void* m_30; void* m_34; void* m_38; void* m_3c;
    void* m_40; void* m_44; void* m_48; void* m_4c;
    void* m_50; void* m_54; void* m_58; void* m_5c;
    void* m_60; void* m_64; void* m_68; void* m_6c;
    void* m_70; void* m_74; void* m_78; void* m_7c;
    void* m_80; void* m_84; void* m_88; void* m_8c;
    void* m_90;
    int m_94;
    void* m_98;
    unsigned char m_9c;
    unsigned char m_9d;
    void* m_a0;
    int m_a4;
    void hkpWorld_queueOperation(FUN_00c91620_Args* args);
    void FUN_00c91120();
    void UpdateFields_00c91140();
    unsigned char* ProcessTarget(unsigned char* result, FUN_00c91620_Target* target);
};
void __cdecl hkpWorldOperationUtil_removeEntityBP(FUN_00c91620_Class* self, FUN_00c91620_Target* target);
void __cdecl hkpWorldCallbackUtil_fireEntityRemoved(FUN_00c91620_Class* self, FUN_00c91620_Target* target);
void __cdecl hkpEntityCallbackUtil_fireEntityRemoved(FUN_00c91620_Target* target);
void __cdecl hkpWorldOperationUtil_removeEntitySI(FUN_00c91620_Class* self, FUN_00c91620_Target* target);

class hkWorldXc91700 {
public:
    int unk000[71];
    hkArray<void*> m_entries;

    void hkpWorld_removeActionListener(void* entry);
};

class hkWorldC9175 {
public:
    int unk000[80];
    hkArray<void*> m_entries;

    void hkpWorld_removeConstraintListener(void* entry);
};

class hkWorldC917 {
public:
    int unk000[74];
    hkArray<void*> m_entries;

    void hkpWorld_removeEntityListener(void* entry);
};

class hkWorldC91F {
public:
    int unk000[77];
    hkArray<void*> m_entries;

    void hkpWorld_removePhantomListener(void* entry);
};

class hkWorldC918 {
public:
    int unk000[95];
    hkArray<void*> m_entries;

    void hkpWorld_removeWorldPostCollideListener(void* entry);
};

class hkWorldXc91930 {
public:
    int unk000[92];
    hkArray<void*> m_entries;

    void hkpWorld_removeWorldPostIntegrateListener(void* entry);
};

class hkWorldXc91980 {
public:
    int unk000[101];
    hkArray<void*> m_entries;

    void hkpWorld_removeIslandPostCollideListener(void* entry);
};

class hkWorldXc91a20 {
public:
    int unk000[104];
    hkArray<void*> m_entries;

    void hkpWorld_removeContactListener(void* entry);
};

class hkWorldXc91a70 {
public:
    int unk000[83];
    hkArray<void*> m_entries;

    void hkpWorld_removeWorldDeletionListener(void* entry);
};

class hkWorldXc91ac0 {
public:
    int unk000[107];
    hkArray<void*> m_entries;

    void hkpWorld_removeContactImpulseLimitBreachedListener(void* entry);
};
struct Allocator {
    virtual void v00();
    virtual void* Allocate(int size);
    virtual void Deallocate(void* p, int size);
};
struct ThreadStorage {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Allocator* m_pThreadAllocator;
};
void* hkMemoryRouter_getInstance();
int __fastcall hkSemaphore_acquire(void*);
struct JobHeader {
    unsigned char m_eJobType;
    unsigned char m_ucSubType;
    unsigned char m_executionFlags;
    unsigned char unk03;
    unsigned short m_jobSize;
    short m_iAffinity;

    JobHeader(unsigned char type, unsigned char subType, unsigned short size, short affinity = -1)
        : m_eJobType(type), m_ucSubType(subType), m_jobSize(size), m_iAffinity(affinity) {}
};
struct RayCastCommand {
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    int m_uiFilterInfo;
    int m_ulUserData;
    void* m_pResultBuffer;
    int m_iResultCount;
    int m_iResultCapacity;
    int unk34;
    int unk38;
    int unk3C;
};
struct JobDoneHeader {
    int m_iJobId;
    int unk04;
    int unk08;
    int unk0C;
};
struct JobBase {
    JobHeader m_kHeader;
    int unk08;
    int unk0C;
    void* m_pCompletionSemaphore;
    JobDoneHeader* m_pJobDoneHeader;
    int unk18;

    __forceinline JobBase(unsigned char subType, unsigned short size)
        : m_kHeader(1, subType, size)
    {
        unk18 = 0;
        m_kHeader.m_executionFlags = 1;
    }
};
__declspec(align(16)) struct Job : JobBase {
    void* m_pCollisionInput;
    int m_iFirstIndex;
    RayCastCommand* m_pCommands;
    int m_iCommandCount;
    int unk2C;
    int unk30;
    void* m_pJobSemaphore;
    int unk38;
    void* m_kdTreeUnk0C;
    void* m_kdTreeUnk10;
    int unk44;
    int unk48;
    int unk4C;

    __forceinline Job(void* input, JobDoneHeader* jobHeader, RayCastCommand* commandArray, int numCommands, void* broadphase, void* semaphore)
        : JobBase(3, sizeof(Job))
    {
        m_pJobDoneHeader = jobHeader;
        m_pCollisionInput = input;
        m_pCompletionSemaphore = semaphore;
        m_iFirstIndex = sizeof(RayCastCommand);
        m_pCommands = commandArray;
        m_iCommandCount = numCommands;
        m_pJobSemaphore = broadphase;
        m_pJobDoneHeader->m_iJobId = (numCommands == 0) ? 1 : (numCommands - 1) / 64 + 1;
        unk38 = 0;
        m_kdTreeUnk0C = 0;
        m_kdTreeUnk10 = 0;
        unk2C = 0;
        unk30 = 0;
    }
};
struct JobQueue {
    void AddObjectCopy(const Job& job, int priority);
};
struct ThreadPool {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void processWork(JobQueue* queue, int type);
    virtual void RunWorkerThread();
};
struct KdTreeManager {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual bool isTreeActive();
    int unk04;
    int unk08;
    void* m_treeData0C;
    void* m_treeData10;
};
struct hkpWorldHelper : hkpWorld {
    void ExecuteRayCastJobs(RayCastCommand* commandArray, int numCommands, JobQueue* jobQueue, ThreadPool* threadPool, void* semaphore, int numCommandsPerJob);
};
extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern unsigned int DAT_0126835c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned int);
extern const char str_010c64b8[];
extern const char str_010c41f8[];
extern void* DAT_010c6488;
extern float DAT_0104da4c;


struct __declspec(align(16)) LinearCaster {
    void* unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    float unk80;
    void ComputeValues_00cfaed0(void*,void*,void*,void*,void*,int,int,void*,void*);
};
struct QueryTree {
    virtual void slot00(); virtual void slot04(); virtual void slot08(); virtual void slot0C();
    virtual bool enabled();
    virtual void slot14(); virtual void slot18(); virtual void slot1C();
    virtual void cast(void*,void*,void*,void*,int,void*,void*);
};
struct CollisionInput {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    int unk70;
};
struct WorldQuery : hkpWorld { void hkpWorld_linearCast(void*,void*,void*,void*); };
extern "C" void __cdecl enumerateAllConstraintsInIsland(void* object, void* value);
struct zzVal_c92860 { void* v; };
static void InvokeOnAllOwners(FUN_00c928c0_Context* ctx, zzVal_c92860 value);
FUN_00c928c0_Context* volatile zz_ctx_c92860 = 0;
void* volatile zz_val_c92860 = 0;
void zz_call_c92860(void);
void __cdecl hkSmallArrayUtil__reserveMore(void* apvArray, int iSizeElem);
class EntityC92B;
class IslandC92B {
public:
    void RemoveEntry(EntityC92B* pkEntity);
    void AddItem(EntityC92B* pkEntity);
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned short m_usStorageIndex;
    unsigned short unk22;
    int unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44;
    int** m_pEntities;
};
class EntityC92B {
public:
    int unk00, unk04, unk08;
    IslandC92B* m_pSimulationIsland;
};

class WorldC92B {
public:
    int unk00[0xcc / 4];
    IslandC92B* m_pFixedIsland;
    int unkD0[(0xe8 - 0xd0) / 4];
    unsigned char m_iMaxEntriesPerNarrowphaseToiTask;
    unsigned char unkE9[0x208 - 0xe9];
    hkSmallArray<EntityC92B*> m_kActorEntries;
};
class ListenerC92B {
public:
    void hkpWorld_attachActionToEntity(EntityC92B* pkEntity, WorldC92B* pkWorld);
};
void __cdecl hkpWorldOperationUtil_mergeIslands(ListenerC92B* pkThis, WorldC92B* pkWorld, int* pkCurrentObject);
class FUN_00c905b0_s {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    void FUN_00c905b0();
};
class ActionC92C : public FUN_00c905b0_s {
public:
    void* m_pOwningWorld;

    void hkpPhantom_firePhantomRemoved();
};

class WorldC92C;
void __cdecl hkpWorldCallbackUtil_firePhantomRemoved(WorldC92C* pkWorld, ActionC92C* pkAction);
void __cdecl hkpWorldOperationUtil_removePhantomBP(WorldC92C* pkWorld, ActionC92C* pkAction);
struct RemoveActionOpC92C {
    unsigned char m_type;
    ActionC92C* m_pAction;
};
class WorldC92C {
public:
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C;
    int unk030, unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080, unk084, unk088;
    int m_iPendingOperationCount;
    int m_iQueuedOperationCount;
    int m_iCriticalOperationsLockCount;
    int m_iCriticalOperationsLockCountForPhantoms;
    bool m_bBlockExecutingPendingOperations;
    char unk09D[3];
    int unkA0;
    int m_iPendingOperationQueueCount;
    int unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC, unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4;
    int unk0D8, unk0DC, unk0E0, unk0E4, unk0E8, unk0EC, unk0F0, unk0F4, unk0F8, unk0FC, unk100, unk104;
    int unk108, unk10C;
    hkArray<ActionC92C*> m_ppActions;

    bool areCriticalOperationsLocked() const
    {
        return m_iCriticalOperationsLockCount + m_iCriticalOperationsLockCountForPhantoms != 0;
    }
    void lockCriticalOperations() { m_iCriticalOperationsLockCount++; }
    void unlockCriticalOperations()
    {
        if (--m_iCriticalOperationsLockCount == 0 && !m_bBlockExecutingPendingOperations) {
            if (m_iPendingOperationCount)
                FUN_00c91120();
            if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount)
                UpdateFields_00c91140();
        }
    }
    void FUN_00c91120();
    void UpdateFields_00c91140();
    void hkpWorld_queueOperation(const RemoveActionOpC92C& kOp);
    void hkpWorld_removePhantom(ActionC92C* pkAction);
};
template <int SIZE>
__forceinline void memCpyOneAlignedXc937a0(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}

namespace hkRouterXc937a0 {
    extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();
}
void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);

class hkOwnerXc937a0 {
public:
    int unk00[71];
    hkArray<void*> m_kNode;

    void hkpWorld_addActionListener(void* item);
};


hkMemoryRouter& __cdecl GetMemoryRouterC93() throw();


template <typename T> struct hkRefPtrC93 {
    __forceinline ~hkRefPtrC93() throw()
    {
        if (m_pRetainedObject) m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
    __forceinline void operator=(T* e) throw()
    {
        if (e) e->RetainReference();
        if (m_pRetainedObject) m_pRetainedObject->removeReference();
        m_pRetainedObject = e;
    }
    T* m_pRetainedObject;
};
class WorldDeletableC93 {
public:
    virtual ~WorldDeletableC93() throw();
};
struct ChunkBufferC93 {
    __forceinline ~ChunkBufferC93() throw()
    {
        if (m_pBuffer) GetMemoryRouterC93().heap().blockFree(m_pBuffer, 0x200);
    }
    void* m_pBuffer;
};
struct MtSimulationJobDataC93 {
    __forceinline void operator delete(void* p) throw() { if (p) GetMemoryRouterC93().heap().blockFree(p, sizeof(MtSimulationJobDataC93)); }
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    ChunkBufferC93 m_kBuffer;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
};
struct CollisionAgentConfigC93 {
    __forceinline void operator delete(void* p) throw() { if (p) GetMemoryRouterC93().heap().blockFree(p, sizeof(CollisionAgentConfigC93)); }
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};
struct ProcessCollisionInputC93 {
    __forceinline void operator delete(void* p) throw() { if (p) GetMemoryRouterC93().heap().blockFree(p, sizeof(ProcessCollisionInputC93)); }
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    ChunkBufferC93 m_kBuffer;
    unsigned int unk68;
    unsigned int unk6c;
    CollisionAgentConfigC93* m_pConfiguration;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
};

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(BSThreadCriticalSectionPC* pkSection);
struct CriticalSectionC93 {
    __forceinline void operator delete(void* p) throw() { if (p) GetMemoryRouterC93().heap().blockFree(p, sizeof(CriticalSectionC93)); }
    __forceinline ~CriticalSectionC93() throw() { DeleteCriticalSection(&m_kCriticalSection); }
    BSThreadCriticalSectionPC m_kCriticalSection;
};
struct BroadPhaseDispatcherC93 {
    __forceinline void operator delete(void* p) throw() { if (p) GetMemoryRouterC93().heap().blockFree(p, sizeof(BroadPhaseDispatcherC93)); }
    ~BroadPhaseDispatcherC93() throw();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
};
struct WorldOperationQueueC93 {
    __forceinline void operator delete(void* p) throw() { if (p) GetMemoryRouterC93().heap().blockFree(p, sizeof(WorldOperationQueueC93)); }
    ~WorldOperationQueueC93() throw();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
};
struct ViolatedConstraintArrayC93 {
    __forceinline void operator delete(void* p) throw() { if (p) GetMemoryRouterC93().heap().blockFree(p, sizeof(ViolatedConstraintArrayC93)); }
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
};

class FUN_00c93e50 : public hkReferencedObject {
public:
    virtual ~FUN_00c93e50() throw();
    void hkpWorld_removeAll() throw();
    hkBool IsEntityAdded(void* pkEntity) throw();

    hkReferencedObject* m_pSimulation;
    unsigned int unk0c;
    float m_gravityX;
    float m_gravityY;
    float m_gravityZ;
    float m_gravityW;
    WorldDeletableC93* m_pFixedIsland;
    void* m_pFixedRigidBody;
    hkArray<void*> m_kActiveSimulationIslands;
    hkArray<void*> m_kInactiveSimulationIslands;
    hkArray<void*> m_kDirtySimulationIslands;
    hkReferencedObject* m_pMaintenanceManager;
    hkRefPtrC93<hkReferencedObject> m_pMemoryWatchDog;
    bool m_bAssertOnRunningOutOfSolverMemory;
    hkReferencedObject* m_pJobSemaphore;
    hkReferencedObject* m_pKdTreeManager;
    bool m_bUseKdTree;
    BroadPhaseDispatcherC93* m_pBroadPhaseDispatcher;
    WorldDeletableC93* m_pPhantomBroadPhaseListener;
    WorldDeletableC93* m_pEntityEntityBroadPhaseListener;
    WorldDeletableC93* m_pBroadPhaseBorderListener;
    MtSimulationJobDataC93* m_pMultithreadedSimulationJobData;
    ProcessCollisionInputC93* m_pCollisionInput;
    hkReferencedObject* m_pCollisionFilter;
    hkReferencedObject* m_pDispatcher;
    hkReferencedObject* m_pConvexListCollisionFilter;
    WorldOperationQueueC93* m_pPendingOperations;
    int m_iPendingOperationCount;
    int m_iQueuedOperationCount;
    int m_iCriticalOperationsLockCount;
    int m_iCriticalOperationsLockCountForPhantoms;
    bool m_bBlockExecutingPendingOperations;
    bool m_bBlockExecutingPendingOperationQueues;
    void* m_pPendingOperationQueues;
    int m_iPendingOperationQueueCount;
    unsigned int m_multiThreadCheckThreadId;
    unsigned int m_multiThreadCheckMarks;
    bool m_bProcessActionsInSingleThread;
    bool m_bAllowUnconstrainedIslandJob;
    unsigned int m_uiMinDesiredIslandSize;
    CriticalSectionC93* m_pModifyConstraintCriticalSection;
    int m_iIsLocked;
    CriticalSectionC93* m_pIslandDirtyListCriticalSection;
    CriticalSectionC93* m_pPropertyMasterLock;
    bool m_bWantSimulationIslands;
    float m_fSnapCollisionToConvexEdgeThreshold;
    float m_fSnapCollisionToConcaveEdgeThreshold;
    bool m_bEnableToiWeldRejection;
    bool m_bWantDeactivation;
    bool m_bActivateOnBodyTransformChange;
    float m_fDeactivationReferenceDistance;
    float m_fToiCollisionResponseRotateNormal;
    int m_iMaxSectorsPerMidphaseTask;
    bool m_bProcessToisMultithreaded;
    int m_iMaxSectorsPerNarrowphaseTask;
    int m_iMaxEntriesPerMidphaseToiTask;
    int m_iMaxEntriesPerNarrowphaseToiTask;
    float m_fSimplifiedToiPenetrationThreshold;
    float m_fToiPenetrationThreshold;
    float m_fHigherToiPenetrationThreshold;
    float m_fForcedToiPenetrationThreshold;
    unsigned int m_uiLastEntityUid;
    unsigned int m_uiLastIslandUid;
    unsigned int m_uiLastConstraintUid;
    hkArray<void*> m_kPhantoms;
    hkArray<void*> m_kActionListeners;
    hkArray<void*> m_kEntityListenerArray;
    hkArray<void*> m_kPhantomListeners;
    hkArray<void*> m_kConstraintListeners;
    hkArray<void*> m_kWorldDeletionListeners;
    hkArray<void*> m_kIslandActivationListeners;
    hkArray<void*> m_kWorldPostSimulationListeners;
    hkArray<void*> m_kWorldPostIntegrateListeners;
    hkArray<void*> m_kWorldPostCollideListeners;
    hkArray<void*> m_kIslandPostIntegrateListeners;
    hkArray<void*> m_kIslandPostCollideListeners;
    hkArray<void*> m_kContactListeners;
    hkArray<void*> m_kContactImpulseLimitBreachedListeners;
    ViolatedConstraintArrayC93* m_pViolatedConstraintArray;
    hkReferencedObject* m_pBroadPhaseBorder;
};
void __cdecl ClearSlotReference(FUN_00c93e50* pkWorld, WorldDeletableC93* pkIsland) throw();
void __cdecl hkpWorldCallbackUtil_fireWorldDeleted(FUN_00c93e50* pkWorld) throw();


hkMemoryRouter& __cdecl GetMemoryRouterC97() throw();

struct hkSmallArrayUtilC97 {
    static void __cdecl GrowArray(void* apvArray, int iSizeElem) throw();
};

struct hkWorldOperationC97 {
    enum Type { ADD_ACTION = 0xa };
    struct TypeTag {
        TypeTag(Type eType) : m_type(static_cast<unsigned char>(eType)) {}
        unsigned char m_type;
    };
    struct AddActionCommand : public TypeTag {
        AddActionCommand() : TypeTag(ADD_ACTION) {}
        hkpAction* m_pAction;
    };
};
namespace hkRouterC97E {
    extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();
}
class hkRefObjC97E {
public:
    virtual ~hkRefObjC97E();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static void* operator new(unsigned int nbytes)
    {
        hkRefObjC97E* b = static_cast<hkRefObjC97E*>(hkRouterC97E::hkMemoryRouter_getInstance().heap().blockAlloc(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
};
struct InfoC97E {
    int unk00;
    int unk04;
    int m_08;
};
class FUN_00cf3ea0 : public hkRefObjC97E {
public:
    int unk08[9];
    int m_2c;
    int unk30[2];

    FUN_00cf3ea0(void* a1, void* a2, InfoC97E* a3, bool a4) throw();
};
class FUN_00c97e30_C {
public:
    void hkpWorld_addConstraint(FUN_00cf3ea0* p);
    FUN_00cf3ea0* Create(void* a1, void* a2, InfoC97E* a3);
};
struct C97E80PendingOperation {
    unsigned char m_type;
    void* m_pAction;
};
struct C97E80Action {
    virtual void function00();
    virtual void function04();
    virtual void function08();
    virtual void function0C();
    virtual void function10();
    virtual void function14();
    virtual int getReferenceCount();
    unsigned int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    void* m_owner44;
};
struct C97E80Owner {
    int unk00, unk04;
    hkpWorld* m_pOwningWorld;
};
struct C97E80PendingShell {
    void __thiscall hkpWorld_queueOperation(C97E80PendingOperation* operation);
};
struct C97E80RemoveShell {
    void __thiscall RemoveActionFromWorld(void* owner);
};
struct C97E80ActionChangeShell {
    void __thiscall RemoveReferenceFromSlots(hkpWorld* world);
};
struct C97E80ReleaseShell {
    void __thiscall FUN_00c905b0();
};
struct C97E80CleanupShell {
    void __thiscall FUN_00c91120();
    void __thiscall UpdateFields_00c91140();
};
void __cdecl hkpWorldOperationUtil_removeConstraintImmediately(hkpWorld* world, C97E80Action* action, int flags);
struct C97E80Return { bool m_iResultCode; };
struct C97E80World : hkpWorld {
    C97E80Return __thiscall hkpWorld_removeConstraint(C97E80Action* action);
};
float __cdecl NiMax(float fA, float fB);
struct __declspec(align(16)) FUN_00c987e0_Pose {
    hkVector4 translation;
    hkQuaternion rotation;
    hkVector4 scale;
    void SetFromInput_Thunk(int a1);
};
struct __declspec(align(16)) EC98BE0Vector {
    float x;
    float y;
    float z;
    float w;
    void __thiscall FUN_00c7f7a0(int a, int b);
};
struct __declspec(align(16)) FUN_00c7f640_Class {
    void setTransformedPos_00c7f640(const void* m, const void* p);
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

class hkListenerListC995 {
public:
    int unk00;
    int unk04;
    hkArray<void*> m_kListeners;
    void* m_pWorldLock;

    void RemoveListener(void* listener);
};
class Ce52e0Helper
{
public:
    void SetFromInput(int*, int);
    void SetFromInput_Thunk(int a);
};
class FlagState {
public:
    unsigned int unk00, unk04;
    unsigned char unk08, state;
    unsigned short first, second;
    void SetFlagBits(unsigned int a, unsigned int b, int code);
};
struct OverlapResult {
    char value;
    OverlapResult() {}
};
struct OverlapPhantom;
struct OverlapCollidable {
    int unk00, unk04, unk08, unk0c;
    signed char ownerOffset;
    char unk11, unk12, unk13;
    int unk14;
    char type;
    OverlapPhantom* owner() {
        return reinterpret_cast<OverlapPhantom*>(reinterpret_cast<char*>(this) + ownerOffset);
    }
};
struct OverlapPhantom {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void add(OverlapCollidable*);
    virtual OverlapResult overlaps(OverlapCollidable*);
    virtual void remove(OverlapCollidable*);
    int unk04, unk08, unk0c;
    OverlapCollidable collidable;
};
struct OverlapFilter {
    virtual void v00();
    virtual OverlapResult enabled(OverlapCollidable*, OverlapCollidable*);
};
struct OverlapContext {
    int unk00, unk04;
    OverlapFilter filter;
};
static void SyncOverlap(OverlapPhantom* phantom, OverlapCollidable* other, OverlapContext* context);
OverlapPhantom* volatile overlapPhantom;
OverlapCollidable* volatile overlapOther;
OverlapContext* volatile overlapContext;
void invokeOverlap();
void nullsub_6();
void __cdecl hkpWorld_unlockReadOnly(void);
namespace c912 {
struct Alloc {
    virtual void vfn0();
    virtual void* AllocateMemoryBlock(int n);
};
}
namespace c912 { inline hkMemoryRouter* router() { return (hkMemoryRouter*)hkMemoryRouter_getInstance(); } }
extern int DAT_010c6420;
extern int DAT_010c6378;
struct CFB240ContactMgrFactory {
    virtual ~CFB240ContactMgrFactory();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* operator new(unsigned int n) {
        CFB240ContactMgrFactory* b = static_cast<CFB240ContactMgrFactory*>(c912::router()->heap().blockAlloc(n));
        b->m_usMemSizeAndFlags = (unsigned short)n;
        return b;
    }
    void operator delete(void*) {}
    void removeReference() throw();
    CFB240ContactMgrFactory() throw() { m_sReferenceCount = 1; }
};
struct FUN_00cfd450 : CFB240ContactMgrFactory {
    int unk08;
    FUN_00cfd450(void*) throw();
};
struct FUN_00cfca20 : CFB240ContactMgrFactory {
    int unk08;
    FUN_00cfca20(void*) throw();
};
struct OtherC912 {
    void* vtable; short unknown; short refs; int kind;
    OtherC912() throw() { refs = 1; kind = 3; vtable = &DAT_010c6378; }
};
struct FactoryThreeC912 : CFB240ContactMgrFactory {
    OtherC912 other;
    virtual ~FactoryThreeC912();
    FactoryThreeC912() throw()
    {
    }
};
struct CFB240Dispatcher {
    void SetContactMgrFactory(CFB240ContactMgrFactory*, int);
};
static void RegisterContactMgrFactories(CFB240Dispatcher* dispatcher, void* world);
void c912e0_caller(CFB240Dispatcher* d, void* w);
struct Shape64 {};
struct Container64 {
    void __thiscall AddShape(Shape64* shape);
};
struct Shape64List {
    Shape64** data;
    int count;
};
struct Element64 {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14;
    int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44;
    Shape64List shapes;
};
struct Context64 {
    int unk00; int unk04; int unk08; int unk0C; int unk10;
    int unk14; int unk18; int unk1C; int unk20; int unk24;
    Element64** elements;
    int elementCount;
};
unsigned char* __cdecl CollectShapes(unsigned char* result, Context64* context, Container64* volatile container);
struct BorderSet {
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    hkpPhantom* p18;
    hkpPhantom* p1c;
    hkpPhantom* p20;
    hkpPhantom* p24;
    hkpPhantom* p28;
    hkpPhantom* p2c;
};
struct PhantomWorld : hkpWorld {
    BorderSet* GetValue();
};
struct PhantomSink {
    void hkpPhysicsSystem_addPhantom(hkpPhantom* p);
};
static void enumerateAllPhantomsInWorld(PhantomWorld* world, PhantomSink* out);
PhantomWorld* volatile g_world;
PhantomSink* volatile g_out;
void invokePhantomCopy();

__forceinline void timer(const char* name, const char* first = 0) {
    hkMonitorStream* stream = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    char* current = stream->m_end.m_storage;
    if (current < stream->m_capacityMinus16.m_storage) {
        volatile hkMonitorStream::TimerCommand* record = (volatile hkMonitorStream::TimerCommand*)current;
        record->m_commandAndMonitor = name;
        if (first) *(const char* volatile*)(current + sizeof(hkMonitorStream::TimerCommand)) = first;
        _ReadWriteBarrier();
        volatile unsigned int stamp = (unsigned int)__rdtsc();
        record->m_time0 = stamp;
        stream->m_end.m_storage = current + (first ? 16 : 12);
    }
}
struct CollisionObject;
struct BroadphaseHandle {
    unsigned int id;
    unsigned char type;
    signed char ownerOffset;
    signed char quality;
    unsigned char flags;
};
struct CollisionObject {
    unsigned int shape;
    unsigned int shapeKey;
    unsigned int motion;
    unsigned int parent;
    signed char ownerOffset;
    unsigned char forceCollideOntoPpu;
    unsigned short shapeSize;
    BroadphaseHandle handle;
    unsigned int boundingVolume;
    void UpdateCollisionIndices();
    hkArray<struct CollisionAgentEntry>* hkpLinkedCollidable_getCollisionEntriesDeterministicUnchecked_00d081e0();
};
struct EntityState {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned char tail;
    unsigned char flags;
};
struct CollisionEntity {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    CollisionObject collidable;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    EntityState* state;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned char type;
};
struct FilterBool {
    char value;
    FilterBool() {}
    FilterBool(bool enabled) : value(enabled) {}
};
struct PhantomInterface {
    virtual void unused00(); virtual void unused04();
    virtual void unused08(); virtual void unused0c();
    virtual void unused10(); virtual void unused14();
    virtual void unused18();
    virtual void addOverlap(CollisionObject*);
    virtual FilterBool hasOverlap(CollisionObject*);
    virtual void removeOverlap(CollisionObject*);
    virtual void unused28(); virtual void unused2c();
    virtual void refresh();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    CollisionObject collidable;
};
struct OverlapPair { BroadphaseHandle* first; BroadphaseHandle* second; OverlapPair() {} };
struct PairArray {
    OverlapPair* data;
    int size;
    int capacityAndFlags;
    OverlapPair storage[128];
    __forceinline void init() { data = storage; size = 0; capacityAndFlags = 0x80000080; }
};
struct Broadphase {
    virtual void unused00(); virtual void unused04();
    virtual void unused08(); virtual void unused0c();
    virtual void unused10(); virtual void unused14();
    virtual void unused18(); virtual void unused1c();
    virtual void unused20(); virtual void unused24();
    virtual void unused28(); virtual void unused2c();
    virtual void unused30(); virtual void unused34();
    virtual void unused38(); virtual void unused3c();
    virtual void unused40(); virtual void unused44();
    virtual void query(BroadphaseHandle*, PairArray*);
};
struct CollisionFilterInterface {
    virtual void unused00();
    virtual FilterBool enabled(CollisionObject*, CollisionObject*);
};
struct CollisionFilter {
    unsigned int unk00;
    unsigned int unk04;
    CollisionFilterInterface filter;
};
struct CollisionDispatcher {
    unsigned int unk0000;     unsigned int unk0004;     unsigned int unk0008;     unsigned int unk000C;
    unsigned int unk0010;     unsigned int unk0014;     unsigned int unk0018;     unsigned int unk001C;
    unsigned int unk0020;     unsigned int unk0024;     unsigned int unk0028;     unsigned int unk002C;
    unsigned int unk0030;     unsigned int unk0034;     unsigned int unk0038;     unsigned int unk003C;
    unsigned int unk0040;     unsigned int unk0044;     unsigned int unk0048;     unsigned int unk004C;
    unsigned int unk0050;     unsigned int unk0054;     unsigned int unk0058;     unsigned int unk005C;
    unsigned int unk0060;     unsigned int unk0064;     unsigned int unk0068;     unsigned int unk006C;
    unsigned int unk0070;     unsigned int unk0074;     unsigned int unk0078;     unsigned int unk007C;
    unsigned int unk0080;     unsigned int unk0084;     unsigned int unk0088;     unsigned int unk008C;
    unsigned int unk0090;     unsigned int unk0094;     unsigned int unk0098;     unsigned int unk009C;
    unsigned int unk00A0;     unsigned int unk00A4;     unsigned int unk00A8;     unsigned int unk00AC;
    unsigned int unk00B0;     unsigned int unk00B4;     unsigned int unk00B8;     unsigned int unk00BC;
    unsigned int unk00C0;     unsigned int unk00C4;     unsigned int unk00C8;     unsigned int unk00CC;
    unsigned int unk00D0;     unsigned int unk00D4;     unsigned int unk00D8;     unsigned int unk00DC;
    unsigned int unk00E0;     unsigned int unk00E4;     unsigned int unk00E8;     unsigned int unk00EC;
    unsigned int unk00F0;     unsigned int unk00F4;     unsigned int unk00F8;     unsigned int unk00FC;
    unsigned int unk0100;     unsigned int unk0104;     unsigned int unk0108;     unsigned int unk010C;
    unsigned int unk0110;     unsigned int unk0114;     unsigned int unk0118;     unsigned int unk011C;
    unsigned int unk0120;     unsigned int unk0124;     unsigned int unk0128;     unsigned int unk012C;
    unsigned int unk0130;     unsigned int unk0134;     unsigned int unk0138;     unsigned int unk013C;
    unsigned int unk0140;     unsigned int unk0144;     unsigned int unk0148;     unsigned int unk014C;
    unsigned int unk0150;     unsigned int unk0154;     unsigned int unk0158;     unsigned int unk015C;
    unsigned int unk0160;     unsigned int unk0164;     unsigned int unk0168;     unsigned int unk016C;
    unsigned int unk0170;     unsigned int unk0174;     unsigned int unk0178;     unsigned int unk017C;
    unsigned int unk0180;     unsigned int unk0184;     unsigned int unk0188;     unsigned int unk018C;
    unsigned int unk0190;     unsigned int unk0194;     unsigned int unk0198;     unsigned int unk019C;
    unsigned int unk01A0;     unsigned int unk01A4;     unsigned int unk01A8;     unsigned int unk01AC;
    unsigned int unk01B0;     unsigned int unk01B4;     unsigned int unk01B8;     unsigned int unk01BC;
    unsigned int unk01C0;     unsigned int unk01C4;     unsigned int unk01C8;     unsigned int unk01CC;
    unsigned int unk01D0;     unsigned int unk01D4;     unsigned int unk01D8;     unsigned int unk01DC;
    unsigned int unk01E0;     unsigned int unk01E4;     unsigned int unk01E8;     unsigned int unk01EC;
    unsigned int unk01F0;     unsigned int unk01F4;     unsigned int unk01F8;     unsigned int unk01FC;
    unsigned int unk0200;     unsigned int unk0204;     unsigned int unk0208;     unsigned int unk020C;
    unsigned int unk0210;     unsigned int unk0214;     unsigned int unk0218;     unsigned int unk021C;
    unsigned int unk0220;     unsigned int unk0224;     unsigned int unk0228;     unsigned int unk022C;
    unsigned int unk0230;     unsigned int unk0234;     unsigned int unk0238;     unsigned int unk023C;
    unsigned int unk0240;     unsigned int unk0244;     unsigned int unk0248;     unsigned int unk024C;
    unsigned int unk0250;     unsigned int unk0254;     unsigned int unk0258;     unsigned int unk025C;
    unsigned int unk0260;     unsigned int unk0264;     unsigned int unk0268;     unsigned int unk026C;
    unsigned int unk0270;     unsigned int unk0274;     unsigned int unk0278;     unsigned int unk027C;
    unsigned int unk0280;     unsigned int unk0284;     unsigned int unk0288;     unsigned int unk028C;
    unsigned int unk0290;     unsigned int unk0294;     unsigned int unk0298;     unsigned int unk029C;
    unsigned int unk02A0;     unsigned int unk02A4;     unsigned int unk02A8;     unsigned int unk02AC;
    unsigned int unk02B0;     unsigned int unk02B4;     unsigned int unk02B8;     unsigned int unk02BC;
    unsigned int unk02C0;     unsigned int unk02C4;     unsigned int unk02C8;     unsigned int unk02CC;
    unsigned int unk02D0;     unsigned int unk02D4;     unsigned int unk02D8;     unsigned int unk02DC;
    unsigned int unk02E0;     unsigned int unk02E4;     unsigned int unk02E8;     unsigned int unk02EC;
    unsigned int unk02F0;     unsigned int unk02F4;     unsigned int unk02F8;     unsigned int unk02FC;
    unsigned int unk0300;     unsigned int unk0304;     unsigned int unk0308;     unsigned int unk030C;
    unsigned int unk0310;     unsigned int unk0314;     unsigned int unk0318;     unsigned int unk031C;
    unsigned int unk0320;     unsigned int unk0324;     unsigned int unk0328;     unsigned int unk032C;
    unsigned int unk0330;     unsigned int unk0334;     unsigned int unk0338;     unsigned int unk033C;
    unsigned int unk0340;     unsigned int unk0344;     unsigned int unk0348;     unsigned int unk034C;
    unsigned int unk0350;     unsigned int unk0354;     unsigned int unk0358;     unsigned int unk035C;
    unsigned int unk0360;     unsigned int unk0364;     unsigned int unk0368;     unsigned int unk036C;
    unsigned int unk0370;     unsigned int unk0374;     unsigned int unk0378;     unsigned int unk037C;
    unsigned int unk0380;     unsigned int unk0384;     unsigned int unk0388;     unsigned int unk038C;
    unsigned int unk0390;     unsigned int unk0394;     unsigned int unk0398;     unsigned int unk039C;
    unsigned int unk03A0;     unsigned int unk03A4;     unsigned int unk03A8;     unsigned int unk03AC;
    unsigned int unk03B0;     unsigned int unk03B4;     unsigned int unk03B8;     unsigned int unk03BC;
    unsigned int unk03C0;     unsigned int unk03C4;     unsigned int unk03C8;     unsigned int unk03CC;
    unsigned int unk03D0;     unsigned int unk03D4;     unsigned int unk03D8;     unsigned int unk03DC;
    unsigned int unk03E0;     unsigned int unk03E4;     unsigned int unk03E8;     unsigned int unk03EC;
    unsigned int unk03F0;     unsigned int unk03F4;     unsigned int unk03F8;     unsigned int unk03FC;
    unsigned int unk0400;     unsigned int unk0404;     unsigned int unk0408;     unsigned int unk040C;
    unsigned int unk0410;     unsigned int unk0414;     unsigned int unk0418;     unsigned int unk041C;
    unsigned int unk0420;     unsigned int unk0424;     unsigned int unk0428;     unsigned int unk042C;
    unsigned int unk0430;     unsigned int unk0434;     unsigned int unk0438;     unsigned int unk043C;
    unsigned int unk0440;     unsigned int unk0444;     unsigned int unk0448;     unsigned int unk044C;
    unsigned int unk0450;     unsigned int unk0454;     unsigned int unk0458;     unsigned int unk045C;
    unsigned int unk0460;     unsigned int unk0464;     unsigned int unk0468;     unsigned int unk046C;
    unsigned int unk0470;     unsigned int unk0474;     unsigned int unk0478;     unsigned int unk047C;
    unsigned int unk0480;     unsigned int unk0484;     unsigned int unk0488;     unsigned int unk048C;
    unsigned int unk0490;     unsigned int unk0494;     unsigned int unk0498;     unsigned int unk049C;
    unsigned int unk04A0;     unsigned int unk04A4;     unsigned int unk04A8;     unsigned int unk04AC;
    unsigned int unk04B0;     unsigned int unk04B4;     unsigned int unk04B8;     unsigned int unk04BC;
    unsigned int unk04C0;     unsigned int unk04C4;     unsigned int unk04C8;     unsigned int unk04CC;
    unsigned int unk04D0;     unsigned int unk04D4;     unsigned int unk04D8;     unsigned int unk04DC;
    unsigned int unk04E0;     unsigned int unk04E4;     unsigned int unk04E8;     unsigned int unk04EC;
    unsigned int unk04F0;     unsigned int unk04F4;     unsigned int unk04F8;     unsigned int unk04FC;
    unsigned int unk0500;     unsigned int unk0504;     unsigned int unk0508;     unsigned int unk050C;
    unsigned int unk0510;     unsigned int unk0514;     unsigned int unk0518;     unsigned int unk051C;
    unsigned int unk0520;     unsigned int unk0524;     unsigned int unk0528;     unsigned int unk052C;
    unsigned int unk0530;     unsigned int unk0534;     unsigned int unk0538;     unsigned int unk053C;
    unsigned int unk0540;     unsigned int unk0544;     unsigned int unk0548;     unsigned int unk054C;
    unsigned int unk0550;     unsigned int unk0554;     unsigned int unk0558;     unsigned int unk055C;
    unsigned int unk0560;     unsigned int unk0564;     unsigned int unk0568;     unsigned int unk056C;
    unsigned int unk0570;     unsigned int unk0574;     unsigned int unk0578;     unsigned int unk057C;
    unsigned int unk0580;     unsigned int unk0584;     unsigned int unk0588;     unsigned int unk058C;
    unsigned int unk0590;     unsigned int unk0594;     unsigned int unk0598;     unsigned int unk059C;
    unsigned int unk05A0;     unsigned int unk05A4;     unsigned int unk05A8;     unsigned int unk05AC;
    unsigned int unk05B0;     unsigned int unk05B4;     unsigned int unk05B8;     unsigned int unk05BC;
    unsigned int unk05C0;     unsigned int unk05C4;     unsigned int unk05C8;     unsigned int unk05CC;
    unsigned int unk05D0;     unsigned int unk05D4;     unsigned int unk05D8;     unsigned int unk05DC;
    unsigned int unk05E0;     unsigned int unk05E4;     unsigned int unk05E8;     unsigned int unk05EC;
    unsigned int unk05F0;     unsigned int unk05F4;     unsigned int unk05F8;     unsigned int unk05FC;
    unsigned int unk0600;     unsigned int unk0604;     unsigned int unk0608;     unsigned int unk060C;
    unsigned int unk0610;     unsigned int unk0614;     unsigned int unk0618;     unsigned int unk061C;
    unsigned int unk0620;     unsigned int unk0624;     unsigned int unk0628;     unsigned int unk062C;
    unsigned int unk0630;     unsigned int unk0634;     unsigned int unk0638;     unsigned int unk063C;
    unsigned int unk0640;     unsigned int unk0644;     unsigned int unk0648;     unsigned int unk064C;
    unsigned int unk0650;     unsigned int unk0654;     unsigned int unk0658;     unsigned int unk065C;
    unsigned int unk0660;     unsigned int unk0664;     unsigned int unk0668;     unsigned int unk066C;
    unsigned int unk0670;     unsigned int unk0674;     unsigned int unk0678;     unsigned int unk067C;
    unsigned int unk0680;     unsigned int unk0684;     unsigned int unk0688;     unsigned int unk068C;
    unsigned int unk0690;     unsigned int unk0694;     unsigned int unk0698;     unsigned int unk069C;
    unsigned int unk06A0;     unsigned int unk06A4;     unsigned int unk06A8;     unsigned int unk06AC;
    unsigned int unk06B0;     unsigned int unk06B4;     unsigned int unk06B8;     unsigned int unk06BC;
    unsigned int unk06C0;     unsigned int unk06C4;     unsigned int unk06C8;     unsigned int unk06CC;
    unsigned int unk06D0;     unsigned int unk06D4;     unsigned int unk06D8;     unsigned int unk06DC;
    unsigned int unk06E0;     unsigned int unk06E4;     unsigned int unk06E8;     unsigned int unk06EC;
    unsigned int unk06F0;     unsigned int unk06F4;     unsigned int unk06F8;     unsigned int unk06FC;
    unsigned int unk0700;     unsigned int unk0704;     unsigned int unk0708;     unsigned int unk070C;
    unsigned int unk0710;     unsigned int unk0714;     unsigned int unk0718;     unsigned int unk071C;
    unsigned int unk0720;     unsigned int unk0724;     unsigned int unk0728;     unsigned int unk072C;
    unsigned int unk0730;     unsigned int unk0734;     unsigned int unk0738;     unsigned int unk073C;
    unsigned int unk0740;     unsigned int unk0744;     unsigned int unk0748;     unsigned int unk074C;
    unsigned int unk0750;     unsigned int unk0754;     unsigned int unk0758;     unsigned int unk075C;
    unsigned int unk0760;     unsigned int unk0764;     unsigned int unk0768;     unsigned int unk076C;
    unsigned int unk0770;     unsigned int unk0774;     unsigned int unk0778;     unsigned int unk077C;
    unsigned int unk0780;     unsigned int unk0784;     unsigned int unk0788;     unsigned int unk078C;
    unsigned int unk0790;     unsigned int unk0794;     unsigned int unk0798;     unsigned int unk079C;
    unsigned int unk07A0;     unsigned int unk07A4;     unsigned int unk07A8;     unsigned int unk07AC;
    unsigned int unk07B0;     unsigned int unk07B4;     unsigned int unk07B8;     unsigned int unk07BC;
    unsigned int unk07C0;     unsigned int unk07C4;     unsigned int unk07C8;     unsigned int unk07CC;
    unsigned int unk07D0;     unsigned int unk07D4;     unsigned int unk07D8;     unsigned int unk07DC;
    unsigned int unk07E0;     unsigned int unk07E4;     unsigned int unk07E8;     unsigned int unk07EC;
    unsigned int unk07F0;     unsigned int unk07F4;     unsigned int unk07F8;     unsigned int unk07FC;
    unsigned int unk0800;     unsigned int unk0804;     unsigned int unk0808;     unsigned int unk080C;
    unsigned int unk0810;     unsigned int unk0814;     unsigned int unk0818;     unsigned int unk081C;
    unsigned int unk0820;     unsigned int unk0824;     unsigned int unk0828;     unsigned int unk082C;
    unsigned int unk0830;     unsigned int unk0834;     unsigned int unk0838;     unsigned int unk083C;
    unsigned int unk0840;     unsigned int unk0844;     unsigned int unk0848;     unsigned int unk084C;
    unsigned int unk0850;     unsigned int unk0854;     unsigned int unk0858;     unsigned int unk085C;
    unsigned int unk0860;     unsigned int unk0864;     unsigned int unk0868;     unsigned int unk086C;
    unsigned int unk0870;     unsigned int unk0874;     unsigned int unk0878;     unsigned int unk087C;
    unsigned int unk0880;     unsigned int unk0884;     unsigned int unk0888;     unsigned int unk088C;
    unsigned int unk0890;     unsigned int unk0894;     unsigned int unk0898;     unsigned int unk089C;
    unsigned int unk08A0;     unsigned int unk08A4;     unsigned int unk08A8;     unsigned int unk08AC;
    unsigned int unk08B0;     unsigned int unk08B4;     unsigned int unk08B8;     unsigned int unk08BC;
    unsigned int unk08C0;     unsigned int unk08C4;     unsigned int unk08C8;     unsigned int unk08CC;
    unsigned int unk08D0;     unsigned int unk08D4;     unsigned int unk08D8;     unsigned int unk08DC;
    unsigned int unk08E0;     unsigned int unk08E4;     unsigned int unk08E8;     unsigned int unk08EC;
    unsigned int unk08F0;     unsigned int unk08F4;     unsigned int unk08F8;     unsigned int unk08FC;
    unsigned int unk0900;     unsigned int unk0904;     unsigned int unk0908;     unsigned int unk090C;
    unsigned int unk0910;     unsigned int unk0914;     unsigned int unk0918;     unsigned int unk091C;
    unsigned int unk0920;     unsigned int unk0924;     unsigned int unk0928;     unsigned int unk092C;
    unsigned int unk0930;     unsigned int unk0934;     unsigned int unk0938;     unsigned int unk093C;
    unsigned int unk0940;     unsigned int unk0944;     unsigned int unk0948;     unsigned int unk094C;
    unsigned int unk0950;     unsigned int unk0954;     unsigned int unk0958;     unsigned int unk095C;
    unsigned int unk0960;     unsigned int unk0964;     unsigned int unk0968;     unsigned int unk096C;
    unsigned int unk0970;     unsigned int unk0974;     unsigned int unk0978;     unsigned int unk097C;
    unsigned int unk0980;     unsigned int unk0984;     unsigned int unk0988;     unsigned int unk098C;
    unsigned int unk0990;     unsigned int unk0994;     unsigned int unk0998;     unsigned int unk099C;
    unsigned int unk09A0;     unsigned int unk09A4;     unsigned int unk09A8;     unsigned int unk09AC;
    unsigned int unk09B0;     unsigned int unk09B4;     unsigned int unk09B8;     unsigned int unk09BC;
    unsigned int unk09C0;     unsigned int unk09C4;     unsigned int unk09C8;     unsigned int unk09CC;
    unsigned int unk09D0;     unsigned int unk09D4;     unsigned int unk09D8;     unsigned int unk09DC;
    unsigned int unk09E0;     unsigned int unk09E4;     unsigned int unk09E8;     unsigned int unk09EC;
    unsigned int unk09F0;     unsigned int unk09F4;     unsigned int unk09F8;     unsigned int unk09FC;
    unsigned int unk0A00;     unsigned int unk0A04;     unsigned int unk0A08;     unsigned int unk0A0C;
    unsigned int unk0A10;     unsigned int unk0A14;     unsigned int unk0A18;     unsigned int unk0A1C;
    unsigned int unk0A20;     unsigned int unk0A24;     unsigned int unk0A28;     unsigned int unk0A2C;
    unsigned int unk0A30;     unsigned int unk0A34;     unsigned int unk0A38;     unsigned int unk0A3C;
    unsigned int unk0A40;     unsigned int unk0A44;     unsigned int unk0A48;     unsigned int unk0A4C;
    unsigned int unk0A50;     unsigned int unk0A54;     unsigned int unk0A58;     unsigned int unk0A5C;
    unsigned int unk0A60;     unsigned int unk0A64;     unsigned int unk0A68;     unsigned int unk0A6C;
    unsigned int unk0A70;     unsigned int unk0A74;     unsigned int unk0A78;     unsigned int unk0A7C;
    unsigned int unk0A80;     unsigned int unk0A84;     unsigned int unk0A88;     unsigned int unk0A8C;
    unsigned int unk0A90;     unsigned int unk0A94;     unsigned int unk0A98;     unsigned int unk0A9C;
    unsigned int unk0AA0;     unsigned int unk0AA4;     unsigned int unk0AA8;     unsigned int unk0AAC;
    unsigned int unk0AB0;     unsigned int unk0AB4;     unsigned int unk0AB8;     unsigned int unk0ABC;
    unsigned int unk0AC0;     unsigned int unk0AC4;     unsigned int unk0AC8;     unsigned int unk0ACC;
    unsigned int unk0AD0;     unsigned int unk0AD4;     unsigned int unk0AD8;     unsigned int unk0ADC;
    unsigned int unk0AE0;     unsigned int unk0AE4;     unsigned int unk0AE8;     unsigned int unk0AEC;
    unsigned int unk0AF0;     unsigned int unk0AF4;     unsigned int unk0AF8;     unsigned int unk0AFC;
    unsigned int unk0B00;     unsigned int unk0B04;     unsigned int unk0B08;     unsigned int unk0B0C;
    unsigned int unk0B10;     unsigned int unk0B14;     unsigned int unk0B18;     unsigned int unk0B1C;
    unsigned int unk0B20;     unsigned int unk0B24;     unsigned int unk0B28;     unsigned int unk0B2C;
    unsigned int unk0B30;     unsigned int unk0B34;     unsigned int unk0B38;     unsigned int unk0B3C;
    unsigned int unk0B40;     unsigned int unk0B44;     unsigned int unk0B48;     unsigned int unk0B4C;
    unsigned int unk0B50;     unsigned int unk0B54;     unsigned int unk0B58;     unsigned int unk0B5C;
    unsigned int unk0B60;     unsigned int unk0B64;     unsigned int unk0B68;     unsigned int unk0B6C;
    unsigned int unk0B70;     unsigned int unk0B74;     unsigned int unk0B78;     unsigned int unk0B7C;
    unsigned int unk0B80;     unsigned int unk0B84;     unsigned int unk0B88;     unsigned int unk0B8C;
    unsigned int unk0B90;     unsigned int unk0B94;     unsigned int unk0B98;     unsigned int unk0B9C;
    unsigned int unk0BA0;     unsigned int unk0BA4;     unsigned int unk0BA8;     unsigned int unk0BAC;
    unsigned int unk0BB0;     unsigned int unk0BB4;     unsigned int unk0BB8;     unsigned int unk0BBC;
    unsigned int unk0BC0;     unsigned int unk0BC4;     unsigned int unk0BC8;     unsigned int unk0BCC;
    unsigned int unk0BD0;     unsigned int unk0BD4;     unsigned int unk0BD8;     unsigned int unk0BDC;
    unsigned int unk0BE0;     unsigned int unk0BE4;     unsigned int unk0BE8;     unsigned int unk0BEC;
    unsigned int unk0BF0;     unsigned int unk0BF4;     unsigned int unk0BF8;     unsigned int unk0BFC;
    unsigned int unk0C00;     unsigned int unk0C04;     unsigned int unk0C08;     unsigned int unk0C0C;
    unsigned int unk0C10;     unsigned int unk0C14;     unsigned int unk0C18;     unsigned int unk0C1C;
    unsigned int unk0C20;     unsigned int unk0C24;     unsigned int unk0C28;     unsigned int unk0C2C;
    unsigned int unk0C30;     unsigned int unk0C34;     unsigned int unk0C38;     unsigned int unk0C3C;
    unsigned int unk0C40;     unsigned int unk0C44;     unsigned int unk0C48;     unsigned int unk0C4C;
    unsigned int unk0C50;     unsigned int unk0C54;     unsigned int unk0C58;     unsigned int unk0C5C;
    unsigned int unk0C60;     unsigned int unk0C64;     unsigned int unk0C68;     unsigned int unk0C6C;
    unsigned int unk0C70;     unsigned int unk0C74;     unsigned int unk0C78;     unsigned int unk0C7C;
    unsigned int unk0C80;     unsigned int unk0C84;     unsigned int unk0C88;     unsigned int unk0C8C;
    unsigned int unk0C90;     unsigned int unk0C94;     unsigned int unk0C98;     unsigned int unk0C9C;
    unsigned int unk0CA0;     unsigned int unk0CA4;     unsigned int unk0CA8;     unsigned int unk0CAC;
    unsigned int unk0CB0;     unsigned int unk0CB4;     unsigned int unk0CB8;     unsigned int unk0CBC;
    unsigned int unk0CC0;     unsigned int unk0CC4;     unsigned int unk0CC8;     unsigned int unk0CCC;
    unsigned int unk0CD0;     unsigned int unk0CD4;     unsigned int unk0CD8;     unsigned int unk0CDC;
    unsigned int unk0CE0;     unsigned int unk0CE4;     unsigned int unk0CE8;     unsigned int unk0CEC;
    unsigned int unk0CF0;     unsigned int unk0CF4;     unsigned int unk0CF8;     unsigned int unk0CFC;
    unsigned int unk0D00;     unsigned int unk0D04;     unsigned int unk0D08;     unsigned int unk0D0C;
    unsigned int unk0D10;     unsigned int unk0D14;     unsigned int unk0D18;     unsigned int unk0D1C;
    unsigned int unk0D20;     unsigned int unk0D24;     unsigned int unk0D28;     unsigned int unk0D2C;
    unsigned int unk0D30;     unsigned int unk0D34;     unsigned int unk0D38;     unsigned int unk0D3C;
    unsigned int unk0D40;     unsigned int unk0D44;     unsigned int unk0D48;     unsigned int unk0D4C;
    unsigned int unk0D50;     unsigned int unk0D54;     unsigned int unk0D58;     unsigned int unk0D5C;
    unsigned int unk0D60;     unsigned int unk0D64;     unsigned int unk0D68;     unsigned int unk0D6C;
    unsigned int unk0D70;     unsigned int unk0D74;     unsigned int unk0D78;     unsigned int unk0D7C;
    unsigned int unk0D80;     unsigned int unk0D84;     unsigned int unk0D88;     unsigned int unk0D8C;
    unsigned int unk0D90;     unsigned int unk0D94;     unsigned int unk0D98;     unsigned int unk0D9C;
    unsigned int unk0DA0;     unsigned int unk0DA4;     unsigned int unk0DA8;     unsigned int unk0DAC;
    unsigned int unk0DB0;     unsigned int unk0DB4;     unsigned int unk0DB8;     unsigned int unk0DBC;
    unsigned int unk0DC0;     unsigned int unk0DC4;     unsigned int unk0DC8;     unsigned int unk0DCC;
    unsigned int unk0DD0;     unsigned int unk0DD4;     unsigned int unk0DD8;     unsigned int unk0DDC;
    unsigned int unk0DE0;     unsigned int unk0DE4;     unsigned int unk0DE8;     unsigned int unk0DEC;
    unsigned int unk0DF0;     unsigned int unk0DF4;     unsigned int unk0DF8;     unsigned int unk0DFC;
    unsigned int unk0E00;     unsigned int unk0E04;     unsigned int unk0E08;     unsigned int unk0E0C;
    unsigned int unk0E10;     unsigned int unk0E14;     unsigned int unk0E18;     unsigned int unk0E1C;
    unsigned int unk0E20;     unsigned int unk0E24;     unsigned int unk0E28;     unsigned int unk0E2C;
    unsigned int unk0E30;     unsigned int unk0E34;     unsigned int unk0E38;     unsigned int unk0E3C;
    unsigned int unk0E40;     unsigned int unk0E44;     unsigned int unk0E48;     unsigned int unk0E4C;
    unsigned int unk0E50;     unsigned int unk0E54;     unsigned int unk0E58;     unsigned int unk0E5C;
    unsigned int unk0E60;     unsigned int unk0E64;     unsigned int unk0E68;     unsigned int unk0E6C;
    unsigned int unk0E70;     unsigned int unk0E74;     unsigned int unk0E78;     unsigned int unk0E7C;
    unsigned int unk0E80;     unsigned int unk0E84;     unsigned int unk0E88;     unsigned int unk0E8C;
    unsigned int unk0E90;     unsigned int unk0E94;     unsigned int unk0E98;     unsigned int unk0E9C;
    unsigned int unk0EA0;     unsigned int unk0EA4;     unsigned int unk0EA8;     unsigned int unk0EAC;
    unsigned int unk0EB0;     unsigned int unk0EB4;     unsigned int unk0EB8;     unsigned int unk0EBC;
    unsigned int unk0EC0;     unsigned int unk0EC4;     unsigned int unk0EC8;     unsigned int unk0ECC;
    unsigned int unk0ED0;     unsigned int unk0ED4;     unsigned int unk0ED8;     unsigned int unk0EDC;
    unsigned int unk0EE0;     unsigned int unk0EE4;     unsigned int unk0EE8;     unsigned int unk0EEC;
    unsigned int unk0EF0;     unsigned int unk0EF4;     unsigned int unk0EF8;     unsigned int unk0EFC;
    unsigned int unk0F00;     unsigned int unk0F04;     unsigned int unk0F08;     unsigned int unk0F0C;
    unsigned int unk0F10;     unsigned int unk0F14;     unsigned int unk0F18;     unsigned int unk0F1C;
    unsigned int unk0F20;     unsigned int unk0F24;     unsigned int unk0F28;     unsigned int unk0F2C;
    unsigned int unk0F30;     unsigned int unk0F34;     unsigned int unk0F38;     unsigned int unk0F3C;
    unsigned int unk0F40;     unsigned int unk0F44;     unsigned int unk0F48;     unsigned int unk0F4C;
    unsigned int unk0F50;     unsigned int unk0F54;     unsigned int unk0F58;     unsigned int unk0F5C;
    unsigned int unk0F60;     unsigned int unk0F64;     unsigned int unk0F68;     unsigned int unk0F6C;
    unsigned int unk0F70;     unsigned int unk0F74;     unsigned int unk0F78;     unsigned int unk0F7C;
    unsigned int unk0F80;     unsigned int unk0F84;     unsigned int unk0F88;     unsigned int unk0F8C;
    unsigned int unk0F90;     unsigned int unk0F94;     unsigned int unk0F98;     unsigned int unk0F9C;
    unsigned int unk0FA0;     unsigned int unk0FA4;     unsigned int unk0FA8;     unsigned int unk0FAC;
    unsigned int unk0FB0;     unsigned int unk0FB4;     unsigned int unk0FB8;     unsigned int unk0FBC;
    unsigned int unk0FC0;     unsigned int unk0FC4;     unsigned int unk0FC8;     unsigned int unk0FCC;
    unsigned int unk0FD0;     unsigned int unk0FD4;     unsigned int unk0FD8;     unsigned int unk0FDC;
    unsigned int unk0FE0;     unsigned int unk0FE4;     unsigned int unk0FE8;     unsigned int unk0FEC;
    unsigned int unk0FF0;     unsigned int unk0FF4;     unsigned int unk0FF8;     unsigned int unk0FFC;
    unsigned int unk1000;     unsigned int unk1004;     unsigned int unk1008;     unsigned int unk100C;
    unsigned int unk1010;     unsigned int unk1014;     unsigned int unk1018;     unsigned int unk101C;
    unsigned int unk1020;     unsigned int unk1024;     unsigned int unk1028;     unsigned int unk102C;
    unsigned int unk1030;     unsigned int unk1034;     unsigned int unk1038;     unsigned int unk103C;
    unsigned int unk1040;     unsigned int unk1044;     unsigned int unk1048;     unsigned int unk104C;
    unsigned int unk1050;     unsigned int unk1054;     unsigned int unk1058;     unsigned int unk105C;
    unsigned int unk1060;     unsigned int unk1064;     unsigned int unk1068;     unsigned int unk106C;
    unsigned int unk1070;     unsigned int unk1074;     unsigned int unk1078;     unsigned int unk107C;
    unsigned int unk1080;     unsigned int unk1084;     unsigned int unk1088;     unsigned int unk108C;
    unsigned int unk1090;     unsigned int unk1094;     unsigned int unk1098;     unsigned int unk109C;
    unsigned int unk10A0;     unsigned int unk10A4;     unsigned int unk10A8;     unsigned int unk10AC;
    unsigned int unk10B0;     unsigned int unk10B4;     unsigned int unk10B8;     unsigned int unk10BC;
    unsigned int unk10C0;     unsigned int unk10C4;     unsigned int unk10C8;     unsigned int unk10CC;
    unsigned int unk10D0;     unsigned int unk10D4;     unsigned int unk10D8;     unsigned int unk10DC;
    unsigned int unk10E0;     unsigned int unk10E4;     unsigned int unk10E8;     unsigned int unk10EC;
    unsigned int unk10F0;     unsigned int unk10F4;     unsigned int unk10F8;     unsigned int unk10FC;
    unsigned int unk1100;     unsigned int unk1104;     unsigned int unk1108;     unsigned int unk110C;
    unsigned int unk1110;     unsigned int unk1114;     unsigned int unk1118;     unsigned int unk111C;
    unsigned int unk1120;     unsigned int unk1124;     unsigned int unk1128;     unsigned int unk112C;
    unsigned int unk1130;     unsigned int unk1134;     unsigned int unk1138;     unsigned int unk113C;
    unsigned int unk1140;     unsigned int unk1144;     unsigned int unk1148;     unsigned int unk114C;
    unsigned int unk1150;     unsigned int unk1154;     unsigned int unk1158;     unsigned int unk115C;
    unsigned int unk1160;     unsigned int unk1164;     unsigned int unk1168;     unsigned int unk116C;
    unsigned int unk1170;     unsigned int unk1174;     unsigned int unk1178;     unsigned int unk117C;
    unsigned int unk1180;     unsigned int unk1184;     unsigned int unk1188;     unsigned int unk118C;
    unsigned int unk1190;     unsigned int unk1194;     unsigned int unk1198;     unsigned int unk119C;
    unsigned int unk11A0;     unsigned int unk11A4;     unsigned int unk11A8;     unsigned int unk11AC;
    unsigned int unk11B0;     unsigned int unk11B4;     unsigned int unk11B8;     unsigned int unk11BC;
    unsigned int unk11C0;     unsigned int unk11C4;     unsigned int unk11C8;     unsigned int unk11CC;
    unsigned int unk11D0;     unsigned int unk11D4;     unsigned int unk11D8;     unsigned int unk11DC;
    unsigned int unk11E0;     unsigned int unk11E4;     unsigned int unk11E8;     unsigned int unk11EC;
    unsigned int unk11F0;     unsigned int unk11F4;     unsigned int unk11F8;     unsigned int unk11FC;
    unsigned int unk1200;     unsigned int unk1204;     unsigned int unk1208;     unsigned int unk120C;
    unsigned int unk1210;     unsigned int unk1214;     unsigned int unk1218;     unsigned int unk121C;
    unsigned int unk1220;     unsigned int unk1224;     unsigned int unk1228;     unsigned int unk122C;
    unsigned int unk1230;     unsigned int unk1234;     unsigned int unk1238;     unsigned int unk123C;
    unsigned int unk1240;     unsigned int unk1244;     unsigned int unk1248;     unsigned int unk124C;
    unsigned int unk1250;     unsigned int unk1254;     unsigned int unk1258;     unsigned int unk125C;
    unsigned int unk1260;     unsigned int unk1264;     unsigned int unk1268;     unsigned int unk126C;
    unsigned int unk1270;     unsigned int unk1274;     unsigned int unk1278;     unsigned int unk127C;
    unsigned int unk1280;     unsigned int unk1284;     unsigned int unk1288;     unsigned int unk128C;
    unsigned int unk1290;     unsigned int unk1294;     unsigned int unk1298;     unsigned int unk129C;
    unsigned int unk12A0;     unsigned int unk12A4;     unsigned int unk12A8;     unsigned int unk12AC;
    unsigned int unk12B0;     unsigned int unk12B4;     unsigned int unk12B8;     unsigned int unk12BC;
    unsigned int unk12C0;     unsigned int unk12C4;     unsigned int unk12C8;     unsigned int unk12CC;
    unsigned int unk12D0;     unsigned int unk12D4;     unsigned int unk12D8;     unsigned int unk12DC;
    unsigned int unk12E0;     unsigned int unk12E4;     unsigned int unk12E8;     unsigned int unk12EC;
    unsigned int unk12F0;     unsigned int unk12F4;     unsigned int unk12F8;     unsigned int unk12FC;
    unsigned int unk1300;     unsigned int unk1304;     unsigned int unk1308;     unsigned int unk130C;
    unsigned int unk1310;     unsigned int unk1314;     unsigned int unk1318;     unsigned int unk131C;
    unsigned int unk1320;     unsigned int unk1324;     unsigned int unk1328;     unsigned int unk132C;
    unsigned int unk1330;     unsigned int unk1334;     unsigned int unk1338;     unsigned int unk133C;
    unsigned int unk1340;     unsigned int unk1344;     unsigned int unk1348;     unsigned int unk134C;
    unsigned int unk1350;     unsigned int unk1354;     unsigned int unk1358;     unsigned int unk135C;
    unsigned int unk1360;     unsigned int unk1364;     unsigned int unk1368;     unsigned int unk136C;
    unsigned int unk1370;     unsigned int unk1374;     unsigned int unk1378;     unsigned int unk137C;
    unsigned int unk1380;     unsigned int unk1384;     unsigned int unk1388;     unsigned int unk138C;
    unsigned int unk1390;     unsigned int unk1394;     unsigned int unk1398;     unsigned int unk139C;
    unsigned int unk13A0;     unsigned int unk13A4;     unsigned int unk13A8;     unsigned int unk13AC;
    unsigned int unk13B0;     unsigned int unk13B4;     unsigned int unk13B8;     unsigned int unk13BC;
    unsigned int unk13C0;     unsigned int unk13C4;     unsigned int unk13C8;     unsigned int unk13CC;
    unsigned int unk13D0;     unsigned int unk13D4;     unsigned int unk13D8;     unsigned int unk13DC;
    unsigned int unk13E0;     unsigned int unk13E4;     unsigned int unk13E8;     unsigned int unk13EC;
    unsigned int unk13F0;     unsigned int unk13F4;     unsigned int unk13F8;     unsigned int unk13FC;
    unsigned int unk1400;     unsigned int unk1404;     unsigned int unk1408;     unsigned int unk140C;
    unsigned int unk1410;     unsigned int unk1414;     unsigned int unk1418;     unsigned int unk141C;
    unsigned int unk1420;     unsigned int unk1424;     unsigned int unk1428;     unsigned int unk142C;
    unsigned int unk1430;     unsigned int unk1434;     unsigned int unk1438;     unsigned int unk143C;
    unsigned int unk1440;     unsigned int unk1444;     unsigned int unk1448;     unsigned int unk144C;
    unsigned int unk1450;     unsigned int unk1454;     unsigned int unk1458;     unsigned int unk145C;
    unsigned int unk1460;     unsigned int unk1464;     unsigned int unk1468;     unsigned int unk146C;
    unsigned int unk1470;     unsigned int unk1474;     unsigned int unk1478;     unsigned int unk147C;
    unsigned int unk1480;     unsigned int unk1484;     unsigned int unk1488;     unsigned int unk148C;
    unsigned int unk1490;     unsigned int unk1494;     unsigned int unk1498;     unsigned int unk149C;
    unsigned int unk14A0;     unsigned int unk14A4;     unsigned int unk14A8;     unsigned int unk14AC;
    unsigned int unk14B0;     unsigned int unk14B4;     unsigned int unk14B8;     unsigned int unk14BC;
    unsigned int unk14C0;     unsigned int unk14C4;     unsigned int unk14C8;     unsigned int unk14CC;
    unsigned int unk14D0;     unsigned int unk14D4;     unsigned int unk14D8;     unsigned int unk14DC;
    unsigned int unk14E0;     unsigned int unk14E4;     unsigned int unk14E8;     unsigned int unk14EC;
    unsigned int unk14F0;     unsigned int unk14F4;     unsigned int unk14F8;     unsigned int unk14FC;
    unsigned int unk1500;     unsigned int unk1504;     unsigned int unk1508;     unsigned int unk150C;
    unsigned int unk1510;     unsigned int unk1514;     unsigned int unk1518;     unsigned int unk151C;
    unsigned int unk1520;     unsigned int unk1524;     unsigned int unk1528;     unsigned int unk152C;
    unsigned int unk1530;     unsigned int unk1534;     unsigned int unk1538;     unsigned int unk153C;
    unsigned int unk1540;     unsigned int unk1544;     unsigned int unk1548;     unsigned int unk154C;
    unsigned int unk1550;     unsigned int unk1554;     unsigned int unk1558;     unsigned int unk155C;
    unsigned int unk1560;     unsigned int unk1564;     unsigned int unk1568;     unsigned int unk156C;
    unsigned int unk1570;     unsigned int unk1574;     unsigned int unk1578;     unsigned int unk157C;
    unsigned int unk1580;     unsigned int unk1584;     unsigned int unk1588;     unsigned int unk158C;
    unsigned int unk1590;     unsigned int unk1594;     unsigned int unk1598;     unsigned int unk159C;
    unsigned int unk15A0;     unsigned int unk15A4;     unsigned int unk15A8;     unsigned int unk15AC;
    unsigned int unk15B0;     unsigned int unk15B4;     unsigned int unk15B8;     unsigned int unk15BC;
    unsigned int unk15C0;     unsigned int unk15C4;     unsigned int unk15C8;     unsigned int unk15CC;
    unsigned int unk15D0;     unsigned int unk15D4;     unsigned int unk15D8;     unsigned int unk15DC;
    unsigned int unk15E0;     unsigned int unk15E4;     unsigned int unk15E8;     unsigned int unk15EC;
    unsigned int unk15F0;     unsigned int unk15F4;     unsigned int unk15F8;     unsigned int unk15FC;
    unsigned int unk1600;     unsigned int unk1604;     unsigned int unk1608;     unsigned int unk160C;
    unsigned int unk1610;     unsigned int unk1614;     unsigned int unk1618;     unsigned int unk161C;
    unsigned int unk1620;     unsigned int unk1624;     unsigned int unk1628;     unsigned int unk162C;
    unsigned int unk1630;     unsigned int unk1634;     unsigned int unk1638;     unsigned int unk163C;
    unsigned int unk1640;     unsigned int unk1644;     unsigned int unk1648;     unsigned int unk164C;
    unsigned int unk1650;     unsigned int unk1654;     unsigned int unk1658;     unsigned int unk165C;
    unsigned int unk1660;     unsigned int unk1664;     unsigned int unk1668;     unsigned int unk166C;
    unsigned int unk1670;     unsigned int unk1674;     unsigned int unk1678;     unsigned int unk167C;
    unsigned int unk1680;     unsigned int unk1684;     unsigned int unk1688;     unsigned int unk168C;
    unsigned int unk1690;     unsigned int unk1694;     unsigned int unk1698;     unsigned int unk169C;
    unsigned int unk16A0;     unsigned int unk16A4;     unsigned int unk16A8;     unsigned int unk16AC;
    unsigned int unk16B0;     unsigned int unk16B4;     unsigned int unk16B8;     unsigned int unk16BC;
    unsigned int unk16C0;     unsigned int unk16C4;     unsigned int unk16C8;     unsigned int unk16CC;
    unsigned int unk16D0;     unsigned int unk16D4;     unsigned int unk16D8;     unsigned int unk16DC;
    unsigned int unk16E0;     unsigned int unk16E4;     unsigned int unk16E8;     unsigned int unk16EC;
    unsigned int unk16F0;     unsigned int unk16F4;     unsigned int unk16F8;     unsigned int unk16FC;
    unsigned int unk1700;     unsigned int unk1704;     unsigned int unk1708;     unsigned int unk170C;
    unsigned int unk1710;     unsigned int unk1714;     unsigned int unk1718;     unsigned int unk171C;
    unsigned int unk1720;     unsigned int unk1724;     unsigned int unk1728;     unsigned int unk172C;
    unsigned int unk1730;     unsigned int unk1734;     unsigned int unk1738;     unsigned int unk173C;
    unsigned int unk1740;     unsigned int unk1744;     unsigned int unk1748;     unsigned int unk174C;
    unsigned int unk1750;     unsigned int unk1754;     unsigned int unk1758;     unsigned int unk175C;
    unsigned int unk1760;     unsigned int unk1764;     unsigned int unk1768;     unsigned int unk176C;
    unsigned int unk1770;     unsigned int unk1774;     unsigned int unk1778;     unsigned int unk177C;
    unsigned int unk1780;     unsigned int unk1784;     unsigned int unk1788;     unsigned int unk178C;
    unsigned int unk1790;     unsigned int unk1794;     unsigned int unk1798;     unsigned int unk179C;
    unsigned int unk17A0;     unsigned int unk17A4;     unsigned int unk17A8;     unsigned int unk17AC;
    unsigned int unk17B0;     unsigned int unk17B4;     unsigned int unk17B8;     unsigned int unk17BC;
    unsigned int unk17C0;     unsigned int unk17C4;     unsigned int unk17C8;     unsigned int unk17CC;
    unsigned int unk17D0;     unsigned int unk17D4;     unsigned int unk17D8;     unsigned int unk17DC;
    unsigned int unk17E0;     unsigned int unk17E4;     unsigned int unk17E8;     unsigned int unk17EC;
    unsigned int unk17F0;     unsigned int unk17F4;     unsigned int unk17F8;     unsigned int unk17FC;
    unsigned int unk1800;     unsigned int unk1804;     unsigned int unk1808;     unsigned int unk180C;
    unsigned int unk1810;     unsigned int unk1814;     unsigned int unk1818;     unsigned int unk181C;
    unsigned int unk1820;     unsigned int unk1824;     unsigned int unk1828;     unsigned int unk182C;
    unsigned int unk1830;     unsigned int unk1834;     unsigned int unk1838;     unsigned int unk183C;
    unsigned int unk1840;     unsigned int unk1844;     unsigned int unk1848;     unsigned int unk184C;
    unsigned int unk1850;     unsigned int unk1854;     unsigned int unk1858;     unsigned int unk185C;
    unsigned int unk1860;     unsigned int unk1864;     unsigned int unk1868;     unsigned int unk186C;
    unsigned int unk1870;     unsigned int unk1874;     unsigned int unk1878;     unsigned int unk187C;
    unsigned int unk1880;     unsigned int unk1884;     unsigned int unk1888;     unsigned int unk188C;
    unsigned int unk1890;     unsigned int unk1894;     unsigned int unk1898;     unsigned int unk189C;
    unsigned int unk18A0;     unsigned int unk18A4;     unsigned int unk18A8;     unsigned int unk18AC;
    unsigned int unk18B0;     unsigned int unk18B4;     unsigned int unk18B8;     unsigned int unk18BC;
    unsigned int unk18C0;     unsigned int unk18C4;     unsigned int unk18C8;     unsigned int unk18CC;
    unsigned int unk18D0;     unsigned int unk18D4;     unsigned int unk18D8;     unsigned int unk18DC;
    unsigned int unk18E0;     unsigned int unk18E4;     unsigned int unk18E8;     unsigned int unk18EC;
    unsigned int unk18F0;     unsigned int unk18F4;     unsigned int unk18F8;     unsigned int unk18FC;
    unsigned int unk1900;     unsigned int unk1904;     unsigned int unk1908;     unsigned int unk190C;
    unsigned int unk1910;     unsigned int unk1914;     unsigned int unk1918;     unsigned int unk191C;
    unsigned int unk1920;     unsigned int unk1924;     unsigned int unk1928;     unsigned int unk192C;
    unsigned int unk1930;     unsigned int unk1934;     unsigned int unk1938;     unsigned int unk193C;
    unsigned int unk1940;     unsigned int unk1944;     unsigned int unk1948;     unsigned int unk194C;
    unsigned int unk1950;     unsigned int unk1954;     unsigned int unk1958;     unsigned int unk195C;
    unsigned int unk1960;     unsigned int unk1964;     unsigned int unk1968;     unsigned int unk196C;
    unsigned int unk1970;     unsigned int unk1974;     unsigned int unk1978;     unsigned int unk197C;
    unsigned int unk1980;     unsigned int unk1984;     unsigned int unk1988;     unsigned int unk198C;
    unsigned int unk1990;     unsigned int unk1994;     unsigned int unk1998;     unsigned int unk199C;
    unsigned int unk19A0;     unsigned int unk19A4;     unsigned int unk19A8;     unsigned int unk19AC;
    unsigned int unk19B0;     unsigned int unk19B4;     unsigned int unk19B8;     unsigned int unk19BC;
    unsigned int unk19C0;     unsigned int unk19C4;     unsigned int unk19C8;     unsigned int unk19CC;
    unsigned int unk19D0;     unsigned int unk19D4;     unsigned int unk19D8;     unsigned int unk19DC;
    unsigned int unk19E0;     unsigned int unk19E4;     unsigned int unk19E8;     unsigned int unk19EC;
    unsigned int unk19F0;     unsigned int unk19F4;     unsigned int unk19F8;     unsigned int unk19FC;
    unsigned int unk1A00;     unsigned int unk1A04;     unsigned int unk1A08;     unsigned int unk1A0C;
    unsigned int unk1A10;     unsigned int unk1A14;     unsigned int unk1A18;     unsigned int unk1A1C;
    unsigned int unk1A20;     unsigned int unk1A24;     unsigned int unk1A28;     unsigned int unk1A2C;
    unsigned int unk1A30;     unsigned int unk1A34;     unsigned int unk1A38;     unsigned int unk1A3C;
    unsigned int unk1A40;     unsigned int unk1A44;     unsigned int unk1A48;     unsigned int unk1A4C;
    unsigned int unk1A50;     unsigned int unk1A54;     unsigned int unk1A58;     unsigned int unk1A5C;
    unsigned int unk1A60;     unsigned int unk1A64;     unsigned int unk1A68;     unsigned int unk1A6C;
    unsigned int unk1A70;     unsigned int unk1A74;     unsigned int unk1A78;     unsigned int unk1A7C;
    unsigned int unk1A80;     unsigned int unk1A84;     unsigned int unk1A88;     unsigned int unk1A8C;
    unsigned int unk1A90;     unsigned int unk1A94;     unsigned int unk1A98;     unsigned int unk1A9C;
    unsigned int unk1AA0;     unsigned int unk1AA4;     unsigned int unk1AA8;     unsigned int unk1AAC;
    unsigned int unk1AB0;     unsigned int unk1AB4;     unsigned int unk1AB8;     unsigned int unk1ABC;
    unsigned int unk1AC0;     unsigned int unk1AC4;     unsigned int unk1AC8;     unsigned int unk1ACC;
    unsigned int unk1AD0;     unsigned int unk1AD4;     unsigned int unk1AD8;     unsigned int unk1ADC;
    unsigned int unk1AE0;     unsigned int unk1AE4;     unsigned int unk1AE8;     unsigned int unk1AEC;
    unsigned int unk1AF0;     unsigned int unk1AF4;     unsigned int unk1AF8;     unsigned int unk1AFC;
    unsigned int unk1B00;     unsigned int unk1B04;     unsigned int unk1B08;     unsigned int unk1B0C;
    unsigned int unk1B10;     unsigned int unk1B14;     unsigned int unk1B18;     unsigned int unk1B1C;
    unsigned int unk1B20;     unsigned int unk1B24;     unsigned int unk1B28;     unsigned int unk1B2C;
    unsigned int unk1B30;     unsigned int unk1B34;     unsigned int unk1B38;     unsigned int unk1B3C;
    unsigned int unk1B40;     unsigned int unk1B44;     unsigned int unk1B48;     unsigned int unk1B4C;
    unsigned int unk1B50;     unsigned int unk1B54;     unsigned int unk1B58;     unsigned int unk1B5C;
    unsigned int unk1B60;     unsigned int unk1B64;     unsigned int unk1B68;     unsigned int unk1B6C;
    unsigned int unk1B70;     unsigned int unk1B74;     unsigned int unk1B78;     unsigned int unk1B7C;
    unsigned int unk1B80;     unsigned int unk1B84;     unsigned int unk1B88;     unsigned int unk1B8C;
    unsigned int unk1B90;     unsigned int unk1B94;     unsigned int unk1B98;     unsigned int unk1B9C;
    unsigned int unk1BA0;     unsigned int unk1BA4;     unsigned int unk1BA8;     unsigned int unk1BAC;
    unsigned char qualityEnabled[10][10];
};
struct Agent {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    CollisionObject* first;
    CollisionObject* second;
};
struct CollisionAgentEntry { Agent* agent; CollisionObject* other; };
struct OverlapAllocator {
    virtual void unused00(); virtual void unused04();
    virtual void unused08(); virtual void unused0c();
    virtual void freeBlock(void*, int);
};
void ResizeAudioStream(void*, void*, int);
static __declspec(noinline) void __cdecl SyncOverlap(PhantomInterface* phantom, CollisionObject* other, CollisionFilter* filter) {
    FilterBool overlapping = phantom->hasOverlap(other);
    CollisionObject* self = &phantom->collidable;
    if (filter->filter.enabled(self, other).value) {
        if (!overlapping.value) phantom->addOverlap(other);
        if (other->handle.type == 2) {
            FilterBool reverseOverlap = ((PhantomInterface*)((char*)other + other->ownerOffset))->hasOverlap(self);
            if (!reverseOverlap.value) ((PhantomInterface*)((char*)other + other->ownerOffset))->addOverlap(self);
        }
    } else {
        if (overlapping.value) phantom->removeOverlap(other);
        if (other->handle.type == 2) {
            FilterBool reverseOverlap = ((PhantomInterface*)((char*)other + other->ownerOffset))->hasOverlap(self);
            if (reverseOverlap.value) ((PhantomInterface*)((char*)other + other->ownerOffset))->removeOverlap(self);
        }
    }
}
void hkpWorldAgentUtil_removeAgentAndItsToiEvents(Agent*);
void _hkAgentNnMachine_UpdateShapeCollectionFilter(Agent*, void*, EntityState*);
void hkpTypedBroadPhaseDispatcher_removeDuplicates(PairArray*, PairArray*);
struct BroadphaseDispatcher {
    void hkpTypedBroadPhaseDispatcher_addPairs(OverlapPair*, int, CollisionFilterInterface*);
};
struct FilterCommand {
    unsigned char type;
    CollisionEntity* entity;
    unsigned char updateCollection;
    unsigned char updateShape;
};
struct CallRet : hkpWorld {
    void hkpWorld_updateCollisionFilterOnEntity(CollisionEntity*, int, int);
    void hkpWorld_queueOperation(FilterCommand*);
    void FUN_00c91120();
    void UpdateFields_00c91140();
};
__forceinline void releasePairs(PairArray& pairs) {
hkMemoryRouter* router = (hkMemoryRouter*)hkMemoryRouter_getInstance();
hkMemoryAllocator* heap = reinterpret_cast<hkMemoryAllocator*>(router->m_heap);
pairs.size=0;
if ((pairs.capacityAndFlags & 0x80000000)==0) heap->bufFree(pairs.data,(pairs.capacityAndFlags & 0x3fffffff)*sizeof(OverlapPair));
}
__forceinline void constructPairs(OverlapPair* p,int n) { for(int j=0;j<n;++j) new(p+j) OverlapPair; }
__forceinline OverlapPair& expandOverlapPair(PairArray& pairs) {
hkMemoryRouter* router = (hkMemoryRouter*)hkMemoryRouter_getInstance();
if (pairs.size == (pairs.capacityAndFlags & 0x3fffffff)) ResizeAudioStream(router->m_heap,&pairs,sizeof(OverlapPair));
constructPairs(pairs.data+pairs.size,1);
return pairs.data[pairs.size++];
}
PhantomInterface* volatile probePhantom;
CollisionObject* volatile probeObject;
CollisionFilter* volatile probeFilter;
void probeOverlapCaller();


extern LocalM128 DAT_010c71e0;
struct RotationInput {
    LocalM128 translation;
    LocalM128 rotation;
};
struct VectorTemporary {
    union { LocalM128 value; float components[4]; };
    void FUN_00c7f7a0(const RotationInput*, const LocalM128*);
};

struct hkTransformC997;
struct __declspec(align(16)) hkVector4C997 {
    float x, y, z, w;
    const LocalM128& getQuad() const { return *(const LocalM128*)&x; }
    LocalM128& getQuad() { return *(LocalM128*)&x; }
    void setZero4() { getQuad() = _mm_setzero_ps(); }
    void set(float a, float b, float c, float d = 0.0f)
    {
        getQuad() = _mm_setr_ps(a, b, c, d);
    }
    void setSub4(const hkVector4C997& a, const hkVector4C997& b) { getQuad() = _mm_sub_ps(*(LocalM128*)&a.x, *(LocalM128*)&b.x); }
    void FUN_00c7f7a0(const hkTransformC997& kTransform, const hkVector4C997& kVector) throw();
};
#include <stdarg.h>
struct RigidBody_s {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
struct RigidBodyList_s {
    RigidBody_s** m_apEntities;
    int m_uiItemCount;
};
struct Owner_s {
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
    RigidBodyList_s m_rigidBodyList;
};
struct System_s {
    void __thiscall addBody(RigidBody_s* body);
};
struct Context_s {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Owner_s* m_owner0;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    Owner_s** m_owners2;
    int m_ownerCount2;
};
struct BoolResult {
    char value;
    BoolResult(bool v) : value(v) {}
};
static BoolResult AddBodiesToSystem(Context_s* a2, ...);
Context_s* volatile retry_context;
System_s* volatile retry_system;
volatile char retry_result;
void retryCaller();
// FUN_00c98240 : MSVC this-adjusting thunk  (sub ecx, 0x08 ; jmp <impl>)
struct A1_00c98240 {
    A1_00c98240();
    virtual void AdjustThisAndForward_00c98240();
    char pad[0x04];
};
struct A2_00c98240 {
    A2_00c98240();
    virtual void AdjustThisAndForward_00c98240();
};
struct Own_00c98240 : A1_00c98240, A2_00c98240 {
    Own_00c98240();
    virtual void key_fn();
// @fnv 0x00c98240
// src: GUESS 0x00c98240 (confidence: low)
    void AdjustThisAndForward_00c98240();
};
Own_00c98240::Own_00c98240() { }
void Own_00c98240::key_fn() { }
Own_00c98240* make_00c98240() { static Own_00c98240 o; return &o; }
// FUN_00c98310 : MSVC this-adjusting thunk  (sub ecx, 0x14 ; jmp <impl>)
struct A1_00c98310 {
    A1_00c98310();
    virtual void FUN_00c98310();
    char pad[0x10];
};
struct A2_00c98310 {
    A2_00c98310();
    virtual void FUN_00c98310();
};
struct Own_00c98310 : A1_00c98310, A2_00c98310 {
    Own_00c98310();
    virtual void key_fn();
// @fnv 0x00c98310
    void FUN_00c98310();
};
Own_00c98310::Own_00c98310() { }
void Own_00c98310::key_fn() { }
Own_00c98310* make_00c98310() { static Own_00c98310 o; return &o; }
// FUN_00c98320 : MSVC this-adjusting thunk  (sub ecx, 0x08 ; jmp <impl>)
struct A1_00c98320 {
    A1_00c98320();
    virtual void AdjustThisAndForward_00c98320();
    char pad[0x04];
};
struct A2_00c98320 {
    A2_00c98320();
    virtual void AdjustThisAndForward_00c98320();
};
struct Own_00c98320 : A1_00c98320, A2_00c98320 {
    Own_00c98320();
    virtual void key_fn();
// @fnv 0x00c98320
// src: GUESS 0x00c98320 (confidence: low)
    void AdjustThisAndForward_00c98320();
};
Own_00c98320::Own_00c98320() { }
void Own_00c98320::key_fn() { }
Own_00c98320* make_00c98320() { static Own_00c98320 o; return &o; }
// sub ecx,8; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (8).
struct PrimaryBase
{
    virtual void FUN_00c98330();
    int unk04;
    int unk08;
};
struct SecondaryBase
{
    virtual void FUN_00c98330();
};
struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00c98330
    virtual void FUN_00c98330();
};
Derived::Derived()
{
}
// FUN_00c98340 : MSVC this-adjusting thunk  (sub ecx, 0x10 ; jmp <impl>)
struct A1_00c98340 {
    A1_00c98340();
    virtual void AdjustThisAndForward_00c98340();
    char pad[0x0c];
};
struct A2_00c98340 {
    A2_00c98340();
    virtual void AdjustThisAndForward_00c98340();
};
struct Own_00c98340 : A1_00c98340, A2_00c98340 {
    Own_00c98340();
    virtual void key_fn();
// @fnv 0x00c98340
// src: GUESS 0x00c98340 (confidence: low)
    void AdjustThisAndForward_00c98340();
};
Own_00c98340::Own_00c98340() { }
void Own_00c98340::key_fn() { }
Own_00c98340* make_00c98340() { static Own_00c98340 o; return &o; }
#include <math.h>
struct FUN_00c905xx_Obj {
    void __thiscall FUN_00c90510();
    void __thiscall FUN_00c905b0();
};
struct HkRefPtr {
    FUN_00c905xx_Obj* m_p;
    HkRefPtr& operator=(HkRefPtr& rhs)
        {
            FUN_00c905xx_Obj* pNew = rhs.m_p;
            if (pNew)
                pNew->FUN_00c90510();
            if (m_p)
                m_p->FUN_00c905b0();
            m_p = pNew;
            return *this;
        }
};
struct Sub_78_70 { float f00; int i04; };
struct Sub_78 {
    char pad00[0x6c];
    unsigned char b6c;
    unsigned char b6d;
    char pad6e[0x02];
    Sub_78_70* p70;
};
struct Sub_80 {
    char pad00[0x1e40];
    float f1e40;
    float f1e44;
};
struct Sub_08 {
    char pad00[0x24];
    float f24;
};
struct Dst_00c91c50 {
    char pad00[0x10];
    LocalM128 v10;
    int i_20;
    float f_24;
    unsigned char b_28;
    unsigned char b_29;
    char pad2a[0x06];
    LocalM128 v30;
    LocalM128 v40;
    unsigned char b_50;
    char pad51[0x02];
    unsigned char b_53;
    float f_54;
    HkRefPtr p58;
    HkRefPtr p5c;
    float f_60;
    int i_64;
    float f_68;
    HkRefPtr p6c;
    int i_70;
    unsigned char b_74;
    unsigned char b_75;
    char pad76[0x02];
    float f_78;
    float f_7c;
    int i_80;
    int i_84;
    float f_88;
    unsigned char b_8c;
    char pad8d[0x03];
    volatile float f_90;
    char pad94[0x04];
    unsigned char b_98;
    unsigned char b_99;
    char pad9a[0x02];
    float f_9c;
    int i_a0;
    unsigned char b_a4;
    unsigned char b_a5;
    unsigned char b_a6;
    unsigned char b_a7;
    float f_a8;
    float f_ac;
    int i_b0;
    unsigned char b_b4;
    char padb5[0x03];
    int i_b8;
    int i_bc;
    float f_c0;
    float f_c4;
    float f_c8;
    float f_cc;
    unsigned char b_d0;
    unsigned char b_d1;
    unsigned char b_d2;
    char padd3[0x01];
    int i_d4;
    unsigned char b_d8;
    unsigned char b_d9;
    char padda[0x02];
    float f_dc;
    unsigned char b_e0;
};
struct Src_00c91c50 {
    char pad00[0x08];
    Sub_08* p08;
    char pad0c[0x04];
    LocalM128 v10;
    char pad20[0x30];
    HkRefPtr p50;
    char pad54[0x08];
    int i5c;
    unsigned char b60;
    char pad61[0x17];
    Sub_78* p78;
    HkRefPtr p7c;
    Sub_80* p80;
    HkRefPtr p84;
    char pad88[0x28];
    unsigned char b_b0;
    unsigned char b_b1;
    char padb2[0x02];
    int i_b4;
    char padb8[0x10];
    unsigned char b_c8;
    char padc9[0x03];
    float f_cc;
    float f_d0;
    unsigned char b_d4;
    unsigned char b_d5;
    unsigned char b_d6;
    char padd7[0x01];
    float f_d8;
    float f_dc;
    int i_e0;
    unsigned char b_e4;
    char pade5[0x03];
    int i_e8;
    int i_ec;
    unsigned char b_f0;
    char padf1[0x03];
    float f_f4;
    float f_f8;
    float f_fc;
    float f_100;
    char pad104[0xb8];
    void* p_1bc;
    int i_1c0;
    char pad1c4[0x20];
    float f_1e4;
    float f_1e8;
    char pad1ec[0x54];
    float f_240;
    char pad244[0xb0];
    int i_2f4;
    int i_2f8;
    char pad2fc[0x08];
    unsigned char b_304;
    unsigned char b_305;
    unsigned char b_306;
    unsigned char b_307;
    float f_308;
    char pad30c[0x04];
    LocalM128 v_310;
    LocalM128 v_320;
    int i_330;
    int i_334;
    int i_338;
    char pad33c[0x04];
    unsigned char b_340;
    void hkpWorld_getCinfo(Dst_00c91c50* pOut);
};
struct MatchAllocator {
    virtual void v00();
    virtual void* allocate(int size);
};
struct MatchRouter {
    int unk00, unk04, unk08, unk0C;
    MatchAllocator* heap;
};
struct FUN_00d065e0 {
    void* vtable;
    unsigned short memorySize;
    short referenceCount;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned char active;
    unsigned char unk41, unk42, unk43;
    FUN_00d065e0() throw();
    static void* operator new(unsigned int size)
    {
        MatchRouter* router = (MatchRouter*)::hkMemoryRouter_getInstance();
        FUN_00d065e0* memory = (FUN_00d065e0*)router->heap->allocate(size);
        memory->memorySize = (unsigned short)size;
        return memory;
    }
    void hkpPhysicsSystem_addPhantom(void* phantom);
};
struct MatchStatus {
    unsigned char value;
    MatchStatus(bool v) : value(v) {}
    operator bool() const { return value != 0; }
};
struct MatchPhantoms {
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14;
    void* p18; void* p1C; void* p20; void* p24; void* p28; void* p2C;
};
struct MatchWorld {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    void** phantoms;
    int phantomCount;
    MatchPhantoms* GetValue();
    void __thiscall AddPhysicsSystem(hkArray<FUN_00d065e0*>* systems);
};
struct FUN_00d065e0Value { FUN_00d065e0* p; };
MatchStatus __cdecl AddBodiesToSystem(MatchWorld*, FUN_00d065e0*);
MatchStatus __cdecl CollectShapes(MatchWorld*, FUN_00d065e0*);
// src: HAVOK_LIB 0x00c92950
static __declspec(noinline) void enumerateAllPhantomsInWorld(MatchWorld* world, FUN_00d065e0* system)
{
    MatchPhantoms* excluded = world->GetValue();
    if (excluded) {
        for (int i=0; i<world->phantomCount; ++i) {
            void* p = world->phantoms[i];
            if (p != excluded->p18 && p != excluded->p1C && p != excluded->p20 &&
                p != excluded->p24 && p != excluded->p28 && p != excluded->p2C)
                system->hkpPhysicsSystem_addPhantom(p);
        }
    } else {
        for (int i=0; i<world->phantomCount; ++i)
            system->hkpPhysicsSystem_addPhantom(world->phantoms[i]);
    }
}
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
extern unsigned int DAT_0126835c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned int);
extern const char str_010c6758[];
extern const char str_010c6748[];
extern const char str_010c6734[];
extern const char str_010c6720[];
extern const char str_01076f38[];


struct ThreadAlloc {
    char* m_next;             // next free stack byte
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    hkMemoryAllocator* m_pThreadAllocator;   // +0x10
};
class BroadPhaseC944 {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C(); virtual void v10();
    virtual void v14(); virtual void v18(); virtual void v1C(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2C(); virtual void v30(); virtual void v34(); virtual void v38();
    virtual void v3C(); virtual void v40(); virtual void v44();
    virtual void updateOverlaps(struct HandleC944* a, struct TempArray* arr);   // vtable +0x48
};
struct WorldObjectC944;
struct CollidableC944;
struct HandleC944 {
    unsigned int m_iOwnerObjectOffset;
    unsigned char m_type;
    signed char m_iOwnerOffset;
    unsigned char m_ucObjectQualityType;
    unsigned int m_uiCollisionFilterData;
    CollidableC944* getOwner() { return reinterpret_cast<CollidableC944*>(reinterpret_cast<char*>(this) + m_iOwnerOffset); }
};
struct CollidableC944 : hkpCdBody {
    signed char m_iOwnerOffset;
    unsigned char m_uiForceCollideOntoPpu;
    unsigned short m_uiShapeSizeOnSpu;
    HandleC944 m_kBroadPhaseHandle;
    WorldObjectC944* getOwner() { return reinterpret_cast<WorldObjectC944*>(reinterpret_cast<char*>(this) + m_iOwnerOffset); }
};
struct FilterResult { char value; FilterResult() {} FilterResult(bool b) : value(b) {} FilterResult(const FilterResult& b) : value(b.value) {} };
struct WorldObjectC944 : hkReferencedObject {
    hkpWorld* m_pOwningWorld;
    unsigned int m_ulUserData;
    CollidableC944 m_kCollidable;
    virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10();
    virtual void v14(); virtual void v18();
};
struct BroadPhaseC944HandlePair { HandleC944* first; HandleC944* second; };
struct TempArray {
    BroadPhaseC944HandlePair* m_data; // +0x00
    int m_iElementCount;                // +0x04
    int m_iCapacityState;    // +0x08
    char* m_original;
    TempArray(int count) : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000u) {
        ThreadAlloc* storage = (ThreadAlloc*)hkMemoryRouter_getInstance();
        char* top = storage->m_next;
        storage->m_next = top + ((count * sizeof(BroadPhaseC944HandlePair) + 127) & ~127);
        m_data = (BroadPhaseC944HandlePair*)top;
        m_original = top;
        m_iCapacityState = count | 0x80000000u;
    }
    void releaseStack() {
        char* oldTop = m_original;
        if ((void*)oldTop == m_data) m_iElementCount = 0;
        ((ThreadAlloc*)hkMemoryRouter_getInstance())->m_next = oldTop;
    }
    void releaseHeap(hkMemoryAllocator& heap) {
        m_iElementCount = 0;
        if (!(m_iCapacityState & 0x80000000u))
            heap.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(BroadPhaseC944HandlePair));
        m_data = 0;
        m_iCapacityState = 0x80000000u;
    }
};
struct PendingOp {
    unsigned char m_type;      // +0x00
    void* m_p;                 // +0x04
    unsigned char m_flag;      // +0x08
};
static __declspec(noinline) void SyncOverlap(hkpPhantom* phantom,CollidableC944* collidable,hkpCollisionFilter* filter)
{
    OverlapResult added = phantom->overlaps(reinterpret_cast<OverlapCollidable*>(collidable));
    if (static_cast<hkpCollidableCollidableFilter*>(filter)->IsCollisionEnabled(reinterpret_cast<const hkpCollidable&>(phantom->m_kCollidable), reinterpret_cast<const hkpCollidable&>(*collidable))) {
        if (!added.value) phantom->add(reinterpret_cast<OverlapCollidable*>(collidable));
        if (collidable->m_kBroadPhaseHandle.m_type == 2) {
            if (!reinterpret_cast<hkpPhantom*>(collidable->getOwner())->overlaps(reinterpret_cast<OverlapCollidable*>(&phantom->m_kCollidable)).value)
                reinterpret_cast<hkpPhantom*>(collidable->getOwner())->add(reinterpret_cast<OverlapCollidable*>(&phantom->m_kCollidable));
        }
    } else {
        if (added.value) phantom->remove(reinterpret_cast<OverlapCollidable*>(collidable));
        if (collidable->m_kBroadPhaseHandle.m_type == 2) {
            if (reinterpret_cast<hkpPhantom*>(collidable->getOwner())->overlaps(reinterpret_cast<OverlapCollidable*>(&phantom->m_kCollidable)).value)
                reinterpret_cast<hkpPhantom*>(collidable->getOwner())->remove(reinterpret_cast<OverlapCollidable*>(&phantom->m_kCollidable));
        }
    }
}
struct PhantomArgC944 { hkpPhantom* p; PhantomArgC944(hkpPhantom* q) : p(q) {} };
struct WorldC944 : hkpWorld { void UpdatePhantom(hkpPhantom*, int); void hkpWorld_queueOperation(PendingOp*); void FUN_00c91120(); void UpdateFields_00c91140(); };
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
inline void* getMemoryRouter() throw() { return &hkRouterXc937a0::hkMemoryRouter_getInstance(); }
extern "C" void __cdecl hkArrayUtil__reserve(void* inst, void* arr, int num, int elemSize) throw();
extern "C" void __cdecl hkpWorldCallbackUtil_fireEntityRemoved(hkpWorld* world, void* entity) throw();
extern "C" void __cdecl hkpEntityCallbackUtil_fireEntityRemoved(void* entity) throw();
extern "C" void __cdecl hkpWorldOperationUtil_removeEntitySI(hkpWorld* world, void* entity) throw();
struct MyPendingQueue {
    void __thiscall hkpWorld_queueOperation(void* op) throw();
};
struct FUN_00cf70f0_Class {
    void __thiscall DispatchPairs(void* data, int size) throw();
};
struct FUN_00d01a80_Class {
    void __thiscall FreeStorage() throw();
};
struct FUN_00c905b0_Class {
    void __thiscall FUN_00c905b0() throw();
};
struct MyExecPending {
    void __thiscall ExecutePendingOperations() throw();
    void __thiscall FUN_00c91120() throw();
};
struct MyExecBodyPending {
    void __thiscall UpdateFields_00c91140() throw();
};


struct DummyCollidable_00c951b0 {
    void* m_pCollisionShape;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_kBroadPhaseHandle;
};
struct EntityMember {
    void* unk00; void* unk04; void* unk08; void* unk0c;
    void* unk10; void* unk14; void* unk18; void* unk1c; void* unk20;
    void FreeStorage() throw();
};
struct DummyEntity_00c951b0 {
    virtual ~DummyEntity_00c951b0() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0c() throw();
    virtual void v10() throw();
    virtual void v14() throw();
    short memSizeAndFlags;
    short referenceCount;
    void* unk08;
    void* unk0c;
    DummyCollidable_00c951b0 collidable;
    void* unk28;
    void* unk2c;
    EntityMember member;
    void* world;
};
struct WorldOp_00c951b0 {
    unsigned char m_type;
    unsigned char pad0;
    unsigned short pad1;
    void* m_kActorEntries;
    short m_iActorEntryCount;
};



template <class T>
struct MyArray {
    hkArray<T>& base;
    inline MyArray(hkArray<T>& b) throw() : base(b) { base.m_data=0; base.m_iElementCount=0; base.m_iCapacityState=0x80000000; }

    inline ~MyArray() throw() {
        hkMemoryRouter* tm = (hkMemoryRouter*)getMemoryRouter();
        hkMemoryAllocator* memory = &tm->temp();
        base.m_iElementCount = 0;
        if ((base.m_iCapacityState & 0x80000000) == 0) {
            memory->ReturnMemory(base.m_data, (base.m_iCapacityState & 0x3fffffff) * sizeof(T));
        }
    }

    inline void reserve(void* tm, int num) throw() {
        if ((base.m_iCapacityState & 0x3fffffff) < num) {
            hkArrayUtil__reserve(&((hkMemoryRouter*)tm)->temp(), &base, num, sizeof(T));
        }
    }

    inline void pushBackUnchecked(const T& val) throw() {
        base.m_data[base.m_iElementCount++] = val;
    }
};
// Two pointer fields used by MyLocalArray; include/Pair.h instead stores two integers and has value constructors.
struct PointerPairRecord {
    void* a;
    void* b;
};
struct MyLocalArray : public hkArrayBase<PointerPairRecord> {
    PointerPairRecord* m_savedStack;

    inline MyLocalArray(int capacity) throw() {
        hkMemoryRouter* tm = (hkMemoryRouter*)getMemoryRouter();
        char* cur = static_cast<char*>(tm->stack().m_next.val());
        tm->stack().m_next = cur + ((capacity * sizeof(PointerPairRecord) + 127) & ~127);
        this->m_data = (PointerPairRecord*)cur;
        this->m_savedStack = (PointerPairRecord*)cur;
        this->m_iCapacityState = capacity | 0x80000000;
    }

    inline ~MyLocalArray() throw() {
        PointerPairRecord* savedStack = m_savedStack;
        if (savedStack == this->m_data) {
            this->m_iElementCount = 0;
        }
        hkMemoryRouter* stackRouter = (hkMemoryRouter*)getMemoryRouter();
        stackRouter->stack().m_next = savedStack;
        hkMemoryRouter* tm = (hkMemoryRouter*)getMemoryRouter();
        hkMemoryAllocator* memory = &tm->heap();
        this->m_iElementCount = 0;
        if ((this->m_iCapacityState & 0x80000000) == 0) {
            memory->bufFree(this->m_data, (this->m_iCapacityState & 0x3fffffff) * sizeof(PointerPairRecord));
        }
    }
};
union TimerOrEnd { volatile unsigned int stamp; void* const* end; };
struct HostWorld_00c951b0 : hkpWorld {
    void RemoveEntities(void* const* entityBatch, int numEntities) throw();
};
struct Op { char type; int p; };
struct Pt { unsigned short x; unsigned short pad; unsigned short y; };
struct Req { char k; Req(char c):k(c){} Req(const Req& o):k(o.k){} };
struct Info { int u0, u1, cnt; };
struct Sub {
  virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
  virtual int T20();
  virtual void T24(Req r, Pt* out);
};
struct Item;
struct Dev {
  virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
  virtual int T20();
  virtual void T24(Req r, Pt* out);
};
struct Item {
  virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5();
  virtual int T18();
  virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15();
  virtual void T40();
  int u04, u08;
  struct Ctl3* m_0c;
  int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30;
  unsigned int m_34;
  int unk38; int unk3c; int unk40;
  Info* m_44;
  void hkpConstraintInstance_pointNullsToFixedRigidBody();
};
struct Ctl3 {
  virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
  virtual int T20();
  virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15();
  virtual void T40();
  int unk04; int unk08; int unk0c; int unk10; int unk14;
  Sub* m_18; unsigned short m_1c, m_1e;
};
struct Mgr {
  void* unk00;
  void* unk04;
  void* unk08;
  void* unk0C;
  void* unk10;
  void* unk14;
  void* unk18;
  void* unk1C;
  void* unk20;
  void* unk24;
  void* unk28;
  void* unk2C;
  void* unk30;
  void* unk34;
  void* unk38;
  void* unk3C;
  void* unk40;
  void* unk44;
  void* unk48;
  void* unk4C;
  void* unk50;
  void* unk54;
  void* unk58;
  void* unk5C;
  void* unk60;
  void* unk64;
  void* unk68;
  void* unk6C;
  void* unk70;
  void* unk74;
  void* unk78;
  void* unk7C;
  void* unk80;
  void* unk84;
  void* unk88;
  void* m_8c; unsigned int m_90; unsigned int m_94; unsigned int m_98; char m_9c;
  char unk9d, unk9e, unk9f; int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc; int unkc0; int unkc4; int unkc8; int unkcc; int unkd0; int unkd4; int unkd8; int unkdc; int unke0; int unke4; int unke8; int unkec; int unkf0; int unkf4; int unkf8; int unkfc; int unk100; int unk104; int unk108;
  unsigned int m_10c;
  void hkpWorld_queueOperation(Op* o);
  void FUN_00c91120();
  void hkpWorld_addAction(Info* i);
  void* hkpWorld_addConstraint(Item* it);
};
extern void* __cdecl hkpWorldOperationUtil_addConstraintImmediately(Mgr*, Item*, unsigned int);
static unsigned char enumerateAllEntitiesInWorld(MatchWorld* world, FUN_00d065e0* system);
MatchWorld* volatile g_matchWorld;
FUN_00d065e0* volatile g_matchSystem;
volatile unsigned char g_matchResult;
void CallMatchSystem();
void __stdcall hkpWorld_UpdateState_00c982d0(unsigned char* out, int a2, int a3);
struct S96_BoolResult {char value;};
extern const char str_010c6908[];
struct S96_TimerEntry {const char* name; unsigned tick; unsigned unk08;};
struct S96_Timer {int unk00; S96_TimerEntry* unk04; int unk08; S96_TimerEntry* unk0C;};
struct S96_Allocator {virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void Free(void*,int);};
struct S96_AllocatorHolder {int unk00,unk04,unk08,unk0C; S96_Allocator* unk10;};
struct S96_Collidable {int unk00,unk04,unk08,unk0C,unk10,unk14; short unk18; signed char unk1A;};
struct S96_Constraint {unsigned char unk00,unk01,unk02,unk03; int unk04,unk08,unk0C; S96_Collidable* unk10; S96_Collidable* unk14;};
struct S96_EntityArray {void** data; int size; int capacity;};
struct S96_Island { int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; unsigned char unk24,unk25; short unk26; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; S96_EntityArray unk48; int unk54; int unk58; S96_Constraint** unk5C; int unk60;};
struct S96_IslandArray {S96_Island** data; int size; int capacity;};
struct S96_FilterCheck {virtual void slot0(); virtual S96_BoolResult Check(S96_Collidable*,S96_Collidable*);};
struct S96_Filter {int unk00,unk04; S96_FilterCheck unk08;};
struct S96_Operation {unsigned char unk00,unk01,unk02,unk03;};
void __cdecl _hkAgentNnMachine_UpdateShapeCollectionFilter(S96_Constraint*,void*,S96_Island*);
void __cdecl hkpWorldAgentUtil_removeAgentAndItsToiEvents(S96_Constraint*);
struct S96_RemovalList {S96_Constraint** data; int size; int capacity; S96_Constraint* local[32]; void clear(){size=0;} int GetLogicalSize() const {return size;} S96_Constraint*& back(){return data[size-1];} void popBack(){--size;}};
struct S96_WorldShell : hkpWorld {
 void hkpWorld_queueOperation(const S96_Operation&); void hkpWorld_updateCollisionFilterOnEntity(void*,int,int); void UpdatePhantom(void*,int); void FUN_00c91120(); void UpdateFields_00c91140();
 __forceinline void S96_attempt() {
  if(!m_iCriticalOperationsLockCount && !m_bBlockExecutingPendingOperations) {
   if(m_iPendingOperationCount) FUN_00c91120();
   if(m_iPendingOperationQueueCount==1 && m_iQueuedOperationCount) UpdateFields_00c91140();
  }
 }
 static __forceinline void S96_TimerBegin(const char* name) {
  S96_Timer* timer=(S96_Timer*)TlsGetValue(DAT_0126835c);
  if(timer->unk04<timer->unk0C) {
   S96_TimerEntry* entry=timer->unk04;
   entry->name=name;
   unsigned tick;
   __asm {
    rdtsc
    mov dword ptr[tick], eax
   }
   entry->tick=tick;
   timer->unk04=entry+1;
  }
 }
 static __forceinline void S96_TimerEnd() {
  S96_Timer* timer=(S96_Timer*)TlsGetValue(DAT_0126835c);
  if(timer->unk04<timer->unk0C) {
   S96_TimerEntry* entry=timer->unk04;
   entry->name=str_010c41f8;
   unsigned tick;
   __asm {
    rdtsc
    mov dword ptr[tick], eax
   }
   entry->tick=tick;
   timer->unk04=entry+1;
  }
 }
 __forceinline bool S96_enabled(S96_Constraint* c) {
  return ((S96_Filter*)m_pCollisionFilter)->unk08.Check(c->unk10,c->unk14).value && ((char*)m_pDispatcher)[0x1bb0+c->unk10->unk1A*10+c->unk14->unk1A];
 }
 void hkpWorld_updateCollisionFilterOnWorld(int mode,int update);
};
extern double DAT_01011588;
extern const char str_010c699c[];
extern const char str_010c698c[];
extern const char str_010c697c[];
extern const char str_010c6970[];
extern const char str_010c6964[];
extern const char str_010c6938[];
extern const char str_010c692c[];
extern const char str_010c6920[];
extern const char str_01076f38[];
struct S97_Bool {
    char m_cBooleanValue;
    inline S97_Bool(bool b) { m_cBooleanValue = static_cast<char>(b); }
    inline operator bool() const { return m_cBooleanValue != 0; }
};
template <class T> struct S97_PadSpu {
    T m_kStorage;
    __forceinline T val() const { return m_kStorage; }
    __forceinline T operator->() const { return m_kStorage; }
    __forceinline void operator=(const T& t) { m_kStorage = t; }
};

static __forceinline void S97_timerList(const char* name1, const char* name2)
{
    hkMonitorStream& mStream = *(hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (mStream.m_end.m_storage < mStream.m_capacityMinus16.m_storage) {
        hkMonitorStream::TimerBeginListCommand* h = reinterpret_cast<hkMonitorStream::TimerBeginListCommand*>(mStream.m_end.m_storage);
        h->m_commandAndMonitor = name1;
        h->m_nameOfFirstSplit = name2;
        h->setTime();
        mStream.m_end.m_storage = (char*)(h + 1);
    }
}
static __forceinline void S97_timer(const char* name)
{
    hkMonitorStream& mStream = *(hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (mStream.m_end.m_storage < mStream.m_capacityMinus16.m_storage) {
        hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.m_end.m_storage);
        h->m_commandAndMonitor = name;
        h->setTime();
        mStream.m_end.m_storage = (char*)(h + 1);
    }
}


struct S97_HeapAllocator { __forceinline hkMemoryAllocator& get(const void*) { return hkMemoryRouter::getInstance().heap(); } };
struct S97_TempAllocator { __forceinline hkMemoryAllocator& get(void*) { return hkMemoryRouter::getInstance().temp(); } };
template <class T>
static __forceinline void S97_ArrayBase_clear(hkArrayBase<T>& self);

template <class T>
static __forceinline void S97_ArrayBase__clearAndDeallocate(hkArrayBase<T>& self, hkMemoryAllocator& alloc);

template <class T>
static __forceinline void S97_ArrayBase_clear(hkArrayBase<T>& self)
{ self.m_iElementCount = 0; }

template <class T>
static __forceinline void S97_ArrayBase__clearAndDeallocate(hkArrayBase<T>& self, hkMemoryAllocator& alloc)
{
        S97_ArrayBase_clear(self);
        if ((self.m_iCapacityState & 0x80000000) == 0) {
            alloc._bufFree<T>(self.m_data, self.getCapacity());
        }
        self.m_data = 0;
        self.m_iCapacityState = 0x80000000;
    }
template <typename T, typename A> struct S97_Array : public hkArrayBase<T> {
    __forceinline S97_Array() {}
    __forceinline S97_Array(T* buffer, int size, int capacity) : hkArrayBase<T>(buffer, size, capacity) {}
    __forceinline void ClearAndRelease() { hkArrayBase<T>::_clearAndDeallocate(A().get(this)); }
};
template <typename T, unsigned N> struct S97_InplaceArray : public S97_Array<T, S97_HeapAllocator> {
    __forceinline explicit S97_InplaceArray(int size = 0) : S97_Array<T, S97_HeapAllocator>(m_kStorage, size, N) {}
    T m_kStorage[N];
};
struct S97_Aabb;
struct S97_Shape {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18();
    virtual void getAabb(const void* localToWorld, float tolerance, S97_Aabb& out) const;
    int unk04; int unk08; int m_type;
    __forceinline int getType() const { return m_type; }
};
struct S97_Collidable {
    const S97_Shape* m_pCollisionShape; unsigned int m_uiCollisionShapeKey; const void* m_pMotionState; const void* m_parent;
    __forceinline const S97_Shape* getShape() const { return m_pCollisionShape; }
    __forceinline const void* getTransform() const { return m_pMotionState; }
};
struct S97_CollisionInput;
typedef void (__cdecl* S97_GetClosestPointsFunc)(const S97_Collidable&, const S97_Collidable&, const S97_CollisionInput&, void*);
struct S97_AgentFuncs { S97_GetClosestPointsFunc m_pGetPenetrationsFunc; int f04; int f08; int f0C; int f10; };
struct S97_DispatcherHead {
    int unk000; int unk004; int unk008; int unk00C;
};
struct S97_Dispatcher {
    __forceinline S97_GetClosestPointsFunc getGetClosestPointsFunc(int typeA, int typeB) const
    {
        const unsigned char (*agent2Types)[32] = (const unsigned char (*)[32])((const char*)this + 0x1a0);
        const S97_AgentFuncs* agent2Func = (const S97_AgentFuncs*)((const char*)this + 0x9a8);
        int idx = agent2Types[typeA][typeB];
        return agent2Func[idx].m_pGetPenetrationsFunc;
    }
};
struct S97_CollisionInput {
    S97_PadSpu<S97_Dispatcher*> m_pCollisionDispatcher;
    int unk04;
    float m_fScalar;
    __forceinline float getTolerance() const { return m_fScalar; }
};
struct S97_CcFilter {
    virtual void v00();
    virtual S97_Bool IsCollisionEnabled(const S97_Collidable& a, const S97_Collidable& b) const;
};
struct S97_RefObject { virtual ~S97_RefObject(); unsigned short m_usMemSizeAndFlags; short m_sReferenceCount; };
struct S97_CollisionFilter : public S97_RefObject, public S97_CcFilter {};
struct __declspec(align(16)) S97_Aabb { float m_kMinimumCorner[4]; float m_kMaximumCorner[4]; };
struct S97_TypedHandle {
    int m_iOwnerObjectOffset; signed char m_type; signed char m_iOwnerOffset;
    __forceinline void* getOwner() const { return const_cast<char*>(reinterpret_cast<const char*>(this) + m_iOwnerOffset); }
};
struct S97_HandlePair { S97_TypedHandle* m_kPointA; S97_TypedHandle* m_kPointB; };
struct S97_BroadPhase {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40();
    virtual void FindOverlappingPairs(const S97_Aabb& aabb, hkArrayBase<S97_HandlePair>& pairsOut) const;
};
struct S97_TreeWorldManager {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual bool isUpToDate() const;
    int unk04; int unk08; const void* m_pRayQueryAabbTree; const void* m_pKdTree;
    __forceinline const void* getAabbTree() const { return m_pRayQueryAabbTree; }
    __forceinline const void* getKdTree() const { return m_pKdTree; }
};
void __cdecl Object_CollectAABBTreeHits(const void* tree, const S97_Aabb* aabb, void* callback, hkArrayBase<void*>* hits, void* mask, void* context);
__declspec(noinline) void __cdecl CallWithDefaults(const void* tree, const S97_Aabb& aabb, hkArrayBase<void*>& hits) {
    if (tree) Object_CollectAABBTreeHits(tree, &aabb, 0, &hits, 0, 0);
}
void __cdecl hkKdTreeAabbQueryUtils_queryAabbIterative(const void* tree, const S97_Aabb& aabb, S97_Array<unsigned long, S97_TempAllocator>& hits);
struct S97_World {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54;
    S97_BroadPhase* m_pJobSemaphore;
    S97_TreeWorldManager* m_pKdTreeManager;
    int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74;
    S97_CollisionInput* m_pCollisionInput;
    S97_CollisionFilter* m_pCollisionFilter;
    inline const S97_CollisionInput* getCollisionInput() const { return m_pCollisionInput; }
    inline const S97_CollisionFilter* getCollisionFilter() const { return m_pCollisionFilter; }
    void hkpWorld_getClosestPoints(const S97_Collidable* collA, const S97_CollisionInput& input, void* collector) const;
};
namespace std{ class type_info; }
typedef float TR;
typedef float TF32;
typedef double TD64;
typedef signed char TC;
typedef signed char TI8;
typedef signed short TI16;
typedef signed int TI32;
typedef unsigned char TU;
typedef unsigned char TU8;
typedef unsigned short TU16;
typedef unsigned int TU32;
typedef unsigned long __w64 TU1;
typedef signed long __w64 TL;
typedef void*Tvl;
enum TR1{ KS=0,KF=1} ;
typedef unsigned __int64 TU64;
typedef __int64 TI64;
typedef long TST2;
typedef unsigned __w64 TS4;
typedef TU16 TOI;
typedef TR TT;
__forceinline TL __cdecl TGBO(const void*base,const void*pntr)throw(){ return TL(pntr)-TL(base);
}
template<typename TYPE>__forceinline TYPE*__cdecl TABO(TYPE*base,TL offset)throw(){ return reinterpret_cast<TYPE*>(reinterpret_cast<char*>(base)+offset); }
class TFLOF{ public:TFLOF()throw():vf1(0){ } int vf1;
} ;
class TC1;
struct TV;
typedef int TB32;
class TB{ public:typedef char CompileTimeTrueType; typedef int CompileTimeFalseType;
inline TB()throw(){ } inline TB(bool b)throw(){ vb1=static_cast<char>(b);
} inline operator bool()const{ return vb1!=0; }
inline TB&operator=(bool e)throw(){ vb1=static_cast<char>(e); return*this; }
inline TB operator==(bool e)const throw(){ return static_cast<int>(vb1)==static_cast<int>(e); } inline TB operator!=(bool e)const throw(){
return static_cast<int>(vb1)!=static_cast<int>(e); } private:char vb1; }
;
class TH{ public:inline operator float()const; private:TI16 vv;
} ;
extern"C"{ extern const TR TUF8iTR[256];
}
class TUF8{ public:enum{ MAX_VALUE=256}
; inline operator float()const; public:TU8 vv; }
;
extern"C"{ extern const TR TUI8TR[256]; }
template<typename ENUM,typename STORAGE>class TE1{ public:TE1()throw(){ } TE1(ENUM e)throw(){
vs8=static_cast<STORAGE>(e); } operator ENUM()const{ return static_cast<ENUM>(vs8);
} void operator=(ENUM e)throw(){ vs8=static_cast<STORAGE>(e); }
TB operator==(ENUM e)const throw(){ return vs8==static_cast<STORAGE>(e); } TB operator!=(ENUM e)const throw(){
return vs8!=static_cast<STORAGE>(e); } private:STORAGE vs8; }
;
template<typename BITS,typename STORAGE>class TF;
template<typename TYPE>class TPS{ public:__forceinline TPS()throw(){
} __forceinline TPS(TYPE e)throw():vs8(e){ } __forceinline void operator=(TYPE e)throw(){
vs8=e; } __forceinline TYPE val()const throw(){ return vs8;
} __forceinline TYPE operator->()const throw(){ return vs8; }
__forceinline operator TYPE()const{ return val(); } private:TYPE vs8;
} ;
struct TCOBAC;
enum KMC{
KMCR,KMCB,KMCC5,KMCCS1,KMCD4,KMCE1,KMCS1,KMCG,KMCD3,KMCM2,KMCSD,KMCV1,KMCD1,KMCU5,KMCA4,KMCB1,KMCC3,KMCA2,KMCT,KMCDF,KMCD,KMCU,KMCBC,KMCS6,KMCA5,KMCS4,KMCS,KMCS5,KMCM4,KMCM1,KMCT1,KMCH,KMCA1,KMCA3,KMCBP,KMCC7,KMCD2,KMCM,KMCS2,KMCC4,KMCC1,KMCM5,KMCA,KMCD5,KMCC6,KMCE,KMCM6,KMCW,KMCRB,KMCP1,KMCS3,KMCC,KMCC2,KMCV,KMCI,KMCAU,KMCAC1,KMCAD,KMCAM,KMCAR,KMCAC2,KMCAR1,KMCAC,KMCBR,KMCBD,KMCCR,KMCCD,KMCCS,KMCAN,KMCAA,KMCAS,KMCU1,KMCU2,KMCU3,KMCU4,KMCPA,KMCM3} ;
template<typename T>class TTLD{ public:__forceinline T getData()const throw(){
return(T)(TU1)TlsGetValue(vsI1); } unsigned long vsI1; }
;
typedef std::type_info TCTI;
struct TCTIH;
class TCRIU;
template<typename T>struct TSOTOV{ enum{ val=sizeof(T)} ;
} ;
template<>struct TSOTOV<void>{ enum{
val=1} ; } ;
class TMA{ public:struct SixUnsignedValueRecord{ static const TS4 INFINITE_SIZE=(TS4(0)-1); TS4 va3;
TS4 viU; TS4 vpIU; TS4 va4; TS4 vtA;
TS4 vlB; } ; virtual~TMA()throw();
virtual void*AllocateMemoryBlock(int numBytes)throw()=0; virtual void ReleaseBlock(void*p,int numBytes)throw()=0; virtual void vs0()throw(); virtual void ReturnMemory(void*p,int numBytes)throw();
virtual void vs11()throw(); virtual void vs21()throw(); virtual void vs31()throw(); virtual void vs41()throw();
virtual void vs51()throw(); virtual void vs61()throw(); virtual void vs71()throw(); virtual void vs81()throw();
template<typename TYPE>inline void _bufFree(void*p,int numElem)throw(){ const int SIZE_ELEM=TSOTOV<TYPE>::val; ReturnMemory(p,numElem*SIZE_ELEM); }
public:enum MemoryState{ MEMORY_STATE_OK,MEMORY_STATE_OUT_OF_MEMORY} ; }
;
namespace TMU{ template<unsigned int NBYTES>struct IntegerTypeByByteSize; template<>struct IntegerTypeByByteSize<1>;
template<>struct IntegerTypeByByteSize<2>; template<>struct IntegerTypeByByteSize<4>; template<>struct IntegerTypeByByteSize<8>; template<unsigned int NBYTES>struct IntegerTypeByByteSize;
}
namespace TMU{ }
struct TSM{
public:static TSM&GetMonitorStream()throw(); void*allocateStack(int numBytes,const char*what)throw(); __forceinline void deallocateStack(void*p)throw(); __forceinline void deallocateStack(int numBytes)throw();
__forceinline int getFreeStackSize()throw(){ return int(TGBO(vn1,ve)); } protected:TPS<void*>vn1;
TPS<void*>vs7; TPS<void*>ve; } ;
__forceinline void*TSM::allocateStack(int numBytes,const char*what)throw(){ ; if(numBytes>getFreeStackSize()){ ;
} void*current=vn1; vn1=TABO(current,numBytes); return current;
}
void TSM::deallocateStack(void*p)throw(){ ; vn1=p;
}
void TSM::deallocateStack(int numBytes)throw(){ vn1=TABO(vn1.val(),-numBytes); ;
}
class TO1;
class TMR{ public:typedef TMA Allocator;
static TMR&__cdecl hkMemoryRouter_getInstance()throw(); inline TSM&stack()throw(){ return vs6; }
inline Allocator&temp()throw(){ return*vt1; } inline Allocator&heap()throw(){
return*vh; } protected:TSM vs6; Allocator*vt1;
Allocator*vh; Allocator*vd2; Allocator*vs5; Allocator*vg;
void*vuD; } ;
template<typename TYPE>__forceinline void __cdecl TDC(TYPE*ptr,int numberOfObjects,int cl)throw(){
TMR::hkMemoryRouter_getInstance().heap().ReleaseBlock(static_cast<void*>(ptr),numberOfObjects*TSOTOV<TYPE>::val); }
template<typename TYPE>__forceinline TYPE*__cdecl TAS1(int n,const char*what=0)throw(){ TMR&mem=TMR::hkMemoryRouter_getInstance();
return static_cast<TYPE*>(mem.stack().allocateStack((((n*TSOTOV<TYPE>::val)+((128)-1))&(~((128)-1))),what)); }
template<typename TYPE>__forceinline void __cdecl TDS(TYPE*ptr)throw(){ TMR::hkMemoryRouter_getInstance().stack().deallocateStack(static_cast<void*>(ptr));
}
extern const TC1 TBOC;
class TBO{ public:__forceinline virtual~TBO()throw();
public:} ;
extern const TC1 TROC;
class TSC3;
class TCS2;
class TVCR;
class TRO:public TBO{ public:virtual~TRO()throw();
void FUN_00c90510()const throw(); enum LockMode{ LOCK_MODE_NONE,LOCK_MODE_AUTO,LOCK_MODE_MANUAL} ;
virtual void vs9()const throw(); virtual void vs10()const throw(); public:enum{ MASK_MEMSIZE=0x7fff}
; TU16 vmSAF; mutable TI16 vrC; public:}
;
template<typename T>class TS3;
extern struct TSIN*TSIL;
struct TSIN;
class TO1;
class TSW;
class TS6;
class TSP;
class TSB1;
class TMT;
struct TCHA;
template<typename T,typename A>class TA2;
class TO1;
typedef TO1 TO;
class TE2;
class TES;
typedef void(__cdecl*TERF)(const char*s,void*errorReportObject);
namespace TCE2{ template<bool b>struct BooleanTrueSpecialization; template<>struct BooleanTrueSpecialization<true>;
template<bool b>struct TrueOnlyTrait; template<>struct TrueOnlyTrait<true>; }
template<class TYPE>class TRP{
public:__forceinline TYPE*val()const throw(); __forceinline operator TYPE*()const; private:TYPE*vp4; }
;
template<class TYPE>__forceinline TYPE*TRP<TYPE>::val()const throw(){ return vp4; }
struct TPNA;
inline void*operator new(TS4,TPNA*p){ return p; }
template<bool N>struct TTB{ typedef TTB<N>type; enum{ result=N}
; } ;
typedef TTB<true>TTIP;
typedef TTB<false>TTIC;
template<typename T>TB::CompileTimeFalseType operator==(const T&,const TTIP&)throw();
template<typename T>struct TIPT:public TTB<(sizeof(*static_cast<T*>(0)==*static_cast<const TTIP*>(0))==sizeof(TB::CompileTimeTrueType))>{ }
;
template<>struct TIPT<bool>:public TTIP{ } ;
;
template<>struct TIPT<TB>:public TTIP{ } ;
;
template<>struct TIPT<char>:public TTIP{ } ;
;
template<>struct TIPT<TI8>:public TTIP{ } ;
;
template<>struct TIPT<TU8>:public TTIP{ } ;
;
template<>struct TIPT<TI16>:public TTIP{ } ;
;
template<>struct TIPT<TU16>:public TTIP{ } ;
;
template<>struct TIPT<TI32>:public TTIP{ } ;
;
template<>struct TIPT<TU32>:public TTIP{ } ;
;
template<>struct TIPT<TI64>:public TTIP{ } ;
;
template<>struct TIPT<TU64>:public TTIP{ } ;
;
template<>struct TIPT<TL>:public TTIP{ } ;
;
template<>struct TIPT<TU1>:public TTIP{ } ;
;
template<>struct TIPT<TUF8>:public TTIP{ } ;
;
template<>struct TIPT<TH>:public TTIP{ } ;
;
template<>struct TIPT<TR>:public TTIP{ } ;
;
template<>struct TIPT<TD64>:public TTIP{ } ;
;
template<>struct TIPT<TV>:public TTIP{ } ;
;
template<typename T>struct TIPT<T*>:public TTIP{ } ;
template<typename T,unsigned int N>struct TIPT<T[N]>:public TIPT<T>{ } ;
class TAU{
public:template<typename T>static __forceinline void construct(T*t,int n,TTIP)throw(); template<typename T>static __forceinline void construct(T*t,int n,TTIC)throw(); template<typename T>static __forceinline void constructWithCopy(T*t,int n,const T&tcopy,TTIP)throw(); template<typename T>static __forceinline void constructWithCopy(T*t,int n,const T&tcopy,TTIC)throw();
template<typename T>static __forceinline void destruct(T*t,int n,TTIP)throw(); template<typename T>static __forceinline void destruct(T*t,int n,TTIC)throw(); static void __cdecl hkArrayUtil__reserve(TMA&a,void*,int reqElem,int sizeElem)throw(); static void __cdecl ResizeAudioStream(TMA&a,void*array,int sizeElem)throw();
} ;
template<typename T>__forceinline void TAU::construct(T*t,int n,TTIP)throw(){ }
template<typename T>__forceinline void TAU::construct(T*t,int n,TTIC)throw(){ for(int i=0;i<n;++i){ ::new(reinterpret_cast<TPNA*>(t+i))T; }
}
template<typename T>__forceinline void TAU::constructWithCopy(T*t,int n,const T&tcopy,TTIP)throw(){ for(int i=0;i<n;++i){ t[i]=tcopy;
} }
template<typename T>__forceinline void TAU::constructWithCopy(T*t,int n,const T&tcopy,TTIC)throw(){ for(int i=0;i<n;++i){
::new(reinterpret_cast<TPNA*>(t+i))T(tcopy); } }
template<typename T>__forceinline void TAU::destruct(T*t,int n,TTIP)throw(){
}
template<typename T>__forceinline void TAU::destruct(T*t,int n,TTIC)throw(){ for(int i=0;i<n;++i){ static_cast<T*>(t)[i].~T();
} }
struct TCTA{ TMA&get(void*)throw(){
return TMR::hkMemoryRouter_getInstance().temp(); } } ;
struct TCHA{ TMA&get(const void*)throw(){ return TMR::hkMemoryRouter_getInstance().heap(); }
} ;
struct TCDA;
template<int OFFSET>struct TCSA;
template<typename T>class TAB{ friend class TAU; friend class TAS2; public:typedef TAB<T>ThisType;
__forceinline TAB()throw(); __forceinline TAB(T*buffer,int size,int capacity)throw(); protected:public:__forceinline~TAB()throw(); __forceinline T&operator[](int i)throw();
__forceinline const T&operator[](int i)const throw(); __forceinline int GetLogicalSize()const throw(); __forceinline int getCapacity()const throw(); __forceinline void clear()throw();
__forceinline void _clearAndDeallocate(TMA&alloc)throw(); __forceinline void _pushBack(TMA&alloc,const T&e)throw(); __forceinline void pushBackUnchecked(const T&e)throw(); __forceinline void hkArrayUtil__reserve(TMA&alloc,int n)throw();
__forceinline void _reserveExactly(TMA&alloc,int n)throw(); __forceinline T*expandByUnchecked(int n)throw(); typedef T*iterator; typedef const T*const_iterator;
__forceinline iterator begin()throw(); __forceinline const_iterator begin()const throw(); protected:public:enum{ CAPACITY_MASK=int(0x3FFFFFFF),FLAG_MASK=int(0xC0000000),DONT_DEALLOCATE_FLAG=int(0x80000000),FORCE_SIGNED=-1}
; protected:friend class TSC3; T*vd1; int vs4;
int vcAF; public:} ;
template<typename T,typename Allocator=TCHA>class TA2:public TAB<T>{
public:typedef Allocator AllocatorType; friend class TAU; typedef TA2<T,TCTA>Temp; typedef TA2<T,TCDA>Debug;
typedef TA2<T,TCHA>Heap; __forceinline TA2()throw():TAB<T>(){ } __forceinline~TA2()throw();
explicit __forceinline TA2(int size)throw(); __forceinline TA2(int size,const T&fill)throw(); protected:__forceinline TA2(const TA2&a)throw(); public:__forceinline void ClearAndRelease()throw(){
TAB<T>::_clearAndDeallocate(AllocatorType().get(this)); } __forceinline void AddBack(const T&e)throw(){ TAB<T>::_pushBack(AllocatorType().get(this),e);
} __forceinline void reserve(int size)throw(){ TAB<T>::hkArrayUtil__reserve(AllocatorType().get(this),size); }
__forceinline void reserveExactly(int size)throw(){ TAB<T>::_reserveExactly(AllocatorType().get(this),size); } }
;
template<typename T,unsigned N,typename Allocator=TCHA>class TIA:public TA2<T,Allocator>{ public:typedef TIA<T,N,Allocator>mytype; __forceinline TB wasReallocated()const throw();
public:T vs8[N]; public:} ;
template<typename T,unsigned N>class TIAA16;
template<typename T>__forceinline T&TAB<T>::operator[](int i)throw(){ ; return vd1[i]; }
template<typename T>__forceinline const T&TAB<T>::operator[](int i)const throw(){ ; return vd1[i]; }
template<typename T>__forceinline int TAB<T>::GetLogicalSize()const throw(){ return vs4; }
template<typename T>__forceinline int TAB<T>::getCapacity()const throw(){
return(vcAF&static_cast<int>(CAPACITY_MASK)); }
template<typename T>__forceinline void TAB<T>::_reserveExactly(TMA&alloc,int n)throw(){ if(getCapacity()<n){
TAU::hkArrayUtil__reserve(alloc,this,n,sizeof(T)); } }
// src: HAVOK_LIB 0x00c908c0
template<typename T>__forceinline void TAB<T>::hkArrayUtil__reserve(TMA&alloc,int n)throw(){
const int capacity=getCapacity(); if(capacity<n){ int cap2=2*capacity; int newSize=(n<cap2)?cap2:n;
TAU::hkArrayUtil__reserve(alloc,this,newSize,sizeof(T)); } }
template<typename T>__forceinline void TAB<T>::clear()throw(){
TAU::destruct(vd1,vs4,typename TIPT<T>::type()); vs4=0; }
template<typename T>__forceinline TAB<T>::TAB()throw():vd1(0),vs4(0),vcAF(DONT_DEALLOCATE_FLAG){
}
template<typename T>__forceinline TAB<T>::~TAB()throw(){ ; ;
}
template<typename T>__forceinline void TAB<T>::_clearAndDeallocate(TMA&alloc)throw(){ clear(); if((vcAF&DONT_DEALLOCATE_FLAG)==0){
alloc._bufFree<T>(vd1,getCapacity()); } vd1=0; vcAF=DONT_DEALLOCATE_FLAG;
}
template<typename T>__forceinline void TAB<T>::_pushBack(TMA&alloc,const T&t)throw(){ if(vs4==getCapacity()){ ;
TAU::ResizeAudioStream(alloc,this,sizeof(T)); } TAU::constructWithCopy(vd1+vs4,1,t,typename TIPT<T>::type()); vs4++;
}
template<typename T>__forceinline void TAB<T>::pushBackUnchecked(const T&t)throw(){ ; TAU::constructWithCopy(vd1+vs4,1,t,typename TIPT<T>::type());
vs4++; }
template<typename T>__forceinline T*TAB<T>::expandByUnchecked(int n)throw(){ ;
int oldsize=vs4; vs4=oldsize+n; TAU::construct(vd1+oldsize,vs4-oldsize,typename TIPT<T>::type()); return vd1+oldsize;
}
template<typename T>typename TAB<T>::iterator TAB<T>::begin()throw(){ return vd1; }
template<typename T>typename TAB<T>::const_iterator TAB<T>::begin()const throw(){ return vd1; }
template<typename T,typename Allocator>__forceinline TA2<T,Allocator>::~TA2()throw(){
ClearAndRelease(); }
template<typename T,unsigned N,typename Allocator>TB TIA<T,N,Allocator>::wasReallocated()const throw(){ return this->vd1!=vs8;
}
namespace TSAU{ void __cdecl hkArrayUtil__reserve(void*,int numElem,int sizeElem)throw(); void __cdecl ResizeAudioStream(void*array,int sizeElem)throw();
}
template<typename T>class TSA1{ friend void __cdecl TSAU::hkArrayUtil__reserve(void*,int numElem,int sizeElem)throw(); friend void __cdecl TSAU::ResizeAudioStream(void*array,int sizeElem)throw();
public:__forceinline int GetLogicalSize()const throw(); __forceinline int getCapacity()const throw(); __forceinline void AddBack(const T&e)throw(); typedef T*iterator;
typedef const T*const_iterator; __forceinline iterator begin()throw(); __forceinline const_iterator begin()const throw(); __forceinline void reserve(int n)throw();
void ClearAndRelease()throw(); public:enum{ CAPACITY_MASK=TU16(0x3fff),FLAG_MASK=TU16(0xC000),DONT_DEALLOCATE_FLAG=TU16(0x8000),LOCKED_FLAG=TU16(0x4000),FORCE_SIGNED=-1} ;
protected:friend class TSC3; void releaseMemory()throw(); T*vd1; TU16 vs4;
TU16 vcAF; public:} ;
template<typename T>__forceinline void TSA1<T>::ClearAndRelease()throw(){
releaseMemory(); vd1=0; vs4=0; vcAF=TU16(DONT_DEALLOCATE_FLAG|(vcAF&LOCKED_FLAG));
}
template<typename T>__forceinline int TSA1<T>::GetLogicalSize()const throw(){ return vs4; }
template<typename T>__forceinline int TSA1<T>::getCapacity()const throw(){ return(vcAF&static_cast<int>(CAPACITY_MASK)); }
template<typename T>__forceinline void TSA1<T>::releaseMemory()throw(){
if((vcAF&DONT_DEALLOCATE_FLAG)==0){ TDC(vd1,getCapacity(),KMCA5); } }
template<typename T>__forceinline void TSA1<T>::AddBack(const T&t)throw(){ if(vs4==getCapacity()){ TSAU::ResizeAudioStream(this,sizeof(T)); }
vd1[vs4++]=t; }
template<typename T>typename TSA1<T>::iterator TSA1<T>::begin()throw(){ return vd1;
}
template<typename T>typename TSA1<T>::const_iterator TSA1<T>::begin()const throw(){ return vd1; }
template<typename T>__forceinline void TSA1<T>::reserve(int n)throw(){ const int capacity=getCapacity(); if(capacity<n){ int cap2=2*capacity;
int newSize=(n<cap2)?cap2:n; TSAU::hkArrayUtil__reserve(this,newSize,sizeof(T)); } }
template<typename KEY>struct TMO;
template<>struct TMO<int>;
template<typename KEY,typename VAL=KEY,typename OPS=TMO<KEY> >class TMB;
template<typename KEY,typename VAL=KEY,typename OPS=TMO<KEY>,typename Allocator=TCHA>class TM;
template<int N>struct TPMS;
template<>struct TPMS<8>;
template<typename K,typename V,typename Allocator=TCHA>class TPM;
class TVCR;
class TRV;
typedef float TR;
typedef LocalM128 TQR;
class TV4;
typedef const TV4&TV4P;
union TQRU;
class TSR{ public:operator TR()const;
private:TQR vr; } ;
typedef const TSR&TSRP;
class TV4C;
typedef const TV4C&TV4CP;
class TV4C;
typedef const TV4C&TV4CP;
class TV4C;
extern const TQR TQRH;
extern const TQR TQR3333;
namespace TM2{
}
namespace std{ }
extern"C"{
}
namespace TM2{ }
extern const TQR TQR0000;
extern const TQR TQR1111;
extern const TQR TQR1000;
extern const TQR TQR0100;
extern const TQR TQR0010;
extern const TQR TQR0001;
extern const TQR TQR3333;
extern const TQR TQRH;
extern const TQR TQRMH;
extern const TQR TQRM;
extern const TQR TQRE;
class TV4;
class TQ;
class TM3;
class TR2;
class TT1;
class TQT;
class TV4{ public:TB::CompileTimeTrueType operator==(const TTIP&)const throw(); ; __forceinline TV4()throw(){
} __forceinline TV4(TR x,TR y,TR z,TR w=0)throw(); __forceinline TV4(const TQR&q)throw(); __forceinline TV4(const TV4&v)throw();
private:TQR vq; public:operator TQR()const; } ;
class TQ{ public:TB::CompileTimeTrueType operator==(const TTIP&)const throw(); ; public:TV4 vv1;
protected:} ;
class TM3{ public:TB::CompileTimeTrueType operator==(const TTIP&)const throw();
; protected:TV4 vc0; TV4 vc1; TV4 vc2;
} ;
extern"C"{ }
class __declspec(align(16))TR2:public TM3{ public:TB::CompileTimeTrueType operator==(const TTIP&)const throw(); ; }
;
class TT1{ public:TB::CompileTimeTrueType operator==(const TTIP&)const throw(); ;
private:TR2 vr2; TV4 vt5; } ;
class TST1{ public:public:public:TV4 vcOM0; TV4 vcOM1; TQ vr0;
TQ vr11; TV4 vcOML; } ;
class TQT{ public:TB::CompileTimeTrueType operator==(const TTIP&)const throw(); ; enum IdentityInitializer{
IDENTITY,} ; enum ZeroInitializer{ ZERO,}
; public:TV4 vt5; TQ vr2; TV4 vs;
} ;
class TM4;
static const TQR g_vNearOneVector={
1.0f-1e-5f,1.0f-1e-5f,1.0f-1e-5f,1.0f-1e-5f} ;
static const TQR g_vNearNegativeOneVector={ -(1.0f-1e-3f),-(1.0f-1e-3f),-(1.0f-1e-3f),-(1.0f-1e-3f)}
;
class TS6{ public:enum ReplaceType{ REPLACE_ONE,REPLACE_ALL}
; private:} ;
class TSP;
class TSB1;
class TSP{ public:enum StringFlags{ OWNED_FLAG=0x1,}
; inline operator const char*()const; private:const char*vsAF1; }
;
class TCE;
class TC1;
class TCA2;
extern const TC1 TCMC;
class TypeMetadataClass;
class TC1;
class TSW;
class TCA2;
extern const TC1 TCEC;
extern const TC1 TCEIC;
class TCE;
extern const TC1 TRRAC;
struct TRRA;
extern const TC1 TRI32AC;
struct TRI32A;
extern const TC1 TUAC;
struct TUA;
extern const TC1 TGAC;
struct TGA;
extern const TC1 TMNTAC;
struct TMNTA;
extern const TC1 TLAC;
struct TLA;
extern const TC1 TSAC;
struct TSA;
extern const TC1 TDAC;
struct TDA;
extern const TC1 TATAC;
struct TATA;
extern const TC1 TDOTAC;
struct TDOTA;
extern const TC1 TDAC1;
struct TDA1;
class TMTC{ public:enum AccessType{
KAI=0,KAR=1,KAR1=2,} ; enum ReadMode{ THIS_OBJECT_ONLY,RECURSIVE}
; protected:public:enum{ MARKED_RO=0xffffffe1,MARKED_RO_SELF_ONLY=0xffffffc1,UNMARKED=0xfffffff1} ;
TU32 vtI; TU16 vmC; protected:TU16 vmBS; public:static class TCS2*vcS1;
} ;
typedef TU16 TCPI;
class TCP;
enum TST{ KSI=0,KSS,KFST=KSS,KSC3,KST1,KSB,KSC,KSCV,KSC1,KSBT,KSL,KSM,KSCT1,KSCT,KSSHF,KSEM,KST,KSCM,KSMIS=KSCM+1,KSC2,KSPCV,KSME,KSCP,KSMS,KSCL,KSTC,KSMR,KSHF,KSSR,KSB1,KSP,KSPC,KSU,KSU1,KSU2,KSMI,KSA=-1} ;
class TCD;
class TCV;
enum TBS{ KSBS=512} ;
typedef __declspec(align(16))char TSB[KSBS];
class TA;
struct TSRCI;
struct TSRCO;
struct TSRBCI;
struct TSRBCO;
class TRHC;
class TCB;
class TSC2;
class TS5;
typedef TU16 TVI;
typedef TU32 TSK;
class TSKP;
extern const TC1 TSC;
class TCS1;
class TS1:public TRO{
public:__forceinline void getAabb(const TT1&localToWorld,TR tolerance,TA&out)const throw(); virtual void vs111()const throw(); virtual void vs12()const throw(); virtual void vs13()const throw();
struct PhysicsShape{ bool vmA3R; bool viFOK; bool vhDMS;
} ; virtual void vs14()const throw(); protected:virtual void CalculateAabb(const TT1&localToWorld,TR tolerance,TA&out)const throw()=0;
virtual void vs15()const throw(); virtual void vs16()const throw(); virtual void vs17()const throw(); public:typedef void(__cdecl*GetSupportingVertexFunc)(const void*thisObj,TV4P direction,TCV&supportVertex);
typedef void(__cdecl*ConvertVertexIdsToVerticesFunc)(const void*thisObj,const TVI*ids,int numIds,class TCV*verticesOut); typedef int(__cdecl*WeldContactPointFunc)(const void*thisObj,TVI*featurePoints,TU8&numFeaturePoints,TV4&contactPointWs,const TT1*thisObjTransform,const TCS1*collidingShape,const TT1*collidingTransform,TV4&separatingNormalInOut); typedef void(__cdecl*GetCentreFunc)(const void*thisObj,TV4&centreOut); typedef int(__cdecl*GetNumCollisionSpheresFunc)(const void*thisObj);
typedef const TS5*(__cdecl*GetCollisionSpheresFunc)(const void*thisObj,TS5*sphereBuffer); typedef void(__cdecl*GetAabbFunc)(const void*thisObj,const TT1&localToWorld,TR tolerance,TA&out); typedef TB(__cdecl*CastRayFunc)(const void*thisObj,const TSRCI&input,TSRCO&output); typedef void(__cdecl*CastRayWithCollectorFunc)(const void*thisObj,const TSRCI&input,const TCB&cdBody,TRHC&collector);
typedef TV4C(__cdecl*CastRayBundleFunc)(const void*thisObj,const TSRBCI&input,TSRBCO&output,TV4CP mask); typedef const TS1*(__cdecl*GetChildShapeFunc)(const void*thisObj,TSK key,TSB&buffer); typedef TU32(__cdecl*GetCollisionFilterInfoFunc)(const void*thisObj,TSK key); struct ShapeCallbackDispatchTable{
TPS<GetSupportingVertexFunc>vgSVF; TPS<ConvertVertexIdsToVerticesFunc>vcVITV; TPS<WeldContactPointFunc>vwCPF; TPS<GetCentreFunc>vgCF;
TPS<GetNumCollisionSpheresFunc>vgNCSF; TPS<GetCollisionSpheresFunc>vgCSF1; TPS<GetAabbFunc>vgAF; TPS<CastRayFunc>vcR;
TPS<CastRayWithCollectorFunc>vcRWC; TPS<CastRayBundleFunc>vcRB; TPS<GetChildShapeFunc>vgCSF; TPS<GetCollisionFilterInfoFunc>vgCFIF;
} ; struct AlignedShapeCallbackTable{ __declspec(align(64))GetSupportingVertexFunc vgSVF;
ConvertVertexIdsToVerticesFunc vcVITV; WeldContactPointFunc vwCPF; GetCentreFunc vgCF; GetNumCollisionSpheresFunc vgNCSF;
GetCollisionSpheresFunc vgCSF1; GetAabbFunc vgAF; CastRayFunc vcR; CastRayWithCollectorFunc vcRWC;
CastRayBundleFunc vcRB; GetChildShapeFunc vgCSF; GetCollisionFilterInfoFunc vgCFIF; }
; typedef void(__cdecl*RegisterFunc)(ShapeCallbackDispatchTable&sf); public:public:TU1 vuD; public:TE1<::TST,TU32>vt6;
public:} ;
__declspec(align(16))class TAS;
void TS1::getAabb(const TT1&localToWorld,TR tolerance,TA&out)const throw(){
CalculateAabb(localToWorld,tolerance,out); }
class TS1;
class TMS1;
class TC2;
class TCB{ public:friend class TC2; __forceinline const TT1&getTransform()const throw();
__forceinline const TS1*getShape()const throw(); public:__forceinline const TMS1*GetMotionState()const throw(); __forceinline void setMotionState(const TMS1*state)throw(); public:const TS1*vs2;
TSK vsK; const void*vm3; const TCB*vp1; }
;
const TT1&TCB::getTransform()const throw(){ ; return*static_cast<const TT1*>(vm3);
}
const TMS1*TCB::GetMotionState()const throw(){ return static_cast<const TMS1*>(vm3); }
void TCB::setMotionState(const TMS1*state)throw(){ vm3=state; }
const TS1*TCB::getShape()const throw(){
return vs2; }
class TBPH{ public:TU32 vi;
public:} ;
enum TCQT{ KCQI=-1,KCQF=0,KCQK,KCQD,KCQDST,KCQM1,KCQC1,KCQB,KCQU,KCQC,KCQKR,KCQM}
;
class TTBPH:public TBPH{ public:protected:enum{ OFFSET_INVALID=127}
; friend class TBPB; TI8 vt6; TI8 voO;
public:TI8 voQT; TU32 vcFI; } ;
class TA;
struct TAU32;
class TS1;
class TT1;
class TC2:public TCB{ public:inline const TS1*getShape()const throw(); inline const TTBPH*getBroadPhaseHandle()const throw(); inline TTBPH*getBroadPhaseHandle()throw();
public:public:struct BoundingVolumeData{ __forceinline void invalidate()throw(){ vm2[0]=1; vm1[0]=0;
} public:TU32 vm2[3]; TU8 veM1[3]; TU8 veS;
TU32 vm1[3]; TU8 veM[3]; TU8 vp; TU16 vnCSA;
TU16 vcCSA; TAU32*vcSA; TSK*vcSK; }
; enum ForceCollideOntoPpuReasons{ FORCE_PPU_USER_REQUEST=1,FORCE_PPU_SHAPE_REQUEST=2,FORCE_PPU_MODIFIER_REQUEST=4,} ;
protected:TI8 voO; public:TU8 vfCOP; TU16 vsSOS; class TTBPH vbPH;
public:struct BoundingVolumeData vbVD; TR vaPD; } ;
class TA{ public:TA()throw(){ } __forceinline TA(const TV4&min,const TV4&max)throw();
public:TV4 vm2; TV4 vm1; } ;
__declspec(align(16))struct TAU32;
__forceinline const TS1*TC2::getShape()const throw(){ return vs2; }
inline const TTBPH*TC2::getBroadPhaseHandle()const throw(){ return&vbPH; }
inline TTBPH*TC2::getBroadPhaseHandle()throw(){
return&vbPH; }
struct TANE;
class TLC:public TC2{
public:public:struct CollisionKeyEntry{ TANE*vaE; TLC*vp2; }
; protected:TA2<struct CollisionKeyEntry>vcE; } ;
extern const TC1 TPVC;
extern const TC1 TPC;
struct TPV;
class CollisionRelatedClass;
class TW;
class TS1;
class TP;
class TRB;
extern const TC1 TWOC;
namespace TWO1{ enum Result{ POSTPONED,DONE}
; }
class TWO:public TRO{ public:enum MtChecks{
MULTI_THREADING_CHECKS_ENABLE,MULTI_THREADING_CHECKS_IGNORE} ; inline TC2*getCollidableRw()throw(); inline const TC2*getCollidable()const throw();
virtual void vs18()throw(); public:enum BroadPhaseType{ BROAD_PHASE_INVALID,BROAD_PHASE_ENTITY,BROAD_PHASE_PHANTOM,BROAD_PHASE_BORDER,BROAD_PHASE_MAX_ID} ;
protected:friend class TW; friend class TWOU; inline void setWorld(TW*world)throw(); inline virtual~TWO()throw();
public:virtual class TMS1*GetMotionState()throw()=0; protected:TW*vw; TU1 vuD; protected:class TLC vc3;
protected:class TMTC vmTC; TSP vn; TA2<class CollisionRelatedClass>vp5; private:class TRO*vaD;
void*vtD; public:} ;
inline TC2*TWO::getCollidableRw()throw(){
return&vc3; }
inline const TC2*TWO::getCollidable()const throw(){ return&vc3;
}
void TWO::setWorld(TW*world)throw(){ vw=world; }
extern const TC1 TMC;
class TM1{ public:enum ResponseType{ RESPONSE_INVALID,RESPONSE_SIMPLE_CONTACT,RESPONSE_REPORTING,RESPONSE_NONE,RESPONSE_MAX_ID}
; private:TE1<ResponseType,TI8>vrT; TR vf2; TR vr1;
public:} ;
class TSR1;
struct TSI{
enum DeactivationClass{ DEACTIVATION_CLASS_INVALID,DEACTIVATION_CLASS_OFF,DEACTIVATION_CLASS_LOW,DEACTIVATION_CLASS_MEDIUM,DEACTIVATION_CLASS_HIGH,DEACTIVATION_CLASS_AGGRESSIVE,DEACTIVATION_CLASSES_END} ; struct FloatAndHalfRecord{
float vlVTI; float vaVTI; float vsOVM; float vrSVT;
float vmDS[2]; TH vmRS[2]; } ;
__declspec(align(16))float vo; float vt; float vd; float vfT;
TV4 vgAPSS; TV4 vgAPS; TV4 viVF; TV4 viIVF;
float vdDT; float vtDD; float vdDFT; float vfTDD;
float vcRV; FloatAndHalfRecord vdI[DEACTIVATION_CLASSES_END]; float vdT; float viDT;
int vnS; int vnMS; float viNMS; float viNS;
TB vfCCOIS; TU8 vdNIFSF[2]; TU8 vdIC; float vmCVS;
} ;
struct T1dMSI;
struct T3dAMSI;
struct TVCA;
class TJS;
class TVA;
class TSDA;
class TSDR;
class TCI2;
class TSR1;
struct TSET;
struct TILBE;
struct TILBH;
class TCI2;
extern"C"{
}
struct TCI1{ int vmSOS; int vsOS;
int vnSR; int vnSET; inline void clear()throw(){ vmSOS=0;
vsOS=0; vnSR=0; vnSET=0; }
} ;
class TCQI1;
class TCQO;
class TCO;
class TCI2;
extern const TC1 TCDC;
extern const TC1 TCIC;
typedef void VoidTypeAlias;
class TCD1;
class TCD1;
class TCD1;
class TE;
class TRB;
class TCO;

class TCL;
class TW;
extern const TC1 TCIC1;
typedef void VoidTypeAlias;
class TCI2;
__declspec(align(16))struct TCI3;
class TMS1{ public:inline TT1&getTransform()throw();
inline const TT1&getTransform()const throw(); protected:TT1 vt4; class TST1 vsT3; public:TV4 vdA;
TR voR; TR vlD; TR vaD1; TUF8 vmLV;
TUF8 vmAV; TU8 vdC; } ;
TT1&TMS1::getTransform()throw(){ return vt4; }
const TT1&TMS1::getTransform()const throw(){
return vt4; }
extern const TC1 TMC1;
class TM5:public TRO{
public:enum MotionType{ MOTION_INVALID,MOTION_DYNAMIC,MOTION_SPHERE_INERTIA,MOTION_BOX_INERTIA,MOTION_KEYFRAMED,MOTION_FIXED,MOTION_THIN_BOX_INERTIA,MOTION_CHARACTER,MOTION_MAX_ID} ; public:virtual void vs19()throw();
virtual void vs20()throw(); virtual void vs211()const throw(); virtual void vs22()const throw(); virtual void vs23()throw();
virtual void vs24()throw(); virtual void vs25()const throw(); virtual void vs26()const throw(); virtual void vs27()throw();
inline TMS1*GetMotionState()throw(); inline const TMS1*GetMotionState()const throw(); virtual void vs28()throw(); virtual void vs29()throw();
virtual void vs30()throw(); inline const TT1&getTransform()const throw(); virtual void vs311()throw(); virtual void vs32()throw();
virtual void vs33()throw(); virtual void vs34()const throw(); virtual void vs35()throw(); virtual void vs36()throw();
virtual void vs37()throw(); virtual void vs38()throw(); virtual void vs39()throw(); virtual void vs40()throw();
public:virtual void vs411()throw(); inline void SynchronizeDeactivationCountersWithWorld(int worldFlag0,int worldFlag1,int worldDeactivationIntegrateCounter)throw(); public:enum{ NUM_INACTIVE_FRAMES_TO_DEACTIVATE=5}
; public:TE1<MotionType,TU8>vt6; TU8 vdIC; TU16 vdNIF[2];
class TMS1 vmS; TV4 viAMI; TV4 vlV; TV4 vaV;
TV4 vdRP[2]; TU32 vdRO[2]; class TMSM*vsM; TU16 vsQTI;
TH vgF; } ;
class TRM:public TM5{
} ;
TMS1*TM5::GetMotionState()throw(){ return&vmS;
}
const TMS1*TM5::GetMotionState()const throw(){ return&vmS; }
const TT1&TM5::getTransform()const throw(){ return vmS.getTransform(); }
void TM5::SynchronizeDeactivationCountersWithWorld(int worldFlag0,int worldFlag1,int worldDeactivationIntegrateCounter)throw(){
; ; if((((unsigned)worldDeactivationIntegrateCounter)%4)<(((unsigned)vdIC)%4)){ worldFlag0=(~worldFlag0)<<14;
} else{ worldFlag0<<=14; }
if(worldDeactivationIntegrateCounter<vdIC){ worldFlag1=(~worldFlag1)<<14; } else{
worldFlag1<<=14; } vdNIF[0]=TU16((vdNIF[0]&0x3fff)|worldFlag0); vdNIF[1]=TU16((vdNIF[1]&0x3fff)|worldFlag1);
}
extern const TC1 TKRMC;
class TKRM:public TM5{ public:virtual~TKRM()throw();
virtual void vs19()throw(); virtual void vs20()throw(); virtual void vs42()const throw(); virtual void vs23()throw();
virtual void vs22()const throw(); virtual void vs24()throw(); virtual void vs43()const throw(); virtual void vs26()const throw();
virtual void vs34()const throw(); virtual void vs35()throw(); virtual void vs36()throw(); virtual void vs37()throw();
virtual void vs38()throw(); virtual void vs39()throw(); virtual void vs40()throw(); protected:public:public:virtual void vs44()throw();
virtual void vs45()throw(); public:} ;
class TMSM:public TKRM{
public:private:} ;
class TEL;
class TEAL;
class TCL1;
class TM5;

class TW;
class TCI2;
class TA1;
class TDCM;
class TSCCU1;
class TLF;
class TBB;
class TdBB;
extern const TC1 TEC;
class TE:public TWO{ public:enum SpuCollisionCallbackEventFilter{ SPU_SEND_NONE=0x00,SPU_SEND_CONTACT_POINT_ADDED=0x01,SPU_SEND_CONTACT_POINT_PROCESS=0x02,SPU_SEND_CONTACT_POINT_REMOVED=0x04,SPU_SEND_CONTACT_POINT_ADDED_OR_PROCESS=SPU_SEND_CONTACT_POINT_ADDED|SPU_SEND_CONTACT_POINT_PROCESS} ;
public:virtual~TE()throw(); inline TB isFixed()const throw(); void UpdateBoundingVolume(const TW*world,const TS1*shape)throw(); protected:public:inline TM5*getMotion()throw();
virtual void vs46()throw(); virtual TMS1*GetMotionState()throw(){ return 0; }
protected:class TM1 vm; protected:friend class TWCU1; public:public:class SmallArraySerializeOverrideType{ public:void*vd1;
TU16 vs4; TU16 vcAF; } ;
public:void*vlCIU; TR vdM; TBB*vbB; public:TU32 vsD1;
public:TOI vsI5; protected:TU16 vcPCD; protected:TSA1<struct TCI3>vcM; protected:TA2<TCI2*>vcS;
protected:TA2<TU8>vcR1; hkpSimulationIsland*vsI; public:TI8 vaRL; TU8 vnSKICPP;
TU8 vrMF; TU32 vu; public:struct SpuCollisionCallback{ public:TSCCU1*vu1;
TU16 vc; TU8 veF; TU8 vuF; }
; struct ExtendedListeners{ TSA1<TEAL*>vaL1; TSA1<TEL*>veL;
} ; public:struct SpuCollisionCallback vsCC; public:class TMSM vm3;
protected:friend class TECU; friend class TWCU; friend class TW; 
friend class TWOU; TSA1<TCL1*>vcL1; protected:TSA1<TA1*>va1; public:TRP<TLF>vlF;
protected:mutable ExtendedListeners*veL1; } ;
inline TM5*TE::getMotion()throw(){
return&vm3; }
inline TB TE::isFixed()const throw(){ return vm3.vt6==TM5::MOTION_FIXED;
}
class TSI1{ public:public:__declspec(align(16))TPS<TT>vsT2; TPS<TT>veT;
TPS<TR>vdT; TPS<TR>viDT; } ;
class TS;
typedef TS TSBW;
class TW;
class TSI1;

class TE;
class TB;
struct TTD;

inline void hkMonitorStream::TimerCommand::setTime()
{
    unsigned int ticks;
    __asm {
        rdtsc
        mov dword ptr[ticks], eax
    }
    m_time0 = ticks;
}
class TTFH;
class TWMAWD;
class TCB;
struct TCI;
class TCLF;
class TC2;
class TCCF{ public:virtual~TCCF()throw(); virtual void vs47()const throw(); }
;
struct TWRCI;
extern const TC1 TRCFC;
class TRCF{
public:virtual~TRCF()throw(); virtual void vs48()const throw(); } ;
struct TCI;
class TBTS;
class TSCF{ public:virtual void vs49()const throw();
virtual void vs50()const throw(); virtual void vs511()const throw(); virtual~TSCF()throw(); }
;
struct TSRCI;
class TSC1;
class TS1;
extern const TC1 TRSCFC;
class TRSCF{ public:virtual void vs52()const throw(); virtual~TRSCF()throw();
} ;
extern const TC1 TCFC;
class TBTS;
class EnumIntegerValue:public TRO,public TCCF,public TSCF,public TRSCF,public TRCF{ public:enum TFT{ KFU=0,KFN=1,KFG=2,KFL=3,KFC1=4,KFP=5,KFC=6,} ;
public:virtual void vs47()const throw(); virtual void vs53()const throw(); virtual void vs50()const throw(); virtual void vs511()const throw();
virtual void vs54()const throw(); virtual void vs48()const throw(); public:TU32 unusedBefore0; TU32 unusedBefore1;
TE1<TFT,TU32>vt6; TU32 unusedAfter0; TU32 unusedAfter1; TU32 unusedAfter2;
public:} ;
extern const TC1 TCFLC;
class TCFL;
extern const class TC1 TWCC;
class TWC:public TRO{ public:enum SolverType{ SOLVER_TYPE_INVALID,SOLVER_TYPE_2ITERS_SOFT,SOLVER_TYPE_2ITERS_MEDIUM,SOLVER_TYPE_2ITERS_HARD,SOLVER_TYPE_4ITERS_SOFT,SOLVER_TYPE_4ITERS_MEDIUM,SOLVER_TYPE_4ITERS_HARD,SOLVER_TYPE_8ITERS_SOFT,SOLVER_TYPE_8ITERS_MEDIUM,SOLVER_TYPE_8ITERS_HARD,SOLVER_TYPE_MAX_ID}
; enum SimulationType{ SIMULATION_TYPE_INVALID,SIMULATION_TYPE_DISCRETE,SIMULATION_TYPE_CONTINUOUS,SIMULATION_TYPE_MULTITHREADED,} ;
enum ContactPointGeneration{ CONTACT_POINT_ACCEPT_ALWAYS,CONTACT_POINT_REJECT_DUBIOUS,CONTACT_POINT_REJECT_MANY,} ; enum BroadPhaseBorderBehaviour{
BROADPHASE_BORDER_ASSERT,BROADPHASE_BORDER_FIX_ENTITY,BROADPHASE_BORDER_REMOVE_ENTITY,BROADPHASE_BORDER_DO_NOTHING,} ; public:TV4 vg1; TI32 vbPQS;
TR vcRV; TE1<BroadPhaseBorderBehaviour,TI8>vbPBB; TB vmPASBPBC; class TA vbPWA;
TB vuKT; TB vuMT; enum TreeUpdateType{ REBUILD_ACTIVE,REBUILD_ALL,}
; TE1<TreeUpdateType,TI8>vtUT; TB vaUKT; TR vcT;
TRP<class EnumIntegerValue>vcF; TRP<class TCLF>vcLF; TR veMLV; int vsOTEQ;
TR veMPDT; TRP<class TWMAWD>vmWD; TI32 vbPNM; TE1<ContactPointGeneration,TI8>vcPG;
TB vaTSCC; TR vsT1; TR vsD; TI32 vsI3;
TI32 vsM1; TR vmCV; TB vfCCOIS; TR vsCTCET1;
TR vsCTCET; TB veTWR; TB veDW; TR viLCEOD;
TI32 viLCMI; TU8 vdNIFSF0; TU8 vdNIFSF1; TU8 vdIC;
TB vsAORBTC; TR vdRD; TR vtCRRN; int vmSPCT;
TB vpTM; int vmEPTCT; int vmNTCPS; TR vnTTAPST;
TR vnTTAPT; TR vnTTAPTH; TR vnTTAPTF; TB veD;
TE1<SimulationType,TI8>vsT; TB veSI; TU32 vmDIS; TB vpAIST;
TB vaIOIWCIASJ; TR vfMPS; TB vfCC; virtual~TWC()throw();
} ;
class EnumIntegerValue;
class TCLF;
class TCD;
class TC2;
struct TCI;
struct TPCI;
class TCL1;
class TTBPD;
struct TWRCI;
struct TWRCO;
struct TLCI;
class TRHC;
class TCPC;
class TCBPC;
class TBP;
class TBPH;
class TA;
class TWO;
class TE;
class TEL;
class TRB;
class TP;
class TPL;
class TPBPL;
class TEEBPL;
class TBPBL;
class TA1;
class TAL;
class TCI2;
class TCD1;
class TCL;
class TPS1;

class TCMF;
struct TMTS;
class TWPSL;
class TWPIL;
class TWPCL;
class TWDL;
class TIAL;
class TCILBL;
class TIPIL;
class TIPCL;
class TSI1;
class TWPBF;
class TS2;
class TWOQ;
struct TDIOPOQ;
class TWMM;
class TWMAWD;
class TBO1;
class TJQ;
class TJTP;
class TdW;
struct TWRCC;
struct TWLCC;
struct TWGCPC;
namespace TWO1{
struct TypeTag; class TypeTagRelatedClass; }
struct TOP;
extern"C"enum TUCFOWM{ KUFOWFC,KUFOWDEECO,}
;
enum TUCFOEM{
KUFOEFC,KUFOEDEECO} ;
enum TEA{ KEADNA,KEADA}
;
enum TUCFM{ KUCFISC,KUCFPSC} ;
struct TWDSI{ TSI1 vsI4; TSI vsI2; }
;
struct TMC2;
enum TSR2{ KSRS,KSRMFBI,KSRMFDC,KSRMFDTS,}
;
class TW:public TRO{ public:void hkpWorld_addEntityBatch(TE*const*entityBatch,int numEntities,TEA initialActivationState=KEADA)throw(); enum ReintegrationRecollideMode{
RR_MODE_REINTEGRATE=1,RR_MODE_RECOLLIDE_BROADPHASE=2,RR_MODE_RECOLLIDE_NARROWPHASE=4,RR_MODE_ALL=7} ; struct ReintegrationCollisionRequest{ int vmRBS;
int vsRBS; hkpSimulationIsland*vlSI; } ;
enum MtAccessChecking{ MT_ACCESS_CHECKING_ENABLED=0,MT_ACCESS_CHECKING_DISABLED} ; inline const EnumIntegerValue*getCollisionFilter()const throw();
enum CachedAabbUpdate{ SHIFT_BROADPHASE_UPDATE_ENTITY_AABBS,SHIFT_BROADPHASE_IGNORE_ENTITY_AABBS} ; inline const TA2<hkpSimulationIsland*>&getActiveSimulationIslands()const throw();
public:__forceinline void lockCriticalOperations()throw(); __forceinline void unlockCriticalOperations()throw(); __forceinline int areCriticalOperationsLocked()const throw(); __forceinline void unlockAndAttemptToExecutePendingOperations()throw();
__forceinline void attemptToExecutePendingOperations(bool executeBodyOperations=true)throw(); void hkpWorld_queueOperation(const TWO1::TypeTag&operation)throw(); private:void FUN_00c91120()throw(); void UpdateFields_00c91140()throw();
public:public:TS2*vs3; TV4 vg1; hkpSimulationIsland*vfI; TRB*vfRB;
TA2<hkpSimulationIsland*>vaSI; TA2<hkpSimulationIsland*>viSI; TA2<hkpSimulationIsland*>vdSI; TWMM*vmM;
TRP<TWMAWD>vmWD; TB vaOROOSM; TBP*vbP; class TTWM*vkTM;
TB vaUT; TTBPD*vbPD; TPBPL*vpBPL; TEEBPL*veEBPL;
TBPBL*vbPBL; TMTS*vmSJD; TPCI*vcI; EnumIntegerValue*vcF;
TCD*vcD1; TCLF*vcLF; TWOQ*vpO; int vpOC;
int vpBOC; int vcOLC; int vcOLCFP; TB vbEPO;
TB vcOA; TDIOPOQ*vpOQ; int vpOQC; mutable class TMTC vmTC;
TB vpAIST; TB vaIOIWCIASJ; TU32 vmDIS; class TCS2*vmCCS;
int viL; class TCS2*viDLCS; class TCS2*vpML; TB vwSI;
TR vsCTCET1; TR vsCTCET; TB veTWR; TB vwD;
TB vsAORBTC; TR vdRD; TR vtCRRN; int vmSPCT;
TB vpTM; int vmEPTCT; int vmNTCPS; TE1<TWC::SimulationType,TI32>vsT;
TR vnTTAPST; TR vnTTAPT; TR vnTTAPTH; TR vnTTAPTF;
static TB vfMS; class TBHolder{ public:public:TB voFMSV; }
; public:TU32 vlEU; TU32 vlIU; public:TU32 vlCU;
friend class TWOU; friend class TWCU; friend class TS2; friend class THS;
friend class TCS; friend class TMTS1; friend class TSCCM; TA2<TP*>vp3;
TA2<TAL*>vaL; TA2<TEL*>veL; TA2<TPL*>vpL; TA2<TCL*>vcL;
TA2<TWDL*>vwDL; TA2<TIAL*>viAL; TA2<TWPSL*>vwPSL; TA2<TWPIL*>vwPIL;
TA2<TWPCL*>vwPCL; TA2<TIPIL*>viPIL; TA2<TIPCL*>viPCL; TA2<TCL1*>vcL1;
TA2<TCILBL*>vcILBL; TVCA*vvCA; class TBPB*vbPB; class TCCU*vcCU;
class TdW*vdW; public:struct TWDSI vdSI1; TV4 vbPE[2]; int vbPNM;
int vsOTEQ; TI32 vbPQS; TI32 vbPUS; TE1<TWC::ContactPointGeneration,TI8>vcPG;
} ;
const TA2<hkpSimulationIsland*>&TW::getActiveSimulationIslands()const throw(){ return vaSI;
}
inline const EnumIntegerValue*TW::getCollisionFilter()const throw(){ ; return vcF;
}
void TW::lockCriticalOperations()throw(){ ; vcOLC++;
; }
void TW::unlockCriticalOperations()throw(){ ;
vcOLC--; ; }
int TW::areCriticalOperationsLocked()const throw(){
; ; return vcOLC; }
extern struct TCDU*g_checkDeterminismUtil;
class TI;
class TO1;
class TCS2;
class TMT;
struct TCDU;
class TVA;
class TCO:public TRO{ public:public:virtual void vs55()throw(); virtual void vs56()throw(); virtual void vs57()throw();
virtual void vs58()throw(); public:TCI1 vcI1; } ;
class TCI2;
class TE;
class TSI1;
class TVA;

class TVA;
class TVA;
class TCQSI;
class TCQI1;
struct TCSI;
struct TBJTH;
struct TBJT;
struct TBJTC;
struct TSJTC;
struct TBJTH;
struct TSCBT;
struct TCSR;
class TCSS;
struct TPCI;
class TCM2;
struct TPCO;
struct TCQI;
class TLC;
class TCD;
class TCO;
struct TCI;
class TCB;
class TCA;
struct TAE;
typedef void TAD;
struct TA3I;
struct TA3PI;
namespace TA3{ typedef int AgentType; enum{ MIN_TOTAL_SIZE=16,MAX_MEMORY_INCREASE=80,MAX_TOTAL_SIZE=128}
; enum StreamCommand{ STREAM_NULL=0,STREAM_END=1,STREAM_CALL=2,STREAM_CALL_FLIPPED=3,STREAM_CALL_WITH_TIM=4,STREAM_CALL_WITH_TIM_FLIPPED=5,STREAM_CALL_AGENT=6,TRANSFORM_FLAG=0x08,STREAM_CALL_WITH_TRANSFORM=TRANSFORM_FLAG|STREAM_CALL,STREAM_CALL_FLIPPED_WITH_TRANSFORM=TRANSFORM_FLAG|STREAM_CALL_FLIPPED,STREAM_CALL_WITH_TIM_WITH_TRANSFORM=TRANSFORM_FLAG|STREAM_CALL_WITH_TIM,STREAM_CALL_WITH_TIM_FLIPPED_WITH_TRANSFORM=TRANSFORM_FLAG|STREAM_CALL_WITH_TIM_FLIPPED,STREAM_CALL_AGENT_WITH_TRANSFORM=TRANSFORM_FLAG|STREAM_CALL_AGENT,} ;
typedef TAD*(__cdecl*CreateFunc)(const TA3I&input,TAE*entry,TAD*agentData); typedef void(__cdecl*DestroyFunc)(TAE*entry,TAD*agentData,TCM2*mgr,TCO&constraintOwner,TCD*dispatcher); typedef TAD*(__cdecl*ProcessFunc)(const TA3PI&input,TAE*entry,TAD*agentData,TV4*separatingNormalOut,TPCO&result); enum Symmetric{
IS_SYMMETRIC,IS_NOT_SYMMETRIC,IS_NOT_SYMMETRIC_AND_FLIPPED} ; typedef void(__cdecl*SepNormalFunc)(const TA3I&input,TAE*entry,TAD*agentData,TV4&separatingNormalOut); typedef TAD*(__cdecl*CleanupFunc)(TAE*entry,TAD*agentData,TCM2*mgr,TCO&constraintOwner);
typedef void(__cdecl*RemovePointFunc)(TAE*entry,TAD*agentData,TCPI idToRemove); typedef void(__cdecl*CommitPotentialFunc)(TAE*entry,TAD*agentData,TCPI iContactPointId); typedef void(__cdecl*CreateZombieFunc)(TAE*entry,TAD*agentData,TCPI idTobecomeZombie); typedef void(__cdecl*UpdateFilterFunc)(TAE*entry,TAD*agentData,const TCB&bodyA,const TCB&bodyB,const TCI&input,TCM2*mgr,TCO&constraintOwner);
typedef void(__cdecl*CalcStatisticsFunc)(TAE*entry,TAD*agentData,const TCI&input,TSC3*collector); typedef void(__cdecl*InvalidateTimFunc)(TAE*entry,TAD*agentData,const TCI&input); typedef void(__cdecl*WarpTimeFunc)(TAE*entry,TAD*agentData,TT oldTime,TT newTime,const TCI&input); }
typedef void TAD;
struct TANE;
struct TANS;
class TC2;
struct TANE;
struct TANS;
struct TANT{ TU32 vbUILS;
TIA<TANS*,1>vs1; } ;
class TTBPHP;
class TBPL{ public:virtual~TBPL()throw(); virtual void vs59()throw(); virtual void vs60()throw();
} ;
class TUF;
class TA1;
class TE;
class TCI2;
class TSI1;
class TBP;
class TW;
class TCD;
struct TWDSI;
class TBPHP;
struct TCI;
struct TPCO;
extern const TC1 FUN_00d07830Class;


class THC;
class TLF;
class TRBC;
extern const TC1 TRBC1;
class TRB:public TE{
public:virtual~TRB()throw(); inline const TT1&getTransform()const throw(); virtual void vs611()const throw(); public:inline TM5*getRigidMotion()const throw();
public:protected:virtual TMS1*GetMotionState()throw(); public:} ;
inline TM5*TRB::getRigidMotion()const throw(){
return const_cast<TMSM*>(&vm3); }
inline const TT1&TRB::getTransform()const throw(){ return getRigidMotion()->getTransform();
}
class TCI2;
class TE;
struct TANT;
class TCS;
class TWOU;
class TRB;
class TBO1;
class TA;
class TRB;
class TWO;
class TCI2;
class TS1;
class TCCF1;
namespace TWO1{ enum Type{
OPERATION_ID_ANY=0,OPERATION_ID_INVALID=0,ENTITY_ADD,ENTITY_REMOVE,ENTITY_UPDATE_BROAD_PHASE,RIGIDBODY_SET_MOTION_TYPE,WORLD_OBJECT_SET_SHAPE,ENTITY_BATCH_ADD,ENTITY_BATCH_REMOVE,CONSTRAINT_ADD,CONSTRAINT_REMOVE,ACTION_ADD,ACTION_REMOVE,ISLAND_MERGE,PHANTOM_ADD,PHANTOM_REMOVE,PHANTOM_BATCH_ADD,PHANTOM_BATCH_REMOVE,PHANTOM_UPDATE_BROAD_PHASE,UPDATE_FILTER_ENTITY,UPDATE_FILTER_ENTITY_PAIR,UPDATE_FILTER_PHANTOM,UPDATE_FILTER_WORLD,UPDATE_MOVED_BODY_INFO,ENTITY_BATCH_REINTEGRATE_AND_RECOLLIDE,RIGIDBODY_SET_POSITION_AND_ROTATION,RIGIDBODY_SET_LINEAR_VELOCITY,RIGIDBODY_SET_ANGULAR_VELOCITY,RIGIDBODY_APPLY_LINEAR_IMPULSE,RIGIDBODY_APPLY_POINT_IMPULSE,RIGIDBODY_APPLY_ANGULAR_IMPULSE,WORLD_OBJECT_ADD_REFERENCE,WORLD_OBJECT_REMOVE_REFERENCE,ACTIVATE_REGION,ACTIVATE_ENTITY,DEACTIVATE_ENTITY,CONSTRAINT_FILTER_BROKEN_EVENT,USER_CALLBACK} ; class TypeTagRelatedClass; struct TypeTag{
TypeTag(Type type)throw():vt6(type){ } TE1<Type,TU8>vt6; private:TypeTag()throw();
} ; struct HandleNode; struct UpdateEntity;
struct RigidBodyMotionTypeChange; struct WorldObjectShapeChange; struct EntityBatchAddPayload:public TypeTag{ EntityBatchAddPayload()throw():TypeTag(ENTITY_BATCH_ADD){
} TE**ve1; TOI vnE; TE1<TEA,TU8>va2;
} ; struct WorldOperationBeforeAddConstraint; struct AddConstraint;
struct WorldOperationBeforeAddActionCommand; struct AddActionCommand; struct WorldOperationAfterAddActionCommand; struct WorldOperation;
struct ForwardDeclaredCommandType; struct ForwardDeclaredWorldOperation8; struct LaterForwardDeclaredCommandType; struct ForwardDeclaredWorldOperation10;
struct OperationBeforePhantomBroadphaseUpdate; struct PhantomBroadphaseUpdate; struct OperationAfterPhantomBroadphaseUpdate; struct SecondPostPhantomBroadphaseOperation;
struct ForwardDeclaredStructAtPositionThirteen; struct ForwardDeclaredStructAtPositionFourteen; struct PhysicsCommand; struct ForwardDeclaredStructAtPositionSixteen;
struct RigidBodyPositionRotationUpdate; struct FourteenthForwardDeclaredType; struct FifteenthForwardDeclaredType; struct ForwardDeclaredStructInSequence;
struct ForwardDeclaredTypeAtPositionThirteen; struct TrailingForwardDeclaredStruct; struct AddReference; struct RemoveReference;
struct ForwardStructAtPositionTwentyFive; struct ForwardStructAtPositionTwentySix; struct IncompleteStructType; struct ForwardDeclaredType;
struct StructAfterForwardDeclaredType; struct OpaqueStructType; }
struct TBOE;
class TWOQ;
struct TDIOPOQ;
class TW;
struct TCBE;
struct TCRE;
class TSI1;
class TP;
class TCILBL;
class TCILBLI;
class TSCCM;
class TCE1;
class TCP;
class TCPP;

class TCPE;
class TC2;
struct TCI;
class TCM2;
class TSC3:public TRO{ public:enum MemoryType{
MEM_OBJECT,MEM_NORMAL,MEM_ALLOCATED,MEM_ARRAY,MEM_OTHER,MEM_LAST,} ; enum Flag{ EXCLUDE_OBJECT_MEMORY=0x1,}
; virtual void vs62()throw(); virtual void vs63()throw(); virtual void vs64()throw();
virtual void vs65()throw(); virtual void vs66()throw(); protected:public:const void*vcD; TVCR*vvR;
bool viUAM; } ;
class TCMF;
struct TPCP;
struct TPCD;
class TCB;
struct TPCI;
struct TPCO;
class TC2;
class TGC;
class TCPM;
struct TSCCA;
class TCPP;
__declspec(align(16))class TCPPWEUD16;
class TCPPS;
;
class TCQI1;
class TCQO;
class TCP;
class TCPP;
struct TSCCA;
class TSCCDI;
class TSCCDII;
extern TR KCLERV;
extern TR KCEERV;
extern"C"{ }
;
class TCP;
class TCM1;
class TCPPS;
struct TCA1;
typedef void(__cdecl*TCABJF)(class TCD1*vcD2,const TCQI1&in,TCQO&out);
struct TBCA;
struct TBA;
struct TSCCA;
struct TBSCA;
struct TSSCA;
struct TSLTCA;
struct TSLTCA1;
struct TSLRCA;
struct TOPCA;
struct TLCA;
struct TLSCA;
struct TLLCA;
struct T2dACA;
struct TACA;
struct TALCA;
struct TTLCA;
struct TCLCA;
struct TAFCA;
struct TAMCA;
struct TRMCA;
struct TLFCA;
struct TLMCA;
struct TPCA;
struct TMCA;
struct TSCMCA;
struct TMCMCA;
struct TCOMCMCA;
struct TVSMCA;
struct TMSMCA;
struct TIMCA;
class TCM2;
class TCP;
class TCPP;
class TV4;
class TDCM;
class TDCIM;
class TSCCAU;
class TCP;
class TSR1;
class TRB;
class TSCCM;
class TSCCD;
class TW;
extern const TC1 TSCCMC;
class TSCCM;
class TRB;
class TV4;
class TCP;
class TSCCU;
struct TPCP;
class TCS1;
class TTS;
class TGC;
__declspec(align(16))class TGC16;
enum{ KMCP=256} ;
struct TAE;
struct TPCD;
class TCM2;
struct TPCO;
class TC2;
struct TCI;
struct TPCO;
class TE;
class TDCM;
enum TCPA{ KCPA=0,KCPR=1} ;
struct TTPAE;
struct TMPAE;
struct TSCCA;
struct TCPAE;
struct TTPAE;
struct TMPAE;
struct TCPCE;
struct TCPRE;
struct TCPE1;
class TCL1;
class TWCU{ public:static void __cdecl NotifyEntityAdded(TW*world,TE*entity)throw(); }
;
class TE;
class TECU{ public:static void __cdecl hkpEntityCallbackUtil_fireEntityAdded(TE*entity)throw();
protected:public:protected:} ;
class TCD;
class EnumIntegerValue;
class TCLF;
struct TCAC;
class TSCQD;
struct TCI{
public:TR getTolerance()const throw(){ return vt3; } public:TPS<TCD*>vd3;
TPS<TB32>vwCP; TPS<TR>vt3; TPS<const EnumIntegerValue*>vf; TPS<const TCLF*>vcLF;
mutable TPS<TB32>vcPA; struct AabbBoundsAndScale{ TV4 vbOL; TV4 vbOH;
TV4 vbS; } ; AabbBoundsAndScale va32I;
} ;
struct TA1nS;
struct TCQI;
struct TA1nS;
struct TPCI:public TCI{ public:public:TSI1 vsI4; mutable TPS<TCQI*>vcQI;
mutable TA1nS*vsAS; void*vdI1; TB veDW; TB vaTSCC;
TCAC*vc4; } ;
class TBP;
class TBPH;
class TBPHP;
class TA;
class TPCC;
class TBPCC;
typedef char TBPAC;
class TBP:public TRO{ public:enum BroadPhaseType{
BROADPHASE_16BIT,BROADPHASE_32BIT} ; virtual void vs67()const throw(); virtual void vs68()throw();
virtual void vs69()throw(); virtual void UpdatePairs(const TAB<TBPH*>&addObjectList,const TAB<TA>&addAabbList,TA2<TBPHP>&newPairs)throw()=0; virtual void vs70()throw(); virtual void vs711()throw();
virtual void vs72()const throw(); virtual void vs73()throw(); virtual void vs74()throw(); virtual void vs75()throw();
virtual void vs76()throw(); virtual void vs77()const throw(); virtual void getAabb(const TBPH*object,TA&aabb)const throw()=0; virtual void vs78()const throw();
virtual void vs79()const throw(); virtual void vs80()const throw(); virtual void vs811()const throw(); virtual void vs82()throw();
virtual void vs83()throw(); virtual void vs84()const throw(); struct TCRI{ TV4 vf3;
int vnC; const TV4*vtB; int vtS; const TBPAC*vaCI;
} ; virtual void vs85()const throw(); virtual void vs86()const throw();
virtual void vs87()const throw(); virtual void vs88()const throw(); struct TCAI{ TV4 vf3;
TV4 vt2; TV4 vhE; const TBPAC*vaCI; }
; virtual void vs89()const throw(); virtual void vs90()throw(); typedef TBP*(__cdecl*createBroadPhaseFunc)(const TV4&worldMin,const TV4&worldMax,int numMarkers);
static createBroadPhaseFunc vdCF; protected:protected:mutable TMTC vmTC; class TCS2*vcS1; public:class ScopedBroadPhaseFactoryOverride{
public:public:createBroadPhaseFunc voCBF; private:} ; }
;
class TBPH;
class TBPHP{ public:TBPH*va;
TBPH*vb; } ;
class TNBPL:public TRO,public TBPL{
public:virtual void vs59()throw(); virtual void vs60()throw(); } ;
class TTBPHP;
class TBPHP;
class TBPL;
class TTBPD{
public:void hkpTypedBroadPhaseDispatcher_addPairs(TTBPHP*newPairs,int numNewPairs,const TCCF*filter)const throw(); protected:TBPL*vbPL[8][8]; TNBPL vnBPL; }
;
template<typename T>class TLA1:public TA2<T>{ public:__forceinline TLA1(int capacity)throw(){ this->vd1=TAS1<T>(capacity);
this->vcAF=capacity|TA2<T>::DONT_DEALLOCATE_FLAG; vlM=this->vd1; } __forceinline TB wasReallocated()const throw(){
return vlM!=this->vd1; } __forceinline~TLA1()throw(){ if(!wasReallocated()){
TA2<T>::clear(); } TDS<T>(vlM); }
T*vlM; } ;
namespace TSTU{
// @fnv 0x00c94bd0
void __cdecl hkSweptTransformUtil_setTimeInformation(TT startTime,TR invDeltaTime,TMS1&motionState)throw(); extern const TQR g_vSimdVectorConstant; }
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void __movsd(unsigned long*, unsigned long const*, size_t);
extern const char str_010c68c8[];
extern const char str_010c41f8[];


struct Sbp_Allocator {
    virtual void slot0(); virtual void slot1(); virtual void slot2();
    virtual void* BufAlloc(int& bytes);
    virtual void BufFree(void* p, int bytes);
};
struct Sbp_Router { int unk00; int unk04; int unk08; int unk0C; Sbp_Allocator* unk10; };
static inline Sbp_Router* Sbp_router() { return (Sbp_Router*)hkMemoryRouter_getInstance(); }
void __cdecl hkpEntityAabbUtil_entityBatchRecalcAabb(void*, void*, int);
struct Sbp_Pair { void* a; void* b; };
template <class T> struct Sbp_Array {
    T* data; int size; int capacity;
    void destroy() { ClearAndRelease(Sbp_router()->unk10); }
    void ClearAndRelease(Sbp_Allocator* heap) {
        size = 0;
        if ((capacity & 0x80000000) == 0) heap->BufFree(data, (capacity & 0x3fffffff) * sizeof(T));
    }
};
struct Sbp_Vec {
    LocalM128 q;
    void add4(const Sbp_Vec& a) { q = _mm_add_ps(q, a.q); }
};
struct Sbp_BroadPhase {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20();
    virtual void ShiftBroadPhase(const Sbp_Vec& shift, Sbp_Vec& effective, Sbp_Array<Sbp_Pair>& pairs);
    virtual void GetOffsetLowHigh32Bit(Sbp_Vec& low, Sbp_Vec& high);
};
struct Sbp_CollisionInput {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    Sbp_Vec m_kAabbMin;
    Sbp_Vec m_kAabbMaximum;
};
struct Sbp_Dispatcher { void hkpTypedBroadPhaseDispatcher_addPairs(Sbp_Pair* pairs, int count, void* filter); };
struct Sbp_Phantom {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual int getType();
};
struct Sbp_AabbPhantom : Sbp_Phantom {
    int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C;
    int unkA0; int unkA4; int unkA8; int unkAC;
    Sbp_Vec m_aabbMin;
    Sbp_Vec m_aabbMax;
};
struct Sbp_ShapePhantom : Sbp_Phantom {
    int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C;
    int unkA0; int unkA4; int unkA8; int unkAC; int unkB0; int unkB4; int unkB8; int unkBC;
    int unkC0; int unkC4; int unkC8; int unkCC; int unkD0; int unkD4; int unkD8; int unkDC;
    Sbp_Vec m_vTranslation;
};
struct Sbp_Border {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14;
    Sbp_Phantom* m_kPhantoms[6];
    void shiftPhantoms(LocalM128& raw);
};
static inline Sbp_Phantom* Sbp_getPhantom(Sbp_Border* b, const int& i) { return b->m_kPhantoms[i]; }
__forceinline void Sbp_Border::shiftPhantoms(LocalM128& raw) { Sbp_Vec& effective=(Sbp_Vec&)raw;
    Sbp_Phantom* const* phantoms = m_kPhantoms;
    for (int i = 0; i < 6; i++) {
        Sbp_Phantom* phantom = phantoms[i];
        switch (phantom->getType()) {
        case 0:
            ((Sbp_AabbPhantom*)phantom)->m_aabbMin.add4(effective);
            ((Sbp_AabbPhantom*)phantom)->m_aabbMax.q = _mm_add_ps(effective.q, ((Sbp_AabbPhantom*)phantom)->m_aabbMax.q);
            break;
        case 1:
        case 2:
            ((Sbp_ShapePhantom*)phantom)->m_vTranslation.add4(effective);
            break;
        }
    }
}
struct Sbp_Entity { int unk00; int unk04; int unk08; int unk0C; void* unk10; };
struct Sbp_Island {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44;
    Sbp_Array<Sbp_Entity*> m_kActorEntries;
};
template <class T> static __forceinline T* Sbp_bufAlloc(Sbp_Allocator* heap, int& n) {
    int bytes = n * sizeof(T);
    T* p = (T*)heap->BufAlloc(bytes);
    n = bytes / (int)sizeof(T);
    return p;
}
template <class T> static __forceinline void Sbp_freeArray(Sbp_Allocator* heap, T* data, int cap) {
    if ((cap & 0x80000000) == 0) heap->BufFree(data, (cap & 0x3fffffff) * sizeof(T));
}
template <class T> static inline void Sbp_copy(T* dst, const T* src, int n) {
    for (int i = 0; i < n; i++) dst[i] = src[i];
}
static __forceinline void Sbp_initArray(Sbp_Island**& data, int& size, int& cap, int n) {
    size = n;
    Sbp_Router* r = Sbp_router();
    Sbp_Allocator* heap = r->unk10;
    _ReadWriteBarrier();
    data = size ? Sbp_bufAlloc<Sbp_Island*>(heap, size) : 0;
    cap = size ? size : 0x80000000;
}
struct Sbp_World : hkpWorld {
    void hkpWorld_shiftBroadPhase(const LocalM128& rawShift, LocalM128& rawEffective, int update);
    void FUN_00c91120();
    void UpdateFields_00c91140();
};
static __forceinline void doShift(Sbp_World* self,const LocalM128& rawShift, LocalM128& rawEffective, int update);
typedef float hkReal_S;
typedef signed short hkInt16_S;
typedef unsigned short hkUint16_S;
typedef unsigned long __w64 hkUlong_S;
typedef unsigned __w64 hk_size_t;

// BooleanTypeConstant / hkTypeIsPod: include/hkTypeTraits.h

;
typedef LocalM128 hkQuadReal;
class hkVector4_S;
typedef const hkVector4_S&hkVector4Parameter;
inline hkSimdReal::hkSimdReal() {}
static __forceinline hkSimdReal makeVectorComponent(const LocalM128& value)
{
    hkSimdReal result;
    result.m_vValue = value;
    return result;
}
static __forceinline hkSimdReal makeScalarComponent(float value)
{
    hkSimdReal result;
    result.m_vValue = (_mm_load_ss)(&value);
    return result;
}
inline hkSimdReal::operator float() const { float result; _mm_store_ss(&result, m_vValue); return result; }
__forceinline LocalM128 hkSimdReal::broadcast() const { return _mm_shuffle_ps(m_vValue, m_vValue, 0); }
__forceinline const LocalM128& hkSimdReal::getQuad() const { return m_vValue; }
template <typename T> inline void hkMemoryAllocator::_bufFree(void* p, int count) { ReturnMemory(p, count * (int)sizeof(T)); }
inline void hkStackMemory::deallocateStack(void* p) { m_next = p; }
template <typename T> inline hkSingleton<T>::hkSingleton() {}
typedef const hkSimdReal&hkSimdRealParameter;
extern const hkQuadReal g_vQuadRealConstant;
class hkTransform_S;


inline hkQuadReal&hkVector4_S::getQuad()
{
return m_vComponents;
}
inline void hkVector4_S::operator=(const hkVector4_S&v)
{
m_vComponents=v.m_vComponents;
}
inline void hkVector4_S::set(hkReal_S a,hkReal_S b,hkReal_S c,hkReal_S d)
{
m_vComponents=_mm_setr_ps(a,b,c,d);
}
inline void hkVector4_S::SetAllComponents(hkSimdRealParameter a)
{
m_vComponents=_mm_shuffle_ps(a.getQuad(),a.getQuad(),(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
}
inline void hkVector4_S::add4(const hkVector4_S&v)
{
m_vComponents=_mm_add_ps(m_vComponents,v.m_vComponents);
}
inline void hkVector4_S::setAdd4(const hkVector4_S&v0,const hkVector4_S&v1)
{
m_vComponents=_mm_add_ps(v0.m_vComponents,v1.m_vComponents);
}
inline void hkVector4_S::sub4(const hkVector4_S&v)
{
m_vComponents=_mm_sub_ps(m_vComponents,v.m_vComponents);
}
inline void hkVector4_S::setSub4(const hkVector4_S&v0,const hkVector4_S&v1)
{
m_vComponents=_mm_sub_ps(v0.m_vComponents,v1.m_vComponents);
}
inline void hkVector4_S::setMul4(const hkVector4_S&a,const hkVector4_S&b)
{
m_vComponents=_mm_mul_ps(a.m_vComponents,b.m_vComponents);
}
inline void hkVector4_S::addMul4(hkSimdRealParameter r,const hkVector4_S&v1)
{
m_vComponents=_mm_add_ps(m_vComponents,
_mm_mul_ps(r.broadcast(),v1.m_vComponents));
}
inline void hkVector4_S::addMul4(const hkVector4_S&x,const hkVector4_S&y)
{
m_vComponents=_mm_add_ps(m_vComponents,
_mm_mul_ps(x.m_vComponents,y.m_vComponents));
}
inline void hkVector4_S::setAddMul4(const hkVector4_S&a,const hkVector4_S&x,const hkVector4_S&y)
{
m_vComponents=_mm_add_ps(a.m_vComponents,
_mm_mul_ps(x.m_vComponents,y.m_vComponents));
}
inline void hkVector4_S::setCross(const hkVector4_S&v0,const hkVector4_S&v1)
{
hkQuadReal cross0;
cross0=_mm_mul_ps(
_mm_shuffle_ps(v0.m_vComponents,v0.m_vComponents,(((3)<<6)|((0)<<4)|((2)<<2)|((1)))),
_mm_shuffle_ps(v1.m_vComponents,v1.m_vComponents,(((3)<<6)|((1)<<4)|((0)<<2)|((2)))));
hkQuadReal cross1;
cross1=_mm_mul_ps(
_mm_shuffle_ps(v0.m_vComponents,v0.m_vComponents,(((3)<<6)|((1)<<4)|((0)<<2)|((2)))),
_mm_shuffle_ps(v1.m_vComponents,v1.m_vComponents,(((3)<<6)|((0)<<4)|((2)<<2)|((1)))));
m_vComponents=_mm_sub_ps(cross0,cross1);}
inline hkSimdReal hkVector4_S::dot3(const hkVector4_S&a)const
{
hkQuadReal x2=_mm_mul_ps(m_vComponents,a.m_vComponents);
hkQuadReal xySum=_mm_add_ss(_mm_shuffle_ps(x2,x2,(((1)<<6)|((1)<<4)|((1)<<2)|((1)))),x2);
return makeVectorComponent(_mm_add_ss(_mm_shuffle_ps(x2,x2,(((2)<<6)|((2)<<4)|((2)<<2)|((2)))),xySum));}
inline hkSimdReal hkVector4_S::length3()const
{
return makeVectorComponent(_mm_sqrt_ss(this->dot3(*this).getQuad()));
}
inline void hkVector4_S::setXYZW(const hkVector4_S&xyz,const hkVector4_S&w)
{
m_vComponents=_mm_shuffle_ps(xyz.m_vComponents,_mm_unpackhi_ps(xyz.m_vComponents,w.m_vComponents),(((3)<<6)|((0)<<4)|((1)<<2)|((0))));
}
inline hkSimdReal hkVector4_S::getSimdAt(int i)const
{
switch(i)
{
case 0:
return makeVectorComponent(m_vComponents);
case 1:
return makeVectorComponent(_mm_shuffle_ps(m_vComponents,m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1)))));
case 2:
return makeVectorComponent(_mm_shuffle_ps(m_vComponents,m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2)))));
case 3:
default:
return makeVectorComponent(_mm_shuffle_ps(m_vComponents,m_vComponents,(((3)<<6)|((3)<<4)|((3)<<2)|((3)))));
}
}
inline void hkVector4_S::broadcast(int i)
{
if(i==0)
{
m_vComponents=_mm_shuffle_ps(m_vComponents,m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
}
}
inline void hkVector4_S::setBroadcast(const hkVector4_S&v,int i)
{
if(i==0)
{
m_vComponents=_mm_shuffle_ps(v.m_vComponents,v.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
}
else if(i==3)
{
m_vComponents=_mm_shuffle_ps(v.m_vComponents,v.m_vComponents,(((3)<<6)|((3)<<4)|((3)<<2)|((3))));
}
}
extern const hkQsTransform DAT_01268700;
struct hkStackDAD {
    char* m_cur;
};
struct hkRouterDAD {
    static hkStackDAD* __cdecl hkMemoryRouter_getInstance() throw();
};
__forceinline void transformLocalPoseToModelPoseDAD(int numTransforms, const short* parentIndices, const hkQsTransform& worldFromModel, const hkQsTransform* poseLocal, hkQsTransform* poseModelOut)
{
    for (int i = 0; i < numTransforms; i++)
    {
        const int parentId = parentIndices[i];
        const hkQsTransform& worldFromParent = (-1 != parentId) ? poseModelOut[parentId] : worldFromModel;
        poseModelOut[i].SetProduct(worldFromParent, poseLocal[i]);
    }
}
extern "C" void _ReadWriteBarrier();
extern int DAT_0108febc;
extern int DAT_01268188;
extern int DAT_01268318;
void* Object_DispatchCommandFour(unsigned int size);
void bhkSerializable_CloneCritLock(void);
void bhkSerializable_CloneCritUnlock(void);
struct TlsBlk_caa4a0 {
    unsigned int m_0000;
    unsigned int m_0004;
    unsigned int m_0008;
    unsigned int m_000c;
    unsigned int m_0010;
    unsigned int m_0014;
    unsigned int m_0018;
    unsigned int m_001c;
    unsigned int m_0020;
    unsigned int m_0024;
    unsigned int m_0028;
    unsigned int m_002c;
    unsigned int m_0030;
    unsigned int m_0034;
    unsigned int m_0038;
    unsigned int m_003c;
    unsigned int m_0040;
    unsigned int m_0044;
    unsigned int m_0048;
    unsigned int m_004c;
    unsigned int m_0050;
    unsigned int m_0054;
    unsigned int m_0058;
    unsigned int m_005c;
    unsigned int m_0060;
    unsigned int m_0064;
    unsigned int m_0068;
    unsigned int m_006c;
    unsigned int m_0070;
    unsigned int m_0074;
    unsigned int m_0078;
    unsigned int m_007c;
    unsigned int m_0080;
    unsigned int m_0084;
    unsigned int m_0088;
    unsigned int m_008c;
    unsigned int m_0090;
    unsigned int m_0094;
    unsigned int m_0098;
    unsigned int m_009c;
    unsigned int m_00a0;
    unsigned int m_00a4;
    unsigned int m_00a8;
    unsigned int m_00ac;
    unsigned int m_00b0;
    unsigned int m_00b4;
    unsigned int m_00b8;
    unsigned int m_00bc;
    unsigned int m_00c0;
    unsigned int m_00c4;
    unsigned int m_00c8;
    unsigned int m_00cc;
    unsigned int m_00d0;
    unsigned int m_00d4;
    unsigned int m_00d8;
    unsigned int m_00dc;
    unsigned int m_00e0;
    unsigned int m_00e4;
    unsigned int m_00e8;
    unsigned int m_00ec;
    unsigned int m_00f0;
    unsigned int m_00f4;
    unsigned int m_00f8;
    unsigned int m_00fc;
    unsigned int m_0100;
    unsigned int m_0104;
    unsigned int m_0108;
    unsigned int m_010c;
    unsigned int m_0110;
    unsigned int m_0114;
    unsigned int m_0118;
    unsigned int m_011c;
    unsigned int m_0120;
    unsigned int m_0124;
    unsigned int m_0128;
    unsigned int m_012c;
    unsigned int m_0130;
    unsigned int m_0134;
    unsigned int m_0138;
    unsigned int m_013c;
    unsigned int m_0140;
    unsigned int m_0144;
    unsigned int m_0148;
    unsigned int m_014c;
    unsigned int m_0150;
    unsigned int m_0154;
    unsigned int m_0158;
    unsigned int m_015c;
    unsigned int m_0160;
    unsigned int m_0164;
    unsigned int m_0168;
    unsigned int m_016c;
    unsigned int m_0170;
    unsigned int m_0174;
    unsigned int m_0178;
    unsigned int m_017c;
    unsigned int m_0180;
    unsigned int m_0184;
    unsigned int m_0188;
    unsigned int m_018c;
    unsigned int m_0190;
    unsigned int m_0194;
    unsigned int m_0198;
    unsigned int m_019c;
    unsigned int m_01a0;
    unsigned int m_01a4;
    unsigned int m_01a8;
    unsigned int m_01ac;
    unsigned int m_01b0;
    unsigned int m_01b4;
    unsigned int m_01b8;
    unsigned int m_01bc;
    unsigned int m_01c0;
    unsigned int m_01c4;
    unsigned int m_01c8;
    unsigned int m_01cc;
    unsigned int m_01d0;
    unsigned int m_01d4;
    unsigned int m_01d8;
    unsigned int m_01dc;
    unsigned int m_01e0;
    unsigned int m_01e4;
    unsigned int m_01e8;
    unsigned int m_01ec;
    unsigned int m_01f0;
    unsigned int m_01f4;
    unsigned int m_01f8;
    unsigned int m_01fc;
    unsigned int m_0200;
    unsigned int m_0204;
    unsigned int m_0208;
    unsigned int m_020c;
    unsigned int m_0210;
    unsigned int m_0214;
    unsigned int m_0218;
    unsigned int m_021c;
    unsigned int m_0220;
    unsigned int m_0224;
    unsigned int m_0228;
    unsigned int m_022c;
    unsigned int m_0230;
    unsigned int m_0234;
    unsigned int m_0238;
    unsigned int m_023c;
    unsigned int m_0240;
    unsigned int m_0244;
    unsigned int m_0248;
    unsigned int m_024c;
    unsigned int m_0250;
    unsigned int m_0254;
    unsigned int m_0258;
    unsigned int m_025c;
    unsigned int m_0260;
    unsigned int m_0264;
    unsigned int m_0268;
    unsigned int m_026c;
    unsigned int m_0270;
    unsigned int m_0274;
    unsigned int m_0278;
    unsigned int m_027c;
    unsigned int m_0280;
    unsigned int m_0284;
    unsigned int m_0288;
    unsigned int m_028c;
    unsigned int m_0290;
    unsigned int m_0294;
    unsigned int m_0298;
    unsigned int m_029c;
    unsigned int m_02a0;
    unsigned int m_02a4;
    unsigned int m_02a8;
    unsigned int m_02ac;
    unsigned int m_02b0;
    int m_02b4;
};
__declspec(thread) TlsBlk_caa4a0 g_tlsBlock;
class TlsGuard_caa4a0 {
public:
    int m_saved;
    TlsGuard_caa4a0() { m_saved = g_tlsBlock.m_02b4; g_tlsBlock.m_02b4 = 0x10; }
    ~TlsGuard_caa4a0() { g_tlsBlock.m_02b4 = m_saved; }
};
struct caa4a0_TblHost { void* m_00; void* m_04; void* m_08; unsigned int* m_0c; };
struct caa4a0_TblFirst { unsigned int* m_00; };
class caa4a0_RefObj {
public:
    virtual void slot00();
    virtual void slot04(int a, unsigned int b);
};
class caa4a0_Target {
public:
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
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
    virtual unsigned int* slotb4(bool* flagOut);
    unsigned int unk04;
    caa4a0_TblHost* unk08;
    caa4a0_TblFirst* unk0c;
    void bhkConstraint_CopyMembers(bhkRefObject* obj, unsigned int param);
    bhkRefObject* bhkLimitedHingeConstraint_CreateClone(unsigned int param);
};
static inline void** AddBack(hkArray<void*>* arr, void* listener) {
    ThreadMemHolder* mem = (ThreadMemHolder*)hkMemoryRouter_getInstance();
    if (arr->m_iElementCount == (arr->m_iCapacityState & 0x3fffffff)) {
        ResizeAudioStream(mem->m_alloc, arr, 4);
    }
    void** p = &arr->m_data[arr->m_iElementCount];
    *p = listener;
    arr->m_iElementCount++;
    return p;
}
struct FUN_00c939a0_Class : hkpWorld {
    void** hkpWorld_addIslandPostCollideListener(void* listener);
};
void ResizeAudioStream(void*, void*, int);
struct hkpWorld_Listener : hkpWorld {
    void*& hkpWorld_addWorldDeletionListener(void* listener);
};
struct FUN_00c92c70_Class {
    void __thiscall hkpWorld_removePhantom(void* phantom);
};
struct FUN_00c936a0_Class {
    void __thiscall hkpWorld_addPhantom(void* phantom);
};
union __declspec(align(16)) PositionQuad {
    LocalM128 simd;
    signed char bytes[16];
};
struct __declspec(align(16)) SavedPosition {
    PositionQuad quad;
    SavedPosition() {}
    SavedPosition(const SavedPosition& other) { quad.simd = *(const LocalM128*)&other.quad.bytes[0]; }
};
struct ActionObj {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void AssignEntity(void* entity);
    void* unk04;
    FUN_00c92c70_Class* m_pOwningWorld;
    void* unk0C;
    void* m_pEntity;
};
struct FUN_00cac980_Holder {
    void* __thiscall hkpCharacterProxy_getShapePhantom();
};
struct FUN_00cac910_shell : FUN_00cac980_Holder {
    const SavedPosition& __thiscall hkpCharacterProxy_getPosition();
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    ActionObj* unk30;
};
struct ArgClass {
    void* unk00;
    void* unk04;
    void* unk08;
};
extern const SavedPosition zeroPosition;
struct HostClass : NiObject {
    FUN_00cac910_shell* unk08;
    __forceinline const SavedPosition& getPosition() {
        FUN_00cac910_shell* proxy = unk08;
        const SavedPosition* result = &zeroPosition;
        if (proxy) {
            this->NiObject::GetStreamableRTTI();
            result = &proxy->hkpCharacterProxy_getPosition();
            this->NiObject::GetStreamableRTTI();
        }
        return *result;
    }
    bool __thiscall bhkCharacterController_SetShape(ArgClass* a1, int a2);
};

void ResizeAudioStream(void*, void*, int);
template <typename T>
inline T* hkArrayPushBack(hkArray<T>& arr, hkMemoryRouter* mem, const T& t) {
    if (arr.m_iElementCount == (arr.m_iCapacityState & 0x3fffffff)) {
        ResizeAudioStream(mem->m_pStreamAllocator, &arr, sizeof(T));
    }
    T* p = &arr.m_data[arr.m_iElementCount];
    *p = t;
    arr.m_iElementCount++;
    return p;
}
struct FUN_00c93aa0_Class : hkpWorld {
    void* hkpWorld_addContactImpulseLimitBreachedListener(void* listener);
};
struct PhantomBatchAllocator {
    virtual void slot00() throw();
    virtual void slot04() throw();
    virtual void slot08() throw();
    virtual void slot0C() throw();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};
struct PhantomBatchRouter {
    void* m_aiEntries;
    void* unk04;
    void* unk08;
    void* unk0C;
    PhantomBatchAllocator* m_pStreamAllocator;
};
void __cdecl hkpWorldCallbackUtil_firePhantomRemoved(hkpWorld* world, hkpPhantom* phantom) throw();
struct BroadPhaseCastCollector {
    hkpBroadPhaseHandle* m_kPointA;
    hkpBroadPhaseHandle* m_kPointB;
};
template <class T>
struct PhantomBatchLocalArray : hkArray<T> {
    T* m_pTrailingData;
    __forceinline PhantomBatchLocalArray(int n) throw() {
        this->m_data = 0;
        this->m_iElementCount = 0;
        this->m_iCapacityState = (int)0x80000000;
        PhantomBatchRouter* mem = (PhantomBatchRouter*)hkMemoryRouter_getInstance();
        char* p = (char*)mem->m_aiEntries;
        int bytes = (n * (int)sizeof(T) + 0x7f) & ~0x7f;
        mem->m_aiEntries = p + bytes;
        this->m_data = (T*)p;
        this->m_iCapacityState = n | (int)0x80000000;
        m_pTrailingData = (T*)p;
    }
};
template <class T>
__forceinline void PhantomBatchLocalArray_release(PhantomBatchLocalArray<T>& a) throw() {
    if (a.m_pTrailingData == a.m_data) {
        a.m_iElementCount = 0;
    }
    T* local = a.m_pTrailingData;
    PhantomBatchRouter* stackRouter = (PhantomBatchRouter*)hkMemoryRouter_getInstance();
    stackRouter->m_aiEntries = local;

    PhantomBatchRouter* router = (PhantomBatchRouter*)hkMemoryRouter_getInstance();
    PhantomBatchAllocator* heap = router->m_pStreamAllocator;
    int cap = a.m_iCapacityState;
    a.m_iElementCount = 0;
    if (cap & (int)0x80000000) {
        return;
    }
    heap->ReturnMemory(a.m_data, (cap & 0x3fffffff) * (int)sizeof(T));
}
__forceinline int PhantomBatchIndexOf(const hkArray<hkpPhantom*>& arr, hkpPhantom* phantom) throw() {
    int count = arr.m_iElementCount;
    int idx = 0;
    if (count > 0) {
        hkpPhantom** cursor = arr.m_data;
        do {
            if (*cursor == phantom) {
                return idx;
            }
            ++idx;
            ++cursor;
        } while (idx < count);
    }
    return -1;
}
__forceinline void PhantomBatchRemoveAt(hkArray<hkpPhantom*>& arr, int index) throw() {
    --arr.m_iElementCount;
    if (arr.m_iElementCount != index) {
        arr.m_data[index] = arr.m_data[arr.m_iElementCount];
    }
}
struct RemovePhantomBatchOp {
    unsigned char m_type;
    hkpPhantom** m_kPhantoms;
    unsigned short m_iPhantomCount;
};
struct BroadPhaseVt {
    virtual void s00() throw();
    virtual void s04() throw();
    virtual void s08() throw();
    virtual void s0C() throw();
    virtual void s10() throw();
    virtual void s14() throw();
    virtual void s18() throw();
    virtual void s1C() throw();
    virtual void RemoveObjectBatch(hkArray<hkpBroadPhaseHandle*>& handles, hkArray<BroadPhaseCastCollector>& pairs) throw();
};
struct BroadPhaseDispatcher {
    void DispatchPairs(BroadPhaseCastCollector* data, int numPairs) throw();
};
struct World_RemovePhantomBatch : hkpWorld {
    void hkpWorld_queueOperation(RemovePhantomBatchOp* op) throw();
    void FUN_00c91120() throw();
    void UpdateFields_00c91140() throw();
    void hkpWorld_removePhantomBatch(hkpPhantom** phantomBatch, int numPhantoms);
};
struct __declspec(align(16)) Vec_00c98780 {
    LocalM128 q;
    void FUN_00c7f7a0(const hkTransform& tr, const hkVector4& v);
};
extern const float DAT_01011d78;
struct Vec_00c98c80 {
    LocalM128 m_vComponents;
    void set(const float& x, const float& y, const float& z, const float& w)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
};
struct Aabb_00c98c80 {
    Vec_00c98c80 m_kMinimumCorner;
    Vec_00c98c80 m_kMaximumCorner;
};
struct Line_00c98c80 {
    Vec_00c98c80 a;
    Vec_00c98c80 b;
};
struct Xf_00c996e0 {
    LocalM128 c0;
    LocalM128 c1;
    LocalM128 c2;
    void SetFromInput_Thunk(const hkQsTransform& a);
};
extern __declspec(thread) unsigned int t_uiMemContextCAA;
inline unsigned int GetMemContextCAA()
{
    return t_uiMemContextCAA;
}
inline void SetMemContextCAA(unsigned int m_uiGeometryShaderFlags)
{
    t_uiMemContextCAA = m_uiGeometryShaderFlags;
}


struct __declspec(align(16)) hkVector4CAA {
    LocalM128 m_vComponents;
    inline hkVector4CAA& operator=(const hkVector4CAA& v) { m_vComponents = v.m_vComponents; return *this; }
};

class ShapeChildCAA {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual hkReferencedObject* v0C();
};
class ShapeCAA : public hkReferencedObject {
public:
    ShapeCAA(); // FUN_00cb9090

    void SetReferencedObject(hkReferencedObject* obj);

    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4CAA m_v20;
    hkVector4CAA m_v30;
    hkVector4CAA m_v40;
    hkVector4CAA m_v50;
    hkVector4CAA m_v60;
    hkVector4CAA m_v70;
    hkVector4CAA m_v80;
    hkVector4CAA m_v90;
    unsigned char unkA0;
    unsigned char unkA1;
    unsigned char m_flagA2;
    unsigned char unkA3;
    int unkA4;
    int unkA8;
    int unkAC;
    ShapeChildCAA* m_pChildAtom;
    int unkB4;
    int unkB8;
    float m_fBC;
    float unkC0;
    float m_fC4;
    float m_fC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
};
struct ShapeCinfoCAA {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_vScale;
};
void __cdecl hkHingeConstraintCinfo_ApplyScale(float scale, ShapeCAA* shape);
class ShapeClonerCAA {
public:
    ShapeCAA* ReleaseObject(ShapeCAA* shape, ShapeCinfoCAA* cinfo);
    ShapeCAA* hkLimitedHingeConstraintCinfo_CloneData(ShapeCAA* dst, ShapeCinfoCAA* cinfo);

    int unk00;
    ShapeCAA* m_pCollisionShape;
};
namespace BatchAdd {


struct BroadPhaseCastCollector {
    void* m_kPointA;
    void* m_kPointB;
};

template <typename T>
class StackAllocatedArray : public hkArray<T> {
public:
    void* m_initialBuffer;

    __forceinline StackAllocatedArray(int capacity) throw() {
        this->m_data = 0;
        this->m_iElementCount = 0;
        this->m_iCapacityState = 0x80000000;
        hkMemoryRouter* tm = (hkMemoryRouter*)::hkMemoryRouter_getInstance();
        void* cur = tm->stack().m_next;
        int numBytes = (capacity * sizeof(T) + 0x7f) & ~0x7f;
        tm->stack().m_next = (char*)cur + numBytes;
        this->m_data = (T*)cur;
        this->m_iCapacityState = capacity | 0x80000000;
        this->m_initialBuffer = cur;
    }

    __forceinline void ClearAndRelease(hkMemoryRouter* tm) throw() {
        hkMemoryAllocator* mem = tm->m_heap;
        int cap = this->m_iCapacityState;
        this->m_iElementCount = 0;
        if ((cap & 0x80000000) == 0) {
            mem->bufFree(this->m_data, (cap & 0x3fffffff) * sizeof(T));
        }
        this->m_data = 0;
        this->m_iCapacityState = 0x80000000;
    }

    __forceinline ~StackAllocatedArray() throw() {
        void* const initialBuffer = this->m_initialBuffer;
        if (initialBuffer == this->m_data) {
            this->m_iElementCount = 0;
        }
        ((hkMemoryRouter*)::hkMemoryRouter_getInstance())->stack().deallocateStack(initialBuffer);
        this->ClearAndRelease((hkMemoryRouter*)::hkMemoryRouter_getInstance());
    }

    __forceinline void setSizeUnchecked(int size) throw() {
        this->m_iElementCount = size;
    }
};

template <typename T>
__forceinline void hkConstructWithCopy(T* p, int n, const T& t) throw() {
    for (int i = 0; i < n; ++i) {
        p[i] = t;
    }
}

template <typename T>
__forceinline void AddBack(hkArray<T>& array, const T& t) throw() {
    hkMemoryRouter* tm = (hkMemoryRouter*)::hkMemoryRouter_getInstance();
    if (array.m_iElementCount == (array.m_iCapacityState & 0x3fffffff)) {
        ::ResizeAudioStream(tm->m_heap, &array, sizeof(T));
    }
    hkConstructWithCopy(array.m_data + array.m_iElementCount, 1, t);
    array.m_iElementCount++;
}

// The shared class does not yet declare this AABB update operation.
struct PhantomAabbOperations {
    void hkpPhantom_setBoundingVolumeData(hkAabb* aabb) throw();
};

struct BroadPhase {
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0C() throw();
    virtual void v10() throw();
    virtual void v14() throw();
    virtual void UpdatePairs(const hkArray<void*>& handles, const hkArray<hkAabb>& aabbs, hkArray<BroadPhaseCastCollector>& pairs) throw();
};

struct BroadPhaseDispatcher {
    void __thiscall hkpTypedBroadPhaseDispatcher_addPairs(BroadPhaseCastCollector* pairs, int numPairs, void* filter) throw();
};

struct PendingOp {
    unsigned char m_type;
    unsigned char m_uiStandInValue;
    unsigned char m_iValueAfterStandIn;
    unsigned char m_pAuxiliaryObject;
    hkpPhantom* const* m_kPhantoms;
    short m_iPhantomCount;
    short m_pad3;
};

struct WorldHelper : public hkpWorld {
    void __thiscall hkpWorld_queueOperation(void* op) throw();
    void __thiscall FUN_00c91120() throw();
    void __thiscall UpdateFields_00c91140() throw();

    void hkpWorld_addPhantomBatch(hkpPhantom* const* phantomBatch, int numPhantoms) throw();
};

// @fnv 0x00c954e0
// src: HAVOK_LIB 0x00c954e0
void WorldHelper::hkpWorld_addPhantomBatch(hkpPhantom* const* phantomBatch, int numPhantoms) throw() {
    if ((m_iCriticalOperationsLockCount + m_iCriticalOperationsLockCountForPhantoms) != 0) {
        PendingOp op;
        op.m_type = 0x0f;
        op.m_kPhantoms = phantomBatch;
        op.m_iPhantomCount = (short)numPhantoms;
        hkpWorld_queueOperation(&op);
        return;
    }

    m_iCriticalOperationsLockCount++;

    StackAllocatedArray<void*> handles(numPhantoms);
    StackAllocatedArray<hkAabb> aabbs(numPhantoms);
    aabbs.setSizeUnchecked(numPhantoms);
    handles.setSizeUnchecked(numPhantoms);

    for (int i = 0; i < numPhantoms; i++) {
        hkArray<hkpPhantom*>* const phantoms = (hkArray<hkpPhantom*>*)&m_kPhantoms;
        hkpPhantom* phantom = phantomBatch[i];
        if (!phantom->m_kCollidable.m_pMotionState) {
            phantom->m_kCollidable.m_pMotionState = (phantom->*reinterpret_cast<void* (hkpPhantom::*)()>(&hkpPhantom::vf06))();
        }
        phantom->m_pOwningWorld = this;
        handles.m_data[i] = &phantom->m_kCollidable.m_kBroadPhaseHandle;
        (phantom->*reinterpret_cast<void (hkpPhantom::*)(hkAabb*)>(&hkpPhantom::overlaps))(&aabbs.m_data[i]);
        reinterpret_cast<PhantomAabbOperations*>(phantom)->hkpPhantom_setBoundingVolumeData(&aabbs.m_data[i]);
        phantom->addReference();

        AddBack(*phantoms, phantom);

        NotifyPhantomAdded(this, phantom);
        phantom->firePhantomAdded();
    }

    StackAllocatedArray<BroadPhaseCastCollector> pairs(m_iBroadPhaseQuerySize);
    ((BroadPhase*)m_pJobSemaphore)->UpdatePairs(handles, aabbs, pairs);

    void* filter = m_pCollisionFilter ? (char*)m_pCollisionFilter + 8 : 0;
    ((BroadPhaseDispatcher*)m_pBroadPhaseDispatcher)->hkpTypedBroadPhaseDispatcher_addPairs(pairs.m_data, pairs.m_iElementCount, filter);

    m_iCriticalOperationsLockCount--;
    if (m_iCriticalOperationsLockCount == 0 && !m_bBlockExecutingPendingOperations) {
        if (m_iPendingOperationCount != 0) {
            FUN_00c91120();
        }
        if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount != 0) {
            UpdateFields_00c91140();
        }
    }
}

}
struct PendingCalls_00c97510 { void FUN_00c91120(); void UpdateFields_00c91140(); };
struct hkAllocQ70 {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void deallocate(void* p, int numBytes);
};
template <typename T>
inline void ConstructWithCopyC97510(T* pDst, int iCount, const T& kItem)
{
    for (int i = 0; i < iCount; ++i)
        pDst[i] = kItem;
}
template <typename T>
inline void PushBackC97510(::hkArray<T>& kArray, const T& kItem)
{
    ::hkMemoryRouter* pkMemory = (::hkMemoryRouter*)hkMemoryRouter_getInstance();
    if (kArray.m_iElementCount == (kArray.m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(pkMemory->m_pStreamAllocator, &kArray, sizeof(T));
    ConstructWithCopyC97510(kArray.m_data + kArray.m_iElementCount, 1, kItem);
    kArray.m_iElementCount++;
}
struct hkpWorldDecomp;
template <typename T>
struct InplaceArray4 : ::hkArray<T> {
    T m_kStorage[4];

    InplaceArray4() {
        this->m_data = m_kStorage;
        this->m_iElementCount = 0;
        this->m_iCapacityState = 0x80000004;
    }

    void ClearAndRelease() {
        ::hkMemoryRouter* tm = (::hkMemoryRouter*)hkMemoryRouter_getInstance();
        hkAllocQ70* mem = (hkAllocQ70*)tm->m_pStreamAllocator;
        int cap = this->m_iCapacityState;
        this->m_iElementCount = 0;
        if ((cap & 0x80000000) == 0) {
            mem->deallocate(this->m_data, (cap & 0x3fffffff) * sizeof(T));
        }
    }
};
template <typename T>
struct ResizableArray {
    T* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;

    int indexOf(T val) const {
        for (int i = 0; i < (int)m_iElementCount; ++i) {
            if (m_data[i] == val) return i;
        }
        return -1;
    }

    void removeAt(int index) {
        m_iElementCount--;
        m_data[index] = m_data[m_iElementCount];
    }
};
void __cdecl NotifyActionRemoved(::hkpWorld* world, hkpAction* action);
struct hkpWorldDecomp : ::hkpWorld {
    void RemoveActionFromWorld(hkpAction* action);
};

void __cdecl hkpWorldMemoryUtil_watchHeapMemory(void* world);

class C91Simulation {
public:
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual int SimulateForDeltaTime(float delta);
};

class C91World : public hkpWorld {
public:
    void IncrementCounter();
    void ahkpWorld_updateKdTree(int queue, int pool);
    int hkpWorld_stepDeltaTime(float delta);
};

// @fnv 0x00c91b10
// src: HAVOK_LIB 0x00c91b10
int C91World::hkpWorld_stepDeltaTime(float delta)
{
    IncrementCounter();
    hkpWorldMemoryUtil_watchHeapMemory(this);
    int result = reinterpret_cast<C91Simulation*>(m_pSimulation)->SimulateForDeltaTime(delta);
    if (m_pKdTreeManager) {
        if (m_bUseKdTree)
            ahkpWorld_updateKdTree(0, 0);
        else
            reinterpret_cast<FUN_00c91250_Class*>(this)->hkpWorld_markTreeDirty();
    }
    reinterpret_cast<FUN_00c91190_Class*>(this)->hkpWorld_unlock();
    return result;
}

struct StepSimulationEntryC91C {
    int hkpMultiThreadedSimulation_finishMtStep(void* queue, void* pool);
};

struct TreeUpdateEntryC91C {
    void ahkpWorld_updateKdTree(void* queue, void* pool);
};

struct WorldFinishEntryC91C : hkpWorld {
    int hkpWorld_finishMtStep(void* queue, void* pool);
};

// @fnv 0x00c91c00
// src: HAVOK_LIB 0x00c91c00
int WorldFinishEntryC91C::hkpWorld_finishMtStep(void* queue, void* pool)
{
    int result = reinterpret_cast<StepSimulationEntryC91C*>(m_pSimulation)->hkpMultiThreadedSimulation_finishMtStep(queue, pool);
    if (result != 0)
        return result;
    if (m_pKdTreeManager == 0)
        return 0;
    if (m_bUseKdTree != 0) {
        reinterpret_cast<TreeUpdateEntryC91C*>(this)->ahkpWorld_updateKdTree(queue, pool);
        return 0;
    }
    reinterpret_cast<FUN_00c91250_Class*>(this)->hkpWorld_markTreeDirty();
    return 0;
}


extern LocalM128 DAT_01017d10;

// Exe 0x00c98e60: shared hkVector4 storage with the unit's checked SIMD expression order.
static __forceinline void WorldVectorPlus(hkVector4& out, const hkVector4& a, const hkVector4& b) { out.m_vComponents=_mm_add_ps(a.m_vComponents,b.m_vComponents); }
static __forceinline void WorldVectorMinus(hkVector4& out, const hkVector4& a, const hkVector4& b) { out.m_vComponents=_mm_sub_ps(a.m_vComponents,b.m_vComponents); }
static __forceinline void WorldVectorScaled(hkVector4& out, LocalM128 scale, const hkVector4& value) { out.m_vComponents=_mm_mul_ps(_mm_shuffle_ps(scale,scale,0),value.m_vComponents); }
static __forceinline void WorldVectorAdd(hkVector4& out, const hkVector4& value) { out.m_vComponents=_mm_add_ps(out.m_vComponents,value.m_vComponents); }
static __forceinline void WorldVectorAbsolute(hkVector4& out, const hkVector4& value) { out.m_vComponents=_mm_and_ps(value.m_vComponents,DAT_01017d10); }
static __forceinline void WorldVectorScale(hkVector4& out, LocalM128 scale) { out.m_vComponents=_mm_mul_ps(_mm_shuffle_ps(scale,scale,0),out.m_vComponents); }


static __forceinline LocalM128 vload(const hkVector4& v)
{
    return v.m_vComponents;
}

static __forceinline void vstore(hkVector4& v, LocalM128 q)
{
    v.m_vComponents = q;
}

static __forceinline void WorldVectorCross(hkVector4& out, const hkVector4& a, const hkVector4& b)
{
    LocalM128 left = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents,a.m_vComponents,0xC9), _mm_shuffle_ps(b.m_vComponents,b.m_vComponents,0xD2));
    LocalM128 right = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents,a.m_vComponents,0xD2), _mm_shuffle_ps(b.m_vComponents,b.m_vComponents,0xC9));
    out.m_vComponents = _mm_sub_ps(left,right);
}
static __forceinline void WorldVectorNormalize(hkVector4& out)
{
    LocalM128 sq = _mm_mul_ps(out.m_vComponents,out.m_vComponents);
    LocalM128 sum = _mm_add_ss(_mm_shuffle_ps(sq,sq,0x55),sq);
    sum = _mm_add_ss(_mm_shuffle_ps(sq,sq,0xAA),sum);
    LocalM128 r = _mm_rsqrt_ss(sum);
    out.m_vComponents = _mm_mul_ps(out.m_vComponents,_mm_shuffle_ps(r,r,0));
}


// @fnv 0x00c98e60
void hkDebugDisplay::DisplayPlane(const hkVector4_S& planeValue, const hkVector4_S& offsetValue, float scale, int color, int id, int tag)
{
    const hkVector4& plane = reinterpret_cast<const hkVector4&>(planeValue);
    const hkVector4& offset = reinterpret_cast<const hkVector4&>(offsetValue);
    float negW = -plane.f[3];
    hkVector4 base;
    WorldVectorScaled(base, _mm_load_ss(&negW), plane);
    WorldVectorAdd(base, offset);

    hkVector4 basis;
    WorldVectorAbsolute(basis, plane);

    int axis;
    if (basis.f[0] < basis.f[1]) {
        if (basis.f[1] < basis.f[2])
            axis = 2;
        else
            axis = 1;
    } else {
        if (basis.f[0] < basis.f[2])
            axis = 2;
        else
            axis = 0;
    }

    vstore(basis, _mm_setzero_ps());
    basis.f[(axis + 1) % 3] = 1.0f;

    WorldVectorCross(basis,plane,basis);
    WorldVectorNormalize(basis);
    WorldVectorScale(basis, _mm_load_ss(&scale));
    hkVector4 side;
    WorldVectorCross(side,basis,plane);
    WorldVectorNormalize(side);
    WorldVectorScale(side, _mm_load_ss(&scale));

    int n = 1;
    int left = 4;
    do {
        hkVector4 a;
        if ((n-1)&2) WorldVectorMinus(a,base,side); else WorldVectorPlus(a,side,base);
        if ((n%4)/2) WorldVectorMinus(a,a,basis); else WorldVectorPlus(a,a,basis);
        hkVector4 c;
        if ((n%4)/2) WorldVectorMinus(c,base,side); else WorldVectorPlus(c,side,base);
        int n1=n+1;
        if ((n1%4)/2) WorldVectorMinus(c,c,basis); else WorldVectorPlus(c,c,basis);
        DisplayLine(reinterpret_cast<const hkVector4_S&>(a), reinterpret_cast<const hkVector4_S&>(c), color, id, tag);
        n = n1;
        --left;
    } while (left != 0);

    hkVector4 direction;
    direction.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&scale), _mm_load_ss(&scale), 0), plane.m_vComponents);
    RenderLine(reinterpret_cast<const hkVector4_S&>(base), reinterpret_cast<const hkVector4_S&>(direction), color, id, tag);
}

struct TierQuotientCtor { double denominator; float threshold; __forceinline float value() const { return denominator/threshold; } };


extern "C" void __debugbreak();
struct WorldCtor;
struct ObjectCtor;
union WordCtor { int i; float f; ObjectCtor* p; void* raw; };
struct ObjectVtableCtor {

    void (__thiscall* vf00)(ObjectCtor*);
    void (__thiscall* vf04)(ObjectCtor*);
    void (__thiscall* vf08)(ObjectCtor*);
    void (__thiscall* vf0c)(ObjectCtor*, WorldCtor*);
    void (__thiscall* vf10)(ObjectCtor*);
    void (__thiscall* vf14)(ObjectCtor*);
    void (__thiscall* vf18)(ObjectCtor*);
    void (__thiscall* vf1c)(ObjectCtor*);
    void (__thiscall* vf20)(ObjectCtor*);
    void (__thiscall* vf24)(ObjectCtor*);
    void (__thiscall* vf28)(ObjectCtor*);
    void (__thiscall* vf2c)(ObjectCtor*);
    void (__thiscall* vf30)(ObjectCtor*);
    void (__thiscall* vf34)(ObjectCtor*);
    void (__thiscall* vf38)(ObjectCtor*);
    void (__thiscall* vf3c)(ObjectCtor*);
    void (__thiscall* vf40)(ObjectCtor*);
    void (__thiscall* vf44)(ObjectCtor*);
    void (__thiscall* vf48)(ObjectCtor*);
    void (__thiscall* vf4c)(ObjectCtor*);
    void (__thiscall* vf50)(ObjectCtor*);
    void (__thiscall* vf54)(ObjectCtor*);
    void (__thiscall* vf58)(ObjectCtor*);
    void (__thiscall* vf5c)(ObjectCtor*);
    void (__thiscall* vf60)(ObjectCtor*);
    void (__thiscall* vf64)(ObjectCtor*);
    void (__thiscall* vf68)(ObjectCtor*);
    void (__thiscall* vf6c)(ObjectCtor*);
    void (__thiscall* vf70)(ObjectCtor*,::hkQuadReal*,::hkQuadReal*,::hkQuadReal*);
};
struct ObjectCtor {
    ObjectVtableCtor* vtable;
    unsigned short size;
    short references;

    WordCtor unk08;
    WordCtor unk0c;
    WordCtor unk10;
    WordCtor unk14;
    WordCtor unk18;
    WordCtor unk1c;
    union { WordCtor unk20; struct { unsigned short id20,id22; }; };
    union { WordCtor unk24; struct { unsigned short id24; unsigned char flags26,flags27; }; };
    WordCtor unk28;
    WordCtor unk2c;
    WordCtor unk30;
    WordCtor unk34;
    WordCtor unk38;
    WordCtor unk3c;
    WordCtor unk40;
    WordCtor unk44;
    WordCtor unk48;
    WordCtor unk4c;
    WordCtor unk50;
    WordCtor unk54;
    WordCtor unk58;
    WordCtor unk5c;
    WordCtor unk60;
    WordCtor unk64;
    WordCtor unk68;
    union { WordCtor unk6c; struct { unsigned char flag6c,flag6d,flag6e,flag6f; }; };
    WordCtor unk70;
    WordCtor unk74;
    WordCtor unk78;
    WordCtor unk7c;
    WordCtor unk80;
    WordCtor unk84;
    WordCtor unk88;
    WordCtor unk8c;
    WordCtor unk90;
    WordCtor unk94;
    WordCtor unk98;
    WordCtor unk9c;
    WordCtor unka0;
    WordCtor unka4;
    WordCtor unka8;
    WordCtor unkac;
    WordCtor unkb0;
    WordCtor unkb4;
    WordCtor unkb8;
    WordCtor unkbc;
    WordCtor unkc0;
    WordCtor unkc4;
    WordCtor unkc8;
    WordCtor unkcc;
    WordCtor unkd0;
    WordCtor unkd4;
    WordCtor unkd8;
    WordCtor unkdc;
    WordCtor unke0;
    WordCtor unke4;
    WordCtor unke8;
    WordCtor unkec;
    WordCtor unkf0;
    WordCtor unkf4;
    WordCtor unkf8;
    WordCtor unkfc;
    WordCtor unk100;
    WordCtor unk104;
    WordCtor unk108;
    WordCtor unk10c;
    WordCtor unk110;
    WordCtor unk114;
    WordCtor unk118;
    WordCtor unk11c;
    WordCtor unk120;
    ObjectCtor* FUN_00cf75c0(WorldCtor*);
    ObjectCtor* FUN_00cf6f90();
    ObjectCtor* InitializeFields_00d107d0(WorldCtor*);
    ObjectCtor* FUN_00cfd450(WorldCtor*);
    ObjectCtor* hkpCollisionDispatcher_hkpCollisionDispatcher(void*,ObjectCtor*);
    ObjectCtor* FUN_00cbfba0();
    ObjectCtor* ProcessAndReturnValue_00cf6da0(int);
    ObjectCtor* FUN_00d02c80(WorldCtor*);
    ObjectCtor* InitializeFields_00d0d020(WorldCtor*);
    ObjectCtor* FUN_00cf87c0(WorldCtor*);
    ObjectCtor* FUN_00d07830(WorldCtor*);
    ObjectCtor* AllocateStorage_00ca8c90(void*);
    ObjectCtor* FUN_00d0b710(WorldCtor*,int,int);
    ObjectCtor* FUN_00d0b250();
    ObjectCtor* FUN_00d0a2d0(WorldCtor*,int);
    ObjectCtor* FUN_00d08cf0(WorldCtor*,int,float);
    ObjectCtor* FUN_00cfca20(WorldCtor*);
    void FUN_00c90510();
    void hkpCollisionDispatcher_initCollisionQualityInfo(void*);
    void SetContactMgrFactory(ObjectCtor*,int);
};
struct AllocCtor { virtual void vf00(); virtual void* allocate(int); };
struct RouterCtor { int unk00,unk04,unk08,unk0c; AllocCtor* allocator; __forceinline AllocCtor& heap() {return *allocator;} };
static __forceinline void* worldAlloc(int size) {
    return ((RouterCtor*)::hkMemoryRouter_getInstance())->heap().allocate(size);
}
template<class T> static __forceinline T* allocObject(int size) {
    T* obj=(T*)worldAlloc(size);
    obj->size=(unsigned short)size;
    return obj;
}
static __forceinline void release(ObjectCtor* p) { ((::FUN_00d1df70*)p)->removeReference(); }

struct RawArrayCtor {
    ObjectCtor** data; int count; unsigned capacity;
    __forceinline void push(ObjectCtor* value) {
        RouterCtor* router=(RouterCtor*)::hkMemoryRouter_getInstance();
        if(count==(capacity&0x3fffffffu)) ::ResizeAudioStream(router->allocator,this,4);
        ObjectCtor** slot=data+count; for(int i=0;i<1;++i) slot[i]=value;
        ++count;
    }
};
struct RangeCtor { float start,end,delta,inverse; };
struct DeactivationCtor { float inverseThreshold, inverseVelocity, damping, time; float distanceSquared, radiusSquared; unsigned short distanceHalf, radiusHalf; };
struct SolverCtor {
    float unk00,unk04,unk08,unk0c;
    ::hkQuadReal unk10,unk20,unk30,unk40;
    float unk50,unk54,unk58,unk5c,unk60;
    DeactivationCtor tiers[6];
    float unk10c,unk110;
    int unk114,unk118;
    float unk11c,unk120;
    unsigned char unk124,unk125,unk126,unk127;
    float unk128;
    int unk12c;
    void UpdateFields_00c90e60(float,float);
    __forceinline DeactivationCtor& configureTier(int tierIndex,float threshold,float speed,float magnitude,float gravityScale);
};
struct ManifoldCtor { float tolerance; int count,unk08,unk0c; };
struct CollisionInputCtor {
    ObjectCtor* dispatcher;
    int unk04;
    float tolerance;
    ObjectCtor* filter;
    ObjectCtor* convexFilter;
    int unk14,unk18,unk1c;
    ::hkQuadReal offset,extent,scale;
    RangeCtor range;
    void* agents;
    int unk64;
    RangeCtor* time;
    unsigned char flag6c,flag6d;
    unsigned short unk6e;
    ManifoldCtor* manifold;
    int unk74,unk78,unk7c;
    static void* operator new(unsigned int n) { return worldAlloc(n); }
    CollisionInputCtor() { unk64=0;unk04=0; }
};

struct WorldInfoCtor {

    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ::hkQuadReal gravity;
    int querySize;
    float solverFriction;
    signed char borderBehavior;
    unsigned char postponeBorder;
    unsigned char unk2a;
    unsigned char unk2b;
    int unk2c;
    ::hkQuadReal minimum;
    ::hkQuadReal maximum;
    unsigned char borderEnabled;
    unsigned char borderAlternate;
    signed char borderMode;
    unsigned char borderFlag;
    float tolerance;
    ObjectCtor* filter;
    ObjectCtor* convexFilter;
    float config60;
    int toiQueueSize;
    float config68;
    ObjectCtor* watchdog;
    int markers;
    signed char generation;
    unsigned char quality;
    unsigned char unk76;
    unsigned char unk77;
    float solverTau;
    float solverDamping;
    int iterations;
    int microsteps;
    float damping;
    unsigned char flag8c;
    unsigned char unk8d;
    unsigned char unk8e;
    unsigned char unk8f;
    float snap;
    float snapOther;
    unsigned char weld;
    unsigned char flag99;
    unsigned char unk9a;
    unsigned char unk9b;
    float manifoldTolerance;
    int manifoldCount;
    unsigned char flagA4;
    unsigned char flagA5;
    unsigned char flagA6;
    unsigned char activate;
    float referenceDistance;
    float rotateNormal;
    int sectors;
    unsigned char threadToi;
    unsigned char unkb5;
    unsigned char unkb6;
    unsigned char unkb7;
    int toiEntries;
    int toiPairs;
    float toi0;
    float toi1;
    float toi2;
    float toi3;
    unsigned char deactivate;
    signed char simulationType;
    unsigned char wantIslands;
    unsigned char unkd3;
    int minIsland;
    unsigned char singleActions;
    unsigned char unkd9;
    unsigned char unkda;
    unsigned char unkdb;
    float simulationValue;
    unsigned char flagE0;
    unsigned char unke1;
    unsigned char unke2;
    unsigned char unke3;
};
struct WorldCtor {
    void* vtable;
    unsigned short size;
    short references;
    ObjectCtor* simulation;
    int unk0c;
    ::hkQuadReal gravity;
    ObjectCtor* fixedIsland;
    ObjectCtor* fixedBody;
    RawArrayCtor active, inactive, dirty;
    ObjectCtor* kdTree;
    ObjectCtor* watchdog;
    unsigned char assertMemory,unk55,unk56,unk57;
    ObjectCtor* broadphase;
    ObjectCtor* border;
    unsigned char autoTree,unk61,unk62,unk63;
    ObjectCtor* broadphaseDispatcher;
    ObjectCtor* phantomListener;
    ObjectCtor* entityListener;
    ObjectCtor* borderListener;
    ObjectCtor* jobs;
    CollisionInputCtor* input;
    ObjectCtor* filter;
    ObjectCtor* dispatcher;
    ObjectCtor* convexFilter;
    ObjectCtor* pending;
    int pendingCount,bodyCount,criticalCount,phantomCount;
    unsigned char blockOperations, allowOperations;
    unsigned short unk9e;
    int pendingQueues,queueCount;
    hkMultiThreadCheck threadCheck;
    unsigned char singleActions, separateIntegration;
    unsigned short unkB2;
    int minIsland;
    ObjectCtor* modifyLock;
    int locked;
    ObjectCtor* dirtyLock;
    ObjectCtor* propertyLock;
    unsigned char wantIslands,unkC9,unkCA,unkCB;
    float snapConvex,snapConcave;
    unsigned char weld,deactivate,activate,unkD7;
    float referenceDistance,rotateNormal;
    int sectors;
    unsigned char threadToi,unkE5,unkE6,unkE7;
    int toiEntries,toiPairs,simulationType;
    float toi0,toi1,toi2,toi3;
    int lastEntity,lastIsland,lastConstraint;
    RawArrayCtor phantoms,actions,entities,phantomCallbacks,constraints,deletionCallbacks,
                 islandCallbacks,postSimulation,postIntegrate,postCollide,islandIntegrate,
                 islandCollide,contacts,impulseLimits;
    ObjectCtor* violated;
    ObjectCtor* broadphaseBorder;
    ObjectCtor* callbackUtil;
    ObjectCtor* destruction;
    int unk1c8,unk1cc;
    RangeCtor time;
    SolverCtor solver;
    ::hkQuadReal minimum,maximum;
    int markers,toiQueueSize,querySize,updateSize;
    unsigned char generation,unk341,unk342,unk343;
    WorldCtor* hkpWorld_hkpWorld(WorldInfoCtor*,int);
    void hkpWorld_addEntity(ObjectCtor*,int);
};
namespace WorldCtorFactorySetup {
static void RegisterContactMgrFactories(::CFB240Dispatcher* dispatcher, WorldCtor* world)
{
    ::FUN_00cfd450* first = new ::FUN_00cfd450(world);
    ::FUN_00cfca20* second = new ::FUN_00cfca20(world);
    ::FactoryThreeC912* third = new ::FactoryThreeC912;
    dispatcher->SetContactMgrFactory(first, 1);
    dispatcher->SetContactMgrFactory(second, 2);
    dispatcher->SetContactMgrFactory(third, 3);
    ((::FUN_00d1df70*)first)->removeReference();
    ((::FUN_00d1df70*)second)->removeReference();
    ((::FUN_00d1df70*)third)->removeReference();
}
}
struct StreamCtor {
    int unk00,unk04,unk08,unk0c;
    StreamCtor* FUN_00cb1600(char*,int);
    StreamCtor* ProcessAndReturnValue_00cc01c0(const char*);
    StreamCtor* WriteInt(int);
    StreamCtor* EvaluateValue_00cc02d0(int);
    void FUN_00cc00e0();
};
struct ErrorCtor {
    virtual void f0(); virtual void f1(); virtual void f2();
    virtual int report(int,unsigned,const char*,const char*,int);
};
extern ErrorCtor* DAT_01268360;
extern unsigned char DAT_012681dc;
extern void UpdateSkyEntries(float,float);
extern void Runtime_GetD107A0RTTIAddress();
extern void hkpCollisionCallbackUtil_addCollisionCallbackUtil(WorldCtor*);
extern ObjectCtor* (__cdecl* DAT_011b37a0)(::hkQuadReal*,::hkQuadReal*,int);

extern int DAT_010c6714;
extern int DAT_010c63f0;
extern int DAT_010c63e0;
extern int DAT_010c6410;
extern int DAT_010c6400;
extern int DAT_010c646c;
extern int DAT_010c6460;
extern int DAT_010c644c;
extern int DAT_010c6440;
extern int DAT_010c6434;
extern int DAT_010c63cc;
extern int DAT_010c6378;
extern int DAT_010c6420;
extern ::hkQuadReal DAT_010c44d0;
extern float DAT_010c6840;
extern float DAT_010c6844;
extern float DAT_010c6848;
extern float DAT_010c684c;
extern float DAT_010c6850;
extern float DAT_010c6860;
extern float DAT_010c42e8;
extern float DAT_0104da4c;
extern float DAT_01013ea4;
extern float DAT_0101df44;
extern float DAT_0102d934;
extern float DAT_01017870;
extern float DAT_010313d4;
extern float DAT_010231a8;
struct BodyInfoCtor {

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
    float unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    unsigned char motionType,unkb5,unkb6,unkb7;
    int unkb8;
    int unkbc;
    void InitializePhysicsFields();
};
struct BuildConfigCtor {
    float magnitude,tolerance,config68,config60,toi0,toi1,toi2,toi3;
    unsigned short one,three,four,five;
    unsigned char multithread,quality,contacts,weld;
};
static __forceinline float length3(::hkQuadReal v) {
    ::hkQuadReal square=(::_mm_mul_ps)(v,v);
    ::hkQuadReal y=(::_mm_shuffle_ps)(square,square,0x55);
    ::hkQuadReal z=(::_mm_shuffle_ps)(square,square,0xaa);
    y=(::_mm_add_ss)(y,square);
    z=(::_mm_add_ss)(z,y);
    z=(::_mm_sqrt_ss)(z);
    float result;
    (::_mm_store_ss)(&result,z);
    return result;
}
static __forceinline void initArray(RawArrayCtor& a) {
    a.capacity=0x80000000u; a.data=0; a.count=0;
}
static __forceinline void setRange(RangeCtor& r,double a,double b) {
 r.start=a; r.end=b; float d=b-a; r.delta=d; r.inverse=d==0.0f ? 0.0f : 1.0f/d;
}

struct DispatcherCtor {
    int unk0000,unk0004,unk0008,unk000c,unk0010,unk0014,unk0018,unk001c,unk0020,unk0024,unk0028,unk002c,unk0030,unk0034,unk0038,unk003c;
    int unk0040,unk0044,unk0048,unk004c,unk0050,unk0054,unk0058,unk005c,unk0060,unk0064,unk0068,unk006c,unk0070,unk0074,unk0078,unk007c;
    int unk0080,unk0084,unk0088,unk008c,unk0090,unk0094,unk0098,unk009c,unk00a0,unk00a4,unk00a8,unk00ac,unk00b0,unk00b4,unk00b8,unk00bc;
    int unk00c0,unk00c4,unk00c8,unk00cc,unk00d0,unk00d4,unk00d8,unk00dc,unk00e0,unk00e4,unk00e8,unk00ec,unk00f0,unk00f4,unk00f8,unk00fc;
    int unk0100,unk0104,unk0108,unk010c,unk0110,unk0114,unk0118,unk011c,unk0120,unk0124,unk0128,unk012c,unk0130,unk0134,unk0138,unk013c;
    int unk0140,unk0144,unk0148,unk014c,unk0150,unk0154,unk0158,unk015c,unk0160,unk0164,unk0168,unk016c,unk0170,unk0174,unk0178,unk017c;
    int unk0180,unk0184,unk0188,unk018c,unk0190,unk0194,unk0198,unk019c,unk01a0,unk01a4,unk01a8,unk01ac,unk01b0,unk01b4,unk01b8,unk01bc;
    int unk01c0,unk01c4,unk01c8,unk01cc,unk01d0,unk01d4,unk01d8,unk01dc,unk01e0,unk01e4,unk01e8,unk01ec,unk01f0,unk01f4,unk01f8,unk01fc;
    int unk0200,unk0204,unk0208,unk020c,unk0210,unk0214,unk0218,unk021c,unk0220,unk0224,unk0228,unk022c,unk0230,unk0234,unk0238,unk023c;
    int unk0240,unk0244,unk0248,unk024c,unk0250,unk0254,unk0258,unk025c,unk0260,unk0264,unk0268,unk026c,unk0270,unk0274,unk0278,unk027c;
    int unk0280,unk0284,unk0288,unk028c,unk0290,unk0294,unk0298,unk029c,unk02a0,unk02a4,unk02a8,unk02ac,unk02b0,unk02b4,unk02b8,unk02bc;
    int unk02c0,unk02c4,unk02c8,unk02cc,unk02d0,unk02d4,unk02d8,unk02dc,unk02e0,unk02e4,unk02e8,unk02ec,unk02f0,unk02f4,unk02f8,unk02fc;
    int unk0300,unk0304,unk0308,unk030c,unk0310,unk0314,unk0318,unk031c,unk0320,unk0324,unk0328,unk032c,unk0330,unk0334,unk0338,unk033c;
    int unk0340,unk0344,unk0348,unk034c,unk0350,unk0354,unk0358,unk035c,unk0360,unk0364,unk0368,unk036c,unk0370,unk0374,unk0378,unk037c;
    int unk0380,unk0384,unk0388,unk038c,unk0390,unk0394,unk0398,unk039c,unk03a0,unk03a4,unk03a8,unk03ac,unk03b0,unk03b4,unk03b8,unk03bc;
    int unk03c0,unk03c4,unk03c8,unk03cc,unk03d0,unk03d4,unk03d8,unk03dc,unk03e0,unk03e4,unk03e8,unk03ec,unk03f0,unk03f4,unk03f8,unk03fc;
    int unk0400,unk0404,unk0408,unk040c,unk0410,unk0414,unk0418,unk041c,unk0420,unk0424,unk0428,unk042c,unk0430,unk0434,unk0438,unk043c;
    int unk0440,unk0444,unk0448,unk044c,unk0450,unk0454,unk0458,unk045c,unk0460,unk0464,unk0468,unk046c,unk0470,unk0474,unk0478,unk047c;
    int unk0480,unk0484,unk0488,unk048c,unk0490,unk0494,unk0498,unk049c,unk04a0,unk04a4,unk04a8,unk04ac,unk04b0,unk04b4,unk04b8,unk04bc;
    int unk04c0,unk04c4,unk04c8,unk04cc,unk04d0,unk04d4,unk04d8,unk04dc,unk04e0,unk04e4,unk04e8,unk04ec,unk04f0,unk04f4,unk04f8,unk04fc;
    int unk0500,unk0504,unk0508,unk050c,unk0510,unk0514,unk0518,unk051c,unk0520,unk0524,unk0528,unk052c,unk0530,unk0534,unk0538,unk053c;
    int unk0540,unk0544,unk0548,unk054c,unk0550,unk0554,unk0558,unk055c,unk0560,unk0564,unk0568,unk056c,unk0570,unk0574,unk0578,unk057c;
    int unk0580,unk0584,unk0588,unk058c,unk0590,unk0594,unk0598,unk059c,unk05a0,unk05a4,unk05a8,unk05ac,unk05b0,unk05b4,unk05b8,unk05bc;
    int unk05c0,unk05c4,unk05c8,unk05cc,unk05d0,unk05d4,unk05d8,unk05dc,unk05e0,unk05e4,unk05e8,unk05ec,unk05f0,unk05f4,unk05f8,unk05fc;
    int unk0600,unk0604,unk0608,unk060c,unk0610,unk0614,unk0618,unk061c,unk0620,unk0624,unk0628,unk062c,unk0630,unk0634,unk0638,unk063c;
    int unk0640,unk0644,unk0648,unk064c,unk0650,unk0654,unk0658,unk065c,unk0660,unk0664,unk0668,unk066c,unk0670,unk0674,unk0678,unk067c;
    int unk0680,unk0684,unk0688,unk068c,unk0690,unk0694,unk0698,unk069c,unk06a0,unk06a4,unk06a8,unk06ac,unk06b0,unk06b4,unk06b8,unk06bc;
    int unk06c0,unk06c4,unk06c8,unk06cc,unk06d0,unk06d4,unk06d8,unk06dc,unk06e0,unk06e4,unk06e8,unk06ec,unk06f0,unk06f4,unk06f8,unk06fc;
    int unk0700,unk0704,unk0708,unk070c,unk0710,unk0714,unk0718,unk071c,unk0720,unk0724,unk0728,unk072c,unk0730,unk0734,unk0738,unk073c;
    int unk0740,unk0744,unk0748,unk074c,unk0750,unk0754,unk0758,unk075c,unk0760,unk0764,unk0768,unk076c,unk0770,unk0774,unk0778,unk077c;
    int unk0780,unk0784,unk0788,unk078c,unk0790,unk0794,unk0798,unk079c,unk07a0,unk07a4,unk07a8,unk07ac,unk07b0,unk07b4,unk07b8,unk07bc;
    int unk07c0,unk07c4,unk07c8,unk07cc,unk07d0,unk07d4,unk07d8,unk07dc,unk07e0,unk07e4,unk07e8,unk07ec,unk07f0,unk07f4,unk07f8,unk07fc;
    int unk0800,unk0804,unk0808,unk080c,unk0810,unk0814,unk0818,unk081c,unk0820,unk0824,unk0828,unk082c,unk0830,unk0834,unk0838,unk083c;
    int unk0840,unk0844,unk0848,unk084c,unk0850,unk0854,unk0858,unk085c,unk0860,unk0864,unk0868,unk086c,unk0870,unk0874,unk0878,unk087c;
    int unk0880,unk0884,unk0888,unk088c,unk0890,unk0894,unk0898,unk089c,unk08a0,unk08a4,unk08a8,unk08ac,unk08b0,unk08b4,unk08b8,unk08bc;
    int unk08c0,unk08c4,unk08c8,unk08cc,unk08d0,unk08d4,unk08d8,unk08dc,unk08e0,unk08e4,unk08e8,unk08ec,unk08f0,unk08f4,unk08f8,unk08fc;
    int unk0900,unk0904,unk0908,unk090c,unk0910,unk0914,unk0918,unk091c,unk0920,unk0924,unk0928,unk092c,unk0930,unk0934,unk0938,unk093c;
    int unk0940,unk0944,unk0948,unk094c,unk0950,unk0954,unk0958,unk095c,unk0960,unk0964,unk0968,unk096c,unk0970,unk0974,unk0978,unk097c;
    int unk0980,unk0984,unk0988,unk098c,unk0990,unk0994,unk0998,unk099c,unk09a0,unk09a4,unk09a8,unk09ac,unk09b0,unk09b4,unk09b8,unk09bc;
    int unk09c0,unk09c4,unk09c8,unk09cc,unk09d0,unk09d4,unk09d8,unk09dc,unk09e0,unk09e4,unk09e8,unk09ec,unk09f0,unk09f4,unk09f8,unk09fc;
    int unk0a00,unk0a04,unk0a08,unk0a0c,unk0a10,unk0a14,unk0a18,unk0a1c,unk0a20,unk0a24,unk0a28,unk0a2c,unk0a30,unk0a34,unk0a38,unk0a3c;
    int unk0a40,unk0a44,unk0a48,unk0a4c,unk0a50,unk0a54,unk0a58,unk0a5c,unk0a60,unk0a64,unk0a68,unk0a6c,unk0a70,unk0a74,unk0a78,unk0a7c;
    int unk0a80,unk0a84,unk0a88,unk0a8c,unk0a90,unk0a94,unk0a98,unk0a9c,unk0aa0,unk0aa4,unk0aa8,unk0aac,unk0ab0,unk0ab4,unk0ab8,unk0abc;
    int unk0ac0,unk0ac4,unk0ac8,unk0acc,unk0ad0,unk0ad4,unk0ad8,unk0adc,unk0ae0,unk0ae4,unk0ae8,unk0aec,unk0af0,unk0af4,unk0af8,unk0afc;
    int unk0b00,unk0b04,unk0b08,unk0b0c,unk0b10,unk0b14,unk0b18,unk0b1c,unk0b20,unk0b24,unk0b28,unk0b2c,unk0b30,unk0b34,unk0b38,unk0b3c;
    int unk0b40,unk0b44,unk0b48,unk0b4c,unk0b50,unk0b54,unk0b58,unk0b5c,unk0b60,unk0b64,unk0b68,unk0b6c,unk0b70,unk0b74,unk0b78,unk0b7c;
    int unk0b80,unk0b84,unk0b88,unk0b8c,unk0b90,unk0b94,unk0b98,unk0b9c,unk0ba0,unk0ba4,unk0ba8,unk0bac,unk0bb0,unk0bb4,unk0bb8,unk0bbc;
    int unk0bc0,unk0bc4,unk0bc8,unk0bcc,unk0bd0,unk0bd4,unk0bd8,unk0bdc,unk0be0,unk0be4,unk0be8,unk0bec,unk0bf0,unk0bf4,unk0bf8,unk0bfc;
    int unk0c00,unk0c04,unk0c08,unk0c0c,unk0c10,unk0c14,unk0c18,unk0c1c,unk0c20,unk0c24,unk0c28,unk0c2c,unk0c30,unk0c34,unk0c38,unk0c3c;
    int unk0c40,unk0c44,unk0c48,unk0c4c,unk0c50,unk0c54,unk0c58,unk0c5c,unk0c60,unk0c64,unk0c68,unk0c6c,unk0c70,unk0c74,unk0c78,unk0c7c;
    int unk0c80,unk0c84,unk0c88,unk0c8c,unk0c90,unk0c94,unk0c98,unk0c9c,unk0ca0,unk0ca4,unk0ca8,unk0cac,unk0cb0,unk0cb4,unk0cb8,unk0cbc;
    int unk0cc0,unk0cc4,unk0cc8,unk0ccc,unk0cd0,unk0cd4,unk0cd8,unk0cdc,unk0ce0,unk0ce4,unk0ce8,unk0cec,unk0cf0,unk0cf4,unk0cf8,unk0cfc;
    int unk0d00,unk0d04,unk0d08,unk0d0c,unk0d10,unk0d14,unk0d18,unk0d1c,unk0d20,unk0d24,unk0d28,unk0d2c,unk0d30,unk0d34,unk0d38,unk0d3c;
    int unk0d40,unk0d44,unk0d48,unk0d4c,unk0d50,unk0d54,unk0d58,unk0d5c,unk0d60,unk0d64,unk0d68,unk0d6c,unk0d70,unk0d74,unk0d78,unk0d7c;
    int unk0d80,unk0d84,unk0d88,unk0d8c,unk0d90,unk0d94,unk0d98,unk0d9c,unk0da0,unk0da4,unk0da8,unk0dac,unk0db0,unk0db4,unk0db8,unk0dbc;
    int unk0dc0,unk0dc4,unk0dc8,unk0dcc,unk0dd0,unk0dd4,unk0dd8,unk0ddc,unk0de0,unk0de4,unk0de8,unk0dec,unk0df0,unk0df4,unk0df8,unk0dfc;
    int unk0e00,unk0e04,unk0e08,unk0e0c,unk0e10,unk0e14,unk0e18,unk0e1c,unk0e20,unk0e24,unk0e28,unk0e2c,unk0e30,unk0e34,unk0e38,unk0e3c;
    int unk0e40,unk0e44,unk0e48,unk0e4c,unk0e50,unk0e54,unk0e58,unk0e5c,unk0e60,unk0e64,unk0e68,unk0e6c,unk0e70,unk0e74,unk0e78,unk0e7c;
    int unk0e80,unk0e84,unk0e88,unk0e8c,unk0e90,unk0e94,unk0e98,unk0e9c,unk0ea0,unk0ea4,unk0ea8,unk0eac,unk0eb0,unk0eb4,unk0eb8,unk0ebc;
    int unk0ec0,unk0ec4,unk0ec8,unk0ecc,unk0ed0,unk0ed4,unk0ed8,unk0edc,unk0ee0,unk0ee4,unk0ee8,unk0eec,unk0ef0,unk0ef4,unk0ef8,unk0efc;
    int unk0f00,unk0f04,unk0f08,unk0f0c,unk0f10,unk0f14,unk0f18,unk0f1c,unk0f20,unk0f24,unk0f28,unk0f2c,unk0f30,unk0f34,unk0f38,unk0f3c;
    int unk0f40,unk0f44,unk0f48,unk0f4c,unk0f50,unk0f54,unk0f58,unk0f5c,unk0f60,unk0f64,unk0f68,unk0f6c,unk0f70,unk0f74,unk0f78,unk0f7c;
    int unk0f80,unk0f84,unk0f88,unk0f8c,unk0f90,unk0f94,unk0f98,unk0f9c,unk0fa0,unk0fa4,unk0fa8,unk0fac,unk0fb0,unk0fb4,unk0fb8,unk0fbc;
    int unk0fc0,unk0fc4,unk0fc8,unk0fcc,unk0fd0,unk0fd4,unk0fd8,unk0fdc,unk0fe0,unk0fe4,unk0fe8,unk0fec,unk0ff0,unk0ff4,unk0ff8,unk0ffc;
    int unk1000,unk1004,unk1008,unk100c,unk1010,unk1014,unk1018,unk101c,unk1020,unk1024,unk1028,unk102c,unk1030,unk1034,unk1038,unk103c;
    int unk1040,unk1044,unk1048,unk104c,unk1050,unk1054,unk1058,unk105c,unk1060,unk1064,unk1068,unk106c,unk1070,unk1074,unk1078,unk107c;
    int unk1080,unk1084,unk1088,unk108c,unk1090,unk1094,unk1098,unk109c,unk10a0,unk10a4,unk10a8,unk10ac,unk10b0,unk10b4,unk10b8,unk10bc;
    int unk10c0,unk10c4,unk10c8,unk10cc,unk10d0,unk10d4,unk10d8,unk10dc,unk10e0,unk10e4,unk10e8,unk10ec,unk10f0,unk10f4,unk10f8,unk10fc;
    int unk1100,unk1104,unk1108,unk110c,unk1110,unk1114,unk1118,unk111c,unk1120,unk1124,unk1128,unk112c,unk1130,unk1134,unk1138,unk113c;
    int unk1140,unk1144,unk1148,unk114c,unk1150,unk1154,unk1158,unk115c,unk1160,unk1164,unk1168,unk116c,unk1170,unk1174,unk1178,unk117c;
    int unk1180,unk1184,unk1188,unk118c,unk1190,unk1194,unk1198,unk119c,unk11a0,unk11a4,unk11a8,unk11ac,unk11b0,unk11b4,unk11b8,unk11bc;
    int unk11c0,unk11c4,unk11c8,unk11cc,unk11d0,unk11d4,unk11d8,unk11dc,unk11e0,unk11e4,unk11e8,unk11ec,unk11f0,unk11f4,unk11f8,unk11fc;
    int unk1200,unk1204,unk1208,unk120c,unk1210,unk1214,unk1218,unk121c,unk1220,unk1224,unk1228,unk122c,unk1230,unk1234,unk1238,unk123c;
    int unk1240,unk1244,unk1248,unk124c,unk1250,unk1254,unk1258,unk125c,unk1260,unk1264,unk1268,unk126c,unk1270,unk1274,unk1278,unk127c;
    int unk1280,unk1284,unk1288,unk128c,unk1290,unk1294,unk1298,unk129c,unk12a0,unk12a4,unk12a8,unk12ac,unk12b0,unk12b4,unk12b8,unk12bc;
    int unk12c0,unk12c4,unk12c8,unk12cc,unk12d0,unk12d4,unk12d8,unk12dc,unk12e0,unk12e4,unk12e8,unk12ec,unk12f0,unk12f4,unk12f8,unk12fc;
    int unk1300,unk1304,unk1308,unk130c,unk1310,unk1314,unk1318,unk131c,unk1320,unk1324,unk1328,unk132c,unk1330,unk1334,unk1338,unk133c;
    int unk1340,unk1344,unk1348,unk134c,unk1350,unk1354,unk1358,unk135c,unk1360,unk1364,unk1368,unk136c,unk1370,unk1374,unk1378,unk137c;
    int unk1380,unk1384,unk1388,unk138c,unk1390,unk1394,unk1398,unk139c,unk13a0,unk13a4,unk13a8,unk13ac,unk13b0,unk13b4,unk13b8,unk13bc;
    int unk13c0,unk13c4,unk13c8,unk13cc,unk13d0,unk13d4,unk13d8,unk13dc,unk13e0,unk13e4,unk13e8,unk13ec,unk13f0,unk13f4,unk13f8,unk13fc;
    int unk1400,unk1404,unk1408,unk140c,unk1410,unk1414,unk1418,unk141c,unk1420,unk1424,unk1428,unk142c,unk1430,unk1434,unk1438,unk143c;
    int unk1440,unk1444,unk1448,unk144c,unk1450,unk1454,unk1458,unk145c,unk1460,unk1464,unk1468,unk146c,unk1470,unk1474,unk1478,unk147c;
    int unk1480,unk1484,unk1488,unk148c,unk1490,unk1494,unk1498,unk149c,unk14a0,unk14a4,unk14a8,unk14ac,unk14b0,unk14b4,unk14b8,unk14bc;
    int unk14c0,unk14c4,unk14c8,unk14cc,unk14d0,unk14d4,unk14d8,unk14dc,unk14e0,unk14e4,unk14e8,unk14ec,unk14f0,unk14f4,unk14f8,unk14fc;
    int unk1500,unk1504,unk1508,unk150c,unk1510,unk1514,unk1518,unk151c,unk1520,unk1524,unk1528,unk152c,unk1530,unk1534,unk1538,unk153c;
    int unk1540,unk1544,unk1548,unk154c,unk1550,unk1554,unk1558,unk155c,unk1560,unk1564,unk1568,unk156c,unk1570,unk1574,unk1578,unk157c;
    int unk1580,unk1584,unk1588,unk158c,unk1590,unk1594,unk1598,unk159c,unk15a0,unk15a4,unk15a8,unk15ac,unk15b0,unk15b4,unk15b8,unk15bc;
    int unk15c0,unk15c4,unk15c8,unk15cc,unk15d0,unk15d4,unk15d8,unk15dc,unk15e0,unk15e4,unk15e8,unk15ec,unk15f0,unk15f4,unk15f8,unk15fc;
    int unk1600,unk1604,unk1608,unk160c,unk1610,unk1614,unk1618,unk161c,unk1620,unk1624,unk1628,unk162c,unk1630,unk1634,unk1638,unk163c;
    int unk1640,unk1644,unk1648,unk164c,unk1650,unk1654,unk1658,unk165c,unk1660,unk1664,unk1668,unk166c,unk1670,unk1674,unk1678,unk167c;
    int unk1680,unk1684,unk1688,unk168c,unk1690,unk1694,unk1698,unk169c,unk16a0,unk16a4,unk16a8,unk16ac,unk16b0,unk16b4,unk16b8,unk16bc;
    int unk16c0,unk16c4,unk16c8,unk16cc,unk16d0,unk16d4,unk16d8,unk16dc,unk16e0,unk16e4,unk16e8,unk16ec,unk16f0,unk16f4,unk16f8,unk16fc;
    int unk1700,unk1704,unk1708,unk170c,unk1710,unk1714,unk1718,unk171c,unk1720,unk1724,unk1728,unk172c,unk1730,unk1734,unk1738,unk173c;
    int unk1740,unk1744,unk1748,unk174c,unk1750,unk1754,unk1758,unk175c,unk1760,unk1764,unk1768,unk176c,unk1770,unk1774,unk1778,unk177c;
    int unk1780,unk1784,unk1788,unk178c,unk1790,unk1794,unk1798,unk179c,unk17a0,unk17a4,unk17a8,unk17ac,unk17b0,unk17b4,unk17b8,unk17bc;
    int unk17c0,unk17c4,unk17c8,unk17cc,unk17d0,unk17d4,unk17d8,unk17dc,unk17e0,unk17e4,unk17e8,unk17ec,unk17f0,unk17f4,unk17f8,unk17fc;
    int unk1800,unk1804,unk1808,unk180c,unk1810,unk1814,unk1818,unk181c,unk1820,unk1824,unk1828,unk182c,unk1830,unk1834,unk1838,unk183c;
    int unk1840,unk1844,unk1848,unk184c,unk1850,unk1854,unk1858,unk185c,unk1860,unk1864,unk1868,unk186c,unk1870,unk1874,unk1878,unk187c;
    int unk1880,unk1884,unk1888,unk188c,unk1890,unk1894,unk1898,unk189c,unk18a0,unk18a4,unk18a8,unk18ac,unk18b0,unk18b4,unk18b8,unk18bc;
    int unk18c0,unk18c4,unk18c8,unk18cc,unk18d0,unk18d4,unk18d8,unk18dc,unk18e0,unk18e4,unk18e8,unk18ec,unk18f0,unk18f4,unk18f8,unk18fc;
    int unk1900,unk1904,unk1908,unk190c,unk1910,unk1914,unk1918,unk191c,unk1920,unk1924,unk1928,unk192c,unk1930,unk1934,unk1938,unk193c;
    int unk1940,unk1944,unk1948,unk194c,unk1950,unk1954,unk1958,unk195c,unk1960,unk1964,unk1968,unk196c,unk1970,unk1974,unk1978,unk197c;
    int unk1980,unk1984,unk1988,unk198c,unk1990,unk1994,unk1998,unk199c,unk19a0,unk19a4,unk19a8,unk19ac,unk19b0,unk19b4,unk19b8,unk19bc;
    int unk19c0,unk19c4,unk19c8,unk19cc,unk19d0,unk19d4,unk19d8,unk19dc,unk19e0,unk19e4,unk19e8,unk19ec,unk19f0,unk19f4,unk19f8,unk19fc;
    int unk1a00,unk1a04,unk1a08,unk1a0c,unk1a10,unk1a14,unk1a18,unk1a1c,unk1a20,unk1a24,unk1a28,unk1a2c,unk1a30,unk1a34,unk1a38,unk1a3c;
    int unk1a40,unk1a44,unk1a48,unk1a4c,unk1a50,unk1a54,unk1a58,unk1a5c,unk1a60,unk1a64,unk1a68,unk1a6c,unk1a70,unk1a74,unk1a78,unk1a7c;
    int unk1a80,unk1a84,unk1a88,unk1a8c,unk1a90,unk1a94,unk1a98,unk1a9c,unk1aa0,unk1aa4,unk1aa8,unk1aac,unk1ab0,unk1ab4,unk1ab8,unk1abc;
    int unk1ac0,unk1ac4,unk1ac8,unk1acc,unk1ad0,unk1ad4,unk1ad8,unk1adc,unk1ae0,unk1ae4,unk1ae8,unk1aec,unk1af0,unk1af4,unk1af8,unk1afc;
    int unk1b00,unk1b04,unk1b08,unk1b0c,unk1b10,unk1b14,unk1b18,unk1b1c,unk1b20,unk1b24,unk1b28,unk1b2c,unk1b30,unk1b34,unk1b38,unk1b3c;
    int unk1b40,unk1b44,unk1b48,unk1b4c,unk1b50,unk1b54,unk1b58,unk1b5c,unk1b60,unk1b64,unk1b68,unk1b6c,unk1b70,unk1b74,unk1b78,unk1b7c;
    int unk1b80,unk1b84,unk1b88,unk1b8c,unk1b90,unk1b94,unk1b98,unk1b9c,unk1ba0,unk1ba4,unk1ba8,unk1bac,unk1bb0,unk1bb4,unk1bb8,unk1bbc;
    int unk1bc0,unk1bc4,unk1bc8,unk1bcc,unk1bd0,unk1bd4,unk1bd8,unk1bdc,unk1be0,unk1be4,unk1be8,unk1bec,unk1bf0,unk1bf4,unk1bf8,unk1bfc;
    int unk1c00,unk1c04,unk1c08,unk1c0c,unk1c10,unk1c14,unk1c18,unk1c1c,unk1c20,unk1c24,unk1c28,unk1c2c,unk1c30,unk1c34,unk1c38,unk1c3c;
    int unk1c40,unk1c44,unk1c48,unk1c4c,unk1c50,unk1c54,unk1c58,unk1c5c;
    int agents;
};


__forceinline DeactivationCtor& SolverCtor::configureTier(int tierIndex,float threshold,float speed,float magnitude,float gravityScale) {
        TierQuotientCtor quotient;
        quotient.denominator=speed*magnitude;
        quotient.threshold=threshold;
        float ratio=quotient.value();
        DeactivationCtor& tier=tiers[tierIndex];
        tier.damping=1.0f-(unk120*0.016f)*ratio;
        tier.inverseThreshold=1.0f/threshold;
        tier.inverseVelocity=1.0f/(threshold*gravityScale);
        tier.time=(float)speed>0.0f ? unk120*0.016f/(float)speed : DAT_010c6848;
    return tier;
}
// @fnv 0x00c95a80
// src: XBOX_PDB 0x00c95a80
WorldCtor* WorldCtor::hkpWorld_hkpWorld(WorldInfoCtor* info, int version) {
    vtable=&DAT_010c6714;
    references=1;
    int tierIndex=0;
    initArray(active); initArray(inactive); initArray(dirty);
    watchdog=0;
    threadCheck.m_uiThreadId=0xfffffff1;
    threadCheck.m_usMarkedForWrite=0x8000;
    initArray(phantoms); initArray(actions); initArray(entities);
    initArray(phantomCallbacks); initArray(constraints); initArray(deletionCallbacks);
    initArray(islandCallbacks); initArray(postSimulation); initArray(postIntegrate);
    initArray(postCollide); initArray(islandIntegrate); initArray(islandCollide);
    initArray(contacts); initArray(impulseLimits);
    lastEntity=-1; lastConstraint=-1; locked=0; assertMemory=1;
    ObjectCtor* object=(ObjectCtor*)worldAlloc(0x204);
    if(object) object->vtable=0; else object=0;
    violated=object;
    object=(ObjectCtor*)worldAlloc(0x28);
    pending=object ? object->FUN_00cf75c0(this) : 0;
    pendingQueues=0; pendingCount=0; bodyCount=0; criticalCount=0; phantomCount=0;
    blockOperations=0; allowOperations=1;
    modifyLock=0; propertyLock=0; dirtyLock=0;
    queueCount=1; destruction=0;
    minimum=info->minimum;
    maximum=info->maximum;
    markers=info->markers;
    broadphase=DAT_011b37a0(&minimum,&maximum,info->markers);
    int broadphaseQuerySize=info->querySize;
    querySize=broadphaseQuerySize;
    updateSize=broadphaseQuerySize/2;
    toiQueueSize=info->toiQueueSize;
    if(version!=0x111d4) {
        int buffer[0x80];
        StreamCtor stream;
        stream.FUN_00cb1600((char*)buffer,sizeof(buffer));
        stream.ProcessAndReturnValue_00cc01c0("** Havok libs built with version [")
              ->WriteInt(0x111d4)
              ->ProcessAndReturnValue_00cc01c0("], used with code built with [")
              ->EvaluateValue_00cc02d0(version)
              ->ProcessAndReturnValue_00cc01c0("]. **");
        if(DAT_01268360->report(3,0x53c94b42,(char*)buffer,".\\World\\hkpWorld.cpp",0xbb5))
            __debugbreak();
        stream.FUN_00cc00e0();
    }
    gravity=info->gravity;
    UpdateSkyEntries(info->snap,info->snapOther);
    snapConvex=info->snap;
    snapConcave=info->snap;
    weld=info->weld;
    activate=info->activate;
    rotateNormal=info->rotateNormal;
    sectors=info->sectors;
    threadToi=info->threadToi;
    toiEntries=info->toiEntries;
    toiPairs=info->toiPairs;
    referenceDistance=info->referenceDistance;
    solver.unk00=1.0f;
    solver.UpdateFields_00c90e60(info->solverTau,info->solverDamping);
    solver.unk60=info->solverFriction;
    solver.unk114=info->iterations;
    solver.unk120=1.0f/info->iterations;
    solver.unk118=info->microsteps;
    solver.unk128=info->damping*info->damping;
    solver.unk11c=1.0f/info->microsteps;
    solver.unk124=info->flag8c;
    solver.unk125=info->flagA4;
    solver.unk126=info->flagA5;
    solver.unk127=info->flagA6;
    solver.unk10c=0.0f; solver.unk110=0.0f;
    float magnitude=length3(info->gravity);
    if(magnitude==0.0f) magnitude=DAT_010c6860;
    float gravityScale=magnitude*0.1f;
    for(;tierIndex<6;++tierIndex) {
        float threshold; float speed;
        switch(tierIndex) {
        case 0: case 1: threshold=1.1920928955078125e-7f; speed=0.0f; break;
        case 2: threshold=0.01f; speed=DAT_010c6850; break;
        case 3: threshold=0.017f; speed=DAT_0101df44; break;
        case 4: threshold=0.02f; speed=DAT_01017870; break;
        default: threshold=0.025f; speed=DAT_010231a8; break;
        }
        DeactivationCtor& tier=solver.configureTier(tierIndex,threshold*magnitude,speed,magnitude,gravityScale);
        float distance=info->referenceDistance;
        tier.distanceSquared=distance*distance;
        tier.radiusSquared=(4.0f*distance)*(4.0f*distance);
        union { float f; int bits; } halfDistance,halfRadius;
        halfDistance.f=(2.0*distance)*(2.0*distance);
        tier.distanceHalf=(unsigned short)(halfDistance.bits>>16);
        halfRadius.f=(8.0f*distance)*(8.0f*distance);
        tier.radiusHalf=(unsigned short)(halfRadius.bits>>16);
    }
    if(info->watchdog) info->watchdog->FUN_00c90510();
    if(watchdog) release(watchdog);
    watchdog=info->watchdog;
    wantIslands=info->wantIslands;
    deactivate=info->deactivate;
    if(!wantIslands && deactivate) deactivate=wantIslands;
    singleActions=info->singleActions;
    separateIntegration=0;
    object=(ObjectCtor*)worldAlloc(0x10c);
    broadphaseDispatcher=object ? object->FUN_00cf6f90() : 0;
    object=allocObject<ObjectCtor>(0xc);
    object->references=1;
    object->vtable=(ObjectVtableCtor*)&DAT_010c63f0;
    object->unk08.raw=&DAT_010c63e0;
    phantomListener=object;
    object=allocObject<ObjectCtor>(0x10);
    entityListener=object->InitializeFields_00d107d0(this);
    object=allocObject<ObjectCtor>(0xc);
    object->references=1;
    object->vtable=(ObjectVtableCtor*)&DAT_010c6410;
    object->unk08.raw=&DAT_010c6400;
    borderListener=object;
    broadphaseDispatcher->unk28.raw=phantomListener ? &phantomListener->unk08 : 0;
    broadphaseDispatcher->unk44.raw=phantomListener ? &phantomListener->unk08 : 0;
    broadphaseDispatcher->unk48.raw=phantomListener ? &phantomListener->unk08 : 0;
    broadphaseDispatcher->unk24.raw=entityListener ? &entityListener->unk08 : 0;
    broadphaseDispatcher->unk2c.raw=borderListener ? &borderListener->unk08 : 0;
    broadphaseDispatcher->unk64.raw=borderListener ? &borderListener->unk08 : 0;
    broadphaseDispatcher->unk4c.raw=borderListener ? &borderListener->unk08 : 0;
    broadphaseDispatcher->unk68.raw=borderListener ? &borderListener->unk08 : 0;
    broadphaseDispatcher->unk6c.raw=borderListener ? &borderListener->unk08 : 0;
    ObjectCtor* agent=allocObject<ObjectCtor>(0xc)->FUN_00cfd450(this);
    dispatcher=allocObject<ObjectCtor>(0x1e50)->hkpCollisionDispatcher_hkpCollisionDispatcher((void*)&Runtime_GetD107A0RTTIAddress,agent);
    release(agent);
    if(!info->filter) {
        object=allocObject<ObjectCtor>(0x30);
        object->FUN_00cbfba0();
        object->vtable=(ObjectVtableCtor*)&DAT_010c646c;
        object->unk08.raw=&DAT_010c6460;
        object->unk0c.raw=&DAT_010c644c;
        object->unk10.raw=&DAT_010c6440;
        object->unk14.raw=&DAT_010c6434;
        object->unk20.i=1;
        filter=object;
    } else {
        filter=info->filter;
        filter->FUN_00c90510();
    }
    if(!info->convexFilter) {
        object=allocObject<ObjectCtor>(8);
        object->references=1;
        object->vtable=(ObjectVtableCtor*)&DAT_010c63cc;
        convexFilter=object;
    } else {
        convexFilter=info->convexFilter;
        convexFilter->FUN_00c90510();
    }
    CollisionInputCtor* in=new CollisionInputCtor;
    input=in;
    in->unk04=0;
    in->dispatcher=dispatcher;
    in->tolerance=info->tolerance;
    in->filter=filter;
    in->convexFilter=convexFilter;
    generation=info->generation;
    in->flag6d=info->quality;
    ManifoldCtor* manifold=(ManifoldCtor*)worldAlloc(0x10);
    if(manifold) { manifold->tolerance=DAT_01013ea4; manifold->count=20; } else manifold=0;
    in->manifold=manifold;
    manifold->tolerance=info->manifoldTolerance;
    in->manifold->count=info->manifoldCount;
    in->flag6c=info->flag99;
    in->unk14=0;
    in->agents=&((DispatcherCtor*)in->dispatcher)->agents;
    setRange(in->range,0.0f,0.0f);
    ::hkQuadReal extent=(::_mm_sub_ps)(info->maximum,info->minimum);
    float inverseX=1.0f/extent.m128_f32[0];
    float inverseY=1.0f/extent.m128_f32[1];
    float inverseZ=1.0f/extent.m128_f32[2];
    in->scale=(::_mm_mul_ps)((::_mm_setr_ps)(inverseX,inverseY,inverseZ,0.0f),(::_mm_shuffle_ps)((_mm_load_ss)(&DAT_010c6844),(_mm_load_ss)(&DAT_010c6844),0));
    in->offset=(_mm_xor_ps)(info->minimum,DAT_010c44d0);
    ::hkQuadReal scalarCoeff=(_mm_load_ss)(&DAT_010c6840);
    ::hkQuadReal splatCoeff=(::_mm_shuffle_ps)(scalarCoeff,scalarCoeff,0);
    (_mm_store_ps)(&in->extent.m128_f32[0],(::_mm_add_ps)((::_mm_mul_ps)(splatCoeff,extent),in->offset));
    ::hkQuadReal zero=(::_mm_setzero_ps)();
    in->scale=(::_mm_shuffle_ps)(in->scale,(::_mm_unpackhi_ps)(in->scale,zero),0xc4);
    ::hkQuadReal voffset=(_mm_load_ps)(&in->offset.m128_f32[0]); (_mm_store_ps)(&in->offset.m128_f32[0],(::_mm_shuffle_ps)(voffset,(::_mm_unpackhi_ps)(voffset,zero),0xc4));
    (_mm_store_ps)(&in->extent.m128_f32[0],(::_mm_shuffle_ps)(in->extent,(::_mm_unpackhi_ps)(in->extent,zero),0xc4));
    broadphase->vtable->vf70(broadphase,&in->offset,&in->extent,&in->scale);
    WorldCtorFactorySetup::RegisterContactMgrFactories((::CFB240Dispatcher*)dispatcher,this);
    if(DAT_012681dc) info->simulationType=3;
    minIsland=0;
    simulationType=info->simulationType;
    switch(simulationType) {
    case 3:
        object=(ObjectCtor*)worldAlloc(0x18);
        modifyLock=object ? object->ProcessAndReturnValue_00cf6da0(4000) : 0;
        object=(ObjectCtor*)worldAlloc(0x18);
        propertyLock=object ? object->ProcessAndReturnValue_00cf6da0(4000) : 0;
        simulation=allocObject<ObjectCtor>(0x180)->FUN_00d02c80(this);
        minIsland=info->minIsland;
        break;
    case 2: simulation=allocObject<ObjectCtor>(0x50)->InitializeFields_00d0d020(this); break;
    case 1: simulation=allocObject<ObjectCtor>(0x2c)->FUN_00cf87c0(this); break;
    }
    object=(ObjectCtor*)worldAlloc(0x18);
    dirtyLock=object ? object->ProcessAndReturnValue_00cf6da0(4000) : 0;
    simulation->unk24.f=info->simulationValue;
    magnitude=length3(gravity);
    if(magnitude==0.0f) magnitude=DAT_010c6860;
    toi0=info->toi0; toi1=info->toi1; toi2=info->toi2; toi3=info->toi3;
    BuildConfigCtor config;
    config.magnitude=magnitude;
    config.tolerance=input->tolerance;
    config.config68=info->config68;
    config.config60=info->config60;
    config.toi0=info->toi0;config.toi1=info->toi1;config.toi2=info->toi2;config.toi3=info->toi3;
    config.multithread=info->simulationType>=2;
    config.quality=info->generation==2;
    config.contacts=info->generation>=1;
    config.one=1;config.three=3;config.four=4;config.five=5;
    config.weld=info->weld;
    dispatcher->hkpCollisionDispatcher_initCollisionQualityInfo(&config);
    input->agents=&((DispatcherCtor*)dispatcher)->agents;
    fixedIsland=allocObject<ObjectCtor>(0x6c)->FUN_00d07830(this);
    fixedIsland->id20=0xffff;
    fixedIsland->flags26 &= 0xf3;
    fixedIsland->flags26 &= 0xfc;
    if(!wantIslands) {
        ObjectCtor* island=allocObject<ObjectCtor>(0x6c)->FUN_00d07830(this);
        active.push(island);
        island->id20=0;
    }
    BodyInfoCtor body;
    body.InitializePhysicsFields();
    body.unk90=0.0f;
    body.motionType=5;
    fixedBody=allocObject<ObjectCtor>(0x220)->AllocateStorage_00ca8c90(&body);
    hkpWorld_addEntity(fixedBody,1);
    release(fixedBody);
    setRange(time,0.0f,0.016666668f);
    input->time=&time;
    if(info->borderBehavior!=3) {
        ObjectCtor* pendingBorder=allocObject<ObjectCtor>(0x44);
        int behavior=info->borderBehavior;
        broadphaseBorder=pendingBorder->FUN_00d0b710(this,behavior,info->postponeBorder);
    } else broadphaseBorder=0;
    kdTree=allocObject<ObjectCtor>(0x10)->FUN_00d0b250();
    kdTree->vtable->vf0c(kdTree,this);
    callbackUtil=0;
    if(info->flagE0) hkpCollisionCallbackUtil_addCollisionCallbackUtil(this);
    if(info->borderEnabled) {
        border=allocObject<ObjectCtor>(0x24)->FUN_00d0a2d0(this,0);
        autoTree=info->borderFlag;
    } else if(info->borderAlternate) {
        ObjectCtor* alternate=allocObject<ObjectCtor>(0x70); int borderMode=info->borderMode; border=alternate->FUN_00d08cf0(this,borderMode,0.0f);
        autoTree=info->borderFlag;
    } else border=0;
    if(info->simulationType!=3) ((FUN_00cf6d20_Class*)&threadCheck)->hkMultiThreadCheck_disableChecks();
    object=(ObjectCtor*)worldAlloc(0x120);
    if(object) {
        object->unkf4.i=0;
        object->unk94.i=0;
    } else object=0;
    jobs=object;
    return this;
}

namespace ArrowHeadRatios {extern const float DAT_010c69c4=0.14999997615814208984375f; extern const float DAT_010c69c0=-0.14999997615814208984375f;}
namespace ArrowLengthLimit { extern const float DAT_0104da4c = 1.1920928955078125e-7f; }


__forceinline ::hkQuadReal arrowSplat(float t) { ::hkQuadReal q = _mm_load_ss(&t); return ::_mm_shuffle_ps(q,q,0); }
struct ArrowVectorView {
    union { ::hkQuadReal q; float f[4]; };
};
extern float DAT_01019de0;
extern float DAT_01017718;
extern float DAT_01016248;
extern ArrowVectorView DAT_010ec7f0;


__forceinline ::hkQuadReal arrowDot3(::hkQuadReal a, ::hkQuadReal b) {
    ::hkQuadReal products = ::_mm_mul_ps(a,b);
    ::hkQuadReal xy = ::_mm_add_ss(::_mm_shuffle_ps(products,products,0x55),products);
    return ::_mm_add_ss(::_mm_shuffle_ps(products,products,0xaa),xy);
}
__forceinline float arrowScalar(::hkQuadReal q) { float out; ::_mm_store_ss(&out,q); return out; }
__forceinline void arrowPerpendicular(ArrowVectorView* v, ArrowVectorView& out) {
    int least=0, side=1, other=2;
    float low=fabsf(v->f[0]);
    float y=fabsf(v->f[1]);
    float z=fabsf(v->f[2]);
    if(y<low) { side=0; least=1; low=y; }
    if(z<low) { other=least; }
    out.q=::_mm_setzero_ps();
    out.f[side]=v->f[other];
    out.f[other]=-v->f[side];
}
__forceinline void arrowCross(ArrowVectorView& out,const ArrowVectorView& left,const ArrowVectorView& right) {
    ::hkQuadReal first=::_mm_mul_ps(::_mm_shuffle_ps(left.q,left.q,0xc9),::_mm_shuffle_ps(right.q,right.q,0xd2));
    ::hkQuadReal second=::_mm_mul_ps(::_mm_shuffle_ps(left.q,left.q,0xd2),::_mm_shuffle_ps(right.q,right.q,0xc9));
    out.q=::_mm_sub_ps(first,second);
}
__forceinline void drawDebugArrow(::hkDebugDisplay* drawer, ArrowVectorView* a, ArrowVectorView* v, int a3, int a4, int a5)
{
    if (arrowScalar(arrowDot3(v->q,v->q)) < ArrowLengthLimit::DAT_0104da4c) return;
    ArrowVectorView sum;
    sum.q = ::_mm_add_ps(_mm_load_ps(a->f),v->q);
    ArrowVectorView u;
    arrowPerpendicular(v,u);
    float scaleValue0 = DAT_01019de0;
    ::hkQuadReal uq = u.q;
    ::hkQuadReal usq = ::_mm_mul_ps(uq, uq);
    ::hkQuadReal t0 = ::_mm_shuffle_ps(usq, usq, 0x55);
    ::hkQuadReal t1 = ::_mm_add_ss(t0, usq);
    ::hkQuadReal t2 = ::_mm_shuffle_ps(usq, usq, 0xaa);
    ::hkQuadReal tt = ::_mm_add_ss(t2, t1);
    ::hkQuadReal r = _mm_rsqrt_ss(tt);
    ::hkQuadReal fr = _mm_mul_ss(_mm_mul_ss(tt, r), r);
    ::hkQuadReal eq = _mm_cmpeq_ss(tt, _mm_set_ss(::DAT_01011d78));
    ::hkQuadReal factor = _mm_andnot_ps(eq, _mm_mul_ss(_mm_mul_ss(_mm_set_ss(DAT_01016248), r), _mm_sub_ss(_mm_set_ss(DAT_01017718), fr)));
    ::hkQuadReal n = ::_mm_mul_ps(uq, ::_mm_shuffle_ps(factor, factor, 0));
    ArrowVectorView unit,cross; unit.q=n; arrowCross(cross,*v,unit);
    ::hkQuadReal len = ::_mm_sqrt_ss(arrowDot3(v->q,v->q));
    ::hkQuadReal scaledN = ::_mm_mul_ps(::_mm_shuffle_ps(len, len, 0), n);
    ::hkQuadReal aq = _mm_load_ps(a->f);
    ::hkQuadReal c = arrowSplat(scaleValue0);
    ::hkQuadReal base = ::_mm_add_ps(::_mm_mul_ps(c, sum.q),
                             ::_mm_mul_ps(::_mm_sub_ps(_mm_load_ps(DAT_010ec7f0.f), c), aq));
    ArrowVectorView o1, o2, o3, o4;
    float scaleValue1 = ArrowHeadRatios::DAT_010c69c4;
    o1.q = ::_mm_add_ps(base, ::_mm_mul_ps(arrowSplat(scaleValue1), scaledN));
    float scaleValue2 = ArrowHeadRatios::DAT_010c69c0;
    o2.q = ::_mm_add_ps(base, ::_mm_mul_ps(arrowSplat(scaleValue2), scaledN));
    float scaleValue3 = ArrowHeadRatios::DAT_010c69c4;
    o3.q = ::_mm_add_ps(base, ::_mm_mul_ps(arrowSplat(scaleValue3), cross.q));
    float scaleValue4 = ArrowHeadRatios::DAT_010c69c0;
    o4.q = ::_mm_add_ps(base, ::_mm_mul_ps(arrowSplat(scaleValue4), cross.q));
    drawer->DisplayLine(*reinterpret_cast<const hkVector4_S*>(&a->q), *reinterpret_cast<const hkVector4_S*>(&sum.q), a3, a4, a5);
    drawer->DisplayLine(*reinterpret_cast<const hkVector4_S*>(&sum.q), *reinterpret_cast<const hkVector4_S*>(&o1.q), a3, a4, a5);
    drawer->DisplayLine(*reinterpret_cast<const hkVector4_S*>(&sum.q), *reinterpret_cast<const hkVector4_S*>(&o2.q), a3, a4, a5);
    drawer->DisplayLine(*reinterpret_cast<const hkVector4_S*>(&sum.q), *reinterpret_cast<const hkVector4_S*>(&o3.q), a3, a4, a5);
    drawer->DisplayLine(*reinterpret_cast<const hkVector4_S*>(&sum.q), *reinterpret_cast<const hkVector4_S*>(&o4.q), a3, a4, a5);
}
// @fnv 0x00c98880
void hkDebugDisplay::RenderLine(const ::hkVector4_S& kFrom, const ::hkVector4_S& kWorldPosition, int uiColor, int aiSoundId, int aiAllocationTag)
{
    drawDebugArrow(this, (ArrowVectorView*)&kFrom, (ArrowVectorView*)&kWorldPosition, uiColor, aiSoundId, aiAllocationTag);
}

extern float DAT_010c6850;


inline hkSimdReal operator*(const hkSimdReal& a,const hkSimdReal& b) { return makeVectorComponent((_mm_mul_ss)(a.getQuad(),b.getQuad())); }
inline hkSimdReal operator+(const hkSimdReal& a,const hkSimdReal& b) { return makeVectorComponent((::_mm_add_ss)(a.getQuad(),b.getQuad())); }
struct Vec_c99210 {
    ::hkQuadReal m_vComponents;
    void setSub4(const Vec_c99210& a, const Vec_c99210& b) { m_vComponents = (::_mm_sub_ps)(a.m_vComponents, b.m_vComponents); }
    void setColor(float x,float y,float z,float w) { m_vComponents = (::_mm_setr_ps)(x,y,z,w); }
    void set(float x, float y, float z, float w) { m_vComponents = (::_mm_setr_ps)(x, y, z, w); }
    __forceinline void setCross(const Vec_c99210& v1, const Vec_c99210& v2)
    {
        ::hkQuadReal cross0 = (::_mm_mul_ps)((::_mm_shuffle_ps)(v2.m_vComponents, v2.m_vComponents, 0xd2), (::_mm_shuffle_ps)(v1.m_vComponents, v1.m_vComponents, 0xc9));
        ::hkQuadReal cross1 = (::_mm_mul_ps)((::_mm_shuffle_ps)(v2.m_vComponents, v2.m_vComponents, 0xc9), (::_mm_shuffle_ps)(v1.m_vComponents, v1.m_vComponents, 0xd2));
        m_vComponents = (::_mm_sub_ps)(cross0, cross1);
    }
    __forceinline hkSimdReal dot3(const Vec_c99210& b) const
    {
        ::hkQuadReal x2 = (::_mm_mul_ps)(m_vComponents, b.m_vComponents);
        ::hkQuadReal xy = (::_mm_add_ss)((::_mm_shuffle_ps)(x2, x2, 0x55), x2);
        return makeVectorComponent((::_mm_add_ss)((::_mm_shuffle_ps)(x2, x2, 0xaa), xy));
    }
    __forceinline hkSimdReal inverseLength3() const
    {
        ::hkQuadReal h = (_mm_set_ss)(0.5f), t = (_mm_set_ss)(3.0f), z = (_mm_set_ss)(0.0f);
        ::hkQuadReal square = dot3(*this).m_vValue;
        ::hkQuadReal mask = (_mm_cmpeq_ss)(square,z);
        ::hkQuadReal guess = (_mm_rsqrt_ss)(square);
        ::hkQuadReal adjusted = (_mm_mul_ss)((_mm_mul_ss)(h,guess), (_mm_sub_ss)(t,(_mm_mul_ss)((_mm_mul_ss)(square,guess),guess)));
        return makeVectorComponent((_mm_andnot_ps)(mask,adjusted));
    }
    __forceinline void normalize3()
    {
        m_vComponents = (::_mm_mul_ps)(inverseLength3().broadcast(), m_vComponents);
    }
    __forceinline void mulS(float s) { m_vComponents = (::_mm_mul_ps)(m_vComponents, (_mm_set_ps1)(s)); }
    void mul4(const hkSimdReal& s) { m_vComponents = (::_mm_mul_ps)(s.broadcast(), m_vComponents); }
    void setMul4(const Vec_c99210& a, const Vec_c99210& b) { m_vComponents = (::_mm_mul_ps)(a.m_vComponents, b.m_vComponents); }
    void scaled(const hkSimdReal& f, const Vec_c99210& v) { m_vComponents = (::_mm_mul_ps)(f.broadcast(), v.m_vComponents); }
    void accumulate(const hkSimdReal& f, const Vec_c99210& v) { m_vComponents = (::_mm_add_ps)(m_vComponents, (::_mm_mul_ps)(f.broadcast(), v.m_vComponents)); }
    void add4(const Vec_c99210& a) { m_vComponents = (::_mm_add_ps)(m_vComponents, a.m_vComponents); }
};

extern const Vec_c99210 DAT_01267e30;

extern ::hkDebugDisplay* DAT_012681e0;
unsigned int __cdecl PackColorBigEndian(float r, float g, float b, float a);

// @fnv 0x00c99210
void hkDebugDisplay::displayLitTriangle(const ::hkVector4_S& vertexA, const ::hkVector4_S& vertexB, const ::hkVector4_S& vertexC, int colorValue)
{
    unsigned int color = static_cast<unsigned int>(colorValue);
    const Vec_c99210& a = reinterpret_cast<const Vec_c99210&>(vertexA);
    const Vec_c99210& b = reinterpret_cast<const Vec_c99210&>(vertexB);
    const Vec_c99210& c = reinterpret_cast<const Vec_c99210&>(vertexC);
    Vec_c99210 e1; e1.setSub4(b, a);
    Vec_c99210 e2; e2.setSub4(c, a);
    Vec_c99210 n; n.setCross(e1, e2);
    n.normalize3();

    Vec_c99210 l0; l0.set(0.5f, 2.0f, 1.0f, 0.0f);
    l0.normalize3();
    const hkSimdReal weight0 = makeScalarComponent(0.9f);
    Vec_c99210 l1; l1.set(-3.0f, -2.0f, -1.0f, 0.0f);
    l1.normalize3();
    Vec_c99210 rgb;
    rgb.set((unsigned char)(color >> 16) * (double(1.0f / 255.0f)), (unsigned char)(color >> 8) * (double(1.0f / 255.0f)), (unsigned char)color * (double(1.0f / 255.0f)), 0.0f);
    Vec_c99210 c0; c0.set(0.75f, 0.75f, 0.75f, 0.0f); c0.setMul4(c0, rgb);
    Vec_c99210 c1; c1.setColor(0.0f, 0.05f, DAT_010c6850, 0.0f); c1.setMul4(c1, rgb);
    const hkSimdReal half = makeScalarComponent(0.5f);
    l1.mul4(makeScalarComponent(0.9f));
    l0.mul4(weight0);
    Vec_c99210 res;
    res.scaled(l0.dot3(n) * half + half, c0);
    res.accumulate(l1.dot3(n) * half + half, c1);
    res.accumulate(makeScalarComponent(0.05f), rgb);
    res.m_vComponents = (_mm_min_ps)((_mm_max_ps)(res.m_vComponents, DAT_01267e30.m_vComponents), (_mm_set_ps1)(1.0f));
    float alpha = (int)(color >> 24) * (double(1.0f / 255.0f));
    unsigned int argb = PackColorBigEndian(res.m_vComponents.m128_f32[0], res.m_vComponents.m128_f32[1], res.m_vComponents.m128_f32[2], alpha);
    DAT_012681e0->DisplayTriangle(vertexA, vertexB, vertexC, argb, 0, 0);
}
