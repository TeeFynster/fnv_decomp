#pragma once

#include "NiColor.h"

class BSFogProperty
{
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    NiColor color;
    float nearDepth;
    float farDepth;
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
    float density;

    BSFogProperty();
    ~BSFogProperty();

    static void* operator new(size_t size);
    static void operator delete(void*, unsigned int);
    void IncRefCount();
    void DecRefCount();
    BSFogProperty* __thiscall FUN_00bb8250(unsigned char flags);

    void SetFog(float start, float end);
    void SetPower(float power);
    void SetWaterFog(float start, float end);
    void SetWaterColor(const NiColor& color);
};
