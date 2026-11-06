#pragma once

#include "NiObject.h"
#include "NiPoint3.h"
#include "NiAVObject.h"

class NiPSysSpawnModifier;
class NiPSysColliderManager;
class NiPSysData;
struct StrArr;

class NiPSysCollider : public NiObject
{
public:
    NiPSysCollider(float bounce, bool spawn, bool die, NiPSysSpawnModifier* spawnMod);

    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual void ProcessClone(CloningProcess& cloning);

    virtual NiPSysCollider* vf35(float time, float& collisionTime,
                               NiPSysData* data, unsigned short index);
    virtual void vf36(float time, NiPSysData* data, unsigned int index);
    virtual void vf37();

    void CreateVertexBufferSet(NiPSysCollider* collider, CloningProcess& cloning);
    NiPSysCollider* Clone(CloningProcess& cloning);

    float m_fBounceFactor;
    bool m_bSpawnOnCollision;
    bool m_bDieOnCollision;
    unsigned char layoutPaddingE[2];
    NiPSysSpawnModifier* m_pSpawnModifier;
    NiPoint3 m_kCollisionPosition;
    float m_fSpawnRate;
    NiPSysColliderManager* m_pColliderManager;
    NiPointer<NiPSysCollider> m_spNextController;
};
