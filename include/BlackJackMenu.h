#pragma once

#include "Menu.h"
#include "NiAVObject.h"

class NiNode;
class NiSourceTexture;
class NiControllerManager;
class NiControllerSequence;

class BlackJackMenu : public Menu
{
public:
    struct Card
    {
        union { int rank; int m0; int unk00; };
        union { int suit; int m4; int unk04; };
        NiPointer<NiSourceTexture> p8;
        NiPointer<NiSourceTexture> pC;

        Card();
        ~Card();
        Card& operator=(const Card&);
    };

    typedef Card CardInfo;
    typedef BSSimpleList<Card*> CardHand;

    union
    {
        unsigned char layoutExtension[0xE48];
        struct
        {
            unsigned char unk28[0xC];
            Tile* m_pTiles[40];
            unsigned char unkD4[0xD9C];
        };
        struct
        {
            int state;
            union { int result; int playerResult; int _handResult0; };
            union { int splitResult; int _handResult1; };
            Tile* tile34;
            Tile* tile38;
            union { Tile* message; Tile* m_tile; };
            Tile* tile40;
            Tile* tile44;
            Tile* tile48;
            Tile* tile4C;
            Tile* tile50;
            Tile* tile54;
            Tile* text;
            int unk5C;
            union { float f60; float payoutMultiplier; };
            union { float f64; float shuffleThreshold; };
            union { int setting; int skill; };
            int bet;
            int splitBet;
            union { int funds; int balance; };
            union { bool flag78; bool luckyWin; };
            union { bool flag79; bool luckyLose; };
            unsigned char unk7A[2];
            union { int m7C; int lastTime; };
            union { unsigned char b80; bool reward; };
            unsigned char unk81[3];
            union { int arr84[3]; int counts[3]; };
            Card cards[208];
            union { CardHand* dealer; CardHand* _dealerHand; CardHand* m_d90; };
            union { CardHand* hand; CardHand* player; CardHand* _playerHand; CardHand* m_d94; };
            union { CardHand* split; CardHand* m_d98; };
            union { int m_d9c; int decks; };
            union { int m_da0; int remaining; };
            bool sounded;
            unsigned char unkDA5[3];
            float soundTime;
            union { unsigned char b_dac; bool standSoft17; };
            unsigned char unkDAD[3];
            union { int _flags; int flags; };
            union { NiAVObject* m_pTreeNode; NiNode* rootdb4; NiNode* m_db4; NiAVObject* root; };
            union { NiAVObject* m_pCardObject1; NiNode* rootdb8; NiAVObject* table; };
            union { NiAVObject* m_pCardObject2; NiNode* rootdbc; NiAVObject* splitHand; };
            union { NiAVObject* m_pCardObject3; NiNode* rootdc0; NiAVObject* dealerHand; };
            union
            {
                NiAVObject* apChips[12];
                struct
                {
                    NiNode* arrDC4[6];
                    NiNode* arrDDC[6];
                };
            };
            union { NiControllerManager* ctrldf4; NiControllerManager* tableAnim; };
            union { NiControllerManager* ctrldf8; NiControllerManager* playerAnim; };
            union { NiControllerManager* ctrldfc; NiControllerManager* splitAnim; };
            union { NiControllerManager* ctrle00; NiControllerManager* dealerAnim; };
            union { NiControllerSequence* anime04; NiControllerSequence* tableStart; };
            union { NiControllerSequence* anime08; NiControllerSequence* tableEnd; };
            union
            {
                NiControllerSequence* playerSeq[8];
                struct
                {
                    NiControllerSequence* anime0c;
                    NiControllerSequence* anime10;
                    NiControllerSequence* anime14;
                    NiControllerSequence* anime18;
                    NiControllerSequence* anime1c;
                    NiControllerSequence* anime20;
                    NiControllerSequence* anime24;
                    NiControllerSequence* anime28;
                };
            };
            union
            {
                NiControllerSequence* splitSeq[8];
                struct
                {
                    NiControllerSequence* anime2c;
                    NiControllerSequence* anime30;
                    NiControllerSequence* anime34;
                    NiControllerSequence* anime38;
                    NiControllerSequence* anime3c;
                    NiControllerSequence* anime40;
                    NiControllerSequence* anime44;
                    NiControllerSequence* anime48;
                };
            };
            union
            {
                NiControllerSequence* dealerSeq[8];
                struct
                {
                    NiControllerSequence* anime4c;
                    NiControllerSequence* anime50;
                    NiControllerSequence* anime54;
                    NiControllerSequence* anime58;
                    NiControllerSequence* anime5c;
                    NiControllerSequence* anime60;
                    NiControllerSequence* anime64;
                    NiControllerSequence* anime68;
                };
            };
            union { NiControllerSequence* anime6c; NiControllerSequence* revealSeq; };
        };
    };

    BlackJackMenu();
    virtual ~BlackJackMenu();
    virtual void AssignTileByID(int, Tile*);
    virtual void HandleSelection(int, Tile*);
    virtual void UpdateDialog();
    virtual int GetClass();

    void SetTile(int aiID, Tile* apTile);
    int __thiscall GetMenuID_00731790();
    void ClearField();
    int __thiscall HasFlag(int flag);
    bool HasFlag(unsigned int flag);
    void SetFlag(int flag, bool value);
    void* __thiscall DestroyIfFlagged(unsigned int flags);
    char __thiscall BlackJackMenu_HasTiles();
    int GetAdjustedValue(int value);
    bool LoadCardDeckResources();
    void InitBlackjackScene();
    void HandleAction(int action, void* tile);
    void UpdateButtonState(int button);
    void UpdateTileText();
    void DealInitialCards();
    int DrawCard(void* hand, bool useSkill, bool split);
    int DrawCard(CardHand* hand, bool useSkill, bool split);
    int DrawCard(int hand, int useSkill, int split);
    int DrawCard(CardHand* hand, int useSkill, int split);
    int BlackJackMenu_GetHandValue(CardHand* hand);
    int HandValue(void* hand);
    int CardValue(int rank);
    void Shuffle();
    bool BlackJackMenu_CanSplitHand();
    bool BlackJackMenu_CanDoubleDown(bool split);
    void BlackJackMenu_SwapCardTextures(int hand, int index, Card* card);
    void BlackJackMenu_SetTileTextAlpha(int index, float value);
    void BlackJackMenu_SetSideHandVisibility(int index);
    void BlackJackMenu_SetSideHandVisibility(bool split);
    void BlackJackMenu_Shuffle();
    void BlackJackMenu_HighlightSelectedDeck();
    void UpdateChipPositions();
    void UpdateCulledNodes();
    void UncullCardObjects();
    void HideArrowNodes();
    NiNode* BlackJackMenu_SetupCamera();
    void BlackJackMenu_DoIdle();
    int GetID();
    int FUN_0059bb30();
    void FUN_00a1d910();
};
