#pragma once

#include "MobileObject.h"

class ArrowRenderer;
class ArrowWorldObj;
class B5F750Ref;

class ArrowProjectile : public MobileObject
{
public:
    int FUN_008ce390();
    ArrowRenderer* GetRenderer();
    B5F750Ref* GetAttachedRef();
    void Detach();
    bool HandleType0(ArrowWorldObj* obj);
    bool HandleType1(ArrowWorldObj* obj);
    bool HandleType2(ArrowWorldObj* obj);
    bool HandleType3(ArrowWorldObj* obj);
    bool HandleType4(ArrowWorldObj* obj);
    bool ProcessImpact();

    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
};
