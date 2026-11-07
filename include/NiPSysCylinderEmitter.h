#pragma once

#include "NiPSysVolumeEmitter.h"

class NiTransform;
struct StrArr;

class NiPSysCylinderEmitter : public NiPSysVolumeEmitter
{
public:
    virtual void LoadBinary(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);

    void* DestroyIfFlagged(unsigned int flags);
    BSFadeNode* CloneFadeNode(CloningProcess& process);
    void AppendShapeParams(StrArr* strings);
    void ComputeVolumeInitialPositionAndVelocity(NiTransform& emitterToPSys, NiPoint3& position, NiPoint3& motionVelocity);  // rotates by the transform (0x00524c40), velocity by its m_Rotate

    bool __thiscall IsEqual_00c1f9e0(NiAVObject* pkObject);
    bool __thiscall FUN_00c31b80(NiAVObject* pkObject);

    float m_fCylinderRadius;
    float m_fCylinderHeight;
};
