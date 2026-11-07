#pragma once

#include "BSExtraData.h"
#include "ActivateList334.h"
#include "ActivateString334.h"

struct ActivateEntry334;
class BSExtraDataEx;
class TESObjectREFR;

class ExtraActivateRef : public BSExtraData
{
public:
    struct ReferenceList : public ActivateList334
    {
        ~ReferenceList();
    };

    struct ReferenceText : public ActivateString334
    {
        ~ReferenceText();
    };

    virtual ~ExtraActivateRef();
    virtual bool Compare(BSExtraData* extra);

    ExtraActivateRef();
    ActivateEntry334* Find(TESObjectREFR* reference);
    bool Compare_00433a20(BSExtraData* pOther);
    void Copy(BSExtraDataEx* apSource);

    ReferenceList references;
    unsigned char flags;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    ReferenceText text;
};
