#pragma once

#include "NiShadeProperty.h"

class NiAVObject;
class NiGeometry;
class ShadowSceneLight;

class BSShaderProperty : public NiShadeProperty
{
  public:
    class ShaderPassEntry;
    class ShaderPassList;

    enum TextureTypeEnum  // values: Xbox PDB BSShaderProperty::TextureTypeEnum
    {
        TEXTYPE_DIFFUSE = 0,
        TEXTYPE_BASE = 0,
        TEXTYPE_NORMAL = 1,
        TEXTYPE_GLOSS = 1,
        TEXTYPE_GLOW = 2,
        TEXTYPE_SKIN_SST = 2,
        TEXTYPE_HAIR_LAYER = 2,
        TEXTYPE_HEIGHT = 3,
        TEXTYPE_ENV = 4,
        TEXTYPE_ENV_MASK = 5,
        TEXTYPE_SPECULAR = 6,
        TEXTYPE_COUNT = 7
    };

    BSShaderProperty();
    BSShaderProperty& operator=(const BSShaderProperty& property);

    void CopyMemberData(BSShaderProperty* property, CloningProcess* cloning);
    static NiObject* CreateObject();
    void* QRenderPasses();
    void CheckCreateRenderPassArray(int count);
    void CheckCreateDepthMapRenderPassArray(int count);
    void CheckCreateLocalMapRenderPassArray(int count);
    void CheckCreateSIBlockRenderPassArray(int count);
    void CheckCreateConstAlphaRenderPassArray(int count);
    void CheckCreateWaterFogRenderPassArray(int count);
    void CheckSilhouetteRenderPassArray(int count);
    void SetLastRenderPassState(int state);
    bool CompareFlags(BSShaderProperty* property);
    bool GetFlag(unsigned int flag);
    void SetFlag(unsigned int flag, bool enabled);
    void SetAlpha(float alpha);
    float GetAlpha();
    float GetFadeAlpha();
    void SetFadeAlpha(float alpha);
    void FreeRenderPasses();
    void ClearRenderPasses();
    void SetObjectType(unsigned int type);
    unsigned int GetObjectType();
    int QShader();
    void SetShader(int shader);
    float QEnvmapScale();
    void SetEnvmapScale(float scale);
    static void ToggleMotionBlurRecurse(NiAVObject* object);
    static void SetMotionBlurRecurse(NiAVObject* object, bool enabled);
    static void SetFlagRecurse(NiAVObject* object, int flag, bool enabled);
    bool Get1stPerson();
    void Set1stPerson(bool enabled);
    float GetDepthBias();
    void SetDepthBias(float bias);
    static void ResetDebugStats();
    static void GetDebugStats(unsigned int* stats);
    void SetMotionBlurred(bool enabled);
    float GetCameraDistance();
    static void ClearRenderPassGarbage();

    unsigned long ulFlags[2];
    float fAlpha;
    float fFadeAlpha;
    float fEnvmapScale;
    float fCameraDistance;
    int iLastRenderPassState;
    void* pRenderPassList;
    void* pDepthMapRenderPassList;
    void* pConstAlphaRenderPassList;
    void* pLocalMapRenderPassList;
    void* pSIBlockRenderPassList;
    void* pWaterFogRenderPassList;
    void* pSilhouettePassList;
    int iShader;
    float fDepthBias;
};

// A render pass (0x10 bytes): the geometry, its pass type, and the shadow-scene lights it is lit by.
class BSShaderProperty::ShaderPassEntry
{
  public:
    NiGeometry* m_pShaderGeometry;
    unsigned short m_usShaderPassType;
    unsigned char m_ucLightIndex;
    bool m_bIsBest;
    bool m_bRendered;
    unsigned char m_ucLightCount;
    unsigned char m_ucLightCapacity;
    unsigned char m_ucPassIndex;
    ShadowSceneLight** m_ppShadowSceneLights;

    ShaderPassEntry(NiGeometry* geometry, unsigned short passType, bool first, unsigned char lightCount,
                    ShadowSceneLight* light0, ...);  // 0x00ba8ec0
    void __cdecl BSShaderProperty_RenderPass_SetLights(unsigned char lightCount, ShadowSceneLight* light0, ...);  // 0x00ba8c50
    void SetPassEnum(unsigned short value)
    {
        m_usShaderPassType = value;
    }
    void SetFirstPass(bool value)
    {
        m_bIsBest = value;
    }
    void SetGeometry(NiGeometry* value)
    {
        m_pShaderGeometry = value;
    }
    static void* operator new(unsigned int size);  // the game heap (ShaderPassList::Add, 0x00ba9ee0)
};

// A property's render-pass list (0x14 bytes): the pass array and the number of passes in use.
class BSShaderProperty::ShaderPassList
{
  public:
    void Add(NiGeometry* geometry, unsigned short passType, bool first, unsigned char lightCount, ShadowSceneLight* light0,
             ShadowSceneLight* light1, ShadowSceneLight* light2, ShadowSceneLight* light3);

    // NiTObjectArray<ShaderPassEntry*> in the original (vftable, base, max size, size, used, grow by); its layout is
    // spelled out here because the shared array templates (NiNode.h) cannot be included by this header's users.
    class PassArray
    {
      public:
        virtual ~PassArray();
        ShaderPassEntry** m_pBase;
        unsigned short m_usMaxSize;
        unsigned short m_usSize;
        unsigned short m_usESize;
        unsigned short m_usGrowBy;
    };

    PassArray m_kRenderPasses;
    unsigned int m_uiCount;
};
typedef char BSShaderProperty_ShaderPassEntry_size_check[(sizeof(BSShaderProperty::ShaderPassEntry) == 0x10) ? 1 : -1];
typedef char BSShaderProperty_ShaderPassList_size_check[(sizeof(BSShaderProperty::ShaderPassList) == 0x14) ? 1 : -1];
