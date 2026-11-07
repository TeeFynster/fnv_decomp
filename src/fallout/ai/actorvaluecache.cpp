// fallout/ai/actorvaluecache.cpp: ActorValueStore (5 functions)

#include "actorvaluecache_decls.h"

// @fnv 0x008c6e90
ActorValueStore::ActorValueStore()
{
    ResetCacheValues();
}

// @fnv 0x008c6f40
void ActorValueStore::InvalidateValue(ActorValue::Index avIndex)
{
    if (avIndex >= 0 && avIndex < ActorValue::ActorValue__Index_ACTOR_VALUE_COUNT)
    {
        Cache[avIndex].m_bIsDirty = true;
        InvalidateDependentValues(avIndex);
    }
}

// @fnv 0x008c6f70
void ActorValueStore::InvalidateDependentValues(ActorValue::Index avIndex)
{
    int numDependents = 0;
    ActorValue::Index* arrayDependents = ActorValue::GetDependentActorValueIndices(avIndex, numDependents);
    if (arrayDependents != 0 && numDependents != 0)
    {
        for (int i = 0; i < numDependents; ++i)
        {
            if (arrayDependents[i] >= 0 && arrayDependents[i] < ActorValue::ActorValue__Index_ACTOR_VALUE_COUNT)
                Cache[arrayDependents[i]].m_bIsDirty = true;
        }
    }
}

// @fnv 0x008c6eb0
void ActorValueStore::ResetCacheValues()
{
    for (int i = 0; i < ActorValue::ActorValue__Index_ACTOR_VALUE_COUNT; ++i)
    {
        ActorValueCacheEntry& info = Cache[i];
        info.fValue = 0.0f;
        info.m_bIsDirty = true;
    }
}

// Stores value into the cached actor-value info for avIndex and clears its flag when avIndex is within the actor-value range.
// @fnv 0x008c6f00
// src: COMMUNITY 0x008c6f00
void ActorValueStore::CachedActorValues_SetActorValue(ActorValue::Index avIndex, float value)
{
    if (avIndex >= 0 && avIndex < ActorValue::ActorValue__Index_ACTOR_VALUE_COUNT)
    {
        ActorValueCacheEntry& info = Cache[avIndex];
        info.fValue = value;
        info.m_bIsDirty = false;
    }
}
