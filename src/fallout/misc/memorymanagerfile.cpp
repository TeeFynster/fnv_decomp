
// src/fallout/misc/memorymanagerfile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/misc/memorymanagerfile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/MemoryManagerFile.h"
#include "../../../include/SeenData.h"

extern int DAT_01083b00;

struct FUN_00878430_shell
{
    int* m_ptr;
    void SetPtr();
};

// @fnv 0x00878430
// src: GUESS 0x00878430 (confidence: low)
void FUN_00878430_shell::SetPtr()
{
    m_ptr = &DAT_01083b00;
}

namespace fnv_008784b0 {
extern "C" void* DAT_01083b00;

struct FUN_008784b0
{
    void* m_p;
    FUN_008784b0();
};

// @fnv 0x008784b0
FUN_008784b0::FUN_008784b0()
{
    m_p = &DAT_01083b00;
}
}  // namespace fnv_008784b0

struct FUN_008799c0_shell
{
    SeenData mSeenData;  // +0x00
    bool __thiscall IsValueSeen(void* arg1, unsigned int arg2);
};

// Computes an offset from arg1 and arg2 and forwards it to mSeenData.IsBitSet, returning its result.
// @fnv 0x008799c0
bool FUN_008799c0_shell::IsValueSeen(void* pBase, unsigned int uiIndex)
{
    unsigned int nValue = (uiIndex << 4) + (unsigned int)pBase;
    return mSeenData.IsBitSet(nValue);
}

void* _Deallocate(void* p);

struct FUN_00878450_shell : FUN_00878430_shell
{
    void* __thiscall FUN_00878450(unsigned int flags);
};

// @fnv 0x00878450
void* __thiscall FUN_00878450_shell::FUN_00878450(unsigned int flags)
{
    SetPtr();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00878480_shell : FUN_00878450_shell
{
    void* __thiscall FUN_00878480(unsigned int flags);
    void __thiscall FUN_008784d0();
};
// Calls FUN_008784d0, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00878480
void* __thiscall FUN_00878480_shell::FUN_00878480(unsigned int flags)
{
    FUN_008784d0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FileSizeInfo
{
    void __thiscall SetFromCall(void* apData, unsigned __int64 aSize, unsigned __int64* apRead);
};
// Reads aSize bytes from the inner file into apData and returns the number of bytes read.
// @fnv 0x00878530
int __thiscall MemoryManagerFile::Read(void* apData, unsigned int aSize)
{
    unsigned __int64 uiBytesRead;
    reinterpret_cast<FileSizeInfo*>(reinterpret_cast<char*>(this) + 4)->SetFromCall(apData, aSize, &uiBytesRead);
    return (int)uiBytesRead;
}

namespace fnv_00878560 {
typedef unsigned __int64 uint64;
struct FileInner
{
    void __thiscall SetAndReturnPointer(const void*, uint64, uint64*);
};
}  // namespace fnv_00878560
// Writes aSize bytes from apData through the inner file object and returns the number of bytes written.
// @fnv 0x00878560
int MemoryManagerFile::Write(const void* apData, unsigned int aSize)
{
    fnv_00878560::uint64 uiwritten;
    reinterpret_cast<fnv_00878560::FileInner*>(reinterpret_cast<char*>(this) + 4)->SetAndReturnPointer(apData, aSize, &uiwritten);
    return (int)uiwritten;
}

namespace fnv_00878590 {
struct FileSizeInfo
{
    int __thiscall BSSystemFile_GetSize(unsigned __int64&);
};
// Retained until MemoryManagerFile declares the size method at 0x00878590.
struct FUN_00878590_shell : FileSizeInfo
{
    int __thiscall MemoryManagerFile_Size();
};
// @fnv 0x00878590
// src: XBOX_PDB 0x00878590
int __thiscall FUN_00878590_shell::MemoryManagerFile_Size()
{
    unsigned __int64 size;
    ((FileSizeInfo*)((char*)this + 4))->BSSystemFile_GetSize(size);
    return (int)size;
}
}  // namespace fnv_00878590

namespace fnv_008785b0 {
typedef unsigned __int64 uint64;
struct FUN_008785e0_holder
{
    void __thiscall SetAndGetField0(__int64, int, uint64*);
};
}  // namespace fnv_008785b0
// @fnv 0x008785b0
void __thiscall MemoryManagerFile::vf04(int aiPos)
{
    fnv_008785b0::uint64 uipos;
    reinterpret_cast<fnv_008785b0::FUN_008785e0_holder*>(reinterpret_cast<char*>(this) + 4)->SetAndGetField0(aiPos, 0, &uipos);
}

class FUN_00b00950
{
  public:
    ~FUN_00b00950();

    int unk00;
};

class FUN_00878430
{
  public:
    virtual ~FUN_00878430();
};

// Retained until MemoryManagerFile declares its virtual destructor and inner file.
class FUN_008784d0 : public FUN_00878430
{
  public:
    FUN_00b00950 m_04;

    virtual ~FUN_008784d0();
};

// @fnv 0x008784d0
FUN_008784d0::~FUN_008784d0()
{}
