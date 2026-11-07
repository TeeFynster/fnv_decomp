#pragma once

#include "BSExtraData.h"

// RTTI vftable 0x01016010 (ctor 0x004385c0): BSSimpleArray<CombatTimeStamp,1024>.
// CombatTargetTimestamp is the shared four-byte timestamp representation.
#include "BSSimpleArray.h"
#include "CombatTargetTimestamp.h"

class ExtraFriendHits : public BSExtraData
{
public:
    ExtraFriendHits();
    virtual ~ExtraFriendHits();

    void Reset();
    int GetFriendHitSlotCount();
    void Destroy();
    void* ScalarDeletingDestructor(unsigned int flags);
    void ExtraFriendHits_AddHit();

    BSSimpleArray<CombatTargetTimestamp> kHits;
};
