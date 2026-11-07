// speedtree/simplebillboard.cpp: SimpleBillboard (1 function)

#include "simplebillboard_decls.h"
// @fnv 0x00b27080
void SimpleBillboard::CalculateBillboardTransform(const float* afPosition)
{
    struct Camera
    {
        float x, y, z;
        __forceinline const float& operator[](int i) const
        {
            return (&x)[i];
        }
    };
    struct Frame
    {
        RotationMatrix3x3 cRot;
        Camera cCamera;
        float fAngleDifference;
    } frame;
    frame.cCamera.z = 0.0f;
    frame.cCamera.y = 0.0f;
    frame.cCamera.x = 0.0f;
    frame.cCamera.x = afPosition[0];
    frame.cCamera.y = afPosition[1];
    frame.cCamera.z = afPosition[2];
    frame.fAngleDifference = atan2(frame.cCamera[1], frame.cCamera[0]) * DAT_010a4d90;
    static CVec3 c0(0.0f, 0.5f, 1.0f);
    static CVec3 c1(0.0f, -0.5f, 1.0f);
    static CVec3 c2(0.0f, -0.5f, 0.0f);
    static CVec3 c3(0.0f, 0.5f, 0.0f);
    static CVec3 corners[4];
    (corners[0].*static_cast<void (CVec3::*)(const float&, const float&, const float&)>(&CVec3::Set))(c0.x, c0.y, c0.z);
    (corners[1].*static_cast<void (CVec3::*)(const float&, const float&, const float&)>(&CVec3::Set))(c1.x, c1.y, c1.z);
    (corners[2].*static_cast<void (CVec3::*)(const float&, const float&, const float&)>(&CVec3::Set))(c2.x, c2.y, c2.z);
    (corners[3].*static_cast<void (CVec3::*)(const float&, const float&, const float&)>(&CVec3::Set))(c3.x, c3.y, c3.z);
    frame.cRot.m_fComponents[0][0] = 1.0f;
    frame.cRot.m_fComponents[0][1] = 0.0f;
    frame.cRot.m_fComponents[0][2] = 0.0f;
    frame.cRot.m_fComponents[1][0] = 0.0f;
    frame.cRot.m_fComponents[1][1] = 1.0f;
    frame.cRot.m_fComponents[1][2] = 0.0f;
    frame.cRot.m_fComponents[2][0] = 0.0f;
    frame.cRot.m_fComponents[2][1] = 0.0f;
    frame.cRot.m_fComponents[2][2] = 1.0f;
    frame.cRot.CRotTransform_RotateY(frame.fAngleDifference);
    DAT_011f8d08 = corners[0] * frame.cRot;
    DAT_011f8d14 = corners[1] * frame.cRot;
    DAT_011f8d20 = corners[2] * frame.cRot;
    DAT_011f8d2c = corners[3] * frame.cRot;
    ReserveBillboardWorkspace();
}
