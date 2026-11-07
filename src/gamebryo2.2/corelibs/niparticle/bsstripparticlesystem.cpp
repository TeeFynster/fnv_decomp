
// src/gamebryo2.2/corelibs/niparticle/bsstripparticlesystem.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/bsstripparticlesystem.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiParticleSystem.h"
#include "../../../../include/NiRenderer.h"
#include "../../../../include/StrArr.h"

// 0x00c257d0 allocates 0x110 bytes and calls NiParticleSystem's constructor/copy; 0x00c25730 renders via NiGeometry.
struct BSStripParticleSystem : NiParticleSystem
{
    void RenderImmediate(NiRenderer*);
    void OnVisible(NiCullingProcess&);
    void AppendString(StrArr*);
    BSStripParticleSystem* CreateParticleSystem(CloningProcess& process);
};

void* g_01202560;

// @fnv 0x00c257c0
// src: COMMUNITY 0x00c257c0
void* __cdecl BSStripParticleSystem_GetRTTI()
{
    return &g_01202560;
}

// @fnv 0x00c25730
void __thiscall BSStripParticleSystem::RenderImmediate(NiRenderer* apkRenderer)
{
    NiGeometry::RenderImmediate(apkRenderer);
    NiRenderer* pkRenderer = apkRenderer;
    if ((pkRenderer->m_eFrameState == 1 || pkRenderer->m_eFrameState == 2) && pkRenderer->m_bRenderTargetGroupActive == 1)
        ((void(__thiscall*)(NiRenderer*, BSStripParticleSystem*))(*(void***)pkRenderer)[112])(pkRenderer, this);
}

char* __cdecl _FUN_00a7d330(void*);
// Calls WriteParticleSystemInfo, gets a string from g_01202560, grows pkStrings if its count reached capacity, then stores the string at the current count.
// @fnv 0x00c25770
void BSStripParticleSystem::AppendString(StrArr* pkStrings)
{
    WriteParticleSystemInfo(pkStrings);
    char* s = _FUN_00a7d330(g_01202560);
    unsigned int n = pkStrings->m_usSize;
    if (n >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(n + pkStrings->m_usGrowBy);
    pkStrings->SetAt(n, s);
}

extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int size);
extern unsigned int UNK_010be35c;
// Allocates the 0x110-byte strip particle system, initializes its base and vtable, then copies it for cloning.
// @fnv 0x00c257d0
BSStripParticleSystem* BSStripParticleSystem::CreateParticleSystem(CloningProcess& process)
{
    BSStripParticleSystem* object = static_cast<BSStripParticleSystem*>(Object_DispatchCommandFour(0x110));
    if (object)
    {
        object->NiParticleSystem_00c1b5c0();
        *reinterpret_cast<unsigned int**>(object) = &UNK_010be35c;
    }
    else
    {
        object = 0;
    }
    this->CopyMembers_00c1b6f0(object, process);
    return object;
}

void __cdecl FUN_00c1b0b0();
// @fnv 0x00c21940
// src: XBOX_PDB 0x00c21940
void __cdecl BSStripParticleSystem_RegisterStreamables()
{
    FUN_00c1b0b0();
}

// @fnv 0x00c256f0
void __thiscall BSStripParticleSystem::OnVisible(NiCullingProcess& a)
{
    NiGeometry::OnVisible(a);
}

void __cdecl FUN_00c1b3a0();
// @fnv 0x00c25700
// src: XBOX_PDB 0x00c25700
void __cdecl BSStripParticleSystem_LoadBinary()
{
    FUN_00c1b3a0();
}

extern "C" void __cdecl LoadModifiers();
// @fnv 0x00c25710
// src: XBOX_PDB 0x00c25710
void __cdecl BSStripParticleSystem_LinkObject()
{
    LoadModifiers();
}

void __cdecl FUN_00c1b400();
// @fnv 0x00c25720
// src: XBOX_PDB 0x00c25720
void __cdecl BSStripParticleSystem_SaveBinary()
{
    FUN_00c1b400();
}

extern void FUN_00c1b1d0();

// @fnv 0x00c21950
// src: XBOX_PDB 0x00c21950
void BSStripParticleSystem_IsEqual()
{
    FUN_00c1b1d0();
}
