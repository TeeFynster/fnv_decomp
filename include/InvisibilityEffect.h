#pragma once

#include "ValueModifierEffect.h"

class Actor;

class InvisibilityEffect : public ValueModifierEffect
{
public:
    InvisibilityEffect(void*, void*, void*);
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);
    InvisibilityEffect* CreateEffect();
    void __thiscall FUN_0082cd10(Actor* actor);
    void __thiscall ApplyInvisibility(Actor* actor);
    void RevertInvisibility(Actor* apActor);
};
