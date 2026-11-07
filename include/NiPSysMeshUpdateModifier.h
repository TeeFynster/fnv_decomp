#pragma once

#include <stddef.h>
#include "NiPSysModifier.h"
#include "NiNode.h"

class StrArr;

class NiPSysMeshUpdateModifier : public NiPSysModifier
{
public:
    NiPSysMeshUpdateModifier() throw();
    virtual ~NiPSysMeshUpdateModifier();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& arCloning);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* apStrings);
    virtual void ProcessClone(CloningProcess& process);
    virtual void PostLinkObject(NiStream& arStream);
    virtual void Update(float time, NiPSysData* data);
    virtual void Initialize(NiPSysData* data, unsigned short newParticle);

    static NiObject* CreateModifier();

    NiAVObject* GetMeshAt(unsigned int index);
    void SetMeshAt(unsigned int index, NiAVObject* mesh, NiPointer<NiAVObject>& previous);
    unsigned int GetMeshCount();
    void AppendString(StrArr* strings);
    void CopyMemberData(NiPSysMeshUpdateModifier* destination, CloningProcess& process);
    NiPSysMeshUpdateModifier& operator=(const NiPSysMeshUpdateModifier& other);
    void Init();
    void ProcessClone_00c20f30(CloningProcess& process);
    bool RegisterStreamables_00c20f80(NiStream& stream);
    NiPSysMeshUpdateModifier* FUN_00c21890(CloningProcess& process);

    NiTObjectArray<NiPointer<NiAVObject> > m_kSceneObjects; // 0x18
};

typedef char NiPSysMeshUpdateModifier_size_check[(sizeof(NiPSysMeshUpdateModifier) == 0x28) ? 1 : -1];
typedef char NiPSysMeshUpdateModifier_scene_objects_offset_check[(offsetof(NiPSysMeshUpdateModifier, m_kSceneObjects) == 0x18) ? 1 : -1];
