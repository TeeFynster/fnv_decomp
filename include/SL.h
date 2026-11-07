#pragma once

class Actor;
class Item;
class SkySoundObj;

class SL
{
public:
    int a;
    int b;

    SL() : a(0), b(0) {}
    ~SL() {}
    void AddHead(SkySoundObj**);
    void RemoveAll();
    Item*& FUN_006815c0();
    void FUN_0063f7b0();
    SL* FUN_00726070();
    void RemoveMatchingItem(Actor* const& a);
};
