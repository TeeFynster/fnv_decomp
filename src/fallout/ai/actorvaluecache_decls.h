// Own header for fallout/ai/actorvaluecache.cpp.
// ActorValueCacheEntry / ActorValueStore layouts copied verbatim from the task's
// canonical and must not be #included. Method declarations added; they do not
// affect layout. ActorValue::Index comes from layout_support.h.
#ifndef FNV_SRC_FALLOUT_AI_ACTORVALUECACHE_H
#define FNV_SRC_FALLOUT_AI_ACTORVALUECACHE_H

#include "layout_support.h"
class ActorValueStore;
class ActorValueCacheEntry;
#pragma pack(push, 4)
class ActorValueCacheEntry
{
  public:
    bool m_bIsDirty;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    float fValue;  // +0x4, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ActorValueCacheEntry) == 8);
FNV_STATIC_ASSERT(offsetof(ActorValueCacheEntry, m_bIsDirty) == 0);
FNV_STATIC_ASSERT(offsetof(ActorValueCacheEntry, fValue) == 4);
#pragma pack(push, 4)
class ActorValueStore
{
  public:
    ActorValueStore();
    void ResetCacheValues();
    void CachedActorValues_SetActorValue(ActorValue::Index avIndex, float value);
    void InvalidateValue(ActorValue::Index avIndex);

  private:
    void InvalidateDependentValues(ActorValue::Index avIndex);

  public:
    ActorValueCacheEntry Cache[77];  // +0x0, 616 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ActorValueStore) == 616);
FNV_STATIC_ASSERT(offsetof(ActorValueStore, Cache) == 0);
namespace ActorValue {
ActorValue::Index* GetDependentActorValueIndices(ActorValue::Index avIndex, int& count);
}
#endif
