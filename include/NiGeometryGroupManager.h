#pragma once

#include "NiMemObject.h"

class NiGeometryGroupManager : public NiMemObject
{
public:
    enum RepackingBehavior
    {
        STATIC,
        UNSHARED,
        DYNAMIC
    };

    virtual void* vf00(unsigned int);
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
};
