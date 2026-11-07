#include "../../../include/TESRegionList.h"

// src/fallout_shared/region system/tesregionlist.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/region system/tesregionlist.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct TESRegion;
struct G2
{
    void AddHead(TESRegion* const&);
};
struct LH
{
    bool IsInList(TESRegion* const&) const;
};


// Returns false if apRegion is null; otherwise adds it to the list at offset 4 if not already present and returns true.
// @fnv 0x004f6600
bool TESRegionList::AddRegion(TESRegion* apRegion)
{
    if (!apRegion)
        return false;
    if (!(((LH*)((char*)this + 4))->IsInList(apRegion)))
        ((G2*)((char*)this + 4))->AddHead(apRegion);
    return true;
}

void __cdecl operator delete(void*);
struct FUN_004f6480_shell
{
    void FUN_004f64b0();
    void* DestroyIfFlagged(unsigned int flags);
};
// Calls FUN_004f64b0, then deletes this object if bit 0 of flags is set, and returns this.
// @fnv 0x004f6480
void* FUN_004f6480_shell::DestroyIfFlagged(unsigned int flags)
{
    FUN_004f64b0();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct IntList
{
    void* first;
    void* last;
    ~IntList();
};
struct Cache
{
    virtual ~Cache();
};
struct CachePair
{
    Cache* first;
    Cache* second;
};
extern CachePair caches[9];
extern unsigned int instanceCount;
struct FUN_004f64b0
{
    virtual ~FUN_004f64b0();
    IntList regions;
    bool ownsCache;
    void TESRegionList_Clear();
};
// Calls FUN_004f6640, then if ownsCache and the instance count drops to zero, deletes both caches in each of the 9 slots.
// @fnv 0x004f64b0
FUN_004f64b0::~FUN_004f64b0()
{
    TESRegionList_Clear();
    if (ownsCache && --instanceCount == 0)
    {
        Cache* second = 0;
        Cache* first = 0;
        for (unsigned int uiIndex = 0; uiIndex < 9; ++uiIndex)
        {
            first = caches[uiIndex].first;
            if (first)
            {
                caches[uiIndex].first = 0;
                delete first;
            }
            second = caches[uiIndex].second;
            if (second)
            {
                caches[uiIndex].second = 0;
                delete second;
            }
        }
    }
}

extern float DAT_01017d00;
extern bool __cdecl FloatEQ(float a, float b, float c);
struct PointObject;
struct RegionNode
{
    bool j_8TESRegionPoint_QEBA_NAEBV0_Z(PointObject* obj);
};
struct PointObject
{
    int unk00, unk04;
    float position;
    bool IsInRegion(RegionNode* region, float value);
};
// @fnv 0x004f7620
bool PointObject::IsInRegion(RegionNode* region, float value)
{
    if (region == 0)
        return false;
    if (FloatEQ(value, position, DAT_01017d00))
    {
        if (region->j_8TESRegionPoint_QEBA_NAEBV0_Z(this))
            return true;
    }
    return false;
}
