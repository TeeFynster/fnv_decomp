#pragma once

#include "hkArray.h"

class hkStringBuf
{
public:
    hkArray<char, hkContainerTempAllocator> m_string;
    unsigned int m_storage[32];

    enum ReplaceType
    {
        REPLACE_ONE,
        REPLACE_ALL
    };

    hkStringBuf() throw();
    ~hkStringBuf() throw();

    void InitBuffer() throw();
    __declspec(noinline) void UpdateFields_00cbbd40() throw();
    void FUN_00d61c10(const char* pcString) throw();

    int indexOf(const char* needle, int start, int end) const throw();
    int indexOf(char c, int start, int end) const;
    int lastIndexOf(char c, int start, int end) const;
    int startsWithCase(const char* other) const;
    void pathBasename();
    int replace(char from, char to, ReplaceType replaceType);
    void lowerCase();
    void upperCase();
    void appendJoin(const char* a, const char* b = 0, const char* c = 0,
                    const char* d = 0, const char* e = 0, const char* f = 0) throw();
    void set(const char* src, int len);
    int split(int c, hkArray<const char*, hkContainerTempAllocator>& bits);
    void chompStart(int n);
    void chompEnd(int n);
    void slice(int offset, int length);
    hkStringBuf& operator=(const char* s);
    hkStringBuf& operator+=(const char* s) throw();

    int getLength() const { return m_string.m_iElementCount - 1; }
    int getCapacity() const { return m_string.getCapacity(); }
    const char* cString() const { return m_string.m_data; }
    void setEmpty() { m_string.m_data[0] = 0; }
    __forceinline void SetSizeAndGrow(int n);
    __forceinline void setLength(int n);
};
