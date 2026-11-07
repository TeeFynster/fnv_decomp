#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiFixedString.h"
#include "../../../../include/NiExtraData.h"
#include "../../../../include/NiStringExtraData.h"
#include "../../../../include/NiStream.h"

// src/gamebryo2.2/corelibs/nimain/nistringextradata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nistringextradata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x00a74200
// src: GAMEBRYO_LIB 0x00a74200
void NiStringExtraData::SaveBinary_00a74200(NiStream& stream)
{
    NiExtraData::SaveBinary(stream);
    stream.SerializeString(m_kStringBuffer);
}

extern "C" void* DAT_011f4a38;

// Returns the address of the global DAT_011f4a38.
// @fnv 0x00a74220
// src: COMMUNITY 0x00a74220
void* __cdecl NiStringExtraData_GetRTTI()
{
    return &DAT_011f4a38;
}

extern "C" int EmptyFS;
extern "C" void* DAT_0109d39c;
// @fnv 0x00a74230
// src: EXE 0x00a74230
void* __cdecl NiStringExtraData_CreateObject()
{
    void* p = BSFadeNode::operator new(0x10);
    if (p)
    {
        static_cast<NiExtraData*>(p)->FUN_00a7b2e0();
        *(void**)p = &DAT_0109d39c;
        static_cast<NiStringExtraData*>(p)->m_p = reinterpret_cast<char*>(EmptyFS);
        return p;
    }
    return 0;
}

// Standalone implementations cover members absent from the shared headers.
// The unused EDX argument preserves the original ECX/stack calling convention.
namespace fnv_00a74260 {
struct NiStreamHelper
{
    void ReadFixedString(NiFixedString&);
    void ReadStringTableEntry(NiFixedString&);
};
// @fnv 0x00a74260
void __fastcall NiStringExtraData_LoadBinary(NiStringExtraData* self, void*, NiStream& stream)
{
    self->NiExtraData::LoadBinary(stream);
    if (*(unsigned int*)((char*)&stream + 0xd8) < 0x14010001)
        ((NiStreamHelper*)&stream)->ReadFixedString(*reinterpret_cast<NiFixedString*>(&self->m_p));
    else
        ((NiStreamHelper*)&stream)->ReadStringTableEntry(*reinterpret_cast<NiFixedString*>(&self->m_p));
}
}  // namespace fnv_00a74260

extern "C" bool FUN_00a7b290();
struct VHack
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(const char*);
};
// @fnv 0x00a741d0
bool __fastcall NiStringExtraData_RegisterStreamables(NiStringExtraData* self, void*, NiStream& stream)
{
    if (!reinterpret_cast<bool (__thiscall*)(NiExtraData*, NiStream&)>(&FUN_00a7b290)(self, stream))
        return false;
    ((VHack*)&stream)->v8(self->m_kStringBuffer);
    return true;
}

// @fnv 0x00a742a0
unsigned char __fastcall NiStringExtraData_Equals(NiStringExtraData* self, void*, NiStringExtraData* pOther)
{
    if (pOther == 0)
    {
        return 0;
    }

    return self->m_p == pOther->m_p;
}

extern "C" void* DAT_0109d39c;
extern "C" void* DAT_0109b220;
extern "C" __declspec(dllimport) void __stdcall FUN_00fdf1c4_import(void* apMemory);
void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);

// Resets the vtable pointer, frees the data buffer if it is not the default, calls FUN_00a7b300, and optionally deallocates the object.
// @fnv 0x00a742c0
NiStringExtraData* __fastcall NiStringExtraData_Destroy(NiStringExtraData* self, void*, unsigned int acFlags)
{
    *reinterpret_cast<volatile int*>(self) = (int)&DAT_0109d39c;
    char* pData = *(char* volatile*)&self->m_p;
    if (pData != (char*)DAT_0109b220)
    {
        FUN_00fdf1c4_import(pData - 8);
    }
    self->DestroyFields_00a7b300();
    if (acFlags & 1)
    {
        FUN_00aa1460(self, 0x10);
    }
    return self;
}

namespace fnv_00a74300 {
extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int);
extern "C" char* DAT_0109b220;
extern "C" void* DAT_0109d39c;
extern "C" void(__stdcall* DAT_00fdf1c0)(void*);
extern "C" void(__stdcall* DAT_00fdf1c4)(void*);

// @fnv 0x00a74300
void* __fastcall NiStringExtraData_CreateCopy(NiStringExtraData* self, void*, int arg)
{
    NiStringExtraData* esi = (NiStringExtraData*)Object_DispatchCommandFour(0x10);
    if (esi != 0)
    {
        esi->FUN_00a7b2e0();
        *reinterpret_cast<void**>(esi) = (void*)&DAT_0109d39c;
        esi->m_p = DAT_0109b220;
    }
    else
    {
        esi = 0;
    }
    self->CopyMembers_00a7b330(esi, reinterpret_cast<void*>(arg));
    char* edi = self->m_p;
    if (esi->m_p != edi)
    {
        if (edi != DAT_0109b220)
        {
            DAT_00fdf1c0(edi - 8);
        }
        if (esi->m_p != DAT_0109b220)
        {
            DAT_00fdf1c4(esi->m_p - 8);
        }
        esi->m_p = edi;
    }
    return esi;
}
}  // namespace fnv_00a74300

struct NiStrTable
{
    int unk00;
    int unk04;
    unsigned short unk08;
    unsigned short unk0A;
    unsigned short unk0C;
    unsigned short unk0E;
    void SetSize(unsigned int n);
    void SetAt(unsigned int i, char*& v);
    void Add(char* v)
    {
        unsigned int n = unk0A;
        if (n >= unk08)
        {
            SetSize(n + unk0E);
        }
        SetAt(n, v);
    }
};

extern "C" char* __cdecl NiViewerStrings_NiGetViewerString_Title(char* s);
extern "C" char* __cdecl NiGetViewerString_00a7d5e0(const char* key, char* value);

extern "C" void FUN_00a7b580();

// @fnv 0x00a74380
void __fastcall NiStringExtraData_GetViewerStrings(NiStringExtraData* self, void*, NiStream& stream)
{
    reinterpret_cast<void (__thiscall*)(NiExtraData*, NiStream&)>(&FUN_00a7b580)(self, stream);
    reinterpret_cast<NiStrTable&>(stream).Add(NiViewerStrings_NiGetViewerString_Title((char*)DAT_011f4a38));
    char* s = self->m_p;
    reinterpret_cast<NiStrTable&>(stream).Add(NiGetViewerString_00a7d5e0("m_kString", s));
}
