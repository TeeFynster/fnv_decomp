#include "../../../../include/BSStringT.h"
#include "../../../../include/BGSAcousticSpace.h"
#include "../../../../include/BGSDehydrationStage.h"
#include "../../../../include/BGSLoadGameBuffer.h"
#include "../../../../include/BGSQuestObjective.h"
#include "../../../../include/TESRecipe.h"
#include "../../../../include/TESRegionGrassObject.h"
#include "../../../../include/TESSound.h"
#include "../../../../include/BSAudio.h"
#include "../../../../include/TESAmmo.h"
#include "../../../../include/TESBoundObject.h"
#include "../../../../include/TESCreature.h"
#include "../../../../include/TESNPC.h"
#include "../../../../include/TESObjectWEAP.h"
#include "../../../../include/HighProcess.h"
#include "../../../../include/PlayerCharacter.h"
// PlayerObj_containermenu: local type (was include/PlayerObj.h, which had no evidence of one real class); its methods are 0x00567400 TESObjectREFR::GetScale, 0x008aded0 Actor::PlayPickUpSound, 0x0095edf0 PlayerCharacter::Setup3rdPersonCameraCaster

class PlayerObj_containermenu
{
public:
    void ShowStartMenuMessageOnce();
    void PlayerCharacter_SetIsAMurderer();
    void PlayerCharacter_RewardKarma(int);
    float TESObjectREFR_GetScale_00567400();
    void PlayActorSound(TESBoundObject* o, int a1, int a2);
    void SyncHolderValue();
};
#include "../../../../include/TESBipedModelForm.h"
#include "../../../../include/TESForm.h"
#include "../../../../include/TESModelTextureSwap.h"
#include "../../../../include/TESTopic.h"
#include "../../../../include/Menu.h"
#include "../../../../include/ContainerMenu.h"
#include "../../../../include/InventoryMenu.h"
#include "../../../../include/Tile.h"

#include "../../../../include/Actor.h"
#include "../../../../include/BaseProcess.h"
#include "../../../../include/BGSListForm.h"
#include "../../../../include/Setting.h"
#include "../../../../include/TESObjectCONT.h"

// Windows headers also declare a LoadString API macro.
#undef LoadString

class HUDMainMenu;

// fallout/interface/menus/containermenu.cpp: container menu and supporting routines (40 functions)

// Helper declarations from containermenu_decls.h are kept here so its partial
// Menu, BSSoundHandle and BSSimpleList definitions do not duplicate the shared types.
#ifndef CONTAINERMENU_DECLS_H
#define CONTAINERMENU_DECLS_H

class ActorCause;

// The shared HUD header declares a static void refresh. This boolean member
// entry point takes only ECX, so a one-argument fastcall declaration has its ABI.
bool __fastcall RefreshHudTargetDisplay(HUDMainMenu* hud);


extern ContainerMenu* DAT_011d93f8;
extern PlayerCharacter* g_thePlayer;
extern int DAT_011f2250;
extern const char DAT_01072278[];
extern void __cdecl StartDialogueForTopic(int);
extern void __cdecl FUN_00778b10();
class CloseVirtualSlots
{
  public:
    virtual void vfn_0000() = 0;
    virtual void vfn_0004() = 0;
    virtual void vfn_0008() = 0;
    virtual void vfn_000c() = 0;
    virtual void vfn_0010() = 0;
    virtual void vfn_0014() = 0;
    virtual void vfn_0018() = 0;
    virtual void vfn_001c() = 0;
    virtual void vfn_0020() = 0;
    virtual void vfn_0024() = 0;
    virtual void vfn_0028() = 0;
    virtual void vfn_002c() = 0;
    virtual void vfn_0030() = 0;
    virtual void vfn_0034() = 0;
    virtual void vfn_0038() = 0;
    virtual void vfn_003c() = 0;
    virtual void vfn_0040() = 0;
    virtual void vfn_0044() = 0;
    virtual void vfn_0048() = 0;
    virtual void vfn_004c() = 0;
    virtual void vfn_0050() = 0;
    virtual void vfn_0054() = 0;
    virtual void vfn_0058() = 0;
    virtual void vfn_005c() = 0;
    virtual void vfn_0060() = 0;
    virtual void vfn_0064() = 0;
    virtual void vfn_0068() = 0;
    virtual void vfn_006c() = 0;
    virtual void vfn_0070() = 0;
    virtual void vfn_0074() = 0;
    virtual void vfn_0078() = 0;
    virtual void vfn_007c() = 0;
    virtual void vfn_0080() = 0;
    virtual void vfn_0084() = 0;
    virtual void vfn_0088() = 0;
    virtual void vfn_008c() = 0;
    virtual void vfn_0090() = 0;
    virtual void vfn_0094() = 0;
    virtual void vfn_0098() = 0;
    virtual void vfn_009c() = 0;
    virtual void vfn_00a0() = 0;
    virtual void vfn_00a4() = 0;
    virtual void vfn_00a8() = 0;
    virtual void vfn_00ac() = 0;
    virtual void vfn_00b0() = 0;
    virtual void vfn_00b4() = 0;
    virtual void vfn_00b8() = 0;
    virtual void vfn_00bc() = 0;
    virtual void vfn_00c0() = 0;
    virtual void vfn_00c4() = 0;
    virtual void vfn_00c8() = 0;
    virtual void vfn_00cc() = 0;
    virtual void vfn_00d0() = 0;
    virtual void vfn_00d4() = 0;
    virtual void vfn_00d8() = 0;
    virtual void vfn_00dc() = 0;
    virtual void vfn_00e0() = 0;
    virtual void vfn_00e4() = 0;
    virtual void vfn_00e8() = 0;
    virtual void vfn_00ec() = 0;
    virtual void vfn_00f0() = 0;
    virtual void vfn_00f4() = 0;
    virtual void vfn_00f8() = 0;
    virtual void vfn_00fc() = 0;
    virtual bool IsActor() = 0;
    virtual void vfn_0104() = 0;
    virtual void vfn_0108() = 0;
    virtual void vfn_010c() = 0;
    virtual void vfn_0110() = 0;
    virtual void vfn_0114() = 0;
    virtual void vfn_0118() = 0;
    virtual void vfn_011c() = 0;
    virtual void vfn_0120() = 0;
    virtual void vfn_0124() = 0;
    virtual void vfn_0128() = 0;
    virtual void vfn_012c() = 0;
    virtual void vfn_0130() = 0;
    virtual void vfn_0134() = 0;
    virtual void vfn_0138() = 0;
    virtual void vfn_013c() = 0;
    virtual void vfn_0140() = 0;
    virtual void vfn_0144() = 0;
    virtual int GetCastsShadows() = 0;
    virtual void vfn_014c() = 0;
    virtual void vfn_0150() = 0;
    virtual void vfn_0154() = 0;
    virtual void vfn_0158() = 0;
    virtual void vfn_015c() = 0;
    virtual void vfn_0160() = 0;
    virtual void vfn_0164() = 0;
    virtual void vfn_0168() = 0;
    virtual void vfn_016c() = 0;
    virtual void vfn_0170() = 0;
    virtual void vfn_0174() = 0;
    virtual void vfn_0178() = 0;
    virtual void vfn_017c() = 0;
    virtual void vfn_0180() = 0;
    virtual void vfn_0184() = 0;
    virtual void vfn_0188() = 0;
    virtual void vfn_018c() = 0;
    virtual void vfn_0190() = 0;
    virtual void vfn_0194() = 0;
    virtual void vfn_0198() = 0;
    virtual void vfn_019c() = 0;
    virtual void vfn_01a0() = 0;
    virtual void vfn_01a4() = 0;
    virtual void vfn_01a8() = 0;
    virtual void vfn_01ac() = 0;
    virtual void vfn_01b0() = 0;
    virtual void vfn_01b4() = 0;
    virtual void vfn_01b8() = 0;
    virtual void vfn_01bc() = 0;
    virtual void vfn_01c0() = 0;
    virtual void vfn_01c4() = 0;
    virtual void vfn_01c8() = 0;
    virtual void vfn_01cc() = 0;
    virtual void vfn_01d0() = 0;
    virtual void vfn_01d4() = 0;
    virtual void vfn_01d8() = 0;
    virtual void vfn_01dc() = 0;
    virtual void vfn_01e0() = 0;
    virtual void* vfn_1e4() = 0;
    virtual void* vfn_1e8(bool) = 0;
    virtual void vfn_01ec() = 0;
    virtual void vfn_01f0() = 0;
    virtual void vfn_01f4() = 0;
    virtual void vfn_01f8() = 0;
    virtual void vfn_01fc() = 0;
    virtual void vfn_0200() = 0;
    virtual void vfn_0204() = 0;
    virtual void vfn_0208() = 0;
    virtual void vfn_020c() = 0;
    virtual void vfn_0210() = 0;
    virtual void vfn_0214() = 0;
    virtual void vfn_0218() = 0;
    virtual bool IsCreature() = 0;
    virtual void vfn_0220() = 0;
    virtual void vfn_0224() = 0;
    virtual void vfn_0228() = 0;
    virtual void vfn_022c() = 0;
    virtual void vfn_0230() = 0;
    virtual void vfn_0234() = 0;
    virtual void vfn_0238() = 0;
    virtual void vfn_023c() = 0;
    virtual void vfn_0240() = 0;
    virtual void vfn_0244() = 0;
    virtual void vfn_0248() = 0;
    virtual void vfn_024c() = 0;
    virtual void vfn_0250() = 0;
    virtual void vfn_0254() = 0;
    virtual void vfn_0258() = 0;
    virtual void vfn_025c() = 0;
    virtual void vfn_0260() = 0;
    virtual void vfn_0264() = 0;
    virtual void vfn_0268() = 0;
    virtual void vfn_026c() = 0;
    virtual void vfn_0270() = 0;
    virtual void vfn_0274() = 0;
    virtual void vfn_0278() = 0;
    virtual void vfn_027c() = 0;
    virtual void vfn_0280() = 0;
    virtual void vfn_0284() = 0;
    virtual void vfn_0288() = 0;
    virtual void vfn_028c() = 0;
    virtual void vfn_0290() = 0;
    virtual void vfn_0294() = 0;
    virtual void vfn_0298() = 0;
    virtual void vfn_029c() = 0;
    virtual void vfn_02a0() = 0;
    virtual void vfn_02a4() = 0;
    virtual void vfn_02a8() = 0;
    virtual void vfn_02ac() = 0;
    virtual void vfn_02b0() = 0;
    virtual void vfn_02b4() = 0;
    virtual void vfn_02b8() = 0;
    virtual void vfn_02bc() = 0;
    virtual void vfn_02c0() = 0;
    virtual void vfn_02c4() = 0;
    virtual void vfn_02c8() = 0;
    virtual void vfn_02cc() = 0;
    virtual void vfn_02d0() = 0;
    virtual void vfn_02d4() = 0;
    virtual void vfn_02d8() = 0;
    virtual void vfn_02dc() = 0;
    virtual void vfn_02e0() = 0;
    virtual void vfn_02e4() = 0;
    virtual void vfn_02e8() = 0;
    virtual void vfn_02ec() = 0;
    virtual void vfn_02f0() = 0;
    virtual void vfn_02f4() = 0;
    virtual void vfn_02f8() = 0;
    virtual void vfn_02fc() = 0;
    virtual void vfn_0300() = 0;
    virtual void vfn_0304() = 0;
    virtual void vfn_0308() = 0;
    virtual void vfn_030c() = 0;
    virtual void vfn_0310() = 0;
    virtual void vfn_0314() = 0;
    virtual void vfn_0318() = 0;
    virtual void vfn_031c() = 0;
    virtual void vfn_0320() = 0;
    virtual void vfn_0324() = 0;
    virtual void vfn_0328() = 0;
    virtual void vfn_032c() = 0;
    virtual void vfn_0330() = 0;
    virtual void vfn_0334() = 0;
    virtual void vfn_0338() = 0;
    virtual void vfn_033c() = 0;
    virtual bool vfn_340(int) = 0;
    virtual void vfn_0344() = 0;
    virtual void vfn_0348() = 0;
    virtual void vfn_034c() = 0;
    virtual void vfn_0350() = 0;
    virtual void vfn_0354() = 0;
    virtual void vfn_0358() = 0;
    virtual void vfn_035c() = 0;
    virtual void vfn_0360() = 0;
    virtual void vfn_0364() = 0;
    virtual void vfn_0368() = 0;
    virtual void vfn_036c() = 0;
    virtual void vfn_0370() = 0;
    virtual void vfn_0374() = 0;
    virtual void vfn_0378() = 0;
    virtual void vfn_037c() = 0;
    virtual void vfn_0380() = 0;
    virtual void vfn_0384() = 0;
    virtual void vfn_0388() = 0;
    virtual void vfn_038c() = 0;
    virtual void vfn_0390() = 0;
    virtual void vfn_0394() = 0;
    virtual void vfn_0398() = 0;
    virtual void vfn_039c() = 0;
    virtual void vfn_03a0() = 0;
    virtual void vfn_03a4() = 0;
    virtual void vfn_03a8() = 0;
    virtual void vfn_03ac() = 0;
    virtual void vfn_03b0() = 0;
    virtual void vfn_03b4() = 0;
    virtual void vfn_03b8() = 0;
    virtual void vfn_03bc() = 0;
    virtual void vfn_03c0() = 0;
    virtual void vfn_03c4() = 0;
    virtual void vfn_03c8() = 0;
    virtual void vfn_03cc() = 0;
    virtual void vfn_03d0() = 0;
    virtual void vfn_03d4() = 0;
    virtual void vfn_03d8() = 0;
    virtual void vfn_03dc() = 0;
    virtual void vfn_03e0() = 0;
    virtual void vfn_03e4() = 0;
    virtual void vfn_03e8() = 0;
    virtual void vfn_03ec() = 0;
    virtual void vfn_03f0() = 0;
    virtual void vfn_03f4() = 0;
    virtual void vfn_03f8() = 0;
    virtual void vfn_03fc() = 0;
    virtual void vfn_0400() = 0;
    virtual void vfn_0404() = 0;
    virtual void vfn_0408() = 0;
    virtual void vfn_040c() = 0;
    virtual void vfn_0410() = 0;
    virtual void vfn_0414() = 0;
    virtual void vfn_0418() = 0;
    virtual void vfn_041c() = 0;
    virtual void vfn_0420() = 0;
    virtual void vfn_0424() = 0;
    virtual void vfn_0428() = 0;
    virtual void vfn_042c() = 0;
    virtual void vfn_0430() = 0;
    virtual void vfn_0434() = 0;
    virtual void vfn_0438() = 0;
    virtual void vfn_043c() = 0;
    virtual void vfn_0440() = 0;
    virtual void vfn_0444() = 0;
    virtual void vfn_0448() = 0;
    virtual void vfn_044c() = 0;
    virtual void vfn_0450() = 0;
    virtual void vfn_0454() = 0;
    virtual void vfn_0458() = 0;
    virtual void vfn_045c() = 0;
    virtual void vfn_0460() = 0;
    virtual void vfn_0464() = 0;
    virtual void vfn_0468() = 0;
    virtual void vfn_046c() = 0;
    virtual void vfn_0470() = 0;
    virtual bool vfn_474(bool) = 0;
};
#endif

// Packet declarations kept here so the shared TESFile, casting enum, and
// TESEnchantableForm definitions are not redeclared by containermenu_packet.h.
#ifndef CONTAINERMENU_PACKET_H
#define CONTAINERMENU_PACKET_H

class SaveLoadFile
{
  public:
    void SetFilePosition(int);
    unsigned Read(void*, unsigned);
    unsigned GetFilePosition();
};
class TESLandTexture;
class TESQuest;
class SpellItem;



// 0x00984f60 stores +0x18 on the save header loaded here, not on the UI singleton.
class SaveHeaderStringView_00984f60
{
  public:
    void FUN_00984f60(unsigned);
};
class SaveHeaderOps
{
  public:
    void QueueWeapon(const char*);
};
class TESIdleForm;
extern char* DAT_011a2224;
extern const char ENGLISH[];
extern "C" unsigned __cdecl strlen(const char*);
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned);
int BSstrcmp(const char*, const char*);
#endif

#include "../../../../include/BSSoundHandle.h"
#include "../../../../include/ExtraDataList.h"
#include "../../../../include/StrMem.h"
#include "../../../../include/TESFullName.h"
#include "../../../../include/TESConditionItem.h"
#include "../../../../include/TESResponse.h"
// Reads a save-file signature and header fields from the file into headerArg, returning early if the signature matches DAT_011a2224.
// @fnv 0x0084dab0
void ReadSaveFileHeader(void* pFile, void* pHeader)
{
    ((SaveLoadFile*)pFile)->SetFilePosition(0);
    char signature[260];
    signature[0] = 0;
    fnv_zlib_memset(signature + 1, 0, 259);
    ((SaveLoadFile*)pFile)->Read(signature, strlen(DAT_011a2224));
    if (BSstrcmp(signature, DAT_011a2224))
        return;
    unsigned skill;
    BGSLoadGameBuffer storage;
    storage.ReadAndVerifySize((SaveLoadFile*)pFile);
    {
        TESLandTexture* parentTexture;
        BGSLoadGameBuffer* pLoadBuffer = &storage;
        char* saveTime;
        int saveVersion = 0;
        pLoadBuffer->ReadDataBlock(&saveVersion, 4);
        ((BGSAcousticSpace*)pHeader)->SetNoonSound((TESSound*)saveVersion);
        if (saveVersion == 48)
        {
            char* data = pLoadBuffer->GetCombinedValue();
            if (data[4] == '|')
                ((SaveHeaderOps*)pHeader)->QueueWeapon(ENGLISH);
            else
            {
                char language[64];
                pLoadBuffer->ReadDataBlock(language, 64);
                ((SaveHeaderOps*)pHeader)->QueueWeapon(language);
            }
        }
        else
        {
            char language[64];
            pLoadBuffer->ReadDataBlock(language, 64);
            ((SaveHeaderOps*)pHeader)->QueueWeapon(language);
        }
        saveTime = 0;
        skill = 0;
        pLoadBuffer->ReadDataBlock(&saveTime, 4);
        pLoadBuffer->ReadDataBlock(&skill, 4);
        parentTexture = 0;
        pLoadBuffer->ReadDataBlock(&parentTexture, 4);
        ((TESRegionGrassObject*)pHeader)->AssignLandTexture((TESLandTexture*)parentTexture);
        ((TESEnchantableForm*)pHeader)->SetCastingType((MagicSystem__CastingType)(unsigned)pLoadBuffer->LoadString(0));
        ((BGSQuestObjective*)pHeader)->SetOwnerQuest((TESQuest*)pLoadBuffer->LoadString(0));
        if (saveVersion > 47)
        {
            unsigned spell = 0;
            pLoadBuffer->ReadDataBlock(&spell, 4);
            ((BGSDehydrationStage*)pHeader)->SetSpell((SpellItem*)spell);
        }
        ((TESConditionItem*)pHeader)->SetObjectType((int)pLoadBuffer->LoadString(0));
        ((SaveHeaderStringView_00984f60*)pHeader)->FUN_00984f60((unsigned)pLoadBuffer->LoadString(0));
        ((TESResponse*)pHeader)->SetSpeakerIdle((TESIdleForm*)saveTime);
        ((TESRecipe*)pHeader)->SetSkill(skill);
        ((TESRecipe*)pHeader)->SetSkillLevel(((SaveLoadFile*)pFile)->GetFilePosition());
    }
}

// @fnv 0x0075b750
void ContainerMenu::Close()
{
    if (DAT_011d93f8)
    {
        DAT_011d93f8->m_kFadeSequence.FadeOutAndRelease(100);

        switch (DAT_011d93f8->m_eContainerMenuMode)
        {
        case 1:
            ((ContainerMenu*)DAT_011d93f8)->UpdateContainer(DAT_011d93f8->m_pContainer, false);
            break;
        case 2: {
            TESObjectREFR* actor =
                ((CloseVirtualSlots*)DAT_011d93f8->m_pContainer)->IsActor() ? DAT_011d93f8->m_pContainer : 0;
            if (!actor && DAT_011d93f8->m_iStolenItemCount > 0)
            {
                ((Actor*)g_thePlayer)
                    ->StealAlarm(DAT_011d93f8->m_pContainer, 0, 0, DAT_011d93f8->m_iStolenItemCount,
                                 DAT_011d93f8->m_pContainer->GetOwner());
            }
            ((ContainerMenu*)DAT_011d93f8)->UpdateContainer(DAT_011d93f8->m_pContainer, false);
            break;
        }
        case 4:
            if (!RefreshHudTargetDisplay(reinterpret_cast<HUDMainMenu*>(&DAT_011f2250)))
                ((CloseVirtualSlots*)g_thePlayer)->vfn_340(9);
            break;
        case 3: {
            bool processContainer = false;
            if (((CloseVirtualSlots*)DAT_011d93f8->m_pContainer)->IsActor() &&
                ((CloseVirtualSlots*)DAT_011d93f8->m_pContainer)->vfn_1e4())
            {
                if (((Actor*)DAT_011d93f8->m_pContainer)->GetProcess() &&
                    ((CloseVirtualSlots*)((Actor*)DAT_011d93f8->m_pContainer)->GetProcess())->GetCastsShadows())
                    processContainer = true;
            }
            if (((CloseVirtualSlots*)DAT_011d93f8->m_pContainer)->IsCreature())
            {
                void* form = DAT_011d93f8->m_pContainer->GetObjectReference();
                ((TESCreature*)form)->UpdateModel3D(DAT_011d93f8->m_pContainer, true, true, true);
            }
            else
            {
                void* form = DAT_011d93f8->m_pContainer->GetObjectReference();
                ((TESNPC*)form)
                    ->RebuildHeadModel(DAT_011d93f8->m_pContainer,
                                       ((CloseVirtualSlots*)DAT_011d93f8->m_pContainer)->vfn_1e8(true));
            }
            if (processContainer && ((Actor*)DAT_011d93f8->m_pContainer)->IsFirstActorFlagSet())
            {
                if (!((CloseVirtualSlots*)((Actor*)DAT_011d93f8->m_pContainer)->GetProcess())->GetCastsShadows())
                    ((Actor*)DAT_011d93f8->m_pContainer)->SetIsSwimming(false);
            }
            {
                BSAudio::GetSingleton()->GetSoundHandleByEditorID(DAT_01072278, 0x121).Play(false);
            }
            StartDialogueForTopic(0);
            break;
        }
        }

        ((BSSimpleList<ActorCause*>*)&DAT_011d93f8->m_kContainerItems)->RemoveAll();
        (*(Tile**)((char*)DAT_011d93f8 + 4))->Set(0x1772, 1);
        DAT_011d93f8->LoadMenuData();
        if (((CloseVirtualSlots*)((Actor*)g_thePlayer)->GetProcess())->vfn_474(true))
            g_thePlayer->UpdatePlayerControls();
        FUN_00778b10();
    }
}


// @fnv 0x0075b200
int __thiscall ContainerMenu::GetClass()
{
    return 0x3f0;
}


// @fnv 0x0075b210
void ContainerMenu::AssignTileByID(int id, Tile* tile)
{
    if (id >= 0 && id < 19)
    {
        m_pTiles[id] = tile;
    }
}

extern void* DAT_011d8a80;

// @fnv 0x0075b6e0
// src: XBOX_PDB 0x0075b6e0
void InterfaceManager_SetContainerMenuQueued(int param1)
{
    if (DAT_011d8a80)
        *(char*)((char*)DAT_011d8a80 + 0x4cd) = (char)param1;
}

// @fnv 0x0075b700
// src: COMMUNITY 0x0075b700
int __cdecl ContainerMenu_GetMenuID()
{
    return 1008;
}

// The shared player header does not expose its container inventory accessor.
// @fnv 0x0075cc70
void* __fastcall GetPlayerContainerInventory(PlayerCharacter* player)
{
    return reinterpret_cast<char*>(player) + 0xDF4;
}

int __cdecl _mbscmp(unsigned char const*, unsigned char const*);

// Compares the strings returned by FUN_00a011f0(0xfc4) on both items using _mbscmp and returns the result.
// @fnv 0x0075d130
// src: XBOX_PDB 0x0075d130
int ContainerMenu_SortFunc(Tile** apItem1, Tile** apItem2)
{
    return _mbscmp((unsigned char const*)(*apItem1)->Tile_GetString(0xfc4),
                   (unsigned char const*)(*apItem2)->Tile_GetString(0xfc4));
}

void __cdecl _Deallocate(void*);
// Handles key 0x20 by closing ContainerMenu and reports whether the key was handled.
// @fnv 0x0075c250
bool ContainerMenu::HandleKeyboardInput(unsigned int aiKey)
{
    bool bhandled = false;
    switch (aiKey)
    {
    case 0x20:
        ContainerMenu::Close();
        bhandled = true;
        break;
    }
    return bhandled;
}

// Sets the value 0xFA3 to 0 on the Tile objects at offsets 0x5C, 0x58 and 0x4C of this object.
// @fnv 0x0075cf70
void ContainerMenu::HandleMouseoverTileAlt(unsigned int aiID, Tile* apTarget)
{
    m_pTiles[13]->Set(0xFA3, 0);
    m_pTiles[12]->Set(0xFA3, 0);
    m_pTiles[9]->Set(0xFA3, 0);
}

// Returns false if any of the 19 ints in field28 is zero, otherwise returns true.
// @fnv 0x0075b710
// src: COMMUNITY 0x0075b710
bool __thiscall ContainerMenu::HasTiles()
{
    for (int i = 0; i < 0x13; ++i)
    {
        if (m_pTiles[i] == 0)
            return false;
    }
    return true;
}

// @fnv 0x0075b270
ContainerMenu::~ContainerMenu()
{
    DAT_011d93f8 = 0;
}

struct FUN_0075cc90_Local
{
    unsigned int m_unk00;
    FUN_0075cc90_Local();
    ~FUN_0075cc90_Local();
    void Clear();
};

struct FUN_0075cc90_Node
{
    FUN_0075cc90_Node* Next();
    void** Value();
};

struct FUN_0075cc90_Obj
{
    void Attach(void* a, FUN_0075cc90_Local* l);
    int Query(int a, int b);
};

struct FUN_0075cc90_Sink
{
    void Deliver(void* a);
    void Apply(void* v, int r);
};


// If a1, a2 and a3 are non-null, attaches a1 to a2, delivers a1 to a3, then applies each node value from the local list to a3 and clears the list.
// @fnv 0x0075cc90
void ContainerMenu::AttachAndDeliver(void* a1, void* apObj, void* apSink)
{
    FUN_0075cc90_Local pad;
    unsigned int list;
    if (apObj != 0 && a1 != 0 && apSink != 0)
    {
        ((FUN_0075cc90_Obj*)apObj)->Attach(a1, &pad);
        ((FUN_0075cc90_Sink*)apSink)->Deliver(a1);
        FUN_0075cc90_Node* p;
        for (p = (FUN_0075cc90_Node*)&pad; p != 0 && *p->Value() != 0; p = p->Next())
        {
            ((FUN_0075cc90_Sink*)apSink)->Apply(*p->Value(), ((FUN_0075cc90_Obj*)*p->Value())->Query(0, 0));
        }
        pad.Clear();
    }
}









// 0x00474a40 checks the ammo form at +4 for type 0x55 (BGSListForm).
BGSListForm* __fastcall GetAmmunitionList(BGSAmmoForm* ammo);

class RefEx : public TESObjectREFR
{
  public:
    TESBoundObject* GetBaseObject();
};


// @fnv 0x0075cfc0
bool IsRefBaseObjectUnplayable(RefEx* apRef)
{
    bool bResult = false;
    if (DAT_011d93f8)
    {
        TESBoundObject* pObject = apRef ? apRef->GetBaseObject() : 0;
        if (DAT_011d93f8->m_eContainerMenuMode == 4)
        {
            bResult =
                GetAmmunitionList(reinterpret_cast<BGSAmmoForm*>(
                    reinterpret_cast<char*>(g_thePlayer->GetActiveWeapon()) +
                    offsetof(TESObjectWEAP, m_pAmmo) - offsetof(BGSAmmoForm, m_pAmmo)))
                    ->GetConditionIndex(pObject) < 0;
        }
        else
        {
            TESBipedModelForm* pBiped = TESBipedModelForm::GetFormAsBipedModel(pObject);
            TESFullName* pFullName = dynamic_cast<TESFullName*>(pObject);
            TESObjectWEAP* pWeapon =
                apRef->GetBaseObject()->GetFormType() == 0x28 ? (TESObjectWEAP*)apRef->GetBaseObject() : 0;
            TESAmmo* pAmmo = apRef->GetBaseObject()->GetFormType() == 0x29 ? (TESAmmo*)apRef->GetBaseObject() : 0;
            if (!pObject || (pBiped && !pBiped->IsPlayable()) || !pFullName || !pFullName->GetLength() ||
                (pWeapon && !pWeapon->IsPlayable()) || (pAmmo && !pAmmo->GetFlag()))
            {
                bResult = true;
            }
        }
    }
    return bResult;
}

int __cdecl BSsprintf(char* buf, unsigned size, const char* fmt, char* name, int count);

struct ContainerLikeObj
{
    bool ItemChange_GetWorn(int);
    int FUN_00726070();
    char* GetTargetFullName();
    void* NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetHead(int, int);
    void FUN_00700320();
    void Tile_Set_00a01350(int, char*, int);
    void Tile_Set_00a01350(void*);
    void FUN_00707e10(char*);
    void* Tile_GetString(int, int);
    void* FUN_007b5370(int);
    void Tile_Set(int, float, int);
};

// @fnv 0x0075d160
// src: XBOX_PDB 0x0075d160
void __cdecl ContainerMenu_InitFunc(void* param1, void* param2)
{
    char buf[0x80];

    if (((ContainerLikeObj*)param2)->ItemChange_GetWorn(0))
    {
        (*(ContainerLikeObj**)((ContainerLikeObj*)((char*)param1 + 4))->NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetHead(0xfa3, 1))->FUN_00700320();
    }

    if (((ContainerLikeObj*)param2)->FUN_00726070() > 1)
    {
        BSsprintf(buf, 0x80, "%s (%d)", ((ContainerLikeObj*)param2)->GetTargetFullName(),
                     ((ContainerLikeObj*)param2)->FUN_00726070());
        ((ContainerLikeObj*)param1)->Tile_Set_00a01350(0xfc4, buf, 1);
    }

    ((ContainerLikeObj*)param1)->FUN_00707e10(((ContainerLikeObj*)param2)->GetTargetFullName());
    (*(ContainerLikeObj**)((ContainerLikeObj*)((char*)param1 + 4))->FUN_007b5370(0xfc4))
        ->Tile_Set_00a01350(((ContainerLikeObj*)param1)->Tile_GetString(0xfc4, 1));
    ((ContainerLikeObj*)param1)->Tile_Set(0xfb0, 0.0f, 1);
}



extern void __cdecl FUN_0075b750();

// @fnv 0x0075d430
bool ContainerMenu::HandleControllerInput(int param1, Tile* apUnused)
{
    bool result = false;

    if (param1 == 0x0b && m_eContainerMenuMode != 4 && m_eContainerMenuMode != 3 && m_eFadeState == 1)
    {
        HandleSelection(0x0a, 0);
        result = true;
    }
    else if (param1 == 0x0a)
    {
        Close();
        result = true;
    }

    return result;
}

// Menu input handler: on accept (1) or cancel (6), play the matching state depending on the controller state.

class InputDeviceState
{
  public:
    long GetState();
};

InputDeviceState* __cdecl GetInputDeviceState();


// For actions 1 and 6, sets the menu state based on whether the input device state is negative.
// @fnv 0x0075d4a0
void ContainerMenu::HandleMousewheel(unsigned int iAction, Tile* apUnused)
{
    if (iAction == 1 || iAction == 6)
    {
        if (GetInputDeviceState()->GetState() < 0)
            HandleSelection(iAction == 1 ? 0 : 5, 0);
        else
            HandleSelection(iAction == 1 ? 2 : 7, 0);
    }
}


struct CurrentItem
{
    int BGSProjectile_GetMotionType();
};
struct SourceForm
{
    int FUN_00401170();
    bool TESObjectWEAP_IsThrownWeapon();
    CurrentItem* GetOrFallback(Actor* actor);
};
struct InventoryEntry
{
    SourceForm* FUN_0044ddc0();
};
struct ActiveList
{
    bool FUN_008256d0();
};
struct ExpectedReference
{
    bool FUN_004997b0();
};
extern ExpectedReference* DAT_011dea3c;
// @fnv 0x0075d510
// The shared ContainerMenu declaration still uses the opaque ActorView parameter.
// src: XBOX_PDB 0x0075d510
bool ContainerMenu::IsPlacingMine(InventoryEntry* entry, ExpectedReference* reference, ActorView* actor)
{
    if (m_eContainerMenuMode == 2 &&
        m_pCurrentList == &m_kFirstItemChangeList &&
        reference == DAT_011dea3c && DAT_011dea3c->FUN_004997b0() && reinterpret_cast<Actor*>(actor)->IsActor() && !reinterpret_cast<Actor*>(actor)->HasHealth(false) &&
        !reinterpret_cast<Actor*>(actor)->GetIsChildSize(false) && entry->FUN_0044ddc0()->FUN_00401170() == 0x28 &&
        reinterpret_cast<ActiveList*>(&m_kContainerItems)->FUN_008256d0())
    {
        Actor* a = 0;
        if (reinterpret_cast<Actor*>(actor)->IsActor())
        {
            a = reinterpret_cast<Actor*>(actor);
            if (a->GetEssential())
                return false;
            if (a->GetProcess())
            {
                if (a->GetProcess()->GetPlantedExplosive())
                    return false;
            }
        }
        SourceForm* b = entry->FUN_0044ddc0();
        if (b->TESObjectWEAP_IsThrownWeapon())
        {
            if (b->GetOrFallback(a))
            {
                if (b->GetOrFallback(a)->BGSProjectile_GetMotionType() == 0x20000)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

struct ItemNode
{
    ExtraDataList** FUN_006815c0();
    ItemNode* FUN_00726070();
};
struct ItemEntry
{
    float FUN_004bd400();
    ItemNode* Modelloader_GetReferencedThis();
};
extern "C" int __cdecl TruncateFloatToInt(float);
// @fnv 0x0075e240
int ContainerMenu::GetContainerValue(ItemEntry* entry, int amount, bool includeUnowned)
{
    TESForm* owner = 0;
    int value = TruncateFloatToInt(entry->FUN_004bd400());
    int count = amount;
    int total = 0;
    if (((CloseVirtualSlots*)m_pContainer)->IsActor())
        owner = (TESForm*)m_pContainer;
    else
        owner = m_pContainer->GetOwner();
    for (ItemNode* node = entry->Modelloader_GetReferencedThis(); count > 0 && node && *node->FUN_006815c0();
         node = node->FUN_00726070())
    {
        TESForm* itemOwner = (*node->FUN_006815c0())->GetOwner();
        if ((!itemOwner && includeUnowned) || (itemOwner && (*node->FUN_006815c0())->GetOwner() == owner))
            total += (*node->FUN_006815c0())->ExtraDataList_GetCount() * value;
        count -= (*node->FUN_006815c0())->ExtraDataList_GetCount();
    }
    if (includeUnowned)
        total += count * value;
    return total;
}

struct MenuInput
{
    void InterfaceManager_TutorialManager_ShowMessage(int, int, int);
};
struct MenuSystem
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    MenuInput input;
    Tile* CombatController_GetCombatState();
};
MenuSystem* InterfaceManager_GetSingleton();
Menu* Tile_GetMenuByClass(int);
void FNV_Warning(const char*, ...);
Tile* Tile_GetTileByName(Tile*, const char*);
int Tile_TextToTrait(const char*);
struct InventoryMenuSetting
{
    const char* FUN_00403df0();
};
extern InventoryMenuSetting DAT_011d4378, DAT_011d2d0c, DAT_011d33fc, DAT_011d2c7c, DAT_011d412c, DAT_011d330c,
    DAT_011d20c4, DAT_011d396c;
// Loads container_menu.xml, validates the container menu, initializes its lists and title tiles, stores the reference and mode, and returns the menu tile.
// @fnv 0x0075b310
// src: COMMUNITY 0x0075b310
Tile* ContainerMenu_Create(TESObjectREFR* reference, int mode)
{
    MenuSystem* tile = InterfaceManager_GetSingleton();
    InterfaceManager_SetContainerMenuQueued(0);
    if (!reference && mode != 4)
        return 0;
    Menu* old = Tile_GetMenuByClass(ContainerMenu_GetMenuID());
    if (old)
        delete old;
    Tile* manager = tile->CombatController_GetCombatState()->ReadFile("Data\\Menus\\container_menu.xml");
    DAT_011d93f8 = manager ? static_cast<ContainerMenu*>(manager->GetMenu()) : 0;
    if (DAT_011d93f8 && DAT_011d93f8->GetClass() == ContainerMenu_GetMenuID())
    {
        DAT_011d93f8->FUN_00a1dc70(reinterpret_cast<TileMenu*>(manager), false);
        if (!DAT_011d93f8->HasTiles())
        {
            FNV_Warning("MENUS: Container Menu Creation Failed... Are your menu and art resources up to date?");
            return 0;
        }
        if (manager->FUN_00a011b0(4007) == 6006.0 || manager->FUN_00a011b0(4007) == 102.0)
            manager->Set(4013, Tile::GetInterfaceScale(), true);
        tile->input.InterfaceManager_TutorialManager_ShowMessage(22, ContainerMenu_GetMenuID(), 512);
        DAT_011d93f8->m_kFirstItemChangeList.Initialize((Tile*)DAT_011d93f8->m_pTiles[4], "CM_list_template");
        DAT_011d93f8->m_kSecondItemChangeList.Initialize((Tile*)DAT_011d93f8->m_pTiles[8], "CM_list_template");
        DAT_011d93f8->m_pTiles[1]->Set(4036, DAT_011d4378.FUN_00403df0(), true);
        DAT_011d93f8->m_pTiles[10]->Set(4036, DAT_011d2d0c.FUN_00403df0(), true);
        DAT_011d93f8->m_pTiles[11]->Set(4036, DAT_011d33fc.FUN_00403df0(), true);
        Tile* title = Tile_GetTileByName(DAT_011d93f8->FUN_00726070(), "CM_Subtitle");
        if (title)
            title->Set(4036, "", true);
        DAT_011d93f8->m_pContainer = reference;
        DAT_011d93f8->m_eContainerMenuMode = static_cast<Interface__CONTAINER_MENU_MODE>(mode);
        DAT_011d93f8->InitContainerMode();
        int subtitle = Tile_TextToTrait("_Title");
        if (DAT_011d93f8->m_pTiles[14])
            DAT_011d93f8->m_pTiles[14]->Set(subtitle, DAT_011d2c7c.FUN_00403df0(), true);
        if (DAT_011d93f8->m_pTiles[15])
            DAT_011d93f8->m_pTiles[15]->Set(subtitle, DAT_011d412c.FUN_00403df0(), true);
        if (DAT_011d93f8->m_pTiles[16])
            DAT_011d93f8->m_pTiles[16]->Set(subtitle, DAT_011d330c.FUN_00403df0(), true);
        if (DAT_011d93f8->m_pTiles[17])
            DAT_011d93f8->m_pTiles[17]->Set(subtitle, DAT_011d20c4.FUN_00403df0(), true);
        if (DAT_011d93f8->m_pTiles[18])
            DAT_011d93f8->m_pTiles[18]->Set(subtitle, DAT_011d396c.FUN_00403df0(), true);
        DAT_011d93f8->FUN_00a1dc20(0);
        DAT_011d93f8->ContainerMenu_UpdateLists(0);
        return manager;
    }
    else if (DAT_011d93f8 && DAT_011d93f8->FUN_00726070())
    {
        delete DAT_011d93f8;
    }
    return 0;
}




// The shared TESObjectCONT has the +0x8C/+0x90 fields but no out-of-line getters.
TESSound* __fastcall GetContainerOpenSound(TESObjectCONT* container);
TESSound* __fastcall GetContainerCloseSound(TESObjectCONT* container);

// @fnv 0x0075baf0
// src: XBOX_PDB 0x0075baf0
void ContainerMenu::PlayContainerSound(TESObjectREFR* apRef, bool abOpen)
{
    TESSound* SoundAssetTmp = 0;
    if (!apRef)
        return;
    switch (apRef->GetObjectReference()->GetFormType())
    {
    case 0x1b:
        if (abOpen)
            SoundAssetTmp = GetContainerOpenSound(static_cast<TESObjectCONT*>(apRef->GetObjectReference()));
        else
            SoundAssetTmp = GetContainerCloseSound(static_cast<TESObjectCONT*>(apRef->GetObjectReference()));
        break;
    case 0x2a:
    case 0x2b:
        if (abOpen)
            BSAudio::GetSingleton()->GetSoundHandleByEditorID("DRSBodyGenericOpen", 0x121).Play(false);
        else
            BSAudio::GetSingleton()->GetSoundHandleByEditorID("DRSBodyGenericClose", 0x121).Play(false);
        break;
    }
    if (SoundAssetTmp)
        BSAudio::GetSingleton()
            ->GetSoundHandleByFilePath(SoundAssetTmp->TESSound_GetFilename(), 0x121, SoundAssetTmp)
            .Play(false);
}


struct Menu75d250Pane
{
    virtual void vf00();
    virtual int IsBusy();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    unsigned GetCount();
    void Reset();
    void SetActive(int abActive);
};


bool __cdecl Interface_IsTopMenuID(int aiID);

// Handles menu actions 13/14 by switching between the two panes and actions 3/4 by resetting the active pane and setting state, returning whether handled.
// @fnv 0x0075d250
bool ContainerMenu::HandleMenuInput(int aiAction, float afUnused)
{
    bool bHandled = false;
    if (Interface_IsTopMenuID(0x3f0))
    {
        switch (aiAction)
        {
        case 13:
            if (!reinterpret_cast<Menu75d250Pane&>(m_kFirstItemChangeList).IsBusy() && reinterpret_cast<Menu75d250Pane&>(m_kFirstItemChangeList).GetCount() > 0)
            {
                reinterpret_cast<Menu75d250Pane&>(m_kSecondItemChangeList).Reset();
                HandleMouseover(0x15, 0);
                reinterpret_cast<Menu75d250Pane&>(m_kFirstItemChangeList).SetActive(1);
                bHandled = true;
            }
            break;
        case 14:
            if (!reinterpret_cast<Menu75d250Pane&>(m_kSecondItemChangeList).IsBusy() && reinterpret_cast<Menu75d250Pane&>(m_kSecondItemChangeList).GetCount() > 0)
            {
                reinterpret_cast<Menu75d250Pane&>(m_kFirstItemChangeList).Reset();
                HandleMouseover(0x16, 0);
                reinterpret_cast<Menu75d250Pane&>(m_kSecondItemChangeList).SetActive(1);
                bHandled = true;
            }
            break;
        case 3:
        case 4:
            if (m_eContainerMenuMode != 4)
            {
                if (m_pCurrentList == &m_kFirstItemChangeList)
                {
                    reinterpret_cast<Menu75d250Pane&>(m_kFirstItemChangeList).Reset();
                    HandleSelection(aiAction == 4 ? 0 : 2, 0);
                    reinterpret_cast<Menu75d250Pane&>(m_kFirstItemChangeList).SetActive(0);
                }
                else
                {
                    reinterpret_cast<Menu75d250Pane&>(m_kSecondItemChangeList).Reset();
                    HandleSelection(aiAction == 4 ? 5 : 7, 0);
                    reinterpret_cast<Menu75d250Pane&>(m_kSecondItemChangeList).SetActive(0);
                }
                bHandled = true;
            }
            break;
        }
    }
    return bHandled;
}

struct XRef_0075d6b0
{
    bool FUN_00440da0();
    bool FUN_00440d80();
};
struct XList_0075d6b0
{
    XRef_0075d6b0* ExtraDataList_GetItemDropper();
    short ExtraDataList_GetCount();
};
struct Node_0075d6b0
{
    XList_0075d6b0** FUN_006815c0();
    Node_0075d6b0* FUN_00726070();
};
struct Entry_0075d6b0
{
    ~Entry_0075d6b0();
    SourceForm* FUN_0044ddc0();
    Node_0075d6b0* Modelloader_GetReferencedThis();
    Node_0075d6b0* FUN_00726070();
};
struct Ref_0075d6b0
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void FUN_17c(SourceForm* item, XList_0075d6b0* extra, int count, bool stolen, int a5, Ref_0075d6b0* from,
                         int a7, int a8, bool a9, int a10);
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void FUN_190(SourceForm* item, XList_0075d6b0* extra, Node_0075d6b0* next);
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void FUN_3d0(XRef_0075d6b0* ref, bool a2, bool a3);
    Entry_0075d6b0* PlayerCharacter_RemoveRockItAmmo(SourceForm* item, XList_0075d6b0* extra, int count, bool a4);
    void PlayerCharacter_AddRockItAmmo(SourceForm* item, XList_0075d6b0* extra, int count);
};
struct List_0075d6b0
{
    void FUN_005ae3d0(SourceForm* const& item);
};
int __cdecl MinInt(int a, int b);
void __cdecl BGSProjectile_InitLiveGrenade(CurrentItem* item, Ref_0075d6b0* to, Ref_0075d6b0* from, SourceForm* form);
// Item transfer is not yet declared by the shared header.
// This extension adds that operation without duplicating the menu layout.
struct ContainerItemTransfer : ContainerMenu
{
    void TransferItem(void* a1, Entry_0075d6b0* entry, int count);
};
// Moves count of an entry's item between the container's two references, handling the special container and splitting stacks when needed.
// @fnv 0x0075d6b0
void ContainerItemTransfer::TransferItem(void* a1, Entry_0075d6b0* entry, int count)
{
    if (!entry || !a1)
        return;
    Ref_0075d6b0* from4 = (m_pCurrentList == &m_kFirstItemChangeList) ? (Ref_0075d6b0*)m_pContainer
                                                                                : (Ref_0075d6b0*)DAT_011dea3c;
    Ref_0075d6b0* to8 = (m_pCurrentList == &m_kFirstItemChangeList) ? (Ref_0075d6b0*)DAT_011dea3c
                                                                              : (Ref_0075d6b0*)m_pContainer;
    bool ok = IsPlacingMine(reinterpret_cast<InventoryEntry*>(entry), reinterpret_cast<ExpectedReference*>(to8), reinterpret_cast<ActorView*>(from4));
    XList_0075d6b0* extra = entry->Modelloader_GetReferencedThis() ? *entry->Modelloader_GetReferencedThis()->FUN_006815c0() : 0;
    if (ok)
    {
        BGSProjectile_InitLiveGrenade(entry->FUN_0044ddc0()->GetOrFallback(0), to8, from4, entry->FUN_0044ddc0());
        ((List_0075d6b0*)&m_kContainerItems)->FUN_005ae3d0(entry->FUN_0044ddc0());
        to8->FUN_17c(entry->FUN_0044ddc0(), extra, count, 0, 0, 0, 0, 0, 1, 0);
        return;
    }
    if (extra && extra->ExtraDataList_GetItemDropper() && !extra->ExtraDataList_GetItemDropper()->FUN_00440da0() &&
        !extra->ExtraDataList_GetItemDropper()->FUN_00440d80())
    {
        ((Ref_0075d6b0*)DAT_011dea3c)->FUN_3d0(extra->ExtraDataList_GetItemDropper(), 1, 0);
        return;
    }
    if (m_eContainerMenuMode == 4)
    {
        int remaining = count;
        Node_0075d6b0* nodeB = entry->Modelloader_GetReferencedThis();
        while (remaining > 0)
        {
            XList_0075d6b0* x4 = nodeB ? *nodeB->FUN_006815c0() : 0;
            int n7 = x4 ? x4->ExtraDataList_GetCount() : remaining;
            n7 = MinInt(n7, remaining);
            if (from4 == (Ref_0075d6b0*)DAT_011dea3c)
            {
                Entry_0075d6b0* movedB = ((Ref_0075d6b0*)DAT_011dea3c)->PlayerCharacter_RemoveRockItAmmo(entry->FUN_0044ddc0(), x4, n7, 1);
                ((Ref_0075d6b0*)DAT_011dea3c)
                    ->FUN_190(movedB->FUN_0044ddc0(),
                              movedB->Modelloader_GetReferencedThis() ? *movedB->Modelloader_GetReferencedThis()->FUN_006815c0() : 0,
                              movedB->FUN_00726070());
                delete movedB;
                nodeB = entry->Modelloader_GetReferencedThis();
            }
            else if (to8 == (Ref_0075d6b0*)DAT_011dea3c)
            {
                ((Ref_0075d6b0*)DAT_011dea3c)->PlayerCharacter_AddRockItAmmo(entry->FUN_0044ddc0(), x4, n7);
                to8->FUN_17c(entry->FUN_0044ddc0(), x4, n7, 0, 0, 0, 0, 0, 1, 0);
                nodeB = nodeB ? nodeB->FUN_00726070() : 0;
            }
            remaining -= n7;
        }
        return;
    }
    to8->FUN_17c(entry->FUN_0044ddc0(), extra, count, m_eContainerMenuMode == 2, 0, from4, 0, 0, 1, 0);
}

namespace fnv_0075e0b0 {
extern Actor* DAT_011dea3c;
// 0x00476c00/0x00AA5230 are MersenneTwister generator/range routines, not Random::Next.
struct IntegerRangeGenerator
{
    unsigned int FUN_00aa5230();
};
IntegerRangeGenerator* __stdcall FUN_00476c00(int);
int __cdecl ComputeClampedSettingSum(int, int, float);
void __cdecl FUN_004d5c60(int);

extern Setting DAT_011d3f94;
extern Setting DAT_011cde20;
bool __cdecl DispatchMessageToSink(const char*, int, const char*, const char*, float, bool);
unsigned int __cdecl TESActorBaseData_GetAlignmentForKarma(float);
}  // namespace fnv_0075e0b0

// @fnv 0x0075e0b0
// src: XBOX_PDB 0x0075e0b0
bool ContainerMenu::PickpocketCheck(Actor* actor, int amount)
{
    bool success = true;
    if (actor && amount > 0 && !actor->GetHasKnockedState())
    {
        int chance = fnv_0075e0b0::ComputeClampedSettingSum(
            fnv_0075e0b0::DAT_011dea3c->GetActorValueAsInteger(static_cast<ActorValue::Index>(42)),
            actor->GetActorValue(static_cast<ActorValue::Index>(42)), (float)amount);
        // Actor::Unk_11F has no arguments in the shared header; this call uses two stack arguments.
        reinterpret_cast<void (__thiscall*)(Actor*, int, int)>(
            (*reinterpret_cast<void***>(fnv_0075e0b0::DAT_011dea3c))[0x11F])(
                fnv_0075e0b0::DAT_011dea3c, 42, 1);
        if (fnv_0075e0b0::FUN_00476c00(100)->FUN_00aa5230() < (unsigned int)chance)
        {
            if (m_pCurrentList == &m_kSecondItemChangeList && !m_bFirstContainerFlag)
            {
                fnv_0075e0b0::FUN_004d5c60(13);
                m_bFirstContainerFlag = true;
            }
        }
        else
        {
            fnv_0075e0b0::DAT_011dea3c->PickpocketAlarm(actor, 0, 0);
            fnv_0075e0b0::DispatchMessageToSink(fnv_0075e0b0::DAT_011d3f94.FUN_00403df0(), 2, 0, 0, 2.0f, false);
            success = false;
            m_bSecondContainerFlag = true;
        }
        actor->GetActorBase();
        unsigned int type = fnv_0075e0b0::TESActorBaseData_GetAlignmentForKarma(actor->GetActorBase()->GetCurrentActorValue(static_cast<ActorValue::Index>(23)));
        if (type != 2 && type != 4)
        {
            static_cast<PlayerCharacter*>(fnv_0075e0b0::DAT_011dea3c)->ModifyKarmaForTheft((int)*fnv_0075e0b0::DAT_011cde20.Setting_Float_00403e20());
        }
    }
    return success;
}


struct TrimGlyph
{
    int texture;
    float uv[8];
    float width, height, leading, spacing, top;
};
struct TrimFontData
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
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    TrimGlyph letters[256];
};
struct TrimFont
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
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    TrimFontData* data;
};
struct TrimManager
{
    void FUN_00a1b020(float*, const char*, int, float, int);
    TrimFont* FUN_005bd5c0(int);
};
TrimManager* FUN_005bd5b0();
extern float DAT_01016970;
extern double DAT_01072310, DAT_010356b0, DAT_01021928;
void* ourMemset(void*, int, unsigned int);
int FUN_00406d50(char*, unsigned int, const char*);
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
// @fnv 0x0075e8c0
void ContainerMenu::SetLabelText(const char* text)
{
    if (!text || !text[0])
        return;
    int font8 = (int)m_pTiles[6]->FUN_00a011b0(4025);
    float dimensions9[3];
    FUN_005bd5b0()->FUN_00a1b020(dimensions9, text, font8, DAT_01016970, 0);
    float widthTmp = m_pTiles[6]->FUN_0045cd60()->FUN_00a011b0(4017) - DAT_01072310;
    if (m_pTiles[5]->IsTraitNonZero(4003))
        widthTmp -= DAT_010356b0;
    if (dimensions9[0] > widthTmp)
    {
        char* buffer = new char[260];
        TrimGlyph* letters = FUN_005bd5b0()->FUN_005bd5c0(font8 - 1)->data->letters;
        float total2 = 0.0f;
        int index = 0;
        ourMemset(buffer, 0, 260);
        total2 += (letters[46].leading + letters[46].width + letters[46].spacing) * DAT_01021928;
        while (total2 <= widthTmp && index < 260)
        {
            buffer[index] = text[index];
            total2 += letters[text[index]].leading + letters[text[index]].width + letters[text[index]].spacing;
            index++;
        }
        FUN_00406d50(buffer, 260, "...");
        m_pTiles[6]->Tile_Set_00a01350(4036, buffer, true);
        delete[] buffer;
    }
    else
        m_pTiles[6]->Tile_Set_00a01350(4036, text, true);
}

extern const char str_010721f4[];
extern const char DAT_01011584[];
extern unsigned char DAT_011a002c;
extern void* DAT_011d93fc;


unsigned __cdecl Cmd_GetSessionTime_Execute();
void* __cdecl Tile_GetTileByName(void* obj, const char* name);
unsigned __fastcall GetRaceCount(char* buf);
void* __fastcall FUN_0044ddc0(void* obj);
int __fastcall FUN_00401170(void* obj);
void __cdecl UpdateAnimationTileFade(int a, int b, int c, void* d, int e);



struct RefObj
{
    float TESObjectARMO_GetDamageThreshold();
    float TESObjectARMO_GetArmorRating();
};


extern ContainerMenu* DAT_011d93f8;

// @fnv 0x0075eac0
void ContainerMenu::UpdateDialog()
{
    if (m_uiCurrentItemIndex != 0 && Cmd_GetSessionTime_Execute() > (unsigned int)m_uiCurrentItemIndex)
    {
        m_uiCurrentItemIndex = 0;
        Tile* tile = (Tile*)Tile_GetTileByName(DAT_011d93f8->FUN_00726070(), str_010721f4);
        if (tile != 0)
        {
            tile->Tile_Set_00a01350(0xfc4, DAT_01011584, true);
        }
    }
    if (GetRaceCount(reinterpret_cast<char*>(&m_kSecondItemChangeList)) > 0 && DAT_011a002c != 0)
    {
        if (DAT_011d93fc != 0 && FUN_00401170(FUN_0044ddc0(DAT_011d93fc)) == 0x28)
        {
            UpdateAnimationTileFade((int)m_pTiles[14], (int)m_pTiles[15], (int)m_pTiles[16], DAT_011d93fc, 0);
        }
        else if (DAT_011d93fc != 0 && FUN_00401170(FUN_0044ddc0(DAT_011d93fc)) == 0x18)
        {
            UpdateAnimationTileFade(
                (DAT_011d93fc != 0 && ((RefObj*)FUN_0044ddc0(DAT_011d93fc))->TESObjectARMO_GetArmorRating() != 0.0) ? (int)m_pTiles[17] : 0,
                (DAT_011d93fc != 0 && ((RefObj*)FUN_0044ddc0(DAT_011d93fc))->TESObjectARMO_GetDamageThreshold() != 0.0) ? (int)m_pTiles[18] : 0, 0,
                DAT_011d93fc, 0);
        }
    }
}

extern int DAT_0106ff84;
void* __cdecl ourMemset(void*, int, unsigned int);
struct Base0071
{
    Base0071();
    ~Base0071();
    void* vtable;
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
};
struct FUN_0071f240 : Base0071
{
    unsigned int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    unsigned int unk48, unk4c, unk50;
    FUN_0071f240();
};
// Sets the vtable, zeroes the 0x20-byte block at unk28, and clears unk4c, unk48 and unk50.
// @fnv 0x0071f240
FUN_0071f240::FUN_0071f240()
{
    vtable = &DAT_0106ff84;
    ourMemset(&unk28, 0, 0x20);
    unk4c = 0;
    unk48 = 0;
    unk50 = 0;
}

// 0x0075cd70  unit_5a9677af71cd.cpp  /MT /Od /Oy- /GS /EHsc /Gy /GF
// thiscall, 2 stack args (ret 8): optional tile lookup, then a switch over the
// tile id (0x14..0x16) driving two mutually exclusive state objects, then the
// shared refresh path that re-inits the visible tile texts.
extern "C" unsigned char DAT_011a002c;
extern "C" void* DAT_011d93fc;



struct StateObj75
{
    void* FUN_007a1910();
};
struct RetObj75
{
    const char* GetIconFilename(int arg);
};

void __cdecl Interface_PopulateItemStatsDisplay(void* a, void* b);

struct Emb75
{
    virtual void v00(int flags);
};


// Handles tile index 0x14-0x16: switches the active state between a98 and b0, updates tiles from the state object, and sets DAT_011a002c.
// @fnv 0x0075cd70
void ContainerMenu::HandleMouseover(unsigned int iTileIndex, Tile* pProcess)
{
    if (pProcess == 0 && static_cast<int>(iTileIndex) >= 0 && static_cast<int>(iTileIndex) < 0x13)
    {
        pProcess = m_pTiles[iTileIndex];
    }

    switch (iTileIndex)
    {
    case 0x15:
        HandleMouseoverTileAlt(0x14, 0);
        reinterpret_cast<Emb75&>(m_kSecondItemChangeList).v00(0);
        m_pCurrentList = &m_kFirstItemChangeList;
        break;
    case 0x16:
        HandleMouseoverTileAlt(0x14, 0);
        reinterpret_cast<Emb75&>(m_kFirstItemChangeList).v00(0);
        m_pCurrentList = &m_kSecondItemChangeList;
        break;
    case 0x14:
        if (pProcess)
        {
            DAT_011a002c = 1;
            if (m_pCurrentList != &m_kFirstItemChangeList && reinterpret_cast<HighProcess*>(pProcess)->GetProcessLevel() == (int)m_pTiles[4])
            {
                HandleMouseover(0x15, 0);
            }
            else
            {
                if (m_pCurrentList != &m_kSecondItemChangeList && reinterpret_cast<HighProcess*>(pProcess)->GetProcessLevel() == (int)m_pTiles[8])
                {
                    HandleMouseover(0x16, 0);
                }
            }
            DAT_011d93fc = ((StateObj75*)m_pCurrentList)->FUN_007a1910();
            if (DAT_011d93fc)
            {
                Interface_PopulateItemStatsDisplay(DAT_011d93fc, m_pTiles[13]);
                ((Tile*)m_pTiles[13])->FUN_00700320(0xfa3, 1);
                ((Tile*)m_pTiles[12])->Tile_Set_00a01350(0xfcc, ((RetObj75*)DAT_011d93fc)->GetIconFilename(0), 1);
                ((Tile*)m_pTiles[12])->FUN_00700320(0xfa3, 1);
                ((Tile*)m_pTiles[9])->FUN_00700320(0x1004, (m_pCurrentList != &m_kFirstItemChangeList) + 1);
                ((Tile*)m_pTiles[9])->FUN_00700320(0xfa3, 1);
            }
        }
    }
}

// HandleContainerMenuActivate v1
extern void* DAT_011d93fc;
extern const char DAT_01012058[];
struct EntrySrc75
{
    void* FindItemData(void** pp);
};
struct FloatSrc75
{
    float FUN_00a011b0();
};
bool __fastcall PlayerCharacter_IsHardcore(void* player);

float __cdecl FUN_0048ebc0(int a, bool b);
struct Sound75
{
    double TESObjectREFR_GetWeightInContainer(int a);
};
struct StrThis75
{
    const char* FUN_00403df0();
};
extern StrThis75 g_011d2628;
struct Name75
{
    const char* TESObjectREFR_GetFullName();
};
struct Msg75
{
    static bool __cdecl DispatchMessageToSink(const char* msg, int a2, const char* a3, const char* a4, float a5,
                                              bool a6);
};


TESForm* __cdecl FUN_00483a00(void* a1);

extern char DAT_010722dc;
extern int DAT_01183028;
extern int DAT_01184720;
struct FloatThis75
{
    double Actor_GetMaxCarryWeight();
};
struct Form75
{
    void* __thiscall GetExtraForm();
};
void* __fastcall BGSSaveFormBuffer_GetForm(void* p);
struct PlayerAct75
{
    void PlayActorSound(void* a1, int a2, int a3);
};
struct ActorProc75
{
    virtual void vfn_0000();
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual void vfn_000c();
    virtual void vfn_0010();
    virtual void vfn_0014();
    virtual void vfn_0018();
    virtual void vfn_001c();
    virtual void vfn_0020();
    virtual void vfn_0024();
    virtual void vfn_0028();
    virtual void vfn_002c();
    virtual void vfn_0030();
    virtual void vfn_0034();
    virtual void vfn_0038();
    virtual void vfn_003c();
    virtual void vfn_0040();
    virtual void vfn_0044();
    virtual void vfn_0048();
    virtual void vfn_004c();
    virtual void vfn_0050();
    virtual void vfn_0054();
    virtual void vfn_0058();
    virtual void vfn_005c();
    virtual void vfn_0060();
    virtual void vfn_0064();
    virtual void vfn_0068();
    virtual void vfn_006c();
    virtual void vfn_0070();
    virtual void vfn_0074();
    virtual void vfn_0078();
    virtual void vfn_007c();
    virtual void vfn_0080();
    virtual void vfn_0084();
    virtual void vfn_0088();
    virtual void vfn_008c();
    virtual void vfn_0090();
    virtual void vfn_0094();
    virtual void vfn_0098();
    virtual void vfn_009c();
    virtual void vfn_00a0();
    virtual void vfn_00a4();
    virtual void vfn_00a8();
    virtual void vfn_00ac();
    virtual void vfn_00b0();
    virtual void vfn_00b4();
    virtual void vfn_00b8();
    virtual void vfn_00bc();
    virtual void vfn_00c0();
    virtual void vfn_00c4();
    virtual void vfn_00c8();
    virtual void vfn_00cc();
    virtual void vfn_00d0();
    virtual void vfn_00d4();
    virtual void vfn_00d8();
    virtual void vfn_00dc();
    virtual void vfn_00e0();
    virtual void vfn_00e4();
    virtual void vfn_00e8();
    virtual void vfn_00ec();
    virtual void vfn_00f0();
    virtual void vfn_00f4();
    virtual void vfn_00f8();
    virtual void vfn_00fc();
    virtual void vfn_0100();
    virtual void vfn_0104();
    virtual void vfn_0108();
    virtual void vfn_010c();
    virtual void vfn_0110();
    virtual void vfn_0114();
    virtual void vfn_0118();
    virtual void vfn_011c();
    virtual void vfn_0120();
    virtual void vfn_0124();
    virtual void vfn_0128();
    virtual void vfn_012c();
    virtual void vfn_0130();
    virtual void vfn_0134();
    virtual void vfn_0138();
    virtual void vfn_013c();
    virtual void vfn_0140();
    virtual void vfn_0144();
    virtual void vfn_0148();
    virtual void* vfn_014c();
    virtual void vfn_0150();
    virtual void vfn_0154();
    virtual void vfn_0158();
    virtual void vfn_015c();
    virtual void vfn_0160();
    virtual void vfn_0164();
    virtual void vfn_0168(int);
};
struct ProcGet75
{
    ActorProc75* FUN_008d8520();
};
struct Inv75
{
    static Inv75* __cdecl FUN_004bf220(void* refr);
    int FUN_004c8f30(void* form);
};

// @fnv 0x0075dc80
void __cdecl HandleContainerMenuActivate(int aiCount)
{
    void* expected;
    void* refObj;
    void* entry;
    {
        bool flag;
        {
            char msgtext[260];
            entry = ((EntrySrc75*)DAT_011d93f8->m_pCurrentList)->FindItemData(&DAT_011d93fc);
            refObj = (DAT_011d93f8->m_pContainer && ((CloseVirtualSlots*)DAT_011d93f8->m_pContainer)->IsActor())
                         ? (void*)DAT_011d93f8->m_pContainer
                         : 0;
            flag = false;
            expected = (DAT_011d93f8->m_pCurrentList == &DAT_011d93f8->m_kFirstItemChangeList)
                           ? (void*)DAT_011dea3c
                           : (void*)DAT_011d93f8->m_pContainer;
            if (aiCount == 0 || DAT_011d93fc == 0 || entry == 0)
                flag = true;
            if (((FloatSrc75*)*(void**)((ContainerLikeObj*)((int*)entry + 1))->FUN_007b5370(4009))->FUN_00a011b0() ==
                128.0)
                flag = true;
            if (DAT_011d93f8->m_eContainerMenuMode == 3 &&
                DAT_011d93f8->m_pCurrentList == &DAT_011d93f8->m_kFirstItemChangeList && refObj != 0)
            {
                if (((Sound75*)refObj)->TESObjectREFR_GetWeightInContainer(0) +
                        FUN_0048ebc0((int)FUN_0044ddc0(DAT_011d93fc), PlayerCharacter_IsHardcore((void*)DAT_011dea3c)) * aiCount >=
                    ((FloatThis75*)refObj)->Actor_GetMaxCarryWeight())
                {
                    BSsprintf(msgtext, 260, DAT_01012058, (char*)((Name75*)refObj)->TESObjectREFR_GetFullName(),
                                 (int)g_011d2628.FUN_00403df0());
                    Msg75::DispatchMessageToSink(msgtext, 2, 0, 0, 2.0f, false);
                    flag = true;
                    int id = (int)dynamic_cast<TESTopic*>(FUN_00483a00(&DAT_010722dc));
                    DAT_011d93f8->PlaySelectedTopicInfo(reinterpret_cast<PlaybackTopic*>(id));
                }
            }
        }
        if (DAT_011d93f8 != 0 && DAT_011d93f8->m_eContainerMenuMode == 2)
        {
            if ((expected == (void*)DAT_011dea3c && refObj != 0) ||
                (expected != (void*)DAT_011dea3c &&
                 ((Form75*)DAT_011d93fc)->GetExtraForm() != BGSSaveFormBuffer_GetForm((void*)DAT_011dea3c)))
            {
                int stolenDelta;
                bool isC8 = (DAT_011d93f8->m_pCurrentList == &DAT_011d93f8->m_kSecondItemChangeList);
                stolenDelta =
                    DAT_011d93f8->GetContainerValue((ItemEntry*)DAT_011d93fc, aiCount, isC8) *
                    (isC8 ? 1 : -1);
                DAT_011d93f8->m_iStolenItemCount += stolenDelta;
                if (!isC8)
                    stolenDelta = 1;
                if (refObj != 0)
                {
                    if (!DAT_011d93f8->PickpocketCheck(reinterpret_cast<Actor*>(refObj), stolenDelta))
                    {
                        flag = true;
                        ContainerMenu::Close();
                    }
                }
            }
        }
        if (!flag)
        {
            void* processBaseObject;
            void* pCachedForm = (void*)FUN_0044ddc0(DAT_011d93fc);
            processBaseObject = ((ProcGet75*)DAT_011dea3c)->FUN_008d8520()->vfn_014c();
            ((PlayerAct75*)DAT_011dea3c)->PlayActorSound(pCachedForm, 1, 0);
            static_cast<ContainerItemTransfer*>(DAT_011d93f8)->TransferItem(entry, static_cast<Entry_0075d6b0*>(DAT_011d93fc), aiCount);
            DAT_011d93f8->ContainerMenu_UpdateLists((int)pCachedForm);
            if (processBaseObject != 0)
            {
                if (Inv75::FUN_004bf220((void*)DAT_011dea3c)->FUN_004c8f30((void*)FUN_0044ddc0(processBaseObject)) == 0)
                {
                    ((ProcGet75*)DAT_011dea3c)->FUN_008d8520()->vfn_0168(0);
                }
            }
        }
    }
}

struct S650Form
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
    virtual unsigned char v37();
    int FUN_00401170();
    unsigned char FUN_004c94d0();
};
struct S650Ref
{
    S650Form* FUN_0044ddc0();
    bool ItemChange_GetWorn(bool);
};
struct S650List
{
    void* FindItemData(S650Ref**);
};
struct S650Group
{
    int GetConditionIndex(S650Form*);
};
S650Group* __cdecl FUN_00483a00(char*);
extern "C" char DAT_010722f4;
extern "C" char DAT_011D93F8;
struct S650Global
{
    char pad[0x80];
    int mode;
    int unk84;
    int unk88;
    int first;
    int second;
    int unk94;
    S650List list1;
    char pad99[0xc8 - 0x99];
    S650List list2;
};
struct S650
{
    static bool ContainerMenu_FilterModeFunc(S650Ref* arg);
};
// Looks up the ref in list1/list2, applies a type-based filter switch, then adds group, form and mode checks to return whether the ref passes.
// @fnv 0x0075e650
// src: XBOX_PDB 0x0075e650
bool S650::ContainerMenu_FilterModeFunc(S650Ref* pRef)
{
    bool result2 = false;
    int type6 = pRef->FUN_0044ddc0()->FUN_00401170();
    void* found8 = (*(S650Global**)&DAT_011D93F8)->list1.FindItemData(&pRef);
    int filterVal = 0;
    bool firstB = true;
    if (found8)
    {
        filterVal = (*(S650Global**)&DAT_011D93F8)->first;
    }
    else
    {
        found8 = (*(S650Global**)&DAT_011D93F8)->list2.FindItemData(&pRef);
        filterVal = (*(S650Global**)&DAT_011D93F8)->second;
        firstB = false;
    }
    switch (filterVal)
    {
        break;
    case 1:
        result2 = type6 != 0x28;
        break;
    case 2:
        result2 = type6 != 0x18 && type6 != 0x1a;
        break;
    case 3:
        result2 = type6 != 0x1d && type6 != 0x2f && type6 != 0x19;
        break;
    case 4:
        result2 = type6 == 0x28 || type6 == 0x18 || type6 == 0x1a || type6 == 0x1d || type6 == 0x2f || type6 == 0x29 ||
                  type6 == 0x19 || type6 == 0x6c || type6 == 0x73 || type6 == 0x74;
        break;
    case 5:
        result2 = type6 != 0x29;
    }
    if (type6 == 0x29)
    {
        S650Group* group = FUN_00483a00(&DAT_010722f4);
        S650Form* form = pRef->FUN_0044ddc0();
        if (group && group->GetConditionIndex(form) >= 0)
            result2 = true;
        if (form && !form->FUN_004c94d0())
            result2 = true;
    }
    if (firstB)
    {
        result2 = result2 || type6 == 0x2e || pRef->FUN_0044ddc0()->v37();
    }
    else if ((*(S650Global**)&DAT_011D93F8)->mode == 2)
    {
        result2 = result2 || pRef->ItemChange_GetWorn(false);
    }
    return result2;
}


class PlaybackHandle
{
  public:
    unsigned soundID;
    bool assumeSuccess;
    unsigned state;
    PlaybackHandle(const PlaybackHandle&);
    ~PlaybackHandle();
    PlaybackHandle& operator=(const PlaybackHandle&);
};

class PlaybackResponse
{
  public:
    TESForm* GetSoundByEditorID();
    unsigned GetSoundID();
    BSStringT<char>* GetText();
    unsigned GetEmotion();
    unsigned GetEmotionValue();
    unsigned GetFlags();
    BSStringT<char>* GetVoiceFilePath();
};
// This dispatch view describes slots directly, independently of Actor's bases.
class PlaybackActor
{
  public:
    virtual ~PlaybackActor();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual void slot1e4();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual void slot1f4();
    virtual void slot1f8();
    virtual void slot1fc();
    virtual void slot200();
    virtual void slot204();
    virtual void slot208();
    virtual void slot20c();
    virtual void slot210();
    virtual void slot214();
    virtual void slot218();
    virtual void slot21c();
    virtual void slot220();
    virtual void slot224();
    virtual void slot228();
    virtual void slot22c();
    virtual void slot230();
    virtual void slot234();
    virtual void slot238();
    virtual void slot23c();
    virtual void slot240();
    virtual void slot244();
    virtual void slot248();
    virtual void slot24c();
    virtual void slot250();
    virtual void slot254();
    virtual void slot258();
    virtual void slot25c();
    virtual void slot260();
    virtual void slot264();
    virtual void slot268();
    virtual void slot26c();
    virtual void slot270();
    virtual void slot274();
    virtual void slot278();
    virtual void slot27c();
    virtual void slot280();
    virtual float PlayVoice(const char*, PlaybackHandle*, unsigned, unsigned, unsigned, unsigned, unsigned,
                            ExpectedReference*, bool, bool, unsigned, unsigned, bool);
    PlaybackHandle GetActorSoundHandle(unsigned, unsigned, unsigned, bool);
};
class PlaybackTopicInfo
{
  public:
    void* GetQuest();
};
class PlaybackTopic
{
  public:
    PlaybackTopicInfo* SelectInfo(Actor*, ExpectedReference*);
};
class PlaybackDialogue
{
  public:
    void* quest;
    PlaybackTopic* topic;
    PlaybackTopicInfo* info;
    TESObjectREFR* speaker;
    void* responses;
    void* current;
    unsigned flags;
    PlaybackDialogue(void*, PlaybackTopic*, PlaybackTopicInfo*, Actor*);
    ~PlaybackDialogue();
    void Begin();
    PlaybackResponse* GetCurrentItem();
};
// Selects a topic info for the current actor, begins a dialogue, and plays the current response's sound or voice, then updates the menu.
// @fnv 0x0075ec60
void ContainerMenu::PlaySelectedTopicInfo(PlaybackTopic* topic)
{
    PlaybackTopicInfo* _item = 0;
    ExpectedReference* _context = DAT_011dea3c;
    Actor* _actor = DAT_011d93f8->m_pContainer && DAT_011d93f8->m_pContainer->IsActor()
                        ? dynamic_cast<Actor*>(DAT_011d93f8->m_pContainer)
                        : 0;
    if (topic)
        _item = topic->SelectInfo(_actor, _context);
    if (_item)
    {
        PlaybackDialogue _data(_item->GetQuest(), topic, _item, _actor);
        _data.Begin();
        PlaybackResponse* _entry = _data.GetCurrentItem();
        if (_entry)
        {
            if (_entry->GetSoundByEditorID())
            {
                unsigned soundID = _entry->GetSoundByEditorID()->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
                reinterpret_cast<PlaybackHandle&>(m_kFadeSequence) =
                    reinterpret_cast<PlaybackActor*>(_actor)->GetActorSoundHandle(soundID, 0, 0x102, true);
            }
            else
            {
                float duration = reinterpret_cast<PlaybackActor*>(_actor)->PlayVoice(
                    _entry->GetVoiceFilePath()->String(), reinterpret_cast<PlaybackHandle*>(&m_kFadeSequence),
                    _entry->GetFlags(), _entry->GetSoundID(), _entry->GetText()->Length(), _entry->GetEmotion(),
                    _entry->GetEmotionValue(), DAT_011dea3c, true, true, 0, 0, true);
            }
            ShowMessageWithSound(*_entry->GetText(), reinterpret_cast<PlaybackHandle&>(m_kFadeSequence));
        }
    }
}

// Native twelve-byte audio handle; its empty but nontrivial destructor is
// retained for the by-value parameter's genuine cleanup contract.
struct BoolSetting539
{
    bool* FUN_00408d60();
};
struct FloatSetting539
{
    float* Setting_Float_00403e20();
};
extern BoolSetting539 DAT_011d8928;
extern FloatSetting539 DAT_011d2178;
extern const char DAT_010721f4[];
extern "C" unsigned int __cdecl strlen(const char*);
unsigned int __cdecl Cmd_GetSessionTime_Execute();
struct ActorAccess539
{
    bool BSSoundHandle_BSSoundHandle_008c1bc0();
};
// @fnv 0x0075eea0
void ContainerMenu::ShowMessageWithSound(StrMem strMessage, BSSoundHandle soundHandle)
{
    float duration3 = 0.0f;
    Actor* actor = (DAT_011d93f8->m_pContainer && ((CloseVirtualSlots*)DAT_011d93f8->m_pContainer)->IsActor())
                       ? dynamic_cast<Actor*>(DAT_011d93f8->m_pContainer)
                       : 0;
    if (strMessage.BSStringT_char_Length() > 0 &&
        (*DAT_011d8928.FUN_00408d60() || (actor && ((ActorAccess539*)actor)->BSSoundHandle_BSSoundHandle_008c1bc0())))
    {
        Tile* tile = (Tile*)Tile_GetTileByName(DAT_011d93f8->FUN_00726070(), DAT_010721f4);
        if (tile)
            tile->Tile_Set_00a01350(0xfc4, strMessage.Modelloader_GetReferencedThis(), true);
        duration3 = (float)soundHandle.GetDuration();
        if (duration3 == 0.0)
            duration3 = strlen(strMessage.Modelloader_GetReferencedThis()) * *DAT_011d2178.Setting_Float_00403e20() * 1000.0;
        m_uiCurrentItemIndex = (unsigned int)(Cmd_GetSessionTime_Execute() + duration3);
    }
}

struct xRef
{
    bool IsDisabled();
    bool IsDeleted();
};
struct xExtra
{
    xRef* GetRef();
};
struct xInner
{
    xExtra** First();
};
struct xItem
{
    xInner* Get();
    int GetCount();
    unsigned int GetFlags();
};
struct xVal
{
    float GetFloat();
};
struct xValMap
{
    xVal* const& Find(int i);
};
struct xTile
{
    int m_i0;
    xValMap m_kFormatEntries;
};
class xCont
{
  public:
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
    virtual bool IsActorX();
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
    virtual void AddItem(unsigned int a, void* b, int c, bool d, int e, void* f, int g, int h, int i, int j);
};
class xPlayer
{
  public:
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
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void Activate(void* pRef, int a, int b);
};
extern ContainerMenu* xContMenu;
extern xPlayer* xThePlayer;

// Activates a valid referenced item; otherwise may transfer it, update menu state, and call AddItem.
// @fnv 0x0075da60
// src: XBOX_PDB 0x0075da60
void ContainerMenu_TakeAllFn(xTile* pTile, xItem* pItem)
{
    if (!pItem || !xContMenu || !pTile || xContMenu->m_bSecondContainerFlag)
        return;
    xExtra* qfTOqo = 0;
    if (pItem->Get())
        qfTOqo = *pItem->Get()->First();
    if (qfTOqo && qfTOqo->GetRef() && !qfTOqo->GetRef()->IsDisabled() && !qfTOqo->GetRef()->IsDeleted())
    {
        xThePlayer->Activate(qfTOqo->GetRef(), 1, 0);
        return;
    }
    if (pTile->m_kFormatEntries.Find(0xfa9)->GetFloat() == 128.0)
        return;
    if (xContMenu->m_eContainerMenuMode == 2)
    {
        xCont* pActor = reinterpret_cast<xCont*>(xContMenu->m_pContainer)->IsActorX() ? reinterpret_cast<xCont*>(xContMenu->m_pContainer) : 0;
        int iTransferred = xContMenu->GetContainerValue(reinterpret_cast<ItemEntry*>(pItem), pItem->GetCount(), true);
        xContMenu->m_iStolenItemCount += iTransferred;
        xContMenu->m_bSecondContainerFlag = !xContMenu->PickpocketCheck(reinterpret_cast<Actor*>(pActor), iTransferred);
    }
    reinterpret_cast<xCont*>(xContMenu->m_pContainer)->AddItem(pItem->GetFlags(), pItem->Get() ? *pItem->Get()->First() : 0, pItem->GetCount(),
                                 xContMenu->m_eContainerMenuMode == 2, 0, xThePlayer, 0, 0, 1, 0);
}

extern "C" void* __cdecl FUN_00ec43fb(void* p, long off, void* src, void* dst, int isRef);

TESForm* FUN_00483a00(const char* pcName);
void DialogMenu_ServiceStart();
struct RefX
{
    int TESObjectREFR_GetFullName();
};
struct GlobX
{
    int FUN_00403df0(int i);
};
extern GlobX DAT_011d3c40;
struct SubX
{
    int TESModel_GetModel();
};
struct PlayerX
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
    int unk28;
    int unk2c;
    SubX kSub;
};
struct HudX
{
    PlayerX* Actor_GetCurrentWeapon();
};
// Switches on m80 to update labels, play the trader sound and selected topic info, or set tile traits to zero.
// @fnv 0x0075bc80
// src: XBOX_PDB 0x0075bc80
void ContainerMenu::InitContainerMode()
{
    switch (m_eContainerMenuMode)
    {
    case 1:
    case 2:
        if (m_pContainer)
        {
            SetLabelText(reinterpret_cast<const char*>(reinterpret_cast<RefX*>(m_pContainer)->TESObjectREFR_GetFullName()));
            PlayContainerSound(m_pContainer, true);
        }
        break;
    case 3:
        if (m_pContainer)
        {
            SetLabelText(reinterpret_cast<const char*>(reinterpret_cast<RefX*>(m_pContainer)->TESObjectREFR_GetFullName()));
            BSAudio::GetSingleton()->GetSoundHandleByEditorID("DRSTraderOpen", 0x121).Play(false);
            DialogMenu_ServiceStart();
            TESTopic* pkForm = dynamic_cast<TESTopic*>(FUN_00483a00("FollowersTrade"));
            DAT_011d93f8->PlaySelectedTopicInfo(reinterpret_cast<PlaybackTopic*>(pkForm));
        }
        m_pTiles[10]->FUN_00700320(0xfa3, 0);
        break;
    case 4:
        m_pTiles[1]->Set(0xfc4, reinterpret_cast<const char*>(DAT_011d3c40.FUN_00403df0(1)));
        if (((HudX*)DAT_011dea3c)->Actor_GetCurrentWeapon())
            SetLabelText(reinterpret_cast<const char*>(((HudX*)DAT_011dea3c)->Actor_GetCurrentWeapon()->kSub.TESModel_GetModel()));
        m_pTiles[10]->FUN_00700320(0xfa3, 0);
        m_pTiles[0]->FUN_00700320(0xfa3, 0);
        m_pTiles[2]->FUN_00700320(0xfa3, 0);
        m_pTiles[5]->FUN_00700320(0xfa3, 0);
        m_pTiles[7]->FUN_00700320(0xfa3, 0);
        break;
    }
}

struct SoundHandle75
{
    unsigned unk00;
    bool unk04;
    unsigned unk08;
    ~SoundHandle75();
    bool Play(bool);
};
struct Audio75
{
    SoundHandle75 GetSoundHandleByEditorID(const char*, unsigned);
};
Audio75* BSAudio_QInstance();
struct Item75
{
    void* FUN_0044ddc0();
    int FUN_00726070();
};
extern Item75* g_011d93fc;
extern unsigned char DAT_011a002c;
struct Player75
{
};
extern Player75* _g_thePlayer;
bool __fastcall PlayerCharacter_IsHardcore(Player75*);
bool TESContainer_IsGold(void*);
double FUN_0048ebc0(void*, bool);
struct Setting75
{
    int* Int();
};
extern Setting75 g_011d2418;
void HandleContainerMenuActivate(int);
void CreateQuantityMenu(int, void (*)(int), int);
void ContainerMenu_TakeAllFn(void*, void*);
void ContainerMenu_FilterModeFunc(void*, void*);
void Interface_PlayMenuSound(int);
struct List75
{
    virtual void reset(int);
    void FUN_007312e0();
    void ListBox_ItemChange_Traverse(void (*)(void*, void*), int, int);
    void ApplyFilter(void (*)(void*, void*));
    unsigned ListBox_ItemChange_NumUnfiltered();
};
// Handles container menu activation by ID, cycling item lists or triggering take-all and quantity menu actions.
// @fnv 0x0075be80
void ContainerMenu::HandleSelection(int aiActionId, Tile* tile)
{
    if (!tile && aiActionId >= 0 && aiActionId < 19)
        tile = m_pTiles[aiActionId];
    switch (aiActionId)
    {
    case 20:
        if (g_011d93fc)
        {
            DAT_011a002c = 0;
            bool take = (TESContainer_IsGold(g_011d93fc->FUN_0044ddc0()) ||
                         FUN_0048ebc0(g_011d93fc->FUN_0044ddc0(), PlayerCharacter_IsHardcore(_g_thePlayer)) <= 0.0) &&
                        (m_eContainerMenuMode == 1 || m_eContainerMenuMode == 2) && m_pCurrentList == &m_kSecondItemChangeList;
            if (g_011d93fc->FUN_00726070() > *g_011d2418.Int() && !IsPlacingMine(reinterpret_cast<InventoryEntry*>(g_011d93fc), reinterpret_cast<ExpectedReference*>(_g_thePlayer), reinterpret_cast<ActorView*>(m_pContainer)) &&
                !take)
            {
                reinterpret_cast<List75*>(m_pCurrentList)->FUN_007312e0();
                reinterpret_cast<List75*>(m_pCurrentList)->reset(0);
                CreateQuantityMenu(g_011d93fc->FUN_00726070(), HandleContainerMenuActivate, 0x7fffffff);
            }
            else if (take)
                HandleContainerMenuActivate(g_011d93fc->FUN_00726070());
            else
                HandleContainerMenuActivate(1);
        }
        break;
    case 10:
        reinterpret_cast<List75&>(m_kSecondItemChangeList).ListBox_ItemChange_Traverse(ContainerMenu_TakeAllFn, 0, 0x7fffffff);
        BSAudio_QInstance()->GetSoundHandleByEditorID("UIItemTakeAll", 0x121).Play(false);
        Close();
        break;
    case 11:
        Close();
        break;
    case 0:
    case 1:
    case 2:
        Interface_PlayMenuSound(m_eMenuSounds);
        do
        {
            reinterpret_cast<int&>(m_eFilterMode) += aiActionId == 0 ? -1 : 1;
            if (reinterpret_cast<int&>(m_eFilterMode) < 0)
                reinterpret_cast<int&>(m_eFilterMode) = 5;
            else if (reinterpret_cast<int&>(m_eFilterMode) > 5)
                reinterpret_cast<int&>(m_eFilterMode) = 0;
            UpdatePaneTitle(reinterpret_cast<TileObj*>(m_pTiles[1]));
            reinterpret_cast<List75&>(m_kFirstItemChangeList).ApplyFilter(ContainerMenu_FilterModeFunc);
        } while (!reinterpret_cast<List75&>(m_kFirstItemChangeList).ListBox_ItemChange_NumUnfiltered() && reinterpret_cast<int&>(m_eFilterMode) != 0);
        break;
    case 5:
    case 6:
    case 7:
        Interface_PlayMenuSound(m_eMenuSounds);
        do
        {
            reinterpret_cast<int&>(m_eSecondFilterMode) += aiActionId == 5 ? -1 : 1;
            if (reinterpret_cast<int&>(m_eSecondFilterMode) < 0)
                reinterpret_cast<int&>(m_eSecondFilterMode) = 5;
            else if (reinterpret_cast<int&>(m_eSecondFilterMode) > 5)
                reinterpret_cast<int&>(m_eSecondFilterMode) = 0;
            UpdatePaneTitle(reinterpret_cast<TileObj*>(m_pTiles[6]));
            reinterpret_cast<List75&>(m_kSecondItemChangeList).ApplyFilter(ContainerMenu_FilterModeFunc);
        } while (!reinterpret_cast<List75&>(m_kSecondItemChangeList).ListBox_ItemChange_NumUnfiltered() && reinterpret_cast<int&>(m_eSecondFilterMode) != 0);
        break;
    }
}

struct CategoryNameReference
{
    const char* TESObjectREFR_GetFullName();
};
extern InventoryMenuSetting DAT_011c3cb4;
extern InventoryMenuSetting DAT_011d29b8, DAT_011d4d50, DAT_011d40b4, DAT_011d2acc, DAT_011d4918;
int __cdecl FUN_00406d30(char* buffer, unsigned int length, const char* source);
void __cdecl BSstrupr(char* buffer, int length);
enum CategoryFilter
{
    FILTER_ALL = 0,
    FILTER_1 = 1,
    FILTER_2 = 2,
    FILTER_3 = 3,
    FILTER_4 = 4,
    FILTER_5 = 5
};
// UI invariant: both category values are initialized to0 and their event writers
// wrap every increment/decrement into0..5 before calling this title updater.
// Every valid path that uses title below first initializes the real buffer.
// Sets pane title text from the selected category and calls FUN_00730490 when the setting equals "ENGLISH".
// @fnv 0x0075e380
void ContainerMenu::UpdatePaneTitle(TileObj* pane)
{
    bool nonEnglish;
    CategoryFilter category5 = reinterpret_cast<Tile*>(pane) == m_pTiles[1] ? static_cast<CategoryFilter>(m_eFilterMode) : static_cast<CategoryFilter>(m_eSecondFilterMode);
    nonEnglish = BSstrcmp(DAT_011c3cb4.FUN_00403df0(), "ENGLISH") != 0;
    char title[260];
    if (!m_pContainer || !pane)
        return;
    switch (category5)
    {
    case 0:
        if (reinterpret_cast<Tile*>(pane) == m_pTiles[1])
        {
            FUN_00406d30(title, 260, DAT_011d4378.FUN_00403df0());
            if (!nonEnglish)
                BSstrupr(title, 260);
            reinterpret_cast<Tile*>(pane)->Tile_Set_00a01350(0xfc4, title, true);
        }
        else
        {
            SetLabelText(reinterpret_cast<CategoryNameReference*>(m_pContainer)->TESObjectREFR_GetFullName());
        }
        break;
    case 1:
        FUN_00406d30(title, 260, DAT_011d29b8.FUN_00403df0());
        if (!nonEnglish)
            BSstrupr(title, 260);
        break;
    case 2:
        FUN_00406d30(title, 260, DAT_011d4d50.FUN_00403df0());
        if (!nonEnglish)
            BSstrupr(title, 260);
        break;
    case 3:
        FUN_00406d30(title, 260, DAT_011d40b4.FUN_00403df0());
        if (!nonEnglish)
            BSstrupr(title, 260);
        break;
    case 4:
        FUN_00406d30(title, 260, DAT_011d2acc.FUN_00403df0());
        if (!nonEnglish)
            BSstrupr(title, 260);
        break;
    case 5:
        FUN_00406d30(title, 260, DAT_011d4918.FUN_00403df0());
        if (!nonEnglish)
            BSstrupr(title, 260);
        break;
    }
    if (category5)
        reinterpret_cast<Tile*>(pane)->Tile_Set_00a01350(0xfc4, title, true);
}

namespace fnv_0075c280 {
struct MenuExtra;
struct FUN_00410360
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;

    FUN_00410360();
    void ExtraDataList_SetItemDropper(MenuReference*);
    void FUN_00419970(float);
};
struct FUN_0096a2d0
{
    int unk00, unk04;
    FUN_0096a2d0();
    FUN_00410360** FUN_006815c0();
    void FUN_005ae3d0(FUN_00410360**);
};
struct FUN_004bc550
{
    FUN_0096a2d0* extra;
    int unk04, unk08;
    FUN_004bc550(TESBoundObject*, int);
    const char* GetTargetFullName();
    FUN_0096a2d0* Modelloader_GetReferencedThis();
};
struct MenuInventory
{
    unsigned int FUN_0044ddc0();
    FUN_004bc550** BSSimpleArray_NiAVObject_1024_GetAt(unsigned int);
};
struct MenuProcess
{
    MenuReference* ExtraDataList_GetDroppedWeapon();
};
}  // namespace fnv_0075c280

struct MenuReference
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual bool IsActor();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual bool IsDead(int);
    fnv_0075c280::MenuProcess* BSFile_GetDevice();
    bool TESForm_GetDisabledOrDeleted();
    MenuForm* BGSSaveFormBuffer_GetForm();
    float TESObjectREFR_GetHealth();
    void GetTwoValues(float*, float*);
};
struct MenuForm
{
    int FUN_00401170();
    MenuForm* TESObjectWEAP_GetCurrentAmmo(MenuReference*);
};
namespace fnv_0075c280 {
struct MenuTileValue
{
    void Tile_Set(float, bool);
};
struct MenuTileHolder
{
    MenuTileValue** FUN_007b5370(int);
};
}  // namespace fnv_0075c280

struct MenuEntry
{
    int unk00;
    fnv_0075c280::MenuTileHolder tile;
};
namespace fnv_0075c280 {
struct MenuSetting
{
    const char* FUN_00403df0();
};
extern MenuSetting DAT_011d3f70, DAT_011d1e60;
extern MenuReference* DAT_011dea3c;
extern const char DAT_01012058[], DAT_010722d0[];
extern float DAT_0101e704;
void IsRefBaseObjectUnplayable();
void ContainerMenu_InitFunc();
void ContainerMenu_FilterModeFunc();
void* FUN_004bf220(MenuReference*);
void BSStringT_char_SPrintF(StrMem*, const char*, ...);
int BSsprintf(char*, unsigned int, const char*, ...);
float FUN_004bd510(float, float);
int FloatToInt(float);
bool InterfaceManager_Has360Controller();
struct MenuInput
{
    void InterfaceManager_SetCurrentFocusTarget(void*, int);
};
MenuInput* InterfaceManager_GetSingleton();
struct MenuRoot
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
    int unk28;
    int unk2c;
    int unk30;

    Tile* tile;
};

}  // namespace fnv_0075c280

// Populates m_kList and otherList with inventory items, applies filters and sorting, and updates the active list selection and weight/capacity display.
// @fnv 0x0075c280
// src: XBOX_PDB 0x0075c280
void InventoryMenu::ContainerMenu_UpdateLists(MenuForm* filter)
{
    int unused4 = 0;
    float weight7, capacity4;
    char label5[64];
    if (active && active->GetSelected())
        active->FUN_007312e0();
    if (mode == 4)
    {
        fnv_0075c280::MenuInventory* _inventory = static_cast<fnv_0075c280::MenuInventory*>(
            GetPlayerContainerInventory(reinterpret_cast<PlayerCharacter*>(fnv_0075c280::DAT_011dea3c)));
        otherList.Clear();
        for (unsigned int iA = 0; iA < _inventory->FUN_0044ddc0(); iA++)
            otherList.ListBox_ItemChange_AddItem((InventoryStackRecord*)*_inventory->BSSimpleArray_NiAVObject_1024_GetAt(iA), (*_inventory->BSSimpleArray_NiAVObject_1024_GetAt(iA))->GetTargetFullName(),
                                   0, 0);
        if (filter)
            AttachAndDeliver(filter, fnv_0075c280::FUN_004bf220(fnv_0075c280::DAT_011dea3c), &m_kList);
        else
            m_kList.PopulateInventoryList(fnv_0075c280::DAT_011dea3c, fnv_0075c280::IsRefBaseObjectUnplayable, 0, 0, 0, 0);
    }
    else if (filter)
    {
        void* playerInventory4 = fnv_0075c280::FUN_004bf220(fnv_0075c280::DAT_011dea3c);
        void* otherInventory = container ? fnv_0075c280::FUN_004bf220(container) : 0;
        MenuForm* ammo4 = filter->FUN_00401170() == 40 ? filter->TESObjectWEAP_GetCurrentAmmo(container->IsActor() ? container : 0) : 0;
        AttachAndDeliver(filter, playerInventory4, &m_kList);
        if (ammo4)
            AttachAndDeliver(ammo4, playerInventory4, &m_kList);
        if (mode == 3)
            otherList.PopulateInventoryList(container, fnv_0075c280::IsRefBaseObjectUnplayable, 0, 0, 0, 0);
        else
        {
            AttachAndDeliver(filter, otherInventory, &otherList);
            if (ammo4)
                AttachAndDeliver(ammo4, otherInventory, &otherList);
        }
    }
    else
    {
        m_kList.PopulateInventoryList(fnv_0075c280::DAT_011dea3c, fnv_0075c280::IsRefBaseObjectUnplayable, 0, 0, 0, 0);
        otherList.PopulateInventoryList(container, fnv_0075c280::IsRefBaseObjectUnplayable, 0, 0, 0, 0);
    }
    for (MenuFormList* node9 = &forms; node9 && *node9->FUN_006815c0(); node9 = node9->FUN_00726070())
    {
        if (!filter || filter == *node9->FUN_006815c0())
        {
            fnv_0075c280::FUN_004bc550* entry2 = new fnv_0075c280::FUN_004bc550((TESBoundObject*)*node9->FUN_006815c0(), 1);
            StrMem name;
            MenuEntry* tile2 = 0;
            fnv_0075c280::BSStringT_char_SPrintF(&name, fnv_0075c280::DAT_01012058, fnv_0075c280::DAT_011d3f70.FUN_00403df0(), entry2->GetTargetFullName());
            tile2 = otherList.ListBox_ItemChange_AddItem((InventoryStackRecord*)entry2, name.Modelloader_GetReferencedThis(), 0, 0);
            (*tile2->tile.FUN_007b5370(0xfa9))->Tile_Set(fnv_0075c280::DAT_0101e704, true);
        }
    }
    if (container && container->IsActor() && container->IsDead(0))
    {
        MenuReference* weapon = container->BSFile_GetDevice()->ExtraDataList_GetDroppedWeapon();
        if (weapon && !weapon->TESForm_GetDisabledOrDeleted() && (!filter || filter == weapon->BGSSaveFormBuffer_GetForm()))
        {
            fnv_0075c280::FUN_004bc550* weaponEntry = new fnv_0075c280::FUN_004bc550((TESBoundObject*)weapon->BGSSaveFormBuffer_GetForm(), 1);
            MenuEntry* weaponTile3 = 0;
            weaponTile3 = otherList.ListBox_ItemChange_AddItem((InventoryStackRecord*)weaponEntry, weaponEntry->GetTargetFullName(), 0, 0);
            if (weaponEntry->Modelloader_GetReferencedThis())
                weaponEntry->extra = new fnv_0075c280::FUN_0096a2d0;
            if (!*weaponEntry->Modelloader_GetReferencedThis()->FUN_006815c0())
            {
                fnv_0075c280::FUN_00410360* extra6 = new fnv_0075c280::FUN_00410360;
                weaponEntry->Modelloader_GetReferencedThis()->FUN_005ae3d0(&extra6);
            }
            (*weaponEntry->Modelloader_GetReferencedThis()->FUN_006815c0())->ExtraDataList_SetItemDropper(weapon);
            (*weaponEntry->Modelloader_GetReferencedThis()->FUN_006815c0())->FUN_00419970(weapon->TESObjectREFR_GetHealth());
        }
    }
    m_kList.ListBox_ItemChange_Traverse(fnv_0075c280::ContainerMenu_InitFunc, 0, 0x7fffffff);
    m_kList.ApplyFilter(fnv_0075c280::ContainerMenu_FilterModeFunc);
    m_kList.Sort(ContainerMenu_SortFunc);
    otherList.ListBox_ItemChange_Traverse(fnv_0075c280::ContainerMenu_InitFunc, 0, 0x7fffffff);
    otherList.ApplyFilter(fnv_0075c280::ContainerMenu_FilterModeFunc);
    otherList.Sort(ContainerMenu_SortFunc);
    fnv_0075c280::DAT_011dea3c->GetTwoValues(&weight7, &capacity4);
    fnv_0075c280::BSsprintf(label5, 64, fnv_0075c280::DAT_010722d0, fnv_0075c280::DAT_011d1e60.FUN_00403df0(), fnv_0075c280::FloatToInt(fnv_0075c280::FUN_004bd510(weight7, 1.0f)),
                 fnv_0075c280::FloatToInt(fnv_0075c280::FUN_004bd510(capacity4, 1.0f)));
    ((fnv_0075c280::MenuRoot*)DAT_011d93f8)->tile->Tile_Set_00a01350(0xfc4, label5, true);
    if (!active && fnv_0075c280::InterfaceManager_Has360Controller())
        active = &otherList;
    if (active)
    {
        if (active->ListBox_ItemChange_NumUnfiltered() > 0)
            active->UpdateCurrentValueTile(1);
        else
        {
            selection = -1;
            HandleSelection(active == &m_kList ? 2 : 7, 0);
            selection = 3;
            if (active->ListBox_ItemChange_NumUnfiltered() > 0)
                active->UpdateCurrentValueTile(1);
            else
            {
                HandleMouseover(active == &m_kList ? 22 : 21, 0);
                if (fnv_0075c280::InterfaceManager_Has360Controller())
                    fnv_0075c280::InterfaceManager_GetSingleton()->InterfaceManager_SetCurrentFocusTarget(active->CallVirtualZero(0xfc3), 1);
            }
        }
    }
}


struct ObjRef
{
    TESBoundObject* FUN_0044ddc0();
    void* Modelloader_GetReferencedThis();
    int FUN_004459e0(int a1);
};
struct ObjRaw
{
    int* FUN_006815c0();
};
struct InvChg
{
    ObjRef* FindEntryWithExtraListType(int a1);
    void ClearExtraForSlot(ObjRef* b, int a2);
    void SetInventorySlotExtraData(ObjRef* p, int v, int a3);
};
struct Loader
{
    void ModelLoader_ReleaseFile(char* name);
    void* ModelLoader_LoadFile(char* name, int a1, int a2, int a3, int a4, int a5);
};
extern Loader* DAT_011c3b3c;
InvChg* __cdecl FUN_004bf220(void* arg);
TESModelTextureSwap* __cdecl GetBipedModelTextureSwap(TESBoundObject* o, void* player);

struct ThiS
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    unsigned char f24;
    int f28;
    void HotKeysWheel_UpdateHotkeyList();
    void HotKeysWheel_SetHotkeyItem(ObjRef* p1);
};

// Calls inventory change routines, passes texture swap names to loader routines, updates a player object, and clears a field.
// @fnv 0x007019e0
// src: XBOX_PDB 0x007019e0
void ThiS::HotKeysWheel_SetHotkeyItem(ObjRef* apObjRef)
{
    InvChg* aX = FUN_004bf220(DAT_011dea3c);
    if (!(apObjRef != 0 && f24 != 0 && aX != 0))
        return;
    ObjRef* b = aX->FindEntryWithExtraListType(f28);
    int v4 = apObjRef->Modelloader_GetReferencedThis() ? *(int*)((ObjRaw*)apObjRef->Modelloader_GetReferencedThis())->FUN_006815c0() : 0;
    TESModelTextureSwap* c_;
    TESModelTextureSwap* d;
    if (b != 0)
    {
        aX->ClearExtraForSlot(b, f28);
        if (b->FUN_0044ddc0() != 0)
        {
            c_ = GetBipedModelTextureSwap(b->FUN_0044ddc0(), DAT_011dea3c);
            if (c_ == 0)
                c_ = dynamic_cast<TESModelTextureSwap*>(b->FUN_0044ddc0());
            if (c_ != 0)
                DAT_011c3b3c->ModelLoader_ReleaseFile(const_cast<char*>(c_->GetModelFilePath()));
        }
    }
    aX->SetInventorySlotExtraData(apObjRef, v4, f28);
    if (apObjRef->FUN_0044ddc0() != 0)
    {
        d = GetBipedModelTextureSwap(apObjRef->FUN_0044ddc0(), DAT_011dea3c);
        if (d == 0)
            d = dynamic_cast<TESModelTextureSwap*>(apObjRef->FUN_0044ddc0());
        if (d != 0)
            DAT_011c3b3c->ModelLoader_LoadFile(const_cast<char*>(d->GetModelFilePath()), 0, 1, 0, 0, 0);
    }
    HotKeysWheel_UpdateHotkeyList();
    ((PlayerObj_containermenu*)DAT_011dea3c)->PlayActorSound(apObjRef->FUN_0044ddc0(), 1, 0);
    f24 = 0;
    ObjRef* aRef = b;
    ObjRef* aCopyP = aRef;
    (void)(aCopyP ? aCopyP->FUN_004459e0(1) : 0);
}

void __cdecl _FUN_00755270(int);

struct CompanionWheelInventory : Menu
{
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    TESObjectREFR* pCompanion;

    void PlayTopicResponse(TESTopic*);
    void RunTopicResultScripts(TESTopic*);
    void CompanionWheelMenu_Do_OpenInventory();
};
// Looks up the FollowersTrade topic and, when pCompanion is non-null, passes it to FUN_007573d0 and FUN_007575b0.
// @fnv 0x007568d0
// src: XBOX_PDB 0x007568d0
void CompanionWheelInventory::CompanionWheelMenu_Do_OpenInventory()
{
    _FUN_00755270(1);
    TESTopic* topic = dynamic_cast<TESTopic*>(FUN_00483a00("FollowersTrade"));
    if (pCompanion != 0)
    {
        PlayTopicResponse(topic);
        RunTopicResultScripts(topic);
    }
}
