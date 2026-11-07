#include "../../../../include/BSScrapArray.h"
#include "../../../../include/BSSimpleArray.h"
#include "../../../../include/BGSReconstructFormsInAllFilesMap.h"
#include "../../../../include/BGSReconstructFormsInFileMap.h"
#include "../../../../include/BGSReconstructCellBlocksMap.h"
#include "../../../../include/BGSReconstructCellsMap.h"
#include "../../../../include/TESObjectREFR.h"
#include "../../../../include/BGSReconstructCellSubBlocksMap.h"
#include "../../../../include/BGSReconstructFormsMap.h"
#include "../../../../include/BGSReconstructWorldSpacesMap.h"
#include "../../../../include/TESFile.h"
#include "../../../../include/TESDataHandler.h"
#include "../../../../include/BGSSaveLoadGame.h"
#include "../../../../include/FormChangeMap.h"
#include "../../../../include/DummyPointerMap.h"
#include "../../../../include/TESGlobal.h"
#include "../../../../include/TESObjectCELL.h"
#include "../../../../include/TESWorldSpace.h"
#include "../../../../include/BGSSaveLoadChangesMap.h"

// Remaining unit declarations are kept here because the old declarations
// header also defines a partial TESForm, now supplied by the shared headers.





struct ChangedFormRecord
{
    TESForm* pForm;
    unsigned int iFlags;
};
// The shared FormChangeMap exposes the storage; additional operations stay method-only.
struct FormChangeMapOperations : FormChangeMap
{
    void BGSConstructedForms_Clear();
    void BGSReconstructedForms_SetAllocSize(unsigned int count);
    ChangedFormRecord* BGSReconstructedForms_GetAt(unsigned int index);
    unsigned int GetElementAt(unsigned int index);
    void BGSReconstructedForms_AddFormData(ChangedFormRecord* data);
};

struct FormChangeArrayOperations : nitmapbase_FormMap
{
    void Resize(int, int);
    unsigned int CallGetFlags();
    void SetCount(unsigned int);
    void Erase(unsigned int, int);
    ChangedFormRecord* GetElement(unsigned int);
};






class TESFormInitFlag
{
  public:
    bool IsFormInitialized() const;
};

extern BGSSaveLoadGame* g_BGSSaveLoadGame;
extern TESDataHandler* g_dataHandler;


#include "../../../../include/BGSCellNumericIDArrayMap.h"
#include "../../../../include/NiPoint3.h"

// Destroy both shared change-array members.
// @fnv 0x00843540
FormChangeMap::~FormChangeMap()
{}

// @fnv 0x008455b0
BGSSaveLoadChangesMap::~BGSSaveLoadChangesMap()
{
    Clear();
}

// @fnv 0x008434d0
BGSReconstructFormsInAllFilesMap::~BGSReconstructFormsInAllFilesMap()
{
    Clear();
}

// @fnv 0x008433d0
BGSReconstructFormsInAllFilesMap::BGSReconstructFormsInAllFilesMap()
    : NiTMap<TESFile*, BGSReconstructFormsInFileMap*>(0x25), m_kFormChangeMap(), iCount(0)
{}

// @fnv 0x008439e0
void BGSReconstructFormsInAllFilesMap::BuildMap()
{
    struct LocalState
    {
        ChangedFormRecord* reconstructForm;
        unsigned int reconstructIndex;
        ChangedFormRecord* initializeForm;
        unsigned int initializeIndex;
        TESForm* form;
        ChangedFormRecord* removedForm;
        unsigned int removeIndex;
        TESFile* threadSafeFile;
        BGSReconstructFormsInFileMap* map;
        TESFile* file;
        unsigned char padding0;
        unsigned char padding1;
        unsigned char padding2;
        bool wasLocked;
        unsigned int size;
        void* position;
    } state;

    g_BGSSaveLoadGame->SetFlag4(true);
    static_cast<FormChangeMapOperations*>(&m_kFormChangeMap)->BGSReconstructedForms_SetAllocSize(iCount);
    state.wasLocked = g_dataHandler->FUN_004516b0();
    g_dataHandler->SetBoolAt61a(true);

    state.position = GetFirstPos();
    while (state.position)
    {
        state.file = 0;
        state.map = 0;
        GetNext(state.position, state.file, state.map);
        state.threadSafeFile = state.file->GetParentTESFile();
        state.map->BuildMap(state.threadSafeFile, &m_kFormChangeMap);
    }

    g_dataHandler->SetBoolAt61a(state.wasLocked);

    state.removeIndex = 0;
    for (; state.removeIndex < m_kFormChangeMap.GetCombinedFlags(); ++state.removeIndex)
    {
        state.removedForm = static_cast<FormChangeMapOperations*>(&m_kFormChangeMap)->BGSReconstructedForms_GetAt(state.removeIndex);
        if (state.removedForm->pForm->GetIsReference())
        {
            state.form = state.removedForm->pForm;
            if (!reinterpret_cast<TESObjectREFR*>(state.form)->GetObjectReference())
            {
                m_kFormChangeMap.RemoveForm(state.removeIndex);
                --state.removeIndex;
            }
        }
    }

    state.size = m_kFormChangeMap.GetCombinedFlags();
    state.initializeIndex = 0;
    for (; state.initializeIndex < state.size; ++state.initializeIndex)
    {
        state.initializeForm = static_cast<FormChangeMapOperations*>(&m_kFormChangeMap)->BGSReconstructedForms_GetAt(state.initializeIndex);
        if (!reinterpret_cast<TESFormInitFlag*>(state.initializeForm->pForm)->IsFormInitialized())
            state.initializeForm->pForm->InitItem();
    }

    state.reconstructIndex = 0;
    for (; state.reconstructIndex < state.size; ++state.reconstructIndex)
    {
        state.reconstructForm = static_cast<FormChangeMapOperations*>(&m_kFormChangeMap)->BGSReconstructedForms_GetAt(state.reconstructIndex);
        AddFormFlagEntry(state.reconstructForm);
    }

    g_BGSSaveLoadGame->SetFlag4(false);
}

// Deletes every file map returned by GetNext, then clears the pointer map, calls FUN_00843240 and resets iCount to 0.
// @fnv 0x008435a0
void BGSReconstructFormsInAllFilesMap::Clear()
{
    void* position = GetFirstPos();
    while (position)
    {
        TESFile* file = 0;
        BGSReconstructFormsInFileMap* map = 0;
        GetNext(position, file, map);
        delete reinterpret_cast<BGSCellNumericIDArrayMap*>(map);
    }
    RemoveAll();
    static_cast<FormChangeMapOperations*>(&m_kFormChangeMap)->BGSConstructedForms_Clear();
    iCount = 0;
}

// Calls Resize(0, 1) on each change array.
// @fnv 0x00843240
// src: COMMUNITY 0x00843240
void FormChangeMapOperations::BGSConstructedForms_Clear()
{
    reinterpret_cast<FormChangeArrayOperations*>(&first)->Resize(0, 1);
    reinterpret_cast<FormChangeArrayOperations*>(&second)->Resize(0, 1);
}

// @fnv 0x00843bb0
unsigned int FormChangeMap::GetCombinedFlags()
{
    return reinterpret_cast<FormChangeArrayOperations*>(&first)->CallGetFlags() +
           reinterpret_cast<FormChangeArrayOperations*>(&second)->CallGetFlags();
}

extern int DAT_01031fac;

struct FUN_00844130_arg
{
    unsigned int val;
};

void __fastcall FUN_005890c0(int* self, FUN_00844130_arg a);

// Calls FUN_005890c0 on self, then stores the address of DAT_01031fac into *self and returns self.
// @fnv 0x00844130
// src: EXE 0x00844130
int* __fastcall NiTMap_TESFile_BGSReconstructFormsInFileMap_NiTMap(int* self, FUN_00844130_arg a)
{
    FUN_005890c0(self, a);
    *self = (int)&DAT_01031fac;
    return self;
}

extern int DAT_0107ed08;

class SaveGameSizeState
{
  public:
    void RecordRequestedSize(unsigned int, unsigned int);
};

// @fnv 0x00844a90
void* __fastcall SaveGameSizeStateConstructor(void* pThis)
{
    *reinterpret_cast<int**>(pThis) = &DAT_0107ed08;
    reinterpret_cast<SaveGameSizeState*>(pThis)->RecordRequestedSize(0, 0);
    return pThis;
}

class GlobalObject_00869f00
{
  public:
    void Clear(bool);
};

extern int DAT_0107ed08;

// @fnv 0x00844ac0
// src: GUESS 0x00844ac0 (confidence: medium)
void __fastcall Object_ResetVirtualTableAndClear_00844ac0(GlobalObject_00869f00* _this)
{
    *(int**)_this = &DAT_0107ed08;
    _this->Clear(true);
}

void __fastcall DeleteAllEntries(void*);

struct FUN_009a5df0
{
    virtual void dummy();
    ~FUN_009a5df0();
};

struct FUN_00844e20 : FUN_009a5df0
{
    ~FUN_00844e20();
};

// Destructor that forwards to DeleteAllEntries with this as the argument.
// @fnv 0x00844e20
FUN_00844e20::~FUN_00844e20()
{
    DeleteAllEntries(this);
}

struct ScrapHeapBuffer
{
    void* Allocate(unsigned int, unsigned int);
    void Deallocate(void*);
};
extern unsigned int DAT_010a2720;
struct OffsetData
{
    unsigned int iOffset;
    void* m_pFormLookupMap;
};
// @fnv 0x006db9b0
template <>
OffsetData* BSScrapArray<OffsetData>::_Allocate(unsigned int aiSizeInItem)
{
    OffsetData* pnewBuffer;
    pnewBuffer = (OffsetData*)m_pAllocator->Allocate(aiSizeInItem * 8, DAT_010a2720);
    return pnewBuffer;
}

// Operations missing from the shared forms map use its checked layout.
struct ReconstructFormsMapOperations : BGSReconstructFormsMap
{
    void AddFlags(int arg);
    void ProcessRef(unsigned int, unsigned int, unsigned int);
};

// @fnv 0x00841320
void ReconstructFormsMapOperations::AddFlags(int arg)
{
    unk10 |= arg;
}

// @fnv 0x00842180
BGSReconstructFormsInFileMap::BGSReconstructFormsInFileMap()
    : NiTMap<unsigned int, BGSReconstructFormsMap*>(0x25)
{
    m_pInteriorMap = 0;
    m_pExteriorMap = 0;
    iCount = 0;
}

struct FUN_00844fc0_shell
{
    void* __thiscall BSSimpleArray_Alloc8BytesMembers(int arg);
};

// Allocates arg << 3 bytes via operator new and returns the pointer.
// @fnv 0x00844fc0
// src: COMMUNITY 0x00844fc0
void* __thiscall FUN_00844fc0_shell::BSSimpleArray_Alloc8BytesMembers(int arg)
{
    void* p = operator new(arg << 3);
    return p;
}


extern "C" void _Deallocate(void*);

// Calls FUN_008411f0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x008411c0
void* BGSReconstructFormsMap::FUN_008411c0(unsigned int flags)
{
    this->FUN_008411f0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}


void __cdecl _Deallocate(void*);

// @fnv 0x00841370
void* BGSReconstructCellsMap::FUN_00841370(unsigned int flags)
{
    BGSReconstructCellsMap::~BGSReconstructCellsMap();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern "C" void __cdecl _Deallocate(void*);


// Destroys the object, frees its storage with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x008416f0
void* __thiscall BGSReconstructCellSubBlocksMap::ScalarDeletingDestructor(unsigned int flags)
{
    BGSReconstructCellSubBlocksMap::~BGSReconstructCellSubBlocksMap();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct S006950d0
{
    unsigned int GetElement(unsigned int);
};

struct FUN_00844160_shell
{
    unsigned int BSSimpleArray_GroupMemberData_1024_GetAt(unsigned int);
};

// @fnv 0x00844160
// src: XBOX_PDB 0x00844160
unsigned int FUN_00844160_shell::BSSimpleArray_GroupMemberData_1024_GetAt(unsigned int a)
{
    return ((S006950d0*)this)->GetElement(a);
}

namespace fnv_00844180 {
void* __cdecl _Deallocate(void* p);

struct FUN_00844180_shell
{
    void __thiscall FUN_00844470();
    void* __thiscall FUN_00844180(unsigned int flags);
};

// Calls FUN_00844470, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00844180
void* __thiscall FUN_00844180_shell::FUN_00844180(unsigned int flags)
{
    FUN_00844470();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00844180

extern "C" void _Deallocate(void*);

struct ReconstructFilesMapBaseOperations : NiTMap<TESFile*, BGSReconstructFormsInFileMap*>
{
    void* FUN_00844270(unsigned int flags);
};

// @fnv 0x00844270
void* ReconstructFilesMapBaseOperations::FUN_00844270(unsigned int flags)
{
    NiTMap<TESFile*, BGSReconstructFormsInFileMap*>::~NiTMap();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00845260_holder
{
    void __thiscall CreateObj();
};

struct FUN_00844500_shell
{
    void __thiscall ForwardToHolder();
};

// @fnv 0x00844500
void __thiscall FUN_00844500_shell::ForwardToHolder()
{
    ((FUN_00845260_holder*)((char*)this + 0xc))->CreateObj();
}

namespace fnv_00844fa0 {
struct GlobalObject_00869f00
{
    void* m_p;
    void __thiscall Clear(bool);
};

extern int DAT_0107ed50;

struct FUN_00844fa0_shell
{
    void* m_p;
    void InitGlobalObject();
};

// @fnv 0x00844fa0
void __thiscall FUN_00844fa0_shell::InitGlobalObject()
{
    m_p = &DAT_0107ed50;
    ((GlobalObject_00869f00*)this)->Clear(true);
}
}  // namespace fnv_00844fa0

struct NiStream;
struct blob12
{
    char b[12];
};
typedef char _sizecheck_NiPoint3[sizeof(NiPoint3) == 12 ? 1 : -1];
struct FUN_00416870_shell : public NiPoint3
{
    void SetComponents(float, float, float);
};

struct FUN_00416870_t : public NiPoint3
{
    FUN_00416870_t* SetComponents(float, float, float);
};
// Sets the point's x, y and z components from the three arguments and returns this.
// @fnv 0x00416870
// src: GUESS 0x00416870 (confidence: high)
FUN_00416870_t* FUN_00416870_t::SetComponents(float fX, float fY, float fZ)
{
    x = fX;
    y = fY;
    z = fZ;
    return this;
}

// @fnv 0x00841190
BGSReconstructFormsMap::BGSReconstructFormsMap()
    : NiTMap<unsigned int, ReconstructFormData>(0x25)
{
    unk10 = 0;
}

// @fnv 0x00841340
BGSReconstructCellsMap::BGSReconstructCellsMap()
    : NiTMap<unsigned int, BGSReconstructFormsMap*>(0x25)
{}


struct FUN_00452420_shell
{
    bool GetFlag(unsigned int) const;
};
// Iterates the map's entries and returns true if any file map's GetFlag(aiFlags) is set.
// @fnv 0x00841660
bool BGSReconstructCellsMap::HasFileMapWithFlag(unsigned int aiFlags)
{
    void* it;
    BGSReconstructFormsMap* pformsMap;
    unsigned int icellKey;
    it = reinterpret_cast<NiTPointerMap<unsigned int, BGSReconstructFormsMap*>*>(this)->GetFirstPos();
    while (it != 0)
    {
        icellKey = 0;
        pformsMap = 0;
        reinterpret_cast<NiTPointerMap<unsigned int, BGSReconstructFormsMap*>*>(this)->GetNext(it, icellKey, pformsMap);
        if (((FUN_00452420_shell*)pformsMap)->GetFlag(aiFlags))
            return true;
    }
    return false;
}

// @fnv 0x008416c0
BGSReconstructCellSubBlocksMap::BGSReconstructCellSubBlocksMap()
    : NiTMap<unsigned int, BGSReconstructCellsMap*>(0x25)
{}

// Iterates the map's entries and returns true as soon as a contained cells map reports the given flags via HasFileMapWithFlag.
// @fnv 0x00841990
bool BGSReconstructCellSubBlocksMap::HasCellWithFlag(unsigned int aiFlags)
{
    void* it;
    unsigned int pFile;
    BGSReconstructCellsMap* pcellsMap;
    it = ((BGSReconstructFormsInAllFilesMap*)this)->GetFirstPos();
    while (it != 0)
    {
        pFile = 0;
        pcellsMap = 0;
        ((BGSReconstructFormsInAllFilesMap*)this)
            ->GetNext(it, (TESFile*&)pFile, (BGSReconstructFormsInFileMap*&)pcellsMap);
        if (pcellsMap->HasFileMapWithFlag(aiFlags))
            return true;
    }
    return false;
}

// @fnv 0x008419f0
BGSReconstructCellBlocksMap::BGSReconstructCellBlocksMap(bool exterior)
    : NiTMap<unsigned int, BGSReconstructCellSubBlocksMap*>(0x25)
{
    unk10 = 0;
    unk14 = exterior;
}

void __cdecl _Deallocate(void*);
// Calls FUN_00841a60, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00841a30
void* BGSReconstructCellBlocksMap::FUN_00841a30(unsigned int flags)
{
    FUN_00841a60();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// @fnv 0x00841ea0
BGSReconstructWorldSpacesMap::BGSReconstructWorldSpacesMap()
    : NiTMap<unsigned int, BGSReconstructCellBlocksMap*>(0x25)
{}

void __cdecl _Deallocate(void*);
// Calls FUN_00841f00, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00841ed0
void* BGSReconstructWorldSpacesMap::FUN_00841ed0(unsigned int flags)
{
    FUN_00841f00();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl _Deallocate(void*);
// @fnv 0x008421c0
void* BGSReconstructFormsInFileMap::ScalarDeletingDestructor(unsigned int flags)
{
    BGSReconstructFormsInFileMap::~BGSReconstructFormsInFileMap();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// @fnv 0x008432e0
// src: COMMUNITY 0x008432e0
ChangedFormRecord* FormChangeMapOperations::BGSReconstructedForms_GetAt(unsigned int auiIndex)
{
    unsigned int flags = reinterpret_cast<FormChangeArrayOperations*>(&first)->CallGetFlags();
    if (auiIndex < flags)
    {
        return reinterpret_cast<FormChangeArrayOperations*>(&first)->GetElement(auiIndex);
    }
    else
    {
        return reinterpret_cast<FormChangeArrayOperations*>(&second)->GetElement(auiIndex - flags);
    }
}

// @fnv 0x00843330
unsigned int FormChangeMapOperations::GetElementAt(unsigned int index)
{
    unsigned int flags = reinterpret_cast<FormChangeArrayOperations*>(&first)->CallGetFlags();
    if (index < flags)
    {
        return *reinterpret_cast<unsigned int*>(reinterpret_cast<FormChangeArrayOperations*>(&first)->GetElement(index));
    }
    else
    {
        return *reinterpret_cast<unsigned int*>(reinterpret_cast<FormChangeArrayOperations*>(&second)->GetElement(index - flags));
    }
}

// @fnv 0x00843380
bool FormChangeMap::RemoveForm(unsigned int auiIndex)
{
    unsigned int flags = reinterpret_cast<FormChangeArrayOperations*>(&first)->CallGetFlags();
    if (auiIndex < flags)
    {
        reinterpret_cast<FormChangeArrayOperations*>(&first)->Erase(auiIndex, 1);
    }
    else
    {
        reinterpret_cast<FormChangeArrayOperations*>(&second)->Erase(auiIndex - flags, 1);
    }
    return true;
}

template <typename T> class BSSimpleList;
TESForm* __cdecl _ref_004839c0(unsigned int);
unsigned int __cdecl GetOwnerFileByID(unsigned int);
struct FUN_00485b60
{
    TESFile* GetFile(int);
};
struct ReconstructFilesSourceLookup
{
    TESFile* BGSReconstructFormsInAllFilesMap_GetFileForFormID(BSSimpleList<TESFile*>* apFileList, unsigned int aiFormID);
};
// @fnv 0x00843fe0
// src: XBOX_PDB 0x00843fe0
TESFile* ReconstructFilesSourceLookup::BGSReconstructFormsInAllFilesMap_GetFileForFormID(BSSimpleList<TESFile*>* apFileList, unsigned int aiFormID)
{
    TESFile* pfile;
    TESForm* pform;
    pform = _ref_004839c0(aiFormID);
    if (pform)
    {
        return ((FUN_00485b60*)pform)->GetFile(-1);
    }
    pfile = (TESFile*)GetOwnerFileByID(aiFormID);
    if (pfile)
    {
        return pfile;
    }
    return g_dataHandler->GetCompiledFileByIndex(aiFormID >> 24);
}

namespace fnv_00844040 {
extern int DAT_0107eba8;
struct S008442a0
{
    void NiTMapBase_DFALL_NiTMapItem_unsigned_int_ReconstructFormData_unsigned_int_ReconstructFormData_NiTMapBase(int);
};
struct FUN_00844040
{
    int vfptr;
    FUN_00844040(int);
};
// Calls FUN_008442a0 on this with a, then sets vfptr to the address of DAT_0107eba8.
// @fnv 0x00844040
FUN_00844040::FUN_00844040(int a)
{
    ((S008442a0*)this)->NiTMapBase_DFALL_NiTMapItem_unsigned_int_ReconstructFormData_unsigned_int_ReconstructFormData_NiTMapBase(a);
    vfptr = (int)&DAT_0107eba8;
}
}  // namespace fnv_00844040

extern int DAT_0107ebc8;
struct S_844070
{
    void FUN_00844590(int);
    S_844070* NiTMap_unsigned_int_BGSReconstructFormsMap_NiTMap(int);
};
// Calls FUN_00844590 with a, stores the address of DAT_0107ebc8 into this, and returns this.
// @fnv 0x00844070
// src: EXE 0x00844070
S_844070* S_844070::NiTMap_unsigned_int_BGSReconstructFormsMap_NiTMap(int a)
{
    FUN_00844590(a);
    *(int*)this = (int)&DAT_0107ebc8;
    return this;
}

extern int DAT_0107ebe8;
struct C008440a0
{
    int m0;
    void NiTMapBase_DFALL_NiTMapItem_unsigned_int_BGSReconstructCellsMap_unsigned_int_BGSReconstructCellsMap_NiTMapBase(int);
    C008440a0* NiTMap_unsigned_int_BGSReconstructCellsMap_NiTMap(int);
};
// Calls FUN_00844690 with a, stores the address of DAT_0107ebe8 in m0, and returns this.
// @fnv 0x008440a0
// src: EXE 0x008440a0
C008440a0* C008440a0::NiTMap_unsigned_int_BGSReconstructCellsMap_NiTMap(int a)
{
    NiTMapBase_DFALL_NiTMapItem_unsigned_int_BGSReconstructCellsMap_unsigned_int_BGSReconstructCellsMap_NiTMapBase(a);
    m0 = (int)&DAT_0107ebe8;
    return this;
}

extern int DAT_0107ec08;
struct S008440d0
{
    int field0;
    void FUN_00844870(int);
    S008440d0* NiTMap_unsigned_int_BGSReconstructCellSubBlocksMap_NiTMap(int);
};
// Calls FUN_00844870 with a, stores the address of DAT_0107ec08 in field0, and returns this.
// @fnv 0x008440d0
// src: EXE 0x008440d0
S008440d0* S008440d0::NiTMap_unsigned_int_BGSReconstructCellSubBlocksMap_NiTMap(int a)
{
    FUN_00844870(a);
    field0 = (int)&DAT_0107ec08;
    return this;
}

extern int DAT_0107ec28;
struct C844100
{
    int* f0;
    void FUN_00844970(int);
    C844100* NiTMap_unsigned_int_BGSReconstructCellBlocksMap_NiTMap(int);
};
// Calls FUN_00844970 with a, sets f0 to point at DAT_0107ec28, and returns this.
// @fnv 0x00844100
// src: EXE 0x00844100
C844100* C844100::NiTMap_unsigned_int_BGSReconstructCellBlocksMap_NiTMap(int a)
{
    FUN_00844970(a);
    f0 = &DAT_0107ec28;
    return this;
}

struct UnnamedClass008441b0
{
    void FUN_00844600();
    void* FUN_008441b0(unsigned int);
};
void __cdecl _Deallocate(void*);
// Calls FUN_00844600, then deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x008441b0
void* UnnamedClass008441b0::FUN_008441b0(unsigned int flags)
{
    FUN_00844600();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl _Deallocate(void*);
struct Fake8441e0
{
    void FUN_008447e0();
    void* FUN_008441e0(unsigned int);
};
// Calls FUN_008447e0, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x008441e0
void* Fake8441e0::FUN_008441e0(unsigned int flags)
{
    this->FUN_008447e0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl _Deallocate(void*);
struct UnknownClass
{
    void FUN_008448e0();
    void* FUN_00844210(unsigned int);
};
// Calls FUN_008448e0, frees this via _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x00844210
void* UnknownClass::FUN_00844210(unsigned int flags)
{
    FUN_008448e0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct C844240
{
    void FUN_008449e0();
    void* FUN_00844240(unsigned int);
};
void __cdecl _Deallocate(void*);
// Calls FUN_008449e0, frees this via _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x00844240
void* C844240::FUN_00844240(unsigned int flags)
{
    this->FUN_008449e0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern int DAT_0107ec68;
void _NiFreeAlias(void*);
struct Unk008444d0
{
    void* _0;
    int _4;
    void* _8;
    void SetVtableAndProcessState_008444d0();
};
// Sets the vtable pointer, clears the pointer map, and frees the _8 allocation.
// @fnv 0x008444d0
// src: GUESS 0x008444d0 (confidence: low)
void Unk008444d0::SetVtableAndProcessState_008444d0()
{
    *(void**)this = (void*)&DAT_0107ec68;
    ((NiTPointerMap<unsigned int, unsigned int>*)this)->RemoveAll();
    _NiFreeAlias(_8);
}

extern int DAT_0107ed1c;
void _NiFreeAlias(void*);
struct S_00844e80
{
    int _0;
    int _4;
    void* _8;
    void ReleaseStorage_00844e80();
};
// @fnv 0x00844e80
// src: GUESS 0x00844e80 (confidence: medium)
void S_00844e80::ReleaseStorage_00844e80()
{
    *(void**)this = (void*)&DAT_0107ed1c;
    ((NiTPointerMap<unsigned int, unsigned int>*)this)->RemoveAll();
    _NiFreeAlias(this->_8);
}

namespace fnv_00844eb0 {
struct S5460
{
    unsigned int unk0;
    unsigned int BSSimpleArray_NiPoint2_1024_AddUninitialized();
};
struct SaveGameSizeState : public S5460
{
    struct Elem
    {
        unsigned int a;
        unsigned int b;
    }* arr;
    void RecordSizeAndLength(unsigned int, unsigned int);
    unsigned int AppendElementAndRecordSize(Elem* p);
};
// @fnv 0x00844eb0
// src: GUESS 0x00844eb0 (confidence: medium)
unsigned int SaveGameSizeState::AppendElementAndRecordSize(Elem* apElem)
{
    unsigned int idx = BSSimpleArray_NiPoint2_1024_AddUninitialized();
    RecordSizeAndLength((unsigned int)&arr[idx], 1);
    arr[idx] = *apElem;
    return idx;
}
}  // namespace fnv_00844eb0

void* __memcpy(void*, const void*, unsigned int);
// Allocates a new buffer of aiNewSizeInItem items, copies GetTarget() items from apBuffer into it, frees apBuffer and returns the new buffer.
// @fnv 0x00845050
template <>
OffsetData* BSScrapArray<OffsetData>::ReallocateBuffer(OffsetData* apBuffer, unsigned int aiNewSizeInItem)
{
    OffsetData* pnewBuffer = (OffsetData*)m_pAllocator->Allocate(aiNewSizeInItem * sizeof(OffsetData), DAT_010a2720);
    __memcpy(pnewBuffer, apBuffer, GetTarget() * sizeof(OffsetData));
    m_pAllocator->Deallocate(apBuffer);
    return pnewBuffer;
}

struct MyVal
{
    unsigned int a;
    unsigned int b;
};
struct MyItem
{
    void* f0;
    unsigned int f4;
    MyVal f8;
};
struct MyHost
{
    void SetEntryKeyAndValue(MyItem* pkItem, unsigned int key, MyVal val);
};
// Stores key into pkItem->f4 and val into pkItem->f8.
// @fnv 0x00993b30
// src: GUESS 0x00993b30 (confidence: high)
void MyHost::SetEntryKeyAndValue(MyItem* pkItem, unsigned int key, MyVal val)
{
    pkItem->f4 = key;
    pkItem->f8 = val;
}

extern "C" void* __cdecl memset(void* dst, int c, unsigned int n);
extern "C" void* __cdecl _NiMalloc(unsigned int size);
extern int DAT_0107ec68;

struct FUN_008442a0_shell
{
    int* p1;
    int p2;
    void* p3;
    int p4;
    int __thiscall NiTMapBase_DFALL_NiTMapItem_unsigned_int_ReconstructFormData_unsigned_int_ReconstructFormData_NiTMapBase(int n);
};

// @fnv 0x008442a0
// src: EXE 0x008442a0
int __thiscall FUN_008442a0_shell::NiTMapBase_DFALL_NiTMapItem_unsigned_int_ReconstructFormData_unsigned_int_ReconstructFormData_NiTMapBase(int aiCount)
{
    p1 = &DAT_0107ec68;
    p2 = aiCount;
    p4 = 0;
    int iByteSize = p2 * 4;
    p3 = _NiMalloc(iByteSize);
    memset(p3, 0, p2 * 4);
    return (int)this;
}

void* __cdecl _NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);
extern int DAT_0107ed1c;

struct FUN_00844db0_shell
{
    void* p;
    int count;
    void* data;
    int pad;
    FUN_00844db0_shell* __thiscall NiTMapBase_DFALL_NiTMapItem_TESFile_BGSReconstructFormsInFileMap_TESFile_BGSReconstructFormsInFileMap_NiTMapBase(int param);
};

// Sets p to DAT_0107ed1c, stores param in count, allocates count*4 bytes into data, zeroes them, and returns this.
// @fnv 0x00844db0
// src: EXE 0x00844db0
FUN_00844db0_shell* __thiscall FUN_00844db0_shell::NiTMapBase_DFALL_NiTMapItem_TESFile_BGSReconstructFormsInFileMap_TESFile_BGSReconstructFormsInFileMap_NiTMapBase(int aiCount)
{
    unsigned int size;
    p = &DAT_0107ed1c;
    count = aiCount;
    pad = 0;
    size = count << 2;
    data = _NiMalloc(size);
    memset(data, 0, count << 2);
    return this;
}

// Sets the capacity of both change arrays.
// @fnv 0x00843be0
// src: COMMUNITY 0x00843be0
void FormChangeMapOperations::BGSReconstructedForms_SetAllocSize(unsigned int auiValue)
{
    reinterpret_cast<FormChangeArrayOperations*>(&first)->SetCount(auiValue);
    reinterpret_cast<FormChangeArrayOperations*>(&second)->SetCount(auiValue);
}

namespace fnv_00841e20 {
struct FUN_00452420_shell
{
    bool GetFlag(unsigned int) const;
};
struct FUN_00841990_shell
{
    bool HasCellWithFlag(unsigned int);
};
struct CellBlockFlagOperations : BGSReconstructCellBlocksMap
{
    bool HasFlagInAnyFile(unsigned int flags);
};
// @fnv 0x00841e20
bool CellBlockFlagOperations::HasFlagInAnyFile(unsigned int flags)
{
    if (unk10 && reinterpret_cast<FUN_00452420_shell*>(unk10)->GetFlag(flags))
        return true;
    void* it = reinterpret_cast<BGSReconstructFormsInAllFilesMap*>(this)->GetFirstPos();
    while (it)
    {
        TESFile* file = 0;
        BGSReconstructFormsInFileMap* map = 0;
        reinterpret_cast<BGSReconstructFormsInAllFilesMap*>(this)->GetNext(it, file, map);
        if (((FUN_00841990_shell*)map)->HasCellWithFlag(flags))
            return true;
    }
    return false;
}
}  // namespace fnv_00841e20

__declspec(thread) unsigned int DAT_00843c10_tls;

// @fnv 0x00843c10
void __thiscall BGSSaveLoadGame::SetFlag4(bool bSet)
{
    if (bSet)
        DAT_00843c10_tls |= 4;
    else
        DAT_00843c10_tls &= 0xfffffffb;
}

extern int DAT_0107ec08;
struct FUN_00844940_class
{
    virtual ~FUN_00844940_class();
};
struct FUN_008448e0 : public FUN_00844940_class
{
    virtual ~FUN_008448e0();
    void FUN_008448e0_RemoveAll();
};
// @fnv 0x008448e0
FUN_008448e0::~FUN_008448e0()
{
    FUN_008448e0_RemoveAll();
}

struct FUN_0072ba80_shell
{
    void FUN_0072ba80(void*, unsigned int);
};
struct S5460
{
    void BSSimpleArray_NiPoint2_1024_ReallocateBuffer(unsigned int, unsigned int);
};
struct FUN_00844c20_shell
{
    void SetCount(unsigned int);
};

// If idx differs from the stored count, shrinks the array to idx elements, calls FUN_006a2770 with idx and the new count, then stores idx as the count.
// @fnv 0x00844c20
void FUN_00844c20_shell::SetCount(unsigned int idx)
{
    if (idx == *(unsigned int*)((char*)this + 0xc))
        return;
    if (idx < *(unsigned int*)((char*)this + 8))
    {
        ((FUN_0072ba80_shell*)this)
            ->FUN_0072ba80((char*)*(void**)((char*)this + 4) + idx * 8, *(unsigned int*)((char*)this + 8) - idx);
        *(unsigned int*)((char*)this + 8) = idx;
    }
    ((S5460*)this)->BSSimpleArray_NiPoint2_1024_ReallocateBuffer(idx, *(unsigned int*)((char*)this + 8));
    *(unsigned int*)((char*)this + 0xc) = idx;
}

namespace fnv_00844ff0 {
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_00844fa0_class
{
    virtual ~FUN_00844fa0_class();
};
struct FUN_00844ff0 : FUN_00844fa0_class, GlobalObject_00869f00
{
    virtual ~FUN_00844ff0();
};
// Destructor that calls Clear(true) on the GlobalObject base subobject of this instance.
// @fnv 0x00844ff0
FUN_00844ff0::~FUN_00844ff0()
{
    reinterpret_cast<GlobalObject_00869f00*>(this)->Clear(true);
}
}  // namespace fnv_00844ff0

// These reconstruction operations are not yet declared by the shared cells map.
struct ReconstructCellsOperations : BGSReconstructCellsMap
{
    void ProcessCell(TESObjectCELL*, TESObjectCELL*, unsigned int, unsigned int);
    void SetAtCoordinates(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    void SetAtCoordinates(unsigned int, short, short, unsigned int, unsigned int, unsigned int);
};

// @fnv 0x00841580
void ReconstructCellsOperations::SetAtCoordinates(unsigned int, short x, short y, unsigned int auiArg1,
                                                 unsigned int auiArg2, unsigned int auiArg3)
{
    int value = TESWorldSpace::BuildCellKey(x, y);
    unsigned int key = 0;

    if (!GetAt(value, reinterpret_cast<BGSReconstructFormsMap*&>(key)))
    {
        key = (unsigned int)new BGSReconstructFormsMap;
        SetAt(value, reinterpret_cast<BGSReconstructFormsMap*>(key));
    }

    reinterpret_cast<ReconstructFormsMapOperations*>(key)->ProcessRef(auiArg1, auiArg2, auiArg3);
}

struct SetAtHelper : public DummyPointerMap
{
    void GetOrCreateAndDispatch(TESObjectCELL*, unsigned int, unsigned int, unsigned int);
};

// Creates the cells map for the key if needed, then dispatches the cell to it.
// @fnv 0x008417e0
void SetAtHelper::GetOrCreateAndDispatch(TESObjectCELL* pKeySource, unsigned int param2, unsigned int param3,
                                         unsigned int param4)
{
    unsigned int uiKey = pKeySource->GetGroupSubBlockKey();
    unsigned int uiEntry = 0;

    if (!this->GetAt(uiKey, uiEntry))
    {
        uiEntry = (unsigned int)new BGSReconstructCellsMap;
        this->SetAt(uiKey, uiEntry);
    }

    static_cast<ReconstructCellsOperations*>((BGSReconstructCellsMap*)uiEntry)
        ->ProcessCell(pKeySource, reinterpret_cast<TESObjectCELL*>(param2), param3, param4);
}

namespace fnv_008418b0 {
void* operator new(unsigned int);

int __cdecl TESObjectCELL_CalcExtGroupSubBlockKey(int, int);

struct FUN_008418b0_shell : public DummyPointerMap
{
    void GetOrCreateEntry(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
};

// @fnv 0x008418b0
void FUN_008418b0_shell::GetOrCreateEntry(unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4,
                                          unsigned int arg5, unsigned int arg6)
{
    unsigned int key = TESObjectCELL_CalcExtGroupSubBlockKey(arg2, arg3);
    BGSReconstructCellsMap* value = 0;

    if (!GetAt(key, reinterpret_cast<unsigned int&>(value)))
    {
        value = new BGSReconstructCellsMap;
        SetAt(key, reinterpret_cast<unsigned int>(value));
    }

    static_cast<ReconstructCellsOperations*>(value)->SetAtCoordinates(arg1, arg2, arg3, arg4, arg5, arg6);
}
}  // namespace fnv_008418b0

namespace fnv_00841fc0 {
void* __cdecl operator new(unsigned int);

struct DoorH
{
    void* GetParentWorldSpace();
};

struct SoundH
{
    unsigned int Deallocate();
};

// Dispatch methods absent from the shared cell-block header stay in method-only adapters.
struct CellBlockEntryOperations : BGSReconstructCellBlocksMap
{
    void ProcessEntry(DoorH*, unsigned int, unsigned int, unsigned int);
};

struct FUN_00841fc0_class : DummyPointerMap
{
    void BGSReconstructWorldSpacesMap_AddCellForm(DoorH*, unsigned int, unsigned int, unsigned int);
};

// @fnv 0x00841fc0
// src: XBOX_PDB 0x00841fc0
void FUN_00841fc0_class::BGSReconstructWorldSpacesMap_AddCellForm(DoorH* door, unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
    void* id;
    unsigned int value;
    unsigned int worldSpace;

    id = door->GetParentWorldSpace();
    value = reinterpret_cast<SoundH*>(id)->Deallocate();
    worldSpace = 0;

    if (!GetAt(value, worldSpace))
    {
        worldSpace = reinterpret_cast<unsigned int>(new BGSReconstructCellBlocksMap(true));
        SetAt(value, worldSpace);
    }

    reinterpret_cast<CellBlockEntryOperations*>(worldSpace)->ProcessEntry(door, arg1, arg2, arg3);
}
}  // namespace fnv_00841fc0

namespace fnv_008420a0 {
struct CellBlockReconstructionOperations : BGSReconstructCellBlocksMap
{
    void ReconstructFormEntry(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
};

void* __cdecl operator new(unsigned int);

unsigned int __fastcall _ref_0084e3a0(unsigned int);

struct FUN_008420a0_class : public DummyPointerMap
{
    void BGSReconstructWorldSpacesMap_AddCellForm_008420a0(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
};

// @fnv 0x008420a0
// src: XBOX_PDB 0x008420a0
void FUN_008420a0_class::BGSReconstructWorldSpacesMap_AddCellForm_008420a0(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4,
                                      unsigned int a5, unsigned int a6)
{
    unsigned int map = _ref_0084e3a0(a1);
    BGSReconstructCellBlocksMap* object = 0;

    if (!GetAt(map, reinterpret_cast<unsigned int&>(object)))
    {
        object = new BGSReconstructCellBlocksMap(true);
        SetAt(map, reinterpret_cast<unsigned int>(object));
    }

    static_cast<CellBlockReconstructionOperations*>(object)->ReconstructFormEntry(a1, a2, a3, a4, a5, a6);
}
}  // namespace fnv_008420a0

namespace fnv_00842600 {
void* __cdecl operator new(unsigned int);

struct CellBlockReferenceOperations : BGSReconstructCellBlocksMap
{
    void ProcessEntry(TESObjectCELL*, int, int, int);
};

struct FUN_00841fc0_standin
{
    void BGSReconstructWorldSpacesMap_AddCellForm(TESObjectCELL*, int, int, int);
};

struct FileCellReconstructionOperations : BGSReconstructFormsInFileMap
{
    void ProcessCell(TESObjectCELL*, int, int, int);
};

// Dispatches the cell to an interior or exterior handler, lazily allocating it, then increments a counter at offset 0x18.
// @fnv 0x00842600
void FileCellReconstructionOperations::ProcessCell(TESObjectCELL* cell, int aiArg1, int aiArg2, int aiArg3)
{
    if (cell->IsInterior())
    {
        if (!m_pInteriorMap)
        {
            m_pInteriorMap = new BGSReconstructCellBlocksMap(false);
        }

        reinterpret_cast<CellBlockReferenceOperations*>(
            m_pInteriorMap)
            ->ProcessEntry(cell, aiArg1, aiArg2, aiArg3);
    }
    else
    {
        if (!m_pExteriorMap)
        {
            m_pExteriorMap = new BGSReconstructWorldSpacesMap();
        }

        reinterpret_cast<FUN_00841fc0_standin*>(
            m_pExteriorMap)
            ->BGSReconstructWorldSpacesMap_AddCellForm(cell, aiArg1, aiArg2, aiArg3);
    }

    ++iCount;
}
}  // namespace fnv_00842600

namespace fnv_00842730 {
void* __cdecl operator new(unsigned int);

struct WorldSpaceMapOperations : BGSReconstructWorldSpacesMap
{
    void __thiscall BGSReconstructWorldSpacesMap_AddCellForm_008420a0(int, int, int, int, int, int);
};

struct FileWorldReconstructionOperations : BGSReconstructFormsInFileMap
{

    void EnsureObjectAndCall(int, int, int, int, int, int);
};

// Allocates the object if null, forwards the six arguments to its method, and increments the count.
// @fnv 0x00842730
void FileWorldReconstructionOperations::EnsureObjectAndCall(int a, int b, int c, int d, int e, int f)
{
    if (m_pExteriorMap == 0)
    {
        m_pExteriorMap = new BGSReconstructWorldSpacesMap;
    }

    static_cast<WorldSpaceMapOperations*>(m_pExteriorMap)->BGSReconstructWorldSpacesMap_AddCellForm_008420a0(a, b, c, d, e, f);

    iCount += 1;
}
}  // namespace fnv_00842730

namespace fnv_00843630 {
void* __cdecl operator new(unsigned int);
void __cdecl _fnv_call_845cc0(char const*, ...);

struct TESFormCallProxy
{
    TESFile* _FNV_GetFile(int);
    char const* TESForm_GetFormTypeString();
};

struct TESFormRefProxy
{
    unsigned int _ref_0084e3a0();
};

struct MapCallProxy
{
    void BGSReconstructFormsInFileMap_AddForm(TESForm*, unsigned int);
};

struct ReconstructFilesFormOperations : BGSReconstructFormsInAllFilesMap
{
    void BGSReconstructFormsInAllFilesMap_AddForm(TESForm*, unsigned int);
};

// Adds apForm to the per-file map keyed by its TESFile, creating the entry if missing, then increments iCount; logs an error when the form has no file.
// @fnv 0x00843630
// src: EXE 0x00843630
void ReconstructFilesFormOperations::BGSReconstructFormsInAllFilesMap_AddForm(TESForm* apForm, unsigned int aiFlags)
{
    BGSReconstructFormsInFileMap* pformsInFileMap;
    TESFile* pfile;

    if (!apForm)
        return;

    pfile = reinterpret_cast<TESFormCallProxy*>(apForm)->_FNV_GetFile(-1);

    if (!pfile)
    {
        _fnv_call_845cc0("Form %08X %s with type %s and no file passed to BGSReconstructFormsInAllFilesMap::AddForm()",
                         reinterpret_cast<TESFormRefProxy*>(apForm)->_ref_0084e3a0(),
                         apForm->GetName(),
                         reinterpret_cast<TESFormCallProxy*>(apForm)->TESForm_GetFormTypeString());
        return;
    }

    pformsInFileMap = 0;

    if (!GetAt(pfile, pformsInFileMap))
    {
        pformsInFileMap = new BGSReconstructFormsInFileMap();

        SetAt(pfile, pformsInFileMap);
    }

    reinterpret_cast<MapCallProxy*>(pformsInFileMap)->BGSReconstructFormsInFileMap_AddForm(apForm, aiFlags);

    ++iCount;
}
}  // namespace fnv_00843630

namespace fnv_00844c90 {
struct FUN_00692480
{
    void Method(char*, char*, unsigned int);
};

struct FUN_006c8a30_Class
{
    void FUN_006a8500();
};

struct FUN_006f3170_Class
{
    bool BSSimpleArray_HasSufficientCapacity();
};

struct FUN_0072ba80_shell
{
    void FUN_0072ba80(char*, unsigned int);
};

struct FUN_00869600_Class
{
    unsigned int BSSimpleArray_GetOptimalCapacity();
};

struct FUN_00844c90_shell
{
    // Virtual destructor for the shell object; empty body.
// @fnv 0x00844c90
    virtual ~FUN_00844c90_shell()
    {}
    virtual char* GetArray(unsigned int) = 0;

    char* m_items;
    unsigned int m_uiItemCount;
    unsigned int m_uiFilterValue;

    void BSSimpleArray_RemoveAt(unsigned int, bool);
};

// src: COMMUNITY 0x00844c90
void FUN_00844c90_shell::BSSimpleArray_RemoveAt(unsigned int index, bool useArray)
{
    char* array;

    if (useArray && reinterpret_cast<FUN_006f3170_Class*>(this)->BSSimpleArray_HasSufficientCapacity())
    {
        unsigned int count = reinterpret_cast<FUN_00869600_Class*>(this)->BSSimpleArray_GetOptimalCapacity();
        array = GetArray(count);

        reinterpret_cast<FUN_00692480*>(this)->Method(array, m_items, index);
        reinterpret_cast<FUN_0072ba80_shell*>(this)->FUN_0072ba80(m_items + index * 8, 1);

        reinterpret_cast<FUN_00692480*>(this)->Method(array + index * 8, m_items + index * 8 + 8, m_uiItemCount - 1);

        reinterpret_cast<FUN_006c8a30_Class*>(this)->FUN_006a8500();
        m_items = array;
        m_uiFilterValue = count;
    }
    else
    {
        reinterpret_cast<FUN_0072ba80_shell*>(this)->FUN_0072ba80(m_items + index * 8, 1);

        reinterpret_cast<FUN_00692480*>(this)->Method(m_items + index * 8, m_items + index * 8 + 8,
                                                      m_uiItemCount - index - 1);
    }

    --m_uiItemCount;
}
}  // namespace fnv_00844c90

namespace fnv_00841b20 {
void* __cdecl operator new(unsigned int);

// The shared reference does not expose this save-state query.
struct ReferenceSaveCheck : TESObjectREFR
{
    bool TESObjectREFR_GetPersistFlagValue();
};

struct FormReferenceOperations : BGSReconstructFormsMap
{
    void ProcessRef(ReferenceSaveCheck*, unsigned int, unsigned int);
};

struct CellSubBlockDispatch : BGSReconstructCellSubBlocksMap
{
    void GetOrCreateAndDispatch(TESObjectCELL*, ReferenceSaveCheck*, unsigned int, unsigned int);
};

struct CellBlockReferenceOperations : BGSReconstructCellBlocksMap
{
    void ProcessEntry(TESObjectCELL*, ReferenceSaveCheck*, unsigned int, unsigned int);
};

// @fnv 0x00841b20
void CellBlockReferenceOperations::ProcessEntry(TESObjectCELL* first, ReferenceSaveCheck* second, unsigned int third,
                                      unsigned int fourth)
{
    if (unk14 && second && second->GetIsReference())
    {
        ReferenceSaveCheck* shell = second;

        if (shell->TESObjectREFR_GetPersistFlagValue())
        {
            if (!unk10)
                unk10 = reinterpret_cast<int>(new BGSReconstructFormsMap());

            reinterpret_cast<FormReferenceOperations*>(unk10)->ProcessRef(second, third, fourth);
            return;
        }
    }

    unsigned int key = first->GetGroupBlockKey();
    unsigned int value = 0;

    if (!GetAt(key, reinterpret_cast<BGSReconstructCellSubBlocksMap*&>(value)))
    {
        value = reinterpret_cast<unsigned int>(new BGSReconstructCellSubBlocksMap());
        SetAt(key, reinterpret_cast<BGSReconstructCellSubBlocksMap*>(value));
    }

    reinterpret_cast<CellSubBlockDispatch*>(value)->GetOrCreateAndDispatch(first, second, third, fourth);
}
}  // namespace fnv_00841b20

// @fnv 0x00844ae0
template <>
void BSSimpleArray<OffsetData>::SetSize(unsigned int size, bool clear)
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
    }
    else if (size < this->iSize)
    {
        this->ReleaseElements(this->pBuffer + size, this->iSize - size);
        this->iSize = size;

        if (clear && size <= this->SimpleArrayStorage / 4)
        {
            this->ReallocateStorage(size, size);
            this->SimpleArrayStorage = size;
        }
    }
    else
    {
        this->InitializeItems(this->pBuffer + this->iSize, size - this->iSize);
        this->iSize = size;
    }
}

// @fnv 0x008411f0
BGSReconstructFormsMap::~BGSReconstructFormsMap()
{
    reinterpret_cast<NiTPointerMap<unsigned int, unsigned int>*>(this)->RemoveAll();
}

// @fnv 0x008413a0
BGSReconstructCellsMap::~BGSReconstructCellsMap()
{
    void* pos2 = reinterpret_cast<NiTPointerMap<unsigned int, BGSReconstructFormsMap*>*>(this)->GetFirstPos();
    while (pos2 != 0)
    {
        unsigned int key = 0;
        BGSReconstructFormsMap* data2 = 0;
        reinterpret_cast<NiTPointerMap<unsigned int, BGSReconstructFormsMap*>*>(this)->GetNext(pos2, key, data2);
        delete data2;
    }
}

struct ValueItem
{
    virtual ~ValueItem();
};
// Iterates the map via FUN_004b9ba0/FUN_006b7f20, deleting each ValueItem until the position is null.
// @fnv 0x00841720
BGSReconstructCellSubBlocksMap::~BGSReconstructCellSubBlocksMap()
{
    void* position = reinterpret_cast<NiTPointerMap<unsigned int, ValueItem*>*>(this)->GetFirstPos();
    while (position != 0)
    {
        ValueItem* item;
        {
            unsigned int key = 0;
            item = 0;
            reinterpret_cast<NiTPointerMap<unsigned int, ValueItem*>*>(this)->GetNext(position, key, item);
        }
        delete item;
    }
}

struct FUN_00401170_shell
{
    unsigned int FUN_00401170();
};

struct FUN_00844eb0_shell
{
    void AppendElementAndRecordSize(ChangedFormRecord* apData);
};

// Dispatches apData to one of two handlers depending on whether its form is a reference or has type 0x39 or 0x41.
// @fnv 0x00843270
// src: COMMUNITY 0x00843270
void FormChangeMapOperations::BGSReconstructedForms_AddFormData(ChangedFormRecord* apData)
{
    if (!apData->pForm->GetIsReference() && ((FUN_00401170_shell*)apData->pForm)->FUN_00401170() != 0x39 &&
        ((FUN_00401170_shell*)apData->pForm)->FUN_00401170() != 0x41)
    {
        ((FUN_00844eb0_shell*)&first)->AppendElementAndRecordSize(apData);
    }
    else
    {
        ((FUN_00844eb0_shell*)&second)->AppendElementAndRecordSize(apData);
    }
}

struct FNV_ValuePair
{
    unsigned int data1;
    unsigned int data2;
};
struct FNV_MapEntry
{
    FNV_MapEntry* next;
    unsigned int key;
    FNV_ValuePair data;
};

class FNV_BucketMap
{
  public:
    virtual void OnDestroy();
    virtual unsigned int GetBucket(unsigned int key);
    virtual bool IsEqual(unsigned int key, unsigned int entryKey);
    virtual void InitializeEntry(FNV_MapEntry* entry, unsigned int key, FNV_ValuePair value);
    virtual void ReservedSlot();
    virtual FNV_MapEntry* NewEntry();

    unsigned int bucketCount;
    FNV_MapEntry** buckets;
    unsigned int entryCount;

    void SetValue(unsigned int key, FNV_ValuePair value);
};

// Looks up the entry for key in its bucket and overwrites its value, or creates, initializes and prepends a new entry and increments entryCount.
// @fnv 0x00844310
void FNV_BucketMap::SetValue(unsigned int key, FNV_ValuePair valuePair)
{
    unsigned int bucketIndex = GetBucket(key);
    FNV_MapEntry* entry = buckets[bucketIndex];
    unsigned int visited = 0;
    while (entry)
    {
        ++visited;
        if (IsEqual(key, entry->key))
        {
            entry->data = valuePair;
            return;
        }
        entry = entry->next;
    }
    entry = NewEntry();
    InitializeEntry(entry, key, valuePair);
    entry->next = buckets[bucketIndex];
    buckets[bucketIndex] = entry;
    entryCount += 1;
}

struct Base00844660
{
    virtual ~Base00844660();
};

struct FUN_00844600 : Base00844660
{
    void FUN_00438af0();
    virtual ~FUN_00844600();
};

// Destructor that calls FUN_00438af0 before the object is destroyed.
// @fnv 0x00844600
FUN_00844600::~FUN_00844600()
{
    FUN_00438af0();
}

struct Base
{
    virtual ~Base();
};

struct FUN_008447e0 : Base
{
    virtual ~FUN_008447e0();
};

// Destructor that clears the NiTPointerMap by calling RemoveAll.
// @fnv 0x008447e0
FUN_008447e0::~FUN_008447e0()
{
    ((NiTPointerMap<int, int>*)this)->RemoveAll();
}

struct FUN_00844a40
{
    virtual ~FUN_00844a40();
};

struct FUN_008449e0_cls : public FUN_00844a40
{
    void Clear();
    virtual ~FUN_008449e0_cls();
};

// @fnv 0x008449e0
FUN_008449e0_cls::~FUN_008449e0_cls()
{
    Clear();
}

struct FormContext
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void Slot56();
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void Slot60();
    virtual void Slot61();
    virtual void Slot62();
    virtual void Slot63();
    virtual void Slot64();
    virtual void Slot65();
    virtual void Slot66();
    virtual void Slot67();
    virtual void Slot68();
    virtual void Slot69();
    virtual void Slot70();
    virtual void Slot71();
    virtual void Slot72();
    virtual void Slot73();
    virtual void Slot74();
    virtual void Slot75();
    virtual const char* GetDisplayName();
    TESFile* FUN_00484e60(int fileIndex);
    const char* GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};

struct FormTypeReader
{
    unsigned int FUN_00401170();
};

void __cdecl ResolveFormID(unsigned int* numericID, TESFile* file);
extern "C" void __cdecl Warning_005b5e40(const char* format, ...);
extern char DAT_01014168[];
extern char DAT_01014100[];

struct FUN_0040e7f0_owner
{
    TESForm* primary;
    TESGlobal* secondary;
    void ResolveFormReferences(FormContext* context);
};

// Resolves primary and secondary form references through the file context, logging failures and clearing secondary when primary is null.
// @fnv 0x0040e7f0
void FUN_0040e7f0_owner::ResolveFormReferences(FormContext* context)
{
    if (primary != 0)
    {
        unsigned int numericID = (unsigned int)primary;
        ResolveFormID(&numericID, context->FUN_00484e60(-1));
        primary = _ref_004839c0(numericID);
        if (primary == 0)
        {
            Warning_005b5e40(DAT_01014168, numericID, context->GetDisplayName(), context->GetHavokWorldObjectCountInSceneGraph_0084e3a0());
        }
    }

    if (primary != 0)
    {
        if (((FormTypeReader*)primary)->FUN_00401170() == 42 && secondary != 0)
        {
            unsigned int uiSecondaryID = (unsigned int)secondary;
            ResolveFormID(&uiSecondaryID, context->FUN_00484e60(-1));
            secondary = dynamic_cast<TESGlobal*>(_ref_004839c0(uiSecondaryID));
            if (secondary == 0)
            {
                Warning_005b5e40(DAT_01014100, uiSecondaryID, context->GetDisplayName(), context->GetHavokWorldObjectCountInSceneGraph_0084e3a0());
            }
        }
    }
    else
    {
        secondary = 0;
    }
}

struct ReconstructCellBlock
{
    virtual ~ReconstructCellBlock();
};
// @fnv 0x00841a60
BGSReconstructCellBlocksMap::~BGSReconstructCellBlocksMap()
{
    void* position = reinterpret_cast<NiTPointerMap<unsigned int, ValueItem*>*>(this)->GetFirstPos();
    while (position)
    {
        unsigned int key = 0;
        ReconstructCellBlock* pEntry = 0;
        reinterpret_cast<NiTPointerMap<unsigned int, ReconstructCellBlock*>*>(this)->GetNext(position, key, pEntry);
        delete pEntry;
    }
}

struct FormWithSaveCheck : TESForm
{
    bool TESObjectREFR_GetPersistFlagValue();
};
struct ReconstructEntry
{
    void ProcessRef(FormWithSaveCheck*, int, int);
    void GetOrCreateEntry(int, int, int, FormWithSaveCheck*, int, int);
};
int __cdecl GetCellCoordKey(int, int);
struct CellBlockSaveLoadOperations : BGSReconstructCellBlocksMap
{
    void ReconstructFormEntry(int, int, int, FormWithSaveCheck*, int, int);
};
// If form is a reference with a save check, forwards it through unk10; otherwise looks up or creates a ReconstructEntry for the handle and reconstructs the entry.
// @fnv 0x00841ca0
void CellBlockSaveLoadOperations::ReconstructFormEntry(int value, int formID, int context, FormWithSaveCheck* form, int flag,
                                              int offset)
{
    int handle3;
    FormWithSaveCheck* referenceForm;
    ReconstructEntry* entry7;
    if (form != 0 && form->GetIsReference() && (referenceForm = form, referenceForm->TESObjectREFR_GetPersistFlagValue()))
    {
        if (unk10 == 0)
            unk10 = reinterpret_cast<int>(new BGSReconstructFormsMap);
        reinterpret_cast<ReconstructEntry*>(unk10)->ProcessRef(form, flag, offset);
    }
    else
    {
        handle3 = GetCellCoordKey(formID, context);
        entry7 = 0;
        if (!GetAt(handle3, reinterpret_cast<BGSReconstructCellSubBlocksMap*&>(entry7)))
        {
            entry7 = (ReconstructEntry*)new BGSReconstructCellSubBlocksMap;
            SetAt(handle3, reinterpret_cast<BGSReconstructCellSubBlocksMap*>(entry7));
        }
        entry7->GetOrCreateEntry(value, formID, context, form, flag, offset);
    }
}

// @fnv 0x008421f0
BGSReconstructFormsInFileMap::~BGSReconstructFormsInFileMap()
{
    void* pPos = reinterpret_cast<NiTPointerMap<unsigned int, BGSCellNumericIDArrayMap*>*>(this)->GetFirstPos();
    while (pPos)
    {
        unsigned int uiKey = 0;
        BGSCellNumericIDArrayMap* pItem = 0;
        reinterpret_cast<NiTPointerMap<unsigned int, BGSCellNumericIDArrayMap*>*>(this)->GetNext(pPos, uiKey, pItem);
        delete pItem;
    }
    delete reinterpret_cast<BGSCellNumericIDArrayMap*>(m_pInteriorMap);
    delete reinterpret_cast<BGSCellNumericIDArrayMap*>(m_pExteriorMap);
}


int __cdecl FloatToInt(float afValue);

struct RegPoint
{
    float x, y, z;
    RegPoint();
};

struct RegRef;
void __cdecl FUN_00846190(int aiIndex, void** appCell, void** appWorld);

struct RegLand
{
    void* FUN_0054ddd0();
    int FUN_00544c30();
    int FUN_00544c60();
};

struct RegRef
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual int GetFormType();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual bool IsReference();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual bool GetPosition(RegPoint* apPos, RegPoint* apRot, int* apIndex, int aiUnk);
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual void v1A0();
    virtual void v1A4();
    virtual void v1A8();
    virtual void v1AC();
    virtual void v1B0();
    virtual void v1B4();
    virtual void v1B8();
    virtual void v1BC();
    virtual void v1C0();
    virtual void v1C4();
    virtual void v1C8();
    virtual void v1CC();
    virtual void v1D0();
    virtual void v1D4();
    virtual void v1D8();
    virtual void v1DC();
    virtual void v1E0();
    virtual void v1E4();
    virtual void v1E8();
    virtual void v1EC();
    virtual void v1F0();
    virtual const RegPoint& GetPos();
    void* TESObjectREFR_GetWorldSpace();
    void* FUN_008d6f30();
    RegLand* FUN_0059bb30();
};

struct RegList
{
    int unk00, unk04, unk08, unk0C, unk10;
    RegList();
    void ProcessRef(RegRef* apRef, int aiUnk, int aiArg);
};

struct RegFormTypeEntry
{
    int iKey;
    int unk04;
    int unk08;
};
extern RegFormTypeEntry g_aRegFormTypes[];

struct RegManager : BGSReconstructFormsInFileMap
{

    void EnsureObjectAndCall(void* apCell, int aiX, int aiY, RegRef* apRef, int aiUnk, int aiArg);
    void ProcessCell(void* apCell, RegRef* apRef, int aiUnk, int aiArg);
    bool FUN_00853130(int aiKey, RegList** appList);
    void FUN_00844700(int aiKey, RegList* apList);
    void BGSReconstructFormsInFileMap_AddForm(RegRef* apRef, int aiArg);
};

// Registers a reference by form type: resolves its cell/world position or land cell and dispatches to the matching registration routine.
// @fnv 0x00842310
// src: XBOX_PDB 0x00842310
void RegManager::BGSReconstructFormsInFileMap_AddForm(RegRef* apRef, int aiArg)
{
    int iType9 = apRef->GetFormType();
    if (apRef->IsReference())
    {
        RegRef* pRef6 = apRef;
        RegPoint _kPos;
        RegPoint kRotX;
        int iIndex6 = 0;
        void* pWorldX = 0;
        void* pCellB = 0;
        if (pRef6->GetPosition(&_kPos, &kRotX, &iIndex6, 0))
            FUN_00846190(iIndex6, &pWorldX, &pCellB);
        else if ((pCellB = pRef6->TESObjectREFR_GetWorldSpace()) != 0)
            _kPos = pRef6->GetPos();
        else
            pWorldX = pRef6->FUN_008d6f30();
        if (pCellB)
        {
            int iX8 = FloatToInt(_kPos.x) >> 12;
            int kIY = FloatToInt(_kPos.y) >> 12;
            EnsureObjectAndCall(pCellB, iX8, kIY, apRef, 0, aiArg);
        }
        else if (pWorldX)
            ProcessCell(pWorldX, apRef, 0, aiArg);
    }
    else if (iType9 == 0x43)
    {
        RegRef* pLandRef3 = apRef;
        RegLand* pLand4 = pLandRef3->FUN_0059bb30();
        void* pLandCell9 = pLand4 ? pLand4->FUN_0054ddd0() : 0;
        if (pLandCell9)
            EnsureObjectAndCall(pLandCell9, pLand4->FUN_00544c30(), pLand4->FUN_00544c60(), apRef, 0, aiArg);
        else if (pLand4)
            ProcessCell(pLand4, apRef, 0, aiArg);
    }
    else if (iType9 == 0x39)
        ProcessCell(apRef, apRef, 0, aiArg);
    else if (iType9 == 0x41)
        ;
    else
    {
        int iKey8 = g_aRegFormTypes[apRef->GetFormType()].iKey;
        RegList* pList5 = 0;
        if (!FUN_00853130(iKey8, &pList5))
        {
            pList5 = new RegList;
            FUN_00844700(iKey8, pList5);
        }
        pList5->ProcessRef(apRef, 0, aiArg);
        iCount++;
    }
}

void SaveGameWarning(const char* fmt, ...);

struct ExtendedForm : TESForm
{
    BSSimpleList<TESFile*>* GetSourceFiles();
    unsigned int GetFormID();

};

struct ExtendedFileMap : BGSReconstructFormsInFileMap
{
    void EnsureObjectAndCall(ExtendedForm* form, unsigned int arg2, unsigned int arg3, unsigned int zero,
                             unsigned int arg4, unsigned int arg5);
};

struct ReconstructMapHelper : BGSReconstructFormsInAllFilesMap
{
    TESFile* BGSReconstructFormsInAllFilesMap_GetFileForFormID(BSSimpleList<TESFile*>* apFileList, unsigned int arg4);
    void BGSReconstructFormsInAllFilesMap_AddReference_008438b0(ExtendedForm* form, unsigned int arg2, unsigned int arg3, unsigned int arg4, unsigned int arg5);
};

// Resolves the form's source file, creates or fetches its ExtendedFileMap, adds the reference to it, and increments iCount; logs an error if no file is found.
// @fnv 0x008438b0
// src: EXE 0x008438b0
void ReconstructMapHelper::BGSReconstructFormsInAllFilesMap_AddReference_008438b0(ExtendedForm* form, unsigned int arg2, unsigned int arg3, unsigned int arg4,
                                        unsigned int arg5)
{
    if (!form)
        return;

    TESFile* file = this->BGSReconstructFormsInAllFilesMap_GetFileForFormID(form->GetSourceFiles(), arg4);
    if (!file)
    {
        SaveGameWarning("Worldspace %08X %s with no file passed to BGSReconstructFormsInAllFilesMap::AddReference()",
                     form->GetFormID(), form->GetName());
        return;
    }

    ExtendedFileMap* subMap = 0;
    if (!GetAt(file, reinterpret_cast<BGSReconstructFormsInFileMap*&>(subMap)))
    {
        subMap = new ExtendedFileMap();
        this->SetAt(file, subMap);
    }
    subMap->EnsureObjectAndCall(form, arg2, arg3, 0, arg4, arg5);
    ++this->iCount;
}

namespace fnv_00843c90 {
struct SceneNode
{
    float GetFloatAt64();
};
struct ObjectBaseView
{
    bool TESForm_GetHasSpokenFlag() const;
};
struct ReferenceView;
struct EnableState
{
    void FUN_006fcfa0();
};
struct WorldSpaceView
{
    EnableState* FUN_00586170(ReferenceView*, bool);
};
struct ActorBaseView
{
    void FUN_005f9e00(ReferenceView*, bool, bool, bool);
    void InitDefaultWorn(ReferenceView*, bool, bool, bool, bool);
};
struct ProcessView
{
    virtual ~ProcessView();
};
struct FUN_00906dc0 : ProcessView
{
    FUN_00906dc0();
    unsigned int field_04;
    unsigned int field_08;
    unsigned int field_0c;
    unsigned int field_10;
    unsigned int field_14;
    unsigned int field_18;
    unsigned int field_1c;
    unsigned int field_20;
    unsigned int field_24;
    unsigned int field_28;
    unsigned int field_2c;
    unsigned int field_30;
    unsigned int field_34;
    unsigned int field_38;
    unsigned int field_3c;
    unsigned int field_40;
    unsigned int field_44;
    unsigned int field_48;
    unsigned int field_4c;
    unsigned int field_50;
    unsigned int field_54;
    unsigned int field_58;
    unsigned int field_5c;
    unsigned int field_60;
    unsigned int field_64;
    unsigned int field_68;
    unsigned int field_6c;
    unsigned int field_70;
    unsigned int field_74;
    unsigned int field_78;
    unsigned int field_7c;
    unsigned int field_80;
    unsigned int field_84;
    unsigned int field_88;
    unsigned int field_8c;
    unsigned int field_90;
    unsigned int field_94;
    unsigned int field_98;
    unsigned int field_9c;
    unsigned int field_a0;
    unsigned int field_a4;
    unsigned int field_a8;
    unsigned int field_ac;
    unsigned int field_b0;
};
struct SecondaryForm
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void Reset(int);
};
struct ExtendedForm : TESForm
{
    unsigned int field_18;
    unsigned int field_1c;
    unsigned int field_20;
    unsigned int field_24;
    unsigned int field_28;
    unsigned int field_2c;
};
struct MultipleForm : ExtendedForm, SecondaryForm
{
};
// Extra mobile-reference operations absent from the shared reference declaration.
struct ReferenceView : TESObjectREFR
{
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void InitializeProcess();
    float FUN_00598040();
    void TESObjectREFR_SetScale(float);
    bool TESForm_GetDisabledOrDeleted();
    ProcessView* FUN_008d8520();
    int FUN_00931850();
    void FUN_00407800(ProcessView*);
    ActorBaseView* FUN_004181e0();
};
struct ActorDeletionQueue
{
    void ProcessLists_RemoveReference(ReferenceView*, int);
};
extern ActorDeletionQueue DAT_011e0e80;
// Additional operation over the shared save/load-game layout.
struct SaveLoadView : BGSSaveLoadGame
{
    void FUN_0084a520(ReferenceView*);
};
struct ReconstructDataView : ChangedFormRecord
{
    bool FUN_00461580(unsigned int);
};
struct NavInfoView
{
    void FUN_00693ef0(bool);
};
struct NavFormView : TESForm
{
    int FUN_00401170();
    NavInfoView* GetNavMeshInfo_0068efb0();
    bool FUN_00440da0();
};
struct ReconstructionWorker
{
    void ReconstructForm(ReconstructDataView* data);
};
// @fnv 0x00843c90
void ReconstructionWorker::ReconstructForm(ReconstructDataView* data)
{
    if (data->pForm->GetIsReference())
    {
        ReferenceView* reference = (ReferenceView*)data->pForm;
        SceneNode* sceneNode = reinterpret_cast<SceneNode*>(reference->GetNiNode());
        if (sceneNode && sceneNode->GetFloatAt64() != reference->TESObjectREFR_GetScale_00567400())
            reference->TESObjectREFR_SetScale(reference->FUN_00598040());
        if (data->FUN_00461580(8) && reinterpret_cast<ObjectBaseView*>(reference->BGSSaveFormBuffer_GetForm())->TESForm_GetHasSpokenFlag() && reference->FUN_00440da0())
        {
            WorldSpaceView* world = reinterpret_cast<WorldSpaceView*>(reference->TESObjectREFR_GetWorldSpace());
            if (world)
                world->FUN_00586170(reference, true)->FUN_006fcfa0();
        }
        if (reference->IsMobileObject())
        {
            ReferenceView* mobile = reference;
            if (mobile->TESForm_GetDisabledOrDeleted())
            {
                if (data->FUN_00461580(8) && mobile->FUN_008d8520())
                {
                    DAT_011e0e80.ProcessLists_RemoveReference(mobile, mobile->FUN_00931850());
                    delete mobile->FUN_008d8520();
                    mobile->FUN_00407800(0);
                }
            }
            else if (!mobile->FUN_008d8520())
            {
                mobile->FUN_00407800(new FUN_00906dc0);
                mobile->InitializeProcess();
            }
            if (mobile->IsActor())
            {
                ReferenceView* actor = mobile;
                ((SaveLoadView*)g_BGSSaveLoadGame)->FUN_0084a520(actor);
                if (data->FUN_00461580(8) && actor->GetNiNode())
                {
                    if (actor->IsCreature())
                    {
                        ActorBaseView* creatureBase = actor->FUN_004181e0();
                        creatureBase->FUN_005f9e00(actor, true, true, true);
                    }
                    else
                    {
                        ActorBaseView* npcBase = actor->FUN_004181e0();
                        npcBase->InitDefaultWorn(actor, true, true, false, true);
                    }
                }
            }
        }
    }
    else if (((ExtendedForm*)data->pForm)->Unk_3E())
    {
        MultipleForm* form = (MultipleForm*)data->pForm;
        SecondaryForm* secondary = form;
        secondary->Reset(0);
    }
    else if (((NavFormView*)data->pForm)->FUN_00401170() == 0x43)
    {
        NavFormView* pNavForm = (NavFormView*)data->pForm;
        if (pNavForm->GetNavMeshInfo_0068efb0())
            pNavForm->GetNavMeshInfo_0068efb0()->FUN_00693ef0(pNavForm->FUN_00440da0());
    }
}
}  // namespace fnv_00843c90

class B844F00Allocator;

class B844F00MemoryManager
{
  public:
    B844F00Allocator* GetDefaultAllocator();
};

B844F00MemoryManager* B844F00GetMemoryManager();

class B844F00Base
{
  public:
    B844F00Base();
    virtual ~B844F00Base();

    void Init(int iSize, int iGrowBy);

    int unk04;
    int unk08;
    int unk0C;
    B844F00Allocator* m_pHeapAllocator;
};

class FUN_00844f00_cls : public B844F00Base
{
  public:
    FUN_00844f00_cls(int iSize, int iGrowBy, B844F00Allocator* pkAllocator);
    virtual ~FUN_00844f00_cls();
};

// Stores the given allocator, or the memory manager's default allocator when none is given, then calls Init with the size and grow-by values.
// @fnv 0x00844f00
FUN_00844f00_cls::FUN_00844f00_cls(int iSize, int iGrowBy, B844F00Allocator* pkAllocator)
{
    m_pHeapAllocator = pkAllocator ? pkAllocator : B844F00GetMemoryManager()->GetDefaultAllocator();
    Init(iSize, iGrowBy);
}

struct Val8443
{
    int a;
    int b;
};
struct Item8443
{
    Item8443* m_pkNext;
    unsigned int m_key;
    Val8443 m_val;
};
class FUN_8443Map
{
  public:
    virtual ~FUN_8443Map();
    virtual unsigned int KeyToHashIndex(unsigned int key);
    virtual bool IsKeysEqual(unsigned int key1, unsigned int key2);
    unsigned int m_uiHashSize;
    Item8443** m_ppkHashTable;
    bool Lookup(unsigned int key, Val8443& val);
};
// Hashes the key, walks the bucket chain comparing keys, and copies the matching item's value into val, returning whether a match was found.
// @fnv 0x008443f0
bool FUN_8443Map::Lookup(unsigned int key, Val8443& val)
{
    unsigned int uiIndex = KeyToHashIndex(key);
    Item8443* pkItem = m_ppkHashTable[uiIndex];
    while (pkItem)
    {
        if (IsKeysEqual(key, pkItem->m_key))
        {
            val = pkItem->m_val;
            return true;
        }
        pkItem = pkItem->m_pkNext;
    }
    return false;
}

class FUN_008444d0
{
  public:
    virtual ~FUN_008444d0();
};
class FUN_00844470 : public FUN_008444d0
{
  public:
    void FUN_00438af0();
    virtual ~FUN_00844470();
};
// Destructor that calls FUN_00438af0 before the object is destroyed.
// @fnv 0x00844470
FUN_00844470::~FUN_00844470()
{
    FUN_00438af0();
}

// Prior reconstruction by another contributor (2026-10-23); unverified; attribution retained.


struct RebuildForm
{
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};

struct RebuildMap;

struct RebuildResult
{

    RebuildForm* form;
    RebuildMap* recordC;

    RebuildResult();
    RebuildResult(RebuildForm*, RebuildMap*);

    bool ActorCause_IsValid();
    void ClearFields();
};

struct RebuildHeader
{
    unsigned int type, sizeXA, label, group, formId4;
};

// TESFile does not yet expose these two reconstruction operations.
struct ReconstructionFileOperations : TESFile
{
    void ResetFileState(bool);
    void SkipCurrentForm();
};

struct RebuildMap
{

    bool FUN_00853130(unsigned int, RebuildMap**);

    bool HasFlagInAnyFile(int);
    bool FUN_00452420(unsigned int);
    bool InterfaceManager_GetMagicPageNumber();

    RebuildMap* TESMain_GetThread();
    void FUN_00841320(unsigned int);
    bool Lookup(unsigned int, RebuildResult*);
};

struct RebuildQueue
{

    unsigned int unk00, unk04, unk08, unk0c, unk10;

    RebuildQueue();
    ~RebuildQueue();

    void ConstructAndForward(unsigned int, RebuildMap*);

    unsigned int FUN_0044ddc0();
    RebuildResult* BSSimpleArray_GroupMemberData_1024_GetAt(unsigned int);
};

struct RebuildCoordinates
{
    int x, y, z;
    RebuildCoordinates();
    void TwoValues_Endian();
};

struct RebuildOutput
{
    void BGSReconstructedForms_AddFormData(RebuildResult*);
};


void ResolveFormID(unsigned int*, TESFile*);

unsigned int PackShortPair(unsigned short, unsigned short);

RebuildForm* TESForm_GetFormByNumericID(unsigned int);

void* ourMemset(void*, int, unsigned int);

void SaveGameWarning(const char*, ...);

const char* FindFormEnumIndex(unsigned int);
const char* GetStringForByte(const char*);

extern unsigned int DAT_01187014, DAT_01187020, DAT_011872b4, DAT_01187314, DAT_011873c8;

extern RebuildForm* DAT_011c3f30;

extern TESDataHandler* DAT_011c3f2c;

// Walks a RebuildFile, resolving world/block/record context and reconstructing forms into output, queueing pending results as needed.
// @fnv 0x008427f0
void BGSReconstructFormsInFileMap::BuildMap(TESFile* file, FormChangeMap* output)

{

    if (!static_cast<unsigned int>(iCount))
        return;

    static_cast<ReconstructionFileOperations*>(file)->ResetFileState(true);

    RebuildHeader* pData7 = reinterpret_cast<RebuildHeader*>(file->GetRecordHeader());

    while (pData7->type == DAT_01187014)
        file->NextForm_00472150(true);

    RebuildMap* world8 = 0;

    RebuildMap* block3 = 0;

    RebuildMap* subBlock = 0;

    RebuildMap* recordC = 0;

    unsigned int idA = 0;
    unsigned int formId4 = 0;

    DAT_011c3f30 = 0;

    bool cached = file->GetCached();

    unsigned int restoredA = 0;

    RebuildQueue queued3;

    unsigned int next4 = 0;

    unsigned int groupEndA = 0;

    bool pending4 = false;

    while (pData7->type && restoredA < static_cast<unsigned int>(iCount))
    {

        RebuildResult result;

        if (pData7->type == DAT_01187020)
        {

            if (pData7->label == DAT_011872b4 || pData7->label == DAT_01187314)
            {

                world8 = 0;

                bool isWorld = pData7->label == DAT_01187314;

                if (isWorld)
                {

                    if (reinterpret_cast<RebuildMap*>(m_pExteriorMap))
                        file->NextForm_00472150(true);

                    else
                        file->FUN_00473660();
                }
                else
                {

                    if (reinterpret_cast<RebuildMap*>(m_pInteriorMap))
                    {
                        world8 = reinterpret_cast<RebuildMap*>(m_pInteriorMap);
                        file->NextForm_00472150(true);
                    }

                    else
                        file->FUN_00473660();
                }

                block3 = 0;
                subBlock = 0;
                recordC = 0;
            }
            else if (pData7->group)
            {

                switch (pData7->group)
                {

                case 1: {

                    unsigned int id = pData7->label;

                    ResolveFormID(&id, file);

                    if (reinterpret_cast<RebuildMap*>(m_pExteriorMap)->FUN_00853130(id, &world8))
                    {

                        if (cached && world8->HasFlagInAnyFile(5))
                            queued3.ConstructAndForward(pData7->formId4, 0);

                        file->NextForm_00472150(true);
                    }
                    else
                        file->FUN_00473660();

                    block3 = 0;
                    subBlock = 0;
                    recordC = 0;
                }
                break;

                case 2:
                case 4:

                    if (world8->FUN_00853130(pData7->label, &block3))
                        file->NextForm_00472150(true);

                    else
                        file->FUN_00473660();

                    subBlock = 0;
                    recordC = 0;

                    break;

                case 3:
                case 5:

                    if (block3->FUN_00853130(pData7->label, &subBlock))
                        file->NextForm_00472150(true);

                    else
                        file->FUN_00473660();

                    recordC = 0;

                    break;

                case 6:

                    if (recordC)
                    {

                        bool persistent = recordC->FUN_00452420(2);

                        bool temp = recordC->FUN_00452420(4);

                        if (cached && !idA && temp)
                        {

                            queued3.ConstructAndForward(pData7->formId4, recordC);
                            temp = false;
                        }

                        if (persistent || temp)
                            file->NextForm_00472150(true);

                        else
                            file->FUN_00473660();
                    }
                    else
                        file->FUN_00473660();

                    break;

                case 8:

                    if (recordC->FUN_00452420(2))
                        file->NextForm_00472150(true);

                    else
                        file->FUN_00473660();

                    break;

                case 9:

                    if (recordC->FUN_00452420(4))
                        file->NextForm_00472150(true);

                    else
                        file->FUN_00473660();

                    break;

                default:
                    file->FUN_00473660();
                }
            }
            else
            {

                if (GetAt(pData7->label, reinterpret_cast<BGSReconstructFormsMap*&>(recordC)))
                    file->NextForm_00472150(true);

                else
                    file->FUN_00473660();
            }
        }
        else if (pData7->type == DAT_01187314)
        {

            idA = pData7->group;

            file->NextForm_00472150(true);
        }
        else if (pData7->type == DAT_011872b4)
        {

            if (subBlock)
            {

                formId4 = pData7->group;

                unsigned int key = formId4;

                if (world8 && world8->InterfaceManager_GetMagicPageNumber())
                {

                    RebuildCoordinates coords9;

                    ourMemset(&coords9, 0, 12);

                    unsigned int type3 = file->TESFile_GetTESChunk();

                    while (type3)
                    {

                        if (type3 == 0x434c4358)
                        {

                            file->FUN_00472890(&coords9, 12);

                            if (file->IsEndianConversionRequired())
                                coords9.TwoValues_Endian();

                            break;
                        }
                        type3 = file->FUN_004726f0() ? file->TESFile_GetTESChunk() : 0;
                    }

                    static_cast<ReconstructionFileOperations*>(file)->SkipCurrentForm();

                    key = PackShortPair((unsigned short)coords9.x, (unsigned short)coords9.y);
                }

                DAT_011c3f30 = 0;

                if (subBlock->FUN_00853130(key, &recordC))
                {

                    if (recordC->FUN_00452420(1))
                    {

                        DAT_011c3f2c->ConstructObject(file, false, 0, false);

                        file->NextForm_00472150(true);

                        RebuildForm* form = TESForm_GetFormByNumericID(formId4);

                        if (form)
                        {

                            RebuildResult cell(form, recordC->TESMain_GetThread());

                            reinterpret_cast<RebuildOutput*>(output)->BGSReconstructedForms_AddFormData(&cell);
                        }
                        else
                            SaveGameWarning("Cell with Form ID %08X was not able to be reconstructed", formId4);

                        ++restoredA;
                    }
                    else
                        file->NextForm_00472150(true);
                }
                else
                    file->NextForm_00472150(true);
            }
            else
            {

                recordC = world8->TESMain_GetThread();

                formId4 = pData7->group;

                DAT_011c3f30 = 0;

                file->NextForm_00472150(true);
            }
        }
        else if (pData7->type == DAT_011873c8)
        {

            unsigned int id = pData7->group;

            if (id == -1 || id == -2)
            {

                if (queued3.FUN_0044ddc0())
                {

                    result = *queued3.BSSimpleArray_GroupMemberData_1024_GetAt(next4++);

                    pending4 = true;
                }
                else
                    pData7->type = 0;
            }
            else
                file->NextForm_00472150(true);
        }
        else
        {

            RebuildResult item;

            unsigned int id = pData7->group;

            recordC->FUN_00841320(0x10000);

            if (recordC->Lookup(id, &item))
            {

                if (formId4 && (!DAT_011c3f30 || DAT_011c3f30->GetHavokWorldObjectCountInSceneGraph_0084e3a0() != formId4))
                    DAT_011c3f30 = TESForm_GetFormByNumericID(formId4);

                DAT_011c3f2c->ConstructObject(file, false, reinterpret_cast<TESForm*>(item.form), true);

                file->NextForm_00472150(true);

                if (!item.form)
                    item.form = TESForm_GetFormByNumericID(id);

                if (item.form)
                    reinterpret_cast<RebuildOutput*>(output)->BGSReconstructedForms_AddFormData(&item);

                else
                    SaveGameWarning("Form %08X with type %s was not able to be reconstructed", id,
                                 GetStringForByte(FindFormEnumIndex(pData7->type)));

                ++restoredA;
            }
            else
                file->NextForm_00472150(true);
        }

        if (groupEndA && groupEndA <= file->GetOffset())
        {

            if (queued3.FUN_0044ddc0() > next4)
                result = *queued3.BSSimpleArray_GroupMemberData_1024_GetAt(next4++);

            else
                pData7->type = 0;
        }

        if (result.ActorCause_IsValid())
        {

            file->SetOffset(reinterpret_cast<unsigned int>(result.form));

            unsigned int sizeXA = 0;

            unsigned int key17 = 0;

            if (pData7->group == 1)
            {

                key17 = pData7->label;

                sizeXA = pData7->sizeXA;

                file->NextForm_00472150(true);
            }
            else
                sizeXA = pData7->sizeXA;

            world8 = 0;
            block3 = 0;
            subBlock = 0;
            recordC = 0;
            formId4 = 0;
            idA = 0;

            groupEndA = file->GetOffset() + sizeXA;

            if (key17)
            {

                idA = key17;

                reinterpret_cast<RebuildMap*>(m_pExteriorMap)->FUN_00853130(idA, &world8);
            }
            else
            {

                recordC = result.recordC;

                formId4 = pData7->label;
            }

            result.ClearFields();

            if (idA && pData7->group == 9)
                file->FUN_00473660();
        }
    }

    DAT_011c3f30 = 0;
}

struct MapValue41f
{
    virtual ~MapValue41f();
};
// Iterates the map via FUN_004b9ba0 and FUN_006b7f20, deleting each MapValue41f data entry.
// @fnv 0x00841f00
BGSReconstructWorldSpacesMap::~BGSReconstructWorldSpacesMap()
{
    void* pos = reinterpret_cast<NiTPointerMap<unsigned int, MapValue41f*>*>(this)->GetFirstPos();
    while (pos)
    {
        unsigned int key = 0;
        MapValue41f* data = 0;
        reinterpret_cast<NiTPointerMap<unsigned int, MapValue41f*>*>(this)->GetNext(pos, key, data);
        delete data;
    }
}

struct ReconstructCellEntry : BGSReconstructFormsMap
{
    void AddFlags(int aiFlags);
    void SetData(void* apCell, unsigned int auiArg1, unsigned int auiArg2);
};


// Computes a key for apCell, creates a ReconstructCellEntry in the map if missing, then adds flags or stores apOther with auiArg1 and auiArg2.
// @fnv 0x00841460
void ReconstructCellsOperations::ProcessCell(TESObjectCELL* apCell, TESObjectCELL* apOther, unsigned int auiArg1,
                                              unsigned int auiArg2)
{
    unsigned int uiKey4 = 0;
    if (apCell->IsInterior())
        uiKey4 = apCell->GetFormID();
    else
        uiKey4 = TESWorldSpace::BuildCellKey(apCell->GetCellGridX(), apCell->GetCellGridY());

    ReconstructCellEntry* pEntry = 0;
    if (!GetAt(uiKey4, reinterpret_cast<BGSReconstructFormsMap*&>(pEntry)))
    {
        pEntry = (ReconstructCellEntry*)new BGSReconstructFormsMap;
        SetAt(uiKey4, pEntry);
    }

    if (apCell == apOther)
    {
        pEntry->AddFlags(1);
        pEntry->AddFlags(auiArg2);
    }
    else
    {
        pEntry->SetData(apOther, auiArg1, auiArg2);
    }
}

void SaveGameWarning(const char* apFormat, ...);
// TESObjectCELL does not yet declare the save-parent lookup at 0x0054DDD0.
// This method-only adapter uses the shared cell layout.
struct CellSaveParentLookup : TESObjectCELL
{
    TESObjectCELL* GetSaveParentCell();
};
bool __fastcall FUN_00425fd0(TESObjectCELL* apForm);
struct FileReferenceOperations : public BGSReconstructFormsInFileMap
{
    void ProcessCell(TESObjectCELL* apForm, int aiUnused, unsigned int auiArg1, unsigned int auiArg2);
};
struct ReconstructFilesCellOperations : public BGSReconstructFormsInAllFilesMap
{
    void BGSReconstructFormsInAllFilesMap_AddReference(TESObjectCELL* apRef, unsigned int auiArg1, unsigned int auiArg2);
};
// Adds a form reference to the per-file map, creating the map if needed, and increments iCount.
// @fnv 0x00843750
// src: EXE 0x00843750
void ReconstructFilesCellOperations::BGSReconstructFormsInAllFilesMap_AddReference(TESObjectCELL* apRef, unsigned int auiArg1, unsigned int auiArg2)
{
    if (!apRef)
        return;
    TESFile* pFile = 0;
    if (FUN_00425fd0(apRef))
        pFile = ((ReconstructFilesSourceLookup*)this)->BGSReconstructFormsInAllFilesMap_GetFileForFormID(apRef->GetSourceFiles(), auiArg1);
    else
        pFile = ((ReconstructFilesSourceLookup*)this)->BGSReconstructFormsInAllFilesMap_GetFileForFormID(static_cast<CellSaveParentLookup*>(apRef)->GetSaveParentCell()->GetSourceFiles(), auiArg1);
    if (!pFile)
    {
        SaveGameWarning("Cell %08X %s with no file passed to BGSReconstructFormsInAllFilesMap::AddReference()",
                     apRef->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), apRef->GetName());
        return;
    }
    BGSReconstructFormsInFileMap* pFileMap = 0;
    if (!GetAt(pFile, pFileMap))
    {
        pFileMap = new BGSReconstructFormsInFileMap;
        SetAt(pFile, pFileMap);
    }
    ((FileReferenceOperations*)pFileMap)->ProcessCell(apRef, 0, auiArg1, auiArg2);
    iCount++;
}

extern "C" void _Deallocate(void*);

struct ReconstructMapDeletingView : BGSReconstructFormsInAllFilesMap
{
    void* __thiscall FUN_00843440(unsigned int flags);
};

// Destroys the BGSReconstructFormsInAllFilesMap base and deallocates the object when flags has bit 0 set.
// @fnv 0x00843440
void* __thiscall ReconstructMapDeletingView::FUN_00843440(unsigned int flags)
{
    BGSReconstructFormsInAllFilesMap::~BGSReconstructFormsInAllFilesMap();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

