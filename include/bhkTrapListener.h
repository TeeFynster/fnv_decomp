#pragma once

#include "bhkEntityListener.h"
#include "hkpPhantomListener.h"

class bhkTrapListener : public bhkEntityListener, public hkpPhantomListener
{
public:
    virtual ~bhkTrapListener();

    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();

    void FUN_0062d760();
    void* DestroyIfFlagged(unsigned int);
};
