
// src/gamebryo2.2/corelibs/nimain/nibooleanextradata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nibooleanextradata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiBooleanExtraData.h"
#include "../../../../include/NiExtraData.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiStream.h"

extern NiRTTI g_011f5f5c;

// @fnv 0x00a9af30
// src: COMMUNITY 0x00a9af30
NiRTTI* __cdecl NiBooleanExtraData_GetRTTI()
{
    return &g_011f5f5c;
}

extern int DAT_010a112c;

// @fnv 0x00a9af90
// src: EXE 0x00a9af90
void* __cdecl NiBooleanExtraData_CreateObject()
{
    void* p = BSFadeNode::operator new(0x10);
    if (p)
    {
        NiExtraData* pExtraData = static_cast<NiExtraData*>(p);
        pExtraData->FUN_00a7b2e0();
        *reinterpret_cast<void**>(p) = &DAT_010a112c;
        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(p) + 0xc) = 0;
    }
    else
    {
        return 0;
    }
    return p;
}

extern void __cdecl _FUN_00a7b300();
extern void __cdecl __Dummy_00b6fef0(void*, unsigned int);


// @fnv 0x00a9afc0
void* __fastcall FUN_00a9afc0(NiBooleanExtraData* self, void*, unsigned int flags)
{
    *reinterpret_cast<void**>(self) = &DAT_010a112c;
    _FUN_00a7b300();
    if (flags & 1)
        __Dummy_00b6fef0(self, 0x10);
    return self;
}

// @fnv 0x00a9af10
bool NiBooleanExtraData::IsEqualTo(NiObject* pObject)
{
    NiBooleanExtraData* pExtra = static_cast<NiBooleanExtraData*>(pObject);
    if (!pExtra)
        return false;
    return m_bValue == pExtra->m_bValue ? true : false;
}

// @fnv 0x00a9af40
// src: XBOX_PDB 0x00a9af40
NiBooleanExtraData* __fastcall NiBooleanExtraData_CreateClone(NiBooleanExtraData* self, void*, CloningProcess* pkCloning)
{
    NiBooleanExtraData* pkClone = static_cast<NiBooleanExtraData*>(BSFadeNode::operator new(0x10));
    if (pkClone)
    {
        pkClone->FUN_00a7b2e0();
        *reinterpret_cast<void**>(pkClone) = &DAT_010a112c;
        pkClone->m_bValue = false;
    }
    else
    {
        pkClone = 0;
    }
    self->CopyMembers_00a7b330(pkClone, pkCloning);
    pkClone->m_bValue = self->m_bValue;
    return pkClone;
}

inline unsigned int NiBinaryStream::BinaryRead(void* pvBuffer, unsigned int uiTotalBytes)
{
    unsigned int uiComponentSizes = 1;
    unsigned int uiRead = (*reinterpret_cast<NIBINARYSTREAM_READFN*>(reinterpret_cast<char*>(this) + 8))(this, pvBuffer, uiTotalBytes, &uiComponentSizes, 1);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += uiRead;
    return uiRead;
}

inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x24c);
}

extern void LoadExtraData();

// Calls the base NiExtraDataBase read, then reads one byte from the stream and stores whether it is nonzero in m_bValue.
// @fnv 0x00a9aff0
void __fastcall ReadFromStream(NiBooleanExtraData* self, void*, NiStream* istr)
{
    reinterpret_cast<void (__thiscall*)(NiExtraData*, NiStream*)>(&LoadExtraData)(self, istr);
    unsigned char ucValue;
    istr->GetBinaryStream()->BinaryRead(static_cast<void*>(&ucValue), 1);
    self->m_bValue = (ucValue != 0);
}

// The stream-like argument: the original reads a pointer at +0x250.

extern void SaveExtraData();

// @fnv 0x00a9b040
// src: XBOX_PDB 0x00a9b040
void __fastcall NiBooleanExtraData_SaveBinary(NiBooleanExtraData* self, void*, NiStream* s)
{
    reinterpret_cast<void (__thiscall*)(NiExtraData*, NiStream*)>(&SaveExtraData)(self, s);
    unsigned char ucValue = self->m_bValue;
    NiBinaryStream* pTarget = *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(s) + 0x250);
    {
        unsigned int one = 1;
        *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pTarget) + 4) +=
            (*reinterpret_cast<NiBinaryStream::NIBINARYSTREAM_WRITEFN*>(reinterpret_cast<char*>(pTarget) + 12))(pTarget, &ucValue, 1, &one, 1);
    }
}

struct ObjArray
{
    void Grow(unsigned int newCount);
    void Insert(unsigned int index, void** value);
    unsigned int unk00;
    unsigned int unk04;
    unsigned short m_08;
    unsigned short m_0A;
    unsigned short m_0C;
    unsigned short m_0E;
};

extern void* DAT_011f5f5c;
extern const char str_010a11c0[];
void* __cdecl LookupRtti(void* rtti);
void* __cdecl LookupName(const char* name, unsigned char flag);

extern void TouchExtraData();

// Calls Touch, then appends the RTTI pointer for DAT_011f5f5c and the result of LookupName(str_010a11c0, m_0C) to the array, growing it when full.
// @fnv 0x00a9b090
void __fastcall AppendRttiAndName(NiBooleanExtraData* self, void*, ObjArray* pArray)
{
    reinterpret_cast<void (__thiscall*)(NiExtraData*, ObjArray*)>(&TouchExtraData)(self, pArray);
    void* v = LookupRtti(DAT_011f5f5c);
    unsigned int count = pArray->m_0A;
    unsigned int cap = pArray->m_08;
    if (count >= cap)
    {
        pArray->Grow(count + pArray->m_0E);
    }
    pArray->Insert(count, &v);

    v = LookupName(str_010a11c0, *reinterpret_cast<unsigned char*>(&self->m_bValue));
    count = pArray->m_0A;
    cap = pArray->m_08;
    if (count >= cap)
    {
        pArray->Grow(count + pArray->m_0E);
    }
    pArray->Insert(count, &v);
}
