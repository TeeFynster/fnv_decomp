#include "nishaderconstantmapentry_decls.h"

// @fnv 0x00e81ba0
NiShaderConstantMapEntry::NiShaderConstantMapEntry() throw()
    : m_kControlPoint((reinterpret_cast<unsigned char*>(&unk08)[0] = 1,
                       EmptyFS.m_kHandle), 0),
      m_kSecondaryString((m_uiValue1 = 0, m_uiValue2 = 0, m_uiValue3 = 0,
                          m_uiValue4 = 0, EmptyFS.m_kHandle), 0)
{
    volatile NiShaderConstantMapEntry* ordered = this;
    ordered->m_uiValue5 = 0;
    ordered->m_uiValue6 = 0;
    ordered->m_pConstantData = 0;
    ordered->m_bFlag0 = false;
    // The two remaining state bytes occupy the tail padding of the shared class.
    reinterpret_cast<volatile unsigned char*>(&m_bFlag0)[1] = 0;
    reinterpret_cast<volatile unsigned char*>(&m_bFlag0)[2] = 0;
}
