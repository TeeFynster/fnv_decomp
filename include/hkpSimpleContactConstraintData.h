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
    int FUN_00cfd200(hkpConstraintOwner& kConstraintOwner, unsigned short uiId);
    int FUN_00d92df0(hkpConstraintOwner& owner, hkContactPt** cpOut, hkCPProperties** cpiOut);
    int FUN_00d92df0(hkpConstraintOwner& owner, hkContactPoint** cpOut, PhysicsMaterial** cpPropsOut);
};
