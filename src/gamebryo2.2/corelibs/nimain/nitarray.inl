#define FNV64_NIPOINTER_COMPARE_DECLS
#include "../../../../include/NiPointer.h"
// Reconstructed source for gamebryo2.2/corelibs/nimain/nitarray.inl.
//
// Self-contained header: the task's bundled headers only forward-declare
// the NiTArray template (see include/layout_support.h), so this unit
// provides the full template definition. Class, member and allocator
#ifndef FNV_NITARRAY_INL
#define FNV_NITARRAY_INL


#include <stddef.h>

#include "../../../../include/NiPointer.h"
template <class T> class NiTNewInterface;
class NiAVObject;
class BSTempEffect;
// Element type of the NiTArray instantiation at 0x00a1e680 (identical code folded with other pointer arrays).
class ShaderDeclarationNestedClass;

class ActorCombatGroup;

#include "../../../../include/NiTMallocInterface.h"
#include "../../../../include/NiTArray.h"

typedef NiTArray<NiPointer<NiAVObject>, NiTNewInterface<NiPointer<NiAVObject> > > NiTArray_NiPointer_NiAVObject;
template<> void NiTArray<NiPointer<NiAVObject>, NiTNewInterface<NiPointer<NiAVObject> > >::SetSize(unsigned int uiNewSize);
template<> void NiTArray<NiPointer<NiAVObject>, NiTNewInterface<NiPointer<NiAVObject> > >::SetAt(unsigned int uiIndex, const NiPointer<NiAVObject>& element);

typedef NiTArray<ActorCombatGroup*, NiTMallocInterface<ActorCombatGroup*> > NiTArray_CombatGroup_Malloc;
typedef char NiTArraySizeCheck[(sizeof(NiTArray_CombatGroup_Malloc) == 16) ? 1 : -1];
typedef char NiTArrayBaseCheck[(offsetof(NiTArray_CombatGroup_Malloc, m_pBase) == 4) ? 1 : -1];
typedef char NiTArrayMaxSizeCheck[(offsetof(NiTArray_CombatGroup_Malloc, m_usMaxSize) == 8) ? 1 : -1];
typedef char NiTArraySizeMemberCheck[(offsetof(NiTArray_CombatGroup_Malloc, m_usSize) == 10) ? 1 : -1];
typedef char NiTArrayESizeCheck[(offsetof(NiTArray_CombatGroup_Malloc, m_usESize) == 12) ? 1 : -1];
typedef char NiTArrayGrowByCheck[(offsetof(NiTArray_CombatGroup_Malloc, m_usGrowBy) == 14) ? 1 : -1];

// @fnv 0x004afc50
template<>
unsigned int NiTArray<NiPointer<NiAVObject>, NiTNewInterface<NiPointer<NiAVObject> > >::Add(
    const NiPointer<NiAVObject>& element)
{
    return SetAtGrow(m_usSize, element);
}

// @fnv 0x004b02d0
template<>
unsigned int NiTArray<NiPointer<NiAVObject>, NiTNewInterface<NiPointer<NiAVObject> > >::SetAtGrow(
    unsigned int uiIndex, const NiPointer<NiAVObject>& element)
{
    if (uiIndex >= m_usMaxSize)
        SetSize(uiIndex + m_usGrowBy);
    SetAt(uiIndex, element);
    return uiIndex;
}

// @fnv 0x00a1e680
template<>
void NiTArray<ShaderDeclarationNestedClass*, NiTMallocInterface<ShaderDeclarationNestedClass*> >::SetAt(
    unsigned int uiIndex, ShaderDeclarationNestedClass* const& element)
{
    if (uiIndex >= m_usSize)
    {
        m_usSize = (unsigned short)(uiIndex + 1);
        if (element)
            m_usESize++;
    }
    else if (element)
    {
        if (!m_pBase[uiIndex])
            m_usESize++;
    }
    else if (m_pBase[uiIndex])
        m_usESize--;

    m_pBase[uiIndex] = element;
}

// @fnv 0x004dffa0
template<>
void NiTArray<NiPointer<BSTempEffect>, NiTNewInterface<NiPointer<BSTempEffect> > >::RemoveAll()
{
    unsigned short us;
    for (us = 0; us < m_usSize; us++)
        m_pBase[us] = NiPointer<BSTempEffect>(0);
    m_usSize = 0;
    m_usESize = 0;
}

// @fnv 0x0096ad30
template <class T, class Allocator>
void NiTArray<T, Allocator>::SetSize(unsigned int uiNewSize)
{
    T* pOldBase;
    unsigned short us;

    if (uiNewSize == m_usMaxSize)
        return;

    if (uiNewSize < m_usSize)
    {
        for (us = (unsigned short)uiNewSize; us < m_usSize; us++)
        {
            if (m_pBase[us] != 0)
            {
                m_pBase[us] = 0;
                m_usESize--;
            }
        }
        m_usSize = (unsigned short)uiNewSize;
    }

    pOldBase = m_pBase;
    m_usMaxSize = (unsigned short)uiNewSize;
    if (uiNewSize > 0)
    {
        m_pBase = Allocator::Allocate(m_usMaxSize);
        for (us = 0; us < m_usSize; us++)
            m_pBase[us] = pOldBase[us];
        for (us = m_usSize; us < m_usMaxSize; us++)
            m_pBase[us] = 0;
    }
    else
    {
        m_pBase = 0;
    }

    Allocator::Deallocate(pOldBase);
}

// @fnv 0x0096ae90
template <class T, class Allocator>
void NiTArray<T, Allocator>::SetAt(unsigned int uiIndex, const T& element)
{
    if (uiIndex >= m_usSize)
    {
        m_usSize = (unsigned short)(uiIndex + 1);
        if (element)
            m_usESize++;
    }
    else if (element)
    {
        if (!m_pBase[uiIndex])
            m_usESize++;
    }
    else if (m_pBase[uiIndex])
    {
        m_usESize--;
    }

    m_pBase[uiIndex] = element;
}

// @fnv 0x00470000
template <class T, class Allocator>
unsigned int NiTArray<T, Allocator>::SetAtGrow(unsigned int uiIndex, const T& element)
{
    if (uiIndex >= m_usMaxSize)
        SetSize(uiIndex + m_usGrowBy);
    SetAt(uiIndex, element);
    return uiIndex;
}

template <class T, class Allocator>
unsigned int NiTArray<T, Allocator>::Add(const T& element)
{
    return SetAtGrow(m_usSize, element);
}

#include "nitarray_pc_effect.h"

// @fnv 0x004bc2c0
void NiDynamicEffect::IncRevisionID()
{
    ++revID;
}

// @fnv 0x00869260
template<>
NiPointer<NiAVObject> NiTArray<NiPointer<NiAVObject>, NiTNewInterface<NiPointer<NiAVObject> > >::RemoveAt(unsigned int uiIndex)
{
    if (uiIndex >= m_usSize)
        return NiPointer<NiAVObject>(0);

    NiPointer<NiAVObject> element = m_pBase[uiIndex];
    m_pBase[uiIndex] = NiPointer<NiAVObject>(0);
    if (element != NiPointer<NiAVObject>(0))
        m_usESize--;
    if (uiIndex == (unsigned short)(m_usSize - 1))
        m_usSize--;
    return element;
}

#endif
