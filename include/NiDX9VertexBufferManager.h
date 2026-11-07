#pragma once

#include "NiRefObject.h"
#include "NiTPointerMap.h"

struct ComStub;

class NiDX9VertexBufferManager : public NiRefObject
{
public:
    class NiDX9VBInfo;

    struct CritSecStub
    {
        void* DebugInfo;
        long LockCount;
        long RecursionCount;
        void* OwningThread;
        void* LockSemaphore;
        unsigned long SpinCount;
    };

    ComStub* device;
    NiTPointerMap<unsigned int, NiDX9VBInfo*> first, second, third;
    int unk3c;
    void* allocation;
    int unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    CritSecStub lock;

    void __thiscall DestroyDefaultBuffers();
    void __thiscall ReleaseStorage_00e8ceb0();
};
