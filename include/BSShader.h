#pragma once

#include "NiD3DDefaultShader.h"
#include "BSShaderManager.h"

class NiD3DPass;
class NiD3DVertexShader;
class NiD3DPixelShader;
class NiDX9ShaderDeclaration;
class BSShaderProperty;
class BSTexture;
class BSGeom;
class BSCamera;
class BSTransform;
class SwizzledMatrix;
class BSShaderParam;
struct _D3DXMACRO;

class BSShader : public NiD3DDefaultShader
{
public:
    BSShader();
    virtual ~BSShader();

    virtual bool Initialize();
    virtual void SetRenderPass(unsigned int aeType);
    virtual void SetShaders(BSShaderManager::RenderPassType aeType = BSShaderManager::BSSM_EMPTY);
    virtual void Func_62(unsigned int aeType);
    virtual void Func_63(unsigned int aeType);
    virtual void RestoreSavedStates(unsigned int aeType);
    virtual void RestoreTechnique(unsigned int uiTechnique);
    virtual void ConfigureTextureStages();
    virtual void ConfigureAllTextureStages();
    virtual void StartMultiPass(NiPropertyState* pShaderProps);
    virtual void StopMultiPass();
    virtual NiDX9ShaderDeclaration* GetShaderDeclaration(NiGeometry*, BSShaderProperty* property);
    virtual void InitShaderConstants();
    virtual void Reinitialize();
    virtual void ClearAllTextureStages();
    virtual void ClearTextureStages(NiD3DPass* apPass);
    virtual void Func_75();
    virtual void CreateD3DPass();
    virtual void Func_77();
    virtual void Func_78(unsigned int* apeType, int a2);

    static void __cdecl GetShaderPath(const char* source, char* output);
    NiD3DVertexShader* CompileVertexShader(const char* path, const _D3DXMACRO* macros,
                                         const char* profile, const char* output);
    NiD3DPixelShader* CompilePixelShader(const char* path, const _D3DXMACRO* macros,
                                       const char* profile, const char* output);
    BSTexture* GetTexture(BSGeom* apGeom, int aiIndex);
    void SetupCamera(BSCamera* apCamera, BSTransform* apTransform);
    void SetupMatrix(SwizzledMatrix* apMatrix, float afScale, int aiValue);
    void SetupShaderPasses(BSShaderParam* apParam);

    NiPointer<NiD3DPass> spPass[1];
    int ePass;
    bool bFirstPass;
    unsigned char _pad65[3];
    int iShaderType;
};
