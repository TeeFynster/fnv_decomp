
// pathfind_ctx_variant.cpp: context variant of src/fallout_shared/pathfinding/pathfind.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "../../../include/NiPoint3.h"
#include "../../../include/NiMatrix3.h"
#include "../../../include/PathingLocation.h"

extern NiPoint3 DAT_011a9478;
extern const NiPoint3 DAT_011a9484;
extern const NiPoint3 DAT_011f426c;
extern const float DAT_01032adc;
extern const float DAT_01018204;
extern const double DAT_0106cbc8;
extern const double DAT_01012060;
extern const double DAT_010240c0;
extern bool __cdecl FUN_006d7490(PathingLocation&, const NiPoint3&, PathingLocation*, void*);
extern bool __cdecl Pathing_CheckLineOfSight(PathingLocation&, PathingLocation&, PathingLocation*, void*);

// @fnv 0x006d99a0
// src: COMMUNITY 0x006d99a0
NiPoint3 __cdecl Pathing_ComputeInitialTangentForActor(float angle, PathingLocation* startRef, PathingLocation* endRef, float radius)
{
    NiMatrix3 rotation6;
    rotation6.MakeZRotation(angle);
    NiPoint3 forwardAxis = rotation6.operator*(DAT_011a9478);
    PathingLocation start0(*startRef);
    NiPoint3 origin20 = start0.FUN_005c3420();
    NiPoint3 goalId_ = origin20.FUN_00439e90(forwardAxis.ApplyScaled(DAT_01032adc));
    PathingLocation first2;
    if (!FUN_006d7490(start0, goalId_, &first2, 0))
        goalId_ = first2.FUN_005c3420();
    NiPoint3 initial = goalId_.SubtractIntoVector(origin20);
    NiPoint3 sideShape7 = initial.FUN_0053d1a0(DAT_011a9484).ApplyScaled(radius);
    PathingLocation leftStartB(origin20.SubtractIntoVector(sideShape7), start0);
    PathingLocation leftEnd5(goalId_.SubtractIntoVector(sideShape7), start0);
    if (!Pathing_CheckLineOfSight(leftStartB, leftEnd5, &first2, 0))
    {
        if (first2.FUN_005c3420().SubtractIntoVector(leftStartB.FUN_005c3420()).FUN_004a7290() <
            initial.FUN_004a7290())
            goalId_ = first2.FUN_005c3420();
    }
    PathingLocation rightStart2(origin20.FUN_00439e90(sideShape7), start0);
    PathingLocation rightEnd2(goalId_.FUN_00439e90(sideShape7), start0);
    if (!Pathing_CheckLineOfSight(rightStart2, rightEnd2, &first2, 0))
    {
        if (first2.FUN_005c3420().SubtractIntoVector(rightStart2.FUN_005c3420()).FUN_004a7290() <
            initial.FUN_004a7290())
            goalId_ = first2.FUN_005c3420();
    }
    goalId_.Subtract(forwardAxis.ApplyScaled(radius).ApplyScaled(DAT_01018204));
    PathingLocation end19(*endRef);
    NiPoint3 endOriginVal = end19.FUN_005c3420();
    PathingLocation endHitX;
    if (!FUN_006d7490(end19, goalId_, &endHitX, 0))
        return DAT_011f426c;
    NiPoint3 endDelta = goalId_.SubtractIntoVector(endOriginVal);
    NiPoint3 endSide = endDelta.FUN_0053d1a0(DAT_011a9484).ApplyScaled(radius);
    PathingLocation endLeftEndA(endOriginVal.SubtractIntoVector(sideShape7), end19);
    PathingLocation endLeftStart6(goalId_.SubtractIntoVector(sideShape7), end19);
    if (!Pathing_CheckLineOfSight(endLeftEndA, endLeftStart6, &endHitX, 0))
        return DAT_011f426c;
    PathingLocation endRightStart4(endOriginVal.FUN_00439e90(sideShape7), end19);
    PathingLocation endRightEnd2(goalId_.FUN_00439e90(sideShape7), end19);
    if (!Pathing_CheckLineOfSight(endRightStart4, endRightEnd2, &endHitX, 0))
        return DAT_011f426c;
    NiPoint3 directionX = endOriginVal.SubtractIntoVector(origin20);
    float distance29 = directionX.FUN_00457910();
    float i = directionX.DotProduct(forwardAxis);
    if (i < DAT_0106cbc8)
    {
        return DAT_011f426c;
    }
    else if (i < DAT_01012060 && distance29 < DAT_010240c0)
    {
        return DAT_011f426c;
    }
    return goalId_.SubtractIntoVector(origin20);
}
