#pragma once

#include "NiInterpController.h"
#include "NiBlendTransformInterpolator.h"

class NiMultiTargetTransformController : public NiInterpController
{
public:
    NiMultiTargetTransformController();
    NiMultiTargetTransformController(unsigned short n);
    virtual ~NiMultiTargetTransformController();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual void ProcessClone(CloningProcess& process);
    virtual void Update(NiUpdateData& update);
    virtual void SetTarget(NiObjectNET* target);

    virtual unsigned short GetTargetCount() const;
    virtual const char* GetTargetName(unsigned short index) const;
    virtual unsigned short GetTargetIndex(const char* id) const;
    virtual unsigned short GetTargetIndex(const NiFixedString& id) const;
    virtual NiInterpolator* GetInterpolator(unsigned short index) const;
    virtual void SetInterpolator(NiInterpolator* interpolator, unsigned short index);
    virtual void AdvanceControllerTime();
    virtual const char* GetControllerID() const;
    virtual NiInterpolator* GetInterpolatorAtIndex(unsigned short index);
    virtual void SetInterpolatorForTarget(NiInterpolator* interpolator, unsigned short index);
    virtual NiBlendInterpolator* GetBlendInterpolator(unsigned short index, bool managerControlled,
                                                     bool accumulateAnimations, float threshold, unsigned char size);
    virtual void SetActiveTimeRange(float startTime, float endTime);
    virtual bool ControlsTransform(NiInterpolator* interpolator, unsigned short index) const;

    void UpdateInterpolatorsAtTime(float time, bool selective);
    unsigned short GetNumTargets() const;
    NiBlendTransformInterpolator* GetBlendInterpolator(unsigned short index);
    NiAVObject* GetTarget(unsigned short index) const;
    unsigned short FindTarget(NiAVObject* target) const;
    unsigned short AddTarget(NiAVObject* target);
    unsigned short FindIndexByValue(NiAVObject* target);
    void SetInterpolatorTarget(unsigned short index, NiAVObject* target);
    void CopyMemberData(NiMultiTargetTransformController* clone, CloningProcess& process);
    void AllocateStorage(unsigned short n);
    void ClearInterpolators();

    NiBlendTransformInterpolator* m_pkBlendInterpolators;
    NiAVObject** m_ppTargetObjects;
    unsigned short m_usNumInterps;
    unsigned char unk3E[2];
};
