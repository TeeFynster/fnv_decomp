// gamebryo2.2/corelibs/nianimation/nibsplineinterpolator.cpp: NiBSplineInterpolator (10 functions)
#include "NiRefObject_inline.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiBSplineInterpolator.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiTPrimitiveArray.h"

#include "nibsplineinterpolator_decls.h"

template <class T> inline NiPointer<T>::operator T*() const
{
    return m_pObject;
}

template <class T> inline T* NiPointer<T>::operator->() const
{
    return m_pObject;
}

__forceinline void NiBinaryStream::ReadFloat(float& value)
{
    unsigned int componentSize = 4;
    m_uiAbsoluteCurrentPos += m_pfnRead(this, &value, 4, &componentSize, 1);
}

__forceinline void NiBinaryStream::Write(void* value)
{
    unsigned int componentSize = 4;
    m_uiAbsoluteCurrentPos += m_pfnWrite(this, value, 4, &componentSize, 1);
}

// @fnv 0x00a58080
void NiBSplineInterpolator::LoadBinary(NiStream& stream)
{
    NiInterpolator::LoadBinary(stream);
    stream.m_pkIstr->ReadFloat(m_fStartTime);
    stream.m_pkIstr->ReadFloat(m_fEndTime);
    AssignSplineObject(m_spTransformData, stream.DeserializeObject());
    AssignSplineObject(m_spSplineBasisData, stream.DeserializeObject());
}

extern "C" const char* g_011f3fe4_arg1;

// The shared class does not yet declare this RTTI override.
// @fnv 0x00a57f70
const NiRTTI* __fastcall NiBSplineInterpolator_GetRTTI(const NiBSplineInterpolator*)
{
    return reinterpret_cast<const NiRTTI*>(&g_011f3fe4_arg1);
}

bool __fastcall RegisterInterpolatorStreamables(NiBSplineInterpolator*, void*, NiStream&);

// The shared class does not yet declare this streaming override.
// @fnv 0x00a57e50
bool __fastcall NiBSplineInterpolator_RegisterStreamables(NiBSplineInterpolator* self, void* unused, NiStream& kStream)
{
    if (!RegisterInterpolatorStreamables(self, unused, kStream))
        return false;
    NiObject* pFirstStreamable = self->m_spTransformData.m_pObject;
    if (pFirstStreamable)
        pFirstStreamable->RegisterStreamables(kStream);
    NiObject* pSecondStreamable = self->m_spSplineBasisData.m_pObject;
    if (pSecondStreamable)
        pSecondStreamable->RegisterStreamables(kStream);
    return true;
}

void __fastcall FUN_00a57f80(void*);
void __cdecl _delete(void*, unsigned int);

// @fnv 0x00a581e0
void* __fastcall NiBSplineInterpolator_Delete(NiBSplineInterpolator* self, void* unused, unsigned int auiFlags)
{
    FUN_00a57f80(self);
    if (auiFlags & 1)
        _delete(self, 0x1c);
    return self;
}

extern double DAT_010231b0;
extern double DAT_010241b0;

// @fnv 0x00a57d60
void NiBSplineInterpolator::GetInterpolatorTimeRange(float& fBegin, float& fEnd) const
{
    if (fBegin == DAT_010231b0 && fEnd == DAT_010241b0)
        fEnd = fBegin = 0.0f;
    else
    {
        fBegin = m_fStartTime;
        fEnd = m_fEndTime;
    }
}

// @fnv 0x00a57da0
unsigned int NiBSplineInterpolator::vf61(unsigned short channel)
{
    if (vf60())
        return vf57(channel) * vf56(channel) * 2;
    return vf57(channel) * vf56(channel) * 4;
}

// Preserve the original full-width channel argument when calling vf62; the shared vf56 declaration takes a short.
// @fnv 0x00a57e00
unsigned int __fastcall NiBSplineInterpolator_ControlPointCount(NiBSplineInterpolator* self, void*, int param)
{
    int r0 = self->vf55();
    if ((unsigned short)param < (unsigned short)r0)
    {
        if (self->m_spTransformData.m_pObject != 0)
        {
            int r1 = self->vf62(param);
            if (r1 != 0xffff)
            {
                void* p = &self->m_spSplineBasisData.m_pObject->GetBSplineBasis();
                return *(int*)p;
            }
        }
    }
    return 0;
}

bool __fastcall IsInterpolatorEqual(NiBSplineInterpolator*, void*, NiObject*);

// The shared class does not yet declare this equality override.
// @fnv 0x00a57e90
bool __fastcall NiBSplineInterpolator_IsEqual(NiBSplineInterpolator* self, void* unused, NiObject* pkObject)
{
    if (!IsInterpolatorEqual(self, unused, pkObject))
        return false;
    NiBSplineInterpolator* pkOther = (NiBSplineInterpolator*)pkObject;
    if (self->m_fStartTime == pkOther->m_fStartTime && self->m_fEndTime == pkOther->m_fEndTime)
        return true;
    if ((self->m_spTransformData && !pkOther->m_spTransformData) ||
        (!self->m_spTransformData && pkOther->m_spTransformData))
        return false;
    if (self->m_spTransformData && !self->m_spTransformData->IsEqual(pkOther->m_spTransformData))
        return false;
    if ((self->m_spSplineBasisData && !pkOther->m_spSplineBasisData) ||
        (!self->m_spSplineBasisData && pkOther->m_spSplineBasisData))
        return false;
    if (self->m_spSplineBasisData && !self->m_spSplineBasisData->IsEqual(pkOther->m_spSplineBasisData))
        return false;
    return false;
}

void __fastcall SaveInterpolatorBinary(NiBSplineInterpolator*, void*, NiStream*);

// The shared class does not yet declare this streaming override.
// @fnv 0x00a58160
void __fastcall NiBSplineInterpolator_SaveBinary(NiBSplineInterpolator* self, void* unused, NiStream* pStream)
{
    SaveInterpolatorBinary(self, unused, pStream);
    pStream->m_pkOstr->Write((void*)&self->m_fStartTime);
    pStream->m_pkOstr->Write((void*)&self->m_fEndTime);
    pStream->SaveLinkID(self->m_spTransformData.m_pObject);
    pStream->SaveLinkID(self->m_spSplineBasisData.m_pObject);
}

template <class T, class TAlloc>
inline unsigned int NiTArray<T, TAlloc>::SetAtGrow(unsigned int uiIndex, const T& pcElement)
{
    if (uiIndex >= m_usMaxSize)
        SetSize(uiIndex + m_usGrowBy);
    SetAt(uiIndex, pcElement);
    return uiIndex;
}

template <class T, class TAlloc>
inline unsigned int NiTArray<T, TAlloc>::Add(const T& pcElement)
{
    return SetAtGrow(m_usSize, pcElement);
}

extern const char* g_pcA58200Name;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcString);
char* __cdecl NiGetViewerString_00a7d550(const char* pcName, float fValue);
void __fastcall GetInterpolatorViewerStrings(NiBSplineInterpolator*, void*, NiViewerStringsArray*);

// The shared class does not yet declare this viewer override.
// @fnv 0x00a58200
void __fastcall NiBSplineInterpolator_GetViewerStrings(NiBSplineInterpolator* self, void* unused, NiViewerStringsArray* pkStrings)
{
    GetInterpolatorViewerStrings(self, unused, pkStrings);
    pkStrings->Add(NiViewerStrings_NiGetViewerString_Title(g_pcA58200Name));
    pkStrings->Add(NiGetViewerString_00a7d550("m_fStartTime", self->m_fStartTime));
    pkStrings->Add(NiGetViewerString_00a7d550("m_fEndTime", self->m_fEndTime));
    NiObject* first = self->m_spTransformData.m_pObject;
    if (first)
        first->GetViewerStrings(pkStrings);
    NiObject* second = self->m_spSplineBasisData.m_pObject;
    if (second)
        second->GetViewerStrings(pkStrings);
}
