#pragma once

#include "hkReferencedObject.h"

class __declspec(align(16)) hkpCharacterContext : public hkReferencedObject
{
public:
    virtual ~hkpCharacterContext() throw();

    int unk08;
    void* unk0C;
    int unk10;
    int unk14;
    unsigned char unk18;
    float unk1C;
    float unk20;
    float unk24;

    hkpCharacterContext* Initialize(void* arg0, int arg1);
    static float __cdecl GetReferenceTimeStep();
};
