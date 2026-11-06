#ifndef BSMAP_DECLS_H
#define BSMAP_DECLS_H


template <class K, class V> struct BSMapEntry
{
    BSMapEntry<K, V>* m_pkNext;
    K m_key;
    V m_data;
};

template <class K, class V> class BSMapBase : public NiTPointerMap<unsigned int, unsigned int>
{
  public:
    bool GetAt(K key, V& data);
    void SetAt(K key, V data);
    virtual ~BSMapBase();
};

class ScrapHeapBuffer;
class PointerMapValue;
class DistantTreeTextureInfo;
#endif
