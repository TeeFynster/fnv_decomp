#define FNV64_HKVECTOR4_OWN_DEFAULT
#define FNV64_HKVECTOR4_OWN_ASSIGN
// src/staging/blk_00de0000_o2_gs_nogs_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00de0000_o2_gs_nogs_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/staging/blk_00de0000_o2_gs_nogs_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/staging/blk_00de0000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/staging/blk_00de0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkMonitorStream.h"
#include "../../include/hkMonitorStream.h"
#include "../../include/hkReferencedObject.h"
#include "../../include/hkMatrix3.h"
#include "../../include/hkVector4.h"
#include "../../include/Vec4.h"
#include <emmintrin.h>
void __cdecl finishLoadedObjecthkpCollidableBoundingVolumeData(void* p, int b);
struct FUN_00cb0c00_class
{
    void __thiscall Object_UpdateFields_00cb0c00();
};
void Object_ProcessState_00dfb490(FUN_00cb0c00_class* self);
void cleanupLoadedObjecthkaSkeletonLocalFrameOnBone(hkReferencedObject** p);
extern int DAT_010cc2fc;
extern int DAT_010df34c;
struct FUN_00dfbdf0_class
{
    void __thiscall ReturnSelf(int a);
};
void Runtime_UpdateState_00dfbdf0(void* p, int a);
extern void* DAT_010d77d8;
struct FUN_00d21de0_Class
{
    void __thiscall hkpSimpleContactConstraintAtom_hkpSimpleContactConstraintAtom(void*);
};
void __cdecl finishLoadedObjecthkpSerializedAgentNnEntry(void** p, void* a2);
extern "C" void* DAT_010305a8;
extern "C" void* DAT_010e222c;
void Object_UpdateState_00dfd0f0(void* a, int b);
struct FUN_00cb0a70_class
{
    void __thiscall ReturnSelf(int);
};
void __cdecl Object_ProcessState_00dfd770(void* arg1, void* arg2);
struct FUN_00cb0a70_cls
{
    void __thiscall ReturnSelf(char*);
};
void Object_UpdateState_00dfda10(char* b, char* a);
extern int DAT_010d3cc0;
void Object_UpdateState_00dfde30(void* p);
extern int DAT_010cc2fc;
extern int DAT_010d08f4;
struct FUN_00cb0a70_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    void __thiscall ReturnSelf(int a);
};
void Object_UpdateState_00dfef50(int* p, int a);
extern int DAT_010cc2fc;
extern int DAT_010e6834;
struct FUN_00dff0f0_class
{
    int m;
    void ReturnSelf(int);
};
void Runtime_UpdateState_00dff0f0(FUN_00dff0f0_class* p, int a);
extern int DAT_010cce28;
extern int DAT_010d07f4;
struct FUN_00cb0a70
{
    void __thiscall m_00cb0a70(int);
};
void __cdecl finishLoadedObjecthkpPhysicsSystemWithContacts(int* a, int b);
struct FUN_00dff340_Class
{
    void* m_p;
    void ReturnSelf(void* arg);
};
extern int DAT_010cc2fc;
extern int DAT_010d0944;
void __cdecl Object_UpdateFields_00dff340(void* p, void* arg);
void CopyFields(void* a, void* b);
void Object_ForwardCall_00dfbc70(FUN_00cb0c00_class* self);
extern int DAT_010df89c;
void __cdecl Runtime_UpdateState_00dfbf50(int* p);
extern int DAT_010df9f4;
void Object_UpdateFields_00dfc060(int* p);
extern int DAT_010dff44;
void __cdecl Runtime_UpdateState_00dfc130(int* p);
typedef void(__thiscall* VTable0)(void*, int);
void __cdecl Runtime_Helper_00dfc230(void** p);
void __cdecl Runtime_UpdateState_00dfc250(void** p);
extern int DAT_010e00cc;
void __cdecl Object_UpdateFields_00dfc280(int* p);
extern int DAT_010e00dc;
void Object_UpdateFields_00dfc2a0(int* p);
void __cdecl Object_InvokeVirtualMethod_00dfc380(void** p);
extern int DAT_010e04ac;
void __cdecl Runtime_UpdateState_00dfc470(int* p);
void __cdecl Object_ProcessAndTransformResult_00dfc500(void* p);
extern int DAT_010e0654;
void __cdecl Object_UpdateFields_00dfc520(int* a);
extern int DAT_0102e368;
void __cdecl Object_UpdateFields_00dfc620(int* p);
extern int DAT_010d0a64;
void __cdecl Object_UpdateFields_00dfc6c0(int* p);
void __cdecl Object_ProcessAndTransformResult_00dfc700(void* p);
extern int DAT_010d0aac;
void Runtime_UpdateState_00dfc730(int* p);
extern int DAT_010e11ec;
void __cdecl Object_UpdateFields_00dfc900(int* p);
extern int DAT_010da04c;
void __cdecl Runtime_UpdateState_00dfca90(int* p);
void __cdecl Runtime_Helper_00dfcad0(void** p);
extern int DAT_010d0b3c;
void Object_UpdateFields_00dfcb00(int* p);
extern void* DAT_010d37e4;
void __cdecl Runtime_UpdateState_00dfcbf0(void** p);
extern int DAT_010c89e4;
void __cdecl Object_UpdateFields_00dfcc60(int* p);
extern int DAT_010d0be4;
void __cdecl Runtime_UpdateState_00dfccd0(int* p);
typedef int(__thiscall* VFunc0)(void*, int);
int __cdecl Object_EvaluateValue_00dfcd10(void* self);
extern int DAT_010c91ec;
void __cdecl Object_UpdateFields_00dfcd40(int* p);
extern int DAT_010d0cd4;
void __cdecl Runtime_UpdateState_00dfce90(int* a);
struct FUN_00dfd7a0_vt
{
    virtual void v0(int);
    virtual void v1(int);
};
void __cdecl Object_InvokeVirtualMethod_00dfd7a0(FUN_00dfd7a0_vt* p);
void __cdecl Object_ForwardCall_00dfd7c0(void* arg);
struct FUN_00dfd940_vt
{
    virtual void __thiscall Object_ForwardCall_00dfd940(int);
};
void __cdecl Object_ForwardCall_00dfd940(FUN_00dfd940_vt* p);
void __cdecl Object_ForwardCall_00dfdb40(void* p);
extern int DAT_010e351c;
void __cdecl Runtime_UpdateState_00dfdb50(int* p);
extern "C" void* DAT_010e352c;
void __cdecl Runtime_UpdateState_00dfdb70(void** p);
void __cdecl Runtime_ForwardCall_00dfdf90(int a, int b);
extern int DAT_010e3e5c;
void __cdecl Runtime_UpdateState_00dfdfb0(int* p);
extern int DAT_010e5474;
void __cdecl Object_UpdateFields_00dfe340(void* p);
struct FUN_00dfe430_class
{
    virtual int __thiscall ReturnSelf(int a);
};
int __cdecl Runtime_ForwardCall_00dfe430(FUN_00dfe430_class* p);
extern int DAT_010e56d4;
void __cdecl Runtime_UpdateState_00dfe490(int* p);
extern int DAT_010e57a4;
void __cdecl Object_UpdateFields_00dfe500(int* p);
struct FUN_00dfe670_vt
{
    virtual void m_iWordAt00(int);
};
void __cdecl Runtime_ForwardCall_00dfe670(FUN_00dfe670_vt* p);
extern int DAT_010e58c8;
void __cdecl Runtime_UpdateState_00dfe690(int** p);
extern int DAT_010e59ac;
void Object_UpdateFields_00dfe700(int* p);
void __cdecl Object_InvokeVirtualMethod_00dfeaa0(void** p);
extern int DAT_010e5b68;
void __cdecl Object_UpdateFields_00dfeb60(int* p);
extern int DAT_010e5b4c;
void __cdecl Runtime_UpdateState_00dfebd0(int* p);
extern int DAT_010e5bfc;
void __cdecl Runtime_UpdateState_00dfec10(int* p);
extern int DAT_010e5d94;
void __cdecl Runtime_UpdateState_00dfec70(int* p);
extern int DAT_010e5da8;
void __cdecl Runtime_UpdateState_00dfec90(int** p);
void __cdecl Runtime_Helper_00dfecb0(int* p);
extern int DAT_010e5e9c;
void __cdecl Runtime_UpdateState_00dfecd0(int* p);
extern int DAT_010e5ff4;
void Runtime_UpdateState_00dfed10(int* p);
extern int DAT_010e60c4;
void __cdecl Object_UpdateFields_00dfee00(int* p);
extern int DAT_010e62a4;
void __cdecl Object_UpdateFields_00dfeea0(int* p);
extern int DAT_010e6394;
void __cdecl Object_UpdateFields_00dfeee0(int* p);
extern int DAT_010e66fc;
void __cdecl Runtime_UpdateState_00dfeff0(int* p);
extern int DAT_010e676c;
void __cdecl Runtime_UpdateState_00dff0d0(int* p);
extern int DAT_010cc2fc;
extern int DAT_010c8e94;
struct FUN_00cb0a70_m_helper
{
    void __thiscall m(int);
};
void __cdecl finishLoadedObjecthkpMouseSpringAction(void* a, void* b);
typedef void(__thiscall* VTableFn)(void*, int);
void __cdecl Object_ProcessState_00dff3c0(void* p);
extern int DAT_010e75cc;
void Object_UpdateFields_00dff5e0(int* p);
extern int DAT_010e75dc;
void __cdecl Object_UpdateFields_00dff600(int* p);
extern int DAT_010e75ec;
void __cdecl Object_UpdateFields_00dff620(int** p);
void __cdecl Object_InvokeVirtualMethod_00dff9e0(void** p);
typedef int(__thiscall* Vfn)(void*, int);
int __cdecl Runtime_EvaluateValue_00dffa30(void* obj);
extern int DAT_010e7c24;
void __cdecl Object_UpdateFields_00dffc80(int* p);
extern int DAT_010cc0d8;
void __cdecl Object_UpdateFields_00dffda0(int* p);
struct FUN_00dffdc0_vt
{
    virtual void m0(int);
};
void __cdecl Object_InvokeVirtualMethod_00dffdc0(FUN_00dffdc0_vt* p);
extern int DAT_010d3838;
void __cdecl Object_UpdateFields_00dffe40(int* p);
extern int DAT_010cb798;
void Object_UpdateFields_00dffee0(int* p);
struct FUN_00dfff60_vt
{
    virtual int __thiscall v0(int);
};
int __cdecl Object_InvokeVirtualMethod_00dfff60(FUN_00dfff60_vt* p);
struct FUN_00dfffc0_VT
{
    virtual void m0(int);
};
void __cdecl Object_InvokeVirtualMethod_00dfffc0(FUN_00dfffc0_VT* p);
extern void* DAT_010e80b4;
void __cdecl Object_UpdateFields_00dfffe0(void** p);
struct FUN_00de87c0_class
{
    float m_iWordAt00;
    float m_iWordAt04;
    float m_8;
    float m_iThirdValue;
    float m_10;
    float m_14;
    float m_18;
    float m_1c;
    float m_20;
    float m_24;
    float m_28;
    float m_2c;
    float m_30;
    float m_34;
    float m_38;
    void SwapFields();
};
void __cdecl Object_ProcessState_00de81a0(void* self, void* arg);
struct FUN_00d21ce0_cls
{
    void __thiscall hkpBridgeConstraintAtom_init(void*);
};
struct FUN_00de8550_t
{
    int m_iWordAt00;
    int m_iWordAt04;
    void* m_8;
};
void __cdecl hkpBridgeConstraintAtom_init_ProcessState_00de8550(FUN_00de8550_t* a, int b);
struct FUN_00de8830_Class
{
    void CopyTransposedMatrix(float* src);
};
int __cdecl _nlz(int arg);
typedef void(__thiscall* Vfn0)(void*, int);
void __cdecl Object_ProcessState_00df6460(void** p);
typedef int(__thiscall* VFunc_00dfb270)(void*, int);
int __cdecl Runtime_EvaluateValue_00dfb270(void* p);
void __cdecl CallMethodOnBothHelpers(FUN_00cb0a70_m_helper* a, int v);
typedef void(__thiscall* VFunc00dfb3f0)(void*, int);
void __cdecl Runtime_Helper_00dfb3f0(void** p);
struct FUN_00dfb450_vt
{
    virtual void m0(int);
};
void __cdecl Runtime_ForwardCall_00dfb450(FUN_00dfb450_vt* p);
struct FUN_00dfb890_vt
{
    virtual void v0(int);
};
void __cdecl Runtime_ForwardCall_00dfb890(FUN_00dfb890_vt* p);
extern int DAT_010c4dec;
void Runtime_UpdateState_00dfb9f0(int* a, int b);
typedef void(__thiscall* VTable0_00dfba70)(void*, int);
void __cdecl Runtime_Helper_00dfba70(void* p);
typedef void(__thiscall* VFn0)(void*, int);
void __cdecl Runtime_UpdateState_00dfbb30(void* p);
void __cdecl Object_ProcessState_00dfbbf0(void* p, int a);
struct S_00d49310_Lock
{
    ~S_00d49310_Lock();
};
void __cdecl Object_DestroyFields(S_00d49310_Lock* self);
void __cdecl Runtime_ProcessState_00dfbc30(void* a, void* b);
void __cdecl DispatchToHelper(void* a, int b);
struct S_00dfb720_Elem
{
    ~S_00dfb720_Elem();
};
void __cdecl Object_DestroyFields_00dfbca0(S_00dfb720_Elem* p);
typedef void(__thiscall* VTable0)(void*, int);
void __cdecl Runtime_Helper_00dfbcd0(void* p);
typedef void(__thiscall* VFunc1)(void*, int);
void __cdecl Runtime_Helper_00dfbdd0(void* p);
struct FUN_00dfc040_vt
{
    virtual void __thiscall Object_ForwardCall_00dfc040(int);
};
void __cdecl Object_ForwardCall_00dfc040(FUN_00dfc040_vt* p);
typedef void(__thiscall* V00dfc790)(void*, int);
void __cdecl Runtime_Helper_00dfc790(void** p);
void __cdecl Runtime_UpdateState_00dfc7f0(int* p);
void __cdecl Runtime_UpdateState_00dfc8d0(void** p);
typedef void(__thiscall* Vfn_00dfcb60)(void*, int);
void __cdecl Object_UpdateFields_00dfcb60(void* p);
struct FUN_00dfcc30_vt
{
    virtual void v0(int);
};
void __cdecl Runtime_ForwardCall_00dfcc30(FUN_00dfcc30_vt* p);
struct FUN_00dd0420_Class
{
    FUN_00dd0420_Class* __thiscall hkpGenericConstraintDataScheme_hkpGenericConstraintDataScheme(int);
};
void __cdecl Object_ProcessState_00dfcd80(FUN_00dd0420_Class* self, int a);
struct FUN_00dfce00_vt
{
    virtual void __thiscall v0(int);
};
void __cdecl Object_InvokeVirtualMethod_00dfce00(FUN_00dfce00_vt* p);
struct FUN_00dfcf00_vt
{
    virtual void m_iWordAt00(int);
};
void __cdecl Object_M_iWordAt00_Thunk(FUN_00dfcf00_vt* p);
struct FUN_00dfd240_vt
{
    virtual void __thiscall Object_ForwardCall_00dfd240(int);
};
void __cdecl Object_ForwardCall_00dfd240(FUN_00dfd240_vt* p);
typedef void(__thiscall* Vfn_00dfd620)(void*, int);
void __cdecl Object_ProcessState_00dfd620(void* p);
struct DFD680MeshData
{
    void ReleaseMeshArrays_00dfd680();
};
void __cdecl Runtime_ForwardCall_00dfd670(DFD680MeshData* p);
extern int DAT_010e311c;
void Object_UpdateState_00dfd7d0(int* p, int a);
void __cdecl Runtime_UpdateState_00dfda70(void* p);
void Runtime_ProcessState_00dfdad0(int* a, int b);
void __cdecl Object_ProcessState_00dfdb00(void* p);
struct FUN_00dfdb20_vt
{
    virtual void v0(int);
};
void __cdecl Object_InvokeVirtualMethod_00dfdb20(FUN_00dfdb20_vt* p);
void __cdecl CallHelperMethod(FUN_00cb0a70_m_helper* a, int b);
struct S_00e3eaa0_Elem
{
    ~S_00e3eaa0_Elem();
};
void __cdecl Runtime_ForwardCall_00dfdd50(S_00e3eaa0_Elem* p);
struct FUN_00e3f900_class
{
    int ProcessAndReturnValue_00e3f900(int);
};
void __cdecl Object_ProcessState_00dfdd60(FUN_00e3f900_class* p, int a);
void CallHelperWithInt(FUN_00cb0a70_m_helper* p, int a);
struct ArrayPair
{
    ~ArrayPair();
};
void __cdecl Object_DestroyFields_00dfe0c0(ArrayPair* p);
typedef void(__thiscall* Vfn_00dfe270)(void*, int);
void __cdecl Runtime_UpdateState_00dfe270(void* p);
void __cdecl Runtime_Helper_00dfe2b0(void* p);
extern int DAT_010cb864;
struct FUN_00ce5360_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int ComputeValue_00ce5360(int a);
};
void __cdecl finishLoadedObjecthkaSkeletonMapper(FUN_00ce5360_class* a, int b);
struct FUN_00dfe320_vt
{
    virtual void m_iWordAt00(int);
};
void __cdecl Object_M_iWordAt00_Thunk_00dfe320(FUN_00dfe320_vt* p);
extern int DAT_010e56d4;
int* Object_GetGlobalObjectAddress_00dfe4a0();
struct FUN_00dfe4e0_vt
{
    virtual void m0(int);
};
void __cdecl Object_InvokeVirtualMethod_00dfe4e0(FUN_00dfe4e0_vt* p);
void __cdecl Runtime_UpdateState_00dfe590(void* p);
extern int DAT_010e587c;
void __cdecl finishLoadedObjecthkaBoneAttachment(void* a, int b);
extern int DAT_010e5a58;
void __cdecl Object_UpdateState_00dfe990(void* a, int b);
void __cdecl Object_UpdateFields_00dfeb40(void* p);
void __cdecl Runtime_Helper_00dfebb0(void** p);
typedef void(__thiscall* Vfn0)(void*, int);
void __cdecl Runtime_Helper_00dfebf0(void* p);
struct FUN_00dfec30_vt
{
    virtual void m0(int);
};
void __cdecl Runtime_ForwardCall_00dfec30(FUN_00dfec30_vt* p);
struct FUN_00dfecf0_vt
{
    virtual void v0(int);
};
void __cdecl Runtime_ForwardCall_00dfecf0(FUN_00dfecf0_vt* p);
struct FUN_00dfede0_vt
{
    virtual void v0(int);
};
void __cdecl Object_InvokeVirtualMethod_00dfede0(FUN_00dfede0_vt* p);
typedef int(__thiscall* Vfn_00dfeec0)(void*, int);
int __cdecl Object_GetIndexedValue_00dfeec0(void* p);
struct FUN_00dfef00_vt
{
    virtual void __thiscall m0(int);
};
void __cdecl Object_InvokeVirtualMethod_00dfef00(FUN_00dfef00_vt* p);
struct FUN_00dff1d0_vt
{
    virtual void m0(int);
};
void __cdecl Runtime_ForwardCall_00dff1d0(FUN_00dff1d0_vt* p);
typedef void(__thiscall* VTable0)(void*, int);
void __cdecl Object_ProcessState_00dff300(void** p);
struct FUN_00dff370_vt
{
    virtual void __thiscall Runtime_ForwardCall_00dff370(int);
};
void __cdecl Runtime_ForwardCall_00dff370(FUN_00dff370_vt* p);
void __cdecl Object_ProcessState_00dff540(void** p);
typedef void(__thiscall* VTable0)(void*, int);
void __cdecl Object_ProcessState_00dff580(void** p);
typedef void(__thiscall* VTable0)(void*, int);
void __cdecl Object_ProcessState_00dff5c0(void* p);
extern int DAT_010cc2fc;
extern int DAT_010d0994;
struct FUN_00dff9b0_m : FUN_00cb0a70
{
    void __thiscall m(int);
};
void __cdecl Object_UpdateState_00dff9b0(FUN_00dff9b0_m* p, int a);
typedef void(__thiscall* VTblFn0)(void*, int);
void __cdecl Runtime_Helper_00dffc10(void* p);
struct FUN_00dffc60_vt
{
    virtual void m0(int);
};
void __cdecl Object_InvokeVirtualMethod_00dffc60(FUN_00dffc60_vt* p);
struct FUN_00dffd80_vt
{
    virtual void __thiscall ReturnSelf(int);
};
void __cdecl Object_ForwardCall_00dffd80(FUN_00dffd80_vt* p);
typedef void(__thiscall* VTableFn)(void*, int);
void __cdecl Object_ProcessState_00dffe20(void* p);
struct FUN_00dffe60_vt
{
    virtual void m_iWordAt00(int);
};
void __cdecl Object_M_iWordAt00_Thunk_00dffe60(FUN_00dffe60_vt* p);
typedef void(__thiscall* Vfn0)(void*, int);
void __cdecl Object_ProcessState_00dfff00(void* p);
extern int DAT_0102e388;
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
struct FUN_00de10e0_cls
{
    int m_vptr;
    unsigned short m_uSize;
    unsigned short m_u06;
    void* m_p08;
    int m_0c;
    int m_10;

    FUN_00de10e0_cls* FUN_00de10e0(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};
extern float DAT_01017d00;
struct FUN_00de3050
{
    float m_iWordAt00;
    FUN_00de3050();
};
extern int DAT_010d8214;
class FUN_00de3060
{
  public:
    void* m_00;
    unsigned short m_04;
    unsigned short m_06;
    unsigned int m_08;
    unsigned int m_0c;

    FUN_00de3060(const unsigned int* src);
};
class FUN_00de3090_cls
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    void ClearField0c();
};
struct Quad16
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
    unsigned int w;
};
class FUN_00de48a0_cls
{
  public:
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
    unsigned int m_60;
    unsigned int m_64;
    unsigned int m_68;
    unsigned int m_6c;
    Quad16 GetQuad16();
};
// CopyStatsTo
// thiscall member of a game object class: copies the 16 bytes of the
// trailing "m_stats" block (this+0x70..0x7c) into the caller's output
// buffer and returns. One stack argument (the output pointer), callee-cleared.
struct StatsBlock
{
    int m_iStat00;
    int m_iStat04;
    int m_iStat08;
    int m_iStat0c;
};
struct GameObject
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
    StatsBlock m_stats;

    void CopyStatsTo(int* __restrict pOut);
};
class FNVFloatGetter_cls
{
  public:
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
    float m_90;
    float GetField90_00de48e0();
};
struct FUN_00de48f0_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    float m_94;
    float GetField94();
};
struct CpuObject
{
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
    float value;
    float GetValue_00de4900();
};
struct FUN_00de4910_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int GetField9c();
};
// CopyVec4ToBuffer: copies the 16-byte vector stored at this+0x80 into the
// 4-int block pointed to by the stack parameter.
struct FUN_00de4920_cls
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0C;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1C;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3C;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4C;
    int m_i50;
    int m_i54;
    int m_i58;
    int m_i5C;
    int m_i60;
    int m_i64;
    int m_i68;
    int m_i6C;
    int m_i70;
    int m_i74;
    int m_i78;
    int m_i7C;
    Vec4 m_v80;
    void CopyVec4ToBuffer(int* volatile pOut);
};
struct FUN_00de4e10_cls
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

    char* GetFieldAtOffset90();
};
class FUN_00de5320_cls
{
  public:
    Vec4 GetVec4At70();
};
struct FUN_00de5350_cls
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
    float m_84;
    float GetField84();
};
class FUN_00de5360_cls
{
  public:
    void* GetFieldAtOffset80_00de5360();
};
extern void* DAT_01269ce8;
int __cdecl Runtime_EvaluateValue_00de8150();
extern int DAT_01269d18;
int* __cdecl Runtime_GetDAT01269d18Address();
extern int DAT_01269d48;
void* Runtime_GetDAT01269d48Address();
extern int g_unk01269d78;
void* __cdecl Runtime_GetUnk01269d78Address();
struct CpuOpaque;
extern CpuOpaque DAT_01269da8;
CpuOpaque* __cdecl Runtime_GetDAT01269da8Address();
extern int DAT_01269dd8;
void* __cdecl Runtime_GetDAT01269dd8Address();
extern int g_unk01269e08;
int* Runtime_GetUnk01269e08Address();
struct GlobalObject
{
    int unk00;
};
extern GlobalObject g_global;
GlobalObject* __cdecl Runtime_GetGlobalAddress();
struct CpuOpaque;
extern CpuOpaque DAT_01269e68;
CpuOpaque* __cdecl Runtime_GetDAT01269e68Address();
extern int g_unk01269e98;
void* __cdecl Runtime_GetUnk01269e98Address();
extern int g_unk01269ec8;
void* __cdecl Runtime_GetUnk01269ec8Address();
class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_01269ef8;
GlobalObjectO2_00d472a0* __cdecl Runtime_GetField01269ef8Address();
extern int DAT_01269f28;
void* __cdecl Runtime_GetDAT01269f28Address();
extern int g_unkGlobal01269f58;
void* __cdecl Runtime_GetUnkGlobal01269f58Address();
extern int DAT_01269f88;
void* __cdecl Runtime_GetDAT01269f88Address();
// FUN_00de8350 : a one-line function - getter
extern int g_target_00de8350;
void* Runtime_GetTarget00de8350Address();
extern int DAT_0126a018;
void* __cdecl Runtime_GetDAT0126a018Address();
extern int DAT_0126a048;
int* Runtime_GetDAT0126a048Address();
struct CpuOpaque;
extern CpuOpaque DAT_0126a078;
CpuOpaque* __cdecl Runtime_GetDAT0126a078Address();
extern int DAT_0126a0a8;
void* __cdecl Runtime_GetDAT0126a0a8Address();
extern int DAT_0126a0d8;
void* __cdecl Runtime_GetDAT0126a0d8Address();
extern int DAT_0126a108;
int* __cdecl Runtime_GetDAT0126a108Address();
extern int DAT_0126a138;
void* __cdecl Runtime_GetDAT0126a138Address();
extern int DAT_0126a168;
void* __cdecl Runtime_GetDAT0126a168Address();
extern int DAT_0126a198;
int* __cdecl Runtime_GetDAT0126a198Address();
extern int DAT_0126a1c8;
void* __cdecl Runtime_GetDAT0126a1c8Address();
extern FUN_00de87c0_class DAT_0126a1f8;
FUN_00de87c0_class* __cdecl Runtime_GetDAT0126a1f8Address();
// FUN_00de84f0 : returns the address of a global data object.
// Original: mov eax, offset DAT_0126a228 ; ret
extern int DAT_0126a228;
int* __cdecl Runtime_GetDAT0126a228Address();
struct CpuOpaque;
extern CpuOpaque DAT_0126a258;
CpuOpaque* __cdecl Runtime_GetDAT0126a258Address();
extern int g_0126a288;
int* __cdecl Runtime_GetField0126a288Address();
struct FUN_00de8570_cls
{
    int m_00;
    int m_04;
    int m_08;
    void __thiscall hkpBridgeConstraintAtom_init(int value);
};
void __cdecl hkpBridgeConstraintAtom_init_ProcessState_00de8570(FUN_00de8570_cls* pTarget, int nIndex);
extern int DAT_0126a378;
void* __cdecl Runtime_GetDAT0126a378Address();
extern int g_unk126a3a8;
void* __cdecl Runtime_GetUnk126a3a8Address();
class FUN_00de8780_cls
{
  public:
    float m_fValues[16];

    unsigned char* HasNoNaNOrInf(unsigned char* pResult);
};
struct JacRow
{
    float x;
    float y;
    float z;
    float w;
};
struct JacBlock
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
    JacRow rows[6];
};
void __cdecl ResetJacobianRows(unsigned char* flags, bool both, JacBlock* a, JacBlock* b);
struct DF25D0State
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    short unk10;
    unsigned char m_ucFlags;
};
struct DF25D0Owner
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
    DF25D0State* m_pkState;
};
void __cdecl hkpWorldOperationUtil_addConstraintToCriticalLockedIsland(void* pkItem, DF25D0Owner* pkOwner);
static void SetOwnerStateFlags(void* pkItem, DF25D0Owner* pkOwner, unsigned char m_ucEntryType);
void DF25D0Attach(void* pkItem, DF25D0Owner* pkOwner, unsigned char m_ucEntryType);
class FUN_00df3110
{
  public:
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
    int m_iArrayLength;

    FUN_00df3110();
};
struct FUN_00df3140_pair
{
    unsigned int m_ucLowNibble;
    unsigned int m_ucHighNibble;
};
void __stdcall CopyPairToIndex(FUN_00df3140_pair* dst, unsigned int idx, FUN_00df3140_pair* src);
struct Handler_cls
{
    void __thiscall Handle(int value);
};
void __cdecl Object_ProcessState_00df6440(Handler_cls* pHandler, int value);
extern int g_0126a430;
int* __cdecl Runtime_GetField0126a430Address();
extern int DAT_0126a478;
void* __cdecl Runtime_GetDAT0126a478Address();
extern "C" int DAT_0126a4a8;
// @fnv 0x00df64c0
// src: GUESS 0x00df64c0 (confidence: low)
extern "C" void* __cdecl Object_GetGlobalObjectAddress_00df64c0()
{
    return &DAT_0126a4a8;
}
struct FUN_00df7a60_class
{
    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0c;
    void* m_p10;
    int unk14;
    int unk18;
    void* m_p1c;

    void __thiscall hkpCollisionQueryJob_atomicIncrementAndReleaseSemaphore();
};
extern "C" __declspec(dllimport) long __stdcall InterlockedExchangeAdd(volatile long* value, long increment);
void __cdecl hkSemaphoreBusyWait_release(void* object, int value);
extern float DAT_010dbb3c;
extern float DAT_0104da48;
struct ParserContext
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, result44;
    int __thiscall ClipRangeByPlane(int, void*, float*);
};
struct FloatPair
{
    float first, second;
    int __thiscall TraverseNode(ParserContext*, int, int*, ParserContext**);
    int __thiscall hkWingedEdge_findVisibilityBoundaryEdges(ParserContext*, int, int*, ParserContext**);
};
struct CpuOpaque;
extern CpuOpaque DAT_0126a5f8;
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00dfb260();
extern int g_unk0126aa18;
int* __cdecl Object_GetGlobalObjectAddress_00dfb280();
struct FUN_00dfb2d0_class
{
    void __thiscall FUN_00dfb2d0(int a);
};
void __cdecl Object_ProcessState_00dfb290(FUN_00dfb2d0_class* p, int a);
extern int DAT_0126aac0;
int* __cdecl Object_GetGlobalObjectAddress_00dfb360();
extern int DAT_0126aaf0;
void* __cdecl Object_GetGlobalObjectAddress_00dfb380();
extern int DAT_0126abe0;
int* __cdecl Object_GetGlobalObjectAddress_00dfb3c0(void);
// Null-guarded forwarder: the first argument is an object pointer; when it
// is non-null the second argument is forwarded to a member function of that
// object (ecx = object, one stack argument).
struct FUN_00dfb3d0_cls
{
    void __thiscall hkaMeshBinding_hkaMeshBinding(int a1);
};
void __cdecl Object_ProcessState_00dfb3d0(FUN_00dfb3d0_cls* pObject, int a1);
extern unsigned char DAT_0126ac10;
void* __cdecl Object_GetGlobalObjectAddress_00dfb420();
struct FUN_00e2ebc0_cls
{
    void __thiscall Init(void* a);
};
void __cdecl Object_ProcessState_00dfb430(FUN_00e2ebc0_cls* pObject, void* pArg);
extern "C" int DAT_0126ac58;
int* __cdecl Object_GetGlobalObjectAddress_00dfb480(void);
extern int DAT_0126acd0;
int __cdecl Runtime_EvaluateValue_00dfb4d0();
extern int DAT_0126ad00;
void* __cdecl Runtime_GetDAT0126ad00Address();
extern int DAT_0126ad30;
void* __cdecl Runtime_GetDAT0126ad30Address();
extern void* DAT_0126ad60;
int __cdecl Object_ComputeValue_00dfb540();
class DFB550Object
{
  public:
    virtual ~DFB550Object();
};
void Runtime_DestroySubobject_00dfb550(DFB550Object* pkObject);
extern int DAT_0126ad90;
int* __cdecl Object_GetGlobalObjectAddress_00dfb560();
inline void* operator new(unsigned int, void* pvWhere) throw()
{
    return pvWhere;
}
struct DFB570FinishFlag
{
    int m_bFinishing;
};
class DFB570Object
{
  public:
    DFB570Object(DFB570FinishFlag flag)
    {
        if (flag.m_bFinishing)
            finishInit();
    }

    virtual void vfunc00();

    void finishInit();
};
void Runtime_AllocateStorage_00dfb570(void* p, int finishing);
extern int DAT_010ddc5c;
void* __cdecl Runtime_GetDAT010ddc5cAddress();
extern int DAT_0126add8;
int* __cdecl Object_GetGlobalObjectAddress_00dfb860();
extern unsigned char g_fnvDat0126ae08;
void* Object_GetGlobalObjectAddress_00dfb880();
// FUN_00dfb8a0 : a one-line function - getter
extern int g_target_00dfb8a0;
void* Object_GetGlobalObjectAddress_00dfb8a0();
// ResetVTable -- installs a fixed vtable on an object and, when the second
// argument is set, runs the object's update step afterwards.
extern int DAT_010de0ec;
// vtable that gets installed
struct ResetVTableObj
{
    void* m_vptr;  // virtual table pointer, offset 0
};
struct ResetVTableTarget
{
    void __thiscall m_update();
};
void __cdecl ResetVTable(ResetVTableObj* p, int bUpdate);
extern int DAT_010de0ec;
void* Runtime_GetDAT010de0ecAddress();
struct CpuOpaque;
extern CpuOpaque DAT_0126ae80;
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00dfb920();
extern int DAT_0126aeb0;
void* __cdecl Object_GetGlobalObjectAddress_00dfb940();
class CalleeObj
{
  public:
    void ComputeValue_00ce5360(void* pParam);
};
void __cdecl Runtime_ProcessState_00dfb950(CalleeObj* pFirst, void* pSecond);
extern int DAT_0126aee0;
int* __cdecl Runtime_GetDAT0126aee0Address();
struct FUN_00ce5370_cls
{
    void __thiscall UpdateState_00ce5370();
};
void __cdecl Object_ForwardCall_00dfb980(FUN_00ce5370_cls* p);
extern int DAT_0126af10;
int* __cdecl Runtime_GetDAT0126af10Address();
// FUN_00dfb9a0 : __cdecl, 13 bytes
//   mov ecx, dword ptr [esp + 4]
//   mov eax, dword ptr [ecx]
//   mov edx, dword ptr [eax]
//   push 0
//   call edx
//   ret
// Calls vtable slot 0 of the object passed in, with the argument 0.
struct FUN_00dfb9a0_cls
{
    virtual int v00(int a);
};
int __cdecl Object_InvokeVirtualMethod_00dfb9a0(FUN_00dfb9a0_cls* pObj);
extern int DAT_0126af40;
int* __cdecl Runtime_GetDAT0126af40Address(void);
extern int DAT_0126af88;
int* Object_GetGlobalObjectAddress_00dfba40();
// FUN_00dfba50: null-guarded forwarding of a second argument to a
// member function of the first (object) argument.
class FUN_00dfba50_cls
{
  public:
    void FUN_00e34800(int a1);
};
void __cdecl Object_ProcessState_00dfba50(FUN_00dfba50_cls* pObject, int a1);
extern int g_unk0126afb8;
void* __cdecl Object_GetGlobalObjectAddress_00dfbaa0();
struct CpuOpaque;
extern CpuOpaque DAT_0126b000;
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00dfbb20();
extern int DAT_0126b030;
void* __cdecl Object_GetGlobalObjectAddress_00dfbb40();
// FUN_00dfbb50 : installs the class vtable into the object and, when the
// second argument is non-zero, tail-calls the routine at FUN_00e35050 with
// the object as 'this'.
extern int DAT_010de90c;
struct FUN_00dfbb50_cls
{
    void* m_vtbl;
    void __thiscall hkaDeltaCompressedAnimation_handleEndian();
};
void __cdecl Object_UpdateState_00dfbb50(FUN_00dfbb50_cls* p, int a);
extern int DAT_010de90c;
void* __cdecl Runtime_GetDAT010de90cAddress();
extern "C" int DAT_0126b078;
// @fnv 0x00dfbc10
// src: GUESS 0x00dfbc10 (confidence: low)
extern "C" void* __cdecl Runtime_GetGlobal0126B078Address()
{
    return &DAT_0126b078;
}
struct CpuOpaque;
extern CpuOpaque DAT_0126b0a8;
CpuOpaque* __cdecl Runtime_GetDAT0126b0a8Address();
extern int DAT_0126b0d8;
int* __cdecl Object_GetGlobalObjectAddress_00dfbc60();
extern int DAT_0126b138;
void* __cdecl Object_GetGlobalObjectAddress_00dfbce0();
// InitVTable : __cdecl initializer for an object with several vtable slots.
// The first vtable is installed, a flag byte at +9 is cleared when the flag is
// set, then the second vtable is installed along with two secondary vtables
// at +0x24 and +0x1c. Finally the flag byte is set to 2 when the flag is set.
extern int DAT_010dec04;
extern int DAT_010dec3c;
extern int DAT_010c925c;
extern int DAT_010debf4;
extern int DAT_010debe4;
struct FUN_00dfbcf0_obj
{
    void* m_pVTable00;
    int m_iValue04;
    unsigned char m_bValue08;
    unsigned char m_bFlag09;
    unsigned short m_wValue0a;
    int m_iValue0c;
    int m_iValue10;
    int m_iValue14;
    int m_iValue18;
    void* m_pVTable1c;
    int m_iValue20;
    void* m_pVTable24;
};
void __cdecl InitVTable(FUN_00dfbcf0_obj* self, int flag);
extern int DAT_010dec3c;
void* __cdecl Runtime_GetDAT010dec3cAddress();
extern int DAT_0126b180;
void* __cdecl Object_GetGlobalObjectAddress_00dfbdc0();
extern int DAT_0126b1b0;
void* __cdecl Object_GetGlobalObjectAddress_00dfbde0();
extern int DAT_0126b1f8;
void* __cdecl Runtime_GetDAT0126b1f8Address();
extern unsigned char DAT_0126b228;
void* __cdecl Runtime_GetDAT0126b228Address();
extern int DAT_0126b258;
void* __cdecl Runtime_GetDAT0126b258Address();
struct CpuOpaque;
extern CpuOpaque DAT_0126b288;
CpuOpaque* __cdecl Runtime_GetDAT0126b288Address();
extern int DAT_0126b2b8;
void* __cdecl Object_GetGlobalObjectAddress_00dfbf20();
struct FUN_00dfbf30_class
{
    virtual void m0(int);
};
void __cdecl Runtime_ForwardCall_00dfbf30(void* p);
extern int DAT_0126b2e8;
int* __cdecl Object_GetGlobalObjectAddress_00dfbf40();
int* __cdecl Object_GetGlobalObjectAddress_00dfbf60();
extern int DAT_0126b330;
void* __cdecl Runtime_GetDAT0126b330Address();
// FUN_00dfc050 : a constant getter - MSVC emits mov eax, OFFSET <global> ; ret.
// The global is declared extern so the store becomes a relocation; the checker
// binds it to the original's own immediate.
extern int g_target_FUN_00dfc050;
void* __cdecl Runtime_GetTargetFUN00dfc050Address();
// FUN_00dfc070 : a one-line function - getter
extern int g_target_00dfc070;
void* Runtime_GetTarget00dfc070Address();
extern int DAT_0126b3a8;
int* __cdecl Object_GetGlobalObjectAddress_00dfc100();
struct S_00dfc110_vt
{
    virtual void m0(int);
};
void __thiscall S_00dfc110_vt::m0(int)
{}
void __cdecl Runtime_ForwardCall_00dfc110(void* p);
extern int g_0126b3d8;
int* __cdecl Object_GetGlobalObjectAddress_00dfc120();
extern int DAT_010dff44;
int* __cdecl Object_GetGlobalObjectAddress_00dfc140();
extern unsigned char DAT_0126b420;
void* __cdecl Object_GetGlobalObjectAddress_00dfc220();
extern char DAT_0126b498;
char* __cdecl Object_GetGlobalObjectAddress_00dfc260();
extern int DAT_010e00cc;
void* Runtime_GetDAT010e00ccAddress();
extern int DAT_010e00dc;
int* __cdecl Runtime_GetDAT010e00dcAddress();
// FUN_00dfc360: cdecl no-arg getter returning the address of a global.
extern int DAT_0126b528;
int* __cdecl Object_GetGlobalObjectAddress_00dfc360();
extern int g_unk0126b4e0;
void* __cdecl Runtime_GetUnk0126b4e0Address();
extern void* DAT_0126b558;
void* Runtime_GetDAT0126b558Address();
struct FUN_00e05c20_class
{
    void __thiscall ReleaseSectorAndSubtrackArrays();
};
void __cdecl Object_ForwardCall_00dfc3a0(FUN_00e05c20_class* p);
struct FUN_00dfc3b0_target
{
    void Run();
};
void __cdecl Runtime_ForwardCall_00dfc3b0(FUN_00dfc3b0_target* pTarget);
// FUN_00dfc440 : a one-line function - getter
extern int g_target_00dfc440;
void* Object_GetGlobalObjectAddress_00dfc440();
class VirtualDispatchObj
{
  public:
    virtual void Invoke0(int arg);
};
void __cdecl Runtime_ForwardCall_00dfc450(VirtualDispatchObj* p);
extern void* DAT_0126b588;
int __cdecl Object_ComputeValue_00dfc460();
extern int DAT_010e04ac;
void* __cdecl Object_GetGlobalObjectAddress_00dfc480();
extern int g_unk0126b678;
void* __cdecl Runtime_GetUnk0126b678Address();
extern int DAT_0126b648;
int* __cdecl Runtime_GetDAT0126b648Address();
extern int DAT_0126b600;
int* __cdecl Runtime_GetDAT0126b600Address();
extern int DAT_010e0654;
int* __cdecl Runtime_GetDAT010e0654Address();
extern int DAT_0126b6a8;
int* __cdecl Runtime_GetDAT0126b6a8Address(void);
// FUN_00dfc5b0 : a one-line function - getter
extern int g_target_00dfc5b0;
void* Runtime_GetTarget00dfc5b0Address();
extern int DAT_0126b708;
int* __cdecl Runtime_GetDAT0126b708Address();
extern int DAT_0126b738;
void* __cdecl Runtime_GetDAT0126b738Address();
struct FUN_00dfc600_vt
{
    virtual void __thiscall m0(int);
};
void __cdecl Object_InvokeVirtualMethod_00dfc600(FUN_00dfc600_vt* p);
extern unsigned char DAT_0126b768;
void* __cdecl Runtime_GetDAT0126b768Address();
extern int DAT_0102e368;
int* __cdecl Runtime_GetDAT0102e368Address();
extern int DAT_0126b7b0;
int* __cdecl Object_GetGlobalObjectAddress_00dfc660();
// FUN_00dfc680 : a one-line function - getter
extern int g_target_00dfc680;
void* Object_GetGlobalObjectAddress_00dfc680();
struct FUN_00dfc690_vt
{
    virtual void m0(int);
};
void __cdecl Runtime_ForwardCall_00dfc690(FUN_00dfc690_vt* p);
extern int DAT_0126b810;
void* __cdecl Object_GetGlobalObjectAddress_00dfc6a0();
extern int DAT_010d0a64;
int* __cdecl Runtime_GetDAT010d0a64Address();
extern char DAT_0126b858;
void* Runtime_GetDAT0126b858Address();
class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_0126b888;
GlobalObjectO2_00d472a0* __cdecl Runtime_GetField0126b888Address();
extern int DAT_010d0aac;
int* __cdecl Object_GetGlobalObjectAddress_00dfc740();
extern int g_unk0126b8d0;
int* __cdecl Object_GetGlobalObjectAddress_00dfc760();
extern int g_0126b900;
int* __cdecl Object_GetGlobalObjectAddress_00dfc7c0();
extern int DAT_0126b948;
int* __cdecl Object_GetGlobalObjectAddress_00dfc7e0();
extern int DAT_0126b978;
void* __cdecl Object_GetGlobalObjectAddress_00dfc800();
class DFC810Object
{
  public:
    void Process(void* pvData);
};
void __cdecl Runtime_ProcessState_00dfc810(DFC810Object* pkObject, void* pvData);
class SpawnedBase
{
  public:
    virtual ~SpawnedBase();
    virtual void Tick();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    SpawnedBase(int a);
};
class SpawnedMid
{
  public:
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    SpawnedMid()
    {
        *(volatile int*)&m_8c = 0;
        *(volatile int*)&m_90 = 0;
        *(volatile int*)&m_94 = (int)0x80000000;
        *(volatile int*)&m_98 = 0;
        *(volatile int*)&m_9c = 0;
        *(volatile int*)&m_a0 = (int)0x80000000;
    }
};
class FUN_00dfc850 : public SpawnedBase, public SpawnedMid
{
  public:
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    int m_d0;
    int m_d4;
    int m_d8;
    int m_dc;
    int m_e0;
    int m_e4;
    int m_e8;
    int m_ec;
    int m_f0;
    int m_f4;
    int m_f8;
    int m_fc;
    int m_100;
    int m_104;
    int m_108;
    int m_10c;
    int m_110;
    int m_114;
    int m_118;
    int m_11c;
    int m_120;
    int m_124;
    int m_128;
    int m_12c;
    int m_130;
    int m_134;
    int m_138;
    int m_13c;
    int m_140;
    int m_144;
    int m_148;
    int m_14c;
    int m_150;
    int m_154;
    int m_158;
    int m_15c;
    int m_160;
    int m_164;
    int m_168;
    virtual ~FUN_00dfc850();
    FUN_00dfc850(int a1);
};
extern int DAT_0126b9c0;
int* __cdecl Object_GetGlobalObjectAddress_00dfc8c0();
extern int g_unk0126b9f0;
int* __cdecl Object_GetGlobalObjectAddress_00dfc8e0();
extern int DAT_010e11ec;
int* __cdecl Runtime_GetDAT010e11ecAddress();
extern int g_0126ba38;
int* __cdecl Runtime_GetField0126ba38Address();
struct FUN_00dfc940_class
{
    virtual void m0(int);
};
void __cdecl Object_InvokeVirtualMethod_00dfc940(FUN_00dfc940_class* p);
extern int DAT_0126ba68;
void* __cdecl Runtime_GetDAT0126ba68Address();
extern int DAT_010d0af4;
struct S_00dfc970_Flag
{
    char v;
    S_00dfc970_Flag(char c)
    {
        v = c;
    }
    S_00dfc970_Flag(const S_00dfc970_Flag& o)
    {
        v = o.v;
    }
};
struct S_00dfc970_Obj
{
    void* vptr;
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
    short unk98;
    char unk9a;
    void hkpRagdollLimitsData_setConeLimitStabilization(S_00dfc970_Flag f);
};
void __cdecl finishLoadedObjecthkpRagdollLimitsData(S_00dfc970_Obj* p, int flag);
extern int DAT_010d0af4;
int* __cdecl Object_GetGlobalObjectAddress_00dfc9a0();
extern int DAT_0126bab0;
int* __cdecl Object_GetGlobalObjectAddress_00dfc9c0();
class DFC9D0Object
{
  public:
    virtual ~DFC9D0Object();
};
void Runtime_DestroySubobject_00dfc9d0(DFC9D0Object* pkObject);
extern int DAT_0126bae0;
int* __cdecl Object_GetGlobalObjectAddress_00dfc9e0();
extern int DAT_010cb71c;
void* __cdecl Runtime_GetDAT010cb71cAddress();
extern int DAT_0126bb28;
void* __cdecl Runtime_GetDAT0126bb28Address();
class DFCA60Object
{
  public:
    virtual ~DFCA60Object();
};
void Object_InvokeVirtualMethod_00dfca60(DFCA60Object* pkObject);
extern char g_unk0126bb58;
void* __cdecl Runtime_GetUnk0126bb58Address();
extern int DAT_010da04c;
int* __cdecl Object_GetGlobalObjectAddress_00dfcaa0();
extern int DAT_0126bba0;
int* __cdecl Object_GetGlobalObjectAddress_00dfcac0();
extern void* DAT_0126bbd0;
int __cdecl Object_ComputeValue_00dfcae0();
extern int DAT_010d0b3c;
int* __cdecl Runtime_GetDAT010d0b3cAddress();
extern int DAT_0126bc18;
void* __cdecl Runtime_GetDAT0126bc18Address();
extern int DAT_0126bc48;
int* __cdecl Runtime_GetDAT0126bc48Address();
extern int DAT_0126bc90;
int* __cdecl Runtime_GetDAT0126bc90Address();
// Stand-in for the object whose virtual slot 0 is invoked with argument 0.
struct FUN_00dfcbc0_vt
{
    virtual void m0(int a);
};
void __cdecl Object_InvokeVirtualMethod_00dfcbc0(FUN_00dfcbc0_vt* pObject);
extern int DAT_0126bcc0;
void* __cdecl Runtime_GetDAT0126bcc0Address();
extern void* DAT_010d37e4;
void** __cdecl Object_GetGlobalObjectAddress_00dfcc00();
// FUN_00dfcc20 : a one-line function - getter
extern int g_target_00dfcc20;
void* Object_GetGlobalObjectAddress_00dfcc20();
struct S_00dfcc40_Obj
{
    int unk00;
};
extern S_00dfcc40_Obj DAT_0126bd38;
S_00dfcc40_Obj* __cdecl Object_GetGlobalObjectAddress_00dfcc40();
// FUN_00dfcc70 : a one-line function - getter
extern int g_target_00dfcc70;
void* Runtime_GetTarget00dfcc70Address();
extern int DAT_0126bd80;
int* __cdecl Runtime_GetDAT0126bd80Address();
// Forwarder: takes the object pointer, calls its first virtual slot with a
// literal 0 argument (push 0; call through the vtable entry).
struct VtblForwarder
{
    virtual int v0(int);
};
int __cdecl Object_InvokeVirtualMethod_00dfcca0(VtblForwarder* p);
// FUN_00dfccb0 : a one-line function - getter
extern int g_target_00dfccb0;
void* Runtime_GetTarget00dfccb0Address();
extern int DAT_010d0be4;
void* __cdecl Object_GetGlobalObjectAddress_00dfcce0();
extern int DAT_0126bdf8;
void* __cdecl Object_GetGlobalObjectAddress_00dfcd00();
struct CpuOpaque;
extern CpuOpaque DAT_0126be28;
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00dfcd20();
extern int DAT_010c91ec;
int* Runtime_GetDAT010c91ecAddress();
extern int DAT_0126be70;
int* __cdecl Runtime_GetDAT0126be70Address();
extern int DAT_0126bea0;
void* __cdecl Object_GetGlobalObjectAddress_00dfcda0();
struct FUN_00dfcdb0_target
{
    void Run();
};
void __cdecl Runtime_ForwardCall_00dfcdb0(FUN_00dfcdb0_target* pTarget);
extern char DAT_0126bed0;
void* __cdecl Runtime_GetDAT0126bed0Address();
struct DFD5E0
{
    void __thiscall FUN_00d53df0(void* p);
};
void __cdecl Object_ProcessState_00dfcde0(void* a, void* b);
extern int DAT_0126bf00;
void* __cdecl Runtime_GetDAT0126bf00Address();
extern int DAT_0126bf48;
int* __cdecl Runtime_GetDAT0126bf48Address();
extern int DAT_0126bf78;
void* __cdecl Runtime_GetDAT0126bf78Address();
extern int DAT_010d0cd4;
int* __cdecl Object_GetGlobalObjectAddress_00dfcea0();
struct CpuOpaque;
extern CpuOpaque DAT_0126bfc0;
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00dfcec0();
extern int DAT_0126bff0;
void* __cdecl Runtime_GetDAT0126bff0Address();
extern int DAT_0126c020;
void* __cdecl Runtime_GetDAT0126c020Address();
struct FUN_00dfcf20_cls
{
    void __thiscall InitializeVtables(int a);
};
void __cdecl Object_ProcessState_00dfcf20(FUN_00dfcf20_cls* p, int a);
extern "C" void* DAT_010305a8;
extern "C" void* DAT_010c6fb0;
extern "C" void* DAT_010cc364;
extern "C" void* DAT_010cc344;
extern "C" void* DAT_010e2144;
extern "C" void* DAT_010e2124;
struct FUN_00dfcf60_cls
{
    void* m_vptr00;
    int m_04;
    int m_08;
    int m_0c;
    void* m_vptr10;
    char m_14;
    unsigned char m_15;
    unsigned char m_16;
    unsigned char m_17;

    FUN_00dfcf60_cls* InitializeVtables(int flag);
};
extern int DAT_0126c068;
void* Object_GetGlobalObjectAddress_00dfd0c0();
struct FUN_00dfd0d0_cls
{
    virtual void Call(int a);
};
void Runtime_ForwardCall_00dfd0d0(FUN_00dfd0d0_cls* pTarget);
extern int DAT_0126c098;
void* Object_GetGlobalObjectAddress_00dfd0e0();
extern "C" void* DAT_010e222c;
void* __cdecl Object_GetGlobalObjectAddress_00dfd120();
extern unsigned char DAT_0126c0e0;
unsigned char* __cdecl Runtime_GetDAT0126c0e0Address();
void __cdecl Object_ProcessAndTransformResult_00dfd1c0(void* p);
extern int DAT_0126c110;
void* __cdecl Runtime_GetDAT0126c110Address();
// FUN_00dfd1e0: null-guarded forwarding of a second argument to a
// member function of the first (object) argument.
class FUN_00dfd1e0_cls
{
  public:
    void Forward(int a1);
};
void __cdecl Object_ProcessState_00dfd1e0(FUN_00dfd1e0_cls* pObject, int a1);
extern int DAT_0126c158;
int* __cdecl Runtime_GetDAT0126c158Address();
// FUN_00dfd250 : a one-line function - getter
extern int g_target_00dfd250;
void* Runtime_GetTarget00dfd250Address();
struct S_00dfd260_Foo
{
    void __thiscall FUN_00d59830(int arg);
};
void __cdecl Object_ProcessState_00dfd260(S_00dfd260_Foo* self, int arg);
extern int DAT_0126c1d0;
int* __cdecl Object_GetGlobalObjectAddress_00dfd2a0();
extern int DAT_0126c200;
int* __cdecl Object_GetGlobalObjectAddress_00dfd2c0();
class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_0126c230;
GlobalObjectO2_00d472a0* __cdecl Runtime_GetField0126c230Address();
struct FUN_00dfd2e0_Class
{
    virtual void VF00(int value);
};
void __cdecl Object_InvokeVirtualMethod_00dfd2e0(FUN_00dfd2e0_Class* param_1);
// FUN_00dfd2f0 : a one-line function - getter
extern int g_target_00dfd2f0;
void* Runtime_GetTarget00dfd2f0Address();
struct FUN_00e3dbd0_class
{
    void __thiscall FUN_00e3dbd0(int value);
};
void __cdecl Object_ProcessState_00dfd300(FUN_00e3dbd0_class* object, int value);
struct FUN_00dfd380_Class
{
    void __thiscall ReleaseFourArrays();
};
void __cdecl Object_ForwardCall_00dfd360(int* param_1);
struct FnvCpu_FUN_00dfd370_CpuTarget
{
    void ReleaseThreeArrays();
};
void __cdecl Runtime_ForwardCall_00dfd370(FnvCpu_FUN_00dfd370_CpuTarget* target);
// FUN_00dfd4e0 : a one-line function - getter
extern int g_target_00dfd4e0;
void* Object_GetGlobalObjectAddress_00dfd4e0();
extern int DAT_0126c2d8;
void* __cdecl Object_GetGlobalObjectAddress_00dfd500();
struct CpuOpaque;
extern CpuOpaque DAT_0126c308;
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00dfd540();
extern int DAT_0126c338;
int* __cdecl Object_GetGlobalObjectAddress_00dfd560();
// FUN_00dfd570: null-guarded forwarder. The first argument (an object
// pointer) is loaded and tested; when it is not null the second argument
// is passed on to a non-virtual member function of that object.
class FUN_00dfd570_cls
{
  public:
    void ReturnSelf(int a1);
};
void __cdecl Object_ProcessState_00dfd570(FUN_00dfd570_cls* pObject, int a1);
extern int DAT_0126c368;
int* __cdecl Runtime_GetDAT0126c368Address();
extern int DAT_0126c398;
int __cdecl Runtime_EvaluateValue_00dfd5f0();
class FUN_00dfd600_cls
{
  public:
    void Callee(unsigned int value);
};
void __cdecl Object_ProcessState_00dfd600(FUN_00dfd600_cls* target, unsigned int value);
// FUN_00dfd650 : a one-line function - getter
extern int g_target_00dfd650;
void* Runtime_GetTarget00dfd650Address();
extern int DAT_0126c410;
int* __cdecl Runtime_GetDAT0126c410Address();
extern int DAT_0126c440;
void* __cdecl Runtime_GetDAT0126c440Address();
extern int DAT_0126c488;
void* __cdecl Runtime_GetDAT0126c488Address();
extern int DAT_0126c4b8;
int* __cdecl Runtime_GetDAT0126c4b8Address();
extern int DAT_010e33dc;
struct FUN_00dfd990_class
{
    void* vtable;
    int field04;
    int field08;
    int field0c;
    int field10;
    FUN_00cb0a70_class field14;
};
void __cdecl Runtime_SetVtableAndProcessState_00dfd990(FUN_00dfd990_class* object, int value);
extern int DAT_0126c500;
void* Object_GetGlobalObjectAddress_00dfda40();
struct S_00e3f510_Foo
{
    void __thiscall SetVptr_00e3f510(int);
};
void __cdecl Object_ProcessState_00dfda50(void* p, int a);
extern int DAT_0126c530;
int* __cdecl Object_GetGlobalObjectAddress_00dfdaa0();
struct AdjacentObjects
{
    FUN_00cb0c00_class first;
    __declspec(align(4)) FUN_00cb0c00_class second;
};
void __cdecl Runtime_ProcessState_00dfdab0(AdjacentObjects* objects);
extern int DAT_0126c578;
void* __cdecl Runtime_GetDAT0126c578Address();
// FUN_00dfdb10 : a one-line function - getter
extern int g_target_00dfdb10;
void* Runtime_GetTarget00dfdb10Address();
extern int DAT_0126c5f0;
void* __cdecl Runtime_GetDAT0126c5f0Address();
extern int DAT_010e351c;
int* __cdecl Object_GetGlobalObjectAddress_00dfdb60();
extern "C" void* DAT_010e352c;
void* __cdecl Object_GetGlobalObjectAddress_00dfdb80();
extern int DAT_0126c638;
int* Object_GetGlobalObjectAddress_00dfdd20();
extern int DAT_0126c668;
int __cdecl Object_ComputeValue_00dfdd80();
extern int DAT_0126c698;
int* __cdecl Object_GetGlobalObjectAddress_00dfddc0();
extern int DAT_0126c6c8;
void* Object_GetGlobalObjectAddress_00dfdde0();
struct CpuOpaque;
extern CpuOpaque DAT_0126c6f8;
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00dfde00();
struct FUN_00dfde10_vtable
{
    virtual void __thiscall slot0(int value)
    {}
};
void __cdecl Runtime_ForwardCall_00dfde10(void* p);
extern int DAT_0126c728;
int __cdecl Object_ComputeValue_00dfde20();
extern int DAT_010d3cc0;
int* __cdecl Runtime_GetDAT010d3cc0Address();
extern char DAT_0126c770;
char* __cdecl Runtime_GetDAT0126c770Address(void);
extern int DAT_0126c7a0;
void* __cdecl Runtime_GetDAT0126c7a0Address();
struct CpuOpaque;
extern CpuOpaque DAT_0126c7d0;
CpuOpaque* __cdecl Runtime_GetDAT0126c7d0Address();
// FUN_00dfdec0: null-guarded forwarding of a second argument to a
// member function of the first (object) argument.
class FUN_00dfdec0_cls
{
  public:
    void hkMonitorStreamStringMap_StringMap_StringMap(int a1);
};
void __cdecl Object_ProcessState_00dfdec0(FUN_00dfdec0_cls* pObject, int a1);
extern unsigned char DAT_0126c800;
void* __cdecl Object_GetGlobalObjectAddress_00dfdee0();
// FUN_00dfdef0: null-guarded forwarding of a second argument to a
// member function of the first (object) argument.
class FUN_00dfdef0_cls
{
  public:
    void GetSelf_00e0f700(int a1);
};
void __cdecl Object_ProcessState_00dfdef0(FUN_00dfdef0_cls* pObject, int a1);
extern int g_unk0126c830;
void* __cdecl Runtime_GetUnk0126c830Address();
extern int DAT_0126c860;
int* __cdecl Runtime_GetDAT0126c860Address();
struct CpuOpaque;
extern CpuOpaque DAT_0126c890;
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00dfdf40();
class DFDF50Object
{
  public:
    virtual ~DFDF50Object();
};
void __cdecl Runtime_DestroySubobject_00dfdf50(DFDF50Object* pkObject);
extern int DAT_0126c8c0;
int* __cdecl Object_GetGlobalObjectAddress_00dfdf60();
extern int DAT_010e3e5c;
int* __cdecl Object_GetGlobalObjectAddress_00dfdfc0();
struct FUN_00ddc870_class
{
    void __thiscall ProcessEntries_00ddc870();
};
void __cdecl Object_ForwardCall_00dfdfd0(FUN_00ddc870_class* self);
extern int DAT_0126c908;
int* __cdecl Runtime_GetDAT0126c908Address();
extern int DAT_0126c938;
void* __cdecl Object_GetGlobalObjectAddress_00dfe0a0();
extern int DAT_0126c968;
void* __cdecl Object_GetGlobalObjectAddress_00dfe0e0();
extern int DAT_0126c998;
void* __cdecl Object_GetGlobalObjectAddress_00dfe100();
// FUN_00dfe120 : a one-line function - getter
extern int g_target_00dfe120;
void* Object_GetGlobalObjectAddress_00dfe120();
extern int DAT_0126c9f8;
void* __cdecl Object_GetGlobalObjectAddress_00dfe140();
// FUN_00dfe160 : a one-line function - getter
extern int g_target_00dfe160;
void* Object_GetGlobalObjectAddress_00dfe160();
extern int DAT_0126ca58;
int* __cdecl Object_GetGlobalObjectAddress_00dfe180();
extern int DAT_0126ca88;
int __cdecl Object_ComputeValue_00dfe1a0();
extern int DAT_0126cab8;
int* __cdecl Object_GetGlobalObjectAddress_00dfe1c0();
extern int DAT_0126cae8;
void* __cdecl Object_GetGlobalObjectAddress_00dfe1e0();
extern int DAT_0126cb18;
void* __cdecl Runtime_GetDAT0126cb18Address();
// FUN_00dfe250: null-guarded forwarding of a second argument to a
// non-virtual member function of the first (object) argument.
class FUN_00dfe250_cls
{
  public:
    void Forward(int a1);
};
void __cdecl Object_ProcessState_00dfe250(FUN_00dfe250_cls* pObject, int a1);
// FUN_00dfe2a0: cdecl, returns the address of a global object.
extern char g_unk0126cb48;
void* __cdecl Object_GetGlobalObjectAddress_00dfe2a0();
extern void* DAT_0126cb90;
int __cdecl Object_ComputeValue_00dfe2c0();
// FUN_00dfe330 : a one-line function - getter
extern int g_target_00dfe330;
void* Runtime_GetTarget00dfe330Address();
extern int DAT_010e5474;
unsigned int __cdecl Runtime_EvaluateValue_00dfe350();
// Helper object whose virtual-like member performs the work.
struct FUN_00cb0a70_obj
{
    void __thiscall m_00cb0a70(int value);
};
void __cdecl Object_ProcessState_00dfe410(FUN_00cb0a70_obj* pObject, int value);
// FUN_00dfe460 : a one-line function - getter
extern int g_target_00dfe460;
void* Object_GetGlobalObjectAddress_00dfe460();
void __cdecl Runtime_ForwardCall_00dfe470(FUN_00dfe430_class* p);
extern int DAT_0126cc68;
void* __cdecl Object_GetGlobalObjectAddress_00dfe480();
// FUN_00dfe4f0: cdecl, returns the address of a global object.
extern char g_unk0126ccb0;
void* __cdecl Runtime_GetUnk0126ccb0Address();
extern int DAT_010e57a4;
int* Runtime_GetDAT010e57a4Address();
// FUN_00dfe5a0: cdecl, returns the address of a global object.
extern char g_unk0126ccf8;
void* __cdecl Object_GetGlobalObjectAddress_00dfe5a0();
struct CpuOpaque;
extern CpuOpaque DAT_0126cd40;
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00dfe680();
extern int DAT_010e58c8;
int* __cdecl Object_GetGlobalObjectAddress_00dfe6a0();
struct FUN_00dfe6e0_Class
{
    virtual void vf00(int value);
};
void __cdecl Object_InvokeVirtualMethod_00dfe6e0(FUN_00dfe6e0_Class* param_1);
extern unsigned char DAT_0126cd88;
void* __cdecl Runtime_GetDAT0126cd88Address();
extern int DAT_010e59ac;
int __cdecl Runtime_EvaluateValue_00dfe710();
struct FUN_00dfe970_class
{
    virtual void __thiscall m_iWordAt00(int);
};
void __cdecl Runtime_ForwardCall_00dfe970(FUN_00dfe970_class* p);
extern int g_unk0126cdd0;
void* __cdecl Object_GetGlobalObjectAddress_00dfe980();
extern int DAT_0126ce18;
int __cdecl Runtime_EvaluateValue_00dfeab0();
extern int DAT_010dec04;
extern int DAT_010e5ae4;
extern int DAT_010c925c;
extern int DAT_010debf4;
extern int DAT_010debe4;
void __cdecl InitObjectVtables(int* p, int b);
extern int DAT_010e5ae4;
int* Object_GetGlobalObjectAddress_00dfeb00();
extern int DAT_0126ce60;
int* __cdecl Runtime_GetDAT0126ce60Address();
extern int DAT_010e5b68;
int* __cdecl Runtime_GetDAT010e5b68Address();
extern int DAT_0126cea8;
int* __cdecl Object_GetGlobalObjectAddress_00dfebc0();
extern int DAT_010e5b4c;
int* __cdecl Object_GetGlobalObjectAddress_00dfebe0();
extern int DAT_0126cef0;
int* __cdecl Object_GetGlobalObjectAddress_00dfec00();
extern int DAT_010e5bfc;
int* __cdecl Object_GetGlobalObjectAddress_00dfec20();
// FUN_00dfec40 : a constant getter - MSVC emits mov eax, OFFSET <global> ; ret.
// The global is declared extern so the store becomes a relocation; the checker
// binds it to the original's own immediate.
extern int g_target_FUN_00dfec40;
void* __cdecl Object_GetGlobalObjectAddress_00dfec40();
class DFEC50Object
{
  public:
    virtual ~DFEC50Object();
};
void __cdecl Runtime_DestroySubobject_00dfec50(DFEC50Object* pkObject);
// FUN_00dfec60 : a one-line function - getter
extern int g_target_00dfec60;
void* Object_GetGlobalObjectAddress_00dfec60();
// FUN_00dfec80: cdecl, returns the address of a global data symbol.
extern int DAT_010e5d94;
int* __cdecl Object_GetGlobalObjectAddress_00dfec80();
extern int DAT_010e5da8;
void* __cdecl Object_GetGlobalObjectAddress_00dfeca0();
extern int DAT_0126cfc8;
void* __cdecl Object_GetGlobalObjectAddress_00dfecc0();
extern int DAT_010e5e9c;
int* __cdecl Object_GetGlobalObjectAddress_00dfece0();
// FUN_00dfed00 : a one-line function - getter
extern int g_target_00dfed00;
void* Object_GetGlobalObjectAddress_00dfed00();
int* Object_GetGlobalObjectAddress_00dfed20();
extern int DAT_0126d058;
int __cdecl Runtime_EvaluateValue_00dfedf0();
extern int DAT_010e60c4;
int* __cdecl Runtime_GetDAT010e60c4Address();
extern int DAT_0126d0a0;
int* __cdecl Runtime_GetDAT0126d0a0Address();
extern int DAT_010e62a4;
void* __cdecl Runtime_GetDAT010e62a4Address();
extern int DAT_0126d0e8;
int __cdecl Runtime_EvaluateValue_00dfeed0();
extern int DAT_010e6394;
int* __cdecl Runtime_GetDAT010e6394Address();
extern int DAT_0126d130;
void* __cdecl Runtime_GetDAT0126d130Address();
extern int DAT_010debf4;
int __cdecl Object_ComputeValue_00dfef40();
class DFEF80Object
{
  public:
    virtual ~DFEF80Object();
};
void Object_InvokeVirtualMethod_00dfef80(DFEF80Object* pkObject);
// FUN_00dfefc0: returns the address of the global object at DAT_0126d190.
extern int DAT_0126d190;
int* Object_GetGlobalObjectAddress_00dfefc0();
// FUN_00dfefd0 : cdecl, 13 bytes
// Calls slot 0 of the object's vtable with the argument 0 and returns the result.
struct FUN_00dfefd0_cls
{
    virtual int v00(int a);
};
int __cdecl Runtime_ForwardCall_00dfefd0(FUN_00dfefd0_cls* pObj);
extern int DAT_0126d1d8;
void* __cdecl Object_GetGlobalObjectAddress_00dfefe0();
extern int DAT_010e66fc;
int* __cdecl Object_GetGlobalObjectAddress_00dff000();
struct FUN_00dff0b0_class
{
    virtual void m0(int);
};
void __cdecl Runtime_ForwardCall_00dff0b0(FUN_00dff0b0_class* p);
extern int DAT_0126d220;
void* __cdecl Object_GetGlobalObjectAddress_00dff0c0();
extern int DAT_010e676c;
int* __cdecl Object_GetGlobalObjectAddress_00dff0e0();
struct FUN_00dff120_Class
{
    virtual void vf00(int value);
};
void __cdecl Object_InvokeVirtualMethod_00dff120(FUN_00dff120_Class* param_1);
// Getter returning the address of a global object.
extern int DAT_0126d268;
int* __cdecl Object_GetGlobalObjectAddress_00dff160();
// Null-guarded forwarder: the first argument is an object pointer; when it is
// non-null the second argument is passed to a member function of that object.
struct FUN_00dff170_cls
{
    void __thiscall FUN_00e45010(int a1);
};
void __cdecl Object_ProcessState_00dff170(FUN_00dff170_cls* pObject, int a1);
struct FUN_00dff190_cls
{
    virtual void m_v00(int arg);
};
void __cdecl Object_ForwardCall_00dff190(FUN_00dff190_cls* pObject);
extern int DAT_0126d298;
int __cdecl Object_ComputeValue_00dff1c0();
extern int DAT_0126d2f8;
int __cdecl Object_ComputeValue_00dff1e0();
struct FUN_00dff250_class
{
    virtual void m0(int);
};
void __cdecl Runtime_ForwardCall_00dff250(FUN_00dff250_class* p);
extern int DAT_0126d328;
void* __cdecl Object_GetGlobalObjectAddress_00dff260();
struct DFF2E0FinishFlag
{
    int m_bFinishing;
};
class DFF2E0Object
{
  public:
    DFF2E0Object(DFF2E0FinishFlag flag);

    static void* operator new(unsigned int, void* p)
    {
        return p;
    }
};
void Object_ConstructInPlace(void* p, int finishing);
extern int DAT_0126d370;
int* __cdecl Runtime_GetDAT0126d370Address();
extern int DAT_0126d3d0;
int __cdecl Runtime_EvaluateValue_00dff3b0();
extern int DAT_0126d418;
int* __cdecl Runtime_GetDAT0126d418Address();
struct CpuOpaque;
extern CpuOpaque DAT_010e6dec;
CpuOpaque* __cdecl Runtime_GetDAT010e6decAddress();
struct FUN_00e46300_class
{
    void __thiscall FUN_00e46300(int);
};
void __cdecl Object_ProcessState_00dff4c0(FUN_00e46300_class* p, int a);
struct DFF4E0Object
{
    virtual void Destroy(bool bFree);
};
void Object_Destroy_Thunk(DFF4E0Object* pkObject);
extern unsigned char DAT_0126d448;
void* __cdecl Runtime_GetDAT0126d448Address();
struct DFF520FinishFlag
{
    int m_bFinishing;
};
class DFF520Object
{
  public:
    DFF520Object(DFF520FinishFlag flag);

    static void* operator new(unsigned int, void* p)
    {
        return p;
    }
};
void Object_ConstructInPlace_00dff520(void* p, int finishing);
extern int DAT_0126d490;
int __cdecl Runtime_EvaluateValue_00dff570();
struct CpuOpaque;
extern CpuOpaque DAT_0126d4d8;
CpuOpaque* __cdecl Runtime_GetDAT0126d4d8Address();
struct CpuOpaque;
extern CpuOpaque DAT_0126d508;
CpuOpaque* __cdecl Runtime_GetDAT0126d508Address();
extern int DAT_0126d550;
void* __cdecl Runtime_GetDAT0126d550Address();
extern int DAT_010e75cc;
int* __cdecl Runtime_GetDAT010e75ccAddress();
extern int DAT_010e75dc;
int* __cdecl Runtime_GetDAT010e75dcAddress();
extern int DAT_010e75ec;
int __cdecl Runtime_EvaluateValue_00dff630();
// Helper class: the object's first virtual slot takes a single int argument.
class FUN_00dff870_cls
{
  public:
    virtual int v0(int a) = 0;
};
int __cdecl Runtime_ForwardCall_00dff870(FUN_00dff870_cls* p);
extern int DAT_0126d5c8;
int* __cdecl Object_GetGlobalObjectAddress_00dff880();
// FUN_00dff890: forwards a second argument to a method of the first argument
// when that pointer is non-null.
struct FUN_00dff890_cls
{
    void __thiscall InitializeRecordPointers(int a);
};
void __cdecl Object_ProcessState_00dff890(FUN_00dff890_cls* pObject, int aValue);
extern "C" char DAT_010c3b80;
extern "C" char DAT_010c3b98;
extern "C" char DAT_010c3bac;
extern "C" char DAT_010c3b8c;
extern "C" char str_0102f13c[];
extern "C" char DAT_010e7700;
extern "C" char DAT_010e76f4;
extern "C" char DAT_010e76e0;
extern "C" char DAT_010e76d4;
extern "C" char DAT_010e76c8;
extern "C" char DAT_010e76ac;
struct FNVRecordPointers
{
    void* volatile m00;
    void* m04;
    void* volatile m08;
    void* volatile m0c;
    void* volatile m10;
    void* volatile m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    void* volatile m30;
    FNVRecordPointers* __thiscall InitializeRecordPointers(int unused);
};
extern int DAT_0126d610;
void* __cdecl Object_GetGlobalObjectAddress_00dffa20();
extern int g_unk0126d658;
void* __cdecl Object_GetGlobalObjectAddress_00dffa40();
// FUN_00dffa50: forwards a value to a helper on the passed-in object
// when that object is present.
struct FUN_00dffa50_cls
{
    void __thiscall FUN_00dffa90(int value);
};
void __cdecl Object_ProcessState_00dffa50(FUN_00dffa50_cls* pObject, int value);
struct DFFA90FinishFlag
{
    int m_bFinishing;
};
class DFFA90ListenerA
{
  public:
    DFFA90ListenerA(DFFA90FinishFlag)
    {}
    virtual ~DFFA90ListenerA();
};
class DFFA90ListenerB
{
  public:
    DFFA90ListenerB(DFFA90FinishFlag)
    {}
    virtual ~DFFA90ListenerB();
};
class DFFA90ListenerC
{
  public:
    DFFA90ListenerC(DFFA90FinishFlag)
    {}
    virtual ~DFFA90ListenerC();
};
class DFFA90ListenerD
{
  public:
    DFFA90ListenerD(DFFA90FinishFlag)
    {}
    virtual ~DFFA90ListenerD();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};
class DFFA90ListenerE
{
  public:
    DFFA90ListenerE(DFFA90FinishFlag)
    {}
    virtual ~DFFA90ListenerE();
};
class FUN_00dffa90 : public hkReferencedObject,
                     public DFFA90ListenerA,
                     public DFFA90ListenerB,
                     public DFFA90ListenerC,
                     public DFFA90ListenerD,
                     public DFFA90ListenerE
{
  public:
    FUN_00dffa90(DFFA90FinishFlag flag);
    virtual ~FUN_00dffa90();
};
class FUN_00dffba0_cls
{
  public:
    virtual void v0(int arg);
};
void __cdecl Object_InvokeVirtualMethod_00dffba0(FUN_00dffba0_cls* p);
extern int DAT_0126d688;
int* __cdecl Runtime_GetDAT0126d688Address();
extern int DAT_0126d6e8;
void* __cdecl Runtime_GetDAT0126d6e8Address();
struct CpuOpaque;
extern CpuOpaque DAT_0126d718;
CpuOpaque* __cdecl Runtime_GetDAT0126d718Address();
extern int DAT_010e7c24;
int* __cdecl Runtime_GetDAT010e7c24Address();
extern int DAT_0126d760;
void* Runtime_GetDAT0126d760Address();
extern int DAT_010cc0d8;
int* __cdecl Runtime_GetDAT010cc0d8Address();
// FUN_00dffdd0 : a one-line function - getter
extern int g_target_00dffdd0;
void* Runtime_GetTarget00dffdd0Address();
extern int DAT_010c6e34;
void* Runtime_GetDAT010c6e34Address();
extern int DAT_0126d7f0;
void* __cdecl Runtime_GetDAT0126d7f0Address();
extern int DAT_010d3838;
void* __cdecl Runtime_GetDAT010d3838Address();
extern char g_unk0126d838;
void* __cdecl Runtime_GetUnk0126d838Address();
extern void* DAT_010c59f4;
extern void* DAT_010c6d54;
void __cdecl Object_UpdateFields_00dffe80(void* p, int b);
// Helper class: the object's first virtual slot takes a single int argument.
class FUN_00dffec0_cls
{
  public:
    virtual int v0(int a) = 0;
};
int __cdecl Object_InvokeVirtualMethod_00dffec0(FUN_00dffec0_cls* p);
extern int DAT_0126d880;
void* __cdecl Runtime_GetDAT0126d880Address();
extern int DAT_010cb798;
int* __cdecl Runtime_GetDAT010cb798Address();
extern int DAT_0126d8c8;
int __cdecl Runtime_EvaluateValue_00dfff10();
extern int DAT_010da004;
struct SpawnedSub
{
    int unk00;
    int unk04;
    unsigned int unk08;
    void __thiscall Notify(unsigned int value);
};
struct SpawnedObject
{
    int* vptr;
    int unk04;
    int unk08;
    SpawnedSub m_0c;
};
void __cdecl InitSpawnedObject(SpawnedObject* p, int flag);
extern int DAT_010da004;
int* __cdecl Runtime_GetDAT010da004Address();
extern int DAT_0126d910;
int* __cdecl Runtime_GetDAT0126d910Address();
struct S_00dfff80_Foo
{
    void __thiscall FUN_00cdf760(int a);
};
void __cdecl CallFooMethodIfNotNull(S_00dfff80_Foo* p, int a);
// FUN_00dfffd0 : a one-line function - getter
extern int g_target_00dfffd0;
void* Runtime_GetTarget00dfffd0Address();
extern void* DAT_010e80b4;
void** __cdecl Runtime_GetDAT010e80b4Address();
class Base_de1210 : public hkReferencedObject
{
  public:
    int m_iUnk08;
    hkMatrix3 m_kRotationMatrix;
    hkVector4 m_kVec40;
    int m_iUnk50;

    Base_de1210()
    {
        m_iUnk08 = 0;
        m_iUnk50 = 3;
        m_kRotationMatrix.setIdentity();
        m_kVec40.m_vComponents = _mm_setzero_ps();
    }
    virtual void v00();
};
class FUN_00de1210 : public Base_de1210
{
  public:
    hkVector4 m_kVec60;
    hkVector4 m_kVec70;

    FUN_00de1210();
    virtual void v00();
};
class DE1FC0Transform : public hkReferencedObject
{
  public:
    DE1FC0Transform()
    {
        m_ulUserData = 0;
        m_type = 2;
        m_rotation.setIdentity();
        m_vTranslation.m_vComponents = _mm_setzero_ps();
    }

    int m_ulUserData;
    int unk0C;
    hkMatrix3 m_rotation;
    hkVector4 m_vTranslation;
    int m_type;
    int unk54;
    int unk58;
    int unk5C;
};
class FUN_00de1fc0 : public DE1FC0Transform
{
  public:
    FUN_00de1fc0();
    virtual void vfunc01();

    hkVector4 m_extra;
};
// Return a copy of the stored 4-float value.
class DE5300Object
{
  public:
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
    hkVector4 m_kValue;

    hkVector4 GetValue() const;
};
struct DE5450Transform
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    hkVector4 m_vTranslation;

    void setIdentity()
    {
        m_kColumn0.m_vComponents = _mm_setzero_ps();
        m_kColumn1.m_vComponents = _mm_setzero_ps();
        m_kColumn2.m_vComponents = _mm_setzero_ps();
        m_kColumn0.x = 1.0f;
        m_kColumn1.y = 1.0f;
        m_kColumn2.z = 1.0f;
        m_vTranslation.m_vComponents = _mm_setzero_ps();
    }
};
class DE5450Shape : public hkReferencedObject
{
  public:
    DE5450Shape() : m_ulUserData(0), m_type(4)
    {
        m_kMotionTransform.setIdentity();
    }

    int m_ulUserData;
    int unk0C;
    DE5450Transform m_kMotionTransform;
    int m_type;
    int unk54;
    int unk58;
    int unk5C;
};
class FUN_00de5450 : public DE5450Shape
{
  public:
    FUN_00de5450();
    virtual void unk00();

    hkVector4 m_vecA;
    hkVector4 m_vecB;
    int m_uiItemCount;
    float m_valueA;
    float m_valueB;
};
struct Matrix64
{
    hkVector4 a, b, c, d;
};
struct Input
{
    int count;
    float a, b;
    hkVector4 vector;
    unsigned* values;
    void* source;
    Matrix64* matrices;
    float scale;
    unsigned flags;
};
struct Header
{
    union
    {
        float epsilon;
        unsigned char type;
    };
    unsigned short count, pad06;
    unsigned flags, unk0c, size;
    float scale, a, b;
};
void Object_ProcessEntries_00df19e0(int, hkVector4*, Matrix64*, void*, void*, void*, void*, void*, int);
void WriteInputHeader(Input* input, void*, Header** cursor);
extern "C" const __m128 DAT_011b9490;
// @fnv 0x00df2740
// src: GUESS 0x00df2740 (confidence: low)
extern "C" __m128 __cdecl Object_GetDAT_011b9490_00df2740()
{
    return DAT_011b9490;
}
// which resets the runtime caches and re-links the embedded collidable to its owner.
struct DF6500FinishFlag
{
    int m_bFinishing;
};
struct DF6500Collidable
{
    int m_pCollisionShape;
    char m_type;
    signed char m_iOwnerOffset;
    short m_pad06;
    int m_unk08;
    void SetOwnerPointer(void* owner)
    {
        m_iOwnerOffset = (signed char)((unsigned int)owner - (unsigned int)this);
    }
};
struct DF6500Object
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    int m_unk10;
    DF6500Collidable m_kCollidable;
    int m_unk20;
    int m_unk24;
    int m_unk28;
    int m_unk2c;
    int m_unk30;
    int m_unk34;
    int m_unk38;
    int m_unk3c;
    short m_unk40;
    short m_unk42;
    int m_unk44;
    int m_unk48;

    DF6500Object(DF6500FinishFlag flag)
    {
        if (flag.m_bFinishing)
        {
            m_unk40 = 0;
            m_unk42 = 0;
            m_unk44 = 0;
            m_unk48 = 0;
            m_unk30 = 0;
            m_unk20 = 1;
            m_kCollidable.SetOwnerPointer(this);
        }
    }
};
void finishLoadedObjecthkpCollidable(void* p, int finishing);
struct BDFCA00FinishFlag
{
    int m_bFinishing;
};
struct BDFCA00UpdateFlag
{
    BDFCA00UpdateFlag(char cValue) : m_cValue(cValue)
    {}
    BDFCA00UpdateFlag(const BDFCA00UpdateFlag& kOther) : m_cValue(kOther.m_cValue)
    {}

    char m_cValue;
};
class BDFCA00Object
{
  public:
    __forceinline BDFCA00Object(BDFCA00FinishFlag kFlag)
    {
        if (kFlag.m_bFinishing && m_bModifierActive)
        {
            Recalculate(BDFCA00UpdateFlag(1));
        }
    }
    virtual ~BDFCA00Object();

    void Recalculate(BDFCA00UpdateFlag kFlag);

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
    short unk114;
    bool m_bModifierActive;
};
void __cdecl finishLoadedObjecthkpRagdollConstraintData(void* pvObject, int iFinishing);
struct FnvCpu_FUN_00de1150_CpuObject
{
    char* EvaluateValue_00de1150();
};
struct FnvCpu_FUN_00de1160_CpuObject
{
    char* ComputeValue_00de1160();
};
struct FnvCpu_FUN_00de4de0_CpuObject
{
    char* ComputeValue_00de4de0();
};
void* __fastcall Object_EvaluateValue_00de4df0(char* self, int);
void __cdecl nullsub_124();
void __cdecl nullsub_125();
void __cdecl nullsub_126(void);
void nullsub_127();
void nullsub_129();
void __cdecl nullsub_131();
void nullsub_133();
void __cdecl nullsub_135();
void __cdecl nullsub_137();
void __cdecl nullsub_139();
void __cdecl nullsub_141();
void __cdecl nullsub_143();
void __cdecl nullsub_145();
void __cdecl nullsub_147();
void __cdecl nullsub_149();
void __cdecl nullsub_151();
void __cdecl nullsub_153();
void __cdecl nullsub_155(void);
void __cdecl nullsub_157();
void __cdecl nullsub_159();
void nullsub_161();
void nullsub_163();
void __cdecl nullsub_165();
void nullsub_167();
void nullsub_169();
void __cdecl nullsub_171();
void nullsub_173();
void __cdecl nullsub_175();
void __cdecl nullsub_177();
void nullsub_179();
void nullsub_181();
void nullsub_123();
void nullsub_128();
void nullsub_130();
void nullsub_134();
void nullsub_136();
void __cdecl nullsub_138();
void nullsub_140();
void __cdecl nullsub_142();
void __cdecl nullsub_144(void);
void __cdecl nullsub_146();
void __cdecl nullsub_148();
void __cdecl nullsub_150();
void __cdecl nullsub_152();
void __cdecl nullsub_154();
void __cdecl nullsub_156();
void nullsub_158();
void __cdecl nullsub_160();
void nullsub_162();
void nullsub_164();
void nullsub_166();
void __cdecl nullsub_168();
void nullsub_170();
void __cdecl nullsub_172();
void nullsub_174();
void __cdecl nullsub_176();
void nullsub_178();
void nullsub_180();
void __cdecl nullsub_132();
void __cdecl nullsub_182();
void __cdecl nullsub_183();
struct stub_cls
{
    int unk00;
};
static void Object_SetUnk00_00df30c0(stub_cls* self, int v);
extern "C" int stub_val(void);
void stub_caller(stub_cls* self);
struct DF30D0Pair
{
    unsigned int m_ucLowNibble;
    unsigned int m_ucHighNibble;
};
static void CopyPairAtIndex(DF30D0Pair* dst, unsigned int idx, const DF30D0Pair* src);
void DF30D0Caller(DF30D0Pair* dst, unsigned int idx, const DF30D0Pair* src);
void hkKdTreeBuilderSparseWriter_flush();
void nullsub_184();
void __cdecl nullsub_185();
struct FUN_00df7210_Inner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int m14;
};
struct FUN_00df7210_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00df7210_Inner* m10;
    char* __thiscall hkCpuWorldLinearCastCollector_hasHit(char* out);
};
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern unsigned long DAT_0126835c;
extern char DAT_010dba3c[];
extern char DAT_010c41f8[];
struct TimerCommandKd
{
    const char* m_name;
    unsigned int m_uiCommandId;
    int unk08;
};
static inline void TimerCommandKdWrite(const char* name)
{
    hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (s->m_end.m_storage < s->m_capacityMinus16.m_storage)
    {
        TimerCommandKd* h = (TimerCommandKd*)s->m_end.m_storage;
        h->m_name = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        h->m_uiCommandId = t;
        s->m_end.m_storage = (char*)(h + 1);
    }
}
struct KdPair
{
    int m_kPointA;
    int m_kPointB;
};
struct KdJob
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int m_20;
    int m_24;
    int m_28;
    int* m_2c;
    int m_30;
    int m_34;
    KdPair m_38;
};
struct KdQueue
{
    int FinishJob(const KdJob* a, const KdJob* b, int flag);
};
void __cdecl MixChannels(KdPair* p, int a2, int a3, int a4, int a5, int a6, int* out);
int __cdecl FinishJobWithPair(KdQueue* queue, KdJob* job);
struct FnvCpu_FUN_00df8920_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    float value;
    float GetValue_00df8920();
};
void __cdecl Runtime_DoNothing_00df9870();
void Runtime_DoNothing_00df9b10();
void __cdecl nullsub_186();
void nullsub_187();
void nullsub_188();
void nullsub_189();
void __cdecl nullsub_190();
void __cdecl nullsub_191();
void __cdecl nullsub_192(void);
void __cdecl nullsub_193();
void nullsub_194();
void __cdecl nullsub_195();
void __cdecl nullsub_196();
void __cdecl nullsub_197();
void nullsub_198(void);
void __cdecl nullsub_199();
void __cdecl nullsub_200();
void nullsub_201();
void __cdecl nullsub_202();
void __cdecl nullsub_203();
void __cdecl nullsub_204();
void __cdecl nullsub_205();
void nullsub_206();
void nullsub_207();
void nullsub_209();
void __cdecl nullsub_208();
void __cdecl nullsub_210();
void nullsub_211();
void nullsub_212();
void nullsub_214();
void __cdecl nullsub_213();
void nullsub_215();
void __cdecl nullsub_216();
void __cdecl nullsub_217(void);
void __cdecl nullsub_218();
void __cdecl nullsub_219();
void nullsub_220();
void nullsub_221();
void __cdecl nullsub_222();
void nullsub_223();
void __cdecl nullsub_224();
void nullsub_225();
void __cdecl nullsub_226();
void nullsub_228();
void nullsub_227();
void __cdecl nullsub_230();
void __cdecl nullsub_229(void);
void __cdecl nullsub_231();
void __cdecl nullsub_232();
void __cdecl nullsub_234();
void __cdecl nullsub_233();
void nullsub_236();
void nullsub_235();
void __cdecl nullsub_238();
void nullsub_237();
void __cdecl nullsub_240();
void __cdecl nullsub_239();
void __cdecl nullsub_242();
void nullsub_241();
void __cdecl nullsub_243(void);
void nullsub_245();
void __cdecl nullsub_244();
void __cdecl nullsub_247();
void __cdecl nullsub_246();
void __cdecl nullsub_249();
void nullsub_248();
void __cdecl nullsub_251();
void __cdecl nullsub_250();
void nullsub_252();
void nullsub_253();
void nullsub_255();
void nullsub_254();
void __cdecl nullsub_257();
void nullsub_256();
void __cdecl nullsub_258();
void __cdecl nullsub_259();
void __cdecl nullsub_260();
void __cdecl nullsub_261();
void __cdecl nullsub_263();
void __cdecl nullsub_262();
void nullsub_264();
void __cdecl nullsub_265();
void __cdecl nullsub_267();
void __cdecl nullsub_266();
void __cdecl nullsub_268();
void __cdecl nullsub_269();
void __cdecl nullsub_270();
void __cdecl nullsub_271();
void nullsub_272();
void nullsub_274();
void nullsub_275();
void __cdecl nullsub_276();
void __cdecl nullsub_277();
void __cdecl nullsub_278();
void __cdecl nullsub_279();
void __cdecl nullsub_280();
void __cdecl nullsub_281();
void __cdecl nullsub_282(void);
void nullsub_283();
void nullsub_284();
void nullsub_285();
void nullsub_286();
void nullsub_287();
void nullsub_288();
void nullsub_289();
void __cdecl nullsub_290();
void __cdecl nullsub_291();
struct FnvCpu_FUN_00dfee80_CpuInterface
{
    virtual void Invoke(int value);
};
void __cdecl Object_InvokeVirtualMethod_00dfee80(FnvCpu_FUN_00dfee80_CpuInterface* object);
struct DestructibleDFF
{
    virtual ~DestructibleDFF();
};
void __cdecl Object_DestructibleDFF_Thunk(DestructibleDFF* pkObject);
struct S00de0fe0_Element
{
    virtual void vf00(int value);
};
struct S00de0fe0_Arr
{
    S00de0fe0_Element** data;
    int count;
    int cap;
    void __thiscall hkpShapeDisplayBuilder_hkpShapeDisplayBuilderEnvironment_hkpShapeDisplayBuilderEnvironment();
};
struct S00de0fe0_Obj10
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void __thiscall hkpShapeDisplayBuilder_hkpShapeDisplayBuilder(int* value);
    void __thiscall UpdateState_00de0f90(int count, S00de0fe0_Element*** array);
};
struct S00de0fe0_Local
{
    S00de0fe0_Arr arr;
    S00de0fe0_Obj10 o;
};
struct S00de0fe0_C983Obj
{
    void __thiscall ForEachCall(int* a, int b, int c, int d, int e);
};
extern void* DAT_012681e0;
// src: HAVOK_LIB 0x00ddfb70
__declspec(noinline) void S00de0fe0_Arr::hkpShapeDisplayBuilder_hkpShapeDisplayBuilderEnvironment_hkpShapeDisplayBuilderEnvironment()
{
    count = 0;
}
void __cdecl hkpShapeDisplayBuilder_addObjectToDebugDisplay(int arg1, int arg2, int arg3, int arg4);
class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_01269fe8;
GlobalObjectO2_00d472a0* __cdecl Runtime_GetField01269fe8Address();
struct cls_d530
{
    int unk00;
    float m_04;
};
extern "C" cls_d530* d530_target(void);
static void Runtime_UpdateState_00def530(float value, cls_d530* target);
void d530_caller(cls_d530* self, float f);
struct d540_cls
{
    float unk00;
    float unk04;
};
extern "C" d540_cls* d540_target(void);
static void Object_UpdateFields_00def540(float a, float b, d540_cls* t);
void d540_caller(float fa, float fb);
extern "C" hkVector4* def550_target(void);
static void SetVec4(float a, float b, float c, float d, hkVector4* t);
void def550_caller(float a, float b, float c, float d);
void Runtime_DoNothing_00df0690();
static void Object_UpdateFields_00df30a0(int* piTarget, int iValue);
void E30A0Store(int* piTarget, int iValue);
struct ProfileEvent
{
    const void* volatile label;
    unsigned int cycles;
    unsigned int extra;
};
struct ThreadProfile
{
    void* owner;
    ProfileEvent* next;
    unsigned int capacity;
    ProfileEvent* end;
};
struct WorkItem
{
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    int remaining;
    unsigned int value;
    int processed;
    unsigned int unk2c;
};
struct WorkQueue
{
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    unsigned int unk20;
    WorkItem* tasks;
    int taskCount;
    int processorCount;
    void* processors[1];
};
struct ExecutionContext
{
    void ProcessCallback(WorkQueue* source, WorkQueue* target, int flags);
};
extern unsigned long DAT_0126835c;
extern "C" const char str_010db918[];
extern "C" const char str_010c41f8[];
int __cdecl hkKdTreeAabbQueryUtils_queryAabbIterative_00d1b930(void* processor, WorkItem* item, unsigned int* value, int remaining);
void __cdecl ProcessWorkQueue(ExecutionContext* context, WorkQueue* queue);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned long DAT_0126835c;
inline hkMonitorStream& hkMonitorStream::getInstance()
{
    return *(hkMonitorStream*)TlsGetValue(DAT_0126835c);
}
static inline void TimerMark(const char* name)
{
    hkMonitorStream* s = &hkMonitorStream::getInstance();
    if (s->m_end.m_storage < s->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)s->m_end.m_storage;
        h->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        h->m_time0 = t;
        s->m_end.m_storage = (char*)(h + 1);
    }
}
struct Key
{
    unsigned char m_type;
    unsigned char m_slot;
};
struct Job
{
    unsigned char m_type;
    unsigned char m_slot;
    unsigned char m_gap[0x16];
    int m_18;
    unsigned char m_gap2[0xc];
    int m_28;
    int m_2c;
};
void __cdecl hkCpuPairGetClosestPointsImplementation(Job* job, int a, int b, int c);
struct Scheduler
{
    int ProcessCallback(Key* key, int b, int a);
};
void __cdecl hkCpuPairGetClosestPointsJob(Scheduler* self, Job* job);
struct FUN_00df9840_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* member10;
    int unk14;
    volatile long* member18;
    void ProcessState_00df9840();
};
extern double DAT_010229b8;
extern "C" unsigned int df9ae0_val(void);
static float rand01(unsigned int state);
volatile float df9ae0_sink;
void q_call_df9ae0(void);
static int g_w1 = 1;
static int g_ws = 3;
static float g_wv = 1.0f;
// src: HAVOK_LIB 0x00df9ae0
static __declspec(noinline) float rand01(void)
{
    g_w1 = (g_w1 * 3) << (g_ws & 31);
    return g_wv;
}
static void WriteFloatToVector(float a, float b, float* out);
void dummy_caller(void);
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
struct FUN_00dfb5a0_cls
{
    int unk00;
    char* m_pData;
    int m_iArrayLength;
    unsigned int m_uCap;

    void UpdateFields_00dfb5a0();
};
template <class T> inline void DestructElementsDFB5A0(T* p, int n)
{
    for (int i = 0; i < n; ++i)
    {
        p[i].Object_UpdateFields_00cb0c00();
    }
}
struct ElemDFB5A0
{
    int unk00;
    FUN_00cb0c00_class m_04;
// src: GUESS 0x00cb0c00 (confidence: low)
    void Object_UpdateFields_00cb0c00()
    {
        m_04.Object_UpdateFields_00cb0c00();
    }
};
extern "C" void* df3210_target(void);
static void Runtime_UpdateState_00df3210(__m128* p);
void df3210_caller(void);
extern const float DAT_010cd644;
struct Dst
{
    __m128 q;
};
static void hkVector4_ComputeValues_00df3170(const unsigned short* src, Dst* d);
void CallerStandIn(Dst* d, const unsigned short* src);


class KdSimdReal
{
  public:
    __forceinline KdSimdReal(float x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __m128 m_vValue;
};
class KdVector4
{
  public:
    __forceinline void set(float a, float b, float c, float d)
    {
        m_vComponents = _mm_setr_ps(a, b, c, d);
    }
    __forceinline void setMul4(const KdVector4& a, const KdVector4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMul4(const KdSimdReal& r, const KdVector4& v1)
    {
        m_vComponents = _mm_mul_ps(r.broadcast(), v1.m_vComponents);
    }
    __forceinline void setAdd4(const KdVector4& a, const KdVector4& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void mul4(const KdVector4& a)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline float& operator()(int a)
    {
        return ((float*)&m_vComponents)[a];
    }
    __forceinline const float& operator()(int a) const
    {
        return ((const float*)&m_vComponents)[a];
    }
    __m128 m_vComponents;
};
class KdVector4Comparison
{
  public:
    enum Mask
    {
        MASK_X = 1,
        MASK_Y = 2,
        MASK_Z = 4
    };
    __forceinline int GetLaneMask() const
    {
        return _mm_movemask_ps(m_uiMask);
    }
    __m128 m_uiMask;
};
class KdBool
{
  public:
    __forceinline KdBool(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    __forceinline operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};
struct KdProjectedEntry
{
    __declspec(align(16)) unsigned short m_kMinimumCorner[3];
    unsigned short m_usFirstVectorPadding;
    unsigned short m_kMaximumCorner[3];
    unsigned short m_usSecondVectorPadding;
    __forceinline void operator=(const KdProjectedEntry& other)
    {
        *(__m128*)this = *(const __m128*)&other;
    }
};
struct KdWorkingSet
{
    KdProjectedEntry* m_pProjectedEntryBegin;
    KdProjectedEntry* m_pProjectedEntryEnd;
};
struct KdSplitResults
{
    int m_iFirstSplitValue;
    int m_iSecondSplitValue;
    unsigned short m_eLeftSplitType;
    unsigned short m_eRightSplitType;
};
namespace KdMath {
template <typename T> __forceinline T max2(T x, T y)
{
    return x > y ? x : y;
}
template <typename T> __forceinline T min2(T x, T y)
{
    return x < y ? x : y;
}
}

static __forceinline __m128 KdToF32(__m128i v)
{
    __m128 two16 = _mm_setr_ps(DAT_010cd644, DAT_010cd644, DAT_010cd644, DAT_010cd644);
    __m128i hi = _mm_srli_epi32(v, 16);
    __m128i lo = _mm_srli_epi32(_mm_slli_epi32(v, 16), 16);
    return _mm_add_ps(_mm_mul_ps(_mm_cvtepi32_ps(hi), two16), _mm_cvtepi32_ps(lo));
}
// src: GUESS 0x00df3170 (confidence: low)
static __declspec(noinline) void hkVector4_ComputeValues_00df3170(const KdProjectedEntry& bounds, KdVector4& extentOut)
{
    __m128i packed = _mm_loadu_si128((const __m128i*)&bounds);
    __m128i zero = _mm_setzero_si128();
    __m128 lo = KdToF32(_mm_unpacklo_epi16(packed, zero));
    __m128 hi = KdToF32(_mm_unpackhi_epi16(packed, zero));
    extentOut.m_vComponents = _mm_sub_ps(hi, lo);
}
// src: GUESS 0x00df3210 (confidence: low)
static __declspec(noinline) void Runtime_UpdateState_00df3210(void* dst)
{
    __m128 zero = _mm_setzero_ps();
    __m128* p = (__m128*)dst;
    p[0] = zero;
    p[1] = zero;
    p[2] = zero;
    p[3] = zero;
    p[4] = zero;
    p[5] = zero;
    p[6] = zero;
    p[7] = zero;
}
// src: HAVOK_LIB 0x00df3250
__declspec(noinline) int __cdecl _nlz(unsigned short x)
{
    int y = x - 0x100;
    int n = (y >> 16) & 8;
    x = (unsigned short)(x << n);
    y = x - 0x1000;
    int m = (y >> 16) & 4;
    n += m;
    x = (unsigned short)(x << m);
    y = x - 0x4000;
    m = (y >> 16) & 2;
    n += m;
    x = (unsigned short)(x << m);
    y = x >> 14;
    m = y & ~(y >> 1);
    return n + 2 - m;
}
int __cdecl Runtime_PartitionBoundsOnLongestAxis(const KdWorkingSet& buffersIn, int startPrimIdx, int endPrimIdx, KdSplitResults& results,
                         KdWorkingSet& buffersOut, const KdProjectedEntry& bounds);

static __forceinline void KdGetDeltaSurfaceArea(const KdVector4& extent, KdVector4& areaOut, KdVector4& deltaOut)
{
    KdVector4 a;
    a.set(extent(1), extent(2), extent(0), 0.0f);
    KdVector4 b;
    b.set(extent(2), extent(0), extent(1), 0.0f);
    areaOut.setMul4(a, b);
    KdVector4 c;
    c.setMul4(0.125f, extent);
    deltaOut.setAdd4(a, b);
    deltaOut.mul4(c);
}

static __forceinline void initializeIterator(const KdProjectedEntry*& it, const KdProjectedEntry* p)
{
    it = p;
}
static __forceinline void reinitializeIterator(const KdProjectedEntry*& it, const KdProjectedEntry* p)
{
    it = p;
}
static __forceinline void initializeIterator(KdProjectedEntry* __restrict& it, KdProjectedEntry* p)
{
    it = p;
}

struct KdTreeBuilder
{
    static int __cdecl ProcessEntries_00df4ec0(const KdWorkingSet& buffersIn, int startPrimIdx, int endPrimIdx,
                                    KdSplitResults& results, int& numAvailableEmptyNodes, KdWorkingSet& buffersOut,
                                    const KdProjectedEntry& bounds, const KdVector4Comparison& allowedEmptySplits);
};

// @fnv 0x00df4ec0
// src: GUESS 0x00df4ec0 (confidence: low)
int __cdecl KdTreeBuilder::ProcessEntries_00df4ec0(const KdWorkingSet& buffersIn, int startPrimIdx, int endPrimIdx,
                                        KdSplitResults& results, int& numAvailableEmptyNodes, KdWorkingSet& buffersOut,
                                        const KdProjectedEntry& bounds, const KdVector4Comparison& allowedEmptySplits)
{
    const int numPrims = endPrimIdx - startPrimIdx;
    if (numPrims == 2)
    {
        const KdProjectedEntry* readIt;
        initializeIterator(readIt, buffersIn.m_pProjectedEntryBegin + startPrimIdx);
        KdProjectedEntry* __restrict writeIt;
        initializeIterator(writeIt, buffersIn.m_pProjectedEntryEnd + startPrimIdx);
        KdProjectedEntry pe0 = *readIt;
        readIt++;
        KdProjectedEntry pe1 = *readIt;
        unsigned short size[3];
        size[0] = (unsigned short)(bounds.m_kMaximumCorner[0] - bounds.m_kMinimumCorner[0]);
        size[1] = (unsigned short)(bounds.m_kMaximumCorner[1] - bounds.m_kMinimumCorner[1]);
        size[2] = (unsigned short)(bounds.m_kMaximumCorner[2] - bounds.m_kMinimumCorner[2]);
        const int axis = size[0] > size[1] ? (size[0] > size[2] ? 0 : 2) : (size[1] > size[2] ? 1 : 2);
        const int splitIndex = startPrimIdx + 1;
        if (pe0.m_kMinimumCorner[axis] > pe1.m_kMinimumCorner[axis])
        {
            *writeIt = pe1;
            writeIt++;
            *writeIt = pe0;
            writeIt++;
            results.m_eRightSplitType = pe1.m_kMaximumCorner[axis];
            results.m_eLeftSplitType = pe0.m_kMinimumCorner[axis];
        }
        else
        {
            *writeIt = pe0;
            writeIt++;
            *writeIt = pe1;
            writeIt++;
            results.m_eRightSplitType = pe0.m_kMaximumCorner[axis];
            results.m_eLeftSplitType = pe1.m_kMinimumCorner[axis];
        }
        results.m_iFirstSplitValue = axis;
        results.m_iSecondSplitValue = splitIndex;
        buffersOut.m_pProjectedEntryEnd = buffersIn.m_pProjectedEntryBegin;
        buffersOut.m_pProjectedEntryBegin = buffersIn.m_pProjectedEntryEnd;
        return 0;
    }
    if (numPrims < 8)
    {
        return Runtime_PartitionBoundsOnLongestAxis(buffersIn, startPrimIdx, endPrimIdx, results, buffersOut, bounds);
    }

    const KdProjectedEntry* entriesIn = buffersIn.m_pProjectedEntryBegin;
    KdVector4 surfaceArea, surfaceDelta;
    KdVector4 extent;
    hkVector4_ComputeValues_00df3170(bounds, extent);
    int splitBin = 0;
    int splitAxis = 0;
    KdGetDeltaSurfaceArea(extent, surfaceArea, surfaceDelta);
    __declspec(align(128)) int minBins[8][4];
    __declspec(align(128)) int maxBins[8][4];
    Runtime_UpdateState_00df3210(minBins);
    Runtime_UpdateState_00df3210(maxBins);
    int binShift[4];
    binShift[0] =
        KdMath::max2(13 - _nlz((unsigned short)(bounds.m_kMaximumCorner[0] - bounds.m_kMinimumCorner[0])), 0);
    binShift[1] =
        KdMath::max2(13 - _nlz((unsigned short)(bounds.m_kMaximumCorner[1] - bounds.m_kMinimumCorner[1])), 0);
    binShift[2] =
        KdMath::max2(13 - _nlz((unsigned short)(bounds.m_kMaximumCorner[2] - bounds.m_kMinimumCorner[2])), 0);

    const KdProjectedEntry* readIt;
    initializeIterator(readIt, entriesIn + startPrimIdx);
    int step = 1;
    if (numPrims > 10)
        step = 2;
    if (numPrims > 100)
        step = 3;
    if (numPrims > 1000)
        step = 4;
    if (numPrims > 10000)
        step = 5;

    for (int i = startPrimIdx; i < endPrimIdx; i += step)
    {
        KdProjectedEntry e = *readIt;
        minBins[(e.m_kMinimumCorner[0] - bounds.m_kMinimumCorner[0]) >> binShift[0]][0]++;
        maxBins[(e.m_kMaximumCorner[0] - bounds.m_kMinimumCorner[0]) >> binShift[0]][0]++;
        minBins[(e.m_kMinimumCorner[1] - bounds.m_kMinimumCorner[1]) >> binShift[1]][1]++;
        maxBins[(e.m_kMaximumCorner[1] - bounds.m_kMinimumCorner[1]) >> binShift[1]][1]++;
        minBins[(e.m_kMinimumCorner[2] - bounds.m_kMinimumCorner[2]) >> binShift[2]][2]++;
        maxBins[(e.m_kMaximumCorner[2] - bounds.m_kMinimumCorner[2]) >> binShift[2]][2]++;
        readIt += step;
    }

    const int numSamples = (numPrims + step - 1) / step;
    int bestLeft = numSamples;
    int bestRight = numSamples;
    float bestCost = 3.40282e+38f;
    KdBool allowEmpty = numAvailableEmptyNodes > 1;
    int masks[3] = {KdVector4Comparison::MASK_X, KdVector4Comparison::MASK_Y, KdVector4Comparison::MASK_Z};

    for (int axis = 0; axis < 3; axis++)
    {
        const float delta = surfaceDelta(axis);
        int numLeft = 0;
        int numRight = numSamples;
        float areaLeft = surfaceArea(axis);
        float areaRight = (float)(delta * 8.0 + surfaceArea(axis));
        for (int bin = 0; bin < 7; bin++)
        {
            numLeft += minBins[bin][axis];
            numRight -= maxBins[bin][axis];
            areaLeft += delta;
            areaRight -= delta;
            const float cost = numLeft * areaLeft + numRight * areaRight;
            KdBool valid =
                (allowEmpty && (allowedEmptySplits.GetLaneMask() & masks[axis]) != 0) || (numLeft > 0 && numRight > 0);
            if (cost < bestCost && valid)
            {
                splitAxis = axis;
                bestCost = cost;
                splitBin = bin;
                bestLeft = numLeft;
                bestRight = numRight;
            }
        }
    }

    const int splitValue =
        bounds.m_kMinimumCorner[(short)splitAxis] + (1 << binShift[(short)splitAxis]) * (splitBin + 1);
    unsigned short rightMin = bounds.m_kMaximumCorner[(short)splitAxis];
    unsigned short leftMax = bounds.m_kMinimumCorner[(short)splitAxis];
    KdProjectedEntry* __restrict left;
    initializeIterator(left, buffersIn.m_pProjectedEntryEnd + startPrimIdx);
    KdProjectedEntry* __restrict right;
    initializeIterator(right, buffersIn.m_pProjectedEntryEnd + (endPrimIdx - 1));
    reinitializeIterator(readIt, entriesIn + startPrimIdx);
    const KdProjectedEntry* endIt = entriesIn + endPrimIdx;
    int splitIndex;
    if (bestLeft >= numSamples && bestRight >= numSamples)
    {
        splitIndex = startPrimIdx + (numPrims >> 1);
        int i;
        for (i = startPrimIdx; i < splitIndex; i++)
        {
            const unsigned short maxE = readIt->m_kMaximumCorner[(short)splitAxis];
            *left = *readIt;
            left++;
            leftMax = KdMath::max2(leftMax, maxE);
            readIt++;
        }
        for (; i < endPrimIdx; i++)
        {
            const unsigned short minE = readIt->m_kMinimumCorner[(short)splitAxis];
            *left = *readIt;
            left++;
            rightMin = KdMath::min2(rightMin, minE);
            readIt++;
        }
    }
    else if (bestLeft >= numSamples)
    {
        while (readIt < endIt)
        {
            const unsigned short minE = readIt->m_kMinimumCorner[(short)splitAxis];
            const unsigned short maxE = readIt->m_kMaximumCorner[(short)splitAxis];
            if (maxE >= splitValue)
            {
                *right = *readIt;
                right--;
                rightMin = KdMath::min2(rightMin, minE);
            }
            else
            {
                *left = *readIt;
                left++;
                leftMax = KdMath::max2(leftMax, maxE);
            }
            readIt++;
        }
        splitIndex = (int)(left - buffersIn.m_pProjectedEntryEnd);
    }
    else
    {
        while (readIt < endIt)
        {
            const unsigned short minE = readIt->m_kMinimumCorner[(short)splitAxis];
            const unsigned short maxE = readIt->m_kMaximumCorner[(short)splitAxis];
            if (minE >= splitValue)
            {
                *right = *readIt;
                right--;
                rightMin = KdMath::min2(rightMin, minE);
            }
            else
            {
                *left = *readIt;
                left++;
                leftMax = KdMath::max2(leftMax, maxE);
            }
            readIt++;
        }
        splitIndex = (int)(left - buffersIn.m_pProjectedEntryEnd);
    }

    if (splitIndex == startPrimIdx || splitIndex == endPrimIdx)
    {
        numAvailableEmptyNodes -= 2;
    }
    results.m_eLeftSplitType = rightMin;
    results.m_eRightSplitType = leftMax;
    results.m_iSecondSplitValue = splitIndex;
    results.m_iFirstSplitValue = splitAxis;
    buffersOut.m_pProjectedEntryEnd = buffersIn.m_pProjectedEntryBegin;
    buffersOut.m_pProjectedEntryBegin = buffersIn.m_pProjectedEntryEnd;
    return 0;
}
