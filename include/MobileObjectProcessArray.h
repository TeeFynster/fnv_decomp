#pragma once

#include "NiTexturingProperty.h"

class MobileObject;
enum PROCESS_TYPE;

class MobileObjectProcessArray
{
public:
    NiTPrimitiveArray<MobileObject*> m_kMobileObjectArray;
    unsigned int m_auiProcessHeadIndices[4];
    unsigned int m_auiProcessTailIndices[4];
    unsigned int m_auiNextUpdateIndices[4];

    void Init();
    void AddActor(MobileObject*, int);
    void RemoveActor(MobileObject*, int);
    void RemoveActor(unsigned int);
    int GetProcessLevelFromIndex(unsigned int);
    PROCESS_TYPE GetProcessLevelFromIndex(unsigned int auiIndex) const;
    void SetProcessLevelForIndex(unsigned int, int);
    MobileObject* GetItem(unsigned int);
    MobileObject* GetItem(unsigned int) const;
    MobileObject* GetNextUpdateProcess(int);
    bool IncNextUpdate(int, int);
    int GetIndexFromActor(MobileObject*, int);
    unsigned int GetIndexFromObject(MobileObject* apObject, PROCESS_TYPE aeLevel) const;
    unsigned int GetSize();
    unsigned int GetSize() const;
    unsigned int GetHead(PROCESS_TYPE aeLevel) const;
    unsigned int GetTail(PROCESS_TYPE aeLevel) const;
    unsigned int GetProcessLevelHead(int);
    unsigned int GetProcessLevelTail(int);
    void MoveToLastUpdated(int, MobileObject*);
    void CheckNextUpdateBounds();
    void GrowArraySize(int);
#if !defined(_MSC_VER) || defined(__vecDelDtor)
    void* __vecDelDtor(unsigned int);
#else
    // MSVC supplies __vecDelDtor for the nontrivial array member.
#endif
    unsigned int ProcessArray_GetProcessLevelTail(int group);
    unsigned int ProcessArray_GetProcessLevelHead(int group);
    MobileObject* ProcessArray_GetItem(unsigned int index);
};
