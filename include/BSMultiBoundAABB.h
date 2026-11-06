#pragma once

#include "BSMultiBoundShape.h"
#include "NiPoint3.h"
#include "NiPoint3.h"
#include "Vec4.h"

class BSMultiBoundAABB : public BSMultiBoundShape
{
public:
    NiPoint3 Center;
    NiPoint3 m_kOffset;

    BSMultiBoundAABB();
    virtual ~BSMultiBoundAABB();
    virtual int FUN_004a7030();
    virtual void SetGridPosition(const NiPoint3& center);

    const Vec57& extent();
    void setExtent(const Vec57& extent);

    float GetPointLength();
    void FUN_00c39270(NiPoint3* points);
    void FUN_00c389e0(Vec4* point);
    void* FUN_004a7060(unsigned int flags);
};
