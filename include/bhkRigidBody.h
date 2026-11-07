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
    virtual void SetPosRot(const NiPoint3&, const NiQuaternion&);
    virtual NiPoint3& GetCenterOfMassLocal_00c8d200(NiPoint3&);
    virtual NiPoint3& GetVec(NiPoint3&);
    virtual hkTransform& vf61(hkTransform&);
    virtual void vf62(hkAabb&);
    virtual void vf63(bool);

    unsigned int GetInstanceSize();
    const __m128& PositionVector();
    const __m128& RotationVector();
    float GetBodyMass();
    hkpMotion* hkpRigidBody_getStoredDynamicMotion();
    float bhkRigidBody_GetMass();
    void* bhkWorldObject_GethkWorldRw();
    const __m128& GetCenterOfMassLocal_00c8d200();
    const __m128& FUN_00c8d240();
    void bhkRigidBody_GetPosition(NiPoint3&);
    void bhkRigidBody_GetRotation(hkVector4&);
    bool IsActive_005609b0();
    int bhkRigidBody_GetMotionType();
    bool IsNonZero(int);
    void bhkRigidBody_GetLinearVelocity(NiPoint3&);
    void bhkRigidBody_GetAngularVelocityNi(NiPoint3&);
    void bhkRigidBody_ApplyKeyframe(const hkVector4&, const hkQuaternion&, float, float);
    void bhkWorldObject_LinkObject(NiStream*);
    void bhkRigidBody_AddActCon(NiObject*);
    void ProcessListNodes();
    void Remove_00c8eb00();
    void bhkEntity_Remove();
    void LinkObject_00c8f3c0(NiStream*);
    static NiObject* __cdecl CreateObject();
};
