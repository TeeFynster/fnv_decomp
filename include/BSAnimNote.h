#pragma once

#include "NiObject.h"

class TimedTextEntry;

class BSAnimNote : public NiObject
{
  public:
    virtual ~BSAnimNote();
    virtual void GetViewerStrings(NiViewerStringsArray* apStrings);
    virtual bool __thiscall vf35(const TimedTextEntry* apTextKey);

    void BaseGetViewerStrings(NiViewerStringsArray* apStrings);

    unsigned char unk08[4];
    float fTime;
};
