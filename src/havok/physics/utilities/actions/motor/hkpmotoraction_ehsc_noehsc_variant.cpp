#include "../../../../../../include/hkArray.h"

// src/havok/physics/utilities/actions/motor/hkpmotoraction_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/utilities/actions/motor/hkpmotoraction.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/actions/motor/hkpmotoraction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/actions/motor/hkpmotoraction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/hkpMotorAction.h"

class hkpRigidBody;
class hkpPhantom;

struct hkMemoryAllocatorMA
{
    virtual ~hkMemoryAllocatorMA();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct hkMemoryRouterMA
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorMA* m_pStreamAllocator;
    hkMemoryAllocatorMA& heap()
    {
        return *m_pStreamAllocator;
    }
};

hkMemoryRouterMA& __cdecl hkMemoryRouter_getInstance();



class hkpMotorActionMA : public hkpMotorAction
{
  public:
    void* operator new(unsigned int nbytes)
    {
        hkReferencedObject* b =
            static_cast<hkReferencedObject*>(hkMemoryRouter_getInstance().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }
    void operator delete(void*, unsigned int);

    hkpMotorActionMA(hkpRigidBody* body, const hkVector4& axis, hkReal spinRate, hkReal gain);

    hkpAction* hkpMotorAction_clone(const hkArrayBase<hkpEntity*>& newEntities, const hkArrayBase<hkpPhantom*>& newPhantoms) const;
};

// @fnv 0x00d4d7f0
// src: HAVOK_LIB 0x00d4d7f0
hkpAction* hkpMotorActionMA::hkpMotorAction_clone(const hkArrayBase<hkpEntity*>& newEntities,
                                          const hkArrayBase<hkpPhantom*>& newPhantoms) const
{
    if (newEntities.GetLogicalSize() != 1)
        return 0;

    if (newPhantoms.GetLogicalSize() != 0)
        return 0;

    hkpMotorActionMA* ma = new hkpMotorActionMA((hkpRigidBody*)newEntities[0], m_kAxisEndPoints, m_fSpinRate, m_fGain);
    ma->m_bSlotEnabled = m_bSlotEnabled;
    ma->m_ulUserData = m_ulUserData;

    return ma;
}
