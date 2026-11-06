#pragma once

#include "hkpConstraintData.h"
#include "hkBool.h"
#include "hkVector4.h"

class hkpPulleyConstraintData : public hkpConstraintData
{
public:
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual hkBool vf07() const;
    virtual int vf08();
    virtual void vf09(char a, int* b);
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15(int a);

    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    hkVector4 m_kTranslationA;
    hkVector4 m_kTranslationB;
    hkVector4 unk40;
    hkVector4 m_kFixedPivotA;
    hkVector4 m_kFixedPivotB;
    float unk70;
    float m_fRopeLength;
};
