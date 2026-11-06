#pragma once

#include "NiTMap.h"

class BGSReconstructFormsMap;

class BGSReconstructCellsMap : public NiTMap<unsigned int, BGSReconstructFormsMap*>
{
public:
    void* ScalarDeletingDestructor(unsigned int flags);
    BGSReconstructCellsMap();
    BGSReconstructCellsMap(unsigned int capacity);
    ~BGSReconstructCellsMap();
    bool HasFileMapWithFlag(unsigned int);
    void* FUN_00841370(unsigned int flags);
    void FUN_008413a0();
};
