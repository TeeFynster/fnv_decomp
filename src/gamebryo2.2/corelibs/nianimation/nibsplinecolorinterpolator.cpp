
// src/gamebryo2.2/corelibs/nianimation/nibsplinecolorinterpolator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nibsplinecolorinterpolator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiBSplineColorInterpolator.h"
#include "../../../../include/NiStream.h"

// @fnv 0x00a51a20
// src: GAMEBRYO_LIB 0x00a51a20
unsigned int NiBSplineColorInterpolator::GetControlHandle(unsigned short usChannel)
{
    if (usChannel)
        return 0xffff;
    return m_kColorACPHandle;
}

extern char const* const g_011f4024_arg1;

// @fnv 0x00a51aa0
// src: COMMUNITY 0x00a51aa0
char const* const* __cdecl NiBSplineColorInterpolator_GetRTTI()
{
    return &g_011f4024_arg1;
}

// Declarations for base operations absent from the shared spline header.
struct SplineBaseOperations
{
    __declspec(nothrow) SplineBaseOperations(int, int);
    void CopyTo(NiBSplineInterpolator*, CloningProcess&);
    void SaveBinary(NiStream*);
    void AppendStrings(struct StringArray*);
    bool IsEqual(NiBSplineInterpolator*);
};
extern int DAT_01099d3c;
// @fnv 0x00a51c60
// src: EXE 0x00a51c60
void* NiBSplineColorInterpolator_CreateObject()
{
    NiBSplineColorInterpolator* p = (NiBSplineColorInterpolator*)BSFadeNode::operator new(52);
    if (p)
    {
        new (p) SplineBaseOperations(0, 0);
        *(volatile int*)p = (int)&DAT_01099d3c;
        ((volatile NiColorA*)&p->m_kDiffuseColor)->a =
            ((volatile NiColorA*)&p->m_kDiffuseColor)->b =
            ((volatile NiColorA*)&p->m_kDiffuseColor)->g =
            ((volatile NiColorA*)&p->m_kDiffuseColor)->r = 0.0f;
        *(volatile unsigned int*)&p->m_kColorACPHandle = 0xffff;
        return p;
    }
    return 0;
}

// @fnv 0x00a50a40
int __fastcall GetChannelResult(NiBSplineColorInterpolator* self, void* unused, unsigned short usChannel)
{
    return 0 == usChannel ? 3 : 0;
}

__forceinline void NiBSplineColorInterpolator::CopyTo(NiBSplineColorInterpolator* pkDest, CloningProcess& kCloning)
{
    ((SplineBaseOperations*)this)->CopyTo(pkDest, kCloning);
    pkDest->m_kDiffuseColor = m_kDiffuseColor;
    pkDest->m_kColorACPHandle = m_kColorACPHandle;
}

// @fnv 0x00a51bf0
// src: XBOX_PDB 0x00a51bf0
NiBSplineInterpolator* __fastcall NiBSplineColorInterpolator_CreateClone(NiBSplineColorInterpolator* self, void* unused, CloningProcess& kCloning)
{
    NiBSplineColorInterpolator* pkClone = (NiBSplineColorInterpolator*)NiObject::operator new(sizeof(NiBSplineColorInterpolator));
    if (pkClone)
    {
        new (pkClone) SplineBaseOperations(0, 0);
        *(volatile int*)pkClone = (int)&DAT_01099d3c;
        ((volatile NiColorA*)&pkClone->m_kDiffuseColor)->r = 0.0f;
        ((volatile NiColorA*)&pkClone->m_kDiffuseColor)->g = 0.0f;
        ((volatile NiColorA*)&pkClone->m_kDiffuseColor)->b = 0.0f;
        ((volatile NiColorA*)&pkClone->m_kDiffuseColor)->a = 0.0f;
        *(volatile unsigned int*)&pkClone->m_kColorACPHandle = 0xffff;
    }
    else
        pkClone = 0;
    self->CopyTo(pkClone, kCloning);
    return pkClone;
}

typedef int(__cdecl* FNVStreamWrite)(void*, const void*, unsigned int, unsigned int*, int);
struct FNVStreamBuffer
{
    int unk00;
    unsigned int position;
    int unk08;
    FNVStreamWrite write;
};

// @fnv 0x00a51ca0
// src: XBOX_PDB 0x00a51ca0
void __fastcall NiBSplineColorInterpolator_SaveBinary(NiBSplineColorInterpolator* self, void* unused, NiStream* stream)
{
    ((SplineBaseOperations*)self)->SaveBinary(stream);
    self->m_kDiffuseColor.SaveBinary(*stream);
    FNVStreamBuffer* writer = reinterpret_cast<FNVStreamBuffer*&>(stream->m_pkOstr);
    {
        int stream = 4;
        writer->position += writer->write(writer, (const void*)&self->m_kColorACPHandle, 4, (unsigned int*)&stream, 1);
    }
}

extern char const* const g_011f4024_arg1;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(char const*);
char* __cdecl NiGetViewerString_00a7d510(char const*, unsigned int);
template <class T> struct FnvStringMallocInterface
{
};
template <class T, class I> struct FnvStringPrimitiveArray
{
    void* unk00;
    int unk04;
    unsigned short capacity;
    unsigned short size;
    unsigned short unk0c;
    unsigned short growth;
    void SetSize(unsigned int);
    void SetAt(unsigned int, T&);
};
struct StringArray : FnvStringPrimitiveArray<char*, FnvStringMallocInterface<char*> > {};
// @fnv 0x00a51d80
void __fastcall AppendColorACPHandleStrings(NiBSplineColorInterpolator* self, void* unused, StringArray* array)
{
    ((SplineBaseOperations*)self)->AppendStrings(array);
    char* value = NiViewerStrings_NiGetViewerString_Title(g_011f4024_arg1);
    unsigned int index = array->size;
    if (index >= array->capacity)
        array->SetSize(index + array->growth);
    array->SetAt(index, value);
    value = NiGetViewerString_00a7d510("m_kColorACPHandle", self->m_kColorACPHandle);
    index = array->size;
    if (index >= array->capacity)
        array->SetSize(index + array->growth);
    array->SetAt(index, value);
}

// Returns true when the channel is zero and its control-point count is zero.
// @fnv 0x00a50610
// src: GUESS 0x00a50610 (confidence: medium)
bool __fastcall NiBSplineColorInterpolator_IsChannelZeroAndEmpty(NiBSplineColorInterpolator* self, void* unused, unsigned short flag)
{
    if (0 == flag)
    {
        unsigned int r = self->vf56(0);
        return !(0u < r);
    }
    return false;
}

extern "C++" unsigned char __stdcall LoadNiBSplineInterpolator(int value);

// @fnv 0x00a50b10
// src: XBOX_PDB 0x00a50b10
unsigned char __stdcall NiBSplineColorInterpolator_RegisterStreamables(int value)
{
    return LoadNiBSplineInterpolator(value) != 0;
}

// @fnv 0x00a51a40
void __fastcall SetValueIfFlagClear(NiBSplineColorInterpolator* self, void* unused, unsigned int value, unsigned short flag)
{
    if (flag == 0)
    {
        self->m_kColorACPHandle = value;
    }
}

// The colour interpolator of a B-spline.
//
// The object keeps the two key times of the segment it interpolates, the
// curve that produces the channel values and the colour that was computed
// for the last time stamp.  Evaluating the same time stamp twice is a
// no-op: the colour that is already stored is handed back unchanged.

struct SplineCurveOperations
{
    void Evaluate(float, float*, int, NiBSplineBasisData*, unsigned int);
};

// @fnv 0x00a51b10
bool __fastcall EvaluateColorAtTime(NiBSplineColorInterpolator* self, void* unused, float fTime, float fUnused, NiColorA* pColorOut)
{
    // The colour is already the one of this time stamp.
    if (self->m_fLastTime == fTime)
    {
        *pColorOut = self->m_kDiffuseColor;
        return true;
    }

    // Only a segment that has a knot can be interpolated.
    if (self->m_kColorACPHandle != 0xffff)
    {
        float fNormalizedTime = (fTime - self->m_fStartTime) / (self->m_fEndTime - self->m_fStartTime);
        float afCurveOut[4];
        ((SplineCurveOperations*)self->m_spTransformData.m_pObject)->Evaluate(fNormalizedTime, afCurveOut, 4, self->m_spSplineBasisData.m_pObject, self->m_kColorACPHandle);
        float colorResult[4];
        colorResult[0] = afCurveOut[0];
        colorResult[1] = afCurveOut[1];
        colorResult[2] = afCurveOut[2];
        colorResult[3] = afCurveOut[3];
        self->m_kDiffuseColor = *reinterpret_cast<const NiColorA*>(colorResult);
    }

    *pColorOut = self->m_kDiffuseColor;
    self->m_fLastTime = fTime;
    return true;
}

// @fnv 0x00a51cf0
// src: GAMEBRYO_LIB 0x00a51cf0
bool __fastcall NiBSplineColorInterpolator_IsEqual(NiBSplineColorInterpolator* self, void* unused, NiBSplineColorInterpolator* other)
{
    if (!((SplineBaseOperations*)self)->IsEqual(other))
    {
        return false;
    }
    if (self->m_kDiffuseColor.operator!=(other->m_kDiffuseColor))
    {
        return false;
    }
    bool bEqual = other->m_kColorACPHandle == self->m_kColorACPHandle;
    return bEqual;
}

// @fnv 0x00a51a00
// src: XBOX_PDB 0x00a51a00
unsigned int __stdcall NiBSplineColorInterpolator_GetDimension(unsigned short usValue)
{
    return (0 == usValue) ? 4 : 0;
}

struct A51D30Input
{
    int unk00;
    int bytesRead;
    int(__cdecl* read)(void* input, void* destination, int size, int* componentSize, int componentCount);
};

// Loads the base spline data and colour, then reads the colour control-point handle.
// @fnv 0x00a51d30
// src: XBOX_PDB 0x00a51d30
void __fastcall NiBSplineColorInterpolator_LoadBinary(NiBSplineColorInterpolator* self, void* unused, NiStream* stream)
{
    self->NiBSplineInterpolator::LoadBinary(*stream);
    self->m_kDiffuseColor.LoadBinary(*stream);
    A51D30Input* input = reinterpret_cast<A51D30Input*&>(stream->m_pkIstr);
    {
        int componentSize = 4;
        input->bytesRead += input->read(input, &self->m_kColorACPHandle, 4, &componentSize, 1);
    }
}
