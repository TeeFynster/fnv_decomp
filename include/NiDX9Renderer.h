#pragma once

#include "NiRenderer.h"
#include "Ni2DBuffer.h"

struct IDirect3DDevice9;
class NiD3DGeometryGroupManager;
class NiDX9RenderState;
class NiDX9LightManager;
class NiVector4;
class NiTexture;
class NiGeometryData;
class NiMaterialProperty;
class NiDynamicEffect;
class NiSkinPartition;
class NiSkinInstance;
class NiPixelData;
class NiSourceTexture;
class NiRenderedTexture;
struct Geometry;
struct Flags;
struct Shape;
struct Color;
struct Mesh;
struct Batch;
struct LocalTransform;
struct Bound;
template <class T> class NiRect;

class NiDX9Renderer : public NiRenderer
{
public:

    // Slots 36-74: NiRenderer interface overrides (NiRenderer.h).
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
    virtual void Unk_4B(unsigned int size);
    virtual void Unk_4C(unsigned int arg0, unsigned int arg1);
    virtual void Unk_4D(unsigned int arg0, unsigned int arg1);
    virtual void Unk_4E(void* buf);
    virtual void CreateSourceTexture(NiSourceTexture* texture);
    virtual bool CreateRenderedTexture(NiRenderedTexture* texture,
                                               Ni2DBuffer::MultiSamplePreference preference);

    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
    virtual void vf96();
    virtual void vf97();
    virtual void vf98();
    virtual void vf99();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void vf114();

    unsigned int __thiscall NiDX9Renderer_GetMaxBuffersPerRenderTargetGroup();
    bool NiDX9Renderer_IsHardwareSkinned(void* geometry, int flag);
    bool NiDX9Renderer_IsHardwareSkinned(void* geometry, void* shader);
    void DrawStrip(void* geometry, unsigned int geometryData, unsigned int skinInstance,
                   void* transform, void* bound);
    void DrawStrip(Geometry* geometry, Flags* flags, Shape* shape, void* context, Color* color);
    void DrawMesh(void* geometry, unsigned int geometryData, unsigned int skinInstance,
                  void* transform, void* bound, unsigned int flags);
    void DrawMesh(Mesh* mesh, unsigned int geometryData, unsigned int skinInstance,
                  void* transform, void* bound, Batch* batch);
    void DrawMesh(int geometry, int geometryData, int skinInstance,
                  LocalTransform* transform, Bound* bound, void* batch);

    unsigned char _undescribed_280[8];
    IDirect3DDevice9* pD3DDevice;
    unsigned char _undescribed_28C[828];
    int eDevType;
    unsigned char _undescribed_5CC[20];
    unsigned char aucBackgroundColor[4];
    float fDepthClear;
    unsigned int uiStencilClear;
    unsigned int uiFlags;
    unsigned char _undescribed_5F0[660];
    NiRenderTargetGroup* pDefaultRenderTargetGroup;
    NiRenderTargetGroup* pCurrentRenderTargetGroup;
    unsigned char _undescribed_88C[20];
    unsigned int uiMaxBuffersPerRenderTargetGroup;
    bool bIndependentBufferBitDepths;
    unsigned char _undescribed_8A5[7];
    NiD3DGeometryGroupManager* pGeometryGroupManager;
    unsigned char _undescribed_8B0[8];
    NiDX9RenderState* pRenderState;
    unsigned char _undescribed_8BC[12];
    NiDX9LightManager* pLightManager;
    unsigned char _undescribed_8CC[180];
    float kD3DView[16];
    float kD3DProj[16];
    unsigned char _undescribed_A00[208];
    bool bVerticalDisplay;
    unsigned char _undescribed_AD1[175];
};
