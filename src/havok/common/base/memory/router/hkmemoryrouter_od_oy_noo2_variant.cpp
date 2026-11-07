
// src/havok/common/base/memory/router/hkmemoryrouter_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/havok/common/base/memory/router/hkmemoryrouter.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/base/memory/router/hkmemoryrouter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/router/hkmemoryrouter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00c85690_Allocator
{
    virtual void unk00();
    virtual void* Allocate(unsigned int size);
};
struct FUN_00c85690_Header
{
    FUN_00c85690_Allocator* allocator;
    unsigned int size;
    int unk08;
    int unk0C;
};
void* __cdecl AllocateWithHeader(FUN_00c85690_Allocator* allocator, unsigned int size);
struct Child
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void FlushUsageData();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void Release();
};
struct Owner
{
    int unk00, unk04, unk08;
    Child* child0C;
    Child* child10;
    Child* child14;
    Child* child18;
    Child* child1C;
    void ReleaseChildren();
};
class MemHeap
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void Free(char* block, unsigned int size);
};
void __cdecl hkMemoryRouter_alignedFree(MemHeap* heap, char* p);
struct FNV_Dispatch
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08(void* block, unsigned int size);
};
struct FNV_BlockHeader
{
    unsigned int m_iObjectReferenceCount;
    unsigned int m_iElementCount;
};
void hkMemoryRouter_easyFree(FNV_Dispatch* owner, char* data);
struct TargetClass
{
    int m_f00;
    int m_f04;
    int m_f08;
    int m_f0c;
    int m_f10;
    int m_f14;
    int m_f18;
    int m_f1c;

    TargetClass* Clear();
};

struct ReturnType
{
    int unk00;
    unsigned short unk04;
};

struct Pool
{
    virtual void unk00();
    virtual ReturnType* Alloc(unsigned int nbytes);
};

struct Holder
{
    Pool* TESMain_GetThread();
};

Holder* __cdecl hkMemoryRouter_getInstance();

// @fnv 0x0056d280
// src: GUESS 0x0056d280 (confidence: medium)
ReturnType* __cdecl Object_AllocateStorage_0056d280(unsigned int nbytes)
{
    ReturnType* result;
    {
        Pool* pool = hkMemoryRouter_getInstance()->TESMain_GetThread();
        result = pool->Alloc(nbytes);
    }
    result->unk04 = (unsigned short)nbytes;
    return result;
}
