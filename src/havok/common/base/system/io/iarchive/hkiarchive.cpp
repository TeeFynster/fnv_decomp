
// src/havok/common/base/system/io/iarchive/hkiarchive.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/iarchive/hkiarchive.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkReferencedObject.h"

struct FUN_00dd9110_class
{
    int m_iWordAt00;
    int m_cByteAtOffset1;
    hkReferencedObject* m_cByteAtOffset2;
    void SetReferencedObject(hkReferencedObject* p);
};

// @fnv 0x00dd9110
void FUN_00dd9110_class::SetReferencedObject(hkReferencedObject* apObject)
{
    apObject->addReference();
    m_cByteAtOffset2->removeReference();
    m_cByteAtOffset2 = apObject;
}

int DAT_010d7c80;

struct FUN_00dd9130_class
{
    FUN_00dd9130_class* Init(hkReferencedObject* p, bool b);
};

// Stores the vtable pointer, reference object and bool flag into this, then calls the object's method and returns this.
// @fnv 0x00dd9130
FUN_00dd9130_class* FUN_00dd9130_class::Init(hkReferencedObject* apObject, bool abFlag)
{
    *(unsigned short*)((char*)this + 6) = 1;
    *(int**)this = &DAT_010d7c80;
    *(hkReferencedObject**)((char*)this + 8) = apObject;
    *(bool*)((char*)this + 12) = abFlag;
    apObject->addReference();
    return this;
}

struct Inner
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void Tail(int a);
};

struct FUN_00dd90d0_cls
{
    int unk00;
    int unk04;
    Inner* m_08;
    void ForwardCall_00dd90d0(int a);
};

// @fnv 0x00dd90d0
// src: GUESS 0x00dd90d0 (confidence: low)
void FUN_00dd90d0_cls::ForwardCall_00dd90d0(int a)
{
    m_08->Tail(a);
}

// The result at 0x00dd90e0 uses an aggregate return pointer; shared hkResult is an enum returned in EAX.
struct ArchiveStreamResult
{
    int m_pClassEnum;
    ArchiveStreamResult(int e)
    {
        m_pClassEnum = e;
    }
};

class hkStreamDD90
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual ArchiveStreamResult getResult();
};

class hkWrapperDD90
{
  public:
    int unk00;
    int unk04;
    hkStreamDD90* m_stream;

    ArchiveStreamResult GetStreamResult();
};

// @fnv 0x00dd90e0
ArchiveStreamResult hkWrapperDD90::GetStreamResult()
{
    return m_stream->getResult();
}

struct FnvCpu_FUN_00dd9100_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    int value;
    int GetValue_00dd9100();
};
// @fnv 0x00dd9100
// src: GUESS 0x00dd9100 (confidence: high)
int FnvCpu_FUN_00dd9100_CpuObject::GetValue_00dd9100()
{
    return value;
}

struct DD8FE0_Writer
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Write(void* buffer, int bytes);
};
struct DD8FE0_Stream
{
    int m_00;
    int m_04;
    DD8FE0_Writer* m_pStreamWriter;
    unsigned char m_swapByteOrder;
    void hkIArchive_readArrayGeneric(void* data, int itemSize, int itemCount);
};
static __forceinline void swapByte(unsigned char& low, unsigned char& high)
{
    unsigned char temp = low;
    low = high;
    high = temp;
}
// Writes itemSize*itemCount bytes to the stream writer, then swaps byte order in-place for 2, 4, or 8-byte items when m_swapByteOrder is set.
// @fnv 0x00dd8fe0
// src: HAVOK_LIB 0x00dd8fe0
void DD8FE0_Stream::hkIArchive_readArrayGeneric(void* data, int itemSize, int itemCount)
{
    m_pStreamWriter->Write(data, itemSize * itemCount);
    if (m_swapByteOrder)
    {
        unsigned char* buffer = static_cast<unsigned char*>(data);
        switch (itemSize)
        {
        case 2:
            if (itemCount > 0)
                do
                {
                    swapByte(buffer[0], buffer[1]);
                    buffer += 2;
                } while (--itemCount);
            break;
        case 4:
            if (itemCount > 0)
            {
                unsigned char* p = buffer + 2;
                do
                {
                    swapByte(p[-2], p[1]);
                    swapByte(p[-1], p[0]);
                    p += 4;
                } while (--itemCount);
            }
            break;
        case 8:
            if (itemCount > 0)
            {
                unsigned char* p = buffer + 6;
                do
                {
                    swapByte(p[-6], p[1]);
                    swapByte(p[-5], p[0]);
                    swapByte(p[-4], p[-1]);
                    swapByte(p[-3], p[-2]);
                    p += 8;
                } while (--itemCount);
            }
            break;
        }
    }
}
