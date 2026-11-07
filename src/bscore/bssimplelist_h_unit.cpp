#include "../../include/BSStringT.h"
// bscore/bssimplelist_h_unit.cpp: RangeConsumer, CopyOwner, Thing (41 functions)

#include "bssimplelist_decls.h"

// Use this unit's complete list declaration in the shared magic headers.
#define FNV64_BSSIMPLELIST_DEFINED

#include "../../include/BGSCameraPath.h"
#include "../../include/BGSHeadPart.h"
#include "../../include/BGSTerminal.h"
#include "../../include/TESDataHandler.h"
#include "../../include/TESObjectDOOR.h"
#include "../../include/TESTopicInfoData.h"
#include "../../include/TESWeather.h"
#include "bssimplelist.inl"

#include "../../include/EnchantmentItem.h"
#include "../../include/MagicItem.h"
#include "../../include/SL.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESEnchantableForm.h"
#include "../../include/TESForm.h"
#include "../../include/TESModelTextureSwap.h"

struct ListX
{
    int m_item;
    ListX* m_pkNext;
    ~ListX();
};
struct FUN_00408b60 : ListX
{
    void DestroyAllItems();
    ~FUN_00408b60();
};

// @fnv 0x00408b60
FUN_00408b60::~FUN_00408b60()
{
    DestroyAllItems();
}

struct FUN_004b0880 : SL
{
    FUN_004b0880();
};

// Constructs the object and clears its list by calling RemoveAll.
// @fnv 0x004b0880
FUN_004b0880::FUN_004b0880()
{
    RemoveAll();
}

struct FUN_004ee7d0_obj
{
    void BGSDecalNode_RemoveDecals();
};
struct FUN_004ee7d0_node
{
    FUN_004ee7d0_obj** _ref_006815c0();
    FUN_004ee7d0_node* FUN_00726070();
};
extern FUN_004ee7d0_node g_011c7d20;

// Walks the node list from g_011c7d20, calling FUN_004ee770 on each node's referenced object when non-null.
// @fnv 0x004ee7d0
// src: COMMUNITY 0x004ee7d0
void BGSDecalNode_RemoveAllDecals()
{
    FUN_004ee7d0_node* node = &g_011c7d20;
    while (node)
    {
        FUN_004ee7d0_obj* obj = *node->_ref_006815c0();
        if (obj)
            obj->BGSDecalNode_RemoveDecals();
        node = node->FUN_00726070();
    }
}

struct FUN_004f66c0_node
{
    TESForm** _ref_006815c0();
    FUN_004f66c0_node* FUN_00726070();
};
struct FUN_004f66c0_shell
{
    TESForm* TESRegionList_HasRegion(int id);
};
// Walks the node chain starting at this+4 and returns the first item whose FUN_0084e3a0() equals id, or 0 if none matches.
// @fnv 0x004f66c0
// src: COMMUNITY 0x004f66c0
TESForm* FUN_004f66c0_shell::TESRegionList_HasRegion(int id)
{
    FUN_004f66c0_node* node = this ? (FUN_004f66c0_node*)((char*)this + 4) : 0;
    while (node)
    {
        if (*node->_ref_006815c0() && (*node->_ref_006815c0())->GetHavokWorldObjectCountInSceneGraph_0084e3a0() == id)
            return *node->_ref_006815c0();
        node = node->FUN_00726070();
    }
    return 0;
}

struct FUN_005549d0_obj
{
    void TESObjectREFR_TogglePrimitive(bool);
};
struct FUN_005549d0_node
{
    FUN_005549d0_obj** _ref_006815c0();
    FUN_005549d0_node* FUN_00726070();
};
struct FUN_005549d0_shell
{
    void TESObjectCELL_TogglePrimitives(bool flag);
};

// Walks the linked list starting at this+0xac and calls FUN_00577390(flag) on each referenced object while the reference is non-null.
// @fnv 0x005549d0
// src: COMMUNITY 0x005549d0
void FUN_005549d0_shell::TESObjectCELL_TogglePrimitives(bool flag)
{
    FUN_005549d0_node* node = (FUN_005549d0_node*)((char*)this + 0xac);
    while (node && *node->_ref_006815c0() != 0)
    {
        (*node->_ref_006815c0())->TESObjectREFR_TogglePrimitive(flag);
        node = node->FUN_00726070();
    }
}

struct FUN_0060f3a0_obj
{
    void* FUN_0060f410(int flags);
};
struct FUN_0060f3a0_node
{
    FUN_0060f3a0_obj** _ref_006815c0();
    bool _ref_008256d0();
    void _ref_0063f7b0();
};
struct FUN_0060f3a0_shell
{
    FUN_0060f3a0_node* GetPosition();
    void ProcessEntries_0060f3a0();
};
// @fnv 0x0060f3a0
// src: GUESS 0x0060f3a0 (confidence: low)
void FUN_0060f3a0_shell::ProcessEntries_0060f3a0()
{
    FUN_0060f3a0_node* node = GetPosition();
    while (node && !node->_ref_008256d0())
    {
        FUN_0060f3a0_obj* item = *node->_ref_006815c0();
        FUN_0060f3a0_obj* pItem = item;
        pItem ? pItem->FUN_0060f410(1) : 0;
        node->_ref_0063f7b0();
    }
}

struct FUN_006137b0_node
{
    TESForm** _ref_006815c0();
    FUN_006137b0_node* FUN_00726070();
};
struct FUN_006137b0_shell;
FUN_006137b0_node* __fastcall NiAVObject_GetWorldTranslate(FUN_006137b0_shell*);
struct FUN_006137b0_shell
{
    TESForm* FindByKey(int key);
};

// Walks the node chain from this shell and returns the first object whose FUN_0084e3a0() equals key, or 0 if none is found.
// @fnv 0x006137b0
TESForm* FUN_006137b0_shell::FindByKey(int key)
{
    FUN_006137b0_node* node = NiAVObject_GetWorldTranslate(this);
    while (node && *node->_ref_006815c0() != 0)
    {
        if ((*node->_ref_006815c0())->GetHavokWorldObjectCountInSceneGraph_0084e3a0() == key)
            return *node->_ref_006815c0();
        node = node->FUN_00726070();
    }
    return 0;
}

struct SoundListView
{
    void AddTail(char* const&);
};
struct FUN_00613810_shell
{
    int FindByKey(int);
    void TESRace_AddHair(char* item);
};
SoundListView* __fastcall NiAVObject_GetWorldTranslate(FUN_00613810_shell*);

// Adds item to the list returned by FUN_0045bb80 unless item is null or FindByKey reports it already present.
// @fnv 0x00613810
// src: COMMUNITY 0x00613810
void FUN_00613810_shell::TESRace_AddHair(char* item)
{
    if (item == 0 || FindByKey(((TESForm*)item)->GetHavokWorldObjectCountInSceneGraph_0084e3a0()))
        return;
    NiAVObject_GetWorldTranslate(this)->AddTail(item);
}

struct FUN_006138b0_node
{
    TESForm** _ref_006815c0();
    FUN_006138b0_node* FUN_00726070();
};
struct FUN_006138b0_shell
{
    FUN_006138b0_node* GetBGSRecipeCategoryList();
    TESForm* FindRecipeCategoryById(int id);
};
// Walks the recipe category list and returns the item whose referenced id equals id, or null if none matches.
// @fnv 0x006138b0
TESForm* FUN_006138b0_shell::FindRecipeCategoryById(int id)
{
    FUN_006138b0_node* node = GetBGSRecipeCategoryList();
    while (node && *node->_ref_006815c0())
    {
        if ((*node->_ref_006815c0())->GetHavokWorldObjectCountInSceneGraph_0084e3a0() == id)
            return *node->_ref_006815c0();
        node = node->FUN_00726070();
    }
    return 0;
}

namespace fnv_00613910 {
struct SoundListView
{
    void AddTail(char* const&);
};
struct FUN_00613910_shell
{
    int FindRecipeCategoryById(int);
    void TESRace_AddEyeColor(char* item);
};
SoundListView* __fastcall GetBackTexture(FUN_00613910_shell*);

// Adds item to the list returned by FUN_00503650 unless item is null or FindRecipeCategoryById on its FUN_0084e3a0 result is nonzero.
// @fnv 0x00613910
// src: COMMUNITY 0x00613910
void FUN_00613910_shell::TESRace_AddEyeColor(char* item)
{
    if (item == 0 || FindRecipeCategoryById(((TESForm*)item)->GetHavokWorldObjectCountInSceneGraph_0084e3a0()))
        return;
    GetBackTexture(this)->AddTail(item);
}
}  // namespace fnv_00613910

namespace fnv_00623430 {
struct FUN_006234b0
{
    FUN_006234b0();
    ~FUN_006234b0();
    virtual void Run();
};
struct FUN_00623430 : FUN_006234b0
{
    SL list;
    FUN_00623430();
    virtual void Run();
};
extern FUN_00623430* DAT_011cc224;
// Sets DAT_011cc224 to this and clears the list by calling RemoveAll.
// @fnv 0x00623430
FUN_00623430::FUN_00623430()
{
    DAT_011cc224 = this;
    list.RemoveAll();
}
}  // namespace fnv_00623430

struct FUN_0066deb0;
struct FUN_0066deb0_vec
{
    float x, y, z;
    FUN_0066deb0_vec();
};
struct G2
{
    void AddHead(FUN_0066deb0* const& item);
};
struct FUN_0066deb0
{
    FUN_0066deb0* prev;
    FUN_0066deb0* next;
    FUN_0066deb0_vec pos;
    int id;
    int flags;
    FUN_0066deb0();
};
extern FUN_0066deb0_vec _NiPoint3_ZERO;
extern int DAT_011d60cc;
extern G2 g_011d6124;
// Initializes prev/next to null, pos to zero, flags to 0, assigns a fresh id from DAT_011d60cc, increments it, and adds this to g_011d6124.
// @fnv 0x0066deb0
FUN_0066deb0::FUN_0066deb0()
{
    prev = 0;
    next = 0;
    pos = _NiPoint3_ZERO;
    flags = 0;
    id = DAT_011d60cc;
    DAT_011d60cc++;
    g_011d6124.AddHead(this);
}

namespace fnv_0083b8d0 {
struct ListX
{
    int m_item;
    ListX* m_pkNext;
    ~ListX();
};
struct FUN_0083b8d0 : ListX
{
    void Conversation_ClearList();
    ~FUN_0083b8d0();
};

// @fnv 0x0083b8d0
FUN_0083b8d0::~FUN_0083b8d0()
{
    Conversation_ClearList();
}
}  // namespace fnv_0083b8d0

struct FUN_0083e110_node
{
    int** _ref_006815c0();
    FUN_0083e110_node* FUN_00726070();
};
struct FUN_0083e110_shell
{
    char pad[0x20];
    FUN_0083e110_node* cur;
    bool AdvanceAndCheckNode();
};

// Advances cur to cur->FUN_00726070() when set, then returns whether cur is non-null and its referenced value is non-zero.
// @fnv 0x0083e110
bool FUN_0083e110_shell::AdvanceAndCheckNode()
{
    if (cur)
        cur = cur->FUN_00726070();
    return cur && *cur->_ref_006815c0() != 0;
}

struct FUN_008c5000_item
{
    int id;
};
struct FUN_008c5000_node
{
    FUN_008c5000_item** _ref_006815c0();
    FUN_008c5000_node* FUN_00726070();
};
struct FUN_008c5000_shell
{
    FUN_008c5000_item* Actor_GetCastPowerItem(int id);
};
// @fnv 0x008c5000
// src: COMMUNITY 0x008c5000
FUN_008c5000_item* FUN_008c5000_shell::Actor_GetCastPowerItem(int id)
{
    FUN_008c5000_item* found = 0;
    if (id && *((FUN_008c5000_node*)((char*)this + 0xf4))->_ref_006815c0())
    {
        FUN_008c5000_node* node = (FUN_008c5000_node*)((char*)this + 0xf4);
        while (node && !found)
        {
            if (*node->_ref_006815c0() && (*node->_ref_006815c0())->id == id)
                found = *node->_ref_006815c0();
            node = node->FUN_00726070();
        }
    }
    return found;
}

struct FUN_008c5090_node
{
    int** _ref_006815c0();
    FUN_008c5090_node* FUN_00726070();
    void RemoveAll();
};
struct FUN_008c5090_shell
{
    void DeleteAllItems();
};
// Walks the node list at offset 0xf4, deletes each referenced item, then removes all nodes from the list.
// @fnv 0x008c5090
void FUN_008c5090_shell::DeleteAllItems()
{
    FUN_008c5090_node* node = (FUN_008c5090_node*)((char*)this + 0xf4);
    while (node)
    {
        int* item = *node->_ref_006815c0();
        if (item)
            delete item;
        node = node->FUN_00726070();
    }
    ((FUN_008c5090_node*)((char*)this + 0xf4))->RemoveAll();
}

struct FUN_008d1560_ref
{
    virtual void Slot0();
};
struct FUN_008d1560_list
{
    bool _ref_008256d0();
    FUN_008d1560_ref** _ref_006815c0();
    void _ref_0063f7b0();
};
extern FUN_008d1560_list g_011dfe14;

typedef void(__thiscall* FUN_008d1560_fn)(void*);

// Loops while g_011dfe14._ref_008256d0() is false, calling a virtual slot on each element from _ref_006815c0() and then _ref_0063f7b0().
// @fnv 0x008d1560
// src: COMMUNITY 0x008d1560
void BSDoorHavokController_ReenableDoors()
{
    while (!g_011dfe14._ref_008256d0())
    {
        void** pref = (void**)*g_011dfe14._ref_006815c0();
        ((FUN_008d1560_fn)(*(void***)pref)[0x1c4 / 4])(pref);
        g_011dfe14._ref_0063f7b0();
    }
}

struct FUN_00964100_item
{
    int id;
};
struct FUN_00964100_node
{
    FUN_00964100_item** _ref_006815c0();
    FUN_00964100_node* FUN_00726070();
};
struct FUN_00964100_shell
{
    FUN_00964100_item* PlayerCharacter_GetPlayerAction(int id);
};
// Walks the node list starting at this+0x60c and returns the first item whose id matches, or null if none is found.
// @fnv 0x00964100
// src: XBOX_PDB 0x00964100
FUN_00964100_item* FUN_00964100_shell::PlayerCharacter_GetPlayerAction(int id)
{
    FUN_00964100_item* item = 0;
    if (!*(FUN_00964100_node**)((char*)this + 0x60c))
        return 0;
    FUN_00964100_node* node = *(FUN_00964100_node**)((char*)this + 0x60c);
    FUN_00964100_item* found = 0;
    while (node && *node->_ref_006815c0() && !item)
    {
        found = *node->_ref_006815c0();
        if (found && found->id == id)
            item = found;
        node = node->FUN_00726070();
    }
    return item;
}

struct FUN_00966bb0_item;
struct FUN_00966bb0_node
{
    FUN_00966bb0_item** _ref_006815c0();
    FUN_00966bb0_node* FUN_00726070();
};
struct FUN_00966bb0_shell
{
    FUN_00966bb0_item* GetItemAt(int index);
};
// Walks the linked list starting at this+0x5e4 and returns the item at the given index, or 0 if the index is out of range.
// @fnv 0x00966bb0
FUN_00966bb0_item* FUN_00966bb0_shell::GetItemAt(int index)
{
    FUN_00966bb0_node* node = (FUN_00966bb0_node*)((char*)this + 0x5e4);
    int iCurrent = 0;
    while (node && *node->_ref_006815c0())
    {
        if (iCurrent == index)
            return *node->_ref_006815c0();
        node = node->FUN_00726070();
        iCurrent++;
    }
    return 0;
}

struct Flt
{
    operator unsigned int() const;
};
struct FUN_00978990_shell
{
    Flt* _ref_006815c0();
    FUN_00978990_shell* FUN_00726070();
    unsigned int CountReferencedNodes();
};

// Walks the linked list from this node, counting nodes whose referenced Flt is non-zero, and returns the count.
// @fnv 0x00978990
unsigned int FUN_00978990_shell::CountReferencedNodes()
{
    FUN_00978990_shell* pNode;
    unsigned int result;
    result = 0;
    pNode = this;
    while (pNode)
    {
        if (*pNode->_ref_006815c0())
            result = result + 1;
        pNode = pNode->FUN_00726070();
    }
    return result;
}

namespace fnv_009ac940 {
struct List_009e03e0
{
    void RemoveAll();
};
struct ListX : List_009e03e0
{
    int m_item;
    ListX* m_pkNext;
    ~ListX();
};
struct FUN_009ac940
{
    int a;
    int b;
    ListX list;
    ~FUN_009ac940();
};

// Destructor that clears the contained list by calling RemoveAll on it.
// @fnv 0x009ac940
FUN_009ac940::~FUN_009ac940()
{
    list.RemoveAll();
}
}  // namespace fnv_009ac940

struct FUN_004f6730_shell
{
    int m_pad00;
    FUN_004f66c0_node m_kNode;
    bool HasEqualListContents(FUN_004f6730_shell* other);
};

// @fnv 0x004f6730
// src: GUESS 0x004f6730 (confidence: medium)
bool FUN_004f6730_shell::HasEqualListContents(FUN_004f6730_shell* other)
{
    FUN_004f66c0_node* list2 = this ? &m_kNode : 0;
    FUN_004f66c0_node* list1 = other ? &other->m_kNode : 0;
    if (!list2 || !list1)
    {
        return false;
    }
    while (list2)
    {
        if (*list2->_ref_006815c0() != *list1->_ref_006815c0())
        {
            return false;
        }
        list2 = list2->FUN_00726070();
        list1 = list1->FUN_00726070();
        if (!list2 && !list1)
        {
            return true;
        }
        else if ((!list2 && list1) || (list2 && !list1))
        {
            return false;
        }
    }
    return true;
}

struct FUN_004f2770_Class
{
    void* PlayerCharacter_GetAllOccupiedRegions();
};
extern FUN_004f2770_Class* _g_thePlayer;

struct RegionList : public FUN_004f66c0_node
{
    virtual void Dummy();
};

// @fnv 0x005a6280
// src: EXE 0x005a6280
bool Cmd_PlayerInRegion_Eval(void* apUnused, void* apRegion, void* apUnused2, double& result)
{
    result = 0.0;
    TESForm* region = (TESForm*)apRegion;
    RegionList* iter = (RegionList*)_g_thePlayer->PlayerCharacter_GetAllOccupiedRegions();
    while (iter && *iter->_ref_006815c0())
    {
        if ((*iter->_ref_006815c0())->GetHavokWorldObjectCountInSceneGraph_0084e3a0() == region->GetHavokWorldObjectCountInSceneGraph_0084e3a0())
        {
            result = 1.0;
            return true;
        }
        iter = (RegionList*)iter->FUN_00726070();
    }
    return true;
}

bool __cdecl Object_ComputeValue_0061f420(unsigned int, unsigned int);

// @fnv 0x0061f360
// src: GUESS 0x0061f360 (confidence: low)
void Object_ProcessEntries_0061f360(void* pItem, void* pNode)
{
    if (pItem && pNode)
    {
        if (((FUN_0060f3a0_node*)pNode)->_ref_008256d0())
        {
            ((G2*)pNode)->AddHead((FUN_0066deb0* const&)pItem);
        }
        else
        {
            void* node = pNode;
            while (node && !((FUN_0060f3a0_node*)node)->_ref_008256d0())
            {
                void* item = *((FUN_0060f3a0_node*)node)->_ref_006815c0();
                if (item == pItem)
                    return;

                if (Object_ComputeValue_0061f420((unsigned int)item, (unsigned int)pItem))
                {
                    ((G2*)node)->AddHead((FUN_0066deb0* const&)pItem);
                    return;
                }

                if (!((FUN_004f66c0_node*)node)->FUN_00726070())
                {
                    ((SoundListView*)node)->AddTail((char* const&)pItem);
                    return;
                }

                node = ((FUN_004f66c0_node*)node)->FUN_00726070();
            }
        }
    }
}

struct Standin_Item
{
    void* m_key;
};

struct Standin_ListBase
{
    bool _ref_008256d0();
    Standin_Item** _ref_006815c0();
    Standin_ListBase* FUN_00726070();
};

struct FUN_007d8040_shell : public Standin_ListBase
{
    virtual void Dummy();
    bool RemoveItemNode(Standin_ListBase* cur, Standin_ListBase* prev);
    bool RemoveByKey(void* param1);
};

// Searches the list for the node whose item key equals param1 and removes it via RemoveItemNode, returning false if param1 is null or the list is empty.
// @fnv 0x007d8040
bool FUN_007d8040_shell::RemoveByKey(void* pKey)
{
    if (!pKey || _ref_008256d0())
        return false;

    Standin_ListBase* _pNode = this;
    Standin_ListBase* pPrevNode = this;
    while (_pNode && (*_pNode->_ref_006815c0())->m_key != pKey)
    {
        pPrevNode = _pNode;
        _pNode = _pNode->FUN_00726070();
    }
    return RemoveItemNode(_pNode, pPrevNode);
}

struct BGSLoadFormBuffer;

struct Conversation
{
    void InitLoadGame_0083c420(BGSLoadFormBuffer*);
};

struct FUN_008363a0_item
{
    int target;
};

struct FUN_008363a0_node
{
    bool _ref_008256d0();
    FUN_008363a0_item** _ref_006815c0();
    void _ref_0063f7b0();
    void _ref_00905330(FUN_008363a0_item**);
    FUN_008363a0_node* FUN_00726070();
};

struct FUN_008363a0_shell
{
    Conversation* m_conv;
    char pad04[0x14];
    FUN_008363a0_node m_kNode;
    void ProcessEntries_008363a0(BGSLoadFormBuffer* buf);
};

// @fnv 0x008363a0
// src: GUESS 0x008363a0 (confidence: low)
void FUN_008363a0_shell::ProcessEntries_008363a0(BGSLoadFormBuffer* pBuffer)
{
    if (m_conv)
    {
        m_conv->InitLoadGame_0083c420(pBuffer);
    }
    FUN_008363a0_node* list = (FUN_008363a0_node*)&m_kNode;
    FUN_008363a0_node* prev = 0;
    while (list && !list->_ref_008256d0())
    {
        FUN_008363a0_item* item = *list->_ref_006815c0();
        bool remove = false;
        if (item)
        {
            if (!item->target)
            {
                remove = true;
            }
        }
        else
        {
            remove = true;
        }
        if (remove)
        {
            if (prev)
            {
                prev->_ref_00905330(list->_ref_006815c0());
                list = prev->FUN_00726070();
            }
            else
            {
                list->_ref_0063f7b0();
            }
        }
        else
        {
            prev = list;
            list = list->FUN_00726070();
        }
    }
}



struct FUN_0083dec0_item
{
    void* FUN_0083c720(int);
};

struct FUN_0083dec0_node
{
    bool _ref_008256d0();
    FUN_0083dec0_item** _ref_006815c0();
    void _ref_0063f7b0();
};

struct FUN_0083dec0 : ::BSStringT<char>
{
    char stringTailPadding[4];
    ListX m_kNode;
    char m_pad14[0x10];
    bool m_flag;
    ~FUN_0083dec0();
};

// @fnv 0x0083dec0
FUN_0083dec0::~FUN_0083dec0()
{
    if (!m_flag)
    {
        FUN_0083dec0_node* node = (FUN_0083dec0_node*)&m_kNode;
        while (node && !node->_ref_008256d0())
        {
            FUN_0083dec0_item* item = *node->_ref_006815c0();
            FUN_0083dec0_item* p = item;
            p ? p->FUN_0083c720(1) : 0;
            node->_ref_0063f7b0();
        }
    }
}

void* __cdecl operator new(unsigned int);

struct Item_009b1630
{
    int id;
    float value;
};

struct FUN_009b1630_node
{
    bool _ref_008256d0();
    Item_009b1630** _ref_006815c0();
    FUN_009b1630_node* FUN_00726070();
};

struct Container_009b1630
{
    char pad[8];
    G2 list;
};

struct FUN_009b1630_shell
{
    void Explosion_AddLimbTarget(Container_009b1630* container, int id, float value);
};

// @fnv 0x009b1630
// src: XBOX_PDB 0x009b1630
void FUN_009b1630_shell::Explosion_AddLimbTarget(Container_009b1630* container, int id, float value)
{
    int iNodeCount = 0;
    FUN_009b1630_node* pNode;
    Item_009b1630* pItem = 0;
    pNode = (FUN_009b1630_node*)&container->list;
    while (pNode && !pNode->_ref_008256d0() && (!pItem || pItem->id != id))
    {
        iNodeCount++;
        Item_009b1630* item = *pNode->_ref_006815c0();
        pNode = pNode->FUN_00726070();
        if (!pItem || pItem->value > item->value || pItem->id == id)
        {
            pItem = item;
        }
    }
    if (pItem && iNodeCount >= 2)
    {
        pItem->id = id;
        pItem->value = value;
    }
    else
    {
        pItem = new Item_009b1630;
        pItem->id = id;
        pItem->value = value;
        container->list.AddHead((FUN_0066deb0* const&)pItem);
    }
}

struct FUN_009b3490_shell
{
    ~FUN_009b3490_shell();
};

void __fastcall Projectile_SpawnMuzzleFlash(void*);

struct Standin_009b3400
{
    void ClearList();
};

// Sets the float at offset 0x150 to zero, deletes every item in the list at 0x88, calls FUN_009c2ff0, and clears the byte at 0x90.
// @fnv 0x009b3400
void Standin_009b3400::ClearList()
{
    *(float*)((char*)this + 0x150) = 0.0f;
    while (!((FUN_0060f3a0_node*)((char*)this + 0x88))->_ref_008256d0())
    {
        FUN_009b3490_shell* item = *(FUN_009b3490_shell**)((FUN_0060f3a0_node*)((char*)this + 0x88))->_ref_006815c0();
        delete item;
        ((FUN_0060f3a0_node*)((char*)this + 0x88))->_ref_0063f7b0();
    }
    Projectile_SpawnMuzzleFlash(this);
    *(char*)((char*)this + 0x90) = 0;
}

struct Item_009b0e00
{
    int m_iKey;
    bool m_bA;
    bool m_bB;
    int m_unk08;
    int m_unk0C;
    Item_009b0e00();
};
struct FUN_009b0f40 : Item_009b0e00
{
    FUN_009b0f40();
};
struct Node_009b0e00
{
    bool _ref_008256d0();
    Item_009b0e00** _ref_006815c0();
    Node_009b0e00* FUN_00726070();
};
struct S009b0e00
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
    Node_009b0e00 m_kNode;
    Item_009b0e00* FindOrCreateItem(int iKey, bool bA, bool bB);
};

// Searches the linked list for an item with matching m_iKey, updates its m_bA/m_bB flags, or allocates a new item and adds it to the list.
// @fnv 0x009b0e00
Item_009b0e00* S009b0e00::FindOrCreateItem(int iKey, bool bA, bool bB)
{
    Node_009b0e00* pNode;
    Item_009b0e00* pNew;
    {
        Item_009b0e00* pItem = 0;
        pNode = &m_kNode;
        while (pNode && !pNode->_ref_008256d0())
        {
            pItem = *pNode->_ref_006815c0();
            if (pItem && pItem->m_iKey == iKey)
            {
                if (bA && !pItem->m_bA)
                    pItem->m_bA = bA;
                if (bB && !pItem->m_bB)
                    pItem->m_bB = bB;
                return pItem;
            }
            pNode = pNode->FUN_00726070();
        }
    }
    pNew = new FUN_009b0f40;
    pNew->m_iKey = iKey;
    pNew->m_bA = bA;
    pNew->m_bB = bB;
    ((G2*)&m_kNode)->AddHead(*(FUN_0066deb0**)&pNew);
    return pNew;
}

class B3B930Item
{
  public:
    ~B3B930Item();
};

class B3B930List
{
  public:
    bool IsEmpty();
    B3B930Item** GetItem();
    void RemoveHead();
    void Conversation_ClearList();

    B3B930Item* m_pkItem;
    B3B930List* m_pkNext;
    int m_iArrayLength;
};

// @fnv 0x0083b930
// src: XBOX_PDB 0x0083b930
void B3B930List::Conversation_ClearList()
{
    B3B930List* pkList = this;
    while (pkList && !pkList->IsEmpty())
    {
        delete *pkList->GetItem();
        pkList->RemoveHead();
    }
    m_iArrayLength = 0;
}

struct CleanupItem
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual int Destroy(bool);
};
struct CleanupList
{
    void FUN_00470470();
};
// Iterates the linked list from this, calls Destroy(true) on each referenced item, then invokes FUN_00470470 on this.
// @fnv 0x00408bc0
void FUN_00408b60::DestroyAllItems()
{
    CleanupItem* item;
    for (FUN_004ee7d0_node* current = (FUN_004ee7d0_node*)this;
         current && (item = (CleanupItem*)*current->_ref_006815c0()) != 0; current = current->FUN_00726070())
    {
        CleanupItem* object = item;
        CleanupItem* callObject = object;
        callObject ? callObject->Destroy(true) : 0;
    }
    ((CleanupList*)this)->FUN_00470470();
}

struct RangeEntry
{
    virtual void Slot0();
    virtual int Enabled();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void* Get(int);
};
struct RangeNode
{
    RangeEntry* item;
    RangeNode* next;
    RangeEntry** FUN_006815c0();
    RangeNode* FUN_00726070();
};
struct RangeHeader
{
    virtual void Slot0();
};
struct RangeHolder : RangeHeader, RangeNode
{
};
struct RangeConsumer
{
    void AddIfAbsent(void*);
    void TESRegionGrassObjectList_MergeLists(float, RangeHolder*, float);
};
// @fnv 0x004f61d0
// src: XBOX_PDB 0x004f61d0
void RangeConsumer::TESRegionGrassObjectList_MergeLists(float input, RangeHolder* holder, float other)
{
    RangeNode* position4 = 0;
    void* item = 0;
    float first3;
    float second;
    if (input > 1.0)
        first3 = (float)(input / 100.0);
    else
        first3 = input;
    if (other > 1.0)
        second = (float)(other / 100.0);
    else
        second = other;
    if (!holder || first3 < 0.0 || first3 > 1.0 || second < 0.0 || second > 1.0)
    {
        return;
    }
    position4 = static_cast<RangeNode*>(holder);
    while (position4 && *position4->FUN_006815c0())
    {
        if (!(*position4->FUN_006815c0())->Enabled())
        {
            position4 = position4->FUN_00726070();
            continue;
        }
        item = (*position4->FUN_006815c0())->Get(0);
        AddIfAbsent(item);
        position4 = position4->FUN_00726070();
    }
}

struct FUN_005ae380_node : BSSimpleList<InventoryStackRecord*>
{
    int FUN_005ae380();
};

struct FUN_00591a40_fallback
{
    int unk00;
    void* TESModel_GetModel();
};

struct FUN_00591a40_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_00591a40_fallback m_fallback;
    int unk1C;
    int unk20;
    int unk24;
    FUN_005ae380_node m_kNode;
    int m_lastIndex;
    void* GetRandomItem();
};

// Returns a random item from the list, avoiding repeating the last index, or falls back to m_fallback when the list is empty or the pick is null.
// @fnv 0x00591a40
void* FUN_00591a40_class::GetRandomItem()
{
    int count = m_kNode.FUN_005ae380();
    if (m_kNode.IsEmpty() && count == 0)
        return m_fallback.TESModel_GetModel();
    else if (count == 1)
        return m_kNode.GetItem();
    else
    {
        BSSimpleList<InventoryStackRecord*>* node = &m_kNode;
        int index = GetRandomNumberInRange(0, m_kNode.FUN_005ae380());

        if (m_lastIndex != 0 && m_lastIndex == index)
        {
            index = 0;
            m_lastIndex = index;
        }
        else if (m_lastIndex == 0 && m_lastIndex == index)
        {
            index = 1;
            m_lastIndex = index;
        }
        else
        {
            m_lastIndex = index;
        }

        while (node != 0 && index--)
        {
            node = node->GetNext();
        }

        if (node != 0 && node->GetItem() != 0)
            return node->GetItem();
    }

    return m_fallback.TESModel_GetModel();
}

struct CopyPair
{
    int first, second;
};
struct CopyList
{
    CopyPair* data;
    CopyList* next;
    CopyList();
    CopyPair** FUN_006815c0();
    bool FUN_008256d0();
    CopyList* FUN_00726070();
    void FUN_005ae3d0(CopyPair* const&);
    void FUN_00905820(CopyPair* const&);
};
struct CopySource
{
    CopyList* FUN_0044ddc0();
};
struct CopyOwner
{
    int unk00, unk04;
    CopyList* list;
    void ScriptLocals_ClearActionList();
    void CopyFromSource(CopySource*);
};
// @fnv 0x005a8f40
void CopyOwner::CopyFromSource(CopySource* source)
{
    if (list)
        ScriptLocals_ClearActionList();
    if (source)
    {
        CopyList* input9 = source->FUN_0044ddc0();
        if (input9 && !input9->FUN_008256d0())
        {
            CopyList* output = list;
            while (input9 && *input9->FUN_006815c0())
            {
                CopyPair* original3 = *input9->FUN_006815c0();
                CopyPair* copy = new CopyPair;
                copy->first = original3->first;
                copy->second = original3->second;
                if (!output)
                {
                    list = new CopyList;
                    list->FUN_005ae3d0(copy);
                    output = list;
                }
                else
                {
                    output->FUN_00905820(copy);
                    output = output->FUN_00726070();
                }
                input9 = input9->FUN_00726070();
            }
        }
    }
}

struct Conv_00832010
{
    ~Conv_00832010();
};
struct Entry_00832010
{
    int unk00;
    Conv_00832010* unk04;
    ~Entry_00832010();
};
struct Entry2_00832010
{
    ~Entry2_00832010();
};

struct Node_00832010
{
    bool _ref_008256d0();
    Entry_00832010** _ref_006815c0();
    Node_00832010* FUN_00726070();
    void RemoveAll();
};
struct Node2_00832010
{
    bool _ref_008256d0();
    Entry2_00832010** _ref_006815c0();
    Node2_00832010* FUN_00726070();
    void RemoveAll();
};

extern unsigned char DAT_011dd436;
extern Node_00832010 g_011dd554;
extern Node2_00832010 g_011dd58c;
extern Node2_00832010 g_011dd59c;
void FUN_008329a0(int);

// @fnv 0x00832010
// src: COMMUNITY 0x00832010
void FalloutRadio_Shutdown()
{
    DAT_011dd436 = 1;
    FUN_008329a0(1);
    Node_00832010* node = &g_011dd554;
    while (node && !node->_ref_008256d0())
    {
        if ((*node->_ref_006815c0())->unk04)
        {
            delete (*node->_ref_006815c0())->unk04;
            (*node->_ref_006815c0())->unk04 = 0;
        }
        delete *node->_ref_006815c0();
        node = node->FUN_00726070();
    }
    g_011dd554.RemoveAll();
    Node2_00832010* iter = &g_011dd58c;
    while (iter && !iter->_ref_008256d0())
    {
        delete *iter->_ref_006815c0();
        iter = iter->FUN_00726070();
    }
    g_011dd58c.RemoveAll();
    g_011dd59c.RemoveAll();
}

struct FUN_0095ec40_Effects
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05(MagicItem* apItem, TESBoundObject* apSource, int aiArg);
};
struct FUN_0095ec40_shell
{
    char pad[0x88];
    FUN_0095ec40_Effects kEffects;
    char pad8c[0x23c - 0x8c];
    BSSimpleList<Actor*>* pList;
    void ClearActorList();
};
// @fnv 0x0095ec40
void FUN_0095ec40_shell::ClearActorList()
{
    if (pList)
    {
        BSSimpleList<Actor*>* pNode = pList;
        while (pNode && !pNode->IsEmpty())
        {
            if (pNode->GetItem())
            {
                TESEnchantableForm* pEnchantable = dynamic_cast<TESEnchantableForm*>((TESBoundObject*)pNode->GetItem());
                EnchantmentItem* pEnchantmentItem = pEnchantable ? pEnchantable->FUN_00726070() : 0;
                if (pEnchantmentItem)
                    kEffects.Unk_05(pEnchantmentItem, (TESBoundObject*)pNode->GetItem(), 0);
            }
            pNode = pNode->GetNext();
        }
        pList->RemoveAll();
        delete pList;
        pList = 0;
    }
}

struct Obj_009b1510
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual void vCC();
    virtual void vD0();
    virtual void vD4();
    virtual void vD8();
    virtual void vDC();
    virtual void vE0();
    virtual void vE4();
    virtual void vE8();
    virtual void vEC();
    virtual void vF0();
    virtual void vF4();
    virtual void vF8();
    virtual void vFC();
    virtual bool IsReady();
    int Actor_GetDamageLocation(int key);
};
struct Key_009b1510
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int GetKey();
};
struct Cont_009b1510
{
    Obj_009b1510* obj;
    int unk04;
    FUN_009b1630_node list;
};
struct Shell_009b1510 : FUN_009b1630_shell
{
    void Explosion_CheckLimbTarget(Cont_009b1510* cont, Key_009b1510* key, float value);
};
// @fnv 0x009b1510
// src: COMMUNITY 0x009b1510
void Shell_009b1510::Explosion_CheckLimbTarget(Cont_009b1510* pContainer, Key_009b1510* key, float value)
{
    if (pContainer && pContainer->obj && pContainer->obj->IsReady())
    {
        Obj_009b1510* kObj = pContainer->obj;
        int count2 = 0;
        Item_009b1630* best3 = 0;
        FUN_009b1630_node* node2 = &pContainer->list;
        while (node2 && !node2->_ref_008256d0())
        {
            count2++;
            Item_009b1630* item3 = *node2->_ref_006815c0();
            node2 = node2->FUN_00726070();
            if (!best3 || best3->value > item3->value)
                best3 = item3;
        }
        if (count2 < 2 || !best3 || best3->value > value)
        {
            int idx = kObj->Actor_GetDamageLocation(key->GetKey());
            if (idx != -1 && idx != 14)
                Explosion_AddLimbTarget(reinterpret_cast<Container_009b1630*>(pContainer), idx, value);
        }
    }
}

struct Node
{
    bool FUN_008256d0();
    int* FUN_006815c0();
    Node* FUN_00726070();
    void FUN_00470470();
};

struct Thing
{
    char pad[0x188];
    Node m_pFirstNode;
    bool NavMeshObstacleManager_ProcessDisabledNavMeshes();
};

extern "C" void NavMesh_SetDisableNavMesh(int value, int flag);

// Iterates m_pFirstNode, calling FUN_00694500 on each node's value, then calls FUN_00470470 on m_pFirstNode and returns true.
// @fnv 0x006c4970
// src: COMMUNITY 0x006c4970
bool Thing::NavMeshObstacleManager_ProcessDisabledNavMeshes()
{
    Node* node = &m_pFirstNode;
    while (node != 0 && !node->FUN_008256d0())
    {
        int value = *node->FUN_006815c0();
        NavMesh_SetDisableNavMesh(value, 1);
        node = node->FUN_00726070();
    }
    m_pFirstNode.FUN_00470470();
    return true;
}

#include <windows.h>
struct _TREEITEM;
typedef _TREEITEM* HTREEITEM;
struct TreeMap65
{
    bool GetAt(unsigned int, HTREEITEM&);
};
struct FUN_004d65a0_Class
{
    int unk00, unk04, unk08;
    HWND window;
    int unk10, unk14;
    TreeMap65 map;
    void ProcessTreeItemHandles_004d65a0(unsigned int key);
};
// For a nonzero key, builds a list from repeated 0x110A results and sends 0x1102 with wParam 2 for each listed handle.
// @fnv 0x004d65a0
// src: GUESS 0x004d65a0 (confidence: low)
void FUN_004d65a0_Class::ProcessTreeItemHandles_004d65a0(unsigned int key)
{
    if (key)
    {
        HTREEITEM node = 0;
        map.GetAt(key, node);
        BSSimpleList<HTREEITEM> list;
        while (node)
        {
            list.AddHead(node);
            node = (HTREEITEM)SendMessageA(window, 0x110a, 3, (LPARAM)node);
        }
        BSSimpleList<HTREEITEM>* current = &list;
        while (current && current->GetItem())
        {
            HTREEITEM hItem = current->GetItem();
            SendMessageA(window, 0x1102, 2, (LPARAM)hItem);
            current = current->GetNext();
        }
        if (node)
        {
            SendMessageA(window, 0x110b, 5, (LPARAM)node);
            SendMessageA(window, 0x110b, 9, (LPARAM)node);
        }
    }
}


// The original texture-list getter shares the no-argument thiscall body at 0x00500940.
// The shared class has no declaration for it; fastcall passes the model in ECX.
BSSimpleList<TESModelTextureSwap::Texture*>* __fastcall GetTextureSwapList(TESModelTextureSwap* model);
TESModelTextureSwap* __cdecl TESBipedModelForm_GetWorldTESModel(void* form, int variant);

// @fnv 0x0048b310
// src: COMMUNITY 0x0048b310
bool TESModelTextureSwap_HasTextureSwap(void* form, int variant)
{
    bool bFound = false;
    TESModelTextureSwap* pkPath = TESBipedModelForm_GetWorldTESModel(form, variant);
    if (!pkPath)
        pkPath = dynamic_cast<TESModelTextureSwap*>(static_cast<TESForm*>(form));
    if (pkPath && !GetTextureSwapList(pkPath)->IsEmpty())
        bFound = true;
    return bFound;
}
