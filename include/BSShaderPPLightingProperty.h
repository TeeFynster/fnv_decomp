#pragma once

#include "BSShaderLightingProperty.h"
#include "NiAVObject.h"
#include "NiColorA.h"

class BSShaderAccumulator;
class BSShaderTextureSet;
class BSTextureSet;
class BSShaderProperty__RenderPass;
class BSShaderPPLightingProperty__TangentSpaceData;
class NiAdditionalGeometryData;
class NiSourceTexture;
class NiTexture;
class NiPoint3;

class BSShaderPPLightingProperty : public BSShaderLightingProperty
{
  public:
    BSShaderPPLightingProperty();

    class TextureEffectData
    {
      public:
        unsigned char data[0x6c];
        NiPointer<NiSourceTexture> spTexture;
    };
    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& cloning);
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void PostLinkObject(NiStream& arStream);

    void CopyTo(BSShaderPPLightingProperty*);
    void CopyToMembers(BSShaderPPLightingProperty*);
    NiAdditionalGeometryData* CreateRendererSpecificProperty(NiGeometry*);
    int GetClampD3D();
    void SetClampD3D(int);
    int GetClampNI();
    void SetClampNI(int);
    unsigned short GetTextureCount();
    unsigned short QLandscapeTextureCount();
    void SetTexture(int, unsigned int, NiTexture*);
    NiTexture* GetTexture(int, unsigned int);
    void SetRectangleBounds(BSShaderTextureSet*);
    void SetDiffuseTexture(unsigned int, NiTexture*);
    void SetNormalTexture(unsigned int, NiTexture*);
    void SetSpecularTexture(unsigned int, NiTexture*);
    void SetGlowTexture(unsigned int, NiTexture*);
    void SetFlagsFromTextures();
    float GetSpecularLODFade();
    float GetEnvMapLODFade();
    void GetRenderPasses_1x(NiGeometry*, int, unsigned short*, unsigned int, BSShaderAccumulator*, bool);
    void GetRenderPasses_2x(NiGeometry*, int, unsigned short*, unsigned int, BSShaderAccumulator*, bool);
    void* GetRTTI();
    NiObject* MakeClone(CloningProcess*);
    void CopyMemberData(BSShaderPPLightingProperty*, CloningProcess*);
    void GetViewerStrings(void*);
    void LoadBinary(NiStream*);
    void LinkObject(NiStream*);
    bool RegisterStreamables(NiStream*);
    void SaveBinary(NiStream*);
    bool IsEqual(NiObject*);
    static NiObject* CreateObject();
    void PostLinkObject(NiStream*);
    bool SetupGeometry(NiGeometry*);
    void* CreateRenderPasses(NiGeometry*, int, unsigned short*, unsigned int, BSShaderAccumulator*, bool);
    unsigned short GetNumberofPasses(NiGeometry*);
    void* GetRenderDepthPass(NiGeometry*);
    NiTexture* GetBaseTexture();
    NiTexture* GetDiffuseTextureIndex(unsigned int);
    NiTexture* GetNormalMapTexture(unsigned int);
    NiTexture* GetSpecularTexture(unsigned int);
    NiTexture* GetGlowTexture(unsigned int);
    void* GetExtraDataPointers();
    NiPoint3* GetTangentExtraData();
    NiPoint3* GetBinormalExtraData();
    void StoreExtraDataPointers(void*);
    void StoreTextureSplatVertexDataPointers(float*);
    static bool GetForceNoProjectedShadowTexture();
    static void SetForceNoProjectedShadowTexture(bool);
    void SetLandscapeSpecularExponents(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char,
                                       unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
    void SetForLandscapeTextures();
    void SetLandscapeTextureSet(unsigned int, BSTextureSet*);
    NiTexture* GetLandscapeTexture(unsigned short);
    bool GetTextureSpecular(int);
    float GetTextureSpecularExponent(int);
    void SetTextureEffectData(void*);
    void* GetTextureEffectData();
    static void UpdateRefractionRecurse(NiAVObject*, bool, float, bool, float, bool);
    static bool HasRefractionRecurse(NiAVObject*);
    float GetRefractionPower();
    void SetRefractionPower(float);
    int GetRefractionFirePeriod();
    void SetRefractionFirePeriod(int);
    float GetParallaxOccMaxPasses();
    void SetParallaxOccMaxPasses(float);
    float GetParallaxOccScale();
    void SetParallaxOccScale(float);
    bool QRemappableTextures();
    void SetTextureSet(BSTextureSet*);
    void CopyTextureSet(BSTextureSet*);
    void LoadTextureSet(char*, BSTextureSet*);
    void EnsureNormalMap();
    BSShaderProperty* ClarifyShader(NiGeometry*, bool, bool);
    void* GetWaterFogPassList(NiGeometry*);
    void GetTextureUse(int*, void*);
    float GetTerrainTexOffsetX();
    float GetTerrainTexOffsetY();
    float GetTerrainTexFade();
    float GetTerrainDetailTexScale();
    void SetTerrainTexParams(float, float, float);
    void SetTerrainDetailTexScale(float);
    void PrecacheTextures();
    void* AddZOnlyPass_1x(NiGeometry*, unsigned short*, bool, bool*, bool, bool);
    void* AddZOnlyTextureEffectPass_1x(NiGeometry*, unsigned short*, bool, bool*, bool);
    void AddConstAlphaPass_1x(NiGeometry*, bool, bool);
    void* AddAmbientPass_1x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool, bool, bool);
    void* AddAmbDiffTexPass_1x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool, bool, bool,
                               bool, bool, bool);
    void* AddAmbDiffDirAndPtPass_1x(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*, bool, bool*,
                                    bool, bool);
    void* AddDiffusePass_1x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool, bool, bool);
    void* AddAmbientDiffuseTexturePass_1x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool,
                                          bool, bool, bool, bool);
    void* AddSpecularPass_1x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool, bool, bool, bool,
                             bool);
    void* AddEnvmapPass_1x(NiGeometry*, unsigned short*, bool, bool*, bool, bool);
    void* AddFogPass_1x(NiGeometry*, unsigned short*, bool, bool*, bool, bool, bool);
    void AddLandscapePasses_1x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool);
    void* AddTextureEffectPass_1x(NiGeometry*, unsigned short*, bool, bool*, bool);
    void* AddTextureEffectPass_2x(NiGeometry*, unsigned short*, bool, bool*, bool);
    void* AddRenderNormalsPass_1x(NiGeometry*, unsigned short*, bool, bool*, bool, bool);
    void* AddRenderNormalsClearPass_1x(NiGeometry*, unsigned short*, bool, bool*, bool);
    void* AddVelocityPass_2x(NiGeometry*, unsigned short*, bool, bool*, bool);
    void* AddSelfIllumAlphaPass(NiGeometry*, unsigned short*, bool, bool, bool);
    void* AddSelfIllumAlphaBlockPass(NiGeometry*, unsigned short*, bool, bool);
    void* AddAmbDiff2Pass_2x(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*, bool, bool*, bool,
                             bool, bool, bool, bool, bool, bool);
    void* AddAmbDiff3Pass_2x(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*,
                             bool, bool*, bool, bool, bool, bool, bool, bool, bool);
    void* AddAmbDiffTexPass_2x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool, bool, bool,
                               bool, bool, bool, bool, bool, bool, bool);
    void* AddAmbDiffTex2Pass_2x(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*, bool, bool*, bool,
                                bool, bool, bool, bool, bool, bool, bool);
    void* AddAmbDiffTexSpecularPass_2x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool, bool,
                                       bool, bool, bool, bool, bool);
    void* AddAmbDiffTexSpecular2Pass_2x(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*, bool, bool*,
                                        bool, bool, bool, bool, bool, bool, bool, bool);
    void* AddAmbDiffTexSpecular10Pass_2x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool, bool,
                                         bool, bool);
    void* AddDiffusePt2Pass_2x(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*, bool, bool*, bool,
                               bool, bool, bool, bool);
    void* AddDiffusePt3Pass_2x(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*,
                               bool, bool*, bool, bool, bool, bool, bool);
    void* AddTexturePass_2x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool, bool, bool, bool,
                            bool, bool, bool);
    void* AddSpecularPass_2x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool, bool, bool, bool,
                             bool);
    void* AddSpecularPt2Pass_2x(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*, bool, bool*, bool,
                                bool, bool, bool);
    void* AddSpecularPt3Pass_2x(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*,
                                bool, bool*, bool, bool, bool, bool);
    void* AddEnvmapPass_2x(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool,
                           bool);
    void AddLandscapePasses_2x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool);
    void AddDepthMapPass_2x(NiGeometry*, bool, bool, BSShaderAccumulator*);
    void AddLocalMapPass_2x(NiGeometry*, bool, bool);
    void AddSilhouettePass_2x(NiGeometry*, bool);

    BSShaderProperty__RenderPass* AddAmbientDiffuseTexturePass_1x(
        NiGeometry*, ShadowSceneLight*, unsigned short&, bool, bool&, bool, bool, bool, bool, bool, bool);
    bool FUN_004a2020(int);
    bool GetFlag(int);
    int GetType();
    void SetFlag(int, bool);
    void SetTexture(int, NiTexture*);
    void SetTexture(int, int, NiSourceTexture*);
    void SetNormalTexture(int, NiTexture*);
    void SetNormalMap(unsigned int, NiTexture*);
    void SetTextureSet(BSShaderTextureSet*);
    void BuildShaderTextureSet(int, int);
    unsigned short GetDiffuseTextureIndex();
    NiTexture* GetNormalMapTexture();

    float _unverified_fWaterDepthCameraOffset;
    float _unverified_fGeomorphParam;
    NiColorA pHairTintColor;
    NiColorA LandBlendParamsA;
    NiPointer<BSTextureSet> spTextureSet;
    unsigned short iTextureCount;
    unsigned char _padAA[2];
    NiPointer<NiTexture>* spTextures[6];
    unsigned char* pSpecularExponent;
    unsigned short usLandscapeTextures;
    unsigned char _padCA[2];
    bool* pbGlossMap;
    NiPointer<BSShaderPPLightingProperty__TangentSpaceData> spTangentSpaceData;
    float* pTextureSplatVertexData;
    int TextureClampMode;
    NiPointer<TextureEffectData> spTexEffectData;
    float fRefractionPower;
    int iRefractionFirePeriod;
    float fParallaxOccMaxPasses;
    float fParallaxOccScale;
    float fTerrainTexOffsetX;
    float fTerrainTexOffsetY;
    float fTerrainTexFade;
    float _unverified_fTerrainDetailTexScale;
    BSShaderProperty__RenderPass* pRenderDepthPass;
};
