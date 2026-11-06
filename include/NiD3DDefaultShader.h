#pragma once

#include "NiD3DShader.h"

class NiDynamicEffectState;

class NiD3DDefaultShader : public NiD3DShader
{
public:
    enum PassFogStatus
    {
        NO_FOG = 0,
        BLACK_FOG = 1,
        STANDARD_FOG = 2
    };

    NiD3DDefaultShader();
    virtual ~NiD3DDefaultShader();

    NiD3DDefaultShader& operator=(const NiD3DDefaultShader&);
    static void __cdecl SetShaderName(const char*);

    bool m_bBaseTextureAlphaNeeded;
    bool m_bVertexColorAlphaNeeded;
    unsigned char _pad3E[2];
    unsigned int m_uiMaxTextureIndex;
    unsigned int m_uiRemainingStages;
    unsigned int m_uiRemainingTextures;
    unsigned int m_uiOldLightingValue;
    PassFogStatus* m_peFogPassArray;
    unsigned int m_uiFogPassArraySize;
    const NiDynamicEffectState* m_pkLastState;
};
