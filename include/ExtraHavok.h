#pragma once

#include "BSExtraData.h"
#include "NP.h"

class bhkWorld;

class ExtraHavok : public BSExtraData
{
public:
    virtual ~ExtraHavok();

    ExtraHavok(bhkWorld*);
    ExtraHavok(int);

    void FUN_0040ee70();
    void* FUN_0040ee40(unsigned int);

    union
    {
        int pad[1];
        struct
        {
            NP first;
        };
        bhkWorld* m_pHavokWorld;
    };
    NP spMopp;
};
