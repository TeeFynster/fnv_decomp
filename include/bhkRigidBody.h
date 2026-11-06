#pragma once

#include "bhkEntity.h"
#include "MagicTarget.h"
#ifndef FNV_LAYOUT_SUPPORT_H
#include "NiAVObject.h"
#endif
#include "hkpMotion.h"

class NiPoint3;
class NiQuaternion;
class hkQuaternion;
class hkAabb;
class hkTransform;

class bhkRigidBody : public bhkEntity
{
public:
    BSSimpleList<NiPointer<bhkSerializable> > m_kSerializableList;

    virtual const NiRTTI* GetRTTI() const;
    virtual unsigned int slotA8();

    virtual NiPoint3& GetPosition(NiPoint3&);
    virtual NiQuaternion& GetRotation(NiQuaternion&);
    virtual void SetPosition(const NiPoint3&);
    virtual void SetRotation(const NiQuaternion&);
    virtual bool vf57(hkpMotion::MotionType);
    virtual void FUN_00c8d1d0(const NiPoint3&, const NiQuaternion&);
    virtual NiPoint3& FUN_00c8d200(NiPoint3&);
    virtual NiPoint3& GetVec(NiPoint3&);
    virtual hkTransform& vf61(hkTransform&);
    virtual void vf62(hkAabb&);
    virtual void vf63(bool);

    unsigned int GetInstanceSize();
    const __m128& PositionVector();
    const __m128& RotationVector();
    float GetBodyMass();
    hkpMotion* FUN_005d3d10();
    float FUN_004b5400();
    void* FUN_00c87a50();
    const __m128& FUN_00c8d200();
    const __m128& FUN_00c8d240();
    void FUN_00560bc0(NiPoint3&);
    void FUN_00560c20(hkVector4&);
    bool FUN_005609b0();
    int FUN_00517630();
    bool IsNonZero(int);
    void FUN_00560d50(NiPoint3&);
    void FUN_00560de0(NiPoint3&);
    void FUN_00c8de20(const hkVector4&, const hkQuaternion&, float, float);
    void FUN_00c859e0(NiStream*);
    void FUN_00c8ef80(NiObject*);
    void ProcessListNodes();
    void FUN_00c8eb00();
    void FUN_00c9d590();
    void FUN_00c8f3c0(NiStream*);
    static NiObject* __cdecl CreateObject();
};
