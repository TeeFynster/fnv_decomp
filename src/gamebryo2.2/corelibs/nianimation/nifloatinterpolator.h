// Unit-local NiFloatInterpolator declarations and inline bodies for shared classes.
#ifndef FNV_NIFLOATINTERPOLATOR_UNIT_H
#define FNV_NIFLOATINTERPOLATOR_UNIT_H


#include <float.h>
#include <stddef.h>

#define FNV_NIFI_SIZE_ASSERT(type, size) typedef char fnv_nifi_size_##type[(sizeof(type) == (size)) ? 1 : -1]
#define FNV_NIFI_OFFSET_ASSERT(type, member, offset)                                                                   \
    typedef char fnv_nifi_offset_##type##_##member[(offsetof(type, member) == (offset)) ? 1 : -1]

#define FNV_FORCEINLINE __forceinline

#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiFloatData.h"
#include "../../../../include/NiInterpolator.h"
#include "../../../../include/NiKeyBasedInterpolator.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiPointer.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}
inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

template <class T> FNV_FORCEINLINE NiPointer<T>::NiPointer(T* pObject) : m_pObject(pObject)
{
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}
template <class T> FNV_FORCEINLINE NiPointer<T>::NiPointer() : m_pObject(0)
{}
template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}
template <class T> inline NiPointer<T>::operator T*() const
{
    return m_pObject;
}

FNV_FORCEINLINE unsigned int NiBinaryStream::BinaryRead(void* pvBuffer, unsigned int uiTotalBytes,
    unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    m_uiAbsoluteCurrentPos += uiBytesRead;
    return uiBytesRead;
}
FNV_FORCEINLINE unsigned int NiBinaryStream::BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes,
    unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    m_uiAbsoluteCurrentPos += uiBytesWritten;
    return uiBytesWritten;
}

#include "../../../../include/NiFloatInterpolator.h"

// Release-mode diagnostics: asserts vanish, the verified read still runs.
#define NIASSERT(x) ((void)0)
#define NIVERIFYEQUALS(x, y) (x)

template <class T> FNV_FORCEINLINE void NiBinaryStreamLoad(NiBinaryStream& is, T* pValue, unsigned int uiNumEls = 1)
{
    NIASSERT(uiNumEls > 0);
    unsigned int uiSize = sizeof(T);
    NIVERIFYEQUALS(is.BinaryRead(pValue, sizeof(T) * uiNumEls, &uiSize, 1), sizeof(T) * uiNumEls);
}

template <class T> FNV_FORCEINLINE void ReadBinaryValue(NiStream& kStream, T& value)
{
    NiBinaryStreamLoad(*kStream.m_pkIstr, &value, 1);
}

#endif