// src/gamebryo2.2/corelibs/nimain/nilinesdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nilinesdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiGeometryData.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiTPrimitiveArray.h"
#include "../../../../include/NiLinesData.h"

// NiLinesData.h currently omits m_pkFlags and these overrides. Keep the real
// derived class here until the shared declaration supports the +0x40 flags array.

extern "C" void* g_011f5b88;

// @fnv 0x00a8a7b0
// src: COMMUNITY 0x00a8a7b0
void* __cdecl NiLinesData_GetRTTI()
{
    return &g_011f5b88;
}

void* __cdecl NiFreeAlias(void*);
extern int DAT_0109f23c;
void __cdecl operator delete(void* p, unsigned int size);

// @fnv 0x00a8a7c0
void* NiLinesData::Destroy(unsigned int flags)
{
    void* pkFlags = m_pkFlags;
    *(void**)this = (void*)&DAT_0109f23c;
    NiFreeAlias(pkFlags);
    NiGeometryData::~NiGeometryData();
    if (flags & 1)
        ::operator delete(this, 0x44);
    return this;
}

// @fnv 0x00a8a730
bool NiLinesData::IsEqual(NiObject* other) const
{
    if (!IsGeometryEqual(other))
    {
        return false;
    }
    const NiLinesData* data = static_cast<const NiLinesData*>(other);
    if (m_pkFlags && !data->m_pkFlags)
    {
        return false;
    }
    if (!m_pkFlags && data->m_pkFlags)
    {
        return false;
    }
    if (m_pkFlags)
    {
        for (unsigned short i = 0; i < m_usVertices; ++i)
        {
            if (m_pkFlags[i] != data->m_pkFlags[i])
            {
                return false;
            }
        }
    }
    return true;
}

// @fnv 0x00a8a850
void NiLinesData::SaveBinary(NiStream& stream)
{
    NiGeometryData::SaveBinary(stream);
    NiBinaryStream* io = stream.m_pkOstr;
    unsigned char* buf = m_pkFlags;
    unsigned int len = m_usVertices;
    {
        unsigned int out = 1;
        unsigned int written = io->m_pfnWrite(io, buf, len, &out, 1);
        io->m_uiAbsoluteCurrentPos += written;
    }
}

template <class T, class TAlloc>
inline unsigned int NiTArray<T, TAlloc>::Add(const T& s)
{
    unsigned int i = m_usSize;
    T t = s;
    if (i >= m_usMaxSize)
        SetSize(i + m_usGrowBy);
    SetAt(i, t);
    return i;
}

extern int DAT_011f5b88;
const char* NiViewerStrings_NiGetViewerString_Title(int g);
const char* NiGetViewerString_00a7d5a0(const char* fmt, int v);

// @fnv 0x00a8a890
void NiLinesData::GetViewerStrings(NiViewerStringsArray* arr)
{
    RegisterGeometryFields(arr);
    arr->Add(NiViewerStrings_NiGetViewerString_Title(DAT_011f5b88));
    arr->Add(NiGetViewerString_00a7d5a0("m_pkFlags", reinterpret_cast<int>(m_pkFlags)));
}

inline unsigned int NiBinaryStream::BinaryRead(void* pvBuffer, unsigned int uiTotalBytes,
                                               unsigned int* puiComponentSizes,
                                               unsigned int uiNumComponents)
{
    unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    m_uiAbsoluteCurrentPos += uiBytesRead;
    return uiBytesRead;
}

template <class T> inline void NiBinaryStreamLoad(NiBinaryStream& is, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    is.BinaryRead(pValue, uiSize * uiNumEls, &uiSize, 1);
}

template <class T> inline void ReadBinaryValue(NiStream& kStream, T* pValue, unsigned int uiNumEls)
{
    NiBinaryStreamLoad(*kStream.m_pkIstr, pValue, uiNumEls);
}

void* NiMalloc(unsigned int stSize);

// @fnv 0x00a8a800
void NiLinesData::LoadBinary(NiStream& kStream)
{
    NiGeometryData::LoadBinary(kStream);
    m_pkFlags = (unsigned char*)NiMalloc(m_usVertices);
    ReadBinaryValue(kStream, m_pkFlags, m_usVertices);
}
