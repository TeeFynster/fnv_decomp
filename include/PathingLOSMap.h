#pragma once
#include "NiRefObject.h"
#include "DummyPointerMap.h"

class NavMeshCollection;
class NavMeshPtr;
class NiSortAdjustNode;
class SpawnedTarget;

class PathingLOSMap : public NiRefObject
{
public:
    struct Shell1c
    {
        unsigned int unk00;

        void AppendValue(NavMeshPtr& ptr);
        void ReleaseMember();
    };

    DummyPointerMap m_map;
    union
    {
        char* pTriangleScores;
        char* m_pData;
    };
    Shell1c m_shell1c;
    unsigned char unk20[0x0C];
    unsigned int m_uTotalCount;
    unsigned char unk30[0x0C];
    float f3c;
    float f40;
    float f44;
    float f48;
    unsigned int unk4C;

    virtual ~PathingLOSMap();

    void* DestroyAndFree(unsigned int flags);
    bool BuildNavMeshMap(NavMeshCollection* pNavMeshArray);
    char* GetTriangleScore(unsigned int aNavMeshID);
    void GetMapValue(unsigned int uiKey, unsigned int& ruiValue);
    char GetLOSValue(unsigned int aiOffset, unsigned short aOffset);
    char GetNavMeshAndTriangleForIndex(unsigned int limit, SpawnedTarget* target, unsigned short* outOffset);
    bool GetUnseenNavMeshAndTriangle(unsigned int a, unsigned int b);
    NiSortAdjustNode* CreateSortAdjustNode();
    void ClampNonPositiveTextChars();
    bool HasNavMeshEntry(unsigned int aiNavMeshID);
};
