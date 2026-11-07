#pragma once

#include "PathingRequest.h"

class LocationAccess;

class PathingRequestClosePoint : public PathingRequest
{
public:
    PathingRequestClosePoint();
    PathingRequestClosePoint(PathingRequestClosePoint*);
    virtual ~PathingRequestClosePoint();
    virtual void CopyTo(PathingRequest*);
    virtual void SaveGame(BGSSaveFormBuffer*);
    virtual void LoadGame(BGSLoadFormBuffer*);


    void SetOrigin(const PathingLocation&);
    void AssignPathingLocation(LocationAccess*);
    void AssignPathingLocation(PathingLocation*);
    void PathingRequestClosePoint_SetMinDistance(float);
    void SetMaxDistance_006e5ee0(float);
    void* __thiscall FUN_006e3f70(unsigned int);
    void __thiscall PathingRequestOptimalLocation_SaveGame(BGSSaveFormBuffer*);
    void PathingRequestOptimalLocation_LoadGame(BGSLoadFormBuffer*);
    void __thiscall CopyToWithClosePoint(PathingRequest*);
    float GetMinDist();
    float GetMaxDist();

    union
    {
        unsigned int extra[2];
        struct
        {
            float fPointHeight;
            float m_fUnknownValue2;
        };
    };
};
