#pragma once

#include "hkStreamWriter.h"
#include "hkArray.h"

class hkCharArray;

class hkArrayStreamWriter : public hkStreamWriter
{
public:
    hkArrayStreamWriter(hkCharArray* arr, int ownership);
    virtual ~hkArrayStreamWriter() throw();

    virtual int write(const void* buf, int len);
    virtual void Reset();

    int Seek(int iRelOffset, int eWhence);

    hkArray<char>* m_aiIndexedValues;
    int m_offset;
    int m_ownership;
};
