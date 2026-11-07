
// src/havok/physics/utilities/serialize/display/hkpserializeddisplaymarkerlistclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/serialize/display/hkpserializeddisplaymarkerlistclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/BSAudio.h"
#include "../../../../../../include/hkMemoryAllocator.h"

inline hkMemoryAllocator& BSAudio::heap()
{
    return *reinterpret_cast<hkMemoryAllocator*>(pListener);
}

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct RefElem_t
{
    void FUN_00c905b0();
};

struct RefBase_cls
{
    virtual void a00();
    virtual ~RefBase_cls() throw()
    {}
};

class FUN_00dff010_cls : public RefBase_cls
{
  public:
    int m_i04;
    RefElem_t** m_ppData;
    int m_iArrayLength;
    unsigned int m_uCapacity;

    ~FUN_00dff010_cls() throw();
};

// Releases each element in m_ppData, frees the backing array through the allocator, and resets the count, pointer and capacity before destroying the base.
// @fnv 0x00dff010
FUN_00dff010_cls::~FUN_00dff010_cls() throw()
{
    for (int i = 0; i < m_iArrayLength; i++)
    {
        m_ppData[i]->FUN_00c905b0();
    }

    hkMemoryRouter* pAudioHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAudioAllocator = reinterpret_cast<hkMemoryAllocator*>(pAudioHolder->m_heap);
    unsigned int uiCapacity = m_uCapacity;
    *(volatile int*)&m_iArrayLength = 0;
    if ((uiCapacity & 0x80000000) == 0)
    {
        pAudioAllocator->bufFree(m_ppData, (uiCapacity & 0x3fffffff) * 4);
    }
    *(volatile RefElem_t***)&m_ppData = 0;
    unsigned int* puiCapacity = &m_uCapacity;
    *puiCapacity = 0x80000000;
    this->RefBase_cls::~RefBase_cls();
}

namespace fnv_00dff080 {
BSAudio* hkMemoryRouter_getInstance();

struct FUN_00e05d10_Base
{
    virtual ~FUN_00e05d10_Base();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;

    void operator delete(void* p, unsigned int)
    {
        FUN_00e05d10_Base* b = static_cast<FUN_00e05d10_Base*>(p);
        hkMemoryRouter_getInstance()->heap().blockFree(p, b->m_usMemSizeAndFlags);
    }
};

struct FUN_00dff080 : FUN_00e05d10_Base
{
    FUN_00dff080(int);
    virtual ~FUN_00dff080();
};

// Constructor taking an unused int; the body is empty.
// @fnv 0x00dff080
FUN_00dff080::FUN_00dff080(int)
{}
}  // namespace fnv_00dff080
