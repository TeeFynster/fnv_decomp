// gamebryo2.2/corelibs/niconsolerenderer/nid3drenderstategroup_decls.h: declares D3DRenderStateGroup
#ifndef NID3DRENDERSTATEGROUP_DECLS_H
#define NID3DRENDERSTATEGROUP_DECLS_H

class D3DRenderStateGroup;
#include "../../../../include/NiTNewInterface.h"
template <class T, class A> class ObjectPool;
extern ObjectPool<D3DRenderStateGroup, NiTNewInterface<D3DRenderStateGroup> >* DAT_0126f718;
struct D3DRenderStateGroup
{
    bool m_bHasBeenApplied;
    static D3DRenderStateGroup* GetCurrentRenderStateGroup();
};
template <class T, class A> class ObjectPool
{
  public:
    T** objects;
    unsigned int allocated;
    unsigned int used;
    void* containers;
    unsigned int currentSize;
    unsigned int initialSize;
    void AddPoolBlock(unsigned int);
    T* Get()
    {
        if (!used)
        {
            AddPoolBlock(currentSize);
            currentSize *= 2;
        }
        T* result = objects[0];
        objects[0] = objects[--used];
        return result;
    }
};
#endif
