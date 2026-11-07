#pragma once

#include "TESPackageData.h"

class PackageTargetRecord;
class LocationDescriptor;
class TESObjectWEAP;
class TESForm;

class TESUseWeaponPackageData : public TESPackageData
{
public:
    struct Parameters
    {
        char m_c00;
        char m_c01;
        char m_c02;
        char m_c03;
        char m_c04;
        char m_c05;
        short m_s06;
        short m_s08;
        short m_s0A;
        float m_f0C;
        float m_f10;
    };

    struct Color
    {
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;
    };

    struct Info
    {
        unsigned char m_ucType;
        unsigned char m_ucPad;
        unsigned short m_usElementCount;
    };

    struct Range
    {
        unsigned short m_usMin;
        unsigned short m_usMax;
    };

    TESUseWeaponPackageData();
    TESUseWeaponPackageData(Parameters kData, int iParam);
    TESUseWeaponPackageData(Color kColor, Info kInfo, Range kRange,
                            float fStart, float m_fEndValue);

    virtual ~TESUseWeaponPackageData();
    virtual void Copy(TESPatrolPackageData* source);
    virtual bool vf02(TESPackageData* other);
    virtual void vf03();
    virtual void InitItem(TESForm* item);
    virtual void SaveToBuffer(BGSSaveFormBuffer* buffer);
    virtual void vf06(BGSLoadFormBuffer* buffer);
    virtual void vf07(BGSLoadFormBuffer* buffer);

    PackageTargetRecord* m_pUseTarget;
    LocationDescriptor* m_pTargetLocation;
    bool m_bFlag1;
    bool m_bFlag2;
    bool m_bFlag3;
    bool m_bFlag4;
    bool m_bFlag5;
    bool m_bFlag6;
    unsigned short m_usValue1;
    unsigned short m_usValue2;
    unsigned short m_usValue3;
    float m_fValue1;
    float m_fValue2;
    TESObjectWEAP* pWeapon;

    TESUseWeaponPackageData* __thiscall InitializeFields_0067caa0();
    void* DestroyIfFlagged(unsigned int flags);
    void Copy(TESPackageData* source);
    void Copy_0067cd90(TESPackageData* apSource);
    bool Compare_0067cfc0(TESPackageData* apCompare);
    void Save_0067d350();
    void SaveGame_0067d550(BGSSaveFormBuffer* buffer);
    void LoadUseWeaponData(BGSLoadFormBuffer* buffer);
    void LoadForm(BGSLoadFormBuffer* apLoadGameBuffer);

    // Out-of-line accessors (HighProcess::ProcessUseWeapon); names from the UseWeapon package flags.
    PackageTargetRecord* GetTarget();         // 0x00726070: m_pUseTarget (+0x4)
    bool IsCrouch();                          // 0x008f9100: +0xe
    bool IsHoldFireWhenBlocked();             // 0x008f9120: +0xf
    bool IsVolleyFire();                      // 0x00833c20: +0x10
    bool GetRepeatFire();                     // 0x00824060: +0x11
    unsigned short GetBurstCount();           // 0x008f21d0: +0x12
    unsigned short GetVolleyShotsMin();       // 0x008f9140: +0x14
    unsigned short GetVolleyShotsMax();       // 0x008f9160: +0x16
    float GetVolleyWaitMin();                 // 0x004a7bd0: +0x18
    float GetVolleyWaitMax();                 // 0x00495460: +0x1c
};
