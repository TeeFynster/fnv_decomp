
// src/fallout/magic/bhkcharacterlistenerspell.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/bhkcharacterlistenerspell.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/NiObject.h"
#include "../../../include/NiRTTI.h"
#include "../../../include/bhkCharacterProxy.h"

extern const NiRTTI g_01268344;

// @fnv 0x00806f00
const NiRTTI* bhkCharacterProxy::GetRTTI() const
{
    return &g_01268344;
}

// @fnv 0x00806f10
unsigned int __fastcall FUN_00806f10(bhkCharacterProxy*)
{
    return 0xc0;
}

const char* __cdecl FUN_00458b20();
int __fastcall GetReferenceFlags(void*);
struct ProxyHolder
{
    const char* FUN_00cac950();
};
struct Holder00807080
{
    const char* FUN_00807080();
};
// Looks up a proxy holder via GetReferenceFlags; if found, returns its FUN_00cac950 result, otherwise returns FUN_00458b20's result.
// @fnv 0x00807080
const char* Holder00807080::FUN_00807080()
{
    ProxyHolder* pProxy = (ProxyHolder*)GetReferenceFlags(this);
    const char* pResult = FUN_00458b20();
    if (pProxy)
    {
        ((NiObject*)this)->NiObject::GetStreamableRTTI();
        pResult = pProxy->FUN_00cac950();
        ((NiObject*)this)->NiObject::GetStreamableRTTI();
    }
    return pResult;
}

#include <xmmintrin.h>
struct Owner1;
struct Item;
struct Node;
struct Arg2;

struct Node2
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* __thiscall FUN_0043b540();
};

struct Node
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
    Node2* m_48;
    int unk4C;
};

struct Str20
{
    int unk00;
    void __thiscall FUN_008c71b0(void* p);
    int __thiscall FUN_0043b4d0();
};

struct __declspec(align(16)) Vec16
{
    __m128 m_v;
    int __thiscall FUN_005532a0(float a, float b, float c, float d);
};

struct Item
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
    void __thiscall FUN_004a3f10(int p);
};

struct ItemSub
{
    void __thiscall FUN_004a3f10(int p);
};

struct Arg2
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
    Item* m_48;
    int m_4C;
};

struct Owner1
{
    Node* __thiscall FUN_00807770(int i);
};

struct Global
{
    int __thiscall FUN_0089f4e0();
};

extern Global* g_pGlobalDea3c;
int __cdecl FUN_004b59f0(void* p);

struct ProxyUpdate
{
    int __thiscall FUN_00807080();
    int __thiscall FUN_00807730(void* p);
    void __thiscall FUN_00806f20(Owner1* a1, Arg2* a2);
};

// For each item, checks its node's m_48 and calls FUN_004a3f10 on the item when branch conditions are met.
// @fnv 0x00806f20
void ProxyUpdate::FUN_00806f20(Owner1* apOwner, Arg2* apArgs)
{
    int count = apArgs->m_4C;
    for (int i = 0; i < count; i++)
    {
        Item* item = apArgs->m_48 + i;
        Node* pNode = apOwner->FUN_00807770(i);
        int iResult1 = FUN_004b59f0(pNode->m_48);
        Str20 s;
        s.FUN_008c71b0(pNode->m_48->FUN_0043b540());
        int iResult3 = s.FUN_0043b4d0();
        if (iResult1 == 0)
        {
            if (iResult3 != 0x1e)
            {
                ((ItemSub*)&item->unk10)->FUN_004a3f10(this->FUN_00807080());
                Vec16 t;
                item->FUN_004a3f10(t.FUN_005532a0(0.0f, 0.0f, 0.0f, 1.0f));
            }
        }
        else
        {
            int iResult4 = this->FUN_00807730(pNode->m_48);
            if (iResult4 != 0 && iResult4 == g_pGlobalDea3c->FUN_0089f4e0())
            {
                ((ItemSub*)&item->unk10)->FUN_004a3f10(this->FUN_00807080());
                Vec16 t;
                item->FUN_004a3f10(t.FUN_005532a0(0.0f, 0.0f, 0.0f, 1.0f));
                break;
            }
        }
    }
}
