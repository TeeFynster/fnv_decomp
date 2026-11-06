// gamebryo2.2/corelibs/nimain/nidefaultavobjectpalette_decls.h: declares NiBinaryStream
#ifndef NIDEFAULTAVOBJECTPALETTE_DECLS_H
#define NIDEFAULTAVOBJECTPALETTE_DECLS_H


inline unsigned int NiBinaryStream::BinaryRead(void* buffer, unsigned int bytes, unsigned int* componentSizes,
                                               unsigned int components)
{
    unsigned int bytesRead = m_pfnRead(this, buffer, bytes, componentSizes, components);
    m_uiAbsoluteCurrentPos += bytesRead;
    return bytesRead;
}

template <class T> void NiBinaryStreamLoad(NiBinaryStream& stream, T* value, unsigned int count = 1)
{
    unsigned int componentSize = sizeof(T);
    stream.BinaryRead(value, sizeof(T) * count, &componentSize, 1);
}

template <class T> void ReadBinaryValue(NiStream& stream, T& value)
{
    NiBinaryStreamLoad(*stream.m_pkIstr, &value, 1);
}

extern NiFixedString EmptyFS;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
void __cdecl NiFree(void*);

#endif
