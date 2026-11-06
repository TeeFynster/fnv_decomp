#pragma once

#include "BSExtraData.h"

class TESForm;

class ExtraStartingWorldOrCell : public BSExtraData
{
public:
    virtual ~ExtraStartingWorldOrCell();
    ExtraStartingWorldOrCell();

    TESForm* m_pStartingWorldOrCell;
};
