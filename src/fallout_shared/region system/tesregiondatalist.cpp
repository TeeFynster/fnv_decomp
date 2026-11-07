#include "../../../include/TESRegionData.h"
// fallout_shared/region system/tesregiondatalist.cpp: RegionDataList (4 functions)

class TESRegionData;

#include "../../../include/BSSimpleList.h"


class RegionDataList : public BSSimpleList<TESRegionData*>
{
  protected:
    bool m_bDataFlag;

  public:
    void Clear();
};

// @fnv 0x004f3400
void RegionDataList::Clear()
{
    TESRegionData* pkRegionData = 0;
    while (ItemsInList() != 0)
    {
        pkRegionData = GetItem();
        RemoveHead();
        if (m_bDataFlag)
            delete pkRegionData;
    }
}

struct SeqObj
{
    BSSimpleList<TESRegionData*>* GetName();
};
struct NodeTmp
{
    TESRegionData*& _ref_006815c0();
    BSSimpleList<TESRegionData*>* _ref_00726070();
};
void __cdecl TESRegionDataImposter_SetImposterVisible(TESRegionData*, unsigned char, unsigned char);
struct Dummy
{
    void TESRegionDataImposter_SetImpostersVisible(unsigned char, unsigned char);
};
// Walks the region data list from GetName and calls FUN_004f24e0 on each non-null entry with a1 and a2.
// @fnv 0x004f2480
// src: COMMUNITY 0x004f2480
void Dummy::TESRegionDataImposter_SetImpostersVisible(unsigned char aucArg1, unsigned char aucArg2)
{
    BSSimpleList<TESRegionData*>* pcurrent = ((SeqObj*)this)->GetName();
    while (pcurrent)
    {
        if (((NodeTmp*)pcurrent)->_ref_006815c0())
            TESRegionDataImposter_SetImposterVisible(((NodeTmp*)pcurrent)->_ref_006815c0(), aucArg1, aucArg2);
        pcurrent = ((NodeTmp*)pcurrent)->_ref_00726070();
    }
}

struct ListX
{
    ~ListX();
};
struct FUN_004f3360 : ListX
{
    ~FUN_004f3360();
};
// @fnv 0x004f3360
FUN_004f3360::~FUN_004f3360()
{
    ((RegionDataList*)(void*)this)->Clear();
}

struct ProbeBase
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual unsigned int v10();
};

class FUN_004f33c0_cls
{
  public:
    int TESRegionDataList_Find(unsigned int aValue);
    void FUN_005ae3d0(ProbeBase** appProbe);

    bool TESRegionDataList_Add(ProbeBase* apProbe);
};

// @fnv 0x004f33c0
// src: COMMUNITY 0x004f33c0
bool FUN_004f33c0_cls::TESRegionDataList_Add(ProbeBase* apProbe)
{
    if (apProbe == 0 || TESRegionDataList_Find(apProbe->v10()))
    {
        return false;
    }
    FUN_005ae3d0(&apProbe);
    return true;
}
