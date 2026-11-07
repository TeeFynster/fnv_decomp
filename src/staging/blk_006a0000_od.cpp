#include "../../include/NavMeshTriangle.h"
#include "../../include/NiColorA.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiTMapBase.h"
#include "../../include/DFALL.h"
#include "../../include/NiPointer.h"

// src/staging/blk_006a0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/BSSimpleArray.h"
#include "../../include/NavMeshEdgePoint.h"
// PathPoint_blk_006a0000_od: local type (was include/PathPoint.h, which had no evidence of one real class); its methods are 0x004941c0 NiPoint3::operator/=, 0x00595c80 NiPoint3::SqrXYLength
#include "../../include/NiPoint3.h"

class PathPoint_blk_006a0000_od
{
public:
    float x;
    float y;
    float z;

    PathPoint_blk_006a0000_od();
    PathPoint_blk_006a0000_od(float, float, float);

    PathPoint_blk_006a0000_od operator+(const PathPoint_blk_006a0000_od& pt) const;
    PathPoint_blk_006a0000_od operator*(float fScalar) const;
    void ScaleByInverse(float);
    float GetSquaredXYLength();
    NiPoint3 FastNavMeshTriLocation_GetLocation();
};
#include "../../include/PathNodeArray.h"
#include "../../include/NiPoint2.h"
#include "../../include/GO.h"
#include "../../include/NP.h"
#include "../../include/NiPoint3.h"
#include "../../include/hkQuaternion.h"
#include "../../include/NavMesh.h"
#include "../../include/NavMeshPtr.h"
#include "../../include/NavMeshSearch.h"
#include "../../include/NiBound.h"
#include "../../include/NavMeshEdgeData.h"
#include "../../include/ObstacleData.h"
#include "../../include/PathingLocation.h"
#include "../../include/BSShaderNoLightingProperty.h"
// Trivial point storage used by this unit's original unoptimized routines.
struct Point3Storage
{
    float x, y, z;
    Point3Storage& operator+=(const Point3Storage&);
};



struct Ret559
{
    bool FUN_00697730();
};

struct S006949d0
{
    void* GetAt(int);
    void* GetFirst();
};

// @fnv 0x006a1420
void* S006949d0::GetFirst()
{
    return GetAt(0);
}

struct FUN_006a1490_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int EvaluateValue_006a1490(int index);
};

// @fnv 0x006a1490
// src: GUESS 0x006a1490 (confidence: low)
int FUN_006a1490_class::EvaluateValue_006a1490(int index)
{
    return index * 0x24 + m_iWordAt04;
}

extern int DAT_0106b3b0;
struct GlobalObject_00869f00
{
    int* vft;
    void __thiscall Clear(bool);
    void __thiscall ResetVirtualTableAndClear_006a14e0();
};
// @fnv 0x006a14e0
// src: GUESS 0x006a14e0 (confidence: medium)
void __thiscall GlobalObject_00869f00::ResetVirtualTableAndClear_006a14e0()
{
    vft = &DAT_0106b3b0;
    Clear(true);
}

extern int DAT_0106b3d4;
struct FUN_006a16d0_class
{
    void* vtbl;
    void FUN_006a20a0(int, int);
    FUN_006a16d0_class* BSSimpleArray_BSSimpleArray_NavMeshPOV_1024_1024_BSSimpleArray_BSSimpleArray_NavMeshPOV_1024_1024();
};
// Sets the vtbl to DAT_0106b3d4, calls FUN_006a20a0(0, 0), and returns this.
// @fnv 0x006a16d0
// src: COMMUNITY 0x006a16d0
FUN_006a16d0_class* FUN_006a16d0_class::BSSimpleArray_BSSimpleArray_NavMeshPOV_1024_1024_BSSimpleArray_BSSimpleArray_NavMeshPOV_1024_1024()
{
    vtbl = &DAT_0106b3d4;
    FUN_006a20a0(0, 0);
    return this;
}

extern int DAT_0106b3d4;
struct FUN_006a1700_class
{
    int* p;
    void FUN_0049faf0(int a);
    void UpdateFields_006a1700();
};
// @fnv 0x006a1700
// src: GUESS 0x006a1700 (confidence: low)
void FUN_006a1700_class::UpdateFields_006a1700()
{
    p = &DAT_0106b3d4;
    FUN_0049faf0(1);
}

extern int DAT_0106b3e8;

struct Dummy_0061bf20
{
    void BSSimpleArray_NavMeshPOVSearchNode_1024_InitialSetup(int, int);
    void* BSSimpleArray_NavMeshPOVSearchNode_1024_BSSimpleArray_NavMeshPOVSearchNode_1024();
};

// @fnv 0x006a1860
// src: COMMUNITY 0x006a1860
void* Dummy_0061bf20::BSSimpleArray_NavMeshPOVSearchNode_1024_BSSimpleArray_NavMeshPOVSearchNode_1024()
{
    *(int*)this = (int)&DAT_0106b3e8;
    BSSimpleArray_NavMeshPOVSearchNode_1024_InitialSetup(0, 0);
    return this;
}

extern int DAT_0106b3fc;
struct S_006b3610
{
    void BSSimpleArray_NavMeshPOVSearchLink_1024_InitialSetup(int, int);
};
struct FUN_006a18b0_class
{
    int* vtable;
    S_006b3610* BSSimpleArray_NavMeshPOVSearchLink_1024_BSSimpleArray_NavMeshPOVSearchLink_1024();
};
// Sets the vtable pointer to DAT_0106b3fc, calls FUN_006a2130 with 0, 0, and returns this as an S_006b3610 pointer.
// @fnv 0x006a18b0
// src: COMMUNITY 0x006a18b0
S_006b3610* FUN_006a18b0_class::BSSimpleArray_NavMeshPOVSearchLink_1024_BSSimpleArray_NavMeshPOVSearchLink_1024()
{
    vtable = &DAT_0106b3fc;
    reinterpret_cast<S_006b3610*>(this)->BSSimpleArray_NavMeshPOVSearchLink_1024_InitialSetup(0, 0);
    return reinterpret_cast<S_006b3610*>(this);
}

namespace fnv_006a18e0 {
extern int DAT_0106b3fc;
struct GlobalObject_00869f00
{
    int* data;
    void Clear(bool);
    void ResetVirtualTableAndClear_006a18e0();
};
// @fnv 0x006a18e0
// src: GUESS 0x006a18e0 (confidence: medium)
void GlobalObject_00869f00::ResetVirtualTableAndClear_006a18e0()
{
    this->data = &DAT_0106b3fc;
    this->Clear(true);
}
}  // namespace fnv_006a18e0

void* _Reallocate(void* base, unsigned int count);

struct FUN_006a1900_Class
{
    void* __thiscall _Reallocate_Thunk(void* base, unsigned int count);
};

// @fnv 0x006a1900
// src: GUESS 0x006a1900 (confidence: medium)
void* __thiscall FUN_006a1900_Class::_Reallocate_Thunk(void* base, unsigned int count)
{
    return _Reallocate(base, count << 6);
}

extern int DAT_0106b410;

struct FUN_0049faf0
{
    void Call(int);
};

struct FUN_006a19e0
{
    int m;
    void Init();
};

// @fnv 0x006a19e0
void FUN_006a19e0::Init()
{
    m = (int)&DAT_0106b410;
    ((FUN_0049faf0*)this)->Call(1);
}

extern "C" void* DAT_0106b424;

struct FUN_006a1a00_class
{
    void* vtable;
    void UpdateState_006a2470(int, int);
    FUN_006a1a00_class* BSSimpleArray_RemoveIndex_1024_BSSimpleArray_RemoveIndex_1024();
};

// Sets the vtable to DAT_0106b424, calls FUN_006a2470 with 0, 0, and returns this.
// @fnv 0x006a1a00
// src: COMMUNITY 0x006a1a00
FUN_006a1a00_class* FUN_006a1a00_class::BSSimpleArray_RemoveIndex_1024_BSSimpleArray_RemoveIndex_1024()
{
    vtable = &DAT_0106b424;
    UpdateState_006a2470(0, 0);
    return this;
}

namespace fnv_006a1a30 {
extern int DAT_0106b424;

struct GlobalObject_00869f00
{
    void Clear(bool);
};

struct FUN_006a1a30_class
{
    GlobalObject_00869f00* m_p;
    void UpdateState_006a1a30();
};

// @fnv 0x006a1a30
// src: GUESS 0x006a1a30 (confidence: low)
void FUN_006a1a30_class::UpdateState_006a1a30()
{
    m_p = (GlobalObject_00869f00*)&DAT_0106b424;
    ((GlobalObject_00869f00*)this)->Clear(true);
}
}  // namespace fnv_006a1a30

struct FUN_006a1b20_class
{
    void __thiscall MatchesPair(int);
};

// @fnv 0x006a1b00
void __cdecl CallMethodOnObject(int pObject, int b)
{
    ((FUN_006a1b20_class*)pObject)->MatchesPair(b);
}

struct FUN_006a1b60_Class
{
    void* GetField54();
};

// @fnv 0x006a1b60
void* FUN_006a1b60_Class::GetField54()
{
    return *(void**)((char*)this + 0x54);
}

extern unsigned int DAT_010a2720;

struct ScrapHeapBuffer
{
    void* Allocate(unsigned int a, unsigned int b);
};

// @fnv 0x006a1f90
// src: GUESS 0x006a1f90 (confidence: low)
void* Runtime_ForwardCall_006a1f90(unsigned int auiSize, ScrapHeapBuffer* heap)
{
    return heap->Allocate(auiSize, DAT_010a2720);
}

namespace fnv_006a2580 {
extern int DAT_0106b44c;

struct GlobalObject_00869f00
{
    void* p;
    void Clear(bool);
    void ResetVirtualTableAndClear_006a2580();
};

// @fnv 0x006a2580
// src: GUESS 0x006a2580 (confidence: medium)
void GlobalObject_00869f00::ResetVirtualTableAndClear_006a2580()
{
    p = &DAT_0106b44c;
    Clear(true);
}
}  // namespace fnv_006a2580

extern int DAT_0106b44c;

struct AX
{
    void BSSimpleArray_float_1024_InitialSetup(unsigned int, unsigned int);
    AX* BSSimpleArray_AStarNode_NavMeshPOVSearchNode_NavMeshPOVSearchLink_1024_BSSimpleArray_AStarNode_NavMeshPOVSearchNode_NavMeshPOVSearchLink_1024();
};

// @fnv 0x006a2850
// src: COMMUNITY 0x006a2850
AX* AX::BSSimpleArray_AStarNode_NavMeshPOVSearchNode_NavMeshPOVSearchLink_1024_BSSimpleArray_AStarNode_NavMeshPOVSearchNode_NavMeshPOVSearchLink_1024()
{
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_0106b44c);
    this->BSSimpleArray_float_1024_InitialSetup(0, 0);
    return this;
}

extern int DAT_0106b460;
struct FUN_006dc440_class
{
    void BSSimpleArray_NavMeshTriHandle_1024_InitialSetup(int, int);
    FUN_006dc440_class* BSSimpleArray_FastNavMeshVertHandle_1024_BSSimpleArray_FastNavMeshVertHandle_1024();
};
// @fnv 0x006a2880
// src: COMMUNITY 0x006a2880
FUN_006dc440_class* FUN_006dc440_class::BSSimpleArray_FastNavMeshVertHandle_1024_BSSimpleArray_FastNavMeshVertHandle_1024()
{
    *(int*)this = (int)&DAT_0106b460;
    this->BSSimpleArray_NavMeshTriHandle_1024_InitialSetup(0, 0);
    return this;
}

extern "C" void* __cdecl Reallocate(void* p, int size);

struct FUN_006a28b0_Class
{
    void* __thiscall BSSimpleArray_Resize8BytesMembers(int m, int n);
};

// @fnv 0x006a28b0
// src: COMMUNITY 0x006a28b0
void* __thiscall FUN_006a28b0_Class::BSSimpleArray_Resize8BytesMembers(int m, int n)
{
    return Reallocate((void*)m, n * 8);
}

extern int DAT_0106b52c;
struct FUN_006a6290_class
{
    void NiTMapBase_DFALL_NiTMapItem_NavMesh_NiPointer_NiNode_NavMesh_NiPointer_NiNode_NiTMapBase_DFALL_NiTMapItem_NavMesh_NiPointer_NiNode_NavMesh_NiPointer_NiNode(int a);
    void* vfn;
    FUN_006a6290_class* NiTMap_NavMesh_NiPointer_NiNode_NiTMap(int a);
};
// Calls FUN_006a6370 with the argument, sets vfn to DAT_0106b52c, and returns this.
// @fnv 0x006a6290
// src: EXE 0x006a6290
FUN_006a6290_class* FUN_006a6290_class::NiTMap_NavMesh_NiPointer_NiNode_NiTMap(int a)
{
    NiTMapBase_DFALL_NiTMapItem_NavMesh_NiPointer_NiNode_NavMesh_NiPointer_NiNode_NiTMapBase_DFALL_NiTMapItem_NavMesh_NiPointer_NiNode_NavMesh_NiPointer_NiNode(a);
    vfn = &DAT_0106b52c;
    return this;
}

struct FUN_006a62c0_class
{
    int* m_p;
    void __thiscall ConstructIntArray(int arg);
    FUN_006a62c0_class* NiTMap_TESObjectCELL_NiPointer_NiNode_NiTMap(int arg);
};

// Calls ConstructIntArray with arg, sets m_p to the string "@cj", and returns this.
// @fnv 0x006a62c0
// src: EXE 0x006a62c0
FUN_006a62c0_class* FUN_006a62c0_class::NiTMap_TESObjectCELL_NiPointer_NiNode_NiTMap(int arg)
{
    ConstructIntArray(arg);
    m_p = (int*)"@cj";
    return this;
}

struct Dummy0042f800
{
    void FUN_0042fcb0(int, int);
    void* __thiscall BSSimpleArray_NiPoint3_1024_BSSimpleArray_NiPoint3_1024(int a);
};

extern int DAT_010159d4;

// @fnv 0x006a65e0
// src: XBOX_PDB 0x006a65e0
void* __thiscall Dummy0042f800::BSSimpleArray_NiPoint3_1024_BSSimpleArray_NiPoint3_1024(int a)
{
    *(int**)this = &DAT_010159d4;
    FUN_0042fcb0(a, a);
    return this;
}

namespace fnv_006a6640 {
struct GlobalObject_00869f00
{
    const char* m_p;
    void Clear(bool);
    void SetPhjAndClear();
};

// @fnv 0x006a6640
void GlobalObject_00869f00::SetPhjAndClear()
{
    m_p = "Phj";
    Clear(true);
}
}  // namespace fnv_006a6640

extern int DAT_0106b5c0;
struct S006d0420
{
    void BSSimpleArray_char_1024_InitialSetup(int, int);
    S006d0420* BSSimpleArray_unsigned_char_1024_BSSimpleArray_unsigned_char_1024(int a);
};
// Stores the address of DAT_0106b5c0 into this object, calls FUN_0069b940 with a twice, and returns this.
// @fnv 0x006a67a0
// src: COMMUNITY 0x006a67a0
S006d0420* S006d0420::BSSimpleArray_unsigned_char_1024_BSSimpleArray_unsigned_char_1024(int a)
{
    *(int*)this = (int)&DAT_0106b5c0;
    BSSimpleArray_char_1024_InitialSetup(a, a);
    return this;
}

namespace fnv_006a67d0 {
extern int DAT_0106b5c0;

struct GlobalObject_00869f00
{
    void Clear(bool);
    void SetVtableAndProcessState_006a67d0();
};

// @fnv 0x006a67d0
// src: GUESS 0x006a67d0 (confidence: low)
void GlobalObject_00869f00::SetVtableAndProcessState_006a67d0()
{
    *reinterpret_cast<void**>(this) = &DAT_0106b5c0;
    Clear(true);
}
}  // namespace fnv_006a67d0

struct FUN_006a68b0_Class
{
    void ForwardCall_006a68d0();
    void ForwardCall_006a68b0();
};

// @fnv 0x006a68b0
// src: GUESS 0x006a68b0 (confidence: low)
void FUN_006a68b0_Class::ForwardCall_006a68b0()
{
    ForwardCall_006a68d0();
}

namespace fnv_006a85b0 {
extern int DAT_0106b688;

struct GlobalObject_00869f00
{
    void Clear(bool);
};

struct FUN_006a85b0_Class
{
    void SetVtableAndProcessState_006a85b0();
};

// @fnv 0x006a85b0
// src: GUESS 0x006a85b0 (confidence: low)
void FUN_006a85b0_Class::SetVtableAndProcessState_006a85b0()
{
    *(int*)this = (int)&DAT_0106b688;
    ((GlobalObject_00869f00*)this)->Clear(true);
}
}  // namespace fnv_006a85b0

namespace fnv_006a8a00 {
struct AX
{
    void BSSimpleArray_float_1024_InitialSetup(unsigned int, unsigned int);
};
extern int DAT_0106b688;
struct FUN_006a8a00 : AX
{
    AX* Init();
};
// @fnv 0x006a8a00
AX* FUN_006a8a00::Init()
{
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_0106b688);
    BSSimpleArray_float_1024_InitialSetup(0, 0);
    return this;
}
}  // namespace fnv_006a8a00

struct FUN_006a9520_Class
{
    bool PathingLocation_QUnused();
};

// @fnv 0x006a9520
// src: XBOX_PDB 0x006a9520
bool FUN_006a9520_Class::PathingLocation_QUnused()
{
    return (reinterpret_cast<const unsigned char*>(this)[0x26] & 2) > 0;
}

struct FUN_006a9560_Class
{
    unsigned char GetByteAtOffset9B() const;
};

// @fnv 0x006a9560
unsigned char FUN_006a9560_Class::GetByteAtOffset9B() const
{
    return ((const unsigned char*)this)[0x9b];
}

namespace fnv_006b42a0 {
extern int DAT_0106ba94;
struct GlobalObject_00869f00
{
    void Clear(bool);
    void ResetVirtualTableAndClear_006b42a0();
};
// @fnv 0x006b42a0
// src: GUESS 0x006b42a0 (confidence: medium)
void GlobalObject_00869f00::ResetVirtualTableAndClear_006b42a0()
{
    *reinterpret_cast<int*>(this) = (int)&DAT_0106ba94;
    Clear(true);
}
}  // namespace fnv_006b42a0

namespace fnv_006b4670 {
struct AX
{
    void BSSimpleArray_float_1024_InitialSetup(unsigned int, unsigned int);
};
extern int DAT_0106ba94;
struct FUN_006b4670_class
{
    AX* SetVtableAndProcessState_006b4670();
};
// @fnv 0x006b4670
// src: GUESS 0x006b4670 (confidence: low)
AX* FUN_006b4670_class::SetVtableAndProcessState_006b4670()
{
    *(int*)this = (int)&DAT_0106ba94;
    ((AX*)this)->BSSimpleArray_float_1024_InitialSetup(0, 0);
    return (AX*)this;
}
}  // namespace fnv_006b4670

extern "C" void __cdecl Deallocate(void*);

struct FUN_006b8310_class
{
    void __thiscall FreeMemory(void* p);
};

// Calls Deallocate on the given pointer to release its memory.
// @fnv 0x006b8310
void __thiscall FUN_006b8310_class::FreeMemory(void* apMemory)
{
    void* a = apMemory;
    Deallocate(a);
}

struct FUN_00aa5410_Helper
{
    int InitWithAlignedSize(unsigned int);
};

struct FUN_006b9400_Class
{
    int AStarNodeHeap_AStarNodeHeap_0();
};

// @fnv 0x006b9400
// src: COMMUNITY 0x006b9400
int FUN_006b9400_Class::AStarNodeHeap_AStarNodeHeap_0()
{
    ((FUN_00aa5410_Helper*)this)->InitWithAlignedSize(0x4800);
    return (int)this;
}



struct FUN_006bb510_shell
{
    Point3Storage a;
    Point3Storage b;
    Point3Storage c;
    void AddToPoints(Point3Storage* p);
};

// Adds the given point to both stored points a and b.
// @fnv 0x006bb510
void FUN_006bb510_shell::AddToPoints(Point3Storage* apPoint)
{
    a += *apPoint;
    b += *apPoint;
}

struct FUN_006bec20_Class
{
    void* m_p;
    void* __thiscall RebuildTriangleList();
    void* NavMeshObstacleCutter_UpdateCoverArray();
};

// @fnv 0x006bec20
// src: COMMUNITY 0x006bec20
void* FUN_006bec20_Class::NavMeshObstacleCutter_UpdateCoverArray()
{
    return reinterpret_cast<FUN_006bec20_Class*>(m_p)->RebuildTriangleList();
}

struct FUN_006bf670_Class
{
    int* GetElementAddress_006bf670(int a);
};

// @fnv 0x006bf670
// src: GUESS 0x006bf670 (confidence: low)
int* FUN_006bf670_Class::GetElementAddress_006bf670(int aiIndex)
{
    return (int*)((char*)*(int*)((char*)this + 4) + aiIndex * 0x1c);
}

namespace fnv_006bf690 {
extern int DAT_0106c2e8;

struct Dummy_0061bf20
{
    void* vtbl;
    void BSSimpleArray_NavMeshPOVSearchNode_1024_InitialSetup(int, int);
    Dummy_0061bf20* InitWithVtbl(int a, int b);
};

// Sets the object's vtbl to DAT_0106c2e8, calls FUN_006b3f40 with a and b, and returns this.
// @fnv 0x006bf690
Dummy_0061bf20* __thiscall Dummy_0061bf20::InitWithVtbl(int aiArg1, int aiArg2)
{
    vtbl = &DAT_0106c2e8;
    BSSimpleArray_NavMeshPOVSearchNode_1024_InitialSetup(aiArg1, aiArg2);
    return this;
}
}  // namespace fnv_006bf690

namespace fnv_006bf6c0 {
extern int DAT_0106c2e8;
struct GlobalObject_00869f00
{
    void Clear(bool);
    void ResetVirtualTableAndClear_006bf6c0();
};
void GlobalObject_00869f00::Clear(bool b)
{}
// @fnv 0x006bf6c0
// src: GUESS 0x006bf6c0 (confidence: medium)
void GlobalObject_00869f00::ResetVirtualTableAndClear_006bf6c0()
{
    *(int*)this = (int)&DAT_0106c2e8;
    Clear(true);
}
}  // namespace fnv_006bf6c0

namespace fnv_006bf710 {
extern int DAT_0106c2fc;

struct GlobalObject_00869f00
{
    void Clear(bool);
    void SetVtableAndProcessState_006bf710();
};

// @fnv 0x006bf710
// src: GUESS 0x006bf710 (confidence: low)
void GlobalObject_00869f00::SetVtableAndProcessState_006bf710()
{
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_0106c2fc);
    Clear(true);
}
}  // namespace fnv_006bf710

struct FUN_006bf780_class
{
    void* __thiscall AllocateBlock(int n);
};

// @fnv 0x006bf780
void* __thiscall FUN_006bf780_class::AllocateBlock(int aiCount)
{
    void* p = operator new(aiCount * 0x1c);
    return p;
}

namespace fnv_006bf7b0 {
extern "C" void* __cdecl Reallocate(void*, size_t);

struct FUN_006bf7b0_Class
{
    void* __thiscall Reallocate_Thunk(int n, int m);
};

// @fnv 0x006bf7b0
// src: GUESS 0x006bf7b0 (confidence: medium)
void* __thiscall FUN_006bf7b0_Class::Reallocate_Thunk(int n, int m)
{
    return Reallocate(reinterpret_cast<void*>(n), m * 0x1c);
}
}  // namespace fnv_006bf7b0

namespace fnv_006bfab0 {
extern int DAT_0106c34c;

struct GlobalObject_00869f00
{
    void Clear(bool);
    void SetVtableAndProcessState_006bfab0();
};

// @fnv 0x006bfab0
// src: GUESS 0x006bfab0 (confidence: low)
void GlobalObject_00869f00::SetVtableAndProcessState_006bfab0()
{
    *(int**)((char*)this + 0) = (int*)&DAT_0106c34c;
    Clear(true);
}
}  // namespace fnv_006bfab0

struct FUN_006bfb90_class
{
    void __thiscall AreValuesEqual_006bfb90(int);
};

// @fnv 0x006bfb70
void CallWithInt(FUN_006bfb90_class* pObject, int iValue)
{
    pObject->AreValuesEqual_006bfb90(iValue);
}

namespace fnv_006bff00 {
extern void* DAT_0106c324;
struct AX
{
    void __thiscall BSSimpleArray_float_1024_InitialSetup(unsigned int, unsigned int);
    AX* __thiscall BSSimpleArray_NavMeshObstacleVertex_1024_BSSimpleArray_NavMeshObstacleVertex_1024();
};
// @fnv 0x006bff00
// src: COMMUNITY 0x006bff00
AX* __thiscall AX::BSSimpleArray_NavMeshObstacleVertex_1024_BSSimpleArray_NavMeshObstacleVertex_1024()
{
    *reinterpret_cast<void**>(this) = &DAT_0106c324;
    BSSimpleArray_float_1024_InitialSetup(0, 0);
    return this;
}
}  // namespace fnv_006bff00

extern int DAT_0106b56c;
void __cdecl NiFreeAlias(void*);
// RTTI at vftable 0x0106b56c identifies the DFALL map base for NavMesh* to NiPointer<NiNode>.
typedef NiTMapBase<DFALL<NiTMapItem<NavMesh*, NiPointer<NiNode> > >, NavMesh*, NiPointer<NiNode> > NavMeshSceneNodeMapBase;
// @fnv 0x006a64b0
template <> NavMeshSceneNodeMapBase::~NiTMapBase()
{
    RemoveAll();
    NiFreeAlias(m_ppkHashTable);
}

extern void NiFreeAlias(void*);
extern int DAT_0106c194;
struct FUN_006b8030_class
{
    void __thiscall RemoveAll();
    void __thiscall SetVtableAndProcessState_006b8030();
};
// @fnv 0x006b8030
// src: GUESS 0x006b8030 (confidence: low)
void __thiscall FUN_006b8030_class::SetVtableAndProcessState_006b8030()
{
    *reinterpret_cast<int**>(this) = &DAT_0106c194;
    RemoveAll();
    NiFreeAlias(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 8));
}

void NiFreeAlias(void*);
extern int DAT_0106c1b4;

struct FUN_006b8130 : NiTPointerMap<int, int>
{
    void Method();
};

// @fnv 0x006b8130
void FUN_006b8130::Method()
{
    *reinterpret_cast<int**>(this) = &DAT_0106c1b4;
    RemoveAll();
    NiFreeAlias(reinterpret_cast<void*>(reinterpret_cast<int*>(this)[2]));
}

namespace fnv_006b8250 {
extern void* DAT_0106c1d4;
extern "C" void NiFreeAlias(void*);

struct FUN_006b8250
{
    void* m_vt;
    int m_kPointA;
    void* m_kPointB;
    void RemoveAll();
    void Init();
};

// @fnv 0x006b8250
void FUN_006b8250::Init()
{
    m_vt = &DAT_0106c1d4;
    RemoveAll();
    NiFreeAlias(m_kPointB);
}
}  // namespace fnv_006b8250

struct FUN_006a0520_class
{
    float m_iWordAt00;
    float m_iWordAt04;
    Point3Storage& MultiplyXYComponents(const Point3Storage& o);
};
// @fnv 0x006a0520
// src: GUESS 0x006a0520 (confidence: medium)
Point3Storage& FUN_006a0520_class::MultiplyXYComponents(const Point3Storage& o)
{
    float a = m_iWordAt00;
    float b5 = m_iWordAt04;
    m_iWordAt00 = a * o.x - b5 * o.y;
    m_iWordAt04 = b5 * o.x + a * o.y;
    return *(Point3Storage*)this;
}

void __cdecl Object_Equals_Thunk();
struct S006a1460
{
    int __thiscall FindMatchingEntry(int a, int b, void(__cdecl* c)());
    bool __thiscall ProcessAndTransformResult_006a1460(int a);
};
// @fnv 0x006a1460
// src: GUESS 0x006a1460 (confidence: low)
bool __thiscall S006a1460::ProcessAndTransformResult_006a1460(int a)
{
    return FindMatchingEntry(a, 0, Object_Equals_Thunk) != -1;
}

struct FUN_006a19b0
{
    int* m_iWordAt00;
    void __thiscall UpdateState_006a2310(int, int);
    FUN_006a19b0(int);
};
// @fnv 0x006a19b0
FUN_006a19b0::FUN_006a19b0(int aiValue)
{
    m_iWordAt00 = &DAT_0106b410;
    UpdateState_006a2310(aiValue, aiValue);
}

struct FUN_006a1aa0_class
{
    int m_iWordAt00;
    void* m_iWordAt04;
    int m_8;
    int FindMatchingEntry(int b, unsigned int a, unsigned char (*cb)(int, int));
};

// @fnv 0x006a1aa0
int FUN_006a1aa0_class::FindMatchingEntry(int b, unsigned int uiStartIndex, unsigned char (*cb)(int, int))
{
    for (unsigned int i = uiStartIndex; i < m_8; i++)
    {
        if (m_iWordAt04 && cb((int)m_iWordAt04 + i * 8, b))
            return i;
    }
    return -1;
}

struct T006a1b20
{
    int f0;
    int f4;
    bool __thiscall MatchesPair(int* a);
};
// Returns true if the two ints pointed to by a equal this object's f0 and f4, otherwise false.
// @fnv 0x006a1b20
bool __thiscall T006a1b20::MatchesPair(int* aiPair)
{
    if (aiPair[0] != f0)
        return 0;
    if (aiPair[1] != f4)
        return 0;
    return 1;
}

void __cdecl _Deallocate(void* p);
struct C_006a1ba0
{
    void* __thiscall FUN_006a1ba0(unsigned int flags);
};
// Calls FUN_006a14e0 on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x006a1ba0
void* __thiscall C_006a1ba0::FUN_006a1ba0(unsigned int flags)
{
    ((GlobalObject_00869f00*)this)->ResetVirtualTableAndClear_006a14e0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern "C" void __cdecl Deallocate(void*);
struct FUN_006a1bd0_class
{
    void __thiscall FUN_006a15b0();
    void* FUN_006a1bd0(unsigned int flags);
};
// @fnv 0x006a1bd0
void* FUN_006a1bd0_class::FUN_006a1bd0(unsigned int flags)
{
    FUN_006a15b0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl _Deallocate(void*);
struct FUN_006a1c00_class
{
    void* __thiscall FUN_006a1c00(unsigned int);
};
// Calls FUN_006a1700 on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x006a1c00
void* __thiscall FUN_006a1c00_class::FUN_006a1c00(unsigned int flags)
{
    ((FUN_006a1700_class*)this)->UpdateFields_006a1700();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_006a1890_class
{
    void __thiscall SetVtableAndProcessState_006a1890();
};
extern "C" void __cdecl Deallocate(void*);
struct FUN_006a1c30_class : FUN_006a1890_class
{
    void* __thiscall FUN_006a1c30(unsigned int flags);
};
// @fnv 0x006a1c30
void* __thiscall FUN_006a1c30_class::FUN_006a1c30(unsigned int flags)
{
    SetVtableAndProcessState_006a1890();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void __cdecl Deallocate(void*);

struct FUN_006a18e0_Class
{
    void __thiscall ResetVirtualTableAndClear_006a18e0();
};

struct FUN_006a1c60_Class
{
    void __thiscall ResetVirtualTableAndClear_006a18e0();
    void* __thiscall FUN_006a1c60(unsigned int flags);
};

// @fnv 0x006a1c60
void* __thiscall FUN_006a1c60_Class::FUN_006a1c60(unsigned int flags)
{
    ResetVirtualTableAndClear_006a18e0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_006a19e0_Class : public FUN_006a19e0
{
    void* __thiscall FUN_006a1c90(unsigned int flags);
};
// @fnv 0x006a1c90
void* __thiscall FUN_006a19e0_Class::FUN_006a1c90(unsigned int flags)
{
    Init();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_006a1cc0_class
{
    void __thiscall UpdateState_006a1a30();
    void* __thiscall FUN_006a1cc0(unsigned int a);
};
// Calls FUN_006a1a30, then deallocates this if bit 0 of a is set, and returns this.
// @fnv 0x006a1cc0
void* __thiscall FUN_006a1cc0_class::FUN_006a1cc0(unsigned int uiFlags)
{
    UpdateState_006a1a30();
    if (uiFlags & 1)
        Deallocate(this);
    return this;
}

void __cdecl BSSleep(unsigned long);
class Modifier
{
  public:
    float GetValue();
};
// Exe 0x006a1cf0: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
class BlkOffset08View
{
  public:
    unsigned int GetFlags();
};
class Arr
{
  public:
    unsigned int* GetAt(int);
};

class PathSearchNode
{
  public:
    char pad0[0x54];
    PathSearchNode* pParent;
};

struct FUN_006a2500;
struct FUN_006a25d0;
template <class A, class B> class AStarConnectionArrayT
{
  public:
    void* m_pBuffer;
    unsigned int m_uiSize;
    unsigned int m_uiCapacity;
    unsigned int m_uiGrow;
    AStarConnectionArrayT();
    virtual ~AStarConnectionArrayT();
};
typedef AStarConnectionArrayT<FUN_006a2500, FUN_006a25d0> ConnectionArray;

class OpenList
{
  public:
    PathSearchNode* PopOpenNode();
    void UnlinkFromList(PathSearchNode*);
    void InsertSorted(PathSearchNode*);
};

struct FUN_006a1cf0_shell
{
    virtual void vf00();
    virtual void GetConnections(PathSearchNode*, ConnectionArray*);
    virtual bool HasReachedGoal(PathSearchNode*);
    char pad004[0x1ff4 - 4];
    OpenList kOpenList;
    char pad1ff5[0x2048 - 0x1ff5];
    PathSearchNode* pBestNode;
    PathSearchNode* pCurrentNode;
    unsigned int unk2050;
    bool bYield;
    PathSearchNode* AStarSearch_NavMeshPOVSearchNode_NavMeshPOVSearchLink_BuildPath();
};

// @fnv 0x006a1cf0
// src: COMMUNITY 0x006a1cf0
PathSearchNode* FUN_006a1cf0_shell::AStarSearch_NavMeshPOVSearchNode_NavMeshPOVSearchLink_BuildPath()
{
    PathSearchNode* pLast;
    {
        ConnectionArray kConnections;
        pLast = pCurrentNode;
        pCurrentNode = kOpenList.PopOpenNode();
        if (!pCurrentNode)
            return 0;
        pBestNode = pCurrentNode;
        int iCount = 0;
        while (pCurrentNode)
        {
            if (HasReachedGoal(pCurrentNode))
            {
                pBestNode = pCurrentNode;
                return pCurrentNode;
            }
            ((GlobalObject_00869f00*)&kConnections)->Clear(false);
            GetConnections(pCurrentNode, &kConnections);
            for (unsigned int i = 0; i < ((BlkOffset08View*)&kConnections)->GetFlags(); i++)
            {
                PathSearchNode* pNode = (PathSearchNode*)*((Arr*)&kConnections)->GetAt(i);
                kOpenList.UnlinkFromList(pNode);
                if (pCurrentNode->pParent == pNode)
                    return 0;
                pNode->pParent = pCurrentNode;
                kOpenList.InsertSorted(pNode);
                if (((Modifier*)pNode)->GetValue() < ((Modifier*)pBestNode)->GetValue())
                    pBestNode = pNode;
            }
            if (bYield)
            {
                iCount++;
                if (iCount == 50)
                {
                    iCount = 0;
                    BSSleep(0);
                }
            }
            pLast = pCurrentNode;
            pCurrentNode = kOpenList.PopOpenNode();
        }
        pCurrentNode = pLast;
        return 0;
    }
}

struct FUN_006a1fb0_class
{
    void UnlinkFromList(int param_1);
};
// Unlinks the node at param_1 from its doubly linked list by patching the neighbours' next/prev pointers, then clears its own pointers.
// @fnv 0x006a1fb0
void FUN_006a1fb0_class::UnlinkFromList(int pNode)
{
    if (*(void**)((char*)pNode + 0x58))
        *(void**)(*(void**)((char*)pNode + 0x58)) = *(void**)((char*)pNode + 0x5c);
    if (*(void**)((char*)pNode + 0x5c))
        *(void**)((char*)*(void**)((char*)pNode + 0x5c) + 0x58) = *(void**)((char*)pNode + 0x58);
    *(void**)((char*)pNode + 0x58) = 0;
    *(void**)((char*)pNode + 0x5c) = 0;
}

struct S_FUN_006a2440
{
    int m_iWordAt00;
    int m_iWordAt04;
    S_FUN_006a2440* InitializeFieldsToMinusOne();
};
// Sets both fields to -1 and returns this.
// @fnv 0x006a2440
// src: GUESS 0x006a2440 (confidence: medium)
S_FUN_006a2440* S_FUN_006a2440::InitializeFieldsToMinusOne()
{
    m_iWordAt00 = -1;
    m_iWordAt04 = -1;
    return this;
}

struct FUN_006a2580
{
    virtual ~FUN_006a2580();
    void* __thiscall FUN_006a25a0(unsigned int);
};
void __cdecl _Deallocate(void*);
// Runs the destructor and, when bit 0 of flags is set, deallocates this object; returns this.
// @fnv 0x006a25a0
void* __thiscall FUN_006a2580::FUN_006a25a0(unsigned int flags)
{
    this->FUN_006a2580::~FUN_006a2580();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_006a25d0
{
    virtual ~FUN_006a25d0();
    void* FUN_006a2820(unsigned int);
};
// Destructs the object and, when bit 0 of flags is set, frees its memory with operator delete; returns this.
// @fnv 0x006a2820
void* FUN_006a25d0::FUN_006a2820(unsigned int flags)
{
    this->FUN_006a25d0::~FUN_006a25d0();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_006a28d0_class
{
    void __thiscall SetVirtualTableAndProcessState_006a2900();
    void* __thiscall FUN_006a28d0(unsigned int flags);
};
// Calls FUN_006a2900, then frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x006a28d0
void* __thiscall FUN_006a28d0_class::FUN_006a28d0(unsigned int flags)
{
    SetVirtualTableAndProcessState_006a2900();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_006a29f0
{
    ~FUN_006a29f0();
};
extern int DAT_011d6e2c;
// Deletes the object held in DAT_011d6e2c if it is non-null, then sets DAT_011d6e2c to 0.
// @fnv 0x006a29a0
// src: COMMUNITY 0x006a29a0
void NavMeshRender_Destroy()
{
    if (DAT_011d6e2c)
        delete (FUN_006a29f0*)DAT_011d6e2c;
    DAT_011d6e2c = 0;
}

extern "C" void __cdecl Deallocate(void*);

struct FUN_006a3580_class
{
    void __thiscall FUN_006a3580();
    void* __thiscall FUN_006a29f0(unsigned int flags);
};

// Calls FUN_006a3580, then frees this with Deallocate if flags has bit 0 set, and returns this.
// @fnv 0x006a29f0
void* FUN_006a3580_class::FUN_006a29f0(unsigned int flags)
{
    FUN_006a3580();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_006a6310_class
{
    void __thiscall FUN_006a6450();
    void* __thiscall FUN_006a6310(unsigned int flags);
};
// @fnv 0x006a6310
void* __thiscall FUN_006a6310_class::FUN_006a6310(unsigned int flags)
{
    FUN_006a6450();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_006a6550_class
{
    void __thiscall FUN_006a6550();
};
struct FUN_006a6340_class : FUN_006a6550_class
{
    void* __thiscall FUN_006a6340(int flags);
};
// @fnv 0x006a6340
void* __thiscall FUN_006a6340_class::FUN_006a6340(int flags)
{
    FUN_006a6550();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void* __cdecl NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);
struct FUN_006a6370_class
{
    int* p;
    int n;
    void* data;
    unsigned int c;
    FUN_006a6370_class* NiTMapBase_DFALL_NiTMapItem_NavMesh_NiPointer_NiNode_NavMesh_NiPointer_NiNode_NiTMapBase_DFALL_NiTMapItem_NavMesh_NiPointer_NiNode_NavMesh_NiPointer_NiNode(int n);
};
// Sets p to DAT_0106b56c, stores n, zeroes c, allocates n*4 bytes into data and clears them, then returns this.
// @fnv 0x006a6370
// src: COMMUNITY 0x006a6370
FUN_006a6370_class* FUN_006a6370_class::NiTMapBase_DFALL_NiTMapItem_NavMesh_NiPointer_NiNode_NavMesh_NiPointer_NiNode_NiTMapBase_DFALL_NiTMapItem_NavMesh_NiPointer_NiNode_NavMesh_NiPointer_NiNode(int aiCount)
{
    p = (int*)&DAT_0106b56c;
    this->n = aiCount;
    c = 0;
    unsigned int uiSize = this->n * 4;
    data = NiMalloc(uiSize);
    memset(data, 0, this->n * 4);
    return this;
}

void _NiFree(void*);
// RTTI at vftable 0x0106b58c identifies the corresponding TESObjectCELL* map base.
typedef NiTMapBase<DFALL<NiTMapItem<TESObjectCELL*, NiPointer<NiNode> > >, TESObjectCELL*, NiPointer<NiNode> > CellSceneNodeMapBase;
// @fnv 0x006a65b0
template <> CellSceneNodeMapBase::~NiTMapBase()
{
    RemoveAll();
    _NiFree(m_ppkHashTable);
}

extern char SG6202[];
struct FUN_006a6610
{
    const char* m_iWordAt00;
    void __thiscall BSSimpleArray_NiColorA_1024_InitialSetup(int a, int b);
    FUN_006a6610(int a);
};
// Sets the stored string pointer to SG6202, then calls FUN_006a69b0 with the same argument twice.
// @fnv 0x006a6610
FUN_006a6610::FUN_006a6610(int a)
{
    m_iWordAt00 = SG6202;
    BSSimpleArray_NiColorA_1024_InitialSetup(a, a);
}

void Deallocate(void*);

struct FUN_006a6850_class
{
    void __thiscall SetPhjAndClear();
    void* __thiscall FUN_006a6850(unsigned int flags);
};
// Calls SetPhjAndClear, frees this when flags has bit 0 set, and returns this.
// @fnv 0x006a6850
void* __thiscall FUN_006a6850_class::FUN_006a6850(unsigned int flags)
{
    SetPhjAndClear();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void __cdecl Deallocate(void*);
struct FUN_006a67d0_class
{
    void __thiscall SetVtableAndProcessState_006a67d0();
};
struct FUN_006a6880_class
{
    void* __thiscall FUN_006a6880(unsigned int flags);
};
// Calls FUN_006a67d0 on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x006a6880
void* __thiscall FUN_006a6880_class::FUN_006a6880(unsigned int flags)
{
    reinterpret_cast<FUN_006a67d0_class*>(this)->SetVtableAndProcessState_006a67d0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_006a7bc0_Class
{
    virtual ~FUN_006a7bc0_Class();
    FUN_006a7bc0_Class* FUN_006a7fb0(unsigned int flags);
};

// Runs the destructor and, when bit 0 of flags is set, deallocates this, then returns this.
// @fnv 0x006a7fb0
FUN_006a7bc0_Class* FUN_006a7bc0_Class::FUN_006a7fb0(unsigned int flags)
{
    FUN_006a7bc0_Class::~FUN_006a7bc0_Class();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void __cdecl Deallocate(void*);
struct FUN_006a85b0_class
{
    void __thiscall SetVtableAndProcessState_006a85b0();
    void* FUN_006a85d0(unsigned int flags);
};
// @fnv 0x006a85d0
void* FUN_006a85b0_class::FUN_006a85d0(unsigned int flags)
{
    SetVtableAndProcessState_006a85b0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_006a85b0
{
    virtual ~FUN_006a85b0();
};
struct FUN_006a8600 : FUN_006a85b0
{
    ~FUN_006a8600();
};
// Destructor that calls Clear(true) on the global object at this address.
// @fnv 0x006a8600
FUN_006a8600::~FUN_006a8600()
{
    reinterpret_cast<GlobalObject_00869f00*>(this)->Clear(true);
}

struct FUN_006a8700_Class
{
    float f0;
    float f4;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    FUN_006a8700_Class* AStarNode_AStarNode();
};
// Sets the two floats and the five int fields at offsets 0x28-0x38 to zero and returns this.
// @fnv 0x006a8700
// src: COMMUNITY 0x006a8700
FUN_006a8700_Class* FUN_006a8700_Class::AStarNode_AStarNode()
{
    f0 = 0.0f;
    f4 = 0.0f;
    *(int*)((char*)this + 0x28) = 0;
    *(int*)((char*)this + 0x2c) = 0;
    *(int*)((char*)this + 0x30) = 0;
    *(int*)((char*)this + 0x34) = 0;
    *(int*)((char*)this + 0x38) = 0;
    return this;
}

void* __cdecl operator new(unsigned int, void*);
struct FUN_006a8a30_class
{
    void __thiscall BSSimpleArray_WeaponData_1024_ConstructItems(int base, unsigned int count);
};
// @fnv 0x006a8a30
// src: XBOX_PDB 0x006a8a30
void __thiscall FUN_006a8a30_class::BSSimpleArray_WeaponData_1024_ConstructItems(int base, unsigned int count)
{
    for (int i = 0; i < count; ++i)
    {
        void* p = operator new(0x14, (void*)(base + i * 0x14));
    }
}

extern "C" void __cdecl Deallocate(void*);
struct FUN_006abc30_Class
{
    void __thiscall SetVtableAndProcessState_006abc30();
};
struct FUN_006abea0_Class
{
    void* FUN_006abea0(unsigned int flags);
};
// Calls FUN_006abc30 on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x006abea0
void* FUN_006abea0_Class::FUN_006abea0(unsigned int flags)
{
    ((FUN_006abc30_Class*)this)->SetVtableAndProcessState_006abc30();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void __cdecl Deallocate(void*);
struct FUN_006abdc0_shell
{
    void ResetVirtualTableAndClear_006abdc0();
};
struct FUN_006abed0_class
{
    void* FUN_006abed0(unsigned int flags);
};
// @fnv 0x006abed0
void* FUN_006abed0_class::FUN_006abed0(unsigned int flags)
{
    ((FUN_006abdc0_shell*)this)->ResetVirtualTableAndClear_006abdc0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl Deallocate(void*);

struct FUN_006abf00_Class
{
    void __thiscall FUN_006abc50();
    void* __thiscall FUN_006abf00(unsigned int flags);
};

// Calls FUN_006abc50, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x006abf00
void* __thiscall FUN_006abf00_Class::FUN_006abf00(unsigned int flags)
{
    FUN_006abc50();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl Deallocate(void*);

struct FUN_006abf30_Class
{
    void __thiscall FUN_006abde0();
    void* __thiscall FUN_006abf30(unsigned int flags);
};

// @fnv 0x006abf30
void* __thiscall FUN_006abf30_Class::FUN_006abf30(unsigned int flags)
{
    FUN_006abde0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_006cf9d0
{
    void __thiscall BSSimpleArray_WeaponData_1024_InitialSetup(unsigned int, unsigned int);
};
extern int DAT_0106b8a0;
struct FUN_006abf60_class
{
    int* vtable;
    FUN_006abf60_class* SetVirtualTableAndProcessState_006abf60();
};
// Sets the vtable pointer to DAT_0106b8a0, calls FUN_009a3d00 with 0, 0, and returns this.
// @fnv 0x006abf60
// src: GUESS 0x006abf60 (confidence: low)
FUN_006abf60_class* FUN_006abf60_class::SetVirtualTableAndProcessState_006abf60()
{
    vtable = &DAT_0106b8a0;
    reinterpret_cast<FUN_006cf9d0*>(this)->BSSimpleArray_WeaponData_1024_InitialSetup(0, 0);
    return this;
}

extern int DAT_0106b8c8;
struct FUN_006abf90_Obj
{
    int* vtable;
    FUN_006abf90_Obj* InitVtable();
};
// Sets the object's vtable to DAT_0106b8c8, calls FUN_006b3f40 with 0, 0, and returns this.
// @fnv 0x006abf90
FUN_006abf90_Obj* FUN_006abf90_Obj::InitVtable()
{
    vtable = &DAT_0106b8c8;
    ((Dummy_0061bf20*)this)->BSSimpleArray_NavMeshPOVSearchNode_1024_InitialSetup(0, 0);
    return this;
}

// PathBuilder appends PathingLocation values to this array (0x006cf1b0).
// Its scalar deleting destructor is 0x006abfe0.
template <> BSSimpleArray<PathingLocation, 1024>::~BSSimpleArray()
{
    Clear(true);
}

struct Elem_006ac070
{
    unsigned char data[0x28];
    void FUN_006ac0b0(int);
};
struct S_006ac070
{
    void BSSimpleArray_PathingLocation_1024_DestructItems(Elem_006ac070* p, unsigned int n);
};
// Calls FUN_006ac0b0(0) on each of the n elements starting at p.
// @fnv 0x006ac070
// src: XBOX_PDB 0x006ac070
void S_006ac070::BSSimpleArray_PathingLocation_1024_DestructItems(Elem_006ac070* pElements, unsigned int n)
{
    unsigned int i;
    for (i = 0; i < n; i++)
    {
        pElements[i].FUN_006ac0b0(0);
    }
}

extern "C" void __cdecl Deallocate(void*);
struct _Mem_2064
{
    ~_Mem_2064();
    void* FUN_006ac0b0(unsigned int flags);
};
// Runs the destructor, then frees this object with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x006ac0b0
void* _Mem_2064::FUN_006ac0b0(unsigned int flags)
{
    _Mem_2064::~_Mem_2064();
    if (flags & 1)
        Deallocate(this);
    return this;
}

// Multiplies both float members by scale and returns a reference to this object.
// @fnv 0x006ad180
NiPoint2& NiPoint2::Scale(float scale)
{
    x *= scale;
    y *= scale;
    return *this;
}

struct ArrHelper
{
    bool __thiscall NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty() const;
    void* __thiscall BSSimpleArray_PathingNode_1024_GetLast();
};
struct S_FUN_006b05a0
{
    char _pad[0x20];
    ArrHelper _arr;
    void* __thiscall PathingSolution_GetLastNode();
};
// @fnv 0x006b05a0
// src: XBOX_PDB 0x006b05a0
void* __thiscall S_FUN_006b05a0::PathingSolution_GetLastNode()
{
    if (_arr.NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
    {
        return 0;
    }
    return _arr.BSSimpleArray_PathingNode_1024_GetLast();
}

extern void* DAT_0106ba6c;
struct FUN_006b3800_Host
{
    void* vtable;
    FUN_006b3800_Host* BSSimpleArray_NavMesh_1024_BSSimpleArray_NavMesh_1024();
};
// Sets the vtable to DAT_0106ba6c, calls FUN_006b3eb0 with 0 and 0, and returns this.
// @fnv 0x006b3800
// src: COMMUNITY 0x006b3800
FUN_006b3800_Host* FUN_006b3800_Host::BSSimpleArray_NavMesh_1024_BSSimpleArray_NavMesh_1024()
{
    vtable = &DAT_0106ba6c;
    reinterpret_cast<AX*>(this)->BSSimpleArray_float_1024_InitialSetup(0, 0);
    return this;
}

struct PathSmootherPOVAvoidanceNode;
struct NavMeshEdgeSegment;

void __cdecl _Deallocate(void*);
// Destructs the AStarSearch object and, when bit 0 of flags is set, deallocates its memory; returns this.
// @fnv 0x006b3850
template <class N, class L> void* __thiscall AStarSearch<N, L>::FUN_006b3850(unsigned int flags)
{
    this->AStarSearch<N, L>::~AStarSearch();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
template void* __thiscall AStarSearch<PathSmootherPOVAvoidanceNode, NavMeshEdgeSegment>::FUN_006b3850(unsigned int);

struct PathSmootherPOVPoint;
// @fnv 0x006b3880
template <> BSSimpleArray<PathSmootherPOVPoint>::~BSSimpleArray()
{
    Clear(true);
}

struct ASC
{
    float f0;
    float f4;
    ASC& operator=(const ASC&);
};
struct FUN_006b3910_S
{
    ASC a;
    ASC b;
    NavMeshEdgePoint c;
    NavMeshEdgePoint d;
    FUN_006b3910_S* PathSmootherPOVLink_Copy(const FUN_006b3910_S* p);
};
// Copies the four members a, b, c and d from p into this object and returns this.
// @fnv 0x006b3910
// src: COMMUNITY 0x006b3910
FUN_006b3910_S* FUN_006b3910_S::PathSmootherPOVLink_Copy(const FUN_006b3910_S* apSource)
{
    a = apSource->a;
    b = apSource->b;
    c = apSource->c;
    d = apSource->d;
    return this;
}

void __cdecl _Deallocate(void*);
struct GlobalObject_00869f00_helper
{
    void __thiscall Dtor();
};
struct Target_006b3a00
{
    void* __thiscall FUN_006b3a00(unsigned int);
};
// @fnv 0x006b3a00
void* __thiscall Target_006b3a00::FUN_006b3a00(unsigned int flags)
{
    ((GlobalObject_00869f00_helper*)this)->Dtor();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_006b43f0_obj
{
    void* __thiscall Constructor();
};
struct S_006b3d90
{
    void* __thiscall AllocateAndConstructObject68();
};
// Allocates a 0x68-byte object via FUN_006a1f90 and returns the result of Constructor on it, or 0 if allocation fails.
// @fnv 0x006b3d90
// src: GUESS 0x006b3d90 (confidence: medium)
void* __thiscall S_006b3d90::AllocateAndConstructObject68()
{
    void* q;
    {
        void* p = Runtime_ForwardCall_006a1f90(0x68, (ScrapHeapBuffer*)this);
        q = p ? ((FUN_006b43f0_obj*)p)->Constructor() : 0;
    }
    return q;
}

void* memset(void* dest, int value, unsigned int count);

struct FUN_006b3de0_Class
{
    void* ProcessAndReturnValue_006b3de0();
};

// Zeroes the 0x1fdc-byte block starting at this, sets the int at offset 0x1fdc to 0, and returns this.
// @fnv 0x006b3de0
// src: GUESS 0x006b3de0 (confidence: low)
void* FUN_006b3de0_Class::ProcessAndReturnValue_006b3de0()
{
    ((int*)this)[0x1fdc / 4] = 0;
    memset(this, 0, 0x1fdc);
    return this;
}

struct H40F0
{
    void ConstructElements(void*, int);
};
struct FUN_006b4190_class
{
    virtual void* v0();
    virtual int Write(unsigned int);
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    void __thiscall UpdateState_006b4190(unsigned int requested, unsigned int savedSize);
};
// @fnv 0x006b4190
// src: GUESS 0x006b4190 (confidence: low)
void FUN_006b4190_class::UpdateState_006b4190(unsigned int uiRequestedSize, unsigned int savedSize)
{
    m_iWordAt04 = 0;
    m_8 = 0;
    m_iThirdValue = 0;
    if (savedSize > uiRequestedSize)
    {
        uiRequestedSize = savedSize;
    }
    if (uiRequestedSize > 0)
    {
        m_iWordAt04 = Write(uiRequestedSize);
        m_iThirdValue = uiRequestedSize;
    }
    if (savedSize > 0)
    {
        reinterpret_cast<H40F0*>(this)->ConstructElements(reinterpret_cast<void*>(m_iWordAt04), savedSize);
        m_8 = savedSize;
    }
}

void __cdecl Deallocate(void*);
struct FUN_006b42a0_class
{
    void __thiscall ResetVirtualTableAndClear_006b42a0();
    void* FUN_006b42c0(unsigned int flags);
};
// Calls FUN_006b42a0, then frees this with Deallocate when bit 0 of flags is set, and returns this.
// @fnv 0x006b42c0
void* FUN_006b42a0_class::FUN_006b42c0(unsigned int flags)
{
    ResetVirtualTableAndClear_006b42a0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void __cdecl Deallocate(void*);

struct FUN_006b4640_Class
{
    void* FUN_006b4640(unsigned int flags);
    void __thiscall FUN_006b42f0();
};

// @fnv 0x006b4640
void* __thiscall FUN_006b4640_Class::FUN_006b4640(unsigned int flags)
{
    FUN_006b42f0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_0069c460_shell
{
    int NavMeshBounds_GetBoundsChunkSize();
};
struct FUN_006b4880_Class
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
    FUN_0069c460_shell* m_58;
    int GetSerializedSize();
};
// @fnv 0x006b4880
int FUN_006b4880_Class::GetSerializedSize()
{
    int i = 0;
    i += 4;
    i += 4;
    i += 4;
    i += 4;
    i += 0xc;
    if (m_58)
        i += m_58->NavMeshBounds_GetBoundsChunkSize();
    i += 4;
    return i;
}

extern "C" void __cdecl Deallocate(void*);

struct FUN_006b7fd0_class
{
    void FUN_006b7fd0();
    void* FUN_006b7e20(unsigned int flags);
};

// Calls FUN_006b7fd0, then frees this via Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x006b7e20
void* FUN_006b7fd0_class::FUN_006b7e20(unsigned int flags)
{
    FUN_006b7fd0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void __cdecl Deallocate(void*);

struct FUN_006b80d0_Class
{
    void FUN_006b80d0();
    void* FUN_006b7e50(unsigned int flags);
};

// Calls FUN_006b80d0, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x006b7e50
void* FUN_006b80d0_Class::FUN_006b7e50(unsigned int flags)
{
    FUN_006b80d0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_006b81f0_class
{
    void* __thiscall FUN_006b81f0();
    void* __thiscall FUN_006b7e80(unsigned int flags);
};
// Calls FUN_006b81f0, frees this when flags has bit 0 set, and returns this.
// @fnv 0x006b7e80
void* __thiscall FUN_006b81f0_class::FUN_006b7e80(unsigned int flags)
{
    FUN_006b81f0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void* __cdecl NiMalloc(unsigned int);
void* __cdecl FillBytes(void* p, unsigned int c, unsigned int n);
struct FUN_006b7eb0_t
{
    void* __thiscall NiTMapBase_NiTPointerAllocator_unsigned_int_unsigned_int_NavMeshInfo_NiTMapBase(int a);
};
// @fnv 0x006b7eb0
// src: EXE 0x006b7eb0
void* FUN_006b7eb0_t::NiTMapBase_NiTPointerAllocator_unsigned_int_unsigned_int_NavMeshInfo_NiTMapBase(int aiCount)
{
    *reinterpret_cast<void**>(this) = &DAT_0106c194;
    reinterpret_cast<int*>(this)[1] = aiCount;
    reinterpret_cast<int*>(this)[3] = 0;
    unsigned int n = reinterpret_cast<int*>(this)[1] << 2;
    reinterpret_cast<int*>(this)[2] = (int)NiMalloc(n);
    FillBytes(reinterpret_cast<void*>(reinterpret_cast<int*>(this)[2]), 0, reinterpret_cast<int*>(this)[1] << 2);
    return this;
}

void* __cdecl NiMalloc(unsigned int size);
void* __cdecl memset(void* dest, int value, unsigned int count);
struct FUN_006b8060_class
{
    void* __thiscall NiTMapBase_DFALL_NiTMapItem_unsigned_int_NiTMap_unsigned_int_BSSimpleArray_NavMeshInfo_1024_unsigned_int_NiTMap_unsigned_int_BSSimpleArray_NavMeshInfo_1024_NiTMapBase(int size);
};
// @fnv 0x006b8060
// src: EXE 0x006b8060
void* FUN_006b8060_class::NiTMapBase_DFALL_NiTMapItem_unsigned_int_NiTMap_unsigned_int_BSSimpleArray_NavMeshInfo_1024_unsigned_int_NiTMap_unsigned_int_BSSimpleArray_NavMeshInfo_1024_NiTMapBase(int size)
{
    *reinterpret_cast<void**>(this) = &DAT_0106c1b4;
    reinterpret_cast<int*>(this)[1] = size;
    reinterpret_cast<int*>(this)[3] = 0;
    unsigned int uiByteCount = reinterpret_cast<int*>(this)[1] << 2;
    reinterpret_cast<void**>(this)[2] = NiMalloc(uiByteCount);
    memset(reinterpret_cast<void*>(reinterpret_cast<void**>(this)[2]), 0, reinterpret_cast<int*>(this)[1] << 2);
    return this;
}

void* __cdecl NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);
extern int DAT_0106c1d4;
struct FUN_006b8160_class
{
    int* vtbl;
    int m_iWordAt04;
    void* m_8;
    int m_iThirdValue;
    FUN_006b8160_class* NiTMapBase_DFALL_NiTMapItem_unsigned_int_BSSimpleArray_NavMeshInfo_1024_unsigned_int_BSSimpleArray_NavMeshInfo_1024_NiTMapBase(int n);
};
// Sets the vtable, stores n, allocates n*4 bytes zeroed into m_8 and returns this.
// @fnv 0x006b8160
// src: EXE 0x006b8160
FUN_006b8160_class* FUN_006b8160_class::NiTMapBase_DFALL_NiTMapItem_unsigned_int_BSSimpleArray_NavMeshInfo_1024_unsigned_int_BSSimpleArray_NavMeshInfo_1024_NiTMapBase(int aiCount)
{
    unsigned int size;
    vtbl = &DAT_0106c1d4;
    m_iWordAt04 = aiCount;
    m_iThirdValue = 0;
    size = m_iWordAt04 << 2;
    m_8 = NiMalloc(size);
    memset(m_8, 0, m_iWordAt04 << 2);
    return this;
}

extern "C" void __cdecl Deallocate(void*);

struct FUN_006b8280_class : FUN_006b8030_class
{
    void* __thiscall FUN_006b8280(unsigned int flags);
};

// @fnv 0x006b8280
void* __thiscall FUN_006b8280_class::FUN_006b8280(unsigned int flags)
{
    SetVtableAndProcessState_006b8030();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_006b82b0_class
{
    void* __thiscall FUN_006b82b0(unsigned int flags);
};
// Calls Method on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x006b82b0
void* __thiscall FUN_006b82b0_class::FUN_006b82b0(unsigned int flags)
{
    ((FUN_006b8130*)this)->Method();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_006b82e0_Class
{
    void __thiscall FUN_006b8250();
    void* __thiscall FUN_006b82e0(unsigned int flags);
};

// Calls FUN_006b8250, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x006b82e0
void* __thiscall FUN_006b82e0_Class::FUN_006b82e0(unsigned int flags)
{
    FUN_006b8250();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_006b8e40
{
    virtual ~FUN_006b8e40();
    void* FUN_006b9150(unsigned int);
};
// Runs the destructor and, when bit 0 of flags is set, frees the object with operator delete; returns this.
// @fnv 0x006b9150
void* FUN_006b8e40::FUN_006b9150(unsigned int flags)
{
    this->FUN_006b8e40::~FUN_006b8e40();
    if (flags & 1)
        operator delete(this);
    return this;
}

void* Runtime_ForwardCall_006a1f90(unsigned int, ScrapHeapBuffer*);
struct FUN_006b96c0_Class
{
    void* __thiscall AStarNode_CombatPlanNode_CombatPlanLink_AStarNode_CombatPlanNode_CombatPlanLink();
};
struct FUN_006b9420_Class
{
    void* __thiscall AStarNodeHeap_CombatPlanNode_CombatPlanLink_AllocateNode();
};
// @fnv 0x006b9420
// src: COMMUNITY 0x006b9420
void* __thiscall FUN_006b9420_Class::AStarNodeHeap_CombatPlanNode_CombatPlanLink_AllocateNode()
{
    void* p5 = Runtime_ForwardCall_006a1f90(0x24, (ScrapHeapBuffer*)this);
    void* r = p5 ? ((FUN_006b96c0_Class*)p5)->AStarNode_CombatPlanNode_CombatPlanLink_AStarNode_CombatPlanNode_CombatPlanLink() : 0;
    return r;
}

struct FUN_006b9630_class
{
    void __thiscall SetVtableAndProcessState_006b9610();
    void* __thiscall FUN_006b9630(unsigned int flags);
};

// @fnv 0x006b9630
void* __thiscall FUN_006b9630_class::FUN_006b9630(unsigned int flags)
{
    SetVtableAndProcessState_006b9610();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern int DAT_0106c250;
struct FUN_006b9610_base
{
    virtual ~FUN_006b9610_base();
};
struct FUN_006b9660 : FUN_006b9610_base
{
    ~FUN_006b9660();
};
// @fnv 0x006b9660
FUN_006b9660::~FUN_006b9660()
{
    ((GlobalObject_00869f00*)this)->Clear(true);
}

struct FUN_006b96c0_class
{
    float f0;
    float f4;
    float f8;
    float fc;
    int i10;
    int i14;
    int i18;
    int i1c;
    int i20;
    FUN_006b96c0_class* __thiscall AStarNode_CombatPlanNode_CombatPlanLink_AStarNode_CombatPlanNode_CombatPlanLink();
};
// Clears the float fields f0 and f4 and the int fields i10 through i20 to zero, then returns this.
// @fnv 0x006b96c0
// src: COMMUNITY 0x006b96c0
FUN_006b96c0_class* __thiscall FUN_006b96c0_class::AStarNode_CombatPlanNode_CombatPlanLink_AStarNode_CombatPlanNode_CombatPlanLink()
{
    f0 = 0.0f;
    f4 = 0.0f;
    i10 = 0;
    i14 = 0;
    i18 = 0;
    i1c = 0;
    i20 = 0;
    return this;
}

void __cdecl Deallocate(void*);

struct FUN_006b9660_class
{
    void FUN_006b9660();
    void* FUN_006b9730(unsigned int flags);
};

// @fnv 0x006b9730
void* FUN_006b9660_class::FUN_006b9730(unsigned int flags)
{
    FUN_006b9660();
    if (flags & 1)
        Deallocate(this);
    return this;
}


// Returns the dot product of the two-component vector p with the stored pair of floats.
// @fnv 0x006b99e0
float NiPoint2::Dot(const NiPoint2& afVec)
{
    return x * afVec.x + y * afVec.y;
}

struct S006bb540
{
    Point3Storage m_iWordAt00;
    Point3Storage m_C;
    NiPoint3 SubtractFromC();
};
// @fnv 0x006bb540
NiPoint3 S006bb540::SubtractFromC()
{
    return ((NiPoint3*)&m_C)->operator-(reinterpret_cast<const NiPoint3&>(m_iWordAt00));
}


struct FUN_006bc8b0
{
    NavMeshEdgeData m0;
    NavMeshEdgeData mC;
    FUN_006bc8b0();
};
// Default-constructs the two navmesh edge records of the object.
// @fnv 0x006bc8b0
FUN_006bc8b0::FUN_006bc8b0()
{}

struct FUN_006bcfe0_Class
{
    unsigned short m_iWordAt00;
    unsigned short m_cByteAtOffset2;
    unsigned short m_iWordAt04;
    unsigned short m_6;
    unsigned short m_8;
    unsigned short m_kPointA;
    unsigned short m_iThirdValue;
    unsigned short m_usTrailingValue;
    void NavMeshObstacleEdge_AddTriangle(unsigned short a, unsigned short b);
};
// @fnv 0x006bcfe0
// src: COMMUNITY 0x006bcfe0
void FUN_006bcfe0_Class::NavMeshObstacleEdge_AddTriangle(unsigned short ausFirst, unsigned short ausSecond)
{
    if (m_8 == 0xffff)
    {
        m_8 = ausFirst;
        m_iThirdValue = ausSecond;
    }
    else if (m_kPointA == 0xffff)
    {
        m_kPointA = ausFirst;
        m_usTrailingValue = ausSecond;
    }
}

struct FUN_006be0c0_Class
{
    unsigned short w0;
    unsigned short w2;
    unsigned short w4;
    unsigned short w6;
    unsigned short w8;
    unsigned short wa;
    int m_iThirdValue;
    int m_10;
    bool NavMeshObstacleEdge_CanBeUsed();
};
// Returns true if w8 is 0xFFFF, or if wa is 0xFFFF and m_10 is not 1, 3 or 4; otherwise false.
// @fnv 0x006be0c0
// src: COMMUNITY 0x006be0c0
bool FUN_006be0c0_Class::NavMeshObstacleEdge_CanBeUsed()
{
    if (w8 == 0xFFFF)
        return true;
    if (wa != 0xFFFF)
        return false;
    if (m_10 == 1 || m_10 == 3 || m_10 == 4)
        return false;
    return true;
}

struct Struct006be630
{
    short m_iWordAt00;
    short m_cByteAtOffset2;
    short m_iWordAt04;
    void __thiscall SetValues(short a, short b, short c);
};
// Stores the three short arguments into the object's three short fields.
// @fnv 0x006be630
void __thiscall Struct006be630::SetValues(short asFirst, short asSecond, short asThird)
{
    m_iWordAt00 = asFirst;
    m_cByteAtOffset2 = asSecond;
    m_iWordAt04 = asThird;
}

struct R006beb80
{
    void __thiscall AddTrianglesToGrid(unsigned short, int);
};
struct P006beb80
{
    char _0[0x18];
    union
    {
        int i;
        unsigned short w;
    } u;
    int len;
};
struct S006beb80
{
    R006beb80* r;
    int _4;
    P006beb80* p;
    void __thiscall NavMeshObstacleCutter_AddNewTrianglesToNavMeshGrid();
};
// If the buffer length is non-zero, calls AddTrianglesToGrid on the receiver with the union value and the last index (u.i + len - 1).
// @fnv 0x006beb80
// src: COMMUNITY 0x006beb80
void __thiscall S006beb80::NavMeshObstacleCutter_AddNewTrianglesToNavMeshGrid()
{
    if (p->len != 0)
        r->AddTrianglesToGrid(p->u.w, p->u.i + p->len - 1);
}

struct NH
{
    Point3Storage const& __thiscall GetVertex_0068f0a0(unsigned short);
};
struct P_006bf1d0
{
    unsigned short m0;
    unsigned char m2;
    unsigned char m3;
    unsigned char m4;
};
struct S_006bf1d0
{
    NH* m0;
    bool __thiscall NavMeshObstacleCutter_IsPointInOverlappedArea(Point3Storage const&);
    bool __thiscall NavMeshObstacleCutter_IsVertInOverlappedArea(P_006bf1d0*);
};
// @fnv 0x006bf1d0
// src: COMMUNITY 0x006bf1d0
bool __thiscall S_006bf1d0::NavMeshObstacleCutter_IsVertInOverlappedArea(P_006bf1d0* p)
{
    if (p->m3 || p->m4)
        return true;
    return NavMeshObstacleCutter_IsPointInOverlappedArea(m0->GetVertex_0068f0a0(p->m0));
}

namespace fnv_006bf2a0 {
struct NH
{
    Point3Storage const& __thiscall GetVertex_0068f0a0(unsigned short);
};
struct S006bf2a0
{
    NH* m_iWordAt00;
    void __thiscall NavMeshObstacleCutter_IsPointInObstacleArea(Point3Storage const&);
    void __thiscall NavMeshObstacleCutter_IsVertInObstacleArea(unsigned short*);
};
// Looks up the Point3Storage for the unsigned short at p via the NH object and passes it to FUN_006bf2d0.
// @fnv 0x006bf2a0
// src: COMMUNITY 0x006bf2a0
void __thiscall S006bf2a0::NavMeshObstacleCutter_IsVertInObstacleArea(unsigned short* p)
{
    NavMeshObstacleCutter_IsPointInObstacleArea(m_iWordAt00->GetVertex_0068f0a0(*p));
}
}  // namespace fnv_006bf2a0

extern int DAT_0106c2fc;
struct S006bf6e0
{
    void* vtable;
    void __thiscall BSSimpleArray_PortalEdgeSwap_1024_InitialSetup(int a, int b);
    S006bf6e0* Construct();
};
// Sets the vtable to DAT_0106c2fc, calls FUN_006bfe70 with 0 and 0, and returns this.
// @fnv 0x006bf6e0
S006bf6e0* S006bf6e0::Construct()
{
    vtable = &DAT_0106c2fc;
    BSSimpleArray_PortalEdgeSwap_1024_InitialSetup(0, 0);
    return this;
}

struct FUN_006bf870
{
    virtual ~FUN_006bf870();
};
struct FUN_006bf890 : FUN_006bf870
{
    ~FUN_006bf890();
};
// Destructor that calls Clear(true) on the object at this address.
// @fnv 0x006bf890
FUN_006bf890::~FUN_006bf890()
{
    ((GlobalObject_00869f00*)this)->Clear(true);
}

extern "C" void __cdecl Deallocate(void*);
struct FUN_006bf6c0_class
{
    void __thiscall ResetVirtualTableAndClear_006bf6c0();
};
struct FUN_006bfbe0_class
{
    void* __thiscall FUN_006bfbe0(int flags);
};
// @fnv 0x006bfbe0
void* __thiscall FUN_006bfbe0_class::FUN_006bfbe0(int flags)
{
    ((FUN_006bf6c0_class*)this)->ResetVirtualTableAndClear_006bf6c0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_006bf710_Class
{
    void SetVtableAndProcessState_006bf710();
    void* FUN_006bfc10(unsigned int flags);
};

// @fnv 0x006bfc10
void* FUN_006bf710_Class::FUN_006bfc10(unsigned int flags)
{
    SetVtableAndProcessState_006bf710();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct EH
{
    int m0;
    int m4;
    int m8;
    EH& __thiscall operator=(EH const&);
};
struct S006bfc40
{
    EH m0;
    EH m12;
    unsigned char m24;
    S006bfc40& __thiscall CopyFields_006bfc40(S006bfc40 const&);
};
// Copies the three members of other into this object and returns a reference to this object.
// @fnv 0x006bfc40
// src: GUESS 0x006bfc40 (confidence: medium)
S006bfc40& __thiscall S006bfc40::CopyFields_006bfc40(S006bfc40 const& other)
{
    m0 = other.m0;
    m12 = other.m12;
    m24 = other.m24;
    return *this;
}

extern "C" void __cdecl Deallocate(void*);
struct FUN_006bf870_class
{
    void __thiscall SetVtableAndProcessState_006bf870();
    void* __thiscall FUN_006bfc80(unsigned int flags);
};
// Calls FUN_006bf870, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x006bfc80
void* __thiscall FUN_006bf870_class::FUN_006bfc80(unsigned int flags)
{
    SetVtableAndProcessState_006bf870();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_006bf890_class
{
    void __thiscall FUN_006bf890();
};
struct FUN_006bfcb0_class
{
    void* __thiscall FUN_006bfcb0(unsigned int flags);
};
// @fnv 0x006bfcb0
void* __thiscall FUN_006bfcb0_class::FUN_006bfcb0(unsigned int flags)
{
    ((FUN_006bf890_class*)this)->FUN_006bf890();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_006bfce0_Class
{
    void __thiscall SetVtableAndProcessState_006bfab0();
    void* __thiscall FUN_006bfce0(unsigned int flags);
};
// Calls FUN_006bfab0, then frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x006bfce0
void* __thiscall FUN_006bfce0_Class::FUN_006bfce0(unsigned int flags)
{
    SetVtableAndProcessState_006bfab0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void __cdecl Deallocate(void*);

struct FUN_006bfd10_class
{
    void __thiscall FUN_006bfad0();
    void* __thiscall FUN_006bfd10(unsigned int flags);
};

// Calls FUN_006bfad0, then frees this object with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x006bfd10
void* FUN_006bfd10_class::FUN_006bfd10(unsigned int flags)
{
    FUN_006bfad0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern int DAT_0106c34c;
struct FUN_006bff30_Class
{
    int* vtable;
    FUN_006bff30_Class* BSSimpleArray_NavMeshObstacleEdge_1024_BSSimpleArray_NavMeshObstacleEdge_1024();
};
// Sets the vtable to DAT_0106c34c, calls FUN_006b3eb0 with 0, 0, and returns this.
// @fnv 0x006bff30
// src: COMMUNITY 0x006bff30
FUN_006bff30_Class* FUN_006bff30_Class::BSSimpleArray_NavMeshObstacleEdge_1024_BSSimpleArray_NavMeshObstacleEdge_1024()
{
    vtable = &DAT_0106c34c;
    reinterpret_cast<AX*>(this)->BSSimpleArray_float_1024_InitialSetup(0, 0);
    return this;
}

struct FUN_006a20a0
{
    void* m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int __thiscall ConstructArray(int a, int b);
    int __thiscall FUN_006a2001(int a);
    void __thiscall UpdateFields_006a20a0(unsigned int requested, unsigned int savedSize);
};
// @fnv 0x006a20a0
// src: GUESS 0x006a20a0 (confidence: low)
void FUN_006a20a0::UpdateFields_006a20a0(unsigned int requested, unsigned int savedSize)
{
    m_iWordAt04 = 0;
    m_8 = 0;
    m_iThirdValue = 0;
    if (savedSize > requested)
    {
        requested = savedSize;
    }
    if (requested > 0)
    {
        m_iWordAt04 = ((int(__thiscall*)(void*, int))(*(void***)this)[1])(this, requested);
        m_iThirdValue = requested;
    }
    if (savedSize > 0)
    {
        ConstructArray(m_iWordAt04, savedSize);
        m_8 = savedSize;
    }
}

void* __cdecl FUN_00ec7230(char* dst, const char* src, unsigned int size);

struct FUN_006a2270_class
{
    void __thiscall BSSimpleArray_PathingNode_1024_CopyItems(char* dst, char* src, unsigned int count);
};

// Copies count elements of 0x3c bytes from src to dst, iterating forward or backward depending on the relative order of dst and src.
// @fnv 0x006a2270
// src: COMMUNITY 0x006a2270
void __thiscall FUN_006a2270_class::BSSimpleArray_PathingNode_1024_CopyItems(char* dst, char* src, unsigned int count)
{
    if (count <= 0)
        return;
    if (dst < src)
    {
        for (unsigned int i = 0; i < count; ++i)
            FUN_00ec7230(dst + i * 0x3c, src + i * 0x3c, 0x3c);
    }
    else if (dst > src)
    {
        for (int i = (int)count - 1; i >= 0; --i)
            FUN_00ec7230(dst + i * 0x3c, src + i * 0x3c, 0x3c);
    }
}

struct FUN_006a26d0_class
{
    void __thiscall ConstructItems(int a, int b);
};
// @fnv 0x006a2310
// src: GUESS 0x006a2310 (confidence: low)
void __thiscall FUN_006a19b0::UpdateState_006a2310(int a, int b)
{
    ((int*)this)[1] = 0;
    ((int*)this)[2] = 0;
    ((int*)this)[3] = 0;
    if ((unsigned int)b > (unsigned int)a)
        a = b;
    if ((unsigned int)a > 0)
    {
        ((int*)this)[1] = ((int(__thiscall*)(FUN_006a19b0*, int))((int*)m_iWordAt00)[1])(this, a);
        ((int*)this)[3] = a;
    }
    if ((unsigned int)b > 0)
    {
        ((FUN_006a26d0_class*)this)->ConstructItems(((int*)this)[1], b);
        ((int*)this)[2] = b;
    }
}

struct FUN_006a2470_class
{
    virtual int Dummy();
    virtual int Write(unsigned int size);
    void ConstructPendingItems(int a, int b);
    int iSize;
    int iPosition;
    int iDataLength;
    void UpdateState_006a2470(unsigned int requested, unsigned int savedSize);
};

// @fnv 0x006a2470
// src: GUESS 0x006a2470 (confidence: low)
void FUN_006a2470_class::UpdateState_006a2470(unsigned int requested, unsigned int savedSize)
{
    iSize = 0;
    iPosition = 0;
    iDataLength = 0;
    if (savedSize > requested)
        requested = savedSize;
    if (requested > 0)
    {
        iSize = Write(requested);
        iDataLength = requested;
    }
    if (savedSize > 0)
    {
        ConstructPendingItems(iSize, savedSize);
        iPosition = savedSize;
    }
}

namespace fnv_006a64e0 {
extern "C" void* __cdecl NiMalloc(unsigned int);
extern "C" void* __cdecl memset(void*, int, unsigned int);
struct FUN_006a64e0_class
{
    int* m_p;
    FUN_006a64e0_class* __thiscall ConstructIntArray(int arg);
};
// @fnv 0x006a64e0
FUN_006a64e0_class* FUN_006a64e0_class::ConstructIntArray(int aiCount)
{
    m_p = (int*)" hj";
    *(int*)((char*)this + 4) = aiCount;
    *(int*)((char*)this + 12) = 0;
    int n = *(int*)((char*)this + 4) << 2;
    *(int*)((char*)this + 8) = (int)NiMalloc((unsigned int)n);
    memset(*(void**)((char*)this + 8), 0, (unsigned int)*(int*)((char*)this + 4) << 2);
    return this;
}
}  // namespace fnv_006a64e0

struct BaseS
{
    BaseS();
    ~BaseS();
};
struct FUN_006a7b10 : BaseS
{
    FUN_006a7b10();
};
extern int DAT_0106b78c;
struct FUN_006a9200 : FUN_006a7b10
{
    FUN_006a9200();
};
// Sets the vtable pointer, constructs two BaseS subobjects at offsets 0x2070 and 0x2084, and zeroes the int at 0x2058 and byte at 0x2080.
// @fnv 0x006a9200
FUN_006a9200::FUN_006a9200()
{
    *(int*)this = (int)&DAT_0106b78c;
    ((BaseS*)((char*)this + 0x2070))->BaseS::BaseS();
    ((BaseS*)((char*)this + 0x2084))->BaseS::BaseS();
    *(int*)((char*)this + 0x2058) = 0;
    *(unsigned char*)((char*)this + 0x2080) = 0;
}

struct FUN_006b3f40_Ifc
{
    virtual void v0();
    virtual void* v1(unsigned int);
};
struct FUN_006d03d0_Ifc
{
    void ConstructParentSpaceNodes(FUN_006b3f40_Ifc*, unsigned int);
};
struct FUN_006b3f40_Class
{
    void* vtbl;
    void BSSimpleArray_NavMeshPOVSearchNode_1024_InitialSetup(unsigned int a, unsigned int b);
};
// @fnv 0x006b3f40
// src: COMMUNITY 0x006b3f40
void FUN_006b3f40_Class::BSSimpleArray_NavMeshPOVSearchNode_1024_InitialSetup(unsigned int a, unsigned int b)
{
    *(void**)((char*)this + 4) = 0;
    *(unsigned int*)((char*)this + 8) = 0;
    *(unsigned int*)((char*)this + 0xc) = 0;
    if (b > a)
        a = b;
    if (a > 0)
    {
        *(void**)((char*)this + 4) = ((FUN_006b3f40_Ifc*)this)->v1(a);
        *(unsigned int*)((char*)this + 0xc) = a;
    }
    if (b > 0)
    {
        ((FUN_006d03d0_Ifc*)this)->ConstructParentSpaceNodes((FUN_006b3f40_Ifc*)*(void**)((char*)this + 4), b);
        *(unsigned int*)((char*)this + 8) = b;
    }
}

struct S5460
{
    bool BSSimpleArray_NavMeshInfo_1024_ShouldGrow();
    unsigned int BSSimpleArray_NavMeshInfo_1024_GetNewSizeForGrow();
};
struct FUN_006f9eb0_class
{
    void BSSimpleArray_Resize_0(unsigned int, int);
};
struct FUN_006b4060_class
{
    void* vtbl;
    void* m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int GetNextIndex();
};
// @fnv 0x006b4060
int FUN_006b4060_class::GetNextIndex()
{
    if (((S5460*)this)->BSSimpleArray_NavMeshInfo_1024_ShouldGrow())
    {
        if (!m_iThirdValue)
        {
            int n = 4;
            m_iWordAt04 = (*(void**(__thiscall*)(void*, int))(*(void***)this)[1])(this, n);
            m_iThirdValue = n;
        }
        else
        {
            unsigned int idx = ((S5460*)this)->BSSimpleArray_NavMeshInfo_1024_GetNewSizeForGrow();
            ((FUN_006f9eb0_class*)this)->BSSimpleArray_Resize_0(idx, m_8);
            m_iThirdValue = idx;
        }
    }
    ++m_8;
    return m_8 - 1;
}



struct DA00694f80
{
    unsigned short& GetAt(int index);
};
struct EdgeArr
{
    unsigned short& Object_GetIndexedValue_006a1440(unsigned int index);
};
unsigned int __cdecl MaxUnsigned(unsigned int, unsigned short);
struct FUN_006bc940_class
{
    NavMesh* mesh;
    void* p1;
    BlkOffset08View* flags;
    unsigned int NavMeshObstacleCutter_GetTrianglesMaxObstacleCount();
};
// @fnv 0x006bc940
// src: COMMUNITY 0x006bc940
unsigned int FUN_006bc940_class::NavMeshObstacleCutter_GetTrianglesMaxObstacleCount()
{
    unsigned int result = 0;
    for (unsigned int i = 0; i < ((BlkOffset08View*)((char*)flags + 0x20))->GetFlags(); ++i)
        result =
            MaxUnsigned(result, mesh->GetTriangle(((DA00694f80*)((char*)flags + 0x20))->GetAt(i))->GetBits13To15());
    for (unsigned int j = 0; j < ((BlkOffset08View*)((char*)flags + 0x30))->GetFlags(); ++j)
        result =
            MaxUnsigned(result, mesh->GetTriangle(((EdgeArr*)((char*)flags + 0x30))->Object_GetIndexedValue_006a1440(j))->GetBits13To15());
    return result;
}

struct FUN_006a0580_class
{
    float m_iWordAt00;
    float m_iWordAt04;
    FUN_006a0580_class& MultiplyConjugateXYComponents(const float* o);
};
// @fnv 0x006a0580
// src: GUESS 0x006a0580 (confidence: medium)
FUN_006a0580_class& FUN_006a0580_class::MultiplyConjugateXYComponents(const float* afInput)
{
    float b = m_iWordAt00;
    float a = m_iWordAt04;
    m_iWordAt00 = b * afInput[0] + a * afInput[1];
    m_iWordAt04 = a * afInput[0] - b * afInput[1];
    return *this;
}

struct FUN_006d4ca0_Class
{
    unsigned char __thiscall Equals(FUN_006d4ca0_Class const* other);
};

// @fnv 0x006a1b80
// src: GUESS 0x006a1b80 (confidence: medium)
unsigned char Object_Equals_Thunk(FUN_006d4ca0_Class* apThis, FUN_006d4ca0_Class const* apOther)
{
    return apThis->Equals(apOther);
}

struct Elem3660
{
    int v;
};
struct Holder3660
{
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    virtual void v0();
    virtual int v1(unsigned int);
    void ConstructElementsInPlace(Elem3660*, int);
    void BSSimpleArray_NavMeshPOVSearchLink_1024_InitialSetup(unsigned int requested, unsigned int savedSize);
};
// @fnv 0x006a2130
// src: COMMUNITY 0x006a2130
void Holder3660::BSSimpleArray_NavMeshPOVSearchLink_1024_InitialSetup(unsigned int requested, unsigned int savedSize)
{
    m_iWordAt04 = 0;
    m_8 = 0;
    m_iThirdValue = 0;
    if (savedSize > requested)
    {
        requested = savedSize;
    }
    if (requested > 0)
    {
        m_iWordAt04 = v1(requested);
        m_iThirdValue = requested;
    }
    if (savedSize > 0)
    {
        ConstructElementsInPlace((Elem3660*)m_iWordAt04, savedSize);
        m_8 = savedSize;
    }
}

struct FUN_006a2a20
{
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    int f58;
    int f5c;
    int f60;
    int f64;
    int f68;
    int f6c;
    int f70;
    int f74;
    int f78;
    int f7c;
    int f80;
    int f84;
    int f88;
    int f8c;
    int f90;
    int f94;
    int f98;
    int f9c;
    int fa0;
    int fa4;
    int fa8;
    int fac;
    int fb0;
    int fb4;
    int fb8;
    int fbc;
    int fc0;
    int fc4;
    int fc8;
    int fcc;
    int fd0;
    int fd4;
    int fd8;
    int fdc;
    int fe0;
    int fe4;
    int fe8;
    int fec;
    int ff0;
    int ff4;
    int ff8;
    int ffc;
    int f100;
    int f104;
    int f108;
    int f10c;
    int f110;
    int f114;
    int f118;
    int f11c;
    int f120;
    int f124;
    int f128;
    int f12c;
    int f130;
    int f134;
    int f138;
    int f13c;
    int f140;
    int f144;
    int f148;
    int f14c;
    int f150;
    int f154;
    int f158;
    int f15c;
    int f160;
    int f164;
    int f168;
    int f16c;
    int f170;
    int f174;
    int f178;
    int f17c;
    int f180;
    int f184;
    int f188;
    int f18c;
    int f190;
    int f194;
    int f198;
    int f19c;
    int f1a0;
    int f1a4;
    int f1a8;
    int f1ac;
    int f1b0;
    int f1b4;
    int f1b8;
    int f1bc;
    int f1c0;
    int f1c4;
    int f1c8;
    int f1cc;
    int f1d0;
    int f1d4;
    int f1d8;
    int f1dc;
    int f1e0;
    int f1e4;
    int f1e8;
    int f1ec;
    int f1f0;
    int f1f4;
    int f1f8;
    int f1fc;
    int f200;
    int f204;
    int f208;
    int f20c;
    int f210;
    FUN_006a2a20();
    ~FUN_006a2a20();
};
extern int DAT_011d6e2c;

// Allocates a new FUN_006a2a20 object and stores its pointer in DAT_011d6e2c.
// @fnv 0x006a2920
// src: COMMUNITY 0x006a2920
void NavMeshRender_InitSingleton()
{
    DAT_011d6e2c = (int)new FUN_006a2a20;
}

struct FUN_006a69b0_Class
{
    void* vtbl;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    virtual int v0();
    virtual int v1(int);
    void ConstructParams(int, int);
    void BSSimpleArray_NiColorA_1024_InitialSetup(unsigned int a, unsigned int b);
};

// @fnv 0x006a69b0
// src: COMMUNITY 0x006a69b0
void FUN_006a69b0_Class::BSSimpleArray_NiColorA_1024_InitialSetup(unsigned int a, unsigned int b)
{
    *(int*)((char*)this + 4) = 0;
    *(int*)((char*)this + 8) = 0;
    *(int*)((char*)this + 0xc) = 0;
    if (b > a)
        a = b;
    if (a > 0)
    {
        *(int*)((char*)this + 4) = v1(a);
        *(int*)((char*)this + 0xc) = a;
    }
    if (b > 0)
    {
        ConstructParams(*(int*)((char*)this + 4), b);
        *(int*)((char*)this + 8) = b;
    }
}

void* __cdecl memcpy(void* dst, const void* src, unsigned int count);
struct ScrapHeap2
{
    void* Allocate(unsigned int a, unsigned int b);
    void Deallocate(void*);
};
struct FUN_006abe40_Class
{
    unsigned int GetFlags();
    void* __thiscall ReallocateArray(void* src, int count);
};
// Allocates count*0xc bytes from the heap, copies GetFlags()*0xc bytes from src, frees src, and returns the new block.
// @fnv 0x006abe40
void* FUN_006abe40_Class::ReallocateArray(void* pSource, int count)
{
    void* dst = ((ScrapHeap2*)*(void**)((char*)this + 0x10))->Allocate(count * 0xc, DAT_010a2720);
    memcpy(dst, pSource, GetFlags() * 0xc);
    ((ScrapHeap2*)*(void**)((char*)this + 0x10))->Deallocate(pSource);
    return dst;
}

struct FUN_006967f0
{
    void Call(unsigned short a, unsigned int b);
};
struct FUN_006bebd0_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    void NavMeshObstacleCutter_RemoveTrianglesFromNavMeshGrid();
};
// @fnv 0x006bebd0
// src: COMMUNITY 0x006bebd0
void FUN_006bebd0_class::NavMeshObstacleCutter_RemoveTrianglesFromNavMeshGrid()
{
    if (*(int*)((char*)*(int*)((char*)this + 8) + 0x1c))
    {
        ((FUN_006967f0*)*(int*)((char*)this + 0))
            ->Call(*(unsigned short*)((char*)*(int*)((char*)this + 8) + 0x18),
                   *(int*)((char*)*(int*)((char*)this + 8) + 0x18) + *(int*)((char*)*(int*)((char*)this + 8) + 0x1c) -
                       1);
    }
}

struct S006bf170
{
    unsigned int FindIndexByValue(unsigned short v);
};
// Scans the array at offset 0x1c for the first element equal to v and returns its index, or -1 if not found.
// @fnv 0x006bf170
unsigned int S006bf170::FindIndexByValue(unsigned short ausValue)
{
    for (unsigned int i = 0; i < ((BlkOffset08View*)((char*)this + 0x1c))->GetFlags(); i++)
        if (*(unsigned short*)*(unsigned int*)((Arr*)((char*)this + 0x1c))->GetAt(i) == ausValue)
            return i;
    return (unsigned int)-1;
}

struct FUN_006bf340_Class
{
    bool ComputeValue_006bf340(unsigned char** a);
};

// @fnv 0x006bf340
// src: GUESS 0x006bf340 (confidence: low)
bool FUN_006bf340_Class::ComputeValue_006bf340(unsigned char** apBuffers)
{
    if (!apBuffers[0][2] && apBuffers[0][6])
        return true;
    if (!apBuffers[1][2] && apBuffers[1][6])
        return true;
    if (apBuffers[0][2] && apBuffers[1][2] && *(int*)(apBuffers + 4) != 1)
        return true;
    return false;
}

struct FUN_006bf480_Class
{
    unsigned short m_iWordAt00;
    unsigned char m_cByteAtOffset2;
    unsigned char m_cByteAtOffset3;
    unsigned char m_iWordAt04;
    unsigned char m_5;
    unsigned char m_6;
    FUN_006bf480_Class(unsigned short a, unsigned char b, unsigned char c, unsigned char d);
};

// Initializes the object's fields from the four constructor arguments and zeroes the two trailing bytes.
// @fnv 0x006bf480
FUN_006bf480_Class::FUN_006bf480_Class(unsigned short a, unsigned char b, unsigned char c, unsigned char d)
{
    m_iWordAt00 = a;
    m_cByteAtOffset2 = b;
    m_cByteAtOffset3 = c;
    m_iWordAt04 = d;
    m_5 = 0;
    m_6 = 0;
}

struct S006bfd40
{
    unsigned int BSSimpleArray_CombatSearchLocation_1024_AddUninitialized();
};
struct S006bfdd0
{
    void ConstructEntries(void* p, int a);
};
struct S006bf730
{
    int m_iWordAt00;
    int m_iWordAt04;
    unsigned int UpdateState_006bf730(const S006bfc40& o);
};
// @fnv 0x006bf730
// src: GUESS 0x006bf730 (confidence: low)
unsigned int S006bf730::UpdateState_006bf730(const S006bfc40& o)
{
    unsigned int r = ((S006bfd40*)this)->BSSimpleArray_CombatSearchLocation_1024_AddUninitialized();
    ((S006bfdd0*)this)->ConstructEntries((char*)this->m_iWordAt04 + r * 0x1c, 1);
    ((S006bfc40*)((char*)this->m_iWordAt04 + r * 0x1c))->CopyFields_006bfc40(o);
    return r;
}

struct FUN_006bfdd0_class
{
    virtual void v0();
    virtual unsigned int Write(unsigned int);
    void ConstructEntries(unsigned int a, unsigned int b);
    unsigned int iSize;
    unsigned int iPosition;
    unsigned int iDataLength;
    void BSSimpleArray_PortalEdgeSwap_1024_InitialSetup(unsigned int requested, unsigned int savedSize);
};

// @fnv 0x006bfe70
// src: COMMUNITY 0x006bfe70
void FUN_006bfdd0_class::BSSimpleArray_PortalEdgeSwap_1024_InitialSetup(unsigned int requested, unsigned int savedSize)
{
    iSize = 0;
    iPosition = 0;
    iDataLength = 0;
    if (savedSize > requested)
    {
        requested = savedSize;
    }
    if (requested > 0)
    {
        iSize = Write(requested);
        iDataLength = requested;
    }
    if (savedSize > 0)
    {
        ConstructEntries(iSize, savedSize);
        iPosition = savedSize;
    }
}

struct FUN_006bde50
{
    bool CanAddEdge(void*, void*);
    void* CreateObject(void*, void*, int);
    void DoWork();
};
// For each flagged actor, scans the array for eligible other actors, tests them with CanAddEdge and appends CreateObject results to the array at offset 0x30.
// @fnv 0x006bde50
void FUN_006bde50::DoWork()
{
    for (unsigned int i = 0; i < ((BlkOffset08View*)((char*)this + 0x1c))->GetFlags(); i++)
    {
        void* actor = (void*)(*(unsigned int*)((Arr*)((char*)this + 0x1c))->GetAt(i));
        if (!((unsigned char*)actor)[2])
            continue;
        for (unsigned int j = 0; j < ((BlkOffset08View*)((char*)this + 0x1c))->GetFlags(); j++)
        {
            void* other = (void*)(*(unsigned int*)((Arr*)((char*)this + 0x1c))->GetAt(j));
            if (((unsigned char*)other)[6])
                continue;
            if (!((unsigned char*)other)[3] && !((unsigned char*)other)[4])
                continue;
            if (CanAddEdge(actor, other))
            {
                void* result = CreateObject(actor, other, 0);
                ((BSSimpleArray<void*>*)((char*)this + 0x30))->Add(result);
            }
        }
    }
}

template <> void BSSimpleArray<Actor*>::Clear(bool)
{}

// @fnv 0x006a1890
// src: GUESS 0x006a1890 (confidence: low)
void FUN_006a1890_class::SetVtableAndProcessState_006a1890()
{
    *reinterpret_cast<int**>(this) = &DAT_0106b3e8;
    reinterpret_cast<BSSimpleArray<Actor*>*>(this)->Clear(true);
}

struct FUN_006a1f70_class
{
    int AStarNodeHeap_PathSmootherPOVNode_PathSmootherPOVLink_512_AStarNodeHeap_PathSmootherPOVNode_PathSmootherPOVLink_512();
};

// @fnv 0x006a1f70
// src: COMMUNITY 0x006a1f70
int FUN_006a1f70_class::AStarNodeHeap_PathSmootherPOVNode_PathSmootherPOVLink_512_AStarNodeHeap_PathSmootherPOVNode_PathSmootherPOVLink_512()
{
    ((FUN_00aa5410_Helper*)this)->InitWithAlignedSize(0xd000);
    return (int)this;
}

struct FUN_00692480
{
    void Method(char*, char*, unsigned int);
};

struct FUN_006c8a30_Class
{
    void FUN_006a8500();
};

struct StandIn
{
    virtual int f0(unsigned int);
    virtual char* f4(unsigned int);
    virtual int f8(unsigned int);
    virtual char* fc(char*, unsigned int);

    char* m_iWordAt04;
    int m_8;
    unsigned int m_iThirdValue;

    void BSSimpleArray_NiPoint2_1024_ReallocateBuffer(unsigned int, unsigned int);
};

int StandIn::f0(unsigned int)
{
    return 0;
}

char* StandIn::f4(unsigned int)
{
    return 0;
}

int StandIn::f8(unsigned int)
{
    return 0;
}

char* StandIn::fc(char*, unsigned int)
{
    return 0;
}

// @fnv 0x006a2770
// src: XBOX_PDB 0x006a2770
void StandIn::BSSimpleArray_NiPoint2_1024_ReallocateBuffer(unsigned int a, unsigned int b)
{
    if (this->m_iWordAt04 != 0)
    {
        if (b == this->m_iThirdValue)
        {
            this->m_iWordAt04 = this->fc(this->m_iWordAt04, a);
        }
        else
        {
            char* result = this->f4(a);
            reinterpret_cast<FUN_00692480*>(this)->Method(result, this->m_iWordAt04, b);
            reinterpret_cast<FUN_006c8a30_Class*>(this)->FUN_006a8500();
            this->m_iWordAt04 = result;
        }
    }
    else
    {
        this->m_iWordAt04 = this->f4(a);
        this->m_iThirdValue = a;
    }
}

struct FUN_006a68d0_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    GO m_8;
    void ForwardCall_006a68d0();
};
// @fnv 0x006a68d0
// src: GUESS 0x006a68d0 (confidence: low)
void FUN_006a68d0_Class::ForwardCall_006a68d0()
{
    m_8.GO::~GO();
}

extern int DAT_0106b6fc;

struct FUN_006a8a80 : public FUN_006a7b10
{
    FUN_006a8a80();
};

// @fnv 0x006a8a80
FUN_006a8a80::FUN_006a8a80() : FUN_006a7b10()
{
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_0106b6fc);

    reinterpret_cast<BSSimpleList<BGSPerk*>*>(reinterpret_cast<char*>(this) + 0x2074)->GetItem();
    reinterpret_cast<BSSimpleList<BGSPerk*>*>(reinterpret_cast<char*>(this) + 0x2080)->GetItem();
    reinterpret_cast<BSSimpleList<BGSPerk*>*>(reinterpret_cast<char*>(this) + 0x208c)->GetItem();

    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x2058) = 0;
}

struct FUN_006b9540_class
{
    void UnlinkFromNeighbors(int param_1);
};

// Unlinks the node at param_1 from its previous and next neighbours, then clears both neighbour pointers.
// @fnv 0x006b9540
void FUN_006b9540_class::UnlinkFromNeighbors(int pNode)
{
    if (*(int*)(pNode + 0x14) != 0)
    {
        **(int**)(pNode + 0x14) = *(int*)(pNode + 0x18);
    }
    if (*(int*)(pNode + 0x18) != 0)
    {
        *(int*)(*(int*)(pNode + 0x18) + 0x14) = *(int*)(pNode + 0x14);
    }
    *(int*)(pNode + 0x14) = 0;
    *(int*)(pNode + 0x18) = 0;
}

struct FUN_006bbc30_ScrapHeap
{
    void __thiscall ScrapHeapBuffer();
};

struct FUN_006bbc30_class
{
    FUN_006bbc30_class* __thiscall EvaluateValue_006bbc30();
};

// @fnv 0x006bbc30
// src: GUESS 0x006bbc30 (confidence: low)
FUN_006bbc30_class* __thiscall FUN_006bbc30_class::EvaluateValue_006bbc30()
{
    reinterpret_cast<FUN_006bbc30_ScrapHeap*>(this)->ScrapHeapBuffer();
    return this;
}



struct FUN_006be660_class
{
    void NavMeshObstacleCutter_AddNewPOVs();
};

// @fnv 0x006be660
// src: COMMUNITY 0x006be660
void FUN_006be660_class::NavMeshObstacleCutter_AddNewPOVs()
{
    for (unsigned int i = 0; i < reinterpret_cast<BlkOffset08View*>(reinterpret_cast<char*>(this) + 0x1c)->GetFlags(); ++i)
    {
        if (reinterpret_cast<unsigned char*>(
                reinterpret_cast<Arr*>(reinterpret_cast<char*>(this) + 0x1c)->GetAt(i)[0])[2])
        {
            reinterpret_cast<BSSimpleArray<unsigned short, 1024>*>(
                reinterpret_cast<char*>(*reinterpret_cast<void**>(this)) + 0xe4)
                ->Add(*reinterpret_cast<unsigned short const*>(
                    reinterpret_cast<Arr*>(reinterpret_cast<char*>(this) + 0x1c)->GetAt(i)[0]));

            reinterpret_cast<BSSimpleArray<unsigned short, 1024>*>(
                reinterpret_cast<char*>(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 8)) + 0x60)
                ->Add(*reinterpret_cast<unsigned short const*>(
                    reinterpret_cast<Arr*>(reinterpret_cast<char*>(this) + 0x1c)->GetAt(i)[0]));
        }
    }
}

struct FUN_00693bd0_class
{
    void NavMeshTriangle_SetObjectCount(unsigned short value);
};

struct FUN_006be770_Info
{
    unsigned char m_00[0x18];
    int m_18;
    int m_1c;
    unsigned char m_20[0x10];
    EdgeArr m_30;
};

struct FUN_006be770_class
{
    NavMesh* m_00;
    unsigned char m_04[4];
    FUN_006be770_Info* m_08;
    unsigned char m_0c[0x38];
    int m_44;

    void NavMeshObstacleCutter_SetObstacleCount();
};

// @fnv 0x006be770
// src: COMMUNITY 0x006be770
void FUN_006be770_class::NavMeshObstacleCutter_SetObstacleCount()
{
    for (unsigned int i = m_08->m_18; i < (unsigned int)(m_08->m_18 + m_08->m_1c); ++i)
    {
        reinterpret_cast<FUN_00693bd0_class*>(m_00->GetTriangle((unsigned short)i))->NavMeshTriangle_SetObjectCount(m_44 + 1);
    }

    for (unsigned int j = 0; j < reinterpret_cast<BlkOffset08View*>(&m_08->m_30)->GetFlags(); ++j)
    {
        NavMeshTriangle* triangle = m_00->GetTriangle(m_08->m_30.Object_GetIndexedValue_006a1440(j));

        reinterpret_cast<FUN_00693bd0_class*>(triangle)->NavMeshTriangle_SetObjectCount(triangle->GetBits13To15() + 1);
    }
}

extern float g_011c7278_arg1;
bool __cdecl NavMeshObstacleManager_IsPointInBox(Point3Storage const&, void* const&, float, float);

struct FUN_006bf2d0_class
{
    int m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    bool NavMeshObstacleCutter_IsPointInObstacleArea(Point3Storage* p);
};

// @fnv 0x006bf2d0
// src: XBOX_PDB 0x006bf2d0
bool FUN_006bf2d0_class::NavMeshObstacleCutter_IsPointInObstacleArea(Point3Storage* p)
{
    for (unsigned int i = 0; i < ((BlkOffset08View*)((char*)m_8 + 0x20))->GetFlags(); i++)
    {
        if (NavMeshObstacleManager_IsPointInBox(*p, *(void**)&m_iWordAt04, g_011c7278_arg1, 32.0f))
            return true;
    }
    return false;
}

// Compares the values pointed to by a and b, returning 1 if a's value is greater, -1 if b's is greater, else 0.
// @fnv 0x006bfb30
// src: GUESS 0x006bfb30 (confidence: high)
int __cdecl Runtime_CompareUnsignedValues(unsigned int* puiLeft, unsigned int* puiRight)
{
    unsigned int* p = puiLeft;
    unsigned int* RunFourthVirtual = puiRight;
    if (*p > *RunFourthVirtual)
        return 1;
    else if (*RunFourthVirtual > *p)
        return -1;
    else
        return 0;
}

int __fastcall GetSignFlags(float* pfValue);

struct A06F0Key
{
    float m_fKey;
    float m_fTime;

    bool CompareKeysBySignAndTime(A06F0Key* pkOther);
};

// Compares this key with another by the result of GetSignFlags on m_fKey, then by m_fTime (ascending for 0/3, descending otherwise).
// @fnv 0x006a06f0
// src: GUESS 0x006a06f0 (confidence: high)
bool A06F0Key::CompareKeysBySignAndTime(A06F0Key* pkOther)
{
    int iThis = GetSignFlags(&m_fKey);
    int iOtherSignFlags = GetSignFlags(&pkOther->m_fKey);
    if (iThis < iOtherSignFlags)
        return true;
    else if (iThis > iOtherSignFlags)
        return false;
    else if (iThis == 0 || iThis == 3)
        return m_fTime <= pkOther->m_fTime;
    else
        return m_fTime >= pkOther->m_fTime;
}

struct MemberA_6a1500
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    MemberA_6a1500();
    ~MemberA_6a1500();
};

struct MemberB_6a1500
{
    int unk0000, unk0004, unk0008, unk000C, unk0010, unk0014, unk0018, unk001C;
    int unk0020, unk0024, unk0028, unk002C, unk0030, unk0034, unk0038, unk003C;
    int unk0040, unk0044, unk0048, unk004C, unk0050, unk0054, unk0058, unk005C;
    int unk0060, unk0064, unk0068, unk006C, unk0070, unk0074, unk0078, unk007C;
    int unk0080, unk0084, unk0088, unk008C, unk0090, unk0094, unk0098, unk009C;
    int unk00A0, unk00A4, unk00A8, unk00AC, unk00B0, unk00B4, unk00B8, unk00BC;
    int unk00C0, unk00C4, unk00C8, unk00CC, unk00D0, unk00D4, unk00D8, unk00DC;
    int unk00E0, unk00E4, unk00E8, unk00EC, unk00F0, unk00F4, unk00F8, unk00FC;
    int unk0100, unk0104, unk0108, unk010C, unk0110, unk0114, unk0118, unk011C;
    int unk0120, unk0124, unk0128, unk012C, unk0130, unk0134, unk0138, unk013C;
    int unk0140, unk0144, unk0148, unk014C, unk0150, unk0154, unk0158, unk015C;
    int unk0160, unk0164, unk0168, unk016C, unk0170, unk0174, unk0178, unk017C;
    int unk0180, unk0184, unk0188, unk018C, unk0190, unk0194, unk0198, unk019C;
    int unk01A0, unk01A4, unk01A8, unk01AC, unk01B0, unk01B4, unk01B8, unk01BC;
    int unk01C0, unk01C4, unk01C8, unk01CC, unk01D0, unk01D4, unk01D8, unk01DC;
    int unk01E0, unk01E4, unk01E8, unk01EC, unk01F0, unk01F4, unk01F8, unk01FC;
    int unk0200, unk0204, unk0208, unk020C, unk0210, unk0214, unk0218, unk021C;
    int unk0220, unk0224, unk0228, unk022C, unk0230, unk0234, unk0238, unk023C;
    int unk0240, unk0244, unk0248, unk024C, unk0250, unk0254, unk0258, unk025C;
    int unk0260, unk0264, unk0268, unk026C, unk0270, unk0274, unk0278, unk027C;
    int unk0280, unk0284, unk0288, unk028C, unk0290, unk0294, unk0298, unk029C;
    int unk02A0, unk02A4, unk02A8, unk02AC, unk02B0, unk02B4, unk02B8, unk02BC;
    int unk02C0, unk02C4, unk02C8, unk02CC, unk02D0, unk02D4, unk02D8, unk02DC;
    int unk02E0, unk02E4, unk02E8, unk02EC, unk02F0, unk02F4, unk02F8, unk02FC;
    int unk0300, unk0304, unk0308, unk030C, unk0310, unk0314, unk0318, unk031C;
    int unk0320, unk0324, unk0328, unk032C, unk0330, unk0334, unk0338, unk033C;
    int unk0340, unk0344, unk0348, unk034C, unk0350, unk0354, unk0358, unk035C;
    int unk0360, unk0364, unk0368, unk036C, unk0370, unk0374, unk0378, unk037C;
    int unk0380, unk0384, unk0388, unk038C, unk0390, unk0394, unk0398, unk039C;
    int unk03A0, unk03A4, unk03A8, unk03AC, unk03B0, unk03B4, unk03B8, unk03BC;
    int unk03C0, unk03C4, unk03C8, unk03CC, unk03D0, unk03D4, unk03D8, unk03DC;
    int unk03E0, unk03E4, unk03E8, unk03EC, unk03F0, unk03F4, unk03F8, unk03FC;
    int unk0400, unk0404, unk0408, unk040C, unk0410, unk0414, unk0418, unk041C;
    int unk0420, unk0424, unk0428, unk042C, unk0430, unk0434, unk0438, unk043C;
    int unk0440, unk0444, unk0448, unk044C, unk0450, unk0454, unk0458, unk045C;
    int unk0460, unk0464, unk0468, unk046C, unk0470, unk0474, unk0478, unk047C;
    int unk0480, unk0484, unk0488, unk048C, unk0490, unk0494, unk0498, unk049C;
    int unk04A0, unk04A4, unk04A8, unk04AC, unk04B0, unk04B4, unk04B8, unk04BC;
    int unk04C0, unk04C4, unk04C8, unk04CC, unk04D0, unk04D4, unk04D8, unk04DC;
    int unk04E0, unk04E4, unk04E8, unk04EC, unk04F0, unk04F4, unk04F8, unk04FC;
    int unk0500, unk0504, unk0508, unk050C, unk0510, unk0514, unk0518, unk051C;
    int unk0520, unk0524, unk0528, unk052C, unk0530, unk0534, unk0538, unk053C;
    int unk0540, unk0544, unk0548, unk054C, unk0550, unk0554, unk0558, unk055C;
    int unk0560, unk0564, unk0568, unk056C, unk0570, unk0574, unk0578, unk057C;
    int unk0580, unk0584, unk0588, unk058C, unk0590, unk0594, unk0598, unk059C;
    int unk05A0, unk05A4, unk05A8, unk05AC, unk05B0, unk05B4, unk05B8, unk05BC;
    int unk05C0, unk05C4, unk05C8, unk05CC, unk05D0, unk05D4, unk05D8, unk05DC;
    int unk05E0, unk05E4, unk05E8, unk05EC, unk05F0, unk05F4, unk05F8, unk05FC;
    int unk0600, unk0604, unk0608, unk060C, unk0610, unk0614, unk0618, unk061C;
    int unk0620, unk0624, unk0628, unk062C, unk0630, unk0634, unk0638, unk063C;
    int unk0640, unk0644, unk0648, unk064C, unk0650, unk0654, unk0658, unk065C;
    int unk0660, unk0664, unk0668, unk066C, unk0670, unk0674, unk0678, unk067C;
    int unk0680, unk0684, unk0688, unk068C, unk0690, unk0694, unk0698, unk069C;
    int unk06A0, unk06A4, unk06A8, unk06AC, unk06B0, unk06B4, unk06B8, unk06BC;
    int unk06C0, unk06C4, unk06C8, unk06CC, unk06D0, unk06D4, unk06D8, unk06DC;
    int unk06E0, unk06E4, unk06E8, unk06EC, unk06F0, unk06F4, unk06F8, unk06FC;
    int unk0700, unk0704, unk0708, unk070C, unk0710, unk0714, unk0718, unk071C;
    int unk0720, unk0724, unk0728, unk072C, unk0730, unk0734, unk0738, unk073C;
    int unk0740, unk0744, unk0748, unk074C, unk0750, unk0754, unk0758, unk075C;
    int unk0760, unk0764, unk0768, unk076C, unk0770, unk0774, unk0778, unk077C;
    int unk0780, unk0784, unk0788, unk078C, unk0790, unk0794, unk0798, unk079C;
    int unk07A0, unk07A4, unk07A8, unk07AC, unk07B0, unk07B4, unk07B8, unk07BC;
    int unk07C0, unk07C4, unk07C8, unk07CC, unk07D0, unk07D4, unk07D8, unk07DC;
    int unk07E0, unk07E4, unk07E8, unk07EC, unk07F0, unk07F4, unk07F8, unk07FC;
    int unk0800, unk0804, unk0808, unk080C, unk0810, unk0814, unk0818, unk081C;
    int unk0820, unk0824, unk0828, unk082C, unk0830, unk0834, unk0838, unk083C;
    int unk0840, unk0844, unk0848, unk084C, unk0850, unk0854, unk0858, unk085C;
    int unk0860, unk0864, unk0868, unk086C, unk0870, unk0874, unk0878, unk087C;
    int unk0880, unk0884, unk0888, unk088C, unk0890, unk0894, unk0898, unk089C;
    int unk08A0, unk08A4, unk08A8, unk08AC, unk08B0, unk08B4, unk08B8, unk08BC;
    int unk08C0, unk08C4, unk08C8, unk08CC, unk08D0, unk08D4, unk08D8, unk08DC;
    int unk08E0, unk08E4, unk08E8, unk08EC, unk08F0, unk08F4, unk08F8, unk08FC;
    int unk0900, unk0904, unk0908, unk090C, unk0910, unk0914, unk0918, unk091C;
    int unk0920, unk0924, unk0928, unk092C, unk0930, unk0934, unk0938, unk093C;
    int unk0940, unk0944, unk0948, unk094C, unk0950, unk0954, unk0958, unk095C;
    int unk0960, unk0964, unk0968, unk096C, unk0970, unk0974, unk0978, unk097C;
    int unk0980, unk0984, unk0988, unk098C, unk0990, unk0994, unk0998, unk099C;
    int unk09A0, unk09A4, unk09A8, unk09AC, unk09B0, unk09B4, unk09B8, unk09BC;
    int unk09C0, unk09C4, unk09C8, unk09CC, unk09D0, unk09D4, unk09D8, unk09DC;
    int unk09E0, unk09E4, unk09E8, unk09EC, unk09F0, unk09F4, unk09F8, unk09FC;
    int unk0A00, unk0A04, unk0A08, unk0A0C, unk0A10, unk0A14, unk0A18, unk0A1C;
    int unk0A20, unk0A24, unk0A28, unk0A2C, unk0A30, unk0A34, unk0A38, unk0A3C;
    int unk0A40, unk0A44, unk0A48, unk0A4C, unk0A50, unk0A54, unk0A58, unk0A5C;
    int unk0A60, unk0A64, unk0A68, unk0A6C, unk0A70, unk0A74, unk0A78, unk0A7C;
    int unk0A80, unk0A84, unk0A88, unk0A8C, unk0A90, unk0A94, unk0A98, unk0A9C;
    int unk0AA0, unk0AA4, unk0AA8, unk0AAC, unk0AB0, unk0AB4, unk0AB8, unk0ABC;
    int unk0AC0, unk0AC4, unk0AC8, unk0ACC, unk0AD0, unk0AD4, unk0AD8, unk0ADC;
    int unk0AE0, unk0AE4, unk0AE8, unk0AEC, unk0AF0, unk0AF4, unk0AF8, unk0AFC;
    int unk0B00, unk0B04, unk0B08, unk0B0C, unk0B10, unk0B14, unk0B18, unk0B1C;
    int unk0B20, unk0B24, unk0B28, unk0B2C, unk0B30, unk0B34, unk0B38, unk0B3C;
    int unk0B40, unk0B44, unk0B48, unk0B4C, unk0B50, unk0B54, unk0B58, unk0B5C;
    int unk0B60, unk0B64, unk0B68, unk0B6C, unk0B70, unk0B74, unk0B78, unk0B7C;
    int unk0B80, unk0B84, unk0B88, unk0B8C, unk0B90, unk0B94, unk0B98, unk0B9C;
    int unk0BA0, unk0BA4, unk0BA8, unk0BAC, unk0BB0, unk0BB4, unk0BB8, unk0BBC;
    int unk0BC0, unk0BC4, unk0BC8, unk0BCC, unk0BD0, unk0BD4, unk0BD8, unk0BDC;
    int unk0BE0, unk0BE4, unk0BE8, unk0BEC, unk0BF0, unk0BF4, unk0BF8, unk0BFC;
    int unk0C00, unk0C04, unk0C08, unk0C0C, unk0C10, unk0C14, unk0C18, unk0C1C;
    int unk0C20, unk0C24, unk0C28, unk0C2C, unk0C30, unk0C34, unk0C38, unk0C3C;
    int unk0C40, unk0C44, unk0C48, unk0C4C, unk0C50, unk0C54, unk0C58, unk0C5C;
    int unk0C60, unk0C64, unk0C68, unk0C6C, unk0C70, unk0C74, unk0C78, unk0C7C;
    int unk0C80, unk0C84, unk0C88, unk0C8C, unk0C90, unk0C94, unk0C98, unk0C9C;
    int unk0CA0, unk0CA4, unk0CA8, unk0CAC, unk0CB0, unk0CB4, unk0CB8, unk0CBC;
    int unk0CC0, unk0CC4, unk0CC8, unk0CCC, unk0CD0, unk0CD4, unk0CD8, unk0CDC;
    int unk0CE0, unk0CE4, unk0CE8, unk0CEC, unk0CF0, unk0CF4, unk0CF8, unk0CFC;
    int unk0D00, unk0D04, unk0D08, unk0D0C, unk0D10, unk0D14, unk0D18, unk0D1C;
    int unk0D20, unk0D24, unk0D28, unk0D2C, unk0D30, unk0D34, unk0D38, unk0D3C;
    int unk0D40, unk0D44, unk0D48, unk0D4C, unk0D50, unk0D54, unk0D58, unk0D5C;
    int unk0D60, unk0D64, unk0D68, unk0D6C, unk0D70, unk0D74, unk0D78, unk0D7C;
    int unk0D80, unk0D84, unk0D88, unk0D8C, unk0D90, unk0D94, unk0D98, unk0D9C;
    int unk0DA0, unk0DA4, unk0DA8, unk0DAC, unk0DB0, unk0DB4, unk0DB8, unk0DBC;
    int unk0DC0, unk0DC4, unk0DC8, unk0DCC, unk0DD0, unk0DD4, unk0DD8, unk0DDC;
    int unk0DE0, unk0DE4, unk0DE8, unk0DEC, unk0DF0, unk0DF4, unk0DF8, unk0DFC;
    int unk0E00, unk0E04, unk0E08, unk0E0C, unk0E10, unk0E14, unk0E18, unk0E1C;
    int unk0E20, unk0E24, unk0E28, unk0E2C, unk0E30, unk0E34, unk0E38, unk0E3C;
    int unk0E40, unk0E44, unk0E48, unk0E4C, unk0E50, unk0E54, unk0E58, unk0E5C;
    int unk0E60, unk0E64, unk0E68, unk0E6C, unk0E70, unk0E74, unk0E78, unk0E7C;
    int unk0E80, unk0E84, unk0E88, unk0E8C, unk0E90, unk0E94, unk0E98, unk0E9C;
    int unk0EA0, unk0EA4, unk0EA8, unk0EAC, unk0EB0, unk0EB4, unk0EB8, unk0EBC;
    int unk0EC0, unk0EC4, unk0EC8, unk0ECC, unk0ED0, unk0ED4, unk0ED8, unk0EDC;
    int unk0EE0, unk0EE4, unk0EE8, unk0EEC, unk0EF0, unk0EF4, unk0EF8, unk0EFC;
    int unk0F00, unk0F04, unk0F08, unk0F0C, unk0F10, unk0F14, unk0F18, unk0F1C;
    int unk0F20, unk0F24, unk0F28, unk0F2C, unk0F30, unk0F34, unk0F38, unk0F3C;
    int unk0F40, unk0F44, unk0F48, unk0F4C, unk0F50, unk0F54, unk0F58, unk0F5C;
    int unk0F60, unk0F64, unk0F68, unk0F6C, unk0F70, unk0F74, unk0F78, unk0F7C;
    int unk0F80, unk0F84, unk0F88, unk0F8C, unk0F90, unk0F94, unk0F98, unk0F9C;
    int unk0FA0, unk0FA4, unk0FA8, unk0FAC, unk0FB0, unk0FB4, unk0FB8, unk0FBC;
    int unk0FC0, unk0FC4, unk0FC8, unk0FCC, unk0FD0, unk0FD4, unk0FD8, unk0FDC;
    int unk0FE0, unk0FE4, unk0FE8, unk0FEC, unk0FF0, unk0FF4, unk0FF8, unk0FFC;
    int unk1000, unk1004, unk1008, unk100C, unk1010, unk1014, unk1018, unk101C;
    int unk1020, unk1024, unk1028, unk102C, unk1030, unk1034, unk1038, unk103C;
    int unk1040, unk1044, unk1048, unk104C, unk1050, unk1054, unk1058, unk105C;
    int unk1060, unk1064, unk1068, unk106C, unk1070, unk1074, unk1078, unk107C;
    int unk1080, unk1084, unk1088, unk108C, unk1090, unk1094, unk1098, unk109C;
    int unk10A0, unk10A4, unk10A8, unk10AC, unk10B0, unk10B4, unk10B8, unk10BC;
    int unk10C0, unk10C4, unk10C8, unk10CC, unk10D0, unk10D4, unk10D8, unk10DC;
    int unk10E0, unk10E4, unk10E8, unk10EC, unk10F0, unk10F4, unk10F8, unk10FC;
    int unk1100, unk1104, unk1108, unk110C, unk1110, unk1114, unk1118, unk111C;
    int unk1120, unk1124, unk1128, unk112C, unk1130, unk1134, unk1138, unk113C;
    int unk1140, unk1144, unk1148, unk114C, unk1150, unk1154, unk1158, unk115C;
    int unk1160, unk1164, unk1168, unk116C, unk1170, unk1174, unk1178, unk117C;
    int unk1180, unk1184, unk1188, unk118C, unk1190, unk1194, unk1198, unk119C;
    int unk11A0, unk11A4, unk11A8, unk11AC, unk11B0, unk11B4, unk11B8, unk11BC;
    int unk11C0, unk11C4, unk11C8, unk11CC, unk11D0, unk11D4, unk11D8, unk11DC;
    int unk11E0, unk11E4, unk11E8, unk11EC, unk11F0, unk11F4, unk11F8, unk11FC;
    int unk1200, unk1204, unk1208, unk120C, unk1210, unk1214, unk1218, unk121C;
    int unk1220, unk1224, unk1228, unk122C, unk1230, unk1234, unk1238, unk123C;
    int unk1240, unk1244, unk1248, unk124C, unk1250, unk1254, unk1258, unk125C;
    int unk1260, unk1264, unk1268, unk126C, unk1270, unk1274, unk1278, unk127C;
    int unk1280, unk1284, unk1288, unk128C, unk1290, unk1294, unk1298, unk129C;
    int unk12A0, unk12A4, unk12A8, unk12AC, unk12B0, unk12B4, unk12B8, unk12BC;
    int unk12C0, unk12C4, unk12C8, unk12CC, unk12D0, unk12D4, unk12D8, unk12DC;
    int unk12E0, unk12E4, unk12E8, unk12EC, unk12F0, unk12F4, unk12F8, unk12FC;
    int unk1300, unk1304, unk1308, unk130C, unk1310, unk1314, unk1318, unk131C;
    int unk1320, unk1324, unk1328, unk132C, unk1330, unk1334, unk1338, unk133C;
    int unk1340, unk1344, unk1348, unk134C, unk1350, unk1354, unk1358, unk135C;
    int unk1360, unk1364, unk1368, unk136C, unk1370, unk1374, unk1378, unk137C;
    int unk1380, unk1384, unk1388, unk138C, unk1390, unk1394, unk1398, unk139C;
    int unk13A0, unk13A4, unk13A8, unk13AC, unk13B0, unk13B4, unk13B8, unk13BC;
    int unk13C0, unk13C4, unk13C8, unk13CC, unk13D0, unk13D4, unk13D8, unk13DC;
    int unk13E0, unk13E4, unk13E8, unk13EC, unk13F0, unk13F4, unk13F8, unk13FC;
    int unk1400, unk1404, unk1408, unk140C, unk1410, unk1414, unk1418, unk141C;
    int unk1420, unk1424, unk1428, unk142C, unk1430, unk1434, unk1438, unk143C;
    int unk1440, unk1444, unk1448, unk144C, unk1450, unk1454, unk1458, unk145C;
    int unk1460, unk1464, unk1468, unk146C, unk1470, unk1474, unk1478, unk147C;
    int unk1480, unk1484, unk1488, unk148C, unk1490, unk1494, unk1498, unk149C;
    int unk14A0, unk14A4, unk14A8, unk14AC, unk14B0, unk14B4, unk14B8, unk14BC;
    int unk14C0, unk14C4, unk14C8, unk14CC, unk14D0, unk14D4, unk14D8, unk14DC;
    int unk14E0, unk14E4, unk14E8, unk14EC, unk14F0, unk14F4, unk14F8, unk14FC;
    int unk1500, unk1504, unk1508, unk150C, unk1510, unk1514, unk1518, unk151C;
    int unk1520, unk1524, unk1528, unk152C, unk1530, unk1534, unk1538, unk153C;
    int unk1540, unk1544, unk1548, unk154C, unk1550, unk1554, unk1558, unk155C;
    int unk1560, unk1564, unk1568, unk156C, unk1570, unk1574, unk1578, unk157C;
    int unk1580, unk1584, unk1588, unk158C, unk1590, unk1594, unk1598, unk159C;
    int unk15A0, unk15A4, unk15A8, unk15AC, unk15B0, unk15B4, unk15B8, unk15BC;
    int unk15C0, unk15C4, unk15C8, unk15CC, unk15D0, unk15D4, unk15D8, unk15DC;
    int unk15E0, unk15E4, unk15E8, unk15EC, unk15F0, unk15F4, unk15F8, unk15FC;
    int unk1600, unk1604, unk1608, unk160C, unk1610, unk1614, unk1618, unk161C;
    int unk1620, unk1624, unk1628, unk162C, unk1630, unk1634, unk1638, unk163C;
    int unk1640, unk1644, unk1648, unk164C, unk1650, unk1654, unk1658, unk165C;
    int unk1660, unk1664, unk1668, unk166C, unk1670, unk1674, unk1678, unk167C;
    int unk1680, unk1684, unk1688, unk168C, unk1690, unk1694, unk1698, unk169C;
    int unk16A0, unk16A4, unk16A8, unk16AC, unk16B0, unk16B4, unk16B8, unk16BC;
    int unk16C0, unk16C4, unk16C8, unk16CC, unk16D0, unk16D4, unk16D8, unk16DC;
    int unk16E0, unk16E4, unk16E8, unk16EC, unk16F0, unk16F4, unk16F8, unk16FC;
    int unk1700, unk1704, unk1708, unk170C, unk1710, unk1714, unk1718, unk171C;
    int unk1720, unk1724, unk1728, unk172C, unk1730, unk1734, unk1738, unk173C;
    int unk1740, unk1744, unk1748, unk174C, unk1750, unk1754, unk1758, unk175C;
    int unk1760, unk1764, unk1768, unk176C, unk1770, unk1774, unk1778, unk177C;
    int unk1780, unk1784, unk1788, unk178C, unk1790, unk1794, unk1798, unk179C;
    int unk17A0, unk17A4, unk17A8, unk17AC, unk17B0, unk17B4, unk17B8, unk17BC;
    int unk17C0, unk17C4, unk17C8, unk17CC, unk17D0, unk17D4, unk17D8, unk17DC;
    int unk17E0, unk17E4, unk17E8, unk17EC, unk17F0, unk17F4, unk17F8, unk17FC;
    int unk1800, unk1804, unk1808, unk180C, unk1810, unk1814, unk1818, unk181C;
    int unk1820, unk1824, unk1828, unk182C, unk1830, unk1834, unk1838, unk183C;
    int unk1840, unk1844, unk1848, unk184C, unk1850, unk1854, unk1858, unk185C;
    int unk1860, unk1864, unk1868, unk186C, unk1870, unk1874, unk1878, unk187C;
    int unk1880, unk1884, unk1888, unk188C, unk1890, unk1894, unk1898, unk189C;
    int unk18A0, unk18A4, unk18A8, unk18AC, unk18B0, unk18B4, unk18B8, unk18BC;
    int unk18C0, unk18C4, unk18C8, unk18CC, unk18D0, unk18D4, unk18D8, unk18DC;
    int unk18E0, unk18E4, unk18E8, unk18EC, unk18F0, unk18F4, unk18F8, unk18FC;
    int unk1900, unk1904, unk1908, unk190C, unk1910, unk1914, unk1918, unk191C;
    int unk1920, unk1924, unk1928, unk192C, unk1930, unk1934, unk1938, unk193C;
    int unk1940, unk1944, unk1948, unk194C, unk1950, unk1954, unk1958, unk195C;
    int unk1960, unk1964, unk1968, unk196C, unk1970, unk1974, unk1978, unk197C;
    int unk1980, unk1984, unk1988, unk198C, unk1990, unk1994, unk1998, unk199C;
    int unk19A0, unk19A4, unk19A8, unk19AC, unk19B0, unk19B4, unk19B8, unk19BC;
    int unk19C0, unk19C4, unk19C8, unk19CC, unk19D0, unk19D4, unk19D8, unk19DC;
    int unk19E0, unk19E4, unk19E8, unk19EC, unk19F0, unk19F4, unk19F8, unk19FC;
    int unk1A00, unk1A04, unk1A08, unk1A0C, unk1A10, unk1A14, unk1A18, unk1A1C;
    int unk1A20, unk1A24, unk1A28, unk1A2C, unk1A30, unk1A34, unk1A38, unk1A3C;
    int unk1A40, unk1A44, unk1A48, unk1A4C, unk1A50, unk1A54, unk1A58, unk1A5C;
    int unk1A60, unk1A64, unk1A68, unk1A6C, unk1A70, unk1A74, unk1A78, unk1A7C;
    int unk1A80, unk1A84, unk1A88, unk1A8C, unk1A90, unk1A94, unk1A98, unk1A9C;
    int unk1AA0, unk1AA4, unk1AA8, unk1AAC, unk1AB0, unk1AB4, unk1AB8, unk1ABC;
    int unk1AC0, unk1AC4, unk1AC8, unk1ACC, unk1AD0, unk1AD4, unk1AD8, unk1ADC;
    int unk1AE0, unk1AE4, unk1AE8, unk1AEC, unk1AF0, unk1AF4, unk1AF8, unk1AFC;
    int unk1B00, unk1B04, unk1B08, unk1B0C, unk1B10, unk1B14, unk1B18, unk1B1C;
    int unk1B20, unk1B24, unk1B28, unk1B2C, unk1B30, unk1B34, unk1B38, unk1B3C;
    int unk1B40, unk1B44, unk1B48, unk1B4C, unk1B50, unk1B54, unk1B58, unk1B5C;
    int unk1B60, unk1B64, unk1B68, unk1B6C, unk1B70, unk1B74, unk1B78, unk1B7C;
    int unk1B80, unk1B84, unk1B88, unk1B8C, unk1B90, unk1B94, unk1B98, unk1B9C;
    int unk1BA0, unk1BA4, unk1BA8, unk1BAC, unk1BB0, unk1BB4, unk1BB8, unk1BBC;
    int unk1BC0, unk1BC4, unk1BC8, unk1BCC, unk1BD0, unk1BD4, unk1BD8, unk1BDC;
    int unk1BE0, unk1BE4, unk1BE8, unk1BEC, unk1BF0, unk1BF4, unk1BF8, unk1BFC;
    int unk1C00, unk1C04, unk1C08, unk1C0C, unk1C10, unk1C14, unk1C18, unk1C1C;
    int unk1C20, unk1C24, unk1C28, unk1C2C, unk1C30, unk1C34, unk1C38, unk1C3C;
    int unk1C40, unk1C44, unk1C48, unk1C4C, unk1C50, unk1C54, unk1C58, unk1C5C;
    int unk1C60, unk1C64, unk1C68, unk1C6C, unk1C70, unk1C74, unk1C78, unk1C7C;
    int unk1C80, unk1C84, unk1C88, unk1C8C, unk1C90, unk1C94, unk1C98, unk1C9C;
    int unk1CA0, unk1CA4, unk1CA8, unk1CAC, unk1CB0, unk1CB4, unk1CB8, unk1CBC;
    int unk1CC0, unk1CC4, unk1CC8, unk1CCC, unk1CD0, unk1CD4, unk1CD8, unk1CDC;
    int unk1CE0, unk1CE4, unk1CE8, unk1CEC, unk1CF0, unk1CF4, unk1CF8, unk1CFC;
    int unk1D00, unk1D04, unk1D08, unk1D0C, unk1D10, unk1D14, unk1D18, unk1D1C;
    int unk1D20, unk1D24, unk1D28, unk1D2C, unk1D30, unk1D34, unk1D38, unk1D3C;
    int unk1D40, unk1D44, unk1D48, unk1D4C, unk1D50, unk1D54, unk1D58, unk1D5C;
    int unk1D60, unk1D64, unk1D68, unk1D6C, unk1D70, unk1D74, unk1D78, unk1D7C;
    int unk1D80, unk1D84, unk1D88, unk1D8C, unk1D90, unk1D94, unk1D98, unk1D9C;
    int unk1DA0, unk1DA4, unk1DA8, unk1DAC, unk1DB0, unk1DB4, unk1DB8, unk1DBC;
    int unk1DC0, unk1DC4, unk1DC8, unk1DCC, unk1DD0, unk1DD4, unk1DD8, unk1DDC;
    int unk1DE0, unk1DE4, unk1DE8, unk1DEC, unk1DF0, unk1DF4, unk1DF8, unk1DFC;
    int unk1E00, unk1E04, unk1E08, unk1E0C, unk1E10, unk1E14, unk1E18, unk1E1C;
    int unk1E20, unk1E24, unk1E28, unk1E2C, unk1E30, unk1E34, unk1E38, unk1E3C;
    int unk1E40, unk1E44, unk1E48, unk1E4C, unk1E50, unk1E54, unk1E58, unk1E5C;
    int unk1E60, unk1E64, unk1E68, unk1E6C, unk1E70, unk1E74, unk1E78, unk1E7C;
    int unk1E80, unk1E84, unk1E88, unk1E8C, unk1E90, unk1E94, unk1E98, unk1E9C;
    int unk1EA0, unk1EA4, unk1EA8, unk1EAC, unk1EB0, unk1EB4, unk1EB8, unk1EBC;
    int unk1EC0, unk1EC4, unk1EC8, unk1ECC, unk1ED0, unk1ED4, unk1ED8, unk1EDC;
    int unk1EE0, unk1EE4, unk1EE8, unk1EEC, unk1EF0, unk1EF4, unk1EF8, unk1EFC;
    int unk1F00, unk1F04, unk1F08, unk1F0C, unk1F10, unk1F14, unk1F18, unk1F1C;
    int unk1F20, unk1F24, unk1F28, unk1F2C, unk1F30, unk1F34, unk1F38, unk1F3C;
    int unk1F40, unk1F44, unk1F48, unk1F4C, unk1F50, unk1F54, unk1F58, unk1F5C;
    int unk1F60, unk1F64, unk1F68, unk1F6C, unk1F70, unk1F74, unk1F78, unk1F7C;
    int unk1F80, unk1F84, unk1F88, unk1F8C, unk1F90, unk1F94, unk1F98, unk1F9C;
    int unk1FA0, unk1FA4, unk1FA8, unk1FAC, unk1FB0, unk1FB4, unk1FB8, unk1FBC;
    int unk1FC0, unk1FC4, unk1FC8, unk1FCC, unk1FD0, unk1FD4, unk1FD8, unk1FDC;

    MemberB_6a1500();
    ~MemberB_6a1500();
};

struct MemberC_6a1500
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

    MemberC_6a1500();
};

struct FUN_006a1500_cls
{
    virtual void unk00();
    MemberA_6a1500 m_04;
    MemberB_6a1500 m_14;
    MemberC_6a1500 m_1ff4;
    int m_2048;
    int m_204c;
    int m_2050;
    char m_2054;

    FUN_006a1500_cls();
};

// Initializes m_2048, m_204c, m_2050 and m_2054 to zero; the member objects are constructed by their own constructors.
// @fnv 0x006a1500
FUN_006a1500_cls::FUN_006a1500_cls()
{
    m_2048 = 0;
    m_204c = 0;
    m_2050 = 0;
    m_2054 = 0;
}

struct FUN_006a1920_cls;

struct S6a21c0_helper
{
    void Call(void* p, int n);
};

struct FUN_006a1920_cls
{
    virtual void v0();
    virtual int v1(int a);
    int m_iWordAt04;
    int m_8;
    void* m_iThirdValue;
    int ProcessAndReturnValue_006a1920();
};

// @fnv 0x006a1920
// src: GUESS 0x006a1920 (confidence: low)
int FUN_006a1920_cls::ProcessAndReturnValue_006a1920()
{
    if (reinterpret_cast<S5460*>(this)->BSSimpleArray_NavMeshInfo_1024_ShouldGrow() != 0)
    {
        if (m_iThirdValue == 0)
        {
            int t = 4;
            m_iWordAt04 = v1(t);
            m_iThirdValue = (void*)t;
        }
        else
        {
            void* p = (void*)reinterpret_cast<S5460*>(this)->BSSimpleArray_NavMeshInfo_1024_GetNewSizeForGrow();
            reinterpret_cast<S6a21c0_helper*>(this)->Call(p, m_8);
            m_iThirdValue = p;
        }
    }
    m_8 = m_8 + 1;
    return m_8 - 1;
}

struct FUN_006a1a50_pair
{
    unsigned int lo;
    unsigned int hi;
};

struct FUN_006a1a50_cls
{
    int m_00;
    FUN_006a1a50_pair* m_04;
    int BSSimpleArray_NiPoint2_1024_AddUninitialized();
    void ConstructPendingItems(int a, int b);
    int UpdateState_006a1a50(const FUN_006a1a50_pair* src);
};

// @fnv 0x006a1a50
// src: GUESS 0x006a1a50 (confidence: low)
int FUN_006a1a50_cls::UpdateState_006a1a50(const FUN_006a1a50_pair* src)
{
    unsigned int idx = BSSimpleArray_NiPoint2_1024_AddUninitialized();
    ConstructPendingItems((int)(m_04 + idx), 1);
    m_04[idx] = *src;
    return idx;
}

struct FUN_006a21c0_class
{
    virtual void v0();
    virtual int v4(int value);
    virtual int v8(int value);
    virtual int vc(int value1, int value2);

    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;

    void __thiscall BSSimpleArray_PathingNode_1024_ReallocateBuffer(int value, int flag);
    void __thiscall BSSimpleArray_PathingNode_1024_CopyItems(int value1, int value2, int value3);
    void __thiscall FUN_006a8500();
};

// @fnv 0x006a21c0
// src: COMMUNITY 0x006a21c0
void __thiscall FUN_006a21c0_class::BSSimpleArray_PathingNode_1024_ReallocateBuffer(int value, int flag)
{
    if (m_iWordAt04 != 0)
    {
        if (flag == m_iThirdValue)
        {
            m_iWordAt04 = vc(m_iWordAt04, value);
        }
        else
        {
            int newValue = v4(value);
            BSSimpleArray_PathingNode_1024_CopyItems(newValue, m_iWordAt04, flag);
            FUN_006a8500();
            m_iWordAt04 = newValue;
        }
    }
    else
    {
        m_iWordAt04 = v4(value);
        m_iThirdValue = value;
    }
}

struct PendingItem
{
    int m_iWordAt00;
    int m_iWordAt04;
    PendingItem();
    void* operator new(unsigned int size, void* where);
    void operator delete(void* p, void* where);
};

PendingItem::PendingItem()
{}

void* PendingItem::operator new(unsigned int size, void* where)
{
    return where;
}

void PendingItem::operator delete(void* p, void* where)
{}

// Constructs b PendingItem objects in place in the array at a.
// @fnv 0x006a23a0
void FUN_006a2470_class::ConstructPendingItems(int apItems, int aiCount)
{
    for (unsigned int i = 0; i < (unsigned int)aiCount; i++)
    {
        new (&((PendingItem*)apItems)[i]) PendingItem;
    }
}

struct FUN_006a2500_base
{
    virtual void unk00();
    int m_04;
    int m_08;
    int m_0c;
    FUN_006a2500_base();
    ~FUN_006a2500_base();
};

struct Singleton_006a2500
{
    void* GetHandle();
};

Singleton_006a2500* MemoryManager_Instance();

struct FUN_006a2500_cls : FUN_006a2500_base
{
    void* m_10;
    FUN_006a2500_cls();
    void BSSimpleArray_float_1024_InitialSetup(unsigned int, unsigned int);
    virtual ~FUN_006a2500_cls();
};

// Initializes the object by storing the handle from FUN_00401020 and calling FUN_006b3eb0 with zero arguments.
// @fnv 0x006a2500
FUN_006a2500_cls::FUN_006a2500_cls()
{
    m_10 = MemoryManager_Instance()->GetHandle();
    BSSimpleArray_float_1024_InitialSetup(0, 0);
}

void __cdecl operator delete(void*, void*);

struct S_006a26d0_Item
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_006a26d0_Item();
};

// Placement-constructs count S_006a26d0_Item objects at base + i * 16.
// @fnv 0x006a26d0
void __thiscall FUN_006a26d0_class::ConstructItems(int base, int count)
{
    for (unsigned int i = 0; i < (unsigned int)count; i++)
    {
        new ((void*)(base + i * 16)) S_006a26d0_Item();
    }
}

extern int DAT_0106b460;

struct FUN_006a2900_shell
{
    int* vtable;
    void FUN_008454f0(int initialize);
    void SetVirtualTableAndProcessState_006a2900();
};

// @fnv 0x006a2900
// src: GUESS 0x006a2900 (confidence: low)
void FUN_006a2900_shell::SetVirtualTableAndProcessState_006a2900()
{
    vtable = &DAT_0106b460;
    FUN_008454f0(1);
}

class SlotSource;
class SlotNode;

struct SlotHolder
{
    int unk00;
    SlotSource* Get();
    void Clear(int flag);
};

struct SlotSource
{
    SlotNode* Resolve();
};

struct SlotNode
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
    virtual void v58(SlotSource* arg);
};

struct FUN_006a61b0_cls
{
    int unk00;
    SlotHolder m_04;
    SlotHolder m_08;
    void NavMeshRender_Update();
};

// Resolves and notifies each slot's node via v58, then clears both slot holders.
// @fnv 0x006a61b0
// src: COMMUNITY 0x006a61b0
void FUN_006a61b0_cls::NavMeshRender_Update()
{
    if (m_04.Get() && m_04.Get()->Resolve())
    {
        m_04.Get()->Resolve()->v58(m_04.Get());
    }
    if (m_08.Get() && m_08.Get()->Resolve())
    {
        m_08.Get()->Resolve()->v58(m_08.Get());
    }
    m_04.Clear(0);
    m_08.Clear(0);
}

struct FNVValue
{
    int data;
    void __thiscall FUN_0045cec0();
    __forceinline ~FNVValue()
    {
        FUN_0045cec0();
    }
};

struct FNVEmbedded
{
    void __thiscall FUN_006e5cc0(FNVValue* value);
};

struct FNVDestination
{
    int unk00;
    int unk04;
    FNVEmbedded embedded;
};

struct FNVHost
{
    void __thiscall SetDestinationValue(FNVDestination* destination, int value, FNVValue extra);
};

// Stores value into destination->unk04 and passes extra to destination->embedded.FUN_006e5cc0.
// @fnv 0x006a63e0
void FNVHost::SetDestinationValue(FNVDestination* destination, int value, FNVValue extraValue)
{
    destination->unk04 = value;
    destination->embedded.FUN_006e5cc0(&extraValue);
}

class Base_b9345
{
  public:
    virtual ~Base_b9345();
    unsigned int unk04;
    unsigned int unk08;
};

class FUN_006a6450 : public Base_b9345
{
  public:
    virtual ~FUN_006a6450();
    void DoCleanup();
};

// @fnv 0x006a6450
FUN_006a6450::~FUN_006a6450()
{
    DoCleanup();
}


void operator delete(void*, void*)
{}

// @fnv 0x006a68f0
void FUN_006a69b0_Class::ConstructParams(int aiBaseAddress, int aiCount)
{
    for (unsigned int i = 0; i < (unsigned int)aiCount; ++i)
    {
        new ((void*)(aiBaseAddress + i * 16)) NiColorA(0.0f, 0.0f, 0.0f, 0.0f);
    }
}

namespace fnv_006a8530 {
struct FUN_006a8530_base
{
    virtual void unk00();
    int m_04;
    int m_08;
    int m_0c;
    FUN_006a8530_base();
    ~FUN_006a8530_base();
};

struct Singleton_006a8530
{
    void* GetHandle();
};

Singleton_006a8530* MemoryManager_Instance();

struct FUN_006a8530_cls : FUN_006a8530_base
{
    void* m_10;
    FUN_006a8530_cls();
    void BSSimpleArray_float_1024_InitialSetup(unsigned int, unsigned int);
    virtual ~FUN_006a8530_cls();
};

// Stores the handle from FUN_00401020() in m_10, then calls FUN_006b3eb0(0, 0).
// @fnv 0x006a8530
FUN_006a8530_cls::FUN_006a8530_cls()
{
    m_10 = MemoryManager_Instance()->GetHandle();
    BSSimpleArray_float_1024_InitialSetup(0, 0);
}
}  // namespace fnv_006a8530

struct SlotNodeItem
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
    SlotNodeItem** m_2c;
    SlotNodeItem* m_30;
};

class SlotOwnerCls
{
  public:
    unsigned int unk00;
    SlotNodeItem* m_04[20];
    SlotNodeItem* PopSlotNode();
};

// @fnv 0x006a8660
SlotNodeItem* SlotOwnerCls::PopSlotNode()
{
    SlotNodeItem* result = 0;
    for (unsigned int i = 0; i < 20; ++i)
    {
        SlotNodeItem** slot = &m_04[i];
        if (*slot != 0)
        {
            result = *slot;
            if ((*slot)->m_30 != 0)
            {
                (*slot)->m_30->m_2c = slot;
                *slot = (*slot)->m_30;
            }
            else
            {
                *slot = 0;
            }
            result->m_2c = 0;
            result->m_30 = 0;
            break;
        }
    }
    return result;
}

extern int DAT_0106b830;
extern int DAT_0106b7f0;

struct FUN_006aa620_CallTarget
{
    void __thiscall FUN_00633c90(int value);
};

struct FUN_006aa620 : public FUN_006a7b10
{
    FUN_006aa620();
};

// @fnv 0x006aa620
FUN_006aa620::FUN_006aa620()
{
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_0106b830);

    reinterpret_cast<FUN_006aa620_CallTarget*>(reinterpret_cast<unsigned char*>(this) + 0x2070)->FUN_00633c90(0);

    *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(this) + 0x2058) = 0;

    *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(this) + 0x208C) = 0xFD;

    *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(this) + 0x2074) = 0;

    *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(this) + 0x2090) = 0;

    *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(this) + 0x2094) = 0;

    *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(this) + 0x2098) = 0;

    *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(this) + 0x209C) =
        *reinterpret_cast<float*>(&DAT_0106b7f0);
}

struct FUN_006ad2f0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_0c;
    void SetPackedField(unsigned short a, unsigned short b, unsigned char c, unsigned char d);
};

// @fnv 0x006ad2f0
void FUN_006ad2f0_cls::SetPackedField(unsigned short uiFieldIndex, unsigned short uiValue, unsigned char uiExtra1,
                                      unsigned char uiExtra2)
{
    if (uiFieldIndex == 2)
        return;
    if ((unsigned int)uiValue > 0xfu)
        uiValue = 0xf;
    int shift = uiFieldIndex * 6 + 16;
    unsigned int mask = 0x3f << shift;
    m_0c &= ~mask;
    if (uiValue > 0)
    {
        unsigned int val = uiValue << shift;
        if (uiValue > 1)
        {
            shift += 4;
            val |= uiExtra1 << shift;
            shift += 1;
            val |= uiExtra2 << shift;
        }
        m_0c |= val;
    }
}

extern float runtimeInitializationFloat2848;
float floor(float x);
float FUN_004e4430(float x);

// @fnv 0x006ad3b0
// src: COMMUNITY 0x006ad3b0
unsigned int NavMeshTriangle_GetCoverLevel(float value, bool roundDown, bool roundNear)
{
    float scaled = value * runtimeInitializationFloat2848;
    unsigned int result;
    if (roundNear)
    {
        float fFloor = floor(scaled);
        float fRemainder = scaled - fFloor;
        if (fRemainder < 0.25)
        {
            result = (unsigned int)fFloor;
        }
        else
        {
            result = (unsigned int)FUN_004e4430(scaled);
        }
    }
    else if (roundDown)
    {
        result = (unsigned int)floor(scaled);
    }
    else
    {
        result = (unsigned int)FUN_004e4430(scaled);
    }
    if (result > 15)
    {
        result = 15;
    }
    return result;
}

struct PathSmootherCleanup
{
    void FUN_006b3710();
    PathSmootherCleanup* FUN_006b3970(unsigned int flags);
};

// Calls FUN_006b3710, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x006b3970
PathSmootherCleanup* PathSmootherCleanup::FUN_006b3970(unsigned int flags)
{
    FUN_006b3710();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_006b3cb0_item
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
};

struct FUN_006b3cb0_pt
{
    void PathSmootherPOVLink_Copy();
};

struct FUN_006b3cb0_arg2
{
    FUN_006b3cb0_item* Object_GetIndexedValue_006a1440(int index);
    void UpdateState_006a8890(int a, int b);
};

struct FUN_006b3cb0_arg3
{
    FUN_006b3cb0_pt* GetBufferElementAddress(int index, void* p);
    void AllocateStorage_006b4450(int a, int b);
};

struct FUN_006b3cb0_node
{
    unsigned int unk00;
    unsigned int unk04;
    FUN_006b3cb0_item m_08;
    unsigned int m_14;
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
    FUN_006b3cb0_node* m_54;
};

class FUN_006b3cb0_cls
{
  public:
    bool CopyNodeListToArrays(FUN_006b3cb0_node* head, FUN_006b3cb0_arg2* a2, FUN_006b3cb0_arg3* a3);
};

// @fnv 0x006b3cb0
bool FUN_006b3cb0_cls::CopyNodeListToArrays(FUN_006b3cb0_node* head, FUN_006b3cb0_arg2* pItemArray,
                                            FUN_006b3cb0_arg3* pPointArray)
{
    if (head == 0)
    {
        return false;
    }
    FUN_006b3cb0_node* node7;
    int count = 0;
    node7 = head;
    while (node7 != 0)
    {
        count = count + 1;
        node7 = node7->m_54;
    }
    pItemArray->UpdateState_006a8890(count, 1);
    pPointArray->AllocateStorage_006b4450(count - 1, 1);
    node7 = head;
    int i6 = count - 1;
    while (node7 != 0)
    {
        *pItemArray->Object_GetIndexedValue_006a1440(i6) = node7->m_08;
        if (i6 > 0)
        {
            pPointArray->GetBufferElementAddress(i6 - 1, &node7->m_14)->PathSmootherPOVLink_Copy();
        }
        node7 = node7->m_54;
        i6 = i6 - 1;
    }
    return true;
}

struct SortNodeB5152
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
    SortNodeB5152** m_ppPrevious;
    SortNodeB5152* m_pNext;
    float GetKey();
};

class FUN_006b3e10_cls
{
  public:
    unsigned int m_uiItemCount;
    SortNodeB5152* m_buckets[1];
    unsigned int GetScaledValue(SortNodeB5152* node);
    void InsertSorted(SortNodeB5152* node);
};

// Computes a bucket index for node, walks that bucket's list while keys are smaller, then links node into the list at that position.
// @fnv 0x006b3e10
void FUN_006b3e10_cls::InsertSorted(SortNodeB5152* node)
{
    unsigned int idx = GetScaledValue(node);
    SortNodeB5152** pp = &m_buckets[idx];
    SortNodeB5152** slot = pp;
    while (*slot != 0 && (double)(*slot)->GetKey() < node->GetKey())
    {
        slot = &(*slot)->m_pNext;
    }
    if (*slot != 0)
    {
        (*slot)->m_ppPrevious = &node->m_pNext;
    }
    node->m_pNext = *slot;
    node->m_ppPrevious = slot;
    *slot = node;
}

struct FUN_006b3fd0_cls
{
    virtual void v0();
    virtual int v1(int arg);
    int m_04;
    int m_08;
    int m_0c;
    bool BSSimpleArray_NavMeshInfo_1024_ShouldGrow();
    int BSSimpleArray_NavMeshInfo_1024_GetNewSizeForGrow();
    void AllocateStorage_006b4590(int a, int b);
    unsigned int UpdateState_006b3fd0();
};

// @fnv 0x006b3fd0
// src: GUESS 0x006b3fd0 (confidence: low)
unsigned int FUN_006b3fd0_cls::UpdateState_006b3fd0()
{
    if (BSSimpleArray_NavMeshInfo_1024_ShouldGrow())
    {
        if (m_0c == 0)
        {
            int v = 4;
            m_04 = v1(v);
            m_0c = v;
        }
        else
        {
            int p = BSSimpleArray_NavMeshInfo_1024_GetNewSizeForGrow();
            AllocateStorage_006b4590(p, m_08);
            m_0c = p;
        }
    }
    m_08 = m_08 + 1;
    return m_08 - 1;
}

void* operator new(unsigned int uiSize, void* pvWhere);
void operator delete(void* pvMem, void* pvWhere);

class C6B40F0Element
{
  public:
    C6B40F0Element();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

class C6B40F0Allocator
{
  public:
    void ConstructElements(C6B40F0Element* pkElements, unsigned int ItemUpdateArray);
};

// Placement-constructs a C6B40F0Element in each of the given number of element slots.
// @fnv 0x006b40f0
void C6B40F0Allocator::ConstructElements(C6B40F0Element* pkElements, unsigned int auiCount)
{
    for (unsigned int i = 0; i < auiCount; i++)
        new (&pkElements[i]) C6B40F0Element;
}

// ---------------------------------------------------------------------------
// PopOpenNode - OpenList::PopOpenNode()
//
// The function walks the twenty slots of the open list (the array at +0x04 of
// the object) and takes the first slot that is still filled.  The node in that
// slot is unlinked from the doubly linked chain: the successor of the node
// takes over the slot and the node itself drops both of its chain links.
// The removed node is returned.
//
// The original is an unoptimised (/Od) build: `this` is spilled to
// [ebp-0x10], the three locals live at [ebp-0x04], [ebp-0x08] and
// [ebp-0x0c] and every value is read back from the frame.
// ---------------------------------------------------------------------------

// One node of the open list's chain.  The node knows the slot it was found
// in (+0x58) and the node that follows it in the chain (+0x5c).
struct FnvOpenNode
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
    FnvOpenNode** pSlot;  // +0x58, the slot this node was taken from
    FnvOpenNode* pNext;   // +0x5C, the next node of the chain
};

// The open list: a word at +0x00 and the twenty slots at +0x04.
struct FnvOpenList
{
    int unk00;
    FnvOpenNode* unk04[20];
    FnvOpenNode* PopOpenNode();
};

// Scans the 20 slots for the first non-null node, unlinks it from its list, clears its slot and next pointers, and returns it.
// @fnv 0x006b4350
FnvOpenNode* FnvOpenList::PopOpenNode()
{
    FnvOpenNode* pRes = 0;
    unsigned int idx;
    FnvOpenNode** pElem;
    for (idx = 0; idx < 20; idx++)
    {
        pElem = &unk04[idx];
        if (*pElem != 0)
        {
            pRes = *pElem;
            if ((*pElem)->pNext != 0)
            {
                (*pElem)->pNext->pSlot = pElem;
                *pElem = (*pElem)->pNext;
            }
            else
            {
                *pElem = 0;
            }
            pRes->pSlot = 0;
            pRes->pNext = 0;
            break;
        }
    }
    return pRes;
}

struct FUN_006b1d80_sub
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
    void FUN_006b1d80();
};

struct FUN_006b43f0_cls
{
    float m_00;
    float m_04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    FUN_006b1d80_sub m_14;
    unsigned int m_54;
    unsigned int m_58;
    unsigned int m_5c;
    unsigned int m_60;
    unsigned int m_64;
    FUN_006b43f0_cls* Constructor();
};

// Initializes the object: zeroes m_00 and m_04, calls m_14.FUN_006b1d80(), clears m_54 through m_64, and returns this.
// @fnv 0x006b43f0
FUN_006b43f0_cls* FUN_006b43f0_cls::Constructor()
{
    m_00 = 0.0f;
    m_04 = 0.0f;
    m_14.FUN_006b1d80();
    m_54 = 0;
    m_58 = 0;
    m_5c = 0;
    m_60 = 0;
    m_64 = 0;
    return this;
}

struct B4590Buffer
{
    virtual void vfunc00();
    virtual void* Allocate(unsigned int uiSize);
    virtual void vfunc08();
    virtual void* Reallocate(void* pBase, unsigned int uiSize);

    void* m_pBase;
    int unk08;
    unsigned int m_uiAllocated;

    void Copy(void* pDest, void* pSrc, unsigned int ItemUpdateArray);
    void Free();
    void AllocateStorage_006b4590(unsigned int uiNewSize, unsigned int uiOldSize);
};

// @fnv 0x006b4590
// src: GUESS 0x006b4590 (confidence: low)
void B4590Buffer::AllocateStorage_006b4590(unsigned int uiNewSize, unsigned int uiOldSize)
{
    if (m_pBase)
    {
        if (uiOldSize == m_uiAllocated)
        {
            m_pBase = Reallocate(m_pBase, uiNewSize);
        }
        else
        {
            void* pNew = Allocate(uiNewSize);
            Copy(pNew, m_pBase, uiOldSize);
            Free();
            m_pBase = pNew;
        }
    }
    else
    {
        m_pBase = Allocate(uiNewSize);
        m_uiAllocated = uiNewSize;
    }
}

class Sub_b9491
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    ~Sub_b9491();
};

class Sub2_b9491
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    ~Sub2_b9491();
};

class Ref54_b9491
{
  public:
    void PathingRequestCoveredMove_SetCombatCoverLocation(int a1);
};

class Ref58_b9491
{
  public:
    int NavMeshBounds_Destroy(int a1);
};

class FUN_006b4790_cls
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    Sub_b9491 m_24;
    Sub_b9491 m_34;
    Sub2_b9491 m_44;
    Ref54_b9491* m_54;
    Ref58_b9491* m_58;
    ~FUN_006b4790_cls();
};

// Destructor: if m_54 is set, calls FUN_006d3100(0) on it; if m_58 is set, calls FUN_006b4850(1) on it.
// @fnv 0x006b4790
FUN_006b4790_cls::~FUN_006b4790_cls()
{
    if (m_54 != 0)
    {
        m_54->PathingRequestCoveredMove_SetCombatCoverLocation(0);
    }
    if (m_58 != 0)
    {
        Ref58_b9491* a = m_58;
        Ref58_b9491* b5 = a;
        b5 ? b5->NavMeshBounds_Destroy(1) : 0;
    }
}

struct SubA
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    SubA();
    ~SubA();
};

struct SubB
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
    int unk0650;
    int unk0654;
    int unk0658;
    int unk065C;
    int unk0660;
    int unk0664;
    int unk0668;
    int unk066C;
    int unk0670;
    int unk0674;
    int unk0678;
    int unk067C;
    int unk0680;
    int unk0684;
    int unk0688;
    int unk068C;
    int unk0690;
    int unk0694;
    int unk0698;
    int unk069C;
    int unk06A0;
    int unk06A4;
    int unk06A8;
    int unk06AC;
    int unk06B0;
    int unk06B4;
    int unk06B8;
    int unk06BC;
    int unk06C0;
    int unk06C4;
    int unk06C8;
    int unk06CC;
    int unk06D0;
    int unk06D4;
    int unk06D8;
    int unk06DC;
    int unk06E0;
    int unk06E4;
    int unk06E8;
    int unk06EC;
    int unk06F0;
    int unk06F4;
    int unk06F8;
    int unk06FC;
    int unk0700;
    int unk0704;
    int unk0708;
    int unk070C;
    int unk0710;
    int unk0714;
    int unk0718;
    int unk071C;
    int unk0720;
    int unk0724;
    int unk0728;
    int unk072C;
    int unk0730;
    int unk0734;
    int unk0738;
    int unk073C;
    int unk0740;
    int unk0744;
    int unk0748;
    int unk074C;
    int unk0750;
    int unk0754;
    int unk0758;
    int unk075C;
    int unk0760;
    int unk0764;
    int unk0768;
    int unk076C;
    int unk0770;
    int unk0774;
    int unk0778;
    int unk077C;
    int unk0780;
    int unk0784;
    int unk0788;
    int unk078C;
    int unk0790;
    int unk0794;
    int unk0798;
    int unk079C;
    int unk07A0;
    int unk07A4;
    int unk07A8;
    int unk07AC;
    int unk07B0;
    int unk07B4;
    int unk07B8;
    int unk07BC;
    int unk07C0;
    int unk07C4;
    int unk07C8;
    int unk07CC;
    int unk07D0;
    int unk07D4;
    int unk07D8;
    int unk07DC;
    int unk07E0;
    int unk07E4;
    int unk07E8;
    int unk07EC;
    int unk07F0;
    int unk07F4;
    int unk07F8;
    int unk07FC;
    int unk0800;
    int unk0804;
    int unk0808;
    int unk080C;
    int unk0810;
    int unk0814;
    int unk0818;
    int unk081C;
    int unk0820;
    int unk0824;
    int unk0828;
    int unk082C;
    int unk0830;
    int unk0834;
    int unk0838;
    int unk083C;
    int unk0840;
    int unk0844;
    int unk0848;
    int unk084C;
    int unk0850;
    int unk0854;
    int unk0858;
    int unk085C;
    int unk0860;
    int unk0864;
    int unk0868;
    int unk086C;
    int unk0870;
    int unk0874;
    int unk0878;
    int unk087C;
    int unk0880;
    int unk0884;
    int unk0888;
    int unk088C;
    int unk0890;
    int unk0894;
    int unk0898;
    int unk089C;
    int unk08A0;
    int unk08A4;
    int unk08A8;
    int unk08AC;
    int unk08B0;
    int unk08B4;
    int unk08B8;
    int unk08BC;
    int unk08C0;
    int unk08C4;
    int unk08C8;
    int unk08CC;
    int unk08D0;
    int unk08D4;
    int unk08D8;
    int unk08DC;
    int unk08E0;
    int unk08E4;
    int unk08E8;
    int unk08EC;
    int unk08F0;
    int unk08F4;
    int unk08F8;
    int unk08FC;
    int unk0900;
    int unk0904;
    int unk0908;
    int unk090C;
    int unk0910;
    int unk0914;
    int unk0918;
    int unk091C;
    int unk0920;
    int unk0924;
    int unk0928;
    int unk092C;
    int unk0930;
    int unk0934;
    int unk0938;
    int unk093C;
    int unk0940;
    int unk0944;
    int unk0948;
    int unk094C;
    int unk0950;
    int unk0954;
    int unk0958;
    int unk095C;
    int unk0960;
    int unk0964;
    int unk0968;
    int unk096C;
    int unk0970;
    int unk0974;
    int unk0978;
    int unk097C;
    int unk0980;
    int unk0984;
    int unk0988;
    int unk098C;
    int unk0990;
    int unk0994;
    int unk0998;
    int unk099C;
    int unk09A0;
    int unk09A4;
    int unk09A8;
    int unk09AC;
    int unk09B0;
    int unk09B4;
    int unk09B8;
    int unk09BC;
    int unk09C0;
    int unk09C4;
    int unk09C8;
    int unk09CC;
    int unk09D0;
    int unk09D4;
    int unk09D8;
    int unk09DC;
    int unk09E0;
    int unk09E4;
    int unk09E8;
    int unk09EC;
    int unk09F0;
    int unk09F4;
    int unk09F8;
    int unk09FC;
    int unk0A00;
    int unk0A04;
    int unk0A08;
    int unk0A0C;
    int unk0A10;
    int unk0A14;
    int unk0A18;
    int unk0A1C;
    int unk0A20;
    int unk0A24;
    int unk0A28;
    int unk0A2C;
    int unk0A30;
    int unk0A34;
    int unk0A38;
    int unk0A3C;
    int unk0A40;
    int unk0A44;
    int unk0A48;
    int unk0A4C;
    int unk0A50;
    int unk0A54;
    int unk0A58;
    int unk0A5C;
    int unk0A60;
    int unk0A64;
    int unk0A68;
    int unk0A6C;
    int unk0A70;
    int unk0A74;
    int unk0A78;
    int unk0A7C;
    int unk0A80;
    int unk0A84;
    int unk0A88;
    int unk0A8C;
    int unk0A90;
    int unk0A94;
    int unk0A98;
    int unk0A9C;
    int unk0AA0;
    int unk0AA4;
    int unk0AA8;
    int unk0AAC;
    int unk0AB0;
    int unk0AB4;
    int unk0AB8;
    int unk0ABC;
    int unk0AC0;
    int unk0AC4;
    int unk0AC8;
    int unk0ACC;
    int unk0AD0;
    int unk0AD4;
    int unk0AD8;
    int unk0ADC;
    int unk0AE0;
    int unk0AE4;
    int unk0AE8;
    int unk0AEC;
    int unk0AF0;
    int unk0AF4;
    int unk0AF8;
    int unk0AFC;
    int unk0B00;
    int unk0B04;
    int unk0B08;
    int unk0B0C;
    int unk0B10;
    int unk0B14;
    int unk0B18;
    int unk0B1C;
    int unk0B20;
    int unk0B24;
    int unk0B28;
    int unk0B2C;
    int unk0B30;
    int unk0B34;
    int unk0B38;
    int unk0B3C;
    int unk0B40;
    int unk0B44;
    int unk0B48;
    int unk0B4C;
    int unk0B50;
    int unk0B54;
    int unk0B58;
    int unk0B5C;
    int unk0B60;
    int unk0B64;
    int unk0B68;
    int unk0B6C;
    int unk0B70;
    int unk0B74;
    int unk0B78;
    int unk0B7C;
    int unk0B80;
    int unk0B84;
    int unk0B88;
    int unk0B8C;
    int unk0B90;
    int unk0B94;
    int unk0B98;
    int unk0B9C;
    int unk0BA0;
    int unk0BA4;
    int unk0BA8;
    int unk0BAC;
    int unk0BB0;
    int unk0BB4;
    int unk0BB8;
    int unk0BBC;
    int unk0BC0;
    int unk0BC4;
    int unk0BC8;
    int unk0BCC;
    int unk0BD0;
    int unk0BD4;
    int unk0BD8;
    int unk0BDC;
    int unk0BE0;
    int unk0BE4;
    int unk0BE8;
    int unk0BEC;
    int unk0BF0;
    int unk0BF4;
    int unk0BF8;
    int unk0BFC;
    int unk0C00;
    int unk0C04;
    int unk0C08;
    int unk0C0C;
    int unk0C10;
    int unk0C14;
    int unk0C18;
    int unk0C1C;
    int unk0C20;
    int unk0C24;
    int unk0C28;
    int unk0C2C;
    int unk0C30;
    int unk0C34;
    int unk0C38;
    int unk0C3C;
    int unk0C40;
    int unk0C44;
    int unk0C48;
    int unk0C4C;
    int unk0C50;
    int unk0C54;
    int unk0C58;
    int unk0C5C;
    int unk0C60;
    int unk0C64;
    int unk0C68;
    int unk0C6C;
    int unk0C70;
    int unk0C74;
    int unk0C78;
    int unk0C7C;
    int unk0C80;
    int unk0C84;
    int unk0C88;
    int unk0C8C;
    int unk0C90;
    int unk0C94;
    int unk0C98;
    int unk0C9C;
    int unk0CA0;
    int unk0CA4;
    int unk0CA8;
    int unk0CAC;
    int unk0CB0;
    int unk0CB4;
    int unk0CB8;
    int unk0CBC;
    int unk0CC0;
    int unk0CC4;
    int unk0CC8;
    int unk0CCC;
    int unk0CD0;
    int unk0CD4;
    int unk0CD8;
    int unk0CDC;
    int unk0CE0;
    int unk0CE4;
    int unk0CE8;
    int unk0CEC;
    int unk0CF0;
    int unk0CF4;
    int unk0CF8;
    int unk0CFC;
    int unk0D00;
    int unk0D04;
    int unk0D08;
    int unk0D0C;
    int unk0D10;
    int unk0D14;
    int unk0D18;
    int unk0D1C;
    int unk0D20;
    int unk0D24;
    int unk0D28;
    int unk0D2C;
    int unk0D30;
    int unk0D34;
    int unk0D38;
    int unk0D3C;
    int unk0D40;
    int unk0D44;
    int unk0D48;
    int unk0D4C;
    int unk0D50;
    int unk0D54;
    int unk0D58;
    int unk0D5C;
    int unk0D60;
    int unk0D64;
    int unk0D68;
    int unk0D6C;
    int unk0D70;
    int unk0D74;
    int unk0D78;
    int unk0D7C;
    int unk0D80;
    int unk0D84;
    int unk0D88;
    int unk0D8C;
    int unk0D90;
    int unk0D94;
    int unk0D98;
    int unk0D9C;
    int unk0DA0;
    int unk0DA4;
    int unk0DA8;
    int unk0DAC;
    int unk0DB0;
    int unk0DB4;
    int unk0DB8;
    int unk0DBC;
    int unk0DC0;
    int unk0DC4;
    int unk0DC8;
    int unk0DCC;
    int unk0DD0;
    int unk0DD4;
    int unk0DD8;
    int unk0DDC;
    int unk0DE0;
    int unk0DE4;
    int unk0DE8;
    int unk0DEC;
    int unk0DF0;
    int unk0DF4;
    int unk0DF8;
    int unk0DFC;
    int unk0E00;
    int unk0E04;
    int unk0E08;
    int unk0E0C;
    int unk0E10;
    int unk0E14;
    int unk0E18;
    int unk0E1C;
    int unk0E20;
    int unk0E24;
    int unk0E28;
    int unk0E2C;
    int unk0E30;
    int unk0E34;
    int unk0E38;
    int unk0E3C;
    int unk0E40;
    int unk0E44;
    int unk0E48;
    int unk0E4C;
    int unk0E50;
    int unk0E54;
    int unk0E58;
    int unk0E5C;
    int unk0E60;
    int unk0E64;
    int unk0E68;
    int unk0E6C;
    int unk0E70;
    int unk0E74;
    int unk0E78;
    int unk0E7C;
    int unk0E80;
    int unk0E84;
    int unk0E88;
    int unk0E8C;
    int unk0E90;
    int unk0E94;
    int unk0E98;
    int unk0E9C;
    int unk0EA0;
    int unk0EA4;
    int unk0EA8;
    int unk0EAC;
    int unk0EB0;
    int unk0EB4;
    int unk0EB8;
    int unk0EBC;
    int unk0EC0;
    int unk0EC4;
    int unk0EC8;
    int unk0ECC;
    int unk0ED0;
    int unk0ED4;
    int unk0ED8;
    int unk0EDC;
    int unk0EE0;
    int unk0EE4;
    int unk0EE8;
    int unk0EEC;
    int unk0EF0;
    int unk0EF4;
    int unk0EF8;
    int unk0EFC;
    int unk0F00;
    int unk0F04;
    int unk0F08;
    int unk0F0C;
    int unk0F10;
    int unk0F14;
    int unk0F18;
    int unk0F1C;
    int unk0F20;
    int unk0F24;
    int unk0F28;
    int unk0F2C;
    int unk0F30;
    int unk0F34;
    int unk0F38;
    int unk0F3C;
    int unk0F40;
    int unk0F44;
    int unk0F48;
    int unk0F4C;
    int unk0F50;
    int unk0F54;
    int unk0F58;
    int unk0F5C;
    int unk0F60;
    int unk0F64;
    int unk0F68;
    int unk0F6C;
    int unk0F70;
    int unk0F74;
    int unk0F78;
    int unk0F7C;
    int unk0F80;
    int unk0F84;
    int unk0F88;
    int unk0F8C;
    int unk0F90;
    int unk0F94;
    int unk0F98;
    int unk0F9C;
    int unk0FA0;
    int unk0FA4;
    int unk0FA8;
    int unk0FAC;
    int unk0FB0;
    int unk0FB4;
    int unk0FB8;
    int unk0FBC;
    int unk0FC0;
    int unk0FC4;
    int unk0FC8;
    int unk0FCC;
    int unk0FD0;
    int unk0FD4;
    int unk0FD8;
    int unk0FDC;
    int unk0FE0;
    int unk0FE4;
    int unk0FE8;
    int unk0FEC;
    int unk0FF0;
    int unk0FF4;
    int unk0FF8;
    int unk0FFC;
    int unk1000;
    int unk1004;
    int unk1008;
    int unk100C;
    int unk1010;
    int unk1014;
    int unk1018;
    int unk101C;
    int unk1020;
    int unk1024;
    int unk1028;
    int unk102C;
    int unk1030;
    int unk1034;
    int unk1038;
    int unk103C;
    int unk1040;
    int unk1044;
    int unk1048;
    int unk104C;
    int unk1050;
    int unk1054;
    int unk1058;
    int unk105C;
    int unk1060;
    int unk1064;
    int unk1068;
    int unk106C;
    int unk1070;
    int unk1074;
    int unk1078;
    int unk107C;
    int unk1080;
    int unk1084;
    int unk1088;
    int unk108C;
    int unk1090;
    int unk1094;
    int unk1098;
    int unk109C;
    int unk10A0;
    int unk10A4;
    int unk10A8;
    int unk10AC;
    int unk10B0;
    int unk10B4;
    int unk10B8;
    int unk10BC;
    int unk10C0;
    int unk10C4;
    int unk10C8;
    int unk10CC;
    int unk10D0;
    int unk10D4;
    int unk10D8;
    int unk10DC;
    int unk10E0;
    int unk10E4;
    int unk10E8;
    int unk10EC;
    int unk10F0;
    int unk10F4;
    int unk10F8;
    int unk10FC;
    int unk1100;
    int unk1104;
    int unk1108;
    int unk110C;
    int unk1110;
    int unk1114;
    int unk1118;
    int unk111C;
    int unk1120;
    int unk1124;
    int unk1128;
    int unk112C;
    int unk1130;
    int unk1134;
    int unk1138;
    int unk113C;
    int unk1140;
    int unk1144;
    int unk1148;
    int unk114C;
    int unk1150;
    int unk1154;
    int unk1158;
    int unk115C;
    int unk1160;
    int unk1164;
    int unk1168;
    int unk116C;
    int unk1170;
    int unk1174;
    int unk1178;
    int unk117C;
    int unk1180;
    int unk1184;
    int unk1188;
    int unk118C;
    int unk1190;
    int unk1194;
    int unk1198;
    int unk119C;
    int unk11A0;
    int unk11A4;
    int unk11A8;
    int unk11AC;
    int unk11B0;
    int unk11B4;
    int unk11B8;
    int unk11BC;
    int unk11C0;
    int unk11C4;
    int unk11C8;
    int unk11CC;
    int unk11D0;
    int unk11D4;
    int unk11D8;
    int unk11DC;
    int unk11E0;
    int unk11E4;
    int unk11E8;
    int unk11EC;
    int unk11F0;
    int unk11F4;
    int unk11F8;
    int unk11FC;
    int unk1200;
    int unk1204;
    int unk1208;
    int unk120C;
    int unk1210;
    int unk1214;
    int unk1218;
    int unk121C;
    int unk1220;
    int unk1224;
    int unk1228;
    int unk122C;
    int unk1230;
    int unk1234;
    int unk1238;
    int unk123C;
    int unk1240;
    int unk1244;
    int unk1248;
    int unk124C;
    int unk1250;
    int unk1254;
    int unk1258;
    int unk125C;
    int unk1260;
    int unk1264;
    int unk1268;
    int unk126C;
    int unk1270;
    int unk1274;
    int unk1278;
    int unk127C;
    int unk1280;
    int unk1284;
    int unk1288;
    int unk128C;
    int unk1290;
    int unk1294;
    int unk1298;
    int unk129C;
    int unk12A0;
    int unk12A4;
    int unk12A8;
    int unk12AC;
    int unk12B0;
    int unk12B4;
    int unk12B8;
    int unk12BC;
    int unk12C0;
    int unk12C4;
    int unk12C8;
    int unk12CC;
    int unk12D0;
    int unk12D4;
    int unk12D8;
    int unk12DC;
    int unk12E0;
    int unk12E4;
    int unk12E8;
    int unk12EC;
    int unk12F0;
    int unk12F4;
    int unk12F8;
    int unk12FC;
    int unk1300;
    int unk1304;
    int unk1308;
    int unk130C;
    int unk1310;
    int unk1314;
    int unk1318;
    int unk131C;
    int unk1320;
    int unk1324;
    int unk1328;
    int unk132C;
    int unk1330;
    int unk1334;
    int unk1338;
    int unk133C;
    int unk1340;
    int unk1344;
    int unk1348;
    int unk134C;
    int unk1350;
    int unk1354;
    int unk1358;
    int unk135C;
    int unk1360;
    int unk1364;
    int unk1368;
    int unk136C;
    int unk1370;
    int unk1374;
    int unk1378;
    int unk137C;
    int unk1380;
    int unk1384;
    int unk1388;
    int unk138C;
    int unk1390;
    int unk1394;
    int unk1398;
    int unk139C;
    int unk13A0;
    int unk13A4;
    int unk13A8;
    int unk13AC;
    int unk13B0;
    int unk13B4;
    int unk13B8;
    int unk13BC;
    int unk13C0;
    int unk13C4;
    int unk13C8;
    int unk13CC;
    int unk13D0;
    int unk13D4;
    int unk13D8;
    int unk13DC;
    int unk13E0;
    int unk13E4;
    int unk13E8;
    int unk13EC;
    int unk13F0;
    int unk13F4;
    int unk13F8;
    int unk13FC;
    int unk1400;
    int unk1404;
    int unk1408;
    int unk140C;
    int unk1410;
    int unk1414;
    int unk1418;
    int unk141C;
    int unk1420;
    int unk1424;
    int unk1428;
    int unk142C;
    int unk1430;
    int unk1434;
    int unk1438;
    int unk143C;
    int unk1440;
    int unk1444;
    int unk1448;
    int unk144C;
    int unk1450;
    int unk1454;
    int unk1458;
    int unk145C;
    int unk1460;
    int unk1464;
    int unk1468;
    int unk146C;
    int unk1470;
    int unk1474;
    int unk1478;
    int unk147C;
    int unk1480;
    int unk1484;
    int unk1488;
    int unk148C;
    int unk1490;
    int unk1494;
    int unk1498;
    int unk149C;
    int unk14A0;
    int unk14A4;
    int unk14A8;
    int unk14AC;
    int unk14B0;
    int unk14B4;
    int unk14B8;
    int unk14BC;
    int unk14C0;
    int unk14C4;
    int unk14C8;
    int unk14CC;
    int unk14D0;
    int unk14D4;
    int unk14D8;
    int unk14DC;
    int unk14E0;
    int unk14E4;
    int unk14E8;
    int unk14EC;
    int unk14F0;
    int unk14F4;
    int unk14F8;
    int unk14FC;
    int unk1500;
    int unk1504;
    int unk1508;
    int unk150C;
    int unk1510;
    int unk1514;
    int unk1518;
    int unk151C;
    int unk1520;
    int unk1524;
    int unk1528;
    int unk152C;
    int unk1530;
    int unk1534;
    int unk1538;
    int unk153C;
    int unk1540;
    int unk1544;
    int unk1548;
    int unk154C;
    int unk1550;
    int unk1554;
    int unk1558;
    int unk155C;
    int unk1560;
    int unk1564;
    int unk1568;
    int unk156C;
    int unk1570;
    int unk1574;
    int unk1578;
    int unk157C;
    int unk1580;
    int unk1584;
    int unk1588;
    int unk158C;
    int unk1590;
    int unk1594;
    int unk1598;
    int unk159C;
    int unk15A0;
    int unk15A4;
    int unk15A8;
    int unk15AC;
    int unk15B0;
    int unk15B4;
    int unk15B8;
    int unk15BC;
    int unk15C0;
    int unk15C4;
    int unk15C8;
    int unk15CC;
    int unk15D0;
    int unk15D4;
    int unk15D8;
    int unk15DC;
    int unk15E0;
    int unk15E4;
    int unk15E8;
    int unk15EC;
    int unk15F0;
    int unk15F4;
    int unk15F8;
    int unk15FC;
    int unk1600;
    int unk1604;
    int unk1608;
    int unk160C;
    int unk1610;
    int unk1614;
    int unk1618;
    int unk161C;
    int unk1620;
    int unk1624;
    int unk1628;
    int unk162C;
    int unk1630;
    int unk1634;
    int unk1638;
    int unk163C;
    int unk1640;
    int unk1644;
    int unk1648;
    int unk164C;
    int unk1650;
    int unk1654;
    int unk1658;
    int unk165C;
    int unk1660;
    int unk1664;
    int unk1668;
    int unk166C;
    int unk1670;
    int unk1674;
    int unk1678;
    int unk167C;
    int unk1680;
    int unk1684;
    int unk1688;
    int unk168C;
    int unk1690;
    int unk1694;
    int unk1698;
    int unk169C;
    int unk16A0;
    int unk16A4;
    int unk16A8;
    int unk16AC;
    int unk16B0;
    int unk16B4;
    int unk16B8;
    int unk16BC;
    int unk16C0;
    int unk16C4;
    int unk16C8;
    int unk16CC;
    int unk16D0;
    int unk16D4;
    int unk16D8;
    int unk16DC;
    int unk16E0;
    int unk16E4;
    int unk16E8;
    int unk16EC;
    int unk16F0;
    int unk16F4;
    int unk16F8;
    int unk16FC;
    int unk1700;
    int unk1704;
    int unk1708;
    int unk170C;
    int unk1710;
    int unk1714;
    int unk1718;
    int unk171C;
    int unk1720;
    int unk1724;
    int unk1728;
    int unk172C;
    int unk1730;
    int unk1734;
    int unk1738;
    int unk173C;
    int unk1740;
    int unk1744;
    int unk1748;
    int unk174C;
    int unk1750;
    int unk1754;
    int unk1758;
    int unk175C;
    int unk1760;
    int unk1764;
    int unk1768;
    int unk176C;
    int unk1770;
    int unk1774;
    int unk1778;
    int unk177C;
    int unk1780;
    int unk1784;
    int unk1788;
    int unk178C;
    int unk1790;
    int unk1794;
    int unk1798;
    int unk179C;
    int unk17A0;
    int unk17A4;
    int unk17A8;
    int unk17AC;
    int unk17B0;
    int unk17B4;
    int unk17B8;
    int unk17BC;
    int unk17C0;
    int unk17C4;
    int unk17C8;
    int unk17CC;
    int unk17D0;
    int unk17D4;
    int unk17D8;
    int unk17DC;
    int unk17E0;
    int unk17E4;
    int unk17E8;
    int unk17EC;
    int unk17F0;
    int unk17F4;
    int unk17F8;
    int unk17FC;
    int unk1800;
    int unk1804;
    int unk1808;
    int unk180C;
    int unk1810;
    int unk1814;
    int unk1818;
    int unk181C;
    int unk1820;
    int unk1824;
    int unk1828;
    int unk182C;
    int unk1830;
    int unk1834;
    int unk1838;
    int unk183C;
    int unk1840;
    int unk1844;
    int unk1848;
    int unk184C;
    int unk1850;
    int unk1854;
    int unk1858;
    int unk185C;
    int unk1860;
    int unk1864;
    int unk1868;
    int unk186C;
    int unk1870;
    int unk1874;
    int unk1878;
    int unk187C;
    int unk1880;
    int unk1884;
    int unk1888;
    int unk188C;
    int unk1890;
    int unk1894;
    int unk1898;
    int unk189C;
    int unk18A0;
    int unk18A4;
    int unk18A8;
    int unk18AC;
    int unk18B0;
    int unk18B4;
    int unk18B8;
    int unk18BC;
    int unk18C0;
    int unk18C4;
    int unk18C8;
    int unk18CC;
    int unk18D0;
    int unk18D4;
    int unk18D8;
    int unk18DC;
    int unk18E0;
    int unk18E4;
    int unk18E8;
    int unk18EC;
    int unk18F0;
    int unk18F4;
    int unk18F8;
    int unk18FC;
    int unk1900;
    int unk1904;
    int unk1908;
    int unk190C;
    int unk1910;
    int unk1914;
    int unk1918;
    int unk191C;
    int unk1920;
    int unk1924;
    int unk1928;
    int unk192C;
    int unk1930;
    int unk1934;
    int unk1938;
    int unk193C;
    int unk1940;
    int unk1944;
    int unk1948;
    int unk194C;
    int unk1950;
    int unk1954;
    int unk1958;
    int unk195C;
    int unk1960;
    int unk1964;
    int unk1968;
    int unk196C;
    int unk1970;
    int unk1974;
    int unk1978;
    int unk197C;
    int unk1980;
    int unk1984;
    int unk1988;
    int unk198C;
    int unk1990;
    int unk1994;
    int unk1998;
    int unk199C;
    int unk19A0;
    int unk19A4;
    int unk19A8;
    int unk19AC;
    int unk19B0;
    int unk19B4;
    int unk19B8;
    int unk19BC;
    int unk19C0;
    int unk19C4;
    int unk19C8;
    int unk19CC;
    int unk19D0;
    int unk19D4;
    int unk19D8;
    int unk19DC;
    int unk19E0;
    int unk19E4;
    int unk19E8;
    int unk19EC;
    int unk19F0;
    int unk19F4;
    int unk19F8;
    int unk19FC;
    int unk1A00;
    int unk1A04;
    int unk1A08;
    int unk1A0C;
    int unk1A10;
    int unk1A14;
    int unk1A18;
    int unk1A1C;
    int unk1A20;
    int unk1A24;
    int unk1A28;
    int unk1A2C;
    int unk1A30;
    int unk1A34;
    int unk1A38;
    int unk1A3C;
    int unk1A40;
    int unk1A44;
    int unk1A48;
    int unk1A4C;
    int unk1A50;
    int unk1A54;
    int unk1A58;
    int unk1A5C;
    int unk1A60;
    int unk1A64;
    int unk1A68;
    int unk1A6C;
    int unk1A70;
    int unk1A74;
    int unk1A78;
    int unk1A7C;
    int unk1A80;
    int unk1A84;
    int unk1A88;
    int unk1A8C;
    int unk1A90;
    int unk1A94;
    int unk1A98;
    int unk1A9C;
    int unk1AA0;
    int unk1AA4;
    int unk1AA8;
    int unk1AAC;
    int unk1AB0;
    int unk1AB4;
    int unk1AB8;
    int unk1ABC;
    int unk1AC0;
    int unk1AC4;
    int unk1AC8;
    int unk1ACC;
    int unk1AD0;
    int unk1AD4;
    int unk1AD8;
    int unk1ADC;
    int unk1AE0;
    int unk1AE4;
    int unk1AE8;
    int unk1AEC;
    int unk1AF0;
    int unk1AF4;
    int unk1AF8;
    int unk1AFC;
    int unk1B00;
    int unk1B04;
    int unk1B08;
    int unk1B0C;
    int unk1B10;
    int unk1B14;
    int unk1B18;
    int unk1B1C;
    int unk1B20;
    int unk1B24;
    int unk1B28;
    int unk1B2C;
    int unk1B30;
    int unk1B34;
    int unk1B38;
    int unk1B3C;
    int unk1B40;
    int unk1B44;
    int unk1B48;
    int unk1B4C;
    int unk1B50;
    int unk1B54;
    int unk1B58;
    int unk1B5C;
    int unk1B60;
    int unk1B64;
    int unk1B68;
    int unk1B6C;
    int unk1B70;
    int unk1B74;
    int unk1B78;
    int unk1B7C;
    int unk1B80;
    int unk1B84;
    int unk1B88;
    int unk1B8C;
    int unk1B90;
    int unk1B94;
    int unk1B98;
    int unk1B9C;
    int unk1BA0;
    int unk1BA4;
    int unk1BA8;
    int unk1BAC;
    int unk1BB0;
    int unk1BB4;
    int unk1BB8;
    int unk1BBC;
    int unk1BC0;
    int unk1BC4;
    int unk1BC8;
    int unk1BCC;
    int unk1BD0;
    int unk1BD4;
    int unk1BD8;
    int unk1BDC;
    int unk1BE0;
    int unk1BE4;
    int unk1BE8;
    int unk1BEC;
    int unk1BF0;
    int unk1BF4;
    int unk1BF8;
    int unk1BFC;
    int unk1C00;
    int unk1C04;
    int unk1C08;
    int unk1C0C;
    int unk1C10;
    int unk1C14;
    int unk1C18;
    int unk1C1C;
    int unk1C20;
    int unk1C24;
    int unk1C28;
    int unk1C2C;
    int unk1C30;
    int unk1C34;
    int unk1C38;
    int unk1C3C;
    int unk1C40;
    int unk1C44;
    int unk1C48;
    int unk1C4C;
    int unk1C50;
    int unk1C54;
    int unk1C58;
    int unk1C5C;
    int unk1C60;
    int unk1C64;
    int unk1C68;
    int unk1C6C;
    int unk1C70;
    int unk1C74;
    int unk1C78;
    int unk1C7C;
    int unk1C80;
    int unk1C84;
    int unk1C88;
    int unk1C8C;
    int unk1C90;
    int unk1C94;
    int unk1C98;
    int unk1C9C;
    int unk1CA0;
    int unk1CA4;
    int unk1CA8;
    int unk1CAC;
    int unk1CB0;
    int unk1CB4;
    int unk1CB8;
    int unk1CBC;
    int unk1CC0;
    int unk1CC4;
    int unk1CC8;
    int unk1CCC;
    int unk1CD0;
    int unk1CD4;
    int unk1CD8;
    int unk1CDC;
    int unk1CE0;
    int unk1CE4;
    int unk1CE8;
    int unk1CEC;
    int unk1CF0;
    int unk1CF4;
    int unk1CF8;
    int unk1CFC;
    int unk1D00;
    int unk1D04;
    int unk1D08;
    int unk1D0C;
    int unk1D10;
    int unk1D14;
    int unk1D18;
    int unk1D1C;
    int unk1D20;
    int unk1D24;
    int unk1D28;
    int unk1D2C;
    int unk1D30;
    int unk1D34;
    int unk1D38;
    int unk1D3C;
    int unk1D40;
    int unk1D44;
    int unk1D48;
    int unk1D4C;
    int unk1D50;
    int unk1D54;
    int unk1D58;
    int unk1D5C;
    int unk1D60;
    int unk1D64;
    int unk1D68;
    int unk1D6C;
    int unk1D70;
    int unk1D74;
    int unk1D78;
    int unk1D7C;
    int unk1D80;
    int unk1D84;
    int unk1D88;
    int unk1D8C;
    int unk1D90;
    int unk1D94;
    int unk1D98;
    int unk1D9C;
    int unk1DA0;
    int unk1DA4;
    int unk1DA8;
    int unk1DAC;
    int unk1DB0;
    int unk1DB4;
    int unk1DB8;
    int unk1DBC;
    int unk1DC0;
    int unk1DC4;
    int unk1DC8;
    int unk1DCC;
    int unk1DD0;
    int unk1DD4;
    int unk1DD8;
    int unk1DDC;
    int unk1DE0;
    int unk1DE4;
    int unk1DE8;
    int unk1DEC;
    int unk1DF0;
    int unk1DF4;
    int unk1DF8;
    int unk1DFC;
    int unk1E00;
    int unk1E04;
    int unk1E08;
    int unk1E0C;
    int unk1E10;
    int unk1E14;
    int unk1E18;
    int unk1E1C;
    int unk1E20;
    int unk1E24;
    int unk1E28;
    int unk1E2C;
    int unk1E30;
    int unk1E34;
    int unk1E38;
    int unk1E3C;
    int unk1E40;
    int unk1E44;
    int unk1E48;
    int unk1E4C;
    int unk1E50;
    int unk1E54;
    int unk1E58;
    int unk1E5C;
    int unk1E60;
    int unk1E64;
    int unk1E68;
    int unk1E6C;
    int unk1E70;
    int unk1E74;
    int unk1E78;
    int unk1E7C;
    int unk1E80;
    int unk1E84;
    int unk1E88;
    int unk1E8C;
    int unk1E90;
    int unk1E94;
    int unk1E98;
    int unk1E9C;
    int unk1EA0;
    int unk1EA4;
    int unk1EA8;
    int unk1EAC;
    int unk1EB0;
    int unk1EB4;
    int unk1EB8;
    int unk1EBC;
    int unk1EC0;
    int unk1EC4;
    int unk1EC8;
    int unk1ECC;
    int unk1ED0;
    int unk1ED4;
    int unk1ED8;
    int unk1EDC;
    int unk1EE0;
    int unk1EE4;
    int unk1EE8;
    int unk1EEC;
    int unk1EF0;
    int unk1EF4;
    int unk1EF8;
    int unk1EFC;
    int unk1F00;
    int unk1F04;
    int unk1F08;
    int unk1F0C;
    int unk1F10;
    int unk1F14;
    int unk1F18;
    int unk1F1C;
    int unk1F20;
    int unk1F24;
    int unk1F28;
    int unk1F2C;
    int unk1F30;
    int unk1F34;
    int unk1F38;
    int unk1F3C;
    int unk1F40;
    int unk1F44;
    int unk1F48;
    int unk1F4C;
    int unk1F50;
    int unk1F54;
    int unk1F58;
    int unk1F5C;
    int unk1F60;
    int unk1F64;
    int unk1F68;
    int unk1F6C;
    int unk1F70;
    int unk1F74;
    int unk1F78;
    int unk1F7C;
    int unk1F80;
    int unk1F84;
    int unk1F88;
    int unk1F8C;
    int unk1F90;
    int unk1F94;
    int unk1F98;
    int unk1F9C;
    int unk1FA0;
    int unk1FA4;
    int unk1FA8;
    int unk1FAC;
    int unk1FB0;
    int unk1FB4;
    int unk1FB8;
    int unk1FBC;
    int unk1FC0;
    int unk1FC4;
    int unk1FC8;
    int unk1FCC;
    int unk1FD0;
    int unk1FD4;
    int unk1FD8;
    int unk1FDC;

    SubB();
    ~SubB();
};

struct SubC
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

    SubC();
};

struct FUN_006b8d90
{
    virtual ~FUN_006b8d90();
    SubA m_04;
    SubB m_14;
    SubC m_1ff4;
    int m_2048;
    int m_204c;
    int m_2050;
    unsigned char m_2054;

    FUN_006b8d90();
};

// Initializes m_2048, m_204c, m_2050 and m_2054 to zero.
// @fnv 0x006b8d90
FUN_006b8d90::FUN_006b8d90()
{
    m_2048 = 0;
    m_204c = 0;
    m_2050 = 0;
    m_2054 = 0;
}

struct FUN_006b8ec0_Node
{
    int unk00;
    float m_f04;
    int m_i08;
};

struct FUN_006b8ec0_cls
{
    int FUN_006b8fe0(int a1, float zero, FUN_006b8ec0_Node** out);
    int InsertNode(FUN_006b8ec0_Node* node);
    FUN_006b8ec0_Node* AStarSearch_NavMeshInfo_const_TESObjectREFR_AddStartNode(int a1, int* src, float f);
};

// @fnv 0x006b8ec0
// src: XBOX_PDB 0x006b8ec0
FUN_006b8ec0_Node* FUN_006b8ec0_cls::AStarSearch_NavMeshInfo_const_TESObjectREFR_AddStartNode(int a1, int* piValue, float afValue)
{
    FUN_006b8ec0_Node* node;
    switch (FUN_006b8fe0(a1, 0.0f, &node))
    {
    case 0:
        node->m_f04 = afValue;
        node->m_i08 = *piValue;
        reinterpret_cast<FUN_006b8ec0_cls*>(reinterpret_cast<char*>(this) + 0x1ff4)->InsertNode(node);
        *reinterpret_cast<FUN_006b8ec0_Node**>(reinterpret_cast<char*>(this) + 0x2050) = node;
        return node;
    case 1:
        return node;
    case 2:
        return 0;
    default:
        return 0;
    }
}

struct S_006b94a0_Node
{
    float unk00;
    float unk04;
    int unk08;
    int unk0c;
    int unk10;
    S_006b94a0_Node** unk14;
    S_006b94a0_Node* unk18;
    float __thiscall GetSum();
};
struct S_006b94a0_Table
{
    int unk00;
    S_006b94a0_Node* unk04[1];
    int __thiscall GetScaledValue(S_006b94a0_Node* node);
    void __thiscall InsertNode(S_006b94a0_Node* node);
};
// @fnv 0x006b94a0
void __thiscall S_006b94a0_Table::InsertNode(S_006b94a0_Node* node)
{
    int index4 = GetScaledValue(node);
    S_006b94a0_Node** slot3 = &unk04[index4];
    S_006b94a0_Node** pp = slot3;
    while (*pp && (*pp)->GetSum() < node->GetSum())
    {
        pp = &(*pp)->unk18;
    }
    if (*pp)
    {
        (*pp)->unk14 = &node->unk18;
    }
    node->unk18 = *pp;
    node->unk14 = pp;
    *pp = node;
}

namespace fnv_006b9590 {
struct MM_6b9590
{
    void* FUN_00aa42e0();
};
MM_6b9590* __cdecl MemoryManager_Instance();

struct Base_6b9760
{
    virtual ~Base_6b9760();
    int unk04;
    int unk08;
    int unk0c;
    Base_6b9760();
};

struct FUN_006b9590 : public Base_6b9760
{
    void* unk10;
    void BSSimpleArray_float_1024_InitialSetup(unsigned int, unsigned int);
    FUN_006b9590();
    virtual ~FUN_006b9590();
};

// Initializes unk10 from FUN_00401020()->FUN_00aa42e0() and calls FUN_006b3eb0 with 0, 0.
// @fnv 0x006b9590
FUN_006b9590::FUN_006b9590()
{
    unk10 = MemoryManager_Instance()->FUN_00aa42e0();
    BSSimpleArray_float_1024_InitialSetup(0, 0);
}
}  // namespace fnv_006b9590

extern int DAT_0106c264;
struct FUN_006b9610_shell
{
    void* vtable;
    void FUN_008454f0(int reset);
    void SetVtableAndProcessState_006b9610();
};
// @fnv 0x006b9610
// src: GUESS 0x006b9610 (confidence: low)
void FUN_006b9610_shell::SetVtableAndProcessState_006b9610()
{
    vtable = &DAT_0106c264;
    FUN_008454f0(1);
}

struct FUN_006b9710_Class
{
    float unk00;
    float unk04;

    float __thiscall GetSum();
};

// @fnv 0x006b9710
float __thiscall FUN_006b9710_Class::GetSum()
{
    return this->unk00 + this->unk04;
}

// Computes barycentric weights of a 2D position relative to triangle vertices a, b, c; returns false if the triangle is degenerate.
// @fnv 0x006b9820
bool __cdecl ComputeBarycentricCoordinates(const float* apVertexA, const float* apVertexB, const float* apVertexC,
                                           const float* position, float* weights)
{
    float inverse;
    float determinant = (apVertexB[0] - apVertexA[0]) * (apVertexC[1] - apVertexA[1]) -
                        (apVertexC[0] - apVertexA[0]) * (apVertexB[1] - apVertexA[1]);
    if (determinant == 0.0)
        return false;

    inverse = 1.0f / determinant;
    weights[0] = ((apVertexB[0] - position[0]) * (apVertexC[1] - position[1]) -
                  (apVertexC[0] - position[0]) * (apVertexB[1] - position[1])) *
                 inverse;
    weights[1] = ((apVertexC[0] - position[0]) * (apVertexA[1] - position[1]) -
                  (apVertexA[0] - position[0]) * (apVertexC[1] - position[1])) *
                 inverse;
    weights[2] = ((apVertexA[0] - position[0]) * (apVertexB[1] - position[1]) -
                  (apVertexB[0] - position[0]) * (apVertexA[1] - position[1])) *
                 inverse;
    return true;
}

struct FUN_006b9940_cls
{
    float x;
    float y;
    float z;
    float DotProduct(FUN_006b9940_cls* other);
    void SubtractIntoVector(FUN_006b9940_cls* out, FUN_006b9940_cls* in);
    void FUN_00439e90(FUN_006b9940_cls* out, FUN_006b9940_cls* in);
};

FUN_006b9940_cls* __cdecl FUN_004a3760(FUN_006b9940_cls* out, float scale, FUN_006b9940_cls* v);
void __cdecl sqrt_004019b0(float value);

// @fnv 0x006b9940
// src: COMMUNITY 0x006b9940
void __cdecl NavMeshMath_DistanceFromLine(FUN_006b9940_cls* a1, FUN_006b9940_cls* a2, FUN_006b9940_cls* a3)
{
    FUN_006b9940_cls v0c2;
    FUN_006b9940_cls v18;
    FUN_006b9940_cls v2;
    float dot4;
    float dotVal;
    float scaleTmp;
    FUN_006b9940_cls v3c4;
    FUN_006b9940_cls v48;

    a3->SubtractIntoVector(&v2, a2);
    a1->SubtractIntoVector(&v18, a2);
    dot4 = v18.DotProduct(&v2);
    dotVal = v2.DotProduct(&v2);
    scaleTmp = dot4 / dotVal;
    a2->FUN_00439e90(&v0c2, FUN_004a3760(&v48, scaleTmp, &v2));
    a1->SubtractIntoVector(&v3c4, &v0c2);
    sqrt_004019b0(v3c4.DotProduct(&v3c4));
}

namespace std {
float abs(float);
}

NiPoint2 operator*(float s, const NiPoint2& p);

// Tests whether segments a-b and c-d cross and, if so, writes the intersection point to out and returns true.
// @fnv 0x006b9e90
// src: XBOX_PDB 0x006b9e90
bool NavMeshMath_Find2DIntersection_006b9e90(const NiPoint2& aStart1, const NiPoint2& aEnd1, const NiPoint2& aStart2, const NiPoint2& aEnd2,
                  NiPoint2& aOutPoint)
{
    float sideD = (aStart1.x - aEnd2.x) * (aEnd1.y - aEnd2.y) - (aStart1.y - aEnd2.y) * (aEnd1.x - aEnd2.x);
    float sideC8 = (aStart1.x - aStart2.x) * (aEnd1.y - aStart2.y) - (aStart1.y - aStart2.y) * (aEnd1.x - aStart2.x);
    if (sideD * sideC8 < 0.0)
    {
        float areaA7 =
            (aStart2.x - aStart1.x) * (aEnd2.y - aStart1.y) - (aStart2.y - aStart1.y) * (aEnd2.x - aStart1.x);
        float areaB = areaA7 + sideC8 - sideD;
        if (std::abs(areaB) < 0.001f)
            areaB = (aStart2.x - aEnd1.x) * (aEnd2.y - aEnd1.y) - (aStart2.y - aEnd1.y) * (aEnd2.x - aEnd1.x);
        if (areaA7 * areaB < 0.0)
        {
            float t = areaA7 / (areaA7 - areaB);
            aOutPoint = aStart1 + t * (aEnd1 - aStart1);
            return true;
        }
    }
    return false;
}

struct ThreeDimensionalVector
{
    float x, y, z;
    ThreeDimensionalVector()
    {}
    ThreeDimensionalVector operator-(const ThreeDimensionalVector& other) const;
    ThreeDimensionalVector operator+(const ThreeDimensionalVector& other) const;
};
ThreeDimensionalVector __cdecl operator*(float scale, const ThreeDimensionalVector& point);
extern const double DAT_01012060;

// Tests whether segments a-b and c-d intersect using cross products and, if so, writes the intersection point to output and returns true.
// @fnv 0x006ba240
// src: XBOX_PDB 0x006ba240
bool __cdecl NavMeshMath_Find2DIntersectionStable(const ThreeDimensionalVector* apSeg1Start, const ThreeDimensionalVector* apSeg1End,
                          const ThreeDimensionalVector* apSeg2Start, const ThreeDimensionalVector* apSeg2End,
                          ThreeDimensionalVector* apResult)
{
    float first = (apSeg1Start->x - apSeg2End->x) * (apSeg1End->y - apSeg2End->y) -
                  (apSeg1Start->y - apSeg2End->y) * (apSeg1End->x - apSeg2End->x);
    float second = (apSeg1Start->x - apSeg2Start->x) * (apSeg1End->y - apSeg2Start->y) -
                   (apSeg1Start->y - apSeg2Start->y) * (apSeg1End->x - apSeg2Start->x);
    float third = (apSeg2Start->x - apSeg1Start->x) * (apSeg2End->y - apSeg1Start->y) -
                  (apSeg2Start->y - apSeg1Start->y) * (apSeg2End->x - apSeg1Start->x);
    float fourth = (apSeg2Start->x - apSeg1End->x) * (apSeg2End->y - apSeg1End->y) -
                   (apSeg2Start->y - apSeg1End->y) * (apSeg2End->x - apSeg1End->x);
    if (first * second <= DAT_01012060 && third * fourth <= DAT_01012060)
    {
        if (first == DAT_01012060)
            return false;
        if (fourth == DAT_01012060)
            return false;
        float ratio = third / (third - fourth);
        *apResult = *apSeg1Start + ratio * (*apSeg1End - *apSeg1Start);
        return true;
    }
    return false;
}

// Two-segment test: point lookups from two containers, cross products, and a
// parameter interpolation of the second segment onto the output point.
struct FUN_006ba7e0_cls
{
    void GetPoint(Point3Storage* out, unsigned int idx);
    Point3Storage* Xform(Point3Storage* out, Point3Storage* p);
};

Point3Storage* __cdecl FUN_006ba7e0_lerp(Point3Storage* out, float t, Point3Storage* p);

// @fnv 0x006ba7e0
// src: GUESS 0x006ba7e0 (confidence: low)
bool __cdecl Object_ProcessAndReturnValue_006ba7e0(unsigned int uiIndexA, FUN_006ba7e0_cls* a2, unsigned int uiIndexB, FUN_006ba7e0_cls* a4,
                          Point3Storage* out)
{
    float t_;
    float _t1;
    Point3Storage pX;
    Point3Storage pA;
    Point3Storage p3;
    float t5;
    Point3Storage tmp5;
    Point3Storage tmp4;

    a4->GetPoint(&pA, uiIndexB);
    a2->GetPoint(&pX, uiIndexA);
    _t1 = pA.x * pX.y - pA.y * pX.x;
    if (_t1 == 0.0)
    {
        return false;
    }
    reinterpret_cast<FUN_006ba7e0_cls*>(uiIndexA)->GetPoint(&p3, uiIndexB);
    t5 = p3.x * pA.y - p3.y * pA.x;
    t_ = t5 / _t1;
    if (t_ < 0.0 || t_ > 1.0)
    {
        return false;
    }
    if (out != 0)
    {
        *out = *reinterpret_cast<FUN_006ba7e0_cls*>(uiIndexA)->Xform(&tmp4, FUN_006ba7e0_lerp(&tmp5, t_, &pX));
    }
    return true;
}

NiPoint3 operator*(float s, const NiPoint3& p);

// @fnv 0x006bab00
// src: COMMUNITY 0x006bab00
bool NavMeshMath_DoCircleAndSegmentIntersect(const NiPoint3& point, float radius, const NiPoint3& start, const NiPoint3& end)
{
    NiPoint3 dir3 = end - start;
    NiPoint3 kRel = point - start;
    NiPoint3 closest;
    float proj = dir3.Dot(kRel);
    if (proj <= 0.0)
    {
        closest = start;
    }
    else
    {
        float fLenSq = dir3.Dot(dir3);
        if (fLenSq <= proj)
        {
            closest = end;
        }
        else
        {
            closest = start + (proj / fLenSq) * dir3;
        }
    }
    return (point - closest).SqrLength() < radius * radius;
}

float __cdecl FUN_005c5420();

struct Pt_6bbad0
{
    float x, y, z;
    Pt_6bbad0();
    Pt_6bbad0 operator+(const Pt_6bbad0& rhs) const;
    Pt_6bbad0 operator-(const Pt_6bbad0& rhs) const;
    Pt_6bbad0 operator*(float s) const;
};

// @fnv 0x006bbad0
// src: XBOX_PDB 0x006bbad0
Pt_6bbad0 __cdecl NavMeshMath_RandomPointOnTriangle(const Pt_6bbad0& aVertex0, const Pt_6bbad0& aVertex1, const Pt_6bbad0& aVertex2)
{
    float j;
    Pt_6bbad0 e = aVertex1 - aVertex0;
    Pt_6bbad0 h = aVertex2 - aVertex0;
    float p = FUN_005c5420();
    j = FUN_005c5420();
    while (p + j > 1.0)
    {
        p = FUN_005c5420();
        j = FUN_005c5420();
    }
    return aVertex0 + e * p + h * j;
}

class BaseList6BC
{
  public:
    ~BaseList6BC();

    int unk00;
    int unk04;
    int unk08;
};

class ListE6BC
{
  public:
    ~ListE6BC();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

class ListA6BC
{
  public:
    ~ListA6BC();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class ListD6BC
{
  public:
    ~ListD6BC();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class ListC6BC
{
  public:
    ~ListC6BC();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class ListB6BC
{
  public:
    ~ListB6BC();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class FUN_006bc330 : public BaseList6BC
{
  public:
    ~FUN_006bc330();

    ListE6BC m_kListC;
    ListA6BC m_kList20;
    ListD6BC m_kList30;
    ListC6BC m_kList40;
    ListB6BC m_kList50;
    ListA6BC m_kList60;
};

// @fnv 0x006bc330
FUN_006bc330::~FUN_006bc330()
{}

struct EdgeA
{
    int v0;
    int v1;
    bool IsValid();
};

struct EdgeArrayA
{
    unsigned int GetSize();
    EdgeA*& GetAt(unsigned int idx);
    unsigned int Add(EdgeA*& item);
};

struct Graph006bdf50
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
    EdgeArrayA edges;
    bool CanJoin(int a, int b);
    EdgeA* MakeEdge(int a, int b, int c);
    void JoinAdjacentEdges();
};

// Scans valid edge pairs that share an endpoint and, when CanJoin allows it, creates a new edge between the opposite endpoints and appends it to edges.
// @fnv 0x006bdf50
void Graph006bdf50::JoinAdjacentEdges()
{
    unsigned int i;
    EdgeA* first4;
    unsigned int j2;
    int b;
    EdgeA* second7;
    int a4;
    EdgeA* created5;

    for (i = 0; i < edges.GetSize(); i++)
    {
        first4 = edges.GetAt(i);
        if (!first4->IsValid())
            continue;
        for (j2 = i + 1; j2 < edges.GetSize(); j2++)
        {
            second7 = edges.GetAt(j2);
            if (!second7->IsValid())
                continue;
            if (first4->v0 == second7->v0)
            {
                a4 = first4->v1;
                b = second7->v1;
            }
            else if (first4->v0 == second7->v1)
            {
                a4 = first4->v1;
                b = second7->v0;
            }
            else if (first4->v1 == second7->v0)
            {
                a4 = first4->v0;
                b = second7->v1;
            }
            else if (first4->v1 == second7->v1)
            {
                a4 = first4->v0;
                b = second7->v0;
            }
            else
            {
                continue;
            }
            if (CanJoin(a4, b))
            {
                created5 = MakeEdge(a4, b, 0);
                edges.Add(created5);
            }
        }
    }
}

struct Vec120
{
    float x, y, z;
    Vec120 operator-(const Vec120&) const;
    Vec120 FUN_004b3800(const Vec120&) const;
    float FUN_004a7290();
};
struct Tri120
{
    unsigned short vertices[3];
    unsigned short adjacency[3];
    unsigned char flags[3];
    unsigned char extra;
    Tri120();
    void SetValues(unsigned short, unsigned short, unsigned short);
    void SetPackedField(int, unsigned short, unsigned char, unsigned char);
    void SetSlotValue(int, unsigned short);
};
struct Vertex120
{
    unsigned short index;
};
struct Edge120
{
    Vertex120* a;
    Vertex120* b;
    unsigned short triangle, unk0a;
    unsigned unk0c, type;
    unsigned short unk14, property;
    unsigned char flag1, flag2;
    unsigned short unk1a;
    unsigned unk1c, unk20, unk24, unk28;
    unsigned short extra;
    bool NavMeshObstacleEdge_CanBeUsed();
    void NavMeshObstacleEdge_AddTriangle(unsigned short, unsigned short);
};
struct Mesh120
{
    const Vec120& GetVertex_0068f0a0(unsigned short);
    unsigned short NavMesh_AddTriangle(Tri120*);
};
struct Array120
{
    unsigned FUN_0044ddc0();
    Edge120** FUN_00877a30(unsigned);
};
struct Host120
{
    Mesh120* mesh;
    unsigned unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    Array120 edges;
    bool NavMeshObstacleCutter_CheckTriangleAgainstObstacle(Vertex120*, Vertex120*, Vertex120*);
    bool NavMeshObstacleCutter_CheckTriangleAgainstOverlapped(Vertex120*, Vertex120*, Vertex120*);
    bool BuildTrianglesFromEdgePairs();
};
// Scans pairs of edges sharing a vertex, builds a triangle from a third edge joining their outer vertices, adds it to the mesh and updates the edges.
// @fnv 0x006be120
bool Host120::BuildTrianglesFromEdgePairs()
{
    bool changed = false;
    for (unsigned i = 0; i < edges.FUN_0044ddc0(); i++)
    {
        Edge120* first = *edges.FUN_00877a30(i);
        if (!first->NavMeshObstacleEdge_CanBeUsed())
            continue;
        Vertex120* shared;
        Vertex120* outer1;
        Vertex120* outer2;
        for (unsigned j = i + 1; j < edges.FUN_0044ddc0(); j++)
        {
            Edge120* second = *edges.FUN_00877a30(j);
            if (!second->NavMeshObstacleEdge_CanBeUsed())
                continue;
            if (first->triangle != 0xffff && first->triangle == second->triangle)
                continue;
            if (first->a == second->a)
            {
                shared = first->a;
                outer1 = first->b;
                outer2 = second->b;
            }
            else if (first->a == second->b)
            {
                shared = first->a;
                outer1 = first->b;
                outer2 = second->a;
            }
            else if (first->b == second->a)
            {
                shared = first->b;
                outer1 = first->a;
                outer2 = second->b;
            }
            else if (first->b == second->b)
            {
                shared = first->b;
                outer1 = first->a;
                outer2 = second->a;
            }
            else
                continue;
            bool done = false;
            for (unsigned k = j + 1; k < edges.FUN_0044ddc0(); k++)
            {
                Edge120* third = *edges.FUN_00877a30(k);
                if (!third->NavMeshObstacleEdge_CanBeUsed())
                    continue;
                if ((third->a == outer1 && third->b == outer2) || (third->a == outer2 && third->b == outer1))
                {
                    if (!NavMeshObstacleCutter_CheckTriangleAgainstObstacle(shared, outer1, outer2))
                        continue;
                    if (!NavMeshObstacleCutter_CheckTriangleAgainstOverlapped(shared, outer1, outer2))
                        continue;
                    unsigned short p;
                    Vec120 e = mesh->GetVertex_0068f0a0(outer1->index) - mesh->GetVertex_0068f0a0(shared->index);
                    Vec120 c = mesh->GetVertex_0068f0a0(outer2->index) - mesh->GetVertex_0068f0a0(shared->index);
                    Vec120 l = e.FUN_004b3800(c);
                    if (l.FUN_004a7290() < 0.1f)
                        break;
                    {
                        Tri120 triangle;
                        if (l.z < 0.0f)
                        {
                            triangle.SetValues(shared->index, outer2->index, outer1->index);
                            triangle.SetPackedField(0, second->property, second->flag1, second->flag2);
                            triangle.SetPackedField(1, third->property, third->flag1, third->flag2);
                            if (first->type == 4)
                                triangle.SetSlotValue(2, first->extra);
                            if (second->type == 4)
                                triangle.SetSlotValue(0, second->extra);
                            if (third->type == 4)
                                triangle.SetSlotValue(1, third->extra);
                        }
                        else
                        {
                            triangle.SetValues(shared->index, outer1->index, outer2->index);
                            triangle.SetPackedField(0, first->property, first->flag1, first->flag2);
                            triangle.SetPackedField(1, third->property, third->flag1, third->flag2);
                            if (first->type == 4)
                                triangle.SetSlotValue(0, first->extra);
                            if (second->type == 4)
                                triangle.SetSlotValue(2, second->extra);
                            if (third->type == 4)
                                triangle.SetSlotValue(1, third->extra);
                        }
                        p = mesh->NavMesh_AddTriangle(&triangle);
                        changed = true;
                        if (l.z < 0.0f)
                        {
                            first->NavMeshObstacleEdge_AddTriangle(p, 2);
                            second->NavMeshObstacleEdge_AddTriangle(p, 0);
                            third->NavMeshObstacleEdge_AddTriangle(p, 1);
                        }
                        else
                        {
                            first->NavMeshObstacleEdge_AddTriangle(p, 0);
                            second->NavMeshObstacleEdge_AddTriangle(p, 2);
                            third->NavMeshObstacleEdge_AddTriangle(p, 1);
                        }
                        if (!first->NavMeshObstacleEdge_CanBeUsed())
                            done = true;
                    }
                    break;
                }
            }
            if (done)
                break;
        }
    }
    return changed;
}


// LocalPathNode: 0x006bec40 reads a ushort node index at +0 of each node; include/PathNode.h has its NavMesh* there.
struct LocalPathNode
{
    unsigned short usIndex;
};

struct PathNodeList
{
    const PathPoint_blk_006a0000_od& GetNodePos(unsigned short usIndex);
};


struct ObstacleDataPtr
{
    void* m_pObject;
};

bool __cdecl NavMeshMath_IsPointInsideTriangle(const PathPoint_blk_006a0000_od& kA, const PathPoint_blk_006a0000_od& kB, const PathPoint_blk_006a0000_od& kC, const PathPoint_blk_006a0000_od& kPoint, float& fDist,
                          float fRadius, float fAngleDifference);
bool __cdecl NavMeshObstacleManager_IsPointInBox(const PathPoint_blk_006a0000_od& kPoint, const ObstacleDataPtr& kObstacle, float fRadius, float fAngleDifference);

struct PathTriangleCheck
{
    PathNodeList* pNodes;
    ObstacleDataPtr kObstacle;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    PathNodeArray kNodeArray;

    bool NavMeshObstacleCutter_CheckTriangleAgainstObstacle(LocalPathNode* pA, LocalPathNode* pB, LocalPathNode* pC);
};

// @fnv 0x006bec40
// src: COMMUNITY 0x006bec40
bool PathTriangleCheck::NavMeshObstacleCutter_CheckTriangleAgainstObstacle(LocalPathNode* pNodeA, LocalPathNode* pNodeB, LocalPathNode* pNodeC)
{
    PathPoint_blk_006a0000_od kA = pNodes->GetNodePos(pNodeA->usIndex);
    PathPoint_blk_006a0000_od kB9 = pNodes->GetNodePos(pNodeB->usIndex);
    PathPoint_blk_006a0000_od kC2 = pNodes->GetNodePos(pNodeC->usIndex);
    PathPoint_blk_006a0000_od kCenter4 = (kA + kB9 + kC2) * 0.33333f;
    float fDist;

    for (unsigned int i4 = 0; i4 < kNodeArray.GetSize(); i4++)
    {
        LocalPathNode* pNode4 = reinterpret_cast<LocalPathNode*>(kNodeArray.GetAt(i4));
        PathPoint_blk_006a0000_od kPoint7 = pNodes->GetNodePos(pNode4->usIndex);
        if (pNode4 == pNodeA || pNode4 == pNodeB || pNode4 == pNodeC)
            continue;
        if (NavMeshMath_IsPointInsideTriangle(kA, kB9, kC2, kPoint7, fDist, 128.0f, 180.0f))
            return false;
    }

    if (NavMeshObstacleManager_IsPointInBox(kCenter4, kObstacle, 128.0f, 180.0f))
        return false;
    return true;
}

namespace fnv_006bf3c0 {
inline void* operator new(unsigned int, void* p)
{
    return p;
}
inline void operator delete(void*, void*)
{}

class FUN_006bf3c0_cls
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    ScrapHeapBuffer m_0c;
    bool NavMeshObstacleCutter_IsVertInOverlappedArea(P_006bf1d0* p);
    void* NavMeshObstacleCutter_CreateVertex(unsigned short a, unsigned char b, unsigned char c, unsigned char d);
};

// Allocates an 8-byte FUN_006bf480_Class with the four arguments, sets its m_5 from FUN_006bf1d0, and returns it.
// @fnv 0x006bf3c0
// src: COMMUNITY 0x006bf3c0
void* FUN_006bf3c0_cls::NavMeshObstacleCutter_CreateVertex(unsigned short a, unsigned char b, unsigned char c, unsigned char d)
{
    void* raw = m_0c.Allocate(8, DAT_010a2720);
    new (raw) FUN_006bf480_Class(a, b, c, d);
    ((FUN_006bf480_Class*)raw)->m_5 = NavMeshObstacleCutter_IsVertInOverlappedArea((P_006bf1d0*)raw);
    return raw;
}
}  // namespace fnv_006bf3c0

struct FUN_006bf4d0_heap
{
    void* ScrapHeap_Allocate(unsigned int size, unsigned int tag);
};

struct FUN_006bf4d0_obj
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
    FUN_006bf4d0_obj(void* a1, void* a2, int a3);
};

struct FUN_006bf4d0_cls
{
    int unk00;
    int unk04;
    int unk08;
    FUN_006bf4d0_heap m_0c;
    void* CreateObject(void* a1, void* a2, int a3);
};

void operator delete(void*, void*);

// Allocates 0x30 bytes from m_0c and placement-constructs a FUN_006bf4d0_obj with a1, a2, a3, returning the new object.
// @fnv 0x006bf4d0
void* FUN_006bf4d0_cls::CreateObject(void* apArg1, void* apArg2, int aiArg3)
{
    void* pNew = m_0c.ScrapHeap_Allocate(0x30, DAT_010a2720);
    new (pNew) FUN_006bf4d0_obj(apArg1, apArg2, aiArg3);
    return pNew;
}

namespace fnv_006bf7d0 {
struct FnvWorkerBase
{
    virtual ~FnvWorkerBase()
    {}
    virtual void vt00()
    {}
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0C;
    FnvWorkerBase();
};

struct FnvSingletonHolder
{
    void* FUN_00aa42e0();
};

void* MemoryManager_Instance();

struct FUN_006bf7d0 : FnvWorkerBase
{
    void* m_pSharedOwner;
    virtual ~FUN_006bf7d0();
    FUN_006bf7d0(unsigned int a1, unsigned int a2, void* a3);
    void BSSimpleArray_float_1024_InitialSetup(unsigned int, unsigned int);
};

// Stores a3, or a value obtained from FUN_00401020()->FUN_00aa42e0() when a3 is null, then calls FUN_006b3eb0 with a1 and a2.
// @fnv 0x006bf7d0
FUN_006bf7d0::FUN_006bf7d0(unsigned int a1, unsigned int a2, void* a3) : FnvWorkerBase()
{
    m_pSharedOwner = a3 != 0 ? a3 : ((FnvSingletonHolder*)MemoryManager_Instance())->FUN_00aa42e0();
    BSSimpleArray_float_1024_InitialSetup(a1, a2);
}
}  // namespace fnv_006bf7d0

struct AuxHandler
{
    void* GetHandle();
};

AuxHandler* GetAuxHandler();

class FUN_006bfa10_base
{
  public:
    virtual void unk00();
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    FUN_006bfa10_base();
    ~FUN_006bfa10_base();
};

class FUN_006bfa10 : public FUN_006bfa10_base
{
  public:
    virtual void unk00();
    void* m_pAux;
    FUN_006bfa10(unsigned int a1, unsigned int a2, void* a3);
    void Init(unsigned int a, unsigned int b);
};

// Stores a3 or the handle from GetAuxHandler() into m_pAux, then calls Init with a1 and a2.
// @fnv 0x006bfa10
FUN_006bfa10::FUN_006bfa10(unsigned int a1, unsigned int a2, void* apAux)
{
    m_pAux = apAux != 0 ? apAux : GetAuxHandler()->GetHandle();
    Init(a1, a2);
}

struct FUN_006bfd40_cls
{
    virtual void v0();
    virtual unsigned int v1(unsigned int n);
    bool Probe();
    unsigned int Alloc();
    void Init(unsigned int a, unsigned int b);
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int BSSimpleArray_CombatSearchLocation_1024_AddUninitialized();
};

// @fnv 0x006bfd40
// src: COMMUNITY 0x006bfd40
unsigned int FUN_006bfd40_cls::BSSimpleArray_CombatSearchLocation_1024_AddUninitialized()
{
    if (Probe())
    {
        if (m_0c == 0)
        {
            unsigned int n = 4;
            m_04 = v1(n);
            m_0c = n;
        }
        else
        {
            unsigned int p = Alloc();
            Init(p, m_08);
            m_0c = p;
        }
    }
    m_08 = m_08 + 1;
    return m_08 - 1;
}

struct FUN_006bff60_Class
{
    virtual void vf00()
    {}
    virtual void* vf04(int value)
    {
        return 0;
    }
    virtual void vf08()
    {}
    virtual void* vf0c(void* current, int value)
    {
        return current;
    }

    void* unk04;
    int unk08;
    int unk0c;

    void __thiscall ProcessEntries_006c0010(void* newItem, void* oldItem, int count);
    void __thiscall FUN_006a8500();
    void __thiscall UpdateFields_006bff60(int value, int count);
};

// @fnv 0x006bff60
// src: GUESS 0x006bff60 (confidence: low)
void __thiscall FUN_006bff60_Class::UpdateFields_006bff60(int value, int count)
{
    if (this->unk04 != 0)
    {
        if (count == this->unk0c)
        {
            this->unk04 = this->vf0c(this->unk04, value);
        }
        else
        {
            void* newItem = this->vf04(value);
            this->ProcessEntries_006c0010(newItem, this->unk04, count);
            this->FUN_006a8500();
            this->unk04 = newItem;
        }
    }
    else
    {
        this->unk04 = this->vf04(value);
        this->unk0c = value;
    }
}

struct FUN_006a1720_Element
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
};

struct FUN_006a1720_class
{
    virtual void FUN_006a1720_vf0();
    virtual FUN_006a1720_Element* Allocate(unsigned int count);

    FUN_006a1720_Element* m_data;
    unsigned int m_iElementCount;
    unsigned int m_pRayCursor;

    void FUN_0049faf0(bool free_memory);
    void BSSimpleArray_TeleportLink_1024_ReallocateBuffer(unsigned int requested, unsigned int old_size);
    void CallVirtualOnEach(FUN_006a1720_Element* first, unsigned int count);
    void ConstructArray(FUN_006a1720_Element* first, unsigned int count);
    void ResizeElementStorage(unsigned int requested, bool shrink);
};

// @fnv 0x006a1720
// src: GUESS 0x006a1720 (confidence: medium)
void FUN_006a1720_class::ResizeElementStorage(unsigned int requested, bool shrink)
{
    if (requested == 0)
    {
        FUN_0049faf0(shrink);
    }
    else if (requested > m_pRayCursor)
    {
        if (m_pRayCursor == 0)
        {
            m_data = Allocate(requested);
            m_pRayCursor = requested;
        }
        else
        {
            BSSimpleArray_TeleportLink_1024_ReallocateBuffer(requested, m_iElementCount);
            m_pRayCursor = requested;
        }
        ConstructArray(m_data + m_iElementCount, requested - m_iElementCount);
        m_iElementCount = requested;
    }
    else if (requested < m_iElementCount)
    {
        CallVirtualOnEach(m_data + requested, m_iElementCount - requested);
        m_iElementCount = requested;
        if (shrink && requested <= (m_pRayCursor >> 2))
        {
            BSSimpleArray_TeleportLink_1024_ReallocateBuffer(requested, requested);
            m_pRayCursor = requested;
        }
    }
    else
    {
        ConstructArray(m_data + m_iElementCount, requested - m_iElementCount);
        m_iElementCount = requested;
    }
}

void* __cdecl operator new(unsigned int size, void* placement);
struct FUN_006a14b0
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FUN_006a14b0();
};
struct Proc006a20
{
    void ConstructArray(int base, int count);
};
// Placement-constructs count FUN_006a14b0 objects at 16-byte intervals starting from base.
// @fnv 0x006a2000
void Proc006a20::ConstructArray(int base, int count)
{
    for (unsigned int index = 0; index < (unsigned int)count; ++index)
    {
        new (reinterpret_cast<char*>(base) + index * 16) FUN_006a14b0;
    }
}

struct Property260
{
    void NiMaterialProperty_SetAlpha(float);
};
struct Pointer260
{
    Property260* value;
    Property260* Modelloader_GetReferencedThis();
};
struct Global260
{
    void* Modelloader_GetReferencedThis();
};
extern Global260 DAT_011d6e5c;
void __cdecl BSShaderProperty_SetFlagRecurse(void*, int, bool);
extern float DAT_0106b4ec;
extern float DAT_0106b4f0;
extern float DAT_0106b4f8;
extern float DAT_0106b4fc;
extern float DAT_0106b500;
extern float DAT_0106b504;
extern float DAT_0106b508;
struct Host260
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
    Pointer260 m_50;
    int m_54;
    Pointer260 m_58;
    int m_5c;
    int m_60;
    int m_64;
    Pointer260 m_68;
    Pointer260 m_6c;
    int m_70;
    Pointer260 m_74;
    Pointer260 m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    Pointer260 m_94;
    int m_98;
    int m_9c;
    int m_a0;
    Pointer260 m_a4;
    Pointer260 m_a8;
    int m_ac;
    Pointer260 m_b0;
    Pointer260 m_b4;
    void NavMeshRender_SetTransparentOverLayMode(bool enabled);
};
// Sets a value on each of several sub-objects depending on enabled, then calls FUN_00ba91a0 with 31 and the inverse of enabled.
// @fnv 0x006a5ee0
// src: COMMUNITY 0x006a5ee0
void Host260::NavMeshRender_SetTransparentOverLayMode(bool enabled)
{
    if (enabled)
    {
        m_94.Modelloader_GetReferencedThis()->NiMaterialProperty_SetAlpha(DAT_0106b4ec);
        m_b0.Modelloader_GetReferencedThis()->NiMaterialProperty_SetAlpha(DAT_0106b4ec);
        m_b4.Modelloader_GetReferencedThis()->NiMaterialProperty_SetAlpha(DAT_0106b4ec);
        m_a4.Modelloader_GetReferencedThis()->NiMaterialProperty_SetAlpha(DAT_0106b4f0);
        m_a8.Modelloader_GetReferencedThis()->NiMaterialProperty_SetAlpha(DAT_0106b4f0);
        m_50.Modelloader_GetReferencedThis()->NiMaterialProperty_SetAlpha(DAT_0106b4f8);
        m_68.Modelloader_GetReferencedThis()->NiMaterialProperty_SetAlpha(DAT_0106b4f8);
        m_58.Modelloader_GetReferencedThis()->NiMaterialProperty_SetAlpha(DAT_0106b4f8);
        m_6c.Modelloader_GetReferencedThis()->NiMaterialProperty_SetAlpha(DAT_0106b4f8);
        m_74.Modelloader_GetReferencedThis()->NiMaterialProperty_SetAlpha(DAT_0106b4f8);
        m_78.Modelloader_GetReferencedThis()->NiMaterialProperty_SetAlpha(DAT_0106b504);
    }
    else
    {
        m_94.Modelloader_GetReferencedThis()->NiMaterialProperty_SetAlpha(DAT_0106b4f0);
        m_b0.Modelloader_GetReferencedThis()->NiMaterialProperty_SetAlpha(DAT_0106b4f0);
        m_b4.Modelloader_GetReferencedThis()->NiMaterialProperty_SetAlpha(DAT_0106b4f0);
        m_a4.Modelloader_GetReferencedThis()->NiMaterialProperty_SetAlpha(DAT_0106b500);
        m_a8.Modelloader_GetReferencedThis()->NiMaterialProperty_SetAlpha(DAT_0106b500);
        m_50.Modelloader_GetReferencedThis()->NiMaterialProperty_SetAlpha(DAT_0106b4fc);
        m_68.Modelloader_GetReferencedThis()->NiMaterialProperty_SetAlpha(DAT_0106b4fc);
        m_58.Modelloader_GetReferencedThis()->NiMaterialProperty_SetAlpha(DAT_0106b4fc);
        m_6c.Modelloader_GetReferencedThis()->NiMaterialProperty_SetAlpha(DAT_0106b4fc);
        m_74.Modelloader_GetReferencedThis()->NiMaterialProperty_SetAlpha(DAT_0106b4fc);
        m_78.Modelloader_GetReferencedThis()->NiMaterialProperty_SetAlpha(DAT_0106b508);
    }
    BSShaderProperty_SetFlagRecurse(DAT_011d6e5c.Modelloader_GetReferencedThis(), 31, !enabled);
}

struct WorkerElement
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};
struct WorkerArray
{
    virtual void v0();
    virtual WorkerElement* Allocate(unsigned int);
    WorkerElement* data;
    unsigned int size;
    unsigned int capacity;
    void FUN_008454f0(bool);
    void UpdateThreat(unsigned int, unsigned int);
    void BSSimpleArray_WeaponData_1024_ConstructItems(WorkerElement*, unsigned int);
    void FUN_0072ba80(WorkerElement*, unsigned int);
    void AllocateStorage_006a8750(unsigned int, bool);
};
// @fnv 0x006a8750
// src: GUESS 0x006a8750 (confidence: low)
void WorkerArray::AllocateStorage_006a8750(unsigned int requested, bool shrink)
{
    if (requested == 0)
    {
        FUN_008454f0(shrink);
    }
    else if (requested > capacity)
    {
        if (capacity == 0)
        {
            data = Allocate(requested);
            capacity = requested;
        }
        else
        {
            UpdateThreat(requested, size);
            capacity = requested;
        }
        BSSimpleArray_WeaponData_1024_ConstructItems(data + size, requested - size);
        size = requested;
    }
    else if (requested < size)
    {
        FUN_0072ba80(data + requested, size - requested);
        size = requested;
        if (shrink && requested <= (capacity >> 2))
        {
            UpdateThreat(requested, requested);
            capacity = requested;
        }
    }
    else
    {
        BSSimpleArray_WeaponData_1024_ConstructItems(data + size, requested - size);
        size = requested;
    }
}

struct H2
{
    virtual void v0();
    virtual void* v1(unsigned int count);
    void* m_data;
    unsigned int m_iElementCount;
    unsigned int m_pRayCursor;
    void UpdateState_006a8890(unsigned int newSize, unsigned char doShrink);
    void FUN_008454f0(unsigned char doShrink);
    void FUN_006dc590(unsigned int newCapacity, unsigned int currentSize);
    void ConstructParentSpaceNodes(void* first, unsigned int count);
    void FUN_0072ba80(void* first, unsigned int count);
};

// @fnv 0x006a8890
// src: GUESS 0x006a8890 (confidence: low)
void H2::UpdateState_006a8890(unsigned int newSize, unsigned char doShrink)
{
    if (newSize == 0)
    {
        FUN_008454f0(doShrink);
    }
    else if (newSize > m_pRayCursor)
    {
        if (m_pRayCursor == 0)
        {
            m_data = v1(newSize);
            m_pRayCursor = newSize;
        }
        else
        {
            FUN_006dc590(newSize, m_iElementCount);
            m_pRayCursor = newSize;
        }
        ConstructParentSpaceNodes((char*)m_data + m_iElementCount * 12, newSize - m_iElementCount);
        m_iElementCount = newSize;
    }
    else if (newSize < m_iElementCount)
    {
        FUN_0072ba80((char*)m_data + newSize * 12, m_iElementCount - newSize);
        m_iElementCount = newSize;
        if (doShrink && newSize <= (m_pRayCursor >> 2))
        {
            FUN_006dc590(newSize, newSize);
            m_pRayCursor = newSize;
        }
    }
    else
    {
        ConstructParentSpaceNodes((char*)m_data + m_iElementCount * 12, newSize - m_iElementCount);
        m_iElementCount = newSize;
    }
}

struct SearchConnectionBuffer
{
    void* vtable;
    PathSearchNode** buffer;
    unsigned int size;
    unsigned int capacity;
    void* heap;
    SearchConnectionBuffer();
    ~SearchConnectionBuffer();
    void FUN_008454f0(bool freeMemory);
    unsigned int FUN_0044ddc0();
    PathSearchNode** FUN_00877a30(unsigned int index);
};
struct PathSearch : FUN_006a1cf0_shell
{
    PathSearchNode* AStarSearch_PathSmootherPOVNode_PathSmootherPOVLink_BuildNodePath();
};
// @fnv 0x006b3a30
// src: COMMUNITY 0x006b3a30
PathSearchNode* PathSearch::AStarSearch_PathSmootherPOVNode_PathSmootherPOVLink_BuildNodePath()
{
    SearchConnectionBuffer connections;
    PathSearchNode* previous = pCurrentNode;
    pCurrentNode = kOpenList.PopOpenNode();
    if (!pCurrentNode)
        return 0;
    pBestNode = pCurrentNode;
    unsigned int iterations = 0;
    while (pCurrentNode)
    {
        if (HasReachedGoal(pCurrentNode))
        {
            pBestNode = pCurrentNode;
            return pCurrentNode;
        }
        connections.FUN_008454f0(false);
        GetConnections(pCurrentNode, reinterpret_cast<ConnectionArray*>(&connections));
        for (unsigned int i = 0; i < connections.FUN_0044ddc0(); ++i)
        {
            PathSearchNode* neighbor = *connections.FUN_00877a30(i);
            kOpenList.UnlinkFromList(neighbor);
            if (pCurrentNode->pParent == neighbor)
                return 0;
            neighbor->pParent = pCurrentNode;
            kOpenList.InsertSorted(neighbor);
            if (reinterpret_cast<Modifier*>(neighbor)->GetValue() < reinterpret_cast<Modifier*>(pBestNode)->GetValue())
                pBestNode = neighbor;
        }
        if (bYield)
        {
            ++iterations;
            if (iterations == 50)
            {
                iterations = 0;
                BSSleep(0);
            }
        }
        previous = pCurrentNode;
        pCurrentNode = kOpenList.PopOpenNode();
    }
    pCurrentNode = previous;
    return 0;
}

struct ResizeElement64
{
    float matrix[16];
};
struct Array64
{
    virtual void unused();
    virtual ResizeElement64* Allocate(unsigned int);
    ResizeElement64* data;
    unsigned int size;
    unsigned int capacity;
    void FUN_008454f0(bool);
    void AllocateStorage_006b4590(unsigned int, unsigned int);
    void ConstructElementsInPlace(ResizeElement64*, unsigned int);
    void FUN_0072ba80(ResizeElement64*, unsigned int);
    void AllocateStorage_006b4450(unsigned int, bool);
};
// @fnv 0x006b4450
// src: GUESS 0x006b4450 (confidence: low)
void Array64::AllocateStorage_006b4450(unsigned int count, bool shrink)
{
    if (count == 0)
    {
        FUN_008454f0(shrink);
    }
    else if (count > capacity)
    {
        if (capacity == 0)
        {
            data = Allocate(count);
            capacity = count;
        }
        else
        {
            AllocateStorage_006b4590(count, size);
            capacity = count;
        }
        ConstructElementsInPlace(data + size, count - size);
        size = count;
    }
    else if (count < size)
    {
        FUN_0072ba80(data + count, size - count);
        size = count;
        if (shrink && count <= capacity / 4)
        {
            AllocateStorage_006b4590(count, count);
            capacity = count;
        }
    }
    else
    {
        ConstructElementsInPlace(data + size, count - size);
        size = count;
    }
}

struct SearchNode9180
{
    float cost;
    float heuristic;
    int state;
    int flags;
    SearchNode9180* parent;
    float CombatTimer_GetTargetTime();
};
struct ConnectionArray9180
{
    virtual ~ConnectionArray9180();
    SearchNode9180** data;
    unsigned size;
    unsigned capacity;
    unsigned grow;
    ConnectionArray9180();
    void FUN_008454f0(bool);
    unsigned FUN_0044ddc0();
    SearchNode9180*& FUN_00877a30(unsigned);
};
struct OpenNodes9180
{
    SearchNode9180* PopNode();
    void UnlinkFromNeighbors(SearchNode9180*);
    void InsertNode(SearchNode9180*);
};
struct Search9180 : FUN_006b8d90
{
    virtual void GetConnections(SearchNode9180*, ConnectionArray9180*);
    virtual bool IsGoal(SearchNode9180*);
    SearchNode9180* FindPathStep();
};
// @fnv 0x006b9180
SearchNode9180* Search9180::FindPathStep()
{
    ConnectionArray9180 connections;
    SearchNode9180* previous = (SearchNode9180*)m_204c;
    m_204c = (int)((OpenNodes9180*)&m_1ff4)->PopNode();
    if (!m_204c)
        return 0;
    m_2048 = m_204c;
    unsigned j = 0;
    while (m_204c)
    {
        if (IsGoal((SearchNode9180*)m_204c))
        {
            m_2048 = m_204c;
            return (SearchNode9180*)m_204c;
        }
        connections.FUN_008454f0(false);
        GetConnections((SearchNode9180*)m_204c, &connections);
        for (unsigned i = 0; i < connections.FUN_0044ddc0(); ++i)
        {
            SearchNode9180* node = connections.FUN_00877a30(i);
            ((OpenNodes9180*)&m_1ff4)->UnlinkFromNeighbors(node);
            if (((SearchNode9180*)m_204c)->parent == node)
                return 0;
            node->parent = (SearchNode9180*)m_204c;
            ((OpenNodes9180*)&m_1ff4)->InsertNode(node);
            if (node->CombatTimer_GetTargetTime() < ((SearchNode9180*)m_2048)->CombatTimer_GetTargetTime())
                m_2048 = (int)node;
        }
        if (m_2054)
        {
            ++j;
            if (j == 50)
            {
                j = 0;
                BSSleep(0);
            }
        }
        previous = (SearchNode9180*)m_204c;
        m_204c = (int)((OpenNodes9180*)&m_1ff4)->PopNode();
    }
    m_204c = (int)previous;
    return 0;
}

namespace fnv_006ba100 {
struct Vec3Ops
{
    float x;
    float y;
    float z;
    Vec3Ops* __thiscall Sub(Vec3Ops* result, const Vec3Ops& rhs) const;
    Vec3Ops* __thiscall Add(Vec3Ops* result, const Vec3Ops& rhs) const;
};
Vec3Ops* __cdecl FUN_004a3760(Vec3Ops* result, float amount, const Vec3Ops& value);
extern double DAT_01012060;

// @fnv 0x006ba100
// src: COMMUNITY 0x006ba100
bool __cdecl NavMeshMath_Find2DIntersection_2(const Point3Storage* apSeg1Start, const Point3Storage* apSeg1End, const Point3Storage* apSeg2Start,
                          const Point3Storage* apSeg2End, Point3Storage* apIntersection)
{
    float fStack_8 = (apSeg1Start->x - apSeg2End->x) * (apSeg1End->y - apSeg2End->y) -
                     (apSeg1Start->y - apSeg2End->y) * (apSeg1End->x - apSeg2End->x);
    float fStack_c = (apSeg1Start->x - apSeg2Start->x) * (apSeg1End->y - apSeg2Start->y) -
                     (apSeg1Start->y - apSeg2Start->y) * (apSeg1End->x - apSeg2Start->x);
    if (fStack_8 * fStack_c <= DAT_01012060)
    {
        float fStack_14 = (apSeg2Start->x - apSeg1Start->x) * (apSeg2End->y - apSeg1Start->y) -
                          (apSeg2Start->y - apSeg1Start->y) * (apSeg2End->x - apSeg1Start->x);
        float fStack_10 = (fStack_14 + fStack_c) - fStack_8;
        if (fStack_14 * fStack_10 < DAT_01012060)
        {
            float fStack5 = fStack_14 / (fStack_14 - fStack_10);
            Vec3Ops temp4;
            Vec3Ops temp2c4;
            Vec3Ops temp38;
            *apIntersection = *reinterpret_cast<const Point3Storage*>(
                reinterpret_cast<const Vec3Ops&>(*apSeg1Start)
                    .Add(&temp38, *reinterpret_cast<const Vec3Ops*>(FUN_004a3760(
                                      &temp2c4, fStack5,
                                      *reinterpret_cast<const Vec3Ops*>(
                                          reinterpret_cast<const Vec3Ops&>(*apSeg1End)
                                              .Sub(&temp4, reinterpret_cast<const Vec3Ops&>(*apSeg1Start)))))));
            return true;
        }
    }
    return false;
}
}  // namespace fnv_006ba100

struct TanPoint3
{
    float x;
    float y;
    float z;

    TanPoint3 operator-(const TanPoint3& arOther) const;
    float SqrLength() const;
};

float __cdecl TanSqrt(float afValue);

// @fnv 0x006ba8c0
bool __cdecl ComputeCircleTangents(const TanPoint3& arCenter, float afRadius, const TanPoint3& arPoint,
                                   TanPoint3& arTangent1, TanPoint3& arTangent2)
{
    TanPoint3 kDelta5 = arPoint - arCenter;
    float fDistSqrA = kDelta5.SqrLength();
    float fRadiusSqr = afRadius * afRadius;
    if (fDistSqrA >= fRadiusSqr)
    {
        float fInvDistSqr = 1.0f / fDistSqrA;
        float fTangentX = TanSqrt(fDistSqrA - fRadiusSqr);
        arTangent1 = arCenter;
        arTangent2 = arCenter;
        arTangent1.x += (afRadius * kDelta5.x - kDelta5.y * fTangentX) * afRadius * fInvDistSqr;
        arTangent1.y += (afRadius * kDelta5.y + kDelta5.x * fTangentX) * afRadius * fInvDistSqr;
        arTangent2.x += (afRadius * kDelta5.x + kDelta5.y * fTangentX) * afRadius * fInvDistSqr;
        arTangent2.y += (afRadius * kDelta5.y - kDelta5.x * fTangentX) * afRadius * fInvDistSqr;
        return true;
    }
    else
        return false;
}

// Computes the closest point on segment start-end to point and returns whether its squared distance to point is less than radius squared.
// @fnv 0x006ba9e0
// src: COMMUNITY 0x006ba9e0
bool NavMeshMath_SegmentCircleIntersection(const NiPoint3& start, const NiPoint3& end, const NiPoint3& point, float radius)
{
    NiPoint3 dir3 = end - start;
    NiPoint3 kRel = point - start;
    NiPoint3 closest;
    float t2 = dir3.Dot(kRel);
    if (t2 <= DAT_01012060)
    {
        closest = start;
    }
    else
    {
        float len2 = dir3.Dot(dir3);
        if (len2 <= t2)
        {
            closest = end;
        }
        else
        {
            closest = start + (t2 / len2) * dir3;
        }
    }
    return (point - closest).SqrLength() < radius * radius;
}

namespace CircleIntersection {
// Use the assignment member address to retain the original out-of-line calls.
struct Line
{
    PathPoint_blk_006a0000_od start, end;
    Line(const Line&);
    void AddToPoints(const PathPoint_blk_006a0000_od&);
    void SubtractFromC(PathPoint_blk_006a0000_od&);
};
struct Circle
{
    PathPoint_blk_006a0000_od center;
    float radius;
    PathPoint_blk_006a0000_od GetNegatedVector();
};
struct Hit
{
    int type;
    NiPoint2 point;
    float parameter;
};
struct Result
{
    int type;
    Hit first, second;
};
extern float DAT_01017d00;
extern double DAT_01012060, DAT_01012070;
float FUN_00408840(float);
float sqrt_004019b0(float);
// Computes where a line intersects a circle, filling result with hit points, parameters and a type code, and returns whether a valid intersection was found.
// @fnv 0x006bac20
bool IntersectLineCircle(Circle* circle, const Line* pLine, Result* result)
{
    float epsilonSlot18 = DAT_01017d00;
    if (circle->radius <= DAT_01012060)
        return false;
    Hit* firstSlot0 = &result->first;
    Hit* secondSlot21 = &result->second;
    Line lineSlot1(*pLine);
    lineSlot1.AddToPoints(circle->GetNegatedVector());
    float radiusSlot20 = 1.0f;
    lineSlot1.start.ScaleByInverse(circle->radius);
    lineSlot1.end.ScaleByInverse(circle->radius);
    // SubtractFromC fills this output; the original code does not construct it first.
    float directionStorage[sizeof(PathPoint_blk_006a0000_od) / sizeof(float)];
    lineSlot1.SubtractFromC(reinterpret_cast<PathPoint_blk_006a0000_od&>(directionStorage));
    float radiusSquaredSlot0 = radiusSlot20 * radiusSlot20;
    bool useXSlot0;
    if (reinterpret_cast<PathPoint_blk_006a0000_od&>(directionStorage).y == DAT_01012060 && reinterpret_cast<PathPoint_blk_006a0000_od&>(directionStorage).x != DAT_01012060)
        useXSlot0 = true;
    else if (reinterpret_cast<PathPoint_blk_006a0000_od&>(directionStorage).y != DAT_01012060 && reinterpret_cast<PathPoint_blk_006a0000_od&>(directionStorage).x == DAT_01012060)
        useXSlot0 = false;
    else if (FUN_00408840(reinterpret_cast<PathPoint_blk_006a0000_od&>(directionStorage).x) > FUN_00408840(reinterpret_cast<PathPoint_blk_006a0000_od&>(directionStorage).y))
        useXSlot0 = true;
    else
        useXSlot0 = false;
    if (useXSlot0)
    {
        float inverseXSlot0 = 1.0f / reinterpret_cast<PathPoint_blk_006a0000_od&>(directionStorage).x;
        float slopeXSlot12 = reinterpret_cast<PathPoint_blk_006a0000_od&>(directionStorage).y * inverseXSlot0;
        float interceptXSlot13 = lineSlot1.start.y - slopeXSlot12 * lineSlot1.start.x;
        float slopeSquaredXSlot1 = slopeXSlot12 * slopeXSlot12;
        float coefficientXSlot14 = slopeSquaredXSlot1 + DAT_01012070;
        float interceptSquaredXSlot10 = interceptXSlot13 * interceptXSlot13;
        float discriminantXSlot0 =
            (radiusSquaredSlot0 * coefficientXSlot14 - interceptSquaredXSlot10) * radiusSquaredSlot0;
        if (discriminantXSlot0 < -epsilonSlot18)
        {
            result->type = 0;
            return false;
        }
        else if (discriminantXSlot0 < epsilonSlot18)
        {
            result->type = 3;
            float singleInverseXSlot11 = 1.0f / (radiusSquaredSlot0 * coefficientXSlot14);
            float singleOffsetXSlot0 = interceptXSlot13 * radiusSlot20;
            NiPoint2 singleXSlot0;
            singleXSlot0.x = -singleOffsetXSlot0 * slopeXSlot12 * singleInverseXSlot11;
            singleXSlot0.y = singleOffsetXSlot0 * singleInverseXSlot11;
            (firstSlot0->point.*&NiPoint2::operator=)(singleXSlot0);
            firstSlot0->parameter = (radiusSlot20 * firstSlot0->point.x - lineSlot1.start.x) * inverseXSlot0;
        }
        else
        {
            result->type = 4;
            float pairInverseXSlot10 = 1.0f / (radiusSquaredSlot0 * coefficientXSlot14);
            float rootX = sqrt_004019b0(discriminantXSlot0);
            float pairOffsetXSlot10 = interceptXSlot13 * radiusSlot20;
            NiPoint2 positiveXSlot10;
            positiveXSlot10.x = (-pairOffsetXSlot10 * slopeXSlot12 + rootX) * pairInverseXSlot10;
            positiveXSlot10.y = (slopeXSlot12 * rootX + pairOffsetXSlot10) * pairInverseXSlot10;
            NiPoint2 negativeXSlot0;
            negativeXSlot0.x = (-pairOffsetXSlot10 * slopeXSlot12 - rootX) * pairInverseXSlot10;
            negativeXSlot0.y = (pairOffsetXSlot10 - slopeXSlot12 * rootX) * pairInverseXSlot10;
            if (reinterpret_cast<PathPoint_blk_006a0000_od&>(directionStorage).x < DAT_01012060)
            {
                (firstSlot0->point.*&NiPoint2::operator=)(positiveXSlot10);
                (secondSlot21->point.*&NiPoint2::operator=)(negativeXSlot0);
            }
            else
            {
                (firstSlot0->point.*&NiPoint2::operator=)(negativeXSlot0);
                (secondSlot21->point.*&NiPoint2::operator=)(positiveXSlot10);
            }
            firstSlot0->parameter = (radiusSlot20 * firstSlot0->point.x - lineSlot1.start.x) * inverseXSlot0;
            secondSlot21->parameter = (radiusSlot20 * secondSlot21->point.x - lineSlot1.start.x) * inverseXSlot0;
        }
    }
    else
    {
        float inverseYSlot0 = 1.0f / reinterpret_cast<PathPoint_blk_006a0000_od&>(directionStorage).y;
        float slopeYSlot0 = reinterpret_cast<PathPoint_blk_006a0000_od&>(directionStorage).x * inverseYSlot0;
        float interceptYSlot0 = lineSlot1.start.x - slopeYSlot0 * lineSlot1.start.y;
        float slopeSquaredYSlot11 = slopeYSlot0 * slopeYSlot0;
        float coefficientYSlot11 = slopeSquaredYSlot11 + DAT_01012070;
        float interceptSquaredYSlot0 = interceptYSlot0 * interceptYSlot0;
        float discriminantYSlot0 =
            (radiusSquaredSlot0 * coefficientYSlot11 - interceptSquaredYSlot0) * radiusSquaredSlot0;
        if (discriminantYSlot0 < -epsilonSlot18)
        {
            result->type = 0;
            return false;
        }
        else if (discriminantYSlot0 < epsilonSlot18)
        {
            result->type = 3;
            float singleInverseYSlot10 = 1.0f / (radiusSquaredSlot0 * coefficientYSlot11);
            float singleOffsetYSlot0 = interceptYSlot0 * radiusSlot20;
            NiPoint2 singleYSlot0;
            singleYSlot0.x = singleOffsetYSlot0 * singleInverseYSlot10;
            singleYSlot0.y = -singleOffsetYSlot0 * slopeYSlot0 * singleInverseYSlot10;
            (firstSlot0->point.*&NiPoint2::operator=)(singleYSlot0);
            firstSlot0->parameter = (radiusSlot20 * firstSlot0->point.y - lineSlot1.start.y) * inverseYSlot0;
        }
        else
        {
            result->type = 4;
            float pairInverseYSlot11 = 1.0f / (radiusSquaredSlot0 * coefficientYSlot11);
            float rootYSlot16 = sqrt_004019b0(discriminantYSlot0);
            float pairOffsetYSlot0 = interceptYSlot0 * radiusSlot20;
            NiPoint2 positiveYSlot0;
            positiveYSlot0.x = (slopeYSlot0 * rootYSlot16 + pairOffsetYSlot0) * pairInverseYSlot11;
            positiveYSlot0.y = (-pairOffsetYSlot0 * slopeYSlot0 + rootYSlot16) * pairInverseYSlot11;
            NiPoint2 negativeYSlot0;
            negativeYSlot0.x = (pairOffsetYSlot0 - slopeYSlot0 * rootYSlot16) * pairInverseYSlot11;
            negativeYSlot0.y = (-pairOffsetYSlot0 * slopeYSlot0 - rootYSlot16) * pairInverseYSlot11;
            if (reinterpret_cast<PathPoint_blk_006a0000_od&>(directionStorage).y < DAT_01012060)
            {
                (firstSlot0->point.*&NiPoint2::operator=)(positiveYSlot0);
                (secondSlot21->point.*&NiPoint2::operator=)(negativeYSlot0);
            }
            else
            {
                (firstSlot0->point.*&NiPoint2::operator=)(negativeYSlot0);
                (secondSlot21->point.*&NiPoint2::operator=)(positiveYSlot0);
            }
            firstSlot0->parameter = (radiusSlot20 * firstSlot0->point.y - lineSlot1.start.y) * inverseYSlot0;
            secondSlot21->parameter = (radiusSlot20 * secondSlot21->point.y - lineSlot1.start.y) * inverseYSlot0;
        }
    }
    if (result->type == 3)
    {
        bool valid = firstSlot0->parameter >= -epsilonSlot18 && firstSlot0->parameter <= 1.0f + epsilonSlot18;
        if (valid)
        {
            if (firstSlot0->parameter < epsilonSlot18 || firstSlot0->parameter > 1.0f - epsilonSlot18)
                result->first.type = 2;
            else
                result->first.type = 1;
            return true;
        }
        else
        {
            result->type = 0;
            return false;
        }
    }
    else
    {
        bool firstValidSlot0 = firstSlot0->parameter >= -epsilonSlot18 && firstSlot0->parameter <= 1.0f + epsilonSlot18;
        bool secondValidSlot0 =
            secondSlot21->parameter >= -epsilonSlot18 && secondSlot21->parameter <= 1.0f + epsilonSlot18;
        if (firstValidSlot0 && secondValidSlot0)
        {
            result->type = 4;
            if (firstSlot0->parameter < epsilonSlot18 || firstSlot0->parameter > 1.0f - epsilonSlot18)
                result->first.type = 2;
            else
                result->first.type = 1;
            if (secondSlot21->parameter < epsilonSlot18 || secondSlot21->parameter > 1.0f - epsilonSlot18)
                result->second.type = 2;
            else
                result->second.type = 1;
            return true;
        }
        else if (firstValidSlot0 && !secondValidSlot0)
        {
            result->type = 2;
            if (firstSlot0->parameter < epsilonSlot18 || firstSlot0->parameter > 1.0f - epsilonSlot18)
                result->first.type = 2;
            else
                result->first.type = 1;
            return true;
        }
        else if (!firstValidSlot0 && secondValidSlot0)
        {
            result->type = 1;
            (firstSlot0->point.*&NiPoint2::operator=)(secondSlot21->point);
            firstSlot0->parameter = secondSlot21->parameter;
            if (firstSlot0->parameter < epsilonSlot18 || firstSlot0->parameter > 1.0f - epsilonSlot18)
                result->first.type = 2;
            else
                result->first.type = 1;
            return true;
        }
        else
        {
            if (lineSlot1.start.GetSquaredXYLength() < radiusSquaredSlot0)
            {
                result->type = 5;
                return false;
            }
            else
            {
                result->type = 0;
                return false;
            }
        }
    }
}
}


struct Obstacle_6bb8b0
{
    bool AngleSinCosArc_WithinRange(const NiPoint2& pt);
};

float __cdecl my_sqrt(float f);

// @fnv 0x006bb8b0
// src: COMMUNITY 0x006bb8b0
bool __cdecl NavMeshMath_CheckArcAgainstCircle(const NiBound* pSphereA, Obstacle_6bb8b0* pObstacle, const NiBound* pSphereB)
{
    if (pSphereA->m_fRadius == 0.0)
        return true;
    if (pSphereB->m_fRadius == 0.0)
        return true;
    NiPoint3 c = pSphereB->m_kCenter.SubtractIntoVector(pSphereA->m_kCenter);
    float p = c.FUN_004a7290();
    float l = c.GetSquaredXYLength();
    if (l == 0.0)
        return false;
    float h = pSphereA->m_fRadius + pSphereB->m_fRadius;
    if (h * h < l)
        return true;
    if (h * h < p)
        return true;
    float q = pSphereA->m_fRadius - pSphereB->m_fRadius;
    if (l < q * q)
        return true;
    if (p < q * q)
        return true;
    float k = pSphereA->m_fRadius * pSphereA->m_fRadius;
    float cf = pSphereB->m_fRadius * pSphereB->m_fRadius;
    float b = my_sqrt(l);
    float eb = 1.0f / b;
    float f = 1.0f / pSphereA->m_fRadius;
    float i = (k - cf + l) * 0.5 * eb;
    float e = i * i;
    float j;
    float ba = my_sqrt((j = k - e));
    NiPoint2 s;
    s.x = (i * c.x + ba * c.y) * f * eb;
    s.y = (i * c.y - ba * c.x) * f * eb;
    NiPoint2 a;
    a.x = (i * c.x - ba * c.y) * f * eb;
    a.y = (i * c.y + ba * c.x) * f * eb;
    if (pObstacle->AngleSinCosArc_WithinRange(s))
        return false;
    if (pObstacle->AngleSinCosArc_WithinRange(a))
        return false;
    return true;
}

// Reconstruct the target using named fields and the pack's local object types.
struct BuildItem
{
    unsigned short objectId;
    unsigned char enabled[3];
    unsigned char options;
    unsigned short component[3];
};

struct BuildCollection
{
    void* elements;
    unsigned int count;
    unsigned int capacity;
    unsigned int grow;
    unsigned int FUN_0044ddc0() const;
    FUN_006bc8b0* GetElementAddress_006bf670(unsigned int index);
    unsigned short* GetBufferEntry(unsigned int index);
    BuildItem* Object_GetIndexedValue_006a1440(unsigned int index);
    int FUN_004b9ba0();
    void NiTMapBase_DFALL_NiTMapItem_unsigned_short_NiPointer_ObstacleData_unsigned_short_NiPointer_ObstacleData_GetNext(int* cursor, unsigned short* value, void* tag);
};

struct BuildInput
{
    unsigned int formID;
    unsigned int flags;
    unsigned int phase;
    unsigned int refCount;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int firstIndex;
    unsigned int indexCount;
    BuildCollection idCollection;
    BuildCollection componentCollection;
    BuildCollection valueCollection;
    BuildCollection annotationCollection;
};

struct BuildValue
{
    void ClearFlags(unsigned int flags);
    void SetSlotValue(int coordinate, unsigned short value);
    void SetArrayValue(int coordinate, unsigned short value);
    void SetFlag_00691570(unsigned int flags);
    unsigned short GetBits13To15();
    void NavMeshTriangle_SetObjectCount(unsigned int lastIndex);
};



struct BuildManager
{
    void FUN_0049c250(unsigned short value);
    void NiTMapBase_DFALL_NiTMapItem_unsigned_short_NiPointer_NavMeshObstacleData_unsigned_short_NiPointer_NavMeshObstacleData_SetAt(unsigned short index, NiPointer<ObstacleData> record);
};

struct BuildOutput
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
    BuildManager* manager;
    BuildValue* FUN_005582f0(unsigned short id);
};

struct BuildBounds
{
    NavMeshEdgeData m0;
    NavMeshEdgeData mC;
    bool processed;
    BuildBounds();
};

struct BuildName
{
    int field00;
    int field04;
    int field08;
    void CopyFromNavMeshEdge(const void*);
};

struct BuildLookup
{
    void* elements;
    unsigned int count;
    unsigned int capacity;
    unsigned int grow;
    int FindIndexIf(const BuildName* name, int option, void (*callback)(void*, int));
    void AppendElement(const BuildName* name);
    void FUN_0061bf70(unsigned int id);
};

struct BuildCatalog
{
    BuildLookup primary;
    BuildLookup alternate;
};

struct BuildIds
{
    void* elements;
    unsigned int count;
    unsigned int capacity;
    unsigned int grow;
    void SetVirtualTableAndProcessState_00438660();
    void UpdateState_00438690();
    int FUN_00719b20(const int* pIndex, int mode, void (*compare)());
    void FUN_007cb2e0(const int* pIndex);
    unsigned int FUN_0044ddc0();
    bool NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty();
    void BSSimpleArray_Sort(const void* comparator);
    unsigned int* FUN_00877a30(int index, bool reverse);
};

struct BuildIdsScope : BuildIds
{
    BuildIdsScope()
    {
        SetVirtualTableAndProcessState_00438660();
    }
    ~BuildIdsScope()
    {
        UpdateState_00438690();
    }
};

struct BuildProcess
{
    BuildOutput* output;
    unsigned int flags;
    BuildInput* input;
    void NavMeshObstacleCutter_UpdateCoverArray();
    void MarkNavMeshTriangles();
    bool Build(BuildOutput* outputParam, BuildInput* inputParam, BuildCatalog* catalog);
};

extern void CallWithInt(void*, int);
extern void Actor_AreReferencedValuesEqual();
extern const int UNK_006bfb30;
// Builds output from input: registers annotation bounds in the catalog, marks values, applies components, and processes the value collection.
// @fnv 0x006bc3e0
bool BuildProcess::Build(BuildOutput* pOutput, BuildInput* pInput, BuildCatalog* catalog)
{
    output = pOutput;
    input = pInput;
    int cursor;
    {
        BuildIdsScope names;
        for (unsigned int i = 0; i < input->annotationCollection.FUN_0044ddc0(); ++i)
        {
            int entry;
            {
                BuildBounds bounds;
                ((BuildName*)&bounds.mC)->CopyFromNavMeshEdge(input->annotationCollection.GetElementAddress_006bf670(i));
                ((BuildName*)&bounds.m0)->CopyFromNavMeshEdge(&input->annotationCollection.GetElementAddress_006bf670(i)->mC);
                bounds.processed = false;
                entry = catalog->primary.FindIndexIf((BuildName*)&bounds.m0, 0, CallWithInt);
                if (entry != -1)
                {
                    if (names.FUN_00719b20(&entry, 0, Actor_AreReferencedValuesEqual) == -1)
                    {
                        names.FUN_007cb2e0(&entry);
                    }
                }
                else
                {
                    if (catalog->alternate.FindIndexIf((BuildName*)&bounds.m0, 0, CallWithInt) == -1)
                    {
                        catalog->alternate.AppendElement((BuildName*)&bounds.m0);
                    }
                }
                if (catalog->primary.FindIndexIf((BuildName*)&bounds.mC, 0, CallWithInt) == -1)
                {
                    catalog->primary.AppendElement((BuildName*)&bounds.mC);
                }
            }
        }
        if (!names.NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
        {
            names.BSSimpleArray_Sort(&UNK_006bfb30);
            for (int i = (int)names.FUN_0044ddc0() - 1; i >= 0; --i)
            {
                catalog->primary.FUN_0061bf70(*names.FUN_00877a30(i, true));
            }
        }
        for (unsigned int i = 0; i < input->idCollection.FUN_0044ddc0(); ++i)
        {
            BuildValue* value = output->FUN_005582f0(*input->idCollection.GetBufferEntry(i));
            value->ClearFlags(0x20);
        }
        for (unsigned int i = 0; i < input->componentCollection.FUN_0044ddc0(); ++i)
        {
            BuildValue* value = output->FUN_005582f0(input->componentCollection.Object_GetIndexedValue_006a1440(i)->objectId);
            value->ClearFlags(0x100);
            for (int component = 0; component < 3; ++component)
            {
                if (input->componentCollection.Object_GetIndexedValue_006a1440(i)->enabled[component])
                {
                    value->SetSlotValue(component, input->componentCollection.Object_GetIndexedValue_006a1440(i)->component[component]);
                }
                else
                {
                    value->SetArrayValue(component, input->componentCollection.Object_GetIndexedValue_006a1440(i)->component[component]);
                }
            }
        }
        for (unsigned int id = input->firstIndex; id < input->firstIndex + input->indexCount; ++id)
        {
            output->FUN_005582f0((unsigned short)id)->SetFlag_00691570(0x20);
        }
        for (unsigned int i = 0; i < input->componentCollection.FUN_0044ddc0(); ++i)
        {
            BuildValue* value = output->FUN_005582f0(input->componentCollection.Object_GetIndexedValue_006a1440(i)->objectId);
            value->NavMeshTriangle_SetObjectCount((unsigned int)value->GetBits13To15() - 1);
        }
        for (unsigned int id = input->firstIndex; id < input->firstIndex + input->indexCount; ++id)
        {
            output->manager->FUN_0049c250((unsigned short)id);
        }
        for (cursor = input->valueCollection.FUN_004b9ba0(); cursor != 0;)
        {
            unsigned short identifier;
            {
                NiPointer<ObstacleData> tag(0);
                input->valueCollection.NiTMapBase_DFALL_NiTMapItem_unsigned_short_NiPointer_ObstacleData_unsigned_short_NiPointer_ObstacleData_GetNext(&cursor, &identifier, &tag);
                output->manager->NiTMapBase_DFALL_NiTMapItem_unsigned_short_NiPointer_NavMeshObstacleData_unsigned_short_NiPointer_NavMeshObstacleData_SetAt(identifier, tag);
            }
        }
        NavMeshObstacleCutter_UpdateCoverArray();
        MarkNavMeshTriangles();
        input->phase = 3;
        return true;
    }
}

struct AdjTriangle
{
    void SetFlag(int aiFlag);
    void SetFlagB(int aiFlag);
    bool IsEdgeExternal(int aiEdge);
    bool HasEdgeLink(int aiEdge);
    unsigned short GetEdgeLink(int aiEdge);
};

struct AdjMesh
{
    AdjTriangle* GetTriangle(unsigned short ausIndex);
    unsigned int GetTriangleCount();
};

typedef int(__cdecl* AdjCompareFn)(const void*, const void*);
int __cdecl AdjCompareIndex(const void* apA, const void* apB);

struct AdjIndexArray
{
    unsigned int GetSize();
    unsigned short* GetAt(unsigned int auiIndex);
    int Find(unsigned int* apValue, unsigned int auiStart, AdjCompareFn apfnCompare);
};

struct AdjSource
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    AdjIndexArray kIndices;
};

struct AdjEntry
{
    unsigned short m_usTriangleID;
    unsigned char ucEdgeExternal[3];
    unsigned char ucPad;
    unsigned short usEdgeLink[3];
};

struct AdjEntryArray
{
    unsigned int GetSize();
    AdjEntry* GetAt(unsigned int auiIndex);
    void SetSize(unsigned int auiSize, bool abShrink);
};

struct AdjBuilder
{
    AdjMesh* pMesh;
    int unk04;
    AdjSource* pSource;

    void CollectLinkedTriangles(AdjEntryArray* apOut);
};

// Marks each source triangle's flag, then appends linked triangles not in the source index list to apOut with their edge data.
// @fnv 0x006bca20
void AdjBuilder::CollectLinkedTriangles(AdjEntryArray* apOut)
{
    for (unsigned int i = 0; i < pSource->kIndices.GetSize(); i++)
    {
        AdjTriangle* pTri = pMesh->GetTriangle(*pSource->kIndices.GetAt(i));
        pTri->SetFlag(0x100);
        for (int j = 0; j < 3; j++)
        {
            if (!pTri->IsEdgeExternal(j) && pTri->HasEdgeLink(j))
            {
                unsigned int uiLinked = pTri->GetEdgeLink(j);
                if (uiLinked >= pMesh->GetTriangleCount())
                    continue;
                AdjTriangle* pLinked = pMesh->GetTriangle((unsigned short)uiLinked);
                if (pSource->kIndices.Find(&uiLinked, 0, AdjCompareIndex) == -1)
                {
                    bool bFound = false;
                    for (unsigned int k = 0; k < apOut->GetSize(); k++)
                    {
                        if (apOut->GetAt(k)->m_usTriangleID == uiLinked)
                        {
                            bFound = true;
                            break;
                        }
                    }
                    if (!bFound)
                    {
                        unsigned int uiIndex = apOut->GetSize();
                        apOut->SetSize(uiIndex + 1, true);
                        apOut->GetAt(uiIndex)->m_usTriangleID = (unsigned short)uiLinked;
                        pLinked->SetFlagB(0x100);
                        for (unsigned int m = 0; m < 3; m++)
                        {
                            if (pLinked->IsEdgeExternal(m))
                            {
                                apOut->GetAt(uiIndex)->ucEdgeExternal[m] = 1;
                                apOut->GetAt(uiIndex)->usEdgeLink[m] = pLinked->GetEdgeLink(m);
                            }
                            else
                            {
                                apOut->GetAt(uiIndex)->ucEdgeExternal[m] = 0;
                                apOut->GetAt(uiIndex)->usEdgeLink[m] = pLinked->GetEdgeLink(m);
                            }
                        }
                    }
                }
            }
        }
    }
}

struct VertS
{
    unsigned short idx;
    unsigned char unk2;
    unsigned char flag3;
    unsigned char flag4;
};
struct EdgeS
{
    VertS* a;
    VertS* b;
    unsigned short triangle;
    unsigned short unk0a;
    unsigned int unk0c;
    unsigned int cls;
    unsigned short unk14;
    unsigned short property;
    bool flag1;
    bool flag2;
    unsigned short unk1a;
    unsigned int f1c;
    unsigned int f20;
    unsigned short f24;
    unsigned short unk26;
    unsigned int f28;
    unsigned short f2c;
    unsigned short unk2e;
    void NavMeshObstacleEdge_AddTriangle(unsigned short, unsigned short);
};
struct TriX
{
    bool IsEdgeFlagSet(int);
    unsigned short GetEdgeExtraInfo_0068f2c0(int);
    unsigned short GetVert_005582d0(int);
    void GetPackedFlags(unsigned short, unsigned short*, bool*, bool*);
};
struct MeshX
{
    bool FindAdjacentEdge(unsigned short, int, unsigned short*, unsigned short*, unsigned short*);
    int FUN_006997b0(unsigned short, int);
};
bool __cdecl AreWideCharsEqual(const unsigned short&, const unsigned short&);
struct NavMeshTriList : DA00694f80
{
    unsigned int GetSize() const;
    int FindMatchingIndex(const unsigned short&, unsigned int,
                          bool(__cdecl*)(const unsigned short&, const unsigned short&));
};
struct Holder8
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    NavMeshTriList m_kNavMeshTriangleList;
};
struct ArrV
{
    int f00;
    int f04;
    int f08;
    int f0c;
    VertS** FUN_00877a30(int);
    unsigned int FUN_007cb2e0(VertS**);
};
struct ArrE
{
    int f00;
    int f04;
    int f08;
    int f0c;
    unsigned int FUN_007cb2e0(EdgeS**);
};
struct HostB60
{
    NavMesh* mesh;
    int f04;
    Holder8* p8;
    int f0c;
    int f10;
    int f14;
    int f18;
    ArrV verts;
    int f2c;
    ArrE edges;
    unsigned int FindIndexByValue(unsigned short);
    VertS* NavMeshObstacleCutter_CreateVertex(unsigned short, int, bool, bool);
    EdgeS* CreateObject(VertS*, VertS*, int);
    void BuildNavMeshEdges();
};
// @fnv 0x006bcc60
void HostB60::BuildNavMeshEdges()
{
    int i;
    for (i = 0; i < p8->m_kNavMeshTriangleList.GetSize(); ++i)
    {
        TriX* tri = (TriX*)mesh->GetTriangle(p8->m_kNavMeshTriangleList.GetAt(i));
        int j;
        for (j = 0; j < 3; ++j)
        {
            int cls = 3;
            bool flagE = false;
            bool flagD = false;
            if (tri->IsEdgeFlagSet(j))
            {
                cls = 4;
                flagD = true;
            }
            else if (tri->GetEdgeExtraInfo_0068f2c0(j) == 0xffff)
            {
                cls = 3;
                flagD = true;
            }
            else
            {
                if (p8->m_kNavMeshTriangleList.FindMatchingIndex(tri->GetEdgeExtraInfo_0068f2c0(j), 0, AreWideCharsEqual) == -1)
                {
                    cls = 2;
                    flagE = true;
                }
            }
            if (flagE || flagD)
            {
                unsigned short vi[2];
                vi[0] = tri->GetVert_005582d0(j);
                vi[1] = tri->GetVert_005582d0((j + 1) % 3);
                VertS* pv[2];
                unsigned int k;
                for (k = 0; k < 2; ++k)
                {
                    int found = (int)FindIndexByValue(vi[k]);
                    if (found == -1)
                    {
                        VertS* newVert = NavMeshObstacleCutter_CreateVertex(vi[k], 0, flagE, flagD);
                        verts.FUN_007cb2e0(&newVert);
                        pv[k] = newVert;
                    }
                    else
                    {
                        (*verts.FUN_00877a30(found))->flag3 =
                            (unsigned char)(int)((*verts.FUN_00877a30(found))->flag3 || flagE);
                        (*verts.FUN_00877a30(found))->flag4 =
                            (unsigned char)(int)((*verts.FUN_00877a30(found))->flag4 || flagD);
                        pv[k] = *verts.FUN_00877a30(found);
                    }
                }
                EdgeS* ed = CreateObject(pv[0], pv[1], cls);
                if (cls == 2)
                {
                    int outC;
                    int outB;
                    int outA;
                    if (((MeshX*)mesh)
                            ->FindAdjacentEdge(p8->m_kNavMeshTriangleList.GetAt(i), j, (unsigned short*)&outC,
                                               (unsigned short*)&outA, (unsigned short*)&outB))
                        ed->NavMeshObstacleEdge_AddTriangle(outA, outB);
                }
                if (cls == 3)
                {
                    ((MeshX*)mesh)->FUN_006997b0(p8->m_kNavMeshTriangleList.GetAt(i), (int)&ed->f1c);
                }
                if (cls == 4)
                {
                    ed->f20 = 0;
                    ed->f24 = p8->m_kNavMeshTriangleList.GetAt(i);
                    ed->f28 = j;
                    ed->f2c = tri->GetEdgeExtraInfo_0068f2c0(j);
                }
                edges.FUN_007cb2e0(&ed);
                if ((unsigned int)j < 2)
                    tri->GetPackedFlags((unsigned short)j, &ed->property, &ed->flag1, &ed->flag2);
            }
        }
    }
}

struct Corner
{
    float x, y, z;
    Corner();
    Corner(float, float, float);
    Corner operator+(const Corner&) const;
    Corner operator-(const Corner&) const;
    float Length() const;
};
struct LocalPoint
{
    float x, y, z;
    LocalPoint();
};
struct Matrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    Corner Transform(const Corner*);
};
struct Shape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Corner position;
    Matrix rotation;
    float value40;
    float value44;
    float value48;
    float value4c;
    float value50;
    float value54;
    float value58;
    float value5c;
    float value60;
    float value64;
    float value68;
    float value6c;
};
struct ShapePtr
{
    Shape* Get() const;
    ShapePtr& Assign(const ShapePtr&);
};
struct Vertex
{
    unsigned short index;
};
struct Edge
{
    Vertex* first;
    Vertex* second;
    int unk08, unk0c, unk10;
    unsigned short unk14, height;
    unsigned char enabled, marked;
    unsigned short unk1a;
    ShapePtr owner;
};
struct Mesh
{
    bool Project(Corner*, float, float, float*);
    unsigned short AddVertex(const Corner*);
    const Corner& GetVertex(unsigned short);
};
struct List
{
    int a, b, c, d, e;
    unsigned Add(void*&);
};
unsigned short ConvertHeight(float, int, int);
extern float projectionDefault;
extern double lengthThreshold;
struct Builder
{
    Mesh* mesh;
    ShapePtr shape;
    int unk08, unk0c, unk10, unk14, unk18;
    List vertices;
    List edges;
    Vertex* MakeVertex(unsigned short, int, int, int);
    Edge* MakeEdge(Vertex*, Vertex*, int);
    void BuildQuad();
};
// Builds a four-vertex quad from the shape's corner values, projects and adds the vertices, links them with edges, and marks edges longer than lengthThreshold.
// @fnv 0x006bd040
void Builder::BuildQuad()
{
    Corner tmp[4];
    tmp[0] = Corner(shape.Get()->value40, shape.Get()->value44, shape.Get()->value48);
    tmp[1] = Corner(shape.Get()->value40, shape.Get()->value50, shape.Get()->value48);
    tmp[2] = Corner(shape.Get()->value4c, shape.Get()->value50, shape.Get()->value48);
    tmp[3] = Corner(shape.Get()->value4c, shape.Get()->value44, shape.Get()->value48);
    unsigned short q;
    float b;
    b = shape.Get()->value6c - shape.Get()->value60;
    q = ConvertHeight(b, 1, 0);
    Vertex* links[4];
    Corner points[4];
    {
        Edge* height[4];
        for (unsigned idx = 0; 4 > idx; idx++)
        {
            points[idx] = shape.Get()->rotation.Transform(&tmp[idx]) + shape.Get()->position;
            float index;
            index = points[idx].z;
            if (mesh->Project(&points[idx], projectionDefault, b, &index))
                points[idx].z = index;
        }
        for (unsigned next = 0; next < 4; next++)
        {
            LocalPoint point;
            (Corner&)point = points[next];
            unsigned short x;
            x = mesh->AddVertex((Corner*)&point);
            links[next] = MakeVertex(x, 1, 0, 0);
            vertices.Add((void*&)links[next]);
        }
        for (unsigned edge = 0; edge < 4; edge++)
        {
            Edge* pForm;
            pForm = MakeEdge(links[edge], links[(1 + edge) % 4], 1);
            height[edge] = pForm;
            edges.Add((void*&)pForm);
        }
        for (unsigned mark = 0; 4 > mark; mark++)
        {
            if ((mesh->GetVertex(height[mark]->second->index) - mesh->GetVertex(height[mark]->first->index)).Length() >
                lengthThreshold)
            {
                height[mark]->height = q;
                height[mark]->enabled = 1;
                height[mark]->marked = 1;
                height[mark]->owner.Assign(shape);
            }
        }
    }
}

struct Vec74
{
    float x, y, z;
    Vec74();
    Vec74 SubtractIntoVector(const Vec74&);
    float GetSquaredXYLength();
};
struct VertexData74
{
    Vec74 position;
    VertexData74();
};
struct Vertex74
{
    unsigned short index;
};
struct Reference74
{
    void NiRefObject_DecRefCount();
};
struct Smart74
{
    Reference74* ptr;
    Reference74* Modelloader_GetReferencedThis();
    void FUN_006e5cc0(const Smart74&);
};
struct EdgeData74
{
    int unk00, unk04, unk08;
    void CopyFromNavMeshEdge(const EdgeData74&);
};
struct Edge74
{
    Vertex74* start;
    Vertex74* end;
    int unk08, unk0c;
    int type;
    short unk14;
    unsigned short flags;
    bool startFlag, endFlag;
    short unk1a;
    Smart74 reference;
    EdgeData74 data;
    unsigned short tag;
    bool split;
    char unk2f;
};
struct EdgeList74
{
    void* ptr;
    int unk04, unk08, unk0c, unk10;
    unsigned int FUN_0044ddc0();
    Edge74*& FUN_00877a30(unsigned int);
    void FUN_007cb2e0(Edge74* const&);
    void BSSimpleArray_HUDMainMenu_SubtitleData_1024_Remove(unsigned int, int);
};
struct VertexList74
{
    void* ptr;
    int unk04, unk08, unk0c, unk10;
    void FUN_007cb2e0(Vertex74* const&);
};
struct Mesh74
{
    Vec74* GetVertex_0068f0a0(unsigned short);
    unsigned short NavMesh_AddVertex(VertexData74&);
};
bool NavMeshMath_Find2DIntersection_2(const Vec74&, const Vec74&, const Vec74&, const Vec74&, Vec74&);
struct Processor74
{
    Mesh74* mesh;
    int unk04, unk08, unk0c, unk10, unk14, unk18;
    VertexList74 vertices;
    EdgeList74 edges;
    Vertex74* NavMeshObstacleCutter_CreateVertex(unsigned short, int, int, int);
    Edge74* CreateObject(Vertex74*, Vertex74*, int);
    void SplitCrossingEdges();
};
// @fnv 0x006bd540
void Processor74::SplitCrossingEdges()
{
    for (unsigned int i = 0; i < edges.FUN_0044ddc0(); ++i)
    {
        Edge74* first6 = edges.FUN_00877a30(i);
        if (first6->type != 1)
            continue;
        Vertex74* a2 = first6->start;
        Vertex74* b10 = first6->end;
        Vec74* pa51 = mesh->GetVertex_0068f0a0(a2->index);
        Vec74* pb32 = mesh->GetVertex_0068f0a0(b10->index);
        for (unsigned int j = 0; j < edges.FUN_0044ddc0(); ++j)
        {
            Edge74* second23 = edges.FUN_00877a30(j);
            if (second23->type != 3 && second23->type != 4)
                continue;
            Vertex74* c5 = second23->start;
            Vertex74* d5 = second23->end;
            Vec74* pc21 = mesh->GetVertex_0068f0a0(c5->index);
            Vec74* pd20 = mesh->GetVertex_0068f0a0(d5->index);
            if (c5 == a2 || d5 == a2 || c5 == b10 || d5 == b10)
                continue;
            Vec74 crossing2;
            if (NavMeshMath_Find2DIntersection_2(*pc21, *pd20, *pa51, *pb32, crossing2))
            {
                float tolerance8 = 0.0001f;
                bool splitFirst21 = false;
                bool splitSecond20 = false;
                Vertex74* intersection6;
                if (pc21->SubtractIntoVector(crossing2).GetSquaredXYLength() < tolerance8)
                {
                    intersection6 = c5;
                    splitFirst21 = true;
                    splitSecond20 = false;
                }
                else if (pd20->SubtractIntoVector(crossing2).GetSquaredXYLength() < tolerance8)
                {
                    intersection6 = d5;
                    splitFirst21 = true;
                    splitSecond20 = false;
                }
                else if (pa51->SubtractIntoVector(crossing2).GetSquaredXYLength() < tolerance8)
                {
                    intersection6 = a2;
                    splitFirst21 = false;
                    splitSecond20 = true;
                }
                else if (pb32->SubtractIntoVector(crossing2).GetSquaredXYLength() < tolerance8)
                {
                    intersection6 = b10;
                    splitFirst21 = false;
                    splitSecond20 = true;
                }
                else
                {
                    VertexData74 vertex53;
                    vertex53.position = crossing2;
                    unsigned short index13 = mesh->NavMesh_AddVertex(vertex53);
                    intersection6 = NavMeshObstacleCutter_CreateVertex(index13, 1, 0, 1);
                    vertices.FUN_007cb2e0(intersection6);
                    splitFirst21 = true;
                    splitSecond20 = true;
                }
                Edge74* firstA3 = 0;
                Edge74* firstB42 = 0;
                Edge74* secondA37 = 0;
                Edge74* secondB23 = 0;
                if (splitFirst21)
                {
                    firstA3 = CreateObject(a2, intersection6, 1);
                    firstB42 = CreateObject(intersection6, b10, 1);
                    firstA3->split = true;
                    firstB42->split = true;
                    firstA3->flags = first6->flags;
                    firstB42->flags = first6->flags;
                    if (first6->startFlag)
                        firstA3->startFlag = true;
                    if (first6->endFlag)
                        firstB42->endFlag = true;
                    firstA3->reference.FUN_006e5cc0(first6->reference);
                    firstB42->reference.FUN_006e5cc0(first6->reference);
                }
                if (splitSecond20)
                {
                    secondA37 = CreateObject(c5, intersection6, second23->type);
                    secondB23 = CreateObject(intersection6, d5, second23->type);
                    secondA37->split = true;
                    secondA37->data.CopyFromNavMeshEdge(second23->data);
                    secondA37->tag = second23->tag;
                    secondB23->split = true;
                    secondB23->data.CopyFromNavMeshEdge(second23->data);
                    secondB23->tag = second23->tag;
                    secondA37->flags = second23->flags;
                    secondB23->flags = second23->flags;
                    if (second23->startFlag)
                        secondA37->startFlag = true;
                    if (second23->endFlag)
                        secondB23->endFlag = true;
                    secondA37->reference.FUN_006e5cc0(second23->reference);
                    secondB23->reference.FUN_006e5cc0(second23->reference);
                }
                if (splitFirst21 && splitSecond20)
                {
                    if (i > j)
                    {
                        if (edges.FUN_00877a30(i)->reference.Modelloader_GetReferencedThis())
                            edges.FUN_00877a30(i)->reference.Modelloader_GetReferencedThis()->NiRefObject_DecRefCount();
                        if (edges.FUN_00877a30(j)->reference.Modelloader_GetReferencedThis())
                            edges.FUN_00877a30(j)->reference.Modelloader_GetReferencedThis()->NiRefObject_DecRefCount();
                        edges.BSSimpleArray_HUDMainMenu_SubtitleData_1024_Remove(i, 1);
                        edges.BSSimpleArray_HUDMainMenu_SubtitleData_1024_Remove(j, 1);
                        i -= 2;
                    }
                    else
                    {
                        if (edges.FUN_00877a30(i)->reference.Modelloader_GetReferencedThis())
                            edges.FUN_00877a30(i)->reference.Modelloader_GetReferencedThis()->NiRefObject_DecRefCount();
                        if (edges.FUN_00877a30(j)->reference.Modelloader_GetReferencedThis())
                            edges.FUN_00877a30(j)->reference.Modelloader_GetReferencedThis()->NiRefObject_DecRefCount();
                        edges.BSSimpleArray_HUDMainMenu_SubtitleData_1024_Remove(j, 1);
                        edges.BSSimpleArray_HUDMainMenu_SubtitleData_1024_Remove(i, 1);
                        i -= 1;
                    }
                }
                else
                {
                    if (splitFirst21)
                    {
                        if (edges.FUN_00877a30(i)->reference.Modelloader_GetReferencedThis())
                            edges.FUN_00877a30(i)->reference.Modelloader_GetReferencedThis()->NiRefObject_DecRefCount();
                        edges.BSSimpleArray_HUDMainMenu_SubtitleData_1024_Remove(i, 1);
                        i -= 1;
                    }
                    if (splitSecond20)
                    {
                        if (edges.FUN_00877a30(j)->reference.Modelloader_GetReferencedThis())
                            edges.FUN_00877a30(j)->reference.Modelloader_GetReferencedThis()->NiRefObject_DecRefCount();
                        edges.BSSimpleArray_HUDMainMenu_SubtitleData_1024_Remove(j, 1);
                        if (i > j)
                            i -= 1;
                    }
                }
                if (splitFirst21)
                {
                    edges.FUN_007cb2e0(firstA3);
                    edges.FUN_007cb2e0(firstB42);
                }
                if (splitSecond20)
                {
                    edges.FUN_007cb2e0(secondA37);
                    edges.FUN_007cb2e0(secondB23);
                }
                break;
            }
        }
    }
}

struct S6bdcb0Target
{
    void Release();
};

struct S6bdcb0Ref
{
    S6bdcb0Target* m_pObject;
    operator S6bdcb0Target*() const;
};

struct S6bdcb0Node
{
    int unk00;
    unsigned char bFlag04;
    unsigned char bFlag05;
};

struct S6bdcb0Item
{
    S6bdcb0Node* pFrom;
    S6bdcb0Node* pTo;
    int unk08;
    int unk0C;
    int iType;
    int unk14;
    int unk18;
    S6bdcb0Ref spRetainedObject;
};

struct S6bdcb0Array
{
    unsigned int GetSize();
    S6bdcb0Item*& GetAt(unsigned int idx);
    void RemoveAt(unsigned int idx, bool bFlag);
};

struct S6bdcb0Owner
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
    S6bdcb0Array kItems;

    bool ShouldRemove(S6bdcb0Item* pItem);
    void NavMeshObstacleCutter_RemoveInvalidEdges();
};

// @fnv 0x006bdcb0
// src: COMMUNITY 0x006bdcb0
void S6bdcb0Owner::NavMeshObstacleCutter_RemoveInvalidEdges()
{
    for (unsigned int i = 0; i < kItems.GetSize(); i++)
    {
        if (ShouldRemove(kItems.GetAt(i)))
        {
            if (kItems.GetAt(i)->spRetainedObject)
                ((S6bdcb0Target*)kItems.GetAt(i)->spRetainedObject)->Release();
            kItems.RemoveAt(i, true);
            i--;
        }
        else if (kItems.GetAt(i)->iType == 1)
        {
            if (!(kItems.GetAt(i)->pFrom->bFlag05 || kItems.GetAt(i)->pFrom->bFlag04) ||
                !(kItems.GetAt(i)->pTo->bFlag05 || kItems.GetAt(i)->pTo->bFlag04))
            {
                if (kItems.GetAt(i)->spRetainedObject)
                    ((S6bdcb0Target*)kItems.GetAt(i)->spRetainedObject)->Release();
                kItems.RemoveAt(i, true);
                i--;
            }
        }
    }
}





struct EdgeSplit_6be830
{
    unsigned short m_iWordAt00;
    unsigned short m_cByteAtOffset2;
    unsigned short m_iWordAt04;
    unsigned short m_6;
    unsigned short m_8;
    unsigned short m_kPointA;
    unsigned short m_iThirdValue;
    unsigned short m_usTrailingValue;
};

struct EdgeSplitArray_6be830
{
    unsigned int GetSize();
    EdgeSplit_6be830*& GetAt(unsigned int idx);
};

struct NavMeshGen_6be830
{
    NavMesh* navMesh00;
    int unk04[11];
    EdgeSplitArray_6be830 arr30;

    void ApplyEdgeSplits();
};

// For each edge split with valid triangle indices, sets the corresponding edges on both adjacent navmesh triangles.
// @fnv 0x006be830
void NavMeshGen_6be830::ApplyEdgeSplits()
{
    for (unsigned int i = 0; i < this->arr30.GetSize(); ++i)
    {
        if (this->arr30.GetAt(i)->m_8 != 0xFFFF && this->arr30.GetAt(i)->m_kPointA != 0xFFFF)
        {
            this->navMesh00->GetTriangle(this->arr30.GetAt(i)->m_8)
                ->SetEdge(this->arr30.GetAt(i)->m_iThirdValue, this->arr30.GetAt(i)->m_kPointA);
            this->navMesh00->GetTriangle(this->arr30.GetAt(i)->m_kPointA)
                ->SetEdge(this->arr30.GetAt(i)->m_usTrailingValue, this->arr30.GetAt(i)->m_8);
        }
    }
}

struct EdgeKey120
{
    unsigned int mesh;
    unsigned short triangle, reserved;
    unsigned int edge;
    EdgeKey120();
};
struct EdgeRecord120
{
    EH first, second;
    bool active;
    EdgeRecord120();
};
struct IndexArray120
{
    unsigned int count, capacity;
    void* data;
    unsigned int grow;
    IndexArray120();
    ~IndexArray120();
    unsigned int FUN_0044ddc0();
    unsigned int* FUN_00877a30(unsigned int);
    int FUN_00719b20(unsigned int*, int, unsigned int(__cdecl*)(const int*, const int*));
    void FUN_007cb2e0(unsigned int*);
    bool NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty();
    void BSSimpleArray_Sort(int(__cdecl*)(unsigned int*, unsigned int*));
};
unsigned int __cdecl Actor_AreReferencedValuesEqual(const int*, const int*);
struct RecordArray120
{
    unsigned int count, capacity;
    void* data;
    unsigned int grow;
    int FindIndexIf(EdgeRecord120*, int, void(__cdecl*)(FUN_006bfb90_class*, int));
    void AppendElement(EdgeRecord120*);
    void FUN_0061bf70(unsigned int, int);
};
struct EdgeSource120
{
    unsigned int m0, m4;
    unsigned short triangle, reserved, edge, unused;
    unsigned int type, m14, m18, m1c;
    EH second;
};
struct EdgeSourceArray120
{
    unsigned int FUN_0044ddc0();
    EdgeSource120** FUN_00877a30(unsigned int);
};
struct RecordSink120
{
    void UpdateState_006bf730(EdgeRecord120*);
};
struct RecordOwner120
{
    unsigned int m00, m04, m08, m0c, m10, m14, m18, m1c, m20, m24, m28, m2c, m30, m34, m38, m3c, m40, m44, m48, m4c;
    RecordSink120 records;
};
struct EdgeUpdater120
{
    void* mesh;
    unsigned int m04;
    RecordOwner120* owner;
    unsigned int m0c, m10, m14, m18, m1c, m20, m24, m28, m2c;
    EdgeSourceArray120 edges;
    void UpdateEdgeRecords(RecordArray120*);
};
// @fnv 0x006be950
void EdgeUpdater120::UpdateEdgeRecords(RecordArray120* arrays)
{
    IndexArray120 removed;
    for (unsigned int i = 0; i < edges.FUN_0044ddc0(); i++)
    {
        if ((*edges.FUN_00877a30(i))->type == 4 && (*edges.FUN_00877a30(i))->triangle != 65535)
        {
            EdgeKey120 key;
            key.mesh = 0;
            key.triangle = (*edges.FUN_00877a30(i))->triangle;
            key.edge = (*edges.FUN_00877a30(i))->edge;
            EdgeRecord120 record;
            record.second = *reinterpret_cast<EH*>(&key);
            record.first = (*edges.FUN_00877a30(i))->second;
            record.active = true;
            owner->records.UpdateState_006bf730(&record);
            unsigned int index = arrays->FindIndexIf(&record, 0, CallWithInt);
            if (index != -1)
            {
                if (removed.FUN_00719b20(&index, 0, Actor_AreReferencedValuesEqual) == -1)
                    removed.FUN_007cb2e0(&index);
            }
            else
            {
                if (arrays[1].FindIndexIf(&record, 0, CallWithInt) == -1)
                    arrays[1].AppendElement(&record);
            }
            if (arrays->FindIndexIf(reinterpret_cast<EdgeRecord120*>(&record.second), 0, CallWithInt) == -1)
                arrays->AppendElement(reinterpret_cast<EdgeRecord120*>(&record.second));
        }
    }
    if (!removed.NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
    {
        removed.BSSimpleArray_Sort(Runtime_CompareUnsignedValues);
        for (int j = removed.FUN_0044ddc0() - 1; j >= 0; j--)
            arrays->FUN_0061bf70(*removed.FUN_00877a30(j), 1);
    }
}

struct EdgeVertex
{
    unsigned short index;
    unsigned char enabled;
    unsigned char unk03;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char blocked;
};
struct EdgePair
{
    EdgeVertex* a;
    EdgeVertex* b;
};
struct EdgePairs
{
    unsigned int FUN_0044ddc0();
    EdgePair** FUN_00877a30(unsigned int);
};
struct EdgeHost
{
    NH* mesh;
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    EdgePairs edges;
};
bool __cdecl NavMeshMath_Find2DIntersection_006ba010(const NiPoint2&, const NiPoint2&, const NiPoint2&, const NiPoint2&);

// @fnv 0x006beea0
bool FUN_006bde50::CanAddEdge(void* pVertexA, void* pVertexB)
{
    if (((EdgeVertex*)pVertexA)->enabled && ((EdgeVertex*)pVertexB)->enabled)
        return false;
    if (!((EdgeVertex*)pVertexA)->enabled && ((EdgeVertex*)pVertexA)->blocked)
        return false;
    if (!((EdgeVertex*)pVertexB)->enabled && ((EdgeVertex*)pVertexB)->blocked)
        return false;
    const PathPoint_blk_006a0000_od& a = (const PathPoint_blk_006a0000_od&)((EdgeHost*)this)->mesh->GetVertex_0068f0a0(((EdgeVertex*)pVertexA)->index);
    const PathPoint_blk_006a0000_od& b = (const PathPoint_blk_006a0000_od&)((EdgeHost*)this)->mesh->GetVertex_0068f0a0(((EdgeVertex*)pVertexB)->index);
    NiPoint2 p(a.x, a.y);
    NiPoint2 q(b.x, b.y);
    if (((EdgeVertex*)pVertexA)->enabled != ((EdgeVertex*)pVertexB)->enabled)
    {
        PathPoint_blk_006a0000_od midpoint = (a + b) * 0.5f;
        if (!((S_006bf1d0*)this)->NavMeshObstacleCutter_IsPointInOverlappedArea((const Point3Storage&)midpoint))
            return false;
    }
    for (unsigned int i = ((EdgeHost*)this)->edges.FUN_0044ddc0() - 1; i != -1; --i)
    {
        if (((*((EdgeHost*)this)->edges.FUN_00877a30(i))->a == pVertexA &&
             (*((EdgeHost*)this)->edges.FUN_00877a30(i))->b == pVertexB) ||
            ((*((EdgeHost*)this)->edges.FUN_00877a30(i))->a == pVertexB &&
             (*((EdgeHost*)this)->edges.FUN_00877a30(i))->b == pVertexA))
            return false;
        if ((*((EdgeHost*)this)->edges.FUN_00877a30(i))->a == pVertexA)
            continue;
        if ((*((EdgeHost*)this)->edges.FUN_00877a30(i))->b == pVertexA)
            continue;
        if ((*((EdgeHost*)this)->edges.FUN_00877a30(i))->a == pVertexB)
            continue;
        if ((*((EdgeHost*)this)->edges.FUN_00877a30(i))->b == pVertexB)
            continue;
        const Point3Storage& posEdgeA =
            ((EdgeHost*)this)->mesh->GetVertex_0068f0a0((*((EdgeHost*)this)->edges.FUN_00877a30(i))->a->index);
        const Point3Storage& posEdgeB =
            ((EdgeHost*)this)->mesh->GetVertex_0068f0a0((*((EdgeHost*)this)->edges.FUN_00877a30(i))->b->index);
        NiPoint2 edgePointA(posEdgeA.x, posEdgeA.y);
        NiPoint2 edgePointB(posEdgeB.x, posEdgeB.y);
        if (NavMeshMath_Find2DIntersection_006ba010(p, q, edgePointA, edgePointB))
            return false;
    }
    return true;
}

struct FUN_006bf570
{
    int unk00;
    int unk04;
    unsigned short unk08;
    unsigned short unk0a;
    unsigned short unk0c;
    unsigned short unk0e;
    int unk10;
    unsigned short unk14;
    unsigned short unk16;
    unsigned char unk18;
    unsigned char unk19;
    NP ref;
    hkQuaternion data;
    FUN_006bf570(int, int, int);
};
// @fnv 0x006bf570
FUN_006bf570::FUN_006bf570(int aiFirst, int aiSecond, int aiThird) : ref(0)
{
    unk00 = aiFirst;
    unk04 = aiSecond;
    unk08 = 0xffff;
    unk0a = 0xffff;
    unk0c = 0xffff;
    unk0e = 0xffff;
    unk10 = aiThird;
    unk16 = 0;
    unk18 = 0;
    unk19 = 0;
    unk14 = 0xffff;
    data.unk00 = 0;
    data.unk04 = 0xffff;
    data.unk08 = -1;
    data.unk0c = 0xffff;
    data.unk0e = 0;
}

struct FUN_006b4670
{
    FUN_006b4670();
    ~FUN_006b4670();
    virtual void v00();
    int m_04, m_08, m_0c;
};
struct FUN_006b4220 : FUN_006b4670
{
    void* m_10;
    virtual void v00();
    void BSSimpleArray_float_1024_InitialSetup(unsigned int a, unsigned int b);
    FUN_006b4220();
};
// Initializes m_10 from the handle returned by FUN_00401020 and calls FUN_006b3eb0 with zero arguments.
// @fnv 0x006b4220
FUN_006b4220::FUN_006b4220()
{
    m_10 = MemoryManager_Instance()->GetHandle();
    BSSimpleArray_float_1024_InitialSetup(0, 0);
}

struct V006b9b10
{
    float x;
    float y;
    float z;
    V006b9b10* SubtractIntoVector(V006b9b10* out, V006b9b10* in);
    V006b9b10* FUN_00439e90(V006b9b10* out, V006b9b10* in);
    double DotProduct(V006b9b10* other);
    float FUN_00457990();
};
V006b9b10* __cdecl FUN_004a3760(V006b9b10* out, float scale, V006b9b10* value);

// @fnv 0x006b9b10
float __cdecl DistanceToSegment(V006b9b10* first, V006b9b10* origin, V006b9b10* second, unsigned char* inside)
{
    V006b9b10 segmentTmp;
    V006b9b10 point;
    double kIter;
    double firstDistance3;
    double lengthSquaredTmp;
    {
        V006b9b10 c2;
        {
            V006b9b10 pA;
            V006b9b10 pForm;
            V006b9b10 x7;
            V006b9b10 scaled5;

            second->SubtractIntoVector(&segmentTmp, origin);
            first->SubtractIntoVector(&point, origin);
            kIter = point.DotProduct(&segmentTmp);
            if (kIter <= 0.0)
            {
                if (inside)
                    *inside = 0;
                return first->SubtractIntoVector(&pA, origin)->FUN_00457990();
            }

            lengthSquaredTmp = segmentTmp.DotProduct(&segmentTmp);
            if (lengthSquaredTmp <= kIter)
            {
                if (inside)
                    *inside = 0;
                return first->SubtractIntoVector(&x7, second)->FUN_00457990();
            }

            firstDistance3 = kIter / lengthSquaredTmp;
            origin->FUN_00439e90(&c2, FUN_004a3760(&pForm, (float)firstDistance3, &segmentTmp));
            if (inside)
                *inside = 1;
            return first->SubtractIntoVector(&scaled5, &c2)->FUN_00457990();
        }
    }
}

namespace ns6b {
struct V3
{
    float x, y, z;
    V3();
    V3 SubtractIntoVector(const V3& o) const;
    V3 FUN_00439e90(const V3& o) const;
};
V3 __cdecl FUN_004a3760(float scale, const V3& v);
}
using ns6b::V3;

// @fnv 0x006ba6e0
// src: XBOX_PDB 0x006ba6e0
bool __cdecl NavMeshMath_LineToLineSegment2DIntersection(const V3& aStart, const V3& aEnd, const V3& cStart, const V3& cEnd, V3* out)
{
    V3 es = aEnd.SubtractIntoVector(aStart);
    V3 gt = cEnd.SubtractIntoVector(cStart);
    float yx = es.x * gt.y - es.y * gt.x;
    if (yx == DAT_01012060)
        return false;
    V3 o1 = cStart.SubtractIntoVector(aStart);
    float k1 = o1.x * es.y - o1.y * es.x;
    float ox = k1 / yx;
    if (ox < DAT_01012060 || ox > 1.0)
        return false;
    float nB = o1.x * gt.y - o1.y * gt.x;
    ox = nB / yx;
    if (out)
        *out = aStart.FUN_00439e90(ns6b::FUN_004a3760(ox, es));
    return true;
}

// Members follow the constructor's verified 0x04, 0x14 and 0x1ff4 layout.
struct FUN_00982610_Type
{
    unsigned unk00, unk04, unk08, unk0c;
    ~FUN_00982610_Type();
};
namespace B391 {
struct FUN_00483710
{

    int unk0000, unk0004, unk0008, unk000C, unk0010, unk0014, unk0018, unk001C;
    int unk0020, unk0024, unk0028, unk002C, unk0030, unk0034, unk0038, unk003C;
    int unk0040, unk0044, unk0048, unk004C, unk0050, unk0054, unk0058, unk005C;
    int unk0060, unk0064, unk0068, unk006C, unk0070, unk0074, unk0078, unk007C;
    int unk0080, unk0084, unk0088, unk008C, unk0090, unk0094, unk0098, unk009C;
    int unk00A0, unk00A4, unk00A8, unk00AC, unk00B0, unk00B4, unk00B8, unk00BC;
    int unk00C0, unk00C4, unk00C8, unk00CC, unk00D0, unk00D4, unk00D8, unk00DC;
    int unk00E0, unk00E4, unk00E8, unk00EC, unk00F0, unk00F4, unk00F8, unk00FC;
    int unk0100, unk0104, unk0108, unk010C, unk0110, unk0114, unk0118, unk011C;
    int unk0120, unk0124, unk0128, unk012C, unk0130, unk0134, unk0138, unk013C;
    int unk0140, unk0144, unk0148, unk014C, unk0150, unk0154, unk0158, unk015C;
    int unk0160, unk0164, unk0168, unk016C, unk0170, unk0174, unk0178, unk017C;
    int unk0180, unk0184, unk0188, unk018C, unk0190, unk0194, unk0198, unk019C;
    int unk01A0, unk01A4, unk01A8, unk01AC, unk01B0, unk01B4, unk01B8, unk01BC;
    int unk01C0, unk01C4, unk01C8, unk01CC, unk01D0, unk01D4, unk01D8, unk01DC;
    int unk01E0, unk01E4, unk01E8, unk01EC, unk01F0, unk01F4, unk01F8, unk01FC;
    int unk0200, unk0204, unk0208, unk020C, unk0210, unk0214, unk0218, unk021C;
    int unk0220, unk0224, unk0228, unk022C, unk0230, unk0234, unk0238, unk023C;
    int unk0240, unk0244, unk0248, unk024C, unk0250, unk0254, unk0258, unk025C;
    int unk0260, unk0264, unk0268, unk026C, unk0270, unk0274, unk0278, unk027C;
    int unk0280, unk0284, unk0288, unk028C, unk0290, unk0294, unk0298, unk029C;
    int unk02A0, unk02A4, unk02A8, unk02AC, unk02B0, unk02B4, unk02B8, unk02BC;
    int unk02C0, unk02C4, unk02C8, unk02CC, unk02D0, unk02D4, unk02D8, unk02DC;
    int unk02E0, unk02E4, unk02E8, unk02EC, unk02F0, unk02F4, unk02F8, unk02FC;
    int unk0300, unk0304, unk0308, unk030C, unk0310, unk0314, unk0318, unk031C;
    int unk0320, unk0324, unk0328, unk032C, unk0330, unk0334, unk0338, unk033C;
    int unk0340, unk0344, unk0348, unk034C, unk0350, unk0354, unk0358, unk035C;
    int unk0360, unk0364, unk0368, unk036C, unk0370, unk0374, unk0378, unk037C;
    int unk0380, unk0384, unk0388, unk038C, unk0390, unk0394, unk0398, unk039C;
    int unk03A0, unk03A4, unk03A8, unk03AC, unk03B0, unk03B4, unk03B8, unk03BC;
    int unk03C0, unk03C4, unk03C8, unk03CC, unk03D0, unk03D4, unk03D8, unk03DC;
    int unk03E0, unk03E4, unk03E8, unk03EC, unk03F0, unk03F4, unk03F8, unk03FC;
    int unk0400, unk0404, unk0408, unk040C, unk0410, unk0414, unk0418, unk041C;
    int unk0420, unk0424, unk0428, unk042C, unk0430, unk0434, unk0438, unk043C;
    int unk0440, unk0444, unk0448, unk044C, unk0450, unk0454, unk0458, unk045C;
    int unk0460, unk0464, unk0468, unk046C, unk0470, unk0474, unk0478, unk047C;
    int unk0480, unk0484, unk0488, unk048C, unk0490, unk0494, unk0498, unk049C;
    int unk04A0, unk04A4, unk04A8, unk04AC, unk04B0, unk04B4, unk04B8, unk04BC;
    int unk04C0, unk04C4, unk04C8, unk04CC, unk04D0, unk04D4, unk04D8, unk04DC;
    int unk04E0, unk04E4, unk04E8, unk04EC, unk04F0, unk04F4, unk04F8, unk04FC;
    int unk0500, unk0504, unk0508, unk050C, unk0510, unk0514, unk0518, unk051C;
    int unk0520, unk0524, unk0528, unk052C, unk0530, unk0534, unk0538, unk053C;
    int unk0540, unk0544, unk0548, unk054C, unk0550, unk0554, unk0558, unk055C;
    int unk0560, unk0564, unk0568, unk056C, unk0570, unk0574, unk0578, unk057C;
    int unk0580, unk0584, unk0588, unk058C, unk0590, unk0594, unk0598, unk059C;
    int unk05A0, unk05A4, unk05A8, unk05AC, unk05B0, unk05B4, unk05B8, unk05BC;
    int unk05C0, unk05C4, unk05C8, unk05CC, unk05D0, unk05D4, unk05D8, unk05DC;
    int unk05E0, unk05E4, unk05E8, unk05EC, unk05F0, unk05F4, unk05F8, unk05FC;
    int unk0600, unk0604, unk0608, unk060C, unk0610, unk0614, unk0618, unk061C;
    int unk0620, unk0624, unk0628, unk062C, unk0630, unk0634, unk0638, unk063C;
    int unk0640, unk0644, unk0648, unk064C, unk0650, unk0654, unk0658, unk065C;
    int unk0660, unk0664, unk0668, unk066C, unk0670, unk0674, unk0678, unk067C;
    int unk0680, unk0684, unk0688, unk068C, unk0690, unk0694, unk0698, unk069C;
    int unk06A0, unk06A4, unk06A8, unk06AC, unk06B0, unk06B4, unk06B8, unk06BC;
    int unk06C0, unk06C4, unk06C8, unk06CC, unk06D0, unk06D4, unk06D8, unk06DC;
    int unk06E0, unk06E4, unk06E8, unk06EC, unk06F0, unk06F4, unk06F8, unk06FC;
    int unk0700, unk0704, unk0708, unk070C, unk0710, unk0714, unk0718, unk071C;
    int unk0720, unk0724, unk0728, unk072C, unk0730, unk0734, unk0738, unk073C;
    int unk0740, unk0744, unk0748, unk074C, unk0750, unk0754, unk0758, unk075C;
    int unk0760, unk0764, unk0768, unk076C, unk0770, unk0774, unk0778, unk077C;
    int unk0780, unk0784, unk0788, unk078C, unk0790, unk0794, unk0798, unk079C;
    int unk07A0, unk07A4, unk07A8, unk07AC, unk07B0, unk07B4, unk07B8, unk07BC;
    int unk07C0, unk07C4, unk07C8, unk07CC, unk07D0, unk07D4, unk07D8, unk07DC;
    int unk07E0, unk07E4, unk07E8, unk07EC, unk07F0, unk07F4, unk07F8, unk07FC;
    int unk0800, unk0804, unk0808, unk080C, unk0810, unk0814, unk0818, unk081C;
    int unk0820, unk0824, unk0828, unk082C, unk0830, unk0834, unk0838, unk083C;
    int unk0840, unk0844, unk0848, unk084C, unk0850, unk0854, unk0858, unk085C;
    int unk0860, unk0864, unk0868, unk086C, unk0870, unk0874, unk0878, unk087C;
    int unk0880, unk0884, unk0888, unk088C, unk0890, unk0894, unk0898, unk089C;
    int unk08A0, unk08A4, unk08A8, unk08AC, unk08B0, unk08B4, unk08B8, unk08BC;
    int unk08C0, unk08C4, unk08C8, unk08CC, unk08D0, unk08D4, unk08D8, unk08DC;
    int unk08E0, unk08E4, unk08E8, unk08EC, unk08F0, unk08F4, unk08F8, unk08FC;
    int unk0900, unk0904, unk0908, unk090C, unk0910, unk0914, unk0918, unk091C;
    int unk0920, unk0924, unk0928, unk092C, unk0930, unk0934, unk0938, unk093C;
    int unk0940, unk0944, unk0948, unk094C, unk0950, unk0954, unk0958, unk095C;
    int unk0960, unk0964, unk0968, unk096C, unk0970, unk0974, unk0978, unk097C;
    int unk0980, unk0984, unk0988, unk098C, unk0990, unk0994, unk0998, unk099C;
    int unk09A0, unk09A4, unk09A8, unk09AC, unk09B0, unk09B4, unk09B8, unk09BC;
    int unk09C0, unk09C4, unk09C8, unk09CC, unk09D0, unk09D4, unk09D8, unk09DC;
    int unk09E0, unk09E4, unk09E8, unk09EC, unk09F0, unk09F4, unk09F8, unk09FC;
    int unk0A00, unk0A04, unk0A08, unk0A0C, unk0A10, unk0A14, unk0A18, unk0A1C;
    int unk0A20, unk0A24, unk0A28, unk0A2C, unk0A30, unk0A34, unk0A38, unk0A3C;
    int unk0A40, unk0A44, unk0A48, unk0A4C, unk0A50, unk0A54, unk0A58, unk0A5C;
    int unk0A60, unk0A64, unk0A68, unk0A6C, unk0A70, unk0A74, unk0A78, unk0A7C;
    int unk0A80, unk0A84, unk0A88, unk0A8C, unk0A90, unk0A94, unk0A98, unk0A9C;
    int unk0AA0, unk0AA4, unk0AA8, unk0AAC, unk0AB0, unk0AB4, unk0AB8, unk0ABC;
    int unk0AC0, unk0AC4, unk0AC8, unk0ACC, unk0AD0, unk0AD4, unk0AD8, unk0ADC;
    int unk0AE0, unk0AE4, unk0AE8, unk0AEC, unk0AF0, unk0AF4, unk0AF8, unk0AFC;
    int unk0B00, unk0B04, unk0B08, unk0B0C, unk0B10, unk0B14, unk0B18, unk0B1C;
    int unk0B20, unk0B24, unk0B28, unk0B2C, unk0B30, unk0B34, unk0B38, unk0B3C;
    int unk0B40, unk0B44, unk0B48, unk0B4C, unk0B50, unk0B54, unk0B58, unk0B5C;
    int unk0B60, unk0B64, unk0B68, unk0B6C, unk0B70, unk0B74, unk0B78, unk0B7C;
    int unk0B80, unk0B84, unk0B88, unk0B8C, unk0B90, unk0B94, unk0B98, unk0B9C;
    int unk0BA0, unk0BA4, unk0BA8, unk0BAC, unk0BB0, unk0BB4, unk0BB8, unk0BBC;
    int unk0BC0, unk0BC4, unk0BC8, unk0BCC, unk0BD0, unk0BD4, unk0BD8, unk0BDC;
    int unk0BE0, unk0BE4, unk0BE8, unk0BEC, unk0BF0, unk0BF4, unk0BF8, unk0BFC;
    int unk0C00, unk0C04, unk0C08, unk0C0C, unk0C10, unk0C14, unk0C18, unk0C1C;
    int unk0C20, unk0C24, unk0C28, unk0C2C, unk0C30, unk0C34, unk0C38, unk0C3C;
    int unk0C40, unk0C44, unk0C48, unk0C4C, unk0C50, unk0C54, unk0C58, unk0C5C;
    int unk0C60, unk0C64, unk0C68, unk0C6C, unk0C70, unk0C74, unk0C78, unk0C7C;
    int unk0C80, unk0C84, unk0C88, unk0C8C, unk0C90, unk0C94, unk0C98, unk0C9C;
    int unk0CA0, unk0CA4, unk0CA8, unk0CAC, unk0CB0, unk0CB4, unk0CB8, unk0CBC;
    int unk0CC0, unk0CC4, unk0CC8, unk0CCC, unk0CD0, unk0CD4, unk0CD8, unk0CDC;
    int unk0CE0, unk0CE4, unk0CE8, unk0CEC, unk0CF0, unk0CF4, unk0CF8, unk0CFC;
    int unk0D00, unk0D04, unk0D08, unk0D0C, unk0D10, unk0D14, unk0D18, unk0D1C;
    int unk0D20, unk0D24, unk0D28, unk0D2C, unk0D30, unk0D34, unk0D38, unk0D3C;
    int unk0D40, unk0D44, unk0D48, unk0D4C, unk0D50, unk0D54, unk0D58, unk0D5C;
    int unk0D60, unk0D64, unk0D68, unk0D6C, unk0D70, unk0D74, unk0D78, unk0D7C;
    int unk0D80, unk0D84, unk0D88, unk0D8C, unk0D90, unk0D94, unk0D98, unk0D9C;
    int unk0DA0, unk0DA4, unk0DA8, unk0DAC, unk0DB0, unk0DB4, unk0DB8, unk0DBC;
    int unk0DC0, unk0DC4, unk0DC8, unk0DCC, unk0DD0, unk0DD4, unk0DD8, unk0DDC;
    int unk0DE0, unk0DE4, unk0DE8, unk0DEC, unk0DF0, unk0DF4, unk0DF8, unk0DFC;
    int unk0E00, unk0E04, unk0E08, unk0E0C, unk0E10, unk0E14, unk0E18, unk0E1C;
    int unk0E20, unk0E24, unk0E28, unk0E2C, unk0E30, unk0E34, unk0E38, unk0E3C;
    int unk0E40, unk0E44, unk0E48, unk0E4C, unk0E50, unk0E54, unk0E58, unk0E5C;
    int unk0E60, unk0E64, unk0E68, unk0E6C, unk0E70, unk0E74, unk0E78, unk0E7C;
    int unk0E80, unk0E84, unk0E88, unk0E8C, unk0E90, unk0E94, unk0E98, unk0E9C;
    int unk0EA0, unk0EA4, unk0EA8, unk0EAC, unk0EB0, unk0EB4, unk0EB8, unk0EBC;
    int unk0EC0, unk0EC4, unk0EC8, unk0ECC, unk0ED0, unk0ED4, unk0ED8, unk0EDC;
    int unk0EE0, unk0EE4, unk0EE8, unk0EEC, unk0EF0, unk0EF4, unk0EF8, unk0EFC;
    int unk0F00, unk0F04, unk0F08, unk0F0C, unk0F10, unk0F14, unk0F18, unk0F1C;
    int unk0F20, unk0F24, unk0F28, unk0F2C, unk0F30, unk0F34, unk0F38, unk0F3C;
    int unk0F40, unk0F44, unk0F48, unk0F4C, unk0F50, unk0F54, unk0F58, unk0F5C;
    int unk0F60, unk0F64, unk0F68, unk0F6C, unk0F70, unk0F74, unk0F78, unk0F7C;
    int unk0F80, unk0F84, unk0F88, unk0F8C, unk0F90, unk0F94, unk0F98, unk0F9C;
    int unk0FA0, unk0FA4, unk0FA8, unk0FAC, unk0FB0, unk0FB4, unk0FB8, unk0FBC;
    int unk0FC0, unk0FC4, unk0FC8, unk0FCC, unk0FD0, unk0FD4, unk0FD8, unk0FDC;
    int unk0FE0, unk0FE4, unk0FE8, unk0FEC, unk0FF0, unk0FF4, unk0FF8, unk0FFC;
    int unk1000, unk1004, unk1008, unk100C, unk1010, unk1014, unk1018, unk101C;
    int unk1020, unk1024, unk1028, unk102C, unk1030, unk1034, unk1038, unk103C;
    int unk1040, unk1044, unk1048, unk104C, unk1050, unk1054, unk1058, unk105C;
    int unk1060, unk1064, unk1068, unk106C, unk1070, unk1074, unk1078, unk107C;
    int unk1080, unk1084, unk1088, unk108C, unk1090, unk1094, unk1098, unk109C;
    int unk10A0, unk10A4, unk10A8, unk10AC, unk10B0, unk10B4, unk10B8, unk10BC;
    int unk10C0, unk10C4, unk10C8, unk10CC, unk10D0, unk10D4, unk10D8, unk10DC;
    int unk10E0, unk10E4, unk10E8, unk10EC, unk10F0, unk10F4, unk10F8, unk10FC;
    int unk1100, unk1104, unk1108, unk110C, unk1110, unk1114, unk1118, unk111C;
    int unk1120, unk1124, unk1128, unk112C, unk1130, unk1134, unk1138, unk113C;
    int unk1140, unk1144, unk1148, unk114C, unk1150, unk1154, unk1158, unk115C;
    int unk1160, unk1164, unk1168, unk116C, unk1170, unk1174, unk1178, unk117C;
    int unk1180, unk1184, unk1188, unk118C, unk1190, unk1194, unk1198, unk119C;
    int unk11A0, unk11A4, unk11A8, unk11AC, unk11B0, unk11B4, unk11B8, unk11BC;
    int unk11C0, unk11C4, unk11C8, unk11CC, unk11D0, unk11D4, unk11D8, unk11DC;
    int unk11E0, unk11E4, unk11E8, unk11EC, unk11F0, unk11F4, unk11F8, unk11FC;
    int unk1200, unk1204, unk1208, unk120C, unk1210, unk1214, unk1218, unk121C;
    int unk1220, unk1224, unk1228, unk122C, unk1230, unk1234, unk1238, unk123C;
    int unk1240, unk1244, unk1248, unk124C, unk1250, unk1254, unk1258, unk125C;
    int unk1260, unk1264, unk1268, unk126C, unk1270, unk1274, unk1278, unk127C;
    int unk1280, unk1284, unk1288, unk128C, unk1290, unk1294, unk1298, unk129C;
    int unk12A0, unk12A4, unk12A8, unk12AC, unk12B0, unk12B4, unk12B8, unk12BC;
    int unk12C0, unk12C4, unk12C8, unk12CC, unk12D0, unk12D4, unk12D8, unk12DC;
    int unk12E0, unk12E4, unk12E8, unk12EC, unk12F0, unk12F4, unk12F8, unk12FC;
    int unk1300, unk1304, unk1308, unk130C, unk1310, unk1314, unk1318, unk131C;
    int unk1320, unk1324, unk1328, unk132C, unk1330, unk1334, unk1338, unk133C;
    int unk1340, unk1344, unk1348, unk134C, unk1350, unk1354, unk1358, unk135C;
    int unk1360, unk1364, unk1368, unk136C, unk1370, unk1374, unk1378, unk137C;
    int unk1380, unk1384, unk1388, unk138C, unk1390, unk1394, unk1398, unk139C;
    int unk13A0, unk13A4, unk13A8, unk13AC, unk13B0, unk13B4, unk13B8, unk13BC;
    int unk13C0, unk13C4, unk13C8, unk13CC, unk13D0, unk13D4, unk13D8, unk13DC;
    int unk13E0, unk13E4, unk13E8, unk13EC, unk13F0, unk13F4, unk13F8, unk13FC;
    int unk1400, unk1404, unk1408, unk140C, unk1410, unk1414, unk1418, unk141C;
    int unk1420, unk1424, unk1428, unk142C, unk1430, unk1434, unk1438, unk143C;
    int unk1440, unk1444, unk1448, unk144C, unk1450, unk1454, unk1458, unk145C;
    int unk1460, unk1464, unk1468, unk146C, unk1470, unk1474, unk1478, unk147C;
    int unk1480, unk1484, unk1488, unk148C, unk1490, unk1494, unk1498, unk149C;
    int unk14A0, unk14A4, unk14A8, unk14AC, unk14B0, unk14B4, unk14B8, unk14BC;
    int unk14C0, unk14C4, unk14C8, unk14CC, unk14D0, unk14D4, unk14D8, unk14DC;
    int unk14E0, unk14E4, unk14E8, unk14EC, unk14F0, unk14F4, unk14F8, unk14FC;
    int unk1500, unk1504, unk1508, unk150C, unk1510, unk1514, unk1518, unk151C;
    int unk1520, unk1524, unk1528, unk152C, unk1530, unk1534, unk1538, unk153C;
    int unk1540, unk1544, unk1548, unk154C, unk1550, unk1554, unk1558, unk155C;
    int unk1560, unk1564, unk1568, unk156C, unk1570, unk1574, unk1578, unk157C;
    int unk1580, unk1584, unk1588, unk158C, unk1590, unk1594, unk1598, unk159C;
    int unk15A0, unk15A4, unk15A8, unk15AC, unk15B0, unk15B4, unk15B8, unk15BC;
    int unk15C0, unk15C4, unk15C8, unk15CC, unk15D0, unk15D4, unk15D8, unk15DC;
    int unk15E0, unk15E4, unk15E8, unk15EC, unk15F0, unk15F4, unk15F8, unk15FC;
    int unk1600, unk1604, unk1608, unk160C, unk1610, unk1614, unk1618, unk161C;
    int unk1620, unk1624, unk1628, unk162C, unk1630, unk1634, unk1638, unk163C;
    int unk1640, unk1644, unk1648, unk164C, unk1650, unk1654, unk1658, unk165C;
    int unk1660, unk1664, unk1668, unk166C, unk1670, unk1674, unk1678, unk167C;
    int unk1680, unk1684, unk1688, unk168C, unk1690, unk1694, unk1698, unk169C;
    int unk16A0, unk16A4, unk16A8, unk16AC, unk16B0, unk16B4, unk16B8, unk16BC;
    int unk16C0, unk16C4, unk16C8, unk16CC, unk16D0, unk16D4, unk16D8, unk16DC;
    int unk16E0, unk16E4, unk16E8, unk16EC, unk16F0, unk16F4, unk16F8, unk16FC;
    int unk1700, unk1704, unk1708, unk170C, unk1710, unk1714, unk1718, unk171C;
    int unk1720, unk1724, unk1728, unk172C, unk1730, unk1734, unk1738, unk173C;
    int unk1740, unk1744, unk1748, unk174C, unk1750, unk1754, unk1758, unk175C;
    int unk1760, unk1764, unk1768, unk176C, unk1770, unk1774, unk1778, unk177C;
    int unk1780, unk1784, unk1788, unk178C, unk1790, unk1794, unk1798, unk179C;
    int unk17A0, unk17A4, unk17A8, unk17AC, unk17B0, unk17B4, unk17B8, unk17BC;
    int unk17C0, unk17C4, unk17C8, unk17CC, unk17D0, unk17D4, unk17D8, unk17DC;
    int unk17E0, unk17E4, unk17E8, unk17EC, unk17F0, unk17F4, unk17F8, unk17FC;
    int unk1800, unk1804, unk1808, unk180C, unk1810, unk1814, unk1818, unk181C;
    int unk1820, unk1824, unk1828, unk182C, unk1830, unk1834, unk1838, unk183C;
    int unk1840, unk1844, unk1848, unk184C, unk1850, unk1854, unk1858, unk185C;
    int unk1860, unk1864, unk1868, unk186C, unk1870, unk1874, unk1878, unk187C;
    int unk1880, unk1884, unk1888, unk188C, unk1890, unk1894, unk1898, unk189C;
    int unk18A0, unk18A4, unk18A8, unk18AC, unk18B0, unk18B4, unk18B8, unk18BC;
    int unk18C0, unk18C4, unk18C8, unk18CC, unk18D0, unk18D4, unk18D8, unk18DC;
    int unk18E0, unk18E4, unk18E8, unk18EC, unk18F0, unk18F4, unk18F8, unk18FC;
    int unk1900, unk1904, unk1908, unk190C, unk1910, unk1914, unk1918, unk191C;
    int unk1920, unk1924, unk1928, unk192C, unk1930, unk1934, unk1938, unk193C;
    int unk1940, unk1944, unk1948, unk194C, unk1950, unk1954, unk1958, unk195C;
    int unk1960, unk1964, unk1968, unk196C, unk1970, unk1974, unk1978, unk197C;
    int unk1980, unk1984, unk1988, unk198C, unk1990, unk1994, unk1998, unk199C;
    int unk19A0, unk19A4, unk19A8, unk19AC, unk19B0, unk19B4, unk19B8, unk19BC;
    int unk19C0, unk19C4, unk19C8, unk19CC, unk19D0, unk19D4, unk19D8, unk19DC;
    int unk19E0, unk19E4, unk19E8, unk19EC, unk19F0, unk19F4, unk19F8, unk19FC;
    int unk1A00, unk1A04, unk1A08, unk1A0C, unk1A10, unk1A14, unk1A18, unk1A1C;
    int unk1A20, unk1A24, unk1A28, unk1A2C, unk1A30, unk1A34, unk1A38, unk1A3C;
    int unk1A40, unk1A44, unk1A48, unk1A4C, unk1A50, unk1A54, unk1A58, unk1A5C;
    int unk1A60, unk1A64, unk1A68, unk1A6C, unk1A70, unk1A74, unk1A78, unk1A7C;
    int unk1A80, unk1A84, unk1A88, unk1A8C, unk1A90, unk1A94, unk1A98, unk1A9C;
    int unk1AA0, unk1AA4, unk1AA8, unk1AAC, unk1AB0, unk1AB4, unk1AB8, unk1ABC;
    int unk1AC0, unk1AC4, unk1AC8, unk1ACC, unk1AD0, unk1AD4, unk1AD8, unk1ADC;
    int unk1AE0, unk1AE4, unk1AE8, unk1AEC, unk1AF0, unk1AF4, unk1AF8, unk1AFC;
    int unk1B00, unk1B04, unk1B08, unk1B0C, unk1B10, unk1B14, unk1B18, unk1B1C;
    int unk1B20, unk1B24, unk1B28, unk1B2C, unk1B30, unk1B34, unk1B38, unk1B3C;
    int unk1B40, unk1B44, unk1B48, unk1B4C, unk1B50, unk1B54, unk1B58, unk1B5C;
    int unk1B60, unk1B64, unk1B68, unk1B6C, unk1B70, unk1B74, unk1B78, unk1B7C;
    int unk1B80, unk1B84, unk1B88, unk1B8C, unk1B90, unk1B94, unk1B98, unk1B9C;
    int unk1BA0, unk1BA4, unk1BA8, unk1BAC, unk1BB0, unk1BB4, unk1BB8, unk1BBC;
    int unk1BC0, unk1BC4, unk1BC8, unk1BCC, unk1BD0, unk1BD4, unk1BD8, unk1BDC;
    int unk1BE0, unk1BE4, unk1BE8, unk1BEC, unk1BF0, unk1BF4, unk1BF8, unk1BFC;
    int unk1C00, unk1C04, unk1C08, unk1C0C, unk1C10, unk1C14, unk1C18, unk1C1C;
    int unk1C20, unk1C24, unk1C28, unk1C2C, unk1C30, unk1C34, unk1C38, unk1C3C;
    int unk1C40, unk1C44, unk1C48, unk1C4C, unk1C50, unk1C54, unk1C58, unk1C5C;
    int unk1C60, unk1C64, unk1C68, unk1C6C, unk1C70, unk1C74, unk1C78, unk1C7C;
    int unk1C80, unk1C84, unk1C88, unk1C8C, unk1C90, unk1C94, unk1C98, unk1C9C;
    int unk1CA0, unk1CA4, unk1CA8, unk1CAC, unk1CB0, unk1CB4, unk1CB8, unk1CBC;
    int unk1CC0, unk1CC4, unk1CC8, unk1CCC, unk1CD0, unk1CD4, unk1CD8, unk1CDC;
    int unk1CE0, unk1CE4, unk1CE8, unk1CEC, unk1CF0, unk1CF4, unk1CF8, unk1CFC;
    int unk1D00, unk1D04, unk1D08, unk1D0C, unk1D10, unk1D14, unk1D18, unk1D1C;
    int unk1D20, unk1D24, unk1D28, unk1D2C, unk1D30, unk1D34, unk1D38, unk1D3C;
    int unk1D40, unk1D44, unk1D48, unk1D4C, unk1D50, unk1D54, unk1D58, unk1D5C;
    int unk1D60, unk1D64, unk1D68, unk1D6C, unk1D70, unk1D74, unk1D78, unk1D7C;
    int unk1D80, unk1D84, unk1D88, unk1D8C, unk1D90, unk1D94, unk1D98, unk1D9C;
    int unk1DA0, unk1DA4, unk1DA8, unk1DAC, unk1DB0, unk1DB4, unk1DB8, unk1DBC;
    int unk1DC0, unk1DC4, unk1DC8, unk1DCC, unk1DD0, unk1DD4, unk1DD8, unk1DDC;
    int unk1DE0, unk1DE4, unk1DE8, unk1DEC, unk1DF0, unk1DF4, unk1DF8, unk1DFC;
    int unk1E00, unk1E04, unk1E08, unk1E0C, unk1E10, unk1E14, unk1E18, unk1E1C;
    int unk1E20, unk1E24, unk1E28, unk1E2C, unk1E30, unk1E34, unk1E38, unk1E3C;
    int unk1E40, unk1E44, unk1E48, unk1E4C, unk1E50, unk1E54, unk1E58, unk1E5C;
    int unk1E60, unk1E64, unk1E68, unk1E6C, unk1E70, unk1E74, unk1E78, unk1E7C;
    int unk1E80, unk1E84, unk1E88, unk1E8C, unk1E90, unk1E94, unk1E98, unk1E9C;
    int unk1EA0, unk1EA4, unk1EA8, unk1EAC, unk1EB0, unk1EB4, unk1EB8, unk1EBC;
    int unk1EC0, unk1EC4, unk1EC8, unk1ECC, unk1ED0, unk1ED4, unk1ED8, unk1EDC;
    int unk1EE0, unk1EE4, unk1EE8, unk1EEC, unk1EF0, unk1EF4, unk1EF8, unk1EFC;
    int unk1F00, unk1F04, unk1F08, unk1F0C, unk1F10, unk1F14, unk1F18, unk1F1C;
    int unk1F20, unk1F24, unk1F28, unk1F2C, unk1F30, unk1F34, unk1F38, unk1F3C;
    int unk1F40, unk1F44, unk1F48, unk1F4C, unk1F50, unk1F54, unk1F58, unk1F5C;
    int unk1F60, unk1F64, unk1F68, unk1F6C, unk1F70, unk1F74, unk1F78, unk1F7C;
    int unk1F80, unk1F84, unk1F88, unk1F8C, unk1F90, unk1F94, unk1F98, unk1F9C;
    int unk1FA0, unk1FA4, unk1FA8, unk1FAC, unk1FB0, unk1FB4, unk1FB8, unk1FBC;
    int unk1FC0, unk1FC4, unk1FC8, unk1FCC, unk1FD0, unk1FD4, unk1FD8, unk1FDC;

    ~FUN_00483710()
    {}
};
}
namespace C391 {
struct FUN_00483710
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

    ~FUN_00483710()
    {}
};
}
namespace Task391 {
struct FUN_006a15b0
{
    virtual ~FUN_006a15b0();
    FUN_00982610_Type resource;
    B391::FUN_00483710 searchState;
    C391::FUN_00483710 searchResult;
    unsigned unk2048, unk204c, unk2050;
    bool unk2054;
};
// @fnv 0x006a15b0
FUN_006a15b0::~FUN_006a15b0()
{}
}

struct FUN_00b00a00_Interface
{
    virtual void Unknown0();
    virtual void Unknown4();
    virtual void Unknown8();
    virtual bool TestValue(int value);
};

FUN_00b00a00_Interface* FUN_00b00a00();
int FUN_0040fc90();

class FUN_006a1630_class : public FUN_006a1cf0_shell
{
  public:
    bool CopyNodeListToArrays(PathSearchNode* head, FUN_006b3cb0_arg2* a2, FUN_006b3cb0_arg3* a3);
    bool ProcessSearchNode(FUN_006b3cb0_arg2* param_2, FUN_006b3cb0_arg3* param_3, bool useBestNode);
};

// Sets bYield from a test value, picks a node from FUN_006a1cf0 or pBestNode, processes it via CopyNodeListToArrays, and returns whether the first node was used.
// @fnv 0x006a1630
bool FUN_006a1630_class::ProcessSearchNode(FUN_006b3cb0_arg2* param_2, FUN_006b3cb0_arg3* param_3, bool useBestNode)
{
    bYield = FUN_00b00a00()->TestValue(FUN_0040fc90());

    PathSearchNode* selectedNode;
    bool result2;
    PathSearchNode* currentNode = AStarSearch_NavMeshPOVSearchNode_NavMeshPOVSearchLink_BuildPath();
    if (currentNode != 0)
    {
        result2 = true;
        selectedNode = currentNode;
    }
    else if (useBestNode)
    {
        result2 = false;
        selectedNode = pBestNode;
    }
    else
    {
        result2 = false;
        selectedNode = 0;
    }

    if (selectedNode != 0)
        CopyNodeListToArrays(selectedNode, param_2, param_3);
    return result2;
}

// RTTI establishes NavMeshSearchHide -> NavMeshSearch -> AStarSearch.
// The base extent ends where the derived request pointer begins at0x20a4.

namespace Point441 {
struct FUN_006815c0
{
    float x, y, z;
    FUN_006815c0()
    {}
};
}
struct Location441
{
    unsigned unk00, unk04, unk08, unk0c, unk10;
};
struct FUN_006a9cb0 : NavMeshSearch
{
    void* request;
    Location441 location;
    Point441::FUN_006815c0 hidePosition;
    float hideDistance;
    Point441::FUN_006815c0 targetPosition;
    virtual ~FUN_006a9cb0();
    FUN_006a9cb0();
};
// Initializes the hide request pointer to null.
// @fnv 0x006a9cb0
FUN_006a9cb0::FUN_006a9cb0()
{
    request = 0;
}



class NavSearchPoint
{
  public:
    NavSearchPoint();
    float x;
    float y;
    float z;
};




class FUN_006ac0e0 : public NavMeshSearch
{
  public:
    FUN_006ac0e0();
    PathingLocation m_kPathingLocation;
    NavSearchPoint m_kRayStart;
    NavSearchPoint m_kRayEnd;
    NavSearchPoint m_goal;
};

void NavMeshSearch::vf()
{}
PathingLocation::PathingLocation()
{}
NavSearchPoint::NavSearchPoint()
{}

// @fnv 0x006ac0e0
FUN_006ac0e0::FUN_006ac0e0()
{}

namespace fnv_006b8f40 {
struct FUN_006b8f40_Holder
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual unsigned char v3(int arg);
};

FUN_006b8f40_Holder* __cdecl FUN_00b00a00();
int __cdecl FUN_0040fc90();

struct FUN_006b8f40_cls
{
    int unk0000, unk0004, unk0008, unk000C, unk0010, unk0014, unk0018, unk001C, unk0020, unk0024, unk0028, unk002C,
        unk0030, unk0034, unk0038, unk003C;
    int unk0040, unk0044, unk0048, unk004C, unk0050, unk0054, unk0058, unk005C, unk0060, unk0064, unk0068, unk006C,
        unk0070, unk0074, unk0078, unk007C;
    int unk0080, unk0084, unk0088, unk008C, unk0090, unk0094, unk0098, unk009C, unk00A0, unk00A4, unk00A8, unk00AC,
        unk00B0, unk00B4, unk00B8, unk00BC;
    int unk00C0, unk00C4, unk00C8, unk00CC, unk00D0, unk00D4, unk00D8, unk00DC, unk00E0, unk00E4, unk00E8, unk00EC,
        unk00F0, unk00F4, unk00F8, unk00FC;
    int unk0100, unk0104, unk0108, unk010C, unk0110, unk0114, unk0118, unk011C, unk0120, unk0124, unk0128, unk012C,
        unk0130, unk0134, unk0138, unk013C;
    int unk0140, unk0144, unk0148, unk014C, unk0150, unk0154, unk0158, unk015C, unk0160, unk0164, unk0168, unk016C,
        unk0170, unk0174, unk0178, unk017C;
    int unk0180, unk0184, unk0188, unk018C, unk0190, unk0194, unk0198, unk019C, unk01A0, unk01A4, unk01A8, unk01AC,
        unk01B0, unk01B4, unk01B8, unk01BC;
    int unk01C0, unk01C4, unk01C8, unk01CC, unk01D0, unk01D4, unk01D8, unk01DC, unk01E0, unk01E4, unk01E8, unk01EC,
        unk01F0, unk01F4, unk01F8, unk01FC;
    int unk0200, unk0204, unk0208, unk020C, unk0210, unk0214, unk0218, unk021C, unk0220, unk0224, unk0228, unk022C,
        unk0230, unk0234, unk0238, unk023C;
    int unk0240, unk0244, unk0248, unk024C, unk0250, unk0254, unk0258, unk025C, unk0260, unk0264, unk0268, unk026C,
        unk0270, unk0274, unk0278, unk027C;
    int unk0280, unk0284, unk0288, unk028C, unk0290, unk0294, unk0298, unk029C, unk02A0, unk02A4, unk02A8, unk02AC,
        unk02B0, unk02B4, unk02B8, unk02BC;
    int unk02C0, unk02C4, unk02C8, unk02CC, unk02D0, unk02D4, unk02D8, unk02DC, unk02E0, unk02E4, unk02E8, unk02EC,
        unk02F0, unk02F4, unk02F8, unk02FC;
    int unk0300, unk0304, unk0308, unk030C, unk0310, unk0314, unk0318, unk031C, unk0320, unk0324, unk0328, unk032C,
        unk0330, unk0334, unk0338, unk033C;
    int unk0340, unk0344, unk0348, unk034C, unk0350, unk0354, unk0358, unk035C, unk0360, unk0364, unk0368, unk036C,
        unk0370, unk0374, unk0378, unk037C;
    int unk0380, unk0384, unk0388, unk038C, unk0390, unk0394, unk0398, unk039C, unk03A0, unk03A4, unk03A8, unk03AC,
        unk03B0, unk03B4, unk03B8, unk03BC;
    int unk03C0, unk03C4, unk03C8, unk03CC, unk03D0, unk03D4, unk03D8, unk03DC, unk03E0, unk03E4, unk03E8, unk03EC,
        unk03F0, unk03F4, unk03F8, unk03FC;
    int unk0400, unk0404, unk0408, unk040C, unk0410, unk0414, unk0418, unk041C, unk0420, unk0424, unk0428, unk042C,
        unk0430, unk0434, unk0438, unk043C;
    int unk0440, unk0444, unk0448, unk044C, unk0450, unk0454, unk0458, unk045C, unk0460, unk0464, unk0468, unk046C,
        unk0470, unk0474, unk0478, unk047C;
    int unk0480, unk0484, unk0488, unk048C, unk0490, unk0494, unk0498, unk049C, unk04A0, unk04A4, unk04A8, unk04AC,
        unk04B0, unk04B4, unk04B8, unk04BC;
    int unk04C0, unk04C4, unk04C8, unk04CC, unk04D0, unk04D4, unk04D8, unk04DC, unk04E0, unk04E4, unk04E8, unk04EC,
        unk04F0, unk04F4, unk04F8, unk04FC;
    int unk0500, unk0504, unk0508, unk050C, unk0510, unk0514, unk0518, unk051C, unk0520, unk0524, unk0528, unk052C,
        unk0530, unk0534, unk0538, unk053C;
    int unk0540, unk0544, unk0548, unk054C, unk0550, unk0554, unk0558, unk055C, unk0560, unk0564, unk0568, unk056C,
        unk0570, unk0574, unk0578, unk057C;
    int unk0580, unk0584, unk0588, unk058C, unk0590, unk0594, unk0598, unk059C, unk05A0, unk05A4, unk05A8, unk05AC,
        unk05B0, unk05B4, unk05B8, unk05BC;
    int unk05C0, unk05C4, unk05C8, unk05CC, unk05D0, unk05D4, unk05D8, unk05DC, unk05E0, unk05E4, unk05E8, unk05EC,
        unk05F0, unk05F4, unk05F8, unk05FC;
    int unk0600, unk0604, unk0608, unk060C, unk0610, unk0614, unk0618, unk061C, unk0620, unk0624, unk0628, unk062C,
        unk0630, unk0634, unk0638, unk063C;
    int unk0640, unk0644, unk0648, unk064C, unk0650, unk0654, unk0658, unk065C, unk0660, unk0664, unk0668, unk066C,
        unk0670, unk0674, unk0678, unk067C;
    int unk0680, unk0684, unk0688, unk068C, unk0690, unk0694, unk0698, unk069C, unk06A0, unk06A4, unk06A8, unk06AC,
        unk06B0, unk06B4, unk06B8, unk06BC;
    int unk06C0, unk06C4, unk06C8, unk06CC, unk06D0, unk06D4, unk06D8, unk06DC, unk06E0, unk06E4, unk06E8, unk06EC,
        unk06F0, unk06F4, unk06F8, unk06FC;
    int unk0700, unk0704, unk0708, unk070C, unk0710, unk0714, unk0718, unk071C, unk0720, unk0724, unk0728, unk072C,
        unk0730, unk0734, unk0738, unk073C;
    int unk0740, unk0744, unk0748, unk074C, unk0750, unk0754, unk0758, unk075C, unk0760, unk0764, unk0768, unk076C,
        unk0770, unk0774, unk0778, unk077C;
    int unk0780, unk0784, unk0788, unk078C, unk0790, unk0794, unk0798, unk079C, unk07A0, unk07A4, unk07A8, unk07AC,
        unk07B0, unk07B4, unk07B8, unk07BC;
    int unk07C0, unk07C4, unk07C8, unk07CC, unk07D0, unk07D4, unk07D8, unk07DC, unk07E0, unk07E4, unk07E8, unk07EC,
        unk07F0, unk07F4, unk07F8, unk07FC;
    int unk0800, unk0804, unk0808, unk080C, unk0810, unk0814, unk0818, unk081C, unk0820, unk0824, unk0828, unk082C,
        unk0830, unk0834, unk0838, unk083C;
    int unk0840, unk0844, unk0848, unk084C, unk0850, unk0854, unk0858, unk085C, unk0860, unk0864, unk0868, unk086C,
        unk0870, unk0874, unk0878, unk087C;
    int unk0880, unk0884, unk0888, unk088C, unk0890, unk0894, unk0898, unk089C, unk08A0, unk08A4, unk08A8, unk08AC,
        unk08B0, unk08B4, unk08B8, unk08BC;
    int unk08C0, unk08C4, unk08C8, unk08CC, unk08D0, unk08D4, unk08D8, unk08DC, unk08E0, unk08E4, unk08E8, unk08EC,
        unk08F0, unk08F4, unk08F8, unk08FC;
    int unk0900, unk0904, unk0908, unk090C, unk0910, unk0914, unk0918, unk091C, unk0920, unk0924, unk0928, unk092C,
        unk0930, unk0934, unk0938, unk093C;
    int unk0940, unk0944, unk0948, unk094C, unk0950, unk0954, unk0958, unk095C, unk0960, unk0964, unk0968, unk096C,
        unk0970, unk0974, unk0978, unk097C;
    int unk0980, unk0984, unk0988, unk098C, unk0990, unk0994, unk0998, unk099C, unk09A0, unk09A4, unk09A8, unk09AC,
        unk09B0, unk09B4, unk09B8, unk09BC;
    int unk09C0, unk09C4, unk09C8, unk09CC, unk09D0, unk09D4, unk09D8, unk09DC, unk09E0, unk09E4, unk09E8, unk09EC,
        unk09F0, unk09F4, unk09F8, unk09FC;
    int unk0A00, unk0A04, unk0A08, unk0A0C, unk0A10, unk0A14, unk0A18, unk0A1C, unk0A20, unk0A24, unk0A28, unk0A2C,
        unk0A30, unk0A34, unk0A38, unk0A3C;
    int unk0A40, unk0A44, unk0A48, unk0A4C, unk0A50, unk0A54, unk0A58, unk0A5C, unk0A60, unk0A64, unk0A68, unk0A6C,
        unk0A70, unk0A74, unk0A78, unk0A7C;
    int unk0A80, unk0A84, unk0A88, unk0A8C, unk0A90, unk0A94, unk0A98, unk0A9C, unk0AA0, unk0AA4, unk0AA8, unk0AAC,
        unk0AB0, unk0AB4, unk0AB8, unk0ABC;
    int unk0AC0, unk0AC4, unk0AC8, unk0ACC, unk0AD0, unk0AD4, unk0AD8, unk0ADC, unk0AE0, unk0AE4, unk0AE8, unk0AEC,
        unk0AF0, unk0AF4, unk0AF8, unk0AFC;
    int unk0B00, unk0B04, unk0B08, unk0B0C, unk0B10, unk0B14, unk0B18, unk0B1C, unk0B20, unk0B24, unk0B28, unk0B2C,
        unk0B30, unk0B34, unk0B38, unk0B3C;
    int unk0B40, unk0B44, unk0B48, unk0B4C, unk0B50, unk0B54, unk0B58, unk0B5C, unk0B60, unk0B64, unk0B68, unk0B6C,
        unk0B70, unk0B74, unk0B78, unk0B7C;
    int unk0B80, unk0B84, unk0B88, unk0B8C, unk0B90, unk0B94, unk0B98, unk0B9C, unk0BA0, unk0BA4, unk0BA8, unk0BAC,
        unk0BB0, unk0BB4, unk0BB8, unk0BBC;
    int unk0BC0, unk0BC4, unk0BC8, unk0BCC, unk0BD0, unk0BD4, unk0BD8, unk0BDC, unk0BE0, unk0BE4, unk0BE8, unk0BEC,
        unk0BF0, unk0BF4, unk0BF8, unk0BFC;
    int unk0C00, unk0C04, unk0C08, unk0C0C, unk0C10, unk0C14, unk0C18, unk0C1C, unk0C20, unk0C24, unk0C28, unk0C2C,
        unk0C30, unk0C34, unk0C38, unk0C3C;
    int unk0C40, unk0C44, unk0C48, unk0C4C, unk0C50, unk0C54, unk0C58, unk0C5C, unk0C60, unk0C64, unk0C68, unk0C6C,
        unk0C70, unk0C74, unk0C78, unk0C7C;
    int unk0C80, unk0C84, unk0C88, unk0C8C, unk0C90, unk0C94, unk0C98, unk0C9C, unk0CA0, unk0CA4, unk0CA8, unk0CAC,
        unk0CB0, unk0CB4, unk0CB8, unk0CBC;
    int unk0CC0, unk0CC4, unk0CC8, unk0CCC, unk0CD0, unk0CD4, unk0CD8, unk0CDC, unk0CE0, unk0CE4, unk0CE8, unk0CEC,
        unk0CF0, unk0CF4, unk0CF8, unk0CFC;
    int unk0D00, unk0D04, unk0D08, unk0D0C, unk0D10, unk0D14, unk0D18, unk0D1C, unk0D20, unk0D24, unk0D28, unk0D2C,
        unk0D30, unk0D34, unk0D38, unk0D3C;
    int unk0D40, unk0D44, unk0D48, unk0D4C, unk0D50, unk0D54, unk0D58, unk0D5C, unk0D60, unk0D64, unk0D68, unk0D6C,
        unk0D70, unk0D74, unk0D78, unk0D7C;
    int unk0D80, unk0D84, unk0D88, unk0D8C, unk0D90, unk0D94, unk0D98, unk0D9C, unk0DA0, unk0DA4, unk0DA8, unk0DAC,
        unk0DB0, unk0DB4, unk0DB8, unk0DBC;
    int unk0DC0, unk0DC4, unk0DC8, unk0DCC, unk0DD0, unk0DD4, unk0DD8, unk0DDC, unk0DE0, unk0DE4, unk0DE8, unk0DEC,
        unk0DF0, unk0DF4, unk0DF8, unk0DFC;
    int unk0E00, unk0E04, unk0E08, unk0E0C, unk0E10, unk0E14, unk0E18, unk0E1C, unk0E20, unk0E24, unk0E28, unk0E2C,
        unk0E30, unk0E34, unk0E38, unk0E3C;
    int unk0E40, unk0E44, unk0E48, unk0E4C, unk0E50, unk0E54, unk0E58, unk0E5C, unk0E60, unk0E64, unk0E68, unk0E6C,
        unk0E70, unk0E74, unk0E78, unk0E7C;
    int unk0E80, unk0E84, unk0E88, unk0E8C, unk0E90, unk0E94, unk0E98, unk0E9C, unk0EA0, unk0EA4, unk0EA8, unk0EAC,
        unk0EB0, unk0EB4, unk0EB8, unk0EBC;
    int unk0EC0, unk0EC4, unk0EC8, unk0ECC, unk0ED0, unk0ED4, unk0ED8, unk0EDC, unk0EE0, unk0EE4, unk0EE8, unk0EEC,
        unk0EF0, unk0EF4, unk0EF8, unk0EFC;
    int unk0F00, unk0F04, unk0F08, unk0F0C, unk0F10, unk0F14, unk0F18, unk0F1C, unk0F20, unk0F24, unk0F28, unk0F2C,
        unk0F30, unk0F34, unk0F38, unk0F3C;
    int unk0F40, unk0F44, unk0F48, unk0F4C, unk0F50, unk0F54, unk0F58, unk0F5C, unk0F60, unk0F64, unk0F68, unk0F6C,
        unk0F70, unk0F74, unk0F78, unk0F7C;
    int unk0F80, unk0F84, unk0F88, unk0F8C, unk0F90, unk0F94, unk0F98, unk0F9C, unk0FA0, unk0FA4, unk0FA8, unk0FAC,
        unk0FB0, unk0FB4, unk0FB8, unk0FBC;
    int unk0FC0, unk0FC4, unk0FC8, unk0FCC, unk0FD0, unk0FD4, unk0FD8, unk0FDC, unk0FE0, unk0FE4, unk0FE8, unk0FEC,
        unk0FF0, unk0FF4, unk0FF8, unk0FFC;
    int unk1000, unk1004, unk1008, unk100C, unk1010, unk1014, unk1018, unk101C, unk1020, unk1024, unk1028, unk102C,
        unk1030, unk1034, unk1038, unk103C;
    int unk1040, unk1044, unk1048, unk104C, unk1050, unk1054, unk1058, unk105C, unk1060, unk1064, unk1068, unk106C,
        unk1070, unk1074, unk1078, unk107C;
    int unk1080, unk1084, unk1088, unk108C, unk1090, unk1094, unk1098, unk109C, unk10A0, unk10A4, unk10A8, unk10AC,
        unk10B0, unk10B4, unk10B8, unk10BC;
    int unk10C0, unk10C4, unk10C8, unk10CC, unk10D0, unk10D4, unk10D8, unk10DC, unk10E0, unk10E4, unk10E8, unk10EC,
        unk10F0, unk10F4, unk10F8, unk10FC;
    int unk1100, unk1104, unk1108, unk110C, unk1110, unk1114, unk1118, unk111C, unk1120, unk1124, unk1128, unk112C,
        unk1130, unk1134, unk1138, unk113C;
    int unk1140, unk1144, unk1148, unk114C, unk1150, unk1154, unk1158, unk115C, unk1160, unk1164, unk1168, unk116C,
        unk1170, unk1174, unk1178, unk117C;
    int unk1180, unk1184, unk1188, unk118C, unk1190, unk1194, unk1198, unk119C, unk11A0, unk11A4, unk11A8, unk11AC,
        unk11B0, unk11B4, unk11B8, unk11BC;
    int unk11C0, unk11C4, unk11C8, unk11CC, unk11D0, unk11D4, unk11D8, unk11DC, unk11E0, unk11E4, unk11E8, unk11EC,
        unk11F0, unk11F4, unk11F8, unk11FC;
    int unk1200, unk1204, unk1208, unk120C, unk1210, unk1214, unk1218, unk121C, unk1220, unk1224, unk1228, unk122C,
        unk1230, unk1234, unk1238, unk123C;
    int unk1240, unk1244, unk1248, unk124C, unk1250, unk1254, unk1258, unk125C, unk1260, unk1264, unk1268, unk126C,
        unk1270, unk1274, unk1278, unk127C;
    int unk1280, unk1284, unk1288, unk128C, unk1290, unk1294, unk1298, unk129C, unk12A0, unk12A4, unk12A8, unk12AC,
        unk12B0, unk12B4, unk12B8, unk12BC;
    int unk12C0, unk12C4, unk12C8, unk12CC, unk12D0, unk12D4, unk12D8, unk12DC, unk12E0, unk12E4, unk12E8, unk12EC,
        unk12F0, unk12F4, unk12F8, unk12FC;
    int unk1300, unk1304, unk1308, unk130C, unk1310, unk1314, unk1318, unk131C, unk1320, unk1324, unk1328, unk132C,
        unk1330, unk1334, unk1338, unk133C;
    int unk1340, unk1344, unk1348, unk134C, unk1350, unk1354, unk1358, unk135C, unk1360, unk1364, unk1368, unk136C,
        unk1370, unk1374, unk1378, unk137C;
    int unk1380, unk1384, unk1388, unk138C, unk1390, unk1394, unk1398, unk139C, unk13A0, unk13A4, unk13A8, unk13AC,
        unk13B0, unk13B4, unk13B8, unk13BC;
    int unk13C0, unk13C4, unk13C8, unk13CC, unk13D0, unk13D4, unk13D8, unk13DC, unk13E0, unk13E4, unk13E8, unk13EC,
        unk13F0, unk13F4, unk13F8, unk13FC;
    int unk1400, unk1404, unk1408, unk140C, unk1410, unk1414, unk1418, unk141C, unk1420, unk1424, unk1428, unk142C,
        unk1430, unk1434, unk1438, unk143C;
    int unk1440, unk1444, unk1448, unk144C, unk1450, unk1454, unk1458, unk145C, unk1460, unk1464, unk1468, unk146C,
        unk1470, unk1474, unk1478, unk147C;
    int unk1480, unk1484, unk1488, unk148C, unk1490, unk1494, unk1498, unk149C, unk14A0, unk14A4, unk14A8, unk14AC,
        unk14B0, unk14B4, unk14B8, unk14BC;
    int unk14C0, unk14C4, unk14C8, unk14CC, unk14D0, unk14D4, unk14D8, unk14DC, unk14E0, unk14E4, unk14E8, unk14EC,
        unk14F0, unk14F4, unk14F8, unk14FC;
    int unk1500, unk1504, unk1508, unk150C, unk1510, unk1514, unk1518, unk151C, unk1520, unk1524, unk1528, unk152C,
        unk1530, unk1534, unk1538, unk153C;
    int unk1540, unk1544, unk1548, unk154C, unk1550, unk1554, unk1558, unk155C, unk1560, unk1564, unk1568, unk156C,
        unk1570, unk1574, unk1578, unk157C;
    int unk1580, unk1584, unk1588, unk158C, unk1590, unk1594, unk1598, unk159C, unk15A0, unk15A4, unk15A8, unk15AC,
        unk15B0, unk15B4, unk15B8, unk15BC;
    int unk15C0, unk15C4, unk15C8, unk15CC, unk15D0, unk15D4, unk15D8, unk15DC, unk15E0, unk15E4, unk15E8, unk15EC,
        unk15F0, unk15F4, unk15F8, unk15FC;
    int unk1600, unk1604, unk1608, unk160C, unk1610, unk1614, unk1618, unk161C, unk1620, unk1624, unk1628, unk162C,
        unk1630, unk1634, unk1638, unk163C;
    int unk1640, unk1644, unk1648, unk164C, unk1650, unk1654, unk1658, unk165C, unk1660, unk1664, unk1668, unk166C,
        unk1670, unk1674, unk1678, unk167C;
    int unk1680, unk1684, unk1688, unk168C, unk1690, unk1694, unk1698, unk169C, unk16A0, unk16A4, unk16A8, unk16AC,
        unk16B0, unk16B4, unk16B8, unk16BC;
    int unk16C0, unk16C4, unk16C8, unk16CC, unk16D0, unk16D4, unk16D8, unk16DC, unk16E0, unk16E4, unk16E8, unk16EC,
        unk16F0, unk16F4, unk16F8, unk16FC;
    int unk1700, unk1704, unk1708, unk170C, unk1710, unk1714, unk1718, unk171C, unk1720, unk1724, unk1728, unk172C,
        unk1730, unk1734, unk1738, unk173C;
    int unk1740, unk1744, unk1748, unk174C, unk1750, unk1754, unk1758, unk175C, unk1760, unk1764, unk1768, unk176C,
        unk1770, unk1774, unk1778, unk177C;
    int unk1780, unk1784, unk1788, unk178C, unk1790, unk1794, unk1798, unk179C, unk17A0, unk17A4, unk17A8, unk17AC,
        unk17B0, unk17B4, unk17B8, unk17BC;
    int unk17C0, unk17C4, unk17C8, unk17CC, unk17D0, unk17D4, unk17D8, unk17DC, unk17E0, unk17E4, unk17E8, unk17EC,
        unk17F0, unk17F4, unk17F8, unk17FC;
    int unk1800, unk1804, unk1808, unk180C, unk1810, unk1814, unk1818, unk181C, unk1820, unk1824, unk1828, unk182C,
        unk1830, unk1834, unk1838, unk183C;
    int unk1840, unk1844, unk1848, unk184C, unk1850, unk1854, unk1858, unk185C, unk1860, unk1864, unk1868, unk186C,
        unk1870, unk1874, unk1878, unk187C;
    int unk1880, unk1884, unk1888, unk188C, unk1890, unk1894, unk1898, unk189C, unk18A0, unk18A4, unk18A8, unk18AC,
        unk18B0, unk18B4, unk18B8, unk18BC;
    int unk18C0, unk18C4, unk18C8, unk18CC, unk18D0, unk18D4, unk18D8, unk18DC, unk18E0, unk18E4, unk18E8, unk18EC,
        unk18F0, unk18F4, unk18F8, unk18FC;
    int unk1900, unk1904, unk1908, unk190C, unk1910, unk1914, unk1918, unk191C, unk1920, unk1924, unk1928, unk192C,
        unk1930, unk1934, unk1938, unk193C;
    int unk1940, unk1944, unk1948, unk194C, unk1950, unk1954, unk1958, unk195C, unk1960, unk1964, unk1968, unk196C,
        unk1970, unk1974, unk1978, unk197C;
    int unk1980, unk1984, unk1988, unk198C, unk1990, unk1994, unk1998, unk199C, unk19A0, unk19A4, unk19A8, unk19AC,
        unk19B0, unk19B4, unk19B8, unk19BC;
    int unk19C0, unk19C4, unk19C8, unk19CC, unk19D0, unk19D4, unk19D8, unk19DC, unk19E0, unk19E4, unk19E8, unk19EC,
        unk19F0, unk19F4, unk19F8, unk19FC;
    int unk1A00, unk1A04, unk1A08, unk1A0C, unk1A10, unk1A14, unk1A18, unk1A1C, unk1A20, unk1A24, unk1A28, unk1A2C,
        unk1A30, unk1A34, unk1A38, unk1A3C;
    int unk1A40, unk1A44, unk1A48, unk1A4C, unk1A50, unk1A54, unk1A58, unk1A5C, unk1A60, unk1A64, unk1A68, unk1A6C,
        unk1A70, unk1A74, unk1A78, unk1A7C;
    int unk1A80, unk1A84, unk1A88, unk1A8C, unk1A90, unk1A94, unk1A98, unk1A9C, unk1AA0, unk1AA4, unk1AA8, unk1AAC,
        unk1AB0, unk1AB4, unk1AB8, unk1ABC;
    int unk1AC0, unk1AC4, unk1AC8, unk1ACC, unk1AD0, unk1AD4, unk1AD8, unk1ADC, unk1AE0, unk1AE4, unk1AE8, unk1AEC,
        unk1AF0, unk1AF4, unk1AF8, unk1AFC;
    int unk1B00, unk1B04, unk1B08, unk1B0C, unk1B10, unk1B14, unk1B18, unk1B1C, unk1B20, unk1B24, unk1B28, unk1B2C,
        unk1B30, unk1B34, unk1B38, unk1B3C;
    int unk1B40, unk1B44, unk1B48, unk1B4C, unk1B50, unk1B54, unk1B58, unk1B5C, unk1B60, unk1B64, unk1B68, unk1B6C,
        unk1B70, unk1B74, unk1B78, unk1B7C;
    int unk1B80, unk1B84, unk1B88, unk1B8C, unk1B90, unk1B94, unk1B98, unk1B9C, unk1BA0, unk1BA4, unk1BA8, unk1BAC,
        unk1BB0, unk1BB4, unk1BB8, unk1BBC;
    int unk1BC0, unk1BC4, unk1BC8, unk1BCC, unk1BD0, unk1BD4, unk1BD8, unk1BDC, unk1BE0, unk1BE4, unk1BE8, unk1BEC,
        unk1BF0, unk1BF4, unk1BF8, unk1BFC;
    int unk1C00, unk1C04, unk1C08, unk1C0C, unk1C10, unk1C14, unk1C18, unk1C1C, unk1C20, unk1C24, unk1C28, unk1C2C,
        unk1C30, unk1C34, unk1C38, unk1C3C;
    int unk1C40, unk1C44, unk1C48, unk1C4C, unk1C50, unk1C54, unk1C58, unk1C5C, unk1C60, unk1C64, unk1C68, unk1C6C,
        unk1C70, unk1C74, unk1C78, unk1C7C;
    int unk1C80, unk1C84, unk1C88, unk1C8C, unk1C90, unk1C94, unk1C98, unk1C9C, unk1CA0, unk1CA4, unk1CA8, unk1CAC,
        unk1CB0, unk1CB4, unk1CB8, unk1CBC;
    int unk1CC0, unk1CC4, unk1CC8, unk1CCC, unk1CD0, unk1CD4, unk1CD8, unk1CDC, unk1CE0, unk1CE4, unk1CE8, unk1CEC,
        unk1CF0, unk1CF4, unk1CF8, unk1CFC;
    int unk1D00, unk1D04, unk1D08, unk1D0C, unk1D10, unk1D14, unk1D18, unk1D1C, unk1D20, unk1D24, unk1D28, unk1D2C,
        unk1D30, unk1D34, unk1D38, unk1D3C;
    int unk1D40, unk1D44, unk1D48, unk1D4C, unk1D50, unk1D54, unk1D58, unk1D5C, unk1D60, unk1D64, unk1D68, unk1D6C,
        unk1D70, unk1D74, unk1D78, unk1D7C;
    int unk1D80, unk1D84, unk1D88, unk1D8C, unk1D90, unk1D94, unk1D98, unk1D9C, unk1DA0, unk1DA4, unk1DA8, unk1DAC,
        unk1DB0, unk1DB4, unk1DB8, unk1DBC;
    int unk1DC0, unk1DC4, unk1DC8, unk1DCC, unk1DD0, unk1DD4, unk1DD8, unk1DDC, unk1DE0, unk1DE4, unk1DE8, unk1DEC,
        unk1DF0, unk1DF4, unk1DF8, unk1DFC;
    int unk1E00, unk1E04, unk1E08, unk1E0C, unk1E10, unk1E14, unk1E18, unk1E1C, unk1E20, unk1E24, unk1E28, unk1E2C,
        unk1E30, unk1E34, unk1E38, unk1E3C;
    int unk1E40, unk1E44, unk1E48, unk1E4C, unk1E50, unk1E54, unk1E58, unk1E5C, unk1E60, unk1E64, unk1E68, unk1E6C,
        unk1E70, unk1E74, unk1E78, unk1E7C;
    int unk1E80, unk1E84, unk1E88, unk1E8C, unk1E90, unk1E94, unk1E98, unk1E9C, unk1EA0, unk1EA4, unk1EA8, unk1EAC,
        unk1EB0, unk1EB4, unk1EB8, unk1EBC;
    int unk1EC0, unk1EC4, unk1EC8, unk1ECC, unk1ED0, unk1ED4, unk1ED8, unk1EDC, unk1EE0, unk1EE4, unk1EE8, unk1EEC,
        unk1EF0, unk1EF4, unk1EF8, unk1EFC;
    int unk1F00, unk1F04, unk1F08, unk1F0C, unk1F10, unk1F14, unk1F18, unk1F1C, unk1F20, unk1F24, unk1F28, unk1F2C,
        unk1F30, unk1F34, unk1F38, unk1F3C;
    int unk1F40, unk1F44, unk1F48, unk1F4C, unk1F50, unk1F54, unk1F58, unk1F5C, unk1F60, unk1F64, unk1F68, unk1F6C,
        unk1F70, unk1F74, unk1F78, unk1F7C;
    int unk1F80, unk1F84, unk1F88, unk1F8C, unk1F90, unk1F94, unk1F98, unk1F9C, unk1FA0, unk1FA4, unk1FA8, unk1FAC,
        unk1FB0, unk1FB4, unk1FB8, unk1FBC;
    int unk1FC0, unk1FC4, unk1FC8, unk1FCC, unk1FD0, unk1FD4, unk1FD8, unk1FDC, unk1FE0, unk1FE4, unk1FE8, unk1FEC,
        unk1FF0, unk1FF4, unk1FF8, unk1FFC;
    int unk2000, unk2004, unk2008, unk200C, unk2010, unk2014, unk2018, unk201C, unk2020, unk2024, unk2028, unk202C,
        unk2030, unk2034, unk2038, unk203C;
    int unk2040, unk2044;
    int m_2048;
    int unk204C;
    int unk2050;
    unsigned char m_2054;
    void* FindPathStep();
    void ExtractNodeValues(void* p, int a1, int a2);
    bool ProcessWithFallback(int a1, int a2, bool a3);
};

// @fnv 0x006b8f40
bool FUN_006b8f40_cls::ProcessWithFallback(int a1, int a2, bool abUseFallback)
{
    bool ok;
    void* q;
    m_2054 = FUN_00b00a00()->v3(FUN_0040fc90());
    q = FindPathStep();
    {
        void* p;
        if (q != 0)
        {
            ok = true;
            p = q;
        }
        else if (abUseFallback)
        {
            ok = false;
            p = (void*)m_2048;
        }
        else
        {
            ok = false;
            p = 0;
        }
        if (p != 0)
        {
            ExtractNodeValues(p, a1, a2);
        }
    }
    return ok;
}
}  // namespace fnv_006b8f40

struct FUN_006bfab0
{
    virtual void v0();
    ~FUN_006bfab0();
};
struct FUN_006bfad0 : FUN_006bfab0
{
    virtual ~FUN_006bfad0();
    void __thiscall FUN_008454f0(int freeMemory);
};
// Destructor that calls FUN_008454f0 with 1 to free memory.
// @fnv 0x006bfad0
FUN_006bfad0::~FUN_006bfad0()
{
    FUN_008454f0(1);
}

struct FUN_006b1d80
{
    float m[16];
    FUN_006b1d80();
};

// Constructs a FUN_006b1d80 object in-place at each of the first count elements of items.
// @fnv 0x006a2630
// src: GUESS 0x006a2630 (confidence: medium)
void Array64::ConstructElementsInPlace(ResizeElement64* items, unsigned int count)
{
    for (unsigned int i = 0; i < count; i++)
    {
        new (&items[i]) FUN_006b1d80;
    }
}

namespace PathDebugRender {

struct DbgObject
{
    static void* operator new(unsigned int auiSize);
    static void operator delete(void* apMem, unsigned int);
    void NiMaterialProperty_SetEmittance(void* apKey);
    void NiMaterialProperty_SetAlpha(float afValue);
    void NiAVObject_AttachProperty(DbgObject* apProperty);
    void NiAVObject_RemoveProperty(int aiValue);
    void NiAlphaProperty_SetAlphaBlending(int aiValue);
};

struct DbgPropertyState : DbgObject
{
    DbgPropertyState();
    int iData[7];
};

struct DbgAlphaProperty : DbgObject
{
    DbgAlphaProperty();
    int iData[0x13];
};

struct DbgPtr
{
    DbgObject* pObject;
    DbgPtr();
    DbgPtr(DbgObject* apObject);
    ~DbgPtr();
    DbgPtr& FUN_0066b0d0(DbgObject* apObject);
    DbgObject* Modelloader_GetReferencedThis();
};

struct DbgColor
{
    float r, g, b, a;
    DbgColor();
    DbgColor(float afR, float afG, float afB, float afA);
};

struct DbgLineArray
{
    int iData[4];
    DbgLineArray(int aiCount);
    ~DbgLineArray();
};

struct DbgPointArray
{
    int iData[4];
    DbgPointArray(int aiCount);
    ~DbgPointArray();
};

extern char DAT_011a9b7c;
extern float DAT_0119cb84;
extern const float DAT_0106b4f0;
extern const float DAT_0106b4f4;
extern const float DAT_0106b4fc;
extern const float DAT_0106b500;
extern const float DAT_0106b508;
extern const float DAT_0106b50c;
DbgObject* __cdecl CreateOctahedron(float afSize, DbgColor* apColor, int aiFlags);

struct FUN_006a2a20
{
    DbgPtr m_pRootNode;
    DbgPtr spLines;
    DbgPtr spPoints;
    DbgPtr aspShapes[17];
    DbgPtr aspLineAlpha[17];
    DbgPtr aspPointAlpha[17];
    DbgColor akColors[17];
    DbgPtr spState;
    DbgPtr spAlpha;
    DbgLineArray kLines;
    DbgPointArray kPoints;
    bool bEnabled;

    FUN_006a2a20();
};

// Constructs 17 colors, alpha values and octahedron shapes with line/point alpha and no-lighting shader properties, plus a state property and spAlpha (0.5).
// @fnv 0x006a2a20
FUN_006a2a20::FUN_006a2a20()
    : m_pRootNode(0), spLines(0), spPoints(0), spState(0), spAlpha(0), kLines(0x25), kPoints(0x25)
{
    bEnabled = false;
    akColors[0] = DbgColor(1.0f, 0.0f, 0.0f, 1.0f);
    akColors[1] = DbgColor(1.0f, 0.0f, 0.0f, 1.0f);
    akColors[2] = DbgColor(0.0f, 1.0f, 0.0f, 1.0f);
    akColors[3] = DbgColor(0.0f, 1.0f, 0.0f, 1.0f);
    akColors[4] = DbgColor(0.0f, 1.0f, 0.5f, 1.0f);
    akColors[5] = DbgColor(0.0f, 0.5f, 1.0f, 1.0f);
    akColors[6] = DbgColor(1.0f, 1.0f, 0.0f, 1.0f);
    akColors[7] = DbgColor(0.0f, 0.0f, 1.0f, 1.0f);
    akColors[8] = DbgColor(0.5f, 0.5f, 1.0f, 1.0f);
    akColors[9] = DbgColor(1.0f, 1.0f, 1.0f, 1.0f);
    akColors[10] = DbgColor(0.0f, 0.0f, 0.0f, 1.0f);
    akColors[11] = DbgColor(1.0f, 0.0f, 1.0f, 1.0f);
    akColors[12] = DbgColor(0.75f, 0.25f, 1.0f, 1.0f);
    akColors[13] = DbgColor(1.0f, 0.5f, 0.0f, 1.0f);
    akColors[14] = DbgColor(1.0f, 0.5f, 0.5f, 1.0f);
    akColors[15] = DbgColor(1.0f, 0.0f, 1.0f, 1.0f);
    akColors[16] = DbgColor(0.75f, 0.0f, 0.0f, 1.0f);
    float afLineAlphaCur[17];
    afLineAlphaCur[0] = DAT_0106b4fc;
    afLineAlphaCur[1] = DAT_0106b500;
    afLineAlphaCur[2] = DAT_0106b4fc;
    afLineAlphaCur[3] = DAT_0106b500;
    afLineAlphaCur[4] = DAT_0106b500;
    afLineAlphaCur[5] = DAT_0106b500;
    afLineAlphaCur[6] = DAT_0106b4fc;
    afLineAlphaCur[7] = DAT_0106b4fc;
    afLineAlphaCur[8] = DAT_0106b4fc;
    afLineAlphaCur[9] = DAT_0106b4fc;
    afLineAlphaCur[10] = DAT_0106b508;
    afLineAlphaCur[11] = DAT_0106b50c;
    afLineAlphaCur[12] = DAT_0106b50c;
    afLineAlphaCur[13] = DAT_0106b4fc;
    afLineAlphaCur[14] = DAT_0106b4fc;
    afLineAlphaCur[15] = DAT_0106b4fc;
    afLineAlphaCur[16] = DAT_0106b4fc;
    float afPointAlpha[17];
    afPointAlpha[0] = DAT_0106b4f0;
    afPointAlpha[1] = DAT_0106b4f4;
    afPointAlpha[2] = DAT_0106b4f0;
    afPointAlpha[3] = DAT_0106b4f4;
    afPointAlpha[4] = DAT_0106b4f0;
    afPointAlpha[6] = DAT_0106b4f0;
    afPointAlpha[7] = DAT_0106b4f0;
    afPointAlpha[8] = DAT_0106b4f0;
    afPointAlpha[9] = DAT_0106b500;
    afPointAlpha[10] = DAT_0106b4f0;
    afPointAlpha[11] = DAT_0106b50c;
    afPointAlpha[12] = DAT_0106b50c;
    afPointAlpha[13] = DAT_0106b4f0;
    afPointAlpha[14] = DAT_0106b4f0;
    afPointAlpha[15] = DAT_0106b4f0;
    afPointAlpha[16] = DAT_0106b4f0;
    spState.FUN_0066b0d0(new DbgPropertyState());
    spState.Modelloader_GetReferencedThis()->NiAlphaProperty_SetAlphaBlending(1);
    for (unsigned int i = 0; i < 17; i++)
    {
        aspLineAlpha[i].FUN_0066b0d0(new DbgAlphaProperty());
        aspLineAlpha[i].Modelloader_GetReferencedThis()->NiMaterialProperty_SetEmittance(&DAT_011a9b7c);
        aspLineAlpha[i].Modelloader_GetReferencedThis()->NiMaterialProperty_SetAlpha(afLineAlphaCur[i]);
        aspPointAlpha[i].FUN_0066b0d0(new DbgAlphaProperty());
        aspPointAlpha[i].Modelloader_GetReferencedThis()->NiMaterialProperty_SetEmittance(&DAT_011a9b7c);
        aspPointAlpha[i].Modelloader_GetReferencedThis()->NiMaterialProperty_SetAlpha(afPointAlpha[i]);
        aspShapes[i].FUN_0066b0d0(CreateOctahedron(DAT_0119cb84, &akColors[i], 1));
        aspShapes[i].Modelloader_GetReferencedThis()->NiAVObject_AttachProperty(aspLineAlpha[i].Modelloader_GetReferencedThis());
        DbgPtr spShaderProperty = reinterpret_cast<DbgObject*>(new BSShaderNoLightingProperty());
        reinterpret_cast<BSShaderNoLightingProperty*>(spShaderProperty.Modelloader_GetReferencedThis())->SetFlag(0x20, false);
        aspShapes[i].Modelloader_GetReferencedThis()->NiAVObject_RemoveProperty(3);
        aspShapes[i].Modelloader_GetReferencedThis()->NiAVObject_AttachProperty(spShaderProperty.Modelloader_GetReferencedThis());
    }
    spAlpha.FUN_0066b0d0(new DbgAlphaProperty());
    spAlpha.Modelloader_GetReferencedThis()->NiMaterialProperty_SetEmittance(&DAT_011a9b7c);
    spAlpha.Modelloader_GetReferencedThis()->NiMaterialProperty_SetAlpha(0.5f);
}

}

class FUN_006a65b0
{
  public:
    virtual ~FUN_006a65b0();

    void FUN_00438af0();
};

class FUN_006a6550 : public FUN_006a65b0
{
  public:
    virtual ~FUN_006a6550();
};

// @fnv 0x006a6550
FUN_006a6550::~FUN_006a6550()
{
    FUN_00438af0();
}

class ArrayBase6B42F0
{
  public:
    virtual ~ArrayBase6B42F0();
    void* m_pBuffer;
    unsigned int m_uiSize;
    unsigned int m_uiCapacity;
    void Clear(bool bFreeMemory);
};
class FUN_006b42f0 : public ArrayBase6B42F0
{
  public:
    virtual ~FUN_006b42f0();
};

// Destructor that calls Clear(true), passing bFreeMemory as true.
// @fnv 0x006b42f0
FUN_006b42f0::~FUN_006b42f0()
{
    Clear(true);
}

extern float DAT_0106c2e0;
struct S006bede0_Vec
{
    float x;
    float y;
    float z;
    S006bede0_Vec& FUN_00439e90(S006bede0_Vec* o0, S006bede0_Vec* p1, S006bede0_Vec* o2, S006bede0_Vec* p3,
                                S006bede0_Vec* o4, float k);
    S006bede0_Vec& FUN_00439e90();
    void ApplyScaled();
};

struct S006bede0_Obj
{
    NavMesh* m0;
    bool NavMeshObstacleCutter_IsPointInOverlappedArea(S006bede0_Vec const&);
    bool NavMeshObstacleCutter_CheckTriangleAgainstOverlapped(unsigned short const* a, unsigned short const* b, unsigned short const* c);
};

// Fetches three vertices from m0 by index, computes t7 from them via FUN_00439e90 and ApplyScaled using DAT_0106c2e0, and returns FUN_006bf220(t7).
// @fnv 0x006bede0
// src: COMMUNITY 0x006bede0
bool S006bede0_Obj::NavMeshObstacleCutter_CheckTriangleAgainstOverlapped(unsigned short const* apIndexA, unsigned short const* apIndexB,
                                 unsigned short const* apIndexC)
{
    S006bede0_Vec pa4 = reinterpret_cast<const S006bede0_Vec&>(m0->GetVertex_0068f0a0(apIndexA[0]));
    S006bede0_Vec pb4 = reinterpret_cast<const S006bede0_Vec&>(m0->GetVertex_0068f0a0(apIndexB[0]));
    S006bede0_Vec pc2 = reinterpret_cast<const S006bede0_Vec&>(m0->GetVertex_0068f0a0(apIndexC[0]));
    S006bede0_Vec t1;
    S006bede0_Vec t2;
    S006bede0_Vec t7;
    pa4.FUN_00439e90(&t2, &pb4, &t1, &pc2, &t7, DAT_0106c2e0).FUN_00439e90().ApplyScaled();
    return NavMeshObstacleCutter_IsPointInOverlappedArea(t7);
}

struct LocalOwnerBase
{
    virtual ~LocalOwnerBase();
    unsigned int unk04, flags;
    LocalOwnerBase();
};
struct StateBlock
{
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10;
    StateBlock(int);
    ~StateBlock();
};
struct FirstArray
{
    unsigned int unk00, unk04, unk08, unk0c;
    FirstArray(int, int);
    ~FirstArray();
};
struct SecondArray
{
    unsigned int unk00, unk04, unk08, unk0c;
    SecondArray(int, int);
    ~SecondArray();
};
struct LookupTable
{
    unsigned int unk00, unk04, unk08, unk0c;
    LookupTable(int);
    ~LookupTable();
};
struct FirstList
{
    unsigned int unk00, unk04, unk08, unk0c;
    FirstList();
    ~FirstList();
};
struct SecondList
{
    unsigned int unk00, unk04, unk08, unk0c;
    SecondList();
    ~SecondList();
};
struct FUN_006bc230 : LocalOwnerBase
{
    StateBlock state;
    FirstArray first;
    SecondArray second;
    LookupTable table;
    FirstList list1;
    SecondList list2;
    FUN_006bc230();
    virtual ~FUN_006bc230();
};
// Constructs state(0), first(32,0), second(32,0) and table(37) with those arguments, default-constructs list1 and list2, and sets flags to 0.
// @fnv 0x006bc230
FUN_006bc230::FUN_006bc230() : state(0), first(32, 0), second(32, 0), table(37)
{
    flags = 0;
}


class NavMeshStaticAvoidNode;
struct FUN_006a7fe0
{
    BSSimpleArray<NavMeshStaticAvoidNode*, 1024> m_aiIndexedValues;
    virtual ~FUN_006a7fe0();
};
// Destructor for a container holding an indexed array of NavMeshStaticAvoidNode pointers.
// @fnv 0x006a7fe0
FUN_006a7fe0::~FUN_006a7fe0()
{}

class NavMeshTriangleReference;
class NavMeshTriangleEdgeReference;
template <class A, class B> struct AStarConnectionArray
{
    ~AStarConnectionArray();
};
struct FUN_006a89d0 : AStarConnectionArray<NavMeshTriangleReference, NavMeshTriangleEdgeReference>
{
    virtual ~FUN_006a89d0();
};
// Empty destructor body; the AStarConnectionArray base destructor runs afterward.
// @fnv 0x006a89d0
FUN_006a89d0::~FUN_006a89d0()
{}

#include "../../include/PathSmootherPOVAvoidanceNode.h"
// @fnv 0x006b38b0
template <> BSSimpleArray<PathSmootherPOVAvoidanceNode>::~BSSimpleArray()
{
    Clear(true);
}

struct NavMeshEdgeSegment;
// @fnv 0x006b38e0
template <> BSSimpleArray<NavMeshEdgeSegment>::~BSSimpleArray()
{
    Clear(true);
}

struct Base_b10083
{
    virtual ~Base_b10083();
    void Cleanup();
};

struct FUN_006b7fd0 : Base_b10083
{
    virtual ~FUN_006b7fd0();
};

// Calls Cleanup on the base class before returning.
// @fnv 0x006b7fd0
FUN_006b7fd0::~FUN_006b7fd0()
{
    Cleanup();
}

class MapDtorWrap : public NiTPointerMap<int, int>
{
  public:
    virtual void unk00();
    ~MapDtorWrap();
};

class FUN_006b80d0_cls : public MapDtorWrap
{
  public:
    virtual ~FUN_006b80d0_cls();
};

// Destructor body that calls RemoveAll through a FUN_006b8030_class cast.
// @fnv 0x006b80d0
FUN_006b80d0_cls::~FUN_006b80d0_cls()
{
    reinterpret_cast<FUN_006b8030_class*>(this)->RemoveAll();
}

class B6B81F0MapBase
{
  public:
    virtual ~B6B81F0MapBase();

    void RemoveAll();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FUN_006b81f0_cls : public B6B81F0MapBase
{
  public:
    FUN_006b81f0_cls();
    virtual ~FUN_006b81f0_cls();
};

// Destructor body that calls RemoveAll.
// @fnv 0x006b81f0
FUN_006b81f0_cls::~FUN_006b81f0_cls()
{
    RemoveAll();
}

class FUN_00483710
{
  public:
    ~FUN_00483710();

    int unk00;
};

namespace CombatGroupB8E {
class FUN_006b8e40
{
  public:
    virtual ~FUN_006b8e40();

    FUN_00982610_Type m_kTargets;
    FUN_00483710 m_kListA;
    int unk0018, unk001C, unk0020, unk0024, unk0028, unk002C, unk0030, unk0034, unk0038, unk003C, unk0040, unk0044;
    int unk0048, unk004C, unk0050, unk0054, unk0058, unk005C, unk0060, unk0064, unk0068, unk006C, unk0070, unk0074;
    int unk0078, unk007C, unk0080, unk0084, unk0088, unk008C, unk0090, unk0094, unk0098, unk009C, unk00A0, unk00A4;
    int unk00A8, unk00AC, unk00B0, unk00B4, unk00B8, unk00BC, unk00C0, unk00C4, unk00C8, unk00CC, unk00D0, unk00D4;
    int unk00D8, unk00DC, unk00E0, unk00E4, unk00E8, unk00EC, unk00F0, unk00F4, unk00F8, unk00FC, unk0100, unk0104;
    int unk0108, unk010C, unk0110, unk0114, unk0118, unk011C, unk0120, unk0124, unk0128, unk012C, unk0130, unk0134;
    int unk0138, unk013C, unk0140, unk0144, unk0148, unk014C, unk0150, unk0154, unk0158, unk015C, unk0160, unk0164;
    int unk0168, unk016C, unk0170, unk0174, unk0178, unk017C, unk0180, unk0184, unk0188, unk018C, unk0190, unk0194;
    int unk0198, unk019C, unk01A0, unk01A4, unk01A8, unk01AC, unk01B0, unk01B4, unk01B8, unk01BC, unk01C0, unk01C4;
    int unk01C8, unk01CC, unk01D0, unk01D4, unk01D8, unk01DC, unk01E0, unk01E4, unk01E8, unk01EC, unk01F0, unk01F4;
    int unk01F8, unk01FC, unk0200, unk0204, unk0208, unk020C, unk0210, unk0214, unk0218, unk021C, unk0220, unk0224;
    int unk0228, unk022C, unk0230, unk0234, unk0238, unk023C, unk0240, unk0244, unk0248, unk024C, unk0250, unk0254;
    int unk0258, unk025C, unk0260, unk0264, unk0268, unk026C, unk0270, unk0274, unk0278, unk027C, unk0280, unk0284;
    int unk0288, unk028C, unk0290, unk0294, unk0298, unk029C, unk02A0, unk02A4, unk02A8, unk02AC, unk02B0, unk02B4;
    int unk02B8, unk02BC, unk02C0, unk02C4, unk02C8, unk02CC, unk02D0, unk02D4, unk02D8, unk02DC, unk02E0, unk02E4;
    int unk02E8, unk02EC, unk02F0, unk02F4, unk02F8, unk02FC, unk0300, unk0304, unk0308, unk030C, unk0310, unk0314;
    int unk0318, unk031C, unk0320, unk0324, unk0328, unk032C, unk0330, unk0334, unk0338, unk033C, unk0340, unk0344;
    int unk0348, unk034C, unk0350, unk0354, unk0358, unk035C, unk0360, unk0364, unk0368, unk036C, unk0370, unk0374;
    int unk0378, unk037C, unk0380, unk0384, unk0388, unk038C, unk0390, unk0394, unk0398, unk039C, unk03A0, unk03A4;
    int unk03A8, unk03AC, unk03B0, unk03B4, unk03B8, unk03BC, unk03C0, unk03C4, unk03C8, unk03CC, unk03D0, unk03D4;
    int unk03D8, unk03DC, unk03E0, unk03E4, unk03E8, unk03EC, unk03F0, unk03F4, unk03F8, unk03FC, unk0400, unk0404;
    int unk0408, unk040C, unk0410, unk0414, unk0418, unk041C, unk0420, unk0424, unk0428, unk042C, unk0430, unk0434;
    int unk0438, unk043C, unk0440, unk0444, unk0448, unk044C, unk0450, unk0454, unk0458, unk045C, unk0460, unk0464;
    int unk0468, unk046C, unk0470, unk0474, unk0478, unk047C, unk0480, unk0484, unk0488, unk048C, unk0490, unk0494;
    int unk0498, unk049C, unk04A0, unk04A4, unk04A8, unk04AC, unk04B0, unk04B4, unk04B8, unk04BC, unk04C0, unk04C4;
    int unk04C8, unk04CC, unk04D0, unk04D4, unk04D8, unk04DC, unk04E0, unk04E4, unk04E8, unk04EC, unk04F0, unk04F4;
    int unk04F8, unk04FC, unk0500, unk0504, unk0508, unk050C, unk0510, unk0514, unk0518, unk051C, unk0520, unk0524;
    int unk0528, unk052C, unk0530, unk0534, unk0538, unk053C, unk0540, unk0544, unk0548, unk054C, unk0550, unk0554;
    int unk0558, unk055C, unk0560, unk0564, unk0568, unk056C, unk0570, unk0574, unk0578, unk057C, unk0580, unk0584;
    int unk0588, unk058C, unk0590, unk0594, unk0598, unk059C, unk05A0, unk05A4, unk05A8, unk05AC, unk05B0, unk05B4;
    int unk05B8, unk05BC, unk05C0, unk05C4, unk05C8, unk05CC, unk05D0, unk05D4, unk05D8, unk05DC, unk05E0, unk05E4;
    int unk05E8, unk05EC, unk05F0, unk05F4, unk05F8, unk05FC, unk0600, unk0604, unk0608, unk060C, unk0610, unk0614;
    int unk0618, unk061C, unk0620, unk0624, unk0628, unk062C, unk0630, unk0634, unk0638, unk063C, unk0640, unk0644;
    int unk0648, unk064C, unk0650, unk0654, unk0658, unk065C, unk0660, unk0664, unk0668, unk066C, unk0670, unk0674;
    int unk0678, unk067C, unk0680, unk0684, unk0688, unk068C, unk0690, unk0694, unk0698, unk069C, unk06A0, unk06A4;
    int unk06A8, unk06AC, unk06B0, unk06B4, unk06B8, unk06BC, unk06C0, unk06C4, unk06C8, unk06CC, unk06D0, unk06D4;
    int unk06D8, unk06DC, unk06E0, unk06E4, unk06E8, unk06EC, unk06F0, unk06F4, unk06F8, unk06FC, unk0700, unk0704;
    int unk0708, unk070C, unk0710, unk0714, unk0718, unk071C, unk0720, unk0724, unk0728, unk072C, unk0730, unk0734;
    int unk0738, unk073C, unk0740, unk0744, unk0748, unk074C, unk0750, unk0754, unk0758, unk075C, unk0760, unk0764;
    int unk0768, unk076C, unk0770, unk0774, unk0778, unk077C, unk0780, unk0784, unk0788, unk078C, unk0790, unk0794;
    int unk0798, unk079C, unk07A0, unk07A4, unk07A8, unk07AC, unk07B0, unk07B4, unk07B8, unk07BC, unk07C0, unk07C4;
    int unk07C8, unk07CC, unk07D0, unk07D4, unk07D8, unk07DC, unk07E0, unk07E4, unk07E8, unk07EC, unk07F0, unk07F4;
    int unk07F8, unk07FC, unk0800, unk0804, unk0808, unk080C, unk0810, unk0814, unk0818, unk081C, unk0820, unk0824;
    int unk0828, unk082C, unk0830, unk0834, unk0838, unk083C, unk0840, unk0844, unk0848, unk084C, unk0850, unk0854;
    int unk0858, unk085C, unk0860, unk0864, unk0868, unk086C, unk0870, unk0874, unk0878, unk087C, unk0880, unk0884;
    int unk0888, unk088C, unk0890, unk0894, unk0898, unk089C, unk08A0, unk08A4, unk08A8, unk08AC, unk08B0, unk08B4;
    int unk08B8, unk08BC, unk08C0, unk08C4, unk08C8, unk08CC, unk08D0, unk08D4, unk08D8, unk08DC, unk08E0, unk08E4;
    int unk08E8, unk08EC, unk08F0, unk08F4, unk08F8, unk08FC, unk0900, unk0904, unk0908, unk090C, unk0910, unk0914;
    int unk0918, unk091C, unk0920, unk0924, unk0928, unk092C, unk0930, unk0934, unk0938, unk093C, unk0940, unk0944;
    int unk0948, unk094C, unk0950, unk0954, unk0958, unk095C, unk0960, unk0964, unk0968, unk096C, unk0970, unk0974;
    int unk0978, unk097C, unk0980, unk0984, unk0988, unk098C, unk0990, unk0994, unk0998, unk099C, unk09A0, unk09A4;
    int unk09A8, unk09AC, unk09B0, unk09B4, unk09B8, unk09BC, unk09C0, unk09C4, unk09C8, unk09CC, unk09D0, unk09D4;
    int unk09D8, unk09DC, unk09E0, unk09E4, unk09E8, unk09EC, unk09F0, unk09F4, unk09F8, unk09FC, unk0A00, unk0A04;
    int unk0A08, unk0A0C, unk0A10, unk0A14, unk0A18, unk0A1C, unk0A20, unk0A24, unk0A28, unk0A2C, unk0A30, unk0A34;
    int unk0A38, unk0A3C, unk0A40, unk0A44, unk0A48, unk0A4C, unk0A50, unk0A54, unk0A58, unk0A5C, unk0A60, unk0A64;
    int unk0A68, unk0A6C, unk0A70, unk0A74, unk0A78, unk0A7C, unk0A80, unk0A84, unk0A88, unk0A8C, unk0A90, unk0A94;
    int unk0A98, unk0A9C, unk0AA0, unk0AA4, unk0AA8, unk0AAC, unk0AB0, unk0AB4, unk0AB8, unk0ABC, unk0AC0, unk0AC4;
    int unk0AC8, unk0ACC, unk0AD0, unk0AD4, unk0AD8, unk0ADC, unk0AE0, unk0AE4, unk0AE8, unk0AEC, unk0AF0, unk0AF4;
    int unk0AF8, unk0AFC, unk0B00, unk0B04, unk0B08, unk0B0C, unk0B10, unk0B14, unk0B18, unk0B1C, unk0B20, unk0B24;
    int unk0B28, unk0B2C, unk0B30, unk0B34, unk0B38, unk0B3C, unk0B40, unk0B44, unk0B48, unk0B4C, unk0B50, unk0B54;
    int unk0B58, unk0B5C, unk0B60, unk0B64, unk0B68, unk0B6C, unk0B70, unk0B74, unk0B78, unk0B7C, unk0B80, unk0B84;
    int unk0B88, unk0B8C, unk0B90, unk0B94, unk0B98, unk0B9C, unk0BA0, unk0BA4, unk0BA8, unk0BAC, unk0BB0, unk0BB4;
    int unk0BB8, unk0BBC, unk0BC0, unk0BC4, unk0BC8, unk0BCC, unk0BD0, unk0BD4, unk0BD8, unk0BDC, unk0BE0, unk0BE4;
    int unk0BE8, unk0BEC, unk0BF0, unk0BF4, unk0BF8, unk0BFC, unk0C00, unk0C04, unk0C08, unk0C0C, unk0C10, unk0C14;
    int unk0C18, unk0C1C, unk0C20, unk0C24, unk0C28, unk0C2C, unk0C30, unk0C34, unk0C38, unk0C3C, unk0C40, unk0C44;
    int unk0C48, unk0C4C, unk0C50, unk0C54, unk0C58, unk0C5C, unk0C60, unk0C64, unk0C68, unk0C6C, unk0C70, unk0C74;
    int unk0C78, unk0C7C, unk0C80, unk0C84, unk0C88, unk0C8C, unk0C90, unk0C94, unk0C98, unk0C9C, unk0CA0, unk0CA4;
    int unk0CA8, unk0CAC, unk0CB0, unk0CB4, unk0CB8, unk0CBC, unk0CC0, unk0CC4, unk0CC8, unk0CCC, unk0CD0, unk0CD4;
    int unk0CD8, unk0CDC, unk0CE0, unk0CE4, unk0CE8, unk0CEC, unk0CF0, unk0CF4, unk0CF8, unk0CFC, unk0D00, unk0D04;
    int unk0D08, unk0D0C, unk0D10, unk0D14, unk0D18, unk0D1C, unk0D20, unk0D24, unk0D28, unk0D2C, unk0D30, unk0D34;
    int unk0D38, unk0D3C, unk0D40, unk0D44, unk0D48, unk0D4C, unk0D50, unk0D54, unk0D58, unk0D5C, unk0D60, unk0D64;
    int unk0D68, unk0D6C, unk0D70, unk0D74, unk0D78, unk0D7C, unk0D80, unk0D84, unk0D88, unk0D8C, unk0D90, unk0D94;
    int unk0D98, unk0D9C, unk0DA0, unk0DA4, unk0DA8, unk0DAC, unk0DB0, unk0DB4, unk0DB8, unk0DBC, unk0DC0, unk0DC4;
    int unk0DC8, unk0DCC, unk0DD0, unk0DD4, unk0DD8, unk0DDC, unk0DE0, unk0DE4, unk0DE8, unk0DEC, unk0DF0, unk0DF4;
    int unk0DF8, unk0DFC, unk0E00, unk0E04, unk0E08, unk0E0C, unk0E10, unk0E14, unk0E18, unk0E1C, unk0E20, unk0E24;
    int unk0E28, unk0E2C, unk0E30, unk0E34, unk0E38, unk0E3C, unk0E40, unk0E44, unk0E48, unk0E4C, unk0E50, unk0E54;
    int unk0E58, unk0E5C, unk0E60, unk0E64, unk0E68, unk0E6C, unk0E70, unk0E74, unk0E78, unk0E7C, unk0E80, unk0E84;
    int unk0E88, unk0E8C, unk0E90, unk0E94, unk0E98, unk0E9C, unk0EA0, unk0EA4, unk0EA8, unk0EAC, unk0EB0, unk0EB4;
    int unk0EB8, unk0EBC, unk0EC0, unk0EC4, unk0EC8, unk0ECC, unk0ED0, unk0ED4, unk0ED8, unk0EDC, unk0EE0, unk0EE4;
    int unk0EE8, unk0EEC, unk0EF0, unk0EF4, unk0EF8, unk0EFC, unk0F00, unk0F04, unk0F08, unk0F0C, unk0F10, unk0F14;
    int unk0F18, unk0F1C, unk0F20, unk0F24, unk0F28, unk0F2C, unk0F30, unk0F34, unk0F38, unk0F3C, unk0F40, unk0F44;
    int unk0F48, unk0F4C, unk0F50, unk0F54, unk0F58, unk0F5C, unk0F60, unk0F64, unk0F68, unk0F6C, unk0F70, unk0F74;
    int unk0F78, unk0F7C, unk0F80, unk0F84, unk0F88, unk0F8C, unk0F90, unk0F94, unk0F98, unk0F9C, unk0FA0, unk0FA4;
    int unk0FA8, unk0FAC, unk0FB0, unk0FB4, unk0FB8, unk0FBC, unk0FC0, unk0FC4, unk0FC8, unk0FCC, unk0FD0, unk0FD4;
    int unk0FD8, unk0FDC, unk0FE0, unk0FE4, unk0FE8, unk0FEC, unk0FF0, unk0FF4, unk0FF8, unk0FFC, unk1000, unk1004;
    int unk1008, unk100C, unk1010, unk1014, unk1018, unk101C, unk1020, unk1024, unk1028, unk102C, unk1030, unk1034;
    int unk1038, unk103C, unk1040, unk1044, unk1048, unk104C, unk1050, unk1054, unk1058, unk105C, unk1060, unk1064;
    int unk1068, unk106C, unk1070, unk1074, unk1078, unk107C, unk1080, unk1084, unk1088, unk108C, unk1090, unk1094;
    int unk1098, unk109C, unk10A0, unk10A4, unk10A8, unk10AC, unk10B0, unk10B4, unk10B8, unk10BC, unk10C0, unk10C4;
    int unk10C8, unk10CC, unk10D0, unk10D4, unk10D8, unk10DC, unk10E0, unk10E4, unk10E8, unk10EC, unk10F0, unk10F4;
    int unk10F8, unk10FC, unk1100, unk1104, unk1108, unk110C, unk1110, unk1114, unk1118, unk111C, unk1120, unk1124;
    int unk1128, unk112C, unk1130, unk1134, unk1138, unk113C, unk1140, unk1144, unk1148, unk114C, unk1150, unk1154;
    int unk1158, unk115C, unk1160, unk1164, unk1168, unk116C, unk1170, unk1174, unk1178, unk117C, unk1180, unk1184;
    int unk1188, unk118C, unk1190, unk1194, unk1198, unk119C, unk11A0, unk11A4, unk11A8, unk11AC, unk11B0, unk11B4;
    int unk11B8, unk11BC, unk11C0, unk11C4, unk11C8, unk11CC, unk11D0, unk11D4, unk11D8, unk11DC, unk11E0, unk11E4;
    int unk11E8, unk11EC, unk11F0, unk11F4, unk11F8, unk11FC, unk1200, unk1204, unk1208, unk120C, unk1210, unk1214;
    int unk1218, unk121C, unk1220, unk1224, unk1228, unk122C, unk1230, unk1234, unk1238, unk123C, unk1240, unk1244;
    int unk1248, unk124C, unk1250, unk1254, unk1258, unk125C, unk1260, unk1264, unk1268, unk126C, unk1270, unk1274;
    int unk1278, unk127C, unk1280, unk1284, unk1288, unk128C, unk1290, unk1294, unk1298, unk129C, unk12A0, unk12A4;
    int unk12A8, unk12AC, unk12B0, unk12B4, unk12B8, unk12BC, unk12C0, unk12C4, unk12C8, unk12CC, unk12D0, unk12D4;
    int unk12D8, unk12DC, unk12E0, unk12E4, unk12E8, unk12EC, unk12F0, unk12F4, unk12F8, unk12FC, unk1300, unk1304;
    int unk1308, unk130C, unk1310, unk1314, unk1318, unk131C, unk1320, unk1324, unk1328, unk132C, unk1330, unk1334;
    int unk1338, unk133C, unk1340, unk1344, unk1348, unk134C, unk1350, unk1354, unk1358, unk135C, unk1360, unk1364;
    int unk1368, unk136C, unk1370, unk1374, unk1378, unk137C, unk1380, unk1384, unk1388, unk138C, unk1390, unk1394;
    int unk1398, unk139C, unk13A0, unk13A4, unk13A8, unk13AC, unk13B0, unk13B4, unk13B8, unk13BC, unk13C0, unk13C4;
    int unk13C8, unk13CC, unk13D0, unk13D4, unk13D8, unk13DC, unk13E0, unk13E4, unk13E8, unk13EC, unk13F0, unk13F4;
    int unk13F8, unk13FC, unk1400, unk1404, unk1408, unk140C, unk1410, unk1414, unk1418, unk141C, unk1420, unk1424;
    int unk1428, unk142C, unk1430, unk1434, unk1438, unk143C, unk1440, unk1444, unk1448, unk144C, unk1450, unk1454;
    int unk1458, unk145C, unk1460, unk1464, unk1468, unk146C, unk1470, unk1474, unk1478, unk147C, unk1480, unk1484;
    int unk1488, unk148C, unk1490, unk1494, unk1498, unk149C, unk14A0, unk14A4, unk14A8, unk14AC, unk14B0, unk14B4;
    int unk14B8, unk14BC, unk14C0, unk14C4, unk14C8, unk14CC, unk14D0, unk14D4, unk14D8, unk14DC, unk14E0, unk14E4;
    int unk14E8, unk14EC, unk14F0, unk14F4, unk14F8, unk14FC, unk1500, unk1504, unk1508, unk150C, unk1510, unk1514;
    int unk1518, unk151C, unk1520, unk1524, unk1528, unk152C, unk1530, unk1534, unk1538, unk153C, unk1540, unk1544;
    int unk1548, unk154C, unk1550, unk1554, unk1558, unk155C, unk1560, unk1564, unk1568, unk156C, unk1570, unk1574;
    int unk1578, unk157C, unk1580, unk1584, unk1588, unk158C, unk1590, unk1594, unk1598, unk159C, unk15A0, unk15A4;
    int unk15A8, unk15AC, unk15B0, unk15B4, unk15B8, unk15BC, unk15C0, unk15C4, unk15C8, unk15CC, unk15D0, unk15D4;
    int unk15D8, unk15DC, unk15E0, unk15E4, unk15E8, unk15EC, unk15F0, unk15F4, unk15F8, unk15FC, unk1600, unk1604;
    int unk1608, unk160C, unk1610, unk1614, unk1618, unk161C, unk1620, unk1624, unk1628, unk162C, unk1630, unk1634;
    int unk1638, unk163C, unk1640, unk1644, unk1648, unk164C, unk1650, unk1654, unk1658, unk165C, unk1660, unk1664;
    int unk1668, unk166C, unk1670, unk1674, unk1678, unk167C, unk1680, unk1684, unk1688, unk168C, unk1690, unk1694;
    int unk1698, unk169C, unk16A0, unk16A4, unk16A8, unk16AC, unk16B0, unk16B4, unk16B8, unk16BC, unk16C0, unk16C4;
    int unk16C8, unk16CC, unk16D0, unk16D4, unk16D8, unk16DC, unk16E0, unk16E4, unk16E8, unk16EC, unk16F0, unk16F4;
    int unk16F8, unk16FC, unk1700, unk1704, unk1708, unk170C, unk1710, unk1714, unk1718, unk171C, unk1720, unk1724;
    int unk1728, unk172C, unk1730, unk1734, unk1738, unk173C, unk1740, unk1744, unk1748, unk174C, unk1750, unk1754;
    int unk1758, unk175C, unk1760, unk1764, unk1768, unk176C, unk1770, unk1774, unk1778, unk177C, unk1780, unk1784;
    int unk1788, unk178C, unk1790, unk1794, unk1798, unk179C, unk17A0, unk17A4, unk17A8, unk17AC, unk17B0, unk17B4;
    int unk17B8, unk17BC, unk17C0, unk17C4, unk17C8, unk17CC, unk17D0, unk17D4, unk17D8, unk17DC, unk17E0, unk17E4;
    int unk17E8, unk17EC, unk17F0, unk17F4, unk17F8, unk17FC, unk1800, unk1804, unk1808, unk180C, unk1810, unk1814;
    int unk1818, unk181C, unk1820, unk1824, unk1828, unk182C, unk1830, unk1834, unk1838, unk183C, unk1840, unk1844;
    int unk1848, unk184C, unk1850, unk1854, unk1858, unk185C, unk1860, unk1864, unk1868, unk186C, unk1870, unk1874;
    int unk1878, unk187C, unk1880, unk1884, unk1888, unk188C, unk1890, unk1894, unk1898, unk189C, unk18A0, unk18A4;
    int unk18A8, unk18AC, unk18B0, unk18B4, unk18B8, unk18BC, unk18C0, unk18C4, unk18C8, unk18CC, unk18D0, unk18D4;
    int unk18D8, unk18DC, unk18E0, unk18E4, unk18E8, unk18EC, unk18F0, unk18F4, unk18F8, unk18FC, unk1900, unk1904;
    int unk1908, unk190C, unk1910, unk1914, unk1918, unk191C, unk1920, unk1924, unk1928, unk192C, unk1930, unk1934;
    int unk1938, unk193C, unk1940, unk1944, unk1948, unk194C, unk1950, unk1954, unk1958, unk195C, unk1960, unk1964;
    int unk1968, unk196C, unk1970, unk1974, unk1978, unk197C, unk1980, unk1984, unk1988, unk198C, unk1990, unk1994;
    int unk1998, unk199C, unk19A0, unk19A4, unk19A8, unk19AC, unk19B0, unk19B4, unk19B8, unk19BC, unk19C0, unk19C4;
    int unk19C8, unk19CC, unk19D0, unk19D4, unk19D8, unk19DC, unk19E0, unk19E4, unk19E8, unk19EC, unk19F0, unk19F4;
    int unk19F8, unk19FC, unk1A00, unk1A04, unk1A08, unk1A0C, unk1A10, unk1A14, unk1A18, unk1A1C, unk1A20, unk1A24;
    int unk1A28, unk1A2C, unk1A30, unk1A34, unk1A38, unk1A3C, unk1A40, unk1A44, unk1A48, unk1A4C, unk1A50, unk1A54;
    int unk1A58, unk1A5C, unk1A60, unk1A64, unk1A68, unk1A6C, unk1A70, unk1A74, unk1A78, unk1A7C, unk1A80, unk1A84;
    int unk1A88, unk1A8C, unk1A90, unk1A94, unk1A98, unk1A9C, unk1AA0, unk1AA4, unk1AA8, unk1AAC, unk1AB0, unk1AB4;
    int unk1AB8, unk1ABC, unk1AC0, unk1AC4, unk1AC8, unk1ACC, unk1AD0, unk1AD4, unk1AD8, unk1ADC, unk1AE0, unk1AE4;
    int unk1AE8, unk1AEC, unk1AF0, unk1AF4, unk1AF8, unk1AFC, unk1B00, unk1B04, unk1B08, unk1B0C, unk1B10, unk1B14;
    int unk1B18, unk1B1C, unk1B20, unk1B24, unk1B28, unk1B2C, unk1B30, unk1B34, unk1B38, unk1B3C, unk1B40, unk1B44;
    int unk1B48, unk1B4C, unk1B50, unk1B54, unk1B58, unk1B5C, unk1B60, unk1B64, unk1B68, unk1B6C, unk1B70, unk1B74;
    int unk1B78, unk1B7C, unk1B80, unk1B84, unk1B88, unk1B8C, unk1B90, unk1B94, unk1B98, unk1B9C, unk1BA0, unk1BA4;
    int unk1BA8, unk1BAC, unk1BB0, unk1BB4, unk1BB8, unk1BBC, unk1BC0, unk1BC4, unk1BC8, unk1BCC, unk1BD0, unk1BD4;
    int unk1BD8, unk1BDC, unk1BE0, unk1BE4, unk1BE8, unk1BEC, unk1BF0, unk1BF4, unk1BF8, unk1BFC, unk1C00, unk1C04;
    int unk1C08, unk1C0C, unk1C10, unk1C14, unk1C18, unk1C1C, unk1C20, unk1C24, unk1C28, unk1C2C, unk1C30, unk1C34;
    int unk1C38, unk1C3C, unk1C40, unk1C44, unk1C48, unk1C4C, unk1C50, unk1C54, unk1C58, unk1C5C, unk1C60, unk1C64;
    int unk1C68, unk1C6C, unk1C70, unk1C74, unk1C78, unk1C7C, unk1C80, unk1C84, unk1C88, unk1C8C, unk1C90, unk1C94;
    int unk1C98, unk1C9C, unk1CA0, unk1CA4, unk1CA8, unk1CAC, unk1CB0, unk1CB4, unk1CB8, unk1CBC, unk1CC0, unk1CC4;
    int unk1CC8, unk1CCC, unk1CD0, unk1CD4, unk1CD8, unk1CDC, unk1CE0, unk1CE4, unk1CE8, unk1CEC, unk1CF0, unk1CF4;
    int unk1CF8, unk1CFC, unk1D00, unk1D04, unk1D08, unk1D0C, unk1D10, unk1D14, unk1D18, unk1D1C, unk1D20, unk1D24;
    int unk1D28, unk1D2C, unk1D30, unk1D34, unk1D38, unk1D3C, unk1D40, unk1D44, unk1D48, unk1D4C, unk1D50, unk1D54;
    int unk1D58, unk1D5C, unk1D60, unk1D64, unk1D68, unk1D6C, unk1D70, unk1D74, unk1D78, unk1D7C, unk1D80, unk1D84;
    int unk1D88, unk1D8C, unk1D90, unk1D94, unk1D98, unk1D9C, unk1DA0, unk1DA4, unk1DA8, unk1DAC, unk1DB0, unk1DB4;
    int unk1DB8, unk1DBC, unk1DC0, unk1DC4, unk1DC8, unk1DCC, unk1DD0, unk1DD4, unk1DD8, unk1DDC, unk1DE0, unk1DE4;
    int unk1DE8, unk1DEC, unk1DF0, unk1DF4, unk1DF8, unk1DFC, unk1E00, unk1E04, unk1E08, unk1E0C, unk1E10, unk1E14;
    int unk1E18, unk1E1C, unk1E20, unk1E24, unk1E28, unk1E2C, unk1E30, unk1E34, unk1E38, unk1E3C, unk1E40, unk1E44;
    int unk1E48, unk1E4C, unk1E50, unk1E54, unk1E58, unk1E5C, unk1E60, unk1E64, unk1E68, unk1E6C, unk1E70, unk1E74;
    int unk1E78, unk1E7C, unk1E80, unk1E84, unk1E88, unk1E8C, unk1E90, unk1E94, unk1E98, unk1E9C, unk1EA0, unk1EA4;
    int unk1EA8, unk1EAC, unk1EB0, unk1EB4, unk1EB8, unk1EBC, unk1EC0, unk1EC4, unk1EC8, unk1ECC, unk1ED0, unk1ED4;
    int unk1ED8, unk1EDC, unk1EE0, unk1EE4, unk1EE8, unk1EEC, unk1EF0, unk1EF4, unk1EF8, unk1EFC, unk1F00, unk1F04;
    int unk1F08, unk1F0C, unk1F10, unk1F14, unk1F18, unk1F1C, unk1F20, unk1F24, unk1F28, unk1F2C, unk1F30, unk1F34;
    int unk1F38, unk1F3C, unk1F40, unk1F44, unk1F48, unk1F4C, unk1F50, unk1F54, unk1F58, unk1F5C, unk1F60, unk1F64;
    int unk1F68, unk1F6C, unk1F70, unk1F74, unk1F78, unk1F7C, unk1F80, unk1F84, unk1F88, unk1F8C, unk1F90, unk1F94;
    int unk1F98, unk1F9C, unk1FA0, unk1FA4, unk1FA8, unk1FAC, unk1FB0, unk1FB4, unk1FB8, unk1FBC, unk1FC0, unk1FC4;
    int unk1FC8, unk1FCC, unk1FD0, unk1FD4, unk1FD8, unk1FDC, unk1FE0, unk1FE4, unk1FE8, unk1FEC, unk1FF0;
    FUN_00483710 m_kListB;
};

// Empty destructor body; member m_kListB is destroyed implicitly.
// @fnv 0x006b8e40
FUN_006b8e40::~FUN_006b8e40()
{}
}

extern int DAT_0106c324;
struct SandBoxChoiceListItem;
// @fnv 0x006bf870
// src: GUESS 0x006bf870 (confidence: low)
void __thiscall FUN_006bf870_class::SetVtableAndProcessState_006bf870()
{
    *(int**)this = &DAT_0106c324;
    reinterpret_cast<BSSimpleArray<SandBoxChoiceListItem>*>(this)->Clear(true);
}

void* __cdecl operator new(unsigned int uiSize, void* pvMem);
void __cdecl operator delete(void* pvObject, void* pvMem);

struct B6BFDD0Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;

    B6BFDD0Entry();
};

class B6BFDD0Allocator
{
  public:
    void ConstructEntries(B6BFDD0Entry* pkArray, unsigned int ItemUpdateArray);
};

// @fnv 0x006bfdd0
void B6BFDD0Allocator::ConstructEntries(B6BFDD0Entry* pkArray, unsigned int ItemUpdateArray)
{
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        new (&pkArray[i]) B6BFDD0Entry;
}

namespace fnv_006ac8b0 {
extern double DAT_01032980;
extern double DAT_01020758;
extern float DAT_0106b158;
extern int DAT_011a9484;




struct PtAll
{
    float x, y, z;
    Point3Storage& Subtract(const Point3Storage& o);
    float FUN_00457990();
    Point3Storage FUN_0053d1a0(void* p);
};
struct PtOp
{
    float x, y, z;
    Point3Storage operator-(const Point3Storage& o) const;
    Point3Storage operator+(const Point3Storage& o) const;
};
struct PtMul
{
    float x, y, z;
    Point3Storage operator*(float s) const;
    PtMul& operator*=(float s);
};
struct FUN_0063c8a0_shell
{
    Point3Storage* ComputeValue_0063c8a0(void* p);
};











namespace Pathing {
class CheckLineOfSightFilter;
}
bool __cdecl Pathing_CheckLineOfSight(PathingLocation& a, PathingLocation& bTmp, PathingLocation* c,
                          Pathing::CheckLineOfSightFilter* d);
float __cdecl NiSqrt_004579e0(float f);

struct Host
{
    char pad0[0x20a4];
    PathingLocation m_20a4;
    char pad20cc[0x20d8 - 0x20cc];
    Point3Storage m_20d8;
    Point3Storage m_20e4;
    float m_20f0;
    float m_20f4;
    float m_20f8;
    float m_20fc;
    bool NavMeshSearchSLPoint_CheckPointOnGoalCircle(Point3Storage* a1, Point3Storage* a2, NavMesh* a3, Point3Storage* a4);
};

// Derives points from a1 and a2, requires several FUN_006d7350 checks between PathingLocations to pass, adjusts the point's height, and writes it to a4.
// @fnv 0x006ac8b0
// src: COMMUNITY 0x006ac8b0
bool Host::NavMeshSearchSLPoint_CheckPointOnGoalCircle(Point3Storage* a1, Point3Storage* a2, NavMesh* apNavMesh, Point3Storage* apResult)
{
    Point3Storage y;
    y = *a1;
    ((PtAll&)y).Subtract(*a2);
    float p;
    p = ((PtAll&)y).FUN_00457990();
    if (p < DAT_01032980)
    {
        y = *a1;
        y.x = y.x + DAT_01020758;
        ((PtAll&)y).Subtract(*a2);
        p = ((PtAll&)y).FUN_00457990();
    }
    float factor;
    float n;
    factor = this->m_20f4 / p;
    n = (this->m_20f4 + this->m_20fc) / p;
    Point3Storage hpt = ((PtMul&)y) * factor;
    this->m_20e4 = ((PtMul&)y) * n;
    Point3Storage s;
    s = *a2;
    ((FUN_0063c8a0_shell&)hpt).ComputeValue_0063c8a0(a2);
    ((FUN_0063c8a0_shell&)this->m_20e4).ComputeValue_0063c8a0(a2);
    this->m_20d8 = ((PtAll&)y).FUN_0053d1a0((void*)&DAT_011a9484);
    Point3Storage ptr = ((PtMul&)this->m_20d8) * this->m_20fc;
    PathingLocation plA(reinterpret_cast<const NiPoint3&>(this->m_20e4), apNavMesh->GetNavMeshInfo_0068efb0());
    PathingLocation o138(reinterpret_cast<const NiPoint3&>(s), this->m_20a4);
    if (!Pathing_CheckLineOfSight(plA, *(PathingLocation*)&o138, 0, 0))
        return false;
    PathingLocation o110(reinterpret_cast<const NiPoint3&>((((PtOp&)this->m_20e4) - ptr)), plA);
    PathingLocation odc(reinterpret_cast<const NiPoint3&>((((PtOp&)s) - ptr)), o138);
    if (!Pathing_CheckLineOfSight(*(PathingLocation*)&o110, *(PathingLocation*)&odc, 0, 0))
        return false;
    PathingLocation o6c(reinterpret_cast<const NiPoint3&>((((PtOp&)this->m_20e4) + ptr)), plA);
    PathingLocation dst6(reinterpret_cast<const NiPoint3&>((((PtOp&)s) + ptr)), o138);
    if (!Pathing_CheckLineOfSight(*(PathingLocation*)&o6c, *(PathingLocation*)&dst6, 0, 0))
        return false;
    {
        PathingLocation ob4Cur(reinterpret_cast<const NiPoint3&>(hpt), plA);
        NavMeshPtr b171Tmp;
        float sq2Info;
        unsigned short cellRes;
        bool bTmp;
        bTmp = ob4Cur.FUN_006dd640(&b171Tmp, &cellRes);
        if (!bTmp)
            return false;
        bool j;
        j = b171Tmp.Modelloader_GetReferencedThis(cellRes, reinterpret_cast<NiPoint3*>(&hpt), &sq2Info, DAT_0106b158, DAT_0106b158)->FUN_00697730();
        if (DAT_01012060 > sq2Info && (s.z - this->m_20e4.z) > DAT_01012060)
        {
            Point3Storage kTheIter;
            kTheIter = *a2;
            ((PtAll&)kTheIter).Subtract(hpt);
            float bok;
            bok = ((PtAll&)kTheIter).FUN_00457990();
            float a;
            a = (bok - this->m_20f8) - this->m_20fc;
            ((PtMul&)kTheIter) *= (a / bok);
            Point3Storage vTmp = ((PtOp&)hpt) + kTheIter;
            NiPoint2 ni2Tmp(kTheIter.x, kTheIter.y);
            float i;
            float pt2;
            i = ni2Tmp.NormalizeXY();
            pt2 = a * a;
            float idx;
            idx = vTmp.z - (hpt.z + sq2Info);
            idx = idx * idx;
            if (idx > pt2)
                return false;
            float x;
            x = pt2 - idx;
            x = NiSqrt_004579e0(x);
            if (x >= i)
                return false;
            float pObjStep;
            pObjStep = i - x;
            ni2Tmp.Scale(pObjStep);
            hpt.x += ni2Tmp.x;
            hpt.y += ni2Tmp.y;
        }
        hpt.z += sq2Info;
        *apResult = hpt;
    }
    return true;
}
}  // namespace fnv_006ac8b0

namespace fnv_006a3580 {
struct FUN_0045cec0
{
    void* object;
    ~FUN_0045cec0();
    FUN_0045cec0& FUN_0066b0d0(void*);
};
struct FUN_006a6450
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ~FUN_006a6450();
};
struct FUN_006a6550
{
    int unk00;
    ~FUN_006a6550();
};
struct FUN_006a3580
{
    FUN_0045cec0 unk00;
    FUN_0045cec0 unk04;
    FUN_0045cec0 unk08;
    FUN_0045cec0 slots0c[17];
    FUN_0045cec0 slots50[17];
    FUN_0045cec0 slots94[17];
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
    FUN_0045cec0 unk1e8;
    FUN_0045cec0 unk1ec;
    FUN_006a6450 unk1f0;
    FUN_006a6550 unk200;
    ~FUN_006a3580();
};
// Calls FUN_0066b0d0(0) on each of the 17 entries of slots50, slots94 and slots0c.
// @fnv 0x006a3580
FUN_006a3580::~FUN_006a3580()
{
    for (unsigned int i = 0; i < 17; i++)
    {
        slots50[i].FUN_0066b0d0(0);
        slots94[i].FUN_0066b0d0(0);
        slots0c[i].FUN_0066b0d0(0);
    }
}
}  // namespace fnv_006a3580

namespace fnv_006bfb90 {
struct FUN_006bfb90_shell
{
    int m_iWordAt00;
    unsigned short m_iWordAt04;
    int m_8;
    bool __thiscall AreValuesEqual_006bfb90(FUN_006bfb90_shell* other);
};

// @fnv 0x006bfb90
// src: GUESS 0x006bfb90 (confidence: medium)
bool __thiscall FUN_006bfb90_shell::AreValuesEqual_006bfb90(FUN_006bfb90_shell* other)
{
    return m_iWordAt00 == other->m_iWordAt00 && m_iWordAt04 == other->m_iWordAt04 && m_8 == other->m_8;
}
}  // namespace fnv_006bfb90
