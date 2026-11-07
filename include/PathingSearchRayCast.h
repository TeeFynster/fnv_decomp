#pragma once

__if_not_exists(NiPoint3::x)
{
#include "NiPoint3.h"
}
__if_not_exists(PathingLocation::Location)
{
#include "PathingLocation.h"
}

class PathingRequest;
class PathingSolutionExt;
class RayCastItem;
class RayCastParam;
class SearchItem;
template <class T, unsigned int N> class BSSimpleArrayExt;

class PathingSearchRayCast
{
public:
    virtual ~PathingSearchRayCast();

    PathingLocation loc04;
    PathingLocation loc2C;
    PathingRequest* pRequest;
    unsigned int unk58;
    NiPoint3 pt5C;
    NiPoint3 pt68;
    float f74;
    void* unk78;
    unsigned int unk7C;
    unsigned int unk80;
    void* unk84;
    int unk88;
    float f8C;
    float f90;

    PathingSearchRayCast();
    bool FUN_006c4000();
    bool SetupFromCellWorld();
    bool UpdateAndCheck(const NiPoint3& p1, const NiPoint3& p2);
    bool CheckPathClear(const NiPoint3& p1, const NiPoint3& p2);
    void ComputeBounds(BSSimpleArrayExt<RayCastItem, 1024>& arr);
    void PathingSearchRayCast_CleanUpRayCasts();
    unsigned int ProcessRayCast(RayCastParam* param1, PathingSolutionExt* param2);
    void ProcessRayCast(SearchItem*, SearchItem*);
    int FUN_004fd3e0();
    void __thiscall FUN_006e62b0();
    void* __thiscall Destroy(unsigned int flags);
};
