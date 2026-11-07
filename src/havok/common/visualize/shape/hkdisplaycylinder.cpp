
// src/havok/common/visualize/shape/hkdisplaycylinder.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/shape/hkdisplaycylinder.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00d58500
// src: COMMUNITY 0x00d58500
void __stdcall nullsub_78(int, int)
{}

#include <xmmintrin.h>
struct DE1F50Vector4
{
    __m128 m_vComponents;

    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return m_vComponents.m128_f32[i];
    }
    void operator=(const DE1F50Vector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

struct DE1F50Transform
{
    DE1F50Vector4 m_kColumn0;
    DE1F50Vector4 m_kColumn1;
    DE1F50Vector4 m_kColumn2;
    DE1F50Vector4 m_vTranslation;

    void setIdentity()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
        m_kColumn0(0) = 1.0f;
        m_kColumn1(1) = 1.0f;
        m_kColumn2(2) = 1.0f;
        m_vTranslation.setZero4();
    }
};

class DE1F50ReferencedObject
{
  public:
    DE1F50ReferencedObject() : m_sReferenceCount(1)
    {}
    virtual void unk00();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class DE1F50Shape : public DE1F50ReferencedObject
{
  public:
    DE1F50Shape() : m_ulUserData(0), m_type(2)
    {
        m_kMotionTransform.setIdentity();
    }

    int m_ulUserData;
    int unk0C;
    DE1F50Transform m_kMotionTransform;
    int m_type;
    int unk54;
    int unk58;
    int unk5C;
};

class FUN_00de1f50 : public DE1F50Shape
{
  public:
    FUN_00de1f50(const DE1F50Vector4& v);
    virtual void unk00();

    DE1F50Vector4 m_vector;
};

// Constructor that stores the given DE1F50Vector4 into m_vector.
// @fnv 0x00de1f50
FUN_00de1f50::FUN_00de1f50(const DE1F50Vector4& v) : m_vector(v)
{
    m_vector = v;
}
