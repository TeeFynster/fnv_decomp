// gamebryo2.2/corelibs/nianimation/niextradatacontroller.cpp: NiPSysModifierCtlr and NiExtraDataController (8 functions)

#include "../../../../include/NiExtraDataController.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiObjectNET.h"
#include "../../../../include/NiPSysModifierCtlr.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/StrArr.h"

inline unsigned int NiStream::version()
{
    return *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 0xd8);
}

// The shared controller lacks this out-of-line helper. ECX holds self.
void __fastcall RefreshExtraData(NiExtraDataController* self);

// @fnv 0x00a571a0
void NiPSysModifierCtlr::LoadBinary(NiStream& stream)
{
    NiSingleInterpController::LoadBinary(stream);
    if (stream.version() < 0x14010001)
        stream.ReadFixedString(m_kTargetModifierName);
    else
        stream.ReadStringTableEntry(m_kTargetModifierName);
}

// @fnv 0x00a57400
// src: XBOX_PDB 0x00a57400
void NiExtraDataController::PostLinkObject_00a57400(NiStream& kStream)
{
    NiObject::LinkObject(kStream);
    if (m_pkTarget)
        RefreshExtraData(this);
}

// Registers the base streamables and then the extra-data name.
// @fnv 0x00a57100
bool __fastcall RegisterExtraDataStreamables(NiExtraDataController* self, int, NiStream& kStream)
{
    if (!self->NiSingleInterpController::RegisterStreamables(kStream))
        return false;
    kStream.RegisterFixedString(self->m_kDataName);
    return true;
}

__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
// Releases the extra data and resolves it again after changing the target.
// @fnv 0x00a57330
void __fastcall SetExtraDataTarget(NiExtraDataController* self, int, NiObjectNET* pkTarget)
{
    NiExtraData* p = self->m_pExtraData.m_pObject;
    if (p)
    {
        if (InterlockedDecrement((volatile long*)&p->m_uiRefCount) == 0)
            p->DeleteThis();
        self->m_pExtraData.m_pObject = 0;
    }
    self->NiTimeController::SetTarget(pkTarget);
    if (self->m_pkTarget)
        RefreshExtraData(self);
}

extern char const* const g_011f3e6c_arg1;

void __stdcall _FUN_00a390a0(StrArr* array);
void* __cdecl _FUN_00a7d330(void* value);
char* __cdecl NiGetViewerString_00a7d5e0(char const* lhs, char const* rhs);

// @fnv 0x00a57420
void __fastcall GetExtraDataViewerStrings(NiExtraDataController* self, int, StrArr* strings)
{
    StrArr* array = strings;

    _FUN_00a390a0(array);

    char* value = static_cast<char*>(_FUN_00a7d330(const_cast<char*>(g_011f3e6c_arg1)));

    unsigned int index = array->m_usSize;
    if (index >= array->m_usMaxSize)
        array->SetSize(index + array->m_usGrowBy);
    array->SetAt(index, value);

    char const* pcExtraDataName = self->m_kDataName.m_kHandle;
    value = NiGetViewerString_00a7d5e0("Extra Data Name", pcExtraDataName);

    index = array->m_usSize;
    if (index >= array->m_usMaxSize)
        array->SetSize(index + array->m_usGrowBy);
    array->SetAt(index, value);
}

struct FUN_00a57150_obj53
{
    void FUN_00a53c30(void* first, void** ppArg);
};

struct FUN_00a57150_obj66
{
    void FUN_0066b0d0(void* arg);
};

// @fnv 0x00a57150
void __fastcall ProcessExtraDataClone(NiExtraDataController* self, int, void* arg)
{
    void* src = arg;
    self->NiSingleInterpController::ProcessClone(*(CloningProcess*)src);
    FUN_00a57150_obj53* o = (FUN_00a57150_obj53*)*(void**)src;
    o->FUN_00a53c30(self, &arg);
    if (self->m_pkTarget != 0)
    {
        if (((NiExtraDataController*)arg)->m_pkTarget != 0)
        {
            NiExtraDataController* other = (NiExtraDataController*)arg;
            FUN_00a57150_obj53* o2 = (FUN_00a57150_obj53*)*(void**)src;
            o2->FUN_00a53c30(self->m_pExtraData.m_pObject, &arg);
            FUN_00a57150_obj66* p = (FUN_00a57150_obj66*)&other->m_pExtraData;
            p->FUN_0066b0d0(arg);
        }
    }
}

template <class T> inline NiPointer<T>::operator T*() const
{
    return m_pObject;
}

template <class T> inline T* NiPointer<T>::operator->() const
{
    return m_pObject;
}

// The original entry point returns a byte rather than the shared bool signature.
// @fnv 0x00a571e0
unsigned char __fastcall IsExtraDataEquivalent(NiExtraDataController* self, int,
                                               NiExtraDataController* other)
{
    if (!((const NiSingleInterpController*)self)->NiSingleInterpController::IsEqual(other))
        return false;
    if ((self->m_pExtraData && !other->m_pExtraData) ||
        (!self->m_pExtraData && other->m_pExtraData))
        return false;
    if (self->m_pExtraData && other->m_pExtraData &&
        !((const NiObject*)self->m_pExtraData.operator->())->IsEqual(other->m_pExtraData))
        return false;
    return other->m_kDataName.m_kHandle == self->m_kDataName.m_kHandle;
}

struct TypeRecord;

struct TypeRecord
{
    void* vtbl;
    TypeRecord* next;
};

void* __fastcall GetFilename_00a62660(void* item);

extern char g_011f4304;
extern unsigned int g_0109b220;

static __forceinline bool HasTargetType(NiObjectNET* arg)
{
    if (arg)
    {
        const TypeRecord* node = reinterpret_cast<const TypeRecord*>(arg->GetRTTI());
        while (node)
        {
            if ((char*)node == &g_011f4304)
                return true;
            node = node->next;
        }
    }
    return false;
}
// @fnv 0x00a57380
bool __fastcall HasMatchingExtraData(NiExtraDataController* self, int, NiObjectNET* pCandidate)
{
    if (!HasTargetType(pCandidate))
        return false;
    if ((unsigned int)self->m_kDataName.m_kHandle == g_0109b220)
        return false;
    for (unsigned int uiIndex = 0; uiIndex < pCandidate->m_usExtraDataSize; ++uiIndex)
    {
        void* pResolved = GetFilename_00a62660(pCandidate->m_ppkExtra[(unsigned short)uiIndex]);
        if (*(void**)pResolved == self->m_kDataName.m_kHandle)
            return true;
    }
    return false;
}
