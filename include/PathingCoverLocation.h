#pragma once

#include "PathingLocation.h"
#include "NiPoint3.h"

class BGSLoadFormBuffer;
class BGSLoadGameBuffer;
class BGSSaveFormBuffer;
class BGSSaveGameBuffer;

class PathingCoverLocation : public PathingLocation
{
public:
    virtual void SaveGame(BGSSaveGameBuffer*);
    virtual void LoadGame(BGSLoadFormBuffer*);

    NiPoint3 a;
    NiPoint3 b;
    NiPoint3 c;
    unsigned char f04c;
    unsigned char f04d;
    unsigned char f04e;
    unsigned char f04f;
    unsigned char f050;
    unsigned char f051;
    unsigned char f052;

    void SetCoverData(unsigned short a, unsigned short b, unsigned short c, char e, char f, char g);
    unsigned char* GetKey_006e4570();
    bool IsLedgeCover_006e4820();
    bool IsLeftSideClosest(const NiPoint3& point);

    PathingCoverLocation& operator=(const PathingCoverLocation&);
    void Load(BGSLoadGameBuffer*);
    void SaveToBuffer(BGSSaveFormBuffer*);
};
