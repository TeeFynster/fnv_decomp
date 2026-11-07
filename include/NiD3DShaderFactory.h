#pragma once

#include "NiShaderFactory.h"

class GraphicsRenderer;

class NiD3DShaderFactory : public NiShaderFactory
{
public:
    virtual void vfn_70(GraphicsRenderer*);
    virtual void vf29();
    virtual void vf30();

    static NiD3DShaderFactory* GetShaderFactory();
    void ShutdownPoint3();
    static void __cdecl InitializePoint3();
    void UpdateShaderMaterialCache(void*);
    void NiDX9MaterialManager_UpdateToDevice(void*);
    void FUN_00aa0390();
    NiShaderFactory* Create();

    void* m_pOwnerShader;
    void* m_pShaderMapStorage;
    void* m_pShaderLibraryIterator;
    void* m_pShaderLibraryStorage;
    unsigned char unk34[0x4C];
    unsigned char m_kShaderMap[0x80];
};
