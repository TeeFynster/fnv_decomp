#pragma once

class NiTMapItemStub;

class NiTMapBaseStub
{
public:
    void* vtbl;
    union
    {
        int unk4;
        unsigned int m_uiHashSize;
    };
    union
    {
        void* unk8;
        NiTMapItemStub** m_ppkHashTable;
    };

    NiTMapBaseStub(unsigned int uiHashSize = 37);
    ~NiTMapBaseStub();
    unsigned int KeyToHashIndex(int key) const;
    void RemoveAll();
    void __thiscall FUN_00b580a0();
    void* __thiscall DestroyAndFree(unsigned int);
};
