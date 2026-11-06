#pragma once

#include "BSExtraData.h"

class ExtraSavedAnimation : public BSExtraData
{
public:
    ExtraSavedAnimation();
    virtual ~ExtraSavedAnimation();

    char* m_pString;
};
