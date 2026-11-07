#pragma once

#include "NiPSysModifierCtlr.h"
#include "NiTPrimitiveSet_float_.h"

class NiPSysEmitterCtlr : public NiPSysModifierCtlr
{
public:
    NiPSysEmitterCtlr();
    NiPSysEmitterCtlr(const char* name) throw();
    virtual ~NiPSysEmitterCtlr();


    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual void ProcessClone(CloningProcess& process);
    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void SetInterpolator(NiInterpolator* interpolator, unsigned short index);
    virtual void vf60();

    void CopyMemberData(NiPSysEmitterCtlr* destination, CloningProcess& process);
    void BSPSysMultiTargetEmitterCtlr_CopyMembers(NiPSysEmitterCtlr* destination, void* process);
    NiPSysEmitterCtlr* BSPSysMultiTargetEmitterCtlr_CreateClone(void* process);

    NiPointer<NiInterpolator> m_spVisibilityInterpolator;
    NiInterpolator* m_pEmitterActiveInterpolator;
    float m_fScaledLastTime;
    bool m_bIsInitialized;
    unsigned char layoutPadding4D[3];
    NiTPrimitiveSet_float_ m_kBirthRateKeys;
};
