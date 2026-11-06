#pragma once

#include "BSExtraData.h"

struct BGSAcousticSpace;

class ExtraCellAcousticSpace : public BSExtraData
{
public:
    ExtraCellAcousticSpace(BGSAcousticSpace*);
    bool Compare(BSExtraData* apCompare) override;
    bool FUN_0040f000(BSExtraData* apCompare);

    BGSAcousticSpace* m_pPathingCell;
};
