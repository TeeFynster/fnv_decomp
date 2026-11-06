#pragma once

#include "BaseFormComponent.h"
#ifndef TESMODELTEXTURESWAP_WORKER_DECLS_H
#include "TESForm.h"
#endif

class TESForm;

class BGSMenuIcon;

class BGSEquipType : public BaseFormComponent
{
public:
    enum EQUIP_TYPE
    {
        ET_NONE = -1,
        ET_BIG_GUN = 0,
        ET_ENERGY_WEAPON = 1,
        ET_SMALL_GUN = 2,
        ET_MELEE_WEAPON = 3,
        ET_UNARMED_WEAPON = 4,
        ET_THROWN_WEAPON = 5,
        ET_MINE = 6,
        ET_BODY_WEAR = 7,
        ET_HEAD_WEAR = 8,
        ET_HAND_WEAR = 9,
        ET_CHEMS = 10,
        ET_STIMPACK = 11,
        ET_FOOD = 12,
        ET_ALCOHOL = 13,
        ET_COUNT = 14
    };

    EQUIP_TYPE m_eEquipType;

    BGSEquipType();
    BGSEquipType& operator=(const BGSEquipType& other);

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);

    void InitializeComponent();
    void ClearComponent();
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);

    void Save();
    static EQUIP_TYPE GetEquipType(TESForm* form);
    int GetEquipType();
    void SetEquipType(EQUIP_TYPE type);
    void SetEquipType(int type);
    static BGSMenuIcon* GetEquipTypeIcon(EQUIP_TYPE type);
    static BGSMenuIcon* GetEquipTypeIcon(int type);
    static const char* GetEquipTypeName(EQUIP_TYPE type);
    static char* GetEquipTypeName(int type);
    static void GenerateDefaultMenuIcons();
};

typedef BGSEquipType::EQUIP_TYPE BGSEquipType__EQUIP_TYPE;
