#pragma once

#include "BSFaceGenMorph.h"

class NiTriBasedGeom;
class BSFaceGenBaseMorphExtraData;

class BSFaceGenMorphDifferential : public BSFaceGenMorph
{
public:
    BSFaceGenMorphDifferential(unsigned int count);
    virtual ~BSFaceGenMorphDifferential();
    void ApplyDifferentialMorph(NiTriBasedGeom*, BSFaceGenBaseMorphExtraData*, float);
};
