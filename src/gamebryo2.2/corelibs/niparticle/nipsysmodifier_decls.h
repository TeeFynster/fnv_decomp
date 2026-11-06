#include "../../../../include/NiTStringPointerMap.h"
// Local clone-map helpers and layout checks for NiPSysModifier.
#ifndef FNV_NIPSYSMODIFIER_DECLS_H
#define FNV_NIPSYSMODIFIER_DECLS_H

#include "layout_support.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiPSysModifier.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiTStringPointerMap.h"

extern NiFixedString EmptyFS;

class CloningProcess
{
  public:
    NiTPointerMap<NiObject*, NiObject*>* m_pCloneMap;
    NiTPointerMap<NiObject*, bool>* m_pProcessMap;
    unsigned int m_eCloneCopyMode;
    char m_bExactType;
};

inline unsigned int NiBinaryStream::BinaryRead(void* pvBuffer, unsigned int uiBytes,
                                              unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
    m_uiAbsoluteCurrentPos += uiRead;
    return uiRead;
}

template <class T> inline void NiBinaryStreamLoad(NiBinaryStream& kStream, T* pValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(pValue, sizeof(T), &uiSize, 1);
}

FNV_STATIC_ASSERT(sizeof(NiObject) == 8);
FNV_STATIC_ASSERT(sizeof(CloningProcess) == 16);
FNV_STATIC_ASSERT(sizeof(NiBinaryStream) == 16);
FNV_STATIC_ASSERT(offsetof(NiStream, m_uiNifFileVersion) == 0xD8);
FNV_STATIC_ASSERT(offsetof(NiStream, m_pkIstr) == 0x24C);
FNV_STATIC_ASSERT(sizeof(NiPSysModifier) == 24);
FNV_STATIC_ASSERT(offsetof(NiPSysModifier, m_kName) == 8);
FNV_STATIC_ASSERT(offsetof(NiPSysModifier, m_uiUpdateOrder) == 12);
FNV_STATIC_ASSERT(offsetof(NiPSysModifier, m_pkTarget) == 16);
FNV_STATIC_ASSERT(offsetof(NiPSysModifier, m_bModifierActive) == 20);

#endif
