#ifndef FNV64_BSSIMPLELIST_DEFINED
#define FNV64_BSSIMPLELIST_DEFINED

template <class T> class BSSimpleList
{
public:
    T m_item;
    BSSimpleList<T>* m_pkNext;
    BSSimpleList();
    BSSimpleList(T& item);
    BSSimpleList(T item, BSSimpleList<T>* next); // exe 0x004b0680
    void FUN_004019f0(); // exe 0x004019f0, BGSListForm initialization
    ~BSSimpleList();
    T& GetItem();
    BSSimpleList<T>* GetNext();
    bool IsEmpty();
    void AddTail(T& item);
    void AddTail(const T& item);
    void Remove(const T& item);
    bool IsInList(T& item);
    void AddHead(T& item);
    // the const forms the process-list code calls (as AddTail above has both)
    void AddHead(const T& item);
    bool IsInList(const T& item) const;
    bool IsEmpty() const;
    bool Contains(const T& item); // exe 0x006c6400, obstacle list
    void RemoveHead();
    void RemoveAll();
    void Sort(int (__cdecl* compare)(T, T));
    void SetItem(const T& item);
    void Insert(T item, int (__cdecl* compare)(T, T));
    // 0x005ae380 (/Od, one folded body for pointer items): counts the nodes whose item is non-null, walking with
    // GetItem (0x006815c0) and GetNext (0x00726070); units' GetSize stand-ins bind the same address
    unsigned int ItemsInList();
    // Per-unit allocation hooks: menu/filefinder inline these calls in the exe. No data layout change.
#ifdef FNV64_BSSIMPLELIST_CUSTOM_NEW
    static void* operator new(unsigned int size);
#endif
#ifdef FNV64_BSSIMPLELIST_CUSTOM_DELETE
    static void operator delete(void* pointer);
#endif
};

#endif
