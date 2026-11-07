#include <xmmintrin.h>
typedef ::__m128 LocalM128;
// src/staging/blk_00d40000_o2_ehsc_noehsc_variant.cpp - flag-variant unit of src/staging/blk_00d40000_o2.cpp: functions whose
// original has no EH frame (Havok was built without exceptions), built /EHs-c-. Declarations copied from that unit.

// Keep the unit's SIMD intrinsic ABI when loading the shared vector declaration.
typedef ::__m128 LocalM128;

// This unit supplies the original out-of-line vector assignment at 0x00d54e40.
#define FNV64_HKVECTOR4_OWN_ASSIGN
#include "../../include/hkVector4.h"
#include "../../include/layout_support.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/FinishingFlag.h"
#include "../../include/NiStream.h"
#include "../../include/hkStringPtr.h"
#include "../../include/hkBool.h"
#include "../../include/hkArray.h"
#include "../../include/hkReferencedObject.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/AutoMemContext.h"
#include "../../include/hkError.h"
#include "../../include/hkOstream.h"
#include "../../include/hkBaseObject.h"
#include "../../include/NiObject.h"
#include "../../include/NiTPointerMap.h"
#include "../../include/NiTMapItem.h"
#include "../../include/bhkRefObject.h"
#include "../../include/bhkListShape.h"
#include "../../include/bhkWorldObject.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkRotation.h"
#include "../../include/hkpConvexShape.h"
#include "../../include/hkpSingleShapeContainer.h"
#include "../../include/hkpShapeContainer.h"


hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

namespace hkRouterD47F {
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();
}

template <class T> class hkRefPtrD47F
{
  public:
    T* m_pRetainedObject;
    ~hkRefPtrD47F()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
};

struct hkNamedVariantD47F
{
    hkStringPtr m_name;
    hkStringPtr m_pClassName;
    hkRefPtrD47F<hkReferencedObject> m_pReferencedResource;
};

template <typename T> __forceinline void hkArrayUtil::destruct(T* t, int n, hkTypeIsClass)
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}
template <typename T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    hkArrayUtil::destruct(m_data, m_iElementCount, hkTypeIsClass());
    m_iElementCount = 0;
    if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
        alloc.bufFree(m_data, getCapacity() * sizeof(T));
    m_data = 0;
    m_iCapacityState = DONT_DEALLOCATE_FLAG;
}

// The shared array has no scalar-deleting helper declaration. Its original ECX/stack ABI is explicit here.
// @fnv 0x00d47fe0
hkArray<hkNamedVariantD47F>* __fastcall DestroyNamedVariantArray(hkArray<hkNamedVariantD47F>* self, void*, unsigned int uiFlags)
{
    self->_clearAndDeallocate(hkRouterD47F::hkMemoryRouter_getInstance().heap());
    if (uiFlags & 1)
        hkRouterD47F::hkMemoryRouter_getInstance().heap().blockFree(self, sizeof(*self));
    return self;
}

inline void hkReferencedObject::operator delete(void* p)
{
    reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance())
        ->heap().blockFree(p, static_cast<hkReferencedObject*>(p)->m_usMemSizeAndFlags);
}

// The +0x10 field is the convex radius; the child container starts at +0x14.
// Shared hkpTransformShape has its child at +0x10, so this is a convex child owner.
class ConvexChildShapeOwner : public hkpConvexShape
{
  public:
    hkpSingleShapeContainer m_child;
    ConvexChildShapeOwner* FUN_00d5e070(unsigned int uiFlags) throw();
};

inline hkpShapeContainer::~hkpShapeContainer() {}
inline hkpSingleShapeContainer::~hkpSingleShapeContainer()
{
    if (m_pContainedShape)
        const_cast<hkpShape*>(m_pContainedShape)->removeReference();
}

// Destroys the object and, when bit 0 of uiFlags is set, frees its memory via operator delete; returns this.
// @fnv 0x00d5e070
ConvexChildShapeOwner* ConvexChildShapeOwner::FUN_00d5e070(unsigned int uiFlags) throw()
{
    this->ConvexChildShapeOwner::~ConvexChildShapeOwner();
    if (uiFlags & 1)
        ConvexChildShapeOwner::operator delete(this);
    return this;
}
