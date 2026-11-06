#pragma once

#include "BSExtraData.h"

class TESObjectCELL;

class ExtraPersistentCell : public BSExtraData
{
public:
    virtual ~ExtraPersistentCell();

    ExtraPersistentCell(TESObjectCELL* aCell);

    TESObjectCELL* cell;
};
