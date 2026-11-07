// gamebryo2.2/corelibs/nianimation/niquattransform.cpp: NiQuatTransform, QXform, QXformViewer, QXform2 (8 functions)

// Preserve the existing point declarations used by this generated unit.
#pragma include_alias("NiPoint3.h", "../../../../include/NiPoint3.h")
#include "PointStorage.h"
#include "../../../../include/NiMatrix3.h"


#include "../../../../include/NiQuatTransform.h"
#include "../../../../include/NiQuaternion.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiColor.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiColorA.h"

// NiQuaternion copied as plain data: the original copies the four floats inline, while the shared class declares an
// out-of-line operator=.
struct NiQuaternionValue
{
    float m_fVectorX, m_fVectorY, m_fVectorZ, m_fScalarPart;
};
extern const float kInvalidTransformValue;

__forceinline void NiBinaryStream::ReadScalar(void* data, unsigned int bytes)
{
    unsigned int size = bytes;
    m_uiAbsoluteCurrentPos += m_pfnRead(this, data, bytes, &size, 1);
}

// Reads translation, rotation and scale from the stream; for older versions reads validity bytes and sets invalid components to kInvalidTransformValue.
// @fnv 0x00a38bb0
void NiQuatTransform::LoadBinary(NiStream& stream)
{
    reinterpret_cast<NiColor&>(x).LoadBinary(stream);
    reinterpret_cast<NiColorA&>(qx).LoadBinary(stream);
    stream.m_pkIstr->ReadScalar(&scale, 4);
    if (stream.m_uiNifFileVersion < 0x0A01006E)
    {
        unsigned char valid;
        stream.m_pkIstr->ReadScalar(&valid, 1);
        if (!valid)
            x = kInvalidTransformValue;
        stream.m_pkIstr->ReadScalar(&valid, 1);
        if (!valid)
            qy = kInvalidTransformValue;
        stream.m_pkIstr->ReadScalar(&valid, 1);
        if (!valid)
            scale = kInvalidTransformValue;
    }
}

struct Inner_00a6db50
{
    void __thiscall Set(float, float, float, float);
};
struct Outer_00a2bdb0
{
    int _0;
    Inner_00a6db50 _4;
    Outer_00a2bdb0* __thiscall ClearInnerVector();
};
// Calls the inner object's method with four zero floats and returns this.
// @fnv 0x00a2bdb0
// src: GUESS 0x00a2bdb0 (confidence: medium)
Outer_00a2bdb0* __thiscall Outer_00a2bdb0::ClearInnerVector()
{
    _4.Set(0.0f, 0.0f, 0.0f, 0.0f);
    return this;
}

extern NiPoint3 DAT_011a8400;
extern NiQuaternion DAT_011f3704;
struct QQuatOps
{
    NiQuaternion MultiplyQuaternion(const NiQuaternion& q) const;
    void FUN_00a38560();
};
struct QXform
{
    NiPoint3 m_kTranslate;
    NiQuaternion m_kRotate;
    float m_fScale;
    QXform() : m_kTranslate(DAT_011a8400), m_kRotate(DAT_011f3704), m_fScale(kInvalidTransformValue)
    {}
    bool IsScaleValid() const
    {
        return m_fScale != -3.4028234663852886e38;
    }
    bool IsRotateValid() const
    {
        return m_kRotate.m_fVectorY != -3.4028234663852886e38;
    }
    bool IsTranslateValid() const
    {
        return m_kTranslate.x != -3.4028234663852886e38;
    }
    void MakeScaleInvalid()
    {
        m_fScale = kInvalidTransformValue;
    }
    void MakeRotateInvalid()
    {
        m_kRotate.m_fVectorY = kInvalidTransformValue;
    }
    void MakeTranslateInvalid()
    {
        m_kTranslate.x = kInvalidTransformValue;
    }
    QXform ProcessAndReturnValue_00a38a00(const QXform& kXform) const;
};
// @fnv 0x00a38a00
// src: GUESS 0x00a38a00 (confidence: low)
QXform QXform::ProcessAndReturnValue_00a38a00(const QXform& kXform) const
{
    QXform kResult;
    if (IsScaleValid() && kXform.IsScaleValid())
        kResult.m_fScale = kXform.m_fScale * m_fScale;
    else
        kResult.MakeScaleInvalid();
    if (IsRotateValid() && kXform.IsRotateValid())
    {
        NiQuaternion kRotate = ((const QQuatOps*)&m_kRotate)->MultiplyQuaternion(kXform.m_kRotate);
        ((QQuatOps*)&kRotate)->FUN_00a38560();
        *(NiQuaternionValue*)&kResult.m_kRotate = *(NiQuaternionValue*)&kRotate;
    }
    else
        kResult.MakeRotateInvalid();
    if (IsTranslateValid() && kXform.IsTranslateValid())
    {
        NiPoint3 kTranslate;
        kTranslate.x = kXform.m_kTranslate.x + m_kTranslate.x;
        kTranslate.y = kXform.m_kTranslate.y + m_kTranslate.y;
        kTranslate.z = kXform.m_kTranslate.z + m_kTranslate.z;
        kResult.m_kTranslate = kTranslate;
    }
    else
        kResult.MakeTranslateInvalid();
    return kResult;
}

char* GetViewerStringName(const char* pcName);
char* GetViewerStringFloat(const char* pcName, float fValue);

struct ViewerPoint3 : NiPoint3
{
    char* FormatToBuffer(const char* pcName) const;
};
struct ViewerQuaternion : NiQuaternion
{
    char* FormatToBuffer(const char* pcName) const;
};

struct ViewerStrings
{
    virtual ~ViewerStrings();
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char*& pcElement);
    unsigned int Add(char*& pcElement)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcElement);
        return uiIndex;
    }
};

struct QXformViewer : QXform
{
    void NiQuatTransform_GetViewerStrings(ViewerStrings* pkStrings);
};

// Appends the class name and, when valid, the translate, rotate and scale members to the viewer string list.
// @fnv 0x00a38cb0
// src: XBOX_PDB 0x00a38cb0
void QXformViewer::NiQuatTransform_GetViewerStrings(ViewerStrings* pkStrings)
{
    char* pcString = GetViewerStringName("NiQuatTransform");
    pkStrings->Add(pcString);
    if (IsTranslateValid())
    {
        char* pcString = static_cast<ViewerPoint3&>(m_kTranslate).FormatToBuffer("m_kTranslate");
        pkStrings->Add(pcString);
    }
    if (IsRotateValid())
    {
        char* pcString = static_cast<ViewerQuaternion&>(m_kRotate).FormatToBuffer("m_kRotate");
        pkStrings->Add(pcString);
    }
    if (IsScaleValid())
    {
        char* pcString = GetViewerStringFloat("m_fScale", m_fScale);
        pkStrings->Add(pcString);
    }
}

extern NiPoint3 DAT_011a8400;
extern NiQuaternion DAT_011f3704;

struct QMat3
{
    float m00;
    float m01;
    float m02;
    float m10;
    float m11;
    float m12;
    float m20;
    float m21;
    float m22;
    NiPoint3 MulPoint(const NiPoint3& p) const;
};
extern const QMat3 kQMat3Identity;


// Hands the scaled point back as plain point storage.
inline PointStorage ScalePoint(float f, const NiPoint3& p)
{
    PointStorage r;
    r.x = f * p.x;
    r.y = f * p.y;
    r.z = f * p.z;
    return r;
}

struct QQuatRot
{
    void ToRotationMatrix(QMat3& m) const;
};

struct QXform2
{
    NiPoint3 m_kTranslate;
    NiQuaternion m_kRotate;
    float m_fScale;
    QXform2() : m_kTranslate(DAT_011a8400), m_kRotate(DAT_011f3704), m_fScale(kInvalidTransformValue)
    {}
    bool IsScaleValid() const
    {
        return m_fScale != -3.4028234663852886e38;
    }
    bool IsRotateValid() const
    {
        return m_kRotate.m_fVectorY != -3.4028234663852886e38;
    }
    bool IsTranslateValid() const
    {
        return m_kTranslate.x != -3.4028234663852886e38;
    }
    QXform2 NiQuatTransform_HierApply(const QXform2& kXform) const;
};

// @fnv 0x00a38830
// src: COMMUNITY 0x00a38830
QXform2 QXform2::NiQuatTransform_HierApply(const QXform2& kXform) const
{
    QXform2 kRes;
    float fScale = 1.0f;
    if (IsScaleValid() && kXform.IsScaleValid())
    {
        float fNew = m_fScale * kXform.m_fScale;
        kRes.m_fScale = fNew;
        fScale = fNew;
    }
    else
    {
        kRes.m_fScale = kInvalidTransformValue;
    }
    QMat3 kRot = kQMat3Identity;
    if (IsRotateValid() && kXform.IsRotateValid())
    {
        NiQuaternion kQ = ((const QQuatOps*)&m_kRotate)->MultiplyQuaternion(kXform.m_kRotate);
        ((QQuatOps*)&kQ)->FUN_00a38560();
        *(NiQuaternionValue*)&kRes.m_kRotate = *(NiQuaternionValue*)&kQ;
        ((const QQuatRot*)&m_kRotate)->ToRotationMatrix(kRot);
    }
    else
    {
        kRes.m_kRotate.m_fVectorY = kInvalidTransformValue;
    }
    if (IsTranslateValid() && kXform.IsTranslateValid())
    {
        PointStorage kS = ScalePoint(fScale, kRot.MulPoint(kXform.m_kTranslate));
        NiPoint3 kSum;
        kSum.x = m_kTranslate.x + kS.x;
        kSum.y = m_kTranslate.y + kS.y;
        kSum.z = m_kTranslate.z + kS.z;
        kRes.m_kTranslate = kSum;
    }
    else
    {
        kRes.m_kTranslate.x = kInvalidTransformValue;
    }
    return kRes;
}

inline unsigned int NiBinaryStream::BinaryWrite(const void* p, unsigned int n, unsigned int* sizes,
                                                unsigned int count)
{
    unsigned int written = m_pfnWrite(this, p, n, sizes, count);
    m_uiAbsoluteCurrentPos += written;
    return written;
}

template <class T>
inline void SaveBinaryValues(NiBinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void SaveBinaryValue(NiStream& kStream, const T& value)
{
    SaveBinaryValues(*kStream.m_pkOstr, &value);
}

// The former DataA38 is a 32-byte transform: its calls bind to NiColor::SaveBinary (0x00a69780)
// for translation and NiQuaternion::SaveBinary (0x00a6e4a0) for rotation, followed by scale.
// @fnv 0x00a38b60
void NiQuatTransform::SaveBinary(NiStream* kStream)
{
    reinterpret_cast<NiColor&>(x).SaveBinary(*kStream);
    reinterpret_cast<NiQuaternion&>(qx).SaveBinary(kStream);
    SaveBinaryValue(*kStream, scale);
}

// local form of NiQuaternion: 0x00a2bcf0 needs POD result construction; the shared default ctor changes bytes.
struct QQ
{
    float m_fVectorX, m_fVectorY, m_fVectorZ, m_fScalarPart;
    void Set(float w, float x, float y, float z);
    QQ MultiplyQuaternion(const QQ& q) const;
};
// Multiplies this quaternion by q using the Hamilton product and returns the resulting quaternion.
// @fnv 0x00a2bcf0
// src: GUESS 0x00a2bcf0 (confidence: medium)
QQ QQ::MultiplyQuaternion(const QQ& aQuat) const
{
    QQ r;
    r.Set(m_fVectorX * aQuat.m_fVectorX - m_fVectorY * aQuat.m_fVectorY - m_fVectorZ * aQuat.m_fVectorZ -
              m_fScalarPart * aQuat.m_fScalarPart,
          m_fVectorX * aQuat.m_fVectorY + m_fVectorY * aQuat.m_fVectorX + m_fVectorZ * aQuat.m_fScalarPart -
              m_fScalarPart * aQuat.m_fVectorZ,
          m_fVectorX * aQuat.m_fVectorZ + m_fVectorZ * aQuat.m_fVectorX + m_fScalarPart * aQuat.m_fVectorY -
              m_fVectorY * aQuat.m_fScalarPart,
          m_fVectorX * aQuat.m_fScalarPart + m_fScalarPart * aQuat.m_fVectorX + m_fVectorY * aQuat.m_fVectorZ -
              m_fVectorZ * aQuat.m_fVectorY);
    return r;
}

#include <string.h>
// local form of NiQuaternion: 0x00a386a0 needs inline memcpy assignment; the shared out-of-line operator= changes bytes.
struct LocalQuaternionConjugateValue
{
    float m_fVectorX, m_fVectorY, m_fVectorZ, m_fScalarPart;
    LocalQuaternionConjugateValue& operator=(const LocalQuaternionConjugateValue& q)
    {
        memcpy(this, &q, sizeof(q));
        return *this;
    }
};
LocalQuaternionConjugateValue NiQuaternionConjugate(const LocalQuaternionConjugateValue& kQuat);
struct QuatPoint
{
    float x, y, z;
    QuatPoint()
    {}
    QuatPoint(float a, float b, float c) : x(a), y(b), z(c)
    {}
    QuatPoint operator-() const
    {
        return QuatPoint(-x, -y, -z);
    }
    QuatPoint operator*(float fScale) const
    {
        QuatPoint kR;
        kR.x = x * fScale;
        kR.y = y * fScale;
        kR.z = z * fScale;
        return kR;
    }
};
// NiMatrix3::operator*(const NiPoint3&) const, inlined here over this unit's QuatPoint.
struct NiMatrix3_QuatPointView : public NiMatrix3
{
    QuatPoint operator*(const QuatPoint& kPt) const
    {
        QuatPoint kR;
        kR.x = m_pEntry[0][0] * kPt.x + m_pEntry[0][1] * kPt.y + m_pEntry[0][2] * kPt.z;
        kR.y = m_pEntry[1][0] * kPt.x + m_pEntry[1][1] * kPt.y + m_pEntry[1][2] * kPt.z;
        kR.z = m_pEntry[2][0] * kPt.x + m_pEntry[2][1] * kPt.y + m_pEntry[2][2] * kPt.z;
        return kR;
    }
};
struct QuatRotate
{
    void NiQuaternion_ToRotation(NiMatrix3& kRot) const;
};
extern char DAT_011a9448;
static const double DAT_010241b0 = -3.4028234663852886e+38;
static const float DAT_01096b8c = -3.402823466e+38f;
struct FUN_00a386a0_shell : NiQuatTransform
{
    void Inverse(NiQuatTransform& kDest);
};

// Computes the inverse transform into kDest by inverting scale, conjugating and rotating the quaternion, and transforming the translation.
// @fnv 0x00a386a0
void FUN_00a386a0_shell::Inverse(NiQuatTransform& kDest)
{
    float fInvScale = 1.0f;
    if (scale == DAT_010241b0)
    {
        kDest.scale = DAT_01096b8c;
    }
    else
    {
        kDest.scale = 1.0f / scale;
        fInvScale = kDest.scale;
    }
    NiMatrix3 kRot = *(NiMatrix3*)&DAT_011a9448;
    if (qy == DAT_010241b0)
    {
        kDest.qy = DAT_01096b8c;
    }
    else
    {
        *(LocalQuaternionConjugateValue*)&kDest.qx =
            NiQuaternionConjugate(*(LocalQuaternionConjugateValue*)&qx);
        ((QuatRotate*)&kDest.qx)->NiQuaternion_ToRotation(kRot);
    }
    if (x == DAT_010241b0)
    {
        kDest.x = DAT_01096b8c;
    }
    else
    {
        *(QuatPoint*)&kDest.x = ((const NiMatrix3_QuatPointView&)kRot * -*(QuatPoint*)&x) * fInvScale;
    }
}
