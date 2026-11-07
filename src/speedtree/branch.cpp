
// src/speedtree/branch.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/branch.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/NiPoint3.h"
// LocalVec: unit-local copy of the former shared stand-in Vec. This unit uses the stand-in's matrix/SpeedTree members (FUN_00c7f640/FUN_00c7f700 transforms, FUN_00b12790/FUN_00b13040), which NiPoint3 does not have.
#include <xmmintrin.h>
class Matrix;
class Scalar;
class Simd;
class Tok;
class Mask;
class Elem;
class Iter;
class CIter;
class CMutIter;
class Mat3;
class Mat4;
class hkVector4;
class hkQuaternion;

class LocalVec
{
public:
    union
    {
        struct
        {
            float x;
            float y;
            float z;
        };
        struct
        {
            void* m_pData;
            int m_iArrayLength;
            int m_iCapacity;
        };
    };

    LocalVec();
    LocalVec(float a, float b, float c);
    // Keep the implicit copy constructor, copy assignment and destructor trivial.

    void negative(const LocalVec& n);
    void inv(const Matrix& m, const LocalVec& n);
    void point(const Matrix& m, const LocalVec& b);
    void difference(const LocalVec& a, const LocalVec& b);
    Scalar dot(const LocalVec& n) const;
    Scalar at(int i) const;
    void set(float a, float b, float c, float d);

    Simd lengthSquared() const;
    void mul(const Simd& factor);
    void SetProduct(const Simd& factor, const LocalVec& v);

    void resize(unsigned n);
    Tok& operator[](unsigned i);
    void release(int elemSize);

    LocalVec& operator-=(const LocalVec& v);
    LocalVec& operator+=(const LocalVec& v);
    LocalVec operator*(float scale) const;
    LocalVec operator+(const LocalVec& v) const;
    LocalVec operator-(const LocalVec& v) const;
    float Squared() const;
    float Length() const;
    float Normalize();
    float Dot(const LocalVec& v) const;
    LocalVec Cross(const LocalVec& v) const;
    LocalVec ApplyScaled(float scale);
    LocalVec ApplyScaled(float scale) const;
    void ProcessState_00acf580(unsigned n, Tok value);
    LocalVec GetNegatedVector();
    LocalVec GetNegatedVector() const;
    LocalVec FUN_0053d1a0(const LocalVec& v);
    LocalVec FUN_004b3800(const LocalVec& v);
    LocalVec FUN_004b3800(const LocalVec& v) const;
    LocalVec FUN_00439e90(const LocalVec& v);
    LocalVec FUN_00439e90(const LocalVec& v) const;
    LocalVec SubtractIntoVector(const LocalVec& v);
    LocalVec SubtractIntoVector(const LocalVec& v) const;
    float FUN_00457990();
    float FUN_00457990() const;
    void Unitize_004a0c10();
    void FUN_006815c0();
    void ScaleComponents(float scale);
    LocalVec& ComputeValue_0063c8a0(const LocalVec& v);
    float FUN_004a7290();
    float FUN_004a7290() const;
    void SetQuaternionComponentsFromVector(const float* values);
    void FUN_00a38560();
    void NiQuaternion_ToRotation(void* value);

    LocalVec& ScaleByInverse(float divisor);
    float FUN_00457910();
    LocalVec* FastNavMeshTriLocation_GetLocation();
    bool HasEqualComponents(const LocalVec& v);

    __m128 get() const;
    void set(__m128 value);
    void operator=(const __m128& value);
    operator __m128() const;
    __m128& getQuad();
    const __m128& getQuad() const;
    __m128& quad();
    const __m128& quad() const;
    float& operator()(int component);
    const float& operator()(int component) const;
    void setZero4();
    void setSub4(const LocalVec& a, const LocalVec& b);
    void setAdd4(const LocalVec& a, const LocalVec& b);
    void setMul4(const LocalVec& a, const LocalVec& b);
    void setMul4(const Scalar& a, const LocalVec& b);
    void add4(const LocalVec& v);
    void mul4(const LocalVec& v);
    void mul4(const Scalar& value);
    void add3clobberW(const LocalVec& v);
    void sub3clobberW(const LocalVec& v);
    void setBroadcast3clobberW(const LocalVec& v, int component);
    Scalar horizontalAdd3() const;
    void setCross(const LocalVec& a, const LocalVec& b);
    Scalar dot3(const LocalVec& v) const;
    Scalar lengthSquared3() const;
    Scalar lengthInverse3() const;
    void normalize3();
    Scalar getSimdAt(int component) const;
    void setInterpolate4(const LocalVec& a, const LocalVec& b, const Scalar& fraction);
    void setAddMul4(const LocalVec& a, const LocalVec& b, const Scalar& scale);
    void setNeg4(const LocalVec& v);
    Mask compareLessThanZero4() const;
    void SetRotatedDirection(const hkQuaternion& rotation, const LocalVec& direction);
    void setRotatedTranslation(const hkQuaternion& rotation, const LocalVec& direction);
    void cross(const LocalVec& a, const LocalVec& b);
    Scalar squared() const;
    Scalar inverseLength() const;
    void normalize();
    void negate(const LocalVec& v);

    void setTransformedPos_00c7f640(const void* matrix, const hkVector4& point);
    void setTransformedPos_00c7f640(Mat4* matrix, void* point);
    void setTransformedPos_00c7f640(const void* matrix, const LocalVec* point);
    void setTransformedPos_00c7f640(const void* matrix, const void* point);
    void hkVector4_setRotatedDir(Mat3* matrix, void* point);
    void hkVector4_setRotatedDir(const void* matrix, const LocalVec* point);
    void Normalize_00b12790();
    void Diff_00b13040(LocalVec* out, const LocalVec* v);
    LocalVec* ScaleSwizzled(LocalVec* out, float factor);
    void AddVector(LocalVec* out, const LocalVec* v);
    float Dot(const LocalVec& v);
    LocalVec* FUN_004a3c90(const LocalVec* v);
    LocalVec* FUN_0062b0a0(LocalVec* out, LocalVec* v);
    LocalVec* hkVector4_lengthInverse3(LocalVec* target);

    void FUN_00cf7690(Elem* value);
    void UpdateState_00b1e970();
    Iter begin();
    Iter end();
    CIter UpdateState_00b33030(CIter first, CIter last);
    void m_vStrips_clear();
    unsigned int size() const;
    unsigned int capacity() const;
    void ClearAllElements();
    void B2EDestroyRange_Thunk(Elem* first, Elem* last);
    bool InitBuffer(unsigned int count);
    Elem* _Ucopy(Elem* first, Elem* last, Elem* out);
    LocalVec& CTreeEngine_SetLeafTextures(const LocalVec& v);
    CMutIter ProcessAndReturnValue_00aceb80(CMutIter first, CMutIter last);
    void ProcessState_00acac40();
    LocalVec& ReleaseStorage_00ad61e0(const LocalVec& v);
};

extern int DAT_011ad14c;

struct FUN_00b14ae0_class
{
    float ComputeValue_00b14ae0(int id, float a, float b);
};

// Returns 1.0, or 1.0 minus a*b when id equals DAT_011ad14c.
// @fnv 0x00b14ae0
// src: GUESS 0x00b14ae0 (confidence: low)
float FUN_00b14ae0_class::ComputeValue_00b14ae0(int id, float a, float b)
{
    float result = 1.0f;
    if (id == DAT_011ad14c)
        result = result - a * b;
    return result;
}

unsigned int __cdecl FUN_00ec7c56(void);

struct FUN_00b15170
{
    char m_00[0xc];
    char* m_0c;
    char* m_10;
    char* GetElement(unsigned int a);
};

// Returns a pointer to the element at index a in the buffer from m_0c to m_10, calling FUN_00ec7c56 if a is out of range.
// @fnv 0x00b15170
char* FUN_00b15170::GetElement(unsigned int uiIndex)
{
    if (uiIndex >= (unsigned int)(m_10 - m_0c))
        FUN_00ec7c56();
    return m_0c + uiIndex;
}

struct FUN_00b2a180
{
    float a;
    float b;
    float c;
    float Dot(const NiPoint3& point);
};

// @fnv 0x00b2a180
float FUN_00b2a180::Dot(const NiPoint3& point)
{
    return a * point.x + b * point.y + c * point.z;
}

double __cdecl FUN_00ec6054(double);
// Normalizes the vector by dividing x, y and z by the square root of the sum of their squares.
// @fnv 0x00b12790
// src: COMMUNITY 0x00b12790
void LocalVec::Normalize_00b12790()
{
    float fSumOfSquares;
    float fInvSquareRoot;
    fSumOfSquares = x * x + y * y + z * z;
    fInvSquareRoot = 1.0f / (float)FUN_00ec6054((double)fSumOfSquares);
    x *= fInvSquareRoot;
    y *= fInvSquareRoot;
    z *= fInvSquareRoot;
}

struct FUN_00b0cff0_class
{
    float x;
    float y;
    float z;
    NiPoint3* __thiscall ScaleSwizzled(NiPoint3* output, float factor);
};
// Multiplies each component by factor and writes them to output with x/y/z rotated (x<-y, y<-z, z<-x), returning output.
// @fnv 0x00b0cff0
NiPoint3* FUN_00b0cff0_class::ScaleSwizzled(NiPoint3* output, float factor)
{
    float z = factor * this->x;
    float x = factor * this->y;
    float y = factor * this->z;
    output->x = z;
    output->y = x;
    output->z = y;
    return output;
}

extern double __cdecl FUN_00eca190(double value);
struct This : FUN_00b2a180
{
    float CVec3_AngleBetween(const NiPoint3& point);
};
// Computes the dot product of point with this object, clamps it to [-1, 1], and returns the result of FUN_00eca190 on the clamped value.
// @fnv 0x00b12720
// src: COMMUNITY 0x00b12720
float This::CVec3_AngleBetween(const NiPoint3& point)
{
    float value = Dot(point);
    if (value < -1.0f)
        value = -1.0f;
    if (value > 1.0f)
        value = 1.0f;
    return (float)FUN_00eca190(value);
}

struct State
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    float threshold;
    float upper;
    int count;
};
extern State* DAT_011f8bf4;
struct GlobalObject_00b3f100
{
    float FUN_00b3f130(float, float);
};
extern GlobalObject_00b3f100 g_011f8c05;
struct Link
{
    Link* next;
    float value;
};
struct Owner
{
    bool TestThresholdAndRandomLimit(Link* link, float input);
};
// @fnv 0x00b13b50
// src: GUESS 0x00b13b50 (confidence: medium)
bool Owner::TestThresholdAndRandomLimit(Link* link, float input)
{
    bool result = false;
    {
        float value = input;
        if (DAT_011f8bf4->count == 0)
        {
            int current = 1;
            Link* index = link;
            Link* next;
            while (index != 0 && (next = index->next) != 0 && current < DAT_011f8bf4->count)
            {
                index = index->next;
                ++current;
            }
            if (index != 0)
                value = index->value;
        }
        if (value > DAT_011f8bf4->threshold)
        {
            if (g_011f8c05.FUN_00b3f130(0.0f, 1.0f) <= DAT_011f8bf4->upper)
                result = true;
        }
    }
    return result;
}

struct B4230Point3
{
    float x;
    float y;
    float z;

    float FastSqrt() const;
};

// Computes the square root of the squared length of the vector via a bit-shift approximation on the float bits.
// @fnv 0x00b14230
float B4230Point3::FastSqrt() const
{
    float fSqrLength = z * z + (y * y + x * x);
    int iSqrtBits = ((*(int*)&fSqrLength) >> 1) + 0x1fc00000;
    return *(float*)&iSqrtBits;
}

// FUN_00b14b10 - blends the first argument towards zero by the second one
// (value - value * factor).  The double literal 0.0 is what makes MSVC 2008
// build the x87 register-to-register multiply instead of the memory-operand one.
struct FUN_00b14b10_class
{
    float UpdateState_00b14b10(float value, float factor);
};

// @fnv 0x00b14b10
// src: GUESS 0x00b14b10 (confidence: low)
float FUN_00b14b10_class::UpdateState_00b14b10(float value, float factor)
{
    float result = factor * (0.0 - value) + value;
    return result;
}

struct b14_sub
{
    float x, y, z;
    float CVec3_Distance(b14_sub* other);
};

struct b14_elem
{
    char unk00[0xc];
    b14_sub sub;
    float unk18;
    char unk1c[0x2c];
};

struct b14_ctx
{
    char unk00[0x20];
    b14_elem* unk20;
    int unk24;
    char unk28[8];
    float unk30;
    void CIdvBranch_ComputeVolume();
};

// @fnv 0x00b14b40
// src: COMMUNITY 0x00b14b40
void b14_ctx::CIdvBranch_ComputeVolume()
{
    if (this->unk20 != 0)
    {
        if (this->unk24 > 1)
        {
            this->unk30 = 0.0f;
            for (int i = 0; i < this->unk24 - 1; i++)
            {
                b14_elem* pCurrent = &this->unk20[i];
                float sum;
                b14_elem* m_pActionSuccessor = &this->unk20[i] + 1;
                {
                    int t1;
                    int t2;
                    sum = pCurrent->sub.CVec3_Distance(&m_pActionSuccessor->sub);
                    this->unk30 = (pCurrent->unk18 + m_pActionSuccessor->unk18) * sum + this->unk30;
                }
            }
        }
    }
}

struct FUN_00b14be0_cls;

struct SegmentEntry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    float f40;
    int unk44;
};

struct OutPair
{
    int idx;
    float t;
};

struct FUN_00b14be0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    SegmentEntry* m_20;
    int m_24;
    void FindSegment(OutPair* out, float v);
};

// @fnv 0x00b14be0
void FUN_00b14be0_cls::FindSegment(OutPair* out, float afValue)
{
    if (m_20 != 0 && m_24 >= 2)
    {
        out->idx = 0;
        for (int i = 1; i < m_24; ++i)
        {
            if (afValue < m_20[i].f40)
            {
                out->idx = i - 1;
                break;
            }
        }
        out->t = (afValue - m_20[out->idx].f40) / (m_20[out->idx + 1].f40 - m_20[out->idx].f40);
    }
}

// @fnv 0x00b15110
// src: GUESS 0x00b15110 (confidence: low)
float __cdecl Branch_UpdateState_00b15110(Link* link)
{
    float ratio;
    Link* rest;
    if (link == 0 || (rest = link->next) == 0)
    {
        return 0.0f;
    }
    {
        Link* next = link->next;
        ratio = Branch_UpdateState_00b15110(next);
        float b = link->value;
        float ret = (1.0f - ratio) * b + ratio;
        return ret;
    }
}

// The class that owns ProjectOntoLine (in the game it derives from the vector
// class, so `this` points at the three floats a, b and c).
struct MyThis
{
    float a, b, c;
    LocalVec* ProjectOntoLine(LocalVec* out, LocalVec* a, LocalVec* b, LocalVec* c);
};

// The function projects the point c onto the line through a and b.
//
// This unit is compiled unoptimised, and there the compiler lays the frame
// out in the order of a hash of the local names, so the names below are
// picked to reproduce the original's frame byte for byte:
//   ebp-0x68  the compiler's own temporary for the 0/1 result
//   ebp-0x64  this
//   ebp-0x60 .. ebp-0x2c  56 bytes of dead temporaries (m, o, L, U, i2, l2)
//   ebp-0x28  e   (the scaled direction)
//   ebp-0x1c  dir (the dot product)
//   ebp-0x18  ejne (the normalised direction)
//   ebp-0x0c  z   (c - a)
// @fnv 0x00b3ec40
LocalVec* MyThis::ProjectOntoLine(LocalVec* out, LocalVec* a, LocalVec* pLineStart, LocalVec* c)
{
    // Raw, float-aligned storage preserves the original uninitialized locals.
    float m[sizeof(LocalVec) / sizeof(float)];
    float o[sizeof(LocalVec) / sizeof(float)];
    float L[sizeof(LocalVec) / sizeof(float)];
    float U[sizeof(LocalVec) / sizeof(float)];
    float i2;
    float l2;
    float e[sizeof(LocalVec) / sizeof(float)];
    float dir;
    float ejne[sizeof(LocalVec) / sizeof(float)];
    float z[sizeof(LocalVec) / sizeof(float)];
    if ((unsigned char)((a->x == pLineStart->x && a->y == pLineStart->y && a->z == pLineStart->z) ? 1 : 0))
    {
        *out = *a;
        return out;
    }
    pLineStart->Diff_00b13040((LocalVec*)ejne, a);
    ((LocalVec*)ejne)->Normalize_00b12790();
    c->Diff_00b13040((LocalVec*)z, a);
    dir = ((LocalVec*)z)->Dot(*(LocalVec*)ejne);
    a->AddVector(out, ((LocalVec*)ejne)->ScaleSwizzled((LocalVec*)e, dir));
    return out;
}

extern unsigned int __cdecl FUN_00ec7c56(void);

struct S_00b14280_Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    float m_ucLowNibble;
    float m_ucHighNibble;
    int unk50;
};

struct S_00b14280_Entries
{
    int unk00;
    int unk04;
    int unk08;
    S_00b14280_Entry* m_pRayStart;
    S_00b14280_Entry* m_kRayEnd;
};

struct S_00b14280_Obj
{
    int unk00;
    NiPoint3 m_pos;
};

struct S_00b14280_List
{
    int unk00;
    int unk04;
    int unk08;
    S_00b14280_Obj** m_pRayStart;
    S_00b14280_Obj** m_kRayEnd;
};

struct S_00b14280_State
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00b14280_Entries m_entries;
    int unk24;
    float m_threshold;
};

struct S_00b14280_This
{
    bool IsPointClearOfEntries(const NiPoint3& pt, unsigned int index, S_00b14280_List* list);
};

// @fnv 0x00b14280
bool S_00b14280_This::IsPointClearOfEntries(const NiPoint3& aPoint, unsigned int index, S_00b14280_List* list)
{
    bool ok5 = true;
    float r7;
    unsigned int i;
    S_00b14280_Entries* a8;
    S_00b14280_Entries* b;
    S_00b14280_Entry* en7;
    S_00b14280_Obj** p5;
    const NiPoint3* RunSeventhVirtualOperation;
    a8 = &((S_00b14280_State*)DAT_011f8bf4)->m_entries;
    if ((unsigned char)(((a8->m_kRayEnd - a8->m_pRayStart) == 0) ? 1 : 0) == 0)
    {
        b = &((S_00b14280_State*)DAT_011f8bf4)->m_entries;
        if (index >= (unsigned int)(b->m_kRayEnd - b->m_pRayStart))
            FUN_00ec7c56();
        en7 = &b->m_pRayStart[index];
        r7 = (en7->m_ucLowNibble > en7->m_ucHighNibble) ? en7->m_ucLowNibble : en7->m_ucHighNibble;
        r7 = r7 * ((S_00b14280_State*)DAT_011f8bf4)->m_threshold;
        for (i = 0; i < (unsigned int)(list->m_kRayEnd - list->m_pRayStart) && ok5; i++)
        {
            if (i >= (unsigned int)(list->m_kRayEnd - list->m_pRayStart))
                FUN_00ec7c56();
            p5 = &list->m_pRayStart[i];
            RunSeventhVirtualOperation = &(*p5)->m_pos;
            if (aPoint.x < RunSeventhVirtualOperation->x + r7 && aPoint.x > RunSeventhVirtualOperation->x - r7 &&
                aPoint.y < RunSeventhVirtualOperation->y + r7 && aPoint.y > RunSeventhVirtualOperation->y - r7 &&
                aPoint.z < RunSeventhVirtualOperation->z + r7 && aPoint.z > RunSeventhVirtualOperation->z - r7)
                ok5 = false;
        }
    }
    else
    {
        ok5 = false;
    }
    return ok5;
}

struct AngleState
{
    LocalVec heading;
    float radians;
    float unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
};

struct FacingTint
{
    int unk00;
    LocalVec* CBillboardLeaf_GetColor(LocalVec* out);
    void CBillboardLeaf_SetColor(LocalVec* point, int flag);
    void CBillboardLeaf_AdjustStaticLighting(LocalVec* point, LocalVec* other, float t);
};

extern double __cdecl FUN_00ec9f30(double value);
extern double DAT_01011588;

// @fnv 0x00b40210
// src: COMMUNITY 0x00b40210
void FacingTint::CBillboardLeaf_AdjustStaticLighting(LocalVec* point, LocalVec* other, float t)
{
    // Avoid invoking LocalVec constructors for the original uninitialized scratch storage.
    float goal[sizeof(LocalVec) / sizeof(float)];
    float sample[sizeof(LocalVec) / sizeof(float)];
    float length;
    float scale;
    float scaled[sizeof(LocalVec) / sizeof(float)];
    float dest[sizeof(LocalVec) / sizeof(float)];
    float basis[sizeof(AngleState) / sizeof(float)];
    ((LocalVec*)((char*)this + 4))->Diff_00b13040((LocalVec*)sample, point);
    ((LocalVec*)sample)->Normalize_00b12790();
    other->Diff_00b13040((LocalVec*)goal, point);
    ((LocalVec*)goal)->Normalize_00b12790();
    ((AngleState*)basis)->radians = ((This*)sample)->CVec3_AngleBetween(*(NiPoint3*)goal);
    length = (float)(double)(float)FUN_00ec9f30(((AngleState*)basis)->radians);
    scale = (float)((length + 1.0) * DAT_01011588) * (1.0f - t) + t;
    this->CBillboardLeaf_SetColor(this->CBillboardLeaf_GetColor((LocalVec*)scaled)->ScaleSwizzled((LocalVec*)dest, scale), 1);
}

#include <stdlib.h>
// Returns a random float between minimum and maximum by scaling rand() to the range width and offsetting by minimum.
// @fnv 0x00b14e90
// src: GUESS 0x00b14e90 (confidence: high)
float Branch_GetRandomFloatInRange(float minimum, float maximum)
{
    float fraction = (float)(rand() / 32767.0);
    float range = maximum - minimum;
    return fraction * range + minimum;
}
