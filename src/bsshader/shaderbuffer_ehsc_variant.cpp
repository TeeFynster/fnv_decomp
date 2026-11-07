#include "../../include/NiTStringPointerMap.h"

// src/bsshader/shaderbuffer_ehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/bsshader/shaderbuffer.cpp lists /MT /O2 /GS /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "shaderbuffer_tables.h"
#include "MemoryManager.h"
#include "../../include/NiTStringPointerMap.h"
class ShaderBufferRecord;
class ShaderBufferCollection
{
  public:
    ~ShaderBufferCollection();
    ShaderBufferRecord* Get(const char* name);
    char* pFileName;
    char* m_pBufferName;
    NiTStringPointerMap<ShaderBufferRecord*> m_kBufferMap;
};
extern MemoryManager g_memoryManager;
void InitializeShaderBufferTables();
struct FUN_00aa4060_Manager
{
    void* MemoryManager_Deallocate(void* object);
};
extern FUN_00aa4060_Manager DAT_011f6238;
extern void* DAT_010ef53c;
extern void FUN_0045cec0(void* object);
extern void __stdcall FUN_00ec5fce(void* base, unsigned int elementSize, unsigned int count, void (*destructor)(void*));
struct FUN_00b7e2b0_Class
{
    void* unk00;
    void* unk04;

    void* Destroy(unsigned char flags);
};

struct S00b7fd90_Alloc
{
    void* Game_DoHeapAlloc(unsigned int uiSize);
};

struct Thing_b9704
{
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
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    Thing_b9704(unsigned int a1, unsigned int a2, Thing_b9704* a3);
    static void* operator new(unsigned int size)
    {
        return ((S00b7fd90_Alloc*)&DAT_011f6238)->Game_DoHeapAlloc(size);
    }
    static void operator delete(void* p)
    {
        DAT_011f6238.MemoryManager_Deallocate(p);
    }
};

struct S00b7fd90_cls
{
    unsigned int m_000;
    Thing_b9704** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void Expand_b9704(unsigned int newSize);
    void SetAt_b9704(unsigned int index, Thing_b9704*& item);
    void ShaderBufferCreator_Add(unsigned int a1, unsigned int a2, Thing_b9704* a3);
};

// @fnv 0x00b7fd90
// src: COMMUNITY 0x00b7fd90
void S00b7fd90_cls::ShaderBufferCreator_Add(unsigned int a1, unsigned int a2, Thing_b9704* a3)
{
    a3 = new Thing_b9704(a1, a2, a3);
    unsigned int index = m_usSize;
    if (index >= m_usMaxSize)
    {
        Expand_b9704(m_usGrowBy + index);
    }
    SetAt_b9704(index, a3);
}
