#pragma once

#include <cstddef>
#include "FinishingFlag.h"

class hkStringPtr
{
public:
    const char* m_pcText;

#if defined(HKSTRINGPTR_THROWING_DEFAULT_CONSTRUCTOR)
    hkStringPtr();
#else
    hkStringPtr() throw();
#endif
    explicit hkStringPtr(FinishingFlag flag) throw();
    ~hkStringPtr() throw();

    void operator=(const char* text) throw();
    const char* cString() const;
    void Init();
    void release();
    void Assign(const char* text);
    void CopyFrom(const hkStringPtr* text);
    void printf(const char* fmt, ...);

    void FUN_00cb0a60();
    void Object_UpdateFields_00cb0c00();
    void UpdateState_00cb0c30(const hkStringPtr* text);
    void printf_00cb0c70(const char* fmt, ...);

    static void* __cdecl operator new(std::size_t nbytes);
};
