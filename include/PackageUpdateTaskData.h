#pragma once

#include "MobileObjectTaskletData.h"

class PackageUpdateTaskData : public MobileObjectTaskletData
{
public:
    PackageUpdateTaskData(BSTFreeList<MobileObjectTaskletContext>* apList);

    BSSimpleList<MobileObject*>* pPrevObjectList;
    unsigned int uiUpdatedCount;
    unsigned int uiSkippedCount;

    void RunPackageUpdateTask(unsigned int aiThread);
};
