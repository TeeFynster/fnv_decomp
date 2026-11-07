
// src/gamebryo2.2/corelibs/nimain/nirendertargetgroup.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nirendertargetgroup.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiDepthStencilBuffer.h"
#include "../../../../include/NiRenderTargetGroup.h"
#include "../../../../include/NiRenderer.h"
#include "../../../../include/StrArr.h"

extern NiRTTI g_012708ec;

// @fnv 0x00ee8530
// src: COMMUNITY 0x00ee8530
NiRTTI* __cdecl NiRenderTargetGroup_GetRTTI()
{
    return &g_012708ec;
}

// @fnv 0x00ee8600
const NiPixelFormat* __thiscall NiRenderTargetGroup::GetPixelFormat() const
{
    NiRenderTargetGroup* p = const_cast<NiRenderTargetGroup*>(this);
    NiPixelFormat* p1 = *reinterpret_cast<NiPixelFormat**>(reinterpret_cast<unsigned char*>(p) + 0x20);
    if (p1)
    {
        NiPixelFormat* p2 = *reinterpret_cast<NiPixelFormat**>(reinterpret_cast<unsigned char*>(p1) + 0x10);
        if (p2)
            return *reinterpret_cast<NiPixelFormat**>(reinterpret_cast<unsigned char*>(p2) + 0xc);
    }
    return 0;
}


// @fnv 0x00ee8460
// src: XBOX_PDB 0x00ee8460
void NiRenderTargetGroup::SetRendererData_00ee8460(RendererData* pkRendererData)
{
    RendererData*& m_pTextureRendererData = reinterpret_cast<RendererData*&>(RenderTargetBufferInfo);
    if (m_pTextureRendererData)
    {
        delete m_pTextureRendererData;
        m_pTextureRendererData = pkRendererData;
    }
    else
    {
        m_pTextureRendererData = pkRendererData;
    }
}

// @fnv 0x00ee84d0
// src: XBOX_PDB 0x00ee84d0
int NiRenderTargetGroup::GetDepthStencilWidth() const
{
    const NiMemObject* p =
        *reinterpret_cast<const NiMemObject* const*>(reinterpret_cast<const unsigned char*>(this) + 0x20);
    if (p)
        return *reinterpret_cast<const int*>(reinterpret_cast<const unsigned char*>(p) + 8);
    return 0;
}

// @fnv 0x00ee84e0
// src: XBOX_PDB 0x00ee84e0
int NiRenderTargetGroup::GetDepthStencilHeight() const
{
    void* p =
        *reinterpret_cast<void**>(const_cast<unsigned char*>(reinterpret_cast<const unsigned char*>(this)) + 0x20);
    if (p)
        return *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(p) + 0xc);
    return 0;
}

// @fnv 0x00ee84f0
// src: XBOX_PDB 0x00ee84f0
NiMemObject* __thiscall NiRenderTargetGroup::GetBuffer_00ee84f0(unsigned int uiIndex) const
{
    return GetBuffers()[uiIndex];
}

// @fnv 0x00ee8550
// src: XBOX_PDB 0x00ee8550
void __thiscall NiRenderTargetGroup::SetResolveDepthBufferMode(bool abResolve)
{
    m_bNeedsResolve = abResolve;
}

// @fnv 0x00ee86e0
// src: XBOX_PDB 0x00ee86e0
void* NiRenderTargetGroup::GetBufferRendererData(unsigned int uiIndex) const
{
    void* p = GetBuffers()[uiIndex];
    if (p)
        return *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(p) + 0x10);
    return 0;
}

extern "C" void __cdecl __Dummy_00b6fef0(void*, int);
void __fastcall DestroyRenderTargetGroup(NiRenderTargetGroup* pkGroup);

// Calls FUN_00ee8560, then if bit 0 of flags is set calls __Dummy_00b6fef0 on this with 0x28, and returns this.
// @fnv 0x00ee87e0
void* __thiscall NiRenderTargetGroup::FUN_00ee87e0(unsigned int flags)
{
    NiRenderTargetGroup* p = this;
    DestroyRenderTargetGroup(this);
    if (flags & 1)
        __Dummy_00b6fef0(p, 0x28);
    return p;
}

void __stdcall AppendCameraPathEntries(StrArr*);
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char*);
// @fnv 0x00ee8800
// src: XBOX_PDB 0x00ee8800
void __stdcall NiRenderTargetGroup_GetViewerStrings(StrArr* pkStrings)
{
    AppendCameraPathEntries(pkStrings);
    char* pString = NiViewerStrings_NiGetViewerString_Title(*(const char**)&g_012708ec);
    unsigned int size = pkStrings->m_usSize;
    unsigned int max = pkStrings->m_usMaxSize;
    if (size >= max)
        pkStrings->SetSize(size + pkStrings->m_usGrowBy);
    pkStrings->SetAt(size, pString);
}

// @fnv 0x00ee8490
unsigned int NiRenderTargetGroup::Unk_23(unsigned int uiStage)
{
    Ni2DBuffer* pkBuffer = reinterpret_cast<Ni2DBuffer*>(GetBuffers()[uiStage]);
    if (pkBuffer)
        return pkBuffer->m_uiImageWidth;
    return 0;
}

// @fnv 0x00ee84b0
void* NiRenderTargetGroup::vf36(unsigned int index)
{
    Ni2DBuffer* pEntry = reinterpret_cast<Ni2DBuffer*>(GetBuffers()[index]);
    if (pEntry)
    {
        return reinterpret_cast<void*>(pEntry->m_uiImageHeight);
    }
    return 0;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct RenderBuffer
{
    virtual void Unknown();
    virtual void Destroy();
    volatile long m_uiRefCount;
};
extern void* g_NiRenderTargetGroupVTable[];
// Releases the renderer data, the depth buffer and the four render buffers via refcount decrement, then calls FUN_00a5d3d0.
// @fnv 0x00ee8560
void __fastcall DestroyRenderTargetGroup(NiRenderTargetGroup* pkGroup)
{
    *reinterpret_cast<void***>(pkGroup) = g_NiRenderTargetGroupVTable;
    delete reinterpret_cast<NiRenderTargetGroup::RendererData*>(pkGroup->RenderTargetBufferInfo);
    RenderBuffer* p = reinterpret_cast<RenderBuffer*>(pkGroup->GetDepthStencilBuffer());
    if (p && !InterlockedDecrement(&p->m_uiRefCount))
        p->Destroy();
    RenderBuffer** ppBufferSlot = reinterpret_cast<RenderBuffer**>(pkGroup->GetBuffers()) + 4;
    for (int i = 3; i >= 0; --i)
    {
        RenderBuffer* pBuffer = *(--ppBufferSlot);
        if (pBuffer && !InterlockedDecrement(&pBuffer->m_uiRefCount))
            pBuffer->Destroy();
    }
    pkGroup->NiObject::FUN_00a5d3d0();
}

// @fnv 0x00ee85e0
void* NiRenderTargetGroup::vf39(unsigned int index)
{
    Ni2DBuffer* pEntry = reinterpret_cast<Ni2DBuffer*>(GetBuffers()[index]);
    if (pEntry != 0)
    {
        Ni2DBuffer::RendererData* pNode = reinterpret_cast<Ni2DBuffer::RendererData*>(pEntry->m_pRendererData);
        if (pNode != 0)
        {
            return const_cast<NiPixelFormat*>(pNode->m_pkPixelFormat);
        }
    }
    return 0;
}

// This accessor has no matching member declaration in the shared header.
// @fnv 0x00ee8700
void* __fastcall GetDepthBufferRendererData(NiRenderTargetGroup* pkGroup)
{
    if (pkGroup->GetDepthStencilBuffer() != 0)
    {
        return pkGroup->GetDepthStencilBuffer()->m_pRendererData;
    }
    return 0;
}

NiRenderTargetGroup* __fastcall FUN_00ee8500(void* mem) throw();

// @fnv 0x00ee8710
NiRenderTargetGroup* __cdecl CreateShaderLevel(unsigned int uiTreeBlockIndex, NiRenderer* pkRenderer)
{
    if (!pkRenderer)
        return 0;
    if (pkRenderer->GetMaxBuffersPerRenderTargetGroup() < uiTreeBlockIndex)
        return 0;
    if (uiTreeBlockIndex > 4)
        return 0;
    void* pvMem = NiObject::operator new(0x28);
    NiRenderTargetGroup* pkObject = pvMem ? FUN_00ee8500(pvMem) : 0;
    reinterpret_cast<unsigned int&>(pkObject->m_aspRenderTargetBuffers[2].m_pObject) = uiTreeBlockIndex;
    return pkObject;
}

// The shared vf42 declaration has no parameters; retain this existing view
// until the two-argument render-buffer binding method is available there.
struct SpawnedObject
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
    virtual void v42(void* a, int b);
    virtual void v43(void* a);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int m_1c;
};

void* __cdecl Object_DispatchCommandFour(unsigned int size);

// @fnv 0x00ee8760
// src: COMMUNITY 0x00ee8760
SpawnedObject* __cdecl NiRenderTargetGroup_Create_(void* a1, NiRenderer* apSource, void* a3)
{
    if (apSource == 0)
    {
        return 0;
    }
    if (a1 == 0)
    {
        return 0;
    }
    if (apSource->GetMaxBuffersPerRenderTargetGroup() < 1)
    {
        return 0;
    }
    SpawnedObject* pSpawned;
    void* mem = Object_DispatchCommandFour(0x28);
    if (mem != 0)
    {
        pSpawned = reinterpret_cast<SpawnedObject*>(FUN_00ee8500(mem));
    }
    else
    {
        pSpawned = 0;
    }
    pSpawned->m_1c = 1;
    pSpawned->v42(a1, 0);
    if (a3 != 0)
    {
        pSpawned->v43(a3);
    }
    return pSpawned;
}

class AA1AC0Class
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned int unk20;

    virtual unsigned int NiFile_GetBuffer();
};

// @fnv 0x00aa1ac0
// src: COMMUNITY 0x00aa1ac0
unsigned int AA1AC0Class::NiFile_GetBuffer()
{
    return unk20;
}

// This flag accessor has no matching member declaration in the shared header.
// @fnv 0x00ee8540
unsigned char __fastcall GetRenderTargetGroupResolveFlag(const NiRenderTargetGroup* pkGroup)
{
    return *reinterpret_cast<const unsigned char*>(&pkGroup->m_bNeedsResolve);
}

#include <windows.h>
struct RefCountedObj
{
    virtual void unk00();
    virtual void Destroy();
    LONG m_lRefCount;
};

// Replaces the item at uiIndex with pNew, decrementing the old item's ref count and incrementing the new one's.
// @fnv 0x00ee8620
bool __fastcall SetRenderTargetGroupItem(NiRenderTargetGroup* pkGroup, void*, RefCountedObj* apItem, unsigned int uiIndex)
{
    pkGroup->SetRendererData_00ee8460(0);
    RefCountedObj** m_apItems = reinterpret_cast<RefCountedObj**>(pkGroup->GetBuffers());
    if (uiIndex < reinterpret_cast<unsigned int&>(pkGroup->m_aspRenderTargetBuffers[2].m_pObject))
    {
        RefCountedObj* pOldItem = m_apItems[uiIndex];
        if (pOldItem != apItem)
        {
            if (pOldItem != 0)
            {
                if (InterlockedDecrement(&pOldItem->m_lRefCount) == 0)
                {
                    pOldItem->Destroy();
                }
            }
            m_apItems[uiIndex] = apItem;
            if (apItem != 0)
            {
                InterlockedIncrement(&apItem->m_lRefCount);
            }
        }
        return true;
    }
    return false;
}

// Replaces the host's depth-stencil buffer, releasing the old one and acquiring a reference to the new one.
// @fnv 0x00ee8690
bool __thiscall NiRenderTargetGroup::SetDepthStencilBuffer(NiDepthStencilBuffer* pkDepthBuffer)
{
    ((void(__thiscall**)(void*, int))(*(void***)this))[49](this, 0);
    NiDepthStencilBuffer* pkOld = GetDepthStencilBuffer();
    if (pkOld != pkDepthBuffer)
    {
        if (pkOld)
        {
            if (InterlockedDecrement(reinterpret_cast<volatile LONG*>(&pkOld->m_uiRefCount)) == 0)
                ((void(__thiscall**)(void*))(*(void***)pkOld))[1](pkOld);
        }
        GetDepthStencilBuffer() = pkDepthBuffer;
        if (pkDepthBuffer)
            InterlockedIncrement(reinterpret_cast<volatile LONG*>(&pkDepthBuffer->m_uiRefCount));
    }
    return true;
}
