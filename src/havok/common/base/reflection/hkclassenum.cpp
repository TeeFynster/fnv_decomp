
// src/havok/common/base/reflection/hkclassenum.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/reflection/hkclassenum.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkCustomAttributes.h"

extern "C" int __cdecl FUN_00d86980();

// Reads a signed char, short or int from p depending on the size returned by FUN_00d86980, defaulting to 0.
// @fnv 0x00d86b80
int __stdcall ReadSignedValueBySize(const void* apData)
{
    int r = 0;
    switch (FUN_00d86980())
    {
    case 1:
        r = *(const signed char*)apData;
        break;
    case 2:
        r = *(const signed short*)apData;
        break;
    case 4:
        r = *(const int*)apData;
        break;
    }
    return r;
}

struct FUN_00db76a0_Class
{
    void* __thiscall GetAttribute(void* arg);
};

// @fnv 0x00db76a0
void* FUN_00db76a0_Class::GetAttribute(void* arg)
{
    hkCustomAttributes* a = *(hkCustomAttributes**)((char*)this + 0xc);
    if (a)
        return a->getAttribute(arg);
    return 0;
}

struct FUN_00db7860
{
    int m_00;
    int m_04;
    int m_08;
    ~FUN_00db7860() throw();
};

struct FUN_00db7870 : public FUN_00db7860
{
    FUN_00db7870(int n) throw();
};

struct hkObjDB76
{
    void writeSignature(FUN_00db7860* p) throw();
    void hkClassEnum_getSignature();
};

// Constructs a temporary FUN_00db7870 with 0 and passes it to FUN_00db7600.
// @fnv 0x00db76c0
// src: HAVOK_LIB 0x00db76c0
void hkObjDB76::hkClassEnum_getSignature()
{
    FUN_00db7870 tmp(0);
    writeSignature(&tmp);
}

template <int SIZE> __forceinline void memCpyOneAlignedXdb76f0(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}

struct hkMemoryRouterXdb76f0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pStreamAllocator;
};

namespace hkRouterXdb76f0 {
extern "C" hkMemoryRouterXdb76f0& __cdecl hkMemoryRouter_getInstance() throw();
}
void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);

template <class T> class hkArrayXdb76f0LocalForm
{ // local form of hkArray: 0x00db76f0 needs the original inline/out-of-line helper split; shared replacement changes bytes.
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void AddBack(const T& e)
    {
        hkMemoryRouterXdb76f0& router = hkRouterXdb76f0::hkMemoryRouter_getInstance();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        memCpyOneAlignedXdb76f0<sizeof(T)>(m_data + m_iElementCount, &e);
        m_iElementCount++;
    }
};

struct hkEntryXdb76f0
{
    unsigned int m_flags;
    void* m_uiFilterValue;
};

class hkOwnerXdb76f0
{
  public:
    int unk00;
    hkArrayXdb76f0LocalForm<hkEntryXdb76f0> m_entries;

    bool CollectMatchingEntries(unsigned int flags, hkArrayXdb76f0LocalForm<void*>& out, unsigned int* remaining);
};

// Iterates m_entries in reverse, adds entries whose m_flags are a subset of flags to out, and stores the unmatched bits in remaining.
// @fnv 0x00db76f0
bool hkOwnerXdb76f0::CollectMatchingEntries(unsigned int flags, hkArrayXdb76f0LocalForm<void*>& out, unsigned int* remaining)
{
    out.m_iElementCount = 0;
    for (int i = m_entries.m_iElementCount - 1; i >= 0 && flags; i--)
    {
        hkEntryXdb76f0& e = m_entries.m_data[i];
        unsigned int f = e.m_flags;
        if ((f & flags) == f)
        {
            void* value = e.m_uiFilterValue;
            out.AddBack(value);
            flags &= ~f;
        }
    }
    *remaining = flags;
    return flags != 0;
}
