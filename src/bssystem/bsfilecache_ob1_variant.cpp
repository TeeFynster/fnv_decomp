
// src/bssystem/bsfilecache_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/bssystem/bsfilecache.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "bsfilecache.h"

BSFileCache* FUN_00aff100();

inline bool IsCacheFinished(BSFileCache* m_pAabbCache)
{
    return m_pAabbCache->m_eCacheState == FILE_CACHING_FINISHED;
}

inline bool IsCachePaused(BSFileCache* m_pAabbCache)
{
    return m_pAabbCache->m_eCacheState == FILE_CACHING_PAUSED ||
           m_pAabbCache->m_eCacheState == FILE_CACHING_FORCE_PAUSED;
}

struct Cls00b01220
{
    unsigned char unk00;
    Cls00b01220* __thiscall AutoPauseFileCaching_AutoPauseFileCaching(int unused);
};

// @fnv 0x00b01220
// src: COMMUNITY 0x00b01220
Cls00b01220* __thiscall Cls00b01220::AutoPauseFileCaching_AutoPauseFileCaching(int unused)
{
    BSFileCache* pCache1 = FUN_00aff100();
    if (!IsCacheFinished(pCache1))
    {
        BSFileCache* pCache2 = FUN_00aff100();
        this->unk00 = IsCachePaused(pCache2);

        BSFileCache* pCache3 = FUN_00aff100();
        if (pCache3->m_eCacheState == FILE_CACHING_IN_PROGRESS)
        {
            pCache3->m_eCacheState = FILE_CACHING_PAUSED;
        }
    }

    return this;
}

BSFileCache* FUN_00aff100();
class FUN_00b012a0_cls
{
  public:
    unsigned char m_00;
    void UpdateFields_00b012a0();
};
// @fnv 0x00b012a0
// src: GUESS 0x00b012a0 (confidence: low)
void FUN_00b012a0_cls::UpdateFields_00b012a0()
{
    BSFileCache* cache = FUN_00aff100();
    if (!IsCacheFinished(cache) && m_00 == 0)
    {
        BSFileCache* cache2 = FUN_00aff100();
        if (cache2->m_eCacheState == FILE_CACHING_PAUSED)
            cache2->m_eCacheState = FILE_CACHING_IN_PROGRESS;
    }
}
