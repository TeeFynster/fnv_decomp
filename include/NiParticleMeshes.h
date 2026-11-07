#pragma once

#include "NiParticles.h"

struct StrArr2;

class NiParticleMeshes : public NiParticles
{
  public:
    NiParticleMeshes();
    virtual ~NiParticleMeshes();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual void SetSelectiveUpdateFlags(bool& selectiveUpdate, bool transforms, bool& rigid);
    virtual void UpdateDownwardPass(NiUpdateData& data, unsigned int flags);
    virtual void UpdateSelectedDownwardPass(NiUpdateData& data, unsigned int flags);
    virtual void UpdateRigidDownwardPass(NiUpdateData& data, unsigned int flags);
    virtual void UpdatePropertiesDownwardPass(NiPropertyState* parentState);
    virtual void UpdateWorldData(NiUpdateData& data);
    virtual void PurgeRendererData(NiRenderer* renderer);
    virtual void RenderImmediate(NiRenderer* renderer);

    void Init();
    void* Delete(unsigned int flags);
    void UpdatePropertyState(NiPropertyState* parentState);
    void FUN_00a59f90(NiUpdateData* data, int flags);
    void UpdateDownwardPassIfSelective(NiUpdateData& data);
    void RenderTarget(NiRenderer* renderer);
    void NiParticleMeshes_CopyMembers(NiParticleMeshes* object, void* arg);
    NiParticleMeshes* CreateAndInitObj(void* arg);
    void NiParticles_GetViewerStrings(StrArr2* strings);
    void AppendString(StrArr2* strings);
    void Object_DoNothing();

    float m_fLastTime;
    bool m_bUpdate;
    char unkC9[3];

    static const void* vftable;
};

typedef char NiParticleMeshes_size_check[(sizeof(NiParticleMeshes) == 204) ? 1 : -1];
typedef char NiParticleMeshes_last_time_offset_check[(offsetof(NiParticleMeshes, m_fLastTime) == 0xC4) ? 1 : -1];
typedef char NiParticleMeshes_update_offset_check[(offsetof(NiParticleMeshes, m_bUpdate) == 0xC8) ? 1 : -1];
