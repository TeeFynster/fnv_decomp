#pragma once

#include "NiFloatInterpController.h"

class BSFrustumFOVController : public NiFloatInterpController
{
public:
    virtual ~BSFrustumFOVController();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual void Update(NiUpdateData& update);
    virtual bool TargetIsRequired(NiObjectNET* object) const;
    virtual void UpdateFloatValue(float* value);

    void CopyMemberData(BSFrustumFOVController* clone, CloningProcess* process);
    void CopyMemberData();
    void GetFieldOfView(float& fValue);

    static NiObject* CreateObject();
};
