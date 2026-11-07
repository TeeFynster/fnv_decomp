
// src/gamebryo2.2/corelibs/nimain/nishadeproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nishadeproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiCullingProperty.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiProperty.h"
#include "../../../../include/NiShadeProperty.h"

extern int DAT_0109e274;

// @fnv 0x00a814e0
NiObject* NiShadeProperty::CreateObject()
{
    NiShadeProperty* node = static_cast<NiShadeProperty*>(NiProperty::operator new(0x20));
    if (node)
    {
        node->NiProperty::NiProperty();
        node->m_uFlags = 1;
        *(void**)node = &DAT_0109e274;
        node->iShaderPropertyType = -1;
        return node;
    }
    return 0;
}

inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}
// @fnv 0x00a81480
// src: XBOX_PDB 0x00a81480
NiObject* NiShadeProperty::CreateClone_00a81480(CloningProcess& kCloning)
{
    NiShadeProperty* pkObject = (NiShadeProperty*)NiProperty::operator new(32);
    if (pkObject)
    {
        ::new (pkObject) NiProperty();
        *(void**)pkObject = (void*)&DAT_0109e274;
        pkObject->iShaderPropertyType = -1;
        pkObject->m_uFlags = 1;
    }
    else
    {
        pkObject = 0;
    }
    ((NiCullingProperty*)this)->NiProperty_CopyMembers((NiCullingProperty*)pkObject, kCloning);
    pkObject->m_uFlags = m_uFlags;
    return (NiObject*)pkObject;
}

// The shared NiProperty declaration does not yet expose these base routines.
struct PropertyRoutines
{
    void SaveBinary(NiStream& stream);
    bool IsEqual(NiObject* object);
    void GetViewerStrings(void* strings);
};

// @fnv 0x00a815c0
void NiShadeProperty::SaveBinary(NiStream& kStream)
{
    reinterpret_cast<PropertyRoutines*>(this)->SaveBinary(kStream);
    NiBinaryStream* __restrict pkOstr = *(NiBinaryStream**)((char*)&kStream + 0x250);
    unsigned int size = 2;
    *(unsigned int*)((char*)pkOstr + 4) +=
        (*(NiBinaryStream::WriteFunction*)((char*)pkOstr + 0xc))(pkOstr, &m_uFlags, 2, &size, 1);
}

inline unsigned int NiBinaryStream::Read(void* pvBuffer, unsigned int uiSize)
{
    unsigned int uiBytes = uiSize;
    unsigned int uiRet = (*(ReadFunction*)((char*)this + 8))(this, pvBuffer, uiSize, &uiBytes, 1);
    *(unsigned int*)((char*)this + 4) += uiRet;
    return uiRet;
}

// @fnv 0x00a95190
// src: XBOX_PDB 0x00a95190
void NiShadeProperty::NiDitherProperty_LoadBinary(NiStream& kStream)
{
    NiProperty::LoadBinary(kStream);
    if (*(unsigned int*)((char*)&kStream + 0xd8) < 0x0A000102)
    {
        m_uFlags = *(unsigned short*)((char*)&kStream + 0x288) & 1;
    }
    else
    {
        (*(NiBinaryStream**)((char*)&kStream + 0x24c))->Read(&m_uFlags, 2);
    }
}

// @fnv 0x00a9a5b0
// src: XBOX_PDB 0x00a9a5b0
bool NiShadeProperty::NiCullingProperty_IsEqual(NiObject* pkObject)
{
    if (!reinterpret_cast<PropertyRoutines*>(this)->IsEqual(pkObject))
        return false;
    NiShadeProperty* pkShade = (NiShadeProperty*)pkObject;
    unsigned char n = (unsigned char)pkShade->m_uFlags;
    n = ~n;
    n ^= (unsigned char)m_uFlags;
    n &= 1;
    return n;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
void* __cdecl Object_DispatchCommandFour(unsigned int);

inline void ReleaseProperty(NiShadeProperty* property)
{
    if (InterlockedDecrement((volatile long*)&property->m_uiRefCount) == 0)
        property->DeleteThis();
}

struct PropertyHolder
{
    NiShadeProperty* property;
    void set(NiShadeProperty* value)
    {
        if (property != value)
        {
            if (property != 0)
                ReleaseProperty(property);
            property = value;
            if (value != 0)
                InterlockedIncrement((volatile long*)&value->m_uiRefCount);
        }
    }
};
extern PropertyHolder DAT_011f5ae8;

// Creates the default shade property and retains it in DAT_011f5ae8.
// @fnv 0x00a81520
// src: XBOX_PDB 0x00a81520
void __cdecl NiShadeProperty__SDMInit()
{
    void* allocation = Object_DispatchCommandFour(32);
    NiShadeProperty* replacement;
    if (allocation != 0)
    {
        replacement = static_cast<NiShadeProperty*>(allocation);
        replacement->NiProperty::NiProperty();
        *(void**)replacement = &DAT_0109e274;
        replacement->iShaderPropertyType = -1;
        replacement->m_uFlags = 1;
    }
    else
    {
        replacement = 0;
    }
    DAT_011f5ae8.set(replacement);
}

namespace fnv_00a81590 {
extern NiShadeProperty* DAT_011f5ae8;

// If the global object pointer is set, decrements its reference count and clears the pointer.
// @fnv 0x00a81590
// src: COMMUNITY 0x00a81590
void NiShadeProperty__SDMShutdown()
{
    if (DAT_011f5ae8)
    {
        ReleaseProperty(DAT_011f5ae8);
        DAT_011f5ae8 = 0;
    }
}
}  // namespace fnv_00a81590

extern void* DAT_011f5ae0;
void* __cdecl NiViewerStrings_NiGetViewerString_Title(void* p);
void* __cdecl NiGetViewerString(const char* name, bool value);
struct NiArr
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned short m_08;
    unsigned short m_0a;
    unsigned short m_0c;
    unsigned short m_0e;
    void FUN_0096ad30(unsigned int n);
    void FUN_0096ae90(unsigned int idx, void** out);
    void Add(void* x)
    {
        unsigned int i = m_0a;
        if (i >= m_08)
            FUN_0096ad30(i + m_0e);
        FUN_0096ae90(i, &x);
    }
};
// @fnv 0x00a81600
void NiShadeProperty::GetViewerStrings(NiViewerStringsArray* strings)
{
    NiArr* a = reinterpret_cast<NiArr*>(strings);
    reinterpret_cast<PropertyRoutines*>(this)->GetViewerStrings(a);
    a->Add(NiViewerStrings_NiGetViewerString_Title(DAT_011f5ae0));
    bool b = (m_uFlags & 1) != 0;
    a->Add(NiGetViewerString("m_bSmooth", b));
}
