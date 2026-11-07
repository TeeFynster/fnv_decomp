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
    unsigned int BSStringT_char_Length();
    char* Modelloader_GetReferencedThis();
    const char* Modelloader_GetReferencedThis() const;
    void __thiscall AnimatingText_Initialize();
};
