
// src/havok/physics/dynamics/constraint/motor/position/hkppositionconstraintmotor.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/motor/position/hkppositionconstraintmotor.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpPositionConstraintMotor.h"
#include "../../../../../../../include/hkMemoryRouter.h"

struct MotorAllocator
{
    virtual void Release(void*);
    virtual void* Allocate(unsigned int size);
};
extern int DAT_010cb76c;
extern int DAT_010cb780;
extern int DAT_010cb798;
struct ReferencedMotorView
{
    void* m_ppVirtualMethodTable;
    unsigned short m_memorySizeAndFlags;
    short m_sReferenceCount;
};
struct ConstraintMotorView
{
    void* volatile m_ppVirtualMethodTable;
    unsigned short m_memorySizeAndFlags;
    short m_sReferenceCount;
    unsigned char m_motorType;
};
struct PositionConstraintMotor
{
    void* m_ppVirtualMethodTable;
    unsigned short m_memorySizeAndFlags;
    short m_sReferenceCount;
    unsigned char m_motorType;
    unsigned char m_reserved09;
    unsigned char m_reserved0A;
    unsigned char m_reserved0B;
    float m_fMinForce;
    float m_fMaxForce;
    float m_fTau;
    float m_fMotorDamping;
    float m_fProportionalRecoveryVelocity;
    float m_fConstantRecoveryVelocity;
    PositionConstraintMotor* __thiscall Clone();
};
// Allocates a 0x24-byte copy of this motor through the global allocator, copies its type and float parameters, and returns it.
// @fnv 0x00cdf5b0
PositionConstraintMotor* __thiscall PositionConstraintMotor::Clone()
{
    hkMemoryRouter* router = (&hkMemoryRouter::getInstance());
    PositionConstraintMotor* copy = (PositionConstraintMotor*)reinterpret_cast<MotorAllocator*>(router->m_heap)->Allocate(0x24);
    ReferencedMotorView* referenced = (ReferencedMotorView*)copy;
    referenced->m_ppVirtualMethodTable = &DAT_010cb76c;
    referenced->m_memorySizeAndFlags = 0x24;
    referenced->m_sReferenceCount = 1;
    const unsigned char motorType = m_motorType;
    ConstraintMotorView* pConstraintMotor = (ConstraintMotorView*)copy;
    pConstraintMotor->m_ppVirtualMethodTable = &DAT_010cb780;
    pConstraintMotor->m_motorType = motorType;
    copy->m_fMinForce = m_fMinForce;
    copy->m_fMaxForce = m_fMaxForce;
    copy->m_ppVirtualMethodTable = &DAT_010cb798;
    copy->m_fTau = m_fTau;
    copy->m_fMotorDamping = m_fMotorDamping;
    copy->m_fProportionalRecoveryVelocity = m_fProportionalRecoveryVelocity;
    copy->m_fConstantRecoveryVelocity = m_fConstantRecoveryVelocity;
    return copy;
}
