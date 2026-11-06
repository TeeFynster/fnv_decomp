#pragma once

#include "NiTLargePrimitiveArray.h"

class TESForm;

class NiFormArray : public NiTLargePrimitiveArray<TESForm *>
{
public:
    NiFormArray();
    virtual ~NiFormArray();

    unsigned int GetIndexOfForm(TESForm* form);
    unsigned int GetSize();
    TESForm*& FUN_00877a30(unsigned int index);
    void SetSize(unsigned int size, unsigned int* oldSize);
    void Compact();
    void SetFormAtIndex(unsigned int index, TESForm* form);
    TESForm* GetFormAt(unsigned int index);
};
