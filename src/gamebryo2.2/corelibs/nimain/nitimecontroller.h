#ifndef FNV_NITIMECONTROLLER_UNIT_H
#define FNV_NITIMECONTROLLER_UNIT_H

#include <stddef.h>
#define FNV64_NIPOINTER_INLINE_BODIES
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiGeometry.h"
#include "../../../../include/NiGeometryData.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiObjectNET.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiTimeController.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

__forceinline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}
__forceinline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}
inline NiTimeController* NiObjectNET::GetControllers() const { return m_spControllers; }
inline NiTimeController* NiTimeController::GetNext() const { return m_spNextController.m_pObject; }
inline NiGeometryData* NiGeometry::GetModelData() const { return m_spModelData.m_pObject; }
inline NiGeometryData* NiGeometry::GetModelData() { return m_spModelData.m_pObject; }
inline unsigned int NiStream::GetFileVersion() const { return m_uiNifFileVersion; }
inline unsigned int NiBinaryStream::BinaryRead(void* buffer, unsigned int bytes, unsigned int* sizes, unsigned int count)
{
    unsigned int read = m_pfnRead(this, buffer, bytes, sizes, count);
    m_uiAbsoluteCurrentPos += read;
    return read;
}
inline unsigned int NiBinaryStream::BinaryWrite(const void* buffer, unsigned int bytes, unsigned int* sizes, unsigned int count)
{
    unsigned int written = m_pfnWrite(this, buffer, bytes, sizes, count);
    m_uiAbsoluteCurrentPos += written;
    return written;
}
template <class T> void NiBinaryStreamLoad(NiBinaryStream& stream, T* value, unsigned int count = 1)
{
    unsigned int size = sizeof(T);
    stream.BinaryRead(value, sizeof(T) * count, &size, 1);
}
template <class T> void ReadBinaryValue(NiStream& stream, T& value)
{
    NiBinaryStreamLoad(*stream.m_pkIstr, &value, 1);
}

// The shared table still names these boolean virtual slots as unknown void hooks.
inline bool NiTimeController::IsGeometryController() const
{
    typedef bool (__thiscall* Query)(const NiTimeController*);
    return reinterpret_cast<Query>((*reinterpret_cast<void***>(const_cast<NiTimeController*>(this)))[40])(this);
}
inline void NiTimeController::SetControllerActive(bool active)
{
    m_uiObjectFlags = (m_uiObjectFlags & ~0x80) | (active << 7);
}

inline bool GetControllerActive(const NiTimeController* controller)
{ return (bool)((controller->m_uiObjectFlags >> 3) & 1); }
inline bool GetControllerForceUpdate(const NiTimeController* controller)
{ return (bool)((controller->m_uiObjectFlags >> 7) & 1); }
inline bool GetControllerComputeScaledTime(const NiTimeController* controller)
{ return (bool)((controller->m_uiObjectFlags >> 6) & 1); }

#include "../../../../include/NiTMallocInterface.h"
#include "../../../../include/NiTArray.h"

#endif
