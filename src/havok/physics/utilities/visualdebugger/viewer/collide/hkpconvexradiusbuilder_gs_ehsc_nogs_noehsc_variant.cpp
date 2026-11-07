// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
struct D31Arr
{
    void* data;                     // +0x00
    int count;                      // +0x04
    unsigned int capacityAndFlags;  // +0x08
};

struct D31Pair
{
    void* base;  // +0x00
    int count;   // +0x04
};

struct D31Item
{
    float x, y, z, w;
};

struct D31VtIface
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(void* buf, int size);  // vtable +0x10
};

struct D31Tbl2
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    D31VtIface* sub;  // +0x10
};

struct D31Mgr
{
    D31Pair* FUN_00d58d50();         // __thiscall
    void FUN_00d59200(D31Arr* out);  // __thiscall, 1 stack arg
};

struct D31Tbl
{
    void* t;
};

__declspec(align(16)) D31Tbl tbl_0101b330;

D31Tbl2* __cdecl hkMemoryRouter_getInstance();

extern float DAT_0101b31c;

// @fnv 0x00de3110
// src: XBOX_PDB 0x00de3110
static __declspec(noinline) float _getPlaneToSurfaceDistance(int dummy, D31Mgr* mgr)
{
    D31Pair* pair = mgr->FUN_00d58d50();
    D31Arr out;
    out.data = 0;
    out.count = 0;
    out.capacityAndFlags = 0x80000000;
    mgr->FUN_00d59200(&out);
    int pc = pair->count;

    float best = DAT_0101b31c;
    if (out.count > 0)
    {
        D31Item* o = (D31Item*)out.data;
        int oc = out.count;
        do
        {
            if (pc > 0)
            {
                __m128 ov = _mm_load_ps((const float*)o);
                D31Item* p = (D31Item*)pair->base;
                int n = pc;
                do
                {
                    __m128 m = _mm_mul_ps(_mm_load_ps((const float*)p), ov);
                    __m128 t = _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m);
                    t = _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), t);
                    float s;
                    _mm_store_ss(&s, t);
                    float dot = p->w + s;
                    if (dot > best)
                    {
                        best = dot;
                    }
                    p++;
                    n--;
                } while (n != 0);
            }
            o++;
            oc--;
        } while (oc != 0);
    }

    D31Tbl2* t2 = hkMemoryRouter_getInstance();
    D31VtIface* vt = t2->sub;
    unsigned int cap = out.capacityAndFlags;
    out.count = 0;
    if (!(cap & 0x80000000u))
    {
        vt->v4(out.data, (int)(cap & 0x3fffffff) * 16);
    }
    return best;
}

float __cdecl S00de3110_Entry()
{
    return _getPlaneToSurfaceDistance(0, (D31Mgr*)tbl_0101b330.t);
}
