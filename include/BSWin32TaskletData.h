#pragma once

#include "BSTaskletData.h"
#include "LockPrimitive.h"

class BSWin32TaskletGroupData;

class BSWin32TaskletData : public BSTaskletData
{
public:
    BSWin32TaskletData();
    virtual ~BSWin32TaskletData();

    BSWin32TaskletGroupData* m_pTaskletGroupData;
    bool m_bFlagAfterTaskletGroup;
    LockPrimitive kTaskDataLock;
    BSWin32TaskletData* m_pTaskletData;
};
