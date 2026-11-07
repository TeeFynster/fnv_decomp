#pragma once
#include "hkpConstraintData.h"
#include "hkArray.h"

class hkpConstraintOwner;
class hkpConstraintInstance;
class hkpSimpleContactConstraintAtom;
class hkpContactPointPropertiesCFD;
class hkContactPoint;
struct hkContactPt;
struct hkCPProperties;
struct PhysicsMaterial;

// Exe RTTI at vftable 0x010cc934: hkpSimpleContactConstraintData derives from hkpConstraintData.
class hkpSimpleContactConstraintData : public hkpConstraintData
{
public:
    hkArray<unsigned char> m_kAtoms;
    int unk18;
    int unk1C;
    int unk20;
    hkpConstraintInstance* m_pHavokConstraint;
    hkpSimpleContactConstraintAtom* m_pAtom;
    int m_iAtomSize;

    hkpContactPointPropertiesCFD* GetContactPointProperties(unsigned short id);
    int freeContactPoint(hkpConstraintOwner& kConstraintOwner, unsigned short uiId);
    int allocateContactPoint(hkpConstraintOwner& owner, hkContactPt** cpOut, hkCPProperties** cpiOut);
    int allocateContactPoint(hkpConstraintOwner& owner, hkContactPoint** cpOut, PhysicsMaterial** cpPropsOut);
};
