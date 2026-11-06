#ifndef FNV_NITPOINTERMAP_LOCAL_H
#define FNV_NITPOINTERMAP_LOCAL_H

class ChangeData;

// 0x00a11db0 writes a list node: next at +0, previous at +4, unlike the shared hash node.
template <class K, class V> class LocalPointerListItem
{
  public:
    LocalPointerListItem<K, V>* m_pkNext;
    LocalPointerListItem<K, V>* m_pkPrev;
    V m_val;
};

// 0x00a11db0 appends to a nonvirtual list: head +0, tail +4, count +8; not NiTPointerMap.
template <class K, class V> class LocalPointerList
{
  public:
    LocalPointerListItem<K, V>* m_pkFirstItem;
    LocalPointerListItem<K, V>* m_pkLastItem;
    unsigned int m_uiCount;

    void NewItem(LocalPointerListItem<K, V>* pkItem);
};

#endif
