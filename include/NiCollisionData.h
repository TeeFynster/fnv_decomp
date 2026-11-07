#pragma once

#include "NiCollisionObject.h"
#include "NiBoundingVolume.h"
#include "NiPoint3.h"
#include "StrArr.h"

class NiCollisionData : public NiCollisionObject
{
  public:
    NiCollisionData();
    virtual ~NiCollisionData();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& arCloning);
    virtual void LoadBinary(NiStream& arStream);
    virtual void LinkObject(NiStream& arStream);
    virtual bool RegisterStreamables(NiStream& arStream);
    virtual void SaveBinary(NiStream& arStream);
    virtual bool IsEqual(NiObject* apObject) const;
    virtual void GetViewerStrings(NiViewerStringsArray* apStrings);
    virtual void AddViewerStrings(NiViewerStringsArray* apStrings);
    virtual void SetSceneObject(NiAVObject*);
    virtual void Unk_24(NiUpdateData&);
    virtual NiPoint3 GetVelocity();

    void SetBoundingVolume(NiBoundingVolume* pkBV);
    void CreateTriData(int);
    void CloneCollisionData(NiCollisionData* pkDest, CloningProcess& kCloning);
    void* DestroyIfFlagged(unsigned int);
    void VirtAt64(StrArr*);
    void FUN_00a81100(StrArr*);
    void NiCollisionObject_CopyMembers(NiCollisionData*, CloningProcess&);
    void UpdateFields_00eacde0();
    void CreateWorldVertices();
    void UpdateWorldVertices();
    void SetSceneGraphObject(NiAVObject* pkSceneObject);
    void FUN_00ead760(NiStream&);
    void GetViewerStrings_00ead870(StrArr*);

    NiPoint3 m_kLocalVelocity;
    NiPoint3 m_kWorldVelocity;
    int m_ePropagationMode;
    int m_eCollisionMode;
    NiBoundingVolume* m_pkModelABV;
    NiBoundingVolume* unk30;
    void* m_pCollisionObject;
    unsigned int unk38;
    unsigned int unk3C;
    void* m_pWorldVertices;
    void* unk44;
    unsigned char unk48;
    unsigned char unk49;
    unsigned short unk4A;
    unsigned short unk4C;
    unsigned char unk4E;
    unsigned char unk4F;
};
