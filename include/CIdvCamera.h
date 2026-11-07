#pragma once

#include "NiPoint3.h"
#include "CVec3.h"

class CIdvCamera
{
public:
    CVec3 m_kTranslation;

    CIdvCamera();
    virtual ~CIdvCamera();
    virtual CIdvCamera& AssignFields_00b3f0c0(const CIdvCamera& other);

    CIdvCamera& UpdateState_00b402d0(const CIdvCamera& src);
    CIdvCamera& CloneCamera();
    NiPoint3 CBillboardLeaf_GetColor();
    float* CBillboardLeaf_GetColor(float* pOut);
    void CBillboardLeaf_SetColor(const NiPoint3& value, bool flag);
};

class CIdvCameraClone : public CIdvCamera
{
public:
    unsigned char unk10;
    unsigned char unk11[3];
    int unk14;
    unsigned char unk18;
    unsigned char unk19[3];
    NiPoint3 unk1C;
    NiPoint3 unk28;
    NiPoint3 unk34;
    unsigned char unk40;
    unsigned char unk41[3];
    float unk44;
    int unk48;

    CIdvCameraClone();
    CIdvCamera& UpdateState_00b402d0(const CIdvCamera& src);
    CIdvCamera& CloneCamera();
};

typedef char CIdvCameraClone_size_check[(sizeof(CIdvCameraClone) == 76) ? 1 : -1];
typedef char CIdvCameraClone_unk10_offset_check[(offsetof(CIdvCameraClone, unk10) == 0x10) ? 1 : -1];
typedef char CIdvCameraClone_unk14_offset_check[(offsetof(CIdvCameraClone, unk14) == 0x14) ? 1 : -1];
typedef char CIdvCameraClone_unk18_offset_check[(offsetof(CIdvCameraClone, unk18) == 0x18) ? 1 : -1];
typedef char CIdvCameraClone_unk1C_offset_check[(offsetof(CIdvCameraClone, unk1C) == 0x1C) ? 1 : -1];
typedef char CIdvCameraClone_unk28_offset_check[(offsetof(CIdvCameraClone, unk28) == 0x28) ? 1 : -1];
typedef char CIdvCameraClone_unk34_offset_check[(offsetof(CIdvCameraClone, unk34) == 0x34) ? 1 : -1];
typedef char CIdvCameraClone_unk40_offset_check[(offsetof(CIdvCameraClone, unk40) == 0x40) ? 1 : -1];
typedef char CIdvCameraClone_unk44_offset_check[(offsetof(CIdvCameraClone, unk44) == 0x44) ? 1 : -1];
typedef char CIdvCameraClone_unk48_offset_check[(offsetof(CIdvCameraClone, unk48) == 0x48) ? 1 : -1];
