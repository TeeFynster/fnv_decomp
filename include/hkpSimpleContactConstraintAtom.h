#pragma once

#include "hkContactPoint.h"

class PhysicsMaterial;
class UInt32Value;

class hkpSimpleContactConstraintAtom
{
public:
    unsigned short m_type;
    unsigned short m_usSizeOfAllAtoms;
    unsigned short m_usNumContactPoints;
    unsigned short m_usMaxNumContactPoints;
    unsigned char m_ucNumReservedContactPoints;
    unsigned char m_ucNumContactPointProperties;
    unsigned char m_ucContactPointPropertiesStriding;
    unsigned char unk0B;
    unsigned short m_usMaxNumContactPointProperties;
    unsigned short unk0E;
    unsigned short m_infoFlags;
    unsigned short unk12;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;

    hkContactPoint* getContactPoints();
    hkContactPoint* getContactPoints() const;
    PhysicsMaterial* getContactPointPropertiesStream(int i);
    UInt32Value* getContactPointPropertiesStream() const;
    int getContactPointPropertiesStriding() const;
};
