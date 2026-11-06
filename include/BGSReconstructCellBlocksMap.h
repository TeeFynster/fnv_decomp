#pragma once

#include "NiTMap.h"

class BGSReconstructCellSubBlocksMap;

class BGSReconstructCellBlocksMap : public NiTMap<unsigned int, BGSReconstructCellSubBlocksMap*>
{
public:
    int unk10;
    bool unk14;

    BGSReconstructCellBlocksMap(bool exterior);
    ~BGSReconstructCellBlocksMap();
    void* ScalarDeletingDestructor(unsigned int flags);

    void FUN_00841a60();
    void* FUN_00841a30(unsigned int flags);
};
