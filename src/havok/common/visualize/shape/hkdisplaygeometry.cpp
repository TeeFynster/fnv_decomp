
// src/havok/common/visualize/shape/hkdisplaygeometry.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/shape/hkdisplaygeometry.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00da2560_Alloc
{
    virtual ~S_00da2560_Alloc();
    virtual void* AllocateMemoryBlock(int n);
    virtual void ReleaseBlock(void* p, int n);
};
struct S_00da2560_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00da2560_Alloc* m_pStreamAllocator;
    S_00da2560_Alloc& heap()
    {
        return *m_pStreamAllocator;
    }
};
S_00da2560_Router* hkMemoryRouter_getInstance();

struct S_00da2560_Member
{
    ~S_00da2560_Member() throw()
    {
        FUN_00cce530();
    }
    void FUN_00cce530() throw();
    void operator delete(void* p)
    {
        hkMemoryRouter_getInstance()->heap().ReleaseBlock(p, 0x18);
    }
};

struct S_00da2560_Base
{
    int unk4;
    virtual ~S_00da2560_Base() throw()
    {}
};

struct FUN_00da2560 : S_00da2560_Base
{
    S_00da2560_Member* m_8;
    virtual ~FUN_00da2560() throw();
};

// Destructor deletes the m_8 member object and clears the pointer.
// @fnv 0x00da2560
FUN_00da2560::~FUN_00da2560() throw()
{
    if (m_8)
    {
        delete m_8;
        m_8 = 0;
    }
}
