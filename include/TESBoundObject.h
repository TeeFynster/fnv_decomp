#pragma once

#include "TESObject.h"
#include "TESBoundObject__BOUND_DATA.h"

class NiPoint3;

class TESBoundObject : public TESObject
{
public:
    TESBoundObject();
    virtual ~TESBoundObject();

    virtual NiNode* Clone3DAlt(TESObjectREFR* requester);
    virtual bool ReplaceModelAlt(const char* path);

    int GetFormType() const;
    float GetBoundSize();
    bool CannotSell();
    int GetSpellType();
    int FUN_0044ddc0();
    unsigned int FUN_00401170();
    void FUN_0050eb90(NiPoint3* point);
    NiPoint3* FUN_0050ead0(NiPoint3* point);
    TESBoundObject* FUN_007af430();
    void LoadBoundData(TESFile* file);
    NiAVObject* Get3DObject(TESObjectREFR* reference);
    NiNode* Get3DObject(TESObjectREFR* reference, bool firstPerson);
    unsigned int ID();

    struct Bounds
    {
        short x;
        short y;
        short z;
    };

    unsigned char unk18[0xC];
    union
    {
        TESBoundObject__BOUND_DATA TESBoundObjectBounds;
        struct TESBoundObjectBounds
        {
            Bounds kMinBoundsCur;
            Bounds kMaxPoint;
        } kBoundData;
    };
};
