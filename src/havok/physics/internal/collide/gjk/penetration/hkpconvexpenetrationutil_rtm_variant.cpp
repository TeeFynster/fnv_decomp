
// src/havok/physics/internal/collide/gjk/penetration/hkpconvexpenetrationutil_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/internal/collide/gjk/penetration/hkpconvexpenetrationutil.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/internal/collide/gjk/penetration/hkpconvexpenetrationutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/penetration/hkpconvexpenetrationutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/hkTransform.h"

#include "../../../../../../../include/hkVector4.h"

struct Entry
{
    hkVector4 m_iThirdValue;
    hkVector4 m_kPointA;
    hkVector4 m_kPointB;
    int m_flag;
};
struct Obj
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_num;
    int m_iThirdValue;
    int m_auiShapeKeys[4];
    Entry m_usTrailingValue[4];
    void ProcessEntries_00e2d440();
    void SetEntries(const hkVector4* a, const hkVector4* b, const hkVector4* c);
};
struct FUN_00df9c40_Obj
{
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
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    __m128* unk60;
    __m128* unk64;
    __m128* unk68;
    int unk6C;

    void PushVectorTriple(const __m128* src);
};
extern "C"
{
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    void _mm_store_ss(float*, __m128);
}
struct S00cd7530_SimdReal
{
    __m128 m_vValue;
    __forceinline operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
};
struct S00cd7530_Vec
{
    __m128 m_vComponents;
    __forceinline void setSub4(const S00cd7530_Vec& a, const S00cd7530_Vec& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline S00cd7530_SimdReal dot3(const S00cd7530_Vec& a) const
    {
        __m128 m = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 y = _mm_shuffle_ps(m, m, 0x55);
        __m128 xy = _mm_add_ss(y, m);
        __m128 z = _mm_shuffle_ps(m, m, 0xaa);
        S00cd7530_SimdReal r;
        r.m_vValue = _mm_add_ss(z, xy);
        return r;
    }
};
struct P
{
    const S00cd7530_Vec* p;
    P()
    {}
};
struct Mid
{
    const S00cd7530_Vec* p;
    Mid()
    {}
};
__forceinline void scalarDots(const S00cd7530_Vec& Q, const S00cd7530_Vec& R, float& QQ, float& RR, float& QR)
{
    QQ = Q.dot3(Q);
    _mm_store_ss(&RR, R.dot3(R).m_vValue);
    QR = R.dot3(Q);
}
void Hkpconvexpenetrationutil_ComputeTriangleBarycentricCoordinates(P pos, P t0, Mid t1, __int64 packedTail);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern const double DAT_01032980;
extern const double DAT_010dbb40;
struct S00dfa940_Entry
{
    hkVector4 m_iThirdValue;
    hkVector4 m_kPointA;
    hkVector4 m_kPointB;
    int m_flag;
};
struct S00dfa940_Simplex
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_num;
    int m_iThirdValue;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    S00dfa940_Entry m_usTrailingValue[0xBA];
    int m_t0;
    int m_t1;
    int m_t2;
    int m_t3;

    void SetEntries(const hkVector4* a, const hkVector4* b, const hkVector4* c);
    int GetNearestEntry();
};
double rand01();
struct S00dfa940_Solver
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
    hkVector4 m_30;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int m_5c;
    const hkVector4* m_60;
    const hkVector4* m_64;
    const hkVector4* m_68;
    int m_6c;

    int BuildSimplexWithRetries(int a1);
    int ProcessAndReturnValue_00df9fe0(int a1, int* out);
    void UpdateState_00df9b50(int idx, S00dfa940_Entry* e);
    int ComputeValues_00df9c90(S00dfa940_Simplex* o, int idx, S00dfa940_Entry* e, int* out);
    void ProcessEntries_00df9d90(S00dfa940_Simplex* o, int idx, int a1);
};
extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
#include <windows.h>
extern DWORD DAT_0126835c;
struct S_00dfaac0_TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    void setTime()
    {
        volatile unsigned int t = (unsigned int)__rdtsc();
        m_uiStartTicks = t;
    }
};
struct S_00dfaac0_MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
    static S_00dfaac0_MonitorStream& GetMonitorStream()
    {
        return *(S_00dfaac0_MonitorStream*)TlsGetValue(DAT_0126835c);
    }
    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
    void timer(const char* name)
    {
        if (memoryAvailable())
        {
            S_00dfaac0_TimerCommand* h = (S_00dfaac0_TimerCommand*)m_kRayEnd;
            h->m_pCommandName = name;
            _ReadWriteBarrier();
            h->setTime();
            m_kRayEnd = (char*)(h + 1);
        }
    }
};
struct __declspec(align(16)) S_00dfaac0_Penetration
{
    int unk00;
    S_00dfaac0_Penetration(int a, int b, const hkTransform& t, float f, int c, int d, int e, int g);
    int BuildSimplexWithRetries(int out);
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
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
};
int __cdecl Geometry_RefineClosestPointsByDirectionSampling(int a, int b, const hkTransform& t, int c, int d, int out);
int __cdecl TestPenetration(int a, int b, const hkTransform& t, float f, int c, int d, int e, int g, int out);
extern "C" void _mm_store_ps(float*, __m128);
extern "C" __m128 _mm_load_ps(const float*);
extern "C"
{
    void** hkMemoryRouter_getInstance();
    void Object_ProcessEntries_00e2d6c0(void*, void*, void*, void*, void*);

    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
    __m128 _mm_set_ps1(float);
}
extern "C" const __m128 DAT_010c44d0;
struct Arg1
{
    int unk00, unk04, unk08, unk0c;
    float float10;
};
struct Arg2
{
    int unk00, unk04, unk08, unk0c;
    float float10;
    float getRadius() const
    {
        return float10;
    }
};
struct OutItem
{
    hkVector4 point;
    hkVector4 direction;
};
struct NormalSplats
{
    __m128 x;
    __m128 z;
};
struct LocalStruct70
{
    hkVector4 m_v0;
    hkVector4 m_v1;
    float m_f;
};
struct WorkObject
{
    int unk00, unk04;
    int m_num;
    int unk0c, unk10, unk14, unk18, unk1c;
    Entry m_usTrailingValue[186];
    hkVector4 unk2ea0;
    void SetEntries(const hkVector4*, const hkVector4*, const hkVector4*);
    Entry* allocEntry()
    {
        Entry* e = &m_usTrailingValue[m_num++];
        e->m_flag = 0;
        return e;
    }
};
struct Item
{
    hkTransform m_matrix;
    __m128 m_vec40;
    float m_float50;
    Arg1* m_arg1;
    Arg2* m_arg2;
    int m_unk5C;
    hkVector4* m_ptr60;
    hkVector4* m_ptr64;
    hkVector4* m_ptr68;
    int m_unk6C;
    hkVector4 m_vec70[4];
    hkVector4 m_vecB0[4];
    hkVector4 m_vecF0[4];
    Arg2* m_arg2_copy;
    OutItem* m_arg5;
    int unk138, unk13c;
    WorkObject m_obj;
    int m_field2ff0;
    int unk2ff4, unk2ff8, unk2ffc;

    void init(Arg1* a1, Arg2* a2, const hkTransform& trans, float eps, hkVector4* v70, hkVector4* vB0, hkVector4* vF0,
              int u6c)
    {
        m_matrix = trans;
        m_vec40 = _mm_set_ps1(eps);
        m_float50 = eps * eps;
        m_arg1 = a1;
        m_arg2 = a2;
        m_ptr60 = v70;
        m_ptr64 = vB0;
        m_unk5C = 0;
        m_ptr68 = vF0;
        m_unk6C = u6c;
    }

    int ProcessAndReturnValue_00df9fe0(LocalStruct70* s, int* arr);
    void UpdateState_00df9b50(int field2ff0, Entry* entry);
    int ComputeValues_00df9c90(const WorkObject& obj, int field2ff0, Entry* entry, int* arr);
    void ProcessEntries_00df9d90(WorkObject* obj, int field2ff0, LocalStruct70* s);
};
struct WorkArray
{
    Item* data;
    Item& operator[](int i)
    {
        return ((Item*)data)[i];
    }
    Item* begin()
    {
        return data;
    }
};
int hkTransform_ProcessEntries_00dfaba0(const hkTransform* transform, Arg1* arg1, Arg2** arg2, int count, const hkTransform* arg4,
                 OutItem** arg5);

extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_xor_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_load_ss(const float* p);

extern float DAT_01267e30;

struct S_00df9d90_Bary
{
    float v[3];
    float get(int i) const
    {
        return v[i];
    }
};
__forceinline __m128 S_00df9d90_Ss(float f)
{
    return _mm_load_ss(&f);
}
__forceinline __m128 S_00df9d90_Mul(__m128 s, const __m128& v)
{
    return _mm_mul_ps(_mm_shuffle_ps(s, s, 0), v);
}

struct S_00df9d90_Src
{
    __m128 unk00;
    __m128* unk10;
    int unk14, unk18, unk1c;
    __m128* unk20;
    int unk24, unk28, unk2c;
    __m128* unk30;
    int unk34, unk38, unk3c;
    float unk40;
};

struct S_00df9d90_Out
{
    __m128 unk00;
    __m128 unk10;
    float unk20;
};

struct S_00df9d90_Owner;
struct S_00df9d90_OwnerP
{
    S_00df9d90_Owner* p;
    S_00df9d90_Owner* val() const
    {
        return p;
    }
};
struct S_00df9d90_OutP
{
    S_00df9d90_Out* p;
    S_00df9d90_Out* val() const
    {
        return p;
    }
};
struct S_00df9d90_Owner
{
    S_00df9d90_Src* WalkAdjacentHullFaces(S_00df9d90_Src* s);
};

void Hkpconvexpenetrationutil_ComputeTriangleBarycentricCoordinates(const void* a, const __m128* b, const __m128* c, const __m128* d, float* out);

struct S_00df9d90_This
{
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c;
    __m128* unk60;
    __m128* unk64;
    __m128* unk68;
    int unk6c;
    S_00df9d90_Out* ProcessEntries_00df9d90(S_00df9d90_OwnerP owner, S_00df9d90_Src* s, S_00df9d90_OutP outp);
};

// @fnv 0x00df9d90
// src: GUESS 0x00df9d90 (confidence: low)
S_00df9d90_Out* S_00df9d90_This::ProcessEntries_00df9d90(S_00df9d90_OwnerP owner, S_00df9d90_Src* s, S_00df9d90_OutP outp)
{
    S_00df9d90_Bary bary;
    for (int i = 0; i < 10; i++)
    {
        unk68[0] = s->unk10[0];
        unk68[1] = s->unk20[0];
        unk68[2] = s->unk30[0];
        Hkpconvexpenetrationutil_ComputeTriangleBarycentricCoordinates(&DAT_01267e30, &unk68[0], &unk68[1], &unk68[2], bary.v);
        if (!(bary.v[0] < 0.0f || bary.v[1] < 0.0f || bary.v[2] < 0.0f))
            break;
        s = owner.val()->WalkAdjacentHullFaces(s);
    }
    __m128* p1 = s->unk10;
    unk60[0] = p1[1];
    unk64[0] = p1[2];
    __m128* p2 = s->unk20;
    unk60[1] = p2[1];
    unk64[1] = p2[2];
    __m128* p3 = s->unk30;
    unk60[2] = p3[1];
    unk64[2] = p3[2];
    unk6c = 3;
    S_00df9d90_Out* o = outp.val();
    __m128 w0 = _mm_load_ss(&bary.v[0]);
    __m128 w1 = S_00df9d90_Ss(bary.get(1));
    __m128 w2 = S_00df9d90_Ss(bary.get(2));
    o->unk10 = _mm_add_ps(_mm_add_ps(S_00df9d90_Mul(w1, unk60[1]), S_00df9d90_Mul(w0, unk60[0])),
                          S_00df9d90_Mul(w2, unk60[2]));
    o->unk20 = -s->unk40;
    o->unk00 = _mm_xor_ps(s->unk00, DAT_010c44d0);
    return o;
}
