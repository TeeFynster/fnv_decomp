#pragma once

#include "TESBoundObject.h"
#include "TESModelTextureSwap.h"

class BGSStaticCollection : public TESBoundObject, public TESModelTextureSwap
{
public:
    BGSStaticCollection();

    bool Load(TESFile* file);
    virtual bool LoadForm(TESFile* file);
    virtual void InitItem();
};
