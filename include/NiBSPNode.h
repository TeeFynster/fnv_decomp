#pragma once

#include "NiNode.h"
#include "NiPlane.h"
#include "NiSphere.h"

struct BSPMatrix;

class NiBSPNode : public NiNode
{
public:
    virtual void ApplyTransform(const NiMatrix3& arRotation, const NiPoint3& arPosition, bool abOnLeft);

    void LoadBinary_00a9a710(NiStream& stream);
    void SaveBinary_00a9a740(NiStream& stream);
    void __thiscall UpdateWorldData_00a9a840(NiUpdateData& data);
    void __thiscall UpdateWorldPlane();
    void NiBSPNode_ApplyTransform(const NiMatrix3& kMat, const NiPoint3& kTrn, bool bOnLeft);
    void NiBSPNode_ApplyTransform(const BSPMatrix& kMat, const NiPoint3& kTrn, bool bOnLeft);
    void AddPlaneConst(const NiPoint3& kTrn);
    void ApplyPlane(const NiMatrix3& kMat, const NiPoint3& kTrn);
    void ApplyPlane(const BSPMatrix& kMat, const NiPoint3& kTrn);
    void ApplyPlane2(const NiMatrix3& kMat, const NiPoint3& kTrn);
    void ApplyPlane2(const BSPMatrix& kMat, const NiPoint3& kTrn);

    NiPlane& GetModelPlane()
    {
        return *reinterpret_cast<NiPlane*>(&m_pSphere);
    }
    const NiPlane& GetModelPlane() const
    {
        return *reinterpret_cast<const NiPlane*>(&m_pSphere);
    }

    NiSphere m_pSphere;
    // VC9 cannot put a plane with a user-defined constructor in an anonymous union.
    __declspec(property(get=GetModelPlane)) NiPlane m_kModelPlane;
    NiPlane m_kWorldPlane;
};
