#pragma once

#include "BSExtraData.h"
#include "NiAVObject.h"

class ActorCause;

class ExtraActorCause : public BSExtraData
{
public:
    virtual ~ExtraActorCause();

    ExtraActorCause();
    void FUN_0042cb30();
    void SetActorCause(int value);
    void* FUN_0042cb00(unsigned int flags);

    NiPointer<ActorCause> actorCause;
};
