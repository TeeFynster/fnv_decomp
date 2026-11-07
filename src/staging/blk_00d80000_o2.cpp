#define FNV64_HKVECTOR4_OWN_DEFAULT
#define FNV64_HKVECTOR4_OWN_ASSIGN
// staging/blk_00d80000_o2.cpp: IdxStand_, ObjD9A4, MonitorBuffer (124 functions)
#include <stdlib.h>
// Keep the unit's minimal SSE declarations: the SDK byte-array lanes add /GS checks.
#define _INCLUDED_MM2
// Exe 0x00d974f0 FUN_00d974f0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) { float m128_f32[4]; unsigned __int64 m128_u64[2]; } __m128, LocalM128;
#define FNV_FOURFLOATVECTOR_NO_SSE
#define FNV_TRANSFORM_NO_SSE
#include "../../include/hkVector4.h"
#include "../../include/Transform.h"
#include "../../include/hkJobType.h"

// src/staging/blk_00d80000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkBool.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkpShape.h"
#include "../../include/hkpCdBody.h"
#include "../../include/hkpAgent3Input.h"
#include "../../include/hkpCollisionDispatcher.h"
#include "../../include/hkpCollisionInput.h"
#include "../../include/hkpConstraintSolverResources.h"
#include "../../include/hkStatisticsCollector.h"
#include "../../include/AutoMemContext.h"
#include "../../include/NiBinaryStream.h"
#include "../../include/NiStream.h"
#include "../../include/hkMonitorStream.h"
#include "../../include/hkArray.h"
#include "../../include/hkBitField.h"
#include "../../include/hkpConstraintInstance.h"
#include "../../include/hkpConstraintListener.h"
// hkTimerCommand_blk_00d80000_o2: local type (was include/hkTimerCommand.h, which had no evidence of one real class); no method of it is bound to a named game function
class hkTimerCommand_blk_00d80000_o2
{
public:
    const char* m_pCommandName;
    unsigned int m_ticks;
    unsigned int m_auiShapeKeys;
};
// hkpTaskHeader_blk_00d80000_o2: local type (was include/hkpTaskHeader.h, which had no evidence of one real class); no method of it is bound to a named game function
class hkpTaskHeader_blk_00d80000_o2 {
public:
    int unk00;
    int m_iJobId;
};

extern int DAT_010cc4f4;

// @fnv 0x00d9f6d0
// src: GUESS 0x00d9f6d0 (confidence: low)
void __cdecl Runtime_UpdateState_00d9f6d0(int* p)
{
    if (p)
        *p = (int)&DAT_010cc4f4;
}

struct FUN_00d85300_Stub {
    void ComputeValue_00d85300(int*);
};
struct FUN_00d85a20_Stub : FUN_00d85300_Stub {
    int* CopyStateFrom(int* p);
};
// @fnv 0x00d85a20
int* FUN_00d85a20_Stub::CopyStateFrom(int* p)
{
    ComputeValue_00d85300(p);
    *(int*)((char*)this + 0x90) = *(int*)((char*)p + 0x90);
    *(int*)((char*)this + 0x94) = *(int*)((char*)p + 0x94);
    *(int*)((char*)this + 0x98) = *(int*)((char*)p + 0x98);
    *(int*)((char*)this + 0x9c) = *(int*)((char*)p + 0x9c);
    *(int*)((char*)this + 0xa0) = *(int*)((char*)p + 0xa0);
    *(int*)((char*)this + 0xa4) = *(int*)((char*)p + 0xa4);
    *(int*)((char*)this + 0xa8) = *(int*)((char*)p + 0xa8);
    *(int*)((char*)this + 0xac) = *(int*)((char*)p + 0xac);
    *(int*)((char*)this + 0xb0) = *(int*)((char*)p + 0xb0);
    *(int*)((char*)this + 0xb4) = *(int*)((char*)p + 0xb4);
    *(int*)((char*)this + 0xb8) = *(int*)((char*)p + 0xb8);
    *(int*)((char*)this + 0xbc) = *(int*)((char*)p + 0xbc);
    *(int*)((char*)this + 0xc0) = *(int*)((char*)p + 0xc0);
    *(int*)((char*)this + 0xc4) = *(int*)((char*)p + 0xc4);
    *(int*)((char*)this + 0xc8) = *(int*)((char*)p + 0xc8);
    return (int*)this;
}

extern char DAT_01267e30;

class FNVDispatchNode {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual unsigned int v08();

    FNVDispatchNode* Resolve();

    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    FNVDispatchNode* m_18;
};

// @fnv 0x00d84ca0
char* GetDispatchTarget(FNVDispatchNode* pNode)
{
    unsigned int idx = pNode->v08();
    while (idx <= 0xf) {
        switch (idx) {
        case 0:
            return (char*)pNode + 0x20;
        case 1:
            return (char*)pNode + 0x50;
        case 2:
            return (char*)pNode + 0x50;
        case 3:
            return &DAT_01267e30;
        case 4:
            return &DAT_01267e30;
        case 5:
            return &DAT_01267e30;
        case 6:
            return (char*)pNode + 0x50;
        case 7:
            return (char*)pNode + 0x50;
        case 8:
            return (char*)pNode + 0x20;
        case 9:
            return (char*)pNode + 0x50;
        case 10:
            return &DAT_01267e30;
        case 11:
            return &DAT_01267e30;
        case 12:
            pNode = pNode->m_18;
            break;
        case 13:
            pNode = pNode->Resolve();
            break;
        case 14:
            return (char*)pNode + 0x50;
        case 15:
            return (char*)pNode + 0x20;
        default:
            return &DAT_01267e30;
        }
        idx = pNode->v08();
    }
    return &DAT_01267e30;
}

struct AllocIface {
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
void __cdecl hkString_memCpy(void* dst, const void* src, unsigned int size);

struct FUN_00d85360_cls {
    void* m_vptr;
    unsigned short m_w04;
    unsigned short m_w06;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2c;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3c;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4c;

    FUN_00d85360_cls* FUN_00d54290();
};

// @fnv 0x00d85360
// src: COMMUNITY 0x00d85360
FUN_00d85360_cls* __cdecl hkpConstraintDataUtils_copyAtoms_hkpBallAndSocketConstraintData_(int pSource)
{
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    FUN_00d85360_cls* obj = (FUN_00d85360_cls*)reinterpret_cast<AllocIface*>(holder->m_heap)->Alloc(0x50);
    obj->m_w04 = 0x50;
    obj = obj->FUN_00d54290();
    hkString_memCpy((char*)obj + 0x10, (char*)pSource + 0x10, 0x38);
    return obj;
}

namespace fnv_00d853a0 {
struct AllocIface {
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
void __cdecl hkString_memCpy(void* dst, const void* src, unsigned int size);

struct FUN_00d853a0_cls {
    void* m_vptr;
    unsigned short m_w04;
    unsigned short m_w06;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2c;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3c;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4c;
    int m_i50;
    int m_i54;
    int m_i58;
    int m_i5c;
    int m_i60;
    int m_i64;
    int m_i68;
    int m_i6c;
    int m_i70;
    int m_i74;
    int m_i78;
    int m_i7c;
    int m_i80;
    int m_i84;
    int m_i88;
    int m_i8c;
    int m_i90;
    int m_i94;
    int m_i98;
    int m_i9c;
    int m_ia0;
    int m_ia4;
    int m_ia8;
    int m_iac;

    FUN_00d853a0_cls* Init();
};

// Allocates a 0xb0-byte object via the global allocator, initializes it, copies 0x9c bytes from a1+0x10 into obj+0x10, and returns obj.
// @fnv 0x00d853a0
// src: HAVOK_LIB 0x00d853a0
FUN_00d853a0_cls* __cdecl copyConstraintAtoms_class_hkpHingeConstraintData(int a1)
{
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    FUN_00d853a0_cls* obj = (FUN_00d853a0_cls*)reinterpret_cast<AllocIface*>(holder->m_heap)->Alloc(0xb0);
    obj->m_w04 = 0xb0;
    obj = obj->Init();
    hkString_memCpy((char*)obj + 0x10, (char*)a1 + 0x10, 0x9c);
    return obj;
}
}  // namespace fnv_00d853a0

namespace fnv_00d853f0 {
struct MemAllocD853 {
    virtual void v0();
    virtual void* Alloc(unsigned int uiSize);
};
struct ObjD853 {
    void* m_vtbl;
    unsigned short m_usSize;
    char pad006[0x0a];
    ObjD853* FUN_00cb9090();
};
extern "C" hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
extern "C" void* __cdecl hkString_memCpy(void* pDst, const void* pSrc, unsigned int ItemUpdateArray);

// @fnv 0x00d853f0
// src: HAVOK_LIB 0x00d853f0
ObjD853* __cdecl copyConstraintAtoms_class_hkpLimitedHingeConstraintData(char* pSource)
{
    hkMemoryRouter* pSingleton = hkMemoryRouter_getInstance();
    MemAllocD853* pAllocator = reinterpret_cast<MemAllocD853*>(pSingleton->m_heap);
    ObjD853* pObj = (ObjD853*)pAllocator->Alloc(0xe0);
    pObj->m_usSize = 0xe0;
    ObjD853* pResult = pObj->FUN_00cb9090();
    hkString_memCpy((char*)pResult + 0x10, pSource + 0x10, 0xcc);
    return pResult;
}
}  // namespace fnv_00d853f0

namespace fnv_00d85440 {
struct D85440Allocator {
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

inline D85440Allocator& GetShapeHeap(hkMemoryRouter& holder)
{
    return *reinterpret_cast<D85440Allocator*>(holder.m_heap);
}

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();

void D85440MemCpy(void* dst, const void* src, int nbytes);

class D85440ReferencedObject {
public:
    static void* operator new(unsigned int nbytes)
    {
        D85440ReferencedObject* b = static_cast<D85440ReferencedObject*>(GetShapeHeap(hkMemoryRouter_getInstance()).AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }
    static void operator delete(void* p);

    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

struct D85440Vector3 {
    float x;
    float y;
    float z;
};

class D85440Shape : public D85440ReferencedObject {
public:
    D85440Shape() throw();

    int unk08;
    D85440Vector3 m_vHalfExtents;
    int unk18;
    int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C;
    int unkA0; int unkA4; int unkA8; int unkAC;
};

// Allocates a new D85440Shape and copies the source shape's vector into it, returning the new shape.
// @fnv 0x00d85440
D85440Shape* CloneShape(const D85440Shape* pkSource)
{
    D85440Shape* pkShape = new D85440Shape();
    D85440MemCpy(&pkShape->m_vHalfExtents, &pkSource->m_vHalfExtents, sizeof(D85440Vector3));
    return pkShape;
}
}  // namespace fnv_00d85440

namespace fnv_00d85490 {
extern int DAT_010cc4f4;

struct FUN_00d85490_Allocator {
    virtual void FUN_00d85490_Alloc0();
    virtual void* FUN_00d85490_Alloc1(unsigned int size);
};

struct FUN_00d4fe80_Stub {
    int unk00;
    unsigned short unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned char unk10;
    void* FUN_00d4fe80();
};

extern void* __cdecl hkMemoryRouter_getInstance();
extern void __cdecl hkString_memCpy(void* destination, const void* source, unsigned int size);

// @fnv 0x00d85490
void* __cdecl CloneAllocatedObject(int* source)
{
    hkMemoryRouter* manager =
        reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
    FUN_00d4fe80_Stub* result =
        reinterpret_cast<FUN_00d4fe80_Stub*>(
            reinterpret_cast<FUN_00d85490_Allocator*>(manager->m_heap)->FUN_00d85490_Alloc1(0xD0));

    result->unk04 = 0xD0;
    result = reinterpret_cast<FUN_00d4fe80_Stub*>(result->FUN_00d4fe80());

    hkString_memCpy(
        reinterpret_cast<unsigned char*>(result) + 0x10,
        reinterpret_cast<const unsigned char*>(source) + 0x10,
        0xC0);

    return result;
}
}  // namespace fnv_00d85490

namespace fnv_00d854e0 {
// CloneStub @ 0x00d854e0, size 68, __cdecl (caller pops), /MT /O2 /GS /EHsc /Gy
//
// Reconstructed behavior:
//   hkMemoryRouter* a = FUN_00c85750();              // cdecl, no args
//   C* obj        = allocator->Create(0x140);       // virtual slot +4, __thiscall
//   obj->unk04    = 0x140;                       // u16 field at +4
//   D* result     = obj->FUN_00cdf2f0();         // __thiscall, no stack args
//   FUN_00cb1260(&result->unk10, &src->unk10, 0x130);  // cdecl, 3 args
//   return result;

struct C_Stub;
struct D_Stub;

// polymorphic stand-in reached through hkMemoryRouter::unk10; Create sits in vtable slot +4
struct B_Stub {
    virtual void* virt0();
    virtual C_Stub* Create(int size);
};

struct C_Stub {
    int unk00;
    unsigned short unk04;
    D_Stub* FUN_00cdf2f0();   // game function at 0x00cdf2f0 (__thiscall member)
};

struct D_Stub {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

// caller-supplied source structure; only the sub-object at +0x10 is touched
struct Src_Stub {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
void __cdecl hkString_memCpy(void* dst, const void* src, unsigned int size);

// Allocates a 0x140-byte object, sets its size, then copies the source payload into the constructed result.
// @fnv 0x00d854e0
D_Stub* __cdecl CloneStub(Src_Stub* src)
{
    hkMemoryRouter* a = hkMemoryRouter_getInstance();
    C_Stub* obj = reinterpret_cast<B_Stub*>(a->m_heap)->Create(0x140);
    obj->unk04 = 0x140;
    D_Stub* result = obj->FUN_00cdf2f0();
    hkString_memCpy(&result->unk10, &src->unk10, 0x130);
    return result;
}
}  // namespace fnv_00d854e0

namespace fnv_00d85530 {
struct SpawnedAllocator {
    virtual void v00();
    virtual void* Alloc(unsigned int size);
};

struct SpawnedObject {
    int unk00;
    unsigned short m_usSize;
    unsigned short unk06;
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

    SpawnedObject* Ctor();
};

struct SpawnedSource {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
void* __cdecl hkString_memCpy(void* dst, const void* src, unsigned int size);

// Allocates a 0x50-byte SpawnedObject from the holder's allocator, sets its size, constructs it, and copies 0x38 bytes from pSrc+0x10 into unk10.
// @fnv 0x00d85530
// src: COMMUNITY 0x00d85530
SpawnedObject* __cdecl hkpConstraintDataUtils_copyAtoms_hkpStiffSpringConstraintData_(SpawnedSource* pSrc)
{
    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    SpawnedAllocator* pAllocator = reinterpret_cast<SpawnedAllocator*>(pHolder->m_heap);
    SpawnedObject* pObj = (SpawnedObject*)pAllocator->Alloc(0x50);
    pObj->m_usSize = 0x50;
    pObj = pObj->Ctor();
    hkString_memCpy(&pObj->unk10, (char*)pSrc + 0x10, 0x38);
    return pObj;
}
}  // namespace fnv_00d85530

namespace fnv_00d85570 {
struct AllocIface {
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
void __cdecl hkString_memCpy(void* dst, const void* src, unsigned int size);

struct FUN_00d85570_cls {
    void* m_vptr;
    unsigned short m_w04;
    unsigned short m_w06;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2c;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3c;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4c;
    int m_i50;
    int m_i54;
    int m_i58;
    int m_i5c;
    int m_i60;
    int m_i64;
    int m_i68;
    int m_i6c;
    int m_i70;
    int m_i74;
    int m_i78;
    int m_i7c;
    int m_i80;
    int m_i84;
    int m_i88;
    int m_i8c;
    int m_i90;
    int m_i94;
    int m_i98;
    int m_i9c;
    int m_ia0;
    int m_ia4;
    int m_ia8;
    int m_iac;
    int m_ib0;
    int m_ib4;
    int m_ib8;
    int m_ibc;
    int m_ic0;
    int m_ic4;
    int m_ic8;
    int m_icc;
    int m_id0;
    int m_id4;
    int m_id8;
    int m_idc;
    int m_ie0;
    int m_ie4;
    int m_ie8;
    int m_iec;
    int m_if0;
    int m_if4;
    int m_if8;
    int m_ifc;
    int m_i100;
    int m_i104;
    int m_i108;
    int m_i10c;
    int m_i110;
    int m_i114;
    int m_i118;
    int m_i11c;
    int m_i120;
    int m_i124;
    int m_i128;
    int m_i12c;
    int m_i130;
    int m_i134;
    int m_i138;
    int m_i13c;
    int m_i140;
    int m_i144;
    int m_i148;
    int m_i14c;
    int m_i150;
    int m_i154;
    int m_i158;
    int m_i15c;

    FUN_00d85570_cls* Init();
};

// @fnv 0x00d85570
FUN_00d85570_cls* __cdecl CloneWithInit(int apSource)
{
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    FUN_00d85570_cls* obj = (FUN_00d85570_cls*)reinterpret_cast<AllocIface*>(holder->m_heap)->Alloc(0x160);
    obj->m_w04 = 0x160;
    obj = obj->Init();
    hkString_memCpy((char*)obj + 0x10, (char*)apSource + 0x10, 0x124);
    return obj;
}
}  // namespace fnv_00d85570

namespace fnv_00d855c0 {
struct FUN_00d855c0_Factory {
    virtual void FUN_00d85300_Unused() = 0;
    virtual void* ComputeValue_00d85300(int size);
};

struct FUN_00d855c0_Data {
    int unk00;
    unsigned short unk04;
};

extern "C" hkMemoryRouter* hkMemoryRouter_getInstance();
extern "C" void* __fastcall FUN_00d84bd0(void* object);
extern "C" void* hkString_memCpy(void* destination, const void* source, unsigned int size);

// @fnv 0x00d855c0
void* __cdecl CloneDataBlock(void* source)
{
    hkMemoryRouter* manager = hkMemoryRouter_getInstance();
    FUN_00d855c0_Data* data = static_cast<FUN_00d855c0_Data*>(
        reinterpret_cast<FUN_00d855c0_Factory*>(manager->m_heap)->ComputeValue_00d85300(0xB0));

    data->unk04 = 0xB0;

    void* result = FUN_00d84bd0(data);
    hkString_memCpy(
        static_cast<unsigned char*>(result) + 0x10,
        static_cast<unsigned char*>(source) + 0x10,
        0x94);

    return result;
}
}  // namespace fnv_00d855c0

namespace fnv_00d85610 {
struct AllocIface {
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
void __cdecl hkString_memCpy(void* dst, const void* src, unsigned int size);

struct FUN_00d85610_cls {
    void* m_vptr;
    unsigned short m_w04;
    unsigned short m_w06;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2c;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3c;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4c;
    int m_i50;
    int m_i54;
    int m_i58;
    int m_i5c;
    int m_i60;
    int m_i64;
    int m_i68;
    int m_i6c;
    int m_i70;
    int m_i74;
    int m_i78;
    int m_i7c;

    FUN_00d85610_cls* Init();
};

// Allocates an 0x80-byte object via the holder's allocator, sets its size field, calls Init, then copies 0x70 bytes from a1+0x10 into obj+0x10 and returns obj.
// @fnv 0x00d85610
FUN_00d85610_cls* __cdecl CloneWithCopiedPayload(int apSource)
{
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    FUN_00d85610_cls* obj = (FUN_00d85610_cls*)reinterpret_cast<AllocIface*>(holder->m_heap)->Alloc(0x80);
    obj->m_w04 = 0x80;
    obj = obj->Init();
    hkString_memCpy((char*)obj + 0x10, (char*)apSource + 0x10, 0x70);
    return obj;
}
}  // namespace fnv_00d85610

namespace fnv_00d856b0 {
struct AllocIface {
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
void __cdecl hkString_memCpy(void* dst, const void* src, unsigned int size);

struct FUN_00d856b0_cls {
    void* m_vptr;
    unsigned short m_w04;
    unsigned short m_w06;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2c;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3c;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4c;
    int m_i50;
    int m_i54;
    int m_i58;
    int m_i5c;
    int m_i60;
    int m_i64;
    int m_i68;
    int m_i6c;
    int m_i70;
    int m_i74;
    int m_i78;
    int m_i7c;
    int m_i80;
    int m_i84;
    int m_i88;
    int m_i8c;
    int m_i90;
    int m_i94;
    int m_i98;
    int m_i9c;
    int m_ia0;
    int m_ia4;
    int m_ia8;
    int m_iac;
    int m_ib0;
    int m_ib4;
    int m_ib8;
    int m_ibc;

    FUN_00d856b0_cls* Init();
};

// @fnv 0x00d856b0
FUN_00d856b0_cls* __cdecl CloneWithAllocatedCopy(int apSource)
{
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    FUN_00d856b0_cls* obj = (FUN_00d856b0_cls*)reinterpret_cast<AllocIface*>(holder->m_heap)->Alloc(0xc0);
    obj->m_w04 = 0xc0;
    obj = obj->Init();
    hkString_memCpy((char*)obj + 0x10, (char*)apSource + 0x10, 0xac);
    return obj;
}
}  // namespace fnv_00d856b0

struct S_00d85af0_Base {
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
    void ComputeValue_00d85300(const S_00d85af0_Base* o);
};
struct S_00d85af0_V3 { float x, y, z; };
struct S_00d85af0_Cls : S_00d85af0_Base {
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    S_00d85af0_V3 unkb4;
    S_00d85af0_Cls* AssignFrom(const S_00d85af0_Cls* o);
};
// @fnv 0x00d85af0
S_00d85af0_Cls* S_00d85af0_Cls::AssignFrom(const S_00d85af0_Cls* o) {
    ComputeValue_00d85300(o);
    unk90 = o->unk90;
    unk94 = o->unk94;
    unk98 = o->unk98;
    unk9c = o->unk9c;
    unka0 = o->unka0;
    unka4 = o->unka4;
    unka8 = o->unka8;
    unkac = o->unkac;
    unkb0 = o->unkb0;
    unkb4 = o->unkb4;
    return this;
}

struct CpuOpaque;
extern CpuOpaque DAT_01269514;
// @fnv 0x00d9f6c0
// src: GUESS 0x00d9f6c0 (confidence: low)
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00d9f6c0()
{
    return &DAT_01269514;
}

extern int DAT_010cc4f4;

// @fnv 0x00d9f6e0
// src: GUESS 0x00d9f6e0 (confidence: low)
unsigned int __cdecl Object_ComputeValue_00d9f6e0() {
    return reinterpret_cast<unsigned int>(&DAT_010cc4f4);
}

// Havok object clone: allocate a default instance and copy the payload (everything after the header).

struct D85660Allocator {
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

inline D85660Allocator& GetObjectHeap(hkMemoryRouter& holder)
{
    return *reinterpret_cast<D85660Allocator*>(holder.m_heap);
}

extern "C" hkMemoryRouter& __cdecl D85660GetMemoryRouter() throw();
void __cdecl D85660MemCpy(void* pvDst, const void* pvSrc, int iNumBytes) throw();

class D85660Object {
public:
    D85660Object() throw();
    virtual ~D85660Object();

    static void* operator new(unsigned int nbytes) throw()
    {
        D85660Object* p = static_cast<D85660Object*>(GetObjectHeap(D85660GetMemoryRouter()).AllocateMemoryBlock(nbytes));
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int unk08;
    int unk0C;
    int m_iData010;
    int m_iData014;
    int m_iData018;
    int m_iData01C;
    int m_iData020;
    int m_iData024;
    int m_iData028;
    int m_iData02C;
    int m_iData030;
    int m_iData034;
    int m_iData038;
    int m_iData03C;
    int m_iData040;
    int m_iData044;
    int m_iData048;
    int m_iData04C;
    int m_iData050;
    int m_iData054;
    int m_iData058;
    int m_iData05C;
    int m_iData060;
    int m_iData064;
    int m_iData068;
    int m_iData06C;
    int m_iData070;
    int m_iData074;
    int m_iData078;
    int m_iData07C;
    int m_iData080;
    int m_iData084;
    int m_iData088;
    int m_iData08C;
    int m_iData090;
    int m_iData094;
    int m_iData098;
    int m_iData09C;
};

// Allocates a new D85660Object and copies 0x84 bytes of data starting at m_iData010 from pkSource into it, returning the clone.
// @fnv 0x00d85660
// src: HAVOK_LIB 0x00d85660
D85660Object* __cdecl copyConstraintAtoms_class_hkpHingeLimitsData(const D85660Object* pkSource)
{
    D85660Object* pkClone = new D85660Object;
    D85660MemCpy(&pkClone->m_iData010, &pkSource->m_iData010, 0x84);
    return pkClone;
}

extern int DAT_010d3838;
struct FUN_00d86260_Class {
    unsigned int m_vptr;
    unsigned short m_word04;
    unsigned short m_word06;
    volatile unsigned char m_byte08;
    volatile float m_float0C;
    float m_float10;
    float m_float14;
    float m_float18;
    FUN_00d86260_Class(float a, float b, float c);
};
// @fnv 0x00d86260
FUN_00d86260_Class::FUN_00d86260_Class(float a, float b, float c)
{
    m_word06 = 1;
    m_byte08 = 0;
    m_float0C = -c;
    m_vptr = (unsigned int)&DAT_010d3838;
    m_float10 = c;
    m_byte08 = 3;
    m_float14 = a;
    m_float18 = b;
}

// The shared stream headers leave the transfer state opaque. These inline
// implementations retain the original transfer slots and position updates.
template <class T>
__forceinline void NiBinaryStream::Read(T& value)
{
    unsigned int size = sizeof(T);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) +=
        (*reinterpret_cast<ReadFunction*>(reinterpret_cast<char*>(this) + 8))(this, &value, sizeof(T), &size, 1);
}

template <class T>
__forceinline void NiStream::BinaryRead(T& value) throw()
{
    (*reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x24c))->Read(value);
}

inline unsigned int NiBinaryStream::BinaryWrite(const void* buffer, unsigned int bytes, unsigned int* sizes, unsigned int count)
{
    unsigned int written = (*reinterpret_cast<WriteFunction*>(reinterpret_cast<char*>(this) + 8))(this, buffer, bytes, sizes, count);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += written;
    return written;
}

inline unsigned int NiBinaryStream::BinaryRead(void* buffer, unsigned int bytes, unsigned int* sizes, unsigned int count)
{
    unsigned int read = (*reinterpret_cast<ReadFunction*>(reinterpret_cast<char*>(this) + 0xc))(this, buffer, bytes, sizes, count);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += read;
    return read;
}

struct Struct40 {
    int m_00, m_04, m_08, m_0c;
    int m_10, m_14, m_18, m_1c;
    int m_20, m_24, m_28, m_2c;
    int m_30, m_34, m_38, m_3c;
};

struct TargetData {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    int unk1c;
    char unk20;
    char unk21;
    short unk22;
    int unk24, unk28, unk2c;
    Struct40 unk30;
    Struct40 unk70;
};

struct FUN_00d53200_class {
    int unk00;
    void hkConstraintCinfo_LoadBinary(NiStream&) throw();
};

struct Derived_00d53200 : public FUN_00d53200_class {
    TargetData* unk04;
    void ReadFromStream(NiStream& stream);
};

// @fnv 0x00d86520
void Derived_00d53200::ReadFromStream(NiStream& stream)
{
    hkConstraintCinfo_LoadBinary(stream);
    TargetData* p = unk04;
    stream.BinaryRead(p->unk1c);
    stream.BinaryRead(p->unk20);
    stream.BinaryRead(p->unk30);
    stream.BinaryRead(p->unk70);
}

inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x250);
}

inline unsigned int NiBinaryStream::BinaryRead(void* buffer, unsigned int bytes)
{
    unsigned int size = bytes;
    unsigned int read = (*reinterpret_cast<ReadFunction*>(reinterpret_cast<char*>(this) + 0xc))(this, buffer, bytes, &size, 1);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += read;
    return read;
}

struct Record {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int header;
    unsigned int flag;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int data30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int words40;
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
    unsigned int words70;
};

void __stdcall hkConstraintCinfo_SaveBinary(NiStream* stream);

struct DataOwner {
    unsigned int unknown00;
    Record* record;
    void ReadRecord(NiStream* stream);
};

// Reads a record header, flag, and two 64-byte blocks from the stream into the record via BinaryRead.
// @fnv 0x00d865d0
void DataOwner::ReadRecord(NiStream* stream)
{
    Record* destination = record;
    hkConstraintCinfo_SaveBinary(stream);
    NiBinaryStream* reader = stream->GetBinaryStream();
    reader->BinaryRead((void*)&destination->header, 4);
    reader = stream->GetBinaryStream();
    reader->BinaryRead((void*)&destination->flag, 1);
    reader = stream->GetBinaryStream();
    reader->BinaryRead((void*)&destination->data30, 64);
    reader = stream->GetBinaryStream();
    reader->BinaryRead((void*)&destination->words70, 64);
}

inline int countBitsSetD866(unsigned int n)
{
    n = ((n >> 1) & 0x55555555) + (n & 0x55555555);
    n = ((n >> 2) & 0x33333333) + (n & 0x33333333);
    n = ((n >> 4) & 0x0f0f0f0f) + (n & 0x0f0f0f0f);
    n = ((n >> 8) & 0x000f000f) + (n & 0x000f000f);
    return (n & 0xff) + (n >> 16);
}

// Sums the set bits of each of iNumWords words in puiWords and returns the total count.
// @fnv 0x00d86680
int __cdecl CountBitsInWords(const unsigned int* puiWords, int iNumWords)
{
    int iTotalBits = 0;
    for (int i = 0; i < iNumWords; i++)
        iTotalBits += countBitsSetD866(puiWords[i]);
    return iTotalBits;
}

int __cdecl j_strncmp(const char*, const char*, unsigned int);
const char* __cdecl hkString_strRchr(const char*, int);
const char* __cdecl hkString_strChr(const char*, int);

struct TypeEntry {
    const char* name;
    int unk04;
    int unk08;
};
extern TypeEntry DAT_011b6ab4[];
extern TypeEntry DAT_011b6c4c[];

struct StringBuf {
    char* m_kStringBuffer;
    int m_fRestLength;
    int m_iCapacityState;
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

    void FUN_00d61a50(const char* s);
    void FUN_00d61fc0(int from, int len);
    int Object_ForwardCall_00d616e0(const char* other);
    void UpdateFields_00cbbd40();
};

// Matches typeName against known type prefixes and a type table, returning the corresponding type code or 0.
// @fnv 0x00d86c00
int __cdecl GetTypeCode(const char* typeName) {
    if (j_strncmp(typeName, "enum ", 5) == 0)
        return 0x18;
    if (j_strncmp(typeName, "flags ", 6) == 0)
        return 0x1f;
    if (j_strncmp(typeName, "hkArray<", 8) == 0)
        return 0x16;
    if (j_strncmp(typeName, "hkSimpleArray<", 14) == 0)
        return 0x1a;
    if (j_strncmp(typeName, "char*", 5) == 0)
        return 0x1d;
    if (j_strncmp(typeName, "hkStringPtr", 11) == 0)
        return 0x21;

    const char* star = hkString_strRchr(typeName, '*');
    if (star != 0 && star[1] == '\0')
        return 0x14;

    StringBuf buf;
    buf.FUN_00d61a50(typeName);

    const char* bracket = hkString_strChr(typeName, '[');
    if (bracket != 0) {
        buf.FUN_00d61fc0(0, bracket - typeName);
    }

    int i = 0;
    TypeEntry* pEntry = DAT_011b6ab4;
    do {
        if (buf.Object_ForwardCall_00d616e0(pEntry->name)) {
            buf.UpdateFields_00cbbd40();
            return i;
        }
        ++pEntry;
        ++i;
    } while ((int)pEntry < (int)DAT_011b6c4c);

    buf.UpdateFields_00cbbd40();
    return 0;
}

struct B { char pad[0x12]; unsigned short w12; };
struct S {
    unsigned int m0;
    B* m4;
    void SetValueAndPtr(unsigned int a, B* b);
};
// @fnv 0x00d87130
void S::SetValueAndPtr(unsigned int uiValue, B* b) {
m0 = uiValue + b->w12; m4 = b;
}

struct D871A0Buffer {
    void append(const void* p, int a, int b);
};
struct FUN_00d871c0_class {
    FUN_00d871c0_class* Append(FUN_00d871c0_class* a, int b, const void* p);
};
// @fnv 0x00d871c0
FUN_00d871c0_class* FUN_00d871c0_class::Append(FUN_00d871c0_class* apData, int b, const void* p)
{
    ((D871A0Buffer*)this)->append(apData, b, (int)p);
    return this;
}

struct TargetClass {
    void* Append(int a, int b, int c);
};

struct MemberClass {
    int FUN_00d86910();
};

struct FUN_00d87380_Class {
    int unk00;
    MemberClass* unk04;

    TargetClass* CallTargetMethod(TargetClass* target, int arg2);
};

// Calls Append on target with this->unk00, the result of this->unk04->FUN_00d86910(), and arg2, then returns target.
// @fnv 0x00d87380
TargetClass* FUN_00d87380_Class::CallTargetMethod(TargetClass* target, int aiArg) {
    target->Append(this->unk00, this->unk04->FUN_00d86910(), aiArg);
    return target;
}

struct FUN_00d86910_Obj {
    int __thiscall FUN_00d86910();
};

struct FUN_00d873b0_Obj {
    void __thiscall FUN_00d873b0(int a, int b);
};

struct FUN_00d873f0_Holder {
    int unk00;
    FUN_00d86910_Obj* unk04;
    FUN_00d873b0_Obj* __thiscall hkClassMemberAccessor_object(FUN_00d873b0_Obj* a);
};

// Calls unk04's method to get a value, passes unk00 and that value to a's method, and returns a.
// @fnv 0x00d873f0
// src: HAVOK_LIB 0x00d873f0
FUN_00d873b0_Obj* FUN_00d873f0_Holder::hkClassMemberAccessor_object(FUN_00d873b0_Obj* pTarget) {
    int r = unk04->FUN_00d86910();
    pTarget->FUN_00d873b0(unk00, r);
    return pTarget;
}

class hkSetD874 {
public:
    int* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    int hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getIterator() const;
};

// @fnv 0x00d87410
// src: XBOX_PDB 0x00d87410
int hkSetD874::hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getIterator() const
{
    int i;
    for (i = 0; i <= m_iPairCount; i++)
    {
        if (m_kPrimitiveElement[i] != -1)
            break;
    }
    return i;
}

struct FUN_00d87910_cls {
    int m_00;

    FUN_00d87910_cls* hkThread_hkThread();
};

// @fnv 0x00d87910
// src: COMMUNITY 0x00d87910
FUN_00d87910_cls* FUN_00d87910_cls::hkThread_hkThread()
{
    m_00 = 0;
    return this;
}

extern "C" unsigned int (__stdcall *DAT_00fdf1d0)();

// @fnv 0x00d87a40
// src: GUESS 0x00d87a40 (confidence: low)
unsigned __int64 __cdecl Object_ForwardCall_00d87a40()
{
    return DAT_00fdf1d0();
}

void __cdecl hkThread_stopThread();

// @fnv 0x00d87a70
// src: GUESS 0x00d87a70 (confidence: low)
void __cdecl hkThread_stopThread_ForwardCall_00d87a70()
{
    hkThread_stopThread();
}

struct FUN_00d87a80_Stub {
    void* GetSelf_00d87a80(int);
};
// @fnv 0x00d87a80
// src: GUESS 0x00d87a80 (confidence: high)
void* FUN_00d87a80_Stub::GetSelf_00d87a80(int)
{
    return this;
}

// @fnv 0x00d87a90
// src: GUESS 0x00d87a90 (confidence: high)
void __cdecl Runtime_DoNothing_00d87a90()
{
}

extern int DAT_010d3cc0;
// @fnv 0x00d87b90
D85660Object* __cdecl CreateD85660Object()
{
    D85660Object* p = static_cast<D85660Object*>(GetObjectHeap(D85660GetMemoryRouter()).AllocateMemoryBlock(0x1c));
    p->m_usMemSizeAndFlags = 0x1c;
    p->m_sReferenceCount = 1;
    *reinterpret_cast<void**>(p) = &DAT_010d3cc0;
    p->m_iData010 = 0;
    p->m_iData014 = 0;
    p->m_iData018 = 0x80000000;
    p->unk08 = 0;
    p->unk0C = 0;
    return p;
}

class FUN_00d88050 {
public:
    FUN_00d88050();

    bool m_bModifierActive;
    int m_iValue;
    bool m_bValueAt0C;
};

// @fnv 0x00d88050
FUN_00d88050::FUN_00d88050()
{
    m_iValue = 0;
    m_bModifierActive = false;
    m_bValueAt0C = false;
}

// @fnv 0x00d88060
// src: GUESS 0x00d88060 (confidence: high)
void __cdecl Object_DoNothing_00d88060()
{
}

struct AllocIfaceFree : AllocIface
{
    virtual void Free(void* block, unsigned int size);
};

extern void* DAT_012691fc;

// Frees the 60-byte block stored in DAT_012691fc through the allocator from FUN_00c85750, then clears DAT_012691fc.
// @fnv 0x00d88070
void __cdecl FreeGlobalBlock()
{
    void* block = DAT_012691fc;
    if (block)
    {
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        AllocIfaceFree* allocator =
            reinterpret_cast<AllocIfaceFree*>(holder->m_heap);
        allocator->Free(block, 60);
    }
    DAT_012691fc = 0;
}

struct FUN_00d880d0 {
    unsigned char m_kPointB;
    int m_i;
    void M_00d880d0();
};
// @fnv 0x00d880d0
void FUN_00d880d0::M_00d880d0()
{
    ++m_i;
    m_kPointB = 0;
}

// @fnv 0x00d880e0
// src: GUESS 0x00d880e0 (confidence: high)
void __cdecl Object_DoNothing_00d880e0() {
}

struct FUN_00d880f0_Class {
    int unk00;
    int unk04;
    unsigned char unk08;

    void SetUnk08(unsigned char val);
};

// @fnv 0x00d880f0
// src: GUESS 0x00d880f0 (confidence: low)
void FUN_00d880f0_Class::SetUnk08(unsigned char val) {
    unk08 = val;
}

struct DispatchTarget {
    virtual void Event0();
    virtual void Event1();
    virtual void Event2();
    virtual void Event3();
    virtual void Event4();
    virtual void Event5();
    virtual void Event6();
    virtual void Dispatch(int argument);
};
// @fnv 0x00d921e0
void __cdecl InvokeDispatch(void* context, DispatchTarget** target, void* reserved, int argument) {
    (*target)->Dispatch(argument);
}

class hkTargetD922B {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void process(void* a, void* b, void* c, void* d);
};

// Calls process on the target object pointed to by ppkTarget, forwarding a, b, c and d.
// @fnv 0x00d92200
// src: HAVOK_LIB 0x00d92200
void __cdecl hkAgent3Bridge_updateFilter(void* pvContext, hkTargetD922B** ppkTarget, void* a, void* b, void* c, void* pvUnused, void* d)
{
    (*ppkTarget)->process(a, b, c, d);
}

// Agent payload stores a collision-agent pointer; the four-byte hkpAgentEntry stores four command bytes.
struct ChildCollisionAgentPayload {
    void* m_pCollisionAgent;
};

// @fnv 0x00d92230
void __cdecl AddChildAgent2ToCollector(void* pvContext, const ChildCollisionAgentPayload* pkEntry, void* pvUnused, hkStatisticsCollector* pkCollector)
{
    // Slot 3 collects a referenced object; the shared declaration calls this slot beginObject.
    pkCollector->beginObject("ChildAgent2", reinterpret_cast<const hkClass*>(pkEntry->m_pCollisionAgent), 0);
}

class FUN_00d92250_obj {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9(int iValue);
};

struct FUN_00d92250_holder {
    FUN_00d92250_obj* m_object;
};

// @fnv 0x00d92250
void __cdecl CallObjectVirtual(void* pvUnused, FUN_00d92250_holder* pkHolder, int iValue)
{
    pkHolder->m_object->V9(iValue);
}

struct FUN_00d92270_Dispatch
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual int v10(float a, float b, int c) = 0;
};

// Calls virtual method v10 on the object pointed to by a2 with a3, a4 and a5, returning its result.
// @fnv 0x00d92270
int DispatchVirtualCall(int aiUnused, FUN_00d92270_Dispatch** a2, float afArg1, float afArg2, int aiArg3)
{
    return (*a2)->v10(afArg1, afArg2, aiArg3);
}

class hkTargetD92A {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void process(void* pvData);
};

// @fnv 0x00d922a0
// src: HAVOK_LIB 0x00d922a0
void __cdecl hkAgent3Bridge_removePoint(void* pvContext, hkTargetD92A** ppkTarget, void* pvData)
{
    (*ppkTarget)->process(pvData);
}

class hkTargetD922 {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void process(void* pvData);
};

// @fnv 0x00d922c0
// src: HAVOK_LIB 0x00d922c0
void __cdecl hkAgent3Bridge_commitPotential(void* pvContext, hkTargetD922** ppkTarget, void* pvData)
{
    (*ppkTarget)->process(pvData);
}

struct FUN_00d922e0_Iface {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2c();
    virtual void unk30();
    virtual void* unk34(int arg);
};

// @fnv 0x00d922e0
void* __cdecl CallIfaceMethod(int unused, FUN_00d922e0_Iface** p, int arg) {
    return (*p)->unk34(arg);
}

struct FUN_00d92380_obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int a, int b, int c, int d);
};
struct FUN_00d92380_vec {
    int a0;
    int a4;
    int a8;
    int ac;
};
struct FUN_00d92380_holder {
    FUN_00d92380_obj* m0;
    int m4;
    int m8;
    int mc;
    int m10;
};
// Calls the virtual method v6 on h->m0 with v->a0, v->a4, v->ac and arg, then returns the address of h->m10.
// @fnv 0x00d92380
int* __cdecl CallVirtualWithVectorArgs(FUN_00d92380_vec* pVec, int u1, FUN_00d92380_holder* pHolder, int u2, int arg)
{
    pHolder->m0->v6(pVec->a0, pVec->a4, pVec->ac, arg);
    return &pHolder->m10;
}

struct FUN_00d93310_cls {
    int m_00;
    int m_04;
    int m_08;

    FUN_00d93310_cls* hkpFixedSizePhysicsCommandQueue_256_hkpFixedSizePhysicsCommandQueue_256();
};

// @fnv 0x00d93310
// src: HAVOK_LIB 0x00d93310
FUN_00d93310_cls* FUN_00d93310_cls::hkpFixedSizePhysicsCommandQueue_256_hkpFixedSizePhysicsCommandQueue_256()
{
    m_00 = 0x10;
    m_04 = 0;
    m_08 = 0x100;
    return this;
}

extern "C" {
    unsigned __int64 __rdtsc(void);
    void _ReadWriteBarrier(void);
    __declspec(dllimport) void* __stdcall TlsGetValue(unsigned int dwTlsIndex);
    extern unsigned int DAT_0126835c;
    void __cdecl Object_ProcessAndReturnValue_00d89f80(void* p, int a2, int a3, int a4, bool* pb);
}

struct TargetObj {
    int dummy;
};

struct SubObj {
    int unk_000; int unk_004; int unk_008; int unk_00c; int unk_010; int unk_014; int unk_018; int unk_01c;
    int unk_020; int unk_024; int unk_028; int unk_02c; int unk_030; int unk_034; int unk_038; int unk_03c;
    int unk_040; int unk_044; int unk_048; int unk_04c; int unk_050; int unk_054; int unk_058; int unk_05c;
    int unk_060; int unk_064; int unk_068; int unk_06c; int unk_070; int unk_074; int unk_078; int unk_07c;
    int unk_080; int unk_084; int unk_088; int unk_08c; int unk_090; int unk_094; int unk_098; int unk_09c;
    int unk_0a0; int unk_0a4; int unk_0a8; int unk_0ac; int unk_0b0; int unk_0b4; int unk_0b8; int unk_0bc;
    int unk_0c0; int unk_0c4; int unk_0c8; int unk_0cc; int unk_0d0; int unk_0d4; int unk_0d8; int unk_0dc;
    int unk_0e0; int unk_0e4; int unk_0e8; int unk_0ec; int unk_0f0; int unk_0f4; int unk_0f8; int unk_0fc;
    int unk_100; int unk_104; int unk_108; int unk_10c; int unk_110; int unk_114; int unk_118; int unk_11c;
    int unk_120; int unk_124; int unk_128; int unk_12c; int unk_130; int unk_134; int unk_138; int unk_13c;
    int unk_140; int unk_144; int unk_148; int unk_14c; int unk_150; int unk_154; int unk_158; int unk_15c;
    int unk_160; int unk_164; int unk_168; int unk_16c; int unk_170; int unk_174; int unk_178; int unk_17c;
    int unk_180; int unk_184; int unk_188; int unk_18c; int unk_190; int unk_194; int unk_198; int unk_19c;
    int unk_1a0; int unk_1a4; int unk_1a8; int unk_1ac; int unk_1b0; int unk_1b4; int unk_1b8; int unk_1bc;
    int unk_1c0; int unk_1c4; int unk_1c8; int unk_1cc; int unk_1d0; int unk_1d4; int unk_1d8; int unk_1dc;
    TargetObj unk1e0;
};

struct Arg0 {
    SubObj* m_pSub;
};

struct Arg2 {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20;
    int unk24;
    int unk28;
    char unk2c;
};

struct Arg1 {
    void ProcessCallback(Arg2* a1, Arg2* a2, int a3);
};

// Writes profiling markers to the TLS stream, calls FUN_00d89f80 on the sub-object, stores the result flag in a3->unk2c, then calls a2->ProcessCallback(a3, a3, 0).
// @fnv 0x00d94670
void LogIntegrateVelocity(Arg0* a1, Arg1* a2, Arg2* a3) {
    hkMonitorStream* stream = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    char* cur = stream->m_end.m_storage;
    if (cur < stream->m_capacityMinus16.val()) {
        *(const char* volatile*)cur = "LtIntegrate";
        *(const char* volatile*)(cur + 0xc) = "StIntVel";
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        *(unsigned int*)(cur + 4) = t;
        cur += 0x10;
        stream->m_end.m_storage = cur;
    }

    bool b = false;
    Object_ProcessAndReturnValue_00d89f80(&a1->m_pSub->unk1e0, a3->unk28, a3->unk20, a3->unk24, &b);
    a3->unk2c = b;

    hkMonitorStream* stream2 = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    char* cur2 = stream2->m_end.m_storage;
    if (cur2 < stream2->m_capacityMinus16.val()) {
        *(const char* volatile*)cur2 = "lt";
        _ReadWriteBarrier();
        volatile unsigned int t2 = (unsigned int)__rdtsc();
        *(unsigned int*)(cur2 + 4) = t2;
        cur2 += 0xc;
        stream2->m_end.m_storage = cur2;
    }

    a2->ProcessCallback(a3, a3, 0);
}

extern "C" char str_010d4030[];

void __cdecl hkStringBuf_printf(unsigned int* result, char* text, double d0,
                          int value0, double d1, int value1, double d2);

// @fnv 0x00d97640
// src: HAVOK_LIB 0x00d97640
unsigned int __cdecl hkVector4Util_toString3(float* values, unsigned int* result,
                                  signed char value) {
    hkStringBuf_printf(result, str_010d4030, (double)values[0], value,
                 (double)values[1], value, (double)values[2]);
    return *result;
}

void __cdecl hkStringBuf_printf(...);

// @fnv 0x00d97680
int __cdecl FormatVec4(hkVector4* v, int* dst, char acSeparator)
{
    hkStringBuf_printf(dst, "%f%c%f%c%f%c%f", v->x, (int)acSeparator, v->y, (int)acSeparator, v->z, (int)acSeparator, v->w);
    return *dst;
}

struct hkRecordD983 {
    float m_00;
    int m_04;
    int unk08;
    int unk0C;
    int m_10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int m_30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;

    hkRecordD983()
    {
        m_00 = 1.0f;
        m_04 = -1;
        m_30 = 0;
        m_10 = -1;
    }
};

struct FUN_00d98390 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkRecordD983 m_records[4];

    FUN_00d98390();
};

// Default-constructs the four hkRecordD983 entries, each initialising m_00 to 1.0f and m_04, m_10 to -1 and m_30 to 0.
// @fnv 0x00d98390
FUN_00d98390::FUN_00d98390()
{
}

void __cdecl Runtime_ProcessEntries_00d98630(void*, void*, void*, void*);

// Calls FUN_00d98630 with the four arguments and returns a1.
// @fnv 0x00d99540
// src: HAVOK_LIB 0x00d99540
void* __cdecl hkKdTreeUtils_isValidRayBundle(void* a1, void* a2, void* a3, void* a4)
{
    Runtime_ProcessEntries_00d98630(a1, a2, a3, a4);
    return a1;
}

struct FNV_00d99f50_Entry { void* value; void* payload; };
struct FNV_00d99f50_Result {
    unsigned char flag;
    FNV_00d99f50_Result() {}
    ~FNV_00d99f50_Result() {}
};
extern "C" void __cdecl hkKdTreeUtils_castRayIterative(unsigned char* scratch, const FNV_00d99f50_Entry* entry, void* context, void* left, void* right);
// Calls FUN_00d98ca0 for each entry with a payload and returns a result whose flag is set if any call reported a nonzero value.
// @fnv 0x00d99f50
// src: HAVOK_LIB 0x00d99f50
FNV_00d99f50_Result __cdecl hkKdTreeUtils_castRayMultiTree(int count, const FNV_00d99f50_Entry* const* entries, void* context, void* left, void* right)
{
    FNV_00d99f50_Result result;
    result.flag = 0;
    for (int i = 0; i < count; ++i) {
        const FNV_00d99f50_Entry* entry = entries[i];
        if (entry && entry->payload) {
            unsigned char temporary;
            hkKdTreeUtils_castRayIterative(&temporary, entry, context, left, right);
            unsigned char combined;
            if (result.flag || temporary)
                combined = 1;
            else
                combined = 0;
            result.flag = combined;
        }
    }
    return result;
}

struct FUN_00d9a4a0_Param {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

struct FUN_00d9a4a0_Float {
    float unk00;
    float unk04;
};

struct FUN_00d9a4a0_Obj {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00d9a4a0_Float* unk10;

    void __thiscall InvokeCallback(int a1);
};

// @fnv 0x00d9a4a0
// src: GUESS 0x00d9a4a0 (confidence: low)
float __fastcall Object_ProcessAndReturnValue_00d9a4a0(
    FUN_00d9a4a0_Obj* self,
    int unused,
    FUN_00d9a4a0_Param* param) {
    self->InvokeCallback(param->unk20);
    return self->unk10->unk04;
}

struct IdxStand_ {
    char* m_iWordAt00;
    void* ComputeValue_00d9a4c0(int idx);
};
// @fnv 0x00d9a4c0
// src: GUESS 0x00d9a4c0 (confidence: low)
void* IdxStand_::ComputeValue_00d9a4c0(int idx)
{
    return m_iWordAt00 + idx * 48;
}

struct FUN_00d9a4d0_Class {
    int unk00;

    int __thiscall GetEntryOffset(unsigned short value);
};

// @fnv 0x00d9a4d0
int __thiscall FUN_00d9a4d0_Class::GetEntryOffset(unsigned short value) {
    return unk00 + value * 0x14;
}

struct FnvCpu_FUN_00d9f6b0_CpuInterface {
    virtual void Invoke(int value);
};
// @fnv 0x00d9f6b0
// src: GUESS 0x00d9f6b0 (confidence: low)
void __cdecl Runtime_ForwardCall_00d9f6b0(FnvCpu_FUN_00d9f6b0_CpuInterface* object)
{
    object->Invoke(0);
}

extern char DAT_0102e388;
struct FUN_00d9fb30_Stub {
    void SetVtableAndProcessState_00d9fb30();
};
// @fnv 0x00d9fb30
// src: GUESS 0x00d9fb30 (confidence: low)
void FUN_00d9fb30_Stub::SetVtableAndProcessState_00d9fb30()
{
    *(int*)this = (int)&DAT_0102e388;
}

// @fnv 0x00d9fb40
// src: GUESS 0x00d9fb40 (confidence: low)
void __stdcall Object_UpdateFields_00d9fb40(unsigned char* output, int unused1)
{
    *output = 1;
}

// @fnv 0x00d9fca0
// src: COMMUNITY 0x00d9fca0
void __stdcall nullsub_68(int) {
}

// @fnv 0x00d9fcb0
// src: COMMUNITY 0x00d9fcb0
void __stdcall nullsub_69(int, int, int) {
}

// @fnv 0x00d9fcc0
// src: COMMUNITY 0x00d9fcc0
void __stdcall nullsub_70(int) {
}

// @fnv 0x00d9fcd0
// src: COMMUNITY 0x00d9fcd0
void __stdcall nullsub_71(int) {
}

// @fnv 0x00d9fce0
// src: COMMUNITY 0x00d9fce0
void __stdcall nullsub_72(int) {
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

extern unsigned int DAT_0126835c;
typedef void* (__stdcall* D85TlsFn)(unsigned long);
extern D85TlsFn DAT_00fdf044;

struct D85Ctn {
    void** entries;
    unsigned short count;
};

struct D85A0 {
    int unk00;
    unsigned int unk04;
};

struct D85Msg {
    D85A0* p;
};

// src: GUESS 0x00d85d40 (confidence: low)
static __declspec(noinline) D85Ctn* Object_ProcessEntries_00d85d40(D85Ctn* c) {
    for (int i = c->count - 1; i >= 0; --i) {
        if (c->entries[i] != 0) continue;
        c->count -= 1;
        unsigned int cnt = c->count;
        if (i < (int)cnt) {
            for (int j = i; j < (int)cnt; ++j)
                c->entries[j] = c->entries[j + 1];
        }
    }
    return c;
}

// @fnv 0x00d85fa0
// src: HAVOK_LIB 0x00d85fa0
void __cdecl hkpConstraintCallbackUtil_fireConstraintBroken(D85Msg a) {
    volatile unsigned int stamps[2];
    D85Ctn* ctn = (D85Ctn*)(a.p->unk04 + 0x20);
    int i = ctn->count - 1;
    if (i >= 0) {
        D85TlsFn tls = DAT_00fdf044;
        do {
            if (ctn->entries[i] != 0) {
                hkMonitorStream* prof = (hkMonitorStream*)tls(DAT_0126835c);
                hkTimerCommand_blk_00d80000_o2* ev = reinterpret_cast<hkTimerCommand_blk_00d80000_o2*>(prof->m_end.val());
                if (reinterpret_cast<char*>(ev) < prof->m_capacityMinus16.val()) {
                    ev->m_pCommandName = "TtconBrokenCb";
                    _ReadWriteBarrier();
                    stamps[0] = (unsigned int)__rdtsc();
                    ev->m_ticks = stamps[0];
                    prof->m_end.m_storage = reinterpret_cast<char*>(ev + 1);
                }
                // The shared c14 slot has no event parameter declaration yet.
                typedef void (__thiscall* BrokenCallback)(hkpConstraintListener*, D85Msg);
                hkpConstraintListener* listener = static_cast<hkpConstraintListener*>(ctn->entries[i]);
                (*reinterpret_cast<BrokenCallback**>(listener))[5](listener, a);
                hkMonitorStream* p2 = (hkMonitorStream*)tls(DAT_0126835c);
                hkTimerCommand_blk_00d80000_o2* e2 = reinterpret_cast<hkTimerCommand_blk_00d80000_o2*>(p2->m_end.val());
                if (reinterpret_cast<char*>(e2) < p2->m_capacityMinus16.val()) {
                    e2->m_pCommandName = "Et";
                    _ReadWriteBarrier();
                    stamps[1] = (unsigned int)__rdtsc();
                    e2->m_ticks = stamps[1];
                    p2->m_end.m_storage = reinterpret_cast<char*>(e2 + 1);
                }
            }
        } while (--i >= 0);
    }
    Object_ProcessEntries_00d85d40(ctn);
}

template <class T>
inline void NiStreamSaveBinaryD861(NiBinaryStream& kStream, const T& value)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryWrite(&value, sizeof(T), &uiSize, 1);
}

// Serialized fields occupy 0x0c and 0x10; shared Data ends at 0x10 and has no second field.
struct SerializedUnsignedPairRecord {
    int unk00[3];
    unsigned int m_0c;
    unsigned int m_10;
};

// Writes the m_0c and m_10 fields of pkData to the stream's backing binary stream via NiStreamSaveBinaryD861.
// @fnv 0x00d86100
// src: XBOX_PDB 0x00d86100
void __cdecl bhkLimitedForceConstraintMotor_LoadBinary(NiStream& kStream, SerializedUnsignedPairRecord* pkData)
{
    NiStreamSaveBinaryD861(**reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(&kStream) + 0x24c), pkData->m_0c);
    NiStreamSaveBinaryD861(**reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(&kStream) + 0x24c), pkData->m_10);
}

template <class T>
inline void NiStreamLoadBinaryD8616(NiBinaryStream& kStream, T& value)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(&value, sizeof(T), &uiSize, 1);
}

// Reads two unsigned int fields from the stream into pkData->m_0c and pkData->m_10.
// @fnv 0x00d86160
// src: XBOX_PDB 0x00d86160
void __cdecl bhkLimitedForceConstraintMotor_SaveBinary(NiStream& kStream, SerializedUnsignedPairRecord* pkData)
{
    NiStreamLoadBinaryD8616(**reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(&kStream) + 0x250), pkData->m_0c);
    NiStreamLoadBinaryD8616(**reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(&kStream) + 0x250), pkData->m_10);
}

extern int DAT_010d3838;
struct FUN_00d86220_Class {
    unsigned int m_vptr;
    unsigned short m_word04;
    unsigned short m_word06;
    volatile unsigned char m_byte08;
    volatile float m_float0C;
    float m_float10;
    float m_float14;
    float m_float18;
    FUN_00d86220_Class();
};
// Initializes the object's vtable pointer, sets m_word06 to 1, m_byte08 to 3, m_float0C to -1000000.0f, m_float10 to 1000000.0f, and m_float14/m_float18 to 0.0f.
// @fnv 0x00d86220
FUN_00d86220_Class::FUN_00d86220_Class()
{
    m_word06 = 1;
    m_byte08 = 0;
    m_float0C = -1000000.0f;
    m_float10 = 1000000.0f;
    m_vptr = (unsigned int)&DAT_010d3838;
    m_byte08 = 3;
    m_float14 = 0.0f;
    m_float18 = 0.0f;
}

extern __declspec(thread) unsigned int tlsArr[0xb0];

inline AutoMemContext::AutoMemContext()
{
    m_eMemoryContext = static_cast<MEM_CONTEXT>(tlsArr[0xaf]);
    tlsArr[0xaf] = 0x10;
}

inline AutoMemContext::~AutoMemContext()
{
    tlsArr[0xaf] = m_eMemoryContext;
}

void __cdecl Object_UpdateFields_00c9eae0(void* p);

struct FUN_00dee750 {
    void* m_vptr;
    unsigned short m_usMemorySizeAndFlags;
    short m_sReferenceCount;
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

    static void* operator new(unsigned int sz)
    {
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        AllocIface* alloc = reinterpret_cast<AllocIface*>(holder->m_heap);
        void* p = alloc->Alloc(sz);
        ((FUN_00dee750*)p)->m_usMemorySizeAndFlags = (unsigned short)sz;
        return p;
    }
    static void operator delete(void* p) { Object_UpdateFields_00c9eae0(p); }

    FUN_00dee750();
};

struct FUN_00d86470_cls {
    int unk00;
    FUN_00dee750* m_04;

    unsigned int hkPointToPathConstraintCinfo_CreateData();
};

// Inside an AutoMemContext scope, allocates a FUN_00dee750 into m_04 if it is null, and returns 0xb0.
// @fnv 0x00d86470
// src: XBOX_PDB 0x00d86470
unsigned int FUN_00d86470_cls::hkPointToPathConstraintCinfo_CreateData()
{
    AutoMemContext ctx;
    if (m_04 == 0) {
        m_04 = new FUN_00dee750;
    }
    return 0xb0;
}

// Sets or clears the bits in the last word of the bit field that extend beyond m_iNumBits based on value.
// @fnv 0x00d867e0
void hkBitField::fillUnusedBits(int value) throw()
{
    int lastWordIndex = (m_iNumBits - 1) >> 5;
    unsigned int* lastWord = &m_auiBitFieldWords.m_data[lastWordIndex];
    int numBitsInLastWord = m_iNumBits - (lastWordIndex << 5);
    if (numBitsInLastWord < 32) {
        unsigned int mask = 0xffffffff << numBitsInLastWord;
        if (!value) {
            *lastWord &= ~mask;
        } else {
            *lastWord |= mask;
        }
    }
}

struct Cls00d86950 {
    int unk00;
    int unk04;
    int unk08;
    int GetUnk08();
};

// @fnv 0x00d86950
int Cls00d86950::GetUnk08() {
    return unk08;
}

struct S_00d87a60 {
    int m_uiFilterValue;
    int GetValue();
};

// @fnv 0x00d87a60
int S_00d87a60::GetValue() {
    return m_uiFilterValue;
}

extern void* DAT_012691fc;
// @fnv 0x00d880a0
// src: GUESS 0x00d880a0 (confidence: low)
void* __cdecl Object_GetDAT_012691fc_00d880a0()
{
    return DAT_012691fc;
}

class FUN_00d88100_Class {
public:
    bool m_bTriggered;
    char unk01;
    char unk02;
    char unk03;
    int m_iArrayLength;
    bool m_bEnableState;
    bool m_abFlags[3];

    bool hkMemoryExceptionTestingUtil_isMemoryAvailableImpl(int iIndex);
};

// Returns false if triggered while enabled, or after setting m_abFlags[iIndex] and m_bTriggered (enabled, flag unset, count >50, multiple of 3); else true.
// @fnv 0x00d88100
// src: HAVOK_LIB 0x00d88100
bool FUN_00d88100_Class::hkMemoryExceptionTestingUtil_isMemoryAvailableImpl(int iIndex)
{
    if (m_bTriggered && m_bEnableState)
        return false;
    if (m_iArrayLength > 50 && m_iArrayLength % 3 == 0 && m_bEnableState && !m_abFlags[iIndex]) {
        m_abFlags[iIndex] = true;
        m_bTriggered = true;
        return false;
    }
    return true;
}

namespace fnv_00d88150 {

inline hkMemoryAllocator& GetMonitorHeap(hkMemoryRouter& holder)
{
    return *reinterpret_cast<hkMemoryAllocator*>(holder.m_heap);
}

namespace hkRouterD881 {
    extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();
}

class FUN_00d88050 {
public:
    char unk00[0x3c];

    FUN_00d88050() throw();
    ~FUN_00d88050() throw() {}

    static void* operator new(unsigned int nbytes) { return GetMonitorHeap(hkRouterD881::hkMemoryRouter_getInstance()).blockAlloc(0x3c); }
    static void operator delete(void* p) { GetMonitorHeap(hkRouterD881::hkMemoryRouter_getInstance()).blockFree(p, 0x3c); }
};

namespace hkGlobalsD881 {
    extern FUN_00d88050* DAT_012691fc;
}
using hkGlobalsD881::DAT_012691fc;

// Deletes the global FUN_00d88050 instance and replaces it with a newly allocated one.
// @fnv 0x00d88150
// src: HAVOK_LIB 0x00d88150
void __cdecl hkMemoryExceptionTestingUtil_create()
{
    delete DAT_012691fc;
    DAT_012691fc = new FUN_00d88050;
}
}  // namespace fnv_00d88150

struct S00d881a0_Leaf {
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
    int m78;
};
struct S00d881a0_Mid {
    int unk00;
    int unk04;
    S00d881a0_Leaf* m08;
};
struct S00d881a0_Obj {
    S00d881a0_Mid* m00;
};
int __cdecl hkRigidMotionUtilApplyAccumulators(void* a0, void* a1, void* a2, void* a3, void* a4, int a5);
void __cdecl hkpEntityAabbUtil_entityBatchRecalcAabb(int a0, void* a1, void* a2);

// Calls FUN_00d29bf0 with eaxv + 0x80 and 0xe0, then FUN_00d1a330 with esi->m00->m08->m78, esi and edi, and returns the first call's result.
// @fnv 0x00d881a0
// src: HAVOK_LIB 0x00d881a0
static __declspec(noinline) int hkConstraintSolverSetup_integrate2(void* p, void* ecxv, char* eaxv, S00d881a0_Obj* esi, void* edi)
{
    int r = hkRigidMotionUtilApplyAccumulators(p, ecxv, eaxv + 0x80, esi, edi, 0xe0);
    hkpEntityAabbUtil_entityBatchRecalcAabb(esi->m00->m08->m78, esi, edi);
    return r;
}

int S00d881a0_Wrap(void* p)
{
    return hkConstraintSolverSetup_integrate2(p, 0, 0, 0, 0);
}

static unsigned char* S00d96870_outp;

// Fills the block at out+0x10 from src and self fields, then sets *self from self+0x6c, clears *out, and sets out[0x12] to 1.
// @fnv 0x00d96870
// src: HAVOK_LIB 0x00d96870
static __declspec(noinline) void spawnBuildJacobiansJobs(unsigned char* self, int* src, unsigned char* out)
{
    unsigned char* dst = out + 0x10;
    if (dst) {
        int v68 = *(int*)(self + 0x68);
        dst[0] = 4;
        dst[1] = 0;
        dst[2] = 1;
        _ReadWriteBarrier();
        short w = 0x30;
        *(short*)(dst + 4) = w;
        w = -1;
        *(short*)(dst + 6) = w;
        *(unsigned short*)(dst + 0x10) = *(unsigned short*)((unsigned char*)src + 0x10);
        *(int*)(dst + 0x14) = *(int*)((unsigned char*)src + 0x14);
        *(int*)(dst + 0x18) = *(int*)((unsigned char*)src + 0x18);
        *(int*)(dst + 0x1c) = *(int*)((unsigned char*)src + 0x1c);
        *(int*)(dst + 0x24) = *(int*)(self + 0x4c);
        unsigned char flag = *(unsigned char*)(self + 0x58);
        *(int*)(dst + 0x20) = v68;
        *(unsigned char*)(dst + 0x28) = flag;
    }
    *(int*)self = *(int*)(self + 0x6c);
    *(int*)out = 0;
    *(unsigned char*)(out + 0x12) = 1;
}

void __fastcall S00d96870_Entry(unsigned char* self, int* src)
{
    spawnBuildJacobiansJobs(self, src, S00d96870_outp);
}

extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_load_ps(const float*);

struct D99FC0Quad { int a; int b; int c; int d; };

struct D99FC0Object {
    void* unk00;
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
    D99FC0Quad q30;
    LocalM128 v40;
};

void __cdecl IntersectTree(int a1, int a2, int a3, float* a4, int* a5,
                          int a6, int a7, float a8, float a9, float a10, int a11);

// Computes the difference between v40 and q30, then passes it to IntersectTree along with obj->unk1C and the input parameters.
// @fnv 0x00d99fc0
void __cdecl ComputeAndDispatchDelta(D99FC0Object* obj, int a2, int a3, float a4,
                          float a5, float a6, int a7)
{
    D99FC0Quad values;
    LocalM128 delta;

    int p = reinterpret_cast<int>(obj->unk00);
    values = obj->q30;
    delta = _mm_sub_ps(obj->v40, *reinterpret_cast<LocalM128*>(&obj->q30));

    IntersectTree(
        p,
        p,
        obj->unk1C,
        reinterpret_cast<float*>(&delta),
        &values.a,
        a2, a3, a4, a5, a6, a7);
}

struct FUN_00d9a410_Target {
    virtual void v00();
    virtual char* v01(char* buffer, int* a, int* b);
};

struct FUN_00d9a410_Object {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

typedef void (__cdecl *FUN_00d9a410_Callback)(int*, int*, void*, int, int);

struct FUN_00d9a410_Entry {
    FUN_00d9a410_Callback fn;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

struct FUN_00d9a410_Stub {
    int unk00;
    int unk04;
    int unk08;
    FUN_00d9a410_Target* unk0c;
    int unk10;
    int unk14;
    int* unk18;
    int unk1c;
    unsigned char* unk20;

    void __thiscall InvokeCallback(int* param);
};

// If target->v01 returns nonzero, looks up an entry in the unk20 table and calls its function with unk18, param, &unk20, unk10 and unk14.
// @fnv 0x00d9a410
void FUN_00d9a410_Stub::InvokeCallback(int* param)
{
    FUN_00d9a410_Object* object = (FUN_00d9a410_Object*)param[0];

    if (object != 0 && unk18 != param) {
        char buffer;
        FUN_00d9a410_Target* target = unk0c;
        char* result = target->v01(&buffer, unk18, param);

        if (*result != 0) {
            unsigned char* base = unk20;
            unsigned int index = ((unsigned int)unk1c + 13) << 5;
            index += (unsigned int)object->unk0c;

            unsigned char slot = base[index];
            FUN_00d9a410_Entry* entry =
                (FUN_00d9a410_Entry*)(base + 0x9ac + slot * 20);

            entry->fn(unk18, param, &unk20, unk10, unk14);
        }
    }
}

struct ArgD9A4 {
    int unk00, unk04, unk08, unk0C;
};

struct InnerD9A4 {
    int unk00;
    float m_fValue;
};

class PrimaryD9A4 {
public:
    virtual ~PrimaryD9A4();
};

class SecondaryD9A4 {
public:
    virtual float ProcessAndReturnValue_00d9a480(ArgD9A4* pkArg) = 0;
};

class ObjD9A4 : public PrimaryD9A4, public SecondaryD9A4 {
public:
    int unk08;
    int unk0C;
    InnerD9A4* m_pkInner;

    void InvokeCallback(int iValue);
    virtual float ProcessAndReturnValue_00d9a480(ArgD9A4* pkArg);
};

// @fnv 0x00d9a480
// src: GUESS 0x00d9a480 (confidence: low)
float ObjD9A4::ProcessAndReturnValue_00d9a480(ArgD9A4* pkArg)
{
    InvokeCallback(pkArg->unk0C);
    return m_pkInner->m_fValue;
}

struct __declspec(align(16)) FUN_00d9a4e0_Obj {
    LocalM128 unk00;
    LocalM128 unk10;
    int unk20;
    unsigned short unk24;
    unsigned short unk26;
    FUN_00d9a4e0_Obj* CopyFrom(const FUN_00d9a4e0_Obj* o);
};

// Copies all fields from the source object into this object and returns a pointer to this.
// @fnv 0x00d9a4e0
FUN_00d9a4e0_Obj* FUN_00d9a4e0_Obj::CopyFrom(const FUN_00d9a4e0_Obj* apSource)
{
    unk00 = apSource->unk00;
    unk10 = apSource->unk10;
    unk20 = apSource->unk20;
    unk20 = apSource->unk20;
    unk24 = apSource->unk24;
    unk26 = apSource->unk26;
    return this;
}

namespace sd84c50 {

class Shape {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual unsigned int GetType() const;
};

struct BoolResult {
    bool m_bValue;

    BoolResult(bool bValue) : m_bValue(bValue) {}
};

// Returns true if the shape's GetType() is one of 0, 1, 2, 6, 7, 8, 9, 12, 13, 14 or 15, otherwise false.
// @fnv 0x00d84c50
// src: HAVOK_LIB 0x00d84c50
BoolResult hkpConstraintPivotsUtil_constraintSupportsPivotGetSet(const Shape* pkShape)
{
    switch (pkShape->GetType())
    {
    case 0:
    case 1:
    case 2:
    case 6:
    case 7:
    case 8:
    case 9:
    case 12:
    case 13:
    case 14:
    case 15:
        return BoolResult(true);
    default:
        return BoolResult(false);
    }
}

}

extern char DAT_01267e30;

class ShapeD84D {
public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1C();
    virtual int getType();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    ShapeD84D* m_pkChild;

    ShapeD84D* GetFieldC();
};

// Returns a pointer to shape data based on the shape type, following child shapes for types 12 and 13.
// @fnv 0x00d84d30
void* __cdecl GetShapeData(ShapeD84D* pkShape)
{
    for (unsigned int t = pkShape->getType(); t <= 15; t = pkShape->getType()) {
        switch (t) {
        case 0:
            return (char*)pkShape + 0x30;
        case 1:
            return (char*)pkShape + 0x90;
        case 2:
            return (char*)pkShape + 0x90;
        case 3:
            return &DAT_01267e30;
        case 4:
            return &DAT_01267e30;
        case 5:
            return &DAT_01267e30;
        case 6:
            return (char*)pkShape + 0x90;
        case 7:
            return (char*)pkShape + 0x90;
        case 8:
            return (char*)pkShape + 0x30;
        case 9:
            return (char*)pkShape + 0x90;
        case 10:
            return &DAT_01267e30;
        case 11:
            return &DAT_01267e30;
        case 12:
            pkShape = pkShape->m_pkChild;
            break;
        case 13:
            pkShape = pkShape->GetFieldC();
            break;
        case 14:
            return (char*)pkShape + 0x90;
        case 15:
            return (char*)pkShape + 0x30;
        }
    }
    return &DAT_01267e30;
}

// pivot vector lives first in each 0x40-byte atom
struct PivotAtom {
    LocalM128 m_kPivotVector;
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
};

// view of the derived-class atom chain at data+0x50
struct AtomChain {
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
    PivotAtom m_kBridgeAtoms[2];
};

// hkpConstraintData stand-in (base class stays 4-aligned)
struct PivotCData {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual int v08();

    PivotCData* hkpMalleableConstraintData_getWrappedConstraintData();

    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    PivotCData* m_wrapped;
};

// Walks the PivotCData chain to the leaf and stores the pivot __m128 value into the bridge atom or raw slot at pivotIndex.
// @fnv 0x00d84dc0
void __cdecl SetPivotAtom(PivotCData* data, const LocalM128* pivot, int pivotIndex)
{
    for (;;) {
        switch (data->v08()) {
        case 12:
            data = data->m_wrapped;
            continue;
        case 13:
            data = data->hkpMalleableConstraintData_getWrappedConstraintData();
            continue;
        case 1:
            ((AtomChain*)data)->m_kBridgeAtoms[pivotIndex].m_kPivotVector = *pivot;
            return;
        case 2:
            ((AtomChain*)data)->m_kBridgeAtoms[pivotIndex].m_kPivotVector = *pivot;
            return;
        case 6:
            ((AtomChain*)data)->m_kBridgeAtoms[pivotIndex].m_kPivotVector = *pivot;
            return;
        case 7:
            ((AtomChain*)data)->m_kBridgeAtoms[pivotIndex].m_kPivotVector = *pivot;
            return;
        case 9:
            ((AtomChain*)data)->m_kBridgeAtoms[pivotIndex].m_kPivotVector = *pivot;
            return;
        case 14:
            ((AtomChain*)data)->m_kBridgeAtoms[pivotIndex].m_kPivotVector = *pivot;
            return;
        case 15:
            ((LocalM128*)data)[pivotIndex + 2] = *pivot;
            return;
        case 0:
            ((LocalM128*)data)[pivotIndex + 2] = *pivot;
            return;
        case 8:
            ((LocalM128*)data)[pivotIndex + 2] = *pivot;
            return;
        default:
            return;
        }
    }
}

extern unsigned int DAT_0126835c;
typedef void* (__stdcall* D90TlsFn)(unsigned long);
extern D90TlsFn DAT_00fdf044;

struct D90Ctn {
    void** entries;
    unsigned short count;
};

// src: GUESS 0x00d85d40 (confidence: low)
static __declspec(noinline) D90Ctn* Object_ProcessEntries_00d85d40(D90Ctn* c) {
    for (int i = c->count - 1; i >= 0; --i) {
        if (c->entries[i] != 0) continue;
        c->count -= 1;
        unsigned int cnt = c->count;
        if (i < (int)cnt) {
            for (int j = i; j < (int)cnt; ++j)
                c->entries[j] = c->entries[j + 1];
        }
    }
    return c;
}

// Iterates the owner's listener array in reverse, records a TtconAddCb/Et profiling event around each v01 call, then compacts the array.
// @fnv 0x00d85d90
// src: HAVOK_LIB 0x00d85d90
D90Ctn* __cdecl hkpConstraintCallbackUtil_fireConstraintAdded(hkpConstraintInstance* pOwner) {
    volatile unsigned int ticks[2];
    D90Ctn* ctn = reinterpret_cast<D90Ctn*>(&pOwner->m_kListeners);
    int i = ctn->count - 1;
    if (i >= 0) {
        D90TlsFn tls = DAT_00fdf044;
        do {
            if (ctn->entries[i] != 0) {
                hkMonitorStream* prof = (hkMonitorStream*)tls(DAT_0126835c);
                hkTimerCommand_blk_00d80000_o2* ev = reinterpret_cast<hkTimerCommand_blk_00d80000_o2*>(prof->m_end.val());
                if (reinterpret_cast<char*>(ev) < prof->m_capacityMinus16.val()) {
                    ev->m_pCommandName = "TtconAddCb";
                    _ReadWriteBarrier();
                    ticks[0] = (unsigned int)__rdtsc();
                    ev->m_ticks = ticks[0];
                    prof->m_end.m_storage = reinterpret_cast<char*>(ev + 1);
                }
                static_cast<hkpConstraintListener*>(ctn->entries[i])->ConstraintAddedCallback(pOwner);
                hkMonitorStream* p2 = (hkMonitorStream*)tls(DAT_0126835c);
                hkTimerCommand_blk_00d80000_o2* e2 = reinterpret_cast<hkTimerCommand_blk_00d80000_o2*>(p2->m_end.val());
                if (reinterpret_cast<char*>(e2) < p2->m_capacityMinus16.val()) {
                    e2->m_pCommandName = "Et";
                    _ReadWriteBarrier();
                    ticks[1] = (unsigned int)__rdtsc();
                    e2->m_ticks = ticks[1];
                    p2->m_end.m_storage = reinterpret_cast<char*>(e2 + 1);
                }
            }
        } while (--i >= 0);
    }
    return Object_ProcessEntries_00d85d40(ctn);
}

static __forceinline void hkTimer(const char* name, volatile unsigned int& t)
{
    hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (s->m_end.m_storage < s->m_capacityMinus16.val()) {
        hkTimerCommand_blk_00d80000_o2* c = (hkTimerCommand_blk_00d80000_o2*)s->m_end.m_storage;
        c->m_pCommandName = name;
        _ReadWriteBarrier();
        t = (unsigned int)__rdtsc();
        c->m_ticks = t;
        s->m_end.m_storage = (char*)(c + 1);
    }
}

struct ListenerArray;
static void Object_ProcessEntries_00d85d40(ListenerArray* array);

// Invokes ConstraintRemovedCallback on each non-null listener in the constraint's listener array, then removes null entries.
// @fnv 0x00d85e40
void __cdecl NotifyConstraintRemoved(hkpConstraintInstance* constraint)
{
    hkpConstraintInstanceSmallArraySerializeOverrideType& listen = constraint->m_kListeners;
    for (int i = listen.m_iElementCount - 1; i >= 0; i--) {
        if (static_cast<hkpConstraintListener**>(listen.m_data)[i] != 0) {
            volatile unsigned int ticks[2];
            hkTimer("TtconRemCb", ticks[0]);
            static_cast<hkpConstraintListener**>(listen.m_data)[i]->ConstraintRemovedCallback(constraint);
            hkTimer("Et", ticks[1]);
        }
    }
    Object_ProcessEntries_00d85d40(reinterpret_cast<ListenerArray*>(&listen));
}

template <typename T>
__forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& kAlloc, int n)
{
    const int iCap = getCapacity();
    if (iCap < n) {
        int iCap2 = 2 * iCap;
        int iNewCap = (n < iCap2) ? iCap2 : n;
        hkArrayUtil::_reserve(kAlloc, this, iNewCap, sizeof(T));
    }
}

template <>
__forceinline void hkArray<unsigned int>::setSize(int n, const unsigned int& fill)
{
    hkMemoryRouter* h = hkMemoryRouter_getInstance();
    hkMemoryAllocator* a = reinterpret_cast<hkMemoryAllocator*>(h->m_heap);
    GrowArrayCapacity(*a, n);
    int i = n - m_iElementCount;
    unsigned int* p = m_data + m_iElementCount;
    while (i-- > 0)
        *p++ = fill;
    m_iElementCount = n;
}

// @fnv 0x00d86820
void hkBitField::setSize(int iNumBits, int iInitialValue)
{
    if (m_iNumBits > 0 && m_iNumBits < iNumBits)
        fillUnusedBits(iInitialValue);
    m_auiBitFieldWords.setSize((iNumBits + 31) >> 5, (iInitialValue ? ~0u : 0u));
    m_iNumBits = iNumBits;
}

extern const char DAT_010d3aa0[];
extern const char DAT_010d3a90[];

int __cdecl j_strncmp(const char*, const char*, int) throw();
int __cdecl hkString_strLen(const char*) throw();
const char* __cdecl hkString_strChr(const char*, int) throw();
int __cdecl CallWithZeroMiddleArg(const char*, int) throw();
int __cdecl GetTypeCode(const char*) throw();

struct HkTempAllocator {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void ReturnMemory(void*, int) throw();
};

struct HkBytes16 {
    int a;
    int b;
    int c;
    int d;
};
struct HkBytes64 {
    HkBytes16 a;
    HkBytes16 b;
    HkBytes16 c;
    HkBytes16 d;
};
struct HkBytes128 {
    HkBytes64 a;
    HkBytes64 b;
};
struct HkInplaceChars {
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    HkBytes128 m_kStorage;
};

struct FUN_00d61b10 {
    HkInplaceChars m_kStringBuffer;

    FUN_00d61b10(const char*, int) throw();
    ~FUN_00d61b10() throw() {
        hkMemoryRouter* router = hkMemoryRouter_getInstance();
        int cap = m_kStringBuffer.m_iCapacityState;
        HkTempAllocator* allocator = reinterpret_cast<HkTempAllocator*>(router->m_temp);
        m_kStringBuffer.m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
            allocator->ReturnMemory(m_kStringBuffer.m_data, cap & 0x3fffffff);
        m_kStringBuffer.m_iCapacityState = int(0x80000000u);
        m_kStringBuffer.m_data = 0;
    }
};

// Parses a type-code string by matching known prefixes or extracting a bracketed substring, then returns its type code.
// @fnv 0x00d86d70
int __cdecl GetTypeCodeFromString(const char* name) throw()
{
    if (j_strncmp(name, DAT_010d3aa0, 8) == 0) {
        name += 8;
        FUN_00d61b10 inner(name, hkString_strLen(name) - 1);
        return GetTypeCode(inner.m_kStringBuffer.m_data);
    }
    if (j_strncmp(name, DAT_010d3a90, 14) == 0) {
        name += 14;
        FUN_00d61b10 inner(name, hkString_strLen(name) - 1);
        return GetTypeCode(inner.m_kStringBuffer.m_data);
    }
    const char* openBracket = hkString_strChr(name, '[');
    if (openBracket) {
        int length = int(hkString_strChr(name, ']') - openBracket) - 1;
        FUN_00d61b10 inner(openBracket + 1, length);
        return CallWithZeroMiddleArg(inner.m_kStringBuffer.m_data, 0);
    }
    return 0;
}

struct FUN_00d87180_cls : S {
    FUN_00d87180_cls* hkClassMemberAccessor_hkClassMemberAccessor(unsigned int a, B* b);
};

// @fnv 0x00d87180
// src: HAVOK_LIB 0x00d87180
FUN_00d87180_cls* FUN_00d87180_cls::hkClassMemberAccessor_hkClassMemberAccessor(unsigned int auiValue, B* apPtr)
{
    void (S::*call)(unsigned int, B*) = &S::SetValueAndPtr;
    (static_cast<S*>(this)->*call)(auiValue, apPtr);
    return this;
}

class OwnerD87A {
public:
    unsigned __int64 GetCurrentValue() const;
    int unk00;
    int unk04;
    unsigned __int64 m_uiCurrentValue;
};

// @fnv 0x00d87a50
unsigned __int64 OwnerD87A::GetCurrentValue() const
{
    return m_uiCurrentValue;
}

__declspec(noinline) extern "C" void* __cdecl FUN_00ec61c0(void* destination, int value, unsigned int size)
{
    unsigned char* p = (unsigned char*)destination;
    for (unsigned int i = 0; i < size; ++i)
        p[i] = (unsigned char)value;
    return destination;
}
struct MonitorBuffer {
    void* m_ppVirtualMethodTable;
    int m_uiItemCount;
    char m_bSlotEnabled;
    char m_buffer[50];
    void hkMemoryExceptionTestingUtil_startNewDemoImpl();
};
// @fnv 0x00d880b0
// src: HAVOK_LIB 0x00d880b0
void MonitorBuffer::hkMemoryExceptionTestingUtil_startNewDemoImpl()
{
    m_uiItemCount = 0;
    FUN_00ec61c0(m_buffer, 0, sizeof(m_buffer));
}

static inline char* alignDownD881(char* p) { return (char*)((unsigned int)p & ~15); }

// Stores step, solver, and query pointers, then carves the aligned buffer into velocity accumulators and three buffer states with computed ray start/end offsets.
// @fnv 0x00d881d0
void __cdecl InitializeConstraintSolverResources(hkStepInfo* pkStepInfo, hkpSolverInfo* pkSolverInfo, hkpConstraintQueryIn* pkQueryIn, char* pcBuffer, int iBufferSize, hkpConstraintSolverResources* pkOut)
{
    pkOut->m_pStepInfo = pkStepInfo;
    pkOut->m_pSolverInfo = pkSolverInfo;
    pkOut->m_pConstraintQueryIn = pkQueryIn;

    iBufferSize -= iBufferSize % 16;
    const float fFactorA = -0.6f;
    const float fFactorB = -(1.0f + fFactorA);

    char* p = (char*)(((unsigned int)pcBuffer + 15) & ~15);
    pkOut->m_pVelocityAccumulatorA = reinterpret_cast<hkpVelocityAccumulator*>(p);
    p = alignDownD881(p + iBufferSize * 10 / 64);
    pkOut->m_pVelocityAccumulatorB = reinterpret_cast<hkpVelocityAccumulator*>(p);
    pkOut->m_pBufferA = p;
    p = alignDownD881(p + iBufferSize * 4 / 64);
    pkOut->m_akBufferStates[0].m_pRayStart = p;
    pkOut->m_pBufferB = p;

    float fSize = (float)(iBufferSize * 40);
    p = alignDownD881(p - (unsigned int)(fSize * fFactorA / 64.0));
    pkOut->m_akBufferStates[1].m_pRayStart = p;
    pkOut->m_akBufferStates[0].m_kRayEnd = p;

    p = alignDownD881(p - (unsigned int)(fSize * fFactorB / 64.0));
    pkOut->m_akBufferStates[2].m_kRayEnd = pcBuffer + iBufferSize;
    pkOut->m_pVelocityAccumulatorC = pkOut->m_pVelocityAccumulatorA;
    pkOut->m_akBufferStates[1].m_kRayEnd = p;
    pkOut->m_akBufferStates[2].m_pRayStart = p;
    pkOut->m_akBufferStates[0].m_pTileTemplate = pkOut->m_akBufferStates[0].m_pRayStart;
    pkOut->m_akBufferStates[0].m_pValues = pkOut->m_akBufferStates[0].m_pRayStart;
    pkOut->m_akBufferStates[2].m_pTileTemplate = pkOut->m_akBufferStates[2].m_pRayStart;
    pkOut->m_akBufferStates[2].m_pValues = pkOut->m_akBufferStates[2].m_pRayStart;
    pkOut->m_akBufferStates[1].m_pTileTemplate = pkOut->m_akBufferStates[1].m_pRayStart;
    pkOut->m_akBufferStates[1].m_pValues = pkOut->m_akBufferStates[1].m_pRayStart;
}

// @fnv 0x00d892e0
// src: GUESS 0x00d892e0 (confidence: high)
void __cdecl Object_DoNothing_00d892e0() {}

typedef hkpCollisionAgent* (__cdecl *CreateFuncD923)(
    const hkpCdBody&, const hkpCdBody&,
    const hkpCollisionInput&, hkpContactMgr*);

// Shared hkpAgentEntry.h is absent; retain the local declaration required by this unit.
struct hkpAgentEntry {
    unsigned char m_ucAgentType;
    unsigned char m_ucNnTrackType;
    unsigned char m_usNumContactPoints;
    unsigned char m_iElementCount;
};
inline CreateFuncD923 FindAgentCreateFunction(const hkpCollisionDispatcher& dispatcher, const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input)
{
    int typeA = *reinterpret_cast<const int*>(&bodyA.m_pCollisionShape->m_type);
    int typeB = *reinterpret_cast<const int*>(&bodyB.m_pCollisionShape->m_type);
    const unsigned char* table = input.m_bCreatePredictiveAgents ? &dispatcher.m_agent3TypeMap[0][0] : &dispatcher.m_agent2TypeMap[0][0];
    unsigned char agentType = table[typeA * 32 + typeB];
    return reinterpret_cast<CreateFuncD923>(dispatcher.m_agent2Funcs[agentType].m_pCreateFunc);
}

// Creates a collision agent via the dispatcher's create function, stores it in freeMemory, and returns a pointer to the agent data at offset 16.
// @fnv 0x00d92300
hkpAgentData* __cdecl CreateAgent(const hkpAgent3Input& input,
                                       hkpAgentEntry* apAgentEntry,
                                       hkpAgentData* freeMemory)
{
    apAgentEntry->m_ucAgentType = (apAgentEntry->m_ucAgentType & 8) | 6;
    hkpContactMgr* pContactMgr = input.m_pContactManager;
    const hkpCdBody* bodyB = input.m_pBodyB;
    const hkpCdBody* bodyA = input.m_pBodyA;
    const hkpCollisionInput* in = reinterpret_cast<const hkpCollisionInput*>(input.m_pRayCastInput.val());
    hkpCollisionDispatcher* pDispatcher = in->m_pCollisionDispatcher;
    CreateFuncD923 f = FindAgentCreateFunction(*pDispatcher, *bodyA, *bodyB, *in);
    hkpCollisionAgent* agent = f(*bodyA, *bodyB, *in, pContactMgr);
    *reinterpret_cast<hkpCollisionAgent**>(freeMemory) = agent;
    apAgentEntry->m_usNumContactPoints = 0xff;
    return reinterpret_cast<hkpAgentData*>(reinterpret_cast<char*>(freeMemory) + 16);
}

struct CleanupAllocator {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08(void* object, unsigned int size);
    virtual void unk0C();
    virtual void unk10(void* object, unsigned int size);
};

struct CleanupRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CleanupAllocator* m_pThreadAllocator;
    int unk14;
    CleanupAllocator* m_allocator2;
};

struct CleanupObject {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void* unk14;
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
    void* unk50;
    unsigned short unk54;
    unsigned short unk56;
    unsigned short unk58;
    unsigned short unk5A;
    void* unk5C;
    int unk60;
    int unk64;
    void* unk68;
    int unk6C;
    int unk70;
    int unk74;
    void* unk78;

};

// Frees the two linked block lists, the unk14 and unk50 buffers and the unk5C array through the allocators, then frees the object itself (0x80 bytes).
// @fnv 0x00d93ab0
// src: HAVOK_LIB 0x00d93ab0
static __declspec(noinline) void deleteTaskHeaderResources(CleanupObject* self) {
    while (self->unk68 != 0) {
        void* block = self->unk68;
        self->unk68 = *reinterpret_cast<void**>(block);

        CleanupRouter* holder =
            reinterpret_cast<CleanupRouter*>(hkMemoryRouter_getInstance());
        holder->m_pThreadAllocator->unk08(block, 0x1000);
    }

    while (self->unk78 != 0) {
        void* block = self->unk78;
        self->unk78 = *reinterpret_cast<void**>(block);

        CleanupRouter* holder =
            reinterpret_cast<CleanupRouter*>(hkMemoryRouter_getInstance());
        holder->m_pThreadAllocator->unk08(block, 0x30);
    }

    if (self->unk14 != 0) {
        void* block = self->unk14;
        int size = self->unk1C;

        CleanupRouter* holder =
            reinterpret_cast<CleanupRouter*>(hkMemoryRouter_getInstance());
        holder->m_allocator2->unk10(block, size);

        self->unk14 = 0;
    }

    if (self->unk10 > 1) {
        unsigned int size = static_cast<unsigned int>(self->unk56);
        void* block = self->unk50;

        CleanupRouter* holder =
            reinterpret_cast<CleanupRouter*>(hkMemoryRouter_getInstance());
        holder->m_pThreadAllocator->unk10(block, size * 4);

        self->unk50 = 0;
    }

    CleanupRouter* holder =
        reinterpret_cast<CleanupRouter*>(hkMemoryRouter_getInstance());
    CleanupAllocator* allocator = holder->m_pThreadAllocator;

    int count = self->unk64;
    self->unk60 = 0;

    if ((static_cast<unsigned int>(count) & 0x80000000u) == 0) {
        void* block = self->unk5C;
        allocator->unk10(
            block,
            static_cast<unsigned int>(count & 0x3FFFFFFF) * 4);
    }

    self->unk5C = 0;
    self->unk64 = 0x80000000;

    CleanupRouter* pRouter =
        reinterpret_cast<CleanupRouter*>(hkMemoryRouter_getInstance());
    pRouter->m_pThreadAllocator->unk08(self, 0x80);
}

CleanupObject* volatile cleanupInput;
void CleanupEntry() { deleteTaskHeaderResources(cleanupInput); }

extern "C" void _ReadWriteBarrier(void);
extern "C" {
    unsigned __int64 __rdtsc(void);
    __declspec(dllimport) void* __stdcall TlsGetValue(unsigned int dwTlsIndex);
}

extern unsigned int DAT_0126835c;
extern "C" char str_010cc5c4[];
extern "C" char str_010d3e98[];
extern "C" char str_01076f38[];

void __cdecl Hkpsolver_ProcessEntries_00d89ed0(void* p, int a, int b);

struct S00d944d0_Ent16 {
    char* m_name;
    unsigned int m_ts;
    int unk08;
    char* m_ucOperationType;
};

struct S00d944d0_Sub {
    int unk00;
};

struct S00d944d0_Obj {
    S00d944d0_Sub* m_sub;
};

struct S00d944d0_Arg2 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int m_20;
    int m_24;
};

struct S00d944d0_Arg1 {
    void ProcessCallback(S00d944d0_Arg2* a1, S00d944d0_Arg2* a2, int a3);
};

// Records two timing entries (LtIntegrate, lt) in the TLS stream, calls FUN_00d89ed0, then invokes a2->ProcessCallback(a3, a3, 0).
// @fnv 0x00d944d0
// src: HAVOK_LIB 0x00d944d0
void __cdecl hkCpuSolveApplyGravityJob(S00d944d0_Obj* apObj, S00d944d0_Arg1* a2,
                         S00d944d0_Arg2* a3)
{
    hkMonitorStream* stream =
        (hkMonitorStream*)TlsGetValue(DAT_0126835c);

    S00d944d0_Ent16* entry =
        (S00d944d0_Ent16*)stream->m_end.m_storage;

    if ((char*)entry < stream->m_capacityMinus16.val()) {
        entry->m_name = (char*)"LtIntegrate";
        entry->m_ucOperationType = (char*)"StAppGrav";

        _ReadWriteBarrier();
        volatile unsigned int timestamp =
            (unsigned int)__rdtsc();
        entry->m_ts = timestamp;

        stream->m_end.m_storage = (char*)(entry + 1);
    }

    Hkpsolver_ProcessEntries_00d89ed0((char*)apObj->m_sub + 0x1e0,
                 a3->m_20, a3->m_24);

    stream = (hkMonitorStream*)TlsGetValue(DAT_0126835c);

    hkTimerCommand_blk_00d80000_o2* entry2 =
        (hkTimerCommand_blk_00d80000_o2*)stream->m_end.m_storage;

    if ((char*)entry2 < stream->m_capacityMinus16.val()) {
        entry2->m_pCommandName = "lt";

        _ReadWriteBarrier();
        volatile unsigned int timestamp =
            (unsigned int)__rdtsc();
        entry2->m_ticks = timestamp;

        stream->m_end.m_storage = (char*)(entry2 + 1);
    }

    a2->ProcessCallback(a3, a3, 0);
}

namespace fnv_00d94570 {
extern unsigned int DAT_0126835c;
extern char str_010cc5c4;
extern char str_010d3ea4;
extern char DAT_01076f38;

struct Fnv94570_Obj {
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
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
};

struct __declspec(align(16)) Fnv94570_Quad {
    int v0;
    int v1;
    int v2;
    int v3;
};

struct Fnv94570_Data {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

struct Fnv94570_Ctx {
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
    Fnv94570_Data* unk2C;

    void ProcessCallback(int a1, int a2, int a3);
};

void __cdecl HkpsolverGsNogs_UpdateState_00d8fb70(
    void* a1,
    int a2,
    int a3,
    int a4,
    int a5,
    int a6);

// Writes timestamped entries to a per-thread buffer, zeroes the d10 block if a3->unk20 is 0, calls FUN_00d8fb70, then a2->ProcessCallback(a3, a3, 0).
// @fnv 0x00d94570
// src: HAVOK_LIB 0x00d94570
void __cdecl hkCpuSolveConstraintBatchJob(Fnv94570_Obj** a1, int a2, Fnv94570_Ctx* apCtx)
{
    hkMonitorStream* tls;
    char* cursor;
    volatile unsigned int timestamp;
    Fnv94570_Data* data;
    int count;
    int* p;
    int d0c;
    int d08;
    int d10;
    unsigned int blocks;
    Fnv94570_Quad zero;

    tls = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    cursor = tls->m_end.m_storage;
    if (cursor < tls->m_capacityMinus16.val()) {
        *(char**)cursor = &str_010cc5c4;
        *(char**)(cursor + 0x0C) = &str_010d3ea4;
        _ReadWriteBarrier();
        timestamp = (unsigned int)__rdtsc();
        *(unsigned int*)(cursor + 0x04) = timestamp;
        tls->m_end.m_storage = cursor + 0x10;
    }

    data = apCtx->unk2C;
    d08 = data->unk08;
    d0c = data->unk0C;
    d10 = data->unk10;
    apCtx->unk24 = (*a1)->unk2F8;

    if (apCtx->unk20 == 0) {
        zero.v0 = 0;
        zero.v1 = 0;
        zero.v2 = 0;
        zero.v3 = 0;
        blocks = ((unsigned int)data->unk18 + 0x0F) & 0xFFFFFFF0u;
        _ReadWriteBarrier();
        count = (int)(blocks / 16u);
        if (count > 0) {
            p = (int*)d10 + 2;
            do {
                p[-2] = 0;
                p[-1] = 0;
                p[0] = 0;
                p[1] = 0;
                p += 4;
            } while (--count != 0);
        }
    }

    HkpsolverGsNogs_UpdateState_00d8fb70(
        &(*a1)->unk1E0,
        apCtx->unk20,
        apCtx->unk28,
        d0c,
        d08,
        d10);

    tls = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    cursor = tls->m_end.m_storage;
    if (cursor < tls->m_capacityMinus16.val()) {
        *(char**)cursor = &DAT_01076f38;
        _ReadWriteBarrier();
        timestamp = (unsigned int)__rdtsc();
        *(unsigned int*)(cursor + 0x04) = timestamp;
        tls->m_end.m_storage = cursor + 0x0C;
    }

    ((Fnv94570_Ctx*)a2)->ProcessCallback((int)apCtx, (int)apCtx, 0);
}
}  // namespace fnv_00d94570

extern char DAT_010cc5c4[];
extern char DAT_010d3eb8[];
extern char DAT_01076f38[];

struct ProfilerLongRecord {
    char* name;
    unsigned int time;
    unsigned int unk08;
    char* secondaryName;
};
struct SolverTarget {
    int unk00, unk04, unk08, unk0c, unk10;
};
struct SolverObject {
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    SolverTarget* target;
};
void __cdecl hkExportImpulsesAndRhs(TargetObj*, int, int, int);

// Records a profiler timestamp, calls FUN_00df0680 with the object's target fields, records a second timestamp, then calls ProcessCallback on context.
// @fnv 0x00d94730
// src: HAVOK_LIB 0x00d94730
void __cdecl hkCpuSolveExportResultsJob(Arg0* world, Arg1* context, SolverObject* object)
{
    hkMonitorStream* stream = static_cast<hkMonitorStream*>(TlsGetValue(DAT_0126835c));
    if (stream->m_end.m_storage < stream->m_capacityMinus16.val()) {
        ProfilerLongRecord* record = reinterpret_cast<ProfilerLongRecord*>(stream->m_end.m_storage);
        record->name = DAT_010cc5c4;
        record->secondaryName = DAT_010d3eb8;
        _ReadWriteBarrier();
        volatile unsigned int time = (unsigned int)__rdtsc();
        record->time = time;
        stream->m_end.m_storage = reinterpret_cast<char*>(record + 1);
    }
    SolverTarget* target = object->target;
    hkExportImpulsesAndRhs(&world->m_pSub->unk1e0, target->unk10, target->unk0c, target->unk08);
    stream = static_cast<hkMonitorStream*>(TlsGetValue(DAT_0126835c));
    if (stream->m_end.m_storage < stream->m_capacityMinus16.val()) {
        hkTimerCommand_blk_00d80000_o2* record = reinterpret_cast<hkTimerCommand_blk_00d80000_o2*>(stream->m_end.m_storage);
        record->m_pCommandName = DAT_01076f38;
        _ReadWriteBarrier();
        volatile unsigned int time = (unsigned int)__rdtsc();
        record->m_ticks = time;
        stream->m_end.m_storage = reinterpret_cast<char*>(record + 1);
    }
    context->ProcessCallback(reinterpret_cast<Arg2*>(object), reinterpret_cast<Arg2*>(object), 0);
}

struct StructItem {
    short* unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned short unk14;
    unsigned short pad16;
    unsigned short unk18;
    unsigned short unk1A;
};

struct StructA {
    StructItem* items;
    int count;
    int unk08;
    int* ptrC;
    int unk10;
    int unk14;
    char unk18;
};

struct StructB {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40; int unk44; int unk48; int unk4C;
    int unk50; int unk54; int unk58; int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
};

extern double DAT_010c9300;
struct LocalFlag { unsigned char value; };
void __cdecl hkSimpleContactConstraintDataBuildJacobian(short* a1, StructB* a2, LocalFlag a3, int** a4);
void __cdecl hkSolverBuildJacobianFromAtomsNotContact(short* a1, unsigned short a2, StructB* a3, int** a4);

// Fills b from each of a's items and calls FUN_00d72190 or FUN_00d6f460 on it, then ends the output at pC with a zero or, if a->unk18 is set, a size record.
// @fnv 0x00d949a0
static __declspec(noinline) void WriteItems(StructA* apSource, StructB* apDest)
{
    int* pOut = apSource->ptrC;
    StructItem* next = apSource->items;
    if (apSource->count > 0) {
        int remaining = apSource->count;
        do {
            StructItem* item = next++;
            apDest->unk38 = item->unk0C;
            apDest->unk3C = item->unk10;
            apDest->unk30 = (item->unk18 << 7) + apSource->unk08;
            apDest->unk34 = (item->unk1A << 7) + apSource->unk08;
            apDest->unk6C = item->unk18;
            apDest->unk70 = item->unk1A;
            apDest->unk60 = item->unk04;
            apDest->unk64 = item->unk08;
            apDest->unk74 = item->unk08;
            unsigned short length = item->unk14;
            short* data = item->unk00;
            if (*data == 0x16) {
                LocalFlag flag = { 1 };
                hkSimpleContactConstraintDataBuildJacobian(data, apDest, flag, &pOut);
                if (--remaining == 0) break;
            } else {
                hkSolverBuildJacobianFromAtomsNotContact(data, length, apDest, &pOut);
                if (--remaining == 0) break;
            }
        } while (true);
    }
    int* out = pOut;
    if (!apSource->unk18) {
        *out = 0;
    } else {
        int diff = apSource->unk10 - (int)out;
        if (diff > 0) {
            out[1] = diff;
            *(float*)out += DAT_010c9300;
            *(char*)out = 2;
        }
    }
}

extern "C" StructA* input_a();
extern "C" StructB* input_b();
void invoke_match() { WriteItems(input_a(),input_b()); }

struct d94eb0_cls { unsigned char b; };
extern "C" d94eb0_cls* d94eb0_target(void);
// @fnv 0x00d94eb0
// src: GUESS 0x00d94eb0 (confidence: low)
static __declspec(noinline) void Runtime_UpdateState_00d94eb0(d94eb0_cls* dst)
{
    *(unsigned char*)dst = 0;
}
void d94eb0_caller(void) { Runtime_UpdateState_00d94eb0(d94eb0_target()); }

template <typename ENUM, typename STORAGE>
__forceinline hkEnum<ENUM, STORAGE>::hkEnum(ENUM e)
{
    m_kStorage = static_cast<STORAGE>(e);
}
struct JobDescriptor {
    unsigned char m_ucSubType;
    hkEnum<hkJobType, unsigned char> m_eJobType;
    hkEnum<hkJobSpuType, unsigned char> m_eSpuType;
    unsigned char unk03;
    unsigned short m_iElementCount;
    short m_iAffinity;
    __forceinline JobDescriptor(hkJobType jobType, unsigned int subType, unsigned short size, hkJobSpuType spuType)
        : m_ucSubType((unsigned char)subType), m_eJobType(jobType), m_eSpuType(spuType), m_iElementCount(size), m_iAffinity(-1) {}
};
struct DynamicsJob : public JobDescriptor {
    int unk08;
    int unk0c;
    unsigned short m_usValueAtOffset10;
    int m_taskHeader14;
    int m_mtThreadStructure18;
    int m_unk1c;
    hkpTaskHeader_blk_00d80000_o2* m_kHeader;
    __forceinline DynamicsJob(unsigned int subType, unsigned short size, const DynamicsJob& src)
        : JobDescriptor(HK_JOB_TYPE_DYNAMICS, subType, size, HK_JOB_SPU_TYPE_DISABLED)
    {
        m_usValueAtOffset10 = src.m_usValueAtOffset10;
        m_taskHeader14 = src.m_taskHeader14;
        m_mtThreadStructure18 = src.m_mtThreadStructure18;
        m_unk1c = src.m_unk1c;
    }
};
struct DynamicsJobSubtype14 : public DynamicsJob {
    __forceinline DynamicsJobSubtype14(const DynamicsJob& job)
        : DynamicsJob(14, 0x30, job)
    {
        m_usValueAtOffset10 = job.m_usValueAtOffset10;
        m_kHeader = job.m_kHeader;
    }
};
inline void* operator new(unsigned int, void* where) throw() { return where; }
struct JobRecord {
    int m_iFirstValue;
    int unk04;
    int unk08;
    int unk0c;
    DynamicsJob m_kJob;
};
// @fnv 0x00d968e0
int __cdecl TryCreateSubtype14Job(void* queue, void* data, const DynamicsJob& job, JobRecord& newJobCreated)
{
    switch (job.m_ucSubType) {
    case 13: {
        hkpTaskHeader_blk_00d80000_o2* header = job.m_kHeader;
        if (header == 0) {
            return 1;
        }
        int n = header->m_iJobId - 1;
        header->m_iJobId = n;
        if (n != 0) {
            return 1;
        }
        new (&newJobCreated.m_kJob) DynamicsJobSubtype14(job);
        newJobCreated.m_iFirstValue = 0;
        return 0;
    }
    case 15:
        return 1;
    case 16:
        return 1;
    default:
        return 1;
    }
}

struct __declspec(align(16)) S00d96970_Local {
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned short unk04;
    short unk06;
    int unk08;
    int unk0C;
    unsigned short unk10;
    unsigned short unk12;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
};

struct S00d96970_Target {
    void __thiscall InsertItemAndNotify(int value, S00d96970_Local* local, int flag);
};

struct S00d96970_Obj {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned char unk20;
    unsigned char unk21;
};

// @fnv 0x00d96970
// src: HAVOK_LIB 0x00d96970
static __declspec(noinline) void spawnSplitSimulationIslandJob(S00d96970_Obj* self, const S00d96970_Local* src, S00d96970_Target* target, int value)
{
    if (self->unk21 != 0) {
        S00d96970_Local local;
        local.unk00 = 5;
        local.unk01 = 0;
        local.unk02 = 2;
        local.unk04 = 0x20;
        local.unk06 = -1;
        local.unk10 = src->unk10;
        local.unk14 = src->unk14;
        local.unk18 = src->unk18;
        local.unk1C = src->unk1C;
        target->InsertItemAndNotify(value, &local, 0);
    }
}

void S00d96970_Entry(S00d96970_Obj* self, const S00d96970_Local* src, S00d96970_Target* target, int value)
{
    spawnSplitSimulationIslandJob(self, src, target, value);
}

namespace fnv_00d969e0 {
struct State;
struct M20;
struct Sub;

struct Ev {
    unsigned char type;
    unsigned char b01;
    unsigned char b02;
    unsigned char unk03;
    unsigned short w04;
    short w06;
    int unk08;
    int unk0c;
    unsigned short w10;
    unsigned short unk12;
    int m_14;
    State* m_18;
    int m_1c;
    union { M20* m_20; unsigned short w20; };
    int m_24;
    union { int m_28; M20* ptr28; };
    union { Sub* m_2c; int i2c; unsigned char b2c; };
    int m_30;
    union { int m_34; struct { unsigned short w34; unsigned short w36; }; };
    int m_38;
    union { int m_3c; unsigned char b3c; };
};

struct Ev30 {
    unsigned char type;
    unsigned char b01;
    unsigned char b02;
    unsigned char unk03;
    unsigned short w04;
    short w06;
    int unk08;
    int unk0c;
    unsigned short w10;
    unsigned short unk12;
    int m_14;
    State* m_18;
    int m_1c;
    M20* m_20;
    int m_24;
    int m_28;
    Sub* m_2c;
};

struct Ev20 {
    unsigned char type;
    unsigned char b01;
    unsigned char b02;
    unsigned char unk03;
    unsigned short w04;
    short w06;
    int unk08;
    int unk0c;
    unsigned short w10;
    unsigned short unk12;
    int m_14;
    State* m_18;
    int m_1c;
};

struct Node {
    int m_00;
    int m_04;
};

struct M20 {
    int unk00;
    int m_04;
    int unk08;
    Node* m_0c;
};

struct Sub {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned short unk1c;
    unsigned short m_1e;
    int m_20;
};

struct State {
    int ref;
    int m_04;
    int m_08;
    int unk0c;
    int unk10;
    int m_14;
    int m_18;
    int unk1c;
    unsigned char m_20;
    unsigned char m_21;
    unsigned short unk22;
    Node* m_24;
    int unk28;
    int unk2c;
    int m_30;
    int m_34;
    unsigned short m_38;
    unsigned short m_3a;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int unk4c;
    int unk50;
    unsigned short m_54;
    unsigned short unk56;
    unsigned char m_58;
    unsigned char m_59;
    unsigned short unk5a;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int m_6c;
    int unk70;
    int m_74;
    int m_78;
    unsigned short m_7c;
    unsigned short unk7e;
};

struct Out {
    int m_00;
    int unk04;
    int unk08;
    int unk0c;
    Ev m_kEvent;
};

struct Ev20;
struct A0Cls {
    int InsertItemAndNotify(int a1, Ev20* temp, int z);
};

static __forceinline void InitEv(Ev* e, Ev* ev, unsigned char type, unsigned char flag, unsigned short size)
{
    e->type = type;
    e->b01 = 0;
    e->b02 = flag;
    _ReadWriteBarrier();
    e->w04 = size;
    e->w06 = -1;
    e->w10 = ev->w10;
    e->m_14 = ev->m_14;
    e->m_18 = ev->m_18;
    e->m_1c = ev->m_1c;
}

inline void* __cdecl operator new(unsigned int, void* p) throw() { return p; }
inline void __cdecl operator delete(void*,void*) throw() {}
struct Placed2 : Ev { __forceinline Placed2(Ev* ev, State* s) {
                    InitEv(this, ev, 8, 1, 0x30);
                    *(Ev30*)this = *(Ev30*)ev;
                    this->i2c = ev->m_2c->m_20;
                
} };
struct EmptyScope { EmptyScope() { _ReadWriteBarrier(); } ~EmptyScope() { _ReadWriteBarrier(); } };
struct Stage0 : Ev { __forceinline Stage0(Ev* ev, State* s){
                    InitEv(this, ev, 6, 1, 0x40);
                    this->m_20 = (M20*)s->m_14;
                    this->m_28 = s->m_30 - (int)this->m_20;
                    this->i2c = s->m_3c - (int)this->m_20; _ReadWriteBarrier();
                    this->m_30 = s->m_40 - (int)this->m_20;
                    this->m_24 = s->m_18;
                    this->m_34 = s->m_44;
                    this->m_38 = s->m_48;
                
} };
struct Stage1 : Ev { __forceinline Stage1(Ev* ev, State* s){
                    InitEv(this, ev, 7, 1, 0x30);
                    this->m_20 = (M20*)s->m_30;
                    this->m_24 = s->m_34;
                
} };
// Dispatches on ev->type, decrements the State reference count, and constructs the next event in out->m_kEvent when the count reaches zero.
// @fnv 0x00d969e0
// src: HAVOK_LIB 0x00d969e0
int __cdecl hkpJobQueueUtils_finishIntegrateJob(A0Cls* a0, int a1, Ev* apEvent, Out* out)
{
    int result = 1;
    State* s = apEvent->m_18;
    switch (apEvent->type) {
    case 1:
    case 2:
        if (--s->ref == 0) {
            if (s->m_74 > 0) {
                Ev* e = &out->m_kEvent;
                if (e) InitEv(e, apEvent, 3, 2, 0x20);
                out->m_00 = 0;
                return 0;
            } else {
                spawnBuildJacobiansJobs((unsigned char*)s, (int*)apEvent, (unsigned char*)out);
                return 0;
            }
        }
        goto Fail;
    case 3: { EmptyScope scope;
        spawnBuildJacobiansJobs((unsigned char*)s, (int*)apEvent, (unsigned char*)out);
        return 0;
        goto Fail;
    }
    case 4:
        if (--s->ref == 0) {
            Ev* next;
            if (s->m_58) {
                Ev* e=&out->m_kEvent; if(e) e=new(e) Stage0(apEvent,s); else e=0;
                out->m_00 = 0;
                out->m_kEvent.b02 = s->m_59 ? 2 : 1;
                next=e;
            } else {
                Stage1* e = new(&out->m_kEvent) Stage1(apEvent,s);
                out->m_00 = 0;
                out->m_kEvent.b02 = 1;
                s->ref = s->m_38;
                next=e;
            }
            if (s->m_21) {
                __declspec(align(16)) Ev20 temp;
                Ev* e = next;
                temp.w04 = 0x20;
                temp.w06 = (unsigned short)-1;
                temp.w10 = e->w10;
                temp.m_14 = e->m_14;
                temp.m_18 = e->m_18;
                int saved = e->m_1c;
                temp.type = 5;
                temp.b01 = 0;
                temp.b02 = 2;
                temp.m_1c = saved;
                a0->InsertItemAndNotify(a1, &temp, 0);
                return 0;
            }
            goto ReturnZero;
        }
        goto Fail;
    case 5:
        goto ProcessAmount;
    case 6:
        s->m_20 = 1;
        _ReadWriteBarrier();
        return result;
    case 7:
        if (--s->ref == 0) {
            Ev* e = &out->m_kEvent;
            if (e) {
                InitEv(e, apEvent, 8, 1, 0x30);
                e->i2c = s->m_78;
                e->m_20 = 0;
                e->m_28 = 0;
            }
            out->m_00 = 0;
            out->m_kEvent.b02 = 1;
            s->ref = s->m_7c;
            return 0;
        }
        goto Fail;
    case 8:
        if (--s->ref == 0) {
            int saved = apEvent->m_2c->m_1e;
            int newref;
            if (saved != 0) {
                Ev* e = &out->m_kEvent;
                if (e) {
                    InitEv(e, apEvent, 8, 1, 0x30);
                    *(Ev30*)e = *(Ev30*)apEvent;
                    e->i2c = apEvent->m_2c->m_20;
                }
                newref = saved;
            } else if ((unsigned int)(apEvent->m_28 + 1) < (unsigned int)apEvent->m_24) {
                Ev* e = new(&out->m_kEvent) Placed2(apEvent,s);
                e->m_28++;
                e->i2c = s->m_78;
                newref = s->m_7c;
            } else {
                Ev* e = &out->m_kEvent;
                if (e) {
                    InitEv(e, apEvent, 9, 1, 0x30);
                    e->m_20 = (M20*)s->m_30;
                    e->m_24 = s->m_34;
                    e->ptr28 = apEvent->m_20;
                    e->b2c = 0;
                }
                newref = s->m_3a;
            }
            out->m_00 = 0;
            out->m_kEvent.b02 = 1;
            s->ref = newref;
            result=0; goto Finish;
        }
        break;
    case 9:
        if (--s->ref == 0) {
            int count;
            if (apEvent->b2c == 0) {
                Ev* e = &out->m_kEvent;
                if (e) {
                    InitEv(e, apEvent, 8, 1, 0x30);
                    e->i2c = s->m_78;
                    e->m_20 = (M20*)(apEvent->m_28 + 1);
                    e->m_28 = 0;
                }
                count = s->m_7c;

            } else {
                Ev* e = &out->m_kEvent;
                if (e) {
                    InitEv(e, apEvent, 11, 2, 0x40);
                    e->m_20 = (M20*)s->m_78;
                    e->w36 = 0;
                    e->w34 = s->m_54;
                    e->m_30 = s->m_14;
                    e->b3c = 0;
                }
                count = s->m_6c;

            }
            out->m_00 = 0;
            out->m_kEvent.b02 = 1;
            s->ref = count;
ReturnZero:
            return 0;
        }
        goto Fail;
    case 10: {
        s->ref--;
        Node* n = apEvent->m_20->m_0c;
        if (n->m_00 != 0) {
            n->m_04 = (int)s->m_24;
            s->m_24 = n;
        }
        if (s->ref == 0)
            s->m_20 = 1;
        goto Fail;
    }
    case 11: {
        if (apEvent->m_38 <= 5)
            s->m_08 = 0;
        result = (int)(((unsigned int)(unsigned short)apEvent->m_34 - 1) >> 7) + 1;
ProcessAmount:
        _ReadWriteBarrier();
        int* count = &apEvent->m_18->m_04;
        int v = *count - result;
        *count = v;
        if (v != 0)
            goto Fail;
        {
            Ev* e = &out->m_kEvent;
            if (e) {
                State* state = apEvent->m_18;
                InitEv(e, apEvent, 12, 2, 0x30);
                e->m_18 = state;
                e->w20 = 1;
            }
            out->m_00 = 0;
            return 0;
        }
        goto Fail;
    }
    case 12:
        goto Fail;
    case 13: {
        M20* p = apEvent->m_20;
        if (!p)
            goto Finish;
        {
            int c = p->m_04 - 1;
            p->m_04 = c;
            if (c != 0)
                goto Fail;
        }
        {
            Ev* e = &out->m_kEvent;
            if (e) {
                InitEv(e, apEvent, 14, 2, 0x30);
                e->w10 = apEvent->w10;
                e->m_20 = apEvent->m_20;
            }
            out->m_00 = 0;
            return 0;
        }
        goto Fail;
    }
    case 14:
        goto Fail;
Fail:
    result=1;
Finish:
    return result;
    case 15:
    case 16:
        goto Finish;
    default:
        goto Fail;
    }
    goto Finish;
}
}  // namespace fnv_00d969e0

extern float DAT_01017b78;
extern float DAT_01012068;
extern float DAT_01050cb0;
extern double DAT_01011588;
extern double DAT_01035718;
extern "C" LocalM128 _mm_set_ps1(float);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);

__forceinline unsigned int roundLane(const float& value)
{
    float copy = value;
    return fnv_FloatToInt(copy);
}

// @fnv 0x00d974f0
// src: GUESS 0x00d974f0 (confidence: low)
float Runtime_ProcessEntries_00d974f0()
{
    float low = DAT_01017b78;
    LocalM128 scale = _mm_set_ps1(DAT_01012068);
    float high = DAT_01050cb0;
    for (int n = 23; n != 0; --n) {
        float mid = (high + low) * DAT_01011588;
        LocalM128 values = _mm_mul_ps(_mm_add_ps(*(const LocalM128*)&DAT_01267e30, _mm_set_ps1(mid)), scale);
        unsigned int x = roundLane(values.m128_f32[0]);
        unsigned int y = roundLane(values.m128_f32[1]);
        unsigned int z = roundLane(values.m128_f32[2]);
        unsigned int w = roundLane(values.m128_f32[3]);
        if (x < 11u) low = mid;
        else high = mid;
    }
    return (high + low) * DAT_01011588 - DAT_01035718;
}

extern const LocalM128 DAT_011b6de0;

// @fnv 0x00d98620
// src: GUESS 0x00d98620 (confidence: low)
LocalM128 __cdecl Object_GetDAT_011b6de0_00d98620()
{
    return DAT_011b6de0;
}

struct ListenerArray {
    void** m_ppItems;
    unsigned short m_wCount;
};

// Removes null entries from the listener array by shifting subsequent items down and decrementing the count.
// @fnv 0x00d85d40
// src: GUESS 0x00d85d40 (confidence: low)
static __declspec(noinline) void Object_ProcessEntries_00d85d40(ListenerArray* pArr)
{
    for (int i = (int)pArr->m_wCount - 1; i >= 0; i--)
    {
        if (pArr->m_ppItems[i] == 0)
        {
            pArr->m_wCount--;
            for (int j = i; j < (int)pArr->m_wCount; j++)
                pArr->m_ppItems[j] = pArr->m_ppItems[j + 1];
        }
    }
}

struct ListenerOwner {
    int unk00;
    ListenerArray m_kNode;
};

void CallCompact(ListenerOwner* o)
{
    Object_ProcessEntries_00d85d40(&o->m_kNode);
}

#include <stdarg.h>
namespace fnv_00d87aa0 {
extern const char DAT_010d3cb4[];
int __cdecl hkString_strCmp(int a, int b);
extern "C" int __cdecl hkString_strLen(const char* s);
int __cdecl hkString_sprintf(char* buf, const char* fmt, ...);
int __cdecl hkString_vsnprintf(char* buf, int size, const char* fmt, va_list args);
struct FUN_00cc0470_Stream { void ForwardCall_00cc0470(const char* s, int n); };
struct D87aa0Name { char m_name[32]; };
struct D87aa0Reporter {
    int unk;
    int unkCur;
    FUN_00cc0470_Stream* m_stream;
    int m_uiItemCount;
    D87aa0Name* m_filters;
    int m_numFilters;
};

// @fnv 0x00d87aa0
// src: HAVOK_LIB 0x00d87aa0
void __cdecl hkTraceStream_printf(D87aa0Reporter* apReporter, const char* id, const char* fmt, ...)
{
    for (int i = 0; i < apReporter->m_numFilters; i++) {
        D87aa0Name& e = apReporter->m_filters[i];
        if (hkString_strCmp((int)e.m_name, (int)id) == 0)
            return;
    }
    int n = ++apReporter->m_uiItemCount;
    if (n == 0x803)
        apReporter->m_uiItemCount = n;
    if (apReporter->m_stream) {
        int buf[0x100];
        va_list args;
        va_start(args, fmt);
        if (*fmt == '#') {
            hkString_sprintf((char*)buf, DAT_010d3cb4, n);
            apReporter->m_stream->ForwardCall_00cc0470((char*)buf, hkString_strLen((char*)buf));
            hkString_vsnprintf((char*)buf, 0x400, fmt + 1, args);
        } else {
            hkString_vsnprintf((char*)buf, 0x400, fmt, args);
        }
        apReporter->m_stream->ForwardCall_00cc0470((char*)buf, hkString_strLen((char*)buf));
    }
}
}  // namespace fnv_00d87aa0

namespace sd85040 {

class Shape {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int GetType() const;
};

struct ContainerShape : Shape {
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    Shape* m_pkChild;
};

struct ListShape : Shape {
    Shape* hkpMalleableConstraintData_getWrappedConstraintData();
};

struct VertexShape : Shape {
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk1c;
    hkVector4 m_akVertices[1];
};

struct TransformShape : Shape {
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk1c;
    Transform m_akTransforms[1];
};

// @fnv 0x00d85040
// src: GUESS 0x00d85040 (confidence: low)
void Object_ProcessEntries_00d85040(Shape* pkShape, const Transform& kTransform, int iIndex)
{
    for (;;)
    {
        switch (pkShape->GetType())
        {
        case 12:
            pkShape = ((ContainerShape*)pkShape)->m_pkChild;
            break;
        case 13:
            pkShape = ((ListShape*)pkShape)->hkpMalleableConstraintData_getWrappedConstraintData();
            break;
        case 1:
            ((TransformShape*)pkShape)->m_akTransforms[iIndex].FUN_00c6cd60(kTransform);
            return;
        case 2:
            ((TransformShape*)pkShape)->m_akTransforms[iIndex].FUN_00c6cd60(kTransform);
            return;
        case 6:
            ((TransformShape*)pkShape)->m_akTransforms[iIndex].FUN_00c6cd60(kTransform);
            return;
        case 7:
            ((TransformShape*)pkShape)->m_akTransforms[iIndex].FUN_00c6cd60(kTransform);
            return;
        case 14:
            ((TransformShape*)pkShape)->m_akTransforms[iIndex].FUN_00c6cd60(kTransform);
            return;
        case 9:
            ((TransformShape*)pkShape)->m_akTransforms[iIndex].FUN_00c6cd60(kTransform);
            return;
        case 0:
            *reinterpret_cast<LocalM128*>(&((VertexShape*)pkShape)->m_akVertices[iIndex].m_vComponents) = kTransform.r[3];
            return;
        case 8:
            *reinterpret_cast<LocalM128*>(&((VertexShape*)pkShape)->m_akVertices[iIndex].m_vComponents) = kTransform.r[3];
            return;
        case 15:
            *reinterpret_cast<LocalM128*>(&((VertexShape*)pkShape)->m_akVertices[iIndex].m_vComponents) = kTransform.r[3];
            return;
        default:
            return;
        }
    }
}

}

struct HasFlag_d86 {
    char pad[0x10];
    unsigned short m_flags;
    hkBool HasFlag() const;
};

// @fnv 0x00d86a70
hkBool HasFlag_d86::HasFlag() const
{
    return (m_flags & 0x200) == 0x200;
}

struct D94Rec16 {
    const char* name;
    unsigned int start;
    unsigned int unk08;
    const char* name2;
};
extern unsigned int DAT_0126835c;
typedef void* (__stdcall *StringCursorGetFn)(unsigned long);
extern StringCursorGetFn DAT_00fdf044;
extern const char str_010d3ef4[];
void __cdecl hkRigidMotionUtilApplyForcesAndBuildAccumulators(char* p, unsigned int a, unsigned int b, unsigned int c, unsigned int d);
struct D94Sub {
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
    int u24;
    int u28;
    int u2c;
    int m30;
};
struct D94Body {
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    D94Sub* m18;
    int u1c;
    int* p20;
    unsigned short us24;
    unsigned short us26;
};
struct D94Obj {
    int ProcessCallback(D94Body* a, D94Body* b, int c);
};
// Records two timing markers in a TLS buffer, calls FUN_00d29830 with a3 fields, then returns a2->ProcessCallback(a3, a3, 0).
// @fnv 0x00d94df0
// src: COMMUNITY 0x00d94df0
int __cdecl hkCpuBuildAccumulatorsJob(char* a1, D94Obj* a2, D94Body* a3)
{
    StringCursorGetFn fn = DAT_00fdf044;
    hkMonitorStream* tp = (hkMonitorStream*)fn(DAT_0126835c);
    D94Rec16* cur = reinterpret_cast<D94Rec16*>(tp->m_end.val());
    if (reinterpret_cast<char*>(cur) < tp->m_capacityMinus16.val()) {
        cur->name = str_010cc5c4;
        cur->name2 = str_010d3ef4;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        cur->start = t;
        cur++;
        tp->m_end.m_storage = reinterpret_cast<char*>(cur);
    }
    hkRigidMotionUtilApplyForcesAndBuildAccumulators(a1 + 0xe0, (unsigned int)(a3->p20 + a3->us24), a3->us26, 0xe0, ((a3->us24 + 1) << 7) + a3->m18->m30);
    hkMonitorStream* tp2 = (hkMonitorStream*)fn(DAT_0126835c);
    hkTimerCommand_blk_00d80000_o2* r = (hkTimerCommand_blk_00d80000_o2*)tp2->m_end.m_storage;
    if (r < (hkTimerCommand_blk_00d80000_o2*)tp2->m_capacityMinus16.m_storage) {
        r->m_pCommandName = str_01076f38;
        _ReadWriteBarrier();
        volatile unsigned int t2 = (unsigned int)__rdtsc();
        r->m_ticks = t2;
        r++;
        tp2->m_end.m_storage = reinterpret_cast<char*>(r);
    }
    return a2->ProcessCallback(a3, a3, 0);
}

#include <string.h>
struct S00d967a0_Obj {
    void** vptr;
};

struct S00d967a0_Rec {
    unsigned char m00;
    unsigned char unk01;
    unsigned short unk02;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned short m10;
    unsigned short unk12;
    int m14;
    unsigned int unk18;
    S00d967a0_Obj* m1C;
    unsigned int unk20;
    unsigned short m24;
    unsigned short unk26;
    unsigned short m28;
    unsigned short m2A;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    int m40;
    unsigned short m44;
};

static __forceinline void memCpy16NonEmpty(void* dst, const void* src, int numQuads)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    do {
        d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; d[3] = s[3];
        s += 4; d += 4;
    } while (--numQuads > 0);
}
static __forceinline int split13(S00d967a0_Rec* src, S00d967a0_Rec* dst)
{
    unsigned short a = src->m28;
    unsigned short c = src->m2A;
    if (a <= c) return 0;
    src->m24++;
    src->m28 = (unsigned short)(a - c);
    src->m40 += c;
    dst->m44 = 0x200;
    dst->m28 = c;
    return 1;
}

static __forceinline int split15(S00d967a0_Rec* src, S00d967a0_Rec* dst)
{
    unsigned short a = src->m28;
    unsigned short c = src->m2A;
    if (a <= c) return 0;
    src->m28 = (unsigned short)(a - c);
    src->m24++;
    dst->m28 = c;
    return 1;
}

// Copies 128 bytes from src to dst, sets dst->m14 from a table lookup, then splits the record for types 13 and 15 or copies it whole for type 14.
// @fnv 0x00d967a0
int SplitRecord(int a1, int a2, S00d967a0_Rec* src, S00d967a0_Rec* dst)
{
    memCpy16NonEmpty(dst, src, 8);
    dst->m14 = ((int*)src->m1C->vptr[10])[dst->m10];
    switch (src->m00) {
    case 13:
        return split13(src, dst);
    case 14:
        memcpy(dst, src, 128);
        return 0;
    case 15:
        return split15(src, dst);
    }
    return 0;
}

extern "C" LocalM128 _mm_setzero_ps();
extern "C" LocalM128 _mm_cmplt_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_cmpeq_ps(LocalM128, LocalM128);
extern "C" int _mm_movemask_ps(LocalM128);
struct D986Result {
    char value;
    D986Result(bool b) : value(b) {}
    operator bool() const { return value != 0; }
};
// @fnv 0x00d98630
// src: GUESS 0x00d98630 (confidence: low)
D986Result __cdecl Runtime_ProcessEntries_00d98630(const LocalM128* src, const LocalM128* dst, int mask)
{
    D986Result result(true);
    LocalM128 zero = _mm_setzero_ps();
    for (int i=0; i<3; ++i) {
        LocalM128 d = _mm_sub_ps(dst[i], src[i]);
        bool hit = ((_mm_movemask_ps(_mm_cmplt_ps(d,zero)) & mask) == mask)
            || ((_mm_movemask_ps(_mm_cmpeq_ps(d,zero)) & mask) == mask)
            || ((_mm_movemask_ps(_mm_cmplt_ps(zero,d)) & mask) == mask);
        result = result && hit;
    }
    return result;
}

// Real body is 0xd96600..0xd9679f (0x1A0). 0xd967a0 is a second function the claim swallowed.
struct D96600Link {
    D96600Link* next;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned char flag1c;
};
struct D96600Table {
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
    int* table;
};
struct D96600Blob {
    unsigned char type;
    unsigned char unk01;
    unsigned short unk02;
    int unk04;
    int unk08;
    int unk0c;
    unsigned short word10;
    unsigned short unk12;
    int field14;
    D96600Link* unk18;
    D96600Table** ppHolder;
    union {
        int count20;
        unsigned int offset20;
        D96600Link* node20;
    };
    union {
        unsigned int limit24;
        struct {
            unsigned short word24;
            unsigned short word26;
        };
    };
    int unk28;
    D96600Link* node2c;
    int unk30;
    unsigned short word34;
    unsigned short word36;
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

    int hkpBroadPhaseJob_popJobTask(int** slot, D96600Blob* dst);
};
static __forceinline int popPart(D96600Blob* src, D96600Blob* dst)
{
    D96600Table* holder = *src->ppHolder;
    int** slot = &holder->table;
    dst->field14 = holder->table[dst->word10];

    switch (src->type) {
    case 0: {
        int n = src->count20;
        if (n <= 1)
            return 0;
        src->word10++;
        src->count20 = n - 1;
        dst->count20 = 1;
        return 1;
    }
    case 1: {
        unsigned short step = 0x80;
        if (src->word26 <= step)
            return 0;
        src->word26 = (unsigned short)(src->word26 - step);
        src->word24 = (unsigned short)(src->word24 + step);
        dst->word26 = step;
        return step - 0x7f;
    }
    case 4:
    case 10:
        if (src->node20->next == 0)
            return 0;
        src->node20 = src->node20->next;
        return 1;
    case 12:
        return src->hkpBroadPhaseJob_popJobTask(slot, dst);
    case 11: {
        unsigned short step = 0x80;
        if (src->word34 > step) {
            src->word34 = (unsigned short)(src->word34 - step);
            src->word36 = (unsigned short)(src->word36 + step);
            dst->word34 = step;
            return step - 0x7f;
        }
        if (src->count20 == 0)
            return 0;
        src->type = 0x0a;
        return 1;
    }
    case 7:
    case 9: {
        unsigned int next = src->offset20 + 0x4000;
        if (next >= src->limit24)
            return 0;
        src->offset20 = next;
        dst->limit24 = next;
        return 1;
    }
    case 8:
        if (src->node2c->flag1c != 0)
            return 0;
        src->node2c = src->node2c->next;
        return 1;
    case 3:
    case 6:
    case 14:
        *dst = *src;
        return 0;
    case 2:
    case 5:
    case 13:
        return 0;
    default:
        return 0;
    }

}
// Copies src into dst in 16-byte blocks, then returns popPart(src, dst), which advances src by its type and sets dst->field14.
// @fnv 0x00d96600
int __cdecl PopPart(int callbackCtx, int callbackIndex, D96600Blob* src, D96600Blob* dst)
{
    memCpy16NonEmpty(dst, src, sizeof(D96600Blob) / 16);
return popPart(src,dst);
}

union __declspec(intrin_type) __declspec(align(16)) __m128i { unsigned __int64 q[2]; };
extern "C" {
LocalM128 _mm_add_ps(LocalM128, LocalM128);
LocalM128 _mm_mul_ps(LocalM128, LocalM128);
LocalM128 _mm_and_ps(LocalM128, LocalM128);
LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
LocalM128 _mm_or_ps(LocalM128, LocalM128);
LocalM128 _mm_cmpeq_ps(LocalM128, LocalM128);
LocalM128 _mm_cmplt_ps(LocalM128, LocalM128);
LocalM128 _mm_cmple_ps(LocalM128, LocalM128);
LocalM128 _mm_min_ps(LocalM128, LocalM128);
LocalM128 _mm_max_ps(LocalM128, LocalM128);
LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
LocalM128 _mm_rcp_ps(LocalM128);
LocalM128 _mm_setzero_ps();

LocalM128 _mm_load_ss(const float*);
LocalM128 _mm_set_ps1(float);
int _mm_movemask_ps(LocalM128);
__m128i _mm_setzero_si128();
__m128i _mm_unpacklo_epi16(__m128i, __m128i);
__m128i _mm_unpackhi_epi16(__m128i, __m128i);
__m128i _mm_srli_epi32(__m128i, int);
__m128i _mm_slli_epi32(__m128i, int);
LocalM128 _mm_cvtepi32_ps(__m128i);
}

__forceinline LocalM128 TreeSplat(float value) {
    LocalM128 scalar = _mm_load_ss(&value);
    return _mm_shuffle_ps(scalar, scalar, 0);
}
struct __declspec(align(16)) TreeVector {
    float x, y, z, w;
    LocalM128 simdValue() const { return *reinterpret_cast<const LocalM128*>(this); }
    float operator[](unsigned int axis) const { return (&x)[axis]; }
};
struct TreeNode {
    int flags;
    unsigned int bounds;
};
struct __declspec(align(16)) QuantizedBounds {
    unsigned short minX, minY, minZ, idLow;
    unsigned short maxX, maxY, maxZ, idHigh;
};
union TreeLeafId {
    unsigned int value;
    struct { unsigned short low, high; };
};
struct TreeCollector {
    virtual void unused();
    virtual void AddHit(unsigned char* state, unsigned int id);
    virtual void begin(unsigned char* state);
    virtual float earlyOut();
};
extern unsigned int DAT_010c92e0[4];
extern const double DAT_010217d0;
extern const LocalM128 DAT_011b6de0;
extern LocalM128 DAT_010c7170;
extern const float DAT_010cd644 = 1.0000000272564224e16f;
extern const float DAT_0104e148 = -3.402820018375656e38f;
extern const float DAT_0104da48 = 3.402820018375656e38f;
float __cdecl NiMax(float a, float b);
float __cdecl NiMin(float a, float b);

template<class T> struct TreeRef { T* p; TreeRef(T* q):p(q){} operator T*()const{return p;} T* operator->()const{return p;} };

__forceinline const QuantizedBounds* projectAt(const TreeNode& node, const QuantizedBounds* leaves, unsigned int index) { return leaves + (node.flags & 0x7fffffff) + index; }
struct BoundPair { LocalM128 minimum, maximum; void set(float a, float b) { minimum = _mm_set_ps1(a); maximum = _mm_set_ps1(b); } };
// Recursively walks a tree of quantized bounds, testing leaf boxes against the ray interval and calling collector->AddHit for each hit.
// @fnv 0x00d986c0
void __cdecl IntersectTree(void* tree, const TreeNode* node,
                        const QuantizedBounds* leaves,
                        const TreeVector* scale, const TreeVector* offset,
                        const TreeVector* origin, const TreeVector* direction,
                        float intervalMin, float intervalMax, float fractionScale,
                        TreeCollector* collector)
{
    const TreeNode* pNodeFirstChild;
    const TreeNode* pNodeSecondChild;
    float enter;
    float leave;
    TreeNode current = *node;
    for (;;) {
        if (~(current.flags >> 31) != 0) {
    if ((current.flags ^ 0x7fffffff) == 0 || (int)current.bounds <= 0) return;
        __m128i integerZero = _mm_setzero_si128();
    const LocalM128 conversionLow = { DAT_010cd644, DAT_010cd644, DAT_010cd644, DAT_010cd644 };
    const LocalM128 conversionHigh = { DAT_010cd644, DAT_010cd644, DAT_010cd644, DAT_010cd644 };
    const LocalM128 negativeInfinity = { DAT_0104e148, DAT_0104e148, DAT_0104e148, DAT_0104e148 };
    const LocalM128 positiveInfinity = { DAT_0104da48, DAT_0104da48, DAT_0104da48, DAT_0104da48 };
    for (int leafIndex=0; leafIndex < (int)current.bounds; ++leafIndex) {
        const QuantizedBounds* item = projectAt(current,leaves,leafIndex);
        TreeLeafId id;
        id.low = item->idLow;
        id.high = item->idHigh;
        QuantizedBounds quantized = *item;
        LocalM128 unitScale = _mm_mul_ps(DAT_011b6de0, scale->simdValue());
        __m128i packed = *reinterpret_cast<const __m128i*>(&quantized);
        __m128i low = _mm_unpacklo_epi16(packed, integerZero);
        __m128i high = _mm_unpackhi_epi16(packed, integerZero);
        LocalM128 minBounds = _mm_add_ps(_mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi32(low,16)), conversionLow),
                                    _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(low,16),16)));
        LocalM128 maxBounds = _mm_add_ps(_mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi32(high,16)), conversionHigh),
                                    _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(high,16),16)));
        minBounds = _mm_add_ps(_mm_mul_ps(minBounds, unitScale), offset->simdValue());
        maxBounds = _mm_add_ps(_mm_mul_ps(maxBounds, unitScale), offset->simdValue());
        LocalM128 dir = direction->simdValue();
        LocalM128 adjustedDir = _mm_shuffle_ps(dir, _mm_unpackhi_ps(dir, DAT_010c7170), 0xc4);
        LocalM128 reciprocal = _mm_rcp_ps(adjustedDir);
        LocalM128 correction = _mm_mul_ps(_mm_mul_ps(reciprocal, adjustedDir), reciprocal);
        reciprocal = _mm_sub_ps(_mm_add_ps(reciprocal, reciprocal), correction);
        LocalM128 zero = _mm_setzero_ps();
        LocalM128 dirIsZero = _mm_cmpeq_ps(zero, dir);
        reciprocal = _mm_or_ps(_mm_andnot_ps(dirIsZero, reciprocal), _mm_and_ps(dirIsZero, zero));
        LocalM128 rayOrigin = origin->simdValue();
        LocalM128 lowerT = _mm_mul_ps(_mm_sub_ps(minBounds, rayOrigin), reciprocal);
        LocalM128 upperT = _mm_mul_ps(_mm_sub_ps(maxBounds, rayOrigin), reciprocal);
        LocalM128 forward = _mm_cmple_ps(zero, reciprocal);
        LocalM128 nearT = _mm_or_ps(_mm_and_ps(forward, lowerT), _mm_andnot_ps(forward, upperT));
        LocalM128 farT = _mm_or_ps(_mm_and_ps(forward, upperT), _mm_andnot_ps(forward, lowerT));
        BoundPair interval; interval.set(intervalMin,intervalMax);
        LocalM128 noMotion = _mm_cmpeq_ps(zero, reciprocal);
        nearT = _mm_or_ps(_mm_andnot_ps(noMotion, nearT), _mm_and_ps(noMotion, negativeInfinity));
        farT = _mm_or_ps(_mm_andnot_ps(noMotion, farT), _mm_and_ps(noMotion, positiveInfinity));
        LocalM128 end = _mm_min_ps(_mm_shuffle_ps(farT,farT,0), _mm_shuffle_ps(farT,farT,0x55));
        end = _mm_min_ps(end,_mm_shuffle_ps(farT,farT,0xaa));
        end = _mm_min_ps(interval.maximum,end);
        LocalM128 start = _mm_max_ps(_mm_shuffle_ps(nearT,nearT,0), _mm_shuffle_ps(nearT,nearT,0x55));
        start = _mm_max_ps(start,_mm_shuffle_ps(nearT,nearT,0xaa));
        start = _mm_max_ps(interval.minimum,start);
        LocalM128 hit = _mm_andnot_ps(noMotion,_mm_cmplt_ps(start,end));
        hit = _mm_or_ps(hit,_mm_and_ps(_mm_and_ps(_mm_cmple_ps(minBounds,rayOrigin),_mm_cmple_ps(rayOrigin,maxBounds)),noMotion));
        if ((_mm_movemask_ps(hit)&7) == 7) {
            unsigned char state;
            collector->AddHit(&state, id.value);
        }
    }
    return;
        }

        unsigned int axis = current.flags & 3;
        node = reinterpret_cast<const TreeNode*>(reinterpret_cast<const char*>(node) + (node->flags & 0x7ffffffc));
        const TreeNode* right = node + 1;
        float lower = (unsigned short)current.bounds / 65535.0 * (*scale)[axis] + (*offset)[axis];
        float upper = (int)(current.bounds >> 16) / 65535.0 * (*scale)[axis] + (*offset)[axis];
        unsigned int mask = DAT_010c92e0[axis];
        LocalM128 directionValue = direction->simdValue();
        LocalM128 zero = _mm_setzero_ps();
        if ((_mm_movemask_ps(_mm_cmpeq_ps(zero, directionValue)) & mask) == mask) {
            bool visitLeft = true;
            if (!((*origin)[axis] <= upper + 0.25)) visitLeft = false;
            bool visitRight = true;
            if (!((*origin)[axis] >= lower - 0.25)) visitRight = false;
            if (visitLeft)
                IntersectTree(tree, node, leaves, scale, offset, origin, direction,
                            intervalMin, intervalMax, fractionScale, collector);
            if (!visitRight) return;
            node = right;
        } else {
            enter = (lower - (*origin)[axis]) / (*direction)[axis];
            leave = (upper - (*origin)[axis]) / (*direction)[axis];
            if ((_mm_movemask_ps(_mm_cmplt_ps(zero, directionValue)) & mask) == mask) {
                pNodeFirstChild = node;
                pNodeSecondChild = right;
            } else {
                pNodeFirstChild = right;
                pNodeSecondChild = node;
                float temp = enter;
                enter = leave;
                leave = temp;
            }
            float fractionLimit = collector->earlyOut() * fractionScale;
            float limit = fractionLimit < intervalMax ? fractionLimit : intervalMax;
            if (leave < intervalMin) {
                node = pNodeSecondChild;
            } else if (enter > limit) {
                node = pNodeFirstChild;
            } else {
                goto overlap;
            }
        }
        current = *node;
    }
overlap:
    {
                unsigned char state;
                collector->begin(&state);
                enter = NiMax(enter, intervalMin);
                IntersectTree(tree, pNodeFirstChild, leaves, scale, offset, origin, direction,
                            intervalMin, NiMin(intervalMax, leave), fractionScale, collector);
                if (NiMin(collector->earlyOut() * fractionScale, intervalMax) > enter)
                    IntersectTree(tree, pNodeSecondChild, leaves, scale, offset, origin, direction,
                                enter, intervalMax, fractionScale, collector);
                return;
    }
}

extern char str_010cc5c4[];
extern char str_010d3ec8[];
extern char DAT_01076f38[];

struct S00d94a80_Ctx {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
};

struct __declspec(align(16)) S00d94a80_Local {
    S00d94a80_Ctx head;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    char* unk94;
};

void __cdecl hkSolverBuildJacobianFromAtomsNotContact(char* atom, int count, S00d94a80_Local* ctx, int** cursor);
struct S00d94a80_Bool {
    bool m_cBooleanValue;
    S00d94a80_Bool(bool v) { m_cBooleanValue = v; }
};
void __cdecl hkSimpleContactConstraintDataBuildJacobian(char* atom, S00d94a80_Local* ctx, S00d94a80_Bool bCopy, int** cursor);
inline S00d94a80_Bool S00d94a80_True() { S00d94a80_Bool r(true); return r; }

struct S00d94a80_A0 {
    SubObj* unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    S00d94a80_Ctx m_ctx;
};

struct S00d94a80_Rec {
    char* unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned short unk14;
    unsigned short unk16;
    unsigned short unk18;
    unsigned short unk1a;
};

struct S00d94a80_Desc {
    int unk00;
    int unk04;
    char* end;
    int* c0;
    char* mon;
    int count;
    S00d94a80_Rec records[1];
};

struct S00d94a80_A2 {
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    S00d94a80_Desc* unk20;
    int unk24;
    unsigned char unk28;
};

struct ArgHandle {
    Arg2* p;
    ArgHandle(Arg2* q):p(q) {}
};

struct S00d94a80_TimerCmd {
    const char* m_name;
    unsigned int m_uiStartTicks;
    __forceinline void setTime()
    {
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        m_uiStartTicks = ticks;
    }
};

static __forceinline void S00d94a80_Process(Arg0* a1, Arg2* p)
{
    S00d94a80_Desc* desc = ((S00d94a80_A2*)p)->unk20;
    S00d94a80_Local base;
    base.head = ((S00d94a80_A0*)a1)->m_ctx;
    S00d94a80_Rec* rec = desc->records;
    char* mon = desc->mon;
    int count = desc->count;
    char* end = desc->end;
    int* c0 = desc->c0;
    base.unk94 = mon;
    bool flag = ((S00d94a80_A2*)p)->unk28 != 0 && desc->unk00 != 0;
    _ReadWriteBarrier();

    
    int* cursor = c0;
    if (count > 0) {
    int remaining = count;
    do {
        S00d94a80_Rec* r = rec++;
        base.head.unk38 = r->unk0c;
        base.head.unk3c = r->unk10;
        base.head.unk30 = (unsigned int)(end + r->unk18 * 128);
        base.head.unk34 = (unsigned int)(end + r->unk1a * 128);
        base.head.unk6c = r->unk18;
        base.head.unk70 = r->unk1a;
        base.head.unk60 = r->unk04;
        base.head.unk64 = r->unk08;
        base.head.unk74 = r->unk08;
        unsigned int w14 = r->unk14;
        char* atom = r->unk00;
        if (*(unsigned short*)atom == 0x16) {
            S00d94a80_Bool b(true);
            hkSimpleContactConstraintDataBuildJacobian(atom, &base, b, &cursor);
        } else {
            hkSolverBuildJacobianFromAtomsNotContact(atom, w14, &base, &cursor);
        }
    } while (--remaining);
    }

    int* c = cursor;
    if (!flag) {
        *c = 0;
    } else {
        int remain = (int)(base.unk94 - (char*)c);
        if (remain > 0) {
            *(float*)c += 1.1920928955078125e-07;
            c[1] = remain;
            *(unsigned char*)c = 2;
        }
    }

}

// @fnv 0x00d94a80
// src: COMMUNITY 0x00d94a80
void __cdecl hkCpuBuildJacobiansJob(Arg0* a1, Arg1* a2, Arg2* a3)
{
    hkMonitorStream* stream = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    char* cur = stream->m_end.m_storage;
    if (cur < stream->m_capacityMinus16.val()) {
        *(const char**)cur = str_010cc5c4;
        *(const char**)(cur + 0xc) = str_010d3ec8;
        ((S00d94a80_TimerCmd*)cur)->setTime();
        stream->m_end.m_storage = cur + 0x10;
    }

    S00d94a80_Process(a1, a3);
    stream = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    cur = stream->m_end.m_storage;
    if (cur < stream->m_capacityMinus16.val()) {
        *(const char**)cur = DAT_01076f38;
        ((S00d94a80_TimerCmd*)cur)->setTime();
        stream->m_end.m_storage = cur + 0xc;
    }

    a2->ProcessCallback(a3, a3, 0);
}

namespace fnv_00d86050 {
extern unsigned int DAT_0126835c;

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);

struct D86050Arr {
    void** m_pElements;          // +00
    unsigned short m_uiItemCount;  // +04
};

struct D86050Self {
    int unk00;
    hkpConstraintInstance* unk04;        // +04
};

struct D86050Stamps {
    unsigned int in;
    unsigned int out;
};

// src: GUESS 0x00d85d40 (confidence: low)
static __declspec(noinline) void Object_ProcessEntries_00d85d40(D86050Arr* arr) {
    for (int i = (int)arr->m_uiItemCount - 1; i >= 0; --i) {
        if (arr->m_pElements[i] == 0) {
            arr->m_uiItemCount = (unsigned short)(arr->m_uiItemCount - 1);
            for (int j = i; j < (int)arr->m_uiItemCount; ++j)
                arr->m_pElements[j] = arr->m_pElements[j + 1];
        }
    }
}

// Invokes the v06 callback on each non-null element of the indexed array, bracketing each call with TtconRepairedCb/Et profiler stamps, then compacts the array.
// @fnv 0x00d86050
// src: HAVOK_LIB 0x00d86050
void __cdecl hkpConstraintCallbackUtil_fireConstraintRepaired(D86050Self* self) {
    D86050Arr* arr = reinterpret_cast<D86050Arr*>(&self->unk04->m_kListeners);
    for (int i = (int)arr->m_uiItemCount - 1; i >= 0; --i) {
        if (arr->m_pElements[i] != 0) {
            volatile D86050Stamps stamp;
            hkMonitorStream* prof = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
            char* cur = prof->m_end.m_storage;
            if (cur < prof->m_capacityMinus16.m_storage) {
                *(const char**)cur = "TtconRepairedCb";
                _ReadWriteBarrier();
                stamp.in = (unsigned int)__rdtsc();
                *(unsigned int*)(cur + 4) = stamp.in;
                cur += 0xc;
                prof->m_end.m_storage = cur;
            }
            // The shared c18 slot has no event parameter declaration yet.
            typedef void (__thiscall* RepairedCallback)(hkpConstraintListener*, D86050Self*);
            hkpConstraintListener* listener = static_cast<hkpConstraintListener*>(arr->m_pElements[i]);
            (*reinterpret_cast<RepairedCallback**>(listener))[6](listener, self);
            prof = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
            cur = prof->m_end.m_storage;
            if (cur < prof->m_capacityMinus16.m_storage) {
                *(const char**)cur = "Et";
                _ReadWriteBarrier();
                stamp.out = (unsigned int)__rdtsc();
                *(unsigned int*)(cur + 4) = stamp.out;
                cur += 0xc;
                prof->m_end.m_storage = cur;
            }
        }
    }
    Object_ProcessEntries_00d85d40(arr);
}
}  // namespace fnv_00d86050

namespace fnv_00d87a10 {
#include <windows.h>

class FUN_00d87a10_Obj {
public:
    int unk00;
    int hkThread_getStatus();
};

// Returns 2 if the thread handle is null, otherwise queries the thread exit code and returns 1 if it equals 0x103, else 0.
// @fnv 0x00d87a10
// src: HAVOK_LIB 0x00d87a10
int FUN_00d87a10_Obj::hkThread_getStatus() {
    if (unk00 == 0)
        return 2;

    DWORD exitCode;
    GetExitCodeThread(reinterpret_cast<HANDLE>(static_cast<int>(unk00)), &exitCode);
    return exitCode == 0x103;
}
}  // namespace fnv_00d87a10

namespace fnv_00d94340 {
extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern unsigned long DAT_0126835c;

struct Arg_00d94340 {
    int unk00, unk04, unk08, unk0C, unk10;
    int m_iA;
    char* m_pcB;
};

void __cdecl ClearFlagsAndMarkDirty(int a, char* b);

class Target_00d94340 {
public:
    void ProcessCallback(Arg_00d94340* a, Arg_00d94340* b, int c);
};

// Records TtSplitIsle and Et timing markers via TLS stream, then calls pkTarget->ProcessCallback with pkArg twice and 0.
// @fnv 0x00d94340
// src: HAVOK_LIB 0x00d94340
void hkCpuSplitSimulationIslandJob(int unusedA, Target_00d94340* pkTarget, Arg_00d94340* pkArg)
{
    hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    hkTimerCommand_blk_00d80000_o2* c = reinterpret_cast<hkTimerCommand_blk_00d80000_o2*>(s->m_end.val());
    if (reinterpret_cast<char*>(c) < s->m_capacityMinus16.val()) {
        c->m_pCommandName = "TtSplitIsle";
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        c->m_ticks = t;
        s->m_end.m_storage = reinterpret_cast<char*>(c + 1);
    }
    ClearFlagsAndMarkDirty(pkArg->m_iA, pkArg->m_pcB + 0x5c);
    hkMonitorStream* s2 = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    hkTimerCommand_blk_00d80000_o2* c2 = reinterpret_cast<hkTimerCommand_blk_00d80000_o2*>(s2->m_end.val());
    if (reinterpret_cast<char*>(c2) < s2->m_capacityMinus16.val()) {
        c2->m_pCommandName = "Et";
        _ReadWriteBarrier();
        volatile unsigned int t2 = (unsigned int)__rdtsc();
        c2->m_ticks = t2;
        s2->m_end.m_storage = reinterpret_cast<char*>(c2 + 1);
    }
    pkTarget->ProcessCallback(pkArg, pkArg, 0);
}
}  // namespace fnv_00d94340

extern const float g_011c5874_arg1;
extern const float runtimeFloatSettingDefault262;
extern double DAT_01035718;

union F128U
{
    LocalM128 v;
    unsigned u[4];
};

static const F128U V4C = { { 196608.0f, 196608.0f, 196608.0f, 196608.0f } };

// Runs 23 bisection steps between g_011c5874_arg1 and runtimeFloatSettingDefault262 and returns the final midpoint minus DAT_01035718.
// @fnv 0x00d97440
// src: GUESS 0x00d97440 (confidence: medium)
float Object_ComputeBisectionMidpoint()
{
    float a = g_011c5874_arg1;
    float b = runtimeFloatSettingDefault262;
    for (int i = 0; i < 23; ++i)
    {
        float v = (float)((b + a) * 0.5);
        F128U t;
        t.v = _mm_add_ps(V4C.v, _mm_mul_ps(_mm_set_ps1(1.0f),
                                           _mm_add_ps(_mm_set_ps1(v),
                                                      _mm_load_ps((const float*)&DAT_01267e30))));
        if ((unsigned short)(t.u[0] >> 6) < 11)
            a = v;
        else
            b = v;
    }
    return (float)((b + a) * 0.5 - DAT_01035718);
}

extern "C" void _mm_store_ps(float* p, LocalM128 a);

extern int DAT_010d37e4;

struct FUN_00d84bd0
{
    unsigned int m_00;
    unsigned short unk04;
    volatile unsigned short m_06;
    volatile unsigned int m_08;
    unsigned int unk0c;
    volatile unsigned short m_10;
    unsigned short unk12;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    volatile float m_20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    volatile float m_34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    volatile float m_48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    volatile float m_60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    volatile float m_74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    volatile float m_88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    volatile unsigned short m_a0;
    volatile unsigned char m_a2;

    FUN_00d84bd0();
};

// Stores &DAT_010d37e4 at offset 0, sets m_06=1, m_10=2, m_a0=7, sets m_20/m_34/m_48 and m_60/m_74/m_88 to 1.0f, and zeroes the other 16-byte blocks.
// @fnv 0x00d84bd0
FUN_00d84bd0::FUN_00d84bd0()
{
    *(int**)this = &DAT_010d37e4;
    m_06 = 1;
    m_08 = 0;
    m_10 = 2;
    m_a0 = 7;
    _mm_store_ps((float*)((char*)this + 0x20), _mm_setzero_ps());
    _mm_store_ps((float*)((char*)this + 0x30), _mm_setzero_ps());
    _mm_store_ps((float*)((char*)this + 0x40), _mm_setzero_ps());
    m_20 = 1.0f;
    m_34 = 1.0f;
    m_48 = 1.0f;
    _mm_store_ps((float*)((char*)this + 0x50), _mm_setzero_ps());
    _mm_store_ps((float*)((char*)this + 0x60), _mm_setzero_ps());
    _mm_store_ps((float*)((char*)this + 0x70), _mm_setzero_ps());
    _mm_store_ps((float*)((char*)this + 0x80), _mm_setzero_ps());
    m_60 = 1.0f;
    m_74 = 1.0f;
    m_88 = 1.0f;
    _mm_store_ps((float*)((char*)this + 0x90), _mm_setzero_ps());
    m_a2 = 0;
}

extern "C" {
LocalM128 _mm_shuffle_ps(LocalM128,LocalM128,int);
LocalM128 _mm_add_ss(LocalM128,LocalM128);
LocalM128 _mm_mul_ps(LocalM128,LocalM128);
LocalM128 _mm_rsqrt_ss(LocalM128);
LocalM128 _mm_mul_ss(LocalM128,LocalM128);
LocalM128 _mm_cmpeq_ss(LocalM128,LocalM128);
LocalM128 _mm_set_ss(float);
LocalM128 _mm_andnot_ps(LocalM128,LocalM128);
LocalM128 _mm_sub_ss(LocalM128,LocalM128);
LocalM128 _mm_or_ps(LocalM128,LocalM128);
LocalM128 _mm_and_ps(LocalM128,LocalM128);
LocalM128 _mm_setzero_ps();
LocalM128 _mm_load_ss(const float*);
LocalM128 _mm_set_ps1(float);
LocalM128 _mm_cmpeq_ps(LocalM128,LocalM128);
LocalM128 _mm_unpackhi_ps(LocalM128,LocalM128);
LocalM128 _mm_rcp_ps(LocalM128);
LocalM128 _mm_add_ps(LocalM128,LocalM128);
LocalM128 _mm_cmple_ps(LocalM128,LocalM128);
LocalM128 _mm_cmplt_ps(LocalM128,LocalM128);
LocalM128 _mm_min_ps(LocalM128,LocalM128);
LocalM128 _mm_max_ps(LocalM128,LocalM128);
void _mm_store_ss(float*,LocalM128);
int _mm_movemask_ps(LocalM128);
}
extern "C" {
__m128i _mm_setzero_si128();
__m128i _mm_unpacklo_epi16(__m128i, __m128i);
__m128i _mm_unpackhi_epi16(__m128i, __m128i);
__m128i _mm_slli_epi32(__m128i, int);
__m128i _mm_srli_epi32(__m128i, int);
LocalM128 _mm_cvtepi32_ps(__m128i);
}

// Storage remains POD so that the aligned scratch vectors do not require /GS.
struct __declspec(align(16)) RayVector {
    union {
        LocalM128 simd;
        struct { float x, y, z, w; };
        float components[4];
    };
    __forceinline LocalM128 get() const { return simd; }
    __forceinline void set(LocalM128 v) { simd = v; }
    __forceinline const float& operator[](unsigned i) const { return components[i]; }
};
struct RayMask {
    LocalM128 simd;
    RayMask() {}
    RayMask(LocalM128 v) : simd(v) {}
    __forceinline LocalM128 get() const { return simd; }
    __forceinline void set(LocalM128 v) {simd=v;}
};
struct __declspec(align(16)) PackedVector { unsigned x,y,z,w; };
struct PrimitiveRecord {
    union {
        struct { unsigned pair0, pair1, pair2, pair3; };
        struct { unsigned short minX, minY, minZ, keyLow, maxX, maxY, maxZ, keyHigh; };
    };
};
struct TreeData {
    TreeNode* root;
    int field04, field08, stackCapacity;
    int field10, field14, field18;
    PrimitiveRecord* primitives;
    int field20, field24, field28, field2c;
    RayVector minimum, maximum;
};
struct RayCollector {
    virtual void unused();
    virtual FNV_00d99f50_Result report(unsigned key);
    virtual FNV_00d99f50_Result finish();
    virtual float fraction();
};
struct VectorRef { unsigned address; const RayVector* get() const { return reinterpret_cast<const RayVector*>(address); } const RayVector* operator->() const { return get(); } };
struct CollectorRef { RayCollector* p; RayCollector* operator->() const { return p; } };
struct OutputRef { unsigned address; void* get() const { return reinterpret_cast<void*>(address); } };
struct TraversalArena { unsigned char* current; };
struct TraversalEntry { TreeNode* node; float nearT, farT; unsigned reserved; };
extern const float DAT_01011d78, DAT_01017718, DAT_01016248;
extern const RayVector DAT_010c4c10;
extern const float DAT_010d4080, DAT_010cd644, DAT_0104e148, DAT_0104da48;
extern const double DAT_010217d0, DAT_01032980;

__forceinline LocalM128 dot3(LocalM128 v) {
    LocalM128 t = _mm_add_ss(_mm_shuffle_ps(v,v,0x55),v);
    return _mm_add_ss(_mm_shuffle_ps(v,v,0xaa),t);
}
__forceinline LocalM128 inverseLength3(const LocalM128& delta) {
    LocalM128 squared = _mm_mul_ps(delta,delta);
    LocalM128 lengthSquared = dot3(squared);
    LocalM128 estimate = _mm_rsqrt_ss(lengthSquared);
    LocalM128 correction = _mm_mul_ss(_mm_mul_ss(lengthSquared,estimate),estimate);
    LocalM128 inverseLength = _mm_andnot_ps(
        _mm_cmpeq_ss(lengthSquared,_mm_set_ss(0.0f)),
        _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f),estimate),_mm_sub_ss(_mm_set_ss(3.0f),correction)));
    return _mm_shuffle_ps(inverseLength,inverseLength,0);
}
__forceinline LocalM128 broadcast(float f) { RayVector v; v.x=f; v.y=f; v.z=f; v.w=f; return v.get(); }
__forceinline LocalM128 broadcast(double f) { RayVector v; v.x=(float)f; v.y=(float)f; v.z=(float)f; v.w=(float)f; return v.get(); }
__forceinline LocalM128 selectVector(LocalM128 mask,LocalM128 yes,LocalM128 no) {
    return _mm_or_ps(_mm_and_ps(mask,yes),_mm_andnot_ps(mask,no));
}

__forceinline LocalM128 convertUnsigned(const __m128i& v) {
    LocalM128 factor = {1.0e16f,1.0e16f,1.0e16f,1.0e16f};
    LocalM128 low = _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v,16),16));
    LocalM128 high = _mm_cvtepi32_ps(_mm_srli_epi32(v,16));
    return _mm_add_ps(_mm_mul_ps(high,factor),low);
}

__forceinline void decodeBox(const PrimitiveRecord* primitive, const RayVector& bias,
    const RayVector& scaleIn, RayVector& boxMin, RayVector& boxMax) {
            PackedVector packed;
            packed.x = primitive->pair0;
            packed.y = primitive->pair1;
            packed.z = primitive->pair2;
            packed.w = primitive->pair3;
            __m128i data = *reinterpret_cast<__m128i*>(&packed);
            __m128i izero = _mm_setzero_si128();
            __m128i low = _mm_unpacklo_epi16(data,izero);
            __m128i high = _mm_unpackhi_epi16(data,izero);
            LocalM128 firstHigh = convertUnsigned(low);
            LocalM128 secondHigh = convertUnsigned(high);
            LocalM128 decodeScale = _mm_mul_ps(scaleIn.get(),DAT_011b6de0);
            boxMin.set(_mm_add_ps(_mm_mul_ps(firstHigh,decodeScale),bias.get()));
            boxMax.set(_mm_add_ps(_mm_mul_ps(secondHigh,decodeScale),bias.get()));
 }
__forceinline bool intersectsBox(const RayVector& origin, const RayVector& inverseDirection,
    float nearT, float clippedEnd, const RayVector& boxMin, const RayVector& boxMax) {
    RayMask negativeDirection, parallelDirection; RayVector near4, far4;
    RayMask zeroMask(_mm_setzero_ps());
    negativeDirection.set(_mm_cmple_ps(zeroMask.get(),inverseDirection.get()));
    parallelDirection.set(_mm_cmpeq_ps(zeroMask.get(),inverseDirection.get()));
    LocalM128 nearValue = _mm_set_ps1(nearT);
    LocalM128 farValue = _mm_set_ps1(clippedEnd);
    near4.set(nearValue); far4.set(farValue);
    LocalM128 negativeLimit={-3.40282e38f,-3.40282e38f,-3.40282e38f,-3.40282e38f};
    LocalM128 positiveLimit={3.40282e38f,3.40282e38f,3.40282e38f,3.40282e38f};
            LocalM128 t0 = _mm_mul_ps(_mm_sub_ps(boxMin.get(),origin.get()),inverseDirection.get());
            LocalM128 t1 = _mm_mul_ps(_mm_sub_ps(boxMax.get(),origin.get()),inverseDirection.get());
            LocalM128 enter = selectVector(negativeDirection.get(),t0,t1);
            LocalM128 leave = selectVector(negativeDirection.get(),t1,t0);
            enter = _mm_or_ps(_mm_andnot_ps(parallelDirection.get(),enter),_mm_and_ps(parallelDirection.get(),negativeLimit));
            leave = _mm_or_ps(_mm_andnot_ps(parallelDirection.get(),leave),_mm_and_ps(parallelDirection.get(),positiveLimit));
            LocalM128 minLeave = _mm_min_ps(_mm_shuffle_ps(leave,leave,0),_mm_shuffle_ps(leave,leave,0x55));
            minLeave = _mm_min_ps(minLeave,_mm_shuffle_ps(leave,leave,0xaa));
            minLeave = _mm_min_ps(far4.get(),minLeave);
            LocalM128 maxEnter = _mm_max_ps(_mm_shuffle_ps(enter,enter,0),_mm_shuffle_ps(enter,enter,0x55));
            maxEnter = _mm_max_ps(maxEnter,_mm_shuffle_ps(enter,enter,0xaa));
            maxEnter = _mm_max_ps(near4.get(),maxEnter);
            LocalM128 hit = _mm_andnot_ps(parallelDirection.get(),_mm_cmplt_ps(maxEnter,minLeave));
            LocalM128 inside = _mm_and_ps(_mm_cmple_ps(origin.get(),boxMax.get()),_mm_cmple_ps(boxMin.get(),origin.get()));
            hit = _mm_or_ps(hit,_mm_and_ps(inside,parallelDirection.get()));
    return (_mm_movemask_ps(hit)&7)==7;
 }

__forceinline TreeNode readNode(TreeNode* p) { return *p; }
__forceinline TreeNode* leftChild(TreeNode* parent) {
    return reinterpret_cast<TreeNode*>(reinterpret_cast<char*>(parent) + (parent->flags & 0x7ffffffc));
}
__forceinline TreeNode* rightChild(TreeNode* parent) { return leftChild(parent) + 1; }
__forceinline unsigned leafStatus(unsigned flags) { return flags ^ 0x7fffffffU; }
__forceinline float minScalar(float a, float b) { return a < b ? a : b; }

__forceinline float decodeSplit(unsigned short s, float bias, float scale) { return (float)(s / DAT_010217d0 * scale + bias); }
namespace RayTraversal {
// Walks the tree along the ray from start to end, calling collector->report with the key of each primitive box hit, and returns collector->finish().
// @fnv 0x00d98ca0
// src: XBOX_PDB 0x00d98ca0
extern "C" FNV_00d99f50_Result __cdecl hkKdTreeUtils_castRayIterative(const TreeData* tree, const RayVector& start, const RayVector& end, RayCollector* collector) {
    PrimitiveRecord* primitives = tree->primitives;
    RayVector boundsMin = tree->minimum;
    RayVector extent; extent.set(_mm_sub_ps(tree->maximum.get(), tree->minimum.get()));
    TreeNode* node = tree->root;
    int capacity = tree->stackCapacity;
    if (capacity <= 0) capacity = 128;
    TreeNode state = readNode(node);
    TraversalArena* arena = reinterpret_cast<TraversalArena*>(hkMemoryRouter_getInstance());
    float nearT = 0.0f;
    TraversalEntry* stackBase = reinterpret_cast<TraversalEntry*>(arena->current);
    TraversalEntry* stackTop = stackBase;
    arena->current += (capacity * 16 + 127) & -128;

    LocalM128 delta = _mm_sub_ps(end.get(),start.get());
    LocalM128 squared = _mm_mul_ps(delta,delta);
    LocalM128 inverseLength = inverseLength3(delta);
    RayVector direction; direction.set(_mm_mul_ps(inverseLength,delta));
    float length;
    _mm_store_ss(&length,_mm_mul_ss(dot3(squared),inverseLength));
    float farT = length;
    RayVector origin = start;
    RayVector zeroVector; zeroVector.set(_mm_setzero_ps());
    RayVector parallel; parallel.set(_mm_cmpeq_ps(zeroVector.get(),direction.get()));
    LocalM128 safeDirection = selectVector(parallel.get(), DAT_010c7170, direction.get());
    safeDirection = _mm_shuffle_ps(safeDirection,_mm_unpackhi_ps(safeDirection,DAT_010c7170),0xc4);
    LocalM128 reciprocal = _mm_rcp_ps(safeDirection);
    reciprocal = _mm_sub_ps(_mm_add_ps(reciprocal,reciprocal),_mm_mul_ps(_mm_mul_ps(reciprocal,safeDirection),reciprocal));
    reciprocal = _mm_and_ps(reciprocal,DAT_010c4c10.get());
    RayVector inverseDirection; inverseDirection.set(selectVector(parallel.get(),zeroVector.get(),reciprocal));
    RayVector splitScale; splitScale.set(_mm_mul_ps(_mm_mul_ps(inverseDirection.get(),extent.get()),broadcast(DAT_010d4080)));
    RayVector splitOffset; splitOffset.set(_mm_mul_ps(_mm_sub_ps(boundsMin.get(),origin.get()),inverseDirection.get()));
    float bound = collector->fraction() * length;
    float clippedEnd = bound < farT ? bound : farT;
    if ((_mm_movemask_ps(parallel.get()) & 7) != 7) {
        unsigned axis, axisMask, parallelBits;
        TreeNode* sibling;
        const PrimitiveRecord* primitive;

        for (;;) {
            while ((state.flags & 0x80000000u) != 0) {
                RayVector z; z.set(_mm_setzero_ps()); parallelBits = _mm_movemask_ps(_mm_cmpeq_ps(z.simd,direction.simd));
                TreeNode* left = leftChild(node);
                sibling = rightChild(node);

                axis = state.flags & 3;
                
                axisMask = DAT_010c92e0[axis];
                if ((parallelBits & axisMask) == axisMask) {
            {
                int lo = (unsigned short)state.bounds;
                float lower = decodeSplit((unsigned short)lo,boundsMin[axis],extent[axis]);
                
                int hi = state.bounds >> 16;
                float upper = decodeSplit((unsigned short)hi,boundsMin[axis],extent[axis]);
                const float margin = 0.0001f;
                upper = (float)(upper + margin);
                int inLeft = origin[axis] <= upper;
                
                lower = (float)(lower - margin);
                int inRight = origin[axis] >= lower;
                if (inLeft && inRight) {
                    node = left;
                    stackTop->node = sibling;
                    stackTop->nearT = nearT;
                    stackTop->farT = farT;
                    ++stackTop;
                } else if (inLeft || inRight) {
                    node = inLeft ? left : sibling;
                } else goto pop_node;
            }
                    state = readNode(node);
                    continue;
                }
        {
            int lo = (unsigned short)state.bounds;
            float lower = (float)(lo * splitScale[axis] + splitOffset[axis]);
            int hi = state.bounds >> 16;
            float upper = (float)(hi * splitScale[axis] + splitOffset[axis]);
            TreeNode* pNodeFirstChild;
            TreeNode* pNodeSecondChild;
            unsigned positive = _mm_movemask_ps(_mm_cmplt_ps(_mm_setzero_ps(),direction.get()));
            if ((positive & DAT_010c92e0[axis]) == DAT_010c92e0[axis]) {
                pNodeFirstChild = left;
                pNodeSecondChild = sibling;
            } else {
                pNodeFirstChild = sibling;
                pNodeSecondChild = left;
                float tmp = lower; lower = upper; upper = tmp;
            }
            node = pNodeSecondChild;
            if (!(upper < nearT)) {
                if (lower > clippedEnd) node = pNodeFirstChild;
                else {
                float savedNear = lower > nearT ? lower : nearT;
                stackTop->node = node;
                stackTop->nearT = savedNear;
                stackTop->farT = farT;
                ++stackTop;
                node = pNodeFirstChild;
                if (upper < farT) farT = upper;
                clippedEnd = minScalar(collector->fraction() * length, farT);
                }
            }
            state = readNode(node);
            continue;
        }

            }
            if (leafStatus(state.flags) != 0 && (int)state.bounds > 0) {
        for (int primitiveIndex = 0; primitiveIndex < (int)state.bounds; ++primitiveIndex) {
            primitive = primitives + (state.flags & 0x7fffffff) + primitiveIndex;
            union KeyParts { struct { unsigned short low, high; }; unsigned value; } key;
            key.low = primitive->keyLow;
            key.high = primitive->keyHigh;
            RayVector boxMin, boxMax;
            decodeBox(primitive,boundsMin,extent,boxMin,boxMax);
            if (intersectsBox(origin,inverseDirection,nearT,clippedEnd,boxMin,boxMax)) {
                collector->report(key.value);
            }
        }

            }
        pop_node:
            if (stackTop != stackBase) {
                --stackTop;
                node = stackTop->node;
                farT = stackTop->farT;
                nearT = stackTop->nearT;
                state = readNode(node);
                clippedEnd = minScalar(collector->fraction() * length, farT);
                if (clippedEnd <= nearT) goto pop_node;
                continue;
            }
            break;
        }
    }
    reinterpret_cast<TraversalArena*>(hkMemoryRouter_getInstance())->current = reinterpret_cast<unsigned char*>(stackBase);
    return collector->finish();
}

}
