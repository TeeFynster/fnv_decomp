#pragma once

#include "NiPoint3.h"

template <class T, unsigned int Growth> class BSSimpleArray;
class NavMeshTriList;

class NavMeshGrid
{
public:
    unsigned int m_uiGridIndex;
    float m_fFirstGridValue;
    float NavMeshPointEntry;
    NiPoint3 IndexedPointRecord;
    NiPoint3 IndexedPointData;
    BSSimpleArray<unsigned short, 1024>* TESFileRecordLoader;

    NavMeshGrid();
    void GetCellCoords(const NiPoint3& arPos, unsigned int& arRow, unsigned int& arCol);
    int GetCellIndex(const NiPoint3& arPos);
    NavMeshTriList* FUN_006967c0(unsigned int auiCol, unsigned int auiRow);
    void GetTriListAtPosition(const NiPoint3& arPos, NavMeshTriList** appList);
    void GetTriListAtPosition(const NiPoint3& arPos, NavMeshTriList*& arpList);
    void GetTriListAtPosition(const NiPoint3* apPos, NavMeshTriList** appList);
    void InitFromPoints(const NiPoint3& arMin, const NiPoint3& arMax, unsigned int auiCount);
    unsigned int FUN_00559450();
    void FUN_00696500(unsigned short ausTriangle, unsigned int auiCol, unsigned int auiRow);
    NiPoint3 FUN_0069d790(unsigned int auiCol, unsigned int auiRow);
    void FUN_0069d2d0();
    void FUN_0069dd50(NavMeshGrid* apGrid);
    void FUN_0069dd50(NavMeshGrid* apGrid) const;
};
