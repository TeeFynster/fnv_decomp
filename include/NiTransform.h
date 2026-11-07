#pragma once

#include <stddef.h>
#include "NiMatrix3.h"
#include "NiPoint3.h"
#include "NiSphere.h"

class NiStream;

class NiTransform
{
public:
    NiMatrix3 m_Rotate;
    NiPoint3 m_Translate;
    float m_fScale;

    NiTransform();
    void ResetToIdentity();
    void Invert(NiTransform* result);
    void Invert(NiTransform& result) const;
    void CalculateInverse(NiTransform* result);
    void CalculateInverse(NiTransform& result);
    void InvertTransform(NiTransform& result) const;
    void InvertTransform();
    bool IsIdentity();

    NiTransform operator*(const NiTransform& other) const;

    void LoadBinary(NiStream* stream);
    void LoadBinary(NiStream& stream);
    void SaveBinary(NiStream* stream);
    char* ToString(const char* prefix);

    NiMatrix3 FUN_004768c0();
    NiTransform* NiTransform_NiTransform();
    NiPoint3 FUN_004b4500(NiPoint3* point);
    void FUN_004b4880(NiTransform& result) const;
    void FUN_004b4880(NiTransform* result) const;
    void ComputeValue_00524c40(NiPoint3* centre, const NiSphere* sphere);
    NiPoint3* ComputeValue_00524c40(NiPoint3* result, const NiPoint3& point) const;
    NiPoint3 ComputeValue_00524c40(const NiPoint3& point) const;
    NiTransform FUN_0062c250(NiTransform* other);
    NiTransform FUN_0062c250(const NiTransform& other) const;
    NiTransform* FUN_0062c250(NiTransform* result, const NiTransform& other) const;
};

typedef char NiTransform_size_check[(sizeof(NiTransform) == 52) ? 1 : -1];
typedef char NiTransform_m_Rotate_offset_check[(offsetof(NiTransform, m_Rotate) == 0) ? 1 : -1];
typedef char NiTransform_m_Translate_offset_check[(offsetof(NiTransform, m_Translate) == 36) ? 1 : -1];
typedef char NiTransform_m_fScale_offset_check[(offsetof(NiTransform, m_fScale) == 48) ? 1 : -1];
