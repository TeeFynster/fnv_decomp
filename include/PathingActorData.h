#pragma once

#include "InventoryChanges.h"

class ActorData;
class TESActorBase;

class PathingActorData
{
public:
    TESActorBase* m_pActorBaseFormItem;
    InventoryChanges* m_pInventoryChangesValue;
    bool m_bCanIgnoreLocks;
    unsigned char layoutPadding9[3];

    PathingActorData();
    PathingActorData& operator=(const PathingActorData& other);
    PathingActorData& CopyFrom(const ActorData& other);
};
