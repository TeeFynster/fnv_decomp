
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void* __cdecl _NiMalloc_00aa1070(unsigned int size);

class FUN_00a8f010_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    char* m_50;
    char* m_54;
    char* m_58;
    char* m_5C;

    void AllocateBuffers(int a1, int a2, int a3);
};

// Allocates one block sized from a1, a2 and a3, then sets m_50..m_5C to offsets within it.
// @fnv 0x00a8f010
void FUN_00a8f010_cls::AllocateBuffers(int aiCount, volatile int aiRows, int aiStride)
{
    unsigned int stride = (unsigned int)(aiStride + 3) & 0xfffffffcu;
    int rows = aiRows * (int)stride;
    unsigned int total = (unsigned int)(rows + aiCount * 12 + 4);
    char* base = (char*)_NiMalloc_00aa1070(total);
    m_50 = base;
    m_54 = base + rows;
    m_58 = m_54 + aiCount * 4;
    m_5C = m_58 + aiCount * 4;
}
