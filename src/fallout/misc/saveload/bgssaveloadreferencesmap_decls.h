// Private declarations for BGSSaveLoadReferencesMap.
#ifndef FNV_BGSSAVELOADREFERENCESMAP_DECLS_H
#define FNV_BGSSAVELOADREFERENCESMAP_DECLS_H


#include "../../../../include/TESForm.h"
#include "../../../../include/TESObjectCELL.h"
#include "../../../../include/TESWorldSpace.h"

#include "../../../../include/NiTPointerMap.h"
#include "../../../../include/BGSCellNumericIDArrayMap.h"

#include "../../../../include/BSSimpleArray.h"

class BGSReconstructFormsInAllFilesMap;

class BGSSaveLoadReferencesMap
{
  public:
    NiTPointerMap<unsigned int, unsigned int> m_kReferenceIDMap;
    BGSCellNumericIDArrayMap m_kCellReferences;
    NiTPointerMap<unsigned int, BGSCellNumericIDArrayMap*> m_kWorldspaceCellReferenceMaps;

    void Clear();
    void LoadCellReferences(TESObjectCELL* cell, BGSReconstructFormsInAllFilesMap* forms);
    void ReconstructFormID(unsigned int id, BGSReconstructFormsInAllFilesMap* forms);
};

typedef char bgssaveloadreferencesmap_cell_map_size[(sizeof(BGSCellNumericIDArrayMap) == 16) ? 1 : -1];
typedef char bgssaveloadreferencesmap_references_size[(sizeof(BGSSaveLoadReferencesMap) == 48) ? 1 : -1];

#endif
