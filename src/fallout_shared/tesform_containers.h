// Unit-private declaration closure. No external function bodies are defined here.
// Provenance and qualified constructor/fold bindings: PROVENANCE.md.
#ifndef FNV_UNIT_TESFORM_CONTAINERS_H
#define FNV_UNIT_TESFORM_CONTAINERS_H

#include "tesform_layout_support.h"
#include "../../include/MapEntryCount.h"

#include "../../include/NiTPointerMap.h"
#include "../../include/NiTMap.h"
#include "../../include/NiTStringTemplateMap.h"

#include "../../include/NiTMallocInterface.h"
#include "../../include/NiTLargeArray.h"
#include "../../include/NiTLargePrimitiveArray.h"

template <class V> class NiTStringMap : public NiTStringTemplateMap<NiTMap<const char*, V>, V>
{
  public:
    NiTStringMap(unsigned int hashSize, bool copyStrings);
};

template <class V> class BSTCaseInsensitiveStringMap : public NiTStringMap<V>
{
  public:
    BSTCaseInsensitiveStringMap(unsigned int hashSize, bool copyStrings);
    virtual unsigned int KeyToHashIndex(const char* key) const;
    virtual bool IsKeysEqual(const char* first, const char* second) const;
};



// These typedefs are layout-assertion conveniences, not new class owners.
typedef NiTPointerMap<unsigned int, TESForm*> TESFormNumericMap;
typedef BSTCaseInsensitiveStringMap<TESForm*> TESFormEditorIDMap;
typedef NiTLargePrimitiveArray<TESForm*> TESFormAlteredArray;
typedef NiTMapItem<const char*, TESForm*> TESFormEditorIDMapItem;
FNV_STATIC_ASSERT(sizeof(TESFormNumericMap) == 0x10);
FNV_STATIC_ASSERT(offsetof(TESFormNumericMap, m_uiHashSize) == 0x4);
FNV_STATIC_ASSERT(offsetof(TESFormNumericMap, m_ppkHashTable) == 0x8);
FNV_STATIC_ASSERT(offsetof(TESFormNumericMap, m_kItemCount) == 0xC);
FNV_STATIC_ASSERT(sizeof(TESFormEditorIDMap) == 0x14);
FNV_STATIC_ASSERT(offsetof(TESFormEditorIDMap, m_uiHashSize) == 0x4);
FNV_STATIC_ASSERT(offsetof(TESFormEditorIDMap, m_ppkHashTable) == 0x8);
FNV_STATIC_ASSERT(offsetof(TESFormEditorIDMap, m_kItemCount) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESFormEditorIDMap, m_bCopy) == 0x10);
FNV_STATIC_ASSERT(sizeof(TESFormEditorIDMapItem) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESFormEditorIDMapItem, m_pkNext) == 0x0);
FNV_STATIC_ASSERT(offsetof(TESFormEditorIDMapItem, m_key) == 0x4);
FNV_STATIC_ASSERT(offsetof(TESFormEditorIDMapItem, m_val) == 0x8);
FNV_STATIC_ASSERT(sizeof(TESFormAlteredArray) == 0x18);
FNV_STATIC_ASSERT(offsetof(TESFormAlteredArray, m_pBase) == 0x4);
FNV_STATIC_ASSERT(offsetof(TESFormAlteredArray, m_uiMaxSize) == 0x8);
FNV_STATIC_ASSERT(offsetof(TESFormAlteredArray, m_uiSize) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESFormAlteredArray, m_uiESize) == 0x10);
FNV_STATIC_ASSERT(offsetof(TESFormAlteredArray, m_uiGrowBy) == 0x14);

// Global allocation/deallocation are declarations only. The covered new
// expressions emit the allocation and exception cleanup naturally.
void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* memory);
#endif
