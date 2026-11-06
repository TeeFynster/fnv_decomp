#pragma once

#include "BSFaceGenMorph.h"

class NiTriBasedGeom;
class BSFaceGenBaseMorphExtraData;

class BSFaceGenMorphStatistical : public BSFaceGenMorph
{
public:
    BSFaceGenMorphStatistical(unsigned int count, unsigned int firstIndex);
    virtual ~BSFaceGenMorphStatistical();
    void ApplyDifferentialMorph(NiTriBasedGeom*, BSFaceGenBaseMorphExtraData*, float);

    unsigned int extra;
};
