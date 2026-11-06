#pragma once

#include "ImageSpaceModifierInstanceTemp.h"
#include "ImageSpaceModifierInstanceDOF.h"
#include "NiPoint2.h"

class ImageSpaceModifierInstanceDRB : public ImageSpaceModifierInstanceTemp
{
  public:
    enum DepthOfFieldMode
    {
        DOF_FRONT_BACK,
        DOF_FRONT,
        DOF_BACK,
        DOF_NONE
    };

    ImageSpaceModifierInstanceDRB(float, float, NiAVObject*, float, DepthOfFieldMode, float, float, float, float,
                                  float, float, const NiPoint2&);

    static ImageSpaceModifierInstanceDRB* Trigger(float, float, DepthOfFieldMode, float, float, float, float,
                                                 float, const NiPoint2&, float);
    static ImageSpaceModifierInstanceDRB* Trigger(float, float, ImageSpaceModifierInstanceDOF::DepthOfFieldMode,
                                                 float, float, float, float, float, const NiPoint2&, float);
    void Apply();

    float m_fRampUp;
    float fStart;
    float m_fRampDown;
    float m_fRampDownStart;
    NiPoint2 Center;
    float fDistance;
    float fImpulseRadiusSquared;
    DepthOfFieldMode Mode;
};
