#pragma once

#include "Menu.h"
#include "BSSoundHandle.h"

class Actor;
class TESTopic;

// CompanionWheelMenu (FNV menu class 1075): ctor 0x00754b40 installs vftable 0x01071d0c; MenuSystem::GetMenuById
// allocates 0x88. Offsets from the ctor, the tile setter 0x00754c00 (index 0..15 into +0x28) and companionwheelmenu.cpp
// (the four toggles 0x007560c0/0x007561b0/0x007562b0/0x007563a0 flip the bytes at +0x6c..+0x6f).
class CompanionWheelMenu : public Menu
{
public:
    CompanionWheelMenu();
    virtual ~CompanionWheelMenu();
    virtual void HandleSelection(int aiID, Tile* apTarget);  // 0x007552e0
    virtual void UpdateDialog();  // 0x00755480: clears the text tile at its timeout, steers the wheel by the stick
    virtual int GetClass();
    virtual bool HandleMenuInput(int aiInput, float afValue);  // 0x007556b0

    void SelectTile(int aiTile, bool abForce);  // 0x007557d0
    void SetButtonAsHighlighted(float afAngle);           // selects the tile under the stick angle
    void SetTileText(const char* apText);       // 0x00755d90
    void ToggleFollowersTacticsDistance();      // 0x007560c0
    void ToggleRelatedTopic();                  // 0x007562b0
    void ToggleFollowerWait();                  // 0x007563a0
    void ToggleAggressive();                    // 0x007561b0
    void HealCompanion();                       // 0x00756490
    void CompanionWheelMenu_Do_OpenInventory();
    void Do_Backup();                        // opens the companion's dialogue and closes the wheel
    void UpdateCompanionInteraction();          // 0x00756980
    void PlayTopicResponse(TESTopic* apTopic);  // 0x007573d0
    void RunTopicResultScripts(TESTopic* apTopic);  // 0x007575b0

    Tile* tiles[16];               // +0x28
    Actor* companion;              // +0x68
    bool followersTacticsDistance; // +0x6c, toggled by 0x007560c0
    bool aggressive;               // +0x6d, toggled by 0x007561b0
    bool relatedTopicVisible;      // +0x6e, toggled by 0x007562b0
    bool followerWait;             // +0x6f, toggled by 0x007563a0
    int selected;                  // +0x70, -1 in the ctor; the selected tile index (SelectTile 0x007557d0)
    bool unk74;                    // +0x74, 0 in the ctor
    unsigned int textClearTime;    // +0x78, tick count at which UpdateDialog clears tile 12's text (set by 0x00757690)
    BSSoundHandle sound;     // +0x7c, built by 0x0041a250
};
