#pragma once

class Wrap;
class StringHandle;
class Node50;
class Ref;

class Pair
{
public:
    union
    {
        int a;
        int value;
    };
    int b;

    Ref& GetNode() { return reinterpret_cast<Ref&>(b); }
    const Ref& GetNode() const { return reinterpret_cast<const Ref&>(b); }
    __declspec(property(get = GetNode)) Ref& node;

    Pair() throw();
    Pair(int aa, int bb);
    Pair(unsigned int group, unsigned int index);

    static void* operator new(unsigned int size, void* p) throw();

    Pair& Imath_Vec2_int_Vec2_int(const Pair& other);
    __declspec(nothrow) Wrap GetMemberArrayValue();
    __declspec(nothrow) StringHandle CreateValueInto();
    __declspec(nothrow) Node50* DispatchToVTableSlot8(int mode);
    __declspec(nothrow) int ForwardCall_00dbac70();
    __declspec(nothrow) float ApplyValue();
    __declspec(nothrow) int CallVirtualWithArg();
};
