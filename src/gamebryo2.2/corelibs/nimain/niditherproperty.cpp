
// src/gamebryo2.2/corelibs/nimain/niditherproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/niditherproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiCullingProperty.h"
#include "../../../../include/NiProperty.h"
#include "../../../../include/StrArr.h"

extern void* g_011f5f48;

// @fnv 0x00a9a5e0
// src: COMMUNITY 0x00a9a5e0
void* __cdecl NiDitherProperty_GetRTTI()
{
    return &g_011f5f48;
}

// @fnv 0x00dc9bc0
// src: GUESS 0x00dc9bc0 (confidence: low)
int __cdecl Object_ComputeValue_00dc9bc0()
{
    return 8;
}

extern void* DAT_010a0f6c;

// @fnv 0x00a9a640
// src: EXE 0x00a9a640
void* __cdecl NiDitherProperty_CreateObject()
{
    void* p = BSFadeNode::operator new(0x1c);
    if (p)
    {
        NiProperty* property = static_cast<NiProperty*>(p);
        property->NiProperty::NiProperty();
        *(short*)((char*)p + 0x18) = 0;
        *(void**)((char*)p + 0) = &DAT_010a0f6c;
        return p;
    }
    return 0;
}

// Allocates and constructs a copy of this NiCullingProperty, runs FUN_00a5d7a0 on it, copies m_usFlags, and returns the copy.
// @fnv 0x00a9a5f0
// src: XBOX_PDB 0x00a9a5f0
NiCullingProperty* NiCullingProperty::NiDitherProperty_CreateClone(CloningProcess& process)
{
    NiCullingProperty* copy = (NiCullingProperty*)BSFadeNode::operator new(0x1c);
    if (copy)
    {
        copy->NiProperty::NiProperty();
        *(void**)copy = &DAT_010a0f6c;
        copy->m_usFlags = 0;
    }
    else
    {
        copy = 0;
    }
    NiProperty_CopyMembers(copy, process);
    copy->m_usFlags = m_usFlags;
    return copy;
}

char* __cdecl NiViewerStrings_NiGetViewerString_Title(char const*);
char* __cdecl NiGetViewerString(char const*, bool);
// The base property viewer helper is not declared with StrArr in NiProperty.h.
struct NiDitherProperty : NiProperty
{
    unsigned char m_bDither;
    void AppendString(StrArr*);
    void AppendDitherSettings(StrArr*);
};
union Temporary
{
    char* text;
    bool flag;
};
// Appends the g_011f5f48 string and a formatted "m_bDither" flag value to the array, growing it as needed.
// @fnv 0x00a9a670
void NiDitherProperty::AppendDitherSettings(StrArr* array)
{
    AppendString(array);
    Temporary value;
    value.text = NiViewerStrings_NiGetViewerString_Title((char const*)g_011f5f48);
    unsigned int index = array->m_usSize;
    if (index >= array->m_usMaxSize)
        array->SetSize(index + array->m_usGrowBy);
    array->SetAt(index, value.text);
    value.flag = (m_bDither & 1) != 0;
    value.text = NiGetViewerString("m_bDither", value.flag);
    index = array->m_usSize;
    if (index >= array->m_usMaxSize)
        array->SetSize(index + array->m_usGrowBy);
    array->SetAt(index, value.text);
}
