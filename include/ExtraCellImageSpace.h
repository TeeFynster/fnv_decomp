#pragma once

#include "BSExtraData.h"

class ExtraCellImageSpace : public BSExtraData
{
public:
    virtual ~ExtraCellImageSpace();
    bool Compare(BSExtraData* extra) override;

    ExtraCellImageSpace(void* aField);

    bool IsDifferentFrom(BSExtraData* extra);

    void* m_pImageSpace;
};
