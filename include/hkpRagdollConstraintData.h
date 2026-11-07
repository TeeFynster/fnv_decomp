#pragma once

#include "hkpConstraintData.h"
#include "hkpRagdollConstraintDataAtoms.h"
#include "hkBool.h"

class hkTransform;
class hkVector4;
class hkRotation;

class hkpRagdollConstraintData : public hkpConstraintData
{
public:
    enum MotorIndex
    {
        MOTOR_TWIST = 0,
        MOTOR_PLANE = 1,
        MOTOR_CONE = 2
    };

    virtual ~hkpRagdollConstraintData() throw();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual int getType() const throw();
    virtual void GetConstraintRuntimeInfo(hkBool wantRuntime, RuntimeInfoD4D& infoOut) const throw();
    virtual void v0A();
    virtual void AddInstance(hkpConstraintInstance* instance, void* runtime, unsigned int runtimeSize);
    virtual void v0C();
    virtual unsigned char* WantsRuntime(unsigned char* result);
    virtual void v0E();
    virtual void PopulateInfo(hkpConstraintDataInfo& infoOut) const;

    void vf03(float fFirst);
    float vf04();
    void vf05(int iBitIndex);
    int vf06();
    hkBool vf07() const;
    int vf08();
    void vf09(int* pUnused, int* pOut);
    int vf10(int iFirst);
    void vf11(int iFirst, int iBuffer, int iLength);
    void vf12(int iFirst, int iSecond);
    void vf13(unsigned char* sOutput);
    void vf14(int iFirst);
    char* vf15(int iIndex);

    // frames given in body space of A and B, or derived from world-space axes and the bodies' transforms
    void setInBodySpace(const hkVector4& kPivotA, const hkVector4& kPivotB,
                        const hkVector4& kPlaneAxisA, const hkVector4& kPlaneAxisB,
                        const hkVector4& kTwistAxisA, const hkVector4& kTwistAxisB);
    void setInWorldSpace(const hkTransform& kBodyATransform, const hkTransform& kBodyBTransform,
                         const hkVector4& kPivot, const hkVector4& kTwistAxisW, const hkVector4& kPlaneAxisW);
    hkBool isValid_00cdf090() const;
    void getConstraintFrameA(hkRotation* pOut);
    void getConstraintFrameB(hkRotation* pOut);
    void setPlaneAngularLimit(float fStart, float fEnd);

    char padC[0x4];
    hkpRagdollConstraintDataAtoms m_kBridgeAtoms;
};
