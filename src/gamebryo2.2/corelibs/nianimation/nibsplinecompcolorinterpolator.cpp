#include "../../../../include/NiObject.h"
#include "../../../../include/NiColorA.h"
#include "../../../../include/NiBSplineCompColorInterpolator.h"
#include "../../../../include/NiBSplineColorInterpolator.h"
#include "../../../../include/NiBSplineData.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiMemObject.h"

// src/gamebryo2.2/corelibs/nianimation/nibsplinecompcolorinterpolator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nibsplinecompcolorinterpolator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

char __stdcall NiBSplineColorInterpolator_RegisterStreamables(char);

// @fnv 0x00a51210
// src: XBOX_PDB 0x00a51210
char __stdcall NiBSplineCompColorInterpolator_RegisterStreamables(char acValue)
{
    char r = NiBSplineColorInterpolator_RegisterStreamables(acValue);
    return r != 0;
}

extern "C" void* g_011f4024;

// @fnv 0x00a51770
// src: COMMUNITY 0x00a51770
void* __cdecl NiBSplineCompColorInterpolator_GetRTTI()
{
    return &g_011f4024;
}

struct FUN_00a50110_obj
{
    void FUN_00a57fd0(FUN_00a50110_obj*, CloningProcess&);
};

// @fnv 0x00a51a60
__declspec(noinline) void NiBSplineColorInterpolator::CopyTo(NiBSplineColorInterpolator* apTarget, CloningProcess& proc)
{
    ((FUN_00a50110_obj*)this)->FUN_00a57fd0((FUN_00a50110_obj*)apTarget, proc);
    *(int*)&apTarget->m_kDiffuseColor.r = *(int*)&m_kDiffuseColor.r;
    *(int*)&apTarget->m_kDiffuseColor.g = *(int*)&m_kDiffuseColor.g;
    *(int*)&apTarget->m_kDiffuseColor.b = *(int*)&m_kDiffuseColor.b;
    *(int*)&apTarget->m_kDiffuseColor.a = *(int*)&m_kDiffuseColor.a;
    *(int*)&apTarget->m_kColorACPHandle = *(int*)&m_kColorACPHandle;
}

void __fastcall FUN_00a57f80(void*);
void __cdecl _delete(void*, unsigned int);
// Calls FUN_00a57f80 on this, frees this with _delete when bit 0 of a is set, and returns this.
// @fnv 0x00a51780
void* NiBSplineCompColorInterpolator::Destroy(unsigned int auiFlags)
{
    FUN_00a57f80(this);
    if (auiFlags & 1)
        _delete(this, 0x3c);
    return this;
}

inline void NiBinaryStream::Write(void* buffer, unsigned int bytes)
{
    unsigned int size = 4;
    *(unsigned int*)((char*)this + 4) +=
        (*(WriteFunction*)((char*)this + 0xc))(this, buffer, bytes, &size, 1);
}

struct BaseCall
{
    void NiBSplineColorInterpolator_SaveBinary(NiStream&);
};
// Calls the base save routine, then writes the two interpolator values (8 bytes) to the stream.
// @fnv 0x00a51970
void NiBSplineCompColorInterpolator::SaveToStream(NiStream& aStream)
{
    ((BaseCall*)this)->NiBSplineColorInterpolator_SaveBinary(aStream);
    NiBinaryStream* output = *(NiBinaryStream**)((char*)&aStream + 0x250);
    output->Write(m_iFourthElementInteger, 8);
}

struct FUN_00a51cf0_obj
{
    bool NiBSplineColorInterpolator_IsEqual(NiObject*);
};
// @fnv 0x00a51730
bool NiBSplineCompColorInterpolator::IsEqual(NiObject* pkObject) const
{
    NiBSplineCompColorInterpolator* pkDest;
    unsigned int uiIndex;
    if (!((FUN_00a51cf0_obj*)this)->NiBSplineColorInterpolator_IsEqual(pkObject))
        return false;
    pkDest = (NiBSplineCompColorInterpolator*)pkObject;
    for (uiIndex = 0; uiIndex < 2; uiIndex++)
    {
        if (m_afOffsetAndHalfRange[uiIndex] != pkDest->m_afOffsetAndHalfRange[uiIndex])
            return false;
    }
    return true;
}

struct BaseHolder
{
    void NiBSplineColorInterpolator_LoadBinary(NiStream&);
};
// Calls the base holder's stream loader, then reads 8 bytes into m_data through the stream's binary reader.
// @fnv 0x00a51930
void NiBSplineCompColorInterpolator::LoadFromStream(NiStream& stream)
{
    ((BaseHolder*)this)->NiBSplineColorInterpolator_LoadBinary(stream);
    NiBinaryStream* __restrict input = *(NiBinaryStream**)((char*)&stream + 0x24c);
    unsigned int size = 4;
    *(unsigned int*)((char*)input + 4) +=
        (*(NiBinaryStream::ReadFunction*)((char*)input + 8))(input, m_data, 8, &size, 1);
}

char* _FUN_00a7d330(const char*);
#include "../../../../include/NiTPrimitiveArray.h"
// Gamebryo NiTArray.inl: the original inlines Add (SetAtGrow) and calls SetSize / SetAt out of line
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::Add(const T& element)
{
    unsigned int uiIndex = m_usSize;
    if (uiIndex >= m_usMaxSize)
        SetSize(uiIndex + m_usGrowBy);
    SetAt(uiIndex, element);
    return uiIndex;
}
struct BaseDummy
{
    void AppendColorACPHandleStrings(NiTPrimitiveArray<char*>*);
};
// @fnv 0x00a519b0
// src: XBOX_PDB 0x00a519b0
void NiBSplineCompColorInterpolator::GetViewerStrings_00a519b0(NiTPrimitiveArray<char*>* pkStrings)
{
    ((BaseDummy*)this)->AppendColorACPHandleStrings(pkStrings);
    char* pcString = _FUN_00a7d330((const char*)g_011f4024);
    pkStrings->Add(pcString);
}

static const float DAT_01099c2c = 3.402823466e+38f;
struct ColorInterpolatorBaseConstruction
{
    void Construct(int, unsigned int, int) throw();
};
extern int DAT_01099c34;
// Allocates and returns a compressed color interpolator with default scalar values.
// @fnv 0x00a518f0
void* CreateSplineCompColorInterpolator()
{
    NiBSplineCompColorInterpolator* result = (NiBSplineCompColorInterpolator*)NiMemObject::operator new(0x3c);
    if (result)
    {
        ((ColorInterpolatorBaseConstruction*)result)->Construct(0, 0xffff, 0);
        *(void**)result = &DAT_01099c34;
        for (int i = 0; i < 2; i++)
            result->m_afScalars[i] = DAT_01099c2c;
        return result;
    }
    return 0;
}

// The shared interpolator headers still declare the legacy color type. Keep this evaluator
// free until they expose NiColorA; the unused EDX parameter preserves the member-call ABI.
// The casts bridge the shared cached color to the identical NiColorA layout.
// Samples the spline color at the normalized time when the index is valid, caches it, and writes the cached color to output.
// @fnv 0x00a517a0
char __fastcall EvaluateColor(NiBSplineCompColorInterpolator* self, void*, float time, void*, NiColorA* output)
{
    if (self->m_fLastTime == time)
    {
        *output = reinterpret_cast<const NiColorA&>(self->m_kDiffuseColor);
        return 1;
    }
    if (self->m_kColorACPHandle != 0xffff)
    {
        float values[4];
        float sampledColor[4];
        self->m_spTransformData.m_pObject->CalculateSplineValue((time - self->m_fStartTime) / (self->m_fEndTime - self->m_fStartTime), values, 4,
                                     self->m_spSplineBasisData.m_pObject, self->m_kColorACPHandle, self->bias, self->multiplier);
        sampledColor[0] = values[0];
        sampledColor[1] = values[1];
        sampledColor[2] = values[2];
        sampledColor[3] = values[3];
        reinterpret_cast<NiColorA&>(self->m_kDiffuseColor) = *(NiColorA*)sampledColor;
    }
    *output = reinterpret_cast<const NiColorA&>(self->m_kDiffuseColor);
    self->m_fLastTime = time;
    return 1;
}

extern void* __cdecl Object_DispatchCommandFour(unsigned int);
// Allocates and initializes a clone, then copies the base and compressed scalar values.
// @fnv 0x00a51890
// src: XBOX_PDB 0x00a51890
NiBSplineCompColorInterpolator* NiBSplineCompColorInterpolator::CreateClone_00a51890(CloningProcess& process)
{
    NiBSplineCompColorInterpolator* __restrict result = (NiBSplineCompColorInterpolator*)Object_DispatchCommandFour(0x3c);
    if (result)
    {
        ((ColorInterpolatorBaseConstruction*)result)->Construct(0, 0xffff, 0);
        *(void* volatile*)result = &DAT_01099c34;
        result->m_fStartValue = DAT_01099c2c;
        result->m_fEndValue = DAT_01099c2c;
    }
    else
        result = 0;
    ((NiBSplineColorInterpolator*)this)->CopyTo((NiBSplineColorInterpolator*)result, process);
    result->m_fStartValue = m_fStartValue;
    result->m_fEndValue = m_fEndValue;
    return result;
}
