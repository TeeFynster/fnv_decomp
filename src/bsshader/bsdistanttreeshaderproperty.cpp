
// src/bsshader/bsdistanttreeshaderproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/bsdistanttreeshaderproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00462d80_shell
{
    unsigned int __thiscall InvokeAndAccumulate(void* pvBuffer, unsigned int uiBytes, unsigned int* uiBytesRead,
                                                unsigned int uiSize);
    unsigned int __thiscall ReadBytes(void* pvBuffer, unsigned int uiBytes);
};

// Reads uiBytes into pvBuffer via InvokeAndAccumulate and returns the number of bytes read.
// @fnv 0x00462d80
unsigned int __thiscall FUN_00462d80_shell::ReadBytes(void* pvBuffer, unsigned int uiBytes)
{
    unsigned int uiSize = 1;
    unsigned int uiBytesRead = InvokeAndAccumulate(pvBuffer, uiBytes, &uiSize, 1);
    return uiBytesRead;
}

struct Elem006fa0d0
{
    unsigned char data[32];
    void FUN_006fa0d0(int);
};
struct Holder006fa090
{
    void ProcessEntries_006fa090(Elem006fa0d0*, unsigned int);
};
// Calls FUN_006fa0d0(0) on each of the n elements of the array pointed to by p.
// @fnv 0x006fa090
// src: GUESS 0x006fa090 (confidence: low)
void Holder006fa090::ProcessEntries_006fa090(Elem006fa0d0* apElements, unsigned int n)
{
    for (unsigned int i = 0; i < n; ++i)
        apElements[i].FUN_006fa0d0(0);
}
