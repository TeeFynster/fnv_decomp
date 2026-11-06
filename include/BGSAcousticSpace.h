#pragma once

#include "TESBoundObject.h"

class TESSound;
class TESRegion;

enum CELL_ENVIRO_TYPE
{
    CELL_ENVIRO_TYPE_CET_NONE = 0,
    CELL_ENVIRO_TYPE_CET_DEFAULT = 1,
    CELL_ENVIRO_TYPE_CET_GENERIC = 2,
    CELL_ENVIRO_TYPE_CET_PADDEDCELL = 3,
    CELL_ENVIRO_TYPE_CET_ROOM = 4,
    CELL_ENVIRO_TYPE_CET_BATHROOM = 5,
    CELL_ENVIRO_TYPE_CET_LIVINGROOM = 6,
    CELL_ENVIRO_TYPE_CET_STONEROOM = 7,
    CELL_ENVIRO_TYPE_CET_AUDITORIUM = 8,
    CELL_ENVIRO_TYPE_CET_CONCERTHALL = 9,
    CELL_ENVIRO_TYPE_CET_CAVE = 10,
    CELL_ENVIRO_TYPE_CET_ARENA = 11,
    CELL_ENVIRO_TYPE_CET_HANGAR = 12,
    CELL_ENVIRO_TYPE_CET_CARPETEDHALLWAY = 13,
    CELL_ENVIRO_TYPE_CET_HALLWAY = 14,
    CELL_ENVIRO_TYPE_CET_STONECORRIDOR = 15,
    CELL_ENVIRO_TYPE_CET_ALLEY = 16,
    CELL_ENVIRO_TYPE_CET_FOREST = 17,
    CELL_ENVIRO_TYPE_CET_CITY = 18,
    CELL_ENVIRO_TYPE_CET_MOUNTAINS = 19,
    CELL_ENVIRO_TYPE_CET_QUARRY = 20,
    CELL_ENVIRO_TYPE_CET_PLAIN = 21,
    CELL_ENVIRO_TYPE_CET_PARKINGLOT = 22,
    CELL_ENVIRO_TYPE_CET_SEWERPIPE = 23,
    CELL_ENVIRO_TYPE_CET_UNDERWATER = 24,
    CELL_ENVIRO_TYPE_CET_SMALLROOM = 25,
    CELL_ENVIRO_TYPE_CET_MEDIUMROOM = 26,
    CELL_ENVIRO_TYPE_CET_LARGEROOM = 27,
    CELL_ENVIRO_TYPE_CET_MEDIUMHALL = 28,
    CELL_ENVIRO_TYPE_CET_LARGEHALL = 29,
    CELL_ENVIRO_TYPE_CET_PLATE = 30,
    CELL_ENVIRO_TYPE_CET_COUNT = 31
};

class BGSAcousticSpace : public TESBoundObject
{
public:
    bool m_bIsInterior;
    unsigned char layoutPadding31[3];
    TESSound* pDawnSound;
    TESSound* pNoonSound;
    TESSound* pDuskSound;
    TESSound* pNightSound;
    TESSound* pWallaSound;
    TESRegion* pRegion;
    CELL_ENVIRO_TYPE m_eCellEnvironmentType;
    int m_iFlags;

    BGSAcousticSpace();

    virtual void ClearData();
    virtual bool LoadForm(TESFile* modInfo);
    virtual void InitItem(void);

    void ResetFormData();
    bool Load(TESFile* file);
    void m_Virtual00();
    void m_Virtual04();
    void m_Virtual08();
    unsigned int Check(const char* string, int value1, int value2);

    void SetDawnSound(TESSound* apSound);
    void SetNoonSound(TESSound* apSound);
    void SetDuskSound(TESSound* apSound);
    void SetNightSound(TESSound* apSound);
    void SetWallaSound(TESSound* apSound);
    void SetRegion(TESRegion* apRegion);
    void SetListenerID(CELL_ENVIRO_TYPE aeType);
    bool GetByteAtOffset48();
    int GetField4C();
};
