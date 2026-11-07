

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

// @fnv 0x00dfaf80
void Obj::SetEntries(const hkVector4* aVecA, const hkVector4* aVecB, const hkVector4* aVecC)
{
    m_num = 4;
    for (int iIndex = 0; iIndex < 4; iIndex++)
    {
        m_usTrailingValue[iIndex].m_kPointA = aVecA[iIndex];
        m_usTrailingValue[iIndex].m_kPointB = aVecB[iIndex];
        m_usTrailingValue[iIndex].m_iThirdValue = aVecC[iIndex];
        m_usTrailingValue[iIndex].m_flag = 0;
    }
    ProcessEntries_00e2d440();
    m_iThirdValue = 0;
}

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

// Stores the three __m128 values from src into the arrays at unk68, unk60 and unk64 at index unk6C, then increments unk6C.
// @fnv 0x00df9c40
void FUN_00df9c40_Obj::PushVectorTriple(const __m128* src)
{
    int idx = this->unk6C;
    this->unk68[idx] = src[0];
    this->unk60[idx] = src[1];
    this->unk64[idx] = src[2];
    this->unk6C = idx + 1;
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
// Computes barycentric coordinates of a point relative to a triangle defined by three vertices and stores the result in a float array.
// @fnv 0x00cd7530
// src: GUESS 0x00cd7530 (confidence: medium)
void Hkpconvexpenetrationutil_ComputeTriangleBarycentricCoordinates(P pos, P t0, Mid t1, __int64 packedTail)
{
    union
    {
        __int64 pair;
        struct
        {
            const S00cd7530_Vec* t2;
            float* result;
        } v;
    } tail;
    tail.pair = packedTail;
    S00cd7530_Vec Q;
    Q.setSub4((*t0.p), *t1.p);
    S00cd7530_Vec R;
    R.setSub4((*tail.v.t2), *t1.p);
    float QQ, RR, QR;
    scalarDots(Q, R, QQ, RR, QR);

    const float QQRR = QQ * RR;
    const float QRQR = QR * QR;
    const float Det = QQRR - QRQR;
    if (Det > 0.0f)
    {
        const float invDet = 1.0f / Det;
        S00cd7530_Vec relPos;
        relPos.setSub4(*t1.p, (*pos.p));
        const float sq = relPos.dot3(Q);
        const float sr = relPos.dot3(R);
        const float q = sr * QR - RR * sq;
        const float r = sq * QR - QQ * sr;
        tail.v.result[0] = invDet * q;
        tail.v.result[1] = invDet * (Det - q - r);
        tail.v.result[2] = invDet * r;
    }
    else
    {
        S00cd7530_Vec S;
        S.setSub4((*t0.p), (*tail.v.t2));
        const float SS = S.dot3(S);
        if (QQ >= RR)
        {
            if (SS >= QQ)
            {
                tail.v.result[1] = 0.0f;
                if (SS > 0.0f)
                {
                    S00cd7530_Vec relPos;
                    relPos.setSub4((*pos.p), (*tail.v.t2));
                    const float t = relPos.dot3(S) / SS;
                    tail.v.result[0] = t;
                    tail.v.result[2] = 1.0f - t;
                }
                else
                {
                    tail.v.result[0] = 0.0f;
                    tail.v.result[2] = 0.0f;
                }
            }
            else
            {
                S00cd7530_Vec relPos;
                relPos.setSub4((*pos.p), *t1.p);
                const float t = relPos.dot3(Q) / QQ;
                tail.v.result[0] = t;
                tail.v.result[1] = 1.0f - t;
                tail.v.result[2] = 0.0f;
            }
        }
        else
        {
            if (SS >= RR)
            {
                S00cd7530_Vec relPos;
                relPos.setSub4((*pos.p), (*tail.v.t2));
                const float t = relPos.dot3(S) / SS;
                tail.v.result[0] = t;
                tail.v.result[1] = 0.0f;
                tail.v.result[2] = 1.0f - t;
            }
            else
            {
                S00cd7530_Vec relPos;
                relPos.setSub4((*pos.p), *t1.p);
                const S00cd7530_SimdReal dot = relPos.dot3(R);
                tail.v.result[0] = 0.0f;
                const float t = float(dot) / RR;
                tail.v.result[2] = t;
                tail.v.result[1] = 1.0f - t;
            }
        }
    }
}

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

// Loops building simplex entries until FUN_00df9fe0/FUN_00df9c90 give a result; on result 3 retries up to 0x14 times, adding an offset to m_30; returns status.
// @fnv 0x00dfa940
// src: GUESS 0x00dfa940 (confidence: medium)
int S00dfa940_Solver::BuildSimplexWithRetries(int a1)
{
    S00dfa940_Simplex simplex;
    hkVector4 tmp;
    int res;
    int vi;
    int ret;
    S00dfa940_Entry* e;

    for (;;)
    {
        res = 0;
        if (ProcessAndReturnValue_00df9fe0(a1, &res) == 1)
        {
            ret = res;
            if (ret != 3)
                goto out;
        }
        else
        {
            simplex.SetEntries(m_60, m_64, m_68);
            vi = simplex.GetNearestEntry();
            e = &simplex.m_usTrailingValue[simplex.m_num++];
            e->m_flag = 0;
            UpdateState_00df9b50(vi, e);
            if (ComputeValues_00df9c90(&simplex, vi, e, &res) != 1)
            {
                for (;;)
                {
                    int n = simplex.m_num;
                    if (n >= 0x37)
                    {
                        ret = 2;
                        goto done;
                    }
                    vi = simplex.GetNearestEntry();
                    simplex.m_num++;
                    e = &simplex.m_usTrailingValue[n];
                    e->m_flag = 0;
                    UpdateState_00df9b50(vi, e);
                    if (ComputeValues_00df9c90(&simplex, vi, e, &res) == 1)
                        break;
                }
            }
            ret = res;
            if (ret != 3)
                goto done;
        }
        if (++m_5c == 1)
        {
            m_6c = 1;
            continue;
        }
        if (m_5c >= 0x14)
            goto out;
        m_6c = 0;
        float f = (float)((rand01() - DAT_01032980) * DAT_010dbb40);
        tmp.x = f;
        tmp.y = f;
        tmp.z = f;
        *(__m128*)&tmp = _mm_add_ps(*(__m128*)&m_30, *(__m128*)&tmp);
        m_30 = tmp;
    }
done:
    ProcessEntries_00df9d90(&simplex, vi, a1);
out:
    return ret;
}

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

// Constructs a Penetration object and calls FUN_00dfa940; if it returns 3, calls FUN_00e2db70 and returns 1, otherwise returns the original result.
// @fnv 0x00dfaac0
int __cdecl TestPenetration(int a, int b, const hkTransform& t, float f, int c, int d, int e, int g, int out)
{
    S_00dfaac0_MonitorStream::GetMonitorStream().timer("TtPenetration");
    S_00dfaac0_Penetration penetration(a, b, t, f, c, d, e, g);
    int result = penetration.BuildSimplexWithRetries(out);
    if (result == 3)
    {
        Geometry_RefineClosestPointsByDirectionSampling(a, b, t, c, d, out);
        result = 1;
    }
    S_00dfaac0_MonitorStream::GetMonitorStream().timer("Et");
    return result;
}

extern "C"
{
    void** hkMemoryRouter_getInstance();
    void Object_ProcessEntries_00e2d6c0(void*, void*, void*, void*, void*);
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

inline void hkTransform::operator=(const hkTransform& o)
{
    m_kColumn0 = o.m_kColumn0;
    m_kColumn1 = o.m_kColumn1;
    m_kColumn2 = o.m_kColumn2;
    m_vTranslation = o.m_vTranslation;
}

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

// @fnv 0x00dfaba0
// src: GUESS 0x00dfaba0 (confidence: low)
int hkTransform_ProcessEntries_00dfaba0(const hkTransform* transform, Arg1* arg1, Arg2** arg2, int count, const hkTransform* arg4,
                 OutItem** arg5)
{
    WorkArray storage;
    void** tls = hkMemoryRouter_getInstance();
    storage.data = (Item*)*tls;
    *tls = (char*)(Item*)storage.data + ((count * sizeof(Item) + 127) & ~127);
    Item* buffer = storage.begin();

    LocalStruct70 local_s;
    hkVector4 out_vec;

    {
        int arr[2];
        int workId = 0;
        for (int i = 0; i < count; ++i)
        {
            Item* item = &storage[workId];
            item->m_arg2_copy = arg2[i];
            item->m_arg5 = arg5[i];
            item->init(arg1, arg2[i], *arg4, 0.0001f, item->m_vec70, item->m_vecB0, item->m_vecF0, 0);

            if (item->ProcessAndReturnValue_00df9fe0(&local_s, arr) == 1)
            {
                count--;
            }
            else
            {
                Item* p = item;
                ++workId;
                p->m_obj.SetEntries(p->m_vec70, p->m_vecB0, p->m_vecF0);
            }
        }

        if (count > 2)
        {
            count = 2;
        }
        else if (count < 2)
        {
            *hkMemoryRouter_getInstance() = buffer;
            return 1;
        }

        arr[0] = 0;
        arr[1] = 0;

        bool flag;
        do
        {
            Object_ProcessEntries_00e2d6c0(&buffer[0].m_obj, &buffer[1].m_obj, &out_vec, &buffer[0].m_field2ff0, &buffer[1].m_field2ff0);
            flag = false;
            Item* pItem = buffer;
            for (int i = 0; i < count; ++i, ++pItem)
            {
                if (arr[i] == 2 || pItem->m_obj.m_num < 55)
                {
                    continue;
                }
                Entry* entry = pItem->m_obj.allocEntry();
                pItem->UpdateState_00df9b50(pItem->m_field2ff0, entry);
                if (pItem->ComputeValues_00df9c90(pItem->m_obj, pItem->m_field2ff0, entry, &arr[i]) == 1)
                {
                    if (arr[i] == 3)
                    {
                        *hkMemoryRouter_getInstance() = buffer;
                        return 1;
                    }
                }
                else
                {
                    flag = true;
                }
            }
        } while (flag);
    }

    float neg_w = -out_vec.w;
    hkVector4 neg_vec_v;
    neg_vec_v = out_vec;
    __m128 neg_vec = _mm_xor_ps(*(__m128*)&neg_vec_v, DAT_010c44d0);
    float f10 = arg1->float10;

    Item* pItem = buffer;
    for (int i = 0; i < count; ++i, ++pItem)
    {
        pItem->ProcessEntries_00df9d90(&pItem->m_obj, pItem->m_field2ff0, &local_s);

        __m128 normal_y;
        __m128 normal_x, normal_z;
        normal_y = _mm_shuffle_ps(neg_vec, neg_vec, 0x55);
        normal_z = _mm_shuffle_ps(neg_vec, neg_vec, 0xAA);
        normal_x = _mm_shuffle_ps(neg_vec, neg_vec, 0x00);
        *(__m128*)&pItem->m_arg5->direction =
            _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_load_ps((const float*)&normal_y), *(__m128*)&transform->m_kColumn1),
                                  _mm_mul_ps(normal_x, *(__m128*)&transform->m_kColumn0)),
                       _mm_mul_ps(_mm_load_ps((const float*)&normal_z), *(__m128*)&transform->m_kColumn2));

        __m128 pt_y = _mm_mul_ps(_mm_shuffle_ps(*(__m128*)&local_s.m_v1, *(__m128*)&local_s.m_v1, 0x55),
                                 *(__m128*)&transform->m_kColumn1);
        __m128 pt_x = _mm_mul_ps(_mm_shuffle_ps(*(__m128*)&local_s.m_v1, *(__m128*)&local_s.m_v1, 0x00),
                                 *(__m128*)&transform->m_kColumn0);
        __m128 pt_z = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*(__m128*)&local_s.m_v1, *(__m128*)&local_s.m_v1, 0xAA),
                                            *(__m128*)&transform->m_kColumn2),
                                 *(__m128*)&transform->m_vTranslation);
        float w = neg_w - f10 - pItem->m_arg2_copy->getRadius();
        *(__m128*)&pItem->m_arg5->point = _mm_add_ps(_mm_add_ps(pt_y, pt_x), pt_z);
        pItem->m_arg5->direction.w = w;
    }

    *hkMemoryRouter_getInstance() = buffer;
    return 0;
}
