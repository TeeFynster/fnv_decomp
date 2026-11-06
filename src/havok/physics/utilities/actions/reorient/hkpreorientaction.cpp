// src/havok/physics/utilities/actions/reorient/hkpreorientaction.cpp
// Functions are listed by their @fnv annotations.

#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkpAction.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkpReorientAction.h"
#include "../../../../../../include/hkpUnaryAction.h"

// GetMonitorStream is 0x00c85750 in other units; its heap allocator is at +0x10.

inline void* hkReferencedObject::operator new(std::size_t uiSize)
{
    hkReferencedObject* pkObj = static_cast<hkReferencedObject*>(
        hkMemoryRouter::getInstance().heap().blockAlloc(uiSize));
    pkObj->m_usMemSizeAndFlags = (unsigned short)uiSize;
    return pkObj;
}

class hkpPhantom;

// The shared hkpUnaryAction lacks the entity/user-data constructor at 0x00d2b260.

// The shared hkpReorientAction lacks the constructor at 0x00e444f0 and Clone at 0x00e44540.

// @fnv 0x00e44540
hkpReorientAction* hkpReorientAction::Clone(const hkArray<hkpEntity*>& newEntities,
                                         const hkArray<hkpPhantom*>& newPhantoms) const
{
    if (newEntities.GetLogicalSize() != 1)
        return 0;
    if (newPhantoms.GetLogicalSize() != 0)
        return 0;
    hkpReorientAction* ra = new hkpReorientAction(newEntities[0], m_vRotationAxis, m_vUpAxis,
                                                m_fSpringStrength, m_fMotorDamping);
    ra->m_ulUserData = m_ulUserData;
    return ra;
}

// @fnv 0x00e444f0
hkpReorientAction::hkpReorientAction(hkpEntity* entity, const hkVector4& rotationAxis,
                                   const hkVector4& upAxis, float strength, float damping) throw()
    : hkpUnaryAction(entity, 0)
{
    m_vRotationAxis = rotationAxis;
    m_vUpAxis = upAxis;
    m_fSpringStrength = strength;
    m_fMotorDamping = damping;
}
