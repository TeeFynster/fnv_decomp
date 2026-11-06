// gamebryo2.2/corelibs/nimain/nipoint2.cpp: NiPoint2 (2 functions)

#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiPoint2.h"
#include "../../../../include/NiStream.h"

__forceinline void NiBinaryStream::ReadFloat(float& value)
{
    unsigned int size = 4;
    m_uiAbsoluteCurrentPos += m_pfnRead(this, &value, 4, &size, 1);
}

inline void NiBinaryStream::Write(float* value)
{
    unsigned int size = 4;
    m_uiAbsoluteCurrentPos += m_pfnWrite(this, value, 4, &size, 1);
}

// Reads two floats from the stream into the point's x and y coordinates.
// @fnv 0x00a68c80
void NiPoint2::LoadBinary(NiStream& stream)
{
    stream.m_pkIstr->ReadFloat(x);
    stream.m_pkIstr->ReadFloat(y);
}

// @fnv 0x00a68ce0
void NiPoint2::SaveBinary(NiStream* stream)
{
    stream->m_pkOstr->Write(&x);
    stream->m_pkOstr->Write(&y);
}
