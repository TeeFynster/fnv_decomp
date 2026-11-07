#pragma once

#include "NiObject.h"
#include "NiFixedString.h"

class NiPSysData;
class NiParticleSystem;

class NiPSysModifier : public NiObject
{
public:
    NiPSysModifier();
    NiPSysModifier(const NiFixedString& name, unsigned int order) throw(); // exe 0x00c316a0

    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void ProcessClone(CloningProcess& process);

    virtual void Update(float time, NiPSysData* data);
    virtual void Initialize(NiPSysData* data, unsigned short newParticle);
    virtual void HandleReset();
    virtual void SetActive(bool active);
    virtual void SetTargetSystem(NiParticleSystem* target);
    virtual bool IsDeferred() const;

    void CopyMemberData(NiPSysModifier* destination, CloningProcess& process);
    void BSWindModifier_LinkObject(NiStream& stream);
    void __thiscall BSPSysStripUpdateModifier_CopyMembers(NiPSysModifier* apDest, CloningProcess& apProcess);
    void NiPSysPositionModifier_LoadBinary(NiStream& stream);
    void FUN_00c31950(NiStream& stream);
    const NiFixedString& GetName() const;
    void SetName(const NiFixedString& name);
    unsigned int GetOrder() const;
    NiParticleSystem* GetSystemPointer();
    bool GetActive() const;

    NiFixedString m_kName;
    unsigned int m_uiUpdateOrder;
    NiParticleSystem* m_pkTarget;
    bool m_bModifierActive;
    unsigned char unk15[3];
};
