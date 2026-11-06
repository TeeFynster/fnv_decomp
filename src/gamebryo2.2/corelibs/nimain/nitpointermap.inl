// @fnv 0x00a11db0
template <class K, class V>
void LocalPointerList<K, V>::NewItem(LocalPointerListItem<K, V>* pkItem)
{
    pkItem->m_pkNext = 0;
    pkItem->m_pkPrev = m_pkLastItem;
    if (m_pkLastItem)
        m_pkLastItem->m_pkNext = pkItem;
    else
        m_pkFirstItem = pkItem;
    m_pkLastItem = pkItem;
    m_uiCount++;
}
