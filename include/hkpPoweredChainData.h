#pragma once

#include <xmmintrin.h>
#include "hkpConstraintChainData.h"
#include "hkpBridgeAtoms.h"
#include "hkaAnimation.h"

class hkpPoweredChainDataConstraintInfo;
class hkMemoryRouter;
struct Motor;
struct Body;
class V4;
struct QueryInput;
struct QueryOutput;

class hkpPoweredChainData : public hkpConstraintChainData
{
public:
    struct RuntimeInfo
    {
        int offset;
        int stride;
    };

    hkpPoweredChainData() throw();
    hkpPoweredChainData(FinishingFlag flag);
    virtual ~hkpPoweredChainData() throw();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void GetRuntimeInfo(unsigned int wantRuntime, void* runtimeInfo);
    virtual void v0A();
    virtual void AddInstance(hkpConstraintInstance* instance, void* runtime,
                             unsigned int runtimeSize);
    virtual void v0C();
    virtual unsigned char* WantsRuntime(unsigned char* result);
    virtual void v0E();
    virtual void PopulateInfo(hkpConstraintDataInfo& infoOut) const;
    virtual void vf16();

    int ReturnConstant_102();
    void getRuntimeInfo_00e3b770(int unused, RuntimeInfo* result);
    void buildJacobian_00e3ba40(const QueryInput& input, QueryOutput& output);
    void getConstraintInfo_00e3b720(int* info) const;

    hkMemoryRouter* hkMemoryRouter_getInstance();
    void addConstraintInfoInBodySpace(const __m128* frameA, const __m128* frameB,
                    const __m128* frameC, Motor* motorA, Motor* motorB,
                    Motor* motorC);
    void addConstraintInfoInBodySpace(void* frameA, void* frameB, void* frameC,
                    int motorA, int motorB, int motorC);
    void addConstraintInfoInBodySpace(const V4* frameA, const V4* frameB, const V4* frameC,
                    Body* motorA, Body* motorB, Body* motorC);

    hkpBridgeAtoms m_kBridgeAtoms;
    hkArray<hkpPoweredChainDataConstraintInfo> m_pConstraintInfo;
    hkReal m_fTau;
    hkReal m_fMotorDamping;
    hkReal m_fMaximumErrorDistance;
    hkReal m_fMaximumLinearImpulse;
    hkReal m_fBreachImpulse;
    hkReal m_fInertiaStabilizationFactor;
    hkReal m_fMaximumAngularImpulse;
};
