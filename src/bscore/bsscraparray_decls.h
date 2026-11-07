
#include "../../include/BSSimpleArray.h"
// bscore/bsscraparray_decls.h: declares MemoryManager
#ifndef BSSCRAPARRAY_DECLS_H
#define BSSCRAPARRAY_DECLS_H

#include "../../include/MemoryManager.h"

class NiAVObject;
class Animation;
class NavMeshInfo;

template <class T> class NiPointer;
MemoryManager* MemoryManager_Instance();


extern unsigned int DAT_01084074;
extern unsigned int DAT_0108c228;


// local form of BSScrapArray: 0x0087d1b0/0x009789e0 needs the BSSimpleArray base ctor and EH cleanup.
template <class T, unsigned int N> class ScrapArrayWithBase : public BSSimpleArray<T, N>
{
public:
    ScrapArrayWithBase();
    ScrapHeapBuffer* m_pAllocator;
};
#endif
