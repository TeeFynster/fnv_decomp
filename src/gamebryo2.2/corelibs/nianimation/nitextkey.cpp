// gamebryo2.2/corelibs/nianimation/nitextkey.cpp: TimedTextEntry, NiTextKeyFnv (2 functions)

#include "nitextkey_decls.h"

inline unsigned int NiBinaryStream::Read(void* buffer, unsigned int size)
{
    unsigned int bytes = m_pfnRead(this, buffer, size, &size, 1);
    m_uiAbsoluteCurrentPos += bytes;
    return bytes;
}

inline void NiBinaryStream::Write(void* buffer, unsigned int size)
{
    m_uiAbsoluteCurrentPos += m_pfnWrite(this, buffer, size, &size, 1);
}

static inline NiBinaryStream* GetTextKeyOutput(const NiStream& stream)
{
    return stream.m_pkOstr;
}

// Reads m_fTime from the stream, then loads m_kText using the version-dependent string reader.
// @fnv 0x00a578d0
void TimedTextEntry::LoadBinary(NiStream& stream)
{
    NiBinaryStream* input = stream.m_pkIstr;
    input->Read(&m_fTime, 4);
    if (stream.m_uiNifFileVersion < 0x14010001)
        stream.ReadFixedString(m_kText);
    else
        stream.ReadStringTableEntry(m_kText);
}

struct NiTextKeyFnv
{
    float m_fTime;
    NiFixedString m_kText;

    void ReadFromStream(NiStream& stream);
};

// @fnv 0x00a57930
void NiTextKeyFnv::ReadFromStream(NiStream& stream)
{
    GetTextKeyOutput(stream)->Write(&m_fTime, sizeof(m_fTime));
    stream.SerializeString(reinterpret_cast<const char*>(&m_kText));
}
