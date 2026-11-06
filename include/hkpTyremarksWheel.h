#pragma once

#include "hkReferencedObject.h"

class hkpTyremark;

class hkpTyremarksWheel : public hkReferencedObject
{
public:
    int m_iMaxNumTyremarks;
    int m_numTyremarks;
    hkpTyremark* m_data;

    hkpTyremark* __thiscall ComputeIndex(int index);
    void __thiscall FUN_00e39f50(hkpTyremark* tyremark);
};
