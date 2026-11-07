
// src/staging/blk_00b80000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00b80000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00b80000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/NiPlane.h"

struct FNVVec3
{
    float x, y, z;
    FNVVec3()
    {}
    FNVVec3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    FNVVec3 operator+(const FNVVec3& b) const
    {
        return FNVVec3(x + b.x, y + b.y, z + b.z);
    }
    FNVVec3 operator-(FNVVec3 b) const
    {
        return FNVVec3(x - b.x, y - b.y, z - b.z);
    }
    FNVVec3 operator*(float s) const
    {
        return FNVVec3(x * s, y * s, z * s);
    }
    float operator*(const FNVVec3& b) const
    {
        return x * b.x + y * b.y + z * b.z;
    }
};
inline FNVVec3 operator*(float s, const FNVVec3& b)
{
    return FNVVec3(s * b.x, s * b.y, s * b.z);
}
inline int NiPlane::Side(const FNVVec3& p) const
{
    float d = x * p.x + y * p.y + z * p.z - c;
    if (d < 0.0f)
        return 2;
    else if (d > 0.0f)
        return 1;
    return 0;
}
inline float NiPlane::Distance(const FNVVec3& p) const
{
    return x * p.x + y * p.y + z * p.z - c;
}
inline int Classify(const NiPlane& q, const FNVVec3& p)
{
    float d = q.x * p.x + q.y * p.y + q.z * p.z - q.c;
    if (d < 0.0f)
        return 2;
    else if (d > 0.0f)
        return 1;
    return 0;
}

struct FNVPlaneArray
{
    NiPlane faces[6];
    unsigned mask;
    FNVPlaneArray()
    {
        mask = 0x3f;
    }
};
struct FNVCuboid
{
    unsigned int f00;
    unsigned int f04;
    unsigned int f08;
    unsigned int f0c;
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
    unsigned int f1c;
    unsigned int f20;
    unsigned int f24;
    unsigned int f28;
    unsigned int f2c;
    unsigned int f30;
    unsigned int f34;
    unsigned int f38;
    unsigned int f3c;
    unsigned int f40;
    unsigned int f44;
    unsigned int f48;
    unsigned int f4c;
    unsigned int f50;
    unsigned int f54;
    unsigned int f58;
    unsigned int f5c;
    unsigned int f60;
    unsigned int f64;
    float f68;
    float f6c;
    float f70;
    float f74;
    float f78;
    float f7c;
    float f80;
    float f84;
    float f88;
    FNVVec3 position;
    float f98;
    float f9c;
    float fa0;
    float fa4;
    float fa8;
    float fac;
    float fb0;
    float fb4;
    float fb8;
    float fbc;
    float fc0;
    float fc4;
    float fc8;
    float fcc;
    float fd0;
    float fd4;
    float fd8;
    float fdc;
    float fe0;
    float fe4;
    float fe8;
    float fec;
    float ff0;
    FNVVec3 Forward() const
    {
        FNVVec3 v;
        v.x = f68;
        v.y = f74;
        v.z = f80;
        return v;
    }
    FNVVec3 Up() const
    {
        FNVVec3 v;
        v.x = f6c;
        v.y = f78;
        v.z = f84;
        return v;
    }
    FNVVec3 Right() const
    {
        FNVVec3 v;
        v.x = f70;
        v.y = f7c;
        v.z = f88;
        return v;
    }
};
struct FUN_00a693e0
{
    unsigned vptr, flags;
    void* visible;
    FNVCuboid* camera;
    float left, right, top, bottom, nearDist, farDist;
    unsigned ortho;
    FNVPlaneArray poly;
    ~FUN_00a693e0();
};
struct FUN_00a69400 : FUN_00a693e0
{
    FUN_00a69400(void*);
    ~FUN_00a69400()
    {}
    void NiCullingProcess_SetFrustum(void*);
};
// @fnv 0x00b9c020
// src: COMMUNITY 0x00b9c020
unsigned char __stdcall ShadowSceneLight_FrustumFrustumIntersection(FNVCuboid* p1, FNVCuboid* p2)
{
    unsigned char adjacency[8][2] = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 2}, {1, 3}, {2, 4}, {3, 4}};
    FNVPlaneArray first, second;
    FNVVec3 vertsA[5], vertsB[5];
    FNVVec3 forward = p1->Forward();
    FNVVec3 pos = p1->position;
    vertsA[0] = pos;
    FNVVec3 up = p1->fe4 * p1->Up();
    FNVVec3 right = p1->fe0 * p1->Right();
    float farDist = p1->ff0;
    vertsA[1] = pos + farDist * forward + farDist * up + farDist * right;
    vertsA[2] = pos + farDist * forward + farDist * up - farDist * right;
    vertsA[3] = pos + farDist * forward - farDist * up + farDist * right;
    vertsA[4] = pos + farDist * forward - farDist * up - farDist * right;
    pos = p2->position;
    forward = p2->Forward();
    vertsB[0] = pos;
    up = p2->fe4 * p2->Up();
    right = p2->fe0 * p2->Right();
    farDist = p2->ff0;
    vertsB[1] = pos + farDist * forward + farDist * up + farDist * right;
    vertsB[2] = pos + farDist * forward + farDist * up - farDist * right;
    vertsB[3] = pos + farDist * forward - farDist * up + farDist * right;
    vertsB[4] = pos + farDist * forward - farDist * up - farDist * right;
    FUN_00a69400 scratch(0);
    scratch.camera = p1;
    scratch.NiCullingProcess_SetFrustum(&p1->fdc);
    first = scratch.poly;
    scratch.camera = p2;
    scratch.NiCullingProcess_SetFrustum(&p2->fdc);
    second = scratch.poly;
    FNVPlaneArray active;
    FNVVec3* verts = 0;
    for (int phase = 0; phase < 2; phase++)
    {
        switch (phase)
        {
        case 0:
            verts = vertsA;
            active = second;
            break;
        case 1:
            verts = vertsB;
            active = first;
            break;
        }
        for (int i = 0; i < 5; i++)
        {
            int j = 0;
            do
            {
                if (Classify(active.faces[j], verts[i]) != 1)
                    goto next_vertex;
            } while (++j < 6);
            return 1;
        next_vertex:;
        }
    }
    for (int phase = 0; phase < 2; phase++)
    {
        switch (phase)
        {
        case 0:
            verts = vertsA;
            active = second;
            break;
        case 1:
            verts = vertsB;
            active = first;
            break;
        }
        for (int edge = 0; edge < 8; edge++)
        {
            FNVVec3 v1 = verts[adjacency[edge][0]];
            FNVVec3 v2 = verts[adjacency[edge][1]];
            for (int plane = 0; plane < 6; plane++)
            {
                int r1 = active.faces[plane].Side(v1);
                int r2 = active.faces[plane].Side(v2);
                if (r1 != r2)
                {
                    FNVVec3 normal = *reinterpret_cast<const FNVVec3*>(&active.faces[plane].x);
                    FNVVec3 delta = normal * active.faces[plane].c - v1;
                    FNVVec3 direction = v2 - v1;
                    float fraction = (normal * delta) / (normal * direction);
                    FNVVec3 point = v1 + fraction * (v2 - v1);
                    if (fraction >= 0.0f && fraction <= 1.0f)
                    {
                        int k = 0;
                        do
                        {
                            if (k != plane && active.faces[k].Side(point) == 2)
                                goto next_plane;
                        } while (++k < 6);
                        return 1;
                    }
                }
                else if (r1 == 0 && r2 == 0)
                    return 1;
            next_plane:;
            }
        }
    }
    return 0;
}
