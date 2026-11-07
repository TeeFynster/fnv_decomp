#pragma once

#include "NiCamera.h"

class NiGeometry;
class NiNodeX;
class NiVisibleArray;

class NiCullingProcess
{
  public:
    NiCullingProcess(NiVisibleArray* pkVisibleSet);

    virtual void* GetRTTI();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void Process(NiAVObject* object);
    virtual void Slot18();
    virtual void Append(NiGeometry* geometry);

    const NiCamera* GetCamera() const;
    void NiCullingProcess_SetFrustum(void* p);
    void BSCullingProcess_Process_00c4f070(NiNodeX* a, NiAVObject* b, int c);

    // Gamebryo's members (allocations of the derived cullers: 0x90 bytes up to BSCullingProcess's own at +0x90).
    const bool m_bUseVirtualAppend;  // +0x04
    void* m_pkVisibleSet;            // +0x08 the NiVisibleArray culled into
    const NiCamera* m_pkCamera;      // +0x0c
    NiFrustum m_kFrustum;            // +0x10
    // +0x2c Gamebryo's NiFrustumPlanes m_kPlanes: six NiPlanes (normal, constant) and the active plane mask.
    // NiFrustumPlanes is defined in ShadowSceneLight.h and several units define their own NiPlane, both after
    // this header, so the member spells the same layout out here.
    struct
    {
        struct
        {
            NiPoint3 m_kNormal;
            float m_fConstant;
        } m_akPlanes[6];
        unsigned int m_uiActivePlaneMask;
    } m_kPlanes;
};
