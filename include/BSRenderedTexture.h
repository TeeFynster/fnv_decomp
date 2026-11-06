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
    void* FUN_004bc320();
    void __thiscall FUN_00876830(int, int);
    void IncRefCount();
};
