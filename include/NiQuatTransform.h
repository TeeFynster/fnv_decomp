#pragma once

#include "NiPoint3.h"
#include "NiQuaternion.h"

class NiStream;

class NiQuatTransform
{
public:
    float x;
    float y;
    float z;
    float qx;
    float qy;
    float qz;
    float qw;
    float scale;

    NiQuatTransform();
    NiQuatTransform& operator=(const NiQuatTransform& rhs);

    const NiPoint3& GetTranslate();
    void GetTransformScale(void* value);
    void* GetRotate();
    void SetLocalRotation(void* value);
    float GetScale();
    void SetScale(float value);
    const NiQuaternion& GetOffsetC();
    float GetFloatAtOffset1C();

    bool IsInvalid() const;
    bool IsTranslateValid();
    bool IsRotateValid();
    bool IsScaleValid();
    bool IsMarkedInvalid();
    bool IsMarkedInvalid() const;
    bool IsTranslateXNotNegatedConstant();
    void SetTranslateValid(bool valid);
    void SetRotateValid(bool valid);
    void SetScaleValid(bool valid);
    void MakeInvalid();

    void Invert(NiQuatTransform* result);
    void TransformBy(NiQuatTransform* result);
    void TransformBy(NiQuatTransform& result);
    NiQuatTransform CombineTransforms(void* other);
    NiQuatTransform CombineTransforms(const NiQuatTransform& other);

    void LoadBinary(NiStream* stream);
    void LoadBinary(NiStream& stream);
    void SaveBinary(NiStream* stream);
    void GetViewerStrings(void* strings);
};
