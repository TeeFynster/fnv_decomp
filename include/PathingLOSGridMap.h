#pragma once
#include "NiRefObject.h"

class PathingLOSGridMap : public NiRefObject
{
public:
    struct LOSGridMap08
    {
        ~LOSGridMap08();

        int unk00;
        int unk04;
        int unk08;
        int unk0C;
    };

    struct LOSGridLock1C
    {
        ~LOSGridLock1C();

        int unk00;
    };

    virtual ~PathingLOSGridMap();

    void __thiscall ClearMap();
    void __thiscall Initialize_006e0320(void* p, float f);
    void __thiscall Reset();
    void __thiscall FUN_006e02a0();
    void __thiscall Animation_ResetVtableAndFinishScriptRunLock();
    void* __thiscall FUN_006e0270(unsigned int flags);
    void FUN_006e04b0();
    void* __thiscall FUN_006e0480(unsigned int flags);

    void __thiscall SetLocation(void* p, float f);
    void* __thiscall DestroyAndFree(unsigned int flags);
    void DestroyElements();
    void* __thiscall DestroyElementsAndFree(unsigned int flags);

    LOSGridMap08 _pad0;
    float m_fCellSize;
    LOSGridLock1C m_1C;
    unsigned char _pad1[0x24];
    float fRadius;
};
