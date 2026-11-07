
// src/gamebryo2.2/corelibs/nisystem/nismallobjectallocator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nisystem/nismallobjectallocator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
struct SubAlloc
{
    char _0[0x18];
    int _18;
    char _1c[0x64];
    int FindEntryContaining(void*);
    int WriteBufferByte(void*);
};
struct PointerCountProcessor
{
    void NiSmallObjectAllocator_Deallocate(void*, unsigned int);
};
// @fnv 0x00aa3830
// src: COMMUNITY 0x00aa3830
void PointerCountProcessor::NiSmallObjectAllocator_Deallocate(void* p, unsigned int stNumBytes)
{
    SubAlloc* pAlloc = (SubAlloc*)((char*)this + (stNumBytes << 8) - 0x100);
    void* pCriticalSection = (char*)pAlloc + 0x80;
    EnterCriticalSection(pCriticalSection);
    int v = pAlloc->FindEntryContaining(p);
    pAlloc->_18 = v;
    pAlloc->WriteBufferByte(p);
    LeaveCriticalSection(pCriticalSection);
}

extern void(__stdcall* g_pfnEntryInit)(void*);

struct FUN_00aa3760_entry
{
    unsigned int unk00;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
};

struct FUN_00aa3760_cls
{
    FUN_00aa3760_entry m_entries[256];
    unsigned int m_10000;

    FUN_00aa3760_cls* InitEntries(unsigned int a1);
};

// @fnv 0x00aa3760
FUN_00aa3760_cls* FUN_00aa3760_cls::InitEntries(unsigned int auiValue)
{
    FUN_00aa3760_cls* self = this;
    void(__stdcall * pfnInit)(void*) = g_pfnEntryInit;
    int iRemaining = 0xff;
    FUN_00aa3760_entry* pEntry = m_entries;
    do
    {
        pEntry->unk00 = 0;
        pEntry->unk08 = 0;
        pEntry->unk0c = 0;
        pEntry->unk10 = 0;
        pEntry->unk14 = 0;
        pEntry->unk18 = 0;
        pEntry->unk1c = 0;
        pfnInit(&pEntry->unk80);
        pEntry++;
    } while ((iRemaining -= 1) >= 0);
    self->m_10000 = auiValue;
    for (unsigned int uiIndex = 1; uiIndex <= 256; uiIndex++)
    {
        FUN_00aa3760_entry* pEntry = &self->m_entries[uiIndex - 1];
        unsigned int v = 0x6400 / uiIndex;
        pEntry->unk0c = 0;
        pEntry->unk10 = 0;
        pEntry->unk08 = 0;
        pEntry->unk14 = 0;
        pEntry->unk00 = uiIndex;
        if (v > 0xff)
        {
            v = 0xff;
        }
        else if (v == 0)
        {
            v = uiIndex * 8;
        }
        pEntry->unk04 = (unsigned char)v;
    }
    return self;
}

// A single allocator block owns a sub-allocator header and a critical section.
struct AllocBlock
{
    int FUN_00aa35a0();
};

// The allocator keeps its blocks in a 0x100 sized array.
class FUN_00aa3810_cls
{
  public:
    int NiSmallObjectAllocator_Allocate(unsigned int index);
};

// @fnv 0x00aa3810
// src: COMMUNITY 0x00aa3810
int FUN_00aa3810_cls::NiSmallObjectAllocator_Allocate(unsigned int index)
{
    AllocBlock* block = (AllocBlock*)((char*)this + (index << 8) - 0x100);
    return block->FUN_00aa35a0();
}
