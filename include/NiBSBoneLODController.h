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
    void NiBSBoneLODController_CleanUp();
    void NiBSBoneLODController_CollectMarkedBones(Node_cls* a, ArrA* b, ArrB* c);
    void NiBSBoneLODController_SetBoneLOD(void* a);
    void NiBSBoneLODController_SetBoneLOD(int a);
    bool InitializeData_00c52d80(Node_cls* arg);
    void PostLinkObject_00c53ab0(NiStream& s);
    void __thiscall NiBSBoneLODController_GetViewerStrings(NiTPrimitiveArray_unsigned_int* array);
    bool ProcessEntries_00c53cf0();

    void* m_34;
    unsigned int f38;
    SubObj sub;
};
