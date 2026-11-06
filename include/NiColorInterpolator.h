#pragma once

#include "NiKeyBasedInterpolator.h"
#include "NiAVObject.h"
#include "NiColorA.h"

class NiColorData;
class ColorAnimationKey;

#include "NiAnimationKey.h"

class NiColorInterpolator : public NiKeyBasedInterpolator
{
  public:
    NiColorInterpolator(NiColorData* pkColorData = 0) throw();
    virtual ~NiColorInterpolator();
    NiColorInterpolator& operator=(const NiColorInterpolator&);

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess&);
    virtual void LoadBinary(NiStream&);
    virtual void LinkObject(NiStream&);
    virtual bool RegisterStreamables(NiStream&);
    virtual void SaveBinary(NiStream&);
    virtual bool IsEqual(NiObject*) const;
    virtual void GetViewerStrings(NiViewerStringsArray*);
    virtual bool UpdateColorA(float, NiObjectNET*, NiColorA&);
    virtual bool IsColorAValueSupported() const;
    virtual void Collapse();
    virtual void GetInterpolatorTimeRange(float&, float&) const;
    virtual void SetActiveTimeRange(float, float);
    virtual NiInterpolator* CloneForTimeRange(float, float);
    virtual unsigned short GetKeyChannelCount() const;
    virtual unsigned int GetColorKeyCount(unsigned short) const;
    virtual void vf57();
    virtual void vf58();
    virtual NiAnimationKey* GetChannelKeys(unsigned short) const;
    virtual unsigned char GetColorKeySize(unsigned short) const;
    virtual void vf61(unsigned short);

    bool Update(float, NiObjectNET*, NiColorA&);
    NiColorData* GetColorData() const;
    void SetColorData(NiColorData*);
    void SetColorValue(NiColorA);
    void SetAnimationKeys(ColorAnimationKey*, unsigned int, NiAnimationKey::KeyType);
    NiAnimationKey::KeyContent GetColorKeyContent(unsigned short) const;
    NiAnimationKey::KeyType GetColorKeyType(unsigned short) const;
    bool IsColorConstant(unsigned short) const;


    NiColorA m_kColorValue;
    NiPointer<NiColorData> m_spColorData;
    unsigned int m_uiLastKeyIndex;
};
