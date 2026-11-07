#pragma once

#include "NiBoundingVolume.h"
#include "NiPlane.h"
#include "NiPoint3.h"
#include "NiPoint3.h"

class AffineMatrix;
class NiPlane4;

class NiHalfSpaceBV : public NiBoundingVolume
{
public:
    union
    {
        struct
        {
            NiPlane m_kHalfSpacePlane;
        };
        struct
        {
            char unk04;
            char pad[15];
        };
    };
    NiPoint3 m_kCenter;

    NiHalfSpaceBV(const NiPoint3& akPoint, const NiPoint3& kNormal);

    virtual void LoadBinary(NiStream& kStream);
    virtual void __thiscall SaveBinary(NiStream& kStream);
    virtual ~NiHalfSpaceBV();
    virtual int F3() const;
    virtual void v10();
    virtual void v5(NiBoundingVolume*, void*);
    virtual NiBoundingVolume* v6();
    virtual NiBoundingVolume* Clone();
    virtual void Copy(const NiBoundingVolume& kABV);
    virtual int IsEqual(const NiBoundingVolume& kABV) const;
    virtual void v28();
    virtual void AddViewerStrings(char* pcPrefix, NiTPrimitiveArray<char*>* pkStrings);

    void SetFromPlane(const NiPlane* source);
    void SetFromPlane(const NiPlane& source);
    void TransformPlane(const NiHalfSpaceBV& source, const AffineMatrix& matrix);
    void TransformPlane(const NiPlane4& source, const AffineMatrix& matrix);
    int MatchesBoundingVolume(const NiBoundingVolume& kABV) const;

    void LoadBinary_00e9cb50(NiStream& stream);
    void SaveBinary_00e9cb80(NiStream& stream);
    NiBoundingVolume* NiHalfSpaceBV_00e9e680(const NiPoint3& akPoint, const NiPoint3& kNormal);
    NiBoundingVolume* Clone_00e9e730();
    void SetWaterColorParameter();
};
