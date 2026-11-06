// Authored unit-local declarations for gamebryo2.2/corelibs/nimain/nigeometrydata.cpp.
// FNV (Fallout: New Vegas, Gamebryo 2.2 branch) revision of NiGeometryData.
// (m_usVertices +0x8 .. m_bVerticesDirty +0x3C, size 0x40) and the
// community reverse-engineered header (JIP LN NVSE netimmerse.h NiGeometryData).
// NiObject, NiStream and NiBinaryStream come from the shared headers in include/;
// NiPointer comes from layout_support.h; streaming assignments expand the NiPointer
// idiom manually (dec-old before inc-new), matching the original bytes.
#ifndef FNV_NIGEOMETRYDATA_UNIT_H
#define FNV_NIGEOMETRYDATA_UNIT_H


#include "../../../../include/NiGeometryData.h"
#include "../../../../include/NiAdditionalGeometryData.h"
#include "../../../../include/NiBound.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiBinaryStream.h"

#ifndef FNV_FORCEINLINE
#define FNV_FORCEINLINE __forceinline
#endif

// Gamebryo's inline reference counting (NiRefObject.inl). The shared NiObject
// header also declares IncRefCount/DecRefCount, which hide NiRefObject's; here
// they are the same inline operation.
__forceinline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}
__forceinline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

// NiStream::GetFileVersion reads the NIF version at +0xD8 (inline in Gamebryo).
__forceinline unsigned int NiStream::GetFileVersion() const
{
    return *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 0xd8);
}

// Gamebryo's NiPointer with its inline bodies (NiSmartPointer.inl); the shared NiPointer (include/NiAVObject.h)
// declares them out of line. Used where this unit's original code inlines the smart pointer.
template <class T> class NiGeomInlinePointer
{
  public:
    T* m_pObject;
    NiGeomInlinePointer(T* object = 0)
    {
        m_pObject = object;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~NiGeomInlinePointer()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
};

#endif
