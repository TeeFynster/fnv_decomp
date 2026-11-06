#pragma once

#include "NiTPointerMap.h"

// RTTI: NumericIDBufferMap : NiTPointerMap<unsigned int,void *>, vftable 0x01080554: only the destructor is its own.
class NumericIDBufferMap : public NiTPointerMap<unsigned int, void*>
{
public:
    virtual ~NumericIDBufferMap();
    void FUN_008555b0();
    void* FUN_00855580(unsigned int flags);
    void* FUN_004b9ba0();
    void FUN_006b7f20(void** node, unsigned int* key, void** value);
    void FUN_00438af0();
};
