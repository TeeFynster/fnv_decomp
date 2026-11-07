// fallout/misc/saveload/bgssaveloadchangesmap.cpp: BGSSaveLoadChangesMap, CombatTargetMap, FormChangeRecord, DelStandIn (17 functions)

#include "../../../../include/CombatTargetMap.h"
#include "bgssaveloadchangesmap_decls.h"
#include <new>

// @fnv 0x00845550
// the base map constructor 0x00845b30 with 0x13af buckets, then the vftable 0x0107ed68
BGSSaveLoadChangesMap::BGSSaveLoadChangesMap() : NiTPointerMap<unsigned int, FormChangeRecord*>(0x13AF)
{
}

// Looks up the actor in the map and returns its array of combat targets, or null if not present.
// @fnv 0x009a4250
BSSimpleArray<Actor*, 1024>* CombatTargetMap::GetTargetsForActor(Actor* actor)
{
    BSSimpleArray<Actor*, 1024>* array = 0;
    if (((NiTPointerMap<unsigned int, BSSimpleArray<Actor*, 1024>*>*)this)->GetAt((unsigned int)actor, array))
        return array;
    return 0;
}

// @fnv 0x00845720
bool BGSSaveLoadChangesMap::ContainsChangeFlags(unsigned int formID, FormChangeMask flags)
{
    FormChangeRecord* changes = FUN_009a4250(formID);
    if (changes)
        return ((FormChangeMask*)changes)->ContainsAnyFlags(flags.Modelloader_GetReferencedThis());
    return false;
}

// @fnv 0x008457b0
void BGSSaveLoadChangesMap::AddFormChangeFlags(unsigned int formID, FormChangeMask flags)
{
    FormChangeRecord* changes = FUN_009a4250(formID);
    if (!changes)
    {
        changes = new FormChangeRecord();
        SetAt(formID, changes);
    }
    else if (((FormChangeMask*)((char*)changes + 4))->Modelloader_GetReferencedThis())
    {
        return;
    }

    changes->FUN_00841100((char*)flags.Modelloader_GetReferencedThis());
}

// @fnv 0x00845880
FormChangeRecord::FormChangeRecord()
{}

// Looks up the change record for formID, creating and inserting a new one if absent, then sets its quantity from flags.
// @fnv 0x008458b0
void BGSSaveLoadChangesMap::ApplyFormQuantityChange(unsigned int formID, FormChangeMask flags)
{
    FormChangeRecord* changes = FUN_009a4250(formID);
    if (!changes)
    {
        changes = new FormChangeRecord();
        SetAt(formID, changes);
    }
    ((QuantityData*)changes)->SetQuantity(flags.Modelloader_GetReferencedThis());
}

// Looks up the change record for formID; if found, deletes it, removes it from the map, and returns true, otherwise returns false.
// @fnv 0x00845a20
bool BGSSaveLoadChangesMap::HasFormChanges(unsigned int formID)
{
    FormChangeRecord* changes = FUN_009a4250(formID);
    if (changes)
    {
        delete changes;
        RemoveAt(formID);
        return true;
    }
    return false;
}

// @fnv 0x00845a80
bool BGSSaveLoadChangesMap::ClearChangeFlags(unsigned int formID, FormChangeMask flags)
{
    FormChangeRecord* changes = FUN_009a4250(formID);
    if (changes && !changes->flags.Modelloader_GetReferencedThis())
    {
        changes->FUN_00562210(flags.Modelloader_GetReferencedThis());
        if (((FormChangeMask*)changes)->Modelloader_GetReferencedThis())
            return false;
        if (((TESDataHandlerAccess*)g_dataHandler)->FormIDExists(formID))
            return false;
        delete changes;
        RemoveAt(formID);
    }
    return true;
}

struct CF845
{
    int f;
    CF845(int);
};
struct Arr845
{
    CF845 first;
};
struct Ctm845
{
    Arr845* GetTargetsForActor(void*);
    CF845 GetFirstEntry(void* actor);
};
// @fnv 0x008456e0
CF845 Ctm845::GetFirstEntry(void* actor)
{
    Arr845* a = GetTargetsForActor(actor);
    if (a)
        return a->first;
    return CF845(0);
}

extern int DAT_01031fac;

struct FUN_00845b30_arg
{
    unsigned int val;
};

void __fastcall FUN_005890c0(int* self, FUN_00845b30_arg a);

// Calls FUN_005890c0 on self, then stores the address of DAT_01031fac into *self and returns self.
// @fnv 0x00845b30
// src: EXE 0x00845b30
int* __fastcall NiTPointerMap_unsigned_int_BGSFormChanges_NiTPointerMap(int* self, FUN_00845b30_arg aArg)
{
    FUN_005890c0(self, aArg);
    *self = (int)&DAT_01031fac;
    return self;
}

void __fastcall DeleteAllEntries(void*);

struct FUN_009a5df0
{
    virtual void dummy();
    ~FUN_009a5df0();
};

struct FUN_00845c00 : FUN_009a5df0
{
    ~FUN_00845c00();
};

// Destructor that calls DeleteAllEntries on this object.
// @fnv 0x00845c00
FUN_00845c00::~FUN_00845c00()
{
    DeleteAllEntries(this);
}

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* DestroyAndFree(unsigned int flags);
};
// Runs the destructor, frees this when flags has bit 0 set, and returns this.
// @fnv 0x00845580
void* DelStandIn::DestroyAndFree(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

struct FUN_00845610_shell : public BGSSaveLoadChangesMap
{
    void DeleteAllChanges();
};

struct NavMeshVertexMap
{
    void* GetFirstPos();
};
namespace p07 {
// NiTPointerMapView: unit-local view (declares only what p07 calls), not the shared NiTPointerMap; renamed so no local type keeps the shared name
template <class K, class V> struct NiTPointerMapView
{
    void GetNext(void*& pos, K& key, V& val);
    void RemoveAll();
};
}
// Iterates the map's entries, deletes each stored change object, then clears the map.
// @fnv 0x00845610
void FUN_00845610_shell::DeleteAllChanges()
{
    void* it = ((NavMeshVertexMap*)this)->GetFirstPos();
    while (it)
    {
        FormChangeRecord* pchanges = 0;
        unsigned int iformID = 0;
        ((p07::NiTPointerMapView<unsigned int, void*>*)this)->GetNext(it, iformID, (void*&)pchanges);
        delete pchanges;
    }
    ((p07::NiTPointerMapView<unsigned int, unsigned int>*)this)->RemoveAll();
}

namespace fnv_00845760 {
struct CF845
{
    CF845(int);
    int data;
};
struct Fake845
{
    int unk;
    CF845 buf;
};
struct S845
{
    CF845 BGSSaveLoadChangesMap_GetChangeBuffer(unsigned int aiFormID);
};
// @fnv 0x00845760
// src: COMMUNITY 0x00845760
CF845 S845::BGSSaveLoadChangesMap_GetChangeBuffer(unsigned int aiFormID)
{
    FormChangeRecord* pEntry;
    pEntry = (FormChangeRecord*)((CombatTargetMap*)this)->GetTargetsForActor((Actor*)aiFormID);
    if (pEntry)
        return ((Fake845*)pEntry)->buf;
    return 0;
}
}  // namespace fnv_00845760

int __fastcall Modelloader_GetReferencedThis(int*);

// Looks up or creates a per-form entry in the map, sets its quantity from FUN_00559450(quantity) and stores extra at offset 4.
// @fnv 0x00845960
void BGSSaveLoadChangesMap::SetCombatTargetQuantity(unsigned int formID, unsigned int quantity, unsigned int extra)
{
    BSSimpleArray<Actor*, 1024>* array = ((CombatTargetMap*)this)->GetTargetsForActor((Actor*)formID);
    if (!array)
    {
        array = (BSSimpleArray<Actor*, 1024>*)new FormChangeRecord;
        ((BGSSaveLoadChangesMap*)this)->SetAt(formID, (FormChangeRecord*)array);
    }
    ((QuantityData*)array)->SetQuantity(Modelloader_GetReferencedThis((int*)&quantity));
    ((unsigned int*)((char*)array + 4))[0] = extra;
}

extern int DAT_0107eda8;
void* __cdecl _NiMalloc(unsigned int size);
void* __cdecl memset(void* dest, int c, unsigned int count);

struct FUN_00845b90_shell
{
    int* vtable_;
    int count_;
    void* data_;
    int tail_;
    FUN_00845b90_shell* InitArray(int size);
};

// Sets the vtable, stores size in count_, allocates count_*4 bytes for data_, zeroes them, and returns this.
// @fnv 0x00845b90
FUN_00845b90_shell* FUN_00845b90_shell::InitArray(int aiCount)
{
    vtable_ = &DAT_0107eda8;
    count_ = aiCount;
    tail_ = 0;
    unsigned int bytes = count_ * 4;
    data_ = _NiMalloc(bytes);
    memset(data_, 0, count_ * 4);
    return this;
}

// the 16-byte base of the destructor shell below (unit-local; was in the local BGSSaveLoadChangesMap copy)
class BGSSaveLoadChangesMapBase
{
  public:
    unsigned int layout[4];
};
struct FUN_00845b60 : BGSSaveLoadChangesMapBase
{
    virtual ~FUN_00845b60();
};
// @fnv 0x00845b60
FUN_00845b60::~FUN_00845b60()
{}
