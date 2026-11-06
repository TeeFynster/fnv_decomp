#pragma once

#include "hkReferencedObject.h"
#include "hkTransform.h"

class hkDisplayGeometry : public hkReferencedObject
{
public:
    virtual ~hkDisplayGeometry() throw();
    virtual void vf03();
    virtual void vf04();

    hkTransform m_kMotionTransform;

    static void* __cdecl operator new(std::size_t nbytes);
};
