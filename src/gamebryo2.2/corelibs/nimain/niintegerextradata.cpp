// gamebryo2.2/corelibs/nimain/niintegerextradata.cpp: NiIntegerExtraData (7 functions)

#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiExtraData.h"
#include "../../../../include/NiIntegerExtraData.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/StrArr.h"

__forceinline void NiBinaryStream::Read(void* data)
{
    unsigned int size = 4;
    m_uiAbsoluteCurrentPos += m_pfnRead(this, data, 4, &size, 1);
}

// Calls NiExtraData::LoadBinary then reads m_iValue from the stream.
// @fnv 0x00a99d30
void NiIntegerExtraData::LoadBinary(NiStream& stream)
{
    NiExtraData::LoadBinary(stream);
    stream.m_pkIstr->Read(&m_iValue);
}

extern char const* const g_01202de0_arg1;

// @fnv 0x00a99c60
// src: COMMUNITY 0x00a99c60
char const* const* __cdecl NiIntegerExtraData_GetRTTI()
{
    return &g_01202de0_arg1;
}

extern int DAT_010a0d24;

// The shared class lacks these lifecycle/viewer declarations. Explicit object
// parameters preserve ECX; an unused EDX parameter keeps remaining arguments on the stack.
// @fnv 0x00a99c70
void __fastcall DestroyIntegerExtraData(NiIntegerExtraData* data)
{
    *reinterpret_cast<int**>(data) = &DAT_010a0d24;
    data->NiExtraData::DestroyFields_00a7b300();
}

// @fnv 0x00a99cd0
// src: EXE 0x00a99cd0
NiExtraData* NiIntegerExtraData_CreateObject()
{
    NiExtraData* pExtraData = static_cast<NiExtraData*>(BSFadeNode::operator new(0x10));
    if (pExtraData)
    {
        pExtraData->FUN_00a7b2e0();
        *reinterpret_cast<int**>(pExtraData) = &DAT_010a0d24;
        static_cast<NiIntegerExtraData*>(pExtraData)->m_iValue = 0;
        return pExtraData;
    }
    return 0;
}

void __cdecl operator delete(void*, unsigned int);
// @fnv 0x00a99d00
void* __fastcall DeleteIntegerExtraData(NiIntegerExtraData* data, void*, unsigned int auiFlags)
{
    *reinterpret_cast<int**>(data) = &DAT_010a0d24;
    data->NiExtraData::DestroyFields_00a7b300();
    if (auiFlags & 1)
        ::operator delete(data, 0x10);
    return data;
}

// NiExtraData has no shared declaration for its viewer-string override.
extern "C" void __cdecl FUN_00a7b580();

void* __cdecl _FUN_00a7d330(void*);
char* __cdecl NiGetViewerString_00a7d4d0(char const*, int);

// Appends the base viewer strings plus a formatted "m_iValue" entry to the string array, growing it as needed.
// @fnv 0x00a99d70
void __fastcall GetIntegerExtraDataViewerStrings(NiIntegerExtraData* data, void*, StrArr* apViewerStrings)
{
    typedef void (__thiscall* GetBaseViewerStrings)(NiExtraData*, StrArr*);
    reinterpret_cast<GetBaseViewerStrings>(&FUN_00a7b580)(data, apViewerStrings);

    char* pString = static_cast<char*>(_FUN_00a7d330(const_cast<char*>(g_01202de0_arg1)));

    unsigned int index = apViewerStrings->m_usSize;
    if (index >= apViewerStrings->m_usMaxSize)
        apViewerStrings->SetSize(index + apViewerStrings->m_usGrowBy);
    apViewerStrings->SetAt(index, pString);

    pString = NiGetViewerString_00a7d4d0("m_iValue", data->m_iValue);

    index = apViewerStrings->m_usSize;
    if (index >= apViewerStrings->m_usMaxSize)
        apViewerStrings->SetSize(index + apViewerStrings->m_usGrowBy);
    apViewerStrings->SetAt(index, pString);
}

extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int);
// @fnv 0x00a99c80
NiIntegerExtraData* __fastcall CreateIntegerExtraData(NiIntegerExtraData* data, void*, unsigned int argument)
{
    NiIntegerExtraData* result;
    NiIntegerExtraData* allocated = (NiIntegerExtraData*)Object_DispatchCommandFour(16);
    if (allocated != 0)
    {
        allocated->FUN_00a7b2e0();
        *(void**)allocated = &DAT_010a0d24;
        allocated->m_iValue = 0;
        result = allocated;
    }
    else
    {
        result = 0;
    }
    data->CopyMembers_00a7b330(result, reinterpret_cast<void*>(argument));
    result->m_iValue = data->m_iValue;
    return result;
}
