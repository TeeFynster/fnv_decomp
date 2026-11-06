// bscore/memorypool_decls.h: declares MemoryPool__FreePoolBlock, MemoryPool
#ifndef FNV_MEMORYPOOL_DECLS_H
#define FNV_MEMORYPOOL_DECLS_H

#include "../../include/RecursiveSpinLock.h"
#include "../../include/MemoryPool.h"

struct MemoryPool__FreePoolBlock
{
    MemoryPool__FreePoolBlock* m_pPreviousBlock;
    MemoryPool__FreePoolBlock* pNext;
};


#endif
