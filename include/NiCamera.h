#pragma once

#include "NiAVObject.h"
#include "NiBound.h"

class NiRenderTargetGroup;

namespace teswater_detail
{
    class NiPoint3;
    class NiMatrix3;
}

#include "NiFrustum.h"

#include "NiRect.h"

class __declspec(novtable) NiCamera : public NiAVObject
{
  public:
    NiCamera();
    void UpdateWorldToCamera(); // exe 0x00a70ba0
    virtual ~NiCamera() {}

    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual void UpdateWorldData(NiUpdateData& update);
    virtual void UpdateWorldBound();

    const NiFrustum& GetViewFrustum() const;
    float GetMaxFarNearRatio() const;
    void SetMinNearPlaneDist(float fDist, bool bUpdate);
    void UpdateViewFrustum(const NiFrustum& frustum);
    void UpdateWorldFrustum();
    void Update(NiUpdateData& data);
    void Update(const NiUpdateData& data);
    NiPoint3 GetWorldTranslation() const;
    NiPoint3 GetWorldForwardVector() const;
    NiPoint3 GetWorldUpVector() const;
    const NiRect<float>& GetViewPort() const;
    unsigned int GetLODAdjust() const;
    NiPoint3 FUN_0045bba0();
    NiPoint3 FUN_0045bba0() const;
    NiPoint3 NiCamera_GetWorldRightVector();
    NiPoint3 NiCamera_GetWorldRightVector() const;
    int ClassifyPoint(const NiPoint3* point);
    bool WindowPixelToRay(long x, long y, NiPoint3& origin, NiPoint3& direction,
                          const NiRenderTargetGroup* group);
    void ScreenPointToRay(float x, float y, NiPoint3& origin, NiPoint3& direction);
    void MapScreenToRay(int x, int y, NiPoint3& origin, NiPoint3& direction, bool flag);
    bool AimAt(const NiPoint3& point, const NiPoint3& up);
    bool SetLookAt(const NiPoint3& point, const NiPoint3& up);
    void GetScreenSpaceBounds(const NiBound& bound, NiPoint3& minimum, NiPoint3& maximum,
                             float tolerance);

    using NiAVObject::NiAVObject_SetTranslate;
    using NiAVObject::SetRotate_0043fa80;
    using NiAVObject::NiAVObject_GetWorldTranslate;
    void NiAVObject_SetTranslate(const NiPoint3& point);
    void NiAVObject_SetTranslate(const teswater_detail::NiPoint3& point);
    void SetRotate_0043fa80(const NiMatrix3* rotation);
    void SetRotate_0043fa80(const teswater_detail::NiMatrix3* rotation);
    void NiAVObject_SetScale(float scale);
    void* TESDataHandler_GetImpactDataSetList();
    void NiCamera_SetMaxFarNearRatio(float ratio);
    void FUN_00712e60(const NiRect<float>& viewport);
    void FUN_00a6faf0(const NiFrustum& frustum);
    bool FitNearAndFarToBound(const NiBound& bound);
    const NiPoint3& NiAVObject_GetWorldTranslate() const;
    const NiMatrix3& NiAVObject_GetWorldRotate() const;
    float NiAVObject_GetWorldScale() const;
    void UpdateFields_00a6fae0();

    float m_aafWorldToCam[4][4];
    NiFrustum m_kViewFrustum;
    float m_fMinNearPlaneDist;
    float m_fMaxFarNearRatio;
    NiRect<float> m_kPort;
    float m_fLODAdjust;
};
