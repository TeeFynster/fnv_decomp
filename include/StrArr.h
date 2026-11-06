#pragma once

class Map;

struct StrArr
{
public:
    void* vtable;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    StrArr(unsigned int uiMaxSize, unsigned int uiGrowBy);

    void SetSize(unsigned int size);
    void FUN_00c4c920(unsigned int size);
    void SetAt(unsigned int index, char*& element);
    void SetAt(unsigned int index, char* const& element);
    void SetAt(unsigned int index, char** element);
    void SetAt(unsigned int index, Map*& element);
    void SetAtInline(unsigned int index, char* element);
    unsigned int SetAtGrow(unsigned int index, char*& element);

    unsigned int Add(char*& element);
    unsigned int Add(char* const& element);
    unsigned int Add(char* element);
    unsigned int AddInline(char* element);
    void AddFirstEmpty(char*& element);
    void AddFirstEmpty(const unsigned int& element);
    void append(char*& element);
    void append(char* const& element);
    void Append(char*& element);
    void Append(char* element);
    void AppendInline(char* element);
    void AppendReference(char*& element);

    unsigned int GetSize();
    unsigned short GetSize() const;
    unsigned short GetAlloc() const;
    unsigned short GetAllocatedSize() const;
    unsigned short GetMaxSize() const;
    unsigned short GetGrow() const;
    unsigned short GetGrowBy() const;
    unsigned short GetGrowSize() const;
};
