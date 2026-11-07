// produce (ebp frame in an /O2 unit). Move the functions to their real unit once identified.
#include "../../../../include/BSMultiBound.h"
#include "../../../../include/BSMultiBoundShape.h"
#include "../../../../include/NiStream.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

template <class T> inline NiPointer<T>::operator T*() const
{
    return m_pObject;
}

template <class T> inline T* NiPointer<T>::operator->() const
{
    return m_pObject;
}

template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pObject)
{
    T* pOld = m_pObject;
    m_pObject = pObject;
    for (int i = 0; i < 1; ++i)
    {
        if (pObject)
            InterlockedIncrement((volatile long*)&pObject->m_uiRefCount);
        if (pOld && !InterlockedDecrement((volatile long*)&pOld->m_uiRefCount))
            pOld->DeleteThis();
    }
    return *this;
}

// @fnv 0x00c35fe0
// src: XBOX_PDB 0x00c35fe0
void BSMultiBound::CopyMembers_00c35fe0(BSMultiBound* pkDest, int kCloning)
{
    CopyMembersStream((unsigned int)pkDest, (void*)kCloning);
    BSMultiBoundShape* pNewInstance = (BSMultiBoundShape*)pShape->MakeClone(*(CloningProcess*)kCloning);
    pkDest->pShape = pNewInstance;
}

// @fnv 0x00c360a0
bool BSMultiBound::RegisterStreamables(NiStream& arStream)
{
    if (!NiObject::RegisterStreamables(arStream))
        return false;
    pShape->RegisterStreamables(arStream);
    return true;
}

// @fnv 0x00c36240
// src: XBOX_PDB 0x00c36240
unsigned char BSMultiBound::QPointWithin(int arg)
{
    if (pShape)
        return pShape->BSMultiBoundSphere_QPointWithin((NiPoint3*)arg);
    return 0;
}
