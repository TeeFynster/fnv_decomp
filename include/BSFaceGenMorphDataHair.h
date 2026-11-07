#pragma once

#include "BSFaceGenMorphData.h"

class FaceGenTriData;

class BSFaceGenMorphDataHair : public BSFaceGenMorphData
{
public:
    BSFaceGenMorphDataHair(FaceGenTriData*);
    virtual ~BSFaceGenMorphDataHair();
    virtual const NiRTTI* GetRTTI() const;

    void FUN_006623d0();
    void* FUN_006623a0(unsigned int);
    void ApplyMorph_00662460(int, int, float);

    void* hairMorph;
};
