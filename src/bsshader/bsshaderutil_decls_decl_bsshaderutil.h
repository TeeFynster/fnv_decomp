// bsshader/bsshaderutil_decls_decl_bsshaderutil.h: local shader utility declarations
#ifndef BSSHADERUTIL_DECLS_H
#define BSSHADERUTIL_DECLS_H

#include "MemoryManager.h"
#include "../../include/NiNode.h"
#include "../../include/NiRenderer.h"
#include "../../include/NiGlobalStringTable.h"

class NiCamera;
struct FadeProperties;

struct FourComponentFloatVector
{
    float ReportDiagnostic;
    float unused4;
    float unused8;
    float m_fBoundRadius;
};

struct FadeState
{
    unsigned char layoutPadding0[0x1c];
    int m_iFadeIndex;
    unsigned char layoutPadding20[0x0c];
    float m_fAlpha;
};

struct FadeProperties
{
    unsigned char layoutPadding0[0x9c];
    unsigned int m_uiInterior;
    unsigned char layoutPaddingA0[8];
    FadeState* m_pFadeState;
};

// BSShaderAccumulatorView: unit-local view of BSShaderAccumulator; this unit needs a NiPointer<NiRefObject> at 0xC4 and a three-argument
// virtual at 0x48 (called by 0x00b6bee0); the shared BSShaderAccumulator does not declare them.
class BSShaderAccumulatorView
{
  public:
    virtual void vfn_00() = 0;
    virtual void vfn_04() = 0;
    virtual void vfn_08() = 0;
    virtual void vfn_0c() = 0;
    virtual void vfn_10() = 0;
    virtual void vfn_14() = 0;
    virtual void vfn_18() = 0;
    virtual void vfn_1c() = 0;
    virtual void vfn_20() = 0;
    virtual void vfn_24() = 0;
    virtual void vfn_28() = 0;
    virtual void vfn_2c() = 0;
    virtual void vfn_30() = 0;
    virtual void vfn_34() = 0;
    virtual void vfn_38() = 0;
    virtual void vfn_3c() = 0;
    virtual void vfn_40() = 0;
    virtual void vfn_44() = 0;
    virtual void vfn_48(void* a, void* b, int c) = 0;
    virtual void vfn_4c() = 0;
    virtual void vfn_50() = 0;
    virtual void vfn_54() = 0;
    virtual void vfn_58() = 0;
    virtual void vfn_5c() = 0;
    virtual void vfn_60() = 0;
    virtual void vfn_64() = 0;
    virtual void vfn_68() = 0;
    virtual void vfn_6c() = 0;
    virtual void vfn_70() = 0;
    virtual void vfn_74() = 0;
    virtual void vfn_78() = 0;
    virtual void vfn_7c() = 0;
    virtual void vfn_80() = 0;
    virtual void vfn_84() = 0;
    virtual void vfn_88() = 0;
    virtual void SetCamera(const NiCamera*) = 0;
    virtual void vfn_90() = 0;
    virtual void vfn_94() = 0;
    virtual void vfn_98() = 0;
    virtual void vfn_9c() = 0;
    virtual void vfn_a0() = 0;
    virtual void vfn_a4() = 0;
    virtual void Unk_2A() = 0;
    virtual void Unk_2B() = 0;
    char padAccum04[0xc0];
    NiPointer<NiRefObject> texture;
};

extern NiCamera* DAT_011f917c;
extern void* DAT_011fa050;
extern void* DAT_011fa054;
extern MemoryManager g_memoryManager;
void BSShaderManager_SetCurrentAccumulator(BSShaderAccumulatorView* accumulator);

struct BSShaderUtilTextureName
{
    char* value;
    BSShaderUtilTextureName(const char* name) : value(NiGlobalStringTable::AddString(name))
    {}
    static void* operator new(unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
    static void operator delete(void* pointer)
    {
        g_memoryManager.Deallocate(pointer);
    }
};

#endif
