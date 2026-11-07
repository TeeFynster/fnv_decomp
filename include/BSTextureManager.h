#pragma once

#include "NiPointer.h"
#include "NiTPointerAllocator.h"
#include "NiTPointerListBase.h"

class BSRenderedTexture;
class NiRenderer;
class NiDepthStencilBuffer;
class NiRefObject;

class BSTextureManager
{
public:
    // src: XBOX_PDB
    enum eTextureType
    {
        TEX_UNKNOWN = -1, // src: XBOX_PDB
        TEX_HDR_FIRST = 0, // src: XBOX_PDB
        TEX_HDR_DOWNSAMPLE = 0, // src: XBOX_PDB
        TEX_HDR_DOWNSAMPLE_ANISOINTERMEDIATE = 1, // src: XBOX_PDB
        TEX_HDR_BLURSWAP = 2, // src: XBOX_PDB
        TEX_HDR_LAST = 2, // src: XBOX_PDB
        TEX_IMAGESPACE_FIRST = 3, // src: XBOX_PDB
        TEX_IMAGESPACE_SWAP = 3, // src: XBOX_PDB
        TEX_IMAGESPACE_LAST = 3, // src: XBOX_PDB
        TEX_MAIN_FIRST = 4, // src: XBOX_PDB
        TEX_MAIN_IMAGESPACE = 4, // src: XBOX_PDB
        TEX_MAIN_FIRSTPERSON = 5, // src: XBOX_PDB
        TEX_MAIN_MENUBG = 6, // src: XBOX_PDB
        TEX_MAIN_LAST = 6, // src: XBOX_PDB
        TEX_TESWATER_FIRST = 7, // src: XBOX_PDB
        TEX_TESWATER_FFT = 7, // src: XBOX_PDB
        TEX_TESWATER_GREY = 8, // src: XBOX_PDB
        TEX_TESWATER_REFLECTION = 9, // src: XBOX_PDB
        TEX_TESWATER_LOD_REFLECTION = 10, // src: XBOX_PDB
        TEX_TESWATER_REFRACTION = 11, // src: XBOX_PDB
        TEX_TESWATER_RAIN = 12, // src: XBOX_PDB
        TEX_TESWATER_SCRAMBLEMAP = 13, // src: XBOX_PDB
        TEX_TESWATER_IFFT_BUTTERFLYMAP = 14, // src: XBOX_PDB
        TEX_TESWATER_HIGH_W = 15, // src: XBOX_PDB
        TEX_TESWATER_HIGH_AMPLITUDE = 16, // src: XBOX_PDB
        TEX_TESWATER_DEPTH = 17, // src: XBOX_PDB
        TEX_TESWATER_NOISE_HEIGHTMAP = 18, // src: XBOX_PDB
        TEX_TESWATER_NOISE_NORMALMAP = 19, // src: XBOX_PDB
        TEX_TESWATER_DISPLACEMENT = 20, // src: XBOX_PDB
        TEX_TESWATER_DEBUG_DISPLAY = 21, // src: XBOX_PDB
        TEX_TESWATER_LAST = 21, // src: XBOX_PDB
        TEX_TREES_FIRST = 22, // src: XBOX_PDB
        TEX_TREES_CANOPYSHADOWMASK = 22, // src: XBOX_PDB
        TEX_TREES_LAST = 22, // src: XBOX_PDB
        TEX_BLUR_FIRST = 23, // src: XBOX_PDB
        TEX_BLURFULL_BUFFER = 23, // src: XBOX_PDB
        TEX_BLURFULL_SWAP = 24, // src: XBOX_PDB
        TEX_BLUR_LAST = 24, // src: XBOX_PDB
        TEX_BLUR20_FIRST = 25, // src: XBOX_PDB
        TEX_BLUR20_BUFFER = 25, // src: XBOX_PDB
        TEX_BLUR20_LAST = 25, // src: XBOX_PDB
        TEX_GETHIT_FIRST = 26, // src: XBOX_PDB
        TEX_GETHIT_BUFFER = 26, // src: XBOX_PDB
        TEX_GETHIT_LAST = 26, // src: XBOX_PDB
        TEX_LOCALMAP_FIRST = 27, // src: XBOX_PDB
        TEX_LOCALMAP_FINAL = 27, // src: XBOX_PDB
        TEX_LOCALMAP_COLOR = 28, // src: XBOX_PDB
        TEX_LOCALMAP_NORMALS = 29, // src: XBOX_PDB
        TEX_LOCALMAP_LAST = 29, // src: XBOX_PDB
        TEX_REFRACTION_FIRST = 30, // src: XBOX_PDB
        TEX_REFRACTION_NORMALS = 30, // src: XBOX_PDB
        TEX_REFRACTION_LAST = 30, // src: XBOX_PDB
        TEX_VFOG_FIRST = 31, // src: XBOX_PDB
        TEX_VFOG = 31, // src: XBOX_PDB
        TEX_SCENE_DEPTH_BUFFER = 32, // src: XBOX_PDB
        TEX_VFOG_SWAP = 33, // src: XBOX_PDB
        TEX_VFOG_LAST = 33, // src: XBOX_PDB
        TEX_VELOCITY_FIRST = 34, // src: XBOX_PDB
        TEX_VELOCITY = 34, // src: XBOX_PDB
        TEX_VELOCITY_SWAP = 35, // src: XBOX_PDB
        TEX_VELOCITY_LAST = 35, // src: XBOX_PDB
        TEX_DOF_FIRST = 36, // src: XBOX_PDB
        TEX_DOF_BLUR = 36, // src: XBOX_PDB
        TEX_DOF_BLUR_SWAP = 37, // src: XBOX_PDB
        TEX_DOF_MASK = 38, // src: XBOX_PDB
        TEX_DOF_LAST = 38, // src: XBOX_PDB
        TEX_DEPTH_RADIALBLUR_FIRST = 39, // src: XBOX_PDB
        TEX_DEPTH_RADIALBLUR_BLUR = 39, // src: XBOX_PDB
        TEX_DEPTH_RADIALBLUR_LAST = 39, // src: XBOX_PDB
        TEX_CUBEMAP_FIRST = 40, // src: XBOX_PDB
        TEX_CUBEMAP_CAMERA = 40, // src: XBOX_PDB
        TEX_CUBEMAP_LAST = 40, // src: XBOX_PDB
        TEX_SHADOWS_FIRST = 41, // src: XBOX_PDB
        TEX_SHADOWS_SHADOWMAP = 41, // src: XBOX_PDB
        TEX_SHADOWS_SHADOWMAPFRUSTUM = 42, // src: XBOX_PDB
        TEX_SHADOWS_LAST = 42, // src: XBOX_PDB
        TEX_ENVMAP_FIRST = 43, // src: XBOX_PDB
        TEX_ENVMAP_WINDOWS = 43, // src: XBOX_PDB
        TEX_ENVMAP_LAST = 43, // src: XBOX_PDB
        TEX_INTERFACE_FIRST = 44, // src: XBOX_PDB
        TEX_INTERFACE_RENDEREDMENU = 44, // src: XBOX_PDB
        TEX_INTERFACE_RENDEREDMENU_SWAP = 45, // src: XBOX_PDB
        TEX_INTERFACE_VATS = 46, // src: XBOX_PDB
        TEX_INTERFACE_RACESEXMENU = 47, // src: XBOX_PDB
        TEX_INTERFACE_TEMP = 48, // src: XBOX_PDB
        TEX_INTERFACE_LAST = 48, // src: XBOX_PDB
        TEX_NOISE_FIRST = 49, // src: XBOX_PDB
        TEX_NOISE_BUFFER = 49, // src: XBOX_PDB
        TEX_NOISE_LAST = 49, // src: XBOX_PDB
        TEX_DECAL_FIRST = 50, // src: XBOX_PDB
        TEX_DECAL_OCCLUSION = 50, // src: XBOX_PDB
        TEX_DECAL_LAST = 50, // src: XBOX_PDB
        TEX_COUNT = 51 // src: XBOX_PDB
    };

    enum RenderTargetType
    {
        BSTM_RT_SCENE_DEPTH_BUFFER = 33
    };

    typedef NiTPointerListBase<NiTPointerAllocator<unsigned int>, NiPointer<BSRenderedTexture> > ShadowRefList;

    ShadowRefList unk00[5];       // 0x00
    ShadowRefList inactive[5];    // 0x3c
    ShadowRefList list78;         // 0x78
    ShadowRefList list84;         // 0x84
    ShadowRefList pending;        // 0x90
    ShadowRefList active;         // 0x9c
    NiPointer<NiDepthStencilBuffer> depth; // 0xa8
    NiPointer<NiDepthStencilBuffer> other; // 0xac

    BSRenderedTexture* ActivatePending();

    void AddRenderedTexture();
    void AddRenderedTexture(BSRenderedTexture*);
    BSRenderedTexture* CreateRenderTargetTexture(NiRenderer* renderer, int type, unsigned int flags,
                                                 BSRenderedTexture* alias, unsigned int aliasOffset);
    void RemoveRenderedTexture(BSRenderedTexture*);
    void BSTextureManager_ReturnFrustumShadowTexture(NiRefObject*);
    void ReleaseByName(const char* name);
    void* BSTextureManager_BorrowRenderedTexture(void* a1, int a2, int a3, int a4, int a5);
};
