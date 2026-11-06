#include "../../../../include/RouletteMenu.h"
#include "../../../../include/BSString.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiObjPtr.h"
#include "../../../../include/InventoryStackRecord.h"
#include "../../../../include/TESContainer.h"
#include "../../../../include/Setting.h"
#include "../../../../include/SL.h"
#include "../../../../include/hkMemoryAllocator.h"
// AudioMgr_BSAudio: this unit's view of BSAudio (0x00453a70 BSAudio::QInstance; 0x00ad73b0 GetSoundHandleByFormID,
// 0x00ad7480 GetSoundHandleByFilename, 0x00ad7550 GetSoundHandleByEditorName, 0x00ad8570 per the community PDB). It
// returns this unit's own sound-handle copy, so it stays local until that copy moves onto BSSoundHandle.
class AudioPlaybackHandle;
class Snd;
class SndForm;
class SndSrc;
class AudioMgr_BSAudio
{
public:
    static AudioMgr_BSAudio* Get();
    AudioPlaybackHandle Make(int id, SndForm* form);
    AudioPlaybackHandle Make2(int id);
    bool PlayAt(void* node, float f, int flags);
    AudioPlaybackHandle GetHandle(const char* name, int flags, int a);
    AudioPlaybackHandle GetSoundByEditorID(const char* editorID, int flags, int a);
    AudioPlaybackHandle GetSoundByEditorID(const char* editorID, int flags);
    Snd Make(void* a, SndSrc* b);
};
#include "../../../../include/BSAudio.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiNode.h"
#include "../../../../include/TESDataHandler.h"
#include "../../../../include/NiMatrix3.h"
#include "../../../../include/Tile.h"
#include "../../../../include/ActorValueOwner.h"
#include "../../../../include/Menu.h"
#include "../../../../include/NiFixedString.h"
#include "../../../../include/BSSoundHandle.h"
#include "../../../../include/Bound.h"
#include "../../../../include/NiUpdateData.h"
#include "../../../../include/SettingT_GameSettingCollection_.h"
#include "../../../../include/GO.h"


// The shared BSAudio factory still declares the legacy handle return type.
// This declaration uses the same entry point and layout with the real handle.
class RouletteAudio : public BSAudio
{
public:
    BSSoundHandle GetSoundHandleByEditorID(const char* editorID, unsigned int flags);
};


// src/fallout/interface/menus/roulettemenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/roulettemenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x007b8f30
int RouletteMenu::FUN_007b8f30()
{
    return 0x43a;
}

// Stores tile into the slot at index id when id is in [0, 11).
// @fnv 0x007b8f40
void RouletteMenu::SetTile(int aiIndex, Tile* tile)
{
    if (aiIndex >= 0 && aiIndex < 11)
    {
        *(Tile**)((char*)this + 0x2c + aiIndex * 4) = tile;
    }
}

namespace fnv_007b8f70 {
extern "C" void __cdecl _Deallocate(void*);

// Calls FUN_007b9020, then deallocates this if flags has bit 1 set, and returns this.
}

// @fnv 0x007b8f70
void* __thiscall RouletteMenu::Destroy(unsigned int flags)
{
    this->FUN_007b9020();
    if (flags & 1)
        fnv_007b8f70::_Deallocate(this);
    return this;
}


// @fnv 0x007bc820
int __cdecl FUN_007bc820()
{
    return 0x43a;
}

namespace fnv_007bed00 {

struct Proc_S
{
    void* GetNext(void);
};

void* __cdecl FUN_004b7210(void);

}

// @fnv 0x007bed00
void RouletteMenu::FUN_007bed00(int aiID, Tile* apTarget)
{
    using fnv_007bed00::Proc_S;
    using fnv_007bed00::FUN_004b7210;
    static_cast<Tile*>(static_cast<Proc_S*>(FUN_004b7210())->GetNext())->Set(0xfa9, 0.0f, true);
}


extern unsigned int __cdecl GetRandomNumberInRange(int, int);

// Stores two random values at offsets 0x4008 and 0x4004, then sets two byte flags based on whether the value at 0x3ff4 minus 5 is zero, positive or negative.
// @fnv 0x007bf670
void RouletteMenu::FUN_007bf670()
{
    *(unsigned int*)((char*)this + 0x4008) = GetRandomNumberInRange(0, 3);
    *(unsigned int*)((char*)this + 0x4004) = GetRandomNumberInRange(0, 0x26);
    int v2 = *(int*)((char*)this + 0x3ff4) - 5;
    if (v2 == 0)
    {
        *(unsigned char*)((char*)this + 0x400e) = 0;
        *(unsigned char*)((char*)this + 0x400d) = 0;
    }
    else if (v2 > 0)
    {
        *(unsigned char*)((char*)this + 0x400e) = 0;
        *(unsigned char*)((char*)this + 0x400d) = 1;
    }
    else if (v2 < 0)
    {
        *(unsigned char*)((char*)this + 0x400e) = 1;
        *(unsigned char*)((char*)this + 0x400d) = 0;
    }
}

struct B006815c0
{
    B006815c0();
};
struct FUN_007b8fa0
{
    SL s;
    unsigned char layoutPadding[0x10 - sizeof(SL)];
    B006815c0 b;
    FUN_007b8fa0();
};
// Initializes the object's SL member and B006815c0 member by running their default constructors.
// @fnv 0x007b8fa0
FUN_007b8fa0::FUN_007b8fa0()
{}

struct ListX
{
    ~ListX();
};
struct FUN_007b9000_shell : ListX
{
    void FUN_007b9000();
};
// @fnv 0x007b9000
void FUN_007b9000_shell::FUN_007b9000()
{
    ListX::~ListX();
}

// Checks the 11 Tile pointers starting at offset 0x2c and returns 1 only if all are non-null, otherwise 0.
// @fnv 0x007bc830
char RouletteMenu::HasAllTiles()
{
    for (int i = 0; i < 11; ++i)
        if (!((Tile**)((char*)this + 0x2c))[i])
            return 0;
    return 1;
}


extern double DAT_01076340;
// Returns true if the TESEyes list value for the given index is less than DAT_01076340, otherwise false.
// @fnv 0x007bf530
bool RouletteMenu::IsEyesListBelowThreshold(int aiIndex)
{
    if (*reinterpret_cast<float*>(reinterpret_cast<char*>(reinterpret_cast<TESDataHandler**>(&m_pRouletteWheel)[aiIndex]->GetTESEyesList()) + 8) < DAT_01076340)
        return true;
    return false;
}

struct Proc_S
{
    void* GetNext();
};

Proc_S* __cdecl _FUN_004b7210();
extern RouletteMenu* DAT_011da878;

// If DAT_011da878 is set, sets tile 0xFA9 on the next tile set and writes 5 at offset 0x28 of DAT_011da878.
// @fnv 0x007b9480
void SetRouletteMenuTile()
{
    if (DAT_011da878)
    {
        reinterpret_cast<Tile*>(_FUN_004b7210()->GetNext())->Set(0xFA9, 255.0f, true);
        *reinterpret_cast<int*>(reinterpret_cast<char*>(DAT_011da878) + 0x28) = 5;
    }
}

namespace fnv_007bed30 {
extern float const g_011e0218_arg1;

struct Proc_S
{
    void* GetNext(void);
};

Proc_S* __cdecl _FUN_004b7210();

// Calls GetNext on the result of _FUN_004b7210 and sets tile 4009 to g_011e0218_arg1 with true.
}

// @fnv 0x007bed30
void RouletteMenu::SetTileValue(int, Tile*)
{
    using fnv_007bed30::g_011e0218_arg1;
    using fnv_007bed30::Proc_S;
    using fnv_007bed30::_FUN_004b7210;
    ((Tile*)_FUN_004b7210()->GetNext())->Set(4009, g_011e0218_arg1, true);
}


struct SceneObjectLookup
{
    static NiAVObject* __cdecl GetObjectByName(NiAVObject*, const char*);
};

extern double const DAT_01023128;
extern double DAT_01076360;
extern char DAT_011a9448;

// @fnv 0x007bf570
void RouletteMenu::RotateRouletteWheelToResult(int aiResult)
{
    double facerotation;
    double radianrotation;
    double degreesperface;
    // Copy into aligned storage without invoking the shared default constructor.
    void* rotation[(sizeof(NiMatrix3) + sizeof(void*) - 1) / sizeof(void*)];
    NiAVObject* pWheelObject;
    int index;

    index = 0;
    degreesperface = DAT_01076360;

    for (; index < 38; ++index)
    {
        if (m_aiPocketNumbers[index] == aiResult)
            break;
    }

    index = 38 - index;

    if (m_iRouletteResult == 0)
        index += 5;
    else if (m_iRouletteResult == 1)
        index += 3;
    else if (m_iRouletteResult == 2)
        index += 10;

    facerotation = index * degreesperface;
    radianrotation = facerotation * DAT_01023128;

    *reinterpret_cast<NiMatrix3*>(rotation) = *reinterpret_cast<const NiMatrix3*>(&DAT_011a9448);
    reinterpret_cast<NiMatrix3*>(rotation)->MakeZRotation(static_cast<float>(radianrotation));

    pWheelObject = SceneObjectLookup::GetObjectByName(m_pRouletteWheel, "Roulette_Wheel:2");

    if (pWheelObject)
        pWheelObject->SetLocalRotation(*reinterpret_cast<NiMatrix3*>(rotation));
}

extern double DAT_01070e78;
extern GO g_011da8a0;

// @fnv 0x007bf840
void RouletteMenu::FUN_007bf840()
{
    // Raw storage preserves the original uninitialized local without a constructor call.
    float loc[3];
    int level = 0;

    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x3fe8) < 5)
        level = 1;
    else if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x3fe8) < 10)
        level = 2;
    else if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x3fe8) < 25)
        level = 3;
    else if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x3fe8) < 40)
        level = 4;
    else if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x3fe8) < 70)
        level = 5;
    else if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x3fe8) < 100)
        level = 6;
    else if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x3fe8) < 250)
        level = 7;
    else if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x3fe8) < 500)
        level = 8;
    else if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x3fe8) < 1000)
        level = 9;
    else
        level = 10;

    *reinterpret_cast<NiPoint3*>(loc) = *reinterpret_cast<const NiPoint3*>(
        reinterpret_cast<TESDataHandler*>(
            *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x3f14 +
                                      *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x3fe0) * 4))
            ->GetTESEyesList());

    reinterpret_cast<NiAVObject*>(
        *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x3f14 +
                                  *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x3fe0) * 4))
        ->FUN_004bc1f0(loc[0], loc[1], static_cast<float>(level * DAT_01070e78));

    reinterpret_cast<NiAVObject*>(
        *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x3f3c +
                                  *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x3fe0) * 4))
        ->FUN_004bc1f0(loc[0], loc[1], 0.0f);

    NiUpdateData update1(0.0f, false, false);
    reinterpret_cast<NiNode*>(g_011da8a0.operator unsigned int())->Update(static_cast<const NiUpdateData&>(update1));
}

extern int DAT_011da86c;

struct BSSimpleListTESRaceSize
{
    int GetSize();
    bool IsEmpty();
};
void __cdecl FUN_004d5c60(int);
// When unk0028 is 4, handles roulette input id 3-8: adjusts unk3fe8 bet, updates tile values and calls ApplyValueToChain with alpha values.
// @fnv 0x007bc870
void RouletteMenu::HandleRouletteInput(int aiInputId, Tile* tile)
{
    if (unk0028 == 4)
    {
        switch (aiInputId)
        {
        case 8:
            SetRouletteMenuTile();
            break;
        case 3: {
            int selected = FUN_007bf390();
            if (selected < 159 && unk3fec < unk4000 && FUN_007bed70(selected))
            {
                ((Tile*)DAT_011da878->m_pBetTile)->SetTraitFloat(DAT_011da86c, 1.0f);
                ((Tile*)DAT_011da878->m_pBetTile)->Set(DAT_011da86c, unk3fec);
                if (unk3fec + unk3fe8 >= unk4000)
                {
                    unk3fe8 = unk4000 - unk3fec;
                    ((Tile*)DAT_011da878->m_pMaxBetTile)->SetTraitFloat(DAT_011da86c, 1.0f);
                    ((Tile*)DAT_011da878->m_pMaxBetTile)->Set(DAT_011da86c, unk3fe8);
                    ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(3, 128.0f);
                    ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(6, 128.0f);
                    ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(7, 128.0f);
                }
                ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(4, 255.0f);
                ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(5, 255.0f);
                if (unk3fe8 == 0)
                {
                    ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(3, 128.0f);
                    ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(7, 128.0f);
                }
                if (unk3fe4 == 10)
                {
                    unk3fe8 = 0;
                    ((Tile*)DAT_011da878->m_pMaxBetTile)->SetTraitFloat(DAT_011da86c, 1.0f);
                    ((Tile*)DAT_011da878->m_pMaxBetTile)->Set(DAT_011da86c, unk3fe8);
                    ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(3, 128.0f);
                    ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(6, 128.0f);
                    ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(7, 128.0f);
                }
            }
            break;
        }
        case 4: {
            int selected2 = FUN_007bf390();
            if (selected2 < 159 && RemoveEntryById(selected2))
            {
                static_cast<RouletteAudio*>(BSAudio::GetSingleton())->GetSoundHandleByEditorID("GAMERouletteDecreaseBet", 0x121).Play(false);
                ((Tile*)DAT_011da878->m_pBetTile)->SetTraitFloat(DAT_011da86c, 1.0f);
                ((Tile*)DAT_011da878->m_pBetTile)->Set(DAT_011da86c, unk3fec);
                ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(6, 255.0f);
                ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(3, 255.0f);
                if (unk3e78->GetSize() == 0)
                {
                    ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(5, 128.0f);
                    ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(4, 128.0f);
                }
                if (unk3fe4 == 9)
                {
                    ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(5, 255.0f);
                    ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(4, 255.0f);
                    ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(3, 255.0f);
                    ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(6, 255.0f);
                    ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(7, 255.0f);
                    ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(8, 255.0f);
                }
            }
            break;
        }
        case 5:
            if (unk3e78 && !unk3e78->IsEmpty())
            {
                FUN_007bf670();
                ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(5, 128.0f);
                ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(4, 128.0f);
                ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(3, 128.0f);
                ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(6, 128.0f);
                ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(7, 128.0f);
                ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(8, 128.0f);
                unk0028 = 1;
                FUN_004d5c60(40);
            }
            break;
        case 6: {
            int oldBet = unk3fe8;
            if (unk3fe8 < 10)
                unk3fe8 += 1;
            else if (unk3fe8 < 40)
                unk3fe8 += 5;
            else if (unk3fe8 < 100)
                unk3fe8 += 10;
            else if (unk3fe8 < 500)
                unk3fe8 += 25;
            else
                unk3fe8 += 100;
            ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(7, 255.0f);
            if (unk3fe8 + unk3fec >= unk3ff0)
            {
                unk3fe8 = unk3ff0 - unk3fec;
                ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(6, 128.0f);
            }
            if (unk3fec + unk3fe8 >= unk4000)
            {
                unk3fe8 = unk4000 - unk3fec;
                ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(6, 128.0f);
            }
            if (unk3fe4 != 10)
                FUN_007bf840();
            if (oldBet != unk3fe8)
                static_cast<RouletteAudio*>(BSAudio::GetSingleton())->GetSoundHandleByEditorID("GAMERouletteValidBet", 0x121).Play(false);
            ((Tile*)DAT_011da878->m_pMaxBetTile)->SetTraitFloat(DAT_011da86c, 1.0f);
            ((Tile*)DAT_011da878->m_pMaxBetTile)->Set(DAT_011da86c, unk3fe8);
            break;
        }
        case 7: {
            int oldBet2 = unk3fe8;
            if (unk3fe8 <= 10)
                unk3fe8 -= 1;
            else if (unk3fe8 <= 40)
                unk3fe8 = unk3fe8 % 5 ? (unk3fe8 / 5) * 5 : unk3fe8 - 5;
            else if (unk3fe8 <= 100)
                unk3fe8 = unk3fe8 % 10 ? (unk3fe8 / 10) * 10 : unk3fe8 - 10;
            else if (unk3fe8 <= 500)
                unk3fe8 = unk3fe8 % 25 ? (unk3fe8 / 25) * 25 : unk3fe8 - 25;
            else
                unk3fe8 = unk3fe8 % 100 ? (unk3fe8 / 100) * 100 : unk3fe8 - 100;
            ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(6, 255.0f);
            if (unk3fe8 <= unk3ffc && unk3ffc + unk3fec < unk4000)
            {
                unk3fe8 = unk3ffc;
                ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(7, 128.0f);
            }
            if (unk3fe8 <= 0)
            {
                unk3fe8 = 0;
                ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(7, 128.0f);
            }
            if (unk3fe4 != 10)
                FUN_007bf840();
            if (oldBet2 != unk3fe8)
                static_cast<RouletteAudio*>(BSAudio::GetSingleton())->GetSoundHandleByEditorID("GAMERouletteValidBet", 0x121).Play(false);
            ((Tile*)DAT_011da878->m_pMaxBetTile)->SetTraitFloat(DAT_011da86c, 1.0f);
            ((Tile*)DAT_011da878->m_pMaxBetTile)->Set(DAT_011da86c, unk3fe8);
            break;
        }
        }
    }
}

struct FUN_0073ac90_shell
{
    int* FUN_0073ac90();
};
struct FUN_006317a0_shell
{
    void** AddEight(void* a, int b, float c, int d);
};

struct FUN_007b52d0_shell
{
    void* DereferenceIfNotNull(void* a);
};

// Walks the object chain at DAT_011da878 slot aiId, calling FUN_00a012d0 on each node produced by AddEight with afValue.
// @fnv 0x007bf710
void RouletteMenu::ApplyValueToChain(int aiId, float afValue)
{
    void* pObj = ((NiObjPtr*)(*(char**)((char*)DAT_011da878 + 0x2c + aiId * 4) + 4))->FUN_00559450();
    char* pCur = *(char**)((char*)DAT_011da878 + 0x2c + aiId * 4) + 4;
    while (pObj != 0 && pCur != 0 && *((FUN_0073ac90_shell*)pCur)->FUN_0073ac90() != 0)
    {
        (reinterpret_cast<Tile*>(*((FUN_006317a0_shell*)pCur)->AddEight(pObj, 0xfa9, afValue, 1))->*
            reinterpret_cast<void (Tile::*)()>(static_cast<void (Tile::*)(int, float, bool)>(&Tile::FUN_00a012d0)))();
        pObj = ((FUN_007b52d0_shell*)pCur)->DereferenceIfNotNull(pObj);
    }
}

extern float DAT_0102caf8;

struct S_007bf7a0_Val
{
    float f;
    char a;
    char b;
    char c;
    char d;
    char e;
    S_007bf7a0_Val(float f, char a, char b);
};
struct S_007bf7a0_Inner
{
    void FUN_00a59c60(S_007bf7a0_Val* v);
};
extern NiObjPtr DAT_011da8a0;
// @fnv 0x007bf7a0
void RouletteMenu::FUN_007bf7a0()
{
    for (int i = 0; i < 10; i++)
    {
        tilesA[i]->FUN_004bc1f0(0.0f, 0.0f, DAT_0102caf8);
        tilesB[i]->FUN_004bc1f0(0.0f, 0.0f, DAT_0102caf8);
    }
    S_007bf7a0_Val v(0.0f, 0, 0);
    reinterpret_cast<S_007bf7a0_Inner*>(DAT_011da8a0.FUN_00559450())->FUN_00a59c60(&v);
}


extern Setting g_011d3e08;

struct NamedForm
{
    const char* GetFullName();
};
struct RoulettePlayerStandIn
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    NamedForm fullName;
};
struct RouletteBetStandIn
{
    int unk00;
    int iAmount;
};
extern RouletteBetStandIn* DAT_011da87c;
extern RoulettePlayerStandIn* DAT_011da880;
extern int DAT_011da870;

int __cdecl FUN_00406d00(char* buffer, int size, const char* format, ...);


static const char kNameFormat[] = "%s %s";

// @fnv 0x007bf9e0
void RouletteMenu::UpdateBetTileText()
{
    char acText[0x104];
    int iLabelLength;
    FUN_00406d00(acText, 0x104, "%s %s%i", DAT_011da880->fullName.GetFullName(), g_011d3e08.String(),
                 DAT_011da87c->iAmount);
    iLabelLength = BSStringLength(acText);
    if (iLabelLength < 0x17)
    {
        FUN_00406d00(acText, 0x104, kNameFormat, DAT_011da880->fullName.GetFullName(), g_011d3e08.String());
        for (int i = 0; i < 0x17 - iLabelLength; i++)
        {
            acText[iLabelLength - 1 + i] = ' ';
            acText[iLabelLength + i] = 0;
        }
        FUN_00406d00(acText, 0x104, "%s%i", acText, DAT_011da87c->iAmount);
    }
    (*reinterpret_cast<Tile**>(reinterpret_cast<char*>(this) + 0x34))->Set(DAT_011da870, acText, true);
}

struct ModelPath
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void FlushUsageData();
    virtual void unused4();
    virtual const char* Path();
};

namespace RouletteCleanup {
struct Scene;

struct MenuRef
{
    ModelPath* FUN_00504e00(int);
};
struct Cache
{
    void FUN_0045a5e0(const char*);
};
struct Player
{
    void FUN_00969b20();
};
struct Scene
{
    void FUN_00572160();
};
struct Pointer
{
    Scene* value;
    Scene* FUN_00559450();
    void FUN_0066b0d0(Scene*);
    ~Pointer();
};
struct Renderer
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual void slote0();
    virtual void slote4();
    virtual void Detach(Scene*);
    void FUN_00b5d180();
};
Renderer* FUN_00450b80(int);
struct Animation
{
    bool FUN_008256d0();
    void FUN_00470470();
    ~Animation();
};
struct Base
{
    virtual ~Base();
};
struct Entry
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    ~Entry();
};
extern Player* DAT_011dea3c;
extern MenuRef* DAT_011da880;
extern Cache* DAT_011c3b3c;
extern Pointer DAT_011da8d0, DAT_011da8a0;
extern void* DAT_011da87c;
extern void* DAT_011da878;
extern const char DAT_01075ff8[], DAT_01075fc4[], DAT_01070944[];
void FUN_00406d30(char*, unsigned int, const char*);
unsigned int FUN_0044a670(const char*);
// The shared RouletteMenu lacks the nontrivial slot-array and pointer members
// needed for this destructor's compiler-generated cleanup and exception states.
struct FUN_007b9020 : Base
{
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    Entry entries[159];
    Animation* animation;
    unsigned int unk3e7c;
    unsigned int unk3e80;
    unsigned int unk3e84;
    unsigned int unk3e88;
    unsigned int unk3e8c;
    unsigned int unk3e90;
    unsigned int unk3e94;
    unsigned int unk3e98;
    unsigned int unk3e9c;
    unsigned int unk3ea0;
    unsigned int unk3ea4;
    unsigned int unk3ea8;
    unsigned int unk3eac;
    unsigned int unk3eb0;
    unsigned int unk3eb4;
    unsigned int unk3eb8;
    unsigned int unk3ebc;
    unsigned int unk3ec0;
    unsigned int unk3ec4;
    unsigned int unk3ec8;
    unsigned int unk3ecc;
    unsigned int unk3ed0;
    unsigned int unk3ed4;
    unsigned int unk3ed8;
    unsigned int unk3edc;
    unsigned int unk3ee0;
    unsigned int unk3ee4;
    unsigned int unk3ee8;
    unsigned int unk3eec;
    unsigned int unk3ef0;
    unsigned int unk3ef4;
    unsigned int unk3ef8;
    unsigned int unk3efc;
    unsigned int unk3f00;
    unsigned int unk3f04;
    unsigned int unk3f08;
    unsigned int unk3f0c;
    unsigned int unk3f10;
    Scene* table;
    Scene* wheel;
    Scene* ball;
    Scene* nodes[10];
    Scene* materials[10];
    Scene* camera;
    Scene* light;
    Scene* target;
    Pointer pointer;
    Scene* group;
    Scene* markers[3];
    virtual ~FUN_007b9020();
};

// Releases menu cache entries, detaches the renderer, clears scene pointers and deletes the animation object.
// @fnv 0x007b9020
FUN_007b9020::~FUN_007b9020()
{
    DAT_011dea3c->FUN_00969b20();
    DAT_011c3b3c->FUN_0045a5e0(DAT_011da880->FUN_00504e00(9)->Path());
    DAT_011c3b3c->FUN_0045a5e0(DAT_01075ff8);
    DAT_011c3b3c->FUN_0045a5e0(DAT_01075fc4);
    DAT_011c3b3c->FUN_0045a5e0(DAT_011da880->FUN_00504e00(6)->Path());
    char* extension = 0;
    char path[260];
    FUN_00406d30(path, 260, DAT_011da880->FUN_00504e00(6)->Path());
    for (unsigned int index = 0; index < FUN_0044a670(path); index++)
    {
        if (path[index] == '.')
        {
            extension = &path[index];
            break;
        }
    }
    if (extension)
    {
        FUN_00406d30(extension, 15, DAT_01070944);
        DAT_011c3b3c->FUN_0045a5e0(path);
    }
    DAT_011da8d0.FUN_0066b0d0(0);
    FUN_00450b80(1)->Detach(DAT_011da8a0.FUN_00559450());
    FUN_00450b80(1)->FUN_00b5d180();
    DAT_011da8a0.FUN_00559450()->FUN_00572160();
    DAT_011da8a0.FUN_0066b0d0(0);
    table = 0;
    wheel = 0;
    ball = 0;
    DAT_011da8d0.FUN_0066b0d0(0);
    camera = 0;
    light = 0;
    target = 0;
    pointer.FUN_0066b0d0(0);
    if (animation && !animation->FUN_008256d0())
        animation->FUN_00470470();
    delete animation;
    group = 0;
    for (int marker = 0; marker < 3; marker++)
        markers[marker] = 0;
    for (int element = 0; element < 10; element++)
    {
        nodes[element] = 0;
        materials[element] = 0;
    }
    if (!animation->FUN_008256d0())
        animation->FUN_00470470();
    animation = 0;
    DAT_011da87c = 0;
    DAT_011da880 = 0;
    DAT_011da878 = 0;
}
}



struct Scene;

struct PathOwner
{
    ModelPath* FUN_00504e00(int);
};
struct ModelLoader
{
    Scene* LoadFile(const char*, int, bool, bool, bool, bool);
};
extern ModelLoader* g_modelLoader;

struct Controller
{
    void* FUN_0047a520(const NiFixedString&);
    void FUN_0048fef0(float);
};
struct NiRTTI;
extern NiRTTI DAT_011f36ac;
#include "../../../../include/NiMemObject.h"
struct Scene : NiMemObject
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void FlushUsageData();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual void unused40();
    virtual void unused41();
    virtual void unused42();
    virtual void unused43();
    virtual void unused44();
    virtual void unused45();
    virtual void unused46();
    virtual void unused47();
    virtual void unused48();
    virtual void unused49();
    virtual void unused50();
    virtual void unused51();
    virtual void unused52();
    virtual void unused53();
    virtual void unused54();
    virtual void Attach(Scene*, bool);
    void FUN_004bc1f0(float, float, float);
    void FUN_00450f90(bool);
    Scene* FUN_00a5d680();
    void FUN_00a59c60(const NiUpdateData&);
    Controller* FUN_00a5c570(const NiRTTI*);
    Bound* FUN_0043d450();
    void FUN_00b5ca70(Scene*, float);
};

// This allocation needs the sized exception-path delete inherited from NiMemObject.
// NiNode's shared declaration also exposes an unsized delete, which changes that path.
struct RouletteSceneNode : Scene
{
    unsigned char layoutExtension[0xA8];
    RouletteSceneNode(unsigned int);
};
struct SceneHolder
{
    SceneHolder& operator=(Scene*);
    Scene* FUN_00559450();
};
extern SceneHolder g_011da8d0;

Scene* __cdecl FUN_004aae30(Scene*, const char*);
Scene* __cdecl FUN_00450b80(int);
void __cdecl FUN_00a6d2d0(Scene*);
namespace RouletteStrings { int __cdecl strcpy_s(char*, unsigned int, const char*); }
// @fnv 0x007b94c0
void RouletteMenu::InitRouletteScene()
{
    reinterpret_cast<Scene*&>(m_pRouletteWheel) = g_modelLoader->LoadFile(((PathOwner*)DAT_011da880)->FUN_00504e00(9)->Path(), 0, true, false, false, false);
    reinterpret_cast<Scene*&>(m_pTableNode) =
        g_modelLoader->LoadFile("Meshes\\terminals\\NV_Roulette\\NV_Roulette-Points.NIF", 0, true, false, false, false);
    reinterpret_cast<Scene*&>(m_iNode) = g_modelLoader->LoadFile("Meshes\\terminals\\NV_Roulette\\NV_Roulette-Bet.NIF", 0, true, false, false, false);
    reinterpret_cast<Scene*&>(tilesA[0]) =
        g_modelLoader->LoadFile(((PathOwner*)DAT_011da880)->FUN_00504e00(6)->Path(), 0, true, false, false, false);
    reinterpret_cast<Scene*&>(m_pTableNode)->FUN_004bc1f0(0.0f, 0.0f, 0.1f);
    reinterpret_cast<Scene*&>(m_iNode)->FUN_004bc1f0(0.0f, 0.0f, 0.1f);
    reinterpret_cast<Scene*&>(m_pValidMarker) = FUN_004aae30(reinterpret_cast<Scene*&>(m_iNode), "Bet_Selector:0");
    reinterpret_cast<Scene*&>(m_pInvalidMarker) = FUN_004aae30(reinterpret_cast<Scene*&>(m_iNode), "Bet_Invalid:0");
    reinterpret_cast<Scene*&>(m_pInvalidMarker)->FUN_00450f90(true);
    char* dot = 0;
    char path[260];
    RouletteStrings::strcpy_s(path, 260, ((PathOwner*)DAT_011da880)->FUN_00504e00(6)->Path());
    for (unsigned int i = 0; i < (unsigned int)BSStringLength(path); i++)
    {
        if (path[i] == '.')
        {
            dot = &path[i];
            break;
        }
    }
    if (dot)
    {
        RouletteStrings::strcpy_s(dot, 15, "_Shadow.NIF");
        reinterpret_cast<Scene*&>(tilesB[0]) = g_modelLoader->LoadFile(path, 0, true, false, false, false);
    }
    for (int j = 1; j < 10; j++)
    {
        reinterpret_cast<Scene*&>(tilesA[j]) = reinterpret_cast<Scene*&>(tilesA[0])->FUN_00a5d680();
        reinterpret_cast<Scene*&>(tilesB[j]) = reinterpret_cast<Scene*&>(tilesB[0])->FUN_00a5d680();
    }
    Scene* object = reinterpret_cast<Scene*&>(m_pRouletteWheel);
    g_011da8d0 = FUN_004aae30(object, "object4");
    (*(SceneHolder*)&g_011da8a0) = new RouletteSceneNode(0);
    (*(SceneHolder*)&g_011da8a0).FUN_00559450()->Attach(reinterpret_cast<Scene*&>(m_pRouletteWheel), true);
    (*(SceneHolder*)&g_011da8a0).FUN_00559450()->Attach(reinterpret_cast<Scene*&>(m_pTableNode), true);
    (*(SceneHolder*)&g_011da8a0).FUN_00559450()->Attach(reinterpret_cast<Scene*&>(m_iNode), true);
    for (int k = 0; k < 10; k++)
        (*(SceneHolder*)&g_011da8a0).FUN_00559450()->Attach(reinterpret_cast<Scene*&>(tilesA[k]), true);
    for (int l = 0; l < 10; l++)
        (*(SceneHolder*)&g_011da8a0).FUN_00559450()->Attach(reinterpret_cast<Scene*&>(tilesB[l]), true);
    m_iChipNode = 3;
    FUN_007bf7a0();
    FUN_007bf840();
    NiUpdateData found(0.0f, false, false);
    (*(SceneHolder*)&g_011da8a0).FUN_00559450()->FUN_00a59c60(found);
    Controller* update = reinterpret_cast<Scene*&>(m_pRouletteWheel)->FUN_00a5c570(&DAT_011f36ac);
    if (update)
    {
        reinterpret_cast<Controller*&>(m_pAnimCtrl) = update;
        spin1 = reinterpret_cast<Controller*&>(m_pAnimCtrl)->FUN_0047a520(NiFixedString("Spin_1"));
        spin2 = reinterpret_cast<Controller*&>(m_pAnimCtrl)->FUN_0047a520(NiFixedString("Spin_2"));
        spin3 = reinterpret_cast<Controller*&>(m_pAnimCtrl)->FUN_0047a520(NiFixedString("Spin_3"));
        reinterpret_cast<Controller*&>(m_pAnimCtrl)->FUN_0048fef0(0.0f);
        FUN_00a6d2d0(reinterpret_cast<Scene*&>(m_pRouletteWheel));
    }
    if (!g_011da8d0.FUN_00559450())
        g_011da8d0 = reinterpret_cast<Scene*>(FUN_007c2180());
    FUN_00450b80(1)->Attach((*(SceneHolder*)&g_011da8a0).FUN_00559450(), true);
    float radius = (*(SceneHolder*)&g_011da8a0).FUN_00559450()->FUN_0043d450()->FUN_0084d030() * 4.0;
    FUN_00450b80(1)->FUN_00b5ca70((*(SceneHolder*)&g_011da8a0).FUN_00559450(), radius);
    InitRouletteWheel();
}

namespace fnv_007bbcf0 {
struct S148c0
{
    void FUN_007148c0(int, int);
};
S148c0* FUN_0043c4b0();
struct Scene
{
    void FUN_00c4f270(int);
    void FUN_004a0fd0(void*);
    void FUN_00c4f2d0();
};
struct Owner
{
    Scene* FUN_008d80e0();
    void* FUN_006629f0();
};
Owner* FUN_0045c670();
struct Holder
{
    void* value;
    Holder(void*);
    ~Holder();
    void* FUN_00559450();
    void FUN_0066b0d0(void*);
};
extern Holder g_011da8d0;
extern const float g_011db5ec_arg1;
void UpdateCameraFrustum(void*, float);
// Exe 0x007bbcf0: unit-local Interface view; declarations and layout are preserved.
struct RoulettemenuInterfaceView
{
    void* FUN_007fd640();
};
RoulettemenuInterfaceView* FUN_004b7210();
void* FUN_00450b80(int);
void FUN_00b6bee0(void*, void*, Scene*);
void FUN_00b6c0d0(void*, void*, int);
// @fnv 0x007bbcf0
void FUN_007bbcf0()
{
    FUN_0043c4b0()->FUN_007148c0(0, 4);
    Owner* pOwner = FUN_0045c670();
    Scene* scene = pOwner->FUN_008d80e0();
    scene->FUN_00c4f270(1);
    void* owner = g_011da8d0.FUN_00559450();
    UpdateCameraFrustum(owner, g_011db5ec_arg1);
    Holder node(FUN_004b7210()->FUN_007fd640());
    scene->FUN_004a0fd0(node.FUN_00559450());
    void* existing = owner ? owner : pOwner->FUN_006629f0();
    FUN_00b6bee0(existing, FUN_00450b80(1), scene);
    FUN_00b6c0d0(existing, node.FUN_00559450(), 0);
    scene->FUN_004a0fd0(0);
    node.FUN_0066b0d0(0);
    scene->FUN_00c4f2d0();
}
}  // namespace fnv_007bbcf0

struct FUN_00733f50
{
    int formID;
    int amount;
    int unk08;
    FUN_00733f50();
};
struct BetList
{
    RouletteBetStandIn** FUN_006815c0();
    BetList* FUN_00726070();
    bool FUN_008256d0();
    void FUN_00726c60(FUN_00733f50*&);
    void FUN_005ae3d0(FUN_00733f50*&);
};

struct PlayerForRoulette
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    ActorValueOwner av;
    BetList* FUN_005a6260();
    bool FUN_00969b80();
    int FUN_00969b40();
    int FUN_00575610(void*);
};
extern PlayerForRoulette* DAT_011dea3c;
struct CasinoData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int limit;
};
struct CasinoForRoulette
{
    int FUN_0084e3a0();
    CasinoData* FUN_00504e60();
    void* FUN_007316d0();
};
struct MenuVirtual
{
    virtual ~MenuVirtual();
    virtual void unknown01();
    virtual void unknown02();
    virtual void unknown03();
    virtual void unknown04();
    virtual void unknown05();
    virtual void unknown06();
    virtual void unknown07();
    virtual void unknown08();
    virtual void unknown09();
    virtual void unknown0a();
    virtual void unknown0b();
    virtual void unknown0c();
    virtual int GetID();
};
struct PlayerVirtual
{
    virtual ~PlayerVirtual();
    virtual void unknown01();
    virtual void unknown02();
    virtual void unknown03();
    virtual void unknown04();
    virtual void unknown05();
    virtual void unknown06();
    virtual void unknown07();
    virtual void unknown08();
    virtual void unknown09();
    virtual void unknown0a();
    virtual void unknown0b();
    virtual void unknown0c();
    virtual void unknown0d();
    virtual void unknown0e();
    virtual void unknown0f();
    virtual void unknown10();
    virtual void unknown11();
    virtual void unknown12();
    virtual void unknown13();
    virtual void unknown14();
    virtual void unknown15();
    virtual void unknown16();
    virtual void unknown17();
    virtual void unknown18();
    virtual void unknown19();
    virtual void unknown1a();
    virtual void unknown1b();
    virtual void unknown1c();
    virtual void unknown1d();
    virtual void unknown1e();
    virtual void unknown1f();
    virtual void unknown20();
    virtual void unknown21();
    virtual void unknown22();
    virtual void unknown23();
    virtual void unknown24();
    virtual void unknown25();
    virtual void unknown26();
    virtual void unknown27();
    virtual void unknown28();
    virtual void unknown29();
    virtual void unknown2a();
    virtual void unknown2b();
    virtual void unknown2c();
    virtual void unknown2d();
    virtual void unknown2e();
    virtual void unknown2f();
    virtual void unknown30();
    virtual void unknown31();
    virtual void unknown32();
    virtual void unknown33();
    virtual void unknown34();
    virtual void unknown35();
    virtual void unknown36();
    virtual void unknown37();
    virtual void unknown38();
    virtual void unknown39();
    virtual void unknown3a();
    virtual void unknown3b();
    virtual void unknown3c();
    virtual void unknown3d();
    virtual void unknown3e();
    virtual void unknown3f();
    virtual void unknown40();
    virtual void unknown41();
    virtual void unknown42();
    virtual void unknown43();
    virtual void unknown44();
    virtual void unknown45();
    virtual void unknown46();
    virtual void unknown47();
    virtual void unknown48();
    virtual void unknown49();
    virtual void unknown4a();
    virtual void unknown4b();
    virtual const char* GetName();
};
struct InterfaceRoulette
{
    Tile* FUN_00586150(const char*);
};
extern Setting g_011d2274, g_011d2d24, g_011d3abc, g_011d2424, g_011d3594, g_011d3804, g_011d3168, g_011d3300,
    g_011d41e0, g_011d2c1c, g_011d2820, g_011d3354, g_011d487c, g_011d33fc;
extern const char DAT_01076274[], DAT_01049638[], DAT_01025cc4[], DAT_01076254[], DAT_01076200[], DAT_010761e4[];
extern float DAT_010162c0, DAT_0101e704;
extern double DAT_010704f0, DAT_010704e8;
MenuVirtual* __cdecl FUN_00a09030(int);
bool __cdecl QueueUIMessage(const char*, int, const char*, const char*, float, bool);
void __cdecl FUN_005b5e40(const char*);
float __stdcall FUN_00a01530(int);
Tile* __cdecl FUN_00a08b20(Tile*, const char*);

// @fnv 0x007bbe20
Tile* __cdecl FUN_007bbe20(RoulettePlayerStandIn* casino, int bet, int arg3, int exchange)
{
    MenuVirtual* oldMenu = FUN_00a09030(0x43a);
    InterfaceRoulette* list = (InterfaceRoulette*)_FUN_004b7210();
    DAT_011da880 = casino;
    BetList* tile = DAT_011dea3c->FUN_005a6260();
    while (tile && *tile->FUN_006815c0())
    {
        if (((CasinoForRoulette*)DAT_011da880)->FUN_0084e3a0() == (*tile->FUN_006815c0())->unk00)
        {
            DAT_011da87c = *tile->FUN_006815c0();
            break;
        }
        if (!tile->FUN_00726070())
            break;
        tile = tile->FUN_00726070();
    }
    if (!DAT_011da87c)
    {
        FUN_00733f50* entry = new FUN_00733f50;
        entry->formID = ((CasinoForRoulette*)DAT_011da880)->FUN_0084e3a0();
        entry->amount = 0;
        tile = DAT_011dea3c->FUN_005a6260();
        if (!tile || tile->FUN_008256d0())
            tile->FUN_00726c60(entry);
        else
            tile->FUN_005ae3d0(entry);
        DAT_011da87c = (RouletteBetStandIn*)entry;
    }
    if (DAT_011dea3c->FUN_00969b80())
    {
        char message[260];
        FUN_00406d00(message, 260, DAT_01076274, g_011d2d24.String(), g_011d2274.String(),
                     DAT_011dea3c->FUN_00969b40());
        QueueUIMessage(message, 0, DAT_01049638, 0, DAT_010162c0, false);
        static_cast<RouletteAudio*>(BSAudio::GetSingleton())->GetSoundHandleByEditorID(DAT_01025cc4, 0x121).Play(false);
        return 0;
    }
    if (DAT_011da87c->iAmount >= ((CasinoForRoulette*)DAT_011da880)->FUN_00504e60()->limit)
    {
        char message[260];
        FUN_00406d00(message, 260, g_011d3abc.String());
        QueueUIMessage(message, 0, DAT_01049638, 0, DAT_010162c0, false);
        static_cast<RouletteAudio*>(BSAudio::GetSingleton())->GetSoundHandleByEditorID(DAT_01025cc4, 0x121).Play(false);
        return 0;
    }
    if (DAT_011dea3c->FUN_00575610(((CasinoForRoulette*)DAT_011da880)->FUN_007316d0()) < bet)
    {
        char message[260];
        FUN_00406d00(message, 260, g_011d2424.String());
        QueueUIMessage(message, 0, DAT_01049638, 0, DAT_010162c0, false);
        static_cast<RouletteAudio*>(BSAudio::GetSingleton())->GetSoundHandleByEditorID(DAT_01025cc4, 0x121).Play(false);
        return 0;
    }
    if (DAT_011da87c->iAmount < exchange && exchange != 0)
    {
        char message[260];
        FUN_00406d00(message, 260, g_011d3594.String());
        QueueUIMessage(message, 0, DAT_01049638, 0, DAT_010162c0, false);
        static_cast<RouletteAudio*>(BSAudio::GetSingleton())->GetSoundHandleByEditorID(DAT_01025cc4, 0x121).Play(false);
        return 0;
    }
    if (oldMenu)
        delete oldMenu;
    Tile* ui = list->FUN_00586150(DAT_01076254)->FUN_00a01b00();
    DAT_011da878 = static_cast<RouletteMenu*>(ui->FUN_00a03c90());
    if (DAT_011da878 && ((MenuVirtual*)DAT_011da878)->GetID() == FUN_007bc820())
    {
        ((RouletteMenu*)DAT_011da878)->unk3ffc = bet;
        ((RouletteMenu*)DAT_011da878)->unk4000 = arg3;
        ((RouletteMenu*)DAT_011da878)->unk3fe8 = bet;
        ((RouletteMenu*)DAT_011da878)->unk3ff0 =
            DAT_011dea3c->FUN_00575610(((CasinoForRoulette*)DAT_011da880)->FUN_007316d0());
        ((RouletteMenu*)DAT_011da878)->unk3FF4 = DAT_011dea3c->av.GetActorValueAsInteger(11);
        ((RouletteMenu*)DAT_011da878)->unk3fec = 0;
        DAT_011da878->FUN_00a1dc70(reinterpret_cast<TileMenu*>(ui), false);
        if (!static_cast<unsigned char>(DAT_011da878->HasAllTiles()))
        {
            FUN_005b5e40(DAT_01076200);
            ((RouletteMenu*)DAT_011da878)->unk0028 = 5;
            return 0;
        }
        if (ui->FUN_00a011b0(0xfa7) == DAT_010704f0 || ui->FUN_00a011b0(0xfa7) == DAT_010704e8)
            ui->FUN_00a012d0(0xfad, FUN_00a01530(1));
        ((Tile*)((RouletteMenu*)DAT_011da878)->m_pMaxBetTile)->FUN_00a01350(DAT_011da870, g_011d3804.String(), true);
        ((Tile*)((RouletteMenu*)DAT_011da878)->m_pMaxBetTile)->SetTraitFloat(DAT_011da86c, 1.0f);
        ((Tile*)((RouletteMenu*)DAT_011da878)->m_pMaxBetTile)
            ->FUN_00700320(DAT_011da86c, ((RouletteMenu*)DAT_011da878)->unk3fe8);
        ((Tile*)((RouletteMenu*)DAT_011da878)->m_pBetTile)->FUN_00a01350(DAT_011da870, g_011d3168.String(), true);
        ((Tile*)((RouletteMenu*)DAT_011da878)->m_pBetTile)->SetTraitFloat(DAT_011da86c, 1.0f);
        ((Tile*)((RouletteMenu*)DAT_011da878)->m_pBetTile)->FUN_00700320(DAT_011da86c, 0);
        ((Tile*)((RouletteMenu*)DAT_011da878)->m_pChipsTile)->FUN_00a01350(DAT_011da870, g_011d3300.String(), true);
        ((Tile*)((RouletteMenu*)DAT_011da878)->m_pChipsTile)->SetTraitFloat(DAT_011da86c, 1.0f);
        ((Tile*)((RouletteMenu*)DAT_011da878)->m_pChipsTile)
            ->FUN_00700320(DAT_011da86c, ((RouletteMenu*)DAT_011da878)->unk3ff0);
        char name[64];
        if (BSStringLength(DAT_011da880->fullName.GetFullName()))
            FUN_00406d00(name, 64, "%s %s", DAT_011da880->fullName.GetFullName(), g_011d3e08.String());
        else
            FUN_00406d00(name, 64, "%s %s", ((PlayerVirtual*)DAT_011da880)->GetName(), g_011d3e08.String());
        ((Tile*)(*reinterpret_cast<Tile**>(reinterpret_cast<char*>(DAT_011da878) + 0x34)))->FUN_00a01350(DAT_011da870, name, true);
        FUN_00a08b20((Tile*)(*reinterpret_cast<Tile**>(reinterpret_cast<char*>(DAT_011da878) + 0x34)), DAT_010761e4)->FUN_00700320(0xfa3, 0);
        FUN_00a08b20((Tile*)(*reinterpret_cast<Tile**>(reinterpret_cast<char*>(DAT_011da878) + 0x34)), DAT_010761e4)->SetChangeFlag(8);
        DAT_011da878->UpdateBetTileText();
        ((Tile*)(*reinterpret_cast<Tile**>(reinterpret_cast<char*>(DAT_011da878) + 0x38)))->FUN_00a01350(0xfc4, g_011d41e0.String(), true);
        ((Tile*)(*reinterpret_cast<Tile**>(reinterpret_cast<char*>(DAT_011da878) + 0x3c)))->FUN_00a01350(0xfc4, g_011d2c1c.String(), true);
        ((Tile*)(*reinterpret_cast<Tile**>(reinterpret_cast<char*>(DAT_011da878) + 0x40)))->FUN_00a01350(0xfc4, g_011d2820.String(), true);
        ((Tile*)(*reinterpret_cast<Tile**>(reinterpret_cast<char*>(DAT_011da878) + 0x44)))->FUN_00a01350(0xfc4, g_011d3354.String(), true);
        ((Tile*)(*reinterpret_cast<Tile**>(reinterpret_cast<char*>(DAT_011da878) + 0x48)))->FUN_00a01350(0xfc4, g_011d487c.String(), true);
        ((Tile*)(*reinterpret_cast<Tile**>(reinterpret_cast<char*>(DAT_011da878) + 0x4c)))->FUN_00a01350(0xfc4, g_011d33fc.String(), true);
        ((Tile*)((RouletteMenu*)DAT_011da878)->m_pInfoTile)->FUN_00a01350(0xfc4, " ", true);
        ((Tile*)((RouletteMenu*)DAT_011da878)->m_pInfoTile)->FUN_00700320(0xfa3, 1);
        DAT_011da878->ApplyValueToChain(5, DAT_0101e704);
        DAT_011da878->ApplyValueToChain(4, DAT_0101e704);
        DAT_011da878->ApplyValueToChain(7, DAT_0101e704);
        DAT_011da878->InitRouletteScene();
        DAT_011da878->FUN_00a1dc20(0);
        return ui;
    }
    else
    {
        if (DAT_011da878 && DAT_011da878->FUN_00726070())
            delete (MenuVirtual*)DAT_011da878;
    }
    return 0;
}

struct RouletteEntry
{
    int amount;
    int id;
    int objectIndex;
};
struct RouletteEntryNode
{
    RouletteEntry** FUN_006815c0();
    void FUN_0063f7b0();
    RouletteEntryNode* FUN_00726070();
};
struct RouletteObject
{
    NiPoint3& FUN_0043c490();
    void FUN_004bc1f0(float, float, float);
    void Update(const NiUpdateData&);
};
struct RouletteScene
{
    RouletteObject* FUN_0043b4a0(int);
};
// Searches the entry list for the entry with the given id, subtracts its amount, removes its object, updates the scene, and deletes the entry.
// @fnv 0x007bf150
bool RouletteMenu::RemoveEntryById(int id)
{
    if (id >= 159 || id < 0)
        return false;
    RouletteEntryNode* node = reinterpret_cast<RouletteEntryNode*>(unk3e78);
    while (node && *node->FUN_006815c0())
    {
        int entryId = (*node->FUN_006815c0())->id;
        if (entryId == id)
        {
            unk3fec -= (*node->FUN_006815c0())->amount;
            reinterpret_cast<RouletteMenu*>(this)->ResetSlotTransform((*node->FUN_006815c0())->objectIndex);
            if (unk3fe4 == 10)
            {
                unk3fe0 = (*node->FUN_006815c0())->objectIndex;
                FUN_007bf840();
                reinterpret_cast<RouletteScene*>(DAT_011da8a0.FUN_00559450())
                    ->FUN_0043b4a0(unk3fe0)
                    ->FUN_004bc1f0(reinterpret_cast<float&>(unk3fd4), reinterpret_cast<float&>(unk3fd8),
                                   reinterpret_cast<RouletteScene*>(DAT_011da8a0.FUN_00559450())
                                       ->FUN_0043b4a0(unk3fe0)
                                       ->FUN_0043c490()
                                       .z);
                reinterpret_cast<RouletteScene*>(DAT_011da8a0.FUN_00559450())
                    ->FUN_0043b4a0(unk3fe0 + 10)
                    ->FUN_004bc1f0(reinterpret_cast<float&>(unk3fd4), reinterpret_cast<float&>(unk3fd8), 0.0f);
                reinterpret_cast<RouletteScene*>(DAT_011da8a0.FUN_00559450())
                    ->FUN_0043b4a0(unk3fe0)
                    ->Update(NiUpdateData(0.0f, false, false));
                reinterpret_cast<RouletteScene*>(DAT_011da8a0.FUN_00559450())
                    ->FUN_0043b4a0(unk3fe0 + 10)
                    ->Update(NiUpdateData(0.0f, false, false));
            }
            --unk3fe4;
            RouletteEntry* entry = *node->FUN_006815c0();
            node->FUN_0063f7b0();
            delete entry;
            entry = 0;
            return true;
        }
        node = node->FUN_00726070();
    }
    return false;
}

namespace fnv_007bf480 {

extern const float runtimeFloatSettingDefault898;

// Resets the slot node and its shadow to the default Z translation and updates both with a zero-time update.
}

// @fnv 0x007bf480
void RouletteMenu::ResetSlotTransform(int iSlot)
{
    using fnv_007bf480::runtimeFloatSettingDefault898;
    reinterpret_cast<NiNode**>(&m_pRouletteWheel)[iSlot]->SetLocalTranslate(0.0f, 0.0f, runtimeFloatSettingDefault898);
    reinterpret_cast<NiNode**>(tilesA + 7)[iSlot]->SetLocalTranslate(0.0f, 0.0f, runtimeFloatSettingDefault898);
    reinterpret_cast<NiNode**>(&m_pRouletteWheel)[iSlot]->Update(NiUpdateData(0.0f, false, false));
    reinterpret_cast<NiNode**>(tilesA + 7)[iSlot]->Update(NiUpdateData(0.0f, false, false));
}


struct Member08
{
    Member08();
    ~Member08();
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};
struct List08
{
    int item, next;
    List08();
    ~List08();
};
int __cdecl FUN_00a00940(const char*, int);
extern const char DAT_01071ba0[];
extern const char DAT_01071b94[];
extern const char DAT_01071b88[];
extern const char DAT_01071b7c[];
extern const char DAT_01071b70[];
extern const char DAT_01073cc0[];
extern const char DAT_01071b64[];
extern const char DAT_01073cb4[];
extern int DAT_011daf6c;
extern int DAT_011daf60;
extern int DAT_011daf58;
extern int DAT_011daf64;
extern int DAT_011daf68;
extern int DAT_011daf78;
extern int DAT_011daf5c;
extern int DAT_011daf70;
struct FUN_007e6780 : Menu
{
    unsigned char layoutExtension[0x54 - sizeof(Menu)];
    Member08 member54;
    List08 list84;
    FUN_007e6780();
    virtual ~FUN_007e6780();
};
// Initializes eight global string handles by calling FUN_00a00940 with string constants and -1.
// @fnv 0x007e6780
FUN_007e6780::FUN_007e6780()
{
    DAT_011daf6c = FUN_00a00940(DAT_01071ba0, -1);
    DAT_011daf60 = FUN_00a00940(DAT_01071b94, -1);
    DAT_011daf58 = FUN_00a00940(DAT_01071b88, -1);
    DAT_011daf64 = FUN_00a00940(DAT_01071b7c, -1);
    DAT_011daf68 = FUN_00a00940(DAT_01071b70, -1);
    DAT_011daf78 = FUN_00a00940(DAT_01073cc0, -1);
    DAT_011daf5c = FUN_00a00940(DAT_01071b64, -1);
    DAT_011daf70 = FUN_00a00940(DAT_01073cb4, -1);
}

int __fastcall FUN_0045bb80(int);
namespace bf {
struct Slot
{
    NiPoint3 m_kPos;
    char pad[0x64 - 0xc];
};
}

// @fnv 0x007bf390
int RouletteMenu::FUN_007bf390()
{
    using bf::Slot;
    int i;
    for (i = 0; i < 0x90; i++)
    {
        NiPoint3 v = ((const NiPoint3*)FUN_0045bb80(m_iNode))->operator-(*reinterpret_cast<NiPoint3*>(&m_aSlots[i].unk10));
        float f = v.Length();
        if (f <= m_afRadius[0])
            break;
    }
    if (i == 0x90)
    {
        for (; i < 0x9f; i++)
        {
            NiPoint3 v2 = ((const NiPoint3*)FUN_0045bb80(m_iNode))->operator-(*reinterpret_cast<NiPoint3*>(&m_aSlots[i].unk10));
            float f2 = v2.Length();
            if (f2 <= m_afRadius[i - 0x8f])
                break;
        }
    }
    return i;
}


extern unsigned char DAT_011f426c;
extern double DAT_0106b168;
extern SettingT_GameSettingCollection_ DAT_011d3f4c;
extern SettingT_GameSettingCollection_ DAT_011d4dbc;
extern SettingT_GameSettingCollection_ DAT_011d4b88;
extern SettingT_GameSettingCollection_ DAT_011d264c;
extern SettingT_GameSettingCollection_ DAT_011d2dcc;
extern SettingT_GameSettingCollection_ DAT_011d32f4;
extern SettingT_GameSettingCollection_ DAT_011d2694;
extern SettingT_GameSettingCollection_ DAT_011d1df0;
extern SettingT_GameSettingCollection_ DAT_011d40c0;
extern SettingT_GameSettingCollection_ DAT_011d2d30;

int __cdecl FUN_00406d30(char*, unsigned int, const char*);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);

struct BoundRes
{
    NiPoint3* FUN_006815c0();
};
struct AVCalls
{
    void FUN_00450f90(int);
    BoundRes* FUN_0043d450();
};
struct VObj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual NiAVObject* Lookup(NiFixedString*);
};
NiAVObject* __cdecl FUN_004aae30(NiAVObject*, char*);
struct SubObj
{
    int unk00;
    int unk04;
    void FUN_005ae3d0(const int&);
};
struct Entry
{
    SubObj sub;
    int flag;
    int n2;
    NiPoint3 p;
    char code[8];
    char name[64];
};
// Builds the 159 roulette wheel entries (names, numbers, flags, positions) and computes the wheel geometry offsets.
// @fnv 0x007b9c40
void RouletteMenu::InitRouletteWheel()
{
    float localRemap_65;
    float localRemap_64;
    int kA;
    int gb4;
    int ga9;
    char localRemap_51[3];
    int gcVal;
    int localRemap_41;
    int localRemap_37;
    int idxGA;
    int localRemap_36;
    int localIndexVal;
    int idxF_;
    int localIndex7;
    int idxD2;
    int idxC6;
    int local83;
    int local80;
    int local46;
    int local23;
    int local20;
    char local1;
    NiAVObject* local3;
    char buf42[8];
    char local2;
    char cA3;
    cA3 = 'A';
    local2 = '0';
    local1 = '1';

    for (local20 = 0; local20 < 159; local20++)
    {
        reinterpret_cast<Entry*>(m_aSlots)[local20].p = *(const NiPoint3*)&DAT_011f426c;
    }

    for (local23 = 0; local23 < 159; local23++)
    {
        FUN_00406d00(buf42, 8, "%c%c%c:0", cA3, local2, local1);
        if (cA3 == 'B' || cA3 == 'D' || cA3 == 'F')
        {
            if ((local1 % 2) == 0)
            {

                local46 = (local23 / 24 + 1) / 2 + (local23 % 24 / 2) * 3;
                FUN_00406d00(reinterpret_cast<Entry*>(m_aSlots)[local23].name, 64, "%s: %i \n%s: 35:1", DAT_011d4dbc.String(), local46,
                             DAT_011d3f4c.String());
                reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(local46);
                if ((local46 % 2) == 0 && local46 < 11)
                    reinterpret_cast<Entry*>(m_aSlots)[local23].flag = 1;
                else if (local46 < 11)
                    reinterpret_cast<Entry*>(m_aSlots)[local23].flag = 2;
                else if ((local46 % 2) == 0 && local46 < 19)
                    reinterpret_cast<Entry*>(m_aSlots)[local23].flag = 2;
                else if (local46 < 19)
                    reinterpret_cast<Entry*>(m_aSlots)[local23].flag = 1;
                else if ((local46 % 2) == 0 && local46 < 28)
                    reinterpret_cast<Entry*>(m_aSlots)[local23].flag = 1;
                else if (local46 < 28)
                    reinterpret_cast<Entry*>(m_aSlots)[local23].flag = 2;
                else if ((local46 % 2) != 0)
                    reinterpret_cast<Entry*>(m_aSlots)[local23].flag = 2;
                else
                    reinterpret_cast<Entry*>(m_aSlots)[local23].flag = 1;
                reinterpret_cast<Entry*>(m_aSlots)[local23].n2 = 35;
            }
            else if (local23 % 24 != 0)
            {

                local80 = (local23 / 24 + 1) / 2 + ((local23 - 1) % 24 / 2) * 3;
                local83 = local80 + 3;
                FUN_00406d00(reinterpret_cast<Entry*>(m_aSlots)[local23].name, 64, "%s: %i,%i \n%s: 17:1", DAT_011d4dbc.String(), local80, local83,
                             DAT_011d3f4c.String());
                reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(local80);
                reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(local83);
                reinterpret_cast<Entry*>(m_aSlots)[local23].flag = 0;
                reinterpret_cast<Entry*>(m_aSlots)[local23].n2 = 17;
            }
            else if (local23 % 24 == 0)
            {
                idxC6 = (local23 / 24 + 1) / 2 + ((local23 + 1) % 24 / 2) * 3;
                if (cA3 == 'D')
                {
                    FUN_00406d00(reinterpret_cast<Entry*>(m_aSlots)[local23].name, 64, "%s: %s,%i \n%s: 11:1", "0,00", DAT_011d4dbc.String(),
                                 idxC6, DAT_011d3f4c.String());
                    reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(37);
                    reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(0);
                    reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(idxC6);
                    reinterpret_cast<Entry*>(m_aSlots)[local23].flag = 0;
                    reinterpret_cast<Entry*>(m_aSlots)[local23].n2 = 11;
                }
                else if (cA3 == 'F')
                {
                    FUN_00406d00(reinterpret_cast<Entry*>(m_aSlots)[local23].name, 64, "%s: %s,%i \n%s: 17:1", "00", DAT_011d4dbc.String(), idxC6,
                                 DAT_011d3f4c.String());
                    reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(37);
                    reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(idxC6);
                    reinterpret_cast<Entry*>(m_aSlots)[local23].flag = 0;
                    reinterpret_cast<Entry*>(m_aSlots)[local23].n2 = 17;
                }
                else
                {
                    FUN_00406d00(reinterpret_cast<Entry*>(m_aSlots)[local23].name, 64, "%s: %s,%i \n%s: 17:1", "0", DAT_011d4dbc.String(), idxC6,
                                 DAT_011d3f4c.String());
                    reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(0);
                    reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(idxC6);
                    reinterpret_cast<Entry*>(m_aSlots)[local23].flag = 0;
                    reinterpret_cast<Entry*>(m_aSlots)[local23].n2 = 17;
                }
            }
        }
        else if (cA3 == 'A')
        {
            if ((local23 % 2) == 1)
            {

                idxD2 = (local23 % 24 / 2) * 3 + 1;
                FUN_00406d00(reinterpret_cast<Entry*>(m_aSlots)[local23].name, 64, "%s: %i,%i,%i \n%s: 11:1", DAT_011d4dbc.String(), idxD2,
                             idxD2 + 1, idxD2 + 2, DAT_011d3f4c.String());
                reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(idxD2);
                reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(idxD2 + 1);
                reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(idxD2 + 2);
                reinterpret_cast<Entry*>(m_aSlots)[local23].flag = 0;
                reinterpret_cast<Entry*>(m_aSlots)[local23].n2 = 11;
            }
            else if (local23 != 0)
            {

                localIndex7 = ((local23 - 1) % 24 / 2) * 3 + 1;
                FUN_00406d00(reinterpret_cast<Entry*>(m_aSlots)[local23].name, 64, "%s: %i,%i,%i,%i,%i,%i \n%s: 5:1", DAT_011d4dbc.String(),
                             localIndex7, localIndex7 + 1, localIndex7 + 2, localIndex7 + 3, localIndex7 + 4,
                             localIndex7 + 5, DAT_011d3f4c.String());
                reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(localIndex7);
                reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(localIndex7 + 1);
                reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(localIndex7 + 2);
                reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(localIndex7 + 3);
                reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(localIndex7 + 4);
                reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(localIndex7 + 5);
                reinterpret_cast<Entry*>(m_aSlots)[local23].flag = 0;
                reinterpret_cast<Entry*>(m_aSlots)[local23].n2 = 5;
            }
            else if (local23 == 0)
            {
                FUN_00406d00(reinterpret_cast<Entry*>(m_aSlots)[local23].name, 64, "%s: 0,00,1,2,3 \n%s: 6:1", DAT_011d4dbc.String(),
                             DAT_011d3f4c.String());
                reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(0);
                reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(37);
                reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(1);
                reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(2);
                reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(3);
                reinterpret_cast<Entry*>(m_aSlots)[local23].flag = 0;
                reinterpret_cast<Entry*>(m_aSlots)[local23].n2 = 6;
            }
        }
        else if (cA3 != 'S')
        {
            if ((local1 % 2) == 0)
            {

                idxF_ = (local23 / 24 + 1) / 2 + (local23 % 24 / 2) * 3;
                localIndexVal = idxF_ + 1;
                FUN_00406d00(reinterpret_cast<Entry*>(m_aSlots)[local23].name, 64, "%s: %i,%i \n%s: 17:1", DAT_011d4dbc.String(), idxF_,
                             localIndexVal, DAT_011d3f4c.String());
                reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(idxF_);
                reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(localIndexVal);
                reinterpret_cast<Entry*>(m_aSlots)[local23].flag = 0;
                reinterpret_cast<Entry*>(m_aSlots)[local23].n2 = 17;
            }
            else if (local23 % 24 != 0)
            {

                idxGA = (local23 / 24 + 1) / 2 + ((local23 - 1) % 24 / 2) * 3;
                localRemap_41 = idxGA + 1;
                localRemap_36 = idxGA + 3;
                localRemap_37 = localRemap_36 + 1;
                FUN_00406d00(reinterpret_cast<Entry*>(m_aSlots)[local23].name, 64, "%s: %i,%i,%i,%i \n%s: 8:1", DAT_011d4dbc.String(), idxGA,
                             localRemap_41, localRemap_36, localRemap_37, DAT_011d3f4c.String());
                reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(idxGA);
                reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(localRemap_41);
                reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(localRemap_36);
                reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(localRemap_37);
                reinterpret_cast<Entry*>(m_aSlots)[local23].flag = 0;
                reinterpret_cast<Entry*>(m_aSlots)[local23].n2 = 8;
            }
            else
            {
                ga9 = (cA3 != 'C') + 1;
                gb4 = (cA3 != 'C') + 2;
                gcVal = (cA3 != 'C') ? 37 : 0;

                cA3 == 'C' ? FUN_00406d30(localRemap_51, 3, "0") : FUN_00406d30(localRemap_51, 3, "00");
                FUN_00406d00(reinterpret_cast<Entry*>(m_aSlots)[local23].name, 64, "%s: %s,%i,%i \n%s: 11:1", DAT_011d4dbc.String(), localRemap_51,
                             ga9, gb4, DAT_011d3f4c.String());
                reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(ga9);
                reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(gb4);
                reinterpret_cast<Entry*>(m_aSlots)[local23].sub.FUN_005ae3d0(gcVal);
                reinterpret_cast<Entry*>(m_aSlots)[local23].flag = 0;
                reinterpret_cast<Entry*>(m_aSlots)[local23].n2 = 11;
            }
        }
        local1++;
        if (local1 > '9')
        {
            local1 = '0';
            local2++;
        }
        if (local1 == '5' && local2 == '2')
        {
            cA3++;
            if (local23 >= 143)
                cA3 = 'S';
            local2 = '0';
            local1 = '1';
        }
        local3 = FUN_004aae30((NiAVObject*)reinterpret_cast<VObj*>(m_pTableNode), buf42);
        if (local3 == 0)
        {
            local3 = reinterpret_cast<VObj*>(m_pTableNode)->Lookup(&NiFixedString(static_cast<const char*>(buf42)));
        }
        ((AVCalls*)local3)->FUN_00450f90(1);
        reinterpret_cast<Entry*>(m_aSlots)[local23].p = *((AVCalls*)local3)->FUN_0043d450()->FUN_006815c0();
        FUN_00406d30(reinterpret_cast<Entry*>(m_aSlots)[local23].code, 8, buf42);
    }

    NiPoint3 diffA = ((NiPoint3&)reinterpret_cast<Entry*>(m_aSlots)[0].p).operator-(reinterpret_cast<Entry*>(m_aSlots)[1].p);
    unk3F90 = diffA.Length();
    m_afRadius[0] = (float)(unk3F90 * DAT_0106b168);

    for (kA = 0x90; kA < 159; kA++)
    {

        if (kA - 0x90 == 0)
        {
            localRemap_65 = reinterpret_cast<Entry*>(m_aSlots)[kA].p.x - reinterpret_cast<Entry*>(m_aSlots)[0].p.x;
            localRemap_64 = reinterpret_cast<Entry*>(m_aSlots)[kA].p.y - reinterpret_cast<Entry*>(m_aSlots)[kA + 1].p.y;
            localRemap_65 < 0.0 ? (localRemap_65 = (float)(localRemap_65 * -0.4900000095367431640625))
                                : (localRemap_65 = (float)(localRemap_65 * 0.4900000095367431640625));
            localRemap_64 < 0.0 ? (localRemap_64 = (float)(localRemap_64 * -0.4900000095367431640625))
                                : (localRemap_64 = (float)(localRemap_64 * 0.4900000095367431640625));
            m_afRadius[1] = m_afRadius[2] = m_afRadius[3] = localRemap_65 < localRemap_64 ? localRemap_65 : localRemap_64;
            FUN_00406d00(reinterpret_cast<Entry*>(m_aSlots)[kA].name, 64, "%s: 00 \n%s: 35:1", DAT_011d4dbc.String(), DAT_011d3f4c.String());
            FUN_00406d00(reinterpret_cast<Entry*>(m_aSlots)[kA + 1].name, 64, "%s: 0,00 \n%s: 17:1", DAT_011d4dbc.String(), DAT_011d3f4c.String());
            FUN_00406d00(reinterpret_cast<Entry*>(m_aSlots)[kA + 2].name, 64, "%s: 0 \n%s: 35:1", DAT_011d4dbc.String(), DAT_011d3f4c.String());
            reinterpret_cast<Entry*>(m_aSlots)[kA].sub.FUN_005ae3d0(37);
            reinterpret_cast<Entry*>(m_aSlots)[kA + 1].sub.FUN_005ae3d0(37);
            reinterpret_cast<Entry*>(m_aSlots)[kA + 1].sub.FUN_005ae3d0(0);
            reinterpret_cast<Entry*>(m_aSlots)[kA + 2].sub.FUN_005ae3d0(0);
            reinterpret_cast<Entry*>(m_aSlots)[kA].flag = 0;
            reinterpret_cast<Entry*>(m_aSlots)[kA + 1].flag = 0;
            reinterpret_cast<Entry*>(m_aSlots)[kA + 2].flag = 0;
            reinterpret_cast<Entry*>(m_aSlots)[kA].n2 = 35;
            reinterpret_cast<Entry*>(m_aSlots)[kA + 1].n2 = 17;
            reinterpret_cast<Entry*>(m_aSlots)[kA + 2].n2 = 35;
        }

        if (kA - 0x90 == 3)
        {
            localRemap_65 = reinterpret_cast<Entry*>(m_aSlots)[kA].p.x - reinterpret_cast<Entry*>(m_aSlots)[kA + 3].p.y;
            localRemap_64 = reinterpret_cast<Entry*>(m_aSlots)[kA].p.y - reinterpret_cast<Entry*>(m_aSlots)[0].p.y;
            localRemap_65 < 0.0 ? (localRemap_65 = (float)(localRemap_65 * -0.4900000095367431640625))
                                : (localRemap_65 = (float)(localRemap_65 * 0.4900000095367431640625));
            localRemap_64 < 0.0 ? (localRemap_64 = (float)(localRemap_64 * -0.4900000095367431640625))
                                : (localRemap_64 = (float)(localRemap_64 * 0.4900000095367431640625));
            m_afRadius[4] = m_afRadius[7] = m_afRadius[10] = localRemap_65 < localRemap_64 ? localRemap_65 : localRemap_64;
            FUN_00406d00(reinterpret_cast<Entry*>(m_aSlots)[kA].name, 64, "%s: %s \n%s: 2:1", DAT_011d4dbc.String(), DAT_011d4b88.String(),
                         DAT_011d3f4c.String());
            FUN_00406d00(reinterpret_cast<Entry*>(m_aSlots)[kA + 3].name, 64, "%s: %s \n%s: 2:1", DAT_011d4dbc.String(), DAT_011d264c.String(),
                         DAT_011d3f4c.String());
            FUN_00406d00(reinterpret_cast<Entry*>(m_aSlots)[kA + 6].name, 64, "%s: %s \n%s: 2:1", DAT_011d4dbc.String(), DAT_011d2dcc.String(),
                         DAT_011d3f4c.String());
            reinterpret_cast<Entry*>(m_aSlots)[kA].flag = 0;
            reinterpret_cast<Entry*>(m_aSlots)[kA + 3].flag = 0;
            reinterpret_cast<Entry*>(m_aSlots)[kA + 6].flag = 0;
            reinterpret_cast<Entry*>(m_aSlots)[kA].n2 = 2;
            reinterpret_cast<Entry*>(m_aSlots)[kA + 3].n2 = 2;
            reinterpret_cast<Entry*>(m_aSlots)[kA + 6].n2 = 2;
        }

        if (kA - 0x90 == 4)
        {
            localRemap_65 = reinterpret_cast<Entry*>(m_aSlots)[kA].p.x - reinterpret_cast<Entry*>(m_aSlots)[kA + 1].p.y;
            localRemap_64 = reinterpret_cast<Entry*>(m_aSlots)[kA].p.y - reinterpret_cast<Entry*>(m_aSlots)[3].p.y;
            localRemap_65 < 0.0 ? (localRemap_65 = (float)(localRemap_65 * -0.4900000095367431640625))
                                : (localRemap_65 = (float)(localRemap_65 * 0.4900000095367431640625));
            localRemap_64 < 0.0 ? (localRemap_64 = (float)(localRemap_64 * -0.4900000095367431640625))
                                : (localRemap_64 = (float)(localRemap_64 * 0.4900000095367431640625));
            m_afRadius[5] = m_afRadius[6] = m_afRadius[8] = m_afRadius[9] = m_afRadius[11] = m_afRadius[12] =
                localRemap_65 < localRemap_64 ? localRemap_65 : localRemap_64;
            FUN_00406d00(reinterpret_cast<Entry*>(m_aSlots)[kA].name, 64, "%s: 1-18 \n%s: 1:1", DAT_011d4dbc.String(), DAT_011d3f4c.String());
            FUN_00406d00(reinterpret_cast<Entry*>(m_aSlots)[kA + 1].name, 64, "%s: %s \n%s: 1:1", DAT_011d4dbc.String(), DAT_011d2694.String(),
                         DAT_011d3f4c.String());
            FUN_00406d00(reinterpret_cast<Entry*>(m_aSlots)[kA + 3].name, 64, "%s: %s \n%s: 1:1", DAT_011d4dbc.String(), DAT_011d1df0.String(),
                         DAT_011d3f4c.String());
            FUN_00406d00(reinterpret_cast<Entry*>(m_aSlots)[kA + 4].name, 64, "%s: %s \n%s: 1:1", DAT_011d4dbc.String(), DAT_011d40c0.String(),
                         DAT_011d3f4c.String());
            FUN_00406d00(reinterpret_cast<Entry*>(m_aSlots)[kA + 6].name, 64, "%s: %s \n%s: 1:1", DAT_011d4dbc.String(), DAT_011d2d30.String(),
                         DAT_011d3f4c.String());
            FUN_00406d00(reinterpret_cast<Entry*>(m_aSlots)[kA + 7].name, 64, "%s: 19-36 \n%s: 1:1", DAT_011d4dbc.String(), DAT_011d3f4c.String());
            reinterpret_cast<Entry*>(m_aSlots)[kA].flag = 0;
            reinterpret_cast<Entry*>(m_aSlots)[kA + 1].flag = 0;
            reinterpret_cast<Entry*>(m_aSlots)[kA + 3].flag = 0;
            reinterpret_cast<Entry*>(m_aSlots)[kA + 4].flag = 0;
            reinterpret_cast<Entry*>(m_aSlots)[kA + 6].flag = 0;
            reinterpret_cast<Entry*>(m_aSlots)[kA + 7].flag = 0;
            reinterpret_cast<Entry*>(m_aSlots)[kA].n2 = 1;
            reinterpret_cast<Entry*>(m_aSlots)[kA + 1].n2 = 1;
            reinterpret_cast<Entry*>(m_aSlots)[kA + 3].n2 = 1;
            reinterpret_cast<Entry*>(m_aSlots)[kA + 4].n2 = 1;
            reinterpret_cast<Entry*>(m_aSlots)[kA + 6].n2 = 1;
            reinterpret_cast<Entry*>(m_aSlots)[kA + 7].n2 = 1;
        }

        if (kA - 0x90 == 12)
        {
            localRemap_65 = reinterpret_cast<Entry*>(m_aSlots)[kA].p.x - reinterpret_cast<Entry*>(m_aSlots)[23].p.x;
            localRemap_64 = reinterpret_cast<Entry*>(m_aSlots)[kA].p.y - reinterpret_cast<Entry*>(m_aSlots)[kA + 1].p.y;
            localRemap_65 < 0.0 ? (localRemap_65 = (float)(localRemap_65 * -0.4900000095367431640625))
                                : (localRemap_65 = (float)(localRemap_65 * 0.4900000095367431640625));
            localRemap_64 < 0.0 ? (localRemap_64 = (float)(localRemap_64 * -0.4900000095367431640625))
                                : (localRemap_64 = (float)(localRemap_64 * 0.4900000095367431640625));
            m_afRadius[13] = m_afRadius[14] = m_afRadius[15] = localRemap_65 < localRemap_64 ? localRemap_65 : localRemap_64;
            FUN_00406d00(reinterpret_cast<Entry*>(m_aSlots)[kA].name, 64, "%s: %s \n%s: 2:1", DAT_011d4dbc.String(), DAT_011d32f4.String(),
                         DAT_011d3f4c.String());
            FUN_00406d00(reinterpret_cast<Entry*>(m_aSlots)[kA + 1].name, 64, "%s: %s \n%s: 2:1", DAT_011d4dbc.String(), DAT_011d32f4.String(),
                         DAT_011d3f4c.String());
            FUN_00406d00(reinterpret_cast<Entry*>(m_aSlots)[kA + 2].name, 64, "%s: %s \n%s: 2:1", DAT_011d4dbc.String(), DAT_011d32f4.String(),
                         DAT_011d3f4c.String());
            reinterpret_cast<Entry*>(m_aSlots)[kA].flag = 0;
            reinterpret_cast<Entry*>(m_aSlots)[kA + 1].flag = 0;
            reinterpret_cast<Entry*>(m_aSlots)[kA + 2].flag = 0;
            reinterpret_cast<Entry*>(m_aSlots)[kA].n2 = 2;
            reinterpret_cast<Entry*>(m_aSlots)[kA + 1].n2 = 2;
            reinterpret_cast<Entry*>(m_aSlots)[kA + 2].n2 = 2;
        }
    }
    int arr17[38] = {14, 2, 0,  28, 9,  26, 30, 11, 7, 20, 32, 17, 5, 22, 34, 15, 3, 24, 36,
                     13, 1, 37, 27, 10, 25, 29, 12, 8, 19, 31, 18, 6, 21, 33, 16, 4, 23, 35};
    memcpy(m_aiPocketNumbers, arr17, 0x98);
    m_bLimitUp = 0;
}

namespace fnv_007bd2a0 {

struct InterfaceMgr
{
    Tile* FUN_0045cd60();
};
InterfaceMgr* __cdecl FUN_004b7210();
bool __cdecl FUN_004b71d0();

// Exe 0x007bd2a0: unit-local ListNode view; declarations and layout are preserved.
struct RoulettemenuListNodeView
{
    void* pItem;
    RoulettemenuListNodeView* pNext;
    int* FUN_006815c0();
    RoulettemenuListNodeView* FUN_00726070();
    void FUN_0063f7b0();
};

struct RouletteBetEntry
{
    int iAmount;
    int iSlotC;
};

struct BetSlot
{
    RoulettemenuListNodeView kNumbers;
    int unk08;
    int iOdds;
    int unk10;
    int unk14;
    int unk18;
    char szNodeName[8];
    char szLabel[64];
};


struct ColorFlags
{
    float fValue;
    bool bA;
    bool bB;
    bool bC;
    bool bD;
    bool bE;
    ColorFlags(float afValue, bool abA, bool abB);
};

struct FixedStr
{
    const char* pString;
    FixedStr(const char* apString);
    ~FixedStr();
};

struct NiObj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual NiObj* GetObjectByName(const FixedStr& arName);
    void FUN_00450f90(bool abHidden);
    bool FUN_00456610();
    NiObj* FUN_0043b4a0(int aiIndex);
    NiPoint3* FUN_0043c490();
    void FUN_004bc1f0(float x, float y, float z);
    void FUN_00a59c60(const ColorFlags& arFlags);
};
NiObj* __cdecl FUN_004aae30(NiObj* apRoot, const char* apName);


struct AnimSeq
{
    float FUN_00508100();
};

struct AnimCtrl
{
    void FUN_0047aab0(AnimSeq* apSeq, int a2, int a3, float afWeight, float afTime, int a6);
    void FUN_0047b220(AnimSeq* apSeq, float afTime);
};

AudioMgr_BSAudio* __cdecl FUN_00453a70();

void __cdecl FUN_00406f60(BSString* apStr, const char* apFormat, ...);
int __cdecl FUN_00406d00(char* apBuf, int aiSize, const char* apFormat, ...);
void __cdecl DispatchMessageToSink(const char* apText, int a2, const char* apIcon, int aiSound, float afTime, int a6);


extern Setting DAT_011d3114;
extern Setting DAT_011d3db4;
extern Setting DAT_011d3abc;
extern Setting DAT_011d4e7c;
extern Setting DAT_011d3a98;
extern Setting DAT_011d2ff4;
extern Setting DAT_011d5050;
extern Setting DAT_011d3474;
extern Setting DAT_011d3f88;
extern Setting DAT_011d3f4c;
extern Setting DAT_011d4dbc;
extern Setting DAT_011d2424;

struct FormX
{
    int unk00;
    unsigned int GetRefID();
};
const char* __cdecl FUN_00482720(FormX* apForm);

struct PlayerX
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void RemoveItem(FormX* apForm, int a2, int aiCount, int a4, int a5, int a6, int a7, int a8, int a9,
                            int a10);
    int FUN_00575610(FormX* apForm);
    int FUN_008adcf0(FormX* apForm, int a2, int a3);
};
extern PlayerX* DAT_011dea3c;

// This chip-change path uses the explicit init/cleanup pair, not the default lifecycle.


struct CasinoStats
{
    int unk00;
    int iEarnings;
    short sLevel;
};
extern CasinoStats* DAT_011da87c;

struct CasinoLimits
{
    int unk[10];
    int iMaxWin;
};

struct NotifyObj
{
    void FUN_0060c9c0(int a1);
};

struct CasinoX
{
    FormX* FUN_007316d0();
    int GetFieldAt210();
    NotifyObj* FUN_00504e40();
    CasinoLimits* FUN_00504e60();
};
extern CasinoX* DAT_011da880;

struct GamepadX
{
    int GetAxisState(int a1, int a2);
    int FUN_00a239e0(int a1);
};
struct InputX
{
    GamepadX* FUN_00877720();
};
extern InputX* DAT_011dea0c;

struct TimerX
{
    int FUN_00825c00();
};
extern TimerX DAT_011f6394;

extern NiObjPtr DAT_011da8a0;
extern int DAT_011da86c;
extern int DAT_011da870;

bool __cdecl FUN_00702450(int a1);
float __cdecl FUN_00408820(float a1);
double __cdecl FUN_00715d40();
double __cdecl FUN_00706e50();

static float s_fSpinTime;
static int s_iLastState = 4;
static bool s_bValidBet;

// Updates the roulette menu state machine, handling spin animation, bet resolution, chip movement, and UI feedback based on m_iFadeIndex.
}

// @fnv 0x007bd2a0
void RouletteMenu::FUN_007bd2a0()
{
    using fnv_007bd2a0::InterfaceMgr;
    using fnv_007bd2a0::FUN_004b7210;
    using fnv_007bd2a0::FUN_004b71d0;
    using fnv_007bd2a0::RouletteBetEntry;
    using fnv_007bd2a0::ColorFlags;
    using fnv_007bd2a0::FixedStr;
    using fnv_007bd2a0::NiObj;
    using fnv_007bd2a0::FUN_004aae30;
    using fnv_007bd2a0::AnimSeq;
    using fnv_007bd2a0::AnimCtrl;
    using fnv_007bd2a0::FUN_00453a70;
    using fnv_007bd2a0::FUN_00406f60;
    using fnv_007bd2a0::FUN_00406d00;
    using fnv_007bd2a0::DispatchMessageToSink;
    using fnv_007bd2a0::DAT_011d3114;
    using fnv_007bd2a0::DAT_011d3db4;
    using fnv_007bd2a0::DAT_011d3abc;
    using fnv_007bd2a0::DAT_011d4e7c;
    using fnv_007bd2a0::DAT_011d3a98;
    using fnv_007bd2a0::DAT_011d2ff4;
    using fnv_007bd2a0::DAT_011d5050;
    using fnv_007bd2a0::DAT_011d3474;
    using fnv_007bd2a0::DAT_011d3f88;
    using fnv_007bd2a0::DAT_011d3f4c;
    using fnv_007bd2a0::DAT_011d4dbc;
    using fnv_007bd2a0::DAT_011d2424;
    using fnv_007bd2a0::FormX;
    using fnv_007bd2a0::FUN_00482720;
    using fnv_007bd2a0::PlayerX;
    using fnv_007bd2a0::DAT_011dea3c;
    using fnv_007bd2a0::CasinoStats;
    using fnv_007bd2a0::DAT_011da87c;
    using fnv_007bd2a0::CasinoLimits;
    using fnv_007bd2a0::NotifyObj;
    using fnv_007bd2a0::CasinoX;
    using fnv_007bd2a0::DAT_011da880;
    using fnv_007bd2a0::GamepadX;
    using fnv_007bd2a0::InputX;
    using fnv_007bd2a0::DAT_011dea0c;
    using fnv_007bd2a0::TimerX;
    using fnv_007bd2a0::DAT_011f6394;
    using fnv_007bd2a0::DAT_011da8a0;
    using fnv_007bd2a0::DAT_011da86c;
    using fnv_007bd2a0::DAT_011da870;
    using fnv_007bd2a0::FUN_00702450;
    using fnv_007bd2a0::FUN_00408820;
    using fnv_007bd2a0::FUN_00715d40;
    using fnv_007bd2a0::FUN_00706e50;
    using fnv_007bd2a0::s_fSpinTime;
    using fnv_007bd2a0::s_iLastState;
    using fnv_007bd2a0::s_bValidBet;
    int iElapsed = 0;
    float fMoveX4 = 1.0f;
    float fMoveY4 = 1.0f;
    static BSSoundHandle kSpinSound;
    bool bActive2 = FUN_00702450(GetClass());
    if (m_iLastTime == 0)
    {
        iElapsed = 0;
        s_fSpinTime = 0.0f;
    }
    else if (bActive2)
    {
        iElapsed = DAT_011f6394.FUN_00825c00() - m_iLastTime;
        if (iElapsed > 1000)
        {
            iElapsed = 0;
        }
        if (s_iLastState != m_iFadeIndex)
        {
            s_fSpinTime = 0.0f;
        }
        else
        {
            s_fSpinTime += iElapsed / 1000.0;
        }
    }
    if (!bActive2)
    {
        FUN_004b7210()->FUN_0045cd60()->FUN_00a012d0(0xfa9, 255.0f, true);
    }
    else
    {
        FUN_004b7210()->FUN_0045cd60()->FUN_00a012d0(0xfa9, 0.0f, true);
    }
    int iStickX3 = 0;
    int iStickY5 = 0;
    int iStickZ4 = 0;
    int iStickMax7 = 0x7fff;
    FUN_004b7210();
    if (FUN_004b71d0())
    {
        iStickX3 = DAT_011dea0c->FUN_00877720()->GetAxisState(0, 7);
        iStickY5 = DAT_011dea0c->FUN_00877720()->GetAxisState(0, 8);
        if (FUN_00408820((float)iStickX3) <= 7849.0)
        {
            iStickX3 = 0;
        }
        if (FUN_00408820((float)iStickZ4) <= 7849.0)
        {
            iStickZ4 = 0;
        }
        fMoveX4 = -iStickX3 / 32767.0;
        if (FUN_00408820((float)iStickY5) <= 7849.0)
        {
            iStickY5 = 0;
        }
        fMoveY4 = -iStickY5 / 32767.0;
    }
    else
    {
        fMoveX4 = -DAT_011dea0c->FUN_00877720()->FUN_00a239e0(1) * (FUN_00715d40() / FUN_00706e50()) / 10.0;
        fMoveY4 = DAT_011dea0c->FUN_00877720()->FUN_00a239e0(2) * (FUN_00715d40() / FUN_00706e50()) / 10.0;
    }
    m_iLastTime = DAT_011f6394.FUN_00825c00();
    s_iLastState = m_iFadeIndex;
    switch (m_iFadeIndex)
    {
    case 5:
        if (FUN_0059bb30() != 2)
        {
            FUN_004b7210()->FUN_0045cd60()->FUN_00a012d0(0xfa9, 255.0f, true);
            FUN_00726070()->FUN_00700320(0x1772, 1);
            FUN_00a1d910();
            int iChipDiff;
            if ((iChipDiff = m_iChips - DAT_011dea3c->FUN_00575610(DAT_011da880->FUN_007316d0())) < 0)
            {
                DAT_011dea3c->RemoveItem(DAT_011da880->FUN_007316d0(), 0, -iChipDiff, 0, 0, 0, 0, 0, 1, 0);
                BSString kLostMsg;
                FUN_00406f60(&kLostMsg, "%i %s%s %s", -iChipDiff, FUN_00482720(DAT_011da880->FUN_007316d0()),
                             DAT_011d3114.FUN_00403df0(), DAT_011d3db4.FUN_00403df0());
                DispatchMessageToSink(kLostMsg.CStr(), 0,
                                      "Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds",
                                      DAT_011dea3c->FUN_008adcf0(DAT_011da880->FUN_007316d0(), 1, 0), 2.0f, 0);
            }
            else if (iChipDiff > 0)
            {
                // the chip change is a temporary TESContainer (ctor 0x00481610, dtor 0x00481680)
                TESContainer kChange;
                kChange.AddObject(reinterpret_cast<TESForm*>(DAT_011da880->FUN_007316d0()), iChipDiff, 0);
                if (DAT_011da87c->iEarnings < DAT_011da880->GetFieldAt210())
                {
                    kChange.FUN_004821a0(reinterpret_cast<TESObjectREFR*>(DAT_011dea3c), false);
                }
                else
                {
                    kChange.FUN_004821a0(reinterpret_cast<TESObjectREFR*>(DAT_011dea3c), true);
                    BSString kWonMsg;
                    FUN_00406f60(&kWonMsg, "%i %s%s %s\n%s", iChipDiff, FUN_00482720(DAT_011da880->FUN_007316d0()),
                                 DAT_011d3114.FUN_00403df0(), DAT_011d4e7c.FUN_00403df0(), DAT_011d3abc.FUN_00403df0());
                    DispatchMessageToSink(kWonMsg.CStr(), 0,
                                          "Interface\\Icons\\Message Icons\\glow_message_vaultboy_very_happy.dds",
                                          DAT_011dea3c->FUN_008adcf0(DAT_011da880->FUN_007316d0(), 1, 0), 2.0f, 0);
                }
            }
            if (m_bLimitUp)
            {
                NotifyObj* pNotify = DAT_011da880->FUN_00504e40();
                if (pNotify)
                {
                    pNotify->FUN_0060c9c0(1);
                }
            }
        }
        break;
    case 1:
        if (reinterpret_cast<AnimSeq*>(m_apSpinSeq[m_iRouletteResult]) == 0)
        {
            break;
        }
        if (s_fSpinTime == 0.0)
        {
            reinterpret_cast<RouletteAudio*>(FUN_00453a70())->GetSoundHandleByEditorID("GAMERouletteSpin", 0x121).Play(false);
            m_pInfoTile->FUN_00700320(0xfa3, 0);
            reinterpret_cast<AnimCtrl*>(m_pAnimCtrl)->FUN_0047aab0(reinterpret_cast<AnimSeq*>(m_apSpinSeq[m_iRouletteResult]), 0, 0, 1.0f, 0.0f, 0);
            m_bSpinning = true;
            RotateRouletteWheelToResult(m_iResult);
        }
        if (1)
        {
            ColorFlags kBallFlags(s_fSpinTime, true, false);
            reinterpret_cast<NiObj*>(DAT_011da8a0.FUN_00559450())->FUN_0043b4a0(0)->FUN_00a59c60(kBallFlags);
        }
        if (reinterpret_cast<AnimSeq*>(m_apSpinSeq[m_iRouletteResult])->FUN_00508100() / 2.0 < s_fSpinTime && m_bSpinning)
        {
            FUN_007bf7a0();
            m_iChipNode = 3;
            NiPoint3 kPos = *reinterpret_cast<NiObj*>(DAT_011da8a0.FUN_00559450())->FUN_0043b4a0(2)->FUN_0043c490();
            reinterpret_cast<NiObj*>(DAT_011da8a0.FUN_00559450())->FUN_0043b4a0(m_iChipNode)->FUN_004bc1f0(kPos.x, kPos.y, 0.0f);
            FUN_007bf840();
            m_bSpinning = false;
        }
        if (reinterpret_cast<AnimSeq*>(m_apSpinSeq[m_iRouletteResult])->FUN_00508100() < s_fSpinTime)
        {
            m_iFadeIndex = 3;
            reinterpret_cast<AnimCtrl*>(m_pAnimCtrl)->FUN_0047b220(reinterpret_cast<AnimSeq*>(m_apSpinSeq[m_iRouletteResult]), 0.0f);
        }
        break;
    case 3: {
        m_iFadeIndex = 4;
        int iWinnings = 0;
        ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(5, 255.0f);
        ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(3, 255.0f);
        ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(4, 128.0f);
        if (m_iBet < m_iMinBet)
        {
            ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(7, 128.0f);
        }
        else
        {
            ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(7, 255.0f);
        }
        if (m_iBet > m_iMaxBet || m_iBet == m_iChips)
        {
            ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(7, 128.0f);
        }
        else
        {
            ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(7, 255.0f);
        }
        ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(8, 255.0f);
        while (m_pBets && *m_pBets->FUN_006815c0())
        {
            bool bWon = false;
            int iSlotC = ((RouletteBetEntry*)*m_pBets->FUN_006815c0())->iSlotC;
            BetSlot* pSlot1 = &m_aSlots[iSlotC];
            if (iSlotC < 0x93)
            {
                ListNode* pNode = &pSlot1->kNumbers;
                while (pNode != 0)
                {
                    if (m_iResult == *pNode->FUN_006815c0())
                    {
                        bWon = true;
                        break;
                    }
                    pNode = (ListNode*)((RouletteMenu*)pNode)->FUN_00726070();
                }
            }
            else
            {
                switch (iSlotC)
                {
                case 0x93:
                    if (m_iResult < 13 && m_iResult > 0)
                    {
                        bWon = true;
                    }
                    break;
                case 0x96:
                    if (m_iResult < 25 && m_iResult > 12)
                    {
                        bWon = true;
                    }
                    break;
                case 0x99:
                    if (m_iResult < 37 && m_iResult > 24)
                    {
                        bWon = true;
                    }
                    break;
                case 0x94:
                    if (m_iResult > 0 && m_iResult < 19)
                    {
                        bWon = true;
                    }
                    break;
                case 0x9b:
                    if (m_iResult > 18 && m_iResult < 37)
                    {
                        bWon = true;
                    }
                    break;
                case 0x95:
                    if (m_iResult % 2 == 0)
                    {
                        bWon = true;
                    }
                    break;
                case 0x9a:
                    if (m_iResult % 2 == 1)
                    {
                        bWon = true;
                    }
                    break;
                case 0x97: {
                    int iRed;
                    for (iRed = 0; iRed < 38; iRed++)
                    {
                        if (m_aiPocketNumbers[iRed] == m_iResult)
                        {
                            break;
                        }
                    }
                    if (iRed % 2 == 0)
                    {
                        bWon = true;
                    }
                    break;
                }
                case 0x98: {
                    int iBlack;
                    for (iBlack = 0; iBlack < 38; iBlack++)
                    {
                        if (m_aiPocketNumbers[iBlack] == m_iResult)
                        {
                            break;
                        }
                    }
                    if (iBlack % 2 == 1)
                    {
                        bWon = true;
                    }
                    break;
                }
                case 0x9c:
                    if ((m_iResult - 1) % 3 == 0)
                    {
                        bWon = true;
                    }
                    break;
                case 0x9d:
                    if ((m_iResult - 2) % 3 == 0)
                    {
                        bWon = true;
                    }
                    break;
                case 0x9e:
                    if (m_iResult % 3 == 0)
                    {
                        bWon = true;
                    }
                }
            }
            if ((bWon || iStickZ4 != 0 || m_iForceWin > 0) && m_iForceWin >= 0)
            {
                iWinnings += (pSlot1->iOdds + 1) * ((RouletteBetEntry*)*m_pBets->FUN_006815c0())->iAmount;
            }
            m_pBets->FUN_0063f7b0();
        }
        iWinnings -= m_iTotalBet;
        m_iChips += iWinnings;
        reinterpret_cast<Tile*>(m_pChipsTile)->SetTraitFloat(DAT_011da86c, 1.0f);
        m_pChipsTile->FUN_00700320(DAT_011da86c, m_iChips);
        DAT_011da87c->iEarnings += iWinnings;
        UpdateBetTileText();
        char szResult[0x104];
        if (iWinnings > 0)
        {
            if (m_bSingular)
            {
                FUN_00406d00(szResult, 0x104, "%s %d %s%s", DAT_011d3a98.FUN_00403df0(), iWinnings,
                             DAT_011d5050.FUN_00403df0(), DAT_011d3114.FUN_00403df0());
            }
            else
            {
                FUN_00406d00(szResult, 0x104, "%s %d %s%s", DAT_011d2ff4.FUN_00403df0(), iWinnings,
                             DAT_011d5050.FUN_00403df0(), DAT_011d3114.FUN_00403df0());
            }
            reinterpret_cast<RouletteAudio*>(FUN_00453a70())->GetSoundHandleByEditorID("GAMERouletteWin", 0x121).Play(false);
            reinterpret_cast<Tile*>(((RouletteMenu*)DAT_011da878)->m_pInfoTile)->SetTraitFloat(0xfc4, 1.0f);
            ((RouletteMenu*)DAT_011da878)->m_pInfoTile->FUN_00a01350(0xfc4, szResult, true);
            ((RouletteMenu*)DAT_011da878)->m_pInfoTile->FUN_00700320(0xfa3, 1);
        }
        else if (iWinnings < 0)
        {
            FUN_00406d00(szResult, 0x104, "%s %d %s%s", DAT_011d3474.FUN_00403df0(), -iWinnings,
                         DAT_011d5050.FUN_00403df0(), DAT_011d3114.FUN_00403df0());
            reinterpret_cast<Tile*>(((RouletteMenu*)DAT_011da878)->m_pInfoTile)->SetTraitFloat(0xfc4, 1.0f);
            ((RouletteMenu*)DAT_011da878)->m_pInfoTile->FUN_00a01350(0xfc4, szResult, true);
            ((RouletteMenu*)DAT_011da878)->m_pInfoTile->FUN_00700320(0xfa3, 1);
        }
        else
        {
            FUN_00406d00(szResult, 0x104, "%s", DAT_011d3f88.FUN_00403df0());
            reinterpret_cast<Tile*>(((RouletteMenu*)DAT_011da878)->m_pInfoTile)->SetTraitFloat(0xfc4, 1.0f);
            ((RouletteMenu*)DAT_011da878)->m_pInfoTile->FUN_00a01350(0xfc4, szResult, true);
            ((RouletteMenu*)DAT_011da878)->m_pInfoTile->FUN_00700320(0xfa3, 1);
        }
        m_iChipCount = 0;
        m_iChipNode = 3;
        m_iTotalBet = 0;
        m_iBet = 0;
        reinterpret_cast<Tile*>(((RouletteMenu*)DAT_011da878)->m_pBetTile)->SetTraitFloat(DAT_011da86c, 1.0f);
        ((RouletteMenu*)DAT_011da878)->m_pBetTile->FUN_00700320(DAT_011da86c, m_iTotalBet);
        if (m_iBet == 0)
        {
            m_iBet = m_iMinBet;
            reinterpret_cast<Tile*>(((RouletteMenu*)DAT_011da878)->m_pMaxBetTile)->SetTraitFloat(DAT_011da86c, (float)m_iBet);
            ((RouletteMenu*)DAT_011da878)->m_pMaxBetTile->FUN_00700320(DAT_011da86c, m_iBet);
        }
        m_iFadeIndex = 4;
        int iMaxWin = DAT_011da880->FUN_00504e60()->iMaxWin;
        int iEarnings = DAT_011da87c->iEarnings;
        int iLevel4 = DAT_011da87c->sLevel;
        for (int iTier = 1; iTier < 5; iTier++)
        {
            if (iTier <= iLevel4)
            {
                m_bLimitUp = false;
            }
            else if (iMaxWin * (iTier * 0.25) <= iEarnings)
            {
                DAT_011da87c->sLevel = (short)iTier;
                m_bLimitUp = true;
            }
        }
        if (m_bLimitUp)
        {
            SetRouletteMenuTile();
        }
        ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(6, 255.0f);
        break;
    }
    case 4:
        if (fMoveX4 != 0.0 || fMoveY4 != 0.0)
        {
            float fSpeed3 = 0.35f;
            m_fCursorX -= fMoveX4 * fSpeed3;
            m_fCursorY -= fMoveY4 * fSpeed3;
            m_fCursorX < -27.5 ? m_fCursorX = -27.5f : 0.0f;
            m_fCursorY < (double)-13.3f ? m_fCursorY = -13.3f : 0.0f;
            m_fCursorX > 28.0 ? m_fCursorX = 28.0f : 0.0f;
            m_fCursorY > (double)13.1f ? m_fCursorY = 13.1f : 0.0f;
            reinterpret_cast<NiObj*>(DAT_011da8a0.FUN_00559450())->FUN_0043b4a0(2)->FUN_004bc1f0(m_fCursorX, m_fCursorY, m_fCursorZ);
            reinterpret_cast<NiObj*>(DAT_011da8a0.FUN_00559450())->FUN_0043b4a0(2)->FUN_00a59c60(ColorFlags(0.0f, false, false));
            if (m_iChipCount < 10)
            {
                reinterpret_cast<NiObj*>(DAT_011da8a0.FUN_00559450())
                    ->FUN_0043b4a0(m_iChipNode)
                    ->FUN_004bc1f0(m_fCursorX, m_fCursorY,
                                   reinterpret_cast<NiObj*>(DAT_011da8a0.FUN_00559450())->FUN_0043b4a0(m_iChipNode)->FUN_0043c490()->z);
                reinterpret_cast<NiObj*>(DAT_011da8a0.FUN_00559450())->FUN_0043b4a0(m_iChipNode + 10)->FUN_004bc1f0(m_fCursorX, m_fCursorY, 0.0f);
                reinterpret_cast<NiObj*>(DAT_011da8a0.FUN_00559450())->FUN_0043b4a0(m_iChipNode)->FUN_00a59c60(ColorFlags(0.0f, false, false));
                reinterpret_cast<NiObj*>(DAT_011da8a0.FUN_00559450())
                    ->FUN_0043b4a0(m_iChipNode + 10)
                    ->FUN_00a59c60(ColorFlags(0.0f, false, false));
            }
            int iHover = FUN_007bf390();
            if (iHover < 0x9f)
            {
                if (m_pHighlight)
                {
                    m_pHighlight->FUN_00450f90(true);
                }
                m_pHighlight = reinterpret_cast<NiAVObject*>(FUN_004aae30(reinterpret_cast<NiObj*>(m_pTableNode), m_aSlots[iHover].szNodeName));
                if (m_pHighlight == 0)
                {
                    m_pHighlight = m_pTableNode->GetObjectByName(NiFixedString(static_cast<const char*>(m_aSlots[iHover].szNodeName)));
                }
                m_pInfoTile->FUN_00a01350(0xfc4, m_aSlots[iHover].szLabel, true);
                if (m_pValidMarker->FUN_00456610())
                {
                    if (s_bValidBet)
                    {
                        s_bValidBet = !s_bValidBet;
                        reinterpret_cast<RouletteAudio*>(FUN_00453a70())->GetSoundHandleByEditorID("GAMERouletteValidBet", 0x121).Play(false);
                    }
                    m_pValidMarker->FUN_00450f90(false);
                    m_pInvalidMarker->FUN_00450f90(true);
                }
                m_pHighlight->FUN_00450f90(false);
            }
            else
            {
                char szInvalid[0x104];
                FUN_00406d00(szInvalid, 0x104, "%s: \n%s: ", DAT_011d4dbc.FUN_00403df0(), DAT_011d3f4c.FUN_00403df0());
                m_pInfoTile->FUN_00a01350(0xfc4, szInvalid, true);
                if (m_pInvalidMarker->FUN_00456610())
                {
                    if (!s_bValidBet)
                    {
                        s_bValidBet = !s_bValidBet;
                        reinterpret_cast<RouletteAudio*>(FUN_00453a70())->GetSoundHandleByEditorID("GAMERouletteInvalidBet", 0x121).Play(false);
                    }
                    m_pValidMarker->FUN_00450f90(true);
                    m_pInvalidMarker->FUN_00450f90(false);
                }
                if (m_pHighlight)
                {
                    m_pHighlight->FUN_00450f90(true);
                }
            }
        }
        if (m_iChips < m_iBet + m_iTotalBet)
        {
            m_iBet = m_iChips - m_iTotalBet;
            reinterpret_cast<Tile*>(((RouletteMenu*)DAT_011da878)->m_pMaxBetTile)->SetTraitFloat(DAT_011da870, 1.0f);
            ((RouletteMenu*)DAT_011da878)->m_pMaxBetTile->FUN_00700320(DAT_011da870, m_iBet);
            ((RouletteMenu*)DAT_011da878)->ApplyValueToChain(6, 128.0f);
        }
        if (m_iChips < m_iMinBet)
        {
            char szBroke[0x104];
            FUN_00406d00(szBroke, 0x104, DAT_011d2424.FUN_00403df0());
            DispatchMessageToSink(szBroke, 0, "Interface\\Icons\\Message Icons\\glow_message_vaultboy_surprised.dds", 0,
                                  2.0f, 0);
            reinterpret_cast<RouletteAudio*>(FUN_00453a70())->GetSoundHandleByEditorID("UIPopUpMessageGeneral", 0x121).Play(false);
            SetRouletteMenuTile();
        }
    }
}

