#pragma once

#include "NiTMap.h"

class BGSReconstructCellBlocksMap;

class BGSReconstructWorldSpacesMap : public NiTMap<unsigned int, BGSReconstructCellBlocksMap*>
{
public:
    BGSReconstructWorldSpacesMap();
    virtual ~BGSReconstructWorldSpacesMap();
    void* ScalarDeletingDestructor(unsigned int flags);
    void FUN_00841f00();
    void* FUN_00841ed0(unsigned int flags);
};
