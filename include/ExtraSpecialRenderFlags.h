#pragma once

#include "BSExtraData.h"

class ExtraSpecialRenderFlags : public BSExtraData
{
public:
    virtual ~ExtraSpecialRenderFlags();
    virtual bool Compare(BSExtraData* apCompare);
    virtual void vf02();
    virtual void Copy_00438330(BSExtraData* pExtraData);

    bool Compare_004382a0(BSExtraData* apCompare);
    unsigned int GetFlags();
    void SetFlags(unsigned int flags);

    unsigned int uiFlags;
    float m_fRenderValue;
};
