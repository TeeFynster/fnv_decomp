#pragma once

#include "BSFileCache.h"

class BSWin32FileCache : public BSFileCache
{
public:
    BSWin32FileCache();
    virtual ~BSWin32FileCache();
    virtual int vf05(int arg);
};
