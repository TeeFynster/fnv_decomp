// fallout/ai/movement/virtualactorpathhandler.h: declares VirtualActorPathHandler
#ifndef FNV_VIRTUALACTORPATHHANDLER_H
#define FNV_VIRTUALACTORPATHHANDLER_H

#include "../../../../include/VirtualActorPathHandler.h"
extern "C" const NiPoint3 NiPoint3_ZERO;
// @fnv 0x009ea710
bool VirtualActorPathHandler::GetPathingDelta(NiPoint3* delta)
{
    *delta = NiPoint3_ZERO;
    return false;
}
#endif
