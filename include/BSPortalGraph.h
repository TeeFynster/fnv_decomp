#pragma once

#include "NiRefObject.h"
#include "BSOcclusionPlane.h"

template <class T> class NiTPointerList;
class P2Obj;

class BSPortalGraph : public NiRefObject
{
public:
    NiTPointerList<BSOcclusionPlane*>& GetOccluderList();
    void BSPortalGraph_AttachAlwaysRenderChild(P2Obj* p2);
    void BSPortalGraph_DetachAlwaysRenderChild(P2Obj* p2);
};
