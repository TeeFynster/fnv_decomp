// bsshader/bsrenderedtexture.cpp: BSRenderedTexture (3 functions)

#include "bsrenderedtexture_decls.h"
#include "../../include/BSRenderedTexture.h"
#include "../../include/NiRenderedCubeMap.h"
#include "../../include/BSShaderNoLightingProperty.h"
#include "../../include/NiDX9Renderer.h"

__forceinline bool NiRenderedTexture::IsExactKindOf(const NiRTTI* type)
{
    return GetRTTI() == type;
}

// @fnv 0x00b6b260
NiRenderTargetGroup* BSRenderedTexture::GetGroup()
{
    if (!this)
        return 0;
    if (!(spTexture[0] ? spTexture[0]->IsExactKindOf(&DAT_012708e4) : false))
        return m_apRenderTargetGroups[0];
    return m_apRenderTargetGroups[static_cast<NiRenderedCubeMap*>(spTexture[0])->unk48];
}

template <class T> inline NiPointer<T>::NiPointer() : m_pObject(0)
{}

inline void BSShaderProperty::SetFlag(unsigned int uiBit, bool bEnabled)
{
    unsigned long uiMask = 1u << (uiBit & 31);
    if (bEnabled)
    {
        if (!(ulFlags[uiBit >> 5] & uiMask))
            iLastRenderPassState = 0;
        ulFlags[uiBit >> 5] |= uiMask;
    }
    else
    {
        if (ulFlags[uiBit >> 5] & uiMask)
            iLastRenderPassState = 0;
        ulFlags[uiBit >> 5] &= ~uiMask;
    }
}

static inline void InitializeFalloff(float* pFalloff, float fStartAngle, float fStopAngle,
                                    float fStartOpacity, float fStopOpacity)
{
    pFalloff[0] = fStartAngle;
    pFalloff[1] = fStopAngle;
    pFalloff[2] = fStartOpacity;
    pFalloff[3] = fStopOpacity;
}

// the shared BSStringT<char>'s default constructor (Init: pString = 0, sLen = sMaxLen = 0), inline in this /O2 unit
template <> inline BSStringT<char>::BSStringT()
{
    pString = 0;
    sLen = 0;
    sMaxLen = 0;
}

// @fnv 0x00b6fc90
BSShaderNoLightingProperty::BSShaderNoLightingProperty()
    : eClampMode(NiTexturingProperty::WRAP_S_WRAP_T)
{
    InitializeFalloff(&fFalloffStartAngle, 0.0f, 0.0f, 0.0f, 0.0f);
    iShader = 0x21;
    iShaderPropertyType = 0x15;
    SetFlag(31, true);
    SetFlag(32, true);
}

bool __cdecl BSRenderedTexture_Begin(NiRenderTargetGroup* pkGroup, int iArg);

// 0x011f4748 is NiRenderer::ms_pRenderer; NiDX9Renderer supplies virtual slot 95.
// Its shared vf95 declaration lacks the Boolean result consumed by this caller.
static inline bool QueryFrameState(NiDX9Renderer* renderer)
{
    typedef bool (__thiscall* FrameStateQuery)(NiDX9Renderer*);
    return reinterpret_cast<FrameStateQuery>((*reinterpret_cast<void***>(renderer))[95])(renderer);
}

// Sets the frame state to 2 when it is 0 and virtual slot 95 returns true, then forwards to FUN_00b6b7d0.
// @fnv 0x00b6b8d0
// src: COMMUNITY 0x00b6b8d0
bool __cdecl BSRenderedTexture_StartOffscreen(int iArg, NiRenderTargetGroup* pkGroup)
{
    int& iState = NiRenderer::ms_pRenderer->m_eFrameState;
    if (iState == 0 && QueryFrameState(static_cast<NiDX9Renderer*>(NiRenderer::ms_pRenderer)))
        iState = 2;
    return BSRenderedTexture_Begin(pkGroup, iArg);
}
