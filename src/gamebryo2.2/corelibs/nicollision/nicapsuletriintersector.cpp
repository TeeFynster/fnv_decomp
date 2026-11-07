
// src/gamebryo2.2/corelibs/nicollision/nicapsuletriintersector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nicollision/nicapsuletriintersector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiPoint3.h"
// In-class bodies of the former Point stand-in.
__forceinline NiPoint3::NiPoint3(float px, float py, float pz) : x(px), y(py), z(pz)
{}
inline NiPoint3 NiPoint3::operator-() const
{
    return NiPoint3(-x, -y, -z);
}
__forceinline NiPoint3 NiPoint3::operator*(float scalar) const
{
    return NiPoint3(scalar * x, scalar * y, scalar * z);
}
__forceinline NiPoint3 NiPoint3::operator/(float scalar) const
{
    float inverse = 1.0f / scalar;
    return NiPoint3(x * inverse, y * inverse, z * inverse);
}
inline bool NiPoint3::operator==(const NiPoint3& other) const
{
    return other.x == x && other.y == y && other.z == z;
}

inline NiPoint3 NiPoint3::operator+(const NiPoint3& p) const
{
    return NiPoint3(x + p.x, y + p.y, z + p.z);
}

inline void AccumulateContactPoint(NiPoint3& point, const NiPoint3& displacement)
{
    point.x += displacement.x;
    point.y += displacement.y;
    point.z += displacement.z;
}

// 0x00eb3830 is also bound as CollisionTriangle's normal calculation in nicapsulebv.cpp.
struct CollisionTriangle
{
    NiPoint3 origin, edge0, edge1;
    NiPoint3 NiTrigon_GetNormal() const;
};
struct S_eb5ce0_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int mode;
    float unk1c;
    NiPoint3 p20;
    NiPoint3 p2c;
    int unk38;
    CollisionTriangle triangle;
    int unk60;
    float s64;
    float s68;
    void NiCapsuleTriIntersector_ComputeContactInformation(int unused, const NiPoint3* d);
};
// Computes the contact point and opposing triangle normal, then applies motion at the contact time in mode 2.
// @fnv 0x00eb5ce0
// src: GAMEBRYO_SRC 0x00eb5ce0
void S_eb5ce0_Obj::NiCapsuleTriIntersector_ComputeContactInformation(int unused, const NiPoint3* d)
{
    p20 = (triangle.origin + triangle.edge0 * s64) + triangle.edge1 * s68;
    p2c = -triangle.NiTrigon_GetNormal();
    if (mode == 2)
    {
        AccumulateContactPoint(p20, *d * unk1c);
    }
}

extern double DAT_01012070;
// Two 12-byte points describe the capsule axis; shared Pair holds two integers (8 bytes).
struct CapsuleAxis
{
    NiPoint3 points[2];
};
struct Triple856
{
    NiPoint3 points[3];
};
struct Source856
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    CapsuleAxis pair;
};
struct Frame856
{
    NiPoint3 delta;
    CapsuleAxis pair;
    Triple856 triple;
};
struct Frame2
{
    CapsuleAxis pair;
    Triple856 triple;
};
float __cdecl NiSqrDistance_Compute_00eb1d20(NiPoint3* a, NiPoint3* b, float* time, float* p, float* q);
class Native856
{
  public:
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    Source856* source;
    Triple856 triple;
    float scale, p, q;
    float Evaluate(const NiPoint3* a, const NiPoint3* b, float s);
};
// @fnv 0x00eb3640
float Native856::Evaluate(const NiPoint3* apOffset, const NiPoint3* b, float s)
{
    CapsuleAxis pair = source->pair;
    Triple856 localTriple = triple;
    pair.points[0] += *apOffset * s;
    localTriple.points[0] += *b * s;
    float time;
    return (float)((double)(NiSqrDistance_Compute_00eb1d20(pair.points, localTriple.points, &time, &p, &q) * scale) - DAT_01012070);
}
