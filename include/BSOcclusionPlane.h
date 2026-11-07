#pragma once

#include "NiObject.h"

class CellPoint3;
class NiPoint3;
class NiPoint2;

class BSOcclusionPlane : public NiObject
{
public:
    // 0x004a5ff0: copies the centre (+0x08), the 2D extents (+0x14) and the 3x3 rotation (+0x1c, 36 bytes).
    BSOcclusionPlane(const NiPoint3& arCenter, NiPoint2* apExtents, char* apRotation);
    virtual ~BSOcclusionPlane();

    virtual void vf35();
    virtual void vf36();

    int GetCullResult() const;
    int GetCullResult();
    int IsNotCulled();
    void TESObjectCELL_ClearLocationMarkers();
    void* FUN_004a6110(unsigned int);
    CellPoint3* FUN_00413f40();
};
