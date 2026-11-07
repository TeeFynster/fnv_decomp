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
    void BSShaderBloodSplatterProperty_SetClampD3D(unsigned int);
    void BSShaderBloodSplatter_InitPass(unsigned int);
    void NiD3DPass_SetPixelShader(NiRefObject*);
    void SetupConstantMaps();
    int ImageSpaceShader_GetShaderDeclaration(void*, void*);
    void X_Shader_ClearPassStages();
    bool BSShaderBloodSplatter_ReloadShaders();
    void* FUN_00b80e40(unsigned int);
    void CreateShaderConstantMaps();
    void InitPassItems(NiPropertyState*);
    void ApplyBloodShader(NiPropertyState*);
};
