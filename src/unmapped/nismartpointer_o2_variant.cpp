
// src/unmapped/nismartpointer_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/unmapped/nismartpointer.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Elem
{
    char data[0x68];
};

Elem* AllocElems(unsigned int count);

struct Heap
{
    void* Allocate(unsigned int size);
};
extern Heap g_heap_11f6238;

struct Block
{
    Elem* m_items;
    unsigned int m_uiItemCount;
    Block* m_next;

    Block(unsigned int count)
    {
        m_uiItemCount = count;
        m_next = 0;
        if (count > 0)
            m_items = AllocElems(count);
        else
            m_items = 0;
    }
    Elem* GetAt(unsigned int i)
    {
        return i >= m_uiItemCount ? 0 : &m_items[i];
    }
};

inline void* operator new(unsigned int, void* p)
{
    return p;
}

struct ElemPtrArray
{
    Elem** m_data;
    unsigned int m_pRayCursor;
    unsigned int m_iElementCount;
    Block* m_kBlocks;

    void SetCapacity(unsigned int cap);
    void Add(Elem* e)
    {
        if (m_iElementCount == m_pRayCursor)
            SetCapacity(m_pRayCursor > 0 ? m_pRayCursor * 2 : 1);
        m_data[m_iElementCount] = e;
        ++m_iElementCount;
    }
    void NiTPool_NiD3DPass_CreateNewObjects(unsigned int count);
};

// @fnv 0x00e80420
// src: COMMUNITY 0x00e80420
void ElemPtrArray::NiTPool_NiD3DPass_CreateNewObjects(unsigned int count)
{
    void* mem = g_heap_11f6238.Allocate(sizeof(Block));
    Block* blk = mem ? new (mem) Block(count) : 0;
    for (unsigned int i = 0; i < count; ++i)
        Add(blk->GetAt(i));
    blk->m_next = m_kBlocks;
    m_kBlocks = blk;
}
