#include "../../../../include/BSTreadTransfInterpolator.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiFixedString.h"
#include "../../../../include/NiQuatTransform.h"
#include "../../../../include/NiStream.h"

// This variant retains the original /MT /O2 /GS /Gy code generation for LoadBinary.

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern MemoryManager _g_memoryManager;

class TreadTransformEntry
{
  public:
    NiQuatTransform first;
    NiQuatTransform second;
    NiFixedString name;

    TreadTransformEntry() throw();
    static void* operator new[](unsigned int size)
    {
        return _g_memoryManager.Allocate(size);
    }
};

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}

inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pObject)
{
    if (m_pObject != pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

// The shared stream declarations leave these storage fields opaque.
inline NiBinaryStream& NiStream::Istr()
{
    return **reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x24C);
}

inline unsigned int NiBinaryStream::BinaryRead(void* p, unsigned int n, unsigned int* sizes, unsigned int count)
{
    unsigned int read = (*reinterpret_cast<NIBINARYSTREAM_READFN*>(reinterpret_cast<char*>(this) + 8))(
        this, p, n, sizes, count);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += read;
    return read;
}

template <class T> inline void NiBinaryStreamLoad(NiBinaryStream* pkIstr, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiComponentSize = sizeof(T);
    pkIstr->BinaryRead(pValue, uiNumEls * sizeof(T), &uiComponentSize, 1);
}

template <class T> inline void NiStreamLoadBinary(NiStream& kStream, T& kValue)
{
    NiBinaryStreamLoad(&kStream.Istr(), &kValue, 1);
}

// @fnv 0x00a438d0
void BSTreadTransfInterpolator::LoadBinary(NiStream& kStream)
{
    NiKeyBasedInterpolator::LoadBinary(kStream);
    NiStreamLoadBinary(kStream, count);
    entries = new TreadTransformEntry[count];
    for (unsigned int i = 0; i < count; i++)
    {
        kStream.ReadStringTableEntry(entries[i].name);
        entries[i].first.LoadBinary(kStream);
        entries[i].second.LoadBinary(kStream);
    }
    reference = kStream.DeserializeObject();
}
