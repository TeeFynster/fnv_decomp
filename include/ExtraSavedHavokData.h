#pragma once

#include "BSExtraData.h"

class __declspec(align(8)) ExtraSavedHavokData : public BSExtraData
{
public:
    virtual ~ExtraSavedHavokData();

    ExtraSavedHavokData();

    void* __thiscall Destroy(unsigned int flags);
    void DeleteBuffer_00435c10();

    char* m_pSavedHavokData;
};
