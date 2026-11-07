typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;
#define _INCLUDED_MM2
// src/havok/physics/collide/shape/convex/capsule/hkpcapsuleshape_ehsc_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/shape/convex/capsule/hkpcapsuleshape_ehsc_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/shape/convex/capsule/hkpcapsuleshape_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/collide/shape/convex/capsule/hkpcapsuleshape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/shape/convex/capsule/hkpcapsuleshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/capsule/hkpcapsuleshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpCapsuleShape.h"
extern char const* const g_01268970_arg1;
void __cdecl hkReferencedObject_calcContentStatistics(char const* const* arg1, char const* const* arg2);
void __cdecl hkpCapsuleShape_calcContentStatistics(char const* const* arg1, char const* const* arg2);
int __cdecl FUN_00d22350();
int __stdcall FUN_00d22d60(int a, int b);
// Exe 0x00d22760 FUN_00d22760: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).

extern "C" LocalM128 _mm_load_ps(float const* p);
extern "C" void _mm_store_ps(float* p, LocalM128 v);
class FUN_00d223f0_cls
{
public:
    void GatherIndexedVectors(unsigned short const* indices, int count, hkVector4* out);
};
struct __declspec(align(16)) hkVector4D224 {
    LocalM128 m_vComponents;

    hkVector4D224() {}
    hkVector4D224(const hkVector4D224& v) { m_vComponents = v.m_vComponents; }
};
class FUN_00d22480_cls {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    hkVector4D224 m_vector;

    hkVector4D224 FUN_00d22480() const;
};
struct FUN_00d224a0_Data {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    LocalM128 unk20;
    LocalM128 unk30;

    void __thiscall FUN_00d224a0(LocalM128* result);
};
extern int DAT_010ce25c;
union __declspec(align(16)) AlignedHKVector4 { LocalM128 simd; struct {float x,y,z,w;}; };
struct FUN_00d22590_Class : hkpCapsuleShape {
    FUN_00d22590_Class* __thiscall FUN_00d22590(
        const AlignedHKVector4& first, const AlignedHKVector4& second, float radius);
};
struct __declspec(align(16)) Point4 {
    float x, y, z, w;
};
struct ClosestLineResult {
    float distance;
    float fractionA;
    float fractionB;
    float extraValue;
    Point4 pointA;
    Point4 pointB;
};
void __cdecl hkLineSegmentUtil_closestPointInfLineInfLine(const Point4& a, const Point4& b,
                            const Point4& c, const Point4& d,
                            ClosestLineResult* out);
void __cdecl GetClosestLinePoints(const Point4& aLineAStart, const Point4& aLineAEnd, const Point4& aLineBStart, const Point4& aLineBEnd, float* pfDistance, float* pfFractionA, float* pfFractionB, Point4* pointA, Point4* pointB);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
extern "C" LocalM128 _mm_load_ss(const float*);
extern "C" void _mm_store_ps(float*, LocalM128);
extern float DAT_01016248;
class Aabb_d22440 {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    LocalM128 m_kMin;
    LocalM128 m_kMax;

    void __thiscall FUN_00d22440(LocalM128* pkCenter) const;
};
extern "C" LocalM128 _mm_sub_ps(LocalM128,LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128,LocalM128);
extern "C" LocalM128 _mm_add_ps(LocalM128,LocalM128);
extern "C" LocalM128 _mm_add_ss(LocalM128,LocalM128);
extern "C" LocalM128 _mm_load_ss(const float*);
extern "C" void _mm_store_ss(float*,LocalM128);
void __cdecl hkpCapsuleShape_closestPointLineSeg(float* arg1, float* arg2, float* arg3, float* out);

extern "C" LocalM128 _mm_mul_ps(LocalM128,LocalM128);
extern "C" LocalM128 _mm_add_ps(LocalM128,LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128,LocalM128);
extern "C" LocalM128 _mm_mul_ss(LocalM128,LocalM128);
extern "C" LocalM128 _mm_add_ss(LocalM128,LocalM128);
extern "C" LocalM128 _mm_sub_ss(LocalM128,LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128,LocalM128,int);
extern "C" LocalM128 _mm_rsqrt_ss(LocalM128);
extern "C" LocalM128 _mm_load_ss(const float*);
extern "C" LocalM128 _mm_andnot_ps(LocalM128,LocalM128);
extern "C" LocalM128 _mm_cmpeq_ss(LocalM128,LocalM128);
extern "C" LocalM128 _mm_setzero_ps();
extern "C" LocalM128 _mm_set_ss(float);
extern "C" void _mm_store_ss(float*,LocalM128);
extern "C" double __cdecl sqrt(double);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
extern const LocalM128 DAT_010c7160, DAT_010ec7f0;

class S00d22760_SimdReal {
public:
    __forceinline S00d22760_SimdReal(const LocalM128& x) : m_vValue(x) {}
    __forceinline S00d22760_SimdReal(float x) { m_vValue = _mm_load_ss(&x); }
    __forceinline S00d22760_SimdReal() {}
    __forceinline operator float() const { float s; _mm_store_ss(&s, m_vValue); return s; }
    __forceinline LocalM128 broadcast() const { return _mm_shuffle_ps(m_vValue, m_vValue, 0); }
    __forceinline const LocalM128& getQuad() const { return m_vValue; }
private:
    LocalM128 m_vValue;
};
typedef const S00d22760_SimdReal& S00d22760_SimdParam;
static __forceinline S00d22760_SimdReal operator-(S00d22760_SimdParam r) {
    return _mm_sub_ss(DAT_010c7160, r.getQuad());
}
class __declspec(align(16)) S00d22760_Vec {
public:
    __forceinline S00d22760_Vec() {}
    __forceinline S00d22760_Vec(const S00d22760_Vec& v) { m_vComponents = v.m_vComponents; }
    __forceinline void operator=(const S00d22760_Vec& v) { m_vComponents = v.m_vComponents; }
    __forceinline void setZero4() { m_vComponents = _mm_setzero_ps(); }
    __forceinline void setSub4(const S00d22760_Vec& a, const S00d22760_Vec& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void setAddMul4(const S00d22760_Vec& a, const S00d22760_Vec& b, S00d22760_SimdParam r) {
        m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(r.broadcast(), b.m_vComponents));
    }
    __forceinline void setInterpolate4(const S00d22760_Vec& v0, const S00d22760_Vec& v1, S00d22760_SimdParam _t) {
        LocalM128 t = _t.broadcast();
        LocalM128 s = _mm_sub_ps(DAT_010ec7f0, t);
        m_vComponents = _mm_add_ps(_mm_mul_ps(s, v0.m_vComponents), _mm_mul_ps(t, v1.m_vComponents));
    }
    __forceinline S00d22760_SimdReal dot3(const S00d22760_Vec& a) const {
        LocalM128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        LocalM128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    __forceinline S00d22760_SimdReal lengthSquared3() const { return this->dot3(*this); }
    __forceinline S00d22760_SimdReal lengthInverse3() const {
        const LocalM128 half = _mm_set_ss(0.5f);
        const LocalM128 three = _mm_set_ss(3.0f);
        const LocalM128 zero = _mm_set_ss(0.0f);
        const LocalM128 len2 = this->dot3(*this).getQuad();
        const LocalM128 len2EqualsZero = _mm_cmpeq_ss(len2, zero);
        const LocalM128 approx = _mm_rsqrt_ss(len2);
        const LocalM128 refined = _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
        return _mm_andnot_ps(len2EqualsZero, refined);
    }
    __forceinline void normalize3() {
        LocalM128 lenInv = lengthInverse3().broadcast();
        m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
    }
    __forceinline S00d22760_SimdReal normalizeWithLength3() {
        LocalM128 len2 = this->dot3(*this).getQuad();
        LocalM128 lenInv = lengthInverse3().broadcast();
        m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
        return _mm_mul_ss(len2, lenInv);
    }
    LocalM128 m_vComponents;
};
class S00d22760_Bool {
public:
    __forceinline S00d22760_Bool() {}
    __forceinline S00d22760_Bool(bool b) { m_cBooleanValue = (char)b; }
    __forceinline operator bool() const { return m_cBooleanValue != 0; }
    char m_cBooleanValue;
};
struct S00d22760_TimerCommand {
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    __forceinline void setTime() {
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        m_uiStartTicks = ticks;
    }
};
class S00d22760_Stream {
public:
    __forceinline static S00d22760_Stream& GetMonitorStream() { return *(S00d22760_Stream*)TlsGetValue(DAT_0126835c); }
    __forceinline S00d22760_Bool memoryAvailable() { return m_kRayEnd < m_pCurrentCommand; }
    __forceinline char* GetStreamEnd() { return m_kRayEnd; }
    __forceinline void setEnd(char* e) { m_kRayEnd = e; }
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
};
class S00d22760_TimeHelper {
public:
    __forceinline S00d22760_TimeHelper() {}
    __forceinline ~S00d22760_TimeHelper() {
        S00d22760_Stream& mStream = S00d22760_Stream::GetMonitorStream();
        if (mStream.memoryAvailable()) {
            S00d22760_TimerCommand* h = reinterpret_cast<S00d22760_TimerCommand*>(mStream.GetStreamEnd());
            h->m_pCommandName = "Et";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
};
struct __declspec(align(16)) S00d22760_Input {
    __forceinline S00d22760_Input() : m_uiFilterInfo(0), m_pRayShapeCollectionFilter(0) {}
    S00d22760_Vec m_vFrom;
    S00d22760_Vec m_vTo;
    unsigned int m_uiFilterInfo;
    const void* m_pRayShapeCollectionFilter;
};
struct __declspec(align(16)) S00d22760_Output {
    S00d22760_Vec m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    int m_pad18;
    int m_pad1c;
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
    __forceinline void setKey(unsigned int key) { m_uiShapeKeys[m_uiShapeKeyIndex] = key; }
};
static __forceinline float S00d22760_sqrtf(float r) { return (float)sqrt(r); }
struct __declspec(align(16)) S00d22760_LineResult {
    __forceinline S00d22760_LineResult() {}
    float m_fValue;
    float m_fFirstParameter;
    float m_fSecondParameter;
    float unk0c;
    S00d22760_Vec m_kFirstVector;
    S00d22760_Vec m_kSecondVector;
};
int __cdecl hkLineSegmentUtil_closestPointInfLineInfLine(const S00d22760_Vec& A, const S00d22760_Vec& dA, const S00d22760_Vec& B, const S00d22760_Vec& dB, S00d22760_LineResult& result);
__declspec(noinline) void __cdecl GetClosestLinePoints(const S00d22760_Vec& A, const S00d22760_Vec& dA, const S00d22760_Vec& B, const S00d22760_Vec& dB, float& distSquared, float& t, float& u, S00d22760_Vec& p, S00d22760_Vec& q)
{
    S00d22760_LineResult result;
    hkLineSegmentUtil_closestPointInfLineInfLine(A, dA, B, dB, result);
    p = result.m_kFirstVector;
    q = result.m_kSecondVector;
    t = result.m_fFirstParameter;
    u = result.m_fSecondParameter;
    distSquared = result.m_fValue;
}
// src: XBOX_PDB 0x00d224c0
__declspec(noinline) void __cdecl hkpCapsuleShape_closestPointLineSeg(const S00d22760_Vec& A, const S00d22760_Vec& B, const S00d22760_Vec& B2, S00d22760_Vec& pt)
{
    S00d22760_Vec d12;
    d12.setSub4(B, A);
    S00d22760_Vec dB;
    dB.setSub4(B2, B);
    float S2 = dB.dot3(d12);
    float D2 = dB.dot3(dB);
    float u = -S2;
    if (u <= 0.0f) {
        pt = B;
    } else if (D2 <= u) {
        pt = B2;
    } else {
        u /= D2;
        pt.setAddMul4(B, dB, u);
    }
}
S00d22760_Bool __cdecl Object_ProcessAndReturnValue_00cd85c0(float radius, const S00d22760_Input& input, S00d22760_Output& results);

class S00d22760_Capsule : public hkpConvexShape {
public:
    enum { HIT_CAP0 = 0, HIT_CAP1 = 1, HIT_BODY = 2 };
    __forceinline const S00d22760_Vec* GetIndexedVertices() const { return &m_kVertexA; }
    __forceinline const S00d22760_Vec& getVertex(int i) const { return GetIndexedVertices()[i]; }
    __declspec(noinline) S00d22760_Bool hkpCapsuleShape_castRayImpl(const S00d22760_Input& input, S00d22760_Output& results) const;
    int unk14;
    int unk18;
    int unk1c;
    S00d22760_Vec m_kVertexA;
    S00d22760_Vec m_kVertexB;
};

// @fnv 0x00d22760
// src: XBOX_PDB 0x00d22760
__declspec(noinline) S00d22760_Bool S00d22760_Capsule::hkpCapsuleShape_castRayImpl(const S00d22760_Input& input, S00d22760_Output& results) const
{
    {
        S00d22760_Stream& mStream = S00d22760_Stream::GetMonitorStream();
        if (mStream.memoryAvailable()) {
            S00d22760_TimerCommand* h = reinterpret_cast<S00d22760_TimerCommand*>(mStream.GetStreamEnd());
            h->m_pCommandName = "TtrcCapsule";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
    S00d22760_TimeHelper timeblock206;
    {
        S00d22760_Vec res;
        hkpCapsuleShape_closestPointLineSeg(input.m_vFrom, getVertex(0), getVertex(1), res);
        S00d22760_Vec join;
        join.setSub4(input.m_vFrom, res);
        float sToCylDistSq = join.lengthSquared3();
        if (sToCylDistSq < m_fSphereRadius * m_fSphereRadius) {
            goto returnFalse;
        }
        float infInfDistSquared = 3.40282e+38f;
        S00d22760_Vec dA;
        dA.setSub4(input.m_vTo, input.m_vFrom);
        S00d22760_Vec dB;
        dB.setSub4(getVertex(1), getVertex(0));
        float t;
        float u;
        S00d22760_Vec p;
        S00d22760_Vec q;
        GetClosestLinePoints(input.m_vFrom, dA, getVertex(0), dB, infInfDistSquared, t, u, p, q);
        if (infInfDistSquared > m_fSphereRadius * m_fSphereRadius) {
            goto returnFalse;
        }
        S00d22760_Vec axis;
        axis = dB;
        float axisLength;
        float ipT;
        {
            const float axisLengthSqrd = axis.lengthSquared3();
            if (axisLengthSqrd > 1.192092896e-07f) {
                axisLength = axis.normalizeWithLength3();
            } else {
                axisLength = 0.0f;
                axis.setZero4();
            }
            S00d22760_Vec dir = dA;
            S00d22760_SimdReal component = dir.dot3(axis);
            S00d22760_Vec flatDir;
            flatDir.setAddMul4(dir, axis, -component);
            const float flatDirLengthSquared3 = flatDir.lengthSquared3();
            if (flatDirLengthSquared3 != 0.0f) {
                float d = (m_fSphereRadius * m_fSphereRadius - infInfDistSquared) / flatDirLengthSquared3;
                ipT = t - S00d22760_sqrtf(d);
            } else {
                ipT = -1.0f;
            }
        }
        if (ipT >= results.m_fHitFraction) {
            goto returnFalse;
        }
        float pointAProj = getVertex(0).dot3(axis);
        S00d22760_Vec intersectPt;
        intersectPt.setInterpolate4(input.m_vFrom, input.m_vTo, ipT);
        const float ptProj = intersectPt.dot3(axis);
        float ptHeight = ptProj - pointAProj;
        if (ipT >= 0.0f && ptHeight > 0.0f && axisLength > ptHeight) {
            S00d22760_Vec projPtOnAxis;
            projPtOnAxis.setInterpolate4(getVertex(0), getVertex(1), ptHeight / axisLength);
            S00d22760_Vec normal;
            normal.setSub4(intersectPt, projPtOnAxis);
            normal.normalize3();
            results.m_vHitNormal = normal;
            results.m_fHitFraction = ipT;
            results.m_iExtraInfo = HIT_BODY;
            results.setKey(0xffffffff);
            return S00d22760_Bool(true);
        }
        {
            float fromLocalProj = input.m_vFrom.dot3(axis);
            float projParam = fromLocalProj - pointAProj;
            S00d22760_Vec fromPtProjAxis;
            fromPtProjAxis.setInterpolate4(getVertex(0), getVertex(1), projParam / axisLength);
            S00d22760_Vec axisToRayStart;
            axisToRayStart.setSub4(input.m_vFrom, fromPtProjAxis);
            if (ipT < 0.0f && axisToRayStart.lengthSquared3() > m_fSphereRadius * m_fSphereRadius) {
                goto returnFalse;
            }
            S00d22760_Input subInput;
            const int extra = (ptHeight <= 0.0f) ? HIT_CAP0 : HIT_CAP1;
            subInput.m_vFrom.setSub4(input.m_vFrom, getVertex(extra));
            subInput.m_vTo.setSub4(input.m_vTo, getVertex(extra));
            if (Object_ProcessAndReturnValue_00cd85c0(m_fSphereRadius, subInput, results)) {
                results.m_iExtraInfo = extra;
                return S00d22760_Bool(true);
            }
            return S00d22760_Bool(false);
        }
    }
returnFalse:
    return S00d22760_Bool(false);
}
