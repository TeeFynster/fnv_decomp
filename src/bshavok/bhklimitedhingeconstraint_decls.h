// Local output layout and helpers for bhkLimitedHingeConstraint.
#ifndef BHKLIMITEDHINGECONSTRAINT_DECLS_H
#define BHKLIMITEDHINGECONSTRAINT_DECLS_H

extern float DAT_01267e30;
void bhkConvexShape_CopyCinfo();

// bhkLimitedHingeVector_bhklimitedhingeconstraint_decls: local type (was include/bhkLimitedHingeVector_bhklimitedhingeconstraint_decls.h, which had no evidence of one real class); its methods are 0x004b4db0 bhkVector4::operator=
class bhkLimitedHingeVector_bhklimitedhingeconstraint_decls
{
public:
    union
    {
        struct
        {
            int unk00;
            int unk04;
            int unk08;
            int unk0C;
        };
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };
        float value[4];
        unsigned char vecData[16];
    };

    void SetQuaternionComponentsFromVector(const float*);
};

class bhkLimitedHingeOutput
{
  public:
    char prefix[16];
    bhkLimitedHingeVector_bhklimitedhingeconstraint_decls first;
    bhkLimitedHingeVector_bhklimitedhingeconstraint_decls second;
};

inline const float* bhkLimitedHingeConstraint::GetFirst() const
{
    return this && m_pHavokObject ? (const float*)((const char*)m_pHavokObject + 0x20) : &DAT_01267e30;
}

inline const float* bhkLimitedHingeConstraint::GetSecond() const
{
    return this && m_pHavokObject ? (const float*)((const char*)m_pHavokObject + 0x30) : &DAT_01267e30;
}
#endif
