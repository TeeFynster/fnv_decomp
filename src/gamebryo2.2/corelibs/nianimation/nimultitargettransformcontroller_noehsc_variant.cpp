#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiMultiTargetTransformController.h"
#include "../../../../include/NiBlendTransformInterpolator.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiQuatTransform.h"
#include "../../../../include/NiQuaternion.h"
#include "../../../../include/NiTransformInterpolator.h"
#include "../../../../include/NiMatrix3.h"

// src/gamebryo2.2/corelibs/nianimation/nimultitargettransformcontroller_noehsc_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /Gy (unit src/gamebryo2.2/corelibs/nianimation/nimultitargettransformcontroller.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

extern MemoryManager _g_memoryManager;

void* NiMalloc(unsigned int);

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);

inline void* operator new(unsigned int n)
{
    return _g_memoryManager.Allocate(n);
}

// NiBlendTransformInterpolator's shared header lacks the default constructor
// and array allocation/deallocation declarations used by these two functions.
// Retain their local construction views until that interface is available.
class BlendInterp
{
  public:
    BlendInterp() throw();
    virtual ~BlendInterp();
    static void* operator new[](unsigned int);
    static void operator delete[](void*);
    unsigned int m_uiRefCount;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
};

// @fnv 0x00a2feb0
// src: XBOX_PDB 0x00a2feb0
void NiMultiTargetTransformController::AllocateStorage(unsigned short n)
{
    m_usNumInterps = n;
    if (n == 0)
        return;

    m_pkBlendInterpolators = (NiBlendTransformInterpolator*)new BlendInterp[n];
    for (unsigned short i = 0; i < n; i++)
        ((BlendInterp*)m_pkBlendInterpolators)[i].IncRefCount();

    m_ppTargetObjects = (NiAVObject**)NiMalloc((unsigned int)n * 4);
    fnv_zlib_memset(m_ppTargetObjects, 0, (unsigned int)n * 4);
}

inline void operator delete(void* p) throw()
{
    _g_memoryManager.Deallocate(p);
}

struct SNAEntry
{
    static void* operator new[](unsigned int size) throw();
};

struct FUN_00a409b0_class : public SNAEntry
{
    virtual ~FUN_00a409b0_class() throw();
    void* m_pkUnk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    FUN_00a409b0_class() throw();
};

extern void(__stdcall* DAT_00fdf1c0)(void*);

// @fnv 0x00a30160
// src: XBOX_PDB 0x00a30160
void NiMultiTargetTransformController::ClearInterpolators()
{
    if (m_usNumInterps == 0)
        return;
    if (m_pkBlendInterpolators == 0)
        return;

    delete[] (FUN_00a409b0_class*)m_pkBlendInterpolators;

    m_pkBlendInterpolators = (NiBlendTransformInterpolator*)new FUN_00a409b0_class[m_usNumInterps];

    unsigned short i = 0;
    if (i < m_usNumInterps)
    {
        void(__stdcall * fn)(void*) = DAT_00fdf1c0;
        do
        {
            fn((char*)m_pkBlendInterpolators + 4 + i * 0x30);
            ++i;
        } while (i < m_usNumInterps);
    }

    fnv_zlib_memset(m_ppTargetObjects, 0, m_usNumInterps * 4);
}
