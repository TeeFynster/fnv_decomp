#pragma once

#include "NiTimeController.h"

class Node_cls;
class ArrA;
class ArrB;
class LinkSet;
class NiTPrimitiveArray_unsigned_int;

class NiBSBoneLODController : public NiTimeController
{
public:
    struct SubObj
    {
        virtual ~SubObj();
        LinkSet** data;
        unsigned short capacity;
        unsigned short high;
        unsigned short used;
        unsigned short grow;

        void FUN_00a90180(unsigned int n);
        void FUN_00ba3aa0(unsigned int idx, LinkSet* const& p);
    };

    virtual void vf45();

    void UpdateMaxValue(Node_cls* a, ArrA* b, unsigned int* out);
    int GetField38();
    void FUN_00c52880();
    void FUN_00c53030(Node_cls* a, ArrA* b, ArrB* c);
    void FUN_00c52960(void* a);
    void FUN_00c52960(int a);
    bool FUN_00c52d80(Node_cls* arg);
    void FUN_00c53ab0(NiStream& s);
    void __thiscall FUN_00c53c50(NiTPrimitiveArray_unsigned_int* array);
    bool FUN_00c53cf0();

    void* m_34;
    unsigned int f38;
    SubObj sub;
};
