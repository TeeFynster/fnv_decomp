// NiRefObject_inline.h: the inline bodies of NiRefObject (Gamebryo NiRefObject.inl) for units that inline them.
// The shared include/NiRefObject.h declares these members; a unit that uses the inline forms includes this file
// after it. NiAtomicIncrement/NiAtomicSubtract are Gamebryo's NiSystem atomics (InterlockedIncrement/Decrement).
#pragma once
#include "NiRefObject.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);

#ifndef FNV_NI_ATOMIC_DEFINED
#define FNV_NI_ATOMIC_DEFINED
inline unsigned int NiAtomicIncrement(unsigned int& value)
{
    return InterlockedIncrement(reinterpret_cast<volatile long*>(&value));
}
inline unsigned int NiAtomicSubtract(unsigned int& value)
{
    return InterlockedDecrement(reinterpret_cast<volatile long*>(&value));
}
#endif

inline NiRefObject::NiRefObject()
{
    m_uiRefCount = 0;
    NiAtomicIncrement(ms_lObjectCount);
}
inline void NiRefObject::IncRefCount()
{
    NiAtomicIncrement(m_uiRefCount);
}
inline void NiRefObject::DecRefCount()
{
    if (NiAtomicSubtract(m_uiRefCount) == 0)
        DeleteThis();
}
