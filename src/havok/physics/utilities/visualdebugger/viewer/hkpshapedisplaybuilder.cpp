// src/havok/physics/utilities/visualdebugger/viewer/hkpshapedisplaybuilder.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/hkpshapedisplaybuilder.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00ddfcd0_Allocator
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int nbytes);
};

struct S_00ddfcd0_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00ddfcd0_Allocator* m_pStreamAllocator;
    S_00ddfcd0_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

S_00ddfcd0_Router* hkMemoryRouter_getInstance();

struct S_00ddfcd0_RefObj
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    S_00ddfcd0_RefObj() throw()
    {
        m_sReferenceCount = 1;
    }
    virtual ~S_00ddfcd0_RefObj() throw()
    {}
    void* operator new(unsigned int nbytes)
    {
        S_00ddfcd0_RefObj* b = static_cast<S_00ddfcd0_RefObj*>(hkMemoryRouter_getInstance()->heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    void operator delete(void*)
    {}
};

struct S_00ddfcd0_Array
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S_00ddfcd0_Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

struct S_00ddfcd0_Obj : S_00ddfcd0_RefObj
{
    S_00ddfcd0_Array m_ppData;
    S_00ddfcd0_Obj() throw()
    {}
    virtual ~S_00ddfcd0_Obj() throw();
};

// Allocates and constructs a new S_00ddfcd0_Obj through the router's heap and returns it as a S_00ddfcd0_RefObj pointer.
// @fnv 0x00ddfcd0
// src: XBOX_PDB 0x00ddfcd0
S_00ddfcd0_RefObj* hkpUserShapeDisplayBuildercreate()
{
    return new S_00ddfcd0_Obj;
}

struct HkArrayRaw
{
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapFlags;
};

struct HkArrayPairBlock
{
    HkArrayRaw m_arrA;
    HkArrayRaw m_arrB;
};

struct HkAllocator
{
    virtual void v00();
    virtual void* Alloc(unsigned int cb);
};

struct HkAllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    HkAllocator* m_pAllocator;
};

struct HkDisplayConvexObj
{
    int unk00;
    unsigned short m_u04;
    unsigned short unk06;

    HkDisplayConvexObj* FUN_00de1d20(HkArrayPairBlock* a1);
};

void __cdecl FUN_00c90940(HkAllocator* a1, HkArrayRaw* a2, int a3);

struct FUN_00ddfc30_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    HkDisplayConvexObj* m_pConvex;

    HkDisplayConvexObj* hkpShapeDisplayBuilder_getCurrentRawGeometry(HkArrayRaw* a1);
};

// If m_pConvex is null, allocates a pair block and a 0x60-byte object, stores it in m_pConvex and appends it to a1's array; returns m_pConvex.
// @fnv 0x00ddfc30
// src: HAVOK_LIB 0x00ddfc30
HkDisplayConvexObj* FUN_00ddfc30_cls::hkpShapeDisplayBuilder_getCurrentRawGeometry(HkArrayRaw* apArray)
{
    int zero = 0;
    if (m_pConvex == (HkDisplayConvexObj*)zero)
    {
        HkArrayPairBlock* pBlock = (HkArrayPairBlock*)zero;
        HkAllocHolder* pHolder = (HkAllocHolder*)hkMemoryRouter_getInstance();
        void* mem = pHolder->m_pAllocator->Alloc(0x18);
        if (mem != (void*)zero)
        {
            HkArrayPairBlock* p = (HkArrayPairBlock*)mem;
            *(void* volatile*)&p->m_arrA.m_pData = (void*)zero;
            *(volatile int*)&p->m_arrA.m_iArrayLength = zero;
            unsigned int uiFlags = 0x80000000u;
            *(volatile unsigned int*)&p->m_arrA.m_uCapFlags = uiFlags;
            *(void* volatile*)&p->m_arrB.m_pData = (void*)zero;
            *(volatile int*)&p->m_arrB.m_iArrayLength = zero;
            p->m_arrB.m_uCapFlags = uiFlags;
            pBlock = p;
        }

        pHolder = (HkAllocHolder*)hkMemoryRouter_getInstance();
        mem = pHolder->m_pAllocator->Alloc(0x60);
        ((HkDisplayConvexObj*)mem)->m_u04 = 0x60;
        m_pConvex = ((HkDisplayConvexObj*)mem)->FUN_00de1d20(pBlock);

        pHolder = (HkAllocHolder*)hkMemoryRouter_getInstance();
        if (apArray->m_iArrayLength == (int)(apArray->m_uCapFlags & 0x3fffffffu))
        {
            FUN_00c90940(pHolder->m_pAllocator, apArray, 4);
        }
        int idx = apArray->m_iArrayLength;
        HkDisplayConvexObj** pArrayData = (HkDisplayConvexObj**)apArray->m_pData;
        HkDisplayConvexObj** slot = pArrayData + idx;
        *slot = *(HkDisplayConvexObj* volatile*)&m_pConvex;
        apArray->m_iArrayLength++;
    }
    return m_pConvex;
}
