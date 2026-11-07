#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form

// src/staging/blk_00dc0000_od_o2_gs_nood_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/staging/blk_00dc0000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00dc0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkBool.h"
#include "../../include/hkSimdReal.h"
#include "../../include/hkVector4.h"
#include "../../include/hkContactPoint.h"

#include <xmmintrin.h>
#include <math.h>
#include <string.h>
inline void* __cdecl operator new(unsigned int, void* location) throw()
{
    return location;
}


inline hkVector4::hkVector4(const hkVector4& vector) : m_vComponents(vector.m_vComponents)
{}

inline hkSimdReal::hkSimdReal(const __m128& x) : m_vValue(x)
{}

inline hkSimdReal::operator float() const
{
    float s;
    _mm_store_ss(&s, m_vValue);
    return s;
}

extern void __cdecl ResizeAudioStream(void* heap, void* array, int elemSize) throw();

#include "../../include/hkArray.h"
// hkArray<T>::pushBack as this unit's original inlines it: the router's heap pointer is read only on the grow path.
template <class T> static __forceinline void AddBack(hkArray<T>* a, const T& t)
{
    hkMemoryRouter* router = (&hkMemoryRouter::getInstance());
    if (a->m_iElementCount == (a->m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(router->m_heap, a, sizeof(T));
    T* destination = a->m_data + a->m_iElementCount;
    if (destination)
    {
        ::new (destination) T;
        memcpy(destination, &t, sizeof(T));
    }
    a->m_iElementCount++;
}

extern int __cdecl Object_ProcessAndReturnValue_00dd6380(hkArray<hkVector4>* planes, int skip1, int skip2, int plane, hkContactPoint* contact);

extern float DAT_0104da48;
extern float DAT_0109afc4;
extern double DAT_01032980;
extern __m128 DAT_010c7160;

// @fnv 0x00dd66d0
// src: GUESS 0x00dd66d0 (confidence: low)
hkBool __cdecl hkBool_ProcessEntries_00dd66d0(const hkVector4* direction, hkArray<hkVector4>* planes, int skip1, int skip2,
                            hkVector4* position, hkArray<hkContactPoint>* contacts)
{
    float best = DAT_0104da48;
    bool found = false;
    for (int i = 0; i < planes->m_iElementCount; i++)
    {
        if (i == skip1 || i == skip2)
            continue;
        __m128 products = _mm_mul_ps(planes->m_data[i].m_vComponents, direction->m_vComponents);
        __m128 denomv = _mm_add_ss(_mm_shuffle_ps(products, products, 0xaa),
                                   _mm_add_ss(_mm_shuffle_ps(products, products, 0x55), products));
        float denom = hkSimdReal(denomv);
        if (DAT_0109afc4 < denom)
        {
            position->m_vComponents.m128_f32[3] = 1.0f;
            __m128 dot = _mm_mul_ps(planes->m_data[i].m_vComponents, position->m_vComponents);
            __m128 sum = _mm_add_ps(_mm_shuffle_ps(dot, dot, 0x4e), dot);
            sum = _mm_add_ps(_mm_shuffle_ps(sum, sum, 0xb1), sum);
            float num = hkSimdReal(_mm_sub_ss(DAT_010c7160, sum));
            float absDenom = (float)fabs(denom);
            float dist = num / absDenom;
            if (dist < best + DAT_01032980)
            {
                hkContactPoint contact;
                if (Object_ProcessAndReturnValue_00dd6380(planes, skip1, skip2, i, &contact) == 0)
                {
                    found = true;
                    float diff = dist - best;
                    if ((float)fabs(diff) < DAT_01032980)
                    {
                        AddBack(contacts, contact);
                    }
                    else
                    {
                        contacts->m_iElementCount = 0;
                        AddBack(contacts, contact);
                        best = dist;
                    }
                }
            }
        }
    }
    return found;
}

extern "C" void __cdecl Atan2(float, float);

static inline float Dot3(__m128 a, __m128 b)
{
    __m128 v = _mm_mul_ps(a, b);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(v, v, 0x55), v);
    float f;
    _mm_store_ss(&f, _mm_add_ss(_mm_shuffle_ps(v, v, 0xaa), s));
    return f;
}

// @fnv 0x00ddd5a0
// src: COMMUNITY 0x00ddd5a0
void __cdecl hkpMeshWeldingUtility_calcAngleForEdge(const float* a, const float* b, const float* c)
{
    __m128 scale = _mm_load_ps(c);
    float fB = Dot3(_mm_load_ps(b), scale);
    float fA = Dot3(_mm_load_ps(a), scale);
    Atan2(fB, fA);
}

extern __m128 DAT_010c44d0;

// @fnv 0x00dd2fd0
// src: GUESS 0x00dd2fd0 (confidence: low)
static __declspec(noinline) void hkSimdReal_ComputeValues_00dd2fd0(hkSimdReal* self, __m128* out, __m128* a1, __m128* a2)
{
    __m128 d = _mm_sub_ps(*a1, self->m_vValue);
    __m128 r = _mm_rcp_ps(d);
    __m128 t = _mm_mul_ps(_mm_mul_ps(r, d), r);
    r = _mm_sub_ps(_mm_add_ps(r, r), t);
    *a2 = _mm_mul_ps(*a1, r);
    *out = _mm_mul_ps(self->m_vValue, r);
    *out = _mm_xor_ps(*out, DAT_010c44d0);
}

void S00dd2fd0_wrap(hkSimdReal* self, __m128* out, __m128* a1, __m128* a2)
{
    hkSimdReal_ComputeValues_00dd2fd0(self, out, a1, a2);
}
