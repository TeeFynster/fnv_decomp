// gamebryo2.2/corelibs/nimain/niplane.cpp: NiSphere, NiPlane (4 functions)
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiColor.h"
#include "../../../../include/NiPlane.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiSphere.h"
#include "../../../../include/NiStream.h"

inline void NiBinaryStream::Read(float* value)
{
    unsigned int size = 4;
    m_uiAbsoluteCurrentPos += m_pfnRead(this, value, 4, &size, 1);
}

inline void NiBinaryStream::Write(float* value)
{
    unsigned int size = 4;
    m_uiAbsoluteCurrentPos += m_pfnWrite(this, value, 4, &size, 1);
}

// Constructs a NiPlane with normal set to NiPoint3::ZERO and constant set to 0.0f.
// @fnv 0x00a69940
NiPlane::NiPlane()
{
    *reinterpret_cast<NiPoint3*>(&x) = NiPoint3::ZERO;
    c = 0.0f;
}

// Loads the sphere's center and radius from the given stream.
// @fnv 0x00a69ac0
void NiSphere::LoadBinary(NiStream& stream)
{
    reinterpret_cast<NiColor*>(&x)->LoadBinary(stream);
    stream.m_pkIstr->Read(&r);
}

// Saves the sphere's center and radius to the stream's output.
// @fnv 0x00eb5410
void NiSphere::SaveBinary(NiStream& stream)
{
    reinterpret_cast<NiColor*>(&x)->SaveBinary(stream);
    stream.m_pkOstr->Write(&r);
}

extern "C" unsigned int __cdecl strlen(const char*);
void* __cdecl _NiMalloc(unsigned int);
int __cdecl _NiSprintf(char*, unsigned int, const char*, ...);
// Allocates a string sized from the prefix length and formats the four floats as "(%g,%g,%g), %g", returning the buffer.
// @fnv 0x00a69a60
char* __fastcall NiPlaneGetFormattedString(const NiPlane* plane, void*, const char* pPrefix)
{
    char* pBuffer;
    unsigned int uiPrefixLen;
    uiPrefixLen = strlen(pPrefix);
    pBuffer = (char*)_NiMalloc(uiPrefixLen + 0x38);
    _NiSprintf(pBuffer, uiPrefixLen + 0x38, "(%g,%g,%g), %g", plane->x, plane->y, plane->z, plane->c);
    return pBuffer;
}
