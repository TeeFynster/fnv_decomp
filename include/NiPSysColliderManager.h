#pragma once

#include "NiPSysModifier.h"

class NiPSysCollider;
struct StrArr;

class NiPSysColliderManager : public NiPSysModifier
{
public:
    virtual ~NiPSysColliderManager();

    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual void ProcessClone(CloningProcess& process);
    virtual void Update(float time, NiPSysData* data);

    void CloneCollider(NiPSysColliderManager* destination, CloningProcess& process);
    void* ReleaseCollider(unsigned int flags);
    using NiPSysModifier::GetViewerStrings;

    NiPSysCollider* m_pFirstCollider;
};
