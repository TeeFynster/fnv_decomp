#pragma once

#include "NiPSysCollider.h"
#include "NiPlane.h"
#include "NiPoint3.h"
#include "NiMatrix3.h"
#include "NiTransform.h"

class NiPSysPlanarCollider : public NiPSysCollider
{
public:
    virtual void LoadBinary(NiStream& stream);

    void CopyMemberData(NiPSysPlanarCollider* destination, CloningProcess& cloning);

    NiAVObject* m_pkColliderObject;
    float m_fOriginX;
    float m_fOriginZ;
    NiPoint3 m_kFirstVector;
    NiPoint3 m_kSecondPlaneVector;
    float m_fWidthSquared;
    float m_fHeightSquared;
    NiPlane m_kHalfSpacePlane;
    NiPoint3 m_kPathOffset;
    unsigned char layoutPadding74[12];
    NiMatrix3 m_kRotationMatrix;
    unsigned char unkA4[12];
    NiTransform m_kFirstTransform;
    unsigned char unkE4[12];
    NiTransform m_kSecondTransform;
    unsigned char unk124[12];
};
