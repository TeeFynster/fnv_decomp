#include <windows.h>
#include <d3d9.h>
#include "../../../../include/NiDX9RenderState.h"

// the shared NiTArray first: NiNode.h then takes it (its own copy is only for units without one)
#include "../../../../include/NiTArray.h"
// gamebryo2.2/corelibs/niconsolerenderer/nid3dpass.cpp: NiD3DPass, Node, MyCls, Shader and more (53 functions)

#include "../../../../include/NiD3DPass.h"
#include "layout_support.h"
#include "nid3dpass_types_NiTArray_NiPointer_NiD3DTextureStage__NiTNewInterface_NiPointer_NiD3DTextureStage_____.h"
#include "nid3dpass_decls.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/Bound.h"
#include "../../../../include/NiTransform.h"
__forceinline NiTransform::NiTransform() {}
// 0x00ee6df8 writes a four-float D3D transform result; caller overwrites w with scale.
struct D3dxTransformResult_00ee6df8 { float x, y, z, w; };
#include "../../../../include/NiTexture.h"
#include "../../../../include/BSShader.h"
#include "../../../../include/NiDX9AdditionalDepthStencilBufferData.h"

// Stores renderer in DAT_0126f710 and, if non-null, copies the pointer at offset 0x8b8 into DAT_0126f714, otherwise clears DAT_0126f714.
// @fnv 0x00e7eea0
void NiD3DPass::SetActiveRenderer(void* renderer)
{
    DAT_0126f710 = renderer;
    if (renderer)
        DAT_0126f714 = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(renderer) + 0x8b8);
    else
        DAT_0126f714 = 0;
}

// Releases every NiPointer slot in the array, decrementing each object's refcount and returning it to the pool at zero, then resets the size fields.
// @fnv 0x00e7fc30
void NiTArray_NiPointer_NiD3DTextureStage__NiTNewInterface_NiPointer_NiD3DTextureStage_____ ::RemoveAll()
{
    NiTArray_NiPointer_NiD3DTextureStage__NiTNewInterface_NiPointer_NiD3DTextureStage_____* array = this;
    unsigned int index = 0;
    if (index < array->m_usSize)
    {
        do
        {
            NiPointer<BeamStage>* slot = array->m_pBase + static_cast<unsigned short>(index);
            BeamStage* stage = slot->m_pObject;
            if (stage)
            {
                --stage->m_uiRefCount;
                if (stage->m_uiRefCount == 0)
                    stage->ReturnToPool();
                slot->m_pObject = 0;
            }
            ++index;
        } while (static_cast<unsigned short>(index) < array->m_usSize);
    }
    m_usSize = 0;
    m_usESize = 0;
}

// @fnv 0x00e7eb00
bool NiD3DPass::ApplyRenderStateChanges(bool force)
{
    NiD3DPassPoolRecord* record = reinterpret_cast<NiD3DPassPoolRecord*>(this);
    if (!force && record->state == DAT_0126f680[record->poolIndex])
        return true;
    DAT_0126f680[record->poolIndex] = record->state;
    if (record->pool->GetItemByIndex(record->poolIndex))
        return false;
    ApplyPassState();
    return true;
}

// Stores count and clears reserved, allocates an SNAEntry array of that size (or null when zero), and returns this.
// @fnv 0x00e7f0f0
NiD3DPass* NiD3DPass::SetD3DDevice(unsigned int count)
{
    NiD3DPassAllocation* allocation = reinterpret_cast<NiD3DPassAllocation*>(this);
    allocation->count = count;
    allocation->reserved = 0;
    if (count > 0)
        allocation->entries = new SNAEntry[count];
    else
        allocation->entries = 0;
    return this;
}

// @fnv 0x00e804d0
void NiD3DPass::CreateD3DPass(NiPointer<NiD3DPass>& output)
{
    NiD3DPass* pass = DAT_0126f72c->Get();
    if (pass)
        ++pass->m_uiRefCount;
    if (!pass->m_bRendererOwned)
        pass->m_bRendererOwned = true;
    D3DRenderStateGroup* group = D3DRenderStateGroup::GetCurrentRenderStateGroup();
    if (pass->m_pkRenderStateGroup != group)
        D3DRenderStateGroup::ReleaseRenderStateGroup(pass->m_pkRenderStateGroup);
    pass->m_pkRenderStateGroup = group;
    if (output.m_pObject != pass)
    {
        NiD3DPass* old = output.m_pObject;
        if (old && --old->m_uiRefCount == 0)
            old->DestroyPass();
        output.m_pObject = pass;
        ++pass->m_uiRefCount;
    }
    if (--pass->m_uiRefCount == 0)
        pass->DestroyPass();
}

// @fnv 0x00e80190
void NiD3DPass::DestroyPass()
{
    if (!m_bRendererOwned)
    {
        typedef void(__thiscall * Destroy)(NiD3DPass*, unsigned int);
        reinterpret_cast<Destroy>((*reinterpret_cast<void***>(this))[0])(this, 1);
        return;
    }
    {
        NiD3DPassRefObject* object = reinterpret_cast<NiD3DPassRefObject*>(m_spPixelConstantMap.m_pObject);
        if (object)
        {
            if (InterlockedDecrement(&object->refs) == 0)
                object->DeleteThis();
            m_spPixelConstantMap.m_pObject = 0;
        }
    }
    {
        NiD3DPassRefObject* object = reinterpret_cast<NiD3DPassRefObject*>(m_spPixelShader.m_pObject);
        if (object)
        {
            if (InterlockedDecrement(&object->refs) == 0)
                object->DeleteThis();
            m_spPixelShader.m_pObject = 0;
        }
    }
    {
        NiD3DPassRefObject* object = reinterpret_cast<NiD3DPassRefObject*>(m_spVertexConstantMap.m_pObject);
        if (object)
        {
            if (InterlockedDecrement(&object->refs) == 0)
                object->DeleteThis();
            m_spVertexConstantMap.m_pObject = 0;
        }
    }
    {
        NiD3DPassRefObject* object = reinterpret_cast<NiD3DPassRefObject*>(m_spVertexShader.m_pObject);
        if (object)
        {
            if (InterlockedDecrement(&object->refs) == 0)
                object->DeleteThis();
            m_spVertexShader.m_pObject = 0;
        }
    }
    D3DRenderStateGroup::ReleaseRenderStateGroup(m_pkRenderStateGroup);
    m_pkRenderStateGroup = 0;
    NiFree(m_pcPixelShaderProgramFile);
    m_pcPixelShaderProgramFile = 0;
    NiFree(m_pcPixelShaderEntryPoint);
    m_pcPixelShaderEntryPoint = 0;
    NiFree(m_pcPixelShaderTarget);
    m_pcPixelShaderTarget = 0;
    NiFree(m_pcVertexShaderProgramFile);
    m_pcVertexShaderProgramFile = 0;
    NiFree(m_pcVertexShaderEntryPoint);
    m_pcVertexShaderEntryPoint = 0;
    NiFree(m_pcVertexShaderTarget);
    m_pcVertexShaderTarget = 0;
    reinterpret_cast<NiTArray_NiPointer_NiD3DTextureStage__NiTNewInterface_NiPointer_NiD3DTextureStage_____*>(
        &m_kStages)
        ->RemoveAll();
    m_uiCurrentStage = 0;
    m_uiStageCount = 0;
    m_uiTexturesPerPass = 0;
    m_bSoftwareVP = false;
    D3DRenderStateGroup* object = reinterpret_cast<D3DRenderStateGroup*>(this);
    reinterpret_cast<NiTSet<D3DRenderStateGroup*, NiTMallocInterface<D3DRenderStateGroup*> >*>(DAT_0126f72c)
        ->Add(object);
}

struct Node_00e7f000
{
    int key;
    int val;
    Node_00e7f000* next;
};

struct Self_00e7f000
{
    int pad0;
    int pad1;
    Node_00e7f000* list1;
    int pad3;
    Node_00e7f000* list2;
};

// Searches list1 then list2 for a node whose key matches, sets foundInSecond to indicate which list matched, and returns the node or null.
// @fnv 0x00e7f000
Node_00e7f000* __fastcall FindNodeByKey(Self_00e7f000* self, int, int key, bool& foundInSecond)
{
    for (Node_00e7f000* pNode = self->list1; pNode; pNode = pNode->next)
    {
        if (pNode->key == key)
        {
            foundInSecond = false;
            return pNode;
        }
    }
    for (Node_00e7f000* pNode = self->list2; pNode; pNode = pNode->next)
    {
        if (pNode->key == key)
        {
            foundInSecond = true;
            return pNode;
        }
    }
    return 0;
}


extern MemoryManager g_memoryManager;

// Releases each NiPointer element in the array, returning objects whose refcount drops to zero to the pool, then deallocates the array block.
// @fnv 0x00e7fcd0
void __cdecl FreePointerArray(NiPointer<BeamStage>* pkElement)
{
    if (pkElement)
    {
        int iCount = ((int*)pkElement)[-1];
        void* pvBase = (int*)pkElement - 1;
        NiPointer<BeamStage>* pkCur = pkElement + iCount;
        while (--iCount >= 0)
        {
            --pkCur;
            BeamStage* pkStage = pkCur->m_pObject;
            if (pkStage)
            {
                if (--pkStage->m_uiRefCount == 0)
                    pkStage->ReturnToPool();
            }
        }
        g_memoryManager.Deallocate(pvBase);
    }
}

void* __cdecl NiTObjectArray_NiPointer_NiScreenTexture_NiTObjectArray_NiPointer_NiScreenTexture(unsigned int);
extern int DAT_010ef35c;
extern int DAT_010ef378;

// @fnv 0x00e80020
// src: COMMUNITY 0x00e80020
void* __fastcall NiTObjectArray_NiPointer_NiD3DTextureStage_Init(void* pThis, int, unsigned int uiMaxSize, unsigned int uiGrowBy)
{
    *(int**)pThis = &DAT_010ef35c;
    unsigned short usMaxSize = (unsigned short)uiMaxSize;
    *(unsigned short*)((char*)pThis + 0x8) = usMaxSize;
    *(unsigned short*)((char*)pThis + 0xe) = (unsigned short)uiGrowBy;
    *(unsigned short*)((char*)pThis + 0xa) = 0;
    *(unsigned short*)((char*)pThis + 0xc) = 0;
    if (usMaxSize > 0)
        *(void**)((char*)pThis + 4) = NiTObjectArray_NiPointer_NiScreenTexture_NiTObjectArray_NiPointer_NiScreenTexture(usMaxSize);
    else
        *(void**)((char*)pThis + 4) = 0;
    *(int**)pThis = &DAT_010ef378;
    return pThis;
}

#include "../../../../include/NiMemObject.h"

void __fastcall FUN_00e7fea0(void* pThis);
void __cdecl NiMemObject_ReleaseStorage_00aa1490(void* pMem, size_t stElementSize);

// Destroys an array of 0x68-byte elements, calling FUN_00e7fea0 on each and freeing the base block when flags has bit 1 set.
// @fnv 0x00e80080
void* __fastcall FUN_00e80080(char* pThis, int, unsigned int flags)
{
    if (flags & 2)
    {
        int count = *((int*)pThis - 1);
        void* base = pThis - 4;
        char* p = pThis + count * 0x68;
        while (--count >= 0)
        {
            p -= 0x68;
            FUN_00e7fea0(p);
        }
        if (flags & 1)
        {
            NiMemObject_ReleaseStorage_00aa1490(base, 0x68);
        }
        return base;
    }
    FUN_00e7fea0(pThis);
    if (flags & 1)
    {
        NiMemObject::operator delete(pThis, 0x68);
    }
    return pThis;
}

namespace fnv_00e80150 {

extern MemoryManager g_memoryManager;
extern unsigned int* _DAT_0126f72c;

// Allocates a 0x18-byte block, zeroes its first four words, sets words 4 and 5 to 8, and stores it in _DAT_0126f72c (or stores null on failure).
// @fnv 0x00e80150
// src: COMMUNITY 0x00e80150
void __cdecl NiD3DPass_InitializePools()
{
    unsigned int* p = (unsigned int*)g_memoryManager.Allocate(0x18);
    if (p != 0)
    {
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p[4] = 8;
        p[5] = 8;
        _DAT_0126f72c = p;
        return;
    }
    _DAT_0126f72c = 0;
}
}  // namespace fnv_00e80150

extern NiTexture* DAT_011f9510;
extern NiTexture* DAT_011f9518;
// Returns the NiTexture at index idx from the array at obj+0xb0, falling back to a default texture based on the flag at obj+0x20.
// @fnv 0x00c03230
NiTexture* __stdcall GetTextureByIndex(char* apObject, int aiIndex)
{
    NiTexture* pTexture = (*(NiTexture***)(apObject + 0xb0))[aiIndex];
    if (!pTexture)
    {
        pTexture = DAT_011f9518;
        if ((*(unsigned int*)(apObject + 0x20) & 0x80) <= 0)
            pTexture = DAT_011f9510;
    }
    return pTexture;
}

struct GlobalObjectO2_00a7b610
{
    int x;
};
extern GlobalObjectO2_00a7b610 g_0126f5c4;
// @fnv 0x00e7d9c0
// src: COMMUNITY 0x00e7d9c0
GlobalObjectO2_00a7b610* __cdecl NiDX9AdditionalDepthStencilBufferData_GetRTTI()
{
    return &g_0126f5c4;
}

namespace fnv_00e7e7a0 {
extern MemoryManager g_memoryManager;
void __fastcall ReleaseStorage_00e7ec60(void*);
// @fnv 0x00e7e7a0
void* __fastcall FUN_00e7e7a0(void* self, int edx, unsigned int flags)
{
    ReleaseStorage_00e7ec60(self);
    if (flags & 1)
        g_memoryManager.Deallocate(self);
    return self;
}
}  // namespace fnv_00e7e7a0

namespace fnv_00e7f050 {
extern MemoryManager g_memoryManager;
void __fastcall NiD3DPass_ReleaseStorage_00e7f070(void*);
// Calls FUN_00e7f070 on self, then deallocates self via g_memoryManager when flags has bit 1 set, and returns self.
// @fnv 0x00e7f050
void* __fastcall FUN_00e7f050(void* self, int edx, unsigned int flags)
{
    NiD3DPass_ReleaseStorage_00e7f070(self);
    if (flags & 1)
        g_memoryManager.Deallocate(self);
    return self;
}
}  // namespace fnv_00e7f050

namespace fnv_00e7f070 {
extern MemoryManager g_memoryManager;
void __cdecl NiMemObject_ReleaseStorage_00aa1490(void* pMem, unsigned int stElementSize);
// @fnv 0x00e7f070
// src: GUESS 0x00e7f070 (confidence: low)
void __fastcall NiD3DPass_ReleaseStorage_00e7f070(void* apList)
{
    NiMemObject_ReleaseStorage_00aa1490(*(void**)apList, 0x10);
    void* next = ((void**)apList)[2];
    if (next)
    {
        NiD3DPass_ReleaseStorage_00e7f070(next);
        g_memoryManager.Deallocate(next);
    }
}
}  // namespace fnv_00e7f070

void __fastcall NiD3DRenderStateGroup_RestoreRenderStates(void*);
struct PassLike
{
    char pad[0x30];
    void* m_p;
};
// @fnv 0x00e7f7d0
// src: XBOX_PDB 0x00e7f7d0
unsigned int __fastcall NiD3DPass_PostProcessRenderingPass(PassLike* self, int edx, unsigned int uiPass)
{
    if (self->m_p)
        NiD3DRenderStateGroup_RestoreRenderStates(self->m_p);
    return 0;
}

extern int DAT_011bf558;
// @fnv 0x00e7f830
// src: COMMUNITY 0x00e7f830
void __cdecl NiD3DPass_SetMaxTextureBlendStages(int v)
{
    DAT_011bf558 = v;
}

extern int DAT_011bf55c;
// @fnv 0x00e7f840
// src: COMMUNITY 0x00e7f840
void __cdecl NiD3DPass_SetMaxSimultaneousTextures(int v)
{
    DAT_011bf55c = v;
}

extern int DAT_011bf560;
// @fnv 0x00e7f850
// src: COMMUNITY 0x00e7f850
void __cdecl NiD3DPass_SetMaxSamplers(int v)
{
    DAT_011bf560 = v;
}

namespace fnv_00e7f900 {
extern MemoryManager g_memoryManager;
void __fastcall DestroyNode(void*);
// @fnv 0x00e7f900
void* __fastcall FUN_00e7f900(void* self, int edx, unsigned int flags)
{
    DestroyNode(self);
    if (flags & 1)
        g_memoryManager.Deallocate(self);
    return self;
}
}  // namespace fnv_00e7f900

extern int DAT_0126f720;
extern int DAT_0126f724;
extern int DAT_0126f728;

// @fnv 0x00e7f920
// src: COMMUNITY 0x00e7f920
void __cdecl NiD3DPass_SetD3DRenderer(int pObject)
{
    DAT_0126f724 = pObject;
    if (pObject)
    {
        int state = *(int*)((char*)pObject + 0x288);
        if (DAT_0126f720)
        {
            int obj = DAT_0126f720;
            int vtbl = *(int*)obj;
            void(__stdcall * release)(int) = (void(__stdcall*)(int)) * ((int*)vtbl + 2);
            release(obj);
        }
        DAT_0126f720 = state;
        if (state)
        {
            int obj = state;
            int vtbl = *(int*)obj;
            void(__stdcall * addRef)(int) = (void(__stdcall*)(int)) * ((int*)vtbl + 1);
            addRef(obj);
        }
        DAT_0126f728 = *(int*)((char*)DAT_0126f724 + 0x8b8);
    }
    else
    {
        if (DAT_0126f720)
        {
            int obj = DAT_0126f720;
            int vtbl = *(int*)obj;
            void(__stdcall * release)(int) = (void(__stdcall*)(int)) * ((int*)vtbl + 2);
            release(obj);
        }
        DAT_0126f720 = 0;
        DAT_0126f728 = 0;
    }
}

extern int DAT_011bf558;
struct SubArr
{
    char d[0x10];
    void NiTObjectArray_NiPointer_NiD3DTextureStage_Init(unsigned int, unsigned int);
};
struct FUN_00e800f0
{
    virtual ~FUN_00e800f0();
    bool b4;
    int pad8[3];
    int f14, f18, f1c;
    SubArr sub;
    int f30, f34, f38, f3c, f40, f44, f48;
    char b4c;
    int f50, f54, f58, f5c;
    char b60, b61;
    int f64;
    FUN_00e800f0();
};
// @fnv 0x00e800f0
FUN_00e800f0::FUN_00e800f0()
{
    f14 = 0;
    f18 = 0;
    f1c = 0;
    sub.NiTObjectArray_NiPointer_NiD3DTextureStage_Init(DAT_011bf558, 4);
    f30 = 0;
    f34 = 0;
    f38 = 0;
    f3c = 0;
    f40 = 0;
    f44 = 0;
    f48 = 0;
    b4c = 0;
    f50 = 0;
    f54 = 0;
    f58 = 0;
    f5c = 0;
    b60 = 0;
    b61 = 0;
    f64 = 0;
    b4 = 0;
}

extern "C" int __cdecl AllocatePoolItem();

struct FUN_00e7dc60_struct
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    unsigned short m_5c;
    unsigned char m_5e;
    unsigned char m_5f;
    int m_60;
    unsigned char m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;

    FUN_00e7dc60_struct* Initialize();
};

// Zeroes several fields, sets m_64 to 1, stores the result of AllocatePoolItem in m_10, and returns this.
// @fnv 0x00e7dc60
FUN_00e7dc60_struct* FUN_00e7dc60_struct::Initialize()
{
    m_04 = 0;
    m_0c = 0;
    m_14 = 0;
    m_18 = 0;
    m_5c = 0;
    m_5e = 0;
    m_5f = 0;
    m_60 = 0;
    m_64 = 1;
    m_10 = AllocatePoolItem();
    return this;
}

struct Dummy00e7dc40
{
    void ReleaseStorage_00e7dbc0();
    void* FUN_00e7dc40(unsigned int);
};
void __cdecl _delete(void*, unsigned int);
// Calls FUN_00e7dbc0, then if bit 0 of flags is set frees this with _delete, and returns this.
// @fnv 0x00e7dc40
void* Dummy00e7dc40::FUN_00e7dc40(unsigned int flags)
{
    ReleaseStorage_00e7dbc0();
    if (flags & 1)
        _delete(this, 0x28);
    return this;
}

struct Holder_00e89060
{
    bool GetSlotValue(int, void*&, bool&);
};
struct Outer_00e7ddf0
{
    char _0[4];
    void* m4;
    char _8[8];
    Holder_00e89060* m10;
    void* NiD3DTextureStage_GetTexCoordIndex();
};
// Calls GetSlotValue with key 11 and returns the resulting pointer if it succeeds, otherwise returns m4.
// @fnv 0x00e7ddf0
// src: COMMUNITY 0x00e7ddf0
void* Outer_00e7ddf0::NiD3DTextureStage_GetTexCoordIndex()
{
    void* pResult = 0;
    bool b = false;
    return m10->GetSlotValue(11, pResult, b) ? pResult : m4;
}

extern int EmptyFS;
void __cdecl RemoveGlobalConstant(char**);
void __cdecl ResetAndRegister(void*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct Holder00e7de30
{
    int _0;
    int _4;
    char* _8;
};
struct This00e7de30
{
    char _00[16];
    void* _10;
    char _14[4];
    Holder00e7de30* _18;
    void UpdateReferenceState_00e7de30();
};
// @fnv 0x00e7de30
// src: GUESS 0x00e7de30 (confidence: low)
void This00e7de30::UpdateReferenceState_00e7de30()
{
    Holder00e7de30* p = _18;
    if (p)
    {
        if (p->_8 != *(char**)&EmptyFS)
            InterlockedIncrement((volatile long*)(p->_8 - 8));
        char* tmp = p->_8;
        RemoveGlobalConstant(&tmp);
        if (tmp != *(char**)&EmptyFS)
            InterlockedDecrement((volatile long*)(tmp - 8));
    }
    ResetAndRegister(_10);
}

namespace fnv_00e7fc80 {
extern MemoryManager g_memoryManager;
struct Obj
{
    virtual void Foo(int);
};
struct Node
{
    Obj* p0;
    int unk4;
    Node* p8;
    void DestroyNode();
};
// @fnv 0x00e7fc80
void Node::DestroyNode()
{
    if (p0)
    {
        if (*(int*)((char*)p0 - 4) != 0)
            p0->Foo(3);
        else
            g_memoryManager.Deallocate((char*)p0 - 4);
    }
    Node* next = p8;
    if (next)
    {
        next->DestroyNode();
        g_memoryManager.Deallocate(next);
    }
}
}  // namespace fnv_00e7fc80

namespace fnv_00e7fe70 {
extern MemoryManager g_memoryManager;
extern int DAT_010ef35c;
void __cdecl FreePointerArray(void*);
struct S
{
    int vfptr;
    void* ptr;
    void* FUN_00e7fe70(unsigned int);
};
// @fnv 0x00e7fe70
void* S::FUN_00e7fe70(unsigned int auiFlags)
{
    void* tmp = ptr;
    vfptr = (int)&DAT_010ef35c;
    FreePointerArray(tmp);
    if (auiFlags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00e7fe70

extern short DAT_0126f958[];

struct FUN_00e89060_shell
{
    char m_00[0x0c];
    char m_0c[0x20];
    char m_2c;
    char m_2d[0x2f];
    char m_5c;
    char m_5d[0x1f];
    int m_7c;
    int m_80[2];
    bool GetSlotValue(int index, int* out, bool* flag);
};

// @fnv 0x00e89060
bool FUN_00e89060_shell::GetSlotValue(int index, int* apiOut, bool* apbFlag)
{
    if ((unsigned short)DAT_0126f958[index] < 8)
    {
        unsigned int i = (unsigned short)DAT_0126f958[index];
        if (reinterpret_cast<char*>(this)[i + 0x5c])
        {
            *apiOut = reinterpret_cast<int*>(this)[i + 0x0f];
            *apbFlag = false;
            return true;
        }
        if (reinterpret_cast<char*>(this)[i + 0x2c])
        {
            *apiOut = reinterpret_cast<int*>(this)[i + 0x03];
            *apbFlag = true;
            return true;
        }
    }
    return false;
}

namespace fnv_00e7f7f0 {
extern unsigned int DAT_011bf558;
extern unsigned int DAT_011bf55c;
struct DummyStruct
{
    unsigned char _pad0[0x14];
    unsigned int m14;
    unsigned int _pad1;
    unsigned int m1c;
    unsigned char NiD3DPass_CheckFreeStages(unsigned int, unsigned int);
};
// @fnv 0x00e7f7f0
// src: COMMUNITY 0x00e7f7f0
unsigned char DummyStruct::NiD3DPass_CheckFreeStages(unsigned int a1, unsigned int a2)
{
    if (DAT_011bf558 < a1 + m14)
        return 0;
    if (DAT_011bf55c < m1c + a2)
        return 0;
    return DAT_011bf55c >= m14 + a2;
}
}  // namespace fnv_00e7f7f0

void* __cdecl _NiMalloc(unsigned int);
void* __cdecl _memmove(void*, const void*, unsigned int);
struct MyCls
{
    char _pad[0x28];
    unsigned int m28;
    unsigned int m2c;
    void* m30;
    bool m34;
    void SetBuffer(unsigned int, unsigned int, void*, bool);
};
// @fnv 0x00e81ca0
void MyCls::SetBuffer(unsigned int uiSize, unsigned int a1, void* pData, bool bCopy)
{
    m28 = uiSize;
    m2c = a1;
    if (bCopy)
    {
        m34 = true;
        NiFree(m30);
        void* p = _NiMalloc(uiSize);
        m30 = p;
        _memmove(p, pData, uiSize);
    }
    else
    {
        m34 = false;
        m30 = pData;
    }
}

inline void DecRef_e7fd20(BeamStage* p)
{
    if (--p->m_uiRefCount == 0)
        p->ReturnToPool();
}

struct TexPtr_e7fd20
{
    BeamStage* m_pObject;
    TexPtr_e7fd20(BeamStage* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->m_uiRefCount++;
    }
    ~TexPtr_e7fd20()
    {
        if (m_pObject)
            DecRef_e7fd20(m_pObject);
    }
    TexPtr_e7fd20& operator=(BeamStage* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                DecRef_e7fd20(m_pObject);
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->m_uiRefCount++;
        }
        return *this;
    }
    TexPtr_e7fd20& operator=(const TexPtr_e7fd20& kPtr)
    {
        if (m_pObject != kPtr.m_pObject)
        {
            if (m_pObject)
                DecRef_e7fd20(m_pObject);
            m_pObject = kPtr.m_pObject;
            if (m_pObject)
                m_pObject->m_uiRefCount++;
        }
        return *this;
    }
    bool operator!=(const TexPtr_e7fd20& kPtr) const
    {
        return m_pObject != kPtr.m_pObject;
    }
};

void* __cdecl NiTObjectArray_NiPointer_NiScreenTexture_NiTObjectArray_NiPointer_NiScreenTexture(unsigned int ItemUpdateArray);
void __cdecl FreePointerArray(TexPtr_e7fd20* pBase);

struct TexArray_e7fd20
{
    void* m_pVtbl;
    TexPtr_e7fd20* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void NiD3DPass_SetAtGrow(unsigned int uiMaxSize);
};

// Resizes the array to uiMaxSize: releases entries above the new size, reallocates the base, copies existing entries and clears the rest.
// @fnv 0x00e7fd20
// src: COMMUNITY 0x00e7fd20
void TexArray_e7fd20::NiD3DPass_SetAtGrow(unsigned int uiMaxSize)
{
    if (uiMaxSize == m_usMaxSize)
        return;

    unsigned short i;
    if (uiMaxSize < m_usSize)
    {
        for (i = (unsigned short)uiMaxSize; i < m_usSize; i++)
        {
            if (m_pBase[i] != TexPtr_e7fd20(0))
            {
                m_pBase[i] = (BeamStage*)0;
                m_usESize--;
            }
        }
        m_usSize = (unsigned short)uiMaxSize;
    }

    TexPtr_e7fd20* pOldEntries = m_pBase;
    m_usMaxSize = (unsigned short)uiMaxSize;
    if (uiMaxSize > 0)
    {
        m_pBase = (TexPtr_e7fd20*)NiTObjectArray_NiPointer_NiScreenTexture_NiTObjectArray_NiPointer_NiScreenTexture(m_usMaxSize);
        for (i = 0; i < m_usSize; i++)
            m_pBase[i] = pOldEntries[i];
        for (i = m_usSize; i < m_usMaxSize; i++)
            m_pBase[i] = (BeamStage*)0;
    }
    else
    {
        m_pBase = 0;
    }

    FreePointerArray(pOldEntries);
}

extern int DAT_0126f6c0;
extern int DAT_0126f6c4;
extern int DAT_0126f6c8;

// @fnv 0x00e7e8d0
// src: COMMUNITY 0x00e7e8d0
void NiD3DTextureStage_SetD3DRenderer(int pObject)
{
    DAT_0126f6c4 = pObject;
    if (pObject)
    {
        int pNewObject = *(int*)(pObject + 0x288);
        if (DAT_0126f6c0)
        {
            typedef void(__stdcall * ReleaseFunction)(int);
            ReleaseFunction release = (ReleaseFunction) * (int**)(*(int**)DAT_0126f6c0 + 2);
            release(DAT_0126f6c0);
        }
        DAT_0126f6c0 = pNewObject;
        if (pNewObject)
        {
            typedef void(__stdcall * AddRefFunction)(int);
            AddRefFunction addRef = (AddRefFunction) * (int**)(*(int**)pNewObject + 1);
            addRef(pNewObject);
        }
        DAT_0126f6c8 = *(int*)(DAT_0126f6c4 + 0x8b8);
    }
    else
    {
        if (DAT_0126f6c0)
        {
            typedef void(__stdcall * ReleaseFunction)(int);
            ReleaseFunction release = (ReleaseFunction) * (int**)(*(int**)DAT_0126f6c0 + 2);
            release(DAT_0126f6c0);
        }
        DAT_0126f6c0 = 0;
        DAT_0126f6c8 = 0;
    }
}

extern int DAT_0126f9a0;

// @fnv 0x00e89670
void ResetAndRegister(D3DRenderStateGroup* apObject)
{
    if (*reinterpret_cast<unsigned char*>(apObject) != 0)
    {
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x0c) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x10) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x14) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x18) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x1c) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x20) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x24) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x28) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x2c) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x30) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x3c) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x40) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x44) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x48) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x4c) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x50) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x54) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x58) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x5c) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x60) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x6c) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x70) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x74) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x78) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x7c) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x80) = 0;
        *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(apObject) + 0x84) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x90) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x94) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x98) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x9c) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0xa0) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0xa4) = 0;
        *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(apObject) + 0xa8) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0xb0) = 0;
        *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(apObject) + 0xb4) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x34) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x04) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x88) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0x64) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(apObject) + 0xac) = 0;

        D3DRenderStateGroup* group = apObject;
        reinterpret_cast<NiTSet<D3DRenderStateGroup*, NiTMallocInterface<D3DRenderStateGroup*> >*>(DAT_0126f9a0)
            ->Add(group);
    }
}

struct Matrix4
{
    float m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33;
};
struct Texture
{
    int unk00;
};
struct TextureRef
{
    Texture* value;
};
struct Geometry
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
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
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual int v56();
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
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    NiTransform transform;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    TextureRef* texture;
};
struct Arg
{
    int unk00, unk04, unk08;
    Geometry* geometry;
};
struct TextureStage
{
    int unk00, unk04;
    Texture* texture;
    void ApplyPairToState(int);
    void FUN_00e7eb00(int);
};
struct Pass
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    TextureStage** stages;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
    void* target;
};
extern Pass* DAT_0126f74c;
extern Geometry** DAT_011f91e0;
struct Device
{
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void Draw(void*, int, int, int, int, int, int, NiTransform*, Bound*, int, int);
};
void __cdecl BSUtilities_GetInverseWorldMatrix(NiTransform*, int, Matrix4*);
struct Shader
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    Device* device;
    Texture* GetTextureByIndex(Geometry*, int);
    void ShadowLightShader_SetupGeometryOpt_WorldViewProj(Geometry*, NiTransform*);
    void UpdateLightShaderConstants(Matrix4*, float);
    void SetupTextureStages(Arg*);
};
// Assigns textures to both texture stages from the geometry, builds a matrix from DAT_011f91e0[0]'s transform, and draws the pass target through the device.
// @fnv 0x00b7ded0
void Shader::SetupTextureStages(Arg* arg)
{
    Geometry* geometry = arg->geometry;
    TextureStage* stage = DAT_0126f74c->stages[0];
    stage->texture = geometry->texture->value;
    stage->ApplyPairToState(geometry->v56());
    stage = DAT_0126f74c->stages[1];
    stage->texture = GetTextureByIndex(geometry, 0);
    stage->ApplyPairToState(geometry->v56());
    DAT_0126f74c->stages[0]->FUN_00e7eb00(0);
    DAT_0126f74c->stages[1]->FUN_00e7eb00(0);
    Geometry* source = DAT_011f91e0[0];
    NiTransform* transform = &source->transform;
    Matrix4 matrix;
    BSUtilities_GetInverseWorldMatrix(transform, 0, &matrix);
    ShadowLightShader_SetupGeometryOpt_WorldViewProj(source, transform);
    UpdateLightShaderConstants(&matrix, transform->m_fScale);
    // The draw call receives uninitialized scratch storage; no constructor runs.
    float boundStorage[sizeof(Bound) / sizeof(float)];
    Bound& bound = *reinterpret_cast<Bound*>(boundStorage);
    NiTransform output;
    Device* active = device;
    if (active && DAT_0126f74c->target)
        active->Draw(DAT_0126f74c->target, 0, 0, 0, 0, 0, 0, &output, &bound, 0, 1);
}

// NiDX9AdditionalDepthStencilBufferData's constructor: the base constructors are
// inline; the object is then linked into the global list of live objects.
//
// The list node allocated by the pool allocator keeps a back pointer, a forward
// pointer and a back-pointer to the owning object.

struct NiDSBListNode
{
    NiDSBListNode* m_pSecondNode;
    NiDSBListNode* m_next;
    void* m_pOwnerObject;
};

inline NiRefObject::NiRefObject()
{
    m_uiRefCount = 0;
    InterlockedIncrement((volatile long*)&ms_lObjectCount);
}

inline Ni2DBuffer::RendererData::RendererData() throw() : m_pkBuffer(0), m_pkPixelFormat(0)
{
}

// Head / tail of the global list of live objects.
extern NiDSBListNode* DAT_0126f5cc;
extern NiDSBListNode* DAT_0126f5d0;

// The pool object and the critical section that guards the list.
extern int DAT_0126f5d4;
extern int DAT_0126f600;


// Pool allocator: hands out a fresh, zeroed list node.
extern NiDSBListNode* __fastcall NiDSBPoolAddHead(void* pPool);

// Runs the inline base constructors, clears the D3D format, then under a critical section allocates a list node and links it into the global list.
// @fnv 0x00e7d940
NiDX9AdditionalDepthStencilBufferData::NiDX9AdditionalDepthStencilBufferData() throw() : m_eCreateFormat(0)
{
    EnterCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(&DAT_0126f600));
    NiDSBListNode* pNode = NiDSBPoolAddHead(&DAT_0126f5d4);
    pNode->m_pOwnerObject = this;
    pNode->m_next = 0;
    pNode->m_pSecondNode = DAT_0126f5cc;
    if (DAT_0126f5cc)
        DAT_0126f5cc->m_next = pNode;
    else
        DAT_0126f5d0 = pNode;
    DAT_0126f5d4 = DAT_0126f5d4 + 1;
    DAT_0126f5cc = pNode;
    LeaveCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(&DAT_0126f600));
}

extern int DAT_011bf558;
extern int DAT_011bf560;
extern int DAT_0126f6c8;

class DispatchObject
{
  public:
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30(int a, int b, int c, int d);
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v_dc(int a, int b);
};

// For each index from start up to DAT_011bf558, calls v_dc and v30 with fixed arguments; then calls v_dc for remaining indices up to DAT_011bf560.
// @fnv 0x00e7dd50
// src: COMMUNITY 0x00e7dd50
void __cdecl NiD3DTextureStage_DisableStage(int start)
{
    unsigned int i = (unsigned int)start;
    if (i < (unsigned int)DAT_011bf558)
    {
        do
        {
            DispatchObject* obj = (DispatchObject*)DAT_0126f6c8;
            obj->v_dc((int)i, 0);
            obj = (DispatchObject*)DAT_0126f6c8;
            obj->v30((int)i, 1, 1, 0);
            obj = (DispatchObject*)DAT_0126f6c8;
            obj->v30((int)i, 4, 1, 0);
            obj = (DispatchObject*)DAT_0126f6c8;
            obj->v30((int)i, 0x18, 0, 0);
        } while (++i < (unsigned int)DAT_011bf558);
    }
    while (i < (unsigned int)DAT_011bf560)
    {
        DispatchObject* obj = (DispatchObject*)DAT_0126f6c8;
        obj->v_dc((int)i, 0);
        ++i;
    }
}

struct E7DE90State
{
    void NiD3DTextureStageGroup_SetSamplerState(unsigned int uiStage, unsigned int uiValue, unsigned int uiExtra, bool bFlag);
};

struct E7DE90Pair
{
    unsigned int uiFirst;
    unsigned int uiSecond;
};

extern E7DE90Pair g_aE7DE90Pairs[];

class E7DE90Owner
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    E7DE90State* m_pkState;

    void ApplyPairToState(unsigned int uiIndex);
};

// Looks up the pair at uiIndex and passes its first and second values to the state object as stages 1 and 2.
// @fnv 0x00e7de90
void E7DE90Owner::ApplyPairToState(unsigned int uiPairIndex)
{
    E7DE90Pair kPair = g_aE7DE90Pairs[uiPairIndex];
    m_pkState->NiD3DTextureStageGroup_SetSamplerState(1, kPair.uiFirst, 0, false);
    kPair = g_aE7DE90Pairs[uiPairIndex];
    m_pkState->NiD3DTextureStageGroup_SetSamplerState(2, kPair.uiSecond, 0, false);
}

struct E7DEF0ClampEntry
{
    unsigned int m_uiAddressV;
    unsigned int m_uiAddressU;
    unsigned int m_uiAddressW;
};

class E7DEF0TextureState
{
  public:
    void SetSamplerState(unsigned int uiState, unsigned int uiValue, unsigned int uiStage, bool bSave);
};

class E7DEF0TextureStage
{
  public:
    static E7DEF0ClampEntry ms_akClampModes[];

    static E7DEF0ClampEntry GetClampEntry(int eMode)
    {
        return ms_akClampModes[eMode];
    }

    int m_eClampMode;
    int unk04;
    int unk08;
    int unk0C;
    E7DEF0TextureState* m_pkState;

    void NiD3DTextureStage_SetFilterMode(int eMode);
};

// SetClampMode
// Sets sampler states 5, 6 and 7 to the U, V and W addresses of the clamp entry for eMode, then stores eMode in m_eClampMode.
// @fnv 0x00e7def0
// src: COMMUNITY 0x00e7def0
void E7DEF0TextureStage::NiD3DTextureStage_SetFilterMode(int eMode)
{
    m_pkState->SetSamplerState(5, GetClampEntry(eMode).m_uiAddressU, 0, false);
    m_pkState->SetSamplerState(6, GetClampEntry(eMode).m_uiAddressV, 0, false);
    m_pkState->SetSamplerState(7, GetClampEntry(eMode).m_uiAddressW, 0, false);
    m_eClampMode = eMode;
}

extern int DAT_011bf558;
extern int DAT_0126f6c0;
extern int DAT_0126f6c4;
extern int DAT_0126f6c8;
extern int DAT_011a9608;
struct PassState
{
    int status;
    unsigned int handle;
    void* texture;
    int reserved;
    Holder_00e89060* holder;
    void SendDeviceCommands(void* item);
    void BindTexture();
    void ApplyPassState();
};
typedef void(__thiscall* DeviceStageFn)(void*, unsigned int, int, void*, int);
typedef void(__thiscall* DeviceStateFn)(void*, unsigned int, int);
typedef void(__thiscall* DeviceDisableFn)(void*, unsigned int, int, int, int);
typedef int(__thiscall* ObjectQueryFn)(void*, void*, char*, char*, int*);
typedef void(__stdcall* DeviceFinishFn)(void*, unsigned int, int, int);
// @fnv 0x00e7ea00
void PassState::ApplyPassState()
{
    union
    {
        bool needsStage;
        char byteA;
    };
    if (handle < (unsigned int)DAT_011bf558)
    {
        void* replacement = 0;
        needsStage = false;
        bool valid = holder->GetSlotValue(11, replacement, needsStage);
        void* chosen = valid ? replacement : (void*)handle;
        void* d = (void*)DAT_0126f6c8;
        ((DeviceStageFn)(*(void***)d)[48])(d, handle, 11, chosen, 0);
    }
    int queryResult = 0;
    char byteB;
    int resultInfo;
    if (texture)
    {
        void* service = ((void**)DAT_0126f6c4)[0x8c4 / 4];
        queryResult = ((ObjectQueryFn)(*(void***)service)[3])(service, texture, &byteA, &byteB, &resultInfo);
    }
    {
        void* d = (void*)DAT_0126f6c8;
        ((DeviceStateFn)(*(void***)d)[55])(d, handle, queryResult);
    }
    if (queryResult)
    {
        if (!byteB)
        {
            void* d = (void*)DAT_0126f6c8;
            ((DeviceDisableFn)(*(void***)d)[51])(d, handle, 7, 0, 0);
        }
        SendDeviceCommands((void*)resultInfo);
        BindTexture();
    }
    if (status == 6)
    {
        void* output = (void*)DAT_0126f6c0;
        ((DeviceFinishFn)(*(void***)output)[69])(output, handle, 10, DAT_011a9608);
    }
}

// apply every enabled pass, and clear the passes left over from a longer previous shader.

class F860RenderState
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void SetAlphaEnable(bool bEnable);
};
extern F860RenderState* g_pkF860RenderState;
extern unsigned int g_uiF860MaxPasses;
void __cdecl F860ClearPasses(unsigned int uiFirst);

class F860Material
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual bool GetAlphaEnable();
};

class F860Group
{
  public:
    void Update();
};

class F860Pass
{
  public:
    bool Apply(bool bForce);
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
    bool m_bEnableState;
};

class F860Shader
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    F860Pass** m_ppkPasses;
    unsigned short unk28;
    unsigned short m_usPassCount;
    int unk2C;
    F860Group* m_pkActorGroup;
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
    F860Material* m_pkMaterial;
    bool m_bAlphaEnable;

    unsigned int RenderShader(void* pvGeometry, void* pvSkin, void* pvPartition, void* pvRendererData,
                              void* pvProperties, void* pvEffects, void* pvWorld, void* pvBound);
};

// @fnv 0x00e7f860
unsigned int F860Shader::RenderShader(void* pvGeometry, void* pvSkin, void* pvPartition, void* pvRendererData,
                                      void* pvProperties, void* pvEffects, void* pvWorld, void* pvBound)
{
    unsigned int uiResult = 0;
    F860Material* pkMaterial = m_pkMaterial;
    if (pkMaterial)
        g_pkF860RenderState->SetAlphaEnable(pkMaterial->GetAlphaEnable());
    else
        g_pkF860RenderState->SetAlphaEnable(m_bAlphaEnable);

    if (m_pkActorGroup)
        m_pkActorGroup->Update();

    unsigned int ItemUpdateArray = m_usPassCount;
    unsigned int i;
    for (i = 0; i < ItemUpdateArray; i++)
    {
        F860Pass* pkPass = m_ppkPasses[i];
        if (!pkPass)
            break;
        if (pkPass->m_bEnableState)
            uiResult = pkPass->Apply(false);
    }
    if (i < g_uiF860MaxPasses)
        F860ClearPasses(i);
    return uiResult;
}

extern "C" void __cdecl ReleaseRenderStateGroup_e7fea0(D3DRenderStateGroup* group);

struct PassRefObject_e7fea0
{
    virtual void vfn_00();
    virtual void DeleteThis();
    long m_lRefCount;
};

inline void ReleaseRef_e7fea0(PassRefObject_e7fea0* p)
{
    if (InterlockedDecrement(&p->m_lRefCount) == 0)
        p->DeleteThis();
}

struct PassPtr_e7fea0
{
    PassRefObject_e7fea0* m_pObject;
    void DecRef()
    {
        if (m_pObject)
            ReleaseRef_e7fea0(m_pObject);
    }
    void Clear()
    {
        if (m_pObject)
        {
            ReleaseRef_e7fea0(m_pObject);
            m_pObject = 0;
        }
    }
};

typedef NiTArray<TexPtr_e7fd20, NiTMallocInterface<TexPtr_e7fd20> > StageArray_e7fea0;
template <> inline NiTArray<TexPtr_e7fd20, NiTMallocInterface<TexPtr_e7fd20> >::~NiTArray()
{
        FreePointerArray(m_pBase);
    }

struct StageArrayStorage_e7fea0
{
    void* m_pVtbl;
    TexPtr_e7fd20* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

struct FUN_00e7fea0
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned int m_uiStageMask;
    unsigned int m_uiNumberOfStages;
    unsigned int m_uiStageOffset;
    StageArrayStorage_e7fea0 m_kStageArray;
    D3DRenderStateGroup* m_pRenderStateGroup;
    PassPtr_e7fea0 m_spFirstShaderConstantMap;
    char* m_pcPixelShaderFile;
    char* m_pcPixelShaderFunction;
    char* m_pcPixelShaderProfile;
    PassPtr_e7fea0 m_spPixelShaderObject;
    PassPtr_e7fea0 m_spSecondShaderConstantMap;
    char m_bUsesSecondShaderConstantMap;
    char* m_pcVertexShaderFile;
    char* m_pcVertexShaderFunction;
    char* m_pcVertexShaderProfile;
    PassPtr_e7fea0 m_spVertexShaderObject;
    bool m_bIsInitialized;
    bool m_bHasBeenApplied;
    unsigned int m_uiRefCount;
    virtual ~FUN_00e7fea0();
};

// @fnv 0x00e7fea0
FUN_00e7fea0::~FUN_00e7fea0()
{
    ReleaseRenderStateGroup_e7fea0(m_pRenderStateGroup);
    m_spFirstShaderConstantMap.Clear();
    NiFree(m_pcPixelShaderFile);
    NiFree(m_pcPixelShaderFunction);
    NiFree(m_pcPixelShaderProfile);
    m_spPixelShaderObject.Clear();
    m_spSecondShaderConstantMap.Clear();
    NiFree(m_pcVertexShaderFile);
    NiFree(m_pcVertexShaderFunction);
    NiFree(m_pcVertexShaderProfile);
    m_spVertexShaderObject.Clear();
    StageArray_e7fea0* pkStages = (StageArray_e7fea0*)&m_kStageArray;
    pkStages->RemoveAll();
    m_uiStageMask = 0;
    m_uiNumberOfStages = 0;
    m_uiStageOffset = 0;
    m_spVertexShaderObject.DecRef();
    m_spSecondShaderConstantMap.DecRef();
    m_spPixelShaderObject.DecRef();
    m_spFirstShaderConstantMap.DecRef();
    pkStages->StageArray_e7fea0::~StageArray_e7fea0();
}

namespace fnv_00b7c7b0 {
struct Vec3f
{
    float x;
    float y;
    float z;
};

// 0x011f91e0 holds the current geometry/pass context; +0x0c is its geometry, as in rw_b7e1::DrawArg.
struct GeometryDrawContext
{
    int unk00;
    int unk04;
    int unk08;
    void* unk0C;
};

struct GeomStub
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
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    Vec3f kTranslate;
};

struct BloodSplatterStub
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
    void* unk5C;
};

struct BloodSplatterHubStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    void* unk20;
};

extern "C" GeometryDrawContext* DAT_011f91e0;
extern "C" BloodSplatterStub* DAT_0126f74c;

void __stdcall D3DXVec3TransformNormal_00ee6df2(Vec3f* out, Vec3f* in, unsigned int param);
void __stdcall D3DXVec3Normalize_00ee6dec(float* a, Vec3f* b);

// @fnv 0x00b7c7b0
// src: COMMUNITY 0x00b7c7b0
void __stdcall BSShader_SetLightDirection(unsigned int param)
{
    void* owner = DAT_011f91e0->unk0C;
    void** ownerVt = *(void***)owner;
    Vec3f* pSrcTranslate = &((GeomStub*)ownerVt[0x3e])->kTranslate;

    volatile float scaledY = (float)(pSrcTranslate->y * -1.0);
    float scaledZ = (float)(pSrcTranslate->z * -1.0);

    Vec3f v1;
    v1.x = (float)(pSrcTranslate->x * -1.0);
    v1.y = scaledY;
    v1.z = scaledZ;

    Vec3f out;
    D3DXVec3TransformNormal_00ee6df2(&out, &v1, param);
    D3DXVec3Normalize_00ee6dec(&v1.x, &out);

    BloodSplatterHubStub* hub = (BloodSplatterHubStub*)DAT_0126f74c->unk5C;
    void* obj = hub->unk20;
    void** objVt = *(void***)obj;
    ((void(__stdcall*)(void*, int, Vec3f*, int))objVt[0x178 / 4])(obj, 0x19, &out, 1);
}
}  // namespace fnv_00b7c7b0

struct BSPass
{
    int unk00;
    int unk04;
    BSTexture* pTexture;

    void SetGeometry(void* apData);
    bool Reset(bool abForce);
};

struct D3D9DeviceInterface
{
    virtual void v000(), v004(), v008(), v00C(), v010(), v014(), v018(), v01C();
    virtual void v020(), v024(), v028(), v02C(), v030(), v034(), v038(), v03C();
    virtual void v040(), v044(), v048(), v04C(), v050(), v054(), v058(), v05C();
    virtual void v060(), v064(), v068(), v06C(), v070(), v074(), v078(), v07C();
    virtual void v080(), v084(), v088(), v08C(), v090(), v094(), v098(), v09C();
    virtual void v0A0(), v0A4(), v0A8(), v0AC(), v0B0(), v0B4(), v0B8(), v0BC();
    virtual void v0C0(), v0C4(), v0C8(), v0CC(), v0D0(), v0D4(), v0D8(), v0DC();
    virtual void v0E0(), v0E4(), v0E8(), v0EC(), v0F0(), v0F4(), v0F8(), v0FC();
    virtual void v100(), v104(), v108(), v10C(), v110(), v114(), v118(), v11C();
    virtual void v120(), v124(), v128(), v12C(), v130(), v134(), v138(), v13C();
    virtual void v140(), v144(), v148(), v14C(), v150(), v154(), v158(), v15C();
    virtual void v160(), v164(), v168(), v16C(), v170(), v174();
    virtual long __stdcall SetVertexShaderConstantF(unsigned int auiStart, const float* apData, unsigned int auiCount);
};

struct BSDeviceHolder
{
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C;
    D3D9DeviceInterface* pDevice;
};

struct S
{
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C;
    int unk020;
    BSPass** ppPasses;
    int unk028, unk02C, unk030, unk034, unk038, unk03C, unk040;
    void* m_pOpaqueData;
    int unk048, unk04C, unk050, unk054, unk058;
    BSDeviceHolder* pDeviceHolder;
};

extern S* g_bsShaderPassContext;

struct BSProperty
{
    BSTexture* pTexture;
};

struct BSGeom
{
    virtual void v000(), v004(), v008(), v00C(), v010(), v014(), v018(), v01C();
    virtual void v020(), v024(), v028(), v02C(), v030(), v034(), v038(), v03C();
    virtual void v040(), v044(), v048(), v04C(), v050(), v054(), v058(), v05C();
    virtual void v060(), v064(), v068(), v06C(), v070(), v074(), v078(), v07C();
    virtual void v080(), v084(), v088(), v08C(), v090(), v094(), v098(), v09C();
    virtual void v0A0(), v0A4(), v0A8(), v0AC(), v0B0(), v0B4(), v0B8(), v0BC();
    virtual void v0C0(), v0C4(), v0C8(), v0CC(), v0D0(), v0D4(), v0D8(), v0DC();
    virtual void* GetModelData();
    int unk004, unk008, unk00C, unk010, unk014, unk018, unk01C;
    int unk020, unk024, unk028, unk02C, unk030, unk034, unk038, unk03C;
    int unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C;
    int unk080, unk084, unk088, unk08C, unk090, unk094, unk098, unk09C;
    int unk0A0, unk0A4, unk0A8;
    BSProperty* pProperty;
};

struct BSTransform
{
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C;
    int unk020, unk024, unk028, unk02C;
    float fScale;
};

struct BSCamera
{
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C;
    int unk020, unk024, unk028, unk02C, unk030, unk034, unk038, unk03C;
    int unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064;
    BSTransform kWorld;
};

struct BSCameraHolder
{
    BSCamera* pCamera;
    char cUnk04, cUnk05, cUnk06, cUnk07, cUnk08;
    unsigned char ucLevel;
};

extern BSCameraHolder* g_pBSCameraHolder;

struct BSVec4
{
    float x, y, z, w;
};

struct SwizzledMatrix
{
    float m[4][4];
};

struct BSLightOut
{
    float f[13];
};

extern BSVec4 g_kBSOrigin;

struct BSShaderParam
{
    int unk00;
    int unk04;
    int iUnk08;
    BSGeom* pGeom;
};

struct BSLightHandler
{
    virtual void v000(), v004(), v008(), v00C(), v010(), v014(), v018(), v01C();
    virtual void v020(), v024(), v028(), v02C(), v030(), v034(), v038(), v03C();
    virtual void v040(), v044(), v048(), v04C(), v050(), v054(), v058(), v05C();
    virtual void v060(), v064(), v068(), v06C(), v070(), v074();
    virtual void Apply(void* apLightData, int a1, int a2, int a3, int a4, int a5, int a6, BSLightOut* apOut,
                       BSVec4* apVec, int a7, int a8);
};

void __cdecl BSBuildMatrix(BSTransform* apTransform, int aiUnk, SwizzledMatrix* apOut);
BSVec4* __stdcall BSTransformCoord(BSVec4* apOut, const BSVec4* apIn, const SwizzledMatrix* apMatrix);



// Assigns textures and geometry to both render passes, resets them, builds the camera matrix, sets the vertex shader constant, and applies the light handler.
// @fnv 0x00b7dfe0
void BSShader::SetupShaderPasses(BSShaderParam* apParam)
{
    BSGeom* pGeom = apParam->pGeom;
    BSPass* pPass = g_bsShaderPassContext->ppPasses[0];
    pPass->pTexture = pGeom->pProperty->pTexture;
    pPass->SetGeometry(pGeom->GetModelData());
    pPass = g_bsShaderPassContext->ppPasses[1];
    pPass->pTexture = GetTexture(pGeom, 0);
    pPass->SetGeometry(pGeom->GetModelData());
    g_bsShaderPassContext->ppPasses[0]->Reset(false);
    g_bsShaderPassContext->ppPasses[1]->Reset(false);

    BSCameraHolder* pHolder = g_pBSCameraHolder;
    BSCamera* pCamera = pHolder->pCamera;
    BSTransform* pTransform = &pCamera->kWorld;
    SwizzledMatrix kMatrix;
    BSBuildMatrix(pTransform, 0, &kMatrix);
    SetupCamera(pCamera, pTransform);
    SetupMatrix(&kMatrix, pTransform->fScale, apParam->iUnk08);

    BSVec4 kPos;
    float fW = (float)pHolder->ucLevel - 1.0;
    BSTransformCoord(&kPos, &g_kBSOrigin, &kMatrix);
    kPos.w = fW;
    g_bsShaderPassContext->pDeviceHolder->pDevice->SetVertexShaderConstantF(0x10, &kPos.x, 1);

    BSLightOut kLight;
    BSLightHandler* pHandler = reinterpret_cast<BSLightHandler*>(m_spPixelConstantMap.m_pObject);
    if (pHandler && g_bsShaderPassContext->m_pOpaqueData)
        pHandler->Apply(g_bsShaderPassContext->m_pOpaqueData, 0, 0, 0, 0, 0, 0, &kLight, &kPos, 0, 1);
}

namespace fnv_00e7dc90 {
class FNV_VirtualDevice
{
  public:
    virtual void vfn_00();
    virtual void vfn_01();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual void vfn_04();
    virtual void vfn_05();
    virtual void vfn_06();
    virtual void vfn_07();
    virtual void vfn_08();
    virtual void vfn_09();
    virtual void vfn_0a();
    virtual void vfn_0b();
    virtual void vfn_0c();
    virtual void vfn_0d();
    virtual void vfn_0e();
    virtual void vfn_0f();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void vfn_15();
    virtual void vfn_16();
    virtual void vfn_17();
    virtual void vfn_18();
    virtual void vfn_19();
    virtual void vfn_1a(int code, int zero1, int zero2, int zero3);
    virtual void vfn_1b();
    virtual void vfn_1c();
    virtual void vfn_1d();
    virtual void vfn_1e();
    virtual void vfn_1f();
    virtual void vfn_20();
    virtual void vfn_21();
    virtual void vfn_22();
    virtual void vfn_23();
    virtual void vfn_24();
    virtual void vfn_25();
    virtual void vfn_26();
    virtual void vfn_27();
    virtual unsigned char vfn_28();
    virtual void vfn_29();
    virtual void vfn_2a();
    virtual void vfn_2b();
    virtual void vfn_2c();
    virtual void vfn_2d();
    virtual void vfn_2e();
    virtual void vfn_2f();
    virtual void vfn_30();
    virtual void vfn_31();
    virtual void vfn_32();
    virtual void vfn_33(int id, int oneOrTwo, int three, int zero);
};

extern FNV_VirtualDevice* DAT_0126f6c4;
extern FNV_VirtualDevice* DAT_0126f6c8;

class FUN_00e7dc90_Class
{
  public:
    unsigned int unknown00;
    int objectId;
    void __thiscall SendDeviceCommands(bool enabled);
};

// If enabled and the device reports flags 4 without 8, sends two vfn_33 commands and eight pairs of vfn_1a codes starting at 0x80.
// @fnv 0x00e7dc90
void __thiscall FUN_00e7dc90_Class::SendDeviceCommands(bool enabled)
{
    if (!enabled)
        return;

    if (DAT_0126f6c4->vfn_28() & 8)
        return;
    if (!(DAT_0126f6c4->vfn_28() & 4))
        return;

    DAT_0126f6c8->vfn_33(objectId, 1, 3, 0);
    DAT_0126f6c8->vfn_33(objectId, 2, 3, 0);

    unsigned int code = 0xc6;
    for (unsigned int remaining = 8; remaining; --remaining)
    {
        DAT_0126f6c8->vfn_1a(code - 0x46, 0, 0, 0);
        DAT_0126f6c8->vfn_1a(code, 0, 0, 0);
        ++code;
    }
}
}  // namespace fnv_00e7dc90

namespace fnv_00e7e940 {
struct RefStandIn
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    void* m_14;
};

struct DeviceStandIn
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual long __stdcall SetTexture(unsigned int uiStage, void* pTexture);
};

extern DeviceStandIn* DAT_0126f6c0;
extern NiDX9RenderState* DAT_0126f6c8;
extern int DAT_0126f6d0;
extern unsigned int DAT_011bf558;

struct SamplerStandIn
{
    unsigned int unk00;
    unsigned int m_04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int m_14;
    RefStandIn* m_18;
    unsigned int m_1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58;
    unsigned char unk5c;
    unsigned char unk5d;
    unsigned char m_5e;

    bool NiD3DTextureStage_CalculateTransformationMatrix(unsigned int masked, void* p);
    void BindTexture();
};

// @fnv 0x00e7e940
void SamplerStandIn::BindTexture()
{
    if (m_04 >= DAT_011bf558)
        return;

    if (m_5e == 0)
    {
        // NiD3DRenderState::vf48 is the texture-stage-state slot (0xc0); its shared declaration has no arguments yet.
        typedef void (__thiscall* SetTextureStageState)(NiDX9RenderState*, unsigned int, int, int, int);
        reinterpret_cast<SetTextureStageState>((*reinterpret_cast<void***>(DAT_0126f6c8))[48])(
            DAT_0126f6c8, m_04, 0x18, 0, 0);
        return;
    }

    unsigned int flags = m_14;
    switch (flags & 0xf0000000)
    {
    case 0:
        DAT_0126f6c0->SetTexture(m_04 + 0x10, &m_1c);
        break;
    case 0x10000000:
        if (!(flags & 0xfffffff))
        {
            DAT_0126f6c0->SetTexture(m_04 + 0x10, m_18->m_14);
        }
        else
        {
            void* p = m_18->m_14;
            if (NiD3DTextureStage_CalculateTransformationMatrix(flags & 0xfffffff, p))
                DAT_0126f6c0->SetTexture(m_04 + 0x10, &DAT_0126f6d0);
        }
        break;
    case 0x20000000:
        if (flags & 0xfffffff)
        {
            if (NiD3DTextureStage_CalculateTransformationMatrix(flags & 0xfffffff, &m_1c))
                DAT_0126f6c0->SetTexture(m_04 + 0x10, &DAT_0126f6d0);
        }
        else
        {
            DAT_0126f6c0->SetTexture(m_04 + 0x10, &m_1c);
        }
        break;
    }
}
}  // namespace fnv_00e7e940

extern int DAT_0109b220;

typedef int(__stdcall* FnvInterlockedOperation)(void*);
extern FnvInterlockedOperation DAT_00fdf1c0;
extern FnvInterlockedOperation DAT_00fdf1c4;

void __cdecl RemoveGlobalConstant(int* value);
void __cdecl ResetAndRegister(void* value);
void __cdecl NiMemObject_ReleaseStorage_00aa1490(void* value, unsigned int size);
void __cdecl FUN_00aa1460(void* value, unsigned int size);

struct Holder
{
    int unk00;
    int unk04;
    int name;
};

struct HolderRef
{
    Holder* holder;
    void Release()
    {
        Holder* h = holder;
        if (h)
        {
            if (h->name != DAT_0109b220)
                DAT_00fdf1c0((void*)(h->name - 8));
            int value = h->name;
            RemoveGlobalConstant(&value);
            if (value != DAT_0109b220)
                DAT_00fdf1c4((void*)(value - 8));
        }
    }
};

struct RenderRef
{
    void* renderGroup;
    void Release()
    {
        ResetAndRegister(renderGroup);
    }
};

struct Element
{
    int unk00, unk04, unk08, unk0c;
    RenderRef render;
    int unk14;
    HolderRef holder;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64;

    void UpdateReferenceState_00e7de30();
    void* FUN_00e7e7c0(unsigned int flags);

    void Release()
    {
        RenderRef& r = render;
        holder.Release();
        r.Release();
    }
};

// In array mode releases the preceding count of elements; otherwise calls FUN_00e7de30, then conditionally calls a helper and returns a pointer.
// @fnv 0x00e7e7c0
void* Element::FUN_00e7e7c0(unsigned int flags)
{
    if (flags & 2)
    {
        int* base = (int*)this - 1;
        int count = *base;
        Element* end = this + count;
        while (--count >= 0)
        {
            --end;
            end->Release();
        }
        if (flags & 1)
            NiMemObject_ReleaseStorage_00aa1490(base, 0x68);
        return base;
    }
    UpdateReferenceState_00e7de30();
    if (flags & 1)
        FUN_00aa1460(this, 0x68);
    return this;
}

namespace fnv_00e7fb80 {
class StageReturn
{
  public:
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
    unsigned int m_uiRefCount;
    void ReturnToPool();
    void DecRefCount()
    {
        if (--m_uiRefCount == 0)
            ReturnToPool();
    }
};
struct StagePtr
{
    StageReturn* m_pObject;
    StagePtr(StageReturn* p = 0) : m_pObject(p)
    {}
    ~StagePtr()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    StagePtr& operator=(const StagePtr& rhs)
    {
        if (m_pObject != rhs.m_pObject)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = rhs.m_pObject;
            if (m_pObject)
                ++m_pObject->m_uiRefCount;
        }
        return *this;
    }
};
extern "C" unsigned int DAT_0126f734;
extern "C" StagePtr DAT_0126f730;
extern "C" void __cdecl FUN_00fde350();
extern "C" int __cdecl atexit(void(__cdecl*)());
struct StageArrayStorage_e7fea0
{
    void* m_pVtbl;
    StagePtr* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void Set(unsigned int index, const StagePtr& value);
};
// Sets the StagePtr at the given index, growing the array if needed and updating the element count when the value differs from the default.
// @fnv 0x00e7fb80
void StageArrayStorage_e7fea0::Set(unsigned int index, const StagePtr& value)
{
    if (!(DAT_0126f734 & 1))
    {
        DAT_0126f734 |= 1;
        DAT_0126f730.m_pObject = 0;
        atexit(FUN_00fde350);
    }
    if (index >= m_usSize)
    {
        m_usSize = index + 1;
        if (value.m_pObject != DAT_0126f730.m_pObject)
            ++m_usESize;
    }
    else
    {
        if (value.m_pObject != DAT_0126f730.m_pObject)
        {
            if (m_pBase[index].m_pObject == DAT_0126f730.m_pObject)
                ++m_usESize;
        }
        else
        {
            if (m_pBase[index].m_pObject != DAT_0126f730.m_pObject)
                --m_usESize;
        }
    }
    m_pBase[index] = value;
}
}  // namespace fnv_00e7fb80

extern int DAT_0126f6c4;
extern float DAT_01016248;
extern float DAT_0126f6d0;
extern float DAT_0126f6d4;
extern float DAT_0126f6d8;
extern float DAT_0126f6dc;
extern float DAT_0126f6e0;
extern float DAT_0126f6e4;
extern float DAT_0126f6e8;
extern float DAT_0126f6ec;
extern float DAT_0126f6f0;
extern float DAT_0126f6f4;
extern float DAT_0126f6f8;
extern float DAT_0126f6fc;
extern float DAT_0126f700;
extern float DAT_0126f704;
extern float DAT_0126f708;
extern float DAT_0126f70c;
extern "C" void* __cdecl memset(void*, int, unsigned int);
// For modes 1–6, combines indexed floats from m and the block at DAT_0126f6c4, writes to DAT_0126f6d0–DAT_0126f70c, and returns false otherwise.
// @fnv 0x00e7df90
// src: COMMUNITY 0x00e7df90
bool __stdcall NiD3DTextureStage_CalculateTransformationMatrix(int mode, float* m)
{
    bool result = true;
    switch (mode)
    {
    case 1: {
        float* pMatrix = (float*)DAT_0126f6c4;
        {
            double term0 = pMatrix[0x291] * m[4];
            double term1 = ((volatile float*)pMatrix)[0x290];
            term1 *= m[0];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x292] * m[8];
            DAT_0126f6d0 = term0;
        }
        {
            double term0 = ((volatile float*)pMatrix)[0x295];
            term0 *= m[4];
            double term1 = ((volatile float*)m)[0];
            term1 *= pMatrix[0x294];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x296] * m[8];
            DAT_0126f6e0 = term0;
        }
        {
            double term0 = ((volatile float*)m)[4];
            term0 *= pMatrix[0x299];
            double term1 = ((volatile float*)pMatrix)[0x298];
            term1 *= m[0];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x29a] * m[8];
            DAT_0126f6f0 = term0;
        }
        {
            double term0 = ((volatile float*)pMatrix)[0x290];
            term0 *= m[1];
            double term1 = ((volatile float*)pMatrix)[0x291];
            term1 *= m[5];
            term0 += term1;
            term0 += (double)((volatile float*)m)[9] * pMatrix[0x292];
            DAT_0126f6d4 = term0;
        }
        {
            double term0 = ((volatile float*)pMatrix)[0x295];
            term0 *= m[5];
            double term1 = ((volatile float*)pMatrix)[0x294];
            term1 *= m[1];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x296] * m[9];
            DAT_0126f6e4 = term0;
        }
        {
            double term0 = ((volatile float*)pMatrix)[0x298];
            term0 *= m[1];
            double term1 = ((volatile float*)m)[5];
            term1 *= pMatrix[0x299];
            term0 += term1;
            term0 += (double)((volatile float*)m)[9] * pMatrix[0x29a];
            DAT_0126f6f4 = term0;
        }
        {
            double term0 = ((volatile float*)pMatrix)[0x290];
            term0 *= m[2];
            double term1 = ((volatile float*)pMatrix)[0x291];
            term1 *= m[6];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x292] * m[10];
            DAT_0126f6d8 = term0;
        }
        {
            double term0 = ((volatile float*)m)[2];
            term0 *= pMatrix[0x294];
            double term1 = ((volatile float*)pMatrix)[0x295];
            term1 *= m[6];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x296] * m[10];
            DAT_0126f6e8 = term0;
        }
        {
            double term0 = ((volatile float*)pMatrix)[0x299];
            term0 *= m[6];
            double term1 = ((volatile float*)pMatrix)[0x298];
            term1 *= m[2];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x29a] * m[10];
            DAT_0126f6f8 = term0;
        }
        {
            double term0 = ((volatile float*)pMatrix)[0x29d];
            term0 *= m[4];
            double term1 = ((volatile float*)m)[0];
            term1 *= pMatrix[0x29c];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x29e] * m[8];
            double term3 = m[12];
            term0 += term3;
            DAT_0126f700 = term0;
        }
        {
            double term0 = ((volatile float*)pMatrix)[0x29d];
            term0 *= m[5];
            double term1 = ((volatile float*)pMatrix)[0x29c];
            term1 *= m[1];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x29e] * m[9];
            double term3 = m[13];
            term0 += term3;
            DAT_0126f704 = term0;
        }
        {
            double term0 = ((volatile float*)m)[2];
            term0 *= pMatrix[0x29c];
            double term1 = ((volatile float*)pMatrix)[0x29d];
            term1 *= m[6];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x29e] * m[10];
            double term3 = m[14];
            term0 += term3;
            DAT_0126f708 = term0;
        }
        DAT_0126f6dc = 0.0f;
        DAT_0126f6ec = 0.0f;
        DAT_0126f6fc = 0.0f;
        DAT_0126f70c = 0.0f;
        break;
    }
    case 2: {
        float* pMatrix = (float*)DAT_0126f6c4;
        {
            double term0 = m[4] * pMatrix[0x291];
            double term1 = ((volatile float*)pMatrix)[0x290];
            term1 *= m[0];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x292] * m[8];
            DAT_0126f6d0 = term0;
        }
        {
            double term0 = ((volatile float*)pMatrix)[0x295];
            term0 *= m[4];
            double term1 = ((volatile float*)m)[0];
            term1 *= pMatrix[0x294];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x296] * m[8];
            DAT_0126f6e0 = term0;
        }
        {
            double term0 = ((volatile float*)m)[4];
            term0 *= pMatrix[0x299];
            double term1 = ((volatile float*)pMatrix)[0x298];
            term1 *= m[0];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x29a] * m[8];
            DAT_0126f6f0 = term0;
        }
        {
            double term0 = ((volatile float*)m)[5];
            term0 *= pMatrix[0x291];
            double term1 = ((volatile float*)pMatrix)[0x290];
            term1 *= m[1];
            term0 += term1;
            term0 += (double)((volatile float*)m)[9] * pMatrix[0x292];
            DAT_0126f6d4 = term0;
        }
        {
            double term0 = ((volatile float*)pMatrix)[0x295];
            term0 *= m[5];
            double term1 = ((volatile float*)pMatrix)[0x294];
            term1 *= m[1];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x296] * m[9];
            DAT_0126f6e4 = term0;
        }
        {
            double term0 = ((volatile float*)pMatrix)[0x298];
            term0 *= m[1];
            double term1 = ((volatile float*)m)[5];
            term1 *= pMatrix[0x299];
            term0 += term1;
            term0 += (double)((volatile float*)m)[9] * pMatrix[0x29a];
            DAT_0126f6f4 = term0;
        }
        {
            double term0 = ((volatile float*)pMatrix)[0x290];
            term0 *= m[2];
            double term1 = ((volatile float*)m)[6];
            term1 *= pMatrix[0x291];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x292] * m[10];
            DAT_0126f6d8 = term0;
        }
        {
            double term0 = ((volatile float*)m)[2];
            term0 *= pMatrix[0x294];
            double term1 = ((volatile float*)pMatrix)[0x295];
            term1 *= m[6];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x296] * m[10];
            DAT_0126f6e8 = term0;
        }
        {
            double term0 = ((volatile float*)pMatrix)[0x299];
            term0 *= m[6];
            double term1 = ((volatile float*)pMatrix)[0x298];
            term1 *= m[2];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x29a] * m[10];
            DAT_0126f6f8 = term0;
        }
        {
            double term0 = ((volatile float*)m)[4];
            term0 *= pMatrix[0x29d];
            double term1 = ((volatile float*)pMatrix)[0x29c];
            term1 *= m[0];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x29e] * m[8];
            double term3 = m[12];
            term0 += term3;
            DAT_0126f700 = term0;
        }
        {
            double term0 = ((volatile float*)pMatrix)[0x29c];
            term0 *= m[1];
            double term1 = ((volatile float*)m)[5];
            term1 *= pMatrix[0x29d];
            term0 += term1;
            term0 += (double)((volatile float*)m)[9] * pMatrix[0x29e];
            double term3 = m[13];
            term0 += term3;
            DAT_0126f704 = term0;
        }
        {
            double term0 = ((volatile float*)pMatrix)[0x29d];
            term0 *= m[6];
            double term1 = ((volatile float*)pMatrix)[0x29c];
            term1 *= m[2];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x29e] * m[10];
            double term3 = m[14];
            term0 += term3;
            DAT_0126f708 = term0;
        }
        DAT_0126f6dc = 0.0f;
        DAT_0126f6ec = 0.0f;
        DAT_0126f6fc = 0.0f;
        DAT_0126f70c = 0.0f;
        break;
    }
    case 3: {
        float* pMatrix = (float*)DAT_0126f6c4;
        {
            double term0 = m[4] * pMatrix[0x291];
            double term1 = ((volatile float*)pMatrix)[0x290];
            term1 *= m[0];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x292] * m[8];
            DAT_0126f6d0 = term0;
        }
        {
            double term0 = ((volatile float*)m)[4];
            term0 *= pMatrix[0x295];
            double term1 = ((volatile float*)pMatrix)[0x294];
            term1 *= m[0];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x296] * m[8];
            DAT_0126f6e0 = term0;
        }
        {
            double term0 = ((volatile float*)pMatrix)[0x299];
            term0 *= m[4];
            double term1 = ((volatile float*)m)[0];
            term1 *= pMatrix[0x298];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x29a] * m[8];
            DAT_0126f6f0 = term0;
        }
        {
            double term0 = ((volatile float*)pMatrix)[0x290];
            term0 *= m[1];
            double term1 = ((volatile float*)m)[5];
            term1 *= pMatrix[0x291];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x292] * m[9];
            DAT_0126f6d4 = term0;
        }
        {
            double term0 = ((volatile float*)pMatrix)[0x294];
            term0 *= m[1];
            double term1 = ((volatile float*)m)[5];
            term1 *= pMatrix[0x295];
            term0 += term1;
            term0 += (double)((volatile float*)m)[9] * pMatrix[0x296];
            DAT_0126f6e4 = term0;
        }
        {
            double term0 = ((volatile float*)pMatrix)[0x299];
            term0 *= m[5];
            double term1 = ((volatile float*)pMatrix)[0x298];
            term1 *= m[1];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x29a] * m[9];
            DAT_0126f6f4 = term0;
        }
        {
            double term0 = ((volatile float*)pMatrix)[0x290];
            term0 *= m[2];
            double term1 = ((volatile float*)pMatrix)[0x291];
            term1 *= m[6];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x292] * m[10];
            DAT_0126f6d8 = term0;
        }
        {
            double term0 = ((volatile float*)pMatrix)[0x295];
            term0 *= m[6];
            double term1 = ((volatile float*)pMatrix)[0x294];
            term1 *= m[2];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x296] * m[10];
            DAT_0126f6e8 = term0;
        }
        {
            double term0 = ((volatile float*)m)[2];
            term0 *= pMatrix[0x298];
            double term1 = ((volatile float*)pMatrix)[0x299];
            term1 *= m[6];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x29a] * m[10];
            DAT_0126f6f8 = term0;
        }
        DAT_0126f700 = m[12];
        DAT_0126f704 = m[13];
        DAT_0126f708 = m[14];
        DAT_0126f6dc = 0.0f;
        DAT_0126f6ec = 0.0f;
        DAT_0126f6fc = 0.0f;
        DAT_0126f70c = 0.0f;
        break;
    }
    case 4: {
        memset(&DAT_0126f6d0, 0, 0x40);
        DAT_0126f6e4 = DAT_01016248;
        DAT_0126f6f0 = DAT_01016248;
        DAT_0126f700 = DAT_01016248;
        DAT_0126f704 = DAT_01016248;
        break;
    }
    case 5: {
        float* pMatrix = (float*)DAT_0126f6c4;
        {
            double term0 = pMatrix[0x291] * m[4];
            double term1 = ((volatile float*)m)[0];
            term1 *= pMatrix[0x290];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x292] * m[8];
            DAT_0126f6d0 = term0;
        }
        {
            double term0 = ((volatile float*)m)[4];
            term0 *= pMatrix[0x295];
            double term1 = ((volatile float*)pMatrix)[0x294];
            term1 *= m[0];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x296] * m[8];
            DAT_0126f6e0 = term0;
        }
        {
            double term0 = ((volatile float*)m)[4];
            term0 *= pMatrix[0x299];
            double term1 = ((volatile float*)pMatrix)[0x298];
            term1 *= m[0];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x29a] * m[8];
            DAT_0126f6f0 = term0;
        }
        {
            double term0 = ((volatile float*)pMatrix)[0x291];
            term0 *= m[5];
            double term1 = ((volatile float*)m)[1];
            term1 *= pMatrix[0x290];
            term0 += term1;
            term0 += (double)((volatile float*)m)[9] * pMatrix[0x292];
            DAT_0126f6d4 = term0;
        }
        {
            double term0 = ((volatile float*)m)[5];
            term0 *= pMatrix[0x295];
            double term1 = ((volatile float*)pMatrix)[0x294];
            term1 *= m[1];
            term0 += term1;
            term0 += (double)((volatile float*)m)[9] * pMatrix[0x296];
            DAT_0126f6e4 = term0;
        }
        {
            double term0 = ((volatile float*)m)[5];
            term0 *= pMatrix[0x299];
            double term1 = ((volatile float*)pMatrix)[0x298];
            term1 *= m[1];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x29a] * m[9];
            DAT_0126f6f4 = term0;
        }
        {
            double term0 = ((volatile float*)m)[2];
            term0 *= pMatrix[0x290];
            double term1 = ((volatile float*)pMatrix)[0x291];
            term1 *= m[6];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x292] * m[10];
            DAT_0126f6d8 = term0;
        }
        {
            double term0 = ((volatile float*)pMatrix)[0x294];
            term0 *= m[2];
            double term1 = ((volatile float*)pMatrix)[0x295];
            term1 *= m[6];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x296] * m[10];
            DAT_0126f6e8 = term0;
        }
        {
            double term0 = ((volatile float*)m)[6];
            term0 *= pMatrix[0x299];
            double term1 = ((volatile float*)m)[2];
            term1 *= pMatrix[0x298];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x29a] * m[10];
            DAT_0126f6f8 = term0;
        }
        DAT_0126f700 = m[12];
        DAT_0126f704 = m[13];
        DAT_0126f708 = m[14];
        DAT_0126f6dc = 0.0f;
        DAT_0126f6ec = 0.0f;
        DAT_0126f6fc = 0.0f;
        DAT_0126f70c = 0.0f;
        break;
    }
    case 6: {
        float* pMatrix = (float*)DAT_0126f6c4;
        {
            double term0 = m[4] * pMatrix[0x291];
            double term1 = ((volatile float*)m)[0];
            term1 *= pMatrix[0x290];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x292] * m[8];
            DAT_0126f6d0 = term0;
        }
        {
            double term0 = ((volatile float*)pMatrix)[0x295];
            term0 *= m[4];
            double term1 = ((volatile float*)m)[0];
            term1 *= pMatrix[0x294];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x296] * m[8];
            DAT_0126f6e0 = term0;
        }
        {
            double term0 = ((volatile float*)m)[4];
            term0 *= pMatrix[0x299];
            double term1 = ((volatile float*)pMatrix)[0x298];
            term1 *= m[0];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x29a] * m[8];
            DAT_0126f6f0 = term0;
        }
        {
            double term0 = ((volatile float*)m)[5];
            term0 *= pMatrix[0x291];
            double term1 = ((volatile float*)pMatrix)[0x290];
            term1 *= m[1];
            term0 += term1;
            term0 += (double)((volatile float*)m)[9] * pMatrix[0x292];
            DAT_0126f6d4 = term0;
        }
        {
            double term0 = ((volatile float*)pMatrix)[0x295];
            term0 *= m[5];
            double term1 = ((volatile float*)pMatrix)[0x294];
            term1 *= m[1];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x296] * m[9];
            DAT_0126f6e4 = term0;
        }
        {
            double term0 = ((volatile float*)pMatrix)[0x298];
            term0 *= m[1];
            double term1 = ((volatile float*)m)[5];
            term1 *= pMatrix[0x299];
            term0 += term1;
            term0 += (double)((volatile float*)m)[9] * pMatrix[0x29a];
            DAT_0126f6f4 = term0;
        }
        {
            double term0 = ((volatile float*)m)[2];
            term0 *= pMatrix[0x290];
            double term1 = ((volatile float*)m)[6];
            term1 *= pMatrix[0x291];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x292] * m[10];
            DAT_0126f6d8 = term0;
        }
        {
            double term0 = ((volatile float*)m)[2];
            term0 *= pMatrix[0x294];
            double term1 = ((volatile float*)pMatrix)[0x295];
            term1 *= m[6];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x296] * m[10];
            DAT_0126f6e8 = term0;
        }
        {
            double term0 = ((volatile float*)pMatrix)[0x299];
            term0 *= m[6];
            double term1 = ((volatile float*)pMatrix)[0x298];
            term1 *= m[2];
            term0 += term1;
            term0 += (double)((volatile float*)pMatrix)[0x29a] * m[10];
            DAT_0126f6f8 = term0;
        }
        DAT_0126f700 = m[12];
        DAT_0126f704 = m[13];
        DAT_0126f708 = m[14];
        DAT_0126f6dc = 0.0f;
        DAT_0126f6ec = 0.0f;
        DAT_0126f6fc = 0.0f;
        DAT_0126f70c = 0.0f;
        break;
    }
    default:
        result = false;
        break;
    }
    return result;
}

namespace fnv_00e7f990 {
extern "C" void* DAT_0126f728;
extern "C" unsigned int DAT_011bf558;
struct FUN_00e89060_shell;
struct RendererApi
{
    virtual void UnknownSlot00() = 0;
    virtual void UnknownSlot01() = 0;
    virtual void UnknownSlot02() = 0;
    virtual void UnknownSlot03() = 0;
    virtual void UnknownSlot04() = 0;
    virtual void UnknownSlot05() = 0;
    virtual void UnknownSlot06() = 0;
    virtual void UnknownSlot07() = 0;
    virtual void UnknownSlot08() = 0;
    virtual void UnknownSlot09() = 0;
    virtual void UnknownSlot10() = 0;
    virtual void UnknownSlot11() = 0;
    virtual void UnknownSlot12() = 0;
    virtual void UnknownSlot13() = 0;
    virtual void UnknownSlot14() = 0;
    virtual void UnknownSlot15() = 0;
    virtual void UnknownSlot16() = 0;
    virtual void UnknownSlot17() = 0;
    virtual void UnknownSlot18() = 0;
    virtual void UnknownSlot19() = 0;
    virtual void UnknownSlot20() = 0;
    virtual void UnknownSlot21() = 0;
    virtual void UnknownSlot22() = 0;
    virtual void UnknownSlot23() = 0;
    virtual void UnknownSlot24() = 0;
    virtual void UnknownSlot25() = 0;
    virtual void UnknownSlot26() = 0;
    virtual void UnknownSlot27() = 0;
    virtual void UnknownSlot28() = 0;
    virtual void UnknownSlot29() = 0;
    virtual void UnknownSlot30() = 0;
    virtual void SetPixelProgram(unsigned int program, unsigned int option) = 0;
    virtual void UnknownSlot32() = 0;
    virtual void UnknownSlot33() = 0;
    virtual void UnknownSlot34() = 0;
    virtual void SetVertexProgram(unsigned int program, unsigned int option) = 0;
    virtual void UnknownSlot36() = 0;
    virtual void UnknownSlot37() = 0;
    virtual void UnknownSlot38() = 0;
    virtual void SetRenderEntry(unsigned int entry, unsigned int option) = 0;
    virtual void UnknownSlot40() = 0;
    virtual void UnknownSlot41() = 0;
    virtual void UnknownSlot42() = 0;
    virtual void SetRenderValue(unsigned int value, unsigned int option) = 0;
    virtual void UnknownSlot44() = 0;
    virtual void UnknownSlot45() = 0;
    virtual void UnknownSlot46() = 0;
    virtual void UnknownSlot47() = 0;
    virtual void SetTextureStageState(unsigned int stage, unsigned int state, unsigned int value,
                                      unsigned int flags) = 0;
};
struct ShaderProgram
{
    virtual void UnknownSlot00() = 0;
    virtual void UnknownSlot01() = 0;
    virtual void UnknownSlot02() = 0;
    virtual void UnknownSlot03() = 0;
    virtual void UnknownSlot04() = 0;
    virtual void UnknownSlot05() = 0;
    virtual void UnknownSlot06() = 0;
    virtual void UnknownSlot07() = 0;
    virtual void UnknownSlot08() = 0;
    virtual void UnknownSlot09() = 0;
    virtual void UnknownSlot10() = 0;
    virtual void UnknownSlot11() = 0;
    virtual void UnknownSlot12() = 0;
    virtual void UnknownSlot13() = 0;
    virtual void UnknownSlot14() = 0;
    virtual void UnknownSlot15() = 0;
    virtual void UnknownSlot16() = 0;
    virtual void UnknownSlot17() = 0;
    virtual void UnknownSlot18() = 0;
    virtual void UnknownSlot19() = 0;
    virtual void UnknownSlot20() = 0;
    virtual void UnknownSlot21() = 0;
    virtual void UnknownSlot22() = 0;
    virtual void UnknownSlot23() = 0;
    virtual void UnknownSlot24() = 0;
    virtual void UnknownSlot25() = 0;
    virtual void UnknownSlot26() = 0;
    virtual void UnknownSlot27() = 0;
    virtual void UnknownSlot28() = 0;
    virtual void UnknownSlot29() = 0;
    virtual void UnknownSlot30() = 0;
    virtual unsigned int GetPixelProgram() = 0;
    virtual void UnknownSlot32() = 0;
    virtual unsigned int GetVertexProgram() = 0;
};
struct ShaderConstantMap
{
    virtual void UnknownSlot00() = 0;
    virtual void UnknownSlot01() = 0;
    virtual void UnknownSlot02() = 0;
    virtual void UnknownSlot03() = 0;
    virtual void UnknownSlot04() = 0;
    virtual void UnknownSlot05() = 0;
    virtual void UnknownSlot06() = 0;
    virtual void UnknownSlot07() = 0;
    virtual void UnknownSlot08() = 0;
    virtual void UnknownSlot09() = 0;
    virtual void UnknownSlot10() = 0;
    virtual void UnknownSlot11() = 0;
    virtual void UnknownSlot12() = 0;
    virtual void UnknownSlot13() = 0;
    virtual void UnknownSlot14() = 0;
    virtual void UnknownSlot15() = 0;
    virtual void UnknownSlot16() = 0;
    virtual void UnknownSlot17() = 0;
    virtual void UnknownSlot18() = 0;
    virtual void UnknownSlot19() = 0;
    virtual void UnknownSlot20() = 0;
    virtual void UnknownSlot21() = 0;
    virtual void UnknownSlot22() = 0;
    virtual void UnknownSlot23() = 0;
    virtual void UnknownSlot24() = 0;
    virtual void UnknownSlot25() = 0;
    virtual void UnknownSlot26() = 0;
    virtual void UnknownSlot27() = 0;
    virtual void UnknownSlot28() = 0;
    virtual void UnknownSlot29() = 0;
    virtual void ApplyConstants(void* shader, unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4,
                                unsigned int p5, unsigned int p6, unsigned int p7, unsigned int p8, unsigned int p9,
                                unsigned int flags) = 0;
};
struct FUN_00e89060_shell
{
    bool GetSlotValue(int id, int* value, bool* initialized);
};
struct TextureStageParameter
{
    unsigned int id;
    unsigned int setting04;
    unsigned int setting08;
    unsigned int setting0c;
    FUN_00e89060_shell* state;
};
struct PassUpdate : NiD3DPass
{
    unsigned int NiD3DPass_SetupShaderPrograms(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5,
                              unsigned int p6, unsigned int p7, unsigned int p8, unsigned int p9);
};
// Sets pixel and vertex shader programs and constants, configures texture stage states, and falls back to render entry or value when no vertex shader is present.
// @fnv 0x00e7f990
// src: XBOX_PDB 0x00e7f990
unsigned int PassUpdate::NiD3DPass_SetupShaderPrograms(unsigned int apContext, unsigned int p2, unsigned int ap3, unsigned int ap4,
                                      unsigned int p5, unsigned int p6, unsigned int p7, unsigned int p8,
                                      unsigned int p9)
{
    ShaderProgram* pPixelShader = reinterpret_cast<ShaderProgram*>(m_spPixelShader.m_pObject);
    if (pPixelShader)
    {
        reinterpret_cast<RendererApi*>(DAT_0126f728)->SetPixelProgram(pPixelShader->GetPixelProgram(), 0);
        ShaderConstantMap* pConstantMap = reinterpret_cast<ShaderConstantMap*>(m_spPixelConstantMap.m_pObject);
        if (pConstantMap)
            pConstantMap->ApplyConstants(m_spPixelShader.m_pObject, apContext, p2, ap3, ap4, p5, p6, p7, p8, p9,
                                         0);
    }
    else
    {
        reinterpret_cast<RendererApi*>(DAT_0126f728)->SetPixelProgram(0, 0);
    }
    ShaderProgram* pVertexShader = reinterpret_cast<ShaderProgram*>(m_spVertexShader.m_pObject);
    if (pVertexShader)
    {
        reinterpret_cast<RendererApi*>(DAT_0126f728)->SetVertexProgram(pVertexShader->GetVertexProgram(), 0);
        ShaderConstantMap* pConstantMap = reinterpret_cast<ShaderConstantMap*>(m_spVertexConstantMap.m_pObject);
        if (pConstantMap)
            pConstantMap->ApplyConstants(m_spVertexShader.m_pObject, apContext, p2, ap3, ap4, p5, p6, p7, p8, p9,
                                         0);
        for (unsigned int stageIndex = 0; stageIndex < (unsigned int)DAT_011bf558; ++stageIndex)
        {
            reinterpret_cast<RendererApi*>(DAT_0126f728)->SetTextureStageState(stageIndex, 11, stageIndex, 0);
            unsigned int texcoordFlags = 0;
            if (stageIndex < m_uiStageCount)
            {
                BeamStage* stage = m_kStages.m_pBase[stageIndex].m_pObject;
                if (stage)
                {
                    TextureStageParameter* pStageParam = reinterpret_cast<TextureStageParameter*>(stage);
                    if (pStageParam->state)
                    {
                        unsigned int value = 0;
                        bool initialized = false;
                        if (pStageParam->state->GetSlotValue(24, reinterpret_cast<int*>(&value), &initialized) &&
                            (value & 0x100))
                            texcoordFlags = 0x100;
                    }
                }
            }
            reinterpret_cast<RendererApi*>(DAT_0126f728)->SetTextureStageState(stageIndex, 24, texcoordFlags, 0);
        }
    }
    else
    {
        reinterpret_cast<RendererApi*>(DAT_0126f728)->SetVertexProgram(0, 0);
        unsigned int* context = reinterpret_cast<unsigned int*>(ap4);
        if (!context)
        {
            if (ap3)
                context = reinterpret_cast<unsigned int*>(*reinterpret_cast<unsigned int*>(ap3 + 0x28));
            else
            {
                unsigned int ctx = *reinterpret_cast<unsigned int*>(apContext + 0xb8);
                context = reinterpret_cast<unsigned int*>(*reinterpret_cast<unsigned int*>(ctx + 0x34));
            }
        }
        if (context[3])
            reinterpret_cast<RendererApi*>(DAT_0126f728)->SetRenderEntry(context[3], 0);
        else
            reinterpret_cast<RendererApi*>(DAT_0126f728)->SetRenderValue(context[4], 0);
    }
    return 0;
}
}  // namespace fnv_00e7f990

struct DepthRendererView
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void PrepareDepthSurface();
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int adapter;
    D3DDEVTYPE deviceType;
    unsigned int unk5cc;
    D3DFORMAT format;
    unsigned int GetAdapter()
    {
        return adapter;
    }
    D3DDEVTYPE GetDeviceType()
    {
        return deviceType;
    }
    D3DFORMAT GetFormat()
    {
        return format;
    }
};
extern DepthRendererView* g_011f4748;
extern IDirect3D9* g_0126f0d8;
inline IDirect3D9* GetDepthD3D()
{
    return g_0126f0d8;
}
struct DepthPixelFormat;
DepthPixelFormat* CreatePixelFormat(D3DFORMAT format);
const char* GetHResultName(HRESULT result);
void Object_DoNothing(const char* format, ...);
// The D3DMULTISAMPLE_TYPE for a buffer's multisample preference.
__forceinline D3DMULTISAMPLE_TYPE GetD3DMultiSampleType(Ni2DBuffer::MultiSamplePreference ePref)
{
    switch (ePref)
    {
    case Ni2DBuffer::MULTISAMPLE_NONE:
        return D3DMULTISAMPLE_NONE;
    case Ni2DBuffer::MULTISAMPLE_2:
        return D3DMULTISAMPLE_2_SAMPLES;
    case Ni2DBuffer::MULTISAMPLE_4:
        return D3DMULTISAMPLE_4_SAMPLES;
    case Ni2DBuffer::MULTISAMPLE_8:
        return D3DMULTISAMPLE_8_SAMPLES;
    default:
        return D3DMULTISAMPLE_NONE;
    }
}
// Recreates the depth stencil surface on the given D3D device, releasing the old surface and updating the pixel format from the new surface description.
// @fnv 0x00e7cf50
bool NiDX9AdditionalDepthStencilBufferData::Recreate(IDirect3DDevice9* pkD3DDevice9)
{
    IDirect3DDevice9* device = pkD3DDevice9;
    if (m_pkSurface)
        Shutdown();
    if (!m_eCreateFormat)
        return false;
    DepthRendererView* renderer = g_011f4748;
    renderer->PrepareDepthSurface();
    D3DFORMAT displayFormat = renderer->GetFormat();
    D3DDEVTYPE deviceType = renderer->GetDeviceType();
    const D3DFORMAT& targetFormat = reinterpret_cast<const D3DFORMAT&>(m_eCreateFormat);
    unsigned int adapter = renderer->GetAdapter();
    HRESULT result = GetDepthD3D()->CheckDeviceFormat(adapter, deviceType, displayFormat, D3DUSAGE_DEPTHSTENCIL,
                                                      D3DRTYPE_SURFACE, targetFormat);
    if (result >= 0)
    {
        result = device->CreateDepthStencilSurface(
            GetWidth(), GetHeight(), static_cast<D3DFORMAT>(m_eCreateFormat),
            GetD3DMultiSampleType(GetMSAAPref()), 0, m_bDiscard, &m_pkSurface, 0);
    }
    if (result < 0)
    {
        Object_DoNothing("NiDX9AdditionalDepthStencilBufferData::Recreate> FAILED %s", GetHResultName(result));
        return false;
    }
    D3DSURFACE_DESC surfaceDesc;
    IDirect3DSurface9*& surface = m_pkSurface;
    if (surface->GetDesc(&surfaceDesc) < 0)
    {
        surface->Release();
        surface = 0;
        return false;
    }
    m_pkPixelFormat = reinterpret_cast<const NiPixelFormat*>(CreatePixelFormat(surfaceDesc.Format));
    return true;
}

namespace rw_b7e1 {
struct Matrix4
{
    float m[16];
};
struct TransformData
{
    float rotation[9];
    NiPoint3 position;
    float scale;
};
struct StageState
{
    unsigned int unk00, unk04;
    void* texture;
    void ApplyPairToState(void*);
    void FUN_00e7eb00(int);
};
struct GeoMaterial
{
    void* texture;
};
struct GeometryData
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
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void* GetTextureState();
    virtual void v39();
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void* GetTexture(int, int);
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
    TransformData world;
    unsigned int unk9C, unkA0, unkA4, unkA8;
    GeoMaterial* material;
};
struct DrawArg
{
    unsigned int unk00, unk04, unk08;
    GeometryData* geom;
};
// Exe 0x00b7e150: unit-local RendererData view; declarations and layout are preserved.
struct ShaderConstantDeviceAccess
{ // distinct from the nested RendererData classes: 0x00b7e150 uploads D3D constants through device +0x20; this is a renderer-device access prefix.
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    IDirect3DDevice9* device;
    void SetConstants(const float* values)
    {
        device->SetVertexShaderConstantF(16, values, 1);
    }
};
struct RendererStageContext
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    StageState** stages;
    unsigned int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58;
    ShaderConstantDeviceAccess* renderer;
};
extern RendererStageContext* DAT_0126f74c;
extern void* DAT_011f951c;
extern GeometryData** DAT_011f91e0;
extern NiPoint3 DAT_011fa2a0;
void BSUtilities_GetInverseWorldMatrix(TransformData const*, int, Matrix4*);
D3dxTransformResult_00ee6df8* __stdcall D3DXVec3TransformCoord_00ee6df8(D3dxTransformResult_00ee6df8*, NiPoint3 const*, Matrix4 const*);
struct Shell_b7e1
{
    void* GetTextureByIndex(GeometryData*, int);
    void ShadowLightShader_SetupGeometryOpt_WorldViewProj(GeometryData*, TransformData*);
    void BSShader_SetLightDirection(Matrix4*);
    void ShadowLightShader_Setup_ADT_PxOpt(DrawArg*);
};
// Sets stage textures and states from the geometry, computes a world transform, and uploads vertex shader constants.
// @fnv 0x00b7e150
// src: COMMUNITY 0x00b7e150
void Shell_b7e1::ShadowLightShader_Setup_ADT_PxOpt(DrawArg* apDrawArg)
{
    GeometryData* geom = apDrawArg->geom;
    StageState* stage = DAT_0126f74c->stages[0];
    stage->texture = geom->material->texture;
    stage->ApplyPairToState(geom->GetTextureState());
    stage = DAT_0126f74c->stages[1];
    stage->texture = GetTextureByIndex(geom, 0);
    stage->ApplyPairToState(geom->GetTextureState());
    stage = DAT_0126f74c->stages[3];
    if (geom->GetTexture(3, 0))
        stage->texture = geom->GetTexture(3, 0);
    else
        stage->texture = DAT_011f951c;
    DAT_0126f74c->stages[0]->FUN_00e7eb00(0);
    DAT_0126f74c->stages[1]->FUN_00e7eb00(0);
    DAT_0126f74c->stages[3]->FUN_00e7eb00(0);
    Matrix4 matrix;
    GeometryData* world = *DAT_011f91e0;
    TransformData* transform = &world->world;
    BSUtilities_GetInverseWorldMatrix(transform, 0, &matrix);
    ShadowLightShader_SetupGeometryOpt_WorldViewProj(world, transform);
    BSShader_SetLightDirection(&matrix);
    float scale = transform->scale;
    // FUN_00ee6df8 fills the vector without a separate constructor call.
    float dataStorage[sizeof(D3dxTransformResult_00ee6df8) / sizeof(float)];
    D3dxTransformResult_00ee6df8& data = *reinterpret_cast<D3dxTransformResult_00ee6df8*>(dataStorage);
    D3DXVec3TransformCoord_00ee6df8(&data, &DAT_011fa2a0, &matrix);
    data.w = scale;
    DAT_0126f74c->renderer->SetConstants(&data.x);
}
}
