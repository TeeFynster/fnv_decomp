#pragma once

#include "hkStringPtr.h"
#include "hkBool.h"

class hkaBone
{
public:
    hkStringPtr m_name;
    hkBool m_bLockTranslation;

    hkaBone();
    static void* operator new(unsigned int, void* p);
    static void operator delete(void*, void*);
};
