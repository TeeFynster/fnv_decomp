// fallout_shared/magic/effectitemlist.cpp: EffectItemList and related magic helpers (28 functions)

#include "effectitemlist.h"
#include "../../../include/EffectItemList.h"
#include "../../../include/EffectItem.h"
// The folded getter at 0x0084e3a0 as this unit calls it on EffectItem (the shared header does not name it).
struct EffectItemFoldedGetter
{
    int _ref_0084e3a0();
};
#include "../../../include/EffectSetting.h"
#include "../../../include/PerkEntryConditionSet.h"
#include "../../../include/RecursiveSpinLock.h"
#include "../../../include/Setting.h"
#include "../../../include/TESFullName.h"

// Out-of-line reference for the inline ActorPathHandler::CompleteNoPathUpdate so the
// translation unit emits the method body attributed to the header.
ActorPathHandler::PATH_HANDLER_RESULT CallNoPathUpdate(ActorPathHandler* pHandler, float fSeconds)
{
    return pHandler->CompleteNoPathUpdate(fSeconds);
}

// @fnv 0x00405d80
bool EffectItemList::FUN_00405d80()
{
    return m_iEffectCount > 0;
}

namespace MagicEffectSystem {
struct _Type
{
    enum Type
    {
    };
};
bool __cdecl IsFlagSet(_Type::Type, unsigned int);
}

// @fnv 0x004064b0
bool __fastcall IsArchetypeFlagSet(EffectSetting* pThis)
{
    return MagicEffectSystem::IsFlagSet((MagicEffectSystem::_Type::Type)pThis->GetArchetype(), 0x7c);
}

struct MagicItem;
struct Script;
struct TESForm;
struct blob8
{
    char b[8];
};

typedef char _sizecheck_EffectItem[sizeof(EffectItem) == 36 ? 1 : -1];

// @fnv 0x004065e0
int __fastcall FUN_004065e0(EffectItemList* pthis)
{
    int eresult = -1;
    EffectItem* peffect = pthis->FindCostliestEffectItem(3, 0);
    if (peffect)
    {
        eresult = peffect->GetEffectID();
    }
    return eresult;
}

double __cdecl FUN_00ec6940(double);

// @fnv 0x00406ce0
float __cdecl FUN_00406ce0(float afValue)
{
    return static_cast<float>(FUN_00ec6940(afValue));
}

int __cdecl _vsprintf_s(char*, int, const char*, char*);

// Calls _vsprintf_s to format the variadic arguments following apFormat into apString1 using aiSize as the buffer size.
// @fnv 0x00406d00
int __cdecl FUN_00406d00(char* apString1, int aiSize, const char* apFormat, ...)
{
    char* vList = (char*)(&apFormat + 1);
    return _vsprintf_s(apString1, aiSize, apFormat, vList);
}

extern unsigned int* g_011d61c8[];

// @fnv 0x00406d70
bool __cdecl FUN_00406d70(int aiIndex, int aiFlag)
{
    return (g_011d61c8[aiIndex][0x11] & aiFlag) != 0;
}

void _FNV_Warning(const char*);
// @fnv 0x00406ee0
EffectItem* EffectItemList::GetEffectItemAtIndex(unsigned char aiIndex)
{
    unsigned char uiCurrentIndex = 0;
    BSSimpleList<EffectItem*>* pCurrentElementNext = this ? reinterpret_cast<BSSimpleList<EffectItem*>*>(&m_item) : 0;
    while (pCurrentElementNext)
    {
        if (uiCurrentIndex == aiIndex)
            return pCurrentElementNext->GetItem();
        uiCurrentIndex++;
        pCurrentElementNext = pCurrentElementNext->GetNext();
    }
    _FNV_Warning(
        "GAME EFFECTS: When trying to get an effect item by its index, the index was larger than the size of the list.");
    return 0;
}

int __cdecl FUN_00ec6cc4(char*, const char*, char*);

// @fnv 0x00407000
int __cdecl FUN_00407000(char* apString1, const char* apFormat, char* aList)
{
    return FUN_00ec6cc4(apString1, apFormat, aList);
}

extern int DAT_01070020;

// @fnv 0x0071f540
void* __fastcall ConstructWithVTable(void* apObject)
{
    reinterpret_cast<RecursiveSpinLock*>(reinterpret_cast<char*>(apObject) + 4)->RecursiveSpinLock::RecursiveSpinLock();
    *reinterpret_cast<int**>(apObject) = &DAT_01070020;
    return apObject;
}

extern int DAT_01011cf4;
extern int DAT_01011d0c;
struct FUN_004056a0
{
    FUN_004056a0();
    ~FUN_004056a0();
    void* vt1;
};
struct FUN_00402c90
{
    TESFullName fullName;
    FUN_004056a0 component;
    FUN_00402c90();
};
// Sets the two vtable pointers of the object to DAT_01011d0c and DAT_01011cf4.
// @fnv 0x00402c90
FUN_00402c90::FUN_00402c90()
{
    *reinterpret_cast<void**>(&fullName) = &DAT_01011d0c;
    component.vt1 = &DAT_01011cf4;
}

// @fnv 0x00405f30
bool EffectItemList::HasNonDetrimentalEffect()
{
    EffectItemList* pCurrentElementNext = this;
    if (pCurrentElementNext->IsEmpty())
        return false;
    bool bfound = false;
    while (pCurrentElementNext && !bfound)
    {
        EffectItem* pitem = pCurrentElementNext->GetItem();
        if (pitem && reinterpret_cast<EffectItemFoldedGetter*>(pitem)->_ref_0084e3a0() == 2 && !pitem->IsDetrimental())
            bfound = true;
        pCurrentElementNext = (EffectItemList*)pCurrentElementNext->GetNext();
    }
    return bfound;
}

// @fnv 0x00405da0
bool EffectItemList::FUN_00405da0()
{
    EffectItemList* pCurrentElementNext = this;
    if (pCurrentElementNext->IsEmpty())
        return false;
    while (pCurrentElementNext)
    {
        EffectItem* pitem = pCurrentElementNext->GetItem();
        if (pitem && !pitem->IsDetrimental() && !pitem->IsHostile())
            return false;
        pCurrentElementNext = static_cast<EffectItemList*>(pCurrentElementNext->GetNext());
    }
    return true;
}

struct EffectItemDeleter
{
    ~EffectItemDeleter();
};

// @fnv 0x00406340
void EffectItemList::FUN_00406340()
{
    EffectItemList* pCurrentElementNext = this;
    while (pCurrentElementNext)
    {
        EffectItem* pitem = pCurrentElementNext->GetItem();
        if (pitem)
        {
            delete (EffectItemDeleter*)pitem;
            pCurrentElementNext->RemoveHead();
        }
        else
        {
            pCurrentElementNext = static_cast<EffectItemList*>(pCurrentElementNext->GetNext());
        }
    }
}

namespace fnv_00403ca0 {

// local form of MagicEffectEntry: 0x00403ca0 needs the out-of-line 0x00403ba0 ctor; shared POD replacement changes bytes.
struct FUN_00403ba0
{
    FUN_00403ba0();
    int m_iMagnitude;
    int m_iArea;
    int m_iPayloadInteger;
    int m_eRange;
    int m_eAssociatedActorValue;
};
// local form of EffectItem: 0x00403ca0 needs automatic data construction at 0x00403ba0; the shared union/POD form changes bytes.
struct FUN_00403ca0
{
    FUN_00403ba0 data;
    EffectSetting* m_pEffectSetting;
    float m_fCost;
    PerkEntryConditionSet Conditions;
    FUN_00403ca0(EffectItem* other);
    void FUN_00403be0(EffectSetting* setting);
    void CopyFrom(EffectItem* other);
};

// @fnv 0x00403ca0
FUN_00403ca0::FUN_00403ca0(EffectItem* pEffectItem)
{
    FUN_00403be0(pEffectItem->GetEffectSetting());
    m_pEffectSetting = 0;
    CopyFrom(pEffectItem);
}
}  // namespace fnv_00403ca0

// @fnv 0x004062a0
bool EffectItemList::HasDetrimentalEffect()
{
    bool bDetrimental = false;
    EffectItemList* pCurrentElementNext = this;
    if (pCurrentElementNext->IsEmpty())
        return false;
    while (pCurrentElementNext && !bDetrimental)
    {
        EffectItem* pitem = pCurrentElementNext->GetItem();
        if (pitem && pitem->IsDetrimental())
            bDetrimental = true;
        pCurrentElementNext = static_cast<EffectItemList*>(pCurrentElementNext->GetNext());
    }
    return bDetrimental;
}

// @fnv 0x004064d0
EffectItem* EffectItemList::FindCostliestEffectItem(int aeRange, bool abAreaOnly)
{
    EffectItemList* pCurrentElementNext;
    EffectItem* pBestItem;
    int imaxCost;
    pBestItem = 0;
    pCurrentElementNext = this;
    if (pCurrentElementNext->IsEmpty())
        return 0;
    imaxCost = -1;
    while (pCurrentElementNext)
    {
        EffectItem* pitem;
        int iItemCost;
        pitem = pCurrentElementNext->GetItem();
        iItemCost = (int)pitem->GetCost(0);
        if (!pitem->IsDetrimental() && iItemCost > imaxCost)
        {
            if (abAreaOnly ? pitem->GetArea() > 0 : 1)
            {
                if (aeRange == 3 ||
                    (aeRange != 3 && reinterpret_cast<EffectItemFoldedGetter*>(pitem)->_ref_0084e3a0() == aeRange))
                {
                    pBestItem = pitem;
                    imaxCost = iItemCost;
                }
            }
        }
        pCurrentElementNext = static_cast<EffectItemList*>(pCurrentElementNext->GetNext());
    }
    return pBestItem;
}

void _Deallocate(void*);
struct Fake406e40
{
    void FUN_00406de0();
    void* FUN_00406e40(unsigned int);
};
// Calls FUN_00406de0, then frees this via _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x00406e40
void* Fake406e40::FUN_00406e40(unsigned int flags)
{
    FUN_00406de0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

float __fastcall FUN_008a0c20(void*);
struct Mid93
{
    virtual void f0();
    virtual void f1();
    virtual int f2(int);
};
struct Obj93
{
    char _p[0xA4];
    Mid93 m;
    void __thiscall GetTwoValues(float*, float*);
};
// Stores FUN_008a0c20(this) into *p2 and the result of m.f2(46) into *p1.
// @fnv 0x0093abe0
void __thiscall Obj93::GetTwoValues(float* pfValue, float* pfResult)
{
    *pfResult = FUN_008a0c20(this);
    *pfValue = (float)m.f2(46);
}

// @fnv 0x00405fe0
bool EffectItemList::FUN_00405fe0()
{
    EffectItemList* pCurrentElementNext = this;
    if (pCurrentElementNext->IsEmpty())
        return false;

    bool bfound = false;
    while (pCurrentElementNext && !bfound)
    {
        EffectItem* pitem = pCurrentElementNext->GetItem();
        if (pitem && reinterpret_cast<EffectItemFoldedGetter*>(pitem)->_ref_0084e3a0() == 1 && !pitem->IsDetrimental())
            bfound = true;

        pCurrentElementNext = (EffectItemList*)pCurrentElementNext->GetNext();
    }
    return bfound;
}

// @fnv 0x00406090
bool EffectItemList::FUN_00406090()
{
    EffectItemList* pCurrentElementNext;
    bool bfound;

    pCurrentElementNext = this;

    if (pCurrentElementNext->IsEmpty())
        return false;

    bfound = false;

    while (pCurrentElementNext && !bfound)
    {
        EffectItem* pitem;

        pitem = pCurrentElementNext->GetItem();

        if (pitem && !reinterpret_cast<EffectItemFoldedGetter*>(pitem)->_ref_0084e3a0() && !pitem->IsDetrimental())
            bfound = true;

        pCurrentElementNext = (EffectItemList*)pCurrentElementNext->GetNext();
    }

    return bfound;
}

// The shared headers do not yet declare these operations. These extensions add
// only the missing method declarations; all list storage comes from the headers.
struct EffectItemListNodeOperations : BSSimpleList<EffectItem*>
{
    int GetSize();
};

struct EffectItemListOperations : EffectItemList
{
    bool Compare(EffectItemList* other);
    void CopyItemsFromList(EffectItemList* list);
    unsigned char FindEffectItemIndex(int formID);
};

// Returns true if the two effect lists differ.
// @fnv 0x00405a00
bool EffectItemListOperations::Compare(EffectItemList* apOther)
{
    if (reinterpret_cast<EffectItemListNodeOperations*>(&apOther->m_item)->GetSize() !=
        reinterpret_cast<EffectItemListNodeOperations*>(&m_item)->GetSize())
        return true;
    if (!IsEmpty())
    {
        EffectItemList* pNodeA = this;
        EffectItemList* pNodeB = apOther;
        while (pNodeA)
        {
            EffectItem* pItemB = pNodeA->GetItem();
            EffectItem* pElement = pNodeB->GetItem();
            if (pItemB && pElement && pItemB->Compare(pElement))
                return true;
            pNodeA = static_cast<EffectItemList*>(pNodeA->GetNext());
            pNodeB = static_cast<EffectItemList*>(pNodeB->GetNext());
        }
    }
    return false;
}

void* __cdecl FormHeap_Allocate(unsigned int uiSize);

class B5B10ItemCopy
{
  public:
    B5B10ItemCopy(EffectItem* pkSource);

    static void* operator new(unsigned int uiSize)
    {
        return FormHeap_Allocate(uiSize);
    }
    static void operator delete(void* pvMem);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

// Clears the owner, then walks the linked EffectItemList and adds a B5B10ItemCopy for each non-null EffectItem.
// @fnv 0x00405b10
void EffectItemListOperations::CopyItemsFromList(EffectItemList* pkList)
{
    FUN_00406340();
    EffectItemList* pkNode = pkList;
    while (pkNode)
    {
        EffectItem* pkItem = pkNode->GetItem();
        if (pkItem)
        {
            B5B10ItemCopy* pkCopy = new B5B10ItemCopy(pkItem);
            AddItem(reinterpret_cast<EffectItem*>(pkCopy));
        }
        pkNode = static_cast<EffectItemList*>(pkNode->GetNext());
    }
}

// @fnv 0x00406140
bool EffectItemList::HasNonDetrimentalEffectWithFlag(unsigned int auiFlag)
{
    EffectItemList* pNode2 = this;
    if (pNode2->IsEmpty())
        return false;
    bool bResultTmp = false;
    while (pNode2 && !bResultTmp)
    {
        EffectItem* pItem = pNode2->GetItem();
        if (pItem && pItem->GetEffectSetting()->IsFlagSet(auiFlag) && !pItem->IsDetrimental())
        {
            bResultTmp = true;
        }
        pNode2 = static_cast<EffectItemList*>(pNode2->GetNext());
    }
    return bResultTmp;
}

EffectSetting* GetUsageMonitorEntry406();

// Returns the first effect item using the script effect setting, or null.
// @fnv 0x00406200
EffectItem* EffectItemList::GetScriptEffect()
{
    EffectItem* pkResult = 0;
    EffectItemList* pkNode = this;
    while (pkNode && !pkNode->IsEmpty() && !pkResult)
    {
        EffectItem* pkEntry = pkNode->GetItem();
        if (pkEntry->GetEffectSetting() == GetUsageMonitorEntry406())
            pkResult = pkEntry;
        else
            pkNode = static_cast<EffectItemList*>(pkNode->GetNext());
    }
    return pkResult;
}

extern double DAT_01012060;
float __cdecl FUN_00404040(float);
// @fnv 0x004063e0
float EffectItemList::GetTotalCost(Actor* actor)
{
    float total;
    EffectItemList* p5 = this;
    if (p5->IsEmpty())
        return 0.0f;
    total = 0.0f;
    while (p5)
    {
        EffectItem* item = p5->GetItem();
        if (!item->IsDetrimental())
            total += item->GetCost(actor);
        p5 = static_cast<EffectItemList*>(p5->GetNext());
    }
    return total < DAT_01012060 ? 0.0f : FUN_00404040(total);
}

// @fnv 0x00406e70
unsigned char EffectItemListOperations::FindEffectItemIndex(int aiFormID)
{
    unsigned char idx3 = 0;
    BSSimpleList<EffectItem*>* cur = this ? reinterpret_cast<BSSimpleList<EffectItem*>*>(&m_item) : 0;
    while (cur != 0)
    {
        if (aiFormID == (int)cur->GetItem())
        {
            return idx3;
        }
        idx3++;
        cur = cur->GetNext();
    }
    _FNV_Warning(
        "GAME EFFECTS: When trying to get an effect item index, the effect item was not found in the effect item list.");
    return 0;
}

struct FaceGenStr
{
    char* pString;
    unsigned short usLen;
    unsigned short usMaxLen;
    FaceGenStr();
    ~FaceGenStr();
    operator const char*() const;
};
int __cdecl FUN_00406f60(FaceGenStr* apStr, const char* apFormat, ...);
void FNV_Warning(const char*);

struct FaceGenModel
{
    unsigned int GetDataSize();
    unsigned int GetTextureSize();
    int GetRefCount();
};

template <class T> struct FaceGenPtr
{
    T* m_pObject;
    FaceGenPtr(T* apObject);
    ~FaceGenPtr();
    operator T*() const;
};

struct FaceGenEntry
{
    int unk00;
    int unk04;
    FaceGenPtr<FaceGenModel> m_pRenderedNodeEntry;
};

struct FaceGenMap
{
    void* GetFirstPos();
    void GetNext(void*& rpPos, const char*& rpKey, FaceGenPtr<FaceGenEntry>& rspVal);
};

struct FaceGenLog
{
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1c();
    virtual void f20();
    virtual void f24();
    virtual void f28();
    virtual void f2c();
    virtual void f30();
    virtual void f34();
    virtual void AddLine(FaceGenStr* apLine, bool abFlag);
};

struct FaceGenCache
{
    int unk00;
    FaceGenMap kMap;
    void FUN_0064fe80(FaceGenLog* apLog);
};

// Iterates the cache map and logs each entry's ref count, key, texture size and data size, warning and optionally adding the line to apLog.
// @fnv 0x0064fe80
void FaceGenCache::FUN_0064fe80(FaceGenLog* apLog)
{
    void* pPos3 = kMap.GetFirstPos();
    const char* pKey2;
    FaceGenPtr<FaceGenEntry> spEntry3(0);
    while (pPos3)
    {
        kMap.GetNext(pPos3, pKey2, spEntry3);
        if (spEntry3)
        {
            FaceGenStr kLine;
            FUN_00406f60(&kLine, "FACEGEN:\t%3d\t%s\t%iKB\t%iKB\r\n",
                         ((FaceGenModel*)((FaceGenEntry*)spEntry3)->m_pRenderedNodeEntry)->GetRefCount() - 1, pKey2,
                         ((FaceGenModel*)((FaceGenEntry*)spEntry3)->m_pRenderedNodeEntry)->GetTextureSize() >> 10,
                         ((FaceGenModel*)((FaceGenEntry*)spEntry3)->m_pRenderedNodeEntry)->GetDataSize() >> 10);
            FNV_Warning(kLine);
            if (apLog)
                apLog->AddLine(&kLine, true);
        }
    }
}

struct Text
{
    char* text;
    unsigned short length;
    unsigned short capacity;
    ~Text();
    operator const char*() const;
};
struct Condition
{
    bool _ref_00680c60(void*, int, bool*, int);
};
struct EI
{
    int magnitude;
    int area;
    int duration;
    int range;
    int actorValue;
    bool _ref_00404730();
    Condition* _ref_00409140();
    Setting* _ref_00825c00();
    Text EffectName();
};
struct Node
{
    EI* item;
    Node* next;
    EI** _ref_006815c0();
    Node* _ref_00726070();
};
struct ListBase
{
    Node head;
};
struct TempList : ListBase
{
    virtual void Stub();
    TempList();
    ~TempList();
    void Add(EI*);
};
struct Player
{
    double _ref_008bebb0();
    double _ref_008bec80();
    float _ref_008c4330();
};
extern Player* _g_thePlayer;
void ApplyPerkModifiers(int, Player*, ...);
bool FUN_00406d70(int, int);
float floor(float);
int TruncateFloatToInt(float);
const char* ValueEffectName(int);
int CopyText(char*, unsigned int, const char*);
int strcat_s(char*, unsigned int, const char*);
int sprintf_s(char*, unsigned int, const char*, ...);
struct Description : ListBase
{
    virtual bool First();
    virtual bool Second();
    void BuildDescription(char*, unsigned int);
};
static const char kDurationFormat[] = "%s %+i(%.1f%c)";
// @fnv 0x00406620
void Description::BuildDescription(char* acBuffer, unsigned int size)
{
    char bufferA[128];
    {
        bool s = false;
        TempList p9;
        bool i = First();
        bool hA = Second();
        bool aA = false;
        *acBuffer = 0;
        bufferA[0] = 0;
        for (Node* nodeB = this ? &head : 0; nodeB && *nodeB->_ref_006815c0(); nodeB = nodeB->_ref_00726070())
        {
            if ((*nodeB->_ref_006815c0())->_ref_00404730())
                continue;
            if (!(*nodeB->_ref_006815c0())->_ref_00409140() ||
                (*nodeB->_ref_006815c0())->_ref_00409140()->_ref_00680c60(_g_thePlayer, 0, &s, 0))
            {
                if ((*nodeB->_ref_006815c0())->_ref_00825c00()->FUN_00403e60(0x2000))
                {
                    CopyText(bufferA, 128, (*nodeB->_ref_006815c0())->EffectName());
                    if (aA)
                    {
                        strcat_s(acBuffer, size, "\n");
                        strcat_s(acBuffer, size, bufferA);
                    }
                    else
                    {
                        strcat_s(acBuffer, size, bufferA);
                        aA = true;
                    }
                }
                else
                    p9.Add(*nodeB->_ref_006815c0());
            }
        }
        for (Node* current5 = (Node*)(ListBase*)&p9; current5 && *current5->_ref_006815c0();
             current5 = current5->_ref_00726070())
        {
            if ((*current5->_ref_006815c0())->magnitude && (*current5->_ref_006815c0())->actorValue != -1)
            {
                int iValueVal = (*current5->_ref_006815c0())->actorValue;
                int kAMagnitude = (*current5->_ref_006815c0())->magnitude;
                float pDuration2 = (float)(*current5->_ref_006815c0())->duration;
                char hUnit4 = 's';
                if (pDuration2 >= 3600.0)
                {
                    pDuration2 /= 3600.0;
                    hUnit4 = 'h';
                }
                else if (pDuration2 >= 60.0)
                {
                    pDuration2 /= 60.0;
                    hUnit4 = 'm';
                }
                if (FUN_00406d70(iValueVal, 0x200))
                    kAMagnitude = -kAMagnitude;
                if (i)
                {
                    float scaled5 = kAMagnitude * _g_thePlayer->_ref_008bebb0();
                    if (iValueVal == 16)
                        ApplyPerkModifiers(12, _g_thePlayer, &scaled5);
                    kAMagnitude = (int)scaled5;
                }
                if (hA && iValueVal != 54)
                {
                    float scaledOther4 = kAMagnitude * _g_thePlayer->_ref_008bec80();
                    if (iValueVal == 16)
                        ApplyPerkModifiers(12, _g_thePlayer, &scaledOther4);
                    kAMagnitude = (int)scaledOther4;
                }
                if (iValueVal == 54 && kAMagnitude > 0)
                    kAMagnitude = (int)floor(kAMagnitude * _g_thePlayer->_ref_008c4330());
                if (hA && iValueVal == 54)
                {
                    float multiplier6 = 1.0f;
                    ApplyPerkModifiers(44, _g_thePlayer, &multiplier6);
                    kAMagnitude = (int)(kAMagnitude * multiplier6);
                }
                if (kAMagnitude >= 0 && kAMagnitude < 1)
                    kAMagnitude = 1;
                if (*acBuffer)
                    strcat_s(acBuffer, 128, ", ");
                if ((*current5->_ref_006815c0())->duration)
                {
                    if (pDuration2 != floor(pDuration2))
                        sprintf_s(bufferA, 128, kDurationFormat, ValueEffectName(iValueVal), kAMagnitude, pDuration2,
                                  hUnit4);
                    else
                        sprintf_s(bufferA, 128, "%s %+i(%d%c)", ValueEffectName(iValueVal), kAMagnitude,
                                  TruncateFloatToInt(pDuration2), hUnit4);
                }
                else
                    sprintf_s(bufferA, 128, "%s %+i", ValueEffectName(iValueVal), kAMagnitude);
                strcat_s(acBuffer, size, bufferA);
            }
        }
    }
}
