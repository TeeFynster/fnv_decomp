#pragma once

#include "NiAdditionalGeometryData.h"

class BSPackedAdditionalGeometryData : public NiAdditionalGeometryData
{
public:
    struct NiBSPackedAGDDataBlock
    {
        unsigned int unk00;
        unsigned int unk04;
        void* unk08;
        unsigned char unk0C;
        unsigned char unk0D;
    };
};
