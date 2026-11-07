#pragma once

class BooleanFloatQuery;
class HitInfo;

class HitArray
{
public:
    BooleanFloatQuery* data;
    int size;
    unsigned int capacity;

    void Append(const BooleanFloatQuery* src);
    HitArray* TESDataHandler_GetWorldSpaceList();
    int FUN_00726070();
    HitInfo* GetEntryAt(int i);
};
