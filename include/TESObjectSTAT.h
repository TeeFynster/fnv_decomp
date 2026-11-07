#pragma once

#include "TESBoundObject.h"
#include "TESModelTextureSwap.h"

class TESFile;
class TESSound;

class TESObjectSTAT : public TESBoundObject, public TESModelTextureSwap
{
public:
    TESObjectSTAT();
    virtual ~TESObjectSTAT();
    virtual bool LoadForm(TESFile* file);

    bool Load(TESFile* file);
    void BGSMovableStatic_InitItem();

    char m_cType;
    unsigned char layoutPadding51[3];
    TESSound* m_pSoundForm;
};
