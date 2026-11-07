// gamebryo2.2/corelibs/nimain/niloddata.cpp: NiLODData (5 functions)
#include "../../../../include/NiLODData.h"

unsigned int __cdecl _access_s(const void*, unsigned int, unsigned int, void*);
// Writes count bytes from buffer to the stream, advances position by the bytes written, and returns that count.
// @fnv 0x00aa1570
unsigned int NiLODData::Write(const void* buffer, unsigned int count)
{
    unsigned int written = _access_s(buffer, 1, count, *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x24));
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x1c) += written;
    return written;
}

extern const char* const g_011f5ee8_arg1;

// @fnv 0x00aa09e0
// src: COMMUNITY 0x00aa09e0
const char* __cdecl NiLODData_GetRTTI()
{
    return (const char*)&g_011f5ee8_arg1;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern long volatile DAT_011f4400;
extern int DAT_0109b4f4;
inline NiRefObject::NiRefObject() : m_uiRefCount(0)
{
    InterlockedIncrement(&DAT_011f4400);
}
// Initialises the object by storing the vtable pointer DAT_0109b4f4 into its first field.
// @fnv 0x00a5d3a0
NiObject::NiObject()
{
    *(void**)this = (void*)&DAT_0109b4f4;
}

namespace fnv_00aa09f0 {
extern int DAT_010a2254;

// Scalar deleting destructor; the flag controls whether storage is released.
// @fnv 0x00aa09f0
void* __fastcall DestroyNiLODData(NiLODData* self, void*, int flags)
{
    *reinterpret_cast<void**>(self) = &DAT_010a2254;
    self->NiRefObject::~NiRefObject();
    if (flags & 1)
        NiObject::operator delete(self, sizeof(NiLODData));
    return self;
}
}  // namespace fnv_00aa09f0

// @fnv 0x00aa09d0
// src: COMMUNITY 0x00aa09d0
char __stdcall NiInterpolator_ResolveDependencies(char)
{
    return 1;
}
