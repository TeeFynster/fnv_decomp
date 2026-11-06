// gamebryo2.2/corelibs/nimain/niskininstance_decls.h: local pointer assignment body and allocator declaration
#pragma once

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
#include "../../../../include/NiObject.h"
#include "../../../../include/NiStream.h"

template <class T> __forceinline NiPointer<T>& NiPointer<T>::operator=(T* value)
{
    if (m_pObject != value)
    {
        T* old = m_pObject;
        if (old && InterlockedDecrement((volatile long*)&old->m_uiRefCount) == 0)
            old->DeleteThis();
        m_pObject = value;
        if (value)
            InterlockedIncrement((volatile long*)&value->m_uiRefCount);
    }
    return *this;
}
void* _NiMalloc(unsigned int);
