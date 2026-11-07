
// src/havok/physics/collide/query/collector/bodypaircollector/hkpallcdbodypaircollector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/collector/bodypaircollector/hkpallcdbodypaircollector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct HkHolder;
HkHolder* hkMemoryRouter_getInstance();
void ResizeAudioStream(void* allocator, void* list, unsigned int elemSize);

struct HkHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pAllocator;
};

// Exe 0x00cb7550: unit-local ListNode view; declarations and layout are preserved.
struct HkpallcdbodypaircollectorListNodeView
{
    int unk00;
    int m_04;
    int unk08;
    HkpallcdbodypaircollectorListNodeView* m_0C;
};

struct TailPair
{
    HkpallcdbodypaircollectorListNodeView* m_firstTail;
    int m_firstVal;
    HkpallcdbodypaircollectorListNodeView* m_secondTail;
    int m_secondVal;
};

struct TailPairArray
{
    TailPair* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapFlags;
};

struct FUN_00cb7550_cls
{
    int unk00;
    int unk04;
    TailPairArray m_08;

    void AppendTailPair(HkpallcdbodypaircollectorListNodeView* a, HkpallcdbodypaircollectorListNodeView* b);
};

// Grows the TailPairArray if full, then appends a slot holding the tail node and value of each of the two lists.
// @fnv 0x00cb7550
void FUN_00cb7550_cls::AppendTailPair(HkpallcdbodypaircollectorListNodeView* a, HkpallcdbodypaircollectorListNodeView* b)
{
    TailPairArray* list = &m_08;
    HkHolder* holder = reinterpret_cast<HkHolder*>(hkMemoryRouter_getInstance());
    if (list->m_iArrayLength == (int)(list->m_uCapFlags & 0x3fffffffu))
    {
        ResizeAudioStream(holder->m_pAllocator, list, 0x10);
    }
    TailPair* slot = list->m_pData + list->m_iArrayLength;
    list->m_iArrayLength++;

    HkpallcdbodypaircollectorListNodeView* tailA = a;
    while (tailA->m_0C != 0)
    {
        tailA = tailA->m_0C;
    }
    slot->m_firstTail = tailA;
    slot->m_firstVal = a->m_04;

    HkpallcdbodypaircollectorListNodeView* tailB = b;
    while (tailB->m_0C != 0)
    {
        tailB = tailB->m_0C;
    }
    slot->m_secondTail = tailB;
    slot->m_secondVal = b->m_04;
}
