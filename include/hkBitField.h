#pragma once

#include "hkArray.h"

class hkBitField
{
  public:
    hkArray<unsigned int> m_auiBitFieldWords;
    int m_iNumBits;

    __declspec(noinline) void fillUnusedBits(int value) throw();
    void setSize(int iNumBits, int iInitialValue);

    int get(int index) const
    {
        return (m_auiBitFieldWords[index >> 5] >> (index & 0x1f)) & 1;
    }
};
