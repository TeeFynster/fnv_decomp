// Inline ActorPathHandler::CompleteNoPathUpdate body for the magic effect-item-list unit
// (returns ActorPathHandler::PATH_HANDLER_RESULT_DONE).
#ifndef FNV_EFFECTITEMLIST_H
#define FNV_EFFECTITEMLIST_H

#include "../../../include/ActorPathHandler.h"

// @fnv 0x009dfdf0
inline ActorPathHandler::PATH_HANDLER_RESULT ActorPathHandler::CompleteNoPathUpdate(float fSeconds)
{
    return PATH_HANDLER_RESULT_DONE;
}

#endif
