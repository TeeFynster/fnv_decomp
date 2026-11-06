#pragma once

#include "NiPSysEmitter.h"

class NiAVObject;
class NiTransform;

class NiPSysVolumeEmitter : public NiPSysEmitter
{
public:
    NiPSysVolumeEmitter();
    NiPSysVolumeEmitter(const char* pcName, NiAVObject* pkEmitterObj, float fSpeed,
                        float fSpeedVar, float fDeclination, float fDeclinationVar,
                        float fPlanarAngle, float fPlanarAngleVar, NiColorA kInitialColor,
                        float fInitialRadius, float fLifeSpan, float fLifeSpanVar,
                        float fRadiusVar);
    virtual ~NiPSysVolumeEmitter();

    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual void ProcessClone(CloningProcess& process);
    virtual void GetPositionAndDirection(NiPoint3& position, NiPoint3& motionVelocity);
    virtual void vf43(NiAVObject* object);
    virtual void vf44(NiTransform& transform, NiPoint3* position, NiPoint3* motionVelocity);

    void LoadBinaryFromStream(NiStream* stream);
    void CopyMemberData(NiPSysVolumeEmitter* destination, CloningProcess& process);
    void* DestroyIfFlagged(unsigned int flags);

    NiAVObject* m_pkEmitterObject;
};
