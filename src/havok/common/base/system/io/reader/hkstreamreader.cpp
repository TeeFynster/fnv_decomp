
// src/havok/common/base/system/io/reader/hkstreamreader.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/reader/hkstreamreader.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct VersionedDataBlock
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual int Read(void* destination, int size);
    int ReadBytes(int size);
};
// Reads up to size bytes in chunks of at most 512 into a local buffer, stopping on a zero-length read, and returns the number of bytes read.
// @fnv 0x00cb14f0
int VersionedDataBlock::ReadBytes(int size)
{
    unsigned int buffer[128];
    int remaining = size;
    while (remaining)
    {
        int count = Read(buffer, remaining > 512 ? 512 : remaining);
        if (!count)
            break;
        remaining -= count;
    }
    return size - remaining;
}

class Stream
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual int Read(void* buf, int n);
    int ReadChar();
};

// @fnv 0x00cb1550
int Stream::ReadChar()
{
    char c;
    if (Read(&c, 1))
        return c;
    return -1;
}

struct S_00cb1570
{
    int ReturnOne(void* pArg);
};
// @fnv 0x00cb1570
// src: GUESS 0x00cb1570 (confidence: high)
int S_00cb1570::ReturnOne(void* pArg)
{
    return 1;
}

// @fnv 0x00cb1580
// src: GUESS 0x00cb1580 (confidence: high)
int __cdecl Object_ReturnOne()
{
    return 1;
}

// @fnv 0x00cb15c0
// src: HAVOK_SRC 0x00cb15c0
void __stdcall hkStreamReader_seekTellSupported(char* p)
{
    *p = 0;
}

struct CB1590Object
{
    virtual int ReturnOne(const void* a, const void* b) const;
};

// @fnv 0x00cb1590
// src: GUESS 0x00cb1590 (confidence: high)
int CB1590Object::ReturnOne(const void* a, const void* b) const
{
    return 1;
}

struct CB15B0Bool
{
    char m_cBooleanValue;

    CB15B0Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

struct CB15B0Object
{
    virtual CB15B0Bool hkStreamReader_markSupported() const;
};

// @fnv 0x00cb15b0
// src: HAVOK_SRC 0x00cb15b0
CB15B0Bool CB15B0Object::hkStreamReader_markSupported() const
{
    return false;
}

// @fnv 0x00cb15a0
// src: HAVOK_SRC 0x00cb15a0
int hkStreamReader_tell()
{
    return -1;
}
