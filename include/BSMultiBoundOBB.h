#pragma once

#include "BSMultiBoundAABB.h"

class NiPoint3;
class NiFrustumPlanes;
class NiPoint3OB;
struct Mat57;
class Vec57;

class BSMultiBoundOBB : public BSMultiBoundAABB
{
public:
    BSMultiBoundOBB();
    virtual ~BSMultiBoundOBB();


    void rotation(const Mat57& rotation);
    const Vec57& extent();
    void setExtent(const Vec57& extent);
    void GetCorners(NiPoint3* corners);
    void FUN_00c37a00(NiPoint3* corners);
    void FUN_00c37a00(NiPoint3OB* corners);
    bool FUN_00c37050(const NiFrustumPlanes& frustum);
    void FUN_004a7130();
    void* FUN_004a7100(unsigned int flags);

    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
};
