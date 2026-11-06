#include "../../include/hkAabbUint32.h"
// staging/blk_00de0000_o2_gs_ehsc_nogs_noehsc_variant.cpp: hkVector4_S, ShapeRayCastOutput, hkVector4, hkTransform and more (8 functions)
#include <windows.h>
#include "../../include/hkJobType.h"

// src/staging/blk_00de0000_o2_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/staging/blk_00de0000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00de0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/hkMonitorStream.h"
#include "../../include/hkVector4.h"
#include "../../include/hkMonitorStream.h"
#include "../../include/hkMonitorStream.h"
#include "../../include/hkStackMemory.h"
#include "../../include/Vec4.h"
#include "../../include/hkAabb.h"
#include "../../include/hkArray.h"
#include "../../include/hkBool.h"
#include "../../include/hkMatrix3.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkThreadLocalData.h"
#include "../../include/hkTransform.h"
#include "../../include/hkVector4.h"
#include "../../include/hkVector4_S.h"
#include "../../include/hkpCollidable.h"
#include "../../include/hkpFixedBufferRayHitCollector.h"
#include "../../include/hkpShape.h"
#include "../../include/hkRotation.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkMonitorStream.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkBaseObject.h"
#include "../../include/hkReferencedObject.h"
#include "../../include/hkpCdBody.h"
#include "../../include/hkpRayHitCollector.h"
void __cdecl FUN_00df64d0(void* p, int b);
struct FUN_00cb0c00_class {
    void __thiscall FUN_00cb0c00();
};
void FUN_00dfb490(FUN_00cb0c00_class* self);
void FUN_00dfb9d0(hkReferencedObject** p);
extern int DAT_010cc2fc;
extern int DAT_010df34c;
struct FUN_00dfbdf0_class {
    void __thiscall FUN_00cb0a70(int a);
};
void FUN_00dfbdf0(void* p, int a);
extern void* DAT_010d77d8;
struct FUN_00d21de0_Class {
    void __thiscall FUN_00d21de0(void*);
};
void __cdecl FUN_00dfc3e0(void** p, void* a2);
extern "C" void* DAT_010305a8;
extern "C" void* DAT_010e222c;
void FUN_00dfd0f0(void* a, int b);
struct FUN_00cb0a70_class {
    void __thiscall FUN_00cb0a70(int);
};
void __cdecl FUN_00dfd770(void* arg1, void* arg2);
struct FUN_00cb0a70_cls {
    void __thiscall FUN_00cb0a70(char*);
};
void FUN_00dfda10(char* b, char* a);
extern int DAT_010d3cc0;
void FUN_00dfde30(void* p);
extern int DAT_010cc2fc;
extern int DAT_010d08f4;
struct FUN_00cb0a70_Class {
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    void __thiscall FUN_00cb0a70(int a);
};
void FUN_00dfef50(int* p, int a);
extern int DAT_010cc2fc;
extern int DAT_010e6834;
struct FUN_00dff0f0_class {
    int m;
    void FUN_00cb0a70(int);
};
void FUN_00dff0f0(FUN_00dff0f0_class* p, int a);
extern int DAT_010cce28;
extern int DAT_010d07f4;
struct FUN_00cb0a70 {
    void __thiscall m_00cb0a70(int);
};
void __cdecl FUN_00dff1f0(int* a, int b);
struct FUN_00dff340_Class {
    void* m_p;
    void FUN_00cb0a70(void* arg);
};
extern int DAT_010cc2fc;
extern int DAT_010d0944;
void __cdecl FUN_00dff340(void* p, void* arg);
void CopyFields(void* a, void* b);
void FUN_00dfbc70(FUN_00cb0c00_class* self);
extern int DAT_010df89c;
void __cdecl FUN_00dfbf50(int* p);
extern int DAT_010df9f4;
void FUN_00dfc060(int* p);
extern int DAT_010dff44;
void __cdecl FUN_00dfc130(int* p);
typedef void (__thiscall *VTable0)(void*, int);
void __cdecl FUN_00dfc230(void** p);
void __cdecl FUN_00dfc250(void** p);
extern int DAT_010e00cc;
void __cdecl FUN_00dfc280(int* p);
extern int DAT_010e00dc;
void FUN_00dfc2a0(int* p);
void __cdecl FUN_00dfc380(void** p);
extern int DAT_010e04ac;
void __cdecl FUN_00dfc470(int* p);
void __cdecl FUN_00dfc500(void* p);
extern int DAT_010e0654;
void __cdecl FUN_00dfc520(int* a);
extern int DAT_0102e368;
void __cdecl FUN_00dfc620(int* p);
extern int DAT_010d0a64;
void __cdecl FUN_00dfc6c0(int* p);
void __cdecl FUN_00dfc700(void* p);
extern int DAT_010d0aac;
void FUN_00dfc730(int* p);
extern int DAT_010e11ec;
void __cdecl FUN_00dfc900(int* p);
extern int DAT_010da04c;
void __cdecl FUN_00dfca90(int* p);
void __cdecl FUN_00dfcad0(void** p);
extern int DAT_010d0b3c;
void FUN_00dfcb00(int* p);
extern void* DAT_010d37e4;
void __cdecl FUN_00dfcbf0(void** p);
extern int DAT_010c89e4;
void __cdecl FUN_00dfcc60(int* p);
extern int DAT_010d0be4;
void __cdecl FUN_00dfccd0(int* p);
typedef int (__thiscall *VFunc0)(void*, int);
int __cdecl FUN_00dfcd10(void* self);
extern int DAT_010c91ec;
void __cdecl FUN_00dfcd40(int* p);
extern int DAT_010d0cd4;
void __cdecl FUN_00dfce90(int* a);
struct FUN_00dfd7a0_vt {
    virtual void v0(int);
    virtual void v1(int);
};
void __cdecl FUN_00dfd7a0(FUN_00dfd7a0_vt* p);
void __cdecl FUN_00dfd7c0(void* arg);
struct FUN_00dfd940_vt {
    virtual void __thiscall FUN_00dfd940(int);
};
void __cdecl FUN_00dfd940(FUN_00dfd940_vt* p);
void __cdecl FUN_00dfdb40(void* p);
extern int DAT_010e351c;
void __cdecl FUN_00dfdb50(int* p);
extern "C" void* DAT_010e352c;
void __cdecl FUN_00dfdb70(void** p);
void __cdecl FUN_00dfdf90(int a, int b);
extern int DAT_010e3e5c;
void __cdecl FUN_00dfdfb0(int* p);
extern int DAT_010e5474;
void __cdecl FUN_00dfe340(void* p);
struct FUN_00dfe430_class {
    virtual int __thiscall FUN_00cb0a70(int a);
};
int __cdecl FUN_00dfe430(FUN_00dfe430_class* p);
extern int DAT_010e56d4;
void __cdecl FUN_00dfe490(int* p);
extern int DAT_010e57a4;
void __cdecl FUN_00dfe500(int* p);
struct FUN_00dfe670_vt {
    virtual void m_iWordAt00(int);
};
void __cdecl FUN_00dfe670(FUN_00dfe670_vt* p);
extern int DAT_010e58c8;
void __cdecl FUN_00dfe690(int** p);
extern int DAT_010e59ac;
void FUN_00dfe700(int* p);
void __cdecl FUN_00dfeaa0(void** p);
extern int DAT_010e5b68;
void __cdecl FUN_00dfeb60(int* p);
extern int DAT_010e5b4c;
void __cdecl FUN_00dfebd0(int* p);
extern int DAT_010e5bfc;
void __cdecl FUN_00dfec10(int* p);
extern int DAT_010e5d94;
void __cdecl FUN_00dfec70(int* p);
extern int DAT_010e5da8;
void __cdecl FUN_00dfec90(int** p);
void __cdecl FUN_00dfecb0(int* p);
extern int DAT_010e5e9c;
void __cdecl FUN_00dfecd0(int* p);
extern int DAT_010e5ff4;
void FUN_00dfed10(int* p);
extern int DAT_010e60c4;
void __cdecl FUN_00dfee00(int* p);
extern int DAT_010e62a4;
void __cdecl FUN_00dfeea0(int* p);
extern int DAT_010e6394;
void __cdecl FUN_00dfeee0(int* p);
extern int DAT_010e66fc;
void __cdecl FUN_00dfeff0(int* p);
extern int DAT_010e676c;
void __cdecl FUN_00dff0d0(int* p);
extern int DAT_010cc2fc;
extern int DAT_010c8e94;
struct FUN_00cb0a70_m_helper {
    void __thiscall m(int);
};
void __cdecl FUN_00dff270(void* a, void* b);
typedef void (__thiscall *VTableFn)(void*, int);
void __cdecl FUN_00dff3c0(void* p);
extern int DAT_010e75cc;
void FUN_00dff5e0(int* p);
extern int DAT_010e75dc;
void __cdecl FUN_00dff600(int* p);
extern int DAT_010e75ec;
void __cdecl FUN_00dff620(int** p);
void __cdecl FUN_00dff9e0(void** p);
typedef int (__thiscall *Vfn)(void*, int);
int __cdecl FUN_00dffa30(void* obj);
extern int DAT_010e7c24;
void __cdecl FUN_00dffc80(int* p);
extern int DAT_010cc0d8;
void __cdecl FUN_00dffda0(int* p);
struct FUN_00dffdc0_vt {
    virtual void m0(int);
};
void __cdecl FUN_00dffdc0(FUN_00dffdc0_vt* p);
extern int DAT_010d3838;
void __cdecl FUN_00dffe40(int* p);
extern int DAT_010cb798;
void FUN_00dffee0(int* p);
struct FUN_00dfff60_vt {
    virtual int __thiscall v0(int);
};
int __cdecl FUN_00dfff60(FUN_00dfff60_vt* p);
struct FUN_00dfffc0_VT {
    virtual void m0(int);
};
void __cdecl FUN_00dfffc0(FUN_00dfffc0_VT* p);
extern void* DAT_010e80b4;
void __cdecl FUN_00dfffe0(void** p);
struct FUN_00de87c0_class {
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
void __cdecl FUN_00de81a0(void* self, void* arg);
struct FUN_00d21ce0_cls {
    void __thiscall FUN_00d21ce0(void*);
};
struct FUN_00de8550_t {
    int m_iWordAt00;
    int m_iWordAt04;
    void* m_8;
};
void __cdecl FUN_00de8550(FUN_00de8550_t* a, int b);
struct FUN_00de8830_Class {
    void CopyTransposedMatrix(float* src);
};
int __cdecl FUN_00df3250(int arg);
typedef void (__thiscall *Vfn0)(void*, int);
void __cdecl FUN_00df6460(void** p);
typedef int (__thiscall *VFunc_00dfb270)(void*, int);
int __cdecl FUN_00dfb270(void* p);
void __cdecl CallMethodOnBothHelpers(FUN_00cb0a70_m_helper* a, int v);
typedef void (__thiscall *VFunc00dfb3f0)(void*, int);
void __cdecl FUN_00dfb3f0(void** p);
struct FUN_00dfb450_vt {
    virtual void m0(int);
};
void __cdecl FUN_00dfb450(FUN_00dfb450_vt* p);
struct FUN_00dfb890_vt {
    virtual void v0(int);
};
void __cdecl FUN_00dfb890(FUN_00dfb890_vt* p);
extern int DAT_010c4dec;
void FUN_00dfb9f0(int* a, int b);
typedef void (__thiscall *VTable0_00dfba70)(void*, int);
void __cdecl FUN_00dfba70(void* p);
typedef void (__thiscall *VFn0)(void*, int);
void __cdecl FUN_00dfbb30(void* p);
void __cdecl FUN_00dfbbf0(void* p, int a);
struct S_00d49310_Lock { ~S_00d49310_Lock(); };
void __cdecl FUN_00dfbc20(S_00d49310_Lock* self);
void __cdecl FUN_00dfbc30(void* a, void* b);
void __cdecl DispatchToHelper(void* a, int b);
struct S_00dfb720_Elem {
    ~S_00dfb720_Elem();
};
void __cdecl FUN_00dfbca0(S_00dfb720_Elem* p);
typedef void (__thiscall *VTable0)(void*, int);
void __cdecl FUN_00dfbcd0(void* p);
typedef void (__thiscall *VFunc1)(void*, int);
void __cdecl FUN_00dfbdd0(void* p);
struct FUN_00dfc040_vt {
    virtual void __thiscall FUN_00dfc040(int);
};
void __cdecl FUN_00dfc040(FUN_00dfc040_vt* p);
typedef void (__thiscall *V00dfc790)(void*, int);
void __cdecl FUN_00dfc790(void** p);
void __cdecl FUN_00dfc7f0(int* p);
void __cdecl FUN_00dfc8d0(void** p);
typedef void (__thiscall *Vfn_00dfcb60)(void*, int);
void __cdecl FUN_00dfcb60(void* p);
struct FUN_00dfcc30_vt {
    virtual void v0(int);
};
void __cdecl FUN_00dfcc30(FUN_00dfcc30_vt* p);
struct FUN_00dd0420_Class {
    FUN_00dd0420_Class* __thiscall FUN_00dd0420(int);
};
void __cdecl FUN_00dfcd80(FUN_00dd0420_Class* self, int a);
struct FUN_00dfce00_vt {
    virtual void __thiscall v0(int);
};
void __cdecl FUN_00dfce00(FUN_00dfce00_vt* p);
struct FUN_00dfcf00_vt {
    virtual void m_iWordAt00(int);
};
void __cdecl FUN_00dfcf00(FUN_00dfcf00_vt* p);
struct FUN_00dfd240_vt {
    virtual void __thiscall FUN_00dfd240(int);
};
void __cdecl FUN_00dfd240(FUN_00dfd240_vt* p);
typedef void (__thiscall *Vfn_00dfd620)(void*, int);
void __cdecl FUN_00dfd620(void* p);
struct DFD680MeshData {
    void FUN_00dfd680();
};
void __cdecl FUN_00dfd670(DFD680MeshData* p);
extern int DAT_010e311c;
void FUN_00dfd7d0(int* p, int a);
void __cdecl FUN_00dfda70(void* p);
void FUN_00dfdad0(int* a, int b);
void __cdecl FUN_00dfdb00(void* p);
struct FUN_00dfdb20_vt {
    virtual void v0(int);
};
void __cdecl FUN_00dfdb20(FUN_00dfdb20_vt* p);
void __cdecl CallHelperMethod(FUN_00cb0a70_m_helper* a, int b);
struct S_00e3eaa0_Elem {
    ~S_00e3eaa0_Elem();
};
void __cdecl FUN_00dfdd50(S_00e3eaa0_Elem* p);
struct FUN_00e3f900_class {
    int FUN_00e3f900(int);
};
void __cdecl FUN_00dfdd60(FUN_00e3f900_class* p, int a);
void CallHelperWithInt(FUN_00cb0a70_m_helper* p, int a);
struct ArrayPair {
    ~ArrayPair();
};
void __cdecl FUN_00dfe0c0(ArrayPair* p);
typedef void (__thiscall *Vfn_00dfe270)(void*, int);
void __cdecl FUN_00dfe270(void* p);
void __cdecl FUN_00dfe2b0(void* p);
extern int DAT_010cb864;
struct FUN_00ce5360_class {
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int FUN_00ce5360(int a);
};
void __cdecl FUN_00dfe2d0(FUN_00ce5360_class* a, int b);
struct FUN_00dfe320_vt {
    virtual void m_iWordAt00(int);
};
void __cdecl FUN_00dfe320(FUN_00dfe320_vt* p);
extern int DAT_010e56d4;
int* FUN_00dfe4a0();
struct FUN_00dfe4e0_vt {
    virtual void m0(int);
};
void __cdecl FUN_00dfe4e0(FUN_00dfe4e0_vt* p);
void __cdecl FUN_00dfe590(void* p);
extern int DAT_010e587c;
void __cdecl FUN_00dfe5b0(void* a, int b);
extern int DAT_010e5a58;
void __cdecl FUN_00dfe990(void* a, int b);
void __cdecl FUN_00dfeb40(void* p);
void __cdecl FUN_00dfebb0(void** p);
typedef void (__thiscall *Vfn0)(void*, int);
void __cdecl FUN_00dfebf0(void* p);
struct FUN_00dfec30_vt {
    virtual void m0(int);
};
void __cdecl FUN_00dfec30(FUN_00dfec30_vt* p);
struct FUN_00dfecf0_vt { virtual void v0(int); };
void __cdecl FUN_00dfecf0(FUN_00dfecf0_vt* p);
struct FUN_00dfede0_vt {
    virtual void v0(int);
};
void __cdecl FUN_00dfede0(FUN_00dfede0_vt* p);
typedef int (__thiscall *Vfn_00dfeec0)(void*, int);
int __cdecl FUN_00dfeec0(void* p);
struct FUN_00dfef00_vt { virtual void __thiscall m0(int); };
void __cdecl FUN_00dfef00(FUN_00dfef00_vt* p);
struct FUN_00dff1d0_vt {
    virtual void m0(int);
};
void __cdecl FUN_00dff1d0(FUN_00dff1d0_vt* p);
typedef void (__thiscall *VTable0)(void*, int);
void __cdecl FUN_00dff300(void** p);
struct FUN_00dff370_vt {
    virtual void __thiscall FUN_00dff370(int);
};
void __cdecl FUN_00dff370(FUN_00dff370_vt* p);
void __cdecl FUN_00dff540(void** p);
typedef void (__thiscall *VTable0)(void*, int);
void __cdecl FUN_00dff580(void** p);
typedef void (__thiscall *VTable0)(void*, int);
void __cdecl FUN_00dff5c0(void* p);
extern int DAT_010cc2fc;
extern int DAT_010d0994;
struct FUN_00dff9b0_m : FUN_00cb0a70 {
    void __thiscall m(int);
};
void __cdecl FUN_00dff9b0(FUN_00dff9b0_m* p, int a);
typedef void (__thiscall *VTblFn0)(void*, int);
void __cdecl FUN_00dffc10(void* p);
struct FUN_00dffc60_vt {
    virtual void m0(int);
};
void __cdecl FUN_00dffc60(FUN_00dffc60_vt* p);
struct FUN_00dffd80_vt {
    virtual void __thiscall FUN_00cb0a70(int);
};
void __cdecl FUN_00dffd80(FUN_00dffd80_vt* p);
typedef void (__thiscall *VTableFn)(void*, int);
void __cdecl FUN_00dffe20(void* p);
struct FUN_00dffe60_vt {
    virtual void m_iWordAt00(int);
};
void __cdecl FUN_00dffe60(FUN_00dffe60_vt* p);
typedef void (__thiscall *Vfn0)(void*, int);
void __cdecl FUN_00dfff00(void* p);
extern int DAT_0102e388;
hkMemoryRouter* __cdecl FUN_00c85750() throw();
struct FUN_00de10e0_cls {
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
struct FUN_00de3050 {
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
class FUN_00de3090_cls {
public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    void FUN_00de3090();
};
struct Quad16 { unsigned int x; unsigned int y; unsigned int z; unsigned int w; };
class FUN_00de48a0_cls
{
public:
    unsigned int unk00; unsigned int unk04; unsigned int unk08; unsigned int unk0C; unsigned int unk10; unsigned int unk14; unsigned int unk18; unsigned int unk1C; unsigned int unk20; unsigned int unk24; unsigned int unk28; unsigned int unk2C; unsigned int unk30; unsigned int unk34; unsigned int unk38; unsigned int unk3C; unsigned int unk40; unsigned int unk44; unsigned int unk48; unsigned int unk4C; unsigned int unk50; unsigned int unk54; unsigned int unk58; unsigned int unk5C;
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
class FNVFloatGetter_cls {
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
    float FUN_00de48e0();
};
struct FUN_00de48f0_cls {
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
    float FUN_00de48f0();
};
struct CpuObject {
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
    float FUN_00de4900();
};
struct FUN_00de4910_cls {
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
    int FUN_00de4910();
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
struct FUN_00de4e10_cls {
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

    char* FUN_00de4e10();
};

class FUN_00de5320_cls {
public:
    Vec4 GetVec4At70();
};
struct FUN_00de5350_cls {
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
    float FUN_00de5350();
};
class FUN_00de5360_cls {
public:
    void* FUN_00de5360();
};
extern void* DAT_01269ce8;
int __cdecl FUN_00de8150();
extern int DAT_01269d18;
int* __cdecl FUN_00de8170();
extern int DAT_01269d48;
void* FUN_00de8190();
extern int g_unk01269d78;
void* __cdecl FUN_00de81d0();
struct CpuOpaque;
extern CpuOpaque DAT_01269da8;
CpuOpaque* __cdecl FUN_00de81f0();
extern int DAT_01269dd8;
void* __cdecl FUN_00de8210();
extern int g_unk01269e08;
int* FUN_00de8230();
struct GlobalObject {
    int unk00;
};
extern GlobalObject g_global;
GlobalObject* __cdecl FUN_00de8250();
struct CpuOpaque;
extern CpuOpaque DAT_01269e68;
CpuOpaque* __cdecl FUN_00de8270();
extern int g_unk01269e98;
void* __cdecl FUN_00de8290();
extern int g_unk01269ec8;
void* __cdecl FUN_00de82b0();
class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_01269ef8;
GlobalObjectO2_00d472a0* __cdecl FUN_00de82d0();
extern int DAT_01269f28;
void* __cdecl FUN_00de82f0();
extern int g_unkGlobal01269f58;
void* __cdecl FUN_00de8310();
extern int DAT_01269f88;
void* __cdecl FUN_00de8330();
// FUN_00de8350 : a one-line function - getter
extern int g_target_00de8350;
void* FUN_00de8350();
extern int DAT_0126a018;
void* __cdecl FUN_00de8390();
extern int DAT_0126a048;
int* FUN_00de83b0();
struct CpuOpaque;
extern CpuOpaque DAT_0126a078;
CpuOpaque* __cdecl FUN_00de83d0();
extern int DAT_0126a0a8;
void* __cdecl FUN_00de83f0();
extern int DAT_0126a0d8;
void* __cdecl FUN_00de8410();
extern int DAT_0126a108;
int* __cdecl FUN_00de8430();
extern int DAT_0126a138;
void* __cdecl FUN_00de8450();
extern int DAT_0126a168;
void* __cdecl FUN_00de8470();
extern int DAT_0126a198;
int* __cdecl FUN_00de8490();
extern int DAT_0126a1c8;
void* __cdecl FUN_00de84b0();
extern FUN_00de87c0_class DAT_0126a1f8;
FUN_00de87c0_class* __cdecl FUN_00de84d0();
// FUN_00de84f0 : returns the address of a global data object.
// Original: mov eax, offset DAT_0126a228 ; ret
extern int DAT_0126a228;
int* __cdecl FUN_00de84f0();
struct CpuOpaque;
extern CpuOpaque DAT_0126a258;
CpuOpaque* __cdecl FUN_00de8510();
extern int g_0126a288;
int* __cdecl FUN_00de8530();
struct FUN_00de8570_cls {
    int m_00;
    int m_04;
    int m_08;
    void __thiscall FUN_00d21ce0(int value);
};
void __cdecl FUN_00de8570(FUN_00de8570_cls* pTarget, int nIndex);
extern int DAT_0126a378;
void* __cdecl FUN_00de8750();
extern int g_unk126a3a8;
void* __cdecl FUN_00de8770();
class FUN_00de8780_cls
{
public:
    float m_fValues[16];

    unsigned char* HasNoNaNOrInf(unsigned char* pResult);
};
struct JacRow { float x; float y; float z; float w; };
struct JacBlock {
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
struct DF25D0State {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    short unk10;
    unsigned char m_ucFlags;
};
struct DF25D0Owner {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14;
    int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C;
    DF25D0State* m_pkState;
};
void __cdecl FUN_00cb3c80(void* pkItem, DF25D0Owner* pkOwner);
static void SetOwnerStateFlags(void* pkItem, DF25D0Owner* pkOwner, unsigned char m_ucEntryType);
void DF25D0Attach(void* pkItem, DF25D0Owner* pkOwner, unsigned char m_ucEntryType);
class FUN_00df3110 {
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
struct FUN_00df3140_pair {
    unsigned int m_ucLowNibble;
    unsigned int m_ucHighNibble;
};
void __stdcall CopyPairToIndex(FUN_00df3140_pair* dst, unsigned int idx, FUN_00df3140_pair* src);
struct Handler_cls
{
    void __thiscall Handle(int value);
};
void __cdecl FUN_00df6440(Handler_cls* pHandler, int value);
extern int g_0126a430;
int* __cdecl FUN_00df6490();
extern int DAT_0126a478;
void* __cdecl FUN_00df64b0();
extern "C" int DAT_0126a4a8;
// @fnv 0x00df64c0
extern "C" void* __cdecl FUN_00df64c0() {
    return &DAT_0126a4a8;
}
struct FUN_00df7a60_class {
    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0c;
    void* m_p10;
    int unk14;
    int unk18;
    void* m_p1c;

    void __thiscall FUN_00df7a60();
};
extern "C" __declspec(dllimport) long __stdcall InterlockedExchangeAdd(
    volatile long* value,
    long increment);
void __cdecl FUN_00d043c0(void* object, int value);
extern float DAT_010dbb3c;
extern float DAT_0104da48;
struct ParserContext { int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,result44; int __thiscall FUN_00e63af0(int, void*,float*); };
struct FloatPair { float first,second; int __thiscall TraverseNode(ParserContext*,int,int*,ParserContext**); int __thiscall FUN_00dfb040(ParserContext*,int,int*,ParserContext**); };
struct CpuOpaque;
extern CpuOpaque DAT_0126a5f8;
CpuOpaque* __cdecl FUN_00dfb260();
extern int g_unk0126aa18;
int* __cdecl FUN_00dfb280();
struct FUN_00dfb2d0_class {
    void __thiscall FUN_00dfb2d0(int a);
};
void __cdecl FUN_00dfb290(FUN_00dfb2d0_class* p, int a);
extern int DAT_0126aac0;
int* __cdecl FUN_00dfb360();
extern int DAT_0126aaf0;
void* __cdecl FUN_00dfb380();
extern int DAT_0126abe0;
int* __cdecl FUN_00dfb3c0(void);
// Null-guarded forwarder: the first argument is an object pointer; when it
// is non-null the second argument is forwarded to a member function of that
// object (ecx = object, one stack argument).
struct FUN_00dfb3d0_cls
{
    void __thiscall FUN_00e2ea20(int a1);
};
void __cdecl FUN_00dfb3d0(FUN_00dfb3d0_cls *pObject, int a1);
extern unsigned char DAT_0126ac10;
void* __cdecl FUN_00dfb420();
struct FUN_00e2ebc0_cls
{
    void __thiscall Init(void* a);
};
void __cdecl FUN_00dfb430(FUN_00e2ebc0_cls* pObject, void* pArg);
extern "C" int DAT_0126ac58;
int* __cdecl FUN_00dfb480(void);
extern int DAT_0126acd0;
int __cdecl FUN_00dfb4d0();
extern int DAT_0126ad00;
void* __cdecl FUN_00dfb4f0();
extern int DAT_0126ad30;
void* __cdecl FUN_00dfb510();
extern void* DAT_0126ad60;
int __cdecl FUN_00dfb540();
class DFB550Object {
public:
    virtual ~DFB550Object();
};
void FUN_00dfb550(DFB550Object* pkObject);
extern int DAT_0126ad90;
int* __cdecl FUN_00dfb560();
inline void* operator new(unsigned int, void* pvWhere) throw() { return pvWhere; }
struct DFB570FinishFlag {
    int m_bFinishing;
};
class DFB570Object {
public:
    DFB570Object(DFB570FinishFlag flag)
    {
        if (flag.m_bFinishing)
            finishInit();
    }

    virtual void vfunc00();

    void finishInit();
};
void FUN_00dfb570(void* p, int finishing);
extern int DAT_010ddc5c;
void* __cdecl FUN_00dfb590();
extern int DAT_0126add8;
int* __cdecl FUN_00dfb860();
extern unsigned char g_fnvDat0126ae08;
void* FUN_00dfb880();
// FUN_00dfb8a0 : a one-line function - getter
extern int g_target_00dfb8a0;
void* FUN_00dfb8a0();
// ResetVTable -- installs a fixed vtable on an object and, when the second
// argument is set, runs the object's update step afterwards.
extern int DAT_010de0ec;
// vtable that gets installed
struct ResetVTableObj {
    void* m_vptr;                     // virtual table pointer, offset 0
};
struct ResetVTableTarget {
    void __thiscall m_update();
};
void __cdecl ResetVTable(ResetVTableObj* p, int bUpdate);
extern int DAT_010de0ec;
void* FUN_00dfb8d0();
struct CpuOpaque;
extern CpuOpaque DAT_0126ae80;
CpuOpaque* __cdecl FUN_00dfb920();
extern int DAT_0126aeb0;
void* __cdecl FUN_00dfb940();
class CalleeObj
{
public:
    void FUN_00ce5360(void *pParam);
};
void __cdecl FUN_00dfb950(CalleeObj *pFirst, void *pSecond);
extern int DAT_0126aee0;
int* __cdecl FUN_00dfb970();
struct FUN_00ce5370_cls {
    void __thiscall FUN_00ce5370();
};
void __cdecl FUN_00dfb980(FUN_00ce5370_cls* p);
extern int DAT_0126af10;
int* __cdecl FUN_00dfb990();
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
int __cdecl FUN_00dfb9a0(FUN_00dfb9a0_cls* pObj);
extern int DAT_0126af40;
int* __cdecl FUN_00dfb9b0(void);
extern int DAT_0126af88;
int* FUN_00dfba40();
// FUN_00dfba50: null-guarded forwarding of a second argument to a
// member function of the first (object) argument.
class FUN_00dfba50_cls
{
public:
    void FUN_00e34800(int a1);
};
void __cdecl FUN_00dfba50(FUN_00dfba50_cls *pObject, int a1);
extern int g_unk0126afb8;
void* __cdecl FUN_00dfbaa0();
struct CpuOpaque;
extern CpuOpaque DAT_0126b000;
CpuOpaque* __cdecl FUN_00dfbb20();
extern int DAT_0126b030;
void* __cdecl FUN_00dfbb40();
// FUN_00dfbb50 : installs the class vtable into the object and, when the
// second argument is non-zero, tail-calls the routine at FUN_00e35050 with
// the object as 'this'.
extern int DAT_010de90c;
struct FUN_00dfbb50_cls
{
    void* m_vtbl;
    void __thiscall FUN_00e35050();
};
void __cdecl FUN_00dfbb50(FUN_00dfbb50_cls* p, int a);
extern int DAT_010de90c;
void* __cdecl FUN_00dfbb70();
extern "C" int DAT_0126b078;
// @fnv 0x00dfbc10
extern "C" void* __cdecl FUN_00dfbc10() {
    return &DAT_0126b078;
}
struct CpuOpaque;
extern CpuOpaque DAT_0126b0a8;
CpuOpaque* __cdecl FUN_00dfbc50();
extern int DAT_0126b0d8;
int* __cdecl FUN_00dfbc60();
extern int DAT_0126b138;
void* __cdecl FUN_00dfbce0();
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
void* __cdecl FUN_00dfbd30();
extern int DAT_0126b180;
void* __cdecl FUN_00dfbdc0();
extern int DAT_0126b1b0;
void* __cdecl FUN_00dfbde0();
extern int DAT_0126b1f8;
void* __cdecl FUN_00dfbe90();
extern unsigned char DAT_0126b228;
void* __cdecl FUN_00dfbeb0();
extern int DAT_0126b258;
void* __cdecl FUN_00dfbed0();
struct CpuOpaque;
extern CpuOpaque DAT_0126b288;
CpuOpaque* __cdecl FUN_00dfbef0();
extern int DAT_0126b2b8;
void* __cdecl FUN_00dfbf20();
struct FUN_00dfbf30_class {
    virtual void m0(int);
};
void __cdecl FUN_00dfbf30(void* p);
extern int DAT_0126b2e8;
int* __cdecl FUN_00dfbf40();
int* __cdecl FUN_00dfbf60();
extern int DAT_0126b330;
void* __cdecl FUN_00dfc030();
// FUN_00dfc050 : a constant getter - MSVC emits mov eax, OFFSET <global> ; ret.
// The global is declared extern so the store becomes a relocation; the checker
// binds it to the original's own immediate.
extern int g_target_FUN_00dfc050;
void* __cdecl FUN_00dfc050();
// FUN_00dfc070 : a one-line function - getter
extern int g_target_00dfc070;
void* FUN_00dfc070();
extern int DAT_0126b3a8;
int* __cdecl FUN_00dfc100();
struct S_00dfc110_vt {
    virtual void m0(int);
};
void __thiscall S_00dfc110_vt::m0(int) {
}
void __cdecl FUN_00dfc110(void* p);
extern int g_0126b3d8;
int* __cdecl FUN_00dfc120();
extern int DAT_010dff44;
int* __cdecl FUN_00dfc140();
extern unsigned char DAT_0126b420;
void* __cdecl FUN_00dfc220();
extern char DAT_0126b498;
char* __cdecl FUN_00dfc260();
extern int DAT_010e00cc;
void* FUN_00dfc290();
extern int DAT_010e00dc;
int* __cdecl FUN_00dfc2b0();
// FUN_00dfc360: cdecl no-arg getter returning the address of a global.
extern int DAT_0126b528;
int* __cdecl FUN_00dfc360();
extern int g_unk0126b4e0;
void* __cdecl FUN_00dfc370();
extern void* DAT_0126b558;
void* FUN_00dfc390();
struct FUN_00e05c20_class {
    void __thiscall FUN_00e05c20();
};
void __cdecl FUN_00dfc3a0(FUN_00e05c20_class* p);
struct FUN_00dfc3b0_target
{
    void Run();
};
void __cdecl FUN_00dfc3b0(FUN_00dfc3b0_target* pTarget);
// FUN_00dfc440 : a one-line function - getter
extern int g_target_00dfc440;
void* FUN_00dfc440();
class VirtualDispatchObj {
public:
    virtual void Invoke0(int arg);
};
void __cdecl FUN_00dfc450(VirtualDispatchObj* p);
extern void* DAT_0126b588;
int __cdecl FUN_00dfc460();
extern int DAT_010e04ac;
void* __cdecl FUN_00dfc480();
extern int g_unk0126b678;
void* __cdecl FUN_00dfc4d0();
extern int DAT_0126b648;
int* __cdecl FUN_00dfc4f0();
extern int DAT_0126b600;
int* __cdecl FUN_00dfc510();
extern int DAT_010e0654;
int* __cdecl FUN_00dfc530();
extern int DAT_0126b6a8;
int* __cdecl FUN_00dfc590(void);
// FUN_00dfc5b0 : a one-line function - getter
extern int g_target_00dfc5b0;
void* FUN_00dfc5b0();
extern int DAT_0126b708;
int* __cdecl FUN_00dfc5d0();
extern int DAT_0126b738;
void* __cdecl FUN_00dfc5f0();
struct FUN_00dfc600_vt {
    virtual void __thiscall m0(int);
};
void __cdecl FUN_00dfc600(FUN_00dfc600_vt* p);
extern unsigned char DAT_0126b768;
void* __cdecl FUN_00dfc610();
extern int DAT_0102e368;
int* __cdecl FUN_00dfc630();
extern int DAT_0126b7b0;
int* __cdecl FUN_00dfc660();
// FUN_00dfc680 : a one-line function - getter
extern int g_target_00dfc680;
void* FUN_00dfc680();
struct FUN_00dfc690_vt {
    virtual void m0(int);
};
void __cdecl FUN_00dfc690(FUN_00dfc690_vt* p);
extern int DAT_0126b810;
void* __cdecl FUN_00dfc6a0();
extern int DAT_010d0a64;
int* __cdecl FUN_00dfc6d0();
extern char DAT_0126b858;
void* FUN_00dfc6f0();
class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_0126b888;
GlobalObjectO2_00d472a0* __cdecl FUN_00dfc710();
extern int DAT_010d0aac;
int* __cdecl FUN_00dfc740();
extern int g_unk0126b8d0;
int* __cdecl FUN_00dfc760();
extern int g_0126b900;
int* __cdecl FUN_00dfc7c0();
extern int DAT_0126b948;
int* __cdecl FUN_00dfc7e0();
extern int DAT_0126b978;
void* __cdecl FUN_00dfc800();
class DFC810Object {
public:
    void Process(void* pvData);
};
void __cdecl FUN_00dfc810(DFC810Object* pkObject, void* pvData);
class SpawnedBase {
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
class SpawnedMid {
public:
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    SpawnedMid() {
        *(volatile int*)&m_8c = 0;
        *(volatile int*)&m_90 = 0;
        *(volatile int*)&m_94 = (int)0x80000000;
        *(volatile int*)&m_98 = 0;
        *(volatile int*)&m_9c = 0;
        *(volatile int*)&m_a0 = (int)0x80000000;
    }
};
class FUN_00dfc850 : public SpawnedBase, public SpawnedMid {
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
int* __cdecl FUN_00dfc8c0();
extern int g_unk0126b9f0;
int* __cdecl FUN_00dfc8e0();
extern int DAT_010e11ec;
int* __cdecl FUN_00dfc910();
extern int g_0126ba38;
int* __cdecl FUN_00dfc930();
struct FUN_00dfc940_class {
    virtual void m0(int);
};
void __cdecl FUN_00dfc940(FUN_00dfc940_class* p);
extern int DAT_0126ba68;
void* __cdecl FUN_00dfc950();
extern int DAT_010d0af4;
struct S_00dfc970_Flag {
    char v;
    S_00dfc970_Flag(char c) { v = c; }
    S_00dfc970_Flag(const S_00dfc970_Flag& o) { v = o.v; }
};
struct S_00dfc970_Obj {
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
    void FUN_00d4f270(S_00dfc970_Flag f);
};
void __cdecl FUN_00dfc970(S_00dfc970_Obj* p, int flag);
extern int DAT_010d0af4;
int* __cdecl FUN_00dfc9a0();
extern int DAT_0126bab0;
int* __cdecl FUN_00dfc9c0();
class DFC9D0Object {
public:
    virtual ~DFC9D0Object();
};
void FUN_00dfc9d0(DFC9D0Object* pkObject);
extern int DAT_0126bae0;
int* __cdecl FUN_00dfc9e0();
extern int DAT_010cb71c;
void* __cdecl FUN_00dfca30();
extern int DAT_0126bb28;
void* __cdecl FUN_00dfca50();
class DFCA60Object {
public:
    virtual ~DFCA60Object();
};
void FUN_00dfca60(DFCA60Object* pkObject);
extern char g_unk0126bb58;
void* __cdecl FUN_00dfca70();
extern int DAT_010da04c;
int* __cdecl FUN_00dfcaa0();
extern int DAT_0126bba0;
int* __cdecl FUN_00dfcac0();
extern void* DAT_0126bbd0;
int __cdecl FUN_00dfcae0();
extern int DAT_010d0b3c;
int* __cdecl FUN_00dfcb10();
extern int DAT_0126bc18;
void* __cdecl FUN_00dfcb30();
extern int DAT_0126bc48;
int* __cdecl FUN_00dfcb90();
extern int DAT_0126bc90;
int* __cdecl FUN_00dfcbb0();
// Stand-in for the object whose virtual slot 0 is invoked with argument 0.
struct FUN_00dfcbc0_vt
{
    virtual void m0(int a);
};
void __cdecl FUN_00dfcbc0(FUN_00dfcbc0_vt* pObject);
extern int DAT_0126bcc0;
void* __cdecl FUN_00dfcbd0();
extern void* DAT_010d37e4;
void** __cdecl FUN_00dfcc00();
// FUN_00dfcc20 : a one-line function - getter
extern int g_target_00dfcc20;
void* FUN_00dfcc20();
struct S_00dfcc40_Obj { int unk00; };
extern S_00dfcc40_Obj DAT_0126bd38;
S_00dfcc40_Obj* __cdecl FUN_00dfcc40();
// FUN_00dfcc70 : a one-line function - getter
extern int g_target_00dfcc70;
void* FUN_00dfcc70();
extern int DAT_0126bd80;
int* __cdecl FUN_00dfcc90();
// Forwarder: takes the object pointer, calls its first virtual slot with a
// literal 0 argument (push 0; call through the vtable entry).
struct VtblForwarder
{
    virtual int v0(int);
};
int __cdecl FUN_00dfcca0(VtblForwarder* p);
// FUN_00dfccb0 : a one-line function - getter
extern int g_target_00dfccb0;
void* FUN_00dfccb0();
extern int DAT_010d0be4;
void* __cdecl FUN_00dfcce0();
extern int DAT_0126bdf8;
void* __cdecl FUN_00dfcd00();
struct CpuOpaque;
extern CpuOpaque DAT_0126be28;
CpuOpaque* __cdecl FUN_00dfcd20();
extern int DAT_010c91ec;
int* FUN_00dfcd50();
extern int DAT_0126be70;
int* __cdecl FUN_00dfcd70();
extern int DAT_0126bea0;
void* __cdecl FUN_00dfcda0();
struct FUN_00dfcdb0_target
{
    void Run();
};
void __cdecl FUN_00dfcdb0(FUN_00dfcdb0_target* pTarget);
extern char DAT_0126bed0;
void* __cdecl FUN_00dfcdd0();
struct DFD5E0 { void __thiscall FUN_00d53df0(void* p); };
void __cdecl FUN_00dfcde0(void* a, void* b);
extern int DAT_0126bf00;
void* __cdecl FUN_00dfce30();
extern int DAT_0126bf48;
int* __cdecl FUN_00dfce50();
extern int DAT_0126bf78;
void* __cdecl FUN_00dfce70();
extern int DAT_010d0cd4;
int* __cdecl FUN_00dfcea0();
struct CpuOpaque;
extern CpuOpaque DAT_0126bfc0;
CpuOpaque* __cdecl FUN_00dfcec0();
extern int DAT_0126bff0;
void* __cdecl FUN_00dfcef0();
extern int DAT_0126c020;
void* __cdecl FUN_00dfcf10();
struct FUN_00dfcf20_cls {
    void __thiscall InitializeVtables(int a);
};
void __cdecl FUN_00dfcf20(FUN_00dfcf20_cls* p, int a);
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
void* FUN_00dfd0c0();
struct FUN_00dfd0d0_cls
{
    virtual void Call(int a);
};
void FUN_00dfd0d0(FUN_00dfd0d0_cls* pTarget);
extern int DAT_0126c098;
void* FUN_00dfd0e0();
extern "C" void* DAT_010e222c;
void* __cdecl FUN_00dfd120();
extern unsigned char DAT_0126c0e0;
unsigned char* __cdecl FUN_00dfd1b0();
void __cdecl FUN_00dfd1c0(void* p);
extern int DAT_0126c110;
void* __cdecl FUN_00dfd1d0();
// FUN_00dfd1e0: null-guarded forwarding of a second argument to a
// member function of the first (object) argument.
class FUN_00dfd1e0_cls
{
public:
    void Forward(int a1);
};
void __cdecl FUN_00dfd1e0(FUN_00dfd1e0_cls *pObject, int a1);
extern int DAT_0126c158;
int* __cdecl FUN_00dfd230();
// FUN_00dfd250 : a one-line function - getter
extern int g_target_00dfd250;
void* FUN_00dfd250();
struct S_00dfd260_Foo {
    void __thiscall FUN_00d59830(int arg);
};
void __cdecl FUN_00dfd260(S_00dfd260_Foo* self, int arg);
extern int DAT_0126c1d0;
int* __cdecl FUN_00dfd2a0();
extern int DAT_0126c200;
int* __cdecl FUN_00dfd2c0();
class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_0126c230;
GlobalObjectO2_00d472a0* __cdecl FUN_00dfd2d0();
struct FUN_00dfd2e0_Class {
    virtual void VF00(int value);
};
void __cdecl FUN_00dfd2e0(FUN_00dfd2e0_Class* param_1);
// FUN_00dfd2f0 : a one-line function - getter
extern int g_target_00dfd2f0;
void* FUN_00dfd2f0();
struct FUN_00e3dbd0_class {
    void __thiscall FUN_00e3dbd0(int value);
};
void __cdecl FUN_00dfd300(FUN_00e3dbd0_class* object, int value);
struct FUN_00dfd380_Class {
    void __thiscall FUN_00dfd380();
};
void __cdecl FUN_00dfd360(int* param_1);
struct FnvCpu_FUN_00dfd370_CpuTarget { void FUN_00dfd440(); };
void __cdecl FUN_00dfd370(FnvCpu_FUN_00dfd370_CpuTarget* target);
// FUN_00dfd4e0 : a one-line function - getter
extern int g_target_00dfd4e0;
void* FUN_00dfd4e0();
extern int DAT_0126c2d8;
void* __cdecl FUN_00dfd500();
struct CpuOpaque;
extern CpuOpaque DAT_0126c308;
CpuOpaque* __cdecl FUN_00dfd540();
extern int DAT_0126c338;
int* __cdecl FUN_00dfd560();
// FUN_00dfd570: null-guarded forwarder. The first argument (an object
// pointer) is loaded and tested; when it is not null the second argument
// is passed on to a non-virtual member function of that object.
class FUN_00dfd570_cls
{
public:
    void FUN_00e3df50(int a1);
};
void __cdecl FUN_00dfd570(FUN_00dfd570_cls *pObject, int a1);
extern int DAT_0126c368;
int* __cdecl FUN_00dfd590();
extern int DAT_0126c398;
int __cdecl FUN_00dfd5f0();
class FUN_00dfd600_cls {
public:
    void Callee(unsigned int value);
};
void __cdecl FUN_00dfd600(FUN_00dfd600_cls* target, unsigned int value);
// FUN_00dfd650 : a one-line function - getter
extern int g_target_00dfd650;
void* FUN_00dfd650();
extern int DAT_0126c410;
int* __cdecl FUN_00dfd790();
extern int DAT_0126c440;
void* __cdecl FUN_00dfd7b0();
extern int DAT_0126c488;
void* __cdecl FUN_00dfd930();
extern int DAT_0126c4b8;
int* __cdecl FUN_00dfd950();
extern int DAT_010e33dc;
struct FUN_00dfd990_class {
    void* vtable;
    int field04;
    int field08;
    int field0c;
    int field10;
    FUN_00cb0a70_class field14;
};
void __cdecl FUN_00dfd990(FUN_00dfd990_class* object, int value);
extern int DAT_0126c500;
void* FUN_00dfda40();
struct S_00e3f510_Foo {
    void __thiscall FUN_00e3f510(int);
};
void __cdecl FUN_00dfda50(void* p, int a);
extern int DAT_0126c530;
int* __cdecl FUN_00dfdaa0();
struct AdjacentObjects {
    FUN_00cb0c00_class first;
    __declspec(align(4)) FUN_00cb0c00_class second;
};
void __cdecl FUN_00dfdab0(AdjacentObjects* objects);
extern int DAT_0126c578;
void* __cdecl FUN_00dfdaf0();
// FUN_00dfdb10 : a one-line function - getter
extern int g_target_00dfdb10;
void* FUN_00dfdb10();
extern int DAT_0126c5f0;
void* __cdecl FUN_00dfdb30();
extern int DAT_010e351c;
int* __cdecl FUN_00dfdb60();
extern "C" void* DAT_010e352c;
void* __cdecl FUN_00dfdb80();
extern int DAT_0126c638;
int* FUN_00dfdd20();
extern int DAT_0126c668;
int __cdecl FUN_00dfdd80();
extern int DAT_0126c698;
int* __cdecl FUN_00dfddc0();
extern int DAT_0126c6c8;
void* FUN_00dfdde0();
struct CpuOpaque;
extern CpuOpaque DAT_0126c6f8;
CpuOpaque* __cdecl FUN_00dfde00();
struct FUN_00dfde10_vtable {
    virtual void __thiscall slot0(int value) {}
};
void __cdecl FUN_00dfde10(void* p);
extern int DAT_0126c728;
int __cdecl FUN_00dfde20();
extern int DAT_010d3cc0;
int* __cdecl FUN_00dfde50();
extern char DAT_0126c770;
char* __cdecl FUN_00dfde70(void);
extern int DAT_0126c7a0;
void* __cdecl FUN_00dfde90();
struct CpuOpaque;
extern CpuOpaque DAT_0126c7d0;
CpuOpaque* __cdecl FUN_00dfdeb0();
// FUN_00dfdec0: null-guarded forwarding of a second argument to a
// member function of the first (object) argument.
class FUN_00dfdec0_cls
{
public:
    void FUN_00e0bf30(int a1);
};
void __cdecl FUN_00dfdec0(FUN_00dfdec0_cls *pObject, int a1);
extern unsigned char DAT_0126c800;
void* __cdecl FUN_00dfdee0();
// FUN_00dfdef0: null-guarded forwarding of a second argument to a
// member function of the first (object) argument.
class FUN_00dfdef0_cls
{
public:
    void FUN_00e0f700(int a1);
};
void __cdecl FUN_00dfdef0(FUN_00dfdef0_cls *pObject, int a1);
extern int g_unk0126c830;
void* __cdecl FUN_00dfdf10();
extern int DAT_0126c860;
int* __cdecl FUN_00dfdf30();
struct CpuOpaque;
extern CpuOpaque DAT_0126c890;
CpuOpaque* __cdecl FUN_00dfdf40();
class DFDF50Object {
public:
    virtual ~DFDF50Object();
};
void __cdecl FUN_00dfdf50(DFDF50Object* pkObject);
extern int DAT_0126c8c0;
int* __cdecl FUN_00dfdf60();
extern int DAT_010e3e5c;
int* __cdecl FUN_00dfdfc0();
struct FUN_00ddc870_class {
    void __thiscall FUN_00ddc870();
};
void __cdecl FUN_00dfdfd0(FUN_00ddc870_class* self);
extern int DAT_0126c908;
int* __cdecl FUN_00dfe090();
extern int DAT_0126c938;
void* __cdecl FUN_00dfe0a0();
extern int DAT_0126c968;
void* __cdecl FUN_00dfe0e0();
extern int DAT_0126c998;
void* __cdecl FUN_00dfe100();
// FUN_00dfe120 : a one-line function - getter
extern int g_target_00dfe120;
void* FUN_00dfe120();
extern int DAT_0126c9f8;
void* __cdecl FUN_00dfe140();
// FUN_00dfe160 : a one-line function - getter
extern int g_target_00dfe160;
void* FUN_00dfe160();
extern int DAT_0126ca58;
int* __cdecl FUN_00dfe180();
extern int DAT_0126ca88;
int __cdecl FUN_00dfe1a0();
extern int DAT_0126cab8;
int* __cdecl FUN_00dfe1c0();
extern int DAT_0126cae8;
void* __cdecl FUN_00dfe1e0();
extern int DAT_0126cb18;
void* __cdecl FUN_00dfe1f0();
// FUN_00dfe250: null-guarded forwarding of a second argument to a
// non-virtual member function of the first (object) argument.
class FUN_00dfe250_cls
{
public:
    void Forward(int a1);
};
void __cdecl FUN_00dfe250(FUN_00dfe250_cls *pObject, int a1);
// FUN_00dfe2a0: cdecl, returns the address of a global object.
extern char g_unk0126cb48;
void* __cdecl FUN_00dfe2a0();
extern void* DAT_0126cb90;
int __cdecl FUN_00dfe2c0();
// FUN_00dfe330 : a one-line function - getter
extern int g_target_00dfe330;
void* FUN_00dfe330();
extern int DAT_010e5474;
unsigned int __cdecl FUN_00dfe350();
// Helper object whose virtual-like member performs the work.
struct FUN_00cb0a70_obj {
    void __thiscall m_00cb0a70(int value);
};
void __cdecl FUN_00dfe410(FUN_00cb0a70_obj* pObject, int value);
// FUN_00dfe460 : a one-line function - getter
extern int g_target_00dfe460;
void* FUN_00dfe460();
void __cdecl FUN_00dfe470(FUN_00dfe430_class* p);
extern int DAT_0126cc68;
void* __cdecl FUN_00dfe480();
// FUN_00dfe4f0: cdecl, returns the address of a global object.
extern char g_unk0126ccb0;
void* __cdecl FUN_00dfe4f0();
extern int DAT_010e57a4;
int* FUN_00dfe510();
// FUN_00dfe5a0: cdecl, returns the address of a global object.
extern char g_unk0126ccf8;
void* __cdecl FUN_00dfe5a0();
struct CpuOpaque;
extern CpuOpaque DAT_0126cd40;
CpuOpaque* __cdecl FUN_00dfe680();
extern int DAT_010e58c8;
int* __cdecl FUN_00dfe6a0();
struct FUN_00dfe6e0_Class {
    virtual void vf00(int value);
};
void __cdecl FUN_00dfe6e0(FUN_00dfe6e0_Class* param_1);
extern unsigned char DAT_0126cd88;
void* __cdecl FUN_00dfe6f0();
extern int DAT_010e59ac;
int __cdecl FUN_00dfe710();
struct FUN_00dfe970_class {
    virtual void __thiscall m_iWordAt00(int);
};
void __cdecl FUN_00dfe970(FUN_00dfe970_class* p);
extern int g_unk0126cdd0;
void* __cdecl FUN_00dfe980();
extern int DAT_0126ce18;
int __cdecl FUN_00dfeab0();
extern int DAT_010dec04;
extern int DAT_010e5ae4;
extern int DAT_010c925c;
extern int DAT_010debf4;
extern int DAT_010debe4;
void __cdecl InitObjectVtables(int* p, int b);
extern int DAT_010e5ae4;
int* FUN_00dfeb00();
extern int DAT_0126ce60;
int* __cdecl FUN_00dfeb50();
extern int DAT_010e5b68;
int* __cdecl FUN_00dfeb70();
extern int DAT_0126cea8;
int* __cdecl FUN_00dfebc0();
extern int DAT_010e5b4c;
int* __cdecl FUN_00dfebe0();
extern int DAT_0126cef0;
int* __cdecl FUN_00dfec00();
extern int DAT_010e5bfc;
int* __cdecl FUN_00dfec20();
// FUN_00dfec40 : a constant getter - MSVC emits mov eax, OFFSET <global> ; ret.
// The global is declared extern so the store becomes a relocation; the checker
// binds it to the original's own immediate.
extern int g_target_FUN_00dfec40;
void* __cdecl FUN_00dfec40();
class DFEC50Object {
public:
    virtual ~DFEC50Object();
};
void __cdecl FUN_00dfec50(DFEC50Object* pkObject);
// FUN_00dfec60 : a one-line function - getter
extern int g_target_00dfec60;
void* FUN_00dfec60();
// FUN_00dfec80: cdecl, returns the address of a global data symbol.
extern int DAT_010e5d94;
int* __cdecl FUN_00dfec80();
extern int DAT_010e5da8;
void* __cdecl FUN_00dfeca0();
extern int DAT_0126cfc8;
void* __cdecl FUN_00dfecc0();
extern int DAT_010e5e9c;
int* __cdecl FUN_00dfece0();
// FUN_00dfed00 : a one-line function - getter
extern int g_target_00dfed00;
void* FUN_00dfed00();
int* FUN_00dfed20();
extern int DAT_0126d058;
int __cdecl FUN_00dfedf0();
extern int DAT_010e60c4;
int* __cdecl FUN_00dfee10();
extern int DAT_0126d0a0;
int* __cdecl FUN_00dfee90();
extern int DAT_010e62a4;
void* __cdecl FUN_00dfeeb0();
extern int DAT_0126d0e8;
int __cdecl FUN_00dfeed0();
extern int DAT_010e6394;
int* __cdecl FUN_00dfeef0();
extern int DAT_0126d130;
void* __cdecl FUN_00dfef10();
extern int DAT_010debf4;
int __cdecl FUN_00dfef40();
class DFEF80Object {
public:
    virtual ~DFEF80Object();
};
void FUN_00dfef80(DFEF80Object* pkObject);
// FUN_00dfefc0: returns the address of the global object at DAT_0126d190.
extern int DAT_0126d190;
int* FUN_00dfefc0();
// FUN_00dfefd0 : cdecl, 13 bytes
// Calls slot 0 of the object's vtable with the argument 0 and returns the result.
struct FUN_00dfefd0_cls
{
    virtual int v00(int a);
};
int __cdecl FUN_00dfefd0(FUN_00dfefd0_cls* pObj);
extern int DAT_0126d1d8;
void* __cdecl FUN_00dfefe0();
extern int DAT_010e66fc;
int* __cdecl FUN_00dff000();
struct FUN_00dff0b0_class {
    virtual void m0(int);
};
void __cdecl FUN_00dff0b0(FUN_00dff0b0_class* p);
extern int DAT_0126d220;
void* __cdecl FUN_00dff0c0();
extern int DAT_010e676c;
int* __cdecl FUN_00dff0e0();
struct FUN_00dff120_Class {
    virtual void vf00(int value);
};
void __cdecl FUN_00dff120(FUN_00dff120_Class* param_1);
// Getter returning the address of a global object.
extern int DAT_0126d268;
int* __cdecl FUN_00dff160();
// Null-guarded forwarder: the first argument is an object pointer; when it is
// non-null the second argument is passed to a member function of that object.
struct FUN_00dff170_cls
{
    void __thiscall FUN_00e45010(int a1);
};
void __cdecl FUN_00dff170(FUN_00dff170_cls *pObject, int a1);
struct FUN_00dff190_cls {
    virtual void m_v00(int arg);
};
void __cdecl FUN_00dff190(FUN_00dff190_cls* pObject);
extern int DAT_0126d298;
int __cdecl FUN_00dff1c0();
extern int DAT_0126d2f8;
int __cdecl FUN_00dff1e0();
struct FUN_00dff250_class {
    virtual void m0(int);
};
void __cdecl FUN_00dff250(FUN_00dff250_class* p);
extern int DAT_0126d328;
void* __cdecl FUN_00dff260();
struct DFF2E0FinishFlag {
    int m_bFinishing;
};
class DFF2E0Object {
public:
    DFF2E0Object(DFF2E0FinishFlag flag);

    static void* operator new(unsigned int, void* p) { return p; }
};
void FUN_00dff2e0(void* p, int finishing);
extern int DAT_0126d370;
int* __cdecl FUN_00dff330();
extern int DAT_0126d3d0;
int __cdecl FUN_00dff3b0();
extern int DAT_0126d418;
int* __cdecl FUN_00dff3d0();
struct CpuOpaque;
extern CpuOpaque DAT_010e6dec;
CpuOpaque* __cdecl FUN_00dff430();
struct FUN_00e46300_class {
    void __thiscall FUN_00e46300(int);
};
void __cdecl FUN_00dff4c0(FUN_00e46300_class* p, int a);
struct DFF4E0Object {
    virtual void Destroy(bool bFree);
};
void FUN_00dff4e0(DFF4E0Object* pkObject);
extern unsigned char DAT_0126d448;
void* __cdecl FUN_00dff510();
struct DFF520FinishFlag {
    int m_bFinishing;
};
class DFF520Object {
public:
    DFF520Object(DFF520FinishFlag flag);

    static void* operator new(unsigned int, void* p) { return p; }
};
void FUN_00dff520(void* p, int finishing);
extern int DAT_0126d490;
int __cdecl FUN_00dff570();
struct CpuOpaque;
extern CpuOpaque DAT_0126d4d8;
CpuOpaque* __cdecl FUN_00dff590();
struct CpuOpaque;
extern CpuOpaque DAT_0126d508;
CpuOpaque* __cdecl FUN_00dff5b0();
extern int DAT_0126d550;
void* __cdecl FUN_00dff5d0();
extern int DAT_010e75cc;
int* __cdecl FUN_00dff5f0();
extern int DAT_010e75dc;
int* __cdecl FUN_00dff610();
extern int DAT_010e75ec;
int __cdecl FUN_00dff630();
// Helper class: the object's first virtual slot takes a single int argument.
class FUN_00dff870_cls
{
public:
    virtual int v0(int a) = 0;
};
int __cdecl FUN_00dff870(FUN_00dff870_cls* p);
extern int DAT_0126d5c8;
int* __cdecl FUN_00dff880();
// FUN_00dff890: forwards a second argument to a method of the first argument
// when that pointer is non-null.
struct FUN_00dff890_cls
{
    void __thiscall InitializeRecordPointers(int a);
};
void __cdecl FUN_00dff890(FUN_00dff890_cls* pObject, int aValue);
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
struct FNVRecordPointers {
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
void* __cdecl FUN_00dffa20();
extern int g_unk0126d658;
void* __cdecl FUN_00dffa40();
// FUN_00dffa50: forwards a value to a helper on the passed-in object
// when that object is present.
struct FUN_00dffa50_cls
{
    void __thiscall FUN_00dffa90(int value);
};
void __cdecl FUN_00dffa50(FUN_00dffa50_cls* pObject, int value);
struct DFFA90FinishFlag {
    int m_bFinishing;
};

class DFFA90ListenerA {
public:
    DFFA90ListenerA(DFFA90FinishFlag) {}
    virtual ~DFFA90ListenerA();
};
class DFFA90ListenerB {
public:
    DFFA90ListenerB(DFFA90FinishFlag) {}
    virtual ~DFFA90ListenerB();
};
class DFFA90ListenerC {
public:
    DFFA90ListenerC(DFFA90FinishFlag) {}
    virtual ~DFFA90ListenerC();
};
class DFFA90ListenerD {
public:
    DFFA90ListenerD(DFFA90FinishFlag) {}
    virtual ~DFFA90ListenerD();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};
class DFFA90ListenerE {
public:
    DFFA90ListenerE(DFFA90FinishFlag) {}
    virtual ~DFFA90ListenerE();
};
class FUN_00dffa90 : public hkReferencedObject,
                     public DFFA90ListenerA,
                     public DFFA90ListenerB,
                     public DFFA90ListenerC,
                     public DFFA90ListenerD,
                     public DFFA90ListenerE {
public:
    FUN_00dffa90(DFFA90FinishFlag flag);
    virtual ~FUN_00dffa90();
};
class FUN_00dffba0_cls {
public:
    virtual void v0(int arg);
};
void __cdecl FUN_00dffba0(FUN_00dffba0_cls* p);
extern int DAT_0126d688;
int* __cdecl FUN_00dffbd0();
extern int DAT_0126d6e8;
void* __cdecl FUN_00dffc50();
struct CpuOpaque;
extern CpuOpaque DAT_0126d718;
CpuOpaque* __cdecl FUN_00dffc70();
extern int DAT_010e7c24;
int* __cdecl FUN_00dffc90();
extern int DAT_0126d760;
void* FUN_00dffd90();
extern int DAT_010cc0d8;
int* __cdecl FUN_00dffdb0();
// FUN_00dffdd0 : a one-line function - getter
extern int g_target_00dffdd0;
void* FUN_00dffdd0();
extern int DAT_010c6e34;
void* FUN_00dffe10();
extern int DAT_0126d7f0;
void* __cdecl FUN_00dffe30();
extern int DAT_010d3838;
void* __cdecl FUN_00dffe50();
extern char g_unk0126d838;
void* __cdecl FUN_00dffe70();
extern void* DAT_010c59f4;
extern void* DAT_010c6d54;
void __cdecl FUN_00dffe80(void* p, int b);
// Helper class: the object's first virtual slot takes a single int argument.
class FUN_00dffec0_cls
{
public:
    virtual int v0(int a) = 0;
};
int __cdecl FUN_00dffec0(FUN_00dffec0_cls* p);
extern int DAT_0126d880;
void* __cdecl FUN_00dffed0();
extern int DAT_010cb798;
int* __cdecl FUN_00dffef0();
extern int DAT_0126d8c8;
int __cdecl FUN_00dfff10();
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
int* __cdecl FUN_00dfff50();
extern int DAT_0126d910;
int* __cdecl FUN_00dfff70();
struct S_00dfff80_Foo {
    void __thiscall FUN_00cdf760(int a);
};
void __cdecl CallFooMethodIfNotNull(S_00dfff80_Foo* p, int a);
// FUN_00dfffd0 : a one-line function - getter
extern int g_target_00dfffd0;
void* FUN_00dfffd0();
extern void* DAT_010e80b4;
void** __cdecl FUN_00dffff0();

extern "C" __m128 _mm_setzero_ps(void);



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
        m_kVec40.setZero4();
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



class DE1FC0Transform : public hkReferencedObject {
public:
    DE1FC0Transform()
    {
        m_ulUserData = 0;
        m_type = 2;
        m_rotation.setIdentity();
        m_vTranslation.setZero4();
    }

    int m_ulUserData;
    int unk0C;
    hkRotation m_rotation;
    hkVector4 m_vTranslation;
    int m_type;
    int unk54;
    int unk58;
    int unk5C;
};
class FUN_00de1fc0 : public DE1FC0Transform {
public:
    FUN_00de1fc0();
    virtual void vfunc01();

    hkVector4 m_extra;
};
// Return a copy of the stored 4-float value.

class DE5300Object {
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



class DE5450Shape : public hkReferencedObject {
public:
    DE5450Shape() : m_ulUserData(0), m_type(4) { m_kMotionTransform.setIdentity(); }

    int m_ulUserData;
    int unk0C;
    hkTransform m_kMotionTransform;
    int m_type;
    int unk54;
    int unk58;
    int unk5C;
};
class FUN_00de5450 : public DE5450Shape {
public:
    FUN_00de5450();
    virtual void unk00();

    hkVector4 m_vecA;
    hkVector4 m_vecB;
    int m_uiItemCount;
    float m_valueA;
    float m_valueB;
};

struct Matrix64 { hkVector4 a,b,c,d; };
struct Input {
 int count; float a,b; hkVector4 vector;
 unsigned* values; void* source; Matrix64* matrices; float scale; unsigned flags;
};
struct Header {
 union {float epsilon; unsigned char type;};
 unsigned short count,pad06;
 unsigned flags,unk0c,size;
 float scale,a,b;
};
void FUN_00df19e0(int,hkVector4*,Matrix64*,void*,void*,void*,void*,void*,int);
void WriteInputHeader(Input* input,void*,Header** cursor);
extern "C" const __m128 DAT_011b9490;
// @fnv 0x00df2740
extern "C" __m128 __cdecl FUN_00df2740() {
    return DAT_011b9490;
}
// which resets the runtime caches and re-links the embedded collidable to its owner.
struct DF6500FinishFlag {
    int m_bFinishing;
};
struct DF6500Collidable {
    int m_pCollisionShape;
    char m_type;
    signed char m_iOwnerOffset;
    short m_pad06;
    int m_unk08;
    void SetOwnerPointer(void* owner) { m_iOwnerOffset = (signed char)((unsigned int)owner - (unsigned int)this); }
};
struct DF6500Object {
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
void FUN_00df6500(void* p, int finishing);
struct BDFCA00FinishFlag {
    int m_bFinishing;
};
struct BDFCA00UpdateFlag {
    BDFCA00UpdateFlag(char cValue) : m_cValue(cValue) {}
    BDFCA00UpdateFlag(const BDFCA00UpdateFlag& kOther) : m_cValue(kOther.m_cValue) {}

    char m_cValue;
};
class BDFCA00Object {
public:
    __forceinline BDFCA00Object(BDFCA00FinishFlag kFlag)
    {
        if (kFlag.m_bFinishing && m_bModifierActive) {
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
void __cdecl FUN_00dfca00(void* pvObject, int iFinishing);
struct FnvCpu_FUN_00de1150_CpuObject { char* FUN_00de1150(); };
struct FnvCpu_FUN_00de1160_CpuObject { char* FUN_00de1160(); };
struct FnvCpu_FUN_00de4de0_CpuObject { char* FUN_00de4de0(); };
void* __fastcall FUN_00de4df0(char* self, int);
void __cdecl FUN_00de8140();
void __cdecl FUN_00de8160();
void __cdecl FUN_00de8180(void);
void FUN_00de81c0();
void FUN_00de81e0();
void __cdecl FUN_00de8200();
void FUN_00de8220();
void __cdecl FUN_00de8240();
void __cdecl FUN_00de8260();
void __cdecl FUN_00de8280();
void __cdecl FUN_00de82a0();
void __cdecl FUN_00de82c0();
void __cdecl FUN_00de82e0();
void __cdecl FUN_00de8300();
void __cdecl FUN_00de8320();
void __cdecl FUN_00de8340();
void __cdecl FUN_00de8360();
void __cdecl FUN_00de8380(void);
void __cdecl FUN_00de83a0();
void __cdecl FUN_00de83c0();
void FUN_00de83e0();
void FUN_00de8400();
void __cdecl FUN_00de8420();
void FUN_00de8440();
void FUN_00de8460();
void __cdecl FUN_00de8480();
void FUN_00de84a0();
void __cdecl FUN_00de84c0();
void __cdecl FUN_00de84e0();
void FUN_00de8500();
void FUN_00de8520();
void FUN_00de8540();
void FUN_00de8590();
void FUN_00de85a0();
void FUN_00de85b0();
void FUN_00de85c0();
void __cdecl FUN_00de85d0();
void FUN_00de85e0();
void __cdecl FUN_00de85f0();
void __cdecl FUN_00de8600(void);
void __cdecl FUN_00de8610();
void __cdecl FUN_00de8620();
void __cdecl FUN_00de8630();
void __cdecl FUN_00de8640();
void __cdecl FUN_00de8650();
void __cdecl FUN_00de8660();
void FUN_00de8670();
void __cdecl FUN_00de8680();
void FUN_00de8690();
void FUN_00de86a0();
void FUN_00de86b0();
void __cdecl FUN_00de86c0();
void FUN_00de86d0();
void __cdecl FUN_00de86e0();
void FUN_00de86f0();
void __cdecl FUN_00de8700();
void FUN_00de8710();
void FUN_00de8720();
void __cdecl FUN_00de8730();
void __cdecl FUN_00de8740();
void __cdecl FUN_00de8760();
struct stub_cls {
    int unk00;
};
static void FUN_00df30c0(stub_cls* self, int v);
extern "C" int stub_val(void);
void stub_caller(stub_cls* self);
struct DF30D0Pair { unsigned int m_ucLowNibble; unsigned int m_ucHighNibble; };
static void CopyPairAtIndex(DF30D0Pair* dst, unsigned int idx, const DF30D0Pair* src);
void DF30D0Caller(DF30D0Pair* dst, unsigned int idx, const DF30D0Pair* src);
void FUN_00df3160();
void FUN_00df64a0();
void __cdecl FUN_00df6540();
struct FUN_00df7210_Inner {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int m14;
};
struct FUN_00df7210_Class {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00df7210_Inner* m10;
    char* __thiscall FUN_00df7210(char* out);
};
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern unsigned long DAT_0126835c;
extern char DAT_010dba3c[];
extern char DAT_010c41f8[];
static inline void TimerCommandKdWrite(const char* name)
{
    hkMonitorStream* s = static_cast<hkMonitorStream*>(TlsGetValue(DAT_0126835c));
    if (s->m_end.m_storage < s->m_capacityMinus16.m_storage) {
        hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(s->m_end.m_storage);
        h->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        h->m_time0 = t;
        s->m_end.m_storage = (char*)(h + 1);
    }
}
struct KdPair { int m_kPointA; int m_kPointB; };
struct KdJob {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int m_20;
    int m_24;
    int m_28;
    int* m_2c;
    int m_30;
    int m_34;
    KdPair m_38;
};
struct KdQueue {
    int FinishJob(const KdJob* a, const KdJob* b, int flag);
};
void __cdecl MixChannels(KdPair* p, int a2, int a3, int a4, int a5, int a6, int* out);
int __cdecl FinishJobWithPair(KdQueue* queue, KdJob* job);
struct FnvCpu_FUN_00df8920_CpuObject {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    float value;
    float FUN_00df8920();
};
void __cdecl FUN_00df9870();
void FUN_00df9b10();
void __cdecl FUN_00dfb250();
void FUN_00dfb350();
void FUN_00dfb370();
void FUN_00dfb4b0();
void __cdecl FUN_00dfb4c0();
void __cdecl FUN_00dfb4e0();
void __cdecl FUN_00dfb500(void);
void __cdecl FUN_00dfb520();
void FUN_00dfb530();
void __cdecl FUN_00dfb850();
void __cdecl FUN_00dfb870();
void __cdecl FUN_00dfb910();
void FUN_00dfb930(void);
void __cdecl FUN_00dfb9c0();
void __cdecl FUN_00dfbab0();
void FUN_00dfbb00();
void __cdecl FUN_00dfbb10();
void __cdecl FUN_00dfbcb0();
void __cdecl FUN_00dfbdb0();
void __cdecl FUN_00dfbe80();
void FUN_00dfbea0();
void FUN_00dfbec0();
void FUN_00dfbee0();
void __cdecl FUN_00dfbf00();
void __cdecl FUN_00dfbf10();
void FUN_00dfc020();
void FUN_00dfc0f0();
void FUN_00dfc210();
void __cdecl FUN_00dfc270();
void FUN_00dfc3c0();
void __cdecl FUN_00dfc3d0();
void __cdecl FUN_00dfc430(void);
void __cdecl FUN_00dfc4c0();
void __cdecl FUN_00dfc4e0();
void FUN_00dfc570();
void FUN_00dfc580();
void __cdecl FUN_00dfc5a0();
void FUN_00dfc5c0();
void __cdecl FUN_00dfc5e0();
void FUN_00dfc640();
void __cdecl FUN_00dfc650();
void FUN_00dfc670();
void FUN_00dfc6b0();
void __cdecl FUN_00dfc6e0();
void __cdecl FUN_00dfc720(void);
void __cdecl FUN_00dfc750();
void __cdecl FUN_00dfc7d0();
void __cdecl FUN_00dfc8b0();
void __cdecl FUN_00dfc8f0();
void FUN_00dfc920();
void FUN_00dfc960();
void __cdecl FUN_00dfc9b0();
void FUN_00dfc9f0();
void __cdecl FUN_00dfca40();
void __cdecl FUN_00dfca80();
void __cdecl FUN_00dfcab0();
void FUN_00dfcaf0();
void __cdecl FUN_00dfcb20(void);
void FUN_00dfcba0();
void __cdecl FUN_00dfcbe0();
void __cdecl FUN_00dfcc10();
void __cdecl FUN_00dfcc50();
void __cdecl FUN_00dfcc80();
void FUN_00dfccc0();
void __cdecl FUN_00dfccf0();
void __cdecl FUN_00dfcd30();
void FUN_00dfcd60();
void FUN_00dfcdc0();
void FUN_00dfce40();
void FUN_00dfce80();
void __cdecl FUN_00dfceb0();
void FUN_00dfced0();
void __cdecl FUN_00dfcee0();
void __cdecl FUN_00dfd0b0();
void __cdecl FUN_00dfd1a0();
void __cdecl FUN_00dfd220();
void __cdecl FUN_00dfd2b0();
void __cdecl FUN_00dfd340();
void FUN_00dfd350();
void __cdecl FUN_00dfd4d0();
void __cdecl FUN_00dfd4f0();
void __cdecl FUN_00dfd510();
void __cdecl FUN_00dfd520();
void __cdecl FUN_00dfd530();
void __cdecl FUN_00dfd550();
void __cdecl FUN_00dfd660();
void FUN_00dfd960();
void FUN_00dfddd0();
void FUN_00dfddf0();
void __cdecl FUN_00dfde60();
void __cdecl FUN_00dfde80();
void __cdecl FUN_00dfdea0();
void __cdecl FUN_00dfdf20();
void __cdecl FUN_00dfe080();
void __cdecl FUN_00dfe0b0();
void __cdecl FUN_00dfe0d0(void);
void FUN_00dfe0f0();
void FUN_00dfe110();
void FUN_00dfe130();
void FUN_00dfe150();
void FUN_00dfe170();
void FUN_00dfe190();
void FUN_00dfe1b0();
void __cdecl FUN_00dfe1d0();
void __cdecl FUN_00dfe200();
struct FnvCpu_FUN_00dfee80_CpuInterface {
    virtual void Invoke(int value);
};
void __cdecl FUN_00dfee80(FnvCpu_FUN_00dfee80_CpuInterface* object);
struct DestructibleDFF {
    virtual ~DestructibleDFF();
};
void __cdecl FUN_00dff5a0(DestructibleDFF* pkObject);
struct S00de0fe0_Element {
    virtual void vf00(int value);
};
struct S00de0fe0_Arr {
    S00de0fe0_Element** data;
    int count;
    int cap;
    void __thiscall FUN_00ddfb70();
};
struct S00de0fe0_Obj10 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void __thiscall FUN_00ddfb80(int* value);
    void __thiscall FUN_00de0f90(int count, S00de0fe0_Element*** array);
};
struct S00de0fe0_Local {
    S00de0fe0_Arr arr;
    S00de0fe0_Obj10 o;
};
struct S00de0fe0_C983Obj {
    void __thiscall ForEachCall(int* a, int b, int c, int d, int e);
};
extern void* DAT_012681e0;
__declspec(noinline) void S00de0fe0_Arr::FUN_00ddfb70() {
    count = 0;

}
void __cdecl FUN_00de0fe0(int arg1, int arg2, int arg3, int arg4);
class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_01269fe8;
GlobalObjectO2_00d472a0* __cdecl FUN_00de8370();
struct cls_d530
{
    int unk00;
    float m_04;
};
extern "C" cls_d530* d530_target(void);
static void FUN_00def530(float value, cls_d530* target);
void d530_caller(cls_d530* self, float f);
struct d540_cls
{
    float unk00;
    float unk04;
};
extern "C" d540_cls* d540_target(void);
static void FUN_00def540(float a, float b, d540_cls* t);
void d540_caller(float fa, float fb);

extern "C" hkVector4* def550_target(void);
static void SetVec4(float a, float b, float c, float d, hkVector4* t);
void def550_caller(float a, float b, float c, float d);
void FUN_00df0690();
static void FUN_00df30a0(int* piTarget, int iValue);
void E30A0Store(int* piTarget, int iValue);
struct ProfileEvent {
    const void* volatile label;
    unsigned int cycles;
    unsigned int extra;
};
struct ThreadProfile {
    void* owner;
    ProfileEvent* next;
    unsigned int capacity;
    ProfileEvent* end;
};
struct WorkItem {
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    int remaining;
    unsigned int value;
    int processed;
    unsigned int unk2c;
};
struct WorkQueue {
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    unsigned int unk20;
    WorkItem* tasks;
    int taskCount;
    int processorCount;
    void* processors[1];
};
struct ExecutionContext {
    void ProcessCallback(WorkQueue* source, WorkQueue* target, int flags);
};
extern unsigned long DAT_0126835c;
extern "C" const char str_010db918[];
extern "C" const char str_010c41f8[];
int __cdecl FUN_00d1b930(void* processor, WorkItem* item, unsigned int* value, int remaining);
void __cdecl ProcessWorkQueue(ExecutionContext* context, WorkQueue* queue);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned long DAT_0126835c;

__forceinline hkMonitorStream* hkMonitorStream::getInstancePtr()
{
    return static_cast<hkMonitorStream*>(TlsGetValue(DAT_0126835c));
}
static inline void TimerMark(const char* name)
{
    hkMonitorStream* s = hkMonitorStream::getInstancePtr();
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
void __cdecl FUN_00df6e00(Job* job, int a, int b, int c);
struct Scheduler
{
    int ProcessCallback(Key* key, int b, int a);
};
void __cdecl FUN_00df6f80(Scheduler* self, Job* job);
struct FUN_00df9840_Class {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* member10;
    int unk14;
    volatile long* member18;
    void FUN_00df9840();
};
extern double DAT_010229b8;
extern "C" unsigned int df9ae0_val(void);
static float FUN_00df9ae0(unsigned int state);
volatile float df9ae0_sink;
void q_call_df9ae0(void);
static int g_w1 = 1;
static int g_ws = 3;
static float g_wv = 1.0f;
static __declspec(noinline) float FUN_00df9ae0(void)
{
    g_w1 = (g_w1 * 3) << (g_ws & 31);
    return g_wv;
}
static void WriteFloatToVector(float a, float b, float* out);
void dummy_caller(void);
hkMemoryRouter* __cdecl FUN_00c85750() throw();
struct FUN_00dfb5a0_cls {
    int unk00;
    char* m_pData;
    int m_iArrayLength;
    unsigned int m_uCap;

    void FUN_00dfb5a0();
};
template <class T>
inline void DestructElementsDFB5A0(T* p, int n)
{
    for (int i = 0; i < n; ++i) {
        p[i].FUN_00cb0c00();
    }
}
struct ElemDFB5A0 { int unk00; FUN_00cb0c00_class m_04; void FUN_00cb0c00() { m_04.FUN_00cb0c00(); } };
void __cdecl ResizeAudioStream(hkMemoryAllocator* alloc, void* array, int sizeOfElement);
// Registry entries store a pointer and an integer key; shared Pair stores two integers and has no pointer constructor.
struct FilterRegistryEntry {
    void* m_uiFilterValue;
    int m_key;
    FilterRegistryEntry(void* value, int key) : m_uiFilterValue(value), m_key(key) {}
};
struct Registry_de30 {
    int unk00, unk04;
    hkArray<FilterRegistryEntry> m_pairs;
    void FUN_00de30a0(void* value, int key);
};
void __cdecl FUN_00de9b00();
static void FUN_00df30b0(stub_cls* target, int value);
void df30b0_caller(stub_cls* target);
static void FUN_00df30f0(__m128* d, int idx, const __m128* s);
void hcaller(__m128* d, int idx, const __m128* s);
struct FNVVec16 {
    unsigned int m_u0;
    unsigned int m_u1;
    unsigned int m_u2;
    unsigned int m_u3;
};
__declspec(align(16)) struct FNVQuad {
    unsigned int m_u0;
    unsigned int m_u1;
    unsigned int m_u2;
    unsigned int m_u3;
};
struct FNVPair8 {
    unsigned int m_uiKey;
    int m_iArrayLength;
};
int FUN_00df3330(FNVPair8* out, FNVVec16* src, __m128* dst, unsigned int index, unsigned int n, int count);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_unpacklo_ps(__m128, __m128);
extern "C" __m128 _mm_unpackhi_ps(__m128, __m128);
extern "C" __m128 _mm_movelh_ps(__m128, __m128);
extern "C" __m128 _mm_movehl_ps(__m128, __m128);


__forceinline const hkVector4& hkRotation::getColumn(int index) const
{
    return (&m_kColumn0)[index];
}
__forceinline void hkVector4::_setMul3(const hkRotation& m, const hkVector4& v)
{
    const __m128 v0 = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x00);
    const __m128 v1 = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x55);
    const __m128 v2 = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xaa);
    const __m128 r0 = _mm_mul_ps(m.m_kColumn0.m_vComponents, v0);
    const __m128 r1 = _mm_mul_ps(m.m_kColumn1.m_vComponents, v1);
    const __m128 r2 = _mm_mul_ps(m.m_kColumn2.m_vComponents, v2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}
__forceinline void hkVector4::_setRotatedInverseDir(const hkRotation& m, const hkVector4& v)
{
    __m128 c0 = m.m_kColumn0.m_vComponents;
    __m128 c1 = m.m_kColumn1.m_vComponents;
    __m128 c2 = m.m_kColumn2.m_vComponents;
    __m128 tmp = _mm_unpacklo_ps(c0, c1);
    __m128 ctmp = _mm_unpackhi_ps(c0, c1);
    c0 = _mm_movelh_ps(tmp, c2);
    tmp = _mm_movehl_ps(c0, tmp);
    c1 = _mm_shuffle_ps(tmp, c2, 0xd4);
    c2 = _mm_shuffle_ps(ctmp, c2, 0xe4);
    const __m128 b0 = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x00);
    const __m128 r0 = _mm_mul_ps(c0, b0);
    const __m128 b1 = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x55);
    const __m128 r1 = _mm_mul_ps(c1, b1);
    const __m128 b2 = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xaa);
    const __m128 r2 = _mm_mul_ps(c2, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}
struct OutRef { hkVector4* p; hkVector4* operator->() const { return p; } };
struct Jac {
    hkMatrix3 m0;      // 0x00
    hkVector4 unk30;
    hkMatrix3 unk40;   // 0x40
    hkVector4 unk70;
    hkMatrix3 m1;      // 0x80
    hkVector4 unkB0;
    hkMatrix3 unkC0;   // 0xC0
    hkVector4 unkF0;
    hkRotation rot;    // 0x100
    hkVector4 unk130;
};
void __cdecl FUN_00df5e80(const Jac* j, const hkVector4* a, const hkVector4* b, OutRef out);
struct Obj_df7a90 {
    unsigned char m_ucType;
    char unk01;
    char unk02;
    char unk03;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int* m_piRefCount;
    void FUN_00df7a60();
};
int __cdecl FUN_00df7a90(int iArg0, int iArg1, Obj_df7a90* pkObj);
struct SDF7_Cmd16 { int a; int b; int c; int d; };
struct SDF7_Cmd32 { SDF7_Cmd16 lo; SDF7_Cmd16 hi; };
struct SDF7_Cmd48 { SDF7_Cmd16 a; SDF7_Cmd16 b; SDF7_Cmd16 c; };
struct SDF7_Cmd64 { SDF7_Cmd32 lo; SDF7_Cmd32 hi; };
struct SDF7_Job {
    unsigned char m_ucSubType;
    unsigned char m_type;
    unsigned short m_iElementCount;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
struct SDF7_Job4 : SDF7_Job {
    int m_iCommandCapacity;
    SDF7_Cmd48* m_pCommands;
    int m_iCommandCount;
};
struct SDF7_Job1 : SDF7_Job {
    int unk20;
    int m_iCommandCapacity;
    SDF7_Cmd32* m_pCommands;
    int m_iCommandCount;
};
struct SDF7_Job2 : SDF7_Job {
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int m_iCommandCapacity;
    SDF7_Cmd16* m_pCommands;
    int m_iCommandCount;
};
struct SDF7_Job3 : SDF7_Job {
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int m_iCommandCapacity;
    SDF7_Cmd64* m_pCommands;
    int m_iCommandCount;
};
struct SDF7_Job0 : SDF7_Job {
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int m_iCommandCapacity;
    SDF7_Cmd48* m_pCommands;
    int m_iCommandCount;
};
struct SDF7_JobQueueEntry : SDF7_Job {
    int m_data[24];
};
__forceinline void SDF7_memCpy16NonEmpty(void* dst, const void* src, int numQuads)
{
    const unsigned int* src32 = (const unsigned int*)src;
    unsigned int* dst32 = (unsigned int*)dst;
    do
    {
        dst32[0] = src32[0];
        dst32[1] = src32[1];
        dst32[2] = src32[2];
        dst32[3] = src32[3];
        src32 += 4;
        dst32 += 4;
    } while (--numQuads > 0);
}
template <class T>
__forceinline int SDF7_split(SDF7_JobQueueEntry& jobIn, SDF7_JobQueueEntry& jobOut)
{
    T& onQueue = static_cast<T&>(static_cast<SDF7_Job&>(jobIn));
    T& out = static_cast<T&>(static_cast<SDF7_Job&>(jobOut));
    if (onQueue.m_iCommandCount > onQueue.m_iCommandCapacity)
    {
        out.m_iCommandCount = onQueue.m_iCommandCapacity;
        onQueue.m_iCommandCount -= onQueue.m_iCommandCapacity;
        onQueue.m_pCommands += onQueue.m_iCommandCapacity;
        return 1;
    }
    return 0;
}
int __cdecl SplitJob(void* queue, void* data, SDF7_JobQueueEntry& jobIn, SDF7_JobQueueEntry& jobOut);
extern char DAT_010dba24[];
struct KdJob2 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    float m_38;
    float m_3c;
    KdPair m_40;
    int m_48;
    int m_4c;
    int m_50;
};
struct KdQueue2 {
    int ProcessCallback(const KdJob2* a, const KdJob2* b, int flag);
};
void __cdecl FUN_00e29cd0(int, int, int, int, int, float, float, KdPair, int*, int, int*);
void __cdecl FUN_00e2a010(int, int, int, int, float, float, KdPair, int*, int, int*);
int __cdecl ExecuteJob(KdQueue2* queue, KdJob2* job);
struct InDF8800 {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c;
    void** m_ppGeometries;      // 0x50
    int m_i0x54;
    int m_i0x58;
    int m_iArrayLength;           // 0x5c
};
struct ArrDF8800 {
    ~ArrDF8800()
    {
        hkMemoryAllocator* pkAllocator = reinterpret_cast<hkMemoryAllocator*>(FUN_00c85750()->m_heap);
        int iCapacityAndFlags = m_iCapacityAndFlags;
        m_uiLogicalSize = 0;
        if ((iCapacityAndFlags & 0x80000000) == 0)
            pkAllocator->bufFree(m_ppGeometries, (iCapacityAndFlags & 0x3fffffff) * 4);
        m_ppGeometries = 0;
        m_iCapacityAndFlags = 0x80000000;
    }
    void** m_ppGeometries;      // 0x00
    int m_uiLogicalSize;            // 0x04
    int m_iCapacityAndFlags;// 0x08
};
struct CollDF8800 {
    CollDF8800(ArrDF8800& kArray, int iFlags) throw();
    virtual ~CollDF8800() {}
    ArrDF8800* m_pkArray;   // 0x04
    int m_iFlags;           // 0x08
};
void __cdecl FillAabbArray(CollDF8800* pkCollector, int i0x58, int iCount, int i0x54) throw();
struct WorldDF8800 {
    void* ProcessCallback(InDF8800* pkSource, InDF8800* pkTarget, int iFlags) throw();
};
void* FUN_00df8800(WorldDF8800* pkWorld, InDF8800* pkInput);
struct Param3Struct {
    unsigned char unk00;
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
};
unsigned int __cdecl CopyAndAdvance(unsigned int param_1, unsigned int param_2, char* param_3, int* param_4);
struct DFB0B0_Entry {
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
    float distance;
    int unk44;
    int unk48;
    int unk4c;
};
struct DFB0B0_Owner {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int numEntries;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    int unk884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    int unk8b8;
    int unk8bc;
    int unk8c0;
    int unk8c4;
    int unk8c8;
    int unk8cc;
    int unk8d0;
    int unk8d4;
    int unk8d8;
    int unk8dc;
    int unk8e0;
    int unk8e4;
    int unk8e8;
    int unk8ec;
    int unk8f0;
    int unk8f4;
    int unk8f8;
    int unk8fc;
    int unk900;
    int unk904;
    int unk908;
    int unk90c;
    int unk910;
    int unk914;
    int unk918;
    int unk91c;
    int unk920;
    int unk924;
    int unk928;
    int unk92c;
    int unk930;
    int unk934;
    int unk938;
    int unk93c;
    int unk940;
    int unk944;
    int unk948;
    int unk94c;
    int unk950;
    int unk954;
    int unk958;
    int unk95c;
    int unk960;
    int unk964;
    int unk968;
    int unk96c;
    int unk970;
    int unk974;
    int unk978;
    int unk97c;
    int unk980;
    int unk984;
    int unk988;
    int unk98c;
    int unk990;
    int unk994;
    int unk998;
    int unk99c;
    int unk9a0;
    int unk9a4;
    int unk9a8;
    int unk9ac;
    int unk9b0;
    int unk9b4;
    int unk9b8;
    int unk9bc;
    int unk9c0;
    int unk9c4;
    int unk9c8;
    int unk9cc;
    int unk9d0;
    int unk9d4;
    int unk9d8;
    int unk9dc;
    int unk9e0;
    int unk9e4;
    int unk9e8;
    int unk9ec;
    int unk9f0;
    int unk9f4;
    int unk9f8;
    int unk9fc;
    int unka00;
    int unka04;
    int unka08;
    int unka0c;
    int unka10;
    int unka14;
    int unka18;
    int unka1c;
    int unka20;
    int unka24;
    int unka28;
    int unka2c;
    int unka30;
    int unka34;
    int unka38;
    int unka3c;
    int unka40;
    int unka44;
    int unka48;
    int unka4c;
    int unka50;
    int unka54;
    int unka58;
    int unka5c;
    int unka60;
    int unka64;
    int unka68;
    int unka6c;
    int unka70;
    int unka74;
    int unka78;
    int unka7c;
    int unka80;
    int unka84;
    int unka88;
    int unka8c;
    int unka90;
    int unka94;
    int unka98;
    int unka9c;
    int unkaa0;
    int unkaa4;
    int unkaa8;
    int unkaac;
    int unkab0;
    int unkab4;
    int unkab8;
    int unkabc;
    int unkac0;
    int unkac4;
    int unkac8;
    int unkacc;
    int unkad0;
    int unkad4;
    int unkad8;
    int unkadc;
    int unkae0;
    int unkae4;
    int unkae8;
    int unkaec;
    int unkaf0;
    int unkaf4;
    int unkaf8;
    int unkafc;
    int unkb00;
    int unkb04;
    int unkb08;
    int unkb0c;
    int unkb10;
    int unkb14;
    int unkb18;
    int unkb1c;
    int unkb20;
    int unkb24;
    int unkb28;
    int unkb2c;
    int unkb30;
    int unkb34;
    int unkb38;
    int unkb3c;
    int unkb40;
    int unkb44;
    int unkb48;
    int unkb4c;
    int unkb50;
    int unkb54;
    int unkb58;
    int unkb5c;
    int unkb60;
    int unkb64;
    int unkb68;
    int unkb6c;
    int unkb70;
    int unkb74;
    int unkb78;
    int unkb7c;
    int unkb80;
    int unkb84;
    int unkb88;
    int unkb8c;
    int unkb90;
    int unkb94;
    int unkb98;
    int unkb9c;
    int unkba0;
    int unkba4;
    int unkba8;
    int unkbac;
    int unkbb0;
    int unkbb4;
    int unkbb8;
    int unkbbc;
    int unkbc0;
    int unkbc4;
    int unkbc8;
    int unkbcc;
    int unkbd0;
    int unkbd4;
    int unkbd8;
    int unkbdc;
    int unkbe0;
    int unkbe4;
    int unkbe8;
    int unkbec;
    int unkbf0;
    int unkbf4;
    int unkbf8;
    int unkbfc;
    int unkc00;
    int unkc04;
    int unkc08;
    int unkc0c;
    int unkc10;
    int unkc14;
    int unkc18;
    int unkc1c;
    int unkc20;
    int unkc24;
    int unkc28;
    int unkc2c;
    int unkc30;
    int unkc34;
    int unkc38;
    int unkc3c;
    int unkc40;
    int unkc44;
    int unkc48;
    int unkc4c;
    int unkc50;
    int unkc54;
    int unkc58;
    int unkc5c;
    int unkc60;
    int unkc64;
    int unkc68;
    int unkc6c;
    int unkc70;
    int unkc74;
    int unkc78;
    int unkc7c;
    int unkc80;
    int unkc84;
    int unkc88;
    int unkc8c;
    int unkc90;
    int unkc94;
    int unkc98;
    int unkc9c;
    int unkca0;
    int unkca4;
    int unkca8;
    int unkcac;
    int unkcb0;
    int unkcb4;
    int unkcb8;
    int unkcbc;
    int unkcc0;
    int unkcc4;
    int unkcc8;
    int unkccc;
    int unkcd0;
    int unkcd4;
    int unkcd8;
    int unkcdc;
    int unkce0;
    int unkce4;
    int unkce8;
    int unkcec;
    int unkcf0;
    int unkcf4;
    int unkcf8;
    int unkcfc;
    int unkd00;
    int unkd04;
    int unkd08;
    int unkd0c;
    int unkd10;
    int unkd14;
    int unkd18;
    int unkd1c;
    int unkd20;
    int unkd24;
    int unkd28;
    int unkd2c;
    int unkd30;
    int unkd34;
    int unkd38;
    int unkd3c;
    int unkd40;
    int unkd44;
    int unkd48;
    int unkd4c;
    int unkd50;
    int unkd54;
    int unkd58;
    int unkd5c;
    int unkd60;
    int unkd64;
    int unkd68;
    int unkd6c;
    int unkd70;
    int unkd74;
    int unkd78;
    int unkd7c;
    int unkd80;
    int unkd84;
    int unkd88;
    int unkd8c;
    int unkd90;
    int unkd94;
    int unkd98;
    int unkd9c;
    int unkda0;
    int unkda4;
    int unkda8;
    int unkdac;
    int unkdb0;
    int unkdb4;
    int unkdb8;
    int unkdbc;
    int unkdc0;
    int unkdc4;
    int unkdc8;
    int unkdcc;
    int unkdd0;
    int unkdd4;
    int unkdd8;
    int unkddc;
    int unkde0;
    int unkde4;
    int unkde8;
    int unkdec;
    int unkdf0;
    int unkdf4;
    int unkdf8;
    int unkdfc;
    int unke00;
    int unke04;
    int unke08;
    int unke0c;
    int unke10;
    int unke14;
    int unke18;
    int unke1c;
    int unke20;
    int unke24;
    int unke28;
    int unke2c;
    int unke30;
    int unke34;
    int unke38;
    int unke3c;
    int unke40;
    int unke44;
    int unke48;
    int unke4c;
    int unke50;
    int unke54;
    int unke58;
    int unke5c;
    int unke60;
    int unke64;
    int unke68;
    int unke6c;
    int unke70;
    int unke74;
    int unke78;
    int unke7c;
    int unke80;
    int unke84;
    int unke88;
    int unke8c;
    int unke90;
    int unke94;
    int unke98;
    int unke9c;
    int unkea0;
    int unkea4;
    int unkea8;
    int unkeac;
    int unkeb0;
    int unkeb4;
    int unkeb8;
    int unkebc;
    int unkec0;
    int unkec4;
    int unkec8;
    int unkecc;
    int unked0;
    int unked4;
    int unked8;
    int unkedc;
    int unkee0;
    int unkee4;
    int unkee8;
    int unkeec;
    int unkef0;
    int unkef4;
    int unkef8;
    int unkefc;
    int unkf00;
    int unkf04;
    int unkf08;
    int unkf0c;
    int unkf10;
    int unkf14;
    int unkf18;
    int unkf1c;
    int unkf20;
    int unkf24;
    int unkf28;
    int unkf2c;
    int unkf30;
    int unkf34;
    int unkf38;
    int unkf3c;
    int unkf40;
    int unkf44;
    int unkf48;
    int unkf4c;
    int unkf50;
    int unkf54;
    int unkf58;
    int unkf5c;
    int unkf60;
    int unkf64;
    int unkf68;
    int unkf6c;
    DFB0B0_Entry entries;
    DFB0B0_Entry* GetNearestEntry();
};
// FUN_00dfdd90 : releases the owned sub-object at +4, clears the field and
// tail-calls the base destructor of the object itself.
struct SubObject
{
    void __thiscall FUN_00c905b0();
};
struct FUN_00dfdd90_cls
{
    int unk00;
    SubObject* m_pSub;
    void __thiscall FUN_00cb0c00();
};
void __cdecl FUN_00dfdd90(FUN_00dfdd90_cls* p);
hkMemoryRouter* __cdecl FUN_00c85750() throw();
struct FUN_00de10b0_cls {
    virtual ~FUN_00de10b0_cls();
    unsigned short m_uSize;
    unsigned short m_u06;

    static void operator delete(void* apMemory) throw()
    {
        hkMemoryRouter* pHolder = FUN_00c85750();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        pAllocator->blockFree(apMemory, ((FUN_00de10b0_cls*)apMemory)->m_uSize);
    }
};
// sub ecx,0x28; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x28).
struct PrimaryBase
{
    virtual void FUN_00de3040();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
};
struct SecondaryBase
{
    virtual void FUN_00de3040();
};
struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00de3040
    virtual void FUN_00de3040();
};
Derived::Derived()
{
}
// 00dff450: compiler-generated thiscall adjustor thunk (sub ecx,0xc; jmp DestroySelf).
// Reproduce via MI dual-slot override: the override lands in both the primary vftable
// and the secondary vftable (which sits at offset 0xc), so VC9 emits the adjustor thunk.
struct AdjPrim {
    virtual void FUN_00dff450();
    int p04;
    int p08;
};
struct AdjSec {
    virtual void FUN_00dff450();
};
struct AdjDerived : AdjPrim, AdjSec {
// @fnv 0x00dff450
    virtual void FUN_00dff450();
};
static AdjDerived g_adjThunk;

extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_mul_ss(__m128, __m128);
extern "C" __m128 _mm_sub_ss(__m128, __m128);
extern "C" __m128 _mm_div_ss(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" void _mm_store_ss(float*, __m128);

extern const float DAT_0104da4c = 1.1920928955078125e-07f;
extern __m128 DAT_010c7160;

// @fnv 0x00de9410
bool __cdecl FUN_00de9410(const __m128* start,const __m128* end,const __m128* plane,float* out) {
__m128 a = *start;
__m128 b = *end;
__m128 p = *plane;
__m128 prod = _mm_mul_ps(_mm_sub_ps(b,a),p);
__m128 xy = _mm_add_ss(_mm_shuffle_ps(prod,prod,0x55),prod);
__m128 dot = _mm_add_ss(_mm_shuffle_ps(prod,prod,0xaa),xy);
__m128 sq=_mm_mul_ss(dot,dot);
float tmp; _mm_store_ss(&tmp,sq);
if (tmp > DAT_0104da4c) {
__m128 w=_mm_shuffle_ps(p,p,0xff);
p=_mm_mul_ps(p,a);
__m128 xy2=_mm_add_ss(_mm_shuffle_ps(p,p,0x55),p);
__m128 xyz=_mm_add_ss(_mm_shuffle_ps(p,p,0xaa),xy2);
__m128 dist=_mm_add_ss(xyz,w);
__m128 t=_mm_div_ss(_mm_sub_ss(DAT_010c7160,dist),dot);
_mm_store_ss(&tmp,t);
*out=tmp; return true; }
return false;
}

extern "C" __m128 _mm_set_ps1(float);

class TransformRadiusInput {
public:
    __m128 v00;
    __m128 v10;
    __m128 v20;
    __m128 v30;
    __m128 v40;
    float m50;
    int m54;
    int m58;
    int m5c;
    int m60;
    int m64;
    int m68;
    int m6c;

    void __thiscall FUN_00dfb1e0(int a1, int a2, const __m128* source,
                                float a4, int a5, int a6, int a7, int a8);
};

// @fnv 0x00dfb1e0
void __thiscall TransformRadiusInput::FUN_00dfb1e0(
    int a1, int a2, const __m128* source, float a4,
    int a5, int a6, int a7, int a8)
{
    v00 = source[0];
    v10 = source[1];
    v20 = source[2];
    v30 = source[3];

    m50 = a4 * a4;
    m54 = a1;
    m58 = a2;
    m60 = a5;
    m64 = a6;
    v40 = _mm_set_ps1(a4);
    m5c = 0;
    m68 = a7;
    m6c = a8;
}

typedef float hkReal;
typedef signed char hkInt8;
typedef signed short hkInt16;
typedef signed int hkInt32;
typedef unsigned char hkUchar;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned long __w64 hkUlong;
typedef unsigned __w64 hk_size_t;


extern "C"{







};
typedef __m128 hkQuadReal;

__forceinline void hkVector4_S::operator=(const hkVector4_S&v)
{
m_vComponents=v.m_vComponents;
}
__forceinline void hkVector4_S::setSub4(const hkVector4_S&v0,const hkVector4_S&v1)
{
m_vComponents=_mm_sub_ps(v0.m_vComponents,v1.m_vComponents);
}
__forceinline void hkVector4_S::_setRotatedDir(const hkRotation&r,const hkVector4_S&b)
{
const hkMatrix3& a = reinterpret_cast<const hkMatrix3&>(r);
const hkQuadReal b0=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
const hkQuadReal r0=_mm_mul_ps(a.m_kColumn0.m_vComponents,b0);
const hkQuadReal b1=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
const hkQuadReal r1=_mm_mul_ps(a.m_kColumn1.m_vComponents,b1);
const hkQuadReal b2=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
const hkQuadReal r2=_mm_mul_ps(a.m_kColumn2.m_vComponents,b2);
m_vComponents=_mm_add_ps(_mm_add_ps(r0,r1),r2);
}
__forceinline void hkVector4_S::_setRotatedInverseDir(const hkRotation&r,const hkVector4_S&b)
{
hkQuadReal c0=r.getColumn(0).m_vComponents;
hkQuadReal c1=r.getColumn(1).m_vComponents;
hkQuadReal c2=r.getColumn(2).m_vComponents;
{hkQuadReal _tmp,_ctmp;_tmp=_mm_unpacklo_ps(c0,c1);_ctmp=_mm_shuffle_ps(_mm_unpackhi_ps(c0,c1),c2,(((3)<<6)|((2)<<4)|((1)<<2)|((0))));c0=_mm_movelh_ps(_tmp,c2);c1=_mm_shuffle_ps(_mm_movehl_ps(c0,_tmp),c2,(((3)<<6)|((1)<<4)|((1)<<2)|((0))));c2=_ctmp;};
const hkQuadReal b0=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
const hkQuadReal r0=_mm_mul_ps(c0,b0);
const hkQuadReal b1=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
const hkQuadReal r1=_mm_mul_ps(c1,b1);
const hkQuadReal b2=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
const hkQuadReal r2=_mm_mul_ps(c2,b2);
m_vComponents=_mm_add_ps(_mm_add_ps(r0,r1),r2);}
__forceinline void hkVector4_S::_setTransformedInversePos(const hkTransform&a,const hkVector4_S&b)
{
// This ray-cast path uses the layout-identical hkVector4_S view.
hkVector4_S t0;t0.setSub4(b,reinterpret_cast<const hkVector4_S&>(a.getTranslation()));
_setRotatedInverseDir(a.getRotation(),t0);
}
__forceinline const hkVector4&hkTransform::getTranslation()const
{
return reinterpret_cast<const hkVector4&>(m_row3);
}
__forceinline const hkRotation&hkTransform::getRotation()const
{
return reinterpret_cast<const hkRotation&>(m_row0);
}

__forceinline hkMonitorStream& hkMonitorStream::getInstance()
{
    extern hkThreadLocalData<hkMonitorStream*> g_pMonitorStream;
    return *g_pMonitorStream.getData();
}
__forceinline char* __cdecl hkMonitorStream::getStart() { return m_start.val(); }
__forceinline char* __cdecl hkMonitorStream::getEnd() { return m_end.val(); }
__forceinline char* __cdecl hkMonitorStream::getCapacityMinus16() { return m_capacityMinus16.val(); }
__forceinline hkBool __cdecl hkMonitorStream::memoryAvailable()
{
    return getEnd() < getCapacityMinus16();
}
__forceinline void __cdecl hkMonitorStream::setEnd(char* ptr) { m_end = ptr; }
__forceinline void hkMonitorStream::TimerCommand::setTime()
{
hkUint32 ticks;
__asm{
rdtsc
mov dword ptr[ticks],eax
}
m_time0=ticks;
}

#include "../../include/hkAabbUint32.h"

struct ShapeRayCastQuery;
struct ShapeRayCastOutput;
class hkpRayHitCollector;
class hkpCdBody;
class hkpShapeContainer;
typedef hkUint32 hkpShapeKey;
__forceinline hkBool hkpShape::RayCast(const ShapeRayCastQuery&input,ShapeRayCastOutput&output)const
{
return IntersectRayWithShape(input,output);
}
__forceinline void hkpShape::castRayWithCollector(const ShapeRayCastQuery&input,const hkpCdBody&cdBody,hkpRayHitCollector&collector)const
{
return CastRayWithCollector(input,cdBody,collector);
}
struct RayCastHitResult
{
inline RayCastHitResult();
inline void reset();
hkVector4_S m_vHitNormal;
hkReal m_fHitFraction;
int m_iExtraInfo;
int unkPad0;int unkPad1;};
void RayCastHitResult::reset()
{
m_fHitFraction=1.0f;
m_iExtraInfo=-1;
}
RayCastHitResult::RayCastHitResult()
{
reset();
}
struct ShapeRayCastOutput:public RayCastHitResult
{
public:
enum{MAX_HIERARCHY_DEPTH=8};
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
__forceinline ShapeRayCastOutput();
__forceinline void reset();
private:
__forceinline void _reset();
public:
hkpShapeKey m_uiShapeKeys[MAX_HIERARCHY_DEPTH];
private:
int m_uiShapeKeyIndex;};
void ShapeRayCastOutput::_reset()
{
m_uiShapeKeyIndex=0;
m_uiShapeKeys[0]=0xffffffff;
}
void ShapeRayCastOutput::reset()
{
RayCastHitResult::reset();
_reset();
}
ShapeRayCastOutput::ShapeRayCastOutput()
{
_reset();
}
__forceinline const hkTransform&hkpCdBody::getTransform()const
{
;
return*static_cast<const hkTransform*>(m_pMotionState);
}
struct GskAgentInput;
__forceinline const hkpShape*hkpCollidable::getShape()const
{
return m_pCollisionShape;
}


class PhysicsSimulationContext
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
public:
CRITICAL_SECTION m_kCriticalSection;};
class BusyWaitingSemaphore
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
protected:
protected:void*m_pCompletionSemaphore;};
typedef BusyWaitingSemaphore hkSemaphoreBusyWait;
template<typename T>
class CapacityGrowingArray
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
private:
inline void increaseCapacity();};
typedef hkUint8 hkJobSubType;
struct JobDescriptor
{__declspec(align(16))hkJobSubType m_ucSubType;};
struct JobQueueConstructionInfo
{};
class JobDispatcher
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
enum{JOB_QUEUE_ENTRY_SIZE=128};
struct JobQueueSlot:public JobDescriptor
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(JobQueueSlot));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
JobQueueSlot(){}
hkUchar m_data[JOB_QUEUE_ENTRY_SIZE-sizeof(JobDescriptor)];
};
struct Queue:public CapacityGrowingArray<JobQueueSlot>
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(Queue));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
};
enum WaitPolicy
{
WAIT_UNTIL_ALL_WORK_COMPLETE,
WAIT_INDEFINITELY
};
struct JobQueueWaitState
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(JobQueueWaitState));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
__declspec(align(16))hkInt16 m_sQueueCounts[HK_JOB_TYPE_MAX];
int m_iWaitCount;
WaitPolicy m_eWaitPolicy;
hkBool m_bWaiting;
hkUint16 m_auiThreadIds[2+2+1];
Queue m_kQueues[2+2+1+HK_JOB_TYPE_MAX];
};
enum JobPopFuncResult
{
POP_QUEUE_ENTRY,
DO_NOT_POP_QUEUE_ENTRY
};
enum NextJobWaitMode
{
WAIT_FOR_NEXT_JOB,
DO_NOT_WAIT_FOR_NEXT_JOB
};
enum JobStatus
{
JOB_INVALID=-1,
GOT_NEXT_JOB,
NO_JOBS_AVAILABLE,
ALL_JOBS_FINISHED,
JOBS_AVAILABLE_BUT_NOT_FOR_CURRENT_ELF,
};
public:
JobDispatcher(const JobQueueConstructionInfo&cinfo);
JobStatus GetNextJob(const JobQueueSlot*oldJob,JobQueueSlot&jobOut,NextJobWaitMode waitStatus=WAIT_FOR_NEXT_JOB);
public:
void releaseOneWaitingThread(JobQueueWaitState*data);
public:
__declspec(align(64))PhysicsSimulationContext m_pWorldLock;
public:
int iFirstInteger;};
struct ShapeRayCastQuery
{
hkVector4_S m_vFrom;
hkVector4_S m_vTo;
hkUint32 m_uiFilterInfo;};
struct WorldRayCastOutput;
struct CollisionQueryJobHeader
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}};
struct RayCastQueryJobDescriptor:public JobDescriptor
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
enum JobSubType
{
RAYCAST_QUERY_SHAPE_RAYCAST,
RAYCAST_QUERY_WORLD_RAYCAST,
RAYCAST_QUERY_KD_TREE_BUILD_FAST,
RAYCAST_QUERY_KD_TREE_BUILD_FAST_DISTRIBUTED_JOB,
RAYCAST_QUERY_KD_TREE_BUILD_FAST_DISTRIBUTED_SUBJOB,
RAYCAST_QUERY_KD_TREE_BUILD_SETUP_JOB,
RAYCAST_QUERY_KD_TREE_BUILD_COORDINATOR_JOB,
RAYCAST_QUERY_WORLD_RAYCAST_WITH_AUTOBUNDLE,
RAYCAST_QUERY_JOB_END
};
protected:
__forceinline RayCastQueryJobDescriptor(JobSubType subType,hkUint16 size);
public:
hkSemaphoreBusyWait*m_pCompletionSemaphore;};
struct WorldRayCastCommand
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
public:
ShapeRayCastQuery m_kRayCastQuery;
hkUint32 m_uiCollisionFilterInfo;
hkInt32 m_iCommandParameter;
const hkpCollidable**m_kCollidables;
int m_iCollidableCount;
WorldRayCastOutput*m_pResultBuffer;
int m_iResultCount;
int m_iResultCapacity;
hkBool m_bResultFlag;};
struct WorldRayCastJob:public RayCastQueryJobDescriptor
{
public:
friend struct RayCastCommandTaskFriend;
enum{MAXIMUM_NUMBER_OF_COMMANDS_PER_TASK=90};
public:
__forceinline WorldRayCastJob(const GskAgentInput*input,CollisionQueryJobHeader*jobHeader,const WorldRayCastCommand*commandArray,int numCommands,hkSemaphoreBusyWait*semaphore,int numCommandsPerTask=MAXIMUM_NUMBER_OF_COMMANDS_PER_TASK);
public:
__forceinline JobDispatcher::JobPopFuncResult popJobTask(WorldRayCastJob&out);
int m_iCommandCapacity;
const WorldRayCastCommand*m_pCommands;
int m_iCommandCount;};
struct WorldRayCastOutput:public ShapeRayCastOutput
{
inline WorldRayCastOutput();
inline void reset();
const hkpCollidable*m_pRootCollidable;};
typedef WorldRayCastOutput hkpWorldRayCastOutputPpu;
void WorldRayCastOutput::reset()
{
m_pRootCollidable=0;
ShapeRayCastOutput::reset();
}
WorldRayCastOutput::WorldRayCastOutput():
m_pRootCollidable(0)
{
}
class WorldRayCastResultHelper
{
public:
__forceinline static hkpWorldRayCastOutputPpu*getNextFreeResult(WorldRayCastCommand*command,hkpWorldRayCastOutputPpu*resultsArray,hkpWorldRayCastOutputPpu*&nextFreeResult,hkReal hitFraction);
};
template<typename COMMAND,typename OUTPUT>
class RayCastResultAllocator
{
public:
__forceinline static OUTPUT*getNextFreeResult(COMMAND*command,OUTPUT*resultsArray,OUTPUT*&nextFreeResult,hkReal hitFraction,hkReal&maxHitFractionOut);
};
__forceinline hkpWorldRayCastOutputPpu*WorldRayCastResultHelper::getNextFreeResult(WorldRayCastCommand*command,hkpWorldRayCastOutputPpu*resultsArray,hkpWorldRayCastOutputPpu*&nextFreeResult,hkReal hitFraction)
{
hkReal dummy=1.0f;
return RayCastResultAllocator<WorldRayCastCommand,hkpWorldRayCastOutputPpu>::getNextFreeResult(command,resultsArray,nextFreeResult,hitFraction,dummy);}
template<typename COMMAND,typename OUTPUT>
OUTPUT*RayCastResultAllocator<COMMAND,OUTPUT>::getNextFreeResult(COMMAND*command,OUTPUT*resultsArray,OUTPUT*&nextFreeResult,hkReal hitFraction,hkReal&maxHitFractionOut)
{
OUTPUT*resultToReturn=0;
if(command->m_iResultCapacity<command->m_iResultCount)
{
resultToReturn=nextFreeResult;
command->m_iResultCapacity++;
nextFreeResult=nextFreeResult+1;
maxHitFractionOut=1.0f;
}
else
{
OUTPUT*furthestHit=resultsArray;
OUTPUT*currentHitInArray=resultsArray+1;
{
for(int i=1;i<command->m_iResultCapacity;i++)
{
if(currentHitInArray->m_fHitFraction>furthestHit->m_fHitFraction)
{
furthestHit=currentHitInArray;
}
currentHitInArray++;
}
}
if(hitFraction<furthestHit->m_fHitFraction)
{
maxHitFractionOut=furthestHit->m_fHitFraction;
resultToReturn=furthestHit;
}
}
return resultToReturn;}
inline void hkpRayHitCollector::reset()
{
m_fEarlyOutHitFraction=1.f;
}
inline hkpRayHitCollector::hkpRayHitCollector()
{
reset();
}

typedef void(__cdecl*hkFixedBufferRayHitCollectorAddRayHitCallbackFunc)(const hkpCdBody&cdBody,const RayCastHitResult&hitInfo,class hkpFixedBufferRayHitCollector*collector);
extern hkFixedBufferRayHitCollectorAddRayHitCallbackFunc g_pFixedBufferRayHitCallback;
__forceinline void registerFixedBufferRayHitCollectorAddRayHitCallbackFunction(hkFixedBufferRayHitCollectorAddRayHitCallbackFunc func)
{
g_pFixedBufferRayHitCallback=func;
}
__forceinline hkpFixedBufferRayHitCollector::hkpFixedBufferRayHitCollector(WorldRayCastOutput*buffer,int capacity):hkpRayHitCollector()
{
;
m_pRayHitBuffer=buffer;
m_pHitBufferEnd=buffer;
m_pRayCursor=capacity;
m_iHitCount=0;
m_pCollidable=0;
}
__forceinline void __cdecl hkCpuShapeRayCastJobProcessCommand(const WorldRayCastCommand&raycastCommand)
{
WorldRayCastCommand*command=const_cast<WorldRayCastCommand*>(&raycastCommand);
ShapeRayCastQuery input=command->m_kRayCastQuery;
WorldRayCastOutput output;
WorldRayCastOutput*nextFreeResult=command->m_pResultBuffer;
{
hkpFixedBufferRayHitCollector fixedBufferRayHitCollector(command->m_pResultBuffer,command->m_iResultCount);
registerFixedBufferRayHitCollectorAddRayHitCallbackFunction(hkpFixedBufferRayHitCollector::addRayHitImplementation);
for(int i=0;i<command->m_iCollidableCount;i++)
{
const hkpCollidable*collidable=command->m_kCollidables[i];
const hkpShape*shape=collidable->getShape();
if(shape)
{
// The shared collidable stores the hkpCdBody prefix without inheritance.
const hkTransform&transform=reinterpret_cast<const hkpCdBody*>(collidable)->getTransform();
input.m_vTo._setTransformedInversePos(transform,command->m_kRayCastQuery.m_vTo);
input.m_vFrom._setTransformedInversePos(transform,command->m_kRayCastQuery.m_vFrom);
output.reset();
if(!command->m_bResultFlag)
{
hkBool hit=shape->RayCast(input,output);
if(hit)
{
WorldRayCastOutput*aiRecipeIndex=WorldRayCastResultHelper::getNextFreeResult(command,command->m_pResultBuffer,nextFreeResult,output.m_fHitFraction);
if(aiRecipeIndex)
{
output.m_vHitNormal._setRotatedDir(transform.getRotation(),output.m_vHitNormal);
*aiRecipeIndex=output;
aiRecipeIndex->m_pRootCollidable=collidable;
}
}
}
else
{
shape->castRayWithCollector(input,*reinterpret_cast<const hkpCdBody*>(collidable),fixedBufferRayHitCollector);
}
}
}
if(command->m_bResultFlag)
{
command->m_iResultCapacity=fixedBufferRayHitCollector.m_iHitCount;
}
}
}
// @fnv 0x00df94b0
JobDispatcher::JobStatus __cdecl FUN_00df94b0(JobDispatcher&jobQueue,JobDispatcher::JobQueueSlot&nextJobOut)
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="T" "t" "CollQueryShapeRayCast";h->setTime();mStream.setEnd((char*)(h+1));}};
const WorldRayCastJob&raycastJob=reinterpret_cast<WorldRayCastJob&>(nextJobOut);
for(int i=0;i<raycastJob.m_iCommandCount;i++)
{
hkCpuShapeRayCastJobProcessCommand(raycastJob.m_pCommands[i]);
}
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return jobQueue.GetNextJob(&nextJobOut,nextJobOut);
}
