#ifndef FNV_BHKRIGIDBODY_WORKER_H
#define FNV_BHKRIGIDBODY_WORKER_H

#include "../../include/NiRTTI.h"
#include "../../include/bhkRigidBody.h"

#include "bhkrigidbody_worker_decls.h"
extern NiRTTI DAT_012681c0;

#pragma optimize("", off)
// @fnv 0x0056d530
const NiRTTI* bhkRigidBody::GetRTTI() const
{
    return &DAT_012681c0;
}

// @fnv 0x0056d540
unsigned int bhkRigidBody::GetInstanceSize()
{
    return 0xe0;
}

#pragma optimize("", on)
// @fnv 0x00c8d170
void bhkRigidBody::SetPosition(const NiPoint3& p)
{
    if (this)
    {
        hkpRigidBody* body = (hkpRigidBody*)m_pHavokObject;
        if (body)
        {
            ((void(__thiscall*)(bhkRigidBody*))NiD3DDefaultShader::SetShaderName)(this);
            body->SetWorldPosition(p);
            ((void(__thiscall*)(bhkRigidBody*))NiD3DDefaultShader::SetShaderName)(this);
        }
    }
}
// @fnv 0x00c8d1a0
void bhkRigidBody::SetRotation(const NiQuaternion& p)
{
    if (this)
    {
        hkpRigidBody* body = (hkpRigidBody*)m_pHavokObject;
        if (body)
        {
            ((void(__thiscall*)(bhkRigidBody*))NiD3DDefaultShader::SetShaderName)(this);
            body->SetBodyOrientation(p);
            ((void(__thiscall*)(bhkRigidBody*))NiD3DDefaultShader::SetShaderName)(this);
        }
    }
}

#pragma optimize("", off)
// @fnv 0x0062ab20
float bhkRigidBody::GetBodyMass()
{
    hkpMotion* motion = hkpRigidBody_getStoredDynamicMotion();
    return motion ? motion->GetMassValue() : bhkRigidBody_GetMass();
}
#pragma optimize("", on)
__forceinline const __m128& bhkRigidBody::PositionVector()
{
    if (this && m_pHavokObject)
        return ((hkpRigidBodyMotionView*)m_pHavokObject)->m_vContactPosition;
    return *(__m128*)&DAT_01267e30;
}
#pragma optimize("t", on)
// @fnv 0x00c8d0f0
NiPoint3& bhkRigidBody::GetPosition(NiPoint3& p)
{
    *(bhkrigidbody_vector*)&p = (const bhkrigidbody_vector&)PositionVector();
    return p;
}
__forceinline const __m128& bhkRigidBody::RotationVector()
{
    if (this && m_pHavokObject)
        return ((hkpRigidBodyMotionView*)m_pHavokObject)->m_rotation;
    return *(__m128*)&DAT_012683b0;
}
#pragma optimize("t", on)
// @fnv 0x00c8d130
NiQuaternion& bhkRigidBody::GetRotation(NiQuaternion& p)
{
    *(bhkrigidbody_vector*)&p = (const bhkrigidbody_vector&)RotationVector();
    return p;
}

// @fnv 0x00c8f510
BhkRigidBody::BhkRigidBody()
{
    rigidBody.m_fSurfaceFriction = DAT_01022958;
    rigidBody.m_iAutoRemoveLevel = 0xff;
    rigidBody.m_fRestitution = DAT_010c60d8;
}
// @fnv 0x00c8d1d0
// src: XBOX_PDB 0x00c8d1d0
void bhkRigidBody::SetPosRot(const NiPoint3& p, const NiQuaternion& q)
{
    if (this)
    {
        hkpRigidBody* body = (hkpRigidBody*)m_pHavokObject;
        if (body)
        {
            bhkWorldObject_GethkWorldRw();
            body->SetPositionAndRotation(p, q);
        }
    }
}
__forceinline const __m128& bhkRigidBody::FUN_00c8d240()
{
    if (this && m_pHavokObject)
        return ((hkpRigidBodyMotionView*)m_pHavokObject)->m_vCenterOfMass1;
    return *(__m128*)&DAT_01267e30;
}
#pragma optimize("t", on)
// @fnv 0x00c8d240
NiPoint3& bhkRigidBody::GetVec(NiPoint3& p)
{
    *(bhkrigidbody_vector*)&p = (const bhkrigidbody_vector&)FUN_00c8d240();
    return p;
}
// src: XBOX_PDB 0x00c8d200
__forceinline const __m128& bhkRigidBody::GetCenterOfMassLocal_00c8d200()
{
    if (this && m_pHavokObject)
        return ((hkpRigidBodyMotionView*)m_pHavokObject)->m_vCenterOfMassLocal;
    return *(__m128*)&DAT_01267e30;
}
#pragma optimize("t", on)
// @fnv 0x00c8d200
// src: XBOX_PDB 0x00c8d200
NiPoint3& bhkRigidBody::GetCenterOfMassLocal_00c8d200(NiPoint3& p)
{
    *(bhkrigidbody_vector*)&p = (const bhkrigidbody_vector&)GetCenterOfMassLocal_00c8d200();
    return p;
}
#endif
