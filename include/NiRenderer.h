#pragma once

#include "NiObject.h"

class Direct3DDeviceInterface;
class Ni2DBuffer;
class NiCamera;
class NiColor;
class NiD3DShaderDeclaration;
class NiDepthStencilBuffer;
class NiDynamicEffect;
class NiFragmentMaterial;
class NiGeometry;
class NiGeometryData;
class NiMaterialProperty;
class NiPixelData;
class NiScreenTexture;
class NiSkinInstance;
class NiSkinPartition;
class NiTexture;
class NiVector4;
class NiDynamicEffectState;
class NiPropertyState;
class NiRenderTargetGroup;
class NiVec4;
class RenderTargetGroup;
template <class T> class NiRect;

class NiRenderer : public NiObject
{
public:
    enum ClearFlags  // flag values: Xbox PDB NiRenderer::ClearFlags
    {
        CLEAR_BACKBUFFER = 1,
        CLEAR_STENCIL = 2,
        CLEAR_ZBUFFER = 4,
        CLEAR_NONE = 0,
        CLEAR_ALL = 7
    };

    virtual ~NiRenderer();

    // NiObject supplies slots 0 through 34; this is slot 35.
    virtual void Unk_23();

    // Slots 36-74: the Gamebryo 2.2 NiRenderer interface, implemented by NiDX9Renderer (vftable 0x010ee4bc;
    // argument counts from the implementations' ret N). Code outside the DX9 renderer calls them through
    // NiRenderer* (NiGeometryData's destructor calls PurgeGeometryData, slot 60). The image's own NiRenderer
    // vftable (0x0109bb94) holds only slots 0-35.
    virtual bool SetDefaultProgramCache(NiFragmentMaterial* pkMaterial, bool bAutoWriteToDisk, bool bWriteDebugFile,
                                        bool bLoad, bool bNoNewProgramCreation, const char* pcWorkingDir); // 36
    virtual void Unk_25(void); // 37 (0x00e6ee00, 3 args)
    virtual void Unk_26(void); // 38 (0x00e695c0, 1 arg)
    virtual const char* GetDriverInfo() const; // 39
    virtual unsigned int GetFlags() const; // 40
    virtual void SetDepthClear(const float fZClear); // 41
    virtual float GetDepthClear() const; // 42
    // Gamebryo: SetBackgroundColor(const NiColor&), SetBackgroundColor(const NiColorA&), GetBackgroundColor(NiColorA&);
    // VC9 lays the overload group out in reverse, so the NiColorA setter is slot 43.
    virtual void SetBackgroundColor(const NiColor& kColor); // 44
    virtual void SetBackgroundColor(NiVector4* inARGB); // 43 (NiColorA)
    virtual void GetBackgroundColor(NiVector4* outARGB); // 45 (NiColorA)
    virtual void SetStencilClear(unsigned int uiClear); // 46
    virtual unsigned int GetStencilClear() const; // 47
    virtual bool ValidateRenderTargetGroup(NiRenderTargetGroup* pkTarget); // 48
    virtual bool IsDepthBufferCompatible(Ni2DBuffer* pkBuffer, NiDepthStencilBuffer* pkDSBuffer); // 49
    virtual NiRenderTargetGroup* GetDefaultRT(); // 50 GetDefaultRenderTargetGroup
    virtual NiRenderTargetGroup* GetCurrentRT(); // 51 GetCurrentRenderTargetGroup
    virtual NiDepthStencilBuffer* GetDefaultDepthStencilBuffer() const; // 52
    virtual Ni2DBuffer* GetDefaultBackBuffer() const; // 53
    virtual unsigned int GetMaxBuffersPerRenderTargetGroup() const; // 54
    virtual bool GetIndependentBufferBitDepths() const; // 55
    virtual bool PrecacheTexture(NiTexture* pkIm, bool bForceLoad, bool bLocked); // 56
    virtual bool SetMipmapSkipLevel(unsigned int uiSkip); // 57
    virtual unsigned int GetMipmapSkipLevel() const; // 58
    virtual bool PrecacheGeometry(NiGeometry* pkGeometry, unsigned int uiBonesPerPartition,
                                  unsigned int uiBonesPerVertex, NiD3DShaderDeclaration* pkShaderDeclaration); // 59
    virtual void PurgeGeometryData(NiGeometryData* pkData); // 60
    virtual void PurgeMaterial(NiMaterialProperty* pkMaterial); // 61
    virtual void PurgeEffect(NiDynamicEffect* pkEffect); // 62
    virtual void PurgeScreenTexture(NiScreenTexture* pkScreenTexture); // 63
    virtual void PurgeSkinPartitionRendererData(NiSkinPartition* pkSkinPartition); // 64
    virtual void PurgeSkinInstance(NiSkinInstance* pkSkinInstance); // 65
    virtual bool PurgeTexture(NiTexture* pkTexture); // 66
    virtual bool PurgeAllTextures(bool bPurgeLocked); // 67
    virtual NiPixelData* TakeScreenShot(const NiRect<unsigned int>* pkScreenRect,
                                        const NiRenderTargetGroup* pkTarget); // 68
    virtual bool FastCopy(const Ni2DBuffer* pkSrc, Ni2DBuffer* pkDest, const NiRect<unsigned int>* pkSrcRect,
                          unsigned int uiDestX, unsigned int uiDestY); // 69
    virtual bool Copy(const Ni2DBuffer* pkSrc, Ni2DBuffer* pkDest, NiRect<unsigned int>* pkSrcRect,
                      NiRect<unsigned int>* pkDestRect, unsigned int copyFilter); // 70
    virtual bool GetLeftRightSwap() const; // 71
    virtual bool SetLeftRightSwap(bool bSwap); // 72
    virtual float GetMaxFogValue() const; // 73
    virtual void SetMaxFogValue(float fFogVal); // 74

    void StartScene();
    void FinishScene();
    RenderTargetGroup* GetDefaultRenderTargetGroup();
    void SetCurrentCamera(NiCamera* camera);
    void TryUnlock();
    void CallFooForEachElement(int, int, const NiVec4*);
    bool MapScreenCoordinates(unsigned int x, unsigned int y,
                              float& mappedX, float& mappedY,
                              const NiRenderTargetGroup* group);

    void NiDX9Renderer_PerformPrecache();
    void NiXenonRenderer_LockRenderer();
    void NiXenonRenderer_UnlockRenderer();
    Direct3DDeviceInterface* NiXenonRenderer_GetD3DDevice();
    int FUN_004e9530();
    unsigned int FUN_004dee70();
    unsigned int FUN_004dee10();

    static NiRenderer* ms_pRenderer;

    unsigned char m_spAccum[4]; // 0x008
    NiPropertyState* m_pkCurrProp; // 0x00C
    NiDynamicEffectState* m_pkCurrEffects; // 0x010
    unsigned char m_spErrorShader[4]; // 0x014
    unsigned char _pad18[0x68]; // 0x018
    unsigned char m_kRendererLock[0x80]; // 0x080
    unsigned char m_kPrecacheCriticalSection[0x80]; // 0x100
    unsigned char m_kSourceDataCriticalSection[0x80]; // 0x180
    int m_eFrameState; // 0x200
    unsigned int m_uiFrameID; // 0x204
    bool m_bRenderTargetGroupActive; // 0x208
    bool m_bBatchRendering; // 0x209
    unsigned char _pad20A[0x76]; // 0x20A
};
