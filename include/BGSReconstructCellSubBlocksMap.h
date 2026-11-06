#pragma once

#include "NiTMap.h"

class BGSReconstructCellsMap;

class BGSReconstructCellSubBlocksMap : public NiTMap<unsigned int, BGSReconstructCellsMap*>
{
public:
    BGSReconstructCellSubBlocksMap();
    virtual ~BGSReconstructCellSubBlocksMap();
    void* __thiscall ScalarDeletingDestructor(unsigned int flags);
    bool HasCellWithFlag(unsigned int);
};
