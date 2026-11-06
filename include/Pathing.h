#pragma once

#include "NiTPointerMap.h"

class NavMesh;
class NavMeshInfo;
class NiPoint3;
class PathingActorData;
class PathingLocation;
class PathingPath;
class PathingRequest;
class PathingRequestFlee;
class PathingRequestHide;
class PathingRequestLOS;
class PathingRequestOptimalLocation;
class PathingSolution;
class RadioPathingPath;
class TESObjectCELL;
class TESObjectREFR;
class TESWorldSpace;

class Pathing
{
public:
    unsigned char pad[28];
    NiTPointerMap<unsigned int, TESObjectREFR*> map;

    class CheckLineOfSightFilter;

    enum TELEPORT_DOOR_PATH_RESTRICTION
    {
        ANY_SPACE = 0,
        ONE_WORLDSPACE = 1,
        INTERIOR_ONLY = 2,
        RestrictionNone = 0
    };

    enum DOOR_LOCK_DISPOSITION
    {
        DOOR_LOCK_DISPOSITION_NORMAL = 0,
        DOOR_LOCK_DISPOSITION_IGNORELOCKS = 1,
        DOOR_LOCK_DISPOSITION_LOCKS_ARE_MINIMAL_USE = 2,
        DOOR_LOCK_DISPOSITION_RADIO = 3,
        DEFAULT_LOCKS = 0,
        IGNORE_LOCKS = 1,
        LOCKS_UNUSED = 2,
        RADIO_LOCKS = 3,
        LockDefault = 0,
        kIgnoreLocks = 0
    };

    bool FUN_00460340();
    NavMeshInfo* FindReferenceByFormId();
    TESObjectREFR* FindReferenceByFormId(unsigned int);

    static bool BuildPath(PathingRequest*, PathingSolution*);
    static bool CalculateHidePath(PathingRequestHide*, PathingSolution*);
    static bool CalculateFleePath(PathingRequestFlee*, PathingSolution*);
    static bool BuildLineOfSightPath(PathingRequestLOS*, PathingSolution*);
    static bool SelectOptimalLocation(PathingRequestOptimalLocation*, PathingSolution*);
    static bool FindRouteBetweenLocations(const PathingLocation&, const PathingLocation&, PathingPath*,
                                         TELEPORT_DOOR_PATH_RESTRICTION, float, PathingActorData*,
                                         DOOR_LOCK_DISPOSITION);
    static bool FindRouteBetweenLocations(const PathingLocation&, const PathingLocation&, RadioPathingPath*,
                                         TELEPORT_DOOR_PATH_RESTRICTION, float, PathingActorData*,
                                         DOOR_LOCK_DISPOSITION);
    static bool FindClosestPathingPoint(TESWorldSpace*, TESObjectCELL*, const NiPoint3&, NiPoint3*);
    static float FindPathDistance(const PathingLocation&, const PathingLocation&, float, PathingActorData*,
                                  DOOR_LOCK_DISPOSITION);
    static bool FindPathingLocationOnNavMesh(PathingLocation&, const NiPoint3&, NavMesh*, unsigned short,
                                            PathingLocation*, CheckLineOfSightFilter*);
    static bool FindPathingLocation(PathingLocation&, const NiPoint3&, PathingLocation*, CheckLineOfSightFilter*);
    static bool __cdecl FindPathingLocation(PathingLocation&, const NiPoint3&, PathingLocation*, void*);
};
