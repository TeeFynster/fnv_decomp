#pragma once

#include "NiPointer.h"

class BSShader;
class NiRefObject;
class NiD3DPass;
class NiD3DVertexShader;
class NiD3DPixelShader;
class NiPropertyState;

class BSShaderBloodSplatter
{
public:
    unsigned char unk00[0x6C];
    NiPointer<NiD3DPass> spRenderPass[2];
    NiPointer<NiD3DVertexShader> m_spTreeVertexShader[2];
    NiPointer<NiD3DPixelShader> m_spPixelShaderVariants[2];

    BSShaderBloodSplatter();
    ~BSShaderBloodSplatter();
    static void* __cdecl operator new(unsigned int size);

    BSShader* CreateShader();
    void InitializeShaderData();
    bool ConfigureShaderPass();
    void FUN_00b81110(unsigned int);
    void FUN_00b805d0(unsigned int);
    void FUN_00b80600(NiRefObject*);
    void SetupConstantMaps();
    int FUN_00b807c0(void*, void*);
    void FUN_00b80380();
    bool FUN_00b80b20();
    void* FUN_00b80e40(unsigned int);
    void CreateShaderConstantMaps();
    void InitPassItems(NiPropertyState*);
    void ApplyBloodShader(NiPropertyState*);
};
