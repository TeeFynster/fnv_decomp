#pragma once

#include "bhkTTNode_TESObjectREFR_.h"

class Refr;
class TESObjectREFR;
class ZoneEntry;

template <class T>
class bhkTTNode;

template <>
class bhkTTNode<TESObjectREFR> : public bhkTTNode_TESObjectREFR_
{
};

class TargetEntry : public bhkTTNode<TESObjectREFR>
{
public:
    virtual void Run_0062c600(ZoneEntry* apTrap);

    __forceinline Refr* GetReference() const
    {
        return *reinterpret_cast<Refr* const*>(this);
    }

    __forceinline void SetReference(Refr* value)
    {
        *reinterpret_cast<Refr**>(this) = value;
    }

    __declspec(property(get=GetReference, put=SetReference)) Refr* reference;

    __forceinline bool GetSelected() const
    {
        return *reinterpret_cast<const bool*>(reinterpret_cast<const char*>(this) + 4);
    }

    __forceinline void SetSelected(bool value)
    {
        *reinterpret_cast<bool*>(reinterpret_cast<char*>(this) + 4) = value;
    }

    __declspec(property(get=GetSelected, put=SetSelected)) bool selected;
};
