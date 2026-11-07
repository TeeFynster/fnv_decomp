
// src/fallout_shared/pathfinding/pathfind_decl_variant_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x006da420: the skeleton of src/fallout_shared/pathfinding/pathfind_decl_variant.cpp
// with declarations corrected to what the original code does (NiPoint3.h: NiPoint3 operator+(const NiPoint3& point) cons -> NiPoint3() {} NiPoint3(const NiPoint3& poi). Move the function to its real unit once
// that unit declares it this way.

// src/fallout_shared/pathfinding/pathfind_decl_variant.cpp - declaration variant unit created 2026-10-24 by decl_variants.py for paused function 0x006da420: the skeleton of src/fallout_shared/pathfinding/pathfind.cpp
// with declarations corrected to what the original code does (pathfind_local_types.h: PathingLocation += PathingLocation(TESObjectREFR* ref);). Move the function to its real unit once
// that unit declares it this way.
#include "../../../include/BSSimpleArray.h"
#include "../../../include/NavMesh.h"
#include "../../../include/NavMeshPtr.h"
#include "../../../include/PathBuilder.h"
#include "../../../include/Pathing.h"
#include "../../../include/PathingLocation.h"
#include "../../../include/PathingPath.h"
#include "../../../include/PathingRequest.h"
#include "../../../include/PathingRequestClosePoint.h"
#include "../../../include/PathingRequestFlee.h"
#include "../../../include/PathingRequestHide.h"
#include "../../../include/PathingRequestLOS.h"
#include "../../../include/PathingRequestOptimalLocation.h"
#include "../../../include/PathingSolution.h"
#include "../../../include/TESPackage.h"
#include "pathfind_decls_decl_pathfind_decl_pathfind_decl_variant.h"

struct RotationMatrix
{
    float entry[3][3];
    RotationMatrix();
    void FUN_004a0c90(float angle);
    NiPoint3 FUN_004b4500(const NiPoint3* axis);
};
// A native const Point3 member consumes only its receiver in ECX.
float __fastcall FUN_004a7290(const NiPoint3& point);
bool __cdecl FUN_006d7490(PathingLocation*, NiPoint3*, PathingLocation*, int);
bool __cdecl Pathing_CheckLineOfSight(PathingLocation&, PathingLocation&, PathingLocation*, Pathing::CheckLineOfSightFilter*);
extern NiPoint3 DAT_011a9478;
extern const NiPoint3 DAT_011a9484;
extern const float DAT_01032adc;
// @fnv 0x006da420
// src: XBOX_PDB 0x006da420
NiPoint3 __cdecl Pathing_ComputeFinalTangentForActor(float angle, const PathingLocation& sourceLocation, float width)
{
    RotationMatrix seed_2;
    seed_2.FUN_004a0c90(angle);
    NiPoint3 base8 = seed_2.FUN_004b4500(&DAT_011a9478);
    PathingLocation mainLocation(sourceLocation);
    NiPoint3 mainPoint4 = mainLocation.GetLocation();
    NiPoint3 endPoint6 = mainPoint4 - base8 * DAT_01032adc;
    PathingLocation hit;
    if (!FUN_006d7490(&mainLocation, &endPoint6, &hit, 0))
        endPoint6 = hit.GetLocation();
    NiPoint3 difference5 = endPoint6 - mainPoint4;
    NiPoint3 offset_2 = difference5.CrossProduct(DAT_011a9484) * width;
    PathingLocation leftStart4(mainPoint4 - offset_2, mainLocation);
    PathingLocation leftEnd(endPoint6 - offset_2, mainLocation);
    if (!Pathing_CheckLineOfSight(leftStart4, leftEnd, &hit, 0))
    {
        if (FUN_004a7290(hit.GetLocation() - leftStart4.GetLocation()) < FUN_004a7290(difference5))
            endPoint6 = hit.GetLocation();
    }
    PathingLocation rightStartX(mainPoint4 + offset_2, mainLocation);
    PathingLocation rightEnd(endPoint6 + offset_2, mainLocation);
    if (!Pathing_CheckLineOfSight(rightStartX, rightEnd, &hit, 0))
    {
        if (FUN_004a7290(hit.GetLocation() - rightStartX.GetLocation()) < FUN_004a7290(difference5))
            endPoint6 = hit.GetLocation();
    }
    return mainPoint4 - endPoint6;
}
