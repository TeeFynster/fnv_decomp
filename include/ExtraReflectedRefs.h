#pragma once

#include "BSExtraData.h"

class BSExtraDataEx;
class ReflectedReferenceRecord;
class TESForm;
class TESObjectREFR;

class ExtraReflectedRefs : public BSExtraData
{
public:
    // BSSimpleList<ReflectedReferenceRecord*>: constructor 0x0096a2d0, destructor 0x0046ffb0 (0x00411b40, 0x00434560).
    struct ListX
    {
        ListX();
        ~ListX();
        void RemoveAll();
        bool FUN_008256d0();
        void** FUN_006815c0();
        ListX* GetNext();

        ReflectedReferenceRecord* item;
        unsigned int next;
    };

    virtual ~ExtraReflectedRefs();
    virtual bool Compare(BSExtraData*);

    ExtraReflectedRefs();
    void FUN_00434560();
    void* FUN_00411bb0(unsigned int);
    void InitItem(TESForm*);
    void Copy(BSExtraData*);
    void Copy(BSExtraDataEx* apSource);
    void ClearReferenceData();
    ReflectedReferenceRecord* GetRefData(TESObjectREFR*);
    void RemoveReference(TESObjectREFR*);
    void AssignReferencedObject(TESObjectREFR*, unsigned int);

    ListX RefList;
};
