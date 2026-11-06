#pragma once

#include "NiKeyBasedInterpolator.h"
#include "NiAVObject.h"
#include "NiFloatData.h"

class NiFloatInterpolator : public NiKeyBasedInterpolator
{
  public:
    NiFloatInterpolator();
    NiFloatInterpolator(NiFloatData* pkFloatData);
    virtual ~NiFloatInterpolator();
    NiFloatInterpolator& operator=(const NiFloatInterpolator&);

    virtual void DeleteThis();
    virtual void LoadBinary(NiStream& kStream);
    virtual bool UpdateFloat(float time, NiObjectNET* target, float& result);
    virtual void Collapse();

    virtual unsigned short GetKeyChannelCount() const;
    virtual unsigned int GetColorKeyCount(unsigned short channel) const;
    virtual void vf57();
    virtual void vf58();
    virtual NiAnimationKey* GetChannelKeys(unsigned short channel) const;
    virtual unsigned char GetColorKeySize(unsigned short channel) const;
    virtual void vf61(unsigned short channel);

    void IncRefCount();
    void DecRefCount();
    bool Update(float time, NiObjectNET* target, float& result);
    NiFloatInterpolator* FUN_00a3c390(float value);
    void SetFloatValue(float value);
    void FUN_007fc2b0(NiFloatData* data);
    void SetKeyData(void* keys, unsigned int count, unsigned int type);
    void SetAnimationKeys(TimedAnimationKey* keys, unsigned int count, NiAnimationKey::KeyType type);
    void SetAnimationKeys(void* keys, unsigned int count, unsigned int type);

    float value;
    NiPointer<NiFloatData> data;
    unsigned int lastIndex;
};
