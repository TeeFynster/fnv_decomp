#pragma once

#include <windows.h>

class NiRenderTargetGroup;
class NiRenderedTexture;

class BSRenderedTexture
{
  public:
    unsigned char base[8];
    NiRenderTargetGroup* m_apRenderTargetGroups[6];
    char unk20[4];
    char m_acDataAtOffset36[4];
    char m_acDataAtOffset40[4];
    int m_iDataAtOffset44;
    NiRenderedTexture* spTexture[4];

    NiRenderTargetGroup* GetGroup();
    static void __cdecl EndAllAndResetRendererState();
    static void EndAll();
    void* BSRenderedTexture_GetTexture();
    void __thiscall TESMain_DrawWorld_StopRenderTarget(int, int);
    void IncRefCount();
};
