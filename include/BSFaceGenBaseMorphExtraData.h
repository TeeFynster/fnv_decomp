#pragma once

#include "NiExtraData.h"
#include "NiPoint3.h"

class BSFaceGenBaseMorphExtraData : public NiExtraData
{
public:
    BSFaceGenBaseMorphExtraData(NiGeometry* geometry, NiPoint3* extraVertices, unsigned int extraCount);
    virtual ~BSFaceGenBaseMorphExtraData();
    virtual const NiRTTI* GetRTTI() const;

    NiPoint3* GetVertices();
    unsigned int GetPointerByFlag(unsigned int);
    void* FUN_006626f0(unsigned int flags);
    void UpdateFields_00662720();

    static const NiRTTI ms_kRTTI;

    NiPoint3* vertices;
    unsigned int count;
    unsigned int originalCount;
};
