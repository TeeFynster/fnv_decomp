#pragma once

#include "NiRefObject.h"
#include "BSOcclusionPlane.h"

template <class T> class NiTPointerList;
class P2Obj;

class BSPortalGraph : public NiRefObject
{
public:
    NiTPointerList<BSOcclusionPlane*>& GetOccluderList();
    void FUN_00c5b1c0(P2Obj* p2);
    void FUN_00c5b370(P2Obj* p2);
};
