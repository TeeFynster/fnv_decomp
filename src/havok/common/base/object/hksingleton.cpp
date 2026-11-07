
// src/havok/common/base/object/hksingleton.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/object/hksingleton.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct LocalTag
{
    unsigned char m_00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
};

struct SlotObject
{
    void FUN_00c903a0();
};

struct SlotRef
{
    SlotObject* m_00;
};

struct FoundEntry
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    SlotRef* m_0c;
};

struct FirstNode;

class SpawnedHelper
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;

    SpawnedHelper(LocalTag tag) throw();
    ~SpawnedHelper() throw();

    void hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(void* value, FirstNode* node) throw();
    FoundEntry* GetValue(void* key, int zero) throw();
};

struct FirstNode
{
    void* m_00;
    unsigned int unk04;
    FirstNode* m_08;
};

struct SecondNode
{
    void* m_00;
    unsigned int unk04;
    SecondNode* m_08;
    SlotRef* m_0c;
};

// Builds a SpawnedHelper from list1 nodes, then for each list2 node looks up its key and copies the found slot pointer, invoking it if non-null.
// @fnv 0x00cf6a00
void __cdecl RelinkSecondListFromHelper(SecondNode* pSecondList, FirstNode* pFirstList) throw()
{
    LocalTag tag;
    tag.m_00 = 0;
    SpawnedHelper helper(tag);

    for (FirstNode* node = pFirstList; node != 0; node = node->m_08)
    {
        helper.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(node->m_00, node);
    }

    for (SecondNode* node = pSecondList; node != 0; node = node->m_08)
    {
        void* key = node->m_00;
        FoundEntry* found = helper.GetValue(key, 0);
        if (found != 0)
        {
            node->m_0c->m_00 = found->m_0c->m_00;
            if (node->m_0c->m_00 != 0)
            {
                node->m_0c->m_00->FUN_00c903a0();
            }
        }
    }
}

namespace fnv_00cf6a90 {
struct FirstNode;

struct RefObj
{
    void ReleaseReference();
};

struct FirstNode
{
    const char* m_00;
    int unk04;
    FirstNode* m_08;
    RefObj** m_0c;
};

struct NameFlag
{
    unsigned char m_bValue;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
};

struct StringMap
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;

    void FUN_00d87790(NameFlag aFlag);
    void hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(const char* aKey, int aValue);
    void* GetValue(const char* aKey, int aDefault);
    void FreeBuffer();
};

// @fnv 0x00cf6a90
void ClearMatchingRefs(FirstNode* pNodesToClear, FirstNode* pKeyNodes)
{
    NameFlag flag;
    flag.m_bValue = 0;

    StringMap nodeMap;
    nodeMap.FUN_00d87790(flag);

    if (pKeyNodes != 0)
    {
        FirstNode* pKeyNode = pKeyNodes;
        do
        {
            nodeMap.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(pKeyNode->m_00, (int)pKeyNode);
            pKeyNode = pKeyNode->m_08;
        } while (pKeyNode != 0);
    }

    FirstNode* pNode = pNodesToClear;
    if (pNode != 0)
    {
        do
        {
            const char* key = pNode->m_00;
            if (nodeMap.GetValue(key, 0))
            {
                if (*pNode->m_0c != 0)
                {
                    (*pNode->m_0c)->ReleaseReference();
                }
                *pNode->m_0c = 0;
            }
            pNode = pNode->m_08;
        } while (pNode != 0);
    }

    nodeMap.FreeBuffer();
}
}  // namespace fnv_00cf6a90
