#pragma once

#include "hkDataArrayImpl.h"

class NativeDBC;

class hkDataArrayNative : public hkDataArrayImpl
{
public:
    hkDataArrayNative(int iWorld, void* pvData, int iSize, int iStride, int iType, int m_iMenuId, int iTupleCount) throw();
    void* operator new(unsigned int nbytes);

    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual hkDataArrayNative* swizzleObjectMember(int index);
    virtual int asVec(int a);
    virtual void vf09();
    virtual int asString(int a);
    virtual void vf11();
    virtual float asReal(int index);
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual int GetElementAsInt(int index);
    virtual void vf17();
    virtual __int64 GetEntry64(int a);
    virtual void vf19();
    virtual NativeDBC* asObject(int index);
    virtual void vf21();
    virtual hkDataArrayNative* GetElement(int iIndex);
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();

    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_24;
    int m_28;
};
