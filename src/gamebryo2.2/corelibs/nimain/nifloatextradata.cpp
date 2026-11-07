#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiExtraData.h"
#include "../../../../include/NiFloatExtraData.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/StrArr.h"

// src/gamebryo2.2/corelibs/nimain/nifloatextradata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nifloatextradata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct GlobalObjectO2_00a7b610
{
};

extern GlobalObjectO2_00a7b610 g_011f5f40;

// @fnv 0x00a9a420
// src: COMMUNITY 0x00a9a420
GlobalObjectO2_00a7b610* __cdecl NiFloatExtraData_GetRTTI()
{
    return &g_011f5f40;
}

extern void* DAT_010a0ec4;
extern void __cdecl DestroyFields_00a7b300();
extern void __cdecl operator delete(void*, unsigned int);

// @fnv 0x00a9a4b0
void* NiFloatExtraData::Destroy(unsigned int flags)
{
    *reinterpret_cast<void**>(this) = &DAT_010a0ec4;
    ::DestroyFields_00a7b300();
    if (flags & 1)
        ::operator delete(this, 0x10);
    return this;
}

// Returns true if pObject is non-null and its float at offset 12 equals m_fValue, otherwise false.
// @fnv 0x00a9a3f0
bool __fastcall MatchesFloatValue(NiFloatExtraData* self, void*, NiObject* pObject)
{
    NiFloatExtraData* pExtra = (NiFloatExtraData*)pObject;
    if (!pExtra)
        return false;
    if (self->m_fValue != pExtra->m_fValue)
        return false;
    return true;
}

// @fnv 0x00a9a430
void* NiExtraData::CloneFloatExtraData(void* kCloning)
{
    NiFloatExtraData* pkObject;
    pkObject = (NiFloatExtraData*)BSFadeNode::operator new(0x10);
    if (pkObject)
    {
        ((NiExtraData*)pkObject)->FUN_00a7b2e0();
        pkObject->m_fValue = 0.0f;
        *reinterpret_cast<void**>(pkObject) = &DAT_010a0ec4;
    }
    else
    {
        pkObject = 0;
    }
    this->CopyMembers_00a7b330(pkObject, kCloning);
    pkObject->m_fValue = static_cast<NiFloatExtraData*>(this)->m_fValue;
    return pkObject;
}

namespace fnv_00a9a480 {

// @fnv 0x00a9a480
// src: EXE 0x00a9a480
void* __cdecl NiFloatExtraData_CreateObject()
{
    void* p = BSFadeNode::operator new(0x10);
    if (p)
    {
        reinterpret_cast<NiExtraData*>(p)->FUN_00a7b2e0();
        *reinterpret_cast<float*>(reinterpret_cast<char*>(p) + 0xc) = 0.0f;
        *reinterpret_cast<void**>(p) = &DAT_010a0ec4;
        return p;
    }
    return 0;
}
}  // namespace fnv_00a9a480

namespace fnv_00a9a4e0 {
// Calls NiExtraData::SaveBinary then writes the 4-byte m_fValue to the stream and advances its position.
// @fnv 0x00a9a4e0
void __fastcall SaveFloatExtraData(NiFloatExtraData* self, void*, NiStream& stream)
{
    self->NiExtraData::SaveBinary(stream);
    NiBinaryStream* __restrict output =
        *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(&stream) + 0x250);
    unsigned int size = 4;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(output) + 4) +=
        (*reinterpret_cast<NiBinaryStream::NIBINARYSTREAM_WRITEFN*>(reinterpret_cast<char*>(output) + 12))(
            output, &self->m_fValue, 4, &size, 1);
}
}  // namespace fnv_00a9a4e0

// The shared NiExtraData header does not declare its StrArr viewer overload.
extern void __fastcall GetExtraDataViewerStrings(NiExtraData* self, void*, StrArr* strings);

char* __cdecl _FUN_00a7d330(GlobalObjectO2_00a7b610* object);
char* __cdecl NiGetViewerString_00a7d550(char const* name, float value);

// @fnv 0x00a9a520
void __fastcall AppendViewerStrings(NiFloatExtraData* self, void* unused, StrArr* strings)
{
    GetExtraDataViewerStrings(self, unused, strings);

    char* value =
        _FUN_00a7d330(reinterpret_cast<GlobalObjectO2_00a7b610*>(*reinterpret_cast<unsigned int*>(&g_011f5f40)));

    unsigned int index = strings->m_usSize;

    if (index >= strings->m_usMaxSize)
        strings->SetSize(index + strings->m_usGrowBy);

    strings->SetAt(index, value);

    value = NiGetViewerString_00a7d550("m_fValue", self->m_fValue);

    index = strings->m_usSize;

    if (index >= strings->m_usMaxSize)
        strings->SetSize(index + strings->m_usGrowBy);

    strings->SetAt(index, value);
}
