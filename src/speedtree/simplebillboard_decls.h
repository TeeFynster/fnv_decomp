// speedtree/simplebillboard_decls.h: declares RotationMatrix3x3 and SimpleBillboard
#ifndef SIMPLEBILLBOARD_DECLS_H
#define SIMPLEBILLBOARD_DECLS_H

#include "../../include/CVec3.h"

class RotationMatrix3x3
{
  public:
    float m_fComponents[3][3];
    __forceinline void Set()
    {
        m_fComponents[0][0] = 1.0f;
        m_fComponents[0][1] = 0.0f;
        m_fComponents[0][2] = 0.0f;
        m_fComponents[1][0] = 0.0f;
        m_fComponents[1][1] = 1.0f;
        m_fComponents[1][2] = 0.0f;
        m_fComponents[2][0] = 0.0f;
        m_fComponents[2][1] = 0.0f;
        m_fComponents[2][2] = 1.0f;
    }
    void CRotTransform_RotateY(float);
};
// These methods are inlined in this unit's original debug build.
__forceinline CVec3::CVec3()
{
    z = 0.0f;
    y = 0.0f;
    x = 0.0f;
}
__forceinline CVec3::CVec3(float a, float b, float c)
{
    x = a;
    y = b;
    z = c;
}
__forceinline const float& CVec3::operator[](int i) const
{
    return (&x)[i];
}
__forceinline void CVec3::Set(const float& a, const float& b, const float& c)
{
    x = a;
    y = b;
    z = c;
}
class SimpleBillboard
{
  public:
    static void CalculateBillboardTransform(const float*);
};
// Preserve the original debug-build inline workspace allocation (23 float slots).
__forceinline void ReserveBillboardWorkspace()
{
    float workspace0, workspace1, workspace2, workspace3, workspace4, workspace5, workspace6, workspace7, workspace8,
        workspace9, workspace10, workspace11, workspace12, workspace13, workspace14, workspace15, workspace16,
        workspace17, workspace18, workspace19, workspace20, workspace21, workspace22;
}
#include <math.h>
extern const double DAT_010a4d90;
extern CVec3 DAT_011f8d08, DAT_011f8d14, DAT_011f8d20, DAT_011f8d2c;
#endif
