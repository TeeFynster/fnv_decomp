#pragma once

#include "NiSkinInstance.h"

class ObjC;
class Entry4;

class BSDismemberSkinInstance : public NiSkinInstance
{
public:
    struct Partition
    {
        union { unsigned char enabled; unsigned char b0; };
        union { unsigned char unk01; unsigned char b1; };
        union { unsigned short bodyPart; unsigned short w; };
    };

    BSDismemberSkinInstance(NiSkinData* skinData, NiNode* rootParent, NiAVObject** bones,
                           Partition* partitions, unsigned int partitionCount);
    BSDismemberSkinInstance(ObjC* skinData, int rootParent, int* bones, Entry4* partitions,
                           int partitionCount);

    virtual ~BSDismemberSkinInstance();
    virtual const NiRTTI* GetRTTI() const;
    virtual void LinkObject(NiStream& stream);

    void* __thiscall FUN_006885e0(unsigned int);
    void __thiscall SetVtableAndProcessState_00688610();
    void* __thiscall FUN_006884c0(int, int, int);
    void* __thiscall ConstructShell(int, int, int, int, int);
    Partition* GetField38();


    static const NiRTTI ms_kRTTI;

    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    unsigned int unk34;
    Partition* unk38;
    unsigned char unk3C;
    unsigned char unk3D[3];
};
