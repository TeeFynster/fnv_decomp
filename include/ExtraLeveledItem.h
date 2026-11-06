#pragma once

#include "BSExtraData.h"

struct ExtraLeveledItem : public BSExtraData
{
public:
    virtual ~ExtraLeveledItem();
    bool Compare(BSExtraData* extra) override;

    ExtraLeveledItem(int aIndex);

    int iIndex;
    bool m_bIsLeveledItem;
    unsigned char layoutPadding11[3];
};
