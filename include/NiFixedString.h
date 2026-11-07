#pragma once
#include <stddef.h>
#include "NiGlobalStringTable.h"

class FixedStringHeader;

class NiFixedString
{
  public:
    char* m_kHandle;

    NiFixedString();
    NiFixedString(const char* text);
    NiFixedString(char* text);
    NiFixedString(char* const& text);
    NiFixedString(const char* handle, int);
    NiFixedString(unsigned int value);
    NiFixedString(const NiFixedString& text);
    __declspec(nothrow) ~NiFixedString();

    NiFixedString& operator=(const char* text);
    NiFixedString& operator=(char* const& text);
    NiFixedString& operator=(const NiFixedString& text);
    operator const char*() const;
    operator const void*() const;
    bool operator==(const char* text) const;
    bool operator==(const NiFixedString& text) const;
    bool operator!=(const NiFixedString& text) const;

    bool Exists();
    bool Exists() const;
    int IsNotEmpty() const;
    unsigned int GetLength();
    unsigned int GetRefCount();
    bool Equals(char* text);
    bool EqualsNoCase(char* text);
    bool Contains(char* text);
    bool HasSuffix(char* text);
    unsigned int QHandle();
    void Init();
    void Assign(const char* text);
    void Clear();
    void Release();
    __declspec(noalias) void AssignInternedString(const NiFixedString& text);
    void* FUN_004b9900(unsigned int flags);
    void FUN_00761760(int* data, unsigned int count);
#if !defined(_MSC_VER)
    void* __vecDelDtor(unsigned int flags);
#endif

    static FixedStringHeader* Header(const char* text);
    static void* operator new(size_t size);
    static void operator delete(void* memory);
    static void operator delete(void* memory, size_t size);
};

#ifndef FNV64_NIFIXEDSTRING_OWN_BODIES
inline NiFixedString::NiFixedString()
{
    m_kHandle = NiGlobalStringTable::ms_pcEmptyString;
}

inline NiFixedString::NiFixedString(const char* pcString)
{
    if (pcString == 0)
        m_kHandle = NiGlobalStringTable::ms_pcEmptyString;
    else
        m_kHandle = NiGlobalStringTable::AddString(pcString);
}

inline NiFixedString::NiFixedString(const char* handle, int)
{
    m_kHandle = const_cast<char*>(handle);
}

inline NiFixedString::NiFixedString(const NiFixedString& kString)
{
    NiGlobalStringTable::IncRefCount(const_cast<GlobalStringHandle&>(kString.m_kHandle));
    m_kHandle = kString.m_kHandle;
}

inline NiFixedString::~NiFixedString()
{
    NiGlobalStringTable::DecRefCount(m_kHandle);
}
#else
// The constructors and the destructor are declared in the class above.
#endif
