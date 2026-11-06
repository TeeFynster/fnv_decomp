#pragma once

#include "TESObjectARMO.h"

class TESObjectARMA : public TESObjectARMO
{
public:
    TESObjectARMA();
    virtual ~TESObjectARMA();
    virtual void InitItem();

    bool Load(TESFile* file);
    void ResetFormData();
};
