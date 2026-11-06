#pragma once

#include <stddef.h>
#include "hkVector4.h"
#include "hkMatrix3.h"

class hkpVelocityAccumulator
{
public:
    unsigned char m_type;
    unsigned char m_iValueAtOffset0C;
    unsigned char unk02;
    unsigned char unk03;
    unsigned int m_uiDeactivationClass;
    float m_fGravityFactor;
    unsigned int unk0C;
    hkVector4 m_vLinearVelocity;
    hkVector4 m_vAngularVelocity;
    hkVector4 m_vInverseInertiaAndMass;
    hkVector4 m_vCenterOfMass;
    hkVector4 m_scratch1;
    hkVector4 m_scratch2;
    hkVector4 m_scratch3;

    __forceinline hkMatrix3& getCoreFromWorldMatrix()
    {
        return reinterpret_cast<hkMatrix3&>(m_scratch1);
    }
    __forceinline const hkMatrix3& getCoreFromWorldMatrix() const
    {
        return reinterpret_cast<const hkMatrix3&>(m_scratch1);
    }
    __declspec(property(get = getCoreFromWorldMatrix)) hkMatrix3 m_kCoreFromWorldMatrix;

    __forceinline const hkVector4& getScratch0() const { return m_vCenterOfMass; }
    __forceinline const hkVector4& getScratch1() const { return reinterpret_cast<const hkVector4&>(m_kCoreFromWorldMatrix.getColumn(0)); }
    __forceinline const hkVector4& getSumLinearVel() const { return getScratch0(); }
    __forceinline const hkVector4& getSumAngularVel() const { return getScratch1(); }

    void setFixed()
    {
        m_fGravityFactor = 0.0f;
        m_type = 1;
        m_vInverseInertiaAndMass.setZero4();
        m_vLinearVelocity.setZero4();
        m_vAngularVelocity.setZero4();
        m_vCenterOfMass.setZero4();
        m_scratch1.setZero4();
        m_scratch2.setZero4();
        m_scratch3.setZero4();
    }
};

typedef char hkpVelocityAccumulator_type_offset_check[(offsetof(hkpVelocityAccumulator, m_type) == 0x00) ? 1 : -1];
typedef char hkpVelocityAccumulator_value_offset_check[(offsetof(hkpVelocityAccumulator, m_iValueAtOffset0C) == 0x01) ? 1 : -1];
typedef char hkpVelocityAccumulator_unk02_offset_check[(offsetof(hkpVelocityAccumulator, unk02) == 0x02) ? 1 : -1];
typedef char hkpVelocityAccumulator_unk03_offset_check[(offsetof(hkpVelocityAccumulator, unk03) == 0x03) ? 1 : -1];
typedef char hkpVelocityAccumulator_deactivation_offset_check[(offsetof(hkpVelocityAccumulator, m_uiDeactivationClass) == 0x04) ? 1 : -1];
typedef char hkpVelocityAccumulator_gravity_offset_check[(offsetof(hkpVelocityAccumulator, m_fGravityFactor) == 0x08) ? 1 : -1];
typedef char hkpVelocityAccumulator_unk0C_offset_check[(offsetof(hkpVelocityAccumulator, unk0C) == 0x0C) ? 1 : -1];
typedef char hkpVelocityAccumulator_linear_offset_check[(offsetof(hkpVelocityAccumulator, m_vLinearVelocity) == 0x10) ? 1 : -1];
typedef char hkpVelocityAccumulator_angular_offset_check[(offsetof(hkpVelocityAccumulator, m_vAngularVelocity) == 0x20) ? 1 : -1];
typedef char hkpVelocityAccumulator_inertia_offset_check[(offsetof(hkpVelocityAccumulator, m_vInverseInertiaAndMass) == 0x30) ? 1 : -1];
typedef char hkpVelocityAccumulator_center_offset_check[(offsetof(hkpVelocityAccumulator, m_vCenterOfMass) == 0x40) ? 1 : -1];
typedef char hkpVelocityAccumulator_scratch1_offset_check[(offsetof(hkpVelocityAccumulator, m_scratch1) == 0x50) ? 1 : -1];
typedef char hkpVelocityAccumulator_scratch2_offset_check[(offsetof(hkpVelocityAccumulator, m_scratch2) == 0x60) ? 1 : -1];
typedef char hkpVelocityAccumulator_scratch3_offset_check[(offsetof(hkpVelocityAccumulator, m_scratch3) == 0x70) ? 1 : -1];
