// gamebryo2.2/corelibs/nianimation/nibsplinecomppoint3interpolator.cpp: NiBSplineCompPoint3Interpolator (8 functions)

#include "../../../../include/NiBSplineCompPoint3Interpolator.h"
#include "../../../../include/NiBSplinePoint3Interpolator.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/StrArr.h"
#include "../../../../include/NiPoint3.h"
#include <string.h>

// Local call adapters for base routines not declared by the shared interpolator header.
// These carry no object storage; all fields come from the shared classes.
struct BSplinePoint3Operations
{
    void Construct(int a, unsigned int handle, int c) throw();
    void CopyUnknownFields(NiBSplineCompPoint3Interpolator* dest, CloningProcess& cloning);
    bool IsEqual(NiObject* object);
    void SaveBinary(NiStream& stream);
};

__forceinline unsigned int NiBinaryStream::Read(void* buffer, unsigned int size)
{
    unsigned int componentSize = 4;
    unsigned int bytes = m_pfnRead(this, buffer, size, &componentSize, 1);
    m_uiAbsoluteCurrentPos += bytes;
    return bytes;
}

inline void NiBinaryStream::Write(void* buffer, unsigned int bytes)
{
    unsigned int componentSize = 4;
    m_uiAbsoluteCurrentPos += m_pfnWrite(this, buffer, bytes, &componentSize, 1);
}

// Calls the base LoadBinary, then reads 8 bytes from the stream's input into the interpolator's data.
// @fnv 0x00a51400
void NiBSplineCompPoint3Interpolator::LoadBinary(NiStream& stream)
{
    NiBSplinePoint3Interpolator::LoadBinary(stream);
    NiBinaryStream* input = stream.m_pkIstr;
    input->Read(&m_fSequenceOffset, 8);
}

extern "C" void* g_011f4014;

// @fnv 0x00a51270
// src: COMMUNITY 0x00a51270
void* __cdecl NiBSplineCompPoint3Interpolator_GetRTTI()
{
    return &g_011f4014;
}

// @fnv 0x00a51230
bool __fastcall NiBSplineCompPoint3Interpolator_IsEqual(NiBSplineCompPoint3Interpolator* self, void*, NiObject* pkObject)
{
    NiBSplineCompPoint3Interpolator* pkDest;
    unsigned int iIndex;
    if (!reinterpret_cast<BSplinePoint3Operations*>(self)->IsEqual(pkObject))
        return false;
    pkDest = (NiBSplineCompPoint3Interpolator*)pkObject;
    for (iIndex = 0; iIndex < 2; iIndex++)
    {
        if ((&self->m_fSequenceOffset)[iIndex] != (&pkDest->m_fSequenceOffset)[iIndex])
            return false;
    }
    return true;
}

void __stdcall FUN_00a50960(StrArr*);
char* __cdecl _FUN_00a7d330(const char*);
// Grows the string array if it is full, then appends the string returned by _FUN_00a7d330(g_011f4014) at the current size index.
// @fnv 0x00a51480
// src: XBOX_PDB 0x00a51480
void __stdcall NiBSplineCompPoint3Interpolator_GetViewerStrings(StrArr* pkStrings)
{
    FUN_00a50960(pkStrings);
    char* pszStr = _FUN_00a7d330((const char*)g_011f4014);
    unsigned int uiSize = pkStrings->m_usSize;
    unsigned int uiMax = pkStrings->m_usMaxSize;
    if (uiSize >= uiMax)
        pkStrings->SetSize(uiSize + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiSize, pszStr);
}

inline NiPoint3::NiPoint3(float inX, float inY, float inZ) : x(inX), y(inY), z(inZ)
{}
// @fnv 0x00a51280
bool __fastcall NiBSplineCompPoint3Interpolator_EvaluateSplineAtTime(NiBSplineCompPoint3Interpolator* self, void*, float time, unsigned int unused, NiPoint3* out)
{
    NiPoint3& lastValue = *reinterpret_cast<NiPoint3*>(&self->m_kPoint3Value);
    if (self->m_fLastTime == time)
    {
        memcpy(out, &lastValue, sizeof(NiPoint3));
        return true;
    }
    if (self->m_kPoint3CPHandle != 0xffff)
    {
        float samples[4];
        float normalized = (time - self->m_fStartTime) / (self->m_fEndTime - self->m_fStartTime);
        self->m_spTransformData.m_pObject->CalculateSplineValue(
            normalized, samples, 3, self->m_spSplineBasisData.m_pObject,
            self->m_kPoint3CPHandle, self->m_fSequenceOffset, self->m_fDecodeScale);
        NiPoint3 updatedValue(samples[0], samples[1], samples[2]);
        memcpy(&lastValue, &updatedValue, sizeof(NiPoint3));
    }
    memcpy(out, &lastValue, sizeof(NiPoint3));
    self->m_fLastTime = time;
    return true;
}

// Saves the base point3 interpolator and the two compression parameters.
// @fnv 0x00a51440
void __fastcall NiBSplineCompPoint3Interpolator_SaveBinary(NiBSplineCompPoint3Interpolator* self, void*, NiStream& stream)
{
    reinterpret_cast<BSplinePoint3Operations*>(self)->SaveBinary(stream);
    NiBinaryStream* pBinaryStream = stream.m_pkOstr;
    pBinaryStream->Write(&self->m_fSequenceOffset, 8);
}

const float DAT_01099a1c = 3.402823466e+38f;
extern const void* NiBSplineCompPoint3Interpolator_vtable[];

// Allocates a compressed point3 interpolator and copies its base and compression fields.
// @fnv 0x00a51360
NiBSplineCompPoint3Interpolator* __fastcall NiBSplineCompPoint3Interpolator_Clone(NiBSplineCompPoint3Interpolator* self, void*, CloningProcess& cloning)
{
    NiBSplineCompPoint3Interpolator* pNew =
        (NiBSplineCompPoint3Interpolator*)BSFadeNode::operator new(sizeof(NiBSplineCompPoint3Interpolator));
    if (pNew)
    {
        reinterpret_cast<BSplinePoint3Operations*>(pNew)->Construct(0, 0xffff, 0);
        *reinterpret_cast<const void***>(pNew) = NiBSplineCompPoint3Interpolator_vtable;
    }
    else
    {
        pNew = 0;
    }
    if (pNew)
    {
        pNew->m_fDecodeScale = pNew->m_fSequenceOffset = DAT_01099a1c;
    }
    else
    {
        pNew = 0;
    }
    reinterpret_cast<BSplinePoint3Operations*>(self)->CopyUnknownFields(pNew, cloning);
    pNew->m_fSequenceOffset = self->m_fSequenceOffset;
    pNew->m_fDecodeScale = self->m_fDecodeScale;
    return pNew;
}

extern void* Object_DispatchCommandFour(unsigned int bytes) throw();

// Allocates and initializes a compressed point3 interpolator.
// @fnv 0x00a513c0
void* __cdecl NiBSplineCompPoint3Interpolator_Create()
{
    NiBSplineCompPoint3Interpolator* result =
        (NiBSplineCompPoint3Interpolator*)Object_DispatchCommandFour(sizeof(NiBSplineCompPoint3Interpolator));
    if (result)
    {
        reinterpret_cast<BSplinePoint3Operations*>(result)->Construct(0, 0xffff, 0);
        *reinterpret_cast<const void***>(result) = NiBSplineCompPoint3Interpolator_vtable;
    }
    else
    {
        result = 0;
    }
    if (result)
    {
        result->m_fDecodeScale = result->m_fSequenceOffset = 3.4028234663852886e+038f;
        return result;
    }
    return 0;
}
