#include "../../../../include/NiTArray.h"

// src/fallout/ai/combat/explosion_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/combat/explosion.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/fallout/ai/combat/explosion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/explosion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../include/AutoMemContext.h"
#include "../../../../include/BSOcclusionPlane.h"
#include "../../../../include/Explosion.h"
// HavokAllocatorContext_explosion: local type (was include/HavokAllocatorContext.h, which had no evidence of one real class); no method of it is bound to a named game function
class HavokMemoryRouter;
#include "../../../../include/hkMemoryAllocator.h"

class HavokAllocatorContext_explosion
{
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    union
    {
        HavokMemoryRouter* m_router;
        hkMemoryAllocator* m_alloc;
    };
};
#include "../../../../include/NavMeshPtr.h"
#include "../../../../include/bhkLiquidAction.h"

void __cdecl _Deallocate(void*);
extern NiRTTI g_01268420;
struct FUN_009afc30_shell
{
    NavMeshPtr m_navMeshPtr;
    NavMesh* hkpFixedBufferCdPointCollector_getHits();
};
struct FUN_009afbb0_shell
{
    virtual ~FUN_009afbb0_shell();
    void* FUN_009afbb0(unsigned int flags);
    void ForwardCall_009afc10();
};
extern "C" void __cdecl Object_UpdateFields_009afbe0(void*);
struct FUN_00621100_shell
{
    void __thiscall SetVtable(void);
};
struct FUN_009afc10_shell
{
    void __thiscall ForwardCall_009afc10();
};
struct FUN_009afc50_shell
{
    char m_auiShapeKeys[0x14];
    NavMeshPtr m_navMeshPtr;
    NavMesh* hkpFixedBufferCdPointCollector_getHits();
};

struct P03MM
{
    void __thiscall DeallocateAlias(void*);
};
extern P03MM g_memoryManager;
void __cdecl FUN_00cbc740();

struct FUN_00cbd4e0_shell
{
    char m_auiShapeKeys[0x14];
    void* FUN_00cbd4e0(unsigned char flag);
};

// @fnv 0x00cbd4e0
void* FUN_00cbd4e0_shell::FUN_00cbd4e0(unsigned char flag)
{
    FUN_00cbc740();
    if (flag & 1)
        g_memoryManager.DeallocateAlias(this);
    return this;
}

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);

struct FUN_00cbc650_obj
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
    unsigned int m_0C;
    unsigned int m_10;
    unsigned int m_14;
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
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned char unk1E4;
    unsigned char m_1e5;
};

struct FUN_00cbc650_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual FUN_00cbc650_obj* vGet(FUN_00cbc650_obj* volatile* pp);
    void bhkUnaryAction_LoadBinary(FUN_00cbc650_obj* a);
    void bhkLiquidAction_LoadBinary(FUN_00cbc650_obj* volatile a1);
};

// @fnv 0x00cbc650
// src: XBOX_PDB 0x00cbc650
void FUN_00cbc650_cls::bhkLiquidAction_LoadBinary(FUN_00cbc650_obj* volatile a1)
{
    FUN_00cbc650_obj* obj = a1;
    bhkUnaryAction_LoadBinary(obj);
    if (obj->m_1e5 != 1)
    {
        volatile unsigned int* p = (volatile unsigned int*)vGet(&a1);
        p[2] = _byteswap_ulong(p[2]);
        p[3] = _byteswap_ulong(p[3]);
        p[4] = _byteswap_ulong(p[4]);
        p[5] = _byteswap_ulong(p[5]);
    }
}

struct FUN_00cbc6a0_Data
{
    volatile unsigned int unk00;
    volatile unsigned int unk04;
    volatile unsigned int unk08;
    volatile unsigned int unk0C;
    volatile unsigned int unk10;
    volatile unsigned int unk14;
};

struct FUN_00cbc6a0_Class
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void bhkLiquidAction_SaveBinary(unsigned char* arg);
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual FUN_00cbc6a0_Data* vf45(int* value);
    void __thiscall bhkUnaryAction_SaveBinary(unsigned char* arg);
};

// @fnv 0x00cbc6a0
// src: XBOX_PDB 0x00cbc6a0
void FUN_00cbc6a0_Class::bhkLiquidAction_SaveBinary(unsigned char* arg)
{
    unsigned char value;
    FUN_00cbc6a0_Data* data = vf45((int*)&value);

    if (arg[0x1E4] != 1)
    {
        data->unk08 = _byteswap_ulong(data->unk08);
        data->unk0C = _byteswap_ulong(data->unk0C);
        data->unk10 = _byteswap_ulong(data->unk10);
        data->unk14 = _byteswap_ulong(data->unk14);
    }

    bhkUnaryAction_SaveBinary(arg);

    if (arg[0x1E4] != 1)
    {
        data->unk08 = _byteswap_ulong(data->unk08);
        data->unk0C = _byteswap_ulong(data->unk0C);
        data->unk10 = _byteswap_ulong(data->unk10);
        data->unk14 = _byteswap_ulong(data->unk14);
    }
}

extern __declspec(thread) int g_memoryContext;
void __cdecl bhkSerializable_CloneCritLock();
void __cdecl bhkSerializable_CloneCritUnlock();
void* __cdecl Object_DispatchCommandFour(unsigned int size);
inline AutoMemContext::AutoMemContext()
{
    m_eMemoryContext = (MEM_CONTEXT)g_memoryContext;
    g_memoryContext = 16;
}
inline AutoMemContext::~AutoMemContext()
{
    g_memoryContext = (int)m_eMemoryContext;
}
struct FUN_00cbc550_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    static void* __cdecl operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
    FUN_00cbc550_class();
};
struct FUN_00cbca20_class
{
    void __thiscall bhkUnaryAction_CopyMembers(FUN_00cbc550_class* obj, int flags);
    FUN_00cbc550_class* __thiscall bhkLiquidAction_CreateClone(int flags);
};
// @fnv 0x00cbca20
// src: XBOX_PDB 0x00cbca20
FUN_00cbc550_class* __thiscall FUN_00cbca20_class::bhkLiquidAction_CreateClone(int flags)
{
    AutoMemContext context;
    bhkSerializable_CloneCritLock();
    FUN_00cbc550_class* result = new FUN_00cbc550_class();
    bhkUnaryAction_CopyMembers(result, flags);
    bhkSerializable_CloneCritUnlock();
    return result;
}


extern "C" HavokAllocatorContext_explosion* __cdecl hkMemoryRouter_getInstance();

struct HavokObj
{
    int unk00;
    short m_flags;
    short m_ref;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;

    static void* operator new(size_t size)
    {
        HavokAllocatorContext_explosion* tm = hkMemoryRouter_getInstance();
        HavokObj* p = (HavokObj*)tm->m_alloc->blockAlloc(size);
        p->m_flags = (short)size;
        return p;
    }
    static void operator delete(void* p);

    HavokObj(void* a1, int a2);
    void removeReference();
};

struct DynCastHelper2
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* unk18;
};

struct DynCastHelper1
{
    int unk00;
    int unk04;
    DynCastHelper2* unk08;
};

struct DynCastObj
{
    DynCastHelper1* __thiscall DynamicCast(const void* rtti);
};

struct GarbageCollectorObjectPtr
{
    DynCastObj* m_ptr;
    int m_unk04;
};

extern const void* DAT_01267b70;
extern const void* g_012043f8;

GarbageCollectorObjectPtr* __cdecl bhkWorldObject_GetProperty(GarbageCollectorObjectPtr* out, void* obj, const void* rtti);

struct ArgStruct
{
    int unk00;
    void* unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
};

struct TargetClass
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf0a();
    virtual void vf0b();
    virtual void vf0c();
    virtual void vf0d();
    virtual void vf0e();
    virtual void vf0f();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf1a();
    virtual void vf1b();
    virtual void vf1c();
    virtual void vf1d();
    virtual void vf1e();
    virtual void vf1f();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf8c(HavokObj* obj);
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf2a();
    virtual void vf2b();
    virtual void vf2c();
    virtual void vf2d();
    virtual void vf2e();
    virtual void vfbc(ArgStruct* arg);

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;

    void bhkLiquidAction_SetTargetObject(void* p);
    void bhkLiquidAction_Init(ArgStruct* arg);
};

// @fnv 0x00cbd520
// src: XBOX_PDB 0x00cbd520
void TargetClass::bhkLiquidAction_Init(ArgStruct* arg)
{
    AutoMemContext memContext;

    this->unk1c = arg->unk08;
    this->unk20 = arg->unk0c;
    this->unk14 = arg->unk10;
    this->unk18 = arg->unk14;

    HavokObj* obj = new HavokObj(arg->unk04, 0);
    this->vf8c(obj);
    obj->removeReference();

    GarbageCollectorObjectPtr gcPtr;
    void* pObj = arg->unk04;
    GarbageCollectorObjectPtr* res = bhkWorldObject_GetProperty(&gcPtr, pObj, &DAT_01267b70);
    if (res->m_ptr)
    {
        DynCastHelper1* dyn = res->m_ptr->DynamicCast(&g_012043f8);
        if (dyn && dyn->unk08 && dyn->unk08->unk18)
        {
            this->bhkLiquidAction_SetTargetObject(dyn->unk08->unk18);
        }
    }

    this->vfbc(arg);
}

template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::SetAtGrow(unsigned int uiIndex, const T& element)
{
    if (uiIndex >= m_usMaxSize)
        SetSize(uiIndex + m_usGrowBy);
    SetAt(uiIndex, element);
    return uiIndex;
}
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::Add(const T& element)
{
    return SetAtGrow(m_usSize, element);
}

typedef NiTArray<char*, NiTMallocInterface<char*> > NiViewerStringArray;
class FUN_00cbd650_base
{
  public:
    void bhkUnaryAction_GetViewerStrings(NiViewerStringArray* pkStrings);
};
class FUN_00cbd650_cls : public FUN_00cbd650_base
{
  public:
    void bhkLiquidAction_GetViewerStrings(NiViewerStringArray* pkStrings);
};
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcString);
extern const char* DAT_01268420;
// @fnv 0x00cbd650
// src: XBOX_PDB 0x00cbd650
void FUN_00cbd650_cls::bhkLiquidAction_GetViewerStrings(NiViewerStringArray* pkStrings)
{
    AutoMemContext kContext;
    bhkUnaryAction_GetViewerStrings(pkStrings);
    pkStrings->Add(NiViewerStrings_NiGetViewerString_Title(DAT_01268420));
}

inline void* operator new(size_t, void* p)
{
    return p;
}
struct SmallAlignedState
{
    unsigned int unk00;
    void* unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    SmallAlignedState() : unk00(0), unk04(0), unk08(5000.0f), unk0c(15.0f), unk10(64.0f), unk14(15.0f)
    {}
};
struct StateAllocator
{
    void* __thiscall Game_DoHeapAlloc(unsigned int bytes);
};
extern StateAllocator DAT_011f6238;
struct StateOwner
{
    unsigned int unk00;
    unsigned int unk04;
    void* unk08;
    SmallAlignedState* unk0c;
    unsigned int unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;
    void __thiscall bhkUnaryAction_CopyCinfo(SmallAlignedState* state);
    SmallAlignedState* bhkLiquidAction_CreateCinfo(bool* created);
};
// @fnv 0x00cbcad0
// src: XBOX_PDB 0x00cbcad0
SmallAlignedState* StateOwner::bhkLiquidAction_CreateCinfo(bool* created)
{
    AutoMemContext context;
    *created = !unk0c;
    if (*created)
    {
        unsigned char* raw = (unsigned char*)DAT_011f6238.Game_DoHeapAlloc(sizeof(SmallAlignedState) + 16);
        unsigned char offset = 16 - ((unsigned int)raw & 15);
        raw += offset;
        raw[-1] = offset;
        SmallAlignedState* state = new (raw) SmallAlignedState;
        unk0c = state;
        if (unk08)
        {
            bhkUnaryAction_CopyCinfo(state);
            state->unk08 = unk1c;
            state->unk0c = unk20;
            state->unk10 = unk14;
            state->unk14 = unk18;
        }
    }
    return unk0c;
}

struct ThreadBlock
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000c;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001c;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002c;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003c;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004c;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005c;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006c;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007c;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008c;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009c;
    unsigned int unk00a0;
    unsigned int unk00a4;
    unsigned int unk00a8;
    unsigned int unk00ac;
    unsigned int unk00b0;
    unsigned int unk00b4;
    unsigned int unk00b8;
    unsigned int unk00bc;
    unsigned int unk00c0;
    unsigned int unk00c4;
    unsigned int unk00c8;
    unsigned int unk00cc;
    unsigned int unk00d0;
    unsigned int unk00d4;
    unsigned int unk00d8;
    unsigned int unk00dc;
    unsigned int unk00e0;
    unsigned int unk00e4;
    unsigned int unk00e8;
    unsigned int unk00ec;
    unsigned int unk00f0;
    unsigned int unk00f4;
    unsigned int unk00f8;
    unsigned int unk00fc;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010c;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011c;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012c;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013c;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014c;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015c;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016c;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017c;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018c;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019c;
    unsigned int unk01a0;
    unsigned int unk01a4;
    unsigned int unk01a8;
    unsigned int unk01ac;
    unsigned int unk01b0;
    unsigned int unk01b4;
    unsigned int unk01b8;
    unsigned int unk01bc;
    unsigned int unk01c0;
    unsigned int unk01c4;
    unsigned int unk01c8;
    unsigned int unk01cc;
    unsigned int unk01d0;
    unsigned int unk01d4;
    unsigned int unk01d8;
    unsigned int unk01dc;
    unsigned int unk01e0;
    unsigned int unk01e4;
    unsigned int unk01e8;
    unsigned int unk01ec;
    unsigned int unk01f0;
    unsigned int unk01f4;
    unsigned int unk01f8;
    unsigned int unk01fc;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020c;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021c;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022c;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023c;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024c;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025c;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026c;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027c;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028c;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029c;
    unsigned int unk02a0;
    unsigned int unk02a4;
    unsigned int unk02a8;
    unsigned int unk02ac;
    unsigned int unk02b0;
    unsigned int context;
};
extern __declspec(thread) ThreadBlock threadBlock;
struct ContextScope
{
    unsigned int saved;
    ContextScope(unsigned int old)
    {
        saved = old;
        threadBlock.context = 16;
    }
    ~ContextScope()
    {
        threadBlock.context = saved;
    }
};
struct CauseMap
{
    bool __thiscall FUN_00a53c30(void* key, void** out);
    void __thiscall InsertOrUpdate(void* key, void* value);
};
extern CauseMap DAT_011b2190;
struct CauseList
{
    void* unk00;
    void* unk04;
    void __thiscall PushItem(void** owner);
};
// @fnv 0x00cbcbd0
// src: XBOX_PDB 0x00cbcbd0
void TargetClass::bhkLiquidAction_SetTargetObject(void* p)
{
    unsigned int restore = threadBlock.context;
    ContextScope scope(restore);
    if (p)
    {
        void* key = p;
        p = 0;
        unk10 = (int)key;
        DAT_011b2190.FUN_00a53c30(key, &p);
        CauseList* list = (CauseList*)p;
        switch ((unsigned int)list)
        {
        case 0: {
            CauseList* allocated = (CauseList*)DAT_011f6238.Game_DoHeapAlloc(8);
            if (allocated != list)
            {
                allocated->unk00 = list;
                allocated->unk04 = list;
                list = allocated;
            }
            DAT_011b2190.InsertOrUpdate((void*)unk10, list);
            if (list)
            {
                restore = *(volatile unsigned int*)&scope.saved;
            }
            else
            {
                scope.saved = *(volatile unsigned int*)&scope.saved;
                return;
            }
            break;
        }
        default:
            break;
        }
        if (list)
        {
            p = this;
            list->PushItem(&p);
        }
    }
restore_exit:
    scope.saved = restore;
cold_exit:;
}
