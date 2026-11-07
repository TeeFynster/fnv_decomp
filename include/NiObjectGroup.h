#pragma once

class NiObjectGroup
{
public:
    unsigned int m_uiSize;
    void* pvContextData;
    void* m_pBeforeRefCount;
    unsigned int m_uiRefCount;

    void ForwardCall_00a8a670();
    void* Allocate(unsigned int);
    void DecRefCount();
    void SetSize(unsigned int);
    unsigned int GetSize();
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
};
