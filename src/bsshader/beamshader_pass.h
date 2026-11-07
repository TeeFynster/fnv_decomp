// bsshader/beamshader_pass.h: beam pass helpers and this unit's NiD3DPass inline methods
#ifndef BEAMSHADER_PASS_H
#define BEAMSHADER_PASS_H

#include "../../include/NiD3DPass.h"
#include "NiRefObject.h"
class BeamTextureState
{
  public:
    void NiD3DTextureStageGroup_SetSamplerState(unsigned int, unsigned int, unsigned int, bool);
};
class BeamStage
{
  public:
    unsigned char pad0[0x10];
    BeamTextureState* state;
    unsigned char pad14[0x4c];
    unsigned int refs;
    void IncRefCount()
    {
        ++refs;
    }
    void DecRefCount()
    {
        if (--refs == 0)
            ReturnToPool();
    }
    void ReturnToPool();
    static void CreateNewStage(NiPointer<BeamStage>&);
};
class D3DRenderStateGroup
{
  public:
    static D3DRenderStateGroup* GetCurrentRenderStateGroup();
    void SetRenderState(unsigned int, unsigned int, bool);
};
inline unsigned int NiD3DPass::GetStageCount() const
{
    return m_uiStageCount;
}

inline void NiD3DPass::IncRefCount()
{
    ++m_uiRefCount;
}

inline void NiD3DPass::DecRefCount()
{
    if (--m_uiRefCount == 0)
        DestroyPass();
}

inline void NiD3DPass::SetRenderState(unsigned int state, unsigned int value, bool save)
{
    if (!m_pkRenderStateGroup)
        m_pkRenderStateGroup = D3DRenderStateGroup::GetCurrentRenderStateGroup();
    m_pkRenderStateGroup->SetRenderState(state, value, save);
}

class BeamPassPointer
{
  public:
    NiD3DPass* object;
    BeamPassPointer() : object(0)
    {}
    ~BeamPassPointer()
    {
        if (object)
            object->DecRefCount();
    }
    void operator=(NiD3DPass* const& p)
    {
        if (object != p)
        {
            if (object)
                object->DecRefCount();
            object = p;
            if (object)
                object->IncRefCount();
        }
    }
};
class BeamStagePointer
{
  public:
    BeamStage* object;
    BeamStagePointer() : object(0)
    {}
    ~BeamStagePointer()
    {
        if (object)
            object->DecRefCount();
    }
};
void ConfigureBeamStage(BeamStage*, unsigned int, unsigned int, unsigned int, bool);
class BeamPassShader
{
  public:
    unsigned char padding[0xb4];
    NiPointer<NiD3DPass> pass;
    NiRefObject* vertex;
    NiRefObject* pixel;
    void SetupPass();
    bool InitializePass();
};
#endif
