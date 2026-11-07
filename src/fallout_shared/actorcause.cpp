// fallout_shared/actorcause.cpp: ActorCause (5 functions)

#include "../../include/ActorCause.h"

// @fnv 0x0066e910
void ActorCause::ClearActorCauseList(BGSLoadGameBuffer* buffer)
{
    ms_kActorCauseList.RemoveAll();
}

// @fnv 0x0047d3d0
// src: COMMUNITY 0x0047d3d0
unsigned short ActorCause::GetRefCount_0047d3d0()
{
    return *(unsigned short*)((char*)this + 0x18);
}

void __fastcall ActorCause_DecRefCount(ActorCause*);
struct Holder0042f780
{
    ActorCause* m_pObject;
    Holder0042f780* AssignRetainedObject(ActorCause* pObject);
};
// @fnv 0x0042f780
// src: GUESS 0x0042f780 (confidence: medium)
Holder0042f780* Holder0042f780::AssignRetainedObject(ActorCause* pObject)
{
    if (m_pObject != pObject)
    {
        if (m_pObject)
            ActorCause_DecRefCount(m_pObject);
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    return this;
}

struct VirtObjPlaceholder;

struct Pair12
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    void Reset();
};

class CauseRef
{
  public:
    Pair12* GetBase();
    VirtObjPlaceholder* GetVirt();
};

struct VirtObjPlaceholder
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
    virtual int v61(CauseRef* apRef);
};

extern Pair12 DAT_011f426c;
extern unsigned int DAT_011d60cc;
extern BSSimpleList<ActorCause*> DAT_011d6124;

// @fnv 0x0066e010
// src: GUESS 0x0066e010 (confidence: low)
ActorCause* ActorCause::UpdateState_0066e010(Actor* apCauseRef)
{
    ((Pair12*)&m_08)->Reset();
    m_00 = apCauseRef;
    Pair12* src2 = (m_00 != 0) ? ((CauseRef*)m_00)->GetBase() : &DAT_011f426c;
    m_08 = *(NiPoint3*)src2;
    m_04 = 0;
    VirtObjPlaceholder* v = (m_00 != 0) ? ((CauseRef*)apCauseRef)->GetVirt() : 0;
    if (v != 0)
    {
        m_04 = (BSSimpleList<DetectionViewData*>*)v->v61((CauseRef*)m_00);
    }
    m_18 = 0;
    m_14 = DAT_011d60cc;
    DAT_011d60cc = DAT_011d60cc + 1;
    ActorCause* self = this;
    DAT_011d6124.AddHead(self);
    return this;
}

class B66E810Node
{
  public:
    bool IsEmpty();
    ActorCause** GetItem();
    B66E810Node* GetNext();
    void RemoveNext(ActorCause** ppkItem);
    void RemoveHead();
};

extern B66E810Node g_kB66E810List;

// Walks g_kB66E810List, updating items with a positive count and deleting/removing items whose count is zero or that are null.
// @fnv 0x0066e810
void __cdecl UpdateOrRemoveItems(int iArg)
{
    B66E810Node* pkNode = &g_kB66E810List;
    B66E810Node* pkPrev = 0;
    while (pkNode && !pkNode->IsEmpty())
    {
        ActorCause* pkItem = *pkNode->GetItem();
        bool bRemove = false;
        if (pkItem)
        {
            if (pkItem->GetCount() > 0)
            {
                pkItem->Update(iArg);
            }
            else
            {
                pkItem->m_iFadeIndex = -1;
                delete pkItem;
                bRemove = true;
            }
        }
        else
        {
            bRemove = true;
        }
        if (bRemove)
        {
            if (pkPrev)
            {
                pkPrev->RemoveNext(pkNode->GetItem());
                pkNode = pkPrev->GetNext();
            }
            else
            {
                pkNode->RemoveHead();
            }
        }
        else
        {
            pkPrev = pkNode;
            pkNode = pkNode->GetNext();
        }
    }
}
