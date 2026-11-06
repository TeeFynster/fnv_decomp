#pragma once

#include "Ni2DBuffer.h"

struct IDirect3DDevice9;
struct IDirect3DSurface9;
class NiRTTI;
class NiNode;
class BSFadeNode;
class BSMultiBoundNode;
class NiGeometry;
class NiTriBasedGeom;
class NiTriStrips;
class NiTriShape;
class BSSegmentedTriShape;
class BSResizableTriShape;
class NiParticles;
class NiLines;
class bhkNiCollisionObject;
class bhkBlendCollisionObject;
class bhkRigidBody;
class bhkLimitedHingeConstraint;

// Gamebryo's DX9 renderer data of a 2D buffer, the root of its own RTTI tree
// (NiRTTI 0x0126f59c, "NiDX92DBufferData"). vftable 0x010eeed4, 27 slots.
// The original's sizeof is 0x20: the scalar deleting destructor in this class's
// vftable (0x00e7d620, slot 0) frees 0x20 bytes.
class NiDX92DBufferData : public Ni2DBuffer::RendererData
{
public:
    NiDX92DBufferData() throw() : m_pkSurface(0)
    {
    }
    virtual ~NiDX92DBufferData();

    // Slots 3..18: the root RTTI declaration. Slot 3 returns the class's NiRTTI
    // (0x00e7cd30 here, overridden per subclass); slots 4..18 all return 0
    // (0x00e7cd40). They are the fifteen type queries NiObject has right after its
    // GetRTTI (same count, same null default), named as NiObject names them.
    static const NiRTTI ms_RTTI;  // 0x0126f59c
    virtual const NiRTTI* GetRTTI() const;
    virtual NiNode* IsSceneNode() const;
    virtual BSFadeNode* IsFadeNode() const;
    virtual BSMultiBoundNode* IsMultiBoundNode() const;
    virtual NiGeometry* IsGeometry() const;
    virtual NiTriBasedGeom* IsTriBasedGeometry() const;
    virtual NiTriStrips* IsTriStrips() const;
    virtual NiTriShape* IsTriShape() const;
    virtual BSSegmentedTriShape* IsSegmentedTriShape() const;
    virtual BSResizableTriShape* IsResizableTriShape() const;
    virtual NiParticles* IsParticlesGeom() const;
    virtual NiLines* IsLineGeometry() const;
    virtual bhkNiCollisionObject* IsBhkNiCollisionObject() const;
    virtual bhkBlendCollisionObject* IsBhkBlendCollisionObject() const;
    virtual bhkRigidBody* IsBhkRigidBody() const;
    virtual bhkLimitedHingeConstraint* IsBhkLimitedHingeConstraint() const;

    // Slots 19..26, Gamebryo's NiDX92DBufferData interface:
    // 19 CanDisplayFrame: false (0x00ee8990), true in NiDX9ImplicitBufferData.
    // 20 DisplayFrame: false (0x00ee8990); NiDX9ImplicitBufferData Presents (0x00e7ccd0).
    // 21 Shutdown (0x00e7cc90): ReleaseReferences(), returns true.
    // 22 Recreate: false (0x00c9a420); subclasses rebuild their surfaces.
    // 23 SetRenderTarget (0x00e7cd50): sets m_pkMSAASurface, else m_pkSurface, as target uiTarget.
    // 24 SetDepthTarget: false (0x00c9a420); 0x00e7cdb0 in NiDX9DepthStencilBufferData.
    // 25 GetMSAAType (0x00be0ad0): returns m_uiMSAAType. The renderer (0x00e74dc0)
    //    StretchRects m_pkMSAASurface into m_pkSurface when it is non-zero.
    // 26 ReleaseReferences (0x00e7d180): releases m_pkSurface and the pixel format.
    virtual bool CanDisplayFrame();
    virtual bool DisplayFrame();
    virtual bool Shutdown();
    virtual bool Recreate(IDirect3DDevice9* pkD3DDevice9);
    virtual bool SetRenderTarget(IDirect3DDevice9* pkD3DDevice9, unsigned int uiTarget);
    virtual bool SetDepthTarget(IDirect3DDevice9* pkD3DDevice9);
    virtual unsigned int GetMSAAType();
    virtual void ReleaseReferences();

    IDirect3DSurface9* m_pkSurface;      // 0x14
    // The multisampled surface rendered into instead of m_pkSurface (0x00e7cd50) and
    // resolved into it by StretchRect (0x00e74dc0); NiDX9TextureBufferData's creator
    // (0x00e7d250) takes it as its last argument.
    IDirect3DSurface9* m_pkMSAASurface;  // 0x18
    // D3DMULTISAMPLE_TYPE of the surface: 0/2/4/8 for m_eMSAAPref 0..3 (0x00e7d250).
    unsigned int m_uiMSAAType;           // 0x1C
};
