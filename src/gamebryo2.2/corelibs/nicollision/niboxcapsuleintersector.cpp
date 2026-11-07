// src/gamebryo2.2/corelibs/nicollision/niboxcapsuleintersector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nicollision/niboxcapsuleintersector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiPoint3.h"
// The former Vector3 stand-in defined this constructor inline in its class.
inline NiPoint3::NiPoint3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
{
}

inline NiPoint3 NiPoint3::operator*(float s) const
{
    return NiPoint3(x * s, y * s, z * s);
}


struct Struct60
{
    NiPoint3 pos;
    int unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38;
};

struct Struct24
{
    NiPoint3 min;
    int unk0C, unk10, unk14;
};

struct Struct38
{
    int unk00;
    Struct60 data;
};

struct Struct3C
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    Struct24 bounds;
};

float NiSqrDistance_Compute_00eb50f0(Struct24* b, Struct60* t, float* res, int* u1, int* u2, int* u3);

struct TestClass
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34;
    Struct38* unk38;
    Struct3C* unk3c;
    float unk40;
    int unk44;
    int unk48;
    int unk4c;

    float NiBoxCapsuleIntersector_Pseudodistance(const NiPoint3& a1, const NiPoint3& a2, float a3);
};

// Scales both points by a3, offsets copies of unk38->data and unk3c->bounds, calls sub_eb50f0 and returns its result times unk40 minus 1.0.
// @fnv 0x00eb38f0
// src: GAMEBRYO_LIB 0x00eb38f0
float TestClass::NiBoxCapsuleIntersector_Pseudodistance(const NiPoint3& a1, const NiPoint3& a2, float afScale)
{
    NiPoint3 vOffset = a1 * afScale;

    Struct60 dataCopy = unk38->data;
    dataCopy.pos += vOffset;

    Struct24 boundsCopy = unk3c->bounds;

    vOffset = a2 * afScale;
    boundsCopy.min += vOffset;

    float res;
    return NiSqrDistance_Compute_00eb50f0(&boundsCopy, &dataCopy, &res, &unk44, &unk48, &unk4c) * unk40 - 1.0;
}

struct Inner
{
    float pad0;
    NiPoint3 a, b, c, d;
    float lx, ly, lz;
    NiPoint3* Compute(const NiPoint3* p, int sx, int sy, int sz, NiPoint3 diff);
};

struct FUN_00eb3a00_cls
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    float s0;
    NiPoint3 pos;
    NiPoint3 out;
    Inner* volatile in;
    int unk3c, unk40;
    float k0, k1, k2;

    void NiBoxCapsuleIntersector_ComputeContactInformation(const NiPoint3* a, const NiPoint3* b);
};

inline void Accumulate(NiPoint3& result, const NiPoint3& v)
{
    float x = v.x;
    result.x += x;
    result.y += v.y;
    float z = result.z;
    result.z = z + v.z;
}

inline void Scale(NiPoint3& result, const NiPoint3& v, float s)
{
    result.x = s * v.x;
    result.y = s * v.y;
    result.z = s * v.z;
}

// Sets pos from *a scaled by s0 plus in->a, b, c, and d weighted by k0, k1, and k2, then stores in->Compute's result in out.
// @fnv 0x00eb3a00
// src: GAMEBRYO_LIB 0x00eb3a00
void FUN_00eb3a00_cls::NiBoxCapsuleIntersector_ComputeContactInformation(const NiPoint3* a, const NiPoint3* b)
{
    NiPoint3 t;
    Scale(t, *a, s0);
    const NiPoint3* base = &in->a;
    NiPoint3 r;
    r.x = base->x + t.x;
    r.y = base->y + t.y;
    r.z = base->z + t.z;
    NiPoint3& vPosition = pos;
    vPosition = r;

    float s = k0;
    const NiPoint3* axis = &in->b;
    Scale(t, *axis, s);
    Inner* p;
    Accumulate(pos, t);
    p = in;
    int x = (k0 == -p->lx) ? -1 : ((k0 == p->lx) ? 1 : 0);

    base = &p->c;
    Scale(t, *base, k1);
    Accumulate(pos, t);
    p = in;
    int y = (k1 == -p->ly) ? -1 : ((k1 == p->ly) ? 1 : 0);

    base = &p->d;
    Scale(t, *base, k2);
    Accumulate(pos, t);
    p = in;
    int z = (k2 == -p->lz) ? -1 : ((k2 == p->lz) ? 1 : 0);

    r.x = b->x - a->x;
    r.y = b->y - a->y;
    r.z = b->z - a->z;
    out = *in->Compute(&r, x, y, z, r);
}
