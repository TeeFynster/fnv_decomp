#pragma once

class SpellItem;

class WeaponVATSData
{
public:
    SpellItem* m_pVATSAttackSpell;
    float m_fSkill;
    float m_fDamageMultiplier;
    float m_fActionPointCost;
    bool bSilent;
    bool m_bModRequired;
    unsigned char cFlags;
    unsigned char layoutPadding13[1];

    void OBJ_WEAP_VATS_SPECIAL_Endian();  // 0x0067ff10: the VATS endian swap TESObjectWEAP::LoadForm calls
};
