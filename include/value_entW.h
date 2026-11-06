#pragma once

#include <basetsd.h>

class value_entW
{
public:
    wchar_t* ve_valuename;
    unsigned long ve_valuelen;
    DWORD_PTR ve_valueptr;
    unsigned long ve_type;
};
