// gamebryo2.2/corelibs/nianimation/nibsplinefloatinterpolator.cpp: NiBSplineFloatInterpolator (12 functions)

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/StrArr.h"
#include "../../../../include/NiBSplineFloatInterpolator.h"
#include "../../../../include/NiBSplineInterpolator.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiStream.h"

// Adapt declarations missing from the shared headers to the original member-call ABI.
// A single-inheritance member pointer holds the function address on the target compiler.
// ThisCallStub has no bases, so its member pointers are one code address on every compiler (NiRefObject's
// NiMemObject base makes Ni class member pointers carry a this-adjustment).
struct ThisCallStub
{
};
template <class Member, class Function> inline Member MemberCall(Function function)
{
    union
    {
        Function function;
        Member member;
    } call;
    call.function = function;
    return call.member;
}

template <class T> void NiBinaryStream::Read(T& value)
{
    unsigned int size = sizeof(T);
    m_uiAbsoluteCurrentPos += m_pfnRead(this, &value, sizeof(T), &size, 1);
}
// Calls the base NiBSplineInterpolator::LoadBinary, then reads m_fFloatValue and m_kFloatCPHandle from the stream input.
// @fnv 0x00a50cd0
void NiBSplineFloatInterpolator::LoadBinary(NiStream& stream)
{
    NiBSplineInterpolator::LoadBinary(stream);
    stream.m_pkIstr->Read(m_fFloatValue);
    stream.m_pkIstr->Read(m_kFloatCPHandle);
}

// @fnv 0x00a50a20
// src: XBOX_PDB 0x00a50a20
int __stdcall NiBSplineFloatInterpolator_GetDimension(unsigned short v)
{
    unsigned short z = 0;
    return z == v;
}

// @fnv 0x00a50a60
unsigned int __fastcall GetHandleByIndex(NiBSplineFloatInterpolator* self, int, unsigned short idx)
{
    unsigned int r = 0xffff;
    if (idx == 0)
        r = self->m_kFloatCPHandle;
    return r;
}

// @fnv 0x00a50a80
void __fastcall SetHandleIfFirstIndex(NiBSplineFloatInterpolator* self, int, unsigned int h, unsigned short idx)
{
    if (idx == 0)
        self->m_kFloatCPHandle = h;
}

bool __fastcall IsBSplineInterpolatorEqual(NiBSplineInterpolator* self, int, NiObject* other);

// @fnv 0x00a50b30
bool __fastcall IsInterpEqual(NiBSplineFloatInterpolator* self, int, NiBSplineFloatInterpolator* other)
{
    if (!(((ThisCallStub*)self)->*MemberCall<bool (ThisCallStub::*)(NiObject*)>(IsBSplineInterpolatorEqual))(other))
        return false;
    if (self->m_fFloatValue != other->m_fFloatValue)
        return false;
    return other->m_kFloatCPHandle == self->m_kFloatCPHandle ? true : false;
}

struct GlobalObjX
{
    int x;
};
extern GlobalObjX g_011f401c_arg1;
// @fnv 0x00a50b70
// src: COMMUNITY 0x00a50b70
GlobalObjX* NiBSplineFloatInterpolator_GetRTTI()
{
    return &g_011f401c_arg1;
}

__declspec(noinline) void __fastcall DestroyBSplineInterpolator(NiBSplineInterpolator* self, int);
void __cdecl __Dummy_00b6fef0(void*, unsigned int);
// @fnv 0x00a50b80
void* __fastcall FUN_00a50b80(void* self, int, unsigned int flags)
{
    (((ThisCallStub*)static_cast<NiBSplineInterpolator*>(self))->*MemberCall<void (ThisCallStub::*)()>(DestroyBSplineInterpolator))();
    if (flags & 1)
        __Dummy_00b6fef0(self, 0x24);
    return self;
}

void __fastcall InitializeBSplineInterpolator(NiBSplineInterpolator* self, int, int, int);
void __fastcall CopyBSplineInterpolator(NiBSplineInterpolator* self, int, NiBSplineInterpolator* object,
                                       CloningProcess& cloning);
extern int DAT_010997f4;
// Allocates a new object, initialises it, copies the float value and handle from this, and returns the clone.
// @fnv 0x00a50c20
NiBSplineFloatInterpolator* __fastcall CloneFloatInterpolator(NiBSplineFloatInterpolator* self, int, CloningProcess& kCloning)
{
    NiBSplineFloatInterpolator* pkObject = (NiBSplineFloatInterpolator*)BSFadeNode::operator new(0x24);
    if (pkObject)
    {
        (((ThisCallStub*)pkObject)->*MemberCall<void (ThisCallStub::*)(int, int)>(InitializeBSplineInterpolator))(0, 0);
        *(void**)pkObject = (void*)&DAT_010997f4;
        pkObject->m_kFloatCPHandle = 0xffff;
    }
    else
    {
        pkObject = 0;
    }
    (((ThisCallStub*)self)->*MemberCall<void (ThisCallStub::*)(NiBSplineInterpolator*, CloningProcess&)>(CopyBSplineInterpolator))(pkObject, kCloning);
    pkObject->m_fFloatValue = self->m_fFloatValue;
    pkObject->m_kFloatCPHandle = self->m_kFloatCPHandle;
    return pkObject;
}

void __fastcall GetBSplineInterpolatorStrings(NiBSplineInterpolator* self, int, StrArr* strings);

char* __cdecl _FUN_00a7d330(char const* value);
char* __cdecl NiGetViewerString_00a7d550(char const* name, float value);
char* __cdecl NiGetViewerString_00a7d510(char const* name, char const* value);

// @fnv 0x00a50d30
void __fastcall SerializeToStrings(NiBSplineFloatInterpolator* self, int, StrArr* strings)
{
    (((ThisCallStub*)self)->*MemberCall<void (ThisCallStub::*)(StrArr*)>(GetBSplineInterpolatorStrings))(strings);

    char* value = _FUN_00a7d330(reinterpret_cast<char const*>(g_011f401c_arg1.x));

    unsigned int index = strings->m_usSize;
    if (index >= strings->m_usMaxSize)
        strings->SetSize(index + strings->m_usGrowBy);

    strings->SetAt(index, value);

    value = NiGetViewerString_00a7d550("m_fFloatValue", self->m_fFloatValue);

    index = strings->m_usSize;
    if (index >= strings->m_usMaxSize)
        strings->SetSize(index + strings->m_usGrowBy);

    strings->SetAt(index, value);

    value = NiGetViewerString_00a7d510("m_kFloatCPHandle", reinterpret_cast<char const*>(self->m_kFloatCPHandle));

    index = strings->m_usSize;
    if (index >= strings->m_usMaxSize)
        strings->SetSize(index + strings->m_usGrowBy);

    strings->SetAt(index, value);
}

void __fastcall EvaluateSpline(NiBSplineData* self, int, float t, float* out, int one,
                               NiBSplineBasisData* basis, unsigned int handle);

// @fnv 0x00a50ba0
bool __fastcall EvaluateAt(NiBSplineFloatInterpolator* self, int, float afTime, unsigned int unused, float* pfOut)
{
    float t;
    if (self->m_fLastTime == afTime)
    {
        *pfOut = self->m_fFloatValue;
        return true;
    }
    unsigned int handle = self->m_kFloatCPHandle;
    if (handle != 0xffff)
    {
        t = (afTime - self->m_fStartTime) / (self->m_fEndTime - self->m_fStartTime);
        (((ThisCallStub*)self->m_spTransformData.m_pObject)->*MemberCall<void (ThisCallStub::*)(float, float*, int, NiBSplineBasisData*, unsigned int)>(EvaluateSpline))(
            t, &self->m_fFloatValue, 1, self->m_spSplineBasisData.m_pObject, handle);
    }
    *pfOut = self->m_fFloatValue;
    self->m_fLastTime = afTime;
    return true;
}

template <class T> inline void WriteValue(NiBinaryStream* stream, T* value)
{
    unsigned int size = sizeof(T);
    stream->m_uiAbsoluteCurrentPos += stream->m_pfnWrite(stream, value, sizeof(T), &size, 1);
}

void __fastcall SaveBSplineInterpolator(NiBSplineInterpolator* self, int, NiStream& stream);

// @fnv 0x00a50c70
void __fastcall SaveFloatInterpolator(NiBSplineFloatInterpolator* self, int, NiStream& stream)
{
    (((ThisCallStub*)self)->*MemberCall<void (ThisCallStub::*)(NiStream&)>(SaveBSplineInterpolator))(stream);
    WriteValue(stream.m_pkOstr, &self->m_fFloatValue);
    WriteValue(stream.m_pkOstr, &self->m_kFloatCPHandle);
}

#include <windows.h>

extern int DAT_0109ae8c;
void __fastcall DestroyInterpolator(NiInterpolator* self, int);

// @fnv 0x00a57f80
__declspec(noinline) void __fastcall DestroyBSplineInterpolator(NiBSplineInterpolator* self, int)
{
    *(void* volatile*)self = (void*)&DAT_0109ae8c;
    NiBSplineBasisData* second = *(NiBSplineBasisData* volatile*)&self->m_spSplineBasisData.m_pObject;
    if (second != 0)
    {
        if (InterlockedDecrement(reinterpret_cast<long*>(&second->m_uiRefCount)) == 0)
        {
            second->DeleteThis();
        }
    }
    NiBSplineData* first = self->m_spTransformData.m_pObject;
    if (first != 0)
    {
        if (InterlockedDecrement(reinterpret_cast<long*>(&first->m_uiRefCount)) == 0)
        {
            first->DeleteThis();
        }
    }
    (((ThisCallStub*)self)->*MemberCall<void (ThisCallStub::*)()>(DestroyInterpolator))();
}
