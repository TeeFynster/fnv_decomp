#define FNV64_HKVECTOR4_PACKET_BODIES
#define FNV64_HKVECTOR4_OWN_CONVERSION
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4
// src/staging/blk_00e00000_o2_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00e00000_o2.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.


// src/staging/blk_00e00000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/BSAudio.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkVector4.h"
#include "../../include/hkArray.h"
#include "../../include/FinishingFlag.h"
#include "../../include/hkSmallArray.h"
#include "../../include/Vec4.h"
extern int DAT_010305a8;
extern int DAT_010c749c;
void __cdecl finishLoadedObjecthkpTriangleShape(int* pObject, int b);
extern int DAT_010305a8;
extern int DAT_010cb5ac;
void finishLoadedObjecthkpSphereShape(int* pObject, int flag);
extern int DAT_010305a8;
extern int DAT_010ce4bc;
void hkpMultiSphereShape_hkpMultiSphereShape_0(int* pObject, int flag);
extern int DAT_010305a8;
extern int DAT_010ce25c;
void finishLoadedObjecthkpCapsuleShape(int* pObject, int b);
extern int DAT_010305a8;
extern int DAT_010c70b4;
void __cdecl finishLoadedObjecthkpBoxShape(int* pObject, int a);
extern int DAT_010e99d8;
struct FUN_00cb0a70
{
    void __thiscall m(int);
};
void Object_UpdateState_00e01c30(void* apObject, void* aValue);
extern int DAT_010c9314;
void Object_UpdateFields_00e02780(void* apObject);
int IsInRange(int aiValue, int aiLowerBound, int aiUpperBound);
void Object_UpdateFields_00e04a60(void* pData);
struct FUN_00e10740_a
{
    int a;
    float b;
};
struct FUN_00e10740_b
{
    int c;
    float d;
};
int __cdecl hkCompareInfosBySize(const FUN_00e10740_a* pLeft, const FUN_00e10740_b* pRight);
struct FUN_00e11960_cls
{
    int m_2c;
    int hkgpMesh_countParts();
};
struct FUN_00e11d80_class
{
    void SetValueForAllNodes(int idx, float val);
};
struct FUN_00e11da0_class
{
    void hkgpMesh_setVerticesTag(int value);
};
struct FUN_00e000a0_vt
{
    virtual void m(int);
};
void __cdecl Object_InvokeVirtualMethod_00e000a0(FUN_00e000a0_vt* p);
extern int DAT_010c59f4;
extern int DAT_010c6cdc;
void __cdecl Object_UpdateFields_00e00120(int* pObject, int bSetHalf);
extern int DAT_010e81a4;
void __cdecl Object_UpdateFields_00e00180(int* p);
struct FUN_00e002d0_vt
{
    virtual void Runtime_ForwardCall_00e002d0(int);
};
void __cdecl Runtime_ForwardCall_00e002d0(FUN_00e002d0_vt* p);
extern int DAT_010c59f4;
extern int DAT_010c6ea4;
void __cdecl Object_UpdateState_00e002f0(int* pObject, int bSetValue);
extern int DAT_010e83b4;
void __cdecl Runtime_UpdateState_00e00350(int* a);
void __cdecl Object_InvokeVirtualMethod_00e00720(void* p);
extern int DAT_010305a8;
extern int DAT_010c6fd0;
extern int DAT_010cc41c;
void __cdecl finishLoadedObjecthkpTransformShape(int* pObject, int bClear);
extern int DAT_010e8824;
void __cdecl Runtime_UpdateState_00e00810(int* p);
struct FUN_00e00930_vt
{
    virtual void __thiscall m0(int);
};
void __cdecl Runtime_ForwardCall_00e00930(FUN_00e00930_vt* p);
void __cdecl Object_ProcessAndTransformResult_00e00b40(int* p);
struct FUN_00e00c70_vt
{
    virtual void __thiscall m0(int);
};
void __cdecl Runtime_ForwardCall_00e00c70(FUN_00e00c70_vt* p);
extern int DAT_010c63cc;
void __cdecl Runtime_UpdateState_00e00d10(int* p);
int __cdecl Runtime_EvaluateValue_00e00d30(int* p);
extern int DAT_010e8d8c;
void __cdecl Runtime_UpdateState_00e00db0(int* a);
extern int DAT_010305a8;
extern int DAT_010c6fd0;
extern int DAT_010d0e5c;
void __cdecl finishLoadedObjecthkpConvexTranslateShape(int* pObject, int bClear);
extern int DAT_010305a8;
extern int DAT_010c6fd0;
extern int DAT_010d102c;
void __cdecl finishLoadedObjecthkpConvexTransformShape(int** a, int abReset);
extern int DAT_010305a8;
extern int DAT_010ce31c;
extern int DAT_010e901c;
void __cdecl Object_UpdateFields_00e010e0(int* pObject, int abFlag);
void __cdecl Runtime_Helper_00e011f0(void* a);
extern int DAT_010305a8;
extern int DAT_010c6ff8;
extern int DAT_010c6fd0;
void __cdecl Object_UpdateFields_00e013a0(int** p, int abClear);
extern int DAT_010e9300;
void Runtime_UpdateState_00e01530(int* p);
extern int DAT_010e9358;
void Runtime_UpdateState_00e01570(int* p);
extern int DAT_010e93ac;
void Runtime_UpdateState_00e015b0(int** p);
typedef void(__thiscall* Fn)(void*, int);
void __cdecl Object_ProcessState_00e01640(int* p);
extern int DAT_010e943c;
void __cdecl Object_UpdateFields_00e01660(int* p);
extern int DAT_010e9494;
void __cdecl Object_UpdateFields_00e016a0(int* p);
struct FUN_00e017d0_vt
{
    virtual void Runtime_ForwardCall_00e017d0(int);
};
void __cdecl Runtime_ForwardCall_00e017d0(FUN_00e017d0_vt* p);
extern int DAT_010e95b4;
void Object_UpdateState_00e017f0(FUN_00cb0a70** apObject, int aiValue);
extern int DAT_010e9614;
void Object_UpdateFields_00e018e0(int* a);
extern int DAT_010e350c;
void __cdecl Runtime_UpdateState_00e019f0(int* p);
extern int DAT_010e96c8;
void __cdecl Runtime_UpdateState_00e01a30(int* p);
extern int DAT_010e977c;
void __cdecl Runtime_UpdateState_00e01b10(int* a);
extern int DAT_010e9b7c;
void __cdecl Runtime_UpdateState_00e01f50(int* p);
struct FUN_00e020e0_vt
{
    virtual int Object_ForwardCall_00e020e0(int);
};
int __cdecl Object_ForwardCall_00e020e0(FUN_00e020e0_vt* c);
extern int DAT_010e9ccc;
void __cdecl Object_UpdateFields_00e02140(int* pObject, int iValue);
void __cdecl Object_InvokeVirtualMethod_00e02260(int** p);
typedef int(__thiscall* FUN_00e02340_fn)(void*, int);
int __cdecl Object_GetIndexedValue_00e02340(void* obj);
extern int DAT_010e9e74;
void __cdecl Object_UpdateFields_00e02360(int* p);
extern int DAT_010e9f48;
void Object_UpdateFields_00e023a0(int* p);
extern int DAT_010e9fa4;
void Object_UpdateFields_00e02480(int* p);
extern int DAT_010ea0a4;
void __cdecl Object_UpdateFields_00e024c0(int* p);
typedef int(__thiscall* VFunc0)(void*, int);
int __cdecl Object_GetIndexedValue_00e024e0(void* p);
extern int DAT_010e310c;
void Object_UpdateFields_00e02500(int* a);
extern int DAT_010ea10c;
void __cdecl Object_UpdateFields_00e02540(int** p);
extern int DAT_010ea154;
void __cdecl Object_UpdateFields_00e02580(int* a);
extern int DAT_010ea188;
void Runtime_UpdateState_00e02630(int* p);
struct FUN_00e026c0_vtbl
{
    virtual int v0(int);
};
int __cdecl Object_InvokeVirtualMethod_00e026c0(FUN_00e026c0_vtbl* p);
extern int DAT_010ea1ac;
void __cdecl Object_UpdateFields_00e026e0(int* p);
struct FUN_00e02720_vtbl
{
    virtual void m0(int);
};
void Object_InvokeVirtualMethod_00e02720(FUN_00e02720_vtbl* p);
typedef void(__thiscall* vt)(void*, int);
void __cdecl Object_ProcessState_00e02760(void* p);
struct FUN_00e0bf20_s
{
    int a;
    int b;
    void __thiscall FUN_00cb0a60();
    FUN_00e0bf20_s();
};
struct FUN_00e11dc0_class
{
    int m_iWordAt00;
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
    void __thiscall hkgpMesh_copyPartIdToVerticesW();
};
int __cdecl Object_InvokeVirtualMethod_00e00100(void* p);
void Object_InvokeVirtualMethod_00e00160(FUN_00e000a0_vt* p);
struct FUN_00e001a0_vt
{
    virtual void m(int);
};
void __cdecl Object_InvokeVirtualMethod_00e001a0(FUN_00e001a0_vt* p);
extern int DAT_010cc2fc;
extern int DAT_010d79c4;
void Object_UpdateFields_00e001c0(FUN_00cb0a70* obj, int aiValue);
int* __cdecl Object_GetGlobalObjectAddress_00e00320();
struct FUN_00e00330_vt
{
    virtual void m(int);
};
void __cdecl Runtime_ForwardCall_00e00330(FUN_00e00330_vt* p);
struct FUN_00e00370_vt
{
    virtual void m0(int);
};
void __cdecl Runtime_ForwardCall_00e00370(FUN_00e00370_vt* p);
struct FUN_00e00430_vt
{
    virtual void __thiscall m0(int);
};
void __cdecl Runtime_ForwardCall_00e00430(FUN_00e00430_vt* p);
extern int DAT_010c59f4;
extern int DAT_010c6dc4;
void __cdecl Object_UpdateState_00e00450(void* apObject, int flag);
typedef void(__thiscall* VFn)(void*, int);
void __cdecl Runtime_UpdateState_00e00550(void* p);
struct FUN_00e005b0_vt
{
    virtual void m(int);
};
void __cdecl Runtime_ForwardCall_00e005b0(FUN_00e005b0_vt* p);
struct FUN_00e00670_vt
{
    virtual void m0(int);
};
void __cdecl Runtime_ForwardCall_00e00670(FUN_00e00670_vt* p);
struct FUN_00e00790_vt
{
    virtual void __thiscall m(int);
};
void __cdecl Runtime_ForwardCall_00e00790(FUN_00e00790_vt* p);
struct FUN_00e007f0_vt
{
    virtual void m0(int);
};
void __cdecl Runtime_ForwardCall_00e007f0(FUN_00e007f0_vt* p);
struct FUN_00e00a20_vt
{
    virtual void m0(int);
};
void __cdecl Object_InvokeVirtualMethod_00e00a20(FUN_00e00a20_vt* p);
void __cdecl Object_InvokeVirtualMethod_00e00ae0(FUN_00e00930_vt* p);
struct FUN_00dcd380_cls
{
    void __thiscall FUN_00dcd380(int b);
};
extern int DAT_010e8a90;
extern int DAT_010e8ab0;
void __cdecl Object_UpdateState_00e00c90(void* pObject, int b);
struct FUN_00e00cf0_vt
{
    virtual void m(int);
};
void __cdecl Runtime_ForwardCall_00e00cf0(FUN_00e00cf0_vt* p);
struct FUN_00e00d90_vt
{
    virtual void m(int);
};
void __cdecl Runtime_ForwardCall_00e00d90(FUN_00e00d90_vt* p);
struct FUN_00e00e70_vt
{
    virtual int Runtime_ForwardCall_00e00e70(int);
};
int __cdecl Runtime_ForwardCall_00e00e70(FUN_00e00e70_vt* p);
void __cdecl Object_InvokeVirtualMethod_00e010c0(FUN_00e000a0_vt* p);
struct FUN_00e01380_vt
{
    virtual void m(int);
};
void __cdecl Object_InvokeVirtualMethod_00e01380(FUN_00e01380_vt* p);
typedef void(__thiscall* Fn0)(void*, int);
void __cdecl Runtime_UpdateState_00e013f0(void* p);
typedef int(__thiscall* Vfn)(void*, int);
int __cdecl Runtime_EvaluateValue_00e01450(void* p);
extern int DAT_0126e330;
int* __cdecl Object_GetGlobalObjectAddress_00e01460();
extern int DAT_010e929c;
struct FUN_00e01470_s
{
    int m_iWordAt00;
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
    FUN_00cb0a70* m_2c;
};
void __cdecl Object_UpdateState_00e01470(FUN_00e01470_s* pObject, int iValue);
void __cdecl Runtime_Helper_00e01510(FUN_00cb0a70* p);
struct FUN_00e01550_vt
{
    virtual void m0(int);
};
void __cdecl Runtime_ForwardCall_00e01550(FUN_00e01550_vt* p);
void __cdecl Object_ProcessAndTransformResult_00e018c0(int* p);
typedef void(__thiscall* Fn)(void*, int);
void __cdecl Runtime_UpdateState_00e019d0(void* p);
struct FUN_00e01a10_vt
{
    virtual void m0(int);
};
void __cdecl Runtime_ForwardCall_00e01a10(FUN_00e01a10_vt* p);
typedef void(__thiscall* Fn)(void*, int);
void __cdecl Runtime_UpdateState_00e01af0(void* p);
struct FUN_00e01c10_vt
{
    virtual void m(int);
};
void __cdecl Runtime_ForwardCall_00e01c10(FUN_00e01c10_vt* p);
struct FUN_00e01cd0_vt
{
    virtual void m(int);
};
void __cdecl Runtime_ForwardCall_00e01cd0(FUN_00e01cd0_vt* p);
extern int DAT_010e9a34;
void finishLoadedObjecthkpSerializedAgentNnEntry_00e01cf0(void* pObject, void* b);
struct FUN_00e01e40_vt
{
    virtual void m0(int);
};
void __cdecl Object_InvokeVirtualMethod_00e01e40(FUN_00e01e40_vt* p);
void __cdecl Runtime_Helper_00e01f30(int* p);
extern int DAT_010e9dec;
struct FUN_00cb0a70_00e02280
{
    int* vt;
    int pad;
    int pad2;
    void __thiscall m(int);
};
void __cdecl Object_UpdateFields_00e02280(int* pObject, int iValue);
typedef void(__thiscall* VFn)(void*, int);
void __cdecl Object_ProcessState_00e02380(void* p);
typedef int(__thiscall* Vf0)(void*, int);
int __cdecl Object_ComputeValue_00e024a0(void* p);
int* __cdecl Runtime_GetDAT010e310cAddress();
struct FUN_00e02560_vt
{
    virtual int m(int);
};
int __cdecl Object_InvokeVirtualMethod_00e02560(FUN_00e02560_vt* p);
int __cdecl Runtime_ForwardCall_00e02610(FUN_00e026c0_vtbl* p);
struct FUN_00e027b0_cls
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    void ApplyRelocations(int base);
};
struct FUN_00e0bf30_s
{
    int a;
    int b;
    FUN_00cb0a70 c;
    FUN_00e0bf30_s* __thiscall hkMonitorStreamStringMap_StringMap_StringMap(int v);
};
void* __cdecl GetConvexHull();
struct FUN_00d752e0_cls
{
    void __thiscall hkgpConvexHull_getVolume();
};
void __cdecl Runtime_ForwardCall_00e114b0();
struct FUN_00e11d60_class
{
    int m_iWordAt00;
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
    int* m_2c;
    int m_30;
    void __thiscall hkgpMesh_setPartId(int val);
};
BSAudio* __cdecl hkMemoryRouter_getInstance();
extern int DAT_0102e388;
struct FUN_00e00000_cls
{
    int m_vptr00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void* m_pData2;
    int m_iCount2;
    unsigned int m_uCapBits2;
    void* m_pData1;
    int m_iCount1;
    unsigned int m_uCapBits1;

    void ReleaseBothArrays();
};
extern int DAT_0126d9a0;
int __cdecl Runtime_EvaluateValue_00e000b0();
// Forward a value to the owner object when the owner pointer is present.
struct FUN_00d50c00_cls
{
    void __thiscall FUN_00d50c00(int value);
};
void __cdecl Object_ProcessState_00e000c0(FUN_00d50c00_cls* pOwner, int value);
struct CpuOpaque;
extern CpuOpaque DAT_0126d9e8;
CpuOpaque* __cdecl Runtime_GetDAT0126d9e8Address();
extern int DAT_010c6cdc;
int* Runtime_GetDAT010c6cdcAddress();
extern int DAT_0126da30;
int* __cdecl Runtime_GetDAT0126da30Address();
extern int DAT_010e81a4;
void* __cdecl Runtime_GetDAT010e81a4Address();
extern int DAT_0126da78;
int* __cdecl Runtime_GetDAT0126da78Address();
struct FUN_00e00220_Class
{
    virtual void VF00(int value);
};
void __cdecl Object_InvokeVirtualMethod_00e00220(FUN_00e00220_Class* param_1);
extern int g_unk0126dac0;
void* __cdecl Runtime_GetUnk0126dac0Address();
// FUN_00e002e0 : a one-line function - getter
extern int g_target_00e002e0;
void* Object_GetGlobalObjectAddress_00e002e0();
extern int g_unk0126db50;
void* __cdecl Object_GetGlobalObjectAddress_00e00340();
extern int DAT_010e83b4;
int* __cdecl Object_GetGlobalObjectAddress_00e00360();
extern unsigned char DAT_0126db98;
void* __cdecl Object_GetGlobalObjectAddress_00e00380();
struct E00390FinishFlag
{
    int m_bFinishing;
};
class E00390Object
{
  public:
    E00390Object(E00390FinishFlag flag);

    static void* operator new(unsigned int, void* p)
    {
        return p;
    }
};
void Runtime_AllocateStorage_00e00390(void* apMemory, int aiFinishFlag);
struct S_00e003d0_Arr
{
    int* data;
    int size;
    unsigned cap;
    S_00e003d0_Arr() : data(0), size(0), cap(0x80000000)
    {}
};
struct S_00e003d0_Base
{
    virtual void unk00();
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
    S_00e003d0_Base(int flag);
};
struct S_00e003d0_Arrs
{
    S_00e003d0_Arr arr8c;
    S_00e003d0_Arr arr98;
};
struct FUN_00e003d0 : S_00e003d0_Base, S_00e003d0_Arrs
{
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    S_00e003d0_Arr arr160;
    FUN_00e003d0(int flag);
};
void S_00e003d0_Base::unk00()
{}
extern int DAT_0126dbe0;
int* __cdecl Object_GetGlobalObjectAddress_00e00440(void);
extern int DAT_010c6dc4;
void* Object_GetGlobalObjectAddress_00e00480();
struct S_00e00490_vt
{
    virtual void m(int);
};
void __cdecl Runtime_ForwardCall_00e00490(S_00e00490_vt* p);
extern int DAT_0126dc28;
int* __cdecl Object_GetGlobalObjectAddress_00e004a0();
struct FUN_00e004f0_class
{
    void __thiscall FUN_00e004f0(int value);
};
void __cdecl Runtime_ProcessState_00e004b0(FUN_00e004f0_class* object, int value);
extern int DAT_0126dc70;
int* __cdecl Object_GetGlobalObjectAddress_00e00560();
extern int DAT_010c749c;
int* Object_GetGlobalObjectAddress_00e005a0();
extern int DAT_0126dcb8;
void* __cdecl Object_GetGlobalObjectAddress_00e005c0();
struct Handler_cls
{
    void __thiscall Handle(int value);
};
void __cdecl Runtime_ProcessState_00e005d0(Handler_cls* pHandler, int value);
struct S_00e00610_P
{
    virtual void unk00();
    int unk04;
    int unk08;
    int unk0c;
    S_00e00610_P(int flag)
    {
        if (flag != 0)
            unk0c = 0;
    }
};
struct S_00e00610_S
{
    virtual void unk00();
    char unk04;
    char unk05;
    char unk06;
    char unk07;
    int unk18;
    int unk1c;
};
struct S_00e00610_Mid : S_00e00610_P, S_00e00610_S
{
    virtual void unk00();
    S_00e00610_Mid(int flag) : S_00e00610_P(flag)
    {
        if (flag != 0)
        {
            unk0c = 7;
            S_00e00610_S::unk05 = 3;
        }
    }
};
void S_00e00610_P::unk00()
{}
void S_00e00610_S::unk00()
{}
void S_00e00610_Mid::unk00()
{}
struct FUN_00e00610 : S_00e00610_Mid
{
    FUN_00e00610(int flag);
};
extern int DAT_0126dd00;
int* Object_GetGlobalObjectAddress_00e00680();
// FUN_00e00690: null-guarded forwarding of a second argument to a
// member function of the first (object) argument.
class FUN_00e00690_cls
{
  public:
    void FUN_00e006d0(int a1);
};
void __cdecl Object_ProcessState_00e00690(FUN_00e00690_cls* pObject, int aiValue);
extern int DAT_010c6fd0;
struct S_00e006d0_A
{
    virtual void v0();
    int unk04;
    int unk08;
    int unk0c;
    char unk10;
    __forceinline S_00e006d0_A(int flag)
    {
        if (flag)
            unk0c = 0;
    }
};
struct S_00e006d0_B : S_00e006d0_A
{
    virtual void v0();
    __forceinline S_00e006d0_B(int flag) : S_00e006d0_A(flag)
    {
        if (flag)
        {
            unk0c = 8;
            unk10 = 2;
        }
    }
};
struct FUN_00e006d0 : S_00e006d0_B
{
    int* unk14;
    virtual void v0();
    FUN_00e006d0(int flag);
};
extern int DAT_0126dd48;
int __cdecl Runtime_EvaluateValue_00e00730();
extern int DAT_010cc41c;
int* __cdecl Object_GetGlobalObjectAddress_00e00780();
struct CpuOpaque;
extern CpuOpaque DAT_0126dd90;
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00e007a0();
extern int DAT_010cb5ac;
int* __cdecl Object_GetGlobalObjectAddress_00e007e0();
struct CpuOpaque;
extern CpuOpaque DAT_0126ddd8;
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00e00800();
extern int DAT_010e8824;
int* Object_GetGlobalObjectAddress_00e00820();
struct S_00e00830_Allocator
{
    virtual void unk0();
    virtual void unk4();
    virtual void unk8();
    virtual void unkC();
    virtual void ReturnMemory(void* p, int nbytes);
};
struct S_00e00830_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00e00830_Allocator* m_pStreamAllocator;
    static S_00e00830_Router& hkMemoryRouter_getInstance();
    S_00e00830_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
struct S_00e00830_Ref
{
    void* m_ptr;
    void Object_UpdateFields_00cb0c00() throw();
    ~S_00e00830_Ref() throw()
    {
        Object_UpdateFields_00cb0c00();
    }
};
struct S_00e00830_Target
{
    void FUN_00c905b0() throw();
};
struct S_00e00830_Ptr
{
    S_00e00830_Target* m_p;
    ~S_00e00830_Ptr() throw()
    {
        if (m_p)
            m_p->FUN_00c905b0();
        m_p = 0;
    }
};
struct S_00e00830_Elem64
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
};
template <typename T> struct S_00e00830_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline void _clearAndDeallocate(S_00e00830_Allocator& alloc) throw()
    {
        T* p = m_data;
        int n = m_iElementCount;
        for (int i = 0; i < n; i++)
        {
            p[i].~T();
        }
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline ~S_00e00830_Array() throw()
    {
        _clearAndDeallocate(S_00e00830_Router::hkMemoryRouter_getInstance().heap());
    }
};
struct S_00e00830_Base
{
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    virtual ~S_00e00830_Base() throw()
    {}
};
struct FUN_00e00830 : S_00e00830_Base
{
    S_00e00830_Ptr m_ptr;
    int unk0c;
    S_00e00830_Array<S_00e00830_Ref> m_refs;
    S_00e00830_Array<S_00e00830_Elem64> m_pElements;
    ~FUN_00e00830() throw();
};
// FUN_00e00940 : a one-line function - getter
extern int g_target_00e00940;
void* Object_GetGlobalObjectAddress_00e00940();
// Resets an object to the "script terminal" class layout: it installs the
// secondary base vtable, the primary vtable and finally the derived vtable.
extern int DAT_010e8894;
extern int DAT_010e88b4;
extern int DAT_010e88a4;
void __cdecl Object_UpdateState_00e00950(int* pObject);
extern int DAT_010e88b4;
int __cdecl Runtime_EvaluateValue_00e00970();
extern "C" struct FUN_00e009c0_vt
{
    virtual void m0(int);
};
// @fnv 0x00e009c0
// src: GUESS 0x00e009c0 (confidence: low)
extern "C" void __cdecl Object_InvokeVirtualMethod_00e009c0(FUN_00e009c0_vt* p)
{
    p->m0(0);
}
struct CpuOpaque;
extern CpuOpaque DAT_0126de68;
CpuOpaque* __cdecl Runtime_GetDAT0126de68Address();
extern int DAT_010d0e18;
int* __cdecl Runtime_GetDAT010d0e18Address();
// FUN_00e00a30 : a one-line function - getter
extern int g_target_00e00a30;
void* Runtime_GetTarget00e00a30Address();
struct FUN_00e00a40_cls
{
    void __thiscall FUN_00e00a80(int a);
};
void __cdecl Object_ProcessState_00e00a40(FUN_00e00a40_cls* pObject, int a);
class __declspec(novtable) BE00A80Base
{
  public:
    virtual ~BE00A80Base();

    int m_iRefCount;
};
class BE00A80InterfaceA
{
  public:
    virtual void OnA();
};
class BE00A80InterfaceB
{
  public:
    virtual void OnB();
};
class BE00A80InterfaceC
{
  public:
    virtual void OnC();
};
class BE00A80InterfaceD
{
  public:
    virtual void OnD();
};
class FUN_00e00a80_cls : public BE00A80Base,
                         public BE00A80InterfaceA,
                         public BE00A80InterfaceB,
                         public BE00A80InterfaceC,
                         public BE00A80InterfaceD
{
  public:
    FUN_00e00a80_cls(int iEnabled);
    virtual ~FUN_00e00a80_cls();
    virtual void OnA();
    virtual void OnB();
    virtual void OnC();
    virtual void OnD();

    int m_iFirst;
    int m_iSecond;
    int m_iEnabled;
};
extern char DAT_0126def8;
char* __cdecl Runtime_GetDAT0126def8Address(void);
extern int DAT_010ce4bc;
void* Runtime_GetDAT010ce4bcAddress();
extern int g_unk0126df40;
void* __cdecl Runtime_GetUnk0126df40Address();
inline void* operator new(unsigned int, void* pvWhere) throw()
{
    return pvWhere;
}
struct E00B60FinishFlag
{
    int m_bFinishing;
};
class E00B60Object
{
  public:
    E00B60Object(E00B60FinishFlag flag);

    int unk00;
};
void ConstructObjectWithFinishFlag(void* apMemory, int finishing);
// FUN_00e00ba0: thiscall ctor-like (flag arg) storing a primary vtable at +0 and
// secondary vtables at +8, +0xc, +0x10, +0x14, then an optional int at +0x20.
struct E00ba0_b0
{
    virtual void unk00();
    int unk04;
};
struct E00ba0_b1
{
    virtual void unk00();
};
struct E00ba0_b2
{
    virtual void unk00();
};
struct E00ba0_b3
{
    virtual void unk00();
};
struct E00ba0_b4
{
    virtual void unk00();
};
class FUN_00e00ba0 : E00ba0_b0, E00ba0_b1, E00ba0_b2, E00ba0_b3, E00ba0_b4
{
  public:
    int unk18;
    int unk1c;
    int m_20;
    FUN_00e00ba0(int flag);
};
struct CpuOpaque;
extern CpuOpaque DAT_0126df88;
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00e00c80();
extern int DAT_0126dfd0;
int* __cdecl Object_GetGlobalObjectAddress_00e00d00();
// FUN_00e00d20: cdecl, returns the address of a global object.
extern int DAT_010c63cc;
int* __cdecl Object_GetGlobalObjectAddress_00e00d20();
extern int DAT_0126e018;
int* __cdecl Object_GetGlobalObjectAddress_00e00d40();
struct FUN_00d57b20_class
{
    void __thiscall hkpCylinderShape_hkpCylinderShape_00d57b20(int value);
};
void __cdecl hkpCylinderShape_hkpCylinderShape_00d57b20_ProcessState_00e00d50(FUN_00d57b20_class* pObject, int value);
extern int DAT_0126e060;
void* __cdecl Object_GetGlobalObjectAddress_00e00da0();
extern int DAT_010e8d8c;
int* __cdecl Object_GetGlobalObjectAddress_00e00dc0();
extern int DAT_0126e0a8;
void* __cdecl Object_GetGlobalObjectAddress_00e00e80();
extern int DAT_010d0e5c;
int* __cdecl Runtime_GetDAT010d0e5cAddress();
struct S_00e00ee0_vt
{
    virtual void m0(int a);
};
void __cdecl Object_InvokeVirtualMethod_00e00ee0(S_00e00ee0_vt* p);
extern int DAT_0126e0f0;
void* __cdecl Runtime_GetDAT0126e0f0Address();
extern int DAT_010d102c;
void* Object_GetGlobalObjectAddress_00e00f40();
// FUN_00e00f50: calls the first virtual (slot 0) of the object passed in the
// first stack argument, with a single 0 argument.
struct FUN_00e00f50_cls
{
    virtual void m_fn(int aParam);
};
void __cdecl Runtime_ForwardCall_00e00f50(FUN_00e00f50_cls* pObj);
extern int DAT_0126e138;
int* __cdecl Object_GetGlobalObjectAddress_00e00f60();
// FUN_00e00f70: forwards a value to a helper on the passed-in object
// when that object is present.
struct FUN_00e00f70_cls
{
    void __thiscall FUN_00e00fb0(int value);
};
void __cdecl Object_ProcessState_00e00f70(FUN_00e00f70_cls* pObject, int value);
extern int DAT_010305a8;
extern int DAT_010c6fb0;
extern int DAT_010cc364;
extern int DAT_010cc344;
extern int DAT_010e8e94;
extern int DAT_010e8e74;
class FUN_00e00fb0
{
  public:
    void* m_vptr;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    void* m_10;
    unsigned char m_14;
    unsigned char m_15;

    FUN_00e00fb0(int flag);
};
struct VirtualSlotObject
{
    virtual void unk00(int arg);
};
void __cdecl Runtime_ForwardCall_00e01050(VirtualSlotObject* p);
extern int DAT_0126e180;
int* __cdecl Object_GetGlobalObjectAddress_00e01060();
extern int DAT_010c6fb0;
extern int DAT_010d10c4;
extern int DAT_010d10a4;
struct InitObject
{
    void* m_pVTable;  // +0x00
    int m_i04;        // +0x04
    int m_i08;        // +0x08
    int m_i0C;        // +0x0C
    int m_i10;        // +0x10
    void* m_pSlot;    // +0x14
};
void __cdecl InitObjectFields(volatile InitObject* pObject, int iFlag);
extern int DAT_010d10c4;
void* __cdecl Runtime_GetDAT010d10c4Address();
extern int DAT_0126e1c8;
void* __cdecl Runtime_GetDAT0126e1c8Address(void);
extern int DAT_010e901c;
void* __cdecl Runtime_GetDAT010e901cAddress();
extern int DAT_0126e210;
void* __cdecl Object_GetGlobalObjectAddress_00e01200();
// FUN_00e01250: thiscall ctor (flag arg) storing secondary vtables at +8,+0xc,+0x10,+0x14
// from inline base ctors, then the primary vtable at +0, then the secondary vtables again,
// then an optional int at +0x20.
struct E01250_b0
{
    virtual void unk00();
    int unk04;
};
struct E01250_b1
{
    virtual void unk00();
};
struct E01250_b2
{
    virtual void unk00();
};
struct E01250_b3
{
    virtual void unk00();
};
struct E01250_b4
{
    virtual void unk00();
};
class FUN_00e01250 : E01250_b0, E01250_b1, E01250_b2, E01250_b3, E01250_b4
{
  public:
    int unk18;
    int unk1c;
    int m_20;
    FUN_00e01250(int flag);
};
struct FUN_00e01320_cls
{
    virtual void m_v00(int arg);
};
void __cdecl Object_InvokeVirtualMethod_00e01320(FUN_00e01320_cls* pObject);
extern int DAT_0126e258;
int* __cdecl Runtime_GetDAT0126e258Address(void);
extern int DAT_010ce25c;
int* __cdecl Runtime_GetDAT010ce25cAddress();
extern int DAT_0126e2a0;
int __cdecl Runtime_EvaluateValue_00e01390();
void* __cdecl Object_GetGlobalObjectAddress_00e013e0();
extern int DAT_0126e2e8;
int* __cdecl Object_GetGlobalObjectAddress_00e01400();
extern int DAT_010c70b4;
int* __cdecl Object_GetGlobalObjectAddress_00e01440();
// FUN_00e01520 : a one-line function - getter
extern int g_target_00e01520;
void* Object_GetGlobalObjectAddress_00e01520();
extern int DAT_010e9300;
int* Object_GetGlobalObjectAddress_00e01540();
extern int DAT_0126e3c0;
void* __cdecl Object_GetGlobalObjectAddress_00e01560();
extern int DAT_010e9358;
int* __cdecl Object_GetGlobalObjectAddress_00e01580();
struct FnvCpu_FUN_00e01590_CpuInterface
{
    virtual void Invoke(int value);
};
void __cdecl Runtime_ForwardCall_00e01590(FnvCpu_FUN_00e01590_CpuInterface* object);
extern int DAT_0126e408;
int* __cdecl Object_GetGlobalObjectAddress_00e015a0();
extern int DAT_010e93ac;
void* __cdecl Object_GetGlobalObjectAddress_00e015c0();
struct CpuOpaque;
extern CpuOpaque DAT_0126e450;
CpuOpaque* __cdecl Runtime_GetDAT0126e450Address();
extern int DAT_010e943c;
void* __cdecl Runtime_GetDAT010e943cAddress();
struct CallerVtbl
{
    virtual int v0(int);
};
int __cdecl Object_InvokeVirtualMethod_00e01680(CallerVtbl* p);
extern int DAT_0126e498;
void* __cdecl Runtime_GetDAT0126e498Address();
extern int DAT_010e9494;
int* __cdecl Runtime_GetDAT010e9494Address();
// Stand-in for the object whose first virtual slot is invoked with the constant 0.
struct FUN_00e016c0_cls
{
    virtual void m0(int a);
};
void __cdecl Object_InvokeVirtualMethod_00e016c0(FUN_00e016c0_cls* pObject);
extern int DAT_0126e4e0;
int __cdecl Runtime_EvaluateValue_00e016d0();
struct EffectSubObject
{
    int unk00;
    void __thiscall Release(int flags);
};
struct EffectHolder
{
    virtual void Virt();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    EffectSubObject m_18;
    EffectSubObject m_1c;
    EffectHolder()
    {}
};
void __cdecl Object_ProcessState_00e016e0(EffectHolder* apHolder, int flags);
extern int DAT_0126e528;
int* __cdecl Object_GetGlobalObjectAddress_00e017e0();
extern int DAT_0126e570;
int* __cdecl Runtime_GetDAT0126e570Address();
extern int DAT_010e9614;
void* __cdecl Runtime_GetDAT010e9614Address();
extern int DAT_0126e5b8;
int __cdecl Object_ComputeValue_00e019e0();
extern int DAT_010e350c;
int* __cdecl Object_GetGlobalObjectAddress_00e01a00();
struct CpuOpaque;
extern CpuOpaque DAT_0126e600;
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00e01a20();
extern int DAT_010e96c8;
void* __cdecl Object_GetGlobalObjectAddress_00e01a40();
extern int g_unk0126e648;
void* __cdecl Object_GetGlobalObjectAddress_00e01b00();
extern int DAT_010e977c;
int* Object_GetGlobalObjectAddress_00e01b20();
extern int DAT_0126e690;
void* __cdecl Object_GetGlobalObjectAddress_00e01c20();
extern int g_unkGlobal;
void* Object_GetGlobalObjectAddress_00e01ce0();
struct FUN_00e01e00_vt
{
    virtual void m(int);
};
void __cdecl Object_InvokeVirtualMethod_00e01e00(FUN_00e01e00_vt* p);
extern int DAT_0126e720;
int* __cdecl Runtime_GetDAT0126e720Address();
// Null-guarded forwarder: the first argument is an object pointer; when it
// is non-null the second argument is forwarded to a member function of that
// object (called with the object as 'this').
class FUN_00e01e20_cls
{
  public:
    void __thiscall Handle(int a1);
};
void __cdecl CallHandleIfNotNull(FUN_00e01e20_cls* pObject, int aiValue);
extern int DAT_0126e768;
int* __cdecl Runtime_GetDAT0126e768Address();
extern int DAT_010e9acc;
struct FUN_00e01e80_obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};
void __cdecl Object_UpdateFields_00e01e80(FUN_00e01e80_obj* pObj, int aiValue);
extern int DAT_0126e7b0;
int* __cdecl Object_GetGlobalObjectAddress_00e01f40();
extern int DAT_010e9b7c;
unsigned int __cdecl Object_ComputeValue_00e01f60();
struct FUN_00e4ae80_Obj
{
    void __thiscall FUN_00e4ae80(int value);
};
void __cdecl Object_ProcessState_00e020c0(FUN_00e4ae80_Obj* pObj, int iValue);
extern int g_unk0126e7f8;
void* __cdecl Runtime_GetUnk0126e7f8Address();
// FUN_00e02120: cdecl, takes a pointer, calls virtual slot 0 with argument 0.
class FUN_00e02120_cls
{
  public:
    virtual int v00(int arg);
};
void Object_InvokeVirtualMethod_00e02120(FUN_00e02120_cls* obj);
extern int g_unk0126e840;
void* __cdecl Runtime_GetUnk0126e840Address();
struct GlobalObject
{
    int unk00;
};
extern GlobalObject g_global;
GlobalObject* __cdecl Runtime_GetGlobalAddress_00e02270();
struct Data_0126e8d0;
extern Data_0126e8d0 DAT_0126e8d0;
Data_0126e8d0* __cdecl Runtime_GetDAT0126e8d0Address();
extern int DAT_010e9e74;
void* __cdecl Runtime_GetDAT010e9e74Address();
extern int DAT_0126e918;
int* __cdecl Runtime_GetDAT0126e918Address();
extern int DAT_010e9f48;
int* __cdecl Runtime_GetDAT010e9f48Address();
struct E02460Object
{
    virtual void Destroy(bool bFree);
};
void Object_Destroy_Thunk_00e02460(E02460Object* pkObject);
extern int DAT_0126e960;
int* __cdecl Runtime_GetDAT0126e960Address();
extern int DAT_010e9fa4;
void* __cdecl Runtime_GetDAT010e9fa4Address();
// FUN_00e024b0 : a one-line function - getter
extern int g_target_00e024b0;
void* Runtime_GetTarget00e024b0Address();
extern int DAT_010ea0a4;
int __cdecl Runtime_EvaluateValue_00e024d0();
extern int DAT_0126e9f0;
int* __cdecl Runtime_GetDAT0126e9f0Address();
struct E02520Object
{
    virtual void Destroy(bool bFree);
};
void Object_Destroy_Thunk_00e02520(E02520Object* pkObject);
extern int DAT_010ea10c;
void* Runtime_GetDAT010ea10cAddress();
extern unsigned char DAT_0126ea80;
void* __cdecl Runtime_GetDAT0126ea80Address();
extern int DAT_010ea154;
int __cdecl Runtime_EvaluateValue_00e02590();
extern int DAT_0126eac8;
void* Object_GetGlobalObjectAddress_00e02620();
extern int DAT_010ea188;
int __cdecl Object_ComputeValue_00e02640();
extern unsigned char DAT_0126eb10;
unsigned char* __cdecl Runtime_GetDAT0126eb10Address();
extern int DAT_010ea1ac;
int* Runtime_GetDAT010ea1acAddress();
class E02700Object
{
  public:
    void Process(void* pvData);
};
void __cdecl Object_ProcessState_00e02700(E02700Object* pkObject, void* pvData);
extern int g_0126eb58;
int* __cdecl Runtime_GetField0126eb58Address();
extern int DAT_0126eba0;
int* __cdecl Runtime_GetDAT0126eba0Address();
extern int DAT_010c9314;
void* __cdecl Object_GetGlobalObjectAddress_00e027a0();
int __cdecl ReadIntAtOffset(int index, int* data);
void __cdecl UpdateStateFlags(void* pData);
void __cdecl ReverseBytesInGroupsOfFour(unsigned char* p);
void __cdecl SwapHeaderBytesAndAdvance(unsigned char* pBuffer);
namespace std {
template <class T> inline void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}
}
void __cdecl ReverseBytesInGroupsOfFour(unsigned char* p);
void __cdecl SwapQuadBytes(unsigned char* pData);
void __cdecl hkpSaveContactPointsEndianUtil_swapEndianType(unsigned char* pBuffer);
inline void E05F60Swap(char& a, char& b)
{
    char t = a;
    a = b;
    b = t;
}
inline void E05F60SwapBytes(void* pv, int iSize)
{
    char* pLo = static_cast<char*>(pv);
    char* pHi = pLo + iSize - 1;
    for (int j = 0; j < iSize / 2; j++)
        E05F60Swap(pLo[j], pHi[-j]);
}
struct E05F60Header
{
    unsigned short m_shorts[3];
    unsigned short unk06;
    unsigned int m_auiHeaderValues[3];
    unsigned int m_value0;
    unsigned int m_value1;
};
void __cdecl SwapHeaderEndianness(E05F60Header* pkHeader);
void __cdecl hkpSaveContactPointsEndianUtil_swapEndianType_00e05fe0(unsigned char* pBuffer);
void __cdecl hkpSaveContactPointsEndianUtil_swapEndianType_00e06010(unsigned char* pucBuffer);
int __cdecl Object_ComputeValue_00e09620();
struct SearchItem
{
    unsigned int unk00, unk04, unk08, unk0C;
    unsigned int unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C;
    unsigned int unk30, unk34, unk38, unk3C;
    double m_key;
    unsigned int unk48, unk4C, unk50;
    int m_type;
};
struct SearchContainer
{
    unsigned int unk00, unk04, unk08, unk0C;
    unsigned int unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C;
    SearchItem** m_items;
    int m_uiItemCount;
};
SearchItem* findChildNode(SearchContainer* c, double key, int aiFieldIndex);
struct FUN_00e10a00_cls
{
    int m_00;

    FUN_00e10a00_cls* return_input_and_0_it_1();
};
// FUN_00e114f0: thiscall, 3 unused stack params, sets a flag byte at +0x100.
class FUN_00e114f0_cls
{
  public:
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
    int m_a0;
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
    unsigned char m_100;
    void __thiscall SetField100(int a1, int a2, int a3);
};
struct FlagObjectPad
{
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
    unsigned char m_flag100;
};
class FUN_00e11500_cls : public FlagObjectPad
{
  public:
    void SetFlag100_00e11500(int a1, int a2);
};
struct FUN_00e11510_obj
{
    void __thiscall UpdateState_00e11510(int a, int b);
};
struct FUN_00e11520_class
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
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    char flag100;
    void SetFlag100_00e11520(int a, int b);
};
class hkMemberE00
{
  public:
    hkMemberE00(FinishingFlag flag) throw();

    int unk00;
    int unk04;
    int unk08;
};
class hkBaseE00
{
  public:
    __forceinline hkBaseE00(FinishingFlag flag) : m_kMemberDescriptor(flag)
    {}
    virtual ~hkBaseE00();

    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    hkSmallArray<int> m_ppData;
    hkMemberE00 m_kMemberDescriptor;
};
class hkMidE00 : public hkBaseE00
{
  public:
    __forceinline hkMidE00(FinishingFlag flag) : hkBaseE00(flag)
    {
        m_iType = -16;
    }
    virtual ~hkMidE00();

    int m_iType;
};
class hkDerivedE00 : public hkMidE00
{
  public:
    __forceinline hkDerivedE00(FinishingFlag flag) : hkMidE00(flag)
    {}
    virtual ~hkDerivedE00();
};
void __cdecl ConstructDerivedObject(void* pvObject, int iFinishing);
char* __cdecl ReadPaddedString(char* base, int* piOffset);
class BE04D90Allocator;
class BE04D90Router
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    BE04D90Allocator* m_pkHeap;
};
BE04D90Router* BE04D90GetRouter() throw();
class BE04D90PointerMap
{
  public:
    BE04D90PointerMap() : m_pPointerArray(0), m_iCapacityFlags(0), m_iPairCount(-1)
    {}
    ~BE04D90PointerMap() throw();

    void Init(BE04D90Allocator* pkAlloc, int iCapacity) throw();
    void ClearAndDeallocate(BE04D90Allocator* pkAlloc) throw();

    void* m_pPointerArray;
    int m_iCapacityFlags;
    int m_iPairCount;
};
class BE04D90Object;
void __cdecl RegisterContextHandlers(BE04D90Object* pkObject, BE04D90PointerMap* pkMap, int iArg) throw();
void __cdecl ProcessObjectArray(BE04D90Object** ppkObjects, int iArg);
struct Payload
{
    float x, y;
    union
    {
        float z;
        unsigned int zbits;
        struct
        {
            unsigned char z0, z1, z2, z3;
        };
    };
    unsigned int flags;
};
struct Input
{
    unsigned char type, selector, unk02, component;
    unsigned int unk04, unk08, unk0c;
    Payload a, b, c;
};
struct Entry
{
    unsigned int key;
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38,
        unk3c, unk40, unk44, unk48, unk4c;
};
struct Context
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000c;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001c;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002c;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003c;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004c;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005c;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006c;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007c;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008c;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009c;
    unsigned int unk00a0;
    unsigned int unk00a4;
    unsigned int unk00a8;
    unsigned int unk00ac;
    unsigned int unk00b0;
    unsigned int unk00b4;
    unsigned int unk00b8;
    unsigned int unk00bc;
    unsigned int unk00c0;
    unsigned int unk00c4;
    unsigned int unk00c8;
    unsigned int unk00cc;
    unsigned int unk00d0;
    unsigned int unk00d4;
    unsigned int unk00d8;
    unsigned int unk00dc;
    unsigned int unk00e0;
    unsigned int unk00e4;
    unsigned int unk00e8;
    unsigned int unk00ec;
    unsigned int unk00f0;
    unsigned int unk00f4;
    unsigned int unk00f8;
    unsigned int unk00fc;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010c;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011c;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012c;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013c;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014c;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015c;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016c;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017c;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018c;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019c;
    unsigned int unk01a0;
    unsigned int unk01a4;
    unsigned int unk01a8;
    unsigned int unk01ac;
    unsigned int unk01b0;
    unsigned int unk01b4;
    unsigned int unk01b8;
    unsigned int unk01bc;
    unsigned int unk01c0;
    unsigned int unk01c4;
    unsigned int unk01c8;
    unsigned int unk01cc;
    unsigned int unk01d0;
    unsigned int unk01d4;
    unsigned int unk01d8;
    unsigned int unk01dc;
    unsigned int unk01e0;
    unsigned int unk01e4;
    unsigned int unk01e8;
    unsigned int unk01ec;
    unsigned int unk01f0;
    unsigned int unk01f4;
    unsigned int unk01f8;
    unsigned int unk01fc;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020c;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021c;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022c;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023c;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024c;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025c;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026c;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027c;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028c;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029c;
    unsigned int unk02a0;
    unsigned int unk02a4;
    unsigned int unk02a8;
    unsigned int unk02ac;
    unsigned int unk02b0;
    unsigned int unk02b4;
    unsigned int unk02b8;
    unsigned int unk02bc;
    unsigned int unk02c0;
    unsigned int unk02c4;
    unsigned int unk02c8;
    unsigned int unk02cc;
    unsigned int unk02d0;
    unsigned int unk02d4;
    unsigned int unk02d8;
    unsigned int unk02dc;
    unsigned int unk02e0;
    unsigned int unk02e4;
    unsigned int unk02e8;
    unsigned int unk02ec;
    unsigned int unk02f0;
    unsigned int unk02f4;
    unsigned int unk02f8;
    unsigned int unk02fc;
    unsigned int unk0300;
    unsigned int unk0304;
    unsigned int unk0308;
    unsigned int unk030c;
    unsigned int unk0310;
    unsigned int unk0314;
    unsigned int unk0318;
    unsigned int unk031c;
    unsigned int unk0320;
    unsigned int unk0324;
    unsigned int unk0328;
    unsigned int unk032c;
    unsigned int unk0330;
    unsigned int unk0334;
    unsigned int unk0338;
    unsigned int unk033c;
    unsigned int unk0340;
    unsigned int unk0344;
    unsigned int unk0348;
    unsigned int unk034c;
    unsigned int unk0350;
    unsigned int unk0354;
    unsigned int unk0358;
    unsigned int unk035c;
    unsigned int unk0360;
    unsigned int unk0364;
    unsigned int unk0368;
    unsigned int unk036c;
    unsigned int unk0370;
    unsigned int unk0374;
    unsigned int unk0378;
    unsigned int unk037c;
    unsigned int unk0380;
    unsigned int unk0384;
    unsigned int unk0388;
    unsigned int unk038c;
    unsigned int unk0390;
    unsigned int unk0394;
    unsigned int unk0398;
    unsigned int unk039c;
    unsigned int unk03a0;
    unsigned int unk03a4;
    unsigned int unk03a8;
    unsigned int unk03ac;
    unsigned int unk03b0;
    unsigned int unk03b4;
    unsigned int unk03b8;
    unsigned int unk03bc;
    unsigned int unk03c0;
    unsigned int unk03c4;
    unsigned int unk03c8;
    unsigned int unk03cc;
    unsigned int unk03d0;
    unsigned int unk03d4;
    unsigned int unk03d8;
    unsigned int unk03dc;
    unsigned int unk03e0;
    unsigned int unk03e4;
    unsigned int unk03e8;
    unsigned int unk03ec;
    unsigned int unk03f0;
    unsigned int unk03f4;
    unsigned int unk03f8;
    unsigned int unk03fc;
    unsigned int unk0400;
    unsigned int unk0404;
    unsigned int unk0408;
    unsigned int unk040c;
    unsigned int unk0410;
    unsigned int unk0414;
    unsigned int unk0418;
    unsigned int unk041c;
    unsigned int unk0420;
    unsigned int unk0424;
    unsigned int unk0428;
    unsigned int unk042c;
    unsigned int unk0430;
    unsigned int unk0434;
    unsigned int unk0438;
    unsigned int unk043c;
    unsigned int unk0440;
    unsigned int unk0444;
    unsigned int unk0448;
    unsigned int unk044c;
    unsigned int unk0450;
    unsigned int unk0454;
    unsigned int unk0458;
    unsigned int unk045c;
    unsigned int unk0460;
    unsigned int unk0464;
    unsigned int unk0468;
    unsigned int unk046c;
    unsigned int unk0470;
    unsigned int unk0474;
    unsigned int unk0478;
    unsigned int unk047c;
    unsigned int unk0480;
    unsigned int unk0484;
    unsigned int unk0488;
    unsigned int unk048c;
    unsigned int unk0490;
    unsigned int unk0494;
    unsigned int unk0498;
    unsigned int unk049c;
    unsigned int unk04a0;
    unsigned int unk04a4;
    unsigned int unk04a8;
    unsigned int unk04ac;
    unsigned int unk04b0;
    unsigned int unk04b4;
    unsigned int unk04b8;
    unsigned int unk04bc;
    unsigned int unk04c0;
    unsigned int unk04c4;
    unsigned int unk04c8;
    unsigned int unk04cc;
    unsigned int unk04d0;
    unsigned int unk04d4;
    unsigned int unk04d8;
    unsigned int unk04dc;
    unsigned int unk04e0;
    unsigned int unk04e4;
    unsigned int unk04e8;
    unsigned int unk04ec;
    unsigned int unk04f0;
    unsigned int unk04f4;
    unsigned int unk04f8;
    unsigned int unk04fc;
    unsigned int unk0500;
    unsigned int unk0504;
    unsigned int unk0508;
    unsigned int unk050c;
    unsigned int unk0510;
    unsigned int unk0514;
    unsigned int unk0518;
    unsigned int unk051c;
    unsigned int unk0520;
    unsigned int unk0524;
    unsigned int unk0528;
    unsigned int unk052c;
    unsigned int unk0530;
    unsigned int unk0534;
    unsigned int unk0538;
    unsigned int unk053c;
    unsigned int unk0540;
    unsigned int unk0544;
    unsigned int unk0548;
    unsigned int unk054c;
    unsigned int unk0550;
    unsigned int unk0554;
    unsigned int unk0558;
    unsigned int unk055c;
    unsigned int unk0560;
    unsigned int unk0564;
    unsigned int unk0568;
    unsigned int unk056c;
    unsigned int unk0570;
    unsigned int unk0574;
    unsigned int unk0578;
    unsigned int unk057c;
    unsigned int unk0580;
    unsigned int unk0584;
    unsigned int unk0588;
    unsigned int unk058c;
    unsigned int unk0590;
    unsigned int unk0594;
    unsigned int unk0598;
    unsigned int unk059c;
    unsigned int unk05a0;
    unsigned int unk05a4;
    unsigned int unk05a8;
    unsigned int unk05ac;
    unsigned int unk05b0;
    unsigned int unk05b4;
    unsigned int unk05b8;
    unsigned int unk05bc;
    unsigned int unk05c0;
    unsigned int unk05c4;
    unsigned int unk05c8;
    unsigned int unk05cc;
    unsigned int unk05d0;
    unsigned int unk05d4;
    unsigned int unk05d8;
    unsigned int unk05dc;
    unsigned int unk05e0;
    unsigned int unk05e4;
    unsigned int unk05e8;
    unsigned int unk05ec;
    unsigned int unk05f0;
    unsigned int unk05f4;
    unsigned int unk05f8;
    unsigned int unk05fc;
    unsigned int unk0600;
    unsigned int unk0604;
    unsigned int unk0608;
    unsigned int unk060c;
    unsigned int unk0610;
    unsigned int unk0614;
    unsigned int unk0618;
    unsigned int unk061c;
    unsigned int unk0620;
    unsigned int unk0624;
    unsigned int unk0628;
    unsigned int unk062c;
    unsigned int unk0630;
    unsigned int unk0634;
    unsigned int unk0638;
    unsigned int unk063c;
    unsigned int unk0640;
    unsigned int unk0644;
    unsigned int unk0648;
    unsigned int unk064c;
    unsigned int unk0650;
    unsigned int unk0654;
    unsigned int unk0658;
    unsigned int unk065c;
    unsigned int unk0660;
    unsigned int unk0664;
    unsigned int unk0668;
    unsigned int unk066c;
    unsigned int unk0670;
    unsigned int unk0674;
    unsigned int unk0678;
    unsigned int unk067c;
    unsigned int unk0680;
    unsigned int unk0684;
    unsigned int unk0688;
    unsigned int unk068c;
    unsigned int unk0690;
    unsigned int unk0694;
    unsigned int unk0698;
    unsigned int unk069c;
    unsigned int unk06a0;
    unsigned int unk06a4;
    unsigned int unk06a8;
    unsigned int unk06ac;
    unsigned int unk06b0;
    unsigned int unk06b4;
    unsigned int unk06b8;
    unsigned int unk06bc;
    unsigned int unk06c0;
    unsigned int unk06c4;
    unsigned int unk06c8;
    unsigned int unk06cc;
    unsigned int unk06d0;
    unsigned int unk06d4;
    unsigned int unk06d8;
    unsigned int unk06dc;
    unsigned int unk06e0;
    unsigned int unk06e4;
    unsigned int unk06e8;
    unsigned int unk06ec;
    unsigned int unk06f0;
    unsigned int unk06f4;
    unsigned int unk06f8;
    unsigned int unk06fc;
    unsigned int unk0700;
    unsigned int unk0704;
    unsigned int unk0708;
    unsigned int unk070c;
    unsigned int unk0710;
    unsigned int unk0714;
    unsigned int unk0718;
    unsigned int unk071c;
    unsigned int unk0720;
    unsigned int unk0724;
    unsigned int unk0728;
    unsigned int unk072c;
    unsigned int unk0730;
    unsigned int unk0734;
    unsigned int unk0738;
    unsigned int unk073c;
    unsigned int unk0740;
    unsigned int unk0744;
    unsigned int unk0748;
    unsigned int unk074c;
    unsigned int unk0750;
    unsigned int unk0754;
    unsigned int unk0758;
    unsigned int unk075c;
    unsigned int unk0760;
    unsigned int unk0764;
    unsigned int unk0768;
    unsigned int unk076c;
    unsigned int unk0770;
    unsigned int unk0774;
    unsigned int unk0778;
    unsigned int unk077c;
    unsigned int unk0780;
    unsigned int unk0784;
    unsigned int unk0788;
    unsigned int unk078c;
    unsigned int unk0790;
    unsigned int unk0794;
    unsigned int unk0798;
    unsigned int unk079c;
    unsigned int unk07a0;
    unsigned int unk07a4;
    unsigned int unk07a8;
    unsigned int unk07ac;
    unsigned int unk07b0;
    unsigned int unk07b4;
    unsigned int unk07b8;
    unsigned int unk07bc;
    unsigned int unk07c0;
    unsigned int unk07c4;
    unsigned int unk07c8;
    unsigned int unk07cc;
    unsigned int unk07d0;
    unsigned int unk07d4;
    unsigned int unk07d8;
    unsigned int unk07dc;
    unsigned int unk07e0;
    unsigned int unk07e4;
    unsigned int unk07e8;
    unsigned int unk07ec;
    unsigned int unk07f0;
    unsigned int unk07f4;
    unsigned int unk07f8;
    unsigned int unk07fc;
    unsigned int unk0800;
    unsigned int unk0804;
    unsigned int unk0808;
    unsigned int unk080c;
    unsigned int unk0810;
    unsigned int unk0814;
    unsigned int unk0818;
    unsigned int unk081c;
    unsigned int unk0820;
    unsigned int unk0824;
    unsigned int unk0828;
    unsigned int unk082c;
    unsigned int unk0830;
    unsigned int unk0834;
    unsigned int unk0838;
    unsigned int unk083c;
    unsigned int unk0840;
    unsigned int unk0844;
    unsigned int unk0848;
    unsigned int unk084c;
    unsigned int unk0850;
    unsigned int unk0854;
    unsigned int unk0858;
    unsigned int unk085c;
    unsigned int unk0860;
    unsigned int unk0864;
    unsigned int unk0868;
    unsigned int unk086c;
    unsigned int unk0870;
    unsigned int unk0874;
    unsigned int unk0878;
    unsigned int unk087c;
    unsigned int unk0880;
    unsigned int unk0884;
    unsigned int unk0888;
    unsigned int unk088c;
    unsigned int unk0890;
    unsigned int unk0894;
    unsigned int unk0898;
    unsigned int unk089c;
    unsigned int unk08a0;
    unsigned int unk08a4;
    unsigned int unk08a8;
    unsigned int unk08ac;
    unsigned int unk08b0;
    unsigned int unk08b4;
    unsigned int unk08b8;
    unsigned int unk08bc;
    unsigned int unk08c0;
    unsigned int unk08c4;
    unsigned int unk08c8;
    unsigned int unk08cc;
    unsigned int unk08d0;
    unsigned int unk08d4;
    unsigned int unk08d8;
    unsigned int unk08dc;
    unsigned int unk08e0;
    unsigned int unk08e4;
    unsigned int unk08e8;
    unsigned int unk08ec;
    unsigned int unk08f0;
    unsigned int unk08f4;
    unsigned int unk08f8;
    unsigned int unk08fc;
    unsigned int unk0900;
    unsigned int unk0904;
    unsigned int unk0908;
    unsigned int unk090c;
    unsigned int unk0910;
    unsigned int unk0914;
    unsigned int unk0918;
    unsigned int unk091c;
    unsigned int unk0920;
    unsigned int unk0924;
    unsigned int unk0928;
    unsigned int unk092c;
    unsigned int unk0930;
    unsigned int unk0934;
    unsigned int unk0938;
    unsigned int unk093c;
    unsigned int unk0940;
    unsigned int unk0944;
    unsigned int unk0948;
    unsigned int unk094c;
    unsigned int unk0950;
    unsigned int unk0954;
    unsigned int unk0958;
    unsigned int unk095c;
    unsigned int unk0960;
    unsigned int unk0964;
    unsigned int unk0968;
    unsigned int unk096c;
    unsigned int unk0970;
    unsigned int unk0974;
    unsigned int unk0978;
    unsigned int unk097c;
    unsigned int unk0980;
    unsigned int unk0984;
    unsigned int unk0988;
    unsigned int unk098c;
    unsigned int unk0990;
    unsigned int unk0994;
    unsigned int unk0998;
    unsigned int unk099c;
    unsigned int unk09a0;
    unsigned int unk09a4;
    unsigned int unk09a8;
    unsigned int unk09ac;
    unsigned int unk09b0;
    unsigned int unk09b4;
    unsigned int unk09b8;
    unsigned int unk09bc;
    unsigned int unk09c0;
    unsigned int unk09c4;
    unsigned int unk09c8;
    unsigned int unk09cc;
    unsigned int unk09d0;
    unsigned int unk09d4;
    unsigned int unk09d8;
    unsigned int unk09dc;
    unsigned int unk09e0;
    unsigned int unk09e4;
    unsigned int unk09e8;
    unsigned int unk09ec;
    unsigned int unk09f0;
    unsigned int unk09f4;
    unsigned int unk09f8;
    unsigned int unk09fc;
    unsigned int unk0a00;
    unsigned int unk0a04;
    unsigned int unk0a08;
    unsigned int unk0a0c;
    unsigned int unk0a10;
    unsigned int unk0a14;
    unsigned int unk0a18;
    unsigned int unk0a1c;
    unsigned int unk0a20;
    unsigned int unk0a24;
    unsigned int unk0a28;
    unsigned int unk0a2c;
    unsigned int unk0a30;
    unsigned int unk0a34;
    unsigned int unk0a38;
    unsigned int unk0a3c;
    unsigned int unk0a40;
    unsigned int unk0a44;
    unsigned int unk0a48;
    unsigned int unk0a4c;
    unsigned int unk0a50;
    unsigned int unk0a54;
    unsigned int unk0a58;
    unsigned int unk0a5c;
    unsigned int unk0a60;
    unsigned int unk0a64;
    unsigned int unk0a68;
    unsigned int unk0a6c;
    unsigned int unk0a70;
    unsigned int unk0a74;
    unsigned int unk0a78;
    unsigned int unk0a7c;
    unsigned int unk0a80;
    unsigned int unk0a84;
    unsigned int unk0a88;
    unsigned int unk0a8c;
    unsigned int unk0a90;
    unsigned int unk0a94;
    unsigned int unk0a98;
    unsigned int unk0a9c;
    unsigned int unk0aa0;
    unsigned int unk0aa4;
    unsigned int unk0aa8;
    unsigned int unk0aac;
    unsigned int unk0ab0;
    unsigned int unk0ab4;
    unsigned int unk0ab8;
    unsigned int unk0abc;
    unsigned int unk0ac0;
    unsigned int unk0ac4;
    unsigned int unk0ac8;
    unsigned int unk0acc;
    unsigned int unk0ad0;
    unsigned int unk0ad4;
    unsigned int unk0ad8;
    unsigned int unk0adc;
    unsigned int unk0ae0;
    unsigned int unk0ae4;
    unsigned int unk0ae8;
    unsigned int unk0aec;
    unsigned int unk0af0;
    unsigned int unk0af4;
    unsigned int unk0af8;
    unsigned int unk0afc;
    unsigned int unk0b00;
    unsigned int unk0b04;
    unsigned int unk0b08;
    unsigned int unk0b0c;
    unsigned int unk0b10;
    unsigned int unk0b14;
    unsigned int unk0b18;
    unsigned int unk0b1c;
    unsigned int unk0b20;
    unsigned int unk0b24;
    unsigned int unk0b28;
    unsigned int unk0b2c;
    unsigned int unk0b30;
    unsigned int unk0b34;
    unsigned int unk0b38;
    unsigned int unk0b3c;
    unsigned int unk0b40;
    unsigned int unk0b44;
    unsigned int unk0b48;
    unsigned int unk0b4c;
    unsigned int unk0b50;
    unsigned int unk0b54;
    unsigned int unk0b58;
    unsigned int unk0b5c;
    unsigned int unk0b60;
    unsigned int unk0b64;
    unsigned int unk0b68;
    unsigned int unk0b6c;
    unsigned int unk0b70;
    unsigned int unk0b74;
    unsigned int unk0b78;
    unsigned int unk0b7c;
    unsigned int unk0b80;
    unsigned int unk0b84;
    unsigned int unk0b88;
    unsigned int unk0b8c;
    unsigned int unk0b90;
    unsigned int unk0b94;
    unsigned int unk0b98;
    unsigned int unk0b9c;
    unsigned int unk0ba0;
    unsigned int unk0ba4;
    unsigned int unk0ba8;
    unsigned int unk0bac;
    unsigned int unk0bb0;
    unsigned int unk0bb4;
    unsigned int unk0bb8;
    unsigned int unk0bbc;
    unsigned int unk0bc0;
    unsigned int unk0bc4;
    unsigned int unk0bc8;
    unsigned int unk0bcc;
    unsigned int unk0bd0;
    unsigned int unk0bd4;
    unsigned int unk0bd8;
    unsigned int unk0bdc;
    unsigned int unk0be0;
    unsigned int unk0be4;
    unsigned int unk0be8;
    unsigned int unk0bec;
    unsigned int unk0bf0;
    unsigned int unk0bf4;
    unsigned int unk0bf8;
    unsigned int unk0bfc;
    unsigned int unk0c00;
    unsigned int unk0c04;
    unsigned int unk0c08;
    unsigned int unk0c0c;
    unsigned int unk0c10;
    unsigned int unk0c14;
    unsigned int unk0c18;
    unsigned int unk0c1c;
    unsigned int unk0c20;
    unsigned int unk0c24;
    unsigned int unk0c28;
    unsigned int unk0c2c;
    unsigned int unk0c30;
    unsigned int unk0c34;
    unsigned int unk0c38;
    unsigned int unk0c3c;
    unsigned int unk0c40;
    unsigned int unk0c44;
    unsigned int unk0c48;
    unsigned int unk0c4c;
    unsigned int unk0c50;
    unsigned int unk0c54;
    unsigned int unk0c58;
    unsigned int unk0c5c;
    unsigned int unk0c60;
    unsigned int unk0c64;
    unsigned int unk0c68;
    unsigned int unk0c6c;
    unsigned int unk0c70;
    unsigned int unk0c74;
    unsigned int unk0c78;
    unsigned int unk0c7c;
    unsigned int unk0c80;
    unsigned int unk0c84;
    unsigned int unk0c88;
    unsigned int unk0c8c;
    unsigned int unk0c90;
    unsigned int unk0c94;
    unsigned int unk0c98;
    unsigned int unk0c9c;
    unsigned int unk0ca0;
    unsigned int unk0ca4;
    unsigned int unk0ca8;
    unsigned int unk0cac;
    unsigned int unk0cb0;
    unsigned int unk0cb4;
    unsigned int unk0cb8;
    unsigned int unk0cbc;
    unsigned int unk0cc0;
    unsigned int unk0cc4;
    unsigned int unk0cc8;
    unsigned int unk0ccc;
    unsigned int unk0cd0;
    unsigned int unk0cd4;
    unsigned int unk0cd8;
    unsigned int unk0cdc;
    unsigned int unk0ce0;
    unsigned int unk0ce4;
    unsigned int unk0ce8;
    unsigned int unk0cec;
    unsigned int unk0cf0;
    unsigned int unk0cf4;
    unsigned int unk0cf8;
    unsigned int unk0cfc;
    unsigned int unk0d00;
    unsigned int unk0d04;
    unsigned int unk0d08;
    unsigned int unk0d0c;
    unsigned int unk0d10;
    unsigned int unk0d14;
    unsigned int unk0d18;
    unsigned int unk0d1c;
    unsigned int unk0d20;
    unsigned int unk0d24;
    unsigned int unk0d28;
    unsigned int unk0d2c;
    unsigned int unk0d30;
    unsigned int unk0d34;
    unsigned int unk0d38;
    unsigned int unk0d3c;
    unsigned int unk0d40;
    unsigned int unk0d44;
    unsigned int unk0d48;
    unsigned int unk0d4c;
    unsigned int unk0d50;
    unsigned int unk0d54;
    unsigned int unk0d58;
    unsigned int unk0d5c;
    unsigned int unk0d60;
    unsigned int unk0d64;
    unsigned int unk0d68;
    unsigned int unk0d6c;
    unsigned int unk0d70;
    unsigned int unk0d74;
    unsigned int unk0d78;
    unsigned int unk0d7c;
    unsigned int unk0d80;
    unsigned int unk0d84;
    unsigned int unk0d88;
    unsigned int unk0d8c;
    unsigned int unk0d90;
    unsigned int unk0d94;
    unsigned int unk0d98;
    unsigned int unk0d9c;
    unsigned int unk0da0;
    unsigned int unk0da4;
    unsigned int unk0da8;
    unsigned int unk0dac;
    unsigned int unk0db0;
    unsigned int unk0db4;
    unsigned int unk0db8;
    unsigned int unk0dbc;
    unsigned int unk0dc0;
    unsigned int unk0dc4;
    unsigned int unk0dc8;
    unsigned int unk0dcc;
    unsigned int unk0dd0;
    unsigned int unk0dd4;
    unsigned int unk0dd8;
    unsigned int unk0ddc;
    unsigned int unk0de0;
    unsigned int unk0de4;
    unsigned int unk0de8;
    unsigned int unk0dec;
    unsigned int unk0df0;
    unsigned int unk0df4;
    unsigned int unk0df8;
    unsigned int unk0dfc;
    unsigned int unk0e00;
    unsigned int unk0e04;
    unsigned int unk0e08;
    unsigned int unk0e0c;
    unsigned int unk0e10;
    unsigned int unk0e14;
    unsigned int unk0e18;
    unsigned int unk0e1c;
    unsigned int unk0e20;
    unsigned int unk0e24;
    unsigned int unk0e28;
    unsigned int unk0e2c;
    unsigned int unk0e30;
    unsigned int unk0e34;
    unsigned int unk0e38;
    unsigned int unk0e3c;
    unsigned int unk0e40;
    unsigned int unk0e44;
    unsigned int unk0e48;
    unsigned int unk0e4c;
    unsigned int unk0e50;
    unsigned int unk0e54;
    unsigned int unk0e58;
    unsigned int unk0e5c;
    unsigned int unk0e60;
    unsigned int unk0e64;
    unsigned int unk0e68;
    unsigned int unk0e6c;
    unsigned int unk0e70;
    unsigned int unk0e74;
    unsigned int unk0e78;
    unsigned int unk0e7c;
    unsigned int unk0e80;
    unsigned int unk0e84;
    unsigned int unk0e88;
    unsigned int unk0e8c;
    unsigned int unk0e90;
    unsigned int unk0e94;
    unsigned int unk0e98;
    unsigned int unk0e9c;
    unsigned int unk0ea0;
    unsigned int unk0ea4;
    unsigned int unk0ea8;
    unsigned int unk0eac;
    unsigned int unk0eb0;
    unsigned int unk0eb4;
    unsigned int unk0eb8;
    unsigned int unk0ebc;
    unsigned int unk0ec0;
    unsigned int unk0ec4;
    unsigned int unk0ec8;
    unsigned int unk0ecc;
    unsigned int unk0ed0;
    unsigned int unk0ed4;
    unsigned int unk0ed8;
    unsigned int unk0edc;
    unsigned int unk0ee0;
    unsigned int unk0ee4;
    unsigned int unk0ee8;
    unsigned int unk0eec;
    unsigned int unk0ef0;
    unsigned int unk0ef4;
    unsigned int unk0ef8;
    unsigned int unk0efc;
    unsigned int unk0f00;
    unsigned int unk0f04;
    unsigned int unk0f08;
    unsigned int unk0f0c;
    unsigned int unk0f10;
    unsigned int unk0f14;
    unsigned int unk0f18;
    unsigned int unk0f1c;
    unsigned int unk0f20;
    unsigned int unk0f24;
    unsigned int unk0f28;
    unsigned int unk0f2c;
    unsigned int unk0f30;
    unsigned int unk0f34;
    unsigned int unk0f38;
    unsigned int unk0f3c;
    unsigned int unk0f40;
    unsigned int unk0f44;
    unsigned int unk0f48;
    unsigned int unk0f4c;
    unsigned int unk0f50;
    unsigned int unk0f54;
    unsigned int unk0f58;
    unsigned int unk0f5c;
    unsigned int unk0f60;
    unsigned int unk0f64;
    unsigned int unk0f68;
    unsigned int unk0f6c;
    unsigned int unk0f70;
    unsigned int unk0f74;
    unsigned int unk0f78;
    unsigned int unk0f7c;
    unsigned int unk0f80;
    unsigned int unk0f84;
    unsigned int unk0f88;
    unsigned int unk0f8c;
    unsigned int unk0f90;
    unsigned int unk0f94;
    unsigned int unk0f98;
    unsigned int unk0f9c;
    unsigned int unk0fa0;
    unsigned int unk0fa4;
    unsigned int unk0fa8;
    unsigned int unk0fac;
    unsigned int unk0fb0;
    unsigned int unk0fb4;
    unsigned int unk0fb8;
    unsigned int unk0fbc;
    unsigned int unk0fc0;
    unsigned int unk0fc4;
    unsigned int unk0fc8;
    unsigned int unk0fcc;
    unsigned int unk0fd0;
    unsigned int unk0fd4;
    unsigned int unk0fd8;
    unsigned int unk0fdc;
    unsigned int unk0fe0;
    unsigned int unk0fe4;
    unsigned int unk0fe8;
    unsigned int unk0fec;
    unsigned int unk0ff0;
    unsigned int unk0ff4;
    unsigned int unk0ff8;
    unsigned int unk0ffc;
    unsigned int unk1000;
    unsigned int unk1004;
    unsigned int unk1008;
    unsigned int unk100c;
    unsigned int unk1010;
    unsigned int unk1014;
    unsigned int unk1018;
    unsigned int unk101c;
    unsigned int unk1020;
    unsigned int unk1024;
    unsigned int unk1028;
    unsigned int unk102c;
    unsigned int unk1030;
    unsigned int unk1034;
    unsigned int unk1038;
    unsigned int unk103c;
    unsigned int unk1040;
    unsigned int unk1044;
    unsigned int unk1048;
    unsigned int unk104c;
    unsigned int unk1050;
    unsigned int unk1054;
    unsigned int unk1058;
    unsigned int unk105c;
    unsigned int unk1060;
    unsigned int unk1064;
    unsigned int unk1068;
    unsigned int unk106c;
    unsigned int unk1070;
    unsigned int unk1074;
    unsigned int unk1078;
    unsigned int unk107c;
    unsigned int unk1080;
    unsigned int unk1084;
    unsigned int unk1088;
    unsigned int unk108c;
    unsigned int unk1090;
    unsigned int unk1094;
    unsigned int unk1098;
    unsigned int unk109c;
    unsigned int unk10a0;
    unsigned int unk10a4;
    unsigned int unk10a8;
    unsigned int unk10ac;
    unsigned int unk10b0;
    unsigned int unk10b4;
    unsigned int unk10b8;
    unsigned int unk10bc;
    unsigned int unk10c0;
    unsigned int unk10c4;
    unsigned int unk10c8;
    unsigned int unk10cc;
    unsigned int unk10d0;
    unsigned int unk10d4;
    unsigned int unk10d8;
    unsigned int unk10dc;
    unsigned int unk10e0;
    unsigned int unk10e4;
    unsigned int unk10e8;
    unsigned int unk10ec;
    unsigned int unk10f0;
    unsigned int unk10f4;
    unsigned int unk10f8;
    unsigned int unk10fc;
    unsigned int unk1100;
    unsigned int unk1104;
    unsigned int unk1108;
    unsigned int unk110c;
    unsigned int unk1110;
    unsigned int unk1114;
    unsigned int unk1118;
    unsigned int unk111c;
    unsigned int unk1120;
    unsigned int unk1124;
    unsigned int unk1128;
    unsigned int unk112c;
    unsigned int unk1130;
    unsigned int unk1134;
    unsigned int unk1138;
    unsigned int unk113c;
    unsigned int unk1140;
    unsigned int unk1144;
    unsigned int unk1148;
    unsigned int unk114c;
    unsigned int unk1150;
    unsigned int unk1154;
    unsigned int unk1158;
    unsigned int unk115c;
    unsigned int unk1160;
    unsigned int unk1164;
    unsigned int unk1168;
    unsigned int unk116c;
    unsigned int unk1170;
    unsigned int unk1174;
    unsigned int unk1178;
    unsigned int unk117c;
    unsigned int unk1180;
    unsigned int unk1184;
    unsigned int unk1188;
    unsigned int unk118c;
    unsigned int unk1190;
    unsigned int unk1194;
    unsigned int unk1198;
    unsigned int unk119c;
    unsigned int unk11a0;
    unsigned int unk11a4;
    unsigned int unk11a8;
    unsigned int unk11ac;
    unsigned int unk11b0;
    unsigned int unk11b4;
    unsigned int unk11b8;
    unsigned int unk11bc;
    unsigned int unk11c0;
    unsigned int unk11c4;
    unsigned int unk11c8;
    unsigned int unk11cc;
    unsigned int unk11d0;
    unsigned int unk11d4;
    unsigned int unk11d8;
    unsigned int unk11dc;
    unsigned int unk11e0;
    unsigned int unk11e4;
    unsigned int unk11e8;
    unsigned int unk11ec;
    unsigned int unk11f0;
    unsigned int unk11f4;
    unsigned int unk11f8;
    unsigned int unk11fc;
    unsigned int unk1200;
    unsigned int unk1204;
    unsigned int unk1208;
    unsigned int unk120c;
    unsigned int unk1210;
    unsigned int unk1214;
    unsigned int unk1218;
    unsigned int unk121c;
    unsigned int unk1220;
    unsigned int unk1224;
    unsigned int unk1228;
    unsigned int unk122c;
    unsigned int unk1230;
    unsigned int unk1234;
    unsigned int unk1238;
    unsigned int unk123c;
    unsigned int unk1240;
    unsigned int unk1244;
    unsigned int unk1248;
    unsigned int unk124c;
    unsigned int unk1250;
    unsigned int unk1254;
    unsigned int unk1258;
    unsigned int unk125c;
    unsigned int unk1260;
    unsigned int unk1264;
    unsigned int unk1268;
    unsigned int unk126c;
    unsigned int unk1270;
    unsigned int unk1274;
    unsigned int unk1278;
    unsigned int unk127c;
    unsigned int unk1280;
    unsigned int unk1284;
    unsigned int unk1288;
    unsigned int unk128c;
    unsigned int unk1290;
    unsigned int unk1294;
    unsigned int unk1298;
    unsigned int unk129c;
    unsigned int unk12a0;
    unsigned int unk12a4;
    unsigned int unk12a8;
    unsigned int unk12ac;
    unsigned int unk12b0;
    unsigned int unk12b4;
    unsigned int unk12b8;
    unsigned int unk12bc;
    unsigned int unk12c0;
    unsigned int unk12c4;
    unsigned int unk12c8;
    unsigned int unk12cc;
    unsigned int unk12d0;
    unsigned int unk12d4;
    unsigned int unk12d8;
    unsigned int unk12dc;
    unsigned int unk12e0;
    unsigned int unk12e4;
    unsigned int unk12e8;
    unsigned int unk12ec;
    unsigned int unk12f0;
    unsigned int unk12f4;
    unsigned int unk12f8;
    unsigned int unk12fc;
    unsigned int unk1300;
    unsigned int unk1304;
    unsigned int unk1308;
    unsigned int unk130c;
    unsigned int unk1310;
    unsigned int unk1314;
    unsigned int unk1318;
    unsigned int unk131c;
    unsigned int unk1320;
    unsigned int unk1324;
    unsigned int unk1328;
    unsigned int unk132c;
    unsigned int unk1330;
    unsigned int unk1334;
    unsigned int unk1338;
    unsigned int unk133c;
    unsigned int unk1340;
    unsigned int unk1344;
    unsigned int unk1348;
    unsigned int unk134c;
    unsigned int unk1350;
    unsigned int unk1354;
    unsigned int unk1358;
    unsigned int unk135c;
    unsigned int unk1360;
    unsigned int unk1364;
    unsigned int unk1368;
    unsigned int unk136c;
    unsigned int unk1370;
    unsigned int unk1374;
    unsigned int unk1378;
    unsigned int unk137c;
    unsigned int unk1380;
    unsigned int unk1384;
    unsigned int unk1388;
    unsigned int unk138c;
    unsigned int unk1390;
    unsigned int unk1394;
    unsigned int unk1398;
    unsigned int unk139c;
    unsigned int unk13a0;
    unsigned int unk13a4;
    unsigned int unk13a8;
    unsigned int unk13ac;
    unsigned int unk13b0;
    unsigned int unk13b4;
    unsigned int unk13b8;
    unsigned int unk13bc;
    unsigned int unk13c0;
    unsigned int unk13c4;
    unsigned int unk13c8;
    unsigned int unk13cc;
    unsigned int unk13d0;
    unsigned int unk13d4;
    unsigned int unk13d8;
    unsigned int unk13dc;
    unsigned int unk13e0;
    unsigned int unk13e4;
    unsigned int unk13e8;
    unsigned int unk13ec;
    unsigned int unk13f0;
    unsigned int unk13f4;
    unsigned int unk13f8;
    unsigned int unk13fc;
    unsigned int unk1400;
    unsigned int unk1404;
    unsigned int unk1408;
    unsigned int unk140c;
    unsigned int unk1410;
    unsigned int unk1414;
    unsigned int unk1418;
    unsigned int unk141c;
    unsigned int unk1420;
    unsigned int unk1424;
    unsigned int unk1428;
    unsigned int unk142c;
    unsigned int unk1430;
    unsigned int unk1434;
    unsigned int unk1438;
    unsigned int unk143c;
    unsigned int unk1440;
    unsigned int unk1444;
    unsigned int unk1448;
    unsigned int unk144c;
    unsigned int unk1450;
    unsigned int unk1454;
    unsigned int unk1458;
    unsigned int unk145c;
    unsigned int unk1460;
    unsigned int unk1464;
    unsigned int unk1468;
    unsigned int unk146c;
    unsigned int unk1470;
    unsigned int unk1474;
    unsigned int unk1478;
    unsigned int unk147c;
    unsigned int unk1480;
    unsigned int unk1484;
    unsigned int unk1488;
    unsigned int unk148c;
    unsigned int unk1490;
    unsigned int unk1494;
    unsigned int unk1498;
    unsigned int unk149c;
    unsigned int unk14a0;
    unsigned int unk14a4;
    unsigned int unk14a8;
    unsigned int unk14ac;
    unsigned int unk14b0;
    unsigned int unk14b4;
    unsigned int unk14b8;
    unsigned int unk14bc;
    unsigned int unk14c0;
    unsigned int unk14c4;
    unsigned int unk14c8;
    unsigned int unk14cc;
    unsigned int unk14d0;
    unsigned int unk14d4;
    unsigned int unk14d8;
    unsigned int unk14dc;
    unsigned int unk14e0;
    unsigned int unk14e4;
    unsigned int unk14e8;
    unsigned int unk14ec;
    unsigned int unk14f0;
    unsigned int unk14f4;
    unsigned int unk14f8;
    unsigned int unk14fc;
    unsigned int unk1500;
    unsigned int unk1504;
    unsigned int unk1508;
    unsigned int unk150c;
    unsigned int unk1510;
    unsigned int unk1514;
    unsigned int unk1518;
    unsigned int unk151c;
    unsigned int unk1520;
    unsigned int unk1524;
    unsigned int unk1528;
    unsigned int unk152c;
    unsigned int unk1530;
    unsigned int unk1534;
    unsigned int unk1538;
    unsigned int unk153c;
    unsigned int unk1540;
    unsigned int unk1544;
    unsigned int unk1548;
    unsigned int unk154c;
    unsigned int unk1550;
    unsigned int unk1554;
    unsigned int unk1558;
    unsigned int unk155c;
    unsigned int unk1560;
    unsigned int unk1564;
    unsigned int unk1568;
    unsigned int unk156c;
    unsigned int unk1570;
    unsigned int unk1574;
    unsigned int unk1578;
    unsigned int unk157c;
    unsigned int unk1580;
    unsigned int unk1584;
    unsigned int unk1588;
    unsigned int unk158c;
    unsigned int unk1590;
    unsigned int unk1594;
    unsigned int unk1598;
    unsigned int unk159c;
    unsigned int unk15a0;
    unsigned int unk15a4;
    unsigned int unk15a8;
    unsigned int unk15ac;
    unsigned int unk15b0;
    unsigned int unk15b4;
    unsigned int unk15b8;
    unsigned int unk15bc;
    unsigned int unk15c0;
    unsigned int unk15c4;
    unsigned int unk15c8;
    unsigned int unk15cc;
    unsigned int unk15d0;
    unsigned int unk15d4;
    unsigned int unk15d8;
    unsigned int unk15dc;
    unsigned int unk15e0;
    unsigned int unk15e4;
    unsigned int unk15e8;
    unsigned int unk15ec;
    unsigned int unk15f0;
    unsigned int unk15f4;
    unsigned int unk15f8;
    unsigned int unk15fc;
    unsigned int unk1600;
    unsigned int unk1604;
    unsigned int unk1608;
    unsigned int unk160c;
    unsigned int unk1610;
    unsigned int unk1614;
    unsigned int unk1618;
    unsigned int unk161c;
    unsigned int unk1620;
    unsigned int unk1624;
    unsigned int unk1628;
    unsigned int unk162c;
    unsigned int unk1630;
    unsigned int unk1634;
    unsigned int unk1638;
    unsigned int unk163c;
    unsigned int unk1640;
    unsigned int unk1644;
    unsigned int unk1648;
    unsigned int unk164c;
    unsigned int unk1650;
    unsigned int unk1654;
    unsigned int unk1658;
    unsigned int unk165c;
    unsigned int unk1660;
    unsigned int unk1664;
    unsigned int unk1668;
    unsigned int unk166c;
    unsigned int unk1670;
    unsigned int unk1674;
    unsigned int unk1678;
    unsigned int unk167c;
    unsigned int unk1680;
    unsigned int unk1684;
    unsigned int unk1688;
    unsigned int unk168c;
    unsigned int unk1690;
    unsigned int unk1694;
    unsigned int unk1698;
    unsigned int unk169c;
    unsigned int unk16a0;
    unsigned int unk16a4;
    unsigned int unk16a8;
    unsigned int unk16ac;
    unsigned int unk16b0;
    unsigned int unk16b4;
    unsigned int unk16b8;
    unsigned int unk16bc;
    unsigned int unk16c0;
    unsigned int unk16c4;
    unsigned int unk16c8;
    unsigned int unk16cc;
    unsigned int unk16d0;
    unsigned int unk16d4;
    unsigned int unk16d8;
    Entry entries[256];
};
void SwapHeaderBytesAndAdvance(Input*);
void SwapQuadBytes(Input*);
void hkpSaveContactPointsEndianUtil_swapEndianType(Input*);
int hkpSaveContactPointsUtil_getSerializedAgentType(unsigned int);
void SwapHkHeaderE05E(Payload*);
void SwapHeaderEndianness(Payload*);
void hkpSaveContactPointsEndianUtil_swapEndianType_00e05fe0(Payload*);
void hkpSaveContactPointsEndianUtil_swapEndianType_00e06010(void*);
void ProcessListBlocks(Context**, void*);
void ProcessInput(Context** context, Input* input, void* argument, bool reverse, int* type, bool* changed);
struct ListEntryE061
{
    int unk;
    int uTmpnk;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int m_18;
    int m_1c;
};
struct FlagE061
{
    unsigned char m_00;
    unsigned char unkCur;
    unsigned char unkValue;
    unsigned char uNewnk;
};
struct BlockE061
{
    int m_00;
};
struct ListE061
{
    BlockE061** m_00;
    int m_04;
    int unk08;
    ListEntryE061** m_0c;
    int m_10;
};
void __cdecl ProcessInput(int a1, char* pos, ListEntryE061* cur, FlagE061 flag, int* consumed, bool* pbOut);
void __cdecl ProcessListBlocks(int a1, ListE061* list);
struct TimedEntry
{
    int field00, field04, field08;
    float time;
};
struct TimedEntryCollection
{
    int count;
    int capacity;
    TimedEntry** entries;
    TimedEntry* lastRemoved;
    void RemoveExpiredEntries(float threshold);
};
struct FUN_00e00dd0_cls
{
    int vptr00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;

    void __thiscall UpdateState_00e00dd0();
};
void ReverseBytesInGroupsOfFour(unsigned char* pucData);
struct S_e05_res
{
    char* __thiscall hkClass_isSuperClass(char* a, S_e05_res* b);
};
struct S_e05_obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual S_e05_res* m4(int value);
};
static bool Object_ProcessAndReturnValue_00e050c0(S_e05_obj* obj, int arg, int value);
struct S_e05_g
{
    S_e05_obj* volatile obj;
    int volatile arg;
    int volatile val;
    bool volatile out;
};
S_e05_g g_e05 = {0, 0, 0, 0};
void e05_probe_caller(void);
inline void swap16E05E(void* pv)
{
    char* c = (char*)pv;
    char t = c[0];
    c[0] = c[1];
    c[1] = t;
}
inline void swapE05E(char& a, char& b)
{
    char t = a;
    a = b;
    b = t;
}
inline void swap32E05E(void* pv)
{
    char* c = (char*)pv;
    swapE05E(c[0], c[3]);
    swapE05E(c[1], c[2]);
}
// Serialized header entry: two 16-bit fields, four-byte stride in SwapHkHeaderE05E (0x00e05ef0).
struct SerializedHalfwordPair
{
    unsigned short m_uiFilterValue;
    unsigned short m_auiShapeKeys;
};
struct hkHeaderE05E
{
    unsigned char unk00;
    unsigned char unk01;
    SerializedHalfwordPair m_entries[7];
    unsigned char unk1E;
    unsigned char unk1F;
    unsigned char unk20;
    unsigned char m_iNumberOfEntries;
    unsigned char unk22;
    unsigned char unk23;
    int m_24;
    int unk28;
    int unk2c;
    int m_30[4];
};
void __cdecl SwapHkHeaderE05E(hkHeaderE05E* h);
struct S00e0bf50_Acc
{
    float m_00;
    float m_04;
    float m_08;
    float m_0c;
    float m_10;
    float m_14;
    float m_18;
    float m_1c;
    unsigned short m_20;
    unsigned short m_22;
    unsigned short m_24;
    unsigned short m_26;
    unsigned short m_28;
    unsigned short m_2a;
    unsigned short m_2c;
    unsigned short m_2e;
};
static void hkMakeSum(S00e0bf50_Acc* dst, S00e0bf50_Acc* src);
void S00e0bf50_Call(S00e0bf50_Acc* dst, S00e0bf50_Acc* src);
template <int SIZE> __forceinline void memCpyOneAlignedE030(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}
void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);
struct RangeE030
{
    int m_iStart;
    int m_iFirstValue;
};
int __cdecl ReadIntAtOffset(const char* pcData, int* piPos);
int __cdecl ReadPaddedString(const char* pcData, int* piPos);
class ParserE030
{
  public:
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
    const char* m_pcBegin;
    const char* m_pcEnd;

    void ReadOffsetStringRanges(int iOffset, hkArray<RangeE030>& kOut);
};
struct Slot00e04e10
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void* v10(int a);
};
struct Mgr00e04e10
{
    unsigned char* hkClass_isSuperClass(unsigned char* out, void* key);
};
static bool __cdecl hkClass_isSuperClass_UpdateState_00e04e10(Slot00e04e10* obj, int a, int b);
bool keep_alive_b11536(Slot00e04e10* obj, int a, int b);
extern const char DAT_010cb2c0[];
extern const char DAT_010eaa4c[];
extern const char DAT_010c65b0[];
extern const char DAT_010eaa40[];
extern const char DAT_010eaa30[];
extern const char DAT_010eaa24[];
extern const char DAT_010eaa18[];
extern const char DAT_010eaa0c[];
extern const char DAT_010eaa00[];
extern const char DAT_010ea9f4[];
extern const char DAT_010ea9e0[];
extern const char DAT_010ea9d4[];
extern const char DAT_010ea9cc[];
extern const char DAT_010ea9c0[];
extern const char DAT_010ea9b4[];
extern const char DAT_010c41dc[];
extern const char DAT_010ea9a8[];
extern const char DAT_010ea998[];
extern const char DAT_010ea984[];
extern const char DAT_010ea974[];
extern const char DAT_010c90a4[];
extern const char DAT_010ea96c[];
extern const char DAT_010ea958[];
extern const char DAT_010ea948[];
extern const char DAT_010ea93c[];
extern const char DAT_010ea92c[];
extern const char DAT_010ea920[];
extern const char DAT_010ea910[];
extern const char DAT_010ea900[];
extern const char DAT_010ea8f4[];
extern const char DAT_010ea8ec[];
extern const char DAT_010ea8e4[];
extern const char DAT_010ea8d4[];
extern const char DAT_010ea8c4[];
extern const char DAT_010c65bc[];
extern const char DAT_010ea8ac[];
extern const char DAT_010ea89c[];
extern const char DAT_010ea88c[];
extern const char DAT_010ea878[];
struct ColorRegistry
{
    void hkMonitorStreamColorTable_addColor(const char* name, unsigned int color);
    void RegisterDefaultColors();
};
struct FUN_00e004f0 : S_00e003d0_Base, S_00e003d0_Arrs
{
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    S_00e003d0_Arr arrd0;
    FUN_00e004f0(int flag);
};
// sub ecx,8; jmp target  ==  MSVC adjustor thunk (second base of a multiple-inheritance override)
struct SpawnedPrimaryBase
{
    virtual void AdjustThisAndForward_00e00980();
    int unk04;
};
struct SpawnedSecondaryBase
{
    virtual void AdjustThisAndForward_00e00980();
};
struct SpawnedDerived : SpawnedPrimaryBase, SpawnedSecondaryBase
{
    SpawnedDerived();
// @fnv 0x00e00980
// src: GUESS 0x00e00980 (confidence: low)
    virtual void AdjustThisAndForward_00e00980();
};
SpawnedDerived::SpawnedDerived()
{}
struct FUN_00e11480
{
    virtual ~FUN_00e11480();
};
extern "C" void _ReadWriteBarrier();
struct VecNode113
{
    VecNode113* next;
    unsigned int unk04, unk08, unk0c;
    __m128 vector;
};
struct VecList113
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    VecNode113* head;
    __m128* ProcessEntries_00e11570(__m128* __restrict out, const __m128* direction);
};
float __cdecl Hkgpmesh_ComputeValues_00e13870(int a, int b);
int __stdcall Object_IsComputedValueBelowThreshold_00e16e20(int a, int b, float c);
struct ExportPlacement;
inline void* operator new(unsigned int, ExportPlacement* address)
{
    return address;
}
struct ExportRecord
{
    const char* name;
    void* object;
};
struct ExportHeap
{
    int unk00, unk04, unk08, unk0c;
    void* heap;
    static ExportHeap& __cdecl hkMemoryRouter_getInstance();
};
struct ExportAlloc
{
    __forceinline ExportHeap& get(void*) const
    {
        return ExportHeap::hkMemoryRouter_getInstance();
    }
};
template <class T> __forceinline void createExportObjects(T* first, int count)
{
    for (int remaining = 0; remaining < count; ++remaining)
        new (reinterpret_cast<ExportPlacement*>(first + remaining)) T;
}
template <class T> struct ExportStorage
{
    T* data;
    int size;
    int capacity;
    __forceinline int capacityValue() const
    {
        return capacity & 0x3fffffff;
    }
    __forceinline T& addWith(ExportHeap& router)
    {
        if (size == capacityValue())
            ResizeAudioStream(router.heap, this, sizeof(T));
        createExportObjects(data + size, 1);
        return data[size++];
    }
};
template <class T, class A> struct ExportList : ExportStorage<T>
{
    __forceinline T& add()
    {
        return this->addWith(A().get(this));
    }
};
struct ExportSection
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    int exportStart;
    int exportEnd;
    void ReadRecords(const void* base, ExportList<ExportRecord, ExportAlloc>& out) const;
};
void __cdecl Object_DoNothing_00e0cce0();
struct Allocator;
struct PtrMap
{
    void* unk00;
    int unk04;
    int unk08;
    __forceinline void init()
    {
        unk00 = 0;
        unk04 = 0;
        unk08 = -1;
        EnsureCapacity(hkMemoryRouter_getInstance()->GetAlloc(), 0);
    }
    __forceinline void destroy()
    {
        ProcessArgument(hkMemoryRouter_getInstance()->GetAlloc());
        Object_DoNothing();
    }
    void EnsureCapacity(Allocator& allocator, int count);
    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(Allocator& allocator, unsigned int key, unsigned int value);
    unsigned int LookupHashEntry(unsigned int key, unsigned int defaultValue);
    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_remove(unsigned int key);
    void ProcessArgument(Allocator& allocator);
    void Object_DoNothing();
    __forceinline void insert(unsigned int key, unsigned int value)
    {
        hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(hkMemoryRouter_getInstance()->GetAlloc(), key, value);
    }
    __forceinline unsigned int FindValueForKey(unsigned int key, unsigned int def)
    {
        return LookupHashEntry(key, def);
    }
    __forceinline void remove(unsigned int key)
    {
        hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_remove(key);
    }
};
template <class T> struct ListItem
{
    T* m_next;
    T* m_pSecondNode;
    ListItem()
    {}
    ListItem(const ListItem&)
    {}
};
struct Vertex : ListItem<Vertex>
{
    int unk08;
    int unk0c;
    Vec4 m_vec10;
    Vec4 m_vec20;
    Vec4 m_vec30;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    Vertex(const Vertex& src)
        : ListItem<Vertex>(src), m_vec10(src.m_vec10), m_vec20(src.m_vec20), m_vec30(src.m_vec30), unk40(src.unk40),
          unk44(src.unk44)
    {}
};
struct Triangle;
struct TriangleTopologyEntry : ListItem<Triangle>
{
    Vertex* m_kVertices[3];
    unsigned int m_ppLinks[3];
    __forceinline Vertex*& vertex(int i)
    {
        return m_kVertices[i];
    }
    __forceinline unsigned int& link(int i)
    {
        return m_ppLinks[i];
    }
};
struct Triangle : TriangleTopologyEntry
{
    Vec4 m_vec20;
    int unk30, unk34, unk38, unk3c, unk40;
    int unk44;
    int unk48;
    int unk4c;
    Triangle(const Triangle& src)
        : TriangleTopologyEntry(src), m_vec20(src.m_vec20), unk30(src.unk30), unk34(src.unk34), unk38(src.unk38),
          unk3c(src.unk3c), unk40(src.unk40)
    {}
};
struct Topology
{
    static __forceinline unsigned int uid2ulong(void* t, unsigned int i)
    {
        return (*(const unsigned int*)&t) + (unsigned int)i;
    }
    template <class T> static __forceinline void ulong2uid(unsigned int uid, T*& t, unsigned int& i)
    {
        i = (unsigned int)(uid & 3);
        uid &= ~3;
        t = *(T**)&uid;
    }
    static __forceinline unsigned int packUid(void* t, unsigned int i)
    {
        return uid2ulong(t, i);
    }
    template <class T> static __forceinline void unpackUid(unsigned int uid, T*& t, unsigned int& i)
    {
        ulong2uid(uid, t, i);
    }
};
struct Edge
{
    Triangle* m_pkTriangle;
    unsigned int m_uiEdgeIndex;

    __forceinline Edge(Triangle* t, unsigned int i) : m_pkTriangle(t), m_uiEdgeIndex(i)
    {}
    __forceinline Edge(const unsigned int& id)
    {
        Topology::unpackUid(id, m_pkTriangle, m_uiEdgeIndex);
    }
    __forceinline Triangle* triangle() const
    {
        return m_pkTriangle;
    }
    __forceinline Edge link() const
    {
        return Edge(m_pkTriangle->link(m_uiEdgeIndex));
    }
    __forceinline bool isValid() const
    {
        return triangle() != 0;
    }
    __forceinline bool isNaked() const
    {
        return !link().isValid();
    }
    __forceinline unsigned int uid() const
    {
        return Topology::packUid(m_pkTriangle, m_uiEdgeIndex);
    }
    __forceinline void bind(const Edge& edge) const
    {
        m_pkTriangle->link(m_uiEdgeIndex) = edge.uid();
        if (edge.isValid())
            edge.m_pkTriangle->link(edge.m_uiEdgeIndex) = uid();
    }
};
template <class T> struct PoolBlock
{
    T m_elements[32];
    T* m_free;
    int m_iAllocatedCount;
};
struct PoolBase
{
    void* AllocateChainedSlotBlock();
};
template <class T> struct PoolList : PoolBase
{
    PoolBlock<T>** m_kBlocks;
    int m_iBlockCount;
    int unk08;
    T* m_pFirstNode;
    int m_iElementCount;
    int unk14;

    __forceinline void* allocateItem()
    {
        PoolBlock<T>* block = (m_iBlockCount && m_kBlocks[0]->m_free) ? m_kBlocks[0] : (PoolBlock<T>*)AllocateChainedSlotBlock();
        T* element = block->m_free;
        block->m_free = *(T**)element;
        ++block->m_iAllocatedCount;
        return element;
    }
    __forceinline T* allocate(const T& value)
    {
        T* item = new (allocateItem()) T(value);
        item->m_pSecondNode = 0;
        item->m_next = m_pFirstNode;
        if (m_pFirstNode)
            m_pFirstNode->m_pSecondNode = item;
        m_iElementCount++;
        m_pFirstNode = item;
        return item;
    }
};
struct Mesh
{
    int unk00;
    int unk04;
    PoolList<Vertex> m_kVertices;
    PoolList<Triangle> m_uiTriangleCount;
    void ReleaseSubobject();
    void hkgpMesh_append(Mesh* mesh);
};
extern "C" void _ReadWriteBarrier();
struct ScalarQ
{
    __m128 value;
    ScalarQ(__m128 v) : value(v)
    {}
    operator float() const
    {
        float result;
        _mm_store_ss(&result, value);
        return result;
    }
};
inline ScalarQ operator+(const ScalarQ& a, const ScalarQ& b)
{
    return _mm_add_ss(a.value, b.value);
}
struct VertexQ
{
    VertexQ* next;
    VertexQ* prev;
    int u8, uC;
    hkVector4 position;
    hkVector4 normal;
    hkVector4 data;
};
struct BlockQ;
struct PoolQ
{
    BlockQ** blocks;
    int count;
    int u8;
    VertexQ* head;
    int size;
};
struct MeshQ
{
    int u0, u4;
    PoolQ pool;
    int unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac;
    int unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc;
    int unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec;
    int unkf0, unkf4, unkf8, unkfc, unk100;
    float squaredTolerance;
    int ProcessEntries_00e11990(const hkVector4& plane, int index);
};

struct SortItem
{
    int unk00;
    int unk04;
    int unk08;
    float fPriority;
};

struct SortedList
{
    int iCount;
    int unk04;
    SortItem** ppItems;

    void hkpMoppDefaultSplitter_hkpMoppMaxList_addElement(SortItem* apItem);
};

// @fnv 0x00e09670
// src: HAVOK_LIB 0x00e09670
void SortedList::hkpMoppDefaultSplitter_hkpMoppMaxList_addElement(SortItem* apItem)
{
    float fPriority = apItem->fPriority;
    int i;
    for (i = iCount - 1; i >= 0; i--)
    {
        if (!ppItems[i] || !(ppItems[i]->fPriority < fPriority))
            break;
        ppItems[i + 1] = ppItems[i];
    }
    ppItems[i + 1] = apItem;
    iCount++;
}
