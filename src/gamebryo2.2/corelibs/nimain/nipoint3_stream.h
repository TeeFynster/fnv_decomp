// Inline scalar stream operations used by NiColor serialization.
#pragma once
#include "../../../../include/NiBinaryStream.h"

inline void NiBinaryStream::Read(float* data)
{
    unsigned int size = 4;
    m_uiAbsoluteCurrentPos += m_pfnRead(this, data, 4, &size, 1);
}

inline void NiBinaryStream::Write(float* data)
{
    unsigned int size = 4;
    m_uiAbsoluteCurrentPos += m_pfnWrite(this, data, 4, &size, 1);
}
