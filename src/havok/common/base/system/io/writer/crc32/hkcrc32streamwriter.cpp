
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" unsigned int __cdecl Crc32ShiftRight8(unsigned int);
struct StateObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int state;
    int hkCrc32StreamWriter_write(unsigned char* bytes, int length);
};
// Updates state by folding each byte of bytes into it through Crc32ShiftRight8, then stores the result in state and returns length.
// @fnv 0x00db7810
// src: HAVOK_LIB 0x00db7810
int StateObject::hkCrc32StreamWriter_write(unsigned char* bytes, int length)
{
    unsigned int current = state;
    for (int i = 0; i < length; ++i)
    {
        unsigned int value = Crc32ShiftRight8((bytes[i] ^ current) & 0xffu);
        current = (current >> 8) ^ value;
    }
    state = current;
    return length;
}

struct TargetClass
{
    char pad00[8];
    int m_val;

    int ComputeValue_00db7860();
};

// @fnv 0x00db7860
// src: GUESS 0x00db7860 (confidence: low)
int TargetClass::ComputeValue_00db7860()
{
    return ~m_val;
}

// FUN_00db7870 : constructor taking one argument. Installs the class vtable,
// sets a 16-bit flag to 1 and stores the bitwise complement of the argument.

extern int DAT_010d538c;

struct FUN_00db7870_cls
{
    void* m_pVTable;
    unsigned short m_w04;
    unsigned short m_w06;
    unsigned int m_dw08;

    FUN_00db7870_cls(unsigned int value);
};

// @fnv 0x00db7870
FUN_00db7870_cls::FUN_00db7870_cls(unsigned int value)
{
    m_w06 = 1;
    m_pVTable = (void*)&DAT_010d538c;
    m_dw08 = ~value;
}

// Sets the one-byte flag at *p to 1 (true) and returns nothing.
// @fnv 0x00db7890
// src: HAVOK_SRC 0x00db7890
void __stdcall hkCrc32StreamWriter_isOk(void* p)
{
    *(unsigned char*)p = 1;
}
