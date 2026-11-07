// src/havok/physics/internal/collide/convexpiecemesh/hkpconvexpiecestreamdataclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/convexpiecemesh/hkpconvexpiecestreamdataclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Record;
struct Manager
{
    virtual void unk00();
    virtual void unk04();
    virtual void Notify(Record* record, unsigned short value);
};
struct Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Manager* manager;
};
Holder* hkMemoryRouter_getInstance();
struct Record
{
    int unk00;
    unsigned short value;
    void DestroyFields_00dffca0();
    Record* FUN_00dffd50(unsigned int flags);
};
// Calls FUN_00dffca0, and if flags has bit 0 set, notifies the manager from FUN_00c85750 with this record and value; returns this.
// @fnv 0x00dffd50
Record* Record::FUN_00dffd50(unsigned int flags)
{
    DestroyFields_00dffca0();
    if (flags & 1)
    {
        Holder* holder = hkMemoryRouter_getInstance();
        holder->manager->Notify(this, value);
    }
    return this;
}

struct BufAllocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void Free(void* ptr, unsigned int size);
};

struct OwnedBuffer
{
    void* ptr;
    unsigned int unk04;
    unsigned int flags;
};

struct BufferOwnerBase
{
    virtual ~BufferOwnerBase()
    {}
};

struct FUN_00dffca0_cls : BufferOwnerBase
{
    unsigned int unk04;
    OwnedBuffer m_buf0;
    OwnedBuffer m_buf1;
    OwnedBuffer m_buf2;

    void DestroyFields_00dffca0();
};

static void ReleaseOwnedBuffer(OwnedBuffer& buf)
{
    Holder* holder = hkMemoryRouter_getInstance();
    BufAllocator* allocator = reinterpret_cast<BufAllocator*>(holder->manager);
    unsigned int flags = buf.flags;
    buf.unk04 = 0;
    if ((flags & 0x80000000u) == 0)
    {
        allocator->Free(buf.ptr, (flags & 0x3fffffffu) * 4);
    }
    buf.ptr = 0;
    buf.flags = 0x80000000u;
}

// Releases the three owned buffers and then calls the base class destructor.
// @fnv 0x00dffca0
// src: GUESS 0x00dffca0 (confidence: medium)
void FUN_00dffca0_cls::DestroyFields_00dffca0()
{
    ReleaseOwnedBuffer(m_buf2);
    ReleaseOwnedBuffer(m_buf1);
    ReleaseOwnedBuffer(m_buf0);
    this->BufferOwnerBase::~BufferOwnerBase();
}
