#pragma once

#include "Menu.h"

class AnimCtrl;
class AnimSeq;
class BSSimpleListTESRaceSize;
class NiAVObject;
class NiNode;

class RouletteMenu : public Menu
{
public:
    struct ListNode
    {
        void* pItem;
        ListNode* pNext;

        int* FUN_006815c0();
        ListNode* FUN_00726070();
        void FUN_0063f7b0();
    };

    struct BetSlot
    {
        ListNode kNumbers;
        int unk08;
        int iOdds;
        int unk10;
        int unk14;
        int unk18;
        char szNodeName[8];
        char szLabel[64];
    };

    virtual ~RouletteMenu();
    virtual void AssignTileByID(int, Tile*);
    virtual void HandleSelection(int, Tile*);
    virtual void HandleMouseover(unsigned int, Tile*);
    virtual void HandleMouseoverTileAlt(unsigned int, Tile*);
    virtual void UpdateDialog();
    virtual int GetClass();

    union
    {
        unsigned char layoutExtension[0x64];
        Tile* m_pTiles[44];
        struct
        {
            union { int m_iFadeIndex; int unk0028; };
            Tile* m_pMaxBetTile;
            Tile* m_pChipsTile;
            unsigned char unk34[0x1C];
            Tile* m_pInfoTile;
            Tile* m_pBetTile;
            int m_iLastTime;
            union
            {
                BetSlot m_aSlots[159];
                struct
                {
                    unsigned char unk5C[0x10];
                    int unk006c;
                };
            };
            union
            {
                ListNode* m_pBets;
                BSSimpleListTESRaceSize* unk3e78;
            };
            int m_aiPocketNumbers[38];
            NiAVObject* m_pRouletteWheel;
            NiAVObject* m_pTableNode;
            union { int m_iNode; int unk3f1c; };
            NiAVObject* tilesA[10];
            NiAVObject* tilesB[10];
            NiAVObject* m_pHighlight;
            NiAVObject* m_pValidMarker;
            NiAVObject* m_pInvalidMarker;
            int unk3F7C;
            AnimCtrl* m_pAnimCtrl;
            union
            {
                AnimSeq* m_apSpinSeq[20];
                struct
                {
                    void* spin1;
                    void* spin2;
                    void* spin3;
                    float unk3F90;
                    float m_afRadius[16];
                };
            };
            union { float m_fCursorX; int unk3fd4; };
            union { float m_fCursorY; int unk3fd8; };
            union { float m_fCursorZ; int unk3fdc; };
            union { int m_iChipNode; int unk3fe0; };
            union { int m_iChipCount; int unk3fe4; };
            union { int m_iBet; int unk3fe8; };
            union { int m_iTotalBet; int unk3fec; };
            union { int m_iChips; int unk3ff0; };
            int unk3FF4;
            int unk3FF8;
            union { int m_iMinBet; int unk3ffc; };
            union { int m_iMaxBet; int unk4000; };
            int m_iResult;
            int m_iRouletteResult;
            bool m_bSpinning;
            bool m_bSingular;
            bool m_b400e;
            bool m_bLimitUp;
            int m_iForceWin;
        };
    };

    RouletteMenu();
    void SetTile(int id, Tile* tile);
    void __thiscall FUN_007b9020();
    void* __thiscall Destroy(unsigned int flags);
    bool SetBet(int);
    bool IsEyesListBelowThreshold(int);
    void ApplyValueToChain(int, float);
    bool RemoveEntryById(int);
    void HandleRouletteInput(int, Tile*);
    char HasAllTiles();
    void SetTileValue(int, Tile*);
    void RotateRouletteWheelToResult(int);
    void ResetSlotTransform(int);
    void UpdateBetTileText();
    void InitRouletteScene();
    void InitRouletteWheel();
    int GetBetIndex();
    void SpinWheel();
    void ResetBetChips();
    void SetBetChip();
    void DoEnter_007bed00(int, Tile*);
    void DoIdle_007bd2a0();
    int GetMenuID_007b8f30();
    void DestroyFields_007b9000();
    NiNode* BlackJackMenu_SetupCamera();
    int FUN_0059bb30();
    Tile* FUN_00726070();
    void FUN_00a1d910();
};
