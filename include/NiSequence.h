#pragma once

#include "NiObject.h"
#include "StrArr.h"

class NiSequence : public NiObject
{
public:
    NiSequence* Initialize(const char* pcName, unsigned int uiArraySize, unsigned int uiArrayGrowBy);
    virtual void LoadBinary(NiStream& kStream);

    char* m_pcName;
    StrArr m_kStringArray;
    char pad[0x14];
    unsigned int m_uiSequenceValue;
};
