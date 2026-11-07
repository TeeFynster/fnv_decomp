#include "../../../include/BSStringT.h"
#include "../../../include/TESSaveLoadGame.h"

// src/fallout/dialogue/dialogueresponse.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/dialogue/dialogueresponse.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_0083d420_shell
{
    unsigned char Length_Thunk();
    unsigned short ProcessAndReturnValue_0083d420();
};

// Sums the sizes returned by two FUN_0083d890 calls plus one each, then adds 8, and returns the total.
// @fnv 0x0083d420
// src: GUESS 0x0083d420 (confidence: low)
unsigned short FUN_0083d420_shell::ProcessAndReturnValue_0083d420()
{
    unsigned short result = 0;
    unsigned char b2 = Length_Thunk();
    result += (unsigned short)b2 + 1;
    unsigned char b1 = ((FUN_0083d420_shell*)((char*)this + 0x10))->Length_Thunk();
    result += (unsigned short)b1 + 1;
    result += 4;
    result += 4;
    return result;
}

struct S7010
{
    unsigned int Length();
};

struct FUN_0083d890_shell : S7010
{
    unsigned int Length_Thunk();
};

// @fnv 0x0083d890
// src: GUESS 0x0083d890 (confidence: medium)
unsigned int FUN_0083d890_shell::Length_Thunk()
{
    return Length();
}

extern TESSaveLoadGame* g_TESSaveLoadGame;

struct Flt
{
    operator unsigned int() const;
};

struct FUN_0083d490_shell : FUN_0083d420_shell
{
    void SaveToGame();
};

// Writes two length-prefixed byte blocks from this and this+0x10, then the 4-byte values at offsets 8 and 0xc, to the save game stream.
// @fnv 0x0083d490
void FUN_0083d490_shell::SaveToGame()
{
    unsigned char c1 = Length_Thunk();
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&c1, 1);
    if (c1)
        g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD((void*)(unsigned int)((Flt*)this)->operator unsigned int(), c1);
    unsigned char c2 = ((FUN_0083d420_shell*)((char*)this + 0x10))->Length_Thunk();
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&c2, 1);
    if (c2)
        g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD((void*)(unsigned int)((Flt*)((char*)this + 0x10))->operator unsigned int(), c2);
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD((char*)this + 8, 4);
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD((char*)this + 0xc, 4);
}

struct FUN_0083d1e0_SubA
{
    int unk00;
    int unk04;

    FUN_0083d1e0_SubA();
    ~FUN_0083d1e0_SubA();
};

struct FUN_0083d1e0_SubB
{
    int unk00;
    int unk04;

    FUN_0083d1e0_SubB();
};

struct FUN_0083d1e0
{
    FUN_0083d1e0_SubA m_00;
    int unk08;
    int unk0C;
    FUN_0083d1e0_SubB m_10;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;

    FUN_0083d1e0();
};

// Initializes the object's fields unk08, unk0C, unk18, unk1C, unk20 and unk28 to zero.
// @fnv 0x0083d1e0
FUN_0083d1e0::FUN_0083d1e0()
{
    unk18 = 0;
    unk1C = 0;
    unk08 = 0;
    unk0C = 0;
    unk20 = 0;
    unk28 = 0;
}

struct FUN_0083d280_Obj
{
    int unk00;
    int unk04;

    ~FUN_0083d280_Obj();
};

struct FUN_0083d280_Sub
{
    int unk00;
    int unk04;

    FUN_0083d280_Sub();
    ~FUN_0083d280_Sub();
    void Assign(unsigned int aValue);
    FUN_0083d280_Obj Get();
};

struct FUN_0083d280_Src
{
    unsigned int Make(unsigned int aValue);
    unsigned int Count();
    unsigned int Name();
    unsigned int Value();
    unsigned int Index();
    unsigned int Pick();
    unsigned char Flag();
    unsigned int Lookup();
    unsigned int Merge(int a1, int a2, unsigned int a3, int a4, void* apOut);
};

unsigned int __cdecl FUN_0083d280_Helper(int aValue);

struct FUN_0083d280_cls
{
    FUN_0083d280_Sub m_sub00;
    int m_08;
    int m_0c;
    FUN_0083d280_Sub m_sub10;
    int m_18;
    int m_1c;
    int m_20;
    unsigned char m_24;
    int m_28;

    void Set(const FUN_0083d280_Obj& aValue);
    FUN_0083d280_cls(int a1, int a2, int a3, int a4, FUN_0083d280_Src* apSrc);
};

// @fnv 0x0083d280
FUN_0083d280_cls::FUN_0083d280_cls(int aiArg1, int aiArg2, int aiArg3, int aiArg4, FUN_0083d280_Src* apSrc)
{
    if (apSrc != 0)
    {
        FUN_0083d280_Sub tmp;
        tmp.Assign(apSrc->Make(0));
        Set(tmp.Get());
        m_08 = apSrc->Count();
        m_0c = apSrc->Name();
        apSrc->Merge(aiArg4, aiArg1, FUN_0083d280_Helper(aiArg3), aiArg3, &m_sub10);
        m_18 = apSrc->Value();
        m_1c = apSrc->Index();
        m_20 = apSrc->Pick();
        m_24 = apSrc->Flag();
        m_28 = apSrc->Lookup();
    }
    else
    {
        m_18 = 0;
        m_1c = 0;
        m_08 = 0;
        m_0c = 0;
        m_20 = 0;
        m_24 = 1;
        m_28 = 0;
    }
}

namespace fnv_0083d550 {
struct FUN_008579e0_shell
{
    void TESSaveLoadGame_LoadGameDataOLD(void*, unsigned int);
};
extern FUN_008579e0_shell* g_TESSaveLoadGame;
void ourMemset(void*, int, unsigned int);

struct Record
{
    ::BSStringT<char> first;
    unsigned int flags, value;
    ::BSStringT<char> second;
    void DialogueResponse_LoadGame();
};
// Reads two ::BSStringT<char> fields, flags, and value from g_TESSaveLoadGame via FUN_008579e0, setting empty strings when lengths are zero.
// @fnv 0x0083d550
// src: XBOX_PDB 0x0083d550
void Record::DialogueResponse_LoadGame()
{
    unsigned char firstLength, secondLength;
    g_TESSaveLoadGame->TESSaveLoadGame_LoadGameDataOLD(&firstLength, 1);
    if (firstLength)
    {
        char firstBuffer[260];
        ourMemset(firstBuffer, 0, 260);
        g_TESSaveLoadGame->TESSaveLoadGame_LoadGameDataOLD(firstBuffer, firstLength);
        first.Set(firstBuffer, 0);
    }
    else
        first.Set("", 0);
    g_TESSaveLoadGame->TESSaveLoadGame_LoadGameDataOLD(&secondLength, 1);
    if (secondLength)
    {
        char secondBuffer[260];
        ourMemset(secondBuffer, 0, 260);
        g_TESSaveLoadGame->TESSaveLoadGame_LoadGameDataOLD(secondBuffer, secondLength);
        second.Set(secondBuffer, 0);
    }
    else
        second.Set("", 0);
    g_TESSaveLoadGame->TESSaveLoadGame_LoadGameDataOLD(&flags, 4);
    g_TESSaveLoadGame->TESSaveLoadGame_LoadGameDataOLD(&value, 4);
}
}  // namespace fnv_0083d550
