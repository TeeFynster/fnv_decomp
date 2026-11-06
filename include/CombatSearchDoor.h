#pragma once

class CombatSearchDoor
{
public:
    char pad[0x0A];
    bool bReserved; // +0xa (0x0098c780)
    unsigned char pad0B; // 12 bytes: BSSimpleArray<CombatSearchDoor>::SetSize 0x0069cea0 scales by 0xc (src: XBOX_PDB size 12)
};
