// Boolean-key dispatch tables and binary-reading helpers used by NiBoolData.
#ifndef FNV_NIBOOLDATA_DECLS_H
#define FNV_NIBOOLDATA_DECLS_H

#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiBoolData.h"
#include "../../../../include/NiObject.h"
// NiStream.h also defines the shared BSStreamHeader; its standalone header would redefine it.
#include "../../../../include/NiStream.h"

inline unsigned int NiBinaryStream::BinaryRead(void* buffer, unsigned int bytes,
                                               unsigned int* sizes, unsigned int count)
{
    unsigned int read = (*m_pfnRead)(this, buffer, bytes, sizes, count);
    m_uiAbsoluteCurrentPos += read;
    return read;
}

extern unsigned char DAT_011f3776[NiAnimationKey::NUMKEYTYPES];
typedef NiAnimationKey*(__cdecl* NiBoolLoadFunction)(NiStream&, unsigned int);
typedef void(__cdecl* NiBoolFillFunction)(NiAnimationKey*, unsigned int, unsigned char);
typedef void(__cdecl* NiBoolDeleteFunction)(NiAnimationKey*);
extern NiBoolLoadFunction DAT_011f3e28[NiAnimationKey::NUMKEYTYPES];
extern NiBoolFillFunction DAT_011f37f8[NiAnimationKey::NUMKEYTYPES];
extern NiBoolDeleteFunction DAT_011f3918[NiAnimationKey::NUMKEYTYPES];

class BooleanKey : public NiAnimationKey
{
  public:
    bool m_bValue;
    static inline unsigned char GetKeySize(KeyType type)
    {
        return DAT_011f3776[type];
    }
    static inline NiBoolLoadFunction GetLoadFunction(KeyType type)
    {
        return DAT_011f3e28[type];
    }
    static inline NiBoolFillFunction GetFillDerivedFunction(KeyType type)
    {
        return DAT_011f37f8[type];
    }
    static inline NiBoolDeleteFunction GetDeleteFunction(KeyType type)
    {
        return DAT_011f3918[type];
    }
};

template <class T> inline void ReadBinaryValue(NiBinaryStream& input, T& value)
{
    unsigned int size = sizeof(T);
    input.BinaryRead(&value, size, &size, 1);
}
template <class T> inline void ReadBinaryValue(NiStream& stream, T& value)
{
    ReadBinaryValue(*stream.m_pkIstr, value);
}

inline void ReadBinaryValue(NiBinaryStream& input, NiAnimationKey::KeyType& type)
{
    unsigned int storedType;
    unsigned int size = sizeof(storedType);
    unsigned int bytesRead = (*input.m_pfnRead)(&input, &storedType, size, &size, 1);
    type = static_cast<NiAnimationKey::KeyType>(storedType);
    input.m_uiAbsoluteCurrentPos += bytesRead;
}
inline void ReadBinaryValue(NiStream& stream, NiAnimationKey::KeyType& type)
{
    ReadBinaryValue(*stream.m_pkIstr, type);
}

#endif
