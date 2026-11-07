
// src/fallout/ai/trespasspackage.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/trespasspackage.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/BGSSaveFormBuffer.h"
#include "../../../include/TrespassPackage.h"
#include "../../../include/TESSaveLoadGame.h"


// @fnv 0x009f9840
// src: XBOX_PDB 0x009f9840
void __thiscall TrespassPackage::LoadGame_009f9840(BGSLoadFormBuffer* apLoadGameBuffer)
{
    TESPackage::LoadGame(apLoadGameBuffer);
    apLoadGameBuffer->ReadTypedData((void*)((char*)this + 0x80), 4);
    apLoadGameBuffer->ReadTypedData((void*)((char*)this + 0x84), 4);
    apLoadGameBuffer->ReadTypedData((void*)((char*)this + 0x90), 4);
    apLoadGameBuffer->ReadTypedData((void*)((char*)this + 0x94), 4);
    apLoadGameBuffer->ReadTypedData((void*)((char*)this + 0x98), 4);
    apLoadGameBuffer->ReadFormIdentifier((void*)((char*)this + 0x88));
    apLoadGameBuffer->ReadFormIdentifier((void*)((char*)this + 0x8c));
}

// Calls FUN_009f9450, then deletes this when flags has bit 1 set, and returns this.
// @fnv 0x009f9220
void* __thiscall TrespassPackage::FUN_009f9220(unsigned int flags)
{
    FUN_009f9450();
    if (flags & 1)
        operator delete(this);
    return this;
}

TESForm* __cdecl _ref_004839c0(TESForm*);

struct FUN_00679a90_shell
{
    void __thiscall DispatchToSubobjects(void*);
};

// @fnv 0x009f98e0
// src: XBOX_PDB 0x009f98e0
void __thiscall TrespassPackage::InitLoadGame_009f98e0(unsigned int a)
{
    ((FUN_00679a90_shell*)this)->DispatchToSubobjects((void*)a);
    *(TESForm**)((char*)this + 0x88) =
        *(TESForm**)((char*)this + 0x88) ? _ref_004839c0(*(TESForm**)((char*)this + 0x88)) : 0;
    *(TESForm**)((char*)this + 0x8c) =
        *(TESForm**)((char*)this + 0x8c) ? _ref_004839c0(*(TESForm**)((char*)this + 0x8c)) : 0;
}

struct STR00
{
    void __thiscall TESForm_LoadGameDataOLD(void*, unsigned int);
};
struct FUN_00484d40_Host
{
    void __thiscall TESForm_LoadNumericID(unsigned int*, int);
};
struct Base009f8770
{
    void __thiscall TESPackage_LoadGame();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
// @fnv 0x009f9660
void __thiscall TrespassPackage::LoadTrespassPackage()
{
    ((Base009f8770*)this)->TESPackage_LoadGame();
    ((STR00*)this)->TESForm_LoadGameDataOLD((char*)this + 0x80, 4);
    ((STR00*)this)->TESForm_LoadGameDataOLD((char*)this + 0x84, 4);
    ((STR00*)this)->TESForm_LoadGameDataOLD((char*)this + 0x90, 4);
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x6c)
    {
        ((STR00*)this)->TESForm_LoadGameDataOLD((char*)this + 0x94, 4);
        ((STR00*)this)->TESForm_LoadGameDataOLD((char*)this + 0x98, 4);
    }
    unsigned int v1;
    ((FUN_00484d40_Host*)this)->TESForm_LoadNumericID(&v1, 4);
    *(unsigned int*)((char*)this + 0x88) = v1;
    unsigned int uiValue8c;
    ((FUN_00484d40_Host*)this)->TESForm_LoadNumericID(&uiValue8c, 4);
    *(unsigned int*)((char*)this + 0x8c) = uiValue8c;
}

struct FUN_006797c0_shell
{
    void __thiscall TESPackage_SaveGame(void*);
};
// Calls the base save routine, then writes five 4-byte fields at offsets 0x80-0x98 and two pointers at 0x88/0x8c to the save buffer.
// @fnv 0x009f9790
void __thiscall TrespassPackage::SaveToBuffer(BGSSaveFormBuffer* apSaveGameBuffer)
{
    ((FUN_006797c0_shell*)this)->TESPackage_SaveGame(apSaveGameBuffer);
    apSaveGameBuffer->SaveData((char*)this + 0x80, 4, 0);
    apSaveGameBuffer->SaveData((char*)this + 0x84, 4, 0);
    apSaveGameBuffer->SaveData((char*)this + 0x90, 4, 0);
    apSaveGameBuffer->SaveData((char*)this + 0x94, 4, 0);
    apSaveGameBuffer->SaveData((char*)this + 0x98, 4, 0);
    apSaveGameBuffer->SerializeFormData(*(void**)((char*)this + 0x88), 0);
    apSaveGameBuffer->SerializeFormData(*(void**)((char*)this + 0x8c), 0);
}

struct Saver
{
    unsigned short TESPackage_GetSaveSize();
};
// Computes the save size: adds FUN_00678fd0's result, 12, 8, and two 4-byte blocks when g_TESSaveLoadGame's version is at least 108.
// @fnv 0x009f9500
// src: XBOX_PDB 0x009f9500
unsigned short TrespassPackage::GetSaveSize_009f9500()
{
    unsigned short usSize = 0;
    usSize += ((Saver*)this)->TESPackage_GetSaveSize();
    usSize += 12;
    if (g_TESSaveLoadGame->FUN_008df040() >= 108)
    {
        usSize += 4;
        usSize += 4;
    }
    usSize += 8;
    return usSize;
}

struct S00679120
{
    void __thiscall SavePackage();
};

struct PC7d
{
    void __thiscall TESForm_SaveGameDataOLD(unsigned int, int);
};

struct FUN_00484d20_Class
{
    void __thiscall ForwardToSaveLoadGame(int, int);
};

extern TESSaveLoadGame* DAT_011de45c;

unsigned int __fastcall _ref_0084e3a0(void*);

// @fnv 0x009f9570
void TrespassPackage::SaveFormRefs()
{
    unsigned int iobjectOwnedID;
    unsigned int iownerID;

    reinterpret_cast<S00679120*>(this)->SavePackage();

    reinterpret_cast<PC7d*>(this)->TESForm_SaveGameDataOLD(
        reinterpret_cast<unsigned int>(reinterpret_cast<unsigned char*>(this) + 0x80), 4);
    reinterpret_cast<PC7d*>(this)->TESForm_SaveGameDataOLD(
        reinterpret_cast<unsigned int>(reinterpret_cast<unsigned char*>(this) + 0x84), 4);
    reinterpret_cast<PC7d*>(this)->TESForm_SaveGameDataOLD(
        reinterpret_cast<unsigned int>(reinterpret_cast<unsigned char*>(this) + 0x90), 4);

    if (DAT_011de45c->FUN_008df040() >= 0x6c)
    {
        reinterpret_cast<PC7d*>(this)->TESForm_SaveGameDataOLD(
            reinterpret_cast<unsigned int>(reinterpret_cast<unsigned char*>(this) + 0x94), 4);
        reinterpret_cast<PC7d*>(this)->TESForm_SaveGameDataOLD(
            reinterpret_cast<unsigned int>(reinterpret_cast<unsigned char*>(this) + 0x98), 4);
    }

    iownerID = 0;
    if (*(TESForm**)((char*)this + 0x88) != 0)
        iownerID = _ref_0084e3a0(*(TESForm**)((char*)this + 0x88));

    reinterpret_cast<FUN_00484d20_Class*>(this)->ForwardToSaveLoadGame(reinterpret_cast<int>(&iownerID), 4);

    iobjectOwnedID = 0;
    if (*(TESForm**)((char*)this + 0x8c) != 0)
        iobjectOwnedID = _ref_0084e3a0(*(TESForm**)((char*)this + 0x8c));

    reinterpret_cast<FUN_00484d20_Class*>(this)->ForwardToSaveLoadGame(reinterpret_cast<int>(&iobjectOwnedID), 4);
}
