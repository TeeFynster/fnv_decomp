// fallout/misc/saveload/bgssaveloadreferencesmap.cpp: BGSSaveLoadReferencesMap, BGSCellNumericIDArrayMap (10 functions)

#include "bgssaveloadreferencesmap_decls.h"
#include "../../../../include/DummyPointerMap.h"

// @fnv 0x00852B60
void BGSSaveLoadReferencesMap::Clear()
{
    m_kReferenceIDMap.RemoveAll();
    m_kCellReferences.Clear();
    void* position = m_kWorldspaceCellReferenceMaps.GetFirstPos();
    while (position)
    {
        struct WorldspaceReferences
        {
            BGSCellNumericIDArrayMap* referencesMap;
            unsigned int worldspaceID;
        } entry;
        entry.worldspaceID = 0;
        entry.referencesMap = 0;
        m_kWorldspaceCellReferenceMaps.GetNext(position, entry.worldspaceID, entry.referencesMap);
        delete entry.referencesMap;
    }
    m_kWorldspaceCellReferenceMaps.RemoveAll();
}

// @fnv 0x008528D0
void BGSCellNumericIDArrayMap::Clear()
{
    void* position = GetFirstPos();
    while (position)
    {
        struct CellReferenceIDs
        {
            BSSimpleArray<unsigned int, 1024>* referenceIDs;
            unsigned int cellKey;
        } entry;
        entry.cellKey = 0;
        entry.referenceIDs = 0;
        GetNext(position, entry.cellKey, entry.referenceIDs);
        delete entry.referenceIDs;
    }
    RemoveAll();
}

// @fnv 0x00852D20
void BGSSaveLoadReferencesMap::LoadCellReferences(TESObjectCELL* cell, BGSReconstructFormsInAllFilesMap* forms)
{
    struct CellReferences
    {
        BGSCellNumericIDArrayMap* referencesMap;
        unsigned int cellKey;
    } cellReferences;
    cellReferences.referencesMap = 0;
    cellReferences.cellKey = 0;
    if (cell->IsCellInterior())
    {
        cellReferences.cellKey = cell->GetFormID();
        cellReferences.referencesMap = &m_kCellReferences;
    }
    else
    {
        cellReferences.cellKey = TESWorldSpace::BuildCellKey(cell->GetCellGridX(), cell->GetCellGridY());
        m_kWorldspaceCellReferenceMaps.GetAt(cell->GetParentWorldSpace()->GetFormID(), cellReferences.referencesMap);
    }
    if (cellReferences.referencesMap)
    {
        BSSimpleArray<unsigned int, 1024>* referenceIDs = 0;
        if (cellReferences.referencesMap->GetAt(cellReferences.cellKey, referenceIDs))
        {
            for (unsigned int index = 0; index < referenceIDs->GetSize(); ++index)
                ReconstructFormID(referenceIDs->GetAt(static_cast<int>(index)), forms);
            cellReferences.referencesMap->RemoveAt(cellReferences.cellKey);
            delete referenceIDs;
        }
    }
}

struct OL4A
{
    OL4A(int);
    ~OL4A();
    int d[4];
};
struct OL4C
{
    OL4C(int);
    ~OL4C();
    int d[4];
};
struct FUN_00852a70
{
    OL4A a;
    BGSCellNumericIDArrayMap b;
    OL4C c;
    FUN_00852a70();
};
// Initializes members a and c with 0x25 and default-constructs b.
// @fnv 0x00852a70
FUN_00852a70::FUN_00852a70() : a(0x25), c(0x25)
{}

extern "C" bool __cdecl Actor_AreReferencedValuesEqual(const unsigned int&, const unsigned int&);

// @fnv 0x00852a10
void BGSCellNumericIDArrayMap::RemoveReference(unsigned int auiKey, unsigned int a2)
{
    BSSimpleArray<unsigned int, 1024>* referenceIDs = 0;
    if (GetAt(auiKey, referenceIDs))
    {
        unsigned int idx = referenceIDs->Find(a2, 0, Actor_AreReferencedValuesEqual);
        if (idx != 0xFFFFFFFF)
        {
            referenceIDs->UpdateEntryValue(idx, 1);
        }
    }
}

// @fnv 0x00852810
BGSCellNumericIDArrayMap::BGSCellNumericIDArrayMap() : NiTMap(0x25)
{}

struct FUN_00852cd0_shell
{
    void RemoveReferenceFromCell(unsigned int aiCellID, unsigned int aiReferenceID, NiPoint3 const& arPos);
};
// Looks up the numeric ID array for aiCellID and removes the reference keyed by the world coordinate of arPos.
// @fnv 0x00852cd0
void FUN_00852cd0_shell::RemoveReferenceFromCell(unsigned int aiCellID, unsigned int aiReferenceID,
                                                 NiPoint3 const& arPos)
{
    BGSCellNumericIDArrayMap* pnumericIDArray = 0;
    if (((DummyPointerMap*)((char*)this + 0x20))->GetAt(aiCellID, (unsigned int&)pnumericIDArray))
    {
        unsigned int uiCoordKey;
        uiCoordKey = TESWorldSpace::GetKeyForWorldCoord(arPos);
        pnumericIDArray->RemoveReference(uiCoordKey, aiReferenceID);
    }
}

struct FUN_00852c00_shell
{
    void AddReferenceToCell(unsigned int aiCellID, unsigned int aiReferenceID, NiPoint3 const& arPos);
};
// Looks up or creates the per-cell numeric ID map for aiCellID, then inserts aiReferenceID under the key derived from arPos.
// @fnv 0x00852c00
void FUN_00852c00_shell::AddReferenceToCell(unsigned int aiCellID, unsigned int aiReferenceID, NiPoint3 const& arPos)
{
    BGSCellNumericIDArrayMap* pNumericIDArray = 0;
    if (!((DummyPointerMap*)((char*)this + 0x20))->GetAt(aiCellID, (unsigned int&)pNumericIDArray))
    {
        pNumericIDArray = new BGSCellNumericIDArrayMap;
        ((DummyPointerMap*)((char*)this + 0x20))->SetAt(aiCellID, (unsigned int)pNumericIDArray);
    }
    int key = TESWorldSpace::GetKeyForWorldCoord(arPos);
    pNumericIDArray->GetOrCreateEntryAdd(key, reinterpret_cast<void*>(aiReferenceID));
}

// Looks up or creates the cell's reference ID array, then adds the reference ID.
// @fnv 0x00852950
unsigned int BGSCellNumericIDArrayMap::GetOrCreateEntryAdd(unsigned int aiKey, void* apValue)
{
    BSSimpleArray<unsigned int, 1024>* pEntry = 0;
    if (!GetAt(aiKey, pEntry))
    {
        pEntry = new BSSimpleArray<unsigned int, 1024>;
        SetAt(aiKey, pEntry);
    }
    return pEntry->Add(reinterpret_cast<unsigned int&>(apValue));
}

struct B852AE0MapB
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    ~B852AE0MapB();
};

struct B852AE0Base
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    ~B852AE0Base();
};

// BGSSaveLoadReferencesMap destructor
class FUN_00852ae0 : public B852AE0Base
{
  public:
    BGSCellNumericIDArrayMap m_kMapA;
    B852AE0MapB m_kMapB;

    void Clear();
    ~FUN_00852ae0();
};

// @fnv 0x00852ae0
FUN_00852ae0::~FUN_00852ae0()
{
    Clear();
}

struct Loader2e40
{
    void* Modelloader_GetReferencedThis();
    void* BGSUnloadedFormBuffer_GetAdvancedBuffer();
};
struct Change2e40
{
    int key;
    Loader2e40 loader;
};
struct Changes2e40
{
    Change2e40* FUN_009a4250(unsigned int);
};
struct Host2e40
{
    Changes2e40* Modelloader_GetReferencedThis();
    void ApplyUnloadedChanges(TESObjectCELL*);
};
extern Host2e40* DAT_011ddf38;
int __cdecl BGSSaveLoadInitialData_GetInitialDataType(unsigned int, int, int);
void __cdecl SaveGameWarning(const char*, ...);
struct Info2e40
{
    int unk00, unk04, cellID, x, y, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    Info2e40();
    bool ReferenceInitialData_GetOriginalLocationCellAndWorld(TESObjectCELL**, TESWorldSpace**);
};
void __cdecl BGSSaveLoadInitialData_LoadInitialDataStruct(void*, int, Info2e40*);
TESObjectCELL* __cdecl ResolveReferenceForm(unsigned int, Info2e40*, bool);
struct Forms2e40
{
    void BGSReconstructFormsInAllFilesMap_AddReference(TESObjectCELL*, unsigned int, bool);
    void BGSReconstructFormsInAllFilesMap_AddReference_008438b0(TESWorldSpace*, int, int, unsigned int, bool);
};
struct Target2e40
{
    void BGSSaveLoadReferencesMap_LoadChangedReference(unsigned int, Forms2e40*);
};
// @fnv 0x00852e40
// src: XBOX_PDB 0x00852e40
void Target2e40::BGSSaveLoadReferencesMap_LoadChangedReference(unsigned int uiRefID, Forms2e40* forms)
{
    Change2e40* change = DAT_011ddf38->Modelloader_GetReferencedThis()->FUN_009a4250(uiRefID);
    if (change)
    {
        int iChangeType = BGSSaveLoadInitialData_GetInitialDataType(uiRefID, 0x3a, change->key);
        if (iChangeType != 5 && iChangeType != 6)
        {
            SaveGameWarning(
                "SAVELOAD: Ref %08X is in the references map but is neither a created reference or a moved reference",
                uiRefID);
            return;
        }
        if (!change->loader.Modelloader_GetReferencedThis())
        {
            SaveGameWarning(
                "SAVELOAD: Ref %08X is in the references map but there is no unloaded buffer for it in the changes map",
                uiRefID);
            return;
        }
        Info2e40 changeInfo;
        BGSSaveLoadInitialData_LoadInitialDataStruct(change->loader.BGSUnloadedFormBuffer_GetAdvancedBuffer(), iChangeType, &changeInfo);
        if (iChangeType == 5)
        {
            TESObjectCELL* cell = ResolveReferenceForm(uiRefID, &changeInfo, false);
            if (cell)
                DAT_011ddf38->ApplyUnloadedChanges(cell);
        }
        else
        {
            TESObjectCELL* interior = 0;
            TESWorldSpace* world = 0;
            if (changeInfo.ReferenceInitialData_GetOriginalLocationCellAndWorld(&interior, &world))
            {
                if (interior)
                    forms->BGSReconstructFormsInAllFilesMap_AddReference(interior, uiRefID, false);
                else
                    forms->BGSReconstructFormsInAllFilesMap_AddReference_008438b0(world, changeInfo.x, changeInfo.y, uiRefID, false);
            }
            else
            {
                SaveGameWarning("CELLS: Could not find cell or worldspace %08X for moved reference %08X",
                             changeInfo.cellID, uiRefID);
            }
        }
    }
}

// @fnv 0x00852870
BGSCellNumericIDArrayMap::~BGSCellNumericIDArrayMap()
{
    Clear();
}
