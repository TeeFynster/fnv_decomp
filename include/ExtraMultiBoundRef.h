#pragma once

#include "BSExtraData.h"

class TESObjectREFR;

class ExtraMultiBoundRef : public BSExtraData
{
public:
    ExtraMultiBoundRef();

    bool Compare(BSExtraData* apCompare) override;
    bool Compare_00435540(BSExtraData* apCompare);

    TESObjectREFR* m_pReference;
};
