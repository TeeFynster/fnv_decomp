#pragma once

#include "hkaRaycastInterface.h"
#include "hkBool.h"
#include "NiMatrix3.h"

class NiNode;
class RagMid;
class HkRef;
class RefObj;
class X48;
class Arr32;
class RagdollPoseArrays;
class T48;
class T208;

class bhkRagdollController : public hkaRaycastInterface
{
public:
    template <class T> struct HkArrX
    {
        T* m_data;
        int m_iElementCount;
        int m_capFlags;
        ~HkArrX();
    };

    struct RefPtr
    {
        RefObj* m_p;
        void Reset();
        ~RefPtr();
    };

    struct FixedStr9
    {
        char* m_h;
        char* GetChars() { return m_h; }
        ~FixedStr9();
    };

    struct PolyArr
    {
        virtual void vf0(void*);
        virtual void vf1(void*);
        virtual void vf2(void*);
        virtual void vf3(void*);
        void* m_data;
        int m_iElementCount;
        int m_cap;
        ~PolyArr();
    };

    virtual ~bhkRagdollController();
    virtual hkBool castRay(const hkVector4& fromWS, const hkVector4& toWS,
                           float& hitFractionOut, hkVector4& normalWSOut);

    void* FUN_00c7de30(unsigned int);
    void FUN_00c75580(unsigned char enabled);
    void FUN_00c7d630(float);
    void FUN_00c7d630(int);
    void FUN_00c7d810();
    void FUN_00c79680();
    void FUN_00c7cb50(int);
    void FUN_00c76350(void*);
    void FUN_00c751f0(void*);
    void FUN_00c7aa60(void*);
    void FUN_00c7ba50(void*, void*, bool*);
    void FUN_00c7d030(void*);
    void FUN_00c7d030(int);
    void FUN_00c7c870();
    void FUN_00c79a50();
    void FUN_00c7b6a0(int);
    void FUN_00c7ba10(bool);
    void FUN_00888a70(float*, float*);
    void SetFloats(float, float);
    // Head-look limits Actor::m_pRagdollController (+0xAC) receives in TESNPC::UpdateActorFaceGen (0x00607420):
    // 0x00607830 stores +0x1a8; 0x00607810 stores +0xf8 + bone*0x50; 0x00c748d0 stores +0x134/+0x138 + bone*0x50.
    void FUN_00607830(float);
    void SetBoneMaxAngle(int, float);
    void SetSlotFloats(int, float, float);
    void ClearField23C();

    unsigned char unk04[0x44];
    union
    {
        RagMid* m_48;
        HkRef* m_p48;
    };
    X48* m_p4c;
    unsigned int unk50;
    RagdollPoseArrays* m_p54;
    NiNode* m_pkNode;
    unsigned int unk5C;
    NiMatrix3 m_kRot;
    RefPtr m_84;
    RagdollPoseArrays* m_p88;
    unsigned char unk8C[8];
    HkArrX<T48> m_94;
    PolyArr m_a0;
    unsigned char unkB0[0x17C];
    HkArrX<T208> m_22c;
    int m_238;
    int m_23c;
    int m_240;
    int m_244;
    Arr32* m_p248;
    FixedStr9 m_24c;
    RefPtr m_250;
    unsigned char unk254[0x4C];
    FixedStr9 m_2a0;
    RefPtr m_2a4;
    unsigned char unk2A8[0x14];
};
