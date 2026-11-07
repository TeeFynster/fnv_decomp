// gamebryo2.2/corelibs/nianimation/nibsplinecompfloatinterpolator.cpp: NiBSplineCompFloatInterpolator (10 functions)

#include "../../../../include/NiBSplineCompFloatInterpolator.h"
#include "../../../../include/NiBSplineFloatInterpolator.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/StrArr.h"

inline void NiBinaryStream::Read(float* values)
{
    unsigned int componentSize = 4;
    m_uiAbsoluteCurrentPos += m_pfnRead(this, values, 8, &componentSize, 1);
}

// @fnv 0x00a51660
void NiBSplineCompFloatInterpolator::LoadBinary(NiStream& stream)
{
    NiBSplineFloatInterpolator::LoadBinary(stream);
    stream.m_pkIstr->Read(m_afOffsetAndHalfRange);
}

extern int g_011f401c;

// @fnv 0x00a51520
// src: COMMUNITY 0x00a51520
int* __cdecl NiBSplineCompFloatInterpolator_GetRTTI()
{
    return &g_011f401c;
}

struct FUN_00a52d20_shell
{
    int* m_p;
    int __thiscall NiBoolInterpolator_GetKeys(int* b, int* c, char* d);
};

// @fnv 0x00a52d20
// src: COMMUNITY 0x00a52d20
int __thiscall FUN_00a52d20_shell::NiBoolInterpolator_GetKeys(int* b, int* c, char* d)
{
    int* p = *(int**)((char*)this + 0x10);
    if (p)
    {
        *b = *(int*)((char*)p + 8);
        *c = *(int*)((char*)p + 0x10);
        *d = *(char*)((char*)p + 0x14);
        return *(int*)((char*)p + 0xc);
    }
    *b = 0;
    *c = 0;
    *d = 0;
    return 0;
}

// The unused fastcall register lets these free functions implement the original
// member ABI. Call through a thiscall pointer so callers pass only ECX and stack arguments.
void __fastcall InitializeBSplineInterpolator(NiBSplineInterpolator* self, int, int a, int b);
extern int DAT_010997f4;

// @fnv 0x00a509f0
NiBSplineFloatInterpolator* __fastcall InitializeFloatInterpolator(NiBSplineFloatInterpolator* self, int,
                                                                  int a, int b, int c)
{
    reinterpret_cast<void (__thiscall*)(NiBSplineInterpolator*, int, int)>(InitializeBSplineInterpolator)(self, a, c);
    *(int*)self = (int)&DAT_010997f4;
    self->m_kFloatCPHandle = b;
    return self;
}

char* __cdecl _FUN_00a7d330(const char*);
void __fastcall SerializeToStrings(NiBSplineFloatInterpolator* self, int, StrArr* strings);

// @fnv 0x00a516e0
void __fastcall AppendString(NiBSplineCompFloatInterpolator* self, int, StrArr* pkStrings)
{
    reinterpret_cast<void (__thiscall*)(NiBSplineFloatInterpolator*, StrArr*)>(SerializeToStrings)(self, pkStrings);
    char* pszString = _FUN_00a7d330((const char*)g_011f401c);
    unsigned int uiSize = pkStrings->m_usSize;
    unsigned int uiMax = pkStrings->m_usMaxSize;
    if (uiSize >= uiMax)
    {
        pkStrings->SetSize(uiSize + pkStrings->m_usGrowBy);
    }
    pkStrings->SetAt(uiSize, pszString);
}

bool __fastcall IsInterpEqual(NiBSplineFloatInterpolator* self, int, NiBSplineFloatInterpolator* object);

// @fnv 0x00a514e0
bool __fastcall Equals(NiBSplineCompFloatInterpolator* self, int, NiBSplineCompFloatInterpolator* pkObject)
{
    NiBSplineCompFloatInterpolator* pkDest;
    unsigned int iIndex;
    if (!reinterpret_cast<bool (__thiscall*)(NiBSplineFloatInterpolator*, NiBSplineFloatInterpolator*)>(IsInterpEqual)(self, pkObject))
        return false;
    pkDest = pkObject;
    for (iIndex = 0; iIndex < 2; iIndex++)
    {
        if (self->m_afOffsetAndHalfRange[iIndex] != pkDest->m_afOffsetAndHalfRange[iIndex])
            return false;
    }
    return true;
}

void __fastcall SaveFloatInterpolator(NiBSplineFloatInterpolator* self, int, NiStream& stream);

// @fnv 0x00a516a0
void __fastcall WriteToStream(NiBSplineCompFloatInterpolator* self, int, NiStream& kStream)
{
    reinterpret_cast<void (__thiscall*)(NiBSplineFloatInterpolator*, NiStream&)>(SaveFloatInterpolator)(self, kStream);
    NiBinaryStream* __restrict pkOstr = kStream.m_pkOstr;
    unsigned int size = 4;
    pkOstr->m_uiAbsoluteCurrentPos += pkOstr->m_pfnWrite(pkOstr, self->m_afOffsetAndHalfRange, 8, &size, 1);
}

// @fnv 0x00a51530
bool __fastcall EvaluateAtTime(NiBSplineCompFloatInterpolator* self, int, float afTime, unsigned int unused, float* pfOut)
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
        self->m_spTransformData.m_pObject->CalculateSplineValue(t, &self->m_fFloatValue, 1,
            self->m_spSplineBasisData.m_pObject, handle, self->m_afOffsetAndHalfRange[0], self->m_afOffsetAndHalfRange[1]);
    }
    *pfOut = self->m_fFloatValue;
    self->m_fLastTime = afTime;
    return true;
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);
static const float kMaxCompScalar = 3.402823466e+38F;
extern int DAT_01099b2c;

inline void InitializeCompFloatInterpolator(NiBSplineCompFloatInterpolator* self)
{
    reinterpret_cast<NiBSplineFloatInterpolator* (__thiscall*)(NiBSplineFloatInterpolator*, int, int, int)>(InitializeFloatInterpolator)(self, 0, 0xffff, 0);
    *(int*)self = (int)&DAT_01099b2c;
    float* pfScalars = self->m_afOffsetAndHalfRange;
    pfScalars[0] = kMaxCompScalar;
    pfScalars[1] = kMaxCompScalar;
}

void __fastcall CopyFloatInterpolator(NiBSplineFloatInterpolator* self, int, NiBSplineFloatInterpolator* object, CloningProcess& cloning);

// @fnv 0x00a515c0
NiBSplineCompFloatInterpolator* __fastcall CloneCompFloatInterpolator(NiBSplineCompFloatInterpolator* self, int, CloningProcess& cloning)
{
    NiBSplineCompFloatInterpolator* p = (NiBSplineCompFloatInterpolator*)Object_DispatchCommandFour(0x2c);
    if (p)
    {
        InitializeCompFloatInterpolator(p);
    }
    else
    {
        p = 0;
    }
    reinterpret_cast<void (__thiscall*)(NiBSplineFloatInterpolator*, NiBSplineFloatInterpolator*, CloningProcess&)>(CopyFloatInterpolator)(self, p, cloning);
    p->m_afOffsetAndHalfRange[0] = self->m_afOffsetAndHalfRange[0];
    p->m_afOffsetAndHalfRange[1] = self->m_afOffsetAndHalfRange[1];
    return p;
}

// @fnv 0x00a51620
// src: EXE 0x00a51620
NiBSplineCompFloatInterpolator* NiBSplineCompFloatInterpolator_CreateObject()
{
    NiBSplineCompFloatInterpolator* p = (NiBSplineCompFloatInterpolator*)NiBSplineCompFloatInterpolator::operator new(0x2c);
    if (p)
    {
        InitializeCompFloatInterpolator(p);
        return p;
    }
    return 0;
}
