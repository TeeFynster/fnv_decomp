// fallout_shared/pathfinding/navmesh_loadsave.cpp (34 functions)

#include <windows.h>
#include "../../../include/BSSimpleArray.h"
#include "../../../include/NiPointer.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESChildCell.h"
#include "../../../include/NiRefObject.h"
#include "../../../include/NavMeshGrid.h"
#include "../../../include/NiTMap.h"
#include "../../../include/BSSimpleArray.h"
#include "../../../include/NavMesh.h"
#include "../../../include/NavMeshPOVData.h"

struct EdgeT;
class AvoidSphere;
class b9_big;
class P3;

class EdgeExtraInfo;
class FindTriangleForLocationFilter;
class NavMeshClosedDoorInfo;
class NavMeshEdgeData;
class NavMeshEdgeExtra;
class NavMeshEdgeRef;
class NavMeshEdgeOut;
class NavMeshEdgeVertexPair;
class NavMeshInfo;
class NavEdgeHit;
class NavMeshTriList;
class NavMeshPtr;
class NavMeshStaticAvoidNode;
class NavMeshTriangle;
class NavMeshTriangleDoorPortal;
class NavMeshVertex;
class ObstacleData;
class ObstacleUndoData;
class OutArr;
class ParentChildLinks;
class TESObjectCELL;


#include "../../../include/NavMeshInfoMap.h"
#include "../../../include/NavMeshTriangle.h"
#include "../../../include/EDGE_EXTRA_INFO_TYPE.h"
#include "../../../include/TESObjectREFR.h"

template <> void BSSimpleArray<NavMeshVertex, 1024>::SetSize(unsigned int, bool);
template <> void BSSimpleArray<NavMeshTriangle, 1024>::SetSize(unsigned int, bool);
template <> void BSSimpleArray<NavMeshTriangleDoorPortal, 1024>::SetSize(unsigned int, bool);
template <> template <>
void BSSimpleArray<NavMeshVertex, 1024>::CopyTo<1024>(BSSimpleArray<NavMeshVertex, 1024>*);
template <> template <>
void BSSimpleArray<NavMeshTriangle, 1024>::CopyTo<1024>(BSSimpleArray<NavMeshTriangle, 1024>*);

// This unit contains the /Od copy of the unsigned-short array copy helper.
template <> template <>
void BSSimpleArray<unsigned short, 1024>::CopyTo<1024>(BSSimpleArray<unsigned short, 1024>*);

class NavMeshVertex
{
  public:
    NiPoint3 Location;
};

class NavMeshInfoTriangleReference
{
  public:
    NavMeshInfo* m_pNavMeshInfo;
    unsigned short m_usTriangleIdentifier;
    unsigned char layoutPadding6[2];
};

class EdgeExtraInfo
{
  public:
    EDGE_EXTRA_INFO_TYPE eType;
    NavMeshInfoTriangleReference Portal;
};

class NavMeshTriangleDoorPortal
{
  public:
    TESObjectREFR* NavMeshDoorPortalData;
    unsigned short m_usDoorPortalIndex;
    unsigned char layoutPadding6[2];
};

#include "../../../include/BGSReconstructFormsInAllFilesMap.h"
class NavMeshObstacleMap : public BGSReconstructFormsInAllFilesMap
{
  public:
    void NiTMapBase_DFALL_NiTMapItem_unsigned_short_NiPointer_ObstacleData_unsigned_short_NiPointer_ObstacleData_GetNext(void*&, unsigned short&, NiPointer<ObstacleData>&);
    void NiTMapBase_DFALL_NiTMapItem_unsigned_short_NiPointer_NavMeshObstacleData_unsigned_short_NiPointer_NavMeshObstacleData_SetAt(unsigned short, NiPointer<ObstacleData>);
};
class NavMeshPOVMap : public BGSReconstructFormsInAllFilesMap
{
  public:
    void NiTMapBase_DFALL_NiTMapItem_unsigned_short_NavMeshPOVData_unsigned_short_NavMeshPOVData_GetNext(void*&, unsigned short&, NavMeshPOVData&);
    void InsertOrUpdate(unsigned short, NavMeshPOVData);
};
#include "../../../include/ActiveEffect.h"
#include "../../../include/AutoMemHelper.h"
#include "../../../include/AutoMemContext.h"
#include "../../../include/TESFile.h"
#include "../../../include/TESRecipe.h"
#include "../../../include/TES.h"
extern TES* g_TES;
#include "../../../include/TwoIntRecord.h"
#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/NavMeshPtr.h"
#include "../../../include/TESObjectCELL.h"
#include "../../../include/TESDataHandler.h"

// Public PC annotation: JohnnyGuitar TESForm.cpp, GAME 0x693EF0.
// @fnv 0x00693ef0
void TESForm::SetCollisionDisabled(bool noCollision)
{
    if (noCollision)
        iFormFlags |= 0x10;
    else
        iFormFlags &= ~0x10;
}

// TESForm/NavMesh PC slot 74 both bind the base SetRefID body to 00485c10.
// @fnv 0x006942c0
void NavMesh::ForceSetFormID(unsigned int formID)
{
    TESForm::SetRefID(formID, false);
}

// @fnv 0x00693e60
void NavMesh::InitItem()
{
    if (GetDisabled())
        ((TESForm*)GetNavMeshInfo_0068efb0())->SetCollisionDisabled(true);
    if (IsDeleted())
    {
        bool altered = g_TES->GetActiveCell()->FUN_00460340();
        SetDeletionState(false);
        g_TES->GetActiveCell()->SetAltered(altered);
    }
    else
        InitializeNavMeshData();
}

// @fnv 0x006942e0
void NavMesh::CopyNavMeshDataTo(NavMeshPtr& copy)
{
    static_cast<const NavMeshPtr&>(copy)->m_pOwningCell = m_pOwningCell;
    Vertices.CopyTo(&static_cast<const NavMeshPtr&>(copy)->Vertices);
    Triangles.CopyTo(&static_cast<const NavMeshPtr&>(copy)->Triangles);
    m_kEdgeExtraInfo.CopyTo(&static_cast<const NavMeshPtr&>(copy)->m_kEdgeExtraInfo);
    m_kIndexList.CopyTo(&static_cast<const NavMeshPtr&>(copy)->m_kIndexList);
    m_kGrid.CopyTo_0069dd50(&static_cast<const NavMeshPtr&>(copy)->m_kGrid);
    m_kObstacleUndoData.CopyTo(&static_cast<const NavMeshPtr&>(copy)->m_kObstacleUndoData);
    m_kClosedDoorInfo.CopyTo(&static_cast<const NavMeshPtr&>(copy)->m_kClosedDoorInfo);
    void* pos = ((NavMeshObstacleMap*)pTriangleToObstacleMap)->GetFirstPos();
    while (pos)
    {
        unsigned short triangle;
        NiPointer<ObstacleData> m_spRegisteredObstacle(0);
        ((NavMeshObstacleMap*)pTriangleToObstacleMap)->NiTMapBase_DFALL_NiTMapItem_unsigned_short_NiPointer_ObstacleData_unsigned_short_NiPointer_ObstacleData_GetNext(pos, triangle, m_spRegisteredObstacle);
        ((NavMeshObstacleMap*)static_cast<const NavMeshPtr&>(copy)->pTriangleToObstacleMap)->NiTMapBase_DFALL_NiTMapItem_unsigned_short_NiPointer_NavMeshObstacleData_unsigned_short_NiPointer_NavMeshObstacleData_SetAt(triangle, m_spRegisteredObstacle);
    }
    pos = ((NavMeshPOVMap*)&POVPointerArray)->GetFirstPos();
    while (pos)
    {
        NavMeshPOVData POV;
        unsigned short key;
        ((NavMeshPOVMap*)&POVPointerArray)->NiTMapBase_DFALL_NiTMapItem_unsigned_short_NavMeshPOVData_unsigned_short_NavMeshPOVData_GetNext(pos, key, POV);
        ((NavMeshPOVMap*)&static_cast<const NavMeshPtr&>(copy)->POVPointerArray)->InsertOrUpdate(key, POV);
    }
    m_kAdditionalIndexList.CopyTo(&static_cast<const NavMeshPtr&>(copy)->m_kAdditionalIndexList);
    m_kAdditionalData.CopyTo(&static_cast<const NavMeshPtr&>(copy)->m_kAdditionalData);
    static_cast<const NavMeshPtr&>(copy)->m_pNavigationMesh = 0;
}

// @fnv 0x00693b70
bool NavMeshTriangle::HasFlag40()
{
    return (m_uiTriangleFlags & 0x40) != 0;
}

// @fnv 0x00693b90
// src: XBOX_PDB 0x00693b90
bool NavMeshTriangle::IsNoLargeCreature()
{
    return FUN_00691140(0x10);
}

extern unsigned int DAT_0106b0dc;

class GlobalObject_00869f00
{
  public:
    void Clear(bool);
};

// @fnv 0x00694e10
// src: GUESS 0x00694e10 (confidence: low)
void __fastcall NavmeshLoadsave_UpdateState_00694e10(GlobalObject_00869f00* pThis)
{
    *(unsigned int**)pThis = &DAT_0106b0dc;
    pThis->Clear(true);
}

struct E00694f20
{
    int a, b, c;
    void Assign(const E00694f20&);
};
struct DA00694f20
{
    int x;
    E00694f20* data;
    unsigned int count;
    E00694f20* Object_GetIndexedValue_006a1440(unsigned int);
    void BSSimpleArray_EdgeExtraInfo_1024_SetSize(unsigned int, int);
};
struct SA00694f20
{
    int x;
    E00694f20* data;
    unsigned int count;
    void BSSimpleArray_EdgeExtraInfo_1024_CopyTo_1024(DA00694f20* dest);
};
// @fnv 0x00694f20
// src: COMMUNITY 0x00694f20
void SA00694f20::BSSimpleArray_EdgeExtraInfo_1024_CopyTo_1024(DA00694f20* dest)
{
    dest->BSSimpleArray_EdgeExtraInfo_1024_SetSize(count, 1);
    for (unsigned int i = 0; i < count; i++)
        dest->Object_GetIndexedValue_006a1440(i)->Assign(data[i]);
}

// Resizes dest to this container's count and copies each element via GetAt.
// @fnv 0x00694f80
template <> template <>
void BSSimpleArray<unsigned short, 1024>::CopyTo<1024>(BSSimpleArray<unsigned short, 1024>* dest)
{
    dest->SetSize(iSize, true);
    for (unsigned int i = 0; i < iSize; i++)
        dest->GetAt(i) = pBuffer[i];
}

struct NN00694fe0
{
    int p;
    NN00694fe0& operator=(const NN00694fe0&);
};
struct DA00694fe0
{
    int x;
    NN00694fe0* data;
    unsigned int count;
    NN00694fe0& GetAt(unsigned int);
    void BSSimpleArray_NiPointer_1024_SetSize(unsigned int, int);
};
struct SA00694fe0
{
    int x;
    NN00694fe0* data;
    unsigned int count;
    void BSSimpleArray_NiPointer_ObstacleUndoData_1024_CopyTo_1024(DA00694fe0* dest);
};
// @fnv 0x00694fe0
// src: COMMUNITY 0x00694fe0
void SA00694fe0::BSSimpleArray_NiPointer_ObstacleUndoData_1024_CopyTo_1024(DA00694fe0* dest)
{
    dest->BSSimpleArray_NiPointer_1024_SetSize(count, 1);
    for (unsigned int i = 0; i < count; i++)
        dest->GetAt(i) = data[i];
}

struct DA00695040
{
    int x;
    TwoIntRecord* data;
    unsigned int count;
    TwoIntRecord* GetElement(unsigned int);
    void FUN_006950f0(unsigned int, int);
};
struct SA00695040
{
    int x;
    TwoIntRecord* data;
    unsigned int count;
    void BSSimpleArray_NavMeshClosedDoorInfo_1024_CopyTo_1024(DA00695040* dest);
};
// @fnv 0x00695040
// src: COMMUNITY 0x00695040
void SA00695040::BSSimpleArray_NavMeshClosedDoorInfo_1024_CopyTo_1024(DA00695040* dest)
{
    dest->FUN_006950f0(count, 1);
    for (unsigned int i = 0; i < count; i++)
        dest->GetElement(i)->FUN_FNVH(data[i]);
}

struct E006950d0
{
    int a;
    int b;
};
struct S006950d0
{
    int x;
    E006950d0* data;
    E006950d0* GetElement(unsigned int i);
};
// @fnv 0x006950d0
E006950d0* S006950d0::GetElement(unsigned int uiIndex)
{
    return &data[uiIndex];
}

struct Item00694c50
{
    Item00694c50* next;
    unsigned short key;
};
struct Map00694c50
{
    virtual void v0();
    virtual unsigned int KeyToHashIndex(unsigned short);
    virtual bool IsKeysEqual(unsigned short, unsigned short);
    virtual void SetValue(Item00694c50*, unsigned short, unsigned int);
    virtual void v10();
    virtual Item00694c50* NewItem();
    unsigned int size;
    Item00694c50** buckets;
    unsigned int count;
    void InsertOrUpdate(unsigned short key, unsigned int val);
};
// Looks up key in the hash bucket; updates the existing item's value or inserts a new item at the bucket head and increments count.
// @fnv 0x00694c50
void Map00694c50::InsertOrUpdate(unsigned short key, unsigned int auiValue)
{
    unsigned int uiIndex;
    unsigned int uiDepth;
    Item00694c50* pkItem;
    uiIndex = KeyToHashIndex(key);
    pkItem = buckets[uiIndex];
    uiDepth = 0;
    while (pkItem)
    {
        uiDepth++;
        if (IsKeysEqual(key, pkItem->key))
        {
            *(unsigned int*)((char*)pkItem + 6) = auiValue;
            return;
        }
        pkItem = pkItem->next;
    }
    pkItem = NewItem();
    SetValue(pkItem, key, auiValue);
    pkItem->next = buckets[uiIndex];
    buckets[uiIndex] = pkItem;
    count++;
}

struct Item00694d30
{
    Item00694d30* next;
    unsigned short key;
};
struct Map00694d30
{
    virtual void v0();
    virtual unsigned int KeyToHashIndex(unsigned short);
    unsigned int size;
    Item00694d30** buckets;
    void NiTMapBase_DFALL_NiTMapItem_unsigned_short_NavMeshPOVData_unsigned_short_NavMeshPOVData_GetNext(Item00694d30** pos, unsigned short* key, NavMeshPOVData* val);
};
// Reads the key and value of the entry at *pos, then advances *pos to the next entry or the next non-empty bucket, or null at the end.
// @fnv 0x00694d30
// src: COMMUNITY 0x00694d30
void Map00694d30::NiTMapBase_DFALL_NiTMapItem_unsigned_short_NavMeshPOVData_unsigned_short_NavMeshPOVData_GetNext(Item00694d30** pos, unsigned short* key, NavMeshPOVData* val)
{
    Item00694d30* pkItem = *pos;
    *key = pkItem->key;
    *val = *(NavMeshPOVData*)((char*)pkItem + 6);
    if (pkItem->next)
    {
        *pos = pkItem->next;
        return;
    }
    unsigned int uiIndex = KeyToHashIndex(pkItem->key);
    for (uiIndex = uiIndex + 1; uiIndex < size; uiIndex++)
    {
        pkItem = buckets[uiIndex];
        if (pkItem)
        {
            *pos = pkItem;
            return;
        }
    }
    *pos = 0;
}

// @fnv 0x00694e30
template <> template <>
void BSSimpleArray<NavMeshVertex, 1024>::CopyTo<1024>(BSSimpleArray<NavMeshVertex, 1024>* dest)
{
    dest->SetSize(iSize, true);
    for (unsigned int i = 0; i < iSize; i++)
        dest->Object_GetIndexedValue_006a1440(i) = pBuffer[i];
}

// @fnv 0x00694ea0
template <> template <>
void BSSimpleArray<NavMeshTriangle, 1024>::CopyTo<1024>(BSSimpleArray<NavMeshTriangle, 1024>* dest)
{
    dest->SetSize(iSize, true);
    for (unsigned int i = 0; i < iSize; i++)
        dest->GetAt(static_cast<int>(i)) = pBuffer[i];
}

// Clamps the unsigned short pointed to by a into the range [b, c].
// @fnv 0x00694660
void ClampUnsignedShort(unsigned short* pusValue, unsigned short usMin, unsigned short usMax)
{
    if (*pusValue > usMax)
        *pusValue = usMax;
    else if (*pusValue < usMin)
        *pusValue = usMin;
}

void __fastcall NavmeshLoadsave_UpdateState_00694e10(void*);
void _Deallocate(void*);

struct FUN_006950a0_shell
{
    void* FUN_006950a0(unsigned int flags);
};

// Calls FUN_00694e10 on this, frees this with _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x006950a0
void* FUN_006950a0_shell::FUN_006950a0(unsigned int flags)
{
    NavmeshLoadsave_UpdateState_00694e10(this);
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_00694b10 {
struct S5460
{
    void BSSimpleArray_NiPoint2_1024_ReallocateBuffer(unsigned int, unsigned int);
};
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_0072ba80_shell
{
    void FUN_0072ba80(void*, unsigned int);
};
struct FUN_00692320_shell
{
    void ConstructEntries(void*, unsigned int);
};
struct FUN_00694b10_shell
{
    void* vtbl;
    void* p;
    unsigned int allocated;
    unsigned int capacity;
    void BSSimpleArray_EdgeExtraInfo_1024_SetSize(unsigned int size, bool flag);
};
// @fnv 0x00694b10
// src: COMMUNITY 0x00694b10
void FUN_00694b10_shell::BSSimpleArray_EdgeExtraInfo_1024_SetSize(unsigned int size, bool abShrink)
{
    if (size == 0)
    {
        ((GlobalObject_00869f00*)this)->Clear(abShrink);
    }
    else if (size > capacity)
    {
        if (capacity == 0)
        {
            p = ((void*(__thiscall*)(void*, unsigned int))((void**)vtbl)[1])(this, size);
            capacity = size;
        }
        else
        {
            ((S5460*)this)->BSSimpleArray_NiPoint2_1024_ReallocateBuffer(size, allocated);
            capacity = size;
        }
        ((FUN_00692320_shell*)this)->ConstructEntries((char*)p + allocated * 0xc, size - allocated);
        allocated = size;
    }
    else if (size < allocated)
    {
        ((FUN_0072ba80_shell*)this)->FUN_0072ba80((char*)p + size * 0xc, allocated - size);
        allocated = size;
        if (abShrink && size <= capacity / 4)
        {
            ((S5460*)this)->BSSimpleArray_NiPoint2_1024_ReallocateBuffer(size, size);
            capacity = size;
        }
    }
    else
    {
        ((FUN_00692320_shell*)this)->ConstructEntries((char*)p + allocated * 0xc, size - allocated);
        allocated = size;
    }
}
}  // namespace fnv_00694b10

namespace fnv_006bc8e0 {
struct S006bebd0
{
    void NavMeshObstacleCutter_RemoveTrianglesFromNavMeshGrid();
};
struct InnerB006bc8e0
{
    char _0[0x10];
    unsigned int v10;
    char _1[4];
    unsigned int v18;
};
struct InnerA006bc8e0
{
    char _0[0x28];
    BSSimpleArray<NavMeshVertex, 1024> o28;
    BSSimpleArray<NavMeshTriangle, 1024> o38;
};
struct Host006bc8e0
{
    InnerA006bc8e0* p0;
    int _4;
    InnerB006bc8e0* p8;
    bool NavMeshObstacleCutter_ResetNavMeshFromObstacleUndoData(InnerA006bc8e0*, InnerB006bc8e0*);
};
// Stores the two inner pointers, calls FUN_006bebd0, then forwards b's v10 and v18 to the two sub-objects with flag 1 and returns true.
// @fnv 0x006bc8e0
// src: COMMUNITY 0x006bc8e0
bool Host006bc8e0::NavMeshObstacleCutter_ResetNavMeshFromObstacleUndoData(InnerA006bc8e0* pInnerA, InnerB006bc8e0* pInnerB)
{
    p0 = pInnerA;
    p8 = pInnerB;
    ((S006bebd0*)this)->NavMeshObstacleCutter_RemoveTrianglesFromNavMeshGrid();
    p0->o28.SetSize(p8->v10, true);
    p0->o38.SetSize(p8->v18, true);
    return true;
}
}  // namespace fnv_006bc8e0

// @fnv 0x00694090
void NavMesh::SetAltered(bool abVal)
{
    ((TESForm*)this)->TESForm::SetAltered(abVal);
    if (abVal && m_pOwningCell)
        m_pOwningCell->SetAltered(true);
}

struct FUN_00694620_shell : TESForm
{
    char _pad[0x104 - sizeof(TESForm)];
    TESForm* m_pNavigationMesh;
    void NavMesh_FinishLoadGameBGS(BGSLoadFormBuffer* apLoadGameBuffer);
};
// @fnv 0x00694620
// src: COMMUNITY 0x00694620
void FUN_00694620_shell::NavMesh_FinishLoadGameBGS(BGSLoadFormBuffer* apLoadGameBuffer)
{
    TESForm::Revert((unsigned int)apLoadGameBuffer);
    if (m_pNavigationMesh != 0)
        m_pNavigationMesh->SetCollisionDisabled(GetDisabled());
}

namespace fnv_00692950 {
struct NavMeshSaveDataHeader
{
    void Endian();
    unsigned int m_uiField0;
    unsigned int VertexCount;
    unsigned int GetTriangleTotal;
    unsigned int m_uiField3;
    unsigned int m_uiField4;
    unsigned int m_uiField5;
};
typedef char _sizecheck_NavMeshSaveStruct[sizeof(NavMeshSaveDataHeader) == 24 ? 1 : -1];
struct NavMeshInfoSaveData
{
    static unsigned int GetSaveSize();
    float m_fValue;
    NavMeshInfo* m_pNavMeshInfo;
    unsigned int m_uiDoorFormID;
    int m_iValue1;
    int m_iValue2;
    int m_iValue3;
    int m_iValue4;
    int m_iValue5;
    int m_iValue6;
    int PAD4_1;
    int PAD4_2;
    unsigned short m_usTriangleIdentifier;
    char _pad_2e[2];
};
typedef char _sizecheck_EdgeExtraInfoOLD[sizeof(NavMeshInfoSaveData) == 48 ? 1 : -1];
struct FUN_00692950_shell : public NavMesh
{
    bool NavMesh_Load(TESFile*);
};

extern "C" void* __cdecl _alloca(unsigned int);
void* operator new(unsigned int);
template <int N> struct EndianSizeTag
{
};
void BSEndian(int*, EndianSizeTag<4>);
void BSEndian(unsigned short*, EndianSizeTag<2>);
int Warning(const char*, ...);
void* memcpy(void*, const void*, unsigned int);
struct EdgeExtraInfoOLDNoPad
{
    float m_fValue;
    NavMeshInfo* m_pNavMeshInfo;
    unsigned int m_uiDoorFormID;
    int m_iValue1;
    int m_iValue2;
    int m_iValue3;
    int m_iValue4;
    int m_iValue5;
    int m_iValue6;
    int PAD4_1;
    int PAD4_2;
    unsigned short m_usTriangleIdentifier;
};
struct FUN_00694de0
{
    FUN_00694de0();
    ~FUN_00694de0();
    void* vtbl;
    int* pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;
};
struct NavMeshPortalIndexArray
{
    unsigned int Add(NavMesh* const&);
};
struct Flt
{
    operator unsigned int() const;
};
TESForm* GetFormByID(unsigned int);

struct SeqObj
{
    void NiRefObject_DecRefCount();
};
struct G00559a40
{
    void NiRefObject_IncRefCount();
};
// Exe 0x00692950: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct NavmeshOffset08View
{
    unsigned int GetFlags();
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct LS3de0
{
    void UpdateEntryValue(unsigned int, unsigned int);
};
struct ContainerItemExtraFileData
{
    void Endian();
};
struct BSXFlags_shell
{
    void ClearFlags(unsigned int);
};
// ProcessListsView: unit-local view (declares only what 0x00692950 calls), not the shared ProcessLists; renamed so no local type keeps the shared name
struct ProcessListsView
{
    unsigned char* GetLifeStateControlFlag();
};

struct VertArr
{
    ContainerItemExtraFileData* Object_GetIndexedValue_006a1440(unsigned int);
};
struct EdgeS
{
    void EdgeExtraInfo_LoadV5(TESFile*, char*);
    void ReadFromFile(TESFile*, char*);
    unsigned int EdgeExtraInfo_GetSizeOfV5();
    unsigned int EdgeExtraInfo_GetSizeOfV9();
};
struct EdgeArr
{
    EdgeS* Object_GetIndexedValue_006a1440(unsigned int);
};
struct DoorS
{
    unsigned int DoorRef;
    unsigned short m_usTriangleIdentifier;
    void CHUNK_Endian();
};
struct DoorArr
{
    DoorS* GetElement(unsigned int);
    void BSSimpleArray_RemoveAt(unsigned int, int);
};
struct TriS
{
    bool HasFlag40();
    bool IsNoLargeCreature();
    void NavMeshTriangle_ToggleLargeActor();
    void NavMeshTriangle_endianSwap();
    void NavMeshTriangle_SetObjectCount(int);
    bool NavMeshTriangle_HasEdgeExtraInfo();
    bool IsEdgeFlagSet(int);
    unsigned short GetEdgeExtraInfo_0068f2c0(int);
};
struct TriArr
{
    TriS& GetElementAddress16(int);
};
struct DA00694f20
{
    void BSSimpleArray_EdgeExtraInfo_1024_SetSize(unsigned int, int);
};
struct DA00694f80
{
    void SetSize(unsigned int, bool);
    unsigned short& GetBufferEntry(int);
};
struct GridS
{
    bool LoadRecord(void*, unsigned int, TESFile*);
};
struct InfoMapS
{
    void ProcessState_006b6990(unsigned int);
};
unsigned int EdgeExtraInfo_GetSizeOfV0();
TESForm* __fastcall NavMeshInfo_GetParentSpace(const NavMeshInfo*);
extern TESObjectCELL* DAT_011c3f30;
extern ProcessListsView g_011d6ca8;

// Reads a NavMesh record from a TESFile, parsing subrecords, converting old versions, and resolving the parent cell and NavMeshInfo.
// @fnv 0x00692950
// src: COMMUNITY 0x00692950
bool FUN_00692950_shell::NavMesh_Load(TESFile* apFile)
{
    AutoMemHelper tempMemContext(
        0x2e, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Pathfinding\\NavMesh_LoadSave.cpp", 0x113);
    if (((TESForm*)this)->IsDeleted())
    {
        ((SeqObj*)((char*)this + 0x1c))->NiRefObject_DecRefCount();
        return false;
    }
    unsigned char formid;
    formid = apFile->GetTESForm();
    if (formid != 0x43)
        return false;
    ((TESForm*)this)->LoadRecordHeader(apFile);
    FUN_00694de0 oldDoorPortalIndices;
    int ifileVersionNumber = 1;
    bool bbadNavMesh = false;
    if (!((TESForm*)this)->IsDeleted())
    {
        char* pMessage;
        NavMeshSaveDataHeader saveStruct;
        do
        {
            switch (apFile->ReadCurrentForm())
            {
            case 0x44494445:  // EDID
                pMessage = (char*)_alloca(apFile->GetChunkSize());
                apFile->GetChunkData(pMessage, 0x200);
                ((TESForm*)this)->SetEditorID_AtRuntime(pMessage);
                break;
            case 0x444e424f:  // OBND
                ((TESForm*)this)->readOBNDSubRecord(apFile);
                break;
            case 0x5245564e:  // NVER
                apFile->GetChunkData(&ifileVersionNumber, 4);
                if (apFile->QEndian())
                    BSEndian(&ifileVersionNumber, EndianSizeTag<4>());
                break;
            case 0x41544144:  // DATA
                if (ifileVersionNumber < 5)
                {
                    apFile->GetChunkData(&saveStruct, 0x14);
                    saveStruct.m_uiField5 = 0;
                }
                else
                {
                    apFile->GetChunkData(&saveStruct, 0x18);
                }
                if (apFile->QEndian())
                    saveStruct.Endian();
                if (saveStruct.GetTriangleTotal >= 0x10000000)
                {
                    saveStruct.GetTriangleTotal -= 0x10000000;
                    bbadNavMesh = true;
                }
                Vertices.SetSize(saveStruct.VertexCount, true);
                Triangles.SetSize(saveStruct.GetTriangleTotal, true);
                ((DA00694f20*)((char*)this + 0x48))->BSSimpleArray_EdgeExtraInfo_1024_SetSize(saveStruct.m_uiField3, 1);
                ((DA00694f80*)((char*)this + 0x78))->SetSize(saveStruct.m_uiField4, true);
                m_kDoorPortals.SetSize(saveStruct.m_uiField5, true);
                TESForm::RemapFormIDForFile(saveStruct.m_uiField0, apFile);
                *(TESObjectCELL**)((char*)this + 0x24) =
                    dynamic_cast<TESObjectCELL*>(GetFormByID(saveStruct.m_uiField0));
                if (!*(TESObjectCELL**)((char*)this + 0x24))
                {
                    Warning("CELL: Could not find parent cell (%08X) for NavMesh (%08X).", saveStruct.m_uiField0,
                            ((TESForm*)this)->GetFormID());
                    if (DAT_011c3f30)
                    {
                        Warning("CELL: Attempting to remap NavMesh parent to cell (%08X) instead.",
                                ((TESForm*)DAT_011c3f30)->GetFormID());
                        *(TESObjectCELL**)((char*)this + 0x24) = DAT_011c3f30;
                    }
                }
                break;
            case 0x5856564e:  // NVVX
                apFile->GetChunkData(((VertArr*)((char*)this + 0x28))->Object_GetIndexedValue_006a1440(0),
                                     ((NavmeshOffset08View*)((char*)this + 0x28))->GetFlags() * 12);
                if (apFile->QEndian())
                {
                    unsigned int isize = ((NavmeshOffset08View*)((char*)this + 0x28))->GetFlags();
                    for (unsigned int i = 0; i < isize; ++i)
                        ((VertArr*)((char*)this + 0x28))->Object_GetIndexedValue_006a1440(i)->Endian();
                }
                break;
            case 0x4143564e:  // NVCA
                apFile->GetChunkData(&((DA00694f80*)((char*)this + 0x78))->GetBufferEntry(0),
                                     ((NavmeshOffset08View*)((char*)this + 0x78))->GetFlags() * 2);
                if (apFile->QEndian())
                {
                    unsigned int isize = ((NavmeshOffset08View*)((char*)this + 0x78))->GetFlags();
                    for (unsigned int i = 0; i < isize; ++i)
                        BSEndian(&((DA00694f80*)((char*)this + 0x78))->GetBufferEntry(i), EndianSizeTag<2>());
                }
                break;
            case 0x5044564e:  // NVDP
            {
                int isize = ((NavmeshOffset08View*)((char*)this + 0x58))->GetFlags();
                apFile->GetChunkData(((DoorArr*)((char*)this + 0x58))->GetElement(0), isize * 8);
                for (int i = 0; i < isize; ++i)
                {
                    if (apFile->QEndian())
                        ((DoorArr*)((char*)this + 0x58))->GetElement(i)->CHUNK_Endian();
                    unsigned int idoorID = ((DoorArr*)((char*)this + 0x58))->GetElement(i)->DoorRef;
                    TESForm::RemapFormIDForFile(idoorID, apFile);
                    TESObjectREFR* pdoor = (TESObjectREFR*)GetFormByID(idoorID);
                    if (pdoor)
                    {
                        ((DoorArr*)((char*)this + 0x58))->GetElement(i)->DoorRef = (unsigned int)pdoor;
                    }
                    else
                    {
                        BSStringT<char> navmeshString;
                        ((TESForm*)this)->GetDebugName(&navmeshString);
                        Warning(
                            "NavMesh: Door reference %08X is not found but is linked to %s.  Please finalize to resolve this.",
                            idoorID, (unsigned int)(const Flt&)navmeshString);
                        unsigned int itriIndex =
                            ((DoorArr*)((char*)this + 0x58))->GetElement(i)->m_usTriangleIdentifier;
                        if (itriIndex < ((NavmeshOffset08View*)((char*)this + 0x38))->GetFlags())
                            ((BSXFlags_shell&)((TriArr*)((char*)this + 0x38))->GetElementAddress16(itriIndex))
                                .ClearFlags(0x400);
                        ((DoorArr*)((char*)this + 0x58))->BSSimpleArray_RemoveAt(i, 1);
                        --i;
                        --isize;
                    }
                }
            }
            break;
            case 0x5254564e:  // NVTR
            {
                apFile->GetChunkData(&((TriArr*)((char*)this + 0x38))->GetElementAddress16(0),
                                     ((NavmeshOffset08View*)((char*)this + 0x38))->GetFlags() * 16);
                unsigned int isize = ((NavmeshOffset08View*)((char*)this + 0x38))->GetFlags();
                for (unsigned int i = 0; i < isize; ++i)
                {
                    if (apFile->QEndian())
                        ((TriArr*)((char*)this + 0x38))->GetElementAddress16(i).NavMeshTriangle_endianSwap();
                    ((TriArr*)((char*)this + 0x38))->GetElementAddress16(i).NavMeshTriangle_SetObjectCount(0);
                }
            }
            break;
            case 0x4447564e:  // NVGD
            {
                unsigned int ichunkSize = apFile->GetChunkSize();
                void* pchunkData = fnv_00692950::operator new(ichunkSize);
                apFile->GetChunkData(pchunkData, ichunkSize);
                if (!((GridS*)((char*)this + 0xa8))->LoadRecord(pchunkData, ichunkSize, apFile))
                {
                    BSStringT<char> navmeshString;
                    ((TESForm*)this)->GetDebugName(&navmeshString);
                    Warning("MASTERFILE: Navmesh %s has a bad navmesh grid, please touch and resave",
                            (unsigned int)(const Flt&)navmeshString);
                    CreateGrid();
                }
                ::operator delete(pchunkData);
            }
            break;
            case 0x5845564e:  // NVEX
            {
                unsigned int ichunksize = apFile->GetChunkSize();
                void* pchunkdata = fnv_00692950::operator new(ichunksize);
                apFile->GetChunkData(pchunkdata, ichunksize);
                char* pchunkPointer = (char*)pchunkdata;
                if (ifileVersionNumber < 5)
                {
                    unsigned int isize = ((NavmeshOffset08View*)((char*)this + 0x48))->GetFlags();
                    EdgeExtraInfoOLDNoPad oldFormat;
                    for (unsigned int i = 0; i < isize; ++i)
                    {
                        memcpy(&oldFormat, pchunkPointer, 0x30);
                        if (oldFormat.m_uiDoorFormID)
                            ((NavMeshPortalIndexArray*)&oldDoorPortalIndices)->Add((NavMesh*)i);
                        char newFormat[48];
                        char* pbufferLoc = newFormat;
                        *(NavMeshInfo**)pbufferLoc = oldFormat.m_pNavMeshInfo;
                        pbufferLoc += 4;
                        *(unsigned short*)pbufferLoc = oldFormat.m_usTriangleIdentifier;
                        ((EdgeArr*)((char*)this + 0x48))->Object_GetIndexedValue_006a1440(i)->EdgeExtraInfo_LoadV5(apFile, newFormat);
                        pchunkPointer += EdgeExtraInfo_GetSizeOfV0();
                    }
                }
                else if (ifileVersionNumber < 9)
                {
                    unsigned int isize = ((NavmeshOffset08View*)((char*)this + 0x48))->GetFlags();
                    for (unsigned int i = 0; i < isize; ++i)
                    {
                        ((EdgeArr*)((char*)this + 0x48))->Object_GetIndexedValue_006a1440(i)->EdgeExtraInfo_LoadV5(apFile, pchunkPointer);
                        pchunkPointer += ((EdgeArr*)((char*)this + 0x48))->Object_GetIndexedValue_006a1440(i)->EdgeExtraInfo_GetSizeOfV5();
                    }
                }
                else
                {
                    unsigned int isize = ((NavmeshOffset08View*)((char*)this + 0x48))->GetFlags();
                    for (unsigned int i = 0; i < isize; ++i)
                    {
                        ((EdgeArr*)((char*)this + 0x48))->Object_GetIndexedValue_006a1440(i)->ReadFromFile(apFile, pchunkPointer);
                        pchunkPointer += ((EdgeArr*)((char*)this + 0x48))->Object_GetIndexedValue_006a1440(i)->EdgeExtraInfo_GetSizeOfV9();
                    }
                }
                ::operator delete(pchunkdata);
            }
            break;
            }
        } while (apFile->NextChunk());
    }

    if (bbadNavMesh)
    {
        BSStringT<char> navmeshString;
        ((TESForm*)this)->GetDebugName(&navmeshString);
        Warning("MASTERFILE: %s has unresolved warnings and will not be loaded.",
                (unsigned int)(const Flt&)navmeshString);
        ((NavMesh*)this)->SetDeletionState(true);
        *(NavMeshInfo**)((char*)this + 0x104) = 0;
        *(TESObjectCELL**)((char*)this + 0x24) = 0;
        ((TESForm*)this)->TESForm::MarkForDeletion(true);
    }
    if (((TESForm*)this)->IsDeleted())
    {
        ((G00559a40*)((char*)this + 0x1c))->NiRefObject_IncRefCount();
        ((InfoMapS*)g_TES->GetActiveCell())->ProcessState_006b6990(((TESForm*)this)->GetFormID());
        return false;
    }
    if (*(NavMeshInfo**)((char*)this + 0x104))
        *(NavMeshInfo**)((char*)this + 0x104) = 0;

    if (!((TESForm*)this)->IsDeleted())
    {
        if (ifileVersionNumber < 5)
        {
            if (((NavmeshOffset08View*)&oldDoorPortalIndices)->GetFlags() > 0)
            {
                BSStringT<char> navmeshString;
                ((TESForm*)this)->GetDebugName(&navmeshString);
                Warning(
                    "Depreciated NavMesh Door Portals found in %s, removing portals, please refinalize cell to create new door portals",
                    (unsigned int)(const Flt&)navmeshString);
            }
            unsigned int isize = ((NavmeshOffset08View*)&oldDoorPortalIndices)->GetFlags();
            for (int i = isize - 1; i >= 0; --i)
            {
                int imodified = *((Arr*)&oldDoorPortalIndices)->GetAt(i);
                UpdateTriangleExtraInfo((unsigned short)imodified);
            }
        }
        if (ifileVersionNumber < 6)
        {
            bool bcoverMessedUp = false;
            unsigned int isize = ((NavmeshOffset08View*)((char*)this + 0x38))->GetFlags();
            for (unsigned int i = 0; i < isize; ++i)
            {
                TriS* ptri = reinterpret_cast<TriS*>(FUN_005582f0((unsigned short)i));
            }
            RebuildTriangleList();
            if (bcoverMessedUp)
            {
                BSStringT<char> navmeshString;
                ((TESForm*)this)->GetDebugName(&navmeshString);
                Warning("%s had cover that could not be converted to the new format, please check and fix",
                        ((TESForm*)this)->GetFormID(), (unsigned int)(const Flt&)navmeshString);
            }
        }
        if (ifileVersionNumber < 8)
        {
            unsigned int isize = ((NavmeshOffset08View*)((char*)this + 0x38))->GetFlags();
            for (unsigned int i = 0; i < isize; ++i)
            {
                TriS* ptri = reinterpret_cast<TriS*>(FUN_005582f0((unsigned short)i));
                if (ptri->IsNoLargeCreature())
                    ptri->NavMeshTriangle_ToggleLargeActor();
            }
        }
        if (!g_TES->GetActiveCell())
            return false;
        *(NavMeshInfo**)((char*)this + 0x104) =
            g_TES->GetActiveCell()->FUN_00693d70(((TESForm*)this)->GetFormID());
        if (!*(NavMeshInfo**)((char*)this + 0x104))
        {
            Warning("MASTERFILE: Did not find matching NavMeshInfo for NavMesh ID %08X, Creating a temporary one",
                    ((TESForm*)this)->GetFormID());
            FUN_006986d0();
        }
        else
        {
            if (!NavMeshInfo_GetParentSpace(*(NavMeshInfo**)((char*)this + 0x104)))
                *(unsigned int*)((char*)*(NavMeshInfo**)((char*)this + 0x104) + 4) =
                    GetDoorForm()->GetFormID();
            ((TESRecipe*)*(NavMeshInfo**)((char*)this + 0x104))->SetCategory((unsigned int)this);
        }
        if (ifileVersionNumber < 10)
        {
            unsigned int isize = ((NavmeshOffset08View*)((char*)this + 0x38))->GetFlags();
            unsigned int ipreferredTris = 0;
            for (unsigned int i = 0; i < isize; ++i)
            {
                TriS* ptri = reinterpret_cast<TriS*>(FUN_005582f0((unsigned short)i));
                if (ptri->HasFlag40())
                    ++ipreferredTris;
            }
            if (*(NavMeshInfo**)((char*)this + 0x104) && isize)
                ((ActiveEffect*)*(NavMeshInfo**)((char*)this + 0x104))
                    ->BaseProcess_SetLastTimeProcessed((float)ipreferredTris / (float)isize);
        }
        if (ifileVersionNumber < 11)
        {
            unsigned int isize = ((NavmeshOffset08View*)((char*)this + 0x38))->GetFlags();
            for (unsigned int i = 0; i < isize; ++i)
            {
                TriS* ptri = reinterpret_cast<TriS*>(FUN_005582f0((unsigned short)i));
                if (ptri->HasFlag40())
                {
                    if (!ptri->NavMeshTriangle_HasEdgeExtraInfo())
                        continue;
                    for (int e = 0; e < 3; ++e)
                    {
                        if (!ptri->IsEdgeFlagSet(e))
                            continue;
                        EdgeExtraInfo* pinfo;
                        unsigned short extraInfoIndex = ptri->GetEdgeExtraInfo_0068f2c0(e);
                        pinfo = reinterpret_cast<EdgeExtraInfo*>(GetEdge(extraInfoIndex));
                        if (!*(NavMeshInfo**)((char*)this + 0x104))
                            continue;
                        for (unsigned int j = 0;
                             j < ((NavmeshOffset08View*)((char*)*(NavMeshInfo**)((char*)this + 0x104) + 0x24))->GetFlags(); ++j)
                        {
                            if (*((Arr*)((char*)*(NavMeshInfo**)((char*)this + 0x104) + 0x24))->GetAt(j) ==
                                (unsigned int)pinfo->Portal.m_pNavMeshInfo)
                            {
                                ((LS3de0*)((char*)*(NavMeshInfo**)((char*)this + 0x104) + 0x24))
                                    ->UpdateEntryValue(j, 1);
                                ((NavMeshPortalIndexArray*)((char*)*(NavMeshInfo**)((char*)this + 0x104) + 0x34))
                                    ->Add((NavMesh* const&)pinfo->Portal.m_pNavMeshInfo);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    if ((*g_011d6ca8.GetLifeStateControlFlag() || !apFile->IsMasterFile()) && !((TESForm*)this)->IsDeleted())
        Validate(false);
    return true;
}
}  // namespace fnv_00692950

// @fnv 0x00694890
template <>
void BSSimpleArray<NavMeshVertex, 1024>::SetSize(unsigned int newCount, bool reset)
{
    if (newCount == 0)
    {
        this->Clear(reset);
    }
    else if (newCount > this->SimpleArrayStorage)
    {
        if (this->SimpleArrayStorage == 0)
        {
            this->pBuffer = this->_Allocate(newCount);
            this->SimpleArrayStorage = newCount;
        }
        else
        {
            this->ReallocateStorage(newCount, this->iSize);
            this->SimpleArrayStorage = newCount;
        }

        this->InitializeItems(this->pBuffer + this->iSize, newCount - this->iSize);
        this->iSize = newCount;
    }
    else if (newCount < this->iSize)
    {
        this->ReleaseElements(this->pBuffer + newCount, this->iSize - newCount);
        this->iSize = newCount;

        if (reset && newCount <= this->SimpleArrayStorage / 4)
        {
            this->ReallocateStorage(newCount, newCount);
            this->SimpleArrayStorage = newCount;
        }
    }
    else
    {
        this->InitializeItems(this->pBuffer + this->iSize, newCount - this->iSize);
        this->iSize = newCount;
    }
}

// @fnv 0x006949d0
template <>
void BSSimpleArray<NavMeshTriangle, 1024>::SetSize(unsigned int uiNewSize, bool bShrinkCapacity)
{
    if (uiNewSize == 0)
    {
        Clear(bShrinkCapacity);
        return;
    }

    if (uiNewSize > SimpleArrayStorage)
    {
        if (SimpleArrayStorage == 0)
        {
            pBuffer = _Allocate(uiNewSize);
            SimpleArrayStorage = uiNewSize;
        }
        else
        {
            ReallocateStorage(uiNewSize, iSize);
            SimpleArrayStorage = uiNewSize;
        }

        InitializeItems(pBuffer + iSize, uiNewSize - iSize);
        iSize = uiNewSize;
    }
    else if (uiNewSize < iSize)
    {
        ReleaseElements(pBuffer + uiNewSize, iSize - uiNewSize);
        iSize = uiNewSize;

        if (bShrinkCapacity && uiNewSize <= SimpleArrayStorage / 4)
        {
            ReallocateStorage(uiNewSize, uiNewSize);
            SimpleArrayStorage = uiNewSize;
        }
    }
    else
    {
        InitializeItems(pBuffer + iSize, uiNewSize - iSize);
        iSize = uiNewSize;
    }
}

// @fnv 0x006950f0
template <>
void BSSimpleArray<NavMeshTriangleDoorPortal, 1024>::SetSize(unsigned int size, bool clear)
{
    if (size == 0)
    {
        this->Clear(clear);
        return;
    }

    if (size > this->SimpleArrayStorage)
    {
        if (this->SimpleArrayStorage == 0)
        {
            this->pBuffer = this->_Allocate(size);
            this->SimpleArrayStorage = size;
        }
        else
        {
            this->ReallocateStorage(size, this->iSize);
            this->SimpleArrayStorage = size;
        }

        this->InitializeItems(this->pBuffer + this->iSize, size - this->iSize);
        this->iSize = size;
        return;
    }

    if (size < this->iSize)
    {
        this->ReleaseElements(this->pBuffer + size, this->iSize - size);
        this->iSize = size;

        if (clear && size <= (this->SimpleArrayStorage >> 2))
        {
            this->ReallocateStorage(size, size);
            this->SimpleArrayStorage = size;
        }
        return;
    }

    this->InitializeItems(this->pBuffer + this->iSize, size - this->iSize);
    this->iSize = size;
}

// @fnv 0x0068ef50
TESObjectCELL* NavMesh::GetSaveParentCell()
{
    return GetParentCell();
}

struct FUN_00693f30_name
{
    FUN_00693f30_name();
    ~FUN_00693f30_name();
    const char* c_str() const;
    char* m_pData;
};

struct FUN_00693f30_obj
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90(FUN_00693f30_name* name);
};

struct FUN_00693f30_count
{
    int FUN_0044ddc0();
};

struct FUN_00693f30_cls
{
    char pad[0x38];
    FUN_00693f30_count triCount;
    FUN_00693f30_obj* FUN_0059bb30();
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    void PrintNavMeshInfo(void* a1);
};

int BSStringT_char_SPrintF(void*, const char*, ...);

// Builds a name via the nav object's vfn_90 and prints the navmesh id, triangle count and cell name through FUN_00406f60.
// @fnv 0x00693f30
void FUN_00693f30_cls::PrintNavMeshInfo(void* a1)
{
    int unk_pad;
    FUN_00693f30_name name;
    {
        FUN_00693f30_obj* nav = FUN_0059bb30();
        if (nav)
        {
            nav->vfn_90(&name);
        }
    }
    BSStringT_char_SPrintF(a1, "NavMesh (%08X) with %d Triangles in Cell %s", GetHavokWorldObjectCountInSceneGraph_0084e3a0(), triCount.FUN_0044ddc0(),
                 name.c_str());
}

struct FUN_00693fe0_cls;

struct Node
{
    unsigned char Test();
};

struct Res
{
    void Fin();
};

void Bar(void* p);

struct FUN_00693fe0_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
    virtual void v30();
    virtual void v31();
    virtual void v32(bool flag);

    unsigned char GetA();
    Node* GetB(int arg);
    void Foo(unsigned char arg);
    void* GetC();
    void* GetD();

    void NavMesh_SetDelete(unsigned char arg);
};

// If arg differs from GetA, updates state via Foo and v32 based on GetB(0)->Test(); when arg is non-zero, calls Bar(GetC()) and Fin() on the active TES navmesh map.
// @fnv 0x00693fe0
// src: XBOX_PDB 0x00693fe0
void FUN_00693fe0_cls::NavMesh_SetDelete(unsigned char arg)
{
    bool flag;
    if (arg != GetA())
    {
        flag = true;
        Node* p = GetB(0);
        if (arg != 0)
        {
            if (!(p != 0 && p->Test() != 0))
                flag = false;
        }
        Foo(arg);
        v32(flag);
    }
    if (arg != 0)
    {
        Bar(GetC());
        reinterpret_cast<Res*>(g_TES->GetActiveCell(GetD()))->Fin();
    }
}

struct NavMeshAction
{
    unsigned int descriptor;
    unsigned int userData;
    unsigned int triangleIndex;
    unsigned int action;
};
extern unsigned int DAT_01187020;
struct PathingService
{
    virtual void UnknownVirtual_00();
    virtual void UnknownVirtual_01();
    virtual void UnknownVirtual_02();
    virtual void UnknownVirtual_03();
    virtual void UnknownVirtual_04();
    virtual void UnknownVirtual_05();
    virtual void UnknownVirtual_06();
    virtual void UnknownVirtual_07();
    virtual void UnknownVirtual_08();
    virtual void UnknownVirtual_09();
    virtual void UnknownVirtual_0a();
    virtual void UnknownVirtual_0b();
    virtual void UnknownVirtual_0c();
    virtual void UnknownVirtual_0d();
    virtual void UnknownVirtual_0e();
    virtual void UnknownVirtual_0f();
    virtual void UnknownVirtual_10();
    virtual void UnknownVirtual_11();
    virtual void UnknownVirtual_12();
    virtual void UnknownVirtual_13();
    virtual void UnknownVirtual_14();
    virtual void UnknownVirtual_15();
    virtual void UnknownVirtual_16();
    virtual void UnknownVirtual_17();
    virtual void UnknownVirtual_18();
    virtual void UnknownVirtual_19();
    virtual void UnknownVirtual_1a();
    virtual void UnknownVirtual_1b();
    virtual void UnknownVirtual_1c();
    virtual void UnknownVirtual_1d();
    virtual void UnknownVirtual_1e();
    virtual void UnknownVirtual_1f();
    virtual void UnknownVirtual_20();
    virtual void UnknownVirtual_21();
    virtual void UnknownVirtual_22();
    virtual void UnknownVirtual_23();
    virtual void UnknownVirtual_24();
    virtual void UnknownVirtual_25();
    virtual void UnknownVirtual_26();
    virtual void UnknownVirtual_27();
    virtual void UnknownVirtual_28();
    virtual void UnknownVirtual_29();
    virtual void UnknownVirtual_2a();
    virtual void UnknownVirtual_2b();
    virtual void UnknownVirtual_2c();
    virtual void UnknownVirtual_2d();
    virtual void UnknownVirtual_2e();
    virtual void UnknownVirtual_2f();
    virtual void UnknownVirtual_30();
    virtual void UnknownVirtual_31();
    virtual void UnknownVirtual_32();
    virtual void UnknownVirtual_33();
    virtual void UnknownVirtual_34();
    virtual void UnknownVirtual_35();
    virtual void UnknownVirtual_36();
    virtual void UnknownVirtual_37();
    virtual void UnknownVirtual_38();
    virtual void UnknownVirtual_39();
    virtual void UnknownVirtual_3a();
    virtual void UnknownVirtual_3b();
    virtual void UnknownVirtual_3c();
    virtual void UnknownVirtual_3d();
    virtual void UnknownVirtual_3e();
    virtual void UnknownVirtual_3f();
    virtual void UnknownVirtual_40();
    virtual void UnknownVirtual_41();
    virtual void UnknownVirtual_42();
    virtual void UnknownVirtual_43();
    virtual unsigned char DispatchAction(NavMeshAction* action, unsigned char enabled, unsigned char option);
    unsigned char TESForm_FormIDMatchesWithoutIndex(unsigned int triangleIndex);
};
struct NavMeshActionController
{
    PathingService* FUN_0059bb30();
    unsigned char ProcessNavMeshAction(NavMeshAction* entry, unsigned char enabled, unsigned char option);
};
// Validates a NavMeshAction against DAT_01187020 and dispatches it by action type, checking the triangle for actions 6, 8 and 9.
// @fnv 0x006940e0
unsigned char NavMeshActionController::ProcessNavMeshAction(NavMeshAction* apAction, unsigned char enabled,
                                                            unsigned char option)
{
    unsigned char result = 0;
    if (apAction != 0 && apAction->descriptor == DAT_01187020)
    {
        PathingService* service = FUN_0059bb30();
        switch (apAction->action)
        {
        case 6:
            if (enabled == 0)
            {
                result = 0;
                break;
            }
        case 8:
        case 9: {
            unsigned char valid = 0;
            if (service->TESForm_FormIDMatchesWithoutIndex(apAction->triangleIndex))
                valid = 1;
            if (valid)
            {
                switch (apAction->action)
                {
                case 8:
                    result = 0;
                    break;
                default:
                    result = 1;
                    break;
                }
            }
            break;
        }
        default:
            if (enabled)
                result = service->DispatchAction(apAction, enabled, option);
            break;
        }
    }
    return result;
}

extern unsigned int DAT_01187020;

class FUN_006941c0_mid;

struct FUN_006941c0_out
{
    unsigned int vtbl;
    unsigned int unk04;
    void* unk08;
    unsigned int unk0C;
    unsigned int unk10;
};

struct FUN_006941c0_in
{
    unsigned int unk00;
    unsigned int unk04;
    void* unk08;
    unsigned int unk0C;
};

class FUN_006941c0_mid
{
  public:
    void* GetCode();
    void* GetHandle();
};

class FUN_006941c0_cls
{
  public:
    FUN_006941c0_mid* GetMid();
    void MapHandleState(FUN_006941c0_out* out, FUN_006941c0_in* in);
};

// If out and in are non-null, checks in->unk0C (3/5/6) and in->unk08 against the mid's code or handle, filling out with DAT_01187020 and state 6 or 9.
// @fnv 0x006941c0
void FUN_006941c0_cls::MapHandleState(FUN_006941c0_out* out, FUN_006941c0_in* in)
{
    if (out != 0)
    {
        out->vtbl = 0;
        if (in != 0)
        {
            FUN_006941c0_mid* m1 = this->GetMid();
            void* h = this->GetMid()->GetHandle();
            switch (in->unk0C)
            {
            case 3:
            case 5:
                if (in->unk08 == m1->GetCode())
                {
                    out->vtbl = DAT_01187020;
                    out->unk0C = 6;
                    out->unk08 = h;
                    out->unk04 = 0;
                    out->unk10 = 0;
                }
                break;
            case 6:
                if (in->unk08 == h)
                {
                    out->vtbl = DAT_01187020;
                    out->unk0C = 9;
                    out->unk08 = this->GetMid()->GetHandle();
                    out->unk04 = 0;
                    out->unk10 = 0;
                }
                break;
            }
        }
    }
}

struct FUN_006947e0_node
{
    FUN_006947e0_node* pNext;
    unsigned short usKey;
    unsigned short unk06;
};

class FUN_006947e0_cls
{
  public:
    virtual void Unk_00(void);
    virtual int Unk_01(unsigned short key);
    unsigned int m_uiCount;
    FUN_006947e0_node** m_ppItems;

    void NiTMapBase_DFALL_NiTMapItem_unsigned_short_NiPointer_ObstacleData_unsigned_short_NiPointer_ObstacleData_GetNext(FUN_006947e0_node** ppNode, unsigned short* pKey, NiPointer<ObstacleData>* pOwner);
};

// @fnv 0x006947e0
// src: COMMUNITY 0x006947e0
void FUN_006947e0_cls::NiTMapBase_DFALL_NiTMapItem_unsigned_short_NiPointer_ObstacleData_unsigned_short_NiPointer_ObstacleData_GetNext(FUN_006947e0_node** ppNode, unsigned short* pKey, NiPointer<ObstacleData>* pOwner)
{
    FUN_006947e0_node* node = *ppNode;
    *pKey = node->usKey;
    *pOwner = *reinterpret_cast<NiPointer<ObstacleData>*>((char*)node + 8);
    if (node->pNext != 0)
    {
        *ppNode = node->pNext;
        return;
    }
    int i = Unk_01(node->usKey);
    i++;
    for (; (unsigned int)i < m_uiCount; i++)
    {
        node = m_ppItems[i];
        if (node != 0)
        {
            *ppNode = node;
            return;
        }
    }
    *ppNode = 0;
}

struct Mesh69
{
    bool FUN_00440da0();
    void TESForm_SetDisabled(bool);
    void LinkMatchingEdges();
};
struct Info69
{
    bool FUN_00690860(NavMeshPtr*);
    void FUN_00693ef0(bool);
};
struct Map69
{
    Info69* FUN_00693d70();
};
void __cdecl FNV_Warning(const char*, ...);
// Looks up the NavMeshInfo for a NavMesh ID and sets its mesh disabled state, warning and returning false if the info or mesh is missing.
// @fnv 0x00694500
// src: COMMUNITY 0x00694500
bool __cdecl NavMesh_SetDisableNavMesh(unsigned int uiNavMeshId, bool disabled)
{
    Info69* info = reinterpret_cast<Map69*>(g_TES->GetActiveCell(uiNavMeshId))->FUN_00693d70();
    if (!info)
    {
        FNV_Warning("DisableNavMesh Script Function: Did not find matching NavMeshInfo for NavMesh ID parameter %08X",
                    uiNavMeshId);
        return false;
    }
    else
    {
        NavMeshPtr navMeshPtr;
        if (!info->FUN_00690860(&navMeshPtr))
        {
            FNV_Warning("DisableNavMesh Script Function: Did not find matching NavMesh for NavMesh ID parameter %08X",
                        uiNavMeshId);
            return false;
        }
        else if (reinterpret_cast<Mesh69*>(navMeshPtr.Modelloader_GetReferencedThis())->FUN_00440da0() != disabled)
        {
            reinterpret_cast<Mesh69*>(navMeshPtr.Modelloader_GetReferencedThis())->TESForm_SetDisabled(disabled);
            info->FUN_00693ef0(disabled);
            if (!disabled)
                reinterpret_cast<Mesh69*>(navMeshPtr.Modelloader_GetReferencedThis())->LinkMatchingEdges();
        }
    }
    return true;
}

struct Item6946a0
{
    Item6946a0* m_pkNext;
    unsigned short m_key;
    NiPointer<ObstacleData> m_val;
};
struct Map6946a0
{
    virtual void v0();
    virtual unsigned int KeyToHashIndex(unsigned short key);
    virtual bool IsKeysEqual(unsigned short key1, unsigned short key2);
    virtual void SetValue(Item6946a0* pkItem, unsigned short key, NiPointer<ObstacleData> val);
    virtual void v10();
    virtual Item6946a0* NewItem();
    unsigned int m_uiHashSize;
    Item6946a0** m_ppkHashTable;
    unsigned int m_uiCount;
    void NiTMapBase_DFALL_NiTMapItem_unsigned_short_NiPointer_NavMeshObstacleData_unsigned_short_NiPointer_NavMeshObstacleData_SetAt(unsigned short key, NiPointer<ObstacleData> val);
};

// Looks up the bucket for key, updates the value if the key exists, otherwise inserts a new item and increments the count.
// @fnv 0x006946a0
// src: COMMUNITY 0x006946a0
void Map6946a0::NiTMapBase_DFALL_NiTMapItem_unsigned_short_NiPointer_NavMeshObstacleData_unsigned_short_NiPointer_NavMeshObstacleData_SetAt(unsigned short key, NiPointer<ObstacleData> aRefVal)
{
    unsigned int uiIndex = KeyToHashIndex(key);
    Item6946a0* pkItem = m_ppkHashTable[uiIndex];
    unsigned int uiDepth = 0;
    while (pkItem)
    {
        uiDepth++;
        if (IsKeysEqual(key, pkItem->m_key))
        {
            pkItem->m_val = aRefVal;
            return;
        }
        pkItem = pkItem->m_pkNext;
    }
    pkItem = NewItem();
    SetValue(pkItem, key, aRefVal);
    pkItem->m_pkNext = m_ppkHashTable[uiIndex];
    m_ppkHashTable[uiIndex] = pkItem;
    m_uiCount++;
}
