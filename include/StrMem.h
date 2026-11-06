#pragma once

class StrMem
{
public:
    char* text;
    unsigned short length;
    unsigned short capacity;

    StrMem();
    StrMem(unsigned int v);
    StrMem(const char* s);
    ~StrMem();

    bool Set(const char* source, unsigned int requested);
    void SetLength(unsigned int n);
    void SetCapacity(unsigned int n);
    void SetMaxLength(unsigned int n);
    unsigned int MaxLength();
    unsigned int MaxLength() const;
    void Init();
    void Clear();
    const char* String() const;
    unsigned int Length() const;
    char* GetText() const;
    unsigned int GetLength() const;
    operator const char*() const;
    StrMem& operator+=(const char*);

    StrMem& FUN_00404820(const char*);
    unsigned int FUN_004048e0();
    char* FUN_00559450();
    const char* FUN_00559450() const;
    void __thiscall FUN_006ffe10();
};
