#pragma once

class SpellItem;

class WeaponCriticalData
{
public:
    unsigned short m_usCriticalDamage;
    unsigned char layoutPadding2[2];
    float m_fCriticalChanceMultiplier;
    bool m_bEffectOnDeath;
    unsigned char layoutPadding9[3];
    SpellItem* pEffect;

    void SwapEndianness();
    void OBJ_WEAP_CRITICAL_Endian();  // 0x00535aa0: the CRDT endian swap TESObjectWEAP::LoadForm calls
};
