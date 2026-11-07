// gamebryo2.2/corelibs/nimain/nitmapbase_h_unit.cpp: SharedAccumulatorState (1 function)

#include "nitmapbase.inl"

// 1 Nov: the included file leaves optimization off (#pragma optimize("", off) never closed); functions added below build
// with the unit's own flags (/O2). Nothing of this unit's own follows the include, so no accepted function is affected.
#pragma optimize("", on)


// Stands in for the NiTPointerMap<NiObject *,bool> member (layout_support.h, included first, keeps a non-polymorphic
// NiTPointerMap of its own); the calls go to NiTMapBase<NiTPointerAllocator<unsigned int>,NiObject *,bool>.
struct FUN_00b63b10_ObjectMap : NiTMapBase<NiTPointerAllocator<unsigned int>, NiObject*, bool>
{
    virtual NiTMapItem<NiObject*, bool>* NewItem();
    virtual void DeleteItem(NiTMapItem<NiObject*, bool>* pkItem);
};

struct SharedAccumulatorState
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    FUN_00b63b10_ObjectMap sharedObjects;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int sharedLock;
    bool BSShaderAccumulator_AddShared(NiObject* object);
};

// Locks sharedLock, checks if object is in sharedObjects, adds it if missing, and returns true when it was newly added.
// @fnv 0x00b63b10
// src: XBOX_PDB 0x00b63b10
bool SharedAccumulatorState::BSShaderAccumulator_AddShared(NiObject* object)
{
    bool value = false;
    EnterCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&sharedLock));
    const bool bFound = sharedObjects.GetAt(object, value);
    if (!bFound)
        sharedObjects.SetAt(object, true);
    LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&sharedLock));
    return !bFound;
}
