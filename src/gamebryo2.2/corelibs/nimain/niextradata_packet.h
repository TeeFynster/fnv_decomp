// Unit-specific declarations and stream helpers.

extern NiFixedString EmptyFS;
extern void* kVtbl_NiExtraData[];
void* _NiMalloc(unsigned int);
template <class T> void ReadBinaryValue(NiStream&, T*, unsigned int);
extern const char g_011c7820_arg1[];

inline bool IsExactKindOf(const void* type, NiObject* object)
{
    if (object)
        return object->GetRTTI() == type;
    return false;
}

inline void ReadCount(NiStream& stream, unsigned int& count)
{
    stream.m_pkIstr->Read(&count, 4);
}

#include "../../../../include/NiMemObject.h"
