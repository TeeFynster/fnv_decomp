#pragma once

#include "NiAVObject.h"
#include "NiColor.h"
#include "StrArr.h"

#include "NiTPointerList.h"

class NiDynamicEffect : public NiAVObject
{
  public:
    NiDynamicEffect();
    virtual ~NiDynamicEffect();
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;

    void AppendEffectProperties(StrArr* strings);

    void IncRevisionID();
    void SetEffectColor(const NiColor& color);
    using NiAVObject::SetEffectColor;

    bool switchState;
    unsigned char effectType;
    long iIndex;
    unsigned long pushCount;
    unsigned long revID;
    NiTPointerList<NiNode*> shadowGenerator;
    NiTPointerList<NiNode*> unaffectedNodes;
};
