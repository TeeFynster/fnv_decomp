#pragma once

#include "hkpRayHitCollector.h"
#include "HitArray.h"

class __declspec(align(16)) hkpAllRayHitCollector : public hkpRayHitCollector
{
public:
    hkpAllRayHitCollector();
    ~hkpAllRayHitCollector();

    virtual void CollectRayHit(const hkpCdBody& cdBody, const RayCastHitResult& hitInfo);
    virtual void vf01();

    int unk08;
    int unk0c;
    HitArray hits;
    unsigned char unk1c[0x304];
};
