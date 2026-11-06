// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NICLONINGPROCESS_H
#define FNV_NICLONINGPROCESS_H

#include <stddef.h>
#ifndef FNV_STATIC_ASSERT
#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]
#endif
template <class K, class V> class NiTPointerMap;
#include "NiObject.h"
class CloningProcess;
#include "../../../../include/NiObjectNET.h"
#pragma pack(push, 4)
class CloningProcess
{
  public:
    NiTPointerMap<NiObject*, NiObject*>* m_pCloneMap;  // +0x0, 4 bytes
    NiTPointerMap<NiObject*, bool>* m_pProcessMap;     // +0x4, 4 bytes
    NiObjectNET::CopyType m_eCloneCopyMode;            // +0x8, 4 bytes
    char m_bExactType;                                 // +0xC, 1 bytes
    unsigned char layoutPaddingD[3];
    // void __cdecl CloningProcess::*(unsigned int)
    // void __cdecl CloningProcess::*()
    // void __cdecl CloningProcess::*()
    // void* __cdecl CloningProcess::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(CloningProcess) == 16);
FNV_STATIC_ASSERT(offsetof(CloningProcess, m_pCloneMap) == 0);
FNV_STATIC_ASSERT(offsetof(CloningProcess, m_pProcessMap) == 4);
FNV_STATIC_ASSERT(offsetof(CloningProcess, m_eCloneCopyMode) == 8);
FNV_STATIC_ASSERT(offsetof(CloningProcess, m_bExactType) == 12);
#endif
