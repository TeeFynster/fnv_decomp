#pragma once

#include "PathingRequestClosePoint.h"

class PathingRequestSafeStraightLine : public PathingRequestClosePoint
{
public:
    PathingRequestSafeStraightLine(int ai);
    virtual ~PathingRequestSafeStraightLine();
    virtual void CopyTo(PathingRequest*);
    virtual void SaveGame(BGSSaveFormBuffer*);
    virtual void LoadGame(BGSLoadFormBuffer*);
    virtual void InitLoadGame(BGSLoadFormBuffer*);

    int FUN_004036b0();
    void* FUN_006e5fd0(unsigned int flags);
    void __thiscall FUN_006e6080(PathingRequest* apDest);
    void __thiscall FUN_006e60c0(int a1);
    void __thiscall SaveToBuffer(BGSSaveFormBuffer* apSaveGameBuffer);
    void FUN_006e6110(BGSLoadFormBuffer* buffer);
    void __thiscall ResolveReference(BGSLoadFormBuffer* apLoadGameBuffer);

    int pTarget;
};
