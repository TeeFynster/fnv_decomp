#pragma once

#include "Menu.h"

class Tile;
class AVObj;
class CtrlObj;

class SlotMachineMenu : public Menu
{
public:
    struct SlotNiPointer
    {
        void* m_pObject;
        ~SlotNiPointer();
        SlotNiPointer& operator=(void* obj);
    };

    SlotMachineMenu();
    virtual ~SlotMachineMenu();
    virtual void AssignTileByID(int, Tile*);
    virtual void HandleSelection(int, Tile*);
    virtual void UpdateDialog();
    virtual int GetClass();

    union
    {
        unsigned char layoutExtension[0x130];
        struct
        {
            union { int state; int m_uiContentCount; };
            union
            {
                int symbols[28];
                int sourceValues[10];
            };
            union { int result; int m_result; };
            union { Tile* tile; Tile* tilea0; };
            union { Tile* tilea4; Tile* m_a4; };
            union { Tile* tilea8; Tile* m_tile; };
            Tile* tileac;
            Tile* tileb0;
            Tile* tileb4;
            Tile* tileb8;
            Tile* tilebc;
            Tile* tilec0;
            union { Tile* tilec4; Tile* m_c4; };
            union { int iTolerance; int stat; };
            union { int bet; int wager; int m_bet; };
            union { int valueCount; int count; int iValueCount; };
            union { int funds; int m_caps; };
            union { bool won; bool bChanged; bool m_d8; };
            unsigned char unkD9[3];
            union { int savedResults[3]; int previous[3]; int saved[3]; };
            union { int currentResults[3]; int current[3]; int m_aiValues[3]; int reels[3]; int m_e8; };
            int m_lastTime;
            unsigned char m_f8;
            unsigned char unkF9[3];
            int soundIndex;
            union { bool loading; unsigned char m_100; };
            unsigned char unk101[3];
            union { AVObj* m_104; void* machine; };
            union
            {
                AVObj* m_108[3];
                void* m_reels[3];
                struct { void* reel1; void* reel2; void* reel3; };
            };
            SlotNiPointer m_reelNodes[8];
            CtrlObj* m_134;
            CtrlObj* m_138;
            CtrlObj* m_13c;
            CtrlObj* m_140;
            CtrlObj* m_144;
            union { CtrlObj* m_148[3]; void* m_reelControllers[3]; };
            unsigned char unk154[4];
        };
        struct
        {
            unsigned char unk28[0x78];
            Tile* m_pTiles[40];
            unsigned char unk140[0x18];
        };
    };

    void SetTile(int id, Tile* tile);
    int GetMenuID_007c0800();
    char HasAllTenTiles();
    bool InitReels();
    bool LoadAssets();
    void InitPayoutMenu();
    void* BlackJackMenu_SetupCamera();
    void DoClick_007c2460(int, void*);
    void Update();
    void SwapBackfacingTextures();
    void SwapFrontfacingTextures();
    void SelectSpinResults();
    int InterpretSpin();
    bool AdjustReels(int);
    void UpdateTileText();
    int GetMode();
    Tile* GetMenuTile();
    void Refresh();
    int SpinResult();
    void UpdateReels();
    void StartSpin();
    void StopReels();
    void Unused0();
    void Unused1();
};
