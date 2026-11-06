#pragma once

#include "TESPackage.h"
#include "NiPoint3.h"
#include "BSSimpleArray.h"

class SearchReference;
class PathingCoverLocation;

class SearchPackage : public TESPackage
{
public:
    class CoverRequest
    {
    public:
        CoverRequest();
        ~CoverRequest()
        {}

        int unk00;
        int unk04;
        int unk08;
        int unk0c;
        int unk10;
        int unk14;
        int unk18;
        int unk1c;
        int unk20;
        int unk24;
        int unk28;
        int unk2c;
        int unk30;
        int unk34;
        int unk38;
        int unk3c;
        int unk40;
        int unk44;
        int unk48;
        int unk4c;
        int unk50;
        int unk54;
        int unk58;
        int unk5c;
        int unk60;
        int unk64;
        int unk68;
        int unk6c;
        int unk70;
        int unk74;
        int unk78;
        int unk7c;
        int unk80;
        int unk84;
        int unk88;
        int unk8c;
        int unk90;
        int unk94;
        int unk98;
        int unk9c;
        int unka0;
        int unka4;
        int unka8;
        int unkac;
        int unkb0;
        int unkb4;
        int unkb8;
        int unkbc;
        int unkc0;
        int unkc4;
        int unkc8;
        int unkcc;
        int unkd0;
        int unkd4;
        int unkd8;
        int unkdc;
        int unke0;
        int unke4;
        int unke8;
    };

    SearchPackage(float afX, float afY, float afZ, int aiValue, int aiUnused);
    virtual ~SearchPackage();

    float unk80;
    int unk84;
    float unk88;
    int unk8c;
    float unk90;
    NiPoint3 unk94;
    int unka0;
    char unka4;
    unsigned char unkA5[3];
    CoverRequest unka8;
    BSSimpleArray<PathingCoverLocation, 1024> unk194;

    int HasSearchLocation();
    unsigned int Radius(SearchReference*);
    void* Cell(SearchReference*);
    NiPoint3 Coord(SearchReference*);
    bool AcquireRadius(SearchReference*, float&);
    void* DestroyIfFlagged(unsigned int flags);
    void* FUN_009f67b0();
};
