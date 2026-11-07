// gamebryo2.2/corelibs/nimain/nilines.cpp: NiLines (8 functions)

#include "../../../../include/BSResizableTriShape.h"
#include "../../../../include/NiRenderer.h"
#include "../../../../include/NiLines.h"
#include "../../../../include/NiTriBasedGeom.h"
#include "../../../../include/NiTriShape.h"

// Sets the geometry data on dest from model, then calls NiAVObject::FUN_00a5ac90 with dest and process.
// @fnv 0x00a80400
__declspec(noinline) void NiLines::CopyMemberData(NiLines* dest, CloningProcess& process)
{
    dest->ReplaceModelData(m_spModelData.m_pObject);
    NiAVObject::CopyMembers_00a5ac90(dest, process);
}

typedef void(__thiscall* RendererFn)(NiRenderer*, NiLines*);
// Calls self's render method, then if the renderer's mode is 1 or 2 and its flag is set, invokes the renderer's virtual function at offset 0x1c4.
// @fnv 0x00a747a0
// src: XBOX_PDB 0x00a747a0
void __fastcall NiLines_RenderImmediate(NiLines* self, int, NiRenderer* apkRenderer)
{
    self->NiGeometry::RenderImmediate(apkRenderer);
    if ((apkRenderer->m_eFrameState == 1 || apkRenderer->m_eFrameState == 2) &&
        apkRenderer->m_bRenderTargetGroupActive == true)
    {
        RendererFn* vt = *(RendererFn**)apkRenderer;
        vt[0x1c4 / 4](apkRenderer, self);
    }
}

struct ActorCombatGroup;
struct GlobalObjectO2_00a7b610;
struct NiCombatArray
{
    virtual ~NiCombatArray();
    ActorCombatGroup** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usESize;
    unsigned short m_usFreeIdx;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int);
    void SetAt(unsigned int, ActorCombatGroup*&);
};
extern GlobalObjectO2_00a7b610* g_011f4a48;
void __stdcall FUN_00a80e70(NiCombatArray*);
ActorCombatGroup* __cdecl NiViewerStrings_NiGetViewerString_Title(GlobalObjectO2_00a7b610*);
// @fnv 0x00a74830
// src: XBOX_PDB 0x00a74830
void __stdcall NiLines_GetViewerStrings(NiCombatArray* pkStrings)
{
    FUN_00a80e70(pkStrings);
    ActorCombatGroup* pkGroup = NiViewerStrings_NiGetViewerString_Title(g_011f4a48);
    unsigned int uiIndex = pkStrings->m_usESize;
    if (uiIndex >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiIndex + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiIndex, pkGroup);
}

// @fnv 0x00e68810
// src: COMMUNITY 0x00e68810
NiLines* __fastcall ReturnThis2(NiLines* self, int)
{
    return self;
}

void __cdecl FUN_00a80470();
// @fnv 0x00a89770
// src: XBOX_PDB 0x00a89770
void __cdecl NiLines_IsEqual()
{
    FUN_00a80470();
}

// @fnv 0x00a9b190
// src: XBOX_PDB 0x00a9b190
extern "C" bool __fastcall NiLines_RegisterStreamables(NiLines* self, int, NiStream& s)
{
    return self->FUN_00a80430(s);
}

void FUN_00a80db0();
// @fnv 0x00a9b1a0
// src: XBOX_PDB 0x00a9b1a0
void __cdecl NiLines_SaveBinary()
{
    FUN_00a80db0();
}

void* __cdecl NiAllocBlock(unsigned int size);
extern const void* DAT_0109d55c[];

// Allocates a NiLines, initializes its geometry base and vtable, then copies the source.
// @fnv 0x00a747e0
// src: XBOX_PDB 0x00a747e0
NiLines* __fastcall NiLines_CreateClone(NiLines* self, int, CloningProcess& process)
{
    NiLines* result = static_cast<NiLines*>(NiAllocBlock(sizeof(NiLines)));
    if (result)
    {
        result->NiGeometry::NiGeometry();
        *reinterpret_cast<const void***>(result) = DAT_0109d55c;
    }
    else
    {
        result = 0;
    }
    self->CopyMemberData(result, process);
    return result;
}
