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
    void FUN_004a39f0(int layer);
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
    void FUN_0059ceb0(hkpClosestRayHitCollector* collector);
    void FUN_004a3f70(HandleRef filter);
    void FUN_004a3da0(const NiPoint3& start);
    void FUN_004a3eb0(const NiPoint3& end);
};
class LookTarget
{
public:
    void* FUN_00553ee0(BhkPickData* ray);
};
class GlobalObject_0045d260
{
  public:
    bool IsInCombat();
};
extern GlobalObject_0045d260 g_011f1c7c;
float __cdecl GetScaleOrHeightDelta(TESObjectREFR* source, int mode);
float __cdecl FUN_009a8460(TESObjectREFR* target, int mode, bool flag);
TESObjectREFR* __cdecl FUN_0056f930(void* hit);
// @fnv 0x009a7940
bool __cdecl FUN_009a7940(Actor* source, TESObjectREFR* target, const NiPoint3& from, const NiPoint3& to,
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
        end.z += FUN_009a8460(target, 2, true);
    BhkPickData ray;
    HandleRef filter = source->FUN_00931ed0();
    if (target && target->IsMobileObject())
    {
        Actor* mobile = static_cast<Actor*>(target);
        filter = mobile->FUN_00931ed0();
    }
    hkpClosestRayHitCollector collector(layer, reinterpret_cast<const SightFilter*>(&filter));
    ray.FUN_0059ceb0(&collector);
    filter = source->FUN_00931ed0();
    filter.FUN_004a39f0(layer);
    ray.FUN_004a3f70(filter);
    ray.FUN_004a3da0(start);
    ray.FUN_004a3eb0(end);
    void* hit = source->FUN_008d6f30()->FUN_00553ee0(&ray);
    if (!hit)
    {
        g_011f1c7c.IsInCombat();
        return true;
    }
    TESObjectREFR* hitRef = FUN_0056f930(hit);
    if (target && hitRef == target)
    {
        g_011f1c7c.IsInCombat();
        return true;
    }
    g_011f1c7c.IsInCombat();
    return false;
}
