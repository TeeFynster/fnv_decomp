#pragma once

#include <windows.h>
#include "hkReferencedObject.h"
#include "hkSingleton.h"

class hkReferencedObjectLock : public hkReferencedObject, public hkSingleton<hkReferencedObjectLock>
{
public:
    hkReferencedObjectLock() throw();
    void ReleaseReference() throw();

    int m_multiThreaded;
    int m_lLockCount;
    int unk10;
    int unk14;
    CRITICAL_SECTION m_kCriticalSection;
};
