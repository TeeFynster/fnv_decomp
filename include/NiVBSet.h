#pragma once

class NiVBBlock;
class VbNode;

class NiVBSetBlockArray
{
public:
    unsigned int unk00;
    NiVBBlock** m_pData;

    void FUN_00a93c50(unsigned int);
};

class NiVBSet
{
public:
    unsigned int m_uiPosition;
    char _04[8];
    unsigned int m_uiIndexCapacity;
    char _10[12];
    NiVBSetBlockArray m_kBlockArray;

    NiVBSet();
    ~NiVBSet();

    void Create(unsigned int key, void* val);
    void Create(unsigned int key, unsigned int val);
    VbNode* NiVBSet_AllocateChip(unsigned int size, bool flag);
    void RemoveNode(NiVBBlock*);
    void NiVBSet_FreeBlock(NiVBBlock*);
    void FreeChip(unsigned int uiArrayIndex, unsigned int uiChipIndex);
};
