// fallout/misc/saveload/FormIDConverter.h: declares FormIDConverter
#ifndef FNV_BGSSAVELOADFORMIDMAP_H
#define FNV_BGSSAVELOADFORMIDMAP_H

#include "../../../../include/NiTPointerMap.h"
#include "../../../../include/TESDataHandler.h"


extern TESDataHandler* g_dataHandler;

// Save/load form-ID remapping table: forward map (formID -> save index),
// reverse map (save index -> formID) and the next index to hand out.
class FormIDConverter
{
  public:
    NiTPointerMap<unsigned int, unsigned int> m_kSourceToTargetFormIDMap;  // +0x0
    NiTPointerMap<unsigned int, unsigned int> m_kTargetToSourceFormIDMap;  // +0x10
    unsigned int m_uiFormIDCount;                                          // +0x20

    FormIDConverter(unsigned int uiHashSize);
    ~FormIDConverter();
    void Clear();
    unsigned int RegisterFormID(unsigned int formID);
};

typedef char bgsSaveLoadFormIDMapSizeAssert[(sizeof(FormIDConverter) == 36) ? 1 : -1];
typedef char bgsSaveLoadFormIDMapIndexToFormIDMapOffsetAssert
    [((int)&((FormIDConverter*)0)->m_kTargetToSourceFormIDMap == 0x10) ? 1 : -1];
typedef char
    bgsSaveLoadFormIDMapICurrentIndexOffsetAssert[((int)&((FormIDConverter*)0)->m_uiFormIDCount == 0x20) ? 1 : -1];
typedef char
    niTPointerMapUnsignedUnsignedSizeAssert[(sizeof(NiTPointerMap<unsigned int, unsigned int>) == 16) ? 1 : -1];

#endif
