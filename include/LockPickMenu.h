#pragma once

#include "Menu.h"
#include "NiPoint3.h"
#include "NiMatrix3.h"

class NiControllerSequence;
class NiControllerManager;
class TESObjectREFR;
class PickWrapper;

class LockPickMenu : public Menu
{
public:
    virtual ~LockPickMenu();
    virtual void AssignTileByID(int, Tile*);
    virtual void HandleLeftClickPress(unsigned int, Tile*);
    virtual void HandleSelection(int, Tile*);
    virtual void HandleMouseover(unsigned int, Tile*);
    virtual void HandleMouseoverTileAlt(unsigned int, Tile*);
    virtual void PostDragTileChange(unsigned int, Tile*, Tile*);
    virtual void PreDragTileChange(unsigned int, Tile*, Tile*);
    virtual void HandleActiveMenuClick(unsigned int, Tile*);
    virtual void OnClickHeld(unsigned int, Tile*);
    virtual void HandleMousewheel(unsigned int, Tile*);
    virtual void UpdateDialog();
    virtual bool HandleKeyboardInput(unsigned int);
    virtual int GetClass();
    virtual bool HandleMenuInput(int, float);
    virtual bool HandleControllerInput(int, Tile*);
    virtual void OnUpdateUserTrait(int);
    virtual void HandleControllerConnectOrDisconnect(bool);

    union
    {
        unsigned char layoutExtension[0xBC];
        struct
        {
            int m_28;
            union
            {
                Tile* m_pTiles[16];
                struct
                {
                    Tile* m_pkSkillTile;
                    Tile* m_30;
                    Tile* m_pkLevelTile;
                    Tile* unk38;
                    Tile* unk3c;
                    Tile* unk40;
                    Tile* unk44;
                    Tile* unk48;
                    Tile* unk4c;
                    Tile* m_pkSkillLabel;
                    Tile* m_pkLevelLabel;
                    Tile* m_58;
                    Tile* m_5c;
                    Tile* unk60;
                    Tile* m_64;
                    Tile* m_68;
                };
            };
            TESObjectREFR* m_6c;
            int m_70;
            int m_74;
            float m_78;
            int m_7c;
            int m_80;
            float m_84;
            int m_88;
            float m_8c;
            float m_90;
            float m_94;
            bool m_98;
            bool m_99;
            unsigned char unk9A[2];
            NiControllerSequence* m_9c;
            NiControllerSequence* m_a0;
            NiControllerManager* m_a4;
            NiControllerSequence* m_a8;
            NiControllerSequence* m_ac;
            NiControllerSequence* m_b0;
            NiMatrix3 rotation;
            NiPoint3 position;
        };
    };

    LockPickMenu();
    int GetClass_0078da90();
    void SetTile(int id, Tile* tile);
    void* FUN_0078dad0(unsigned int flags);
    void DoEnter_007902b0(int, Tile*);
    void DoLeave_007902f0(int, Tile*);
    void HandleLockPickAction(int aiCode, int aiUnused);
    void UpdateLockRotation(float amount);
    void AdvanceSequence(float afDelta);
    void RotateLockpick();
    bool LockPickMenu_IsTurningLock(bool);
    void UpdateSweetSpot();
    void InitLockInterface();
    void* Create3DCamera();
    bool LockPickMenu_HasTiles();
    void DoIdle_0078eb50();
    void FUN_00a1d910();
    int FUN_0059bb30();
    PickWrapper* FUN_00726070(Tile*, const char*, int);
    using Menu::FUN_00726070;
};
