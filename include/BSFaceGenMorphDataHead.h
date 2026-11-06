#pragma once

#include "BSFaceGenMorphData.h"
#include "BSFaceGenMorph.h"
#include "NiRTTI.h"

class FaceGenTriData;

class BSFaceGenMorphDataHead : public BSFaceGenMorphData
{
public:
    BSFaceGenMorphDataHead();
    BSFaceGenMorphDataHead(FaceGenTriData*);
    virtual ~BSFaceGenMorphDataHead();

    virtual const NiRTTI* GetRTTI() const;

    void* FUN_00661db0(unsigned int flags);
    void FUN_00662030(int aiSelector, int aiIndex, int aiArg1, int aiArg2, float weight);
    int FUN_006620d0(int aiIndex);
    int FUN_00662110(int aiIndex);
    int FUN_00662150(int aiIndex);
    int FUN_00662190(int aiIndex);

    static const NiRTTI ms_kRTTI;

    BSFaceGenMorph** expressions;
    BSFaceGenMorph** modifiers;
    BSFaceGenMorph** phonemes;
    BSFaceGenMorph** custom;
};
