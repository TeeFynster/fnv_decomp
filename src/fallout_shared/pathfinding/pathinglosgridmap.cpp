#include "../../../include/NiRefObject.h"
#include "../../../include/PathingLocation.h"
#include "../../../include/TESConditionItem.h"
#include "../../../include/PathingLOSGridMap.h"
#include "../../../include/BGSSaveFormBuffer.h"
#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/BSSimpleArray.h"
#include "../../../include/GO.h"
#include "../../../include/NavMesh.h"
#include "../../../include/NavMeshInfo.h"
#include "../../../include/NiPointer.h"
#include "../../../include/NiAVObject.h"
#include "../../../include/BGSSaveGameBuffer.h"
#include "../../../include/BSAudio.h"
#include "../../../include/DummyPointerMap.h"
#include "../../../include/TES.h"

// src/fallout_shared/pathfinding/pathinglosgridmap.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/pathinglosgridmap.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_006e0590_shell
{
    void ForwardCall_006e0590();
};

struct FUN_006e10a0_shell
{
    void ResetVirtualTableAndClear_006e10a0();
};

// @fnv 0x006e0590
// src: GUESS 0x006e0590 (confidence: low)
void FUN_006e0590_shell::ForwardCall_006e0590()
{
    ((FUN_006e10a0_shell*)(reinterpret_cast<char*>(this) + 4))->ResetVirtualTableAndClear_006e10a0();
}

// @fnv 0x006a62f0
template <>
signed char& __thiscall BSSimpleArray<signed char>::GetAt(unsigned int index)
{
    return *(pBuffer + index);
}

// @fnv 0x006e0ed0
template <>
signed char& __thiscall BSSimpleArray<signed char>::GetElement(unsigned int index)
{
    return GetAt(index);
}


struct FUN_006e08f0_shell
{
    NavMeshInfo* m_pNavMeshInfo;
    bool PathingLOSGrid_GetNavMesh(NavMeshPtr& aArg);
};

// Checks whether the object at offset 16 is non-null and, if so, delegates to its NavMeshInfo method with aArg.
// @fnv 0x006e08f0
// src: COMMUNITY 0x006e08f0
bool FUN_006e08f0_shell::PathingLOSGrid_GetNavMesh(NavMeshPtr& aArg)
{
    if (reinterpret_cast<void**>(this)[4] == 0)
        return false;
    return reinterpret_cast<NavMeshInfo*>(reinterpret_cast<void**>(this)[4])->ResolveNavMesh(aArg);
}

void __cdecl _delete(void*, unsigned int);
// Calls FUN_006e02a0, then frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x006e0270
void* __thiscall PathingLOSGridMap::FUN_006e0270(unsigned int flags)
{
    this->FUN_006e02a0();
    if (flags & 1)
        _delete(this, 0x54);
    return this;
}

void __cdecl operator delete(void*);
// Calls FUN_006e04b0, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x006e0480
void* __thiscall PathingLOSGridMap::FUN_006e0480(unsigned int flags)
{
    FUN_006e04b0();
    if (flags & 1)
        ::operator delete(this);
    return this;
}

struct FUN_006e0560_shell : FUN_006e0590_shell
{
    void* __thiscall DestroyIfFlagged(unsigned int);
};
// @fnv 0x006e0560
void* __thiscall FUN_006e0560_shell::DestroyIfFlagged(unsigned int flags)
{
    ForwardCall_006e0590();
    if (flags & 1)
        ::operator delete(this);
    return this;
}


struct FUN_006dfe90_shell
{
    bool __thiscall PathingLOSGrid_SetLocationSeen(BSAudio*, bool);
};
struct FUN_006e0bc0_shell
{
    bool __thiscall PathingLOSGridMap_SetLocationSeen(BSAudio* aArg, bool aFlag);
};
// @fnv 0x006e0bc0
// src: XBOX_PDB 0x006e0bc0
bool __thiscall FUN_006e0bc0_shell::PathingLOSGridMap_SetLocationSeen(BSAudio* aArg, bool aFlag)
{
    void* pTopic = aArg->GetAudioBackendData();
    if (!pTopic || ((PathingLocation*)aArg)->GetShortValueAtOffset24() == 0xFFFF)
        return false;
    unsigned int key = 0;
    if (((DummyPointerMap*)((char*)this + 8))->GetAt(*(GO*)pTopic, key))
        return ((FUN_006dfe90_shell*)key)->PathingLOSGrid_SetLocationSeen(aArg, aFlag);
    return false;
}

extern "C"
{
    void __declspec(dllimport) __stdcall vprintf(const char*, void*);
}
extern int DAT_0106cef8;
struct AX
{
    void __thiscall BSSimpleArray_float_1024_InitialSetup(unsigned int, unsigned int);
};
struct FUN_006e1020_shell : AX
{
    FUN_006e1020_shell* __thiscall BSSimpleArray_PathingLOSGridCell_1024_BSSimpleArray_PathingLOSGridCell_1024();
};
// Sets the object's vtable pointer to DAT_0106cef8, calls FUN_006b3eb0 with 0, 0, and returns this.
// @fnv 0x006e1020
// src: COMMUNITY 0x006e1020
FUN_006e1020_shell* __thiscall FUN_006e1020_shell::BSSimpleArray_PathingLOSGridCell_1024_BSSimpleArray_PathingLOSGridCell_1024()
{
    *reinterpret_cast<unsigned int**>(this) = reinterpret_cast<unsigned int*>(&DAT_0106cef8);
    BSSimpleArray_float_1024_InitialSetup(0, 0);
    return this;
}

struct FUN_006e0190
{
    unsigned char b0;
    char pad[3];
    BSSimpleArray<signed char> m;
    int i14;
    int i18;
    FUN_006e0190();
};
// Initializes the embedded object, sets b0 and i14 to 0 and i18 to -1.
// @fnv 0x006e0190
FUN_006e0190::FUN_006e0190()
{
    b0 = 0;
    i14 = 0;
    i18 = -1;
}

// @fnv 0x006e05b0
void __thiscall PathingLOSGridMap::Reset()
{
    m_fCellSize = 0.0f;
    ClearMap();
    Initialize_006e0320(&m_1C, fRadius);
}

void* __cdecl operator new(unsigned int);
struct SetAtHelper
{
    void SetAt(unsigned int, unsigned int);
};
struct FUN_006e0e80
{
    char d[0x14];
    FUN_006e0e80();
};
struct FUN_006e0480
{
    ~FUN_006e0480();
    void Lst0044_Data00D4_Arr0004_Load(BGSLoadFormBuffer*);
};
struct FUN_006e0d20_t
{
    void Lst0044_Data00D4_Load(BGSLoadFormBuffer* apLoadGameBuffer);
};

// @fnv 0x006e0d20
// src: COMMUNITY 0x006e0d20
void FUN_006e0d20_t::Lst0044_Data00D4_Load(BGSLoadFormBuffer* apLoadGameBuffer)
{
    unsigned int isaveGameCount = apLoadGameBuffer->ReadElementCount();
    for (unsigned int iloop = 0; iloop < isaveGameCount; iloop++)
    {
        bool bremove = false;
        FUN_006e0480* ppathingLOSGrid = (FUN_006e0480*)new FUN_006e0e80;
        unsigned int inavmeshID;
        apLoadGameBuffer->ReadFormIdentifier(static_cast<void*>(&inavmeshID));
        ppathingLOSGrid->Lst0044_Data00D4_Arr0004_Load(apLoadGameBuffer);
        if (inavmeshID == 0)
            bremove = true;
        if (!bremove)
            ((SetAtHelper*)((char*)this + 8))->SetAt(inavmeshID, (unsigned int)ppathingLOSGrid);
        else
            delete ppathingLOSGrid;
    }
    apLoadGameBuffer->ReadTypedData((char*)this + 0x18, 4U);
    apLoadGameBuffer->ReadTypedData((char*)this + 0x44, 4U);
    apLoadGameBuffer->ReadTypedData((char*)this + 0x48, 4U);
    ((PathingLocation*)((char*)this + 0x1c))->LoadGame(apLoadGameBuffer);
}

struct FUN_00aa6060_shell
{
    void __thiscall AcquireLock();
};
class PathingLOSGrid;
// RTTI: the map at 8 is NiTMap<unsigned int,PathingLOSGrid *> (vftable 0x0106ceb8).
typedef NiTMap<unsigned int, PathingLOSGrid*> PathingLOSGridTable;
struct FUN_00aa62e0_shell
{
    void __thiscall BSReadWriteLock_UnlockWrite();
};
// Calls AcquireLock on the object at offset 0x4c, deletes every value in the map at offset 8, then calls RemoveAll and FUN_00aa62e0.
// @fnv 0x006e03e0
void PathingLOSGridMap::ClearMap()
{
    ((FUN_00aa6060_shell*)((char*)this + 0x4c))->AcquireLock();
    void* position = ((PathingLOSGridTable*)((char*)this + 8))->GetFirstPos();
    while (position)
    {
        unsigned int key = 0;
        ::FUN_006e0480* value = 0;
        ((PathingLOSGridTable*)((char*)this + 8))->GetNext(position, key, (PathingLOSGrid*&)value);
        delete value;
    }
    ((PathingLOSGridTable*)((char*)this + 8))->RemoveAll();
    ((FUN_00aa62e0_shell*)((char*)this + 0x4c))->BSReadWriteLock_UnlockWrite();
}

struct FUN_006df9c0_shell
{
    unsigned char m_byte;
    unsigned char pad[3];
    BSSimpleArray<signed char> m_aiIndexedValues;
    unsigned char pad2[0x14];

    void __thiscall SaveFields_006df9c0(BGSSaveGameBuffer*);
};

// Saves the byte, a 4-byte value at offset 0x18, and, when m_byte is zero, the count and each element returned by FUN_006e0ed0.
// @fnv 0x006df9c0
// src: GUESS 0x006df9c0 (confidence: medium)
void __thiscall FUN_006df9c0_shell::SaveFields_006df9c0(BGSSaveGameBuffer* buffer)
{
    buffer->SaveData(this, 1, 0);
    buffer->SaveData((void*)((char*)this + 0x18), 4, 0);

    if (!m_byte)
    {
        unsigned int count;

        count = ((char*)this + 4) ? m_aiIndexedValues.GetSize() : 0;
        buffer->SaveVariableSizedValue(count);

        for (unsigned int i = 0; i < count; ++i)
        {
            void* data = &m_aiIndexedValues.GetElement(i);
            buffer->SaveData(data, 1, 0);
        }
    }
}

template <>
void __thiscall BSSimpleArray<signed char>::SetSize(unsigned int, bool);

struct FormLoadEntry
{
    bool m_bIsLoaded;
    unsigned char pad0[3];
    BSSimpleArray<signed char> index;

    void __thiscall LoadForm(BGSLoadFormBuffer*);
};

// Reads a byte and four bytes into the object, then, if the flag is unset, reads a count and that many single bytes into indexed entries.
// @fnv 0x006dfa70
void __thiscall FormLoadEntry::LoadForm(BGSLoadFormBuffer* apLoadGameBuffer)
{
    apLoadGameBuffer->ReadTypedData(this, 1U);
    apLoadGameBuffer->ReadTypedData(reinterpret_cast<char*>(this) + 0x18, 4U);

    if (!m_bIsLoaded)
    {
        unsigned int isaveGameCount = apLoadGameBuffer->ReadElementCount();

        index.SetSize(isaveGameCount, true);

        for (unsigned int i = 0; i < isaveGameCount; ++i)
        {
            signed char* cindex = &index.GetElement(i);

            apLoadGameBuffer->ReadTypedData(cindex, 1U);
        }
    }
}

// @fnv 0x006e10c0
template <>
void __thiscall BSSimpleArray<signed char>::SetSize(unsigned int uiNewSize, bool abShrinkCapacity)
{
    if (uiNewSize == 0)
    {
        Clear(abShrinkCapacity);
    }
    else if (uiNewSize > SimpleArrayStorage)
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

        if (abShrinkCapacity && uiNewSize <= (SimpleArrayStorage >> 2))
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

struct Lock
{
    void Enter();
    void Leave();
};

struct FUN_006e0730
{
    unsigned char data[20];
    FUN_006e0730(NiPointer<NavMesh>*);
};

struct FUN_006dfba0_shell
{
    void __thiscall RebuildFromNavMesh(NiPointer<NavMesh>*);
};

struct FUN_006e05f0_shell
{
    bool __thiscall AddNavMeshes(BSSimpleArray<NiPointer<NavMesh> >*);
};

// @fnv 0x006e05f0
bool FUN_006e05f0_shell::AddNavMeshes(BSSimpleArray<NiPointer<NavMesh> >* aArg)
{
    reinterpret_cast<Lock*>(reinterpret_cast<unsigned char*>(this) + 0x4c)->Enter();

    for (unsigned int index = 0; index < aArg->GetSize(); ++index)
    {
        NiPointer<NavMesh> ptrNavMesh2(aArg->GetAt((int)index));
        unsigned int navMeshID = 0;

        if (!reinterpret_cast<DummyPointerMap*>(reinterpret_cast<unsigned char*>(this) + 8)
                 ->GetAt(reinterpret_cast<NavMesh*>(static_cast<unsigned int>(reinterpret_cast<GO&>(ptrNavMesh2)))->GetHavokWorldObjectCountInSceneGraph_0084e3a0(),
                         navMeshID))
        {
            navMeshID = reinterpret_cast<unsigned int>(new FUN_006e0730(&ptrNavMesh2));

            reinterpret_cast<SetAtHelper*>(reinterpret_cast<unsigned char*>(this) + 8)
                ->SetAt(reinterpret_cast<NavMesh*>(static_cast<unsigned int>(reinterpret_cast<GO&>(ptrNavMesh2)))->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), navMeshID);
        }
        else
        {
            reinterpret_cast<FUN_006dfba0_shell*>(navMeshID)->RebuildFromNavMesh(
                reinterpret_cast<NiPointer<NavMesh>*>(&ptrNavMesh2));
        }
    }

    reinterpret_cast<Lock*>(reinterpret_cast<unsigned char*>(this) + 0x4c)->Leave();
    return true;
}

struct IndexList
{
    unsigned int __thiscall FUN_0044ddc0();
    unsigned short* __thiscall BSSimpleArray_unsigned_short_1024_GetAt(unsigned int index);
};

struct NavMeshKey;

struct NavMeshLookup
{
    NavMeshLookup* __thiscall Modelloader_GetReferencedThis();
    unsigned char* __thiscall GetTriangleScore(NavMeshLookup* rhs);
    bool __thiscall FUN_0069ad00(NavMeshKey* key);
    IndexList* __thiscall NavMesh_GetTrianglesForGridCell(unsigned int identifier);
};

struct NavMeshKey
{
    NavMeshLookup* pointer;
    NavMeshKey();
    ~NavMeshKey();
    NavMeshLookup* __thiscall Modelloader_GetReferencedThis();
};

typedef BSSimpleArray<signed char> NavMeshResults;

struct FUN_006df440_owner
{
    union
    {
        bool valid;
        unsigned int state;
    };
    NavMeshResults results;
    NavMeshLookup* lookup;
    unsigned int identifier;
    bool __thiscall InitFromLookup(NavMeshLookup* value);
};

// Copies bytes indexed by the lookup's index list into results, clears valid if any byte is <=0 or 0x7f, and returns false on missing data.
// @fnv 0x006df440
bool FUN_006df440_owner::InitFromLookup(NavMeshLookup* apLookup)
{
    unsigned char* const bytes = apLookup->Modelloader_GetReferencedThis()->GetTriangleScore(lookup->Modelloader_GetReferencedThis());
    if (!bytes)
        return false;

    NavMeshKey key;
    if (!lookup->FUN_0069ad00(&key))
        return false;

    IndexList* const indices = key.Modelloader_GetReferencedThis()->NavMesh_GetTrianglesForGridCell(identifier);
    if (!indices)
        return false;

    results.Clear(false);
    results.SetSize(indices->FUN_0044ddc0(), true);
    valid = true;

    for (unsigned int index = 0; index < indices->FUN_0044ddc0(); ++index)
    {
        results.GetAt(index) = bytes[*indices->BSSimpleArray_unsigned_short_1024_GetAt(index)];
        if (results.GetAt(index) <= 0 || results.GetAt(index) == 0x7f)
            valid = false;
    }

    if (valid)
        results.Clear(true);

    return true;
}


class B6E01D0Array
{
  public:
    B6E01D0Array(int iGrowBy);
    ~B6E01D0Array();

    void* m_pData;
    int m_uiLogicalSize;
    int m_iCapacity;
    int m_iGrowBy;
};


class B6E01D0Matrix
{
  public:
    B6E01D0Matrix();

    float m_afEntry0;
    float m_afEntry1;
    float m_afEntry2;
};

class FUN_006e01d0_cls : public NiRefObject
{
  public:
    FUN_006e01d0_cls();
    virtual ~FUN_006e01d0_cls();

    B6E01D0Array m_kNodeArray;
    float m_fCost;
    PathingLocation m_kGoal;
    float m_fHitDistance;
    float m_fTime;
    B6E01D0Matrix m_kTransform;
};

// Constructs the solution object, initializing its array with grow-by 0x25 and zeroing cost, time and related floats.
// @fnv 0x006e01d0
FUN_006e01d0_cls::FUN_006e01d0_cls() : m_kNodeArray(0x25), m_fCost(0.0f), m_fHitDistance(0.0f), m_fTime(0.0f)
{}

struct Loc14
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    Loc14();
    ~Loc14();
};


struct Sub4c
{
    int unk00;
    void AcquireLock();
    void BSReadWriteLock_UnlockWrite();
};

unsigned char __cdecl Pathing_FindConnectedNavmeshesForLocation(void* aP, float aF, Loc14* aOut);


// @fnv 0x006e0320
// src: COMMUNITY 0x006e0320
void PathingLOSGridMap::Initialize_006e0320(void* aArg, float aF)
{
    reinterpret_cast<Sub4c*>(reinterpret_cast<char*>(this) + 0x4c)->AcquireLock();
    *reinterpret_cast<PathingLocation*>(&m_1C) = *static_cast<const PathingLocation*>(aArg);
    fRadius = aF;
    Loc14 locResult;
    if (Pathing_FindConnectedNavmeshesForLocation(&m_1C, aF, &locResult) != 0)
    {
        reinterpret_cast<FUN_006e05f0_shell*>(this)->AddNavMeshes(
            reinterpret_cast<BSSimpleArray<NiPointer<NavMesh> >*>(&locResult));
    }
    else
    {
        fRadius = 0.0f;
    }
    reinterpret_cast<Sub4c*>(reinterpret_cast<char*>(this) + 0x4c)->BSReadWriteLock_UnlockWrite();
}

struct NavMeshRef
{
    void* m_pObject;
    NavMeshRef();
    ~NavMeshRef();
};

struct NavMeshRefArray
{
    void* m_pBuffer;
    unsigned int m_uiCapacity;
    unsigned int m_uiSize;
    unsigned int m_uiGrowBy;
    NavMeshRefArray();
    ~NavMeshRefArray();
    unsigned int Add(const NavMeshRef& arRef);
};

struct LOSTarget;

struct LOSTargetPtr
{
    LOSTarget* m_pObject;
    operator LOSTarget*() const;
};

struct LOSTarget
{
    void CollectNavMeshes(NavMeshRefArray& arArray);
};

struct LOSNavMeshInfo
{
    bool GetNavMeshRef(NavMeshRef& arRef);
    void Update(LOSTargetPtr& arTarget);
};

struct LOSInfoMap
{
    void* GetFirstPos();
    void GetNext(void*& arPos, unsigned int& arKey, LOSNavMeshInfo*& arVal);
};

struct LOSLock
{
    void Lock();
    void Unlock();
};

struct LOSGridOwner
{
    int unk00;
    int unk04;
    LOSInfoMap kMap;
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
    LOSLock kLock;

    bool UpdateNavMeshes(LOSTargetPtr& arTarget);
};

// @fnv 0x006e07a0
bool LOSGridOwner::UpdateNavMeshes(LOSTargetPtr& arTarget)
{
    kLock.Lock();
    NavMeshRefArray kArray2;
    void* pPos3;
    for (pPos3 = kMap.GetFirstPos(); pPos3;)
    {
        LOSNavMeshInfo* pInfo;
        unsigned int uiKey;
        kMap.GetNext(pPos3, uiKey, pInfo);
        NavMeshRef kRef9;
        if (pInfo->GetNavMeshRef(kRef9))
            kArray2.Add(kRef9);
    }
    ((LOSTarget*)arTarget)->CollectNavMeshes(kArray2);
    for (pPos3 = kMap.GetFirstPos(); pPos3;)
    {
        LOSNavMeshInfo* pInfo2;
        unsigned int uiKey2;
        kMap.GetNext(pPos3, uiKey2, pInfo2);
        NavMeshRef kRefX;
        if (pInfo2->GetNavMeshRef(kRefX))
            pInfo2->Update(arTarget);
    }
    kLock.Unlock();
    return true;
}

// PathingLOSMap access: 0x006d8990/0x006d89b0 use its array at +0x1c, and 0x006e0b00 its seen/unseen counters at +0x30/+0x34; NavMeshArray has its array at +0.
struct TriangleVisibilityData
{
    unsigned int GetCount();
    const NiPointer<NavMesh>& GetAt(unsigned int auiIndex);
    float GetValue();
};

struct GridEntryX
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    GridEntryX(const NavMeshInfo* apInfo);
    bool Update(const NiPointer<TriangleVisibilityData>& arArray);
};

struct EntryMapX
{
    bool GetAt(unsigned int auiKey, GridEntryX*& arVal) const;
    void SetAt(unsigned int auiKey, GridEntryX* apVal);
};

struct LockX
{
    void Lock();
    void Unlock();
};

void* __cdecl operator new(unsigned int);

// Local PathingLOSGridMap fallback: the shared header lacks this update method and the lock at +0x4c.
struct LOSGridUpdateState
{
    int unk00;
    int unk04;
    EntryMapX kMap;
    int unk0C;
    int unk10;
    int unk14;
    float fValue;
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
    LockX kLock;

    bool UpdateFromNavMeshArray(const NiPointer<TriangleVisibilityData>& arArray);
};

// Locks the map, creates or finds a GridEntryX per nav mesh and updates it, then stores the array value in fValue and unlocks.
// @fnv 0x006e0920
bool LOSGridUpdateState::UpdateFromNavMeshArray(const NiPointer<TriangleVisibilityData>& arNavMeshArray)
{
    kLock.Lock();
    for (unsigned int i6 = 0; i6 < arNavMeshArray->GetCount(); i6++)
    {
        NiPointer<NavMesh> spNavMesh2(arNavMeshArray->GetAt(i6));
        GridEntryX* pEntry = 0;
        if (!kMap.GetAt(static_cast<NavMesh*>(spNavMesh2)->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), pEntry))
        {
            pEntry = new GridEntryX(static_cast<NavMesh*>(spNavMesh2)->GetNavMeshInfo_0068efb0());
            kMap.SetAt(static_cast<NavMesh*>(spNavMesh2)->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), pEntry);
        }
        pEntry->Update(arNavMeshArray);
    }
    fValue = arNavMeshArray->GetValue();
    kLock.Unlock();
    return true;
}

class C6E0A90List
{
  public:
    C6E0A90List();
    ~C6E0A90List();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class FUN_006e0a90 : public C6E0A90List
{
  public:
    FUN_006e0a90(const FUN_006e0a90& kOther);

    void CopyFrom(const FUN_006e0a90& kOther);

    int m_iArrayLength;
};

// @fnv 0x006e0a90
FUN_006e0a90::FUN_006e0a90(const FUN_006e0a90& kOther)
{
    m_iArrayLength = 0;
    CopyFrom(kOther);
}

struct FUN_006e0b00_cls
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
    unsigned int m_i30;
    unsigned int m_i34;
    float GetRatio();
};

// Returns m_i30 divided by the sum of m_i30 and m_i34, or 1.0 when that sum is zero.
// @fnv 0x006e0b00
float FUN_006e0b00_cls::GetRatio()
{
    unsigned int total = m_i30 + m_i34;
    if (total != 0)
    {
        return (float)((double)m_i30 / (double)total);
    }
    else
    {
        return 1.0f;
    }
}

struct FUN_0044edb0_shell
{
    void* __thiscall TESMain_GetThread();
};
struct FUN_00559450_shell
{
    void* __thiscall Modelloader_GetReferencedThis(unsigned int*);
};
struct FUN_00853130_shell
{
    bool __thiscall FUN_00853130(void*);
};
struct FUN_006dfdc0_shell
{
    bool __thiscall PathingLOSGrid_IsLocationSeen(void*);
};

struct FUN_006e0b50_cls
{
    unsigned char m_00[8];
    unsigned char m_08[0x10];

    bool __thiscall PathingLOSGridMap_IsLocationSeen(void* aArg);
};

// @fnv 0x006e0b50
// src: XBOX_PDB 0x006e0b50
bool __thiscall FUN_006e0b50_cls::PathingLOSGridMap_IsLocationSeen(void* aArg)
{
    unsigned int value;
    void* pHolder = ((FUN_0044edb0_shell*)aArg)->TESMain_GetThread();
    if (pHolder == 0 || ((PathingLocation*)aArg)->GetShortValueAtOffset24() == 0xffff)
    {
        return false;
    }
    value = 0;
    if (((FUN_00853130_shell*)((char*)this + 8))->FUN_00853130(((FUN_00559450_shell*)pHolder)->Modelloader_GetReferencedThis(&value)))
    {
        return ((FUN_006dfdc0_shell*)value)->PathingLOSGrid_IsLocationSeen(aArg);
    }
    return false;
}

struct LoadBufferEx
{
    unsigned int __thiscall StartVariableSizedValue();
    void __thiscall FUN_00865db0(unsigned int key, unsigned int flags);
    void __thiscall SaveVariableSizedValue_00865ff0(unsigned int writtenCount, unsigned int offset);
    void __thiscall FUN_00865e50(void* value, unsigned int size, unsigned int flags);
};
struct PathingCell
{
    void __thiscall WriteToBuffer(LoadBufferEx* buffer);
};
struct CellMap
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    void* __thiscall FUN_004b9ba0();
    void __thiscall FUN_006b7f20(void*& position, unsigned int& key, PathingCell*& value);
};
struct CellData
{
    virtual void LoadGame(LoadBufferEx* buffer);
    unsigned int unk04, unk08, unk0c, unk10, unk14;
    unsigned int unk18, unk1c, unk20, unk24;
};
struct PathingGrid
{
    unsigned int unk00;
    unsigned int unk04;
    CellMap cells;
    unsigned int unk18;
    CellData metadata;
    unsigned int unk44;
    unsigned int unk48;

    void SaveGame(LoadBufferEx* buffer);
};
// @fnv 0x006e0c40
void PathingGrid::SaveGame(LoadBufferEx* buffer)
{
    unsigned int writtenCount = 0;
    unsigned int startOffset = buffer->StartVariableSizedValue();
    void* position = cells.FUN_004b9ba0();
    while (position != 0)
    {
        PathingCell* cell = 0;
        unsigned int key;
        cells.FUN_006b7f20(position, key, cell);
        if (cell != 0)
        {
            buffer->FUN_00865db0(key, 0);
            cell->WriteToBuffer(buffer);
            writtenCount++;
        }
    }
    buffer->SaveVariableSizedValue_00865ff0(writtenCount, startOffset);
    buffer->FUN_00865e50(&unk18, 4, 0);
    buffer->FUN_00865e50(&unk44, 4, 0);
    buffer->FUN_00865e50(&unk48, 4, 0);
    metadata.LoadGame(buffer);
}

struct Owner6df780
{
    bool valid;
    NavMeshResults results;
    NavMeshLookup* lookup;
    unsigned int identifier;
    bool __thiscall UpdateNavMeshResults(PathingLocation* a1, unsigned char a2);
};
// @fnv 0x006df780
bool __thiscall Owner6df780::UpdateNavMeshResults(PathingLocation* a1, unsigned char a2)
{
    NavMeshKey key;
    if (!lookup->FUN_0069ad00(&key))
        return false;
    IndexList* list3 = key.Modelloader_GetReferencedThis()->NavMesh_GetTrianglesForGridCell(identifier);
    if (valid)
    {
        if (a2)
            return true;
        else
        {
            valid = false;
            results.SetSize(list3->FUN_0044ddc0(), true);
            for (unsigned int i = 0; i < list3->FUN_0044ddc0(); ++i)
            {
                unsigned short w = *list3->BSSimpleArray_unsigned_short_1024_GetAt(i);
                if (w == a1->GetShortValueAtOffset24())
                    results.GetAt(i) = -1;
                else
                    results.GetAt(i) = 1;
            }
            return true;
        }
    }
    else
    {
        if (list3->FUN_0044ddc0() != ((IndexList*)&results)->FUN_0044ddc0())
            return false;
        for (unsigned int i = 0; i < list3->FUN_0044ddc0(); ++i)
        {
            unsigned short w = *list3->BSSimpleArray_unsigned_short_1024_GetAt(i);
            if (w == a1->GetShortValueAtOffset24())
            {
                results.GetAt(i) = a2 ? 1 : -1;
                return true;
            }
        }
    }
    return false;
}

// Destructor of an owning array: delete every element, then the base array frees its storage.

class E04B0Element
{
  public:
    ~E04B0Element();

    int unk00;
};

class E04B0Array
{
  public:
    ~E04B0Array();
    unsigned int GetSize();
    E04B0Element*& GetAt(unsigned int uiIndex) const;

    void* m_pBuffer;
    unsigned int m_uiCapacity;
    unsigned int m_uiSize;
};

class FUN_006e04b0 : public E04B0Array
{
  public:
    ~FUN_006e04b0();
};

// Destructor that iterates over the array and deletes each element pointer returned by GetAt.
// @fnv 0x006e04b0
FUN_006e04b0::~FUN_006e04b0()
{
    for (unsigned int i = 0; i < GetSize(); i++)
        delete GetAt(i);
}

namespace fnv_006e0730 {
class C6E0730List
{
  public:
    C6E0730List();
    ~C6E0730List();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class FUN_006e0730 : public C6E0730List
{
  public:
    FUN_006e0730(const FUN_006e0730& kOther);

    void CopyFrom(const FUN_006e0730& kOther);

    int m_iArrayLength;
};

// @fnv 0x006e0730
FUN_006e0730::FUN_006e0730(const FUN_006e0730& kOther)
{
    m_iArrayLength = 0;
    CopyFrom(kOther);
}
}  // namespace fnv_006e0730


struct FormLoadEntry;



// The approved header set does not yet contain NavMeshLookupView_00693d70.h.
// 0x00693d70 is the NavMeshInfoMap lookup (map at +0x1c), not the static Pathing utility.
struct NavMeshLookupView_00693d70
{
    NavMeshInfo* FindReferenceByFormId();
};

unsigned int _data_011c16bc;
int g_TES;

// @fnv 0x006e0070
// src: COMMUNITY 0x006e0070
void FUN_006e0480::Lst0044_Data00D4_Arr0004_Load(BGSLoadFormBuffer* apLoadGameBuffer)
{
    unsigned int inavmeshID;

    inavmeshID = 0;
    apLoadGameBuffer->ReadFormIdentifier(static_cast<void*>(&inavmeshID));

    ((NavMeshInfo**)((char*)this + 0x10))[0] =
        ((NavMeshLookupView_00693d70*)((TES*)g_TES)->GetActiveCell(inavmeshID))->FindReferenceByFormId();

    {
        unsigned int isaveGameCount;

        isaveGameCount = apLoadGameBuffer->ReadElementCount();
        ((BSSimpleArray<FormLoadEntry*>*)this)->SetSize(isaveGameCount, true);

        {
            unsigned int i;

            for (i = 0; i < isaveGameCount; ++i)
            {
                FormLoadEntry** ppFormLoadEntry;

                ppFormLoadEntry = &((BSSimpleArray<FormLoadEntry*>*)this)->GetAt((int)i);
                *ppFormLoadEntry = (FormLoadEntry*)new FUN_006e0190();

                (*ppFormLoadEntry)->LoadForm(apLoadGameBuffer);
                ((TESConditionItem*)*ppFormLoadEntry)->SetObjectType((int)((NavMeshInfo**)((char*)this + 0x10))[0]);
            }
        }
    }
}

// @fnv 0x006e02a0
PathingLOSGridMap::~PathingLOSGridMap()
{
    ClearMap();
}
