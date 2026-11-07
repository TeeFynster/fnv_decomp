#pragma once

#include "NiNode.h"

class BeamStage;
class D3DRenderStateGroup;
class NiD3DPixelShader;
class NiD3DShaderConstantMap;
class NiD3DVertexShader;
class NiGeometry;
class NiGeometryBufferData;
class NiSkinInstance;

class NiD3DPass
{
public:
    virtual ~NiD3DPass();
    virtual unsigned int SetupShaderPrograms(
        NiGeometry* geometry, const NiSkinInstance* skin, void* rendererData,
        NiGeometryBufferData* bufferData, const NiPropertyState* properties,
        const NiDynamicEffectState* effects, const NiTransform* world,
        const NiBound* bound, unsigned int pass);
    virtual unsigned int SetupRenderingPass(
        NiGeometry* geometry, const NiSkinInstance* skin,
        NiGeometryBufferData* bufferData, const NiPropertyState* properties,
        const NiDynamicEffectState* effects, const NiTransform* world,
        const NiBound* bound, unsigned int pass);
    virtual unsigned int PostProcessRenderingPass(unsigned int pass);

    static void CreateD3DPass(NiPointer<NiD3DPass>& pass);
    static void CreateD3DPass(NiD3DPass*& pass);
    static void CreateD3DPass(void** pass);
    static void SetActiveRenderer(void* renderer);

    void DestroyPass();
    void FUN_00e80190();
    void NiD3DPass_SetVertexShader(NiD3DPixelShader* shader);
    void NiD3DPass_SetPixelShader(NiD3DVertexShader* shader);
    void DeleteThis();
    void Release();
    void IncRefCount();
    void DecRefCount();
    bool ApplyRenderStateChanges(bool force);
    NiD3DPass* SetD3DDevice(unsigned int count);
    void ApplyPassState();
    void SetAlphaBlendMode(unsigned int sourceBlend, unsigned int destinationBlend,
                           bool sourceAlpha);
    D3DRenderStateGroup* GetRenderStateGroup();
    unsigned int GetStageCount() const;
    void AppendStage(BeamStage* stage);
    void NiD3DPass_SetStage(unsigned int stageNum, BeamStage* stage);
    void SetRenderState(unsigned int state, unsigned int value, bool save);
    template <class Result>
    Result SetRenderState(unsigned int state, unsigned int value, bool save);
    void SetRenderState(unsigned int state, unsigned int value);
    void SetVertexShader(NiD3DVertexShader* shader);
    void SetPixelShader(NiD3DPixelShader* shader);
    void SetPixelConstantMap(NiD3DShaderConstantMap* map);
    void SetVertexConstantMap(NiD3DShaderConstantMap* map);

    char m_szName[16];
    unsigned int m_uiCurrentStage;
    unsigned int m_uiStageCount;
    unsigned int m_uiTexturesPerPass;
    NiTObjectArray<NiPointer<BeamStage> > m_kStages;
    D3DRenderStateGroup* m_pkRenderStateGroup;
    NiPointer<NiD3DShaderConstantMap> m_spPixelConstantMap;
    char* m_pcPixelShaderProgramFile;
    char* m_pcPixelShaderEntryPoint;
    char* m_pcPixelShaderTarget;
    NiPointer<NiD3DPixelShader> m_spPixelShader;
    NiPointer<NiD3DShaderConstantMap> m_spVertexConstantMap;
    char cEnabledStages;
    unsigned char _pad4D[3];
    char* m_pcVertexShaderProgramFile;
    char* m_pcVertexShaderEntryPoint;
    char* m_pcVertexShaderTarget;
    NiPointer<NiD3DVertexShader> m_spVertexShader;
    bool m_bSoftwareVP;
    bool m_bRendererOwned;
    unsigned char _pad62[2];
    unsigned int m_uiRefCount;
};
