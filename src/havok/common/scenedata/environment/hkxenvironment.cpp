
// src/havok/common/scenedata/environment/hkxenvironment.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/environment/hkxenvironment.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkBaseObject.h"
#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkStringPtr.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryAllocator.h"

struct HKXMemoryManager
{
    virtual void Unused1()
    {}
    virtual void Unused2()
    {}
    virtual void Free(void* p, unsigned short size) = 0;
};

struct HKXMemoryRouter
{
    char padding[0x10];
    HKXMemoryManager* manager;
};

struct HKXEnvironmentStandIn
{
    char padding[4];
    unsigned short size;
    void DestroyEnvironment();
    HKXEnvironmentStandIn* FUN_00e3f8a0(unsigned char flags);
};

HKXMemoryRouter* _D1A0E0GetMemoryRouter();

// Calls DestroyEnvironment, then if bit 0 of flags is set frees this through the memory router's manager, and returns this.
// @fnv 0x00e3f8a0
HKXEnvironmentStandIn* HKXEnvironmentStandIn::FUN_00e3f8a0(unsigned char flags)
{
    DestroyEnvironment();

    if (flags & 1)
    {
        HKXMemoryRouter* router = _D1A0E0GetMemoryRouter();
        router->manager->Free(this, size);
    }

    return this;
}

extern int DAT_010ebab8;

struct FnvVtObj
{
    int m_vptr;

    FnvVtObj* SetVptr_00e3f510(unsigned int unusedArg);
};

// @fnv 0x00e3f510
// src: GUESS 0x00e3f510 (confidence: low)
FnvVtObj* FnvVtObj::SetVptr_00e3f510(unsigned int unusedArg)
{
    m_vptr = (int)&DAT_010ebab8;
    return this;
}

struct EnvironmentVariable
{
    hkStringPtr m_name;
    hkStringPtr m_value;
};
HKXMemoryRouter* __cdecl hkMemoryRouter_getInstance();

__forceinline void ReleaseEnvironmentVariables(hkArray<EnvironmentVariable>& variables)
{
    hkMemoryAllocator* allocator = reinterpret_cast<hkMemoryAllocator*>(hkMemoryRouter_getInstance()->manager);
    EnvironmentVariable* entry = variables.m_data;
    if (variables.m_iElementCount > 0)
    {
        int remaining = variables.m_iElementCount;
        do
        {
            entry->m_value.~hkStringPtr();
            entry->m_name.~hkStringPtr();
            ++entry;
        } while (--remaining != 0);
    }
    variables.m_iElementCount = 0;
    if ((static_cast<unsigned int>(variables.m_iCapacityState) & 0x80000000u) == 0)
        allocator->bufFree(variables.m_data, (variables.m_iCapacityState & 0x3fffffff) * sizeof(EnvironmentVariable));
    variables.m_data = 0;
    variables.m_iCapacityState = 0x80000000;
}
struct EnvironmentLayout
{
    void** vtable;
    unsigned short memoryFlags;
    short referenceCount;
    hkArray<EnvironmentVariable> variables;
};
// Releases the environment's variable array, then calls the hkBaseObject destructor.
// @fnv 0x00e3f820
void HKXEnvironmentStandIn::DestroyEnvironment()
{
    EnvironmentLayout* environment = reinterpret_cast<EnvironmentLayout*>(this);
    ReleaseEnvironmentVariables(environment->variables);
    reinterpret_cast<hkBaseObject*>(environment)->hkBaseObject::~hkBaseObject();
}

void ResizeAudioStream(void* pvAlloc, void* apvArray, int iSizeElem);

// The shared header omits the copy constructor at 0x00cb0bd0. This
// one-pointer aggregate is passed on the stack; fastcall supplies this in ECX.
struct EnvironmentStringCopyArgument
{
    const hkStringPtr* source;
};
void __fastcall CopyConstructEnvironmentString(hkStringPtr* destination, EnvironmentStringCopyArgument source) throw();

template <int ELEMENTSIZE> __forceinline void CopyAlignedWords(void* pvDst, const void* pvSrc)
{
    for (int i = 0; i < ELEMENTSIZE / 4; ++i)
        static_cast<unsigned int*>(pvDst)[i] = static_cast<const unsigned int*>(pvSrc)[i];
}

template <typename T> __forceinline void DestroyElements(T* t, int n)
{
    for (int i = 0; i < n; ++i)
        t[i].~T();
}

template <typename T> __forceinline void hkArrayBase<T>::removeAt(int iIndex)
{
    DestroyElements<T>(&m_data[iIndex], 1);
    m_iElementCount--;
    if (m_iElementCount != iIndex)
        CopyAlignedWords<sizeof(T)>(m_data + iIndex, m_data + m_iElementCount);
}

template <> __forceinline void hkArray<EnvironmentVariable>::pushBack(const EnvironmentVariable& kElem)
{
    HKXMemoryRouter* pRouter = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAlloc = reinterpret_cast<hkMemoryAllocator*>(pRouter->manager);
    if (m_iElementCount == getCapacity())
        ResizeAudioStream(pAlloc, this, sizeof(EnvironmentVariable));
    EnvironmentVariable* destination = &m_data[m_iElementCount];
    if (destination)
    {
        EnvironmentStringCopyArgument name = { &kElem.m_name };
        CopyConstructEnvironmentString(&destination->m_name, name);
        EnvironmentStringCopyArgument value = { &kElem.m_value };
        CopyConstructEnvironmentString(&destination->m_value, value);
    }
    m_iElementCount++;
}

class hkxAttributeMapE3F3
{
  public:
    virtual void V0() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkArray<EnvironmentVariable> m_pCustomAttributes;

    int FindEntryByKey(const char* pcName) throw();
    int SetOrRemoveCustomAttribute(const char* pcName, const char* pcValue) throw();
};

// Sets or removes a custom attribute by name, returning 1 if a missing attribute was requested for removal, otherwise 0.
// @fnv 0x00e3f3b0
// src: GUESS 0x00e3f3b0 (confidence: high)
int hkxAttributeMapE3F3::SetOrRemoveCustomAttribute(const char* pcName, const char* pcValue) throw()
{
    int iIndex = FindEntryByKey(pcName);
    if (pcValue == 0)
    {
        if (iIndex == -1)
            return 1;
        m_pCustomAttributes.removeAt(iIndex);
        return 0;
    }
    if (iIndex != -1)
    {
        m_pCustomAttributes[iIndex].m_value = pcValue;
        return 0;
    }
    EnvironmentVariable kPair;
    kPair.m_name = pcName;
    kPair.m_value = pcValue;
    m_pCustomAttributes.pushBack(kPair);
    return 0;
}

