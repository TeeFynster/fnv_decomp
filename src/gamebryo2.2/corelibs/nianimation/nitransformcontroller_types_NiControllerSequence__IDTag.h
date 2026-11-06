// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NICONTROLLERSEQUENCE_IDTAG_H
#define FNV_NICONTROLLERSEQUENCE_IDTAG_H

#include <stddef.h>
#ifndef FNV_STATIC_ASSERT
#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]
#endif
template <class K, class V> class NiTPointerMap;
#include "NiFixedString.h"
class NiControllerSequence__IDTag;
#pragma pack(push, 4)
class NiControllerSequence__IDTag
{
  public:
    NiControllerSequence__IDTag& operator=(const NiControllerSequence__IDTag&);
    NiFixedString m_kAVObjectName;    // +0x0, 4 bytes
    NiFixedString m_kPropertyType;    // +0x4, 4 bytes
    NiFixedString m_kCtlrType;        // +0x8, 4 bytes
    NiFixedString m_kCtlrID;          // +0xC, 4 bytes
    NiFixedString m_kInterpolatorID;  // +0x10, 4 bytes
    // IDTag
    // const NiFixedString& __cdecl NiControllerSequence::IDTag::*()
    // void __cdecl NiControllerSequence::IDTag::*(const NiFixedString&)
    // const NiFixedString& __cdecl NiControllerSequence::IDTag::*()
    // void __cdecl NiControllerSequence::IDTag::*(const NiFixedString&)
    // const NiFixedString& __cdecl NiControllerSequence::IDTag::*()
    // void __cdecl NiControllerSequence::IDTag::*(const NiFixedString&)
    // const NiFixedString& __cdecl NiControllerSequence::IDTag::*()
    // void __cdecl NiControllerSequence::IDTag::*(const NiFixedString&)
    // const NiFixedString& __cdecl NiControllerSequence::IDTag::*()
    // void __cdecl NiControllerSequence::IDTag::*(const NiFixedString&)
    // NiControllerSequence::IDTag& __cdecl NiControllerSequence::IDTag::*(const NiControllerSequence::IDTag&)
    // void __cdecl NiControllerSequence::IDTag::*()
    // bool __cdecl NiControllerSequence::IDTag::*()
    // void __cdecl NiControllerSequence::IDTag::*(NiStream&)
    // void __cdecl NiControllerSequence::IDTag::*(NiStream&)
    // void __cdecl NiControllerSequence::IDTag::*(NiStream&, void*&)
    // void __cdecl NiControllerSequence::IDTag::*(NiStringPalette*, NiStream&)
    // bool __cdecl NiControllerSequence::IDTag::*(const NiControllerSequence::IDTag&)
    // bool __cdecl NiControllerSequence::IDTag::*()
    // bool __cdecl NiControllerSequence::IDTag::*()
    // void __cdecl NiControllerSequence::IDTag::*()
    // void __cdecl NiControllerSequence::IDTag::*()
    // void* __cdecl NiControllerSequence::IDTag::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiControllerSequence__IDTag) == 20);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence__IDTag, m_kAVObjectName) == 0);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence__IDTag, m_kPropertyType) == 4);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence__IDTag, m_kCtlrType) == 8);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence__IDTag, m_kCtlrID) == 12);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence__IDTag, m_kInterpolatorID) == 16);
#endif
