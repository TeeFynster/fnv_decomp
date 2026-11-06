#pragma once

#include "hkpRayHitCollector.h"

struct __declspec(align(16)) SightVector4
{
    float components[4];
};

struct SightFilter
{
    unsigned int bits;

    SightFilter(int bits);
    void FUN_004a39f0(int layer);
    unsigned int FUN_004a3a20();
    void FUN_0059ce80(unsigned int);
};

struct __declspec(align(16)) SightRayOutput
{
    SightVector4 normal;
    float hitFraction;
    unsigned int m_uiExtraInfo;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int shapeKeys[8];
    void* rootCollidable;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    void* hitObject;
};

class __declspec(align(16)) hkpClosestRayHitCollector : public hkpRayHitCollector
{
public:
    hkpClosestRayHitCollector(int layer, const SightFilter* filter);
    ~hkpClosestRayHitCollector();

    virtual void CollectRayHit(const hkpCdBody& cdBody, const RayCastHitResult& hitInfo);
    virtual void vf01();

    SightRayOutput output;
    SightFilter filter;
    float distance;
};
