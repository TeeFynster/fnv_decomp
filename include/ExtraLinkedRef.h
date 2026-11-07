#pragma once

#include "BSExtraData.h"

class TESObjectREFR;

class ExtraLinkedRef : public BSExtraData
{
public:
    virtual ~ExtraLinkedRef();
    virtual bool Compare(BSExtraData* apCompare);

    bool __thiscall Compare_00433670(BSExtraData* apCompare);

    TESObjectREFR* m_pLinkedReference;
};
