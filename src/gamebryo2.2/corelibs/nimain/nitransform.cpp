// gamebryo2.2/corelibs/nimain/nitransform.cpp: NiTransform (4 functions)
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiColor.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiTransform.h"

// unit matrix, written row by row in the order the inlined copies store it
#define XF_M3_ROW(r, a, b, c) m_pEntry[r][0] = a; m_pEntry[r][1] = b; m_pEntry[r][2] = c;
inline void NiMatrix3::MakeIdentity()
{
    XF_M3_ROW(0, 1.0f, 0.0f, 0.0f)
    XF_M3_ROW(1, 0.0f, 1.0f, 0.0f)
    XF_M3_ROW(2, 0.0f, 0.0f, 1.0f)
}
#undef XF_M3_ROW

inline void NiBinaryStream::Read(float* value)
{
    unsigned int size = sizeof(float);
    m_uiAbsoluteCurrentPos += m_pfnRead(this, value, sizeof(float), &size, 1);
}

inline void NiBinaryStream::Write(const void* value)
{
    unsigned int componentSize = sizeof(float);
    m_uiAbsoluteCurrentPos += m_pfnWrite(this, value, sizeof(float), &componentSize, 1);
}

// @fnv 0x00a86bf0
void NiTransform::ResetToIdentity()
{
    m_Rotate.MakeIdentity();
    m_Translate = NiPoint3::ZERO;
    m_fScale = 1.0f;
}

// @fnv 0x00a86c80
void NiTransform::LoadBinary(NiStream& stream)
{
    m_Rotate.LoadBinary(stream);
    m_Translate.LoadBinary(stream);
    stream.m_pkIstr->Read(&m_fScale);
}

// The shared class does not declare this comparison. The unused EDX argument
// preserves the original member-call ABI while using NiTransform directly.
// @fnv 0x00a86c30
unsigned int __fastcall TransformNotEqual(const NiTransform* transform, void*, const NiTransform& other)
{
    if (transform->m_Rotate == other.m_Rotate)
    {
        if (!(transform->m_Translate != other.m_Translate))
        {
            if (transform->m_fScale == other.m_fScale)
                return false;
        }
    }
    return true;
}

// Writes the orientation, translation, and scale of the transform to the given NiStream.
// @fnv 0x00a86cd0
void NiTransform::SaveBinary(NiStream* stream)
{
    m_Rotate.SaveBinary(*stream);
    m_Translate.SaveBinary(stream);
    stream->m_pkOstr->Write(static_cast<const void*>(&m_fScale));
}
