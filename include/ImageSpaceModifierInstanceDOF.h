#pragma once

#include "ImageSpaceModifierInstanceTemp.h"

class ImageSpaceModifierInstanceDOF : public ImageSpaceModifierInstanceTemp
{
  public:
    enum DepthOfFieldMode  // values: Xbox PDB ImageSpaceModifierInstanceDOF::DepthOfFieldMode
    {
        DOF_FRONT_BACK = 0,
        DOF_FRONT = 1,
        DOF_BACK = 2,
        DOF_FRONT_BACK_MASK = 3,
        DOF_FRONT_MASK = 4,
        DOF_BACK_MASK = 5,
        DOF_NONE = 6
    };

    ImageSpaceModifierInstanceDOF();
    ImageSpaceModifierInstanceDOF(float, float, DepthOfFieldMode, float, float, float, NiAVObject*, float);
    virtual ~ImageSpaceModifierInstanceDOF();

    void DestroyMembers();
    void* ScalarDeletingDestructor(unsigned int);
    static ImageSpaceModifierInstanceDOF* CreateAndRegister(float, float, DepthOfFieldMode, float, float, float);
    void Apply();
    float GetDistance();
    void SetDistance(float);
    void SetStrength(float);
    void SetIntensity(float);

    void ImageSpaceModifierInstance_SetPermanent(bool);
    void FUN_0063f790(float);
    void FUN_0050f9a0(void*);
    float FUN_0084d030();
    void BaseProcess_SetLastTimeProcessed(float);

    float fDistance;
    float fImpulseRadiusSquared;
    float m_fMaskConstant;
    DepthOfFieldMode Mode;
};
