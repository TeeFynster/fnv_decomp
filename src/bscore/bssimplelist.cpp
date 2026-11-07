// bscore/bssimplelist.cpp: TargetClass, ObsList, GList, ActList and more (39 functions)

#define FNV64_NIPOINTER_INLINE_BODIES
#include "../../include/NiPointer.h"
#include "../../include/BSSimpleList.h"
#include "../../include/InventoryStackRecord.h"
#include "../../include/CombatTargetTimestamp.h"
#include "../../include/NiPoint3.h"
#include "../../include/SL.h"
#include "../../include/Script.h"
#include "../../include/StrMem.h"
#include "../../include/TESTexture.h"
#include "../../include/TopicInfoArray.h"


class ActorValueInfo;
namespace ActorValue { enum Index; }

// Reusable definitions from bscore/bssimplelist.inl. Explicit pointer-list
// instantiations below select the original linker-folded bodies.

// Default constructor for BSSimpleList that initializes m_item and m_pkNext to null.
// @fnv 0x0096a2d0
template <class T> BSSimpleList<T>::BSSimpleList() : m_item(0), m_pkNext(0)
{}

// Initializes m_item from item and sets m_pkNext to null.
// @fnv 0x00470440
template <class T> BSSimpleList<T>::BSSimpleList(T& item) : m_item(item), m_pkNext(0)
{}

// @fnv 0x00905820
template <class T> void BSSimpleList<T>::AddTail(T& item)
{
    if (!item)
        return;
    BSSimpleList<T>* tail = this;
    while (tail->m_pkNext)
        tail = tail->m_pkNext;
    if (tail->m_item)
        tail->m_pkNext = new BSSimpleList<T>(item);
    else
        tail->m_item = item;
}

// @fnv 0x006815c0
template <class T> T& BSSimpleList<T>::GetItem()
{
    return m_item;
}

// @fnv 0x00726070
template <class T> BSSimpleList<T>* BSSimpleList<T>::GetNext()
{
    return m_pkNext;
}

// Returns true when the BSSimpleList has no next node and no item.
// @fnv 0x008256d0
template <class T> bool BSSimpleList<T>::IsEmpty()
{
    return !m_pkNext && !m_item;
}

// Deletes every node after this one, then clears this node's m_item and next pointer.
// @fnv 0x00470470
template <class T> void BSSimpleList<T>::RemoveAll()
{
    while (m_pkNext)
    {
        BSSimpleList<T>* next = m_pkNext->m_pkNext;
        m_pkNext->m_pkNext = 0;
        delete m_pkNext;
        m_pkNext = next;
    }
    m_item = 0;
}

// @fnv 0x0046ffb0
template <class T> BSSimpleList<T>::~BSSimpleList()
{
    RemoveAll();
}

// @fnv 0x005ae3d0
template <class T> void BSSimpleList<T>::AddHead(T& item)
{
    if (!item)
        return;
    if (m_item)
    {
        BSSimpleList<T>* node = new BSSimpleList<T>(m_item);
        node->m_pkNext = m_pkNext;
        m_pkNext = node;
        m_item = item;
    }
    else
        m_item = item;
}

// When m_pkNext is nonnull, copies its item and successor into this node and deletes it; otherwise sets m_item to 0.
// @fnv 0x0063f7b0
template <class T> void BSSimpleList<T>::RemoveHead()
{
    if (m_pkNext)
    {
        BSSimpleList<T>* node = m_pkNext;
        m_pkNext = node->m_pkNext;
        m_item = node->m_item;
        node->m_pkNext = 0;
        delete node;
    }
    else
        m_item = 0;
}

template class BSSimpleList<InventoryStackRecord*>;

struct ListX
{
    ~ListX();
};
struct W004702f0 : ListX
{
    W004702f0* FUN_004702f0(unsigned int flags);
};
// Destroys the BSSimpleList base subobject and frees the object memory when the low bit of flags is set.
// @fnv 0x004702f0
W004702f0* W004702f0::FUN_004702f0(unsigned int flags)
{
    ListX::~ListX();
    if (flags & 1)
    {
        ::operator delete(this);
    }
    return this;
}

struct FUN_004818b0
{
    unsigned int a;
    void* b;
    void* c;
    FUN_004818b0();
};
// @fnv 0x004818b0
FUN_004818b0::FUN_004818b0()
{
    a = 1;
    b = 0;
    c = 0;
}

class NiNode;

// These lifecycle operations are supplied by the game's out-of-line helpers.
template <> NiPointer<NiNode>::~NiPointer();
template <> NiPointer<NiNode>::NiPointer(const NiPointer<NiNode>&);
template <> NiPointer<NiNode>& NiPointer<NiNode>::operator=(const NiPointer<NiNode>&);
template <> NiPointer<NiNode>& NiPointer<NiNode>::operator=(NiNode*);

// NiPointer.h does not yet declare the raw-pointer inequality overload. Keep
// just that operation here, inheriting the shared pointer layout and operations.
struct NodePointerWithRawComparison : NiPointer<NiNode>
{
    using NiPointer<NiNode>::operator=;
    bool operator!=(NiNode*) const;
};
struct ObsList
{
    void* m_item;
    ObsList* m_pkNext;
    bool BSSimpleList_NiRefObjectPtr_IsEmpty();
};
// Returns true when m_pkNext is null and this object compares equal to a null NiNode pointer.
// @fnv 0x004a4460
// src: COMMUNITY 0x004a4460
bool ObsList::BSSimpleList_NiRefObjectPtr_IsEmpty()
{
    return (m_pkNext == 0 && *reinterpret_cast<NiPointer<NiNode>*>(this) == 0) ? 1 : 0;
}

void* __cdecl operator new(unsigned int);

struct B006815c0
{
    float x;
    float y;
    B006815c0();
};
struct FUN_004f7680 : public SL
{
    void* m_pScaleResult;
    bool m_bOwnsPointMemory;
    char pad0d[3];
    B006815c0 m_kMinimums;
    B006815c0 Maximums;
    unsigned int m_uiDistanceInsideAtMax;
    unsigned int iCount;

    FUN_004f7680(bool abOwnsPointMemory);
};

struct FUN_004bc550_t
{
    SL* m_00;
    void* m_04;
    int m_08;

    FUN_004bc550_t* InitializeFields_004bc550(int a1, void* a2);
};

// Initialises the object by storing a1 in m_08, allocating a new SL into m_00, and storing a2 in m_04.
// @fnv 0x004bc550
// src: GUESS 0x004bc550 (confidence: low)
FUN_004bc550_t* FUN_004bc550_t::InitializeFields_004bc550(int aiValue, void* a2)
{
    m_08 = aiValue;
    m_00 = new SL();
    m_04 = a2;
    return this;
}

struct V3
{
    float x, y, z;
    V3();
};
extern V3 _NiPoint3_ZERO;
struct FUN_004d9330
{
    char c;
    void* p;
    V3 v;
    FUN_004d9330();
};
// Initializes c to 0, p to null, and v to _NiPoint3_ZERO.
// @fnv 0x004d9330
FUN_004d9330::FUN_004d9330()
{
    c = 0;
    p = 0;
    v = _NiPoint3_ZERO;
}

struct GObj;
struct GNode
{
    GObj** _ref_006815c0();
    GNode* _ref_00726070();
};
struct GList
{
    GObj* TESRegionDataList_Find(int key);
};
// Walks nodes from this pointer and returns the first object whose vtable slot 4 returns key, or null if none match.
// @fnv 0x004f35b0
// src: COMMUNITY 0x004f35b0
GObj* GList::TESRegionDataList_Find(int key)
{
    GNode* node = reinterpret_cast<GNode*>(this);
    GObj* pObj = 0;
    while (node)
    {
        pObj = *node->_ref_006815c0();
        if (pObj && reinterpret_cast<int(__thiscall*)(GObj*)>((*reinterpret_cast<void***>(pObj))[4])(pObj) == key)
            return pObj;
        node = node->_ref_00726070();
    }
    return 0;
}

extern float _DAT_01015f5c;

// @fnv 0x004f7680
FUN_004f7680::FUN_004f7680(bool abOwnsPointMemory)
{
    m_bOwnsPointMemory = abOwnsPointMemory;
    m_uiDistanceInsideAtMax = 0x400;
    iCount = 0;
    m_kMinimums.y = 3.4028234663852886e+38f;
    m_kMinimums.x = 3.4028234663852886e+38f;
    Maximums.y = _DAT_01015f5c;
    Maximums.x = _DAT_01015f5c;
    m_pScaleResult = 0;
}

struct CondS
{
    char pad[8];
    CondS();
    ~CondS();
};
struct FUN_00500960
{
    StrMem ResponseText;
    StrMem m_kMenuText;
    Script m_kScript;
    CondS Conditions;
    void* m_pNote;
    void* m_pTerminal;
    char cFlags;

    FUN_00500960();
};

struct FUN_00500910 : StrMem
{
    unsigned int a;
    unsigned int b;
    FUN_00500910();
};
// Constructor for FUN_00500910 that zero-initializes the two unsigned int members a and b.
// @fnv 0x00500910
FUN_00500910::FUN_00500910()
{
    a = 0;
    b = 0;
}

// Calls two script methods, clears header byte 0x10, and sets m_pNote, m_pTerminal, and cFlags to zero.
// @fnv 0x00500960
FUN_00500960::FUN_00500960()
{
    m_kScript.SetInitializationState(false);
    m_kScript.NotifySaveLoadGameOfFormChange();
    ((char*)m_kScript.GetHeader())[0x10] = 0;
    m_pNote = 0;
    m_pTerminal = 0;
    cFlags = 0;
}

struct FUN_00513d60
{
    void* a;
    bool b;
    void* c;
    FUN_00513d60();
};
// Initializes the struct's pointer and boolean members to null and false.
// @fnv 0x00513d60
FUN_00513d60::FUN_00513d60()
{
    a = 0;
    b = false;
    c = 0;
}

void* __cdecl operator new(unsigned int);

struct FUN_006317f0
{
    char pad[8];
    FUN_006317f0(const void*);
};

struct TargetClass
{
    NodePointerWithRawComparison m_item;
    TargetClass* m_pkNext;

    void BSSimpleList_NiRefObjectPtr_AddTail(const NiPointer<NiNode>& item);
};

// Appends a NiNode reference to the end of the linked list, reusing an empty slot or allocating a new node.
// @fnv 0x0052a9b0
// src: COMMUNITY 0x0052a9b0
void TargetClass::BSSimpleList_NiRefObjectPtr_AddTail(const NiPointer<NiNode>& item)
{
    if (item == 0)
        return;

    TargetClass* pkCur = this;
    while (pkCur->m_pkNext)
        pkCur = pkCur->m_pkNext;

    if (pkCur->m_item != 0)
    {
        pkCur->m_pkNext = (TargetClass*)new FUN_006317f0(&item);
    }
    else
    {
        pkCur->m_item = item;
    }
}

struct FUN_00590b60
{
    StrMem a;
    CondS b;
    FUN_00590b60();
};
// @fnv 0x00590b60
FUN_00590b60::FUN_00590b60()
{}

struct TESForm;
struct FormFlagRecord
{
    TESForm* pForm;
    unsigned int iFlags;
};
typedef char _sizecheck_ACTION_OBJECT[sizeof(FormFlagRecord) == 8 ? 1 : -1];

struct ActNode
{
    FormFlagRecord** _ref_006815c0();
    ActNode* _ref_00726070();
};
struct ActList
{
    void* pad0;
    void* pad1;
    ActNode* head;
    FormFlagRecord* ScriptLocals_GetActionObject(TESForm* form, bool create);
};
// Returns a matching entry, or the last visited entry with a null form when create is true.
// @fnv 0x005a90b0
// src: XBOX_PDB 0x005a90b0
FormFlagRecord* ActList::ScriptLocals_GetActionObject(TESForm* form, bool create)
{
    if (!head)
        return 0;
    FormFlagRecord* empty4;
    ActNode* cur = head;
    empty4 = 0;
    while (cur && *cur->_ref_006815c0())
    {
        FormFlagRecord* obj = *cur->_ref_006815c0();
        if (obj->pForm == form)
            return obj;
        if (obj->pForm == 0)
            empty4 = obj;
        cur = cur->_ref_00726070();
    }
    if (create)
        return empty4;
    else
        return 0;
}

struct RefList
{
    void* m_item;
    RefList* m_pkNext;
    bool BSSimpleList_TESLevSpell_IsInList(void** item);
};
// Walks the linked list and returns true when a node's m_item matches the value pointed to by item.
// @fnv 0x005f65d0
// src: XBOX_PDB 0x005f65d0
bool RefList::BSSimpleList_TESLevSpell_IsInList(void** item)
{
    const RefList* pNode = this;
    while (pNode && pNode->m_item != *item)
        pNode = pNode->m_pkNext;
    return pNode != 0;
}

struct FUN_005fcf10
{
    StrMem a;
    StrMem b;
    TESTexture t;
    FUN_005fcf10();
};
// @fnv 0x005fcf10
FUN_005fcf10::FUN_005fcf10()
{}

struct Dummy_0061bf20
{
    char b[0x10];
};
Dummy_0061bf20* __fastcall ConstructDummy(Dummy_0061bf20*);
struct FUN_00619740
{
    void* pQuest;
    TopicInfoArray arr;
    Dummy_0061bf20 d;
    void* m_pAlternateQuest;
    bool bInitialized;
    FUN_00619740();
};
// Constructs the embedded dummy, sets both quest pointers to null, and clears the initialized flag.
// @fnv 0x00619740
FUN_00619740::FUN_00619740()
{
    ConstructDummy(&d);
    pQuest = 0;
    m_pAlternateQuest = 0;
    bInitialized = false;
}

namespace fnv_00631540 {
void* __cdecl operator new(unsigned int);

struct FUN_006317f0
{
    char pad[8];
    FUN_006317f0(const void*);
};

struct TargetClass
{
    NodePointerWithRawComparison m_item;
    TargetClass* m_pkNext;

    void BSSimpleList_NiPointer_bhkAction_AddHead(const NiPointer<NiNode>& item);
};

// @fnv 0x00631540
// src: XBOX_PDB 0x00631540
void TargetClass::BSSimpleList_NiPointer_bhkAction_AddHead(const NiPointer<NiNode>& item)
{
    if (item == 0)
        return;

    if (m_item != 0)
    {
        TargetClass* pkTmp = (TargetClass*)new FUN_006317f0(this);
        pkTmp->m_pkNext = m_pkNext;
        m_pkNext = pkTmp;
        m_item = item;
    }
    else
    {
        m_item = item;
    }
}
}  // namespace fnv_00631540

struct ListReader
{
    NiPointer<NiNode> item;
    ListReader* next;
    ~ListReader();
    bool IsEmpty();
    void BSSimpleList_NiPointer_bhkAction_Remove(const NiPointer<NiNode>& value);
};
// Removes the node whose item equals value; if it is the only node, clears item.
// @fnv 0x00631620
// src: XBOX_PDB 0x00631620
void ListReader::BSSimpleList_NiPointer_bhkAction_Remove(const NiPointer<NiNode>& value)
{
    if (value == 0 || IsEmpty())
        return;
    ListReader* previous;
    ListReader* current = this;
    previous = this;
    while (current && current->item != value)
    {
        previous = current;
        current = current->next;
    }
    if (current)
    {
        if (current == this)
        {
            if (next)
            {
                previous = next;
                next = previous->next;
                item = previous->item;
                previous->next = 0;
                delete previous;
            }
            else
                item = 0;
        }
        else
        {
            previous->next = current->next;
            current->next = 0;
            delete current;
        }
    }
}

namespace fnv_006317f0 {
struct FUN_006317f0 : NiPointer<NiNode>
{
    void* next;
    FUN_006317f0(const NiPointer<NiNode>&);
};
// @fnv 0x006317f0
FUN_006317f0::FUN_006317f0(const NiPointer<NiNode>& p) : NiPointer<NiNode>(p)
{
    next = 0;
}
}  // namespace fnv_006317f0

namespace fnv_0066e590 {
struct B006815c0
{
    char pad[12];
    B006815c0();
};



CombatTargetTimestamp* __fastcall CombatTargetTimestamp_ClearTimeStamp(CombatTargetTimestamp*);
extern float DAT_010673a0;

struct FUN_0066e590
{
    void* pActor;
    int m_eDetectionLevel;
    int iLevel;
    B006815c0 m_kActorPosition;
    char m_abyActorState[4];
    bool b360view;
    bool m_bCombatState;
    bool m_bHasLineOfSight;
    bool m_bIsDetected;
    int m_iDetectionValue;

    FUN_0066e590();
};

// Initializes actor reference, position, detection flags, and sets the timestamp to negative global time.
// @fnv 0x0066e590
FUN_0066e590::FUN_0066e590()
{
    CombatTargetTimestamp_ClearTimeStamp((CombatTargetTimestamp*)m_abyActorState);
    pActor = 0;
    m_eDetectionLevel = 0;
    m_bHasLineOfSight = false;
    m_bIsDetected = true;
    iLevel = -100;
    *(NiPoint3*)&m_kActorPosition = NiPoint3::ZERO;
    CombatTargetTimestamp timeStamp(-DAT_010673a0);
    *(CombatTargetTimestamp*)m_abyActorState = timeStamp;
    b360view = false;
    m_bCombatState = false;
    m_iDetectionValue = -100;
}
}  // namespace fnv_0066e590

struct FUN_007653f0_class
{
    void BSSimpleList_ShellSort(void** apArray, int(__cdecl* apCompareFn)(const void*, const void*), int aiCount);
};

// Sorts apArray in place using a shell sort algorithm with a compare function apCompareFn over aiCount elements.
// @fnv 0x007653f0
// src: COMMUNITY 0x007653f0
void FUN_007653f0_class::BSSimpleList_ShellSort(void** apArray, int(__cdecl* apCompareFn)(const void*, const void*), int aiCount)
{
    int igap = 0;
    int ileft = 0;
    int iright = aiCount - 1;

    for (igap = 1; igap <= (iright - ileft) / 9; igap = 3 * igap + 1)
    {
    }

    for (; igap > 0; igap /= 3)
    {
        for (int i = ileft + igap; i <= iright; ++i)
        {
            int j = i;
            void* pswap = apArray[i];
            while (j >= ileft + igap && apCompareFn(pswap, apArray[j - igap]) < 0)
            {
                apArray[j] = apArray[j - igap];
                j -= igap;
            }
            apArray[j] = pswap;
        }
    }
}

struct FlagS
{
    char pad[0x2c];
    unsigned short flags;
    void ListBox_ItemChange_SetFlag(unsigned int bit, bool on);
};
// Sets or clears the bit at position bit in the flags field depending on the on parameter.
// @fnv 0x007a1950
// src: XBOX_PDB 0x007a1950
void FlagS::ListBox_ItemChange_SetFlag(unsigned int bit, bool on)
{
    if (on)
        flags |= (1 << bit);
    else
        flags &= ~(1 << bit);
}

struct Date
{
    virtual ~Date();
    void* FUN_007b3fa0(unsigned int flags);
};
void __cdecl Deallocate(void*);
// Destroys the Date object and, if the low bit of flags is set, frees the object memory via Deallocate, returning the original this pointer.
// @fnv 0x007b3fa0
void* Date::FUN_007b3fa0(unsigned int flags)
{
    this->Date::~Date();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct Cur
{
    int* _ref_006815c0();
};
struct TopicS
{
    char pad[0x20];
    Cur* cur;
    bool HasCur();
};
// Sets cur to the address at offset 0xC and returns whether it and its referenced integer are nonzero.
// @fnv 0x0083e0c0
bool TopicS::HasCur()
{
    cur = reinterpret_cast<Cur*>(reinterpret_cast<char*>(this) + 0xc);
    return (cur && *cur->_ref_006815c0() != 0) ? 1 : 0;
}

extern "C" void* __cdecl _alloca(unsigned int);

struct ItemChangeList : BSSimpleList<InventoryStackRecord*>
{

    int ItemsInList();

    void BSSimpleList_ShellSort(InventoryStackRecord**, int(__cdecl*)(InventoryStackRecord*, InventoryStackRecord*), int);

    void BSSimpleList_BubbleSort(int(__cdecl*)(InventoryStackRecord*, InventoryStackRecord*));

    void SortItems(int(__cdecl* compare)(InventoryStackRecord*, InventoryStackRecord*));
};

// Copies the list items into a stack buffer, sorts them with the given compare function, then rebuilds the linked list in sorted order.
// @fnv 0x0083fd60
void ItemChangeList::SortItems(int(__cdecl* compare)(InventoryStackRecord*, InventoryStackRecord*))
{

    int iStack6 = ItemsInList();

    InventoryStackRecord** puStack_10 = (InventoryStackRecord**)_alloca(iStack6 * 4 + 4);

    if (!puStack_10)
    {

        BSSimpleList_BubbleSort(compare);

        return;
    }

    BSSimpleList<InventoryStackRecord*>* _puStack_18 = this;

    int iStack_20 = 0;

    for (; iStack_20 < iStack6; ++iStack_20, _puStack_18 = _puStack_18->m_pkNext)
    {

        puStack_10[iStack_20] = _puStack_18->m_item;
    }

    BSSimpleList_ShellSort(puStack_10, compare, iStack6);

    RemoveAll();

    _puStack_18 = this;

    BSSimpleList<InventoryStackRecord*>* puStack_1c = 0;

    for (int iStack_24 = 0; iStack_24 < iStack6; ++iStack_24)
    {

        if (iStack_24 > 0)
        {

            _puStack_18 = new BSSimpleList<InventoryStackRecord*>(puStack_10[iStack_24]);
        }
        else
        {

            _puStack_18->m_item = puStack_10[iStack_24];

            _puStack_18->m_pkNext = 0;
        }

        if (puStack_1c)
        {

            puStack_1c->m_pkNext = _puStack_18;
        }

        puStack_1c = _puStack_18;
    }
}

struct ItemChangeListNode
{
    InventoryStackRecord* m_item;
    ItemChangeListNode* m_pkNext;
    ~ItemChangeListNode();
    bool IsEmpty();
    void RemoveMatchingItem(InventoryStackRecord* const& item);
};

// Removes a matching node; when it is the head, copies its successor into the head or clears the head, and otherwise unlinks and deletes it.
// @fnv 0x00905330
// src: GUESS 0x00905330 (confidence: medium)
void ItemChangeListNode::RemoveMatchingItem(InventoryStackRecord* const& item)
{
    if (!item || IsEmpty())
        return;
    ItemChangeListNode* pCur = this;
    ItemChangeListNode* pPrev3 = this;
    while (pCur && pCur->m_item != item)
    {
        pPrev3 = pCur;
        pCur = pCur->m_pkNext;
    }
    if (pCur)
    {
        if (pCur == this)
        {
            if (m_pkNext)
            {
                pPrev3 = m_pkNext;
                m_pkNext = pPrev3->m_pkNext;
                m_item = pPrev3->m_item;
                pPrev3->m_pkNext = 0;
                delete pPrev3;
            }
            else
            {
                m_item = 0;
            }
        }
        else
        {
            pPrev3->m_pkNext = pCur->m_pkNext;
            pCur->m_pkNext = 0;
            delete pCur;
        }
    }
}

void __cdecl _Deallocate(void*);

struct List_009e03e0
{
    ~List_009e03e0();
    void** _ref_006815c0();
    void _ref_0063f7b0();
};

struct FUN_00967290_struct
{
    char pad[0xd48];
    List_009e03e0* m_kNode;

    void PlayerCharacter_FreeCompassTargets();
};

// @fnv 0x00967290
// src: COMMUNITY 0x00967290
void FUN_00967290_struct::PlayerCharacter_FreeCompassTargets()
{
    if (m_kNode)
    {
        void* item = 0;
        while (m_kNode && *m_kNode->_ref_006815c0())
        {
            item = *m_kNode->_ref_006815c0();
            void* pItem = item;
            _Deallocate(pItem);
            m_kNode->_ref_0063f7b0();
        }
        delete m_kNode;
        m_kNode = 0;
    }
}

struct S_00aa3e40
{
    void* Game_DoHeapAlloc(unsigned int n);
};

extern S_00aa3e40 DAT_011f6238;

struct S_00a0c7c0_Node
{
    void* m_item;
    S_00a0c7c0_Node* m_pkNext;
};

struct S_00a0c7c0_List
{
    void* m_item;
    S_00a0c7c0_Node* m_pkNext;

    void AddToHead(void** arg);
};

// Prepends the item pointed to by apItem to the front of this linked list, allocating a new node when the list is not empty.
// @fnv 0x00a0c7c0
void S_00a0c7c0_List::AddToHead(void** apItem)
{
    if (!*apItem)
        return;
    if (m_item)
    {
        S_00a0c7c0_Node* p2 = (S_00a0c7c0_Node*)DAT_011f6238.Game_DoHeapAlloc(8);
        S_00a0c7c0_Node* a = p2 ? (p2->m_item = m_item, p2->m_pkNext = 0, p2) : 0;
        S_00a0c7c0_Node* b5 = a;
        b5->m_pkNext = m_pkNext;
        m_pkNext = b5;
        m_item = *apItem;
    }
    else
    {
        m_item = *apItem;
    }
}

struct ModifierEntryView
{
    char TESTextureList_GetTextureCount();
};

struct ModifierFormView
{
    void* vtable;
    unsigned char formType;
    unsigned int formFlags;
    unsigned int formID;
    BSSimpleList<TESFile*> files;
};

struct ModifierNameView
{
    void* vtable;
    BSStringT<char> name;
};

struct ModifierDescriptionView
{
    void* vtable;
    unsigned int fileOffset;
};

struct ModifierIconView
{
    void* vtable;
    BSStringT<char> textureName;
};

struct ModifierActorValueView
{
    ModifierFormView form;
    ModifierNameView fullName;
    ModifierDescriptionView description;
    ModifierIconView icon;
    char* scriptName;
    BSStringT<char> abbreviation;
    unsigned int flags;
};

struct ModifierRoutingList : BSSimpleList<ModifierEntryView*>
{
    void FUN_00937280(char, ModifierEntryView*);
    void ModifierList_AddModifier(ModifierEntryView* mod);
};

namespace ActorValue {
ActorValueInfo* __cdecl GetActorValueInfo(Index);
}

// Looks up the modifier key; calls the other routing method when info has bit 0 set, otherwise adds the entry at the head.
// @fnv 0x00937380
// src: XBOX_PDB 0x00937380
void ModifierRoutingList::ModifierList_AddModifier(ModifierEntryView* apEntry)
{
    if (!apEntry)
        return;
    char key = apEntry->TESTextureList_GetTextureCount();
    ActorValueInfo* info = ActorValue::GetActorValueInfo(static_cast<ActorValue::Index>(key));
    if (info && (reinterpret_cast<ModifierActorValueView*>(info)->flags & 1))
        FUN_00937280(key, apEntry);
    else
        AddHead(apEntry);
}
