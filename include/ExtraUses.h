#pragma once

#include "BSExtraData.h"

class ExtraUses : public BSExtraData
{
public:
    virtual ~ExtraUses();
    virtual bool Compare(BSExtraData* apCompare);

    unsigned char m_ucUses;
    unsigned char unk0D[3];
};
