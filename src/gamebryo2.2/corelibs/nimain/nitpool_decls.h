// gamebryo2.2/corelibs/nimain/nitpool_decls.h: declares D3DRenderStateGroup

#include "layout_support.h"
// NiStreamLinkIDSet_nitpool_decls: local type (was include/NiStreamLinkIDSet.h, which had no evidence of one real class); its methods are 0x00a311e0 NiTSet<NiScreenGeometryData::ScreenElement *,NiTMallocInterface<NiScreenGeometryData::ScreenElement *> >::Add, 0x00a543b0 NiTSet::Ptr::Add
class Item;
class NiGeomMorpherUpdateTask;
class D3DRenderStateGroup;

class NiStreamLinkIDSet_nitpool_decls
{
public:
    void* m_kPointA;
    unsigned int m_uiItemCount;
    unsigned int m_pRayCursor;

    void Realloc(unsigned int);
    void ProcessEntries_00a56e60(unsigned int ItemUpdateArray);
    unsigned int Find(Item* item);
    int Find(unsigned int value);
    void Add(Item* item);
    void Add(NiGeomMorpherUpdateTask* pkTask);
    void Add(D3DRenderStateGroup* p);
    void AddUnique(Item* item);
};
#include "MemoryManager.h"
extern MemoryManager g_memoryManager;
struct D3DRenderStateGroup
{
    unsigned char data[20];
};
D3DRenderStateGroup* Object_CreateElementArray(unsigned int);
inline void NiStreamLinkIDSet_nitpool_decls::Add(D3DRenderStateGroup* p)
{
    if (m_pRayCursor == m_uiItemCount)
        Realloc(m_uiItemCount > 0 ? m_uiItemCount * 2 : 1);
    static_cast<D3DRenderStateGroup**>(m_kPointA)[m_pRayCursor++] = p;
}
template <class T, class A> class ObjectPoolBlock
{
  public:
    T* objects;
    unsigned int count;
    ObjectPoolBlock* next;
    static void* operator new(unsigned int n) throw()
    {
        return g_memoryManager.Allocate(n);
    }
    ObjectPoolBlock(unsigned int n) throw() : count(n), next(0)
    {
        if (n > 0)
            objects = Object_CreateElementArray(n);
        else
            objects = 0;
    }
    T* GetAt(unsigned int i)
    {
        if (i >= count)
            return 0;
        return objects + i;
    }
};
template <class T, class A> class ObjectPool
{
  public:
    NiStreamLinkIDSet_nitpool_decls freeObjects;
    ObjectPoolBlock<T, A>* containers;
    unsigned int currentSize, initialSize;
    void AddPoolBlock(unsigned int n);
};
