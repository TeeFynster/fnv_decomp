#pragma once

#include <stddef.h>
#include "NiLight.h"
#include "NiPoint3.h"
#include "NiPoint3.h"

class NiPointLight : public NiLight
{
  public:
    NiPointLight();
    virtual ~NiPointLight();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual void UpdateWorldData(NiUpdateData& update);


    bool IsEqual(NiObject* object);
    void SetEffectColor(const NiPoint3& color);
    using NiLight::SetEffectColor;
    void SetConstantAttenuation(float value);
    void SetLinearAttenuation(float value);
    void SetQuadraticAttenuation(float value);
    void SetDimmer(float value);
    void SetSpecularColor(const NiPoint3& color);
    void IncRevisionID();

    void FUN_0050c630(float value);
    void FUN_0050c660(float value);
    void FUN_0050c690(float value);
    void NiLight_SetDimmer(float value);
    void FUN_0050dd50(const NiPoint3& color);
    void FUN_004bc2c0();
    bool IsEqual_00a7d730(NiObject* object);
    void UpdateWorldData_00a7d7a0(NiUpdateData& update);

    unsigned char storage[0xfc - sizeof(NiLight)];
};

typedef char NiPointLight_size_check[(sizeof(NiPointLight) == 252) ? 1 : -1];
typedef char NiPointLight_storage_offset_check[(offsetof(NiPointLight, storage) == 0xf0) ? 1 : -1];
