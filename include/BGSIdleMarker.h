#pragma once

#include "TESBoundObject.h"
#include "BGSIdleCollection.h"

class BGSIdleMarker : public TESBoundObject, public BGSIdleCollection
{
public:
    BGSIdleMarker();
    virtual ~BGSIdleMarker();

    virtual void InitItem(void);
    bool Load(TESFile* file);
};
