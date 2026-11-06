#pragma once

#include "NiStream.h"

class NiPoint3;

class FurnitureMark
{
public:
    float fX;
    float fY;
    float fZ;
    unsigned short usHeading;
    unsigned char cMarkerType;

    unsigned int QNumber();
    void SetNumber(unsigned int);
    void* QPosition();
    void SetPosition(void*);
    float GetCurrentTargetDistance();
    NiPoint3* FUN_006815c0();   // 0x006815c0 (returns the position)
    void SetFurnitureHeading(float);
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    void __dflt_ctor_closure();
};
