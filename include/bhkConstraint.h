#pragma once

#include "bhkSerializable.h"

class bhkConstraint : public bhkSerializable
{
public:

    bhkConstraint();
    virtual ~bhkConstraint();

    virtual const NiRTTI* GetRTTI() const;

    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();

    void* DestroyConstraint(unsigned int);
    void bhkSerializable_Kill();

    int m_iThirdValue;

    static const NiRTTI ms_kRTTI;
};
