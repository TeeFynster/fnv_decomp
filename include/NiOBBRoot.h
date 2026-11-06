#pragma once

#include "NiPoint3.h"

class NiOBBRoot
{
public:
    virtual void* Destroy(unsigned int auiFlags);
    virtual unsigned char CompareBounds(NiOBBRoot* other, int a2, int a3, int a4, int a5);
    virtual int TestAgainst(NiOBBRoot* other, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
    virtual void vf03(int a);

    float m_fTimeStep;
    int unk08;
    int unk0C;
    NiPoint3 m_kValue;

    float GetDeltaTime() const
    {
        return m_fTimeStep;
    }

    const NiPoint3& GetSourceVelocity() const
    {
        return m_kValue;
    }
};
