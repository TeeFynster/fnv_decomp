#include "../../../include/NavMeshInfo.h"
// fallout_shared/pathfinding/navmeshinfomap.cpp: NavMeshInfoMap, std, NavMeshInfo and more (26 functions)

#include "../../../include/MemoryManager.h"
#include "../../../include/TESFile.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/AutoMemContext.h"
#include "../../../include/MapEntryCount.h"
#include "../../../include/TESWorldSpace.h"
#include "../../../include/DummyPointerMap.h"
#include "../../../include/GridArray.h"
#include "../../../include/TESRecipe.h"
#include "../../../include/NavMesh.h"
#include "../../../include/NavMeshBounds.h"
#include "../../../include/NavMeshPtr.h"
#include "../../../include/NavMeshInfoMap.h"

// NavMeshInfoMap: bounding-box verification and loaded-info initialization.
// NavMeshBounds, BSSimpleArray 16, NiTPointerMap 16) with layout asserts.

#include <stddef.h>
#include <malloc.h>
#include "../../../include/TESObjectCELL.h"
#include "../../../include/MEM_CONTEXT.h"
#include "../../../include/ENUM_FORM_ID.h"
template <int N> struct EndianSizeTag
{
    char value;
};
void BSEndian(unsigned int*, EndianSizeTag<4>);
void BSEndian(int*, EndianSizeTag<4>);
void* operator new(unsigned int);
void operator delete(void*);
// Global allocation wrapper at 0x00401000, distinct from the manager member allocator.
void* __cdecl FNV_AllocateBuffer(unsigned int);
void FNV_DeleteBuffer(void*);

#define NULL 0

#pragma pack(push, 4)

typedef char BSSimpleArrayCheck[sizeof(BSSimpleArray<NavMeshInfo*, 1024>) == 16 ? 1 : -1];

// Kept local: include/NavMeshInfo.h lacks the cell lookup, save and validation helpers below.

typedef char NavMeshInfoCheckSize[sizeof(NavMeshInfo) == 92 ? 1 : -1];
typedef char NavMeshInfoCheckBounds[offsetof(NavMeshInfo, pBounds) == 0x58 ? 1 : -1];

#include "../../../include/NiTMapItem.h"

typedef char NiTMapCheck[sizeof(NiTPointerMap<unsigned int, void*>) == 16 ? 1 : -1];

typedef NiTPointerMap<unsigned int, void*> CellKeyMap;

struct OuterPair
{
    void* pInnerMapRaw;
    unsigned int uiOuterKey;
};

struct InnerCounts
{
    unsigned int uiIndex;
    unsigned int uiValid;
};

typedef char TESFormCheck[sizeof(TESForm) == 24 ? 1 : -1];

typedef char NavMeshInfoMapCheck[sizeof(NavMeshInfoMap) == 64 ? 1 : -1];
typedef char NavMeshInfoMapCheckCell[offsetof(NavMeshInfoMap, m_kNavMeshInfoArraysByWorldspace) == 0x2C ? 1 : -1];

#pragma pack(pop)

typedef BSSimpleArray<TESObjectREFR*, 1024> NavMeshDoorArray;

unsigned int NavMeshInfo_GetCellOrCoords(NavMeshInfo*);
bool Actor_AreReferencedValuesEqual(NavMeshInfo*&, NavMeshInfo*&);

// Scans every outer/inner map entry and returns false if any NavMeshInfoArray with more than one element has fewer than size-1 entries with bounds.
// @fnv 0x006b7cb0
bool NavMeshInfoMap::ValidateNavMeshInfoArrays()
{
    bool bResult = true;
    void* pOuterPos = m_kNavMeshInfoArraysByWorldspace.GetFirstPos();
    while (pOuterPos)
    {
        OuterPair outer;
        m_kNavMeshInfoArraysByWorldspace.GetNext(pOuterPos, outer.uiOuterKey, reinterpret_cast<NiTPointerMap<unsigned int, NavMeshInfoArray*>*&>(outer.pInnerMapRaw));
        void* pInnerPos = ((CellKeyMap*)outer.pInnerMapRaw)->GetFirstPos();
        while (pInnerPos)
        {
            unsigned int uiInnerKey;
            void* pArrayRaw;
            ((CellKeyMap*)outer.pInnerMapRaw)->GetNext(pInnerPos, uiInnerKey, pArrayRaw);
            if (((NavMeshInfoArray*)pArrayRaw)->GetSize() > 1)
            {
                InnerCounts counts;
                counts.uiValid = 0;
                for (counts.uiIndex = 0; counts.uiIndex < ((NavMeshInfoArray*)pArrayRaw)->GetSize(); counts.uiIndex++)
                {
                    if (((NavMeshInfoArray*)pArrayRaw)->GetAt((int)counts.uiIndex)->GetBounds())
                        counts.uiValid++;
                }
                if (counts.uiValid < ((NavMeshInfoArray*)pArrayRaw)->GetSize() - 1)
                    bResult = false;
            }
        }
    }
    return bResult;
}

namespace std {
float abs(float value);
}
int Warning(const char* format, ...);

struct NavMeshValidation
{
    unsigned int id;
    void* info;
    TESForm* parent;
};

// Validates each NavMeshInfo entry, warns and deletes entries with missing parent space or bad approx location, otherwise links parent and initializes it.
// @fnv 0x006b63c0
void NavMeshInfoMap::InitItem()
{
    void* pPos;
    {
        NavMeshInfoArray DeleteArray;
        pPos = m_kNavMeshInfosByFormID.GetFirstPos();
        while (pPos)
        {
            bool bDelete;
            {
                NavMeshValidation entry;
                m_kNavMeshInfosByFormID.GetNext(pPos, entry.id, reinterpret_cast<NavMeshInfo*&>(entry.info));
                bDelete = false;
                entry.parent = TESForm::GetFormByID(((NavMeshInfo*)entry.info)->m_uiParentSpaceID);
                if (!entry.parent)
                {
                    Warning("MASTERFILE: Could not find Parent Space with ID %08x for NavmeshInfo %08x",
                            ((NavMeshInfo*)entry.info)->m_uiParentSpaceID, entry.id);
                    bDelete = true;
                }
                if (std::abs(((NavMeshInfo*)entry.info)->m_kNavMeshPosition.z) > 1.0e14f)
                {
                    Warning("MASTERFILE: NavmeshInfo %08x has bad approx location, ignoring", entry.id);
                    bDelete = true;
                }
                if (bDelete)
                {
                    DeleteArray.Add((NavMeshInfo*&)entry.info);
                }
                else
                {
                    ((NavMeshInfo*)entry.info)->m_pParentSpace = entry.parent;
                    InsertNavMeshInfo((NavMeshInfo*)entry.info);
                }
                if (!m_bKeepNavMeshLoaded)
                    ((NavMeshInfo*)entry.info)->ReleaseNavMesh();
            }
        }
        for (unsigned int uiIndex = 0; uiIndex < DeleteArray.GetSize(); uiIndex++)
        {
            m_kNavMeshInfosByFormID.RemoveAt(DeleteArray[uiIndex]->GetNavMeshID());
            delete DeleteArray[uiIndex];
        }
        m_bKeepNavMeshLoaded = true;
        ValidateNavMeshInfoArrays();
    }
}

// Registers info in the per-parent NavMeshInfoArray for its cell key, creating the inner map and array as needed, and skips if already present.
// @fnv 0x006b7980
void NavMeshInfoMap::InsertNavMeshInfo(NavMeshInfo* info)
{
    struct CellKeyLookup
    {
        void* innerMap;
        unsigned int parentID;
        unsigned int cellKey;
    } lookup;
    lookup.cellKey = NavMeshInfo_GetCellOrCoords(info);
    if (info->GetInteriorCell())
        lookup.parentID = 0;
    else
        lookup.parentID = info->m_uiParentSpaceID;
    if (!m_kNavMeshInfoArraysByWorldspace.GetAt(lookup.parentID, reinterpret_cast<NiTPointerMap<unsigned int, NavMeshInfoArray*>*&>(lookup.innerMap)))
    {
        unsigned int hashSize = 103;
        if (!lookup.parentID)
        {
            hashSize = 1009;
        }
        else
        {
            TESWorldSpace* world = (TESWorldSpace*)TESForm::GetFormByID(lookup.parentID);
            if (world && !world->GetSmallWorld())
                hashSize = 1009;
        }
        lookup.innerMap = new NiTPointerMap<unsigned int, NavMeshInfoArray*>(hashSize);
        m_kNavMeshInfoArraysByWorldspace.SetAt(lookup.parentID, (NiTPointerMap<unsigned int, NavMeshInfoArray*>*)lookup.innerMap);
    }
    NavMeshInfoArray* array;
    if (!((NiTPointerMap<unsigned int, NavMeshInfoArray*>*)lookup.innerMap)->GetAt(lookup.cellKey, array))
    {
        array = new NavMeshInfoArray;
        ((NiTPointerMap<unsigned int, NavMeshInfoArray*>*)lookup.innerMap)->SetAt(lookup.cellKey, array);
    }
    if (array->Find(info, 0, Actor_AreReferencedValuesEqual) != (unsigned int)-1)
        return;
    array->Add(info);
}

// @fnv 0x006b46a0
NavMeshInfo::NavMeshInfo()
{
    uiFlags = 0;
    m_uiNavMeshID = 0;
    m_uiParentSpaceID = 0;
    m_pParentSpace = 0;
    m_uiPathingFlags = 0xdeaddead;
    m_kNavMeshPosition = NiPoint3::ZERO;
    pBounds = 0;
    m_pLocationNavMesh = 0;
    m_fStoredValue = 0.0f;
}

// @fnv 0x006b5c30
NavMeshInfoMap::NavMeshInfoMap()
    : m_bNavMeshInfoArraysValid(false), m_kNavMeshInfosByFormID(10009), m_kNavMeshInfoArraysByWorldspace(103),
      m_bKeepNavMeshLoaded(false)
{
    SetFormType(ENUM_FORM_ID_NAVI_ID);
}

extern int DAT_01031fac;

struct FUN_006b7d90_arg
{
    unsigned int val;
};

void __fastcall FUN_005890c0(int* self, FUN_006b7d90_arg a);

// Calls FUN_005890c0 on self, then stores the address of DAT_01031fac into *self and returns self.
// @fnv 0x006b7d90
// src: EXE 0x006b7d90
int* __fastcall NiTPointerMap_unsigned_int_NavMeshInfo_NiTPointerMap(int* self, FUN_006b7d90_arg aArg)
{
    FUN_005890c0(self, aArg);
    *self = (int)&DAT_01031fac;
    return self;
}

namespace fnv_006b7dc0 {
extern int DAT_01031fac;

struct FUN_006b7dc0_arg
{
    unsigned int val;
};

void __fastcall FUN_005890c0(int* self, FUN_006b7dc0_arg a);

// Calls FUN_005890c0 on self, then stores the address of DAT_01031fac into *self and returns self.
// @fnv 0x006b7dc0
// src: EXE 0x006b7dc0
int* __fastcall NiTMap_unsigned_int_NiTMap_unsigned_int_BSSimpleArray_NavMeshInfo_1024_NiTMap(int* self, FUN_006b7dc0_arg aArg)
{
    FUN_005890c0(self, aArg);
    *self = (int)&DAT_01031fac;
    return self;
}
}  // namespace fnv_006b7dc0

namespace fnv_006b7df0 {
extern int DAT_01031fac;

struct FUN_006b7df0_arg
{
    unsigned int val;
};

void __fastcall FUN_005890c0(int* self, FUN_006b7df0_arg a);

// Calls FUN_005890c0 on self, then stores the address of DAT_01031fac into *self and returns self.
// @fnv 0x006b7df0
// src: EXE 0x006b7df0
int* __fastcall NiTMap_unsigned_int_BSSimpleArray_NavMeshInfo_1024_NiTMap(int* self, FUN_006b7df0_arg aArg)
{
    FUN_005890c0(self, aArg);
    *self = (int)&DAT_01031fac;
    return self;
}
}  // namespace fnv_006b7df0

extern "C" void* __cdecl _alloca(unsigned int);
// Exe 0x006b5d80: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct NavmeshinfomapOffset08View
{
    unsigned int GetFlags();
};
struct Arr
{
    unsigned int* GetAt(int);
};

// @fnv 0x006b5d80
bool NavMeshInfoMap::LoadNavMeshInfoMap(TESFile* apFile)
{
    int ifileVersionNumber;
    AutoMemContext tempMemContext(
        (MEM_CONTEXT)0x2e, true,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Pathfinding\\NavMeshInfoMap.cpp", 0x5c);
    if (m_bKeepNavMeshLoaded)
    {
        void* it = m_kNavMeshInfosByFormID.GetFirstPos();
        while (it)
        {
            unsigned int navmeshID;
            NavMeshInfo* pinfo;
            m_kNavMeshInfosByFormID.GetNext(it, navmeshID, reinterpret_cast<NavMeshInfo*&>(pinfo));
            for (unsigned int i = 0; i < ((NavmeshinfomapOffset08View*)&pinfo->m_kDoorReferences)->GetFlags(); i++)
                *((Arr*)&pinfo->m_kDoorReferences)->GetAt(i) = (*(TESForm**)((Arr*)&pinfo->m_kDoorReferences)->GetAt(i))->GetFormID();
        }
        m_bKeepNavMeshLoaded = false;
    }
    int ibuffersize = 0x9b0;
    void* pchunkdata = FNV_AllocateBuffer(ibuffersize);
    unsigned char formid = apFile->GetTESForm();
    if (formid != 0x38)
        return false;
    unsigned int thisID = ((TESForm*)this)->GetFormID();
    ((TESForm*)this)->LoadRecordHeader(apFile);
    ifileVersionNumber = 1;
    do
    {
        switch ((int)apFile->GetChunkID())
        {
        case 0x44494445: {
            char* pMessage = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(pMessage, 0x200);
            ((TESForm*)this)->SetEditorID_AtRuntime(pMessage);
            break;
        }
        case 0x444e424f:
            ((TESForm*)this)->readOBNDSubRecord(apFile);
            break;
        case 0x5245564e:
            apFile->GetChunkData(&ifileVersionNumber, 0);
            if (apFile->IsEndianConversionRequired())
                BSEndian(&ifileVersionNumber, EndianSizeTag<4>());
            if (ifileVersionNumber < 5)
                m_bNavMeshInfoArraysValid = true;
            break;
        case 0x494d564e: {
            int ichunksize = apFile->GetChunkSize();
            if (ichunksize > ibuffersize)
            {
                FNV_DeleteBuffer(pchunkdata);
                ibuffersize = ichunksize;
                pchunkdata = FNV_AllocateBuffer(ibuffersize);
            }
            apFile->GetChunkData(pchunkdata, ichunksize);
            NavMeshInfo* pnewInfo = new NavMeshInfo;
            pnewInfo->LoadNavMeshInfo((char*)pchunkdata, apFile, ifileVersionNumber);
            NavMeshInfo* poldInfo = FUN_00693d70(pnewInfo->GetNavMeshID());
            if (poldInfo)
            {
                NavMeshPtr sppreviousNavMesh;
                bool bhasNavMesh = poldInfo->AcquireNavMesh(sppreviousNavMesh);
                BSSimpleArray<NavMeshInfo*, 1024> oldadjacentNavMeshes;
                BSSimpleArray<NavMeshInfo*, 1024> oldpreferredAdjacentNavMeshes;
                BSSimpleArray<TESObjectREFR*, 1024> oldconnectedDoors;
                poldInfo->m_kConnectedNavMeshInfos.CopyTo(&oldadjacentNavMeshes);
                poldInfo->m_kPreferredConnections.CopyTo(&oldpreferredAdjacentNavMeshes);
                poldInfo->m_kDoorReferences.CopyTo(&oldconnectedDoors);
                pnewInfo->CopyTo(poldInfo);
                if (bhasNavMesh)
                    ((TESRecipe*)poldInfo)->SetCategory(((NavMeshInfo*)&sppreviousNavMesh)->GetNavMeshID());
                oldadjacentNavMeshes.CopyTo(&poldInfo->m_kConnectedNavMeshInfos);
                oldpreferredAdjacentNavMeshes.CopyTo(&poldInfo->m_kPreferredConnections);
                oldconnectedDoors.CopyTo(&poldInfo->m_kDoorReferences);
                delete pnewInfo;
            }
            else
            {
                ((DummyPointerMap*)&m_kNavMeshInfosByFormID)->SetAt(pnewInfo->GetNavMeshID(), (unsigned int)pnewInfo);
            }
            break;
        }
        case 0x4943564e: {
            int ichunksize = apFile->GetChunkSize();
            if (ichunksize > ibuffersize)
            {
                FNV_DeleteBuffer(pchunkdata);
                ibuffersize = ichunksize;
                pchunkdata = FNV_AllocateBuffer(ibuffersize);
            }
            apFile->GetChunkData(pchunkdata, ichunksize);
            char* pchunkPointer = (char*)pchunkdata;
            unsigned int infoID = *(unsigned int*)pchunkPointer;
            if (apFile->IsEndianConversionRequired())
                BSEndian(&infoID, EndianSizeTag<4>());
            TESForm::RemapFormIDForFile(infoID, apFile);
            pchunkPointer += 4;
            NavMeshInfo* pinfo;
            if (!((const DummyPointerMap*)&m_kNavMeshInfosByFormID)->GetAt(infoID, (unsigned int&)pinfo))
                return false;
            if (ifileVersionNumber >= 5)
                pinfo->LoadSerializedData(pchunkPointer, apFile, ifileVersionNumber);
            break;
        }
        }
    } while (apFile->NextChunk());
    FNV_DeleteBuffer(pchunkdata);
    return true;
}

// @fnv 0x006b5cd0
void* __fastcall DeleteNavMeshInfoMap(NavMeshInfoMap* self, void*, unsigned int flags)
{
    self->NavMeshInfoMap::~NavMeshInfoMap();
    if (flags & 1)
        FNV_DeleteBuffer(self);
    return self;
}

struct TESFormCall
{
    void SetAltered(bool);
    void Revert(unsigned int);
};
// Calls SetAltered with abVal; when abVal is false, iterates the map at offset 0x1c and reverts each NavMeshInfo.
// @fnv 0x006b68b0
void NavMeshInfoMap::SetAlteredAndRevertNavMeshes(bool abVal)
{
    ((TESFormCall*)this)->SetAltered(abVal);
    if (!abVal)
    {
        void* it;
        unsigned int navmeshID;
        NavMeshInfo* pinfo;
        it = m_kNavMeshInfosByFormID.GetFirstPos();
        while (it)
        {
            m_kNavMeshInfosByFormID.GetNext(it, navmeshID, reinterpret_cast<NavMeshInfo*&>(pinfo));
            ((TESFormCall*)pinfo)->TESFormCall::Revert(0);
        }
    }
}

int __fastcall _FNV_GetFormType(TESForm* apForm);
struct FUN_00484020_shell
{
    bool IsLessThan(TESForm* apForm);
};
// Returns true if apForm's form type is 0x43, otherwise delegates to IsLessThan.
// @fnv 0x006b6910
// src: XBOX_PDB 0x006b6910
bool NavMeshInfoMap::SavesBefore_006b6910(TESForm* apForm)
{
    if (::_FNV_GetFormType(apForm) == 0x43)
        return true;
    return ((FUN_00484020_shell*)this)->IsLessThan(apForm);
}

namespace fnv_006b7850 {

unsigned int PrepareScriptMessage(int);
}  // namespace fnv_006b7850

// Looks up the worldspace's map by form ID, then the cell's entry by prepared key, returning the stored info pointer or null.
// @fnv 0x006b7850
// src: XBOX_PDB 0x006b7850
void* NavMeshInfoMap::FindNavMeshInfoForCellKey(TESWorldSpace* apWorldSpace, int aiCellKey)
{
    const DummyPointerMap* worldspaceMap;
    void* infoarray;
    if (!reinterpret_cast<const DummyPointerMap*>(&m_kNavMeshInfoArraysByWorldspace)
             ->GetAt(reinterpret_cast<TESForm*>(apWorldSpace)->GetFormID(),
                     reinterpret_cast<unsigned int&>(worldspaceMap)))
        return 0;
    if (!worldspaceMap->GetAt(fnv_006b7850::PrepareScriptMessage(aiCellKey), reinterpret_cast<unsigned int&>(infoarray)))
        return 0;
    return infoarray;
}

namespace fnv_006b7910 {
struct _Mem_20a4
{
    void SetSize(unsigned int, bool);
};
struct HArr
{
    void GrowCapacity(unsigned int);
};
}  // namespace fnv_006b7910

// @fnv 0x006b7910
// src: COMMUNITY 0x006b7910
void NavMeshInfoMap::GetAllNavMeshInfo(BSSimpleArray<void*, 1024>* pArray)
{
    ((fnv_006b7910::_Mem_20a4*)pArray)->SetSize(0, false);
    ((fnv_006b7910::HArr*)pArray)->GrowCapacity(0x800);
    void* it = m_kNavMeshInfosByFormID.GetFirstPos();
    while (it)
    {
        void* pinfo;
        unsigned int navmeshID;
        m_kNavMeshInfosByFormID.GetNext(it, navmeshID, reinterpret_cast<NavMeshInfo*&>(pinfo));
        pArray->Add(pinfo);
    }
}

namespace fnv_006b78b0 {
const char* __cdecl PrepareScriptMessage(const char*);
}  // namespace fnv_006b78b0

// Looks up two map entries: one at key 0, then one keyed by PrepareScriptMessage(s), returning the second value or 0 if either lookup fails.
// @fnv 0x006b78b0
unsigned int NavMeshInfoMap::LookupScriptMessageValue(const char* pcScriptMessage)
{
    unsigned int uiValue;
    {
        unsigned int uiMapPtr;
        if (!reinterpret_cast<const DummyPointerMap&>(m_kNavMeshInfoArraysByWorldspace).GetAt(0, uiMapPtr))
            return 0;
        if (!((const DummyPointerMap*)uiMapPtr)->GetAt((unsigned int)fnv_006b78b0::PrepareScriptMessage(pcScriptMessage), uiValue))
            return 0;
        return uiValue;
    }
}

// Destructor that calls ClearNavMeshInfoMaps before the object is torn down.
// @fnv 0x006b5d00
NavMeshInfoMap::~NavMeshInfoMap()
{
    ClearNavMeshInfoMaps();
}

namespace fnv_006b77e0 {
struct CellH
{
    int GetCellGridX();
    int GetCellGridY();
};
struct DoorH
{
    void* GetParentWorldSpace();
};
int __cdecl BuildCellKey(short, short);
}  // namespace fnv_006b77e0

// @fnv 0x006b77e0
// src: XBOX_PDB 0x006b77e0
int NavMeshInfoMap::FindNavMeshInfoForCell(TESObjectCELL* cell)
{
    if (!cell)
        return 0;
    if (cell->IsInterior())
        return LookupScriptMessageValue(cell);
    else
        return FindNavMeshInfoForCellKey(((fnv_006b77e0::DoorH*)cell)->GetParentWorldSpace(),
                            fnv_006b77e0::BuildCellKey((short)((fnv_006b77e0::CellH*)cell)->GetCellGridX(), (short)((fnv_006b77e0::CellH*)cell)->GetCellGridY()));
}

// @fnv 0x006b7770
// src: XBOX_PDB 0x006b7770
TESObjectCELL* NavMeshInfo::GetCell()
{
    TESWorldSpace* worldSpace = GetParentWorldSpace();
    if (worldSpace)
    {
        return worldSpace
            ->GetCellByKey(static_cast<unsigned int>(m_uiPathingFlags));
    }
    else
    {
        return reinterpret_cast<NavMeshInfo*>(this)->GetInteriorCell();
    }
}

struct FormView
{
    unsigned int FUN_00401170();
};
struct FormArray
{
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    FormView** FUN_00877a30(unsigned int);
};
extern FormArray* DAT_011c54c4;
struct InfoView
{
    bool FUN_0047c850();
};
struct PtrView
{
    NavMesh* Modelloader_GetReferencedThis();
};
// @fnv 0x006b6580
// src: XBOX_PDB 0x006b6580
bool NavMeshInfoMap::ProcessBeforeSave()
{
    if (!FUN_00460340())
        return true;
    FormView* formTmp;
    unsigned int i5;
    unsigned int total4 = DAT_011c54c4->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    unsigned int count4 = 0;
    for (i5 = 0; i5 < total4; i5++)
    {
        formTmp = *DAT_011c54c4->FUN_00877a30(i5);
        if (formTmp->FUN_00401170() == 0x43)
            count4++;
    }
    if (count4 == 0)
    {
        bool found6 = false;
        void* pos4 = m_kNavMeshInfosByFormID.GetFirstPos();
        while (pos4)
        {
            unsigned int keyTmp;
            void* value5;
            m_kNavMeshInfosByFormID.GetNext(pos4, keyTmp, reinterpret_cast<NavMeshInfo*&>(value5));
            if (((InfoView*)value5)->FUN_0047c850())
            {
                found6 = true;
                break;
            }
        }
        if (!found6)
        {
            SetAltered(false);
            return true;
        }
    }
    void* position = m_kNavMeshInfosByFormID.GetFirstPos();
    while (position)
    {
        unsigned int key3;
        void* valueVal;
        m_kNavMeshInfosByFormID.GetNext(position, key3, reinterpret_cast<NavMeshInfo*&>(valueVal));
        NavMeshPtr mesh8;
        if (((NavMeshInfo*)valueVal)->AcquireNavMesh(mesh8) && mesh8.Modelloader_GetReferencedThis()->FUN_00460340() &&
            !mesh8.Modelloader_GetReferencedThis()->FUN_00440d80())
            mesh8.Modelloader_GetReferencedThis()->FUN_006986d0();
    }
    ValidateNavMeshes();
    return true;
}

struct NavigationRequest
{
    int stored;
    bool FUN_00690860(void* output);
    int FUN_006b6390(bool enable);
};
struct BoundNavigationMap
{
    bool FUN_00853130(int entry, NavigationRequest** request);
    void RemoveKey(int entry);
};
struct ScopedNavPointer
{
    void* current;
    void FUN_0042fb00();
    void Object_ForwardCall_0042fa40();
    void* Modelloader_GetReferencedThis(int index);
    ScopedNavPointer()
    {
        FUN_0042fb00();
    }
    ~ScopedNavPointer()
    {
        Object_ForwardCall_0042fa40();
    }
};
struct ActiveResolver
{
    void* FUN_00484e60();
};
struct VerifiedPath
{
    bool FUN_00471c20();
};
// @fnv 0x006b6a00
void NavMeshInfoMap::ActivateNavigationEntry(int identifier)
{
    NavigationRequest* entry;
    if (reinterpret_cast<BoundNavigationMap*>(&m_kNavMeshInfosByFormID)->FUN_00853130(identifier, &entry))
    {
        RemoveInfoFromCellKeyMap(entry);
        bool isAccepted = false;
        ScopedNavPointer pointer;
        if (entry->FUN_00690860(&pointer))
        {
            VerifiedPath* active = reinterpret_cast<VerifiedPath*>(
                reinterpret_cast<ActiveResolver*>(pointer.Modelloader_GetReferencedThis(0))->FUN_00484e60());
            if (active && active->FUN_00471c20())
                isAccepted = true;
        }
        {
            NavigationRequest* selected = entry;
            NavigationRequest* target = selected;
            target ? target->FUN_006b6390(true) : 0;
        }
        reinterpret_cast<BoundNavigationMap*>(&m_kNavMeshInfosByFormID)->RemoveKey(identifier);
        if (isAccepted)
            SetAltered(true);
    }
}

unsigned int NavMeshInfo_GetCellOrCoords(NavMeshInfo*);
bool Actor_AreReferencedValuesEqual(NavMeshInfo*&, NavMeshInfo*&);
struct InfoArray
{
    virtual ~InfoArray();
    unsigned int FUN_00719b20(NavMeshInfo* const&, unsigned int, bool (*)(NavMeshInfo*&, NavMeshInfo*&));
    void BSSimpleArray_HUDMainMenu_SubtitleData_1024_Remove(unsigned int, bool);
    bool NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty();
};
struct InnerMap
{
    virtual ~InnerMap();
    bool FUN_00853130(unsigned int, InfoArray*&);
    bool RemoveKey(unsigned int);
    bool IsFieldCZero();
};
struct OuterMap
{
    bool FUN_00853130(unsigned int, InnerMap*&);
    bool RemoveKey(unsigned int);
};
// @fnv 0x006b7b70
// src: COMMUNITY 0x006b7b70
void NavMeshInfoMap::RemoveInfoFromCellKeyMap(NavMeshInfo* info)
{
    unsigned int parent = NavMeshInfo_GetCellOrCoords(info);
    unsigned int map;
    if (info->GetInteriorCell())
        map = 0;
    else
        map = info->m_uiParentSpaceID;
    InnerMap* array;
    if (!reinterpret_cast<OuterMap&>(m_kNavMeshInfoArraysByWorldspace).FUN_00853130(map, array))
        return;
    InfoArray* index;
    if (!array->FUN_00853130(parent, index))
        return;
    unsigned int key = index->FUN_00719b20(info, 0, Actor_AreReferencedValuesEqual);
    if (key == -1)
        return;
    index->BSSimpleArray_HUDMainMenu_SubtitleData_1024_Remove(key, true);
    if (index->NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
    {
        array->RemoveKey(parent);
        delete index;
        if (array->IsFieldCZero())
        {
            reinterpret_cast<OuterMap&>(m_kNavMeshInfoArraysByWorldspace).RemoveKey(map);
            delete array;
        }
    }
}

void SaveFormVersion(unsigned int auiChunkID, int aiVersion);
void SaveFormChunk(unsigned int auiChunkID, void* apData, unsigned int auiSize);
bool IsSaveEndianSwapped();

// Starts a save, writes the REVN version, then writes an IMVN info chunk and an ICVN index chunk for each navmesh entry, and ends the save.
// @fnv 0x006b6740
void NavMeshInfoMap::SaveNavMeshInfoMap()
{
    StartSave();
    SaveFormVersion('REVN', 11);

    void* pos2 = m_kNavMeshInfosByFormID.GetFirstPos();
    while (pos2)
    {
        unsigned int key;
        void* info3;
        m_kNavMeshInfosByFormID.GetNext(pos2, key, reinterpret_cast<NavMeshInfo*&>(info3));
        unsigned int sizeB = ((NavMeshInfo*)info3)->GetInfoChunkSize();
        char* buffer_ = (char*)operator new(sizeB);
        ((NavMeshInfo*)info3)->WriteInfoChunk(buffer_);
        SaveFormChunk('IMVN', buffer_, sizeB);
        operator delete(buffer_);
    }

    pos2 = m_kNavMeshInfosByFormID.GetFirstPos();
    while (pos2)
    {
        unsigned int key3;
        void* info6;
        m_kNavMeshInfosByFormID.GetNext(pos2, key3, reinterpret_cast<NavMeshInfo*&>(info6));
        unsigned int size2 = ((NavMeshInfo*)info6)->GetIndexChunkSize() + 4;
        char* bufferVal = (char*)operator new(size2);
        char* cur3 = bufferVal;
        unsigned int id5 = ((NavMeshInfo*)info6)->GetNavMeshID();
        if (IsSaveEndianSwapped())
        {
            BSEndian(&id5, EndianSizeTag<4>());
        }
        *(unsigned int*)cur3 = id5;
        cur3 += 4;
        ((NavMeshInfo*)info6)->WriteIndexChunk(cur3);
        SaveFormChunk('ICVN', bufferVal, size2);
        operator delete(bufferVal);
    }
    EndSave();
}

struct CellKeyStand
{
    bool IsEmpty();
};
bool __fastcall IsFieldCZero(DummyPointerMap* p);
// @fnv 0x006b6990
// src: GUESS 0x006b6990 (confidence: low)
void NavMeshInfoMap::ProcessState_006b6990(unsigned int id)
{
    unsigned int info;
    if (reinterpret_cast<NiTPointerMap<unsigned int, unsigned int>*>(&m_kNavMeshInfosByFormID)->GetAt(id, info))
    {
        reinterpret_cast<CellKeyMap*>(&m_kNavMeshInfosByFormID)->RemoveAt(id);
        if (!IsFieldCZero(reinterpret_cast<DummyPointerMap*>(&m_kNavMeshInfoArraysByWorldspace)))
        {
            RemoveInfoFromCellKeyMap(info);
        }
        SetAltered(true);
    }
}

template <class V> struct FUN_006b6b20_Map
{
    virtual ~FUN_006b6b20_Map();
    unsigned int m_uiHashSize;
    void* m_ppkHashTable;
    unsigned int m_uiCount;
    void* FUN_004b9ba0();
    void FUN_006b7f20(void*& rpPos, unsigned int& ruiKey, V& rkValue);
    void FUN_00438af0();
};
struct CellNavMeshInfoArray
{
    virtual ~CellNavMeshInfoArray();
};
typedef FUN_006b6b20_Map<CellNavMeshInfoArray*> CellNavMeshInfoMap;
// Deletes every NavMeshInfo in the first map and every CellNavMeshInfoMap with its arrays in the second, clears both maps, then calls Unk_32(true).
// @fnv 0x006b6b20
void NavMeshInfoMap::ClearNavMeshInfoMaps()
{
    void* pPos = ((FUN_006b6b20_Map<NavMeshInfo*>*)&m_kNavMeshInfosByFormID)->FUN_004b9ba0();
    while (pPos)
    {
        unsigned int uiKey;
        NavMeshInfo* pInfo;
        ((FUN_006b6b20_Map<NavMeshInfo*>*)&m_kNavMeshInfosByFormID)->FUN_006b7f20(pPos, uiKey, pInfo);
        delete pInfo;
    }
    ((FUN_006b6b20_Map<NavMeshInfo*>*)&m_kNavMeshInfosByFormID)->FUN_00438af0();
    pPos = ((FUN_006b6b20_Map<CellNavMeshInfoMap*>*)&m_kNavMeshInfoArraysByWorldspace)->FUN_004b9ba0();
    while (pPos)
    {
        unsigned int uiCellKey;
        CellNavMeshInfoMap* pCellNavMeshInfoMap;
        ((FUN_006b6b20_Map<CellNavMeshInfoMap*>*)&m_kNavMeshInfoArraysByWorldspace)
            ->FUN_006b7f20(pPos, uiCellKey, pCellNavMeshInfoMap);
        void* pInnerPos = pCellNavMeshInfoMap->FUN_004b9ba0();
        while (pInnerPos)
        {
            unsigned int uiInfoKey;
            CellNavMeshInfoArray* pArray;
            pCellNavMeshInfoMap->FUN_006b7f20(pInnerPos, uiInfoKey, pArray);
            delete pArray;
        }
        delete pCellNavMeshInfoMap;
    }
    ((FUN_006b6b20_Map<CellNavMeshInfoMap*>*)&m_kNavMeshInfoArraysByWorldspace)->FUN_00438af0();
    SetAltered(true);
}

struct MeshInfoArray;
struct CellView
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
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
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual const char* GetEditorID();
};

struct MeshInfoArray
{
    void* vtable;
    NavMeshInfo** items;
    unsigned int count;
    unsigned int capacity;
    unsigned int FUN_0044ddc0();
    NavMeshInfo** FUN_00877a30(unsigned int);
    NavMeshInfo** BSSimpleArray_NiAVObject_1024_GetAt(unsigned int);
    void BSSimpleArray_HUDMainMenu_SubtitleData_1024_Remove(unsigned int, bool);
    unsigned int FUN_00719b20(NavMeshInfo* const&, unsigned int, bool(__cdecl*)(NavMeshInfo*&, NavMeshInfo*&));
};
TESForm* __fastcall NavMeshInfo_GetParentSpace(const NavMeshInfo*);

struct DataMatch
{
    unsigned int key;
    NavMeshInfo* info;
    bool NavMeshTriangleEdgePortal_IsValid();
};
struct GridRecord
{
    void* unk00;
    NavMeshInfo* info;
};
struct GridLookup
{
    MeshInfoArray* FindNavMeshInfoForCellKey(NavMesh*, unsigned int);
};
struct GridMap
{
    GridMap();
    ~GridMap();
    NavMesh* Modelloader_GetReferencedThis();
    void* GetEdge(unsigned short);
    void* FUN_0068f6b0(unsigned short);
    unsigned int GetArrFlags();
    unsigned int NavMesh_GetNumDoorPortals();
    void CollectTrianglesForDoor(NavMeshInfo*, void*);
};
struct LinkChecker
{
    void* vtable;
    void* buffer;
    unsigned int size;
    unsigned int capacity;
    LinkChecker();
    ~LinkChecker();
    bool NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty();
};
struct NavMeshInfoMapData
{
    void* vtable;
    unsigned int hashSize;
    void* hashTable;
    unsigned int count;
    void* FUN_004b9ba0();
    void FUN_006b7f20(void**, unsigned int*, NavMeshInfo**);
};

extern char DAT_01011584[];
extern char DAT_0106c0d8[];
extern char DAT_0106c078[];
extern char DAT_0106c008[];
extern char DAT_0106bfa8[];
extern char DAT_0106bf18[];
extern char DAT_0106be98[];
extern char DAT_0106be20[];
extern char DAT_0106bdb0[];
extern int __cdecl Warning(const char*, ...);
extern bool __cdecl Actor_AreReferencedValuesEqual(NavMeshInfo*&, NavMeshInfo*&);
extern void __cdecl RemoveNavMeshId(NavMeshInfo*);
extern void __cdecl SplitUInt32(unsigned int, short*, short*);
extern unsigned int __cdecl PackShortPair(unsigned short, unsigned short);
struct LocalList
{
    void* vtable;
    NavMeshInfo** buffer;
    unsigned int size;
    unsigned int cap;
    LocalList();
    ~LocalList();
    unsigned int FUN_0044ddc0();
    NavMeshInfo** FUN_00877a30(unsigned int);
    void FUN_007cb2e0(void*);
    unsigned int FUN_00719b20(NavMeshInfo* const&, unsigned int, bool(__cdecl*)(NavMeshInfo*&, NavMeshInfo*&));
};
struct InfoResolver
{
    unsigned int id;
    NavMeshInfo* info;
    bool NavMeshTriangleEdgePortal_IsValid();
};
// Iterates the nav mesh map, warns about and collects invalid meshes, checks adjacency, m_kPreferredConnections links and m_kDoorReferences, and cleans up the collected meshes.
// @fnv 0x006b6c60
void NavMeshInfoMap::ValidateNavMeshes()
{
    void* iterator;
    {
        LocalList invalidatedList;
        {
            NavMeshInfo* meshInfo;
            {
                unsigned int identifier;
                iterator = m_kNavMeshInfosByFormID.GetFirstPos();
                while (iterator)
                {
                    m_kNavMeshInfosByFormID.GetNext(iterator, identifier, reinterpret_cast<NavMeshInfo*&>(meshInfo));
                    if (!NavMeshInfo_GetParentSpace(meshInfo))
                    {
                        Warning(DAT_0106c0d8, ((PtrView*)meshInfo)->Modelloader_GetReferencedThis(),
                                (((NavMeshInfo*)meshInfo)->GetCell()
                                     ? ((CellView*)((NavMeshInfo*)meshInfo)->GetCell())->GetEditorID()
                                     : DAT_01011584));
                        invalidatedList.FUN_007cb2e0(&meshInfo);
                    }
                    else if (!meshInfo->HasNonZeroAtOffset54())
                    {
                        Warning(DAT_0106c078, ((PtrView*)meshInfo)->Modelloader_GetReferencedThis(),
                                (((NavMeshInfo*)meshInfo)->GetCell()
                                     ? ((CellView*)((NavMeshInfo*)meshInfo)->GetCell())->GetEditorID()
                                     : DAT_01011584));
                        RemoveNavMeshId(meshInfo);
                        invalidatedList.FUN_007cb2e0(&meshInfo);
                    }
                    else
                    {
                        NavMeshPtr activeMesh;
                        {
                            if (!meshInfo->AcquireNavMesh(activeMesh))
                            {
                                Warning(
                                    DAT_0106c008, ((PtrView*)meshInfo)->Modelloader_GetReferencedThis(),
                                    (((NavMeshInfo*)meshInfo)->GetCell()
                                         ? ((CellView*)((NavMeshInfo*)meshInfo)->GetCell())->GetEditorID()
                                         : DAT_01011584));
                                invalidatedList.FUN_007cb2e0(&meshInfo);
                                continue;
                            }
                            if (activeMesh.GetPtr()->FUN_00440d80())
                                invalidatedList.FUN_007cb2e0(&meshInfo);
                            for (unsigned int k = 0; k < meshInfo->m_kConnectedNavMeshInfos.GetSize(); ++k)
                            {
                                bool invalid = false;
                                if (*((MeshInfoArray*)&meshInfo->m_kConnectedNavMeshInfos)->FUN_00877a30(k))
                                {
                                    if (!FUN_00693d70((unsigned int)((PtrView*)*((MeshInfoArray*)&meshInfo->m_kConnectedNavMeshInfos)
                                                                         ->FUN_00877a30(k))
                                                          ->Modelloader_GetReferencedThis()))
                                        invalid = true;
                                }
                                else
                                    invalid = true;
                                if (invalid)
                                {
                                    Warning(DAT_0106bfa8, ((PtrView*)meshInfo)->Modelloader_GetReferencedThis(),
                                            (((NavMeshInfo*)meshInfo)->GetCell()
                                                 ? ((CellView*)((NavMeshInfo*)meshInfo)->GetCell())
                                                       ->GetEditorID()
                                                 : DAT_01011584));
                                    ((InfoArray*)&meshInfo->m_kConnectedNavMeshInfos)->BSSimpleArray_HUDMainMenu_SubtitleData_1024_Remove(k, true);
                                    --k;
                                }
                            }
                            for (unsigned int k = 0; k < meshInfo->m_kPreferredConnections.GetSize(); ++k)
                            {
                                bool invalid = false;
                                if (*((MeshInfoArray*)&meshInfo->m_kPreferredConnections)->FUN_00877a30(k))
                                {
                                    if (!FUN_00693d70((unsigned int)((PtrView*)*((MeshInfoArray*)&meshInfo->m_kPreferredConnections)
                                                                         ->FUN_00877a30(k))
                                                          ->Modelloader_GetReferencedThis()))
                                        invalid = true;
                                }
                                else
                                    invalid = true;
                                if (invalid)
                                {
                                    Warning(DAT_0106bfa8, ((PtrView*)meshInfo)->Modelloader_GetReferencedThis(),
                                            (((NavMeshInfo*)meshInfo)->GetCell()
                                                 ? ((CellView*)((NavMeshInfo*)meshInfo)->GetCell())
                                                       ->GetEditorID()
                                                 : DAT_01011584));
                                    ((InfoArray*)&meshInfo->m_kPreferredConnections)->BSSimpleArray_HUDMainMenu_SubtitleData_1024_Remove(k, true);
                                    --k;
                                }
                            }
                            LocalList neighborList;
                            if (meshInfo->GetParentWorldSpace())
                            {
                                short gridX, gridY;
                                SplitUInt32(meshInfo->m_uiPathingFlags, &gridX, &gridY);
                                for (int x = gridX - 1; x <= gridX + 1; ++x)
                                {
                                    for (int y = gridY - 1; y <= gridY + 1; ++y)
                                    {
                                        if (x == gridX && y == gridY)
                                            continue;
                                        MeshInfoArray* pCellMeshes =
                                            ((GridLookup*)this)
                                                ->FindNavMeshInfoForCellKey((NavMesh*)meshInfo->GetParentWorldSpace(),
                                                               PackShortPair((unsigned short)x, (unsigned short)y));
                                        if (pCellMeshes)
                                            for (unsigned int i = 0; i < pCellMeshes->FUN_0044ddc0(); ++i)
                                                neighborList.FUN_007cb2e0(pCellMeshes->BSSimpleArray_NiAVObject_1024_GetAt(i));
                                    }
                                }
                            }
                            NavMeshPtr meshPtr;
                            if (meshInfo->AcquireNavMesh(meshPtr))
                            {
                                bool corrupt = false;
                                {
                                    for (unsigned int k = 0; k < meshInfo->m_kConnectedNavMeshInfos.GetSize(); ++k)
                                    {
                                        NavMeshInfo* record = *((MeshInfoArray*)&meshInfo->m_kConnectedNavMeshInfos)->FUN_00877a30(k);
                                        LinkChecker linkChecker;
                                        ((GridMap*)meshPtr.GetPtr())->CollectTrianglesForDoor(record, &linkChecker);
                                        if (linkChecker.NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
                                        {
                                            Warning(DAT_0106bf18, ((PtrView*)meshInfo)->Modelloader_GetReferencedThis(),
                                                    ((PtrView*)record)->Modelloader_GetReferencedThis());
                                            corrupt = true;
                                            break;
                                        }
                                    }
                                    for (unsigned int k = 0; k < meshInfo->m_kPreferredConnections.GetSize(); ++k)
                                    {
                                        NavMeshInfo* record = *((MeshInfoArray*)&meshInfo->m_kPreferredConnections)->FUN_00877a30(k);
                                        LinkChecker linkChecker;
                                        ((GridMap*)meshPtr.GetPtr())->CollectTrianglesForDoor(record, &linkChecker);
                                        if (linkChecker.NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
                                        {
                                            Warning(DAT_0106bf18, ((PtrView*)meshInfo)->Modelloader_GetReferencedThis(),
                                                    ((PtrView*)record)->Modelloader_GetReferencedThis());
                                            corrupt = true;
                                            break;
                                        }
                                    }
                                    unsigned int count = ((GridMap*)meshPtr.GetPtr())->GetArrFlags();
                                    for (unsigned int k = 0; k < count; ++k)
                                    {
                                        unsigned int size;
                                        if (((DataMatch*)&(
                                                 (GridRecord*)((GridMap*)meshPtr.GetPtr())->GetEdge((unsigned short)k))
                                                 ->info)
                                                ->NavMeshTriangleEdgePortal_IsValid())
                                        {
                                            NavMeshInfo* other =
                                                ((GridRecord*)((GridMap*)meshPtr.GetPtr())->GetEdge((unsigned short)k))
                                                    ->info;
                                            bool missing = true;
                                            size = meshInfo->m_kConnectedNavMeshInfos.GetSize();
                                            for (unsigned int i = 0; i < size; ++i)
                                                if (*((MeshInfoArray*)&meshInfo->m_kConnectedNavMeshInfos)->FUN_00877a30(i) == other)
                                                {
                                                    missing = false;
                                                    break;
                                                }
                                            size = meshInfo->m_kPreferredConnections.GetSize();
                                            for (unsigned int i = 0; i < size; ++i)
                                                if (*((MeshInfoArray*)&meshInfo->m_kPreferredConnections)->FUN_00877a30(i) == other)
                                                {
                                                    missing = false;
                                                    break;
                                                }
                                            if (missing)
                                            {
                                                if (neighborList.FUN_00719b20(other, 0, Actor_AreReferencedValuesEqual) !=
                                                    (unsigned int)-1)
                                                {
                                                    Warning(DAT_0106be98, ((PtrView*)meshInfo)->Modelloader_GetReferencedThis(),
                                                            ((PtrView*)other)->Modelloader_GetReferencedThis());
                                                    corrupt = true;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                    for (unsigned int k = 0; k < ((GridMap*)meshPtr.GetPtr())->NavMesh_GetNumDoorPortals(); ++k)
                                    {
                                        NavMeshInfo** other = (NavMeshInfo**)((GridMap*)meshPtr.GetPtr())
                                                                  ->FUN_0068f6b0((unsigned short)k);
                                        if (((InfoArray*)&meshInfo->m_kDoorReferences)->FUN_00719b20(*other, 0, Actor_AreReferencedValuesEqual) ==
                                            (unsigned int)-1)
                                        {
                                            Warning(DAT_0106be20, ((PtrView*)meshInfo)->Modelloader_GetReferencedThis(),
                                                    ((TESObjectREFR*)*other)->GetHavokWorldObjectCountInSceneGraph_0084e3a0());
                                            corrupt = true;
                                            break;
                                        }
                                    }
                                    for (unsigned int k = 0; k < meshInfo->m_kDoorReferences.GetSize(); ++k)
                                    {
                                        NavMeshInfo* other = *((MeshInfoArray*)&meshInfo->m_kDoorReferences)->FUN_00877a30(k);
                                        {
                                            bool linkChecker = false;
                                            for (unsigned int i = 0; i < ((GridMap*)meshPtr.GetPtr())->NavMesh_GetNumDoorPortals();
                                                 ++i)
                                            {
                                                if (*(NavMeshInfo**)((GridMap*)meshPtr.GetPtr())
                                                         ->FUN_0068f6b0((unsigned short)i) == other)
                                                {
                                                    linkChecker = true;
                                                    break;
                                                }
                                            }
                                            if (!linkChecker)
                                            {
                                                Warning(DAT_0106bdb0, ((PtrView*)meshInfo)->Modelloader_GetReferencedThis(),
                                                        ((TESObjectREFR*)other)->GetHavokWorldObjectCountInSceneGraph_0084e3a0());
                                                corrupt = true;
                                                break;
                                            }
                                        }
                                    }
                                }
                                if (corrupt)
                                    meshInfo->InitializeFromMeshSource(meshPtr.GetPtr());
                            }
                        }
                    }
                }
                for (unsigned int i = 0; i < invalidatedList.FUN_0044ddc0(); ++i)
                {
                    ProcessState_006b6990(((PtrView*)*invalidatedList.FUN_00877a30(i))->Modelloader_GetReferencedThis());
                    NavMeshInfo* info = *invalidatedList.FUN_00877a30(i);
                    NavMeshInfo* current = info;
                    current ? ((NavigationRequest*)current)->FUN_006b6390(true) : 0;
                }
            }
        }
    }
}

using ::TESObjectCELL;

::TESForm* __fastcall NavMeshInfo_GetParentSpace(const ::NavMeshInfo*);

// Casts the TESForm* returned by FUN_00690830(this) to TESObjectCELL*.
// @fnv 0x006b77b0
TESObjectCELL* NavMeshInfo::GetInteriorCell()
{
    return dynamic_cast< ::TESObjectCELL*>(NavMeshInfo_GetParentSpace(this));
}
