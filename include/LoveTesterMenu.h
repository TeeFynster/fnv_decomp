#pragma once

#include "Menu.h"
#include "NiAVObject.h"

class NiSourceTexture;
class ModelOps;
class ClickNode;
class Cb_WM;
class Lvl_WM;
class Scene109;
class Digit109;
class Button109;
class Label109;

// LoveTesterMenu (FNV menu class 1074): ctor 0x00720550 installs vftable 0x01070174; MenuSystem::GetMenuById
// allocates 0x230 (the ctor's last arrays end at +0x230). The old 0x4014 was RouletteMenu's (ctor 0x007b8d30).
class LoveTesterMenu : public Menu
{
public:
    class LoveTesterTextItem; // exe RTTI: BSSimpleArray<LoveTesterMenu::LoveTesterTextItem*,1024>
    virtual ~LoveTesterMenu();
    virtual void HandleSelection(int, Tile*);
    virtual void UpdateDialog();
    virtual bool HandleKeyboardInput(unsigned int);
    virtual int GetClass();
    virtual bool HandleMenuInput(int, float);

    struct ClickArray
    {
        int count, capacity, data, grow;
        unsigned int FUN_0044ddc0();
        ClickNode** BSSimpleArray_NiAVObject_1024_GetAt(unsigned int);
        void FUN_008454f0(bool);
    };

    struct ClickGroup
    {
        ClickArray objects, allocations;
    };

    struct CbArr_WM
    {
        int a, b, c, d;
        unsigned int FUN_0044ddc0();
        Cb_WM*& BSSimpleArray_NiAVObject_1024_GetAt(unsigned int);
    };

    struct Pair_WM
    {
        CbArr_WM a, b;
    };

    struct LvlArr_WM
    {
        int a, b, c, d;
        unsigned int FUN_0044ddc0();
        Lvl_WM*& BSSimpleArray_NiAVObject_1024_GetAt(unsigned int);
    };

    struct DigitList109
    {
        int unk00, unk04, unk08, unk0C;
        void FUN_007cb2e0(Digit109* const&);
    };

    struct ButtonList109
    {
        int unk00, unk04, unk08, unk0C;
        void FUN_007cb2e0(Button109* const&);
    };

    struct LabelList109
    {
        int unk00, unk04, unk08, unk0C;
        void FUN_007cb2e0(Label109* const&);
    };

    union
    {
        unsigned char layoutExtension[0x208];
        struct
        {
            int unk28;
            int unk2C;
            int unk30;
            int unk34;
            int unk38;
            int unk3C;
            int unk40;
            int unk44;
            union
            {
                int unk48;
                int position;
                int mode;
                int idx;
                int animationIndex;
                int iMode;
            };
            union
            {
                int unk4C;
                int special;
            };
            union
            {
                int unk50;
                float time;
                float elapsed;
            };
            union
            {
                int unk54;
                struct
                {
                    union
                    {
                        bool m_bState54;
                        bool finished;
                    };
                    unsigned char unk55[3];
                };
            };
            union
            {
                int unk58;
                int m_iEntryCount;
                int available;
                int availablePoints;
                int m_iMaximumCount;
            };
            union
            {
                unsigned int counter5c;
                int u5c;
                Scene109* front;
                ModelOps* model;
                NiAVObject* root;
            };
            union
            {
                unsigned int counter60;
                int u60;
                Scene109* cabinet;
            };
            union
            {
                LvlArr_WM arr64;
                ClickArray list64;
            };
            union
            {
                LvlArr_WM arr74;
                ClickArray list74;
                DigitList109 digits;
            };
            union
            {
                ClickGroup groups[9];
                Pair_WM pairs[9];
                struct
                {
                    ButtonList109 misc;
                    unsigned char unk94[0xF0];
                    ButtonList109 adjustments;
                    LabelList109 values;
                };
            };
            union
            {
                CbArr_WM arr1a4;
                ClickArray list1a4;
                ButtonList109 controls;
            };
            union
            {
                CbArr_WM arr1b4;
                ClickArray list1b4;
                LabelList109 totals;
            };
            NiPointer<NiSourceTexture> tex[27];
        };
    };

    LoveTesterMenu();
    bool InitializeCollection(int* missingIndex);
    void Setup();
    void* GetNode();
    void StepPosition(int);
    bool StepPosition(bool increase);
    bool HandleKeyInput(int key);
    void HandleButton(int button, int unused);
    void HandleClick(int id, int unused);
    bool HandleMenuKey(int key, int unused);
    void UpdateAnimation();
    int GetSelectedIndex();
    int GetCount();
    void Init();
    int LoveTesterMenu_GetCurrentStatesActorValue();
    int SPECIALBookMenu_GetTotalPointsUsed();
    void RefreshPage();
    void VigorTester_InitTextures();
    void FUN_00a1d910();
};
