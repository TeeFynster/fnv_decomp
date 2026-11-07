
// src/staging/blk_008a0000_o2_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /Od /Oy- /GS /EHsc /Gy (unit src/staging/blk_008a0000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

// src/staging/blk_008a0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include <xmmintrin.h>
struct FUN_008b3d70_Vec3
{
    float x;
    float y;
    float z;
    FUN_008b3d70_Vec3 SubtractIntoVector(const FUN_008b3d70_Vec3& o) const;
    FUN_008b3d70_Vec3 ApplyScaled(float f) const;
};
void NiPoint3_UnitizeVector(FUN_008b3d70_Vec3* v);

struct FUN_008b3d70_Hit
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void* GetObject();
};
struct FUN_008b3d70_World;
FUN_008b3d70_Hit* ArrowProjectile_PickSceneGraph(FUN_008b3d70_World* world, FUN_008b3d70_Vec3 origin, FUN_008b3d70_Vec3 dir, float* dist,
                               int flag);

struct FUN_008b3d70_hkVec
{
    __m128 v;
    void FUN_006815c0();
};
struct FUN_008b3d70_Sphere
{
    __m128 v;
    void BGSPrimitive_EvaluateValue_006240d0();
    void hkSphere_setPosition(const FUN_008b3d70_hkVec& c);
    void hkSphere_setRadius(float r);
};
FUN_008b3d70_hkVec& NI2HK(FUN_008b3d70_hkVec& out, const FUN_008b3d70_Vec3& in);
struct FUN_008b3d70_Body
{
    void* Bipedanim_GetReferenceFlagsOrZero();
};
FUN_008b3d70_Body* bhkUtilFunctions_GetClosestBody(FUN_008b3d70_World* world, FUN_008b3d70_Sphere* s, int flag);
struct FUN_008b3d70_Wrap
{
    FUN_008b3d70_Hit* FUN_0044ddc0();
};
FUN_008b3d70_Wrap* FUN_004b5a20(void* p);

struct FUN_008b3d70_Picker
{
    FUN_008b3d70_World* TESObjectREFR_Get3D();
    void* Actor_GetClosestBone(FUN_008b3d70_Vec3 start, FUN_008b3d70_Vec3 end);
};

// @fnv 0x008b3d70
// src: XBOX_PDB 0x008b3d70
void* FUN_008b3d70_Picker::Actor_GetClosestBone(FUN_008b3d70_Vec3 start, FUN_008b3d70_Vec3 end)
{
    FUN_008b3d70_World* world = TESObjectREFR_Get3D();
    FUN_008b3d70_Hit* object = 0;
    float distance = 512.0f;
    FUN_008b3d70_Vec3 direction = end.SubtractIntoVector(start);
    NiPoint3_UnitizeVector(&direction);
    FUN_008b3d70_Vec3 origin = end.SubtractIntoVector(direction.ApplyScaled(distance).ApplyScaled(0.5f));
    object = ArrowProjectile_PickSceneGraph(world, origin, direction, &distance, 0);
    if (!object)
    {
        FUN_008b3d70_Sphere bound;
        bound.BGSPrimitive_EvaluateValue_006240d0();
        FUN_008b3d70_hkVec center;
        center.FUN_006815c0();
        NI2HK(center, end);
        bound.hkSphere_setPosition(center);
        bound.hkSphere_setRadius(200.0f);
        FUN_008b3d70_Body* body = bhkUtilFunctions_GetClosestBody(world, &bound, 0);
        if (body)
        {
            FUN_008b3d70_Wrap* wrapper = FUN_004b5a20(body->Bipedanim_GetReferenceFlagsOrZero());
            if (wrapper)
                object = wrapper->FUN_0044ddc0();
        }
    }
    if (object)
        return object->GetObject();
    return 0;
}
