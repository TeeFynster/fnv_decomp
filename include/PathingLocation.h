#pragma once

// Define when a complete local NiPoint3 definition precedes this header.
#ifndef FNV64_PATHINGLOCATION_USE_LOCAL_NIPOINT3
#include "NiPoint3.h"
#endif

class BGSLoadFormBuffer;
class BGSLoadGameBuffer;
class BGSSaveGameBuffer;
class BGSWorldLocation;
class CoordinateTriple;
class FindTriangleForLocationFilter;
class Location16;
class MoveActor454;
class NavMeshInfo;
class NavMeshPtr;
class TESObjectCELL;
class TESObjectREFR;
class TESWorldSpace;
template <class T, unsigned int N> class BSSimpleArray;

class PathingLocation
{
public:
    virtual void SaveGame(BGSSaveGameBuffer*);
    virtual void LoadGame(BGSLoadFormBuffer*);

    NiPoint3 Location;
    const NavMeshInfo* m_pLocationNavMesh;
    const BSSimpleArray<const NavMeshInfo*, 1024>* pNavMeshInfoArray;
    TESObjectCELL* pCell;
    TESWorldSpace* m_pContainingWorldspace;
    unsigned int m_uiPathingFlags;
    unsigned short m_usTriangleID;
    unsigned char uiFlags;
    union
    {
        char _pad_27;
        unsigned char unk27;
    };

    PathingLocation();
    PathingLocation(const PathingLocation&);
    PathingLocation(TESObjectREFR*);
    PathingLocation(BGSWorldLocation*);
    PathingLocation(Location16*);
    PathingLocation(const NiPoint3&, const NavMeshInfo*);
    PathingLocation(const NiPoint3&, const NavMeshInfo*, unsigned short);
    PathingLocation(const BGSWorldLocation&, NavMeshInfo*, unsigned short);
    PathingLocation(const CoordinateTriple&, NavMeshInfo*, unsigned short);
    PathingLocation(const NiPoint3&, void*);
    PathingLocation(const NiPoint3*, TESWorldSpace*);
    PathingLocation(const NiPoint3&, TESObjectCELL*);
    PathingLocation(const NiPoint3&, TESObjectREFR*);
    PathingLocation(const NiPoint3&, MoveActor454*);
    PathingLocation(const NiPoint3&, TESObjectCELL*, TESWorldSpace*);
    PathingLocation(const NiPoint3&, const PathingLocation&);
    ~PathingLocation();
    PathingLocation& operator=(const PathingLocation&);

    void SetNavMeshInfo(void*);
    void SetLocation(void*);
    void SetLocationSimple(void*);
    void SetTriangleIndex(unsigned short);
    NiPoint3 GetLocation();
    NiPoint3 GetLocation() const;
    NiPoint3 GetPoint() const;
    NiPoint3 FUN_005c3420() const;
    template <class Point>
    Point GetLocation();
    template <class Point>
    Point GetLocation() const;
    template <class Point>
    Point GetPoint() const;
    template <class Point>
    Point FUN_005c3420() const;
    NiPoint3 FastNavMeshTriLocation_GetLocation();
    TESObjectCELL* GetContainingCell();
    TESObjectCELL* FUN_006dd4f0() const;
    TESWorldSpace* GetParentWorldspace();
    TESWorldSpace* FUN_00441110() const;
    TESObjectCELL* GetCellSimple();
    TESWorldSpace* GetWorldspaceSimple();
    void* GetAssociatedNavMesh();
    bool IsOnNavMesh(void*);
    bool ResolveNavMesh(NavMeshPtr*);
    bool ResolveNavMesh(NavMeshPtr&);
    bool FindNavMeshTriangle(NavMeshPtr*, unsigned short*);
    bool FindNavMeshTriangle(NavMeshPtr&, unsigned short&);
    unsigned short GetTriangle();
    unsigned short GetShortValueAtOffset24();
    bool HasValidTriangle();
    bool HasNavMesh();
    void* GetNavMeshInfo();
    bool FindContainingTriangle(FindTriangleForLocationFilter*);
    bool IsPathingLocationValid();
    bool HasPathingLocation();
    bool IsPathingLocationFlagSet();
    bool PathingLocation_QUnused();
    bool FUN_006dd610(void*);
    bool FUN_006dd640(NavMeshPtr*, unsigned short*);
    bool FUN_006dd6a0();
    bool FUN_006dd6f0(int);
    bool FUN_006dd6f0(bool);
    bool FUN_006de250();
    bool QUnused();
    void SetUnused();
    void ClearUnused();
    bool QValid();
    void ResetLocation();
    void WriteDebugString(char*, int);
    bool IsDistanceBelowThreshold(float);
    bool IsCloseTo(void*, float);
    void SetLocationData(void*, TESObjectCELL*, TESWorldSpace*);
    void SetLocationData(const NiPoint3&, TESObjectCELL*, TESWorldSpace*);
    bool QAllMeshesReachable();
    void SetAllMeshesReachable(int);
    void SetAllMeshesReachable(bool);
    bool GetAllMeshesReachable();
    void LoadGame(BGSLoadGameBuffer*);
    void Load(BGSLoadGameBuffer*);
};
