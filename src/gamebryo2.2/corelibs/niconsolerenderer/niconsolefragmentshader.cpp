
#include "niconsolefragmentshader_decls.h"
#include "../../../../include/BSShaderBloodSplatter.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiFragmentShaderInstanceDescriptor.h"
#include "../../../../include/NiRenderer.h"
#include "../../../../include/NiD3DShader.h"
#include "../../../../include/NiD3DShaderConstantMap.h"
#include "../../../../include/NiD3DPass.h"
#include "../../../../include/NiTPointerListBase.h"
#include "../../../../include/NiTPointerAllocator.h"
#include "../../../../include/NiTListItem.h"
// @fnv 0x00e8b560
void ShaderCache::BindGPUProgram()
{
    while (count)
    {
        PoolAllocatorBase<unsigned int>::LinkedListEntry* node = head;
        head = node->next;
        if (head)
            head->prev = 0;
        else
            tail = 0;
        ShaderEntry* entry = (ShaderEntry*)node->data;
        node->data = 0;
        PoolAllocatorBase<unsigned int>::ms_kPoolState.Lock(0);
        node->prev = 0;
        node->next = PoolAllocatorBase<unsigned int>::ms_pFreeList;
        PoolAllocatorBase<unsigned int>::ms_pFreeList = node;
        if (--DAT_011c5f84 == 0)
            PoolAllocatorBase<unsigned int>::ms_kPoolState.m_uiOwningThreadID = 0;
        --count;
        ShaderData* data = entry->data;
        typedef void(__stdcall * SetFunction)(Device*, unsigned int, unsigned int);
        ((SetFunction)device->vtable[53])(device, data->handle, 0);
        data->active = false;
    }
    current = initial;
}

// @fnv 0x00e8d230
char __fastcall EnsureD3DShaderInitialized(NiD3DShader* shader, void*, int arg)
{
    if (shader->m_bInitialized)
        return 1;
    char result = shader->NiD3DShader::Initialize() ? 1 : 0;
    return result;
}

extern char const* const g_01270918_arg1;

// @fnv 0x00e8d360
// src: COMMUNITY 0x00e8d360
char const* const* __cdecl NiShader_NiShaderInstanceDescriptor_GetRTTI()
{
    return &g_01270918_arg1;
}

extern int DAT_010efeb4;

extern MemoryManager g_memoryManager;

struct NiShaderInstanceDescriptor
{
    void* m_p;
    void* __thiscall FUN_00e8d370(unsigned int mode);
};

// Sets m_p to the address of DAT_010efeb4 and, when mode has bit 0 set, deallocates this via g_memoryManager, then returns this.
// @fnv 0x00e8d370
void* __thiscall NiShaderInstanceDescriptor::FUN_00e8d370(unsigned int mode)
{
    m_p = &DAT_010efeb4;
    if (mode & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}

extern "C" void* g_01270918;

// @fnv 0x00e8d530
// src: COMMUNITY 0x00e8d530
void* __cdecl NiFragmentShaderInstanceDescriptor_GetRTTI()
{
    return &g_01270918;
}

struct GlobalObjectO2_00a7b610
{
};
extern GlobalObjectO2_00a7b610 g_0126f9d8;

// @fnv 0x00e8d580
// src: COMMUNITY 0x00e8d580
GlobalObjectO2_00a7b610* __cdecl NiDX9FragmentShader_GetRTTI()
{
    return &g_0126f9d8;
}

// 0x0043a010 is NiTPointerAllocator<unsigned int>::Allocate; the list uses head/tail/count at 0/4/8.
// @fnv 0x00e8b5f0
template <>
void NiTPointerListBase<NiTPointerAllocator<unsigned int>, void*>::AddHead(void* const& element)
{
    NiTListItem<void*>* node = (NiTListItem<void*>*)m_kItemCount.Allocate();
    node->m_element = element;
    node->m_pkPrev = 0;
    node->m_pkNext = m_pkHead;
    if (m_pkHead)
    {
        m_pkHead->m_pkPrev = node;
        ++m_kItemCount.m_uiCount;
        m_pkHead = node;
        return;
    }
    ++m_kItemCount.m_uiCount;
    m_pkTail = node;
    m_pkHead = node;
}

void __cdecl FUN_00e81470();
// @fnv 0x00e8d340
// src: COMMUNITY 0x00e8d340
void __cdecl NiDX9FragmentShader_DestroyRendererData()
{
    return FUN_00e81470();
}


struct NiD3DVertexDeclaration
{
    static NiD3DVertexDeclaration* __cdecl Create(NiRenderer*, unsigned int, unsigned int);
};

struct NiConsoleShaderDeclaration_shellEx
{
    NiD3DVertexDeclaration* __thiscall NiDX9FragmentShader_CreateShaderDeclaration(unsigned int a, unsigned int b);
};

// @fnv 0x00e8d410
// src: COMMUNITY 0x00e8d410
NiD3DVertexDeclaration* __thiscall NiConsoleShaderDeclaration_shellEx::NiDX9FragmentShader_CreateShaderDeclaration(unsigned int a, unsigned int b)
{
    NiD3DVertexDeclaration* p = NiD3DVertexDeclaration::Create(NiRenderer::ms_pRenderer, a, b);
    void** vtable = *(void***)this;
    void* fn = vtable[0x30];
    ((void(__thiscall*)(NiConsoleShaderDeclaration_shellEx*, NiD3DVertexDeclaration*))fn)(this, p);
    return p;
}

typedef void(__cdecl* DAT_0126f738_fn_t)(void*, void*, unsigned int, unsigned int, unsigned int);
extern DAT_0126f738_fn_t DAT_0126f738[];
// Calls the function pointer at DAT_0126f738 indexed by the int at a1+0x134, passing a1+0xF4, a1+0x118, a2, a3 and a4.
// @fnv 0x00e8d3d0
void __cdecl DispatchByIndex(void* a1, unsigned int auiArg2, unsigned int auiArg3, unsigned int auiArg4)
{
    DAT_0126f738[*(int*)((char*)a1 + 0x134)]((char*)a1 + 0xF4, (char*)a1 + 0x118, auiArg2, auiArg3, auiArg4);
}

extern int EmptyFS;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
// @fnv 0x00e8d540
void* __thiscall NiFragmentShaderInstanceDescriptor::FUN_00e8d540(unsigned int flags)
{
    if ((int)m_pDescriptorData != EmptyFS)
        InterlockedDecrement((long volatile*)((int)m_pDescriptorData - 8));
    *(int*)this = (int)&DAT_010efeb4;
    if (flags & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}

extern BSShaderBloodSplatter* DAT_0126f74c;
int __fastcall NiD3DPass_SetVertexShader(char*, int, NiRefObject*);
struct FUN_00e8d5f0_Param
{
    char _0[8];
    int m8;
};
// Rejects a1 >= 1 or a null DAT_0126f74c; for a2->m8 of 0 calls FUN_00b79950, for 2 calls FUN_00b80600, and returns true.
// @fnv 0x00e8d5f0
bool __stdcall ProcessShaderParam(unsigned int a1, FUN_00e8d5f0_Param* pParam, void* pUnused)
{
    if (a1 >= 1)
        return false;
    BSShaderBloodSplatter* p = DAT_0126f74c;
    if (!p)
        return false;
    switch (pParam->m8)
    {
    case 0:
        NiD3DPass_SetVertexShader((char*)p, (int)pParam, (NiRefObject*)pParam);
        break;
    case 2:
        p->NiD3DPass_SetPixelShader((NiRefObject*)pParam);
        return true;
    }
    return true;
}

struct Rec24
{
    char pad[0x24];
    unsigned short m24;
};

struct IShaderVt
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual int v11(unsigned short a);
};

struct Obj18
{
    void NiDX9Renderer_CalculateBoneMatrices(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e);
    void NiDX9Renderer_SetModelTransform(unsigned int a, unsigned int b);
};

struct FragHost
{
    char pad0[0x18];
    Obj18* m18;
    IShaderVt* m1c;
    char pad1[0x18];
    int m38;

    int FUN_00e807d0(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f,
                     unsigned int g, unsigned int h);
    int NiDX9FragmentShader_SetupTransformations(unsigned int p1, unsigned int p2, Rec24* p3, unsigned int p4, unsigned int p5, unsigned int p6,
                     unsigned int p7, unsigned int p8);
};

// @fnv 0x00e8d260
// src: COMMUNITY 0x00e8d260
int FragHost::NiDX9FragmentShader_SetupTransformations(unsigned int p1, unsigned int p2, Rec24* pRec, unsigned int p4, unsigned int p5,
                           unsigned int p6, unsigned int p7, unsigned int p8)
{
    if (pRec != 0)
    {
        if (m38 == 0)
        {
            m18->NiDX9Renderer_CalculateBoneMatrices(p2, p7, 1, 3, 1);
        }
        m1c->v11(pRec->m24);
        m18->NiDX9Renderer_SetModelTransform(p7, 0);
        return 0;
    }
    return FUN_00e807d0(p1, p2, 0, p4, p5, p6, p7, p8);
}

struct FUN_00e8d3a0_sub
{
    unsigned char Query(unsigned int id, unsigned int* out, unsigned char* flag);
};

struct FUN_00e8d3a0_cls
{
    char unk00[0x10];
    FUN_00e8d3a0_sub* m_10;
    unsigned char QueryFlagB();
};

// Calls Query on m_10 for id 0xb, then returns flag masked with 0xFF when Query succeeds, else 0.
// @fnv 0x00e8d3a0
unsigned char FUN_00e8d3a0_cls::QueryFlagB()
{
    unsigned int value = 0;
    unsigned char flag = 0;
    unsigned char result = (m_10->Query(0xb, &value, &flag) != 0 ? -1 : 0) & flag;
    return result;
}

struct S_00e8d590_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int m64;
    void FUN_00e80190(void);
};
void __cdecl FUN_00e804d0(S_00e8d590_Obj** out);
// @fnv 0x00e8d590
// src: COMMUNITY 0x00e8d590
bool __stdcall NiDX9FragmentShader_AppendRenderPass(int* out)
{
    S_00e8d590_Obj* obj = 0;
    if (DAT_0126f74c == 0)
    {
        FUN_00e804d0(&obj);
        DAT_0126f74c = (BSShaderBloodSplatter*)obj;
        *out = 0;
        if (obj)
        {
            S_00e8d590_Obj* p = obj;
            p->m64--;
            if (p->m64 == 0)
                p->FUN_00e80190();
        }
        return true;
    }
    return false;
}

struct Inner_e8db90
{
    Inner_e8db90();
    void* __thiscall FUN_00ee8a10(unsigned int a);
};

struct SubObj_e8db90
{
    virtual void unk00();
    Inner_e8db90 m_inner;
    SubObj_e8db90() : m_inner()
    {}
};

struct BaseObj_e8db90
{
    BaseObj_e8db90();
    virtual void unk00();
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
};

struct FieldsMid_e8db90
{
    unsigned char m_24;
    unsigned char m_25;
    unsigned char m_26;
    unsigned char m_27;
    unsigned int m_28;
    unsigned int m_2c;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
    FieldsMid_e8db90()
    {
        m_24 = 0;
        m_25 = 0;
        m_28 = 0;
        m_2c = 0;
        m_30 = 0;
        m_34 = 0;
        m_38 = 0;
    }
};

struct FUN_00e8db90 : BaseObj_e8db90, FieldsMid_e8db90
{
    virtual void unk00();
    SubObj_e8db90 m_3c;
    FUN_00e8db90(unsigned int a);
};

// @fnv 0x00e8db90
FUN_00e8db90::FUN_00e8db90(unsigned int a)
{
    m_3c.m_inner.FUN_00ee8a10(a);
}

unsigned int __stdcall NiD3DShader_SetupRenderingPass(void* a, void* b, void* c, void* d, void* e, void* f, void* g);

// @fnv 0x00e8d250
// src: COMMUNITY 0x00e8d250
unsigned int __stdcall NiDX9FragmentShader_SetupRenderingPass(void* a, void* b, void* c, void* d, void* e, void* f, void* g)
{
    return NiD3DShader_SetupRenderingPass(a, b, c, d, e, f, g);
}

void __cdecl FUN_00e811d0();
// @fnv 0x00e8d2e0
// src: COMMUNITY 0x00e8d2e0
void __cdecl NiDX9FragmentShader_SetupShaderPrograms()
{
    FUN_00e811d0();
}

extern int __cdecl PrepareShaderAndStreams();

// @fnv 0x00e8d2f0
// src: COMMUNITY 0x00e8d2f0
int __cdecl NiDX9FragmentShader_PrepareGeometryForRendering()
{
    return PrepareShaderAndStreams();
}

extern "C" void __cdecl ThisCall_Ret0_8Args();
// @fnv 0x00e8d300
// src: COMMUNITY 0x00e8d300
void __cdecl j_retn0_1()
{
    ThisCall_Ret0_8Args();
}

__declspec(noreturn) void __cdecl FUN_00e805f0();

// @fnv 0x00e8d310
// src: XBOX_PDB 0x00e8d310
void __cdecl NiDX9FragmentShader_PostProcessPipeline()
{
    FUN_00e805f0();
}

void __cdecl FUN_00e80580();
// @fnv 0x00e8d320
// src: COMMUNITY 0x00e8d320
void __cdecl NiDX9FragmentShader_FirstPass()
{
    FUN_00e80580();
}

void __cdecl FUN_00e80590();

// @fnv 0x00e8d330
// src: COMMUNITY 0x00e8d330
void __cdecl NiDX9FragmentShader_NextPass()
{
    FUN_00e80590();
}


extern NiD3DPass* g_pD3DPass;
extern void* g_pD3DRenderer;

inline void* __cdecl operator new(size_t, void* storage) throw()
{
    return storage;
}

static __forceinline NiD3DShaderConstantMap* CreateShaderConstantMap(int type)
{
    void* storage = NiD3DShaderConstantMap::operator new(sizeof(NiD3DShaderConstantMap));
    return storage ? ::new (storage) NiD3DShaderConstantMap(g_pD3DRenderer, type) : 0;
}

// Returns the pass's vertex or pixel constant map for shader type 0, creating and registering it if absent.
// @fnv 0x00e8dca0
NiD3DShaderConstantMap* __stdcall GetOrCreateShaderConstantMap(unsigned int auiShaderType, int eMapType)
{
    if (auiShaderType >= 1)
        return 0;
    NiD3DPass* pkPass = g_pD3DPass;
    if (!pkPass)
        return 0;
    NiD3DShaderConstantMap* pkMap = 0;
    if (eMapType == 0)
    {
        pkMap = pkPass->m_spVertexConstantMap.m_pObject;
        if (!pkMap)
        {
            pkMap = CreateShaderConstantMap(0);
            pkPass->SetVertexConstantMap(pkMap);
        }
    }
    else if (eMapType == 1)
    {
        pkMap = pkPass->m_spPixelConstantMap.m_pObject;
        if (!pkMap)
        {
            pkMap = CreateShaderConstantMap(2);
            pkPass->SetPixelConstantMap(pkMap);
        }
    }
    return pkMap;
}

struct ShaderStandIn
{
    unsigned int __thiscall FUN_00e81170(void*, void*, void*, void*, void*, void*, void*);
};
struct FUN_00bd16e0_shell : ShaderStandIn
{
    unsigned int __thiscall NiDX9FragmentShader_PreProcessPipeline(void* a, void* b, void* c, void* d, void* e, void* f, void* g);
};
// @fnv 0x00bd16e0
// src: XBOX_PDB 0x00bd16e0
unsigned int __thiscall FUN_00bd16e0_shell::NiDX9FragmentShader_PreProcessPipeline(void* a, void* b, void* c, void* d, void* e, void* f, void* g)
{
    return FUN_00e81170(a, b, c, d, e, f, g);
}

// Object cached in BSShaderBloodSplatter+0x30; receives SetNodeValue / RemoveNodeByKey as this.
struct BloodMap
{
    void SetNodeValue(unsigned int a, int b, int c);
    void RemoveNodeByKey(unsigned int a);
};

// Pointer returned by FUN_00e7f7c0; dword table at offset 0x20 indexed by param.
struct BloodArrView
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int m20[64];
};

// View of BSShaderBloodSplatter for this function.
struct BloodSplatterView
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
    BloodMap* unk30;
    BloodArrView* NiD3DPass_GetD3DRenderState(void);
    void NiD3DPass_SetRenderState(unsigned int a, int b, int c);
};

BloodMap* __stdcall FUN_00e7f5d0(void);

// Sets blood splatter node values and passes indexed array values to the view; returns false for an unsupported type or missing view.
// @fnv 0x00e8d450
bool __stdcall SetBloodSplatter(unsigned int auiShaderType, bool abEnabled, bool bParam3, int aiIndex, bool bParam5,
                                int aiSecondIndex)
{
    if (auiShaderType >= 1)
        return false;

    BloodSplatterView* pkSplat = (BloodSplatterView*)DAT_0126f74c;
    if (!pkSplat)
        return false;

    if (abEnabled)
    {
        if (!pkSplat->unk30)
            pkSplat->unk30 = FUN_00e7f5d0();
        pkSplat->unk30->SetNodeValue(0x1b, 1, 1);

        BloodArrView* pkArr = pkSplat->NiD3DPass_GetD3DRenderState();

        if (!bParam3)
        {
            pkSplat->NiD3DPass_SetRenderState(0x13, pkArr->m20[aiIndex], 0);
        }
        else
        {
            BloodMap* pkBloodMap = pkSplat->unk30;
            if (pkBloodMap)
                pkBloodMap->RemoveNodeByKey(0x13);
        }

        if (!bParam5)
        {
            pkSplat->NiD3DPass_SetRenderState(0x14, pkArr->m20[aiSecondIndex], 0);
        }
        else
        {
            BloodMap* pkBloodMap = pkSplat->unk30;
            if (pkBloodMap)
                pkBloodMap->RemoveNodeByKey(0x14);
        }
    }
    else
    {
        if (!pkSplat->unk30)
            pkSplat->unk30 = FUN_00e7f5d0();
        pkSplat->unk30->SetNodeValue(0x1b, 0, 1);
    }

    return true;
}

extern unsigned int DAT_010eff44;
extern void* DAT_0109b220;
void operator delete(void* pvObject, unsigned int uiSize);

struct ShaderObj
{
    volatile unsigned int m_vft0;
    unsigned int unk04;
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
    unsigned int m_vft3c;
    void* volatile m_40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;

    void FUN_00e806c0();
    ShaderObj* Release(unsigned int uiFlags);
};

// Releases the device reference, calls FUN_00e806c0, and optionally deletes this when uiFlags has bit 0 set.
// @fnv 0x00e8dbe0
ShaderObj* ShaderObj::Release(unsigned int uiFlags)
{
    m_vft0 = (unsigned int)&DAT_010eff44;
    void* pvDevice = m_40;
    if (pvDevice != DAT_0109b220)
        InterlockedDecrement((volatile long*)pvDevice - 2);
    m_vft3c = (unsigned int)&DAT_010efeb4;
    FUN_00e806c0();
    if (uiFlags & 1)
        operator delete(this, sizeof(ShaderObj));
    return this;
}

class ShaderConstantEntryE8D
{
  public:
    void Destroy();
    unsigned int m_uiPosition;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_uiValue1;
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
    unsigned short m_usRegisterInfo;
    unsigned short unk5e;
    int m_iRefCount;
};

__forceinline void SetFlagBitsE8D(ShaderConstantEntryE8D* pkE, unsigned int uiClear, unsigned int uiSet)
{
    pkE->m_uiValue1 &= uiClear;
    pkE->m_uiValue1 |= uiSet;
}

__forceinline void ReleaseEntryE8D(ShaderConstantEntryE8D* pkEntry)
{
    if (pkEntry)
    {
        ShaderConstantEntryE8D* pkTemp = pkEntry;
        --pkTemp->m_iRefCount;
        if (pkTemp->m_iRefCount == 0)
            pkTemp->Destroy();
    }
}

class ShaderConstantMapE8D
{
  public:
    int AddEntry(void* pvList, ShaderConstantEntryE8D* pkEntry);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    void* m_pvEntries;
    unsigned int m_uiStreamIndex;
};
extern ShaderConstantMapE8D* g_pkConstantMapE8D;

void __cdecl CreateEntryE8D(ShaderConstantEntryE8D** ppkEntry);
bool __cdecl LookupPredefinedE8D(const char* pcName, unsigned int* puiType);
bool __cdecl LookupObjectE8D(const char* pcName, unsigned int* puiType);

// Creates and adds an entry, then sets its fields according to predefined or object lookup results.
// @fnv 0x00e8d630
bool __stdcall AddShaderConstant(unsigned int uiFlags, unsigned int* puiIndex, const char* pcName,
                                 unsigned int uiUnused3, unsigned int uiExtra)
{
    if (uiFlags >= 1)
        return false;

    ShaderConstantMapE8D* pkMap = g_pkConstantMapE8D;
    if (!pkMap)
        return false;

    ShaderConstantEntryE8D* pkEntry = 0;
    CreateEntryE8D(&pkEntry);
    if (pkMap->AddEntry(pkMap->m_pvEntries, pkEntry))
    {
        ReleaseEntryE8D(pkEntry);
        return false;
    }
    *puiIndex = pkMap->m_uiStreamIndex - 1;

    unsigned int uiConstantType = 0;
    if (LookupPredefinedE8D(pcName, &uiConstantType))
    {
        switch (uiConstantType)
        {
        case 0:
            SetFlagBitsE8D(pkEntry, 0xf0ffffff, 0x200000);
            break;
        case 1:
            SetFlagBitsE8D(pkEntry, 0xf0ffffff, 0x300000);
            break;
        case 2:
            SetFlagBitsE8D(pkEntry, 0xf0ffffff, 0x400000);
            break;
        case 3:
            SetFlagBitsE8D(pkEntry, 0xf0ffffff, 0x500000);
            break;
        case 4:
            SetFlagBitsE8D(pkEntry, 0xf0ffffff, 0x600000);
            break;
        case 5:
            SetFlagBitsE8D(pkEntry, 0xf0ffffff, 0x700000);
            break;
        case 6:
            SetFlagBitsE8D(pkEntry, 0xf0ffffff, 0x800000);
            break;
        case 7:
            SetFlagBitsE8D(pkEntry, 0xf0ffffff, 0x900000);
            break;
        case 8:
            SetFlagBitsE8D(pkEntry, 0xf00fffff, uiExtra | 0x1000000);
            break;
        case 9:
            SetFlagBitsE8D(pkEntry, 0xf00fffff, uiExtra | 0x2000000);
            break;
        default:
            ReleaseEntryE8D(pkEntry);
            return false;
        }
    }
    else if (LookupObjectE8D(pcName, &uiConstantType))
    {
        unsigned short usRegisterType = 0;
        switch (uiConstantType)
        {
        case 0:
            usRegisterType = 0x700;
            break;
        case 1:
            usRegisterType = 0x600;
            break;
        case 2:
            usRegisterType = 0x500;
            break;
        case 3:
            usRegisterType = 0x800;
            break;
        }
        pkEntry->m_usRegisterInfo = (usRegisterType & 0xff00) | uiExtra;
    }
    ReleaseEntryE8D(pkEntry);
    return true;
}

struct ShaderConstantList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned int count;
    int unk1c;
    int unk20;
    void** entries;
};

struct ShaderGeometry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void* property;
};

struct ShaderBaseView
{
    void NiD3DShader_UpdatePipeline(void*, void*, void*, ShaderGeometry*, void*, void*, void*);
};

struct ShaderView : ShaderBaseView
{
    void BindShaderInput(void*, void*, void*);
    void NiDX9FragmentShader_UpdatePipeline(void*, void*, void*, ShaderGeometry*, void*, void*, void*);
};

// Iterates the global list, calls BindShaderInput for nonnull entries, then invokes the base class routine.
// @fnv 0x00e8dc30
// src: COMMUNITY 0x00e8dc30
void ShaderView::NiDX9FragmentShader_UpdatePipeline(void* a, void* b, void* c, ShaderGeometry* geometry, void* e, void* f, void* g)
{
    ShaderConstantList* pConstantList = reinterpret_cast<ShaderConstantList*>(DAT_0126f74c);
    if (pConstantList)
    {
        for (unsigned int i = 0; i < pConstantList->count; ++i)
        {
            void* entry = pConstantList->entries[i];
            if (entry)
                BindShaderInput(entry, geometry->property, e);
        }
    }
    ShaderBaseView::NiD3DShader_UpdatePipeline(a, b, c, geometry, e, f, g);
}

extern "C" void _ReadWriteBarrier();
struct BinaryDataRecord
{
    unsigned int field00;
    unsigned short format;
    unsigned short field06;
    void* data;
};
struct StreamSet
{
    BinaryDataRecord* position;
    BinaryDataRecord* normal;
    BinaryDataRecord* color;
    BinaryDataRecord* weights;
    BinaryDataRecord* indices;
    BinaryDataRecord* tangent;
    BinaryDataRecord* binormal;
    BinaryDataRecord* extra;
    BinaryDataRecord* texcoords[1];
};
struct SkinData
{
    unsigned int field00, field04;
    unsigned short field08, count;
};
struct Geometry
{
    unsigned int field00, field04, field08, field0c, field10, field14, field18, field1c;
    StreamSet* streams;
    unsigned short field24, streamCount;
    unsigned int field28;
    SkinData* skin;
    BinaryDataRecord* GetElementAt(unsigned int);
};
struct TextureProperty
{
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    unsigned int field20;
    unsigned int field24;
    unsigned int field28;
    unsigned int field2c;
    unsigned int field30;
    unsigned int field34;
    unsigned int field38;
    unsigned int field3c;
    unsigned int field40;
    unsigned int field44;
    unsigned int field48;
    unsigned int field4c;
    unsigned int field50;
    unsigned int field54;
    unsigned int field58;
    unsigned int field5c;
    unsigned int field60;
    unsigned int field64;
    unsigned int field68;
    unsigned int field6c;
    unsigned int field70;
    unsigned int field74;
    unsigned int field78;
    unsigned int field7c;
    unsigned int field80;
    unsigned int field84;
    unsigned int field88;
    unsigned int field8c;
    unsigned int field90;
    unsigned int field94;
    unsigned int field98;
    unsigned char active;
    unsigned int field0a0;
    unsigned int field0a4;
    unsigned int field0a8;
    unsigned int field0ac;
    unsigned int field0b0;
    unsigned int field0b4;
    unsigned int field0b8;
    unsigned int field0bc;
    unsigned int field0c0;
    unsigned int field0c4;
    unsigned int field0c8;
    unsigned int field0cc;
    unsigned int field0d0;
    unsigned int field0d4;
    unsigned int field0d8;
    unsigned int field0dc;
    unsigned int field0e0;
    unsigned int field0e4;
    unsigned int field0e8;
    unsigned int field0ec;
    unsigned int field0f0;
    unsigned int field0f4;
    unsigned int field0f8;
    unsigned int field0fc;
    unsigned int field100;
    unsigned int field104;
    unsigned int field108;
    unsigned int field10c;
    unsigned int field110;
    unsigned int field114;
    unsigned int field118;
    unsigned int field11c;
    unsigned int field120;
    void* data;
    unsigned int format;
    unsigned int dimension;
};
struct PropertyNode
{
    PropertyNode* next;
    TextureProperty* data;
};
struct PropertyState
{
    unsigned int field00, field04, field08, field0c;
    PropertyNode* first;
    PropertyNode* second;
    TextureProperty* primary;
    TextureProperty* secondary;
    __forceinline TextureProperty* Find(PropertyNode* node, unsigned int index, unsigned int found)
    {
        while (node)
        {
            TextureProperty* texture = node->data;
            node = node->next;
            if (texture && texture->active == 1 && (unsigned short)found++ == (unsigned short)index)
                return texture;
        }
        return 0;
    }
};
struct BeamTextureState
{
    void SetStageValue(unsigned int, unsigned int, bool);
};
struct Descriptor
{
    unsigned int field00, field04;
    void* data;
    unsigned int selector;
    BeamTextureState* state;
    unsigned int field14, field18, field1c, field20, field24, field28, field2c;
    unsigned int field30, field34, field38, field3c, field40, field44, field48, field4c;
    unsigned int field50, field54, field58;
    unsigned short property;
    unsigned int NiD3DTextureStage_GetTexCoordIndex();
    bool QueryFlagB();
    void ApplyPairToState(unsigned int);
    void NiD3DTextureStage_SetFilterMode(unsigned int);
};
struct ShaderHost
{
    unsigned int field00, field04, field08, field0c, field10, field14, field18;
    void BindShaderInput(Descriptor* descriptor, Geometry* geometry, PropertyState* properties);
};
static __forceinline BinaryDataRecord* LookupStream(Geometry* geometry, unsigned int selector)
{
    unsigned int category = selector & 0x0f000000;
    if (category == 0)
    {
        switch (selector & 0x00f00000)
        {
        case 0x200000:
            return geometry->streams->position;
        case 0x300000:
            return geometry->streams->normal;
        case 0x400000:
            return geometry->streams->color;
        case 0x500000:
            return geometry->streams->weights;
        case 0x600000:
            return geometry->streams->indices;
        case 0x700000:
            return geometry->streams->tangent;
        case 0x800000:
            return geometry->streams->binormal;
        case 0x900000:
            return geometry->streams->extra;
        }
    }
    else if (category == 0x01000000)
    {
        if ((unsigned short)selector < (unsigned int)(geometry->streamCount - 8))
            return geometry->streams->texcoords[(unsigned short)selector];
    }
    else if (category == 0x02000000)
    {
        SkinData* skin = geometry->skin;
        unsigned int slot = (unsigned short)selector;
        if (skin && slot < skin->count)
            return geometry->GetElementAt(slot);
    }
    return 0;
}

// Resolves a descriptor's property or stream selector into data, dimension, and format, then applies them to the descriptor's state.
// @fnv 0x00e8d890
void ShaderHost::BindShaderInput(Descriptor* descriptor, Geometry* geometry, PropertyState* properties)
{
    unsigned short property = descriptor->property;
    unsigned int selector = descriptor->selector;
    void* data = 0;
    unsigned int dimension = 0;
    unsigned int format = 0;
    if (!property)
    {
        if (selector)
        {
            BinaryDataRecord* stream = LookupStream(geometry, selector);
            if (stream)
            {
                unsigned int packed = stream->format;
                _ReadWriteBarrier();
                data = stream->data;
                _ReadWriteBarrier();
                dimension = (packed >> 12) & 3;
                format = (packed >> 8) & 15;
                if ((selector & 0xf0000000) == 0x10000000)
                {
                    unsigned int value = stream->format & 255;
                    value |= descriptor->NiD3DTextureStage_GetTexCoordIndex() & 0xffff0000;
                    bool flag = descriptor->QueryFlagB();
                    descriptor->state->SetStageValue(11, value, flag);
                }
            }
        }
    }
    else
    {
        unsigned int found = 0;
        if (!properties)
            goto finish;
        unsigned short index = property & 0xff;
        TextureProperty* texture = 0;
        switch (property >> 8)
        {
        case 5:
            texture = properties->primary;
            goto check;
        case 6:
            texture = properties->Find(properties->second, index, found);
            break;
        case 7:
            texture = properties->Find(properties->first, index, found);
            break;
        case 8:
            texture = properties->secondary;
        check:
            if (!texture || !texture->active)
                goto finish;
            break;
        }
        if (texture)
        {
            data = texture->data;
            dimension = texture->dimension;
            format = texture->format;
            if ((selector & 0xf0000000) == 0x10000000)
                DispatchByIndex(texture, (unsigned int)descriptor, (unsigned int)descriptor->QueryFlagB(), field18);
        }
    }
finish:
    descriptor->data = data;
    descriptor->ApplyPairToState(dimension);
    descriptor->NiD3DTextureStage_SetFilterMode(format);
}
