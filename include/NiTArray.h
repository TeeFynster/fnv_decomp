#pragma once

// Checked constructor exception specification: NiDynamicGeometryGroup 0x00e957b0.
#ifndef FNV64_NITARRAY_CTOR_SPEC
#define FNV64_NITARRAY_CTOR_SPEC
#endif

#include <stddef.h>

// the allocator policies are only template arguments here (several shared headers still define their own
// NiTMallocInterface / NiTNewInterface); include/NiTMallocInterface.h and NiTNewInterface.h hold the definitions
template <class T> class NiTMallocInterface;
template <class T> class NiTNewInterface;

// Gamebryo 2.2 NiTArray.h. RTTI: NiTArray<T, TAlloc> (no bases) has one vftable slot, the destructor
// (e.g. NiTArray<Actor *,NiTMallocInterface<Actor *> > vftable 0x01092930 -> 0x009e9c60, which frees m_pBase at +4);
// object_sizes.csv: the exe's ctors fill 0x10 bytes: vtable, T* m_pBase at 4, the four unsigned shorts at 8..0xe.
//
// Bodies: VC9 inlining of SetAt/Add/... differs per unit (some originals call them out of line, /O2 units inline
// them), so units define the bodies they need out of class, e.g.
//     template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::GetSize() const { return this->m_usSize; }
// Define FNV64_NITARRAY_INLINE_BODIES before the first include to get the Gamebryo bodies from this header.
template <class T, class TAlloc> class NiTArray
{
  public:
    NiTArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1) FNV64_NITARRAY_CTOR_SPEC;
    virtual ~NiTArray();

    // Gamebryo: NiTArray : NiMemObject. The FNV units inline its operator new (MemoryManager::Allocate) into new-expressions
    // of these arrays (NiTexturingProperty::LoadBinary 0x00a6ad60 allocates m_pShaderMaps that way); a unit defines the body.
    // No class operator delete is declared: no unit deletes one through it yet, and declaring it adds the ctor-throw cleanup.
    static void* operator new(size_t uiSize);

    unsigned int GetSize() const;
    unsigned int GetEffectiveSize() const;
    unsigned int GetAllocatedSize() const;
    unsigned int GetGrowBy() const;
    void SetGrowBy(unsigned int uiGrowBy);
    void FUN_00a90180(int); // exe: 0x00a90180
    T* GetBase();
    T& GetAt(unsigned int uiIndex);
    const T& GetAt(unsigned int uiIndex) const;

    void SetAt(unsigned int uiIndex, const T& element);
    unsigned int SetAtGrow(unsigned int uiIndex, const T& element);
    unsigned int Add(const T& element);
    unsigned int AddFirstEmpty(const T& element);
    T RemoveAt(unsigned int uiIndex);
    T RemoveAtAndFill(unsigned int uiIndex);
    T RemoveEnd();
    void RemoveAll();
    unsigned int Remove(const T& element);
    void Compact();
    void UpdateSize();
    void SetSize(unsigned int uiMaxSize);
    unsigned int Find(const T& element) const;

    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

#ifdef FNV64_NITARRAY_INLINE_BODIES
// Bodies as the exe's inlined copies show them (0x009e9c60 for the destructor). The constructor's store order
// (capacity, step, both counts, then the buffer) is what the /O2 copies keep.
template <class T, class TAlloc> inline NiTArray<T, TAlloc>::NiTArray(unsigned int uiCapacity, unsigned int uiStep) FNV64_NITARRAY_CTOR_SPEC
{
    m_usMaxSize = (unsigned short)uiCapacity;
    m_usGrowBy = (unsigned short)uiStep;
    m_usSize = 0;
    m_usESize = 0;
    if (this->m_usMaxSize > 0)
        this->m_pBase = TAlloc::Allocate(this->m_usMaxSize);
    else
        this->m_pBase = 0;
}

template <class T, class TAlloc> inline NiTArray<T, TAlloc>::~NiTArray() { TAlloc::Deallocate(this->m_pBase); }

// plain accessors
template <class T, class TAlloc> inline T* NiTArray<T, TAlloc>::GetBase() { return this->m_pBase; }
template <class T, class TAlloc> inline T& NiTArray<T, TAlloc>::GetAt(unsigned int uiSlot) { return this->m_pBase[uiSlot]; }
template <class T, class TAlloc> inline const T& NiTArray<T, TAlloc>::GetAt(unsigned int uiSlot) const { return this->m_pBase[uiSlot]; }
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::GetAllocatedSize() const { return this->m_usMaxSize; }
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::GetSize() const { return this->m_usSize; }
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::GetEffectiveSize() const { return this->m_usESize; }
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::GetGrowBy() const { return this->m_usGrowBy; }
template <class T, class TAlloc> inline void NiTArray<T, TAlloc>::SetGrowBy(unsigned int uiStep) { m_usGrowBy = (unsigned short)uiStep; }

// store one slot: the used-slot count m_usESize follows null/non-null transitions, m_usSize grows past the end
template <class T, class TAlloc> inline void NiTArray<T, TAlloc>::SetAt(unsigned int uiSlot, const T& kItem)
{
    if (uiSlot >= m_usSize)
    {
        m_usSize = (unsigned short)(uiSlot + 1);
        if (kItem != T(0))
            m_usESize++;
    }
    else if (kItem != T(0))
    {
        if (m_pBase[uiSlot] == T(0))
            m_usESize++;
    }
    else if (m_pBase[uiSlot] != T(0))
    {
        m_usESize--;
    }
    m_pBase[uiSlot] = kItem;
}

template <class T, class TAlloc>
inline unsigned int NiTArray<T, TAlloc>::SetAtGrow(unsigned int uiSlot, const T& kItem)
{
    if (uiSlot >= m_usMaxSize)
        SetSize(uiSlot + m_usGrowBy);
    SetAt(uiSlot, kItem);
    return uiSlot;
}

template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::Add(const T& kItem) { return SetAtGrow(m_usSize, kItem); }
#endif