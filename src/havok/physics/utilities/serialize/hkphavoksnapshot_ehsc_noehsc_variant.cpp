#include "../../../../../include/hkResult.h"
#include "../../../../../include/hkBool.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkStringPtr.h"
#include "../../../../../include/hkClass.h"
#include "../../../../../include/hkRefVariant.h"
#include "../../../../../include/hkRootLevelContainer.h"


// src/havok/physics/utilities/serialize/hkphavoksnapshot_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/utilities/serialize/hkphavoksnapshot.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/serialize/hkphavoksnapshot.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/serialize/hkphavoksnapshot.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// The TLS getter is 0x00c85750 and the heap is at +0x10; hkMemoryRouter.h is not available yet.
#include "../../../../../include/hkMemoryRouter.h"
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
inline hkMemoryRouter* getRouter()
{
    return hkMemoryRouter_getInstance();
}

void __cdecl ResizeAudioStream(void* alloc, void* arr, int elemSize);

__forceinline hkRefVariant::~hkRefVariant() throw()
{
    if (m_pRetainedObject)
        m_pRetainedObject->removeReference();
    m_pRetainedObject = 0;
}
class hkRootLevelContainerNamedVariant
{
public:
    hkStringPtr m_name;
    hkStringPtr m_pClassName;
    hkRefVariant m_pReferencedResource;

    __forceinline hkRootLevelContainerNamedVariant()
    {}
    __forceinline ~hkRootLevelContainerNamedVariant()
    {}

    __forceinline void set(const char* name, const void* object, const hkClass* pClassInfo)
    {
        m_name = name;
        m_pReferencedResource.FUN_00d47770(object, pClassInfo);
        m_pClassName = m_pReferencedResource.hkRefVariant_getClass() ? m_pReferencedResource.hkRefVariant_getClass()->getName() : 0;
    }
};
inline void* operator new(unsigned int, void* p)
{
    return p;
}

template <typename T> __forceinline void destruct(T* t, int n)
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}

__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return getRouter()->heap();
}

template <typename T, typename Allocator>
__forceinline hkArray<T, Allocator>::~hkArray()
{
    hkMemoryAllocator& a = Allocator().get(this);
    destruct(this->m_data, this->m_iElementCount);
    this->m_iElementCount = 0;
    if ((this->m_iCapacityState & 0x80000000) == 0)
        a.bufFree(this->m_data, (this->m_iCapacityState & 0x3fffffff) * sizeof(T));
}

template <typename T>
__forceinline T& hkArrayBase<T>::_expandOne(hkMemoryAllocator& a)
{
    if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(&a, this, sizeof(T));
    new (m_data + m_iElementCount) T();
    return m_data[m_iElementCount++];
}
extern int DAT_01268b54;
// The game ABI passes aggregate result storage as the first stack argument.
void __cdecl hkpHavokSnapshot_save(hkResult* result, const void* object, const void* pClassInfo, int a3, int a4, int a5, int a6);

// @fnv 0x00cc0bc0
// src: HAVOK_LIB 0x00cc0bc0
hkResult* __cdecl hkpHavokSnapshot_saveUnderRootLevel(hkResult* result, const void* object, const hkClass& pClassInfo, int a3, int a4, int a5)
{
    hkRootLevelContainer container;
    container.m_kNamedVariants.expandOne().set(pClassInfo.getName(), object, &pClassInfo);
    hkpHavokSnapshot_save(result, &container, &DAT_01268b54, a3, a4, a5, 0);
    return result;
}
