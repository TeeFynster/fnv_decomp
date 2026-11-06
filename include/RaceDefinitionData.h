#pragma once

class WeaponSkillEntry
{
public:
    char m_eWeaponSkill;
    char m_cBonus;
};

class RaceDefinitionData
{
public:
    WeaponSkillEntry m_kSkillBonuses[7];
    float m_fGlyphExtent[2];
    float fWeight[2];
    int iFlags;
    void SwapEndian();
};
