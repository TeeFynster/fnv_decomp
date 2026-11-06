#pragma once

#include <stddef.h>
#include "hkVector4.h"

struct ClassMemberDescriptor;
class hkClass;

class CodeInfo
{
public:
    hkVector4 m_offset;

    class CommandArgument;
    struct DefaultStruct;

    static const ClassMemberDescriptor Members[];
    static const hkClass& __cdecl staticClass();

    float getScale() const;
    void setScale(float inVal);

    static void* __cdecl operator new(size_t nbytes);
    static void __cdecl operator delete(void* p);
    static void* __cdecl operator new(size_t n, void* p);
    static void* __cdecl operator new[](size_t n, void* p);
    static void __cdecl operator delete(void* p, void* place);
    static void __cdecl operator delete[](void* p, void* place);
};
