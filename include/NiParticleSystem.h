#pragma once

#include "NiParticles.h"
#include "NiTransform.h"

class NiPSysData;
class NiPSysModifier;
class NiStream;
class NiUpdateData;
class StrArr;

class NiParticleSystem : public NiParticles
{
  public:
    NiParticleSystem();
    virtual ~NiParticleSystem();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual void ProcessClone(CloningProcess& process);
    virtual void PostLinkObject(NiStream& stream);
    virtual void SetSelectiveUpdateFlags(bool& selectiveUpdate, bool transforms, bool& rigid);
    virtual void UpdateDownwardPass(NiUpdateData& data, unsigned int flags);
    virtual void UpdateSelectedDownwardPass(NiUpdateData& data, unsigned int flags);
    virtual void UpdateRigidDownwardPass(NiUpdateData& data, unsigned int flags);
    virtual void UpdateWorldData(NiUpdateData& data);
    virtual void UpdateWorldBound();
    virtual void UpdateSystem(float time);
    virtual void Update(float time);

    void NiLines_LinkObject(NiStream* stream);
    void InitializeNewParticle(unsigned short particle);
    void InitializeNewParticle(unsigned int particle);
    void PerformSystemReset();
    void Do_UpdateSystem(float time);
    void ProcessClone_00c1b060(CloningProcess& process);
    void CopyMembers_00c1b6f0(NiParticleSystem* destination, CloningProcess& process);
    NiParticleSystem* NiParticleSystem_00c1b5c0();
    void CopyMemberData(NiParticleSystem* destination, CloningProcess& process);
    void InsertSorted(NiPSysModifier* modifier);
    void LoadModifiers(NiStream* stream);
    void FindModifier();
    NiPSysModifier* GetModifier(const NiFixedString& name);
    void UpdateParticleSystem(NiUpdateData& data, unsigned int flags);
    void WriteParticleSystemInfo(StrArr* strings);

    union
    {
        bool m_bFlag;
        bool m_bC4;
        unsigned char m_c4;
    };
    unsigned char unkc5[3];
    union
    {
        NiTPointerList<NiPointer<NiPSysModifier> > m_kModifiers;
        NiTPointerList<NiPointer<NiPSysModifier> > m_kList;
    };
    union
    {
        float m_fLastTime;
        float m_fD4;
    };
    union
    {
        bool m_bHasAccumulation;
        bool m_bD8;
    };
    bool m_bD9;
    unsigned char unkda[2];
    NiTransform m_kUnmodifiedWorld;
};

typedef char NiParticleSystem_flag_offset_check[(offsetof(NiParticleSystem, m_bFlag) == 0xC4) ? 1 : -1];
typedef char NiParticleSystem_modifiers_offset_check[(offsetof(NiParticleSystem, m_kModifiers) == 0xC8) ? 1 : -1];
typedef char NiParticleSystem_time_offset_check[(offsetof(NiParticleSystem, m_fLastTime) == 0xD4) ? 1 : -1];
typedef char NiParticleSystem_reset_offset_check[(offsetof(NiParticleSystem, m_bHasAccumulation) == 0xD8) ? 1 : -1];
typedef char NiParticleSystem_bound_offset_check[(offsetof(NiParticleSystem, m_bD9) == 0xD9) ? 1 : -1];
typedef char NiParticleSystem_transform_offset_check[(offsetof(NiParticleSystem, m_kUnmodifiedWorld) == 0xDC) ? 1 : -1];
