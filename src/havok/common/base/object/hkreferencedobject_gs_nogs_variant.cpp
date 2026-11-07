
// src/havok/common/base/object/hkreferencedobject_gs_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/common/base/object/hkreferencedobject.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/base/object/hkreferencedobject.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/object/hkreferencedobject.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../include/NiBinaryStream.h"
#include "../../../../../include/bhkWorldObject.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkReferencedObjectLock.h"
#include "../../../../../include/hkpWorldObject.h"

// The router returned by 0x00c85750 has its heap allocator at +0x10; no shared router header exists yet.
#include "../../../../../include/hkMemoryRouter.h"
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();

inline void* hkReferencedObject::operator new(std::size_t nbytes)
{
    hkReferencedObject* b = static_cast<hkReferencedObject*>(hkMemoryRouter_getInstance().heap().blockAlloc(nbytes));
    b->m_usMemSizeAndFlags = (unsigned short)nbytes;
    return b;
}

static inline void replaceInstance(hkReferencedObjectLock* p)
{
    if (hkReferencedObjectLock::s_instance)
        hkReferencedObjectLock::s_instance->ReleaseReference();
    hkReferencedObjectLock::s_instance = p;
}

// @fnv 0x00c90420
// src: HAVOK_LIB 0x00c90420
void __cdecl hkReferencedObject_lockInit(int value)
{
    if (!hkReferencedObjectLock::s_instance)
    {
        hkReferencedObjectLock* p = new hkReferencedObjectLock();
        p->m_multiThreaded = value;
        replaceInstance(p);
    }
    else
    {
        hkReferencedObjectLock::s_instance->m_multiThreaded = value;
    }
}
#include <xmmintrin.h>
struct FUN_00c90e60_cls
{
    int unk00;
    float m_fBoundRadius;
    float m_fOriginZ;
    float m_fHalfRadius;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    __m128 m_kRadiusOverHeight;
    __m128 m_kHeightOverRadius;
    float m_fHeightOverRadius;
    float m_fRadiusOverHeight;
    float m_fHeightOverHalfRadius;
    float m_fHalfRadiusOverHeight;
    void UpdateFields_00c90e60(float fRadius, float m_fGlyphExtent);
};
// @fnv 0x00c90e60
// src: GUESS 0x00c90e60 (confidence: low)
void FUN_00c90e60_cls::UpdateFields_00c90e60(float fRadius, float m_fGlyphExtent)
{
    m_fBoundRadius = fRadius;
    float fHalfRadius = fRadius * 0.5;
    m_fHalfRadius = fHalfRadius;
    m_fOriginZ = m_fGlyphExtent;
    m_fHeightOverRadius = m_fGlyphExtent / fRadius;
    m_fHeightOverHalfRadius = m_fGlyphExtent / fHalfRadius;
    m_fRadiusOverHeight = fRadius / m_fGlyphExtent;
    m_fHalfRadiusOverHeight = fHalfRadius / m_fGlyphExtent;
    m_kRadiusOverHeight = _mm_set1_ps(m_fRadiusOverHeight);
    m_kHeightOverRadius = _mm_set1_ps(m_fHeightOverRadius);
}
