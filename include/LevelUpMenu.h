#pragma once

#include "Menu.h"

struct Member64
{
    Member64();
    ~Member64();

    int fn_7e1110(Tile*);
    void fn_7314c0(void (__cdecl* callback)(Tile*), int, int);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct Member94
{
    Member94();
    ~Member94();

    bool fn_7877a0(Tile*);
    void fn_787780(Tile*);
    void fn_787850(bool);
    void fn_787760(Tile*);
    int fn_7878d0();
    void fn_7314c0(void (__cdecl* callback)(Tile*), int, int);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

template <class T> struct LevelUpOwnedList
{
    T item;
    LevelUpOwnedList* next;

    LevelUpOwnedList();
    ~LevelUpOwnedList();
};

class LevelUpMenu : public Menu
{
public:
    LevelUpMenu();
    virtual ~LevelUpMenu();
    virtual void AssignTileByID(int, Tile*);
    virtual void HandleSelection(int, Tile*);
    virtual void HandleMouseover(unsigned int, Tile*);
    virtual void UpdateDialog();
    virtual int GetClass();
    virtual bool HandleMenuInput(int, float);
    virtual bool HandleControllerInput(int, Tile*);

    void RefreshNetworkState();
    void PlayLevelUpSuccessSound();
    void OnButtonPressed(int, Tile*);
    void fn_7867a0(Tile*);
    Tile* fn_726070();
    void fn_785990();
    void fn_7866e0(Tile*);
    void fn_785830(int);

    union
    {
        unsigned char layoutExtension[0x3C];
        struct
        {
            int unk28;
            Tile* unk2c;
            Tile* unk30;
            Tile* unk34;
            Tile* unk38;
            Tile* unk3c;
            Tile* unk40;
            Tile* unk44;
            Tile* unk48;
            Tile* unk4c;
            Tile* unk50;
            int unk54;
            int unk58;
            int unk5c;
            int unk60;
        };
    };
    Member64 unk64;
    Member94 unk94;
    LevelUpOwnedList<void*> unkC4;
};
