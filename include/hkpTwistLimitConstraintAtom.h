#pragma once

class hkpTwistLimitConstraintAtom
{
public:
    unsigned short m_type;
    unsigned char m_bLimitEnabled;
    unsigned char m_ucTwistAxis;
    unsigned char m_ucReferenceAxis;
    unsigned char unk05;
    unsigned short unk06;
    float m_fMinAngle;
    float m_fMaxAngle;
    float m_fAngularLimitsTauFactor;
};
