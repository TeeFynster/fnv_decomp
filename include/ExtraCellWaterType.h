#pragma once

#include "BSExtraData.h"
#include "TESWaterForm.h"

class ExtraCellWaterType : public BSExtraData
{
public:
    ExtraCellWaterType();

    TESWaterForm* m_pWaterForm;
};
