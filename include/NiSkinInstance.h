#pragma once

#include "NiObject.h"
#include "NiAVObject.h"
#include "NiPointer.h"

class NiSkinData;
class NiSkinPartition;
class FaceObject;

class NiSkinInstance : public NiObject
{
  public:
    NiSkinInstance() throw();
    virtual ~NiSkinInstance();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& arCloning);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& arStream);
    virtual void SaveBinary(NiStream& arStream);
    virtual bool IsEqual(NiObject* apObject) const;
    virtual void GetViewerStrings(NiViewerStringsArray* apStrings);
    virtual void PostLinkObject(NiStream& arStream);

    bool IsCloneable(CloningProcess& kCloning);
    void CopyMemberData(NiSkinInstance* pkDest, CloningProcess& kCloning);
    NiSkinInstance* FUN_00a86830(CloningProcess& kCloning);

    NiSkinData* GetSkinData();
    NiSkinData* GetData();
    NiAVObject** GetBones();
    NiSkinPartition* GetSkinPartition();
    NiSkinPartition* FUN_0043b230();
    void FUN_004addc0(NiSkinPartition* pPartition);
    void FUN_004addc0(NiSkinInstance*);
    FaceObject** FUN_00825c00();
    void __thiscall FUN_00a85580();
    void* __thiscall FUN_006885a0(unsigned int flags);
    void SetRootParent(NiNode* rootParent);
    void SetBone(unsigned int index, NiAVObject* bone);
    void SetBone(unsigned int index, FaceObject* bone);
    FaceObject* GetControllers() const;
    void __thiscall EnsureSkinPartition(NiGeometry* geometry);

    static const NiRTTI ms_kRTTI;

    NiPointer<NiObject> m_pSkinData;
    NiPointer<NiObject> m_pkSkinMeshPartition;
    NiObject* m_pRootParent;
    NiObject** m_ppBones;
};
