// src/fallout/ai/playercharacter_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (MagicItem, SpellItem). Unused skeleton declarations have been removed so this unit can use
// the shared include/ definitions; move the functions to their real unit once its classes are polymorphic.


#include "../../../include/ActorMover.h"
#include "../../../include/ArrowProjectile.h"
#include "../../../include/AutoMemContext.h"
#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/BGSPerk.h"
#include "../../../include/BGSSaveLoadGame.h"
#include "../../../include/BGSSaveLoadManager.h"
#include "../../../include/BSSoundHandle.h"
#include "../../../include/BaseProcess.h"
#include "../../../include/DialoguePackage.h"
#include "../../../include/GO.h"
#include "../../../include/HUDMainMenu.h"
#include "../../../include/ShadowSceneLight.h"
#include "../../../include/ImageSpaceModifierInstance.h"
#include "../../../include/InventoryChanges.h"
#include "../../../include/InventoryStackRecord.h"
#include "../../../include/MagicItem.h"
#include "../../../include/MagicProjectile.h"
#include "../../../include/MagicTarget.h"
#include "../../../include/NiBound.h"
#include "../../../include/NiPoint2.h"
#include "../../../include/PathingLocation.h"
#include "../../../include/PathingSolution.h"
#include "../../../include/PerkData.h"
#include "../../../include/PlayerCharacter.h"
union SETTING_VALUE;
#include "../../../include/SettingT_GameSettingCollection_.h"
#include "../../../include/SkyObject.h"
#include "../../../include/SpellItem.h"
#include "../../../include/TESChallenge.h"
#include "../../../include/TESClass.h"
#include "../../../include/TESPackage.h"
#include "../../../include/TESQuest.h"
#include "../../../include/TESRegion.h"
#include "../../../include/TESTopic.h"
#include "../../../include/TESWeather.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/bhkCollisionObject.h"

// Only the declarations used by this RTTI variant and its existing helper bodies remain.

struct IRExtraNode;
struct IRForm;

struct IRExtraList
{
    virtual ~IRExtraList();
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;

    IRExtraList();
    void CopyFrom(IRExtraList* apOther);
    short GetCount();
    void SetCount(unsigned short ausCount);
};

struct IRFormStack
{
    IRExtraNode* pExtendData;
    int iCount;
    IRForm* pType;

    IRFormStack(IRForm* apType, int aiCount);
    IRExtraNode* GetExtendData();
    int GetCount();
    void SetCount(int aiCount);
    IRForm* GetType();
};

struct IREntryArray
{
    unsigned int GetSize();
    IRFormStack*& GetAt(unsigned int auiIndex);
    void Remove(unsigned int auiIndex, bool abShrink);
};

struct IRContainer
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
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    int unk5CC;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    int unk5E0;
    int unk5E4;
    int unk5E8;
    int unk5EC;
    int unk5F0;
    int unk5F4;
    int unk5F8;
    int unk5FC;
    int unk600;
    int unk604;
    int unk608;
    int unk60C;
    int unk610;
    int unk614;
    int unk618;
    int unk61C;
    int unk620;
    int unk624;
    int unk628;
    int unk62C;
    int unk630;
    int unk634;
    int unk638;
    int unk63C;
    int unk640;
    int unk644;
    int unk648;
    int unk64C;
    int unk650;
    int unk654;
    int unk658;
    int unk65C;
    int unk660;
    int unk664;
    int unk668;
    int unk66C;
    int unk670;
    int unk674;
    int unk678;
    int unk67C;
    int unk680;
    int unk684;
    int unk688;
    int unk68C;
    int unk690;
    int unk694;
    int unk698;
    int unk69C;
    int unk6A0;
    int unk6A4;
    int unk6A8;
    int unk6AC;
    int unk6B0;
    int unk6B4;
    int unk6B8;
    int unk6BC;
    int unk6C0;
    int unk6C4;
    int unk6C8;
    int unk6CC;
    int unk6D0;
    int unk6D4;
    int unk6D8;
    int unk6DC;
    int unk6E0;
    int unk6E4;
    int unk6E8;
    int unk6EC;
    int unk6F0;
    int unk6F4;
    int unk6F8;
    int unk6FC;
    int unk700;
    int unk704;
    int unk708;
    int unk70C;
    int unk710;
    int unk714;
    int unk718;
    int unk71C;
    int unk720;
    int unk724;
    int unk728;
    int unk72C;
    int unk730;
    int unk734;
    int unk738;
    int unk73C;
    int unk740;
    int unk744;
    int unk748;
    int unk74C;
    int unk750;
    int unk754;
    int unk758;
    int unk75C;
    int unk760;
    int unk764;
    int unk768;
    int unk76C;
    int unk770;
    int unk774;
    int unk778;
    int unk77C;
    int unk780;
    int unk784;
    int unk788;
    int unk78C;
    int unk790;
    int unk794;
    int unk798;
    int unk79C;
    int unk7A0;
    int unk7A4;
    int unk7A8;
    int unk7AC;
    int unk7B0;
    int unk7B4;
    int unk7B8;
    int unk7BC;
    int unk7C0;
    int unk7C4;
    int unk7C8;
    int unk7CC;
    int unk7D0;
    int unk7D4;
    int unk7D8;
    int unk7DC;
    int unk7E0;
    int unk7E4;
    int unk7E8;
    int unk7EC;
    int unk7F0;
    int unk7F4;
    int unk7F8;
    int unk7FC;
    int unk800;
    int unk804;
    int unk808;
    int unk80C;
    int unk810;
    int unk814;
    int unk818;
    int unk81C;
    int unk820;
    int unk824;
    int unk828;
    int unk82C;
    int unk830;
    int unk834;
    int unk838;
    int unk83C;
    int unk840;
    int unk844;
    int unk848;
    int unk84C;
    int unk850;
    int unk854;
    int unk858;
    int unk85C;
    int unk860;
    int unk864;
    int unk868;
    int unk86C;
    int unk870;
    int unk874;
    int unk878;
    int unk87C;
    int unk880;
    int unk884;
    int unk888;
    int unk88C;
    int unk890;
    int unk894;
    int unk898;
    int unk89C;
    int unk8A0;
    int unk8A4;
    int unk8A8;
    int unk8AC;
    int unk8B0;
    int unk8B4;
    int unk8B8;
    int unk8BC;
    int unk8C0;
    int unk8C4;
    int unk8C8;
    int unk8CC;
    int unk8D0;
    int unk8D4;
    int unk8D8;
    int unk8DC;
    int unk8E0;
    int unk8E4;
    int unk8E8;
    int unk8EC;
    int unk8F0;
    int unk8F4;
    int unk8F8;
    int unk8FC;
    int unk900;
    int unk904;
    int unk908;
    int unk90C;
    int unk910;
    int unk914;
    int unk918;
    int unk91C;
    int unk920;
    int unk924;
    int unk928;
    int unk92C;
    int unk930;
    int unk934;
    int unk938;
    int unk93C;
    int unk940;
    int unk944;
    int unk948;
    int unk94C;
    int unk950;
    int unk954;
    int unk958;
    int unk95C;
    int unk960;
    int unk964;
    int unk968;
    int unk96C;
    int unk970;
    int unk974;
    int unk978;
    int unk97C;
    int unk980;
    int unk984;
    int unk988;
    int unk98C;
    int unk990;
    int unk994;
    int unk998;
    int unk99C;
    int unk9A0;
    int unk9A4;
    int unk9A8;
    int unk9AC;
    int unk9B0;
    int unk9B4;
    int unk9B8;
    int unk9BC;
    int unk9C0;
    int unk9C4;
    int unk9C8;
    int unk9CC;
    int unk9D0;
    int unk9D4;
    int unk9D8;
    int unk9DC;
    int unk9E0;
    int unk9E4;
    int unk9E8;
    int unk9EC;
    int unk9F0;
    int unk9F4;
    int unk9F8;
    int unk9FC;
    int unkA00;
    int unkA04;
    int unkA08;
    int unkA0C;
    int unkA10;
    int unkA14;
    int unkA18;
    int unkA1C;
    int unkA20;
    int unkA24;
    int unkA28;
    int unkA2C;
    int unkA30;
    int unkA34;
    int unkA38;
    int unkA3C;
    int unkA40;
    int unkA44;
    int unkA48;
    int unkA4C;
    int unkA50;
    int unkA54;
    int unkA58;
    int unkA5C;
    int unkA60;
    int unkA64;
    int unkA68;
    int unkA6C;
    int unkA70;
    int unkA74;
    int unkA78;
    int unkA7C;
    int unkA80;
    int unkA84;
    int unkA88;
    int unkA8C;
    int unkA90;
    int unkA94;
    int unkA98;
    int unkA9C;
    int unkAA0;
    int unkAA4;
    int unkAA8;
    int unkAAC;
    int unkAB0;
    int unkAB4;
    int unkAB8;
    int unkABC;
    int unkAC0;
    int unkAC4;
    int unkAC8;
    int unkACC;
    int unkAD0;
    int unkAD4;
    int unkAD8;
    int unkADC;
    int unkAE0;
    int unkAE4;
    int unkAE8;
    int unkAEC;
    int unkAF0;
    int unkAF4;
    int unkAF8;
    int unkAFC;
    int unkB00;
    int unkB04;
    int unkB08;
    int unkB0C;
    int unkB10;
    int unkB14;
    int unkB18;
    int unkB1C;
    int unkB20;
    int unkB24;
    int unkB28;
    int unkB2C;
    int unkB30;
    int unkB34;
    int unkB38;
    int unkB3C;
    int unkB40;
    int unkB44;
    int unkB48;
    int unkB4C;
    int unkB50;
    int unkB54;
    int unkB58;
    int unkB5C;
    int unkB60;
    int unkB64;
    int unkB68;
    int unkB6C;
    int unkB70;
    int unkB74;
    int unkB78;
    int unkB7C;
    int unkB80;
    int unkB84;
    int unkB88;
    int unkB8C;
    int unkB90;
    int unkB94;
    int unkB98;
    int unkB9C;
    int unkBA0;
    int unkBA4;
    int unkBA8;
    int unkBAC;
    int unkBB0;
    int unkBB4;
    int unkBB8;
    int unkBBC;
    int unkBC0;
    int unkBC4;
    int unkBC8;
    int unkBCC;
    int unkBD0;
    int unkBD4;
    int unkBD8;
    int unkBDC;
    int unkBE0;
    int unkBE4;
    int unkBE8;
    int unkBEC;
    int unkBF0;
    int unkBF4;
    int unkBF8;
    int unkBFC;
    int unkC00;
    int unkC04;
    int unkC08;
    int unkC0C;
    int unkC10;
    int unkC14;
    int unkC18;
    int unkC1C;
    int unkC20;
    int unkC24;
    int unkC28;
    int unkC2C;
    int unkC30;
    int unkC34;
    int unkC38;
    int unkC3C;
    int unkC40;
    int unkC44;
    int unkC48;
    int unkC4C;
    int unkC50;
    int unkC54;
    int unkC58;
    int unkC5C;
    int unkC60;
    int unkC64;
    int unkC68;
    int unkC6C;
    int unkC70;
    int unkC74;
    int unkC78;
    int unkC7C;
    int unkC80;
    int unkC84;
    int unkC88;
    int unkC8C;
    int unkC90;
    int unkC94;
    int unkC98;
    int unkC9C;
    int unkCA0;
    int unkCA4;
    int unkCA8;
    int unkCAC;
    int unkCB0;
    int unkCB4;
    int unkCB8;
    int unkCBC;
    int unkCC0;
    int unkCC4;
    int unkCC8;
    int unkCCC;
    int unkCD0;
    int unkCD4;
    int unkCD8;
    int unkCDC;
    int unkCE0;
    int unkCE4;
    int unkCE8;
    int unkCEC;
    int unkCF0;
    int unkCF4;
    int unkCF8;
    int unkCFC;
    int unkD00;
    int unkD04;
    int unkD08;
    int unkD0C;
    int unkD10;
    int unkD14;
    int unkD18;
    int unkD1C;
    int unkD20;
    int unkD24;
    int unkD28;
    int unkD2C;
    int unkD30;
    int unkD34;
    int unkD38;
    int unkD3C;
    int unkD40;
    int unkD44;
    int unkD48;
    int unkD4C;
    int unkD50;
    int unkD54;
    int unkD58;
    int unkD5C;
    int unkD60;
    int unkD64;
    int unkD68;
    int unkD6C;
    int unkD70;
    int unkD74;
    int unkD78;
    int unkD7C;
    int unkD80;
    int unkD84;
    int unkD88;
    int unkD8C;
    int unkD90;
    int unkD94;
    int unkD98;
    int unkD9C;
    int unkDA0;
    int unkDA4;
    int unkDA8;
    int unkDAC;
    int unkDB0;
    int unkDB4;
    int unkDB8;
    int unkDBC;
    int unkDC0;
    int unkDC4;
    int unkDC8;
    int unkDCC;
    int unkDD0;
    int unkDD4;
    int unkDD8;
    int unkDDC;
    int unkDE0;
    int unkDE4;
    int unkDE8;
    int unkDEC;
    int unkDF0;
    IREntryArray kEntries;
    int unkDF8;
    int unkDFC;
    int unkE00;
    float fWeight;

    bool IsHardcore();
    IRFormStack* PlayerCharacter_RemoveRockItAmmo(IRForm* apItem, IRExtraList* apExtra, int aiCount, bool abReturnEntry);
};

namespace RockItAmmoCountDetail {
struct ItemCountView
{
    int FUN_00726070();
};

struct EntryArrayView
{
    unsigned int FUN_0044ddc0();
    ItemCountView*& FUN_00877a30(unsigned int index);
};

struct PlayerView : IRContainer
{
    int PlayerCharacter_GetNumRockItAmmo();
};

// @fnv 0x00969040
// src: XBOX_PDB 0x00969040
int PlayerView::PlayerCharacter_GetNumRockItAmmo()
{
    int iitemCt = 0;
    int iammoCt = 0;
    for (; iammoCt < reinterpret_cast<EntryArrayView*>(&kEntries)->FUN_0044ddc0(); ++iammoCt)
    {
        iitemCt += reinterpret_cast<EntryArrayView*>(&kEntries)->FUN_00877a30(iammoCt)->FUN_00726070();
    }
    return iitemCt;
}
}

struct Save451;
extern Save451* g_TESSaveLoadGame;
struct Data451;
extern Data451* g_dataHandler;
void FNV_Warning(const char* fmt, ...);
TESForm* TESForm_GetFormByNumericID(unsigned int id);
struct GlobalObject2_0096a2d0;
extern GlobalObject2_0096a2d0 g_011e0ae8;

struct SaveStream
{
    unsigned char* FUN_00825c00();
    bool TESSaveLoadGame_UseSaveGameBlocks();
    void TESSaveLoadGame_SaveGameDataOLD(void*, int);
    unsigned char FUN_008df040();
};

struct SaveOption
{
    bool* Bool();
};
extern SaveOption g_011de4e8;
struct FormRecord;
// Exe 0x00955620: unit-local ListNode view; declarations and layout are preserved.
struct PlayercharacterListNodeView
{
    FormRecord* data;
    PlayercharacterListNodeView* next;
    bool FUN_008256d0();
    FormRecord** FUN_006815c0();
    PlayercharacterListNodeView* FUN_00726070();
    int GetSize();
};

struct FormRecord
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short unk08;
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    unsigned int FUN_0040a1e0();
    unsigned int RefreshItem();
    FormRecord* TESObjectREFR_GetWorldSpace();
    FormRecord* FUN_008d6f30();
    FormRecord* FUN_0059bb30();
    FormRecord* FUN_005e3fa0();
    bool BGSBodyPart_GetToHitChance();
    PlayercharacterListNodeView* BSFile_GetDevice();
    FormRecord* FindItemByDoneFlag(bool);
    bool TESTextureList_GetTextureCount();
    FormRecord* TESMain_GetThread();
    unsigned int FUN_00726070();
    FormRecord* FUN_00502430();
    void TESClass_SaveGameTES();
    void SerializeFaceGenData(void*);
};

struct SaveMap
{
    unsigned int count;
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    void* GetFirstPos();
    void GetNextEntry(void*&, unsigned int&, unsigned char&);
};
struct SaveSubobject
{
    void SaveValueAndFollowingBytes(unsigned int);
};
struct SaveReference
{
    unsigned int formID;
    unsigned char unk04;
    unsigned char detail0;
    unsigned char detail1;
    unsigned char detail2;
    unsigned char detail3;
};
struct StreamView
{
    SaveReference* GetHitSound();
};
void __cdecl SaveLog(const char*, ...);
void __cdecl Animation_SaveAnimation(void*, unsigned int);
void __cdecl CopyEntrySecondFields(void*);
void __cdecl ActiveEffect_SaveActiveEffectList(FormRecord*, void*);
extern unsigned int g_011e0b5c;
extern FormRecord* g_011e0784;
extern FormRecord* g_011e078c;

struct IntegerOption
{
    int* Int();
};
extern IntegerOption g_011d0a9c;
struct DataLookup
{
    FormRecord* GetTESClassByID(int);
};

extern "C" unsigned int __cdecl strlen(const char*);
struct PositionSource
{

    virtual void Unknown0();
    virtual void Unknown1();
    virtual void Unknown2();
    virtual void Unknown3();
    virtual void Unknown4();
    virtual void Unknown5();
    virtual void Unknown6();
    virtual void Unknown7();
    virtual void Unknown8();
    virtual void Unknown9();
    virtual void Unknown10();
    virtual void Unknown11();
    virtual void Unknown12();
    virtual void Unknown13();
    virtual void Unknown14();
    virtual void Unknown15();
    virtual void Unknown16();
    virtual void Unknown17();
    virtual void Unknown18();
    virtual void Unknown19();
    virtual void Unknown20();
    virtual void Unknown21();
    virtual void Unknown22();
    virtual void Unknown23();
    virtual void Unknown24();
    virtual void Unknown25();
    virtual void Unknown26();
    virtual void Unknown27();
    virtual void Unknown28();
    virtual void Unknown29();
    virtual void Unknown30();
    virtual void Unknown31();
    virtual void Unknown32();
    virtual void Unknown33();
    virtual void Unknown34();
    virtual void Unknown35();
    virtual void Unknown36();
    virtual void Unknown37();
    virtual void Unknown38();
    virtual void Unknown39();
    virtual void Unknown40();
    virtual void Unknown41();
    virtual void Unknown42();
    virtual void Unknown43();
    virtual void Unknown44();
    virtual void Unknown45();
    virtual void Unknown46();
    virtual void Unknown47();
    virtual void Unknown48();
    virtual void Unknown49();
    virtual void Unknown50();
    virtual void Unknown51();
    virtual void Unknown52();
    virtual void Unknown53();
    virtual void Unknown54();
    virtual void Unknown55();
    virtual void Unknown56();
    virtual void Unknown57();
    virtual void Unknown58();
    virtual void Unknown59();
    virtual void Unknown60();
    virtual void Unknown61();
    virtual void Unknown62();
    virtual void Unknown63();
    virtual void Unknown64();
    virtual void Unknown65();
    virtual void Unknown66();
    virtual void Unknown67();
    virtual void Unknown68();
    virtual void Unknown69();
    virtual void Unknown70();
    virtual void Unknown71();
    virtual void Unknown72();
    virtual void Unknown73();
    virtual void Unknown74();
    virtual void Unknown75();
    virtual void Unknown76();
    virtual void Unknown77();
    virtual void Unknown78();
    virtual void Unknown79();
    virtual void Unknown80();
    virtual void Unknown81();
    virtual void Unknown82();
    virtual void Unknown83();
    virtual void Unknown84();
    virtual void Unknown85();
    virtual void Unknown86();
    virtual void Unknown87();
    virtual void Unknown88();
    virtual void Unknown89();
    virtual void Unknown90();
    virtual void Unknown91();
    virtual void Unknown92();
    virtual void Unknown93();
    virtual void Unknown94();
    virtual void Unknown95();
    virtual void Unknown96();
    virtual void Unknown97();
    virtual void Unknown98();
    virtual void Unknown99();
    virtual void Unknown100();
    virtual void Unknown101();
    virtual void Unknown102();
    virtual void Unknown103();
    virtual void Unknown104();
    virtual void Unknown105();
    virtual void Unknown106();
    virtual void Unknown107();
    virtual void Unknown108();
    virtual void Unknown109();
    virtual void Unknown110();
    virtual void Unknown111();
    virtual void Unknown112();
    virtual void Unknown113();
    virtual void Unknown114();
    virtual void Unknown115();
    virtual void Unknown116();
    virtual void Unknown117();
    virtual void Unknown118();
    virtual void Unknown119();
    virtual void Unknown120();
    virtual void Unknown121();
    virtual void Unknown122();
    virtual void Unknown123();
    virtual void Unknown124();
    virtual const NiPoint3& GetPosition();
};
struct PlayerSave
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    FormRecord* unk208;
    unsigned int unk20c;
    FormRecord* unk210;
    FormRecord* unk214;
    FormRecord* unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned char unk240;
    unsigned char unk241;
    unsigned char unk242;
    unsigned char unk243;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    FormRecord* unk604;
    unsigned int unk608;
    unsigned int unk60c;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61c;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62c;
    unsigned int unk630;
    unsigned int unk634;
    FormRecord* unk638;
    unsigned int unk63c;
    unsigned int unk640;
    unsigned int unk644;
    unsigned char unk648;
    unsigned char unk649;
    unsigned char unk64a;
    unsigned char unk64b;
    unsigned char unk64c;
    unsigned char unk64d;
    unsigned char unk64e;
    unsigned char unk64f;
    unsigned char unk650;
    unsigned char unk651;
    unsigned char unk652;
    unsigned char unk653;
    unsigned int unk654;
    unsigned char unk658;
    unsigned char unk659;
    unsigned char unk65a;
    unsigned char unk65b;
    unsigned int unk65c;
    unsigned int unk660;
    unsigned int unk664;
    unsigned int unk668;
    unsigned char unk66c;
    unsigned char unk66d;
    unsigned char unk66e;
    unsigned char unk66f;
    unsigned int unk670;
    unsigned int unk674;
    unsigned int unk678;
    unsigned int unk67c;
    unsigned char unk680;
    unsigned char unk681;
    unsigned char unk682;
    unsigned char unk683;
    unsigned int unk684;
    unsigned int unk688;
    unsigned int unk68c;
    unsigned int unk690;
    unsigned int unk694;
    unsigned int unk698;
    unsigned int unk69c;
    unsigned int unk6a0;
    unsigned int unk6a4;
    unsigned int unk6a8;
    unsigned int unk6ac;
    PlayercharacterListNodeView unk6b0;
    FormRecord* unk6b8;
    PlayercharacterListNodeView unk6bc;
    unsigned int unk6c4;
    unsigned int unk6c8;
    unsigned char unk6cc;
    unsigned char unk6cd;
    unsigned char unk6ce;
    unsigned char unk6cf;
    unsigned int unk6d0;
    unsigned int unk6d4;
    unsigned char unk6d8;
    unsigned char unk6d9;
    unsigned char unk6da;
    unsigned char unk6db;
    unsigned int unk6dc;
    unsigned int unk6e0;
    unsigned int unk6e4;
    unsigned char unk6e8;
    unsigned char unk6e9;
    unsigned char unk6ea;
    unsigned char unk6eb;
    MagicItem* unk6ec;
    FormRecord* unk6f0;
    PositionSource* unk6f4;
    unsigned int unk6f8;
    unsigned int unk6fc;
    unsigned int unk700;
    unsigned int unk704;
    unsigned int unk708;
    unsigned int unk70c;
    unsigned int unk710;
    unsigned int unk714;
    unsigned int unk718;
    unsigned int unk71c;
    unsigned int unk720;
    unsigned int unk724;
    unsigned int unk728;
    unsigned int unk72c;
    unsigned int unk730;
    unsigned int unk734;
    unsigned int unk738;
    FormRecord* unk73c;
    FormRecord* unk740;
    unsigned int unk744;
    unsigned int unk748;
    unsigned int unk74c;
    unsigned int unk750;
    unsigned int unk754;
    unsigned int unk758;
    unsigned char unk75c;
    unsigned char unk75d;
    unsigned char unk75e;
    unsigned char unk75f;
    FormRecord* unk760;
    unsigned int unk764;
    unsigned int unk768;
    unsigned int unk76c;
    unsigned int unk770;
    unsigned int unk774;
    unsigned int unk778;
    unsigned int unk77c;
    unsigned int unk780;
    unsigned int unk784;
    unsigned int unk788;
    unsigned int unk78c;
    unsigned int unk790;
    unsigned int unk794;
    unsigned int unk798;
    unsigned int unk79c;
    unsigned int unk7a0;
    unsigned int unk7a4;
    unsigned int unk7a8;
    FormRecord* unk7ac;
    unsigned int unk7b0;
    unsigned int unk7b4;
    unsigned int unk7b8;
    unsigned int unk7bc;
    unsigned int unk7c0;
    unsigned char unk7c4;
    unsigned char unk7c5;
    unsigned char unk7c6;
    unsigned char unk7c7;
    unsigned int unk7c8;
    unsigned int unk7cc;
    unsigned int unk7d0;
    unsigned int unk7d4;
    unsigned int unk7d8;
    unsigned int unk7dc;
    unsigned int unk7e0;
    unsigned int unk7e4;
    unsigned int unk7e8;
    unsigned int unk7ec;
    unsigned int unk7f0;
    unsigned int unk7f4;
    unsigned int unk7f8;
    unsigned int unk7fc;
    unsigned int unk800;
    unsigned int unk804;
    unsigned int unk808;
    unsigned int unk80c;
    unsigned int unk810;
    unsigned int unk814;
    unsigned int unk818;
    unsigned int unk81c;
    unsigned int unk820;
    unsigned int unk824;
    unsigned int unk828;
    unsigned int unk82c;
    unsigned int unk830;
    unsigned int unk834;
    unsigned int unk838;
    unsigned int unk83c;
    unsigned int unk840;
    unsigned int unk844;
    unsigned int unk848;
    unsigned int unk84c;
    unsigned int unk850;
    SaveMap unk854;
    unsigned int unk858;
    unsigned int unk85c;
    unsigned int unk860;
    unsigned int unk864;
    unsigned int unk868;
    unsigned int unk86c;
    unsigned int unk870;
    unsigned int unk874;
    SaveSubobject unk878;
    void TESForm_SaveGameDataOLD(void*, int);
    void ForwardToSaveLoadGame(void*, int);
    void Character_SaveGame(unsigned int);
    bool Actor_GetIronSights();
    PlayercharacterListNodeView* PlayerCharacter_GetCasinoDataList();
    PlayercharacterListNodeView* GetField614();
    PlayercharacterListNodeView* GetField618();
    PlayercharacterListNodeView* GetSelfOffset6A8();
    FormRecord* BGSSaveFormBuffer_GetForm();
    const char* TESObjectREFR_GetFullName();
    FormRecord* FUN_004181e0();
    void PlayerCharacter_SaveGame(unsigned int flags);
};

// Original read-only string addresses, independent of MSVC literal numbering.
namespace PlayerSaveStrings
{
    enum
    {
        kSaveFormLog = 0x010153a0,
        kSaveLog = 0x0101536c,
        kOversizedBlockLog = 0x01015318,
        kPlayerSourcePath = 0x0108a8e0
    };
}

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
#pragma intrinsic(memcpy)

// @fnv 0x00955620
// src: XBOX_PDB 0x00955620
void PlayerSave::PlayerCharacter_SaveGame(unsigned int flags)
{
    {
        unsigned short blockSize3 = 0;
        unsigned char* blockStart9 = 0;
        unsigned char* initialPosition3 = reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_00825c00();
        if (*g_011de4e8.Bool())
            initialPosition3 = reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_00825c00();
        if (reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->TESSaveLoadGame_UseSaveGameBlocks())
        {
            unsigned int marker = 0x424c4f4b;
            reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->TESSaveLoadGame_SaveGameDataOLD(&marker, 4);
            blockStart9 = reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_00825c00();
            reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->TESSaveLoadGame_SaveGameDataOLD(&blockSize3, 2);
        }
        TESForm_SaveGameDataOLD(&unk244, 0x134);
        TESForm_SaveGameDataOLD(&unk378, 0x134);
        if (reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_008df040() >= 0x31)
            TESForm_SaveGameDataOLD(&unk4b0, 0x134);
        TESForm_SaveGameDataOLD(&unk4ac, 4);
        if (*g_011de4e8.Bool())
        {
            unsigned char* endPosition4 = reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_00825c00();
            SaveReference* reference = ((StreamView*)g_TESSaveLoadGame)->GetHitSound();
            if (reference)
            {
                TESForm* form = TESForm_GetFormByNumericID(reference->formID);
                SaveLog(reinterpret_cast<const char*>(PlayerSaveStrings::kSaveFormLog),
                        endPosition4 - initialPosition3, reference->formID, form->GetName(),
                        *(unsigned int*)&reference->detail0, 0x3378,
                        reinterpret_cast<const char*>(PlayerSaveStrings::kPlayerSourcePath));
            }
            else
                SaveLog(reinterpret_cast<const char*>(PlayerSaveStrings::kSaveLog), endPosition4 - initialPosition3, 0x3378,
                        reinterpret_cast<const char*>(PlayerSaveStrings::kPlayerSourcePath));
        }
        if (reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->TESSaveLoadGame_UseSaveGameBlocks())
        {
            unsigned char* endPositionA = reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_00825c00();
            unsigned char* sizePosition = blockStart9;
            if (endPositionA > sizePosition + 0xffff)
                FNV_Warning(reinterpret_cast<const char*>(PlayerSaveStrings::kOversizedBlockLog),
                            reinterpret_cast<const char*>(PlayerSaveStrings::kPlayerSourcePath), 0x3378);
            *(unsigned short*)blockStart9 = (unsigned short)(endPositionA - sizePosition);
        }
    }
    Character_SaveGame(flags);
    {
        unsigned short blockSize3 = 0;
        unsigned char* blockStart9 = 0;
        unsigned char* initialPosition3 = reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_00825c00();
        if (*g_011de4e8.Bool())
            initialPosition3 = reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_00825c00();
        if (reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->TESSaveLoadGame_UseSaveGameBlocks())
        {
            unsigned int marker2 = 0x424c4f4b;
            reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->TESSaveLoadGame_SaveGameDataOLD(&marker2, 4);
            blockStart9 = reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_00825c00();
            reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->TESSaveLoadGame_SaveGameDataOLD(&blockSize3, 2);
        }
        {
            if (flags & 0x10000000)
                Animation_SaveAnimation(this, unk690);
            // Serialize the original raw vector copy without calling the shared NiPoint3 copy constructor.
            // 0x011f426c is NiPoint3_ZERO; its old binding uses a struct tag, while the shared type uses class.
            unsigned int position[3];
            memcpy(position, &(unk6f4 ? unk6f4->GetPosition() : *reinterpret_cast<const NiPoint3*>(0x011f426c)), 12);
            TESForm_SaveGameDataOLD(&unk64a, 1);
            TESForm_SaveGameDataOLD(&unk64d, 1);
            TESForm_SaveGameDataOLD(&unk651, 1);
            TESForm_SaveGameDataOLD(&unk652, 1);
            TESForm_SaveGameDataOLD(&unk654, 4);
            TESForm_SaveGameDataOLD(&unk660, 4);
            TESForm_SaveGameDataOLD(&unk664, 4);
            TESForm_SaveGameDataOLD(&unk668, 4);
            TESForm_SaveGameDataOLD(&unk66c, 1);
            TESForm_SaveGameDataOLD(&unk6cc, 1);
            TESForm_SaveGameDataOLD(&unk6d0, 4);
            TESForm_SaveGameDataOLD(&unk6d4, 4);
            TESForm_SaveGameDataOLD(&unk6d8, 1);
            TESForm_SaveGameDataOLD(&unk6dc, 4);
            TESForm_SaveGameDataOLD(&unk6e8, 1);
            TESForm_SaveGameDataOLD(&unk6e4, 4);
            TESForm_SaveGameDataOLD(&position, 12);
            TESForm_SaveGameDataOLD(&unk698, 4);
            TESForm_SaveGameDataOLD(&unk67c, 4);
            TESForm_SaveGameDataOLD(&unk734, 4);
            reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->TESSaveLoadGame_SaveGameDataOLD(&unk738, 4);
            TESForm_SaveGameDataOLD(&unk658, 1);
            TESForm_SaveGameDataOLD(&unk65c, 4);
            TESForm_SaveGameDataOLD(&unk75c, 1);
            TESForm_SaveGameDataOLD(&unk75e, 1);
            TESForm_SaveGameDataOLD(&unk730, 4);
            TESForm_SaveGameDataOLD(&unk790, 4);
            TESForm_SaveGameDataOLD(&unk680, 1);
            if (reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_008df040() >= 0x28 &&
                reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_008df040() < 0x2d)
            {
                TESForm_SaveGameDataOLD(&unk7a0, 12);
                TESForm_SaveGameDataOLD(&unk7a0, 12);
            }
            if (reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_008df040() >= 0x39)
            {
                unsigned int statistics[43];
                CopyEntrySecondFields(statistics);
                TESForm_SaveGameDataOLD(statistics, 0xac);
                TESForm_SaveGameDataOLD(&unk744, 0x14);
            }
            if (reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_008df040() >= 0x3f)
                TESForm_SaveGameDataOLD(&unk7c4, 1);
            if (reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_008df040() >= 0x40)
            {
                reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->TESSaveLoadGame_SaveGameDataOLD(&unk63c, 4);
                TESForm_SaveGameDataOLD(&unk640, 4);
                TESForm_SaveGameDataOLD(&unk644, 4);
            }
            if (reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_008df040() >= 0x49)
            {
                TESForm_SaveGameDataOLD(&unk200, 4);
                TESForm_SaveGameDataOLD(&unk240, 1);
            }
            if (reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_008df040() >= 0x70)
            {
            }
            if (reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_008df040() >= 0x71)
            {
                TESForm_SaveGameDataOLD(&unk64e, 1);
                TESForm_SaveGameDataOLD(&unk66d, 1);
                TESForm_SaveGameDataOLD(&unk794, 4);
                ForwardToSaveLoadGame(&unk7f4, 4);
            }
            if (reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_008df040() >= 0x78)
            {
                bool flagValue = Actor_GetIronSights();
                TESForm_SaveGameDataOLD(&flagValue, 1);
            }
            if (reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_008df040() >= 0x7a)
                TESForm_SaveGameDataOLD(&g_011e0b5c, 4);
        }
        if (reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_008df040() >= 0x7a)
        {
            unsigned int entryID4 = 0;
            PlayercharacterListNodeView* entries6 = PlayerCharacter_GetCasinoDataList();
            int entryCount = entries6->GetSize();
            TESForm_SaveGameDataOLD(&entryCount, 4);
            while (entries6 && *entries6->FUN_006815c0())
            {
                entryID4 = (*entries6->FUN_006815c0())->unk00;
                TESForm_SaveGameDataOLD(&entryID4, 4);
                TESForm_SaveGameDataOLD(&(*entries6->FUN_006815c0())->unk04, 4);
                TESForm_SaveGameDataOLD(&(*entries6->FUN_006815c0())->unk08, 2);
                entries6 = entries6->FUN_00726070();
            }
        }
        if (reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_008df040() >= 0x7a)
        {
            unsigned int entryID4 = 0;
            PlayercharacterListNodeView* entries2 = GetField614();
            int entryCount2 = entries2->GetSize();
            TESForm_SaveGameDataOLD(&entryCount2, 4);
            while (entries2 && *entries2->FUN_006815c0())
            {
                entryID4 = (*entries2->FUN_006815c0())->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
                TESForm_SaveGameDataOLD(&entryID4, 4);
                entries2 = entries2->FUN_00726070();
            }
            entries2 = GetField618();
            entryCount2 = entries2->GetSize();
            TESForm_SaveGameDataOLD(&entryCount2, 4);
            while (entries2 && *entries2->FUN_006815c0())
            {
                entryID4 = (*entries2->FUN_006815c0())->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
                TESForm_SaveGameDataOLD(&entryID4, 4);
                entries2 = entries2->FUN_00726070();
            }
            TESForm_SaveGameDataOLD(&unk61c, 4);
            TESForm_SaveGameDataOLD(&unk620, 4);
            TESForm_SaveGameDataOLD(&unk624, 4);
            TESForm_SaveGameDataOLD(&unk628, 4);
            TESForm_SaveGameDataOLD(&unk62c, 4);
        }
        {
            unsigned int id5 = 0;
            if (unk208)
                id5 = unk208->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            ForwardToSaveLoadGame(&id5, 4);
            unsigned int globalID3 = 0;
            if (g_011e0784)
                globalID3 = g_011e0784->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            ForwardToSaveLoadGame(&globalID3, 4);
            unsigned int spellID = 0;
            if (unk6ec)
            {
                SpellItem* spell = dynamic_cast<SpellItem*>(unk6ec);
                if (spell)
                    spellID = reinterpret_cast<FormRecord*>(spell)->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            }
            ForwardToSaveLoadGame(&spellID, 4);
            unsigned int id4 = 0;
            if (unk214)
                id4 = unk214->FUN_0040a1e0();
            ForwardToSaveLoadGame(&id4, 4);
            unsigned int id8 = 0;
            if (unk218)
                id8 = unk218->RefreshItem();
            ForwardToSaveLoadGame(&id8, 4);
            unsigned int id760_2 = 0;
            if (unk760)
                id760_2 = unk760->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            ForwardToSaveLoadGame(&id760_2, 4);
            unsigned int id6f4 = 0;
            if (unk6f0)
                id6f4 = unk6f0->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            ForwardToSaveLoadGame(&id6f4, 4);
            unsigned int id73c4 = 0;
            if (unk73c)
                id73c4 = unk73c->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            ForwardToSaveLoadGame(&id73c4, 4);
            unsigned int id_ = 0;
            if (unk758)
                id_ = ((FormRecord*)unk758)->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            ForwardToSaveLoadGame(&id_, 4);
        }
        if (reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_008df040() >= 0x28 &&
            reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_008df040() < 0x2d)
        {
            unsigned int id7ac = 0;
            if (unk7ac)
                id7ac = unk7ac->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            ForwardToSaveLoadGame(&id7ac, 4);
        }
        if (reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_008df040() >= 0x40)
        {
            unsigned int id638 = 0;
            if (unk638)
                id638 = unk638->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            ForwardToSaveLoadGame(&id638, 4);
        }
        if (reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_008df040() >= 0x42)
        {
            unsigned int globalID2 = 0;
            if (g_011e078c)
                globalID2 = g_011e078c->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            ForwardToSaveLoadGame(&globalID2, 4);
        }
        if (reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_008df040() >= 0x57)
        {
            unsigned int id604 = 0;
            if (unk604)
                id604 = unk604->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            ForwardToSaveLoadGame(&id604, 4);
        }
        if (reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_008df040() >= 0x60)
        {
            unsigned int worldID = 0;
            if (unk6f4)
            {
                FormRecord* world = ((FormRecord*)unk6f4)->TESObjectREFR_GetWorldSpace();
                if (!world)
                    world = ((FormRecord*)unk6f4)->FUN_008d6f30();
                if (world)
                    worldID = world->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            }
            ForwardToSaveLoadGame(&worldID, 4);
        }
        if (reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_008df040() >= 0x63)
        {
            unsigned short count63 = 0;
            unsigned char* countPos63 = reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_00825c00();
            TESForm_SaveGameDataOLD(&count63, 2);
            PlayercharacterListNodeView* list9 = 0;
            while (list9 && !list9->FUN_008256d0())
            {
                FormRecord* item63 = *list9->FUN_006815c0();
                unsigned int id63 = 0;
                if (item63)
                    id63 = item63->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
                ForwardToSaveLoadGame(&id63, 4);
                ++count63;
                list9 = list9->FUN_00726070();
            }
            *(unsigned short*)countPos63 = count63;
        }
        if (reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_008df040() >= 0x6c)
        {
            unsigned int parentID = 0;
            if (unk760 && unk760->FUN_0059bb30())
                parentID = unk760->FUN_0059bb30()->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            ForwardToSaveLoadGame(&parentID, 4);
        }
        if (reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_008df040() >= 0x6f)
        {
            unsigned short mapCount = (unsigned short)unk854.GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            TESForm_SaveGameDataOLD(&mapCount, 2);
            unsigned short savedCount = 0;
            void* mapPosition = unk854.GetFirstPos();
            while (mapPosition)
            {
                unsigned int mapKey = 0;
                unsigned char mapValue2 = 0;
                unk854.GetNextEntry(mapPosition, mapKey, mapValue2);
                ForwardToSaveLoadGame(&mapKey, 4);
                TESForm_SaveGameDataOLD(&mapValue2, 1);
                ++savedCount;
            }
        }
        if (reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_008df040() >= 0x73)
        {
            unsigned short count73 = 0;
            unsigned char* countPos8 = reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_00825c00();
            TESForm_SaveGameDataOLD(&count73, 2);
            PlayercharacterListNodeView* list73 = reinterpret_cast<PlayercharacterListNodeView*>(&g_011e0ae8);
            while (list73 && !list73->FUN_008256d0())
            {
                FormRecord* item73 = *list73->FUN_006815c0();
                unsigned int id_ = 0;
                if (item73)
                    id_ = item73->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
                ForwardToSaveLoadGame(&id_, 4);
                ++count73;
                list73 = list73->FUN_00726070();
            }
            *(unsigned short*)countPos8 = count73;
        }
        ActiveEffect_SaveActiveEffectList(unk210, this);
        unk878.SaveValueAndFollowingBytes(flags);
        {
            unsigned int activeQuestID = 0;
            if (unk6b8)
                activeQuestID = unk6b8->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            ForwardToSaveLoadGame(&activeQuestID, 4);
        }
        {
            unsigned short topicCount5 = 0;
            unsigned char* topicCountPos = reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_00825c00();
            TESForm_SaveGameDataOLD(&topicCount5, 2);
            PlayercharacterListNodeView* topics9 = GetSelfOffset6A8();
            while (topics9 && !topics9->FUN_008256d0())
            {
                FormRecord* topic = *topics9->FUN_006815c0();
                unsigned int topicID = topic->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
                ForwardToSaveLoadGame(&topicID, 4);
                ++topicCount5;
                topics9 = topics9->FUN_00726070();
            }
            *(unsigned short*)topicCountPos = topicCount5;
        }
        {
            unsigned short questCount3 = 0;
            unsigned char* questCountPos = reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_00825c00();
            TESForm_SaveGameDataOLD(&questCount3, 2);
            PlayercharacterListNodeView* quests2 = &unk6b0;
            while (quests2 && !quests2->FUN_008256d0())
            {
                FormRecord* quest = *quests2->FUN_006815c0();
                FormRecord* questForm = quest->FUN_005e3fa0();
                unsigned int questID3 = questForm->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
                bool completed = false;
                bool questFlag = quest->BGSBodyPart_GetToHitChance();
                PlayercharacterListNodeView* questEntries3 = questForm->BSFile_GetDevice();
                while (questEntries3 && !questEntries3->FUN_008256d0())
                {
                    FormRecord* questEntry = *questEntries3->FUN_006815c0();
                    if (quest == questEntry->FindItemByDoneFlag(questFlag))
                    {
                        completed = questEntry->TESTextureList_GetTextureCount();
                        break;
                    }
                    questEntries3 = questEntries3->FUN_00726070();
                }
                ForwardToSaveLoadGame(&questID3, 4);
                TESForm_SaveGameDataOLD(&completed, 1);
                TESForm_SaveGameDataOLD(&questFlag, 1);
                ++questCount3;
                quests2 = quests2->FUN_00726070();
            }
            *(unsigned short*)questCountPos = questCount3;
        }
        {
            unsigned short objectiveCount = 0;
            unsigned char* objectiveCountPos2 = reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_00825c00();
            TESForm_SaveGameDataOLD(&objectiveCount, 2);
            PlayercharacterListNodeView* objectives = &unk6bc;
            while (objectives && !objectives->FUN_008256d0())
            {
                FormRecord* objectiveA = *objectives->FUN_006815c0();
                FormRecord* objectiveQuest = objectiveA->TESMain_GetThread();
                unsigned int objectiveQuestID = objectiveQuest->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
                unsigned int objectiveID2 = objectiveA->FUN_00726070();
                ForwardToSaveLoadGame(&objectiveQuestID, 4);
                TESForm_SaveGameDataOLD(&objectiveID2, 4);
                ++objectiveCount;
                objectives = objectives->FUN_00726070();
            }
            *(unsigned short*)objectiveCountPos2 = objectiveCount;
        }
        {
            FormRecord* acoustic = BGSSaveFormBuffer_GetForm();
            acoustic->SerializeFaceGenData(this);
            const char* playerName3 = TESObjectREFR_GetFullName();
            unsigned char nameSize = (unsigned char)(strlen(playerName3) + 1);
            TESForm_SaveGameDataOLD(&nameSize, 1);
            TESForm_SaveGameDataOLD((void*)playerName3, nameSize);
        }
        if (reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_008df040() >= 0x2c)
        {
            FormRecord* actorBase = FUN_004181e0();
            FormRecord* actorClass5 = actorBase->FUN_00502430();
            FormRecord* defaultClass = reinterpret_cast<DataLookup*>(g_dataHandler)->GetTESClassByID(*g_011d0a9c.Int());
            unsigned int classID2 = 0;
            if (actorClass5)
                classID2 = actorClass5->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            ForwardToSaveLoadGame(&classID2, 4);
            if (actorClass5 && actorClass5 == defaultClass)
                actorClass5->TESClass_SaveGameTES();
        }
        if (reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_008df040() >= 0x45)
        {
            unsigned int id740 = 0;
            if (unk740)
                id740 = unk740->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            ForwardToSaveLoadGame(&id740, 4);
        }
        if (*g_011de4e8.Bool())
        {
            unsigned char* endPosition2 = reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_00825c00();
            SaveReference* reference4 = ((StreamView*)g_TESSaveLoadGame)->GetHitSound();
            if (reference4)
            {
                TESForm* form2 = TESForm_GetFormByNumericID(reference4->formID);
                SaveLog(reinterpret_cast<const char*>(PlayerSaveStrings::kSaveFormLog),
                        endPosition2 - initialPosition3, reference4->formID, form2->GetName(),
                        *(unsigned int*)&reference4->detail0, 0x3592,
                        reinterpret_cast<const char*>(PlayerSaveStrings::kPlayerSourcePath));
            }
            else
                SaveLog(reinterpret_cast<const char*>(PlayerSaveStrings::kSaveLog), endPosition2 - initialPosition3, 0x3592,
                        reinterpret_cast<const char*>(PlayerSaveStrings::kPlayerSourcePath));
        }
        if (reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->TESSaveLoadGame_UseSaveGameBlocks())
        {
            unsigned char* endPosition5 = reinterpret_cast<SaveStream*>(g_TESSaveLoadGame)->FUN_00825c00();
            unsigned char* sizePosition2 = blockStart9;
            if (endPosition5 > sizePosition2 + 0xffff)
                FNV_Warning(reinterpret_cast<const char*>(PlayerSaveStrings::kOversizedBlockLog),
                            reinterpret_cast<const char*>(PlayerSaveStrings::kPlayerSourcePath), 0x3592);
            *(unsigned short*)blockStart9 = (unsigned short)(endPosition5 - sizePosition2);
        }
    }
}
