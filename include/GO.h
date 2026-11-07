#pragma once

#include <cstddef>

class NiObj;
class TESPackage;
class NiTexturingProperty;
class FGHolder;
class FGEntry;

class GO
{
public:
    union
    {
        void* p;
        void* m_pObject;
        unsigned int value;
        char b[4];
    };

    GO();
    GO(int value);
    GO(unsigned int* value);
    ~GO();

    GO& operator=(void* value);
    bool operator!=(int value) const;

    operator unsigned int() const;
    operator unsigned int();
    operator NiObj*() const;
    operator TESPackage*() const;
    operator NiTexturingProperty*() const;
    operator FGHolder*() const;
    operator FGEntry*() const;

    bool IsNotEqual(unsigned int value);
    int GetObjectFlags();

    void* FUN_00418f10(unsigned int flags);
    void DestroyFields();
    void FUN_0044aed0(void* value);
    void LockFreeMap_MarkedPointer_SetMark(bool flag);
    void* SetTaggedPointer(bool flag, void* value);
    GO* FUN_008228f0(unsigned int flags);

    static void* operator new[](std::size_t size);
};
