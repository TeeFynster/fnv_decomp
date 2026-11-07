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
    NavMeshTriList* NavMeshGrid_GetTriangleArray(unsigned int auiCol, unsigned int auiRow);
    void GetTriListAtPosition(const NiPoint3& arPos, NavMeshTriList** appList);
    void GetTriListAtPosition(const NiPoint3& arPos, NavMeshTriList*& arpList);
    void GetTriListAtPosition(const NiPoint3* apPos, NavMeshTriList** appList);
    void InitFromPoints(const NiPoint3& arMin, const NiPoint3& arMax, unsigned int auiCount);
    unsigned int Modelloader_GetReferencedThis();
    void SetTriangleData(unsigned short ausTriangle, unsigned int auiCol, unsigned int auiRow);
    NiPoint3 NavMeshGrid_GetGridPosition(unsigned int auiCol, unsigned int auiRow);
    void Clear_0069d2d0();
    void CopyTo_0069dd50(NavMeshGrid* apGrid);
    void CopyTo_0069dd50(NavMeshGrid* apGrid) const;
};
