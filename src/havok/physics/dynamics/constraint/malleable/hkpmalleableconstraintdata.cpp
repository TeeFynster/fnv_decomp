
// src/havok/physics/dynamics/constraint/malleable/hkpmalleableconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/malleable/hkpmalleableconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpMalleableConstraintData.h"

struct hkMalleableContactNormal : hkReferencedObject
{
    void RetainReference();
    void removeReference();
};

struct hkMalleableConstraintData
{
    int m_auiShapeKeys[56];
    hkMalleableContactNormal* m_contactNormals[16];
    void SetContactNormal(int index, hkMalleableContactNormal* normal);
};

// @fnv 0x00cdea30
void hkMalleableConstraintData::SetContactNormal(int index, hkMalleableContactNormal* normal)
{
    hkMalleableContactNormal* oldNormal;
    if (normal)
        normal->RetainReference();
    oldNormal = m_contactNormals[index];
    if (oldNormal)
        oldNormal->removeReference();
    m_contactNormals[index] = normal;
}

struct ConstraintDataVTable
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c(int);
};
struct MalleableConstraintDataStandIn
{
    int m_auiShapeKeys[3];
    ConstraintDataVTable* m_pConstraintData;
    int hkpMalleableConstraintData_isValid(int a);
};
// @fnv 0x00cdf690
// src: HAVOK_LIB 0x00cdf690
int MalleableConstraintDataStandIn::hkpMalleableConstraintData_isValid(int aiValue)
{
    m_pConstraintData->v1c(aiValue);
    return aiValue;
}

// @fnv 0x00cdf6b0
// src: COMMUNITY 0x00cdf6b0
int hkpMalleableConstraintData_getType()
{
    return 13;
}

struct FUN_00cdf620_Arg
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    void* m_data;
    int m_iElementCount;
};

class FUN_00cdf620_Target
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15(FUN_00cdf620_Arg* pkArg);
};

struct FUN_00cdf620_cls
{
    int m_00;
    int m_04;
    int m_08;
    FUN_00cdf620_Target* m_target;
    char m_10;

    void DispatchArg(FUN_00cdf620_Arg* pkArg);
};

// @fnv 0x00cdf620
void FUN_00cdf620_cls::DispatchArg(FUN_00cdf620_Arg* pkArg)
{
    m_target->V15(pkArg);
    pkArg->m_data = &m_10;
    pkArg->m_iElementCount = 0xc;
}

struct hkPairCDF6
{
    int m_pHeadNode;
    int m_iSecondInteger;
};

class hkInnerCDF6
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual int forward(hkPairCDF6 kPair);
};

class hkOuterCDF6
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkInnerCDF6* m_inner;

    int ForwardToInner(hkPairCDF6 kPair);
};

// Forwards the pair to m_inner's virtual forward and returns its result.
// @fnv 0x00cdf650
int hkOuterCDF6::ForwardToInner(hkPairCDF6 kPair)
{
    return m_inner->forward(kPair);
}

class MalleableGetterStandIn : public hkpMalleableConstraintData
{
  public:
    hkpConstraintData* hkpMalleableConstraintData_getWrappedConstraintData();
};

// @fnv 0x00cdf6c0
// src: XBOX_PDB 0x00cdf6c0
hkpConstraintData* MalleableGetterStandIn::hkpMalleableConstraintData_getWrappedConstraintData()
{
    return m_pConstraintData;
}

struct FUN_00cdf6d0_t
{
    int m_auiShapeKeys[3];
    int m_field_c;
    int GetFieldC();
};

// @fnv 0x00cdf6d0
// src: GUESS 0x00cdf6d0 (confidence: low)
int FUN_00cdf6d0_t::GetFieldC()
{
    return m_field_c;
}

struct Cdf7c0Info
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkpConstraintAtom* unk10;
    int unk14;
};

struct __declspec(align(16)) Cdf7c0Buf
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    float unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
};

struct Cdf7c0VTable
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v36();
    virtual void v38(Cdf7c0Info* info);
};

struct Cdf7c0Flag
{
    bool v;
};

void hkSimpleContactConstraintDataBuildJacobian(hkpConstraintAtom* atom, Cdf7c0Buf* buf, Cdf7c0Flag flag, int param2);
void hkSolverBuildJacobianFromAtomsNotContact(hkpConstraintAtom* atom, int unk14, Cdf7c0Buf* buf, int param2);

struct Cdf7c0Self
{
    int unk00;
    int unk04;
    int unk08;
    Cdf7c0VTable* m_pConstraintData;
    int unk10;
    int unk14;
    int unk18;
    float m_fSpringStrength;
    void hkpMalleableConstraintData_buildJacobian(const Cdf7c0Buf& src, int param2);
};

// Copies src, scales the copy's unk24 by m_fSpringStrength, then calls FUN_00d72190 for a contact atom or FUN_00d6f460 otherwise.
// @fnv 0x00cdf7c0
// src: XBOX_PDB 0x00cdf7c0
void Cdf7c0Self::hkpMalleableConstraintData_buildJacobian(const Cdf7c0Buf& src, int param2)
{
    Cdf7c0Buf buf = src;
    buf.unk24 *= m_fSpringStrength;
    Cdf7c0Info info;
    m_pConstraintData->v38(&info);
    Cdf7c0Flag flag;
    hkpConstraintAtom* atom = info.unk10;
    if (atom->m_type == hkpConstraintAtom::TYPE_CONTACT)
    {
        flag.v = true;
        hkSimpleContactConstraintDataBuildJacobian(atom, &buf, flag, param2);
    }
    else
    {
        hkSolverBuildJacobianFromAtomsNotContact(atom, info.unk14, &buf, param2);
    }
}

class hkObjectCDF6
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    float m_uiFilterValue;

    void hkpMalleableConstraintData_setStrength(float fValue);
};

// @fnv 0x00cdf670
// src: XBOX_PDB 0x00cdf670
void hkObjectCDF6::hkpMalleableConstraintData_setStrength(float fValue)
{
    m_uiFilterValue = fValue;
}
