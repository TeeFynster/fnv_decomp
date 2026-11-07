#pragma once

class TESObjectREFR;
class BooleanFloatQuery;
class HitData;

class VATSCommand
{
public:
    void Initialize();
    void VATS_COMMAND_Initialize();
    ~VATSCommand();

    int eAction;
    bool bSuccess;
    bool m_kFieldAfterWeaponFlags;
    bool m_bFirstActionFlag;
    bool m_bSecondActionFlag;
    unsigned char m_ucFirstActionCode;
    unsigned char m_ucSecondActionCode;
    char _pad_a[2];
    TESObjectREFR* pTarget;
    int m_iActionValue;
    HitData* m_pActionObject; // src: XBOX_PDB (name HitData); VATSCommand::Initialize 0x009c8c40 news one here
    float m_fArmorDamage;
    float m_fHealthDamage;
    float m_fOverrideActionPoints;
    bool m_bFinalActionFlag;
    char _pad_25[3];
};
