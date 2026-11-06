// Supplied declaration is the first16-byte prefix used only by reference here.
// Public PC NiObjectCopyInfo additionally has scale at+0x10; sizeof below validates this prefix only.
// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIBLENDINTERPOLATOR_NICLONINGPROCESS_H
#define FNV_NIBLENDINTERPOLATOR_NICLONINGPROCESS_H

#include "niblendinterpolator_layout_support.h"
#include "../../../../include/NiObject.h"
#include "niblendinterpolator_NiTPointerMap.h"
#include "niblendinterpolator_layout_support.h"
class CloningProcess;
#include "../../../../include/NiObjectNET.h"
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
FNV_STATIC_ASSERT(sizeof(CloningProcess) == 16);
FNV_STATIC_ASSERT(offsetof(CloningProcess, m_pCloneMap) == 0);
FNV_STATIC_ASSERT(offsetof(CloningProcess, m_pProcessMap) == 4);
FNV_STATIC_ASSERT(offsetof(CloningProcess, m_eCloneCopyMode) == 8);
FNV_STATIC_ASSERT(offsetof(CloningProcess, m_bExactType) == 12);
#endif
