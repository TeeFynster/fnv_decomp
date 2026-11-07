#include "../../include/NiTListItem.h"
#include "../../include/NiTPointerListBase.h"
#include "../../include/NiTListItem.h"

// src/fallout_shared/tesobjectcell_ob1_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /GF /Ob1 (unit src/fallout_shared/tesobjectcell.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "tesobjectcell_packet.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiRefObject.h"
void __cdecl operator delete(void* pointer);
const char kTESObjectCELLCellRefLockEnter[] = "TESObjectCELL::CellRefLockEnter()";
unsigned int TESTerrainLODManager_GetGrassNode();
NiAVObject* TESMain_GetWeatherRoot();

extern double DAT_01017cf8;
float __cdecl NiAbs_00408820(float);
double __cdecl FUN_00ec6cde(double);
double __cdecl FUN_00ec9f30(double);

inline double NiAbs(float fValue)
{
    return (float)FUN_00ec6cde(fValue);
}
inline float NiFunc(float fValue)
{
    return (float)FUN_00ec9f30(fValue);
}

__forceinline double AbsRef(const float& value)
{
    return (float)FUN_00ec6cde(value);
}
__forceinline float ComputeAbs(const float& y)
{
    float arg1 = y;
    float context = AbsRef(arg1);
    return context;
}

inline void NiPoint3::Set(float fX, float fY, float fZ)
{
    x = fX;
    y = fY;
    z = fZ;
}

inline NiPoint3 NiPoint3::operator-(const NiPoint3& b) const
{
    NiPoint3 result;
    result.x = x - b.x;
    result.y = y - b.y;
    result.z = z - b.z;
    return result;
}

struct FUN_004b4600_Class
{
    void FUN_004b4600();
};
struct M_004b4500 : FUN_004b4600_Class
{
    union
    {
        struct
        {
            float m00, m01, m02, m10, m11, m12, m20, m21, m22;
        };
        float entry[3][3];
    };
    bool FUN_004b46a0(M_004b4500*);
    M_004b4500 Inverse()
    {
        M_004b4500 inverse;
        if (!FUN_004b46a0(&inverse))
            inverse.FUN_004b4600();
        return inverse;
    }
    NiPoint3 FUN_004b4500(const NiPoint3* p)
    {
        NiPoint3 result;
        result.x = m00 * p->x + m01 * p->y + m02 * p->z;
        result.y = m10 * p->x + m11 * p->y + m12 * p->z;
        result.z = m20 * p->x + m21 * p->y + m22 * p->z;
        return result;
    }
};
struct SphereInput : NiPoint3
{
    float radius;
};
struct BoxInput
{
    unsigned int kind;
    unsigned int flags;
    NiPoint3 center;
    float halfWidth;
    float halfDepth;
    M_004b4500 rotation;
    unsigned char BSOcclusionPlane_TestIntersection(const SphereInput* sphere);
};

// @fnv 0x00c34890
// src: COMMUNITY 0x00c34890
unsigned char BoxInput::BSOcclusionPlane_TestIntersection(const SphereInput* sphere)
{
    float halfA;
    M_004b4500 rotationB = rotation.Inverse();
    NiPoint3 point7 = rotationB.FUN_004b4500(&(*sphere - center));
    NiPoint3 bound;
    float radius6;
    {
        point7.x = NiAbs(point7.x);
        point7.y = NiAbs(point7.y);
        point7.z = NiAbs(point7.z);
        radius6 = sphere->radius;
        bound.Set(point7.x - radius6, point7.y - radius6, point7.z - radius6);
    }
    if (!(bound.x <= halfWidth) || !(bound.z <= halfDepth) || !(bound.y <= 0.0))
        return false;
    halfA = radius6 * NiFunc(ComputeAbs(bound.y) / radius6);
    return (point7.x - halfA <= halfWidth && point7.y - halfA <= halfDepth) ? 1 : 0;
}

extern int(__stdcall* DAT_00fdf1c0)(void*);
extern int(__stdcall* DAT_00fdf1c4)(void*);

inline void NiRefObject::IncRefCount()
{
    DAT_00fdf1c0(&m_uiRefCount);
}

inline void NiRefObject::DecRefCount()
{
    if (!DAT_00fdf1c4(&m_uiRefCount))
        DeleteThis();
}

// Unit-local smart pointer and list shapes of the 0x00c5bfb0 cell reference list (NiPointer/NiTPointerList layout).
template <class T> struct CellRefPointer
{
    T* m_pObject;
    CellRefPointer(T* pObject = 0)
    {
        m_pObject = pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    CellRefPointer(const CellRefPointer& ptr)
    {
        m_pObject = ptr.m_pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~CellRefPointer()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    CellRefPointer& FUN_0066b0d0(T* pObject);
};



typedef NiTListItem<CellRefPointer<NiRefObject> > CellRefItem;

struct CellRefAllocator
{

    void NiTPointerAllocator_unsigned_int_Deallocate(CellRefItem* pkItem);
};

typedef NiTPointerListBase<CellRefAllocator, CellRefPointer<NiRefObject> > CellRefPointerList;
template <> inline void NiTPointerListBase<CellRefAllocator, CellRefPointer<NiRefObject> >::DeleteItem(NiTListItem<CellRefPointer<NiRefObject> >* pkItem)
{
        int unused[5];  // compiled-out debug locals of the inlined helper
        pkItem->m_element.FUN_0066b0d0(0);
        m_kItemCount.NiTPointerAllocator_unsigned_int_Deallocate(pkItem);
        m_kItemCount.m_uiCount--;
    }

// @fnv 0x00c5bfb0
template <> CellRefPointer<NiRefObject> NiTPointerListBase<CellRefAllocator, CellRefPointer<NiRefObject> >::RemovePos(void*& kPos)
{
    CellRefItem* pkNode = (CellRefItem*)kPos;
    if (pkNode == m_pkHead)
    {
        kPos = pkNode->m_pkNext;
        return RemoveHead();
    }
    if (pkNode == m_pkTail)
    {
        kPos = 0;
        return RemoveTail();
    }
    CellRefItem* pkPrev = pkNode->m_pkPrev;
    CellRefItem* pkNext = pkNode->m_pkNext;
    kPos = pkNext;
    if (pkPrev)
        pkPrev->m_pkNext = pkNext;
    if (pkNext)
        pkNext->m_pkPrev = pkPrev;
    CellRefPointer<NiRefObject> element = pkNode->m_element;
    DeleteItem(pkNode);
    return element;
}

#include <windows.h>

extern CRITICAL_SECTION DAT_01203328;

template <class T> class SmartPtr5b
{
  public:
    T* m_pObject;

    SmartPtr5b(T* pObject = 0)
    {
        m_pObject = pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~SmartPtr5b()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }

    SmartPtr5b& FUN_006e5cc0(const SmartPtr5b& rhs)
    {
        if (m_pObject != rhs.m_pObject)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = rhs.m_pObject;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

struct ListItem5b
{
    ListItem5b* m_pNext;
    ListItem5b* m_pListObject;
    SmartPtr5b<NiRefObject> m_element;
};

struct Alloc5b
{
    ListItem5b* NiGeometry_AddProperty();
};

struct List5b
{
    ListItem5b* m_pHead;
    ListItem5b* m_pTail;
    Alloc5b m_kItemCount;

    ListItem5b* GetHeadPos() const
    {
        return m_pHead;
    }
    NiRefObject* GetNext(ListItem5b*& pos) const
    {
        NiRefObject* const& e = pos->m_element.m_pObject;
        pos = pos->m_pNext;
        return e;
    }

    void NiTListBase_AddNodeTail(ListItem5b*);

    void AddHead(const SmartPtr5b<NiRefObject>& element)
    {
        ListItem5b* pkNode = m_kItemCount.NiGeometry_AddProperty();
        pkNode->m_element.FUN_006e5cc0(element);
        NiTListBase_AddNodeTail(pkNode);
    }

    SmartPtr5b<NiRefObject> RemovePos(ListItem5b*& pos);
};

struct Owner5b
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
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    List5b m_list50;
    List5b m_list5c;
    void BSPortalGraph_AttachAlwaysRenderChild(NiRefObject* p);
};

// @fnv 0x00c5b1c0
// src: COMMUNITY 0x00c5b1c0
void Owner5b::BSPortalGraph_AttachAlwaysRenderChild(NiRefObject* p)
{
    if (!p)
        return;
    EnterCriticalSection(&DAT_01203328);
    ListItem5b* pos = m_list50.GetHeadPos();
    while (pos)
    {
        NiRefObject* cur = m_list50.GetNext(pos);
        if (cur == p)
            break;
    }
    if (!pos)
    {
        m_list50.AddHead(p);
        pos = m_list5c.GetHeadPos();
        while (pos)
        {
            ListItem5b* saved2 = pos;
            NiRefObject* cur = m_list5c.GetNext(pos);
            if (cur == p)
            {
                m_list5c.RemovePos(saved2);
            }
        }
    }
    LeaveCriticalSection(&DAT_01203328);
}

namespace fnv_00c5b370 {
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* cs);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs);

template <class T> class CellRefPointer
{
  public:
    T* m_p;
    inline CellRefPointer(T* p = 0) : m_p(p)
    {
        if (m_p)
            m_p->IncRefCount();
    }
    inline ~CellRefPointer()
    {
        if (m_p)
            m_p->DecRefCount();
    }
    inline operator T*() const
    {
        return m_p;
    }
    inline CellRefPointer& operator=(const CellRefPointer& o)
    {
        if (m_p != o.m_p)
        {
            if (m_p)
                m_p->DecRefCount();
            m_p = o.m_p;
            if (m_p)
                m_p->IncRefCount();
        }
        return *this;
    }
};

struct ItemNode
{
    ItemNode* next;
    ItemNode* prev;
    CellRefPointer<NiRefObject> item;
};

struct NodePool
{
    ItemNode* NiGeometry_AddProperty();
};

struct ItemList
{
    int unk00;
    int unk04;
    NodePool pool;
    void NiTListBase_AddNodeTail(ItemNode* node);
    inline void AddTail(const CellRefPointer<NiRefObject>& ref)
    {
        ItemNode* pNode = pool.NiGeometry_AddProperty();
        pNode->item = ref;
        NiTListBase_AddNodeTail(pNode);
    }
};

struct PendingList
{
    ItemNode* head;
    CellRefPointer<NiRefObject> RemovePos(ItemNode** iter);
    inline ItemNode* GetHead() const
    {
        return head;
    }
    inline CellRefPointer<NiRefObject>& GetNext(ItemNode*& iter)
    {
        CellRefPointer<NiRefObject>& item = iter->item;
        iter = iter->next;
        return item;
    }
};

extern char DAT_01203328;

struct ItemQueue
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
    PendingList pending;
    int unk54;
    int unk58;
    ItemList items;
    void BSPortalGraph_DetachAlwaysRenderChild(NiRefObject* obj);
};

// @fnv 0x00c5b370
// src: XBOX_PDB 0x00c5b370
void ItemQueue::BSPortalGraph_DetachAlwaysRenderChild(NiRefObject* obj)
{
    EnterCriticalSection(&DAT_01203328);
    items.AddTail(obj);
    NiRefObject* p;
    ItemNode* it;
    ItemNode* cur;
    it = pending.GetHead();
    while (it)
    {
        cur = it;
        p = pending.GetNext(it);
        if (p == obj)
        {
            pending.RemovePos(&cur);
            break;
        }
    }
    LeaveCriticalSection(&DAT_01203328);
}
}  // namespace fnv_00c5b370
