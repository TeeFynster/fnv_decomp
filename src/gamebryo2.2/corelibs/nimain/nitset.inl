#include "../../../../include/NiPointer.h"
#include "../../../../include/NiTSet.h"


class NiMaterialResource
{
public:
    long m_uiRefCount;
    virtual ~NiMaterialResource();
    virtual void DeleteThis();
};

extern "C" __declspec(dllimport) long __stdcall
InterlockedDecrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall
InterlockedIncrement(volatile long* value);

template <class T>
inline NiPointer<T>& NiPointer<T>::operator=(const NiPointer& other)
{
    T* pOld = m_pObject;
    if (pOld != other.m_pObject)
    {
        if (pOld && InterlockedDecrement(&pOld->m_uiRefCount) == 0)
            pOld->DeleteThis();
        m_pObject = other.m_pObject;
        if (m_pObject)
            InterlockedIncrement(&m_pObject->m_uiRefCount);
    }
    return *this;
}

void* __cdecl NiTObjectArray_NiPointer_NiScreenTexture_NiTObjectArray_NiPointer_NiScreenTexture(unsigned int count);
void __cdecl ReleaseObjectArray(void* memory);

typedef NiTSet<NiPointer<NiMaterialResource>,
               NiTNewInterface<NiPointer<NiMaterialResource> > >
    NiMaterialResourceSet;

template <>
// @fnv 0x00e8ea60
void NiMaterialResourceSet::Add(
    const NiPointer<NiMaterialResource>& value)
{
    if (m_uiUsed == m_uiAlloced)
    {
        unsigned int uiNewAlloced;
        if (m_uiAlloced > 0)
            uiNewAlloced = m_uiAlloced + m_uiAlloced;
        else
            uiNewAlloced = 1;
        Realloc(uiNewAlloced);
    }
    m_pBase[m_uiUsed++] = value;
}

template <>
// @fnv 0x00e8e3a0
void NiMaterialResourceSet::Realloc(unsigned int uiAlloced)
{
    if (uiAlloced != m_uiAlloced)
    {
        NiPointer<NiMaterialResource>* pNew;
        if (uiAlloced > 0)
        {
            pNew = static_cast<NiPointer<NiMaterialResource>*>(
                NiTObjectArray_NiPointer_NiScreenTexture_NiTObjectArray_NiPointer_NiScreenTexture(uiAlloced));
            for (unsigned int i = 0; i < m_uiUsed; ++i)
                pNew[i] = m_pBase[i];
        }
        else
        {
            pNew = 0;
        }

        ReleaseObjectArray(m_pBase);
        m_pBase = pNew;
        m_uiAlloced = uiAlloced;
    }
}

extern unsigned char DAT_01096968;

void* __cdecl _NiMalloc(unsigned int size);
void __cdecl NiFree(void* memory);


