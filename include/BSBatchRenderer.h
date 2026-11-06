#pragma once

#include "NiObject.h"
#include "MagicTarget.h"

class BSBatchRenderer__GeometryGroup;
class BSBatchRenderer__RenderContext;
class Cam_af60;
template <class T_Key, class T_Data> class NiTMapItem;
class NiTListItem_BSBatchRenderer__GeometryGroup___;

class NiTMap_unsigned_int_unsigned_int_
{
public:
    NiTMap_unsigned_int_unsigned_int_(int = 0);
    virtual ~NiTMap_unsigned_int_unsigned_int_();
    unsigned int m_uiHashSize;
    NiTMapItem<unsigned int, unsigned int>** m_ppkHashTable;
    struct ItemCount
    {
        unsigned int m_uiCount;
    } m_kItemCount;
};

class NiTPointerList_BSBatchRenderer__GeometryGroup___
{
public:
    __declspec(noinline) NiTPointerList_BSBatchRenderer__GeometryGroup___()
    {
        m_kItemCount.m_uiCount = 0;
        m_pkHead = 0;
        m_pkTail = 0;
    }

    __declspec(noinline) ~NiTPointerList_BSBatchRenderer__GeometryGroup___()
    {
        FUN_00b71300();
    }
    void FUN_00b71300();

    NiTListItem_BSBatchRenderer__GeometryGroup___* m_pkHead;
    NiTListItem_BSBatchRenderer__GeometryGroup___* m_pkTail;
    struct ItemCount
    {
        unsigned int m_uiCount;
    } m_kItemCount;
};

class BSBatchRenderer : public NiObject
{
public:
    struct PassTextureSlots
    {
        void ClearPassTextureSlots();
    };

    void* pRenderPassA;
    NiTMap_unsigned_int_unsigned_int_ RenderPassMap;
    unsigned int uiRenderPassCount;
    unsigned int uiCurrentFirstPass;
    unsigned int uiCurrentLastPass;
    BSBatchRenderer__RenderContext* pInstanceRenderer;
    BSSimpleList<unsigned short> kActivePassIndexList;
    int iGroupingAlphas;
    bool bAlphaGroupZPrePass;
    unsigned char _pad39[3];
    BSBatchRenderer__GeometryGroup* pGeometryGroupsA[13];
    BSBatchRenderer__GeometryGroup* pAlphaGroupA[2];
    NiTPointerList_BSBatchRenderer__GeometryGroup___ AlphaGroupList[2];
    BSBatchRenderer__GeometryGroup* pCurrentAlphaGroup[2];

    BSBatchRenderer(unsigned int, int);
    virtual ~BSBatchRenderer();

    bool FindBucketIndex(unsigned int, int&);
    bool FindPassBucket(unsigned int&, int&, bool&);
    bool FindOrCreateGroupBucket(unsigned int&, int&);
    void ReleaseGeometryGroups();
    void FUN_00b99730();
    void ClearAllGroups(int);
    void UpdateVisibility(int idx, Cam_af60* cam, bool flag, float maxDist);
};
