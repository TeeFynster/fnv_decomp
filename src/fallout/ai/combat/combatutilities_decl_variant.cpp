#include "../../../../include/NiPoint3.h"
#include "../../../../include/hkpClosestRayHitCollector.h"
// Avoid collision with the compiler-generated constructor closure in TESBoundObject.
#define __local_vftable_ctor_closure FNVLocalVftableCtorClosure
#include "../../../../include/Actor.h"
#include "../../../../include/AlchemyItem.h"
#include "../../../../include/BGSProjectile.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/PathingRequest.h"
#include "../../../../include/TESObjectREFR.h"
#undef __local_vftable_ctor_closure

// Declaration variant for the line-of-sight query at 0x009a7940.
#pragma strict_gs_check(on)
class HandleRef
{
public:
    unsigned int bits;
    HandleRef(int bits);
    void CFilter_SetLayer(int layer);
};
struct __declspec(align(16)) SightRayInput
{
    SightVector4 from, to;
    bool enableShapeCollectionFilter;
    HandleRef filter;
};
struct __declspec(align(16)) BhkPickData
{
    SightRayInput input;
    SightRayOutput output;
    SightVector4 startBounds;
    void* unkA0;
    hkpClosestRayHitCollector* collector;
    unsigned int collectorMode;
    bool enabled;
    BhkPickData();
    void bhkPickData_SetClosestCollector(hkpClosestRayHitCollector* collector);
    void bhkPickData_SetFilter(HandleRef filter);
    void bhkPickData_SetFrom(const NiPoint3& start);
    void bhkPickData_SetTo(const NiPoint3& end);
};
class LookTarget
{
public:
    void* TESObjectCELL_Pick(BhkPickData* ray);
};
class GlobalObject_0045d260
{
  public:
    bool IsInCombat();
};
extern GlobalObject_0045d260 g_011f1c7c;
float __cdecl GetScaleOrHeightDelta(TESObjectREFR* source, int mode);
float __cdecl CombatUtilities_GetTargetFiringZOffset(TESObjectREFR* target, int mode, bool flag);
TESObjectREFR* __cdecl TESObjectREFR_FindReferenceFor3D(void* hit);
// @fnv 0x009a7940
// src: XBOX_PDB 0x009a7940
bool __cdecl CombatUtilities_CalculateLOS(Actor* source, TESObjectREFR* target, const NiPoint3& from, const NiPoint3& to,
                          int unused, int requestedLayer)
{
    g_011f1c7c.IsInCombat();
    int layer = 37;
    if (requestedLayer != -1)
        layer = requestedLayer;
    NiPoint3 start = from;
    start.z += GetScaleOrHeightDelta(source, 1);
    NiPoint3 end = to;
    if (target)
        end.z += CombatUtilities_GetTargetFiringZOffset(target, 2, true);
    BhkPickData ray;
    HandleRef filter = source->FUN_00931ed0();
    if (target && target->IsMobileObject())
    {
        Actor* mobile = static_cast<Actor*>(target);
        filter = mobile->FUN_00931ed0();
    }
    hkpClosestRayHitCollector collector(layer, reinterpret_cast<const SightFilter*>(&filter));
    ray.bhkPickData_SetClosestCollector(&collector);
    filter = source->FUN_00931ed0();
    filter.CFilter_SetLayer(layer);
    ray.bhkPickData_SetFilter(filter);
    ray.bhkPickData_SetFrom(start);
    ray.bhkPickData_SetTo(end);
    void* hit = source->FUN_008d6f30()->TESObjectCELL_Pick(&ray);
    if (!hit)
    {
        g_011f1c7c.IsInCombat();
        return true;
    }
    TESObjectREFR* hitRef = TESObjectREFR_FindReferenceFor3D(hit);
    if (target && hitRef == target)
    {
        g_011f1c7c.IsInCombat();
        return true;
    }
    g_011f1c7c.IsInCombat();
    return false;
}
