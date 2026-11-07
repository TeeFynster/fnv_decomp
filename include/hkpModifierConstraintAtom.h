#pragma once

struct GenericConstraintAtomScheme;

class hkpModifierConstraintAtom
{
public:
    unsigned short m_type;
    unsigned short unk02;
    int unk04;
    int unk08;
    int unk0C;
    union
    {
        int unk10;
        struct
        {
            unsigned short m_usModifierAtomSize;
            unsigned short m_iChildSize;
        };
    };
    hkpModifierConstraintAtom* m_pChildAtom;

    int addModifierDataToConstraintInfo(GenericConstraintAtomScheme& infoOut, unsigned char& usedFlagsOut);
};
