#pragma once

#include "NiExtraData.h"
#include "BSStringT.h"

class NiAVObject;

class DebugTextExtraData : public NiExtraData
{
public:
    DebugTextExtraData(NiAVObject* a, const char* name, int x, int y);
    virtual const NiRTTI* GetRTTI() const;
    // Preserve the /Ob1 deleting-destructor scratch frame with the shared string destructor.
    static __forceinline void operator delete(void* object, size_t size)
    {
        int a0, a1, a2, a3, a4, a5, a6, a7;
        NiMemObject::operator delete(object, size);
    }

    NiAVObject* node;
    BSStringT<char> text;
    int expected;
    int height;
};
