
// src/fallout_shared/speedtree/bstreemanager_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/speedtree/bstreemanager.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../../include/BSTreeManager.h"
#include "../../../include/NiPointer.h"
#include "bstreemanager_decls.h"
#include "../../../include/NP.h"
#include "../../../include/Setting.h"
#include "../../../include/NiRenderer.h"
#include "../../../include/NiDX9Renderer.h"
void* BSTreeManager_GetInstance(bool create);
void SetGlobalFloatFromUInt(unsigned int value);
void ClampAndStoreValue(float value);
extern NP DAT_011f95e4;
void SetGlobalValue(unsigned int value);
struct FUN_006652c0_shell
{
    void SetByteAtOffset44(unsigned char value);
};
extern Setting originalRuntimeFloatSetting1295;
float GameSetting_fTreeNearDistanceBase_Get();
extern unsigned char __cdecl GetFirstProcessListByte(void);
extern unsigned char* __cdecl _FUN_00664840(bool);
unsigned char BSTreeManager_GetTreesEnabled(bool abCreateIfNotFound);

struct GraphicsRenderer : public NiRenderer
{
    bool BeginUsingRenderTargetGroup(NiRenderTargetGroup* pkTarget, unsigned int uiClone);
};

void __cdecl PushRefCountedSlot(NiRenderTargetGroup* pkTarget);

// @fnv 0x00b6b7d0
// src: COMMUNITY 0x00b6b7d0
void BSRenderedTexture_Begin(NiRenderTargetGroup* pkTarget, unsigned int uiClone)
{
    NiRenderer* pkRenderer = NiRenderer::ms_pRenderer;
    if (pkTarget == 0)
    {
        pkTarget = static_cast<NiDX9Renderer*>(pkRenderer)->GetDefaultRT();
    }
    if (pkRenderer->m_bRenderTargetGroupActive)
    {
        pkRenderer->TryUnlock();
    }
    NiRenderTargetGroup* pkTarget2 = pkTarget;
    if (pkTarget2 == 0)
    {
        pkTarget2 = static_cast<NiDX9Renderer*>(NiRenderer::ms_pRenderer)->GetDefaultRT();
    }
    ((GraphicsRenderer*)NiRenderer::ms_pRenderer)->BeginUsingRenderTargetGroup(pkTarget2, uiClone);
    PushRefCountedSlot(pkTarget);
}
