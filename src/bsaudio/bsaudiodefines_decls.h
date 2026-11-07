// bsaudio/bsaudiodefines_decls.h: declares SoundMessageRecord
#ifndef FNV_BSAUDIODEFINES_DECLS_H
#define FNV_BSAUDIODEFINES_DECLS_H

#include "../../include/NiAVObject.h"
#include "../../include/NiPointer.h"
#include "../../include/NiTListItem.h"

#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);

__forceinline void NiAVObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

template <> __forceinline NiPointer<NiAVObject>::operator NiAVObject*() const
{
    return m_pObject;
}

template <> __forceinline NiPointer<NiAVObject>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}
void __cdecl NiObjectGarbage_Add(NiAVObject*);
class SoundMessageRecord
{
  public:
    unsigned int fields[4];
    NiPointer<NiAVObject> pObject;
    ~SoundMessageRecord();
};
#endif
