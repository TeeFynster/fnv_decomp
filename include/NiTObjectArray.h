#ifndef FNV64_NITOBJECTARRAY_H
#define FNV64_NITOBJECTARRAY_H

#include "NiTArray.h"

// Gamebryo 2.2 NiTArray.h. RTTI: NiTObjectArray<T> : NiTArray<T, NiTNewInterface<T> >, one vftable slot (its own destructor,
// e.g. NiTObjectArray<Animation *> vftable 0x01082808 -> 0x00869c90), no data members of its own.
template <class T> class NiTObjectArray : public NiTArray<T, NiTNewInterface<T> >
{
  public:
    NiTObjectArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1);
    // no user-declared destructor (Gamebryo declares none): the implicit virtual one, e.g. 0x00869c90 -> 0x00869cc0, calls
    // ~NiTArray without storing a vftable, which a user-declared one would
};

#ifdef FNV64_NITARRAY_INLINE_BODIES
template <class T>
inline NiTObjectArray<T>::NiTObjectArray(unsigned int uiMaxSize, unsigned int uiGrowBy)
    : NiTArray<T, NiTNewInterface<T> >(uiMaxSize, uiGrowBy)
{
}
#endif
#endif

#if defined(FNV64_NITOBJECTARRAY_SHADER_ENTRIES) && !defined(FNV64_NITOBJECTARRAY_SHADER_ENTRIES_DEFINED)
#define FNV64_NITOBJECTARRAY_SHADER_ENTRIES_DEFINED
#include "NiPointer.h"
class NiShaderConstantMapEntry;

template <> class NiTObjectArray<NiPointer<NiShaderConstantMapEntry> >
{
public:
    __forceinline NiTObjectArray()
        : m_pBase(0), m_usMaxSize(0), m_usSize(0), m_usESize(0), m_usGrowBy(1)
    {}
    virtual ~NiTObjectArray();

    void NiTObjectArray_NiPointer_NiShaderConstantMapEntry_RemoveAll();

    union
    {
        NiPointer<NiShaderConstantMapEntry>* m_pBase;
        NiPointer<NiShaderConstantMapEntry>* data;
    };
    union { unsigned short m_usMaxSize; unsigned short capacity; };
    union { unsigned short m_usSize; unsigned short size; };
    union { unsigned short m_usESize; unsigned short count; };
    union { unsigned short m_usGrowBy; unsigned short grow; };

    __forceinline NiPointer<NiShaderConstantMapEntry>& GetAt(unsigned int index)
    {
        return m_pBase[index];
    }
    NiPointer<NiShaderConstantMapEntry>& GetAt(unsigned int index) const;
    void RemoveAll();
    __declspec(noalias) __declspec(nothrow) void SetAt(
        unsigned int, const NiPointer<NiShaderConstantMapEntry>& __restrict) throw();
};
#endif
