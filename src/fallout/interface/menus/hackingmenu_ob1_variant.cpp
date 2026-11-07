#include "../../../../include/BSAudio.h"
#include "../../../../include/BSSoundHandle.h"
#include "../../../../include/FORenderedMenu.h"
#include "../../../../include/FORenderedTerminal.h"
#include "../../../../include/HackingMenu.h"
#include "../../../../include/SL.h"
#include "../../../../include/StrMem.h"
#include "../../../../include/Tile.h"

// src/fallout/interface/menus/hackingmenu_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/fallout/interface/menus/hackingmenu.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/interface/menus/hackingmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/hackingmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct PlaybackDevice
{
    BSSoundHandle __thiscall Play(unsigned int a, unsigned int b);
};

extern PlaybackDevice* __cdecl GetPlaybackDevice();

struct TlsBlock00ad7550
{
    unsigned int unk000, unk004, unk008, unk00c, unk010, unk014;
    unsigned int unk018, unk01c, unk020, unk024, unk028, unk02c;
    unsigned int unk030, unk034, unk038, unk03c, unk040, unk044;
    unsigned int unk048, unk04c, unk050, unk054, unk058, unk05c;
    unsigned int unk060, unk064, unk068, unk06c, unk070, unk074;
    unsigned int unk078, unk07c, unk080, unk084, unk088, unk08c;
    unsigned int unk090, unk094, unk098, unk09c, unk0a0, unk0a4;
    unsigned int unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    unsigned int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4;
    unsigned int unk0d8, unk0dc, unk0e0, unk0e4, unk0e8, unk0ec;
    unsigned int unk0f0, unk0f4, unk0f8, unk0fc, unk100, unk104;
    unsigned int unk108, unk10c, unk110, unk114, unk118, unk11c;
    unsigned int unk120, unk124, unk128, unk12c, unk130, unk134;
    unsigned int unk138, unk13c, unk140, unk144, unk148, unk14c;
    unsigned int unk150, unk154, unk158, unk15c, unk160, unk164;
    unsigned int unk168, unk16c, unk170, unk174, unk178, unk17c;
    unsigned int unk180, unk184, unk188, unk18c, unk190, unk194;
    unsigned int unk198, unk19c, unk1a0, unk1a4, unk1a8, unk1ac;
    unsigned int unk1b0, unk1b4, unk1b8, unk1bc, unk1c0, unk1c4;
    unsigned int unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    unsigned int unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4;
    unsigned int unk1f8, unk1fc, unk200, unk204, unk208, unk20c;
    unsigned int unk210, unk214, unk218, unk21c, unk220, unk224;
    unsigned int unk228, unk22c, unk230, unk234, unk238, unk23c;
    unsigned int unk240, unk244, unk248, unk24c, unk250, unk254;
    unsigned int unk258, unk25c, unk260, unk264, unk268, unk26c;
    unsigned int unk270, unk274, unk278, unk27c, unk280, unk284;
    unsigned int unk288, unk28c, unk290, unk294, unk298, unk29c;
    unsigned int unk2a0, unk2a4, unk2a8, unk2ac, unk2b0, tag2b4;
    unsigned int unk2b8;
};
extern __declspec(thread) TlsBlock00ad7550 g_tls00ad7550;

struct AudioTag
{
    static int Get()
    {
        return g_tls00ad7550.tag2b4;
    }
    static void Set(int value)
    {
        g_tls00ad7550.tag2b4 = value;
    }
};

struct TagScope
{
    int m_saved;
    TagScope()
    {
        m_saved = AudioTag::Get();
        AudioTag::Set(0xb);
    }
    ~TagScope()
    {
        AudioTag::Set(m_saved);
    }
};

struct SoundPlayback
{
    BSSoundHandle BSAudio_GetSoundHandleByEditorName(unsigned int a, unsigned int b);
};

// @fnv 0x00ad7550
// src: COMMUNITY 0x00ad7550
BSSoundHandle SoundPlayback::BSAudio_GetSoundHandleByEditorName(unsigned int a, unsigned int b)
{
    TagScope scope;
    return GetPlaybackDevice()->Play(a, b);
}
