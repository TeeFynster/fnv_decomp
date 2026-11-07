
// src/unmapped/bhkboxshape_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/unmapped/bhkboxshape.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkVector4.h"
extern __declspec(thread) int g_iThreadState2B4;
struct ThreadStateGuard
{
    int m_iSaved;
    ThreadStateGuard()
    {
        m_iSaved = g_iThreadState2B4;
        g_iThreadState2B4 = 0x10;
    }
    ~ThreadStateGuard()
    {
        g_iThreadState2B4 = m_iSaved;
    }
};
// The router returned at 0x00c85750 is shared as hkMemoryRouter; its heap is at +0x10.
struct SpawnSource
{
    int unk00, unk04, unk08, unk0C;
    float m_fVectorY, m_fVectorZ, m_fScalarPart, m_fVectorX;
};
extern float DAT_010c72bc;
struct SpawnedRefObject
{
    void* m_pVtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    static void* operator new(unsigned int n)
    {
        SpawnedRefObject* b = (SpawnedRefObject*)hkMemoryRouter::getInstance().heap().blockAlloc(n);
        b->m_usMemSizeAndFlags = (unsigned short)n;
        return b;
    }
    static void operator delete(void* p, unsigned int n)
    {
        hkMemoryRouter::getInstance().m_heap->blockFree(p, n);
    }
    SpawnedRefObject(const hkVector4&, float);
    void FUN_00c905b0();
};
struct SpawnOwner
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35(SpawnedRefObject*);
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47(SpawnSource*);
    void bhkBoxShape_Init_00ca0190(SpawnSource*);
};
// @fnv 0x00ca0190
// src: XBOX_PDB 0x00ca0190
void SpawnOwner::bhkBoxShape_Init_00ca0190(SpawnSource* pSource)
{
    ThreadStateGuard kGuard;
    // Keep the SIMD temporary: VC9 /GS omits the original cookie for a shared hkVector4 temporary.
    SpawnedRefObject* pObject = new SpawnedRefObject(
        reinterpret_cast<const hkVector4&>(static_cast<const __m128&>(
            _mm_setr_ps(pSource->m_fVectorY, pSource->m_fVectorZ, pSource->m_fScalarPart, pSource->m_fVectorX))),
        DAT_010c72bc);
    v35(pObject);
    pObject->FUN_00c905b0();
    v47(pSource);
}
