#pragma once

#include "BGSReconstructCellsMap.h"

class BGSReconstructCellBlocksMap;
class BGSReconstructWorldSpacesMap;
class TESFile;
class FormChangeMap;

class BGSReconstructFormsInFileMap : public NiTMap<unsigned int, BGSReconstructFormsMap*>
{
public:
    BGSReconstructCellBlocksMap* m_pInteriorMap;
    BGSReconstructWorldSpacesMap* m_pExteriorMap;
    int iCount;

    BGSReconstructFormsInFileMap();
    ~BGSReconstructFormsInFileMap();
    void* ScalarDeletingDestructor(unsigned int flags);
    void BuildMap(TESFile* file, FormChangeMap* forms);
};
