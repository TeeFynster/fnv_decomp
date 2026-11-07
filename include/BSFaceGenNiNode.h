#pragma once

#include "NiNode.h"

class BSFaceGenAnimationData;

class BSFaceGenNiNode : public NiNode
{
  public:
    BSFaceGenNiNode();
    virtual ~BSFaceGenNiNode();
    virtual const NiRTTI* GetRTTI() const;

    virtual BSFaceGenAnimationData* GetAnimationData();
    virtual void SetAnimationData(BSFaceGenAnimationData* apData);
    virtual void Unk_108();
    virtual void Unk_10C();
    virtual void Unk_110();
    virtual void SetAnimationUpdate(bool abUpdate);
    virtual void Unk_118();
    virtual void SetApplyRotToParent(bool abApply);
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();

    char GetFixedNormals();
    void SetFixedNormals(bool abFixedNormals);
    void UpdateFaceGenAnimation(NiUpdateData* apUpdateData);
    void UpdateFaceGenAnimation(NiUpdateData& arUpdateData);
    void BSFaceGenNiNode_UpdateAllChildrenMorphData(bool abUpdate);

    void BSMultiBoundRoom_SetCullResult(unsigned int uiFlags);
    void SceneGraph_SetCameraFOV(float f, int a, void* b, int c);
    void StopMoving(bool stop);
    void SetApplyRotToParent(int apply);

    static const NiRTTI ms_kRTTI;

    NiPointer<BSFaceGenAnimationData> spAnimationData;
    char padB0[0x26];
    bool bAnimationUpdate;
    char padD7[1];
    bool bApplyRotationToParent;
    char padD9[0x17];
};
