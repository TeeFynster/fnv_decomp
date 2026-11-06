#pragma once

class CA0E60Array
{
public:
    unsigned int unk00;
    void** m_pBuffer;
    unsigned int m_uiSize;
    unsigned int m_uiCapacity;

    ~CA0E60Array();
    void** Allocate(unsigned int ItemUpdateArray);
    void Free(void** pBuffer);
    void Reallocate(unsigned int uiNewAlloc, unsigned int uiCopyCount);
    void SetSize(unsigned int uiSize);
    void CopyTo(CA0E60Array& kDest) const;
};
