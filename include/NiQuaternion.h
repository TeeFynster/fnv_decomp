#pragma once

class Mat112;
class NiPoint3;
class NiStream;
class NiMatrix3;

class NiQuaternion
{
public:
    float m_fVectorX;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;

    NiQuaternion();

    NiQuaternion(float w, float x, float y, float z)
        : m_fVectorX(w), m_fVectorY(x), m_fVectorZ(y), m_fScalarPart(z)
    {}

    NiQuaternion& operator=(const NiQuaternion& src);

    bool operator!=(const NiQuaternion& other) const;
    NiQuaternion Negate() const;

    NiQuaternion operator+(const NiQuaternion& q) const
    {
        return NiQuaternion(m_fVectorX + q.m_fVectorX, m_fVectorY + q.m_fVectorY,
                            m_fVectorZ + q.m_fVectorZ, m_fScalarPart + q.m_fScalarPart);
    }

    NiQuaternion operator*(float scalar) const
    {
        return NiQuaternion(m_fVectorX * scalar, m_fVectorY * scalar,
                            m_fVectorZ * scalar, m_fScalarPart * scalar);
    }

    NiQuaternion ScaleFourComponents(float scalar) const;
    void FUN_00a38560();
    void NiQuaternion_ToRotation(Mat112* matrix);

    void SetW(float value);
    void SetX(float value);
    void SetY(float value);
    void SetZ(float value);
    float GetW();
    float GetX();
    float GetY();
    float GetZ();
    void SetValues(float w, float x, float y, float z);
    void GetValues(float* w, float* x, float* y, float* z);

    void Sum4(const NiQuaternion& q, float w, float x, float y, float z)
    {
        m_fVectorX = q.m_fVectorX + w;
        m_fVectorY = q.m_fVectorY + x;
        m_fVectorZ = q.m_fVectorZ + y;
        m_fScalarPart = q.m_fScalarPart + z;
    }

    void MakeUnitLength();
    void Normalize();
    void EnsureCanonicalSign();
    void Snap();
    void Slerp(float t, const NiQuaternion& a, const NiQuaternion& b);
    void Slerp(float t, NiQuaternion* a, NiQuaternion* b);
    void InterpolateSquad(float t, NiQuaternion* a, NiQuaternion* b, NiQuaternion* c, NiQuaternion* d);
    void GetAngleAxis(float& angle, NiPoint3& axis);
    void GetAngleAxis(float* angle, NiPoint3* axis);
    void FromAngleAxis(float angle, NiPoint3* axis);
    void FromAngleAxisX(float angle);
    void FromAngleAxisY(float angle);
    void FromAngleAxisZ(float angle);
    void SetRotationFromEulerXYZ(float x, float y, float z);
    void ToRotationMatrix(NiMatrix3& matrix);
    void ToRotationMatrix(NiMatrix3* matrix);
    void FromRotationMatrix(const NiMatrix3& matrix);
    void FromRotationMatrix(NiMatrix3* matrix);
    void LoadBinary(NiStream* stream);
    void SaveBinary(NiStream* stream);
    char* FormatToBuffer(char* buffer);

    static float Dot(const NiQuaternion& p, const NiQuaternion& q);

    static float Dot(NiQuaternion* p, NiQuaternion* q);
    static NiQuaternion MakeUnitLength(NiQuaternion* quaternion);
    static NiQuaternion Exp(NiQuaternion* quaternion);
    static NiQuaternion Log(NiQuaternion* quaternion);
    static NiQuaternion Intermediate(NiQuaternion* a, NiQuaternion* b, NiQuaternion* c);
    static void LoadBinary(NiStream* stream, NiQuaternion* quaternions, unsigned int count);
    static void SaveBinary(NiStream* stream, NiQuaternion* quaternions, unsigned int count);
    static float ISqrt_approx_in_neighborhood(float value);
    static float Lerp(float a, float b, float t);
    static __declspec(noinline) float CalculateSlerpWeight(float t, float cosine);
    static const NiQuaternion IDENTITY;
};
