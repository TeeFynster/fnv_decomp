#pragma once

#include "BSNiNode.h"
#include "BSMultiBound.h"

class BSMultiBound;
class BSOcclusionPlane;

class BSMultiBoundNode : public BSNiNode
{
public:
    BSMultiBoundNode();
    virtual ~BSMultiBoundNode();

    virtual const NiRTTI* GetRTTI() const;
    virtual BSMultiBoundNode* IsMultiBoundNode() const;
    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual void UpdateDownwardPass(NiUpdateData& data, unsigned int flags);
    virtual void UpdateWorldBound();
    virtual void OnVisible(NiCullingProcess& culler);
    virtual void UpdateUpwardPass();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();

    void SetMultiBound(BSMultiBound* bound);
    bool CheckProcStateAndPlane(NiPoint3 viewPoint, NiCullingProcess& culler, BSOcclusionPlane* plane);
    void CopyMemberData(BSMultiBoundNode* destination, CloningProcess& cloning);
    void CopyMembers_00c1b6f0(BSMultiBoundNode* pDest, CloningProcess& kCloning);
    void UpdateDownwardPass_00c3a5b0(NiUpdateData& data, unsigned int flags);

public:
    BSMultiBound* spMultiBound;
    unsigned int unkB0;
};
