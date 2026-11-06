#pragma once

#include "hkBool.h"

class hkVector4;

class hkaRaycastInterface
{
public:
    virtual ~hkaRaycastInterface() {}

    // Overloaded virtuals are laid out in reverse declaration order, so the
    // vtable is: ~hkaRaycastInterface, castRay (with filter), castRay.
    virtual hkBool castRay(const hkVector4& fromWS, const hkVector4& toWS,
                           float& hitFractionOut, hkVector4& normalWSOut);
    virtual hkBool castRay(const hkVector4& fromWS, const hkVector4& toWS,
                           unsigned int collisionFilterInfo, float& hitFractionOut,
                           hkVector4& normalWSOut);
};
