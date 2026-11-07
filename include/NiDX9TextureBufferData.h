#pragma once

#include "NiDX92DBufferData.h"

class IDirect3DTexture9;
struct IDirect3DBaseTexture9;
struct IDirect3DCubeTexture9;

// vftable 0x010eefbc (GetRTTI 0x00e7d220, ReleaseReferences 0x00e7d490): wraps a
// texture's surface, a cube map's face surface included.
class NiDX9TextureBufferData : public NiDX92DBufferData
{
public:
    NiDX9TextureBufferData() throw() : m_pkRenderTexture(0)
    {
    }
    virtual ~NiDX9TextureBufferData();
    virtual const NiRTTI* GetRTTI() const;
    virtual void ReleaseReferences();

    static NiDX9TextureBufferData* __cdecl Create_00e7d250(
        IDirect3DTexture9* pkD3DTexture, Ni2DBuffer*& pkBuffer,
        int eMSAAPref, int iUnk18);
    // 0x00e7d390: wraps face eFace (a D3DCUBEMAP_FACES) of a cube texture; the
    // existing face and the device are unused.
    static NiDX9TextureBufferData* __cdecl CreateCubeFace(
        IDirect3DCubeTexture9* pkD3DCubeTexture, int eFace,
        NiDX9TextureBufferData* pkExistingFace, IDirect3DDevice9* pkD3DDevice9,
        Ni2DBuffer*& pkBuffer);

    // The texture (0x00e7d250) or cube texture (0x00e7d390) the surface belongs to.
    IDirect3DBaseTexture9* m_pkRenderTexture;  // 0x20
};
