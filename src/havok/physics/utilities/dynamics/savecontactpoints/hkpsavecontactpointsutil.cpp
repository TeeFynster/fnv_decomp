
// src/havok/physics/utilities/dynamics/savecontactpoints/hkpsavecontactpointsutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/dynamics/savecontactpoints/hkpsavecontactpointsutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/BSAudio.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkReferencedObject.h"

// The memory router stores its heap allocator at offset 0x10.
inline hkMemoryAllocator& BSAudio::heap()
{
    return *reinterpret_cast<hkMemoryAllocator*>(reinterpret_cast<hkMemoryRouter*>(this)->m_heap);
}

namespace fnvc_adapt {
BSAudio* __cdecl hkMemoryRouter_getInstance();
}

struct FUN_00dce8d0_class
{
    unsigned long LookupHashEntry(unsigned long key, unsigned long def);
    unsigned long GetValueOrDefault(unsigned long key);
};
// @fnv 0x00dce8d0
unsigned long FUN_00dce8d0_class::GetValueOrDefault(unsigned long key)
{
    return ((FUN_00dce8d0_class*)((char*)this + 4))->LookupHashEntry(key, 0);
}

void __cdecl hkBoxBoxAgent3_process(void);
void __cdecl hkCapsuleTriangleAgent3_process(void);
void __cdecl hkPredGskAgent3_process(void);
void __cdecl hkPredGskCylinderAgent3_process(void);
void __cdecl hkConvexListAgent3_process(void);
void __cdecl BuildEventIndex(void);
void __fastcall hkBvTreeAgent3_process(void*, int, void*, int);
void __cdecl process_00d35770(void);
void __cdecl hkpCollectionAgent3_process(void);

// @fnv 0x00dcd4d0
// src: COMMUNITY 0x00dcd4d0
int __cdecl hkpSaveContactPointsUtil_getSerializedAgentType(void* p)
{
    if (p == (void*)&hkBoxBoxAgent3_process)
        return 1;
    if (p == (void*)&hkCapsuleTriangleAgent3_process)
        return 2;
    if (p == (void*)&hkPredGskAgent3_process)
        return 3;
    if (p == (void*)&hkPredGskCylinderAgent3_process)
        return 4;
    if (p == (void*)&hkConvexListAgent3_process)
        return 5;
    if (p == (void*)&BuildEventIndex)
        return 6;
    if (p == (void*)&hkBvTreeAgent3_process)
        return 7;
    if (p == (void*)&process_00d35770)
        return 8;
    return (p != (void*)&hkpCollectionAgent3_process) ? 0 : 9;
}

struct D10710Object
{
    void Search(void* a, void* b, void* c, int flag);
    void CallWithFlag(void* a, void* b, void* c);
};

// @fnv 0x00d10710
void D10710Object::CallWithFlag(void* a, void* b, void* c)
{
    Search(a, b, c, 1);
}

struct Entry
{
    unsigned key;
    unsigned value;
    unsigned flags;
    unsigned type;
    unsigned state;
    unsigned metadata;
};
struct Node
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
    virtual int BaseIndex();
    virtual void slot10();
    virtual int Find(unsigned key);
    unsigned flags, type, state, metadata, level;
    Node* parent;
    unsigned capacity, size, reserved;
    Entry* entries;
    int count;
};
struct Object
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void SetContext(void*);
};
struct Item
{
    unsigned key;
    Object* object;
};
struct FUN_00dcb550_class
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void* Context();
    unsigned flags, count;
    Item* items;
    unsigned capacity, version;
    Node* current;
    int AddNodeEntry(Entry*);
    int SetItemContextByKey(unsigned key);
};
// Finds the entry for key in the current node tree, resolves its index, and calls SetContext on the matching item's object.
// @fnv 0x00dcb550
int FUN_00dcb550_class::SetItemContextByKey(unsigned key)
{
    int offset = current->Find(key);
    Node* node = current;
    offset -= node->BaseIndex();
    Node* walk = node;
    Entry* entry;
    do
    {
        offset += walk->count;
        if (offset >= 0)
            goto found;
        walk = walk->parent;
    } while (walk);
    entry = node->entries - 1;
    goto resolve;
found:
    entry = &walk->entries[offset];
resolve:
    int index = AddNodeEntry(entry);
    if (index != -1)
    {
        Item* item = &items[index];
        item->object->SetContext(Context());
    }
    return index;
}

struct DCD6A0Context;
struct DCD6A0Item;
typedef void(__cdecl* DCD6A0AgentFunc)();

typedef void(__cdecl* DCD6A0Func)(DCD6A0Item* item, void* data, int a, int b, DCD6A0Context* context);

struct DCD6A0Entry
{
    DCD6A0Func m_func;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    DCD6A0AgentFunc m_key;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
};

struct DCD6A0Context
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004C;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005C;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006C;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007C;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008C;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009C;
    int unk00A0;
    int unk00A4;
    int unk00A8;
    int unk00AC;
    int unk00B0;
    int unk00B4;
    int unk00B8;
    int unk00BC;
    int unk00C0;
    int unk00C4;
    int unk00C8;
    int unk00CC;
    int unk00D0;
    int unk00D4;
    int unk00D8;
    int unk00DC;
    int unk00E0;
    int unk00E4;
    int unk00E8;
    int unk00EC;
    int unk00F0;
    int unk00F4;
    int unk00F8;
    int unk00FC;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010C;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011C;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012C;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013C;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014C;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015C;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016C;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017C;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018C;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019C;
    int unk01A0;
    int unk01A4;
    int unk01A8;
    int unk01AC;
    int unk01B0;
    int unk01B4;
    int unk01B8;
    int unk01BC;
    int unk01C0;
    int unk01C4;
    int unk01C8;
    int unk01CC;
    int unk01D0;
    int unk01D4;
    int unk01D8;
    int unk01DC;
    int unk01E0;
    int unk01E4;
    int unk01E8;
    int unk01EC;
    int unk01F0;
    int unk01F4;
    int unk01F8;
    int unk01FC;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020C;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021C;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022C;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023C;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024C;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025C;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026C;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027C;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028C;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029C;
    int unk02A0;
    int unk02A4;
    int unk02A8;
    int unk02AC;
    int unk02B0;
    int unk02B4;
    int unk02B8;
    int unk02BC;
    int unk02C0;
    int unk02C4;
    int unk02C8;
    int unk02CC;
    int unk02D0;
    int unk02D4;
    int unk02D8;
    int unk02DC;
    int unk02E0;
    int unk02E4;
    int unk02E8;
    int unk02EC;
    int unk02F0;
    int unk02F4;
    int unk02F8;
    int unk02FC;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030C;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031C;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032C;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033C;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034C;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035C;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036C;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037C;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038C;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039C;
    int unk03A0;
    int unk03A4;
    int unk03A8;
    int unk03AC;
    int unk03B0;
    int unk03B4;
    int unk03B8;
    int unk03BC;
    int unk03C0;
    int unk03C4;
    int unk03C8;
    int unk03CC;
    int unk03D0;
    int unk03D4;
    int unk03D8;
    int unk03DC;
    int unk03E0;
    int unk03E4;
    int unk03E8;
    int unk03EC;
    int unk03F0;
    int unk03F4;
    int unk03F8;
    int unk03FC;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040C;
    int unk0410;
    int unk0414;
    int unk0418;
    int unk041C;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042C;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043C;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044C;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045C;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046C;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047C;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048C;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049C;
    int unk04A0;
    int unk04A4;
    int unk04A8;
    int unk04AC;
    int unk04B0;
    int unk04B4;
    int unk04B8;
    int unk04BC;
    int unk04C0;
    int unk04C4;
    int unk04C8;
    int unk04CC;
    int unk04D0;
    int unk04D4;
    int unk04D8;
    int unk04DC;
    int unk04E0;
    int unk04E4;
    int unk04E8;
    int unk04EC;
    int unk04F0;
    int unk04F4;
    int unk04F8;
    int unk04FC;
    int unk0500;
    int unk0504;
    int unk0508;
    int unk050C;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051C;
    int unk0520;
    int unk0524;
    int unk0528;
    int unk052C;
    int unk0530;
    int unk0534;
    int unk0538;
    int unk053C;
    int unk0540;
    int unk0544;
    int unk0548;
    int unk054C;
    int unk0550;
    int unk0554;
    int unk0558;
    int unk055C;
    int unk0560;
    int unk0564;
    int unk0568;
    int unk056C;
    int unk0570;
    int unk0574;
    int unk0578;
    int unk057C;
    int unk0580;
    int unk0584;
    int unk0588;
    int unk058C;
    int unk0590;
    int unk0594;
    int unk0598;
    int unk059C;
    int unk05A0;
    int unk05A4;
    int unk05A8;
    int unk05AC;
    int unk05B0;
    int unk05B4;
    int unk05B8;
    int unk05BC;
    int unk05C0;
    int unk05C4;
    int unk05C8;
    int unk05CC;
    int unk05D0;
    int unk05D4;
    int unk05D8;
    int unk05DC;
    int unk05E0;
    int unk05E4;
    int unk05E8;
    int unk05EC;
    int unk05F0;
    int unk05F4;
    int unk05F8;
    int unk05FC;
    int unk0600;
    int unk0604;
    int unk0608;
    int unk060C;
    int unk0610;
    int unk0614;
    int unk0618;
    int unk061C;
    int unk0620;
    int unk0624;
    int unk0628;
    int unk062C;
    int unk0630;
    int unk0634;
    int unk0638;
    int unk063C;
    int unk0640;
    int unk0644;
    int unk0648;
    int unk064C;
    int unk0650;
    int unk0654;
    int unk0658;
    int unk065C;
    int unk0660;
    int unk0664;
    int unk0668;
    int unk066C;
    int unk0670;
    int unk0674;
    int unk0678;
    int unk067C;
    int unk0680;
    int unk0684;
    int unk0688;
    int unk068C;
    int unk0690;
    int unk0694;
    int unk0698;
    int unk069C;
    int unk06A0;
    int unk06A4;
    int unk06A8;
    int unk06AC;
    int unk06B0;
    int unk06B4;
    int unk06B8;
    int unk06BC;
    int unk06C0;
    int unk06C4;
    int unk06C8;
    int unk06CC;
    int unk06D0;
    int unk06D4;
    int unk06D8;
    int unk06DC;
    int unk06E0;
    int unk06E4;
    int unk06E8;
    int unk06EC;
    int unk06F0;
    int unk06F4;
    int unk06F8;
    int unk06FC;
    int unk0700;
    int unk0704;
    int unk0708;
    int unk070C;
    int unk0710;
    int unk0714;
    int unk0718;
    int unk071C;
    int unk0720;
    int unk0724;
    int unk0728;
    int unk072C;
    int unk0730;
    int unk0734;
    int unk0738;
    int unk073C;
    int unk0740;
    int unk0744;
    int unk0748;
    int unk074C;
    int unk0750;
    int unk0754;
    int unk0758;
    int unk075C;
    int unk0760;
    int unk0764;
    int unk0768;
    int unk076C;
    int unk0770;
    int unk0774;
    int unk0778;
    int unk077C;
    int unk0780;
    int unk0784;
    int unk0788;
    int unk078C;
    int unk0790;
    int unk0794;
    int unk0798;
    int unk079C;
    int unk07A0;
    int unk07A4;
    int unk07A8;
    int unk07AC;
    int unk07B0;
    int unk07B4;
    int unk07B8;
    int unk07BC;
    int unk07C0;
    int unk07C4;
    int unk07C8;
    int unk07CC;
    int unk07D0;
    int unk07D4;
    int unk07D8;
    int unk07DC;
    int unk07E0;
    int unk07E4;
    int unk07E8;
    int unk07EC;
    int unk07F0;
    int unk07F4;
    int unk07F8;
    int unk07FC;
    int unk0800;
    int unk0804;
    int unk0808;
    int unk080C;
    int unk0810;
    int unk0814;
    int unk0818;
    int unk081C;
    int unk0820;
    int unk0824;
    int unk0828;
    int unk082C;
    int unk0830;
    int unk0834;
    int unk0838;
    int unk083C;
    int unk0840;
    int unk0844;
    int unk0848;
    int unk084C;
    int unk0850;
    int unk0854;
    int unk0858;
    int unk085C;
    int unk0860;
    int unk0864;
    int unk0868;
    int unk086C;
    int unk0870;
    int unk0874;
    int unk0878;
    int unk087C;
    int unk0880;
    int unk0884;
    int unk0888;
    int unk088C;
    int unk0890;
    int unk0894;
    int unk0898;
    int unk089C;
    int unk08A0;
    int unk08A4;
    int unk08A8;
    int unk08AC;
    int unk08B0;
    int unk08B4;
    int unk08B8;
    int unk08BC;
    int unk08C0;
    int unk08C4;
    int unk08C8;
    int unk08CC;
    int unk08D0;
    int unk08D4;
    int unk08D8;
    int unk08DC;
    int unk08E0;
    int unk08E4;
    int unk08E8;
    int unk08EC;
    int unk08F0;
    int unk08F4;
    int unk08F8;
    int unk08FC;
    int unk0900;
    int unk0904;
    int unk0908;
    int unk090C;
    int unk0910;
    int unk0914;
    int unk0918;
    int unk091C;
    int unk0920;
    int unk0924;
    int unk0928;
    int unk092C;
    int unk0930;
    int unk0934;
    int unk0938;
    int unk093C;
    int unk0940;
    int unk0944;
    int unk0948;
    int unk094C;
    int unk0950;
    int unk0954;
    int unk0958;
    int unk095C;
    int unk0960;
    int unk0964;
    int unk0968;
    int unk096C;
    int unk0970;
    int unk0974;
    int unk0978;
    int unk097C;
    int unk0980;
    int unk0984;
    int unk0988;
    int unk098C;
    int unk0990;
    int unk0994;
    int unk0998;
    int unk099C;
    int unk09A0;
    int unk09A4;
    int unk09A8;
    int unk09AC;
    int unk09B0;
    int unk09B4;
    int unk09B8;
    int unk09BC;
    int unk09C0;
    int unk09C4;
    int unk09C8;
    int unk09CC;
    int unk09D0;
    int unk09D4;
    int unk09D8;
    int unk09DC;
    int unk09E0;
    int unk09E4;
    int unk09E8;
    int unk09EC;
    int unk09F0;
    int unk09F4;
    int unk09F8;
    int unk09FC;
    int unk0A00;
    int unk0A04;
    int unk0A08;
    int unk0A0C;
    int unk0A10;
    int unk0A14;
    int unk0A18;
    int unk0A1C;
    int unk0A20;
    int unk0A24;
    int unk0A28;
    int unk0A2C;
    int unk0A30;
    int unk0A34;
    int unk0A38;
    int unk0A3C;
    int unk0A40;
    int unk0A44;
    int unk0A48;
    int unk0A4C;
    int unk0A50;
    int unk0A54;
    int unk0A58;
    int unk0A5C;
    int unk0A60;
    int unk0A64;
    int unk0A68;
    int unk0A6C;
    int unk0A70;
    int unk0A74;
    int unk0A78;
    int unk0A7C;
    int unk0A80;
    int unk0A84;
    int unk0A88;
    int unk0A8C;
    int unk0A90;
    int unk0A94;
    int unk0A98;
    int unk0A9C;
    int unk0AA0;
    int unk0AA4;
    int unk0AA8;
    int unk0AAC;
    int unk0AB0;
    int unk0AB4;
    int unk0AB8;
    int unk0ABC;
    int unk0AC0;
    int unk0AC4;
    int unk0AC8;
    int unk0ACC;
    int unk0AD0;
    int unk0AD4;
    int unk0AD8;
    int unk0ADC;
    int unk0AE0;
    int unk0AE4;
    int unk0AE8;
    int unk0AEC;
    int unk0AF0;
    int unk0AF4;
    int unk0AF8;
    int unk0AFC;
    int unk0B00;
    int unk0B04;
    int unk0B08;
    int unk0B0C;
    int unk0B10;
    int unk0B14;
    int unk0B18;
    int unk0B1C;
    int unk0B20;
    int unk0B24;
    int unk0B28;
    int unk0B2C;
    int unk0B30;
    int unk0B34;
    int unk0B38;
    int unk0B3C;
    int unk0B40;
    int unk0B44;
    int unk0B48;
    int unk0B4C;
    int unk0B50;
    int unk0B54;
    int unk0B58;
    int unk0B5C;
    int unk0B60;
    int unk0B64;
    int unk0B68;
    int unk0B6C;
    int unk0B70;
    int unk0B74;
    int unk0B78;
    int unk0B7C;
    int unk0B80;
    int unk0B84;
    int unk0B88;
    int unk0B8C;
    int unk0B90;
    int unk0B94;
    int unk0B98;
    int unk0B9C;
    int unk0BA0;
    int unk0BA4;
    int unk0BA8;
    int unk0BAC;
    int unk0BB0;
    int unk0BB4;
    int unk0BB8;
    int unk0BBC;
    int unk0BC0;
    int unk0BC4;
    int unk0BC8;
    int unk0BCC;
    int unk0BD0;
    int unk0BD4;
    int unk0BD8;
    int unk0BDC;
    int unk0BE0;
    int unk0BE4;
    int unk0BE8;
    int unk0BEC;
    int unk0BF0;
    int unk0BF4;
    int unk0BF8;
    int unk0BFC;
    int unk0C00;
    int unk0C04;
    int unk0C08;
    int unk0C0C;
    int unk0C10;
    int unk0C14;
    int unk0C18;
    int unk0C1C;
    int unk0C20;
    int unk0C24;
    int unk0C28;
    int unk0C2C;
    int unk0C30;
    int unk0C34;
    int unk0C38;
    int unk0C3C;
    int unk0C40;
    int unk0C44;
    int unk0C48;
    int unk0C4C;
    int unk0C50;
    int unk0C54;
    int unk0C58;
    int unk0C5C;
    int unk0C60;
    int unk0C64;
    int unk0C68;
    int unk0C6C;
    int unk0C70;
    int unk0C74;
    int unk0C78;
    int unk0C7C;
    int unk0C80;
    int unk0C84;
    int unk0C88;
    int unk0C8C;
    int unk0C90;
    int unk0C94;
    int unk0C98;
    int unk0C9C;
    int unk0CA0;
    int unk0CA4;
    int unk0CA8;
    int unk0CAC;
    int unk0CB0;
    int unk0CB4;
    int unk0CB8;
    int unk0CBC;
    int unk0CC0;
    int unk0CC4;
    int unk0CC8;
    int unk0CCC;
    int unk0CD0;
    int unk0CD4;
    int unk0CD8;
    int unk0CDC;
    int unk0CE0;
    int unk0CE4;
    int unk0CE8;
    int unk0CEC;
    int unk0CF0;
    int unk0CF4;
    int unk0CF8;
    int unk0CFC;
    int unk0D00;
    int unk0D04;
    int unk0D08;
    int unk0D0C;
    int unk0D10;
    int unk0D14;
    int unk0D18;
    int unk0D1C;
    int unk0D20;
    int unk0D24;
    int unk0D28;
    int unk0D2C;
    int unk0D30;
    int unk0D34;
    int unk0D38;
    int unk0D3C;
    int unk0D40;
    int unk0D44;
    int unk0D48;
    int unk0D4C;
    int unk0D50;
    int unk0D54;
    int unk0D58;
    int unk0D5C;
    int unk0D60;
    int unk0D64;
    int unk0D68;
    int unk0D6C;
    int unk0D70;
    int unk0D74;
    int unk0D78;
    int unk0D7C;
    int unk0D80;
    int unk0D84;
    int unk0D88;
    int unk0D8C;
    int unk0D90;
    int unk0D94;
    int unk0D98;
    int unk0D9C;
    int unk0DA0;
    int unk0DA4;
    int unk0DA8;
    int unk0DAC;
    int unk0DB0;
    int unk0DB4;
    int unk0DB8;
    int unk0DBC;
    int unk0DC0;
    int unk0DC4;
    int unk0DC8;
    int unk0DCC;
    int unk0DD0;
    int unk0DD4;
    int unk0DD8;
    int unk0DDC;
    int unk0DE0;
    int unk0DE4;
    int unk0DE8;
    int unk0DEC;
    int unk0DF0;
    int unk0DF4;
    int unk0DF8;
    int unk0DFC;
    int unk0E00;
    int unk0E04;
    int unk0E08;
    int unk0E0C;
    int unk0E10;
    int unk0E14;
    int unk0E18;
    int unk0E1C;
    int unk0E20;
    int unk0E24;
    int unk0E28;
    int unk0E2C;
    int unk0E30;
    int unk0E34;
    int unk0E38;
    int unk0E3C;
    int unk0E40;
    int unk0E44;
    int unk0E48;
    int unk0E4C;
    int unk0E50;
    int unk0E54;
    int unk0E58;
    int unk0E5C;
    int unk0E60;
    int unk0E64;
    int unk0E68;
    int unk0E6C;
    int unk0E70;
    int unk0E74;
    int unk0E78;
    int unk0E7C;
    int unk0E80;
    int unk0E84;
    int unk0E88;
    int unk0E8C;
    int unk0E90;
    int unk0E94;
    int unk0E98;
    int unk0E9C;
    int unk0EA0;
    int unk0EA4;
    int unk0EA8;
    int unk0EAC;
    int unk0EB0;
    int unk0EB4;
    int unk0EB8;
    int unk0EBC;
    int unk0EC0;
    int unk0EC4;
    int unk0EC8;
    int unk0ECC;
    int unk0ED0;
    int unk0ED4;
    int unk0ED8;
    int unk0EDC;
    int unk0EE0;
    int unk0EE4;
    int unk0EE8;
    int unk0EEC;
    int unk0EF0;
    int unk0EF4;
    int unk0EF8;
    int unk0EFC;
    int unk0F00;
    int unk0F04;
    int unk0F08;
    int unk0F0C;
    int unk0F10;
    int unk0F14;
    int unk0F18;
    int unk0F1C;
    int unk0F20;
    int unk0F24;
    int unk0F28;
    int unk0F2C;
    int unk0F30;
    int unk0F34;
    int unk0F38;
    int unk0F3C;
    int unk0F40;
    int unk0F44;
    int unk0F48;
    int unk0F4C;
    int unk0F50;
    int unk0F54;
    int unk0F58;
    int unk0F5C;
    int unk0F60;
    int unk0F64;
    int unk0F68;
    int unk0F6C;
    int unk0F70;
    int unk0F74;
    int unk0F78;
    int unk0F7C;
    int unk0F80;
    int unk0F84;
    int unk0F88;
    int unk0F8C;
    int unk0F90;
    int unk0F94;
    int unk0F98;
    int unk0F9C;
    int unk0FA0;
    int unk0FA4;
    int unk0FA8;
    int unk0FAC;
    int unk0FB0;
    int unk0FB4;
    int unk0FB8;
    int unk0FBC;
    int unk0FC0;
    int unk0FC4;
    int unk0FC8;
    int unk0FCC;
    int unk0FD0;
    int unk0FD4;
    int unk0FD8;
    int unk0FDC;
    int unk0FE0;
    int unk0FE4;
    int unk0FE8;
    int unk0FEC;
    int unk0FF0;
    int unk0FF4;
    int unk0FF8;
    int unk0FFC;
    int unk1000;
    int unk1004;
    int unk1008;
    int unk100C;
    int unk1010;
    int unk1014;
    int unk1018;
    int unk101C;
    int unk1020;
    int unk1024;
    int unk1028;
    int unk102C;
    int unk1030;
    int unk1034;
    int unk1038;
    int unk103C;
    int unk1040;
    int unk1044;
    int unk1048;
    int unk104C;
    int unk1050;
    int unk1054;
    int unk1058;
    int unk105C;
    int unk1060;
    int unk1064;
    int unk1068;
    int unk106C;
    int unk1070;
    int unk1074;
    int unk1078;
    int unk107C;
    int unk1080;
    int unk1084;
    int unk1088;
    int unk108C;
    int unk1090;
    int unk1094;
    int unk1098;
    int unk109C;
    int unk10A0;
    int unk10A4;
    int unk10A8;
    int unk10AC;
    int unk10B0;
    int unk10B4;
    int unk10B8;
    int unk10BC;
    int unk10C0;
    int unk10C4;
    int unk10C8;
    int unk10CC;
    int unk10D0;
    int unk10D4;
    int unk10D8;
    int unk10DC;
    int unk10E0;
    int unk10E4;
    int unk10E8;
    int unk10EC;
    int unk10F0;
    int unk10F4;
    int unk10F8;
    int unk10FC;
    int unk1100;
    int unk1104;
    int unk1108;
    int unk110C;
    int unk1110;
    int unk1114;
    int unk1118;
    int unk111C;
    int unk1120;
    int unk1124;
    int unk1128;
    int unk112C;
    int unk1130;
    int unk1134;
    int unk1138;
    int unk113C;
    int unk1140;
    int unk1144;
    int unk1148;
    int unk114C;
    int unk1150;
    int unk1154;
    int unk1158;
    int unk115C;
    int unk1160;
    int unk1164;
    int unk1168;
    int unk116C;
    int unk1170;
    int unk1174;
    int unk1178;
    int unk117C;
    int unk1180;
    int unk1184;
    int unk1188;
    int unk118C;
    int unk1190;
    int unk1194;
    int unk1198;
    int unk119C;
    int unk11A0;
    int unk11A4;
    int unk11A8;
    int unk11AC;
    int unk11B0;
    int unk11B4;
    int unk11B8;
    int unk11BC;
    int unk11C0;
    int unk11C4;
    int unk11C8;
    int unk11CC;
    int unk11D0;
    int unk11D4;
    int unk11D8;
    int unk11DC;
    int unk11E0;
    int unk11E4;
    int unk11E8;
    int unk11EC;
    int unk11F0;
    int unk11F4;
    int unk11F8;
    int unk11FC;
    int unk1200;
    int unk1204;
    int unk1208;
    int unk120C;
    int unk1210;
    int unk1214;
    int unk1218;
    int unk121C;
    int unk1220;
    int unk1224;
    int unk1228;
    int unk122C;
    int unk1230;
    int unk1234;
    int unk1238;
    int unk123C;
    int unk1240;
    int unk1244;
    int unk1248;
    int unk124C;
    int unk1250;
    int unk1254;
    int unk1258;
    int unk125C;
    int unk1260;
    int unk1264;
    int unk1268;
    int unk126C;
    int unk1270;
    int unk1274;
    int unk1278;
    int unk127C;
    int unk1280;
    int unk1284;
    int unk1288;
    int unk128C;
    int unk1290;
    int unk1294;
    int unk1298;
    int unk129C;
    int unk12A0;
    int unk12A4;
    int unk12A8;
    int unk12AC;
    int unk12B0;
    int unk12B4;
    int unk12B8;
    int unk12BC;
    int unk12C0;
    int unk12C4;
    int unk12C8;
    int unk12CC;
    int unk12D0;
    int unk12D4;
    int unk12D8;
    int unk12DC;
    int unk12E0;
    int unk12E4;
    int unk12E8;
    int unk12EC;
    int unk12F0;
    int unk12F4;
    int unk12F8;
    int unk12FC;
    int unk1300;
    int unk1304;
    int unk1308;
    int unk130C;
    int unk1310;
    int unk1314;
    int unk1318;
    int unk131C;
    int unk1320;
    int unk1324;
    int unk1328;
    int unk132C;
    int unk1330;
    int unk1334;
    int unk1338;
    int unk133C;
    int unk1340;
    int unk1344;
    int unk1348;
    int unk134C;
    int unk1350;
    int unk1354;
    int unk1358;
    int unk135C;
    int unk1360;
    int unk1364;
    int unk1368;
    int unk136C;
    int unk1370;
    int unk1374;
    int unk1378;
    int unk137C;
    int unk1380;
    int unk1384;
    int unk1388;
    int unk138C;
    int unk1390;
    int unk1394;
    int unk1398;
    int unk139C;
    int unk13A0;
    int unk13A4;
    int unk13A8;
    int unk13AC;
    int unk13B0;
    int unk13B4;
    int unk13B8;
    int unk13BC;
    int unk13C0;
    int unk13C4;
    int unk13C8;
    int unk13CC;
    int unk13D0;
    int unk13D4;
    int unk13D8;
    int unk13DC;
    int unk13E0;
    int unk13E4;
    int unk13E8;
    int unk13EC;
    int unk13F0;
    int unk13F4;
    int unk13F8;
    int unk13FC;
    int unk1400;
    int unk1404;
    int unk1408;
    int unk140C;
    int unk1410;
    int unk1414;
    int unk1418;
    int unk141C;
    int unk1420;
    int unk1424;
    int unk1428;
    int unk142C;
    int unk1430;
    int unk1434;
    int unk1438;
    int unk143C;
    int unk1440;
    int unk1444;
    int unk1448;
    int unk144C;
    int unk1450;
    int unk1454;
    int unk1458;
    int unk145C;
    int unk1460;
    int unk1464;
    int unk1468;
    int unk146C;
    int unk1470;
    int unk1474;
    int unk1478;
    int unk147C;
    int unk1480;
    int unk1484;
    int unk1488;
    int unk148C;
    int unk1490;
    int unk1494;
    int unk1498;
    int unk149C;
    int unk14A0;
    int unk14A4;
    int unk14A8;
    int unk14AC;
    int unk14B0;
    int unk14B4;
    int unk14B8;
    int unk14BC;
    int unk14C0;
    int unk14C4;
    int unk14C8;
    int unk14CC;
    int unk14D0;
    int unk14D4;
    int unk14D8;
    int unk14DC;
    int unk14E0;
    int unk14E4;
    int unk14E8;
    int unk14EC;
    int unk14F0;
    int unk14F4;
    int unk14F8;
    int unk14FC;
    int unk1500;
    int unk1504;
    int unk1508;
    int unk150C;
    int unk1510;
    int unk1514;
    int unk1518;
    int unk151C;
    int unk1520;
    int unk1524;
    int unk1528;
    int unk152C;
    int unk1530;
    int unk1534;
    int unk1538;
    int unk153C;
    int unk1540;
    int unk1544;
    int unk1548;
    int unk154C;
    int unk1550;
    int unk1554;
    int unk1558;
    int unk155C;
    int unk1560;
    int unk1564;
    int unk1568;
    int unk156C;
    int unk1570;
    int unk1574;
    int unk1578;
    int unk157C;
    int unk1580;
    int unk1584;
    int unk1588;
    int unk158C;
    int unk1590;
    int unk1594;
    int unk1598;
    int unk159C;
    int unk15A0;
    int unk15A4;
    int unk15A8;
    int unk15AC;
    int unk15B0;
    int unk15B4;
    int unk15B8;
    int unk15BC;
    int unk15C0;
    int unk15C4;
    int unk15C8;
    int unk15CC;
    int unk15D0;
    int unk15D4;
    int unk15D8;
    int unk15DC;
    int unk15E0;
    int unk15E4;
    int unk15E8;
    int unk15EC;
    int unk15F0;
    int unk15F4;
    int unk15F8;
    int unk15FC;
    int unk1600;
    int unk1604;
    int unk1608;
    int unk160C;
    int unk1610;
    int unk1614;
    int unk1618;
    int unk161C;
    int unk1620;
    int unk1624;
    int unk1628;
    int unk162C;
    int unk1630;
    int unk1634;
    int unk1638;
    int unk163C;
    int unk1640;
    int unk1644;
    int unk1648;
    int unk164C;
    int unk1650;
    int unk1654;
    int unk1658;
    int unk165C;
    int unk1660;
    int unk1664;
    int unk1668;
    int unk166C;
    int unk1670;
    int unk1674;
    int unk1678;
    int unk167C;
    int unk1680;
    int unk1684;
    int unk1688;
    int unk168C;
    int unk1690;
    int unk1694;
    int unk1698;
    int unk169C;
    int unk16A0;
    int unk16A4;
    int unk16A8;
    int unk16AC;
    int unk16B0;
    DCD6A0Entry m_entries[1];
};

struct DCD6A0Item
{
    unsigned char m_type;
    unsigned char m_uiEdgeIndex;
};

void __cdecl DCD6A0Agent1();
void __cdecl DCD6A0Agent2();
void __cdecl DCD6A0Agent3();
void __cdecl DCD6A0Agent4();
void __cdecl DCD6A0Agent5();
void __cdecl DCD6A0Agent6();
void __cdecl DCD6A0Agent7();
void __cdecl DCD6A0Agent8();
void __cdecl DCD6A0Agent9();

// File-static helper (reconstruction of FUN_00dcd4d0): maps a registered agent function to its id.
static int DCD6A0GetAgentId(DCD6A0AgentFunc func)
{
    if (func == DCD6A0Agent1)
        return 1;
    if (func == DCD6A0Agent2)
        return 2;
    if (func == DCD6A0Agent3)
        return 3;
    if (func == DCD6A0Agent4)
        return 4;
    if (func == DCD6A0Agent5)
        return 5;
    if (func == DCD6A0Agent6)
        return 6;
    if (func == DCD6A0Agent7)
        return 7;
    if (func == DCD6A0Agent8)
        return 8;
    return (func == DCD6A0Agent9) ? 9 : 0;
}

// Taking the helper's address keeps its standard stack argument, as the original codegen shows.
int(__cdecl* g_DCD6A0GetAgentId)(DCD6A0AgentFunc) = DCD6A0GetAgentId;

// @fnv 0x00dcd6a0
int __cdecl DispatchItemToAgent(int aiExpectedAgentId, DCD6A0Context** contextPtr, int aiArg1, int aiArg2,
                                DCD6A0Item* item)
{
    void* data;
    switch (item->m_type)
    {
    case 2:
        data = (char*)item + 0x20;
        break;
    case 4:
        data = (char*)item + 0x30;
        break;
    case 6:
        return 1;
    default:
        return 1;
    }
    DCD6A0Context* context = *contextPtr;
    int index = item->m_uiEdgeIndex;
    if (DCD6A0GetAgentId(context->m_entries[index].m_key) != aiExpectedAgentId || !aiExpectedAgentId)
        return 1;
    context->m_entries[index].m_func(item, data, aiArg1, aiArg2, context);
    return 0;
}

struct S_00dcdd80_RefObj
{
    void* vtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    static void* operator new(unsigned int nbytes)
    {
        S_00dcdd80_RefObj* b =
            static_cast<S_00dcdd80_RefObj*>(fnvc_adapt::hkMemoryRouter_getInstance()->heap().blockAlloc(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void*, unsigned int)
    {}
    void FUN_00c905b0();
};
struct FUN_00dce930 : S_00dcdd80_RefObj
{
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
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    FUN_00dce930() throw();
};
struct S_00dcdd80_WorldObj
{
    void* vtbl;
    int unk04;
    struct S_00dcdd80_World2* m_pOwningWorld;
};
struct S_00dcdd80_World2
{
    int unk00;
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
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
};
struct S_00dcdd80_Collidable
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    signed char m_iOwnerOffset;
    char unk11;
    short unk12;
    int unk14;
    signed char m_type;
    void* getOwner()
    {
        return (char*)this + m_iOwnerOffset;
    }
};
struct S_00dcdd80_Item
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00dcdd80_Collidable* unk10;
};
struct S_00dcdd80_Listener
{
    void AddObject(FUN_00dce930* obj);
};
int __cdecl hkpSaveContactPointsUtil_serializeCollisionEntry(void* a, S_00dcdd80_Item* item, int c, FUN_00dce930* obj);

static inline S_00dcdd80_WorldObj* S_00dcdd80_getRigidBody(S_00dcdd80_Collidable* c)
{
    if (c->m_type == 1)
        return (S_00dcdd80_WorldObj*)c->getOwner();
    return 0;
}

// For each item, allocates a FUN_00dce930, tests it against world->unk78 via FUN_00dcd720, notifies the listener on failure, then calls FUN_00c905b0.
// @fnv 0x00dcdd80
// src: HAVOK_LIB 0x00dcdd80
void hkpSaveContactPointsUtil_saveContactPoints_00dcdd80(void* a, S_00dcdd80_Item** items, int count, S_00dcdd80_Listener* listener)
{
    S_00dcdd80_World2* world = S_00dcdd80_getRigidBody(items[0]->unk10)->m_pOwningWorld;
    for (int i = 0; i < count; i++)
    {
        FUN_00dce930* obj = new FUN_00dce930();
        int iWorldValue = world->unk78;
        if (!hkpSaveContactPointsUtil_serializeCollisionEntry(a, items[i], iWorldValue, obj))
            listener->AddObject(obj);
        obj->FUN_00c905b0();
    }
}

namespace fnv_00dcde10 {
void* __cdecl hkString_memCpy(void*, const void*, unsigned int);
void* __cdecl Object_ComputeValue_00d32ac0(void*, void*);
int __cdecl CopyAudioNodeTree(void*, void*, void*);
// src: COMMUNITY 0x00dcd4d0
int hkpSaveContactPointsUtil_getSerializedAgentType(void* p)
{
    if (p == reinterpret_cast<void*>(&hkBoxBoxAgent3_process))
        return 1;
    if (p == reinterpret_cast<void*>(&hkCapsuleTriangleAgent3_process))
        return 2;
    if (p == reinterpret_cast<void*>(&hkPredGskAgent3_process))
        return 3;
    if (p == reinterpret_cast<void*>(&hkPredGskCylinderAgent3_process))
        return 4;
    if (p == reinterpret_cast<void*>(&hkConvexListAgent3_process))
        return 5;
    if (p == reinterpret_cast<void*>(&BuildEventIndex))
        return 6;
    if (p == reinterpret_cast<void*>(&hkBvTreeAgent3_process))
        return 7;
    if (p == reinterpret_cast<void*>(&process_00d35770))
        return 8;
    if (p == reinterpret_cast<void*>(&hkpCollectionAgent3_process))
        return 9;
    return 0;
}
struct EntryState
{
    unsigned int count, capacity, flags;
};
__forceinline EntryState* reset(EntryState* p)
{
    if (p)
    {
        p->count = 0;
        p->capacity = 0;
        p->flags = 0x80000000;
    }
    return p;
}
// @fnv 0x00dcde10
int DispatchInstruction(char* source, int kind, void* context, char** ppRegistry, unsigned char* instruction)
{
    unsigned char* payload;
    switch (instruction[0])
    {
    case 2:
        payload = instruction + 32;
        break;
    case 4:
        payload = instruction + 48;
        break;
    case 6:
        return 1;
    default:
        return 1;
    }
    if (hkpSaveContactPointsUtil_getSerializedAgentType(*reinterpret_cast<void**>(*ppRegistry + 0x16dc + instruction[1] * 80)) != kind)
        return 1;
    switch (kind)
    {
    case 1:
    case 2:
    case 3:
    case 4:
        hkString_memCpy(instruction + 24, source + 140, 104);
        instruction[2] = source[118];
        instruction[3] = source[119];
        return 0;
    case 5:
        hkString_memCpy(instruction + 24, source + 140, 104);
        instruction[2] = source[118];
        instruction[3] = source[119];
        if (payload[11] & 32)
            return 0;
        return CopyAudioNodeTree(context, ppRegistry,
                                 reset(static_cast<EntryState*>(Object_ComputeValue_00d32ac0(instruction, payload))));
    case 6:
    case 7:
    case 8:
    case 9:
        hkString_memCpy(instruction + 24, source + 140, 104);
        return CopyAudioNodeTree(context, ppRegistry, reset(reinterpret_cast<EntryState*>(payload)));
    default:
        return 1;
    }
}
}  // namespace fnv_00dcde10

struct LocalContext
{
    void* vtable;
};
extern int DAT_010d77c0;
extern "C" void __cdecl hkpSaveContactPointsUtil_loadContactPointsInternal(int, int, int, LocalContext*);
// Sets up a LocalContext with DAT_010d77c0 as its vtable and forwards first, second and third to FUN_00dcea10.
// @fnv 0x00dce7b0
void __cdecl RunWithLocalContext(int first, int second, int third)
{
    LocalContext local;
    local.vtable = &DAT_010d77c0;
    hkpSaveContactPointsUtil_loadContactPointsInternal(first, second, third, &local);
}

void __cdecl hkpSaveContactPointsUtil_loadContactPointsInternal(int, int, int, void*);
int __cdecl hkMemoryRouter_getInstance();
struct FUN_00dce7e0_local
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void __thiscall FUN_00dce840(void*, void*);
    void __thiscall ProcessArgument(int);
    void __thiscall Object_DoNothing();
};
// Reads a value from *p, initializes a local via FUN_00dce840, calls FUN_00dcea10, then invokes two methods on the local using a value from FUN_00c85750.
// @fnv 0x00dce7e0
// src: HAVOK_LIB 0x00dce7e0
void __cdecl hkpSaveContactPointsUtil_loadContactPoints(int aiArg1, int aiArg2, int* p, int d)
{
    FUN_00dce7e0_local local;
    int value = *(int*)(*p + 8);
    local.FUN_00dce840(p, (void*)d);
    hkpSaveContactPointsUtil_loadContactPointsInternal(aiArg1, aiArg2, value, &local);
    int object = hkMemoryRouter_getInstance();
    ((FUN_00dce7e0_local*)((char*)&local + 4))->ProcessArgument(*(int*)(object + 0x10));
    ((FUN_00dce7e0_local*)((char*)&local + 4))->Object_DoNothing();
}

namespace fnv_00dce840 {

extern "C" BSAudio& __cdecl hkMemoryRouter_getInstance();

struct DCE840PointerMap
{
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    DCE840PointerMap() : m_kPrimitiveElement(0), m_iCapacityFlags(0), m_iPairCount(-1)
    {
        reserve(hkMemoryRouter_getInstance().heap(), 0);
    }

    void reserve(hkMemoryAllocator& alloc, int numElements);
    void clear();
    void insert(hkMemoryAllocator& alloc, void* key, int value);
};

struct FUN_00dce840
{
    virtual void vfunc00();

    DCE840PointerMap m_map;

    FUN_00dce840(void* const* keys, int numKeys);
};

// Clears m_map, reserves room for numKeys entries, then inserts each key from keys with value 1.
// @fnv 0x00dce840
FUN_00dce840::FUN_00dce840(void* const* keys, int numKeys)
{
    m_map.clear();
    m_map.reserve(hkMemoryRouter_getInstance().heap(), numKeys);
    for (int i = 0; i < numKeys; i++)
    {
        void* key = keys[i];
        m_map.insert(hkMemoryRouter_getInstance().heap(), key, 1);
    }
}
}  // namespace fnv_00dce840

void __cdecl hkArrayUtil__reserve(void* apAllocator, void* apArray, unsigned int auiNewCap, int aiElemSize);

struct SrcNode
{
    unsigned int** m_ppBuffers;
    int m_iArrayLength;
    int unk08;
    SrcNode** m_ppItems;
    int m_iItemCount;
    int unk14;
    int m_iIndex;
    int m_iFirstValue;
};

struct DstBlock
{
    unsigned int* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapBits;
};

struct Buffer512
{
    unsigned int m_i00;
    unsigned int m_i04;
    unsigned int m_i08;
    unsigned int m_i0c;
    unsigned int m_i10;
    unsigned int m_i14;
    unsigned int m_i18;
    unsigned int m_i1c;
    unsigned int m_i20;
    unsigned int m_i24;
    unsigned int m_i28;
    unsigned int m_i2c;
    unsigned int m_i30;
    unsigned int m_i34;
    unsigned int m_i38;
    unsigned int m_i3c;
    unsigned int m_i40;
    unsigned int m_i44;
    unsigned int m_i48;
    unsigned int m_i4c;
    unsigned int m_i50;
    unsigned int m_i54;
    unsigned int m_i58;
    unsigned int m_i5c;
    unsigned int m_i60;
    unsigned int m_i64;
    unsigned int m_i68;
    unsigned int m_i6c;
    unsigned int m_i70;
    unsigned int m_i74;
    unsigned int m_i78;
    unsigned int m_i7c;
    unsigned int m_i80;
    unsigned int m_i84;
    unsigned int m_i88;
    unsigned int m_i8c;
    unsigned int m_i90;
    unsigned int m_i94;
    unsigned int m_i98;
    unsigned int m_i9c;
    unsigned int m_ia0;
    unsigned int m_ia4;
    unsigned int m_ia8;
    unsigned int m_iac;
    unsigned int m_ib0;
    unsigned int m_ib4;
    unsigned int m_ib8;
    unsigned int m_ibc;
    unsigned int m_ic0;
    unsigned int m_ic4;
    unsigned int m_ic8;
    unsigned int m_icc;
    unsigned int m_id0;
    unsigned int m_id4;
    unsigned int m_id8;
    unsigned int m_idc;
    unsigned int m_ie0;
    unsigned int m_ie4;
    unsigned int m_ie8;
    unsigned int m_iec;
    unsigned int m_if0;
    unsigned int m_if4;
    unsigned int m_if8;
    unsigned int m_ifc;
    unsigned int m_i100;
    unsigned int m_i104;
    unsigned int m_i108;
    unsigned int m_i10c;
    unsigned int m_i110;
    unsigned int m_i114;
    unsigned int m_i118;
    unsigned int m_i11c;
    unsigned int m_i120;
    unsigned int m_i124;
    unsigned int m_i128;
    unsigned int m_i12c;
    unsigned int m_i130;
    unsigned int m_i134;
    unsigned int m_i138;
    unsigned int m_i13c;
    unsigned int m_i140;
    unsigned int m_i144;
    unsigned int m_i148;
    unsigned int m_i14c;
    unsigned int m_i150;
    unsigned int m_i154;
    unsigned int m_i158;
    unsigned int m_i15c;
    unsigned int m_i160;
    unsigned int m_i164;
    unsigned int m_i168;
    unsigned int m_i16c;
    unsigned int m_i170;
    unsigned int m_i174;
    unsigned int m_i178;
    unsigned int m_i17c;
    unsigned int m_i180;
    unsigned int m_i184;
    unsigned int m_i188;
    unsigned int m_i18c;
    unsigned int m_i190;
    unsigned int m_i194;
    unsigned int m_i198;
    unsigned int m_i19c;
    unsigned int m_i1a0;
    unsigned int m_i1a4;
    unsigned int m_i1a8;
    unsigned int m_i1ac;
    unsigned int m_i1b0;
    unsigned int m_i1b4;
    unsigned int m_i1b8;
    unsigned int m_i1bc;
    unsigned int m_i1c0;
    unsigned int m_i1c4;
    unsigned int m_i1c8;
    unsigned int m_i1cc;
    unsigned int m_i1d0;
    unsigned int m_i1d4;
    unsigned int m_i1d8;
    unsigned int m_i1dc;
    unsigned int m_i1e0;
    unsigned int m_i1e4;
    unsigned int m_i1e8;
    unsigned int m_i1ec;
    unsigned int m_i1f0;
    unsigned int m_i1f4;
    unsigned int m_i1f8;
    unsigned int m_i1fc;
};

int __cdecl CopyAudioNodeTree(SrcNode* apSrc, int aiCount, DstBlock* apDst);

// Allocates a 0x200-byte buffer per source buffer, copies each Buffer512 into the destination block, then recurses into child nodes.
// @fnv 0x00dcd950
int __cdecl CopyAudioNodeTree(SrcNode* apSrc, int aiCount, DstBlock* apDst)
{
    int count = apSrc->m_iArrayLength;
    hkMemoryRouter* pAudioHolder = (hkMemoryRouter*)fnvc_adapt::hkMemoryRouter_getInstance();
    hkMemoryAllocator* alloc = reinterpret_cast<hkMemoryAllocator*>(pAudioHolder->m_heap);
    int cap = (int)(apDst->m_uCapBits & 0x3fffffffu);
    if (cap < count)
    {
        int newCap = cap + cap;
        if (count >= newCap)
        {
            newCap = count;
        }
        hkArrayUtil__reserve(alloc, apDst, (unsigned int)newCap, 4);
    }
    apDst->m_iArrayLength = count;
    for (int i = 0; i < apSrc->m_iArrayLength; ++i)
    {
        hkMemoryRouter* h = (hkMemoryRouter*)fnvc_adapt::hkMemoryRouter_getInstance();
        hkMemoryAllocator* a = reinterpret_cast<hkMemoryAllocator*>(h->m_heap);
        unsigned int* p = (unsigned int*)reinterpret_cast<hkMemoryAllocator*>(a)->blockAlloc(0x200);
        if (p != 0)
        {
            *p = 0;
        }
        else
        {
            p = 0;
        }
        apDst->m_pData[i] = (unsigned int)p;
        Buffer512* d = (Buffer512*)apDst->m_pData[i];
        Buffer512* pSrcBuffer = (Buffer512*)apSrc->m_ppBuffers[i];
        *d = *pSrcBuffer;
    }
    for (int j = 0; j < apSrc->m_iItemCount; ++j)
    {
        SrcNode* item = apSrc->m_ppItems[j];
        unsigned int uiChildAddr = apDst->m_pData[item->m_iIndex] + item->m_iFirstValue + 0x10;
        if (uiChildAddr != 0)
        {
            unsigned int* pChildHeader = (unsigned int*)uiChildAddr;
            pChildHeader[0] = 0;
            pChildHeader[1] = 0;
            pChildHeader[2] = 0x80000000u;
        }
        if (CopyAudioNodeTree(item, aiCount, (DstBlock*)uiChildAddr) == 1)
        {
            return 1;
        }
    }
    return 0;
}

struct CollisionRecordHeader
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char size;
};
struct S_00dcda40_Block
{
    int unk00;
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
    int len;
    unsigned char** starts;
    int count;
};
struct S_00dcda40_Arr
{
    S_00dcda40_Block** data;
    int size;
    int cap;
    void Search(hkMemoryAllocator& h, int idx, void* src, int n);
    __forceinline S_00dcda40_Arr(const S_00dcda40_Arr& other) : data(0), size(0), cap(0x80000000)
    {
        hkMemoryAllocator& heap = fnvc_adapt::hkMemoryRouter_getInstance()->heap();
        if ((cap & 0x3fffffff) < other.size)
        {
            if ((cap & 0x80000000) == 0)
                heap.bufFree(data, (cap & 0x3fffffff) * 4);
            int bytes = other.size * 4;
            data = (S_00dcda40_Block**)heap.bufAlloc(bytes);
            cap = bytes / 4;
        }
        size = other.size;
        S_00dcda40_Block** src = other.data;
        S_00dcda40_Block** dst = data;
        int count = size;
        for (int index = 0; index < count; ++index)
            dst[index] = src[index];
    }
    __forceinline void append(const S_00dcda40_Arr& other)
    {
        int count = other.size;
        void* src = other.data;
        int at = size;
        hkMemoryAllocator& heap = fnvc_adapt::hkMemoryRouter_getInstance()->heap();
        Search(heap, at, src, count);
    }
};
struct S_00dcda40_World
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    S_00dcda40_Arr first;
    S_00dcda40_Arr second;
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
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
};

// @fnv 0x00dcda40
void __cdecl ProcessCollisionRecords(void* arg1, S_00dcda40_World* world, S_00dcdd80_Listener* sink)
{
    S_00dcda40_Arr mergedBlocks(world->first);
    mergedBlocks.append(world->second);
    for (int i = 0; i < mergedBlocks.size; i++)
    {
        for (int j = 0; j < mergedBlocks.data[i]->count;)
        {
            unsigned char* p = mergedBlocks.data[i]->starts[j];
            j++;
            unsigned char* end;
            if (j == mergedBlocks.data[i]->count)
                end = p + mergedBlocks.data[i]->len;
            else
                end = p + 0x200;
            while (p < end)
            {
                FUN_00dce930* r = new FUN_00dce930;
                void* callbackArg = arg1;
                int state = world->unk78;
                if (!hkpSaveContactPointsUtil_serializeCollisionEntry(callbackArg, (S_00dcdd80_Item*)p, state, r))
                    sink->AddObject(r);
                r->FUN_00c905b0();
                p += ((CollisionRecordHeader*)p)->size;
            }
        }
    }
    hkMemoryAllocator& finalHeap = fnvc_adapt::hkMemoryRouter_getInstance()->heap();
    mergedBlocks.size = 0;
    if ((mergedBlocks.cap & 0x80000000) == 0)
        finalHeap.bufFree(mergedBlocks.data, (mergedBlocks.cap & 0x3fffffff) * 4);
}

namespace fnv_00dce8f0 {
namespace fnvc_adapt {
void* hkMemoryRouter_getInstance();
}

class FUN_00cb1a90_out
{
  public:
    FUN_00cb1a90_out(void* p) throw();
};

class SubOfSel : public FUN_00cb1a90_out
{
  public:
    void Object_DoNothing();
    SubOfSel(void* p) throw() : FUN_00cb1a90_out(*(void**)((char*)fnvc_adapt::hkMemoryRouter_getInstance() + 0x10))
    {
        Object_DoNothing();
    }
};

class FUN_00dce8f0 : public SubOfSel
{
  public:
    virtual void VF();
    FUN_00dce8f0(unsigned char flag) throw();
};

// Initializes the SubOfSel base and, when bit 0 of flag is set, deletes this object.
// @fnv 0x00dce8f0
FUN_00dce8f0::FUN_00dce8f0(unsigned char aucFlags) throw() : SubOfSel((void*)0)
{
    if (aucFlags & 1)
        operator delete(this);
}
}  // namespace fnv_00dce8f0

template <typename T> inline void S00dcdf70_construct(T* p, int n, const T& t)
{
    for (int i = 0; i < n; ++i)
    {
        p[i] = t;
    }
}

struct S00dcd720_Bool
{
    char m_cBooleanValue;
};
struct S00dcd720_Part
{
    int u00;
    int u04;
    int u08;
    int u0c;
    signed char m_off;
    char u11;
    char u12;
    char u13;
    int u14;
    char m_type;
};
struct S00dcd720_Hdr
{
    int u00;
    unsigned short m_numA;
    unsigned short m_numB;
    unsigned char u08;
    unsigned char u09;
    unsigned char m_iElementIndex;
    unsigned char u0b;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
    int u24;
    int u28;
    int u2c;
};
struct S00dcd720_Shape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual int v34();
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    char* m_bytes;
    int m_iVertexCount;
    int u28;
    int u2c;
    int u30;
    int u34;
    int u38;
    S00dcd720_Hdr* m_hdr;
};
struct S00dcd720_Src
{
    int u00;
    int u04;
    S00dcd720_Shape* m_pCollisionShape;
    int u0c;
    S00dcd720_Part* m_partA;
    S00dcd720_Part* m_partB;
};
template <class T> struct S00dcd720_Arr;

template <class T> struct S00dcd720_Arr
{
    T* m_data;
    int m_iElementCount;
    int m_capFlags;
    __forceinline void reserve(int n, int sz)
    {
        hkMemoryAllocator& a = _FUN_00c85750()->heap();
        int cap = m_capFlags & 0x3fffffff;
        if (cap < n)
        {
            int cap2 = cap * 2;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(&a, (S00dcd720_Arr<char>*)this, newSize, sz);
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(n, sizeof(T));
        m_iElementCount = n;
    }
};
struct S00dcd720_Elem
{
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
};
struct S00dcd720_Ref
{
    void FUN_00c90510();
};
struct S00dcd720_Out
{
    int u00;
    int u04;
    S00dcd720_Part* m_kPointA;
    S00dcd720_Part* m_kPointB;
    void* m_ca;
    void* m_cb;
    char m_flag;
    char m_cBooleanValue;
    char u1a;
    char u1b;
    int u1c;
    S00dcd720_Hdr m_hdr;
    S00dcd720_Arr<unsigned char> m_arr50;
    S00dcd720_Arr<S00dcd720_Elem> m_arr5c;
    S00dcd720_Arr<char> m_arr68;
    int m_74;
    int u78;
    int u7c;
    int u80;
    int u84;
    int u88;
    int u8c;
    int u90;
    int u94;
    int u98;
    int u9c;
    int ua0;
    int ua4;
    int ua8;
    int uac;
    int ub0;
    int ub4;
    int ub8;
    int ubc;
    int uc0;
    int uc4;
    int uc8;
    int ucc;
    int ud0;
    int ud4;
    int ud8;
    int udc;
    int ue0;
    int ue4;
    int ue8;
    int uec;
    int uf0;
    int uf4;
    int uf8;
    int ufc;
    int u100;
    int u104;
    int u108;
    int u10c;
    int u110;
    int m_context114;
};
struct S00dcd720_Cb
{
    char m_flag;
    void* (*m_fn)(S00dcd720_Part*);
};

BSAudio* __cdecl _FUN_00c85750();

extern "C"
{
    void __cdecl hkArrayUtil__reserve(void* allocator, void* array, int numElements, int elementSize);
}
void __cdecl ResizeAudioStream(void* allocator, void* array, int elementSize);

#include "../../../../../../include/hkArray.h"
// hkArray<T>::reserve (hkArray.inl _reserve) and pushBack as the unit spells them (allocator from the router heap).
template <typename T> static __forceinline void reserve(hkArray<T>& a, hkMemoryAllocator& alloc, int numElements)
{
    int cap = a.m_iCapacityState & 0x3fffffff;
    if (cap < numElements)
    {
        int cap2 = 2 * cap;
        int newCap = (numElements < cap2) ? cap2 : numElements;
        hkArrayUtil__reserve(&alloc, &a, newCap, sizeof(T));
    }
}
template <typename T> static __forceinline void AddBack(hkArray<T>& a, const T& val)
{
    BSAudio* h = _FUN_00c85750();
    if (a.m_iElementCount == (a.m_iCapacityState & 0x3fffffff))
    {
        ResizeAudioStream(&h->heap(), &a, sizeof(T));
    }
    S00dcdf70_construct(a.m_data + a.m_iElementCount, 1, val);
    a.m_iElementCount++;
}

struct Block512
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
    Block512() : unk000(0)
    {}
    static void* operator new(size_t sz)
    {
        return _FUN_00c85750()->heap().blockAlloc(sz);
    }
    static void operator delete(void* p)
    {
        _FUN_00c85750()->heap().blockFree(p, sizeof(Block512));
    }
};

inline int S00dcdf70_byteOffset(const void* base, const void* p)
{
    return (int)((const char*)p - (const char*)base);
}

struct S00dcdf70_Loc
{
    int field18;
    int field1c;
    S00dcdf70_Loc()
    {}
    S00dcdf70_Loc(int a, int b) : field18(a), field1c(b)
    {}
};

struct Struct0x20
{
    hkArray<Block512*> arr1;
    hkArray<Struct0x20*> arr2;
    S00dcdf70_Loc loc;

    Struct0x20()
    {
        loc.field18 = -1;
    }
    ~Struct0x20();

    static void* operator new(size_t sz)
    {
        return _FUN_00c85750()->heap().blockAlloc(sz);
    }
    static void operator delete(void* p)
    {
        _FUN_00c85750()->heap().blockFree(p, sizeof(Struct0x20));
    }
};

int __cdecl hkpSaveContactPointsUtil_serializeEntry(const void* cur, hkBool flag, void* context, int* pItemSize, int* pField18, void** pSubPtr,
                         Struct0x20* child);

// Iterates over chunks, calls FUN_00dcd550 to parse sub-structures, and populates out->arr1 with Block512 copies and out->arr2 with child nodes.
// @fnv 0x00dcdf70
// src: HAVOK_LIB 0x00dcdf70
int __cdecl hkpSaveContactPointsUtil_serialize1nTrack(const hkArray<Block512*>& chunks, void* context, Struct0x20* out)
{
    const char* cur;
    int iNumChunks = chunks.m_iElementCount;
    reserve(out->arr1, _FUN_00c85750()->heap(), iNumChunks);
    for (int i = 0; i < chunks.m_iElementCount; ++i)
    {
        Block512* chunk = chunks.m_data[i];
        cur = (const char*)&chunk->unk010;
        const char* end = (const char*)&chunk->unk010 + chunk->unk000;
        while (cur < end)
        {
            void* subPtr = 0;
            int itemSize = 0;
            int dummy;
            Struct0x20* __restrict child = new Struct0x20();
            if (hkpSaveContactPointsUtil_serializeEntry(cur, hkBool(false), context, &itemSize, &dummy, &subPtr, child) == 0)
            {
                if (child->arr1.m_iElementCount != 0)
                {
                    child->loc.field18 = i;
                    child->loc.field1c = S00dcdf70_byteOffset(&chunk->unk010, subPtr);
                    AddBack<Struct0x20*>(out->arr2, child);
                }
                else
                {
                    delete child;
                }
                cur += itemSize;
            }
            else
            {
                delete child;
                return 1;
            }
        }
        BSAudio* h = _FUN_00c85750();
        if (out->arr1.m_iElementCount == (out->arr1.m_iCapacityState & 0x3fffffff))
        {
            ResizeAudioStream(&h->heap(), &out->arr1, 4);
        }
        out->arr1.m_iElementCount++;
        out->arr1.m_data[i] = new Block512();
        *out->arr1.m_data[i] = *chunk;
    }
    return 0;
}

struct SpawnedItem
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
    unsigned int m_0C;
    unsigned int m_10;
    unsigned int m_14;
    unsigned char m_18;
    unsigned char unk19;
    unsigned char unk1A;
    unsigned char unk1B;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int m_12C;
    void Release();
};

struct Resolver
{
    unsigned char m_00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned int(__cdecl* m_04)(unsigned int);
};

struct Visitor
{
    virtual void v00();
    virtual int v01(unsigned int key);
};

struct ListOwner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    SpawnedItem** m_44;
    int m_48;

    __forceinline void RemoveAt(int i)
    {
        m_44[i]->Release();
        m_48--;
        if (m_48 != i)
        {
            m_44[i] = m_44[m_48];
        }
    }
};

struct Ctx
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int m_78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int m_8C;
    unsigned int m_90;
    int m_94;
    unsigned int unk98;
    unsigned char m_9C;
    unsigned char unk9D;
    unsigned char unk9E;
    unsigned char unk9F;
    unsigned int unkA0;
    unsigned int m_A4;
    void Flush();
    void Tail();
};

void* __cdecl FindEntryValue(unsigned int a, unsigned int b);
void __cdecl SwapMeshRecords(unsigned int a, SpawnedItem* b);
int __cdecl hkpSaveContactPointsUtil_deserializeCollisionEntry(Resolver* a1, SpawnedItem* item, unsigned int edi, unsigned int ebx, unsigned int ctx78,
                         void* p);

// @fnv 0x00dcea10
// src: HAVOK_LIB 0x00dcea10
void __cdecl hkpSaveContactPointsUtil_loadContactPointsInternal(Resolver* apResolver, ListOwner* apListOwner, Ctx* apCtx, Visitor* apVisitor)
{
    apCtx->m_94++;
    for (int i = apListOwner->m_48 - 1; i >= 0; --i)
    {
        SpawnedItem* item = apListOwner->m_44[i];
        unsigned int edi;
        unsigned int ebx;
        if (item->m_18 != 0)
        {
            edi = apResolver->m_04(item->m_10);
            ebx = apResolver->m_04(item->m_14);
        }
        else
        {
            edi = item->m_08;
            ebx = item->m_0C;
        }
        if (edi == 0 || ebx == 0)
            continue;
        if (!apVisitor->v01(edi) && !apVisitor->v01(ebx))
            continue;
        void* p = FindEntryValue(edi + 0x10, ebx + 0x10);
        if (p == 0)
            continue;
        if (item->m_12C != 0x103)
            SwapMeshRecords(apCtx->m_78, item);
        int ok = hkpSaveContactPointsUtil_deserializeCollisionEntry(apResolver, item, edi, ebx, apCtx->m_78, p);
        if (apResolver->m_00 == 0 || ok == 0)
            continue;
        SpawnedItem** d = apListOwner->m_44;
        __assume(d != 0);
        SpawnedItem* r = d[i];
        r->Release();
        apListOwner->m_48--;
        int last = apListOwner->m_48;
        if (last != i)
            apListOwner->m_44[i] = apListOwner->m_44[last];
    }
    if (--apCtx->m_94 != 0)
        return;
    if (apCtx->m_9C != 0)
        return;
    if (apCtx->m_8C != 0)
        apCtx->Flush();
    if (apCtx->m_A4 != 1 || apCtx->m_90 == 0)
        return;
    apCtx->Tail();
}

namespace fnv_00dce9e0 {

BSAudio* hkMemoryRouter_getInstance();

struct FUN_00e05d10_Base
{
    virtual ~FUN_00e05d10_Base();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;

    void operator delete(void* p, unsigned int)
    {
        FUN_00e05d10_Base* b = static_cast<FUN_00e05d10_Base*>(p);
        hkMemoryRouter_getInstance()->heap().blockFree(p, b->m_usMemSizeAndFlags);
    }
};

struct FUN_00dce9e0 : FUN_00e05d10_Base
{
    FUN_00dce9e0(int);
    virtual ~FUN_00dce9e0();
};

// Constructor taking an unused int argument; the written body is empty.
// @fnv 0x00dce9e0
FUN_00dce9e0::FUN_00dce9e0(int)
{}
}  // namespace fnv_00dce9e0

struct AgentKey
{
    void* value;
};
// src: COMMUNITY 0x00dcd4d0
__declspec(noinline) int __cdecl hkpSaveContactPointsUtil_getSerializedAgentType(AgentKey key)
{
    if (key.value == (void*)hkBoxBoxAgent3_process)
        return 1;
    if (key.value == (void*)hkCapsuleTriangleAgent3_process)
        return 2;
    if (key.value == (void*)hkPredGskAgent3_process)
        return 3;
    if (key.value == (void*)hkPredGskCylinderAgent3_process)
        return 4;
    if (key.value == (void*)hkConvexListAgent3_process)
        return 5;
    if (key.value == (void*)BuildEventIndex)
        return 6;
    if (key.value == (void*)hkBvTreeAgent3_process)
        return 7;
    if (key.value == (void*)process_00d35770)
        return 8;
    return key.value == (void*)hkpCollectionAgent3_process ? 9 : 0;
}
extern "C" void* __cdecl Runtime_EvaluateValue_00d32ad0(void*, void*);
extern "C" int __cdecl hkpSaveContactPointsUtil_serialize1nTrack(void*, DCD6A0Context**, int);
// Resolves the collision data pointer and type for a CollisionRecordHeader entry, writing results to output, size, and type out-parameters.
// @fnv 0x00dcd550
// src: HAVOK_LIB 0x00dcd550
int __cdecl hkpSaveContactPointsUtil_serializeEntry(CollisionRecordHeader* apRecord, char abOffset, DCD6A0Context** context, int* size, int* type,
                         void** output, int arg)
{
    *output = 0;
    unsigned char* data;
    switch (apRecord->unk00)
    {
    case 6:
    case 14:
        return 1;
    case 4:
    case 5:
    case 12:
    case 13:
        data = (unsigned char*)apRecord + (abOffset ? 48 : 32);
        goto process;
    case 2:
    case 3:
    case 10:
    case 11:
        data = (unsigned char*)apRecord + (abOffset ? 32 : 16);
    process: {
        AgentKey key = {(void*)(*context)->m_entries[apRecord->unk01].m_key};
        int t = hkpSaveContactPointsUtil_getSerializedAgentType(key);
        *type = t;
        switch (t)
        {
        case 1:
        case 2:
        case 3:
        case 4:
            *type = t;
            *size = apRecord->size;
            return 0;
        case 5:
            *type = t;
            *size = apRecord->size;
            if (data[11] & 32)
                return 0;
            *output = Runtime_EvaluateValue_00d32ad0(apRecord, data);
            return hkpSaveContactPointsUtil_serialize1nTrack(*output, context, arg);
        case 6:
        case 7:
        case 8:
        case 9:
            *size = apRecord->size;
            *type = t;
            *output = data;
            return hkpSaveContactPointsUtil_serialize1nTrack(data, context, arg);
        default:
            return 1;
        }
    }
    case 0:
    case 1:
        *size = 16;
        return 0;
    default:
        return 0;
    }
}

BSAudio* __cdecl _FUN_00c85750();

int hkpSaveContactPointsUtil_serializeEntry(S00dcd720_Src*, S00dcd720_Bool, int, int*, int*, void**, void*);
extern "C" void hkString_memCpy(void*, const void*, int);

static inline S00dcd720_Part* S00dcd720_get(S00dcd720_Part* p)
{
    return (p->m_type == 1) ? (S00dcd720_Part*)((char*)p + p->m_off) : 0;
}

// Calls FUN_00dcd550 on src, then copies shape header and arrays into out and sets the part fields via cb->m_fn or by storing them and calling FUN_00c90510.
// @fnv 0x00dcd720
// src: HAVOK_LIB 0x00dcd720
int __cdecl hkpSaveContactPointsUtil_serializeCollisionEntry(S00dcd720_Cb* cb, S00dcd720_Src* src, int c, S00dcd720_Out* out)
{
    if (src->m_pCollisionShape->v34() != 0 || src->m_pCollisionShape->m_hdr->m_numA <= 0)
        return 1;
    int size = -1;
    int b = 0;
    int r;
    {
        void* decoded;
        S00dcd720_Bool flag;
        flag.m_cBooleanValue = 1;
        r = hkpSaveContactPointsUtil_serializeEntry(src, flag, c, &size, &b, &decoded, &out->m_context114);
    }
    if (r == 0)
    {
        out->m_cBooleanValue = (char)b;
        if (size)
            hkString_memCpy(&out->m_74, src, size);
        S00dcd720_Shape* shape = src->m_pCollisionShape;
        out->m_arr68.SetSizeAndGrow(shape->m_iVertexCount);
        for (int i = 0; i < out->m_arr68.m_iElementCount; i++)
            out->m_arr68.m_data[i] = shape->m_bytes[i];
        S00dcd720_Hdr* hdr = shape->m_hdr;
        out->m_arr50.SetSizeAndGrow(hdr->m_iElementIndex * hdr->m_numA);
        hkString_memCpy(out->m_arr50.m_data, (char*)hdr + hdr->m_numB * 32 + 0x30, hdr->m_iElementIndex * hdr->m_numA);
        out->m_arr5c.SetSizeAndGrow(hdr->m_numA);
        hkString_memCpy(out->m_arr5c.m_data, (char*)hdr + 0x30, hdr->m_numA * 32);
        out->m_hdr = *shape->m_hdr;
        S00dcd720_Part* pPartA = S00dcd720_get(src->m_partA);
        S00dcd720_Part* pPartB = S00dcd720_get(src->m_partB);
        out->m_flag = cb->m_flag;
        char& f = out->m_flag;
        if (f)
        {
            out->m_ca = cb->m_fn(pPartA);
            out->m_cb = cb->m_fn(pPartB);
        }
        else
        {
            out->m_kPointA = pPartA;
            out->m_kPointB = pPartB;
            ((S00dcd720_Ref*)pPartA)->FUN_00c90510();
            ((S00dcd720_Ref*)out->m_kPointB)->FUN_00c90510();
        }
        return 0;
    }
    return 1;
}

struct ResourceDce;

struct ContactDce;
struct BodyDce;
struct CountDce;
struct Big30
{
    int d00;
    int d01;
    int d02;
    int d03;
    int d04;
    int d05;
    int d06;
    int d07;
};
struct NodeF
{
    int u00;
    int u04;
    ResourceDce* m_08;
    int u0c;
    unsigned char m_10;
    char u11;
    char u12;
    char u13;
    int u14;
    unsigned char m_18;
    char u19;
    char u1a;
    char u1b;
    int u1c;
};
struct CountInfoDce
{
    int maximum;
    int bytes;
    int objects;
    int headers;
    void clear()
    {
        maximum = 0;
        bytes = 0;
        objects = 0;
        headers = 0;
    }
};
struct SubH
{
    int u00;
    BodyDce* m_kNodeCollection[2];
    int m_0c;
    unsigned short m_10;
    unsigned short u12;
    unsigned short m_14w;
    unsigned short m_16;
    unsigned short m_18;
    unsigned char m_1a;
    char u1b;
    int u1c;
    BodyDce* getMasterEntity() const
    {
        return m_kNodeCollection[m_1a];
    }
    void subConstraintInfo(const CountInfoDce& delta)
    {
        unsigned int numSolverResults = m_16 - delta.objects;
        unsigned int numSolverElemTemps = m_18 - delta.headers;
        unsigned int sizeOfSchemas = m_14w - delta.bytes;
        m_16 = (unsigned short)numSolverResults;
        m_18 = (unsigned short)numSolverElemTemps;
        m_14w = (unsigned short)sizeOfSchemas;
    }
    void AddConstraintToCriticalSection(const CountInfoDce& delta)
    {
        unsigned int numSolverResults = m_16 + delta.objects;
        unsigned int numSolverElemTemps = m_18 + delta.headers;
        unsigned int sizeOfSchemas = m_14w + delta.bytes;
        m_16 = (unsigned short)numSolverResults;
        m_18 = (unsigned short)numSolverElemTemps;
        m_14w = (unsigned short)sizeOfSchemas;
    }
};
struct DataEntryDce
{
    int u00;
    int u04;
    int m_08;
};
struct NodeG
{
    unsigned short u00;
    unsigned short m_02;
    unsigned short m_04;
    unsigned short m_06;
    unsigned short u08;
    unsigned char m_0a;
    char u0b;
    int u0c;
    Big30 m_block;
    void addToConstraintInfo(CountInfoDce& infoOut) const
    {
        int size = m_04;
        infoOut.bytes += 0x80 + (size >> 1) * 0x70 + (size & 1) * 0x30;
        infoOut.maximum = infoOut.bytes + 0x20;
        infoOut.objects += size + 2;
        infoOut.headers += size + (2 + 1);
        if (size >= 2)
        {
            infoOut.bytes += 0x20;
            infoOut.objects += 1;
            infoOut.headers += 1 + 0;
        }
    }
    DataEntryDce* entries()
    {
        return reinterpret_cast<DataEntryDce*>(reinterpret_cast<char*>(this + 1) + (m_06 << 5));
    }
};
struct S00dce180_Instance
{
    int vt00;
    int u04;
    int u08;
    int u0c;
    int u10;
    void* m_kActorEntries[2];
    int u1c;
    int u20;
    int u24;
    int u28;
    int u2c;
    SubH* m_pConstraintInternal;
    BodyDce* getMasterEntity() const
    {
        return m_pConstraintInternal->getMasterEntity();
    }
};
template <typename T> __forceinline void S00dce180_swap(T& x, T& y)
{
    T t(x);
    x = y;
    y = t;
}
struct BytesDce
{
    char* data;
    int size;
    int capacity;
    void reserve(hkMemoryAllocator& alloc, int count);
    void resize(int count);
};
struct WorkObj
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
    virtual ContactDce* contact(int id);
    virtual void* properties(int id);
    virtual void enumerate(hkArrayBase<unsigned short>* out);
    int u04;
    int m_08;
    int u0c;
    unsigned short u10;
    unsigned short m_12;
    int u14;
    int u18;
    int u1c;
    BytesDce bytes;
    int u2c;
    int u30;
    int u34;
    int u38;
    NodeG* m_3c;
    int u40;
    S00dce180_Instance m_pHavokConstraint;
};
struct Arg0
{
    char u00;
    unsigned char m_01;
    char u02;
    char u03;
    int u04;
    unsigned char m_08;
    unsigned char m_09;
    unsigned char m_0a;
    char u0b;
    int u0c;
};
struct NodeDce
{
    int u000;
    int u004;
    void* m_008;
    int u00c;
    int u010;
    int u014;
    unsigned char u018;
    signed char m_019;
    unsigned short u01a;
    int u01c;
    int u020;
    unsigned short m_024;
    unsigned char u026;
    unsigned char u027;
    unsigned char m_028;
    unsigned char m_029;
    unsigned short u02a;
    unsigned short m_02c;
    unsigned short u02e;
    Big30 m_030;
    void* m_050;
    int u054;
    int u058;
    void* m_05c;
    int u060;
    int u064;
    char* m_068;
    int m_06c;
    int u070;
    int u074;
    int u078;
    int u07c;
    int u080;
    int u084;
    int u088;
    int u08c;
    int u090;
    int u094;
    int u098;
    int u09c;
    int u0a0;
    int u0a4;
    int u0a8;
    int u0ac;
    int u0b0;
    int u0b4;
    int u0b8;
    int u0bc;
    int u0c0;
    int u0c4;
    int u0c8;
    int m_0cc;
    int u0d0;
    int u0d4;
    int u0d8;
    int u0dc;
    int u0e0;
    int u0e4;
    unsigned char m_0e8;
    char u0e9;
    char u0ea;
    char u0eb;
    int u0ec;
    int u0f0;
    int u0f4;
    int u0f8;
    int u0fc;
    int u100;
    int u104;
    int u108;
    int u10c;
    int u110;
    int unk0114;
    int unk0118;
    int unk011c;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012c;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013c;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014c;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015c;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016c;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017c;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018c;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019c;
    int unk01a0;
    int unk01a4;
    int unk01a8;
    int unk01ac;
    int unk01b0;
    int unk01b4;
    int unk01b8;
    int unk01bc;
    int unk01c0;
    int unk01c4;
    int unk01c8;
    int unk01cc;
    int unk01d0;
    int unk01d4;
    int unk01d8;
    int unk01dc;
    int unk01e0;
    int unk01e4;
    int unk01e8;
    int unk01ec;
    int unk01f0;
    int unk01f4;
    int unk01f8;
    int unk01fc;
    int unk0200;
    unsigned short m_204;
};
struct P5
{
    unsigned short m_00;
    unsigned short u02;
    unsigned short m_04;
    unsigned short m_06;
    WorkObj* m_08;
    int u0c;
    NodeF* m_10;
    NodeF* m_14;
    int u18;
};
struct CountDataDce
{
    int u00;
    int bytes;
    int objects;
    int headers;
    void add(const CountInfoDce& d)
    {
        u00 = u00 > d.maximum ? u00 : d.maximum;
        u00 = u00 > d.bytes ? u00 : d.bytes;
        bytes += d.bytes;
        objects += d.objects;
        headers += d.headers;
    }
    CountDataDce& subtract(const CountInfoDce& d)
    {
        bytes -= d.bytes;
        objects -= d.objects;
        headers -= d.headers;
        return *this;
    }
};
struct CountDce
{
    int u00;
    int u04;
    CountDataDce data;
    inline void AccumulateStats(struct S00dce180_Instance* constraint, CountInfoDce& delta);
    inline void subConstraintInfo(struct S00dce180_Instance* constraint, CountInfoDce& delta);
};
struct BodyDce
{
    int u000;
    int u004;
    int u008;
    int u00c;
    int u010;
    int u014;
    int u018;
    int u01c;
    int u020;
    int u024;
    int u028;
    int u02c;
    int u030;
    int u034;
    int u038;
    int u03c;
    int u040;
    int u044;
    int u048;
    int u04c;
    int u050;
    int u054;
    int u058;
    int u05c;
    int u060;
    int u064;
    int u068;
    int u06c;
    int u070;
    int u074;
    int u078;
    int u07c;
    int u080;
    int u084;
    int u088;
    int u08c;
    int u090;
    int u094;
    int u098;
    int u09c;
    int u0a0;
    int u0a4;
    int u0a8;
    int u0ac;
    int u0b0;
    int u0b4;
    int u0b8;
    int u0bc;
    int u0c0;
    int u0c4;
    int u0c8;
    CountDce* m_counts;
    CountDce* GetSimulationIsland() const
    {
        return m_counts;
    }
};
struct ResourceDce
{
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
    int u24;
    int u28;
    int u2c;
    int u30;
    int u34;
    int u38;
    int u3c;
    int u40;
    int u44;
    int u48;
    int u4c;
    int u50;
    int u54;
    int u58;
    int u5c;
    int u60;
    int u64;
    int u68;
    int u6c;
    int u70;
    int u74;
    int u78;
    int u7c;
    int u80;
    int u84;
    int u88;
    int u8c;
    int u90;
    int m_94;
    int u98;
    unsigned char m_9c;
};
struct ContactDce
{
    int u00;
    int u04;
    int u08;
    unsigned char u0c;
    unsigned char u0d;
    unsigned char u0e;
    unsigned char m_0f;
    int u10;
    int m_14;
};

namespace DceAccess {
extern "C" BSAudio* hkMemoryRouter_getInstance();
}

struct ContactListDce
{
    ContactDce* current;
    hkArrayBase<unsigned short> ids;
};
struct OutputDce;
struct InputDce
{
    void* m_00;
    void* m_04;
    int m_08;
    int m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    float m_1c;
    int m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    unsigned short m_30;
    unsigned short m_32;
    InputDce(void* const& ta, void* tb, WorkObj* work, int id, void* context, OutputDce* output, ContactDce*& saved);
};
extern "C" float DAT_0104da48;
struct __declspec(align(16)) OutputDce
{
    int m_0000;
    int m_0004;
    int m_0008;
    int m_000c;
    int m_0010;
    int m_0014;
    int m_0018;
    int m_001c;
    int m_0020;
    int m_0024;
    int m_0028;
    int m_002c;
    int m_0030;
    int m_0034;
    int m_0038;
    int m_003c;
    int m_0040;
    int m_0044;
    int m_0048;
    int m_004c;
    int m_0050;
    int m_0054;
    int m_0058;
    int m_005c;
    int m_0060;
    int m_0064;
    int m_0068;
    int m_006c;
    int m_0070;
    int m_0074;
    int m_0078;
    int m_007c;
    int m_0080;
    int m_0084;
    int m_0088;
    int m_008c;
    int m_0090;
    int m_0094;
    int m_0098;
    int m_009c;
    int m_00a0;
    int m_00a4;
    int m_00a8;
    int m_00ac;
    int m_00b0;
    int m_00b4;
    int m_00b8;
    int m_00bc;
    int m_00c0;
    int m_00c4;
    int m_00c8;
    int m_00cc;
    int m_00d0;
    int m_00d4;
    int m_00d8;
    int m_00dc;
    int m_00e0;
    int m_00e4;
    int m_00e8;
    int m_00ec;
    int m_00f0;
    int m_00f4;
    int m_00f8;
    int m_00fc;
    int m_0100;
    int m_0104;
    int m_0108;
    int m_010c;
    int m_0110;
    int m_0114;
    int m_0118;
    int m_011c;
    int m_0120;
    int m_0124;
    int m_0128;
    int m_012c;
    int m_0130;
    int m_0134;
    int m_0138;
    int m_013c;
    int m_0140;
    int m_0144;
    int m_0148;
    int m_014c;
    int m_0150;
    int m_0154;
    int m_0158;
    int m_015c;
    int m_0160;
    int m_0164;
    int m_0168;
    int m_016c;
    int m_0170;
    int m_0174;
    int m_0178;
    int m_017c;
    int m_0180;
    int m_0184;
    int m_0188;
    int m_018c;
    int m_0190;
    int m_0194;
    int m_0198;
    int m_019c;
    int m_01a0;
    int m_01a4;
    int m_01a8;
    int m_01ac;
    int m_01b0;
    int m_01b4;
    int m_01b8;
    int m_01bc;
    int m_01c0;
    int m_01c4;
    int m_01c8;
    int m_01cc;
    int m_01d0;
    int m_01d4;
    int m_01d8;
    int m_01dc;
    int m_01e0;
    int m_01e4;
    int m_01e8;
    int m_01ec;
    int m_01f0;
    int m_01f4;
    int m_01f8;
    int m_01fc;
    int m_0200;
    int m_0204;
    int m_0208;
    int m_020c;
    int m_0210;
    int m_0214;
    int m_0218;
    int m_021c;
    int m_0220;
    int m_0224;
    int m_0228;
    int m_022c;
    int m_0230;
    int m_0234;
    int m_0238;
    int m_023c;
    int m_0240;
    int m_0244;
    int m_0248;
    int m_024c;
    int m_0250;
    int m_0254;
    int m_0258;
    int m_025c;
    int m_0260;
    int m_0264;
    int m_0268;
    int m_026c;
    int m_0270;
    int m_0274;
    int m_0278;
    int m_027c;
    int m_0280;
    int m_0284;
    int m_0288;
    int m_028c;
    int m_0290;
    int m_0294;
    int m_0298;
    int m_029c;
    int m_02a0;
    int m_02a4;
    int m_02a8;
    int m_02ac;
    int m_02b0;
    int m_02b4;
    int m_02b8;
    int m_02bc;
    int m_02c0;
    int m_02c4;
    int m_02c8;
    int m_02cc;
    int m_02d0;
    int m_02d4;
    int m_02d8;
    int m_02dc;
    int m_02e0;
    int m_02e4;
    int m_02e8;
    int m_02ec;
    int m_02f0;
    int m_02f4;
    int m_02f8;
    int m_02fc;
    int m_0300;
    int m_0304;
    int m_0308;
    int m_030c;
    int m_0310;
    int m_0314;
    int m_0318;
    int m_031c;
    int m_0320;
    int m_0324;
    int m_0328;
    int m_032c;
    int m_0330;
    int m_0334;
    int m_0338;
    int m_033c;
    int m_0340;
    int m_0344;
    int m_0348;
    int m_034c;
    int m_0350;
    int m_0354;
    int m_0358;
    int m_035c;
    int m_0360;
    int m_0364;
    int m_0368;
    int m_036c;
    int m_0370;
    int m_0374;
    int m_0378;
    int m_037c;
    int m_0380;
    int m_0384;
    int m_0388;
    int m_038c;
    int m_0390;
    int m_0394;
    int m_0398;
    int m_039c;
    int m_03a0;
    int m_03a4;
    int m_03a8;
    int m_03ac;
    int m_03b0;
    int m_03b4;
    int m_03b8;
    int m_03bc;
    int m_03c0;
    int m_03c4;
    int m_03c8;
    int m_03cc;
    int m_03d0;
    int m_03d4;
    int m_03d8;
    int m_03dc;
    int m_03e0;
    int m_03e4;
    int m_03e8;
    int m_03ec;
    int m_03f0;
    int m_03f4;
    int m_03f8;
    int m_03fc;
    int m_0400;
    int m_0404;
    int m_0408;
    int m_040c;
    int m_0410;
    int m_0414;
    int m_0418;
    int m_041c;
    int m_0420;
    int m_0424;
    int m_0428;
    int m_042c;
    int m_0430;
    int m_0434;
    int m_0438;
    int m_043c;
    int m_0440;
    int m_0444;
    int m_0448;
    int m_044c;
    int m_0450;
    int m_0454;
    int m_0458;
    int m_045c;
    int m_0460;
    int m_0464;
    int m_0468;
    int m_046c;
    int m_0470;
    int m_0474;
    int m_0478;
    int m_047c;
    int m_0480;
    int m_0484;
    int m_0488;
    int m_048c;
    int m_0490;
    int m_0494;
    int m_0498;
    int m_049c;
    int m_04a0;
    int m_04a4;
    int m_04a8;
    int m_04ac;
    int m_04b0;
    int m_04b4;
    int m_04b8;
    int m_04bc;
    int m_04c0;
    int m_04c4;
    int m_04c8;
    int m_04cc;
    int m_04d0;
    int m_04d4;
    int m_04d8;
    int m_04dc;
    int m_04e0;
    int m_04e4;
    int m_04e8;
    int m_04ec;
    int m_04f0;
    int m_04f4;
    int m_04f8;
    int m_04fc;
    int m_0500;
    int m_0504;
    int m_0508;
    int m_050c;
    int m_0510;
    int m_0514;
    int m_0518;
    int m_051c;
    int m_0520;
    int m_0524;
    int m_0528;
    int m_052c;
    int m_0530;
    int m_0534;
    int m_0538;
    int m_053c;
    int m_0540;
    int m_0544;
    int m_0548;
    int m_054c;
    int m_0550;
    int m_0554;
    int m_0558;
    int m_055c;
    int m_0560;
    int m_0564;
    int m_0568;
    int m_056c;
    int m_0570;
    int m_0574;
    int m_0578;
    int m_057c;
    int m_0580;
    int m_0584;
    int m_0588;
    int m_058c;
    int m_0590;
    int m_0594;
    int m_0598;
    int m_059c;
    int m_05a0;
    int m_05a4;
    int m_05a8;
    int m_05ac;
    int m_05b0;
    int m_05b4;
    int m_05b8;
    int m_05bc;
    int m_05c0;
    int m_05c4;
    int m_05c8;
    int m_05cc;
    int m_05d0;
    int m_05d4;
    int m_05d8;
    int m_05dc;
    int m_05e0;
    int m_05e4;
    int m_05e8;
    int m_05ec;
    int m_05f0;
    int m_05f4;
    int m_05f8;
    int m_05fc;
    int m_0600;
    int m_0604;
    int m_0608;
    int m_060c;
    int m_0610;
    int m_0614;
    int m_0618;
    int m_061c;
    int m_0620;
    int m_0624;
    int m_0628;
    int m_062c;
    int m_0630;
    int m_0634;
    int m_0638;
    int m_063c;
    int m_0640;
    int m_0644;
    int m_0648;
    int m_064c;
    int m_0650;
    int m_0654;
    int m_0658;
    int m_065c;
    int m_0660;
    int m_0664;
    int m_0668;
    int m_066c;
    int m_0670;
    int m_0674;
    int m_0678;
    int m_067c;
    int m_0680;
    int m_0684;
    int m_0688;
    int m_068c;
    int m_0690;
    int m_0694;
    int m_0698;
    int m_069c;
    int m_06a0;
    int m_06a4;
    int m_06a8;
    int m_06ac;
    int m_06b0;
    int m_06b4;
    int m_06b8;
    int m_06bc;
    int m_06c0;
    int m_06c4;
    int m_06c8;
    int m_06cc;
    int m_06d0;
    int m_06d4;
    int m_06d8;
    int m_06dc;
    int m_06e0;
    int m_06e4;
    int m_06e8;
    int m_06ec;
    int m_06f0;
    int m_06f4;
    int m_06f8;
    int m_06fc;
    int m_0700;
    int m_0704;
    int m_0708;
    int m_070c;
    int m_0710;
    int m_0714;
    int m_0718;
    int m_071c;
    int m_0720;
    int m_0724;
    int m_0728;
    int m_072c;
    int m_0730;
    int m_0734;
    int m_0738;
    int m_073c;
    int m_0740;
    int m_0744;
    int m_0748;
    int m_074c;
    int m_0750;
    int m_0754;
    int m_0758;
    int m_075c;
    int m_0760;
    int m_0764;
    int m_0768;
    int m_076c;
    int m_0770;
    int m_0774;
    int m_0778;
    int m_077c;
    int m_0780;
    int m_0784;
    int m_0788;
    int m_078c;
    int m_0790;
    int m_0794;
    int m_0798;
    int m_079c;
    int m_07a0;
    int m_07a4;
    int m_07a8;
    int m_07ac;
    int m_07b0;
    int m_07b4;
    int m_07b8;
    int m_07bc;
    int m_07c0;
    int m_07c4;
    int m_07c8;
    int m_07cc;
    int m_07d0;
    int m_07d4;
    int m_07d8;
    int m_07dc;
    int m_07e0;
    int m_07e4;
    int m_07e8;
    int m_07ec;
    int m_07f0;
    int m_07f4;
    int m_07f8;
    int m_07fc;
    int m_0800;
    int m_0804;
    int m_0808;
    int m_080c;
    int m_0810;
    int m_0814;
    int m_0818;
    int m_081c;
    int m_0820;
    int m_0824;
    int m_0828;
    int m_082c;
    int m_0830;
    int m_0834;
    int m_0838;
    int m_083c;
    int m_0840;
    int m_0844;
    int m_0848;
    int m_084c;
    int m_0850;
    int m_0854;
    int m_0858;
    int m_085c;
    int m_0860;
    int m_0864;
    int m_0868;
    int m_086c;
    int m_0870;
    int m_0874;
    int m_0878;
    int m_087c;
    int m_0880;
    int m_0884;
    int m_0888;
    int m_088c;
    int m_0890;
    int m_0894;
    int m_0898;
    int m_089c;
    int m_08a0;
    int m_08a4;
    int m_08a8;
    int m_08ac;
    int m_08b0;
    int m_08b4;
    int m_08b8;
    int m_08bc;
    int m_08c0;
    int m_08c4;
    int m_08c8;
    int m_08cc;
    int m_08d0;
    int m_08d4;
    int m_08d8;
    int m_08dc;
    int m_08e0;
    int m_08e4;
    int m_08e8;
    int m_08ec;
    int m_08f0;
    int m_08f4;
    int m_08f8;
    int m_08fc;
    int m_0900;
    int m_0904;
    int m_0908;
    int m_090c;
    int m_0910;
    int m_0914;
    int m_0918;
    int m_091c;
    int m_0920;
    int m_0924;
    int m_0928;
    int m_092c;
    int m_0930;
    int m_0934;
    int m_0938;
    int m_093c;
    int m_0940;
    int m_0944;
    int m_0948;
    int m_094c;
    int m_0950;
    int m_0954;
    int m_0958;
    int m_095c;
    int m_0960;
    int m_0964;
    int m_0968;
    int m_096c;
    int m_0970;
    int m_0974;
    int m_0978;
    int m_097c;
    int m_0980;
    int m_0984;
    int m_0988;
    int m_098c;
    int m_0990;
    int m_0994;
    int m_0998;
    int m_099c;
    int m_09a0;
    int m_09a4;
    int m_09a8;
    int m_09ac;
    int m_09b0;
    int m_09b4;
    int m_09b8;
    int m_09bc;
    int m_09c0;
    int m_09c4;
    int m_09c8;
    int m_09cc;
    int m_09d0;
    int m_09d4;
    int m_09d8;
    int m_09dc;
    int m_09e0;
    int m_09e4;
    int m_09e8;
    int m_09ec;
    int m_09f0;
    int m_09f4;
    int m_09f8;
    int m_09fc;
    int m_0a00;
    int m_0a04;
    int m_0a08;
    int m_0a0c;
    int m_0a10;
    int m_0a14;
    int m_0a18;
    int m_0a1c;
    int m_0a20;
    int m_0a24;
    int m_0a28;
    int m_0a2c;
    int m_0a30;
    int m_0a34;
    int m_0a38;
    int m_0a3c;
    int m_0a40;
    int m_0a44;
    int m_0a48;
    int m_0a4c;
    int m_0a50;
    int m_0a54;
    int m_0a58;
    int m_0a5c;
    int m_0a60;
    int m_0a64;
    int m_0a68;
    int m_0a6c;
    int m_0a70;
    int m_0a74;
    int m_0a78;
    int m_0a7c;
    int m_0a80;
    int m_0a84;
    int m_0a88;
    int m_0a8c;
    int m_0a90;
    int m_0a94;
    int m_0a98;
    int m_0a9c;
    int m_0aa0;
    int m_0aa4;
    int m_0aa8;
    int m_0aac;
    int m_0ab0;
    int m_0ab4;
    int m_0ab8;
    int m_0abc;
    int m_0ac0;
    int m_0ac4;
    int m_0ac8;
    int m_0acc;
    int m_0ad0;
    int m_0ad4;
    int m_0ad8;
    int m_0adc;
    int m_0ae0;
    int m_0ae4;
    int m_0ae8;
    int m_0aec;
    int m_0af0;
    int m_0af4;
    int m_0af8;
    int m_0afc;
    int m_0b00;
    int m_0b04;
    int m_0b08;
    int m_0b0c;
    int m_0b10;
    int m_0b14;
    int m_0b18;
    int m_0b1c;
    int m_0b20;
    int m_0b24;
    int m_0b28;
    int m_0b2c;
    int m_0b30;
    int m_0b34;
    int m_0b38;
    int m_0b3c;
    int m_0b40;
    int m_0b44;
    int m_0b48;
    int m_0b4c;
    int m_0b50;
    int m_0b54;
    int m_0b58;
    int m_0b5c;
    int m_0b60;
    int m_0b64;
    int m_0b68;
    int m_0b6c;
    int m_0b70;
    int m_0b74;
    int m_0b78;
    int m_0b7c;
    int m_0b80;
    int m_0b84;
    int m_0b88;
    int m_0b8c;
    int m_0b90;
    int m_0b94;
    int m_0b98;
    int m_0b9c;
    int m_0ba0;
    int m_0ba4;
    int m_0ba8;
    int m_0bac;
    int m_0bb0;
    int m_0bb4;
    int m_0bb8;
    int m_0bbc;
    int m_0bc0;
    int m_0bc4;
    int m_0bc8;
    int m_0bcc;
    int m_0bd0;
    int m_0bd4;
    int m_0bd8;
    int m_0bdc;
    int m_0be0;
    int m_0be4;
    int m_0be8;
    int m_0bec;
    int m_0bf0;
    int m_0bf4;
    int m_0bf8;
    int m_0bfc;
    int m_0c00;
    int m_0c04;
    int m_0c08;
    int m_0c0c;
    int m_0c10;
    int m_0c14;
    int m_0c18;
    int m_0c1c;
    int m_0c20;
    int m_0c24;
    int m_0c28;
    int m_0c2c;
    int m_0c30;
    int m_0c34;
    int m_0c38;
    int m_0c3c;
    int m_0c40;
    int m_0c44;
    int m_0c48;
    int m_0c4c;
    int m_0c50;
    int m_0c54;
    int m_0c58;
    int m_0c5c;
    int m_0c60;
    int m_0c64;
    int m_0c68;
    int m_0c6c;
    int m_0c70;
    int m_0c74;
    int m_0c78;
    int m_0c7c;
    int m_0c80;
    int m_0c84;
    int m_0c88;
    int m_0c8c;
    int m_0c90;
    int m_0c94;
    int m_0c98;
    int m_0c9c;
    int m_0ca0;
    int m_0ca4;
    int m_0ca8;
    int m_0cac;
    int m_0cb0;
    int m_0cb4;
    int m_0cb8;
    int m_0cbc;
    int m_0cc0;
    int m_0cc4;
    int m_0cc8;
    int m_0ccc;
    int m_0cd0;
    int m_0cd4;
    int m_0cd8;
    int m_0cdc;
    int m_0ce0;
    int m_0ce4;
    int m_0ce8;
    int m_0cec;
    int m_0cf0;
    int m_0cf4;
    int m_0cf8;
    int m_0cfc;
    int m_0d00;
    int m_0d04;
    int m_0d08;
    int m_0d0c;
    int m_0d10;
    int m_0d14;
    int m_0d18;
    int m_0d1c;
    int m_0d20;
    int m_0d24;
    int m_0d28;
    int m_0d2c;
    int m_0d30;
    int m_0d34;
    int m_0d38;
    int m_0d3c;
    int m_0d40;
    int m_0d44;
    int m_0d48;
    int m_0d4c;
    int m_0d50;
    int m_0d54;
    int m_0d58;
    int m_0d5c;
    int m_0d60;
    int m_0d64;
    int m_0d68;
    int m_0d6c;
    int m_0d70;
    int m_0d74;
    int m_0d78;
    int m_0d7c;
    int m_0d80;
    int m_0d84;
    int m_0d88;
    int m_0d8c;
    int m_0d90;
    int m_0d94;
    int m_0d98;
    int m_0d9c;
    int m_0da0;
    int m_0da4;
    int m_0da8;
    int m_0dac;
    int m_0db0;
    int m_0db4;
    int m_0db8;
    int m_0dbc;
    int m_0dc0;
    int m_0dc4;
    int m_0dc8;
    int m_0dcc;
    int m_0dd0;
    int m_0dd4;
    int m_0dd8;
    int m_0ddc;
    int m_0de0;
    int m_0de4;
    int m_0de8;
    int m_0dec;
    int m_0df0;
    int m_0df4;
    int m_0df8;
    int m_0dfc;
    int m_0e00;
    int m_0e04;
    int m_0e08;
    int m_0e0c;
    int m_0e10;
    int m_0e14;
    int m_0e18;
    int m_0e1c;
    int m_0e20;
    int m_0e24;
    int m_0e28;
    int m_0e2c;
    int m_0e30;
    int m_0e34;
    int m_0e38;
    int m_0e3c;
    int m_0e40;
    int m_0e44;
    int m_0e48;
    int m_0e4c;
    int m_0e50;
    int m_0e54;
    int m_0e58;
    int m_0e5c;
    int m_0e60;
    int m_0e64;
    int m_0e68;
    int m_0e6c;
    int m_0e70;
    int m_0e74;
    int m_0e78;
    int m_0e7c;
    int m_0e80;
    int m_0e84;
    int m_0e88;
    int m_0e8c;
    int m_0e90;
    int m_0e94;
    int m_0e98;
    int m_0e9c;
    int m_0ea0;
    int m_0ea4;
    int m_0ea8;
    int m_0eac;
    int m_0eb0;
    int m_0eb4;
    int m_0eb8;
    int m_0ebc;
    int m_0ec0;
    int m_0ec4;
    int m_0ec8;
    int m_0ecc;
    int m_0ed0;
    int m_0ed4;
    int m_0ed8;
    int m_0edc;
    int m_0ee0;
    int m_0ee4;
    int m_0ee8;
    int m_0eec;
    int m_0ef0;
    int m_0ef4;
    int m_0ef8;
    int m_0efc;
    int m_0f00;
    int m_0f04;
    int m_0f08;
    int m_0f0c;
    int m_0f10;
    int m_0f14;
    int m_0f18;
    int m_0f1c;
    int m_0f20;
    int m_0f24;
    int m_0f28;
    int m_0f2c;
    int m_0f30;
    int m_0f34;
    int m_0f38;
    int m_0f3c;
    int m_0f40;
    int m_0f44;
    int m_0f48;
    int m_0f4c;
    int m_0f50;
    int m_0f54;
    int m_0f58;
    int m_0f5c;
    int m_0f60;
    int m_0f64;
    int m_0f68;
    int m_0f6c;
    int m_0f70;
    int m_0f74;
    int m_0f78;
    int m_0f7c;
    int m_0f80;
    int m_0f84;
    int m_0f88;
    int m_0f8c;
    int m_0f90;
    int m_0f94;
    int m_0f98;
    int m_0f9c;
    int m_0fa0;
    int m_0fa4;
    int m_0fa8;
    int m_0fac;
    int m_0fb0;
    int m_0fb4;
    int m_0fb8;
    int m_0fbc;
    int m_0fc0;
    int m_0fc4;
    int m_0fc8;
    int m_0fcc;
    int m_0fd0;
    int m_0fd4;
    int m_0fd8;
    int m_0fdc;
    int m_0fe0;
    int m_0fe4;
    int m_0fe8;
    int m_0fec;
    int m_0ff0;
    int m_0ff4;
    int m_0ff8;
    int m_0ffc;
    int m_1000;
    int m_1004;
    int m_1008;
    int m_100c;
    int m_1010;
    int m_1014;
    int m_1018;
    int m_101c;
    int m_1020;
    int m_1024;
    int m_1028;
    int m_102c;
    int m_1030;
    int m_1034;
    int m_1038;
    int m_103c;
    int m_1040;
    int m_1044;
    int m_1048;
    int m_104c;
    int m_1050;
    int m_1054;
    int m_1058;
    int m_105c;
    int m_1060;
    int m_1064;
    int m_1068;
    int m_106c;
    int m_1070;
    int m_1074;
    int m_1078;
    int m_107c;
    int m_1080;
    int m_1084;
    int m_1088;
    int m_108c;
    int m_1090;
    int m_1094;
    int m_1098;
    int m_109c;
    int m_10a0;
    int m_10a4;
    int m_10a8;
    int m_10ac;
    int m_10b0;
    int m_10b4;
    int m_10b8;
    int m_10bc;
    int m_10c0;
    int m_10c4;
    int m_10c8;
    int m_10cc;
    int m_10d0;
    int m_10d4;
    int m_10d8;
    int m_10dc;
    int m_10e0;
    int m_10e4;
    int m_10e8;
    int m_10ec;
    int m_10f0;
    int m_10f4;
    int m_10f8;
    int m_10fc;
    int m_1100;
    int m_1104;
    int m_1108;
    int m_110c;
    int m_1110;
    int m_1114;
    int m_1118;
    int m_111c;
    int m_1120;
    int m_1124;
    int m_1128;
    int m_112c;
    int m_1130;
    int m_1134;
    int m_1138;
    int m_113c;
    int m_1140;
    int m_1144;
    int m_1148;
    int m_114c;
    int m_1150;
    int m_1154;
    int m_1158;
    int m_115c;
    int m_1160;
    int m_1164;
    int m_1168;
    int m_116c;
    int m_1170;
    int m_1174;
    int m_1178;
    int m_117c;
    int m_1180;
    int m_1184;
    int m_1188;
    int m_118c;
    int m_1190;
    int m_1194;
    int m_1198;
    int m_119c;
    int m_11a0;
    int m_11a4;
    int m_11a8;
    int m_11ac;
    int m_11b0;
    int m_11b4;
    int m_11b8;
    int m_11bc;
    int m_11c0;
    int m_11c4;
    int m_11c8;
    int m_11cc;
    int m_11d0;
    int m_11d4;
    int m_11d8;
    int m_11dc;
    int m_11e0;
    int m_11e4;
    int m_11e8;
    int m_11ec;
    int m_11f0;
    int m_11f4;
    int m_11f8;
    int m_11fc;
    int m_1200;
    int m_1204;
    int m_1208;
    int m_120c;
    int m_1210;
    int m_1214;
    int m_1218;
    int m_121c;
    int m_1220;
    int m_1224;
    int m_1228;
    int m_122c;
    int m_1230;
    int m_1234;
    int m_1238;
    int m_123c;
    int m_1240;
    int m_1244;
    int m_1248;
    int m_124c;
    int m_1250;
    int m_1254;
    int m_1258;
    int m_125c;
    int m_1260;
    int m_1264;
    int m_1268;
    int m_126c;
    int m_1270;
    int m_1274;
    int m_1278;
    int m_127c;
    int m_1280;
    int m_1284;
    int m_1288;
    int m_128c;
    int m_1290;
    int m_1294;
    int m_1298;
    int m_129c;
    int m_12a0;
    int m_12a4;
    int m_12a8;
    int m_12ac;
    int m_12b0;
    int m_12b4;
    int m_12b8;
    int m_12bc;
    int m_12c0;
    int m_12c4;
    int m_12c8;
    int m_12cc;
    int m_12d0;
    int m_12d4;
    int m_12d8;
    int m_12dc;
    int m_12e0;
    int m_12e4;
    int m_12e8;
    int m_12ec;
    int m_12f0;
    int m_12f4;
    int m_12f8;
    int m_12fc;
    int m_1300;
    int m_1304;
    int m_1308;
    int m_130c;
    int m_1310;
    int m_1314;
    int m_1318;
    int m_131c;
    int m_1320;
    int m_1324;
    int m_1328;
    int m_132c;
    int m_1330;
    int m_1334;
    int m_1338;
    int m_133c;
    int m_1340;
    int m_1344;
    int m_1348;
    int m_134c;
    int m_1350;
    int m_1354;
    int m_1358;
    int m_135c;
    int m_1360;
    int m_1364;
    int m_1368;
    int m_136c;
    int m_1370;
    int m_1374;
    int m_1378;
    int m_137c;
    int m_1380;
    int m_1384;
    int m_1388;
    int m_138c;
    int m_1390;
    int m_1394;
    int m_1398;
    int m_139c;
    int m_13a0;
    int m_13a4;
    int m_13a8;
    int m_13ac;
    int m_13b0;
    int m_13b4;
    int m_13b8;
    int m_13bc;
    int m_13c0;
    int m_13c4;
    int m_13c8;
    int m_13cc;
    int m_13d0;
    int m_13d4;
    int m_13d8;
    int m_13dc;
    int m_13e0;
    int m_13e4;
    int m_13e8;
    int m_13ec;
    int m_13f0;
    int m_13f4;
    int m_13f8;
    int m_13fc;
    int m_1400;
    int m_1404;
    int m_1408;
    int m_140c;
    int m_1410;
    int m_1414;
    int m_1418;
    int m_141c;
    int m_1420;
    int m_1424;
    int m_1428;
    int m_142c;
    int m_1430;
    int m_1434;
    int m_1438;
    int m_143c;
    int m_1440;
    int m_1444;
    int m_1448;
    int m_144c;
    int m_1450;
    int m_1454;
    int m_1458;
    int m_145c;
    int m_1460;
    int m_1464;
    int m_1468;
    int m_146c;
    int m_1470;
    int m_1474;
    int m_1478;
    int m_147c;
    int m_1480;
    int m_1484;
    int m_1488;
    int m_148c;
    int m_1490;
    int m_1494;
    int m_1498;
    int m_149c;
    int m_14a0;
    int m_14a4;
    int m_14a8;
    int m_14ac;
    int m_14b0;
    int m_14b4;
    int m_14b8;
    int m_14bc;
    int m_14c0;
    int m_14c4;
    int m_14c8;
    int m_14cc;
    int m_14d0;
    int m_14d4;
    int m_14d8;
    int m_14dc;
    int m_14e0;
    int m_14e4;
    int m_14e8;
    int m_14ec;
    int m_14f0;
    int m_14f4;
    int m_14f8;
    int m_14fc;
    int m_1500;
    int m_1504;
    int m_1508;
    int m_150c;
    int m_1510;
    int m_1514;
    int m_1518;
    int m_151c;
    int m_1520;
    int m_1524;
    int m_1528;
    int m_152c;
    int m_1530;
    int m_1534;
    int m_1538;
    int m_153c;
    int m_1540;
    int m_1544;
    int m_1548;
    int m_154c;
    int m_1550;
    int m_1554;
    int m_1558;
    int m_155c;
    int m_1560;
    int m_1564;
    int m_1568;
    int m_156c;
    int m_1570;
    int m_1574;
    int m_1578;
    int m_157c;
    int m_1580;
    int m_1584;
    int m_1588;
    int m_158c;
    int m_1590;
    int m_1594;
    int m_1598;
    int m_159c;
    int m_15a0;
    int m_15a4;
    int m_15a8;
    int m_15ac;
    int m_15b0;
    int m_15b4;
    int m_15b8;
    int m_15bc;
    int m_15c0;
    int m_15c4;
    int m_15c8;
    int m_15cc;
    int m_15d0;
    int m_15d4;
    int m_15d8;
    int m_15dc;
    int m_15e0;
    int m_15e4;
    int m_15e8;
    int m_15ec;
    int m_15f0;
    int m_15f4;
    int m_15f8;
    int m_15fc;
    int m_1600;
    int m_1604;
    int m_1608;
    int m_160c;
    int m_1610;
    int m_1614;
    int m_1618;
    int m_161c;
    int m_1620;
    int m_1624;
    int m_1628;
    int m_162c;
    int m_1630;
    int m_1634;
    int m_1638;
    int m_163c;
    int m_1640;
    int m_1644;
    int m_1648;
    int m_164c;
    int m_1650;
    int m_1654;
    int m_1658;
    int m_165c;
    int m_1660;
    int m_1664;
    int m_1668;
    int m_166c;
    int m_1670;
    int m_1674;
    int m_1678;
    int m_167c;
    int m_1680;
    int m_1684;
    int m_1688;
    int m_168c;
    int m_1690;
    int m_1694;
    int m_1698;
    int m_169c;
    int m_16a0;
    int m_16a4;
    int m_16a8;
    int m_16ac;
    int m_16b0;
    int m_16b4;
    int m_16b8;
    int m_16bc;
    int m_16c0;
    int m_16c4;
    int m_16c8;
    int m_16cc;
    int m_16d0;
    int m_16d4;
    int m_16d8;
    int m_16dc;
    int m_16e0;
    int m_16e4;
    int m_16e8;
    int m_16ec;
    int m_16f0;
    int m_16f4;
    int m_16f8;
    int m_16fc;
    int m_1700;
    int m_1704;
    int m_1708;
    int m_170c;
    int m_1710;
    int m_1714;
    int m_1718;
    int m_171c;
    int m_1720;
    int m_1724;
    int m_1728;
    int m_172c;
    int m_1730;
    int m_1734;
    int m_1738;
    int m_173c;
    int m_1740;
    int m_1744;
    int m_1748;
    int m_174c;
    int m_1750;
    int m_1754;
    int m_1758;
    int m_175c;
    int m_1760;
    int m_1764;
    int m_1768;
    int m_176c;
    int m_1770;
    int m_1774;
    int m_1778;
    int m_177c;
    int m_1780;
    int m_1784;
    int m_1788;
    int m_178c;
    int m_1790;
    int m_1794;
    int m_1798;
    int m_179c;
    int m_17a0;
    int m_17a4;
    int m_17a8;
    int m_17ac;
    int m_17b0;
    int m_17b4;
    int m_17b8;
    int m_17bc;
    int m_17c0;
    int m_17c4;
    int m_17c8;
    int m_17cc;
    int m_17d0;
    int m_17d4;
    int m_17d8;
    int m_17dc;
    int m_17e0;
    int m_17e4;
    int m_17e8;
    int m_17ec;
    int m_17f0;
    int m_17f4;
    int m_17f8;
    int m_17fc;
    int m_1800;
    int m_1804;
    int m_1808;
    int m_180c;
    int m_1810;
    int m_1814;
    int m_1818;
    int m_181c;
    int m_1820;
    int m_1824;
    int m_1828;
    int m_182c;
    int m_1830;
    int m_1834;
    int m_1838;
    int m_183c;
    int m_1840;
    int m_1844;
    int m_1848;
    int m_184c;
    int m_1850;
    int m_1854;
    int m_1858;
    int m_185c;
    int m_1860;
    int m_1864;
    int m_1868;
    int m_186c;
    int m_1870;
    int m_1874;
    int m_1878;
    int m_187c;
    int m_1880;
    int m_1884;
    int m_1888;
    int m_188c;
    int m_1890;
    int m_1894;
    int m_1898;
    int m_189c;
    int m_18a0;
    int m_18a4;
    int m_18a8;
    int m_18ac;
    int m_18b0;
    int m_18b4;
    int m_18b8;
    int m_18bc;
    int m_18c0;
    int m_18c4;
    int m_18c8;
    int m_18cc;
    int m_18d0;
    int m_18d4;
    int m_18d8;
    int m_18dc;
    int m_18e0;
    int m_18e4;
    int m_18e8;
    int m_18ec;
    int m_18f0;
    int m_18f4;
    int m_18f8;
    int m_18fc;
    int m_1900;
    int m_1904;
    int m_1908;
    int m_190c;
    int m_1910;
    int m_1914;
    int m_1918;
    int m_191c;
    int m_1920;
    int m_1924;
    int m_1928;
    int m_192c;
    int m_1930;
    int m_1934;
    int m_1938;
    int m_193c;
    int m_1940;
    int m_1944;
    int m_1948;
    int m_194c;
    int m_1950;
    int m_1954;
    int m_1958;
    int m_195c;
    int m_1960;
    int m_1964;
    int m_1968;
    int m_196c;
    int m_1970;
    int m_1974;
    int m_1978;
    int m_197c;
    int m_1980;
    int m_1984;
    int m_1988;
    int m_198c;
    int m_1990;
    int m_1994;
    int m_1998;
    int m_199c;
    int m_19a0;
    int m_19a4;
    int m_19a8;
    int m_19ac;
    int m_19b0;
    int m_19b4;
    int m_19b8;
    int m_19bc;
    int m_19c0;
    int m_19c4;
    int m_19c8;
    int m_19cc;
    int m_19d0;
    int m_19d4;
    int m_19d8;
    int m_19dc;
    int m_19e0;
    int m_19e4;
    int m_19e8;
    int m_19ec;
    int m_19f0;
    int m_19f4;
    int m_19f8;
    int m_19fc;
    int m_1a00;
    int m_1a04;
    int m_1a08;
    int m_1a0c;
    int m_1a10;
    int m_1a14;
    int m_1a18;
    int m_1a1c;
    int m_1a20;
    int m_1a24;
    int m_1a28;
    int m_1a2c;
    int m_1a30;
    int m_1a34;
    int m_1a38;
    int m_1a3c;
    int m_1a40;
    int m_1a44;
    int m_1a48;
    int m_1a4c;
    int m_1a50;
    int m_1a54;
    int m_1a58;
    int m_1a5c;
    int m_1a60;
    int m_1a64;
    int m_1a68;
    int m_1a6c;
    int m_1a70;
    int m_1a74;
    int m_1a78;
    int m_1a7c;
    int m_1a80;
    int m_1a84;
    int m_1a88;
    int m_1a8c;
    int m_1a90;
    int m_1a94;
    int m_1a98;
    int m_1a9c;
    int m_1aa0;
    int m_1aa4;
    int m_1aa8;
    int m_1aac;
    int m_1ab0;
    int m_1ab4;
    int m_1ab8;
    int m_1abc;
    int m_1ac0;
    int m_1ac4;
    int m_1ac8;
    int m_1acc;
    int m_1ad0;
    int m_1ad4;
    int m_1ad8;
    int m_1adc;
    int m_1ae0;
    int m_1ae4;
    int m_1ae8;
    int m_1aec;
    int m_1af0;
    int m_1af4;
    int m_1af8;
    int m_1afc;
    int m_1b00;
    int m_1b04;
    int m_1b08;
    int m_1b0c;
    int m_1b10;
    int m_1b14;
    int m_1b18;
    int m_1b1c;
    int m_1b20;
    int m_1b24;
    int m_1b28;
    int m_1b2c;
    int m_1b30;
    int m_1b34;
    int m_1b38;
    int m_1b3c;
    int m_1b40;
    int m_1b44;
    int m_1b48;
    int m_1b4c;
    int m_1b50;
    int m_1b54;
    int m_1b58;
    int m_1b5c;
    int m_1b60;
    int m_1b64;
    int m_1b68;
    int m_1b6c;
    int m_1b70;
    int m_1b74;
    int m_1b78;
    int m_1b7c;
    int m_1b80;
    int m_1b84;
    int m_1b88;
    int m_1b8c;
    int m_1b90;
    int m_1b94;
    int m_1b98;
    int m_1b9c;
    int m_1ba0;
    int m_1ba4;
    int m_1ba8;
    int m_1bac;
    int m_1bb0;
    int m_1bb4;
    int m_1bb8;
    int m_1bbc;
    int m_1bc0;
    int m_1bc4;
    int m_1bc8;
    int m_1bcc;
    int m_1bd0;
    int m_1bd4;
    int m_1bd8;
    int m_1bdc;
    int m_1be0;
    int m_1be4;
    int m_1be8;
    int m_1bec;
    int m_1bf0;
    int m_1bf4;
    int m_1bf8;
    int m_1bfc;
    int m_1c00;
    int m_1c04;
    int m_1c08;
    int m_1c0c;
    int m_1c10;
    int m_1c14;
    int m_1c18;
    int m_1c1c;
    int m_1c20;
    int m_1c24;
    int m_1c28;
    int m_1c2c;
    int m_1c30;
    int m_1c34;
    int m_1c38;
    int m_1c3c;
    int m_1c40;
    int m_1c44;
    int m_1c48;
    int m_1c4c;
    int m_1c50;
    int m_1c54;
    int m_1c58;
    int m_1c5c;
    int m_1c60;
    int m_1c64;
    int m_1c68;
    int m_1c6c;
    int m_1c70;
    int m_1c74;
    int m_1c78;
    int m_1c7c;
    int m_1c80;
    int m_1c84;
    int m_1c88;
    int m_1c8c;
    int m_1c90;
    int m_1c94;
    int m_1c98;
    int m_1c9c;
    int m_1ca0;
    int m_1ca4;
    int m_1ca8;
    int m_1cac;
    int m_1cb0;
    int m_1cb4;
    int m_1cb8;
    int m_1cbc;
    int m_1cc0;
    int m_1cc4;
    int m_1cc8;
    int m_1ccc;
    int m_1cd0;
    int m_1cd4;
    int m_1cd8;
    int m_1cdc;
    int m_1ce0;
    int m_1ce4;
    int m_1ce8;
    int m_1cec;
    int m_1cf0;
    int m_1cf4;
    int m_1cf8;
    int m_1cfc;
    int m_1d00;
    int m_1d04;
    int m_1d08;
    int m_1d0c;
    int m_1d10;
    int m_1d14;
    int m_1d18;
    int m_1d1c;
    int m_1d20;
    int m_1d24;
    int m_1d28;
    int m_1d2c;
    int m_1d30;
    int m_1d34;
    int m_1d38;
    int m_1d3c;
    int m_1d40;
    int m_1d44;
    int m_1d48;
    int m_1d4c;
    int m_1d50;
    int m_1d54;
    int m_1d58;
    int m_1d5c;
    int m_1d60;
    int m_1d64;
    int m_1d68;
    int m_1d6c;
    int m_1d70;
    int m_1d74;
    int m_1d78;
    int m_1d7c;
    int m_1d80;
    int m_1d84;
    int m_1d88;
    int m_1d8c;
    int m_1d90;
    int m_1d94;
    int m_1d98;
    int m_1d9c;
    int m_1da0;
    int m_1da4;
    int m_1da8;
    int m_1dac;
    int m_1db0;
    int m_1db4;
    int m_1db8;
    int m_1dbc;
    int m_1dc0;
    int m_1dc4;
    int m_1dc8;
    int m_1dcc;
    int m_1dd0;
    int m_1dd4;
    int m_1dd8;
    int m_1ddc;
    int m_1de0;
    int m_1de4;
    int m_1de8;
    int m_1dec;
    int m_1df0;
    int m_1df4;
    int m_1df8;
    int m_1dfc;
    int m_1e00;
    int m_1e04;
    int m_1e08;
    int m_1e0c;
    int m_1e10;
    int m_1e14;
    int m_1e18;
    int m_1e1c;
    int m_1e20;
    int m_1e24;
    int m_1e28;
    int m_1e2c;
    int m_1e30;
    int m_1e34;
    int m_1e38;
    int m_1e3c;
    int m_1e40;
    int m_1e44;
    int m_1e48;
    int m_1e4c;
    int m_1e50;
    int m_1e54;
    int m_1e58;
    int m_1e5c;
    int m_1e60;
    int m_1e64;
    int m_1e68;
    int m_1e6c;
    int m_1e70;
    int m_1e74;
    int m_1e78;
    int m_1e7c;
    int m_1e80;
    int m_1e84;
    int m_1e88;
    int m_1e8c;
    int m_1e90;
    int m_1e94;
    int m_1e98;
    int m_1e9c;
    int m_1ea0;
    int m_1ea4;
    int m_1ea8;
    int m_1eac;
    int m_1eb0;
    int m_1eb4;
    int m_1eb8;
    int m_1ebc;
    int m_1ec0;
    int m_1ec4;
    int m_1ec8;
    int m_1ecc;
    int m_1ed0;
    int m_1ed4;
    int m_1ed8;
    int m_1edc;
    int m_1ee0;
    int m_1ee4;
    int m_1ee8;
    int m_1eec;
    int m_1ef0;
    int m_1ef4;
    int m_1ef8;
    int m_1efc;
    int m_1f00;
    int m_1f04;
    int m_1f08;
    int m_1f0c;
    int m_1f10;
    int m_1f14;
    int m_1f18;
    int m_1f1c;
    int m_1f20;
    int m_1f24;
    int m_1f28;
    int m_1f2c;
    int m_1f30;
    int m_1f34;
    int m_1f38;
    int m_1f3c;
    int m_1f40;
    int m_1f44;
    int m_1f48;
    int m_1f4c;
    int m_1f50;
    int m_1f54;
    int m_1f58;
    int m_1f5c;
    int m_1f60;
    int m_1f64;
    int m_1f68;
    int m_1f6c;
    int m_1f70;
    int m_1f74;
    int m_1f78;
    int m_1f7c;
    int m_1f80;
    int m_1f84;
    int m_1f88;
    int m_1f8c;
    int m_1f90;
    int m_1f94;
    int m_1f98;
    int m_1f9c;
    int m_1fa0;
    int m_1fa4;
    int m_1fa8;
    int m_1fac;
    int m_1fb0;
    int m_1fb4;
    int m_1fb8;
    int m_1fbc;
    int m_1fc0;
    int m_1fc4;
    int m_1fc8;
    int m_1fcc;
    int m_1fd0;
    int m_1fd4;
    int m_1fd8;
    int m_1fdc;
    int m_1fe0;
    int m_1fe4;
    int m_1fe8;
    int m_1fec;
    int m_1ff0;
    int m_1ff4;
    int m_1ff8;
    int m_1ffc;
    int m_2000;
    int m_2004;
    int m_2008;
    int m_200c;
    int m_2010;
    int m_2014;
    int m_2018;
    int m_201c;
    int m_2020;
    int m_2024;
    int m_2028;
    int m_202c;
    int m_2030;
    int m_2034;
    int m_2038;
    int m_203c;
    int m_2040;
    int m_2044;
    int m_2048;
    int m_204c;
    int m_2050;
    int m_2054;
    int m_2058;
    int m_205c;
    int m_2060;
    int m_2064;
    int m_2068;
    int m_206c;
    int m_2070;
    int m_2074;
    int m_2078;
    int m_207c;
    int m_2080;
    int m_2084;
    int m_2088;
    int m_208c;
    int m_2090;
    int m_2094;
    int m_2098;
    int m_209c;
    int m_20a0;
    int m_20a4;
    int m_20a8;
    int m_20ac;
    int m_20b0;
    int m_20b4;
    int m_20b8;
    int m_20bc;
    int m_20c0;
    int m_20c4;
    int m_20c8;
    int m_20cc;
    int m_20d0;
    int m_20d4;
    int m_20d8;
    int m_20dc;
    int m_20e0;
    int m_20e4;
    int m_20e8;
    int m_20ec;
    int m_20f0;
    int m_20f4;
    int m_20f8;
    int m_20fc;
    int m_2100;
    int m_2104;
    int m_2108;
    int m_210c;
    int m_2110;
    int m_2114;
    int m_2118;
    int m_211c;
    int m_2120;
    int m_2124;
    int m_2128;
    int m_212c;
    int m_2130;
    int m_2134;
    int m_2138;
    int m_213c;
    int m_2140;
    int m_2144;
    int m_2148;
    int m_214c;
    int m_2150;
    int m_2154;
    int m_2158;
    int m_215c;
    int m_2160;
    int m_2164;
    int m_2168;
    int m_216c;
    int m_2170;
    int m_2174;
    int m_2178;
    int m_217c;
    int m_2180;
    int m_2184;
    int m_2188;
    int m_218c;
    int m_2190;
    int m_2194;
    int m_2198;
    int m_219c;
    int m_21a0;
    int m_21a4;
    int m_21a8;
    int m_21ac;
    int m_21b0;
    int m_21b4;
    int m_21b8;
    int m_21bc;
    int m_21c0;
    int m_21c4;
    int m_21c8;
    int m_21cc;
    int m_21d0;
    int m_21d4;
    int m_21d8;
    int m_21dc;
    int m_21e0;
    int m_21e4;
    int m_21e8;
    int m_21ec;
    int m_21f0;
    int m_21f4;
    int m_21f8;
    int m_21fc;
    int m_2200;
    int m_2204;
    int m_2208;
    int m_220c;
    int m_2210;
    int m_2214;
    int m_2218;
    int m_221c;
    int m_2220;
    int m_2224;
    int m_2228;
    int m_222c;
    int m_2230;
    int m_2234;
    int m_2238;
    int m_223c;
    int m_2240;
    int m_2244;
    int m_2248;
    int m_224c;
    int m_2250;
    int m_2254;
    int m_2258;
    int m_225c;
    int m_2260;
    int m_2264;
    int m_2268;
    int m_226c;
    int m_2270;
    int m_2274;
    int m_2278;
    int m_227c;
    int m_2280;
    int m_2284;
    int m_2288;
    int m_228c;
    int m_2290;
    int m_2294;
    int m_2298;
    int m_229c;
    int m_22a0;
    int m_22a4;
    int m_22a8;
    int m_22ac;
    int m_22b0;
    int m_22b4;
    int m_22b8;
    int m_22bc;
    int m_22c0;
    int m_22c4;
    int m_22c8;
    int m_22cc;
    int m_22d0;
    int m_22d4;
    int m_22d8;
    int m_22dc;
    int m_22e0;
    int m_22e4;
    int m_22e8;
    int m_22ec;
    int m_22f0;
    int m_22f4;
    int m_22f8;
    int m_22fc;
    int m_2300;
    int m_2304;
    int m_2308;
    int m_230c;
    int m_2310;
    int m_2314;
    int m_2318;
    int m_231c;
    int m_2320;
    int m_2324;
    int m_2328;
    int m_232c;
    int m_2330;
    int m_2334;
    int m_2338;
    int m_233c;
    int m_2340;
    int m_2344;
    int m_2348;
    int m_234c;
    int m_2350;
    int m_2354;
    int m_2358;
    int m_235c;
    int m_2360;
    int m_2364;
    int m_2368;
    int m_236c;
    int m_2370;
    int m_2374;
    int m_2378;
    int m_237c;
    int m_2380;
    int m_2384;
    int m_2388;
    int m_238c;
    int m_2390;
    int m_2394;
    int m_2398;
    int m_239c;
    int m_23a0;
    int m_23a4;
    int m_23a8;
    int m_23ac;
    int m_23b0;
    int m_23b4;
    int m_23b8;
    int m_23bc;
    int m_23c0;
    int m_23c4;
    int m_23c8;
    int m_23cc;
    int m_23d0;
    int m_23d4;
    int m_23d8;
    int m_23dc;
    int m_23e0;
    int m_23e4;
    int m_23e8;
    int m_23ec;
    int m_23f0;
    int m_23f4;
    int m_23f8;
    int m_23fc;
    int m_2400;
    int m_2404;
    int m_2408;
    int m_240c;
    int m_2410;
    int m_2414;
    int m_2418;
    int m_241c;
    int m_2420;
    int m_2424;
    int m_2428;
    int m_242c;
    int m_2430;
    int m_2434;
    int m_2438;
    int m_243c;
    int m_2440;
    int m_2444;
    int m_2448;
    int m_244c;
    int m_2450;
    int m_2454;
    int m_2458;
    int m_245c;
    int m_2460;
    int m_2464;
    int m_2468;
    int m_246c;
    int m_2470;
    int m_2474;
    int m_2478;
    int m_247c;
    int m_2480;
    int m_2484;
    int m_2488;
    int m_248c;
    int m_2490;
    int m_2494;
    int m_2498;
    int m_249c;
    int m_24a0;
    int m_24a4;
    int m_24a8;
    int m_24ac;
    int m_24b0;
    int m_24b4;
    int m_24b8;
    int m_24bc;
    int m_24c0;
    int m_24c4;
    int m_24c8;
    int m_24cc;
    int m_24d0;
    int m_24d4;
    int m_24d8;
    int m_24dc;
    int m_24e0;
    int m_24e4;
    int m_24e8;
    int m_24ec;
    int m_24f0;
    int m_24f4;
    int m_24f8;
    int m_24fc;
    int m_2500;
    int m_2504;
    int m_2508;
    int m_250c;
    int m_2510;
    int m_2514;
    int m_2518;
    int m_251c;
    int m_2520;
    int m_2524;
    int m_2528;
    int m_252c;
    int m_2530;
    int m_2534;
    int m_2538;
    int m_253c;
    int m_2540;
    int m_2544;
    int m_2548;
    int m_254c;
    int m_2550;
    int m_2554;
    int m_2558;
    int m_255c;
    int m_2560;
    int m_2564;
    int m_2568;
    int m_256c;
    int m_2570;
    int m_2574;
    int m_2578;
    int m_257c;
    int m_2580;
    int m_2584;
    int m_2588;
    int m_258c;
    int m_2590;
    int m_2594;
    int m_2598;
    int m_259c;
    int m_25a0;
    int m_25a4;
    int m_25a8;
    int m_25ac;
    int m_25b0;
    int m_25b4;
    int m_25b8;
    int m_25bc;
    int m_25c0;
    int m_25c4;
    int m_25c8;
    int m_25cc;
    int m_25d0;
    int m_25d4;
    int m_25d8;
    int m_25dc;
    int m_25e0;
    int m_25e4;
    int m_25e8;
    int m_25ec;
    int m_25f0;
    int m_25f4;
    int m_25f8;
    int m_25fc;
    int m_2600;
    int m_2604;
    int m_2608;
    int m_260c;
    int m_2610;
    int m_2614;
    int m_2618;
    int m_261c;
    int m_2620;
    int m_2624;
    int m_2628;
    int m_262c;
    int m_2630;
    int m_2634;
    int m_2638;
    int m_263c;
    int m_2640;
    int m_2644;
    int m_2648;
    int m_264c;
    int m_2650;
    int m_2654;
    int m_2658;
    int m_265c;
    int m_2660;
    int m_2664;
    int m_2668;
    int m_266c;
    int m_2670;
    int m_2674;
    int m_2678;
    int m_267c;
    int m_2680;
    int m_2684;
    int m_2688;
    int m_268c;
    int m_2690;
    int m_2694;
    int m_2698;
    int m_269c;
    int m_26a0;
    int m_26a4;
    int m_26a8;
    int m_26ac;
    int m_26b0;
    int m_26b4;
    int m_26b8;
    int m_26bc;
    int m_26c0;
    int m_26c4;
    int m_26c8;
    int m_26cc;
    int m_26d0;
    int m_26d4;
    int m_26d8;
    int m_26dc;
    int m_26e0;
    int m_26e4;
    int m_26e8;
    int m_26ec;
    int m_26f0;
    int m_26f4;
    int m_26f8;
    int m_26fc;
    int m_2700;
    int m_2704;
    int m_2708;
    int m_270c;
    int m_2710;
    int m_2714;
    int m_2718;
    int m_271c;
    int m_2720;
    int m_2724;
    int m_2728;
    int m_272c;
    int m_2730;
    int m_2734;
    int m_2738;
    int m_273c;
    int m_2740;
    int m_2744;
    int m_2748;
    int m_274c;
    int m_2750;
    int m_2754;
    int m_2758;
    int m_275c;
    int m_2760;
    int m_2764;
    int m_2768;
    int m_276c;
    int m_2770;
    int m_2774;
    int m_2778;
    int m_277c;
    int m_2780;
    int m_2784;
    int m_2788;
    int m_278c;
    int m_2790;
    int m_2794;
    int m_2798;
    int m_279c;
    int m_27a0;
    int m_27a4;
    int m_27a8;
    int m_27ac;
    int m_27b0;
    int m_27b4;
    int m_27b8;
    int m_27bc;
    int m_27c0;
    int m_27c4;
    int m_27c8;
    int m_27cc;
    int m_27d0;
    int m_27d4;
    int m_27d8;
    int m_27dc;
    int m_27e0;
    int m_27e4;
    int m_27e8;
    int m_27ec;
    int m_27f0;
    int m_27f4;
    int m_27f8;
    int m_27fc;
    int m_2800;
    int m_2804;
    int m_2808;
    int m_280c;
    int m_2810;
    int m_2814;
    int m_2818;
    int m_281c;
    int m_2820;
    int m_2824;
    int m_2828;
    int m_282c;
    int m_2830;
    int m_2834;
    int m_2838;
    int m_283c;
    int m_2840;
    int m_2844;
    int m_2848;
    int m_284c;
    int m_2850;
    int m_2854;
    int m_2858;
    int m_285c;
    int m_2860;
    int m_2864;
    int m_2868;
    int m_286c;
    int m_2870;
    int m_2874;
    int m_2878;
    int m_287c;
    int m_2880;
    int m_2884;
    int m_2888;
    int m_288c;
    int m_2890;
    int m_2894;
    int m_2898;
    int m_289c;
    int m_28a0;
    int m_28a4;
    int m_28a8;
    int m_28ac;
    int m_28b0;
    int m_28b4;
    int m_28b8;
    int m_28bc;
    int m_28c0;
    int m_28c4;
    int m_28c8;
    int m_28cc;
    int m_28d0;
    int m_28d4;
    int m_28d8;
    int m_28dc;
    int m_28e0;
    int m_28e4;
    int m_28e8;
    int m_28ec;
    int m_28f0;
    int m_28f4;
    int m_28f8;
    int m_28fc;
    int m_2900;
    int m_2904;
    int m_2908;
    int m_290c;
    int m_2910;
    int m_2914;
    int m_2918;
    int m_291c;
    int m_2920;
    int m_2924;
    int m_2928;
    int m_292c;
    int m_2930;
    int m_2934;
    int m_2938;
    int m_293c;
    int m_2940;
    int m_2944;
    int m_2948;
    int m_294c;
    int m_2950;
    int m_2954;
    int m_2958;
    int m_295c;
    int m_2960;
    int m_2964;
    int m_2968;
    int m_296c;
    int m_2970;
    int m_2974;
    int m_2978;
    int m_297c;
    int m_2980;
    int m_2984;
    int m_2988;
    int m_298c;
    int m_2990;
    int m_2994;
    int m_2998;
    int m_299c;
    int m_29a0;
    int m_29a4;
    int m_29a8;
    int m_29ac;
    int m_29b0;
    int m_29b4;
    int m_29b8;
    int m_29bc;
    int m_29c0;
    int m_29c4;
    int m_29c8;
    int m_29cc;
    int m_29d0;
    int m_29d4;
    int m_29d8;
    int m_29dc;
    int m_29e0;
    int m_29e4;
    int m_29e8;
    int m_29ec;
    int m_29f0;
    int m_29f4;
    int m_29f8;
    int m_29fc;
    int m_2a00;
    int m_2a04;
    int m_2a08;
    int m_2a0c;
    int m_2a10;
    int m_2a14;
    int m_2a18;
    int m_2a1c;
    int m_2a20;
    int m_2a24;
    int m_2a28;
    int m_2a2c;
    int m_2a30;
    int m_2a34;
    int m_2a38;
    int m_2a3c;
    int m_2a40;
    int m_2a44;
    int m_2a48;
    int m_2a4c;
    int m_2a50;
    int m_2a54;
    int m_2a58;
    int m_2a5c;
    int m_2a60;
    int m_2a64;
    int m_2a68;
    int m_2a6c;
    int m_2a70;
    int m_2a74;
    int m_2a78;
    int m_2a7c;
    int m_2a80;
    int m_2a84;
    int m_2a88;
    int m_2a8c;
    int m_2a90;
    int m_2a94;
    int m_2a98;
    int m_2a9c;
    int m_2aa0;
    int m_2aa4;
    int m_2aa8;
    int m_2aac;
    int m_2ab0;
    int m_2ab4;
    int m_2ab8;
    int m_2abc;
    int m_2ac0;
    int m_2ac4;
    int m_2ac8;
    int m_2acc;
    int m_2ad0;
    int m_2ad4;
    int m_2ad8;
    int m_2adc;
    int m_2ae0;
    int m_2ae4;
    int m_2ae8;
    int m_2aec;
    int m_2af0;
    int m_2af4;
    int m_2af8;
    int m_2afc;
    int m_2b00;
    int m_2b04;
    int m_2b08;
    int m_2b0c;
    int m_2b10;
    int m_2b14;
    int m_2b18;
    int m_2b1c;
    int m_2b20;
    int m_2b24;
    int m_2b28;
    int m_2b2c;
    int m_2b30;
    int m_2b34;
    int m_2b38;
    int m_2b3c;
    int m_2b40;
    int m_2b44;
    int m_2b48;
    int m_2b4c;
    int m_2b50;
    int m_2b54;
    int m_2b58;
    int m_2b5c;
    int m_2b60;
    int m_2b64;
    int m_2b68;
    int m_2b6c;
    int m_2b70;
    int m_2b74;
    int m_2b78;
    int m_2b7c;
    int m_2b80;
    int m_2b84;
    int m_2b88;
    int m_2b8c;
    int m_2b90;
    int m_2b94;
    int m_2b98;
    int m_2b9c;
    int m_2ba0;
    int m_2ba4;
    int m_2ba8;
    int m_2bac;
    int m_2bb0;
    int m_2bb4;
    int m_2bb8;
    int m_2bbc;
    int m_2bc0;
    int m_2bc4;
    int m_2bc8;
    int m_2bcc;
    int m_2bd0;
    int m_2bd4;
    int m_2bd8;
    int m_2bdc;
    int m_2be0;
    int m_2be4;
    int m_2be8;
    int m_2bec;
    int m_2bf0;
    int m_2bf4;
    int m_2bf8;
    int m_2bfc;
    int m_2c00;
    int m_2c04;
    int m_2c08;
    int m_2c0c;
    int m_2c10;
    int m_2c14;
    int m_2c18;
    int m_2c1c;
    int m_2c20;
    int m_2c24;
    int m_2c28;
    int m_2c2c;
    int m_2c30;
    int m_2c34;
    int m_2c38;
    int m_2c3c;
    int m_2c40;
    int m_2c44;
    int m_2c48;
    int m_2c4c;
    int m_2c50;
    int m_2c54;
    int m_2c58;
    int m_2c5c;
    int m_2c60;
    int m_2c64;
    int m_2c68;
    int m_2c6c;
    int m_2c70;
    int m_2c74;
    int m_2c78;
    int m_2c7c;
    int m_2c80;
    int m_2c84;
    int m_2c88;
    int m_2c8c;
    int m_2c90;
    int m_2c94;
    int m_2c98;
    int m_2c9c;
    int m_2ca0;
    int m_2ca4;
    int m_2ca8;
    int m_2cac;
    int m_2cb0;
    int m_2cb4;
    int m_2cb8;
    int m_2cbc;
    int m_2cc0;
    int m_2cc4;
    int m_2cc8;
    int m_2ccc;
    int m_2cd0;
    int m_2cd4;
    int m_2cd8;
    int m_2cdc;
    int m_2ce0;
    int m_2ce4;
    int m_2ce8;
    int m_2cec;
    int m_2cf0;
    int m_2cf4;
    int m_2cf8;
    int m_2cfc;
    int m_2d00;
    int m_2d04;
    int m_2d08;
    int m_2d0c;
    int m_2d10;
    int m_2d14;
    int m_2d18;
    int m_2d1c;
    int m_2d20;
    int m_2d24;
    int m_2d28;
    int m_2d2c;
    int m_2d30;
    int m_2d34;
    int m_2d38;
    int m_2d3c;
    int m_2d40;
    int m_2d44;
    int m_2d48;
    int m_2d4c;
    int m_2d50;
    int m_2d54;
    int m_2d58;
    int m_2d5c;
    int m_2d60;
    int m_2d64;
    int m_2d68;
    int m_2d6c;
    int m_2d70;
    int m_2d74;
    int m_2d78;
    int m_2d7c;
    int m_2d80;
    int m_2d84;
    int m_2d88;
    int m_2d8c;
    int m_2d90;
    int m_2d94;
    int m_2d98;
    int m_2d9c;
    int m_2da0;
    int m_2da4;
    int m_2da8;
    int m_2dac;
    int m_2db0;
    int m_2db4;
    int m_2db8;
    int m_2dbc;
    int m_2dc0;
    int m_2dc4;
    int m_2dc8;
    int m_2dcc;
    int m_2dd0;
    int m_2dd4;
    int m_2dd8;
    int m_2ddc;
    int m_2de0;
    int m_2de4;
    int m_2de8;
    int m_2dec;
    int m_2df0;
    int m_2df4;
    int m_2df8;
    int m_2dfc;
    int m_2e00;
    int m_2e04;
    int m_2e08;
    int m_2e0c;
    int m_2e10;
    int m_2e14;
    int m_2e18;
    int m_2e1c;
    int m_2e20;
    int m_2e24;
    int m_2e28;
    int m_2e2c;
    int m_2e30;
    int m_2e34;
    int m_2e38;
    int m_2e3c;
    int m_2e40;
    int m_2e44;
    int m_2e48;
    int m_2e4c;
    int m_2e50;
    int m_2e54;
    int m_2e58;
    int m_2e5c;
    int m_2e60;
    int m_2e64;
    int m_2e68;
    int m_2e6c;
    int m_2e70;
    int m_2e74;
    int m_2e78;
    int m_2e7c;
    int m_2e80;
    int m_2e84;
    int m_2e88;
    int m_2e8c;
    int m_2e90;
    int m_2e94;
    int m_2e98;
    int m_2e9c;
    int m_2ea0;
    int m_2ea4;
    int m_2ea8;
    int m_2eac;
    int m_2eb0;
    int m_2eb4;
    int m_2eb8;
    int m_2ebc;
    int m_2ec0;
    int m_2ec4;
    int m_2ec8;
    int m_2ecc;
    int m_2ed0;
    int m_2ed4;
    int m_2ed8;
    int m_2edc;
    int m_2ee0;
    int m_2ee4;
    int m_2ee8;
    int m_2eec;
    int m_2ef0;
    int m_2ef4;
    int m_2ef8;
    int m_2efc;
    int m_2f00;
    int m_2f04;
    int m_2f08;
    int m_2f0c;
    int m_2f10;
    int m_2f14;
    int m_2f18;
    int m_2f1c;
    int m_2f20;
    int m_2f24;
    int m_2f28;
    int m_2f2c;
    int m_2f30;
    int m_2f34;
    int m_2f38;
    int m_2f3c;
    int m_2f40;
    int m_2f44;
    int m_2f48;
    int m_2f4c;
    int m_2f50;
    int m_2f54;
    int m_2f58;
    int m_2f5c;
    int m_2f60;
    int m_2f64;
    int m_2f68;
    int m_2f6c;
    int m_2f70;
    int m_2f74;
    int m_2f78;
    int m_2f7c;
    int m_2f80;
    int m_2f84;
    int m_2f88;
    int m_2f8c;
    int m_2f90;
    int m_2f94;
    int m_2f98;
    int m_2f9c;
    int m_2fa0;
    int m_2fa4;
    int m_2fa8;
    int m_2fac;
    int m_2fb0;
    int m_2fb4;
    int m_2fb8;
    int m_2fbc;
    int m_2fc0;
    int m_2fc4;
    int m_2fc8;
    int m_2fcc;
    int m_2fd0;
    int m_2fd4;
    int m_2fd8;
    int m_2fdc;
    int m_2fe0;
    int m_2fe4;
    int m_2fe8;
    int m_2fec;
    int m_2ff0;
    int m_2ff4;
    int m_2ff8;
    int m_2ffc;
    int m_3000;
    int m_3004;
    int m_3008;
    int m_300c;
    int m_3010;
    int m_3014;
    int m_3018;
    int m_301c;
    int m_3020;
    int m_3024;
    int m_3028;
    int m_302c;
    float m_3030;
    int m_3034;
    int m_3038;
    int m_303c;
    int m_3040;
    int m_3044;
    int m_3048;
    int m_304c;
    float m_3050;
    float m_3054;
    int m_3058;
    int m_305c;
    int m_3060;
    int m_3064;
    int m_3068;
    int m_306c;
    int m_3070;
    int m_3074;
    int m_3078;
    int m_307c;
    int m_3080;
    OutputDce() : m_0004(0), m_3030(DAT_0104da48), m_3050(0.0f), m_3054(0.0f)
    {}
};
struct SmallDce
{
    void* m_00;
    void* m_04;
    int m_08;
    int m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    unsigned char m_1c;
    unsigned char m_1d;
    unsigned char m_1e;
    unsigned char u1f;
    int m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    int m_30;
};
struct LocalStateDce
{
    CountInfoDce counts;
    void* transform;
};

extern "C" int PickIslandByValue(void* p5, int a, int b);
extern "C" int DispatchItemToAgent(int a, void* p4, WorkObj* wb, int cc, void* p5);
extern "C" int DispatchInstruction(NodeDce* p1, int sb, void* inner, void* p4, void* p5);
extern "C" void hkArrayUtil__reserve(void* old, void* bufptr, int nsize, int one);
extern "C" void hkpWorldOperationUtil_addConstraintImmediately(void* obj, void* work, int one);
extern "C" int RoundUpToBucketSize(int w);
extern "C" NodeG* AllocateBlock(int a, int b, int c, int d);
extern "C" void __fastcall AccumulateStats(void* cc, void* elem, void* a, int* b);
extern "C" void hkAgentNnMachine_InvalidateTimInAgent(void* p5, void* p4);
extern "C" void hkpWorldCallbackUtil_fireContactPointAdded(void* a, void* item);
extern "C" void hkpEntityCallbackUtil_fireContactPointAddedInternal(NodeDce* p, void* item);
extern "C" void hkpWorldCallbackUtil_fireContactPointCallback(void* a, void* item);
extern "C" void hkpEntityCallbackUtil_fireContactPointCallbackInternal(NodeDce* p, void* item);
extern "C" float DAT_0104da48;
typedef int(__thiscall* FnThiscallInt)(void* self, int a);
typedef int(__thiscall* FnThiscallInt2)(void* self, int a, int b);
typedef int(__thiscall* FnThiscallFree)(void* self, void* ptr, int size);
typedef void(__thiscall* FnThiscallVoidPtr)(void* self, void* a);
__forceinline void BytesDce::reserve(hkMemoryAllocator& alloc, int count)
{
    int cap = capacity & 0x3fffffff;
    if (cap < count)
    {
        int newcap = (count < cap + cap) ? cap + cap : count;
        hkArrayUtil__reserve(&alloc, this, newcap, 1);
    }
}
__forceinline void BytesDce::resize(int count)
{
    hkMemoryAllocator& allocator = DceAccess::hkMemoryRouter_getInstance()->heap();
    reserve(allocator, count);
    size = count;
}
__forceinline InputDce::InputDce(void* const& ta, void* tb, WorkObj* work, int id, void* context, OutputDce* output,
                                 ContactDce*& saved)
{
    saved = work->contact(id);
    void* properties = work->properties(id);
    m_00 = ta;
    m_04 = tb;
    m_08 = 1;
    m_10 = properties;
    m_14 = 0;
    m_18 = saved;
    m_1c = 0.0f;
    m_24 = work;
    m_28 = context;
    m_2c = output;
    m_20 = 0;
    m_30 = (unsigned short)id;
    if (work->m_08 == 0)
        m_32 = work->m_12;
    else
        m_32 = 0;
}
static NodeF* ResolveF(NodeF* f)
{
    if (f->m_18 == 1)
        return (NodeF*)((char*)f + (signed char)f->m_10);
    return 0;
}
inline void CountDce::subConstraintInfo(S00dce180_Instance* constraint, CountInfoDce& delta)
{
    if (constraint->m_pConstraintInternal)
    {
        data.subtract(delta);
        constraint->m_pConstraintInternal->subConstraintInfo(delta);
    }
}
inline void CountDce::AccumulateStats(S00dce180_Instance* constraint, CountInfoDce& delta)
{
    if (constraint->m_pConstraintInternal)
    {
        data.add(delta);
        constraint->m_pConstraintInternal->AddConstraintToCriticalSection(delta);
        int sizeOfSchemas = constraint->m_pConstraintInternal->m_14w;
        data.u00 = data.u00 > sizeOfSchemas ? data.u00 : sizeOfSchemas;
    }
}

// Swaps constraint ends if needed, copies state from p1 into p5's work object, calls per-contact handlers for each contact id, returns 0 on success else 1.
// @fnv 0x00dce180
// src: HAVOK_LIB 0x00dce180
int __cdecl hkpSaveContactPointsUtil_deserializeCollisionEntry(Arg0* apFlags, NodeDce* apNode, NodeDce* apNodeA, NodeDce* apNodeB, void* apContext, P5* p5)
{
    void* idx = 0;
    LocalStateDce i;
    unsigned int ecx0_2 = apNodeA->m_0cc;
    WorkObj* c = p5->m_08;
    int w4_2 = apNodeB->m_0cc;
    if (ecx0_2 != w4_2)
    {
        if (5 == apNodeA->m_0e8)
        {
            ecx0_2 = w4_2;
        }
        else if (apNodeB->m_0e8 != 5)
        {
            ecx0_2 = PickIslandByValue(p5, ecx0_2, w4_2);
        }
    }
    int item_end = apNode->m_019;
    if (DispatchItemToAgent(item_end, apContext, c, ecx0_2, p5) == 0)
    {
        NodeF* want = p5->m_10;
        NodeF* pResolved = ResolveF(want);
        if (apNodeA != (NodeDce*)pResolved)
        {
            S00dce180_swap(p5->m_10, p5->m_14);
            S00dce180_swap(p5->m_04, p5->m_06);
            S00dce180_Instance* pConstraint = &c->m_pHavokConstraint;
            S00dce180_swap(pConstraint->m_kActorEntries[0], pConstraint->m_kActorEntries[1]);
            if (pConstraint->m_pConstraintInternal)
            {
                S00dce180_swap((unsigned long&)pConstraint->m_pConstraintInternal->m_kNodeCollection[0],
                               (unsigned long&)pConstraint->m_pConstraintInternal->m_kNodeCollection[1]);
                pConstraint->m_pConstraintInternal->m_1a = !pConstraint->m_pConstraintInternal->m_1a;
            }
        }
        int v;
        v = apNode->m_019;
        if (DispatchInstruction(apNode, v, &apNode->unk0114, apContext, p5) == 0)
        {
            c->bytes.resize(apNode->m_06c);
            for (int k = 0; k < c->bytes.size; k++)
                c->bytes.data[k] = apNode->m_068[k];
            if (!c->m_3c->m_04)
            {
                NodeF* p = ResolveF(p5->m_10);
                ResourceDce* pResource = p->m_08;
                pResource->m_94 -= 1;
                pResource->m_9c = 1;
                hkpWorldOperationUtil_addConstraintImmediately(pResource, &c->m_pHavokConstraint, 1);
                pResource->m_94 += 1;
                pResource->m_9c = 0;
            }
            {
                CountInfoDce info1;
                info1.clear();
                c->m_3c->addToConstraintInfo(info1);
                c->m_pHavokConstraint.getMasterEntity()->GetSimulationIsland()->subConstraintInfo(
                    &c->m_pHavokConstraint, info1);
            }
            NodeG* pNodeG;
            pNodeG = c->m_3c;
            int base = RoundUpToBucketSize(pNodeG->m_02);
            BSAudio* pSvc = DceAccess::hkMemoryRouter_getInstance();
            pSvc->heap().blockFree(pNodeG, base);
            int ecxv = apNode->m_024;
            unsigned int n = apNode->m_02c;
            unsigned int s58 = apNode->m_029;
            unsigned int cnt = apNode->m_028;
            c->m_3c = AllocateBlock(ecxv, cnt, s58, n);
            c->m_3c->m_04 = (unsigned short)ecxv;
            c->m_3c->m_block = apNode->m_030;
            c->m_pHavokConstraint.m_pConstraintInternal->m_0c = (int)c->m_3c;
            c->m_pHavokConstraint.m_pConstraintInternal->m_10 = c->m_3c->m_02;
            {
                CountInfoDce info;
                info.clear();
                c->m_3c->addToConstraintInfo(info);
                c->m_pHavokConstraint.getMasterEntity()->GetSimulationIsland()->AccumulateStats(&c->m_pHavokConstraint,
                                                                                             info);
            }
            NodeG* kIter = c->m_3c;
            int res = kIter->m_0a * ecxv;
            hkString_memCpy(kIter->entries(), apNode->m_050, res);
            hkString_memCpy(c->m_3c + 1, apNode->m_05c, ecxv << 5);
            if (0 != apFlags->m_01)
            {
                NodeG* pObj = c->m_3c;
                DataEntryDce* pEntry = pObj->entries();
                int ptr = pObj->m_0a;
                for (int m = 0; m < (int)c->m_3c->m_04; m++)
                {
                    pEntry->m_08 = 0;
                    pEntry = reinterpret_cast<DataEntryDce*>(reinterpret_cast<char*>(pEntry) + ptr);
                }
            }
            ContactListDce val;
            c->enumerate(&val.ids);
            if (!!apFlags->m_08)
            {
                for (int a = 0; a < val.ids.m_iElementCount; a++)
                {
                    int j = val.ids.m_data[a];
                    OutputDce output;

                    i.transform = 0;
                    idx = 0;
                    if (apFlags->m_0a ? true : false)
                    {
                        i.transform = &apNodeA->u010;
                        idx = &apNodeB->u010;
                    }
                    InputDce z(i.transform, idx, c, j, apContext, &output, val.current);
                    hkpWorldCallbackUtil_fireContactPointAdded(apNodeA->m_008, &z);
                    if ((bool)apNodeA->m_204)
                        hkpEntityCallbackUtil_fireContactPointAddedInternal(apNodeA, &z);
                    if (apNodeB->m_204 != 0)
                        hkpEntityCallbackUtil_fireContactPointAddedInternal(apNodeB, &z);
                }
            }
            if ((bool)apFlags->m_09)
            {
                int esi_val = val.ids.m_iElementCount;
                for (int a = 0; esi_val > a; a++)
                {
                    unsigned int j = val.ids.m_data[a];
                    ContactDce* pContact = c->contact(j);
                    if ((pContact->m_0f & 1) != 0)
                        continue;
                    val.current = c->contact(j);
                    void* b = c->properties(j);
                    SmallDce z;
                    z.m_14 = b;
                    z.m_18 = val.current;
                    z.m_28 = &val.current->m_14;
                    z.m_00 = (void*)2;
                    z.m_0c = (int)c;
                    z.m_04 = apNodeA;
                    z.m_08 = (int)apNodeB;
                    z.m_10 = (void*)4;
                    z.m_1c = 0;
                    z.m_1d = 0;
                    z.m_1e = 0;
                    z.m_20 = 0;
                    z.m_24 = 0;
                    z.m_2c = 0;
                    z.m_30 = 0;
                    hkpWorldCallbackUtil_fireContactPointCallback(apNodeA->m_008, &z);
                    z.m_00 = 0;
                    if ((bool)apNodeA->m_204)
                        hkpEntityCallbackUtil_fireContactPointCallbackInternal(apNodeA, &z);
                    z.m_00 = (void*)1;
                    if (!!apNodeB->m_204)
                        hkpEntityCallbackUtil_fireContactPointCallbackInternal(apNodeB, &z);
                }
            }
            hkAgentNnMachine_InvalidateTimInAgent(p5, apContext);
            BSAudio* rf = DceAccess::hkMemoryRouter_getInstance();
            long r;
            hkMemoryAllocator* pAlloc = &rf->heap();
            r = val.ids.m_iCapacityState;
            val.ids.m_iElementCount = 0;
            if ((r & 0x80000000) == 0)
            {
                pAlloc->bufFree(val.ids.m_data, (r & 0x3fffffff) * 2);
            }
            return 0;
        }
    }
    return 1;
}

// Preserve the inline Havok base construction used by the placement constructor.

struct DCEInfo
{
    DCEInfo() : m_usUnk04(0x16), m_usUnk14(0), m_usUnk16(3)
    {}

    int unk00;
    unsigned short m_usUnk04;
    short unk06;
    int unk08;
    int unk0C;
    int unk10;
    unsigned short m_usUnk14;
    unsigned short m_usUnk16;
};

class DCEEntryInit : public hkReferencedObject
{
  public:
    __forceinline DCEEntryInit();
    static void* operator new(unsigned int, void* storage)
    {
        return storage;
    }
    static void operator delete(void*, void*)
    {}

    int m_iUnk08;
    int m_iUnk0C;
    int m_iUnk10;
    int m_iUnk14;
    bool m_bUnk18;
    DCEInfo m_kInfo;
    int m_iUnk34;
    int m_iUnk38;
    int m_iUnk3C;
    int m_iUnk40;
    int m_iUnk44;
    int m_iUnk48;
    int m_iUnk4C;
    hkArray<int> m_kArray50;
    hkArray<int> m_kArray5C;
    hkArray<int> m_kArray68;
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
    hkArray<int> m_kArray114;
    hkArray<int> m_kArray120;
    int m_iUnk12C;
    int m_iUnk130;
};

DCEEntryInit::DCEEntryInit()
    : m_iUnk08(0), m_iUnk0C(0), m_iUnk10(-1), m_iUnk14(-1), m_bUnk18(false), m_iUnk34(0), m_iUnk38(0), m_iUnk3C(0),
      m_iUnk40(0), m_iUnk44(0), m_iUnk48(0), m_iUnk4C(0), m_iUnk12C(0x103), m_iUnk130(1)
{}

// Placement-constructs a DCEEntryInit object on the provided storage buffer and returns a pointer to it.
// @fnv 0x00dce930
// src: GUESS 0x00dce930 (confidence: medium)
extern "C" DCEEntryInit* __fastcall SolverEntry_ConstructInPlace(void* storage, void*)
{
    __assume(storage != 0);
    return new (storage) DCEEntryInit;
}
