#pragma once

#include "NiTMap.h"

class Actor;
class CombatTargetData;
template <class T, unsigned int N> class BSSimpleArray;

// RTTI: CombatTargetMap : NiTMap<Actor *,CombatTargetData *>, vftable 0x0108e1e8 (only the destructor is its own).
class CombatTargetMap : public NiTMap<Actor*, CombatTargetData*>
{
public:
    BSSimpleArray<Actor*, 1024>* GetTargetsForActor(Actor* actor);
    void ResetTargetMap();
};
