
// src/fallout_shared/havok/bgszonetargetlistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/bgszonetargetlistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/BGSZoneTargetListener.h"

extern int DAT_0104d9e0;

// The shared header has no constructor declaration; ECX carries the listener here.
// @fnv 0x0061ffb0
void* __fastcall ConstructZoneTargetListener(BGSZoneTargetListener* listener)
{
    *reinterpret_cast<void**>(listener) = &DAT_0104d9e0;
    listener->m_flags = 0;
    return listener;
}

void __cdecl _Deallocate(void* p);

// Calls FUN_00620110, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x006200e0
void* __thiscall BGSZoneTargetListener::Destroy(unsigned int flags)
{
    this->~BGSZoneTargetListener();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct ZoneLink
{
    int unk00;
    int unk04;
    void SetValue(int value, bool set);
    void Attach(ZoneLink* next);
};

// Sets or clears the flag bits in the embedded link, whose flags are at offset 0.
// @fnv 0x00620760
void ZoneLink::SetValue(int flags, bool set)
{
    if (set)
        unk00 |= flags;
    else
        unk00 &= ~flags;
}

void ourMemalignFree(int param);
// @fnv 0x0087e9b0
void CallWithParam(int param)
{
    ourMemalignFree(param);
}

struct FUN_0061fc10_shell
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void __thiscall FUN_0061fc10(unsigned int a, unsigned int b);
};

extern void* DAT_0104e3e8;

struct FUN_0062d840_shell
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* __thiscall TrapEntry_TrapEntry(unsigned int a, unsigned int b);
};

// Calls FUN_0061fc10 with a and b, sets the first field to point at DAT_0104e3e8, and returns this.
// @fnv 0x0062d840
// src: EXE 0x0062d840
void* __thiscall FUN_0062d840_shell::TrapEntry_TrapEntry(unsigned int a, unsigned int b)
{
    ((FUN_0061fc10_shell*)this)->FUN_0061fc10(a, b);
    m_iWordAt00 = &DAT_0104e3e8;
    return this;
}

struct Member140
{
    void __thiscall bhkTTNode_TESObjectREFR_bhkTTNode_TESObjectREFR(unsigned int a, unsigned int b);
};
extern int DAT_0104d9cc[];
struct FUN_0061fc10
{
    void* m0;
    char _4[16];
    int _14;
    FUN_0061fc10(unsigned int a, unsigned int b);
};
// Calls FUN_00620720 on the member at offset 4 with a and b, then sets m0 to DAT_0104d9cc and _14 to 0.
// @fnv 0x0061fc10
FUN_0061fc10::FUN_0061fc10(unsigned int uiFirst, unsigned int uiSecond)
{
    ((Member140*)((char*)this + 4))->bhkTTNode_TESObjectREFR_bhkTTNode_TESObjectREFR(uiFirst, uiSecond);
    m0 = DAT_0104d9cc;
    _14 = 0;
}

extern int DAT_0104d9d8;
struct FUN_0061fe70_shell
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void __thiscall TargetEntry_TargetEntry(unsigned int a, unsigned int b);
    void* __thiscall Construct(unsigned int a, unsigned int b);
};
// Calls FUN_0061fba0 with a and b, stores the address of DAT_0104d9d8 at this, and returns this.
// @fnv 0x0061fe70
void* __thiscall FUN_0061fe70_shell::Construct(unsigned int a, unsigned int b)
{
    TargetEntry_TargetEntry(a, b);
    *reinterpret_cast<void**>(this) = &DAT_0104d9d8;
    return this;
}

struct FUN_00620720_shell
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    FUN_00620720_shell* __thiscall bhkTTNode_TESObjectREFR_bhkTTNode_TESObjectREFR(void* a, void* b);
};

// Stores the two arguments into the object's fields and clears the other two pointers, then returns this.
// @fnv 0x00620720
// src: XBOX_PDB 0x00620720
FUN_00620720_shell* __thiscall FUN_00620720_shell::bhkTTNode_TESObjectREFR_bhkTTNode_TESObjectREFR(void* pFirst, void* pSecond)
{
    m_iThirdValue = pFirst;
    m_8 = pSecond;
    m_iWordAt00 = 0;
    m_iWordAt04 = 0;
    return this;
}

struct FUN_0061fef0_Node
{
    void* TargetEntry_QNextEntry();
};
struct FUN_0061fea0_shell
{
    char _pad[0x14];
    void* m_14;
    void ClearList();
};
// @fnv 0x0061fea0
void FUN_0061fea0_shell::ClearList()
{
    void* pNode;
    pNode = m_14;
    while (pNode != 0)
    {
        void* tmp;
        void* pNext;
        pNext = ((FUN_0061fef0_Node*)pNode)->TargetEntry_QNextEntry();
        tmp = pNode;
        CallWithParam((int)tmp);
        pNode = pNext;
    }
    m_14 = 0;
}

// Allocates and constructs a new FUN_0061fc10 object from the two unsigned int arguments and returns it.
// @fnv 0x0061ffe0
void* BGSZoneTargetListener::Create(unsigned int uiFirst, unsigned int uiSecond)
{
    return new FUN_0061fc10(uiFirst, uiSecond);
}

struct ZoneBase
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct ZoneNode : ZoneBase, ZoneLink
{
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
    static void* operator new(unsigned int size);
    static void operator delete(void*);
    ZoneNode(unsigned int a, unsigned int b);
};

struct ZoneList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    ZoneNode* head;
    ZoneNode* Find(unsigned int key);
    ZoneNode* FindOrCreateNode(unsigned int key, unsigned int data, int value);
};

// Looks up a node by key in the list, creating, initializing and prepending a new one if not found, then returns it.
// @fnv 0x0061fc70
ZoneNode* ZoneList::FindOrCreateNode(unsigned int key, unsigned int data, int value)
{
    ZoneNode* node = head ? Find(key) : 0;
    if (!node)
    {
        node = new ZoneNode(key, data);
        node->SetValue(value, 1);
        node->Attach(head);
        head = node;
    }
    return node;
}

struct NodeBase0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct NodeBase16
{
    NodeBase16* __thiscall bhkTTNode_RemoveFromList(NodeBase16* previous);
};
struct Node : NodeBase0, NodeBase16
{
};
struct Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    Node* node14;
    void __thiscall ZoneEntry_RemoveTargetEntry(Node* node);
};
void CallWithParam(int value);

// @fnv 0x0061ff30
// src: COMMUNITY 0x0061ff30
void Holder::ZoneEntry_RemoveTargetEntry(Node* node)
{
    if (node == 0)
        return;
    node14 = static_cast<Node*>(node->bhkTTNode_RemoveFromList(node14));
    Node* toRelease = node;
    CallWithParam((int)toRelease);
}

struct ZoneTargetNode
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

    static void* __cdecl operator new(unsigned int size);
    static void operator delete(void*);
    ZoneTargetNode(unsigned int a, unsigned int b);
};

// Allocates and constructs a ZoneTargetNode from the two given values and returns it.
// @fnv 0x00620060
void* BGSZoneTargetListener::CreateZoneTargetNode(unsigned int uiFirst, unsigned int uiSecond)
{
    return new ZoneTargetNode(uiFirst, uiSecond);
}

extern int DAT_0104d9c4;

struct S_0061fba0_Member
{
    void __thiscall bhkTTNode_TESObjectREFR_bhkTTNode_TESObjectREFR(unsigned int a, unsigned int b);
};

struct S_0061fba0_Sub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void __thiscall FUN_006815c0();
    void __thiscall hkVector4_setZero4();
};

struct S_0061fba0_Obj
{
    const void* vtbl;
    int unk04;
    int unk08;
    int unk0c;
    S_0061fba0_Member m_10;
    int unk14;
    int unk18;
    int unk1c;
    S_0061fba0_Sub m_20;
    S_0061fba0_Sub m_30;
    int unk40;
    S_0061fba0_Obj* __thiscall TargetEntry_TargetEntry(unsigned int a, unsigned int b);
};

// @fnv 0x0061fba0
// src: XBOX_PDB 0x0061fba0
S_0061fba0_Obj* __thiscall S_0061fba0_Obj::TargetEntry_TargetEntry(unsigned int a, unsigned int b)
{
    m_10.bhkTTNode_TESObjectREFR_bhkTTNode_TESObjectREFR(a, b);
    vtbl = (const void*)&DAT_0104d9c4;
    m_20.FUN_006815c0();
    m_30.FUN_006815c0();
    m_20.hkVector4_setZero4();
    m_30.hkVector4_setZero4();
    unk40 = 0x24;
    return this;
}

struct EmbeddedLink
{
    unsigned int unk00;
    EmbeddedLink* FUN_00726070();
};

struct OwnerPrefix
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
};

struct LinkedOwnerLayout : OwnerPrefix, EmbeddedLink
{
};

// Returns the embedded link call result cast to LinkedOwnerLayout*.
// @fnv 0x0061fef0
// src: XBOX_PDB 0x0061fef0
void* FUN_0061fef0_Node::TargetEntry_QNextEntry()
{
    return static_cast<LinkedOwnerLayout*>(reinterpret_cast<LinkedOwnerLayout*>(this)->FUN_00726070());
}

struct Construct : ZoneNode
{
    Construct(unsigned int key, unsigned int data);
};

struct FUN_0057b700_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    ZoneNode* unk14;
    ZoneNode* __thiscall ZoneEntry_AddTrapTarget(unsigned int key, unsigned int arg2, unsigned int arg3);
};

// Finds a ZoneNode by key in the list, or creates and attaches a new FUN_0061fe70 node with the given key, arg2, and arg3 values.
// @fnv 0x0061fd70
// src: COMMUNITY 0x0061fd70
ZoneNode* FUN_0057b700_class::ZoneEntry_AddTrapTarget(unsigned int key, unsigned int auiData, unsigned int auiValue)
{
    ZoneNode* result = (unk14 != 0) ? ((ZoneList*)this)->Find(key) : 0;
    if (result == 0)
    {
        result = new Construct(key, auiData);
        result->SetValue(auiValue, 1);
        result->Attach((ZoneLink*)unk14);
        unk14 = result;
    }
    return result;
}
