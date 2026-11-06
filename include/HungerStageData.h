#pragma once

class SpellItem;

class HungerStageData
{
public:
    HungerStageData();
    void Reinitialize();

    unsigned int m_uiStageLevel;
    SpellItem* m_pSpell;
};
