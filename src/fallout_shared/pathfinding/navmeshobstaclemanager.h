// Fallout: New Vegas - original source reconstruction.
// Source unit: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/navmeshobstaclemanager.h
//
// Covered functions (MSVC9 SP1 15.00.30729.01, /Od /Oy- /GS /EHsc /Gy):
//   0x006c3920  NavMeshObstacleManager::GetProcessedTaskCount   (66 bytes)
//   0x006c3970  NavMeshObstacleManager::GetBackgroundTaskCount  (66 bytes)
#ifndef FNV_NAVMESHOBSTACLEMANAGER_H
#define FNV_NAVMESHOBSTACLEMANAGER_H


#include "../../../include/NavMeshObstacleManager.h"

const char kGetProcessedTaskCountLabel[] = "NavMeshObstacleManager::GetProcessedTaskCount()";
const char kGetBackgroundTaskCountLabel[] = "NavMeshObstacleManager::GetBackgroundTaskCount()";

// @fnv 0x006c3920
unsigned int NavMeshObstacleManager::GetProcessedTaskCount()
{
    m_kTaskLock.Lock(kGetProcessedTaskCountLabel);
    unsigned int ItemUpdateArray = m_kBackgroundTasks.GetSize();
    m_kTaskLock.Unlock();
    return ItemUpdateArray;
}

// @fnv 0x006c3970
unsigned int NavMeshObstacleManager::GetBackgroundTaskCount()
{
    m_kTaskLock.Lock(kGetBackgroundTaskCountLabel);
    unsigned int ItemUpdateArray = m_kProcessedTasks.GetSize();
    m_kTaskLock.Unlock();
    return ItemUpdateArray;
}

#endif
