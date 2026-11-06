#pragma once

#include "NiD3DRenderState.h"

class NiDX9RenderState : public NiD3DRenderState
{
public:
    virtual ~NiDX9RenderState();

    struct Entry
    {
        unsigned int value;
        unsigned int unk;
    };

    char _pad[0xE20 - sizeof(NiD3DRenderState)];
    Entry mState[8][5];

    unsigned int GetStateValue(unsigned int, unsigned int);
    void ApplyDefaultRenderStates();
};
