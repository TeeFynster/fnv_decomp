#pragma once

#include "BSExtraData.h"
#include "BGSPrimitive.h"

class ExtraPrimitive : public BSExtraData
{
public:
    ExtraPrimitive(BGSPrimitive* apPrimitive);

    virtual ~ExtraPrimitive();
    virtual bool __thiscall Compare(BSExtraData* apCompare);

    bool __thiscall Compare_00437370(BSExtraData* apCompare);
    void* __thiscall FUN_0041fb20(unsigned int flags);
    void* __thiscall FUN_0041fb50();

    BGSPrimitive* m_pPrimitive;
};
