
// src/fallout/ai/middlehighprocess_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/middlehighprocess.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "middlehighprocess_decls.h"
bool IsValidSandboxProcedure(int aiProcedure);

struct C69FC0State
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int flags;
};
struct C69FC0Packet
{
    unsigned int status;
    unsigned char mode;
    unsigned int opcode;
    unsigned int selection;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
};
C69FC0State* __cdecl GetExtraDataChecked(int object);
void __cdecl bhkWorld_DoObjectRec(int object, C69FC0Packet* packet, unsigned int dispatcher);
extern unsigned int DAT_011afebc;

static inline unsigned int C69FC0IsEnabled(int object)
{
    C69FC0State* pkState = GetExtraDataChecked(object);
    return pkState ? (pkState->flags & 2) : 0;
}

// @fnv 0x00c69fc0
// src: COMMUNITY 0x00c69fc0
bool __cdecl _bhkWorld_AdjustForceAddCount(int object, unsigned char bSelect, unsigned char mode, unsigned char overrideCheck)
{
    bool bResult = false;
    if (object)
    {
        if (overrideCheck || C69FC0IsEnabled(object))
        {
            bResult = true;
            C69FC0Packet kPacket;
            kPacket.status = 0;
            kPacket.mode = mode;
            kPacket.opcode = 0xd;
            kPacket.selection = bSelect != 0;
            if (DAT_011afebc)
                bhkWorld_DoObjectRec(object, &kPacket, DAT_011afebc);
        }
    }
    return bResult;
}
