#pragma once

class BSSystemUtilitiesStrings
{
public:
    char* m_pStringFunctions[8];

    virtual ~BSSystemUtilitiesStrings();
    virtual void Initialize();
    virtual void Destroy();

    void SetStringAt(unsigned int index, const char* str);
    void CallVTableMethod();
    void* DestroyIfFlagged(unsigned int flags);
    void SetVirtualTable_00af35c0();
};
