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
    void FUN_00507610(float);
    void FUN_006e5ee0(float);
    void* __thiscall FUN_006e3f70(unsigned int);
    void __thiscall FUN_006e5f00(BGSSaveFormBuffer*);
    void FUN_006e5f50(BGSLoadFormBuffer*);
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
