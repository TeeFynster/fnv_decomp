
// src/gamebryo2.2/corelibs/nimain/niparticles.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/niparticles.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiGeometryData.h"
#include "../../../../include/NiParticles.h"
#include "../../../../include/NiRenderer.h"
#include "../../../../include/StrArr.h"

extern char const* const g_011f5f14_arg1;

// @fnv 0x00a9b1b0
// src: COMMUNITY 0x00a9b1b0
char const* const* __cdecl NiParticles_GetRTTI()
{
    return &g_011f5f14_arg1;
}

// @fnv 0x00a9b230
void NiParticles::CalculateConsistency(bool bTool)
{
    NiGeometryData* p = m_spModelData.m_pObject;
    p->SetDataConsistency((NiGeometryData::Consistency)0);
}

// The shared NiGeometry declaration has no out-of-line destructor declaration.
void __fastcall DestroyGeometry(NiGeometry*);
void __cdecl _delete(void*, unsigned int);
// Calls FUN_00a80580 on this, frees this with _delete when bit 0 of f is set, and returns this.
// @fnv 0x00a9b1c0
void* __fastcall DeleteParticles(NiParticles* self, void*, unsigned int auiFlags)
{
    DestroyGeometry(self);
    if (auiFlags & 1)
        _delete(self, 0xC4);
    return self;
}

// @fnv 0x00a9b1f0
void __fastcall SetupRenderer(NiParticles* self, void*, NiRenderer* apkRenderer)
{
    NiRenderer* pkRenderer = apkRenderer;
    self->NiGeometry::RenderImmediate(pkRenderer);
    if ((pkRenderer->m_eFrameState == 1 || pkRenderer->m_eFrameState == 2) && pkRenderer->m_bRenderTargetGroupActive == 1)
    {
        ((void(__thiscall*)(NiRenderer*, void*))(*(void***)pkRenderer)[111])(pkRenderer, self);
    }
}

void __stdcall FUN_00a80e70(StrArr*);
char* _FUN_00a7d330(const char*);
// Grows the StrArr if it is full, then appends the string returned by _FUN_00a7d330(g_011f5f14_arg1) at the current size.
// @fnv 0x00a9b2e0
// src: XBOX_PDB 0x00a9b2e0
void __stdcall NiParticles_GetViewerStrings(StrArr* apStrArr)
{
    FUN_00a80e70(apStrArr);
    char* psz = _FUN_00a7d330(g_011f5f14_arg1);
    unsigned int uiSize = apStrArr->m_usSize;
    unsigned int uiMax = apStrArr->m_usMaxSize;
    if (uiSize >= uiMax)
        apStrArr->SetSize(apStrArr->m_usGrowBy + uiSize);
    apStrArr->SetAt(uiSize, psz);
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);
extern int DAT_010a11d4;

inline void* operator new(unsigned int, void* memory) { return memory; }

// @fnv 0x00a9b250
NiParticles* __fastcall CreateAndInitObject(NiParticles* self, void*, unsigned int arg)
{
    NiParticles* p = (NiParticles*)Object_DispatchCommandFour(0xc4);
    if (p != 0)
    {
        ::new (p) NiGeometry;
        *(void**)p = (void*)&DAT_010a11d4;
    }
    else
    {
        p = 0;
    }
    self->NiGeometry::CopyMemberData(p, (CloningProcess*)arg);
    return p;
}

struct ObjHdr
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    union
    {
        unsigned char m_18b;
        unsigned short m_18w;
    };
};

struct HolderB8
{
    void NiParticlesData_SortParticles(unsigned int);
};

struct ArgRec
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_0C;
};

// If m_9C is set and its flag bits are set, forwards pArg->m_0C to m_B8, then calls FUN_00a7fd90(pArg).
// @fnv 0x00a9b2a0
void __fastcall ProcessArgIfFlagged(NiParticles* self, void*, ArgRec* pArg)
{
    ObjHdr* pObjHdr = (ObjHdr*)self->m_PropertyState.m_aspProps[0];
    if (pObjHdr != 0 && (pObjHdr->m_18b & 1) != 0 && (pObjHdr->m_18w & 0x1E0) != 0)
    {
        ((HolderB8*)self->m_spModelData.m_pObject)->NiParticlesData_SortParticles(pArg->m_0C);
    }
    self->NiGeometry::OnVisible(*reinterpret_cast<NiCullingProcess*>(pArg));
}
