#pragma once

#include "NiTMap.h"

class ReconstructFormData;

class BGSReconstructFormsMap : public NiTMap<unsigned int, ReconstructFormData>
{
public:
    int unk10;

    BGSReconstructFormsMap();
    virtual ~BGSReconstructFormsMap();
    void FUN_008411f0();
    void* FUN_008411c0(unsigned int flags);
};
