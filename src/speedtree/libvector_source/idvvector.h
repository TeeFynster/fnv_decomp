// speedtree/libvector_source/idvvector.h: declares RotationMatrix3x3
#ifndef FNV_IDVVECTOR_H
#define FNV_IDVVECTOR_H

#include "../../../include/CVec3.h"

class RotationMatrix3x3
{
  public:
    float m_fComponents[3][3];
};
__forceinline CVec3::CVec3(float a, float b, float c) : x(a), y(b), z(c)
{}
// @fnv 0x00b12890
CVec3 CVec3::operator*(const RotationMatrix3x3& transform) const
{
    float result[3];
    result[0] =
        transform.m_fComponents[2][0] * z + (transform.m_fComponents[1][0] * y + transform.m_fComponents[0][0] * x);
    result[1] =
        transform.m_fComponents[2][1] * z + (transform.m_fComponents[1][1] * y + transform.m_fComponents[0][1] * x);
    result[2] =
        transform.m_fComponents[2][2] * z + (transform.m_fComponents[1][2] * y + transform.m_fComponents[0][2] * x);
    return CVec3(result[0], result[1], result[2]);
}
#endif
