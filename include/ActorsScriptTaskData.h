#pragma once

#include "MobileObjectTaskletData.h"

class ActorsScriptTaskData : public MobileObjectTaskletData
{
public:
    ActorsScriptTaskData(BSTFreeList<MobileObjectTaskletContext>* apList);

    BSSimpleList<MobileObject*>* pPrevObjectList;
    unsigned int uiRunCount;
};
