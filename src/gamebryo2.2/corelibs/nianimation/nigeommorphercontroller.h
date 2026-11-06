// gamebryo2.2/corelibs/nianimation/nigeommorphercontroller.h: the NiGeomMorpherController variant units' view of
// the shared Gamebryo classes (include/), with the inline bodies Gamebryo has for NiPointer and the
// reference counts (as nigeommorphercontroller.cpp defines them).
#ifndef FNV_NIGEOMMORPHERCONTROLLER_UNIT_H
#define FNV_NIGEOMMORPHERCONTROLLER_UNIT_H

#include "../../../../include/NiGeomMorpherController.h"
#include "../../../../include/NiColorInterpolator.h"
#include "../../../../include/NiColorData.h"
#include "../../../../include/NiObjectNET.h"
#include "../../../../include/NiColorA.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

int NiStricmp(const char* a, const char* b);
extern const NiColorA DAT_011a9430;
extern bool DAT_011f3724;

inline void NiInterpolator::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}
inline void NiInterpolator::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}
template <class T> inline NiPointer<T>::NiPointer() : m_pObject(0)
{
}
template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pkNew)
{
    if (m_pObject != pkNew)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = pkNew;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}
template <class T> inline NiPointer<T>::operator T*() const
{
    return m_pObject;
}
template <class T> inline T* NiPointer<T>::operator->() const
{
    return m_pObject;
}

#endif
