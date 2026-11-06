#pragma once

#include "hkpConstraintData.h"
#include "hkpLimitedHingeConstraintDataAtoms.h"
#include "hkBool.h"

class hkpLimitedHingeConstraintData : public hkpConstraintData
{
public:
    hkpLimitedHingeConstraintData();
    virtual ~hkpLimitedHingeConstraintData() throw();

    virtual void vf03(float v);
    virtual float vf04();
    virtual void SetConstraintFlag(int cl);
    virtual unsigned char vf06();
    virtual hkBool vf07() const;
    virtual int vf08();
    virtual void vf09(int* a1, int* a2);
    virtual int vf10(int a);
    virtual void vf11(int a, int b, int c);
    virtual void vf12(int a, int b);
    virtual void vf13(unsigned char* output);
    virtual void vf14(int a);
    virtual void* vf15(int arg);

    static void* operator new(unsigned int size);
    static void operator delete(void* p);

    char padC[0x4];
    hkpLimitedHingeConstraintDataAtoms m_kBridgeAtoms;
};
