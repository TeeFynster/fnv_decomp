#pragma once

#include "hkpCharacterProxyListener.h"

class bhkCharacterListener : public hkpCharacterProxyListener
{
public:
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();

    unsigned char unk04[0x6C];

    unsigned int GetFlags(unsigned int aiFlags);
};
