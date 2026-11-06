#define FNV64_HKVECTOR4_OWN_DEFAULT
#define FNV64_HKVECTOR4_OWN_ASSIGN

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
void __cdecl FUN_00df64d0(void* p, int b);
struct FUN_00cb0c00_class
{
    void __thiscall FUN_00cb0c00();
};
void FUN_00dfb490(FUN_00cb0c00_class* self);
void FUN_00dfb9d0(hkReferencedObject** p);
extern int DAT_010cc2fc;
extern int DAT_010df34c;
struct FUN_00dfbdf0_class
{
    void __thiscall FUN_00cb0a70(int a);
};
void FUN_00dfbdf0(void* p, int a);
extern void* DAT_010d77d8;
struct FUN_00d21de0_Class
{
    void __thiscall FUN_00d21de0(void*);
};
void __cdecl FUN_00dfc3e0(void** p, void* a2);
extern "C" void* DAT_010305a8;
extern "C" void* DAT_010e222c;
void FUN_00dfd0f0(void* a, int b);
struct FUN_00cb0a70_class
{
    void __thiscall FUN_00cb0a70(int);
};
void __cdecl FUN_00dfd770(void* arg1, void* arg2);
struct FUN_00cb0a70_cls
{
    void __thiscall FUN_00cb0a70(char*);
};
void FUN_00dfda10(char* b, char* a);
extern int DAT_010d3cc0;
void FUN_00dfde30(void* p);
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
    void __thiscall FUN_00cb0a70(int a);
};
void FUN_00dfef50(int* p, int a);
extern int DAT_010cc2fc;
extern int DAT_010e6834;
struct FUN_00dff0f0_class
{
    int m;
    void FUN_00cb0a70(int);
};
void FUN_00dff0f0(FUN_00dff0f0_class* p, int a);
extern int DAT_010cce28;
extern int DAT_010d07f4;
struct FUN_00cb0a70
{
    void __thiscall m_00cb0a70(int);
};
void __cdecl FUN_00dff1f0(int* a, int b);
struct FUN_00dff340_Class
{
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
typedef void(__thiscall* VTable0)(void*, int);
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
typedef int(__thiscall* VFunc0)(void*, int);
int __cdecl FUN_00dfcd10(void* self);
extern int DAT_010c91ec;
void __cdecl FUN_00dfcd40(int* p);
extern int DAT_010d0cd4;
void __cdecl FUN_00dfce90(int* a);
struct FUN_00dfd7a0_vt
{
    virtual void v0(int);
    virtual void v1(int);
};
void __cdecl FUN_00dfd7a0(FUN_00dfd7a0_vt* p);
void __cdecl FUN_00dfd7c0(void* arg);
struct FUN_00dfd940_vt
{
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
struct FUN_00dfe430_class
{
    virtual int __thiscall FUN_00cb0a70(int a);
};
int __cdecl FUN_00dfe430(FUN_00dfe430_class* p);
extern int DAT_010e56d4;
void __cdecl FUN_00dfe490(int* p);
extern int DAT_010e57a4;
void __cdecl FUN_00dfe500(int* p);
struct FUN_00dfe670_vt
{
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
struct FUN_00cb0a70_m_helper
{
    void __thiscall m(int);
};
void __cdecl FUN_00dff270(void* a, void* b);
typedef void(__thiscall* VTableFn)(void*, int);
void __cdecl FUN_00dff3c0(void* p);
extern int DAT_010e75cc;
void FUN_00dff5e0(int* p);
extern int DAT_010e75dc;
void __cdecl FUN_00dff600(int* p);
extern int DAT_010e75ec;
void __cdecl FUN_00dff620(int** p);
void __cdecl FUN_00dff9e0(void** p);
typedef int(__thiscall* Vfn)(void*, int);
int __cdecl FUN_00dffa30(void* obj);
extern int DAT_010e7c24;
void __cdecl FUN_00dffc80(int* p);
extern int DAT_010cc0d8;
void __cdecl FUN_00dffda0(int* p);
struct FUN_00dffdc0_vt
{
    virtual void m0(int);
};
void __cdecl FUN_00dffdc0(FUN_00dffdc0_vt* p);
extern int DAT_010d3838;
void __cdecl FUN_00dffe40(int* p);
extern int DAT_010cb798;
void FUN_00dffee0(int* p);
struct FUN_00dfff60_vt
{
    virtual int __thiscall v0(int);
};
int __cdecl FUN_00dfff60(FUN_00dfff60_vt* p);
struct FUN_00dfffc0_VT
{
    virtual void m0(int);
};
void __cdecl FUN_00dfffc0(FUN_00dfffc0_VT* p);
extern void* DAT_010e80b4;
void __cdecl FUN_00dfffe0(void** p);
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
void __cdecl FUN_00de81a0(void* self, void* arg);
struct FUN_00d21ce0_cls
{
    void __thiscall FUN_00d21ce0(void*);
};
struct FUN_00de8550_t
{
    int m_iWordAt00;
    int m_iWordAt04;
    void* m_8;
};
void __cdecl FUN_00de8550(FUN_00de8550_t* a, int b);
struct FUN_00de8830_Class
{
    void CopyTransposedMatrix(float* src);
};
int __cdecl FUN_00df3250(int arg);
typedef void(__thiscall* Vfn0)(void*, int);
void __cdecl FUN_00df6460(void** p);
typedef int(__thiscall* VFunc_00dfb270)(void*, int);
int __cdecl FUN_00dfb270(void* p);
void __cdecl CallMethodOnBothHelpers(FUN_00cb0a70_m_helper* a, int v);
typedef void(__thiscall* VFunc00dfb3f0)(void*, int);
void __cdecl FUN_00dfb3f0(void** p);
struct FUN_00dfb450_vt
{
    virtual void m0(int);
};
void __cdecl FUN_00dfb450(FUN_00dfb450_vt* p);
struct FUN_00dfb890_vt
{
    virtual void v0(int);
};
void __cdecl FUN_00dfb890(FUN_00dfb890_vt* p);
extern int DAT_010c4dec;
void FUN_00dfb9f0(int* a, int b);
typedef void(__thiscall* VTable0_00dfba70)(void*, int);
void __cdecl FUN_00dfba70(void* p);
typedef void(__thiscall* VFn0)(void*, int);
void __cdecl FUN_00dfbb30(void* p);
void __cdecl FUN_00dfbbf0(void* p, int a);
struct S_00d49310_Lock
{
    ~S_00d49310_Lock();
};
void __cdecl FUN_00dfbc20(S_00d49310_Lock* self);
void __cdecl FUN_00dfbc30(void* a, void* b);
void __cdecl DispatchToHelper(void* a, int b);
struct S_00dfb720_Elem
{
    ~S_00dfb720_Elem();
};
void __cdecl FUN_00dfbca0(S_00dfb720_Elem* p);
typedef void(__thiscall* VTable0)(void*, int);
void __cdecl FUN_00dfbcd0(void* p);
typedef void(__thiscall* VFunc1)(void*, int);
void __cdecl FUN_00dfbdd0(void* p);
struct FUN_00dfc040_vt
{
    virtual void __thiscall FUN_00dfc040(int);
};
void __cdecl FUN_00dfc040(FUN_00dfc040_vt* p);
typedef void(__thiscall* V00dfc790)(void*, int);
void __cdecl FUN_00dfc790(void** p);
void __cdecl FUN_00dfc7f0(int* p);
void __cdecl FUN_00dfc8d0(void** p);
typedef void(__thiscall* Vfn_00dfcb60)(void*, int);
void __cdecl FUN_00dfcb60(void* p);
struct FUN_00dfcc30_vt
{
    virtual void v0(int);
};
void __cdecl FUN_00dfcc30(FUN_00dfcc30_vt* p);
struct FUN_00dd0420_Class
{
    FUN_00dd0420_Class* __thiscall FUN_00dd0420(int);
};
void __cdecl FUN_00dfcd80(FUN_00dd0420_Class* self, int a);
struct FUN_00dfce00_vt
{
    virtual void __thiscall v0(int);
};
void __cdecl FUN_00dfce00(FUN_00dfce00_vt* p);
struct FUN_00dfcf00_vt
{
    virtual void m_iWordAt00(int);
};
void __cdecl FUN_00dfcf00(FUN_00dfcf00_vt* p);
struct FUN_00dfd240_vt
{
    virtual void __thiscall FUN_00dfd240(int);
};
void __cdecl FUN_00dfd240(FUN_00dfd240_vt* p);
typedef void(__thiscall* Vfn_00dfd620)(void*, int);
void __cdecl FUN_00dfd620(void* p);
struct DFD680MeshData
{
    void FUN_00dfd680();
};
void __cdecl FUN_00dfd670(DFD680MeshData* p);
extern int DAT_010e311c;
void FUN_00dfd7d0(int* p, int a);
void __cdecl FUN_00dfda70(void* p);
void FUN_00dfdad0(int* a, int b);
void __cdecl FUN_00dfdb00(void* p);
struct FUN_00dfdb20_vt
{
    virtual void v0(int);
};
void __cdecl FUN_00dfdb20(FUN_00dfdb20_vt* p);
void __cdecl CallHelperMethod(FUN_00cb0a70_m_helper* a, int b);
struct S_00e3eaa0_Elem
{
    ~S_00e3eaa0_Elem();
};
void __cdecl FUN_00dfdd50(S_00e3eaa0_Elem* p);
struct FUN_00e3f900_class
{
    int FUN_00e3f900(int);
};
void __cdecl FUN_00dfdd60(FUN_00e3f900_class* p, int a);
void CallHelperWithInt(FUN_00cb0a70_m_helper* p, int a);
struct ArrayPair
{
    ~ArrayPair();
};
void __cdecl FUN_00dfe0c0(ArrayPair* p);
typedef void(__thiscall* Vfn_00dfe270)(void*, int);
void __cdecl FUN_00dfe270(void* p);
void __cdecl FUN_00dfe2b0(void* p);
extern int DAT_010cb864;
struct FUN_00ce5360_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int FUN_00ce5360(int a);
};
void __cdecl FUN_00dfe2d0(FUN_00ce5360_class* a, int b);
struct FUN_00dfe320_vt
{
    virtual void m_iWordAt00(int);
};
void __cdecl FUN_00dfe320(FUN_00dfe320_vt* p);
extern int DAT_010e56d4;
int* FUN_00dfe4a0();
struct FUN_00dfe4e0_vt
{
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
typedef void(__thiscall* Vfn0)(void*, int);
void __cdecl FUN_00dfebf0(void* p);
struct FUN_00dfec30_vt
{
    virtual void m0(int);
};
void __cdecl FUN_00dfec30(FUN_00dfec30_vt* p);
struct FUN_00dfecf0_vt
{
    virtual void v0(int);
};
void __cdecl FUN_00dfecf0(FUN_00dfecf0_vt* p);
struct FUN_00dfede0_vt
{
    virtual void v0(int);
};
void __cdecl FUN_00dfede0(FUN_00dfede0_vt* p);
typedef int(__thiscall* Vfn_00dfeec0)(void*, int);
int __cdecl FUN_00dfeec0(void* p);
struct FUN_00dfef00_vt
{
    virtual void __thiscall m0(int);
};
void __cdecl FUN_00dfef00(FUN_00dfef00_vt* p);
struct FUN_00dff1d0_vt
{
    virtual void m0(int);
};
void __cdecl FUN_00dff1d0(FUN_00dff1d0_vt* p);
typedef void(__thiscall* VTable0)(void*, int);
void __cdecl FUN_00dff300(void** p);
struct FUN_00dff370_vt
{
    virtual void __thiscall FUN_00dff370(int);
};
void __cdecl FUN_00dff370(FUN_00dff370_vt* p);
void __cdecl FUN_00dff540(void** p);
typedef void(__thiscall* VTable0)(void*, int);
void __cdecl FUN_00dff580(void** p);
typedef void(__thiscall* VTable0)(void*, int);
void __cdecl FUN_00dff5c0(void* p);
extern int DAT_010cc2fc;
extern int DAT_010d0994;
struct FUN_00dff9b0_m : FUN_00cb0a70
{
    void __thiscall m(int);
};
void __cdecl FUN_00dff9b0(FUN_00dff9b0_m* p, int a);
typedef void(__thiscall* VTblFn0)(void*, int);
void __cdecl FUN_00dffc10(void* p);
struct FUN_00dffc60_vt
{
    virtual void m0(int);
};
void __cdecl FUN_00dffc60(FUN_00dffc60_vt* p);
struct FUN_00dffd80_vt
{
    virtual void __thiscall FUN_00cb0a70(int);
};
void __cdecl FUN_00dffd80(FUN_00dffd80_vt* p);
typedef void(__thiscall* VTableFn)(void*, int);
void __cdecl FUN_00dffe20(void* p);
struct FUN_00dffe60_vt
{
    virtual void m_iWordAt00(int);
};
void __cdecl FUN_00dffe60(FUN_00dffe60_vt* p);
typedef void(__thiscall* Vfn0)(void*, int);
void __cdecl FUN_00dfff00(void* p);
extern int DAT_0102e388;
hkMemoryRouter* __cdecl FUN_00c85750() throw();
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
    void FUN_00de3090();
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
    float FUN_00de48e0();
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
    float FUN_00de48f0();
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
    float FUN_00de4900();
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

    char* FUN_00de4e10();
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
    float FUN_00de5350();
};
class FUN_00de5360_cls
{
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
struct GlobalObject
{
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
struct FUN_00de8570_cls
{
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
void __cdecl FUN_00cb3c80(void* pkItem, DF25D0Owner* pkOwner);
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
void __cdecl FUN_00df6440(Handler_cls* pHandler, int value);
extern int g_0126a430;
int* __cdecl FUN_00df6490();
extern int DAT_0126a478;
void* __cdecl FUN_00df64b0();
extern "C" int DAT_0126a4a8;
// @fnv 0x00df64c0
extern "C" void* __cdecl FUN_00df64c0()
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

    void __thiscall FUN_00df7a60();
};
extern "C" __declspec(dllimport) long __stdcall InterlockedExchangeAdd(volatile long* value, long increment);
void __cdecl FUN_00d043c0(void* object, int value);
extern float DAT_010dbb3c;
extern float DAT_0104da48;
struct ParserContext
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, result44;
    int __thiscall FUN_00e63af0(int, void*, float*);
};
struct FloatPair
{
    float first, second;
    int __thiscall TraverseNode(ParserContext*, int, int*, ParserContext**);
    int __thiscall FUN_00dfb040(ParserContext*, int, int*, ParserContext**);
};
struct CpuOpaque;
extern CpuOpaque DAT_0126a5f8;
CpuOpaque* __cdecl FUN_00dfb260();
extern int g_unk0126aa18;
int* __cdecl FUN_00dfb280();
struct FUN_00dfb2d0_class
{
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
void __cdecl FUN_00dfb3d0(FUN_00dfb3d0_cls* pObject, int a1);
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
class DFB550Object
{
  public:
    virtual ~DFB550Object();
};
void FUN_00dfb550(DFB550Object* pkObject);
extern int DAT_0126ad90;
int* __cdecl FUN_00dfb560();
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
void* FUN_00dfb8d0();
struct CpuOpaque;
extern CpuOpaque DAT_0126ae80;
CpuOpaque* __cdecl FUN_00dfb920();
extern int DAT_0126aeb0;
void* __cdecl FUN_00dfb940();
class CalleeObj
{
  public:
    void FUN_00ce5360(void* pParam);
};
void __cdecl FUN_00dfb950(CalleeObj* pFirst, void* pSecond);
extern int DAT_0126aee0;
int* __cdecl FUN_00dfb970();
struct FUN_00ce5370_cls
{
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
void __cdecl FUN_00dfba50(FUN_00dfba50_cls* pObject, int a1);
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
extern "C" void* __cdecl FUN_00dfbc10()
{
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
struct FUN_00dfbf30_class
{
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
struct S_00dfc110_vt
{
    virtual void m0(int);
};
void __thiscall S_00dfc110_vt::m0(int)
{}
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
struct FUN_00e05c20_class
{
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
class VirtualDispatchObj
{
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
struct FUN_00dfc600_vt
{
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
struct FUN_00dfc690_vt
{
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
class DFC810Object
{
  public:
    void Process(void* pvData);
};
void __cdecl FUN_00dfc810(DFC810Object* pkObject, void* pvData);
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
int* __cdecl FUN_00dfc8c0();
extern int g_unk0126b9f0;
int* __cdecl FUN_00dfc8e0();
extern int DAT_010e11ec;
int* __cdecl FUN_00dfc910();
extern int g_0126ba38;
int* __cdecl FUN_00dfc930();
struct FUN_00dfc940_class
{
    virtual void m0(int);
};
void __cdecl FUN_00dfc940(FUN_00dfc940_class* p);
extern int DAT_0126ba68;
void* __cdecl FUN_00dfc950();
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
    void FUN_00d4f270(S_00dfc970_Flag f);
};
void __cdecl FUN_00dfc970(S_00dfc970_Obj* p, int flag);
extern int DAT_010d0af4;
int* __cdecl FUN_00dfc9a0();
extern int DAT_0126bab0;
int* __cdecl FUN_00dfc9c0();
class DFC9D0Object
{
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
class DFCA60Object
{
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
struct S_00dfcc40_Obj
{
    int unk00;
};
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
struct DFD5E0
{
    void __thiscall FUN_00d53df0(void* p);
};
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
struct FUN_00dfcf20_cls
{
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
void __cdecl FUN_00dfd1e0(FUN_00dfd1e0_cls* pObject, int a1);
extern int DAT_0126c158;
int* __cdecl FUN_00dfd230();
// FUN_00dfd250 : a one-line function - getter
extern int g_target_00dfd250;
void* FUN_00dfd250();
struct S_00dfd260_Foo
{
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
struct FUN_00dfd2e0_Class
{
    virtual void VF00(int value);
};
void __cdecl FUN_00dfd2e0(FUN_00dfd2e0_Class* param_1);
// FUN_00dfd2f0 : a one-line function - getter
extern int g_target_00dfd2f0;
void* FUN_00dfd2f0();
struct FUN_00e3dbd0_class
{
    void __thiscall FUN_00e3dbd0(int value);
};
void __cdecl FUN_00dfd300(FUN_00e3dbd0_class* object, int value);
struct FUN_00dfd380_Class
{
    void __thiscall FUN_00dfd380();
};
void __cdecl FUN_00dfd360(int* param_1);
struct FnvCpu_FUN_00dfd370_CpuTarget
{
    void FUN_00dfd440();
};
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
void __cdecl FUN_00dfd570(FUN_00dfd570_cls* pObject, int a1);
extern int DAT_0126c368;
int* __cdecl FUN_00dfd590();
extern int DAT_0126c398;
int __cdecl FUN_00dfd5f0();
class FUN_00dfd600_cls
{
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
struct FUN_00dfd990_class
{
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
struct S_00e3f510_Foo
{
    void __thiscall FUN_00e3f510(int);
};
void __cdecl FUN_00dfda50(void* p, int a);
extern int DAT_0126c530;
int* __cdecl FUN_00dfdaa0();
struct AdjacentObjects
{
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
struct FUN_00dfde10_vtable
{
    virtual void __thiscall slot0(int value)
    {}
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
void __cdecl FUN_00dfdec0(FUN_00dfdec0_cls* pObject, int a1);
extern unsigned char DAT_0126c800;
void* __cdecl FUN_00dfdee0();
// FUN_00dfdef0: null-guarded forwarding of a second argument to a
// member function of the first (object) argument.
class FUN_00dfdef0_cls
{
  public:
    void FUN_00e0f700(int a1);
};
void __cdecl FUN_00dfdef0(FUN_00dfdef0_cls* pObject, int a1);
extern int g_unk0126c830;
void* __cdecl FUN_00dfdf10();
extern int DAT_0126c860;
int* __cdecl FUN_00dfdf30();
struct CpuOpaque;
extern CpuOpaque DAT_0126c890;
CpuOpaque* __cdecl FUN_00dfdf40();
class DFDF50Object
{
  public:
    virtual ~DFDF50Object();
};
void __cdecl FUN_00dfdf50(DFDF50Object* pkObject);
extern int DAT_0126c8c0;
int* __cdecl FUN_00dfdf60();
extern int DAT_010e3e5c;
int* __cdecl FUN_00dfdfc0();
struct FUN_00ddc870_class
{
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
void __cdecl FUN_00dfe250(FUN_00dfe250_cls* pObject, int a1);
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
struct FUN_00cb0a70_obj
{
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
struct FUN_00dfe6e0_Class
{
    virtual void vf00(int value);
};
void __cdecl FUN_00dfe6e0(FUN_00dfe6e0_Class* param_1);
extern unsigned char DAT_0126cd88;
void* __cdecl FUN_00dfe6f0();
extern int DAT_010e59ac;
int __cdecl FUN_00dfe710();
struct FUN_00dfe970_class
{
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
class DFEC50Object
{
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
class DFEF80Object
{
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
struct FUN_00dff0b0_class
{
    virtual void m0(int);
};
void __cdecl FUN_00dff0b0(FUN_00dff0b0_class* p);
extern int DAT_0126d220;
void* __cdecl FUN_00dff0c0();
extern int DAT_010e676c;
int* __cdecl FUN_00dff0e0();
struct FUN_00dff120_Class
{
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
void __cdecl FUN_00dff170(FUN_00dff170_cls* pObject, int a1);
struct FUN_00dff190_cls
{
    virtual void m_v00(int arg);
};
void __cdecl FUN_00dff190(FUN_00dff190_cls* pObject);
extern int DAT_0126d298;
int __cdecl FUN_00dff1c0();
extern int DAT_0126d2f8;
int __cdecl FUN_00dff1e0();
struct FUN_00dff250_class
{
    virtual void m0(int);
};
void __cdecl FUN_00dff250(FUN_00dff250_class* p);
extern int DAT_0126d328;
void* __cdecl FUN_00dff260();
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
struct FUN_00e46300_class
{
    void __thiscall FUN_00e46300(int);
};
void __cdecl FUN_00dff4c0(FUN_00e46300_class* p, int a);
struct DFF4E0Object
{
    virtual void Destroy(bool bFree);
};
void FUN_00dff4e0(DFF4E0Object* pkObject);
extern unsigned char DAT_0126d448;
void* __cdecl FUN_00dff510();
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
struct DFFA90FinishFlag
{
    int m_bFinishing;
};
class DFFA90ReferencedObject
{
  public:
    DFFA90ReferencedObject(DFFA90FinishFlag)
    {}
    virtual ~DFFA90ReferencedObject();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
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
class FUN_00dffa90 : public DFFA90ReferencedObject,
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
struct S_00dfff80_Foo
{
    void __thiscall FUN_00cdf760(int a);
};
void __cdecl CallFooMethodIfNotNull(S_00dfff80_Foo* p, int a);
// FUN_00dfffd0 : a one-line function - getter
extern int g_target_00dfffd0;
void* FUN_00dfffd0();
extern void* DAT_010e80b4;
void** __cdecl FUN_00dffff0();
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

#include "../../include/hkRotation.h"

class DE1FC0ReferencedObject
{
  public:
    DE1FC0ReferencedObject()
    {
        m_sReferenceCount = 1;
    }
    virtual void vfunc00();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class DE1FC0Transform : public DE1FC0ReferencedObject
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
    hkRotation m_rotation;
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
        m_kColumn0.f[0] = 1.0f;
        m_kColumn1.f[1] = 1.0f;
        m_kColumn2.f[2] = 1.0f;
        m_vTranslation.m_vComponents = _mm_setzero_ps();
    }
};
class DE5450ReferencedObject
{
  public:
    DE5450ReferencedObject() : m_sReferenceCount(1)
    {}
    virtual void unk00();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class DE5450Shape : public DE5450ReferencedObject
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
void FUN_00df19e0(int, hkVector4*, Matrix64*, void*, void*, void*, void*, void*, int);
void WriteInputHeader(Input* input, void*, Header** cursor);
extern "C" const __m128 DAT_011b9490;
// @fnv 0x00df2740
extern "C" __m128 __cdecl FUN_00df2740()
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
void FUN_00df6500(void* p, int finishing);
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
void __cdecl FUN_00dfca00(void* pvObject, int iFinishing);
struct FnvCpu_FUN_00de1150_CpuObject
{
    char* FUN_00de1150();
};
struct FnvCpu_FUN_00de1160_CpuObject
{
    char* FUN_00de1160();
};
struct FnvCpu_FUN_00de4de0_CpuObject
{
    char* FUN_00de4de0();
};
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
struct stub_cls
{
    int unk00;
};
static void FUN_00df30c0(stub_cls* self, int v);
extern "C" int stub_val(void);
void stub_caller(stub_cls* self);
struct DF30D0Pair
{
    unsigned int m_ucLowNibble;
    unsigned int m_ucHighNibble;
};
static void CopyPairAtIndex(DF30D0Pair* dst, unsigned int idx, const DF30D0Pair* src);
void DF30D0Caller(DF30D0Pair* dst, unsigned int idx, const DF30D0Pair* src);
void FUN_00df3160();
void FUN_00df64a0();
void __cdecl FUN_00df6540();
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
    char* __thiscall FUN_00df7210(char* out);
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
struct FnvCpu_FUN_00dfee80_CpuInterface
{
    virtual void Invoke(int value);
};
void __cdecl FUN_00dfee80(FnvCpu_FUN_00dfee80_CpuInterface* object);
struct DestructibleDFF
{
    virtual ~DestructibleDFF();
};
void __cdecl FUN_00dff5a0(DestructibleDFF* pkObject);
struct S00de0fe0_Element
{
    virtual void vf00(int value);
};
struct S00de0fe0_Arr
{
    S00de0fe0_Element** data;
    int count;
    int cap;
    void __thiscall FUN_00ddfb70();
};
struct S00de0fe0_Obj10
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void __thiscall FUN_00ddfb80(int* value);
    void __thiscall FUN_00de0f90(int count, S00de0fe0_Element*** array);
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
__declspec(noinline) void S00de0fe0_Arr::FUN_00ddfb70()
{
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
int __cdecl FUN_00d1b930(void* processor, WorkItem* item, unsigned int* value, int remaining);
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
void __cdecl FUN_00df6e00(Job* job, int a, int b, int c);
struct Scheduler
{
    int ProcessCallback(Key* key, int b, int a);
};
void __cdecl FUN_00df6f80(Scheduler* self, Job* job);
struct FUN_00df9840_Class
{
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
struct FUN_00dfb5a0_cls
{
    int unk00;
    char* m_pData;
    int m_iArrayLength;
    unsigned int m_uCap;

    void FUN_00dfb5a0();
};
template <class T> inline void DestructElementsDFB5A0(T* p, int n)
{
    for (int i = 0; i < n; ++i)
    {
        p[i].FUN_00cb0c00();
    }
}
struct ElemDFB5A0
{
    int unk00;
    FUN_00cb0c00_class m_04;
    void FUN_00cb0c00()
    {
        m_04.FUN_00cb0c00();
    }
};

extern "C" void* df3210_target(void);

// @fnv 0x00df3210
static __declspec(noinline) void FUN_00df3210(__m128* p)
{
    __m128 z = _mm_setzero_ps();
    *p++ = z;
    *p++ = z;
    *p++ = z;
    *p++ = z;
    *p++ = z;
    *p++ = z;
    *p++ = z;
    *p++ = z;
}

void df3210_caller(void)
{
    FUN_00df3210((__m128*)df3210_target());
}

extern const float DAT_010cd644;

// @fnv 0x00df3170
static __declspec(noinline) void FUN_00df3170(const unsigned short* src, hkVector4* d)
{
    __m128i zero = _mm_setzero_si128();
    __m128i data = _mm_loadu_si128((const __m128i*)src);
    __m128i lo = _mm_unpacklo_epi16(data, zero);
    __m128i hi = _mm_unpackhi_epi16(data, zero);
    __declspec(align(16)) float k2[4] = {DAT_010cd644, DAT_010cd644, DAT_010cd644, DAT_010cd644};
    __declspec(align(16)) float k1[4] = {DAT_010cd644, DAT_010cd644, DAT_010cd644, DAT_010cd644};
    d->m_vComponents = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi32(hi, 16)), _mm_load_ps(k1)),
                                 _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(hi, 16), 16))),
                      _mm_add_ps(_mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi32(lo, 16)), _mm_load_ps(k2)),
                                 _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(lo, 16), 16))));
}
void CallerStandIn(hkVector4* d, const unsigned short* src)
{
    FUN_00df3170(src, d);
}
