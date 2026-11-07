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
    void ApplyMorph(int aiSelector, int aiIndex, int aiArg1, int aiArg2, float weight);
    int GetExpressionMorph(int aiIndex);
    int GetModifierMorph(int aiIndex);
    int GetPhonemeMorph(int aiIndex);
    int GetCustomMorph(int aiIndex);

    static const NiRTTI ms_kRTTI;

    BSFaceGenMorph** expressions;
    BSFaceGenMorph** modifiers;
    BSFaceGenMorph** phonemes;
    BSFaceGenMorph** custom;
};
