#pragma once

#include "NiAccumulator.h"

class ItemListNode;

class NiBackToFrontAccumulator : public NiAccumulator
{
  public:
    NiBackToFrontAccumulator()
        : m_kItemsToSortAndRender(0), m_iNumItems(0), m_iMaxItems(0), m_ppkItems(0), m_pfDepths(0)
    {}
    virtual ~NiBackToFrontAccumulator();

    virtual void Sort();

    void NiCollisionObject_CopyMembers(NiBackToFrontAccumulator* pkClone, CloningProcess& kCloning);
    void QuickSort(int, int);
    float GetPivotValue(int, int);
    NiBackToFrontAccumulator& operator=(const NiBackToFrontAccumulator&);

    struct ItemList
    {
        ItemList()
        {
            m_kItemCount.m_uiCount = 0;
            m_pkHead = 0;
            m_pkTail = 0;
        }
        ItemListNode* m_pkHead;
        ItemListNode* m_pkTail;
        struct Allocator
        {
            unsigned int m_uiCount;
        } m_kItemCount;
    };

    ItemList m_kItems;
    ItemList* m_kItemsToSortAndRender;
    int m_iNumItems;
    int m_iMaxItems;
    NiGeometry** m_ppkItems;
    float* m_pfDepths;
    int m_iCurrItem;
};
