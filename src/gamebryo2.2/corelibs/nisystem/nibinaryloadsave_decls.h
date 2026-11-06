// gamebryo2.2/corelibs/nisystem/nibinaryloadsave_decls.h: declares NiAnimationKey and BooleanKey and binary stream helpers
#ifndef NIBINARYLOADSAVE_DECLS_H
#define NIBINARYLOADSAVE_DECLS_H

inline unsigned int NiBinaryStream::BinaryRead(void* data, unsigned int bytes, unsigned int* sizes, unsigned int count)
{
    unsigned int result = m_pfnRead(this, data, bytes, sizes, count);
    m_uiAbsoluteCurrentPos += result;
    return result;
}
template <class T> inline void NiBinaryStreamLoad(NiBinaryStream& input, T* value)
{
    unsigned int size = sizeof(T);
    input.BinaryRead(value, sizeof(T), &size, 1);
}
#include "../../../../include/NiAnimationKey.h"
class BooleanKey : public NiAnimationKey
{
  public:
    bool m_bValue;
    void LoadBinary(NiStream& stream);
};
#endif
