
// src/havok/common/base/system/io/socket/hksocket.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/socket/hksocket.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkReferencedObject.h"

struct S_00d2b790_Target
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C(void* pArg);
};
struct S_00d2b790
{
    int unk00;
    int unk04;
    S_00d2b790_Target* m_pFlagTarget;
    void* DispatchToTarget(void* pArg);
};
// @fnv 0x00d2b790
void* S_00d2b790::DispatchToTarget(void* pArg)
{
    m_pFlagTarget->v0C(pArg);
    return pArg;
}

struct Reader
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual int Read(int start, int length);
};

struct Owner
{
    unsigned char unk00[8];
    Reader* reader;
    int hkSocket_WriterAdapter_write(int start, int length);
};

// @fnv 0x00d2b7b0
// src: HAVOK_LIB 0x00d2b7b0
int Owner::hkSocket_WriterAdapter_write(int start, int length)
{
    int done = 0;
    if (length > 0)
    {
        while (done < length)
        {
            int amount = reader->Read(start + done, length - done);
            done += amount;
            if (amount == 0)
                return done;
        }
    }
    return length;
}

struct FUN_00da30a0_class
{
    int unk00;
    unsigned short unk04;
    void InitWithParam(int value);
};
struct FUN_00c85750_context
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    struct Allocator
    {
        virtual void first();
        virtual FUN_00da30a0_class* allocate(unsigned int);
    }* unk10;
};
FUN_00c85750_context* __cdecl hkMemoryRouter_getInstance();
// @fnv 0x00d2b820
void __cdecl CreateAllocatedValue()
{
    FUN_00c85750_context* context = hkMemoryRouter_getInstance();
    FUN_00da30a0_class* value = context->unk10->allocate(0x24);
    value->unk04 = 0x24;
    value->InitWithParam(-1);
}

// @fnv 0x00d2b8b0
// src: COMMUNITY 0x00d2b8b0
int __stdcall DllMain_12(int a, int b, int c)
{
    return 1;
}

namespace fnv_00d2b8c0 {
struct FUN_00d2b8c0_Class;
struct RetPart
{
    virtual void first();
    virtual void second();
    virtual void Release(FUN_00d2b8c0_Class* owner, unsigned int count);
};
struct UnkRet
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    RetPart* part10;
};
struct FUN_00d2b8c0_Class
{
    void* vptr00;
    unsigned short refCount;
    unsigned short unk06;
    void* vptr08;
    int unk0c;
    int unk10;
    void* vptr14;
    FUN_00d2b8c0_Class* FUN_00d2b8c0(unsigned int flags);
};
void* DAT_0102e388;
UnkRet* hkMemoryRouter_getInstance();
// @fnv 0x00d2b8c0
FUN_00d2b8c0_Class* FUN_00d2b8c0_Class::FUN_00d2b8c0(unsigned int flags)
{
    vptr14 = &DAT_0102e388;
    vptr08 = &DAT_0102e388;
    vptr00 = &DAT_0102e388;
    if (flags & 1)
    {
        UnkRet* object = hkMemoryRouter_getInstance();
        unsigned int count = refCount;
        RetPart* part = object->part10;
        part->Release(this, count);
    }
    return this;
}
}  // namespace fnv_00d2b8c0

struct StreamIface
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual int Read(char* buf, int size);
};

class FUN_00d2b740_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    StreamIface* m_pBinaryStream;

    int hkSocket_ReaderAdapter_read(char* buf, int size);
};

// @fnv 0x00d2b740
// src: HAVOK_LIB 0x00d2b740
int FUN_00d2b740_cls::hkSocket_ReaderAdapter_read(char* apBuffer, int size)
{
    int total = 0;
    if (size > 0)
    {
        do
        {
            int n = m_pBinaryStream->Read(apBuffer + total, size - total);
            total += n;
            if (n == 0)
            {
                return total;
            }
        } while (total < size);
    }
    return size;
}

struct FUN_00d2b800_cls;

struct NvdTarget
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(void* a);
};

struct FUN_00d2b800_cls
{
    char unk00[8];
    NvdTarget* m_08;

    void* ForwardToTarget(void* a1);
};

// @fnv 0x00d2b800
void* FUN_00d2b800_cls::ForwardToTarget(void* apArg)
{
    m_08->v3(apArg);
    return apArg;
}

typedef void(__cdecl* InitFuncD2B)();
extern "C" bool DAT_01268a44;
extern "C" InitFuncD2B DAT_011b3de8;



class FUN_00d2b850;

class PartAD2B : public hkReferencedObject
{
  public:
    PartAD2B() throw() : m_pOwnerObject(0)
    {}
    virtual ~PartAD2B() throw();

    FUN_00d2b850* m_pOwnerObject;
};

class PartBD2B : public hkReferencedObject
{
  public:
    PartBD2B() throw() : m_pOwnerObject(0)
    {}
    virtual ~PartBD2B() throw();

    FUN_00d2b850* m_pOwnerObject;
};

class FUN_00d2b850 : public hkReferencedObject
{
  public:
    FUN_00d2b850() throw();
    virtual ~FUN_00d2b850() throw();

    PartAD2B m_partA;
    PartBD2B m_partB;
};

// @fnv 0x00d2b850
FUN_00d2b850::FUN_00d2b850() throw()
{
    m_partA.m_pOwnerObject = this;
    m_partB.m_pOwnerObject = this;
    if (!DAT_01268a44 && DAT_011b3de8)
    {
        DAT_011b3de8();
        DAT_01268a44 = true;
    }
}
