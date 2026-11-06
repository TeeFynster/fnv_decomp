#pragma once

#include "Menu.h"
#include "NiAVObject.h"
#include "NiPoint2.h"
#include "NiPoint3.h"
#include "NiMatrix3.h"
#include "BSSoundHandle.h"

class NiNode;

// SurgeryMenu (FNV menu class 1054): ctor 0x0071fbf0 installs vftable 0x01070084; MenuSystem::GetMenuById allocates
// 0x160. Members from the ctor: empty-ctor objects (0x006815c0: NiPoint2/NiPoint3/NiMatrix3) at +0x74, +0x7c,
// +0xf8, +0x104, +0x128, +0x150 sized by the gaps between them; SoundPlaybackHandles (0x0041a250) at +0x94/+0xa0;
// NiPointer<NiNode>[6] at +0xc8 and two at +0xf0/+0xf4; the tile setter 0x0071ffe0 stores ids 1..18 into +0x2c.
class SurgeryMenu : public Menu
{
public:
    class PerkEntryHandler
    {
    public:
        void RefreshPerkState();
    };

    SurgeryMenu();
    virtual ~SurgeryMenu();

    static void __cdecl UpdatePerkEntries();

    int unk28;                       // +0x28, 0 in the ctor
    Tile* tiles[18];                 // +0x2c
    NiPoint2 unk74;                  // +0x74
    NiPoint2 unk7C;                  // +0x7c
    float unk84;                     // +0x84
    int unk88;                       // +0x88
    int unk8C;                       // +0x8c
    bool unk90;                      // +0x90
    bool unk91;                      // +0x91
    BSSoundHandle sound94;     // +0x94
    BSSoundHandle soundA0;     // +0xa0
    float unkAC;                     // +0xac
    int unkB0;                       // +0xb0
    int unkB4;                       // +0xb4
    int unkB8;                       // +0xb8
    int unkBC;                       // +0xbc
    int unkC0;                       // +0xc0, 0x1b in the ctor
    int unkC4;                       // +0xc4, 1 in the ctor
    NiPointer<NiNode> nodes[6];      // +0xc8
    int unkE0;                       // +0xe0
    int unkE4;                       // +0xe4
    int unkE8;                       // +0xe8
    float unkEC;                     // +0xec
    NiPointer<NiNode> nodeF0;        // +0xf0
    NiPointer<NiNode> nodeF4;        // +0xf4
    NiPoint3 unkF8;                  // +0xf8
    NiMatrix3 unk104;       // +0x104
    NiMatrix3 unk128;       // +0x128
    float unk14C;                    // +0x14c
    NiPoint3 unk150;                 // +0x150
    bool unk15C;                     // +0x15c
    bool unk15D;                     // +0x15d
};
