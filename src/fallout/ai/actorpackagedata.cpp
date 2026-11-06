
// Fallout: New Vegas - original source reconstruction.
// Original: platforms/common/code/fallout/ai/actorpackagedata.cpp
//
// ActorPackageData::CreatePackageData allocates the runtime package-data
// object matching a package type. Each case news one derived ActorPackageData
// class through the global allocator; unknown types return NULL.
#include "actorpackagedata.h"
#include "../../../include/ActorPackageData.h"
#include "../../../include/EscortActorPackageData.h"
#include "../../../include/GuardActorPackageData.h"
#include "../../../include/PatrolActorPackageData.h"
#include "../../../include/SandBoxActorPackageData.h"
#include "../../../include/UseWeaponActorPackageData.h"

#ifndef NULL
#define NULL 0
#endif

// Allocates and returns the ActorPackageData subclass matching the given package type, or NULL for unsupported types.
// @fnv 0x008c6ca0
ActorPackageData* ActorPackageData::CreatePackageData(PTYPE aeType)
{
    ActorPackageData* pResult = NULL;
    switch (aeType)
    {
    case PTYPE_ESCORT:
        pResult = new EscortActorPackageData();
        break;
    case PTYPE_SANDBOX:
        pResult = new SandBoxActorPackageData();
        break;
    case PTYPE_PATROL:
        pResult = new PatrolActorPackageData();
        break;
    case PTYPE_GUARD:
        pResult = new GuardActorPackageData();
        break;
    case PTYPE_USEWEAPON:
        pResult = new UseWeaponActorPackageData();
        break;
    }
    return pResult;
}
