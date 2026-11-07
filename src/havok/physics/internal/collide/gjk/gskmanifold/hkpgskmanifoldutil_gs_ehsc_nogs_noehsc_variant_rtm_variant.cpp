// src/havok/physics/internal/collide/gjk/gskmanifold/hkpgskmanifoldutil_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/internal/collide/gjk/gskmanifold/hkpgskmanifoldutil_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/internal/collide/gjk/gskmanifold/hkpgskmanifoldutil_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/internal/collide/gjk/gskmanifold/hkpgskmanifoldutil.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/internal/collide/gjk/gskmanifold/hkpgskmanifoldutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/gskmanifold/hkpgskmanifoldutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct S_00dad640_Entry
{
    unsigned short unk0;
    unsigned short id;
    unsigned int unk4;
};
struct S_00dad640_Set
{
    unsigned char unk0;
    unsigned char unk1;
    unsigned char count;
    unsigned char unk3;
    S_00dad640_Entry entries[1];
};
struct S_00dad640_Target
{
    virtual void unk0();
    virtual void unk4();
    virtual void unk8();
    virtual void unkC();
    virtual void unk10();
    virtual void Release(unsigned short id, void* arg);
};
void ReleaseAllEntries(S_00dad640_Set* set, S_00dad640_Target* target, void* arg);
struct S_00dad4d0_Key
{
    unsigned short ids[4];
    unsigned char numA;
    unsigned char numB;
};
struct S_00dad4d0_Entry
{
    unsigned char numA;
    unsigned char numB;
    unsigned char unk2;
    unsigned char unk3;
    unsigned char offs[4];
};
struct S_00dad4d0_Raw
{
    unsigned int lo;
    unsigned int hi;
};
struct S_00dad4d0_Set
{
    unsigned char unk0;
    unsigned char unk1;
    unsigned char count;
    unsigned char unk3;
    S_00dad4d0_Entry entries[1];

    unsigned short Id(unsigned char off)
    {
        return *(unsigned short*)((char*)&entries[count] + (off >> 3));
    }
};
bool FindAndPromoteEntry(S_00dad4d0_Set* set, S_00dad4d0_Key* key);
void __fastcall hkGskManifold_garbageCollect(int unused, S_00dad640_Set* set);
void __cdecl _hkGskManifold_removePoint(S_00dad640_Set* set, unsigned int index);
#include <xmmintrin.h>
extern float DAT_0104da48;
struct __declspec(align(16)) S_00daee00_Vec
{
    float x;
    float y;
    float z;
    float w;

    void setSub4(const S_00daee00_Vec& a, const S_00daee00_Vec& b)
    {
        *(__m128*)this = _mm_sub_ps(*(const __m128*)&a, *(const __m128*)&b);
    }
    void setCross(const S_00daee00_Vec& a, const S_00daee00_Vec& b)
    {
        __m128 v1 = *(const __m128*)&a;
        __m128 v2 = *(const __m128*)&b;
        __m128 c0 = _mm_mul_ps(_mm_shuffle_ps(v1, v1, 0xc9), _mm_shuffle_ps(v2, v2, 0xd2));
        __m128 c1 = _mm_mul_ps(_mm_shuffle_ps(v1, v1, 0xd2), _mm_shuffle_ps(v2, v2, 0xc9));
        *(__m128*)this = _mm_sub_ps(c0, c1);
    }
    void storeLengthSquared3(float& f) const
    {
        __m128 v = *(const __m128*)this;
        __m128 x2 = _mm_mul_ps(v, v);
        __m128 r = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
        _mm_store_ss(&f, r);
    }
};
struct S_00daee00_Point
{
    S_00daee00_Vec pos;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    float unk24;
    float unk28;
    float unk2C;
};
struct S_00daee00
{
    S_00daee00_Point points[5];
    int hkGskManifold_findRedundant5thPoint();
};
struct S_00dad720_Vec
{
    __m128 m_afExtents[16];
    __m128 m_v100;
    int unk110;
    int unk114;
    int unk118;
    float m_pFreeList;
};
struct S_00dad720_Out
{
    __m128 m_v0;
    __m128 m_v10;
    __m128 m_v20;
};
struct S_00dad720_Rec
{
    int unk0;
    unsigned char m_kPointA;
    unsigned char m_kPointB;
    unsigned char m_iThirdValue;
};
extern const __m128 DAT_010ec7f0;
static __forceinline __m128 Cross3(const __m128& a, const __m128& b)
{
    __m128 t0 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    __m128 t1 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    return _mm_sub_ps(t1, t0);
}
static __forceinline __m128 Dot3_3vs3(const __m128& a0, const __m128& b0, const __m128& a1, const __m128& b1,
                                      const __m128& a2, const __m128& b2)
{
    __m128 m0 = _mm_mul_ps(a0, b0);
    __m128 m1 = _mm_mul_ps(a1, b1);
    __m128 m2 = _mm_mul_ps(a2, b2);
    __m128 tmp = _mm_unpacklo_ps(m0, m1);
    __m128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(m0, m1), m2, 0xe4);
    m0 = _mm_movelh_ps(tmp, m2);
    m1 = _mm_shuffle_ps(_mm_movehl_ps(m0, tmp), m2, 0xd4);
    m2 = ctmp;
    return _mm_add_ps(_mm_add_ps(m0, m1), m2);
}
static int Object_ProcessAndReturnValue_00dad720(S_00dad720_Rec* rec, S_00dad720_Vec* vecs, S_00dad720_Out* out);
volatile int g_rec;
volatile int g_vecs;
volatile int g_out;
volatile int g_res;
void CallTarget_dad720();
#include <xmmintrin.h>
struct S_00dae220_Entry
{
    unsigned char numA;
    unsigned char numB;
    unsigned char unk2;
    unsigned char unk3;
    unsigned char offs[4];
};
struct S_00dae220_Set
{
    unsigned char numA;
    unsigned char numB;
    unsigned char count;
    unsigned char unk3;
    S_00dae220_Entry entries[1];
};
void __fastcall hkGskManifold_garbageCollect(int unused, S_00dae220_Set* set);
extern "C" void _ReadWriteBarrier(void);
struct ContactManifold
{
    unsigned char unk0;
    unsigned char unk1;
    unsigned char count;
    unsigned char unk3;
    S_00dad640_Entry entries[4];
};
struct ContactRecord
{
    __m128 position;
    __m128 normal;
    unsigned id;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
};
struct ContactCache
{
    ContactRecord points[4];
    int hkGskManifold_findRedundant5thPoint();
};
struct ContactContext
{
    unsigned unk00;
    void* userData;
};
struct ContactManager
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual unsigned short add(void* a, void* b, void* c, ContactContext* context, S_00dad4d0_Key* key,
                               ContactRecord* point);
    virtual void slot4();
    virtual void remove(unsigned short id, void* userData);
};
static inline void CopyContact(ContactRecord& destination, const ContactRecord& source)
{
    destination.position = source.position;
    destination.normal = source.normal;
    destination.id = source.id;
}
static inline unsigned short* VertexIds(ContactManifold* set)
{
    return reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(set) + 4 + set->count * 8);
}
static inline S_00dad4d0_Entry& ContactEntry(ContactManifold* set, unsigned index)
{
    return *reinterpret_cast<S_00dad4d0_Entry*>(reinterpret_cast<char*>(set) + 4 + index * 8);
}
static void __fastcall hkGskManifold_garbageCollect(int, ContactManifold* set);
int hkGskManifold_addPoint(ContactManifold* set, void* a, void* b, void* c, ContactContext* context, S_00dad4d0_Key* key,
                 ContactRecord* point, ContactCache* cache, ContactManager* manager, int defer);
// src: COMMUNITY 0x00dae220
static __declspec(noinline) void __fastcall hkGskManifold_garbageCollect(int, ContactManifold* set)
{
    __declspec(align(16)) unsigned int usedWords[4];
    _mm_store_ps(reinterpret_cast<float*>(usedWords), _mm_setzero_ps());
    unsigned char* used = reinterpret_cast<unsigned char*>(usedWords);
    unsigned remap[16];
    unsigned contactCount = set->count;
    unsigned char* offs = ContactEntry(set, 0).offs;
    for (unsigned k = 0; k < contactCount; ++k)
    {
        int total = offs[-4] + offs[-3];
        used[offs[0] >> 4] = 1;
        used[offs[1] >> 4] = 1;
        if (total >= 3)
            used[offs[2] >> 4] = 1;
        if (total == 4)
            used[offs[3] >> 4] = 1;
        offs += 8;
    }
    unsigned short* vertices = reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(set) + 4 + contactCount * 8);
    int total = set->unk0 + set->unk1;
    unsigned count = 0;
    unsigned offset = 0;
    for (int i = 0; i < total; ++i)
    {
        remap[i] = offset;
        if (used[i])
        {
            vertices[count++] = vertices[i];
            offset += 16;
        }
    }
    unsigned countA = remap[set->unk0] >> 4;
    set->unk0 = static_cast<unsigned char>(countA);
    set->unk1 = static_cast<unsigned char>(count - countA);
    for (unsigned i = 0; i < set->count; ++i)
    {
        S_00dad4d0_Entry& entry = ContactEntry(set, i);
        entry.offs[0] = static_cast<unsigned char>(remap[entry.offs[0] >> 4]);
        entry.offs[1] = static_cast<unsigned char>(remap[entry.offs[1] >> 4]);
        entry.offs[2] = static_cast<unsigned char>(remap[entry.offs[2] >> 4]);
        entry.offs[3] = static_cast<unsigned char>(remap[entry.offs[3] >> 4]);
    }
}

extern const __m128 DAT_010ec7f0;
extern const __m128 DAT_010c44d0;
class Scalar
{
    __m128 value;

  public:
    Scalar()
    {}
    Scalar(const __m128& input) : value(input)
    {}
    Scalar(float input)
    {
        value = _mm_load_ss(&input);
    }
    operator float() const
    {
        float result;
        _mm_store_ss(&result, value);
        return result;
    }
    __forceinline const __m128& getQuad() const
    {
        return value;
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
};
__forceinline Scalar operator+(const Scalar& a, const Scalar& b)
{
    return _mm_add_ss(a.getQuad(), b.getQuad());
}
__forceinline Scalar operator-(const Scalar& a, const Scalar& b)
{
    return _mm_sub_ss(a.getQuad(), b.getQuad());
}
__forceinline Scalar operator/(const Scalar& a, const Scalar& b)
{
    return _mm_div_ss(a.getQuad(), b.getQuad());
}
class Mask
{
    __m128 bits;
    friend class ManifoldVector4;

  public:
    enum
    {
        MASK_XY = 3
    };
    __forceinline int anyIsSet(int m) const
    {
        return _mm_movemask_ps(bits) & m;
    }
    __forceinline int GetLaneMask() const
    {
        return _mm_movemask_ps(bits);
    }
};
// hkVector4 with the unit's own inline Havok 7.1 SIMD bodies (setCross, dot3, normalize3, setInterpolate4, compareLessThanZero4...) over a private __m128.
class ManifoldVector4
{
    __m128 value;

  public:
    __forceinline ManifoldVector4()
    {}
    __forceinline ManifoldVector4(const ManifoldVector4& input) : value(input.value)
    {}
    __forceinline void operator=(const ManifoldVector4& input)
    {
        value = input.value;
    }
    __forceinline void operator=(const __m128& input)
    {
        value = input;
    }
    __forceinline __m128& getQuad()
    {
        return value;
    }
    __forceinline const __m128& getQuad() const
    {
        return value;
    }
    __forceinline float& operator()(int n)
    {
        return reinterpret_cast<float*>(&value)[n];
    }
    __forceinline const float& operator()(int n) const
    {
        return reinterpret_cast<const float*>(&value)[n];
    }
    __forceinline void setZero4()
    {
        value = _mm_setzero_ps();
    }
    __forceinline void setSub4(const ManifoldVector4& a, const ManifoldVector4& b)
    {
        value = _mm_sub_ps(a.value, b.value);
    }
    __forceinline void setAdd4(const ManifoldVector4& a, const ManifoldVector4& b)
    {
        value = _mm_add_ps(a.value, b.value);
    }
    __forceinline void setCross(const ManifoldVector4& a, const ManifoldVector4& b)
    {
        __m128 left = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xc9), _mm_shuffle_ps(b.value, b.value, 0xd2));
        __m128 right = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xd2), _mm_shuffle_ps(b.value, b.value, 0xc9));
        value = _mm_sub_ps(left, right);
    }
    __forceinline Scalar dot3(const ManifoldVector4& b) const
    {
        __m128 terms = _mm_mul_ps(value, b.value);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(terms, terms, 0x55), terms);
        return _mm_add_ss(_mm_shuffle_ps(terms, terms, 0xaa), sum);
    }
    __forceinline Scalar lengthSquared3() const
    {
        return dot3(*this);
    }
    __forceinline Scalar lengthInverse3() const
    {
        const __m128 half = _mm_set_ss(0.5f);
        const __m128 three = _mm_set_ss(3.0f);
        const __m128 zero = _mm_set_ss(0.0f);
        const __m128 square = dot3(*this).getQuad();
        const __m128 equal = _mm_cmpeq_ss(square, zero);
        const __m128 approx = _mm_rsqrt_ss(square);
        const __m128 refined =
            _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(square, approx), approx)));
        return _mm_andnot_ps(equal, refined);
    }
    __forceinline void normalize3()
    {
        __m128 reciprocal = lengthInverse3().broadcast();
        value = _mm_mul_ps(reciprocal, value);
    }
    __forceinline Scalar getSimdAt(int n) const
    {
        switch (n)
        {
        case 0:
            return value;
        case 1:
            return _mm_shuffle_ps(value, value, 0x55);
        case 2:
            return _mm_shuffle_ps(value, value, 0xaa);
        default:
            return _mm_shuffle_ps(value, value, 0xff);
        }
    }
    __forceinline void setInterpolate4(const ManifoldVector4& a, const ManifoldVector4& b, const Scalar& fraction)
    {
        __m128 t = fraction.broadcast();
        __m128 s = _mm_sub_ps(DAT_010ec7f0, t);
        value = _mm_add_ps(_mm_mul_ps(s, a.value), _mm_mul_ps(t, b.value));
    }
    __forceinline void setAddMul4(const ManifoldVector4& a, const ManifoldVector4& b, const Scalar& scale)
    {
        value = _mm_add_ps(a.value, _mm_mul_ps(scale.broadcast(), b.value));
    }
    __forceinline void setNeg4(const ManifoldVector4& a)
    {
        value = _mm_xor_ps(a.value, DAT_010c44d0);
    }
    __forceinline Mask compareLessThanZero4() const
    {
        Mask result;
        result.bits = _mm_cmplt_ps(value, _mm_setzero_ps());
        return result;
    }
};
template <class T> class Field
{
    T value;

  public:
    __forceinline Field()
    {}
    __forceinline Field(T input) : value(input)
    {}
    __forceinline void operator=(T input)
    {
        value = input;
    }
    __forceinline T val() const
    {
        return value;
    }
    __forceinline T operator->() const
    {
        return value;
    }
    __forceinline operator T() const
    {
        return val();
    }
};
namespace Parallel {
__forceinline void dot3_3vs3(const ManifoldVector4& a, const ManifoldVector4& b, const ManifoldVector4& c, const ManifoldVector4& d, const ManifoldVector4& e, const ManifoldVector4& f,
                             ManifoldVector4& result)
{
    register __m128 ab = _mm_mul_ps(a.getQuad(), b.getQuad());
    register __m128 cd = _mm_mul_ps(c.getQuad(), d.getQuad());
    register __m128 ef = _mm_mul_ps(e.getQuad(), f.getQuad());
    __m128 lower = _mm_unpacklo_ps(ab, cd);
    __m128 upper = _mm_shuffle_ps(_mm_unpackhi_ps(ab, cd), ef, 0xe4);
    ab = _mm_movelh_ps(lower, ef);
    cd = _mm_shuffle_ps(_mm_movehl_ps(ab, lower), ef, 0xd4);
    ef = upper;
    result.getQuad() = _mm_add_ps(_mm_add_ps(ab, cd), ef);
}
__forceinline void dot3_1vs4(const ManifoldVector4& v, const ManifoldVector4& a, const ManifoldVector4& b, const ManifoldVector4& c, const ManifoldVector4& d, ManifoldVector4& result)
{
    register __m128 va = _mm_mul_ps(a.getQuad(), v.getQuad());
    register __m128 vb = _mm_mul_ps(b.getQuad(), v.getQuad());
    register __m128 vc = _mm_mul_ps(c.getQuad(), v.getQuad());
    register __m128 vd = _mm_mul_ps(d.getQuad(), v.getQuad());
    __m128 abLo = _mm_shuffle_ps(va, vb, 0x44);
    __m128 abHi = _mm_shuffle_ps(va, vb, 0xee);
    __m128 cdLo = _mm_shuffle_ps(vc, vd, 0x44);
    __m128 cdHi = _mm_shuffle_ps(vc, vd, 0xee);
    va = _mm_shuffle_ps(abLo, cdLo, 0x88);
    vb = _mm_shuffle_ps(abLo, cdLo, 0xdd);
    vc = _mm_shuffle_ps(abHi, cdHi, 0x88);
    vd = _mm_shuffle_ps(abHi, cdHi, 0xdd);
    result.getQuad() = _mm_add_ps(_mm_add_ps(va, vb), vc);
}
__forceinline void dot3_2vs2(const ManifoldVector4& a, const ManifoldVector4& b, const ManifoldVector4& c, const ManifoldVector4& d, ManifoldVector4& result)
{
    register __m128 ac = _mm_mul_ps(a.getQuad(), c.getQuad());
    register __m128 ad = _mm_mul_ps(a.getQuad(), d.getQuad());
    register __m128 bc = _mm_mul_ps(b.getQuad(), c.getQuad());
    register __m128 bd = _mm_mul_ps(b.getQuad(), d.getQuad());
    __m128 aLo = _mm_shuffle_ps(ac, ad, 0x44);
    __m128 aHi = _mm_shuffle_ps(ac, ad, 0xee);
    __m128 bLo = _mm_shuffle_ps(bc, bd, 0x44);
    __m128 bHi = _mm_shuffle_ps(bc, bd, 0xee);
    ac = _mm_shuffle_ps(aLo, bLo, 0x88);
    ad = _mm_shuffle_ps(aLo, bLo, 0xdd);
    bc = _mm_shuffle_ps(aHi, bHi, 0x88);
    bd = _mm_shuffle_ps(aHi, bHi, 0xdd);
    result.getQuad() = _mm_add_ps(_mm_add_ps(ac, ad), bc);
}
}

struct Feature
{
    unsigned char dimensionA, dimensionB;
    unsigned short id;
    unsigned char vertices[4];
};
struct Manifold
{
    unsigned char verticesA, verticesB, count, reserved;
    Feature features[4];
};
struct CdVertex : ManifoldVector4
{
};
struct WorkData
{
    CdVertex points[16];
    ManifoldVector4 axis;
    Field<float> radiusA, radiusB, tolerance, maxDistanceSq;
    const ManifoldVector4& getA(unsigned int offset) const
    {
        return *reinterpret_cast<const CdVertex*>(reinterpret_cast<const char*>(points) + offset);
    }
    const ManifoldVector4& getB(unsigned int offset) const
    {
        return *reinterpret_cast<const CdVertex*>(reinterpret_cast<const char*>(points) + offset);
    }
};
struct Converted
{
    ManifoldVector4 position, difference, normal;
};
struct ProcessPoint
{
    ManifoldVector4 position, normal;
    Field<unsigned int> id;
    unsigned int extra0, extra1, extra2;
};
struct ProcessOutput
{
    Field<ProcessPoint*> next;
    Field<void*> owner;
    ProcessPoint* reserve(int)
    {
        return next;
    }
    void commit(int n)
    {
        next = next.val() + n;
    }
    void abort(int)
    {}
};
struct Manager
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void remove(unsigned short, void*);
};

__forceinline int pointPair(const WorkData& data, const Feature& feature, Converted& out)
{
    const ManifoldVector4& a = data.getA(feature.vertices[0]);
    const ManifoldVector4& b = data.getB(feature.vertices[1]);
    ManifoldVector4 difference;
    difference.setSub4(a, b);
    float square = difference.lengthSquared3();
    if (square > data.maxDistanceSq)
        return 1;
    out.difference = difference;
    out.normal = data.axis;
    out.position = a;
    return 0;
}
__forceinline int pointSegment(const WorkData& data, const Feature& feature, Converted& out)
{
    const ManifoldVector4& a = data.getA(feature.vertices[0]);
    const ManifoldVector4& b = data.getB(feature.vertices[1]);
    const ManifoldVector4& c = data.getB(feature.vertices[2]);
    out.position = a;
    out.normal = data.axis;
    ManifoldVector4 edge;
    edge.setSub4(c, b);
    ManifoldVector4 fromC;
    fromC.setSub4(c, a);
    ManifoldVector4 fromB;
    fromB.setSub4(a, b);
    ManifoldVector4 cross;
    cross.setCross(edge, fromC);
    ManifoldVector4 products;
    Parallel::dot3_3vs3(fromC, edge, fromB, edge, cross, cross, products);
    float square = edge.lengthSquared3();
    int outside = products.compareLessThanZero4().anyIsSet(Mask::MASK_XY);
    if (products(3) > data.maxDistanceSq * square || outside)
        return 1;
    Scalar fraction = products.getSimdAt(0) / (products.getSimdAt(0) + products.getSimdAt(1));
    ManifoldVector4 onSegment;
    onSegment.setInterpolate4(b, c, fraction);
    out.difference.setSub4(a, onSegment);
    return 0;
}
__forceinline ManifoldVector4 copyVector(const ManifoldVector4& input)
{
    ManifoldVector4 result;
    result = input;
    return result;
}
__forceinline int segmentPoint(const WorkData& data, const Feature& feature, Converted& out)
{
    const ManifoldVector4& a = data.getA(feature.vertices[0]);
    const ManifoldVector4& b = data.getB(feature.vertices[1]);
    const ManifoldVector4& c = data.getB(feature.vertices[2]);
    out.normal = data.axis;
    const ManifoldVector4& aValue = copyVector(a);
    ManifoldVector4 edge;
    edge.setSub4(b, aValue);
    ManifoldVector4 fromB;
    fromB.setSub4(b, c);
    ManifoldVector4 fromA;
    fromA.setSub4(c, a);
    ManifoldVector4 cross;
    cross.setCross(edge, fromB);
    ManifoldVector4 products;
    Parallel::dot3_3vs3(fromB, edge, fromA, edge, cross, cross, products);
    float square = edge.lengthSquared3();
    int outside = products.compareLessThanZero4().anyIsSet(Mask::MASK_XY);
    if (products(3) > data.maxDistanceSq * square || outside)
        return 1;
    Scalar fraction = products.getSimdAt(0) / (products.getSimdAt(0) + products.getSimdAt(1));
    out.position.setInterpolate4(b, a, fraction);
    out.difference.setSub4(out.position, c);
    return 0;
}
__forceinline int pointTriangle(const WorkData& data, const Feature& feature, Converted& out)
{
    const ManifoldVector4& a = data.getA(feature.vertices[0]);
    const ManifoldVector4& b = data.getB(feature.vertices[1]);
    const ManifoldVector4& c = data.getB(feature.vertices[2]);
    const ManifoldVector4& d = data.getB(feature.vertices[3]);
    out.position = a;
    out.difference.setSub4(a, b);
    ManifoldVector4 edge0;
    edge0.setSub4(d, c);
    ManifoldVector4 edge1;
    edge1.setSub4(b, d);
    ManifoldVector4 edge2;
    edge2.setSub4(c, b);
    ManifoldVector4 normal;
    normal.setCross(edge0, edge1);
    normal.normalize3();
    ManifoldVector4 products;
    {
        ManifoldVector4 toC;
        toC.setSub4(a, c);
        ManifoldVector4 toD;
        toD.setSub4(a, d);
        ManifoldVector4 toB;
        toB.setSub4(a, b);
        ManifoldVector4 side0;
        side0.setCross(toC, edge0);
        ManifoldVector4 side1;
        side1.setCross(toD, edge1);
        ManifoldVector4 side2;
        side2.setCross(toB, edge2);
        Parallel::dot3_1vs4(normal, side0, side1, side2, data.axis, products);
    }
    out.normal = normal;
    int mask = products.compareLessThanZero4().GetLaneMask();
    if (mask & 8)
        out.normal.setNeg4(normal);
    return (~mask) & 7;
}
__forceinline int trianglePoint(const WorkData& data, const Feature& feature, Converted& out)
{
    const ManifoldVector4& a = data.getA(feature.vertices[0]);
    const ManifoldVector4& b = data.getB(feature.vertices[1]);
    const ManifoldVector4& c = data.getB(feature.vertices[2]);
    const ManifoldVector4& d = data.getB(feature.vertices[3]);
    out.position = d;
    out.difference.setSub4(a, d);
    ManifoldVector4 edge0;
    edge0.setSub4(c, b);
    ManifoldVector4 edge1;
    edge1.setSub4(a, c);
    ManifoldVector4 edge2;
    edge2.setSub4(b, a);
    ManifoldVector4 normal;
    normal.setCross(edge0, edge1);
    normal.normalize3();
    ManifoldVector4 products;
    {
        ManifoldVector4 toB;
        toB.setSub4(d, b);
        ManifoldVector4 toC;
        toC.setSub4(d, c);
        ManifoldVector4 toA;
        toA.setSub4(d, a);
        ManifoldVector4 side0;
        side0.setCross(toB, edge0);
        ManifoldVector4 side1;
        side1.setCross(toC, edge1);
        ManifoldVector4 side2;
        side2.setCross(toA, edge2);
        Parallel::dot3_1vs4(normal, side0, side1, side2, data.axis, products);
    }
    Scalar projection = out.difference.dot3(normal);
    out.position.setAddMul4(d, normal, projection);
    out.normal = normal;
    int mask = products.compareLessThanZero4().GetLaneMask();
    if (mask & 8)
        out.normal.setNeg4(normal);
    return (~mask) & 7;
}
__forceinline int segmentPair(const WorkData& data, const Feature& feature, Converted& out)
{
    const ManifoldVector4& a = data.getA(feature.vertices[0]);
    const ManifoldVector4& b = data.getA(feature.vertices[1]);
    const ManifoldVector4& c = data.getB(feature.vertices[2]);
    const ManifoldVector4& d = data.getB(feature.vertices[3]);
    ManifoldVector4 edgeA;
    edgeA.setSub4(b, a);
    ManifoldVector4 edgeB;
    edgeB.setSub4(d, c);
    ManifoldVector4 difference0;
    difference0.setSub4(a, c);
    ManifoldVector4 difference1;
    difference1.setSub4(b, d);
    ManifoldVector4 normal;
    normal.setCross(edgeA, edgeB);
    ManifoldVector4 ortA;
    ortA.setCross(edgeA, normal);
    ManifoldVector4 ortB;
    ortB.setCross(edgeB, normal);
    out.normal = data.axis;
    ManifoldVector4 products;
    Parallel::dot3_2vs2(difference0, difference1, ortB, ortA, products);
    int mask = products.compareLessThanZero4().GetLaneMask();
    if (mask != 3 && mask != 12)
        return 1;
    Scalar first = products.getSimdAt(0);
    Scalar t = first / (first - products.getSimdAt(2));
    out.position.setInterpolate4(a, b, t);
    Scalar second = products.getSimdAt(1);
    Scalar u = second / (second - products.getSimdAt(3));
    ManifoldVector4 onB;
    onB.setInterpolate4(c, d, u);
    out.difference.setSub4(out.position, onB);
    return 0;
}
__forceinline int convert(const WorkData& data, const Feature& feature, Converted& out)
{
    switch (feature.dimensionA * 4 + feature.dimensionB)
    {
    case 0:
        return 1;
    case 5:
        return pointPair(data, feature, out);
    case 6:
        return pointSegment(data, feature, out);
    case 7:
        return pointTriangle(data, feature, out);
    case 9:
        return segmentPoint(data, feature, out);
    case 10:
        return segmentPair(data, feature, out);
    case 13:
        return trianglePoint(data, feature, out);
    default:
        return 1;
    }
}
__forceinline void downshift(Manifold& manifold, int oldCount, int newCount)
{
    unsigned int* dst = reinterpret_cast<unsigned int*>(&manifold.features[newCount]);
    unsigned int* src = reinterpret_cast<unsigned int*>(&manifold.features[oldCount]);
    for (int n = (manifold.verticesA + manifold.verticesB - 1) >> 1; n >= 0; --n)
        *dst++ = *src++;
}
// src: COMMUNITY 0x00dae220
static __declspec(noinline) void hkGskManifold_garbageCollect(Manifold* manifold)
{
    unsigned char used[16] = {0};
    unsigned int pointCount = manifold->count;
    for (unsigned int p = 0; p < pointCount; ++p)
    {
        const Feature& f = manifold->features[p];
        int dimensions = f.dimensionA + f.dimensionB;
        used[f.vertices[0] >> 4] = 1;
        used[f.vertices[1] >> 4] = 1;
        if (dimensions >= 3)
            used[f.vertices[2] >> 4] = 1;
        if (dimensions == 4)
            used[f.vertices[3] >> 4] = 1;
    }
    unsigned short* ids = reinterpret_cast<unsigned short*>(&manifold->features[pointCount]);
    int total = manifold->verticesA + manifold->verticesB;
    int map[16];
    int outCount = 0;
    int offset = 0;
    for (int i = 0; i < total; ++i)
    {
        map[i] = offset;
        if (used[i])
        {
            ids[outCount++] = ids[i];
            offset += 16;
        }
    }
    int newA = map[manifold->verticesA] >> 4;
    manifold->verticesA = static_cast<unsigned char>(newA);
    manifold->verticesB = static_cast<unsigned char>(outCount - newA);
    for (unsigned int p = 0; p < manifold->count; ++p)
    {
        Feature& f = manifold->features[p];
        f.vertices[0] = static_cast<unsigned char>(map[f.vertices[0] >> 4]);
        f.vertices[1] = static_cast<unsigned char>(map[f.vertices[1] >> 4]);
        f.vertices[2] = static_cast<unsigned char>(map[f.vertices[2] >> 4]);
        f.vertices[3] = static_cast<unsigned char>(map[f.vertices[3] >> 4]);
    }
}

// @fnv 0x00dae3a0
// src: COMMUNITY 0x00dae3a0
void __cdecl hkGskManifold_verifyAndGetPoints(Manifold& manifold, const WorkData& data, int start, ProcessOutput& output, Manager* mgr)
{
    unsigned int oldCount = manifold.count;
    unsigned int count = oldCount;
    for (unsigned int index = start; index < count; ++index)
    {
        ProcessPoint* point = output.reserve(1);
        Feature& feature = manifold.features[index];
        Converted converted;
        converted.position.setZero4();
        converted.difference.setZero4();
        converted.normal.setZero4();
        int result = convert(data, feature, converted);
        if (result == 0)
        {
            const ManifoldVector4& normal = converted.normal;
            float distance = normal.dot3(converted.difference);
            float radiusSum = data.radiusA + data.radiusB;
            Scalar shift = data.radiusB - distance;
            distance -= radiusSum;
            if (distance < data.tolerance)
            {
                point->position.setAddMul4(converted.position, normal, shift);
                point->normal = normal;
                point->normal(3) = distance;
                point->id = feature.id;
                output.commit(1);
                continue;
            }
        }
        output.abort(1);
        if (feature.id != 0xffff)
            mgr->remove(feature.id, output.owner.val());
        --count;
        feature = manifold.features[count];
        --index;
    }
    if (oldCount > count)
    {
        manifold.count = static_cast<unsigned char>(count);
        downshift(manifold, oldCount, count);
        hkGskManifold_garbageCollect(&manifold);
    }
}
