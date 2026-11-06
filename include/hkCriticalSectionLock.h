#pragma once

#include "hkCriticalSection.h"

class hkCriticalSectionLock
{
public:
    hkCriticalSection* m_kCriticalSection;

    hkCriticalSectionLock(hkCriticalSection* pkSection);
    hkCriticalSectionLock(void* section);
    ~hkCriticalSectionLock();
};
