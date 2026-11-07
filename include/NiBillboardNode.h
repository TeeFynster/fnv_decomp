#pragma once

#include "NiNode.h"
#include "StrArr.h"

struct BoardObject;
struct BoardVector;
struct BillboardClone;

class NiBillboardNode : public NiNode
{
  public:
    NiBillboardNode();
    virtual ~NiBillboardNode();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void LoadBinary(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual void UpdateDownwardPass(NiUpdateData& data, unsigned int flags);
    virtual void UpdateSelectedDownwardPass(NiUpdateData& data, unsigned int flags);
    virtual void UpdateRigidDownwardPass(NiUpdateData& data, unsigned int flags);
    virtual void UpdateWorldBound();
    virtual void OnVisible(NiCullingProcess& culler);

    using NiNode::MakeClone;
    using NiNode::IsEqual;
    using NiNode::UpdateDownwardPass;

    void ForwardCall_0051cfe0();
    void* Destroy(unsigned int flags);
    void NiAVObject_SetSelectiveUpdate(bool value);
    void SetMode_0051d000(int flags);
    void NiBillboardNode_SetUpdateControllers(int flags);

    void UpdateSelectedDownwardPass_00a7da80(NiUpdateData& data, unsigned int flags);
    void UpdateRigidDownwardPass_00a7dab0(NiUpdateData& data, unsigned int flags);
    void UpdateDownwardPass_00a7dae0(NiUpdateData& data, unsigned int flags);
    unsigned char IsEqual_00a7db30(NiObject* object);
    __declspec(noalias) bool NiBillboardNode_RotateToCenter(const BoardObject* camera, const BoardVector& position,
                                        BoardVector& worldPosition, BoardVector& up, BoardVector& right);
    void RotateToCamera(const BoardObject* camera);
    void RotateToCamera(NiCullingProcess* camera);
    void OnVisible_00a7e610(NiCullingProcess* process);
    void UpdateWorldBound_00a7e630();
    BillboardClone* CreateClone_00a7e710(void* context);
    void LoadBinary_00a7e7b0(NiStream& stream);
    void SaveBinary_00a7e850(NiStream& stream);
    void GetViewerStrings_00a7e890(StrArr* array);

    static const NiRTTI ms_kRTTI;

    unsigned int unkAC;
    unsigned int unkB0;
};
